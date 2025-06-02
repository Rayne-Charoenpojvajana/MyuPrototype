#ifndef ASIOFUNCTIONS_H
#define ASIOFUNCTIONS_H

#include "Configs.h"


extern Configs& configs;
extern DriverInfo asioDriverInfo;
extern ASIOCallbacks asioCallbacks;
extern bool streaming;
extern int maxDriverLength;
// extern long selectedBufferSize;
// extern long softwareMinBuffer;
// extern long softwareMaxBuffer;
// extern long selectedSampleRate;
// extern std::array<long, NUM_SAMPLERATES> softwareSampleRates;
extern std::array<std::vector<float>, MAX_INPUTS> inputs;
extern std::array<std::vector<float>, MAX_OUTPUTS> outputs;
//----------------------------------------------------------------------------------
// some external references
extern AsioDrivers* asioDrivers;
extern std::array<std::vector<std::unique_ptr<Layer>>, MAX_INPUTS> layers;
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
