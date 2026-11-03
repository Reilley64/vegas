#pragma once

class hkpVelocityAccumulatorQ;
namespace hkSolverQ { struct SolverStepInfo; }
struct BeginArg;
struct ProbeHeader;
struct SpawnedElem;
struct SpawnedOwner;
struct hkpJacobianBallSocketChainSchemaQ;
struct hkpSolverElemTempQ;
struct hkpSolverInfoQ;

// 0x00d892d0
void FUN_00d892d0();
// 0x00d893a0
void FUN_00d893a0(const void *, void *, void *, ::ProbeHeader *, float *);
// 0x00d89690
void FUN_00d89690(const ::hkpSolverInfoQ &, const ::hkSolverQ::SolverStepInfo &, ::hkpVelocityAccumulatorQ *, ::hkpJacobianBallSocketChainSchemaQ *, ::hkpSolverElemTempQ *);
// 0x00d89ed0
void FUN_00d89ed0(::SpawnedOwner *, ::BeginArg, ::SpawnedElem *);
