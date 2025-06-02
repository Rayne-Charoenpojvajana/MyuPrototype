#include "configs.h"


std::array<std::vector<float>, MAX_INPUTS> inputs;
std::array<std::vector<float>, MAX_OUTPUTS> outputs;
std::array<std::vector<std::unique_ptr<Layer>>, MAX_INPUTS> layers;
bool streaming = false;
DriverInfo asioDriverInfo;
ASIOCallbacks asioCallbacks;
AsioDrivers helperDrivers;
int maxDriverLength = MAX_DRIVERLENGTH;



