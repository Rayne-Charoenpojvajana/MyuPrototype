#include "asiofunctions.h"


long selectedBufferSize = MIN_BUFFERS;

float inputs[MAX_INPUTS][MAX_BUFFERS];
float outputs[MAX_OUTPUTS][MAX_BUFFERS];

bool streaming = false;
DriverInfo asioDriverInfo;
ASIOCallbacks asioCallbacks;
AsioDrivers helperDrivers;
int maxDriverLength = 32;
long softwareMinBuffer = MIN_BUFFERS;
const long softwareMaxBuffer = MAX_BUFFERS;
long numSampleRates = 2;
long softwareSampleRates[] = {44100, 48000};
long selectedSampleRate = softwareSampleRates[0];
WAVFile* clicks = new WAVFile(":/Click_1.wav");
int intData[2][64];
