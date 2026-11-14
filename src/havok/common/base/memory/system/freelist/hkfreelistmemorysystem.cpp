
// src/havok/common/base/memory/system/freelist/hkfreelistmemorysystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/system/freelist/hkfreelistmemorysystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include "fnv/decl/FNVArray.h"
#include "fnv/decl/FUN_00cbbfe0_This.h"
#include "fnv/decl/FUN_00cd06a0_class.h"
#include "fnv/decl/FUN_00d5ffd0_class.h"
#include <new>
#include "fnv/decl/FUN_00cbbfa0_class.h"
#include "fnv/decl/FUN_00cbf1a0_cls.h"
#include "fnv/decl/FUN_00cf6da0_cls.h"
#include "fnv/decl/FUN_00d2c3a0_class.h"
#include "fnv/decl/FUN_00d2c7a0_class.h"
#include "fnv/decl/FUN_00d5e900.h"
#include "fnv/decl/FUN_00d60270_cls.h"
#include "fnv/decl/FUN_00d60500.h"
#include "fnv/decl/HKThreadMemory.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/Target.h"
#include "havok/hkMemoryRouter.h"
#include "fnv/decl/hkObjD5E9.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cbc000.h"
#include "fnv/symbols_00d2c000.h"
#include "fnv/symbols_01094000.h"
#include "fnv/symbols_010ca000.h"
struct FUN_00cd06c0_t
{
    void FUN_00cd06c0(intptr_t v);
};
// @fnv 0x00cd06c0
void FUN_00cd06c0_t::FUN_00cd06c0(intptr_t v)
{
    *(int*)((char*)this + 4) = v;
    *(int*)((char*)this + 0x18) = v;
}


struct FUN_00cd06a0
{
    void* m_p00;
    FUN_00cd06a0(int aiArg);
};

// @fnv 0x00cd06a0
FUN_00cd06a0::FUN_00cd06a0(int aiArg)
{
    m_p00 = &DAT_010cacd0;
    reinterpret_cast<::FUN_00d2c7a0_class *>(this)->FUN_00d2c7a0();
    reinterpret_cast<::FUN_00cbf1a0_cls *>(this)->FUN_00cbf1a0();
}

struct Inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
};
struct Outer
{
    char pad[0x1c];
    Inner inner;
    void FUN_00cd06e0();
};
// @fnv 0x00cd06e0
void Outer::FUN_00cd06e0()
{
    inner.v16();
}

struct FUN_00cd0940_record
{
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void slot05() = 0;
    virtual void slot06() = 0;
    virtual void slot07() = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
};
struct FUN_00cd0940_iface
{
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02(int, int) = 0;
};
struct FUN_00cd0940_shell
{
    void ResetRecordState(int* param, unsigned char mode);
};
// @fnv 0x00cd0940
void FUN_00cd0940_shell::ResetRecordState(int* aiParams, unsigned char mode)
{
    FUN_00cd0940_record* record = (FUN_00cd0940_record*)((unsigned char*)this + aiParams[8] * 0x138 + 0xc6c);
    if ((mode & 2) != 0)
    {
        if (*(int*)((unsigned char*)record + 0x130) != 0)
        {
            int start = aiParams[1];
            int length = aiParams[2] - start;
            if (length != 0)
            {
                ((FUN_00cd0940_iface*)((unsigned char*)this + 0x1c))->slot02(start, length);
                aiParams[1] = 0;
                aiParams[0] = 0;
                aiParams[2] = 0;
            }
        }
        record->slot13();
        aiParams[3] = 0;
        aiParams[6] = 0;
    }
    if ((mode & 1) != 0)
    {
        record->slot13();
        *(volatile int*)((unsigned char*)record + 0x128) = 0;
        *(volatile unsigned char*)((unsigned char*)record + 0x12c) = 0;
        ::FUN_00d2cab0();
    }
}

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiBytes) throw();
};

struct AudioHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    AudioAllocator* m_pAllocator;
};


