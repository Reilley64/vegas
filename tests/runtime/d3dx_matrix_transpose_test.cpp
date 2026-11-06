#include "fnv/symbols_00ee6000.h"

#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace
{
using Matrix = std::array<float, 16>;

void require(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL: %s\n", message);
        std::abort();
    }
}

void asymmetric_out_of_place()
{
    const Matrix source = {
        1, -2, 3, 4,
        5, 6, -7, 8,
        9, 10, 11, -12,
        -13, 14, 15, 16};
    const Matrix expected = {
        1, 5, 9, -13,
        -2, 6, 10, 14,
        3, -7, 11, 15,
        4, 8, -12, 16};
    const Matrix unchanged = source;
    Matrix destination{};
    require(FUN_00ee6dd4(destination.data(), source.data()) == destination.data(),
            "returns caller destination");
    require(destination == expected, "asymmetric matrix transpose");
    require(std::memcmp(source.data(), unchanged.data(), sizeof(source)) == 0,
            "out-of-place source is unchanged");
}

void asymmetric_in_place()
{
    Matrix matrix = {
        1, -2, 3, 4,
        5, 6, -7, 8,
        9, 10, 11, -12,
        -13, 14, 15, 16};
    const Matrix expected = {
        1, 5, 9, -13,
        -2, 6, 10, 14,
        3, -7, 11, 15,
        4, 8, -12, 16};
    require(FUN_00ee6dd4(matrix.data(), matrix.data()) == matrix.data(),
            "returns in-place destination");
    require(matrix == expected, "asymmetric in-place transpose");
}

void identity_and_diagonal()
{
    const Matrix identity = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1};
    Matrix destination{};
    require(FUN_00ee6dd4(destination.data(), identity.data()) == destination.data(),
            "returns identity destination");
    require(destination == identity, "identity stays identity");

    Matrix diagonal = {
        -3, 0, 0, 0,
        0, 2.5f, 0, 0,
        0, 0, 7, 0,
        0, 0, 0, -0.25f};
    const Matrix expected = {
        -3, 0, 0, 0,
        0, 2.5f, 0, 0,
        0, 0, 7, 0,
        0, 0, 0, -0.25f};
    require(FUN_00ee6dd4(diagonal.data(), diagonal.data()) == diagonal.data(),
            "returns diagonal destination");
    require(diagonal == expected, "diagonal stays diagonal in place");
}

void caller_buffer_bounds()
{
    struct GuardedMatrix
    {
        std::array<unsigned char, 8> before;
        Matrix matrix;
        std::array<unsigned char, 8> after;
    };
    const GuardedMatrix source = {
        {0x13, 0x24, 0x35, 0x46, 0x57, 0x68, 0x79, 0x8a},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
        {0x8a, 0x79, 0x68, 0x57, 0x46, 0x35, 0x24, 0x13}};
    GuardedMatrix destination = {
        {0x91, 0x82, 0x73, 0x64, 0x55, 0x46, 0x37, 0x28},
        {},
        {0x28, 0x37, 0x46, 0x55, 0x64, 0x73, 0x82, 0x91}};
    const auto before = destination.before;
    const auto after = destination.after;
    const Matrix expected = {
        1, 5, 9, 13,
        2, 6, 10, 14,
        3, 7, 11, 15,
        4, 8, 12, 16};
    const GuardedMatrix unchanged = source;
    require(FUN_00ee6dd4(destination.matrix.data(), source.matrix.data()) ==
                destination.matrix.data(), "returns guarded destination");
    require(destination.matrix == expected, "guarded matrix transpose");
    require(destination.before == before && destination.after == after,
            "out-of-place writes stay in destination matrix");
    require(source.before == unchanged.before && source.matrix == unchanged.matrix &&
                source.after == unchanged.after, "guarded source unchanged");

    destination.matrix = source.matrix;
    require(FUN_00ee6dd4(destination.matrix.data(), destination.matrix.data()) ==
                destination.matrix.data(), "returns guarded in-place destination");
    require(destination.matrix == expected, "guarded in-place transpose");
    require(destination.before == before && destination.after == after,
            "in-place writes stay in destination matrix");
}
}

int main()
{
    asymmetric_out_of_place();
    std::puts("PASS: asymmetric distinct buffers, unchanged source, return identity");
    asymmetric_in_place();
    std::puts("PASS: asymmetric exact in-place and return identity");
    identity_and_diagonal();
    std::puts("PASS: identity and non-unit diagonal");
    caller_buffer_bounds();
    std::puts("PASS: source and destination bounds, distinct and exact in-place");
}
