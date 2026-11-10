#pragma once
#include <cstdint>

struct CellMopp;
class TESFile;
template <class> class BSSimpleList;

// 0x00537b10
::BSSimpleList< ::TESFile *> *GetSourceFilesFromForm(char *);
// 0x00537b30
::CellMopp *GetCellMopp(char *);
// 0x00537bd0
namespace fnv_00537bd0 { const char *GetStringAtOffset(const char *); }
// 0x00537d60
void *FUN_00537d60_Create(unsigned int, uintptr_t, unsigned int, int, int);
