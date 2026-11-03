// src/havok/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshapeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshapeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"



struct FUN_00dfd380_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pDataD;
    int m_iCountD;
    unsigned int m_uCapD;
    void* m_pDataC;
    int m_iCountC;
    unsigned int m_uCapC;
    void* m_pDataB;
    int m_iCountB;
    unsigned int m_uCapB;
    void* m_pDataA;
    int m_iCountA;
    unsigned int m_uCapA;

    void FUN_00dfd380();
};

// Frees the four data arrays through the audio allocator when their capacity flag is clear, then resets each pointer, count and capacity.
// @fnv 0x00dfd380
void FUN_00dfd380_cls::FUN_00dfd380()
{
    hkMemoryAllocator* pAllocator = &hkMemoryRouter::getInstance().heap();
    unsigned int uCapA = m_uCapA;
    m_iCountA = 0;
    if ((uCapA & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_pDataA, (uCapA & 0x3fffffffu) * 2);
    }
    m_pDataA = 0;
    m_uCapA = 0x80000000u;

    hkMemoryAllocator* pAllocator2 = &hkMemoryRouter::getInstance().heap();
    unsigned int uCapB = m_uCapB;
    m_iCountB = 0;
    if ((uCapB & 0x80000000u) == 0)
    {
        pAllocator2->bufFree(m_pDataB, (uCapB & 0x3fffffffu) * 2);
    }
    m_pDataB = 0;
    m_uCapB = 0x80000000u;

    hkMemoryAllocator* pAllocator3 = &hkMemoryRouter::getInstance().heap();
    unsigned int uCapC = m_uCapC;
    m_iCountC = 0;
    if ((uCapC & 0x80000000u) == 0)
    {
        pAllocator3->bufFree(m_pDataC, (uCapC & 0x3fffffffu) * 2);
    }
    m_pDataC = 0;
    m_uCapC = 0x80000000u;

    hkMemoryAllocator* pAllocator4 = &hkMemoryRouter::getInstance().heap();
    unsigned int uCapD = m_uCapD;
    m_iCountD = 0;
    if ((uCapD & 0x80000000u) == 0)
    {
        pAllocator4->bufFree(m_pDataD, (uCapD & 0x3fffffffu) * 2);
    }
    m_pDataD = 0;
    m_uCapD = 0x80000000u;
}

namespace fnv_00dfd440 {



struct FUN_00dfd440_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pDataC;
    int m_iCountC;
    unsigned int m_uCapC;
    void* m_pDataB;
    int m_iCountB;
    unsigned int m_uCapB;
    void* m_pDataA;
    int m_iCountA;
    unsigned int m_uCapA;

    void FUN_00dfd440();
};

// Frees the three capacity-flagged data arrays through the audio allocator and resets each pointer, count and capacity to empty.
// @fnv 0x00dfd440
void FUN_00dfd440_cls::FUN_00dfd440()
{
    hkMemoryAllocator* pAllocator = &hkMemoryRouter::getInstance().heap();
    unsigned int uCapA = m_uCapA;
    m_iCountA = 0;
    if ((uCapA & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_pDataA, (uCapA & 0x3fffffffu) * 2);
    }
    m_pDataA = 0;
    m_uCapA = 0x80000000u;

    hkMemoryAllocator* pAllocator2 = &hkMemoryRouter::getInstance().heap();
    unsigned int uCapB = m_uCapB;
    m_iCountB = 0;
    if ((uCapB & 0x80000000u) == 0)
    {
        pAllocator2->bufFree(m_pDataB, (uCapB & 0x3fffffffu));
    }
    m_pDataB = 0;
    m_uCapB = 0x80000000u;

    hkMemoryAllocator* pAllocator3 = &hkMemoryRouter::getInstance().heap();
    unsigned int uCapC = m_uCapC;
    m_iCountC = 0;
    if ((uCapC & 0x80000000u) == 0)
    {
        pAllocator3->bufFree(m_pDataC, (uCapC & 0x3fffffffu) * 2);
    }
    m_pDataC = 0;
    m_uCapC = 0x80000000u;
}
}  // namespace fnv_00dfd440
