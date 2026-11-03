
// src/fallout_shared/tesobjectcell_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF /Oy- (unit src/fallout_shared/tesobjectcell_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/tesobjectcell_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectcell.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();
struct FUN_00b5a9a0_Node
{
    void* m_pListObject;
    void* m_pNext;
    unsigned int m_uiCount;
};
struct FUN_00b5a9a0_List
{
    FUN_00b5a9a0_Node* m_pHead;
    FUN_00b5a9a0_Node* m_pTail;
    unsigned int m_uiCount;
    void __thiscall FUN_00b5a9a0(FUN_00b5a9a0_Node* node);
};
void* __cdecl _memmove(void* dst, const void* src, unsigned int count);
void* __cdecl _fnv_zlib_memset(void* ptr, int value, unsigned int count);
struct FUN_00bb39e0_shell
{
    int m_00;
    int m_04;
    void* m_08;
    void FUN_00bb39e0(const void* src, unsigned int count);
};

#include <xmmintrin.h>
struct FUN_004a3c90
{
    __m128 m_00;
    FUN_004a3c90(const FUN_004a3c90& src);
};

// @fnv 0x004a3c90
FUN_004a3c90::FUN_004a3c90(const FUN_004a3c90& src)
{
    m_00 = src.m_00;
}

struct FUN_005532a0_cls
{
    __m128 m_v;
    FUN_005532a0_cls* FUN_005532a0(float a1, float a2, float a3, float a4);
};

// @fnv 0x005532a0
FUN_005532a0_cls* FUN_005532a0_cls::FUN_005532a0(float a1, float a2, float a3, float a4)
{
    m_v = _mm_setr_ps(a1, a2, a3, a4);
    return this;
}
