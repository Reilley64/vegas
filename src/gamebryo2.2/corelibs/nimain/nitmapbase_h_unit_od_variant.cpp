
// src/gamebryo2.2/corelibs/nimain/nitmapbase_h_unit_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitmapbase_h_unit.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/InteriorCellLookup.h"
#include "fnv/decl/ResourceDescriptor.h"
#include "fnv/decl/Twin_008d0360.h"
#include "fnv/decl/fnv_005892c0__FUN_005892c0_t.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00845000.h"
#include "nitmapbase.inl"

struct FUN_00404cd0_Class
{
    void* FUN_00404cd0(unsigned int flags);
};

// @fnv 0x00404cd0
void* FUN_00404cd0_Class::FUN_00404cd0(unsigned int flags)
{
    reinterpret_cast<::Twin_008d0360 *>(this)->FUN_00404c80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
