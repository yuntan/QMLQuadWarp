import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: mainWindow
    width: 600; height: 600

    QuadWarp {
        id: quadWarp
        anchors.fill: parent
        source: image
    }

    Image {
        id: image
        visible: false
        source: "file:///home/yuntan/Download/sample.jpg"
    }
}
