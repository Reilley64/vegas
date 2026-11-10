#pragma once

struct NiStream;

class NiBSplinePoint3Interpolator {
public:
    // 0x00a50910
    void LoadBinary(::NiStream &);
};
