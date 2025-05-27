import QtQuick
import QtQuick.Window
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

Item {
    property int from_value
    property int to_value
    property int range_1
    property int range_2
    property int range_3
    property alias vlaue: main_progress_bar.value
    property string unit

    ProgressBar{
        anchors.centerIn: parent
        id:main_progress_bar
        from: from_value
        to: to_value

        property string actual_color: "green"

        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 6
            color: "transparent"
            radius: 3
        }

        contentItem:
            Rectangle{
            color: "transparent"
            implicitWidth: 100
            implicitHeight: implicitWidth
            Rectangle
            {
                id: outerRing
                z: 10
                anchors.fill: parent
                radius: Math.max(width, height) / 2
                color: "transparent"
                border.color: "gray"
                border.width: 5
            }
            Rectangle
            {
                id: innerRing
                z: 10
                anchors.fill: parent
                anchors.margins: (outerRing.border.width - border.width) / 2
                radius: outerRing.radius
                color: "transparent"
                border.color: "darkgray"
                border.width: 3

                ConicalGradient
                {
                    source: innerRing
                    anchors.fill: parent
                    gradient: Gradient
                    {
                        GradientStop { position: 0.00; color: main_progress_bar.actual_color }
                        GradientStop { position: main_progress_bar.value/100; color: main_progress_bar.actual_color }
                        GradientStop { position: (main_progress_bar.value/100) + 0.01; color: "transparent" }
                        GradientStop { position: 1.00; color: "transparent" }
                    }
                }
            }
            Label
            {
                id: progressLabel
                anchors.centerIn: parent
                color: main_progress_bar.value >= range_2? "red": main_progress_bar.value >= range_1? "#ffe208" : "green"
                text: (main_progress_bar.value.toFixed(1)) + "°"
                font.pixelSize: 20
            }
        }
    }
}
