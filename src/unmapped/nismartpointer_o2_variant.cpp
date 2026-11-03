
// src/unmapped/nismartpointer_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/unmapped/nismartpointer.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00a311e0_s.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00e80000.h"
#include "fnv/symbols_011f6000.h"
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
