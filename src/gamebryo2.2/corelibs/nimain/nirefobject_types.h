#ifndef FNV_ASTRA_NIREF_ARRAY_TYPES_H
#define FNV_ASTRA_NIREF_ARRAY_TYPES_H
#include <stddef.h>
// The covered PC address belongs to this array specialization, not DecRefCount.
class NiAVObject;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    bool operator==(const NiPointer<T>&) const;
    bool operator!=(const NiPointer<T>&) const;
    NiPointer<T>& operator=(const NiPointer<T>&);
};
template <class T> class NiTNewInterface;
template <class T, class Allocator> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetAt(unsigned int, const T&);
};
typedef NiPointer<NiAVObject> AVObjectPointer;
typedef NiTArray<AVObjectPointer, NiTNewInterface<AVObjectPointer> > AVObjectArray;
#endif
