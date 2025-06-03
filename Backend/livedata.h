#ifndef LIVEDATA_H
#define LIVEDATA_H
#include "configs.h"
#include "asiodrivers.h"
#include "Layer/clicklayer.h"
#include "Layer/gainlayer.h"
#include <QThread>
class LiveData
{
private:
    LiveData();;
    ~LiveData();
public:
    bool streaming = false;
    std::array<std::vector<float>, MAX_INPUTS> inputs;
    std::array<std::vector<float>, MAX_OUTPUTS> outputs;
    std::array<std::vector<std::unique_ptr<Layer>>, MAX_INPUTS> layers;
    std::array<int, MAX_INPUTS> inputRoute = {0, 1};
    std::array<int, MAX_OUTPUTS> outputRoute = {0, 1};
    static LiveData& getInstance();
};

#endif // LIVEDATA_H
