
// src/havok/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/tagfile/binary/hkbinarytagfilereader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstddef>
#include "fnv/decl/S00dc5f30_Obj.h"
#include <new>
#include <cstring>
#include "fnv/decl/AudioHandle.h"
#include "fnv/decl/DBA7F0Ref.h"
#include "fnv/decl/DBABE0Binding.h"
#include "fnv/decl/DBADC0Binding.h"
#include "fnv/decl/DD8FE0_Stream.h"
#include "fnv/decl/DataObjectHandle.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00dba650_cls.h"
#include "fnv/decl/FUN_00dba780_cls.h"
#include "fnv/decl/FUN_00dba870_cls.h"
#include "fnv/decl/FUN_00dbaa30_cls.h"
#include "fnv/decl/FUN_00dbaa50_cls.h"
#include "fnv/decl/FUN_00dbaa90_cls.h"
#include "fnv/decl/FUN_00dbaab0_cls.h"
#include "fnv/decl/FUN_00dbab50.h"
#include "fnv/decl/FUN_00dbab70_cls.h"
#include "fnv/decl/FUN_00dbad00_cls.h"
#include "fnv/decl/FUN_00dbad60_cls.h"
#include "fnv/decl/FUN_00dbae80_cls.h"
#include "fnv/decl/FUN_00dbaea0_cls.h"
#include "fnv/decl/FUN_00dd90d0_cls.h"
#include "fnv/decl/FUN_00dd9130_class.h"
#include "fnv/decl/S_00dbab30_Ref.h"
#include "fnv/decl/S_00dbaed0_Obj.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/fnv_00dba920__Target.h"
#include "fnv/decl/fnv_00dbada0__Wrapper.h"
#include "fnv/decl/fnv_00dbae10__Outer.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00dba000.h"
#include "fnv/symbols_00dc5000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01268000.h"
extern "C" void* DAT_010d6ce8;

struct FUN_00dc5d30
{
    void* m_p;
    short m_usTrailingValue;
    short m_f;
    FUN_00dc5d30();
};

// @fnv 0x00dc5d30
FUN_00dc5d30::FUN_00dc5d30()
{
    m_f = 1;
    m_p = &DAT_010d6ce8;
}

struct hkBinaryTagFileReaderVirtualObject
{
    virtual void FreeAllBlocks(int);
};

struct hkMemoryRouterContext
{
    virtual void FUN_00d00000();
    virtual void FUN_00d00004();
    virtual void FUN_00d00008();
    virtual void FUN_00d0000c();
    virtual void Free(void*, unsigned int);
};

struct NineIntegerRecord
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0c;
    hkMemoryRouterContext* m_p10;
};

NineIntegerRecord* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c856c0(void*, void*);

struct hkLargeBlockAllocator
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0c;
    void* m_p10;
    hkBinaryTagFileReaderVirtualObject* m_p14;
    void* m_p18;
    unsigned int m_n1c;
    unsigned int m_flags20;
    void** m_p24;
    int m_n28;
    unsigned int m_flags2c;
    void* m_p30;
    unsigned int m_n34;
    unsigned int m_flags38;

    void FreeAllBlocks();
    void FUN_00dd91f0();
};

// @fnv 0x00dc6020
void hkLargeBlockAllocator::FreeAllBlocks()
{
    if (m_p14)
        m_p14->FreeAllBlocks(1);

    int i = 2;
    if (i < m_n28)
    {
        do
        {
            void* item = m_p24[i];
            NineIntegerRecord* router = _D1A0E0GetMemoryRouter();
            _FUN_00c856c0(router->m_p10, item);
            ++i;
        } while (i < m_n28);
    }

    NineIntegerRecord* router = _D1A0E0GetMemoryRouter();
    hkMemoryRouterContext* context = router->m_p10;
    unsigned int flags = m_flags38;
    m_n34 = 0;
    if (!(flags & 0x80000000))
        context->Free(m_p30, (flags & 0x3fffffff) * 4);
    m_p30 = 0;
    m_flags38 = 0x80000000;

    router = _D1A0E0GetMemoryRouter();
    context = router->m_p10;
    flags = m_flags2c;
    m_n28 = 0;
    if (!(flags & 0x80000000))
        context->Free(m_p24, (flags & 0x3fffffff) * 4);
    m_p24 = 0;
    m_flags2c = 0x80000000;

    router = _D1A0E0GetMemoryRouter();
    context = router->m_p10;
    flags = m_flags20;
    m_n1c = 0;
    if (!(flags & 0x80000000))
        context->Free(m_p18, (flags & 0x3fffffff) * 4);
    m_p18 = 0;
    m_flags20 = 0x80000000;

    return FUN_00dd91f0();
}

class hkMemoryAllocatorDC5D;

struct hkMemoryRouterDC5D
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC5D* m_pStreamAllocator;
    hkMemoryAllocatorDC5D& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC5D& __cdecl FUN_00c85750();


