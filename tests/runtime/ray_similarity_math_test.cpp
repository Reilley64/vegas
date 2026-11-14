#include "check.h"
#include "fnv/ray_similarity_math.h"
#include <cmath>
#include <limits>

using RaySimilarityMath::RayVector;
using RaySimilarityMath::FUN_00e29920;

static RayVector vector(float x, float y = 0, float z = 0, float w = 0)
{
    return {_mm_setr_ps(x, y, z, w)};
}

int main()
{
    Checks checks("runtime.ray_similarity_math");
    const float inf = std::numeric_limits<float>::infinity();
    const float nan = std::numeric_limits<float>::quiet_NaN();
    const RayVector zero = vector(0);
    const RayVector normal = vector(1);
    auto compare = [&](const char* name, bool expected, RayVector a, RayVector b, RayVector n,
                       RayVector a2, RayVector b2, RayVector n2, float threshold, float limit) {
        checks.Equal(name, expected, FUN_00e29920(a, b, n, a2, b2, n2, threshold, limit));
    };
    compare("equal rays", true, zero, normal, normal, zero, normal, normal, 1, 0);
    compare("direction below threshold", false, zero, zero, normal, zero, zero, vector(-1), 0, 0);
    compare("direction exact boundary", true, zero, zero, normal, zero, zero, normal, 1, 0);
    compare("direction just below boundary", false, zero, zero, normal, zero, zero, normal,
            std::nextafter(1.0f, inf), 0);
    compare("endpoint exact squared boundary", true, zero, zero, normal, vector(3, 4), vector(0, 0, 5), normal, 1, 25);
    compare("first endpoint outside", false, zero, zero, normal, vector(3, 4), zero, normal, 1,
            std::nextafter(25.0f, 0.0f));
    compare("second endpoint outside", false, zero, zero, normal, zero, vector(0, 0, 5), normal, 1,
            std::nextafter(25.0f, 0.0f));
    compare("negative limit", false, zero, zero, normal, zero, zero, normal, 1, -1);
    compare("signed zero limits", true, vector(-0.0f), zero, normal, zero, zero, normal, 1, -0.0f);
    compare("nan direction does not reject", true, zero, zero, vector(nan), zero, zero, normal, 1, 0);
    compare("nan threshold does not reject", true, zero, zero, normal, zero, zero, vector(-1), nan, 0);
    compare("nan first distance does not reject", true, zero, zero, normal, vector(nan), zero, normal, 1, 0);
    compare("nan second distance does not reject", true, zero, zero, normal, zero, vector(nan), normal, 1, 0);
    compare("nan limit does not reject", true, zero, zero, normal, vector(10), vector(20), normal, 1, nan);
    compare("first nan does not hide second failure", false, zero, zero, normal, vector(nan), vector(2), normal, 1, 1);
    compare("nan threshold does not hide distance failure", false, zero, zero, normal, vector(2), zero, normal, nan, 1);
    compare("infinite distance exceeds finite limit", false, zero, zero, normal, vector(inf), zero, normal, 1, 1);
    compare("infinite limit accepts infinite distance", true, zero, zero, normal, vector(inf), vector(-inf), normal, 1, inf);
    compare("negative infinite limit rejects", false, zero, zero, normal, zero, zero, normal, 1, -inf);
    compare("positive infinite direction", true, zero, zero, vector(inf), zero, zero, normal, 1, 0);
    compare("negative infinite direction", false, zero, zero, vector(-inf), zero, zero, normal, 1, 0);
    compare("infinite threshold rejects finite direction", false, zero, zero, normal, zero, zero, normal, inf, 0);
    compare("equal infinite directions pass threshold", true, zero, zero, vector(inf), zero, zero, normal, inf, 0);
    compare("infinite subtraction becomes unordered", true, vector(inf), zero, normal, vector(inf), zero, normal, 1, 0);
    compare("overflowed squared distance", false, zero, zero, normal, vector(std::numeric_limits<float>::max()), zero,
            normal, 1, std::numeric_limits<float>::max());
    compare("w lane does not enter comparisons", true, vector(0, 0, 0, inf), vector(0, 0, 0, nan),
            vector(1, 0, 0, nan), vector(0, 0, 0, -inf), vector(0, 0, 0, inf), vector(1, 0, 0, inf), 1, 0);
    // In single precision, y*x + x*x cancels before z*x is added.
    compare("dot uses z plus y plus x grouping", true, zero, zero, vector(16777216.0f, -16777216.0f, 1),
            zero, zero, vector(1, 1, 1), 1, 0);
    compare("squared distance retains small xy before z", false, zero, zero, normal, vector(1, 1, 4096), zero,
            normal, 1, 16777216.0f);
    return checks.ExitCode();
}
