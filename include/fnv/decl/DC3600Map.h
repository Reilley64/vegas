#pragma once

struct DC3600Allocator;
struct DC3600Key;

struct DC3600Map {
public:
    // 0x00dc3600
    int InsertKeyValue(::DC3600Allocator &, ::DC3600Key, int);
};
