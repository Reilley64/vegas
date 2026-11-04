#pragma once

class NiStream;

struct NiTexture {
public:
    // 0x0064ceb0
    ::NiTexture *FUN_0064ceb0(float, float, float, void *);
    // 0x00a47350
    void LoadBinary(::NiStream &);
};
