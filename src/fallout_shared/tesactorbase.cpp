// fallout_shared/tesactorbase.cpp: TESActorBase, Reset3DMobIterator, ActorBaseTarget, ActorBaseSaveView and more (23 functions)

#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatDamageCalculator.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0047e340_shell.h"
#include "fnv/decl/FUN_0047e4a0_cls.h"
#include "fnv/decl/FUN_0047f7e0_shell.h"
#include "fnv/decl/FUN_0047f8c0_shell.h"
#include "fnv/decl/FUN_004801e0_shell.h"
#include "fnv/decl/FUN_00480240_shell.h"
#include "fnv/decl/FUN_00480270_shell.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e70_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_0096bbc0_cls.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormListPair.h"
#include "fnv/decl/LoadedSpells.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/S0048d8f0_SpellListSaveSizer.h"
#include "fnv/decl/SavePayload.h"
#include "fnv/decl/TESActorBaseData47E.h"
#include "fnv/decl/TESHealthForm.h"
#include "fnv/decl/TESSpellList.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0047e380__TESActorBaseData_0047e380.h"
#include "fnv/decl/fnv_0047e6f0__TESActorBaseData_Shell.h"
#include "fnv/decl/fnv_0047f840__FUN_0047f840_shell.h"
#include "fnv/decl/fnv_0047f940__BGSChangeHandler.h"
#include "fnv/decl/fnv_0047f980__FUN_0047f980_Class.h"
#include "fnv/decl/fnv_00480210__FUN_00480210_This.h"
#include "fnv/decl/fnv_004802b0__FUN_004802b0_Class.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_0048da20__TESSpellList_Target.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004be000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005d8000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "tesactorbase_decls.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/s428110__Owner.h"

// @fnv 0x0048cee0
SEX TESActorBase::GetSex()
{
    return reinterpret_cast<MissileProjectile*>(reinterpret_cast<char*>(this) + 4)->GetCharacterSex();
}

// Returns true if the form is an actor base (type 42) whose actor base data has flag 0x10 set; otherwise false.
// @fnv 0x005f0d00
bool TESActorBase::SetPlayable()
{
    if (reinterpret_cast<TESForm*>(this)->GetFormType() == 42)
        return reinterpret_cast<TESActorBaseData*>(reinterpret_cast<char*>(this) + 0x30)->GetFlag(0x10);
    return false;
}

// @fnv 0x005f1630
void TESActorBase::NotifyFormIDChanged(int changeFlags)
{
    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(this)))->FUN_0084e3a0()))))
    {
        if (::g_BGSSaveLoadGame->ShouldSaveForm(reinterpret_cast<TESForm*>(this), false))
            reinterpret_cast<::FUN_0047e340_shell *>((reinterpret_cast<TESActorBaseData*>(reinterpret_cast<char*>(this) + 0x30)))->FUN_0047e340(changeFlags);
    }
    else
        reinterpret_cast<TESForm*>(this)->MarkAsModified(changeFlags);
}

// Loads the actor base from the buffer: base form, actor data, crime, attributes, AI form, and optionally the full name when change flag 0x20 is set.
// @fnv 0x005f1fd0
void TESActorBase::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<TESForm*>(this)->LoadGame(buffer);
    reinterpret_cast<::TESActorBaseData47E *>((reinterpret_cast<TESActorBaseData*>(reinterpret_cast<char*>(this) + 0x30)))->FUN_0047ea70((::BGSLoadFormBuffer47E *)(buffer));
    reinterpret_cast<::TESSpellList *>((reinterpret_cast<Crime*>(reinterpret_cast<char*>(this) + 0x7c)))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::fnv_004802b0::FUN_004802b0_Class *>((reinterpret_cast<TESAttributes*>(reinterpret_cast<char*>(this) + 0xb8)))->LoadDataIfChanged((::fnv_004802b0::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::fnv_0047f980::FUN_0047f980_Class *>((reinterpret_cast<TESAIForm*>(reinterpret_cast<char*>(this) + 0x90)))->FUN_0047f980((::fnv_0047f980::BGSLoadFormBuffer *)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x20)))->FUN_004280f0())
    {
        char name[264];
        reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((buffer))->FUN_008649a0(name);
        reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(this) + 0xd0)->SetFullName(name);
    }
}

