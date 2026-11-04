
// src/staging/blk_00880000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/S00561240_Vector.h"
#include "fnv/symbols_00450000.h"
#include <xmmintrin.h>

struct S008910c0_Vector
{
    __m128 m_vComponents;
                 // broadcast x
    void FUN_008910c0(const S008910c0_Vector* a, const S008910c0_Vector* b);  // subMul
};

// @fnv 0x008910c0
void S008910c0_Vector::FUN_008910c0(const S008910c0_Vector* a, const S008910c0_Vector* b)
{
    S008910c0_Vector kScale;
    m_vComponents = _mm_sub_ps(m_vComponents, _mm_mul_ps(((::S008910c0_Vector *)(reinterpret_cast<::S00561240_Vector *>((void *)(a))->FUN_00561240((::S00561240_Vector *)(::S008910c0_Vector *)(&kScale))))->m_vComponents, b->m_vComponents));
}
