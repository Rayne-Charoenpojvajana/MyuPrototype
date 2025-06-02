#include "clicklayer.h"


void ClickLayer::transform(std::vector<float> &input, std::vector<float> &output) {

}

void ClickLayer::launchUI()  {
    view = std::make_unique<QQuickView>();
    view->setInitialProperties({{"clickLayer", QVariant::fromValue(this)}});
    view->setSource(QUrl("MyuPrototype/Frontend/Windows/ClickWindow.qml"));
    view->show();
}
