// src/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationvarctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterdeclinationvarctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c2b8b0
#include <new>
#include "fnv/decl/FUN_00c32d80.h"
#include "fnv/decl/NiPSysAirFieldAirFrictionCtlr.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_010bf000.h"
#include "fnv/symbols_01202000.h"
void* __cdecl FUN_00c2b8b0()
{
    return &(*reinterpret_cast<void * *>(&::g_01202750));
}

struct NiPSysModifierFloatCtlr
{
    char _pad[0x24];
    float fTarget;
};

struct NiPSysEmitterDeclinationVarCtlr : NiPSysModifierFloatCtlr
{
    char _pad2[0x14];
    NiPSysModifierFloatCtlr* m_pFloatCtlr;
    void FUN_00c2a0b0(float fValue);
};

// @fnv 0x00c2a0b0
void NiPSysEmitterDeclinationVarCtlr::FUN_00c2a0b0(float fValue)
{
    m_pFloatCtlr->fTarget = fValue;
}

namespace fnv_00c2b8c0 {
struct NiPSysModifierFloatCtlr
{
    char _pad[0x3c];
};
struct NiPSysEmitterDeclinationVarCtlr : NiPSysModifierFloatCtlr
{
    void FUN_00c2b8c0(float& fValue);
};

// @fnv 0x00c2b8c0
void NiPSysEmitterDeclinationVarCtlr::FUN_00c2b8c0(float& fValue)
{
    NiPSysModifierFloatCtlr* p = *(NiPSysModifierFloatCtlr**)((char*)this + 0x3c);
    fValue = *(float*)((char*)p + 0x24);
}
}  // namespace fnv_00c2b8c0

struct StrArr
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    inline unsigned int Add(char*& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
        return uiIndex;
    }
};

// @fnv 0x00c2b920
void FUN_00c2b920(StrArr* pStringArray)
{
    FUN_00c32f60(pStringArray);
    char* s = ::FUN_00a7d330((char*)(*reinterpret_cast<void * *>(&::g_01202750)));
    pStringArray->Add(s);
}


void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

};

struct FUN_00c2b8d0_cls
{

    SpawnedObject* FUN_00c2b8d0(void* arg);
};

// @fnv 0x00c2b8d0
SpawnedObject* FUN_00c2b8d0_cls::FUN_00c2b8d0(void* arg)
{
    SpawnedObject* obj = (SpawnedObject*)FUN_00aa13e0(0x40);
    if (obj != 0)
    {
        new ((void *)(obj)) ::FUN_00c32d80();
        obj->m_vtbl = &DAT_010bfb54;
    }
    else
    {
        obj = 0;
    }
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>((this))->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(obj), (*(::CloningProcess *)(arg)));
    return obj;
}
