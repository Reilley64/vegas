#pragma once

class hkpConvexShape;
struct AlignedTransform;

struct Standin {
public:
    // 0x0051b1d0
    void *DestroyIfFlagged(unsigned int);
    // 0x00d5d7a0
    ::Standin *FUN_00d5d7a0(const ::hkpConvexShape *, const ::AlignedTransform &, int);
};
