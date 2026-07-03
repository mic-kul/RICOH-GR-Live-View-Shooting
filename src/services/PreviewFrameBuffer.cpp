#include "PreviewFrameBuffer.h"

namespace rvf {

void PreviewFrameBuffer::reset() { _stats = PreviewFrameStats{}; }
void PreviewFrameBuffer::recordFrame(size_t size) { ++_stats.frames; _stats.lastFrameSize = size; }
void PreviewFrameBuffer::recordDrop() { ++_stats.droppedFrames; }
PreviewFrameStats PreviewFrameBuffer::stats() const { return _stats; }

}  // namespace rvf
