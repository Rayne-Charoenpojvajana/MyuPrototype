import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ToolBar {
    background: Rectangle {
        anchors.fill: parent
        color : Style.mainWindowBackgroundColor
    }
    // RowLayout {
    //     ColumnLayout {
    //         Layout.topMargin: 10
    //         spacing: 2
    //         ProgressBar {
    //             id: p0
    //             Layout.preferredHeight: 20
    //         }
    //         ProgressBar {
    //             id: p1
    //             Layout.preferredHeight: 20
    //         }

    //     }
    // }
    RowLayout {
        GridLayout {
            Layout.topMargin: 10
            ProgressBar {
                id: p0
                Layout.preferredHeight: 20
                Layout.row: 0
                Layout.column: 0
            }
            Button {
                id: c0
                text: "chain"
                Layout.row: 0
                Layout.column: 1
            }
            ProgressBar {
                id: p1
                Layout.preferredHeight: 20
                Layout.row: 1
                Layout.column: 0
            }
            Button {
                id: c1
                text: "chain"
                Layout.row: 1
                Layout.column: 1
                onClicked: {
                    l1.visible = !l1.visible;
                }
            }
            LayerWindow {
                id: l1

            }
        }
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
