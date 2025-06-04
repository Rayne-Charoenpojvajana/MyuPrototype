#include "asiothread.h"


ASIOThread::ASIOThread(QObject *parent)
    : QThread(parent)
{
}

void ASIOThread::setSelectedDriver(QString selectedDriver) {
    this->selectedDriver = selectedDriver;
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
    std::vector<char*> drivers(numDev);
    for (int i = 0; i < numDev; i++) {
        drivers[i] = new char[configs.maxDriverLength];
    }
    helperDrivers.getDriverNames(drivers.data(), numDev);
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
        liveData.streaming = true;
        setupASIO(selectedDriver.toUtf8().data());
        liveData.streaming = false;
    }
}
