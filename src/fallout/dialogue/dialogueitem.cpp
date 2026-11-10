// fallout/dialogue/dialogueitem.cpp: DialogueItem, DelStandIn, StandIn, DialogueItemResolver and more (14 functions)

#include "fnv/save_load_game_view.h"
#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0061e760_shell.h"
#include "fnv/decl/FUN_0083d420_shell.h"
#include "fnv/decl/FUN_0083d490_shell.h"
#include "fnv/decl/FUN_0083d690_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0083d550__Record.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011de000.h"
#include "dialogueitem_decls.h"

// @fnv 0x0083c820
DialogueResponse* DialogueItem::GetActiveResponse()
{
    if (m_pCurrentResponseList)
        return (*((::DialogueResponse * *)(&reinterpret_cast<::SimpleListNodeView*>(m_pCurrentResponseList)->m_item)));
    else
        return NULL;
}

// @fnv 0x005e3fa0
TESObjectREFR* DialogueItem::FUN_005e3fa0()
{
    return *(TESObjectREFR**)((char*)this + 0x6c);
}

void dialogueitem_emit_deleting_destructor(DialogueItem* item);

struct FUN_0083c7e0_shell : public DialogueItem
{
    bool FUN_0083c7e0();
};


// @fnv 0x0083c7e0
bool FUN_0083c7e0_shell::FUN_0083c7e0()
{
    if (*(void**)&this->m_pCurrentResponseList)
    {
        *(void**)&this->m_pCurrentResponseList = reinterpret_cast<::Callees *>((*(void**)&this->m_pCurrentResponseList))->FUN_00726070();
    }
    return *(void**)&this->m_pCurrentResponseList != 0;
}

namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_005c90d0(unsigned int flags);
};
// Calls the destructor on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x005c90d0
void* DelStandIn::FUN_005c90d0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

namespace fnv_0083c670 {
class DialogueResponse
{
  public:
    ~DialogueResponse();
};
struct ListX
{
    ~ListX();
    bool _ref_008256d0();
    void _ref_0063f7b0();
};
struct FUN_0083c670
{
    ListX list;
    ~FUN_0083c670();
};
// Destructor that repeatedly deletes the list's current DialogueResponse and advances until the list reports empty.
// @fnv 0x0083c670
FUN_0083c670::~FUN_0083c670()
{
    ListX* pList = &list;
    while (pList && !pList->_ref_008256d0())
    {
        delete *((::fnv_0083c670::DialogueResponse **)(&reinterpret_cast<::SimpleListNodeView*>(pList)->m_item));
        pList->_ref_0063f7b0();
    }
}
}  // namespace fnv_0083c670

struct FUN_0083c9e0_resp
{
};
struct FUN_0083c9e0_t
{
    bool IsEmpty();
    unsigned short FUN_0083c9e0();
};

