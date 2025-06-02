#ifndef LAYER_H
#define LAYER_H
#include <vector>
#include <QObject>



class Layer : public QObject
{
private:
    Q_OBJECT
    int channelNum;
    QString path;
public:
    Layer();
    void setInfo(int channelNum, QString path);
    virtual void transform(std::vector<float>& input, std::vector<float>& output) = 0;
    virtual void launchUI() = 0;
};

#endif // LAYER_H
