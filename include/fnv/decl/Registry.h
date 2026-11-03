#pragma once

class Obj;
struct Item;

class Registry {
public:
    // 0x00a2e570
    ::Item *FindItemByBindingId(int, bool);
    // 0x00dca820
    void RegisterObject(::Obj *volatile);
};
