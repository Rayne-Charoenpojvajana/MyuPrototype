/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<clicklayer.h>)
#  include <clicklayer.h>
#endif
#if __has_include(<gainlayer.h>)
#  include <gainlayer.h>
#endif
#if __has_include(<maincontroller.h>)
#  include <maincontroller.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_MyuPrototype()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<ClickLayer>("MyuPrototype", 1);
    qmlRegisterTypesAndRevisions<GainLayer>("MyuPrototype", 1);
    QMetaType::fromType<Layer *>().id();
    qmlRegisterTypesAndRevisions<MainController>("MyuPrototype", 1);
    QT_WARNING_POP
    qmlRegisterModule("MyuPrototype", 1, 0);
}

static const QQmlModuleRegistration myuPrototypeRegistration("MyuPrototype", qml_register_types_MyuPrototype);
