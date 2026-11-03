// fallout_shared/niformarray_decls.h: declares NiFormArray
#ifndef FNV_NIFORMARRAY_DECLS_H
#define FNV_NIFORMARRAY_DECLS_H


#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "layout_support.h"

template <class T> class NiTMallocInterface;
template <class T, class Allocator> class NiTLargeArray;
template <class T> class NiTLargePrimitiveArray;

// Complete the form-pointer specialization without changing shared declarations.
template <> class NiTLargeArray<TESForm*, NiTMallocInterface<TESForm*> >
{
  public:
    void** m_ppVirtualMethodTable;
    TESForm** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;

    void SetAt(unsigned int index, TESForm*& form);
    void SetSize(unsigned int size);
};

template <> class NiTLargePrimitiveArray<TESForm*> : public NiTLargeArray<TESForm*, NiTMallocInterface<TESForm*> >
{
};

class NiFormArray : public NiTLargePrimitiveArray<TESForm*>
{
  public:
    void Compact();
    TESForm*& FUN_00877a30(unsigned int index);
    void SetFormAtIndex(unsigned int index, TESForm* form);
    unsigned int GetIndexOfForm(TESForm* form);
};


// The canonical _memmove binding names a different runtime entry point.
void* __cdecl FUN_00ec7230(void* destination, const void* source, unsigned int size);

#endif
