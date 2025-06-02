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
    ASIOThread asioThread;
    QString selectedDriver = "";

public:
    MainController();
    ~MainController() {
        asioThread.closeThread();
        asioThread.setStreaming(false);
        asioThread.quit();
        QThread::msleep(1000);
    }
    Q_INVOKABLE QStringList getDriverList() {
        return asioThread.getDriverList();
    }
    Q_INVOKABLE void setSelectedDriver(QString driver) {
        this->selectedDriver = driver;
        if (asioThread.getStreaming()) {
            asioThread.setStreaming(false);
        }
    }
    Q_INVOKABLE QList<double> getMonitor() {
        QList<double> list;
        for(auto input : inputs) {
            if (!asioThread.getStreaming() || input.empty()) {
                list.append(0);
                continue;
            }
            list.append(input[0]);
        }
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
        selectedBufferSize = size;
        if (asioThread.getStreaming()) {
            asioThread.setStreaming(false);
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
        if (asioThread.getStreaming()) {
            asioThread.setStreaming(false);
        }
    }
    Q_INVOKABLE void addLayer(int channelNum, QString path) {
        layers[channelNum].push_back(std::make_unique<ClickLayer>(channelNum, path));
        layers[channelNum].back()->launchUI();
    }
    Q_INVOKABLE void test() {
        qDebug() << "yo";
    }
signals:
    void addedLayer(int, QString);
public slots:
    void qmlInit() {
        addLayer(0, ":/Clicks/click_1.wav");
        connect(&asioThread, &ASIOThread::requestSelectedDriver, this, &MainController::sendSelectedDriver);
        asioThread.start();
    }
    void sendSelectedDriver(char** selectedDriver, bool* await) {
        *selectedDriver = this->selectedDriver.toUtf8().data();
        *await = false;
    }
};

#endif // MAINCONTROLLER_H
