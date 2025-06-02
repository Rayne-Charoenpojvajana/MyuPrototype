#include "asiofunctions.h"

long selectedBufferSize = MIN_BUFFERS;
std::array<long, NUM_SAMPLERATES> softwareSampleRates = {192000};
long selectedSampleRate = softwareSampleRates[0];
std::array<std::vector<float>, MAX_INPUTS> inputs;
std::array<std::vector<float>, MAX_OUTPUTS> outputs;
std::array<std::vector<std::unique_ptr<Layer>>, MAX_INPUTS> layers;
bool streaming = false;
DriverInfo asioDriverInfo;
ASIOCallbacks asioCallbacks;
AsioDrivers helperDrivers;
int maxDriverLength = MAX_DRIVERLENGTH;
long softwareMinBuffer = MIN_BUFFERS;
long softwareMaxBuffer = MAX_BUFFERS;
QMutex mutex;
