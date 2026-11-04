#include <windows.h>
#include "fnv/symbols_0106b000.h"
#include "fnv_asm_helpers.h"
// src/havok/common/base/system/stopwatch/hksystemclock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/stopwatch/hksystemclock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


struct Obj
{
    virtual long long v0();
    virtual long long v1();
    virtual long long v2();
    virtual long long GetCounter();
    unsigned __int64 FUN_00dd8e20();
};

unsigned __int64 g_freq;

// @fnv 0x00dd8e20
unsigned __int64 Obj::FUN_00dd8e20()
{
    if (g_freq != 0)
        return g_freq;

    double best = ::CombatWeapons::DAT_0106b798;
    int count = 10;
    while (count != 0)
    {
        long long t1 = this->GetCounter();
        __int64 q1;
        QueryPerformanceCounter((LARGE_INTEGER*)&q1);
        volatile int busy = 1;
        for (int i = 0x1388; i != 0; --i)
        {
            busy = busy * busy + busy;
        }
        long long t2 = this->GetCounter();
        __int64 q2;
        QueryPerformanceCounter((LARGE_INTEGER*)&q2);
        QueryPerformanceFrequency((LARGE_INTEGER*)&g_freq);

        unsigned __int64 num = (unsigned __int64)(t2 - t1);
        unsigned __int64 den = (unsigned __int64)(q2 - q1);
        double ratio = (double)num / (double)den;
        if (best > ratio)
            best = ratio;
        --count;
    }
    g_freq = (unsigned __int64)(best * (double)g_freq);
    return g_freq;
}// src/havok/common/base/system/stopwatch/hksystemclock_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/havok/common/base/system/stopwatch/hksystemclock.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/havok/common/base/system/stopwatch/hksystemclock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/stopwatch/hksystemclock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dd8e00
unsigned __int64 __cdecl FUN_00dd8e00() {
    unsigned __int64 ticks;
    fnv_ReadTicks64(ticks);
    return ticks;
}
