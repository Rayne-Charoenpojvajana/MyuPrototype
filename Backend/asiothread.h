#ifndef ASIOTHREAD_H
#define ASIOTHREAD_H

#include <QThread>
#include <QDebug>
#include "asiofunctions.h"

class ASIOThread : public QThread
{
public:
    explicit ASIOThread(QObject *parent = nullptr)
        : QThread(parent)
    {
    }

private:
    Q_OBJECT
    void run() override {
        test();
    }

signals:
    void signalConnectDriver();
};

#endif // ASIOTHREAD_H
