#pragma once

#include <Arduino.h>

namespace rvf {

enum class LogLevel { Info, Warning, Error };

void logf(LogLevel level, const char* tag, const char* format, ...);

}  // namespace rvf

#define LOGI(tag, fmt, ...) ::rvf::logf(::rvf::LogLevel::Info, tag, fmt, ##__VA_ARGS__)
#define LOGW(tag, fmt, ...) ::rvf::logf(::rvf::LogLevel::Warning, tag, fmt, ##__VA_ARGS__)
#define LOGE(tag, fmt, ...) ::rvf::logf(::rvf::LogLevel::Error, tag, fmt, ##__VA_ARGS__)
