#include "fnv/ray_similarity_math.h"

static __forceinline __m128 dot3(__m128 a, __m128 b)
{
    __m128 q = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q));
}
namespace RaySimilarityMath
{
// @fnv 0x00e29920
extern "C" __declspec(noinline) bool FUN_00e29920(const RayVector& a, const RayVector& b, const RayVector& n,
                                                  const RayVector& a2, const RayVector& b2, const RayVector& n2,
                                                  float thresh, float limit)
{
    float dot;
    _mm_store_ss(&dot, dot3(n.q, n2.q));
    if (dot < thresh)
        return false;
    __m128 d1 = _mm_sub_ps(a2.q, a.q);
    __m128 d2 = _mm_sub_ps(b2.q, b.q);
    float distance1;
    _mm_store_ss(&distance1, dot3(d1, d1));
    if (distance1 > limit)
        return false;
    float distance2;
    _mm_store_ss(&distance2, dot3(d2, d2));
    return !(distance2 > limit);
}
}  // namespace RaySimilarityMath