// @fnv 0x0083c9e0
unsigned short FUN_0083c9e0_t::FUN_0083c9e0()
{
    unsigned short usSize = 0;
    usSize += 1;
    FUN_0083c9e0_t* pIter = this;
    while (pIter && !pIter->IsEmpty())
    {
        FUN_0083c9e0_resp* pResponse = *((::FUN_0083c9e0_resp **)(&reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item));
        usSize += reinterpret_cast<::FUN_0083d420_shell *>((pResponse))->FUN_0083d420();
        pIter = ((::FUN_0083c9e0_t *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }
    usSize += 1;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    return usSize;
}


struct FUN_0083c900_shell : public DialogueItem
{
    short GetResponseIndex(DialogueResponse* response);
};

// Returns the index of response in the dialogue responses list, warning and returning 0 if it is not found.
// @fnv 0x0083c900
short FUN_0083c900_shell::GetResponseIndex(DialogueResponse* response)
{
    short iElementIndex = 0;
    BSSimpleList<DialogueResponse*>* pCurrentElementNext = &m_kResponseList;
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        if (response == (*((::DialogueResponse * *)(&reinterpret_cast<::SimpleListNodeView*>(pCurrentElementNext)->m_item))))
            return iElementIndex;
        ++iElementIndex;
        pCurrentElementNext = ((::BSSimpleList< ::DialogueResponse *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    ::FUN_005b5e40(
        );
    return 0;
}


struct DialogueItem_shell : public DialogueItem
{
    DialogueResponse* GetResponseByIndex(short index);
};

// Walks the dialogue response list and returns the response at the given index, warning and returning null if the index is out of range.
// @fnv 0x0083c970
DialogueResponse* DialogueItem_shell::GetResponseByIndex(short index)
{
    short current = 0;
    BSSimpleList<DialogueResponse*>* node = &m_kResponseList;
    while (node && !node->IsEmpty())
    {
        if (current == index)
            return (*((::DialogueResponse * *)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)));
        ++current;
        node = ((::BSSimpleList< ::DialogueResponse *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    ::FUN_005b5e40(
        );
    return 0;
}

bool _ref_008256d0(void*);
class DialogueResponse;
DialogueResponse*& _ref_006815c0(void*);
struct StandIn
{
    char _pad[8];
    void* _cur;
    void FUN_0083c8a0(DialogueResponse* apDialogueResponse);
};
// @fnv 0x0083c8a0
void StandIn::FUN_0083c8a0(DialogueResponse* apDialogueResponse)
{
    void* pCurrentElementNext = (void*)this;
    while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
    {
        if (apDialogueResponse == _ref_006815c0(pCurrentElementNext))
        {
            _cur = pCurrentElementNext;
            break;
        }
        pCurrentElementNext = reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070();
    }
}

struct TESSaveLoadGame
{
};
struct DialogueFormRef
{
};
struct DialogueResponseSave
{
};
struct FUN_0083ca90_t : DialogueItem
{
    void SaveDialogueItem();
};

// @fnv 0x0083ca90
void FUN_0083ca90_t::SaveDialogueItem()
{
    char cCount4 = 0;
    char* pCountPos8 = ((char *)(reinterpret_cast<::SaveLoadGameView *>((g_TESSaveLoadGame))->pBufferCursor));
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&cCount4, 1);
    BSSimpleList<DialogueResponse*>* plist2 = &m_kResponseList;
    while (plist2 && !plist2->IsEmpty())
    {
        DialogueResponse* presponse3 = (*((::DialogueResponse * *)(&reinterpret_cast<::SimpleListNodeView*>(plist2)->m_item)));
        reinterpret_cast<::FUN_0083d490_shell *>((((DialogueResponseSave*)presponse3)))->SaveToGame();
        cCount4++;
        plist2 = ((::BSSimpleList< ::DialogueResponse *> *)(reinterpret_cast<::Callees *>((plist2))->FUN_00726070()));
    }
    *pCountPos8 = cCount4;

    char cCurrentVal = -1;
    if (m_pCurrentResponseList)
        cCurrentVal = reinterpret_cast<::FUN_0083c900_shell *>(this)->GetResponseIndex((*((::DialogueResponse * *)(&reinterpret_cast<::SimpleListNodeView*>(m_pCurrentResponseList)->m_item))));
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&cCurrentVal, 1);

    unsigned int aIInfoID = 0;
    if (pInfo)
        aIInfoID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((DialogueFormRef*)pInfo)))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>((g_TESSaveLoadGame))->FUN_00857a10((const unsigned int *)(void *)(&aIInfoID), 4);

    unsigned int m_uiTopicFormID = 0;
    if (pTopic)
        m_uiTopicFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((DialogueFormRef*)pTopic)))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>((g_TESSaveLoadGame))->FUN_00857a10((const unsigned int *)(void *)(&m_uiTopicFormID), 4);

    unsigned int iQuestID_2 = 0;
    if (pQuest)
        iQuestID_2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((DialogueFormRef*)pQuest)))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>((g_TESSaveLoadGame))->FUN_00857a10((const unsigned int *)(void *)(&iQuestID_2), 4);

    unsigned int iSpeakerID = 0;
    if (m_pDialogueSpeaker)
        iSpeakerID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((DialogueFormRef*)m_pDialogueSpeaker)))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>((g_TESSaveLoadGame))->FUN_00857a10((const unsigned int *)(void *)(&iSpeakerID), 4);
}

class TESForm
{
  public:
    virtual ~TESForm();
};
class TESObjectREFR : public TESForm
{
};
class DialogueItemResolver : public DialogueItem
{
  public:
    void FUN_0083cdf0();
};
// @fnv 0x0083cdf0
void DialogueItemResolver::FUN_0083cdf0()
{
    unsigned int loc = (unsigned int)reinterpret_cast<std::uintptr_t>(m_pDialogueSpeaker);
    if (loc)
    {
        m_pDialogueSpeaker = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(loc));
    }
}

