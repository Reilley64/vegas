#pragma once
#include <cstdint>

struct SpawnedObject {
public:
    // 0x007a6250
    void FUN_007a6250();
    // 0x0085fb40
    ::SpawnedObject *FUN_0085fb40(const char *, int, int);
    // 0x00c5b8d0
    void FUN_00c5b8d0();
    // 0x00dd8d40
    ::SpawnedObject *Construct(intptr_t);
};
