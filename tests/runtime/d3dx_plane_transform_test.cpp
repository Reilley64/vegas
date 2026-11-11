#include "fnv/d3dx_types.h"
#include "fnv/symbols_00ee6000.h"

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <initializer_list>
#include <limits>

namespace
{
void Check(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL plane transform: %s\n", message);
        std::exit(1);
    }
}

void Expect(const D3DXPLANE& actual, const D3DXPLANE& expected)
{
    Check(actual.a == expected.a && actual.b == expected.b && actual.c == expected.c && actual.d == expected.d,
          "four coefficients");
}

void ExpectMatrix(const D3DXMATRIX& actual, const D3DXMATRIX& expected)
{
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            Check(actual.m[row][column] == expected.m[row][column], "matrix input unchanged");
}

struct Guarded
{
    unsigned int before = 0x13579bdf;
    D3DXPLANE value{9, 9, 9, 9};
    unsigned int after = 0x2468ace0;
};

void Case(const D3DXPLANE& values, const D3DXMATRIX& matrix, const D3DXPLANE& expected)
{
    Guarded input, output;
    input.value = values;
    const auto savedMatrix = matrix;
    D3DXPLANE* returned = FUN_00ee6dc8(&output.value, &input.value, &matrix);
    Check(returned == &output.value, "exact borrowed output return");
    Expect(*returned, expected);
    Expect(input.value, values);
    ExpectMatrix(matrix, savedMatrix);
    returned = FUN_00ee6dc8(&input.value, &input.value, &matrix);
    Check(returned == &input.value, "exact in-place return");
    Expect(*returned, expected);
    ExpectMatrix(matrix, savedMatrix);
    for (const auto* object : {&input, &output})
        Check(object->before == 0x13579bdf && object->after == 0x2468ace0,
              "ordinary adjacent canaries");
}

// With the inverse transpose of a transformation, the transformed plane holds
// the transformed points: a point's signed distance is unchanged.
void MovesWithPoints(const D3DXPLANE& plane, const D3DXMATRIX& transformation, float x, float y, float z)
{
    D3DXMATRIX inverse{{.m = {}}}, inverseTranspose{{.m = {}}};
    Check(FUN_00ee6dda(&inverse, nullptr, &transformation) != nullptr, "invertible transformation");
    FUN_00ee6dd4(&inverseTranspose, &inverse);
    D3DXPLANE moved{0, 0, 0, 0};
    FUN_00ee6dc8(&moved, &plane, &inverseTranspose);
    const float point[3]{x, y, z};
    float movedPoint[3]{0, 0, 0};
    FUN_00ee6df8(movedPoint, point, &transformation);
    const double before = double(plane.a) * x + double(plane.b) * y + double(plane.c) * z + plane.d;
    const double after = double(moved.a) * movedPoint[0] + double(moved.b) * movedPoint[1] +
                         double(moved.c) * movedPoint[2] + moved.d;
    Check(std::fabs(before - after) < 1e-4, "signed distance of a moved point is kept");
}
}

int main()
{
    const D3DXMATRIX identity{{.m = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}};
    Case({0.6f, 0, 0.8f, -2.5f}, identity, {0.6f, 0, 0.8f, -2.5f});

    // Hand-derived row-vector product with an asymmetric matrix: every
    // coefficient, the distance included, takes part in every result.
    const D3DXMATRIX dense{{.m = {{1, 2, 3, 4}, {-2, 1, -1, 3}, {5, -1, 2, 1}, {10, -20, 30, 8}}}};
    Case({1, 2, 3, 4}, dense, {52, -79, 127, 45});
    Case({0, 0, 0, 1}, dense, {10, -20, 30, 8});
    Case({1, 0, 0, 0}, dense, {1, 2, 3, 4});

    // The plane y = 2 moved by (0, 3, 0) is y = 5. The matrix is the inverse
    // transpose of that translation, written out by hand.
    const D3DXMATRIX translationInverseTranspose{
        {.m = {{1, 0, 0, 0}, {0, 1, 0, -3}, {0, 0, 1, 0}, {0, 0, 0, 1}}}};
    Case({0, 1, 0, -2}, translationInverseTranspose, {0, 1, 0, -5});

    // No normalization and no homogeneous divide.
    const D3DXMATRIX scale{{.m = {{2, 0, 0, 0}, {0, -4, 0, 0}, {0, 0, 0.5f, 0}, {0, 0, 0, 2}}}};
    Case({1, 1, 1, 1}, scale, {2, -4, 0.5f, 2});

    // PROJECT CHOICE, not D3DX behaviour: sums are formed in double precision
    // and rounded once, and a sum too large for single precision is an
    // infinity of its sign. What D3DX returns for such inputs is not known.
    const float large = 0x1p127f;
    const D3DXMATRIX overflow{{.m = {{large, 0, 0, 0}, {large, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}};
    Case({1, 1, 0, 0}, overflow, {std::numeric_limits<float>::infinity(), 0, 0, 0});
    Case({-1, -1, 0, 0}, overflow, {-std::numeric_limits<float>::infinity(), 0, 0, 0});

    const D3DXMATRIX affine{{.m = {{0, 2, 0, 0}, {-1, 0, 0, 0}, {0, 0, 4, 0}, {2, -4, 8, 1}}}};
    MovesWithPoints({0.6f, 0, 0.8f, -2.5f}, affine, 1, 2, 3);
    MovesWithPoints({0, 1, 0, 3}, affine, -4, 0.5f, 7);
    const D3DXMATRIX sheared{{.m = {{1, 0.5f, 0, 0}, {0, 1, -0.25f, 0}, {2, 0, 1, 0}, {-3, 6, 1, 1}}}};
    MovesWithPoints({1.0f / 3.0f, 2.0f / 3.0f, 2.0f / 3.0f, 1}, sheared, 2, -1, 3);

    std::puts("PASS plane transform");
    return 0;
}
