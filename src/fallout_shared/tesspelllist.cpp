// fallout_shared/tesspelllist.cpp: TESSpellList, TESAttributes, FloatValueProvider, SpellListTask and more (19 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/xEffOwner.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
#include "tesspelllist.h"

// @fnv 0x0048d0d0
void TESSpellList::ClearComponent()
{
    ClearSpells();
}

// Removes all entries from the spell list and from the list returned by GetOffsetC.
// @fnv 0x0048d0f0
void TESSpellList::ClearSpells()
{
    BSSimpleList<InventoryStackRecord*>* pFirstList =
        reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData());
    BSSimpleList<InventoryStackRecord*>* pSecondList;
    while (pFirstList && (pFirstList->m_item))
        pFirstList->RemoveHead();

    pSecondList = ((::BSSimpleList< ::InventoryStackRecord *> *)(::GetOffsetC((std::intptr_t)this)));
    while (pSecondList && (pSecondList->m_item))
        pSecondList->RemoveHead();
}

// @fnv 0x0047ffa0
TESAttributes::~TESAttributes()
{
    reinterpret_cast<TESForm*>(this)->ClearData();
}

// Constructs a TESSpellList and calls IsInCombat on the object viewed as a TESForm.
// @fnv 0x0048cfe0
TESSpellList::TESSpellList()
{
    reinterpret_cast<TESForm*>(this)->ClearData();
}

template <> class BSSimpleList<int>
{
  public:
    int item;
    BSSimpleList<int>* next;
    ~BSSimpleList();
};
struct FUN_0048d060 : public BaseFormComponent
{
    BSSimpleList<int> a;
    BSSimpleList<int> b;
    ~FUN_0048d060();
};
// @fnv 0x0048d060
FUN_0048d060::~FUN_0048d060()
{
    reinterpret_cast<::TESSpellList *>(this)->ClearComponent();
}

// @fnv 0x0048d150
std::intptr_t GetOffsetC(std::intptr_t apBase)
{
    return apBase + 0xc;
}

class TESDataHandler
{
};
struct LH
{
    void AddHead(SpellItem*&);
};
struct PadX
{
    char pad[0x7c];
};
struct FloatValueProvider : public BaseProcess
{
    bool FUN_0048d170(SpellItem* apSpell);
};
struct ZX2 : public PadX, public FloatValueProvider
{
};
// @fnv 0x0048d170
bool FloatValueProvider::FUN_0048d170(SpellItem* apSpell)
{
    if (!apSpell)
        return false;
    if (reinterpret_cast<::RefList *>((void *)(((LH*)GetCurrentProcessData())))->FUN_005f65d0((void **)&(apSpell)))
        return false;
    ((LH*)GetCurrentProcessData())->AddHead(apSpell);
    if (this == static_cast<FloatValueProvider*>((ZX2*)::_g_thePlayer->GetActorBase()) && !reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004516b0())
        reinterpret_cast<::xEffOwner *>((::_g_thePlayer))->FUN_0094c6c0((::xEffItem *)(apSpell));
    return true;
}

namespace fnv_0048d290 {
struct FUN_0048d290_shell : public TESSpellList
{
    bool FUN_0048d290(TESForm*);
};

class TESDataHandler;
struct DHX
{
};
struct ZX2
{
    bool FUN_0048d210(TESLevSpell*);
};
// @fnv 0x0048d290
bool FUN_0048d290_shell::FUN_0048d290(TESForm* apSpellIn)
{
    if (reinterpret_cast<::FUN_004516b0_shell *>((((DHX*)(*reinterpret_cast<::fnv_0048d290::TESDataHandler * *>(&::g_dataHandler)))))->FUN_004516b0())
    {
        reinterpret_cast<::FloatValueProvider *>((((ZX2*)this)))->FUN_0048d170((SpellItem*)apSpellIn);
        return true;
    }
    SpellItem* pSpell = dynamic_cast<SpellItem*>(apSpellIn);
    TESLevSpell* pLevSpell = dynamic_cast<TESLevSpell*>(apSpellIn);
    if (pSpell)
        return reinterpret_cast<::FloatValueProvider *>((((ZX2*)this)))->FUN_0048d170(pSpell);
    else if (pLevSpell)
        return ((ZX2*)this)->FUN_0048d210(pLevSpell);
    return false;
}
}  // namespace fnv_0048d290

