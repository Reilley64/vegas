#pragma once

#include "fnv/package_schedule_fields.h"

class TESCombatStyle;

// The leading data members of CombatController (a TESPackage), for units whose CombatController stand-ins declare no
// fields. The 32-bit getter folded into 0x00980070 reads `pCombatStyle` when called on a combat controller. Comments
// give the 32-bit offsets. Members the decompiled code has not named yet are 32-bit placeholders that keep the
// 32-bit layout; one that holds a pointer moves every later member on x64, so check the layout before relying on the
// members after it.
struct CombatControllerFields
{
    // TESPackage
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
    // CombatController
    void* pGroup;                           // 0x80
    void* pCurrentProcedure;                // 0x84
    void* pQueuedProcedure;                 // 0x88
    void* pProcedureArrayVtable;            // 0x8C
    void* pProcedureArrayBuffer;            // 0x90
    unsigned int uiProcedureArraySize;      // 0x94
    unsigned int uiProcedureArrayCapacity;  // 0x98
    void* pCombatState;                     // 0x9C
    unsigned int uiUnknownA0[7];            // 0xA0
    void* pActor;                           // 0xBC
    void* pTarget;                          // 0xC0
    unsigned int uiUnknownC4[12];           // 0xC4
    TESCombatStyle* pCombatStyle;           // 0xF4
};
