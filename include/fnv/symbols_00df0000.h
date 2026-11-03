#pragma once

struct ConstraintSolverState;
struct FUN_00df0810_Dest;
struct FUN_00df0810_Source;
struct JacBlock;
struct MotionArgument;
struct VelocityPair;

// 0x00df0680
void FUN_00df0680();
// 0x00df06a0
void ResetJacobianRows(unsigned char *, bool, ::JacBlock *, ::JacBlock *);
// 0x00df07c0
void FUN_00df07c0(const unsigned char *, ::MotionArgument);
// 0x00df0810
void CopyChannelValue(int, int, ::FUN_00df0810_Source *, ::FUN_00df0810_Dest *);
// 0x00df0d30
extern "C" void FUN_00df0d30(const ::ConstraintSolverState &, ::VelocityPair *);