template <class T> __forceinline void constructWithCopyDC5D(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayDC5D
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorDC5D& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyDC5D(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

char* __cdecl AllocateWithHeader(hkMemoryAllocatorDC5D* pkAlloc, int iNumBytes) throw();

class hkBinaryReaderDC5D
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    hkArrayDC5D<char*> m_pStringFunctions;

    char* ReadString();
};

namespace fnv_00dc5e10 {
struct hkAllocatorDC5E
{
    virtual void V0() throw();
};

struct hkMemoryRouterDC5E
{
    void* m_apvUnk00[4];
    hkAllocatorDC5E* m_pkHeap;
    hkAllocatorDC5E& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterDC5E* __cdecl FUN_00c85750() throw();


template <typename T> struct hkArrayDC5E
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void GrowArrayCapacity(hkAllocatorDC5E& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(FUN_00c85750()->heap(), n);
        m_iElementCount = n;
    }
};

class hkBinaryTagfileReaderDC5E
{
  public:
    void ReadBits(int iNumBits, hkArrayDC5E<char>& kBitsOut) throw();
};

// Reads iNumBits bits from the tagfile into kBitsOut, unpacking each byte least-significant bit first, then resizes the array to iNumBits.
// @fnv 0x00dc5e10
void hkBinaryTagfileReaderDC5E::ReadBits(int iNumBits, hkArrayDC5E<char>& kBitsOut) throw()
{
    int iNumBitsRounded = (iNumBits + 7) & ~7;
    int iNumBytes = iNumBitsRounded / 8;
    unsigned int auiBuf[16];
    kBitsOut.SetSizeAndGrow(iNumBitsRounded);
    reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(auiBuf, 1, iNumBytes);
    for (int i = 0; i < iNumBytes; i++)
    {
        unsigned int uiByte = ((unsigned char*)auiBuf)[i];
        for (int j = 0; j < 8; j++)
        {
            kBitsOut[i * 8 + j] = char(uiByte & 1);
            uiByte >>= 1;
        }
    }
    kBitsOut.SetSizeAndGrow(iNumBits);
}
}  // namespace fnv_00dc5e10


struct VirtualObject
{
    virtual void dummy0();
    virtual void dummy1();
    virtual void* vtable_8();
};

struct Struct3;

struct Field10Class
{
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void* vtable_0c(Struct3* s);
    virtual void dummy4();
    virtual void dummy5();
    virtual int* vtable_18(void* outVal);
    virtual void dummy7();
    virtual void dummy8();
    virtual void vtable_24(char* name);
};

struct Item
{
    char* m_name;
    int m_type;
    int m_extra;
    char* m_altName;
};

static __forceinline void callFree(hkMemoryRouterContext* ctx, void* p, unsigned int size)
{
    ctx->Free(p, size);
}

struct ItemArray
{
    Item* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease()
    {
        NineIntegerRecord* r = _D1A0E0GetMemoryRouter();
        hkMemoryRouterContext* ctx = r->m_p10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            callFree(ctx, m_data, (cap & 0x3fffffff) * 16);
        }
    }
};

struct Struct3
{
    char* m_str;
    int m_type;
    void* m_obj;
    ItemArray m_items;
};

template <class T> inline void constructWithCopy(T* destination, const T* source, int count)
{
    for (int i = 0; i < count; ++i)
        destination[i] = source[i];
}
template <class T> struct ObjectArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int index)
    {
        return m_data[index];
    }
};

struct TagFileReader
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Field10Class* m_p10;
    hkBinaryTagFileReaderVirtualObject* m_p14;
    ObjectArray<VirtualObject*> m_kTrackedObjects;
    ObjectArray<void*> m_objects24;
    ObjectArray<void*> m_objects30;
    Field10Class* getP10()
    {
        return m_p10;
    }
    int ReadTagFileEntry();
};

struct Locals
{
    void* outVal;
    Struct3 s;
};

