#pragma once

#include <xmmintrin.h>

namespace RaySimilarityMath
{
struct RayVector
{
    __m128 q;
};

// Compare directions and squared endpoint distances. Unordered comparisons do not reject a pair.
extern "C" bool FUN_00e29920(const RayVector& a, const RayVector& b, const RayVector& n,
                            const RayVector& a2, const RayVector& b2, const RayVector& n2,
                            float thresh, float limit);
}  // namespace RaySimilarityMath
