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
    footer: MainWindowFooter {}
    Component.onCompleted: {
        MainController.qmlInit();
    }
}
