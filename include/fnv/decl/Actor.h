#pragma once

class TESActorBase;
class TESObjectREFR;
enum ACTOR_LIFE_STATE;
enum SEX;
enum SIT_SLEEP_STATE;

class Actor {
public:
    // 0x004181e0
    ::TESActorBase *GetActorBase();
    // 0x004997b0
    bool IsSneaking();
    // 0x0087f4c0
    ::SEX GetSex();
    // 0x00884c60
    void FUN_00884c60();
    // 0x008a1800
    void SetActorLifeState(::ACTOR_LIFE_STATE);
    // 0x008a3b30
    bool IsMoving();
    // 0x008b0190
    bool IsVisible(int);
    // 0x008c00e0
    void FUN_008c00e0(::TESObjectREFR *, int, int);
    // 0x008c2e50
    void AddDefaultSpells();
    // 0x008c3c40
    void ConfigureActorState(bool, bool);
    // 0x008c4640
    void UpdateActorPresentation();
    // 0x00920fb0
    void SetCurrentSitSleepState(::SIT_SLEEP_STATE);
    // 0x0095e6f0
    void FUN_0095e6f0(int);
};
