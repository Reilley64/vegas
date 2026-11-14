#include "fnv/symbols_00ee6000.h"

#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <limits>

namespace
{
using Matrix = std::array<float, 16>;
static_assert(sizeof(Matrix) == 64);
constexpr Matrix identity = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
constexpr Matrix first = {1, 2, 3, 4, 1, -2, 3, -4, 1, 2, -3, -4, 1, -2, -3, 4};
constexpr Matrix second = {2, -1, 0.5f, 3, -2, 4, 1, -0.5f, 3, 0.25f, -1, 2, 1, -3, 2, 4};
// Independent literal dot products of the two asymmetric matrices, in both orders.
// All fixture products are exactly representable dyadics: no tolerance can hide
// wrong order, transpose, signs or zero entries. This is not an SDK bit oracle.
constexpr Matrix product = {11, -4.25f, 7.5f, 24, 11, 3.75f, -12.5f, -6,
                            -15, 18.25f, -2.5f, -20, 1, -21.75f, 9.5f, 14};
constexpr Matrix reverseProduct = {4.5f, 1, -7.5f, 22, 2.5f, -9, 4.5f, -30,
                                   4.25f, -0.5f, 6.75f, 23, 4, 4, -24, 24};
constexpr Matrix squared = {10, -4, -12, 0, -2, 20, 0, -16, -4, 0, 30, -8, 0, -8, -6, 40};

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
        require(std::isfinite(actual[i]) && actual[i] == expected[i], "exact finite literal product element");
}

struct GuardedMatrix
{
    std::array<unsigned char, 8> before{1, 3, 5, 7, 9, 11, 13, 15};
    Matrix matrix;
    std::array<unsigned char, 8> after{2, 4, 6, 8, 10, 12, 14, 16};
};

void check_guards(const GuardedMatrix& actual, const GuardedMatrix& saved)
{
    require(actual.before == saved.before && actual.after == saved.after, "source/output guards unchanged");
}

void success_case(const Matrix& left, const Matrix& right, const Matrix& expected)
{
    // Distinct output, exact output==left and exact output==right.
    for (unsigned int alias = 0; alias < 3; ++alias)
    {
        GuardedMatrix a{{1, 3, 5, 7, 9, 11, 13, 15}, left};
        GuardedMatrix b{{1, 3, 5, 7, 9, 11, 13, 15}, right};
        GuardedMatrix destination{{1, 3, 5, 7, 9, 11, 13, 15}, second};
        const auto savedA = a, savedB = b, savedDestination = destination;
        Matrix& output = alias == 1 ? a.matrix : alias == 2 ? b.matrix : destination.matrix;
        require(FUN_00ee6de0(output.data(), a.matrix.data(), b.matrix.data()) == output.data(),
                "returns exact output pointer for distinct/left/right alias");
        check_matrix(output, expected);
        check_guards(a, savedA);
        check_guards(b, savedB);
        check_guards(destination, savedDestination);
        if (alias != 1)
            require(std::memcmp(a.matrix.data(), savedA.matrix.data(), sizeof(Matrix)) == 0, "left source unchanged");
        if (alias != 2)
            require(std::memcmp(b.matrix.data(), savedB.matrix.data(), sizeof(Matrix)) == 0, "right source unchanged");
        if (alias != 0)
            require(destination.matrix == savedDestination.matrix, "unused destination unchanged");
    }
}

