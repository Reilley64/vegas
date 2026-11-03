// fallout_shared/tesreactionform.cpp: TESReactionForm, ReactionCompare, C0B0Owner, TESReactionFormLoad (21 functions)

#include <new>
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048b000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011de000.h"
#include "tesreactionform_decls.h"


static const int kInitializeDataComponentValue1 = 8;

// @fnv 0x0048bad0
void TESReactionForm::InitializeComponent()
{
    m_ucReactionFlags = kInitializeDataComponentValue1;
}

// @fnv 0x0048baf0
void TESReactionForm::ClearComponent()
{
    ClearReactionList();
}

// @fnv 0x0048bb10
void TESReactionForm::ClearReactionList()
{
    while (((reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData()))->m_item) != 0)
    {
        InventoryStackRecord* pToFree =
            ((reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData()))->m_item);
        InventoryStackRecord* pItem = pToFree;
        ::FUN_00401030(pItem);
        reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData())
            ->RemoveHead();
    }
}

// Constructs the map base by forwarding the given size to the TESReactionMapStorage base constructor.
// Constructs a BSMapBase<int, DistantTreeTextureInfo*> with the given size, delegating to TESReactionMapStorage.
// @fnv 0x0048b380
template <> BSMapBase<int, DistantTreeTextureInfo*>::BSMapBase(unsigned int size) : TESReactionMapStorage(size)
{}

// On load, walks the reaction list and drops entries whose formID no longer resolves, unlinking them from the list.
// @fnv 0x0048cb40
void TESReactionForm::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(4)))->FUN_004280f0(4))
    {
        BSSimpleList<BGSCameraShot*>* current = reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(&m_kReactionList);
        BSSimpleList<BGSCameraShot*>* previous = 0;
        while (current && !current->IsEmpty())
        {
            ReactionInfo* reaction = reinterpret_cast<ReactionInfo*>((current->item));
            bool remove = false;
            if (reaction)
            {
                reaction->formID = reaction->formID
                                       ? reinterpret_cast<unsigned int>(::FUN_004839c0(reaction->formID))
                                       : 0;
                if (!reaction->formID)
                {
                    delete reaction;
                    remove = true;
                }
            }
            else
            {
                remove = true;
            }
            if (remove)
            {
                if (previous)
                {
                    reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330((::InventoryStackRecord *const &)((current->item)));
                    current = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
                }
                else
                {
                    current->RemoveHead();
                }
            }
            else
            {
                previous = current;
                current = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
            }
        }
    }
}

// Resolves each reaction entry's formID against the given form's file, warns and removes entries whose form cannot be found.
// @fnv 0x0048bc30
void TESReactionForm::InitItem(TESForm* form)
{
    // Local names preserve the original MSVC9 stack allocation.
    TESFile* pPrev;
    BSSimpleList<BGSCameraShot*>* pList =
        reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData());
    BSSimpleList<BGSCameraShot*>* pFile = 0;
    pPrev = form ? form->GetFile(-1) : 0;
    while (pList && (pList->item))
    {
        ReactionInfo* reaction = reinterpret_cast<ReactionInfo*>((pList->item));
        unsigned int formID = reaction->formID;
        ::ResolveFormID((unsigned int *)&(formID), pPrev);
        reaction->formID = (unsigned int)(std::uintptr_t)(::FUN_004839c0(formID));
        if (reaction->formID)
        {
            pList = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        }
        else
        {
            ::FUN_005b5e40();
            if (((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070())) || !pFile)
            {
                pList->RemoveHead();
            }
            else
            {
                reinterpret_cast<::ItemChangeListNode *>((pFile))->FUN_00905330((::InventoryStackRecord *const &)(reinterpret_cast<BGSCameraShot* const&>(reaction)));
                pList = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((pFile))->FUN_00726070()));
            }
            delete reaction;
        }
    }
}

struct FUN_0048c1b0_shell : public TESReactionForm
{
    int FUN_0048c1b0(TESForm*);
};

struct GROUP_REACTION_dummy
{
    TESForm* pForm;
    int iOffset;
    int eFightReaction;
};


