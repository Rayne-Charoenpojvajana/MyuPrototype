import QtQuick.Controls.Material
import QtQuick
import QtQuick.Controls
import MyuPrototype

Item {
    width: 300
    height: 300
    property real bpm
    required property ClickLayer clickLayer

    Rectangle
    {
        id: background
        anchors.fill: parent
        color: Style.mainWindowBackgroundColor
    }
    Dial {
        onMoved: {

        }
    }
}
