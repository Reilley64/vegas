
// src/gamebryo2.2/corelibs/nimain/niobjectnet_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niobjectnet.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_0056e000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01268000.h"
#include "niobjectnet_decls.h"
#pragma optimize("", off)
#pragma optimize("", on)
#pragma optimize("", off)
#pragma optimize("", on)
#pragma optimize("", off)
#pragma optimize("", on)

struct FUN_007408d0_Class
{
    char m_auiShapeKeys[0x24];
    int m_val;
    bool FUN_007408d0(int a);
};
// @fnv 0x007408d0
bool FUN_007408d0_Class::FUN_007408d0(int a)
{
    if (a == 2 || a == 0)
    {
        m_val = a;
        return true;
    }
    return false;
}
