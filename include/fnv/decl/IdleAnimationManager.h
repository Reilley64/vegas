#pragma once

class IdleAnimationDirectoryEntry;
class NiFormArray;
class TESForm;
class TESIdleForm;
class TESObject;
class TESObjectREFR;
enum ANIM_GROUP_WEAPON_ENUM;
template <class> class BSSimpleList;

class IdleAnimationManager {
public:
    // 0x00600170
    ::IdleAnimationDirectoryEntry *ClearIdleData(const char *, ::BSSimpleList<const char *> *, bool);
    // 0x00600690
    ::NiFormArray *GetIdleArray(::TESForm *);
    // 0x00600700
    ::BSSimpleList<const char *> *FindIdleArrayEntry(const char *, ::ANIM_GROUP_WEAPON_ENUM);
    // 0x006007f0
    static void BuildIdlePath(const char *, char *);
    // 0x006008f0
    static ::TESObject *GetCurrentUsedItem();
    // 0x00600930
    static bool GetUsedItemActivate();
    // 0x00600950
    ::TESIdleForm *FindIdleFormForObject(::TESObjectREFR *, ::TESObjectREFR *);
};
