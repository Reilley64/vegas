// bscore/bssimplelist_decls.h: declares TESDataHandler
#ifndef FNV_BSSIMPLELIST_DECLS_H
#define FNV_BSSIMPLELIST_DECLS_H

class InventoryStackRecord;
#include "fnv/bs_simple_list.h"
class TESClass;
class TESDataHandler
{
  public:
    BSSimpleList<TESClass*>* GetTESClassList();
};
#endif
