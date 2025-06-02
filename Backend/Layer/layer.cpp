#include "layer.h"

Layer::Layer() {

}

void Layer::setInfo(int channelNum, QString path) {
    this->channelNum = channelNum;
    this->path = path;
}
