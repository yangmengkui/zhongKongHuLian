#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
//#include <QByteArray>
#include <stdlib.h> //exit()
#include <strings.h>//bzero()
#include <unistd.h> //close()
#include "protocol.h"
//#include "airlink.h"

class QSerialPort;

class Serial : public QObject
{
    Q_OBJECT
public:
    explicit Serial(const QString &serialDev, QObject *parent = 0);
//    bool sendSerial(const QByteArray &data);

signals:
    void serialChanged(Data data);

private slots:
    void readSerial();
private:
    QByteArray m_recv;
    QSerialPort *m_serialPort;
//	FRAME_TYPES m_frameType;
};

#endif // SERIAL_H

