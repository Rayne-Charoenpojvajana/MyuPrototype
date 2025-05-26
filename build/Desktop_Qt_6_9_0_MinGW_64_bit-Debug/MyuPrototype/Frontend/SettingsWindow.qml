import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    title: "Settings"
    color: Style.mainWindowBackgroundColor
    width: 400
    height: 225
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    visible: false
    ColumnLayout {
        RowLayout {
            Layout.leftMargin: 10
            Layout.topMargin: 10
            ComboBox {
                id: cbox
                model: ListModel {
                    id: listModel
                    ListElement {text: ""}
                }
                displayText: currentText
                textRole: "text"
                Layout.preferredWidth: 200
                Layout.preferredHeight: 30
                contentItem: Text {
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 8
                    opacity: parent.pressed ? 0.3 : 1
                    color: "#FFFFFF"
                    text: parent.displayText
                }
                background: Rectangle {
                    color: "#969696"
                    radius: 3
                    border.color: "#282828"
                    opacity: parent.hovered ? 0.7 : 1
                }
                onActivated: {
                    MainController.setSelectedDriver(currentText);
                }
            }
            Timer {
                repeat: true; interval: 1000; running: true
                onTriggered: {
                    let drivers = MainController.getDriversList();
                    if (drivers.length === 0) {
                        return
                    }
                    if (listModel.count > 1) {
                        listModel.remove(1, listModel.count - 1)
                    }
                    for (const driver of drivers) {
                        listModel.append({text: driver})
                    }
                }
            }
        }
    }





}
