// fallout_shared/testopic.cpp: TESTopic, NavShell2, TopicFlagStandIn, TopicSaver and more (49 functions)

#include <new>
#include <ctime>
#include <malloc.h>
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/B408A80String.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSTempEffectDebris.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_0042efe0_cls.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004600f0_class.h"
#include "fnv/decl/FUN_00460270_cls.h"
#include "fnv/decl/FUN_004612e0_shell.h"
#include "fnv/decl/FUN_00461780_cls.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472fe0_cls.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_00526ae0_class.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00600ab0_shell.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_006186d0.h"
#include "fnv/decl/FUN_0061bf70_Class.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_0061f170_cls.h"
#include "fnv/decl/FUN_0061f280_This.h"
#include "fnv/decl/FUN_0061f340_shell.h"
#include "fnv/decl/FUN_006b3f40_Class.h"
#include "fnv/decl/FUN_006cf4c0_Array.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiFormArray.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S00863d90.h"
#include "fnv/decl/SortOwner.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/TESFormSortProxy.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TMapStandIn.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/TopicLinkLists.h"
#include "fnv/decl/TopicLookup.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/VFDialogue.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00952830__FUN_00952830_Class.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0119a000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "TESTopic.h"
#include "TESTopicInfo.h"
#include "TESQuest.h"
#include "QuestDialogueInfo.h"
#include "INFO_LINK_ELEMENT.h"
#include "TESTopicInfoData.h"
#include "DialogueItem.h"
#include "MobileObject.h"
#include "PlayerCharacter.h"
#include "game_constants.h"
#include "TESTopicInfo_decl_testopic.h"

// @fnv 0x0061a790
TESTopicInfo* TESTopic::FindMatchingTopicInfo(bool& deferred, TESObjectREFR* speaker, TESObjectREFR* listener,
                                              bool filter, TESTopic* previousTopic,
                                              BSSimpleList<DialogueItem*>* history)
{
    return FindMatchingTopicInfo(this, deferred, speaker, listener, filter, previousTopic, history);
}

struct TESObject
{
    int _FNV_GetFormType();
};
struct FUN_00616f40_shell
{
    bool DispatchOnNextFormType(TESObject* obj, int a, int b, int c, int d);
};
// If obj is non-null and its next object's form type is 0x16, 0x2a or 0x2b, forwards that next object to BuildVoiceFilePath; otherwise returns false.
// @fnv 0x00616f40
bool FUN_00616f40_shell::DispatchOnNextFormType(TESObject* obj, int a, int b, int c, int d)
{
    if (obj)
    {
        switch (((::TESObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((obj))->FUN_007af430()))->_FNV_GetFormType())
        {
        case 0x16:
        case 0x2a:
        case 0x2b:
            return reinterpret_cast<::VFDialogue *>(this)->BuildVoiceFilePath((::VFForm *)(::TESObject *)(((::TESObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((obj))->FUN_007af430()))), (void *)(a), (void *)(b), (::VFTopicInfo *)(c), (char *)(d));
        }
    }
    return false;
}

struct FUN_00619010_shell : public TESTopic
{
    void FUN_00619010(char*);
};

// @fnv 0x00619010
void FUN_00619010_shell::FUN_00619010(char* apPrompt)
{
    reinterpret_cast<::TextString *>(&(m_kDummyPrompt))->FUN_004037f0(apPrompt, 0);
}

// @fnv 0x00619410
bool FUN_00619410(const char* pFlags)
{
    return (bool)(pFlags[0x25] & 2);
}

struct FUN_006195d0_shell : public TESTopic
{
    QuestDialogueInfo* GetOrCreateQuestInfo(TESQuest*, bool);
};

QuestDialogueInfo* FUN_00619740(void*);

struct QuestInfoStub : public QuestDialogueInfo
{
    QuestInfoStub()
    {
        FUN_00619740(this);
    }
};

// Searches the quest info list for an entry matching apQuest, creating and appending a new entry if none is found.
// @fnv 0x006195d0
QuestDialogueInfo* FUN_006195d0_shell::GetOrCreateQuestInfo(TESQuest* apQuest, bool abReSort)
{
    if (!apQuest)
        return 0;

    BSSimpleList<QuestDialogueInfo*>* pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)this)->GetDiffuseColor()));
    QuestDialogueInfo* pQuestInfo = 0;

    while (pList && (pList->m_item) && !pQuestInfo)
    {
        pQuestInfo = (pList->m_item);
        pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        if (pQuestInfo->bInitialized)
        {
            if ((!pQuestInfo->pQuest || ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pQuestInfo->pQuest))->FUN_0084e3a0())) != (unsigned int)(std::uintptr_t)apQuest) &&
                (!pQuestInfo->m_pAlternateQuest || ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pQuestInfo->m_pAlternateQuest))->FUN_0084e3a0())) != (unsigned int)(std::uintptr_t)apQuest))
            {
                pQuestInfo = 0;
            }
        }
        else
        {
            if (pQuestInfo && pQuestInfo->pQuest != apQuest && pQuestInfo->m_pAlternateQuest != apQuest)
            {
                pQuestInfo = 0;
            }
        }
    }

    if (!pQuestInfo)
    {
        pQuestInfo = new QuestDialogueInfo;
        pQuestInfo->pQuest = apQuest;
        reinterpret_cast<::Callees *>((((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)this)->GetDiffuseColor()))))->FUN_00905820((void *)&(pQuestInfo));
    }

    return pQuestInfo;
}

struct FUN_00619a70_shell : public TESTopicInfo
{
    unsigned short FUN_00619a70();
};

// @fnv 0x00619a70
unsigned short FUN_00619a70_shell::FUN_00619a70()
{
    return this->m_uiInfoIndex;
}

struct FUN_00619b20_shell : public TESTopicInfo
{
    bool FUN_00619b20();
};

// @fnv 0x00619b20
bool FUN_00619b20_shell::FUN_00619b20()
{
    return (bool)(this->m_Data.flags & 4);
}

struct FUN_00619d00_shell : public TESTopic
{
    TESQuest* FindQuestForTopicInfo(TESTopicInfo*);
};

extern TESTopicInfo* __cdecl GetTopicInfoByIndex(QuestDialogueInfo*, unsigned int);

struct FUN_00619df0_shell : public TESTopic
{
    bool FUN_00619df0();
};
// Searches the topic's quest info list for apInfo and returns the owning quest, recursing into the remapped rumor topic when applicable.
// @fnv 0x00619d00
TESQuest* FUN_00619d00_shell::FindQuestForTopicInfo(TESTopicInfo* apInfo)
{
    if (!apInfo)
        return 0;

    if (reinterpret_cast<::FUN_00619df0_shell *>((void *)this)->FUN_00619df0())
        return reinterpret_cast<FUN_00619d00_shell*>(((::TESTopic *)(::fnv_0061a2d0::GetTopicSubTypeName((*(int *)&(const ::DIALOGUE_TYPE &)(DIALOGUE_TYPE_DT_CONVERSATION)), 5))))
            ->FindQuestForTopicInfo(apInfo);

    const BSSimpleList<QuestDialogueInfo*>* pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)this)->GetDiffuseColor()));
    unsigned int maxSize = 0;

    while (
        pList &&
        *reinterpret_cast<QuestDialogueInfo**>(
            ((::BSSimpleList< ::TESTopic *> *)((void *)(reinterpret_cast<TESTopicInfoData*>(const_cast<BSSimpleList<QuestDialogueInfo*>*>(pList)))))))
    {
        QuestDialogueInfo* pQuestInfo = *reinterpret_cast<QuestDialogueInfo**>(
            ((::BSSimpleList< ::TESTopic *> *)((void *)(reinterpret_cast<TESTopicInfoData*>(const_cast<BSSimpleList<QuestDialogueInfo*>*>(pList))))));
        pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((void *)(pList))->FUN_00726070()));

        maxSize = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((pQuestInfo))->GetCurrentProcessData())))))->FUN_0084e3a0()));
        if (maxSize)
        {
            for (unsigned int i = 0; i < maxSize; ++i)
            {
                TESTopicInfo* pInfo = GetTopicInfoByIndex(pQuestInfo, i);
                if (pInfo == apInfo)
                    return pQuestInfo->pQuest;
            }
        }
    }

    return 0;
}

// @fnv 0x00619df0
bool FUN_00619df0_shell::FUN_00619df0()
{
    return (this->m_Data.cFlags & 1) ? true : false;
}

TESTopicInfo* __cdecl GetTopicInfoByIndex(QuestDialogueInfo* apQuestInfo, unsigned int aiIndex);

struct FUN_00619e10_impl : public TESTopic
{
    TESTopicInfo* FindTopicInfoByFormID(unsigned int aiInfoID, bool abReverse);
};

// Scans the quest info list, searching each info array forward or backward for a TESTopicInfo whose FormID equals aiInfoID, and returns it or null.
// @fnv 0x00619e10
TESTopicInfo* FUN_00619e10_impl::FindTopicInfoByFormID(unsigned int aiInfoID, bool abReverse)
{
    BSSimpleList<QuestDialogueInfo*>* pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)this)->GetDiffuseColor()));
    unsigned int maxSize = 0;

    while (pList && (pList->m_item))
    {
        QuestDialogueInfo* pQuestInfo = (pList->m_item);
        pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        maxSize = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((pQuestInfo))->GetCurrentProcessData()))))->FUN_0084e3a0()));
        if (maxSize != 0)
        {
            if (abReverse)
            {
                for (int i = maxSize - 1; i >= 0; --i)
                {
                    TESTopicInfo* pInfo = GetTopicInfoByIndex(pQuestInfo, i);
                    if (pInfo && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pInfo))->FUN_0084e3a0())) == aiInfoID)
                    {
                        return pInfo;
                    }
                }
            }
            else
            {
                for (unsigned int i = 0; i < maxSize; ++i)
                {
                    TESTopicInfo* pInfo = GetTopicInfoByIndex(pQuestInfo, i);
                    if (pInfo && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pInfo))->FUN_0084e3a0())) == aiInfoID)
                    {
                        return pInfo;
                    }
                }
            }
        }
    }
    return 0;
}

