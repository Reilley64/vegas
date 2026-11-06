
// src/havok/common/serialize/packfile/hkpackfiledata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/hkpackfiledata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cb1930_t.h"
#include "fnv/decl/FUN_00cb1a60_t.h"
#include "fnv/decl/FUN_00cb1fe0_t.h"
#include "fnv/decl/FUN_00d87760_class.h"
#include "fnv/decl/FUN_00d87790.h"
#include "fnv/decl/FUN_00d877d0_class.h"
#include "fnv/decl/FUN_00e06800_cls.h"
#include "fnv/decl/FUN_00e069a0_cls.h"
#include "fnv/decl/hkObjectD878.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkStringMapD874.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d06000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_01268000.h"
struct FUN_00cb1930_Class
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
    void* m_usTrailingValue;
    void* m_f;
    void* m_g;
    void* m_h;
    void* m_i;
    void* m_iUnknownValue;
};

// Native class lookup belongs to the actual owner in packfile_data_finishing.cpp.

struct hkReferencedObject
{
};

// Native retention belongs to the resource owner, not a +0x2c receiver view.

struct FUN_00e05950_class
{
    int* m_p;
    int m_auiShapeKeys;
    int m_uiItemCount;
    int FindFirstNonEmptySlot();
};

// @fnv 0x00e05950
int FUN_00e05950_class::FindFirstNonEmptySlot()
{
    int count = 0;
    if (m_uiItemCount >= 0)
    {
        int* p = m_p;
        while (count <= m_uiItemCount)
        {
            if (p[0] != -1)
                break;
            ++count;
            p = (int*)((char*)p + 8);
        }
    }
    return count;
}

struct UnkRet
{
    intptr_t a;
    int b;
    int c;
    int d;
    intptr_t e;
};
struct UnkHolder
{
    int x;
    int y;
    int z;
    int w;
    int* data;
    int count;
    int pad;
    int pad2;
    UnkRet* FUN_00c85750();
    void FUN_00e055a0(UnkRet* r, int v);
};
// Appends a two-int entry (r, v) to the array at this+0x58, growing it via ResizeAudioStream when full, and increments the count.
// @fnv 0x00e055a0
void UnkHolder::FUN_00e055a0(UnkRet* r, int v)
{
    UnkRet* slot = (UnkRet*)((char*)this + 0x58);
    UnkRet* pTemp = FUN_00c85750();
    if ((unsigned int)slot->b == ((unsigned int)slot->c & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(void *)((void*)pTemp->e), (::AudioStream *)(slot), 8);
    UnkRet* p = (UnkRet*)((char*)slot->a + slot->b * 8);
    slot->b++;
    p->a = (intptr_t)r;
    p->b = v;
}

struct FUN_00e05550_Class
{
    char pad[0x4c];
    int* m_data;
    int m_uiItemCount;
    int m_pRayCursor;
    void AppendPair(int a, int b);
};

void* __cdecl _D1A0E0GetMemoryRouter();

// Appends the pair (a, b) to the array at this+0x4c, growing it via the memory router when full, and increments the count.
// @fnv 0x00e05550
void FUN_00e05550_Class::AppendPair(int aiFirst, int aiSecond)
{
    hkMemoryRouter* router = static_cast<hkMemoryRouter*>(_D1A0E0GetMemoryRouter());
    if (m_uiItemCount == (m_pRayCursor & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)&router->heap(), (::AudioStream *)&m_data, 8);
    int iIndex = m_uiItemCount;
    int* slot = m_data + iIndex * 2;
    m_uiItemCount = iIndex + 1;
    slot[0] = aiFirst;
    slot[1] = aiSecond;
}

// Native resource statistics and its real collector protocol are owned by
// native_resource_statistics.cpp; no raw virtual-slot receiver remains here.

struct ByteSink
{
    void PutBytePair(char a, char b);
};
struct E06C20Writer
{
};
struct FUN_00e06800_Class
{
};

struct FUN_00e06d70_Class
{
    char pad[0x10];
    void* m_pWriter;
    void WriteSize(uintptr_t size);
};

// @fnv 0x00e06d70
void FUN_00e06d70_Class::WriteSize(uintptr_t size)
{
    void* p = m_pWriter;
    if (size < 0x100)
        ((ByteSink*)p)->PutBytePair(9, (char)size);
    else if (size < 0x10000)
        reinterpret_cast<::FUN_00e06800_cls *>((((FUN_00e06800_Class*)p)))->FUN_00e06800(0xa, (intptr_t)((void*)size));
    else
        reinterpret_cast<::FUN_00e069a0_cls *>((((E06C20Writer*)p)))->FUN_00e069a0(0xb, (uintptr_t)((void*)size));
}

struct FUN_00e05100_cls
{
    int unk00;
    int unk04;
    int m_iValue08;
    void FUN_00e05100(int value, intptr_t unused);
};

// @fnv 0x00e05100
void FUN_00e05100_cls::FUN_00e05100(int value, intptr_t unused)
{
    m_iValue08 = value;
}

struct FUN_00e05240_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    bool FUN_00e05240();
};

