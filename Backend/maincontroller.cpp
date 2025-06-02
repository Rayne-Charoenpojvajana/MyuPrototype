#include "maincontroller.h"




MainController::MainController() {

}

MainController::~MainController() {
    asioThread.closeThread();
    asioThread.setStreaming(false);
    asioThread.quit();
    QThread::msleep(1000);
}

QStringList MainController::getDriverList() {
    return asioThread.getDriverList();
}

void MainController::setSelectedDriver(QString driver) {
    this->selectedDriver = driver;
    if (asioThread.getStreaming()) {
        asioThread.setStreaming(false);
    }
}

QList<double> MainController::getMonitor() {
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

QList<long> MainController::getBufferSizes() {
    QList<long> list;
    for(long i = configs.softwareMinBuffer; i <= configs.softwareMaxBuffer; i*=2) {
        list.append(i);
    }
    return list;
}

void MainController::setBufferSize(long size) {
    configs.selectedBufferSize = size;
    if (asioThread.getStreaming()) {
        asioThread.setStreaming(false);
    }
}

QList<long> MainController::getSampleRates() {
    QList<long> list;
    for (auto sr : configs.softwareSampleRates) {
        list.append(sr);
    }
    return list;
}

void MainController::setSampleRate(long sampleRate) {
    configs.selectedSampleRate = sampleRate;
    if (asioThread.getStreaming()) {
        asioThread.setStreaming(false);
    }
}

void MainController::addLayer(int channelNum, QString path) {
    layers[channelNum].push_back(std::make_unique<ClickLayer>());
    layers[channelNum].back()->setInfo(channelNum, path);
    layers[channelNum].back()->launchUI();
}

void MainController::qmlInit() {
    addLayer(0, ":/Clicks/click_1.wav");
    connect(&asioThread, &ASIOThread::requestSelectedDriver, this, &MainController::sendSelectedDriver);
    asioThread.start();
}

void MainController::sendSelectedDriver(char **selectedDriver, bool *await) {
    *selectedDriver = this->selectedDriver.toUtf8().data();
    *await = false;
}


