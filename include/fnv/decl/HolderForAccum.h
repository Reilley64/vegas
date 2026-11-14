#pragma once

class NiAccumulator;
class NiCamera;

struct HolderForAccum {
public:
    // 0x00ba3cb0
    void SetAccumulatorAt(unsigned int, ::NiAccumulator *, const ::NiCamera *);
};
