// fallout/ai/lowprocess_ExtraDataList.h: declares ExtraDataList
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_0041c8d0_shell.h"
#include "fnv/decl/fnv_00421310__FUN_00421310_shell.h"
class RegionPoint;
// Source layout: ExtraDataList. PC corrections are in generate_headers.py.
#ifndef FNV_EXTRADATALIST_H
#define FNV_EXTRADATALIST_H
#include "layout_support.h"
#include "BaseExtraList.h"
class ExtraDataList : public BaseExtraList
{
  public:
    RegionPoint* GetStartingPositionData();

    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
};
#endif
