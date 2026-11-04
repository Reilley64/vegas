// src/havok/physics/collide/broadphase/hkpbroadphase.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/hkpbroadphase.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <windows.h>
#include "fnv/decl/FUN_00cf6d20_Class.h"
#include "fnv/decl/FUN_00cf6da0_cls.h"
#include "fnv/decl/hkMultiThreadCheckCF6E.h"
#include "fnv/symbols_0102e000.h"
extern char DAT_010d3f7c[];

struct SpawnedObject
{
    unsigned int m_i00;
    unsigned short m_w04;
};

struct InitObject
{
    void* m_pGlobal;
    unsigned short unk04;
    unsigned short m_w06;
    SpawnedObject m_sub;
    unsigned int m_i10;
    InitObject* FUN_00d97010();
};

// @fnv 0x00d97010
InitObject* InitObject::FUN_00d97010()
{
    m_w06 = 1;
    m_pGlobal = DAT_010d3f7c;
    SpawnedObject* pSubObject = &m_sub;
    pSubObject->m_i00 = 0xfffffff1u;
    pSubObject->m_w04 = 0x8000;
    m_i10 = 0;
    reinterpret_cast<::FUN_00cf6d20_Class *>((pSubObject))->FUN_00cf6d20();
    return this;
}


// The broad phase's views below share its 32-bit layout: vtable, memory size and reference count, thread check
// (+0x08) and critical section (+0x10).
struct FUN_00d97060_cls
{
    const void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_threadCheck[2];  // +0x08, hkMultiThreadCheck
    CRITICAL_SECTION* m_pSection;

    void FUN_00d97060();
};

// @fnv 0x00d97060
void FUN_00d97060_cls::FUN_00d97060()
{
    LeaveCriticalSection(m_pSection);
}

// FUN_00d97070: thiscall, one stack parameter, /MT /O2 /GS /EHsc /Gy

struct SubObj
{
    unsigned int unk00;
    unsigned int unk04;
};

class Spawned
{
  public:
    virtual void v00();
};




class Owner
{
  public:
    const void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    SubObj m_08;
    Spawned* m_10;
    void FUN_00d97070(int spinCount);
};

// @fnv 0x00d97070
void Owner::FUN_00d97070(int apArg)
{
    if (m_10 == 0)
    {
        Spawned* s = static_cast<Spawned*>(hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(CRITICAL_SECTION)));
        m_10 = (s != 0) ? ((::Spawned *)(reinterpret_cast<::FUN_00cf6da0_cls *>((s))->FUN_00cf6da0((unsigned long)(apArg)))) : s;
        reinterpret_cast<::hkMultiThreadCheckCF6E *>(&(m_08))->ResetThreadCheck();
    }
}

namespace fnv_00d97100 {
struct CpuObject
{
    const void* m_vtable;
    unsigned short size;
    void FUN_00d970c0();
    CpuObject* FUN_00d97100(unsigned int flags);
};
// Calls FUN_00d970c0, then if bit 0 of flags is set, frees this (size bytes) to the heap allocator, and returns this.
// @fnv 0x00d97100
CpuObject* CpuObject::FUN_00d97100(unsigned int flags)
{
    FUN_00d970c0();
    if (flags & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00d97100


struct FUN_00d97050_cls
{
    const void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_threadCheck[2];  // +0x08, hkMultiThreadCheck
    CRITICAL_SECTION* m_pSection;

    void FUN_00d97050();
};

// @fnv 0x00d97050
void FUN_00d97050_cls::FUN_00d97050()
{
    EnterCriticalSection(m_pSection);
}


struct FUN_00d970c0_cls
{
    const void* m_vptr;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_threadCheck[2];  // +0x08, hkMultiThreadCheck
    CRITICAL_SECTION* m_pCs;

    void FUN_00d970c0();
};


// Deletes the critical section m_pCs, frees it via the holder's allocator, clears m_pCs, and sets the vtable pointer to DAT_0102e388.
// @fnv 0x00d970c0
void FUN_00d970c0_cls::FUN_00d970c0()
{
    m_vptr = &DAT_010d3f7c;
    CRITICAL_SECTION* pCs = m_pCs;
    if (pCs != 0)
    {
        DeleteCriticalSection(pCs);
        hkMemoryRouter::getInstance().heap().blockFree(pCs, sizeof(CRITICAL_SECTION));
        m_pCs = 0;
    }
    m_vptr = &::DAT_0102e388;
}
