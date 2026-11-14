#pragma once

namespace VatsQueueText { struct VATSAction; }

namespace VatsQueueText {
struct VATSMenuQueue {
public:
    // 0x007efa10
    void UpdateQueueEntry(::VatsQueueText::VATSAction *, bool, bool);
};
}
