#pragma once

struct NiPoint3;

class NiPosData {
public:
    // 0x004a3760
    static ::NiPoint3 *ComputePositionAtTime(::NiPoint3 *, float, const ::NiPoint3 *);
};
