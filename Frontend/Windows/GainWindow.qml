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
    Component.onCompleted: {
        gainLayer.setGain(initGain)
    }
}
