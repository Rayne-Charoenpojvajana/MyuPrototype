import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 400
    height: 225
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    ListView {
        anchors.fill: parent
        ButtonGroup { id: group1}
        ButtonGroup { id: group2}
        model: ListModel {

        }
        delegate: RowLayout {
            spacing: 0
            Button {
                Layout.maximumWidth: 100
                text: name
            }
            CheckBox {
                ButtonGroup.group: group1
            }
            CheckBox {
                ButtonGroup.group: group2
            }
            CheckBox {

            }
            required property int index
            required property string name
        }
    }
    Timer {
        repeat: true; interval: 100; running: true
        onTriggered: {

        }
    }
}
