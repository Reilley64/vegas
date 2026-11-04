#pragma once
#include "havok/hkUlong.h"

struct hkDebugDisplayHandler;
struct hkpConstraintInstance;

struct ConstraintVisualizer {
public:
    // 0x00de6550
    void FUN_00de6550(::hkpConstraintInstance *, ::hkDebugDisplayHandler *, hkUlong, int);
};
