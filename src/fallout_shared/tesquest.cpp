// fallout_shared/tesquest.cpp: TESQuest, PlayerQuestData, FakeQuest, QuestSaveSize and more (39 functions)

#include <new>
#include <malloc.h>
#include "fnv/decl/B408A80String.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DialogueItem.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004b1030_Class.h"
#include "fnv/decl/FUN_004b1050Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0059e400_shell.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005a9d00_shell.h"
#include "fnv/decl/FUN_005abf60_shell.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_005dc960_shell.h"
#include "fnv/decl/FUN_005ec370_shell.h"
#include "fnv/decl/FUN_005ec500_shell.h"
#include "fnv/decl/FUN_005ec700_shell.h"
#include "fnv/decl/FUN_0060ce80_Obj.h"
#include "fnv/decl/FUN_0060f320_shell.h"
#include "fnv/decl/FUN_0067fdb0_shell.h"
#include "fnv/decl/FUN_00680910_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormChangeRecord.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LoadScriptLocals.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/ResponseOwner.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_0048cca0.h"
#include "fnv/decl/SaveLocals9db0.h"
#include "fnv/decl/StageHolder.h"
#include "fnv/decl/TESFaction_RankDataView.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/ThisX.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_005a9f20__FUN_005a9f20_shell.h"
#include "fnv/decl/fnv_005aa090__FUN_005aa090.h"
#include "fnv/decl/fnv_005ec280__FUN_005ec280_shell.h"
#include "fnv/decl/fnv_005ec5d0__FUN_005ec5d0_shell.h"
#include "fnv/decl/fnv_0060f2c0__FUN_0060f2c0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005a9000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005dc000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0077a000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011de000.h"
#include "tesquest_types.h"

// @fnv 0x0060d700
unsigned int TESQuest::GetStageMask()
{
    return m_ucEnabled;
}

// @fnv 0x0060c740
void TESQuest::ResetFormData()
{
    SetEnabled(true);
    m_ucEnabled = 0;
}

// Deletes every stage object in the quest's stage list and removes each entry until the list is empty.
// @fnv 0x0060c7d0
void TESQuest::RemoveAllStages()
{
    BSSimpleList<QuestStage*>* stages = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (stages && !stages->IsEmpty())
    {
        delete (stages->m_item);
        stages->RemoveHead();
    }
}

// Walks the quest's stage list and returns whether the stage with the given index is marked done, or false if not found.
// @fnv 0x0060d600
bool TESQuest::HasStage(unsigned char ucStageIndex)
{
    BSSimpleList<QuestStage*>* stages = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (stages && !stages->IsEmpty())
    {
        if (((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>(((stages->m_item)))->FUN_009373f0())) == ucStageIndex)
            return reinterpret_cast<::FUN_005dc960_shell *>(((stages->m_item)))->FUN_005dc960();
        stages = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::Callees *>((stages))->FUN_00726070()));
    }
    return false;
}

// @fnv 0x0060c760
void TESQuest::ClearData()
{
    GetConditions()->InitializeConditionItems();
    RemoveAllStages();
    ClearObjectives();
    if (m_pScriptLocals)
    {
        delete m_pScriptLocals;
        m_pScriptLocals = 0;
    }
}

// Deletes every BGSQuestObjective in the objective list and removes each entry until the list is empty.
// @fnv 0x0060c870
void TESQuest::ClearObjectives()
{
    BSSimpleList<BGSQuestObjective*>* objectives = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (objectives && !objectives->IsEmpty())
    {
        delete (objectives->m_item);
        objectives->RemoveHead();
    }
}

// @fnv 0x0060f110
void TESQuest::GetTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets,
                                       BSSimpleList<BGSQuestObjective*>* objectives)
{
    if (!targets)
        return;
    reinterpret_cast<::FileMatchList *>((targets))->RemoveAll();
    if (reinterpret_cast<::FUN_0059e400_shell *>(this)->FUN_0059e400())
        return;
    BSSimpleList<BGSQuestObjective*>* pObjectiveNode = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (pObjectiveNode && (pObjectiveNode->m_item))
    {
        if (reinterpret_cast<::RefList *>((objectives))->FUN_005f65d0((void **)&((pObjectiveNode->m_item))))
            reinterpret_cast<::FUN_005ec500_shell *>(((pObjectiveNode->m_item)))->AddMatchingTargetsToList(targets);
        pObjectiveNode = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::Callees *>((pObjectiveNode))->FUN_00726070()));
    }
}

// Scans the stage list for the highest done stage index and stores it into the quest's highest completed stage field if greater.
// @fnv 0x0060d670
void TESQuest::UpdateStageMask()
{
    BSSimpleList<QuestStage*>* stages = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    unsigned char currentStage = 0;
    while (stages && !stages->IsEmpty())
    {
        QuestStage* stage = (stages->m_item);
        if (reinterpret_cast<::FUN_005dc960_shell *>((stage))->FUN_005dc960() && ((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>((stage))->FUN_009373f0())) > currentStage)
            currentStage = ((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>((stage))->FUN_009373f0()));
        stages = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::Callees *>((stages))->FUN_00726070()));
    }
    if (currentStage > m_ucEnabled)
        m_ucEnabled = currentStage;
}

// @fnv 0x0060EFD0
bool TESQuest::HasTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets,
                                       BSSimpleList<BGSQuestObjective*>* objectives)
{
    BSSimpleList<RegionObjectEntry*>* currentTarget = targets;
    BSSimpleList<BGSQuestObjective*>* currentObjective = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    if (currentTarget && currentObjective)
    {
        while (currentObjective)
        {
            if ((currentObjective->m_item) && (*(::QUEST_OBJECTIVE_STATE *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((currentObjective->m_item)))->FUN_007af430())) == QOS_DISPLAYED &&
                reinterpret_cast<::RefList *>((objectives))->FUN_005f65d0((void **)&((currentObjective->m_item))))
            {
                BSSimpleList<RegionObjectEntry*>* objectiveTarget = ((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::NonActorMagicTarget *>(((currentObjective->m_item)))->GetActiveEffectList()));
                while (objectiveTarget)
                {
                    RegionObjectEntry* target = (objectiveTarget->m_item);
                    if (target && ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>((target))->GetCurrentProcessData()))->ContainsTrait(target->GetReference(false), 0))
                    {
                        if (!currentTarget || !(currentTarget->m_item) || (currentTarget->m_item) != target)
                            return false;
                        if (currentTarget)
                            currentTarget = ((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::Callees *>((currentTarget))->FUN_00726070()));
                    }
                    objectiveTarget = ((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::Callees *>((objectiveTarget))->FUN_00726070()));
                }
            }
            currentObjective = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::Callees *>((currentObjective))->FUN_00726070()));
        }
    }
    if (currentTarget && !currentTarget->IsEmpty())
        return false;
    return true;
}

