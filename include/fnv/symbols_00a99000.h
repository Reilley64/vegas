#pragma once
struct NiStream;

class NiExtraData;
struct NiFogProperty;

// 0x00a99710
void *FUN_00a99710();
// 0x00a99a10
::NiExtraData *FUN_00a99a10();
// 0x00a99cd0
::NiExtraData *FUN_00a99cd0();
// 0x00a99fd0
::NiFogProperty *CreateNiFogProperty();
// 0x00a99e40
struct FUN_00a99e40_shell { bool FUN_00a99e40(::NiStream& kStream); };
