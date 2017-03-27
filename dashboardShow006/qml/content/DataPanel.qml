import QtQuick 2.3

Item {
	id:dataPanel
	opacity:0.0

	Image {
		id: odo_trip
		x: 621
		y: 667
		opacity: 1.0
		width: 682
		height: 28
		source: "qrc:/images/odo_trip.png"
	}
	Image {
		id: time_temp
		x: 598
		y: 60
		opacity: 1.0
		width: 747
		height: 29
		source: "qrc:/images/time_temp.png"
	}

	Rectangle{
		id: socBar
		x: 41
		y: 396
		opacity: 1.0
		width: 211
		height: 316
		color: "#00000000"
		property real barAngle: 65 // 0- 64
		transform:Rotation{
			origin.x:388 - socBar.x
			origin.y:400 - socBar.y
			angle: 32 - socBar.barAngle//-90//-180
		}
		clip: true
		Image {
			id: bar
			x: 0
			y: 0
			opacity: 1.0
			width: 211
			height: 316
			source: "qrc:/images/bar.png"
			transform:Rotation{
				origin.x:388 - socBar.x
				origin.y:400 - socBar.y
				angle: socBar.barAngle//-90//-180
			}
		}
	}

	Rectangle{
		id: waterTempBar
		x: 41+ 1626
		y: 396
		opacity: 1.0
		width: 211
		height: 316
		color: "#00000000"
		property real barAngle: 65 // 0- 64
		transform:Rotation{
			origin.x:1533 - waterTempBar.x
			origin.y:400 - waterTempBar.y
			angle: -32 + waterTempBar.barAngle//-90//-180
		}
		clip: true
		Image {
			x: 0
			y: 0
			opacity: 1.0
			width: 211
			height: 316
			mirror: true
			source: "qrc:/images/bar.png"
			transform:Rotation{
				origin.x:1533 - waterTempBar.x
				origin.y:400 - waterTempBar.y
				angle: -waterTempBar.barAngle//-90//-180
			}
		}
	}



	Item{
		id: gear
		x: 350
		y: 360
		Image{
			id: p
			visible: false
			source:"qrc:/gear/images/gear/P.png"
			Behavior on visible {
				NumberAnimation {
					target: p
					property: "scale"
					duration: 300
					from: 0.0
					to: 1.0
				}
			}
		}
		Image{
			id: r
			visible: false
			source:"qrc:/gear/images/gear/R.png"
			Behavior on visible {
				NumberAnimation {
					target: r
					property: "scale"
					duration: 300
					from: 0.0
					to: 1.0
				}
			}
		}
		Image{
			id: n
			visible: false
			source:"qrc:/gear/images/gear/N.png"
			Behavior on visible {
				NumberAnimation {
					target: n
					property: "scale"
					duration: 300
					from: 0.0
					to: 1.0
				}
			}
		}
		Image{
			id: d
			visible: false
			source:"qrc:/gear/images/gear/D.png"
			Behavior on visible {
				NumberAnimation {
					target: d
					property: "scale"
					duration: 300
					from: 0.0
					to: 1.0
				}
			}
		}
	}

	property real kwV: 0 // 0 -240


	Row{
		x: 1337 - 1145
		y: 205
		Rectangle{
			opacity: 1.0
			width: 196
			height: 390
			clip: true
			color: "#00000000"
			Image {
				source: "qrc:/images/ring.png"
				transform:Rotation{
					origin.x:388 - 1337 + 1145
					origin.y:400 - 205
					angle: {
						if(dataPanel.kwV >= 180.0)
							return 0;
						if(dataPanel.kwV < 180.0 && dataPanel.kwV >=0.0 )
							return -180.0 + dataPanel.kwV;
					}
				}
			}
		}

		Rectangle{
			opacity: 1.0
			width: 196
			height: 390
			clip: true
			color: "#00000000"
			Image {
				source: "qrc:/images/ring.png"
				mirror: true
				transform:Rotation{
					origin.x:388 - 1337 - 196 + 1145
					origin.y:400 - 205
					angle: {
						if(dataPanel.kwV >= 180.0)
							return -180.0 + (dataPanel.kwV - 180.0)/180.0*180.0;
						if(dataPanel.kwV < 180.0 && dataPanel.kwV >=0.0 )
							return -180.0;
					}
				}
			}
		}
	}

	Image {
		id: point1
		x: 1531 - 1145
		y: 551
		visible: dataPanel.opacity == 1.0
		source: "qrc:/images/point.png"
		transform:Rotation{
			origin.x:388 - 1531 + 1145
			origin.y:400 - 551
			angle: dataPanel.kwV
		}
	}

	Image {
		id: pointMask1
		x: 1531- 1145
		y: 551
		opacity: 1.0
		width: 59
		height: 45
		source: "qrc:/images/pointMask.png"
	}

	property real speedV: 0 // 0 -220
	Item{
		id: speedValue
		x: 1435
		y: 360
		width: 68*3
		height: 62
		DigitValue{
			anchors.centerIn: speedValue
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
			value: dataPanel.speedV
			spacing: -5
		}
	}
	Row{
		x: 1337
		y: 205
		Rectangle{
			opacity: 1.0
			width: 196
			height: 390
			clip: true
			color: "#00000000"
			Image {
				source: "qrc:/images/ring.png"
				transform:Rotation{
					origin.x:1533 - 1337
					origin.y:400 - 205
					angle: {
						if(dataPanel.speedV >= 150.0)
							return 0;
						if(dataPanel.speedV < 150.0 && dataPanel.speedV >=0.0 )
							return -180.0 + dataPanel.speedV/150.0*180.0;
					}
				}
			}
		}

		Rectangle{
			opacity: 1.0
			width: 196
			height: 390
			clip: true
			color: "#00000000"
			Image {
				source: "qrc:/images/ring.png"
				mirror: true
				transform:Rotation{
					origin.x:1533 - 1337 - 196
					origin.y:400 - 205
					angle: {
						if(dataPanel.speedV >= 150.0)
							return -180.0 + (dataPanel.speedV - 150.0)/150.0*180.0;
						if(dataPanel.speedV < 150.0 && dataPanel.speedV >=0.0 )
							return -180.0;
					}
				}
			}
		}
	}

	Image {
		id: point
		x: 1531
		y: 551
		visible: dataPanel.opacity === 1.0
		source: "qrc:/images/point.png"
		transform:Rotation{
			origin.x:1533 - 1531
			origin.y:400 - 551
			angle: dataPanel.speedV/220.0 * 264.0
		}
	}

	Image {
		id: pointMask
		x: 1531
		y: 551
		opacity: 1.0
		width: 59
		height: 45
		source: "qrc:/images/pointMask.png"
	}

	Image {
		id: mode
		x: 1419
		y: 449
		opacity: 1.0
		width: 243
		height: 67
		source: "qrc:/images/mode.png"
	}

	MidShow{
		id: midShow
		state: ""
	}

	states: [
		State {
			name: ""
			PropertyChanges { target: dataPanel; opacity: 0.0 }
			PropertyChanges { target: midShow; state: "" }
		},
		State {
			name: "show"
			PropertyChanges { target: dataPanel; opacity: 1.0 }
			PropertyChanges { target: midShow; state: "show" }
		}
	]

	transitions: [
		Transition {
			from: ""
			to: "show"
			SequentialAnimation{
				NumberAnimation { target: dataPanel; property: "opacity"; to: 1.0; duration: 1000 }
				ParallelAnimation{
					NumberAnimation { target: socBar; property: "barAngle"; to: 0; duration: 1000 }
					NumberAnimation { target: waterTempBar; property: "barAngle"; to: 0; duration: 1000 }
				}
				ParallelAnimation{
					NumberAnimation { target: socBar; property: "barAngle"; to: 13; duration: 500 }
					NumberAnimation { target: waterTempBar; property: "barAngle"; to: 20; duration: 500 }
				}
				ScriptAction{
					script: {
						p.visible = true;
						r.visible = false;
						n.visible = false;
						d.visible = false;
					}
				}

				PauseAnimation {duration: 500}
				ScriptAction{
					script: {
						p.visible = false;
						r.visible = false;
						n.visible = true;
						d.visible = false;
					}
				}

				PauseAnimation {duration: 500}
				ScriptAction{
					script: {
						p.visible = false;
						r.visible = false;
						n.visible = false;
						d.visible = true;
					}
				}
				ParallelAnimation{
					SequentialAnimation{
						NumberAnimation { target: dataPanel; property: "speedV"; to: 60; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 120; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 210; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 40; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 5; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 80; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 111; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 211; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 77; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 19; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 204; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 160; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 140; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 70; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "speedV"; to: 0; duration: 1000; }
					}
					SequentialAnimation{
						NumberAnimation { target: dataPanel; property: "kwV"; to: 77; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 19; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 204; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 160; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 140; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 60; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 120; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 210; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 40; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 5; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 80; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 111; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 211; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 70; duration: 1000; }
						NumberAnimation { target: dataPanel; property: "kwV"; to: 0; duration: 1000; }
					}
				}
				ScriptAction{
					script: {
						p.visible = true;
						r.visible = false;
						n.visible = false;
						d.visible = false;
					}
				}

				PauseAnimation {duration: 500}
				ScriptAction{
					script: {
						dataPanel.state = ""
					}
				}

			}

		},
		Transition {
			from: "show"
			to: ""
			SequentialAnimation{
				NumberAnimation { target: socBar; property: "barAngle"; to: 65; duration: 0 }
				NumberAnimation { target: waterTempBar; property: "barAngle"; to: 65; duration: 0 }
				ScriptAction{
					script: {
						p.visible = false;
						r.visible = false;
						n.visible = false;
						d.visible = false;
					}
				}
			}
		}
	]
}
