#include "Logger.h"

#include <stdarg.h>
#include <stdio.h>

namespace rvf {
namespace {
const char* levelText(LogLevel level) {
    switch (level) {
        case LogLevel::Info: return "I";
        case LogLevel::Warning: return "W";
        case LogLevel::Error: return "E";
    }
    return "?";
}
}  // namespace

void logf(LogLevel level, const char* tag, const char* format, ...) {
    Serial.printf("[%s][%s] ", levelText(level), tag != nullptr ? tag : "APP");

    char buffer[192];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format != nullptr ? format : "", args);
    va_end(args);

    Serial.print(buffer);
    Serial.println();
}

}  // namespace rvf
