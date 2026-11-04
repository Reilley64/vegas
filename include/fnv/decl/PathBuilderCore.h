#pragma once

struct DoorEntryList;
struct PathLoc;
struct PathLocArray;

struct PathBuilderCore {
public:
    // 0x006cac90
    int ProcessPathNode(int, ::PathLocArray *, ::DoorEntryList *);
    // 0x006cb050
    int FUN_006cb050(::PathLoc *, ::PathLocArray *, int, ::DoorEntryList *);
};
