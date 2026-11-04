#pragma once
#include <cstdint>

class BSXFlags;
class NiAVObject;
class NiBound;
class NiCamera;
class NiNode;
class NiObjectNET;
class NiPoint3;
class TESSound;
struct BSShaderPPLightingProperty;
struct FNVNode;
struct FormLike;
struct TESCombatStyle;

// 0x004b5260
namespace fnv_004b5260 { ::NiAVObject *FUN_004b5260(::NiAVObject *); }
// 0x004b52f0
void *FUN_004b52f0(void *);
// 0x004b5400
float FUN_004b5400(void *);
// 0x004b5440
bool FUN_004b5440(const ::NiPoint3 &, const ::NiPoint3 &, float);
// 0x004b5470
int FUN_004b5470(::TESCombatStyle *, float);
// 0x004b54c0
float FUN_004b54c0(float);
// 0x004b5510
float FUN_004b5510(float);
// 0x004b5530
float FUN_004b5530(float);
// 0x004b5550
float FUN_004b5550(float, float);
// 0x004b5570
float FUN_004b5570(float, float);
// 0x004b55e0
unsigned int FindAcceptedForm(::FNVNode *);
// 0x004b5710
::BSShaderPPLightingProperty *FindPPLightingProperty(::NiNode *);
// 0x004b5820
uintptr_t FUN_004b5820(::FormLike *);
// 0x004b5950
void *FUN_004b5950(const void *);
// 0x004b5980
int FUN_004b5980(intptr_t);
// 0x004b59c0
const void *FUN_004b59c0(const char *);
// 0x004b59d0
const void *FUN_004b59d0(const char *);
// 0x004b59f0
void *FUN_004b59f0(const void *);
// 0x004b5a80
void *FUN_004b5a80(const void *);
// 0x004b5aa0
unsigned int DeallocateIfPresent(::TESSound *);
// 0x004b5b20
bool HandleUnparentedObjectNode(::NiNode *);
// 0x004b5bf0
bool FUN_004b5bf0(::NiAVObject *);
// 0x004b5c80
bool IsObjectNetValid(::NiObjectNET *);
// 0x004b5d10
bool RemoveInvalidChildNodes(::NiNode *);
// 0x004b5fa0
bool FUN_004b5fa0(const ::BSXFlags *);
// 0x004b5fc0
bool FUN_004b5fc0(::NiAVObject *, ::NiCamera *);
// 0x004b5ff0
bool IsBoundVisible(::NiBound *, ::NiCamera *);
