#ifndef CLICKLAYER_H
#define CLICKLAYER_H

#include "layer.h"
#include <QQuickView>
#include <QtQml/qqmlregistration.h>
#include "../Audio/wavfile.h"
class ClickLayer: public Layer
{
private:
    Q_OBJECT
    QML_ELEMENT
    std::unique_ptr<QQuickView> view;
public:
    void transform(std::vector<float>& input, std::vector<float>& output) override;
    void launchUI() override;
};

#endif // CLICKLAYER_H
