#pragma once

#include <Arduino.h>

namespace rvf {

enum class ErrorCode {
    Ok,
    Unknown,
    Timeout,
    InvalidState,
    BleConnectFailed,
    BleSecurityFailed,
    CameraPowerOff,
    WifiConnectFailed,
    HttpProbeFailed,
    PreviewTimeout,
    ShutterFailed,
};

struct Result {
    ErrorCode code = ErrorCode::Ok;
    String message;

    bool ok() const { return code == ErrorCode::Ok; }
    static Result success() { return Result{}; }
    static Result failure(ErrorCode error, const String& detail = String()) {
        Result result;
        result.code = error;
        result.message = detail;
        return result;
    }
};

}  // namespace rvf
