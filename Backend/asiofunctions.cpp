#include "asiofunctions.h"






DriverInfo asioDriverInfo;
ASIOCallbacks asioCallbacks;
AsioDrivers helperDrivers;
extern AsioDrivers* asioDrivers;




//----------------------------------------------------------------------------------
long init_asio_static_data (DriverInfo *asioDriverInfo)
{
    if (ASIOGetChannels(&asioDriverInfo->inputChannels, &asioDriverInfo->outputChannels) != ASE_OK) {
        return -1;
    }
    if (ASIOGetBufferSize(&asioDriverInfo->minSize, &asioDriverInfo->maxSize, &asioDriverInfo->preferredSize, &asioDriverInfo->granularity) != ASE_OK) {
        return -2;
    }
    if (ASIOCanSampleRate(asioDriverInfo->selectedSampleRate) != ASE_OK) {
        return -3;
    }
    if (ASIOSetSampleRate(asioDriverInfo->selectedSampleRate) != ASE_OK) {
        return -4;
    }
    if (ASIOGetSampleRate(&asioDriverInfo->sampleRate) != ASE_OK) {
        return -5;
    }
    if(ASIOOutputReady() == ASE_OK) {
        asioDriverInfo->postOutput = true;
    } else {
        asioDriverInfo->postOutput = false;
    }
    return 0;
}


//----------------------------------------------------------------------------------
// conversion from 64 bit ASIOSample/ASIOTimeStamp to double float
#if NATIVE_INT64
#define ASIO64toDouble(a)  (a)
#else
const double twoRaisedTo32 = 4294967296.;
#define ASIO64toDouble(a)  ((a).lo + (a).hi * twoRaisedTo32)
#endif

ASIOTime *bufferSwitchTimeInfo(ASIOTime *timeInfo, long index, ASIOBool processNow)
{
    long buffSize = asioDriverInfo.selectedBufferSize;
    int iCount = 0;
    for (int i = 0; i < asioDriverInfo.inputBuffers + asioDriverInfo.outputBuffers; i++) {
        if (asioDriverInfo.bufferInfos[i].isInput == ASIOTrue && iCount < liveData.inputs.size()) {
            switch (asioDriverInfo.channelInfos[i].type) {
            case ASIOSTInt32LSB:
                for(int j = 0; j < buffSize; ++j) {
                    liveData.inputs[iCount][j] = *((int *)asioDriverInfo.bufferInfos[i].buffers[index] + j) / (float )0x7fffffff;
                }   
                break;
            }
            iCount++;
        }
    }
    for (int i = 0; i < configs.layers.size(); i++) {
        liveData.outputs[i].assign(buffSize, 0);
        auto &chain = configs.layers[i];
        int inputSrc = configs.inputRoute[i];
        liveData.processes[i] = liveData.inputs[inputSrc];
        for(int k = 0; k < chain.size(); k++) {
            auto &layer = chain[k];
            if (layer->getEnabled()) {
                layer->transform(liveData.processes[i]);
            }
            if (layer->getProcess()) {

            }
            if (layer->getOutput()) {
                liveData.outputs[i] = liveData.processes[i];
            }
        }
    }
    int oCount = 0;
    for (int i = 0; i < asioDriverInfo.inputBuffers + asioDriverInfo.outputBuffers; i++) {
        if (asioDriverInfo.bufferInfos[i].isInput == false && oCount < liveData.outputs.size()) {
            switch (asioDriverInfo.channelInfos[i].type) {
            case ASIOSTInt32LSB:
                for(int j = 0; j < buffSize; ++j) {
                    *((int*)asioDriverInfo.bufferInfos[i].buffers[index] + j) = liveData.outputs[oCount][j] * (float) 0x7fffffff;
                }
                break;
            }
            oCount++;
        }
    }
    if (asioDriverInfo.postOutput) {
        ASIOOutputReady();
    }
    return 0L;
}

//----------------------------------------------------------------------------------
void bufferSwitch(long index, ASIOBool processNow)
{
    ASIOTime  timeInfo;
    memset (&timeInfo, 0, sizeof (timeInfo));
    if(ASIOGetSamplePosition(&timeInfo.timeInfo.samplePosition, &timeInfo.timeInfo.systemTime) == ASE_OK)
        timeInfo.timeInfo.flags = kSystemTimeValid | kSamplePositionValid;
    bufferSwitchTimeInfo (&timeInfo, index, processNow);
}


//----------------------------------------------------------------------------------
void sampleRateChanged(ASIOSampleRate sRate)
{

}

