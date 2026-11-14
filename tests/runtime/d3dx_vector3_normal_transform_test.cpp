#include "NiPoint3.h"
#include "fnv/d3dx_types.h"
#include "fnv/symbols_00ee6000.h"

#include <cstdio>
#include <cstdlib>
#include <memory>

namespace
{
using Entry = void* (*)(void*, const void*, const void*);
constexpr Entry TransformNormal = static_cast<Entry>(&FUN_00ee6df2);

void Check(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL vector3 normal transform: %s\n", message);
        std::exit(1);
    }
}

void Expect(const NiPoint3& actual, const NiPoint3& expected)
{
    Check(actual.x == expected.x && actual.y == expected.y && actual.z == expected.z,
          "three scalar results");
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
    NiPoint3 value{0, 0, 0};
    unsigned int after = 0x2468ace0;
};

void Case(const NiPoint3& values, const D3DXMATRIX& matrix, const NiPoint3& expected)
{
    Guarded input, output;
    input.value = values;
    const auto savedMatrix = matrix;
    auto* returned = static_cast<NiPoint3*>(TransformNormal(&output.value, &input.value, &matrix));
    Check(returned == &output.value, "exact borrowed output return");
    Expect(*returned, expected);
    Expect(input.value, values);
    ExpectMatrix(matrix, savedMatrix);
    returned = static_cast<NiPoint3*>(TransformNormal(&input.value, &input.value, &matrix));
    Check(returned == &input.value, "exact in-place return");
    Expect(*returned, expected);
    ExpectMatrix(matrix, savedMatrix);
    for (const auto* object : {&input, &output})
        Check(object->before == 0x13579bdf && object->after == 0x2468ace0,
              "ordinary adjacent canaries");
}
}

int main()
{
    // Independent literal oracles. Nonsymmetric upper-left values distinguish
    // row-vector multiplication from a transpose; nonunit results stay nonunit.
    const D3DXMATRIX dense{{.m = {{1, 2, 3, 4}, {-2, 1, -1, 3}, {5, -1, 2, 1}, {10, -20, 30, 2}}}};
    Case({2, -1, 3}, dense, {19, 0, 13});
    Case({-1, 2, 0.5f}, dense, {-2.5f, -0.5f, -4});
    Case({0, 1, 0}, dense, {-2, 1, -1});
    Case({0, 0, 0}, dense, {0, 0, 0});
    const D3DXMATRIX otherTranslation{{.m = {{1, 2, 3, -7}, {-2, 1, -1, 8}, {5, -1, 2, -9}, {-100, 200, -300, 4}}}};
    Case({2, -1, 3}, otherTranslation, {19, 0, 13});
    const D3DXMATRIX identity{{.m = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}};
    Case({-2.5f, 0.25f, 3}, identity, {-2.5f, 0.25f, 3});
    const D3DXMATRIX translatedIdentity{{.m = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {10, -20, 30, 1}}}};
    Case({2, -1, 3}, translatedIdentity, {2, -1, 3});
    const D3DXMATRIX scale{{.m = {{2, 0, 0, 0}, {0, -4, 0, 0}, {0, 0, 0.5f, 0}, {0, 0, 0, 1}}}};
    Case({-2.5f, 0.25f, 3}, scale, {-5, -1, 1.5f});
    const D3DXMATRIX zero{{.m = {}}};
    Case({2, -1, 3}, zero, {0, 0, 0});

    // Separate genuine public allocations expose an invented fourth input read
    // or output write to sanitizer redzones without inspecting object layouts.
    auto input = std::make_unique<NiPoint3>(NiPoint3{2, -1, 3});
    auto output = std::make_unique<NiPoint3>();
    auto matrix = std::make_unique<D3DXMATRIX>(dense);
    Check(static_cast<NiPoint3*>(TransformNormal(output.get(), input.get(), matrix.get())) == output.get(),
          "allocated output return");
    Expect(*output, {19, 0, 13});
    Expect(*input, {2, -1, 3});
    ExpectMatrix(*matrix, dense);
    Check(static_cast<NiPoint3*>(TransformNormal(input.get(), input.get(), matrix.get())) == input.get(),
          "allocated in-place return");
    Expect(*input, {19, 0, 13});
    ExpectMatrix(*matrix, dense);
    std::puts("PASS native vector3 normal transform: literal xyz, translation ignored, no normalization, exact return, preserved inputs, exact alias, canaries and allocation redzones");
}
