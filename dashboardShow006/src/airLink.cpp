//#include <QDebug>
//#include <QDateTime>
//#include <QTimerEvent>
//#include <QTcpSocket>
//#include <airLink.h>

//CarStatus::CarStatus(QSerialPort *parent)
//    : CarStatus(serialDev, parent)
//{
//    initNetWork();

//    connect(this, SIGNAL(key1Changed(bool)), this, SLOT(leftButtonDeal(bool)));
//    connect(this, SIGNAL(key2Changed(bool)), this, SLOT(rightButtonDeal(bool)));
//    connect(this, SIGNAL(key3Changed(bool)), this, SLOT(okButtonDeal(bool)));
//    connect(this, SIGNAL(key4Changed(bool)), this, SLOT(energyFlowButtonDeal(bool)));
//}

///* 连接建立时调用该函数，停止发送建立连接的请求 */
//void SpecificCarStatus::conEstablished()
//{
//    m_connectFlag = true;
//    m_tcpConnectTimer->stop();
//    qDebug() << "conEstablished!";
//}
///* 当连接断开时，发送连接请求 */
//void SpecificCarStatus::disConnected()
//{
//    m_connectFlag = false;
//    client->close();
//    m_tcpConnectTimer->start(500);
//}

///* 请求链接函数：以每秒2次的频率向服务器请求建立链接，
//    当链接建立时停止发送请求。*/
//void SpecificCarStatus::connecting()
//{
//    client->connectToHost(CONNECT_SERVERS_ADDR, CONNECT_SERVERS_PORT);    // local
//    qDebug() << "try connectToHost";
//}

//void SpecificCarStatus::sendToHud()
//{
//    AckSocket ackSocket;
//    memset(&ackSocket, 0, sizeof(AckSocket));

//    ackSocket.head = 0xAA;
//    ackSocket.length = sizeof(AckSocket) + 5;

//    ackSocket.socketPack.generatorPower = m_generatorPower + 20;
//    ackSocket.socketPack.speed = m_speed;

//    ackSocket.crc = crc16Check((uint8_t *)(&(ackSocket.socketPack)), sizeof(SocketPack));
//    ackSocket.tail = 0x55;
//    long len = 0;
//    len = client->write(QByteArray((char *)&ackSocket, sizeof(AckSocket)));
//    client->flush();         // 立即把缓冲区的数据写到底层的网络套接字中，即立刻把数据发送出去。

//    if (-1 == len) {
//        client->close();
//        return;
//    }
//}

//void SpecificCarStatus::initNetWork()
//{
//    client = new QTcpSocket();
//    client->setParent(this);
//    client->connectToHost(CONNECT_SERVERS_ADDR, CONNECT_SERVERS_PORT);    // local
//    m_tcpConnectTimer = new QTimer;
//    m_tcpConnectTimer->start(500);
//    connect(m_tcpConnectTimer,SIGNAL(timeout()),this,SLOT(connecting()));
//    connect(client, SIGNAL(connected()), this, SLOT(conEstablished()));
//    connect(client, SIGNAL(connected()), this, SLOT(sendToHud()));
//    connect(client, SIGNAL(disconnected()), this, SLOT(disConnected()));
//}












#include "airLink.h"
#include "serial.h"
#include <QTcpSocket>
#include <QtCore/QFile>
#include <QtCore/QByteArray>
#include <QTimer>
#include <QHostInfo>
#include <QNetworkInterface>
#define UDPPort 6666
#define SERVPORT 3333
//HUD
#include <QDebug>
#include <QDateTime>
#include <QTimerEvent>
#include <QTcpSocket>
//#include <airLink.h>

using namespace std;



AirLink::~AirLink()
{
}


#ifdef SERIAL_MODE
AirLink::AirLink(const QString &serialDev, QObject *parent) :
    QObject(parent)
{
    m_serial = new Serial(serialDev, this);
    connect (m_serial, SIGNAL(serialChanged(Data)), this, SLOT(getSerial(Data)));

    m_id_turn = 0;
    m_speed = 100;

    flagSpeed = false;
    flagSpeedPause_2s = 0;

    m_stalls = 2;
    m_turnDistance = 0;
    m_destDistance = 0;
    flagCount = 0;
    m_carInfo_flag = true ;

    sendToHudC.release();

    QTimer *time2s = new QTimer;
    time2s->start(1200);
    connect(time2s,SIGNAL(timeout()),this,SLOT(serialReadyread()));

//    QTimer *time_100ms = new QTimer;
//    time_100ms->start(100);
//    connect(time_100ms,SIGNAL(timeout()),this,SLOT(speedChangedSlot()));
//#ifndef SERIAL_MODE
    initNetWork();
//#endif

}