// Returns the topic info at aiInfoIndex from apQuestInfo's info array if the index is in range, otherwise returns 0.
// @fnv 0x00619f20
TESTopicInfo* __cdecl GetTopicInfoByIndex(QuestDialogueInfo* apQuestInfo, unsigned int aiInfoIndex)
{
    if (!apQuestInfo)
        return 0;

    if (aiInfoIndex >= 0 && aiInfoIndex < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((apQuestInfo))->GetCurrentProcessData())))))->FUN_0084e3a0())))
        return ((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((apQuestInfo))->GetCurrentProcessData()))->GetAt(aiInfoIndex);
    else
        return 0;
}

struct TopicInfoStandin
{
};
// For each entry in apInfoArray up to its form ID, calls FUN_0061f340 on the entry with its index as a 16-bit value.
// @fnv 0x00619fe0
void FUN_00619fe0(TopicInfoArray* apInfoArray)
{
    if (apInfoArray)
    {
        unsigned int maxSize = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)apInfoArray)))->FUN_0084e3a0()));
        for (unsigned int i = 0; i < maxSize; i++)
        {
            TopicInfoStandin* pInfo = (TopicInfoStandin*)apInfoArray->GetAt(i);
            if (pInfo)
            {
                reinterpret_cast<::FUN_0061f340_shell *>((pInfo))->FUN_0061f340((unsigned short)i);
            }
        }
    }
}

class AutoMemContext
{
    int dummy;

  public:
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};

class TESGlobal;
class TESGlobalMap
{
  public:
};

struct FullNameEx
{
    int dummy;
};

struct TESTopicEx
{
    char pad1[0x14];
    FullNameEx fullName;
    char pad2[0x2c];

    TESTopicEx(int type);

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
    virtual void SetFormID(unsigned int id, bool bUpdate);
    virtual void v75();
    virtual void v76();
    virtual void SetEditorID(const char* id);
};

struct TopicDefaultEntry
{
    TESTopicEx* topic;
    unsigned int formID;
    const char* editorID;
};

struct DataHandlerEx
{
};


// @fnv 0x0061a040
void __cdecl CreateDefaultTopics()
{
    AutoMemContext memContext((MEM_CONTEXT)0x35, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESTopic.cpp", 0x1573);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < DAT_0119a41c[i]; j++)
        {
            if ((*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].topic == 0)
            {
                (*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].topic = new TESTopicEx(i);
                (*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].topic->SetFormID((*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].formID, true);
                (*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].topic->SetEditorID((*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].editorID);
                reinterpret_cast<::TESFullName *>(&((*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].topic->fullName))->SetFullName(
                    ((const char *)(::FUN_00464f30((std::intptr_t)((*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].editorID)))));
                reinterpret_cast<::FUN_00461780_cls *>(((*reinterpret_cast<::DataHandlerEx * *>(&::g_dataHandler))))->Method((int)((*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].topic));
                reinterpret_cast<::TMapStandIn *>((DAT_011c54c8))->InsertOrUpdate((unsigned int)((*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].editorID), (TESGlobal*)(*reinterpret_cast<TopicDefaultEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i][j].topic);
            }
        }
    }
}

namespace fnv_0061a2d0 {
struct TopicSubTypeEntry
{
    const char* name;
    int a;
    int b;
};


// Returns the name of the topic sub-type entry at index for the given type, or null if index is out of range.
// @fnv 0x0061a2d0
const char* __cdecl GetTopicSubTypeName(int type, int index)
{
    if (index < 0)
        return 0;
    if (index >= ::DAT_0119a41c[type])
        return 0;
    return (*reinterpret_cast<fnv_0061a2d0::TopicSubTypeEntry * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[type][index].name;
}
}  // namespace fnv_0061a2d0

namespace fnv_0061a310 {
class DataHandler;


struct TopicHelper
{
};

// Walks the data handler's topic list and returns the first TESTopic whose lookup of pInfo's form ID yields pInfo, else null.
// @fnv 0x0061a310
TESTopic* __cdecl FindTopicByInfo(TESTopicInfo* pTopicInfo)
{
    TESTopicInfoData* pList = ((::TESTopicInfoData *)(reinterpret_cast<::FUN_004612e0_shell *>(((*reinterpret_cast<::fnv_0061a310::DataHandler * *>(&::g_dataHandler))))->FUN_004612e0()));
    while (pList && *(TESTopic**)((::BSSimpleList< ::TESTopic *> *)((void *)(pList))))
    {
        TESTopic* pTopic = *(TESTopic**)((::BSSimpleList< ::TESTopic *> *)((void *)(pList)));
        pList = ((::TESTopicInfoData *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        if (reinterpret_cast<::FUN_00619e10_impl *>((((TopicHelper*)pTopic)))->FindTopicInfoByFormID(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pTopicInfo))->FUN_0084e3a0())), 0) == pTopicInfo)
        {
            return pTopic;
        }
    }
    return 0;
}
}  // namespace fnv_0061a310

bool __cdecl FUN_0061a450(TESTopic* pMenuTopicEntry, TESTopic* apTopic, bool abUsePriority);
bool _ref_008256d0(void* p);

struct SoundListView
{
};

// @fnv 0x0061a380
void __cdecl AddTopicToList(TESTopic* apTopic, BSSimpleList<TESTopic*>* apTopicList, bool abUsePriority)
{
    if (apTopic && apTopicList)
    {
        if (_ref_008256d0(apTopicList))
        {
            ((BSSimpleList<char const*>*)apTopicList)->AddHead((char const*&)apTopic);
        }
        else
        {
            BSSimpleList<TESTopic*>* pCurrentElementNext = apTopicList;
            while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
            {
                TESTopic* pMenuTopicEntry = *(TESTopic**)((::BSSimpleList< ::TESTopic *> *)((void *)(((TESTopicInfoData*)pCurrentElementNext))));
                if (pMenuTopicEntry == apTopic)
                    break;
                if (FUN_0061a450(pMenuTopicEntry, apTopic, abUsePriority))
                {
                    ((BSSimpleList<char const*>*)pCurrentElementNext)->AddHead((char const*&)apTopic);
                    break;
                }
                if (!((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070())))
                {
                    reinterpret_cast<::Callees *>((((SoundListView*)pCurrentElementNext)))->FUN_00905820((void *)&(apTopic));
                    break;
                }
                pCurrentElementNext = ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
            }
        }
    }
}


// Compares two TESTopic objects by priority (when abUsePriority) or by name, returning whether the first sorts before the second.
// @fnv 0x0061a450
bool __cdecl FUN_0061a450(TESTopic* apTopic1, TESTopic* apTopic2, bool abUsePriority)
{
    if (apTopic1 != 0 && apTopic2 != 0)
    {
        const char* topic1name = apTopic1->GetName();
        const char* topic2name = apTopic2->GetName();
        if (abUsePriority)
        {
            float fPriorityDiff = reinterpret_cast<::FUN_00526ae0_class *>((apTopic2))->FUN_00526ae0() - reinterpret_cast<::FUN_00526ae0_class *>((apTopic1))->FUN_00526ae0();
            if (fPriorityDiff > DAT_01030f28)
                return true;
            else if (FUN_0040eb10(fPriorityDiff, 0.0f, 0.001f))
            {
                if (*topic1name < *topic2name)
                    return true;
                else
                    return ::FUN_00404dc0(apTopic1->GetName(), apTopic2->GetName()) > 0;
            }
        }
        else
        {
            if (*topic1name < *topic2name)
                return true;
            else
                return ::FUN_00404dc0(apTopic1->GetName(), apTopic2->GetName()) > 0;
        }
    }
    return false;
}

struct FUN_0061a760_shell : public TESTopic
{
    TESTopicInfo* GetTopicInfo(bool& deferred, TESObjectREFR* speaker, TESObjectREFR* listener);
};
// Returns the topic info for the given speaker and listener by delegating to the topic info lookup with deferred output and no extra filters.
// @fnv 0x0061a760
TESTopicInfo* FUN_0061a760_shell::GetTopicInfo(bool& deferred, TESObjectREFR* speaker, TESObjectREFR* listener)
{
    return FindMatchingTopicInfo(deferred, speaker, listener, false, 0, 0);
}

// @fnv 0x0061aed0
bool IsFlag20Set(char* pThis)
{
    return (bool)(pThis[0x25] & 0x20);
}


// @fnv 0x0061b9d0
__int64 __cdecl GetTime64(__int64* pTime)
{
    return std::time((std::time_t *)(pTime));
}

// @fnv 0x0061b9f0
int GetSignedByteAtOffset36(signed char* pThis)
{
    return pThis[0x24];
}

