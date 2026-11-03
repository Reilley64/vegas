// fnv_simd.h - element access to SSE vectors.
//
// MSVC declares __m128 as a union, and the original code read and wrote its elements through the union members
// (m128_f32, m128_u64 and so on). Other compilers declare it as a vector type. fnv_simd_as<T>(v) gives the vector's
// elements as an array of T.
#pragma once

#include <xmmintrin.h>

template <typename T, typename Vector>
inline T* fnv_simd_as(Vector& v)
{
    static_assert(sizeof(Vector) == 16);
    return reinterpret_cast<T*>(&v);
}

template <typename T, typename Vector>
inline const T* fnv_simd_as(const Vector& v)
{
    static_assert(sizeof(Vector) == 16);
    return reinterpret_cast<const T*>(&v);
}
