#pragma once

namespace ApplyForcesStepPrivate { struct MotionList; }
namespace ApplyForcesStepPrivate { struct SolverInfo; }
namespace ApplyForcesStepPrivate { struct TimeInterval; }
namespace ApplyForcesStepPrivate { struct Vec; }
namespace ApplyForcesStepPrivate { template <class> struct Ref; }
namespace StepReleaseFitPrivate { struct StepReleaseFitStepArgs; }

// 0x00d28560
bool FUN_00d28560(void *, char **, int, int);
// 0x00d28680
namespace StepReleaseFitPrivate { extern "C" void FUN_00d28680(::StepReleaseFitPrivate::StepReleaseFitStepArgs); }
// 0x00d28a30
namespace ApplyForcesStepPrivate { extern "C" int FUN_00d28a30(::ApplyForcesStepPrivate::Ref<const ::ApplyForcesStepPrivate::SolverInfo>, const ::ApplyForcesStepPrivate::TimeInterval *, ::ApplyForcesStepPrivate::Ref<const ::ApplyForcesStepPrivate::Vec>, ::ApplyForcesStepPrivate::MotionList, int, int); }
