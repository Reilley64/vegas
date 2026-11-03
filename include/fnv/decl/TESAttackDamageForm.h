#pragma once

class BaseFormComponent;

class TESAttackDamageForm {
public:
    // 0x0047fdc0
    TESAttackDamageForm();
    // 0x0047fdf0
    ~TESAttackDamageForm();
    // 0x0047fe30
    void FUN_0047fe30(::BaseFormComponent *);
    // 0x0047ff30
    unsigned short GetAttackDamage();
};
