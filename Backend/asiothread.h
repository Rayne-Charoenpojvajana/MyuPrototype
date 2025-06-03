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

private:
    Q_OBJECT

    bool closed = false;
    void run() override;
signals:
    void requestSelectedDriver(char**, bool*);
};

#endif // ASIOTHREAD_H
