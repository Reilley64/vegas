#pragma once
#include "havok/hkClass.h"

// Actual class-descriptor constructor. The original fourth argument is unused;
// all pointer-bearing fields remain native pointers, not unsigned integers.
struct FUN_00d472a0 : hkClass
{
    // 0x00d472a0
    FUN_00d472a0(char*, hkClass*, int, const void*, int,
        hkClassEnum*, int, hkClassMember*, int, void*, hkCustomAttributes*,
        unsigned int, int);
};
