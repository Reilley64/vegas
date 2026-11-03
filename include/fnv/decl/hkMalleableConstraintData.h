#pragma once

struct hkMalleableContactNormal;

struct hkMalleableConstraintData {
public:
    // 0x00cdea30
    void SetContactNormal(int, ::hkMalleableContactNormal *);
    // 0x00cdea70
    void FUN_00cdea70(::hkMalleableContactNormal *);
    // 0x00cdea90
    void FUN_00cdea90(::hkMalleableContactNormal *);
    // 0x00cdeab0
    void FUN_00cdeab0(::hkMalleableContactNormal *);
};
