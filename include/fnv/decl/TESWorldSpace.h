#pragma once

class BGSTerrainManager;
class TESFile;
class TESObjectCELL;
class TESObjectREFR;

class TESWorldSpace {
public:
    // 0x00473ff0
    static bool IsFormIDOwnedByFile(unsigned int, ::TESFile *);
    // 0x00584150
    void FUN_00584150(float);
    // 0x00584bc0
    void SetFieldD0(unsigned int);
    // 0x00586130
    void FUN_00586130(float);
    // 0x00586170
    ::BGSTerrainManager *GetWorldTerrainManager();
    // 0x005861b0
    bool GetSmallWorld();
    // 0x005862e0
    bool IsFlag4C20Set();
    // 0x005863d0
    void SetParent(::TESWorldSpace *);
    // 0x005875a0
    ::TESObjectCELL *GetCellAtGridPosition(int, int);
    // 0x00587630
    ::TESObjectCELL *GetCellByKey(unsigned int);
    // 0x00587ff0
    void AddPersistentReference(::TESObjectREFR *);
};
