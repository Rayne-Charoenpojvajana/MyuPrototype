#ifndef CLICKLAYER_H
#define CLICKLAYER_H

#include "layer.h"
#include <QDebug>
class ClickLayer: public Layer
{
public:
    ClickLayer();
    void transform(float* input, float* output, long buffSize) override {

    }
};

#endif // CLICKLAYER_H
