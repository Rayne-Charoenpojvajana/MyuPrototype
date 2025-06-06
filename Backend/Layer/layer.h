#ifndef LAYER_H
#define LAYER_H
#include <qqmlapplicationengine.h>
#include <vector>
#include <QObject>
#include <QMutex>
#include <QQuickView>

class NewQuickView: public QQuickView {
public:
    using QQuickView::QQuickView;
    bool readyToClose = false;
protected:
    bool event(QEvent *event) override
    {
        if (event->type() == QEvent::Close && !readyToClose) {
            setVisible(false);
            return false;
        }
        return QQuickView::event(event);
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
    void close();
    void setInfo(int channelNum, QString path);
    virtual void transform(std::vector<float>&) = 0;
    virtual bool setupUI() = 0;
    void toggleUI();
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
