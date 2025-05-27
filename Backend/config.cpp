#include "asiofunctions.h"

#define MAX_BUFFER 512
#define MIN_BUFFER 64
long selectedBufferSize = MIN_BUFFER;

double input0[MAX_BUFFER];
double input1[MAX_BUFFER];
InputMonitors inputMonitors = {
    input0,
    input1
};
bool streaming = false;
DriverInfo asioDriverInfo;
ASIOCallbacks asioCallbacks;
AsioDrivers helperDrivers;
int maxDriverLength = 32;
long softwareMinBuffer = MIN_BUFFER;
const long softwareMaxBuffer = MAX_BUFFER;

long numSampleRates = 2;
long softwareSampleRates[] = {44100, 48000};
long selectedSampleRate = softwareSampleRates[0];


