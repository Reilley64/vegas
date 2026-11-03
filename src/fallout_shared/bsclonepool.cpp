
// src/fallout_shared/bsclonepool.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bsclonepool.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DecalListManager.h"
#include "fnv/decl/FUN_004b08e0_Class.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ListX.h"
#include "fnv/decl/ObsList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00631540__TargetClass.h"
#include "fnv/symbols_00559000.h"
struct S_004b0aa0_Found;
struct S_004b0aa0_Cur
{
    bool FUN_008256d0();
};
struct S_004b0aa0_Sub
{
};
struct S_004b0aa0_Found
{
    int key;
    S_004b0aa0_Sub sub;
};
struct S_004b0aa0_Self : S_004b0aa0_Cur
{
    void ProcessKeyedEntry(int key, unsigned count);
};
// @fnv 0x004b0aa0
void S_004b0aa0_Self::ProcessKeyedEntry(int key, unsigned count)
{
    if (!key)
        return;
    {
        S_004b0aa0_Found* found = 0;
        S_004b0aa0_Cur* cur = this;
        while (cur && !found && !cur->FUN_008256d0())
        {
            S_004b0aa0_Found* pEntry = *((::S_004b0aa0_Found **)((void *)(cur)));
            if (pEntry && pEntry->key == key)
                found = pEntry;
            cur = ((::S_004b0aa0_Cur *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
        }
        if (found)
        {
            unsigned uiStep;
            for (uiStep = 0; uiStep < count && !reinterpret_cast<::ObsList *>(&(found->sub))->FUN_004a4460(); uiStep++)
                reinterpret_cast<::DecalListManager *>(&(found->sub))->PopHead();
            if (reinterpret_cast<::ObsList *>(&(found->sub))->FUN_004a4460())
            {
                reinterpret_cast<::ItemChangeListNode *>(this)->FUN_00905330((*(::InventoryStackRecord *const *)(&found)));
                S_004b0aa0_Found* pFoundCopy = found;
                S_004b0aa0_Found* p3 = pFoundCopy;
                (void)(p3 ? reinterpret_cast<::FUN_004b08e0_Class *>((p3))->FUN_004b08e0(1) : 0);
            }
        }
    }
}

struct SpawnedObject
{
    bool FUN_008256d0();
};

class FUN_004b0ba0_cls
{
  public:
    unsigned int FUN_004b0ba0(std::uintptr_t arg);
};

// @fnv 0x004b0ba0
unsigned int FUN_004b0ba0_cls::FUN_004b0ba0(std::uintptr_t arg)
{
    unsigned int result2;
    unsigned int found8 = 0;
    std::uintptr_t cur = (std::uintptr_t)this;
    while (cur != 0 && found8 == 0 && !((SpawnedObject*)cur)->FUN_008256d0())
    {
        std::uintptr_t tmp = *((unsigned int *)((void *)(((SpawnedObject*)cur))));
        if (tmp != 0 && *(unsigned int*)tmp == arg)
            found8 = tmp;
        cur = ((std::uintptr_t)(reinterpret_cast<::Callees *>((((SpawnedObject*)cur)))->FUN_00726070()));
    }

    result2 = 0;
    if (found8 != 0)
    {
        std::uintptr_t p3 = found8 + 4;
        while (result2 == 0 && p3 != 0 && !reinterpret_cast<::ObsList *>((((SpawnedObject*)p3)))->FUN_004a4460())
        {
            std::uintptr_t r = ((unsigned int)(::FUN_00559450((int *)(((SpawnedObject*)((unsigned int *)((void *)(((SpawnedObject*)p3)))))))));
            if (r != 0 && ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((SpawnedObject*)r)))->FUN_00726070())) == 1)
                result2 = r;
            p3 = ((std::uintptr_t)(reinterpret_cast<::Callees *>((((SpawnedObject*)p3)))->FUN_00726070()));
        }
    }
    return result2;
}

struct B0C80List
{
    B0C80List();
    ~B0C80List();


    int unk00;
    int unk04;
    int unk08;
};

struct FUN_004b0c80
{
    FUN_004b0c80();

    int m_iArrayLength;
    B0C80List m_kList;
};

// @fnv 0x004b0c80
FUN_004b0c80::FUN_004b0c80()
{
    m_iArrayLength = 0;
    reinterpret_cast<::ListX *>(&(m_kList))->FUN_004ee920();
}

extern const char DAT_0101fca0[];
struct AutoMemHelper
{
    AutoMemHelper(int aiMemoryContext, bool bFlag, const char* pcFile, int iLine);
    ~AutoMemHelper();
    int m_iPrev;
};

struct FUN_004ad270
{
    ~FUN_004ad270();
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
};

struct FUN_004ad050 : public FUN_004ad270
{
    FUN_004ad050(float fValue);
};

struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int iObject);
    ~GlobalObject_00633c90();
    int m_pObject;
};

struct List4b0910_Ptrs
{
    int m_pInventoryEntryData;
    List4b0910_Ptrs* m_pNext;
};

struct Key4b0910
{
};

struct Entry4b0910
{
    Key4b0910* m_pkKey;
    List4b0910_Ptrs m_kList;
};

struct List4b0910
{
    bool FUN_008256d0();
    void FUN_005ae3d0(Entry4b0910** ppkEntry);
    Entry4b0910* m_pkItem;
    List4b0910* m_pkNext;
};

namespace n4b0910 {
struct FUN_004b0c80
{
    FUN_004b0c80();
    Key4b0910* m_pkKey;
    List4b0910_Ptrs m_kList;
};
}

struct FUN_004b0910_cls : public List4b0910
{
    void AddKeyedItems(Key4b0910* pkKey, unsigned int ItemUpdateArray);
};

// @fnv 0x004b0910
void FUN_004b0910_cls::AddKeyedItems(Key4b0910* pkKey, unsigned int ItemUpdateArray)
{
    if (!pkKey)
        return;

    AutoMemHelper kMemVal(0x31, true, DAT_0101fca0, 0x38);
    Entry4b0910* pkFound4 = 0;
    List4b0910* pkIter = this;
    while (pkIter && !pkFound4 && !pkIter->FUN_008256d0())
    {
        Entry4b0910* pkEntry = *((::Entry4b0910 **)((void *)(pkIter)));
        if (pkEntry && pkEntry->m_pkKey == pkKey)
            pkFound4 = pkEntry;
        pkIter = ((::List4b0910 *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070()));
    }

    if (!pkFound4)
    {
        pkFound4 = (Entry4b0910*)new n4b0910::FUN_004b0c80;
        pkFound4->m_pkKey = pkKey;
        FUN_005ae3d0(&pkFound4);
    }

    for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; uiIndex++)
    {
        FUN_004ad050 kArgTmp(1.0f);
        std::intptr_t iObject2 = ((std::intptr_t)(reinterpret_cast<::A5D2C0Object *>((pkKey))->FUN_00a5d2c0((*(::A5D2C0CloningProcess *)(&kArgTmp)))));
        reinterpret_cast<::fnv_00631540::TargetClass *>(&(pkFound4->m_kList))->FUN_00631540((const ::NiPointer< ::NiNode> &)((const ::GlobalObject_00633c90 &)(iObject2)));
    }
}

#include "generated/data/fallout_shared/bsclonepool.inc"
