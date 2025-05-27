import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
ToolBar {
    background: Rectangle {
        anchors.fill: parent
        color : Style.footerColor
    }
    RowLayout {
        spacing: Style.toolBarSpacing
        ToolBarButton {
            Layout.preferredWidth: Style.toolBarButtonWidth
            text: qsTr("Settings")
            onClicked: {
                settingsWindow.visible = !settingsWindow.visible
            }
        }
        ToolBarButton {
            Layout.preferredWidth: Style.toolBarButtonWidth
            text: qsTr("Metronome")
        }
        SettingsWindow {
            id: settingsWindow
        }
    }
}
