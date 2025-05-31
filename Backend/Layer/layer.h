#ifndef LAYER_H
#define LAYER_H

class Layer
{
public:
    Layer();
    virtual void transform(float*,float*,long) = 0;

};

#endif // LAYER_H