struct ListNode
{
};
struct Holder_0048d830 : BaseProcess
{
    bool ContainsPackage(ActorPackageContext* package);
};
// @fnv 0x0048d830
bool Holder_0048d830::ContainsPackage(ActorPackageContext* package)
{
    ListNode* node = reinterpret_cast<ListNode*>(GetCurrentProcessData());
    while (node)
    {
        ActorPackageContext* entry = ((::ActorPackageContext *)((void *)(node)));
        if (entry == package)
            return true;
        node = ((::ListNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return false;
}

struct FUN_0048d880_shell : public BSSimpleList<void*>
{
    bool FUN_0048d880(void* item);
};

// Walks the list returned by GetOffsetC and returns true if any entry equals item, otherwise false.
// @fnv 0x0048d880
bool FUN_0048d880_shell::FUN_0048d880(void* item)
{
    BSSimpleList<void*>* node = ((::BSSimpleList<void *> *)(::GetOffsetC((std::intptr_t)this)));
    while (node)
    {
        void* entry = (node->m_item);
        if (entry == item)
            return true;
        node = ((::BSSimpleList<void *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return false;
}

struct Helper00905330
{
};
struct Host0048d8d0 : BaseProcess
{
    void ForwardToHelper(intptr_t);
};
// @fnv 0x0048d8d0
void Host0048d8d0::ForwardToHelper(intptr_t a)
{
    reinterpret_cast<::ItemChangeListNode *>((((Helper00905330*)GetCurrentProcessData())))->FUN_00905330((::InventoryStackRecord *const &)(a));
}

struct SpellListHandle
{
    void FUN_005ae3d0();
};
struct SpellListTask
{
    bool FUN_0048d210(TESLevSpell* spell);
};
// @fnv 0x0048d400
void TESSpellList::InitItem(TESForm* owner)
{
    struct SpellCursor
    {
        BSSimpleList<InventoryStackRecord*>* current;
        BSSimpleList<InventoryStackRecord*>* previous;
        TESFile* file;
    } listCursor;
    listCursor.previous = 0;
    listCursor.current =
        reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData());
    listCursor.file = owner ? owner->GetFile(-1) : 0;
    while (listCursor.current && (listCursor.current->m_item))
    {
        struct ResolvedForm
        {
            unsigned int id;
            TESForm* form;
        } resolvedForm;
        resolvedForm.id = (unsigned int)(std::uintptr_t)((listCursor.current->m_item));
        ::ResolveFormID((unsigned int *)&(resolvedForm.id), listCursor.file);
        resolvedForm.form = ::FUN_004839c0(resolvedForm.id);
        {
            struct SpellTypes
            {
                SpellItem* spell;
                TESLevSpell* leveled;
            } spellTypes;
            {
                TESActorBase* actor;
                if (!resolvedForm.form)
                {
                    if (((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.current)))->FUN_00726070())) ||
                        !listCursor.previous)
                        listCursor.current->RemoveHead();
                    else
                    {
                        BGSCameraShot* pRemovedEntry = reinterpret_cast<BGSCameraShot*>(resolvedForm.id);
                        reinterpret_cast<::ItemChangeListNode *>((reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(listCursor.previous)))->FUN_00905330((::InventoryStackRecord *const &)(pRemovedEntry));
                        listCursor.current = reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(
                            ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.previous)))->FUN_00726070())));
                    }
                    if (owner)
                    {
                        if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                            ::FUN_005b5e40();
                        else
                            ::FUN_005b5e40();
                    }
                    else
                        ::FUN_005b5e40();
                }
                else
                {
                    spellTypes.spell = dynamic_cast<SpellItem*>(resolvedForm.form);
                    spellTypes.leveled = dynamic_cast<TESLevSpell*>(resolvedForm.form);
                    if (spellTypes.spell)
                    {
                        reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(listCursor.current)
                            ->SetItem(reinterpret_cast<BGSCameraShot* const&>(spellTypes.spell));
                        actor = dynamic_cast<TESActorBase*>(this);
                        if (actor && actor == ::_g_thePlayer->GetActorBase())
                            reinterpret_cast<::xEffOwner *>((::_g_thePlayer))->FUN_0094c6c0((::xEffItem *)(spellTypes.spell));
                        listCursor.previous = listCursor.current;
                        listCursor.current = reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(
                            ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.current)))->FUN_00726070())));
                    }
                    else
                    {
                        if (((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.current)))->FUN_00726070())) ||
                            !listCursor.previous)
                            listCursor.current->RemoveHead();
                        else
                        {
                            BGSCameraShot* pRemovedEntry = reinterpret_cast<BGSCameraShot*>(resolvedForm.id);
                            reinterpret_cast<::ItemChangeListNode *>((reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(listCursor.previous)))->FUN_00905330((::InventoryStackRecord *const &)(pRemovedEntry));
                            listCursor.current = reinterpret_cast<BSSimpleList<InventoryStackRecord*>*>(
                                ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(listCursor.previous)))->FUN_00726070())));
                        }
                        if (spellTypes.leveled)
                            reinterpret_cast<::SpellListTask *>(this)->FUN_0048d210(spellTypes.leveled);
                    }
                }
            }
        }
    }
}
struct PlayerBaseData
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
};
struct PlayerProcess : PlayerBaseData, SpellListTask
{
};
struct PlayerProcessAccessor
{
};
// @fnv 0x0048d210
bool SpellListTask::FUN_0048d210(TESLevSpell* spell)
{
    if (!spell)
        return false;
    if (this == static_cast<SpellListTask*>(((::PlayerProcess *)(reinterpret_cast<::Actor *>((reinterpret_cast<PlayerProcessAccessor*>(::_g_thePlayer)))->GetActorBase()))))
        return false;
    if (reinterpret_cast<::RefList *>((((::SpellListHandle *)(::GetOffsetC((std::intptr_t)this)))))->FUN_005f65d0({}))
        return false;
    ((::SpellListHandle *)(::GetOffsetC((std::intptr_t)this)))->FUN_005ae3d0();
    return true;
}

