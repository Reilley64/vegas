#pragma once
#include <cstdint>

struct Input;
struct Item;
struct Queue;
struct Tree;
struct Workers;

struct Manager {
public:
    // 0x00b6da10
    void FUN_00b6da10(::Item *);
    // 0x00ca2ad0
    bool FUN_00ca2ad0(void *, uintptr_t);
    // 0x00d0a810
    void FUN_00d0a810(::Tree **, ::Input *, ::Queue *, ::Workers *);
};