void exact_sized_and_representation_buffers()
{
    // Separate exact-size heap objects give ASan redzones for reads and writes;
    // guard fields alone would miss a read beyond a matrix inside its wrapper.
    auto a = std::make_unique<Matrix>(first);
    auto b = std::make_unique<Matrix>(second);
    auto out = std::make_unique<Matrix>();
    require(FUN_00ee6de0(out->data(), a->data(), b->data()) == out->data(), "exact-size return");
    check_matrix(*out, product);
    require(*a == first && *b == second, "exact-size sources unchanged");
    require(FUN_00ee6de0(a->data(), a->data(), b->data()) == a->data(), "exact-size left alias return");
    check_matrix(*a, product);
    *a = first;
    require(FUN_00ee6de0(b->data(), a->data(), b->data()) == b->data(), "exact-size right alias return");
    check_matrix(*b, product);
    require(FUN_00ee6de0(a->data(), a->data(), a->data()) == a->data(), "all-three-same exact-size return");
    check_matrix(*a, squared);

    // The public void-pointer seam borrows representations, not a matrix class.
    // Byte-aligned storage must not require type-punning or float alignment.
    std::array<unsigned char, 66> bytesA{}, bytesB{}, bytesOut{};
    bytesA.front() = bytesB.front() = bytesOut.front() = 123;
    bytesA.back() = bytesB.back() = bytesOut.back() = 231;
    std::memcpy(bytesA.data() + 1, first.data(), sizeof(Matrix));
    std::memcpy(bytesB.data() + 1, second.data(), sizeof(Matrix));
    const auto savedA = bytesA, savedB = bytesB;
    void* output = bytesOut.data() + 1;
    require(FUN_00ee6de0(output, bytesA.data() + 1, bytesB.data() + 1) == output, "representation return");
    Matrix result;
    std::memcpy(result.data(), output, sizeof(result));
    check_matrix(result, product);
    require(bytesA == savedA && bytesB == savedB, "source representations and bounds unchanged");
    require(bytesOut.front() == 123 && bytesOut.back() == 231, "representation output bounds");
}

// This fixture specifies binary32 accuracy, not exact elimination bits. One
// binary32 ULP at the largest literal oracle magnitude gives an absolute error
// budget that remains meaningful at mathematical zeros. It is a fixture
// criterion, not a universal inverse-accuracy or original-library guarantee.
void check_pipeline_oracle(const Matrix& actual, const Matrix& expected)
{
    float scale = 0;
    for (float value : expected)
        if (std::fabs(value) > scale)
            scale = std::fabs(value);
    const double tolerance = double(std::nextafter(scale, std::numeric_limits<float>::infinity())) - scale;
    require(scale > 0 && std::isfinite(tolerance), "finite nonzero pipeline oracle scale");
    for (unsigned int i = 0; i < 16; ++i)
        require(std::isfinite(actual[i]) && std::fabs(double(actual[i]) - expected[i]) <= tolerance,
                "pipeline inverse accuracy against independent literal oracle");
}

void check_pipeline_residuals(const Matrix& source, const Matrix& inverse)
{
    double sourceNorm = 0, inverseNorm = 0;
    for (unsigned int row = 0; row < 4; ++row)
    {
        double sourceRow = 0, inverseRow = 0;
        for (unsigned int column = 0; column < 4; ++column)
        {
            sourceRow += std::fabs(double(source[row * 4 + column]));
            inverseRow += std::fabs(double(inverse[row * 4 + column]));
        }
        if (sourceRow > sourceNorm)
            sourceNorm = sourceRow;
        if (inverseRow > inverseNorm)
            inverseNorm = inverseRow;
    }
    // Independent two-sided inverse identity, evaluated in double. Require a
    // binary32 epsilon normalized backward error for this finite fixture.
    const double budget = std::numeric_limits<float>::epsilon() * sourceNorm * inverseNorm;
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
            require(std::isfinite(left) && std::fabs(left - expected) <= budget, "pipeline product * inverse residual");
            require(std::isfinite(right) && std::fabs(right - expected) <= budget, "pipeline inverse * product residual");
        }
}