namespace fnv_0061ba10 {
struct DataHandlerStandin
{
};
struct TopicStandin
{
    bool HasInfoForQuest(TESQuest* quest, int flag);
};
struct ConvStandin
{
};
// Walks the data handler's list of topics, testing each against apQuest and calling SortList, returning false as soon as one fails.
// @fnv 0x0061ba10
bool CheckTopicsForQuest(TESQuest* apQuest)
{
    bool result = true;
    TESTopicInfoData* pCurrentElementNext = ((::TESTopicInfoData *)(reinterpret_cast<::FUN_004612e0_shell *>(((*reinterpret_cast<::fnv_0061ba10::DataHandlerStandin * *>(&::g_dataHandler))))->FUN_004612e0()));
    while (pCurrentElementNext && *(TopicStandin**)((::BSSimpleList< ::TESTopic *> *)((void *)(pCurrentElementNext))) && result)
    {
        if (!apQuest || (*(TopicStandin**)((::BSSimpleList< ::TESTopic *> *)((void *)(pCurrentElementNext))))->HasInfoForQuest(apQuest, 0))
        {
            result = reinterpret_cast<::SortOwner *>(((*(TopicStandin**)((::BSSimpleList< ::TESTopic *> *)((void *)(pCurrentElementNext))))))->SortList();
        }
        pCurrentElementNext = ((::TESTopicInfoData *)(reinterpret_cast<::Callees *>((((ConvStandin*)pCurrentElementNext)))->FUN_00726070()));
    }
    return result;
}
}  // namespace fnv_0061ba10

struct FUN_0061bcd0_shell : public TESTopic
{
    void FUN_0061bcd0();
};


struct FUN_00619010_helper
{
};

// Clears the form's data via TESForm::ClearData, then passes DAT_01011584 to FUN_00619010 on this object.
// @fnv 0x0061bcd0
void FUN_0061bcd0_shell::FUN_0061bcd0()
{
    TESForm::ClearData();
    reinterpret_cast<::FUN_00619010_shell *>((reinterpret_cast<FUN_00619010_helper*>(this)))->FUN_00619010((char *)(int *)(&(*reinterpret_cast<int *>((void *)&::DAT_01011584))));
}


struct Dummy_0061bf20
{
    int* vtable;
};

// Sets the object's vtable to DAT_0104d458, calls FUN_006b3f40(0, 0), and returns the object.
// @fnv 0x0061bf20
Dummy_0061bf20* ConstructDummy(Dummy_0061bf20* apObject)
{
    apObject->vtable = &DAT_0104d458;
    reinterpret_cast<::FUN_006b3f40_Class *>((apObject))->FUN_006b3f40(0, 0);
    return apObject;
}

struct NavMeshPtr
{
    int p;
    ~NavMeshPtr();
};
struct S2f850
{
    unsigned int AppendValue(const NavMeshPtr&);
};
struct NavShell2 : public S2f850
{
    unsigned int FUN_00469500(NavMeshPtr apNavMesh);
};
// Calls AppendValue with apNavMesh and returns its result.
// @fnv 0x00469500
unsigned int NavShell2::FUN_00469500(NavMeshPtr apNavMesh)
{
    unsigned int ireturn = AppendValue(apNavMesh);
    return ireturn;
}

struct TopicFlagStandIn
{
    char pad[0x26];
    char flags;
    bool FUN_0061aef0();
};
// @fnv 0x0061aef0
bool TopicFlagStandIn::FUN_0061aef0()
{
    return (flags & 1) ? true : false;
}

struct SL
{
    int a;
    int b;
    SL();
    ~SL();
};
struct StrMem
{
    int a;
    int b;
    StrMem();
    ~StrMem();
};
struct SFTX
{
};
struct DDX
{
    unsigned char type;
    unsigned char flags;
};
struct SL_d0046ffb0 : SL
{
    ~SL_d0046ffb0();
};
struct FUN_00618580 : public TESForm, public TESFullName
{
    DDX m_Data;
    float m_fTopicParamB;
    SL_d0046ffb0 m_kQuestInfoList;
    StrMem m_kDummyPrompt;
    int m_iTopicFlags;
    StrMem cPrompt2;
    FUN_00618580(unsigned char aType);
    ~FUN_00618580();
};
// @fnv 0x00618580
FUN_00618580::FUN_00618580(unsigned char aType)
{
    ::FUN_00403d30(&m_Data, 0, sizeof(m_Data));
    m_iTopicFlags = 0;
    m_fTopicParamB = 50.0f;
    m_Data.type = aType;
    reinterpret_cast<::FUN_004f15a0_shell *>((((SFTX*)this)))->FUN_004f15a0(0x45);
}

namespace fnv_006189c0 {
struct FileStub
{
};
struct DHStub
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct TopicSaver
{
    bool SaveTopicInfo(FileStub* apFile);
};
// @fnv 0x006189c0
bool TopicSaver::SaveTopicInfo(FileStub* apFile)
{
    TESTopicInfo* info;
    unsigned int i4;
    unsigned int aMaxSize;
    TopicInfoArray* pArray;
    QuestDialogueInfo* pQuestInfo;
    bool mastersave;
    BSSimpleList<QuestDialogueInfo*>* pList6;

    ((TESTopic*)this)->SaveForm();
    reinterpret_cast<::FUN_00472fe0_cls *>((apFile))->RunProbe((::Fun472Param *)(void *)(this));
    mastersave = ((bool)(reinterpret_cast<::FUN_004600f0_class *>(((*reinterpret_cast<::fnv_006189c0::DHStub * *>(&::g_dataHandler))))->GetByteAt618()));
    pList6 = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)(((TESTopic*)this)))->GetDiffuseColor()));
    while (pList6 && (pList6->m_item))
    {
        pQuestInfo = (pList6->m_item);
        pList6 = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((pList6))->FUN_00726070()));
        pArray = ((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((pQuestInfo))->GetCurrentProcessData()));
        aMaxSize = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)pArray)))->FUN_0084e3a0()));
        for (i4 = 0; i4 < aMaxSize; ++i4)
        {
            info = (TESTopicInfo*)*((Arr*)pArray)->GetAt(i4);
            if (info)
                reinterpret_cast<::FUN_00460270_cls *>(((*reinterpret_cast<::fnv_006189c0::DHStub * *>(&::g_dataHandler))))->FUN_00460270((::TESForm *)(info), reinterpret_cast<::TESFile *>((apFile))->IsMasterFile());
        }
    }
    return true;
}
}  // namespace fnv_006189c0

namespace fnv_0061a270 {

// For each of 8 tables, zeroes the first int of every 12-byte entry up to the table's count in DAT_0119a41c.
// @fnv 0x0061a270
void ClearTableEntries()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < ::DAT_0119a41c[i]; ++j)
        {
            *(int*)((char*)DAT_0119a43c[i] + j * 12) = 0;
        }
    }
}
}  // namespace fnv_0061a270

struct TESFaction_RankDataView
{
public:
    bool FUN_00455620();
};

struct FUN_0061af10_shell : TESFaction_RankDataView
{
    bool HasFlag4();
};

// @fnv 0x0061af10
bool FUN_0061af10_shell::HasFlag4()
{
    return (*((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField())) & 4) != 0;
}

struct BSStr
{
};
struct BSStringT_char
{
};
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
struct TESTopic_shell
{
    bool SetStringIfDifferent(const char*);
};
// @fnv 0x006184f0
bool TESTopic_shell::SetStringIfDifferent(const char* apString)
{
    char* p2;
    unsigned int n = ::FUN_0044a670(apString) + 1;
    p2 = (char*)_alloca(n);
    TaskQueueInterface::CopyStringToBuffer(p2, n, apString);
    if (reinterpret_cast<::B408A80String *>((void *)(((BSStringT_char*)((char*)this + 0x40))))->FUN_00408a80(p2, true) == 0)
        return false;
    reinterpret_cast<::TextString *>((((BSStr*)((char*)this + 0x40))))->FUN_004037f0(p2, 0);
    return true;
}

struct Holder6186a0
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_006186d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006186a0
void* Holder6186a0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_006186d0 *>(this)->FUN_006186d0::~FUN_006186d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_00618960_obj
{
    char _pad[0x3C];
    unsigned int unk3C;
    void InitLoadingTopic();
};
// @fnv 0x00618960
void FUN_00618960_obj::InitLoadingTopic()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    ::FUN_00485910(0x58444958, unk3C);
    g_loadingTopic = (TESTopic*)this;
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

namespace fnv_00619a90 {
struct FUN_00619f70_shell
{
    unsigned int* FindQuestInfoArray(unsigned int);
};
struct FUN_0061f280_shell
{
};
struct FUN_00619b20_shell
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct BSTempEffectDebris
{
};
struct FUN_00619a90_shell
{
    void ProcessTopicInfoList(unsigned int param);
};

// Retrieves a list for param, then for each entry calls FUN_00619b20 and, if true and IsNew, calls FUN_0061f280.
// @fnv 0x00619a90
void FUN_00619a90_shell::ProcessTopicInfoList(unsigned int param)
{
    unsigned int* list = ((FUN_00619f70_shell*)this)->FindQuestInfoArray(param);
    if (list)
    {
        unsigned int count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)list)))->FUN_0084e3a0()));
        unsigned int i = 0;
        for (; i < count; ++i)
        {
            TESTopicInfo* info = *(TESTopicInfo**)((Arr*)list)->GetAt(i);
            if (info && reinterpret_cast<::FUN_00619b20_shell *>((((FUN_00619b20_shell*)info)))->FUN_00619b20() && reinterpret_cast<::BSTempEffectDebris *>((((BSTempEffectDebris*)info)))->ShouldDelete())
                reinterpret_cast<::FUN_0061f280_This *>((((FUN_0061f280_shell*)info)))->FUN_0061f280();
        }
    }
}
}  // namespace fnv_00619a90

