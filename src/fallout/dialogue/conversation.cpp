// fallout/dialogue/conversation.cpp: ConversationLoad, DialogueItem, ListNode, Conversation and more (11 functions)

#include <cstdint>
#include "fnv/save_load_game_view.h"
#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DialogueItemBufferWriter.h"
#include "fnv/decl/DialogueItemResolver.h"
#include "fnv/decl/DialogueItem_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0083c9e0_t.h"
#include "fnv/decl/FUN_0083ca90_t.h"
#include "fnv/decl/FUN_0083d0d0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011de000.h"
#include "conversation_decls.h"

// @fnv 0x0083c7b0
bool DialogueItem::SelectDefaultResponseList()
{
    m_pCurrentResponseList = &m_kResponseList;
    return (*((::DialogueResponse * *)(&reinterpret_cast<::SimpleListNodeView*>(m_pCurrentResponseList)->m_item))) != 0;
}

struct ListItem
{
};
struct ListNode
{
    bool _ref_008256d0() const;
    void FUN_0083c220();
};
// Walks the list from this node, calling FUN_0083cdf0 on each node's item until a node satisfies _ref_008256d0 or the list ends.
// @fnv 0x0083c220
void ListNode::FUN_0083c220()
{
    ListNode* current = this;
    while (current && !current->_ref_008256d0())
    {
        ListItem* item = *((::ListItem **)(&reinterpret_cast<::SimpleListNodeView*>(current)->m_item));
        reinterpret_cast<::DialogueItemResolver *>((item))->FUN_0083cdf0();
        current = ((::ListNode *)(reinterpret_cast<::Callees *>((void *)(current))->FUN_00726070()));
    }
}

