#include "vst3layer.h"
#include "public.sdk/source/vst/hosting/hostclasses.h"
#include "public.sdk/source/vst/hosting/module.h"

void VST3Layer::transform(std::vector<float> &)
{

}
using namespace VST3::Hosting;
using namespace Steinberg;
using namespace Vst;


HostApplication* context = nullptr;
Module::Ptr module = nullptr;
IPtr<PlugProvider> plugProvider = nullptr;
IPtr<IComponent> vstPlug = nullptr;
IPtr<IAudioProcessor> audioEffect = nullptr;
IPtr<IEditController> editController = nullptr;
IPtr<Steinberg::IPlugView> view = nullptr;
void VST3Layer::setupUI()
{
    context = owned(new HostApplication());
    PluginContextFactory::instance().setPluginContext(context);
    std::string path = "C:/Users/User/Documents/NewFolder/MyuPrototype/MyuPrototype/VST3/Archetype Plini X.vst3";
    std::string error;
    module = VST3::Hosting::Module::create(path, error);
    PluginFactory factory = module->getFactory();
    for (auto &classInfo : factory.classInfos()) {
        if (classInfo.category() == kVstAudioEffectClass) {
            plugProvider = owned(new PlugProvider(factory, classInfo, true));
        }
    }
    vstPlug = plugProvider->getComponent();
    audioEffect = FUnknownPtr<IAudioProcessor>(vstPlug);
    editController = plugProvider->getController();
    FUnknownPtr<IProcessContextRequirements> contextRequirements(audioEffect);
    if (contextRequirements) {
        auto flags = contextRequirements->getProcessContextRequirements();
#define PRINT_FLAG(x) if (flags & IProcessContextRequirements::Flags::x) { qDebug() << (#x); }
        PRINT_FLAG(kNeedSystemTime)
        PRINT_FLAG(kNeedContinousTimeSamples)
        PRINT_FLAG(kNeedProjectTimeMusic)
        PRINT_FLAG(kNeedBarPositionMusic)
        PRINT_FLAG(kNeedCycleMusic)
        PRINT_FLAG(kNeedSamplesToNextClock)
        PRINT_FLAG(kNeedTempo)
        PRINT_FLAG(kNeedTimeSignature)
        PRINT_FLAG(kNeedChord)
        PRINT_FLAG(kNeedFrameRate)
        PRINT_FLAG(kNeedTransportState)
#undef PRINT_FLAG
    }
    view = editController->createView(ViewType::kEditor);
    if (!view) {
        qDebug() << "hey";
    }
}

void VST3Layer::toggleUI()
{

}

VST3Layer::VST3Layer() {}



