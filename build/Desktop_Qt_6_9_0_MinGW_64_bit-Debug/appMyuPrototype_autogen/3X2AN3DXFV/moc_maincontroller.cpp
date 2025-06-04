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
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'qmlInit'
        QtMocHelpers::SlotData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'getDriverList'
        QtMocHelpers::MethodData<QStringList()>(7, 6, QMC::AccessPublic, QMetaType::QStringList),
        // Method 'setSelectedDriver'
        QtMocHelpers::MethodData<void(QString)>(8, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Method 'getMonitor'
        QtMocHelpers::MethodData<QList<float>()>(9, 6, QMC::AccessPublic, 0x80000000 | 10),
        // Method 'getOutput'
        QtMocHelpers::MethodData<QList<float>()>(11, 6, QMC::AccessPublic, 0x80000000 | 10),
        // Method 'getBufferSizes'
        QtMocHelpers::MethodData<QList<long>()>(12, 6, QMC::AccessPublic, 0x80000000 | 13),
        // Method 'setBufferSize'
        QtMocHelpers::MethodData<void(long)>(14, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Long, 6 },
        }}),
        // Method 'getSampleRates'
        QtMocHelpers::MethodData<QList<long>()>(15, 6, QMC::AccessPublic, 0x80000000 | 13),
        // Method 'setSampleRate'
        QtMocHelpers::MethodData<void(long)>(16, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Long, 6 },
        }}),
        // Method 'addLayer'
        QtMocHelpers::MethodData<void(int, QString)>(17, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::QString, 6 },
        }}),
        // Method 'getLayerPaths'
        QtMocHelpers::MethodData<QStringList(QString)>(18, 6, QMC::AccessPublic, QMetaType::QStringList, {{
            { QMetaType::QString, 6 },
        }}),
        // Method 'swapLayers'
        QtMocHelpers::MethodData<void(int, int, int)>(19, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 6 }, { QMetaType::Int, 6 },
        }}),
        // Method 'removeLayer'
        QtMocHelpers::MethodData<void(int, int)>(20, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 6 },
        }}),
        // Method 'toggleLayerUI'
        QtMocHelpers::MethodData<void(int, int)>(21, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 6 },
        }}),
        // Method 'setLayerEnabled'
        QtMocHelpers::MethodData<void(int, int, bool)>(22, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 6 }, { QMetaType::Bool, 6 },
        }}),
        // Method 'setLayerProcess'
        QtMocHelpers::MethodData<void(int, int, bool)>(23, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 6 }, { QMetaType::Bool, 6 },
        }}),
        // Method 'setLayerOutput'
        QtMocHelpers::MethodData<void(int, int, bool)>(24, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 6 }, { QMetaType::Bool, 6 },
        }}),
        // Method 'setInputRoute'
        QtMocHelpers::MethodData<void(int, int)>(25, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 6 },
        }}),
        // Method 'setOutputRoute'
        QtMocHelpers::MethodData<void(int, int)>(26, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 6 },
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
