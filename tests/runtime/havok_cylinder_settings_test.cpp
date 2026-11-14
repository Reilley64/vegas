#include "havok/CylinderSettings.h"
#include "havok/ScalarConstants.h"

#include <bit>
#include <cstdint>
#include <cstdio>
#include <type_traits>

static_assert(std::is_same_v<decltype(DAT_0101ffa0), const double>);
static_assert(std::is_same_v<decltype(DAT_010d0f08), double>);
static_assert(std::is_same_v<decltype(DAT_011b5be0), float>);
static_assert(std::is_same_v<decltype(DAT_011b5be4), float>);
static_assert(std::is_same_v<decltype(&ComputeByteScale), void (*)(int)>);

namespace {
struct Example
{
    int bits;
    std::uint32_t factor;
    std::uint32_t reciprocal;
};

bool check(const Example& example)
{
    ComputeByteScale(example.bits);
    if (std::bit_cast<std::uint32_t>(DAT_011b5be0) == example.factor &&
        std::bit_cast<std::uint32_t>(DAT_011b5be4) == example.reciprocal) return true;
    std::fprintf(stderr, "bits=%d: got %08x/%08x, expected %08x/%08x\n", example.bits,
        std::bit_cast<std::uint32_t>(DAT_011b5be0), std::bit_cast<std::uint32_t>(DAT_011b5be4),
        example.factor, example.reciprocal);
    return false;
}
} // namespace

int main()
{
    if (DAT_011b5be0 != 2.6874115f || DAT_011b5be4 != 0.37210527f ||
        DAT_010d0f08 != 0.7070000171661377 || DAT_0101ffa0 != 0.10000000149011612) return 1;

    // Literal nearest-even binary32 answers from exact rational input values,
    // including reciprocal rounding AFTER the first float store. No production
    // expression or shared value is used to compute the expected results here.
    const Example defaults[] = {
        {0, 0xbe10d65c, 0xc0e23d71}, {7, 0xbe10d65c, 0xc0e23d71},
        {-7, 0xbe10d65c, 0xc0e23d71},
        {8, 0x3fa2f127, 0x3f491a2c}, {15, 0x3fa2f127, 0x3f491a2c},
        {16, 0x402bfe8d, 0x3ebe8495}, {23, 0x402bfe8d, 0x3ebe8495},
        {24, 0x40834243, 0x3e79a4e7}, {32, 0x40b08540, 0x3e39a201},
        {64, 0x4132c899, 0x3db74876}, {120, 0x41a89987, 0x3d425a94},
        {-8, 0xbfc726be, 0xbf2489c7}, {-15, 0xbfc726be, 0xbf2489c7},
        {-16, 0xc03e1958, 0xbeac5f93}
    };
    for (const auto& example : defaults) if (!check(example)) return 2;

    const double savedInput = DAT_010d0f08;
    DAT_010d0f08 = 1.0;
    const bool mutableInputObserved = check({8, 0x3f666666, 0x3f8e38e4}) &&
        check({16, 0x3ff33333, 0x3f06bca2}) && check({24, 0x4039999a, 0x3eb08d3d});
    DAT_010d0f08 = savedInput;
    if (!mutableInputObserved) return 3;
    if (!check({16, 0x402bfe8d, 0x3ebe8495})) return 4;
    if (DAT_010d0f08 != 0.7070000171661377 || DAT_0101ffa0 != 0.10000000149011612) return 5;
    std::puts("Real cylinder producer: defaults, integer truncation, exact float/reciprocal rounding, mutable input and restoration passed");
}
