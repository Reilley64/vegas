#pragma once
#include <cstdint>

struct TransformRecord {
public:
    // 0x00a59980
    void GetMatrix(uintptr_t, float *);
};
