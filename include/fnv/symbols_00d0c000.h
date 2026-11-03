#pragma once

struct ArrayRef_cls;
struct ByteArray;
struct CollidableD0;
struct CollisionEvent;
struct CollisionQueue;
struct Flags_cls;
struct Island;
struct PairArrayD0;
struct S_00d0c6d0_ByteArray;
struct S_00d0c6d0_EntryArray;
struct SolverInfo;
struct SrcA;
struct ThingP;
struct ThingX;
struct Vec;
struct WorldD0;

// 0x00d0c030
void UpdateBroadPhasePairs(::CollidableD0 **, int, ::WorldD0 *, ::PairArrayD0 &, ::PairArrayD0 &);
// 0x00d0c480
void ProcessCollisionEvent(void *, ::CollisionEvent *, float, ::CollisionQueue *);
// 0x00d0c6d0
void FUN_00d0c6d0(::S_00d0c6d0_EntryArray *, int *, ::S_00d0c6d0_ByteArray *);
// 0x00d0c790
void UpdateIslandMotionStates(::Island *, ::ByteArray *, ::SolverInfo *);
// 0x00d0c9c0
void FUN_00d0c9c0(::ThingX **, int, ::ThingP *, int, bool);
// 0x00d0cde0
void FUN_00d0cde0(float, char *, ::Flags_cls *, ::ArrayRef_cls *);
// 0x00d0ceb0
unsigned char *CollectMatchingEntries(unsigned char *, ::SrcA *, ::Vec *, int, ::Vec *);
