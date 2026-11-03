// fallout_shared/testopicinfo.cpp: TESTopicInfo, DelStandIn, TopicLinkLists, TopicInfoCompare and more (52 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSTempEffectDebris.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401280_Class.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00484150_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_00619b20_shell.h"
#include "fnv/decl/FUN_00619c50_shell.h"
#include "fnv/decl/FUN_00619d00_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009527b0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Scr.h"
#include "fnv/decl/TESFormSortProxy.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00484730__FUN_00484730_shell.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b1000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011de000.h"
#include "testopicinfo_topicinfo_helpers.h"
#include "testopicinfo_topicinfo_TESTopicInfo.h"
#include "testopicinfo_topicinfo_forms.h"
#include "TESFile.h"
#include "testopicinfo_topicinfo_TESTopic.h"
#include "testopicinfo_topicinfo_TESConversationData.h"
#include "Script.h"
#include "ScriptVariableInfo.h"
#include "ScriptReferencedObject.h"
#include "ScriptHeaderData.h"
#include "testopicinfo_topicinfo_ResponseListWrapper.h"
#include "testopicinfo_topicinfo_TESResponse.h"
#include "game_constants.h"
#include "original_script.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>

extern TESTopicInfo* g_cachedResultScriptInfo;
extern Script g_resultScripts[2];
extern ScriptVariableInfo* g_loadedScriptVariable;
extern TESTopicInfo* g_cachedResponseInfo;
extern const char g_topicInfoLoadWarning[];

// Removes every entry from the add-topic list returned by GetAddTopicList until the list is empty.
// @fnv 0x0061d250
void TESTopicInfo::ResetResponseList()
{
    BSSimpleList<TESTopic*>* topics = GetAddTopicList();
    while (topics && !topics->IsEmpty())
        topics->RemoveHead();
}

// @fnv 0x0061d230
void TESTopicInfo::ClearResponses()
{
    (*reinterpret_cast<::TESResponseList *>(&::g_011cc07c)).ClearResponses();
}

// @fnv 0x0061cff0
void TESTopicInfo::ClearData()
{
    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0())
    {
        if (reinterpret_cast<::FUN_00619a70_shell *>(this)->FUN_00619a70() != kInvalidTopicInfoIndex)
        {
            TESTopic* owner = ::fnv_0061a310::FindTopicByInfo(this);
            if (owner)
                SetOwnerTopic(owner);
        }
        reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()->InitializeConditionItems();
        ClearResponses();
        ResetResponseList();
        Script emptyScript;
        reinterpret_cast<::FUN_005aa420_shell *>(&(g_resultScripts[0]))->CopyFromScript(&emptyScript);
        reinterpret_cast<::FUN_005aa420_shell *>(&(g_resultScripts[1]))->CopyFromScript(&emptyScript);
    }
    g_cachedResponseInfo = 0;
    g_cachedResultScriptInfo = 0;
    if (m_pResponseData)
        delete m_pResponseData;
}

// @fnv 0x0061d140
void TESTopicInfo::SetOwnerTopic(TESTopic* owner)
{
    if (owner && reinterpret_cast<::FUN_00619a70_shell *>(this)->FUN_00619a70() != kInvalidTopicInfoIndex)
    {
        QuestDialogueInfo* questInfo = ((::QuestDialogueInfo *)(reinterpret_cast<::FUN_00619c50_shell *>((owner))->FindTopicByInfoID((unsigned int)(this))));
        if (questInfo)
        {
            TopicInfoArray* infoArray = ((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()));
            int iCount;
            if (infoArray->GetAt(reinterpret_cast<::FUN_00619a70_shell *>(this)->FUN_00619a70()) == this)
                infoArray->RemoveAt(reinterpret_cast<::FUN_00619a70_shell *>(this)->FUN_00619a70());
            else
            {
                bool bFound = false;
                iCount = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((infoArray))->FUN_0084e3a0()));
                for (int index = 0; index < iCount; index++)
                {
                    if (infoArray->GetAt(index) == this)
                    {
                        infoArray->RemoveAt(index);
                        bFound = true;
                        break;
                    }
                }
            }
            infoArray->Compact();
            ::FUN_00619fe0(infoArray);
        }
    }
}

// @fnv 0x0061db30
void TESTopicInfo::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::TESForm *>(this)->LoadGame(buffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags()))->FUN_004280f0(0x80000000))
        m_bGoodbye = true;
}

// @fnv 0x0061db80
void TESTopicInfo::Revert(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0((unsigned int)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetOldChangeFlags()))->FUN_004280f0(0x80000000))
        m_bGoodbye = false;
}

// @fnv 0x0061f150
void TESTopicInfo::AddTopicList()
{
    reinterpret_cast<::FUN_009527b0_Class *>((::_g_thePlayer))->AddTopics((::FUN_00952b30_BSSimpleList *)(::BSSimpleList< ::TESTopic *> *)(GetAddTopicList()));
}

struct FUN_00409480_shell : public TESTopicInfo
{
    void FUN_00409480(TESActorBase*);
};

// @fnv 0x00409480
void FUN_00409480_shell::FUN_00409480(TESActorBase* apActor)
{
    this->m_pDialogueSpeaker = apActor;
}

struct FUN_00508d70_shell : public TESForm
{
    bool FUN_00508d70();
};
// @fnv 0x0061eb60
Script* TESTopicInfo::GetResultScript(unsigned int onEnd)
{
    unsigned int resultIndex = onEnd;
    if (this == g_cachedResultScriptInfo)
        return &g_resultScripts[resultIndex];
    g_cachedResultScriptInfo = this;
    Script emptyScript;
    reinterpret_cast<::FUN_005aa420_shell *>(&(g_resultScripts[0]))->CopyFromScript(&emptyScript);
    g_resultScripts[0].NotifySaveLoadGameOfFormChange();
    ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(g_resultScripts[0]))->GetConditions()))->m_bQuest = false;
    reinterpret_cast<::FUN_005aa420_shell *>(&(g_resultScripts[1]))->CopyFromScript(&emptyScript);
    g_resultScripts[1].NotifySaveLoadGameOfFormChange();
    ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(g_resultScripts[1]))->GetConditions()))->m_bQuest = false;
    if (!reinterpret_cast<::FUN_00508d70_shell *>(this)->FUN_00508d70())
        return &g_resultScripts[resultIndex];
    g_resultScripts[0].SetInitializationState(false);
    g_resultScripts[1].SetInitializationState(false);
    TESFile* file = GetFile(-1);
    if (!file || !m_ulTopicFlags)
        return &g_resultScripts[resultIndex];
    file = file->GetParentTESFile();
    if (!reinterpret_cast<::TESOffsetWorker *>((file))->FUN_004723a0(m_ulTopicFlags))
        return &g_resultScripts[resultIndex];
    unsigned char form = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (form != kTopicInfoFormType)
        return &g_resultScripts[resultIndex];
    unsigned int scriptIndex = 0;
    int chunk;
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case kNextScriptChunk:
            scriptIndex++;
            break;
        case kScriptVariableDataChunk:
        case kScriptVariableNameChunk:
            if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == kScriptVariableDataChunk)
            {
                g_loadedScriptVariable = new ScriptVariableInfo;
                g_loadedScriptVariable->Load(file);
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(&(g_resultScripts[scriptIndex]))->FUN_005d43e0()))))->FUN_00905820((void *)&(g_loadedScriptVariable));
            }
            else if (g_loadedScriptVariable)
            {
                char* variableName = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(variableName), kScriptVariableNameReadSize);
                reinterpret_cast<::TextString *>(&(g_loadedScriptVariable->m_kName))->FUN_004037f0(variableName, 0);
            }
            break;
        case kScriptHeaderChunk:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(g_resultScripts[scriptIndex]))->GetConditions()))), 0);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00414220_shell *>((((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(g_resultScripts[scriptIndex]))->GetConditions()))))->FUN_00414220();
            break;
        case kScriptCompiledDataChunk: {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            char* data = static_cast<char*>(_alloca(size));
            memset(data, 0, size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(data), 0);
            reinterpret_cast<::FUN_005aae70_shell *>(&(g_resultScripts[scriptIndex]))->FUN_005aae70(size, data);
            break;
        }
        case kScriptFormReferenceChunk: {
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            unsigned int formID;
            file->GetChunkData(&formID);
            reference->pForm = reinterpret_cast<TESForm*>(formID);
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(&(g_resultScripts[scriptIndex]))->FUN_005d43c0()))))->FUN_00905820((void *)&(reference));
            break;
        }
        case kScriptVariableReferenceChunk: {
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            unsigned int variableID;
            file->GetChunkData(&variableID);
            reference->m_uiFormID = variableID;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(&(g_resultScripts[scriptIndex]))->FUN_005d43c0()))))->FUN_00905820((void *)&(reference));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    reinterpret_cast<::Scr *>(&(g_resultScripts[0]))->FUN_005ab400(this);
    reinterpret_cast<::Scr *>(&(g_resultScripts[1]))->FUN_005ab400(this);
    return &g_resultScripts[resultIndex];
}

