#pragma once

#include <climits>
#include <cstddef>

// Fixed-width record staging used by the retained endian converter.
struct S_00462230 {
    unsigned int unk00;
    unsigned int unk04;
    // 0x00462230
    void FUN_00462230();
};

static_assert(CHAR_BIT == 8);
static_assert(sizeof(unsigned int) == 4);
static_assert(offsetof(S_00462230, unk00) == 0);
static_assert(offsetof(S_00462230, unk04) == 4);
static_assert(sizeof(S_00462230) == 8);
