#pragma once

#include <cstdint>

class NiPoint3;

struct Thing {
public:
    // 0x0043a930
    void Save();
    // 0x00480180
    void SetByte(int, char, unsigned char);
    // 0x00525a90
    std::intptr_t GetOrFallback(std::intptr_t);
    // 0x00564bc0
    bool FUN_00564bc0();
    // 0x0056afc0
    bool FUN_0056afc0();
    // 0x006b0a60
    ::NiPoint3 *RotatePoint90(::NiPoint3 *, float *, int);
    // 0x006c4970
    bool FUN_006c4970();
    // 0x007e5e30
    int GetIndex(int);
    // 0x00867ca0
    int FUN_00867ca0();
    // 0x00881510
    intptr_t FUN_00881510();
    // 0x00a64010
    void WriteData();
};