// @fnv 0x00508d70
bool FUN_00508d70_shell::FUN_00508d70()
{
    return (m_uiFormFlags & 0x2000) ? true : false;
}


struct FUN_0061c190
{
    BSSimpleList<int> m_kLinkFromList;
    BSSimpleList<int> m_kLinkToList;
    BSSimpleList<int> m_kFollowUpInfoList;

    ~FUN_0061c190();
};

struct FUN_0061cc60_node
{
};
struct FUN_0061cc60_holder
{
    FUN_0061cc60_node* head;
    void AddNode(int a);
};
struct RecursiveSpinLock
{
    int x[2];
    RecursiveSpinLock();
    ~RecursiveSpinLock();
};
struct FUN_0061ce40_holder
{
    RecursiveSpinLock a;
    RecursiveSpinLock b;
    RecursiveSpinLock c;
    FUN_0061ce40_holder();
};
// @fnv 0x0061ce40
FUN_0061ce40_holder::FUN_0061ce40_holder()
{}

struct FUN_0061cfd0_shell : public TESTopicInfo
{
    void FUN_0061cfd0(char*);
};
// @fnv 0x0061dbd0
bool TESTopicInfo::LoadForm(TESFile* file)
{
    unsigned int previousInfoID;
    int responseCount;
    {
        unsigned char m_ucFormType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
        if (m_ucFormType != kTopicInfoFormType)
            return false;
        if (!file->GetOptimizedFile())
            m_ulTopicFlags = file->GetOffset();
        previousInfoID = kNoPreviousTopicInfo;
        struct TopicRecord
        {
            int chunk;
            unsigned int uiChunkType;
        } record;
        record.uiChunkType = 0;
        reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
        responseCount = 0;
        while (record.chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
        {
            switch (record.chunk)
            {
            case kConditionDataChunk:
                reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()->Load(file);
                break;
            case kPreviousTopicInfoChunk:
                file->GetChunkData(&previousInfoID);
                if (previousInfoID)
                    ::ResolveFormID((unsigned int *)&(previousInfoID), file);
                break;
            case kTopicInfoDataChunk:
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_Data), sizeof(m_Data));
                if (m_Data.type >= DIALOGUE_TYPE_DIALOGUE_TYPE_COUNT)
                    MarkForDeletion(true);
                if (m_Data.type == DIALOGUE_TYPE_DT_CONVERSATION)
                    SetTopicInfoData(0);
                break;
            case kAdditionalTopicChunk: {
                unsigned int topicID = 0;
                file->GetChunkData(&topicID);
                reinterpret_cast<::Callees *>((GetAddTopicList()))->FUN_00905820((void *)&(const ::TESTopic *const &)(reinterpret_cast<TESTopic*>(topicID)));
                break;
            }
            case kTopicInfoQuestChunk:
                file->GetChunkData(&record.uiChunkType);
                ::ResolveFormID((unsigned int *)&(record.uiChunkType), file);
                break;
            case kConversationLinkToChunk: {
                if (!((::TESTopicInfoData *)(::GetField38((char *)this))))
                    SetTopicInfoData(0);
                unsigned int topicID = 0;
                file->GetChunkData(&topicID);
                reinterpret_cast<::Callees *>((((::TESTopicInfoData *)(::GetField38((char *)this)))->GetLinkToList()))->FUN_00905820((void *)&(const ::TESTopic *const &)(reinterpret_cast<TESTopic*>(topicID)));
                break;
            }
            case kConversationLinkFromChunk: {
                if (!((::TESTopicInfoData *)(::GetField38((char *)this))))
                    SetTopicInfoData(0);
                unsigned int topicID = 0;
                file->GetChunkData(&topicID);
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::TESTopic *> *)(new ((void *)(((::TESTopicInfoData *)(::GetField38((char *)this))))) ::Vec3()))))->FUN_00905820((void *)&(const ::TESTopic *const &)(reinterpret_cast<TESTopic*>(topicID)));
                break;
            }
            case kConversationFollowUpChunk: {
                if (!((::TESTopicInfoData *)(::GetField38((char *)this))))
                    SetTopicInfoData(0);
                unsigned int infoID = 0;
                file->GetChunkData(&infoID);
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::TESTopicInfo *> *)(::FUN_00460140((int)(((::TESTopicInfoData *)(::GetField38((char *)this)))))))))->FUN_00905820((void *)&(const ::TESTopicInfo *const &)(reinterpret_cast<TESTopicInfo*>(infoID)));
                break;
            }
            case kTopicInfoPromptChunk: {
                char prompt[kTopicInfoPromptReadSize];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(prompt), sizeof(prompt));
                reinterpret_cast<::FUN_0061cfd0_shell *>(this)->FUN_0061cfd0((char *)(prompt));
                break;
            }
            case kTopicInfoPerkSkillChunk: {
                unsigned int formID = 0;
                file->GetChunkData(&formID);
                m_pPerkSkillStat = reinterpret_cast<TESForm*>(formID);
                break;
            }
            case kTopicInfoSpeakerChunk: {
                unsigned int speakerID = 0;
                file->GetChunkData(&speakerID);
                m_pDialogueSpeaker = reinterpret_cast<TESActorBase*>(speakerID);
                break;
            }
            case kTopicInfoDifficultyChunk: {
                unsigned int difficulty;
                file->GetChunkData(&difficulty);
                if (difficulty < SPEECH_CHALLENGE_LEVEL_SCL_COUNT)
                    reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((*(::TESObjectREFR * *)&(const ::SPEECH_CHALLENGE_LEVEL &)(static_cast<SPEECH_CHALLENGE_LEVEL>(difficulty))));
                if (m_eDifficultyLevel == SPEECH_CHALLENGE_LEVEL_SCL_NONE)
                    m_eDifficultyLevel = SPEECH_CHALLENGE_LEVEL_SCL_VERYEASY;
                break;
            }
            }
            if (!file->NextChunk())
                break;
        }
        if (m_Data.type == DIALOGUE_TYPE_DT_PERSUASION)
            m_Data.type = DIALOGUE_TYPE_DT_TOPIC;
        if (!reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
        {
            if (!reinterpret_cast<::TopicMethods *>((g_loadingTopic))->AddTopicInfo(reinterpret_cast<TESQuest*>(record.uiChunkType), this, previousInfoID))
                ::FUN_005b5e40();
        }
        return true;
    }
}
// Clears m_Data and the topic-info fields, sets the form type, prompt, speaker, actor value, perk and difficulty level to defaults.
// @fnv 0x0061cf40
void TESTopicInfo::InitializeComponent()
{
    memset(&m_Data, 0, sizeof(m_Data));
    m_ulTopicFlags = 0;
    m_bGoodbye = false;
    m_uiInfoIndex = kInvalidTopicInfoIndex;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(kTopicInfoFormType))));
    m_pResponseData = 0;
    m_pOwnerQuest = 0;
    reinterpret_cast<::FUN_0061cfd0_shell *>(this)->FUN_0061cfd0((char *)(::DAT_01011584));
    reinterpret_cast<::FUN_00409480_shell *>(this)->FUN_00409480(0);
    reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(::ActorValueInfo *)(0));
    reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(::BGSPerk *)(0));
    reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((*(::TESObjectREFR * *)&(const ::SPEECH_CHALLENGE_LEVEL &)(SPEECH_CHALLENGE_LEVEL_SCL_VERYEASY)));
}

// @fnv 0x0061cfd0
void FUN_0061cfd0_shell::FUN_0061cfd0(char* apPrompt)
{
    reinterpret_cast<::TextString *>((&this->m_kPrompt))->FUN_004037f0(apPrompt, 0);
}

// Reads the flags byte at offset 0x26 and returns 1 if bit 0x10 is set, 3 if bit 0x20 is set, otherwise 2.
// @fnv 0x0061e720
int FUN_0061e720(const char* pThis)
{
    return (pThis[0x26] & 0x10) ? 1 : ((pThis[0x26] & 0x20) ? 3 : 2);
}

struct FUN_0061e760_shell : public TESTopicInfo
{
    TESResponseList* FUN_0061e760(TESResponseList* list);
};

// @fnv 0x0061e760
TESResponseList* FUN_0061e760_shell::FUN_0061e760(TESResponseList* list)
{
    return DuplicateResponseList(list);
}

