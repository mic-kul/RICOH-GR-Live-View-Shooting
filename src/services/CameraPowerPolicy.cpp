#include "CameraPowerPolicy.h"

namespace rvf {

bool CameraPowerPolicy::mayActivateWifi(CameraPowerStatus status) const {
    // Placeholder policy: do not proceed unless confirmed on.
    return status == CameraPowerStatus::On;
}

}  // namespace rvf
