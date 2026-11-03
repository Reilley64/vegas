#pragma once

#include "havok/hkBase.h"
namespace VehicleFrictionApply { struct TimeStepInfo; }
namespace VehicleFrictionApply { struct VehicleSimulationData; }
namespace VehicleFrictionApply { struct hkpVehicleFrictionDescription; }
namespace VehicleFrictionApply { struct hkpVehicleFrictionStatus; }
struct CurveInput;
struct CurveOutput;
struct MatResult;
struct MatrixNm;

// 0x00e590f0
::MatResult SolveMatrixColumns(void *, ::MatrixNm &, ::MatrixNm &, int, float);
// 0x00e592a0
void PrefixSum(float *, unsigned int);
// 0x00e59340
::hkBool InvertMatrix2x2(const float *, float *, float);
// 0x00e593f0
void FUN_00e593f0(::CurveInput *, ::CurveOutput *);
// 0x00e59a40
namespace VehicleFrictionApply { extern "C" void FUN_00e59a40(const ::VehicleFrictionApply::TimeStepInfo &, const ::VehicleFrictionApply::hkpVehicleFrictionDescription &, ::VehicleFrictionApply::VehicleSimulationData &, ::VehicleFrictionApply::hkpVehicleFrictionStatus &); }
