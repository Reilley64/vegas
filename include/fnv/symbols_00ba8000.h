#pragma once
class NiStream;

#include <cstdint>

struct BSSP_stub2;
struct BSSP_stub4;
struct BSSP_stub;
class CloningProcess;
struct FUN_00ba8c30_shell2;
struct SpawnedObject;

// 0x00ba8a00
::SpawnedObject *FUN_00ba8a00();
// 0x00ba8a70
struct FUN_00ba8a70_shell { void FUN_00ba8a70(::NiStream& kStream); };
// 0x00ba8b10
void FUN_00ba8b10(::BSSP_stub4 *, int, ::BSSP_stub4 *, ::CloningProcess *);
// 0x00ba8b60
void FUN_00ba8b60(bool);
// 0x00ba8be0
void FUN_00ba8be0(::BSSP_stub *, int, std::intptr_t);
// 0x00ba8c00
void AllocateElemArray(::BSSP_stub2 *, int, unsigned char);
// 0x00ba8c30
void FUN_00ba8c30(::FUN_00ba8c30_shell2 *, int);
// 0x00ba8cd0
void FUN_00ba8cd0(char *);
// 0x00ba8a80
struct FUN_00ba8a80_shell { bool FUN_00ba8a80(::NiStream& kStream); };
