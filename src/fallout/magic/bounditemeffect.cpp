
// src/fallout/magic/bounditemeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/bounditemeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/save_load_game_view.h"
#include "InventoryStackRecord.h"
#include "fnv/effect_item_fields.h"
#include "fnv/active_effect_fields.h"
#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AssociatedItemCopyEntry.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatState.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_0041ab70_shell.h"
#include "fnv/decl/FUN_0041b010.h"
#include "fnv/decl/FUN_0041b040_shell.h"
#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004811e0_shell.h"
#include "fnv/decl/FUN_004bc780_shell.h"
#include "fnv/decl/FUN_004bed00_host.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00806c20_cls.h"
#include "fnv/decl/FUN_00806da0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_0088c650_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004064d0__EffectItemList.h"
#include "fnv/decl/fnv_0040fe20__FUN_0040fe20_shell.h"
#include "fnv/decl/fnv_00412380__FUN_00412380_shell.h"
#include "fnv/decl/fnv_0041afa0__FUN_0041afa0_Class.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_004be5a0__InventoryChangesSaveSize.h"
#include "fnv/decl/fnv_004be6f0__SaveInventory.h"
#include "fnv/decl/fnv_004be930__FUN_004be930_shell.h"
#include "fnv/decl/fnv_004bfda0__FUN_004bfda0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00804210__ActiveEffectUpdateShell.h"
#include "fnv/decl/fnv_00806de0__AssociatedItemEffect.h"
#include "fnv/decl/fnv_00806e70__AssociatedItemEffect.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008a6970__FUN_008a6970_shell.h"
#include "fnv/decl/s88c790__Actor.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_0103b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
class Actor;
struct MagicTarget
{
    virtual ~MagicTarget()
    {}
public:
    ::Actor *GetOwnerActor() const;
};

struct Character : MagicTarget
{
    virtual ~Character()
    {}
};

struct BoundItemEffect
{
    bool IsTargetCharacter(MagicTarget* apTarget);
};

// Returns true if apTarget is a Character, using a dynamic_cast to check the type.
// @fnv 0x008099c0
bool BoundItemEffect::IsTargetCharacter(MagicTarget* apTarget)
{
    Character* pActor = dynamic_cast<Character*>(apTarget);
    return pActor != 0;
}

struct FUN_00807eb0_shell : BoundItemEffect
{
    void* FUN_00807eb0(unsigned int flags);
    void FUN_00807ee0();
};
struct MagicCaster;
struct MagicItem;
struct EffectItem;
struct InventoryStackRecord;

struct Actor;
struct AssociatedItemEffect
{
public:
    void FUN_00806e30(::Actor *);
};

struct FUN_00807e10 : AssociatedItemEffect
{
    FUN_00807e10(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    char pad01[0xa4];
    char unka4;
    char unka5;
    char unka6;
    char unka7;
    char unka8;
    char pada9[0x2];
};

extern void* DAT_0107979c;

// Calls the base AssociatedItemEffect constructor, installs the vtable, and zeroes the derived fields at offsets 0x4c through 0xa8.
// @fnv 0x00807e10
FUN_00807e10::FUN_00807e10(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect)
{
    new ((void *)this) ::FUN_00806c20_cls(apCaster, apSpell, (::FUN_00806c20_helper1 *)(apEffect));
    *(void**)this = &DAT_0107979c;
    *(InventoryStackRecord**)((char*)this + 0x4c) = 0;
    int i;
    for (i = 0; i < 0x14; i++)
        *(InventoryStackRecord**)((char*)this + 0x50 + i * 4) = 0;
    *(float*)((char*)this + 0xa0) = 0.0f;
    this->unka4 = 0;
    this->unka5 = 0;
    this->unka6 = 0;
    this->unka7 = 0;
    this->unka8 = 0;
}

struct TESBoundObject
{
    virtual void vfunc00();
};

struct ModelS
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0c();
    virtual void vfunc10();
    virtual const char* GetModelPath();
    unsigned int GetModelLength() const;
};

struct TESObjectWEAP : TESBoundObject
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    ModelS model;
};

struct TESNPC : TESBoundObject
{
    int GetSex();
};

class BGSBipedModelList;
enum BIPED_OBJECT;
struct TESBipedModelForm
{
    virtual void vfunc00();
public:
    bool HasBipedModel(::BIPED_OBJECT, bool, ::BGSBipedModelList *);
};

struct RefS
{
};

struct CasterS
{
    virtual void vfunc00();
    virtual RefS* GetCasterRef();
};

struct XDataS
{
};

struct XListS
{
};

struct EntryS
{
    TESBoundObject* GetType();
    ~EntryS();
};

struct EffItemS
{
};

struct ModelHolderS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ModelS model;
};

struct EffListS
{
};

struct MagicItemS
{
    int unk00;
    int unk04;
    int unk08;
    EffListS list;
    ModelHolderS* GetHolder(int aiFlag);
};

struct LoaderS
{
};


struct BaseEffectS
{
    virtual ~BaseEffectS();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
};

struct FUN_00807ee0 : BaseEffectS
{
    EntryS* unk4c;
    EntryS* unk50[20];
    bool unka0;
    bool unka1;
    bool unka2;
    bool unka3;
    bool unka4;
    bool unka5;
    bool unka6;
    bool unka7;
    virtual ~FUN_00807ee0();
};
// Calls FUN_00807ee0, then frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00807eb0
void* FUN_00807eb0_shell::FUN_00807eb0(unsigned int flags)
{
    reinterpret_cast<::FUN_00807ee0 *>(this)->FUN_00807ee0::~FUN_00807ee0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00807ee0
FUN_00807ee0::~FUN_00807ee0()
{
    if (unk4c && unka6)
    {
        TESBoundObject* pObject = reinterpret_cast<::InventoryStackRecord *>(unk4c)->m_pItemObject;
        TESObjectWEAP* pWeap = dynamic_cast<TESObjectWEAP*>(pObject);
        if (pWeap && pWeap->model.GetModelLength() > 0)
            reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::LoaderS * *>(&::g_modelLoader))))->FUN_00445300((char *)(pWeap->model.GetModelPath()), false, 1);
    }
    if (unka7)
    {
        int iSex = 0;
        if (((::CasterS *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) && ((::CasterS *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetCasterRef())
        {
            TESNPC* pNPC = dynamic_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::CasterS *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetCasterRef()))->FUN_007af430())));
            if (pNPC)
                iSex = pNPC->GetSex();
        }
        for (int i = 0; i < 20; i++)
        {
            if (unk50[i] && reinterpret_cast<::InventoryStackRecord *>(unk50[i])->m_pItemObject)
            {
                TESBipedModelForm* pBiped = dynamic_cast<TESBipedModelForm*>(reinterpret_cast<::InventoryStackRecord *>(unk50[i])->m_pItemObject);
                if (pBiped)
                {
                    unka7 = true;
                    reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::LoaderS * *>(&::g_modelLoader))))->FUN_00445300((char *)(reinterpret_cast<::FUN_004811e0_shell *>((pBiped))->FUN_004811e0(iSex)), false, 1);
                }
            }
        }
    }
    if (unk4c)
    {
        XDataS* pXData = ((::XListS *)(::FUN_00559450((int *)(unk4c)))) ? *((::XDataS **)(&reinterpret_cast<::SimpleListNodeView*>(((::XListS *)(::FUN_00559450((int *)(unk4c)))))->m_item)) : 0;
        if (pXData)
            reinterpret_cast<::fnv_0041afa0::FUN_0041afa0_Class *>((pXData))->FUN_0041afa0();
        reinterpret_cast<::FUN_004bc780_shell *>((unk4c))->ClearExtraDataList();
        delete unk4c;
    }
    for (int j = 0; j < 20; j++)
    {
        if (unk50[j])
        {
            XDataS* pXData2 = ((::XListS *)(::FUN_00559450((int *)(unk50[j])))) ? *((::XDataS **)(&reinterpret_cast<::SimpleListNodeView*>(((::XListS *)(::FUN_00559450((int *)(unk50[j])))))->m_item)) : 0;
            if (pXData2)
                reinterpret_cast<::fnv_0041afa0::FUN_0041afa0_Class *>((pXData2))->FUN_0041afa0();
            reinterpret_cast<::FUN_004bc780_shell *>((unk50[j]))->ClearExtraDataList();
            delete unk50[j];
        }
    }
    if (unka5 && ((::MagicItemS *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell)) && ((::EffItemS *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect)))
    {
        ModelHolderS* pHolder = ((::MagicItemS *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell))->GetHolder(0);
        EffItemS* pFound = ((::EffItemS *)(reinterpret_cast<::fnv_004064d0::EffectItemList *>(&(((::MagicItemS *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell))->list))->FindCostliestEffectItem(reinterpret_cast<::EffectItemFields *>(reinterpret_cast<::ActiveEffectFields *>(this)->effect)->range, 0)));
        if (pHolder->model.GetModelLength() > 0 && ((::EffItemS *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect)) == pFound)
            reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::LoaderS * *>(&::g_modelLoader))))->FUN_00445300((char *)(pHolder->model.GetModelPath()), false, 1);
        unka5 = false;
    }
}


