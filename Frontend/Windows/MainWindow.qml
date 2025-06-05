import QtQuick.Controls.Fusion
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    title: "Myu"
    width: 800
    height: 450
    visible: true
    color: Style.mainWindowBackgroundColor
    header: MainWindowHeader {}
    footer: MainWindowFooter {}
    onClosing: (close) => {
        MainController.close()
    }
}
