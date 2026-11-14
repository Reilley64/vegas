// fallout_shared/bgsloadedreferencecollection.h: declares TESObjectREFR, TimeGlobal, LoadedReferenceMap
#ifndef FNV_BGSLOADEDREFERENCECOLLECTION_H
#define FNV_BGSLOADEDREFERENCECOLLECTION_H


#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_011f6000.h"
#include "layout_support.h"
#include "TESForm.h"

template <class K, class V> class NiTMapItem
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    K m_key;
    V m_val;
};
template <class K, class V> class NiTPointerMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    NiTMapItem<K, V>** m_ppkHashTable;
    struct MapEntryCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;
    NiTPointerMap(unsigned int hashSize);
    bool GetAt(K key, V& result) const;
    void SetAt(K key, V value);
};

struct ExtraRadioData;
class TESObjectREFR : public TESForm
{
public:
    ::ExtraRadioData *GetExtraRadioData();
};

class TimeGlobal
{
  public:
};

class LoadedReferenceMap : public NiTPointerMap<unsigned int, TESObjectREFR*>
{
  public:
    unsigned int iCount;              // +0x10
    unsigned int m_uiLastUpdateTime;  // +0x14

    bool AddReference(TESObjectREFR* pRef);
};


#endif
