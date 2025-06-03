import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MyuPrototype
ApplicationWindow {
    property int channelNum
    width: 400
    height: 225
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    title: channelNum

    ListModel {
        id: listModel
    }
    ColumnLayout {
        RowLayout {
            ButtonGroup {
                id: switchGroup
            }
            ButtonGroup {
                id: switchGroup2
            }
            CheckBox {
                checked: channelNum === 0
                ButtonGroup.group: switchGroup
                onClicked: {
                    MainController.setInputRoute(channelNum, 0)
                }
            }
            CheckBox {
                checked: channelNum === 1
                ButtonGroup.group: switchGroup
                onClicked: {
                    MainController.setInputRoute(channelNum, 1)
                }
            }
            CheckBox {
                checked: channelNum === 0
                ButtonGroup.group: switchGroup2
                onClicked: {
                    MainController.setOutputRoute(channelNum, 0)
                }
            }
            CheckBox {
                checked: channelNum === 1
                ButtonGroup.group: switchGroup2
                onClicked: {
                    MainController.setOutputRoute(channelNum, 1)
                }
            }
            ComboBox {
                model: listModel
                textRole: "path"
                id: box
                Component.onCompleted: {
                    const list1 = MainController.getLayerPaths("Gains")
                    for (const elem1 of list1) {
                        listModel.append({path: elem1})
                    }
                    const list2 = MainController.getLayerPaths("Clicks")
                    for (const elem2 of list2) {
                        listModel.append({path: elem2})
                    }
                    currentIndex = 0
                }
            }
            Button {
                text: qsTr("+")
                Layout.maximumWidth: 30
                onClicked: {
                    MainController.addLayer(channelNum, box.currentText)
                    layerModel.append({path: box.currentText})
                }
            }
        }
        ListView {
            Layout.preferredHeight: 200
            Layout.preferredWidth: 200
            ButtonGroup { id: group1}
            ButtonGroup { id: group2}
            model: ListModel {
                id: layerModel
            }
            delegate: RowLayout {
                spacing: 0
                Button {
                    Layout.minimumWidth: 100
                    Layout.maximumWidth: 100
                    contentItem: Text {
                        text: index + qsTr("->") + qsTr(path)
                        horizontalAlignment: Text.AlignLeft
                        elide: Text.ElideRight
                    }
                    onClicked: {
                        MainController.toggleLayerUI(channelNum, index)
                    }
                }
                CheckBox {
                    ButtonGroup.group: group1
                    onToggled: {
                        MainController.setLayerProcess(channelNum, index, checked)
                    }
                }
                CheckBox {
                    ButtonGroup.group: group2
                    onToggled: {
                        MainController.setLayerOutput(channelNum, index, checked)
                    }


                }
                CheckBox {
                    onToggled: {
                        MainController.setLayerEnabled(channelNum, index, checked)
                    }
                }
                Button {
                    text: qsTr("↓")
                    Layout.maximumWidth: 30
                    onClicked: {
                        if (index >= layerModel.count - 1) {
                            return
                        }
                        MainController.swapLayers(channelNum, index, index+1)
                        layerModel.move(index, Math.min(layerModel.count-1, index+1), 1)
                    }
                }
                Button {
                    text: qsTr("↑")
                    Layout.maximumWidth: 30
                    onClicked: {
                        if (index <= 0) {
                            return
                        }
                        MainController.swapLayers(channelNum, index, index-1)
                        layerModel.move(index, Math.max(0, index-1), 1)
                    }
                }
                Button {
                    text: qsTr("-")
                    Layout.maximumWidth: 30
                    onClicked: {
                        MainController.removeLayer(channelNum, index)
                        layerModel.remove(index, 1)
                    }
                }
                required property string path
                required property int index
            }
        }

    }
    Timer {
        repeat: true; interval: 100; running: true
        onTriggered: {

        }
    }
}
