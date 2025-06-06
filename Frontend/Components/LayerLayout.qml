import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Shapes
import QtQuick.Particles
RowLayout {
    required property int channel
    Button {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: qsTr("Input " + channel)
    }
    ProgressBar {
        Layout.fillWidth: true
        Layout.fillHeight: true
    }
    Button {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: qsTr("Chain " + channel)
    }
    ProgressBar {
        Layout.fillWidth: true
        Layout.fillHeight: true
    }
    Button {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: qsTr("Output " + channel)
    }
}
