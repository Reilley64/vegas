#pragma once
#include <cstdint>

struct H {
public:
    // 0x0087b3b0
    void SendCommand22(std::uintptr_t, unsigned int);
    // 0x00b8a760
    void SetFloat4At(int, float, float, float, float);
};
