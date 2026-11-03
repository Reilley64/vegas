#pragma once
#include "havok/hkUlong.h"

struct Display;
struct Input;
struct LineDrawer;

struct Viewer {
public:
    // 0x00de7020
    void FUN_00de7020(::Input *, ::LineDrawer *, hkUlong, int);
    // 0x00de7a70
    void FUN_00de7a70(::Input *, ::Display *, hkUlong, int);
};
