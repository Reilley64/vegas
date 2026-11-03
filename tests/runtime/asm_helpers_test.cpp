#include "check.h"
#include "fnv_asm_helpers.h"

#include <climits>
#include <cmath>

namespace
{

void FloatToIntRoundsToNearestEven(Checks& checks)
{
    checks.Equal("2.5", 2, fnv_FloatToInt(2.5f));
    checks.Equal("3.5", 4, fnv_FloatToInt(3.5f));
    checks.Equal("-2.5", -2, fnv_FloatToInt(-2.5f));
    checks.Equal("-1.75", -2, fnv_FloatToInt(-1.75f));
    checks.Equal("1.25", 1, fnv_FloatToInt(1.25f));
    checks.Equal("out of range", INT_MIN, fnv_FloatToInt(3.0e9f));
}

void SinCos(Checks& checks)
{
    float s = 1.0f, c = 0.0f;
    fnv_SinCos(0.0f, s, c);
    checks.Equal("sin 0", 0.0f, s);
    checks.Equal("cos 0", 1.0f, c);
    fnv_SinCos(0.5235987756f, s, c);
    checks.Equal("sin pi/6", true, std::fabs(s - 0.5f) < 1e-6f);
    checks.Equal("cos pi/6", true, std::fabs(c - 0.8660254f) < 1e-6f);
}

struct Point
{
    float x, y, z;
};

const float matrix[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void TransformVectorsUsesRows(Checks& checks)
{
    const Point src[2] = {{1, 0, 0}, {1, 1, 2}};
    Point dst[2] = {};
    unsigned int n = 2;
    fnv_TransformVectors(n, src, dst, matrix);
    checks.Equal("first x", 1.0f, dst[0].x);
    checks.Equal("first y", 4.0f, dst[0].y);
    checks.Equal("first z", 7.0f, dst[0].z);
    checks.Equal("second x", 9.0f, dst[1].x);
    checks.Equal("second y", 21.0f, dst[1].y);
    checks.Equal("second z", 33.0f, dst[1].z);

    Point untouched = {5, 5, 5};
    n = 0;
    fnv_TransformVectors(n, src, &untouched, matrix);
    checks.Equal("count 0", 5.0f, untouched.x);
}

void TransformPointsAddsTranslation(Checks& checks)
{
    const Point src[1] = {{1, 1, 2}};
    Point dst[1] = {};
    unsigned int n = 1;
    float tx = 0.5f, ty = -1.0f, tz = 10.0f;
    fnv_TransformPoints(n, src, dst, matrix, tx, ty, tz);
    checks.Equal("x", 9.5f, dst[0].x);
    checks.Equal("y", 20.0f, dst[0].y);
    checks.Equal("z", 43.0f, dst[0].z);
}

void AddWeightedPoint(Checks& checks)
{
    Point sum = {1, 2, 3};
    Point p = {2, 4, 8};
    Point* out = &sum;
    const float* point = &p.x;
    float weight = 0.5f;
    fnv_AddWeightedPoint(out, point, weight);
    checks.Equal("x", 2.0f, sum.x);
    checks.Equal("y", 4.0f, sum.y);
    checks.Equal("z", 7.0f, sum.z);
}

void ReadTicks64Advances(Checks& checks)
{
    unsigned __int64 first = 0, second = 0;
    fnv_ReadTicks64(first);
    fnv_ReadTicks64(second);
    checks.Equal("nonzero", true, first != 0);
    checks.Equal("advances", true, second >= first);
}

void CpuidReportsExtendedLeaves(Checks& checks)
{
    int maxExtended = 0;
    fnv_CpuidMaxExtended(maxExtended);
    checks.Equal("extended range", true, (static_cast<unsigned int>(maxExtended) & 0x80000000u) != 0);
}

} // namespace

int main()
{
    Checks checks("asm_helpers");
    checks.Run("FloatToInt", [&] { FloatToIntRoundsToNearestEven(checks); });
    checks.Run("SinCos", [&] { SinCos(checks); });
    checks.Run("TransformVectors", [&] { TransformVectorsUsesRows(checks); });
    checks.Run("TransformPoints", [&] { TransformPointsAddsTranslation(checks); });
    checks.Run("AddWeightedPoint", [&] { AddWeightedPoint(checks); });
    checks.Run("ReadTicks64", [&] { ReadTicks64Advances(checks); });
    checks.Run("Cpuid", [&] { CpuidReportsExtendedLeaves(checks); });
    return checks.ExitCode();
}
