#include "asiorunner.h"


ASIORunner::ASIORunner() {}


QStringList ASIORunner::getDrivers() {
    QStringList list;
    long numDev = helperDrivers.asioGetNumDev();
    std::vector<char*> drivers(numDev);
    for (int i = 0; i < numDev; i++) {
        drivers[i] = new char[configs.maxDriverLength];
    }
    helperDrivers.getDriverNames(drivers.data(), numDev);
    for (int i = 0; i < numDev; i++) {
        list.append(drivers[i]);
        delete drivers[i];
    }
    return list;
}

bool ASIORunner::run() {
    if (!setupASIO(configs.selectedDriver.toUtf8().data())) {
        running = false;
        return false;
    }
    running = true;
    return true;
}


bool ASIORunner::halt() {
    if (running) {
        endASIO();
    }
    return true;
}

