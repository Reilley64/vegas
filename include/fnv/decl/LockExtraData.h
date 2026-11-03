#pragma once

class TESObjectREFR;

class LockExtraData {
public:
    // 0x004309e0
    int GetLockLevel(::TESObjectREFR *);
    // 0x00430a10
    int GetLevel(::TESObjectREFR *);
    // 0x00430a90
    void SetLocked(bool);
    // 0x00430ae0
    bool MeetsMinimumLockLevel();
    // 0x00430b40
    static int ConvertLockLevel(int);
    // 0x005021a0
    bool IsLocked();
};
