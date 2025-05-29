import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MyuPrototype

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
            id: row
            Layout.topMargin: 10
            Layout.leftMargin: 10
            ComboBox {
                model: ListModel {
                    id: sModel
                }
                Layout.preferredHeight: 30
                Layout.preferredWidth: 200
                background: Rectangle {
                    color: "#282828"
                    radius: 3
                    border.color: "black"
                    opacity: parent.hovered ? 0.7 : 1
                }
                id: sampleBox
                textRole: "text"
                displayText: currentText
                contentItem: Text {
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 8
                    opacity: parent.pressed ? 0.3 : 1
                    color: "#FFFFFF"
                    text: parent.displayText
                }
                onActivated: {
                    MainController.setSampleRate(currentText)
                }

                Component.onCompleted: {
                    const sampleRates = MainController.getSampleRates()
                    for (const rate of sampleRates) {
                        sModel.append({text: rate})
                    }
                    currentIndex = 0
                    MainController.setSampleRate(currentText)
                }
            }
            ComboBox {
                id: box
                textRole: "text"
                model: ListModel {
                    id: model
                }
                Layout.preferredHeight: 30
                Layout.preferredWidth: 100
                background: Rectangle {
                    color: "#282828"
                    radius: 3
                    border.color: "black"
                    opacity: parent.hovered ? 0.7 : 1
                }
                displayText: currentText
                contentItem: Text {
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 8
                    opacity: parent.pressed ? 0.3 : 1
                    color: "#FFFFFF"
                    text: parent.displayText
                }
                onActivated: {
                    MainController.setBufferSize(currentText)
                }
                Component.onCompleted: {
                    const bufferSizes = MainController.getBufferSizes()
                    for (const size of bufferSizes) {
                        model.append({text: size})
                    }
                    currentIndex = 0
                    MainController.setBufferSize(currentText)
                }
            }
        }
        RowLayout {
            Layout.leftMargin: 10
            ComboBox {
                id: cbox
                model: ListModel {
                    id: listModel
                    ListElement {text: ""}
                }
                displayText: currentText
                textRole: "text"
                Layout.preferredWidth: 300 + row.spacing
                Layout.preferredHeight: 30
                contentItem: Text {
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 8
                    opacity: parent.pressed ? 0.3 : 1
                    color: "#FFFFFF"
                    text: parent.displayText
                }
                background: Rectangle {
                    color: "#282828"

                    radius: 3
                    border.color: "black"
                    opacity: parent.hovered ? 0.7 : 1
                }
                onActivated: {
                    MainController.setSelectedDriver(currentText);
                }
                Timer {
                    repeat: true; interval: 1000; running: true
                    onTriggered: {
                        let drivers = MainController.getDriverList();
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
}