struct BGSSaveGameBuffer
{
};
struct DialogueResponseBufferWriter
{
};
struct DialogueItemBufferWriter : ::DialogueItem
{
    void FUN_0083ce40(BGSSaveGameBuffer* apSaveGameBuffer);
};

// Writes the response list, current response index, and associated form data (pInfo, pTopic, pQuest, m_pDialogueSpeaker) to apSaveGameBuffer.
// @fnv 0x0083ce40
void DialogueItemBufferWriter::FUN_0083ce40(BGSSaveGameBuffer* apSaveGameBuffer)
{
    short scurrentResponse;
    ::BSSimpleList< ::DialogueResponse*>* pCurrentElementNext;
    unsigned int isaveGameBufferPos;
    unsigned int isaveGameCount;

    isaveGameCount = 0;
    isaveGameBufferPos = reinterpret_cast<::FUN_00865f20_shell *>((apSaveGameBuffer))->FUN_00865f20();
    pCurrentElementNext = &m_kResponseList;
    while (pCurrentElementNext)
    {
        ::DialogueResponse* presponse = (*((::DialogueResponse * *)(&reinterpret_cast<::SimpleListNodeView*>(pCurrentElementNext)->m_item)));
        if (presponse)
        {
            reinterpret_cast<::FUN_0083d690_shell *>((reinterpret_cast<DialogueResponseBufferWriter*>(presponse)))->FUN_0083d690((::BGSSaveFormBuffer *)(apSaveGameBuffer));
            isaveGameCount++;
        }
        pCurrentElementNext = ((::BSSimpleList< ::DialogueResponse *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((apSaveGameBuffer))->FUN_00865ff0(isaveGameCount, isaveGameBufferPos);
    scurrentResponse = m_pCurrentResponseList ? reinterpret_cast<::FUN_0083c900_shell *>(this)->GetResponseIndex((*((::DialogueResponse * *)(&reinterpret_cast<::SimpleListNodeView*>(m_pCurrentResponseList)->m_item)))) : -1;
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&scurrentResponse, 2, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pInfo), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pTopic), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pQuest), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pDialogueSpeaker), 0);
}

namespace fnv_0083c520 {
struct TESResponse
{
};
class TESResponseList
{
  public:
    TESResponseList();
    ~TESResponseList();
    operator unsigned int() const;
    TESResponse* pHead;
};
struct FUN_0061e760_shell
{
};
class DialogueResponse;
typedef ::BSSimpleList<DialogueResponse*> DialogueResponseList;
class DialogueResponse
{
  public:
    DialogueResponse(TESQuest*, TESTopic*, TESTopicInfo*, TESObjectREFR*, TESResponse*);
    char* pResponseText;
    unsigned short usResponseLen;
    unsigned short usResponseMax;
    unsigned int eEmotion;
    int ActorProjectileState;
    char* pVoiceFile;
    unsigned short usVoiceLen;
    unsigned short usVoiceMax;
    void* m_pFirstIdleForm;
    void* m_pSecondIdleForm;
    TESTopic* pTopic;
    TESQuest* pQuest;
    TESObjectREFR* m_pDialogueSpeaker;
};
struct FUN_0083c520
{
    DialogueResponseList ResponseList;
    void* m_pCurrentResponseList;
    TESTopicInfo* pInfo;
    TESTopic* pTopic;
    TESQuest* pQuest;
    TESObjectREFR* m_pDialogueSpeaker;
    FUN_0083c520(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo, TESObjectREFR* apSpeaker);
};

// Constructs a dialogue response list by iterating over TESResponse entries from apInfo and appending a DialogueResponse for each.
// @fnv 0x0083c520
FUN_0083c520::FUN_0083c520(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo, TESObjectREFR* apSpeaker)
{
    m_pCurrentResponseList = 0;
    pInfo = 0;
    if (apTopic && apInfo && apQuest)
    {
        pInfo = apInfo;
        pTopic = apTopic;
        pQuest = apQuest;
        m_pDialogueSpeaker = apSpeaker;
        TESResponseList responseList;
        reinterpret_cast<::FUN_0061e760_shell *>((((FUN_0061e760_shell*)apInfo)))->FUN_0061e760((::TESResponseList *)(::fnv_0083c520::TESResponseList *)(&responseList));
        TESResponse* presponse = responseList.pHead;
        while (presponse)
        {
            DialogueResponse* pResponse = new DialogueResponse(apQuest, apTopic, apInfo, apSpeaker, presponse);
            reinterpret_cast<::Callees *>(&(ResponseList))->FUN_00905820((void *)&(pResponse));
            presponse = (TESResponse*)(reinterpret_cast<::FUN_0045cd60_shell *>((presponse))->FUN_0045cd60());
        }
    }
}
}  // namespace fnv_0083c520

