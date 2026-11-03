#pragma once

class BGSEncounterZone;
class BSExtraData;
class ExtraRadioData;
class NiNode;
class TESModel;

class TESObjectREFR {
public:
    // 0x00527080
    ::BSExtraData *GetExtraData(unsigned char) const;
    // 0x00546a90
    static ::BGSEncounterZone *FUN_00546a90();
    // 0x00567d20
    ::BGSEncounterZone *FindEncounterZone();
    // 0x00568e50
    ::ExtraRadioData *GetExtraRadioData();
    // 0x005715d0
    const char *GetModelFilePath();
    // 0x00571600
    float GetBoundingRadius();
    // 0x00571630
    ::TESModel *GetTESModel();
    // 0x00573090
    bool IsLimbMissing(int);
    // 0x00598040
    float GetScale();
    // 0x0080fcf0
    void ResetProjectileIdleAnimation();
    // 0x008984c0
    void FUN_008984c0();
    // 0x008d47d0
    void Get3D(::NiNode *, bool);
};
