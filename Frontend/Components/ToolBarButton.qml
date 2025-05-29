import QtQuick
import QtQuick.Controls
ToolButton {
    font.pixelSize: Style.toolBarButtonFontSize
    palette.buttonText: Style.toolBarButtonColor
    background: Rectangle {
        opacity: parent.hovered ? 0.3 : 0
        radius: 3
    }
}
