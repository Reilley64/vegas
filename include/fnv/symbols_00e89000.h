#pragma once
#include <cstdint>

class D3DRenderStateGroup;
struct Counts;
struct Pair;
struct PoolItemStub;
struct SNAEntryElem;

// 0x00e89220
void ClearFields(void *);
// 0x00e89460
::SNAEntryElem *FUN_00e89460(unsigned int);
// 0x00e895f0
void FUN_00e895f0();
// 0x00e89630
::PoolItemStub *AllocatePoolItem();
// 0x00e89670
void ResetAndRegister(::D3DRenderStateGroup *);
// 0x00e89ad0
void FUN_00e89ad0(intptr_t);
// 0x00e89d50
const char *GetHResultName(unsigned int);
// 0x00e89ed0
intptr_t SelectFormatTileValue(::Pair *, ::Counts *);
