#pragma once
#include "havok/hkUlong.h"

struct Draw;
struct Input;
struct TimeInterval;

struct Simulation {
public:
    // 0x00cf8da0
    int FUN_00cf8da0(const ::TimeInterval *);
    // 0x00de7730
    void FUN_00de7730(::Input *, ::Draw *, hkUlong, int);
};
