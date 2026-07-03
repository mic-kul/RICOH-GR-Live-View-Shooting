#pragma once

#include "../core/Result.h"

namespace rvf {

class WifiPreviewService {
public:
    Result activateWifi();
    Result connectWifi();
    void disconnectWifi();
    Result startPreview();
    void stopPreview();
    bool isPreviewRunning() const;
};

}  // namespace rvf
