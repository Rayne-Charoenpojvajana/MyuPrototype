
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


RowLayout {
    required property var initList
    required property var initElem
    required property string label
    ComboBox {
        Layout.fillWidth: true
        Layout.fillHeight: true
        model: ListModel {}
        Component.onCompleted: {
            let foundIdx = 0
            for(let i = 0; i < initList.length; i++) {
                const elem = initList[i]
                model.append({display: elem});
                if (elem === initElem) {
                    foundIdx = i
                }
            }
            currentIndex = foundIdx
        }
    }
    Button {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: qsTr(label)
    }

}
