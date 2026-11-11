// Checks the native D3DX functions with the argument patterns that VEGAS-90
// restored, from before 3f0599801, in four lighting functions: in
// lighting30shader.cpp the frustum update that 0x00bbef90 inlines, 0x00bbe6b0
// and 0x00bbc050, and in shadowlightshader.cpp 0x00b78a90. It tests the
// callees' contract, not the repaired sites, which do not link into a test.
// Each case runs the function's sequence of D3DX calls, with the same
// argument pattern, on objects of the same shape (16 floats for a matrix, 3
// for a point), checks what the sequence must leave, and checks that skipping
// the calls does not leave it. Skipping the calls is not what the
// argument-less calls did: ?FUN_00ee6dd4@@YAXXZ has no definition at all, and
// the other two argument-less names call through an import pointer with
// whatever the registers hold.
// An object the function leaves uninitialized starts here with the value 7 in
// every float.
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
        std::fprintf(stderr, "FAIL lighting D3DX call arguments: %s\n", message);
        std::exit(1);
    }
}

bool Near(double actual, double expected)
{
    return std::fabs(actual - expected) <= 1e-5 * (1 + std::fabs(expected));
}

// Neither orthogonal nor symmetric, and invertible.
const D3DXMATRIX view{{.m = {{2, 0, 1, 0}, {0, 3, 0, 0}, {1, 0, 4, 0}, {5, -7, 11, 1}}}};
const D3DXMATRIX projection{{.m = {{1.5f, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 1.25f, 1}, {0, 0, -0.5f, 0}}}};

// The frustum update: ::FUN_00ee6de0(&vp, &view, &proj), then the restored
// ::FUN_00ee6dda(&inv, 0, &vp) and ::FUN_00ee6dd4(&vp, &inv) leave vp as the
// inverse transpose of view * projection.
D3DXMATRIX FrustumPlanesMatrix(bool restored)
{
    D3DXMATRIX vp, inv{{.m = {{7, 7, 7, 7}, {7, 7, 7, 7}, {7, 7, 7, 7}, {7, 7, 7, 7}}}};
    FUN_00ee6de0(&vp, &view, &projection);
    if (restored)
    {
        FUN_00ee6dda(&inv, 0, &vp);
        FUN_00ee6dd4(&vp, &inv);
    }
    return vp;
}

// vp is the inverse transpose of A = view * projection when vp^T * A = I.
bool IsInverseTransposeOfViewProjection(const D3DXMATRIX& vp)
{
    D3DXMATRIX a;
    FUN_00ee6de0(&a, &view, &projection);
    for (unsigned int i = 0; i < 4; ++i)
        for (unsigned int j = 0; j < 4; ++j)
        {
            double sum = 0;
            for (unsigned int k = 0; k < 4; ++k)
                sum += double(vp.m[k][i]) * a.m[k][j];
            if (!Near(sum, i == j ? 1 : 0))
                return false;
        }
    return true;
}

// 0x00bbe6b0: a copy of the view matrix is transposed in place,
// ::FUN_00ee6dd4(&mat, &mat).
D3DXMATRIX TransposedViewCopy(bool restored)
{
    D3DXMATRIX mat = view;
    if (restored)
        FUN_00ee6dd4(&mat, &mat);
    return mat;
}

bool IsViewTransposed(const D3DXMATRIX& mat)
{
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            if (mat.m[row][column] != view.m[column][row])
                return false;
    return true;
}

// 0x00bbc050 and 0x00b78a90: a point or direction is transformed as a normal
// into an uninitialized local, which is then normalized back into it:
// ::FUN_00ee6df2(&vTransformed, &vPoint, matrix), then
// ::FUN_00ee6dec(&vPoint, &vTransformed); in 0x00b78a90
// ::FUN_00ee6df2(&transformedPos, &lightDirection, &matrix), then
// ::FUN_00ee6dec(&lightDirection, &transformedPos).
struct Point3
{
    float x, y, z;
};

Point3 NormalizedNormalTransform(Point3 vPoint, const D3DXMATRIX* matrix, bool restored)
{
    Point3 vTransformed{7, 7, 7};
    if (restored)
        FUN_00ee6df2(&vTransformed, &vPoint, matrix);
    FUN_00ee6dec(&vPoint, &vTransformed);
    return vPoint;
}

void Cases()
{
    Check(IsInverseTransposeOfViewProjection(FrustumPlanesMatrix(true)),
          "the frustum matrix is the inverse transpose of view times projection");
    Check(!IsInverseTransposeOfViewProjection(FrustumPlanesMatrix(false)),
          "skipping the calls leaves view times projection");

    Check(IsViewTransposed(TransposedViewCopy(true)), "the view copy is transposed");
    Check(!IsViewTransposed(TransposedViewCopy(false)), "skipping the calls leaves the view copy as it was");

    // (1, 2, 2) times the upper 3x3 of view is (4, 6, 9); its length is sqrt(133).
    const Point3 expected{float(4 / std::sqrt(133.0)), float(6 / std::sqrt(133.0)), float(9 / std::sqrt(133.0))};
    const Point3 restored = NormalizedNormalTransform({1, 2, 2}, &view, true);
    Check(Near(restored.x, expected.x) && Near(restored.y, expected.y) && Near(restored.z, expected.z),
          "the point is the normalized normal transform");
    const Point3 broken = NormalizedNormalTransform({1, 2, 2}, &view, false);
    Check(!(Near(broken.x, expected.x) && Near(broken.y, expected.y) && Near(broken.z, expected.z)),
          "skipping the calls normalizes the uninitialized local instead");
}
}

int main()
{
    Cases();
    return 0;
}
