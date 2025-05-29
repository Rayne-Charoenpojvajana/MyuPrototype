import QtQuick.Controls.Fusion
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MyuPrototype
import "../Pages"

ApplicationWindow {
    title: "Myu"
    width: 800
    height: 450
    visible: true
    color: Style.mainWindowBackgroundColor
    header: MainWindowHeader {}
    footer: MainWindowFooter {}
    Component.onCompleted: {
        MainController.qmlInit();
    }
    StackView {
        id: stack
        initialItem: freePlay
    }
    FreePlay {
        id: freePlay
    }

    MouseArea {
        anchors.fill: parent
        onClicked: forceActiveFocus()
        z: -999
    }



}
