#pragma once
#include <cstdint>

struct LodCell;
struct LodPoint;

struct LodGrid {
public:
    // 0x00458be0
    intptr_t FUN_00458be0(::LodCell *, ::LodPoint *);
};
