#pragma once
#include <cstdint>

class B55480AVObject;
class BSFogProperty;
class NiAVObject;
class NiGeometry;
struct NiPoint3;
struct PropHelper;
struct Shader;

// 0x00b55360
void ProcessPropertyTree(::PropHelper *, int);
// 0x00b553d0
void FUN_00b553d0(::NiGeometry *, ::NiPoint3 *);
// 0x00b55480
void SetPropertyValueRecursive(::B55480AVObject *, int);
// 0x00b55520
::BSFogProperty *FUN_00b55520(int);
// 0x00b55560
::Shader *FUN_00b55560(unsigned int);
// 0x00b557d0
void FUN_00b557d0();
// 0x00b55a10
void FUN_00b55a10();
// 0x00b55ac0
void FUN_00b55ac0(void *, void *, void *);
// 0x00b55b00
void FUN_00b55b00(::PropHelper *, float);
// 0x00b55b80
void FUN_00b55b80(::NiAVObject *);
// 0x00b55bb0
void FUN_00b55bb0();
