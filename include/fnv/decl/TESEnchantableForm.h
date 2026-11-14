#pragma once

class EnchantmentItem;
class TESForm;

class TESEnchantableForm {
public:
    // 0x004830a0
    TESEnchantableForm();
    // 0x00483170
    void SetFormEnchantmentAmount(unsigned short);
    // 0x00483210
    void InitItem(::TESForm *);
    // 0x004be330
    static ::EnchantmentItem *FindFormEnchantment(::TESForm *);
};
