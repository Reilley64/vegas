#pragma once

class Script;
class SpawnedObject;
struct FunctionData;

// 0x00682320
bool FUN_00682320(const ::FunctionData *, unsigned int);
// 0x00682380
bool FUN_00682380(unsigned short *, unsigned int);
// 0x006823d0
::Script *FUN_006823d0(unsigned int, const ::FunctionData *);
// 0x00682740
void ReleaseSpawnedObject(::SpawnedObject *);
