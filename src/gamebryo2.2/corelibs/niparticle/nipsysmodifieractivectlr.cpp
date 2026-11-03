// gamebryo2.2/corelibs/niparticle/nipsysmodifieractivectlr.cpp: NiPSysAirFieldAirFrictionCtlr, StandIn, NiPSysModifierActiveCtlr (13 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/CtlrStandin.h"
#include "fnv/decl/FUN_00a52f00.h"
#include "fnv/decl/FUN_00a57630.h"
#include "fnv/decl/NiStream.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c1b0f0__FUN_00c1b0f0_cls.h"
#include "fnv/decl/fnv_00c31530__NiPSysModifierCtlrRuntime.h"
#include "fnv/decl/fnv_00c32d30__NiPSysModifierBoolCtlr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01202000.h"
#include "nipsysmodifieractivectlr_decls.h"

// @fnv 0x00c32de0
void NiPSysAirFieldAirFrictionCtlr::CopyMemberData(NiPSysAirFieldAirFrictionCtlr* destination, CloningProcess& cloning)
{
    NiPSysModifierCtlr::CopyMemberData(destination, cloning);
}

extern int DAT_010c0d2c;

// @fnv 0x00c32b60
void* FUN_00c32b60(void* pThis)
{
    reinterpret_cast<::CtlrStandin *>((pThis))->FUN_00c31260();
    *(int**)pThis = &DAT_010c0d2c;
    return pThis;
}

struct BSFadeNode
{
    static void* __cdecl operator new(size_t);
};

struct Dummy_00a532d0
{
    void* FUN_00a532d0(bool bValue);
};

static void* (Dummy_00a532d0::*const pfn_00a532d0)(bool) = &Dummy_00a532d0::FUN_00a532d0;

void* FUN_00a532d0(void* p, int, bool bValue);

struct Wrap_00a532d0
{
    char pad[0x18];
    static void* __cdecl operator new(size_t s)
    {
        return BSFadeNode::operator new(s);
    }
    Wrap_00a532d0(bool bValue)
    {
        ((void*(*)(void*, bool))FUN_00a532d0)(this, bValue);
    }
};

// Reads a bool via virtual call at offset 0xf0, allocates a 0x18-byte BSFadeNode, and constructs it with that bool, returning null on allocation failure.
// @fnv 0x00c32b80
void* FUN_00c32b80(void* pThis, int, unsigned short usUnused)
{
    bool bValue;
    (*(void(**)(void*, bool*))(*(intptr_t*)pThis + 0xf0))(pThis, &bValue);
    void* p = BSFadeNode::operator new(0x18);
    if (p)
        return ((void*(*)(void*, bool))FUN_00a532d0)(p, bValue);
    return 0;
}

// @fnv 0x00c32bc0
bool FUN_00c32bc0(const void* pThis, int, void* pkInterpolator, unsigned short usIndex)
{
    return (*(bool(**)(void*))(*(intptr_t*)pkInterpolator + 0xa4))(pkInterpolator);
}

struct FUN_00c29d50_shell
{
    void FUN_00c29d50(char* pOut);
};

// @fnv 0x00c29d50
void FUN_00c29d50_shell::FUN_00c29d50(char* pOut)
{
    *pOut = *(char*)(*(intptr_t*)((char*)this + 0x3c) + 0x14);
}

struct GlobalObjectO2_00a7b610;

// @fnv 0x00c29d40
GlobalObjectO2_00a7b610* __cdecl FUN_00c29d40()
{
    return &::g_012026d0;
}


// @fnv 0x00c32be0
const char* __cdecl FUN_00c32be0()
{
    return reinterpret_cast<const char*>(&(*reinterpret_cast<const char *const *>(&::g_012027f0)));
}

struct NiObjectNET;
struct NiPSysModifier;
struct BaseStandIn
{
};
struct PsStandIn
{
};
struct StandIn
{
    bool FUN_00c29dd0(NiObjectNET*);
};
// @fnv 0x00c29dd0
bool StandIn::FUN_00c29dd0(NiObjectNET* pkTarget)
{
    NiPSysModifier* pkModifier;
    if (!reinterpret_cast<::fnv_00c31530::NiPSysModifierCtlrRuntime *>((((BaseStandIn*)this)))->IsTargetParticleSystem((::fnv_00c31530::NiParticleSystemRuntime *)(pkTarget)))
        return false;
    pkModifier = ((::NiPSysModifier *)(reinterpret_cast<::fnv_00c1b0f0::FUN_00c1b0f0_cls *>((((PsStandIn*)pkTarget)))->FUN_00c1b0f0((unsigned int *)(void *)((void*)((char*)this + 0x38)))));
    return pkModifier;
}