namespace fnv_0061a720 {
struct FUN_0061a760_shell
{
};
struct FUN_0061a720_shell : FUN_0061a760_shell
{
    TESTopicInfo* FUN_0061a720(MobileObject*, PlayerCharacter*);
};
// Calls GetTopicInfo with speaker and listener; returns its TESTopicInfo unless the deferred flag was set, in which case returns null.
// @fnv 0x0061a720
TESTopicInfo* FUN_0061a720_shell::FUN_0061a720(MobileObject* speaker, PlayerCharacter* listener)
{
    bool deferred = false;
    TESTopicInfo* info;
    info = reinterpret_cast<::FUN_0061a760_shell *>(this)->GetTopicInfo(deferred, speaker, listener);
    if (deferred)
        return 0;
    else
        return info;
}
}  // namespace fnv_0061a720

struct FUN_0061b320_shell : public TESTopic
{
    DialogueItem* FUN_0061b320(TESObjectREFR*, TESObjectREFR*, TESTopic*, void*, bool);
};

struct FUN_0083c520
{
    char data[0x1c];
    FUN_0083c520(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo, TESObjectREFR* apSpeaker);
};
struct TopicInfo_Ext
{
    TESQuest* FUN_006733e0();
};
// @fnv 0x0061b320
DialogueItem* FUN_0061b320_shell::FUN_0061b320(TESObjectREFR* apSpeaker, TESObjectREFR* apTarget,
                                               TESTopic* apPreviousTopic, void* apConversationList, bool abRunImmediate)
{
    bool bIgnoreMe;
    TESTopicInfo* info = FindMatchingTopicInfo(bIgnoreMe, apSpeaker, apTarget, true, apPreviousTopic,
                                               (BSSimpleList<DialogueItem*>*)apConversationList);
    if (info)
    {
        DialogueItem* pDialogueItem =
            (DialogueItem*)new FUN_0083c520(((TopicInfo_Ext*)info)->FUN_006733e0(), this, info, apSpeaker);
        if (abRunImmediate && pDialogueItem && ((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pDialogueItem))->FUN_0084e3a0())) &&
            FUN_00579200((char const*)((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pDialogueItem))->FUN_0084e3a0()))))
        {
            reinterpret_cast<::FUN_0061f170_cls *>((((TopicInfo_Ext*)((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pDialogueItem))->FUN_0084e3a0())))))->FUN_0061f170((void *)(false), (::ArgObj *)(apSpeaker));
            reinterpret_cast<::TESTopicInfo *>((((TopicInfo_Ext*)((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pDialogueItem))->FUN_0084e3a0())))))->AddTopicList();
        }
        return pDialogueItem;
    }
    else
    {
        return 0;
    }
}

namespace fnv_00618aa0 {

struct TESFileRef
{
    bool _ref_004727f0(void*);
};

struct ArrSI
{
};
struct TESConditionItem
{
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct NiTLargeArraySetSizeHelper
{
    void SetSize(unsigned int);
};
struct ArrX
{
};
struct TopicDefaultEntryX
{
    void* pTopic;
    int unk;
    const char* pName;
};

struct ParentSpaceNode
{
    int a;
    int b;
    int c;
};
struct NavMeshTriangleEdgeReference
{
    int a;
    int b;
    int c;
};
}  // namespace fnv_00618aa0

template <> class BSSimpleArray<fnv_00618aa0::NavMeshTriangleEdgeReference, 1024>
{
  public:
    unsigned int Add(const fnv_00618aa0::NavMeshTriangleEdgeReference&);
};

namespace fnv_00618aa0 {
typedef BSSimpleArray<ParentSpaceNode, 1024> PSNArr;
struct FUN_006195d0_shell : public TESTopic
{
};
struct FUN_00619010_shell : public TESTopic
{
};


struct FUN_00618aa0_t : public TESTopic
{
    bool FUN_00618aa0(::TESFile* pFile);
};

// @fnv 0x00618aa0
bool FUN_00618aa0_t::FUN_00618aa0(::TESFile* pFile)
{
    unsigned char formid = (unsigned char)reinterpret_cast<::FUN_00472660_shell *>((((TESFileRef*)pFile)))->FUN_00472660();
    QuestDialogueInfo* pLastQuestInfo = 0;
    if (formid != 0x45)
        return false;

    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(pFile));

    BSSimpleList<QuestDialogueInfo*>* pQuestInfoList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)this)->GetDiffuseColor()));
    while (pQuestInfoList && *(int*)((::BSSimpleList< ::TESTopic *> *)((void *)(((TESTopicInfoData*)pQuestInfoList)))) != 0)
    {
        QuestDialogueInfo* pQuestInfo = *(QuestDialogueInfo**)((::BSSimpleList< ::TESTopic *> *)((void *)(((TESTopicInfoData*)pQuestInfoList))));
        if (pQuestInfo)
        {
            reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)pQuestInfo + 0x1c))))->Clear(true);
        }
        pQuestInfoList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((void *)(pQuestInfoList))->FUN_00726070()));
    }

    int chunkid;
    while ((chunkid = reinterpret_cast<::FUN_004726b0_class *>((((TESFileRef*)pFile)))->FUN_004726b0()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pEditorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((((TESFileRef*)pFile)))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((TESFileRef*)pFile)))->FUN_00472890((char *)(pEditorID), 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(pFile);
            break;
        case 0x4c4c5546:
            ::ReadFullName((::TESFullName *)(void *)(this ? (void*)&tESFullNameComponent : 0), pFile);
            break;
        case 0x49545351: {
            unsigned int uiChunkType = 0;
            ((TESFileRef*)pFile)->_ref_004727f0(&uiChunkType);
            ::ResolveFormID((unsigned int *)&(uiChunkType), GetFile(-1));
            QuestDialogueInfo* pQuestInfo = reinterpret_cast<::FUN_006195d0_shell *>((((FUN_006195d0_shell*)this)))->GetOrCreateQuestInfo((TESQuest*)uiChunkType, false);
            if (pQuestInfo)
            {
                pLastQuestInfo = pQuestInfo;
                unsigned int uiOldSize = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((pQuestInfo))->GetCurrentProcessData())))))->GetName()));
                ((NiTLargeArraySetSizeHelper*)((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((pQuestInfo))->GetCurrentProcessData())))->SetSize(uiOldSize + 100);
                reinterpret_cast<::FUN_00600ab0_shell *>((((TESConditionItem*)((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((pQuestInfo))->GetCurrentProcessData())))))->FUN_00600ab0(10);
            }
            break;
        }
        case 0x43464e49: {
            unsigned int infoID = 0;
            ((TESFileRef*)pFile)->_ref_004727f0(&infoID);
            ::ResolveFormID((unsigned int *)&(infoID), GetFile(-1));
            if (pLastQuestInfo)
            {
                INFO_LINK_ELEMENT infolink;
                infolink.pInfo = 0;
                infolink.nID = infoID;
                infolink.m_iIndex = -1;
                reinterpret_cast<::FUN_006cf4c0_Array *>((((BSSimpleArray<NavMeshTriangleEdgeReference, 1024>*)((char*)pLastQuestInfo + 0x1c))))->FUN_006cf4c0((const ::ParentSpaceNode &)(*(NavMeshTriangleEdgeReference*)&infolink));
            }
            break;
        }
        case 0x58464e49: {
            int m_iIndex = -1;
            ((TESFileRef*)pFile)->_ref_004727f0(&m_iIndex);
            if (pLastQuestInfo)
            {
                int IdxJustAdded;
                if ((IdxJustAdded = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)pLastQuestInfo + 0x1c))))->GetName())) - 1) >= 0)
                {
                    ((PSNArr*)((char*)pLastQuestInfo + 0x1c))->GetAt(IdxJustAdded).c = m_iIndex;
                    int size = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)pLastQuestInfo + 0x1c))))->GetName()));
                    for (int iter = 0; iter < IdxJustAdded; iter++)
                    {
                        if (*(int*)&((PSNArr*)((char*)pLastQuestInfo + 0x1c))->GetAt(iter) ==
                            *(int*)&((PSNArr*)((char*)pLastQuestInfo + 0x1c))->GetAt(IdxJustAdded))
                        {
                            ((PSNArr*)((char*)pLastQuestInfo + 0x1c))->GetAt(iter).c = m_iIndex;
                            reinterpret_cast<::FUN_0061bf70_Class *>((((ArrX*)((char*)pLastQuestInfo + 0x1c))))->FUN_0061bf70(IdxJustAdded, 1);
                            break;
                        }
                    }
                }
            }
            break;
        }
        case 0x4d414e50:
            ((TESFileRef*)pFile)->_ref_004727f0(&m_fTopicParamB);
            break;
        case 0x4d554454: {
            char szBuffer[256];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((TESFileRef*)pFile)))->FUN_00472890((char *)(szBuffer), 0x100);
            reinterpret_cast<::FUN_00619010_shell *>((((FUN_00619010_shell*)this)))->FUN_00619010(szBuffer);
            break;
        }
        case 0x41544144:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((((TESFileRef*)pFile)))->FUN_00472890((char *)(void *)(&m_Data), 2);
            break;
        case 0x58444958:
            ((TESFileRef*)pFile)->_ref_004727f0(&m_iTopicFlags);
            break;
        }
        if (!reinterpret_cast<::TESFile *>((((TESFileRef*)pFile)))->NextChunk())
            break;
    }

    if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) <= 0x7ff)
    {
        for (unsigned int i = 0; i < 8; i++)
        {
            for (unsigned int j = 0; j < (unsigned int)::DAT_0119a41c[i]; j++)
            {
                if (((TopicDefaultEntryX*)(*reinterpret_cast<void * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i])[j].pTopic == this)
                {
                    m_Data.type = (char)i;
                    SetEditorID_AtRuntime(((TopicDefaultEntryX*)(*reinterpret_cast<void * (*)[]>(&::fnv_0061a270::DAT_0119a43c))[i])[j].pName);
                }
            }
        }
    }

    SetInitializationState(false);
    ::g_loadingTopic = this;
    return true;
}
}  // namespace fnv_00618aa0

