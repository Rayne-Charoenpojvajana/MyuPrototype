#ifndef VST3LAYER_H
#define VST3LAYER_H

#include "layer.h"
#include "public.sdk/samples/vst-hosting/editorhost/source/platform/iapplication.h"
#include "public.sdk/samples/vst-hosting/audiohost/source/media/audioclient.h"
#include "public.sdk/source/vst/hosting/module.h"
#include "public.sdk/source/vst/hosting/plugprovider.h"
#include "public.sdk/source/vst/utility/optional.h"
#include "public.sdk/source/vst/utility/stringconvert.h"
#include "pluginterfaces/gui/iplugview.h"
#include "public.sdk/samples/vst-hosting/editorhost/source/platform/iapplication.h"
#include <pluginterfaces/vst/ivsteditcontroller.h>


class VST3Layer : public Layer
{
public:
    void transform(std::vector<float>&) override;
    void setupUI() override;
    void toggleUI() override;
    VST3Layer();
};

#endif // VST3LAYER_H