struct FUN_0061eb40_shell : public TESResponse
{
    void FUN_0061eb40(char*);
};

// @fnv 0x0061eb40
void FUN_0061eb40_shell::FUN_0061eb40(char* apResponseText)
{
    reinterpret_cast<::TextString *>((&this->m_kResponseText))->FUN_004037f0(apResponseText, 0);
}

struct FUN_0061f260_shell : public TESTopicInfo
{
    bool FUN_0061f260();
};

// @fnv 0x0061f260
bool FUN_0061f260_shell::FUN_0061f260()
{
    return (bool)(this->m_Data.flags & 0x10);
}

struct FUN_0061f340_shell : public TESTopicInfo
{
    void FUN_0061f340(unsigned short);
};

// @fnv 0x0061f340
void FUN_0061f340_shell::FUN_0061f340(unsigned short usIndex)
{
    this->m_uiInfoIndex = usIndex;
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* DestroyAndFree_0061cb30(unsigned int flags);
};
// Runs the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x0061cb30
void* DelStandIn::DestroyAndFree_0061cb30(unsigned int flags)
{
    reinterpret_cast<::TESResponse *>((((DtorStandIn*)this)))->TESResponse::~TESResponse();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

namespace fnv_0061d110 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* DestroyAndDeallocate(unsigned int flags);
};
// Calls the destructor on this object, then deallocates it when bit 0 of flags is set, and returns this.
// @fnv 0x0061d110
void* DelStandIn::DestroyAndDeallocate(unsigned int flags)
{
    reinterpret_cast<::FUN_0061c190 *>((((DtorStandIn*)this)))->FUN_0061c190::~FUN_0061c190();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_0061d110

struct List_009e03e0
{
};

struct FUN_0061c330_shell
{
    char pad0[8];
    List_009e03e0 m_list8;
    char pad16[8];
    List_009e03e0 m_list16;
    void RemoveAllLists();
};
// Destructor that calls RemoveAllLists on this object.
// @fnv 0x0061c190
FUN_0061c190::~FUN_0061c190()
{
    reinterpret_cast<::FUN_0061c330_shell *>((this))->RemoveAllLists();
}

// Calls RemoveAll on the list at offset 8, on this object's own list, and on the list at offset 0x10.
// @fnv 0x0061c330
void FUN_0061c330_shell::RemoveAllLists()
{
    reinterpret_cast<::FileMatchList *>(&(m_list8))->RemoveAll();
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)this)))->RemoveAll();
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)((char*)this + 0x10))))->RemoveAll();
}

struct FUN_0061cc40_shell
{
    void FUN_0061cc40(int askilllevel);
};

// @fnv 0x0061cc40
void FUN_0061cc40_shell::FUN_0061cc40(int askilllevel)
{
    reinterpret_cast<int*>(this)[10] = askilllevel;
}

struct FUN_0061cc90_shell : TESResponse
{
    void AppendResponse(TESResponse* a);
};
// If head is null, stores a as the head node; otherwise forwards a to head->AppendResponse.
// @fnv 0x0061cc60
void FUN_0061cc60_holder::AddNode(int pNode)
{
    if (head == 0)
    {
        head = (FUN_0061cc60_node*)pNode;
    }
    else
    {
        reinterpret_cast<::FUN_0061cc90_shell *>((head))->AppendResponse((::TESResponse *)(pNode));
    }
}

// Walks the response chain to its last node and links the given response onto the end of it.
// @fnv 0x0061cc90
void FUN_0061cc90_shell::AppendResponse(TESResponse* apResponse)
{
    TESResponse* next = this;
    while (((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((next))->FUN_0045cd60())) != 0)
    {
        next = ((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((next))->FUN_0045cd60()));
    }
    next->pNext = apResponse;
}

struct FUN_0061e5e0_shell
{
    char _pad[0x20];
    char _pad2[3];
    char m_kMemberDescriptor;
    char* GetFieldPtr();
};

// @fnv 0x0061e5e0
char* FUN_0061e5e0_shell::GetFieldPtr()
{
    return &m_kMemberDescriptor;
}

struct TESFormStub
{
};

struct FUN_0061dad0_shell
{
    void FUN_0061dad0(unsigned int aiFlags, unsigned int aiCurrentFlags);
};

// @fnv 0x0061dad0
void FUN_0061dad0_shell::FUN_0061dad0(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>((((TESFormStub*)this)))->FUN_00484c50(aiFlags, aiCurrentFlags);
    if (aiFlags & 0x80000000)
        ((unsigned char*)this)[0x22] = 1;
}

struct FUN_0061db00_shell : TESForm
{
    void Revert(unsigned int);
};

// Calls TESForm::Revert with the given buffer and, if the high bit of aiFlags is set, clears byte at offset 0x22.
// @fnv 0x0061db00
void FUN_0061db00_shell::Revert(unsigned int aiFlags)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0((unsigned int)((BGSLoadFormBuffer*)aiFlags));
    if (aiFlags & 0x80000000)
        ((char*)this)[0x22] = 0;
}

namespace ActorValue { enum Index; }
struct TESRecipe
{
public:
    void SetRequiredSkill(::ActorValue::Index);
};

struct FUN_006174d0_shell
{
    void CopyResponse(TESResponse* source);
};

struct FUN_0061cb60_shell : TESResponseList
{
    void FUN_0061cb60(TESResponse* head);
};
// Loads TESResponse records from the file's response chunk into list or g_topicInfoResponses, caching this as g_cachedResponseInfo when list is null.
// @fnv 0x0061e780
TESResponseList* TESTopicInfo::DuplicateResponseList(TESResponseList* pResponseList)
{
    unsigned char form;
    {
        struct ResponseRead
        {
            TESResponse* response;
            int chunk;
            TESFile* file;
        } responseReader;
        if (this == g_cachedResponseInfo)
        {
            if (pResponseList)
            {
                reinterpret_cast<::FUN_0061cb60_shell *>((pResponseList))->FUN_0061cb60(((::TESResponse *)(::FUN_00559450((int *)&((*reinterpret_cast<::TESResponseList *>(&::g_011cc07c)))))));
                return pResponseList;
            }
            else
                return &(*reinterpret_cast<::TESResponseList *>(&::g_011cc07c));
        }
        if (!pResponseList)
        {
            g_cachedResponseInfo = this;
            ClearResponses();
        }
        responseReader.file = GetFile(-1);
        if (!responseReader.file || !m_ulTopicFlags)
            return pResponseList ? pResponseList : &(*reinterpret_cast<::TESResponseList *>(&::g_011cc07c));
        responseReader.file = responseReader.file->GetParentTESFile();
        if (!reinterpret_cast<::TESOffsetWorker *>((responseReader.file))->FUN_004723a0(m_ulTopicFlags))
            return pResponseList ? pResponseList : &(*reinterpret_cast<::TESResponseList *>(&::g_011cc07c));
        form = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((responseReader.file))->FUN_00472660()));
        if (form != kTopicInfoFormType)
            return pResponseList ? pResponseList : &(*reinterpret_cast<::TESResponseList *>(&::g_011cc07c));
        responseReader.response = 0;
        while (responseReader.chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((responseReader.file))->FUN_004726b0())))
        {
            switch (responseReader.chunk)
            {
            case 0x54445254:  // TRDT reader.response data
                responseReader.response = new TESResponse;
                responseReader.response->Load(responseReader.file);
                responseReader.response->InitItem(this);
                if (pResponseList)
                    reinterpret_cast<::FUN_0061cc60_holder *>((pResponseList))->AddNode((int)(responseReader.response));
                else
                    reinterpret_cast<::FUN_0061cc60_holder *>(&((*reinterpret_cast<::TESResponseList *>(&::g_011cc07c))))->AddNode((int)(responseReader.response));
                break;
            case 0x314d414e:  // NAM1 reader.response text
                if (responseReader.response)
                {
                    unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((responseReader.file))->GetField25C();
                    char* text = static_cast<char*>(_alloca(size));
                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((responseReader.file))->FUN_00472890((char *)(text), size);
                    reinterpret_cast<::FUN_0061eb40_shell *>((responseReader.response))->FUN_0061eb40((char *)(text));
                }
                break;
            case 0x4d414e53:  // SNAM speaker idle
                if (responseReader.response)
                {
                    struct IdleReference
                    {
                        unsigned int formID;
                        TESForm* form;
                    } reference;
                    reference.formID = 0;
                    responseReader.file->GetChunkData(&reference.formID);
                    ::ResolveFormID((unsigned int *)&(reference.formID), responseReader.file);
                    TESIdleForm* idle = 0;
                    reference.form = ::FUN_004839c0(reference.formID);
                    if (reference.form && reference.form->GetFormType() == 72)
                        idle = static_cast<TESIdleForm*>(reference.form);
                    if (reference.formID && !idle)
                        ::FUN_005b5e40();
                    reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((responseReader.response))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(idle));
                }
                break;
            case 0x4d414e4c:  // LNAM listener idle
                if (responseReader.response)
                {
                    struct IdleReference
                    {
                        unsigned int formID;
                        TESForm* form;
                    } reference;
                    reference.formID = 0;
                    responseReader.file->GetChunkData(&reference.formID);
                    ::ResolveFormID((unsigned int *)&(reference.formID), responseReader.file);
                    TESIdleForm* idle = 0;
                    reference.form = ::FUN_004839c0(reference.formID);
                    if (reference.form && reference.form->GetFormType() == 72)
                        idle = static_cast<TESIdleForm*>(reference.form);
                    if (reference.formID && !idle)
                        ::FUN_005b5e40();
                    reinterpret_cast<::TESRecipe *>((responseReader.response))->SetRequiredSkill((::ActorValue::Index)(idle));
                }
                break;
            }
            if (!responseReader.file->NextChunk())
                break;
        }
        return pResponseList ? pResponseList : &(*reinterpret_cast<::TESResponseList *>(&::g_011cc07c));
    }
}

