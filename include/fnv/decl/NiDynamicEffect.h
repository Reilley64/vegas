#pragma once

class NiStream;

class NiDynamicEffect {
public:
    // 0x004bc2c0
    void IncRevisionID();
    // 0x00a68ea0
    void LoadBinary(::NiStream &);
    // 0x00a69070
    void LinkObject(::NiStream &);
    // 0x00a69320
    NiDynamicEffect();
};
