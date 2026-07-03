#pragma once

#include "UserCommand.h"

namespace rvf {

class ButtonInput {
public:
    UserCommand poll();
};

}  // namespace rvf
