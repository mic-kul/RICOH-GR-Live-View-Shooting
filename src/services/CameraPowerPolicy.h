#pragma once

namespace rvf {

enum class CameraPowerStatus { Unknown, Off, On };

class CameraPowerPolicy {
public:
    bool mayActivateWifi(CameraPowerStatus status) const;
};

}  // namespace rvf
