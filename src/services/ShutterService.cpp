#include "ShutterService.h"

namespace rvf {

Result ShutterService::shoot(bool) {
    return Result::failure(ErrorCode::InvalidState, "ShutterService skeleton is not wired");
}

}  // namespace rvf