struct FUN_00484020_shell
{
};
int FNV_GetFormType(TESForm*);
struct FUN_00619430_shell : TESTopic
{
    bool FUN_00619430(TESForm* apForm);
};
// @fnv 0x00619430
bool FUN_00619430_shell::FUN_00619430(TESForm* apForm)
{
    bool bResult = false;
    switch (FNV_GetFormType(apForm))
    {
    case 0x46: {
        TESTopicInfo* pTopicInfo = dynamic_cast<TESTopicInfo*>(apForm);
        if (pTopicInfo)
        {
            TESTopic* pMenuTopicEntry = ::fnv_0061a310::FindTopicByInfo(pTopicInfo);
            if (pMenuTopicEntry)
            {
                if (pMenuTopicEntry == this)
                    bResult = true;
                else
                    bResult = Sort(pMenuTopicEntry);
            }
        }
    }
    break;
    case 0x45: {
        TESTopic* pothertopic = dynamic_cast<TESTopic*>(apForm);
        if (pothertopic && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pothertopic))->FUN_0084e3a0())))
            bResult = true;
    }
    break;
    default:
        bResult = reinterpret_cast<::TESFormSortProxy *>((((FUN_00484020_shell*)this)))->IsLessThan(apForm);
        break;
    }
    return bResult;
}

TESTopicInfo* __cdecl GetTopicInfoByIndex(QuestDialogueInfo* info, unsigned int index);

struct FUN_00619c50_shell : TESTopic
{
    TESTopic* FindTopicByInfoID(unsigned int topicID);
};

// @fnv 0x00619c50
TESTopic* FUN_00619c50_shell::FindTopicByInfoID(unsigned int topicID)
{
    BSSimpleList<QuestDialogueInfo*>* pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)this)->GetDiffuseColor()));
    unsigned int count_2 = 0;
    while (pList && (pList->m_item))
    {
        QuestDialogueInfo* pInfo = (pList->m_item);
        pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        count_2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((pInfo))->GetCurrentProcessData())))))->FUN_0084e3a0()));
        if (count_2)
        {
            for (unsigned int i = 0; i < count_2; ++i)
            {
                TESTopicInfo* result = GetTopicInfoByIndex(pInfo, i);
                if (result == reinterpret_cast<TESTopicInfo*>(topicID))
                    return reinterpret_cast<TESTopic*>(pInfo);
            }
        }
    }
    return 0;
}

namespace fnv_0061a5a0 {
struct DH;
struct FUN_004612e0_shell
{
};
struct ListX
{
    ~ListX();
};
struct SL : ListX
{
    SL();
    void* m_item;
    void* m_next;
};
struct G2
{
    void AddHead(int*);
};
struct GridArray
{
};
struct ItemList
{
    void FUN_0063f7b0();
};
struct VATSCommand;
struct VATS_CommandList
{
};
bool _ref_008256d0(void*);
struct TopicSort_0061a5a0
{
};

// Sorts the topic list by priority, moving out-of-order topics into a temporary list and reinserting them via AddTopicToList.
// @fnv 0x0061a5a0
void SortTopicList(bool abSortByPriority, BSSimpleList<TESTopic*>* apTopicList)
{
    BSSimpleList<TESTopic*>* pBaseList = apTopicList;
    if (!pBaseList)
        pBaseList = (BSSimpleList<TESTopic*>*)reinterpret_cast<::FUN_004612e0_shell *>((((FUN_004612e0_shell*)(*reinterpret_cast<::fnv_0061a5a0::DH * *>(&::g_dataHandler)))))->FUN_004612e0();
    SL sortlist;
    BSSimpleList<TESTopic*>* pCurrentElementNext = pBaseList;
    BSSimpleList<TESTopic*>* plastlist = 0;
    while (pCurrentElementNext && (*(TESTopic**)((::BSSimpleList< ::TESTopic *> *)((void *)(((TESTopicInfoData*)(pCurrentElementNext)))))))
    {
        bool badvanced = false;
        if (((BSSimpleList<TESTopic*>*)((std::intptr_t)(reinterpret_cast<::Callees *>((void *)(((GridArray*)(pCurrentElementNext))))->FUN_00726070()))))
        {
            TESTopic* ptopic1 = (*(TESTopic**)((::BSSimpleList< ::TESTopic *> *)((void *)(((TESTopicInfoData*)(pCurrentElementNext))))));
            TESTopic* ptopic2 =
                (*(TESTopic**)((::BSSimpleList< ::TESTopic *> *)((void *)(((TESTopicInfoData*)(((BSSimpleList<TESTopic*>*)((std::intptr_t)(reinterpret_cast<::Callees *>((void *)(((GridArray*)(pCurrentElementNext))))->FUN_00726070())))))))));
            if (::FUN_0061a450(ptopic1, ptopic2, abSortByPriority))
            {
                if (plastlist)
                {
                    reinterpret_cast<::ItemChangeListNode *>((((VATS_CommandList*)plastlist)))->FUN_00905330((::InventoryStackRecord *const &)((VATSCommand* const&)ptopic1));
                    pCurrentElementNext = ((BSSimpleList<TESTopic*>*)((std::intptr_t)(reinterpret_cast<::Callees *>((void *)(((GridArray*)(plastlist))))->FUN_00726070())));
                }
                else
                {
                    ((ItemList*)pCurrentElementNext)->FUN_0063f7b0();
                }
                ((G2*)&sortlist)->AddHead((int*)&ptopic1);
                badvanced = true;
            }
        }
        if (!badvanced)
        {
            plastlist = pCurrentElementNext;
            pCurrentElementNext = ((BSSimpleList<TESTopic*>*)((std::intptr_t)(reinterpret_cast<::Callees *>((void *)(((GridArray*)(pCurrentElementNext))))->FUN_00726070())));
        }
    }
    while (!_ref_008256d0(&sortlist))
    {
        TESTopic* pMenuTopicEntry = (*(TESTopic**)((::BSSimpleList< ::TESTopic *> *)((void *)(((TESTopicInfoData*)(&sortlist))))));
        ((ItemList*)&sortlist)->FUN_0063f7b0();
        ::AddTopicToList(pMenuTopicEntry, pBaseList, abSortByPriority);
    }
}
}  // namespace fnv_0061a5a0

struct FUN_00619bc0_shell : TESTopic
{
    bool HasInfoForQuest(TESQuest* apQuest, bool apCheck);
};

// Scans the quest info list for an entry whose pQuest matches apQuest and returns whether its info array form ID is positive, or true when apCheck is false.
// @fnv 0x00619bc0
bool FUN_00619bc0_shell::HasInfoForQuest(TESQuest* apQuest, bool apCheck)
{
    if (!apQuest)
        return false;
    BSSimpleList<QuestDialogueInfo*>* pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)this)->GetDiffuseColor()));
    while (pList && (pList->m_item))
    {
        QuestDialogueInfo* pInfo = (pList->m_item);
        pList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        if (pInfo->pQuest == apQuest)
        {
            return ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((pInfo))->GetCurrentProcessData())))))->FUN_0084e3a0())) > 0 || !apCheck;
        }
    }
    return false;
}

struct FUN_00619f70_shell : public TESTopic
{
    TopicInfoArray* FindQuestInfoArray(TESTopicInfo* apInfo);
};

// @fnv 0x00619f70
TopicInfoArray* FUN_00619f70_shell::FindQuestInfoArray(TESTopicInfo* apInfo)
{
    BSSimpleList<QuestDialogueInfo*>* list = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)this)->GetDiffuseColor()));
    while (list && (list->m_item))
    {
        QuestDialogueInfo* info = (list->m_item);
        list = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
        if (info->pQuest == (TESQuest*)apInfo && (apInfo || !info->m_pAlternateQuest))
            return ((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((info))->GetCurrentProcessData()));
    }
    return 0;
}

struct FUN_006189a0_target
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
    virtual void Forward(int a);
};

struct FUN_006189a0_cls
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
    virtual void Forward(int a);
    void FUN_006189a0(int a);
};

// @fnv 0x006189a0
void FUN_006189a0_cls::FUN_006189a0(int a)
{
    Forward(a);
}

