#pragma once
#include "havok/hkUlong.h"

struct hkDebugDisplayHandler;
class hkpConstraintInstance;

struct ConstraintVisualizer {
public:
    // 0x00de6550
    void FUN_00de6550(::hkpConstraintInstance *, ::hkDebugDisplayHandler *, hkUlong, int);
};
