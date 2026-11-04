#pragma once

struct D9Body;
struct D9Contact;
struct D9Shape;
struct D9Solver;
struct Derived;
struct IncomingBatch;
struct ListenerArg;
struct PendingBatch;
struct S_00d9ec40_Entry;
struct S_00d9ec40_Less;
struct S_Owner;
struct Target;
struct hkArray12_8b0;
struct hkArray16_8b0;

// 0x00d9e250
void PassObjectToTarget(::Derived *, void *, ::Target *);
// 0x00d9e2e0
void FUN_00d9e2e0(::S_Owner *, ::ListenerArg, int);
// 0x00d9e4a0
void FUN_00d9e4a0(::PendingBatch &, ::IncomingBatch &);
// 0x00d9e8b0
void FUN_00d9e8b0(::hkArray16_8b0 *, ::hkArray12_8b0 *volatile);
// 0x00d9ec40
void QuickSortEntries(::S_00d9ec40_Entry *, int, int, ::S_00d9ec40_Less);
// 0x00d9ee50
void FUN_00d9ee50(::D9Solver *, const ::D9Contact &, void *, ::D9Body *, ::D9Body *, ::D9Shape *, ::D9Shape *, float &);
