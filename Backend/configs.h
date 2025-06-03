#ifndef CONFIGS_H
#define CONFIGS_H


#define MAX_BUFFERS 256
#define MIN_BUFFERS 256
#define MAX_INPUTS 2
#define MAX_OUTPUTS 2
#define MAX_DRIVERLENGTH 128
#define NUM_SAMPLERATES 1


#include "asio.h"
#include <array>
enum {
    // number of input and outputs supported by the host application
    // you can change these to higher or lower values
    kMaxInputChannels = MAX_INPUTS,
    kMaxOutputChannels = MAX_OUTPUTS
};


// internal data storage
typedef struct DriverInfo
{
    // ASIOInit()
    ASIODriverInfo driverInfo;

    // ASIOGetChannels()
    long           inputChannels;
    long           outputChannels;

    // ASIOGetBufferSize()
    long           minSize;
    long           maxSize;
    long           preferredSize;
    long           granularity;
    long           selectedBufferSize;

    // ASIOGetSampleRate()
    ASIOSampleRate sampleRate;

    long selectedSampleRate;
    // ASIOOutputReady()
    bool           postOutput;

    // ASIOGetLatencies ()
    long           inputLatency;
    long           outputLatency;

    // ASIOCreateBuffers ()
    long inputBuffers;	// becomes number of actual created input buffers
    long outputBuffers;	// becomes number of actual created output buffers
    ASIOBufferInfo bufferInfos[kMaxInputChannels + kMaxOutputChannels]; // buffer info's

    // ASIOGetChannelInfo()
    ASIOChannelInfo channelInfos[kMaxInputChannels + kMaxOutputChannels]; // channel info's
    // The above two arrays share the same indexing, as the data in them are linked together

    // Information from ASIOGetSamplePosition()
    // data is converted to double floats for easier use, however 64 bit integer can be used, too
    double         nanoSeconds;
    double         samples;
    double         tcSamples;	// time code samples

    // bufferSwitchTimeInfo()
    ASIOTime       tInfo;			// time info state
    unsigned long  sysRefTime;      // system reference time, when bufferSwitch() was called

    // Signal the end of processing in this example
    bool           stopped;
} DriverInfo;

class Configs {
private:
    Configs();;
    ~Configs();;
public:
    int maxDriverLength = MAX_DRIVERLENGTH;
    long selectedBufferSize = MIN_BUFFERS;
    long softwareMinBuffer = MIN_BUFFERS;
    long softwareMaxBuffer = MAX_BUFFERS;
    std::array<long, NUM_SAMPLERATES> softwareSampleRates = {192000};
    long selectedSampleRate = softwareSampleRates[0];
    static Configs& getInstance();

};

#endif // CONFIGS_H
