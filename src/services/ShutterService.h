#pragma once

#include "../core/Result.h"

namespace rvf {

class ShutterService {
public:
    Result shoot(bool autofocus);
};

}  // namespace rvf
