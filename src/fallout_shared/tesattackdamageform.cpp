// fallout_shared/tesattackdamageform.cpp: TESAttackDamageForm, TESCreature (6 functions)

#include "fnv/decl/BGSDehydrationStage.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00461560_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0047bdd0_shell.h"
#include "fnv/decl/FUN_0047ccc0_shell.h"
#include "fnv/decl/FUN_0047cd40_shell.h"
#include "fnv/decl/FUN_0047cd90_shell.h"
#include "fnv/decl/FUN_0047cdd0_shell.h"
#include "fnv/decl/FUN_0047d370_shell.h"
#include "fnv/decl/FUN_0047d390_shell.h"
#include "fnv/decl/FUN_0047d3b0_shell.h"
#include "fnv/decl/FUN_0047dd30_shell.h"
#include "fnv/decl/FUN_0047fb50_shell.h"
#include "fnv/decl/FUN_00480000_shell.h"
#include "fnv/decl/FUN_004870f0_shell.h"
#include "fnv/decl/FUN_00487240_shell.h"
#include "fnv/decl/FUN_00507780.h"
#include "fnv/decl/FUN_0050eaa0_shell.h"
#include "fnv/decl/FUN_0057ee10.h"
#include "fnv/decl/FUN_005f0640_shell.h"
#include "fnv/decl/FUN_005f8bb0_shell.h"
#include "fnv/decl/FUN_005f8bd0_Helper.h"
#include "fnv/decl/FUN_005f9100_shell.h"
#include "fnv/decl/FUN_005f91d0_shell.h"
#include "fnv/decl/FUN_005f9ad0_shell.h"
#include "fnv/decl/FUN_005f9af0_shell.h"
#include "fnv/decl/FUN_005f9b10_class.h"
#include "fnv/decl/FUN_005f9b30_shell.h"
#include "fnv/decl/FUN_005fa2c0_shell.h"
#include "fnv/decl/FUN_005fbdb0_shell.h"
#include "fnv/decl/FUN_00803a90_shell.h"
#include "fnv/decl/FUN_008126e0_shell.h"
#include "fnv/decl/FUN_00821640_shell.h"
#include "fnv/decl/FUN_00821660_shell.h"
#include "fnv/decl/ModelCopyView.h"
#include "fnv/decl/TABStub.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047ca20__FUN_0047ca20_shell.h"
#include "fnv/decl/fnv_0047de40__TABStub.h"
#include "fnv/decl/fnv_0047de70__TABStub.h"
#include "fnv/decl/fnv_0047dfe0__TABStub.h"
#include "fnv/decl/fnv_0047e010__TABStub.h"
#include "fnv/decl/fnv_0047e1c0__S47b.h"
#include "fnv/decl/fnv_0047e270__FUN_0047e270_shell.h"
#include "fnv/decl/fnv_00489db0__FUN_00489db0_shell.h"
#include "fnv/decl/fnv_0048cce0__FUN_0048cce0_shell.h"
#include "fnv/decl/fnv_0048d630__SpellListAccess.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00505000.h"
#include "fnv/symbols_00567000.h"
#include "fnv/symbols_005f8000.h"
#include "fnv/symbols_005f9000.h"
#include "fnv/symbols_008f2000.h"
#include "tesattackdamageform_creature_decls.h"

// @fnv 0x0047fdf0
TESAttackDamageForm::~TESAttackDamageForm()
{
    Free();
}

// @fnv 0x0047ff30
unsigned short TESAttackDamageForm::GetAttackDamage()
{
    return m_usAttackDamage;
}

