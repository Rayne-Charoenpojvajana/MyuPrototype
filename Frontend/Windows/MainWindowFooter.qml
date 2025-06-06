import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../Components"
ToolBar {
    RowLayout {
        ToolBarButton {
            text: qsTr("Settings")
            onClicked: {
                settingsWindow.visible = !settingsWindow.visible
            }
        }
        SettingsWindow {
            id: settingsWindow
        }
    }
}
