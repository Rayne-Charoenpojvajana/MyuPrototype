#ifndef LAYER_H
#define LAYER_H
#include <QDebug>
#include <vector>
#include "../Audio/wavfile.h"

class Layer : public QObject
{
private:
    Q_OBJECT
public:
    int channelNum;
    QString path;
    Layer(int channelNum, QString path) {
        this->channelNum = channelNum;
        this->path = path;
    }
    virtual void transform(std::vector<float>& input, std::vector<float>& output) = 0;
    virtual void launchUI() = 0;
};

#endif // LAYER_H
