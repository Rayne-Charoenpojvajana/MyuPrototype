import QtQuick.Controls.Material
import QtQuick
import QtQuick.Controls
Item {
    // required property ClickLayer layer
    width: 300
    height: 300
    property real bpm
    Rectangle
    {
        id: background
        anchors.fill: parent
        color: "black"
    }
    Dial {
        onMoved: {
            MainController.test()
        }
    }
}
