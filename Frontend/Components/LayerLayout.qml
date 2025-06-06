import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../Windows"

RowLayout {
    required property int channel
    ToolButton {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: qsTr("Input " + channel)
    }
    ProgressBar {
        Layout.fillWidth: true
        Layout.fillHeight: true
    }
    ToolButton {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: qsTr("Chain " + channel)
        onClicked: {
            layerWindow.visible = !layerWindow.visible
        }
    }
    ProgressBar {
        Layout.fillWidth: true
        Layout.fillHeight: true
    }
    ToolButton {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: qsTr("Output " + channel)
    }
    LayerWindow {
        id: layerWindow
        channelNum: channel
    }
}
