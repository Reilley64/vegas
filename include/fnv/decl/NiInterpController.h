#pragma once

struct NiStream;

class NiInterpController {
public:
    // 0x00a2f910
    void LoadBinary(::NiStream &);
    // 0x00c9a6b0
    void LinkObject(::NiStream &);
    // 0x01096320
    static const unsigned short INVALID_INDEX;
};
