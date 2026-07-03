#include "WifiPreviewService.h"

namespace rvf {

Result WifiPreviewService::activateWifi() { return Result::success(); }
Result WifiPreviewService::connectWifi() { return Result::success(); }
void WifiPreviewService::disconnectWifi() {}
Result WifiPreviewService::startPreview() { return Result::success(); }
void WifiPreviewService::stopPreview() {}
bool WifiPreviewService::isPreviewRunning() const { return false; }

}  // namespace rvf
