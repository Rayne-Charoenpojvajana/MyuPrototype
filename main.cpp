#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>



#include "public.sdk/samples/vst-hosting/editorhost/source/platform/iapplication.h"
#include "public.sdk/samples/vst-hosting/audiohost/source/media/audioclient.h"
#include "public.sdk/source/vst/hosting/module.h"
#include "public.sdk/source/vst/hosting/plugprovider.h"
#include "public.sdk/source/vst/utility/optional.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/logo.png"));
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MyuPrototype", "MainWindow");
    // std::string error = "";
    // const std::string path = "C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/VST3/Archetype Plini X.vst3";
    // VST3::Hosting::Module::Ptr module = VST3::Hosting::Module::create(path, error);
    // if (! module) {
    //      return -1;
    // }
    // auto factory = module->getFactory ();
    // VST3::Optional<VST3::UID> effectID;
    // Steinberg::IPtr<Steinberg::Vst::PlugProvider> plugProvider;
    // for (auto& classInfo : factory.classInfos ())
    // {
    //     if (classInfo.category () == kVstAudioEffectClass)
    //     {
    //         if (effectID)
    //         {
    //             if (*effectID != classInfo.ID ())
    //                 continue;
    //         }
    //         plugProvider = owned (new Steinberg::Vst::PlugProvider (factory, classInfo, true));
    //         break;
    //     }
    // }







    return app.exec();
}
