#include <cstdint>
// bscore/bsmap_decls.h: declares BGSDistantTreeBlock
#ifndef BSMAP_DECLS_H
#define BSMAP_DECLS_H


template <class K, class V> class NiTPointerMap
{
  public:
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;

    virtual ~NiTPointerMap();
    virtual unsigned int Hash(std::uintptr_t key);
    virtual bool Equal(std::uintptr_t key1, std::uintptr_t key2);
    virtual void FillEntry(void* item, std::uintptr_t key, void* data);
    virtual void UnlinkEntry(void* item);
    virtual void* AllocateEntry();

    void RemoveAll();
};

template <class K, class V> struct BSMapEntry
{
    BSMapEntry<K, V>* m_pkNext;
    K m_key;
    V m_data;
};

template <class K, class V> class BSMapBase : public NiTPointerMap<unsigned int, unsigned int>
{
  public:
    bool GetAt(K key, V& data);
    void SetAt(K key, V data);
    virtual ~BSMapBase();
};

class ScrapHeapBuffer;
class PointerMapValue;
class DistantTreeTextureInfo;
class BGSDistantTreeBlock
{
  public:
    class InstanceData;
};

#endif
