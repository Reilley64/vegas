#pragma once
#include <cstdint>

struct Tile050;

struct Owner050 {
public:
    // 0x00754690
    ::Tile050 *AddListEntry(int, const char *, intptr_t, const char *);
};
