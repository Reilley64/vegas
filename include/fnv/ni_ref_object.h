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
inline bool NiAtomicTryIncrement(unsigned int& value)
{
#ifdef _MSC_VER
    auto* target = reinterpret_cast<volatile long*>(&value);
    long observed = InterlockedCompareExchange(target, 0, 0);
    while (static_cast<unsigned long>(observed) != 0xffffffffUL) {
        const long desired = static_cast<long>(static_cast<unsigned long>(observed) + 1UL);
        const long replaced = InterlockedCompareExchange(target, desired, observed);
        if (replaced == observed)
            return true;
        observed = replaced;
    }
    return false;
#else
    std::atomic_ref<unsigned int> target(value);
    auto observed = target.load(std::memory_order_relaxed);
    while (observed != 0xffffffffU) {
        if (target.compare_exchange_weak(observed, observed + 1,
                                         std::memory_order_relaxed,
                                         std::memory_order_relaxed))
            return true;
    }
    return false;
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
    bool TryIncRefCount()
    {
        return NiAtomicTryIncrement(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (NiAtomicSubtract(m_uiRefCount) == 0)
            DeleteThis();
    }
    static unsigned int ms_lObjectCount;
};
