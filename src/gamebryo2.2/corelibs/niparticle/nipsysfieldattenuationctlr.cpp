
// src/gamebryo2.2/corelibs/niparticle/nipsysfieldattenuationctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysfieldattenuationctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c2b230
#include "fnv/decl/NiPSysAirFieldAirFrictionCtlr.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c1b0f0__FUN_00c1b0f0_cls.h"
#include "fnv/decl/fnv_00c31530__NiPSysModifierCtlrRuntime.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_01202000.h"
void* __cdecl FUN_00c2b230()
{
    return &(*reinterpret_cast<void * *>(&::g_01202720));
}

struct NiObjectNET;
struct BaseStandIn
{
};
struct B00c1bff0
{
};
struct NiObjectNET : B00c1bff0
{
};
struct NiPSysModifier
{
    virtual void* _v0();
    virtual void* _v1();
    virtual void* GetRTTI();
};
struct NiPSysFieldAttenuationCtlr : BaseStandIn
{
    bool FUN_00c2b290(NiObjectNET*);
};
// Calls the base check on pkTarget, resolves a NiPSysModifier from this+0x38, and returns true if its RTTI chain contains g_01202688_arg1.
// @fnv 0x00c2b290
bool NiPSysFieldAttenuationCtlr::FUN_00c2b290(NiObjectNET* pkTarget)
{
    if (!reinterpret_cast<::fnv_00c31530::NiPSysModifierCtlrRuntime *>(this)->IsTargetParticleSystem((::fnv_00c31530::NiParticleSystemRuntime *)(pkTarget)))
        return false;
    NiPSysModifier* pkModifier = (NiPSysModifier*)reinterpret_cast<::fnv_00c1b0f0::FUN_00c1b0f0_cls *>((pkTarget))->FUN_00c1b0f0((unsigned int *)(void *)((void*)((char*)this + 0x38)));
    if (!pkModifier)
        return false;
    for (void* p = pkModifier->GetRTTI(); p; p = *(void**)((char*)p + 4))
    {
        if (p == (void*)&(*reinterpret_cast<const char *const *>(&::g_012027e0)))
            return true;
    }
    return false;
}

// Candidate for CreateFieldAttenuationController (0x00c2b240, 75 bytes, /MT /O2 /GS /EHsc /Gy)
// factory: allocates 0x40 bytes, runs the base ctor (0xc32d80),
// installs the NiPSysFieldAttenuationCtlr vtable, then hands the object to
// this->FUN_00c32de0 along with the caller's NiObjectNET*. Returns the new
// object, or null (passing null through) when allocation fails.

// The game's operator new (0xaa13e0), declared under a stand-in name: the
// shared symbol map binds the global ??2@YAPAXI@Z to a placeholder address.
void* NiMemAlloc(unsigned int uiSize);
inline void* operator new(size_t, void* pvWhere)
{
    return pvWhere;
}

// Stand-in for the base whose ctor lives at 0xc32d80.
struct FieldCtlrBase
{
    FieldCtlrBase();
};

// Stand-in carrying the vtable the original installs (DAT_010bf554).
// fnvcheck derives the vtable address from the original image bytes.
struct AttenCtlr
{
    virtual void* _v0()
    {
        return 0;
    }
    virtual void* _v1()
    {
        return 0;
    }
    virtual void* _v2()
    {
        return 0;
    }
    unsigned char _pad[0x40 - 4];
};

struct Owner
{
    NiPSysFieldAttenuationCtlr* CreateFieldAttenuationController(NiObjectNET* pArg);
};

// Allocates and constructs an AttenCtlr, passes it with pArg to FUN_00c32de0, and returns it as a NiPSysFieldAttenuationCtlr.
// @fnv 0x00c2b240
NiPSysFieldAttenuationCtlr* Owner::CreateFieldAttenuationController(NiObjectNET* pArg)
{
    AttenCtlr* pCtlr = (AttenCtlr*)NiMemAlloc(sizeof(AttenCtlr));
    if (pCtlr)
    {
        new (pCtlr) FieldCtlrBase;
        new (pCtlr) AttenCtlr;
    }
    else
    {
        pCtlr = 0;
    }
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>((this))->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(pCtlr), (*(::CloningProcess *)(pArg)));
    return (NiPSysFieldAttenuationCtlr*)pCtlr;
}

struct StrArr
{
    void* unk00;
    char** data;
    unsigned short capacity;
    unsigned short index;
    unsigned short count;
    unsigned short growBy;
};
// Appends the string returned by FUN_00a7d330(g_01202720) to the array, growing it if the index reaches capacity.
// @fnv 0x00c2b2e0
void FUN_00c2b2e0(StrArr* array)
{
    FUN_00c32f60(array);
    char* value = ::FUN_00a7d330(static_cast<char*>((*reinterpret_cast<void * *>(&::g_01202720))));
    unsigned int index = array->index;
    unsigned int capacity = array->capacity;
    if (index >= capacity)
        reinterpret_cast<::ViewerStrings *>((array))->SetSize(index + array->growBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(index, value);
}