// @fnv 0x0060CBA0
void TESQuest::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    tESScriptableFormComponent.InitItem(this);
    if (((::Script *)(reinterpret_cast<::Callees *>(&(tESScriptableFormComponent))->FUN_00726070())))
    {
        m_pScriptLocals = reinterpret_cast<::FUN_005abf60_shell *>((((::Script *)(reinterpret_cast<::Callees *>(&(tESScriptableFormComponent))->FUN_00726070()))))->FUN_005abf60();
        reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>((((::Script *)(reinterpret_cast<::Callees *>(&(tESScriptableFormComponent))->FUN_00726070()))))->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(::TESQuest *)(this));
        if (m_pScriptLocals)
            SetFormFlags(0x40000000);
        if ((*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011cb81c)).Bool()->b)
            SetEnabled(true);
    }
    if (GetConditions())
        GetConditions()->InitItem(this);
    BSSimpleList<QuestStage*>* stage = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (stage && !stage->IsEmpty())
    {
        reinterpret_cast<::FUN_0060f320_shell *>(((stage->m_item)))->FUN_0060f320(this);
        stage = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::Callees *>((stage))->FUN_00726070()));
    }
    BSSimpleList<BGSQuestObjective*>* objective = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (objective && !objective->IsEmpty())
    {
        (objective->m_item)->InitItem(this);
        objective = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::Callees *>((objective))->FUN_00726070()));
    }
    SetStartsEnabled(reinterpret_cast<::TESFaction_RankDataView *>(this)->FUN_00455620());
    SetInitializationState(true);
}

enum QUEST_CHUNK_ID
{
    CHUNK_EDID = 0x44494445,
    CHUNK_OBND = 0x444e424f,
    CHUNK_SCRI = 0x49524353,
    CHUNK_FULL = 0x4c4c5546,
    CHUNK_ICON = 0x4e4f4349,
    CHUNK_DATA = 0x41544144,
    CHUNK_QOBJ = 0x4a424f51,
    CHUNK_QSTA = 0x41545351,
    CHUNK_INDX = 0x58444e49,
    CHUNK_QSDT = 0x54445351,
    CHUNK_SCDA = 0x41444353,
    CHUNK_SLSD = 0x44534c53,
    CHUNK_SCVR = 0x52564353,
    CHUNK_SCRO = 0x4f524353,
    CHUNK_SCHR = 0x52484353,
    CHUNK_SCRV = 0x56524353,
    CHUNK_CNAM = 0x4d414e43,
    CHUNK_CTDA = 0x41445443
};

// @fnv 0x0060C8E0
BGSQuestObjective* TESQuest::GetObjective(unsigned int index)
{
    struct ObjectiveSearch
    {
        BSSimpleList<BGSQuestObjective*>* objectives;
        unsigned int objectiveIndex;
    } search;
    search.objectives = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    search.objectiveIndex = 0;
    while (search.objectives && !search.objectives->IsEmpty())
    {
        BGSQuestObjective* objective = (search.objectives->m_item);
        if (objective && ((unsigned int)(reinterpret_cast<::Callees *>((objective))->FUN_00726070())) == index)
            return objective;
        search.objectives = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::Callees *>((search.objectives))->FUN_00726070()));
    }
    return 0;
}

// @fnv 0x0060EAF0
void TESQuest::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::TESForm *>(this)->LoadGame(buffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(2)))->FUN_004280f0(2))
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&data.m_ucEntryType), 1);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(4)))->FUN_004280f0(4))
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&data.fQuestDelayTime), 4);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x80000000U)))->FUN_004280f0(0x80000000U))
    {
        unsigned int stageCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
        for (unsigned int i = 0; i < stageCount; ++i)
        {
            unsigned char stageIndex = 0;
            bool done = false;
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&stageIndex), 1);
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&done), 1);
            {
                QuestStage* stage = GetStage(stageIndex);
                if (stage)
                    reinterpret_cast<::FUN_0067fdb0_shell *>((stage))->FUN_0067fdb0(done);
                else
                    ::FUN_00845cc0("SAVELOAD: Could not find stage %i in quest %s during load.", stageIndex,
                               GetEditorName());
                unsigned int itemCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
                for (unsigned int j = 0; j < itemCount; ++j)
                {
                    unsigned char itemIndex = 0;
                    bool hasDate = false;
                    Date logDate;
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&itemIndex), 1);
                    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&hasDate), 1);
                    if (hasDate)
                        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&logDate), 4);
                    if (hasDate && stage)
                    {
                        PlayerQuestData* item = ((::PlayerQuestData *)(reinterpret_cast<::fnv_0060f2c0::FUN_0060f2c0_shell *>((stage))->FindItemByDoneFlag(itemIndex)));
                        if (item)
                            reinterpret_cast<::MiddleHighProcess *>((item))->SetFaceAnimationData((::TargetDoorController *)(::Date *)(new Date(logDate)));
                    }
                }
            }
        }
        m_ucEnabled = 0;
        UpdateStageMask();
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x40000000U)))->FUN_004280f0(0x40000000U))
    {
        if (m_pScriptLocals)
            reinterpret_cast<::fnv_005a9f20::FUN_005a9f20_shell *>((m_pScriptLocals))->FUN_005a9f20((::fnv_005a9f20::BGSLoadFormBuffer *)(buffer));
        else
        {
            ScriptLocals locals;
            reinterpret_cast<::fnv_005a9f20::FUN_005a9f20_shell *>(&(locals))->FUN_005a9f20((::fnv_005a9f20::BGSLoadFormBuffer *)(buffer));
        }
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x20000000U)))->FUN_004280f0(0x20000000U))
    {
        unsigned int objectiveCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
        for (unsigned int k = 0; k < objectiveCount; ++k)
        {
            struct SavedObjectiveState
            {
                unsigned int index;
                QUEST_OBJECTIVE_STATE state;
            } savedObjective;
            savedObjective.index = 0;
            savedObjective.state = QOS_DORMANT;
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&savedObjective.index), 4);
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&savedObjective.state), 4);
            BGSQuestObjective* objective = GetObjective(savedObjective.index);
            if (objective)
                reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((objective))->FUN_0050f9c0((*(::fnv_0050f9c0::TESForm * *)&(savedObjective.state)));
        }
    }
}

// @fnv 0x0060CEB0
bool TESQuest::Load(TESFile* file)
{
    QuestStage* stage;
    {
        unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
        if (formType != FORM_QUEST)
            return false;
        stage = 0;
        PlayerQuestData* item = 0;
        RegionObjectEntry* target = 0;
        BGSQuestObjective* objective = 0;
        reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
        SetInitializationState(false);
        unsigned char itemIndex = 0;
        int chunk;
        while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
        {
            switch (chunk)
            {
            case CHUNK_EDID: {
                char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
                SetEditorID_AtRuntime(editorID);
                break;
            }
            case CHUNK_OBND:
                readOBNDSubRecord(file);
                break;
            case CHUNK_SCRI: {
                unsigned int script = 0;
                file->GetChunkData(&script);
                reinterpret_cast<::CombatProcedure *>(&(tESScriptableFormComponent))->Initialize((::CombatController *)(::Script *)(reinterpret_cast<Script*>(script)));
                tESScriptableFormComponent.InitItem(this);
                break;
            }
            case CHUNK_FULL:
                ::ReadFullName(this ? &tESFullNameComponent : 0, file);
                break;
            case CHUNK_ICON:
                TESTexture::ReadTextureData(this ? &tESIconComponent : 0, file);
                break;
            case CHUNK_DATA:
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data, sizeof(data));
                break;
            case CHUNK_QOBJ:
                objective = new BGSQuestObjective;
                reinterpret_cast<::FUN_005ec370_shell *>((objective))->FUN_005ec370(file);
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()))))->FUN_00905820((void *)&(objective));
                objective->SetOwner(this);
                break;
            case CHUNK_QSTA:
                stage = 0;
                item = 0;
                target = new RegionObjectEntry;
                target->Load(file);
                if (!objective)
                {
                    objective = new BGSQuestObjective;
                    reinterpret_cast<::Callees *>((((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()))))->FUN_00905820((void *)&(objective));
                    objective->SetOwner(this);
                }
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::NonActorMagicTarget *>((objective))->GetActiveEffectList()))))->FUN_00905820((void *)&(target));
                break;
            case CHUNK_INDX:
                stage = new QuestStage;
                stage->Load(file);
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00905820((void *)&(stage));
                break;
            case CHUNK_QSDT:
                if (stage)
                {
                    item = new PlayerQuestData;
                    item->Load(file);
                    item->SetIndex(itemIndex);
                    ++itemIndex;
                    reinterpret_cast<::Callees *>((((::BSSimpleList< ::PlayerQuestData *> *)(reinterpret_cast<::BaseProcess *>((stage))->GetCurrentProcessData()))))->FUN_00905820((void *)&(item));
                }
                continue;
                break;
            case CHUNK_SCDA:
            case CHUNK_SLSD:
            case CHUNK_SCVR:
            case CHUNK_SCRO:
            case CHUNK_SCHR:
            case CHUNK_SCRV:
                if (item)
                {
                    item->Load(file);
                    continue;
                }
                break;
            case CHUNK_CNAM:
                if (item)
                    item->SetHasLogEntry(true);
                break;
            case CHUNK_CTDA:
                if (item)
                    ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>((item))->GetCurrentProcessData()))->Load(file);
                else if (target)
                    ((::PerkEntryConditionSet *)(reinterpret_cast<::BaseProcess *>((target))->GetCurrentProcessData()))->Load(file);
                else
                    GetConditions()->Load(file);
                break;
            }
            if (!file->NextChunk())
                break;
        }
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_0060ce80_Obj *>(&(data))->FUN_0060ce80();
        return true;
    }
}

