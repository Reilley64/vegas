#pragma once

struct TESClimate;
enum Sky__SKY_MODE;

struct Sky {
public:
    // 0x0046dd00
    static ::Sky *GetInstance();
    // 0x0059e950
    bool IsRaining();
    // 0x0063a3f0
    void SetMode(::Sky__SKY_MODE);
    // 0x0063c8f0
    void SetCurrentClimate(::TESClimate *, bool);
    // 0x011ccb78
    static ::Sky *pInstance;
};
