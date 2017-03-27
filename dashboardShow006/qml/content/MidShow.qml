import QtQuick 2.3

Item {
	id: midShow
	opacity: 0.0

	Image {
		id: runningInfoMenu
		x: 733
		y: 247
		visible: false
		width: 454
		height: 207
		source: "qrc:/midShow/images/midShow/runningInfoMenu.png"
	}
	Image {
		id: runningInfo
		x: 727
		y: 128
		visible: false
		width: 466
		height: 486
		source: "qrc:/midShow/images/midShow/runningInfo.png"
	}

	Image {
		id: tirePressMenu
		x: 733
		y: 247
		visible: false
		width: 454
		height: 207
		source: "qrc:/midShow/images/midShow/tirePressMenu.png"
	}
	Image {
		id: tirePress
		x: 754
		y: 150
		visible: false
		width: 404
		height: 441
		source: "qrc:/midShow/images/midShow/tirePress.png"
	}
	Image {
		id: setMenu
		x: 733
		y: 247
		visible: false
		width: 454
		height: 207
		source: "qrc:/midShow/images/midShow/setMenu.png"
	}
	Image {
		id: set
		x: 727
		y: 128
		visible: false
		width: 466
		height: 486
		source: "qrc:/midShow/images/midShow/set.png"
	}
	Image {
		id: naviMenu
		x: 733
		y: 247
		visible: false
		width: 454
		height: 207
		source: "qrc:/midShow/images/midShow/naviMenu.png"
	}
	Image {
		id: navi
		x: 611
		y: 126
		visible: false
		width: 701
		height: 504
		source: "qrc:/midShow/images/midShow/navi.png"
	}

	Image {
		id: rightLamp
		x: 1355
		y: 20
		visible: false
		width: 49
		height: 59
		source: "qrc:/midShow/images/midShow/rightLamp.png"
	}
	Image {
		id: leftLamp
		x: 516
		y: 20
		visible: false
		width: 49
		height: 59
		source: "qrc:/midShow/images/midShow/leftLamp.png"
	}
	Image {
		id: frontFogLamp
		x: 776
		y: 44
		visible: false
		width: 55
		height: 45
		source: "qrc:/midShow/images/midShow/frontFogLamp.png"
	}
	Image {
		id: carDoorLamp
		x: 663
		y: 123
		visible: false
		width: 45
		height: 59
		source: "qrc:/midShow/images/midShow/carDoorLamp.png"
	}
	Image {
		id: rearFogLamp
		x: 1024
		y: 44
		visible: false
		width: 55
		height: 44
		source: "qrc:/midShow/images/midShow/rearFogLamp.png"
	}
	Image {
		id: tirePressLamp
		x: 1217
		y: 123
		visible: false
		width: 53
		height: 48
		source: "qrc:/midShow/images/midShow/tirePressLamp.png"
	}
	Image {
		id: highLamp
		x: 938
		y: 47
		visible: false
		width: 57
		height: 36
		source: "qrc:/midShow/images/midShow/HighLamp.png"
	}
	Image {
		id: positionLamp
		x: 857
		y: 49
		visible: false
		width: 62
		height: 34
		source: "qrc:/midShow/images/midShow/positionLamp.png"
	}

	onStateChanged: {
		if(state == ""){
			runningInfoMenu.visible = false;
			runningInfo.visible = false;
			tirePressMenu.visible = false;
			tirePress.visible = false;
			setMenu.visible = false;
			set.visible = false;
			naviMenu.visible = false;
			navi.visible = false;

			rightLamp.visible = false;
			leftLamp.visible = false;
			frontFogLamp.visible = false;
			carDoorLamp.visible = false;
			rearFogLamp.visible = false;
			tirePressLamp.visible = false;
			highLamp.visible = false;
			positionLamp.visible = false;

		}
	}

	SequentialAnimation{
		id: runAnimation
		running: false
		loops: Animator.Infinite
		ScriptAction{
			script: {

				runningInfoMenu.visible = true;
				runningInfo.visible = false;
				tirePressMenu.visible = false;
				tirePress.visible = false;
				setMenu.visible = false;
				set.visible = false;
				naviMenu.visible = false;
				navi.visible = false;

				rightLamp.visible = false;
				leftLamp.visible = false;
				frontFogLamp.visible = false;
				carDoorLamp.visible = false;
				rearFogLamp.visible = false;
				tirePressLamp.visible = false;
				highLamp.visible = false;
				positionLamp.visible = false;
			}
		}
		PauseAnimation {duration: 2000}
		ScriptAction{
			script: {
				runningInfoMenu.visible = false;
				runningInfo.visible = true;
				tirePressMenu.visible = false;
				tirePress.visible = false;
				setMenu.visible = false;
				set.visible = false;
				naviMenu.visible = false;
				navi.visible = false;

				rightLamp.visible = false;
				leftLamp.visible = false;
				frontFogLamp.visible = false;
				carDoorLamp.visible = true;
				rearFogLamp.visible = false;
				tirePressLamp.visible = false;
				highLamp.visible = true;
				positionLamp.visible = false;
			}
		}
		PauseAnimation {duration: 2000}
		ScriptAction{
			script: {
				runningInfoMenu.visible = false;
				runningInfo.visible = false;
				tirePressMenu.visible = true;
				tirePress.visible = false;
				setMenu.visible = false;
				set.visible = false;
				naviMenu.visible = false;
				navi.visible = false;


				rightLamp.visible = false;
				leftLamp.visible = true;
				frontFogLamp.visible = true;
				carDoorLamp.visible = false;
				rearFogLamp.visible = true;
				tirePressLamp.visible = false;
				highLamp.visible = false;
				positionLamp.visible = true;
			}
		}
		PauseAnimation {duration: 2000}
		ScriptAction{
			script: {
				runningInfoMenu.visible = false;
				runningInfo.visible = false;
				tirePressMenu.visible = false;
				tirePress.visible = true;
				setMenu.visible = false;
				set.visible = false;
				naviMenu.visible = false;
				navi.visible = false;

				rightLamp.visible = true;
				leftLamp.visible = false;
				frontFogLamp.visible = false;
				carDoorLamp.visible = false;
				rearFogLamp.visible = true;
				tirePressLamp.visible = true;
				highLamp.visible = false;
				positionLamp.visible = true;
			}
		}
		PauseAnimation {duration: 2000}
		ScriptAction{
			script: {
				runningInfoMenu.visible = false;
				runningInfo.visible = false;
				tirePressMenu.visible = false;
				tirePress.visible = false;
				setMenu.visible = true;
				set.visible = false;
				naviMenu.visible = false;
				navi.visible = false;

				rightLamp.visible = false;
				leftLamp.visible = false;
				frontFogLamp.visible = false;
				carDoorLamp.visible = true;
				rearFogLamp.visible = false;
				tirePressLamp.visible = true;
				highLamp.visible = false;
				positionLamp.visible = true;
			}
		}
		PauseAnimation {duration: 2000}
		ScriptAction{
			script: {
				runningInfoMenu.visible = false;
				runningInfo.visible = false;
				tirePressMenu.visible = false;
				tirePress.visible = false;
				setMenu.visible = false;
				set.visible = true;
				naviMenu.visible = false;
				navi.visible = false;

				rightLamp.visible = true;
				leftLamp.visible = false;
				frontFogLamp.visible = true;
				carDoorLamp.visible = false;
				rearFogLamp.visible = false;
				tirePressLamp.visible = true;
				highLamp.visible = false;
				positionLamp.visible = true;
			}
		}
		PauseAnimation {duration: 2000}
		ScriptAction{
			script: {
				runningInfoMenu.visible = false;
				runningInfo.visible = false;
				tirePressMenu.visible = false;
				tirePress.visible = false;
				setMenu.visible = false;
				set.visible = false;
				naviMenu.visible = true;
				navi.visible = false;

				rightLamp.visible = false;
				leftLamp.visible = true;
				frontFogLamp.visible = false;
				carDoorLamp.visible = false;
				rearFogLamp.visible = true;
				tirePressLamp.visible = false;
				highLamp.visible = false;
				positionLamp.visible = true;
			}
		}
		PauseAnimation {duration: 2000}
		ScriptAction{
			script: {
				runningInfoMenu.visible = false;
				runningInfo.visible = false;
				tirePressMenu.visible = false;
				tirePress.visible = false;
				setMenu.visible = false;
				set.visible = false;
				naviMenu.visible = false;
				navi.visible = true;

				rightLamp.visible = false;
				leftLamp.visible = false;
				frontFogLamp.visible = true;
				carDoorLamp.visible = true;
				rearFogLamp.visible = false;
				tirePressLamp.visible = false;
				highLamp.visible = true;
				positionLamp.visible = false;
			}
		}
		PauseAnimation {duration: 2000}
	}

	states: [
		State {
			name: ""
			PropertyChanges { target: midShow; opacity: 0.0 }
		},
		State {
			name: "show"
			PropertyChanges { target: midShow; opacity: 1.0 }
		}
	]

	transitions: [
		Transition {
			from: ""
			to: "show"
			SequentialAnimation{
				NumberAnimation { target: midShow; property: "opacity";duration: 1000; }
				ScriptAction{
					script: {
						runAnimation.running = true;
					}
				}
			}
		},
		Transition {
			from: "show"
			to: ""
			SequentialAnimation{
				NumberAnimation { target: midShow; property: "opacity";duration: 1000; }
				ScriptAction{
					script: {
						runAnimation.running = false;
					}
				}
			}
		}
	]
}
