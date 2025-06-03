#ifndef ASIOFUNCTIONS_H
#define ASIOFUNCTIONS_H

#include "livedata.h"

extern Configs& configs;
extern LiveData& liveData;
extern AsioDrivers helperDrivers;


// extern bool streaming;


// extern std::array<std::vector<float>, MAX_INPUTS> inputs;
// extern std::array<std::vector<std::unique_ptr<Layer>>, MAX_INPUTS> layers;
// extern std::array<std::vector<float>, MAX_OUTPUTS> outputs;





bool loadAsioDriver(char*);
void setupASIO(char*);
long init_asio_static_data (DriverInfo*);
ASIOError create_asio_buffers (DriverInfo*);
unsigned long get_sys_reference_time();
void bufferSwitch(long, ASIOBool);
ASIOTime *bufferSwitchTimeInfo(ASIOTime*, long, ASIOBool);
void sampleRateChanged(ASIOSampleRate);
long asioMessages(long, long, void*, double*);



#endif // ASIOFUNCTIONS_H
