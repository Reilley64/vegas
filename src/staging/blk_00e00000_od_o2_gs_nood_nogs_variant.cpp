
// src/staging/blk_00e00000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00e00000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/decl/S_00e11a90_Class.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_01268000.h"
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct ColumnScalarsE1
{
    float x, y, z, w;
};
struct MatrixScalarsE1
{
    ColumnScalarsE1 c0, c1, c2, c3;
};
struct MatrixE1
{
    __m128 c0, c1, c2, c3;
};
struct MatrixOwnerE1
{
    void FUN_00e11ba0(const void*);
};
// @fnv 0x00e11ba0
void MatrixOwnerE1::FUN_00e11ba0(const void* input)
{
    __declspec(align(16)) MatrixScalarsE1 identity;
    identity.c0 = (*reinterpret_cast<const ::MatrixScalarsE1 *>(&::DAT_01268370)).c0;
    identity.c1 = (*reinterpret_cast<const ::MatrixScalarsE1 *>(&::DAT_01268370)).c1;
    identity.c2 = (*reinterpret_cast<const ::MatrixScalarsE1 *>(&::DAT_01268370)).c2;
    identity.c3 = (*reinterpret_cast<const ::MatrixScalarsE1 *>(&::DAT_01268370)).c3;
    MatrixE1 matrix;
    matrix.c0 = *reinterpret_cast<const __m128*>(&identity.c0);
    matrix.c1 = *reinterpret_cast<const __m128*>(&identity.c1);
    matrix.c2 = *reinterpret_cast<const __m128*>(&identity.c2);
    matrix.c3 = *reinterpret_cast<const __m128*>(&identity.c3);
    reinterpret_cast<::RotationRows *>(&(matrix))->FUN_00cb2d90((void *)(input));
    reinterpret_cast<::S_00e11a90_Class *>(this)->FUN_00e11a90((int)&(matrix));
}
