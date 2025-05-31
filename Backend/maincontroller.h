#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "asiothread.h"
#include <QDebug>
#include <QObject>
#include <QtQml/qqmlregistration.h>
#include <QStringListModel>
#include <synchapi.h>
#include <QAudioFormat>
class MainController : public QObject
{
private:
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    ASIOThread* asioThread = new ASIOThread();
    QString selectedDriver = "";

public:
    MainController();
    Q_INVOKABLE QStringList getDriverList() {
        return asioThread->getDriverList();
    }
    Q_INVOKABLE void setSelectedDriver(QString driver) {
        this->selectedDriver = driver;
        if (asioThread->getStreaming()) {
            asioThread->setStreaming(false);
        }
    }
    Q_INVOKABLE QList<double> getMonitor() {
        if (!asioThread->getStreaming()) {
            return {0,0};
        }
        QList<double> list;
        list.append(inputs[0][0]);
        list.append(inputs[1][0]);
        return list;
    }
    Q_INVOKABLE QList<long> getBufferSizes() {
        QList<long> list;
        for(long i = softwareMinBuffer; i <= softwareMaxBuffer; i*=2) {
            list.append(i);
        }
        return list;
    }
    Q_INVOKABLE void setBufferSize(long size) {
        if (asioThread->getStreaming()) {
            asioThread->setStreaming(false);
        }
    }
    Q_INVOKABLE QList<long> getSampleRates() {
        QList<long> list;
        for (auto sr : softwareSampleRates) {
            list.append(sr);
        }
        return list;
    }
    Q_INVOKABLE void setSampleRate(long sampleRate) {
        selectedSampleRate = sampleRate;
        if (asioThread->getStreaming()) {
            asioThread->setStreaming(false);
        }
    }
    Q_INVOKABLE void setMetronome(bool state, double bpm) {
        clicks->cursor = 0;
        clicks->count = 0;
        clicks->interval = std::round((60/bpm) * clicks->sampleRate);
        clicks->on = state;
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