// @fnv 0x005f2150
Reset3DMobIterator::Reset3DMobIterator()
{
    ::FUN_005d8b10((int *)this);
    vtable = (void*)&DAT_01047670;
}

// If reset is set, runs the 3D mob iterator over this actor base twice and resets the player's process 3D when this is the player's base.
// @fnv 0x005f20a0
void TESActorBase::FUN_005f20a0(bool reset)
{
    if (!reset)
        return;
    Reset3DMobIterator mobIter;
    mobIter.base = this;
    mobIter.reset = reset;
    reinterpret_cast<::CombatProcedure *>(&(mobIter))->Initialize((::CombatController *)(0));
    reinterpret_cast<::FUN_0096bbc0_cls *>(&((*reinterpret_cast<::ProcessLists *>(&::g_011e0e80))))->ProcessMobileObjects((::FUN_0096bbc0_list *)(::Reset3DMobIterator *)(&mobIter));
    reinterpret_cast<::CombatProcedure *>(&(mobIter))->Initialize((::CombatController *)(1));
    reinterpret_cast<::FUN_0096bbc0_cls *>(&((*reinterpret_cast<::ProcessLists *>(&::g_011e0e80))))->ProcessMobileObjects((::FUN_0096bbc0_list *)(::Reset3DMobIterator *)(&mobIter));
    if (::_g_thePlayer->GetActorBase() == this)
    {
        if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((::_g_thePlayer))->GetBaseTexture())))
            ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((::_g_thePlayer))->GetBaseTexture()))->Reset3D(reset);
    }
}

// If the actor's object reference equals base and it has a process, resets that process's 3D state with reset.
// @fnv 0x005f2170
void Reset3DMobIterator::operator()(Actor* actor)
{
    if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((actor))->FUN_007af430())) == base && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())))
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->Reset3D(reset);
}

// @fnv 0x005f1590
bool TESActorBase::ShouldUseDefaultAppearance(TESObjectREFR* ref)
{
    bool result = true;
    if (reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((::g_BGSSaveLoadGame))->FUN_0042ce10())
    {
        if (reinterpret_cast<::FUN_00576d30_shell *>((static_cast<Actor*>(ref)))->FUN_00576d30() &&
            ::g_BGSSaveLoadGame->HasFormChangeFlags(reinterpret_cast<TESForm*>(ref), (*(::FormChangeMask *)&(const ::GlobalObject_008c71b0 &)(GlobalObject_008c71b0(0x08000020)))))
            result = false;
    }
    else
    {
        if (ref->IsDead(false) &&
            ::g_BGSSaveLoadGame->HasFormChangeFlags(reinterpret_cast<TESForm*>(ref), (*(::FormChangeMask *)&(const ::GlobalObject_008c71b0 &)(GlobalObject_008c71b0(0x400)))))
            result = false;
    }
    return result;
}

struct FUN_005f0b00_shell : public TESActorBase
{
    int FUN_005f0b00();
};

struct VTableHolder_005f0b00
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual int vfn_4();
};

// @fnv 0x005f0b00
int FUN_005f0b00_shell::FUN_005f0b00()
{
    return ((VTableHolder_005f0b00*)((char*)this + 0xb0))->vfn_4();
}

struct FUN_005f0b50_shell : public TESActorBase
{
    bool FUN_005f0b50();
};

