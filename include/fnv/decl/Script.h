#pragma once

class TESObjectREFR;

class Script {
public:
    // 0x005533c0
    void GetLocalData();
    // 0x005a40d0
    static bool GetActorSexConditionFunction(::TESObjectREFR *, void *, void *, double &);
    // 0x005aa0f0
    Script();
    // 0x005aa2a0
    void ClearData();
    // 0x005ac740
    static bool IsConsolePlatform();
    // 0x005acc70
    static void CopyIdentifierBitsToValue(const unsigned int &, double &);
    // 0x00671d10
    char *GetData();
};
