// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00ee6000.h"

#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <limits>
#include <utility>

// Native transpose of a 4x4 float matrix into caller-owned storage.
// @fnv 0x00ee6dd4
void* FUN_00ee6dd4(void* pOut, const void* pM)
{
    static_assert(sizeof(float) == 4);
    // Stage every element before writing pOut so exact in-place calls are safe.
    // Copy representations rather than aliasing the callers' matrix structs.
    unsigned char transposed[16 * sizeof(float)];
    const auto* source = static_cast<const unsigned char*>(pM);
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            std::memcpy(transposed + (row * 4 + column) * sizeof(float),
                        source + (column * 4 + row) * sizeof(float), sizeof(float));
    std::memcpy(pOut, transposed, sizeof(transposed));
    return pOut;
}

namespace
{
// Exact zero classification for a finite binary32 matrix, not a numerical
// tolerance. Every element is an integer mantissa times a power of two.
// Four-element products lie on the 2^-596 lattice and have magnitude <2^512.
// After alignment each product needs at most 1108 bits; summing all 24 signed
// determinant terms needs at most 1113 bits. 35 words hold 1120 bits, so these
// unsigned accumulators cannot overflow. No dynamic integer storage is needed.
bool HasZeroDeterminant(const float (&matrix)[16])
{
    static_assert(sizeof(float) == 4 && std::numeric_limits<float>::is_iec559 &&
                  std::numeric_limits<float>::radix == 2 && std::numeric_limits<float>::digits == 24);
    std::array<std::uint32_t, 35> positiveTerms{}, negativeTerms{};
    std::array<unsigned int, 4> columns{0, 1, 2, 3};
    do
    {
        bool negative = false;
        for (unsigned int row = 0; row < 4; ++row)
            for (unsigned int next = row + 1; next < 4; ++next)
                if (columns[row] > columns[next])
                    negative = !negative;

        // A product of four 24-bit mantissas fits in three 32-bit words.
        std::array<std::uint32_t, 3> product{1, 0, 0};
        int shift = 596;
        for (unsigned int row = 0; row < 4; ++row)
        {
            const auto bits = std::bit_cast<std::uint32_t>(matrix[row * 4 + columns[row]]);
            const auto exponent = (bits >> 23) & 0xffu;
            const auto mantissa = (bits & 0x7fffffu) | (exponent ? 0x800000u : 0u);
            shift += exponent ? static_cast<int>(exponent) - 150 : -149;
            negative ^= (bits >> 31) != 0;
            std::uint64_t carry = 0;
            for (auto& word : product)
            {
                const std::uint64_t value = std::uint64_t(word) * mantissa + carry;
                word = static_cast<std::uint32_t>(value);
                carry = value >> 32;
            }
        }

        // Finite inputs give shift in [0,1012]. Split only at unsigned word
        // boundaries, guarding the zero-bit case to avoid a shift by 32.
        const auto firstWord = static_cast<unsigned int>(shift) / 32;
        const auto bitShift = static_cast<unsigned int>(shift) % 32;
        auto& total = negative ? negativeTerms : positiveTerms;
        std::uint64_t carry = 0;
        for (unsigned int word = 0; word < total.size(); ++word)
        {
            std::uint32_t term = 0;
            if (word >= firstWord && word < firstWord + product.size())
                term |= product[word - firstWord] << bitShift;
            if (bitShift != 0 && word > firstWord && word <= firstWord + product.size())
                term |= product[word - firstWord - 1] >> (32 - bitShift);
            const std::uint64_t value = std::uint64_t(total[word]) + term + carry;
            total[word] = static_cast<std::uint32_t>(value);
            carry = value >> 32;
        }
    }
    while (std::next_permutation(columns.begin(), columns.end()));
    return positiveTerms == negativeTerms;
}
}

