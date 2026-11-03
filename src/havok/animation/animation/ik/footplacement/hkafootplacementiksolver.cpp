
// src/havok/animation/animation/ik/footplacement/hkafootplacementiksolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/ik/footplacement/hkafootplacementiksolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00cd8800
#include <cstdint>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_011f6000.h"
void FUN_00cd8800(unsigned char* out, int arg2, int arg3, int arg4, int arg5)
{
    *out = 0;
}

struct GlobalMgr
{
};


struct FUN_00c74e70_cls
{
    intptr_t m_vptr;

    FUN_00c74e70_cls* FUN_00c74e70(unsigned char acFlags);
};

// Sets the object's vtable pointer to DAT_010c4b60 and, when bit 0 of acFlags is set, releases the object through DAT_011f6238, returning this.
// @fnv 0x00c74e70
FUN_00c74e70_cls* FUN_00c74e70_cls::FUN_00c74e70(unsigned char acFlags)
{
    m_vptr = (intptr_t)&DAT_010c4b60;
    if (acFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::GlobalMgr *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}

struct CD8810Bool
{
    char m_cBooleanValue;

    CD8810Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct CD8810Filter
{
    virtual CD8810Bool FUN_00cd8810(const void* a, const void* b, const void* c, const void* d, const void* e) const;
};

// @fnv 0x00cd8810
CD8810Bool CD8810Filter::FUN_00cd8810(const void* a, const void* b, const void* c, const void* d, const void* e) const
{
    return false;
}

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"

class NormVec_cls
{
  public:
    __m128 m_v;
    __m128* FUN_00c74c90(__m128* out);
};

// Computes the normalized version of m_v using an approximate reciprocal square root and one Newton-Raphson refinement, storing the result in out.
// @fnv 0x00c74c90
__m128* NormVec_cls::FUN_00c74c90(__m128* out)
{
    __m128 vVec = m_v;
    __m128 vSq = _mm_mul_ps(vVec, vVec);
    __m128 vLenSq = _mm_add_ss(_mm_shuffle_ps(vSq, vSq, 0xaa), _mm_add_ss(_mm_shuffle_ps(vSq, vSq, 0x55), vSq));
    __m128 vInvLen = _mm_rsqrt_ss(vLenSq);
    __m128 vZeroMask = _mm_cmpeq_ss(vLenSq, _mm_set_ss(0.0f));
    __m128 vT = _mm_mul_ss(_mm_mul_ss(vLenSq, vInvLen), vInvLen);
    __m128 vRefined = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), vInvLen), _mm_sub_ss(_mm_set_ss(3.0f), vT));
    __m128 s = _mm_andnot_ps(vZeroMask, vRefined);
    s = _mm_shuffle_ps(s, s, 0);
    __m128 vResult = _mm_mul_ps(s, vVec);
    if ((_mm_movemask_ps(_mm_cmplt_ps(vVec, _mm_setzero_ps())) & 8) != 0)
    {
        vResult = _mm_xor_ps(::DAT_010c44d0, vResult);
    }
    *out = vResult;
    return out;
}

#include "generated/data/havok/animation/animation/ik/footplacement/hkafootplacementiksolver.inc"
