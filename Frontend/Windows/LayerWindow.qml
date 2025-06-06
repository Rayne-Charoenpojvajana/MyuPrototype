import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MyuPrototype
import "../Components"
ApplicationWindow {
    required property int channelNum
    width: Screen.width / 4
    height: Screen.height / 4
    title: qsTr("Chain " + channelNum)
    header: LayerWindowHeader {

    }
    LayerComponent {
        channelNumber: channelNum
    }
}

// ApplicationWindow {
//     property int channelNum
//     width: 400
//     height: 225
//     minimumWidth: width
//     minimumHeight: height
//     maximumWidth: width
//     maximumHeight: height
//     title: channelNum

//     ListModel {
//         id: listModel
//     }
//     ColumnLayout {
//         RowLayout {
//             ButtonGroup {
//                 id: switchGroup
//             }
//             ButtonGroup {
//                 id: switchGroup2
//             }
//             CheckBox {
//                 id: in0
//                 ButtonGroup.group: switchGroup
//                 onClicked: {
//                     MainController.setInputRoute(channelNum, 0)
//                 }
//             }
//             CheckBox {
//                 id: in1
//                 ButtonGroup.group: switchGroup
//                 onClicked: {
//                     MainController.setInputRoute(channelNum, 1)
//                 }
//             }
//             Component.onCompleted: {
//                 const res = MainController.getInputRoute(channelNum)
//                 in0.checked = res === 0
//                 in1.checked = res === 1;
//             }

//             ComboBox {
//                 model: listModel
//                 Layout.preferredWidth: 200
//                 textRole: "name"
//                 valueRole: "path"
//                 id: control
//                 delegate: ItemDelegate {
//                     required property var model
//                     required property int index
//                     width: ListView.view.width
//                     palette.text: control.palette.text
//                     palette.highlightedText: control.palette.highlightedText
//                     font.weight: control.currentIndex === index ? Font.DemiBold : Font.Normal
//                     highlighted: control.highlightedIndex === index
//                     hoverEnabled: control.hoverEnabled
//                     text: model[control.textRole]
//                 }
//                 Component.onCompleted: {
//                     const list = MainController.getLayerPaths()
//                     for (const elem of list) {
//                         const shortelem = elem.substring(elem.lastIndexOf("/"))
//                         listModel.append({name: shortelem, path: elem})
//                     }
//                 }
//             }
//             Button {
//                 text: qsTr("+")
//                 Layout.maximumWidth: 30
//                 onClicked: {
//                     if (control.currentValue === "") {
//                         return
//                     }
//                     MainController.addLayer(channelNum, control.currentValue)
//                 }
//             }
//             Connections {
//                 target: MainController
//                 function onUpdateLayers(map) {
//                     const channel = map["channel"]
//                     if (channelNum !== channel) {
//                         return
//                     }
//                     const paths = map["paths"]
//                     const isEnables = map["isEnables"]
//                     const isProcesses = map["isProcesses"]
//                     const isOutputs = map["isOutputs"]
//                     layerModel.clear()
//                     for (let i = 0; i < paths.length; i++) {
//                         layerModel.append({
//                                               path: paths[i],
//                                               isEnable: isEnables[i],
//                                               isProcess: isProcesses[i],
//                                               isOutput: isOutputs[i]
//                                           })
//                     }
//                 }
//             }
//         }
//         ListView {
//             Layout.preferredHeight: 200
//             Layout.preferredWidth: 200
//             model: ListModel {
//                 id: layerModel
//             }
//             delegate: RowLayout {
//                 spacing: 0
//                 Button {
//                     Layout.minimumWidth: 100
//                     Layout.maximumWidth: 100
//                     contentItem: Text {
//                         text: index + qsTr("->") + qsTr(path)
//                         horizontalAlignment: Text.AlignLeft
//                         elide: Text.ElideLeft
//                     }
//                     onClicked: {
//                         MainController.toggleLayerUI(channelNum, index)
//                     }
//                 }
//                 CheckBox {
//                     checked: isEnable
//                     onToggled: {
//                         MainController.setLayerEnabled(channelNum, index, checked)
//                     }
//                 }
//                 CheckBox {
//                     checked: isProcess
//                     onToggled: {
//                         MainController.setLayerProcess(channelNum, index, checked)
//                     }
//                 }
//                 CheckBox {
//                     checked: isOutput
//                     onToggled: {
//                         MainController.setLayerOutput(channelNum, index, checked)
//                     }
//                 }
//                 Button {
//                     text: qsTr("↓")
//                     Layout.maximumWidth: 30
//                     onClicked: {
//                         MainController.swapLayers(channelNum, index, index+1)
//                     }
//                 }
//                 Button {
//                     text: qsTr("↑")
//                     Layout.maximumWidth: 30
//                     onClicked: {
//                         MainController.swapLayers(channelNum, index, index-1)
//                     }
//                 }
//                 Button {
//                     text: qsTr("-")
//                     Layout.maximumWidth: 30
//                     onClicked: {
//                         MainController.removeLayer(channelNum, index)
//                     }
//                 }
//                 required property string path
//                 required property int index
//                 required property bool isEnable
//                 required property bool isProcess
//                 required property bool isOutput
//             }
//         }

//     }
// }
