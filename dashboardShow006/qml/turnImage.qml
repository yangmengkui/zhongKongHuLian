import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2
import airLink 1.0

Item {
    width: 1920
    height: 720
    //    color: "black"
    Item{
        id:item1
        x:959
        y:351
        width: 105
        height:34
        Text {
            id: turndistance
            font.family: FontName.fontCurrentMicroSoftYahei
//            font.family: FontName.Acens
            anchors.centerIn: item1
            text: qairlink.turnDistance>=1000? (qairlink.turnDistance/1000).toFixed(1):qairlink.turnDistance
            color:"white"
            font.pixelSize: 50
        }
    }
    Text {
        id: km_m
        x:1074
        y:361
        color:"white"
        font.pixelSize: 24
        opacity: 0.6
        font.family: FontName.fontCurrentMicroSoftYahei
        text:qairlink.turnDistance>=1000? "KM":"M"
    }

    Text {
        id: current
        x:686
        y:531 + 4 + 6
        color:"white"
        font.pixelSize: 20
        opacity: 0.6
        font.family: FontName.fontCurrentMicroSoftYahei
        text: "当前"
    }

    Text {
        id: curRoadName
        x:686 + 50
        y:531 + 6
        width: 250
//        textFormat: Text.RichText
        elide: Text.ElideRight
        color:"white"
        font.pixelSize: 24
        font.family: FontName.fontCurrentMicroSoftYahei
        text: qairlink.curRoad
              //+ '<html> <body><a href=http://baidu.com></a><body></html>'
//        onLinkActivated:Qt.openUrlExternally(link)
//        onLinkActivated: {Qt.openUrlExternally(link)
//            curRoadName.font.pixelSize = 30
//        }
    }



    Text {
        id: last
        x:958
        y:402 + 8
        color:"white"
        font.pixelSize: 20
        opacity: 0.6
        font.family: FontName.fontCurrentMicroSoftYahei
        text: "进入"
    }
    Text {
        id: lastRoadName
        x:958 + 50
        y:402 + 5
        width: 185
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        color:"white"
        font.pixelSize: 24
        font.family: FontName.fontCurrentMicroSoftYahei
        text: qairlink.turnRoad
    }

    Text {
        id: getdistant
        x:1044
        y:534 + 2
        color:"white"
        font.family: FontName.fontCurrentMicroSoftYahei
        font.pixelSize: 20
        opacity: 0.6
        text:"距终点 "
    }
    Text {
        id: destance
        x:1044 + 70
        y:534 + 2
        color:"white"
        font.family: FontName.fontCurrentMicroSoftYahei
        font.pixelSize: 24
        text: (qairlink.destDistance>=1000?((qairlink.destDistance/1000).toFixed(1)  ):(qairlink.destDistance))
    }
    Text {
        id: km
        anchors.left: destance.right
        anchors.leftMargin: 3
        y:541
        color:"white"
        font.pixelSize: 18
        opacity: 0.6
        font.family: FontName.fontCurrentMicroSoftYahei
        text: qairlink.destDistance>=1000 ? "KM" : "M"
    }


    Item{
        id:turnImage
        x:804
        y:345
        height: 90
        width: 90

        Image {
            id: straight //1
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/straight.png"
            visible: qairlink.id_turn === 1
        }
        Image {
            id: right //3
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/right.png"
            visible: qairlink.id_turn === 3
        }


        Image {
            id: left //7
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/left.png"
            visible: qairlink.id_turn === 7
        }
        Image {
            id: ring //9
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/ring.png"
            visible: qairlink.id_turn === 9
        }
        Image {
            id: leftY //16
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/leftY.png"
            visible: qairlink.id_turn === 16
        }
        Image {
            id: rightY //17
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/rightY.png"
            visible: qairlink.id_turn === 17
        }

        Image {
            id: pianli //6
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/pianli.png"
            visible: qairlink.id_turn === 6
        }

        Image {
            id: curve //32
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/curve.png"
            visible: qairlink.id_turn === 32
        }


        Image {
            id: tunnel //35
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/tunnel.png"
            visible: qairlink.id_turn === 35
        }
        Image {
            id: flag //48
            anchors.centerIn: turnImage
            source: "qrc:/turnImage/turnImage2/flag.png"
            visible: qairlink.id_turn === 48
        }
    }
}