// @fnv 0x0060c9c0
void TESQuest::SetEnabled(bool enabled)
{
    enabled
        ? reinterpret_cast<QuestData*>(((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<struct ::FUN_005a8080 *>((reinterpret_cast<TESRecipe*>(this)))->GetField())))->m_ucEntryType |= 1
        : reinterpret_cast<QuestData*>(((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<struct ::FUN_005a8080 *>((reinterpret_cast<TESRecipe*>(this)))->GetField())))->m_ucEntryType &= ~1;
    MarkAsModified(2);
}

// @fnv 0x0060cd00
void TESQuest::SetStartsEnabled(bool enabled)
{
    enabled
        ? reinterpret_cast<QuestData*>(((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<struct ::FUN_005a8080 *>((reinterpret_cast<TESRecipe*>(this)))->GetField())))->m_ucEntryType |= 16
        : reinterpret_cast<QuestData*>(((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<struct ::FUN_005a8080 *>((reinterpret_cast<TESRecipe*>(this)))->GetField())))->m_ucEntryType &= ~16;
}

// @fnv 0x0060d4d0
void TESQuest::RunScript()
{
    if (((::Script *)(reinterpret_cast<::Callees *>(&(tESScriptableFormComponent))->FUN_00726070())))
        reinterpret_cast<::FUN_005ac1e0_shell *>((((::Script *)(reinterpret_cast<::Callees *>(&(tESScriptableFormComponent))->FUN_00726070()))))->FUN_005ac1e0(0, m_pScriptLocals, 0, false);
}

// @fnv 0x0060d490
void PlayerQuestData::SetHasLogEntry(bool abHasLogEntry)
{
    bHasLogEntry = abHasLogEntry;
}

// @fnv 0x0060d4b0
void PlayerQuestData::SetIndex(unsigned char index)
{
    m_ucClipIdentifier = index;
}

struct FUN_004b1000_shell
{
    short a[2];
    short* CopyShortPair(const short* b);
};

// Copies the first two shorts from b into the object's a array and returns a pointer to it.
// @fnv 0x004b1000
short* FUN_004b1000_shell::CopyShortPair(const short* pSource)
{
    a[0] = pSource[0];
    a[1] = pSource[1];
    return a;
}

struct MiscStatManager
{
    enum MiscStat
    {
    };
    static void __cdecl AddMiscStat(MiscStat id, int val);
};

// @fnv 0x0060cad0
void FUN_0060cad0(int aeStatId)
{
    MiscStatManager::AddMiscStat((MiscStatManager::MiscStat)aeStatId, -1);
}

struct FUN_0060d5e0_shell : TESRecipe
{
    bool HasFlag8();
};
// @fnv 0x0060d510
bool TESQuest::IsStageComplete(unsigned char ucStageIndex)
{
    BSSimpleList<QuestStage*>* stages = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (stages && !stages->IsEmpty())
    {
        if (((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>(((stages->m_item)))->FUN_009373f0())) == ucStageIndex)
        {
            if (!reinterpret_cast<::FUN_0059e400_shell *>(this)->FUN_0059e400() || reinterpret_cast<::FUN_0060d5e0_shell *>(this)->HasFlag8())
                SetEnabled(true);
            if (ucStageIndex > m_ucEnabled)
                m_ucEnabled = ucStageIndex;
            reinterpret_cast<::StageHolder *>(((stages->m_item)))->FUN_0060f4a0(this, false);
            MarkAsModified(0x80000000U);
            return true;
        }
        stages = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::Callees *>((stages))->FUN_00726070()));
    }
    return false;
}

// @fnv 0x0060d5e0
bool FUN_0060d5e0_shell::HasFlag8()
{
    return (reinterpret_cast<unsigned char*>(((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<struct ::FUN_005a8080 *>((this))->GetField())))[0] & 8) != 0;
}

struct FUN_0060da90_shell
{
    void* GetOffsetPointer();
};

// @fnv 0x0060da90
void* FUN_0060da90_shell::GetOffsetPointer()
{
    return reinterpret_cast<char*>(this) + 0x6B0;
}

struct FUN_00737e30_shell
{
    unsigned int m_210;
    unsigned int GetFieldAt210();
};

// @fnv 0x00737e30
unsigned int FUN_00737e30_shell::GetFieldAt210()
{
    return ((unsigned int*)this)[0x210 / 4];
}

struct FUN_004b0fa0_shell
{
    short m_iWordAt00;
    short m_cByteAtOffset2;
    FUN_004b0fa0_shell();
};

// @fnv 0x004b0fa0
FUN_004b0fa0_shell::FUN_004b0fa0_shell()
{
    m_iWordAt00 = 0;
    m_cByteAtOffset2 = 0;
}

struct FUN_0060d8d0_shell : TESRecipe
{
    bool HasFlag0x10();
};

// @fnv 0x0060d8d0
bool FUN_0060d8d0_shell::HasFlag0x10()
{
    return (*reinterpret_cast<unsigned char*>(((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<struct ::FUN_005a8080 *>((this))->GetField()))) & 0x10) != 0;
}

struct FUN_0060e680_shell
{
    void SetFlags(unsigned int arg);
};

// @fnv 0x0060e680
void FUN_0060e680_shell::SetFlags(unsigned int auiFlags)
{
    *(unsigned int*)((char*)this + 0x54) = *(unsigned int*)((char*)this + 0x54) | auiFlags;
}

struct FakeQuest
{
    void FUN_0060c660();
    void* FUN_0060c630(unsigned int);
};
extern "C" void __cdecl _security_check_cookie(unsigned int);
extern "C" unsigned int DAT_011c16bc;
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
struct BSStringT_char
{
};
struct BSStr
{
};
struct FUN_0060dab0_shell
{
    bool FUN_0060dab0(const char* arg);
};
// @fnv 0x0060dab0
bool FUN_0060dab0_shell::FUN_0060dab0(const char* pcString)
{
    unsigned int size = ::FUN_0044a670(pcString) + 1;
    char* buffer = static_cast<char*>(_alloca(size));
    TaskQueueInterface::CopyStringToBuffer(buffer, size, pcString);
    if (!((char *)(reinterpret_cast<::B408A80String *>((void *)(reinterpret_cast<BSStringT_char*>(reinterpret_cast<char*>(this) + 0x64)))->FUN_00408a80(buffer, true))))
        return false;
    reinterpret_cast<::TextString *>((reinterpret_cast<BSStr*>(reinterpret_cast<char*>(this) + 0x64)))->FUN_004037f0(buffer, 0);
    return true;
}

