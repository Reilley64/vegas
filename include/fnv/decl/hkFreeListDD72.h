#pragma once

class hkBoolDD72;
struct hkBlockDD72;

class hkFreeListDD72 {
public:
    // 0x00dd72f0
    void WalkFreeBlocks(::hkBlockDD72 *, void (*)(void *, int, hkBoolDD72, int, void *), int, void *);
};