struct SpellNode
{
    int Count();
};

struct SpellListView
{
    bool DiffersFrom(BaseFormComponent* apOther);
};

// Compares this spell list against another TESSpellList, returning true if any spell or level spell is missing or the counts differ.
// @fnv 0x0048d700
bool SpellListView::DiffersFrom(BaseFormComponent* apOther)
{
    SpellListView* pOtherList = (SpellListView*)dynamic_cast<TESSpellList*>(apOther);
    if (!pOtherList)
        return true;
    int iSpellCount = 0;
    SpellNode* pSpellNode = ((::SpellNode *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    while (pSpellNode)
    {
        void* pSpell = ((void *)((void *)(pSpellNode)));
        if (pSpell)
        {
            if (!reinterpret_cast<::Holder_0048d830 *>((pOtherList))->ContainsPackage((::ActorPackageContext *)(pSpell)))
                return true;
            iSpellCount++;
        }
        pSpellNode = ((::SpellNode *)(reinterpret_cast<::Callees *>((pSpellNode))->FUN_00726070()));
    }
    if (((::SpellNode *)(reinterpret_cast<::BaseProcess *>((pOtherList))->GetCurrentProcessData()))->Count() != iSpellCount)
        return true;
    {
        int iLevSpellCount = 0;
        SpellNode* pLevSpellNode = ((::SpellNode *)(::GetOffsetC((std::intptr_t)this)));
        while (pLevSpellNode)
        {
            void* pLevSpell = ((void *)((void *)(pLevSpellNode)));
            if (pLevSpell)
            {
                if (!reinterpret_cast<::FUN_0048d880_shell *>((pOtherList))->FUN_0048d880(((void *)((void *)(pLevSpellNode)))))
                    return true;
                iLevSpellCount++;
            }
            pLevSpellNode = ((::SpellNode *)(reinterpret_cast<::Callees *>((pLevSpellNode))->FUN_00726070()));
        }
        if (((::SpellNode *)(::GetOffsetC((std::intptr_t)(pOtherList))))->Count() != iLevSpellCount)
            return true;
    }
    return false;
}

struct SavedRecord
{
    unsigned int id;
    unsigned char kind;
    unsigned char flags[4];
    unsigned char version;
};
struct TESSaveLoadGame
{
};
struct LoadedList
{
    void* item;
    LoadedList* next;
    void AddHead(SpellItem*&);
    void AddHead(TESLevSpell*&);
};
struct LoadedSpells
{
    void* vtable;
    LoadedList spells;
    LoadedList leveledSpells;
    void LoadSpellList(unsigned int, unsigned int);
};
// Reads a spell-list block from the save buffer, clearing and refilling the spell and leveled-spell lists and warning on header or size mismatches.
// @fnv 0x0048dca0
void LoadedSpells::LoadSpellList(unsigned int flags, unsigned int unused)
{
    int p;
    if (flags & 16)
    {
        unsigned short h = 0;
        unsigned int a = 0;
        if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
        {
            unsigned int s;
            reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&s, 4);
            if (s != 0x424c4f4b)
            {
                SavedRecord* f = ((::SavedRecord *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(g_TESSaveLoadGame))));
                if (f)
                {
                    TESForm* eb = FUN_004839c0(f->id);
                    ::FUN_005b5e40(
                        );
                }
                else
                {
                    ::FUN_005b5e40(
                        );
                }
            }
            a = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((g_TESSaveLoadGame))->FUN_00825c00();
            reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&h, 2);
        }
        reinterpret_cast<::FileMatchList *>(&(spells))->RemoveAll();
        reinterpret_cast<::FileMatchList *>(&(leveledSpells))->RemoveAll();
        unsigned short i;
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&i, 2);
        for (p = 0; p < i; p++)
        {
            unsigned int b;
            reinterpret_cast<::FUN_00857aa0 *>((g_TESSaveLoadGame))->ValidateFormIDArray(&b, 4);
            SpellItem* q = dynamic_cast<SpellItem*>(FUN_004839c0(b));
            TESLevSpell* cf = dynamic_cast<TESLevSpell*>(FUN_004839c0(b));
            if (q)
            {
                spells.AddHead(q);
            }
            else if (cf)
            {
                bool ba = true;
                if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() < 71 && reinterpret_cast<::RefList *>(&(leveledSpells))->FUN_005f65d0((void **)&(cf)))
                    ba = false;
                if (ba)
                    leveledSpells.AddHead(cf);
            }
            else
            {
                ::FUN_005b5e40();
            }
        }
        if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
        {
            unsigned int l = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((g_TESSaveLoadGame))->FUN_00825c00();
            SavedRecord* k = ((::SavedRecord *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(g_TESSaveLoadGame))));
            if (k)
            {
                TESForm* c = FUN_004839c0(k->id);
                if (l > a + h)
                {
                    ::FUN_005b5e40(
                        );
                }
                else if (l < a + h)
                {
                    ::FUN_005b5e40(
                        );
                }
            }
            else
            {
                if (l > a + h)
                {
                    ::FUN_005b5e40(
                        );
                }
                else if (l < a + h)
                {
                    ::FUN_005b5e40(
                        );
                }
            }
        }
    }
}

