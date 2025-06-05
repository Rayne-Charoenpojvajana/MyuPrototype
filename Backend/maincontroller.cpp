#include "maincontroller.h"




MainController::MainController() {
    asioRunner.run();
}

MainController::~MainController() {

}

QStringList MainController::getDrivers() {
    return asioRunner.getDrivers();
}

void MainController::setSelectedDriver(QString driver) {
    configs.selectedDriver = driver;
}

QList<float> MainController::getMonitor() {
    QList<float> list;
    for(auto& input : liveData.inputs) {
        list.append(input.front());
    }
    return list;
}

QList<float> MainController::getOutput() {
    QList<float> list;
    for(auto& output : liveData.outputs) {
        list.append(output.front());
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
}

void MainController::addLayer(int channelNum, QString path) {
    asioRunner.halt();
    std::unique_ptr<Layer> layer;
    QString root = QCoreApplication::applicationDirPath();
    if (path.startsWith(root + "/Gains/")) {
        layer = std::make_unique<GainLayer>();
    } else if (path.startsWith(root + "/Clicks/")) {
        layer = std::make_unique<ClickLayer>();
    } else if (path.startsWith(root + "/VST3/")){
        layer = std::make_unique<VST3Layer>();
    }
    layer->setInfo(channelNum, path);
    layer->setupUI();
    configs.layers[channelNum].push_back(std::move(layer));
    preUpdateLayers(channelNum);
    asioRunner.run();
}

void MainController::close() {
    for(auto& layers : configs.layers) {
        for(auto& layer : layers) {
            layer->close();
        }
    }
}

void MainController::preUpdateLayers(int channelNum) {
    QVariantMap map;
    map["channel"] = channelNum;
    QList<QString> paths;
    QList<QVariant> isEnables;
    QList<QVariant> isProcesses;
    QList<QVariant> isOutputs;
    for (auto &layer : configs.layers[channelNum]) {
        paths.append(layer->getPath());
        isEnables.append(layer->getEnabled());
        isProcesses.append(layer->getProcess());
        isOutputs.append(layer->getOutput());
    }
    map["paths"] = paths;
    map["isEnables"] = isEnables;
    map["isProcesses"] = isProcesses;
    map["isOutputs"] = isOutputs;
    emit updateLayers(map);
}





QStringList MainController::getLayerPaths() {
    QStringList list;
    QStringList srcs = {"/Gains", "/Clicks", "/VST3"};
    QString root = QCoreApplication::applicationDirPath();
    for (QString str : srcs) {
        QString src = root + str;
        if (!QDir(src).exists()) {
            continue;
        }
        QDirIterator it(src, QDir::Files);
        while (it.hasNext()) {
            QString path = it.next();
            list.append(path);
        }
    }
    return list;
}

void MainController::swapLayers(int channelNum, int idx1, int idx2) {
    if (idx1 == idx2) {
        return;
    }
    std::vector<std::unique_ptr<Layer>> &vect = configs.layers[channelNum];
    if (idx1 >= vect.size() || idx2 >= vect.size()) {
        return;
    }
    if (idx1 < 0 || idx2 < 0) {
        return;
    }
    asioRunner.halt();
    std::swap(vect[idx1], vect[idx2]);
    preUpdateLayers(channelNum);
    asioRunner.run();
}

void MainController::removeLayer(int channelNum, int idx) {
    asioRunner.halt();
    std::vector<std::unique_ptr<Layer>> &vect = configs.layers[channelNum];
    vect.erase(configs.layers[channelNum].begin() + idx);
    preUpdateLayers(channelNum);
    asioRunner.run();
}

void MainController::toggleLayerUI(int channelNum, int idx) {
    asioRunner.halt();
    std::unique_ptr<Layer> &layer = configs.layers[channelNum][idx];
    layer->toggleUI();
    preUpdateLayers(channelNum);
    asioRunner.run();
}

void MainController::setLayerEnabled(int channelNum, int idx, bool val) {
    asioRunner.halt();
    std::unique_ptr<Layer> &layer = configs.layers[channelNum][idx];
    layer->setEnabled(val);
    preUpdateLayers(channelNum);
    asioRunner.run();
}

void MainController::setLayerOutput(int channelNum, int idx, bool val) {
    asioRunner.halt();
    for(int i = 0; i < configs.layers[channelNum].size(); i++) {
        std::unique_ptr<Layer> &layer = configs.layers[channelNum][i];
        if (i == idx) {
           layer->setOutput(val);
        } else if (val == true) {
            layer->setOutput(!val);
        } else {
            layer->setProcess(val);
        }
    }
    preUpdateLayers(channelNum);
    asioRunner.run();
}

void MainController::setLayerProcess(int channelNum, int idx, bool val) {
    asioRunner.halt();
    for(int i = 0; i < configs.layers[channelNum].size(); i++) {
        std::unique_ptr<Layer> &layer = configs.layers[channelNum][i];
        if (i == idx) {
            layer->setProcess(val);
        } else if (val == true){
            layer->setProcess(!val);
        } else {
            layer->setProcess(val);
        }
    }
    preUpdateLayers(channelNum);
    asioRunner.run();
}

void MainController::setInputRoute(int channelNum, int inputNum) {
    asioRunner.halt();
    configs.inputRoute[channelNum] = inputNum;
    asioRunner.run();
}

long MainController::getInputRoute(int channelNum) {
    return configs.inputRoute[channelNum];
}

void MainController::setOutputRoute(int channelNum, int outputNum) {
    asioRunner.halt();
    configs.outputRoute[channelNum] = outputNum;
    asioRunner.run();
}

long MainController::getSelectedBuffer() {
    return configs.selectedBufferSize;
}

long MainController::getSelectedSampleRate() {
    return configs.selectedSampleRate;
}

QString MainController::getSelectedDriver() {
    return configs.selectedDriver;
}




