// Source layout: ExtraContainerChanges. PC corrections are in generate_headers.py.
#ifndef FNV_EXTRACONTAINERCHANGES_H
#define FNV_EXTRACONTAINERCHANGES_H
#include "layout_support.h"
#include "BSExtraData.h"
class ExtraContainerChanges : public BSExtraData
{
  public:
    InventoryChanges* pChanges;  // +0xC
    ExtraContainerChanges(InventoryChanges* changes);
};
#endif
