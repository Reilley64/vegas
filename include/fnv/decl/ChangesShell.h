#pragma once

struct BoundShell;
struct ExtraNodeShell;
struct ExtraShell;

struct ChangesShell {
public:
    // 0x004c1520
    void AddItemExtraData(::BoundShell *, int, int, ::ExtraShell *, ::ExtraNodeShell **);
};
