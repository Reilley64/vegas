#pragma once
#include <cstdint>

struct Obj;
struct Item;

class Registry {
public:
    // 0x00a2e570
    ::Item *FindItemByBindingId(intptr_t, bool);
    // 0x00dca820
    void RegisterObject(::Obj *volatile);
};
