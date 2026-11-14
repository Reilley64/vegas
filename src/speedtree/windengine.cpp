
// src/speedtree/windengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/windengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_011f8000.h"
extern float DAT_010a5784;
extern float DAT_010a5788;

struct FUN_00b37510_shell
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    void SetFromSource(const float* src);
};

// Copies src[0], src[1] and src[6] into f18, f1c and f4, and computes f20 and f24 from src[6] scaled by DAT_010a5784 and DAT_010a5788.
// @fnv 0x00b37510
void FUN_00b37510_shell::SetFromSource(const float* afSource)
{
    f18 = afSource[0];
    f1c = afSource[1];
    f20 = DAT_010a5784 * afSource[6] * f1c;
    f24 = DAT_010a5788 * afSource[6] * f18;
    f4 = afSource[6];
}

struct MatrixRange
{
    char _pad[0x28];
    unsigned int m_uiStartingMatrix;
    unsigned int m_uiMatrixSpan;
    void SetMatrixRange(unsigned int nStartingMatrix, unsigned int nMatrixSpan);
};

// @fnv 0x00b37570
void MatrixRange::SetMatrixRange(unsigned int nStartingMatrix, unsigned int nMatrixSpan)
{
    m_uiStartingMatrix = nStartingMatrix;
    m_uiMatrixSpan = nMatrixSpan;
}

struct FUN_00b37470_shell
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    unsigned int u28;
    unsigned int u2c;
    unsigned int u30;
    unsigned int u34;
    float SetStrength(float fOldStrength, float fNewStrength, float fOldTimeShift);
};
// Stores the old strength, recomputes the frequency-scaled values f20/f24 and the phase f0, resets u30/u34, and returns the phase.
// @fnv 0x00b37470
float FUN_00b37470_shell::SetStrength(float fOldStrength, float fNewStrength, float fOldTimeShift)
{
    float fNewLeafFrequency = DAT_010a5784 * fNewStrength * f1c;
    f4 = fOldStrength;
    f20 = DAT_010a5784 * f4 * f1c;
    f24 = DAT_010a5788 * f4 * f18;
    f0 = DAT_011f8d80 * fNewLeafFrequency + fOldTimeShift - DAT_011f8d80 * f20;
    u34 = 0;
    u30 = 0;
    return f0;
}

#include "generated/data/speedtree/windengine.inc"
