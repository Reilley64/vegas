// fallout/ai/alarmpackage.cpp: Crime, TESSpellList, Candidate, Cls and more (27 functions)

#include "fnv/save_load_game_view.h"
#include <cstdint>
#include <new>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00616c20_shell.h"
#include "fnv/decl/FUN_00678fd0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00855220_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_0085a2e0_Class.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_00972740_shell.h"
#include "fnv/decl/FUN_009727c0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/Package679120.h"
#include "fnv/decl/Package6798c0.h"
#include "fnv/decl/PackageCopy.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0047d680__FUN_0047d680_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_009a5f90__FUN_009a5f90_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "alarmpackage_decls.h"


// The leading members of Crime as the crime save code reads them. The 4-byte getter folded into 0x00726070 reads
// the crime type at +0x4.
struct CrimeTypeView
{
    unsigned int uiUnknown00;
    unsigned int uiCrimeType;
};

// If the buffer's change flags include 0x10, clears both spell lists and re-adds each SpellItem and TESLevSpell read from the buffer.
// @fnv 0x0048e140
void TESSpellList::LoadGame(BGSLoadFormBuffer* buffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x10)))->FUN_004280f0(0x10))
    {
        reinterpret_cast<::FileMatchList *>(&(spellList))->RemoveAll();
        reinterpret_cast<::FileMatchList *>(&(leveledSpellList))->RemoveAll();

        {
            unsigned int spellCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
            for (unsigned int i = 0; i < spellCount; ++i)
            {
                SpellItem* pLevSpell = 0;
                pLevSpell = dynamic_cast<SpellItem*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                if (pLevSpell)
                    spellList.AddHead(pLevSpell);
            }
        }

        {
            unsigned int leveledSpellCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
            for (unsigned int i = 0; i < leveledSpellCount; ++i)
            {
                TESLevSpell* pLevSpell = 0;
                pLevSpell = dynamic_cast<TESLevSpell*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                if (pLevSpell)
                    leveledSpellList.AddHead(pLevSpell);
            }
        }
    }
}

struct ChangesMap
{
};
struct FUN_0085a290_t
{
    ChangesMap* pChanges;
    void DeleteFormById(unsigned int id);
};
// @fnv 0x0085a290
void FUN_0085a290_t::DeleteFormById(unsigned int uiFormId)
{
    TESForm* pForm = ::FUN_004839c0(uiFormId);
    if (pForm)
        reinterpret_cast<::FUN_0085a2e0_Class *>(this)->FUN_0085a2e0(pForm);
    else
        reinterpret_cast<::FUN_00855220_shell *>((pChanges))->FUN_00855220(uiFormId, true);
}

struct Actor;
struct LH
{
};
struct Crime
{
    unsigned char _pad[0x1c];
    LH _list;
    bool IsActorInList(Actor* apActor);
};
// @fnv 0x009eb9a0
bool Crime::IsActorInList(Actor* apActor)
{
    return reinterpret_cast<::RefList *>(&(_list))->FUN_005f65d0((void **)&(apActor));
}

struct Actor;
struct SL
{
};
struct FUN_009eba00_t
{
    int m_uiItemCount;
    void FUN_009eba00(Actor* a);
};
// @fnv 0x009eba00
void FUN_009eba00_t::FUN_009eba00(Actor* apActor)
{
    reinterpret_cast<::ItemChangeListNode *>((reinterpret_cast<SL*>(reinterpret_cast<char*>(this) + 0x1c)))->FUN_00905330((::InventoryStackRecord *const &)(apActor));
    m_uiItemCount = m_uiItemCount - 1;
}

struct BSSimpleListTESRaceSize
{
    bool _ref_008256d0();
    int GetSize();
};
struct FUN_009ebab0_host
{
    char _pad[0x1C];
    BSSimpleListTESRaceSize _list;
    int GetRaceListSize();
};
// Returns 0 if the race list reference check succeeds, otherwise returns the list size.
// @fnv 0x009ebab0
int FUN_009ebab0_host::GetRaceListSize()
{
    if (_list._ref_008256d0())
        return 0;
    else
        return _list.GetSize();
}

struct FUN_009ec640_t
{
    void FUN_009ec700();
    FUN_009ec640_t* FUN_009ec640(unsigned int flags);
};
namespace fnv_009ec810 {
struct SpellItem;
struct LH
{
};
struct FUN_009ec810_t
{
    bool IsSpellInList(SpellItem* a);
};
// @fnv 0x009ec810
bool FUN_009ec810_t::IsSpellInList(SpellItem* pSpell)
{
    return reinterpret_cast<::RefList *>((void *)(reinterpret_cast<LH*>(reinterpret_cast<char*>(this) + 0x80)))->FUN_005f65d0((void **)&(pSpell));
}
}  // namespace fnv_009ec810

