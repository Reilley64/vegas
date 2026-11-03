// fnv_asm_helpers.h - helpers for instruction sequences the original program wrote in x87 inline assembly.
//
// The original engine reached fsincos, a float-to-int conversion in the current rounding mode (fld + fistp), rdtsc,
// cpuid, int 3 and a few fixed x87 transform loops through small inline-assembly helpers. These are C++ and compiler
// intrinsic versions with the same results. Call sites use the same names and arguments.
#pragma once

#include <cmath>
#include <intrin.h>

// fsincos.
inline void fnv_SinCos(float fRadians, float& fSin, float& fCos)
{
    fSin = std::sin(fRadians);
    fCos = std::cos(fRadians);
}

// fld + fistp: rounds in the current rounding mode (round to nearest even by default). Out-of-range values give
// INT_MIN, as fistp's integer indefinite does.
inline int fnv_FloatToInt(float fValue)
{
    return _mm_cvtss_si32(_mm_set_ss(fValue));
}

// dst[i] = matrix * src[i] for n vectors of three floats; the matrix is nine floats, row by row.
inline void fnv_TransformVectors(unsigned int n, const void* src, void* dst, const void* matrix)
{
    const float* s = static_cast<const float*>(src);
    float* d = static_cast<float*>(dst);
    const float* m = static_cast<const float*>(matrix);
    for (; n != 0; --n, s += 3, d += 3)
    {
        const float x = s[0], y = s[1], z = s[2];
        d[0] = x * m[0] + y * m[1] + z * m[2];
        d[1] = x * m[3] + y * m[4] + z * m[5];
        d[2] = x * m[6] + y * m[7] + z * m[8];
    }
}

// fnv_TransformVectors, then adds (tx, ty, tz).
inline void fnv_TransformPoints(unsigned int n, const void* src, void* dst, const void* matrix, float tx, float ty,
                                float tz)
{
    const float* s = static_cast<const float*>(src);
    float* d = static_cast<float*>(dst);
    const float* m = static_cast<const float*>(matrix);
    for (; n != 0; --n, s += 3, d += 3)
    {
        const float x = s[0], y = s[1], z = s[2];
        d[0] = x * m[0] + y * m[1] + z * m[2] + tx;
        d[1] = x * m[3] + y * m[4] + z * m[5] + ty;
        d[2] = x * m[6] + y * m[7] + z * m[8] + tz;
    }
}

// rdtsc.
inline void fnv_ReadTicks64(unsigned __int64& ticks)
{
    ticks = __rdtsc();
}

// cpuid leaf 0x80000000: the highest extended leaf (eax).
inline void fnv_CpuidMaxExtended(int& result)
{
    int registers[4];
    __cpuid(registers, static_cast<int>(0x80000000u));
    result = registers[0];
}

// cpuid leaf 0x80000001, eax. The original loaded the leaf into edx instead of eax, so the leaf it queried was
// whatever eax held; eax of an extended leaf never has bit 31 set, which is the only bit the caller tests.
inline void fnv_CpuidLegacyExtended(int& result)
{
    int registers[4];
    __cpuid(registers, static_cast<int>(0x80000001u));
    result = registers[0];
}

// cpuid leaf 1: the feature flags (edx).
inline void fnv_CpuidFeatures(int& result)
{
    int registers[4];
    __cpuid(registers, 1);
    result = registers[3];
}

// Havok HK_BREAKPOINT, reached at the end of HK_ERROR / HK_ASSERT reports in release builds.
inline void fnv_Breakpoint()
{
    __debugbreak();
}

// out += point * weight for one point of three floats (the position-only skinning loop at 0x00a855f0).
inline void fnv_AddWeightedPoint(void* out, const float* point, float weight)
{
    float* o = static_cast<float*>(out);
    o[0] = point[0] * weight + o[0];
    o[1] = point[1] * weight + o[1];
    o[2] = point[2] * weight + o[2];
}
