#include "configs.h"
#include <qqmlapplicationengine.h>






Configs::Configs() {}

Configs::~Configs() {}

Configs &Configs::getInstance() {
    static Configs s;
    return s;
}
