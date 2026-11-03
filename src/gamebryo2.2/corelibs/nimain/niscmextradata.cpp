
// src/gamebryo2.2/corelibs/nimain/niscmextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niscmextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00ee89a0
#include "fnv/decl/ExtraDataObject.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01270000.h"
int* __cdecl FUN_00ee89a0()
{
    return &(*reinterpret_cast<int *>(&::g_01270908));
}

extern int DAT_0110129c;
struct FUN_00a7b300_shell
{
    void FUN_00a7b300();
};
void __cdecl operator delete(void*, unsigned int);
struct NiSCMExtraData
{
    char _pad[36];
    void* m_24;
    char _pad2[4];
    void* m_2c;
    void* Destroy(unsigned int);
};
// @fnv 0x00ee89b0
void* NiSCMExtraData::Destroy(unsigned int auiFlags)
{
    void* tmp = m_24;
    *(int*)this = (int)&DAT_0110129c;
    ::FUN_00aa10f0(tmp);
    ::FUN_00aa10f0(m_2c);
    ((FUN_00a7b300_shell*)this)->FUN_00a7b300();
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0x30);
    return this;
}

struct FUN_00a7b2e0_shell
{
};
struct FUN_00a5b950_shell
{
};

struct FUN_00ee8910_obj
{
    void* vfptr;
    int unk04;
    int unk08;
    int m_countA;
    int unk10;
    int m_countB;
    int m_zero18;
    int unk1c;
    int m_zero20;
    void* m_arrA;
    int unk28;
    void* m_arrB;
    FUN_00ee8910_obj* FUN_00ee8910(int, int, int);
};

// @fnv 0x00ee8910
FUN_00ee8910_obj* FUN_00ee8910_obj::FUN_00ee8910(int a, int aiCountA, int aiCountB)
{
    reinterpret_cast<::ExtraDataObject *>((((FUN_00a7b2e0_shell*)this)))->FUN_00a7b2e0();
    vfptr = &DAT_0110129c;
    ::AssignFixedString((char *)(((FUN_00a5b950_shell*)this)), a, {});
    m_countA = aiCountA;
    m_zero18 = 0;
    if (aiCountA != 0)
    {
        m_arrA = ::FUN_00aa1070(aiCountA * 8);
    }
    else
    {
        m_arrA = 0;
    }
    m_countB = aiCountB;
    m_zero20 = 0;
    if (aiCountB != 0)
    {
        m_arrB = ::FUN_00aa1070(aiCountB * 8);
    }
    else
    {
        m_arrB = 0;
    }
    return this;
}
