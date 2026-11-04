#pragma once
#include <cstdint>

class RgbaColor;
class TESObjectREFR;
namespace fnv_009a9370 { struct CombatController; }
namespace fnv_009a9370 { struct CombatCoverPointData; }
namespace fnv_009a9370 { struct NiPoint3; }
namespace fnv_009a93a0 { struct TESAmmoInitCalls; }
struct ActH2;
struct CoordinateTriple;
struct DebugPoint;
struct PathingRequest;
struct Ref;
struct S_009a9180_Actor;
struct S_009a9180_Data;
struct TargetActor;
struct TargetSettings;
struct TargetVector;

// 0x009a9180
void FUN_009a9180(::S_009a9180_Actor *, ::S_009a9180_Data *, float *, float *, float *);
// 0x009a9370
namespace fnv_009a9370 { void FUN_009a9370(::fnv_009a9370::CombatController *, ::fnv_009a9370::CombatCoverPointData *, ::fnv_009a9370::NiPoint3 *, ::fnv_009a9370::NiPoint3 *); }
// 0x009a93a0
namespace fnv_009a93a0 { void FUN_009a93a0(::fnv_009a93a0::TESAmmoInitCalls *, intptr_t, intptr_t, intptr_t, intptr_t); }
// 0x009a93e0
void FUN_009a93e0(float, ::TargetActor *, ::TargetSettings *, ::TargetVector *, ::TargetVector *);
// 0x009a9630
bool FUN_009a9630(void *);
// 0x009a96c0
bool FUN_009a96c0(::ActH2 *);
// 0x009a96f0
bool FUN_009a96f0(::TESObjectREFR *, ::CoordinateTriple *);
// 0x009a9720
bool IsExplosionRadiusValid(::PathingRequest *);
// 0x009a97b0
char FUN_009a97b0(char, char);
// 0x009a9800
char IsBitSetOrNeighbor(unsigned int, char);
// 0x009a9a20
bool AssignCombatPlanAngles(::Ref *, ::Ref *);
// 0x009a9f20
void DrawDebugLine(const ::DebugPoint &, const ::DebugPoint &, int, float, const ::RgbaColor *, const ::RgbaColor *);