// @fnv 0x005f0b50
bool FUN_005f0b50_shell::FUN_005f0b50()
{
    if (GetFormType() == 0x2b)
    {
        if (reinterpret_cast<TESActorBaseData*>((char*)this + 0x30)->GetFlag(0x10) ||
            reinterpret_cast<TESActorBaseData*>((char*)this + 0x30)->GetFlag(1))
            return true;
        else
            return false;
    }
    return true;
}

struct FUN_005f0c80_shell : public TESActorBase
{
    bool FUN_005f0c80();
};

// @fnv 0x005f0c80
bool FUN_005f0c80_shell::FUN_005f0c80()
{
    if (GetFormType() == 0x2b)
    {
        if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x800000))
            return true;
        else
            return false;
    }
    return false;
}

struct BGSBodyPartData
{
    static BGSBodyPartData* ms_pBodyPartDataInstance;
    static BGSBodyPartData* ms_pBodyPartData;
};

// @fnv 0x005f0f80
BGSBodyPartData* FUN_005f0f80(TESActorBase* apActorBase)
{
    if (BGSBodyPartData::ms_pBodyPartDataInstance && apActorBase == ::_g_thePlayer->GetActorBase())
        return BGSBodyPartData::ms_pBodyPartDataInstance;
    return BGSBodyPartData::ms_pBodyPartData;
}

struct FUN_005f0b30_shell
{
    void FUN_005f0b30(int a1);
};

// @fnv 0x005f0b30
void FUN_005f0b30_shell::FUN_005f0b30(int aiValue)
{
    reinterpret_cast<::CombatProcedure *>((((Reset3DMobIterator*)((char*)this + 0xb0))))->Initialize((::CombatController *)(aiValue));
}


struct FUN_005f0ba0_shell : TESActorBase
{
    bool FUN_005f0ba0();
};

// @fnv 0x005f0ba0
bool FUN_005f0ba0_shell::FUN_005f0ba0()
{
    if (!reinterpret_cast<::FUN_005f0b50_shell *>((this))->FUN_005f0b50())
        return false;
    if (GetFormType() == 0x2b)
    {
        if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x40000))
            return false;
    }
    return true;
}

struct ArrSI
{
};

struct FUN_005f0f50_shell : ArrSI
{
    char HasFlag80000();
};

// @fnv 0x005f0f50
char FUN_005f0f50_shell::HasFlag80000()
{
    unsigned int flags = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
    return (flags & 0x80000) != 0;
}

struct Dummy : TESBoundObject
{
    bool FUN_005f0c40();
};
// Returns true if this form is an actor base (type 0x2B) whose actor base data has flag 0x20 set; otherwise false.
// @fnv 0x005f0c40
bool Dummy::FUN_005f0c40()
{
    if (GetFormType() == 0x2B)
    {
        if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x20))
            return true;
        else
            return false;
    }
    return false;
}

struct FUN_0047e360_Cls
{
    void ClearFlags(unsigned int);
};
struct BGSSaveLoadGame_Hack
{
};
struct TESForm_Hack
{
};
struct FUN_005f1690_Cls : TESForm
{
    void FUN_005f1690(int);
};
// @fnv 0x005f1690
void FUN_005f1690_Cls::FUN_005f1690(int aiChangeFlags)
{
    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))) && reinterpret_cast<::BGSSaveLoadGame *>((((BGSSaveLoadGame_Hack*)::g_BGSSaveLoadGame)))->IsFormChanged(this))
        ((FUN_0047e360_Cls*)((char*)this + 0x30))->ClearFlags(aiChangeFlags);
    else
        reinterpret_cast<::TESForm *>((((TESForm_Hack*)this)))->MarkAsUnmodified(aiChangeFlags);
}

