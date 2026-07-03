#pragma once

#include "../core/AppMessage.h"

namespace rvf {

class UiManager {
public:
    void handleMessage(const AppMessage& message);
};

}  // namespace rvf
