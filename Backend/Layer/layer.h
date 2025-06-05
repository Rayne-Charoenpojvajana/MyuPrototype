#ifndef LAYER_H
#define LAYER_H
#include <qqmlapplicationengine.h>
#include <vector>
#include <QObject>
#include <QMutex>
#include <QQuickView>

class NewQuickView: public QQuickView {
protected:
    bool event(QEvent *event) override
    {
        if (event->type() == QEvent::Close) {
            setVisible(false);
        }
        return false;
    }
};

class Layer : public QObject
{
private:
    Q_OBJECT
    int channelNum;
    QString path;
    bool process = false;
    bool output = false;
    bool enabled = false;
protected:
    bool uiVisible = false;
    std::unique_ptr<NewQuickView> view;
public:
    QMutex mutex;
    Layer();
    ~Layer();
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
};

#endif // LAYER_H
