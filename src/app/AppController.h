#pragma once

#include "AppState.h"
#include "../core/AppMessage.h"

namespace rvf {

class AppController {
public:
    void begin();
    void tick(uint32_t nowMs);
    void dispatch(const AppMessage& message);
    AppState state() const;
private:
    AppState _state = AppState::Booting;
};

}  // namespace rvf
