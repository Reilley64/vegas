#pragma once

struct CellMopp;
struct TESFile;
template <class> struct BSSimpleList;

// 0x00537b10
::BSSimpleList< ::TESFile *> *GetSourceFilesFromForm(char *);
// 0x00537b30
::CellMopp *GetCellMopp(char *);
// 0x00537bd0
namespace fnv_00537bd0 { const char *GetStringAtOffset(const char *); }
// 0x00537d60
void *FUN_00537d60_Create(unsigned int, unsigned int, unsigned int, int, int);