struct ReaderDC5BD0
{
    int FUN_00dc5bd0();
};
// @fnv 0x00dc5d90
char* hkBinaryReaderDC5D::ReadString()
{
    int iLen = reinterpret_cast<::ReaderDC5BD0 *>(this)->FUN_00dc5bd0();
    if (iLen > 0)
    {
        char* pcString = AllocateWithHeader(&FUN_00c85750().heap(), iLen + 1);
        reinterpret_cast<::FUN_00dd90d0_cls *>(this)->FUN_00dd90d0((int)(pcString));
        pcString[iLen] = 0;
        m_pStringFunctions.AddBack(pcString);
        return pcString;
    }
    return m_pStringFunctions.m_data[-iLen];
}
// @fnv 0x00dc6c90
int TagFileReader::ReadTagFileEntry()
{
    Locals entry;

    entry.s.m_items.m_data = 0;
    entry.s.m_items.m_iElementCount = 0;
    entry.s.m_items.m_iCapacityState = 0x80000000;

    entry.s.m_str = reinterpret_cast<::hkBinaryReaderDC5D *>((this))->ReadString();
    entry.s.m_type = reinterpret_cast<::ReaderDC5BD0 *>((this))->FUN_00dc5bd0();

    if (!*getP10()->vtable_18(&entry.outVal))
    {
        entry.s.m_items.ClearAndRelease();
        return 1;
    }

    int iObjectIndex = reinterpret_cast<::ReaderDC5BD0 *>((this))->FUN_00dc5bd0();
    if (iObjectIndex >= 0 && m_kTrackedObjects[iObjectIndex])
    {
        entry.s.m_obj = m_kTrackedObjects[iObjectIndex]->vtable_8();
    }
    else
    {
        entry.s.m_obj = 0;
    }

    int iItemCount = reinterpret_cast<::ReaderDC5BD0 *>((this))->FUN_00dc5bd0();
    {
        NineIntegerRecord* r = _D1A0E0GetMemoryRouter();
        hkMemoryRouterContext* ctx = r->m_p10;
        int iNewCapacity = entry.s.m_items.m_iCapacityState & 0x3fffffff;
        if (iNewCapacity < iItemCount)
        {
            iNewCapacity += iNewCapacity;
            if (iItemCount >= iNewCapacity)
                iNewCapacity = iItemCount;
            ::FUN_00c908c0((::SpawnedObject *)(ctx), (::SpawnedArray *)(void *)(&entry.s.m_items), iNewCapacity, 16);
        }
    }

    entry.s.m_items.m_iElementCount = iItemCount;

    for (int i = 0; i < entry.s.m_items.m_iElementCount; ++i)
    {
        Item* item = &entry.s.m_items.m_data[i];
        item->m_name = reinterpret_cast<::hkBinaryReaderDC5D *>((this))->ReadString();
        item->m_type = reinterpret_cast<::ReaderDC5BD0 *>((this))->FUN_00dc5bd0();
        item->m_extra = (item->m_type & 0x20) ? reinterpret_cast<::ReaderDC5BD0 *>((this))->FUN_00dc5bd0() : 0;
        int lowType = item->m_type & 0xf;
        char* pAltName = (lowType == 9 || lowType == 8) ? reinterpret_cast<::hkBinaryReaderDC5D *>((this))->ReadString() : 0;
        item->m_altName = pAltName;
        if (pAltName)
        {
            getP10()->vtable_24(item->m_altName);
        }
    }

    void* pResult = getP10()->vtable_0c(&entry.s);
    {
        ObjectArray<VirtualObject*>* targetArr = &m_kTrackedObjects;
        NineIntegerRecord* r = _D1A0E0GetMemoryRouter();
        if (targetArr->m_iElementCount == (targetArr->m_iCapacityState & 0x3fffffff))
        {
            ::ResizeAudioStream((::AudioAllocator *)(r->m_p10), (::AudioStream *)(targetArr), 4);
        }
        VirtualObject* pStoredObject = static_cast<VirtualObject*>(pResult);
        constructWithCopy(targetArr->m_data + targetArr->m_iElementCount, &pStoredObject, 1);
        ++targetArr->m_iElementCount;
    }

    entry.s.m_items.ClearAndRelease();
    return 0;
}

__forceinline void ReadVarIntDC5BD0(ReaderDC5BD0& kReader, __int64& kValue)
{
    unsigned char ucByte;
    reinterpret_cast<::DD8FE0_Stream *>(&(kReader))->FUN_00dd8fe0(&ucByte, 1, 1);
    unsigned __int64 uiByte = (int)ucByte;
    unsigned __int64 uiValue = (uiByte & ~0x81) >> 1;
    int bNegative = (int)(uiByte & 1);
    int iShift = 6;
    while (uiByte & 0x80)
    {
        reinterpret_cast<::DD8FE0_Stream *>(&(kReader))->FUN_00dd8fe0(&ucByte, 1, 1);
        uiByte = (int)ucByte;
        uiValue |= (uiByte & ~0x80) << iShift;
        iShift += 7;
    }
    if (bNegative)
    {
        kValue = -(__int64)uiValue;
        return;
    }
    kValue = uiValue;
}

// Reads a variable-length integer from the reader and returns it as a 32-bit signed value.
// @fnv 0x00dc5bd0
int ReaderDC5BD0::FUN_00dc5bd0()
{
    __int64 iVarInt;
    ReadVarIntDC5BD0(*this, iVarInt);
    return (int)iVarInt;
}

struct ReaderDC5C80
{
    __int64 ReadVarInt();
};

// Reads a variable-length signed integer and returns the decoded value.
// @fnv 0x00dc5c80
__int64 ReaderDC5C80::ReadVarInt()
{
    unsigned char ucByte;
    reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&ucByte, 1, 1);
    unsigned __int64 uiByte = (int)ucByte;
    unsigned __int64 uiValue = (uiByte & ~0x81) >> 1;
    int bNegative = (int)(uiByte & 1);
    int iShift = 6;
    while (uiByte & 0x80)
    {
        reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&ucByte, 1, 1);
        uiByte = (int)ucByte;
        uiValue |= (uiByte & ~0x80) << iShift;
        iShift += 7;
    }
    if (bNegative)
        uiValue = -(__int64)uiValue;
    return uiValue;
}

struct FUN_00dc5d50_Local
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;

    void FUN_00dc5f30(unsigned int, unsigned int);
    void FUN_00dc6e50(unsigned int);
    void FreeAllBlocks();
};

// @fnv 0x00dc5d50
unsigned int FUN_00dc5d50(unsigned int a, unsigned int b, unsigned int c)
{
    FUN_00dc5d50_Local local;
    local.FUN_00dc5f30(b, c);
    local.FUN_00dc6e50(a);
    reinterpret_cast<::hkLargeBlockAllocator *>(&(local))->FreeAllBlocks();
    return a;
}


struct S00dc5f30_Tag
{
    unsigned char m_kPointB;
    S00dc5f30_Tag()
    {
        m_kPointB = 0;
    }
    S00dc5f30_Tag(const S00dc5f30_Tag& o)
    {
        m_kPointB = o.m_kPointB;
    }
};

struct S00dc5f30_HL
{
    void* m_p;
    unsigned int m_uiValueCount;
    unsigned int m_flags;
};

