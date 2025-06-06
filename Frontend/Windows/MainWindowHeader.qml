import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../Components"
ColumnLayout {
    width: parent.width / 2
    LayerLayout {
        channel: 0
    }
    LayerLayout {
        channel: 1
    }
}