void AirLink::speedChangedSlot()
{
    if(m_speed == 100)
    speedFlag_100_126 = false;
    if(!speedFlag_100_126)
        m_speed++;
    if(m_speed == 126)
        speedFlag_100_126 = true;
    if(speedFlag_100_126)
        m_speed--;
    emit speedChanged();
    sendToHudC.acquire();
    sendToHud();
    sendToHudC.release();
}



void AirLink::serialReadyread()
{
    flagSpeedPause_2s ++;
    if(flagSpeedPause_2s == 2)
    {
    QTimer *time_100ms = new QTimer;
    time_100ms->start(150);
    connect(time_100ms,SIGNAL(timeout()),this,SLOT(speedChangedSlot()));
    }
//    flagSpeedPause_2s = true;

    flagCount++;
     if(flagCount > 1&& m_carInfo_flag == false)
     {
         m_carInfo_flag = true;
         emit carInfo_flagChanged();
     }
}

void AirLink::getSerial(Data data)
{
    flagCount = 0 ;
    m_carInfo_flag = false;
    emit carInfo_flagChanged();
    /*解析数据帧，并向QML发送信号*/
    flagInfoType = data.type;
    flagPicType_first = data.type_first;
    flagPicType_second = data.type_second;
//    QByteArray distanceData = frame.data;

    if (WORD_PICINDEX == flagInfoType) {
        if (flagPicType_first <= TURN_OTHERS) {
            m_id_turn = data.type_first;

            emit id_turnChanged();
        } else if (flagPicType_first <= TOWARDS_DIRECTION_C) {
            m_id_towards = data.type_first;
            emit id_towardsChanged();
        }
        if (flagPicType_second <= GUIDE_OTHERS) {
            m_id_guide = data.type_second;
            emit id_guideChanged();
        } else if (flagPicType_second <= CLOCK_DIRECTION_12) {
            m_id_clock = data.type_second;
            emit id_clockChanged();
        }
//        sendToHud(data);
    } else if (WORD_DISTANCE == flagInfoType) {
//        cout << "received a distance data" << endl ;
//        m_turnDistance = distanceData.left(6).toInt(&ok, 16);
//        distanceData.remove(0, 6);
        m_turnDistance = data.turn_distance;
//        cout << "m_turnDistance:" << m_turnDistance  << endl;
        emit turnDistanceChanged();

//        m_destDistance = distanceData.left(6).toInt(&ok, 16);
//        distanceData.remove(0, 6);
        m_destDistance = data.dest_distance;
//        cout << "m_destDistance:" << m_destDistance  << endl;
        emit destDistanceChanged();
    }else if (WORD_INDICATOR == flagInfoType) {
        m_curRoad = data.curRoad;
//        qDebug() << "m_curRoad" << m_curRoad << endl ;
        emit curRoadChanged();
        m_turnRoad = data.turnRoad;
//         qDebug() << "m_turnRoad" << m_turnRoad << endl ;
        emit turnRoadChanged();
    }
//    m_speed = 100;
    m_stalls = 2;
//    m_turnDistance = 2000;
    sendToHudC.acquire();
    sendToHud();
    sendToHudC.release();
}


// -------------HUD NETWORK-------------


/* 连接建立时调用该函数，停止发送建立连接的请求 */
void AirLink::conEstablished()
{
    m_connectFlag = true;
    m_tcpConnectTimer->stop();
    qDebug() << "conEstablished!";
}
/* 当连接断开时，发送连接请求 */
void AirLink::disConnected()
{
    m_connectFlag = false;
    client->close();
    m_tcpConnectTimer->start(500);
}

/* 请求链接函数：以每秒2次的频率向服务器请求建立链接，
    当链接建立时停止发送请求。*/
void AirLink::connecting()
{
    client->connectToHost(CONNECT_SERVERS_ADDR, CONNECT_SERVERS_PORT);    // local
    qDebug() << "try connectToHost";
}

