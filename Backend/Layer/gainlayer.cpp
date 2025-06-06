#include "gainlayer.h"

void GainLayer::transform(std::vector<float> &input) {
    for(int j = 0; j < input.size(); j++) {
        input[j] *= gain;
    }
}

bool GainLayer::setupUI() {
    view = std::make_unique<NewQuickView>();
    view->setTitle(getPath());
    view->setInitialProperties({{"gainLayer", QVariant::fromValue(this)}});
    view->setSource(QUrl("MyuPrototype/Frontend/Windows/GainWindow.qml"));
    return true;
}

inline float dBToAmplitude(float db) {
    return pow(10.0f, db/20.0f);
}

void GainLayer::setGain(float gain) {
    this->gain = dBToAmplitude(gain);
}

