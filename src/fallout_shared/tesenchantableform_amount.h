// fallout_shared/tesenchantableform_amount.h: declares TESEnchantableForm, EnchantmentItem, BGSCameraPath
#ifndef FNV_TESENCHANTABLEFORM_AMOUNT_H
#define FNV_TESENCHANTABLEFORM_AMOUNT_H


#include "fnv/decl/Callees.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "BaseFormComponent.h"

class EnchantmentItem;

#include "tesenchantableform.h"

class TESForm;
class EnchantmentItem : public TESForm
{
  public:
    char _pdbpad_18[28];
    char data[16];
public:
    bool IsValidObject(::TESForm *);
};
class BGSCameraShot;
template <class> class BSSimpleList;
class BGSCameraPath
{
  public:
    int HasNameForWarning();
public:
    ::BSSimpleList< ::BGSCameraShot *> *GetShotList();
};
#endif