struct G2
{
    void AddHead(int* const& a);
};
struct FUN_009ec830_t
{
    void AddHeadAtOffset(int* a);
};
// @fnv 0x009ec830
void FUN_009ec830_t::AddHeadAtOffset(int* a)
{
    reinterpret_cast<G2*>(reinterpret_cast<char*>(this) + 0x80)->AddHead(a);
}

namespace fnv_009ec850 {
struct Actor
{
};
struct MyList
{
    bool _ref_008256d0();
};
struct FUN_009ec850_shell
{
    char _pad[0x80];
    MyList _list;
    void FUN_009ec850(uintptr_t, Actor*);
};
// @fnv 0x009ec850
void FUN_009ec850_shell::FUN_009ec850(uintptr_t a, Actor* pActor)
{
    reinterpret_cast<::ItemChangeListNode *>(&(_list))->FUN_00905330((::InventoryStackRecord *const &)(a));
    if (_list._ref_008256d0())
        reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>((pActor))->FUN_00881680(0);
}
}  // namespace fnv_009ec850

struct List005fda50
{
};
struct Crime005fda50
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
    virtual void v18(int);
    char _pad04[0x34];
    List005fda50* pList38;
    char _pad3C[8];
    int i44;
    void FUN_005fda50(int, bool);
};
// @fnv 0x005fda50
void Crime005fda50::FUN_005fda50(int aiAmount, bool b)
{
    i44 += aiAmount;
    if (pList38 && b)
        reinterpret_cast<::FUN_00616c20_shell *>((pList38))->FUN_00616c20(1);
    v18(0x80000000);
}

namespace fnv_009eb9c0 {
struct FUN_009eb9c0_list
{
    void AddHead(Actor* const& a);
};
struct Crime
{
    int BackgroundTask;
    char pad[0x18];
    FUN_009eb9c0_list actors;
    void AddActor(Actor* apActor);
};
// @fnv 0x009eb9c0
void Crime::AddActor(Actor* apActor)
{
    if (!reinterpret_cast<::RefList *>(&(actors))->FUN_005f65d0((void **)&(apActor)))
    {
        actors.AddHead(apActor);
        BackgroundTask = BackgroundTask + 1;
    }
}
}  // namespace fnv_009eb9c0

struct FUN_009eba30_t;
struct FUN_009eba30_xl
{
};
struct FUN_0041cf00_shell
{
    FUN_009eba30_xl* FUN_0041cf00();
};
struct XActor
{
};
struct FUN_009eba30_node
{
};
struct FUN_009eba30_t
{
    int BackgroundTask;
    char pad[0x18];
    FUN_009eba30_node list;
    void FUN_009eba30();
};
// @fnv 0x009eba30
void FUN_009eba30_t::FUN_009eba30()
{
    FUN_009eba30_node* pnode = &list;
    while (pnode && *((::XActor **)(((::Vec3 *)(void *)(pnode)))))
    {
        XActor* pActor = *((::XActor **)(((::Vec3 *)(void *)(pnode))));
        FUN_009eba30_xl* pList = ((::FUN_0041cf00_shell *)(reinterpret_cast<::FUN_005d43c0_ *>((void *)(pActor))->FUN_005d43c0()))->FUN_0041cf00();
        if (pList)
            reinterpret_cast<::ItemChangeListNode *>((pList))->FUN_00905330((::InventoryStackRecord *const &)((const ::FUN_009eba30_t *const &)(this)));
        pnode = ((::FUN_009eba30_node *)(reinterpret_cast<::Callees *>((pnode))->FUN_00726070()));
    }
    BackgroundTask = 0;
}

struct FUN_009ec5d0_pkg
{
    char pad[0x7c];
    FUN_009ec5d0_pkg();
    ~FUN_009ec5d0_pkg();
    virtual void v0();
};
struct FUN_009ec5d0_sl
{
    FUN_009ec5d0_sl();
};
struct FUN_009ec5d0 : public FUN_009ec5d0_pkg
{
    FUN_009ec5d0_sl list;
    FUN_009ec5d0();
};
// Constructs the object: initializes the base subobject and the embedded list member.
// @fnv 0x009ec5d0
FUN_009ec5d0::FUN_009ec5d0()
{}

