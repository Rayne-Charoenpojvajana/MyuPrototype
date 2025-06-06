import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import MyuPrototype
RowLayout {
    width: parent.width / 2
    ColumnLayout {
        spacing: 0
        Layout.fillHeight: true
        ButtonGroup {
            id: inputGroup
        }
        CheckBox {
            checked: MainController.getInputRoute(channelNum) === 0
            ButtonGroup.group: inputGroup
            onToggled: {
                MainController.setInputRoute(channelNum, 0)
            }
        }
        CheckBox {
            checked: MainController.getInputRoute(channelNum) === 1
            ButtonGroup.group: inputGroup
            onToggled: {
                MainController.setInputRoute(channelNum, 1)
            }
        }
    }
    ComboBox {
        id: cbox
        Layout.fillHeight: true
        Layout.fillWidth: true
        model: ListModel {

        }
        textRole: "text"
        valueRole: "value"
        Component.onCompleted: {
            const paths = MainController.getLayerPaths();
            model.append({text: " "})
            for (const path of paths) {
                model.append({
                                 text: path.substring(path.lastIndexOf("/")),
                                 value: path
                             })
            }
            currentIndex = 0
        }
    }
    ToolButton {
        Layout.fillHeight: true
        text: qsTr("+")
        onClicked: {
            MainController.addLayer(channelNum, cbox.currentValue)
        }
    }
    ColumnLayout {
        spacing: 0
        Layout.fillHeight: true
        ButtonGroup {
            id: outputGroup
        }
        CheckBox {
            checked: MainController.getOutputRoute(channelNum) === 0
            ButtonGroup.group: outputGroup
            onToggled: {
                MainController.setInputRoute(channelNum, 0)
            }
        }
        CheckBox {
            checked: MainController.getOutputRoute(channelNum) === 1
            ButtonGroup.group: outputGroup
            onToggled: {
                MainController.setInputRoute(channelNum, 1)
            }
        }
    }
}