struct Conversation
{
    BSSimpleList<DialogueItem*> m_kDialogueItems;
    void FUN_0083c420(BGSLoadFormBuffer*);
};
struct DialogueItem_Stub
{
};
// Iterates the dialogue item list and calls each item's load function with the buffer.
// @fnv 0x0083c420
void Conversation::FUN_0083c420(BGSLoadFormBuffer* pBuffer)
{
    BSSimpleList<DialogueItem*>* pCurrentElementNext = reinterpret_cast<BSSimpleList<DialogueItem*>*>(this);
    while (pCurrentElementNext)
    {
        DialogueItem* pdialogueItem = (*((::DialogueItem * *)(&reinterpret_cast<::SimpleListNodeView*>(pCurrentElementNext)->m_item)));
        if (pdialogueItem)
        {
            reinterpret_cast<::FUN_0083d0d0_Class *>((reinterpret_cast<DialogueItem_Stub*>(pdialogueItem)))->RefreshObjectRef((intptr_t)(pBuffer));
        }
        pCurrentElementNext = ((::BSSimpleList< ::DialogueItem *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
}


struct Conversation_Stub
{
    short FUN_0083ba50(DialogueItem* item);
};

// Walks the dialogue item list looking for item and returns its index, warning and returning 0 if not found.
// @fnv 0x0083ba50
short Conversation_Stub::FUN_0083ba50(DialogueItem* item)
{
    short index = 0;
    ListNode* node = (ListNode*)this;
    while (node && !node->_ref_008256d0())
    {
        if (item == (DialogueItem*)((::ListItem **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item))[0])
            return index;
        ++index;
        node = ((::ListNode *)(reinterpret_cast<::Callees *>((void *)(node))->FUN_00726070()));
    }
    ::FUN_005b5e40(
        );
    return 0;
}

struct FormRecordMetadata
{
    unsigned int iFormID;
    char cUnk4;
    unsigned char iFlags[4];
    unsigned char cVersion;
};
struct TESFormStub
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
    virtual const char* GetFormDisplayName();
};
struct TESSaveLoadGame
{
};
class TESSound;
struct EffectSetting
{
public:
    ::TESSound *GetHitSound();
};
struct GameTimerRecord
{
};
struct DialogueItemLoad : DialogueItem
{
    void FUN_0083cc10();
};
class DialogueResponse;
struct StandIn
{
public:
    void FUN_0083c8a0(::DialogueResponse *);
};
struct ConversationLoad : Conversation
{
    void* m_pConversationLoadContext;
    void* FUN_0083bac0(unsigned short);
    void LoadFromSave();
};

// Reads a save block header and dialogue item count, creates and appends DialogueItem objects, sets the current item, and warns on buffer overrun or underrun.
// @fnv 0x0083bec0
void ConversationLoad::LoadFromSave()
{
    unsigned short usBlockSize = 0;
    char* uiStartBufferPosition = 0;
    if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
    {
        unsigned int uiBlockHeader;
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&uiBlockHeader, 4);
        if (uiBlockHeader != 0x424c4f4b)
        {
            FormRecordMetadata* pheader = ((::FormRecordMetadata *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((EffectSetting*)g_TESSaveLoadGame)))));
            if (pheader)
            {
                TESForm* pform = FUN_004839c0(pheader->iFormID);
                ::FUN_005b5e40(
                    );
            }
            else
            {
                ::FUN_005b5e40(
                    );
            }
        }
        uiStartBufferPosition = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&usBlockSize, 2);
    }
    unsigned short icount;
    reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&icount, 2);
    for (unsigned int i = 0; i < icount; i++)
    {
        DialogueItem* pdialogueItem = new DialogueItem;
        ((DialogueItemLoad*)pdialogueItem)->FUN_0083cc10();
        reinterpret_cast<::Callees *>(&(m_kDialogueItems))->FUN_00905820((void *)&(pdialogueItem));
    }
    short sCurrentItemIndex;
    reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&sCurrentItemIndex, 2);
    if (sCurrentItemIndex != -1)
        ((StandIn*)this)->FUN_0083c8a0((::DialogueResponse *)(void *)(FUN_0083bac0(sCurrentItemIndex)));
    else
        m_pConversationLoadContext = 0;
    if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
    {
        char* uiCurrentBufferPosition = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
        FormRecordMetadata* pheader = ((::FormRecordMetadata *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((EffectSetting*)g_TESSaveLoadGame)))));
        if (pheader)
        {
            TESForm* pform = FUN_004839c0(pheader->iFormID);
            if (uiCurrentBufferPosition > usBlockSize + uiStartBufferPosition)
                ::FUN_005b5e40(
                    );
            else if (uiCurrentBufferPosition < usBlockSize + uiStartBufferPosition)
                ::FUN_005b5e40(
                    );
        }
        else
        {
            if (uiCurrentBufferPosition > usBlockSize + uiStartBufferPosition)
                ::FUN_005b5e40(
                    );
            else if (uiCurrentBufferPosition < usBlockSize + uiStartBufferPosition)
                ::FUN_005b5e40(
                    );
        }
    }
}

struct DialogueItemListRef
{
    bool _ref_008256d0() const;
};

