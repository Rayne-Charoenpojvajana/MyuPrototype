#include "asiothread.h"


ASIOThread::ASIOThread(QObject *parent)
    : QThread(parent)
{
}

bool ASIOThread::getStreaming() {
    return streaming;
}

void ASIOThread::setStreaming(bool stream) {
    streaming = stream;
}

QStringList ASIOThread::getDriverList() {
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

void ASIOThread::closeThread() {
    close = true;
}

void ASIOThread::run() {
    while(!close) {
        msleep(500);
        char* selectedDriver = (char*) "";
        bool await = true;
        emit requestSelectedDriver(&selectedDriver, &await);
        while(await && !close);
        streaming = true;
        setupASIO(selectedDriver);
        streaming = false;
    }
}
