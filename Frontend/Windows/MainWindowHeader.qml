import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../Components"
import MyuPrototype
ColumnLayout {
    width: parent.width / 2
    LayerLayout {
        channel: 0
        id: ll0
    }
    LayerLayout {
        channel: 1
        id: ll1
    }
    Timer {
        running: true; repeat: true; interval: 33
        onTriggered: {
            const inputVals = MainController.getMonitor()
            ll0.inputVal = inputVals[0]
            ll1.inputVal = inputVals[1]
        }
    }
}