void AirLink::sendToHud()
{
    AckSocket ackSocket;
    memset(&ackSocket, 0, sizeof(AckSocket));

    ackSocket.head = 0xAA;
    ackSocket.length = sizeof(AckSocket) + 5;

    ackSocket.socketPack.speed = m_speed;
    ackSocket.socketPack.stalls = m_stalls;

    ackSocket.socketPack.id_turn = m_id_turn;

    ackSocket.socketPack.id_guide = m_id_guide;
    ackSocket.socketPack.id_towards = m_id_towards;
    ackSocket.socketPack.id_clock = m_id_clock;
    ackSocket.socketPack.turnDistance = m_turnDistance;
    ackSocket.socketPack.destDistance = m_destDistance;

    QByteArray curRoad_tempArray = m_curRoad.toUtf8();//toLocal8Bit() also right
    QByteArray turnRoad_tempArray = m_turnRoad.toUtf8();//toLatin1() shi dan zi jie bian ma de .
    strcpy(ackSocket.socketPack.curRoad,curRoad_tempArray.data());
    QString temp = curRoad_tempArray.data();
    strcpy(ackSocket.socketPack.turnRoad,turnRoad_tempArray.data());
    // -------is not through QByteArray--------
//    strcpy(ackSocket.socketPack.curRoad,data.curRoad);
//    QString temp  = data.curRoad;
//    QString temp1  = ackSocket.socketPack.turnRoad;
//    qDebug()<<"****sendHud****"<<temp;
//    qDebug()<<"****sendHud1****"<<temp1;
//    strcpy(ackSocket.socketPack.turnRoad,data.turnRoad);



    ackSocket.crc = crc16Check((uint8_t *)(&(ackSocket.socketPack)), sizeof(SocketPack));
    ackSocket.tail = 0x55;
    long len = 0;
    len = client->write(QByteArray((char *)&ackSocket, sizeof(AckSocket)));
    client->flush();         // 立即把缓冲区的数据写到底层的网络套接字中，即立刻把数据发送出去。

    if (-1 == len) {
        client->close();
        return;
    }
}

void AirLink::initNetWork()
{
    client = new QTcpSocket();
    client->setParent(this);
    client->connectToHost(CONNECT_SERVERS_ADDR, CONNECT_SERVERS_PORT);    // local
    m_tcpConnectTimer = new QTimer;
    m_tcpConnectTimer->start(500);
    connect(m_tcpConnectTimer,SIGNAL(timeout()),this,SLOT(connecting()));
    connect(client, SIGNAL(connected()), this, SLOT(conEstablished()));
//    connect(client, SIGNAL(connected()), this, SLOT(sendToHud()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disConnected()));
}


void AirLink::emitRefreshSmallTurn()
{
    emit callQmlRefeshImgSmallTurn();
}


#else
//------------NetWork Phone--------------------------

AirLink::AirLink(QObject *parent) : QObject(parent)
{
    wordDataAll.clear();
    wordData.clear();
    readAllWordFlag = false;
    initNetWork();
}

void AirLink::getSocketWordInfo()
{
    qDebug() << "receive a word info";
    bool ok;
    wordDataAll.append(socketData->readAll());
    if(wordDataAll.length() > 0) {
        while(wordDataAll.length() > 0) {
            if(!readAllWordFlag) {
                QString dataHead = wordDataAll.left(13);
                wordDataAll.remove(0,13);
                qDebug() << "dataHead:" << dataHead;
                if("autorock-head" == dataHead) {
                    QByteArray temp;
                    temp = wordDataAll.left(4);
                    wordDataLeft = temp.toInt(&ok, 16) - 12;//len
                    qDebug() << "wordDataLeft:" << wordDataLeft;
                    wordDataAll.remove(0, 4);

                    temp = wordDataAll.left(4);
                    flagInfoType = (infoType)temp.toInt(&ok, 16);//flag1
                    wordDataAll.remove(0, 4);

                    temp = wordDataAll.left(4);
                    flagPicType_first = (picType)wordDataAll.left(4).toInt(&ok, 16);//flag2
                    wordDataAll.remove(0, 4);

                    temp = wordDataAll.left(4);
                    flagPicType_second = (picType)wordDataAll.left(4).toInt(&ok, 16);//flag2
                    wordDataAll.remove(0, 4);
                }
                readAllWordFlag = true;
            } else {
                QByteArray dataTemp;
                dataTemp.clear();
                dataTemp = wordDataAll.left(wordDataLeft);
                wordDataAll.remove(0, wordDataLeft);
                wordData.append(dataTemp);
                wordDataLeft = wordDataLeft - dataTemp.length();
                if (0 == wordDataLeft) {
                    qDebug() << "received a complete data,wordData:" << wordData ;
                    readAllWordFlag = false;
                    if(flagInfoType == WORD_PICINDEX) {
                        cout << "received a pic index" <<  endl;
                        picType data1 = (picType)wordData.left(4).toInt(&ok, 16);
                        wordData.remove(0, 4);
                        picType data2 = (picType)wordData.left(4).toInt(&ok, 16);
                        wordData.remove(0, 4);

                        if(flagPicType_first <= TURN_OTHERS) {
                            m_id_turn = data1;
                            cout << "m_id_turn:" << m_id_turn << endl;
                            emit id_turnChanged();
                        } else if(flagPicType_first <= TOWARDS_DIRECTION_C) {
                            m_id_towards = data1;
                            cout << "m_id_towards:" << m_id_towards << endl;
                            emit id_towardsChanged();
                        }
                        if(flagPicType_second <= GUIDE_OTHERS) {
                            m_id_guide = data2;
                            cout << "m_id_guide:" << m_id_guide << endl;
                            emit id_guideChanged();
                        } else if(flagPicType_second <= CLOCK_DIRECTION_12) {
                            m_id_clock = data2;
                            cout << "m_id_clock:" << m_id_clock << endl;
                            emit id_clockChanged();
                        }

                    } else if(flagInfoType == WORD_DISTANCE) {
                        cout << "received a distance data" << endl ;
                        m_turnDistance = wordData.left(6).toInt(&ok, 16);
                        wordData.remove(0, 6);
                        cout << "m_turnDistance:" << m_turnDistance  << endl;
                        emit turnDistanceChanged();

                        m_destDistance = wordData.left(6).toInt(&ok, 16);
                        wordData.remove(0, 6);
                        cout << "m_destDistance:" << m_destDistance << endl << endl;
                        emit destDistanceChanged();
                    }
                }
                wordData.clear();
            }
        }
    }
}

