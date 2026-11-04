#pragma once

class NiStream;

class NiPSysBoundUpdateModifier {
public:
    // 0x00c2d6d0
    void LinkObject(::NiStream &);
    // 0x00c2d720
    void SetUpdateSkipCounter(int);
};
