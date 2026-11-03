// fallout_shared/region system/tesregiondataimposter.cpp: Callees, ParamCls, TESRegionDataImposter (11 functions)

#include <new>
#include "fnv/decl/ActionIterator.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/RegionSource.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004f81e0__FUN_004f81e0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "tesregiondataimposter_decls.h"

// @fnv 0x004f2190
bool TESRegionDataImposter::ReadRegionData(TESFile* file)
{
    if (!file)
        return false;
    switch (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
    case 0x44494452: {
        unsigned int uiChunkSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
        struct ImposterArrayCounts
        {
            unsigned int formIDSize;
            unsigned int count;
        } loadCounts;
        loadCounts.formIDSize = sizeof(unsigned int);
        loadCounts.count = uiChunkSize / loadCounts.formIDSize;
        unsigned int* formIDs = new unsigned int[loadCounts.count];
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(formIDs), uiChunkSize);
        for (unsigned int i = 0; i < loadCounts.count; i++)
        {
            unsigned int formID = formIDs[i];
            if (file->IsEndianConversionRequired())
                ::FUN_00401080((int *)(unsigned int *)(&formID));
            AddImposter(reinterpret_cast<TESObjectREFR*>(formID));
        }
        delete[] formIDs;
        break;
    }
    default:
        return false;
    }
    return true;
}

struct List_009e03e0
{
};

struct FUN_004f2370_shell
{
    bool ClearList();
};

// @fnv 0x004f2370
bool FUN_004f2370_shell::ClearList()
{
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)((TESTopicInfoData*)this)->GetLinkToList())))->RemoveAll();
    return true;
}

struct T004f1f40
{
    void* DestroyIfFlagged(unsigned int);
};
struct TESRegionData
{
    virtual void f0() const;
    virtual void f1() const;
    virtual void f2() const;
    virtual void f3() const;
    virtual void f4() const;
};
struct FUN_004f2450_holder
{
    void CallRegionDataVirtual(const TESRegionData* apRegionData, unsigned int aiTotalBlending);
};
// @fnv 0x004f2450
void FUN_004f2450_holder::CallRegionDataVirtual(const TESRegionData* apRegionData, unsigned int aiTotalBlending)
{
    TESRegionDataImposter* pdataIn = (TESRegionDataImposter*)apRegionData;
    if (apRegionData != 0)
        apRegionData->f4();
}

struct FUN_004f1f70_shell
{
    char m_data[16];
    FUN_004f1f70_shell(const FUN_004f1f70_shell*);
};
struct FUN_004f23d0_shell : FUN_004f1f70_shell
{
    FUN_004f1f70_shell* FUN_004f23d0();
};
// Allocates a new shell object by copy-constructing it from this object and returns the new pointer.
// @fnv 0x004f23d0
FUN_004f1f70_shell* FUN_004f23d0_shell::FUN_004f23d0()
{
    FUN_004f1f70_shell* pdata = new FUN_004f1f70_shell((const FUN_004f1f70_shell*)this);
    return pdata;
}

class FUN_004f2040_sub
{
  public:
    ~FUN_004f2040_sub();
};

class FUN_004f2040_base
{
  public:
    virtual ~FUN_004f2040_base();
    unsigned int unk04;
};

class FUN_004f2040_cls : public FUN_004f2040_base
{
  public:
    FUN_004f2040_sub m_08;
    virtual ~FUN_004f2040_cls();
};
// Calls FUN_004f2040, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x004f1f40
void* T004f1f40::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004f2040_cls *>(this)->FUN_004f2040_cls::~FUN_004f2040_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004f2040
FUN_004f2040_cls::~FUN_004f2040_cls()
{
    reinterpret_cast<::FUN_004f2370_shell *>(this)->ClearList();
}

struct FUN_004f20b0_elem
{
};
struct FUN_004f20b0_node
{
    int GetSize();
    FUN_004f20b0_elem* item;
    FUN_004f20b0_node* next;
};
struct FUN_004f20b0_cls
{
    int unk00;
    int unk04;
    FUN_004f20b0_node m08;
    void ResetAndCollectProbes();
};
struct ContNode;
struct Item4f11
{
};
struct Node4f11
{
};
struct Head4f11
{
};

class Obj4f11
{
  public:
    char _pad[0x18];
    Head4f11* m_pHead;
    ContNode* m_pNext;
    bool FUN_004f11e0();
};

