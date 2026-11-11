#include "NiPoint3.h"
#include "fnv/symbols_00ee6000.h"

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <initializer_list>

namespace
{
void Check(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL vector3 normalize: %s\n", message);
        std::exit(1);
    }
}

void Expect(const NiPoint3& actual, const NiPoint3& expected)
{
    Check(actual.x == expected.x && actual.y == expected.y && actual.z == expected.z,
          "three scalar results");
}

struct Guarded
{
    unsigned int before = 0x13579bdf;
    NiPoint3 value{0, 0, 0};
    unsigned int after = 0x2468ace0;
};

void Case(const NiPoint3& values, const NiPoint3& expected)
{
    Guarded input, output;
    input.value = values;
    auto* returned = static_cast<NiPoint3*>(FUN_00ee6dec(&output.value, &input.value));
    Check(returned == &output.value, "exact borrowed output return");
    Expect(*returned, expected);
    Expect(input.value, values);
    returned = static_cast<NiPoint3*>(FUN_00ee6dec(&input.value, &input.value));
    Check(returned == &input.value, "exact in-place return");
    Expect(*returned, expected);
    for (const auto* object : {&input, &output})
        Check(object->before == 0x13579bdf && object->after == 0x2468ace0,
              "ordinary adjacent canaries");
}

// Unit length and unchanged direction for a vector with no exact quotient.
void Identity(const NiPoint3& values)
{
    NiPoint3 result{0, 0, 0};
    FUN_00ee6dec(&result, &values);
    const double x = result.x, y = result.y, z = result.z;
    Check(std::fabs(std::sqrt(x * x + y * y + z * z) - 1) < 1e-6, "unit length");
    const double a = values.x, b = values.y, c = values.z;
    const double scale = std::sqrt(a * a + b * b + c * c);
    Check(std::fabs(y * c - z * b) < 1e-6 * scale && std::fabs(z * a - x * c) < 1e-6 * scale &&
              std::fabs(x * b - y * a) < 1e-6 * scale,
          "parallel to the input");
    Check(x * a + y * b + z * c > 0, "same direction as the input");
}
}

int main()
{
    // Hand-derived values: 3-4-5 and 1-2-2-3 triples.
    Case({3, 0, 4}, {0.6f, 0, 0.8f});
    Case({0, -3, 4}, {0, -0.6f, 0.8f});
    Case({1, 2, 2}, {1.0f / 3.0f, 2.0f / 3.0f, 2.0f / 3.0f});
    Case({-2, 0, 0}, {-1, 0, 0});
    Case({0, 0, 0.125f}, {0, 0, 1});
    // An already normalized axis is unchanged.
    Case({0, 1, 0}, {0, 1, 0});
    Identity({2, -1, 3});
    Identity({-0.001f, 250, 0.5f});

    // PROJECT CHOICE, not D3DX behaviour: the public reference does not state
    // the zero-length case. This function returns the zero vector.
    Case({0, 0, 0}, {0, 0, 0});
    // PROJECT CHOICE, not D3DX behaviour: the length is evaluated in double
    // precision, so these inputs normalize here. Their squares overflow or
    // underflow single precision, and what D3DX returns for them is not known.
    Case({0x1p127f, 0, 0}, {1, 0, 0});
    Case({0, -0x1p-140f, 0}, {0, -1, 0});
    Case({0x1p100f, 0, 0x1p100f}, {0.70710678f, 0, 0.70710678f});
    Identity({1e30f, -2e30f, 3e30f});
    Identity({1e-30f, 2e-30f, -3e-30f});

    std::puts("PASS vector3 normalize");
    return 0;
}
