#ifndef PROCESSERTHREAD_H
#define PROCESSERTHREAD_H

#include <QThread>

class ProcesserThread : public QThread
{
public:
    explicit ProcesserThread(QObject *parent = nullptr);
};

#endif // PROCESSERTHREAD_H
