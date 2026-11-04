#pragma once

class TESForm;

struct SomeClass {
public:
    // 0x0058f210
    void RemapImpactData(::TESForm *);
    // 0x005e4810
    void SetEntryStateByKey(unsigned short, unsigned char);
    // 0x0086bb70
    int FUN_0086bb70(unsigned int);
    // 0x00a93c50
    void *FUN_00a93c50(unsigned int);
    // 0x00e06650
    void Destroy();
};