struct FNStub
{
};
struct BGSSaveGameBuffer
{
};
struct FUN_00484d60_holder
{
};
struct FUN_0047ea30_holder
{
};
struct FUN_0048e040_holder
{
};
struct FUN_00480270_holder
{
};
struct FUN_0047f940_holder
{
};
struct FUN_005f1f30_shell : public BGSLoadFormBuffer
{
    void FUN_005f1f30(unsigned int);
};
// @fnv 0x005f1f30
void FUN_005f1f30_shell::FUN_005f1f30(unsigned int buffer)
{
    reinterpret_cast<::FakeForm *>((((FUN_00484d60_holder*)this)))->SaveIfChanged((::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::SavePayload *>((((FUN_0047ea30_holder*)((char*)this + 0x30))))->FUN_0047ea30((::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::FormListPair *>((((FUN_0048e040_holder*)((char*)this + 0x7c))))->FUN_0048e040((::SaveFormBuf0048 *)(buffer));
    reinterpret_cast<::FUN_00480270_shell *>((((FUN_00480270_holder*)((char*)this + 0xb8))))->FUN_00480270((::PacketSerializer *)(buffer));
    reinterpret_cast<::fnv_0047f940::BGSChangeHandler *>((((FUN_0047f940_holder*)((char*)this + 0x90))))->SaveChangeData((::fnv_0047f940::BGSSaveFormBuffer *)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(((BGSLoadFormBuffer*)buffer)->GetChangeFlags(0x20)))->FUN_004280f0())
    {
        const char* pfullname = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)this + 0xd0))))->FUN_00408da0()));
        reinterpret_cast<::FUN_00865e70_shell *>((((BGSSaveGameBuffer*)buffer)))->FUN_00865e70(pfullname, 0);
    }
}

struct S005f0bf0
{
    char _pad[0x30];
    TESActorBaseData abd;
    bool FUN_005f0bf0();
};
// Returns true unless the form type is 0x2B and neither the 0x40 nor the 1 flag is set in abd.
// @fnv 0x005f0bf0
bool S005f0bf0::FUN_005f0bf0()
{
    if (((TESForm*)this)->GetFormType() == 0x2B)
    {
        if (abd.GetFlag(0x40) || abd.GetFlag(1))
            return true;
        else
            return false;
    }
    return true;
}

extern int DAT_01186fcc;
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct FormTarget
{
    unsigned int FUN_00401170();
};
struct ComponentTarget
{
};
struct ItemTarget
{
};
float __cdecl ConvertUIntToFloat(unsigned int);
struct ActorBaseTarget : TESActorBase
{
    float FUN_005f0d60(FormTarget* form);
};
// Looks up a form by type and returns a value derived from the matching item, component or constant, defaulting to 0.0f.
// @fnv 0x005f0d60
float ActorBaseTarget::FUN_005f0d60(FormTarget* form)
{
    float result = 0.0f;
    if (form)
    {
        switch (form->FUN_00401170())
        {
        case 41: {
            void* item = FUN_00ec43fb(form, 0, &DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_011840c4)), 0);
            if (item)
                result = 1.0f;
            break;
        }
        case 40: {
            void* item = FUN_00ec43fb(form, 0, &DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_01183998)), 0);
            if (item && ((int)(::TESHealthForm::GetBaseHealth((::TESForm *)(item)))))
            {
                float condition = 1.0f;
                enum
                {
                    actorComponentOffset = 0x100
                };
                result = ::FUN_00644ce0((::ActorValueOwner *)(void *)(this ? reinterpret_cast<char*>(this) + actorComponentOffset : 0), (::DmgWeapon *)(item), condition,
                                      1.0f, 0, 0, (::InventoryStackRecord *)(0), 0);
            }
            break;
        }
        case 26: {
            void* item = FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01186fcc, 0);
            if (item)
            {
                enum
                {
                    itemComponentOffset = 0x58
                };
                result = ConvertUIntToFloat(
                    ((unsigned int)(reinterpret_cast<::Callees *>((reinterpret_cast<ComponentTarget*>(reinterpret_cast<char*>(item) + itemComponentOffset)))->FUN_00726070())));
            }
            break;
        }
        case 24: {
            ItemTarget* item = static_cast<ItemTarget*>(FUN_00ec43fb(form, 0, &DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_01183a34)), 0));
            if (item && ((int)(::TESHealthForm::GetBaseHealth((::TESForm *)(item)))))
            {
                float condition = 1.0f;
                result =
                    ((double)(::CombatDamageCalculator::CalculateArmorDamageThreshold(static_cast<unsigned short>(((float)(::FUN_004be060((void *)(item))))), condition))) + ::FUN_004be180((char *)(item));
            }
            break;
        }
        case 30:
            result = DAT_01016410;
            break;
        }
    }
    return result;
}

