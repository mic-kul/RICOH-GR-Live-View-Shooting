#pragma once

#include "../core/AppMessage.h"
#include "../core/PeriodicTask.h"

namespace rvf {

class SystemSupervisor {
public:
    void begin(uint32_t nowMs);
    bool check(uint32_t nowMs, AppMessage& outMessage);
private:
    PeriodicTask _checkTask{1000};
};

}  // namespace rvf
