#pragma once

struct NiStream;

class NiSkinInstance {
public:
    // 0x00a86340
    void LoadBinary(::NiStream &);
    // 0x00a86380
    void LinkObject(::NiStream &);
};
