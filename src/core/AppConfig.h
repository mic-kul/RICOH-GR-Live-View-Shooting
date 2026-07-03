#pragma once

#include <Arduino.h>

namespace rvf {

struct AppConfig {
    static constexpr const char* kProjectName = "RICOH Viewfinder";
    static constexpr const char* kFirmwareRole = "StickS3 GR viewfinder";
    // TODO_UNVERIFIED: future phases may move confirmed values from src/config.h here.
};

}  // namespace rvf
