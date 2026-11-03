#pragma once

struct ActorObj;
struct ItemObj;

struct ItemList {
public:
    // 0x0098bc00
    ::ItemObj *FindBestItem(::ActorObj *, unsigned char, ::ItemObj *);
};
