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
    for(auto input : liveData.inputs) {
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
    std::unique_ptr<Layer> layer;
    if (path.startsWith("Gains/")) {
        layer = std::make_unique<GainLayer>();
    } else if (path.startsWith("Clicks/")) {
        layer = std::make_unique<ClickLayer>();
    }
    layer->setInfo(channelNum, path);
    layer->setupUI();
    liveData.layers[channelNum].push_back(std::move(layer));
}

void MainController::qmlInit() {
    connect(&asioThread, &ASIOThread::requestSelectedDriver, this, &MainController::sendSelectedDriver);
    asioThread.start();
}

void MainController::sendSelectedDriver(char **selectedDriver, bool *await) {
    *selectedDriver = this->selectedDriver.toUtf8().data();
    *await = false;
}

QStringList MainController::getLayerPaths(QString src) {
    if (!QDir(src).exists()) {
        QDir().mkdir(src);
    }
    QStringList list;
    QDirIterator it(QCoreApplication::applicationDirPath() + "/" + src, QDir::Files, QDirIterator::Subdirectories);
    QDir root(QCoreApplication::applicationDirPath());
    while (it.hasNext()) {
        list.append(root.relativeFilePath(it.next()));
    }
    return list;
}

void MainController::swapLayers(int channelNum, int idx1, int idx2) {
    std::vector<std::unique_ptr<Layer>> &vect = liveData.layers[channelNum];
    std::swap(vect[idx1], vect[idx2]);
}

void MainController::removeLayer(int channelNum, int idx) {
    std::vector<std::unique_ptr<Layer>> &vect = liveData.layers[channelNum];
    vect.erase(liveData.layers[channelNum].begin() + idx);
}

void MainController::toggleLayerUI(int channelNum, int idx) {
    std::unique_ptr<Layer> &layer = liveData.layers[channelNum][idx];
    layer->toggleUI();
}

void MainController::setLayerEnabled(int channelNum, int idx, bool val) {
    std::unique_ptr<Layer> &layer = liveData.layers[channelNum][idx];
    layer->setEnabled(val);
}

void MainController::setLayerOutput(int channelNum, int idx, bool val) {
    std::unique_ptr<Layer> &layer = liveData.layers[channelNum][idx];
    layer->setOutput(val);
}

void MainController::setLayerProcess(int channelNum, int idx, bool val) {
    std::unique_ptr<Layer> &layer = liveData.layers[channelNum][idx];
    layer->setProcess(val);
}

void MainController::setInputRoute(int channelNum, int layerNum) {
    liveData.inputRoute[channelNum] = layerNum;
}

void MainController::setOutputRoute(int channelNum, int layerNum) {
    liveData.outputRoute[channelNum] = layerNum;
}

