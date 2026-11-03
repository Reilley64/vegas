#pragma once
#include <cstdint>

class TESBoundObject;

struct Inv4c6a10 {
public:
    // 0x004c6a10
    ::TESBoundObject *FindInventoryItemByType(intptr_t, int *);
};
