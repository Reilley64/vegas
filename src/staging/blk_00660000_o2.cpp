
// src/staging/blk_00660000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/S00561240_Vector.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00450000.h"
#include <xmmintrin.h>

struct ScalarValue
{
    __m128 value;
    ScalarValue(const __m128&);
};

struct Vec4
{
    __m128 value;
    ScalarValue Dot(const Vec4&) const;
    void FUN_0066c930();
};

// @fnv 0x0066c930
void Vec4::FUN_0066c930()
{
    ScalarValue dot = Dot(*this);
    __m128 d = (*(const ::__m128 *)(new ((void *)&dot) ::Vec3()));
    ScalarValue s(_mm_rsqrt_ss(d));
    value = _mm_mul_ps(value, (*(::__m128 *)(reinterpret_cast<::S00561240_Vector *>((void *)&(s))->FUN_00561240({}))));
}
