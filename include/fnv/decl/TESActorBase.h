#pragma once

class BGSLoadFormBuffer;
class TESObjectREFR;
enum SEX;

class TESActorBase {
public:
    // 0x0048cee0
    ::SEX GetSex();
    // 0x005f0cc0
    ::SEX GetSex() const;
    // 0x005f1590
    bool ShouldUseDefaultAppearance(::TESObjectREFR *);
    // 0x005f1fd0
    void LoadGame(::BGSLoadFormBuffer *);
    // 0x005f20a0
    void FUN_005f20a0(bool);
};