// Searches the reaction list for a matching form and returns its fight reaction, or 0 if not found.
// @fnv 0x0048c1b0
int FUN_0048c1b0_shell::FUN_0048c1b0(TESForm* apForm)
{
    if (apForm != 0)
    {
        void* pList = reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData();
        while (pList != 0 && *((::GROUP_REACTION_dummy **)((void *)(pList))) != 0)
        {
            GROUP_REACTION_dummy* fr = *((::GROUP_REACTION_dummy **)((void *)(pList)));
            if (fr->pForm == apForm)
                return fr->eFightReaction;
            pList = reinterpret_cast<::Callees *>((pList))->FUN_00726070();
        }
    }
    return 0;
}

struct SoundListView
{
};
struct ListH_0048bfc0
{
};
struct RF_0048bfc0
{
    char pad[4];
    ListH_0048bfc0 list;
};
struct Args_0048bfc0
{
    TESForm* apForm;
    int aiReaction;
};
// @fnv 0x0048bfc0
void FUN_0048bfc0(BaseProcess* self, Args_0048bfc0 args)
{
    if (!args.apForm)
        return;
    bool bFound = false;
    void* pList = self->GetCurrentProcessData();
    while (pList && *((::GROUP_REACTION_dummy **)((void *)(pList))))
    {
        GROUP_REACTION_dummy* fr = *((::GROUP_REACTION_dummy **)((void *)(pList)));
        if (fr->pForm == args.apForm)
        {
            if (args.aiReaction == 0 && fr->eFightReaction == 0)
            {
                reinterpret_cast<::ItemChangeListNode *>((((ListH_0048bfc0*)((char*)self + 4))))->FUN_00905330((*(::InventoryStackRecord *const *)(&fr)));
                delete fr;
            }
            else
            {
                fr->iOffset = args.aiReaction;
            }
            bFound = true;
            break;
        }
        pList = reinterpret_cast<::Callees *>((pList))->FUN_00726070();
    }
    if (!bFound && args.aiReaction)
    {
        GROUP_REACTION_dummy* fr = new GROUP_REACTION_dummy;
        fr->pForm = args.apForm;
        fr->iOffset = args.aiReaction;
        reinterpret_cast<::Callees *>((((SoundListView*)self->GetCurrentProcessData())))->FUN_00905820((void *)&(fr));
    }
}

struct BFC_s
{
    BFC_s();
    virtual void Init();
};
struct SL
{
    void* item;
    void* next;
    SL();
    ~SL();
};
struct FUN_0048ba00 : public BFC_s
{
    SL m_kReactionList;
    unsigned char m_ucReactionFlags;
    FUN_0048ba00();
};
// @fnv 0x0048ba00
FUN_0048ba00::FUN_0048ba00()
{
    ((TESReactionForm*)this)->InitializeComponent();
}

struct ListX
{
    ~ListX();
};
struct FUN_0048ba70 : BaseFormComponent
{
    ListX m_kNode;
    ~FUN_0048ba70();
};
// @fnv 0x0048ba70
FUN_0048ba70::~FUN_0048ba70()
{
    ((TESReactionForm*)(void*)this)->ClearComponent();
}

struct ReactionEntry
{
    unsigned int formID;
    int a;
    int b;
};
struct G2
{
    void AddHead(ReactionEntry* const&);
};
struct BGSLoadFormBufferA
{
};
struct FUN_0048ca90 : TESReactionForm
{
    void LoadReaction(BGSLoadFormBuffer* buffer);
};
// @fnv 0x0048ca90
void FUN_0048ca90::LoadReaction(BGSLoadFormBuffer* buffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(4)))->FUN_004280f0(4))
    {
        ClearReactionList();
        unsigned int count = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((((BGSLoadFormBufferA*)buffer)))->FUN_00864a60();
        for (unsigned int i = 0; i < count; ++i)
        {
            ReactionEntry* entry = new ReactionEntry;
            reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((((BGSLoadFormBufferA*)buffer)))->FUN_008648e0((unsigned int *)(void *)(&entry->formID));
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBufferA*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&entry->a), 4);
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBufferA*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&entry->b), 4);
            ((G2*)((char*)this + 4))->AddHead(entry);
        }
    }
}

struct RefH : public TESForm
{
};

struct ContainerItemExtraFileData
{
    unsigned int formID;
    unsigned int field4;
    unsigned int field8;
};


struct FUN_0048bb70_shell : public BaseProcess
{
    void WriteCameraShotList();
};

