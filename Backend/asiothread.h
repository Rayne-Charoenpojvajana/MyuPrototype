#ifndef ASIOTHREAD_H
#define ASIOTHREAD_H

#include <QThread>
#include <QDebug>
#include "asiofunctions.h"


class ASIOThread : public QThread
{
public:
    explicit ASIOThread(QObject *parent = nullptr);
    bool getStreaming();
    void setStreaming(bool stream);
    QStringList getDriverList();
    void closeThread();
private:
    Q_OBJECT
    bool close = false;
    void run() override;
signals:
    void requestSelectedDriver(char**, bool*);
};

#endif // ASIOTHREAD_H
