// Source layout: ExtraDataList. PC corrections are in generate_headers.py.
#ifndef FNV_EXTRADATALIST_H
#define FNV_EXTRADATALIST_H
#include "layout_support.h"
#include "BaseExtraList.h"
class ExtraDismemberedLimbs;
class ExtraDataList : public BaseExtraList
{
  public:
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
    ExtraDismemberedLimbs* GetDismemberedLimbs();
public:
    void RemoveExtraDataType0x15();
};
#endif
