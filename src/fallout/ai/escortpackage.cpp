// fallout/ai/escortpackage.cpp: EscortActorPackageData (10 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/ActorPackageData.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0055d3b0__FUN_0055d3b0.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_008bc860__FUN_008bc860_StandIn.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_01068000.h"
#include "escortpackage_decls.h"

// Initializes the EscortActorPackageData object by calling FUN_0067d920, setting its vtable to kVtbl_UseWeaponActorPackageData, and clearing pActor.
// @fnv 0x0067d8f0
EscortActorPackageData::EscortActorPackageData()
{
    new ((void *)this) ::ActorPackageData();
    m_ppVirtualMethodTable = (*reinterpret_cast<void * (*)[]>(&::DAT_01068a88));
    pActor = 0;
}

struct G2
{
    void AddHead(Actor* const&);
};
struct LH
{
};
struct FUN_009f0a20
{
    G2 m_kNode;
    void RegisterActor(Actor* apActor);
};
// Adds apActor to the head of the list at offset 0x10 only if it is not already in that list.
// @fnv 0x009f0a20
void FUN_009f0a20::RegisterActor(Actor* apActor)
{
    if (!(reinterpret_cast<::RefList *>((((LH*)((char*)this + 0x10))))->FUN_005f65d0((void **)&(apActor))))
        ((G2*)((char*)this + 0x10))->AddHead(apActor);
}

struct S0980
{
    void* FUN_009f0980(unsigned int);
};
struct TESObjectREFR
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool IsActor();
};
struct H_9f0b70
{
    void RemoveActorFromList(Actor*);
    void FUN_009f0b70(TESObjectREFR*);
};
// If the deleted reference is an Actor, casts it to Actor and forwards it to RemoveActorFromList.
// @fnv 0x009f0b70
void H_9f0b70::FUN_009f0b70(TESObjectREFR* apDeletedObj)
{
    Actor* pactor;
    if (!apDeletedObj->IsActor())
        return;
    pactor = reinterpret_cast<Actor*>(apDeletedObj);
    RemoveActorFromList(pactor);
}

struct BSSimpleList_I
{
    void Remove(int);
};
struct BSSimpleList_Actor
{
    void Remove(Actor* const&);
};

// @fnv 0x009f0a60
void H_9f0b70::RemoveActorFromList(Actor* actor)
{
    reinterpret_cast<::ItemChangeListNode *>((((BSSimpleList_Actor*)((char*)this + 0x10))))->FUN_00905330((::InventoryStackRecord *const &)(actor));
}

struct RefH
{
};

struct FUN_008bc860_class
{
};

struct FUN_0055d3b0_class
{
};

struct ListStandin
{
    bool _ref_008256d0();
};


struct FUN_009f0a80_shell
{
    int FUN_009f0a80(Actor* apEscorter, void* apType);
};

// @fnv 0x009f0a80
int FUN_009f0a80_shell::FUN_009f0a80(Actor* apEscorter, void* apType)
{
    void* pNode;
    int iCount;

    pNode = (void*)((char*)this + 0x10);
    while (pNode)
    {
        Actor* pactor = (Actor*)*((void **)(((::Vec3 *)(void *)(pNode))));
        pNode = reinterpret_cast<::Callees *>((pNode))->FUN_00726070();
        if (pactor)
        {
            if (reinterpret_cast<::FUN_00440d80_shell *>((void *)(((RefH*)pactor)))->FUN_00440d80() || !reinterpret_cast<::fnv_008bc860::FUN_008bc860_StandIn *>((((FUN_008bc860_class*)pactor)))->FUN_008bc860(apEscorter))
            {
                reinterpret_cast<::ItemChangeListNode *>((((ListStandin*)((char*)this + 0x10))))->FUN_00905330((::InventoryStackRecord *const &)(pactor));
                if (!((ListStandin*)((char*)this + 0x10))->_ref_008256d0())
                {
                    pNode = (void*)((char*)this + 0x10);
                }
            }
        }
    }

    iCount = 0;
    for (pNode = (void*)((char*)this + 0x10); pNode; pNode = reinterpret_cast<::Callees *>((pNode))->FUN_00726070())
    {
        Actor* pactor = (Actor*)*((void **)(((::Vec3 *)(void *)(pNode))));
        if (pactor && reinterpret_cast<::fnv_0055d3b0::FUN_0055d3b0 *>((((FUN_0055d3b0_class*)pactor)))->IsOfType(apType))
        {
            iCount++;
        }
    }

    return iCount;
}

struct BGSSaveFormBuffer
{
};


struct FUN_009f0bb0_shell
{
    void SaveFormList(BGSSaveFormBuffer* apSaveGameBuffer);
    unsigned int pad00[0x2];
    void* unk08;
};