//----------------------------------------------------------------------------------
long asioMessages(long selector, long value, void* message, double* opt)
{
    long ret = 0;
    switch(selector)
    {
    case kAsioSelectorSupported:
        if(value == kAsioResetRequest
            || value == kAsioEngineVersion
            || value == kAsioResyncRequest
            || value == kAsioLatenciesChanged
            || value == kAsioSupportsTimeInfo
            || value == kAsioSupportsTimeCode
            || value == kAsioSupportsInputMonitor)
            ret = 1L;
        break;
    case kAsioResetRequest:
        ret = 1L;
        break;
    case kAsioResyncRequest:
        ret = 1L;
        break;
    case kAsioLatenciesChanged:
        ret = 1L;
        break;
    case kAsioEngineVersion:
        ret = 2L;
        break;
    case kAsioSupportsTimeInfo:
        ret = 1;
        break;
    case kAsioSupportsTimeCode:
        ret = 0;
        break;
    }
    return ret;
}


//----------------------------------------------------------------------------------
ASIOError create_asio_buffers (DriverInfo *asioDriverInfo)
{
    long i;
    ASIOError result;
    ASIOBufferInfo *info = asioDriverInfo->bufferInfos;
    if (asioDriverInfo->inputChannels > kMaxInputChannels)
        asioDriverInfo->inputBuffers = kMaxInputChannels;
    else
        asioDriverInfo->inputBuffers = asioDriverInfo->inputChannels;
    for(i = 0; i < asioDriverInfo->inputBuffers; i++, info++)
    {
        info->isInput = ASIOTrue;
        info->channelNum = i;
        info->buffers[0] = info->buffers[1] = 0;
    }
    if (asioDriverInfo->outputChannels > kMaxOutputChannels)
        asioDriverInfo->outputBuffers = kMaxOutputChannels;
    else
        asioDriverInfo->outputBuffers = asioDriverInfo->outputChannels;
    for(i = 0; i < asioDriverInfo->outputBuffers; i++, info++)
    {
        info->isInput = ASIOFalse;
        info->channelNum = i;
        info->buffers[0] = info->buffers[1] = 0;
    }
    result = ASIOCreateBuffers(asioDriverInfo->bufferInfos,
                               asioDriverInfo->inputBuffers + asioDriverInfo->outputBuffers,
                               asioDriverInfo->selectedBufferSize, &asioCallbacks);
    if (result == ASE_OK)
    {
        for (i = 0; i < asioDriverInfo->inputBuffers + asioDriverInfo->outputBuffers; i++)
        {
            asioDriverInfo->channelInfos[i].channel = asioDriverInfo->bufferInfos[i].channelNum;
            asioDriverInfo->channelInfos[i].isInput = asioDriverInfo->bufferInfos[i].isInput;
            result = ASIOGetChannelInfo(&asioDriverInfo->channelInfos[i]);
            if (result != ASE_OK)
                break;
        }
        if (result == ASE_OK)
        {
            result = ASIOGetLatencies(&asioDriverInfo->inputLatency, &asioDriverInfo->outputLatency);
        }

    }
    return result;
}

unsigned long get_sys_reference_time()
{
    QTime now = QTime::currentTime();
    return now.msecsSinceStartOfDay();
}

void setupASIO(char* asioDriverName) {

    asioDriverInfo = {};
    if (loadAsioDriver (asioDriverName))
    {
        if (ASIOInit (&asioDriverInfo.driverInfo) == ASE_OK)
        {
            asioDriverInfo.selectedSampleRate = configs.selectedSampleRate;
            if (init_asio_static_data (&asioDriverInfo) == 0)
            {
                if (configs.selectedBufferSize < asioDriverInfo.minSize) {
                    asioDriverInfo.selectedBufferSize = std::max({configs.softwareMinBuffer, asioDriverInfo.minSize});
                } else if (configs.selectedBufferSize > asioDriverInfo.maxSize) {
                    asioDriverInfo.selectedBufferSize = std::min({configs.softwareMinBuffer, asioDriverInfo.minSize});
                } else {
                    asioDriverInfo.selectedBufferSize = configs.selectedBufferSize;
                }
                asioCallbacks.bufferSwitch = &bufferSwitch;
                asioCallbacks.sampleRateDidChange = &sampleRateChanged;
                asioCallbacks.asioMessage = &asioMessages;
                asioCallbacks.bufferSwitchTimeInfo = &bufferSwitchTimeInfo;
                if (create_asio_buffers (&asioDriverInfo) == ASE_OK)
                {
                    for(int i = 0; i < liveData.inputs.size(); i++) {
                        liveData.inputs[i].assign(asioDriverInfo.selectedBufferSize, 0);
                    }
                    for(int i = 0; i < liveData.processes.size(); i++) {
                        liveData.processes[i].assign(asioDriverInfo.selectedBufferSize, 0);
                    }
                    for(int i = 0; i < liveData.outputs.size(); i++) {
                        liveData.outputs[i].assign(asioDriverInfo.selectedBufferSize, 0);
                    }
                    if (ASIOStart() == ASE_OK)
                    {
                        while (!asioDriverInfo.stopped && liveData.streaming)
                        {

                            QThread::msleep(250);
                        }
                        asioDriverInfo.stopped = true;
                        ASIOStop();
                    }
                    ASIODisposeBuffers();
                }
            }
            ASIOExit();
        }
        asioDrivers->removeCurrentDriver();
    }
}

