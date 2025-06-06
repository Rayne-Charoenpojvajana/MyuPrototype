import QtQuick.Controls.Fusion
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
ApplicationWindow {
    title: qsTr("Myu")
    visible: true
    width: Screen.width / 2
    height: Screen.height / 2
    header: MainWindowHeader {}
    footer: MainWindowFooter {}
    onClosing: (close) => {
                   MainController.close()
               }
}
