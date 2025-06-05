#ifndef ASIOFUNCTIONS_H
#define ASIOFUNCTIONS_H

#include "livedata.h"

static Configs& configs = Configs::getInstance();
static LiveData& liveData = LiveData::getInstance();
extern AsioDrivers helperDrivers;
bool loadAsioDriver(char*);
bool setupASIO(char*);
bool endASIO();
long init_asio_static_data (DriverInfo*);
ASIOError create_asio_buffers (DriverInfo*);
unsigned long get_sys_reference_time();
void bufferSwitch(long, ASIOBool);
ASIOTime *bufferSwitchTimeInfo(ASIOTime*, long, ASIOBool);
void sampleRateChanged(ASIOSampleRate);
long asioMessages(long, long, void*, double*);



#endif // ASIOFUNCTIONS_H
