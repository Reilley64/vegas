
// src/fallout_shared/pathfinding/navmesh_loadsave_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/pathfinding/navmesh_loadsave.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00460340_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_006947e0_cls.h"
#include "fnv/decl/FUN_00699b60_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Map00694c50.h"
#include "fnv/decl/Map00694d30.h"
#include "fnv/decl/Map6946a0.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00690d50__FUN_00690d50_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_011de000.h"
#include "navmesh_loadsave_decls.h"

// FUN_00692940 : MSVC this-adjusting thunk  (sub ecx, 0x1c ; jmp <impl>)
struct A1_00692940
{
    A1_00692940();
    virtual void FUN_00692940();
    char pad[0x18];
};
struct A2_00692940
{
    A2_00692940();
    virtual void FUN_00692940();
};
struct Own_00692940 : A1_00692940, A2_00692940
{
    Own_00692940();
    virtual void key_fn();
// @fnv 0x00692940
    void FUN_00692940();
};
Own_00692940::Own_00692940()
{}
void Own_00692940::key_fn()
{}
Own_00692940* make_00692940()
{
    static Own_00692940 o;
    return &o;
}
