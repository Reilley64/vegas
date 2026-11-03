#pragma once
#include <cstdint>

enum ANIM_GROUP_ENUM;
namespace fnv_0097feb0 { class Actor; }
struct CombatState;
struct OffsetActor;
struct OffsetVector;
struct VtableOwner;

// 0x0097f2d0
char FUN_0097f2d0(char *);
// 0x0097f2f0
char GetByteAtOffset70(char *);
// 0x0097f310
bool FUN_0097f310(::VtableOwner *, intptr_t);
// 0x0097fb20
bool FUN_0097fb20(::CombatState *);
// 0x0097fd80
bool GetActorSlotExtent(::OffsetActor *, int, ::OffsetVector &);
// 0x0097feb0
namespace fnv_0097feb0 { float FUN_0097feb0(::fnv_0097feb0::Actor *, ::ANIM_GROUP_ENUM); }
