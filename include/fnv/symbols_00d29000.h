#pragma once

namespace ApplyAccumulatorsPrivate { class QuantizedBoundsData; }
namespace ApplyAccumulatorsPrivate { class hkStepInfo; }
namespace ApplyAccumulatorsPrivate { class hkpMotion; }
namespace ApplyAccumulatorsPrivate { struct ConstraintSolverInfo; }
struct ContextA0;
struct SourceItem;
struct TargetItem;

// 0x00d29830
::TargetItem *FUN_00d29830(::ContextA0 *, ::SourceItem **, int, int, ::TargetItem *);
// 0x00d29bf0
namespace ApplyAccumulatorsPrivate { extern "C" int FUN_00d29bf0(const ::ApplyAccumulatorsPrivate::ConstraintSolverInfo &, const ::ApplyAccumulatorsPrivate::hkStepInfo &, const ::ApplyAccumulatorsPrivate::QuantizedBoundsData *, ::ApplyAccumulatorsPrivate::hkpMotion *const *, int, int); }
