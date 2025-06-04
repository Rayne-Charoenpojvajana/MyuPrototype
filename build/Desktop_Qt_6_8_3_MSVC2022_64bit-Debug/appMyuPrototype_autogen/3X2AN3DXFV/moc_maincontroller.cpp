/****************************************************************************
** Meta object code from reading C++ file 'maincontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
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
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
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


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN14MainControllerE = QtMocHelpers::stringData(
    "MainController",
    "QML.Element",
    "auto",
    "QML.Singleton",
    "true",
    "qmlInit",
    "",
    "getDriverList",
    "setSelectedDriver",
    "getMonitor",
    "QList<float>",
    "getOutput",
    "getBufferSizes",
    "QList<long>",
    "setBufferSize",
    "getSampleRates",
    "setSampleRate",
    "addLayer",
    "getLayerPaths",
    "swapLayers",
    "removeLayer",
    "toggleLayerUI",
    "setLayerEnabled",
    "setLayerProcess",
    "setLayerOutput",
    "setInputRoute",
    "setOutputRoute"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN14MainControllerE[] = {

 // content:
      12,       // revision
       0,       // classname
       2,   14, // classinfo
      19,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,  132,    6, 0x0a,    1 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,  133,    6, 0x02,    2 /* Public */,
       8,    1,  134,    6, 0x02,    3 /* Public */,
       9,    0,  137,    6, 0x02,    5 /* Public */,
      11,    0,  138,    6, 0x02,    6 /* Public */,
      12,    0,  139,    6, 0x02,    7 /* Public */,
      14,    1,  140,    6, 0x02,    8 /* Public */,
      15,    0,  143,    6, 0x02,   10 /* Public */,
      16,    1,  144,    6, 0x02,   11 /* Public */,
      17,    2,  147,    6, 0x02,   13 /* Public */,
      18,    1,  152,    6, 0x02,   16 /* Public */,
      19,    3,  155,    6, 0x02,   18 /* Public */,
      20,    2,  162,    6, 0x02,   22 /* Public */,
      21,    2,  167,    6, 0x02,   25 /* Public */,
      22,    3,  172,    6, 0x02,   28 /* Public */,
      23,    3,  179,    6, 0x02,   32 /* Public */,
      24,    3,  186,    6, 0x02,   36 /* Public */,
      25,    2,  193,    6, 0x02,   40 /* Public */,
      26,    2,  198,    6, 0x02,   43 /* Public */,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QString,    6,
    0x80000000 | 10,
    0x80000000 | 10,
    0x80000000 | 13,
    QMetaType::Void, QMetaType::Long,    6,
    0x80000000 | 13,
    QMetaType::Void, QMetaType::Long,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    6,
    QMetaType::QStringList, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    6,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    6,    6,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    6,    6,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    6,    6,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN14MainControllerE.offsetsAndSizes,
    qt_meta_data_ZN14MainControllerE,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // Q_OBJECT / Q_GADGET
        MainController,
        // method 'qmlInit'
        void,
        // method 'getDriverList'
        QStringList,
        // method 'setSelectedDriver'
        void,
        QString,
        // method 'getMonitor'
        QList<float>,
        // method 'getOutput'
        QList<float>,
        // method 'getBufferSizes'
        QList<long>,
        // method 'setBufferSize'
        void,
        long,
        // method 'getSampleRates'
        QList<long>,
        // method 'setSampleRate'
        void,
        long,
        // method 'addLayer'
        void,
        int,
        QString,
        // method 'getLayerPaths'
        QStringList,
        QString,
        // method 'swapLayers'
        void,
        int,
        int,
        int,
        // method 'removeLayer'
        void,
        int,
        int,
        // method 'toggleLayerUI'
        void,
        int,
        int,
        // method 'setLayerEnabled'
        void,
        int,
        int,
        bool,
        // method 'setLayerProcess'
        void,
        int,
        int,
        bool,
        // method 'setLayerOutput'
        void,
        int,
        int,
        bool,
        // method 'setInputRoute'
        void,
        int,
        int,
        // method 'setOutputRoute'
        void,
        int,
        int
    >,
    nullptr
} };

void MainController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->qmlInit(); break;
        case 1: { QStringList _r = _t->getDriverList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setSelectedDriver((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { QList<float> _r = _t->getMonitor();
            if (_a[0]) *reinterpret_cast< QList<float>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QList<float> _r = _t->getOutput();
            if (_a[0]) *reinterpret_cast< QList<float>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QList<long> _r = _t->getBufferSizes();
            if (_a[0]) *reinterpret_cast< QList<long>*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setBufferSize((*reinterpret_cast< std::add_pointer_t<long>>(_a[1]))); break;
        case 7: { QList<long> _r = _t->getSampleRates();
            if (_a[0]) *reinterpret_cast< QList<long>*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setSampleRate((*reinterpret_cast< std::add_pointer_t<long>>(_a[1]))); break;
        case 9: _t->addLayer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 10: { QStringList _r = _t->getLayerPaths((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->swapLayers((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 12: _t->removeLayer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 13: _t->toggleLayerUI((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 14: _t->setLayerEnabled((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 15: _t->setLayerProcess((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 16: _t->setLayerOutput((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 17: _t->setInputRoute((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 18: _t->setOutputRoute((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN14MainControllerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MainController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
