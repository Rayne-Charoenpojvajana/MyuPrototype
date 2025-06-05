#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>








#include "Backend/Layer/vst3layer.h";
static VST3Layer layer;
int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/logo.png"));
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MyuPrototype", "MainWindow");
    layer.setupUI();
















    return app.exec();
}
