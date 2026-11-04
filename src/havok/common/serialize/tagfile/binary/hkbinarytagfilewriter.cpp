
// src/havok/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include "fnv/decl/DBAFB0Handle.h"
#include "fnv/decl/DataClassAccess.h"
#include "fnv/decl/FUN_00dba680_cls.h"
#include "fnv/decl/FUN_00dba730_cls.h"
#include "fnv/decl/FUN_00dba810_cls.h"
#include "fnv/decl/FUN_00dba9c0_cls.h"
#include "fnv/decl/FUN_00dbab90_cls.h"
#include "fnv/decl/FUN_00dbabb0_cls.h"
#include "fnv/decl/FUN_00dbac50_cls.h"
#include "fnv/decl/FUN_00dbac70_cls.h"
#include "fnv/decl/MemberArrayValue.h"
#include "fnv/decl/Outer_dbac40.h"
struct MyDesc;
#include "fnv/decl/S_00dbac90.h"
struct ScanObject;
#include "fnv/decl/This_2.h"
#include "fnv/decl/Wrapper.h"
#include "fnv/decl/fnv_00dba9a0__FUN_00dba9a0_cls.h"
#include "fnv/decl/fnv_00dbaa00__Wrapper.h"
#include "fnv/decl/fnv_00dbac00__Wrapper.h"
#include "fnv/decl/fnv_00dbac10__CpuObject.h"
#include "fnv/decl/fnv_00dbac80__Wrapper.h"
#include <new>
#include <cstring>
#include "fnv/decl/D60590Object.h"
#include "fnv/decl/DBA7F0Ref.h"
#include "fnv/decl/DataClassMemberAccess.h"
#include "fnv/decl/DataObjectHandle.h"
#include "fnv/decl/FUN_00d605d0_class.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/FUN_00d60b00_class.h"
#include "fnv/decl/FUN_00d877d0_class.h"
#include "fnv/decl/FUN_00dba650_cls.h"
#include "fnv/decl/FUN_00dba6a0_cls.h"
#include "fnv/decl/FUN_00dba780_cls.h"
#include "fnv/decl/FUN_00dba8f0_cls.h"
#include "fnv/decl/FUN_00dba980_cls.h"
#include "fnv/decl/FUN_00dba9d0_cls.h"
#include "fnv/decl/FUN_00dbab70_cls.h"
#include "fnv/decl/FUN_00dbaca0_cls.h"
#include "fnv/decl/FUN_00dbaea0_cls.h"
#include "fnv/decl/FUN_00dbaf10_cls.h"
#include "fnv/decl/S_00dba990.h"
#include "fnv/decl/S_00dbaed0_Obj.h"
#include "fnv/decl/fnv_00dba920__Target.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/decl/hkObjectD878.h"
#include "fnv/decl/hkStringMapD874.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d60000.h"
#include "fnv/symbols_00dba000.h"
#include "fnv/symbols_00dbe000.h"
#include "fnv/symbols_01011000.h"
struct BSAudio
{
    intptr_t a;
    intptr_t b;
    intptr_t c;
    intptr_t d;
    intptr_t e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;
};
struct UnkRet
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;
};
struct UnkHolder
{
    void* a;
    int b;
    int c;
    void FUN_00dbedb0(UnkRet*, int);
};
struct FUN_00dc0380
{
    BSAudio* p;
    UnkHolder unk;
    int a;
    int b;
    int c;
    FUN_00dc0380(BSAudio* v);
};
// @fnv 0x00dc0380
FUN_00dc0380::FUN_00dc0380(BSAudio* pAudio)
{
    p = pAudio;
    UnkHolder* h = &unk;
    h->a = 0;
    h->b = 0;
    h->c = -1;
    BSAudio* r = static_cast<BSAudio*>(::FUN_00c85750());
    h->FUN_00dbedb0(reinterpret_cast<UnkRet*>(*(reinterpret_cast<int**>(r) + 4)), 0);
    a = 0;
    b = 0;
    c = 0x80000000;
}

struct ObjectHandle
{
    void* object;
    __declspec(nothrow) int FUN_00dbac00();
    ~ObjectHandle()
    {
        reinterpret_cast<::FUN_00dbab70_cls *>(this)->FUN_00dbab70();
    }
};
struct StringHandle
{
    void* object;
    __declspec(nothrow) void FUN_00dba7f0();
    ~StringHandle()
    {
        reinterpret_cast<::DBA7F0Ref *>(this)->FUN_00dba7f0();
    }
};
struct Value
{
    int FUN_00dbac40();
    int CallVirtualWithArg();
    float ApplyValue();
    void* FUN_00dbac70();
    __declspec(nothrow) ObjectHandle FUN_00dbacd0();
};
// @fnv 0x00dbeab0
int IsTruthy(Value* value)
{
    if (value->FUN_00dbac40() >= 16)
        return value->FUN_00dbacd0().FUN_00dbac00();
    switch (value->FUN_00dbac40())
    {
    case 0:
        return 0;
    case 1:
    case 2:
        return value->CallVirtualWithArg() != 0;
    case 3:
        return value->ApplyValue() != 0.0f;
    case 4:
    case 6:
    case 7:
        return 1;
    case 8:
    case 9:
        return ((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(const ::StringHandle &)((*(::StringHandle *)(reinterpret_cast<::FUN_00dbaca0_cls *>((value))->CreateValueInto({})))))->FUN_00dba980())) == 0;
    case 16:
        return value->FUN_00dbacd0().FUN_00dbac00() != 0;
    case 10:
        return value->FUN_00dbac70() != 0;
    default:
        return 0;
    }
}

struct ResourceKey
{
    uintptr_t first;
    uintptr_t second;
};
struct SoundEntry
{
    void* sound;
};
struct Receiver
{
};
struct Description
{
    void FUN_009ba810(ResourceKey* key);
};
struct ResourceLookup
{
    int unk00;
    int unk04;
    int unk08;
};
struct AudioResourceState
{
    void* active;
    ResourceLookup lookup;
    SoundEntry** entries;
    void* ResolveSound(Receiver* receiver, Description* description);
};
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
};

struct AudioMgr
{
    void *unk00, *unk04, *unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator& tempHeap()
    {
        return *unk0c;
    }
};

inline AudioMgr* audio()
{
    return (AudioMgr*)static_cast<BSAudio*>(::FUN_00c85750());
}


struct hkCharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->tempHeap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), n < cap ? cap : n, 1);
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        char* p = m_data + m_iElementCount;
        int num = n - m_iElementCount;
        if (num <= 0)
        {
            m_iElementCount = n;
            return;
        }
        std::memset(p, 0, num);
        m_iElementCount = n;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

struct FUN_00dbef20 : hkCharArray
{
    FUN_00dbef20(int n);
};

// Initializes the char array to empty, reserves capacity rounded up to a multiple of 8, then sets the size to n.
// @fnv 0x00dbef20
FUN_00dbef20::FUN_00dbef20(int aiSize)
{
    m_data = 0;
    m_iElementCount = 0;
    m_iCapacityState = 0x80000000;
    SetSizeAndGrow((aiSize + 7) & ~7);
    setSizeUnchecked(aiSize);
}

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct ArrayDeallocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    ArrayDeallocator* m_pArrayDealloc;
    AudioAllocator* m_pAllocator;
};

struct Element
{
    int m_i00;
    void FUN_00dba7f0();
};

struct SubObject
{
    int m_i00;
    int m_i04;
    int m_i08;
};

struct FUN_00dc03d0_cls
{
    int unk00;
    SubObject m_kSub;
    Element** m_ppArray;
    int m_iArrayLength;
    unsigned int m_uCapacity;
    void ClearArray();
};

namespace fnv_00dc0460 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct AudioMgr
{
    void *unk00, *unk04, *unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& tempHeap()
    {
        return *unk0c;
    }
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
inline AudioMgr* audio()
{
    return (AudioMgr*)static_cast<BSAudio*>(::FUN_00c85750());
}

struct Elem24
{
    int v[4];
    uintptr_t key[2];
};

template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = audio()->tempHeap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct MemberA
{
    int pad[4];
};
struct MemberB
{
    int pad[3];
    void AllocBufferIfNotFlagged(hkMemoryAllocator* alloc);
};
struct MemberC
{
};

struct BaseObj
{
    int pad[4];
};

struct Obj : BaseObj
{
    MemberA m10;
    MemberA m20;
    int unk30;
    MemberB m34;
    hkArray<char> m40;
    hkArray<Elem24> m4c;
    MemberC m58;
    void FUN_00dc0460();
};

// @fnv 0x00dc0460
void Obj::FUN_00dc0460()
{
    reinterpret_cast<::FUN_00dc03d0_cls *>(&(m58))->ClearArray();
    m4c.ClearAndRelease();
    m40.ClearAndRelease();
    m34.AllocBufferIfNotFlagged(&audio()->heap());
    reinterpret_cast<::FUN_00d877d0_class *>(&(m20))->FreeBuffer();
    reinterpret_cast<::FUN_00d877d0_class *>(&(m10))->FreeBuffer();
    reinterpret_cast<::D60590Object *>(this)->FUN_00d60590();
}
}  // namespace fnv_00dc0460

