
// src/fallout_shared/pathfinding/pathsmootherpov_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x006b23d0: the skeleton of src/fallout_shared/pathfinding/pathsmootherpov.cpp
// with declarations corrected to what the original code does (pathsmootherpov_decls.h: PathSmootherPOVSearch += bool FindPath(const NavMeshEdgePoint& edge, const NiPoint3& point, NavMeshEdgePoint& location, float& cost);). Move the function to its real unit once
// that unit declares it this way.

#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AvoidNodes__Search.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/ClearanceSearch.h"
#include "fnv/decl/FUN_0045cbc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00505c00_shell.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_00691620_shell.h"
#include "fnv/decl/FUN_00691640_shell.h"
#include "fnv/decl/FUN_00697980_t.h"
#include "fnv/decl/FUN_00698320_t.h"
#include "fnv/decl/FUN_0069f900_shell.h"
#include "fnv/decl/FUN_0069f920_cls.h"
#include "fnv/decl/FUN_006a0840_shell.h"
#include "fnv/decl/FUN_006a9520_Class.h"
#include "fnv/decl/FUN_006a9560_Class.h"
#include "fnv/decl/FUN_006b0570_shell.h"
#include "fnv/decl/FUN_006b05d0_shell.h"
#include "fnv/decl/FUN_006b1df0_shell.h"
#include "fnv/decl/FUN_006b3380_shell.h"
#include "fnv/decl/FUN_006b3420_shell.h"
#include "fnv/decl/FloatValueProvider.h"
#include "fnv/decl/GetCenterX_006a6eb0.h"
#include "fnv/decl/Holder670.h"
#include "fnv/decl/LastNodeSearch17.h"
#include "fnv/decl/PSSearchView.h"
#include "fnv/decl/PathSmootherAccess.h"
#include "fnv/decl/S_FUN_006b05a0.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_Dummy_0069e390.h"
#include "fnv/decl/fnv_0068f0c0__FUN_0068f0c0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00533000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006b9000.h"
#include "fnv/symbols_006ba000.h"
#include "fnv/symbols_006d4000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011d7000.h"
#include "fnv/symbols_011de000.h"
#include "pathsmootherpov_decls_decl_pathsmootherpov.h"
// MSVC9 allocates these locals by identifier as well as scope.
// Semantic aliases preserve the verified stack layout while keeping the body readable.
#define currentNode iNumTangents
#define incomingLink pCurrentLink
#define centerDelta Tangents
#define xyDistanceSquared iTested
#define heightSquared fZDistSqr
#define startSphere Diff
#define endSphere Node
#define tangentData fXYDistSqr
#define tangentCount EndSphere
#define testedCount StartSphere
#define direction Dir
#define leftDirection Left
#define sourceArc EntryLoc
#define sourceLocation Arc
#define exitLocation ExitLoc
#define entryLocation ProjectedLoc
#define destination height
#define projectedPoint EndLoc
#define heightDelta StartLoc
#define discount fDiscount
#define cost m_fPathingCostCur
#define nextNode pListNode
#define radialDistance Right
#define rightDirection fScaleMultiplier
#define tangentLength Perp
#define perpendicular fTangentLength
#undef currentNode
#undef incomingLink
#undef centerDelta
#undef xyDistanceSquared
#undef heightSquared
#undef startSphere
#undef endSphere
#undef tangentData
#undef tangentCount
#undef testedCount
#undef direction
#undef leftDirection
#undef sourceArc
#undef sourceLocation
#undef exitLocation
#undef entryLocation
#undef destination
#undef projectedPoint
#undef heightDelta
#undef discount
#undef cost
#undef nextNode
#undef radialDistance
#undef rightDirection
#undef tangentLength
#undef perpendicular

// @fnv 0x006b23d0
bool PathSmootherPOVSearch::FUN_006b23d0(const NavMeshEdgePoint& edge, Sphere& sphere, CircularArc arc)
{
    float firstRadius1 = arc.Direction == AD_CCW ? sphere.Radius - ::GetFloatAtOffset68((const char *)(pRequest)) * 0.9f
                                                 : sphere.Radius + ::GetFloatAtOffset68((const char *)(pRequest)) * 0.9f;
    NiPoint3 firstDirection0 = arc.Start.MakePointOnCircle(firstRadius1);
    NavMeshEdgePoint firstLocation6;
    Sphere firstSphere2(sphere.Center, firstRadius1);
    float cost13 = 0.0f;
    if (!reinterpret_cast<::PathSmootherAccess *>(this)->FindPath(edge, sphere.Center + firstDirection0, (::NavMeshEdgePoint *)&(firstLocation6), cost13))
        return false;
    NavMeshEdgePoint firstExit15;
    if (!FUN_006b1e50(firstLocation6, firstSphere2, arc, &firstExit15))
        return false;

    float secondRadius1 = arc.Direction == AD_CCW ? sphere.Radius + ::GetFloatAtOffset68((const char *)(pRequest)) * 0.9f
                                                  : sphere.Radius - ::GetFloatAtOffset68((const char *)(pRequest)) * 0.9f;
    NiPoint3 secondDirection2 = arc.Start.MakePointOnCircle(secondRadius1);
    NavMeshEdgePoint secondLocation2;
    Sphere secondSphere12(sphere.Center, secondRadius1);
    if (!reinterpret_cast<::PathSmootherAccess *>(this)->FindPath(edge, sphere.Center + secondDirection2, (::NavMeshEdgePoint *)&(secondLocation2), cost13))
        return false;
    NavMeshEdgePoint secondExit9;
    if (!FUN_006b1e50(secondLocation2, secondSphere12, arc, &secondExit9))
        return false;
    return true;
}
