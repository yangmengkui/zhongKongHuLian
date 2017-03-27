import QtQuick 2.3
import "content"

Rectangle {
	id: mainViewer
	width: 1920
	height: 720
	color: "black"

	Loader{
		id:splashPanel
        active: false
		source: "qrc:/qml/qml/content/SplashPanel.qml"
		asynchronous: true
		visible: (!dashboardPanel.visible) && (timer.running === true) && (status == Loader.Ready)
		onStatusChanged: {
			if( status == Loader.Ready )
				dashboardPanel.active = true;
		}
	}

	Timer{
		id: timer
		interval: 1500; running: true; repeat: false
		onTriggered: {
			timer.running = false;
			splashPanel.active = false;
			splashPanel.source = "";
		}
	}

	Loader{
		id:dashboardPanel
        active: true
		source: "qrc:/qml/qml/content/DashboardPanel.qml"
		asynchronous: true
        visible: (status == Loader.Ready)
	}

    Loader{
        active: qairlink.carInfo_flag === false
        source: "qrc:/qml/qml/turnImage.qml"
    }
}
