#pragma once

struct StringArray;

struct Object {
public:
    // 0x0044d240
    bool InsertOrReplaceNode(int, int, int *, bool);
    // 0x008cfad0
    void FUN_008cfad0(float, int, int, int, int, unsigned char);
    // 0x00a415f0
    ::Object *FUN_00a415f0();
    // 0x00c9d6b0
    void FUN_00c9d6b0(::StringArray *);
    // 0x00e03160
    void FUN_00e03160();
};
