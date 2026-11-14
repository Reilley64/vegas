#pragma once

#include "havok/hkMemoryRouter.h"

// Complete native monitor owner. The four cursor fields are consumed by job callers.
struct SpawnedBuffer
{
    char* m_00 = nullptr;
    char* m_04 = nullptr;
    char* m_08 = nullptr;
    char* m_0c = nullptr;
    unsigned char m_10 = 0;

    explicit SpawnedBuffer(hkMemoryAllocator& allocator) : allocator(allocator) {}
    ~SpawnedBuffer();
    void Resize(int bytes);
    void Reset() { m_04 = m_00; }
    hkMemoryAllocator& allocator;
    int capacity = 0;
};

namespace havok::base
{
SpawnedBuffer* GetMonitor();
// Publishes a borrowed owner; allocation and release stay with the caller.
void SetMonitor(SpawnedBuffer* value);
}
