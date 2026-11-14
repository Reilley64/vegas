// src/bsshader/lighting30shaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/lighting30shaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include <new>
#include "fnv/decl/FUN_00a5c200.h"
#include "fnv/symbols_00a75000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_0109d000.h"
#include "fnv/symbols_011f4000.h"
struct GlobalObjectO2_00a7b610
{
    GlobalObjectO2_00a7b610();
};

// Returns the address of the global object g_011f4a5c.
// @fnv 0x00a756c0
GlobalObjectO2_00a7b610* __cdecl FUN_00a756c0()
{
    return &::g_011f4a5c;
}

struct BSFadeNode
{
};

void* FUN_00a75650(void*);

// @fnv 0x00a756d0
void* __cdecl FUN_00a756d0()
{
    void* p = ::operator new(0x4c);
    if (p)
        return FUN_00a75650(p);
    return 0;
}


extern long DAT_011aa070;


struct ObjectWithFloats
{
    void* m_vptr;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    long m_18;
    volatile float m_1c;
    volatile float m_20;
    volatile float m_24;
    volatile float m_28;
    volatile float m_2c;
    volatile float m_30;
    volatile int m_34;
    float m_38;
    float m_3c;
    float m_40;
    int m_44;
    int m_48;
};

// @fnv 0x00a75650
void* FUN_00a75650(void* self)
{
    ObjectWithFloats* p = (ObjectWithFloats*)self;
    new ((void *)(self)) struct ::FUN_00a5c200();
    p->m_vptr = (void*)&DAT_0109d6c4;
    p->m_1c = 0.0f;
    p->m_20 = 0.0f;
    p->m_24 = 0.0f;
    p->m_28 = 0.0f;
    p->m_2c = 0.0f;
    p->m_30 = 0.0f;
    p->m_24 = 0.0f;
    p->m_34 = 0;
    p->m_20 = 0.0f;
    p->m_1c = 0.0f;
    p->m_30 = 0.0f;
    p->m_2c = 0.0f;
    p->m_28 = 0.0f;
    p->m_38 = ::DAT_0101e570;
    p->m_3c = 1.0f;
    p->m_40 = 1.0f;
    p->m_18 = InterlockedIncrement(&DAT_011aa070);
    p->m_44 = 1;
    p->m_48 = 0;
    return self;
}

#include "generated/data/bsshader/lighting30shaderproperty.inc"