// @fnv 0x00e05240
bool FUN_00e05240_cls::FUN_00e05240()
{
    return m_20 != 0;
}

struct hkAllocatorE054;

struct hkMemoryRouterE054
{
    void* m_apvUnk00[4];
    hkAllocatorE054* m_pkHeap;
    hkAllocatorE054& heap()
    {
        return *m_pkHeap;
    }
};


template <typename T> __forceinline T min2E054(T x, T y)
{
    return x < y ? x : y;
}

template <typename T> __forceinline void copyE054(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <typename T> __forceinline void constructWithArrayE054(T* dst, int n, const T* src)
{
    for (int i = 0; i < n; i++)
        new (dst + i) T(src[i]);
}

template <typename T> struct hkArrayE054
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(hkAllocatorE054& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewSize, sizeof(T));
        }
    }
    __forceinline void _copyFromArray(hkAllocatorE054& kAlloc, const hkArrayE054<T>& a)
    {
        const int iOldSize = m_iElementCount;
        int iNewSize = a.m_iElementCount;
        int iCopiedSize = (iNewSize > iOldSize) ? iOldSize : iNewSize;
        GrowArrayCapacity(kAlloc, iNewSize);
        copyE054<T>(m_data, a.m_data, iCopiedSize);
        constructWithArrayE054<T>(m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);
        m_iElementCount = iNewSize;
    }
    __forceinline hkArrayE054& operator=(const hkArrayE054<T>& a)
    {
        _copyFromArray(((hkMemoryRouterE054*)FUN_00c85750())->heap(), a);
        return *this;
    }
};

struct PairE054
{
    int m_kPointA;
    int m_kPointB;
};

class FUN_00e05410_Owner
{
  public:
    char m_pad00[0x4c];
    hkArrayE054<PairE054> m_iSecondInteger;
    hkArrayE054<PairE054> m_pHeadNode;

    void CopyPairArrays(hkArrayE054<PairE054>& kFirstOut, hkArrayE054<PairE054>& kSecondOut) const throw();
};

// @fnv 0x00e05410
void FUN_00e05410_Owner::CopyPairArrays(hkArrayE054<PairE054>& kFirstOut, hkArrayE054<PairE054>& kSecondOut) const
    throw()
{
    kFirstOut = m_pHeadNode;
    kSecondOut = m_iSecondInteger;
}

// Native class/finish registry receivers are declared shared owners now;
// unrelated legacy virtual receiver views are not used for native resources.

struct hkPointerMapPairE055
{
    uintptr_t m_uiKey;
    uintptr_t m_uiCurrentValue;
};

struct hkPointerMapE055 : public FUN_00e05950_class
{
    int isValid(int iIt) const
    {
        return iIt <= m_uiItemCount;
    }
    int getNext(int iIt) const
    {
        int i = iIt;
        for (i += 1; i <= m_uiItemCount; ++i)
        {
            if (((hkPointerMapPairE055*)m_p)[i].m_uiKey != ~uintptr_t(0))
                break;
        }
        return i;
    }
    uintptr_t GetIteratorKey(int iIt) const
    {
        return ((hkPointerMapPairE055*)m_p)[iIt].m_uiKey;
    }
    uintptr_t getValue(int iIt) const
    {
        return ((hkPointerMapPairE055*)m_p)[iIt].m_uiCurrentValue;
    }
};

// The native hkPackfileDataE055 owner and retained second finishing entry
// are declared in NativeWorld.h and implemented in packfile_data_finishing.cpp.

void __cdecl FUN_00c856c0(void* heap, void* ptr);

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease(hkMemoryAllocator* alloc)
    {
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc->bufFree(this->m_data, (cap & 0x3fffffff) * sizeof(T));
        }
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }
};

struct Chunk
{
    void* data;
    int size;
    int unk8;
};

struct Export
{
    int a;
    int b;
};

struct Import
{
    int a;
    int b;
};

struct Map1Type
{
    void* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;

    void ClearAndRelease()
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        reinterpret_cast<::CB1A90Owner *>((this))->ProcessArgument((::CB1A90Argument *)(router->m_heap));
        ::FUN_00a29680();
    }
};

