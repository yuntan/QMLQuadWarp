TARGET = QMLQuadWarp
TEMPLATE = app

QT += qml quick widgets

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    src/main.cpp \
    src/homography.cpp

QML_FILES += $$files(qml/*.qml)

JS_FILES += $$files(js/*.js)

OTHER_FILES += \
    $$QML_FILES \
    $$JS_FILES \
    shader/QuadWarp.vert

RESOURCES += \
    qml.qrc

HEADERS += \
    src/homography.h
