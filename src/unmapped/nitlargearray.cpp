
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include "fnv/symbols_0109b000.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_00a63000.h"
#include "fnv/symbols_011f6000.h"

typedef char* GlobalStringHandle;

struct NiGlobalStringTable
{
    static unsigned int* GetRefCount(GlobalStringHandle handle)
    {
        return (unsigned int*)(handle - 8);
    }
    static void IncRefCount(GlobalStringHandle& handle)
    {
        if (handle == ::DAT_0109b220)
            return;
        InterlockedIncrement((volatile long*)GetRefCount(handle));
    }
    static void DecRefCount(GlobalStringHandle& handle)
    {
        if (handle == ::DAT_0109b220)
            return;
        InterlockedDecrement((volatile long*)GetRefCount(handle));
    }
};

GlobalStringHandle AddString(const char* pcString);

class NiFixedString
{
  public:
    NiFixedString(const char* pcString = 0)
    {
        if (pcString == 0)
            m_kHandle = ::DAT_0109b220;
        else
            m_kHandle = AddString(pcString);
    }
    ~NiFixedString()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    NiFixedString& operator=(const NiFixedString& kString)
    {
        if (m_kHandle != kString.m_kHandle)
        {
            GlobalStringHandle kHandle = kString.m_kHandle;
            NiGlobalStringTable::IncRefCount(kHandle);
            NiGlobalStringTable::DecRefCount(m_kHandle);
            m_kHandle = kHandle;
        }
        return *this;
    }
    GlobalStringHandle m_kHandle;
};

struct NiFixedStringArray
{
    virtual void v00();
    NiFixedString* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Clear();
};

// Assigns an empty NiFixedString to every element, then resets m_uiSize and m_uiESize to zero.
// @fnv 0x00a637d0
void NiFixedStringArray::Clear()
{
    for (unsigned int uiIndex = 0; uiIndex < m_uiSize; uiIndex++)
        m_pBase[uiIndex] = NiFixedString(0);
    m_uiSize = 0;
    m_uiESize = 0;
}

struct MemoryManager
{
};

bool operator!=(const NiFixedString& a, const NiFixedString& b)
{
    return a.m_kHandle != b.m_kHandle;
}

struct MyNiFixedStringArray : public NiFixedStringArray
{
    void FUN_00a65140(unsigned int uiMaxSize);
};

// @fnv 0x00a65140
void MyNiFixedStringArray::FUN_00a65140(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_uiMaxSize)
    {
        return;
    }

    unsigned int i;
    if (uiMaxSize < m_uiSize)
    {
        for (i = uiMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != NiFixedString(0))
            {
                m_pBase[i] = NiFixedString(0);
                m_uiESize--;
            }
        }

        m_uiSize = uiMaxSize;
    }

    NiFixedString* pSaveBase = m_pBase;
    m_uiMaxSize = uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = ((::NiFixedString *)(::FUN_00a63ae0(m_uiMaxSize)));

        for (i = 0; i < m_uiSize; i++)
        {
            m_pBase[i] = pSaveBase[i];
        }

        for (i = m_uiSize; i < m_uiMaxSize; i++)
        {
            m_pBase[i] = NiFixedString(0);
        }
    }
    else
    {
        m_pBase = 0;
    }

    delete[] pSaveBase;
}
