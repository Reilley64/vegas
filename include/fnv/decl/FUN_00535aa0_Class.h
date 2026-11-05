#pragma once

#include <climits>
#include <cstddef>

// Fixed-width record staging used by the retained endian converter.
struct FUN_00535aa0_Class {
    unsigned short unk00;
    char pad02[0x2];
    unsigned int unk04;
    // 0x00535aa0
    void FUN_00535aa0();
};

static_assert(CHAR_BIT == 8);
static_assert(sizeof(unsigned int) == 4);
static_assert(sizeof(unsigned short) == 2);
static_assert(offsetof(FUN_00535aa0_Class, unk00) == 0);
static_assert(offsetof(FUN_00535aa0_Class, pad02) == 2);
static_assert(offsetof(FUN_00535aa0_Class, unk04) == 4);
static_assert(sizeof(FUN_00535aa0_Class) == 8);
