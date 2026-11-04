#pragma once
#include <cstdint>

struct Entry;
struct Event;

struct Handler {
public:
    // 0x00815480
    bool FUN_00815480(::Event *, intptr_t, bool);
    // 0x00d07030
    void EmitString(int, unsigned int *);
    // 0x00e07ca0
    int FUN_00e07ca0(::Entry *, ::Entry *, ::Entry *, char *);
};
