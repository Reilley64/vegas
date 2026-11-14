#pragma once

namespace InvalidateTimDetail { struct Input; }
namespace InvalidateTimDetail { struct Node; }
struct FUN_00cfdc90_Obj;
struct FnvCtx;
struct FnvNode;
struct LinkNode;
struct hkpSimpleContactConstraintAtomCFD2;

// 0x00cfd950
namespace fnv_00cfd950 { void FUN_00cfd950(::hkpSimpleContactConstraintAtomCFD2 *, int); }
// 0x00cfdbe0
void FUN_00cfdbe0(::InvalidateTimDetail::Node *, const ::InvalidateTimDetail::Input &);
// 0x00cfdc90
void DispatchSlotCallback(::FUN_00cfdc90_Obj *, float, float, void *);
// 0x00cfdd70
void *FindEntryValue(::LinkNode *, ::LinkNode *);
// 0x00cfdf60
void GetNodePairValue(::FnvNode **, ::FnvNode **, ::FnvCtx *, int *, int *);