// @fnv 0x0061cb60
void FUN_0061cb60_shell::FUN_0061cb60(TESResponse* head)
{
    ClearResponses();
    TESResponse* previous = 0;
    while (head)
    {
        TESResponse* response = new TESResponse;
        ((FUN_006174d0_shell*)response)->CopyResponse(head);
        if (previous)
            reinterpret_cast<::FUN_0061cc40_shell *>((((TESRecipe*)previous)))->FUN_0061cc40((int)response);
        else
            reinterpret_cast<::FUN_0061cc60_holder *>(this)->AddNode((int)(response));
        previous = response;
        head = ((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((head))->FUN_0045cd60()));
    }
}

struct FUN_0061d6a0_shell : public TESTopicInfo
{
    void FUN_0061d6a0(bool set);
};

// @fnv 0x0061d6a0
void FUN_0061d6a0_shell::FUN_0061d6a0(bool set)
{
    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0() && set && reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
    {
        TESTopic* owner = ::fnv_0061a310::FindTopicByInfo(this);
        if (owner)
            owner->SetAltered(true);
    }
    reinterpret_cast<::fnv_00484730::FUN_00484730_shell *>(this)->FUN_00484730(set);
}

extern "C" void* _data_011c16bc;
struct FUN_00680a70_shell
{
    void CopyConditions(PerkEntryConditionSet* dst, PerkEntryConditionSet* src);
};
struct FUN_0061e0f0_shell : TESTopicInfo
{
    void FUN_0061e0f0(PerkEntryConditionSet* apCond);
};
// @fnv 0x0061e0f0
void FUN_0061e0f0_shell::FUN_0061e0f0(PerkEntryConditionSet* apCond)
{
    if (apCond)
        ((FUN_00680a70_shell*)((char*)this + 0x18))->CopyConditions(apCond, (PerkEntryConditionSet*)this);
    else
    {
        PerkEntryConditionSet temp;
        ((FUN_00680a70_shell*)((char*)this + 0x18))->CopyConditions(&temp, (PerkEntryConditionSet*)this);
    }
}