class ActorPackageContext
{
  public:
};
struct TESSpellListShell : TESSpellList
{
    void FUN_0048d330();
};
// @fnv 0x0048d330
void TESSpellListShell::FUN_0048d330()
{
    ListNode* currentLeveledSpell = ((::ListNode *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    unsigned int currentSpell;
    ActorPackageContext* spell;
    while (currentLeveledSpell != 0 && (spell = ((::ActorPackageContext *)((void *)(currentLeveledSpell)))) != 0)
    {
        if (!reinterpret_cast<::FUN_00440d80_shell *>((spell))->FUN_00440d80())
        {
            currentSpell = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((spell))->FUN_0084e3a0()));
            ::FUN_00485910(0x4f4c5053, currentSpell);
        }
        currentLeveledSpell = ((::ListNode *)(reinterpret_cast<::Callees *>((currentLeveledSpell))->FUN_00726070()));
    }
    ListNode* leveledSpell = (ListNode*)((::BSSimpleList< ::InventoryStackRecord *> *)(::GetOffsetC((std::intptr_t)this)));
    {
        ActorPackageContext* formId;
        while (leveledSpell != 0 && (formId = ((::ActorPackageContext *)((void *)(leveledSpell)))) != 0)
        {
            if (!reinterpret_cast<::FUN_00440d80_shell *>((formId))->FUN_00440d80())
            {
                unsigned int leveledFormId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((formId))->FUN_0084e3a0()));
                ::FUN_00485910(0x4f4c5053, leveledFormId);
            }
            leveledSpell = ((::ListNode *)(reinterpret_cast<::Callees *>((leveledSpell))->FUN_00726070()));
        }
    }
}