struct AudioObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct Dc0380Layout
{
    BSAudio* p;
    UnkHolder unk;
    int a;
    int b;
    int c;
};
struct FUN_00dc05b0_writer
{
    AudioObject first;
    AudioObject second;
    AudioObject third;
    int unk30;
    UnkHolder unk34;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    Dc0380Layout audio;
    void FUN_00dc0500(intptr_t, int);
    void WriteVarint(unsigned int, unsigned int);
    void FUN_00dbf450(int, int);
    void FUN_00dc00b0(int);
};
struct CallbackTarget
{
    virtual void Dummy0()
    {}
    virtual void Dummy1()
    {}
    virtual void Dummy2()
    {}
    virtual void Dummy3()
    {}
    virtual void Dummy4()
    {}
    virtual void Complete()
    {}
};
// @fnv 0x00dc05b0
int WriteAudioObject(int value, CallbackTarget* target, int source)
{
    FUN_00dc05b0_writer writer;
    writer.FUN_00dc0500((intptr_t)target, source);
    reinterpret_cast<::hkOArchive_2 *>(&(writer))->WriteInt(0xcab00d1e);
    reinterpret_cast<::hkOArchive_2 *>(&(writer))->WriteInt(0xd011face);
    writer.WriteVarint(1, 0);
    writer.WriteVarint(0, 0);
    writer.FUN_00dbf450(value, 0);
    writer.FUN_00dc00b0(value);
    target->Complete();
    reinterpret_cast<::fnv_00dc0460::Obj *>(&(writer))->FUN_00dc0460();
    return 0;
}

struct Obj
{
    void WriteVarint(__int64);
};

// @fnv 0x00dbe790
void Obj::WriteVarint(__int64 value)
{
    unsigned __int64 u;

    if (value < 0)
    {
        __int64 t = -value;
        u = ((unsigned __int64)t << 1) | 1ULL;
    }
    else
    {
        u = (unsigned __int64)value << 1;
    }

    unsigned char byte = (unsigned char)(u & 0x7f);
    u >>= 7;

    if (u != 0)
    {
        do
        {
            reinterpret_cast<::FUN_00d605d0_class *>((this))->FUN_00d605d0((unsigned char)(byte | 0x80));
            byte = (unsigned char)(u & 0x7f);
            u >>= 7;
        } while (u != 0);
    }

    reinterpret_cast<::FUN_00d605d0_class *>((this))->FUN_00d605d0(byte);
}

struct FUN_00dbe8c0_cls
{
    struct HashEntry
    {
        uintptr_t key0;
        uintptr_t key1;
        unsigned int value;
    };

    HashEntry* m_pEntries;
    unsigned int m_u04;
    unsigned int m_uMask;

    unsigned int FindEntryValue(uintptr_t aKey0, uintptr_t aKey1, unsigned int aDefault);
};
// @fnv 0x00dbebe0
void* AudioResourceState::ResolveSound(Receiver* receiver, Description* description)
{
    ResourceKey key;
    if (active && !((int)(reinterpret_cast<::FUN_00dba980_cls *>((description))->FUN_00dba980())))
    {
        description->FUN_009ba810(&key);
        int index = ((int)(reinterpret_cast<::FUN_00dbe8c0_cls *>(&(lookup))->FindEntryValue(key.first, key.second, -1)));
        if (index != -1)
        {
            reinterpret_cast<::DataObjectHandle *>((receiver))->FUN_00dba760((::RefObj *)(entries[index]->sound));
            return receiver;
        }
    }
    reinterpret_cast<::FUN_00dba780_cls *>((receiver))->AssignRef((::FUN_00dba780_cls *)(description));
    return receiver;
}

// Looks up the entry matching aKey0 and aKey1 in the open-addressed hash table and returns its value, or aDefault if not found.
// @fnv 0x00dbe8c0
unsigned int FUN_00dbe8c0_cls::FindEntryValue(uintptr_t aKey0, uintptr_t aKey1, unsigned int aDefault)
{
    unsigned int mask = m_uMask;
    if ((int)mask > 0)
    {
        unsigned int idx = ((aKey0 >> 4) * 0x9e3779b1u) & mask;
        if (m_pEntries[idx].key0 != 0)
        {
            for (;;)
            {
                HashEntry* e = &m_pEntries[idx];
                if (e->key0 == aKey0 && e->key1 == aKey1)
                {
                    return m_pEntries[idx].value;
                }
                idx = (idx + 1) & mask;
                if (m_pEntries[idx].key0 == 0)
                {
                    break;
                }
            }
        }
    }
    return aDefault;
}

// A 12-byte hash table (as used by the hkPackfileWriter module): a pointer to
// an array of 12-byte entries, a flag word and the number of entries.
struct HashEntry
{
    uintptr_t unk00;
    uintptr_t unk04;
    int unk08;
};

struct HashTableBase
{
    HashEntry* m_entries;
    int m_flags;
    int m_uiItemCount;

    void ClearEntries();
};

// Clears the key field of every entry of the table (the table holds
// @fnv 0x00dbe920
void HashTableBase::ClearEntries()
{
    int n = m_uiItemCount + 1;
    for (int i = 0; i < n; i++)
        m_entries[i].unk00 = 0;
    m_flags &= 0x80000000;
}

struct AudioIface
{
    virtual void v00();
    virtual void v04();
    virtual void Alloc(void* apBuf, unsigned int auSize);
};

struct FUN_00dbe950_cls
{
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;

    void AllocBufferIfNotFlagged(AudioIface* apIface);
};
// @fnv 0x00dc03d0
void FUN_00dc03d0_cls::ClearArray()
{
    for (int i = 0; i < m_iArrayLength; i++)
    {
        Element* pElement = m_ppArray[i];
        if (pElement)
        {
            reinterpret_cast<::DBA7F0Ref *>((pElement))->FUN_00dba7f0();
            AudioHolder* pAllocHolder = (AudioHolder*)static_cast<BSAudio*>(::FUN_00c85750());
            AudioAllocator* pAllocator = pAllocHolder->m_pAllocator;
            pAllocator->Free(pElement, 4);
        }
    }

    AudioHolder* pArrayHolder = (AudioHolder*)static_cast<BSAudio*>(::FUN_00c85750());
    ArrayDeallocator* pDealloc = pArrayHolder->m_pArrayDealloc;
    unsigned int uCapacity = m_uCapacity;
    m_iArrayLength = 0;
    if ((uCapacity & 0x80000000) == 0)
        pDealloc->FreeArray(m_ppArray, (uCapacity & 0x3fffffff) * 4);

    m_ppArray = 0;
    m_uCapacity = 0x80000000;

    AudioHolder* pSubHolder = (AudioHolder*)static_cast<BSAudio*>(::FUN_00c85750());
    AudioAllocator* pSubAllocator = pSubHolder->m_pAllocator;
    reinterpret_cast<::FUN_00dbe950_cls *>(&(m_kSub))->AllocBufferIfNotFlagged((::AudioIface *)(pSubAllocator));
}

// @fnv 0x00dbe950
void FUN_00dbe950_cls::AllocBufferIfNotFlagged(AudioIface* apIface)
{
    reinterpret_cast<::HashTableBase *>(this)->ClearEntries();
    if ((m_04 & 0x80000000u) == 0)
    {
        unsigned int uCount = m_08 + 1;
        apIface->Alloc(m_00, uCount * (unsigned int)sizeof(HashEntry));
    }
}

struct AllocOwner
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* p, unsigned int size);
};

struct Entry12
{
    uintptr_t a;
    uintptr_t b;
    int c;
};

struct FUN_00dbe810_cls
{
};

struct FUN_00dbec60_cls
{
    Entry12* m_00;
    unsigned int m_04;
    int m_08;

    void FUN_00dbec60(AllocOwner* alloc, int count);
};


struct DBED30StringMap
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void insert(const char* key, int val);
};

struct DBED30Writer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DBED30StringMap m_pStringFunctions;

    void WriteString(const char* s);
};