// Writes the form at offset 8, then each non-null form from the list at offset 0x10, and stores the count at the saved buffer position.
// @fnv 0x009f0bb0
void FUN_009f0bb0_shell::SaveFormList(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(this->unk08), 0);

    unsigned int isaveGameCount = 0;
    unsigned int isaveGameBufferPos = reinterpret_cast<::FUN_00865f20_shell *>((apSaveGameBuffer))->FUN_00865f20();
    void* pCurrentElementNext = (void*)((char*)this + 0x10);
    while (pCurrentElementNext)
    {
        void* pForm = *((void **)(((::Vec3 *)(void *)(pCurrentElementNext))));
        if (pForm)
        {
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pForm), 0);
            isaveGameCount++;
        }
        pCurrentElementNext = reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070();
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((apSaveGameBuffer))->FUN_00865ff0(isaveGameCount, isaveGameBufferPos);
}

struct BGSLoadGameBuffer
{
};

struct TESForm
{
    virtual ~TESForm();
};

struct TESPackage : public TESForm
{
};


struct StandIn006759b0
{
    void* FUN_006759b0();
};

struct FUN_009f0c40_shell
{
    void* pad00;
    void* pad04;
    TESPackage* pPackage;
    void* m_pEscortPackageData;
    G2 m_kNode;

    void LoadPackageAndActors(BGSLoadGameBuffer* apLoadGameBuffer);
};

// Resolves a TESPackage from the buffer's form id, stores its result, then reads a count of Actors and adds each to a list.
// @fnv 0x009f0c40
void FUN_009f0c40_shell::LoadPackageAndActors(BGSLoadGameBuffer* apLoadGameBuffer)
{
    pPackage = dynamic_cast<TESPackage*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apLoadGameBuffer))->FUN_008648a0()));
    m_pEscortPackageData = pPackage ? ((StandIn006759b0*)pPackage)->FUN_006759b0() : 0;

    unsigned int isaveGameCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
    for (unsigned int uiIndex = 0; uiIndex < isaveGameCount; uiIndex++)
    {
        Actor* pForm = 0;
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&pForm));
        m_kNode.AddHead(pForm);
    }
}

class B9F09B0Base
{
  public:
    virtual ~B9F09B0Base();

    int unk04;
    int unk08;
    int unk0C;
};

template <class T> class B9F09B0List
{
  public:
    ~B9F09B0List();
    void RemoveAll();

    T m_item;
    B9F09B0List* m_pkNext;
};

class FUN_009f09b0_cls : public B9F09B0Base
{
  public:
    virtual ~FUN_009f09b0_cls();

    B9F09B0List<void*> m_kEntries;
};
// Calls FUN_009f09b0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x009f0980
void* S0980::FUN_009f0980(unsigned int flags)
{
    reinterpret_cast<::FUN_009f09b0_cls *>(this)->FUN_009f09b0_cls::~FUN_009f09b0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that removes all entries from the m_kEntries list.
// @fnv 0x009f09b0
FUN_009f09b0_cls::~FUN_009f09b0_cls()
{
    reinterpret_cast<::FileMatchList *>(&(m_kEntries))->RemoveAll();
}

class Actor : public TESForm
{
};

struct ActorListNode
{
    bool IsEmpty();
    void SetItem(Actor* const&);
    void RemoveHead();
};

struct FUN_009f0cf0_arg
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual int f03();
};

struct FUN_009f0cf0_shell
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    ActorListNode m_kNode;

    void PruneActorList(FUN_009f0cf0_arg* apArg);
};

// Walks the actor list, re-resolves each entry via _ref_004839c0, removes entries that fail, then stores apArg->f03() in unk04.
// @fnv 0x009f0cf0
void FUN_009f0cf0_shell::PruneActorList(FUN_009f0cf0_arg* apArg)
{
    ActorListNode* pNode = &m_kNode;
    ActorListNode* pPrev = 0;
    while (pNode && !pNode->IsEmpty())
    {
        Actor* pActor = *((::Actor **)(((::Vec3 *)(void *)(pNode))));
        bool bRemove = false;
        if (pActor)
        {
            pActor = pActor ? dynamic_cast<Actor*>(::FUN_004839c0((unsigned int)(uintptr_t)pActor)) : 0;
            if (pActor)
                pNode->SetItem(pActor);
            else
                bRemove = true;
        }
        else
        {
            bRemove = true;
        }
        if (bRemove)
        {
            if (pPrev)
            {
                reinterpret_cast<::ItemChangeListNode *>((pPrev))->FUN_00905330((::InventoryStackRecord *const &)(*((::Actor **)(((::Vec3 *)(void *)(pNode))))));
                pNode = ((::ActorListNode *)(reinterpret_cast<::Callees *>((pPrev))->FUN_00726070()));
            }
            else
            {
                pNode->RemoveHead();
            }
        }
        else
        {
            pPrev = pNode;
            pNode = ((::ActorListNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
    }
    unk04 = apArg->f03();
}
