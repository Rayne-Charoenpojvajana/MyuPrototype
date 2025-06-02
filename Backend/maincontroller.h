#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include "asiothread.h"
#include <QDebug>
#include <QObject>
#include <QtQml/qqmlregistration.h>
#include <QStringListModel>

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
    Q_INVOKABLE void setSelectedDriver(QString driver);
    Q_INVOKABLE QList<double> getMonitor();
    Q_INVOKABLE QList<long> getBufferSizes();
    Q_INVOKABLE void setBufferSize(long size);
    Q_INVOKABLE QList<long> getSampleRates();
    Q_INVOKABLE void setSampleRate(long sampleRate);
    Q_INVOKABLE void addLayer(int channelNum, QString path);
signals:
    void addedLayer(int, QString);
public slots:
    void qmlInit();
    void sendSelectedDriver(char** selectedDriver, bool* await);
};

#endif // MAINCONTROLLER_H