// Writes a string to the stream: emits its length and bytes if new, otherwise emits the negated existing index; null writes -1.
// @fnv 0x00dbed30
void DBED30Writer::WriteString(const char* pcString)
{
    if (pcString)
    {
        intptr_t index = reinterpret_cast<::hkObjectD878 *>((void *)&(m_pStringFunctions))->GetValue((intptr_t)(pcString), -1);
        if (index == -1)
        {
            intptr_t len = ::fnv_00cb10d0::FUN_00cb10d0(pcString);
            reinterpret_cast<::Obj *>(this)->WriteVarint(len);
            reinterpret_cast<::FUN_00d607b0_class *>(this)->FUN_00d607b0((intptr_t)(pcString));
            reinterpret_cast<::hkStringMapD874 *>(&(m_pStringFunctions))->FUN_00d874d0(pcString, m_pStringFunctions.m_iCapacityFlags + 1);
        }
        else
        {
            reinterpret_cast<::Obj *>(this)->WriteVarint(-index);
        }
    }
    else
    {
        reinterpret_cast<::Obj *>(this)->WriteVarint(-1);
    }
}

struct S_dbefc0_Heap
{
    int unk;
};
struct S_dbefc0_Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    S_dbefc0_Heap* unk0c;
    S_dbefc0_Heap& heap()
    {
        return *unk0c;
    }
};

static __forceinline S_dbefc0_Heap& S_dbefc0_GetHeap()
{
    return ((S_dbefc0_Router*)static_cast<BSAudio*>(::FUN_00c85750()))->heap();
}

struct S_dbefc0_Bytes
{
    char* data;
    int size;
    int cap;

    __forceinline void GrowArrayCapacity(S_dbefc0_Heap& heap, int n)
    {
        int c = cap & 0x3fffffff;
        if (c < n)
        {
            int c2 = c + c;
            ::FUN_00c908c0((::SpawnedObject *)(::S_dbefc0_Heap *)(&heap), (::SpawnedArray *)(void *)(this), (n < c2) ? c2 : n, 1);
        }
    }
    __forceinline void _setSize(S_dbefc0_Heap& heap, int n)
    {
        GrowArrayCapacity(heap, n);
        char* p = data + size;
        int diff = n - size;
        if (diff <= 0)
        {
            size = n;
            return;
        }
        std::memset(p, 0, diff);
        size = n;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        _setSize(S_dbefc0_GetHeap(), n);
    }
    __forceinline void trim(int n)
    {
        GrowArrayCapacity(S_dbefc0_GetHeap(), n);
        size = n;
    }
    void FUN_00dbefc0(const unsigned char* bytes, int count);
};

// @fnv 0x00dbefc0
void S_dbefc0_Bytes::FUN_00dbefc0(const unsigned char* bytes, int count)
{
    int oldSize = size;
    SetSizeAndGrow((oldSize + 7) & ~7);
    int iOffset = 0;
    for (int i = 0; i < count; i++)
    {
        unsigned char b = bytes[i];
        data[iOffset + 0] = b & 1;
        b >>= 1;
        data[iOffset + 1] = b & 1;
        b >>= 1;
        data[iOffset + 2] = b & 1;
        b >>= 1;
        data[iOffset + 3] = b & 1;
        b >>= 1;
        data[iOffset + 4] = b & 1;
        b >>= 1;
        data[iOffset + 5] = b & 1;
        b >>= 1;
        data[iOffset + 6] = b & 1;
        b >>= 1;
        data[iOffset + 7] = b & 1;
        iOffset += 8;
    }
    trim(oldSize);
}

struct Rec_00dbf0d0
{
    unsigned char* unk00;  // data buffer
    int unk04;             // used size
    int unk08;             // capacity (low 30 bits) + flags
    void PackBitsToBytes(unsigned char* dest);
};


// @fnv 0x00dbf0d0
void Rec_00dbf0d0::PackBitsToBytes(unsigned char* dest)
{
    int oldSize = this->unk04;
    int newSize = (oldSize + 7) & 0xfffffff8;

    // make sure the buffer can hold the padded size
    {
        BSAudio* audio = static_cast<BSAudio*>(::FUN_00c85750());
        intptr_t audioD = audio->d;
        int cap = this->unk08 & 0x3fffffff;
        if (cap < newSize)
        {
            int newCap = cap + cap;
            if (newSize >= newCap)
                newCap = newSize;
            ::FUN_00c908c0((::SpawnedObject *)(audioD), (::SpawnedArray *)(::Rec_00dbf0d0 *)(this), newCap, 1);
        }
    }

    // zero the region that was just added
    {
        int delta = newSize - this->unk04;
        unsigned char* dst = this->unk00 + this->unk04;
        while (delta > 0)
        {
            int chunk = delta;
            std::memset(dst, 0, chunk);
            dst += chunk;
            delta -= chunk;
        }
    }

    this->unk04 = newSize;

    // pack the low bit of every byte into one byte
    for (int i = 0; i < this->unk04; i += 8)
    {
        unsigned char v = this->unk00[i + 7];
        const unsigned char* p = this->unk00 + i;
        v = (unsigned char)((v << 1) | p[6]);
        v = (unsigned char)((v << 1) | p[5]);
        v = (unsigned char)((v << 1) | p[4]);
        v = (unsigned char)((v << 1) | p[3]);
        v = (unsigned char)((v << 1) | p[2]);
        v = (unsigned char)((v << 1) | p[1]);
        v = (unsigned char)((v << 1) | p[0]);
        *dest++ = v;
    }

    // give the memory back
    {
        BSAudio* audio = static_cast<BSAudio*>(::FUN_00c85750());
        intptr_t audioD = audio->d;
        int cap = this->unk08 & 0x3fffffff;
        if (cap < oldSize)
        {
            int newCap = cap + cap;
            if (oldSize >= newCap)
                newCap = oldSize;
            ::FUN_00c908c0((::SpawnedObject *)(audioD), (::SpawnedArray *)(::Rec_00dbf0d0 *)(this), newCap, 1);
        }
    }
    this->unk04 = oldSize;
}

struct S_00dc0500_Flag
{
    bool b;
    S_00dc0500_Flag(bool v) : b(v)
    {}
};
struct S_00dc0500_Opt
{
    bool b;
    S_00dc0500_Opt(bool v) : b(v)
    {}
    S_00dc0500_Opt(const S_00dc0500_Opt& o) : b(o.b)
    {}
};
struct FUN_00d60830
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d60830(BSAudio* a1, S_00dc0500_Opt f);
};
struct S_00dc0500_Str
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct FUN_00d87790 : S_00dc0500_Str
{
    FUN_00d87790(S_00dc0500_Flag f);
};
struct S_00dc0500_Holder : UnkHolder
{
    S_00dc0500_Holder()
    {
        a = 0;
        b = 0;
        c = -1;
        BSAudio* p = static_cast<BSAudio*>(::FUN_00c85750());
        FUN_00dbedb0((UnkRet*)p->e, 0);
    }
};
struct S_00dc0500_Arr
{
    void* a;
    int b;
    int c;
    S_00dc0500_Arr() : a(0), b(0), c(0x80000000)
    {}
};
struct FUN_00dc0500 : FUN_00d60830
{
    FUN_00d87790 m_10;
    FUN_00d87790 m_20;
    int m_30;
    S_00dc0500_Holder m_34;
    S_00dc0500_Arr m_40;
    S_00dc0500_Arr m_4c;
    FUN_00dc0380 m_58;
    FUN_00dc0500(BSAudio* a1, BSAudio* a2);
};
// @fnv 0x00dc0500
FUN_00dc0500::FUN_00dc0500(BSAudio* pAudio, BSAudio* a2)
    : FUN_00d60830(pAudio, S_00dc0500_Opt(false)), m_10(S_00dc0500_Flag(false)), m_20(S_00dc0500_Flag(false)), m_30(0),
      m_58(a2)
{
    reinterpret_cast<::hkStringMapD874 *>(&(m_20))->FUN_00d874d0((const char *)(int *)(&(*reinterpret_cast<int *>((void *)&::DAT_01011584))), 0);
    reinterpret_cast<::hkStringMapD874 *>(&(m_10))->FUN_00d874d0((const char *)(int *)(&(*reinterpret_cast<int *>((void *)&::DAT_01011584))), 0);
}


struct S_dbf1a0_Map
{
    int unk00;
    int unk04;
};