struct S00dc5f30_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_p10;
    int m_n14;
    S00dc5f30_HL m_hl18;
    S00dc5f30_HL m_hl24;
    S00dc5f30_HL m_hl30;


    S00dc5f30_Obj* FUN_00dc5f30(int a0, int a1);
};

// Initializes the object with a0 and a1, sets m_p10 and m_n14, and adds three entries to the m_hl18 and m_hl24 lists.
// @fnv 0x00dc5f30
S00dc5f30_Obj* S00dc5f30_Obj::FUN_00dc5f30(int a0, int a1)
{
    reinterpret_cast<::FUN_00dd9130_class *>(this)->Init((::hkReferencedObject *)(a0), (*(bool *)&(const ::S00dc5f30_Tag &)(S00dc5f30_Tag())));
    m_p10 = (void*)a1;
    m_n14 = 0;
    S00dc5f30_HL* pFirstList = &m_hl18;
    S00dc5f30_HL* pSecondList = &m_hl24;
    pFirstList->m_p = 0;
    pFirstList->m_uiValueCount = 0;
    pFirstList->m_flags = 0x80000000;
    pSecondList->m_p = 0;
    pSecondList->m_uiValueCount = 0;
    pSecondList->m_flags = 0x80000000;
    m_hl30.m_p = 0;
    m_hl30.m_uiValueCount = 0;
    m_hl30.m_flags = 0x80000000;

    hkMemoryRouterDC5D& r = FUN_00c85750();
    if (pFirstList->m_uiValueCount == (pFirstList->m_flags & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(r.m_pStreamAllocator), (::AudioStream *)(pFirstList), 4);
    }
    void** pSlot = (void**)pFirstList->m_p + pFirstList->m_uiValueCount;
    __assume(pSlot != 0);
    new (pSlot) void * (0);
    ++pFirstList->m_uiValueCount;

    hkMemoryRouterDC5D& r2 = FUN_00c85750();
    if (pSecondList->m_uiValueCount == (pSecondList->m_flags & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(r2.m_pStreamAllocator), (::AudioStream *)(pSecondList), 4);
    }
    void** pSlot2 = (void**)pSecondList->m_p + pSecondList->m_uiValueCount;
    __assume(pSlot2 != 0);
    new (pSlot2) void*(&(*reinterpret_cast<char *>((void *)&::DAT_01011584)));
    pSecondList->m_uiValueCount += 1;

    hkMemoryRouterDC5D& r3 = FUN_00c85750();
    if (pSecondList->m_uiValueCount == (pSecondList->m_flags & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(r3.m_pStreamAllocator), (::AudioStream *)(pSecondList), 4);
    }
    void** pSlot3 = (void**)pSecondList->m_p + pSecondList->m_uiValueCount;
    __assume(pSlot3 != 0);
    new (pSlot3) void * (0);
    pSecondList->m_uiValueCount += 1;

    return this;
}

