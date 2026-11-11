// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00ee6000.h"
#include "fnv/d3dx_types.h"

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

// Three-component row-vector normal transformation in borrowed storage.
// @fnv 0x00ee6df2
void* FUN_00ee6df2(void* output, const void* input, const void* matrix)
{
    // Value copies follow the existing void*-based numerical contracts without
    // overlaying callers' vector/matrix types. Stage before any output write.
    float vector[3], source[16];
    std::memcpy(vector, input, sizeof(vector));
    std::memcpy(source, matrix, sizeof(source));
    const float result[3]{
        vector[0] * source[0] + vector[1] * source[4] + vector[2] * source[8],
        vector[0] * source[1] + vector[1] * source[5] + vector[2] * source[9],
        vector[0] * source[2] + vector[1] * source[6] + vector[2] * source[10]};
    // No translation, homogeneous divide, fourth component or normalization.
    std::memcpy(output, result, sizeof(result));
    return output;
}

// Native three-component normalization in borrowed storage: input / |input|.
// Project choices, not D3DX behaviour: a zero-length input gives the zero
// vector, and the length is evaluated in double precision.
// @fnv 0x00ee6dec
void* FUN_00ee6dec(void* output, const void* input)
{
    static_assert(sizeof(float) == 4);
    // Value copies avoid overlaying callers' vector types; staging the result
    // supports an exact input/output alias.
    float vector[3];
    std::memcpy(vector, input, sizeof(vector));
    // Squares of binary32 values are exact in binary64, so the length neither
    // overflows nor underflows for any finite input and is rounded once.
    const double x = vector[0], y = vector[1], z = vector[2];
    const double length = std::sqrt(x * x + y * y + z * z);
    float result[3]{0, 0, 0};
    if (length != 0)
    {
        // Each quotient has magnitude at most 1, so narrowing cannot overflow.
        result[0] = static_cast<float>(x / length);
        result[1] = static_cast<float>(y / length);
        result[2] = static_cast<float>(z / length);
    }
    std::memcpy(output, result, sizeof(result));
    return output;
}

// Three-component row-vector coordinate transformation with implicit input w=1.
// @fnv 0x00ee6df8
void* FUN_00ee6df8(void* output, const void* input, const void* matrix)
{
    // Borrow values without overlaying callers' types. Complete all reads and
    // arithmetic before writing xyz, including an exact input/output alias.
    float vector[3], source[16];
    std::memcpy(vector, input, sizeof(vector));
    std::memcpy(source, matrix, sizeof(source));
    const float x = vector[0] * source[0] + vector[1] * source[4] + vector[2] * source[8] + source[12];
    const float y = vector[0] * source[1] + vector[1] * source[5] + vector[2] * source[9] + source[13];
    const float z = vector[0] * source[2] + vector[1] * source[6] + vector[2] * source[10] + source[14];
    const float w = vector[0] * source[3] + vector[1] * source[7] + vector[2] * source[11] + source[15];
    const float result[3]{x / w, y / w, z / w};
    std::memcpy(output, result, sizeof(result));
    return output;
}