struct S_dbf1a0_Handle
{
    void* m_ptr;
    S_dbf1a0_Handle(void* p) throw()
    {
        reinterpret_cast<::FUN_00dba650_cls *>(this)->FUN_00dba650((uintptr_t)(p));
    }
    S_dbf1a0_Handle() throw()
    {
        m_ptr = 0;
    }
    ~S_dbf1a0_Handle() throw()
    {
        ::FUN_00dba660();
    }

    void FUN_00dba650(void* p) throw();
    void FUN_00dba660() throw();
    const char* FUN_00dba680() const throw();
    int FUN_00dba690() const throw();
    int FUN_00dba6f0() const throw();
};

struct S_dbf1a0_Elem
{
    const char* name;
    const void* unk04;
    int flags;
    void* sub;
    int unk10;

    S_dbf1a0_Elem() throw() : name(0), unk04(0), flags(0), sub(0), unk10(0)
    {}
};

struct hkTempAlloc : hkMemoryAllocator
{
    virtual void* v04() throw();
    virtual void* v08() throw();
    virtual void* AllocateBufferWithSize(int& numBytes) throw();
    virtual void ReturnMemory(void* p, int numBytes) throw();

    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut) throw()
    {
        int n = reqNumInOut * (int)sizeof(T);
        T* p = (T*)AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return p;
    }
    template <typename T> __forceinline void _bufFree(void* p, int numElem) throw()
    {
        ReturnMemory(p, numElem * (int)sizeof(T));
    }
};

struct S_dbf1a0_Router
{
    void *unk00, *unk04, *unk08;
    hkTempAlloc* unk0c;
    hkTempAlloc& heap() throw()
    {
        return *unk0c;
    }
};

template <typename T> struct S_dbf1a0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline S_dbf1a0_Array(int n) throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        hkTempAlloc& alloc = ((S_dbf1a0_Router*)static_cast<BSAudio*>(::FUN_00c85750()))->heap();
        T* p = n ? alloc._bufAlloc<T>(n) : 0;
        int cap = n ? n : 0x80000000;
        m_data = p;
        m_iElementCount = n;
        m_iCapacityState = cap;
        if (n > 0)
        {
            T* e = p;
            do
            {
                new (e) T();
                ++e;
            } while (--n != 0);
        }
    }

    __forceinline ~S_dbf1a0_Array() throw()
    {
        hkTempAlloc& alloc = ((S_dbf1a0_Router*)static_cast<BSAudio*>(::FUN_00c85750()))->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
    }
};

struct S_dbf1a0_Writer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_dbf1a0_Map m_map;

    intptr_t WriteHandle(const S_dbf1a0_Handle& h) throw();
};

// @fnv 0x00dbf1a0
intptr_t S_dbf1a0_Writer::WriteHandle(const S_dbf1a0_Handle& ahHandle) throw()
{
    if (!ahHandle.m_ptr)
    {
        return 0;
    }

    const char* name = ahHandle.FUN_00dba680();
    intptr_t id = reinterpret_cast<::hkObjectD878 *>(&(m_map))->GetValue((intptr_t)(name), -1);
    if (id >= 0)
    {
        return id;
    }

    intptr_t parentId = WriteHandle((*(::S_dbf1a0_Handle *)(reinterpret_cast<::FUN_00dba6a0_cls *>((void *)&(ahHandle))->SetShiftedValue({}))));

    name = ahHandle.FUN_00dba680();
    id = reinterpret_cast<::hkObjectD878 *>(&(m_map))->GetValue((intptr_t)(name), -1);
    if (id != -1)
    {
        return id;
    }

    int iContactPointId = m_map.unk04;
    const char* curName = ahHandle.FUN_00dba680();
    reinterpret_cast<::hkStringMapD874 *>(&(m_map))->FUN_00d874d0(curName, iContactPointId);
    int count = ahHandle.FUN_00dba6f0();

    S_dbf1a0_Array<S_dbf1a0_Elem> arr(count);
    reinterpret_cast<::FUN_00dbaf10_cls *>((void *)&(ahHandle))->DispatchRecords(&arr);

    reinterpret_cast<::Obj *>(this)->WriteVarint(2);
    reinterpret_cast<::DBED30Writer *>(this)->WriteString(ahHandle.FUN_00dba680());
    reinterpret_cast<::Obj *>(this)->WriteVarint(ahHandle.FUN_00dba690());
    reinterpret_cast<::Obj *>(this)->WriteVarint(parentId);
    reinterpret_cast<::Obj *>(this)->WriteVarint(count);

    for (int i = 0; i < count; ++i)
    {
        S_dbf1a0_Elem* elem = &arr.m_data[i];
        reinterpret_cast<::DBED30Writer *>(this)->WriteString(elem->name);
        reinterpret_cast<::Obj *>(this)->WriteVarint(elem->flags);
        if (elem->flags & 0x20)
        {
            reinterpret_cast<::Obj *>(this)->WriteVarint(arr.m_data[i].unk10);
        }
        int type = elem->flags & 0xf;
        if (type == 9 || type == 8)
        {
            if (elem->sub)
            {
                reinterpret_cast<::DBED30Writer *>(this)->WriteString(S_dbf1a0_Handle(elem->sub).FUN_00dba680());
            }
            else
            {
                reinterpret_cast<::Obj *>(this)->WriteVarint(-1LL);
            }
        }
    }

    for (int i = 0; i < count; ++i)
    {
        void* sub = arr.m_data[i].sub;
        if (sub)
        {
            WriteHandle(S_dbf1a0_Handle(sub));
        }
    }

    return iContactPointId;
}

class hkMemoryAllocatorDBE8;

struct hkPairKeyDBE8
{
    uintptr_t m_k1;
    uintptr_t m_k2;
    bool operator==(const hkPairKeyDBE8& o) const
    {
        return m_k1 == o.m_k1 && m_k2 == o.m_k2;
    }
};

struct hkPairMapElemDBE8
{
    hkPairKeyDBE8 m_key;
    unsigned int m_uiFilterValue;
};

class hkPairMapDBE8
{
  public:
    hkPairMapElemDBE8* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int InsertOrUpdate(hkMemoryAllocatorDBE8& alloc, hkPairKeyDBE8 key, unsigned int uiValue);
};
// @fnv 0x00dbec60
void FUN_00dbec60_cls::FUN_00dbec60(AllocOwner* alloc, int count)
{
    int newCap = count;
    if (newCap <= 8)
        newCap = 8;

    unsigned int oldFlags = m_04 & 0x80000000u;
    Entry12* pOldEntries = m_00;
    int oldCount = m_08 + 1;

    m_00 = (Entry12*)alloc->Alloc(newCap * (unsigned int)sizeof(Entry12));
    for (int i = 0; i < newCap; ++i)
        m_00[i].a = 0;

    m_04 = 0;
    m_08 = newCap - 1;

    for (int i = 0; i < oldCount; ++i)
    {
        if (pOldEntries[i].a == 0)
            continue;
        volatile Entry12* v = pOldEntries;
        reinterpret_cast<::hkPairMapDBE8 *>((reinterpret_cast<FUN_00dbe810_cls*>(this)))->InsertOrUpdate((*(::hkMemoryAllocatorDBE8 *)(alloc)), ::hkPairKeyDBE8{v[i].a, v[i].b}, v[i].c);
    }

    if (oldFlags == 0)
        alloc->Free(pOldEntries, oldCount * (unsigned int)sizeof(Entry12));
}

// Grows the map if needed, finds the slot for key via open addressing, stores uiValue, and returns 1 if the key was newly inserted.
// @fnv 0x00dbe810
int hkPairMapDBE8::InsertOrUpdate(hkMemoryAllocatorDBE8& alloc, hkPairKeyDBE8 key, unsigned int uiValue)
{
    if ((m_iCapacityFlags & 0x7fffffff) * 2 > m_iPairCount)
        reinterpret_cast<::FUN_00dbec60_cls *>(this)->FUN_00dbec60((::AllocOwner *)&(alloc), m_iPairCount * 2 + 2);

    unsigned int i = ((key.m_k1 >> 4) * 0x9e3779b1) & m_iPairCount;
    int isNewKey = 1;
    while (m_kPrimitiveElement[i].m_key.m_k1 != 0)
    {
        if (m_kPrimitiveElement[i].m_key == key)
        {
            isNewKey = 0;
            break;
        }
        i = (i + 1) & m_iPairCount;
    }
    m_iCapacityFlags += isNewKey;
    m_kPrimitiveElement[i].m_key = key;
    m_kPrimitiveElement[i].m_uiFilterValue = uiValue;
    return isNewKey;
}

