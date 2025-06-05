#ifndef VST3LAYER_H
#define VST3LAYER_H

#include "layer.h"
#include "pluginterfaces/vst/ivstaudioprocessor.h"
#include "pluginterfaces/vst/ivstprocesscontext.h"
#include "public.sdk/source/vst/hosting/hostclasses.h"
#include "public.sdk/source/vst/hosting/module.h"
#include "public.sdk/source/vst/hosting/plugprovider.h"
#include "pluginterfaces/gui/iplugview.h"
#include "public.sdk/source/vst/hosting/processdata.h"
#include "public.sdk/source/vst/hosting/eventlist.h"
#include <QQuickWindow>
using namespace VST3::Hosting;
using namespace Steinberg;
using namespace Vst;
class VST3Layer : public Layer
{
private:
    HostApplication* context = nullptr;
    Module::Ptr module = nullptr;
    IPtr<PlugProvider> plugProvider = nullptr;
    IPtr<IComponent> vstPlug = nullptr;
    IPtr<IAudioProcessor> audioEffect = nullptr;
    IPtr<IEditController> editController = nullptr;
    IPtr<IPlugView> view = nullptr;
    QQuickWindow* window;
    HostProcessData processData = {};
    ProcessSetup processSetup = {};
    ProcessContext processContext = {};
    std::vector<BusInfo> inAudioBusInfos, outAudioBusInfos;
    int numInAudioBuses = 0, numOutAudioBuses = 0;
    std::vector<BusInfo> inEventBusInfos, outEventBusInfos;
    std::vector<SpeakerArrangement> inSpeakerArrs, outSpeakerArrs;
    int numInEventBuses = 0, numOutEventBuses = 0;
public:
    void transform(std::vector<float>&) override;
    void setupUI() override;
    void toggleUI() override;
    VST3Layer();
};

#endif // VST3LAYER_H
