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
}

