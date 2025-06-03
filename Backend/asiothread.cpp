#include "asiothread.h"


ASIOThread::ASIOThread(QObject *parent)
    : QThread(parent)
{
}

bool ASIOThread::getStreaming() {
    return liveData.streaming;
}

void ASIOThread::setStreaming(bool stream) {
    liveData.streaming = stream;
}

QStringList ASIOThread::getDriverList() {
    QStringList list;
    if (getStreaming()) {
        return list;
    }
    long numDev = helperDrivers.asioGetNumDev();
    char* drivers[numDev];
    for (int i = 0; i < numDev; i++) {
        drivers[i] = new char[configs.maxDriverLength];
    }
    helperDrivers.getDriverNames(drivers, numDev);
    for (int i = 0; i < numDev; i++) {
        list.append(drivers[i]);
        delete drivers[i];
    }
    return list;
}

void ASIOThread::closeThread() {
    closed = true;
}

void ASIOThread::run() {
    while(!closed) {
        msleep(500);
        char* selectedDriver = (char*) "";
        bool await = true;
        emit requestSelectedDriver(&selectedDriver, &await);
        while(await && !closed);
        liveData.streaming = true;
        setupASIO(selectedDriver);
        liveData.streaming = false;
    }
}