struct PtrArrayMember
{
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~PtrArrayMember() throw()
    {
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_ppData, (uCapacity & 0x3fffffff) * 4);
        m_ppData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct FUN_00cd0c80
{
    int unk00;
    PtrArrayMember m_kFirst;
    PtrArrayMember m_kSecond;

    ~FUN_00cd0c80() throw();
};

// Destructor stub for a structure holding two PtrArrayMember members; the members' destructors run after this body.
// @fnv 0x00cd0c80
FUN_00cd0c80::~FUN_00cd0c80() throw()
{}

struct SearchObject
{
    int Search(uintptr_t arg0, unsigned int arg1, uintptr_t arg2, unsigned int arg3);
};
// @fnv 0x00cd1e20
int SearchObject::Search(uintptr_t arg0, unsigned int arg1, uintptr_t arg2, unsigned int arg3)
{
    ((::FNVArray*)this)->FUN_00cd1d80((void*)arg0, (int)arg1, 0, (const int*)arg2, (int)arg3);
    return 0;
}

struct SpawnedSub
{
};

struct FUN_00cd06f0_cls
{
    void AccumulateSpawnedSubTotals(int* out);
};

// Iterates 0x20 entries, adding each active entry's Compute() result and value into out[1] and out[0], then sets out[2] to 0.
// @fnv 0x00cd06f0
void FUN_00cd06f0_cls::AccumulateSpawnedSubTotals(int* out)
{
    char* elem = (char*)this + 0xd9c;
    int remaining = 0x20;
    do
    {
        if (*(elem - 4) != 0)
        {
            SpawnedSub* sub = (SpawnedSub*)(elem - 0x130);
            out[1] += reinterpret_cast<::Target *>((sub))->ComputeWeightedSum();
            out[0] += *(int*)elem;
        }
        elem += 0x138;
        remaining--;
    } while (remaining != 0);
    out[2] = remaining;
}

struct CD0730Object
{
    virtual int FUN_00cd0730(const void* info) const;
};

// @fnv 0x00cd0730
int CD0730Object::FUN_00cd0730(const void* info) const
{
    return 1;
}


struct Gap040
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
};
struct Gap038
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
};
struct Gap400
{
    Gap040 g00;
    Gap040 g01;
    Gap040 g02;
    Gap040 g03;
    Gap040 g04;
    Gap040 g05;
    Gap040 g06;
    Gap040 g07;
    Gap040 g08;
    Gap040 g09;
    Gap040 g0a;
    Gap040 g0b;
    Gap040 g0c;
    Gap040 g0d;
    Gap040 g0e;
    Gap040 g0f;
};

struct Pair
{
    int a;
    int b;
};

struct Flags
{
    unsigned int bits;
};

struct Svc
{
    virtual void s0();
    virtual int s1(int a, int b);
};

struct Sub0b0c
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};

struct FUN_00d5e960_t
{
};

struct Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(Sub0b0c* s, const char* g, unsigned int flags);
    Svc* svc;
    Gap400 ga;
    Gap400 gb;
    Gap040 gc00;
    Gap040 gc01;
    Gap040 gc02;
    Gap040 gc03;
    Gap040 gc04;
    Gap040 gc05;
    Gap040 gc06;
    Gap040 gc07;
    Gap040 gc08;
    Gap040 gc09;
    Gap040 gc0a;
    Gap038 gd;
    int f0b00;
    int f0b04;
    int unk0b08;
    Sub0b0c sub0b0c;
    FUN_00d5e960_t cnt0b30;
    Sub0b0c* FUN_00cd0740(const Pair* p, Flags flags);
};