struct MagicCaster;
struct MagicItem;
struct EffectItem;

class B085F0Effect
{
  public:
    B085F0Effect(MagicCaster* pkCaster, MagicItem* pkItem, EffectItem* pkEffectItem);


    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
};

// Allocates a B085F0Effect via its constructor from the caster, item and effect item, and returns the new object.
// @fnv 0x008085f0
B085F0Effect* __cdecl FUN_008085f0(MagicCaster* pkCaster, MagicItem* pkItem, EffectItem* pkEffectItem)
{
    return new B085F0Effect(pkCaster, pkItem, pkEffectItem);
}

struct AEEntry
{
    void* pExtendData;
    int iCount;
    TESBoundObject* pType;

    AEEntry(AEEntry* apSource);
    TESBoundObject* GetType();
};

struct AERef
{
};

struct AECaster
{
    virtual void v00();
    virtual AERef* GetCasterRef();
};

struct AEModelLoader
{
};


struct AEEffect
{
    void* pVtable;
    int unk04;
    MagicItem* pSpell;
    EffectItem* pEffect;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    MagicCaster* m_pEffectInstance;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    AEEntry* pItem;
    AEEntry* pItems[20];
    int unkA0;
    bool bFlagA4;
    bool unkA5;
    bool bWeaponQueued;
    bool bBipedQueued;
    int unkA8;

    AEEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    AEEffect* Clone();
};

// Creates a copy of this effect, deep-copies its item entries, queues weapon and biped models on the loader, and copies bFlagA4.
// @fnv 0x008082c0
AEEffect* AEEffect::Clone()
{
    AEEffect* pNewInstance = new AEEffect(m_pEffectInstance, pSpell, pEffect);
    reinterpret_cast<::AssociatedItemCopyEntry *>(this)->FUN_00806d50((::ActiveEffect *)(pNewInstance));
    if (pItem)
        pNewInstance->pItem = new AEEntry(pItem);
    for (int i = 0; i < 20; i++)
    {
        if (pItems[i])
            pNewInstance->pItems[i] = new AEEntry(pItems[i]);
    }

    if (pItem && bWeaponQueued)
    {
        TESBoundObject* pType = reinterpret_cast<::InventoryStackRecord *>(pItem)->m_pItemObject;
        TESObjectWEAP* pWeapon = dynamic_cast<TESObjectWEAP*>(pType);
        if (pWeapon && pWeapon->model.GetModelLength() > 0)
        {
            pNewInstance->bWeaponQueued = true;
            reinterpret_cast<::QueueHelper *>(((*reinterpret_cast<::AEModelLoader * *>(&::g_modelLoader))))->FUN_00444040((intptr_t)(pWeapon->model.GetModelPath()), 0, 0, 0, true, true, false);
        }
    }

    if (bBipedQueued)
    {
        int iSex = 0;
        if (((::AECaster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetCasterRef())
        {
            TESNPC* pNPC = dynamic_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::AECaster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetCasterRef()))->FUN_007af430())));
            if (pNPC)
                iSex = pNPC->GetSex();
        }
        for (int j = 0; j < 20; j++)
        {
            if (pItems[j] && reinterpret_cast<::InventoryStackRecord *>(pItems[j])->m_pItemObject)
            {
                TESBipedModelForm* pBiped = dynamic_cast<TESBipedModelForm*>(reinterpret_cast<::InventoryStackRecord *>(pItems[j])->m_pItemObject);
                if (pBiped)
                {
                    pNewInstance->bBipedQueued = true;
                    reinterpret_cast<::QueueHelper *>(((*reinterpret_cast<::AEModelLoader * *>(&::g_modelLoader))))->FUN_00444040((intptr_t)(reinterpret_cast<::FUN_004811e0_shell *>((pBiped))->FUN_004811e0(iSex)), 0, 0, 0, true, true, false);
                }
            }
        }
    }
    pNewInstance->bFlagA4 = bFlagA4;
    return pNewInstance;
}

