#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQmlContext>
#include<QQuickView>
#include<QtQml>
#include <QGuiApplication>
#include<QQmlEngine>
#include <QQmlComponent>
#include "airLink.h"
#include "fontName.h"
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    QCommandLineParser parser;
//    QCommandLineOption serialOption(QStringList() << "s" << "serial port device name", "specify serial port device", "serial", "ttyS2");
//    parser.addOption(serialOption);
//    parser.process(app);


#ifndef SERIAL_MODE
     AirLink *airlink = new AirLink;
#else
//     QString serial = "/dev/ttyUSB0";
   QString serial =  "/dev/ttymxc1";
 //    if (parser.isSet(serialOption))
 //        serial = parser.value(serialOption);
 //    AirLink_lib airLink(serial);
 //    AirLink airLink(serial);

 //    AirLink *airlink = new AirLink;
     AirLink *airlink = new AirLink(serial);
#endif
    QQuickView viewer;
    MFontName fontName;
    viewer.rootContext()->setContextProperty("qairlink", airlink);
    qmlRegisterType<AirLink>("airLink", 1, 0, "AirLink");
    viewer.rootContext()->setContextProperty("FontName", &fontName);
    viewer.setSource(QUrl("qrc:/qml/qml/mainViewer.qml"));

    viewer.show();
    return app.exec();
}
