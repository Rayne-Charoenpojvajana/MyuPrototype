#ifndef ASIORUNNER_H
#define ASIORUNNER_H



#include "asiofunctions.h"


class ASIORunner
{
public:
    QStringList getDrivers();
    ASIORunner();
    bool run();
    bool halt();
private:
    bool running = false;
};

#endif // ASIORUNNER_H
