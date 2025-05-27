#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "asiothread.h"
#include <QDebug>
#include <QObject>
#include <QtQml/qqmlregistration.h>
#include <QStringListModel>
#include <synchapi.h>

class MainController : public QObject
{
private:
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    ASIOThread* asioThread = new ASIOThread();
    QString selectedDriver = "testing";
public:
    MainController();
    Q_INVOKABLE QStringList getDriversList() {
        return asioThread->getDriversList();
    }
    Q_INVOKABLE void setSelectedDriver(QString driver) {
        this->selectedDriver = driver;
        if (asioThread->getStreaming()) {
            asioThread->setStreaming(false);
        }
    }
    Q_INVOKABLE double getMonitor() {
        return test[0];
    }
public slots:
    void qmlInit() {
        connect(asioThread, &ASIOThread::requestSelectedDriver, this, &MainController::sendSelectedDriver);
        asioThread->start();
    }
    void sendSelectedDriver(char** selectedDriver, bool* await) {
        *selectedDriver = this->selectedDriver.toUtf8().data();
        *await = false;
    }
};

#endif // MAINCONTROLLER_H
