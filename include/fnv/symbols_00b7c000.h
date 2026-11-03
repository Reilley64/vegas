#pragma once
#include <cstdint>

class NiNode;
namespace fnv_00b7cb00 { struct LightMatrix; }
namespace fnv_00b7cb00 { struct ScaleSource; }
struct B7C1F0Property;
struct Matrix;
struct NiD3DShader;
struct SlotObject;
template <class> struct NiPointer;

// 0x00b7c0a0
void FUN_00b7c0a0(::NiD3DShader *, uintptr_t, unsigned int);
// 0x00b7c120
void FUN_00b7c120(intptr_t);
// 0x00b7c150
void SetEntryField(intptr_t);
// 0x00b7c170
void FUN_00b7c170(intptr_t);
// 0x00b7c190
void UpdateSlotFromGlobal(intptr_t);
// 0x00b7c1f0
void FUN_00b7c1f0(::B7C1F0Property *, uintptr_t, unsigned int, bool);
// 0x00b7c230
void FUN_00b7c230(char *, uintptr_t, int, unsigned char);
// 0x00b7c2c0
void SetSlotValue(::SlotObject *, int, int);
// 0x00b7c3a0
void UpdateFogShaderConstants();
// 0x00b7c7b0
namespace fnv_00b7c7b0 { void FUN_00b7c7b0(uintptr_t); }
// 0x00b7c850
void UpdateLightShaderConstants(const ::Matrix *, float);
// 0x00b7cb00
namespace fnv_00b7cb00 { void UpdateShaderLights(const ::fnv_00b7cb00::LightMatrix *, float, ::fnv_00b7cb00::ScaleSource *); }
// 0x00b7ce30
void DeleteNiNodePointerArray(::NiPointer< ::NiNode> *);
// 0x00b7cfb0
void SetPassValues(uintptr_t);
