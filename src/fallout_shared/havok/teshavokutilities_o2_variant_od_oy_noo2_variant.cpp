
// src/fallout_shared/havok/teshavokutilities_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/havok/teshavokutilities_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/teshavokutilities_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/teshavokutilities.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/teshavokutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teshavokutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <new>
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0056ded0.h"
#include "fnv/decl/FUN_00c8d280_cls.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiPosData.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WorldObject_c8d3.h"
#include "fnv/decl/_dummy_476a80.h"
#include "fnv/decl/fnv_00437c10__FUN_00437c10.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_01268000.h"
struct Point3
{
    float x, y, z;
};
struct Aabb
{
    __m128 minimum, maximum;
};
struct HavokTransform
{
    __m128 rotation0, rotation1, rotation2, translation;
};
struct Transform
{
    float rotation[3][3];
    Point3 translation;
    float scale;
    Transform* FUN_0062c250(Transform* out, const Transform* other) const;
    Point3* FUN_00524c40(Point3* out, const Point3* point) const;
};
struct Node
{
};
struct WorldObject
{
};
struct CollisionObject
{
};
struct RTTI;
// @fnv 0x0062bfb0
Point3* FUN_0062bfb0(Point3* out, Node* node)
{
    Point3 chosen = (*reinterpret_cast<::Point3 *>((void *)&::NiPoint3::ZERO));
    CollisionObject* collision = ((::CollisionObject *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(node))));
    if (collision)
    {
        WorldObject* body = ((::WorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(collision))));
        if (body)
        {
            Aabb bounds;
            new ((void *)&(bounds)) ::fnv_00437c10::FUN_00437c10();
            reinterpret_cast<::WorldObject_c8d3 *>((body))->GetAabb((*(::Aabb_c8d3 *)(&bounds)));
            Point3 minimum;
            new ((void *)&(minimum)) ::Vec3();
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&minimum)), (*(const ::hkVector4 *)(&bounds.minimum)));
            Point3 maximum;
            new ((void *)&(maximum)) ::Vec3();
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&maximum)), (*(const ::hkVector4 *)(&bounds.maximum)));
            Point3 lower, upper, minTermA, maxTermA, minTermB, maxTermB;
            reinterpret_cast<::Point3Offset *>((void *)(((::Point3 *)(::NiPosData::ComputePositionAtTime((::NiPoint3 *)(::Point3 *)(&maxTermA), .55f, (const ::NiPoint3 *)(const ::Point3 *)(&maximum))))))->ProjectileLaunched((::NiPoint3 *)(::Point3 *)(&upper), (::NiPoint3 *)(((::Point3 *)(::NiPosData::ComputePositionAtTime((::NiPoint3 *)(::Point3 *)(&minTermA), .45f, (const ::NiPoint3 *)(const ::Point3 *)(&minimum))))));
            reinterpret_cast<::Point3Offset *>((void *)(((::Point3 *)(::NiPosData::ComputePositionAtTime((::NiPoint3 *)(::Point3 *)(&maxTermB), .45f, (const ::NiPoint3 *)(const ::Point3 *)(&maximum))))))->ProjectileLaunched((::NiPoint3 *)(::Point3 *)(&lower), (::NiPoint3 *)(((::Point3 *)(::NiPosData::ComputePositionAtTime((::NiPoint3 *)(::Point3 *)(&minTermB), .55f, (const ::NiPoint3 *)(const ::Point3 *)(&minimum))))));
            Point3 random;
            chosen = *((::Point3 *)(reinterpret_cast<::FUN_00416870_t *>(&(random))->FUN_00416870(::RandomFloat(lower.x, upper.x), ::RandomFloat(lower.y, upper.y),
                                          ::RandomFloat(lower.z, upper.z))));
            if (::FUN_0043b300((const ::NiRTTI *)(const ::RTTI *)(&(*reinterpret_cast<::RTTI *>(&::g_012683c8))), (::NiAVObject *)(body)) || ((::Node *)(reinterpret_cast<::Twin_0044ddc0 *>((collision))->GetName())) != node)
            {
                HavokTransform bodyHavok;
                new ((void *)&(bodyHavok)) ::FUN_0056ded0();
                reinterpret_cast<::FUN_00c8d280_cls *>((body))->FUN_00c8d280((::S8d280_Mat *)(::HavokTransform *)(&bodyHavok));
                Transform bodyWorld;
                reinterpret_cast<::_dummy_476a80 *>(&(bodyWorld))->FUN_00476a80();
                ::FUN_00624ad0((::NiTransform *)(struct ::Transform *)(&bodyWorld), (::TopicH *)(&bodyHavok));
                bodyWorld.scale = 1.0f;
                Transform inverse;
                reinterpret_cast<::_dummy_476a80 *>(&(inverse))->FUN_00476a80();
                reinterpret_cast<::NiTransform *>((void *)(((const struct ::Transform *)(::FUN_00461130((int)(node))))))->CalculateInverse((*(::NiTransform *)(&inverse)));
                Transform composed;
                Point3 transformed;
                chosen = *inverse.FUN_0062c250(&composed, &bodyWorld)->FUN_00524c40(&transformed, &chosen);
            }
        }
    }
    *out = chosen;
    return out;
}
