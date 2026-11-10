#pragma once

namespace fnv_0081e040 { struct GameTimerRecord; }
namespace fnv_0081e040 { struct S86a0; }
namespace fnv_0081e040 { struct Vector3; }
struct FUN_0081e440_Object;
struct MarkerErrorObj;
class NiAVObject;

// 0x0081e040
namespace fnv_0081e040 { void FUN_0081e040(void *, unsigned int, unsigned int, int, ::fnv_0081e040::GameTimerRecord *, ::fnv_0081e040::S86a0 *, ::fnv_0081e040::Vector3, ::fnv_0081e040::Vector3); }
// 0x0081e310
::MarkerErrorObj *GetMarkerErrorObj();
// 0x0081e440
void FUN_0081e440(::FUN_0081e440_Object *);
// 0x0081e460
::NiAVObject *LoadAndCloneModel(const char *);
