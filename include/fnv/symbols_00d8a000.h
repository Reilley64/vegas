#pragma once

class PoweredChainAccumulator;
class QuantizedBoundsData;
class SolverSchemaHeader;
namespace PoweredChainSolver { struct PoweredChainStepTemp; }
struct ConstraintSolverInfo;
struct FloatRecord;
struct PoweredChainResult;
struct PoweredChainSchema;
struct PoweredChainSettings;

// 0x00d8a3a0
void FUN_00d8a3a0(const ::PoweredChainSettings &, const ::PoweredChainSolver::PoweredChainStepTemp &, ::PoweredChainAccumulator *, ::PoweredChainSchema *, ::PoweredChainResult *);
// 0x00d8aac0
extern "C" void FUN_00d8aac0(const ::ConstraintSolverInfo &, const ::SolverSchemaHeader *, ::QuantizedBoundsData *, ::FloatRecord *);
