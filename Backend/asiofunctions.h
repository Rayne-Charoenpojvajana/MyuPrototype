#ifndef ASIOFUNCTIONS_H
#define ASIOFUNCTIONS_H

#include <windows.h>
#include "asio.h"
#include "asiodrivers.h"
#include "Audio/wavfile.h"
#include <QTime>


#define MAX_BUFFERS 512
#define MIN_BUFFERS 64
#define MAX_OUTPUTS 32
#define MAX_INPUTS 32


enum {
    // number of input and outputs supported by the host application
    // you can change these to higher or lower values
    kMaxInputChannels = MAX_INPUTS,
    kMaxOutputChannels = MAX_OUTPUTS
};

extern int intData[2][64];
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



extern DriverInfo asioDriverInfo;
extern ASIOCallbacks asioCallbacks;
extern bool streaming;
extern int maxDriverLength;
extern long selectedBufferSize;
extern long softwareMinBuffer;
extern const long softwareMaxBuffer;
extern long selectedSampleRate;
extern long softwareSampleRates[];
extern long numSampleRates;
extern float inputs[MAX_INPUTS][MAX_BUFFERS];
extern float outputs[MAX_OUTPUTS][MAX_BUFFERS];

//----------------------------------------------------------------------------------
// some external references
extern AsioDrivers* asioDrivers;
extern WAVFile* clicks;
bool loadAsioDriver(char *name);

// internal prototypes (required for the Metrowerks CodeWarrior compiler)
void setupASIO(char*);
long init_asio_static_data (DriverInfo *asioDriverInfo);
ASIOError create_asio_buffers (DriverInfo *asioDriverInfo);
unsigned long get_sys_reference_time();


// callback prototypes
void bufferSwitch(long index, ASIOBool processNow);
ASIOTime *bufferSwitchTimeInfo(ASIOTime *timeInfo, long index, ASIOBool processNow);
void sampleRateChanged(ASIOSampleRate sRate);
long asioMessages(long selector, long value, void* message, double* opt);



#endif // ASIOFUNCTIONS_H