class FUN_00935a40_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00935a40_cls* m_pFirstNode;


    bool HasEntryWithKey(std::intptr_t key);
};
// Picks a TESTopicInfo from the topic's quest info lists, honoring conditions, history, filters and random selection, and reports deferred info via deferred.
// Scans quest topic info for dialogue candidates, applies link and history checks, and may return a deferred or randomly selected candidate.
// @fnv 0x0061a7d0
TESTopicInfo* TESTopic::FindMatchingTopicInfo(const TESTopic* originalTopic, bool& deferred, TESObjectREFR* speaker,
                                              TESObjectREFR* listener, bool filter, TESTopic* previousTopic,
                                              BSSimpleList<DialogueItem*>* history)
{
    const TESTopic* pTopic = originalTopic;
    if (pTopic && reinterpret_cast<::FUN_00619df0_shell *>((void *)(pTopic))->FUN_00619df0())
        pTopic = ((::TESTopic *)(::fnv_0061a2d0::GetTopicSubTypeName((*(int *)&(const ::DIALOGUE_TYPE &)(DIALOGUE_TYPE_DT_CONVERSATION)), kRemappedRumorsSubtype)));
    deferred = false;
    if (!pTopic || reinterpret_cast<::FUN_00440d80_shell *>((void *)(pTopic))->FUN_00440d80())
        return 0;
    TESTopicInfo* usedCandidate = 0;
    BSSimpleList<TESTopicInfo*> listRandomInfos;
    unsigned int randomCount = 0;
    bool bWasPlaying = false;
    BSSimpleList<QuestDialogueInfo*>* pQuestInfoList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)(pTopic))->GetDiffuseColor()));
    TESTopicInfo* lastDeferredInfo = 0;
    while (pQuestInfoList && (pQuestInfoList->m_item) && !bWasPlaying)
    {
        QuestDialogueInfo* questInfo = (pQuestInfoList->m_item);
        TESQuest* quest = questInfo->pQuest;
        pQuestInfoList = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((pQuestInfoList))->FUN_00726070()));
        if (quest && reinterpret_cast<::TESFaction_RankDataView *>((quest))->FUN_00455620() && quest->GetConditions()->ContainsTrait(speaker, listener))
        {
            TopicInfoArray sortedArray;
            TopicInfoArray* pSourceArray = ((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()));
            unsigned int sourceCount = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pSourceArray))->FUN_0084e3a0()));
            for (unsigned int sourceIndex = 0; sourceIndex < sourceCount; sourceIndex++)
                reinterpret_cast<::S00863d90 *>(&(sortedArray))->FUN_00863d90((const unsigned int &)(pSourceArray->GetAt(sourceIndex)));
            unsigned int linkSize = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(questInfo->m_kInfoLinks))->GetName()));
            for (unsigned int linkIndex = 0; linkIndex < linkSize; linkIndex++)
            {
                if (questInfo->m_kInfoLinks.GetAt(linkIndex).pInfo)
                {
                    int desiredIndex = questInfo->m_kInfoLinks.GetAt(linkIndex).m_iIndex;
                    if (desiredIndex < 0 || static_cast<unsigned int>(desiredIndex) > ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(sortedArray))->FUN_0084e3a0())))
                        desiredIndex = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(sortedArray))->FUN_0084e3a0()));
                    reinterpret_cast<::NiFormArray *>(&(sortedArray))->SetFormAtIndex(desiredIndex, (::TESForm *)(questInfo->m_kInfoLinks.GetAt(linkIndex).pInfo));
                }
            }
            unsigned int currentIndex = 0;
            TESTopicInfo* pTopicInfo = 0;
            if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(sortedArray))->FUN_0084e3a0())) > currentIndex)
                pTopicInfo = sortedArray.GetAt(currentIndex);
            while (pTopicInfo)
            {
                bool bDeferred = false;
                bool bAllowed = true;
                if (pTopicInfo && reinterpret_cast<::TopicFlagStandIn *>((pTopicInfo))->FUN_0061aef0() && speaker->IsMobileObject())
                {
                    MobileObject* mobileSpeaker = static_cast<MobileObject*>(speaker);
                    if (reinterpret_cast<::FUN_00935a40_cls *>((mobileSpeaker))->HasEntryWithKey((std::intptr_t)(pTopicInfo)))
                        bAllowed = false;
                }
                if (pTopicInfo && bAllowed && reinterpret_cast<::FUN_0061e600_t *>((pTopicInfo))->FUN_0061e600(bDeferred, 0, speaker, listener))
                {
                    deferred = false;
                    bool select = true;
                    if (filter || (previousTopic && previousTopic->GetDialogueType() == DIALOGUE_TYPE_DT_TOPIC))
                    {
                        TESTopicInfoData* conversationData = ((::TESTopicInfoData *)(::GetField38((char *)(pTopicInfo))));
                        if (conversationData)
                        {
                            if (previousTopic)
                            {
                                select = false;
                                BSSimpleList<TESTopic*>* topicNode = ((::BSSimpleList< ::TESTopic *> *)((void *)(conversationData)));
                                while (topicNode && !topicNode->IsEmpty())
                                {
                                    if ((topicNode->m_item) == previousTopic ||
                                        ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((topicNode->m_item)))->FUN_0084e3a0())) == kAnyPreviousTopicFormID)
                                    {
                                        select = true;
                                        break;
                                    }
                                    topicNode = ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((topicNode))->FUN_00726070()));
                                }
                                if (!filter && topicNode && topicNode->IsEmpty())
                                    select = true;
                            }
                            else if (!((::BSSimpleList< ::TESTopic *> *)((void *)(conversationData)))->IsEmpty() && listener != ::_g_thePlayer)
                                select = false;
                        }
                        if (select)
                        {
                            if (::IsFlag20Set((char *)(pTopicInfo)))
                                bWasPlaying = true;
                            BSSimpleList<DialogueItem*>* historyNode = history;
                            while (historyNode && !historyNode->IsEmpty())
                            {
                                DialogueItem* dialogue = (historyNode->m_item);
                                if (((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((dialogue))->FUN_0084e3a0())) == pTopicInfo)
                                {
                                    usedCandidate = pTopicInfo;
                                    select = false;
                                    break;
                                }
                                if (!reinterpret_cast<::FUN_0061af10_shell *>((questInfo->pQuest))->HasFlag4() &&
                                    ((::TESQuest *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((dialogue))->FUN_00825c00())) == questInfo->pQuest &&
                                    ((::TESTopic *)(reinterpret_cast<::MagicCaster_shell *>((dialogue))->FUN_0044edb0())) == originalTopic)
                                {
                                    usedCandidate = pTopicInfo;
                                    select = false;
                                    break;
                                }
                                historyNode = ((::BSSimpleList< ::DialogueItem *> *)(reinterpret_cast<::Callees *>((historyNode))->FUN_00726070()));
                            }
                        }
                    }
                    if (select)
                    {
                        if (::IsFlag20Set((char *)(pTopicInfo)))
                            bWasPlaying = true;
                        if (listRandomInfos.IsEmpty() && !::FUN_00619410((const char *)(pTopicInfo)))
                            return pTopicInfo;
                        else
                        {
                            if (!::FUN_00619410((const char *)(pTopicInfo)))
                            {
                                bWasPlaying = true;
                                break;
                            }
                            else
                            {
                                listRandomInfos.AddHead(pTopicInfo);
                                randomCount++;
                            }
                        }
                    }
                }
                if (!filter && bDeferred)
                {
                    lastDeferredInfo = pTopicInfo;
                    deferred = true;
                }
                if (bWasPlaying)
                    break;
                currentIndex++;
                if (currentIndex < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(sortedArray))->FUN_0084e3a0())))
                    pTopicInfo = sortedArray.GetAt(currentIndex);
                else
                    pTopicInfo = 0;
            }
        }
    }
    if (listRandomInfos.IsEmpty())
    {
        if (filter)
            return 0;
        else
            return lastDeferredInfo;
    }
    else
    {
        int randomChoice = randomCount ? DialogueRandom() % randomCount + 1 : 0;
        int seen = 0;
        BSSimpleList<TESTopicInfo*>* pCandidate = &listRandomInfos;
        TESTopicInfo* result = 0;
        TESTopicInfo* pSelectedInfo = 0;
        while (seen < randomChoice && pCandidate)
        {
            pSelectedInfo = (pCandidate->m_item);
            if (pSelectedInfo)
            {
                result = pSelectedInfo;
                seen++;
            }
            pCandidate = ((::BSSimpleList< ::TESTopicInfo *> *)(reinterpret_cast<::Callees *>((pCandidate))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>(&(listRandomInfos))->RemoveAll();
        return result;
    }
}

// Walks the entry list reached through FUN_00574900/FUN_005e3fa0/FUN_005d43c0/FUN_0042efe0 and returns true if any entry's unk00 equals key.
// @fnv 0x00935a40
bool FUN_00935a40_cls::HasEntryWithKey(std::intptr_t key)
{
    FUN_00935a40_cls* res = 0;
    if (((bool)(::FUN_00574900((const unsigned char *)(this)))))
    {
        res = ((::FUN_00935a40_cls *)(reinterpret_cast<::FUN_0042efe0_cls *>((((::FUN_00935a40_cls *)(reinterpret_cast<::FUN_005d43c0_ *>((((::FUN_00935a40_cls *)(reinterpret_cast<::DialogueItem *>((this))->SelectDefaultResponseList()))))->FUN_005d43c0()))))->FUN_0042efe0()));
    }
    else
    {
        res = ((::FUN_00935a40_cls *)(reinterpret_cast<::FUN_0042efe0_cls *>((((::FUN_00935a40_cls *)(reinterpret_cast<::FUN_005d43c0_ *>((this))->FUN_005d43c0()))))->FUN_0042efe0()));
    }
    if (res != 0)
    {
        FUN_00935a40_cls* cur = res->m_pFirstNode;
        while (cur != 0 && *((::FUN_00935a40_cls **)((void *)(cur))) != 0)
        {
            FUN_00935a40_cls* item = *((::FUN_00935a40_cls **)((void *)(cur)));
            if (item->unk00 == key)
            {
                return true;
            }
            cur = ((::FUN_00935a40_cls *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
        }
    }
    return false;
}

namespace fnv_00619030 {


struct BSSimpleArray_Helper
{
};

struct NiTLargeArray_TESTopicInfo
{
    void Compact();
    void SetSize(unsigned int size);
};

struct TopicInfoStandin : public TESTopicInfo
{
};

struct PlayerCharacter_Helper : public PlayerCharacter
{
};

struct TESTopic_Shell : public TESTopic
{
    void InitializeTopic();
};

// Initializes the topic's quest info entries, resolves their quests and infos, compacts the info arrays, and notifies the player if the topic is random.
// @fnv 0x00619030
void TESTopic_Shell::InitializeTopic()
{
    if (GetInitialized())
        return;

    BSSimpleList<QuestDialogueInfo*>* pIter = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::TESRegion *>((void *)this)->GetDiffuseColor()));
    BSSimpleList<QuestDialogueInfo*>* prev = 0;
    while (pIter && (pIter->m_item))
    {
        QuestDialogueInfo* questInfo = (pIter->m_item);
        TopicInfoArray* array;
        if (questInfo)
        {
            if (!questInfo->bInitialized)
            {
                int count = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(questInfo->m_kInfoLinks))->GetName()));
                for (int i = 0; i < count; i++)
                {
                    unsigned int formID = questInfo->m_kInfoLinks.GetAt(i).nID;
                    TESTopicInfo* pTopicInfo = dynamic_cast<TESTopicInfo*>(::FUN_004839c0(formID));
                    questInfo->m_kInfoLinks.GetAt(i).pInfo = pTopicInfo;
                    if (pTopicInfo)
                    {
                        unsigned int index;
                        bool bFound = false;
                        for (index = 0; index < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))))->FUN_0084e3a0())); index++)
                        {
                            if (((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))->GetAt(index) == pTopicInfo)
                            {
                                bFound = true;
                                break;
                            }
                        }
                        if (bFound)
                        {
                            reinterpret_cast<::FUN_0061bf70_Class *>((((BSSimpleArray_Helper*)&questInfo->m_kInfoLinks)))->FUN_0061bf70(i, true);
                            count--;
                            i--;
                        }
                    }
                    else
                    {
                        std::uintptr_t uiChunkType = (std::uintptr_t)questInfo->pQuest;
                        TESQuest* quest = dynamic_cast<TESQuest*>(::FUN_004839c0(uiChunkType));
                        reinterpret_cast<::FUN_0061bf70_Class *>((((BSSimpleArray_Helper*)&questInfo->m_kInfoLinks)))->FUN_0061bf70(i, true);
                        count--;
                        i--;
                    }
                }

                if (questInfo->pQuest)
                {
                    std::uintptr_t uiChunkType = (std::uintptr_t)questInfo->pQuest;
                    questInfo->pQuest = dynamic_cast<TESQuest*>(::FUN_004839c0(uiChunkType));
                }
                else if (questInfo->m_pAlternateQuest)
                {
                    unsigned int formID = (unsigned int)(std::uintptr_t)questInfo->m_pAlternateQuest;
                    ::ResolveFormID(&formID, GetFile(-1));
                    questInfo->m_pAlternateQuest = dynamic_cast<TESQuest*>(::FUN_004839c0(formID));
                }
                else
                {
                    int size = 0;
                    if (((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData())))
                        size = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))))->FUN_0084e3a0()));
                    int nonDeletedCount = 0;
                    if (size)
                    {
                        for (int k = 0; k < size; k++)
                        {
                            TESTopicInfo* info = ((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))->GetAt(k);
                            if (!reinterpret_cast<::FUN_00440d80_shell *>((void *)(info))->FUN_00440d80())
                                nonDeletedCount++;
                        }
                    }
                    if (nonDeletedCount > 0)
                    {
                        ::FUN_005b5e40(
                            );
                    }
                }
                questInfo->bInitialized = true;
            }

            array = ((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()));
            if (array)
            {
                ((NiTLargeArray_TESTopicInfo*)array)->Compact();
                ((NiTLargeArray_TESTopicInfo*)array)->SetSize(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((array))->FUN_0084e3a0())));
                unsigned int infoCount = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((array))->FUN_0084e3a0()));
                for (unsigned int i = 0; i < infoCount; i++)
                {
                    TESTopicInfo* curInfo = array->GetAt(i);
                    if (curInfo)
                    {
                        curInfo->m_pOwnerQuest = questInfo->pQuest;
                        curInfo->InitItem();
                        reinterpret_cast<::FUN_0061f340_shell *>((((TopicInfoStandin*)curInfo)))->FUN_0061f340((unsigned short)i);
                    }
                }
            }
        }
        prev = pIter;
        pIter = ((::BSSimpleList< ::QuestDialogueInfo *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }

    if (::FUN_00619410((const char *)this))
    {
        reinterpret_cast<::fnv_00952830::FUN_00952830_Class *>((((PlayerCharacter_Helper*)::_g_thePlayer)))->FUN_00952830((std::intptr_t)(this), 0, 0);
    }
    SetInitializationState(true);
}
}  // namespace fnv_00619030