struct Pair;
struct ObjC;
struct Arr;
struct Rec
{
    intptr_t key;
    intptr_t value;
    int enabled;
    intptr_t fourth;
    int fifth;
    Rec() : key(0), value(0), enabled(0), fourth(0), fifth(0)
    {}
};
struct Wrap
{
    void* m_p;
    __declspec(nothrow) int FUN_00dbac10() const;
    __declspec(nothrow) Pair FUN_00dbabb0(int idx) const;
    __declspec(nothrow) Pair FUN_00dbab90(int idx) const;
    __declspec(nothrow) int FUN_00dbac00() const;
    __declspec(nothrow) void FUN_00dba7f0();
    __declspec(nothrow) ObjC FUN_00dbac20() const;
    __declspec(nothrow) void FUN_00dba660();
    ~Wrap()
    {
        reinterpret_cast<::FUN_00dbab70_cls *>(this)->FUN_00dbab70();
    }
};
struct Node50
{
    int m_00;
    int m_04;
    int m_08;
    float m_0c;
};
struct Pair
{
    void* m_p;
    int m_i;
    __declspec(nothrow) Wrap FUN_00dbacd0();
    __declspec(nothrow) Node50* DispatchToVTableSlot8(int mode);
    __declspec(nothrow) intptr_t FUN_00dbac70();
    __declspec(nothrow) float ApplyValue();
    __declspec(nothrow) int CallVirtualWithArg();
};
struct Arr
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    Arr()
    {}
    Arr(int n);
};
struct ObjC
{
    void* m_00;
    __declspec(nothrow) int FUN_00dba730();
    __declspec(nothrow) void FUN_00dba660();
    ~ObjC()
    {
        ::FUN_00dba660();
    }
};
struct __declspec(align(8)) Obj2
{
    char* m_00;
    int m_04;
    int m_08;
    __declspec(nothrow) void FUN_00dbef20(int n);
};
struct AllocV
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void* AllocBytes(int* psize);
    virtual void Free(void* p, unsigned int size);
};
static __forceinline Rec* allocateRecords(AllocV* allocator, int& capacity)
{
    if (capacity)
    {
        int bytes = capacity * (int)sizeof(Rec);
        Rec* data = (Rec*)allocator->AllocBytes(&bytes);
        capacity = bytes / (int)sizeof(Rec);
        return data;
    }
    return 0;
}
__forceinline Arr::Arr(int n)
{
    int capacity = n;
    m_data = 0;
    m_iElementCount = 0;
    m_cap = (int)0x80000000;
    BSAudio* router = static_cast<BSAudio*>(::FUN_00c85750());
    AllocV* allocator = (AllocV*)router->d;
    Rec* data = allocateRecords(allocator, capacity);
    int flags = capacity ? capacity : (int)0x80000000;
    m_data = data;
    m_iElementCount = capacity;
    m_cap = flags;
    for (int k = 0; k < capacity; ++k)
        new (data + k) Rec;
}
struct Host
{
    __declspec(nothrow) void WriteArray(const Wrap& arg0, int count);
};
struct S_00dbfef0_A;
struct S_00dbfef0_B;

struct S_00dbfef0_X
{
    const char* unk00;
    const void* unk04;
    int unk08;
    void* unk0C;
};

struct S_00dbfef0_Node
{
    float FUN_00dbaa00();
    int DispatchToInterface(int n);
    intptr_t FUN_00dba9c0();
    void GetResult(S_00dbfef0_A* out);
};

struct S_00dbfef0_B
{
    S_00dbfef0_X* p;
    void FUN_00dba7f0();
    int FUN_00dba680();
    void FUN_00dba660();
};

struct S_00dbfef0_A
{
    S_00dbfef0_Node* p;
    int FUN_00dbac00();
    int FUN_00dbac10();
    void FUN_00dbac20(S_00dbfef0_B* b);
};

struct S_00dbfef0_Sub
{
};

struct S_00dbfef0_Visitor
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S_00dbfef0_Sub m_sub;
    void WriteNode(S_00dbfef0_Node* node, S_00dbfef0_B b);
};

struct HkNodeE980
{
    int FUN_00dba9c0();
    float FUN_00dbaa00();
    __declspec(nothrow) ObjectHandle GetResult();
};
// Evaluates a node by dispatching on its type code and returning the corresponding boolean result.
// @fnv 0x00dbe980
int EvaluateNode(HkNodeE980* node)
{
    if (reinterpret_cast<::fnv_00dba920::Target *>((node))->QueryAndWriteResult() >= 0x10)
    {
        return node->GetResult().FUN_00dbac00();
    }
    switch (reinterpret_cast<::fnv_00dba920::Target *>((node))->QueryAndWriteResult())
    {
    case 0:
        return 0;
    case 1:
    case 2:
        return reinterpret_cast<::S_00dba990 *>((node))->FUN_00dba990() != 0;
    case 3:
        return node->FUN_00dbaa00() != 0.0f;
    case 4:
    case 6:
    case 7:
        return 1;
    case 8:
    case 9:
        return ((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(const ::StringHandle &)((*(::StringHandle *)(reinterpret_cast<::FUN_00dba9d0_cls *>((node))->FUN_00dba9d0({})))))->FUN_00dba980())) == 0;
    case 16:
        return node->GetResult().FUN_00dbac00() != 0;
    case 10:
        return node->FUN_00dba9c0() != 0;
    }
    return 0;
}

