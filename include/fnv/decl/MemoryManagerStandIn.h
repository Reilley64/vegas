#pragma once

// Compatibility entry base of the canonical MemoryManager, not an owner.
struct MemoryManagerStandIn {
protected:
    MemoryManagerStandIn() = default;
public:
    // 0x00aa3e40
    void *FUN_00aa3e40(unsigned int);
};
