#pragma once

struct NiPoint3;

struct OrientedBoxBound {
public:
    // 0x00eadf30
    void ComputeFromPoints(unsigned short, const ::NiPoint3 *);
};
