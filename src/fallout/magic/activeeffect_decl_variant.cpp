
// src/fallout/magic/activeeffect_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00805920: the skeleton of src/fallout/magic/activeeffect.cpp
// with declarations corrected to what the original code does (activeeffect_local.h: virtual void LoadGame(Actor* apActor); -> virtual void @@LGTMP@@;; activeeffect_local.h: virtual void LoadGame(BGSLoadFormBuffer* apBuf -> virtual void LoadGame(Actor* apActor);; activeeffect_local.h: virtual void @@LGTMP@@; -> virtual void LoadGame(BGSLoadFormBuffer* apBuf). Move the function to its real unit once
// that unit declares it this way.

#include "fnv/decl/BGSDebris.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00404390_shell.h"
#include "fnv/decl/FUN_004044d0_shell.h"
#include "fnv/decl/FUN_00408680_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_0049bb50_shell.h"
#include "fnv/decl/FUN_00693d50_shell.h"
#include "fnv/decl/FUN_007df210_shell.h"
#include "fnv/decl/FUN_00804250_shell.h"
#include "fnv/decl/FUN_00806420_shell.h"
#include "fnv/decl/FUN_00833c20_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00857bd0.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/Self.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/W004702f0.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00804000.h"
#include "fnv/symbols_00806000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "activeeffect_local_decl_activeeffect.h"
class ActiveEffectLoadDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* pBuffer);
};
class MagicCaster
{
  public:
    static MagicCaster* GetCasterByHandle(unsigned int id);
};
class MagicTarget
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual bool IsActor();
    char data[12];
    static int CompareActiveEffects(ActiveEffect*, ActiveEffect*);
    static MagicTarget* GetMagicTargetByID(unsigned int id);
};
class MagicItem
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual MagicSystem__SpellType GetSpellType();
    char prefix[8];
    EffectItemList effects;
    static MagicItem* GetMagicItemByID(unsigned int id);
};
class Actor : public ActorPrimary, public MagicTarget, public ActorValueOwner
{
};
class SpellItem : public MagicItem
{
};
class AlchemyItem : public MagicItem
{
  public:
    void* FUN_004030b0();
};
class MagicHitEffectLoadDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void InitLoadGame(BGSLoadFormBuffer* pBuffer);
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer*);
};
class ActiveEffectLoadGameDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
class ActiveEffectInitLoadGameDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void InitLoadGame(Actor*);
};

class TESSaveLoadGame
{
  public:
};
extern const char DAT_010793e0[];
// @fnv 0x00805920
ActiveEffect* FUN_00805920(BGSLoadFormBuffer* buffer)
{
    unsigned short effectSize = 28;
    unsigned int magicItemID;
    unsigned char recordIndex;
    MagicItem* magicItem;
    if (reinterpret_cast<::FUN_008df040_shell *>((::g_TESSaveLoadGame))->FUN_008df040() >= 42)
        reinterpret_cast<::FUN_008579e0_shell *>((::g_TESSaveLoadGame))->FUN_008579e0(&effectSize, 2);
    reinterpret_cast<::FUN_00857aa0 *>((::g_TESSaveLoadGame))->ValidateFormIDArray(&magicItemID, 4);
    reinterpret_cast<::FUN_008579e0_shell *>((::g_TESSaveLoadGame))->FUN_008579e0(&recordIndex, 1);
    magicItem = MagicItem::GetMagicItemByID(magicItemID);
    if (magicItem)
    {
        EffectItem* effect = ((::EffectItem *)(reinterpret_cast<::HX *>(&(magicItem->effects))->FUN_00406ee0(recordIndex)));
        if (effect)
        {
            ActiveEffect* active = MagicEffectSystem::Activate(0, magicItem, effect, 0);
            active->LoadGame(buffer);
            return active;
        }
    }
    reinterpret_cast<::FUN_00857bd0 *>((::g_TESSaveLoadGame))->Init(effectSize);
    ::FUN_005b5e40();
    return 0;
}
