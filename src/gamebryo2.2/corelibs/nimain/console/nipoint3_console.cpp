// gamebryo2.2/corelibs/nimain/console/nipoint3_console.cpp: free functions (2 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/ni_point3_startup_table.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011f4000.h"
#include "NiPoint3.h"

// The source is the default pixel format record: flags 1 and 32 bits per
// pixel (8193), FORMAT_RGBA, no tiling, renderer hint -1, no extra data, then
// the components red, green, blue and alpha, each with representation 0,
// 8 bits and the signed byte 1 (264 is 8 + (1 << 8)). The destination starts
// as a copy of the source, made by the dynamic initializer below.
//
// These values are an owner-approved native default (VEGAS-85, 2026-11-12),
// not values recovered from the original release. They are the stored list
// with a zero inserted before the first 264 and 264 as the 17th int.

// @fnv 0x00a62110
alignas(16) NiPoint3StartupTable gNiPoint3StartupSrc = {{8193, 1, 0, -1, 0, 0, 0, 264, 1, 0, 264, 2, 0, 264, 3, 0, 264}};
alignas(16) NiPoint3StartupTable gNiPoint3StartupDst = gNiPoint3StartupSrc;


// Normalizes each of count NiPoint3 vectors spaced by stride bytes, scaling by the reciprocal of its length via a lookup table.
// @fnv 0x00a7e960
void NormalizePoints(NiPoint3* pElementBuffer, unsigned int count, unsigned int stride)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        union
        {
            float f;
            unsigned int u;
        } fInvLen;
        fInvLen.f = pElementBuffer->x * pElementBuffer->x + pElementBuffer->y * pElementBuffer->y +
                    pElementBuffer->z * pElementBuffer->z;
        if (fInvLen.u == 0)
        {
            fInvLen.f = 0.0f;
        }
        else
        {
            unsigned short usExponent = (fInvLen.u >> 23) - 127;
            fInvLen.u &= 0x7fffff;
            if (usExponent & 1)
            {
                fInvLen.u |= 0x800000;
            }
            int iExponent = ((short)usExponent >> 1) + 127;
            fInvLen.u >>= 16;
            fInvLen.u = (iExponent << 23) | ((unsigned int*)(*reinterpret_cast<void * *>(&::DAT_011f4aa8)))[fInvLen.u];
            fInvLen.f = 1.0f / fInvLen.f;
        }
        pElementBuffer->x *= fInvLen.f;
        pElementBuffer->y *= fInvLen.f;
        pElementBuffer->z *= fInvLen.f;
        pElementBuffer = (NiPoint3*)((char*)pElementBuffer + stride);
    }
}

#include "generated/data/gamebryo2.2/corelibs/nimain/console/nipoint3_console.inc"
