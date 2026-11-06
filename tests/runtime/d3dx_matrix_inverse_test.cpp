#include "fnv/symbols_00ee6000.h"

#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace
{
using Matrix = std::array<float, 16>;
constexpr Matrix identity = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
// H * diag(1,2,3,4), where H has orthogonal rows of length 2.
// Thus det = 16*24 = 384 and inverse = diag(1,1/2,1/3,1/4) * H^T/4.
constexpr Matrix dense = {1, 2, 3, 4, 1, -2, 3, -4, 1, 2, -3, -4, 1, -2, -3, 4};
constexpr Matrix denseInverse = {
    0.25f, 0.25f, 0.25f, 0.25f,
    0.125f, -0.125f, 0.125f, -0.125f,
    1.0f / 12, 1.0f / 12, -1.0f / 12, -1.0f / 12,
    0.0625f, -0.0625f, -0.0625f, 0.0625f};

void require(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL: %s\n", message);
        std::abort();
    }
}

void check_matrix(const Matrix& actual, const Matrix& expected)
{
    for (unsigned int i = 0; i < 16; ++i)
    {
        require(std::isfinite(actual[i]), "finite inverse element");
        const double error = std::fabs(double(actual[i]) - expected[i]);
        require(error <= 2e-6 * std::fabs(double(expected[i])), "literal inverse oracle");
    }
}

void check_residuals(const Matrix& source, const Matrix& inverse)
{
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
        {
            double left = 0, right = 0;
            for (unsigned int k = 0; k < 4; ++k)
            {
                left += double(source[row * 4 + k]) * inverse[k * 4 + column];
                right += double(inverse[row * 4 + k]) * source[k * 4 + column];
            }
            const double expected = row == column ? 1 : 0;
            require(std::fabs(left - expected) <= 2e-5, "A * inverse residual");
            require(std::fabs(right - expected) <= 2e-5, "inverse * A residual");
        }
}

struct GuardedMatrix
{
    std::array<unsigned char, 8> before{1, 3, 5, 7, 9, 11, 13, 15};
    Matrix matrix;
    std::array<unsigned char, 8> after{2, 4, 6, 8, 10, 12, 14, 16};
};
struct GuardedDeterminant
{
    float before = 123;
    float value = -987;
    float after = -456;
};

void success_case(const Matrix& input, const Matrix& expected, float expectedDeterminant)
{
    for (bool inPlace : {false, true})
        for (bool withDeterminant : {false, true})
        {
            const GuardedMatrix source{{1, 3, 5, 7, 9, 11, 13, 15}, input};
            const GuardedMatrix savedSource = source;
            GuardedMatrix destination{{1, 3, 5, 7, 9, 11, 13, 15}, input};
            const auto before = destination.before, after = destination.after;
            GuardedDeterminant determinant;
            const void* pM = inPlace ? destination.matrix.data() : source.matrix.data();
            void* pOut = destination.matrix.data();
            require(FUN_00ee6dda(pOut, withDeterminant ? &determinant.value : nullptr, pM) == pOut,
                    "success returns exact caller destination");
            check_matrix(destination.matrix, expected);
            check_residuals(input, destination.matrix);
            require(destination.before == before && destination.after == after, "destination bounds");
            require(source.before == savedSource.before && source.after == savedSource.after &&
                        std::memcmp(source.matrix.data(), savedSource.matrix.data(), sizeof(Matrix)) == 0,
                    "distinct source and source guards unchanged");
            require(determinant.before == 123 && determinant.after == -456, "determinant bounds");
            if (!withDeterminant)
                require(determinant.value == -987, "absent determinant is not written");
            else if (std::isinf(expectedDeterminant))
                require(determinant.value == expectedDeterminant, "determinant overflow narrows to signed infinity");
            else
                require(std::fabs(double(determinant.value) - expectedDeterminant) <=
                            2e-6 * std::fabs(double(expectedDeterminant)), "literal determinant oracle");
        }
}

void exact_sized_buffers()
{
    // Separate exact-sized objects give sanitizers redzones for reads as well
    // as writes; enclosing guard fields alone would not detect an overread.
    const Matrix source = dense;
    const Matrix savedSource = source;
    Matrix destination;
    float determinant;
    require(FUN_00ee6dda(destination.data(), &determinant, source.data()) == destination.data(),
            "exact-sized distinct destination identity");
    check_matrix(destination, denseInverse);
    require(determinant == 384 && source == savedSource, "exact-sized determinant and unchanged source");
    destination = dense;
    require(FUN_00ee6dda(destination.data(), nullptr, destination.data()) == destination.data(),
            "exact-sized in-place destination identity");
    check_matrix(destination, denseInverse);
}