// Walks the dialogue item list until the entry at aiIndex is found and returns its item, warning and returning 0 if the index is out of range.
// @fnv 0x0083bac0
void* ConversationLoad::FUN_0083bac0(unsigned short aiIndex)
{
    short iElementIndex = 0;
    BSSimpleList<DialogueItem*>* pCurrentElementNext = (BSSimpleList<DialogueItem*>*)this;
    while (pCurrentElementNext && !((DialogueItemListRef*)pCurrentElementNext)->_ref_008256d0())
    {
        if (iElementIndex == (short)aiIndex)
            return (*((::DialogueItem * *)(&reinterpret_cast<::SimpleListNodeView*>(pCurrentElementNext)->m_item)));
        iElementIndex++;
        pCurrentElementNext = ((::BSSimpleList< ::DialogueItem *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    ::FUN_005b5e40(
        );
    return 0;
}

namespace fnv_0083c330 {
struct BGSLoadFormBuffer
{
};

struct DialogueItem_shell
{
};

struct SoundListView
{
};

struct FUN_0083c330_shell
{
    void FUN_0083c330(BGSLoadFormBuffer* buffer);
};

// @fnv 0x0083c330
void FUN_0083c330_shell::FUN_0083c330(BGSLoadFormBuffer* buffer)
{
    short count;
    unsigned int currentItem = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
    unsigned int index = 0;

    for (; index < currentItem; ++index)
    {
        DialogueItem* item = new DialogueItem;
        reinterpret_cast<::DialogueItem_shell *>((reinterpret_cast<DialogueItem_shell*>(item)))->LoadDialogueItem((::BGSLoadFormBuffer *)(buffer));
        reinterpret_cast<::Callees *>((reinterpret_cast<SoundListView*>(this)))->FUN_00905820((void *)&(*reinterpret_cast<char* const*>(&item)));
    }

    count = -1;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&count), 2);

    if (count != -1)
    {
        reinterpret_cast<StandIn*>(this)->FUN_0083c8a0(
            (::DialogueResponse *)(void *)(reinterpret_cast<ConversationLoad*>(this)->FUN_0083bac0(static_cast<unsigned short>(count))));
    }
}
}  // namespace fnv_0083c330

class StrList
{
  public:
    StrList();
    ~StrList();

    void* m_pkHead;
    void* m_pkTail;
};

class FUN_0083b850;


class FUN_0083b850 : public StrList
{
  public:
    FUN_0083b850(void* pvA, void* pvB, void* pvC);

    int m_iArrayLength;
};

// @fnv 0x0083b850
FUN_0083b850::FUN_0083b850(void* pvA, void* pvB, void* pvC)
{
    m_iArrayLength = 0;
    ::GenerateConversation((::TESObjectREFR *)(pvA), (::TESObjectREFR *)(pvB), (::DialogueList *)(::FUN_0083b850 *)(this), (::FUN_0061b320_shell *)(pvC));
}

struct FormIDEntry
{
    unsigned int iFormID;
    char cUnk4;
    unsigned char iFlags;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char cVersion;
};
struct SaveLoadGameStub
{
};
struct SettingStub
{
    unsigned char* Bool();
};
struct FormStub
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
    virtual const char* GetEditorName();
};
struct DialogueItemSave
{
};
struct DialogueItemNode
{
    bool IsEmpty() const;
};
struct DialogueItemList : DialogueItemNode
{
    unsigned short FUN_0083bb30();
};
static const char kConversationFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Dialogue\\Conversation.cpp";
static const char kSaveSizeFormFormat[] =
    "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s";
static const char kSaveSizeFormat[] = "GetSaveSize(): %-5i ending at line %i in file %s";

