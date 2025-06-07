import QtQuick.Controls.Fusion
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Shapes
ApplicationWindow {
    title: qsTr("Myu")
    visible: true
    width: Screen.width / 2
    height: Screen.height / 2
    header: MainWindowHeader {}
    footer: MainWindowFooter {}
    Grid {
        rows: 5
        columns: 12
        spacing: 12
        Repeater {
            model: 60
            Rectangle {
                width: 50
                height: 50
            }
        }
    }
    property bool flag: false
    onClosing: (close) => {
                   MainController.close()
               }
}
