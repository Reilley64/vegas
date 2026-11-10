#pragma once

class GlobalObject_004aff00;
struct GlobalObject_00869f00;
struct Arr;
struct Caller008693c0;
struct FUN_008693f0_Class;
struct RefList;

// 0x00869190
void SetTlsFlag(bool);
// 0x00869420
void FUN_00869420(::RefList *, ::RefList *);
// 0x008694c0
void ForEachNavMesh(::GlobalObject_004aff00 *, ::Caller008693c0 *);
// 0x00869510
void CopyNonNullElements(::GlobalObject_00869f00 *, ::GlobalObject_00869f00 *);
// 0x00869560
void FUN_00869560(::Arr *, ::FUN_008693f0_Class *);
// 0x008696c0
void FUN_008696c0(void *);
// 0x00869840
void **AllocateUIntArray(unsigned int);
// 0x00869f30
void RunModeSwitch(int);
