import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MyuPrototype
import "../Components"
ApplicationWindow {
    required property int channelNum
    width: Screen.width / 4
    height: Screen.height / 4
    title: qsTr("Chain " + channelNum)
    header: LayerWindowHeader {

    }
    LayerComponent {
        channelNumber: channelNum
    }
}