struct FUN_009ec670_pkg
{
    char pad[0x7c];
    FUN_009ec670_pkg();
    ~FUN_009ec670_pkg();
    virtual void v0();
};
struct FUN_009ec670_sl
{
    FUN_009ec670_sl();
    ~FUN_009ec670_sl();
    void AddHead(Actor* const& a);
};
struct FUN_009ec670 : public FUN_009ec670_pkg
{
    FUN_009ec670_sl list;
    FUN_009ec670(Actor* apActor);
};
// Constructs the object and, if apActor is non-null, adds it to the head of the list.
// @fnv 0x009ec670
FUN_009ec670::FUN_009ec670(Actor* apActor)
{
    if (apActor)
        list.AddHead(apActor);
}

struct FUN_009ec700_pkg
{
    char pad[0x7c];
    ~FUN_009ec700_pkg();
    virtual void v0();
};
struct FUN_009ec700_sl
{
    ~FUN_009ec700_sl();
};
struct FUN_009ec700 : public FUN_009ec700_pkg
{
    FUN_009ec700_sl list;
    ~FUN_009ec700();
};
// @fnv 0x009ec640
FUN_009ec640_t* FUN_009ec640_t::FUN_009ec640(unsigned int flags)
{
    reinterpret_cast<::FUN_009ec700 *>(this)->FUN_009ec700::~FUN_009ec700();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that removes all entries from the list member before the base package destructor runs.
// @fnv 0x009ec700
FUN_009ec700::~FUN_009ec700()
{
    reinterpret_cast<::FileMatchList *>(&(list))->RemoveAll();
}


struct FUN_009ebae0_shell
{
    void AddActorToList(Actor* a);
    unsigned int pad00[0xe];
    void* unk38;
};

// Creates the BSSimpleList at offset 0x38 if null, then adds the given Actor to its head.
// @fnv 0x009ebae0
void FUN_009ebae0_shell::AddActorToList(Actor* apActor)
{
    if (!*(BSSimpleList<Actor*>**)&this->unk38)
    {
        *(BSSimpleList<Actor*>**)&this->unk38 = new BSSimpleList<Actor*>;
    }
    (*(BSSimpleList<Actor*>**)&this->unk38)->AddHead(apActor);
}

struct DialoguePackage
{
};

struct List_009e03e0
{
};

struct CrimeNode
{
};

struct AlarmPackage : public TESForm
{
};

struct FUN_009ec780_shell : public AlarmPackage
{
    void FUN_009ec780(TESForm* apCopy);
};

// @fnv 0x009ec780
void FUN_009ec780_shell::FUN_009ec780(TESForm* apCopy)
{
    AlarmPackage* pAlarmSource;
    CrimeNode* pCurrentElementNext;

    reinterpret_cast<::PackageCopy *>((((DialoguePackage*)this)))->CopyFromPackage(apCopy);
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)((char*)this + 0x80))))->RemoveAll();
    pAlarmSource = dynamic_cast<AlarmPackage*>(apCopy);
    if (pAlarmSource)
    {
        pCurrentElementNext = ((::CrimeNode *)(reinterpret_cast<::TESDataHandler *>((pAlarmSource))->GetTESClassList()));
        while (pCurrentElementNext && *((int **)(((::Vec3 *)(void *)(pCurrentElementNext)))))
        {
            ((G2*)((char*)this + 0x80))->AddHead(*((int **)(((::Vec3 *)(void *)(pCurrentElementNext)))));
            pCurrentElementNext = ((::CrimeNode *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        }
    }
}

struct Saver
{
};

struct TESSaveLoadGame
{
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};


struct Interface
{
};

struct FormWithID
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
    virtual const char* GetEditorID();
};

struct FUN_009ec890_shell : public Saver
{
    unsigned short FUN_009ec890();
};

