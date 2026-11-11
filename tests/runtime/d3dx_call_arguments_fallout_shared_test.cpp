// Checks the native D3DX functions with the argument patterns that VEGAS-90
// restored, from before 3f0599801, in two fallout_shared functions:
// 0x00c4c2d0 in xgamesetting.cpp and 0x004ecef0 in teswater.cpp. It tests the
// callees' contract, not the repaired sites, which do not link into a test.
// Each case runs the function's sequence of D3DX calls, with the same
// argument pattern, on objects of the same shape (16 floats for a matrix),
// checks what the sequence must leave, and checks that skipping the calls
// does not leave it. Skipping the calls is not what the argument-less calls
// did: ?FUN_00ee6dd4@@YAXXZ has no definition at all, and the other two
// argument-less names call through an import pointer with whatever the
// registers hold.
#include "fnv/d3dx_types.h"
#include "fnv/symbols_00ee6000.h"

#include <cmath>
#include <cstdio>
#include <cstdlib>

namespace
{
void Check(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL fallout_shared D3DX call arguments: %s\n", message);
        std::exit(1);
    }
}

bool Near(double actual, double expected)
{
    return std::fabs(actual - expected) <= 1e-5 * (1 + std::fabs(expected));
}

D3DXMATRIX Identity()
{
    return D3DXMATRIX{{.m = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}};
}

// 0x00c4c2d0, second branch: kM is the identity moved to the camera position,
// and the restored call ::FUN_00ee6dda(pOut, 0, &kM) writes its inverse.
void CameraInverse(D3DXMATRIX* pOut, float x, float y, float z, bool restored)
{
    D3DXMATRIX kM = Identity();
    kM.m[3][0] = x;
    kM.m[3][1] = y;
    kM.m[3][2] = z;
    if (restored)
        FUN_00ee6dda(pOut, 0, &kM);
}

bool IsTranslation(const D3DXMATRIX& matrix, float x, float y, float z)
{
    D3DXMATRIX expected = Identity();
    expected.m[3][0] = x;
    expected.m[3][1] = y;
    expected.m[3][2] = z;
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            if (!Near(matrix.m[row][column], expected.m[row][column]))
                return false;
    return true;
}

void CameraInverseCases()
{
    const D3DXMATRIX unwritten{{.m = {{9, 9, 9, 9}, {9, 9, 9, 9}, {9, 9, 9, 9}, {9, 9, 9, 9}}}};
    D3DXMATRIX out = unwritten;
    CameraInverse(&out, 10, -20, 30.5f, true);
    Check(IsTranslation(out, -10, 20, -30.5f), "the camera matrix is the inverse translation");
    out = unwritten;
    CameraInverse(&out, 10, -20, 30.5f, false);
    Check(!IsTranslation(out, -10, 20, -30.5f), "skipping the calls leaves the camera matrix unwritten");
}

// 0x004ecef0: the restored calls ::FUN_00ee6dda(&inverse, 0, &transform) and
// ::FUN_00ee6dd4(&transform, &inverse) turn the transformation into its
// inverse transpose, which the plane transform then takes.
D3DXPLANE WaterPlane(const D3DXMATRIX& placement, D3DXPLANE plane, bool restored)
{
    D3DXMATRIX transform = placement;
    D3DXMATRIX inverse{};
    if (restored)
    {
        FUN_00ee6dda(&inverse, 0, &transform);
        FUN_00ee6dd4(&transform, &inverse);
    }
    D3DXPLANE result{};
    FUN_00ee6dce(&plane, &plane);
    FUN_00ee6dc8(&result, &plane, &transform);
    return result;
}

// Every point of the plane, moved by the placement, lies on the result.
bool HoldsMovedPoints(const D3DXMATRIX& placement, const D3DXPLANE& result)
{
    // Three points of x + 2y + 2z = 6.
    const float points[3][3] = {{6, 0, 0}, {0, 3, 0}, {2, 1, 1}};
    for (const auto& p : points)
    {
        double moved[3];
        for (unsigned int column = 0; column < 3; ++column)
            moved[column] = p[0] * placement.m[0][column] + p[1] * placement.m[1][column] +
                            p[2] * placement.m[2][column] + placement.m[3][column];
        const double distance = result.a * moved[0] + result.b * moved[1] + result.c * moved[2] + result.d;
        if (!Near(distance, 0))
            return false;
    }
    return true;
}

void WaterPlaneCases()
{
    // Scale, shear and translation: neither orthogonal nor symmetric.
    const D3DXMATRIX placement{{.m = {{2, 0, 0, 0}, {1, 3, 0, 0}, {0, 0.5f, 4, 0}, {5, -7, 11, 1}}}};
    const D3DXPLANE plane{1, 2, 2, -6};
    Check(HoldsMovedPoints(placement, WaterPlane(placement, plane, true)),
          "the water plane holds the moved points");
    Check(!HoldsMovedPoints(placement, WaterPlane(placement, plane, false)),
          "skipping the calls transforms the plane by the placement itself");
}
}

int main()
{
    CameraInverseCases();
    WaterPlaneCases();
    return 0;
}
