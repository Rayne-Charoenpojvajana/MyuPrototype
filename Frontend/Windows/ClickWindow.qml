import QtQuick.Controls.Material
import QtQuick
import QtQuick.Controls
import MyuPrototype
import QtQuick.Layouts

Window {
    width: 300
    height: 300

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

    Rectangle
    {
        id: background
        anchors.fill: parent
        color: Style.mainWindowBackgroundColor
    }
    Component.onCompleted: {
        clickLayer.setBPM(initBPM);
        clickLayer.setAccent(initAccent);
    }

    RowLayout {
        ColumnLayout {
            TextField {
                validator: DoubleValidator {

                }
                text: initBPM
                onEditingFinished: {
                    if (text < minBPM || text > maxBPM) {
                        return;
                    }
                    clickLayer.setBPM(text);
                }
            }
            TextField {
                text: initAccent
                validator: IntValidator {

                }
                onEditingFinished: {
                    if (text < minAccent || text > maxAccent) {
                        return;
                    }
                    clickLayer.setAccent(text)
                }
            }
        }
        Dial {
            value: initGain
            onMoved: {
                clickLayer.setGain(value)
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


    MouseArea {
        z: -999
        anchors.fill: parent
        onClicked: {
            forceActiveFocus()
        }
    }


}
