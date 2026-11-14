#pragma once

struct NiPoint3;

struct NiPick {
public:
    // 0x00705fc0
    void FUN_00705fc0(void *);
    // 0x00e98e20
    bool PerformPick(const ::NiPoint3 &, const ::NiPoint3 &, bool);
    // 0x00e98fa0
    ~NiPick();
};
