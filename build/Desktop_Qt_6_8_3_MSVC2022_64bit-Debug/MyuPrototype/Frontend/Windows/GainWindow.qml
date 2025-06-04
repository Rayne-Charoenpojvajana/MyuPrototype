import QtQuick.Controls.Basic
import QtQuick
import QtQuick.Controls
Item {
    width: 300
    height: 300
    required property GainLayer gainLayer
    property real initGain: 0
    property real minGain: -20
    property real maxGain: 20
    Rectangle
    {
        id: background
        anchors.fill: parent
        color: Style.mainWindowBackgroundColor
    }
    Component.onCompleted: {
        gainLayer.setGain(initGain)
    }

    Dial {
        value: initGain
        onMoved: {
            gainLayer.setGain(value)
        }
        Label {
            text: Math.round(100 * parent.value) / 100
            x: parent.width/2 - width/2
            y: parent.height/2 - height/2
        }
        from: minGain
        to: maxGain
    }
}
