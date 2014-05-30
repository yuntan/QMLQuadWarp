import QtQuick 2.2

Item {
    id: handle
    property alias drag: mouse.drag

    Rectangle {
        property int l: 10
        x: -l; y: -l
        width: 2*l; height: 2*l
        radius: l
        color: "red"
        MouseArea {
            id: mouse
            anchors.fill: parent
            drag.target: handle
            drag.threshold: 0
        }
    }
}
