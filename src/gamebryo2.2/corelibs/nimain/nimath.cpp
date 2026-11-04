
// src/gamebryo2.2/corelibs/nimain/nimath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nimath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <math.h>
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
namespace fnv_00a813c0 {
// 512-entry sine/cosine lookup tables (filled at start-up).

// 2*pi and the angular step of one table slot.
extern float g_fTwoPi;
extern double g_fAngleStep;

// Fills both tables with 512 sine and cosine values of an angle difference that increases by g_fTwoPi multiplied by g_fAngleStep.
// @fnv 0x00a813c0
void InitTrigTables()
{
    float fAngleDifference = 0.0f;
    double fStep = g_fTwoPi * g_fAngleStep;

    for (unsigned int i = 0; i < 512; i++)
    {
        ::DAT_011f52e0[i] = sinf(fAngleDifference);
        (*reinterpret_cast<float (*)[512]>(&::DAT_011f4ae0))[i] = cosf(fAngleDifference);
        fAngleDifference = (float)(fAngleDifference + fStep);
    }
}
}  // namespace fnv_00a813c0

#include "generated/data/gamebryo2.2/corelibs/nimain/nimath.inc"
