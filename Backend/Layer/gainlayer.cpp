#include "gainlayer.h"

void GainLayer::transform(std::vector<float> &input, std::vector<float> &output) {

}

void GainLayer::setupUI()  {
    view = std::make_unique<QQuickView>();
    view->setInitialProperties({{"gainLayer", QVariant::fromValue(this)}});
    view->setSource(QUrl("MyuPrototype/Frontend/Windows/GainWindow.qml"));
}

void GainLayer::setGain(float gain) {
    this->gain = gain;
}


void GainLayer::toggleUI() {
    uiVisible = !uiVisible;;
    view->setProperty("visible", uiVisible);;
}