// @fnv 0x009ec890
unsigned short FUN_009ec890_shell::FUN_009ec890()
{
    unsigned short isaveGameCount = 0;
    isaveGameCount += reinterpret_cast<::FUN_00678fd0_shell *>(this)->FUN_00678fd0();
    unsigned short isaveGameBufferPos = isaveGameCount;
    if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
    {
        isaveGameCount += 4;
        isaveGameCount += 2;
    }
    if (*::g_011de4e8.Bool())
    {
        char* header = (char*)((void *)(reinterpret_cast<::EffectSetting *>((g_TESSaveLoadGame))->GetHitSound()));
        if (header)
        {
            TESForm* form = ::FUN_004839c0(*(unsigned int*)header);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return isaveGameCount;
}

namespace fnv_009ecec0 {
struct BGSSaveFormBuffer
{
};

struct CrimeNode : public BSSimpleList<Crime*>
{
};

struct ProcessLists
{
};

struct FUN_009ecec0_shell
{
    void SaveCrimeList(BGSSaveFormBuffer* apSaveGameBuffer);
};

// Iterates the crime list, saving each crime's type byte and index, then writes the count and buffer position.
// @fnv 0x009ecec0
void FUN_009ecec0_shell::SaveCrimeList(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int isaveGameCount = 0;
    unsigned int isaveGameBufferPos = reinterpret_cast<::FUN_00865f20_shell *>((apSaveGameBuffer))->FUN_00865f20();
    CrimeNode* pCurrentElementNext = reinterpret_cast<CrimeNode*>((char*)this + 0x80);
    while (pCurrentElementNext)
    {
        Crime* pcrime = *((::Crime **)(((::Vec3 *)(void *)(pCurrentElementNext))));
        if (pcrime)
        {
            char ccrimeType = (char)reinterpret_cast<::CrimeTypeView*>(pcrime)->uiCrimeType;
            unsigned short icrimeIndex = reinterpret_cast<::FUN_00972740_shell *>(&((*reinterpret_cast<::fnv_009ecec0::ProcessLists *>(&::g_011e0e80))))->FUN_00972740(ccrimeType, (::BGSPerk *)(pcrime));
            reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&ccrimeType, 1, 0);
            reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&icrimeIndex, 2, 0);
            isaveGameCount++;
        }
        pCurrentElementNext = static_cast<CrimeNode*>(((::BSSimpleList< ::Crime *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070())));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((apSaveGameBuffer))->FUN_00865ff0(isaveGameCount, isaveGameBufferPos);
}
}  // namespace fnv_009ecec0

struct TESPackage
{
};

struct BGSLoadFormBuffer_Accessor : BGSLoadFormBuffer
{
};

struct ProcessLists
{
};

struct FUN_009ecf70_shell : public TESPackage
{
    void LoadCrimeList(BGSLoadFormBuffer* apLoadGameBuffer);
};

// Loads the base package, then reads a count and for each entry reads a crime type and index, resolving each crime and adding it to the list at offset 0x80.
// @fnv 0x009ecf70
void FUN_009ecf70_shell::LoadCrimeList(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::Package6798c0 *>(this)->LoadPackage((::LoadBuffer6798c0 *)(apLoadGameBuffer));
    unsigned int isaveGameCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
    for (unsigned int iIndex = 0; iIndex < isaveGameCount; ++iIndex)
    {
        char ccrimeType = 0;
        unsigned short icrimeIndex = 0;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((static_cast<BGSLoadFormBuffer_Accessor*>(apLoadGameBuffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ccrimeType), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((static_cast<BGSLoadFormBuffer_Accessor*>(apLoadGameBuffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&icrimeIndex), 2);
        Crime* pcrime = reinterpret_cast<::FUN_009727c0_shell *>(&((*reinterpret_cast<::ProcessLists *>(&::g_011e0e80))))->FUN_009727c0(ccrimeType, icrimeIndex);
        if (pcrime)
        {
            reinterpret_cast<G2*>((char*)this + 0x80)->AddHead((int*&)pcrime);
        }
    }
}

extern const char $SG7034[];
extern const char $SG7035[];
extern const char $SG7038[];

struct FUN_009ebb80_hit_sound
{
    unsigned int formID;
};

struct FUN_009ebb80_form
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
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual void v64()
    {}
    virtual void v65()
    {}
    virtual void v66()
    {}
    virtual void v67()
    {}
    virtual void v68()
    {}
    virtual void v69()
    {}
    virtual void v70()
    {}
    virtual void v71()
    {}
    virtual void v72()
    {}
    virtual const char* GetEditorID()
    {
        return 0;
    }
    virtual void v73()
    {}
    virtual void v74()
    {}
    virtual const char* v75()
    {
        return 0;
    }
};

struct FUN_009ebb80_shell
{
    char pad[0x1c];
    BSSimpleListTESRaceSize list;

    unsigned short FUN_009ebb80();
};

// @fnv 0x009ebb80
unsigned short FUN_009ebb80_shell::FUN_009ebb80()
{
    unsigned short usTotalSize = 0;
    {
        unsigned short usStartSize = usTotalSize;
        FUN_009ebb80_hit_sound* SoundAssetTmp;

        if (reinterpret_cast<::FUN_00862110_cls *>((::g_TESSaveLoadGame))->FUN_00862110())
        {
            usTotalSize += 4;
            usTotalSize += 2;
        }

        usTotalSize += 0x10;
        usTotalSize += 0x10;
        usTotalSize += list.GetSize() * 4 + 2;

        if (*::g_011de4e8.Bool())
        {
            SoundAssetTmp = reinterpret_cast<FUN_009ebb80_hit_sound*>(((void *)(reinterpret_cast<::EffectSetting *>((::g_TESSaveLoadGame))->GetHitSound())));

            if (SoundAssetTmp)
            {
                FUN_009ebb80_form* pForm = reinterpret_cast<FUN_009ebb80_form*>(::FUN_004839c0(SoundAssetTmp->formID));

                ::FUN_0040fbe0();
            }
            else
            {
                ::FUN_0040fbe0();
            }
        }

        return usTotalSize;
    }
}

struct SaveLocal
{
};
struct AuxLocal
{
    unsigned int value;
};
struct NodeLocal
{
    TESForm* item;
    NodeLocal* next;
};
struct Candidate
{
    unsigned int unk00, unk04;
    TESForm* form08;
    TESForm* form0c;
    unsigned char flag10;
    TESForm* form14;
    unsigned int unk18;
    NodeLocal list1c;
    TESForm* form24;
    unsigned int unk28;
    unsigned char flag2c;
    unsigned int unk30;
    AuxLocal aux34;
    NodeLocal* list38;
    void SaveToStream(SaveLocal* buffer);
};
// Writes the candidate's scalar fields, aux34, four forms and both linked lists of forms to the save buffer, patching each list's count.
// @fnv 0x009ebfe0
void Candidate::SaveToStream(SaveLocal* buffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk00, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk04, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&flag10, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk18, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk28, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&flag2c, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk30, 4, 0);
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>(&(aux34))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(form08), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(form0c), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(form14), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(form24), 0);
    int count6 = 0;
    unsigned int pos1 = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();
    NodeLocal* node9 = &list1c;
    while (node9)
    {
        TESForm* item1 = *((::TESForm **)(((::Vec3 *)(void *)(node9))));
        if (item1)
        {
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(item1), 0);
            ++count6;
        }
        node9 = ((::NodeLocal *)(reinterpret_cast<::Callees *>((node9))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count6, pos1);
    {
        int count7 = 0;
        unsigned int pos3 = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();
        NodeLocal* nodeTmp = list38;
        while (nodeTmp)
        {
            TESForm* item6 = *((::TESForm **)(((::Vec3 *)(void *)(nodeTmp))));
            if (item6)
            {
                reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(item6), 0);
                ++count7;
            }
            nodeTmp = ((::NodeLocal *)(reinterpret_cast<::Callees *>((nodeTmp))->FUN_00726070()));
        }
        reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count7, pos3);
    }
}

