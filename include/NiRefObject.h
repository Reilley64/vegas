// Source layout: NiRefObject. PC corrections are in generate_headers.py.
#ifndef FNV_NIREFOBJECT_H
#define FNV_NIREFOBJECT_H
#include "layout_support.h"
#include "NiMemObject.h"
#ifndef FNV_NI_ATOMIC_DEFINED
#define FNV_NI_ATOMIC_DEFINED
inline unsigned int NiAtomicIncrement(unsigned int& value)
{
    return InterlockedIncrement(reinterpret_cast<volatile long*>(&value));
}
inline unsigned int NiAtomicSubtract(unsigned int& value)
{
    return InterlockedDecrement(reinterpret_cast<volatile long*>(&value));
}
#endif
class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;  // +0x4
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
#endif
