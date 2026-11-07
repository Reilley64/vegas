#include "fnv/d3dx_types.h"
#include "fnv/symbols_00ee6000.h"

#include <cstdio>
#include <cstdlib>
#include <memory>
#include <type_traits>

namespace
{
using Entry = D3DXVECTOR4* (*)(D3DXVECTOR4*, const D3DXVECTOR4*, const D3DXMATRIX*);
static_assert(std::is_same_v<decltype(&FUN_00ee6e34), Entry>);

void Check(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL vector4 transform: %s\n", message);
        std::exit(1);
    }
}

void Expect(const D3DXVECTOR4& actual, const D3DXVECTOR4& expected)
{
    Check(actual.x == expected.x && actual.y == expected.y &&
          actual.z == expected.z && actual.w == expected.w, "all four scalar results");
}

D3DXMATRIX DenseMatrix()
{
    return {{.m = {{1, 2, 3, 4}, {-2, 1, -1, 3}, {5, -1, 2, 1}, {1, 3, -2, 1}}}};
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
    D3DXVECTOR4 value{0, 0, 0, 0};
    unsigned int after = 0x2468ace0;
};

void Case(const D3DXVECTOR4& values, const D3DXMATRIX& matrix, const D3DXVECTOR4& expected)
{
    Guarded input, output;
    input.value = values;
    const auto savedMatrix = matrix;
    Check(FUN_00ee6e34(&output.value, &input.value, &matrix) == &output.value, "exact output pointer return");
    Expect(output.value, expected);
    Expect(input.value, values);
    ExpectMatrix(matrix, savedMatrix);
    Check(FUN_00ee6e34(&input.value, &input.value, &matrix) == &input.value, "exact input/output alias return");
    Expect(input.value, expected);
    ExpectMatrix(matrix, savedMatrix);
    for (const auto* object : {&input, &output})
        Check(object->before == 0x13579bdf && object->after == 0x2468ace0, "ordinary adjacent canaries");
}
}

int main()
{
    const auto dense = DenseMatrix();
    // Literal row-vector results; the nonsymmetric matrix distinguishes columns
    // from rows. Nonunit output w must neither divide xyz nor become one.
    Case({2, -1, 3, 4}, dense, {23, 12, 5, 12});
    Case({2, -1, 3, 0}, dense, {19, 0, 13, 8});
    Case({2, -1, 3, 1}, dense, {20, 3, 11, 9});
    Case({0, 0, 0, 2}, dense, {2, 6, -4, 2});
    Case({0, 0, 1, 0}, dense, {5, -1, 2, 1});
    Case({0, 0, 0, 0}, dense, {0, 0, 0, 0});
    const D3DXMATRIX identity{{.m = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}};
    Case({-2.5f, 0.25f, 3, -4}, identity, {-2.5f, 0.25f, 3, -4});
    const D3DXMATRIX scale{{.m = {{2, 0, 0, 0}, {0, -4, 0, 0}, {0, 0, 0.5f, 0}, {0, 0, 0, 8}}}};
    Case({-2.5f, 0.25f, 3, -4}, scale, {-5, -1, 1.5f, -32});
    const D3DXMATRIX affine{{.m = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {10, -20, 30, 1}}}};
    Case({2, -1, 3, 0}, affine, {2, -1, 3, 0});
    Case({2, -1, 3, 2}, affine, {22, -41, 63, 2});

    // Separate genuine public objects expose overrun/overread to ASan without
    // asserting their layout or manufacturing larger fake operand storage.
    auto input = std::make_unique<D3DXVECTOR4>(2, -1, 3, 4);
    auto output = std::make_unique<D3DXVECTOR4>();
    auto matrix = std::make_unique<D3DXMATRIX>(dense);
    Check(FUN_00ee6e34(output.get(), input.get(), matrix.get()) == output.get(), "allocated output return");
    Expect(*output, {23, 12, 5, 12});
    Expect(*input, {2, -1, 3, 4});
    ExpectMatrix(*matrix, dense);
    Check(FUN_00ee6e34(input.get(), input.get(), matrix.get()) == input.get(), "allocated exact alias return");
    Expect(*input, {23, 12, 5, 12});
    ExpectMatrix(*matrix, dense);
    std::puts("PASS native vector4 transform: literal row-vector/w results, exact return, preserved inputs, exact alias, canaries and allocation redzones");
}
