#pragma once
struct NiStream;
#include <cstdint>

class NiDirectionalLight;
class NiTriBasedGeomData;

// 0x00a75650
void *FUN_00a75650(void *);
// 0x00a756d0
void *FUN_00a756d0();
// 0x00a75c10
void FUN_00a75c10();
// 0x00a75c20
void *FUN_00a75c20(char *);
// 0x00a75d50
::NiDirectionalLight *CreateNiDirectionalLight();
// 0x00a75e20
::NiTriBasedGeomData *FUN_00a75e20(::NiTriBasedGeomData *);
// 0x00a75ec0
::NiTriBasedGeomData *FUN_00a75ec0(::NiTriBasedGeomData *);
// 0x00a75f00
struct FUN_00a75f00_shell { bool FUN_00a75f00(::NiStream& kStream); };
// 0x00a75f10
intptr_t FUN_00a75f10(char *);
