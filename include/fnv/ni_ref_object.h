#pragma once

#ifdef _MSC_VER
#include <windows.h>
#else
#include <atomic>
#endif
#include "fnv/ni_mem_object.h"

#ifndef FNV_NI_ATOMIC_DEFINED
#define FNV_NI_ATOMIC_DEFINED
inline unsigned int NiAtomicIncrement(unsigned int& value)
{
#ifdef _MSC_VER
    return InterlockedIncrement(reinterpret_cast<volatile long*>(&value));
#else
    return ++std::atomic_ref<unsigned int>(value);
#endif
}
inline unsigned int NiAtomicSubtract(unsigned int& value)
{
#ifdef _MSC_VER
    return InterlockedDecrement(reinterpret_cast<volatile long*>(&value));
#else
    return --std::atomic_ref<unsigned int>(value);
#endif
}
#endif
class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;
    NiRefObject()
    {
        m_uiRefCount = 0;
        NiAtomicIncrement(ms_lObjectCount);
    }
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        NiAtomicIncrement(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (NiAtomicSubtract(m_uiRefCount) == 0)
            DeleteThis();
    }
    static unsigned int ms_lObjectCount;
};