void singular_cases()
{
    // Duplicate rows; no assertion about undocumented singular destination contents.
    const Matrix singular = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, -3, -4, 1, -2, -3, 4};
    // The third row equals the first plus the second; no duplicate rows.
    const Matrix dependent = {1, 2, 3, 0, 4, 5, 6, 0, 5, 7, 9, 0, 0, 0, 0, 1};
    const Matrix dependentLastRow = {1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 10, 11, 5, 7, 9, 11};
    const Matrix dependentCases[] = {
        singular, Matrix{}, dependent, dependentLastRow,
        {3, 1, 2, 0, 1, 4, 5, 0, 4, 5, 7, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 2, 3, 5, 0, 3, 4, 6, 0, 0, 0, 0, 1},
        {2, 3, 5, 0, 7, 11, 13, 0, 9, 14, 18, 0, 0, 0, 0, 1}};
    // All row relations remain exact when these small integers are scaled by
    // powers of two, including the smallest subnormal unit and large normals.
    for (const Matrix& unscaled : dependentCases)
        for (int exponent : {0, -149, -120, 120})
        {
            Matrix matrix;
            for (unsigned int i = 0; i < 16; ++i)
                matrix[i] = std::ldexp(unscaled[i], exponent);
            for (bool inPlace : {false, true})
                for (bool withDeterminant : {false, true})
                {
                    const GuardedMatrix source{{1, 3, 5, 7, 9, 11, 13, 15}, matrix};
                    GuardedMatrix destination{{1, 3, 5, 7, 9, 11, 13, 15}, matrix};
                    const auto before = destination.before, after = destination.after;
                    GuardedDeterminant determinant;
                    const void* pM = inPlace ? destination.matrix.data() : source.matrix.data();
                    require(FUN_00ee6dda(destination.matrix.data(), withDeterminant ? &determinant.value : nullptr, pM) == nullptr,
                            "singular inversion returns nullptr, not default success");
                    require(destination.before == before && destination.after == after, "singular destination bounds");
                    require(source.matrix == matrix, "singular distinct source unchanged");
                    require(determinant.before == 123 && determinant.after == -456, "singular determinant bounds");
                    if (withDeterminant)
                        require(determinant.value == 0, "singular determinant is zero");
                }
        }
    // Independently scale columns, so a single input mixes subnormal and
    // large normal exponents while preserving row 2 = row 0 + row 1 exactly.
    const float unit = std::ldexp(1.0f, -149);
    const Matrix mixed = {unit, 0x1p121f, 3, 0, 4 * unit, 5 * 0x1p120f, 6, 0,
                          5 * unit, 7 * 0x1p120f, 9, 0, 0, 0, 0, 1};
    for (bool inPlace : {false, true})
        for (bool withDeterminant : {false, true})
        {
            Matrix output = mixed;
            float determinant = -987;
            require(FUN_00ee6dda(output.data(), withDeterminant ? &determinant : nullptr,
                                inPlace ? output.data() : mixed.data()) == nullptr,
                    "mixed-exponent dependent rows are singular");
            if (withDeterminant)
                require(determinant == 0, "mixed-exponent singular determinant");
        }
}
}

int main()
{
    success_case(identity, identity, 1);
    std::puts("PASS: identity, optional determinant, distinct/exact-in-place return and bounds");
    success_case({-2, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0.5f, 0, 0, 0, 0, -8},
                 {-0.5f, 0, 0, 0, 0, 0.25f, 0, 0, 0, 0, 2, 0, 0, 0, 0, -0.125f}, 32);
    std::puts("PASS: non-unit signed diagonal literal inverse and determinant");
    success_case(dense, denseInverse, 384);
    std::puts("PASS: fully populated asymmetric literal inverse/determinant and two-sided residuals");
    success_case({0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                 {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, -1);
    success_case({0, 2, 0, 0, -3, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0.5f},
                 {0, -1.0f / 3, 0, 0, 0.5f, 0, 0, 0, 0, 0, 0.25f, 0, 0, 0, 0, 2}, 12);
    std::puts("PASS: zero-leading pivot, row permutation and determinant sign");
    singular_cases();
    std::puts("PASS: singular failure, determinant, distinct/exact-in-place and bounds");
    exact_sized_buffers();
    std::puts("PASS: exact 64-byte matrix and single-float determinant objects");
    for (int exponent : {-120, -40, -20, 20, 40, 120})
    {
        Matrix source, expected;
        for (unsigned int i = 0; i < 16; ++i)
        {
            source[i] = std::ldexp(dense[i], exponent);
            expected[i] = std::ldexp(denseInverse[i], -exponent);
        }
        // At the extreme scales the determinant narrows to zero/infinity;
        // inversion must not use that narrowed determinant as a singularity test.
        const float determinant = exponent <= -40 ? 0.0f :
            exponent >= 40 ? HUGE_VALF : std::ldexp(384.0f, 4 * exponent);
        success_case(source, expected, determinant);
    }
    std::puts("PASS: well-conditioned small/large finite scales, determinant narrowing independent of success");
}
