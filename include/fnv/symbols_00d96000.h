#pragma once

namespace fnv_00d969e0 { struct A0Cls; }
namespace fnv_00d969e0 { struct Ev; }
namespace fnv_00d969e0 { struct Out; }
struct D96600Blob;
struct PoolSet;
struct DynamicsJob;
struct JobRecord;
struct S00d967a0_Rec;
struct S_00d96530_Header;

// 0x00d96530
::S_00d96530_Header *AllocateBlockHeader(int, int);
// 0x00d96600
int PopPart(int, int, ::D96600Blob *, ::D96600Blob *);
// 0x00d967a0
int SplitRecord(int, int, ::S00d967a0_Rec *, ::S00d967a0_Rec *);
// 0x00d968e0
int TryCreateSubtype14Job(void *, void *, const ::DynamicsJob &, ::JobRecord &);
// 0x00d969e0
namespace fnv_00d969e0 { int FUN_00d969e0(::fnv_00d969e0::A0Cls *, ::PoolSet *, ::fnv_00d969e0::Ev *, ::fnv_00d969e0::Out *); }