void AirLink::proConnectedData()
{
    std::cout << "connection for data established!" << std::endl;
}

void AirLink::proConnectedCtrl()
{
    std::cout << "connection for ctrl established!" << std::endl;
}

void AirLink::proConnectionData()
{
    std::cout << "receive a request for data." << std::endl;
    socketData = serverData.nextPendingConnection();
    connect(socketData, SIGNAL(readyRead()), this, SLOT(getSocketWordInfo()));
}

void AirLink::proConnectionCtrl()
{
    std::cout << "receive a request for ctrl." << std::endl;
    socketCtrl = serverCtrl.nextPendingConnection();
    /*  !!!!!!!!!!!!!!!!!!!!!!!!!!  */
    //    connect(socketCtrl, SIGNAL(readyRead()), this, SLOT());
    qDebug() << "" ;
}

void AirLink::sendIp()
{
    udpSocket->writeDatagram(localAddress,QHostAddress::Broadcast,UDPPort);
    qDebug() << "send a message:" << localAddress;
}

void AirLink::initNetWork()
{
    std::cout << "initing network" << std::endl;
    socketData = new QTcpSocket;
    socketCtrl = new QTcpSocket;
    udpSocket = new QUdpSocket;
    QString localHostName = QHostInfo::localHostName();
    qDebug() << "localHostName" << localHostName;
    qDebug() << "localHostName0:" << QNetworkInterface().allAddresses().at(0).toString();
    qDebug() << "localHostName1:" << QNetworkInterface().allAddresses().at(1).toString();
//    qDebug() << "localHostName2:" << QNetworkInterface().allAddresses().at(2).toString();
//    qDebug() << "localHostName3:" << QNetworkInterface().allAddresses().at(3).toString();
    address=QNetworkInterface::allAddresses().at(2);
//        address=QNetworkInterface::allAddresses().at(0);
    QString ipAddress = address.toString();
    qDebug() << "ipAddress" << ipAddress;
    QString IPPort = QString("autorock-alive") + ":" +  ipAddress + ":" + QString::number(SERVPORT);
    localAddress = IPPort.toLatin1();
    qDebug() << "localAddress:" << localAddress;

    /*广播本地IP及端口号*/
    udpSocket->writeDatagram(localAddress,QHostAddress::Broadcast,UDPPort);
    udpTimer.start(2000);
    connect(&udpTimer, SIGNAL(timeout()), this, SLOT(sendIp()));
    qDebug() << "**************************";

    /*监听客户端的连接请求*/
    serverData.setParent(this);
    serverData.listen(QHostAddress::Any, SERVPORT);
    serverCtrl.setParent(this);
    serverCtrl.listen(QHostAddress::Any, SERVPORT + 1);

    connect(&serverData, SIGNAL(newConnection()), this, SLOT(proConnectionData()));
    connect(socketData, SIGNAL(connected()), this, SLOT(proConnectedData()));
    connect(&serverCtrl, SIGNAL(newConnection()), this, SLOT(proConnectionCtrl()));
    connect(socketCtrl, SIGNAL(connected()), this, SLOT(proConnectedCtrl()));

    socketData->setReadBufferSize(1024*1024);//设置接收端缓冲区大小
    std::cout << "network inited!" << std::endl;
}

void AirLink::deInit()
{
    serverData.close();
    serverCtrl.close();
    socketData->close();
    socketCtrl->close();
}
#endif


