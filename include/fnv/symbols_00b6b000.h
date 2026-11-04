#pragma once
#include <cstdint>

#include <cstdint>

class B6B610Wrapper;
class BSShaderAccumulator;
class NiCamera;
class NiRenderTargetGroup;
class ShaderAccB6BA;
namespace fnv_00b6bbd0 { class NiPixelFormat; }
namespace fnv_00b6bbd0 { class NiTexture; }
struct Accumulator6b;
struct FUN_00b6b180_Obj;
struct FUN_00b6b180_Tex;
struct FUN_00b6b930_Object;
struct NiRenderTargetGroup;
struct PixelData;
struct PointerList6b;

// 0x00b6b050
void PushRefCountedSlot(int *);
// 0x00b6b0b0
namespace fnv_00b6b0b0 { void FUN_00b6b0b0(); }
// 0x00b6b180
::FUN_00b6b180_Tex *FUN_00b6b180(::FUN_00b6b180_Obj *, ::FUN_00b6b180_Tex *);
// 0x00b6b610
::B6B610Wrapper *CreateWrapperFromGeometry(void *, void *, void *, void *, void *, void *, void *, void *, void *);
// 0x00b6b6c0
namespace fnv_00b6b6c0 { void ClearAndUnlockRenderer(); }
// 0x00b6b7d0
void FUN_00b6b7d0(::NiRenderTargetGroup *, unsigned int);
// 0x00b6b840
void FUN_00b6b840();
// 0x00b6b890
void FUN_00b6b890(int, std::intptr_t);
// 0x00b6b8d0
bool FUN_00b6b8d0(intptr_t, ::NiRenderTargetGroup *);
// 0x00b6b910
void CopyBlock48(void *, const void *);
// 0x00b6b930
void FUN_00b6b930(uintptr_t, ::FUN_00b6b930_Object *);
// 0x00b6b940
void FUN_00b6b940(::PixelData *);
// 0x00b6ba20
void FUN_00b6ba20(::NiCamera *, ::ShaderAccB6BA *);
// 0x00b6bbd0
namespace fnv_00b6bbd0 { ::fnv_00b6bbd0::NiTexture *FUN_00b6bbd0(::fnv_00b6bbd0::NiTexture *, const ::fnv_00b6bbd0::NiPixelFormat *); }
// 0x00b6bee0
void FUN_00b6bee0(void *, void *, ::BSShaderAccumulator *);
// 0x00b6bfc0
void FUN_00b6bfc0(void *, ::PointerList6b &, ::Accumulator6b *);
