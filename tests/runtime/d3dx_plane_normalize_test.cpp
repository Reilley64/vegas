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
        std::fprintf(stderr, "FAIL plane normalize: %s\n", message);
        std::exit(1);
    }
}

void Expect(const D3DXPLANE& actual, const D3DXPLANE& expected)
{
    Check(actual.a == expected.a && actual.b == expected.b && actual.c == expected.c && actual.d == expected.d,
          "four coefficients");
}

struct Guarded
{
    unsigned int before = 0x13579bdf;
    D3DXPLANE value{9, 9, 9, 9};
    unsigned int after = 0x2468ace0;
};

void Case(const D3DXPLANE& values, const D3DXPLANE& expected)
{
    Guarded input, output;
    input.value = values;
    auto* returned = static_cast<D3DXPLANE*>(FUN_00ee6dce(&output.value, &input.value));
    Check(returned == &output.value, "exact borrowed output return");
    Expect(*returned, expected);
    Expect(input.value, values);
    returned = static_cast<D3DXPLANE*>(FUN_00ee6dce(&input.value, &input.value));
    Check(returned == &input.value, "exact in-place return");
    Expect(*returned, expected);
    for (const auto* object : {&input, &output})
        Check(object->before == 0x13579bdf && object->after == 0x2468ace0,
              "ordinary adjacent canaries");
}

// The normalized plane has a unit normal and holds the same points.
void Identity(const D3DXPLANE& values, float x, float y, float z)
{
    D3DXPLANE result{0, 0, 0, 0};
    FUN_00ee6dce(&result, &values);
    const double a = result.a, b = result.b, c = result.c;
    Check(std::fabs(std::sqrt(a * a + b * b + c * c) - 1) < 1e-6, "unit normal");
    const double before = double(values.a) * x + double(values.b) * y + double(values.c) * z + values.d;
    const double after = a * x + b * y + c * z + result.d;
    const double length = std::sqrt(double(values.a) * values.a + double(values.b) * values.b +
                                    double(values.c) * values.c);
    Check(std::fabs(before / length - after) < 1e-5, "signed distance of a point is kept");
}
}

int main()
{
    // Hand-derived values: the distance is divided by the same length as the normal.
    Case({0, 3, 4, 10}, {0, 0.6f, 0.8f, 2});
    Case({2, 0, 0, -6}, {1, 0, 0, -3});
    Case({1, 2, 2, 3}, {1.0f / 3.0f, 2.0f / 3.0f, 2.0f / 3.0f, 1});
    Case({0, 0, -0.5f, 0}, {0, 0, -1, 0});
    // An already normalized plane is unchanged.
    Case({0, 1, 0, -7.25f}, {0, 1, 0, -7.25f});
    Identity({2, -1, 3, 4}, 0.5f, -2, 1.5f);
    Identity({-0.001f, 250, 0.5f, -1000}, 3, 4, -5);

    // PROJECT CHOICE, not D3DX behaviour: the public reference does not state
    // the zero-length case. This function returns the zero plane.
    Case({0, 0, 0, 5}, {0, 0, 0, 0});
    // PROJECT CHOICE, not D3DX behaviour: the length is evaluated in double
    // precision, so these inputs normalize here. Their squares overflow or
    // underflow single precision, and what D3DX returns for them is not known.
    Case({0x1p100f, 0, 0, 0x1p101f}, {1, 0, 0, 2});
    Case({0, 0x1p-140f, 0, 0x1p-139f}, {0, 1, 0, 2});
    // PROJECT CHOICE, not D3DX behaviour: a distance too large for single
    // precision after the division is an infinity of its sign.
    Case({0x1p-100f, 0, 0, -0x1p100f}, {1, 0, 0, -std::numeric_limits<float>::infinity()});

    std::puts("PASS plane normalize");
    return 0;
}
