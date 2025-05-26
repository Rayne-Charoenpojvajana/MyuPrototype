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
        QStringList list;
        if (asioThread->isASIORunning()) {
            return list;
        }
        AsioDrivers tempDrivers;
        long numDev = tempDrivers.asioGetNumDev();
        char* drivers[numDev];
        for (int i = 0; i < numDev; i++) {
            drivers[i] = new char[MAX_DRIVER_LENGTH];
        }
        tempDrivers.getDriverNames(drivers, numDev);
        for (int i = 0; i < numDev; i++) {
            list.append(drivers[i]);
            delete drivers[i];
        }
        return list;
    }
    Q_INVOKABLE void setSelectedDriver(QString driver) {
        this->selectedDriver = driver;
        if (asioThread->isASIORunning()) {
            qDebug() << "trying";

        }
    }
public slots:
    void qmlInit() {

    }
    void sendSelectedDriver(char** selectedDriver, bool* await) {
        *selectedDriver = this->selectedDriver.toUtf8().data();
        *await = false;
    }
};

#endif // MAINCONTROLLER_H
