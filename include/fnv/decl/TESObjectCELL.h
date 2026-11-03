#pragma once

class BGSEncounterZone;
class NiAVObject;
class TESRegionList;
class TESWorldSpace;
struct RefX;

class TESObjectCELL {
public:
    // 0x00425fd0
    bool IsCellInterior() const;
    // 0x004503f0
    int GetCellStandValue();
    // 0x00456fc0
    ::NiAVObject *GetCellChildAt(int);
    // 0x00541ac0
    void CellRefLockEnter();
    // 0x00541b00
    void ClearData();
    // 0x00542d20
    unsigned char FUN_00542d20();
    // 0x00543c30
    unsigned char GetField24();
    // 0x00544c30
    int GetCellGridX();
    // 0x00544c60
    int GetCellGridY();
    // 0x005454d0
    void *FUN_005454d0();
    // 0x00546c20
    ::BGSEncounterZone *FindEncounterZone() const;
    // 0x00547110
    ::TESRegionList *GetRegionList(bool);
    // 0x005497a0
    ::NiAVObject *GetDynamicNode();
    // 0x0054ddd0
    ::TESWorldSpace *GetParentWorldSpace();
    // 0x005508b0
    void RemoveNonPersistentRefs();
    // 0x00551180
    ::RefX *FUN_00551180(::RefX *);
    // 0x00551620
    bool HasCellExtraData();
    // 0x00552bb0
    unsigned char FUN_00552bb0();
    // 0x005571a0
    void FUN_005571a0(bool);
    // 0x00557470
    void ClearCellReferenceList();
    // 0x00947d10
    void ClearAudioMarkers();
};