// Stores p->a and p->b into f0b00/f0b04, optionally calls v3 on sub0b0c and svc->s1 then cnt0b30, and returns &sub0b0c.
// @fnv 0x00cd0740
Sub0b0c* Owner::FUN_00cd0740(const Pair* apPair, Flags flags)
{
    f0b00 = apPair->a;
    f0b04 = apPair->b;
    if (flags.bits & 1)
    {
        v3(&sub0b0c, str_01094d90, flags.bits);
    }
    if (flags.bits & 2)
    {
        int b = apPair->b;
        if (b)
        {
            intptr_t r = svc->s1(b, b);
            reinterpret_cast<::hkObjD5E9 *>(&(cnt0b30))->InitStream((char *)(r), {});
        }
    }
    return &sub0b0c;
}

extern "C" uintptr_t DAT_012686cc;

struct Helper
{
};

struct FUN_00cd0c70_cls
{
    int unk00;

    FUN_00cd0c70_cls* FUN_00cd0c70(int aiUnused);
};

struct CD07B0_Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void FreeBytes(void* apMemory, unsigned int auiBytes);
};
struct CD07B0_Obj1c
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void Release();
};
struct CD07B0_Buffer
{
    int unk00;
    char* m_pBegin;
    char* m_pRecordEnd;
    unsigned int Size() const
    {
        return m_pRecordEnd - m_pBegin;
    }
};
struct FUN_00cd07b0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Detach(Sub0b0c* apSub, Flags akFlags);
    CD07B0_Allocator* m_pAllocator;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    CD07B0_Obj1c m_kObj1c;
    Gap400 ga;
    Gap400 gb;
    Gap040 gc00;
    Gap040 gc01;
    Gap040 gc02;
    Gap040 gc03;
    Gap040 gc04;
    Gap040 gc05;
    Gap040 gc06;
    Gap040 gc07;
    Gap040 gc08;
    Gap040 gc09;
    Gap040 gc0a;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    Sub0b0c m_kSub;
    CD07B0_Buffer m_kBuffer;
    int Cleanup(Flags akFlags);
};

// Frees the buffer bytes and detaches the sub-object when the corresponding flag bits are set, then nulls the allocator pointer.
// @fnv 0x00cd07b0
int FUN_00cd07b0_cls::Cleanup(Flags akFlags)
{
    if (akFlags.bits & 2)
    {
        if (m_kBuffer.Size())
        {
            m_pAllocator->FreeBytes(m_kBuffer.m_pBegin, m_kBuffer.Size());
            reinterpret_cast<::hkObjD5E9 *>(&(m_kBuffer))->InitStream((char *)(0), 0);
        }
    }
    if (akFlags.bits & 1)
    {
        Detach(&m_kSub, akFlags);
        m_kObj1c.Release();
    }
    m_pAllocator = 0;
    return 0;
}

#include <windows.h>
struct FUN_00d2c3a0_t
{
};

struct Slot_1c_t
{
    virtual void v0();
    virtual int v1(int n);
};

struct FUN_00cd0830_cls
{
    void AcquireSlot(unsigned int* out, unsigned int a2, unsigned int flags);
};

