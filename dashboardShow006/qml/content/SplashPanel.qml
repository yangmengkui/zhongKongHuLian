import QtQuick 2.2

Rectangle {
	id: splashPanel
	opacity: 0.0

	Image {
		 id: openBg
		 x: 0
		 y: 0
		 opacity: 1.0
		 source: "qrc:/splashPanel/images/splashPanel/openBg.png"
	 }
	 Image {
		 id: logo
		 x: 668
		 y: 21
		 opacity: 0.0
		 scale: 0.0
		 source: "qrc:/splashPanel/images/splashPanel/logo.png"
	 }

	states: [
		State {
			name: ""
			PropertyChanges { target: splashPanel; opacity: 0.0 }
			PropertyChanges { target: logo; opacity: 0.0;scale: 0.0 }
		},
		State {
			name: "show"
			PropertyChanges { target: splashPanel; opacity: 1.0 }
			PropertyChanges { target: logo; opacity: 1.0;scale: 1.0 }
		}
	]

	transitions: [
		Transition {
			from: ""
			to: "show"
			SequentialAnimation{
				NumberAnimation { target: logo; properties: "opacity,scale"; duration: 500; }
			}
		},
		Transition {
			from: "show"
			to: ""
		}
	]

	Component.onCompleted: {
		state = "show";
	}
}
