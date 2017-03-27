#ifndef AIRLINK_H
#define AIRLINK_H

#include <QWidget>
#include <QLabel>
#include <iostream>
#include <QtGui/QPalette>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QUdpSocket>
#include <QTimer>
#include "protocol.h"
#include "serial.h"
#include <QObject>
#include "changepicsmallturn.h"

#ifdef SERIAL_MODE
class AirLink : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(picType id_turn MEMBER m_id_turn NOTIFY id_turnChanged)
//    Q_PROPERTY(picType id_guide MEMBER m_id_guide NOTIFY id_guideChanged)
//    Q_PROPERTY(picType id_towards MEMBER m_id_towards NOTIFY id_towardsChanged)
//    Q_PROPERTY(picType id_clock MEMBER m_id_clock NOTIFY id_clockChanged)

    Q_PROPERTY(int id_turn MEMBER m_id_turn NOTIFY id_turnChanged)
    Q_PROPERTY(int id_guide MEMBER m_id_guide NOTIFY id_guideChanged)
    Q_PROPERTY(int id_towards MEMBER m_id_towards NOTIFY id_towardsChanged)
    Q_PROPERTY(int id_clock MEMBER m_id_clock NOTIFY id_clockChanged)

    Q_PROPERTY(int turnDistance MEMBER m_turnDistance NOTIFY turnDistanceChanged)
    Q_PROPERTY(int destDistance MEMBER m_destDistance NOTIFY destDistanceChanged)

    Q_PROPERTY(QString curRoad MEMBER m_curRoad NOTIFY curRoadChanged)
    Q_PROPERTY(QString turnRoad MEMBER m_turnRoad NOTIFY turnRoadChanged)

    Q_PROPERTY(uint stalls MEMBER m_stalls  NOTIFY stallsChanged)
    Q_PROPERTY(uint speed MEMBER m_speed NOTIFY speedChanged)

    Q_PROPERTY(bool carInfo_flag MEMBER m_carInfo_flag NOTIFY carInfo_flagChanged)

//    Q_ENUMS(picType)
public:
    explicit AirLink(const QString &serialDev, QObject *parent = 0);
    explicit AirLink(QObject *parent = 0)
        : QObject(parent) {}
    ~AirLink();

signals:
    void id_turnChanged();
    void callQmlRefeshImgSmallTurn();

    void id_guideChanged();
    void id_towardsChanged();
    void id_clockChanged();

    void turnDistanceChanged();
    void destDistanceChanged();

    void curRoadChanged();
    void turnRoadChanged();

    void stallsChanged();
    void speedChanged();
    void carInfo_flagChanged();

protected slots:
//    void getSerial(Frame frame);
    void getSerial(Data data);

    void connecting();            // 请求建立连接
    void conEstablished();        // 建立连接
    void disConnected();
    void sendToHud();
    void initNetWork();

    void serialReadyread();

     void emitRefreshSmallTurn();//small pics更新图片,normal

private:
    QLabel *ql_show;


    Serial *m_serial;

//    picType m_id_turn;
//    picType m_id_guide;
//    picType m_id_towards;
//    picType m_id_clock;



    int m_id_turn;
    QByteArray imageDataSmallPic;//storage data for small pics

    int m_id_guide;
    int m_id_towards;
    int m_id_clock;

    int m_turnDistance;
    int m_destDistance;

    int m_speed;
    int m_stalls;
    QString m_curRoad;
    QString m_turnRoad;

    bool m_carInfo_flag;
    u_int8_t flagCount;


    infoType flagInfoType;
    picType flagPicType_first;
    picType flagPicType_second;


    QTcpSocket *client;            // socket对象
    QTimer *m_tcpConnectTimer;
    bool m_connectFlag;

};