class TopicInfoArrayMethods : public TopicInfoArray
{
  public:
    void FUN_00864240(unsigned int index, TESTopicInfo*& value);
    void FUN_0061bdc0();
};
class TopicInfoMethods : public TESTopicInfo
{
  public:
};
class TopicMethods : public TESTopic
{
  public:
    bool AddTopicInfo(TESQuest* quest, TESTopicInfo* info, unsigned int previousInfoID);
};
void FUN_00619fe0(TopicInfoArray* array);

// @fnv 0x00619820
bool TopicMethods::AddTopicInfo(TESQuest* quest, TESTopicInfo* info, unsigned int previousInfoID)
{
    if (!quest || !info)
        return false;
    QuestDialogueInfo* questInfo = reinterpret_cast<::FUN_006195d0_shell *>(this)->GetOrCreateQuestInfo(quest, false);
    if (previousInfoID)
    {
        TESTopicInfo* previousInfo;
        {
            unsigned int insertionIndex;
            {
                unsigned int i;
                {
                    int lastIndex;
                    if (previousInfoID != 0xffffffffu && reinterpret_cast<::FUN_00619a70_shell *>((info))->FUN_00619a70() != 0xffff)
                    {
                        TESTopicInfo* empty = 0;
                        reinterpret_cast<::NiFormArray *>((static_cast<TopicInfoArrayMethods*>(((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData())))))->SetSize(reinterpret_cast<::FUN_00619a70_shell *>((info))->FUN_00619a70(), (unsigned int *)&(empty));
                    }
                    if (previousInfoID != 0xffffffffu)
                    {
                        previousInfo = reinterpret_cast<::FUN_00619e10_impl *>(this)->FindTopicInfoByFormID(previousInfoID, true);
                        if (previousInfo && previousInfoID)
                        {
                            insertionIndex = 0xffffffffu;
                            if (reinterpret_cast<::FUN_00619a70_shell *>((previousInfo))->FUN_00619a70() == 0xffff)
                            {
                                for (i = 0; i < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))))->FUN_0084e3a0())); i++)
                                {
                                    if (((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))->GetAt(i) == previousInfo)
                                    {
                                        insertionIndex = i + 1;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                insertionIndex = reinterpret_cast<::FUN_00619a70_shell *>((previousInfo))->FUN_00619a70() + 1;
                            }
                            reinterpret_cast<::NiFormArray *>((((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))))->SetFormAtIndex(insertionIndex, (::TESForm *)(info));
                        }
                        else
                        {
                            ::FUN_005b5e40(
                                );
                            reinterpret_cast<::NiFormArray *>((((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))))->SetFormAtIndex(0, (::TESForm *)(info));
                        }
                    }
                    else if (reinterpret_cast<::FUN_00619a70_shell *>((info))->FUN_00619a70() == 0xffff)
                    {
                        lastIndex = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))))->FUN_0084e3a0())) - 1;
                        while (lastIndex > 0 && !::GetTopicInfoByIndex(questInfo, lastIndex))
                            lastIndex--;
                        lastIndex++;
                        reinterpret_cast<::FUN_0061f340_shell *>((static_cast<TopicInfoMethods*>(info)))->FUN_0061f340((unsigned short)lastIndex);
                        static_cast<TopicInfoArrayMethods*>(((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData())))->FUN_00864240(lastIndex, info);
                    }
                }
            }
        }
    }
    else
    {
        reinterpret_cast<::NiFormArray *>((((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData()))))->SetFormAtIndex(0, (::TESForm *)(info));
    }
    static_cast<TopicInfoArrayMethods*>(((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData())))->FUN_0061bdc0();
    FUN_00619fe0(((::TopicInfoArray *)(reinterpret_cast<::BaseProcess *>((questInfo))->GetCurrentProcessData())));
    return true;
}

struct SettingFloat
{
};


// Returns the negated DAT_011cff1c value minus DAT_011d14d0 multiplied by (1.0f minus iValue / 100.0f).
// @fnv 0x00648f60
float FUN_00648f60(int iValue)
{
    return -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting1110)))))) - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::originalRuntimeFloatSetting1111)))))) * (1.0f - iValue / 100.0f);
}

#include <stdlib.h>
struct FUN_005c90d0
{
    ~FUN_005c90d0();
};
struct DialogueList;

