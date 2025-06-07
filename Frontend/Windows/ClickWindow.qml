import QtQuick.Controls.Material
import QtQuick
import QtQuick.Controls
import MyuPrototype
import QtQuick.Layouts

Item {
    width: Screen.width / 4
    height: Screen.height / 4

    required property ClickLayer clickLayer
    property real initBPM: 120
    property int initAccent: 4
    property real initGain: 0
    property real maxBPM: 400
    property real minBPM: 02
    property int maxAccent: 50
    property int minAccent: 1
    property real maxGain: 20
    property real minGain: -20

    Component.onCompleted: {
        clickLayer.setBPM(initBPM);
        clickLayer.setAccent(initAccent);
        clickLayer.setGain(initGain);
    }
}