#else
class AirLink : public QObject
{
    Q_OBJECT
    Q_PROPERTY(picType id_turn MEMBER m_id_turn NOTIFY id_turnChanged)
    Q_PROPERTY(picType id_guide MEMBER m_id_guide NOTIFY id_guideChanged)
    Q_PROPERTY(picType id_towards MEMBER m_id_towards NOTIFY id_towardsChanged)
    Q_PROPERTY(picType id_clock MEMBER m_id_clock NOTIFY id_clockChanged)
    Q_PROPERTY(int turndistance MEMBER m_turnDistance NOTIFY turnDistanceChanged)
    Q_PROPERTY(int destDistance MEMBER m_destDistance NOTIFY destDistanceChanged)
public:
    explicit AirLink(QObject *parent = 0);
    ~AirLink();
    enum infoType {
        WORD_PICINDEX,//图标索引，图片在本地加载
        WORD_DISTANCE,//距离
        WORD_INDICATOR,//提示文字，预留。
        DATA_MAP,//地图信息，大图片，通过网络传输，预留。
        DATA_SMALL_PIC,//小图标，通过网络传输，预留。
    };

    //ORDI:普通路,FREEWAY高速路
    enum picType {
        PICTYPE_NULL,//0
        /*导航转弯信息*/
        TURN_NULL,//null
        TURN_ORDI_STRAIGHT,//普通路直行
        TURN_ORDI_RIGHT_FRONT,//普通路右前方向
        TURN_ORDI_RIGHT,//普通路右转
        TURN_ORDI_RIGHT_REAR,//普通路右后方向
        TURN_ORDI_TURNED_AROUND,//普通路折返方向
        TURN_ORDI_LEFT_REAR,//普通路左后方向
        TURN_ORDI_LEFT,//普通路左转
        TURN_ORDI_LEFT_FRONT,//普通路左前方向
        TURN_ORDI_TO_ISLAND,//10
        TURN_ISLAND_TO_ISLAND,
        TURN_ISLAND_TO_ORDI,
        TURN_RIGHT_TURN_LANE,
        TURN_DRIVE_FROM_MIDDLE,
        TURN_DRIVE_ON_THE_MOST_LEFT,
        TURN_DRIVE_ON_THE_MOST_RIGHT,
        TURN_DRIVE_ON_THE_LEFT,
        TURN_DRIVE_ON_THE_RIGHT,
        TURN_STRAIGHT_FREEWAY_ENTRANCE,
        TURN_MIDDLE_FREEWAY_ENTRANCE,//20
        TURN_MOSTLEFT_FREEWAY_ENTRANCE,
        TURN_MOSTRIGHT_FREEWAY_ENTRANCE,
        TURN_LEFT_FREEWAY_ENTRANCE,
        TURN_RIGHT_FREEWAY_ENTRANCE,
        TURN_STRAIGHT_FREEWAY_EXIT,
        TURN_MIDDLE_FREEWAY_EXIT,
        TURN_MOSTLEFT_FREEWAY_EXIT,
        TURN_MOSTRIGHT_FREEWAY_EXIT,
        TURN_LEFT_FREEWAY_EXIT,
        TURN_RIGHT_FREEWAY_EXIT,//30
        TURN_LEFT_INTO_MAINROAD,
        TURN_RIGHT_EXIT_MAINROAD,
        TURN_GO_STRAIGHT_ON_LEFT,
        TURN_GO_STRAIGHT_ON_RIGHT,
        TURN_TOLL_STATION,
        TURN_TUNNEL,
        TURN_ROAD_TO_FERRY,
        TURN_ENTER_SERVICEAREA,
        TURN_ENTER_SERVICEAREA_ONLEFT,
        TURN_ENTER_SERVICEAREA_ONRIGHT,//40
        TURN_TURNLEFT_DRIVE_ONLEFT,
        TURN_TURNLEFT_DRIVE_ONRIGHT,
        TURN_TURNRIGHT_DRIVE_ONLEFT,
        TURN_TURNRIGHT_DRIVE_ONRIGHT,
        TURN_PASSING_POINT1,
        TURN_PASSING_POINT2,
        TURN_PASSING_POINT3,
        TURN_PASSING_POINT4,
        TURN_DESTINATION,
        TURN_STRAIGHT_CITYFAST_ENTRANCE,//50
        TURN_MIDDLE_CITYFAST_ENTRANCE,
        TURN_MOSTLEFT_CITYFAST_ENTRANCE,
        TURN_MOSTRIGHT_CITYFAST_ENTRANCE,
        TURN_LEFT_CITYFAST_ENTRANCE,
        TURN_RIGHT_CITYFAST_ENTRANCE,
        TURN_STRAIGHT_CITYFAST_EXIT,
        TURN_MIDDLE_CITYFAST_EXIT,
        TURN_MOSTLEFT_CITYFAST_EXIT,
        TURN_MOSTRIGHT_CITYFAST_EXIT,
        TURN_LEFT_CITYFAST_EXIT,//60
        TURN_RIGHT_CITYFAST_EXIT,
        TURN_BRIDGE,
        TURN_VIADUCT,
        TURN_PARKING,
        TURN_ENTER_PARKING_ONLEFT,
        TURN_ENTER_PARKING_ONRIGHT,
        TURN_OTHERS,//67