class hkMemoryAllocatorDC5D
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
template <typename T> __forceinline void ConstructTF(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        ::new (static_cast<void*>(p + i)) T();
}
template <typename T> __forceinline void ConstructWithCopyTF(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}
template <typename T> struct hkArrayTF
{
    hkArrayTF() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline void clearStorage()
    {
        hkMemoryAllocatorDC5D& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
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
        hkMemoryAllocatorDC5D& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        ConstructWithCopyTF(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void setSizeUnchecked(int n)
    {
        ConstructTF(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> struct hkLocalArrayTF : public hkArrayTF<T>
{
    __forceinline hkLocalArrayTF(int n)
    {
        hkMemoryRouterDC5D& kRouter = FUN_00c85750();
        T* pLocal = (T*)kRouter.m_00;
        kRouter.m_00 = (int)((char*)pLocal + ((n * sizeof(T) + 0x7f) & ~0x7f));
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline void clearLocal()
    {
        T* pLocal = m_pStackAllocation;
        if (pLocal == this->m_data)
            this->m_iElementCount = 0;
        FUN_00c85750().m_00 = (int)pLocal;
    }
    T* m_pStackAllocation;
};
class hkOstreamTF
{
  public:
    hkOstreamTF(void* pvBuffer, int iSize)
    {
        new ((void *)this) ::FUN_00cb1600(pvBuffer, iSize);
    }
    void close()
    {
        reinterpret_cast<struct ::FUN_00cc00e0 *>(this)->FUN_00cc00e0::~FUN_00cc00e0();
    }
    hkOstreamTF& operator<<(const char* pcString)
    {
        return (*(::hkOstreamTF *)(reinterpret_cast<::SinkOwner *>(this)->FUN_00cc01c0(pcString)));
    }
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};
class hkErrorTF
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int eType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine);
};
struct hkDataClassImplTF;
struct hkDataObjectImplTF;
struct MemberInfoTF
{
    MemberInfoTF() : m_name(0), m_pClassName(0), m_type(0), m_valuePtr(0), m_extra(0)
    {}
    const char* m_name;
    const char* m_pClassName;
    int m_type;
    void* m_valuePtr;
    int m_extra;
};
class hkDataClassTF
{
  public:
    hkDataClassTF(hkDataClassImplTF* pkImpl)
    {
        reinterpret_cast<::FUN_00dba650_cls *>(this)->FUN_00dba650((unsigned int)(pkImpl));
    }
    void close()
    {
        ::FUN_00dba660();
    }
    int FUN_00dba730() const;
    hkDataClassImplTF* m_pClassImpl;
};
struct ValueRawTF
{
    hkDataObjectImplTF* m_pClassImpl;
    void* m_handle;
};
struct ValueTF
{
    ValueTF(const ValueRawTF& r)
    {
        m_handle = r.m_handle;
        m_pClassImpl = r.m_pClassImpl;
    }
    hkDataObjectImplTF* m_pClassImpl;
    void* m_handle;
};
class hkDataObjectTF
{
  public:
    hkDataObjectTF(hkDataObjectImplTF* pkImpl)
    {
        reinterpret_cast<::DataObjectHandle *>(this)->FUN_00dba760((::RefObj *)(pkImpl));
    }
    hkDataObjectTF(const hkDataObjectTF& kOther)
    {
        reinterpret_cast<::FUN_00dba780_cls *>(this)->AssignRef((::FUN_00dba780_cls *)&(kOther));
    }
    __forceinline hkDataObjectTF(hkDataObjectTF& other, hkLocalArrayTF<MemberInfoTF>& members,
                                 hkLocalArrayTF<bool>& used, hkDataClassTF& pClassInfo)
    {
        reinterpret_cast<::FUN_00dba780_cls *>(this)->AssignRef((::FUN_00dba780_cls *)&(other));
        members.clearLocal();
        members.clearStorage();
        used.clearLocal();
        used.clearStorage();
        other.close();
        pClassInfo.close();
    }
    void close()
    {
        reinterpret_cast<::DBA7F0Ref *>(this)->FUN_00dba7f0();
    }
    ValueTF operator[](const char* pcName)
    {
        ValueRawTF raw;
        return *((::ValueRawTF *)(reinterpret_cast<::FUN_00dba870_cls *>(this)->FUN_00dba870(&raw, (void *)(pcName))));
    }
    hkDataObjectImplTF* getImplementation() const
    {
        return m_pClassImpl;
    }
    hkDataObjectImplTF* m_pClassImpl;
};
class hkDataWorldTF
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual hkDataObjectImplTF* GetObject(const hkDataClassTF& kClass);
};
class hkBinaryTagfileReaderTF
{
  public:
    int ReadTag()
    {
        return reinterpret_cast<::ReaderDC5BD0 *>((this))->FUN_00dc5bd0();
    }
    hkDataObjectTF FUN_00dc6970(int aiAllocationTag);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkDataWorldTF* m_pOwningWorld;
    int unk14;
    hkArrayTF<hkDataClassImplTF*> m_kLookupMap;
    int unk24;
    int unk28;
    int unk2C;
    hkArrayTF<hkDataObjectImplTF*> m_remembered;
};
struct TagAllocator
{
    virtual void unused00();
    virtual void unused04();
    virtual void unused08();
    virtual void* allocate(int& bytes);
    virtual void freeBlock(void* block, int bytes);
};
struct TagRouter
{
    char* stackTop;
    void* stackEnd;
    void* stackBlock;
    TagAllocator* temporary;
    TagAllocator* heap;
};
__forceinline TagRouter* getTagRouter()
{
    return reinterpret_cast<TagRouter*>(&FUN_00c85750());
}
template <class T> struct TagArray
{
    T* data;
    int size;
    int capacity;
    __forceinline TagArray() : data(0), size(0), capacity(0x80000000)
    {}
    static __forceinline T* allocateNonzero(TagAllocator* a, int& count)
    {
        int bytes = count * sizeof(T);
        T* p = static_cast<T*>(a->allocate(bytes));
        count = bytes / int(sizeof(T));
        return p;
    }
    static __forceinline T* allocateChunk(TagAllocator* a, int& count)
    {
        return count ? allocateNonzero(a, count) : 0;
    }
    __forceinline TagArray(int count) : data(0), size(0), capacity(0x80000000)
    {
        T* p = allocateChunk(getTagRouter()->temporary, count);
        int flags = count ? count : 0x80000000;
        data = p;
        size = count;
        capacity = flags;
    }
    __forceinline void reserve(TagAllocator* a, int count)
    {
        int current = capacity & 0x3fffffff;
        if (current < count)
        {
            int grown = current * 2;
            ::FUN_00c908c0((::SpawnedObject *)(a), (::SpawnedArray *)(void *)(this), count >= grown ? count : grown, sizeof(T));
        }
    }
    __forceinline void release(TagAllocator* a)
    {
        size = 0;
        if (!(capacity & 0x80000000))
            a->freeBlock(data, (capacity & 0x3fffffff) * sizeof(T));
    }
};
template <class T> struct TagLocalArray : TagArray<T>
{
    T* original;
    __forceinline void allocateLocal(int count)
    {
        TagRouter* router = getTagRouter();
        T* p = reinterpret_cast<T*>(router->stackTop);
        router->stackTop += (count * sizeof(T) + 127) & ~127;
        data = p;
        original = p;
        capacity = count | 0x80000000;
    }
    __forceinline void releaseLocal()
    {
        T* p = original;
        if (p == data)
            size = 0;
        getTagRouter()->stackTop = reinterpret_cast<char*>(p);
        release(getTagRouter()->heap);
        data = 0;
        capacity = 0x80000000;
    }
};
struct TagArrayValue;
struct TagClass;
struct TagString
{
    void* object;
    __forceinline ~TagString() throw()
    {
        reinterpret_cast<::DBA7F0Ref *>(this)->FUN_00dba7f0();
    }
};
struct TagArrayRef
{
    void* object;
    int FUN_00dbac10();
    TagArrayValue FUN_00dbab90(int) throw();
    TagClass FUN_00dbac20();
};
struct TagArrayValue
{
    void* array;
    int index;
    TagArrayRef FUN_00dbacd0();
};
struct TagMember
{
    const char* name;
    void* type;
    void* pClassInfo;
    int flags;
    int tupleSize;
    __forceinline TagMember() : name(0), type(0), pClassInfo(0), flags(0), tupleSize(0)
    {}
};
struct TagClass
{
    void* object;
    int FUN_00dba730();
};
struct TagReader
{
    TagString FUN_00dc6970(int) throw();
    void FUN_00dc6100(TagArrayRef*, int);
};
// Reads an array of 'count' elements from the tag stream into the given TagArrayRef, dispatching on the element type code.
// @fnv 0x00dc6100
void TagReader::FUN_00dc6100(TagArrayRef* array, int count)
{
    switch (array->FUN_00dbac10())
    {
    case 1: {
        TagArray<char> values(count);
        values.reserve(getTagRouter()->temporary, count);
        reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(values.data, 1, count);
        reinterpret_cast<::fnv_00dbae10::Outer *>((array))->FUN_00dbae10((int)(values.data));
        values.release(getTagRouter()->temporary);
        break;
    }
    case 2:
        for (int i = 0; i < count; ++i)
            reinterpret_cast<::fnv_00dbada0::Wrapper *>((void *)&(const ::TagArrayValue &)(array->FUN_00dbab90(i)))->InvokeOnInterface(reinterpret_cast<::ReaderDC5BD0 *>(this)->FUN_00dc5bd0());
        break;
    case 3: {
        TagArray<float> values(count);
        values.reserve(getTagRouter()->temporary, count);
        values.size = count;
        reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(values.data, 4, count);
        reinterpret_cast<::FUN_00dbae80_cls *>((array))->FUN_00dbae80((void *)(values.data), (void *)(values.size));
        values.release(getTagRouter()->temporary);
        break;
    }
    case 4: {
        int width = reinterpret_cast<::ReaderDC5BD0 *>(this)->FUN_00dc5bd0();
        float values[4] = {0, 0, 0, 0};
        for (int i = 0; i < count; ++i)
        {
            reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(values, 4, width);
            reinterpret_cast<::FUN_00dbad60_cls *>((void *)&(const ::TagArrayValue &)(array->FUN_00dbab90(i)))->FUN_00dbad60((int)(values), 4);
        }
        break;
    }
    case 6:
    case 7: {
        int width = 4 * (array->FUN_00dbac10() - 3);
        for (int i = 0; i < count; ++i)
        {
            float values[16];
            for (int j = 0; j < width; ++j)
            {
                float value;
                reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&value, 4, 1);
                values[j] = value;
            }
            reinterpret_cast<::FUN_00dbad60_cls *>((void *)&(const ::TagArrayValue &)(array->FUN_00dbab90(i)))->FUN_00dbad60((int)(values), width);
        }
        break;
    }
    case 8:
        for (int i = 0; i < count; ++i)
        {
            reinterpret_cast<::FUN_00dbad00_cls *>((void *)&(const ::TagArrayValue &)(array->FUN_00dbab90(i)))->FUN_00dbad00((int *)&(const ::TagString &)(FUN_00dc6970(-1)));
        }
        break;
    case 10:
        for (int i = 0; i < count; ++i)
            reinterpret_cast<::DBADC0Binding *>((void *)&(const ::TagArrayValue &)(array->FUN_00dbab90(i)))->FUN_00dbadc0((void *)(reinterpret_cast<::hkBinaryReaderDC5D *>(this)->ReadString()));
        break;
    case 9: {
        reinterpret_cast<::DBABE0Binding *>((array))->FUN_00dbabe0((void *)(count));
        TagClass pClassInfo = array->FUN_00dbac20();
        int membersCount = pClassInfo.FUN_00dba730();
        TagLocalArray<char> presentBits;
        presentBits.allocateLocal(128);
        reinterpret_cast<::fnv_00dc5e10::hkBinaryTagfileReaderDC5E *>(this)->ReadBits(membersCount, (::fnv_00dc5e10::hkArrayDC5E<char> &)(presentBits));
        TagLocalArray<TagMember> members;
        members.allocateLocal(membersCount);
        int toConstruct = membersCount - members.size;
        TagMember* first = members.data + members.size;
        for (int k = 0; k < toConstruct; ++k)
            new (first + k) TagMember;
        members.size = membersCount;
        reinterpret_cast<::S_00dbaed0_Obj *>(&(pClassInfo))->DispatchItems((::S_00dbaed0_Elem **)&(members));
        int i = 0;
        if (membersCount > 0)
        {
            int byteOffset = 0;
            do
            {
                TagMember& member = *reinterpret_cast<TagMember*>(reinterpret_cast<char*>(members.data) + byteOffset);
                if (presentBits.data[i])
                {
                    TagArrayRef field = (*(::TagArrayRef *)(reinterpret_cast<::FUN_00dbaea0_cls *>((array))->InvokeCallbackInto((::FUN_00dbab50_cls *)(member.name), {})));
                    if (!member.tupleSize)
                    {
                        FUN_00dc6100(&field, count);
                    }
                    else
                    {
                        for (int j = 0; j < count; ++j)
                        {
                            TagArrayRef item = field.FUN_00dbab90(j).FUN_00dbacd0();
                            FUN_00dc6100(&item, member.tupleSize);
                            reinterpret_cast<::FUN_00dbab70_cls *>(&(item))->FUN_00dbab70();
                        }
                    }
                    reinterpret_cast<::FUN_00dbab70_cls *>(&(field))->FUN_00dbab70();
                }
                ++i;
                byteOffset += sizeof(TagMember);
            } while (i < membersCount);
        }
        members.releaseLocal();
        presentBits.releaseLocal();
        ::FUN_00dba660();
        break;
    }
    }
}

struct Item20
{
    void* name;
    int subtype;
    int flags;
    void* objectClass;
    int tupleSize;
};
struct RefA
{
    void* object;
};
struct RefB
{
    void* object;
};
struct ParamP
{
    void* object;
    int member;
};
struct ValueWorld
{
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void* vtable_0c(Struct3*);
    virtual void dummy4();
    virtual void* vtable_14(RefA*, const Item20*);
    virtual int* vtable_18(void*);
    virtual void dummy7();
    virtual void dummy8();
    virtual void vtable_24(char*);
};
struct ValueReader : TagFileReader
{
    void FUN_00dc6720(ParamP, const Item20*);
};
// Reads a data object from the binary tagfile stream, resolves its class and members, reads present values, and returns the object.
// @fnv 0x00dc6970
hkDataObjectTF hkBinaryTagfileReaderTF::FUN_00dc6970(int aiAllocationTag)
{
    int iTagType = aiAllocationTag;
    if (iTagType == -1)
        iTagType = ReadTag();
    if (iTagType == 5)
        return hkDataObjectTF(m_remembered[ReadTag()]);
    if (iTagType == 6)
        return hkDataObjectTF(0);
    hkDataClassTF kClass(m_kLookupMap[ReadTag()]);
    int iNumMembers = kClass.FUN_00dba730();
    hkDataObjectTF kObj(m_pOwningWorld->GetObject(kClass));
    switch (iTagType)
    {
    case 4:
        m_remembered.AddBack(kObj.getImplementation());
        break;
    case 3:
        break;
    default: {
        unsigned int auiBuf[128];
        hkOstreamTF kOstr(auiBuf, sizeof(auiBuf));
        kOstr << "corrupt file";
        if ((*reinterpret_cast<::hkErrorTF * *>(&::DAT_01268360))->message(3, 0x484994d5, (const char*)auiBuf, ".\\Tagfile\\Binary\\hkBinaryTagfileReader.cpp",
                                  376))
            __debugbreak();
        kOstr.close();
        break;
    }
    }
    hkLocalArrayTF<bool> kUsedMembers(128);
    reinterpret_cast<::fnv_00dc5e10::hkBinaryTagfileReaderDC5E *>(this)->ReadBits(iNumMembers, (::fnv_00dc5e10::hkArrayDC5E<char> &)(kUsedMembers));
    hkLocalArrayTF<MemberInfoTF> kMembers(iNumMembers);
    kMembers.setSizeUnchecked(iNumMembers);
    reinterpret_cast<::S_00dbaed0_Obj *>((void *)&(kClass))->DispatchItems((::S_00dbaed0_Elem **)&(kMembers));
    for (int i = 0; i < iNumMembers; ++i)
    {
        const MemberInfoTF& kInfo = kMembers[i];
        if (kUsedMembers[i])
        {
            ValueRawTF raw;
            ValueRawTF* r = ((::ValueRawTF *)(reinterpret_cast<::FUN_00dba870_cls *>(&(kObj))->FUN_00dba870(&raw, (void *)(kInfo.m_name))));
            reinterpret_cast<::ValueReader *>(this)->FUN_00dc6720((::ParamP)(r->m_pClassImpl), (const ::Item20 *)(r->m_handle));
        }
    }
    return hkDataObjectTF(kObj, kMembers, kUsedMembers, kClass);
}
// Reads a typed value from the tag file stream into ParamP based on Item20 flags, handling scalars, vectors, objects, and references.
// @fnv 0x00dc6720
void ValueReader::FUN_00dc6720(ParamP value, const Item20* item)
{
    RefA owner;
    if (item->flags & 0x20)
    {
        reinterpret_cast<::DataObjectHandle *>(&(owner))->FUN_00dba760((::RefObj *)(value.object));
        void* created = reinterpret_cast<ValueWorld*>(m_p10)->vtable_14(&owner, item);
        RefB reference;
        new ((void *)&(reference)) ::FUN_00dbab50((::DBAB50Object *)(created));
        reinterpret_cast<::TagReader *>(this)->FUN_00dc6100((::TagArrayRef *)(::RefB *)(&reference), item->tupleSize);
        reinterpret_cast<::FUN_00dbab70_cls *>(&(reference))->FUN_00dbab70();
        reinterpret_cast<::DBA7F0Ref *>(&(owner))->FUN_00dba7f0();
        return;
    }
    if (item->flags & 0x10)
    {
        Item20 local;
        memcpy(&local, item, sizeof(local));
        int index = reinterpret_cast<::ReaderDC5BD0 *>((this))->FUN_00dc5bd0();
        if (reinterpret_cast<::fnv_00dba920::Target *>(&(value))->QueryAndWriteResult() == 0x19 && item->objectClass == 0)
        {
            int objectIndex = reinterpret_cast<::ReaderDC5BD0 *>((this))->FUN_00dc5bd0();
            local.objectClass = m_kTrackedObjects.m_data[objectIndex];
        }
        reinterpret_cast<::DataObjectHandle *>(&(owner))->FUN_00dba760((::RefObj *)(value.object));
        void* created = reinterpret_cast<ValueWorld*>(m_p10)->vtable_14(&owner, &local);
        RefB reference;
        new ((void *)&(reference)) ::FUN_00dbab50((::DBAB50Object *)(created));
        reinterpret_cast<::DBABE0Binding *>(&(reference))->FUN_00dbabe0((void *)(index));
        reinterpret_cast<::TagReader *>(this)->FUN_00dc6100((::TagArrayRef *)(::RefB *)(&reference), index);
        reinterpret_cast<::FUN_00dbab70_cls *>(&(reference))->FUN_00dbab70();
        reinterpret_cast<::DBA7F0Ref *>(&(owner))->FUN_00dba7f0();
        return;
    }
    switch (item->flags)
    {
    case 1: {
        unsigned char scalar;
        reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&scalar, 1, 1);
        reinterpret_cast<::FUN_00dbaa30_cls *>(&(value))->FUN_00dbaa30(scalar);
        break;
    }
    case 2: {
        unsigned __int64 scalar = ((unsigned long long)(reinterpret_cast<::ReaderDC5C80 *>((this))->ReadVarInt()));
        reinterpret_cast<::FUN_00dbaa90_cls *>(&(value))->FUN_00dbaa90((int)scalar, (int)(scalar >> 32));
        break;
    }
    case 3: {
        float scalar = ::FUN_00dc5bb0();
        reinterpret_cast<::FUN_00dbaab0_cls *>(&(value))->DispatchFloatToVtbl(scalar);
        break;
    }
    case 4:
    case 6:
    case 7: {
        float values[16];
        float scalar;
        int count = item->flags * 4 - 12;
        for (int i = 0; i < count; ++i)
        {
            reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&scalar, 4, 1);
            values[i] = scalar;
        }
        reinterpret_cast<::AudioHandle *>(&(value))->FUN_00dbab10((unsigned int)(values), count);
        break;
    }
    case 8:
    case 9: {
        RefA object;
        reinterpret_cast<::hkBinaryTagfileReaderTF *>(this)->FUN_00dc6970((int)(&object));
        reinterpret_cast<::FUN_00dbaa50_cls *>(&(value))->DispatchToObject((void **)(::RefA *)(&object));
        reinterpret_cast<::DBA7F0Ref *>(&(object))->FUN_00dba7f0();
        break;
    }
    case 10:
        reinterpret_cast<::S_00dbab30_Ref *>(&(value))->FUN_00dbab30((int)(reinterpret_cast<::hkBinaryReaderDC5D *>((this))->ReadString()));
        break;
    default:
        break;
    }
}


