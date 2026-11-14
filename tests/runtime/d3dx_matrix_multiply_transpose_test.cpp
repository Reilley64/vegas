#include "fnv/symbols_00ee6000.h"
#include "gamebryo2.2/corelibs/niconsolerenderer/niconsolerenderer_types_NiConsoleRenderer.h"

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <type_traits>

namespace
{
using Values = std::array<float, 16>;
using Entry = D3DXMATRIX* (*)(D3DXMATRIX*, const D3DXMATRIX*, const D3DXMATRIX*);
static_assert(std::is_same_v<decltype(&FUN_00ee6dfe), Entry>);

void Check(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL multiply-transpose: %s\n", message);
        std::exit(1);
    }
}

D3DXMATRIX Matrix(const Values& values)
{
    // Initialize and subsequently read the same array member of the real union.
    D3DXMATRIX result{{.m = {}}};
    for (unsigned int r = 0; r < 4; ++r)
        for (unsigned int c = 0; c < 4; ++c)
            result.m[r][c] = values[4 * r + c];
    return result;
}

void Expect(const D3DXMATRIX& actual, const Values& expected)
{
    for (unsigned int r = 0; r < 4; ++r)
        for (unsigned int c = 0; c < 4; ++c)
            Check(actual.m[r][c] == expected[4 * r + c], "exact scalar result (including mathematical zeros)");
}

constexpr Values first{1, 2, 3, 4, -2, 1, -1, 3, 5, -1, 2, 1, 1, 3, -2, 1};
constexpr Values second{2, -1, 4, 1, 1, 3, -2, 5, -3, 2, 1, 4, 4, -2, -1, 2};
// Independently worked integer product rows are (11,3,-1,31), (12,-3,-14,5),
// (7,-6,23,10), (15,2,-5,10). Literal oracle below is their transpose.
constexpr Values denseExpected{11, 12, 7, 15, 3, -3, -6, 2, -1, -14, 23, -5, 31, 5, 10, 10};

struct Guarded
{
    std::uint32_t before = 0x13579bdf;
    D3DXMATRIX matrix = Matrix({});
    std::uint32_t after = 0x2468ace0;
};

void DenseDistinct()
{
    Guarded a, b, out;
    a.matrix = Matrix(first);
    b.matrix = Matrix(second);
    const auto aBefore = a.matrix;
    const auto bBefore = b.matrix;
    Check(FUN_00ee6dfe(&out.matrix, &a.matrix, &b.matrix) == &out.matrix, "exact output return");
    Expect(out.matrix, denseExpected);
    Check(std::memcmp(&a.matrix, &aBefore, 64) == 0 && std::memcmp(&b.matrix, &bBefore, 64) == 0, "independent inputs unchanged");
    for (const auto* p : {&a, &b, &out})
        Check(p->before == 0x13579bdf && p->after == 0x2468ace0, "adjacent canaries");
}

void ExactCase(const Values& aValues, const Values& bValues, const Values& expected)
{
    auto a = Matrix(aValues);
    auto b = Matrix(bValues);
    auto out = Matrix({});
    const auto aBefore = a;
    const auto bBefore = b;
    Check(FUN_00ee6dfe(&out, &a, &b) == &out, "exact case return");
    Expect(out, expected);
    Check(std::memcmp(&a, &aBefore, 64) == 0 && std::memcmp(&b, &bBefore, 64) == 0, "exact case independent inputs");
}

void IdentityAndZero()
{
    constexpr Values identity{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    constexpr Values zero{};
    constexpr Values firstTranspose{1, -2, 5, 1, 2, 1, -1, 3, 3, -1, 2, -2, 4, 3, 1, 1};
    ExactCase(first, identity, firstTranspose);
    ExactCase(identity, first, firstTranspose);
    ExactCase(first, zero, zero);
    ExactCase(zero, second, zero);
}

void ScaleAndPermutation()
{
    constexpr Values scale{-0.5f, 0, 0, 0, 0, 2, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0.25f};
    // Right scaling scales columns before transpose; left scaling scales rows.
    ExactCase(first, scale, {-0.5f, 1, -2.5f, -0.5f, 4, 2, -2, 6, -12, 4, -8, 8, 1, 0.75f, 0.25f, 0.25f});
    ExactCase(scale, first, {-0.5f, -4, -20, 0.25f, -1, 2, 4, 0.75f, -1.5f, -2, -8, -0.5f, -2, 6, -4, 0.25f});
    constexpr Values permutation{0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0};
    ExactCase(first, permutation, {4, 3, 1, 1, 1, -2, 5, 1, 2, 1, -1, 3, 3, -1, 2, -2});
    ExactCase(permutation, first, {-2, 5, 1, 1, 1, -1, 3, 2, -1, 2, -2, 3, 3, 1, 1, 4});
    // Dyadic orthogonal rows: equal inputs cancel exactly off the diagonal.
    constexpr Values halfHadamard{0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f,
                                 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f};
    ExactCase(halfHadamard, halfHadamard, {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
}

void ExactAliases()
{
    Guarded a, b, out;
    a.matrix = Matrix(first);
    b.matrix = Matrix(second);
    Check(FUN_00ee6dfe(&a.matrix, &a.matrix, &b.matrix) == &a.matrix, "out aliases first return");
    Expect(a.matrix, denseExpected);
    Expect(b.matrix, second);
    a.matrix = Matrix(first);
    Check(FUN_00ee6dfe(&b.matrix, &a.matrix, &b.matrix) == &b.matrix, "out aliases second return");
    Expect(b.matrix, denseExpected);
    Expect(a.matrix, first);
    // Literal transpose of the independently worked square, not a public composition oracle.
    constexpr Values square{16, -6, 18, -14, 13, 7, 10, 10, -1, -15, 18, -6, 17, -3, 20, 12};
    Check(FUN_00ee6dfe(&out.matrix, &a.matrix, &a.matrix) == &out.matrix, "equal inputs return");
    Expect(out.matrix, square);
    Expect(a.matrix, first);
    Check(FUN_00ee6dfe(&a.matrix, &a.matrix, &a.matrix) == &a.matrix, "alias-all return");
    Expect(a.matrix, square);
    for (const auto* p : {&a, &b, &out})
        Check(p->before == 0x13579bdf && p->after == 0x2468ace0, "alias canaries");
}

void ExactSizeRedzones()
{
    // Separately allocated real objects give ASan a redzone around each object.
    auto a = std::make_unique<D3DXMATRIX>(Matrix(first));
    auto b = std::make_unique<D3DXMATRIX>(Matrix(second));
    auto out = std::make_unique<D3DXMATRIX>(Matrix({}));
    Check(FUN_00ee6dfe(out.get(), a.get(), b.get()) == out.get(), "exact-size return");
    Expect(*out, denseExpected);
    Expect(*a, first);
    Expect(*b, second);
    Check(FUN_00ee6dfe(a.get(), a.get(), b.get()) == a.get(), "exact-size alias return");
    Expect(*a, denseExpected);
    Expect(*b, second);
}
}

int main()
{
    DenseDistinct();
    IdentityAndZero();
    ScaleAndPermutation();
    ExactAliases();
    ExactSizeRedzones();
    std::puts("PASS genuine D3DXMATRIX multiply-transpose: exact order/transpose/return/input preservation/aliases/canaries/allocation redzones");
}
