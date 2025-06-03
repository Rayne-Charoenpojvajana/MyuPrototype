#include "livedata.h"



LiveData::LiveData() {}

LiveData::~LiveData() {}

LiveData &LiveData::getInstance() {
    static LiveData instance;
    return instance;
}