namespace fnv_00970b30 {
// 0x00970b30  /MT /Od /Oy- /GS /EHsc /Gy
struct TESFaction;
struct BaseProcess;
struct TESActorBase;

struct Actor
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual bool v64();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual bool v87();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual bool v8b(int a);
    TESActorBase* GetActorBase();
};

struct ProcVt
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p180();
    virtual int v181(Actor* a, int b);
};

struct TESActorBaseData
{
};
struct Arr
{
};


struct Cls
{
    char pad00[4];
    Actor* FUN_00970b30(TESFaction* fac, bool a2, bool a3);
};

// Scans the actor array for a faction member passing the rank and process checks, optionally picking the one with the lowest value from FUN_005723b0.
// @fnv 0x00970b30
Actor* Cls::FUN_00970b30(TESFaction* pFaction, bool bRequireProcess, bool bPickBest)
{
    Actor* pB = 0;
    Actor* g4 = 0;
    float pE = ::DAT_01022958;
    Actor* e8 = 0;
    Actor* d4 = 0;
    Actor* c4 = 0;
    for (unsigned int i = 0; !(pB && bPickBest) && i < reinterpret_cast<::FUN_005be5c0_shell *>((((Arr*)((char*)this + 4))))->FUN_005be5c0(0); i++)
    {
        Actor* v20 = 0;
        float f24 = 0.0f;
        g4 = ((::fnv_00970b30::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((Arr*)((char*)this + 4))))->FUN_00968670(i)));
        if (g4 && g4->v64())
            v20 = g4;
        if (v20 && !v20->v8b(0) && !((bool)(reinterpret_cast<::FUN_00437bd0_stub *>((v20))->FUN_00437bd0())) &&
            reinterpret_cast<::fnv_0047d680::FUN_0047d680_shell *>((((TESActorBaseData*)((char*)v20->GetActorBase() + 0x30))))->GetFactionRank((::fnv_0047d680::TESFaction *)(pFaction), v20 == (*reinterpret_cast<::fnv_00970b30::Actor * *>(&::_g_thePlayer))) >
                -1 &&
            (!bRequireProcess || ((ProcVt*)((::fnv_00970b30::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((v20))->GetBaseTexture())))->v181((*reinterpret_cast<::fnv_00970b30::Actor * *>(&::_g_thePlayer)), 0) > 0))
        {
            pB = v20;
            if (bPickBest)
            {
                f24 = reinterpret_cast<::RefS *>((v20))->FUN_005723b0((::RefS *)((*reinterpret_cast<::fnv_00970b30::Actor * *>(&::_g_thePlayer))), 0, 0);
                if (f24 < pE)
                {
                    e8 = v20;
                    if (e8->v87())
                    {
                        c4 = e8;
                        e8 = 0;
                    }
                    pE = f24;
                }
            }
            if (v20->v87())
            {
                d4 = pB;
                pB = 0;
            }
        }
    }
    if (!pB && d4)
    {
        pB = d4;
        if (bPickBest)
        {
            e8 = c4;
            pB = e8;
        }
    }
    else
    {
        if (bPickBest && e8)
            pB = e8;
    }
    return pB;
}
}  // namespace fnv_00970b30

