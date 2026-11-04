#pragma once

class QuantizedBoundsData;
class SolverSchemaHeader;
struct ConstraintSolverInfo;
struct FloatRecord;

// 0x00def570
void FUN_00def570(const ::ConstraintSolverInfo &, const ::FloatRecord *, const ::SolverSchemaHeader *, const ::QuantizedBoundsData *);
