import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ToolBar {
    background: Rectangle {
        anchors.fill: parent
        color : Style.mainWindowBackgroundColor
    }
    RowLayout {
        ColumnLayout {
            Layout.topMargin: 10
            spacing: 2
            ProgressBar {
                id: p0
                Layout.preferredHeight: 14
            }
            ProgressBar {
                id: p1
                Layout.preferredHeight: 16
            }


            Timer {
                repeat: true; interval: 20; running: true
                onTriggered: {
                    const list = MainController.getMonitor()
                    p0.value = Math.abs(list[0])
                    p1.value = Math.abs(list[1])
                }
            }
        }
    }
}
