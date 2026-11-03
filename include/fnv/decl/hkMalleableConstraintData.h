#pragma once

struct hkMalleableContactNormal;

struct hkMalleableConstraintData {
public:
    // 0x00cdea30
    void SetContactNormal(int, ::hkMalleableContactNormal *);
};
