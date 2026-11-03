
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00ddccb0_cls.h"
#include "fnv/decl/FUN_00ddf170_cls.h"
#include "fnv/decl/S_00dd9380.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d62000.h"
#include "fnv/symbols_01269000.h"
extern int DAT_010d16f0;
extern int DAT_010d1700;
extern int DAT_010d1720;
extern void __cdecl FUN_00ddcc60();

struct FUN_00d62fe0_cls
{
    void FUN_00d62fe0();
};

// @fnv 0x00d62fe0
void FUN_00d62fe0_cls::FUN_00d62fe0()
{
    *(int*)this = (int)&DAT_010d1720;
    *(int*)((char*)this + 8) = (int)&DAT_010d1700;
    *(int*)((char*)this + 0x20) = (int)&DAT_010d16f0;
    FUN_00ddcc60();
}

extern int DAT_01268fc0;
extern int DAT_01268fc4;

struct FUN_00d63210_class
{
    int GetValueByFlag();
};

// @fnv 0x00d63210
int FUN_00d63210_class::GetValueByFlag()
{
    if (*(char*)((char*)this + 0x20))
        return DAT_01268fc0;
    return DAT_01268fc4;
}

typedef void(__cdecl* SnapshotFn)();

struct ProfileRegistry
{
};

extern int DAT_01268fc4;
extern int DAT_01268fc0;


// Registers the two world-snapshot commands with the profile registry, storing their returned handles in DAT_01268fc4 and DAT_01268fc0.
// @fnv 0x00d63000
void __cdecl RegisterSnapshotCommands()
{
    DAT_01268fc4 = reinterpret_cast<::S_00dd9380 *>(((*reinterpret_cast<::ProfileRegistry * *>(&::DAT_01269cd0))))->FUN_00dd9380("* Grab World Snapshot Native", (int)(((void (&)())::FUN_00d62f20)));
    DAT_01268fc0 = reinterpret_cast<::S_00dd9380 *>(((*reinterpret_cast<::ProfileRegistry * *>(&::DAT_01269cd0))))->FUN_00dd9380("* Grab World Snapshot PC", (int)(((void (&)())::AllocateRecordWithData)));
}

struct FUN_00c7be20_cls;

struct FUN_00c7be20_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct FUN_00c7be20_src
{
    int unk00;
    int unk04;
    int* m_08;
    int m_0c;
};

struct FUN_00c7be20_arr
{
    int* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};

void* __cdecl FUN_00c85750() throw();

struct FUN_00c7be20_cls
{
    int unk00;
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
    int unk40;
    int unk44;
    FUN_00c7be20_src* m_48;

    void CopySourceArray(FUN_00c7be20_arr* out);
};

// Grows the output array to hold m_48's element count, sets its size, then copies the elements from m_48->m_08 into it.
// @fnv 0x00c7be20
void FUN_00c7be20_cls::CopySourceArray(FUN_00c7be20_arr* out)
{
    FUN_00c7be20_src* pSource = m_48;
    if (pSource != 0)
    {
        int iCount = pSource->m_0c;
        FUN_00c7be20_holder* pAllocHolder = reinterpret_cast<FUN_00c7be20_holder*>(FUN_00c85750());
        void* allocator = pAllocHolder->m_pAllocator;
        unsigned int uiCapacity = out->m_capFlags & 0x3fffffffu;
        if ((int)uiCapacity < iCount)
        {
            int newCap = (int)(uiCapacity + uiCapacity);
            if (iCount >= newCap)
            {
                newCap = iCount;
            }
            ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(out), (unsigned int)newCap, 4);
        }
        *(volatile int*)&out->m_uiItemCount = iCount;
        int iRemaining = m_48->m_0c;
        int* pSrcData = m_48->m_08;
        int* pDstData = *(int* volatile*)&out->m_data;
        if (iRemaining > 0)
        {
            int iByteDelta = (int)pSrcData - (int)pDstData;
            do
            {
                *pDstData = *(int*)((char*)pDstData + iByteDelta);
                ++pDstData;
            } while (--iRemaining != 0);
        }
    }
}

struct SubObj
{
    virtual void vfunc0();
    virtual void vfunc1(void* item);
};

struct Container
{
    char pad[0x6c];
    void** m_data;
    int m_iElementCount;
};

struct FUN_00d62fa0_class
{
    char pad[0x18];
    SubObj m_subObj;
    Container* m_container;

    void ProcessContainerItems();
};

// @fnv 0x00d62fa0
void FUN_00d62fa0_class::ProcessContainerItems()
{
    if (m_container)
    {
        for (int iIndex = 0; iIndex < m_container->m_iElementCount; iIndex++)
        {
            m_subObj.vfunc1(m_container->m_data[iIndex]);
        }
    }
}

namespace fnv_00d63250 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d63250_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;


    FUN_00d63250_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00d62fe0, then if acFlags bit 0 is set frees this via the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00d63250
FUN_00d63250_cls* FUN_00d63250_cls::Destroy(unsigned char acFlags)
{
    reinterpret_cast<::FUN_00d62fe0_cls *>(this)->FUN_00d62fe0();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d63250

extern int DAT_010d1794;
extern int DAT_010d1774;
extern int DAT_010d1764;

struct SubObject
{
};

struct FUN_00d63280_cls
{
    void* m_vtbl0;
    int unk04;
    void* m_vtbl8;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_vtbl20;
    int unk24;
    SubObject m_sub28;

    FUN_00d63280_cls* FUN_00d63280(int a, int b);
};

// @fnv 0x00d63280
FUN_00d63280_cls* FUN_00d63280_cls::FUN_00d63280(int a, int b)
{
    new ((void *)this) ::FUN_00ddccb0_cls((*(const ::BDDCCB0Array< ::BDDCCB0ProcessContext *> *)(b)));
    m_vtbl0 = (void*)&DAT_010d1794;
    m_vtbl8 = (void*)&DAT_010d1774;
    m_vtbl20 = (void*)&DAT_010d1764;
    reinterpret_cast<::FUN_00ddf170_cls *>(&(m_sub28))->FUN_00ddf170(a, 0x7a120);
    return this;
}

// Adjustor thunk for virtual FUN_00d63230 (sub ecx,8; jmp to the Derived implementation).
struct PrimaryBase
{
    virtual void FUN_00d63230();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d63230();
};

struct ThunkOwner : PrimaryBase, SecondaryBase
{
    ThunkOwner();
// @fnv 0x00d63230
    virtual void FUN_00d63230();
};

ThunkOwner::ThunkOwner()
{}

struct D63240Primary
{
    virtual void vfunc00();
    virtual void FUN_00d63240();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct D63240Secondary
{
    virtual void FUN_00d63240();
};

struct D63240Object : D63240Primary, D63240Secondary
{
    D63240Object();

// @fnv 0x00d63240
    virtual void FUN_00d63240();
};

D63240Object::D63240Object()
{}

#include "generated/data/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.inc"
