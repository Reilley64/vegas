#include "fnv/d3dx_types.h"
#include "fnv/symbols_00ee6000.h"

#include <cmath>
#include <cstdio>
#include <cstdlib>

namespace
{
constexpr float HalfPi = 1.57079632679489661923f;
constexpr float Pi = 3.14159265358979323846f;

void Check(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL matrix rotation yaw pitch roll: %s\n", message);
        std::exit(1);
    }
}

struct Guarded
{
    unsigned int before = 0x13579bdf;
    D3DXMATRIX value{{.m = {{9, 9, 9, 9}, {9, 9, 9, 9}, {9, 9, 9, 9}, {9, 9, 9, 9}}}};
    unsigned int after = 0x2468ace0;
};

D3DXMATRIX Rotation(float yaw, float pitch, float roll)
{
    Guarded output;
    void* returned = FUN_00ee6e04(&output.value, yaw, pitch, roll);
    Check(returned == &output.value, "exact borrowed output return");
    Check(output.before == 0x13579bdf && output.after == 0x2468ace0, "ordinary adjacent canaries");
    // The homogeneous row and column are exact for every angle.
    for (unsigned int index = 0; index < 3; ++index)
        Check(output.value.m[index][3] == 0 && output.value.m[3][index] == 0, "no translation or projection");
    Check(output.value.m[3][3] == 1, "unit homogeneous element");
    return output.value;
}

// PROJECT CHOICE, not D3DX behaviour: the 1e-6 tolerance. Sine and cosine come
// from each build target's own library and may differ by a rounding step, so
// angle-dependent elements are compared within a tolerance this test picked.
// It says nothing about how close the result is to what D3DX returns.
void ExpectNear(const D3DXMATRIX& actual, const D3DXMATRIX& expected, const char* message)
{
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            Check(std::fabs(actual.m[row][column] - expected.m[row][column]) < 1e-6f, message);
}

D3DXMATRIX Product(const D3DXMATRIX& first, const D3DXMATRIX& second)
{
    D3DXMATRIX product{{.m = {}}};
    FUN_00ee6de0(&product, &first, &second);
    return product;
}

void Identities(float yaw, float pitch, float roll)
{
    const D3DXMATRIX rotation = Rotation(yaw, pitch, roll);
    // Row-vector order: roll about z first, then pitch about x, then yaw about y.
    const D3DXMATRIX composed =
        Product(Product(Rotation(0, 0, roll), Rotation(0, pitch, 0)), Rotation(yaw, 0, 0));
    ExpectNear(rotation, composed, "roll, then pitch, then yaw");
    // A rotation is orthonormal: its transpose is its inverse.
    D3DXMATRIX transpose{{.m = {}}};
    FUN_00ee6dd4(&transpose, &rotation);
    const D3DXMATRIX identity{{.m = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}};
    ExpectNear(Product(rotation, transpose), identity, "orthonormal rows");
    // Negated angles applied in the opposite order undo the rotation.
    const D3DXMATRIX inverse =
        Product(Product(Rotation(-yaw, 0, 0), Rotation(0, -pitch, 0)), Rotation(0, 0, -roll));
    ExpectNear(Product(rotation, inverse), identity, "negated angles in reverse order");
}
}

int main()
{
    // Zero angles give the identity exactly.
    const D3DXMATRIX identity{{.m = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}};
    const D3DXMATRIX zero = Rotation(0, 0, 0);
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            Check(zero.m[row][column] == identity.m[row][column], "zero angles give the identity");

    // Quarter turns about one axis each. Rows are the images of the x, y and
    // z axes: yaw takes +z to +x, pitch takes +y to +z, roll takes +x to +y.
    ExpectNear(Rotation(HalfPi, 0, 0), {{.m = {{0, 0, -1, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 1}}}},
               "quarter yaw about y");
    ExpectNear(Rotation(0, HalfPi, 0), {{.m = {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, -1, 0, 0}, {0, 0, 0, 1}}}},
               "quarter pitch about x");
    ExpectNear(Rotation(0, 0, HalfPi), {{.m = {{0, 1, 0, 0}, {-1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}},
               "quarter roll about z");
    ExpectNear(Rotation(Pi, 0, 0), {{.m = {{-1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, -1, 0}, {0, 0, 0, 1}}}},
               "half yaw about y");

    // Hand-derived dense value: yaw 30, pitch 45 and roll 60 degrees.
    ExpectNear(Rotation(Pi / 6, Pi / 4, Pi / 3),
               {{.m = {{0.73919892f, 0.61237244f, 0.28033009f, 0},
                       {-0.57322330f, 0.35355339f, 0.73919892f, 0},
                       {0.35355339f, -0.70710678f, 0.61237244f, 0},
                       {0, 0, 0, 1}}}},
               "yaw 30, pitch 45, roll 60 degrees");

    Identities(Pi / 6, Pi / 4, Pi / 3);
    Identities(-2.5f, 1.25f, 0.75f);
    Identities(4, -3, 2);
    Identities(0.001f, 0, -0.002f);

    std::puts("PASS matrix rotation yaw pitch roll");
    return 0;
}