struct TESForm
{
    virtual void formVirtual();
};
struct TESObjectARMO : TESForm
{
};
struct ItemData
{
};
struct ItemList
{
};
struct ItemEntry
{
    TESObjectWEAP* GetType();
};
struct Proc
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf00a();
    virtual void vf00b();
    virtual void vf00c();
    virtual void vf00d();
    virtual void vf00e();
    virtual void vf00f();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf01a();
    virtual void vf01b();
    virtual void vf01c();
    virtual void vf01d();
    virtual void vf01e();
    virtual void vf01f();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf02a();
    virtual void vf02b();
    virtual void vf02c();
    virtual void vf02d();
    virtual void vf02e();
    virtual void vf02f();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf03a();
    virtual void vf03b();
    virtual void vf03c();
    virtual void vf03d();
    virtual void vf03e();
    virtual void vf03f();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf04a();
    virtual void vf04b();
    virtual void vf04c();
    virtual void vf04d();
    virtual void vf04e();
    virtual void vf04f();
    virtual void vf050();
    virtual void vf051();
    virtual ItemEntry* GetEntry();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf05a();
    virtual void vf05b();
    virtual void vf05c();
    virtual void vf05d();
    virtual void vf05e();
    virtual void vf05f();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf06a();
    virtual void vf06b();
    virtual void vf06c();
    virtual void vf06d();
    virtual void vf06e();
    virtual void vf06f();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf07a();
    virtual void vf07b();
    virtual void vf07c();
    virtual void vf07d();
    virtual void vf07e();
    virtual void vf07f();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf08a();
    virtual void vf08b();
    virtual void vf08c();
    virtual void vf08d();
    virtual void vf08e();
    virtual void vf08f();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf09a();
    virtual void vf09b();
    virtual void vf09c();
    virtual void vf09d();
    virtual void vf09e();
    virtual void vf09f();
    virtual void vf0a0();
    virtual void vf0a1();
    virtual void vf0a2();
    virtual void vf0a3();
    virtual void vf0a4();
    virtual void vf0a5();
    virtual void vf0a6();
    virtual void vf0a7();
    virtual void vf0a8();
    virtual void vf0a9();
    virtual void vf0aa();
    virtual void vf0ab();
    virtual void vf0ac();
    virtual void vf0ad();
    virtual void vf0ae();
    virtual void vf0af();
    virtual void vf0b0();
    virtual void vf0b1();
    virtual void vf0b2();
    virtual void vf0b3();
    virtual void vf0b4();
    virtual void vf0b5();
    virtual void vf0b6();
    virtual void vf0b7();
    virtual void vf0b8();
    virtual void vf0b9();
    virtual void vf0ba();
    virtual void vf0bb();
    virtual void vf0bc();
    virtual void vf0bd();
    virtual void vf0be();
    virtual void vf0bf();
    virtual void vf0c0();
    virtual void vf0c1();
    virtual void vf0c2();
    virtual void vf0c3();
    virtual void vf0c4();
    virtual void vf0c5();
    virtual void vf0c6();
    virtual void vf0c7();
    virtual void vf0c8();
    virtual void vf0c9();
    virtual void vf0ca();
    virtual void vf0cb();
    virtual void vf0cc();
    virtual void vf0cd();
    virtual void vf0ce();
    virtual void vf0cf();
    virtual void vf0d0();
    virtual void vf0d1();
    virtual void vf0d2();
    virtual void vf0d3();
    virtual void vf0d4();
    virtual void vf0d5();
    virtual void vf0d6();
    virtual void vf0d7();
    virtual void vf0d8();
    virtual void vf0d9();
    virtual void vf0da();
    virtual void vf0db();
    virtual void vf0dc();
    virtual void vf0dd();
    virtual void vf0de();
    virtual void vf0df();
    virtual void vf0e0();
    virtual void vf0e1();
    virtual void vf0e2();
    virtual void vf0e3();
    virtual void vf0e4();
    virtual void vf0e5();
    virtual void vf0e6();
    virtual void vf0e7();
    virtual void vf0e8();
    virtual void vf0e9();
    virtual void vf0ea();
    virtual void vf0eb();
    virtual void vf0ec();
    virtual void vf0ed();
    virtual void vf0ee();
    virtual void vf0ef();
    virtual void vf0f0();
    virtual void vf0f1();
    virtual void vf0f2();
    virtual void vf0f3();
    virtual void vf0f4();
    virtual void vf0f5();
    virtual void vf0f6();
    virtual void vf0f7();
    virtual void vf0f8();
    virtual void vf0f9();
    virtual void vf0fa();
    virtual void vf0fb();
    virtual void vf0fc();
    virtual void vf0fd();
    virtual void vf0fe();
    virtual void vf0ff();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf10a();
    virtual void vf10b();
    virtual void vf10c();
    virtual void vf10d();
    virtual void vf10e();
    virtual void vf10f();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual bool IsReady();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf11a();
    virtual void vf11b();
    virtual void vf11c();
    virtual void vf11d();
    virtual void vf11e();
    virtual void vf11f();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf12a();
    virtual void vf12b();
    virtual void vf12c();
    virtual void vf12d();
    virtual void vf12e();
    virtual void vf12f();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf13a();
    virtual void vf13b();
    virtual void vf13c();
    virtual void vf13d();
    virtual void vf13e();
    virtual void vf13f();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf14a();
    virtual void vf14b();
    virtual void Equip(TESObjectWEAP*);
};
struct ActorObj
{
};
struct TargetObj
{
};
struct Changes
{
};
struct EffectObj
{
    int unk00;
    float unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    float unka0;
    bool started;
    char unkA5;
    char unkA6;
    char unkA7;
    bool pending;
    TESForm* GetAssociated();
    void Update(float delta);
};
namespace fnv_00809a00 {
struct Actor;

struct FormIDEntry;

class TESForm
{
  public:
    virtual void Reserved00();
    virtual void Reserved01();
    virtual void Reserved02();
    virtual void Reserved03();
    virtual void Reserved04();
    virtual void Reserved05();
    virtual void Reserved06();
    virtual void Reserved07();
    virtual void Reserved08();
    virtual void Reserved09();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual char* GetSaveSizeLabel();
};

struct EffectItem

{

};

struct FUN_00806da0_shell

{

};

class TESSaveLoadGame

{

  public:


    FormIDEntry* GetCurrentFormHeader();
};


struct GlobalObject_0045cf30

{

    unsigned char* Bool();
};




struct BoundItemEffectSaveSizeLayout

{

    unsigned int unk00;

    unsigned int unk04;

    unsigned int unk08;

    unsigned int unk0c;

    unsigned int unk10;

    unsigned int unk14;

    unsigned int unk18;

    unsigned int unk1c;

    unsigned int unk20;

    unsigned int unk24;

    unsigned int unk28;

    unsigned int unk2c;

    unsigned int unk30;

    unsigned int unk34;

    unsigned int unk38;

    unsigned int unk3c;

    unsigned int unk40;

    unsigned int unk44;

    unsigned int unk48;

    EffectItem* unk4c;

    EffectItem* effectItems[20];

    unsigned short FUN_00809a00(Actor* apActor);
};

// @fnv 0x00809a00
unsigned short BoundItemEffectSaveSizeLayout::FUN_00809a00(Actor* apActor)

{

    unsigned short usSize9 = 0;

    usSize9 += reinterpret_cast<::FUN_00806da0_shell *>((((FUN_00806da0_shell*)this)))->FUN_00806da0((::Actor *)(apActor));

    unsigned short usBaseSize8 = usSize9;

    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_00809a00::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())

    {

        usSize9 += 4;

        usSize9 += 2;
    }

    usSize9 += 1;

    if (unk4c != 0)

    {

        usSize9 += reinterpret_cast<::fnv_004be5a0::InventoryChangesSaveSize *>((unk4c))->FUN_004be5a0();
    }

    int i6;

    for (i6 = 0; i6 < 20; ++i6)

    {

        usSize9 += 1;

        if (effectItems[i6] != 0)

        {

            usSize9 += reinterpret_cast<::fnv_004be5a0::InventoryChangesSaveSize *>((effectItems[i6]))->FUN_004be5a0();
        }
    }

    if ((*reinterpret_cast<::fnv_00809a00::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool()[0] != 0)

    {

        FormIDEntry* pHeader = (*reinterpret_cast<::fnv_00809a00::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))->GetCurrentFormHeader();

        if (pHeader != 0)

        {

            TESForm* pForm = ((::fnv_00809a00::TESForm *)(::FUN_004839c0(*(unsigned int*)pHeader)));

            ::FUN_0040fbe0();
        }

        else

        {

            ::FUN_0040fbe0();
        }
    }

    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_00809a00::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x41)

    {

        usSize9 += 4;

        usSize9 += 1;
    }

    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_00809a00::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x6b)

    {

        usSize9 += 1;
    }

    return usSize9;
}
}  // namespace fnv_00809a00

// Adapted from contributor Worker18 (2026-10-23); independently verified and modified.

struct Actor;


struct Obj12
{

    Obj12();

    ~Obj12();

    int f00, f04, f08;


    int FUN_004459e0(int a);
};

struct Sound
{

    virtual void v00();

    virtual void v01();

    virtual void v02();

    virtual void v03();

    virtual void v04();

    virtual void v05();

    virtual void v06();

    virtual void v07();

    virtual void v08();

    virtual void v09();

    virtual void v10();

    virtual void v11();

    virtual void v12();

    virtual void v13();

    virtual void v14();

    virtual void v15();

    virtual void v16();

    virtual void v17();

    virtual void v18();

    virtual void v19();

    virtual void v20();

    virtual void v21();

    virtual void v22();

    virtual void v23();

    virtual void v24();

    virtual void v25();

    virtual void v26();

    virtual void v27();

    virtual void v28();

    virtual void v29();

    virtual void v30();

    virtual void v31();

    virtual void v32();

    virtual void v33();

    virtual void v34();

    virtual void v35();

    virtual void v36();

    virtual void v37();

    virtual void v38();

    virtual void v39();

    virtual void v40();

    virtual void v41();

    virtual void v42();

    virtual void v43();

    virtual void v44();

    virtual void v45();

    virtual void v46();

    virtual void v47();

    virtual void v48();

    virtual void v49();

    virtual void v50();

    virtual void v51();

    virtual void v52();

    virtual void v53();

    virtual void v54();

    virtual void v55();

    virtual void v56();

    virtual void v57();

    virtual void v58();

    virtual void v59();

    virtual void v60();

    virtual void v61();

    virtual void v62();

    virtual void v63();

    virtual void v64();

    virtual void v65();

    virtual void v66();

    virtual void v67();

    virtual void v68();

    virtual void v69();

    virtual void v70();

    virtual void v71();

    virtual void v72();

    virtual void v73();

    virtual void v74();

    virtual void v75();

    virtual int VCall130();
};

struct TESSound
{

    void* m_00;
};

struct FUN_008579e0_shell
{

    void FUN_008579e0(void* buf, unsigned int n);
};

struct TimeGlobal : FUN_008579e0_shell
{

};

