#ifndef LAYER_H
#define LAYER_H
#include <qqmlapplicationengine.h>
#include <vector>
#include <QObject>
#include <QMutex>


class Layer : public QObject
{
private:
    Q_OBJECT
    int channelNum;
    QString path;
    bool process = false;
    bool output = false;
    bool enabled = false;
    int inputSel;
    QMutex mutex;
protected:
    bool uiVisible = false;
public:
    Layer();
    void setInfo(int channelNum, QString path);
    virtual void transform(std::vector<float>&) = 0;
    virtual void setupUI() = 0;
    virtual void toggleUI() = 0;
    QString getPath();
    int getChannelNum();
    bool getProcess();
    void setProcess(bool);
    bool getOutput();
    void setOutput(bool);
    bool getEnabled();
    void setEnabled(bool);
    bool getUiVisible() const;
    void setUiVisible(bool newUiVisible);
    QMutex& getMutex();
};

#endif // LAYER_H
