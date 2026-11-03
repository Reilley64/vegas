#pragma once
#include <cstdint>

struct TileX;

struct ListOwner {
public:
    // 0x007242f0
    bool ContainsKey(void *);
    // 0x007e0e70
    ::TileX *FUN_007e0e70(intptr_t, const char *, void *, const char *);
};