struct GlobalObjectO2_00a7b610;
struct StrArr
{
};
struct NiPSysModifierBoolCtlr
{
};
struct NiPSysModifierActiveCtlr : NiPSysModifierBoolCtlr
{
    void FUN_00c29e00(StrArr*);
};
// @fnv 0x00c29e00
void NiPSysModifierActiveCtlr::FUN_00c29e00(StrArr* pArray)
{
    reinterpret_cast<::fnv_00c32d30::NiPSysModifierBoolCtlr *>(this)->FUN_00c32d30((::fnv_00c32d30::StrArr *)(pArray));
    char* p = (char*)((void *)(::FUN_00a7d330((const char *)(const void *)((const void*)*(void**)(void*)&::g_012026d0))));
    unsigned int uiIndex = *(unsigned short*)((char*)pArray + 0x0a);
    unsigned int n = *(unsigned short*)((char*)pArray + 0x08);
    if (uiIndex >= n)
        reinterpret_cast<::ViewerStrings *>((pArray))->SetSize(*(unsigned short*)((char*)pArray + 0x0e) + uiIndex);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pArray))->SetAt(uiIndex, p);
}

// FUN_00c29d60 (0x00c29d60, 31 bytes)
//
//   mov edx, dword ptr [ecx + 0x3c]      ; target = this->unk3c
//   mov eax, dword ptr [esp + 4]          ; the 4-byte stack argument
//   cmp byte ptr [edx + 0x14], al         ; target->unk14 != (unsigned char)arg
//   je  <ret 4>
//   mov ecx, edx                          ; this of the virtual call
//   mov edx, dword ptr [ecx]              ; vptr
//   mov dword ptr [esp + 4], eax          ; the argument is forwarded in place
//   mov eax, dword ptr [edx + 0x98]       ; vtable slot 0x98 -> 38
//   jmp eax
//   ret 4
//
// The two `this->unk3c` accesses must NOT be routed through a local pointer:
// with a local, cl 2008 coalesces the pointer into the incoming ECX and the
// call needs no `mov ecx, edx` copy (29 bytes).  Spelling both accesses as
// `this->unk3c->...` keeps the two memory descriptors distinct, so the
// pointer is materialised in EDX and copied into ECX for the virtual call.

struct FNV_C29D60_VtableBase
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
};

// The object held in this->unk3c: a byte flag at +0x14 and a virtual at
// vtable offset 0x98 (slot 38, i.e. right after the 38 base slots).
struct FNV_C29D60_Target : FNV_C29D60_VtableBase
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned char unk14;
    virtual void FUN_00c29e00(unsigned int nValue);
};

// The owner of the function: the target pointer sits at +0x3c.
struct FNV_C29D60_Owner
{
    int unk00;
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
    FNV_C29D60_Target* unk3c;
    void FUN_00c29d60(unsigned int nValue);
};

// @fnv 0x00c29d60
void FNV_C29D60_Owner::FUN_00c29d60(unsigned int nValue)
{
    if (this->unk3c->unk14 != (unsigned char)nValue)
    {
        this->unk3c->FUN_00c29e00(nValue);
    }
}

class C29D80Base
{
  public:
    C29D80Base() throw();
    virtual ~C29D80Base();

    static void* operator new(size_t uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

class C29D80Object : public C29D80Base
{
  public:
    C29D80Object() throw()
    {}
    virtual ~C29D80Object();

    C29D80Object* FUN_00c29d80(void* pvCloning);
};

// @fnv 0x00c29d80
C29D80Object* C29D80Object::FUN_00c29d80(void* pvCloning)
{
    C29D80Object* pkClone = new C29D80Object;
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>(this)->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(pkClone), (*(::CloningProcess *)(pvCloning)));
    return pkClone;
}

extern "C" void __cdecl jmp_0xc32bf0();

// @fnv 0x00c29d30
void FUN_00c29d30()
{
    jmp_0xc32bf0();
}

#include <windows.h>
void* __cdecl FUN_00aa13e0(unsigned int size);

struct RefCountedStandIn
{
    virtual void Unk0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};

struct NewStandIn
{
};

struct ArgStandIn
{
    char unk00[0xd8];
    unsigned int m_d8;
};

class FUN_00c32bf0_cls
{
  public:
    void FUN_00c32bf0(ArgStandIn* arg);

    char unk00[0x34];
    RefCountedStandIn* m_34;
};

// Calls FUN_00a57630, allocates an object using the returned pointer, and replaces m_34 while updating reference counts.
// @fnv 0x00c32bf0
void FUN_00c32bf0_cls::FUN_00c32bf0(ArgStandIn* arg)
{
    reinterpret_cast<struct ::FUN_00a57630 *>(this)->LinkObject((*(::NiStream *)(arg)));
    if (arg->m_d8 >= 0xa010068)
    {
        return;
    }
    void* pSource = ((void *)(reinterpret_cast<::NiStream *>((arg))->GetLoadedObject()));
    void* n = FUN_00aa13e0(0x20);
    RefCountedStandIn* pNew;
    if (n != 0)
    {
        pNew = ((::RefCountedStandIn *)(new ((void *)(((NewStandIn*)n))) ::FUN_00a52f00((::NiBoolData *)(pSource))));
    }
    else
    {
        pNew = 0;
    }
    RefCountedStandIn* pOld = m_34;
    if (pOld != pNew)
    {
        if (pOld != 0)
        {
            if (InterlockedDecrement((LONG*)&pOld->m_uiRefCount) == 0)
            {
                pOld->DeleteThis();
            }
        }
        m_34 = pNew;
        if (pNew != 0)
        {
            InterlockedIncrement((LONG*)&pNew->m_uiRefCount);
        }
    }
}
