#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _qt_qml_MyuPrototype_Frontend_Style_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_MyuPrototype_Frontend_Components_ToolBarButton_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_MyuPrototype_Frontend_Windows_MainWindow_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_MyuPrototype_Frontend_Windows_MainWindowFooter_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_MyuPrototype_Frontend_Windows_MainWindowHeader_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_MyuPrototype_Frontend_Windows_SettingsWindow_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_MyuPrototype_Frontend_Windows_LayerWindow_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_MyuPrototype_Frontend_Windows_ClickWindow_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_MyuPrototype_Frontend_Windows_GainWindow_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/MyuPrototype/Frontend/Style.qml"), &QmlCacheGeneratedCode::_qt_qml_MyuPrototype_Frontend_Style_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/MyuPrototype/Frontend/Components/ToolBarButton.qml"), &QmlCacheGeneratedCode::_qt_qml_MyuPrototype_Frontend_Components_ToolBarButton_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/MyuPrototype/Frontend/Windows/MainWindow.qml"), &QmlCacheGeneratedCode::_qt_qml_MyuPrototype_Frontend_Windows_MainWindow_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/MyuPrototype/Frontend/Windows/MainWindowFooter.qml"), &QmlCacheGeneratedCode::_qt_qml_MyuPrototype_Frontend_Windows_MainWindowFooter_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/MyuPrototype/Frontend/Windows/MainWindowHeader.qml"), &QmlCacheGeneratedCode::_qt_qml_MyuPrototype_Frontend_Windows_MainWindowHeader_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/MyuPrototype/Frontend/Windows/SettingsWindow.qml"), &QmlCacheGeneratedCode::_qt_qml_MyuPrototype_Frontend_Windows_SettingsWindow_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/MyuPrototype/Frontend/Windows/LayerWindow.qml"), &QmlCacheGeneratedCode::_qt_qml_MyuPrototype_Frontend_Windows_LayerWindow_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/MyuPrototype/Frontend/Windows/ClickWindow.qml"), &QmlCacheGeneratedCode::_qt_qml_MyuPrototype_Frontend_Windows_ClickWindow_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/MyuPrototype/Frontend/Windows/GainWindow.qml"), &QmlCacheGeneratedCode::_qt_qml_MyuPrototype_Frontend_Windows_GainWindow_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appMyuPrototype)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appMyuPrototype))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appMyuPrototype)() {
    return 1;
}
