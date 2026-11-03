// fallout_shared/tesresponse.cpp: TESResponse, DialogueResponseData (11 functions)

#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00616c70_cls.h"
#include "fnv/decl/FUN_00619d00_shell.h"
#include "fnv/decl/FUN_0061e2b0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_011cb000.h"
#include "tesresponse_decls.h"
#include <stdio.h>
#include <string.h>

// Resolves the response's topic, sound and idle form IDs against the owner's file, clearing invalid ones and warning on failure, then applies the emotion value.
// @fnv 0x00617580
void TESResponse::InitItem(TESForm* owner)
{
    if (Data.m_pTopic)
    {
        struct FormResolution
        {
            unsigned int formID;
            TESForm* form;
        } resolved;
        resolved.formID = reinterpret_cast<unsigned int>(Data.m_pTopic);
        ::ResolveFormID((unsigned int *)&(resolved.formID), owner->GetFile(-1));
        resolved.form = ::FUN_004839c0(resolved.formID);
        if (resolved.form && resolved.form->GetFormType() == 69)
            Data.m_pTopic = static_cast<TESTopic*>(resolved.form);
        else
            Data.m_pTopic = 0;
        if (!Data.m_pTopic)
        {
            TESTopicInfo* info = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* topic = ::fnv_0061a310::FindTopicByInfo(info);
            TESQuest* quest = 0;
            if (topic)
                quest = reinterpret_cast<::FUN_00619d00_shell *>((topic))->FindQuestForTopicInfo(info);
            {
                BSStringT<char> text;
                reinterpret_cast<::FUN_0061e2b0_shell *>((info))->BuildResponseText(text, true);
                char description[260];
                sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)", ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((info))->FUN_0084e3a0())),
                        ((const char *)(::FUN_00559450((int *)&(text)))), quest ? quest->GetEditorName() : "", quest ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((quest))->FUN_0084e3a0())) : 0,
                        topic ? topic->GetName() : "", topic ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((topic))->FUN_0084e3a0())) : 0);
                ::FUN_005b5e40();
            }
        }
    }
    if (Data.m_pResponseSound)
    {
        struct FormResolution
        {
            unsigned int formID;
            TESForm* form;
        } resolved;
        resolved.formID = reinterpret_cast<unsigned int>(Data.m_pResponseSound);
        ::ResolveFormID((unsigned int *)&(resolved.formID), owner->GetFile(-1));
        resolved.form = ::FUN_004839c0(resolved.formID);
        if (resolved.form && resolved.form->GetFormType() == 13)
            Data.m_pResponseSound = static_cast<TESSound*>(resolved.form);
        else
            Data.m_pResponseSound = 0;
        if (!Data.m_pResponseSound)
        {
            TESTopicInfo* info = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* topic = ::fnv_0061a310::FindTopicByInfo(info);
            TESQuest* quest = 0;
            if (topic)
                quest = reinterpret_cast<::FUN_00619d00_shell *>((topic))->FindQuestForTopicInfo(info);
            {
                BSStringT<char> text;
                reinterpret_cast<::FUN_0061e2b0_shell *>((info))->BuildResponseText(text, true);
                char description[260];
                sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)", ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((info))->FUN_0084e3a0())),
                        ((const char *)(::FUN_00559450((int *)&(text)))), quest ? quest->GetEditorName() : "", quest ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((quest))->FUN_0084e3a0())) : 0,
                        topic ? topic->GetName() : "", topic ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((topic))->FUN_0084e3a0())) : 0);
                ::FUN_005b5e40();
            }
        }
    }
    if (m_pFirstIdleForm)
    {
        struct FormResolution
        {
            unsigned int formID;
            TESForm* form;
        } resolved;
        resolved.formID = reinterpret_cast<unsigned int>(m_pFirstIdleForm);
        ::ResolveFormID((unsigned int *)&(resolved.formID), owner->GetFile(-1));
        resolved.form = ::FUN_004839c0(resolved.formID);
        if (resolved.form && resolved.form->GetFormType() == 72)
            m_pFirstIdleForm = static_cast<TESIdleForm*>(resolved.form);
        else
            m_pFirstIdleForm = 0;
        if (!m_pFirstIdleForm)
        {
            TESTopicInfo* info = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* topic = ::fnv_0061a310::FindTopicByInfo(info);
            TESQuest* quest = 0;
            if (topic)
                quest = reinterpret_cast<::FUN_00619d00_shell *>((topic))->FindQuestForTopicInfo(info);
            {
                BSStringT<char> text;
                reinterpret_cast<::FUN_0061e2b0_shell *>((info))->BuildResponseText(text, true);
                char description[260];
                sprintf(description, "TopicInfo %08X \"%s\" in Quest %s (%08x) Topic %s (%08x)", ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((info))->FUN_0084e3a0())),
                        ((const char *)(::FUN_00559450((int *)&(text)))), quest ? quest->GetEditorName() : "", quest ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((quest))->FUN_0084e3a0())) : 0,
                        topic ? topic->GetName() : "", topic ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((topic))->FUN_0084e3a0())) : 0);
                ::FUN_005b5e40();
            }
        }
    }
    if (m_pSecondIdleForm)
    {
        struct FormResolution
        {
            unsigned int formID;
            TESForm* form;
        } resolved;
        resolved.formID = reinterpret_cast<unsigned int>(m_pSecondIdleForm);
        ::ResolveFormID((unsigned int *)&(resolved.formID), owner->GetFile(-1));
        resolved.form = ::FUN_004839c0(resolved.formID);
        if (resolved.form && resolved.form->GetFormType() == 72)
            m_pSecondIdleForm = static_cast<TESIdleForm*>(resolved.form);
        else
            m_pSecondIdleForm = 0;
        if (!m_pSecondIdleForm)
        {
            TESTopicInfo* info = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* topic = ::fnv_0061a310::FindTopicByInfo(info);
            TESQuest* quest = 0;
            if (topic)
                quest = reinterpret_cast<::FUN_00619d00_shell *>((topic))->FindQuestForTopicInfo(info);
            {
                BSStringT<char> text;
                reinterpret_cast<::FUN_0061e2b0_shell *>((info))->BuildResponseText(text, true);
                // The original listener failure path does not initialize this buffer.
                char description[260];
                ::FUN_005b5e40();
            }
        }
    }
    if (GetEmotion())
        reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cbdf4))))))->i));
}

