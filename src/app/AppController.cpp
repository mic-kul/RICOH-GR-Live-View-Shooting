#include "AppController.h"

namespace rvf {

void AppController::begin() { _state = AppState::Idle; }
void AppController::tick(uint32_t) {}
void AppController::dispatch(const AppMessage& message) {
    if (message.type == AppEventType::ErrorRaised) {
        _state = AppState::Error;
    }
}
AppState AppController::state() const { return _state; }

}  // namespace rvf
