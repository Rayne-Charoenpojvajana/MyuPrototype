import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ToolBar {
    background: Rectangle {
        anchors.fill: parent
        color : Style.mainWindowBackgroundColor
    }
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
                onClicked: {
                    l0.visible = !l0.visible;
                }
            }
            ProgressBar {
                id: o0
                Layout.preferredHeight: 20
                Layout.row: 0
                Layout.column: 2
            }
            LayerWindow {
                id: l0
                channelNum: 0
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
            ProgressBar {
                id: o1
                Layout.preferredHeight: 20
                Layout.row: 1
                Layout.column: 2
            }
            LayerWindow {
                id: l1
                channelNum: 1
            }
        }
    }
    Timer {
        repeat: true; interval: 20; running: true
        onTriggered: {

        }
    }
}
