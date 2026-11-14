#pragma once
#include <cstdint>

class NiPixelData;
class NiPixelFormat;
struct NiPoint3;
struct ActorCombatGroup;
struct CheckerColor;
struct FUN_00a62a40_this;
struct NiStream;
struct Settings_a62;
struct Vector4f;
template <class, class> class NiTArray;
template <class> class NiTMallocInterface;

// 0x00a62030
void FUN_00a62030();
// 0x00a62090
namespace fnv_00a62090 { void FUN_00a62090(); }
// 0x00a62130
bool FUN_00a62130(void *, int, ::NiStream *);
// 0x00a62150
void SwapByteQuadWords(::Vector4f *, unsigned int);
// 0x00a622d0
void ApplySettings(const ::Settings_a62 &);
// 0x00a62330
::NiPixelData *CreateCheckerboardTexture(const ::CheckerColor &, const ::CheckerColor &, const ::NiPixelFormat &, unsigned int);
// 0x00a62a10
intptr_t DispatchIfHighBitSet(intptr_t, int, int);
// 0x00a62a40
void FUN_00a62a40(::FUN_00a62a40_this *, int, ::NiTArray< ::ActorCombatGroup *, ::NiTMallocInterface< ::ActorCombatGroup *>> *);
// 0x00a62be0
bool FUN_00a62be0(const ::NiPoint3 **, const ::NiPoint3 *, const ::NiPoint3 *, float, ::NiPoint3 *, ::NiPoint3 *, ::NiPoint3 &);
