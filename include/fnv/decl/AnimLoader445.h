#pragma once

class TESModel;
struct Actor445;
struct AnimList;

struct AnimLoader445 {
public:
    // 0x00445a10
    void QueueModelAnimations(::TESModel *, int, int, ::Actor445 *, bool, bool);
    // 0x00447300
    ::AnimList *MakeList(char *, char *, int);
};
