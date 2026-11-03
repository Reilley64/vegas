#pragma once

struct Buffer;
struct Result;
struct S_00dd0260_PadJac;
struct S_00dd0260_PadSpu;
struct S_00dd0260_QueryIn;
struct S_00dd0260_Vector4;
struct VectorA;
struct VectorB;

// 0x00dd0260
void ComputeJacobian(const ::S_00dd0260_Vector4 &, const ::S_00dd0260_Vector4 &, const ::S_00dd0260_QueryIn &, ::S_00dd0260_PadJac, ::S_00dd0260_PadSpu);
// 0x00dd03c0
void FUN_00dd03c0(::VectorA *, ::VectorB *, ::Result *, ::Buffer *);
