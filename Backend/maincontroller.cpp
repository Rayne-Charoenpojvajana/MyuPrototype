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
    // this->selectedDriver = driver;
    asioThread.setSelectedDriver(driver);
    if (asioThread.getStreaming()) {
        asioThread.setStreaming(false);
    }
}

QList<float> MainController::getMonitor() {
    QList<float> list;
    for(auto& input : liveData.inputs) {
        if (!asioThread.getStreaming() || input.empty()) {
            list.append(0);
            continue;
        }
        list.append(input[0]);
    }
    return list;
}

QList<float> MainController::getOutput() {
    QList<float> list;
    for(auto& output : liveData.outputs) {
        if (!asioThread.getStreaming() || output.empty()) {
            list.append(0);
            continue;
        }
        list.append(output[0]);
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
    } else {
        layer = std::make_unique<VST3Layer>();
        layer->setEnabled(true);
        layer->setOutput(true);
    }
    layer->setInfo(channelNum, path);
    layer->setupUI();
    configs.layers[channelNum].push_back(std::move(layer));
}

void MainController::qmlInit() {
    addLayer(1, "C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/VST3/Archetype Plini X.vst3");
    asioThread.start();
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
    std::vector<std::unique_ptr<Layer>> &vect = configs.layers[channelNum];
    std::swap(vect[idx1], vect[idx2]);
}

void MainController::removeLayer(int channelNum, int idx) {
    std::vector<std::unique_ptr<Layer>> &vect = configs.layers[channelNum];
    vect.erase(configs.layers[channelNum].begin() + idx);
}

void MainController::toggleLayerUI(int channelNum, int idx) {
    std::unique_ptr<Layer> &layer = configs.layers[channelNum][idx];
    layer->toggleUI();
}

void MainController::setLayerEnabled(int channelNum, int idx, bool val) {
    std::unique_ptr<Layer> &layer = configs.layers[channelNum][idx];
    layer->setEnabled(val);
}

void MainController::setLayerOutput(int channelNum, int idx, bool val) {
    for(int i = 0; i < configs.layers[channelNum].size(); i++) {
        std::unique_ptr<Layer> &layer = configs.layers[channelNum][i];
        if (i == idx) {
           layer->setOutput(val);
        } else {
            layer->setOutput(!val);
        }
    }
}

void MainController::setLayerProcess(int channelNum, int idx, bool val) {
    for(int i = 0; i < configs.layers[channelNum].size(); i++) {
        std::unique_ptr<Layer> &layer = configs.layers[channelNum][i];
        if (i == idx) {
            layer->setProcess(val);
        } else {
            layer->setProcess(!val);
        }
    }
}

void MainController::setInputRoute(int channelNum, int inputNum) {
    configs.inputRoute[channelNum] = inputNum;
}

void MainController::setOutputRoute(int channelNum, int outputNum) {
    configs.outputRoute[channelNum] = outputNum;
}