// When flags bit 0 is set, scans up to 32 entries, marks a zero byte, and writes slot-related values; bit 1 writes additional values.
// @fnv 0x00cd0830
void FUN_00cd0830_cls::AcquireSlot(unsigned int* out, unsigned int a2, unsigned int flags)
{
    char* self = (char*)this;
    int iSlotIndex;
    unsigned int uiZero;

    if (flags & 1)
    {
        EnterCriticalSection((LPCRITICAL_SECTION)(self + 0x336c));
        iSlotIndex = 0;
        char* e = self + 0xd98;
        do
        {
            if (*e == 0)
                goto found;
            ++iSlotIndex;
            e += 0x138;
        } while (iSlotIndex < 0x20);
        goto notfound;
    found:
        *(unsigned char*)(self + 0xd98 + iSlotIndex * 0x138) = 1;
    notfound:
        LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0x336c));

        char* slot = self + iSlotIndex * 0x138 + 0xc6c;
        *(unsigned int*)(slot + 0x128) = a2;
        uintptr_t uiValue = *(unsigned int*)(self + 0xb08);
        reinterpret_cast<::FUN_00d2c3a0_class *>((((FUN_00d2c3a0_t*)slot)))->FUN_00d2c3a0((void *)(uiValue), (void *)(8));

        uiZero = 0;
        out[3] = uiZero;
        out[4] = (uintptr_t)slot;
        out[7] = *(unsigned int*)(self + 0xb08);
        out[5] = *(unsigned int*)(self + 4);
        out[6] = uiZero;
        out[8] = iSlotIndex;
        out[1] = uiZero;
        out[0] = uiZero;
        out[2] = uiZero;
    }
    else
    {
        uiZero = 0;
    }

    if (flags & 2)
    {
        iSlotIndex = out[8];
        unsigned int ebp = *(unsigned int*)(self + 0xb00);
        char* slot = self + iSlotIndex * 0x138 + 0xc6c;
        if (ebp != uiZero)
        {
            int r = ((Slot_1c_t*)(self + 0x1c))->v1(ebp);
            out[1] = r;
            out[0] = r;
            out[2] = r + ebp;
            *(unsigned int*)(slot + 0x130) = ebp;
            *(unsigned int*)(slot + 0x134) = (uintptr_t)out;
        }
        out[3] = (uintptr_t)slot;
        out[6] = (uintptr_t)(self + 0xb30);
    }
}

struct FUN_00cbf1a0_t
{
};

struct FUN_00cd0c50_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    CRITICAL_SECTION m_cs;

    FUN_00cd0c50_cls* Destroy(int a1);
};

// @fnv 0x00cd0c50
FUN_00cd0c50_cls* FUN_00cd0c50_cls::Destroy(int a1)
{
    DeleteCriticalSection(&this->m_cs);
    reinterpret_cast<::FUN_00cbf1a0_cls *>((reinterpret_cast<FUN_00cbf1a0_t*>(this)))->FUN_00cbf1a0();
    return this;
}

namespace fnv_00cd0b30 {
extern "C" char str_010cade0;
extern "C" char str_010cadb4;

struct AudioHolderStub
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* m_pAllocator;
};


struct Target_cc01
{
};

struct VSlotObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual int vSlot50();
};

struct CtorLocal
{
    int unk10;
    void** m_ppA;
    unsigned int m_nCallbackId;
    unsigned int m_cA;
    int* m_pB;
    unsigned int m_nB;
    unsigned int m_cB;
    unsigned int unk2c;
    int unk30;
    void FUN_00cd0c80();
};

struct FUN_00cd0b30_cls
{
    void FUN_00cd0b30(intptr_t a1);
};

// Calls FUN_00cc01c0 twice, collects slot pointers and values, passes the local to FUN_00cbc220, then calls its FUN_00cd0c80 method.
// @fnv 0x00cd0b30
void FUN_00cd0b30_cls::FUN_00cd0b30(intptr_t apTarget)
{
    char* self = (char*)this;
    reinterpret_cast<::SinkOwner *>((((Target_cc01*)apTarget)))->FUN_00cc01c0(&str_010cade0);
    reinterpret_cast<::SinkOwner *>((((Target_cc01*)apTarget)))->FUN_00cc01c0(&str_010cadb4);

    CtorLocal localData;
    localData.m_cA = 0x80000000u;
    localData.m_cB = 0x80000000u;
    VSlotObj* obj = (VSlotObj*)(self + 0x1c);
    localData.unk10 = 0;
    localData.m_ppA = 0;
    localData.m_nCallbackId = 0;
    localData.m_pB = 0;
    localData.m_nB = 0;
    localData.unk2c = 0;
    localData.unk30 = 0;
    localData.unk30 = obj->vSlot50();
    localData.unk10 = *(int*)(self + 0xb08);

    char* p = self + 0xda0;
    for (unsigned int i = 0x20; i != 0; --i)
    {
        if (*(p - 8) != 0)
        {
            AudioHolderStub* holder = static_cast<AudioHolderStub*>(::FUN_00c85750());
            if (localData.m_nCallbackId == (localData.m_cA & 0x3fffffffu))
            {
                ::ResizeAudioStream((::AudioAllocator *)(holder->m_pAllocator), (::AudioStream *)(void *)(&localData.m_ppA), 4);
            }
            localData.m_ppA[localData.m_nCallbackId] = (void*)(p - 0x134);
            localData.m_nCallbackId++;

            holder = static_cast<AudioHolderStub*>(::FUN_00c85750());
            if (localData.m_nB == (localData.m_cB & 0x3fffffffu))
            {
                ::ResizeAudioStream((::AudioAllocator *)(holder->m_pAllocator), (::AudioStream *)(void *)(&localData.m_pB), 4);
            }
            localData.m_pB[localData.m_nB] = *(int*)p;
            localData.m_nB++;
        }
        p += 0x138;
    }

    ::FUN_00cbc220((::hkOstream *)(this), (::MemSystemInfo *)(apTarget));
    reinterpret_cast<::FUN_00cd0c80 *>(&(localData))->FUN_00cd0c80::~FUN_00cd0c80();
}
}
extern int DAT_010cad74;
extern int DAT_010cad0c;


