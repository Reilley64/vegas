#pragma once
#include <cstdint>

struct FUN_008c5000_item;

struct FUN_008c5000_shell {
public:
    // 0x008c4fe0
    int IsNonZero(intptr_t);
    // 0x008c5000
    ::FUN_008c5000_item *FUN_008c5000(int);
};
