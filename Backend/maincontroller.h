#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "asiorunner.h"
#include <QDebug>
#include <QObject>
#include <QtQml/qqmlregistration.h>
#include <QStringListModel>
#include <QDirIterator>
#include "Backend/Layer/vst3layer.h";
class MainController : public QObject
{
private:
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    ASIORunner asioRunner;
    QString selectedDriver = "";

public:
    MainController();
    ~MainController();
    Q_INVOKABLE QStringList getDrivers();
    Q_INVOKABLE void setSelectedDriver(QString);
    Q_INVOKABLE QList<float> getMonitor();
    Q_INVOKABLE QList<float> getOutput();
    Q_INVOKABLE QList<long> getBufferSizes();
    Q_INVOKABLE void setBufferSize(long);
    Q_INVOKABLE QList<long> getSampleRates();
    Q_INVOKABLE void setSampleRate(long);
    Q_INVOKABLE void addLayer(int, QString);
    Q_INVOKABLE QStringList getLayerPaths();
    Q_INVOKABLE void swapLayers(int, int, int);
    Q_INVOKABLE void removeLayer(int, int);
    Q_INVOKABLE void toggleLayerUI(int, int);
    Q_INVOKABLE void setLayerEnabled(int, int, bool);
    Q_INVOKABLE void setLayerProcess(int, int, bool);
    Q_INVOKABLE void setLayerOutput(int, int, bool);
    Q_INVOKABLE void setInputRoute(int, int);
    Q_INVOKABLE void setOutputRoute(int, int);
    Q_INVOKABLE long getSelectedBuffer();
    Q_INVOKABLE long getSelectedSampleRate();
    Q_INVOKABLE QString getSelectedDriver();
    Q_INVOKABLE long getInputRoute(int);
    Q_INVOKABLE long getOutputRoute(int);
    Q_INVOKABLE void close();
    void preUpdateLayers(int);
signals:
    void updateLayers(QVariantMap map);
};

#endif // MAINCONTROLLER_H
