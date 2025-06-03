#include "clicklayer.h"


void ClickLayer::transform(std::vector<float> &input, std::vector<float> &output) {

}

void ClickLayer::setupUI()  {
    view = std::make_unique<QQuickView>();
    view->setInitialProperties({{"clickLayer", QVariant::fromValue(this)}});
    view->setSource(QUrl("MyuPrototype/Frontend/Windows/ClickWindow.qml"));
}

void ClickLayer::setBPM(float bpm) {
    this->bpm = bpm;
}

void ClickLayer::setAccent(int accent) {
    this->accent = accent;
}

void ClickLayer::setGain(float gain) {
    this->gain = gain;
}

void ClickLayer::toggleUI() {
    uiVisible = !uiVisible;;
    view->setProperty("visible", uiVisible);;
}
