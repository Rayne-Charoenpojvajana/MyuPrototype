import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MyuPrototype
import "../Components"

ApplicationWindow {
    title: qsTr("Settings")
    width: Screen.width / 4
    height: Screen.height / 4
    ColumnLayout {
        width: parent.width / 2
        SettingsLayout {
            id: driver
            initList: MainController.getDrivers()
            initElem: MainController.getSelectedDriver()
            label: qsTr("ASIO Driver")
        }
        SettingsLayout {
            initList: MainController.getSampleRates()
            initElem: MainController.getSelectedSampleRate()
            label: qsTr("Sample Rate")
        }
        SettingsLayout {
            initList: MainController.getBufferSizes()
            initElem: MainController.getSelectedBuffer()
            label: qsTr("Buffer Size")
        }
    }

    // ColumnLayout {
    //     RowLayout {
    //         id: row
    //         Layout.topMargin: 10
    //         Layout.leftMargin: 10
    //         ComboBox {
    //             model: ListModel {

    //             }
    //             Layout.preferredHeight: 30
    //             Layout.preferredWidth: 200
    //             background: Rectangle {
    //                 color: "#282828"
    //                 radius: 3
    //                 border.color: "black"
    //                 opacity: parent.hovered ? 0.7 : 1
    //             }
    //             id: sampleBox
    //             textRole: "text"
    //             displayText: currentText
    //             contentItem: Text {
    //                 verticalAlignment: Text.AlignVCenter
    //                 leftPadding: 8
    //                 opacity: parent.pressed ? 0.3 : 1
    //                 color: "#FFFFFF"
    //                 text: parent.displayText
    //             }
    //             onActivated: {
    //                 MainController.setSampleRate(currentText)
    //             }

    //             Component.onCompleted: {
    //                 const selected = MainController.getSelectedSampleRate()
    //                 const list = MainController.getSampleRates()
    //                 row.setup(sampleBox, selected, list)
    //             }
    //         }
    //         ComboBox {
    //             id: box
    //             textRole: "text"
    //             model: ListModel {

    //             }
    //             Layout.preferredHeight: 30
    //             Layout.preferredWidth: 100
    //             background: Rectangle {
    //                 color: "#282828"
    //                 radius: 3
    //                 border.color: "black"
    //                 opacity: parent.hovered ? 0.7 : 1
    //             }
    //             displayText: currentText
    //             contentItem: Text {
    //                 verticalAlignment: Text.AlignVCenter
    //                 leftPadding: 8
    //                 opacity: parent.pressed ? 0.3 : 1
    //                 color: "#FFFFFF"
    //                 text: parent.displayText
    //             }
    //             onActivated: {
    //                 MainController.setBufferSize(currentText)
    //             }
    //             Component.onCompleted: {
    //                 const selected = MainController.getSelectedBuffer()
    //                 const list = MainController.getBufferSizes()
    //                 row.setup(box, selected, list)

    //             }

    //         }
    //         function setup(box, selected, list) {
    //             let idx = 0
    //             let found = false
    //             for(const elem of list) {
    //                 box.model.append({text: elem})
    //                 if (selected === elem) {
    //                     found = true
    //                     box.currentIndex = idx
    //                 }
    //                 idx++
    //             }
    //             if (!found) {
    //                 box.currentIndex = 0
    //                 MainController.setBufferSize(box.currentText)
    //             }
    //         }
    //     }
    //     RowLayout {
    //         Layout.leftMargin: 10
    //         ComboBox {
    //             id: cbox
    //             model: ListModel {
    //                 id: listModel
    //                 ListElement {text: ""}
    //             }
    //             displayText: currentText
    //             textRole: "text"
    //             Layout.preferredWidth: 300 + row.spacing
    //             Layout.preferredHeight: 30
    //             contentItem: Text {
    //                 verticalAlignment: Text.AlignVCenter
    //                 leftPadding: 8
    //                 opacity: parent.pressed ? 0.3 : 1
    //                 color: "#FFFFFF"
    //                 text: parent.displayText
    //             }
    //             background: Rectangle {
    //                 color: "#282828"

    //                 radius: 3
    //                 border.color: "black"
    //                 opacity: parent.hovered ? 0.7 : 1
    //             }
    //             onActivated: {
    //                 MainController.setSelectedDriver(currentText);
    //             }
    //             Timer {
    //                 repeat: true; interval: 2000; running: true; triggeredOnStart: true
    //                 onTriggered: {
    //                     const selected = MainController.getSelectedDriver()
    //                     const list = MainController.getDrivers()
    //                     listModel.clear()
    //                     row.setup(cbox, selected, list)
    //                 }
    //             }
    //         }

    //     }
    // }
}

