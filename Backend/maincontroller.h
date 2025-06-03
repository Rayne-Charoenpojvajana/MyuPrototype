#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "asiothread.h"
#include <QDebug>
#include <QObject>
#include <QtQml/qqmlregistration.h>
#include <QStringListModel>
#include <QDirIterator>
class MainController : public QObject
{
private:
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    ASIOThread asioThread;
    QString selectedDriver = "";

public:
    MainController();
    ~MainController();
    Q_INVOKABLE QStringList getDriverList();
    Q_INVOKABLE void setSelectedDriver(QString);
    Q_INVOKABLE QList<double> getMonitor();
    Q_INVOKABLE QList<long> getBufferSizes();
    Q_INVOKABLE void setBufferSize(long);
    Q_INVOKABLE QList<long> getSampleRates();
    Q_INVOKABLE void setSampleRate(long);
    Q_INVOKABLE void addLayer(int, QString);
    Q_INVOKABLE QStringList getLayerPaths(QString);
    Q_INVOKABLE void swapLayers(int, int, int);
    Q_INVOKABLE void removeLayer(int, int);
    Q_INVOKABLE void toggleLayerUI(int, int);
    Q_INVOKABLE void setLayerEnabled(int, int, bool);
    Q_INVOKABLE void setLayerProcess(int, int, bool);
    Q_INVOKABLE void setLayerOutput(int, int, bool);
    Q_INVOKABLE void setInputRoute(int, int);
    Q_INVOKABLE void setOutputRoute(int, int);
public slots:
    void qmlInit();
    void sendSelectedDriver(char**, bool*);

};

#endif // MAINCONTROLLER_H