struct Callees
{
    void FUN_004f1460(void* param);
    void FUN_0096a2d0();
    void* FUN_00413f40();
    void FUN_00470470();
    void* FUN_006815c0();
    void FUN_00905820(void* item);
    void* FUN_00726070();
};
// Adds ref to the list; if that fails, appends it to the fallback list and returns true, otherwise returns false.
// @fnv 0x004f2390
bool TESRegionDataImposter::AddImposter(TESObjectREFR* ref)
{
    if (!reinterpret_cast<::RefList *>((((BSSimpleList<TESForm*>*)((TESTopicInfoData*)this)->GetLinkToList())))->FUN_005f65d0((void **)&(reinterpret_cast<TESForm*&>(ref))))
    {
        reinterpret_cast<::Callees *>((((BSSimpleList<QuantityData*>*)&m_kImposterList)))->FUN_00905820((void *)&(reinterpret_cast<QuantityData*&>(ref)));
        return true;
    }
    return false;
}
// Walks the imposter's reference list, resolving each stored form ID to a TESObjectREFR and removing entries that fail to resolve.
// @fnv 0x004f2290
void TESRegionDataImposter::InitItem(TESForm* form)
{
    struct ImposterResolution
    {
        TESObjectREFR* reference;
        unsigned int formID;
    } entry;
    entry.reference = 0;
    BSSimpleList<TESObjectREFR*>* pList = (BSSimpleList<TESObjectREFR*>*)((TESTopicInfoData*)this)->GetLinkToList();
    while (pList)
    {
        if ((pList->m_item))
        {
            entry.formID = reinterpret_cast<unsigned int>((pList->m_item));
            TESFile* file = form ? form->GetFile(-1) : 0;
            ::ResolveFormID((unsigned int *)&(entry.formID), file);
            entry.reference = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(entry.formID));
            pList->SetItem(entry.reference);
        }
        if (!entry.reference)
        {
            pList->RemoveHead();
            if (!(pList->m_item))
                break;
        }
        else
        {
            pList = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        }
    }
}
// @fnv 0x004f20b0
void FUN_004f20b0_cls::ResetAndCollectProbes()
{
    reinterpret_cast<::RegionSource *>(this)->WriteSaveData();
    FUN_004f20b0_elem* pElem = 0;
    int count = m08.GetSize();
    if (count)
    {
        FUN_004f20b0_node* pNode = &m08;
        unsigned int* pProbes = new unsigned int[count];
        for (unsigned int iIndex = 0; pNode && iIndex < (unsigned int)count; iIndex++)
        {
            pElem = *((::FUN_004f20b0_elem **)((void *)(pNode)));
            unsigned int v2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pElem))->FUN_0084e3a0()));
            pProbes[iIndex] = v2;
            pNode = ((::FUN_004f20b0_node *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
        ::FUN_00485710((void *)(0x44494452), pProbes, (void *)(count));
        delete pProbes;
    }
}
// Returns false if m_pNext or m_pHead is null, m_pHead->FUN_004f3610() fails, or any node's item fails FUN_004f81e0(1); otherwise true.
// @fnv 0x004f11e0
bool Obj4f11::FUN_004f11e0()
{
    ContNode* pNode = m_pNext;
    if (!m_pNext || !m_pHead)
        return false;
    if (!reinterpret_cast<::ActionIterator *>((m_pHead))->FUN_004f3610())
        return false;
    while (pNode && *((::Item4f11 **)((void *)(((Node4f11*)pNode)))))
    {
        if (!reinterpret_cast<::fnv_004f81e0::FUN_004f81e0_shell *>(((*((::Item4f11 **)((void *)(((Node4f11*)pNode)))))))->FUN_004f81e0(1))
            return false;
        pNode = ((::ContNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return true;
}

void Callees::FUN_004f1460(void* /*param*/)
{}
void Callees::FUN_0096a2d0()
{}
void* Callees::FUN_00413f40()
{
    return 0;
}
void Callees::FUN_00470470()
{}
void* Callees::FUN_006815c0()
{
    return 0;
}
void Callees::FUN_00905820(void* /*item*/)
{}
void* Callees::FUN_00726070()
{
    return 0;
}

struct BaseCls
{
    int m_unk04;
    BaseCls(void* param)
    {
        ((Callees*)this)->FUN_004f1460(param);
    }
    virtual ~BaseCls();
};

struct MemberCls
{
    void* m_item;
    MemberCls* m_pkNext;
    MemberCls()
    {
        ((Callees*)this)->FUN_0096a2d0();
    }
    ~MemberCls();
};

struct ParamCls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
};

void ParamCls::v0()
{}
void ParamCls::v1()
{}
void ParamCls::v2()
{}
void ParamCls::v3()
{}
int ParamCls::v4()
{
    return 0;
}

struct FUN_004f1f70_cls : BaseCls
{
    MemberCls m_kMemberDescriptor;
    FUN_004f1f70_cls(void* param);
    ~FUN_004f1f70_cls();
};

// Calls FUN_00470470 on the result of this->FUN_00413f40(); if param's v4() is 8, traverses its list and passes each node's item to m_kMemberDescriptor.
// @fnv 0x004f1f70
FUN_004f1f70_cls::FUN_004f1f70_cls(void* param) : BaseCls(param)
{
    reinterpret_cast<::FileMatchList *>((((Callees*)((void *)(reinterpret_cast<::TESTopicInfoData *>((((Callees*)this)))->GetLinkToList())))))->RemoveAll();

    void* refr = param;
    if (((ParamCls*)refr)->v4() == 8)
    {
        void* node = ((void *)(reinterpret_cast<::TESTopicInfoData *>((((Callees*)refr)))->GetLinkToList()));
        while (node != 0)
        {
            ((Callees*)&m_kMemberDescriptor)->FUN_00905820(((void *)((void *)(((Callees*)node)))));
            node = ((Callees*)node)->FUN_00726070();
        }
    }
}