struct hkDataObjectImpl;

struct DataObjectImplReference
{
    hkDataObjectImpl* m_pClassImpl;
    DataObjectImplReference(hkDataObjectImpl* impl);
};

struct hkOstream
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;
    hkOstream(void* buf, int bufSize);
    ~hkOstream();
    hkOstream& operator<<(const char* s);
};

struct hkError
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int message(int type, int id, const char* desc, const char* file, int line);
};


struct hkBinaryTagfileReader
{
    DataObjectImplReference readObjectTopLevel(int tag);

    DataObjectImplReference FUN_00dc6e50();
};

// @fnv 0x00dc6e50
DataObjectImplReference hkBinaryTagfileReader::FUN_00dc6e50()
{
    char buf[512];
    int magic0;
    reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&magic0, 4, 1);
    int magic1;
    reinterpret_cast<::DD8FE0_Stream *>(this)->FUN_00dd8fe0(&magic1, 4, 1);
    if (magic0 == 0xcab00d1e && magic1 == 0xd011face)
    {
        for (int tag = reinterpret_cast<::ReaderDC5BD0 *>(this)->FUN_00dc5bd0(); tag != -1; tag = reinterpret_cast<::ReaderDC5BD0 *>(this)->FUN_00dc5bd0())
        {
            switch (tag)
            {
            case 1: {
                if (reinterpret_cast<::ReaderDC5BD0 *>(this)->FUN_00dc5bd0() != 0)
                {
                    {
                        hkOstream ostr(buf, sizeof(buf));
                        reinterpret_cast<::SinkOwner *>((void *)&(const ::hkOstream &)(ostr))->FUN_00cc01c0("Unrecognised tagfile version.");
                        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0x2ab6036f, buf, ".\\Tagfile\\Binary\\hkBinaryTagfileReader.cpp",
                                              0x1d9);
                    }
                    return DataObjectImplReference(0);
                }
                break;
            }
            case 2: {
                if (reinterpret_cast<::TagFileReader *>(this)->ReadTagFileEntry() == 1)
                {
                    return DataObjectImplReference(0);
                }
                break;
            }
            case 3:
            case 4:
            case 6: {
                return readObjectTopLevel(tag);
            }
            default: {
                return DataObjectImplReference(0);
            }
            }
        }
    }
    else
    {
        hkOstream ostr(buf, sizeof(buf));
        reinterpret_cast<::SinkOwner *>((void *)&(const ::hkOstream &)(ostr))->FUN_00cc01c0("This does not look like a binary tagfile (magic number mismatch)");
        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0x2ab6036f, buf, ".\\Tagfile\\Binary\\hkBinaryTagfileReader.cpp", 0x1c5);
    }
    return DataObjectImplReference(0);
}
