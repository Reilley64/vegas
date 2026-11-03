
// src/havok/physics/collide/query/collector/raycollector/hkpclosestrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpclosestrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0059c000.h"
struct HKPCloseStrayHitCollector
{
    void* Destroy(unsigned int flags);
};
// Calls FUN_0059cf00 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0059cf20
void* HKPCloseStrayHitCollector::Destroy(unsigned int flags)
{
    ::FUN_0059cf00((void **)(void *)(this));
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Moved from hkpclosestrayhitcollector_o2_nood_variant.cpp (VEGAS-15).
#include "fnv/symbols_00cf0000.h"

#include <xmmintrin.h>

struct HKPCloseNode
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    HKPCloseNode* m_0c;
};

struct FUN_00ca9440_src
{
    __m128 m_00;
    float m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
};

struct FUN_00ca9440_cls
{
    unsigned int unk00;
    float m_04;
    __m128 m_10;
    float m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    HKPCloseNode* m_60;

    void FUN_00ca9440(HKPCloseNode* node, FUN_00ca9440_src* src);
};

// @fnv 0x00ca9440
void FUN_00ca9440_cls::FUN_00ca9440(HKPCloseNode* node, FUN_00ca9440_src* src)
{
    if (src->m_10 < m_20)
    {
        m_10 = src->m_00;
        m_20 = src->m_10;
        m_24 = src->m_14;
        m_28 = src->m_18;
        m_2c = src->m_1c;
        ::CollectValuesReversed((int *)(void *)(&m_30), 8, (::LinkedEntry *)(node));
        HKPCloseNode* last = node;
        while (last->m_0c)
            last = last->m_0c;
        m_60 = last;
        m_04 = src->m_10;
    }
}