struct DialogueLoadGame : ::TESSaveLoadGame
{
};
class TESTopicInfo : public ::TESForm
{
};
class TESTopic : public ::TESForm
{
};
class TESQuest : public ::TESForm
{
};
class TESIdleForm;
class DialogueResponse
{
  public:
    DialogueResponse();
    BSStringT<char> m_kResponseText;
    unsigned int eEmotion;
    unsigned int m_uiEmotionValue;
    BSStringT<char> m_kResponseNotes;
    TESIdleForm* m_pFirstIdleForm;
    TESIdleForm* m_pSecondIdleForm;
    TESTopic* pTopic;
    TESTopicInfo* pInfo;
    TESQuest* pQuest;
};
struct DialogueItemLoad : ::DialogueItem
{
    void FUN_0083cc10();
};

// Reads response count, current index, topic info, topic, quest, and speaker IDs from the save stream into the dialogue item.
// @fnv 0x0083cc10
void DialogueItemLoad::FUN_0083cc10()
{
    unsigned char cCount4;
    unsigned int iloopB;
    ::DialogueResponse* presponse3;
    char cCurrentVal;
    unsigned int aIInfoID;
    unsigned int m_uiTopicFormID;
    unsigned int iQuestID_2;
    unsigned int iSpeakerID;

    reinterpret_cast<::FUN_008579e0_shell *>((((DialogueLoadGame*)g_TESSaveLoadGame)))->FUN_008579e0(&cCount4, 1);
    for (iloopB = 0; iloopB < cCount4; iloopB++)
    {
        presponse3 = reinterpret_cast< ::DialogueResponse*>(new DialogueResponse);
        reinterpret_cast<::fnv_0083d550::Record *>((reinterpret_cast<DialogueResponse*>(presponse3)))->FUN_0083d550();
        reinterpret_cast<::Callees *>(&(m_kResponseList))->FUN_00905820((void *)&(presponse3));
    }

    reinterpret_cast<::FUN_008579e0_shell *>((((DialogueLoadGame*)g_TESSaveLoadGame)))->FUN_008579e0(&cCurrentVal, 1);
    if (cCurrentVal != -1)
        reinterpret_cast<::StandIn *>(this)->FUN_0083c8a0(reinterpret_cast<::DialogueItem_shell *>(this)->GetResponseByIndex(cCurrentVal));
    else
        m_pCurrentResponseList = 0;

    reinterpret_cast<::FUN_00857aa0 *>((((DialogueLoadGame*)g_TESSaveLoadGame)))->ValidateFormIDArray((unsigned int *)(void *)(&aIInfoID), 4);
    if (aIInfoID)
        pInfo = reinterpret_cast< ::TESTopicInfo*>(dynamic_cast<TESTopicInfo*>(::FUN_004839c0(aIInfoID)));
    reinterpret_cast<::FUN_00857aa0 *>((((DialogueLoadGame*)g_TESSaveLoadGame)))->ValidateFormIDArray((unsigned int *)(void *)(&m_uiTopicFormID), 4);
    if (m_uiTopicFormID)
        pTopic = reinterpret_cast< ::TESTopic*>(dynamic_cast<TESTopic*>(::FUN_004839c0(m_uiTopicFormID)));
    reinterpret_cast<::FUN_00857aa0 *>((((DialogueLoadGame*)g_TESSaveLoadGame)))->ValidateFormIDArray((unsigned int *)(void *)(&iQuestID_2), 4);
    if (iQuestID_2)
        pQuest = reinterpret_cast< ::TESQuest*>(dynamic_cast<TESQuest*>(::FUN_004839c0(iQuestID_2)));
    reinterpret_cast<::FUN_00857aa0 *>((((DialogueLoadGame*)g_TESSaveLoadGame)))->ValidateFormIDArray((unsigned int *)(void *)(&iSpeakerID), 4);
    m_pDialogueSpeaker = reinterpret_cast<::TESObjectREFR*>(static_cast<std::uintptr_t>(iSpeakerID));
}
