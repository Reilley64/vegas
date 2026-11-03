#pragma once
#include <cstdint>

namespace fnv_004a5100 { struct FUN_004a5100; }
struct BGSPrimitiveBox;
struct Point3;

// 0x004a5040
::BGSPrimitiveBox *CreatePrimitiveBox(::Point3 *, std::intptr_t);
// 0x004a5100
namespace fnv_004a5100 { ::fnv_004a5100::FUN_004a5100 *FUN_004a5100_create(float, std::intptr_t); }
