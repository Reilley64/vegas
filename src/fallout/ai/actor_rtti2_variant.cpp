// src/fallout/ai/actor_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESBoundObject). The skeleton of src/fallout/ai/actor.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00453700_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_00491180_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00494710_shell.h"
#include "fnv/decl/FUN_0049bdc0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_0098adb0_shell.h"
#include "fnv/decl/FUN_009acce0_shell.h"
#include "fnv/decl/FUN_009c8d60_t.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/ThisStub.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/UAMActor.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004955c0__FUN_004955c0_t.h"
#include "fnv/decl/fnv_00567050__FUN_00567050_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00895110__PickActor.h"
#include "fnv/decl/fnv_0089f580__ActorStub.h"
#include "fnv/decl/fnv_008b28c0__This8b.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "actor_rtti2_actor.h"

// Reuse complete component classes when this code is inserted into actor.cpp.
__if_not_exists(BGSPickupPutdownSounds::BGSPickupPutdownSounds)
{
    class BGSPickupPutdownSounds : public BaseFormComponent
    {
      public:
        TESSound* m_pPickupSound;
        TESSound* m_pPutdownSound;
    };
}
__if_not_exists(BGSEquipType::BGSEquipType)
{
    class BGSEquipType : public BaseFormComponent
    {
      public:
        static int GetEquipType(TESForm*);
        int m_eEquipType;
    };
}

struct PickupSoundActorView : public Actor
{
    char* FUN_008adcf0(::TESBoundObject*, bool, bool);
};

struct PickupSoundVirtualView
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual char* s76();
};
struct PickupPutdownSoundView
{
};
struct PickupAlchemySoundView
{
};
int _FNV_GetFormType(void* pThis);
// @fnv 0x008adcf0
char* PickupSoundActorView::FUN_008adcf0(::TESBoundObject* apobjREFR, bool abPickUp, bool abUse)
{
    const char* soundname;
    {
        BGSPickupPutdownSounds* ppickupPutdownSound;
        {
            int eformType;
            {
                AlchemyItem* ping;
                if (!apobjREFR)
                    return 0;
                ppickupPutdownSound = dynamic_cast<BGSPickupPutdownSounds*>(apobjREFR);
                soundname = 0;
                if (!abUse && abPickUp && ppickupPutdownSound &&
                    reinterpret_cast<::Callees *>((((PickupPutdownSoundView*)ppickupPutdownSound)))->FUN_00726070())
                {
                    return ((PickupSoundVirtualView*)reinterpret_cast<::Callees *>((((PickupPutdownSoundView*)ppickupPutdownSound)))->FUN_00726070())
                        ->s76();
                }
                else if (!abUse && !abPickUp && ppickupPutdownSound &&
                         ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((((PickupPutdownSoundView*)ppickupPutdownSound)))->GetName())))
                {
                    return ((PickupSoundVirtualView*)((void *)(reinterpret_cast<::Twin_0044ddc0 *>((((PickupPutdownSoundView*)ppickupPutdownSound)))->GetName())))
                        ->s76();
                }
                eformType = apobjREFR ? _FNV_GetFormType(apobjREFR) : 0;
                switch (eformType)
                {
                case 0x2f:
                    if (!abUse)
                    {
                    }
                    else
                    {
                        ping = (AlchemyItem*)apobjREFR;
                        return ((void *)(reinterpret_cast<::FUN_009acce0_shell *>((((PickupAlchemySoundView*)ping)))->GetFieldC8()))
                                   ? ((PickupSoundVirtualView*)((void *)(reinterpret_cast<::FUN_009acce0_shell *>((((PickupAlchemySoundView*)ping)))->GetFieldC8())))->s76()
                                   : 0;
                    }
                    break;
                case 0x28:
                    switch (BGSEquipType::GetEquipType((TESForm*)apobjREFR))
                    {
                    case 0:
                        return abPickUp ? "UIItemGunsBigUp" : "UIItemGunsBigDown";
                    case 2:
                        return abPickUp ? "UIItemGunsSmallUp" : "UIItemGunsSmallDown";
                    case 3:
                        return abPickUp ? "UIItemMeleeUp" : "UIItemMeleeDown";
                    }
                    break;
                }
                return abPickUp == true ? "UIItemGenericUp" : "UIItemGenericDown";
            }
        }
    }
}
