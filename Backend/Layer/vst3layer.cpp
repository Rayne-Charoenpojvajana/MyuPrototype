#include "vst3layer.h"




void VST3Layer::transform(std::vector<float>& input)
{
    for(int i = 0; i < input.size(); i++) {
        processData.inputs->channelBuffers32[0][i] = input[i];
        processData.inputs->channelBuffers32[1][i] = input[i];
    }
    audioEffect->process(processData);
    for(int i = 0; i < input.size(); i++) {
        input[i] = processData.outputs->channelBuffers32[0][i];
    }
}

void VST3Layer::setupUI()
{
    context = owned(new HostApplication());
    PluginContextFactory::instance().setPluginContext(context);
    std::string path = getPath().toStdString();
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
    auto flags = contextRequirements->getProcessContextRequirements();
    view = editController->createView(ViewType::kEditor);
    ViewRect viewRect = {};
    view->getSize(&viewRect);
    view->isPlatformTypeSupported(kPlatformTypeHWND);
    window = new QQuickWindow();
    window->setWidth(viewRect.getWidth());
    window->setHeight(viewRect.getHeight());
    window->setMaximumWidth(viewRect.getWidth());
    window->setMaximumHeight(viewRect.getHeight());
    view->attached((HWND) window->winId(), Steinberg::kPlatformTypeHWND);
    window->show();
    numInAudioBuses = vstPlug->getBusCount(MediaTypes::kAudio, BusDirections::kInput);
    numOutAudioBuses = vstPlug->getBusCount(MediaTypes::kAudio, BusDirections::kOutput);
    numInEventBuses = vstPlug->getBusCount(MediaTypes::kEvent, BusDirections::kInput);
    numOutEventBuses = vstPlug->getBusCount(MediaTypes::kEvent, BusDirections::kOutput);
    for (int i = 0; i < numInAudioBuses; ++i) {
        BusInfo info;
        vstPlug->getBusInfo(kAudio, kInput, i, info);
        inAudioBusInfos.push_back(info);
        vstPlug->activateBus(kAudio, kInput, i, true);

        SpeakerArrangement speakerArr;
        audioEffect->getBusArrangement(kInput, i, speakerArr);
        inSpeakerArrs.push_back(speakerArr);
    }

    for (int i = 0; i < numInEventBuses; ++i) {
        BusInfo info;
        vstPlug->getBusInfo(kEvent, kInput, i, info);
        inEventBusInfos.push_back(info);
        vstPlug->activateBus(kEvent, kInput, i, true);
    }

    for (int i = 0; i < numOutAudioBuses; ++i) {
        BusInfo info;
        vstPlug->getBusInfo(kAudio, kOutput, i, info);
        outAudioBusInfos.push_back(info);
        vstPlug->activateBus(kAudio, kOutput, i, true);

        SpeakerArrangement speakerArr;
        audioEffect->getBusArrangement(kOutput, i, speakerArr);
        outSpeakerArrs.push_back(speakerArr);
    }

    for (int i = 0; i < numOutEventBuses; ++i) {
        BusInfo info;
        vstPlug->getBusInfo(kEvent, kOutput, i, info);
        outEventBusInfos.push_back(info);
        vstPlug->activateBus(kEvent, kOutput, i, true);
    }
    // audioEffect->setBusArrangements(inSpeakerArrs.data(), numInAudioBuses, outSpeakerArrs.data(), numOutAudioBuses);
    processSetup.processMode = kRealtime;
    processSetup.symbolicSampleSize = kSample32;
    processSetup.sampleRate = 192000;
    processSetup.maxSamplesPerBlock = 512;
    audioEffect->setupProcessing(processSetup);
    processData.prepare(*vstPlug, processSetup.maxSamplesPerBlock, processSetup.symbolicSampleSize);
    processData.numSamples = processSetup.maxSamplesPerBlock;
    processData.processContext = &processContext;
    if (numInEventBuses > 0) {
        processData.inputEvents = new EventList[numInEventBuses];
    }
    if (numOutEventBuses > 0) {
        processData.outputEvents = new EventList[numOutEventBuses];
    }
    vstPlug->setActive(true);
    audioEffect->setProcessing(true);
}

void VST3Layer::toggleUI()
{

}

VST3Layer::VST3Layer() {}