struct FormTypeView
{
    int FUN_00401170();
};
struct DialogueList
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    unsigned int FUN_005ae380();
};
struct TopicList
{
    bool FUN_008256d0();
    unsigned int FUN_005ae380();
};
struct ConversationDataView
{
};
struct InfoView
{
};
struct ItemView
{
};
struct DataHandlerView
{
};
struct AIView
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
    virtual int GetDisposition();
};
struct ActorBaseView : TESForm
{
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    AIView ai;
};
extern unsigned char DAT_011cbeac;
// Adds dialogue items to history by selecting topics for speaker and listener, with random selection among available topic links.
// @fnv 0x0061b440
unsigned int __cdecl GenerateConversation(TESObjectREFR* speaker, TESObjectREFR* listener, DialogueList* history,
                                          FUN_0061b320_shell* initialTopic)
{
    int used[500];
    DialogueItem* choice;
    bool item;
    if (!history)
        return 0;
    while (history && !history->FUN_008256d0())
    {
        delete (FUN_005c90d0*)((::DialogueItem *)((void *)(history)));
        history->FUN_0063f7b0();
    }
    if (!speaker || !listener)
        return 0;
    TESObjectREFR* previous = speaker;
    TESObjectREFR* currentSpeaker = listener;
    FUN_0061b320_shell* nextItem = 0;
    TESTopic* currentListener = 0;
    TESBoundObject* topic = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((previous))->FUN_007af430()));
    if (topic && ((FormTypeView*)topic)->FUN_00401170() == 43 && !((ActorBaseView*)topic)->ai.GetDisposition())
        return 0;
    nextItem = initialTopic;
    if (!nextItem)
        nextItem = ((::FUN_0061b320_shell *)(reinterpret_cast<::TopicLookup *>((((DataHandlerView*)(*reinterpret_cast<::DataHandlerEx * *>(&::g_dataHandler)))))->FUN_00461690(210)));
    DialogueItem* base = 0;
    int exhausted = -1;
    srand((unsigned int)((unsigned int)(::GetTime64((long long *)(0)))));
    while (nextItem && history->FUN_005ae380() < 100)
    {
        TopicList* topics;
        base = nextItem->FUN_0061b320(previous, currentSpeaker, currentListener, history, false);
        if (!base)
        {
            if (!initialTopic || ::GetSignedByteAtOffset36((signed char *)(((InfoView*)initialTopic))) == 1)
            {
                nextItem = ((::FUN_0061b320_shell *)(reinterpret_cast<::TopicLookup *>((((DataHandlerView*)(*reinterpret_cast<::DataHandlerEx * *>(&::g_dataHandler)))))->FUN_00461690(212)));
                base = nextItem->FUN_0061b320(previous, currentSpeaker, currentListener, history, false);
            }
            if (!base)
                break;
        }
        if (base && ((::InfoView *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ItemView*)base)))->FUN_0084e3a0())) && ::FUN_00579200((const char *)(((::InfoView *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ItemView*)base)))->FUN_0084e3a0())))))
        {
            reinterpret_cast<::FUN_0061f170_cls *>((((::InfoView *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ItemView*)base)))->FUN_0084e3a0()))))->FUN_0061f170((void *)(false), (::ArgObj *)(speaker));
            reinterpret_cast<::FUN_0061f170_cls *>((((::InfoView *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ItemView*)base)))->FUN_0084e3a0()))))->FUN_0061f170((void *)(true), (::ArgObj *)(speaker));
            reinterpret_cast<::TESTopicInfo *>((((::InfoView *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ItemView*)base)))->FUN_0084e3a0()))))->AddTopicList();
        }
        reinterpret_cast<::Callees *>((history))->FUN_00905820((void *)&(base));
        currentListener = (TESTopic*)nextItem;
        nextItem = 0;
        choice = 0;
        item = false;
        FUN_00403d30(used, 0, 2000);
        exhausted = -1;
        while (!choice && !item)
        {
            int count;
            if (((::InfoView *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ItemView*)base)))->FUN_0084e3a0())) && ((::ConversationDataView *)(::GetField38((char *)(((::InfoView *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ItemView*)base)))->FUN_0084e3a0())))))))
            {
                topics = ((::TopicList *)(reinterpret_cast<::TESTopicInfoData *>((((::ConversationDataView *)(::GetField38((char *)(((::InfoView *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ItemView*)base)))->FUN_0084e3a0()))))))))->GetLinkToList()));
                count = topics->FUN_005ae380();
                if (count)
                {
                    if (exhausted == -1)
                        exhausted = rand() % count + 1;
                    else
                        while (used[exhausted - 1])
                            exhausted = rand() % count + 1;
                }
                if (exhausted > 0)
                    used[exhausted - 1] = 1;
                int n = 0;
                while (n < exhausted && topics && !topics->FUN_008256d0())
                {
                    nextItem = (FUN_0061b320_shell*)((::TESTopic *)((void *)(topics)));
                    topics = ((::TopicList *)(reinterpret_cast<::Callees *>((topics))->FUN_00726070()));
                    n++;
                }
                switch (::GetSignedByteAtOffset36((signed char *)(((::InfoView *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ItemView*)base)))->FUN_0084e3a0())))))
                {
                case 2:
                    if (rand() % 2 != 0)
                        break;
                case 0: {
                    TESObjectREFR* temp = previous;
                    previous = currentSpeaker;
                    currentSpeaker = temp;
                    break;
                }
                }
                item = true;
                for (unsigned int i = 0; i < (unsigned int)count && item; i++)
                    if (!used[i])
                        item = false;
                choice = nextItem->FUN_0061b320(previous, currentSpeaker, currentListener, history, false);
            }
            else
                item = true;
        }
    }
    if (DAT_011cbeac)
    {
        ::FUN_00703c00("------NEW CONVERSATION CREATED---------------------", {});
        DialogueList* node = history;
        {
            int index = 1;
            while (node && ((::DialogueItem *)((void *)(node))))
            {
                ItemView* entry = (ItemView*)((::DialogueItem *)((void *)(node)));
                node = ((::DialogueList *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
                if (entry)
                {
                    if (reinterpret_cast<::DialogueItem *>((entry))->SelectDefaultResponseList())
                    {
                        ::FUN_00703c00("Item %d: %s says '%s'", (const char *)(index));
                    }
                    else
                    {
                        ::FUN_00703c00("Item %d: %s has no response!", (const char *)(index));
                    }
                }
                index++;
            }
        }
    }
    return history->FUN_005ae380();
}

// @fnv 0x0061af30
TESTopicInfo* FUN_0061af30(TESTopicInfo* input, bool& deferredResult, TESObjectREFR* speaker, TESObjectREFR* listener,
                           bool filter, BSSimpleList<DialogueItem*>* history)
{
    TESTopicInfo* b = input;
    deferredResult = false;
    if (!b || reinterpret_cast<::FUN_00440d80_shell *>((void *)(b))->FUN_00440d80())
        return 0;
    TESTopicInfo* excluded = 0;
    BSSimpleList<TESTopicInfo*> choices;
    unsigned int f = 0;
    bool h = false;
    BSSimpleList<TESTopicInfo*>* a = 0;
    if (((::TESTopicInfoData *)(::GetField38((char *)(b)))))
        a = ((::BSSimpleList< ::TESTopicInfo *> *)(::FUN_00460140((std::intptr_t)(((::TESTopicInfoData *)(::GetField38((char *)(b))))))));
    TESTopicInfo* fallback = 0;
    while (a && (a->m_item) && !h)
    {
        TESTopicInfo* info = (a->m_item);
        TESQuest* quest = info->m_pOwnerQuest;
        a = ((::BSSimpleList< ::TESTopicInfo *> *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
        if (quest && reinterpret_cast<::TESFaction_RankDataView *>((quest))->FUN_00455620() && quest->GetConditions()->ContainsTrait(speaker, listener))
        {
            bool deferred = false;
            bool allowed = true;
            if (info && reinterpret_cast<::TopicFlagStandIn *>((info))->FUN_0061aef0() && speaker->IsMobileObject())
            {
                MobileObject* mobile = (MobileObject*)speaker;
                if (reinterpret_cast<::FUN_00935a40_cls *>((mobile))->HasEntryWithKey((std::intptr_t)(info)))
                    allowed = false;
            }
            if (info && allowed && reinterpret_cast<::FUN_0061e600_t *>((info))->FUN_0061e600(deferred, 0, speaker, listener))
            {
                deferredResult = false;
                bool keep = true;
                if (keep)
                {
                    if (::IsFlag20Set((char *)(info)))
                        h = true;
                    BSSimpleList<DialogueItem*>* seen = history;
                    while (seen && !seen->IsEmpty())
                    {
                        DialogueItem* dialogue = (seen->m_item);
                        if (((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((dialogue))->FUN_0084e3a0())) == info)
                        {
                            excluded = info;
                            keep = false;
                            break;
                        }
                        seen = ((::BSSimpleList< ::DialogueItem *> *)(reinterpret_cast<::Callees *>((seen))->FUN_00726070()));
                    }
                }
                if (keep)
                {
                    if (::IsFlag20Set((char *)(info)))
                        h = true;
                    if (choices.IsEmpty() && !::FUN_00619410((const char *)(info)))
                    {
                        return info;
                    }
                    else if (!::FUN_00619410((const char *)(info)))
                    {
                        h = true;
                        break;
                    }
                    else
                    {
                        choices.AddHead(info);
                        f++;
                    }
                }
                if (!filter && deferred)
                {
                    fallback = info;
                    deferredResult = true;
                }
                if (h)
                    break;
            }
        }
    }
    if (choices.IsEmpty())
    {
        if (filter)
            return 0;
        else
            return fallback;
    }
    else
    {
        int pick = f ? DialogueRandom() % f + 1 : 0;
        int a = 0;
        BSSimpleList<TESTopicInfo*>* c = &choices;
        TESTopicInfo* selected = 0;
        TESTopicInfo* b = 0;
        while (a < pick && c)
        {
            b = (c->m_item);
            if (b)
            {
                selected = b;
                a++;
            }
            c = ((::BSSimpleList< ::TESTopicInfo *> *)(reinterpret_cast<::Callees *>((c))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>(&(choices))->RemoveAll();
        return selected;
    }
}

#include "generated/data/fallout_shared/testopic.inc"
