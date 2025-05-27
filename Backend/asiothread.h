#ifndef ASIOTHREAD_H
#define ASIOTHREAD_H

#include <QThread>
#include <QDebug>
#include "asiofunctions.h"


class ASIOThread : public QThread
{
public:
    explicit ASIOThread(QObject *parent = nullptr)
        : QThread(parent)
    {
    }
    bool getStreaming() {
        return streaming;
    }
    void setStreaming(bool stream) {
        streaming = stream;
    }
    QStringList getDriverList() {
        QStringList list;
        if (getStreaming()) {
            return list;
        }
        extern AsioDrivers helperDrivers;
        long numDev = helperDrivers.asioGetNumDev();
        char* drivers[numDev];
        for (int i = 0; i < numDev; i++) {
            drivers[i] = new char[maxDriverLength];
        }
        helperDrivers.getDriverNames(drivers, numDev);
        for (int i = 0; i < numDev; i++) {
            list.append(drivers[i]);
            delete drivers[i];
        }
        return list;
    }
private:
    Q_OBJECT
    void run() override {
        while(1) {
            msleep(2000);
            char* selectedDriver = (char*) "";
            bool await = true;
            emit requestSelectedDriver(&selectedDriver, &await);
            while(await);
            streaming = true;
            setupASIO(selectedDriver);
            streaming = false;
        }
    }
signals:
    void requestSelectedDriver(char**, bool*);
};

#endif // ASIOTHREAD_H
