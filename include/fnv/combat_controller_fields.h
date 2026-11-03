#pragma once

#include "fnv/package_fields.h"

class TESCombatStyle;

// The leading data members of CombatController (a TESPackage), for units whose CombatController stand-ins declare no
// fields. The 4-byte getters folded into 0x00980070, 0x005e3fc0 (+0xA4), 0x0097ae90 (GetFieldBC, +0xBC) and
// 0x00586150 (+0x9C) read `pCombatStyle`, `pUnknownA4`, `pActor` and `pCombatState` when called on a combat
// controller. Comments give the 32-bit offsets. Members the decompiled code has not named yet are 32-bit placeholders
// that keep the 32-bit layout; one that holds a pointer moves every later member on x64, so check the layout before
// relying on the members after it.
struct CombatControllerFields : PackageFields
{
    void* pGroup;                           // 0x80
    void* pCurrentProcedure;                // 0x84
    void* pQueuedProcedure;                 // 0x88
    void* pProcedureArrayVtable;            // 0x8C
    void* pProcedureArrayBuffer;            // 0x90
    unsigned int uiProcedureArraySize;      // 0x94
    unsigned int uiProcedureArrayCapacity;  // 0x98
    void* pCombatState;                     // 0x9C
    unsigned int uiUnknownA0;               // 0xA0
    void* pUnknownA4;                       // 0xA4
    unsigned int uiUnknownA8[5];            // 0xA8
    void* pActor;                           // 0xBC
    void* pTarget;                          // 0xC0
    unsigned int uiUnknownC4[12];           // 0xC4
    TESCombatStyle* pCombatStyle;           // 0xF4
};
