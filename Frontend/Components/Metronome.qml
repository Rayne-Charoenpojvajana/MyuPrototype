import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

RowLayout {
    TextEdit {
        text: "what"
    }

    // Dial {
    //     Layout.leftMargin: 25
    //     Layout.topMargin: 25
    //     id: control
    //     background: Rectangle {
    //         x: control.width / 2 - width / 2
    //         y: control.height / 2 - height / 2
    //         implicitWidth: 40
    //         implicitHeight: 40
    //         width: Math.max(64, Math.min(control.width, control.height))
    //         height: width
    //         color: "transparent"
    //         radius: width / 2
    //         border.color: Style.footerColor
    //         opacity: control.pressed ? 1 : 0.7
    //     }
    //     stepSize: 1
    //     wrap: true
    //     startAngle: 180
    //     endAngle: 540
    //     onWrapped: function(dir) {
    //         if (value === 20) {
    //             wrapped = false
    //             return
    //         }

    //         if (dir === Dial.Clockwise) {
    //             from += 20
    //             to += 20
    //         }
    //         if (dir === Dial.CounterClockwise) {
    //             from -= 20
    //             to -= 20
    //         }



    //     }

    //     snapMode: Dial.SnapAlways
    //     from: 20
    //     to: 40
    //     Label {
    //         text: control.value + qsTr("\nBPM")
    //         verticalAlignment: Text.AlignVCenter
    //         horizontalAlignment: Text.AlignHCenter
    //         x: control.width / 2 - width / 2
    //         y: control.height + height
    //     }

    //     handle: Rectangle {
    //         id: handleItem
    //         x: control.background.x + control.background.width / 2 - width / 2
    //         y: control.background.y + control.background.height / 2 - height / 2
    //         width: 9
    //         height: width
    //         color: Style.inputBarColor
    //         radius: width
    //         antialiasing: true
    //         transform: [
    //             Translate {
    //                 y: -Math.min(control.background.width, control.background.height) * 0.4 + handleItem.height / 2
    //             },
    //             Rotation {
    //                 angle: control.angle
    //                 origin.x: handleItem.width / 2
    //                 origin.y: handleItem.height / 2
    //             }
    //         ]
    //     }
    // }

}