// Builds a filename from quest, topic and info when the response ID is nonzero, otherwise sets it to "New Response".
// @fnv 0x00617400
void TESResponse::BuildResponseFileName(TESQuest* quest, TESTopic* topic, TESTopicInfo* info, BSStringT<char>& filename)
{
    if (!quest || !topic || !info)
        return;
    unsigned int responseID = GetResponseID();
    if (responseID > 0)
    {
        char combined[260];
        BuildQuestTopicName(quest, topic, combined, sizeof(combined));
        unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((info))->FUN_0084e3a0())) & 0x00FFFFFF;
        ::FUN_00406f60((::FUN_00406f90_this *)&(filename), "%s_%08X_%u", combined, formID, responseID);
    }
    else
        reinterpret_cast<::TextString *>(&(filename))->FUN_004037f0("New Response", 0);
}

// @fnv 0x00616ce0
TESResponse::TESResponse()
{
    reinterpret_cast<::TextString *>(&(m_kResponseText))->FUN_004037f0(0, 0);
    m_pFirstIdleForm = 0;
    m_pSecondIdleForm = 0;
    pNext = 0;
}

// @fnv 0x006172c0
void TESResponse::BuildQuestTopicName(TESQuest* quest, TESTopic* topic, char* output, unsigned int capacity)
{
    if (!output || !capacity)
        return;
    *output = 0;
    if (!quest || !topic)
        return;
    // Separate scopes preserve the original buffer lifetimes and stack ordering.
    unsigned int questLength;
    {
        char topicName[260];
        {
            char questName[260];
            {
                ::FUN_004046f0(questName, quest->GetEditorName());
                ::FUN_004046f0(topicName, topic->GetName());
                questLength = strlen(questName);
                unsigned int topicLength = strlen(topicName);
                if (questLength + topicLength > 25)
                {
                    struct NameLimits
                    {
                        unsigned int quest;
                        unsigned int topic;
                    } limits;
                    limits.quest = 10;
                    limits.topic = 15;
                    if (questLength > limits.quest)
                        questName[limits.quest] = 0;
                    else
                        limits.topic += limits.quest - questLength;
                    topicName[limits.topic] = 0;
                }
                sprintf_s(output, capacity, "%s_%s", questName, topicName);
            }
        }
    }
}

// Deletes every TESResponse in the linked list starting at pHead, then sets pHead to null.
// @fnv 0x0061cad0
void TESResponseList::ClearResponses()
{
    TESResponse* response = pHead;
    while (response)
    {
        TESResponse* next = ((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((response))->FUN_0045cd60()));
        delete response;
        response = next;
    }
    pHead = 0;
}

// Reads the response data chunk from the TESFile if the chunk ID matches, converting endianness when required.
// @fnv 0x00617530
void TESResponse::Load(TESFile* file)
{
    if (file && ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x54445254)
    {
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), sizeof(Data));
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_00616c70_cls *>(&(Data))->InitializeFields();
    }
}

// @fnv 0x00616de0
const char* TESResponse::GetDialogueText()
{
    return ((const char *)(::FUN_00559450((int *)&(m_kResponseText)))) ? ((const char *)(::FUN_00559450((int *)&(m_kResponseText)))) : "";
}

// @fnv 0x00616d70
DialogueResponseData::DialogueResponseData()
{
    eEmotion = static_cast<DIALOGUE_EMOTION>(0);
    ActorProjectileState = 50;
    m_pTopic = 0;
    m_ucResponseFlags = 0;
    m_pResponseSound = 0;
    m_bTenthFlag = true;
}

// @fnv 0x00616dc0
TESResponse::~TESResponse()
{}

// @fnv 0x006174b0
unsigned int TESResponse::GetResponseID()
{
    return Data.m_ucResponseFlags;
}

struct DialogueResponse
{
};
struct BSStr
{
};
struct TESObject
{
};
struct RegionPointList
{
};
struct BSThread
{
};
namespace ActorValue { enum Index; }
struct TESRecipe
{
public:
    void SetRequiredSkill(::ActorValue::Index);
};
struct FUN_006174d0_shell
{
    char _pad[24];
    BSStr s;
    void CopyResponse(TESResponse* apCopy);
};
// Copies 24 bytes from apCopy into this, then sets the string, distance and skill fields from apCopy's members.
// @fnv 0x006174d0
void FUN_006174d0_shell::CopyResponse(TESResponse* apCopy)
{
    __memcpy(this, &(*(::BSStringT<char> *)((void *)(((DialogueResponse*)apCopy)))), 24);
    reinterpret_cast<::TextString *>(&(s))->FUN_004037f0(apCopy->GetDialogueText(), 0);
    reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((((RegionPointList*)this)))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObject*)apCopy)))->FUN_007af430()))));
    ((TESRecipe*)this)->SetRequiredSkill((::ActorValue::Index)(reinterpret_cast<::ActorMover *>((((BSThread*)apCopy)))->GetCurrentMoveModeType()));
}
