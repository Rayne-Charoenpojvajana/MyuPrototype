import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../Components"
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
            text: qsTr("Free Play")
        }
        SettingsWindow {
            id: settingsWindow
        }
    }
}