struct FormIDEntry
{
    unsigned int formID;
    unsigned char type;
    unsigned char flags;
};

struct TESSaveLoadGame
{
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct SaveSizeNamedForm
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetEditorID();
};


struct SaveSizeFormPart
{
    int unk00;
};
struct SaveSizeActorBaseData
{
    int unk00;
};
struct SaveSizeContainer
{
    int unk00;
};
struct SaveSizeAIForm
{
    int unk00;
};
struct SaveSizeAttributes
{
    int unk00;
};

struct ActorBaseSaveView
{
    SaveSizeFormPart form;
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
    SaveSizeActorBaseData actorData;
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
    SaveSizeContainer container;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    SaveSizeAIForm aiForm;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    SaveSizeAttributes attributes;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    FNStub fullName;

    unsigned short FUN_005f16f0(unsigned int changeFlags);
};

// Accumulates the save size of the actor base's parts and optionally logs the total with the current form's ID and editor ID.
// @fnv 0x005f16f0
unsigned short ActorBaseSaveView::FUN_005f16f0(unsigned int changeFlags)
{
    unsigned short totalSize = 0;
    unsigned short startSize = totalSize;
    if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
    {
        totalSize += 4;
        totalSize += 2;
    }
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x6d)
    {
        totalSize += reinterpret_cast<::FUN_00484bf0_shell *>(&(form))->FUN_00484bf0(changeFlags);
    }
    totalSize += reinterpret_cast<::FUN_004801e0_shell *>(&(attributes))->FUN_004801e0(changeFlags);
    totalSize += reinterpret_cast<::fnv_0047e380::TESActorBaseData_0047e380 *>(&(actorData))->FUN_0047e380(changeFlags);
    totalSize += reinterpret_cast<::S0048d8f0_SpellListSaveSizer *>(&(container))->FUN_0048d8f0(changeFlags);
    totalSize += reinterpret_cast<::FUN_0047f7e0_shell *>(&(aiForm))->FUN_0047f7e0(changeFlags);
    if (changeFlags & 0)
    {
        totalSize += 4;
    }
    if (changeFlags & 0x20)
    {
        totalSize += 1;
        totalSize += ::FUN_0044a670(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(fullName))->FUN_00408da0())));
    }
    if (*::g_011de4e8.Bool())
    {
        FormIDEntry* pFormHeader = ((::FormIDEntry *)(reinterpret_cast<::EffectSetting *>((g_TESSaveLoadGame))->GetHitSound()));
        if (pFormHeader)
        {
            SaveSizeNamedForm* namedForm = ((::SaveSizeNamedForm *)(::FUN_004839c0(pFormHeader->formID)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return totalSize;
}

namespace fnv_005f18c0 {
struct SaveRecord
{
    unsigned int formID;
    unsigned char type;
    unsigned char flagsLow;
    unsigned char flagsByte1;
    unsigned char flagsByte2;
    unsigned char flagsByte3;
};
struct TESSaveLoadGame
{
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct SaveAttributes
{
};
struct SaveActorData
{
};
struct SaveInventory
{
};
struct SaveAI
{
};
struct SaveList
{
};
struct SaveActorBase
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
    SaveActorData actorData;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    SaveInventory inventory;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    SaveAI ai;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    SaveList list;
    unsigned int unkb4;
    SaveAttributes attributes;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    FNStub fullName;
    void FUN_005f18c0(unsigned int flags);
};
struct SaveForm
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* Describe();
};

// @fnv 0x005f18c0
void SaveActorBase::FUN_005f18c0(unsigned int flags)
{
    unsigned short size = 0;
    unsigned short* pos2 = 0;
    unsigned int offset2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
    if (*(*reinterpret_cast<::fnv_005f18c0::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool())
        offset2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int tag = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&tag, 4);
        pos2 = (unsigned short*)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&size, 2);
    }
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 109)
        reinterpret_cast<::PC7d *>(this)->FUN_00484c20(flags);
    reinterpret_cast<::fnv_00480210::FUN_00480210_This *>(&(attributes))->FUN_00480210(flags);
    reinterpret_cast<::FUN_0047e4a0_cls *>(&(actorData))->SaveFactionData(flags);
    reinterpret_cast<::fnv_0048da20::TESSpellList_Target *>(&(inventory))->SaveSpellList(flags);
    reinterpret_cast<::fnv_0047f840::FUN_0047f840_shell *>(&(ai))->FUN_0047f840(flags);
    if (flags & 0)
    {
        unsigned int first = ((unsigned int)(reinterpret_cast<::Callees *>(&(list))->FUN_00726070()));
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0((void *)(&first), 4);
    }
    if (flags & 0x20)
    {
        const char* data = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(fullName))->FUN_00408da0()));
        unsigned char pos = (unsigned char)::FUN_0044a670(data);
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0((void *)(&pos), 1);
        if (pos)
            reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0((void *)(data), pos);
    }
    if (*(*reinterpret_cast<::fnv_005f18c0::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool())
    {
        unsigned int end = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        SaveRecord* record = ((::fnv_005f18c0::SaveRecord *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (record)
        {
            SaveForm* form = ((::fnv_005f18c0::SaveForm *)(::FUN_004839c0(record->formID)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int current = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_005f18c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        unsigned int block = (unsigned int)pos2;
        if (current > block + 0xffff)
            ::FUN_005b5e40();
        *pos2 = (unsigned short)(current - block);
    }
}
}  // namespace fnv_005f18c0

namespace fnv_005f1b30 {

struct LoadHdr
{
    int id;
    char b04;
    char b05;
    char b06;
    char b07;
    char b08;
    unsigned char ver;
};

struct FormName
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual const char* GetName();
};


struct TESSaveLoadGame
{
};

struct Sub30
{
    int data;
};
struct Sub7C
{
    int data;
};
struct Sub90
{
    int data;
};
struct SubB0
{
    int data;
};
struct SubB8
{
    int data;
};
struct SubD0
{
    int data;
};

struct ActorBaseLoad
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    Sub30 sub30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    Sub7C sub7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    Sub90 sub90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    SubB0 subB0;
    int fieldB4;
    SubB8 subB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    int fieldCC;
    SubD0 subD0;

    void FUN_005f1b30(unsigned int, unsigned int);
};

// Reads the actor base block from the save stream, dispatches to sub-structs, and verifies the block boundary against the expected end position.
// @fnv 0x005f1b30
void ActorBaseLoad::FUN_005f1b30(unsigned int aiFlags, unsigned int a2)
{
    FormName* form5;
    LoadHdr* hdrB;
    int hdrWord;
    unsigned int curPosC;
    unsigned short usVarZ;
    usVarZ = 0;
    curPosC = 0;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_005f1b30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_005f1b30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&hdrWord, 4);
        if (hdrWord != 0x424c4f4b)
        {
            hdrB = ((::fnv_005f1b30::LoadHdr *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_005f1b30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))));
            if (hdrB != 0)
            {
                form5 = ((::fnv_005f1b30::FormName *)(::FUN_004839c0(hdrB->id)));
                ::FUN_005b5e40(
                    );
            }
            else
            {
                ::FUN_005b5e40(
                    );
            }
        }
        curPosC = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_005f1b30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_005f1b30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&usVarZ, 2);
    }
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_005f1b30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x6d)
        reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>(this)->FUN_00484c50(aiFlags, a2);
    reinterpret_cast<::FUN_00480240_shell *>(&(subB8))->FUN_00480240(aiFlags, a2);
    reinterpret_cast<::fnv_0047e6f0::TESActorBaseData_Shell *>(&(sub30))->FUN_0047e6f0(aiFlags, (void *)(a2));
    reinterpret_cast<::LoadedSpells *>(&(sub7C))->LoadSpellList(aiFlags, a2);
    reinterpret_cast<::FUN_0047f8c0_shell *>(&(sub90))->FUN_0047f8c0(aiFlags, a2);
    if (aiFlags & 0)
    {
        void* scriptVal;
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&scriptVal, 4);
        reinterpret_cast<::CombatProcedure *>(&(subB0))->Initialize((::CombatController *)(scriptVal));
    }
    if (aiFlags & 0x20)
    {
        unsigned char flagByte;
        char nameBuf[0x104];
        ::FUN_00403d30(nameBuf, 0, 0x104);
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&flagByte, 1);
        if (flagByte != 0)
            reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(nameBuf, flagByte);
        reinterpret_cast<::TESFullName *>(&(subD0))->SetFullName(nameBuf);
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_005f1b30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        FormName* form25;
        unsigned int endPos0;
        LoadHdr* hdr2A;
        endPos0 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_005f1b30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        hdr2A = ((::fnv_005f1b30::LoadHdr *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::fnv_005f1b30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))));
        if (hdr2A != 0)
        {
            form25 = ((::fnv_005f1b30::FormName *)(::FUN_004839c0(hdr2A->id)));
            if (endPos0 > usVarZ + curPosC)
            {
                ::FUN_005b5e40(
                    );
            }
            else if (endPos0 < usVarZ + curPosC)
            {
                ::FUN_005b5e40(
                    );
            }
        }
        else
        {
            if (endPos0 > usVarZ + curPosC)
            {
                ::FUN_005b5e40(
                    );
            }
            else if (endPos0 < usVarZ + curPosC)
            {
                ::FUN_005b5e40(
                    );
            }
        }
    }
}
}  // namespace fnv_005f1b30

