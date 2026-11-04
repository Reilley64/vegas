#pragma once

struct Callback;
struct TESWorldSpace;

struct Container {
public:
    // 0x0099a360
    bool FUN_0099a360(int, ::TESWorldSpace *);
    // 0x00d33600
    void FUN_00d33600(void *, void *, char *, struct ::Callback *);
    // 0x00d56800
    void FUN_00d56800();
};
