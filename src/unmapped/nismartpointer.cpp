
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include "fnv/decl/fnv_0044b010__FUN_0044b010_shell.h"
#include "fnv/decl/fnv_0044b050__FUN_0044b050_shell.h"
#include "fnv/decl/fnv_0044b0f0__FUN_0044b0f0_shell.h"
#include "fnv/decl/fnv_0044b180__FUN_0044b180_shell.h"
#include "fnv/symbols_01272000.h"
#include "fnv/tls.h"
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
    tls = g_tlsBlock.memoryContext;
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