// @fnv 0x0048bb70
void FUN_0048bb70_shell::WriteCameraShotList()
{
    BSSimpleList<BGSCameraShot*>* current = (BSSimpleList<BGSCameraShot*>*)GetCurrentProcessData();
    BGSCameraShot* shot;
    ContainerItemExtraFileData data;

    while (current && (current->item))
    {
        shot = (current->item);

        if (!reinterpret_cast<::FUN_00440d80_shell *>((void *)((*reinterpret_cast<RefH**>(shot))))->FUN_00440d80())
        {
            data.formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<RefH**>(shot))))->FUN_0084e3a0()));
            data.field4 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(shot) + 4);
            data.field8 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(shot) + 8);

            if (((bool)(::FUN_00401500())))
                reinterpret_cast<::Class005a6b10 *>(&(data))->FUN_005a6b10();

            ::AppendChunk(0x4d414e58, &data, 0xc);

            if (((bool)(::FUN_00401500())))
                reinterpret_cast<::Class005a6b10 *>(&(data))->FUN_005a6b10();
        }

        current = (BSSimpleList<BGSCameraShot*>*)((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
    }
}

struct GROUP_REACTION_bd50
{
    TESForm* pForm;
    int iOffset;
    int eFightReaction;
};

struct ReactionListOps_bd50
{
};

extern int DAT_01186b30;

struct FUN_0048bd50_shell : public TESReactionForm
{
    void CopyReactionList(TESForm* form);
};

// @fnv 0x0048bd50
void FUN_0048bd50_shell::CopyReactionList(TESForm* form)
{
    ReactionListOps_bd50* p = (ReactionListOps_bd50*)dynamic_cast<::TESReactionForm *>(reinterpret_cast<::BaseFormComponent *>(form));
    if (p == 0)
    {
        return;
    }
    reinterpret_cast<::TESReactionForm *>((this))->ClearReactionList();
    ReactionListOps_bd50* cur5;
    ReactionListOps_bd50* dst;
    dst = ((::ReactionListOps_bd50 *)(reinterpret_cast<::BaseProcess *>((((ReactionListOps_bd50*)this)))->GetCurrentProcessData()));
    cur5 = ((::ReactionListOps_bd50 *)(reinterpret_cast<::BaseProcess *>((p))->GetCurrentProcessData()));
    while (cur5 != 0 && *((::GROUP_REACTION_bd50 **)((void *)(cur5))) != 0)
    {
        GROUP_REACTION_bd50* src2 = *((::GROUP_REACTION_bd50 **)((void *)(cur5)));
        GROUP_REACTION_bd50* item = new GROUP_REACTION_bd50;
        item->pForm = src2->pForm;
        item->iOffset = src2->iOffset;
        item->eFightReaction = src2->eFightReaction;
        reinterpret_cast<::Callees *>((dst))->FUN_00905820(&item);
        if (((::ReactionListOps_bd50 *)(reinterpret_cast<::Callees *>((dst))->FUN_00726070())) != 0)
        {
            dst = ((::ReactionListOps_bd50 *)(reinterpret_cast<::Callees *>((dst))->FUN_00726070()));
        }
        cur5 = ((::ReactionListOps_bd50 *)(reinterpret_cast<::Callees *>((cur5))->FUN_00726070()));
    }
}

struct ReactionData
{
    unsigned int form;
    int offset;
    int fight;
};
struct ReactionList
{
    bool FUN_008256d0();
};
struct ReactionAccess
{
};
struct ReactionCompare : TESReactionForm
{
    bool FUN_0048be40(BaseFormComponent*);
};
// Compares this reaction form's list against another TESReactionForm's list entry by entry, returning true when they differ or the other list is longer.
// @fnv 0x0048be40
bool ReactionCompare::FUN_0048be40(BaseFormComponent* component)
{
    TESReactionForm* right = dynamic_cast<TESReactionForm*>(component);
    if (!right)
        return true;
    ReactionList* other = ((::ReactionList *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<ReactionAccess*>(this)))->GetCurrentProcessData()));
    ReactionList* left = ((::ReactionList *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<ReactionAccess*>(right)))->GetCurrentProcessData()));
    while (other)
    {
        if (!left)
            return true;
        ReactionData* rhs = *((::ReactionData **)((void *)(other)));
        ReactionData* lhs = *((::ReactionData **)((void *)(left)));
        if (rhs && lhs)
        {
            if (rhs->form != lhs->form)
                return true;
            if (rhs->offset != lhs->offset)
                return true;
            if (rhs->fight != lhs->fight)
                return true;
        }
        else if (rhs || lhs)
            return true;
        left = ((::ReactionList *)(reinterpret_cast<::Callees *>((left))->FUN_00726070()));
        other = ((::ReactionList *)(reinterpret_cast<::Callees *>((other))->FUN_00726070()));
    }
    if (left && !left->FUN_008256d0())
        return true;
    return false;
}