namespace fnv_0048da20 {
class TimeGlobal
{
  public:
};

class TESWorldSpace;
class TES
{
  public:
};

class TESSaveLoadGame
{
  public:
};


class GlobalObject_0045cf30
{
  public:
    unsigned char* Bool();
};


class ActorMagicSpellList
{
  public:
};

class FUN_0048d880_shell
{
  public:
};


class TESSpellList_Target : public TESSpellList
{
  public:
    void SaveSpellList(unsigned int flags);
};

// If flags has bit 0x10, writes a BLOCK header and the spell count plus each spell's form ID to the save stream, with optional timing diagnostics.
// @fnv 0x0048da20
void TESSpellList_Target::SaveSpellList(unsigned int flags)
{
    if (flags & 0x10)
    {
        unsigned short unk0CVal = 0;
        unsigned short* pBlockSize3 = 0;
        unsigned int startPosData;
        unsigned int blok;
        unsigned short spellCount1;
        unsigned short* pNumSpells;
        BSSimpleList<SpellItem*>* curNodePtr;
        SpellItem* spell3;
        unsigned int spellID1;
        BSSimpleList<SpellItem*>* levNode2;
        SpellItem* levSpell2;
        unsigned int leveledID;
        unsigned int currentPos1;
        void* createdObj2;
        TESForm* form;
        std::uintptr_t startBlock;
        unsigned int posNow1;

        startPosData = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        if (*(*reinterpret_cast<::fnv_0048da20::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool())
            startPosData = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();

        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            blok = 0x424C4F4B;
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&blok, 4);
            pBlockSize3 = (unsigned short*)(std::uintptr_t)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unk0CVal, 2);
        }