class TESSound;
struct EffectSetting : TimeGlobal
{

public:
    ::TESSound *GetHitSound();
};

struct TESSaveLoadGame : EffectSetting
{


};











extern char DAT_01079810;

struct This
{

    int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48;

    Obj12* m_4c;

    Obj12* m_50[20];

    int fA0;

    unsigned char fA4, fA5, fA6, fA7;

    unsigned char fA8;


    void FUN_00809e60(Actor* param);
};

// @fnv 0x00809e60
void This::FUN_00809e60(Actor* apActor)

{

    reinterpret_cast<::AssociatedItemEffect *>(this)->FUN_00806e30(apActor);

    unsigned short w18 = 0;

    char* flag = 0;

    if (reinterpret_cast<::FUN_00862110_cls *>((::g_TESSaveLoadGame))->FUN_00862110())
    {

        unsigned int i;

        ::g_TESSaveLoadGame->FUN_008579e0(&i, 4);

        if (i != 0x424c4f4b)
        {

            TESSound* rec = ((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(::g_TESSaveLoadGame))));

            if (rec != 0)
            {

                Sound* pForm;

                pForm = ((::Sound *)(::FUN_004839c0((unsigned int)(std::uintptr_t)(rec->m_00))));

                ::FUN_005b5e40();
            }
            else
            {

                ::FUN_005b5e40();
            }
        }

        flag = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;

        ::g_TESSaveLoadGame->FUN_008579e0(&w18, 2);
    }

    unsigned char n1c;

    ::g_TESSaveLoadGame->FUN_008579e0(&n1c, 1);

    if (n1c)
    {

        m_4c = new Obj12;

        reinterpret_cast<::fnv_004be930::FUN_004be930_shell *>((m_4c))->FUN_004be930();
    }

    int rec2 = 0;

    for (; rec2 < 0x14; rec2++)
    {

        ::g_TESSaveLoadGame->FUN_008579e0(&n1c, 1);

        if (n1c)
        {

            m_50[rec2] = new Obj12;

            reinterpret_cast<::fnv_004be930::FUN_004be930_shell *>((m_50[rec2]))->FUN_004be930();

            if (!((reinterpret_cast<::Twin_0044ddc0 *>((m_50[rec2]))->GetName())))
            {
                delete m_50[rec2];
                m_50[rec2] = 0;
            }
        }
    }

    fA4 = 1;

    if ((int)reinterpret_cast<::FUN_008df040_shell *>((::g_TESSaveLoadGame))->FUN_008df040() >= 0x41)
    {

        ::g_TESSaveLoadGame->FUN_008579e0(&fA0, 4);

        ::g_TESSaveLoadGame->FUN_008579e0(&fA4, 1);
    }

    if ((int)reinterpret_cast<::FUN_008df040_shell *>((::g_TESSaveLoadGame))->FUN_008df040() >= 0x6b)
    {

        ::g_TESSaveLoadGame->FUN_008579e0(&fA8, 1);
    }

    if (reinterpret_cast<::FUN_00862110_cls *>((::g_TESSaveLoadGame))->FUN_00862110())
    {

        char* ts;

        ts = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;

        TESSound* tag = ((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(::g_TESSaveLoadGame))));

        if (tag != 0)
        {

            Sound* snd2 = ((::Sound *)(::FUN_004839c0((unsigned int)(std::uintptr_t)(tag->m_00))));

            if (ts > flag + (unsigned int)w18)
            {

                ::FUN_005b5e40();
            }
            else if (ts < flag + (unsigned int)w18)
            {

                ::FUN_005b5e40();
            }
        }
        else
        {

            if (ts > flag + (unsigned int)w18)
            {

                ::FUN_005b5e40();
            }
            else if (ts < flag + (unsigned int)w18)
            {

                ::FUN_005b5e40();
            }
        }
    }
}

namespace fnv_00809bd0 {
struct SaveHeader
{
    unsigned int id;
    unsigned char unk04;
    unsigned char flags;
};
struct TESForm
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0c();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1c();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2c();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3c();
    virtual void vfunc40();
    virtual void vfunc44();
    virtual void vfunc48();
    virtual void vfunc4c();
    virtual void vfunc50();
    virtual void vfunc54();
    virtual void vfunc58();
    virtual void vfunc5c();
    virtual void vfunc60();
    virtual void vfunc64();
    virtual void vfunc68();
    virtual void vfunc6c();
    virtual void vfunc70();
    virtual void vfunc74();
    virtual void vfunc78();
    virtual void vfunc7c();
    virtual void vfunc80();
    virtual void vfunc84();
    virtual void vfunc88();
    virtual void vfunc8c();
    virtual void vfunc90();
    virtual void vfunc94();
    virtual void vfunc98();
    virtual void vfunc9c();
    virtual void vfunca0();
    virtual void vfunca4();
    virtual void vfunca8();
    virtual void vfuncac();
    virtual void vfuncb0();
    virtual void vfuncb4();
    virtual void vfuncb8();
    virtual void vfuncbc();
    virtual void vfuncc0();
    virtual void vfuncc4();
    virtual void vfuncc8();
    virtual void vfunccc();
    virtual void vfuncd0();
    virtual void vfuncd4();
    virtual void vfuncd8();
    virtual void vfuncdc();
    virtual void vfunce0();
    virtual void vfunce4();
    virtual void vfunce8();
    virtual void vfuncec();
    virtual void vfuncf0();
    virtual void vfuncf4();
    virtual void vfuncf8();
    virtual void vfuncfc();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10c();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11c();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12c();
    virtual const char* GetName();
};
struct TESSaveLoadGame
{
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct ValueReferencePair
{
};
struct SaveEffect : FUN_00807ee0
{
    bool unka8;
    void FUN_00809bd0(void* arg);
};
// Writes the effect's bound-item references and version-gated fields to the save stream, with optional block header and debug logging.
// @fnv 0x00809bd0
void SaveEffect::FUN_00809bd0(void* arg)
{
    reinterpret_cast<::fnv_00806de0::AssociatedItemEffect *>(this)->FUN_00806de0((::Actor *)(arg));
    bool present;
    int iSlot;
    unsigned short blockSize = 0;
    char* blockStart = 0;
    {
        char* uiTimestamp = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
        if (*(*reinterpret_cast<::fnv_00809bd0::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool())
            uiTimestamp = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            unsigned int tag = 0x424c4f4b;
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&tag, 4);
            blockStart = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&blockSize, 2);
        }
        present = false;
        if (unk4c)
            present = true;
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&present, 1);
        if (present)
            reinterpret_cast<::fnv_004be6f0::SaveInventory *>((((ValueReferencePair*)unk4c)))->FUN_004be6f0();
        for (iSlot = 0; iSlot < 20; iSlot++)
        {
            present = false;
            if (unk50[iSlot])
                present = true;
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&present, 1);
            if (present)
                reinterpret_cast<::fnv_004be6f0::SaveInventory *>((((ValueReferencePair*)unk50[iSlot])))->FUN_004be6f0();
        }
        if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 65)
        {
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unka0, 4);
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unka4, 1);
        }
        if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 107)
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unka8, 1);
        if (*(*reinterpret_cast<::fnv_00809bd0::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool())
        {
            char* uiHeaderPos = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
            SaveHeader* pSaveHeader = ((::fnv_00809bd0::SaveHeader *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
            if (pSaveHeader)
            {
                TESForm* form = ((::fnv_00809bd0::TESForm *)(::FUN_004839c0(pSaveHeader->id)));
                ::FUN_0040fbe0();
            }
            else
            {
                ::FUN_0040fbe0();
            }
        }
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_00809bd0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            char* uiFinishPos = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
            char* uiBeginPos = blockStart;
            if (uiFinishPos > uiBeginPos + 65535)
                ::FUN_005b5e40();
            *(unsigned short*)blockStart = (unsigned short)(uiFinishPos - uiBeginPos);
        }
    }
}
}  // namespace fnv_00809bd0

struct BIItemData
{
};
struct BIItemNode
{
};

struct BIEntry
{
    ~BIEntry();
};

