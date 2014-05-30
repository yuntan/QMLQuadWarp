#include <QApplication>
#include <QtQml>
#include <QtQuick>
#include <QDebug>

#include "homography.h"

QApplication *app;
QQmlApplicationEngine *engine;

int main(int argc, char *argv[])
{
    //    QApplication app(argc, argv);
    app = new QApplication(argc,argv);
    app->setApplicationName("QMLQuadWarp");

    //    QQmlApplicationEngine engine;
    engine = new QQmlApplicationEngine();

    qmlRegisterType<Homography>("QMLQuadWarp", 1, 0, "Homography");

    // read vertex shader and fragment shader file
    QFile fragFile1(":/shader/QuadWarp.vert");
    if(fragFile1.open(QIODevice::ReadOnly)) {
        QTextStream in(&fragFile1);
        engine->rootContext()->setContextProperty(QLatin1String("QuadWarpVertShader"), in.readAll());
        fragFile1.close();
    }

    // qmlファイルをロード
    engine->load(QUrl("qrc:/qml/main.qml"));

    QObject *topLevel = engine->rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    if ( !window ) {
        qWarning("Error: Your root item has to be a Window.");
        return -1;
    }
    window->show();
    return app->exec();
}
