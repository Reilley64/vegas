#pragma once

struct Info_dcf880;
struct Input102;
struct Input_dcf280;
struct Input_dcf5b0;
struct Jac_dcf880;
struct Jacobian_dcf280;
struct Jacobian_dcf5b0;
struct ObjA;
struct ObjB;
struct QueryIn_dcf880;
struct QueryOut_dcf880;
struct Row102;
struct S00dcfec0_V;
struct S_00dcf100_Cfg;
struct S_00dcf100_In;
struct S_00dcf100_Out;
struct S_00dcf720_Info;
struct S_00dcf720_Jacobian;
struct S_00dcf720_QueryIn;
struct hkVector4;

// 0x00dcf100
void FUN_00dcf100(::S_00dcf100_In *, ::S_00dcf100_Cfg *, ::S_00dcf100_Out **);
// 0x00dcf280
void FUN_00dcf280(::Input_dcf280 *, ::S_00dcf100_Cfg *, ::Jacobian_dcf280 **);
// 0x00dcf5b0
void FUN_00dcf5b0(::Input_dcf5b0 *, ::S_00dcf100_Cfg *, ::Jacobian_dcf5b0 **, float);
// 0x00dcf720
void FUN_00dcf720(const ::S_00dcf720_Info &, const ::S_00dcf720_QueryIn &, ::S_00dcf720_Jacobian *, float);
// 0x00dcf880
void ComputeAngularJacobian(const ::Info_dcf880 &, const ::QueryIn_dcf880 &, ::QueryOut_dcf880 &);
// 0x00dcfa30
void FUN_00dcfa30(::Info_dcf880 *, ::S_00dcf100_Cfg *, ::Jac_dcf880 **);
// 0x00dcfc00
void FUN_00dcfc00(const ::hkVector4 *, const ::hkVector4 *, float, const ::Input102 *, ::Row102 *);
// 0x00dcfec0
void FUN_00dcfec0(const ::S00dcfec0_V &, const ::S00dcfec0_V &, const ::S00dcfec0_V &, const ::S00dcfec0_V &, ::S00dcfec0_V &, float &);
// 0x00dcfff0
void FUN_00dcfff0(::ObjA *, ::ObjB *, float *);
