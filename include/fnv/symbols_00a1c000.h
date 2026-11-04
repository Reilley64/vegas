#pragma once

#include <cstdint>

class Menu;
struct CompressedXML;
struct MenuValueDescriptor;

// 0x00a1c6f0
void FUN_00a1c6f0();
// 0x00a1c790
void FUN_00a1c790();
// 0x00a1c800
void FUN_00a1c800();
// 0x00a1c9b0
::MenuValueDescriptor *GetOrLoadXML(const char *, bool);
// 0x00a1ca20
namespace fnv_00a1ca20 { void RemoveMenuEntries(const char *, ::Menu *); }
// 0x00a1cb60
void FUN_00a1cb60(const char *, std::uintptr_t);
// 0x00a1ce70
::CompressedXML *LoadCompressedXML(const char *, const char *);
