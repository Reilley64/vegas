// fallout_shared/region system/tesregionpointlist_cell.h: declares TESRegionList, TESRegionPointList_CellExtraList, TESObjectCELL

#include "fnv/decl/FUN_0041bbd0_shell.h"
#include "fnv/decl/FUN_0041bce0_class.h"
class TESRegionList
{
  public:
    unsigned char layout[16];
    TESRegionList(int);
};
class TESRegionPointList_CellExtraList
{
  public:
};
class TESObjectCELL
{
  public:
    unsigned char prefix[0x28];
    TESRegionPointList_CellExtraList extraData;
    bool IsCellInterior() const;
    TESRegionList* GetRegionList(bool);
};