struct BSStr
{
};
struct BSStringT_char
{
    BSStringT_char& operator+=(const char*);
};
struct TESResponse_shell : TESResponse
{
};
struct FUN_0061e2b0_shell : TESTopicInfo
{
    void BuildResponseText(BSStringT<char>& text, bool firstOnly);
};
// @fnv 0x0061d290
void TESTopicInfo::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    TESFile* pFile = GetFile(-1);
    {
        BSSimpleList<TESTopic*>* previous = 0;
        TESResponse* pResponse;
        {
            BSSimpleList<TESTopic*>* pTopics = GetAddTopicList();
            while (pTopics && ((::TESTopic *)(new ((void *)(pTopics)) ::Vec3())))
            {
                unsigned int formID = reinterpret_cast<unsigned int>(((::TESTopic *)(new ((void *)(pTopics)) ::Vec3())));
                ::ResolveFormID((unsigned int *)&(formID), pFile);
                TESTopic* topic = dynamic_cast<TESTopic*>(::FUN_004839c0(formID));
                if (!topic)
                {
                    if (((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pTopics))->FUN_00726070())) || !previous)
                        pTopics->RemoveHead();
                    else
                    {
                        reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330((::InventoryStackRecord *const &)((const ::TESTopic *const &)(reinterpret_cast<TESTopic*>(formID))));
                        pTopics = ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
                    }
                    TESTopic* ownerTopic = ::fnv_0061a310::FindTopicByInfo(this);
                    TESQuest* ownerQuest = 0;
                    if (ownerTopic)
                        ownerQuest = reinterpret_cast<::FUN_00619d00_shell *>((ownerTopic))->FindQuestForTopicInfo(this);
                    {
                        BSStringT<char> text;
                        reinterpret_cast<::FUN_0061e2b0_shell *>(this)->BuildResponseText(text, true);
                        char description[260];
                        if (ownerTopic && ownerQuest)
                            sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                    ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())), ((const char *)(::FUN_00559450((int *)&(text)))), ownerQuest->GetEditorName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((ownerQuest))->FUN_0084e3a0())),
                                    ownerTopic->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((ownerTopic))->FUN_0084e3a0())));
                        else
                            sprintf(description, "TopicInfo %08X \"%s\"", ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())), ((const char *)(::FUN_00559450((int *)&(text)))));
                        ::FUN_005b5e40();
                    }
                }
                else
                {
                    pTopics->SetItem(topic);
                    previous = pTopics;
                    pTopics = ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pTopics))->FUN_00726070()));
                }
            }
            unsigned int speakerID = reinterpret_cast<unsigned int>(((::TESActorBase *)(reinterpret_cast<::Twin_00639b40 *>(this)->GetEntryPoint())));
            if (speakerID)
            {
                ::ResolveFormID((unsigned int *)&(speakerID), GetFile(-1));
                reinterpret_cast<::FUN_00409480_shell *>(this)->FUN_00409480(dynamic_cast<TESActorBase*>(::FUN_004839c0(speakerID)));
            }
            if (reinterpret_cast<::BGSCameraPath *>(this)->GetConditions())
                reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()->InitItem(this);
            if (((::TESTopicInfoData *)(::GetField38((char *)this))))
                ((::TESTopicInfoData *)(::GetField38((char *)this)))->InitItem(this);
            pResponse = ((::TESResponse *)(::FUN_00559450((int *)&((*reinterpret_cast<::TESResponseList *>(&::g_011cc07c))))));
            while (pResponse)
            {
                pResponse->InitItem(this);
                pResponse = ((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((pResponse))->FUN_0045cd60()));
            }
            if (m_pPerkSkillStat)
            {
                struct PerkSkillResolution
                {
                    unsigned int formID;
                    TESForm* form;
                    ActorValueInfo* actorValue;
                } resolved;
                resolved.formID = reinterpret_cast<unsigned int>(m_pPerkSkillStat);
                ::ResolveFormID((unsigned int *)&(resolved.formID), GetFile(-1));
                resolved.form = ::FUN_004839c0(resolved.formID);
                resolved.actorValue = dynamic_cast<ActorValueInfo*>(resolved.form);
                if (resolved.actorValue)
                    m_pPerkSkillStat = resolved.actorValue;
                else
                {
                    BGSPerk* perk = dynamic_cast<BGSPerk*>(resolved.form);
                    m_pPerkSkillStat = perk;
                }
            }
            SetInitializationState(true);
        }
    }
}
// @fnv 0x0061c360
void TESTopicInfoData::InitItem(TESForm* owner)
{
    BSSimpleList<TESTopic*>* pPreviousTopic = 0;
    BSSimpleList<TESTopic*>* pTopicList = GetLinkToList();
    TESFile* pFile = owner ? owner->GetFile(-1) : 0;
    {
        struct InfoCursor
        {
            BSSimpleList<TESTopicInfo*>* current;
            BSSimpleList<TESTopicInfo*>* previous;
        } infoCursor;

        while (pTopicList && ((::TESTopic *)(new ((void *)(pTopicList)) ::Vec3())))
        {
            struct TopicResolution
            {
                TESTopic* topic;
                unsigned int formID;
                TESForm* form;
            } resolved;
            resolved.formID = reinterpret_cast<unsigned int>(((::TESTopic *)(new ((void *)(pTopicList)) ::Vec3())));
            ::ResolveFormID((unsigned int *)&(resolved.formID), pFile);
            resolved.topic = 0;
            resolved.form = ::FUN_004839c0(resolved.formID);
            if (resolved.form && resolved.form->GetFormType() == ENUM_FORM_ID_DIAL_ID)
                resolved.topic = static_cast<TESTopic*>(resolved.form);

            if (!resolved.topic)
            {
                if (((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pTopicList))->FUN_00726070())) || !pPreviousTopic)
                    pTopicList->RemoveHead();
                else
                {
                    reinterpret_cast<::ItemChangeListNode *>((pPreviousTopic))->FUN_00905330((::InventoryStackRecord *const &)((const ::TESTopic *const &)(reinterpret_cast<TESTopic*>(resolved.formID))));
                    pTopicList = ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pPreviousTopic))->FUN_00726070()));
                }

                struct DiagnosticContext
                {
                    TESTopicInfo* info;
                    TESTopic* topic;
                    TESQuest* quest;
                } context;
                context.info = 0;
                if (owner && owner->GetFormType() == ENUM_FORM_ID_INFO_ID)
                    context.info = static_cast<TESTopicInfo*>(owner);
                context.topic = ::fnv_0061a310::FindTopicByInfo(context.info);
                context.quest = 0;
                if (context.topic)
                    context.quest = reinterpret_cast<::FUN_00619d00_shell *>((context.topic))->FindQuestForTopicInfo(context.info);
                {
                    BSStringT<char> text;
                    reinterpret_cast<::FUN_0061e2b0_shell *>((context.info))->BuildResponseText(text, true);
                    char description[1024];
                    if (context.topic && context.quest)
                        sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.info))->FUN_0084e3a0())), ((const char *)(::FUN_00559450((int *)&(text)))), context.quest->GetEditorName(),
                                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.quest))->FUN_0084e3a0())), context.topic->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.topic))->FUN_0084e3a0())));
                    else
                        sprintf(description, "TopicInfo %08X \"%s\"", ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.info))->FUN_0084e3a0())), ((const char *)(::FUN_00559450((int *)&(text)))));
                    ::FUN_005b5e40();
                }
            }
            else
            {
                pTopicList->SetItem(resolved.topic);
                pPreviousTopic = pTopicList;
                pTopicList = ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pTopicList))->FUN_00726070()));
            }
        }

        pPreviousTopic = 0;
        pTopicList = ((::BSSimpleList< ::TESTopic *> *)(new ((void *)this) ::Vec3()));
        while (pTopicList && ((::TESTopic *)(new ((void *)(pTopicList)) ::Vec3())))
        {
            struct TopicResolution
            {
                TESTopic* topic;
                unsigned int formID;
                TESForm* form;
            } resolved;
            resolved.formID = reinterpret_cast<unsigned int>(((::TESTopic *)(new ((void *)(pTopicList)) ::Vec3())));
            ::ResolveFormID((unsigned int *)&(resolved.formID), pFile);
            resolved.topic = 0;
            resolved.form = ::FUN_004839c0(resolved.formID);
            if (resolved.form && resolved.form->GetFormType() == ENUM_FORM_ID_DIAL_ID)
                resolved.topic = static_cast<TESTopic*>(resolved.form);

            if (!resolved.topic)
            {
                if (((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pTopicList))->FUN_00726070())) || !pPreviousTopic)
                    pTopicList->RemoveHead();
                else
                {
                    reinterpret_cast<::ItemChangeListNode *>((pPreviousTopic))->FUN_00905330((::InventoryStackRecord *const &)((const ::TESTopic *const &)(reinterpret_cast<TESTopic*>(resolved.formID))));
                    pTopicList = ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pPreviousTopic))->FUN_00726070()));
                }

                struct DiagnosticContext
                {
                    TESTopicInfo* info;
                    TESTopic* topic;
                    TESQuest* quest;
                } context;
                context.info = 0;
                if (owner && owner->GetFormType() == ENUM_FORM_ID_INFO_ID)
                    context.info = static_cast<TESTopicInfo*>(owner);
                context.topic = ::fnv_0061a310::FindTopicByInfo(context.info);
                context.quest = 0;
                if (context.topic)
                    context.quest = reinterpret_cast<::FUN_00619d00_shell *>((context.topic))->FindQuestForTopicInfo(context.info);
                {
                    BSStringT<char> text;
                    reinterpret_cast<::FUN_0061e2b0_shell *>((context.info))->BuildResponseText(text, true);
                    char description[1024];
                    if (context.topic && context.quest)
                        sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.info))->FUN_0084e3a0())), ((const char *)(::FUN_00559450((int *)&(text)))), context.quest->GetEditorName(),
                                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.quest))->FUN_0084e3a0())), context.topic->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.topic))->FUN_0084e3a0())));
                    else
                        sprintf(description, "TopicInfo %08X \"%s\"", ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.info))->FUN_0084e3a0())), ((const char *)(::FUN_00559450((int *)&(text)))));
                    ::FUN_005b5e40();
                }
            }
            else
            {
                pTopicList->SetItem(resolved.topic);
                pPreviousTopic = pTopicList;
                pTopicList = ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pTopicList))->FUN_00726070()));
            }
        }

        infoCursor.current = ((::BSSimpleList< ::TESTopicInfo *> *)(::FUN_00460140((int)this)));
        infoCursor.previous = 0;
        while (infoCursor.current && ((::TESTopicInfo *)(new ((void *)(infoCursor.current)) ::Vec3())))
        {
            struct InfoResolution
            {
                TESTopicInfo* followUp;
                unsigned int formID;
                TESForm* form;
            } resolved;
            resolved.formID = reinterpret_cast<unsigned int>(((::TESTopicInfo *)(new ((void *)(infoCursor.current)) ::Vec3())));
            ::ResolveFormID((unsigned int *)&(resolved.formID), pFile);
            resolved.followUp = 0;
            resolved.form = ::FUN_004839c0(resolved.formID);
            if (resolved.form && resolved.form->GetFormType() == ENUM_FORM_ID_INFO_ID)
                resolved.followUp = static_cast<TESTopicInfo*>(resolved.form);

            if (!resolved.followUp)
            {
                if (((::BSSimpleList< ::TESTopicInfo *> *)(reinterpret_cast<::Callees *>((infoCursor.current))->FUN_00726070())) || !infoCursor.previous)
                    infoCursor.current->RemoveHead();
                else
                {
                    reinterpret_cast<::ItemChangeListNode *>((infoCursor.previous))->FUN_00905330((::InventoryStackRecord *const &)((const ::TESTopicInfo *const &)(reinterpret_cast<TESTopicInfo*>(resolved.formID))));
                    infoCursor.current = ((::BSSimpleList< ::TESTopicInfo *> *)(reinterpret_cast<::Callees *>((infoCursor.previous))->FUN_00726070()));
                }

                struct DiagnosticContext
                {
                    TESTopicInfo* info;
                    TESTopic* topic;
                    TESQuest* quest;
                } context;
                context.info = 0;
                if (owner && owner->GetFormType() == ENUM_FORM_ID_INFO_ID)
                    context.info = static_cast<TESTopicInfo*>(owner);
                context.topic = ::fnv_0061a310::FindTopicByInfo(context.info);
                context.quest = 0;
                if (context.topic)
                    context.quest = reinterpret_cast<::FUN_00619d00_shell *>((context.topic))->FindQuestForTopicInfo(context.info);
                {
                    BSStringT<char> text;
                    reinterpret_cast<::FUN_0061e2b0_shell *>((context.info))->BuildResponseText(text, true);
                    char description[1024];
                    if (context.topic && context.quest)
                        sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)",
                                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.info))->FUN_0084e3a0())), ((const char *)(::FUN_00559450((int *)&(text)))), context.quest->GetEditorName(),
                                ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.quest))->FUN_0084e3a0())), context.topic->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.topic))->FUN_0084e3a0())));
                    else
                        sprintf(description, "TopicInfo %08X \"%s\"", ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((context.info))->FUN_0084e3a0())), ((const char *)(::FUN_00559450((int *)&(text)))));
                    ::FUN_005b5e40();
                }
            }
            else
            {
                infoCursor.current->SetItem(resolved.followUp);
                infoCursor.previous = infoCursor.current;
                infoCursor.current = ((::BSSimpleList< ::TESTopicInfo *> *)(reinterpret_cast<::Callees *>((infoCursor.current))->FUN_00726070()));
            }
        }
    }
}
// @fnv 0x0061e2b0
void FUN_0061e2b0_shell::BuildResponseText(BSStringT<char>& text, bool firstOnly)
{
    reinterpret_cast<::TextString *>((((BSStr*)&text)))->FUN_004037f0(0, 0);
    TESResponse* response = ((::TESResponse *)(::FUN_00559450((int *)(DuplicateResponseList(0)))));
    while (response)
    {
        ((BSStringT_char*)&text)->operator+=(reinterpret_cast<::TESResponse *>((((TESResponse_shell*)response)))->GetDialogueText());
        if (((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((response))->FUN_0045cd60())))
            ((BSStringT_char*)&text)->operator+=(" | ");
        if (firstOnly)
            break;
        response = ((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((response))->FUN_0045cd60()));
    }
}

