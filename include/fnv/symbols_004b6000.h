#pragma once

class FUN_004b6ce0_cls;
class FUN_00b668b0;
class NiAVObject;
class NiCamera;
class NiObj6220;
class NiPoint3;
namespace fnv_004b68a0 { struct ArrSI; }
namespace fnv_004b68a0 { struct FUN_004b68a0_data; }
namespace fnv_004b6bc0 { struct bhkCollisionObject; }
namespace fnv_004b6c20 { struct hkpWorldObject; }
namespace fnv_004b6c70 { struct bhkCollisionObject; }
struct AVObjectEx;
struct FUN_004b6a00_data;
struct bhkCollisionObject;

// 0x004b61d0
bool FUN_004b61d0(::NiPoint3, ::NiCamera *, float);
// 0x004b6220
float GetAnimValueByPrefix(::NiObj6220 *, const char *, const char *);
// 0x004b6360
void FUN_004b6360(::NiAVObject *, const ::NiPoint3 *, ::FUN_00b668b0 *);
// 0x004b6630
void FUN_004b6630(::NiAVObject *);
// 0x004b66d0
int CountCollisionObjects(::NiAVObject *, bool, bool, bool);
// 0x004b6740
void FUN_004b6740(::NiAVObject *, char *);
// 0x004b6810
int FilterByFlags(void *, int, bool, bool, bool);
// 0x004b68a0
namespace fnv_004b68a0 { void FUN_004b68a0(::fnv_004b68a0::ArrSI *, ::fnv_004b68a0::FUN_004b68a0_data *); }
// 0x004b6980
int FUN_004b6980(::NiAVObject *, void *, bool, bool, bool);
// 0x004b6a00
void ProcessObjectMatch(::NiAVObject *, ::FUN_004b6a00_data *);
// 0x004b6ae0
int FUN_004b6ae0(::NiAVObject *);
// 0x004b6b20
void FUN_004b6b20(::bhkCollisionObject *, void *);
// 0x004b6b60
int FUN_004b6b60(::NiAVObject *, void *);
// 0x004b6bc0
namespace fnv_004b6bc0 { void FUN_004b6bc0(::fnv_004b6bc0::bhkCollisionObject *, void *); }
// 0x004b6c20
namespace fnv_004b6c20 { ::fnv_004b6c20::hkpWorldObject *FindCollisionObjectByIndex(::NiAVObject *, int); }
// 0x004b6c70
namespace fnv_004b6c70 { void FUN_004b6c70(::fnv_004b6c70::bhkCollisionObject *, int *); }
// 0x004b6ce0
void FUN_004b6ce0(::FUN_004b6ce0_cls *);
// 0x004b6dc0
void SetObjectFormID(::NiAVObject *, unsigned int);
// 0x004b6e70
const char *GetStringAtOffset13C(const char *);
// 0x004b6e90
namespace fnv_004b6e90 { void AttachLightingPropertyRecursive(::NiAVObject *); }
// 0x004b6f90
void EnsureLightingProperty(::AVObjectEx *);
