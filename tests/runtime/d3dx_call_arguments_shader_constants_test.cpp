// Checks the native D3DX functions with the argument patterns that VEGAS-90
// restored, from before 3f0599801, in five shader-constant functions:
// 0x00e82b40 and 0x00e83db0 in nid3dshaderconstantmap.cpp, 0x00e96fb0 in
// nid3dhlslpixelshader.cpp, and 0x00e972e0 and 0x00e974f0 in
// nid3dhlslvertexshader.cpp. It tests the callees' contract, not the repaired
// sites, which do not link into a test.
// Each case runs the function's sequence of D3DX calls, with the same
// argument pattern, on objects of the same shape (16 floats for a matrix),
// checks what the sequence must leave, and checks that skipping the calls
// does not leave it. Skipping the calls is not what the argument-less calls
// did: ?FUN_00ee6dd4@@YAXXZ has no definition at all, and the other two
// argument-less names call through an import pointer with whatever the
// registers hold.
#include "fnv/d3dx_types.h"
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
        std::fprintf(stderr, "FAIL shader constant D3DX call arguments: %s\n", message);
        std::exit(1);
    }
}

// H * diag(1,2,3,4), where H has orthogonal rows of length 2 (as in the inverse test).
const D3DXMATRIX dense{{.m = {{1, 2, 3, 4}, {1, -2, 3, -4}, {1, 2, -3, -4}, {1, -2, -3, 4}}}};
const D3DXMATRIX denseInverse{{.m = {{0.25f, 0.25f, 0.25f, 0.25f},
                                     {0.125f, -0.125f, 0.125f, -0.125f},
                                     {1.0f / 12, 1.0f / 12, -1.0f / 12, -1.0f / 12},
                                     {0.0625f, -0.0625f, -0.0625f, 0.0625f}}}};

D3DXMATRIX Transposed(const D3DXMATRIX& matrix)
{
    D3DXMATRIX result;
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            result.m[row][column] = matrix.m[column][row];
    return result;
}

bool Same(const D3DXMATRIX& actual, const D3DXMATRIX& expected)
{
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            if (std::fabs(double(actual.m[row][column]) - expected.m[row][column]) >
                2e-6 * (1 + std::fabs(double(expected.m[row][column]))))
                return false;
    return true;
}

// 0x00e82b40: the constant matrix is inverted and transposed in place,
// ::FUN_00ee6dda(&DAT_0126f8c0, 0, &DAT_0126f8c0) and
// ::FUN_00ee6dd4(&DAT_0126f8c0, &DAT_0126f8c0), as the flags ask.
D3DXMATRIX constantMatrix;

void GlobalConstant(bool inverse, bool transpose, bool restored)
{
    constantMatrix = dense;
    if (inverse && restored)
        FUN_00ee6dda(&constantMatrix, 0, &constantMatrix);
    if (transpose && restored)
        FUN_00ee6dd4(&constantMatrix, &constantMatrix);
}

// 0x00e83db0: the same, through ptr = &matResult:
// ::FUN_00ee6dda(ptr, 0, ptr) and ::FUN_00ee6dd4(ptr, ptr).
D3DXMATRIX LocalConstant(bool inverse, bool transpose, bool restored)
{
    D3DXMATRIX matResult = dense;
    D3DXMATRIX* ptr = &matResult;
    if (inverse && restored)
        FUN_00ee6dda(ptr, 0, ptr);
    if (transpose && restored)
        FUN_00ee6dd4(ptr, ptr);
    return matResult;
}

void ConstantCases()
{
    for (bool inverse : {false, true})
        for (bool transpose : {false, true})
        {
            D3DXMATRIX expected = inverse ? denseInverse : dense;
            if (transpose)
                expected = Transposed(expected);
            GlobalConstant(inverse, transpose, true);
            Check(Same(constantMatrix, expected), "the global constant is inverted and transposed as asked");
            Check(Same(LocalConstant(inverse, transpose, true), expected),
                  "the local constant is inverted and transposed as asked");
            if (!inverse && !transpose)
                continue;
            GlobalConstant(inverse, transpose, false);
            Check(!Same(constantMatrix, expected), "skipping the calls leaves the global constant as it was");
            Check(!Same(LocalConstant(inverse, transpose, false), expected),
                  "skipping the calls leaves the local constant as it was");
        }
}

// 0x00e96fb0 and 0x00e974f0: entry pusReorderArray[i] (usIndex) of a block of
// 16-byte registers, four registers to the entry, is transposed into kMatrix:
// ::FUN_00ee6dd4(&kMatrix, (const Matrix16*)((const char*)pvDataSource +
// pusReorderArray[i] * uiRegistersPerEntry * 16)). With one entry, 0x00e972e0
// and both functions' other branch pass the block itself:
// ::FUN_00ee6dd4(&kTranspose, (const VS_00e972e0_Matrix*)pvDataSource).
struct Matrix16
{
    float m[16];
};

Matrix16 ReorderedEntry(const void* pvDataSource, const unsigned short* pusReorderArray, unsigned int i,
                        unsigned int uiRegistersPerEntry, bool restored)
{
    Matrix16 kMatrix{{7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}};
    if (restored)
        FUN_00ee6dd4(&kMatrix, (const Matrix16*)((const char*)pvDataSource +
                                                 pusReorderArray[i] * uiRegistersPerEntry * 16));
    return kMatrix;
}

Matrix16 WholeBlock(const void* pvDataSource, bool restored)
{
    Matrix16 kTranspose{{7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}};
    if (restored)
        FUN_00ee6dd4(&kTranspose, (const Matrix16*)pvDataSource);
    return kTranspose;
}

bool IsTransposeOf(const Matrix16& actual, const float* source)
{
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            if (actual.m[row * 4 + column] != source[column * 4 + row])
                return false;
    return true;
}

void RegisterCases()
{
    // Three entries of four registers each; entry e holds 100 * e + index.
    float block[3 * 16];
    for (unsigned int e = 0; e < 3; ++e)
        for (unsigned int k = 0; k < 16; ++k)
            block[e * 16 + k] = float(100 * e + k);
    const unsigned short reorder[3] = {2, 0, 1};
    for (unsigned int i = 0; i < 3; ++i)
    {
        Check(IsTransposeOf(ReorderedEntry(block, reorder, i, 4, true), block + reorder[i] * 16),
              "kMatrix is the transpose of the reordered entry");
        Check(!IsTransposeOf(ReorderedEntry(block, reorder, i, 4, false), block + reorder[i] * 16),
              "skipping the calls leaves kMatrix unwritten");
    }
    Check(IsTransposeOf(WholeBlock(block, true), block), "the block's first entry is transposed");
    Check(!IsTransposeOf(WholeBlock(block, false), block), "skipping the calls leaves the result unwritten");
    for (unsigned int e = 0; e < 3; ++e)
        for (unsigned int k = 0; k < 16; ++k)
            Check(block[e * 16 + k] == float(100 * e + k), "the registers are only read");
}
}

int main()
{
    ConstantCases();
    RegisterCases();
    return 0;
}
