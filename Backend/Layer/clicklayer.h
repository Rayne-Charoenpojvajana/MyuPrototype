#ifndef CLICKLAYER_H
#define CLICKLAYER_H

#include "layer.h"
#include <QQuickView>
#include <QtQml/qqmlregistration.h>

class ClickLayer: public Layer
{
private:
    Q_OBJECT
    QML_ELEMENT
    std::unique_ptr<QQuickView> view;
    float bpm;
    int accent;
    float gain;
public:
    void transform(std::vector<float>&, std::vector<float>&) override;
    void setupUI() override;
    void toggleUI() override;
    Q_INVOKABLE void setBPM(float);
    Q_INVOKABLE void setAccent(int);
    Q_INVOKABLE void setGain(float);
};

#endif // CLICKLAYER_H
