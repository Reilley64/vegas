#pragma once

#include "fnv/package_schedule_fields.h"

class TESCombatStyle;

// The data members of TESPackage, for units whose package stand-ins declare no fields. Comments give the 32-bit
// offsets. The 4-byte getters folded into 0x0055b980 (BGSMessageInitAccess::GetIconFormID) and 0x00671d10
// (Script::GetData) read `pLocation` and `pPackageTarget` when called on a package. Members the decompiled code has
// not named yet are 32-bit placeholders that keep the 32-bit layout; one that holds a pointer moves every later
// member on x64, so check the layout before relying on the members after it.
struct PackageFields
{
    void* vtable;                           // 0x00
    unsigned char ucFormType;               // 0x04
    unsigned int uiFormFlags;               // 0x08
    unsigned int uiFormID;                  // 0x0C
    void* pModListItem;                     // 0x10
    void* pModListNext;                     // 0x14
    unsigned int uiProcedureArrayIndex;     // 0x18
    unsigned int uiPackageFlags;            // 0x1C
    unsigned char ucPackageType;            // 0x20
    unsigned short usBehaviorFlags;         // 0x22
    unsigned short usSpecificFlags;         // 0x24
    void* pPackageData;                     // 0x28
    void* pLocation;                        // 0x2C
    void* pPackageTarget;                   // 0x30
    void* pIdleCollection;                  // 0x34
    PackageScheduleFields kSchedule;        // 0x38
    unsigned int uiUnknown40[2];            // 0x40
    TESCombatStyle* pPackageCombatStyle;    // 0x48
    unsigned int uiUnknown4C[13];           // 0x4C
};

// The data members of PackageTarget (TESPackage::pPackageTarget), for units whose target stand-ins declare no fields.
// `iValue` is the count or the radius, depending on the target type; the 4-byte getter folded into 0x0044ddc0 reads
// it when called on a package target.
struct PackageTargetFields
{
    unsigned char ucTargetType;
    void* pTarget;
    int iValue;
};
