#include "fnv/symbols_00c85000.h"
// src/havok/common/scenedata/material/hkxmaterialshaderclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxmaterialshaderclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    AudioAllocator* m_pAllocator;
};


struct FUN_00e02230
{
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00e02230();
    virtual ~FUN_00e02230();
    static void operator delete(void* apMemory)
    {
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        unsigned int uiSize = ((FUN_00e02230*)apMemory)->m_u04;
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, uiSize);
    }
};

// Initializes m_u04 and m_u06 to zero.
// @fnv 0x00e02230
FUN_00e02230::FUN_00e02230()
{
    m_u04 = 0;
    m_u06 = 0;
}