// @fnv 0x0083bb30
unsigned short DialogueItemList::FUN_0083bb30()
{
    unsigned short size3 = 0;
    unsigned short start = size3;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        size3 += 4;
        size3 += 2;
    }
    size3 += 2;
    DialogueItemNode* node5 = this;
    while (node5 && !node5->IsEmpty())
    {
        DialogueItemSave* item8 = *((::DialogueItemSave **)(&reinterpret_cast<::SimpleListNodeView*>(node5)->m_item));
        size3 += reinterpret_cast<::FUN_0083c9e0_t *>((item8))->FUN_0083c9e0();
        node5 = ((::DialogueItemNode *)(reinterpret_cast<::Callees *>((void *)(node5))->FUN_00726070()));
    }
    size3 += 2;
    if (*(*reinterpret_cast<::SettingStub *>(&::g_011de4e8)).Bool())
    {
        FormIDEntry* header3 = ((::FormIDEntry *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (header3)
        {
            FormStub* form = ((::FormStub *)(::FUN_004839c0(header3->iFormID)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return size3;
}

class B83C270Buffer
{
  public:
};

class B83C270Item
{
  public:
};

class B83C270Node
{
  public:
};

class B83C270Conversation
{
  public:
    B83C270Node m_kHead;
    int unk04;
    B83C270Node* m_pkCurrent;

    void FUN_0083c270(B83C270Buffer* pkBuffer);
};

// Begins a chunk, saves each non-null item in the node list, ends the chunk, then saves the current node's item index (or -1).
// @fnv 0x0083c270
void B83C270Conversation::FUN_0083c270(B83C270Buffer* pkBuffer)
{
    int iCount7 = 0;
    unsigned int uiChunk = reinterpret_cast<::FUN_00865f20_shell *>((pkBuffer))->FUN_00865f20();
    B83C270Node* pkNode4 = &m_kHead;
    while (pkNode4)
    {
        B83C270Item* pkItem = *((::B83C270Item **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode4)->m_item));
        if (pkItem)
        {
            reinterpret_cast<::DialogueItemBufferWriter *>((pkItem))->FUN_0083ce40((::BGSSaveGameBuffer *)(pkBuffer));
            iCount7++;
        }
        pkNode4 = ((::B83C270Node *)(reinterpret_cast<::Callees *>((pkNode4))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((pkBuffer))->FUN_00865ff0(iCount7, uiChunk);
    short sIndex3 = m_pkCurrent ? reinterpret_cast<::Conversation_Stub *>(this)->FUN_0083ba50((::DialogueItem *)(*((::B83C270Item **)(&reinterpret_cast<::SimpleListNodeView*>(m_pkCurrent)->m_item)))) : -1;
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&sIndex3, 2, 0);
}

struct CVItem
{
};

struct CVNode
{
    void* m_item;
    CVNode* m_pkNext;
    bool IsEmpty() const;
};

struct CVConv : CVNode
{
    CVNode* m_pConversationLoadContext;
    void SaveConversation();
};

struct CVSaveLoad
{
};

extern "C" char DAT_0107db20;

// @fnv 0x0083bc80
void CVConv::SaveConversation()
{
    short sCount_ = 0;                                  // slot -0x10
    short* pSizeTmp = 0;                                // slot -0x04
    char* pCount7 = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;  // slot -0x14
    if (*(*reinterpret_cast<::SettingStub *>(&::g_011de4e8)).Bool())
        pCount7 = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::CVSaveLoad * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int uiBlok9 = 0x424c4f4b;  // slot -0x20
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::CVSaveLoad * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&uiBlok9, 4);
        pSizeTmp = (short*)reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::CVSaveLoad * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&sCount_, 2);
    }
    short sIndex5 = 0;                                  // slot -0x1c
    short* sVer7 = (short*)reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;  // slot -0x0c
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::CVSaveLoad * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&sIndex5, 2);
    CVNode* uiStartTime4 = this;  // slot -0x18
    while (uiStartTime4 && !uiStartTime4->IsEmpty())
    {
        CVItem* pItem = *((::CVItem **)(&reinterpret_cast<::SimpleListNodeView*>(uiStartTime4)->m_item));  // slot -0x24
        reinterpret_cast<::FUN_0083ca90_t *>((pItem))->SaveDialogueItem();
        sIndex5++;
        uiStartTime4 = ((::CVNode *)(reinterpret_cast<::Callees *>((void *)(uiStartTime4))->FUN_00726070()));
    }
    *sVer7 = sIndex5;
    short pNode2 = -1;  // slot -0x08
    if (m_pConversationLoadContext)
        pNode2 = reinterpret_cast<::Conversation_Stub *>(this)->FUN_0083ba50((::DialogueItem *)(*((::CVItem **)(&reinterpret_cast<::SimpleListNodeView*>(m_pConversationLoadContext)->m_item))));
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::CVSaveLoad * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&pNode2, 2);
    if (*(*reinterpret_cast<::SettingStub *>(&::g_011de4e8)).Bool())
    {
        char* uiEndTime4 = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;  // slot -0x2c
        void* _pWorld = ((void *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::CVSaveLoad * *>(&::g_TESSaveLoadGame))))->GetHitSound()));             // slot -0x28
        if (_pWorld)
        {
            TESFormStub* pForm = (TESFormStub*)FUN_004839c0(*(unsigned int*)_pWorld);  // -0x30
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::CVSaveLoad * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        char* uiEnd7 = reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor;  // slot -0x34
        char* uiStart2 = (char*)pSizeTmp;    // slot -0x38
        if (uiEnd7 > uiStart2 + 0xffff)
            ::FUN_005b5e40();
        *pSizeTmp = (short)(uiEnd7 - uiStart2);
    }
}
