#pragma once

#include <Arduino.h>

namespace rvf {

struct PreviewFrameStats {
    uint32_t frames = 0;
    uint32_t droppedFrames = 0;
    size_t lastFrameSize = 0;
};

class PreviewFrameBuffer {
public:
    void reset();
    void recordFrame(size_t size);
    void recordDrop();
    PreviewFrameStats stats() const;
private:
    PreviewFrameStats _stats;
};

}  // namespace rvf
