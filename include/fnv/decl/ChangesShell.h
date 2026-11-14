#pragma once
#include <cstdint>

struct BoundShell;
struct ExtraNodeShell;
struct ExtraShell;

struct ChangesShell {
public:
    // 0x004c1520
    void AddItemExtraData(::BoundShell *, int, intptr_t, ::ExtraShell *, ::ExtraNodeShell **);
};
