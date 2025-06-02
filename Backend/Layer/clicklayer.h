#ifndef CLICKLAYER_H
#define CLICKLAYER_H

#include "layer.h"
#include <QDebug>
#include <QQuickView>

class ClickLayer: public Layer
{
private:
    Q_OBJECT
public:
    std::unique_ptr<WAVFile> clickFile;
    std::unique_ptr<QQuickView> view;
    bool loop = false;
    uint32_t interval = 2 << 5;
    uint32_t count = 0;
    uint32_t cursor = 0;

    ClickLayer(int channelNum, QString path): Layer(channelNum, path) {
        clickFile = std::make_unique<WAVFile>(path);
        view = std::make_unique<QQuickView>();
    }
    bool atEnd() {
        return cursor == clickFile->data.size();
    }
    void transform(std::vector<float>& input, std::vector<float>& output) override {
        int buffSize = input.size();
        for(int j = 0; j < buffSize; j++) {
            float clickData = 0;
            if (atEnd()) {
                clickData = clickFile->data[cursor];
                cursor++;
            }
            output[j] = input[j] + clickData;
            count++;
            if (count == interval) {
                count = 0;
                if (loop) {
                    cursor = 0;
                }
            }
        }
    }
    void launchUI() override  {
        // view->setInitialProperties({{"layer", QVariant::fromValue(this)}});
        view->setSource(QUrl("MyuPrototype/Frontend/Windows/ClickWindow.qml"));
        view->show();
    }
};

#endif // CLICKLAYER_H
