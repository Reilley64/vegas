// fallout_shared/tesenchantableform.h: declares TESEnchantableForm
#ifndef FNV_TESENCHANTABLEFORM_H
#define FNV_TESENCHANTABLEFORM_H


#include "fnv/decl/Callees.h"
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

#endif
