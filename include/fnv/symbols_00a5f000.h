#pragma once
#include <cstdint>

namespace fnv_00a5ff10 { struct OwnerTriple; }
namespace fnv_00a5ff10 { struct RefCounted; }
namespace fnv_00a5ff10 { struct Texture; }
struct FnvSourceTexture;
struct NiObjectBase;
struct NiProperty;
struct TextureListView;

// 0x00a5f030
::NiObjectBase *FUN_00a5f030();
// 0x00a5f0d0
char *BuildSourceString(const char *, int);
// 0x00a5f280
::NiProperty *FUN_00a5f280();
// 0x00a5f7b0
void FUN_00a5f7b0(intptr_t);
// 0x00a5f800
void FUN_00a5f800(::TextureListView *);
// 0x00a5fe30
::FnvSourceTexture *FUN_00a5fe30(std::intptr_t, const char *, const int *, unsigned char);
// 0x00a5ff10
namespace fnv_00a5ff10 { ::fnv_00a5ff10::Texture *FUN_00a5ff10(::fnv_00a5ff10::RefCounted *, void *, const ::fnv_00a5ff10::OwnerTriple *); }
