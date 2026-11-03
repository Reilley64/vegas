
// src/fallout_shared/modelloader_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/modelloader.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/FUN_0043caa0_shell.h"
#include "fnv/decl/FUN_0043caf0_shell.h"
#include "fnv/decl/FUN_0043cc60_shell.h"
#include "fnv/decl/FUN_0043e810_shell.h"
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/FUN_00448a20_class.h"
#include "fnv/decl/FUN_00448a60_struct.h"
#include "fnv/decl/FUN_00496cd0_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00c3d440_cls.h"
#include "fnv/decl/Loader_S.h"
#include "fnv/decl/ObjectC3.h"
#include "fnv/decl/RecursiveModelLoader.h"
#include "fnv/decl/ThisS.h"
#include "fnv/decl/fnv_00440ba0__FUN_00440ba0_shell.h"
#include "fnv/decl/fnv_004414f0__FUN_004414f0.h"
#include "fnv/decl/fnv_004446a0__FUN_004446a0_shell.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00449000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_01202000.h"
#include "modelloader_verified_packet.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct PlaceHolder
{
    char _pad[0x24];
    char* m_h;
    void FUN_00e81c60(char*&);
};
// @fnv 0x00e81c60
void PlaceHolder::FUN_00e81c60(char*& kHandle)
{
    char* pkSrc = kHandle;
    if (m_h != pkSrc)
    {
        if (pkSrc != ::DAT_0109b220)
            InterlockedIncrement((long volatile*)(pkSrc - 8));
        if (m_h != ::DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_h - 8));
        m_h = pkSrc;
    }
}
