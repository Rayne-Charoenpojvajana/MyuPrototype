/****************************************************************************
** Meta object code from reading C++ file 'maincontroller.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Backend/maincontroller.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maincontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14MainControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto MainController::qt_create_metaobjectdata<qt_meta_tag_ZN14MainControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainController",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "addedLayer",
        "",
        "qmlInit",
        "sendSelectedDriver",
        "char**",
        "selectedDriver",
        "bool*",
        "await",
        "getDriverList",
        "setSelectedDriver",
        "driver",
        "getMonitor",
        "QList<double>",
        "getBufferSizes",
        "QList<long>",
        "setBufferSize",
        "size",
        "getSampleRates",
        "setSampleRate",
        "sampleRate",
        "addLayer",
        "channelNum",
        "path"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'addedLayer'
        QtMocHelpers::SignalData<void(int, QString)>(5, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::QString, 6 },
        }}),
        // Slot 'qmlInit'
        QtMocHelpers::SlotData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sendSelectedDriver'
        QtMocHelpers::SlotData<void(char * *, bool *)>(8, 6, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Method 'getDriverList'
        QtMocHelpers::MethodData<QStringList()>(13, 6, QMC::AccessPublic, QMetaType::QStringList),
        // Method 'setSelectedDriver'
        QtMocHelpers::MethodData<void(QString)>(14, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 15 },
        }}),
        // Method 'getMonitor'
        QtMocHelpers::MethodData<QList<double>()>(16, 6, QMC::AccessPublic, 0x80000000 | 17),
        // Method 'getBufferSizes'
        QtMocHelpers::MethodData<QList<long>()>(18, 6, QMC::AccessPublic, 0x80000000 | 19),
        // Method 'setBufferSize'
        QtMocHelpers::MethodData<void(long)>(20, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Long, 21 },
        }}),
        // Method 'getSampleRates'
        QtMocHelpers::MethodData<QList<long>()>(22, 6, QMC::AccessPublic, 0x80000000 | 19),
        // Method 'setSampleRate'
        QtMocHelpers::MethodData<void(long)>(23, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Long, 24 },
        }}),
        // Method 'addLayer'
        QtMocHelpers::MethodData<void(int, QString)>(25, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 26 }, { QMetaType::QString, 27 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<MainController, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject MainController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14MainControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14MainControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14MainControllerE_t>.metaTypes,
    nullptr
} };

void MainController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->addedLayer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->qmlInit(); break;
        case 2: _t->sendSelectedDriver((*reinterpret_cast< std::add_pointer_t<char**>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool*>>(_a[2]))); break;
        case 3: { QStringList _r = _t->getDriverList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setSelectedDriver((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: { QList<double> _r = _t->getMonitor();
            if (_a[0]) *reinterpret_cast< QList<double>*>(_a[0]) = std::move(_r); }  break;
        case 6: { QList<long> _r = _t->getBufferSizes();
            if (_a[0]) *reinterpret_cast< QList<long>*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setBufferSize((*reinterpret_cast< std::add_pointer_t<long>>(_a[1]))); break;
        case 8: { QList<long> _r = _t->getSampleRates();
            if (_a[0]) *reinterpret_cast< QList<long>*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setSampleRate((*reinterpret_cast< std::add_pointer_t<long>>(_a[1]))); break;
        case 10: _t->addLayer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainController::*)(int , QString )>(_a, &MainController::addedLayer, 0))
            return;
    }
}

const QMetaObject *MainController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14MainControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MainController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainController::addedLayer(int _t1, QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}
QT_WARNING_POP