        /*引导道路类型*/
        GUIDE_FREEWAY_ENTRANCE,//68
        GUIDE_FREEWAY_EXIT,
        GUIDE_CITYFAST_ENTRANCE,
        GUIDE_CITYFAST_EXIT,
        GUIDE_ENTER_VIADUCT,
        GUIDE_EXIT_VIADUCT,
        GUIDE_ENTER_BRIDGE,
        GUIDE_EXIT_BRIDGE,
        GUIDE_OTHERS,//76

        /*时钟方向*/
        TOWARDS_DEFAULT,//77
        TOWARDS_DIRECTION_1,
        TOWARDS_DIRECTION_2,
        TOWARDS_DIRECTION_3,
        TOWARDS_DIRECTION_4,
        TOWARDS_DIRECTION_5,
        //    TOWARDS_DIRECTION_RESERVED,
        TOWARDS_DIRECTION_7,
        TOWARDS_DIRECTION_8,
        TOWARDS_DIRECTION_9,
        TOWARDS_DIRECTION_A,
        TOWARDS_DIRECTION_B,
        TOWARDS_DIRECTION_C,//88

        /*时钟背景*/
        CLOCK_DEFAULT,//89
        CLOCK_DIRECTION_1,
        CLOCK_DIRECTION_2,
        CLOCK_DIRECTION_3,
        CLOCK_DIRECTION_4,
        CLOCK_DIRECTION_5,
        //    CLOCK_DIRECTION_6,//
        CLOCK_DIRECTION_7,
        CLOCK_DIRECTION_8,
        CLOCK_DIRECTION_9,
        CLOCK_DIRECTION_10,
        CLOCK_DIRECTION_11,
        CLOCK_DIRECTION_12,//100
    };

    Q_ENUMS(picType)

signals:
    void id_turnChanged();
    void id_guideChanged();
    void id_towardsChanged();
    void id_clockChanged();

    void turnDistanceChanged();
    void destDistanceChanged();

public slots:
    void getSocketWordInfo();  //获取从服务器端传来的图片数据
    void proConnectedData();
    void proConnectedCtrl();
    void proConnectionData();//deal with connect request for data
    void proConnectionCtrl();//deal with connect request for ctrl

    void sendIp();//broadcast local IP and port
private:
    QTcpServer serverData, serverCtrl;
    QTcpSocket *socketData, *socketCtrl;   //socket for data, socket for ctrl
    QUdpSocket *udpSocket;
    QLabel *ql_show;

    QByteArray wordData;
    QByteArray wordDataAll;
    QByteArray localAddress;//local IP and port
    QHostAddress address;

    //      QTimer *timerConnect;
    long avalibleNum;
    void initNetWork();
//    void sendCtrlInfo();
    void deInit();
    QTimer udpTimer ;
    bool headFlag;

    picType m_id_turn;
    picType m_id_guide;
    picType m_id_towards;
    picType m_id_clock;

    int m_turnDistance;
    int m_destDistance;
    bool readAllWordFlag;
    int wordDataLeft;

    infoType flagInfoType;
    //    picType flagPicType;
    picType flagPicType_first;
    picType flagPicType_second;
};
#endif

#endif // AIRLINK_H