// Four-component row-vector transformation. No divide or normalization.
// @fnv 0x00ee6e34
D3DXVECTOR4* FUN_00ee6e34(D3DXVECTOR4* output, const D3DXVECTOR4* input, const D3DXMATRIX* matrix)
{
    // Finish every read before the assignment, including an exact input alias.
    const D3DXVECTOR4 result{
        input->x * matrix->m[0][0] + input->y * matrix->m[1][0] +
            input->z * matrix->m[2][0] + input->w * matrix->m[3][0],
        input->x * matrix->m[0][1] + input->y * matrix->m[1][1] +
            input->z * matrix->m[2][1] + input->w * matrix->m[3][1],
        input->x * matrix->m[0][2] + input->y * matrix->m[1][2] +
            input->z * matrix->m[2][2] + input->w * matrix->m[3][2],
        input->x * matrix->m[0][3] + input->y * matrix->m[1][3] +
            input->z * matrix->m[2][3] + input->w * matrix->m[3][3]};
    *output = result;
    return output;
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

// Native rotation matrix from yaw, pitch and roll angles in radians, written
// row-major into borrowed storage. Rows transform as row vectors: the result
// is roll about z, then pitch about x, then yaw about y, in a left-handed
// coordinate system, as the public D3DX reference describes the function.
// @fnv 0x00ee6e04
void* FUN_00ee6e04(void* pOut, float yaw, float pitch, float roll)
{
    static_assert(sizeof(float) == 4);
    const double sy = std::sin(double(yaw)), cy = std::cos(double(yaw));
    const double sp = std::sin(double(pitch)), cp = std::cos(double(pitch));
    const double sr = std::sin(double(roll)), cr = std::cos(double(roll));
    // Every element has magnitude at most 2, so narrowing cannot overflow.
    const float rotation[16]{
        static_cast<float>(cr * cy + sr * sp * sy), static_cast<float>(sr * cp),
        static_cast<float>(sr * sp * cy - cr * sy), 0,
        static_cast<float>(cr * sp * sy - sr * cy), static_cast<float>(cr * cp),
        static_cast<float>(sr * sy + cr * sp * cy), 0,
        static_cast<float>(cp * sy), static_cast<float>(-sp), static_cast<float>(cp * cy), 0,
        0, 0, 0, 1};
    std::memcpy(pOut, rotation, sizeof(rotation));
    return pOut;
}

namespace
{
// Round a binary64 intermediate to binary32 once, with an explicit infinity
// rather than an out-of-range conversion.
float Narrow(double value)
{
    return std::fabs(value) > std::numeric_limits<float>::max() ?
        std::copysign(std::numeric_limits<float>::infinity(), value) : static_cast<float>(value);
}
}

// Native plane normalization in borrowed storage: all four coefficients
// (a, b, c, d) divided by the length of the normal (a, b, c).
// Project choices, not D3DX behaviour: a zero-length normal gives the zero
// plane, and the length is evaluated in double precision.
// @fnv 0x00ee6dce
void* FUN_00ee6dce(void* pout, const void* pp)
{
    static_assert(sizeof(float) == 4);
    // Value copies avoid overlaying callers' plane types; staging the result
    // supports an exact input/output alias.
    float plane[4];
    std::memcpy(plane, pp, sizeof(plane));
    const double a = plane[0], b = plane[1], c = plane[2];
    // Squares of binary32 values are exact in binary64: no overflow or underflow.
    const double length = std::sqrt(a * a + b * b + c * c);
    float result[4]{0, 0, 0, 0};
    if (length != 0)
    {
        result[0] = static_cast<float>(a / length);
        result[1] = static_cast<float>(b / length);
        result[2] = static_cast<float>(c / length);
        // The distance is not bounded by the normal's length.
        result[3] = Narrow(double(plane[3]) / length);
    }
    std::memcpy(pout, result, sizeof(result));
    return pout;
}

// Native plane transformation in borrowed storage: the coefficients
// (a, b, c, d) as a four-component row vector times the matrix. As the public
// D3DX reference describes the function, the caller passes the inverse
// transpose of the transformation and a plane with a normalized normal.
// @fnv 0x00ee6dc8
D3DXPLANE* FUN_00ee6dc8(D3DXPLANE* output, const D3DXPLANE* plane, const D3DXMATRIX* matrix)
{
    static_assert(sizeof(float) == 4 && sizeof(D3DXPLANE) == 16 && sizeof(D3DXMATRIX) == 64);
    // Callers pass their own plane and matrix types through these pointers,
    // so copy representations. Stage the result before any output write.
    float coefficients[4], source[16], result[4];
    std::memcpy(coefficients, plane, sizeof(coefficients));
    std::memcpy(source, matrix, sizeof(source));
    for (unsigned int column = 0; column < 4; ++column)
    {
        // Products of binary32 values are exact in binary64.
        double value = 0;
        for (unsigned int row = 0; row < 4; ++row)
            value += double(coefficients[row]) * source[row * 4 + column];
        result[column] = Narrow(value);
    }
    std::memcpy(output, result, sizeof(result));
    return output;
}

// Native transposed product in caller-owned matrix storage.
// @fnv 0x00ee6dfe
D3DXMATRIX* FUN_00ee6dfe(D3DXMATRIX* pOut, const D3DXMATRIX* first, const D3DXMATRIX* second)
{
    // Stage the whole product before touching pOut, including exact aliases.
    float product[16]{};
    FUN_00ee6de0(product, first, second);
    FUN_00ee6dd4(pOut, product);
    return pOut;
}
