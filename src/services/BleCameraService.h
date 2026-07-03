#pragma once

#include "../core/Result.h"

namespace rvf {

class BleCameraService {
public:
    Result begin();
    Result scan();
    Result connect();
    void disconnect();
    bool isConnected() const;
};

}  // namespace rvf
