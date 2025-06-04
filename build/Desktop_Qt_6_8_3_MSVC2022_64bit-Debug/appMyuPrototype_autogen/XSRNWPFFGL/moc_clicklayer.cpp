/****************************************************************************
** Meta object code from reading C++ file 'clicklayer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Backend/Layer/clicklayer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clicklayer.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10ClickLayerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10ClickLayerE = QtMocHelpers::stringData(
    "ClickLayer",
    "QML.Element",
    "auto",
    "setBPM",
    "",
    "setAccent",
    "setGain"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10ClickLayerE[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       3,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   34,    4, 0x02,    1 /* Public */,
       5,    1,   37,    4, 0x02,    3 /* Public */,
       6,    1,   40,    4, 0x02,    5 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Float,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject ClickLayer::staticMetaObject = { {
    QMetaObject::SuperData::link<Layer::staticMetaObject>(),
    qt_meta_stringdata_ZN10ClickLayerE.offsetsAndSizes,
    qt_meta_data_ZN10ClickLayerE,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // Q_OBJECT / Q_GADGET
        ClickLayer,
        // method 'setBPM'
        void,
        float,
        // method 'setAccent'
        void,
        int,
        // method 'setGain'
        void,
        float
    >,
    nullptr
} };

void ClickLayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ClickLayer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->setBPM((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 1: _t->setAccent((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->setGain((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *ClickLayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClickLayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10ClickLayerE.stringdata0))
        return static_cast<void*>(this);
    return Layer::qt_metacast(_clname);
}

int ClickLayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Layer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
