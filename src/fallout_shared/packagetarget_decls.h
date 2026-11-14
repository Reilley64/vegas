// fallout_shared/packagetarget_decls.h: declares BGSCameraPath
#ifndef FNV_PACKAGETARGET_DECLS_H
#define FNV_PACKAGETARGET_DECLS_H

#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
enum PACK_LOC_TYPE
{
    PACK_LOC_TYPE_INVALID = -1
};
class TESForm;
class BGSCameraShot;
class PerkEntryConditionSet;
template <class> class BSSimpleList;
class BGSCameraPath
{
  public:
    int HasNameForWarning();
public:
    ::PerkEntryConditionSet *GetConditions();
public:
    ::BSSimpleList< ::BGSCameraShot *> *GetShotList();
};
#endif
