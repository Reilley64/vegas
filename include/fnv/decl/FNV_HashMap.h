#pragma once
#include <cstdint>

struct FNV_MapKey;

struct FNV_HashMap {
public:
    // 0x00658950
    void InsertOrUpdate(intptr_t, ::FNV_MapKey);
};
