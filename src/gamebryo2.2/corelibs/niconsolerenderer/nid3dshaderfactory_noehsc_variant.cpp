
// to their real unit once identified.

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa0390.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_010f0000.h"
#include "fnv/symbols_011f6000.h"
#include "nid3dshaderfactory_decls.h"
const char kFailedShaderFactoryMessage[] = "Failed to create shader factory!";

class ShaderRefObject
{
  public:
    virtual ~ShaderRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct ShaderMapItem
{
    ShaderMapItem* m_pkNext;
    const char* m_key;
    NiPointer<ShaderRefObject> m_val;
};

struct ShaderMapAllocator
{
    unsigned int m_uiCount;
};

class ShaderStringPointerMap
{
  public:
    virtual ~ShaderStringPointerMap();
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(ShaderMapItem* pkItem, const char* key, NiPointer<ShaderRefObject> val);

    unsigned int m_uiHashSize;
    ShaderMapItem** m_ppkHashTable;
    ShaderMapAllocator m_kItemCount;
    bool m_bCopy;

    void FUN_00e927f0(const char* key, NiPointer<ShaderRefObject> val) throw();
};

// @fnv 0x00e927f0
void ShaderStringPointerMap::FUN_00e927f0(const char* key, NiPointer<ShaderRefObject> val)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    ShaderMapItem* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            if (!m_bCopy)
                pkItem->m_key = key;
            pkItem->m_val = val;
            return;
        }
        pkItem = pkItem->m_pkNext;
    }

    pkItem = (ShaderMapItem*)((void *)(reinterpret_cast<::FUN_0043a010_shell *>(&(m_kItemCount))->FUN_0043a010()));
    SetValue(pkItem, key, val);
    pkItem->m_pkNext = m_ppkHashTable[uiIndex];
    m_ppkHashTable[uiIndex] = pkItem;
    m_kItemCount.m_uiCount++;
}
