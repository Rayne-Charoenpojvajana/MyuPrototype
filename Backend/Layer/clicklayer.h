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
    float bpm;
    int accent;
    float gain;
    std::unique_ptr<WAVFile> wavFile;
public:
    void transform(std::vector<float>&) override;
    void setupUI() override;
    void toggleUI() override;
    Q_INVOKABLE void setBPM(float);
    Q_INVOKABLE void setAccent(int);
    Q_INVOKABLE void setGain(float);
    int count = 0;
    int interval = 2 << 10;
    int cursor = 0;
};

#endif // CLICKLAYER_H
