import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Qt.labs.folderlistmodel
import MyuPrototype
ScrollView {
    width: parent.width
    height: parent.height
    required property int channelNumber
    ListView {
        id: lv
        width: parent.width
        height: Style.minListViewHeight
        model: ListModel{}
        delegate: LayerDelegate {
            width: lv.width
            delegateChannel: channelNumber

        }
        Connections {
            target: MainController
            function onUpdateLayers(map) {
                const channel = map["channel"]
                if (channelNumber !== channel) {
                    return
                }
                const paths = map["paths"]
                const isEnables = map["isEnables"]
                const isProcesses = map["isProcesses"]
                const isOutputs = map["isOutputs"]
                lv.model.clear()
                for (let i = 0; i < paths.length; i++) {
                    lv.model.append({
                                          path: paths[i],
                                          isEnable: isEnables[i],
                                          isProcess: isProcesses[i],
                                          isOutput: isOutputs[i]
                                      })
                }
            }
        }
    }
}
