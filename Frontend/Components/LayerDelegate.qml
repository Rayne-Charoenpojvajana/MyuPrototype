import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import MyuPrototype
RowLayout {
    required property string path
    required property bool isEnable
    required property bool isProcess
    required property bool isOutput
    required property int index
    required property int delegateChannel
    uniformCellSizes: true
    Text {
        Layout.fillWidth: true
        Layout.fillHeight: true
        elide: Text.ElideLeft
        text: path
    }
    RowLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true
        CheckBox {
            checked: isEnable
            onToggled: {
                MainController.setLayerEnabled(delegateChannel, index, checked)
            }
        }
        CheckBox {
            checked: isProcess
            onToggled: {
                MainController.setLayerProcess(delegateChannel, index, checked)
            }
        }
        CheckBox {
            checked: isOutput
            onToggled: {
                MainController.setLayerOutput(delegateChannel, index, checked)
            }
        }
        ToolButton {
            text: qsTr("○")
            onClicked: {
                MainController.toggleLayerUI(delegateChannel, index)
            }
        }
        ToolButton {
            text: qsTr("↑")
            onClicked: {
                MainController.swapLayers(delegateChannel, index, index - 1)
            }
        }
        ToolButton {
            text: qsTr("↓")
            onClicked: {
                MainController.swapLayers(delegateChannel, index, index + 1)
            }
        }
        ToolButton {
            text: qsTr("×")
            onClicked: {
                MainController.removeLayer(delegateChannel, index)
            }
        }
    }
}