// The covered address is a secondary-base override on TESCreature. The old
// Several tiny accessors were folded with unrelated canonical methods. Their
// actorData so the calls retain the original non-null subobject adjustment.
// Copies template data from selectedForm or the current template into this creature according to the template use flags, then marks the template as copied.
// @fnv 0x005fb450
void TESCreature::CopyFromTemplateForm(TESActorBase* selectedForm)
{
    if (!reinterpret_cast<ActorMover*>(reinterpret_cast<char*>(&actorData) - offsetof(TESActorBaseData, actorData))
             ->GetCurrentMoveModeType() &&
        !selectedForm)
        return;

    struct TemplateSelection
    {
        unsigned short useFlags;
        TESForm* leveled;
        TESCreature* creature;
    } templateSelection;
    {
        TESCreature defaultCreature;
        reinterpret_cast<::FUN_008126e0_shell *>(&(defaultCreature))->SetWhich((int)(((::TESCombatStyle *)(::FUN_00505000()))));
        templateSelection.creature = 0;
        if (!reinterpret_cast<::FUN_0047cdd0_shell *>(this)->FUN_0047cdd0())
            templateSelection.creature =
                (TESCreature*)reinterpret_cast<ActorMover*>(reinterpret_cast<char*>(&actorData) -
                                                            offsetof(TESActorBaseData, actorData))
                    ->GetCurrentMoveModeType();
        if (selectedForm && selectedForm->GetFormType() == ENUM_FORM_ID_CREA_ID)
            templateSelection.creature = (TESCreature*)selectedForm;
        if (!templateSelection.creature)
            templateSelection.creature = &defaultCreature;
        else if (reinterpret_cast<ActorMover*>(reinterpret_cast<char*>(&templateSelection.creature->actorData) -
                                               offsetof(TESActorBaseData, actorData))
                     ->GetCurrentMoveModeType() &&
                 !reinterpret_cast<::TABStub *>((templateSelection.creature))->FUN_0047cca0())
            templateSelection.creature->CopyFromTemplateForm(0);

        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_SCRIPT))))
            reinterpret_cast<::fnv_0048cce0::FUN_0048cce0_shell *>(this)->CopyFromScriptableForm((TESScriptableForm*)templateSelection.creature);
        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_INVENTORY))))
            reinterpret_cast<::TESContainer *>(this)->CopyFromBase((TESContainer*)templateSelection.creature);
        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_BASE_DATA))))
        {
            reinterpret_cast<::FUN_004870f0_shell *>(this)->CopyFullNameFrom((TESFullName*)templateSelection.creature);
            struct BaseDataFlags
            {
                int inherited;
                int current;
            } flags;
            flags.current = reinterpret_cast<ActorBaseAttributes*>(
                                ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<PlayerQuestData*>(reinterpret_cast<char*>(&actorData) -
                                                                   offsetof(TESActorBaseData, actorData))))->GetCurrentProcessData())))
                                ->m_uiActorFlags;
            flags.current &= ~0x1070220a;
            flags.inherited =
                reinterpret_cast<ActorBaseAttributes*>(
                    ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<PlayerQuestData*>(reinterpret_cast<char*>(&templateSelection.creature->actorData) -
                                                       offsetof(TESActorBaseData, actorData))))->GetCurrentProcessData())))
                    ->m_uiActorFlags;
            flags.inherited &= 0x1070220a;
            reinterpret_cast<::FUN_0047dd30_shell *>(this)->FUN_0047dd30(flags.inherited | flags.current);
        }
        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_MODEL))))
        {
            reinterpret_cast<::ModelCopyView *>(this)->FUN_00489430((TESModel*)templateSelection.creature);
            reinterpret_cast<::fnv_00489db0::FUN_00489db0_shell *>(this)->CopyModelListFromComponent((TESModelList*)templateSelection.creature);
            reinterpret_cast<::FUN_0047fb50_shell *>(this)->FUN_0047fb50((TESAnimation*)templateSelection.creature);
            SetBodyPartData(templateSelection.creature->GetBodyPartData());
            reinterpret_cast<::FUN_0050eaa0_shell *>(this)->FUN_0050eaa0((::TESBoundObject *)(templateSelection.creature));
            reinterpret_cast<::FUN_005f8bb0_shell *>(this)->SetImpactDataSet(reinterpret_cast<::FUN_005f9b30_shell *>((templateSelection.creature))->GetImpactDataSet());
            SetBloodImpactMaterial(templateSelection.creature->GetBloodImpactMaterial());
            reinterpret_cast<::BGSDestructibleObjectForm *>(this)->FUN_004786e0((BGSDestructibleObjectForm*)templateSelection.creature);
            struct ModelFlags
            {
                int inherited;
                int mask;
                int current;
            } flags;
            flags.current = reinterpret_cast<ActorBaseAttributes*>(
                                ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<PlayerQuestData*>(reinterpret_cast<char*>(&actorData) -
                                                                   offsetof(TESActorBaseData, actorData))))->GetCurrentProcessData())))
                                ->m_uiActorFlags;
            flags.mask = 0x4b8f8071;
            flags.current &= ~flags.mask;
            flags.inherited =
                reinterpret_cast<ActorBaseAttributes*>(
                    ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<PlayerQuestData*>(reinterpret_cast<char*>(&templateSelection.creature->actorData) -
                                                       offsetof(TESActorBaseData, actorData))))->GetCurrentProcessData())))
                    ->m_uiActorFlags;
            flags.inherited &= flags.mask;
            reinterpret_cast<::FUN_0047dd30_shell *>(this)->FUN_0047dd30(flags.inherited | flags.current);
            if (reinterpret_cast<::FUN_005f91d0_shell *>((templateSelection.creature))->FUN_005f91d0())
            {
                CreatureSoundCollection* sounds = GetMutableCreatureSounds();
                reinterpret_cast<::FUN_005f0640_shell *>((sounds))->CopyCreatureSoundLists(reinterpret_cast<::FUN_005f91d0_shell *>((templateSelection.creature))->FUN_005f91d0());
            }
            else
            {
                SetCreatureSoundsFrom(reinterpret_cast<::FUN_005f9100_shell *>((templateSelection.creature))->FUN_005f9100());
            }
            m_eSoundLevel = templateSelection.creature->FUN_009c0070();
        }
        if (!m_pCreatureSounds)
        {
            if (reinterpret_cast<::FUN_005f91d0_shell *>((templateSelection.creature))->FUN_005f91d0())
            {
                CreatureSoundCollection* sounds = GetMutableCreatureSounds();
                reinterpret_cast<::FUN_005f0640_shell *>((sounds))->CopyCreatureSoundLists(reinterpret_cast<::FUN_005f91d0_shell *>((templateSelection.creature))->FUN_005f91d0());
            }
            else
            {
                SetCreatureSoundsFrom(reinterpret_cast<::FUN_005f9100_shell *>((templateSelection.creature))->FUN_005f9100());
            }
        }
        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_TRAITS))))
        {
            // Folded death-item getter followed by its setter.
            reinterpret_cast<::BGSDehydrationStage *>(this)->FUN_0050f9a0((::SpellItem *)(::TESLevItem *)((TESLevItem*)((int)(reinterpret_cast<::BGSTerrainManager *>((reinterpret_cast<NiTimeController*>(
                             reinterpret_cast<char*>(&templateSelection.creature->actorData) -
                             offsetof(TESActorBaseData, actorData))))->GetMinLevel()))));
            reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((reinterpret_cast<TESResponse*>(reinterpret_cast<char*>(&actorData) - offsetof(TESActorBaseData, actorData))))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(::TESIdleForm *)((TESIdleForm*)templateSelection.creature->GetVoiceType()));
            reinterpret_cast<::fnv_0047e1c0::S47b *>(this)->SetClampedValue(templateSelection.creature->GetHealthRegeneration());
            reinterpret_cast<::FUN_005fbdb0_shell *>(this)->FUN_005fbdb0(((unsigned char)(templateSelection.creature->GetCreatureType())));
            reinterpret_cast<::FUN_005f8bd0_Helper *>(this)->Set((int)(((::BGSListForm *)(::GetField158((std::intptr_t)(templateSelection.creature))))));
            SetCombatStyle(templateSelection.creature->GetCombatStyle());
        }
        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_STATS))))
        {
            reinterpret_cast<::fnv_0047dfe0::TABStub *>(this)->FUN_0047dfe0(reinterpret_cast<::FUN_0047d370_shell *>((templateSelection.creature))->FUN_0047d370());
            SetMatchesPCLevel(reinterpret_cast<::FUN_00461560_shell *>((templateSelection.creature))->FUN_00461560());
            reinterpret_cast<::fnv_0047de40::TABStub *>(this)->FUN_0047de40(reinterpret_cast<::FUN_0047d390_shell *>((templateSelection.creature))->FUN_0047d390());
            reinterpret_cast<::fnv_0047de70::TABStub *>(this)->FUN_0047de70(reinterpret_cast<::FUN_0047d3b0_shell *>((templateSelection.creature))->FUN_0047d3b0());
            reinterpret_cast<::FUN_00480000_shell *>(this)->CopyAttributesFromComponent((TESAttributes*)templateSelection.creature);
            reinterpret_cast<::FUN_00487240_shell *>(this)->CopyHealthForm((TESHealthForm*)templateSelection.creature);
            reinterpret_cast<::TESAttackDamageForm *>(this)->FUN_0047fe30((TESAttackDamageForm*)templateSelection.creature);
            reinterpret_cast<::fnv_0047e270::FUN_0047e270_shell *>(this)->SetSpeedMult(::GetShortAtOffset12((const char *)(templateSelection.creature)));
            reinterpret_cast<::fnv_0047e010::TABStub *>(this)->FUN_0047e010(templateSelection.creature->GetFatigue());
            reinterpret_cast<::FUN_005fa2c0_shell *>(this)->SetByteAt12D(::FUN_005f8f70((char *)(templateSelection.creature)));
            reinterpret_cast<::FUN_005f9af0_shell *>(this)->SetCreatureType(reinterpret_cast<::FUN_005f9ad0_shell *>((templateSelection.creature))->FUN_005f9ad0());
            reinterpret_cast<::FUN_00507780 *>(this)->SetBoltsRadiusStrength(reinterpret_cast<::FUN_00821640_shell *>((templateSelection.creature))->FUN_00821640());
            reinterpret_cast<::FUN_00803a90_shell *>(this)->SetBoltGrowWidth(::FUN_00567470((char *)(templateSelection.creature)));
            reinterpret_cast<::FUN_005f9b10_class *>(this)->SetBoltSmallWidth(reinterpret_cast<::FUN_00821660_shell *>((templateSelection.creature))->FUN_00821660());
        }
        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_FACTIONS))))
            reinterpret_cast<::fnv_0047ca20::FUN_0047ca20_shell *>(this)->CopyFactionRanks((TESActorBaseData*)templateSelection.creature);
        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_SPELLS))))
        {
            reinterpret_cast<::fnv_0048d630::SpellListAccess *>(this)->FUN_0048d630((TESSpellList*)templateSelection.creature);
            reinterpret_cast<::FUN_0047bdd0_shell *>(this)->FUN_0047bdd0((BGSTouchSpellForm*)templateSelection.creature);
        }
        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_AI_DATA))))
            CopyAISettings((TESAIForm*)templateSelection.creature);
        if (reinterpret_cast<::FUN_0047cd40_shell *>(this)->FUN_0047cd40((*(int *)&(const ::TESActorBaseData::TEMPLATE_USE_FLAG &)(USE_AI_PACKAGES))))
            reinterpret_cast<::TESAIForm *>(this)->CopyAIPackageList((TESAIForm*)templateSelection.creature);

        templateSelection.useFlags = 0;
        templateSelection.leveled = ((::TESForm *)(::FindFirstNonActorBaseTemplate((::DummyVtable *)(::TESActorBase *)(this), (unsigned short *)&(templateSelection.useFlags))));
        if (templateSelection.leveled)
        {
            reinterpret_cast<TESActorBaseData*>(reinterpret_cast<char*>(&actorData) - offsetof(TESActorBaseData, actorData))->m_ppTemplateForms = templateSelection.leveled;
            reinterpret_cast<::FUN_0047cd90_shell *>(this)->FUN_0047cd90(templateSelection.useFlags);
        }
        reinterpret_cast<::FUN_0047ccc0_shell *>(this)->FUN_0047ccc0(true);
    }
}

struct FUN_0047fe10_shell : public TESAttackDamageForm
{
    void FUN_0047fe10();
};
// @fnv 0x0047fdc0
TESAttackDamageForm::TESAttackDamageForm()
{
    reinterpret_cast<::FUN_0047fe10_shell *>(this)->FUN_0047fe10();
}

// @fnv 0x0047fe10
void FUN_0047fe10_shell::FUN_0047fe10()
{
    m_usAttackDamage = 0;
}

struct Unk_57
{
    void* FUN_0057ede0(unsigned int);
};
// Calls FUN_0057ee10, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0057ede0
void* Unk_57::FUN_0057ede0(unsigned int flags)
{
    reinterpret_cast<::FUN_0057ee10 *>(this)->FUN_0057ee10::~FUN_0057ee10();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
