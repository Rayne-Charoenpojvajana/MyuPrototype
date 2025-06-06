
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


RowLayout {
    required property var initList
    required property var initElem
    required property string label
    uniformCellSizes: true
    ComboBox {
        Layout.fillWidth: true
        Layout.fillHeight: true
        model: ListModel {}
        textRole: "text"
        Component.onCompleted: {
            let foundIdx = 0
            for(let i = 0; i < initList.length; i++) {
                const elem = initList[i]
                model.append({text: elem});
                if (elem === initElem) {
                    foundIdx = i
                }
            }
            currentIndex = foundIdx
        }
    }
    ToolButton {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: qsTr(label)
    }
}