// Native inverse of a 4x4 float matrix into caller-owned storage.
// @fnv 0x00ee6dda
void* FUN_00ee6dda(void* pOut, float* pDeterminant, const void* pM)
{
    static_assert(sizeof(float) == 4);
    float source[16];
    std::memcpy(source, pM, sizeof(source));
    double augmented[4][8]{};
    for (unsigned int row = 0; row < 4; ++row)
    {
        for (unsigned int column = 0; column < 4; ++column)
        {
            const float value = source[row * 4 + column];
            if (!std::isfinite(value))
                return nullptr;
            augmented[row][column] = value;
        }
        augmented[row][row + 4] = 1;
    }

    // Rounded elimination can leave a nonzero pivot for exactly dependent
    // rows. Reject exact singularity before it can masquerade as an inverse.
    if (HasZeroDeterminant(source))
    {
        if (pDeterminant)
            *pDeterminant = 0;
        return nullptr;
    }

    // Partial pivoting avoids dividing by a zero leading element and limits
    // elimination growth. Double intermediates retain range for determinants
    // of normally scaled float matrices, even when the float result is 0/inf.
    // A zero floating pivot still reports numerical failure; no epsilon cutoff.
    double determinant = 1;
    for (unsigned int column = 0; column < 4; ++column)
    {
        unsigned int pivotRow = column;
        for (unsigned int row = column + 1; row < 4; ++row)
            if (std::fabs(augmented[row][column]) > std::fabs(augmented[pivotRow][column]))
                pivotRow = row;
        if (augmented[pivotRow][column] == 0)
        {
            if (pDeterminant)
                *pDeterminant = 0;
            return nullptr;
        }
        if (pivotRow != column)
        {
            for (unsigned int k = 0; k < 8; ++k)
                std::swap(augmented[column][k], augmented[pivotRow][k]);
            determinant = -determinant;
        }
        const double pivot = augmented[column][column];
        if (!std::isfinite(pivot))
            return nullptr;
        determinant *= pivot;
        for (unsigned int k = column + 1; k < 8; ++k)
            augmented[column][k] /= pivot;
        augmented[column][column] = 1;
        for (unsigned int row = 0; row < 4; ++row)
        {
            if (row == column)
                continue;
            const double factor = augmented[row][column];
            for (unsigned int k = column + 1; k < 8; ++k)
                augmented[row][k] -= factor * augmented[column][k];
            augmented[row][column] = 0;
        }
    }

    // Narrowing the optional determinant must not determine success. Handle
    // overflow explicitly rather than relying on an out-of-range float cast.
    const double floatMax = std::numeric_limits<float>::max();
    if (pDeterminant)
        *pDeterminant = std::fabs(determinant) > floatMax ?
            std::copysign(std::numeric_limits<float>::infinity(), determinant) :
            static_cast<float>(determinant);

    float inverse[16];
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
        {
            const double value = augmented[row][column + 4];
            if (!std::isfinite(value) || std::fabs(value) > floatMax)
                return nullptr;
            inverse[row * 4 + column] = static_cast<float>(value);
        }
    // All input is staged and no matrix output is written until success.
    // This supports exact in-place calls without aliasing caller struct types.
    std::memcpy(pOut, inverse, sizeof(inverse));
    return pOut;
}

// Native row-major 4x4 float product, first * second, in borrowed storage.
// Replaces the original D3DXMatrixMultiply forwarding leaf, not its SDK code.
// @fnv 0x00ee6de0
void* FUN_00ee6de0(void* pOut, const void* pM1, const void* pM2)
{
    static_assert(sizeof(float) == 4);
    // Representation copies avoid imposing a struct type or alignment on callers.
    // Stage both inputs and the output to support either exact alias and squaring.
    float first[16], second[16], product[16];
    std::memcpy(first, pM1, sizeof(first));
    std::memcpy(second, pM2, sizeof(second));
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
        {
            // Double intermediates retain range for finite binary32 products;
            // no epsilon, domain cutoff or original SDK bit-equivalence claim.
            double value = 0;
            for (unsigned int k = 0; k < 4; ++k)
                value += double(first[row * 4 + k]) * second[k * 4 + column];
            product[row * 4 + column] = std::fabs(value) > std::numeric_limits<float>::max() ?
                std::copysign(std::numeric_limits<float>::infinity(), value) : static_cast<float>(value);
        }
    std::memcpy(pOut, product, sizeof(product));
    return pOut;
}