struct FUN_0061cdc0_shell
{
    char pad1[0x25];
    signed char m_flags;  // +0x25
    void FUN_0061cdc0(bool value);
};
// @fnv 0x0061ccd0
TESTopicInfo::TESTopicInfo(DIALOGUE_TYPE type)
{
    InitializeComponent();
    m_Data.type = static_cast<char>(type);
    if (type == DIALOGUE_TYPE_DT_CONVERSATION)
    {
        m_pResponseData = new TESTopicInfoData;
        reinterpret_cast<::FUN_0061cdc0_shell *>(this)->FUN_0061cdc0(true);
    }
}

// @fnv 0x0061cdc0
void FUN_0061cdc0_shell::FUN_0061cdc0(bool abSet)
{
    abSet ? m_flags |= 2 : m_flags &= ~2;
}

struct FUN_0061f280_This
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19(unsigned int)
    {}
    char _pad[30];
    unsigned char field22;
    void FUN_0061f280();
};
// @fnv 0x0061f280
void FUN_0061f280_This::FUN_0061f280()
{
    field22 = 0;
    v19(0x80000000);
}

struct GlobalObject2_0040c150
{
};
int FUN_0061e720(const char*);
struct CondOps
{
};
struct QuestOps
{
};
struct AVOwner
{
    virtual void v0();
    virtual void v1();
    virtual int GetActorValue(int);
};
struct ActorS
{
    char pad[0xa4];
    AVOwner avOwner;
};
struct FUN_0061e600_t : public TESTopicInfo
{
    bool FUN_0061e600(bool& rbDeferred, TESQuest* apQuest, TESObjectREFR* apSpeaker, TESObjectREFR* apListener);
};

// @fnv 0x0061e600
bool FUN_0061e600_t::FUN_0061e600(bool& rbDeferred, TESQuest* apQuest, TESObjectREFR* apSpeaker,
                                  TESObjectREFR* apListener)
{
    bool bResult;
    ActorS* pActor;
    if (reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
        return false;
    if (reinterpret_cast<::FUN_00619b20_shell *>(this)->FUN_00619b20() && reinterpret_cast<::BSTempEffectDebris *>(this)->ShouldDelete())
        return false;
    {
        int iType = FUN_0061e720((const char*)this);
        pActor = 0;
        if (apListener && ((TESForm*)apListener)->IsActor())
            pActor = (ActorS*)apListener;
        if (pActor && pActor->avOwner.GetActorValue(9) <= *((int *)&(::FUN_0043d4d0((int *)&(::g_011d0dc8)))))
        {
            if (iType == 3)
                return false;
        }
        else if (iType == 1)
            return false;
        bResult = false;
        {
            bool bQuestOK = true;
            if (apQuest)
                bQuestOK =
                    reinterpret_cast<::PerkEntryConditionSet *>((((::CondOps *)(reinterpret_cast<::TESQuest *>((((QuestOps*)apQuest)))->GetConditions()))))->ContainsTrait(apSpeaker, apListener, rbDeferred, false);
            if (bQuestOK)
                bResult =
                    reinterpret_cast<::PerkEntryConditionSet *>((((CondOps*)((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>((((Script*)this)))->GetConditions())))))->ContainsTrait(apSpeaker, apListener, rbDeferred, false);
        }
    }
    return bResult;
}

struct BSS
{
    virtual ~BSS();
    unsigned long value;
};

struct ListX
{
    virtual ~ListX();
    unsigned long value;
};

struct Base5a
{
    virtual ~Base5a();
};

struct FUN_0061ceb0 : public Base5a
{
    unsigned char basePadding[0x14];
    PerkEntryConditionSet m_kInfoConditions;
    unsigned char conditionPadding[8];
    BSS m_kPrompt;
    ListX m_kAddTopicList;

    ~FUN_0061ceb0();
};

// @fnv 0x0061ceb0
FUN_0061ceb0::~FUN_0061ceb0()
{
    ((TESTopicInfo*)this)->TESTopicInfo::ClearData();
}


struct FUN_00485b60
{
    bool FUN_00485be0(unsigned int);
};

struct GROUP_PARENT_CHECK
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual bool CheckFormGRUP(FormRecordHeader*, bool, bool) = 0;
};

struct FUN_0061d820_shell
{
    bool CheckGroupForm(FormRecordHeader*, bool, bool);
};

// @fnv 0x0061d820
bool FUN_0061d820_shell::CheckGroupForm(FormRecordHeader* apGroupFORM, bool abAllowParentGroups, bool abCurrentOnly)
{
    bool bretval;
    TESTopic* pparenttopic;

    bretval = false;
    if (apGroupFORM)
    {
        if (reinterpret_cast<unsigned int*>(apGroupFORM)[0] == ::fnv_00543df0::kGroupFormType)
        {
            pparenttopic = ::fnv_0061a310::FindTopicByInfo(reinterpret_cast<TESTopicInfo*>(this));

            if (pparenttopic)
            {
                if (abAllowParentGroups)
                {
                    bretval = reinterpret_cast<GROUP_PARENT_CHECK*>(pparenttopic)
                                  ->CheckFormGRUP(apGroupFORM, abAllowParentGroups, abCurrentOnly);
                }

                if (!bretval && apGroupFORM->iFormID == 7 &&
                    reinterpret_cast<FUN_00485b60*>(pparenttopic)
                        ->FUN_00485be0(apGroupFORM->flags))
                {
                    bretval = true;
                }
            }
        }
    }

    return bretval;
}

struct TopicLinkLists
{
    void CopyLinksFrom(int unused, TopicLinkLists* source);
};
// @fnv 0x0061e180
void TESTopicInfo::SetTopicInfoData(TESTopicInfoData* data)
{
    if (data)
    {
        if (!m_pResponseData)
            m_pResponseData = new TESTopicInfoData;
        reinterpret_cast<::TopicLinkLists *>((m_pResponseData))->CopyLinksFrom((int)(this), (::TopicLinkLists *)(data));
    }
    else
    {
        if (m_pResponseData)
        {
            delete m_pResponseData;
            m_pResponseData = 0;
        }
        m_pResponseData = new TESTopicInfoData;
    }
}

