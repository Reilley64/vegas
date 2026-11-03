
// src/fallout_shared/pathfinding/navmeshmath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshmath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_006b9000.h"
struct NiPoint2
{
    float x;
    float y;
    NiPoint2(float a, float b);
};
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct NiPoint3Out
{
    float x;
    float y;
    float z;
};
// @fnv 0x006b9790
bool __cdecl FUN_006b9790(const NiPoint3& aPoint1, const NiPoint3& aPoint2, const NiPoint3& aPoint3,
                          const NiPoint3& aPoint4, NiPoint3Out* out)
{
    return ::ComputeBarycentricCoordinates((const float *)&(const ::NiPoint2 &)(NiPoint2(aPoint1.x, aPoint1.y)), (const float *)&(const ::NiPoint2 &)(NiPoint2(aPoint2.x, aPoint2.y)),
                                         (const float *)&(const ::NiPoint2 &)(NiPoint2(aPoint3.x, aPoint3.y)), (const float *)&(const ::NiPoint2 &)(NiPoint2(aPoint4.x, aPoint4.y)), (float *)(out));
}
