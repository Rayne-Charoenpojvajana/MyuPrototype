#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include <QDebug>
#include <QObject>
#include <QtQml/qqmlregistration.h>
#include <QStringListModel>
#include "asiofunctions.h"
class MainController : public QObject
{
private:
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON


public:
    MainController();

};

#endif // MAINCONTROLLER_H
