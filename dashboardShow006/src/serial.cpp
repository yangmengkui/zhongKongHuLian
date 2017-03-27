#include <QDebug>
#include <QSerialPort>  //.pro文件中，QT += serialport
#include <serial.h>

#define SERIAL_READ_BUFFER_SIZE 2048	// 2048 Byte

Serial::Serial(const QString &serialDev, QObject *parent) :
    QObject(parent)
{
    m_serialPort = new QSerialPort(this);
    m_serialPort->setPortName(serialDev);

    /* the serial port should be protected against receiving too much data,
     * which may eventually cause the application to run out of memory.*/
    m_serialPort->setReadBufferSize(SERIAL_READ_BUFFER_SIZE);

    if (m_serialPort->open(QIODevice::ReadWrite)
            && m_serialPort->setBaudRate(BAUD_RATE)
            && m_serialPort->setDataBits(QSerialPort::Data8)
            && m_serialPort->setParity(QSerialPort::NoParity)
            && m_serialPort->setStopBits(QSerialPort::OneStop)
            && m_serialPort->setFlowControl(QSerialPort::NoFlowControl)
            && m_serialPort->clear(QSerialPort::AllDirections)) {
        qDebug() << "Succeed to open serial port.";
    } else {
        qDebug() << "Fail to open serial port: " << serialDev
                 << "\n" << m_serialPort->errorString();
        return; //return -1;??
    }
    connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(readSerial()));
}

void Serial::readSerial()
{
//    qDebug()<<"find data in serialPort";
    m_recv += m_serialPort->readAll();
    while (m_recv.length() >= (int)sizeof(Frame)) {
        /*如果首字节不是起始标志位0xAA，则从左往右遍历接收到的数据，
           直到找到0xAA，然后把标志位之前的数据都舍弃。*/
        if ((uint8_t)0xAA != (uint8_t)m_recv[0]) {
            bool found0xAA = false;
            for (int i = 0; i < m_recv.length(); ++i) {
                if ((uint8_t)0xAA == (uint8_t)m_recv[i]) {
                    m_recv.remove(0, i);
                    found0xAA = true;
                    break;
                }
            }
            if (!found0xAA)  m_recv.clear();
        } else {
            if ((uint8_t)0x55 != (uint8_t)m_recv[FRAME_BYTELEN-1]) {
                m_recv.remove(0, 1); //???
            } else {
                QByteArray bf = m_recv.left(FRAME_BYTELEN);//读取一个完整的数据帧
                m_recv.remove(0, FRAME_BYTELEN);
                Frame *frame = (Frame *)bf.data();//一个完整的数据帧
//                qDebug() << bf.toHex();
//                qDebug() << frame->data.dest_distance;
//                 qDebug() << frame->head;
                if (frame->crc == crc16Check((uint8_t *)(&(frame->data)), sizeof(Data)))
//                    emit serialChanged(frame->data);
                /*原方案：只对有效数据进行校验，只发送有效数据。现需要使用
                   数据帧中的三个flag，但是这三个flag不在校验的范围，是否可靠？*/
                emit serialChanged(frame->data);
            }
        }
    }
}