// WriteToSave - Candidate::SaveGame (BLOK block writer)

struct MyNode;

struct FormRec
{
    unsigned int formID;
    unsigned char unk04;
    unsigned int flags;
};

struct MyNode
{
    TESForm* item;
    MyNode* next;
    bool FUN_008256d0();
};

struct SaveMgr
{
};


extern const char DAT_01092b94[];


struct MyCand
{
    int unk00;
    int unk04;
    TESForm* form08;
    TESForm* form0c;
    unsigned char flag10;
    char pad10[3];
    TESForm* form14;
    unsigned int unk18;
    MyNode list1c;
    TESForm* form24;
    unsigned int unk28;
    unsigned char flag2c;
    char pad2c[3];
    unsigned int unk30;
    unsigned int aux34;
    MyNode* list38;
    void WriteToSave();
};

// Serializes the candidate's flags, form IDs and linked-list form IDs to the save stream, with optional block header and size patching.
// @fnv 0x009ebca0
void MyCand::WriteToSave()
{
    unsigned short a7 = 0;
    char* aa = 0;
    char* a9 = ((char *)(reinterpret_cast<SaveLoadGameView*>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->pBufferCursor));

    if (*::g_011de4e8.Bool())
        a9 = ((char *)(reinterpret_cast<SaveLoadGameView*>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->pBufferCursor));

    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        int a5 = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&a5, 4);
        aa = ((char *)(reinterpret_cast<SaveLoadGameView*>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->pBufferCursor));
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&a7, 2);
    }

    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&flag10, 1);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&flag2c, 1);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unk04, 4);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unk18, 4);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unk28, 4);

    int a1 = 0;
    if (form08)
        a1 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form08))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&a1), 4);

    int a1c = 0;
    if (form0c)
        a1c = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form0c))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&a1c), 4);

    int actor2 = 0;
    if (form14)
        actor2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form14))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&actor2), 4);

    int ang4 = 0;
    if (form24)
        ang4 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form24))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&ang4), 4);

    unsigned short a38 = 0;
    unsigned short* a8 = (unsigned short*)((char *)(reinterpret_cast<SaveLoadGameView*>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->pBufferCursor));
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&a38, 2);

    MyNode* action9 = &list1c;
    while (action9 && !action9->FUN_008256d0())
    {
        TESForm* active = *((::TESForm **)(((::Vec3 *)(void *)(action9))));
        int ac = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((active))->FUN_0084e3a0()));
        reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&ac), 4);
        a38++;
        action9 = ((::MyNode *)(reinterpret_cast<::Callees *>((action9))->FUN_00726070()));
    }
    *(unsigned short*)a8 = a38;

    if (*::g_011de4e8.Bool())
    {
        char* a4 = ((char *)(reinterpret_cast<SaveLoadGameView*>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->pBufferCursor));
        FormRec* ang8 = ((::FormRec *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (ang8)
        {
            TESForm* pLookup = ::FUN_004839c0(ang8->formID);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }

    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        char* agg = ((char *)(reinterpret_cast<SaveLoadGameView*>(((*reinterpret_cast<::SaveMgr * *>(&::g_TESSaveLoadGame))))->pBufferCursor));
        char* agg4 = aa;
        if (agg > agg4 + 0xffff)
            ::FUN_005b5e40();
        *(unsigned short*)aa = (unsigned short)(agg - agg4);
    }
}

extern "C" char DAT_01183108;
extern "C" char DAT_01183028;
extern "C" char DAT_01184704;
struct Reader009
{
};
class TESBoundObject : public TESForm
{
};
class TESFaction : public TESForm
{
};
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct List009
{
    char data[8];
    List009();
    ~List009();
    void FUN_005ae3d0(void**);
};
struct Field009
{
};
struct Host009
{
    unsigned a, b, c, d;
    char e;
    char pad11[3];
    void* f;
    unsigned g;
    List009 list;
    unsigned h, j;
    char k;
    char pad2d[3];
    unsigned l;
    Field009 field;
    char pad35[3];
    List009* strings;
    void ReadFromStream(Reader009* r);
};
// Reads fields, a nested field, form references and two lists from the stream, then discards the faction list if it is empty.
// @fnv 0x009ec1a0
void Host009::ReadFromStream(Reader009* apReader)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apReader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apReader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&b), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apReader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&e), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apReader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&g), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apReader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&j), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apReader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&k), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apReader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&l), 4);
    reinterpret_cast<::CombatTargetTimestamp *>(&(field))->LoadGame((::BGSLoadGameBuffer *)(apReader));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apReader))->FUN_008648e0((unsigned int *)(void *)(&c));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apReader))->FUN_008648e0((unsigned int *)(void *)(&d));
    f = dynamic_cast<TESBoundObject*>(::FUN_004839c0((unsigned int)(uintptr_t)(((void *)(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apReader))->FUN_008648a0())))));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apReader))->FUN_008648e0((unsigned int *)(void *)(&h));
    {
        unsigned count = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apReader))->FUN_00864a60()));
        for (unsigned i = 0; i < count; i++)
        {
            void* item = 0;
            reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apReader))->FUN_008648e0((unsigned int *)(void *)(&item));
            list.FUN_005ae3d0(&item);
        }
    }
    strings = new List009;
    {
        unsigned uiFactionCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apReader))->FUN_00864a60()));
        for (unsigned uiFactionIndex = 0; uiFactionIndex < uiFactionCount; uiFactionIndex++)
        {
            void* pFaction = 0;
            pFaction = dynamic_cast<TESFaction*>(::FUN_004839c0((unsigned int)(uintptr_t)(((void *)(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apReader))->FUN_008648a0())))));
            if (pFaction)
                strings->FUN_005ae3d0(&pFaction);
        }
    }
    if (!*((void **)(((::Vec3 *)(void *)(strings)))))
    {
        delete strings;
        strings = 0;
    }
}

