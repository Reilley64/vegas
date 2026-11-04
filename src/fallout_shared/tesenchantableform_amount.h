// fallout_shared/tesenchantableform_amount.h: declares TESEnchantableForm, EnchantmentItem, BGSCameraPath
#ifndef FNV_TESENCHANTABLEFORM_AMOUNT_H
#define FNV_TESENCHANTABLEFORM_AMOUNT_H


#include "fnv/decl/Callees.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "BaseFormComponent.h"

class EnchantmentItem;

enum MagicSystemCastingType
{
    MAGIC_SYSTEM_CAST_ONCE = 0,
    MAGIC_SYSTEM_WHEN_USED = 1,
    MAGIC_SYSTEM_WHEN_STRIKES = 2,
    MAGIC_SYSTEM_CONSTANT_EFFECT = 3,
    MAGIC_SYSTEM_CASTING_COUNT = 4
};

class TESEnchantableForm : public BaseFormComponent
{
  public:
    static EnchantmentItem* FindFormEnchantment(class TESForm* form);
    TESEnchantableForm();
    void InitializeComponent();
    void SetFormEnchantmentAmount(unsigned short amount);
    void InitItem(class TESForm* owner);

    EnchantmentItem* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    unsigned char paddingA[2];
    MagicSystemCastingType m_eCastingType;
};

#include "tesenchantableform_decls.h"

// @fnv 0x004be330
EnchantmentItem* TESEnchantableForm::FindFormEnchantment(TESForm* form)
{
    TESEnchantableForm* enchantable = dynamic_cast<TESEnchantableForm*>(form);
    return enchantable ? (EnchantmentItem*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)enchantable)))->FUN_00726070())) : 0;
}

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
