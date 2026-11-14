#pragma once
#include <cstdint>

class hkpShape;
class hkTransform;

struct cf5990_TransformShape {
public:
    // 0x00cf5990
    intptr_t FUN_00cf5990(::hkpShape *, const ::hkTransform &);
};