// Adjust the stored count for a form: add a new entry if missing, remove the entry when its count reaches zero.

class C0B0Form;

struct C0B0Entry
{
    C0B0Form* m_pkForm;
    int m_iArrayLength;
    int unk08;
};

class C0B0Node
{
  public:
};

class C0B0List : public C0B0Node
{
  public:
};

class C0B0Owner
{
  public:
    void FUN_0048c0b0(C0B0Form* pkForm, int iDelta);
};

// @fnv 0x0048c0b0
void C0B0Owner::FUN_0048c0b0(C0B0Form* pkForm, int iDelta)
{
    if (!pkForm || !iDelta)
        return;

    C0B0Entry* pkEntry = 0;
    C0B0Node* pkIter = ((::C0B0List *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    bool bFound = false;
    while (pkIter && *((::C0B0Entry **)((void *)(pkIter))))
    {
        pkEntry = *((::C0B0Entry **)((void *)(pkIter)));
        if (pkEntry->m_pkForm == pkForm)
        {
            bFound = true;
            break;
        }
        pkIter = ((::C0B0Node *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070()));
    }

    if (!bFound)
    {
        pkEntry = new C0B0Entry;
        pkEntry->m_pkForm = pkForm;
        pkEntry->m_iArrayLength = iDelta;
        reinterpret_cast<::Callees *>((((::C0B0List *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()))))->FUN_00905820((void *)&(pkEntry));
    }
    else
    {
        pkEntry->m_iArrayLength += iDelta;
        if (!pkEntry->m_iArrayLength)
        {
            reinterpret_cast<::ItemChangeListNode *>((((::C0B0List *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()))))->FUN_00905330((::InventoryStackRecord *const &)(pkEntry));
            delete pkEntry;
        }
    }
}

struct FUN_0048c220_shell
{
    void FUN_0048c220(TESForm* apForm, int aiReaction);
};
// If apForm is non-null, updates the matching list entry's reaction or appends a new entry when aiReaction is non-zero.
// @fnv 0x0048c220
void FUN_0048c220_shell::FUN_0048c220(TESForm* apForm, int aiReaction)
{
    if (apForm == 0)
    {
        return;
    }
    bool bFound = false;
    void* pNode = ((void *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    while (pNode != 0 && *((::GROUP_REACTION_dummy **)((void *)(pNode))) != 0)
    {
        GROUP_REACTION_dummy* pItem = *((::GROUP_REACTION_dummy **)((void *)(pNode)));
        if (pItem->pForm == apForm)
        {
            pItem->eFightReaction = aiReaction;
            bFound = true;
            break;
        }
        pNode = reinterpret_cast<::Callees *>((pNode))->FUN_00726070();
    }
    if (!bFound && aiReaction != 0)
    {
        GROUP_REACTION_dummy* newItem = new GROUP_REACTION_dummy;
        newItem->pForm = apForm;
        newItem->iOffset = 0;
        newItem->eFightReaction = aiReaction;
        reinterpret_cast<::Callees *>((static_cast<SoundListView*>(((void *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData())))))->FUN_00905820((void *)&(newItem));
    }
}

namespace fnv_0048c2e0 {
struct Global_011de45c
{
};
struct Global_011de4e8
{
    const unsigned char* FUN_00408d60();
};
struct ActorPackageContext
{
    int FUN_005ae380();
};
struct FUN_0048c2e0_shell : BaseProcess
{
    unsigned short FUN_0048c2e0(unsigned int flags);
};
// Computes the serialized size of the package data when flag bit 4 is set, adding fixed fields and per-entry sizes, and logs the result.
// @fnv 0x0048c2e0
unsigned short FUN_0048c2e0_shell::FUN_0048c2e0(unsigned int flags)
{
    unsigned short count = 0;
    if ((flags & 4) != 0)
    {
        unsigned short start = count;
        if (reinterpret_cast<::FUN_00862110_cls *>((((Global_011de45c*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
        {
            count += 4;
            count += 2;
        }
        ActorPackageContext* package = ((::fnv_0048c2e0::ActorPackageContext *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
        count += 2;
        count += package->FUN_005ae380() * 8;
        if (*((Global_011de4e8*)&(*reinterpret_cast<unsigned char *>(&::g_011de4e8)))->FUN_00408d60() != 0)
        {
            unsigned int* formID = ((unsigned int *)(reinterpret_cast<::EffectSetting *>((((Global_011de45c*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->GetHitSound()));
            if (formID != 0)
            {
                TESForm* form = ::FUN_004839c0(*formID);
                ::FUN_0040fbe0(::DAT_01012cb0, count - start, *formID, form->GetEditorID(),
                             *(unsigned int*)((unsigned char*)formID + 5), 0x557, str_0101d4c8);
            }
            else
            {
                ::FUN_0040fbe0(::DAT_01012c78, count - start, 0x557, str_0101d4c8);
            }
        }
    }
    return count;
}
}  // namespace fnv_0048c2e0

struct ObjC400
{
    unsigned int formID;
    char flag4;
    int field5;
};
struct SaveC400
{
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct S24
{
    void WriteReactionList(unsigned int arg);
};

// @fnv 0x0048c400
void S24::WriteReactionList(unsigned int auiFlags)
{
    if (auiFlags & 4)
    {
        unsigned short sizeWord = 0;
        std::uintptr_t posSize4 = 0;
        unsigned int startPos = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        if (*::g_011de4e8.Bool())
        {
            startPos = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        }
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            int tag = 0x424c4f4b;
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&tag, 4);
            posSize4 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&sizeWord, 2);
        }
        unsigned short kCount = 0;
        unsigned int posCountC = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&kCount, 2);
        ReactionListOps_bd50* node = ((::ReactionListOps_bd50 *)(reinterpret_cast<::BaseProcess *>((((ReactionListOps_bd50*)this)))->GetCurrentProcessData()));
        while (node)
        {
            GROUP_REACTION_bd50* item = *((::GROUP_REACTION_bd50 **)((void *)(node)));
            if (item)
            {
                unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((item->pForm))->FUN_0084e3a0()));
                reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&formID), 4);
                reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&item->iOffset, 4);
                kCount++;
            }
            node = ((::ReactionListOps_bd50 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        *(unsigned short*)posCountC = kCount;
        if (*::g_011de4e8.Bool())
        {
            unsigned int endPos2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
            ObjC400* kObj = ((::ObjC400 *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
            if (kObj)
            {
                TESForm* form = FUN_004839c0(kObj->formID);
                ::FUN_0040fbe0(::DAT_010153a0, endPos2 - startPos, kObj->formID, form->GetEditorID(),
                             *(int*)((char*)kObj + 5), 1403, ::fnv_0048c2e0::str_0101d4c8);
            }
            else
            {
                ::FUN_0040fbe0(::DAT_0101536c, endPos2 - startPos, 1403, ::fnv_0048c2e0::str_0101d4c8);
            }
        }
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            unsigned int endPos = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveC400 * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
            unsigned int blockStart = posSize4;
            if (endPos > blockStart + 0xffff)
            {
                ::FUN_005b5e40(::DAT_01015318, ::fnv_0048c2e0::str_0101d4c8, 1403);
            }
            *(unsigned short*)posSize4 = (unsigned short)(endPos - blockStart);
        }
    }
}

struct SaveLoadFormInfo
{
    unsigned int formID;
    unsigned char unk04;
    unsigned char flagsByte0;
    unsigned char flagsByte1;
    unsigned char flagsByte2;
    unsigned char flagsByte3;
    unsigned char version;
};

struct SaveLoadGameStub
{
};


struct TESReactionFormLoad : public TESReactionForm
{
    void LoadReactions(unsigned int auiChangeFlags, BGSLoadFormBuffer* apBuffer);
};

// @fnv 0x0048c640
void TESReactionFormLoad::LoadReactions(unsigned int auiChangeFlags, BGSLoadFormBuffer* apBuffer)
{
    if (auiChangeFlags & 4)
    {
        unsigned short usLength = 0;
        unsigned int dwStart = 0;
        unsigned short usNum;
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            unsigned int uiMarker;
            reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&uiMarker, 4);
            if (uiMarker != 0x424C4F4B)
            {
                SaveLoadFormInfo* pInfo = ((::SaveLoadFormInfo *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))));
                if (pInfo)
                {
                    TESForm* pForm = ::FUN_004839c0(pInfo->formID);
                    ::FUN_005b5e40(
                        );
                }
                else
                {
                    ::FUN_005b5e40(
                        );
                }
            }
            dwStart = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
            reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&usLength, 2);
        }
        reinterpret_cast<::TESReactionForm *>(this)->ClearReactionList();
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&usNum, 2);
        for (unsigned int i = 0; i < usNum; i++)
        {
            unsigned int auiFormId;
            reinterpret_cast<::FUN_00857aa0 *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->ValidateFormIDArray(&auiFormId, 4);
            int iFactionReaction;
            reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&iFactionReaction, 4);
            ::FUN_0048bfc0((::BaseProcess *)this, ::Args_0048bfc0{(TESForm*)(std::uintptr_t)auiFormId, iFactionReaction});
        }
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            unsigned int endPos = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_00825c00();
            SaveLoadFormInfo* pEndInfo = ((::SaveLoadFormInfo *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)((*reinterpret_cast<::SaveLoadGameStub * *>(&::g_TESSaveLoadGame))))));
            if (pEndInfo)
            {
                TESForm* pEndForm = ::FUN_004839c0(pEndInfo->formID);
                if (endPos > usLength + dwStart)
                {
                    ::FUN_005b5e40(
                        );
                }
                else if (endPos < usLength + dwStart)
                {
                    ::FUN_005b5e40(
                        );
                }
            }
            else
            {
                if (endPos > usLength + dwStart)
                {
                    ::FUN_005b5e40(
                        );
                }
                else if (endPos < usLength + dwStart)
                {
                    ::FUN_005b5e40(
                        );
                }
            }
        }
    }
}

void _ref_0063f7b0(void* pList);

struct FUN_0048c930_shell
{
    void ResolveGroupReactionForms(unsigned int flags, unsigned int unused);
};

// When flags has bit 4, walks the list, resolves each entry's pForm via _ref_004839c0, and deletes entries whose form resolves to null.
// @fnv 0x0048c930
void FUN_0048c930_shell::ResolveGroupReactionForms(unsigned int flags, unsigned int unused)
{
    if (flags & 4)
    {
        void* iter = ((void *)(reinterpret_cast<::BaseProcess *>((this))->GetCurrentProcessData()));
        int count = 0;
        while (iter != 0)
        {
            GROUP_REACTION_dummy* entry = *((::GROUP_REACTION_dummy **)((void *)(iter)));
            if (entry != 0)
            {
                unsigned int formID = (unsigned int)(std::uintptr_t)entry->pForm;
                entry->pForm = (TESForm*)((std::uintptr_t)(::FUN_004839c0(formID)));
                if (entry->pForm == 0)
                {
                    _ref_0063f7b0(iter);
                    GROUP_REACTION_dummy* dead = entry;
                    ::FUN_00401030(dead);
                }
                else
                {
                    iter = reinterpret_cast<::Callees *>((iter))->FUN_00726070();
                }
            }
            else
            {
                iter = reinterpret_cast<::Callees *>((iter))->FUN_00726070();
            }
        }
    }
}

struct FUN_0048c9d0_ChangeFlags
{
};

struct FUN_0048c9d0_ListNode
{
    void* item;
    FUN_0048c9d0_ListNode* next;

};

struct FUN_0048c9d0_SaveBuffer
{
    FUN_0048c9d0_ChangeFlags* FUN_00428110(int* value, int size);
};

struct FUN_0048c9d0_Class
{
    int unk00;
    FUN_0048c9d0_ListNode list;

    void FUN_0048c9d0(FUN_0048c9d0_SaveBuffer* buffer);
};

// @fnv 0x0048c9d0
void FUN_0048c9d0_Class::FUN_0048c9d0(FUN_0048c9d0_SaveBuffer* buffer)
{
    void* item;
    FUN_0048c9d0_ListNode* cursor;
    unsigned int value;
    int count;

    {
        int temp;
        if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((buffer->FUN_00428110(&temp, 4)))->FUN_004280f0({}))
        {
            count = 0;
            value = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();
            cursor = &list;
            while (cursor != 0)
            {
                item = ((::FUN_0048c9d0_ListNode *)((void *)(cursor)))->item;
                if (item != 0)
                {
                    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(std::intptr_t*)item), 0);
                    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)item + 4, 4, 0);
                    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)item + 8, 4, 0);
                    count = count + 1;
                }
                cursor = ((::FUN_0048c9d0_ListNode *)(reinterpret_cast<::Callees *>((cursor))->FUN_00726070()));
            }
            reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count, value);
        }
    }
}

#include "generated/data/fallout_shared/tesreactionform.inc"
