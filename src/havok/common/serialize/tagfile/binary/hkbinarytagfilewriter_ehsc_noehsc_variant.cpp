
// src/havok/common/serialize/tagfile/binary/hkbinarytagfilewriter_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/tagfile/binary/hkbinarytagfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include <cstddef>
#include "fnv/decl/DBA7F0Ref.h"
#include "fnv/decl/DBAFB0Handle.h"
#include "fnv/decl/DataClassAccess.h"
#include "fnv/decl/DataObjectHandle.h"
#include "fnv/decl/FUN_00d605d0_class.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/FUN_00d60b00_class.h"
#include "fnv/decl/FUN_00dba650_cls.h"
#include "fnv/decl/FUN_00dba680_cls.h"
#include "fnv/decl/FUN_00dba6a0_cls.h"
#include "fnv/decl/FUN_00dba730_cls.h"
#include "fnv/decl/FUN_00dba780_cls.h"
#include "fnv/decl/FUN_00dba810_cls.h"
#include "fnv/decl/FUN_00dba980_cls.h"
#include "fnv/decl/FUN_00dba9c0_cls.h"
#include "fnv/decl/FUN_00dba9d0_cls.h"
#include "fnv/decl/FUN_00dbab70_cls.h"
#include "fnv/decl/FUN_00dbab90_cls.h"
#include "fnv/decl/FUN_00dbabb0_cls.h"
#include "fnv/decl/FUN_00dbac50_cls.h"
#include "fnv/decl/FUN_00dbac70_cls.h"
#include "fnv/decl/FUN_00dbaca0_cls.h"
#include "fnv/decl/FUN_00dbaea0_cls.h"
#include "fnv/decl/FUN_00dbaf10_cls.h"
#include "fnv/decl/MemberArrayValue.h"
#include "fnv/decl/Outer_dbac40.h"
#include "fnv/decl/ResourceWriter.h"
#include "fnv/decl/S_00dba990.h"
#include "fnv/decl/S_00dbac90.h"
#include "fnv/decl/S_00dbaed0_Obj.h"
#include "fnv/decl/ScanWriter.h"
#include "fnv/decl/This_2.h"
#include "fnv/decl/Wrapper.h"
#include "fnv/decl/fnv_00dba920__Target.h"
#include "fnv/decl/fnv_00dba9a0__FUN_00dba9a0_cls.h"
#include "fnv/decl/fnv_00dbaa00__Wrapper.h"
#include "fnv/decl/fnv_00dbac00__Wrapper.h"
#include "fnv/decl/fnv_00dbac10__CpuObject.h"
#include "fnv/decl/fnv_00dbac80__Wrapper.h"
#include "fnv/decl/fnv_00dc0460__Obj.h"
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
BSAudio* __cdecl FUN_00c85750();
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
    int a;
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
struct ObjectHandle
{
    void* object;
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
};
struct ResourceKey
{
    int first;
    int second;
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
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator& tempHeap()
    {
        return *unk0c;
    }
};
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}
void* __cdecl _fnv_zlib_memset(void* dst, int val, int n);
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
        _fnv_zlib_memset(p, 0, num);
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
    int unk00;
    int unk04;
    int unk08;
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
    void FUN_00dc0500(int, int);
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
int WriteAudioObject(int value, CallbackTarget* target, int source);
struct Obj
{
    void WriteVarint(__int64);
};
struct FUN_00dbe8c0_cls
{
    struct HashEntry
    {
        unsigned int key0;
        unsigned int key1;
        unsigned int value;
    };

    HashEntry* m_pEntries;
    unsigned int m_u04;
    unsigned int m_uMask;

    unsigned int FindEntryValue(unsigned int aKey0, unsigned int aKey1, unsigned int aDefault);
};
// A 12-byte hash table (as used by the hkPackfileWriter module): a pointer to
// an array of 12-byte entries, a flag word and the number of entries.
struct HashEntry
{
    int unk00;
    int unk04;
    int unk08;
};
struct HashTableBase
{
    HashEntry* m_entries;
    int m_flags;
    int m_uiItemCount;