struct __declspec(nothrow) IHeap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int* pBytes);
    virtual void ReleaseBlock(void* p, int n);
};
inline __declspec(nothrow) IHeap& myAlloc()
{
    typedef BSAudio*(__cdecl * GetAudioFn)();
    GetAudioFn fn = (GetAudioFn)FUN_00c85750;
    AudioMgr* mgr = (AudioMgr*)fn();
    return *(IHeap*)mgr->unk0c;
}
struct FUN_00dba650
{
    void* object;
    __declspec(nothrow) FUN_00dba650()
    {}
    __declspec(nothrow) ~FUN_00dba650()
    {
        ::FUN_00dba660();
    }
    __declspec(nothrow) void FUN_00dba660();
    __declspec(nothrow) int FUN_00dba730();
};
struct MyDesc
{
    void* object;
    __declspec(nothrow) MyDesc()
    {
        object = 0;
    }
    __declspec(nothrow) ~MyDesc()
    {
        reinterpret_cast<::DBA7F0Ref *>(this)->FUN_00dba7f0();
    }
    __declspec(nothrow) void FUN_00dba7f0();
    __declspec(nothrow) ResourceKey GetSourcePair();
    __declspec(nothrow) FUN_00dba650 GetObjectValue();
    __declspec(nothrow) ResourceKey FUN_00dba890(intptr_t id);
};
struct AudioResourceState2
{
};
struct MyHolder
{
};
struct Entry24
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    uintptr_t unk10;
    uintptr_t unk18;
};
struct Struct20
{
    intptr_t a;
    intptr_t b;
    int c;
    intptr_t d;
    int e;
    __forceinline __declspec(nothrow) Struct20() : a(0), b(0), c(0), d(0), e(0)
    {}
};
struct MyCharArray : FUN_00dbef20
{
    int unk0c;
    __declspec(nothrow) MyCharArray(int n) : FUN_00dbef20(n)
    {}
    __forceinline __declspec(nothrow) ~MyCharArray()
    {
        IHeap& heap = myAlloc();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            heap.ReleaseBlock(m_data, cap & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct TempArr
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline __declspec(nothrow) TempArr(char* data, int size, int capacity)
        : m_data(data), m_iElementCount(size), m_iCapacityState(capacity | 0x80000000)
    {}

    __forceinline __declspec(nothrow) ~TempArr()
    {
        IHeap& heap = myAlloc();
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            heap.ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
};
struct Array20
{
    Struct20* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline __declspec(nothrow) Array20() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    static __forceinline __declspec(nothrow) Struct20* allocate(IHeap& heap, int& n)
    {
        if (n)
        {
            int bytes = n * (int)sizeof(Struct20);
            Struct20* p = (Struct20*)heap.AllocateBufferWithSize(&bytes);
            n = bytes / (int)sizeof(Struct20);
            return p;
        }
        return 0;
    }
    __forceinline __declspec(nothrow) Array20(int n) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        IHeap& heap = myAlloc();
        Struct20* data = allocate(heap, n);
        int capacity = n ? n : 0x80000000;
        setData(data, n, capacity);
        for (int i = 0; i < n; ++i)
        {
            new (data + i) Struct20();
        }
    }

    __forceinline __declspec(nothrow) void setData(Struct20* data, int n, int capacity)
    {
        m_data = data;
        m_iElementCount = n;
        m_iCapacityState = capacity;
    }

    __forceinline __declspec(nothrow) ~Array20()
    {
        IHeap& heap = myAlloc();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            heap.ReleaseBlock(m_data, (cap & 0x3fffffff) * (int)sizeof(Struct20));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct FUN_00d607b0_s
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct ResourceWriter : FUN_00d607b0_s
{
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int m_30;
    FUN_00dbe8c0_cls m_34;
    S_00dc0500_Arr m_40;
    S_00dc0500_Arr m_4c;
    AudioResourceState2 m_58;
    int unk5c, unk60, unk64, unk68, unk6c;


    __declspec(nothrow) void FUN_00dc00b0(MyDesc* input);
};
// Dispatches on the wrapper's type value and writes values or packed member data to the host.
// @fnv 0x00dbf930
void Host::WriteArray(const Wrap& arg0, int count)
{
    long i;
    if (arg0.FUN_00dbac10() & 0x20)
    {
        for (i = 0; i < count; i++)
        {
            Wrap j = arg0.FUN_00dbabb0(i).FUN_00dbacd0();
            int n = j.FUN_00dbac00();
            WriteArray(j, n);
        }
        return;
    }
    switch (arg0.FUN_00dbac10())
    {
    case 0:
        return;
    case 5:
        return;
    case 1: {
        for (i = 0; i < count; i++)
        {
            reinterpret_cast<::FUN_00d605d0_class *>(this)->FUN_00d605d0(arg0.FUN_00dbabb0(i).CallVirtualWithArg());
        }
    }
    break;
    case 2: {
        for (i = 0; i < count; i++)
        {
            reinterpret_cast<::Obj *>(this)->WriteVarint((__int64)arg0.FUN_00dbabb0(i).CallVirtualWithArg());
        }
    }
    break;
    case 3: {
        for (i = 0; i < count; i++)
        {
            float fValue = arg0.FUN_00dbabb0(i).ApplyValue();
            ::HashUInt((uintptr_t)this);
        }
    }
    break;
    case 4: {
        int n = count;
        int mode = 3;
        int i;
        for (i = 0; i < n; i++)
        {
            Node50* pNode = arg0.FUN_00dbabb0(i).DispatchToVTableSlot8(4);
            if (pNode->m_0c != 0.0f)
            {
                mode = 4;
                break;
            }
        }
        reinterpret_cast<::Obj *>(this)->WriteVarint((__int64)mode);
        for (i = 0; i < n; i++)
        {
            Node50* value = arg0.FUN_00dbabb0(i).DispatchToVTableSlot8(4);
            reinterpret_cast<::FUN_00d60b00_class *>(this)->WriteFloatArray((const float *)(value), mode);
        }
    }
    break;
    case 6:
    case 7: {
        int t = arg0.FUN_00dbac10();
        int off = 4 * t - 12;
        for (i = 0; i < count; i++)
        {
            Node50* value = arg0.FUN_00dbabb0(i).DispatchToVTableSlot8(off);
            reinterpret_cast<::FUN_00d60b00_class *>(this)->WriteFloatArray((const float *)(value), off);
        }
    }
    break;
    case 9: {
        Obj2 packedBits;
        int iCount = arg0.FUN_00dbac20().FUN_00dba730();
        Arr items(iCount);
        reinterpret_cast<::S_00dbaed0_Obj *>((void *)&(const ::ObjC &)(arg0.FUN_00dbac20()))->DispatchItems((::S_00dbaed0_Elem **)&(items));
        new ((void *)&(packedBits)) ::FUN_00dbef20(iCount);
        for (int idx = 0; idx < iCount; idx++)
        {
            Rec* r = (Rec*)items.m_data + idx;

            if (r->enabled != 0)
            {
                Wrap w9 = (*(::Wrap *)(reinterpret_cast<::FUN_00dbaea0_cls *>((void *)&(arg0))->InvokeCallbackInto((::FUN_00dbab50_cls *)(r->key), {})));
                int buf = w9.FUN_00dbac00();
                for (int j = 0; j < buf; j++)
                {
                    if (::IsTruthy((::Value *)this) != 0)
                    {
                        packedBits.m_00[idx] = 1;
                        break;
                    }
                    buf = w9.FUN_00dbac00();
                }
            }
        }
        hkCharArray m;
        m.m_data = 0;
        m.m_iElementCount = 0;
        m.m_iCapacityState = (int)0x80000000;
        int need = ((packedBits.m_04 + 7) & ~7) / 8;
        m.setSizeUnchecked(need);
        reinterpret_cast<::Rec_00dbf0d0 *>(&(packedBits))->PackBitsToBytes((unsigned char *)(m.m_data));
        reinterpret_cast<::FUN_00d607b0_class *>(this)->FUN_00d607b0((intptr_t)(m.m_data));
        {
            BSAudio* pRouter = static_cast<BSAudio*>(::FUN_00c85750());
            AllocV* pAllocator = (AllocV*)(void*)pRouter->d;
            long cap2 = m.m_iCapacityState;
            m.m_iElementCount = 0;
            if ((cap2 & 0x80000000u) == 0)
                pAllocator->Free(m.m_data, cap2 & 0x3fffffff);
        }
        {
            for (i = 0; i < iCount; i++)
            {
                if (packedBits.m_00[i] != 0)
                {
                    Rec* r;
                    r = (Rec*)items.m_data + i;

                    Wrap w9b = (*(::Wrap *)(reinterpret_cast<::FUN_00dbaea0_cls *>((void *)&(arg0))->InvokeCallbackInto((::FUN_00dbab50_cls *)(r->key), {})));
                    WriteArray(w9b, count);
                }
            }
        }
        {
            BSAudio* sn = static_cast<BSAudio*>(::FUN_00c85750());
            AllocV* mn = (AllocV*)(void*)sn->d;
            int cap = packedBits.m_08;
            packedBits.m_04 = 0;
            if ((cap & 0x80000000u) == 0)
                mn->Free(packedBits.m_00, cap & 0x3fffffff);
            packedBits.m_00 = 0;
            packedBits.m_08 = (int)0x80000000;
        }
        {
            BSAudio* s4 = static_cast<BSAudio*>(::FUN_00c85750());
            AllocV* mgr4 = (AllocV*)(void*)s4->d;
            long cap1 = items.m_cap;
            items.m_iElementCount = 0;
            if ((cap1 & 0x80000000u) == 0)
                mgr4->Free(items.m_data, (cap1 & 0x3fffffff) * (unsigned int)sizeof(Rec));
        }
    }
    break;
    case 8: {
        for (i = 0; i < count; i++)
        {
            reinterpret_cast<::ResourceWriter *>(this)->FUN_00dc00b0((::MyDesc *)&(const ::StringHandle &)((*(::StringHandle *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)&(const ::Pair &)(arg0.FUN_00dbabb0(i)))->CreateValueInto({})))));
        }
    }
    break;
    case 10: {
        for (i = 0; i < count; i++)
        {
            reinterpret_cast<::DBED30Writer *>(this)->WriteString((const char *)(arg0.FUN_00dbabb0(i).FUN_00dbac70()));
        }
    }
    break;
    default:
        break;
    }
}
// Writes a node's result to the visitor's output stream, dispatching on the result type to emit varints, floats, strings, or nested values.
// @fnv 0x00dbfef0
void S_00dbfef0_Visitor::WriteNode(S_00dbfef0_Node* node, S_00dbfef0_B b)
{
    if (reinterpret_cast<::fnv_00dba920::Target *>((node))->QueryAndWriteResult() & 0x20)
    {
        S_00dbfef0_A a;
        node->GetResult(&a);
        reinterpret_cast<::Host *>(this)->WriteArray((*(const ::Wrap *)(&a)), a.FUN_00dbac00());
        reinterpret_cast<::FUN_00dbab70_cls *>(&(a))->FUN_00dbab70();
        return;
    }
    if (reinterpret_cast<::fnv_00dba920::Target *>((node))->QueryAndWriteResult() & 0x10)
    {
        S_00dbfef0_A a;
        node->GetResult(&a);
        int n = a.FUN_00dbac00();
        reinterpret_cast<::Obj *>(this)->WriteVarint(n);
        if (a.FUN_00dbac10() == 9 && b.p->unk0C == 0)
        {
            a.FUN_00dbac20(&b);
            int v = b.FUN_00dba680();
            intptr_t r = reinterpret_cast<::hkObjectD878 *>(&(m_sub))->GetValue(v, 0);
            reinterpret_cast<::Obj *>(this)->WriteVarint(r);
            ::FUN_00dba660();
        }
        reinterpret_cast<::Host *>(this)->WriteArray((*(const ::Wrap *)(&a)), n);
        reinterpret_cast<::FUN_00dbab70_cls *>(&(a))->FUN_00dbab70();
        return;
    }
    switch (reinterpret_cast<::fnv_00dba920::Target *>((node))->QueryAndWriteResult())
    {
    case 1:
        reinterpret_cast<::FUN_00d605d0_class *>(this)->FUN_00d605d0(reinterpret_cast<::S_00dba990 *>((node))->FUN_00dba990());
        break;
    case 2:
        reinterpret_cast<::Obj *>(this)->WriteVarint(reinterpret_cast<::S_00dba990 *>((node))->FUN_00dba990());
        break;
    case 3: {
        float f = node->FUN_00dbaa00();
        ::HashUInt((uintptr_t)this);
    }
    break;
    case 4:
    case 6:
    case 7: {
        int n = reinterpret_cast<::fnv_00dba920::Target *>((node))->QueryAndWriteResult() * 4 - 12;
        intptr_t p = node->DispatchToInterface(n);
        reinterpret_cast<::FUN_00d60b00_class *>(this)->WriteFloatArray((const float *)(p), n);
        break;
    }
    case 8:
    case 9:
        reinterpret_cast<::ResourceWriter *>(this)->FUN_00dc00b0((::MyDesc *)(((intptr_t)(reinterpret_cast<::FUN_00dba9d0_cls *>((node))->FUN_00dba9d0((::FUN_00dba760_cls *)(::S_00dbfef0_B *)(&b))))));
        reinterpret_cast<::DBA7F0Ref *>(&(b))->FUN_00dba7f0();
        break;
    case 10:
        reinterpret_cast<::DBED30Writer *>(this)->WriteString((const char *)(node->FUN_00dba9c0()));
        break;
    }
}
// Resolves a sound, writes a varint tag, handle, and per-item resource keys to the resource stream.
// @fnv 0x00dc00b0
void ResourceWriter::FUN_00dc00b0(MyDesc* apSoundDesc)
{
    MyDesc desc = (*(::MyDesc *)(reinterpret_cast<::AudioResourceState *>(&(m_58))->ResolveSound((::Receiver *)(apSoundDesc), {})));
    if (((int)(reinterpret_cast<::FUN_00dba980_cls *>(&(desc))->FUN_00dba980())))
    {
        reinterpret_cast<::Obj *>(this)->WriteVarint(6);
        return;
    }

    ResourceKey key = desc.GetSourcePair();
    int iEntryIndex = (int)m_34.FindEntryValue(key.first, key.second, -1);
    Entry24* kIter = &((Entry24*)m_4c.a)[iEntryIndex];
    if (kIter->unk04 >= 0)
    {
        reinterpret_cast<::Obj *>(this)->WriteVarint(5);
        reinterpret_cast<::Obj *>(this)->WriteVarint(kIter->unk04);
        return;
    }

    FUN_00dba650 k = desc.GetObjectValue();
    intptr_t reqBytes = reinterpret_cast<::S_dbf1a0_Writer *>(this)->WriteHandle((*(const ::S_dbf1a0_Handle *)(&k)));
    if (1 < kIter->unk0c)
    {
        reinterpret_cast<::Obj *>(this)->WriteVarint(4);
        kIter->unk04 = m_30++;
    }
    else
    {
        reinterpret_cast<::Obj *>(this)->WriteVarint(3);
    }
    kIter->unk00 = 1;
    reinterpret_cast<::Obj *>(this)->WriteVarint(reqBytes);

    int c;
    c = k.FUN_00dba730();
    MyCharArray charArr(c);

    intptr_t res;
    res = (intptr_t)m_40.a + kIter->unk08;
    int count = ((charArr.m_iElementCount + 7) & ~7) / 8;
    {
        TempArr temp((char*)res, count, count);
        reinterpret_cast<::FUN_00d607b0_class *>(this)->FUN_00d607b0((intptr_t)temp.m_data);
        reinterpret_cast<::S_dbefc0_Bytes *>(&(charArr))->FUN_00dbefc0((const unsigned char *)(temp.m_data), temp.m_iElementCount);
    }

    Array20 ptr(c);

    reinterpret_cast<::S_00dbaed0_Obj *>(&(k))->DispatchItems((::S_00dbaed0_Elem **)(void *)(&ptr));

    for (int i = 0; c > i; ++i)
    {
        if (charArr.m_data[i])
        {
            Struct20* item = &ptr.m_data[i];
            ResourceKey z = desc.FUN_00dba890(item->a);
            reinterpret_cast<::S_00dbfef0_Visitor *>(this)->WriteNode((::S_00dbfef0_Node *)(::ResourceKey *)(&z), ::S_00dbfef0_B{(::S_00dbfef0_X *)item});
        }
    }
}

struct ScanKey
{
    uintptr_t first, second;
    ScanKey& operator=(const ScanKey& k)
    {
        first = k.first;
        second = k.second;
        return *this;
    }
};
struct ScanClass;
struct ScanArray;
struct ScanValue;
struct ScanItem;
struct ScanObject
{
    void* object;
    __declspec(nothrow) ScanKey GetSourcePair() const;
    __declspec(nothrow) ScanClass GetObjectValue() const;
    __declspec(nothrow) int FUN_00dba8b0() const;
    __declspec(nothrow) int FUN_00dba8c0(intptr_t iterator) const;
    __declspec(nothrow) int FUN_00dba8d0(intptr_t iterator) const;
    __declspec(nothrow) int FUN_00dba8e0(intptr_t iterator) const;
    __declspec(nothrow) void FUN_00dba7f0();
    ~ScanObject()
    {
        reinterpret_cast<::DBA7F0Ref *>(this)->FUN_00dba7f0();
    }
};
struct ScanMember
{
    intptr_t name, flags, type, className, extra;
    ScanMember() : name(0), flags(0), type(0), className(0), extra(0)
    {}
};
struct ScanClass
{
    void* object;
    __declspec(nothrow) int FUN_00dba730() const;
    __declspec(nothrow) int FUN_00dba740(int name) const;
    __declspec(nothrow) void FUN_00dba660();
    ~ScanClass()
    {
        ::FUN_00dba660();
    }
};
struct ScanArray
{
    void* object;
    __declspec(nothrow) int FUN_00dbac00() const;
    __declspec(nothrow) ScanClass FUN_00dbac20() const;
    __declspec(nothrow) ScanItem FUN_00dbab90(int index) const;
    ~ScanArray()
    {
        reinterpret_cast<::FUN_00dbab70_cls *>(this)->FUN_00dbab70();
    }
};
struct ScanValue
{
    void* object;
    int index;
    __declspec(nothrow) ScanArray GetResult() const;
};
struct ScanItem
{
    void* object;
    int index;
};
struct ScanResources
{
    __declspec(nothrow) ScanObject FUN_00dbedd0(const ScanObject& source);
};
struct ScanRecord
{
    int first, second, bitOffset, count;
    ScanKey key;
};
extern ScanRecord DAT_010d6848;
struct ScanReferences
{
    ScanRecord* data;
    int size, capacity;
    __forceinline ScanRecord& back()
    {
        return data[size - 1];
    }
    __forceinline void append(const ScanRecord& value)
    {
        hkMemoryAllocator& heap = ::audio()->tempHeap();
        if (size == (capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)&(heap), (::AudioStream *)(void *)(this), sizeof(ScanRecord));
        data[size++] = value;
    }
};
struct ScanMap
{
    void* data;
    int size, capacity;
    __forceinline void insert(AllocOwner* heap, ScanKey key, int value)
    {
        reinterpret_cast<::hkPairMapDBE8 *>(this)->InsertOrUpdate((*(::hkMemoryAllocatorDBE8 *)(heap)), ::hkPairKeyDBE8{key.first, key.second}, value);
    }
};
struct ScanMask : hkCharArray
{
    int unk0c;
    __declspec(nothrow) void FUN_00dbef20(int n);
    __forceinline char& memberInteresting(int index)
    {
        return m_data[index];
    }
    __forceinline ScanMask(int n)
    {
        new ((void *)this) ::FUN_00dbef20(n);
    }
    __forceinline ~ScanMask()
    {
        hkTempAlloc& heap = ((S_dbf1a0_Router*)static_cast<BSAudio*>(::FUN_00c85750()))->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000u) == 0)
            heap.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct ScanWriter
{
    AudioObject first, second, third;
    int unk30;
    ScanMap map;
    hkCharArray bits;
    ScanReferences references;
    ScanResources resources;
    __declspec(nothrow) void FUN_00dbf450(const ScanObject& source, int supplemental);
};
// Resolves a ScanObject, deduplicates it in the reference map, and recursively writes its class handle, member mask, and nested values to the writer's bit buffer.
// @fnv 0x00dbf450
void ScanWriter::FUN_00dbf450(const ScanObject& source, int supplemental)
{
    ScanObject object = resources.FUN_00dbedd0(source);
    if (((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(object))->FUN_00dba980())))
        return;
    {
        ScanKey key = object.GetSourcePair();
        int index = ((int)(reinterpret_cast<::FUN_00dbe8c0_cls *>((void *)&(map))->FindEntryValue(key.first, key.second, -1)));
        if (index != -1)
        {
            ++references.data[index].count;
            return;
        }
        if (!supplemental)
        {
            index = map.size & 0x7fffffff;
            map.insert(reinterpret_cast<AllocOwner*>(static_cast<BSAudio*>(::FUN_00c85750())->e), object.GetSourcePair(), index);
            references.append(DAT_010d6848);
            ScanRecord& record = references.back();
            record.key = object.GetSourcePair();
        }
        ScanClass type = object.GetObjectValue();
        reinterpret_cast<::S_dbf1a0_Writer *>(this)->WriteHandle((const ::S_dbf1a0_Handle &)(type));
        ScanMask mask(type.FUN_00dba730());
        for (intptr_t iterator = object.FUN_00dba8b0(); object.FUN_00dba8c0(iterator);
             iterator = object.FUN_00dba8d0(iterator))
        {
            ScanValue value = (*(::ScanValue *)(reinterpret_cast<::FUN_00dba8f0_cls *>((void *)&(object))->FUN_00dba8f0((void *)(iterator), {})));
            if (::EvaluateNode((::HkNodeE980 *)this))
            {
                mask.memberInteresting(type.FUN_00dba740(object.FUN_00dba8e0(iterator))) = 1;
                int kind = reinterpret_cast<::fnv_00dba920::Target *>((void *)&(value))->QueryAndWriteResult() & 15;
                if (kind == 8 || kind == 9)
                {
                    switch (reinterpret_cast<::fnv_00dba920::Target *>((void *)&(value))->QueryAndWriteResult())
                    {
                    case 8:
                    case 9:
                        FUN_00dbf450((*(::ScanObject *)(reinterpret_cast<::FUN_00dba9d0_cls *>((void *)&(value))->FUN_00dba9d0({}))), 0);
                        break;
                    case 25:
                    case 41: {
                        ScanClass elementType = value.GetResult().FUN_00dbac20();
                        reinterpret_cast<::S_dbf1a0_Writer *>(this)->WriteHandle((const ::S_dbf1a0_Handle &)(elementType));
                        for (int member = 0; member < elementType.FUN_00dba730(); ++member)
                        {
                            ScanMember description;
                            reinterpret_cast<::DataClassMemberAccess *>((void *)&(elementType))->FUN_00dba720(member, (::S_00dbaed0_Elem *)&(description));
                            if (description.type == 8)
                            {
                                ScanArray elements = (*(::ScanArray *)(reinterpret_cast<::FUN_00dbaea0_cls *>((void *)(void *)&(const ::ScanArray &)(value.GetResult()))->InvokeCallbackInto((::FUN_00dbab50_cls *)(description.name), {})));
                                int count = elements.FUN_00dbac00();
                                for (int i = 0; i < count; ++i)
                                {
                                    FUN_00dbf450((*(::ScanObject *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)(void *)&(const ::ScanItem &)(elements.FUN_00dbab90(i)))->CreateValueInto({}))), 0);
                                }
                            }
                        }
                        break;
                    }
                    case 24:
                    case 40: {
                        int count = value.GetResult().FUN_00dbac00();
                        for (int i = 0; i < count; ++i)
                        {
                            FUN_00dbf450((*(::ScanObject *)(reinterpret_cast<::FUN_00dbaca0_cls *>((void *)(void *)&(const ::ScanItem &)(value.GetResult().FUN_00dbab90(i)))->CreateValueInto({}))), 0);
                        }
                        break;
                    }
                    }
                }
            }
        }
        if (!supplemental)
        {
            references.data[index].bitOffset = bits.m_iElementCount;
            int bytes = ((mask.m_iElementCount + 7) & ~7) / 8;
            hkCharArray& destination = bits;
            hkMemoryAllocator& heap = ::audio()->tempHeap();
            int oldSize = destination.m_iElementCount;
            int newSize = oldSize + bytes;
            int capacity = destination.getCapacity();
            if (capacity < newSize)
            {
                int doubled = capacity * 2;
                ::FUN_00c908c0((::SpawnedObject *)&(heap), (::SpawnedArray *)(void *)(&destination), newSize < doubled ? doubled : newSize, 1);
            }
            destination.m_iElementCount += bytes;
            reinterpret_cast<::Rec_00dbf0d0 *>(&(mask))->PackBitsToBytes((unsigned char *)(void *)(destination.m_data + oldSize));
        }
    }
}