struct BIChanges
{
};
struct BIWornList
{
};
struct BIWornSlot
{
};

class BIProcess
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void SetDirty(int iFlag);  // +0x450
};

struct BISound
{
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~BISound();
};

class BIActor
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void UnequipItem(void* pkForm, int iA, int iB, int iC, int iD, int iE, int iF, int iG, int iH,
                             int iI);  // +0x17c
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual int IsAlive();  // +0x1d0
    BISound FUN_00933270(const char* pcName, int iA, unsigned int uiFlags, int iB);
};

struct BIArmor
{
    int unk00[28];
    struct BISlots
    {
    } m_kSlots;  // +0x70
};

struct BIModelHolder
{
    int unk00[6];
    ModelS m_kModel;  // +0x18
};
struct BIList
{
};
struct BIEffectItem
{
    int unk00[3];
    BIList m_kList;  // +0x0c
    BIModelHolder* FUN_0040a300(int iFlag);
};
struct BINode
{
};

class BIShader
{
  public:
    BIShader(BIActor* pkActor, const char* pcModel, float fTime);
    virtual ~BIShader();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual bool Init();  // +0xc4
    int unk04[14];
};

struct BIModelLoader
{
};
struct BIShaderManager
{
};

struct BITarget
{
};

bool FUN_0080a700(BIActor* pkActor, BIEntry* pkEntry, void* pkEffect);

class BIEffect
{
  public:
    int unk00[19];
    BIEntry* m_pkWeaponEntry;       // +0x4c
    BIEntry* m_apArmorEntries[20];  // +0x50
    int unka0;
    bool m_bModifierActive;   // +0xa4
    bool m_bShowShader;       // +0xa5
    bool m_bLoadWeaponModel;  // +0xa6
    bool m_bLoadArmorModel;   // +0xa7

    TESForm* FUN_006733e0();
    void StopEffect();
};

namespace fnv_00808680 {
class NiNode;
class TESModel
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual char* GetModelPath();
    unsigned int GetModelLength() const;
};
struct EffectSettingQ
{
    char pad00[0x18];
    TESModel kModel;
};
struct EffectItem;
struct EffectItemList
{
};
class MagicItem
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual int GetType();
    char pad04[8];
    EffectItemList kList;
    EffectSettingQ* FUN_0040a300(int iUnk);
};
struct EffectItem
{
};
struct MagicTarget_00822b40
{
};
class ModelLoaderQ
{
  public:
};

class ActiveEffect
{
  public:
    void* FUN_006733e0();
    void FUN_00808680();
    char pad00[0xa0];
    float fHitEffectTime;
};

// Loads the model, sets fHitEffectTime from FUN_004b6220 for non-type-4 items with a node, and calls FUN_00445300 when the selected range item differs.
// @fnv 0x00808680
void ActiveEffect::FUN_00808680()
{
    void* pTarget = ((::fnv_00808680::MagicTarget_00822b40 *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((void *)(reinterpret_cast<::MagicTarget *>((((::fnv_00808680::MagicTarget_00822b40 *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (!FUN_006733e0() || !pTarget)
    {
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(false);
        return;
    }
    if (((::fnv_00808680::MagicItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell)) && ((::fnv_00808680::EffectItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect)))
    {
        EffectSettingQ* pBaseEffect = ((::fnv_00808680::MagicItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell))->FUN_0040a300(0);
        EffectItem* pRangeItem = ((::fnv_00808680::EffectItem *)(reinterpret_cast<::fnv_004064d0::EffectItemList *>(&(((::fnv_00808680::MagicItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell))->kList))->FindCostliestEffectItem(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_00808680::EffectItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect))))->FUN_0084e3a0(), 0)));
        if (pBaseEffect->kModel.GetModelLength() > 0)
        {
            NiNode* pNode = ((::fnv_00808680::NiNode *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((((ModelLoaderQ*)(*reinterpret_cast<::LoaderS * *>(&::g_modelLoader)))))->FUN_00447080((char *)(pBaseEffect->kModel.GetModelPath()), 0, true, false, false, false)));
            bool bIsType4 = ((::fnv_00808680::MagicItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell))->GetType() == 4;
            if (!bIsType4)
            {
                if (pNode)
                    fHitEffectTime = ::GetAnimValueByPrefix((::NiObj6220 *)(pNode), kMagicModelHitEffectName, ::g_011d4c84_arg1);
            }
            else
            {
                fHitEffectTime = 0.0f;
            }
            if (((::fnv_00808680::EffectItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect)) != pRangeItem)
                reinterpret_cast<::FUN_00445300_shell *>((((ModelLoaderQ*)(*reinterpret_cast<::LoaderS * *>(&::g_modelLoader)))))->FUN_00445300(pBaseEffect->kModel.GetModelPath(), false, 1);
        }
    }
}
}  // namespace fnv_00808680

struct ExtraP;
struct ExtraListP
{
    void FUN_005ae3d0(ExtraP**);
};
struct ExtraP
{
};
struct EntryP
{
    ExtraListP* list;
    ~EntryP();
    void* FUN_004459e0(int);
};
struct ProcessP
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual EntryP* Equipped();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void Update(int);
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void SetWeapon(TESObjectWEAP*);
};
struct InvP
{
};
struct InvHolderP
{
};
struct ActorP
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void AddItem(TESBoundObject*, ExtraP*, int);
};
struct CasterP
{
};
struct ModelLoaderP
{
};

struct FUN_00410360 : ExtraP
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    FUN_00410360();
};
struct FUN_004bc550 : EntryP
{
    int u04, u08;
    FUN_004bc550(TESBoundObject*, int);
};
struct FUN_004bc650 : EntryP
{
    int u04, u08;
    FUN_004bc650(EntryP*);
};
struct ArmorSlotsP
{
};
struct SummonArmorLayout : TESBoundObject
{
    int u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c, u40, u44, u48, u4c, u50, u54, u58,
        u5c, u60, u64, u68, u6c;
    ArmorSlotsP slots;
};

