#pragma once

struct D625A0Allocator;

struct D625A0CharArray {
public:
    // 0x00d625a0
    void ReplaceRange(::D625A0Allocator &, int, int, const char *, int);
};
