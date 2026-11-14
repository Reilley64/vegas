#pragma once

class Quad8;
class hkVec8;
struct AngularJac;
struct AngularMotorInfo;
struct BodyRecord;
struct CfmRecord;
struct ChainState;
struct InputStruct;
struct LinearJac;
struct MatrixTriple;
struct OffsetRecord;
struct PoweredChain;
class hkAabb;
struct hkChainInfo;

// 0x00df1060
void FUN_00df1060(int, int, const ::ChainState &, ::Quad8 *);
// 0x00df11a0
void FUN_00df11a0(::InputStruct *, ::hkAabb *);
// 0x00df1260
extern "C" void FUN_00df1260(::PoweredChain *, int *, int *, float *);
// 0x00df1430
void FUN_00df1430(const ::hkChainInfo &, int &, int &, ::hkVec8 *, void *);
// 0x00df19e0
void FUN_00df19e0(int, const ::CfmRecord &, ::AngularMotorInfo *, ::LinearJac *, ::AngularJac *__restrict, ::OffsetRecord *, const ::BodyRecord *, ::MatrixTriple *, int);