struct S00dbedb0_Callee : UnkHolder
{
};
// @fnv 0x00dbedb0
__declspec(noinline) void UnkHolder::FUN_00dbedb0(UnkRet* value, int count)
{
    int needed = count + count;
    int capacity = 8;
    while (capacity < needed)
        capacity += capacity;
    reinterpret_cast<::FUN_00dbec60_cls *>((((S00dbedb0_Callee*)this)))->FUN_00dbec60((::AllocOwner *)(value), capacity);
}


struct ObjImpl;
struct ObjHandle
{
    ObjImpl* p0;
    ObjImpl* p1;
};
struct DataObj
{
    ObjImpl* m_pClassImpl;
    DataObj(ObjImpl* impl);
    DataObj(const DataObj& o);
    ~DataObj();
    ObjHandle GetObjectHandle() const;
    static void* operator new(std::size_t n);
};
struct DataWorld
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual DataObj CopyContents(const DataObj& src);
};
struct BlockAlloc
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct ContainerHeap;
struct MemRouter
{
    void *unk00, *unk04, *unk08;
    ContainerHeap* m_pStreamAllocator;
    BlockAlloc* m_block;
    ContainerHeap& heap()
    {
        return *m_pStreamAllocator;
    }
    BlockAlloc& block()
    {
        return *m_block;
    }
};
__forceinline MemRouter& router()
{
    return *(MemRouter*)static_cast<BSAudio*>(::FUN_00c85750());
}
struct HandleMap
{
    void* m_kPrimitiveElement;
    int m_iCapacityFlags, m_iPairCount;
    void insert(BlockAlloc& a, ObjImpl* key0, ObjImpl* key1, int val);
    __forceinline void insert(ObjHandle key, int val)
    {
        reinterpret_cast<::hkPairMapDBE8 *>(this)->InsertOrUpdate((::hkMemoryAllocatorDBE8 &)(router().block()), ::hkPairKeyDBE8{(uintptr_t)key.p0, (uintptr_t)key.p1}, val);
    }
};
template <typename T> __forceinline void constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <typename T> struct PtrArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void AddBack(const T& t)
    {
        ContainerHeap& h = router().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)&(h), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopy(m_data + m_iElementCount++, 1, t);
    }
};
__forceinline void* DataObj::operator new(std::size_t n)
{
    return router().block().AllocateMemoryBlock((int)n);
}
struct ObjCloner
{
    DataWorld* m_pOwningWorld;
    HandleMap m_kHandleMap;
    PtrArray<DataObj*> m_objs;
    DataObj FUN_00dbedd0(const DataObj& src);
};
// @fnv 0x00dbedd0
DataObj ObjCloner::FUN_00dbedd0(const DataObj& src)
{
    if (m_pOwningWorld && !((int)(reinterpret_cast<::FUN_00dba980_cls *>((void *)&(src))->FUN_00dba980())))
    {
        ObjHandle h = src.GetObjectHandle();
        int idx = ((int)(reinterpret_cast<::FUN_00dbe8c0_cls *>((void *)&(m_kHandleMap))->FindEntryValue((uintptr_t)h.p0, (uintptr_t)h.p1, -1)));
        if (idx == -1)
        {
            DataObj dst = m_pOwningWorld->CopyContents(src);
            if (::FUN_00dbaf90((void *)&(dst)))
            {
                m_kHandleMap.insert(h, m_objs.GetLogicalSize());
                m_objs.AddBack(new DataObj(dst));
                return dst;
            }
        }
        else
        {
            return DataObj(m_objs[idx]->m_pClassImpl);
        }
    }
    return src;
}

#include "generated/data/havok/common/serialize/tagfile/binary/hkbinarytagfilewriter.inc"
