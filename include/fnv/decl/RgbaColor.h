#pragma once

struct NiStream;

struct RgbaColor {
public:
    // 0x005321d0
    ::RgbaColor &FUN_005321d0(float);
    // 0x00a69720
    char *ToString(const char *);
    // 0x00a69800
    void LoadBinary(::NiStream &);
};
