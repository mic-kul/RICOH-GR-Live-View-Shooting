#pragma once

namespace rvf {

enum class AppState {
    Booting,
    Idle,
    ScanningCamera,
    ConnectingBle,
    CheckingCameraPower,
    CameraPowerOff,
    ActivatingWifi,
    ConnectingWifi,
    HttpProbing,
    PreviewStarting,
    PreviewRunning,
    PreviewStopped,
    Shooting,
    Disconnected,
    Error,
};

}  // namespace rvf