struct Base_cd09d0
{
    void* m_vptr;
    int unk04;
    void* m_08;
    int unk0c, unk10, unk14, unk18;
    ~Base_cd09d0()
    {
        m_08 = &DAT_010cad0c;
        reinterpret_cast<::FUN_00cbbfe0_This *>((this))->FUN_00cbbfe0();
    }
};
struct Mem1c_cd09d0
{
    int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    int unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    int unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c;
    int unk0140, unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c;
    int unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c;
    int unk0180, unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c;
    int unk01a0, unk01a4, unk01a8, unk01ac, unk01b0, unk01b4, unk01b8, unk01bc;
    int unk01c0, unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc;
    int unk01e0, unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc;
    int unk0200, unk0204, unk0208, unk020c, unk0210, unk0214, unk0218, unk021c;
    int unk0220, unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c;
    int unk0240, unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c;
    int unk0260, unk0264, unk0268, unk026c, unk0270, unk0274, unk0278, unk027c;
    int unk0280, unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c;
    int unk02a0, unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc;
    int unk02c0, unk02c4, unk02c8, unk02cc, unk02d0, unk02d4, unk02d8, unk02dc;
    int unk02e0, unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc;
    int unk0300, unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c;
    int unk0320, unk0324, unk0328, unk032c, unk0330, unk0334, unk0338, unk033c;
    int unk0340, unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c;
    int unk0360, unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c;
    int unk0380, unk0384, unk0388, unk038c, unk0390, unk0394, unk0398, unk039c;
    int unk03a0, unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc;
    int unk03c0, unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc;
    int unk03e0, unk03e4, unk03e8, unk03ec, unk03f0, unk03f4, unk03f8, unk03fc;
    int unk0400, unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c;
    int unk0420, unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c;
    int unk0440, unk0444, unk0448, unk044c, unk0450, unk0454, unk0458, unk045c;
    int unk0460, unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c;
    int unk0480, unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c;
    int unk04a0, unk04a4, unk04a8, unk04ac, unk04b0, unk04b4, unk04b8, unk04bc;
    int unk04c0, unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc;
    int unk04e0, unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc;
    int unk0500, unk0504, unk0508, unk050c, unk0510, unk0514, unk0518, unk051c;
    int unk0520, unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c;
    int unk0540, unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c;
    int unk0560, unk0564, unk0568, unk056c, unk0570, unk0574, unk0578, unk057c;
    int unk0580, unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c;
    int unk05a0, unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc;
    int unk05c0, unk05c4, unk05c8, unk05cc, unk05d0, unk05d4, unk05d8, unk05dc;
    int unk05e0, unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc;
    int unk0600, unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c;
    int unk0620, unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c;
    int unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c;
    int unk0660, unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c;
    int unk0680, unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c;
    int unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc;
    int unk06c0, unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc;
    int unk06e0, unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc;
    int unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c;
    int unk0720, unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c;
    int unk0740, unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c;
    int unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c;
    int unk0780, unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c;
    int unk07a0, unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc;
    int unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc;
    int unk07e0, unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc;
    int unk0800, unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c;
    int unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c;
    int unk0840, unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c;
    int unk0860, unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c;
    int unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c;
    int unk08a0, unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc;
    int unk08c0, unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc;
    int unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc;
    int unk0900, unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c;
    int unk0920, unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c;
    int unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c;
    int unk0960, unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c;
    int unk0980, unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c;
    int unk09a0, unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc;
    int unk09c0, unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc;
    int unk09e0, unk09e4, unk09e8, unk09ec, unk09f0, unk09f4, unk09f8, unk09fc;
    int unk0a00, unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c;
    int unk0a20, unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c;
    int unk0a40, unk0a44, unk0a48, unk0a4c, unk0a50, unk0a54, unk0a58, unk0a5c;
    int unk0a60, unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c;
    int unk0a80, unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98;
    ~Mem1c_cd09d0()
    {
        reinterpret_cast<::FUN_00d5ffd0_class *>((this))->FUN_00d5ffd0();
    }
};
struct MemAB8_cd09d0
{
    int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014;
    CRITICAL_SECTION m_kLock;
    int unk0030, unk0034, unk0038, unk003c, unk0040, unk0044, unk0048, unk004c;
    int unk0050, unk0054, unk0058, unk005c, unk0060, unk0064, unk0068, unk006c;
    int unk0070, unk0074;
    ~MemAB8_cd09d0()
    {
        DeleteCriticalSection(&m_kLock);
        reinterpret_cast<::FUN_00cbf1a0_cls *>((this))->FUN_00cbf1a0();
    }
};
struct MemB30_cd09d0
{
    int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    int unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    int unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138;
    ~MemB30_cd09d0()
    {
        reinterpret_cast<::FUN_00cd06a0_class *>((this))->ResetVftableAndDeleteCriticalSection();
    }
};
struct Block_cd09d0
{
    void* m_vptr;
    int unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c, unk0020;
    int unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c, unk0040;
    int unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c, unk0060;
    int unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c, unk0080;
    int unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c, unk00a0;
    int unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc, unk00c0;
    int unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc, unk00e0;
    int unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc, unk0100;
    int unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c, unk0120;
    int unk0124, unk0128, unk012c, unk0130, unk0134;
    ~Block_cd09d0()
    {
        m_vptr = &DAT_010cacd0;
        reinterpret_cast<::FUN_00d2c7a0_class *>((this))->FUN_00d2c7a0();
        reinterpret_cast<::FUN_00cbf1a0_cls *>((this))->FUN_00cbf1a0();
    }
};
class Pool_cd09d0 : public Base_cd09d0
{
  public:
    Mem1c_cd09d0 m_k1c;
    MemAB8_cd09d0 m_kAB8;
    MemB30_cd09d0 m_kB30;
    Block_cd09d0 m_akBlocks[32];
    CRITICAL_SECTION m_kLock;
    ~Pool_cd09d0();
};

// @fnv 0x00cd09d0
Pool_cd09d0::~Pool_cd09d0()
{
    m_vptr = (void*)&DAT_010cad74;
    *(volatile uintptr_t*)&DAT_012686cc = 0;
    DeleteCriticalSection(&m_kLock);
}



// @fnv 0x00cd0c70
FUN_00cd0c70_cls* FUN_00cd0c70_cls::FUN_00cd0c70(int aiUnused)
{
    reinterpret_cast<::Pool_cd09d0 *>((((Helper*)this)))->Pool_cd09d0::~Pool_cd09d0();
    return this;
}

#include "generated/data/havok/common/base/memory/system/freelist/hkfreelistmemorysystem.inc"
