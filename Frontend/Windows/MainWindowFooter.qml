import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ToolBar {
    RowLayout {
        ToolButton {
            text: qsTr("Settings")
            onClicked: {
                settingsWindow.visible = !settingsWindow.visible
            }
        }
    }
    SettingsWindow {
        id: settingsWindow
    }
}
