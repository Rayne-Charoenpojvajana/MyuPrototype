#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include "Backend/asiothread.h"
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
    ASIOThread* thread = new ASIOThread();
    thread->start();
    return app.exec();
}
