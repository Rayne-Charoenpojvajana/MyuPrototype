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
    bool isASIORunning() {
        return asioRunning;
    }
private:
    Q_OBJECT
    bool asioRunning = false;
    void run() override {
        while(1) {
            msleep(2000);
            char* selectedDriver = (char*) "";
            bool await = true;
            emit requestSelectedDriver(&selectedDriver, &await);
            while(await);
            asioRunning = true;
            setupASIO(selectedDriver);
            asioRunning = false;
        }
    }
signals:
    void requestSelectedDriver(char**, bool*);
};

#endif // ASIOTHREAD_H