    void ClearEntries();
};
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
struct AllocOwner
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* p, unsigned int size);
};
struct Entry12
{
    int a;
    int b;
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
struct S_dbefc0_Heap
{
    int unk;
};
struct S_dbefc0_Router
{
    int unk00;
    int unk04;
    int unk08;
    S_dbefc0_Heap* unk0c;
    S_dbefc0_Heap& heap()
    {
        return *unk0c;
    }
};
void* __cdecl FUN_00ec61c0(void* dst, int value, unsigned int count);
static __forceinline S_dbefc0_Heap& S_dbefc0_GetHeap()
{
    return ((S_dbefc0_Router*)FUN_00c85750())->heap();
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
        FUN_00ec61c0(p, 0, diff);
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
struct Rec_00dbf0d0
{
    unsigned char* unk00;  // data buffer
    int unk04;             // used size
    int unk08;             // capacity (low 30 bits) + flags
    void PackBitsToBytes(unsigned char* dest);
};
void __cdecl fnv_memset_00ec61c0(void* dest, int ch, int count);
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
        BSAudio* p = FUN_00c85750();
        FUN_00dbedb0((UnkRet*)p->e, 0);
    }
};
struct S_00dc0500_Arr
{
    int a;
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
        reinterpret_cast<::FUN_00dba650_cls *>(this)->FUN_00dba650((unsigned int)(p));
    }
    S_dbf1a0_Handle() throw()
    {
        m_ptr = 0;
    }
    ~S_dbf1a0_Handle() throw()
    {
        ::FUN_00dba660();
    }

    void FUN_00dba660() throw();
};
struct S_dbf1a0_Elem
{
    const char* name;
    int unk04;
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
    int unk00, unk04, unk08;
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
        hkTempAlloc& alloc = ((S_dbf1a0_Router*)FUN_00c85750())->heap();
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
        hkTempAlloc& alloc = ((S_dbf1a0_Router*)FUN_00c85750())->heap();
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

    int WriteHandle(const S_dbf1a0_Handle& h) throw();
};
class hkMemoryAllocatorDBE8;
struct hkPairKeyDBE8
{
    unsigned int m_k1;
    unsigned int m_k2;
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
struct Pair;
struct ObjC;
struct Arr;
struct Rec
{
    int key;
    int value;
    int enabled;
    int fourth;
    int fifth;
    Rec() : key(0), value(0), enabled(0), fourth(0), fifth(0)
    {}
};
struct Wrap
{
    void* m_p;
    __declspec(nothrow) void FUN_00dba7f0();
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
    BSAudio* router = FUN_00c85750();
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
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct S_00dbfef0_Node
{
};
struct S_00dbfef0_B
{
    S_00dbfef0_X* p;
    void FUN_00dba7f0();
    void FUN_00dba660();
};
struct S_00dbfef0_A
{
    S_00dbfef0_Node* p;
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
    int unk00, unk04, unk08;
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
    return *(MemRouter*)FUN_00c85750();
}
struct HandleMap
{
    int m_kPrimitiveElement, m_iCapacityFlags, m_iPairCount;
    void insert(BlockAlloc& a, ObjImpl* key0, ObjImpl* key1, int val);
    __forceinline void insert(ObjHandle key, int val)
    {
        reinterpret_cast<::hkPairMapDBE8 *>(this)->InsertOrUpdate((::hkMemoryAllocatorDBE8 &)(router().block()), (::hkPairKeyDBE8)(key.p0), (unsigned int)(key.p1));
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
    return router().block().AllocateMemoryBlock(n);
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
        int idx = ((int)(reinterpret_cast<::FUN_00dbe8c0_cls *>((void *)&(m_kHandleMap))->FindEntryValue((*(unsigned int *)&(const ::ObjHandle &)(h)), -1, {})));
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
