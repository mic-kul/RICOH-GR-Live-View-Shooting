#include "SystemSupervisor.h"

namespace rvf {

void SystemSupervisor::begin(uint32_t nowMs) { _checkTask.reset(nowMs); }
bool SystemSupervisor::check(uint32_t nowMs, AppMessage& outMessage) {
    if (!_checkTask.consumeIfDue(nowMs)) { return false; }
    outMessage = AppMessage{};
    return false;
}

}  // namespace rvf
