
// src/havok/common/serialize/util/hkrootlevelcontainer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkrootlevelcontainer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/ReferencedObjectHolder.h"
#include "fnv/symbols_00cb0000.h"
#include "havok/hkRootLevelContainer.h"

struct FUN_00d46d40_s
{
};


struct hkClassObj : FUN_00d46d40_s
{
};

struct FUN_00d477a0_s
{
    void* m_object;

};

struct EntryD480
{
    int unk00;
    unsigned int m_pcText;
    FUN_00d477a0_s m_pReferencedResource;

    const void* GetUnderlyingObject() const
    {
        return m_pReferencedResource.m_object;
    }
    const char* getName()
    {
        return ((::hkClassObj *)(reinterpret_cast<::ReferencedObjectHolder *>(&(m_pReferencedResource))->FUN_00d477a0())) ? reinterpret_cast<::FnvClassNameNode *>((((::hkClassObj *)(reinterpret_cast<::ReferencedObjectHolder *>(&(m_pReferencedResource))->FUN_00d477a0()))))->FUN_00d46d40()
                                                    : (const char*)(m_pcText & ~1u);
    }
};

class VariantListD480
{
  public:
    EntryD480* m_data;
    int m_iElementCount;

    void* FindByName(const char* pcName, const void* pkAfter);
};

// Finds an entry in m_data whose name matches pcName, starting the search after the entry whose underlying object is pkAfter, and returns its object or 0.
// @fnv 0x00d48080
void* VariantListD480::FindByName(const char* pcName, const void* pkAfter)
{
    int iStart = 0;
lNext:
    if (pkAfter && iStart < m_iElementCount)
    {
        if (m_data[iStart++].GetUnderlyingObject() != pkAfter)
            goto lNext;
    }
    for (int i = iStart; i < m_iElementCount; i++)
    {
        if (m_data[i].getName() && ::fnv_00cb0fa0::FUN_00cb0fa0((const char *)((int)pcName), (const char *)((int)m_data[i].getName())) == 0)
            return m_data[i].m_pReferencedResource.m_object;
    }
    return 0;
}

struct Ent_d48150
{
    unsigned int unk00;
    int unk04;
    int unk08;
};


struct Cls_d48150
{
    Ent_d48150* m_data;
    int m_iElementCount;
    int idx(int key)
    {
        int i = 0;
        Ent_d48150* e;
        while (key != 0 && i < m_iElementCount && (e = &m_data[i], i++, e->unk08 != key))
        {
        }
        return i;
    }
    int FUN_00d48150(void* ctx, int key);
};

// @fnv 0x00d48150
int Cls_d48150::FUN_00d48150(void* apContext, int key)
{
    int iIndex = idx(key);
    for (; iIndex < m_iElementCount; iIndex++)
    {
        int v = (int)m_data[iIndex].unk00;
        if ((v & -2) == 0 || ::fnv_00cb0fa0::FUN_00cb0fa0((const char *)(apContext), (const char *)(v & -2)) != 0)
            continue;
        return m_data[iIndex].unk08;
    }
    return 0;
}
