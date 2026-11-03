// src/fallout_shared/bgsprimitive_ob1_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/bgsprimitive.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Ob1 /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004a51d0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s4a5200__Owner.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00a5b000.h"
#include "bgsprimitive_decls.h"

double __cdecl fabs(double);
struct S00c365f0_Vec : NiPoint3
{
};
struct S00c365f0_Mat
{
    float m[3][3];
    void GetCol(unsigned int c, NiPoint3& out) const
    {
        out.x = m[0][c];
        out.y = m[1][c];
        out.z = m[2][c];
    }
};
inline float S00c365f0_fabsf(float _X)
{
    return ((float)fabs((double)_X));
}
inline float S00c365f0_Abs(float _X)
{
    return (S00c365f0_fabsf(_X));
}
struct S00c365f0_Box
{
    int unk00, unk04, unk08;
    NiPoint3 center;
    NiPoint3 extents;
    S00c365f0_Mat rotation;
    int FUN_00c365f0(const NiBound& sphere);
};

// @fnv 0x00c365f0
int S00c365f0_Box::FUN_00c365f0(const NiBound& sphere)
{
    NiPoint3 c2 = sphere.m_kCenter;
    float r = sphere.m_fBoundRadius;
    bool inside = true;
    bool outside2 = true;
    NiPoint3 ax = NiPoint3::ZERO;
    NiPoint3 ay = NiPoint3::ZERO;
    NiPoint3 _az = NiPoint3::ZERO;
    rotation.GetCol(0, ax);
    float a4 = S00c365f0_Abs(reinterpret_cast<::FUN_004b6190_shell *>((void *)(((S00c365f0_Vec*)&c2)))->DotProduct((void *)&(ax)) - reinterpret_cast<::FUN_004b6190_shell *>((void *)(((S00c365f0_Vec*)&ax)))->DotProduct((void *)&(center)));
    inside &= a4 - (extents.x - r) <= 0.0;
    outside2 &= a4 - (extents.x + r) <= 0.0;
    if (inside || outside2)
    {
        rotation.GetCol(1, ay);
        float ay9 =
            S00c365f0_Abs(reinterpret_cast<::FUN_004b6190_shell *>((void *)(((S00c365f0_Vec*)&c2)))->DotProduct((void *)&(ay)) - reinterpret_cast<::FUN_004b6190_shell *>((void *)(((S00c365f0_Vec*)&ay)))->DotProduct((void *)&(center)));
        if (inside)
            inside &= ay9 - (extents.y - r) <= 0.0;
        outside2 &= ay9 - (extents.y + r) <= 0.0;
        if (inside || outside2)
        {
            rotation.GetCol(2, _az);
            float az3 =
                S00c365f0_Abs(reinterpret_cast<::FUN_004b6190_shell *>((void *)(((S00c365f0_Vec*)&c2)))->DotProduct((void *)&(_az)) - reinterpret_cast<::FUN_004b6190_shell *>((void *)(((S00c365f0_Vec*)&_az)))->DotProduct((void *)&(center)));
            if (inside)
                inside &= az3 - (extents.z - r) <= 0.0;
            outside2 &= az3 - (extents.z + r) <= 0.0;
        }
    }
    return inside ? 2 : outside2 ? 1 : 0;
}
