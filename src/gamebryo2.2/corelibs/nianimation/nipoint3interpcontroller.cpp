
// gamebryo2.2/corelibs/nianimation/nipoint3interpcontroller.cpp: free functions (6 functions)
#include <new>
#include "fnv/decl/FUN_00a3ca10.h"
#include "fnv/decl/Holder00a390a0.h"
#include "fnv/decl/NiObject.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_0109a000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "nipoint3interpcontroller_decls.h"

struct BSFadeNode
{
};
struct NiPoint3
{
    float x, y, z;
};
struct NiPoint3InterpolatorStandIn
{
    NiPoint3InterpolatorStandIn* FUN_00a49650(NiPoint3 v);
};
typedef void(* GetPoint3Fn)(void*, NiPoint3*);

// @fnv 0x00a57c20
void* FUN_00a57c20(void* self, int, unsigned short usIndex)
{
    NiPoint3 kValue;
    (*(GetPoint3Fn**)self)[0xec / 4](self, &kValue);
    void* pMemory = ::operator new(0x20);
    NiPoint3InterpolatorStandIn* pInterpolator = (NiPoint3InterpolatorStandIn*)pMemory;
    if (pInterpolator)
        return pInterpolator->FUN_00a49650(kValue);
    return 0;
}

// @fnv 0x00a57ca0
const char* const* FUN_00a57ca0()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f4238));
}

namespace fnv_00a57cb0 {
class NiRTTI;
struct GlobalObjectO2_00a7b610;
struct NiPoint3
{
    float x, y, z;
};
class NiObject
{
  public:
};
struct NiPoint3InterpolatorStandIn
{
    void FUN_00a494b0(NiPoint3 v);
};
typedef void(* GetPoint3Fn)(void*, NiPoint3*);

// Casts pkInterp to a NiPoint3 interpolator, reads a NiPoint3 from self via a virtual call, and passes it to the interpolator.
// @fnv 0x00a57cb0
void FUN_00a57cb0(void* self, int, NiObject* pkInterp, int)
{
    NiPoint3InterpolatorStandIn* pkPoint3Interp =
        !pkInterp ? 0 : (NiPoint3InterpolatorStandIn*)((::fnv_00a57cb0::NiObject *)(reinterpret_cast<::NiObject *>((void *)(pkInterp))->DynamicCast((const ::NiRTTI *)(const ::fnv_00a57cb0::NiRTTI *)((const NiRTTI*)&(*reinterpret_cast<::fnv_00a57cb0::GlobalObjectO2_00a7b610 *>(&::g_011f3f70))))));
    NiPoint3 kValue;
    (*(GetPoint3Fn**)self)[0xec / 4](self, &kValue);
    pkPoint3Interp->FUN_00a494b0(kValue);
}
}  // namespace fnv_00a57cb0

struct ActorCombatGroup;
template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTArray
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
typedef NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> > CombatGroupArray;

// @fnv 0x00a57d10
void FUN_00a57d10(CombatGroupArray* pCombatGroups)
{
    reinterpret_cast<::Holder00a390a0 *>((pCombatGroups))->FUN_00a390a0({});
    ActorCombatGroup* pGroup = ((::ActorCombatGroup *)(::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f4238)))));
    unsigned int uiIndex = *(unsigned short*)((char*)pCombatGroups + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)pCombatGroups + 8))
        reinterpret_cast<::ViewerStrings *>((pCombatGroups))->SetSize(*(unsigned short*)((char*)pCombatGroups + 0xe) + uiIndex);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pCombatGroups))->SetAt(uiIndex, (char *&)(pGroup));
}


// @fnv 0x00a532c0
unsigned int* __cdecl FUN_00a532c0()
{
    return &(*reinterpret_cast<unsigned int *>(&::g_011f404c));
}

struct S_00a53280_Foo
{
    void* unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
    void* unk10;
    int unk14;

    void* FUN_00a53280(void* arg);
};

extern void(* FUN_00fdf1c0)(void*);

// @fnv 0x00a53280
void* S_00a53280_Foo::FUN_00a53280(void* arg)
{
    new ((void *)this) ::FUN_00a3ca10();

    unk00 = (void*)&DAT_0109a0b4;
    unk0c = DAT_0109a914;
    unk10 = arg;

    if (arg)
    {
        FUN_00fdf1c0((void*)((unsigned char*)arg + 4));
    }

    unk14 = 0;
    return this;
}

#include "generated/data/gamebryo2.2/corelibs/nianimation/nipoint3interpcontroller.inc"