struct S00679120
{
};
struct TimeGlobal
{
};
struct TESSaveLoadGameHelper
{
};
struct ProcessLists9EC990
{
};
struct CrimeList
{
};

struct FUN_009ec990_host
{
    void FUN_009ec990();
};

// @fnv 0x009ec990
void FUN_009ec990_host::FUN_009ec990()
{
    reinterpret_cast<::Package679120 *>((((S00679120*)this)))->SavePackage();

    unsigned short usVersion7 = 0;
    unsigned short* pSizeTmp = 0;
    char* uiStart3 = reinterpret_cast<SaveLoadGameView*>((((TimeGlobal*)g_TESSaveLoadGame)))->pBufferCursor;
    if (*::g_011de4e8.Bool())
        uiStart3 = reinterpret_cast<SaveLoadGameView*>((((TimeGlobal*)g_TESSaveLoadGame)))->pBufferCursor;

    if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
    {
        unsigned int uiMagic_2 = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>((((TESSaveLoadGameHelper*)g_TESSaveLoadGame)))->FUN_008579b0(&uiMagic_2, 4);
        pSizeTmp = (unsigned short*)reinterpret_cast<SaveLoadGameView*>((((TimeGlobal*)g_TESSaveLoadGame)))->pBufferCursor;
        reinterpret_cast<::FUN_008579b0_shell *>((((TESSaveLoadGameHelper*)g_TESSaveLoadGame)))->FUN_008579b0(&usVersion7, 2);
    }

    unsigned short m_usPassCountLocal = 0;
    unsigned short* aPCount = (unsigned short*)reinterpret_cast<SaveLoadGameView*>((((TimeGlobal*)g_TESSaveLoadGame)))->pBufferCursor;
    reinterpret_cast<::FUN_008579b0_shell *>((((TESSaveLoadGameHelper*)g_TESSaveLoadGame)))->FUN_008579b0(&m_usPassCountLocal, 2);

    BSSimpleList<void*>* pNodeX = 0;
    while (pNodeX != 0 && !pNodeX->IsEmpty())
    {
        void* pv = ((void *)(((::Vec3 *)(void *)(pNodeX))));
        char cIndex2 = (char)reinterpret_cast<::CrimeTypeView*>(pv)->uiCrimeType;
        reinterpret_cast<::FUN_008579b0_shell *>((((TESSaveLoadGameHelper*)g_TESSaveLoadGame)))->FUN_008579b0(&cIndex2, 1);
        unsigned short usResult6 = reinterpret_cast<::FUN_00972740_shell *>((((ProcessLists9EC990*)&(*reinterpret_cast<::ProcessLists *>(&::g_011e0e80)))))->FUN_00972740((int)cIndex2, (::BGSPerk *)(pv));
        reinterpret_cast<::FUN_008579b0_shell *>((((TESSaveLoadGameHelper*)g_TESSaveLoadGame)))->FUN_008579b0(&usResult6, 2);
        m_usPassCountLocal++;
        pNodeX = ((::BSSimpleList<void *> *)(reinterpret_cast<::Callees *>((pNodeX))->FUN_00726070()));
    }
    *aPCount = m_usPassCountLocal;

    if (*::g_011de4e8.Bool())
    {
        char* uiEnd = reinterpret_cast<SaveLoadGameView*>((((TimeGlobal*)g_TESSaveLoadGame)))->pBufferCursor;
        unsigned char* pRec9 = (unsigned char*)((void *)(reinterpret_cast<::EffectSetting *>((g_TESSaveLoadGame))->GetHitSound()));
        if (pRec9 != 0)
        {
            FormWithID* pForm3 = (FormWithID*)((void *)(::FUN_004839c0(*(unsigned int*)pRec9)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }

    if (reinterpret_cast<::FUN_00862110_cls *>((g_TESSaveLoadGame))->FUN_00862110())
    {
        uintptr_t uiEnd9 = reinterpret_cast<uintptr_t>(reinterpret_cast<SaveLoadGameView*>((((TimeGlobal*)g_TESSaveLoadGame)))->pBufferCursor);
        uintptr_t uiStart2 = (uintptr_t)pSizeTmp;
        if (uiEnd9 > uiStart2 + 0xffff)
            ::FUN_005b5e40();
        *(unsigned short*)pSizeTmp = (unsigned short)(uiEnd9 - uiStart2);
    }
}

using ::TESObjectREFR;
using ::Actor;

class TESObjectREFR : public TESForm
{
  public:
};
class Actor : public TESObjectREFR
{
};

struct AlarmActorList
{
    Actor* data;
    AlarmActorList* next;
    bool FUN_008256d0();
    void FUN_00726c60(Actor* const& actor);
    void FUN_0063f7b0();
};
struct AlarmPackageData
{
    int unk00;
    int unk04;
    TESObjectREFR* ref;
    Actor* actor;
    int unk10;
    int unk14;
    int unk18;
    AlarmActorList actors;
    TESForm* other;
    void FUN_009ec400(void* unused);
};

// @fnv 0x009ec400
void AlarmPackageData::FUN_009ec400(void* unused)
{
    ref = ref ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(uintptr_t)ref)) : 0;
    actor = actor ? dynamic_cast<Actor*>(::FUN_004839c0((unsigned int)(uintptr_t)actor)) : 0;
    other = other ? ::FUN_004839c0((unsigned int)(uintptr_t)other) : 0;
    AlarmActorList* current = &actors;
    AlarmActorList* previous = 0;
    while (current && !current->FUN_008256d0())
    {
        Actor* entry = *((::Actor **)(((::Vec3 *)(void *)(current))));
        bool erase = false;
        if (entry)
        {
            entry = entry ? dynamic_cast<Actor*>(::FUN_004839c0((unsigned int)(uintptr_t)entry)) : 0;
            if (entry)
            {
                current->FUN_00726c60(entry);
            }
            else
            {
                erase = true;
            }
        }
        else
        {
            erase = true;
        }
        if (erase)
        {
            if (previous)
            {
                reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330((*(::InventoryStackRecord *const *)(((::Actor **)(((::Vec3 *)(void *)(current)))))));
                current = ((::AlarmActorList *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
            }
            else
            {
                current->FUN_0063f7b0();
            }
        }
        else
        {
            previous = current;
            current = ((::AlarmActorList *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
        }
    }
    if (ref)
    {
        reinterpret_cast<::fnv_00564db0::FUN_00564db0_cls *>((ref))->FUN_00564db0(1);
    }
}
