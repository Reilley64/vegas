#pragma once

struct Src;
namespace fnv_00d01380 { struct World833; }
namespace fnv_00d01440 { struct World833; }
struct D014F0World;
struct D015A0World;
struct D01650World;
struct D017B0World;
struct D019B0Event;
struct D019B0World;
struct D01CE0Context;
struct D01E50Node;
struct ParamObj;
struct RemovedEvent;
struct S00d01850_Out;
struct S00d01850_Owner;
struct S011b0_Island;
struct S011b0_World;
struct S_00d01bc0_Owner;
struct WorldD;
struct hkpWorld;

// 0x00d011b0
void FUN_00d011b0(::S011b0_World *, ::S011b0_Island *);
// 0x00d01380
namespace fnv_00d01380 { void FUN_00d01380(::fnv_00d01380::World833 *); }
// 0x00d01440
namespace fnv_00d01440 { void FUN_00d01440(::fnv_00d01440::World833 *, void *); }
// 0x00d014f0
void FUN_00d014f0(::D014F0World *, void *);
// 0x00d015a0
void FUN_00d015a0(::D015A0World *, void *, void *);
// 0x00d01650
void FUN_00d01650(::D01650World *, void *, void *);
// 0x00d01700
void FUN_00d01700(::hkpWorld *, void *, int);
// 0x00d017b0
void NotifyEntityRemoved(::D017B0World *, void *);
// 0x00d01850
void FUN_00d01850(::S00d01850_Owner *, ::S00d01850_Out *);
// 0x00d01900
void FUN_00d01900(::WorldD *, ::RemovedEvent &);
// 0x00d019b0
void NotifyShapeSetListeners(::D019B0World *, ::D019B0Event *);
// 0x00d01bc0
void FUN_00d01bc0(::S_00d01bc0_Owner *);
// 0x00d01ce0
void ApplyActionPhases(::D01CE0Context *);
// 0x00d01d20
void FUN_00d01d20(::Src *);
// 0x00d01df0
void ProcessChildLoop(::ParamObj *);
// 0x00d01e50
int DispatchNodeByKind(void *, ::D01E50Node *);
