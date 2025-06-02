import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

RowLayout {

    property real bpm: 120
    property real prevVal: 0

    Dial {
        Layout.leftMargin: 25
        Layout.topMargin: 25
        id: control
        background: Rectangle {
            x: control.width / 2 - width / 2
            y: control.height / 2 - height / 2
            implicitWidth: 64
            implicitHeight: 64
            width: Math.max(64, Math.min(control.width, control.height))
            height: width
            color: "transparent"
            radius: width / 2
            border.color: Style.footerColor
            opacity: control.pressed ? 1 : 0.7
        }
        stepSize: 1/20
        wrap: true
        startAngle: 180
        from: 0
        to: 1
        endAngle: 540
        onMoved: {
            input.focus = false
            if (Math.abs(control.value - prevVal) > 1.5/20 && Math.abs(control.value - prevVal) <= 0.98) {
                control.value = prevVal
            }
            if (control.value === 0 && prevVal === 1 && bpm <= 400) {

            } else if (control.value === 1 && prevVal === 0 && bpm >= 20) {

            } else if (control.value > prevVal && bpm < 400) {
                if (!Number.isInteger(bpm)) {
                    bpm = Math.ceil(bpm)
                } else {
                    bpm++
                }
            } else if (control.value < prevVal && bpm > 20) {
                if (!Number.isInteger(bpm)) {
                    bpm = Math.floor(bpm)
                } else {
                    bpm--
                }
            }
            prevVal = control.value
        }
        snapMode: Dial.SnapAlways
        handle: Rectangle {
            id: handleItem
            x: control.background.x + control.background.width / 2 - width / 2
            y: control.background.y + control.background.height / 2 - height / 2
            width: 15
            height: width
            color: Style.inputBarColor
            radius: width
            antialiasing: true
            transform: [
                Translate {
                    y: -Math.min(control.background.width, control.background.height) * 0.4 + handleItem.height / 2
                },
                Rotation {
                    angle: control.angle
                    origin.x: handleItem.width / 2
                    origin.y: handleItem.height / 2
                }
            ]


        }


        TextField {
            id: input
            x: control.width/2 - width/2
            y: control.height - height / 10
            width: 50
            horizontalAlignment: TextField.AlignHCenter
            text: bpm
            background: Rectangle {
                color: "transparent"
            }
            onEditingFinished: {
                if (!isNaN(text)) {
                    if (text >= 20 && text <= 400) {
                        bpm = Math.round(text * 100) / 100
                    }
                }
            }
        }
        Label {
            id: label
            x: control.width/2 - width / 2
            y: control.height + input.height - height/2
            text: "BPM"
        }
    }
    Button {
        id: button
        checkable: true
        implicitWidth: 50
        text: checked ? "On" : "Off"
        onToggled: {

        }
    }
}
