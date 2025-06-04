#ifndef ASIOTHREAD_H
#define ASIOTHREAD_H



#include "asiofunctions.h"


class ASIOThread : public QThread
{
public:
    bool getStreaming();
    void setStreaming(bool);
    QStringList getDriverList();
    void closeThread();
    explicit ASIOThread(QObject* = nullptr);
    void setSelectedDriver(QString);
private:
    Q_OBJECT
    QString selectedDriver;
    bool closed = false;
    void run() override;
};

#endif // ASIOTHREAD_H
