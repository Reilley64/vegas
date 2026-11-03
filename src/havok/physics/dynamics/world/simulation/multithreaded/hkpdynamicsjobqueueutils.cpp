
// src/havok/physics/dynamics/world/simulation/multithreaded/hkpdynamicsjobqueueutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/hkpdynamicsjobqueueutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"





struct S_00d96530_RelArray
{
    int m_offset;
    int m_iElementCount;
    int m_pRayCursor;
    S_00d96530_RelArray(void* data, int capacity)
    {
        m_offset = (char*)data - (char*)this;
        m_iElementCount = 0;
        m_pRayCursor = capacity;
    }
};

struct S_00d96530_Block
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d96530_RelArray m_ppData;
    // The inline storage follows the 0x20-byte block header.
    static const int kHeaderBytes = 0x20;
    S_00d96530_Block(int capacity) : m_ppData((char*)this + kHeaderBytes, capacity)
    {}
};

struct S_00d96530_Header
{
    int m_iBlockCount;
    int m_maxBlocks;
    int m_iDofCount;
    S_00d96530_Block* m_kBlocks[1];
};

// @fnv 0x00d96530
S_00d96530_Header* AllocateBlockHeader(int numBlocks, int numElems)
{
    S_00d96530_Header* pHeader =
        static_cast<S_00d96530_Header*>(hkMemoryRouter::getInstance().heap().blockAlloc((short)numBlocks * 4 + 0xc));
    int iBlockBytes = numElems << 4;
    pHeader->m_maxBlocks = numBlocks;
    pHeader->m_iBlockCount = numBlocks;
    pHeader->m_iDofCount = iBlockBytes + 0x20;
    S_00d96530_Block** blocks = pHeader->m_kBlocks;
    for (int i = 0; i < numBlocks; i++)
    {
        void* p = hkMemoryRouter::getInstance().heap().blockAlloc(iBlockBytes + 0x20);
        blocks[i] = static_cast<S_00d96530_Block*>(p);
        new (p) S_00d96530_Block(iBlockBytes);
    }
    return pHeader;
}

inline void S_Call(void* a, int b)
{
    hkMemoryRouter::getInstance().heap().blockFree(a, b);
}
struct S_Item;
struct S_C
{
    int count;
    int unk04;
    int unk08;
    S_Item* arr[8];
    void FUN_00d965b0();
};
// Frees each of the count blocks in arr (unk08 bytes each), then this block (count*4+0xc bytes), to the heap allocator.
// @fnv 0x00d965b0
void S_C::FUN_00d965b0()
{
    S_Item* const* p = arr;
    for (int i = 0; i < count; i++)
        S_Call(p[i], unk08);
    S_Call(this, (short)count * 4 + 0xc);
}
