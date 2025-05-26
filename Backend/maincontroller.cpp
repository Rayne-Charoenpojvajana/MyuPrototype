#include "maincontroller.h"



MainController::MainController() {
    connect(asioThread, &ASIOThread::requestSelectedDriver, this, &MainController::sendSelectedDriver);
    asioThread->start();
}