// Clears this object's link lists, then copies the source's from-list, to-list and follow-up-list items into them.
// @fnv 0x0061c210
void TopicLinkLists::CopyLinksFrom(int unused, TopicLinkLists* source)
{
    if (!source)
        return;
    reinterpret_cast<::FUN_0061c330_shell *>(this)->RemoveAllLists();
    int item9;
    {
        BSSimpleList<int>* iter = 0;
        item9 = 0;
        for (iter = ((::BSSimpleList<int> *)(reinterpret_cast<::TESTopicInfoData *>((source))->GetLinkToList())); iter && ((int)(new ((void *)(iter)) ::Vec3()));)
        {
            item9 = ((int)(new ((void *)(iter)) ::Vec3()));
            iter = ((::BSSimpleList<int> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
            reinterpret_cast<::Callees *>((((::BSSimpleList<int> *)(reinterpret_cast<::TESTopicInfoData *>(this)->GetLinkToList()))))->FUN_00905820((void *)&(item9));
        }
        iter = ((::BSSimpleList<int> *)(new ((void *)(source)) ::Vec3()));
        item9 = 0;
        for (; iter && ((int)(new ((void *)(iter)) ::Vec3()));)
        {
            item9 = ((int)(new ((void *)(iter)) ::Vec3()));
            iter = ((::BSSimpleList<int> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
            reinterpret_cast<::Callees *>((((::BSSimpleList<int> *)(new ((void *)this) ::Vec3()))))->FUN_00905820((void *)&(item9));
        }
    }
    BSSimpleList<int>* follow2 = ((::BSSimpleList<int> *)(::FUN_00460140((int)(source))));
    int followItem4;
    while (follow2 && (followItem4 = ((int)(new ((void *)(follow2)) ::Vec3()))) != 0)
    {
        follow2 = ((::BSSimpleList<int> *)(reinterpret_cast<::Callees *>((follow2))->FUN_00726070()));
        reinterpret_cast<::Callees *>((((::BSSimpleList<int> *)(::FUN_00460140((int)this)))))->FUN_00905820((void *)&(followItem4));
    }
}

struct DialogueFormType : TESForm
{
    int FUN_00401170();
};
struct DialogueTopicCompare
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual bool Compare(TESTopic*);
};
struct TopicInfoCompare : TESTopicInfo
{
    bool FUN_0061d710(TESForm*);
};
// @fnv 0x0061d710
bool TopicInfoCompare::FUN_0061d710(TESForm* form)
{
    bool bResult = false;
    switch (static_cast<DialogueFormType*>(form)->FUN_00401170())
    {
    case 0x46: {
        TESTopicInfo* pOtherInfo = dynamic_cast<TESTopicInfo*>(form);
        if (pOtherInfo)
        {
            TESTopic* pSourceTopic = ::fnv_0061a310::FindTopicByInfo((::TESTopicInfo *)(::TESForm *)(this));
            TESTopic* otherOwner = ::fnv_0061a310::FindTopicByInfo((::TESTopicInfo *)(pOtherInfo));
            if (otherOwner && pSourceTopic && otherOwner != pSourceTopic)
            {
                bResult = reinterpret_cast<DialogueTopicCompare*>(pSourceTopic)->Compare(otherOwner);
            }
        }
        break;
    }
    case 0x45: {
        TESTopic* topic = dynamic_cast<TESTopic*>(form);
        if (topic)
        {
            TESTopic* owner = ::fnv_0061a310::FindTopicByInfo((::TESTopicInfo *)(::TESForm *)(this));
            if (owner && owner != topic)
                bResult = reinterpret_cast<DialogueTopicCompare*>(owner)->Compare(topic);
        }
        break;
    }
    default:
        bResult = reinterpret_cast<::TESFormSortProxy *>(this)->IsLessThan(form);
    }
    return bResult;
}

struct FUN_0061d8c0_input
{
    unsigned int unk00;
    unsigned int unk04;
    TESTopicInfo* unk08;
    unsigned int unk0C;
};

struct FUN_0061d8c0_output
{
    TESResponse* pResponse;
    unsigned int unk04;
    unsigned int formID;
    unsigned int unk0C;
    unsigned int unk10;
};

extern TESTopicInfo* DAT_01187344;

struct FUN_0061d8c0_shell
{
    void GetResponseForTopicInfo(FUN_0061d8c0_output* output, FUN_0061d8c0_input* input);
};

// @fnv 0x0061d8c0
void FUN_0061d8c0_shell::GetResponseForTopicInfo(FUN_0061d8c0_output* output, FUN_0061d8c0_input* input)
{
    int iVar1;

    if (output != 0)
    {
        output->pResponse = 0;
        if (input != 0)
        {
            switch (input->unk0C)
            {
            case 0:
                if (input->unk08 == DAT_01187344)
                {
                    iVar1 = ((int)(::fnv_0061a310::FindTopicByInfo((::TESTopicInfo *)(void *)(this))));
                    if (iVar1 != 0)
                    {
                        output->pResponse = (*reinterpret_cast<::TESResponse * *>(&::fnv_00543df0::kGroupFormType));
                        output->unk0C = 7;
                        output->formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)iVar1)))->FUN_0084e3a0()));
                        output->unk04 = 0;
                        output->unk10 = 0;
                    }
                }
                break;
            }
        }
    }
}

struct DebugTextOut;

struct TESResponseText : TESResponse
{
};

struct ResponseListHolder
{
};

struct TopicInfoDebug : TESTopicInfo
{
    void PrintDebugInfo(DebugTextOut* out);
};

// Builds topic, quest and response text fragments and prints the form type, editor ID, form ID and those fragments via DebugTextPrintf.
// @fnv 0x0061d950
void TopicInfoDebug::PrintDebugInfo(DebugTextOut* out)
{
    char topicText3[260];
    topicText3[0] = 0;
    TESTopic* topicA = ::fnv_0061a310::FindTopicByInfo(this);
    if (topicA)
    {
        sprintf(topicText3, ", Topic '%s' (%08X)", topicA->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((topicA))->FUN_0084e3a0())));
    }
    char questText2[260];
    questText2[0] = 0;
    if (topicA && reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
    {
        TESQuest* quest = reinterpret_cast<::FUN_00619d00_shell *>((topicA))->FindQuestForTopicInfo(this);
        if (quest)
        {
            sprintf(questText2, "Quest '%s' (%08X)", quest->GetEditorName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((quest))->FUN_0084e3a0())));
        }
    }
    char responseText9[260];
    responseText9[0] = 0;
    TESResponseText* response = ((::TESResponseText *)(::FUN_00559450((int *)(((::ResponseListHolder *)(reinterpret_cast<::TESTopicInfo *>(this)->DuplicateResponseList((::TESResponseList *)(0))))))));
    if (response)
    {
        sprintf(responseText9, ", Text: \"%s\"", reinterpret_cast<::TESResponse *>((response))->GetDialogueText());
    }
    ::FUN_00406f60((::FUN_00406f90_this *)(out), "%s Form '%s' (%08X): %s%s%s", ((const char *)(reinterpret_cast<::FUN_00440e30_This *>(this)->FUN_00440e30())), ((const char *)(reinterpret_cast<::FUN_00401280_Class *>(this)->FUN_00401280())), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())), questText2,
                    topicText3, responseText9);
}

struct TopicInfoCopy : TESTopicInfo
{
    void FUN_0061e330(TESForm* form);
    TESQuest* FUN_006733e0();
};
struct ResponseCopy : TESResponse
{
};
struct ScriptCopy : Script
{
};
// Copies topic info data from another TESTopicInfo: add-topic list, responses, prompt, perk/actor value, difficulty, speaker, result scripts and quest.
// @fnv 0x0061e330
void TopicInfoCopy::FUN_0061e330(TESForm* form)
{
    TESTopicInfo* topic = dynamic_cast<TESTopicInfo*>(form);
    if (!topic)
        return;
    BSSimpleList<TESTopic*>* source = 0;
    TESTopic* node = 0;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(form);
    m_Data = ((::TopicInfoData *)(reinterpret_cast<::FUN_0061e5e0_shell *>((static_cast<TopicInfoCopy*>(topic)))->GetFieldPtr()))[0];
    reinterpret_cast<::TESTopicInfo *>(this)->ResetResponseList();
    source = topic->GetAddTopicList();
    while (source && ((::TESTopic *)(new ((void *)(source)) ::Vec3())))
    {
        node = ((::TESTopic *)(new ((void *)(source)) ::Vec3()));
        source = ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((source))->FUN_00726070()));
        reinterpret_cast<::Callees *>((GetAddTopicList()))->FUN_00905820((void *)&(node));
    }
    reinterpret_cast<::TESTopicInfo *>(this)->ClearResponses();
    TESResponse* response = ((::TESResponse *)(::FUN_00559450((int *)(reinterpret_cast<::TESTopicInfo *>((static_cast<TopicInfoCopy*>(topic)))->DuplicateResponseList((::TESResponseList *)(0))))));
    while (response)
    {
        TESResponse* copy = new TESResponse;
        reinterpret_cast<::FUN_006174d0_shell *>((static_cast<ResponseCopy*>(copy)))->CopyResponse(response);
        reinterpret_cast<::FUN_0061cc60_holder *>((reinterpret_cast<::TESTopicInfo *>(this)->DuplicateResponseList((::TESResponseList *)(0))))->AddNode((int)(copy));
        response = ((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((response))->FUN_0045cd60()));
    }
    reinterpret_cast<::FUN_0061cfd0_shell *>(this)->FUN_0061cfd0((char *)(((const char *)(::FUN_00559450((int *)(((::BSStringT<char> *)(reinterpret_cast<::FUN_004610d0_shell *>((static_cast<TopicInfoCopy*>(topic)))->GetExtraDataList()))))))));
    if (topic->m_pPerkSkillStat)
    {
        switch (topic->m_pPerkSkillStat->GetFormType())
        {
        case ENUM_FORM_ID_PERK_ID:
            reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(::BGSPerk *)(reinterpret_cast<BGSPerk*>(topic->m_pPerkSkillStat)));
            break;
        case ENUM_FORM_ID_AVIF_ID:
            reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(::ActorValueInfo *)(reinterpret_cast<ActorValueInfo*>(topic->m_pPerkSkillStat)));
            break;
        default:
            m_pPerkSkillStat = topic->m_pPerkSkillStat;
        }
    }
    else
    {
        reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(::BGSPerk *)(0));
    }
    reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((*(::TESObjectREFR * *)&(const ::SPEECH_CHALLENGE_LEVEL &)((*(::SPEECH_CHALLENGE_LEVEL *)(reinterpret_cast<::LowProcess *>((static_cast<TopicInfoCopy*>(topic)))->GetActiveCombatTarget())))));
    reinterpret_cast<::FUN_00409480_shell *>(this)->FUN_00409480(((::TESActorBase *)(reinterpret_cast<::Twin_00639b40 *>((topic))->GetEntryPoint())));
    reinterpret_cast<::FUN_005aa420_shell *>((static_cast<ScriptCopy*>(GetResultScript(0))))->CopyFromScript(topic->GetResultScript(0));
    reinterpret_cast<::FUN_005aa420_shell *>((static_cast<ScriptCopy*>(GetResultScript(1))))->CopyFromScript(topic->GetResultScript(1));
    reinterpret_cast<FUN_0061f340_shell*>(this)->FUN_0061f340(reinterpret_cast<::FUN_00619a70_shell *>((topic))->FUN_00619a70());
    reinterpret_cast<FUN_0061e0f0_shell*>(this)->FUN_0061e0f0(reinterpret_cast<::BGSCameraPath *>((static_cast<TopicInfoCopy*>(topic)))->GetConditions());
    if (((::TESTopicInfoData *)(::GetField38((char *)(static_cast<TopicInfoCopy*>(topic))))))
        reinterpret_cast<::TESTopicInfo *>(this)->SetTopicInfoData(((::TESTopicInfoData *)(::GetField38((char *)(static_cast<TopicInfoCopy*>(topic))))));
    reinterpret_cast<::ValueModifierEffect *>(this)->SetActorValue((::ActorValue::Index)(static_cast<TopicInfoCopy*>(topic)->FUN_006733e0()));
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(reinterpret_cast<::TESForm *>((static_cast<TopicInfoCopy*>(topic)))->GetInitialized());
}

