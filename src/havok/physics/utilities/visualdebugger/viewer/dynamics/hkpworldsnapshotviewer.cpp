
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
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
    DAT_01268fc4 = reinterpret_cast<::S_00dd9380 *>(((*reinterpret_cast<::ProfileRegistry * *>(&::DAT_01269cd0))))->FUN_00dd9380("* Grab World Snapshot Native", reinterpret_cast<intptr_t>(((void (&)())::FUN_00d62f20)));
    DAT_01268fc0 = reinterpret_cast<::S_00dd9380 *>(((*reinterpret_cast<::ProfileRegistry * *>(&::DAT_01269cd0))))->FUN_00dd9380("* Grab World Snapshot PC", reinterpret_cast<intptr_t>(((void (&)())::AllocateRecordWithData)));
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

static inline void* getMemoryRouter() { return ::FUN_00c85750(); }

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
        FUN_00c7be20_holder* pAllocHolder = reinterpret_cast<FUN_00c7be20_holder*>(getMemoryRouter());
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

static inline AudioHolder* getMemoryRouter() { return static_cast<AudioHolder*>(::FUN_00c85750()); }

struct FUN_00d63250_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;


    FUN_00d63250_cls* Destroy(unsigned char acFlags);
};

// Calls FUN_00d62fe0, then if acFlags bit 0 is set frees this via the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00d63250
FUN_00d63250_cls* FUN_00d63250_cls::Destroy(unsigned char acFlags)
{
    reinterpret_cast<::FUN_00d62fe0_cls *>(this)->FUN_00d62fe0();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = getMemoryRouter();
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

// Moved from hkpworldsnapshotviewer_ehsc_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_00d605d0_class.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/FUN_00ddcc60.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/symbols_00d60000.h"
#include "fnv/symbols_010d6000.h"
#include "fnv/symbols_011b7000.h"
void __cdecl RegisterSnapshotCommands();

class hkBool
{
  public:
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct FUN_00c7be20_arr;

inline hkMemoryAllocator& containerHeap()
{
    return ((NineIntegerRecord*)getMemoryRouter())->heap();
}

struct hkCharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkCharArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkCharArray()
    {
        hkMemoryAllocator& alloc = containerHeap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    char* begin()
    {
        return m_data;
    }
    void reserve(int n)
    {
        hkMemoryAllocator& alloc = containerHeap();
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)(void *)(&alloc), (::SpawnedArray *)(::FUN_00c7be20_arr *)((FUN_00c7be20_arr*)this), newSize, 1);
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

struct hkArrayStreamWriter
{
    void* m_vtbl;
    int m_usMemSizeAndFlags;
    hkCharArray* m_aiIndexedValues;
    int m_offset;
    int m_ownership;

    hkArrayStreamWriter(hkCharArray* arr, int ownership);
    ~hkArrayStreamWriter();
};

struct StructureLayoutRules
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};

struct hkpWorld;

hkBool __cdecl FUN_00cc0d60(hkpWorld* world, hkArrayStreamWriter* writer, hkBool binary,
                            const StructureLayoutRules* rules, int aiFlags);

struct hkDisplaySerializeOStream
{
};

struct hkProcessHandler
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void deleteProcess(int tag);
};

struct hkpPhysicsContext
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
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    hkpWorld** m_ppWorlds;
    int m_numWorlds;

    int getNumWorlds() const
    {
        return m_numWorlds;
    }
    hkpWorld* getWorld(int i) const
    {
        return m_ppWorlds[i];
    }
};

struct FUN_00d63040_cls
{
    int unk00;
    int unk04;
    int unk08;
    hkDisplaySerializeOStream* m_pDisplayStream;
    int unk10;
    hkProcessHandler* m_pProcessHandler;
    int unk18;
    hkpPhysicsContext* m_iValueAtOffset0C;
    hkBool m_convertToPC;

    void FUN_00d63040(float frameTimeInMs);
};

// @fnv 0x00d63040
void FUN_00d63040_cls::FUN_00d63040(float frameTimeInMs)
{
    if (m_pDisplayStream)
    {
        hkCharArray storage;
        storage.reserve(100 * 1024);
        hkArrayStreamWriter sw(&storage, 1);

        const StructureLayoutRules& rules = m_convertToPC.m_cBooleanValue ? (*reinterpret_cast<::StructureLayoutRules *>(&::DAT_010d6ae8)) : (*reinterpret_cast<::StructureLayoutRules *>(&::DAT_011b7b88));
        for (int wi = 0; wi < m_iValueAtOffset0C->getNumWorlds(); ++wi)
        {
            storage.SetSizeAndGrow(0);
            FUN_00cc0d60(m_iValueAtOffset0C->getWorld(wi), &sw, true, &rules, 0);
            int length = storage.GetLogicalSize();
            if (length >= 1)
            {
                ::FUN_00d60960((const float *)(m_pDisplayStream));
                reinterpret_cast<::FUN_00d605d0_class *>((m_pDisplayStream))->FUN_00d605d0(0xd0);
                reinterpret_cast<::FUN_00d605d0_class *>((m_pDisplayStream))->FUN_00d605d0(rules.m_ucBytesInPointer);
                reinterpret_cast<::FUN_00d605d0_class *>((m_pDisplayStream))->FUN_00d605d0(rules.m_bLittleEndian);
                reinterpret_cast<::FUN_00d605d0_class *>((m_pDisplayStream))->FUN_00d605d0(rules.m_bReusePaddingOptimization);
                reinterpret_cast<::FUN_00d605d0_class *>((m_pDisplayStream))->FUN_00d605d0(rules.m_bEmptyBaseClassOptimization);
                reinterpret_cast<::hkOArchive_2 *>((m_pDisplayStream))->WriteInt(length);
                reinterpret_cast<::FUN_00d607b0_class *>((m_pDisplayStream))->FUN_00d607b0(reinterpret_cast<intptr_t>(storage.begin()));
            }
        }
    }

    if (m_pProcessHandler)
    {
        m_pProcessHandler->deleteProcess(m_convertToPC.m_cBooleanValue ? DAT_01268fc0 : DAT_01268fc4);
    }
}
#include "generated/data/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldsnapshotviewer.inc"
