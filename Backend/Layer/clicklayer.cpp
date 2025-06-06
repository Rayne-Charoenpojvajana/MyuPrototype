#include "clicklayer.h"


void ClickLayer::transform(std::vector<float> &input) {

}

bool ClickLayer::setupUI()  {
    view = std::make_unique<NewQuickView>();
    view->setTitle(getPath());
    view->setInitialProperties({{"clickLayer", QVariant::fromValue(this)}});
    view->setSource(QUrl("MyuPrototype/Frontend/Windows/ClickWindow.qml"));
    return true;
}

void ClickLayer::setBPM(float bpm) {
    this->bpm = bpm;
    interval = (60 / bpm) * wavFile->format.sampleRate();
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
