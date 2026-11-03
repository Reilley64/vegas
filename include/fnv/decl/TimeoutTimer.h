#pragma once

class BGSLoadFormBuffer;

class TimeoutTimer {
public:
    // 0x006b9130
    float FUN_006b9130();
    // 0x008d7f80
    bool CheckTimer();
    // 0x00910b10
    void FUN_00910b10();
    // 0x009a44e0
    TimeoutTimer(void *, float, float, float, float);
    // 0x009a5f20
    void LoadGame(::BGSLoadFormBuffer *);
};
