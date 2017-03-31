import QtQuick 2.3

Rectangle {
    id: dashboardPanel
    opacity: 0.0
    property int rpm: 1000
    property int rpmAngleTo: 270 / 10000 * rpm
    property int speed: qairlink.speed
    property real speedAngleTo: 270 / 200 * speed
    property int oil: 100
    property real oilAngleTo: 59.5 / 100 * oil
    property int water: 100
    property real waterAngleTo: 59.5 / 100 * water

    Image {
        id: midBg
        x: 536
        y: 433
        opacity: 1.0
        source: "qrc:/images/midBg.png"
    }
    // module 转速盘
    Image {
        id: leftBg
        x: 3
        y: 34
        opacity: 1.0
        source: "qrc:/images/leftBg.png"
    }
//    Text {
//        id: rpmid
//        anchors.horizontalCenter: leftBg.horizontalCenter
//        anchors.top: leftBg.top
//        anchors.topMargin: 420
//        font.pixelSize: 70
//        color: "white"
//        style: Text.Outline;
//        styleColor: "blue"
//        text: dashboardPanel.rpm > 2000 ?(dashboardPanel.rpm/1000  - 2 ).toFixed(1) :(dashboardPanel.rpm/1000 ).toFixed(1)
//    }

    DigitValue{
        x:270
        y:480
        spacing: 6
        icon0: "qrc:/speedNum/images/speedNum/0.png"
        icon1: "qrc:/speedNum/images/speedNum/1.png"
        icon2: "qrc:/speedNum/images/speedNum/2.png"
        icon3: "qrc:/speedNum/images/speedNum/3.png"
        icon4: "qrc:/speedNum/images/speedNum/4.png"
        icon5: "qrc:/speedNum/images/speedNum/5.png"
        icon6: "qrc:/speedNum/images/speedNum/6.png"
        icon7: "qrc:/speedNum/images/speedNum/7.png"
        icon8: "qrc:/speedNum/images/speedNum/8.png"
        icon9: "qrc:/speedNum/images/speedNum/9.png"
        value:dashboardPanel.rpm > 2000 ?Math.floor(dashboardPanel.rpm/1000  - 2 ) :Math.floor(dashboardPanel.rpm/1000 )
    }
    Rectangle{
        x:332
        y:510
        height: 8
        width: 8
        radius: 4
        color: "white"
    }
    DigitValue{
        x:349
        y:480
        spacing: 8
        icon0: "qrc:/speedNum/images/speedNum/0.png"
        icon1: "qrc:/speedNum/images/speedNum/1.png"
        icon2: "qrc:/speedNum/images/speedNum/2.png"
        icon3: "qrc:/speedNum/images/speedNum/3.png"
        icon4: "qrc:/speedNum/images/speedNum/4.png"
        icon5: "qrc:/speedNum/images/speedNum/5.png"
        icon6: "qrc:/speedNum/images/speedNum/6.png"
        icon7: "qrc:/speedNum/images/speedNum/7.png"
        icon8: "qrc:/speedNum/images/speedNum/8.png"
        icon9: "qrc:/speedNum/images/speedNum/9.png"
        value:((dashboardPanel.rpm%1000)/100)
    }

    Item{
        id: rpmBarBg
        x: 57
        y: 21
        width: 275
        height: 668
        clip: rpm > 6500 ? false : true//true

        transform: Rotation{
            origin.x: 332 - rpmBarBg.x
            origin.y: 372 - rpmBarBg.y
            angle: 45
        }

        Image {
            id: rpmBar
            x: 64 - rpmBarBg.x
            y: 85 - rpmBarBg.y
            opacity: 1.0
            source: "qrc:/images/rpmBar.png"
            transform: Rotation{
                id: rpmBarRotation
                origin.x: 332 - rpmBar.x - rpmBarBg.x
                origin.y: 372 - rpmBar.y - rpmBarBg.y
                angle: -135 - 45 + rpmAngleTo
            }
        }
    }
    Image {
        id: rpmPoint
        x: 292
        y: 75
        opacity: 1.0
        source: "qrc:/images/rpmPoint.png"
        transform: Rotation{
            id: rpmRotation
            origin.x: 332 - rpmPoint.x
            origin.y: 372 - rpmPoint.y
            angle:{
                //                console.log(rpmAngleTo)
                return -135 + rpmAngleTo
            }
        }
    }

    // module 速度盘
    Image {
        id: rightBg
        x: 1255
        y: 54
        opacity: 1.0
        source: "qrc:/images/rightBg.png"
    }
    //    Text {
    //        id: speedid
    //        anchors.horizontalCenter: rightBg.horizontalCenter
    //        anchors.top: rightBg.top
    //        anchors.topMargin: 400
    //        font.pixelSize: 70
    //        color: "white"
    //        style: Text.Outline; styleColor: "blue"
    //        text: dashboardPanel.speed
    //    }

    DigitValue{
        anchors.horizontalCenter: rightBg.horizontalCenter
        anchors.horizontalCenterOffset: 5
        anchors.top: rightBg.top
        anchors.topMargin: 425
        spacing: 5
        icon0: "qrc:/speedNum/images/speedNum/0.png"
        icon1: "qrc:/speedNum/images/speedNum/1.png"
        icon2: "qrc:/speedNum/images/speedNum/2.png"
        icon3: "qrc:/speedNum/images/speedNum/3.png"
        icon4: "qrc:/speedNum/images/speedNum/4.png"
        icon5: "qrc:/speedNum/images/speedNum/5.png"
        icon6: "qrc:/speedNum/images/speedNum/6.png"
        icon7: "qrc:/speedNum/images/speedNum/7.png"
        icon8: "qrc:/speedNum/images/speedNum/8.png"
        icon9: "qrc:/speedNum/images/speedNum/9.png"
        value:dashboardPanel.speed
    }

    Item{
        id: speedBarBg
        x: 1255
        y: 21
        width: 275 + 55
        height: 668
        clip: speed > 130 ? false : true
        transform: Rotation{
            origin.x: 1587 - speedBarBg.x
            origin.y: 372 - speedBarBg.y
            angle: 45
        }

        Image {
            id: speedBar
            x: 1319 - speedBarBg.x
            y: 104 - speedBarBg.y
            opacity: 1.0
            source: "qrc:/images/speedBar.png"
            transform: Rotation{
                id: speedBarRotation
                origin.x: 1587 - speedBar.x - speedBarBg.x
                origin.y: 372 - speedBar.y - speedBarBg.y
                angle: -169.5 - 45 + speedAngleTo
            }
        }
    }

    Image {
        id: speedPoint
        x: 1582
        y: 104
        opacity: 1.0
        smooth: true
        source: "qrc:/images/speedPoint.png"
        transform: Rotation{
            id: speedRotation
            origin.x: 1587 - speedPoint.x
            origin.y: 372 - speedPoint.y
            angle: -135 + speedAngleTo
        }
    }

    // module 档位
    Item{
        id:gear
        Image {
            id: globalBg
            x: 551
            y: 46
            opacity: 1.0
            source: "qrc:/images/globalBg.png"
        }
        Image {
            id: gearD
            x: 994
            y: 638
            opacity: 1.0
            source: "qrc:/images/gearD.png"
        }
        Image {
            id: gearN
            x: 950
            y: 639
            opacity: 0.0
            source: "qrc:/images/gearN.png"
        }
        Image {
            id: gearR
            x: 908
            y: 638
            opacity: 0.0
            source: "qrc:/images/gearR.png"
        }
        Image {
            id: gearP
            x: 864
            y: 638
            opacity: 0.0
            source: "qrc:/images/gearP.png"
        }
    }
    // module 时间
    Image {
        id: maohao
        x: 551
        y: 46
        opacity: 1.0
        source: "qrc:/images/time.png"
    }

    // tempure
    Image {
        id: tempure
        x: 1224
        y: 46
        opacity: 1.0
        source: "qrc:/images/tempure.png"
    }

    // module 装饰线
    Image {
        id: leftLine
        x: 29
        y: 28
        opacity: 1.0
        source: "qrc:/images/leftLine.png"
    }
    Image {
        id: rightLine
        x: 1366
        y: 28
        opacity: 1.0
        source: "qrc:/images/rightLine.png"
    }
    Image {
        id: downLine
        x: 555
        y: 581
        opacity: 1.0
        source: "qrc:/images/downLine.png"
    }
    Image {
        id: upLine
        x: 555
        y: 122
        opacity: 1.0
        source: "qrc:/images/upLine.png"
    }

    // module 水温___1
    Image {
        id: waterTempBg
        x: 1256
        y: 218
        opacity: 1.0
        source: "qrc:/images/waterTempBg.png"
    }
    Item{
        id: waterTempBarBg
        x: 1245
        width:230
        height: 374
        clip: true
        transform: Rotation{
            id: waterTempBarBgRotation
            origin.x: 1587 - waterTempBarBg.x
            origin.y: 374 - waterTempBarBg.y
            angle: -36
        }
        Image {
            id: waterTempBar
            x: 1253 - waterTempBarBg.x
            y: 217 - waterTempBarBg.y
            opacity: 1.0
            source: "qrc:/images/waterTempBar.png"
            transform: Rotation{
                id: waterRotation
                origin.x: 1587 - waterTempBar.x - waterTempBarBg.x
                origin.y: 374 - waterTempBar.y - waterTempBarBg.y
                angle: -59.5 + 36 + waterAngleTo
            }
        }
    }

    // module 油量___1
    Image {
        id: oilBg
        x: 577
        y: 218
        opacity: 1.0
        source: "qrc:/images/oilBg.png"
    }
    Item{
        id: oilBarBg
        x: 445
        width:230
        height: 374
        clip: true
        transform: Rotation{
            id: oilBarBgRotation
            origin.x: 332 - oilBarBg.x
            origin.y: 374 - oilBarBg.y
            angle: 36
        }
        Image {
            id: oilBar
            x: 593 - oilBarBg.x
            y: 218 - oilBarBg.y
            opacity: 1.0
            source: "qrc:/images/oilBar.png"
            transform: Rotation{
                id: oilRotation
                origin.x: 332 - oilBar.x - oilBarBg.x
                origin.y: 374 - oilBar.y - oilBarBg.y
                angle: 59.5 - 36 - oilAngleTo
            }
        }
    }


    // module 续航里程___1
    Image {
        id: mileBg
        x: 745
        y: 144
        opacity: 1.0
        source: "qrc:/images/mileBg.png"
    }
    Image {
        id: mileBar
        x: width > 250 ? 743 : 745
        y: 144
        width: 255//428
        opacity: 1.0
        source: "qrc:/images/mileBar.png"
    }

    Image {
        id: xuhang
        x: 848
        y: 174
        opacity: 1.0
        source: "qrc:/images/xuhang .png"
    }
    Image {
        id: milePoint
        x: 734 + mileBar.width - 2//949 //735 - 1160
        y: 137
        opacity: 1.0
        source: "qrc:/images/milePoint.png"
    }
    // module 行车信息中
    Image {
        id: carInfo
        x: 743
        y: 267
        opacity: qairlink.carInfo_flag === false ? 0.0: 1.0
        source: "qrc:/images/carINfo.png"
    }
    Image {
        id: samllTrip
        x: 1255
        y: 659
        source: "qrc:/images/samllTrip.png"
    }
    Image {
        id: totalTrip
        x: 508
        y: 658
        source: "qrc:/images/totalTrip.png"
    }




    states: [
        State {
            name: ""
            PropertyChanges { target: dashboardPanel; opacity: 1.0 }
        },
        State {
            name: "show"
            PropertyChanges { target: dashboardPanel; opacity: 1.0 }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "show"
            ParallelAnimation{
                NumberAnimation { target: dashboardPanel; property: "opacity"; to: 1.0; duration: 100; }
                SequentialAnimation{
                    ParallelAnimation{
                        NumberAnimation { target: dashboardPanel; property: "speed"; to: 200; duration: 500; }
                        NumberAnimation { target: dashboardPanel; property: "rpm"; to: 8000; duration: 400; }
                    }
                    ParallelAnimation{
                        NumberAnimation { target: dashboardPanel; property: "speed"; to: 0; duration: 500; }
                        NumberAnimation { target: dashboardPanel; property: "rpm"; to: /*12*/0; duration: 400; }
                    }
                    ParallelAnimation{
                        NumberAnimation { target: dashboardPanel; property: "speed"; to: 100; duration: 500; }
                        NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4900; duration: 400; }
                    }
                    ParallelAnimation{
//                        NumberAnimation { target: dashboardPanel; property: "speed"; to: 80; duration: 1000; }
                        NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4000; duration: 800; }
                    }
                    ParallelAnimation{
//                        NumberAnimation { target: dashboardPanel; property: "speed"; to: 90; duration: 1000; }
                        NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4900; duration: 1000; }
                    }
                    ParallelAnimation{
//                        NumberAnimation { target: dashboardPanel; property: "speed"; to: 100; duration: 1000; }
                    }
                    ParallelAnimation{
//                        NumberAnimation { target: dashboardPanel; property: "speed"; to: 120; duration: 1000; }
                    }

                    SequentialAnimation{
                        loops: Animation.Infinite
                        ParallelAnimation{
//                            NumberAnimation { target: dashboardPanel; property: "speed"; from: 120;to: 120; duration: 1000; }
                            NumberAnimation { target: dashboardPanel; property: "rpm"; from:4900;to: 4500; duration: 1000; }
                        }
                        ParallelAnimation{
//                            NumberAnimation { target: dashboardPanel; property: "speed"; to: 126; duration: 1000; }
                            NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4800; duration: 1000; }
                        }
                        ParallelAnimation{
//                            NumberAnimation { target: dashboardPanel; property: "speed"; to: 128; duration: 1000; }
                            NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4900; duration: 1000; }
                        }
                        ParallelAnimation{
//                            NumberAnimation { target: dashboardPanel; property: "speed"; to: 126; duration: 1000; }
                            NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4600; duration: 1000; }
                        }
                        ParallelAnimation{
//                            NumberAnimation { target: dashboardPanel; property: "speed"; to: 128; duration: 1000; }
                            NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4300; duration: 1000; }
                        }
                        ParallelAnimation{
//                            NumberAnimation { target: dashboardPanel; property: "speed"; to: 124; duration: 1000; }
                            NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4600; duration: 1000; }
                        }
                        ParallelAnimation{
//                            NumberAnimation { target: dashboardPanel; property: "speed"; to: 120; duration: 1000; }
                            NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4900; duration: 1000; }
                        }
                    }
                }
                //                SequentialAnimation{
                //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 8000; duration: 600; }
                //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: /*12*/0; duration: 600; }
                //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 3000; duration: 700; }
                //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4000; duration: 800; }
                //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 5000; duration: 1000; }
                //                    //                    SequentialAnimation{
                //                    //                        loops: Animation.Infinite
                //                    //                    NumberAnimation { target: dashboardPanel; property: "rpm"; from:5000;to: 4500; duration: 1000; }
                //                    //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4800; duration: 1000; }
                //                    //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 5000; duration: 1000; }
                //                    //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4600; duration: 1000; }
                //                    //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4300; duration: 1000; }
                //                    //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 4600; duration: 1000; }
                //                    //                    NumberAnimation { target: dashboardPanel; property: "rpm"; to: 5000; duration: 1000; }
                //                    //                }
                //                }
            }
        },
        Transition {
            from: "show"
            to: ""
            SequentialAnimation{

                NumberAnimation { target: dashboardPanel; property: "opacity"; to: 0.0; duration: 100; }
                ScriptAction{
                    script: {
                        dashboardPanel.state = "show"
                    }
                }
            }
        }
    ]

    Component.onCompleted: {
        state = "show";
    }
}
