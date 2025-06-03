#ifndef LIVEDATA_H
#define LIVEDATA_H
#include "configs.h"
#include "asiodrivers.h"
#include <QThread>
class LiveData
{
private:
    LiveData();;
    ~LiveData();
public:
    bool streaming = false;
    std::array<std::vector<float>, MAX_INPUTS> inputs;
    std::array<std::vector<float>, MAX_OUTPUTS> processes;
    std::array<std::vector<float>, MAX_OUTPUTS> outputs;
    static LiveData& getInstance();
};

#endif // LIVEDATA_H
