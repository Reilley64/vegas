#pragma once

class hkVector4;
struct HkShape;
struct MassBody;
struct Mat4CE;
struct hkpMassProperties;

// 0x00cef6d0
int FUN_00cef6d0(const ::hkVector4 &, const ::hkVector4 &, float, float, ::hkpMassProperties &);
// 0x00ceff00
void FUN_00ceff00(::HkShape *, const ::Mat4CE &, float, ::MassBody &);
