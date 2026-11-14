#pragma once

struct hkVector4;
namespace CapsuleMassSimd { struct CapsuleMassVector; }
struct Receiver;
struct hkpMassProperties;

// 0x00cee290
int FUN_00cee290(const ::hkVector4 &, const ::hkVector4 &, const ::hkVector4 &, float, float, ::hkpMassProperties &);
// 0x00ceeca0
namespace CapsuleMassSimd { int FUN_00ceeca0(const ::CapsuleMassSimd::CapsuleMassVector *, const ::CapsuleMassSimd::CapsuleMassVector *, float, float, ::Receiver *); }
