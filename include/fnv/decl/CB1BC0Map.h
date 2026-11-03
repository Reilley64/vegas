#pragma once

struct CB1BC0Allocator;

struct CB1BC0Map {
public:
    // 0x00cb1bc0
    int InsertKeyValue(::CB1BC0Allocator &, unsigned long long, unsigned long long);
    // 0x00cb2030
    void ResizeToFit(::CB1BC0Allocator &, int);
};