// 005fbfa0 = VC9 adjustor thunk. Recipe (b90180 class of matches): MI dual-slot override,
// the virtual METHOD named after the claim token FUN_005fbfa0, declared only (never defined)
// so the emitted [thunk] COMDAT is the unique defined symbol carrying the token, and
// fnvcheck binds its jmp target from the original bytes.

struct ThunkPrim
{
    virtual void* FUN_005fbfa0(unsigned int);
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
    int p24;
    int p28;
    int p2c;
    int p30;
    int p34;
    int p38;
    int p3c;
    int p40;
    int p44;
    int p48;
    int p4c;
    int p50;
    int p54;
    int p58;
    int p5c;
    int p60;
    int p64;
    int p68;
    int p6c;
    int p70;
    int p74;
    int p78;
    int p7c;
    int p80;
    int p84;
    int p88;
    int p8c;
    int p90;
    int p94;
    int p98;
    int p9c;
    int pa0;
    int pa4;
    int pa8;
    int pac;
    int pb0;
    int pb4;
    int pb8;
    int pbc;
    int pc0;
    int pc4;
    int pc8;
    int pcc;
    int pd0;
    int pd4;
    int pd8;
};

struct ThunkSec
{
    virtual void* FUN_005fbfa0(unsigned int);
};

struct ThunkHost : ThunkPrim, ThunkSec
{
// @fnv 0x005fbfa0
    virtual void* FUN_005fbfa0(unsigned int);
};

static ThunkHost g_thunk;

#include "generated/data/fallout_shared/tesactorbase.inc"
