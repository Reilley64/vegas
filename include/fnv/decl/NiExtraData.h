#pragma once

class NiFixedString;
class NiStream;

class NiExtraData {
public:
    // 0x00a7b3b0
    void LinkObject(::NiStream &);
    // 0x00a7b440
    NiExtraData(const ::NiFixedString &);
    // 0x00a7b4a0
    void LoadBinary(::NiStream &);
};
