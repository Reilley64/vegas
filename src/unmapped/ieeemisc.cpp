
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cmath>
#include "fnv/symbols_00aaf000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
// @fnv 0x00ac79e0
float FUN_00ac79e0(float a, float b)
{
    float fSum;
    if (!std::isnan(a))
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\algs.cpp", 0x1b2);
    }
    if (!std::isnan(b))
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\algs.cpp", 0x1b3);
    }
    fSum = a + b;
    if (!std::isfinite(fSum))
    {
        if ((double)fSum == (float)std::fabs(fSum))
        {
            return DAT_01016970;
        }
        else
        {
            return DAT_01015f5c;
        }
    }
    return fSum;
}
