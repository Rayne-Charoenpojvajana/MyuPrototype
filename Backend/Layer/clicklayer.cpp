#include "clicklayer.h"


void ClickLayer::transform(std::vector<float> &input) {
    for(int j = 0; j < input.size(); j++) {
        if (cursor < wavFile->data.size()) {
            input[j] += wavFile->data[cursor];
            cursor++;
        }
        count++;
        if (count >= interval) {
            count = 0;
            cursor = 0;
        }
    }
}

void ClickLayer::setupUI()  {
    view = std::make_unique<QQuickView>();
    QString src = QCoreApplication::applicationDirPath() + "/" + getPath();
    QFile file(src);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!file.atEnd()) {
        QString line = file.readLine();
        wavFile = std::make_unique<WAVFile>(line);
    }
    file.close();
    view->setTitle(getPath());
    view->setInitialProperties({{"clickLayer", QVariant::fromValue(this)}});
    view->setSource(QUrl("MyuPrototype/Frontend/Windows/ClickWindow.qml"));
}

void ClickLayer::setBPM(float bpm) {
    this->bpm = bpm;
    interval = (60 / this->bpm) * wavFile->format.sampleRate();
    qDebug() << interval;
}

void ClickLayer::setAccent(int accent) {
    this->accent = accent;
}

inline float dBToAmplitude(float db) {
    return pow(10.0f, db/20.0f);
}

void ClickLayer::setGain(float gain) {
    this->gain = dBToAmplitude(gain);
}

void ClickLayer::toggleUI() {
    uiVisible = !uiVisible;;
    view->setProperty("visible", uiVisible);;
}