struct Flt
{
    operator unsigned int();
};
struct FUN_0060c5f0_Class
{
    char _pad[0x64];
    Flt fld64;
    const char* GetStringOrEmpty();
};
// Returns the string pointer stored in fld64, or an empty string when fld64 is zero.
// @fnv 0x0060c5f0
const char* FUN_0060c5f0_Class::GetStringOrEmpty()
{
    return (unsigned int)fld64 ? (const char*)(unsigned int)fld64 : "";
}

struct BGSSaveFormBuffer : BGSLoadFormBuffer
{
};
struct FUN_0060e7c0_outer
{
    char _pad[0x5c];
    int _5c;
    void FUN_0060e7c0(BGSSaveFormBuffer* apSaveGameBuffer);
};
// @fnv 0x0060e7c0
void FUN_0060e7c0_outer::FUN_0060e7c0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apSaveGameBuffer->GetChangeFlags(0x40000000)))->FUN_004280f0(0x40000000) && _5c == 0)
        reinterpret_cast<::FormChangeRecord *>((apSaveGameBuffer))->FUN_005621f0(0x40000000);
}

namespace stand {
struct TESScriptableForm
{
    virtual void f0();
    TESScriptableForm();
    void* m_pFormScript;
    bool m_bHasScript;
};
struct TESIcon
{
    virtual void f0();
    TESIcon();
    ~TESIcon();
    void* p;
    unsigned int n;
};
struct TESFullName
{
    virtual void f0();
    TESFullName();
    ~TESFullName();
    void* p;
    unsigned int n;
};
}
struct FUN_0060c5c0
{
    FUN_0060c5c0();
    unsigned int a;
    float b;
};
struct SL
{
    SL();
    ~SL();
    void* a;
    void* b;
};
struct CondS
{
    CondS();
    ~CondS();
    void* a;
    void* b;
};
struct StrMem
{
    StrMem();
    ~StrMem();
    char* p;
    unsigned short a;
    unsigned short b;
};
struct FUN_0060c4b0_QI
{
};
struct FUN_0060c4b0 : public TESForm, public stand::TESScriptableForm, public stand::TESIcon, public stand::TESFullName
{
    FUN_0060c5c0 data;
    SL m_kStageList;
    SL m_kObjectives;
    CondS m_kInfoConditions;
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    StrMem strEditorID;
    FUN_0060c4b0();
    virtual ~FUN_0060c4b0();
};
// @fnv 0x0060c4b0
FUN_0060c4b0::FUN_0060c4b0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(FORM_QUEST)));
    m_pScriptLocals = 0;
    reinterpret_cast<::TESQuest *>((((FUN_0060c4b0_QI*)this)))->ResetFormData();
}


struct FUN_0060caf0_shell : TESQuest
{
    void FUN_0060caf0(bool abCompleted);
};

// Sets or clears the completed flag bit 0x40 on the quest, calls vtable slot 18 with 2, and notifies via FUN_0077a480 when newly completed.
// @fnv 0x0060caf0
void FUN_0060caf0_shell::FUN_0060caf0(bool abCompleted)
{
    if (abCompleted && reinterpret_cast<::FUN_0059e400_shell *>(this)->FUN_0059e400())
        return;
    if (abCompleted && !(data.m_ucEntryType & 0x40))
    {
        data.m_ucEntryType |= 0x40;
        data.m_ucEntryType |= 2;
        ((void(*)(void*, unsigned int))(*(void***)this)[18])(this, 2);
        ::fnv_0077a480::FUN_0077a480((::fnv_0077a480::TESQuest *)(void *)(this));
    }
    else if (!abCompleted && (data.m_ucEntryType & 0x40))
    {
        data.m_ucEntryType &= ~0x40;
        ((void(*)(void*, unsigned int))(*(void***)this)[18])(this, 2);
    }
}

struct TopicMenuController
{
    static void __cdecl IncrementMiscStat(int id);
};

struct FUN_0060ca30_shell
{
    // Virtual destructor for the shell type; performs no work.
// @fnv 0x0060ca30
    virtual ~FUN_0060ca30_shell()
    {}
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void RemoveTopic(int id)
    {}

    unsigned char _pad[0x38];
    unsigned char data;

    void FUN_0060ca30(bool abCompleted);
};

void FUN_0060ca30_shell::FUN_0060ca30(bool abCompleted)
{
    if (abCompleted && !(data & 2))
    {
        data |= 2;
        RemoveTopic(2);
        TopicMenuController::IncrementMiscStat(0);
        ::fnv_0077a480::FUN_0077a480((::fnv_0077a480::TESQuest *)(void *)(this));
    }
    else if (!abCompleted && (data & 2))
    {
        data &= ~2;
        RemoveTopic(2);
        FUN_0060cad0(0);
    }
}

class QuestBase
{
  public:
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    BSSimpleList<TESFile*> m_kSourceFiles;
    virtual ~QuestBase();
};

class FUN_0060c660 : public QuestBase, public TESScriptableForm, public TESIcon, public TESFullName
{
  public:
    QuestData data;
    BSSimpleList<QuestStage*> m_kStageList;
    BSSimpleList<BGSQuestObjective*> m_kObjectives;
    PerkEntryConditionSet m_kInfoConditions;
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    unsigned char layoutPadding61[3];
    BSStringT<char> strEditorID;

