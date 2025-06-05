#include "layer.h"

bool Layer::getProcess()
{
    return process;
}

void Layer::setProcess(bool newProcess)
{
    process = newProcess;
}

bool Layer::getOutput()
{
    return output;
}

void Layer::setOutput(bool newOutput)
{
    output = newOutput;
}

bool Layer::getEnabled()
{
    return enabled;
}

void Layer::setEnabled(bool newEnabled)
{
    enabled = newEnabled;
}

void Layer::close() {
    view->readyToClose = true;
    view->close();
}

Layer::Layer() {

}

void Layer::setInfo(int channelNum, QString path) {
    this->channelNum = channelNum;
    this->path = path;
}

QString Layer::getPath() {
    return path;
}

int Layer::getChannelNum() {
    return channelNum;
}
