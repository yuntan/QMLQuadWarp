import QtQuick 2.2
import QMLQuadWarp 1.0

Item {
    id: _root
    property alias source: effect.source
    property bool __initialized: undefined

    function reset() {
        h1.x = source.width + (width - source.width) / 2; h1.y = (height - source.height) / 2
        h2.x = (width - source.width) / 2;                h2.y = (height - source.height) / 2
        h3.x = (width - source.width) / 2;                h3.y = source.height + (height - source.height) / 2
        h4.x = source.width + (width - source.width) / 2; h4.y = source.height + (height - source.height) / 2
    }

    Component.onCompleted: __initialized = false
    onWidthChanged: {
        if(!__initialized) {
            reset()
            __initialized = true
        }
    }

    ShaderEffect {
        id: effect
        anchors.fill: parent

        property Item source
        property real w: source.width / width
        property real h: source.height / height
        property alias homography: h.matrix

        Homography {
            id: h

            p1: Qt.point(h1.x, h1.y)
            p2: Qt.point(h2.x, h2.y)
            p3: Qt.point(h3.x, h3.y)
            p4: Qt.point(h4.x, h4.y)
            sourceSize: Qt.size(source.width, source.height)
        }

        vertexShader: QuadWarpVertShader
    }

    Handle { id: h1 }
    Handle { id: h2 }
    Handle { id: h3 }
    Handle { id: h4 }
}