    virtual ~FUN_0060c660();
};
// @fnv 0x0060c630
void* FakeQuest::FUN_0060c630(unsigned int flags)
{
    reinterpret_cast<::FUN_0060c660 *>(this)->FUN_0060c660::~FUN_0060c660();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls ResetDefaults to reset the quest's state.
// @fnv 0x0060c660
FUN_0060c660::~FUN_0060c660()
{
    reinterpret_cast<::TESQuest *>(this)->ClearData();
}

struct FUN_0060c950_item
{
};

struct FUN_0060c950_node
{
};

struct FUN_0060c950_cls
{
    void FUN_0060c950(int a1);
};

// @fnv 0x0060c950
void FUN_0060c950_cls::FUN_0060c950(int a1)
{
    FUN_0060c950_node* node = ((::FUN_0060c950_node *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (node && *((::FUN_0060c950_item **)((void *)(node))))
    {
        reinterpret_cast<::fnv_005ec5d0::FUN_005ec5d0_shell *>(((*((::FUN_0060c950_item **)((void *)(node))))))->FUN_005ec5d0((::fnv_005ec5d0::QUEST_OBJECTIVE_STATE)(reinterpret_cast<::BGSQuestObjective *>(((*((::FUN_0060c950_item **)((void *)(node))))))->GetDisplayed() ? 3 : 2));
        node = ((::FUN_0060c950_node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
}

struct FNV_InitNode;
struct FNV_SubObject
{
    void FUN_00483710();
};
struct FNV_NodeValue
{
    FNV_SubObject* object;
};
struct FNV_InitNode
{
    bool FUN_008256d0();
};
struct FNV_InitPart
{
};
struct FUN_0060cd60_shell : TESQuest
{
    void FUN_0060cd60();
};
struct FNV_EventObject
{
};

// @fnv 0x0060cd60
void FUN_0060cd60_shell::FUN_0060cd60()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::S_0048cca0 *>((reinterpret_cast<FNV_InitPart*>(&tESScriptableFormComponent)))->FUN_0048cca0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<FNV_InitPart*>(&tESIconComponent + 1)))->FUN_00487010();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FNV_InitPart*>(&tESIconComponent)))->FUN_0048e370(0x4e4f4349);
    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::FUN_0060ce80_Obj *>((reinterpret_cast<FNV_InitPart*>(&tESFullNameComponent + 1)))->FUN_0060ce80();
    }
    reinterpret_cast<::SDSaveForm *>(this)->FUN_00485e20(reinterpret_cast<char*>(&tESFullNameComponent) + 12, 8);
    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::FUN_0060ce80_Obj *>((reinterpret_cast<FNV_InitPart*>(&tESFullNameComponent + 1)))->FUN_0060ce80();
    }
    if (((::FNV_SubObject *)(reinterpret_cast<::TESQuest *>(this)->GetConditions())) != 0)
    {
        reinterpret_cast<::FUN_00680910_shell *>((reinterpret_cast<FNV_EventObject*>(((::FNV_SubObject *)(reinterpret_cast<::TESQuest *>(this)->GetConditions())))))->ProcessItems();
    }
    FNV_InitNode* node = ((::FNV_InitNode *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (node != 0 && !node->FUN_008256d0())
    {
        reinterpret_cast<::TESForm *>((((::FNV_NodeValue *)((void *)(node)))->object))->ClearData();
        node = ((::FNV_InitNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    FNV_InitNode* pOtherNode = ((::FNV_InitNode *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (pOtherNode != 0 && !pOtherNode->FUN_008256d0())
    {
        reinterpret_cast<::fnv_005ec280::FUN_005ec280_shell *>((((::FNV_NodeValue *)((void *)(pOtherNode)))->object))->FUN_005ec280();
        pOtherNode = ((::FNV_InitNode *)(reinterpret_cast<::Callees *>((pOtherNode))->FUN_00726070()));
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct QuestEntryStandIn
{
};

struct PlayerQuestListStandIn
{
};


// Clears apList, then walks the player's quest entry list and appends or prepends entries whose quest matches apQuest or passes the completed/any filter.
// @fnv 0x0060d8f0
void __cdecl FUN_0060d8f0(BSSimpleList<QuestEntryStandIn*>* apList, TESQuest* apQuest, bool abCompleted, bool abAddTail,
                          bool abAny)
{
    if (!apList)
        return;
    reinterpret_cast<::FileMatchList *>((apList))->RemoveAll();
    BSSimpleList<TESQuest*> kSeen;
    BSSimpleList<QuestEntryStandIn*>* pNode = ((::BSSimpleList< ::QuestEntryStandIn *> *)(reinterpret_cast<::FUN_0060da90_shell *>(((*reinterpret_cast<::PlayerQuestListStandIn * *>(&::_g_thePlayer))))->GetOffsetPointer()));
    while (pNode && (pNode->m_item))
    {
        TESQuest* pQuest;
        QuestEntryStandIn* pEntry2 = (pNode->m_item);
        pQuest = ((::TESQuest *)(reinterpret_cast<::DialogueItem *>((pEntry2))->SelectDefaultResponseList()));
        pNode = ((::BSSimpleList< ::QuestEntryStandIn *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        if (pQuest)
        {
            bool bOk3 = !apQuest || (apQuest && pQuest == apQuest);
            if (bOk3 && !apQuest)
            {
                bOk3 = (abCompleted == reinterpret_cast<::FUN_0059e400_shell *>((pQuest))->FUN_0059e400() || abAny) && !reinterpret_cast<::RefList *>(&(kSeen))->FUN_005f65d0((void **)&(pQuest));
                if (bOk3)
                    kSeen.AddHead(pQuest);
            }
            if (bOk3 && ((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pEntry2))->GetBaseTexture())) && ((void *)(reinterpret_cast<::ResponseOwner *>((pEntry2))->FUN_0060fdb0((::RecForm *)(pQuest)))))
            {
                if (abAddTail)
                    reinterpret_cast<::Callees *>((apList))->FUN_00905820((void *)&(pEntry2));
                else
                    apList->AddHead(pEntry2);
            }
        }
    }
    reinterpret_cast<::FileMatchList *>(&(kSeen))->RemoveAll();
}

struct SaveFormInfo
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char flagsStart;
};

struct SaveLoadGameStub
{
};

struct FormSaveSizeStub
{
    unsigned short GetSaveSize(unsigned int changedFlags);
};

struct ScriptLocalsSaveStub
{
    unsigned short GetSaveSize();
};

struct StageItemListStub
{
    int GetSize();
};

struct QuestStageStub
{
};

struct StageNodeStub
{
};


struct QuestSaveSize : TESQuest
{
    unsigned short FUN_0060dba0(unsigned int changedFlags);
};

// @fnv 0x0060dba0
unsigned short QuestSaveSize::FUN_0060dba0(unsigned int changedFlags)
{
    unsigned short size7 = 0;
    size7 += reinterpret_cast<::FUN_00484bf0_shell *>((((FormSaveSizeStub*)this)))->FUN_00484bf0(changedFlags);
    unsigned short baseSize2 = size7;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        size7 += 4;
        size7 += 2;
    }
    if (changedFlags & 2)
    {
        size7 += 1;
    }
    if (changedFlags & 0x80000000)
    {
        StageNodeStub* node9 = ((::StageNodeStub *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
        size7 += 1;
        while (node9)
        {
            QuestStageStub* stage = ((::QuestStageStub *)((void *)(node9)));
            if (stage)
            {
                size7 += 2;
                StageItemListStub* items2 = ((::StageItemListStub *)(reinterpret_cast<::BaseProcess *>((stage))->GetCurrentProcessData()));
                size7 += items2->GetSize() * 5 + 1;
            }
            node9 = ((::StageNodeStub *)(reinterpret_cast<::Callees *>((node9))->FUN_00726070()));
        }
    }
    if (changedFlags & 0x40000000)
    {
        size7 += ::GetScriptLocalsSerializedSize((::ScriptLocals *)(((ScriptLocalsSaveStub*)m_pScriptLocals)));
    }
    if ((*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011de4e8)).Bool()->b)
    {
        SaveFormInfo* info = ((::SaveFormInfo *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (info)
        {
            TESForm* form = ::FUN_004839c0(info->formID);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return size7;
}

struct FUN_004534f0_shell
{
    void FUN_004534f0(unsigned int auiFlags);
};
// @fnv 0x0060EE40
void TESQuest::Revert(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0((unsigned int)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetOldChangeFlags(0x80000000U)))->FUN_004280f0(0x80000000U))
    {
        BSSimpleList<QuestStage*>* stages = &m_kStageList;
        while (stages)
        {
            QuestStage* stage = (stages->m_item);
            if (stage)
            {
                reinterpret_cast<::FUN_0067fdb0_shell *>((stage))->FUN_0067fdb0(false);
                BSSimpleList<PlayerQuestData*>* items = ((::BSSimpleList< ::PlayerQuestData *> *)(reinterpret_cast<::BaseProcess *>((stage))->GetCurrentProcessData()));
                while (items)
                {
                    PlayerQuestData* item = (items->m_item);
                    if (item && ((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((item))->GetBaseTexture())))
                    {
                        delete ((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((item))->GetBaseTexture()));
                        reinterpret_cast<::MiddleHighProcess *>((item))->SetFaceAnimationData((::TargetDoorController *)(::Date *)(0));
                    }
                    items = ((::BSSimpleList< ::PlayerQuestData *> *)(reinterpret_cast<::Callees *>((items))->FUN_00726070()));
                }
            }
            stages = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::Callees *>((stages))->FUN_00726070()));
        }
        m_ucEnabled = 0;
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetOldChangeFlags(0x40000000U)))->FUN_004280f0(0x40000000U) && m_pScriptLocals)
        reinterpret_cast<::fnv_005aa090::FUN_005aa090 *>((m_pScriptLocals))->Method((int)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetOldChangeFlags(0x20000000U)))->FUN_004280f0(0x20000000U))
    {
        BSSimpleList<BGSQuestObjective*>* objectives = &m_kObjectives;
        while (objectives)
        {
            BGSQuestObjective* objective = (objectives->m_item);
            if (objective)
                reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((objective))->FUN_0050f9c0((*(::fnv_0050f9c0::TESForm * *)&(const ::QUEST_OBJECTIVE_STATE &)(QOS_DORMANT)));
            objectives = ((::BSSimpleList< ::BGSQuestObjective *> *)(reinterpret_cast<::Callees *>((objectives))->FUN_00726070()));
        }
    }
}

struct QuestScriptLocals
{
};

struct FUN_0060e6a0_shell : TESQuest
{
    void FUN_0060e6a0(unsigned int auiFlags);
};

// @fnv 0x0060e6a0
void FUN_0060e6a0_shell::FUN_0060e6a0(unsigned int auiFlags)
{
    ((FUN_004534f0_shell*)this)->FUN_004534f0(auiFlags);
    if (auiFlags & 0x80000000)
    {
        BSSimpleList<QuestStage*>* pStageIter = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
        while (pStageIter)
        {
            QuestStage* pStage = (pStageIter->m_item);
            if (pStage)
            {
                reinterpret_cast<::FUN_0067fdb0_shell *>((pStage))->FUN_0067fdb0(false);
                BSSimpleList<PlayerQuestData*>* pItemIter = ((::BSSimpleList< ::PlayerQuestData *> *)(reinterpret_cast<::BaseProcess *>((pStage))->GetCurrentProcessData()));
                while (pItemIter)
                {
                    PlayerQuestData* pItem3 = (pItemIter->m_item);
                    Date* pDate3 = pItem3 ? ((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pItem3))->GetBaseTexture())) : 0;
                    if (pDate3)
                    {
                        reinterpret_cast<::MiddleHighProcess *>((pItem3))->SetFaceAnimationData((::TargetDoorController *)(::Date *)(0));
                        delete pDate3;
                    }
                    pItemIter = ((::BSSimpleList< ::PlayerQuestData *> *)(reinterpret_cast<::Callees *>((pItemIter))->FUN_00726070()));
                }
            }
            pStageIter = ((::BSSimpleList< ::QuestStage *> *)(reinterpret_cast<::Callees *>((pStageIter))->FUN_00726070()));
        }
        m_ucEnabled = 0;
    }
    if ((auiFlags & 0x40000000) && m_pScriptLocals)
    {
        reinterpret_cast<::FUN_005a9d00_shell *>((((QuestScriptLocals*)m_pScriptLocals)))->FUN_005a9d00();
    }
}

struct QuestSaveManager
{
};
struct QuestSaveItem
{
};
struct QuestSaveItemNode
{
};
struct QuestSaveStage
{
};
struct QuestSaveStageNode
{
};
struct QuestSaveLocals
{
};
struct QuestSave : TESQuest
{
    void FUN_0060dd50(unsigned int flags);
};

// Writes the quest's save data: flags, stage and item lists, optional locals, debug size logging, and a block-size header when block saving is active.
// @fnv 0x0060dd50
void QuestSave::FUN_0060dd50(unsigned int flags)
{
    reinterpret_cast<::PC7d *>(this)->FUN_00484c20(flags);
    unsigned short h = 0;  // Reserved block size.
    unsigned char* p = 0;  // Address of the reserved block-size field.
    unsigned char* a = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if ((*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011de4e8)).Bool()->b)
        a = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if (reinterpret_cast<::FUN_00862110_cls *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned int marker = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&marker, 4);
        p = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        reinterpret_cast<::FUN_008579b0_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&h, 2);
    }
    if (flags & 2)
    {
        unsigned char questFlags = *((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&questFlags, 1);
    }
    if (flags & 0x80000000)
    {
        unsigned char p = 0;  // Number of saved stages.
        unsigned char* j = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&p, 1);
        QuestSaveStageNode* h = ((::QuestSaveStageNode *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));  // Stage iterator.
        while (h)
        {
            QuestSaveStage* stage = ((::QuestSaveStage *)((void *)(h)));
            if (stage)
            {
                unsigned char eb = ((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>((stage))->FUN_009373f0()));  // Stage index.
                bool f = reinterpret_cast<::FUN_005dc960_shell *>((stage))->FUN_005dc960();            // Stage completion flag.
                reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&eb, 1);
                reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&f, 1);
                unsigned char q = 0;  // Number of saved stage items.
                unsigned char* cf = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
                reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&q, 1);
                QuestSaveItemNode* s = ((::QuestSaveItemNode *)(reinterpret_cast<::BaseProcess *>((stage))->GetCurrentProcessData()));  // Stage-item iterator.
                while (s)
                {
                    QuestSaveItem* item = ((::QuestSaveItem *)((void *)(s)));
                    if (item)
                    {
                        unsigned char j = ((unsigned char)(::FUN_005dc980((const char *)(item))));  // Stage-item index.
                        Date* p = ((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((item))->GetBaseTexture()));          // Log date, if present.
                        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&j, 1);
                        if (p)
                        {
                            reinterpret_cast<::FUN_008579b0_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(p, 4);
                        }
                        else
                        {
                            Date emptyDate;
                            reinterpret_cast<::FUN_008579b0_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&emptyDate, 4);
                        }
                        ++q;
                    }
                    s = ((::QuestSaveItemNode *)(reinterpret_cast<::Callees *>((s))->FUN_00726070()));
                }
                *cf = q;
                ++p;
            }
            h = ((::QuestSaveStageNode *)(reinterpret_cast<::Callees *>((h))->FUN_00726070()));
        }
        *j = p;
    }
    if (flags & 0x40000000)
        reinterpret_cast<::ThisX *>((((QuestSaveLocals*)m_pScriptLocals)))->WriteScriptLocals();
    if ((*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011de4e8)).Bool()->b)
    {
        unsigned char* end = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        SaveFormInfo* formInfo = ((::SaveFormInfo *)(reinterpret_cast<::EffectSetting *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->GetHitSound()));
        if (formInfo)
        {
            TESForm* form = ::FUN_004839c0(formInfo->formID);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned char* h = ((unsigned char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((QuestSaveManager*)(*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        unsigned char* j = p;  // Beginning of the saved block.
        if (h > j + 65535)
            ::FUN_005b5e40();
        *(unsigned short*)p = (unsigned short)(h - j);
    }
}

extern "C" char UNK_0104ad80[];
extern "C" char UNK_0104adc0[];
struct StreamReader
{
};
struct QuestInput
{
};
struct StageSave
{
};
struct StageEntry
{
};
struct SavedDate
{
    unsigned int value;
    void FUN_007b3fa0(unsigned int);
};
struct LogValue
{
    short low, high;
    LogValue();
    ~LogValue();
};
void FUN_00483710(LogValue*);
struct LocalsState
{
    void* FUN_0041af70(unsigned int);
};
typedef unsigned int(* TagMethod)(void*);
struct QuestLoader : TESQuest
{
    void LoadQuestData(unsigned int flags, unsigned int extra);
};
// Reads quest data from the stream: enabled flag, stages with dates, script locals, and logs size mismatches.
// @fnv 0x0060e0d0
void QuestLoader::LoadQuestData(unsigned int flags, unsigned int extra)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>((((QuestInput*)this)))->FUN_00484c50(flags, extra);
    unsigned short sizeRead = 0;
    unsigned int start = 0;
    if (reinterpret_cast<::FUN_00862110_cls *>((((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned int tag;
        reinterpret_cast<::FUN_008579e0_shell *>((((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&tag, 4);
        if (tag != 0x424c4f4b)
        {
            void* entry = ((void *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))));
            if (entry)
            {
                void* view = ((void *)(::FUN_004839c0((unsigned int)(*(void**)entry))));
                ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_01015718)), UNK_0104ad80, 0xfaf, *(void**)entry, ((TagMethod*)*(void**)view)[76](view),
                             *(unsigned char*)((char*)entry + 9), *(unsigned int*)((char*)entry + 5));
            }
            else
            {
                ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_010156a8)), UNK_0104ad80, 0xfaf, ((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008df040());
            }
        }
        start = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579e0_shell *>((((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&sizeRead, 2);
    }
    if (flags & 2)
    {
        unsigned char enabled;
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((QuestInput*)this)))->FUN_00484d00(&enabled, 1);
        *((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>((((QuestInput*)this)))->GetField())) = enabled;
    }
    if (flags & 0x80000000)
    {
        unsigned char stageCount;
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((QuestInput*)this)))->FUN_00484d00(&stageCount, 1);
        for (int i = 0; i < stageCount; ++i)
        {
            unsigned char stageId;
            unsigned char isComplete;
            reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((QuestInput*)this)))->FUN_00484d00(&stageId, 1);
            reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((QuestInput*)this)))->FUN_00484d00(&isComplete, 1);
            StageSave* questStage = (StageSave*)((void *)(reinterpret_cast<::TESQuest *>((((QuestInput*)this)))->GetStage(stageId)));
            if (questStage)
            {
                reinterpret_cast<::FUN_0067fdb0_shell *>((questStage))->FUN_0067fdb0(isComplete);
            }
            else
            {
                ::FUN_005b5e40();
            }
            {
                unsigned char itemCount;
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((QuestInput*)this)))->FUN_00484d00(&itemCount, 1);
                for (int j = 0; j < itemCount; ++j)
                {
                    Date dateValue;
                    {
                        unsigned char itemId;
                        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((QuestInput*)this)))->FUN_00484d00(&itemId, 1);
                        reinterpret_cast<::FUN_008579e0_shell *>((((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&dateValue, 4);
                        if (questStage)
                        {
                            StageEntry* item = (StageEntry*)((void *)(reinterpret_cast<::fnv_0060f2c0::FUN_0060f2c0_shell *>((questStage))->FindItemByDoneFlag(itemId)));
                            if (item)
                            {

                                if (reinterpret_cast<::FUN_004b1030_Class *>((((LogValue*)&dateValue)))->FUN_004b1030() == 0 &&
                                    ((unsigned short)(reinterpret_cast<::FUN_004b1050Class *>((((LogValue*)&dateValue)))->FUN_004b1050())) == 0)
                                {
                                    SavedDate* pOldDate = (SavedDate*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((item))->GetBaseTexture()));
                                    if (pOldDate)
                                    {
                                        delete (Date*)pOldDate;
                                        reinterpret_cast<::MiddleHighProcess *>((item))->SetFaceAnimationData((::TargetDoorController *)(void *)(0));
                                    }
                                }
                                else
                                {
                                    SavedDate* pOldDate = (SavedDate*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((item))->GetBaseTexture()));
                                    if (pOldDate)
                                    {
                                        reinterpret_cast<::FUN_004b1000_shell *>((pOldDate))->CopyShortPair((const short *)(const ::Date *)(&dateValue));
                                    }
                                    else
                                    {
                                        pOldDate = (SavedDate*)new Date(dateValue);
                                        reinterpret_cast<::MiddleHighProcess *>((item))->SetFaceAnimationData((::TargetDoorController *)(pOldDate));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        this->m_ucEnabled = 0;
        reinterpret_cast<::TESQuest *>((((QuestInput*)this)))->UpdateStageMask();
    }
    if (flags & 0x40000000)
    {
        if (!this->m_pScriptLocals)
        {
            ScriptLocals* replacement = new ScriptLocals;
            {
                reinterpret_cast<::LoadScriptLocals *>((((LocalsState*)replacement)))->FUN_005a9950();
                delete replacement;
                reinterpret_cast<::FUN_0060e680_shell *>((((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->SetFlags(0x40000000);
            }
        }
        else
        {
            reinterpret_cast<::LoadScriptLocals *>((((LocalsState*)this->m_pScriptLocals)))->FUN_005a9950();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>((((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        void* entry;
        {
            unsigned int actual = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
            entry = ((void *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))));
            if (entry)
            {
                void* view = ((void *)(::FUN_004839c0((unsigned int)(*(void**)entry))));
                if (actual > start + sizeRead)
                    ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_01015588)), actual - (start + sizeRead), UNK_0104ad80, 0x1010, *(void**)entry,
                                 ((TagMethod*)*(void**)view)[76](view), *(unsigned char*)((char*)entry + 9),
                                 *(unsigned int*)((char*)entry + 5));
                else if (actual < start + sizeRead)
                    ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_01015500)), (start + sizeRead) - actual, UNK_0104ad80, 0x1010, *(void**)entry,
                                 ((TagMethod*)*(void**)view)[76](view), *(unsigned char*)((char*)entry + 9),
                                 *(unsigned int*)((char*)entry + 5));
            }
            else
            {
                if (actual > start + sizeRead)
                    ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_010154a0)), actual - (start + sizeRead), UNK_0104ad80, 0x1010,
                                 ((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008df040());
                else if (actual < start + sizeRead)
                    ::FUN_005b5e40((*reinterpret_cast<char (*)[]>(&::fnv_008d0bc0::DAT_01015440)), (start + sizeRead) - actual, UNK_0104ad80, 0x1010,
                                 ((StreamReader*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008df040());
            }
        }
    }
}

// WriteToBuffer - data round worker13 v06
struct F810Buf;
struct F810Flags
{
};
struct F810Item1;
struct F810Item2;
struct F810Item3;
struct F810Node2
{
    F810Item2* pItem;
    F810Node2* pNext;
};
struct F810Node3
{
    F810Item3* pItem;
    F810Node3* pNext;
};
struct F810Item1
{
};
struct F810Item2
{
};
struct F810Item3
{
};
struct F810Node1
{
    F810Item1* pItem;
    F810Node1* pNext;
};
struct F810Obj
{
};
struct F810Buf
{
    F810Flags* FUN_00428110(void* out, unsigned int tag);
};
struct FUN_0060e810_shell
{
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned char cFlag3c;
    unsigned char r3d;
    unsigned char r3e;
    unsigned char r3f;
    unsigned int iVal40;
    F810Node1 list44;
    F810Node3 list4c;
    unsigned int f54;
    unsigned int f58;
    F810Obj* pObj5c;
    void WriteToBuffer(F810Buf* buf);
};

// Serializes cFlag3c, iVal40, the list44 and list4c lists and pObj5c into buf, each guarded by a tag check, writing counts via FUN_00865ff0.
// @fnv 0x0060e810
void FUN_0060e810_shell::WriteToBuffer(F810Buf* buf)
{
    unsigned int flagsE;
    unsigned int tagD;
    unsigned int flags2;
    unsigned int flag2;
    unsigned int flag;
    F810Node3* next0;
    void* valY;
    F810Item3* entry;
    int iterY;
    F810Node3* head1;
    unsigned int cntY;
    unsigned char gotB;
    unsigned char opts;
    void* val1;
    F810Item2* item2;
    F810Node2* listD;
    unsigned int cntA;
    int idxD;
    unsigned char rawD;
    unsigned char flg;
    F810Item1* itemD;
    F810Node1* nodeC;
    unsigned int cnt1;
    int idx0;
    reinterpret_cast<::FakeForm *>(this)->SaveIfChanged((::BGSSaveFormBuffer *)(buf));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((buf->FUN_00428110(&flag, 2)))->FUN_004280f0({}))
    {
        reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50(&cFlag3c, 1, 0);
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((buf->FUN_00428110(&flag2, 4)))->FUN_004280f0({}))
    {
        reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50(&iVal40, 4, 0);
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((buf->FUN_00428110(&flags2, 0x80000000)))->FUN_004280f0({}))
    {
        idx0 = 0;
        cnt1 = reinterpret_cast<::FUN_00865f20_shell *>((buf))->FUN_00865f20();
        nodeC = &list44;
        while (nodeC != 0)
        {
            itemD = *((::F810Item1 **)((void *)(nodeC)));
            if (itemD != 0)
            {
                rawD = ((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>((itemD))->FUN_009373f0()));
                flg = reinterpret_cast<::FUN_005dc960_shell *>((itemD))->FUN_005dc960();
                reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50(&rawD, 1, 0);
                reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50(&flg, 1, 0);
                idxD = 0;
                cntA = reinterpret_cast<::FUN_00865f20_shell *>((buf))->FUN_00865f20();
                listD = ((::F810Node2 *)(reinterpret_cast<::BaseProcess *>((itemD))->GetCurrentProcessData()));
                while (listD != 0)
                {
                    item2 = *((::F810Item2 **)((void *)(listD)));
                    if (item2 != 0)
                    {
                        opts = ((bool)(::FUN_005dc980((const char *)(item2))));
                        val1 = ((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((item2))->GetBaseTexture()));
                        gotB = (val1 != 0);
                        reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50(&opts, 1, 0);
                        reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50(&gotB, 1, 0);
                        if (gotB)
                        {
                            reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50(val1, 4, 0);
                        }
                        idxD++;
                    }
                    listD = ((::F810Node2 *)(reinterpret_cast<::Callees *>((listD))->FUN_00726070()));
                }
                reinterpret_cast<::FUN_00865ff0_shell *>((buf))->FUN_00865ff0(idxD, cntA);
                idx0++;
            }
            nodeC = ((::F810Node1 *)(reinterpret_cast<::Callees *>((nodeC))->FUN_00726070()));
        }
        reinterpret_cast<::FUN_00865ff0_shell *>((buf))->FUN_00865ff0(idx0, cnt1);
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((buf->FUN_00428110(&tagD, 0x40000000)))->FUN_004280f0({}))
    {
        reinterpret_cast<::SaveLocals9db0 *>((pObj5c))->FUN_005a9db0((::BGSSaveFormBuffer *)(buf));
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((buf->FUN_00428110(&flagsE, 0x20000000)))->FUN_004280f0({}))
    {
        iterY = 0;
        cntY = reinterpret_cast<::FUN_00865f20_shell *>((buf))->FUN_00865f20();
        head1 = &list4c;
        while (head1 != 0)
        {
            entry = *((::F810Item3 **)((void *)(head1)));
            if (entry != 0)
            {
                valY = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((entry))->FUN_007af430()));
                if (valY != 0)
                {
                    next0 = ((::F810Node3 *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070()));
                    reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50(&next0, 4, 0);
                    reinterpret_cast<::FUN_00865e50_shell *>((buf))->FUN_00865e50(&valY, 4, 0);
                    iterY++;
                }
            }
            head1 = ((::F810Node3 *)(reinterpret_cast<::Callees *>((head1))->FUN_00726070()));
        }
        reinterpret_cast<::FUN_00865ff0_shell *>((buf))->FUN_00865ff0(iterY, cntY);
    }
}

struct ScriptX
{
};
struct ScriptableBase
{
    virtual void f0();
    ScriptX* m_pFormScript;
    bool m_bHasScript;
    unsigned char layoutPadding[3];
};
struct IconBase
{
    virtual void f0();
    void* p;
    unsigned int n;
};
struct NameBase
{
    virtual void f0();
    void* p;
    unsigned int n;
};
struct StageItem
{
};
struct SItemNode
{
};
struct Stage
{
};
struct StageNode
{
};
struct ObjItem
{
};
struct ObjNode
{
};
struct QuestShell : TESForm, ScriptableBase, IconBase, NameBase
{
    FUN_0060c5c0 data;
    SL m_kStageList;
    SL m_kObjectives;
    CondS m_kInfoConditions;
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    StrMem strEditorID;
    void FUN_0060d720();
};

// @fnv 0x0060d720
void QuestShell::FUN_0060d720()
{
    StageNode* aStageNode;
    ObjNode* objNode;
    Stage* stage;
    {
        SItemNode* itemNode;
        Date* logDate3;
        StageItem* stageItemA;

        aStageNode = ((::StageNode *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
        while (aStageNode)
        {
            stage = *((::Stage **)((void *)(aStageNode)));
            if (stage)
            {
                reinterpret_cast<::FUN_0067fdb0_shell *>((stage))->FUN_0067fdb0(false);
                itemNode = ((::SItemNode *)(reinterpret_cast<::BaseProcess *>((stage))->GetCurrentProcessData()));
                while (itemNode)
                {
                    stageItemA = *((::StageItem **)((void *)(itemNode)));
                    logDate3 = stageItemA ? ((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((stageItemA))->GetBaseTexture())) : 0;
                    if (logDate3)
                    {
                        reinterpret_cast<::MiddleHighProcess *>((stageItemA))->SetFaceAnimationData((::TargetDoorController *)(::Date *)(0));
                        delete logDate3;
                    }
                    itemNode = ((::SItemNode *)(reinterpret_cast<::Callees *>((itemNode))->FUN_00726070()));
                }
            }
            aStageNode = ((::StageNode *)(reinterpret_cast<::Callees *>((aStageNode))->FUN_00726070()));
        }
    }

    m_ucEnabled = 0;

    objNode = ((::ObjNode *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (objNode && *((::ObjItem **)((void *)(objNode))))
    {
        reinterpret_cast<::fnv_005ec5d0::FUN_005ec5d0_shell *>(((*((::ObjItem **)((void *)(objNode))))))->FUN_005ec5d0((::fnv_005ec5d0::QUEST_OBJECTIVE_STATE)(0));
        objNode = ((::ObjNode *)(reinterpret_cast<::Callees *>((objNode))->FUN_00726070()));
    }

    if (m_pScriptLocals)
    {
        delete m_pScriptLocals;
        m_pScriptLocals = reinterpret_cast<::FUN_005abf60_shell *>((((::ScriptX *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->FUN_005abf60();
    }

    ::FUN_00619b60((int)(this));
    reinterpret_cast<::TESQuest *>(this)->SetEnabled(reinterpret_cast<::FUN_0060d8d0_shell *>(this)->HasFlag0x10());
    reinterpret_cast<::FUN_0060ca30_shell *>(this)->FUN_0060ca30(false);
    reinterpret_cast<::FUN_0060caf0_shell *>(this)->FUN_0060caf0(false);
    reinterpret_cast<::FUN_005ec700_shell *>(this)->SetFlag20(false);
}

#include "generated/data/fallout_shared/tesquest.inc"
