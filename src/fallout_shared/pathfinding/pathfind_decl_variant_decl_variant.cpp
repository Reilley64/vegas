
// src/fallout_shared/pathfinding/pathfind_decl_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x006da420: the skeleton of src/fallout_shared/pathfinding/pathfind_decl_variant.cpp
// with declarations corrected to what the original code does (NiPoint3.h: NiPoint3 operator+(const NiPoint3& point) cons -> NiPoint3() {} NiPoint3(const NiPoint3& poi). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/pathfinding/pathfind_decl_variant.cpp - declaration variant unit created 2026-10-24 by decl_variants.py for paused function 0x006da420: the skeleton of src/fallout_shared/pathfinding/pathfind.cpp
// with declarations corrected to what the original code does (pathfind_local_types.h: PathingLocation += PathingLocation(TESObjectREFR* ref);). Move the function to its real unit once
// that unit declares it this way.
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_006e78b0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_0096aaf0_shell.h"
#include "fnv/decl/NLLocation.h"
#include "fnv/decl/PathBuilderCore.h"
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
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_011a9000.h"
#include "pathfind_decls_decl_pathfind_decl_pathfind_decl_variant.h"

struct RotationMatrix
{
    float entry[3][3];
    RotationMatrix();
    NiPoint3 FUN_004b4500(const NiPoint3* axis);
};
// A native const Point3 member consumes only its receiver in ECX.
bool __cdecl FUN_006d7490(PathingLocation*, NiPoint3*, PathingLocation*, int);
bool __cdecl FUN_006d7350(PathingLocation&, PathingLocation&, PathingLocation*, Pathing::CheckLineOfSightFilter*);
// @fnv 0x006da420
NiPoint3 __cdecl FUN_006da420(float angle, const PathingLocation& sourceLocation, float width)
{
    RotationMatrix seed_2;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(seed_2))->FUN_004a0c90(angle);
    NiPoint3 base8 = seed_2.FUN_004b4500(&DAT_011a9478);
    PathingLocation mainLocation(sourceLocation);
    NiPoint3 mainPoint4 = reinterpret_cast<::TaskQueueInterface *>((void *)&(mainLocation))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
    NiPoint3 endPoint6 = mainPoint4 - base8 * DAT_01032adc;
    PathingLocation hit;
    if (!FUN_006d7490(&mainLocation, &endPoint6, &hit, 0))
        endPoint6 = reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
    NiPoint3 difference5 = endPoint6 - mainPoint4;
    NiPoint3 offset_2 = difference5.CrossProduct(DAT_011a9484) * width;
    PathingLocation leftStart4(mainPoint4 - offset_2, mainLocation);
    PathingLocation leftEnd(endPoint6 - offset_2, mainLocation);
    if (!FUN_006d7350(leftStart4, leftEnd, &hit, 0))
    {
        if (reinterpret_cast<::TESCombatStyle *>((void *)(reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr) - reinterpret_cast<::TaskQueueInterface *>((void *)&(leftStart4))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)(difference5))->UpdateCombatStyle())
            endPoint6 = reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
    }
    PathingLocation rightStartX(mainPoint4 + offset_2, mainLocation);
    PathingLocation rightEnd(endPoint6 + offset_2, mainLocation);
    if (!FUN_006d7350(rightStartX, rightEnd, &hit, 0))
    {
        if (reinterpret_cast<::TESCombatStyle *>((void *)(reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr) - reinterpret_cast<::TaskQueueInterface *>((void *)&(rightStartX))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)(difference5))->UpdateCombatStyle())
            endPoint6 = reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
    }
    return mainPoint4 - endPoint6;
}
