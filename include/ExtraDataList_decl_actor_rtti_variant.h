// Source layout: ExtraDataList. PC corrections are in generate_headers.py.
#ifndef FNV_EXTRADATALIST_H
#define FNV_EXTRADATALIST_H

#include "fnv/decl/BaseExtraList_shell.h"
#include "layout_support.h"
#include "BaseExtraList.h"
class ExtraDismemberedLimbs;
class ExtraDataList : public BaseExtraList
{
  public:
      // declared for the original code (decl_variants.py)

  public:
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};
#endif
