#pragma once
#include <cstdint>

class NiQuaternion;
class NiStream;
namespace fnv_00a6d2d0 { class TCTimeNode; }
struct NiQuaternionConjugateValue;
struct Quaternion;
struct TCAV;
struct TCReg;

// 0x00a6d0f0
bool FUN_00a6d0f0(::TCReg *, intptr_t, ::NiStream &);
// 0x00a6d190
char *FUN_00a6d190(const char *, intptr_t);
// 0x00a6d2d0
namespace fnv_00a6d2d0 { void FUN_00a6d2d0(::fnv_00a6d2d0::TCTimeNode *); }
// 0x00a6d390
void StartControllersRecursive(::TCAV *, float);
// 0x00a6dc00
::NiQuaternionConjugateValue NiQuaternionConjugate(const ::NiQuaternionConjugateValue &);
// 0x00a6dc30
float FUN_00a6dc30(float, float);
// 0x00a6dc90
::NiQuaternion FUN_00a6dc90(const ::NiQuaternion &);
// 0x00a6dd50
::Quaternion *FUN_00a6dd50(::Quaternion *, const ::Quaternion *, ::Quaternion *, const ::Quaternion *);