extern "C" void* __cdecl _alloca(unsigned int);
struct ScriptOps : Script
{
};
struct FileOps : TESFile
{
};
struct FUN_0061eb60_class : TESTopicInfo
{
    Script* FUN_0061eb60(unsigned int);
};
// Returns one of two cached result Script objects for this topic info, resetting and reloading them from the file's SC* chunks when the cache misses.
// @fnv 0x0061eb60
Script* FUN_0061eb60_class::FUN_0061eb60(unsigned int auiIndex)
{
    unsigned int h = auiIndex;
    if (this == g_cachedResultScriptInfo)
        return &g_resultScripts[h];
    g_cachedResultScriptInfo = this;
    Script i;
    reinterpret_cast<::FUN_005aa420_shell *>(&(g_resultScripts[0]))->CopyFromScript(&i);
    reinterpret_cast<::TESForm *>((((ScriptOps*)&g_resultScripts[0])))->NotifySaveLoadGameOfFormChange();
    ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(g_resultScripts[0]))->GetConditions()))->m_bQuest = false;
    reinterpret_cast<::FUN_005aa420_shell *>(&(g_resultScripts[1]))->CopyFromScript(&i);
    reinterpret_cast<::TESForm *>((((ScriptOps*)&g_resultScripts[1])))->NotifySaveLoadGameOfFormChange();
    ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(g_resultScripts[1]))->GetConditions()))->m_bQuest = false;
    if (!reinterpret_cast<::FUN_00508d70_shell *>(this)->FUN_00508d70())
        return &g_resultScripts[h];
    reinterpret_cast<::TESForm *>((((ScriptOps*)&g_resultScripts[0])))->SetInitializationState(0);
    reinterpret_cast<::TESForm *>((((ScriptOps*)&g_resultScripts[1])))->SetInitializationState(0);
    TESFile* a = GetFile(-1);
    if (!a || !m_ulTopicFlags)
        return &g_resultScripts[h];
    a = a->GetParentTESFile();
    if (!reinterpret_cast<::TESOffsetWorker *>((a))->FUN_004723a0(m_ulTopicFlags))
        return &g_resultScripts[h];
    unsigned char p = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((a))->FUN_00472660()));
    if (p != 0x46)
        return &g_resultScripts[h];
    int s = 0;
    int f;
    while (f = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((a))->FUN_004726b0())))
    {
        switch (f)
        {
        case 0x5458454e:
            s += 1;
            break;
        case 0x44534c53:
        case 0x52564353:
            if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((a))->FUN_004726b0())) == 0x44534c53)
            {
                g_loadedScriptVariable = new ScriptVariableInfo;
                g_loadedScriptVariable->Load(a);
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(&(g_resultScripts[s]))->FUN_005d43e0()))))->FUN_00905820((void *)&(g_loadedScriptVariable));
            }
            else if (g_loadedScriptVariable)
            {
                char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((a))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((a))->FUN_00472890((char *)(name), 0x200);
                reinterpret_cast<::TextString *>(&(g_loadedScriptVariable->m_kName))->FUN_004037f0(name, 0);
            }
            break;
        case 0x52484353:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((a))->FUN_00472890((char *)(void *)(((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(g_resultScripts[s]))->GetConditions()))), 0);
            if (reinterpret_cast<::TESFile *>((((FileOps*)a)))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00414220_shell *>((((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(g_resultScripts[s]))->GetConditions()))))->FUN_00414220();
            break;
        case 0x41444353: {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((a))->GetField25C();
            char* data = (char*)_alloca(size);
            FUN_00403d30(data, 0, size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((a))->FUN_00472890((char *)(data), 0);
            reinterpret_cast<::FUN_005aae70_shell *>(&(g_resultScripts[s]))->FUN_005aae70(size, data);
            break;
        }
        case 0x4f524353: {
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            unsigned int id;
            a->GetChunkData(&id);
            reference->pForm = (TESForm*)id;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(&(g_resultScripts[s]))->FUN_005d43c0()))))->FUN_00905820((void *)&(reference));
            break;
        }
        case 0x56524353: {
            ScriptReferencedObject* variable = new ScriptReferencedObject;
            unsigned int id;
            a->GetChunkData(&id);
            variable->m_uiFormID = id;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(&(g_resultScripts[s]))->FUN_005d43c0()))))->FUN_00905820((void *)&(variable));
            break;
        }
        }
        if (!a->NextChunk())
            break;
    }
    reinterpret_cast<::Scr *>(&(g_resultScripts[0]))->FUN_005ab400(this);
    reinterpret_cast<::Scr *>(&(g_resultScripts[1]))->FUN_005ab400(this);
    return &g_resultScripts[h];
}


class B61F2B0Object
{
  public:
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
    int m_iZ;

    int FUN_0061f2b0();
};

// @fnv 0x0061f2b0
int B61F2B0Object::FUN_0061f2b0()
{
    switch (m_iZ)
    {
    case 1:
        return *((int *)&(::FUN_0043d4d0((int *)&(::g_011cc06c))));
    case 2:
        return *((int *)&(::FUN_0043d4d0((int *)&(::g_011cc03c))));
    case 3:
        return *((int *)&(::FUN_0043d4d0((int *)&(::g_011cc058))));
    case 4:
        return *((int *)&(::FUN_0043d4d0((int *)&(::g_011cc024))));
    case 5:
        return *((int *)&(::FUN_0043d4d0((int *)&(::g_011cbf54))));
    }
    return -1;
}

struct S_00619510_Obj
{
    unsigned int unk00;
    int unk04;
    unsigned int unk08;
    int unk0C;
};
struct FUN_00619510_shell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual bool v15(TESTopic* t);
    bool IsFormInGroup(S_00619510_Obj* arg);
};
// @fnv 0x00619510
bool FUN_00619510_shell::IsFormInGroup(S_00619510_Obj* pGroupObj)
{
    bool result = false;
    if (pGroupObj != 0 && pGroupObj->unk00 == ::fnv_00543df0::kGroupFormType)
    {
        switch (pGroupObj->unk0C)
        {
        case 0:
            result = reinterpret_cast<::FUN_00484150_shell *>(this)->IsFormTypeBelowThreshold((::FormRecordHeader *)(pGroupObj));
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            result = false;
            break;
        case 7: {
            TESTopic* t = dynamic_cast<TESTopic*>(FUN_004839c0(pGroupObj->unk08));
            if (t)
                result = v15(t);
            break;
        }
        }
    }
    return result;
}

struct FUN_0061ce10
{
    virtual ~FUN_0061ce10();
};
// Destructor for the FUN_0061ce10 class that performs no additional cleanup.
// @fnv 0x0061ce10
FUN_0061ce10::~FUN_0061ce10()
{}