struct Map2Type
{
    void* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};

// The constructed resource destructor owns cleanup and exact-sized deallocation.
// No deleting wrapper reads allocation size from an unrelated word prefix.

struct Crux53_HkRouter
{
    void* unk00; void* unk04; void* unk08; void* unk0c;
    void* heap;
};
void __cdecl FUN_00c856c0(void* heap, void* ptr);
char* __cdecl FUN_00cb1410(const char* src);
inline void Crux53_FreeName(char* existing)
{
    Crux53_HkRouter* router = (Crux53_HkRouter*)FUN_00c85750();
    FUN_00c856c0(router->heap, existing);
}
struct Crux53_Named
{
    int unk00, unk04, unk08;
    char* name;
    void SetName(const char* newName);
};
// Frees the current name string and assigns the result of FUN_00cb1410(newName).
// @fnv 0x00e05110
void Crux53_Named::SetName(const char* newName)
{
    Crux53_FreeName(name);
    name = FUN_00cb1410(newName);
}

template <int SIZE> __forceinline void memCpyOneAlignedE051(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

template <class T> class hkArrayE051
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAlignedE051<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

struct hkEntryE051
{
    void* m_object;
    int m_key;
};

class hkListenerE051
{
  public:
    int unk00[19];
    hkArrayE051<hkEntryE051> m_entries;

    void FUN_00e05190(int key);
};

// Removes all entries from m_entries whose m_key matches key by calling removeAt on each matching index.
// @fnv 0x00e05190
void hkListenerE051::FUN_00e05190(int key)
{
    for (int i = m_entries.m_iElementCount - 1; i >= 0; i--)
    {
        if (m_entries.m_data[i].m_key == key)
            m_entries.removeAt(i);
    }
}

namespace fnv_00e051e0 {
struct PairE051
{
    int m_key;
    void* m_pIntegerData;
};

template <unsigned int SIZE> inline void memCpyOneAlignedE051(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < (int)(SIZE / 4));
}

template <class T> class hkArrayE051
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAlignedE051<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

class FUN_00e051e0_C
{
  public:
    char unk00[0x58];
    hkArrayE051<PairE051> m_entries;

    void RemoveEntry(void* pValue);
};

// Finds the entry in m_entries whose m_pIntegerData equals pValue and removes it from the array.
// @fnv 0x00e051e0
void FUN_00e051e0_C::RemoveEntry(void* pValue)
{
    for (int i = m_entries.m_iElementCount - 1; i >= 0; i--)
    {
        if (m_entries.m_data[i].m_pIntegerData == pValue)
        {
            m_entries.removeAt(i);
            return;
        }
    }
}
}  // namespace fnv_00e051e0

struct FUN_00e05370_Entry
{
    int id;
    void* key;
};
struct FUN_00e05370_Callback
{
    int unknown0;
    int unknown4;
    void(__cdecl* invoke)(int);
};
struct FUN_00e05370_List
{
    FUN_00e05370_Entry* data;
    int capacity;
    int lastIndex;
};
struct FUN_00e05370_Map
{
    int unknown0;
    int count;
    int unknown8;
    int unknownC;
    int unknown10;
    void* table;
};
struct FUN_00e05370_Class
{
    int unknown0;
    int unknown4;
    int field08;
    int unknownC;
    FUN_00e05370_List list;
    FUN_00e05370_Map map;
    void Clear();
};
// Native final cleanup is implemented by packfile_data_finishing.cpp.

// Invokes each registered callback with its entry id, then resets field08 and clears the list and map.
// @fnv 0x00e05370
void FUN_00e05370_Class::Clear()
{
    if (map.table && map.count > 0)
    {
        int limit = list.lastIndex;
        int index = 0;
        while (index <= limit && list.data[index].id == -1)
            ++index;
        if (index <= list.lastIndex)
        {
            do
            {
                void* key = list.data[index].key;
                FUN_00e05370_Callback* pCallback = ((::FUN_00e05370_Callback *)(reinterpret_cast<::hkObjectD878 *>(&(map))->GetValue((intptr_t)(key), 0)));
                if (pCallback && pCallback->invoke)
                    pCallback->invoke(list.data[index].id);
                int next = index + 1;
                while (next <= list.lastIndex && list.data[next].id == -1)
                    ++next;
                index = next;
            } while (index <= list.lastIndex);
        }
    }
    field08 = 0;
    reinterpret_cast<::FUN_00cb1a60_t *>(&(list))->ResetEntries();
    reinterpret_cast<::FUN_00d87760_class *>(&(map))->ClearEntries();
}

// S00e05700_Class construction is a real C++ factory in native_world.cpp.