struct SexP
{
    int FUN_005f0cc0();
};
struct ArmorModelP
{
    virtual void v00();
};
struct EquipManagerP
{
};
struct EffectP : FUN_00807ee0
{
    bool unka8;
    TESForm* FUN_006733e0();
    void FUN_00808a30();
};
// @fnv 0x00808800
void EffectObj::Update(float delta)
{
    if (!started)
    {
        if (unk04 >= unka0)
        {
            reinterpret_cast<::EffectP *>(this)->FUN_00808a30();
            started = true;
        }
    }
    else
    {
        ActorObj* actor = ((::TargetObj *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::ActorObj *)(reinterpret_cast<::MagicTarget *>((((::TargetObj *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
        TESObjectWEAP* weaponA = dynamic_cast<TESObjectWEAP*>(GetAssociated());
        if (actor && ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && weaponA)
        {
            ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Equip(weaponA);
            if (pending && ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetEntry())
            {
                ItemEntry* entry2 = ((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetEntry();
                if (weaponA == ((::TESObjectWEAP *)(reinterpret_cast<::Twin_0044ddc0 *>((entry2))->GetName())) && ((::ItemList *)(::FUN_00559450((int *)(entry2)))))
                {
                    pending = false;
                    ItemData* data = *((::ItemData **)(&reinterpret_cast<::SimpleListNodeView*>(((::ItemList *)(::FUN_00559450((int *)(entry2)))))->m_item));
                    reinterpret_cast<::FUN_0041ab70_shell *>((data))->FUN_0041ab70(true);
                }
            }
            if (actor == (*reinterpret_cast<::ActorObj * *>(&::_g_thePlayer)) && !((::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->IsReady() && !reinterpret_cast<::fnv_008a6970::FUN_008a6970_shell *>((actor))->FUN_008a6970())
                reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(false);
        }
        else if (pending)
        {
            TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(GetAssociated());
            if (armor)
            {
                Changes* changes3 = ((::Changes *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(actor))));
                ItemData* data = ((::ItemData *)(reinterpret_cast<::fnv_004bfda0::FUN_004bfda0_shell *>((changes3))->FUN_004bfda0((::fnv_004bfda0::TESBoundObject *)(armor), true)));
                if (data)
                {
                    pending = false;
                    reinterpret_cast<::FUN_0041ab70_shell *>((data))->FUN_0041ab70(true);
                }
            }
        }
    }
}
// Applies the effect by equipping the weapon or armor form on the caster actor, loading models and updating the equip manager.
// @fnv 0x00808a30
void EffectP::FUN_00808a30()
{
    TESObjectARMO* armor;
    ActorP* weapon = ((::CasterP *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::ActorP *)(reinterpret_cast<::MagicTarget *>((((::CasterP *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    TESObjectWEAP* actor = dynamic_cast<TESObjectWEAP*>(FUN_006733e0());
    armor = dynamic_cast<TESObjectARMO*>(FUN_006733e0());
    if (actor)
    {
        if (((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped())
        {
            ExtraP* old = 0;
            old = *((::ExtraP **)(&reinterpret_cast<::SimpleListNodeView*>(((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped()->list)->m_item));
            if (reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((old))->FUN_0040fe20() < 2 || reinterpret_cast<::fnv_0040fe20::FUN_0040fe20_shell *>((old))->FUN_0040fe20() == 2 && reinterpret_cast<::FUN_00418770_shell *>((old))->FUN_00418770() > 1)
                old = 0;
            TESBoundObject* extra = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped()))->GetName()));
            if (extra && !unka6)
            {
                TESObjectWEAP* oldWeapon = dynamic_cast<TESObjectWEAP*>(extra);
                if (oldWeapon && oldWeapon->model.GetModelLength() > 0)
                {
                    reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((((ModelLoaderP*)(*reinterpret_cast<::BIModelLoader * *>(&::g_modelLoader)))))->FUN_00447080((char *)(oldWeapon->model.GetModelPath()), 0, 1, 0, 0, 0);
                    unka6 = true;
                }
            }
            reinterpret_cast<::s88c790::Actor *>((weapon))->FUN_0088c790((std::intptr_t)(reinterpret_cast<::InventoryStackRecord *>(((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped())->m_pItemObject), 1,
                                 (std::intptr_t)(*((::ExtraP **)(&reinterpret_cast<::SimpleListNodeView*>(((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped()->list)->m_item))), 0, 0, 1);
            unk4c = (EntryS*)new FUN_004bc550(extra, 0);
            if (old)
            {
                FUN_00410360* copied = new FUN_00410360;
                reinterpret_cast<::fnv_00412380::FUN_00412380_shell *>((copied))->FUN_00412380((::ExtraDataList *)(old));
                ((EntryP*)unk4c)->list->FUN_005ae3d0((ExtraP**)&copied);
            }
        }
        weapon->AddItem(actor, 0, 1);
        if (!((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped() || ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped()))->GetName())) != actor)
            reinterpret_cast<::FUN_0088c650_shell *>((weapon))->FUN_0088c650(actor, 1, (::ExtraDataList *)(0), 1, 1, 1);
        ExtraP* newExtra = 0;
        if (((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture())) && ((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped() &&
            ((::ExtraListP *)(::FUN_00559450((int *)(((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped())))))
        {
            newExtra = *((::ExtraP **)(&reinterpret_cast<::SimpleListNodeView*>(((::ExtraListP *)(::FUN_00559450((int *)(((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Equipped())))))->m_item));
            reinterpret_cast<::FUN_0041ab70_shell *>((newExtra))->FUN_0041ab70(1);
        }
        else
            unka8 = true;
        ((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->Update(1);
        ((::ProcessP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((weapon))->GetBaseTexture()))->SetWeapon(actor);
    }
    else if (armor)
    {
        int manager = 0;
        TESNPC* sex = dynamic_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((weapon))->FUN_007af430())));
        if (sex)
            manager = ((SexP*)sex)->FUN_005f0cc0();
        bool worn = unka7;
        for (int slot = 0; slot < 20; slot++)
        {
            EntryP* entry = 0;
            if (reinterpret_cast<::TESBipedModelForm *>(&(((SummonArmorLayout*)armor)->slots))->HasBipedModel((::BIPED_OBJECT)(slot), 0, (::BGSBipedModelList *)(0)))
            {
                InvP* inventory = ((::InvP *)(reinterpret_cast<::ExtraDataList *>((((::InvHolderP *)(reinterpret_cast<::FUN_005d43c0_ *>((weapon))->FUN_005d43c0()))))->GetContainerChangeData()));
                if (inventory)
                    entry = ((::EntryP *)(reinterpret_cast<::Target *>((inventory))->FUN_004c8c10(slot, 0)));
            }
            if (entry)
            {
                if (reinterpret_cast<::InventoryStackRecord *>(entry)->m_pItemObject && !worn)
                {
                    TESBipedModelForm* biped = dynamic_cast<TESBipedModelForm*>(reinterpret_cast<::InventoryStackRecord *>(entry)->m_pItemObject);
                    if (biped)
                    {
                        reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((((ModelLoaderP*)(*reinterpret_cast<::BIModelLoader * *>(&::g_modelLoader)))))->FUN_00447080((char *)(reinterpret_cast<::FUN_004811e0_shell *>((((ArmorModelP*)biped)))->FUN_004811e0(manager)), 0, 1, 0, 0, 0);
                        unka7 = true;
                    }
                }
                ExtraP* data = *((::ExtraP **)(&reinterpret_cast<::SimpleListNodeView*>(entry->list)->m_item));
                if (data)
                {
                    reinterpret_cast<::FUN_0041b010 *>((data))->Method(0);
                    if (reinterpret_cast<::ExtraDataList *>((data))->IsEmpty())
                        reinterpret_cast<::ItemChangeListNode *>((((::ExtraListP *)(::FUN_00559450((int *)(entry))))))->FUN_00905330((*(::InventoryStackRecord *const *)(&data)));
                }
                unk50[slot] = (EntryS*)new FUN_004bc650(entry);
                delete entry;
            }
        }
        ExtraP* npc = new FUN_00410360;
        weapon->AddItem((TESBoundObject*)armor, npc, 1);
        reinterpret_cast<::FUN_0088c650_shell *>((weapon))->FUN_0088c650((TESBoundObject*)armor, 1, (::ExtraDataList *)(0), 1, 0, 1);
        EquipManagerP* preload = ((::EquipManagerP *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(weapon))));
        npc = ((::ExtraP *)(reinterpret_cast<::fnv_004bfda0::FUN_004bfda0_shell *>((preload))->FUN_004bfda0((::fnv_004bfda0::TESBoundObject *)(armor), 1)));
        if (npc)
            reinterpret_cast<::FUN_0041ab70_shell *>((npc))->FUN_0041ab70(1);
        else
            unka8 = true;
    }
    else
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(0);
}

struct ArmoViewQ
{
    char pad[0x70];
    BIArmor::BISlots bipedModel;
};
class EffectSetting;
struct ActiveEffect
{
    virtual ~ActiveEffect();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
public:
    ::EffectSetting *GetEffectSetting() const;
};
// @fnv 0x008091a0
void BIEffect::StopEffect()
{
    BIActor* pkActor = ((::BITarget *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::BIActor *)(reinterpret_cast<::MagicTarget *>((((::BITarget *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (m_bModifierActive && pkActor)
    {
        TESObjectWEAP* pkWeapon = dynamic_cast<TESObjectWEAP*>(FUN_006733e0());
        TESObjectARMO* pkArmorRes = dynamic_cast<TESObjectARMO*>(FUN_006733e0());
        if (pkWeapon)
        {
            BIItemData* pkData = 0;
            BIChanges* pkChanges = ((::BIChanges *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(pkActor))));
            pkData = ((::BIItemData *)(reinterpret_cast<::fnv_004bfda0::FUN_004bfda0_shell *>((pkChanges))->FUN_004bfda0((::fnv_004bfda0::TESBoundObject *)(pkWeapon), 0)));
            if (pkData)
                reinterpret_cast<::FUN_0041b040_shell *>((pkData))->FUN_0041b040();
            reinterpret_cast<::s88c790::Actor *>((pkActor))->FUN_0088c790((intptr_t)(pkWeapon), 1, 0, 0, 0, 1);
            pkActor->UnequipItem(pkWeapon, 0, 1, 0, 0, 0, 0, 0, 1, 0);
            if (m_pkWeaponEntry)
            {
                bool bEquipped = false;
                pkData = ((::BIItemNode *)(::FUN_00559450((int *)(m_pkWeaponEntry)))) ? *((::BIItemData **)(&reinterpret_cast<::SimpleListNodeView*>(((::BIItemNode *)(::FUN_00559450((int *)(m_pkWeaponEntry)))))->m_item)) : 0;
                if (reinterpret_cast<::CombatState *>((pkActor))->GetInventoryItemCount((::TESForm *)(::TESBoundObject *)(reinterpret_cast<::InventoryStackRecord *>(m_pkWeaponEntry)->m_pItemObject)) >= 1)
                {
                    bEquipped = true;
                    reinterpret_cast<::FUN_0088c650_shell *>((pkActor))->FUN_0088c650(reinterpret_cast<::InventoryStackRecord *>(m_pkWeaponEntry)->m_pItemObject, 1, (::ExtraDataList *)(0), 1, 0, 1);
                }
                if (m_bLoadWeaponModel)
                {
                    TESBoundObject* pkBase = reinterpret_cast<::InventoryStackRecord *>(m_pkWeaponEntry)->m_pItemObject;
                    TESObjectWEAP* pkOldWeapon = dynamic_cast<TESObjectWEAP*>(pkBase);
                    if (pkOldWeapon && pkOldWeapon->model.GetModelLength() > 0)
                        reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::BIModelLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(pkOldWeapon->model.GetModelPath()), 0, 1);
                    m_bLoadWeaponModel = false;
                }
                if (pkData)
                    reinterpret_cast<::fnv_0041afa0::FUN_0041afa0_Class *>((pkData))->FUN_0041afa0();
                reinterpret_cast<::FUN_004bc780_shell *>((m_pkWeaponEntry))->ClearExtraDataList();
                delete m_pkWeaponEntry;
                m_pkWeaponEntry = 0;
                ((::BIProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkActor))->GetBaseTexture()))->SetDirty(1);
            }
        }
        else if (pkArmorRes)
        {
            int iSexCur = 0;
            TESNPC* pkNPC = dynamic_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkActor))->FUN_007af430())));
            if (pkNPC)
                iSexCur = pkNPC->GetSex();
            BIItemData* pkArmorData = 0;
            BIChanges* pkArmorChanges = ((::BIChanges *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)(pkActor))));
            pkArmorData = ((::BIItemData *)(reinterpret_cast<::fnv_004bfda0::FUN_004bfda0_shell *>((pkArmorChanges))->FUN_004bfda0((::fnv_004bfda0::TESBoundObject *)(pkArmorRes), 0)));
            if (pkArmorData)
                reinterpret_cast<::FUN_0041b040_shell *>((pkArmorData))->FUN_0041b040();
            reinterpret_cast<::s88c790::Actor *>((pkActor))->FUN_0088c790((intptr_t)(pkArmorRes), 1, 0, 0, 0, 1);
            pkActor->UnequipItem(pkArmorRes, 0, 1, 0, 0, 0, 0, 0, 1, 0);
            for (int i = 0; i < 0x14; i++)
            {
                if (reinterpret_cast<::TESBipedModelForm *>(&(((BIArmor*)pkArmorRes)->m_kSlots))->HasBipedModel((::BIPED_OBJECT)(i), 0, (::BGSBipedModelList *)(0)) && m_apArmorEntries[i])
                {
                    BIEntry* pkEntry = m_apArmorEntries[i];
                    BIItemData* pkEntryData = 0;
                    if (((::BIItemNode *)(::FUN_00559450((int *)(pkEntry)))))
                        pkEntryData = *((::BIItemData **)(&reinterpret_cast<::SimpleListNodeView*>(((::BIItemNode *)(::FUN_00559450((int *)(pkEntry)))))->m_item));
                    if (pkEntry)
                    {
                        bool bKeepModel = false;
                        bool bEquipped = false;
                        if (reinterpret_cast<::CombatState *>((pkActor))->GetInventoryItemCount((::TESForm *)(::TESBoundObject *)(reinterpret_cast<::InventoryStackRecord *>(pkEntry)->m_pItemObject)) >= 1)
                        {
                            reinterpret_cast<::FUN_0088c650_shell *>((pkActor))->FUN_0088c650(reinterpret_cast<::InventoryStackRecord *>(pkEntry)->m_pItemObject, 1, (::ExtraDataList *)(0), 1, 0, 1);
                            BIEntry* pkWorn = ((::BIEntry *)(reinterpret_cast<::Target *>((((::BIWornList *)(reinterpret_cast<::ExtraDataList *>((((::BIWornSlot *)(reinterpret_cast<::FUN_005d43c0_ *>((pkActor))->FUN_005d43c0()))))->GetContainerChangeData()))))->FUN_004c8c10({}, {})));
                            if (!pkWorn || reinterpret_cast<::InventoryStackRecord *>(pkWorn)->m_pItemObject != reinterpret_cast<::InventoryStackRecord *>(pkEntry)->m_pItemObject)
                                bKeepModel = FUN_0080a700(pkActor, pkEntry, this);
                            delete pkWorn;
                            bEquipped = true;
                        }
                        if (m_bLoadArmorModel && reinterpret_cast<::InventoryStackRecord *>(pkEntry)->m_pItemObject && !bKeepModel)
                        {
                            TESBipedModelForm* pkBiped = dynamic_cast<TESBipedModelForm*>(reinterpret_cast<::InventoryStackRecord *>(pkEntry)->m_pItemObject);
                            if (pkBiped)
                                reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::BIModelLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(reinterpret_cast<::FUN_004811e0_shell *>((pkBiped))->FUN_004811e0(iSexCur)), 0, 1);
                        }
                        if (pkEntryData)
                            reinterpret_cast<::fnv_0041afa0::FUN_0041afa0_Class *>((pkEntryData))->FUN_0041afa0();
                        reinterpret_cast<::FUN_004bc780_shell *>((pkEntry))->ClearExtraDataList();
                        delete pkEntry;
                        pkEntry = 0;
                    }
                    m_apArmorEntries[i] = 0;
                }
            }
            m_bLoadArmorModel = false;
        }
        if (pkActor->IsAlive() && ((::BIProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkActor))->GetBaseTexture())) && !(reinterpret_cast<::FUN_0045cd60_shell *>((((::BIProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkActor))->GetBaseTexture()))))->FUN_0045cd60()) &&
            ((::BIEffectItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell)) && ((::BINode *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect)))
        {
            BIModelHolder* pkModelOut = ((::BIEffectItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell))->FUN_0040a300(0);
            void* pvFound = ((void *)(reinterpret_cast<::fnv_004064d0::EffectItemList *>(&(((::BIEffectItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell))->m_kList))->FindCostliestEffectItem(reinterpret_cast<::EffectItemFields *>(reinterpret_cast<::ActiveEffectFields *>(this)->effect)->range, 0)));
            if (((::BINode *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect)) == pvFound)
            {
                if (((::BIModelHolder *)(reinterpret_cast<::ActiveEffect *>(this)->GetEffectSetting()))->m_kModel.GetModelLength() > 0)
                {
                    BIShader* pkShader = 0;
                    pkShader = new BIShader(pkActor, pkModelOut->m_kModel.GetModelPath(), -1.0f);
                    if (pkShader->Init())
                        reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::BIShaderManager *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(pkShader));
                    else
                        delete pkShader;
                    if (m_bShowShader)
                    {
                        reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::BIModelLoader * *>(&::g_modelLoader))))->FUN_00445300((char *)(pkModelOut->m_kModel.GetModelPath()), 0, 1);
                        m_bShowShader = false;
                    }
                }
                pkActor->FUN_00933270("ITMBoundDisappear", 0, 0x40000102, 1);
            }
        }
        reinterpret_cast<::TESRecipe *>(this)->SetRequiredSkill((::ActorValue::Index)(0));
        m_bModifierActive = false;
    }
}
struct BoundSlotItem
{
    BoundSlotItem(BIEntry* apRef);
    int unk00;
    int unk04;
    int unk08;
};
struct BoundItemEffectX : ActiveEffect
{
    BoundSlotItem* slots[20];
    TESForm* FUN_006733e0();
};
struct EffectNode
{
    bool FUN_008256d0();
};
struct MagicTargetX
{
    virtual ~MagicTargetX();
    virtual void Unk01();
    virtual EffectNode* GetEffectList();
};
struct ActorHead
{
    virtual ~ActorHead();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
};
struct ActorX : ActorHead, MagicTargetX
{
};

// Finds a free armor slot shared by apRef and a bound-armor effect on apActor, storing a BoundSlotItem and returning true.
// @fnv 0x0080a700
bool FUN_0080a700(BIActor* apActor, BIEntry* apRef, void* apExclude)
{
    TESBipedModelForm* pBiped5 = apRef ? dynamic_cast<TESBipedModelForm*>(reinterpret_cast<::InventoryStackRecord *>(apRef)->m_pItemObject) : 0;
    if (!apActor || !pBiped5)
    {
        return false;
    }
    EffectNode* pNode2 = static_cast<MagicTargetX*>((ActorX*)apActor)->GetEffectList();
    while (pNode2 && !pNode2->FUN_008256d0())
    {
        ActiveEffect* pEffect = *((::ActiveEffect **)(&reinterpret_cast<::SimpleListNodeView*>(pNode2)->m_item));
        BoundItemEffectX* pBound6 = (BoundItemEffectX*)dynamic_cast<BoundItemEffect*>(pEffect);
        if (pBound6 && (void*)pBound6 != apExclude)
        {
            TESObjectARMO* aPArmor = dynamic_cast<TESObjectARMO*>(pBound6->FUN_006733e0());
            if (aPArmor)
            {
                for (int i4 = 0; i4 < 20; i4++)
                {
                    if (reinterpret_cast<::TESBipedModelForm *>((((BIArmor::BISlots*)pBiped5)))->HasBipedModel((::BIPED_OBJECT)(i4), 0, (::BGSBipedModelList *)(0)) &&
                        reinterpret_cast<::TESBipedModelForm *>(&(((ArmoViewQ*)aPArmor)->bipedModel))->HasBipedModel((::BIPED_OBJECT)(i4), 0, (::BGSBipedModelList *)(0)) && !pBound6->slots[i4])
                    {
                        pBound6->slots[i4] = new BoundSlotItem(apRef);
                        return true;
                    }
                }
            }
        }
        pNode2 = ((::EffectNode *)(reinterpret_cast<::Callees *>((pNode2))->FUN_00726070()));
    }
    return false;
}

class TESBoundObject;
class TESObjectWEAP;
class TESNPC;
class TESBipedModelForm;
struct EntryA
{
    ~EntryA();
};
struct InventoryA
{
};
struct ExtraA
{
};
struct ActorA
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void Equip(TESBoundObject*, int, int);
};
struct TargetA
{
};
struct ModelLoaderA
{
};
struct SexA
{
    int FUN_005f0cc0();
};
struct BoundLoadEffectView : BaseEffectS
{
    EntryA* weapon;
    EntryA* armor[20];
    int a0;
    bool a4;
    bool a5;
    bool a6;
    bool a7;
    TESForm* FUN_006733e0();
    void FUN_0080a2d0(intptr_t);
};
// Loads weapon and armor models when a4 is set, copies their entries below version 0x61, and conditionally equips the bound object.
// @fnv 0x0080a2d0
void BoundLoadEffectView::FUN_0080a2d0(intptr_t arg)
{
    int actor;
    reinterpret_cast<::fnv_00806e70::AssociatedItemEffect *>(this)->FUN_00806e70((::fnv_00806e70::Actor *)(arg));
    ActorA* j = ((::TargetA *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::ActorA *)(reinterpret_cast<::MagicTarget *>((((::TargetA *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (a4)
    {
        if (weapon)
        {
            TESBoundObject* object = reinterpret_cast<::InventoryStackRecord *>(weapon)->m_pItemObject;
            TESObjectWEAP* pWeapon = dynamic_cast<TESObjectWEAP*>(object);
            if (pWeapon && pWeapon->model.GetModelLength() > 0)
            {
                a6 = true;
                reinterpret_cast<::QueueHelper *>((((ModelLoaderA*)(*reinterpret_cast<::BIModelLoader * *>(&::g_modelLoader)))))->FUN_00444040((intptr_t)(pWeapon->model.GetModelPath()), 0, 0, 0, 1, 0, 0);
            }
        }
        int sex = 0;
        if (j)
        {
            TESNPC* npc = dynamic_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((j))->FUN_007af430())));
            if (npc)
                sex = ((SexA*)npc)->FUN_005f0cc0();
        }
        for (int i = 0; i < 20; i++)
        {
            if (armor[i] && reinterpret_cast<::InventoryStackRecord *>(armor[i])->m_pItemObject)
            {
                TESBipedModelForm* biped = dynamic_cast<TESBipedModelForm*>(reinterpret_cast<::InventoryStackRecord *>(armor[i])->m_pItemObject);
                if (biped)
                {
                    a7 = true;
                    reinterpret_cast<::QueueHelper *>((((ModelLoaderA*)(*reinterpret_cast<::BIModelLoader * *>(&::g_modelLoader)))))->FUN_00444040((intptr_t)(reinterpret_cast<::FUN_004811e0_shell *>((biped))->FUN_004811e0(sex)), 0, 0, 0, 1, 1, 0);
                }
            }
        }
    }
    if (weapon)
    {
        reinterpret_cast<::FUN_004bed00_host *>((weapon))->FUN_004bed00();
        if (reinterpret_cast<::FUN_008df040_shell *>((::g_TESSaveLoadGame))->FUN_008df040() < 0x61)
        {
            EntryA* pWeaponCopy = (EntryA*)new FUN_004bc650((EntryP*)weapon);
            delete weapon;
            weapon = pWeaponCopy;
        }
        reinterpret_cast<::s88c790::Actor *>((j))->FUN_0088c790((std::intptr_t)(reinterpret_cast<::InventoryStackRecord *>(weapon)->m_pItemObject), 1, 0, 0, 0, 1);
    }
    for (actor = 0; actor < 20; actor++)
    {
        if (armor[actor])
        {
            reinterpret_cast<::FUN_004bed00_host *>((armor[actor]))->FUN_004bed00();
            if (reinterpret_cast<::FUN_008df040_shell *>((::g_TESSaveLoadGame))->FUN_008df040() < 0x61)
            {
                EntryA* pArmorCopy = (EntryA*)new FUN_004bc650((EntryP*)armor[actor]);
                delete armor[actor];
                armor[actor] = pArmorCopy;
            }
            reinterpret_cast<::s88c790::Actor *>((j))->FUN_0088c790((std::intptr_t)(reinterpret_cast<::InventoryStackRecord *>(armor[actor])->m_pItemObject), 1, 0, 0, 0, 1);
        }
    }
    if (a4)
    {
        InventoryA* item = ((::InventoryA *)(reinterpret_cast<::ExtraDataList *>((((::ExtraA *)(reinterpret_cast<::FUN_005d43c0_ *>((j))->FUN_005d43c0()))))->GetContainerChangeData()));
        TESBoundObject* pBoundForm = dynamic_cast<TESBoundObject*>(FUN_006733e0());
        if (item && !reinterpret_cast<::FUN_004c8f30_shell *>((item))->FUN_004c8f30((intptr_t)(pBoundForm)))
        {
            j->Equip(pBoundForm, 0, 1);
            reinterpret_cast<::FUN_0088c650_shell *>((j))->FUN_0088c650(pBoundForm, 1, (::ExtraDataList *)(0), 1, 0, 1);
        }
    }
}

#include "generated/data/fallout/magic/bounditemeffect.inc"
