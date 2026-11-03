#pragma once

struct FNV_MapKey;

struct FNV_HashMap {
public:
    // 0x00658950
    void InsertOrUpdate(int, ::FNV_MapKey);
};
