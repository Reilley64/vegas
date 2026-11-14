#pragma once
#include <cstdint>

struct S00e24650_Edge;
struct S00e24650_Vtx;

struct EdgeWalker {
public:
    // 0x00e23df0
    ::S00e24650_Edge FUN_00e23df0(::S00e24650_Edge, uintptr_t);
    // 0x00e24650
    ::S00e24650_Edge FUN_00e24650(::S00e24650_Edge, uintptr_t, ::S00e24650_Vtx *);
};
