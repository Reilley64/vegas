
// src/staging/blk_00960000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include <xmmintrin.h>

struct V
{
    __m128 v;
    void FUN_00961190(const V& o);
};

// @fnv 0x00961190
void V::FUN_00961190(const V& o)
{
    v = _mm_sub_ps(v, o.v);
}
