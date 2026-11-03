// include/havok/hkpPairCollisionFilterPairMap.h - the disabled-pair counts of hkpPairCollisionFilter.
// The release kept these in hkPointerMap<unsigned long long, unsigned long long> with the two entity pointers packed into one key.
// Two full pointers do not fit one 64-bit key on x64, so this map keys on the pointer pair. It keeps the
// release's open addressing, hash (taken from the larger pointer's low 32 bits), growth and removal, so lookups,
// counts and slot order match the release.
#ifndef FNV_HAVOK_HKPPAIRCOLLISIONFILTERPAIRMAP_H
#define FNV_HAVOK_HKPPAIRCOLLISIONFILTERPAIRMAP_H

#include <cstdint>

#include "havok/hkMemoryRouter.h"

struct hkpPairFilterKey
{
    const void* m_pLow;
    const void* m_pHigh;

    hkpPairFilterKey() : m_pLow(nullptr), m_pHigh(nullptr) {}

    // Orders the two pointers the way the release ordered its packed key.
    hkpPairFilterKey(const void* a, const void* b)
        : m_pLow((uintptr_t)a < (uintptr_t)b ? a : b), m_pHigh((uintptr_t)a < (uintptr_t)b ? b : a)
    {
    }

    bool operator==(const hkpPairFilterKey& other) const
    {
        return m_pLow == other.m_pLow && m_pHigh == other.m_pHigh;
    }
};

struct hkpPairFilterMap
{
    struct Pair
    {
        hkpPairFilterKey key;
        unsigned long long val;
        bool used;
    };

    Pair* m_elem = nullptr;
    int m_numElems = 0; // high bit: the storage is not owned
    int m_hashMod = -1;

    static unsigned hash(const hkpPairFilterKey& key, unsigned mod)
    {
        return (((unsigned)(uintptr_t)key.m_pHigh >> 4) * 0x9e3779b1u) & mod;
    }

    // hkMap::findKey: the slot index, or m_hashMod + 1 when the key is absent.
    int findKey(const hkpPairFilterKey& key) const
    {
        if (m_hashMod > 0)
        {
            for (unsigned i = hash(key, m_hashMod); m_elem[i].used; i = (i + 1) & m_hashMod)
            {
                if (m_elem[i].key == key)
                {
                    return (int)i;
                }
            }
        }
        return m_hashMod + 1;
    }

    unsigned long long getWithDefault(const hkpPairFilterKey& key, unsigned long long def) const
    {
        int i = findKey(key);
        return i <= m_hashMod ? m_elem[i].val : def;
    }

    // hkMap::insert: returns 1 when the key is new.
    int insert(hkMemoryAllocator& alloc, const hkpPairFilterKey& key, unsigned long long val)
    {
        int count = m_numElems & 0x7fffffff;
        if (count + count > m_hashMod)
        {
            resizeTable(alloc, m_hashMod + m_hashMod + 2);
        }
        unsigned i;
        int isNewKey = 1;
        for (i = hash(key, m_hashMod); m_elem[i].used; i = (i + 1) & m_hashMod)
        {
            if (m_elem[i].key == key)
            {
                isNewKey = 0;
                break;
            }
        }
        m_numElems += isNewKey;
        m_elem[i].key = key;
        m_elem[i].val = val;
        m_elem[i].used = true;
        return isNewKey;
    }

    // hkMap::remove(key): returns 0 when the key was found and removed.
    int remove(const hkpPairFilterKey& key)
    {
        int it = findKey(key);
        if (it <= m_hashMod)
        {
            removeAt((unsigned)it);
            return 0;
        }
        return 1;
    }

    // hkMap::clear: empties every slot and keeps the storage.
    void clear()
    {
        int n = m_hashMod + 1;
        for (int i = 0; i < n; i++)
        {
            m_elem[i].used = false;
        }
        m_numElems &= 0x80000000;
    }

    // hkMap::reserve.
    void reserve(hkMemoryAllocator& alloc, int numElements)
    {
        int doubled = numElements + numElements;
        int size = 8;
        while (size < doubled)
        {
            size += size;
        }
        resizeTable(alloc, size);
    }

    // hkMap::clearAndDeallocate.
    void clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        clear();
        if (!(m_numElems & 0x80000000))
        {
            alloc.blockFree(m_elem, (m_hashMod + 1) * (int)sizeof(Pair));
        }
        m_elem = nullptr;
        m_numElems = 0;
        m_hashMod = -1;
    }

  private:
    void removeAt(unsigned i)
    {
        --m_numElems;
        m_elem[i].used = false;

        unsigned lo = (i + m_hashMod) & m_hashMod;
        while (m_elem[lo].used)
        {
            lo = (lo + m_hashMod) & m_hashMod;
        }
        lo = (lo + 1) & m_hashMod;

        unsigned empty = i;
        for (i = (i + 1) & m_hashMod; m_elem[i].used; i = (i + 1) & m_hashMod)
        {
            unsigned h = hash(m_elem[i].key, m_hashMod);
            if ((i >= lo) && (h > empty))
            {
                continue;
            }
            else if ((i < empty) && (h > empty || h <= i))
            {
                continue;
            }
            else if (h > empty && h < lo)
            {
                continue;
            }
            m_elem[empty] = m_elem[i];
            m_elem[i].used = false;
            empty = i;
        }
    }

    void resizeTable(hkMemoryAllocator& alloc, int newCapacity)
    {
        if (newCapacity <= 8)
        {
            newCapacity = 8;
        }
        int oldCapacity = m_hashMod + 1;
        int dontDeallocate = m_numElems & 0x80000000;
        Pair* oldElem = m_elem;
        m_elem = static_cast<Pair*>(alloc.blockAlloc(newCapacity * (int)sizeof(Pair)));
        for (int i = 0; i < newCapacity; i++)
        {
            m_elem[i].used = false;
        }
        m_numElems = 0;
        m_hashMod = newCapacity - 1;
        for (int i = 0; i < oldCapacity; i++)
        {
            if (oldElem[i].used)
            {
                insert(alloc, oldElem[i].key, oldElem[i].val);
            }
        }
        if (dontDeallocate == 0)
        {
            alloc.blockFree(oldElem, oldCapacity * (int)sizeof(Pair));
        }
    }
};

#endif
