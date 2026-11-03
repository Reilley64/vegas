
// pathfind_ctx_variant.cpp: context variant of src/fallout_shared/pathfinding/pathfind.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_006e78b0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_0096aaf0_shell.h"
#include "fnv/decl/NLLocation.h"
#include "fnv/decl/PathBuilderCore.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/This152.h"
#include "fnv/decl/fnv_006f49c0__FUN_006f49c0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_006d0000.h"
#include "fnv/symbols_006d1000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_006d4000.h"
#include "fnv/symbols_006d7000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_011a9000.h"
#include "pathfind_decls.h"

struct Vec3 : NiPoint3
{
    Vec3();
    Vec3 ApplyScaled(float) const;
};
struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    Vec3 FUN_004b4500(const Vec3*);
};
struct PointOperations
{
    Vec3 FUN_0053d1a0(const Vec3&) const;
};
struct PathingLocationOperations
{
};
extern const double DAT_0106cbc8;
extern bool __cdecl FUN_006d7490(PathingLocation&, const Vec3&, PathingLocation*, void*);
extern bool __cdecl FUN_006d7350(PathingLocation&, PathingLocation&, PathingLocation*, void*);

// @fnv 0x006d99a0
Vec3 __cdecl FUN_006d99a0(float angle, PathingLocation* startRef, PathingLocation* endRef, float radius)
{
    Matrix rotation6;
    new ((void *)&(rotation6)) ::Vec3();
    reinterpret_cast<::FUN_004a0c90_shell *>(&(rotation6))->FUN_004a0c90(angle);
    Vec3 forwardAxis = rotation6.FUN_004b4500(&(*reinterpret_cast<::Vec3 *>(&::DAT_011a9478)));
    PathingLocation start0(*startRef);
    Vec3 origin20 = (*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&start0)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
    Vec3 goalId_ = (*(::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(origin20))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(forwardAxis.ApplyScaled(DAT_01032adc)), {})));
    PathingLocation first2;
    if (!FUN_006d7490(start0, goalId_, &first2, 0))
        goalId_ = (*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
    Vec3 initial = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0((::NiPoint3 *)&(origin20), *(const ::NiPoint3 *)nullptr)));
    Vec3 sideShape7 = ((PointOperations*)&initial)->FUN_0053d1a0((*reinterpret_cast<const ::Vec3 *>((void *)&::DAT_011a9484))).ApplyScaled(radius);
    PathingLocation leftStartB((*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(origin20))->FUN_00439ef0((::NiPoint3 *)&(sideShape7), *(const ::NiPoint3 *)nullptr))), start0);
    PathingLocation leftEnd5((*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0((::NiPoint3 *)&(sideShape7), *(const ::NiPoint3 *)nullptr))), start0);
    if (!FUN_006d7350(leftStartB, leftEnd5, &first2, 0))
    {
        if (reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&(
                 const Vec3&)((*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::Vec3 &)((*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))))->FUN_00439ef0((::NiPoint3 *)&(const ::Vec3 &)((*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&leftStartB)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), *(const ::NiPoint3 *)nullptr)))))))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&initial)))->UpdateCombatStyle())
            goalId_ = (*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
    }
    PathingLocation rightStart2((*(::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(origin20))->ProjectileLaunched((::NiPoint3 *)&(sideShape7), {}))), start0);
    PathingLocation rightEnd2((*(::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(goalId_))->ProjectileLaunched((::NiPoint3 *)&(sideShape7), {}))), start0);
    if (!FUN_006d7350(rightStart2, rightEnd2, &first2, 0))
    {
        if (reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&(
                 const Vec3&)((*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::Vec3 &)((*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))))->FUN_00439ef0((::NiPoint3 *)&(const ::Vec3 &)((*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&rightStart2)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), *(const ::NiPoint3 *)nullptr)))))))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&initial)))->UpdateCombatStyle())
            goalId_ = (*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
    }
    reinterpret_cast<::NiPoint3 *>((((PointOperations*)&goalId_)))->Subtract((const ::NiPoint3 &)((const ::Vec3 &)(forwardAxis.ApplyScaled(radius).ApplyScaled(DAT_01018204))));
    PathingLocation end19(*endRef);
    Vec3 endOriginVal = (*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&end19)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
    PathingLocation endHitX;
    if (!FUN_006d7490(end19, goalId_, &endHitX, 0))
        return (*reinterpret_cast<const ::Vec3 *>((void *)&::NiPoint3::ZERO));
    Vec3 endDelta = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0((::NiPoint3 *)&(endOriginVal), *(const ::NiPoint3 *)nullptr)));
    Vec3 endSide = ((PointOperations*)&endDelta)->FUN_0053d1a0((*reinterpret_cast<const ::Vec3 *>((void *)&::DAT_011a9484))).ApplyScaled(radius);
    PathingLocation endLeftEndA((*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(endOriginVal))->FUN_00439ef0((::NiPoint3 *)&(sideShape7), *(const ::NiPoint3 *)nullptr))), end19);
    PathingLocation endLeftStart6((*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0((::NiPoint3 *)&(sideShape7), *(const ::NiPoint3 *)nullptr))), end19);
    if (!FUN_006d7350(endLeftEndA, endLeftStart6, &endHitX, 0))
        return (*reinterpret_cast<const ::Vec3 *>((void *)&::NiPoint3::ZERO));
    PathingLocation endRightStart4((*(::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(endOriginVal))->ProjectileLaunched((::NiPoint3 *)&(sideShape7), {}))), end19);
    PathingLocation endRightEnd2((*(::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(goalId_))->ProjectileLaunched((::NiPoint3 *)&(sideShape7), {}))), end19);
    if (!FUN_006d7350(endRightStart4, endRightEnd2, &endHitX, 0))
        return (*reinterpret_cast<const ::Vec3 *>((void *)&::NiPoint3::ZERO));
    Vec3 directionX = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(endOriginVal))->FUN_00439ef0((::NiPoint3 *)&(origin20), *(const ::NiPoint3 *)nullptr)));
    float distance29 = reinterpret_cast<::NiPoint3 *>((((PointOperations*)&directionX)))->GetLengthSquared();
    float i = reinterpret_cast<::FUN_004b6190_shell *>((void *)(((PointOperations*)&directionX)))->DotProduct((void *)&(forwardAxis));
    if (i < DAT_0106cbc8)
    {
        return (*reinterpret_cast<const ::Vec3 *>((void *)&::NiPoint3::ZERO));
    }
    else if (i < ::_DAT_01012060 && distance29 < DAT_010240c0)
    {
        return (*reinterpret_cast<const ::Vec3 *>((void *)&::NiPoint3::ZERO));
    }
    return (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0((::NiPoint3 *)&(origin20), *(const ::NiPoint3 *)nullptr)));
}

#include "generated/data/fallout_shared/pathfinding/pathfind_ctx_variant.inc"
