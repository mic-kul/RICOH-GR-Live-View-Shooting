#include "BleCameraService.h"

namespace rvf {

Result BleCameraService::begin() { return Result::success(); }
Result BleCameraService::scan() { return Result::success(); }
Result BleCameraService::connect() { return Result::success(); }
void BleCameraService::disconnect() {}
bool BleCameraService::isConnected() const { return false; }

}  // namespace rvf
