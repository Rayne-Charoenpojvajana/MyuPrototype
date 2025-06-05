#ifndef GAINLAYER_H
#define GAINLAYER_H

#include "layer.h"
#include <QQuickView>
#include <QtQml/qqmlregistration.h>
class GainLayer : public Layer
{
private:
    Q_OBJECT
    QML_ELEMENT
    float gain;
public:
    void transform(std::vector<float>&) override;
    void setupUI() override;
    void toggleUI() override;
    Q_INVOKABLE void setGain(float);
};

#endif // GAINLAYER_H