        spellCount1 = 0;
        pNumSpells = (unsigned short*)(std::uintptr_t)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&spellCount1, 2);

        curNodePtr = ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<ActorMagicSpellList*>(this)))->GetCurrentProcessData()));
        while (curNodePtr)
        {
            spell3 = (curNodePtr->m_item);
            if (spell3)
            {
                spellID1 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((spell3))->FUN_0084e3a0()));
                reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&spellID1), 4);
                spellCount1++;
            }
            curNodePtr = ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::Callees *>((curNodePtr))->FUN_00726070()));
        }

        levNode2 =
            reinterpret_cast<BSSimpleList<SpellItem*>*>(((::BSSimpleList<void *> *)(::GetOffsetC((std::intptr_t)(reinterpret_cast<FUN_0048d880_shell*>(this))))));
        while (levNode2)
        {
            levSpell2 = (levNode2->m_item);
            if (levSpell2)
            {
                leveledID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((levSpell2))->FUN_0084e3a0()));
                reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&leveledID), 4);
                spellCount1++;
            }
            levNode2 = ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::Callees *>((levNode2))->FUN_00726070()));
        }

        *pNumSpells = spellCount1;

        if (*(*reinterpret_cast<::fnv_0048da20::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool())
        {
            currentPos1 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
            createdObj2 = ((::fnv_0048da20::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((reinterpret_cast<TES*>((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->GetHitSound()));
            if (createdObj2)
            {
                form = ::FUN_004839c0(*(unsigned int*)createdObj2);
                ::FUN_0040fbe0();
            }
            else
            {
                ::FUN_0040fbe0();
            }
        }

        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            posNow1 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>((*reinterpret_cast<::fnv_0048da20::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
            startBlock = (std::uintptr_t)pBlockSize3;
            if (posNow1 > startBlock + 0xFFFF)
            {
                ::FUN_005b5e40();
            }
            *pBlockSize3 = (unsigned short)(posNow1 - startBlock);
        }
    }
}
}  // namespace fnv_0048da20

namespace fnv_0048d630 {
struct SpellNode
{
    void FUN_005ae3d0(void*& spell);
};

struct SpellListAccess : TESSpellList
{
    void FUN_0048d630(BaseFormComponent* source);
};

// Copies all spells from the source TESSpellList into this list, clearing existing entries first.
// @fnv 0x0048d630
void SpellListAccess::FUN_0048d630(BaseFormComponent* source)
{
    TESSpellList* a = dynamic_cast<TESSpellList*>(source);
    if (a == 0)
        return;

    ClearSpells();

    SpellNode* f = ((::fnv_0048d630::SpellNode *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<SpellListAccess*>(a)))->GetCurrentProcessData()));
    SpellNode* b = ((::fnv_0048d630::SpellNode *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    void* d;
    while (f != 0)
    {
        d = ((void *)((void *)(f)));
        if (d != 0)
            b->FUN_005ae3d0(d);
        f = ((::fnv_0048d630::SpellNode *)(reinterpret_cast<::Callees *>((f))->FUN_00726070()));
    }

    SpellNode* e = reinterpret_cast<SpellNode*>(((::BSSimpleList< ::InventoryStackRecord *> *)(::GetOffsetC((std::intptr_t)(a)))));
    {
        SpellNode* c = reinterpret_cast<SpellNode*>(((::BSSimpleList< ::InventoryStackRecord *> *)(::GetOffsetC((std::intptr_t)this))));
        while (e != 0)
        {
            void* g = ((void *)((void *)(e)));
            if (g != 0)
                c->FUN_005ae3d0(g);
            e = ((::fnv_0048d630::SpellNode *)(reinterpret_cast<::Callees *>((e))->FUN_00726070()));
        }
    }
}
}  // namespace fnv_0048d630

struct S0048d8f0_Record
{
    unsigned int id;
    unsigned char unk04;
    unsigned char flags[4];
};
struct S0048d8f0_SaveGame
{
};
struct S0048d8f0_SettingStub
{
    unsigned char* Bool();
};
struct S0048d8f0_FormStub
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
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
struct S0048d8f0_SizedList
{
    void* item;
    S0048d8f0_SizedList* next;
    int GetSize();
};
struct S0048d8f0_SpellListSaveSizer
{
    void* vtable;
    S0048d8f0_SizedList spells;
    S0048d8f0_SizedList leveledSpells;
    unsigned short FUN_0048d8f0(unsigned int saveFlags);
};

// When saveFlags bit 0x10 is set, adds two bytes and list-size contributions, plus six bytes when the save-state check succeeds.
// @fnv 0x0048d8f0
unsigned short S0048d8f0_SpellListSaveSizer::FUN_0048d8f0(unsigned int saveFlags)
{
    unsigned short size = 0;
    if (saveFlags & 0x10)
    {
        unsigned short start = size;
        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::S0048d8f0_SaveGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            size += 4;
            size += 2;
        }
        size += 2;
        size += spells.GetSize() * 4;
        size += leveledSpells.GetSize() * 4;
        if (*(*reinterpret_cast<::S0048d8f0_SettingStub *>(&::g_011de4e8)).Bool())
        {
            S0048d8f0_Record* record = ((::S0048d8f0_Record *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::S0048d8f0_SaveGame * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
            if (record)
            {
                S0048d8f0_FormStub* form = ((::S0048d8f0_FormStub *)(::FUN_004839c0(record->id)));
                ::FUN_0040fbe0();
            }
            else
            {
                ::FUN_0040fbe0();
            }
        }
    }
    return size;
}

// sub ecx,0x7c; jmp FUN_005f18c0
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (0x7c = vptr + thirty int fields).
struct ThunkPrimaryBase_005fbf70
{
    virtual void FUN_005fbf70();
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
};

struct ThunkSecondaryBase_005fbf70
{
    virtual void FUN_005fbf70();
};

struct ThunkDerived_005fbf70 : ThunkPrimaryBase_005fbf70, ThunkSecondaryBase_005fbf70
{
    ThunkDerived_005fbf70();
// @fnv 0x005fbf70
    virtual void FUN_005fbf70();
};

ThunkDerived_005fbf70::ThunkDerived_005fbf70()
{}

// MSVC adjustor thunk: the primary base occupies 0x7c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase_005fbfe0
{
    virtual void FUN_005fbfe0();
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
};

struct SecondaryBase_005fbfe0
{
    virtual void FUN_005fbfe0();
};

struct Derived_005fbfe0 : PrimaryBase_005fbfe0, SecondaryBase_005fbfe0
{
    Derived_005fbfe0();
// @fnv 0x005fbfe0
    virtual void FUN_005fbfe0();
};

Derived_005fbfe0::Derived_005fbfe0()
{}

namespace fnv_005fc020 {
// Adjustor (this-adjusting) thunk for FUN_005fc020:
//     sub ecx, 0x7c ; jmp FUN_005f1b30
// MSVC emits such a thunk in the vftable of a class that inherits the same
// virtual from two bases: it converts the secondary base sub-object pointer
// back to the derived object pointer by subtracting the size of the primary
// base (0x7c = 4 byte vptr + 30 int members) and tail jumps to the
// implementation.  Both bases declare the virtual, the derived class
// redeclares it and only defines its constructor, which makes the compiler
// emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_005fc020();
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
};

struct SecondaryBase
{
    virtual void FUN_005fc020();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fc020
    virtual void FUN_005fc020();
};

Derived::Derived()
{}
}
