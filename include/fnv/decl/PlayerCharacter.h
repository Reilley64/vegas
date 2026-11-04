#pragma once

class Animation;
class BGSNote;
struct Biped;

class PlayerCharacter {
public:
    // 0x007d1340
    int FUN_007d1340();
    // 0x0093a5f0
    void SetUnderAIControl(bool);
    // 0x0094df60
    bool IsSleepingOrResting();
    // 0x00950290
    void UpdateCameraMode();
    // 0x00950a60
    ::Animation *GetAnimation(bool) const;
    // 0x00950b00
    ::Biped *FUN_00950b00(bool);
    // 0x00966c10
    bool HasNote(::BGSNote *);
};
