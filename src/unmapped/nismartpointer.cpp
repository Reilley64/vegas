
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include "fnv/decl/fnv_0044b010__FUN_0044b010_shell.h"
#include "fnv/decl/fnv_0044b050__FUN_0044b050_shell.h"
#include "fnv/decl/fnv_0044b0f0__FUN_0044b0f0_shell.h"
#include "fnv/decl/fnv_0044b180__FUN_0044b180_shell.h"
#include "fnv/symbols_01272000.h"
#include <new>
#include "fnv/decl/FUN_00a311e0_s.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00e80000.h"
#include "fnv/symbols_011f6000.h"
struct KFModel
{
    unsigned int m_uiObjectRefCount;
};

struct NiPointer_KFModel
{
    KFModel* m_pObject;
    NiPointer_KFModel& FUN_0044b070(KFModel* pObject);
};

// @fnv 0x0044b070
NiPointer_KFModel& NiPointer_KFModel::FUN_0044b070(KFModel* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            reinterpret_cast<::fnv_0044b050::FUN_0044b050_shell *>((m_pObject))->FUN_0044b050();
        m_pObject = pObject;
        if (m_pObject)
            reinterpret_cast<::fnv_0044b010::FUN_0044b010_shell *>((m_pObject))->FUN_0044b010();
    }
    return *this;
}

struct LoadedFile
{
    int BackgroundTask;
};
struct NiPointer_LoadedFile
{
    LoadedFile* m_pObject;
    NiPointer_LoadedFile& FUN_0044b220(LoadedFile* pObject);
};
// @fnv 0x0044b220
NiPointer_LoadedFile& NiPointer_LoadedFile::FUN_0044b220(LoadedFile* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            reinterpret_cast<::fnv_0044b180::FUN_0044b180_shell *>((m_pObject))->FUN_0044b180();
        m_pObject = pObject;
        if (m_pObject)
            reinterpret_cast<::fnv_0044b0f0::FUN_0044b0f0_shell *>((m_pObject))->FUN_0044b0f0();
    }
    return *this;
}


struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};


struct RefObj
{
    int unk00;
    int unk04;
    long m_08;
};

struct RefPtr
{
    RefObj* m_pObject;
};

struct BSBase
{
    virtual void vfn_base();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    BSBase(int a1);
};

struct FUN_00c3c590 : BSBase
{
    virtual void vfn_0();
    virtual void vfn_4();
    int m_18;
    RefPtr m_1c;
    int m_20;
    int m_24;
    FUN_00c3c590(int a1);
};

// @fnv 0x00c3c590
FUN_00c3c590::FUN_00c3c590(int a1) : BSBase(a1)
{
    RefPtr* p;
    RefObj* kObj;
    int tls;
    p = &m_1c;
    p->m_pObject = 0;
    if (p->m_pObject != 0)
    {
        kObj = p->m_pObject;
        InterlockedIncrement(&kObj->m_08);
    }
    m_20 = 0;
    m_24 = 0;
    tls = g_tlsBlock.m_2b4;
    m_18 = tls;
}

struct Elem
{
    char data[0x68];
};

struct Heap
{
};

struct Block
{
    Elem* m_items;
    unsigned int m_uiItemCount;
    Block* m_next;

    Block(unsigned int count)
    {
        m_uiItemCount = count;
        m_next = 0;
        if (count > 0)
            m_items = ((::Elem *)(::FUN_00e80390(count)));
        else
            m_items = 0;
    }
    Elem* GetAt(unsigned int i)
    {
        return i >= m_uiItemCount ? 0 : &m_items[i];
    }
};

struct ElemPtrArray
{
    Elem** m_data;
    unsigned int m_pRayCursor;
    unsigned int m_iElementCount;
    Block* m_kBlocks;

    void Add(Elem* e)
    {
        if (m_iElementCount == m_pRayCursor)
            reinterpret_cast<::FUN_00a311e0_s *>(this)->FUN_00a311e0(m_pRayCursor > 0 ? m_pRayCursor * 2 : 1);
        m_data[m_iElementCount] = e;
        ++m_iElementCount;
    }
    void FUN_00e80420(unsigned int count);
};

// @fnv 0x00e80420
void ElemPtrArray::FUN_00e80420(unsigned int count)
{
    void* mem = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::Heap *>(&::g_memoryManager))))->FUN_00aa3e40(sizeof(Block));
    Block* blk = mem ? new (mem) Block(count) : 0;
    for (unsigned int i = 0; i < count; ++i)
        Add(blk->GetAt(i));
    blk->m_next = m_kBlocks;
    m_kBlocks = blk;
}
