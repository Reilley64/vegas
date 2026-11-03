
// src/fallout/interface/inventorylist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/inventorylist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_004be2d0_shell.h"
#include "fnv/symbols_00469000.h"
struct InventoryStackRecord
{
};
// @fnv 0x00719c80
int __cdecl FUN_00719c80(InventoryStackRecord* pFirst, InventoryStackRecord* pSecond)
{
    return ::FUN_00469880((void *)(((const unsigned char *)(reinterpret_cast<::FUN_004be2d0_shell *>((pFirst))->GetTargetFullName()))), (void *)(((const unsigned char *)(reinterpret_cast<::FUN_004be2d0_shell *>((pSecond))->GetTargetFullName()))));
}
