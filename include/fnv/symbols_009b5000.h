#pragma once
#include <cstdint>

namespace fnv_009b5650 { struct BooleanFloatQuery; }
namespace n9b { struct Ctx; }
namespace n9b { struct Info; }
struct Actor9b58d0;
struct ActorHit;
struct ActorStub;
struct BooleanFloatQuery;
struct CombatThing;
struct FUN_009b5a30_Class;
struct RefHit;
struct Struct9b58d0;
struct Thing9b58d0;

// 0x009b5050
void SetContextInfo(::n9b::Ctx *, ::n9b::Info *);
// 0x009b5120
void FUN_009b5120(intptr_t, intptr_t, intptr_t, intptr_t, unsigned char, intptr_t, int);
// 0x009b5170
void InitHitData(::BooleanFloatQuery *, ::ActorHit *, ::ActorHit *, ::RefHit *, unsigned char);
// 0x009b5650
namespace fnv_009b5650 { void InitFromObjects(::fnv_009b5650::BooleanFloatQuery *, void *, void *, void *, void *); }
// 0x009b5720
void FUN_009b5720(::FUN_009b5a30_Class *, intptr_t, intptr_t, float);
// 0x009b5770
void InitCombatThing(::CombatThing *, int, int, ::ActorStub *, float);
// 0x009b58d0
void FUN_009b58d0(::Thing9b58d0 *, intptr_t, ::Actor9b58d0 *, float, ::Struct9b58d0 *);