void pipeline()
{
    // Shear/scale/translation followed by a nonuniform scale. Their noncommuting
    // product and inverse-transpose follow exact triangular substitution, not
    // another call to the multiply implementation or a cloned runtime oracle.
    const Matrix view = {1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 3, 4, 5, 1};
    const Matrix projection = {2, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0.5f, 0, 0, 0, 0, 1};
    const Matrix expectedProduct = {2, 8, 0, 0, 0, 4, 0, 0, 0, 0, 1, 0, 6, 16, 2.5f, 1};
    const Matrix expectedInverse = {0.5f, -1, 0, 0, 0, 0.25f, 0, 0, 0, 0, 1, 0, -3, 2, -2.5f, 1};
    const Matrix expectedTranspose = {0.5f, 0, 0, -3, -1, 0.25f, 0, 2, 0, 0, 1, -2.5f, 0, 0, 0, 1};
    GuardedMatrix combined{{1, 3, 5, 7, 9, 11, 13, 15}, second};
    const auto saved = combined;
    require(FUN_00ee6de0(combined.matrix.data(), view.data(), projection.data()) == combined.matrix.data(),
            "pipeline multiply return");
    check_matrix(combined.matrix, expectedProduct);
    float determinant = -1;
    require(FUN_00ee6dda(combined.matrix.data(), &determinant, combined.matrix.data()) == combined.matrix.data(),
            "pipeline accepted inverse exact-in-place return");
    require(determinant == 8, "pipeline independent determinant");
    check_pipeline_oracle(combined.matrix, expectedInverse);
    check_pipeline_residuals(expectedProduct, combined.matrix);
    const Matrix inverseBeforeTranspose = combined.matrix;
    // Literal transpose index permutation additionally requires bit preservation
    // of the actual inverse, so numerical tolerance cannot hide a bad transpose.
    const Matrix permutedInverse = {
        inverseBeforeTranspose[0], inverseBeforeTranspose[4], inverseBeforeTranspose[8], inverseBeforeTranspose[12],
        inverseBeforeTranspose[1], inverseBeforeTranspose[5], inverseBeforeTranspose[9], inverseBeforeTranspose[13],
        inverseBeforeTranspose[2], inverseBeforeTranspose[6], inverseBeforeTranspose[10], inverseBeforeTranspose[14],
        inverseBeforeTranspose[3], inverseBeforeTranspose[7], inverseBeforeTranspose[11], inverseBeforeTranspose[15]};
    require(FUN_00ee6dd4(combined.matrix.data(), combined.matrix.data()) == combined.matrix.data(),
            "pipeline accepted transpose exact-in-place return");
    check_pipeline_oracle(combined.matrix, expectedTranspose);
    require(std::memcmp(combined.matrix.data(), permutedInverse.data(), sizeof(Matrix)) == 0,
            "pipeline transpose preserves actual inverse representations exactly");
    check_guards(combined, saved);
}
}

int main()
{
    success_case(first, second, product);
    success_case(second, first, reverseProduct);
    success_case(first, first, squared);
    std::puts("PASS: literal asymmetric dense products in both orders, square, return, alias and source/output guards");
    success_case(first, identity, first);
    success_case(identity, second, second);
    success_case(first, Matrix{}, Matrix{});
    success_case(Matrix{}, second, Matrix{});
    success_case({-2, 0, 0, 0, 0, 0.5f, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0.25f}, first,
                 {-2, -4, -6, -8, 0.5f, -1, 1.5f, -2, -4, -8, 12, 16, 0.25f, -0.5f, -0.75f, 1});
    std::puts("PASS: two-sided identity/zero and signed fractional nonuniform scale");
    for (const auto& exponents : {std::array{60, 60}, std::array{-60, -60},
                                  std::array{120, -120}, std::array{-120, 120}, std::array{-70, -70}})
    {
        Matrix a, b, expected;
        for (unsigned int i = 0; i < 16; ++i)
        {
            a[i] = std::ldexp(first[i], exponents[0]);
            b[i] = std::ldexp(second[i], exponents[1]);
            expected[i] = std::ldexp(product[i], exponents[0] + exponents[1]);
        }
        success_case(a, b, expected);
    }
    std::puts("PASS: small/large finite scales, reciprocal scales and exact subnormal products");
    GuardedMatrix same{{1, 3, 5, 7, 9, 11, 13, 15}, first};
    const auto savedSame = same;
    require(FUN_00ee6de0(same.matrix.data(), same.matrix.data(), same.matrix.data()) == same.matrix.data(),
            "guarded all-three-same return");
    check_matrix(same.matrix, squared);
    check_guards(same, savedSame);
    exact_sized_and_representation_buffers();
    std::puts("PASS: all-three-same, exact-size redzone fixtures and byte representations");
    pipeline();
    std::puts("PASS: real public multiply -> accepted inverse -> transpose literal pipeline");
}
