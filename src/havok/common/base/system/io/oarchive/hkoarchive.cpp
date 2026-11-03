
// src/havok/common/base/system/io/oarchive/hkoarchive.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/oarchive/hkoarchive.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/CB1BC0Map.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/MapCB1C.h"
#include "fnv/decl/fnv_00dbe710__S_00dbe710.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_010d1000.h"
struct hkReferencedObject
{
};

struct FUN_00d60810
{
    int m_iWordAt00;
    int m_iWordAt04;
    hkReferencedObject* m_8;
    void AssignReferencedObject(hkReferencedObject* p);
};

// @fnv 0x00d60810
void FUN_00d60810::AssignReferencedObject(hkReferencedObject* apObject)
{
    reinterpret_cast<::FUN_00c90510_class *>((apObject))->FUN_00c90510();
    reinterpret_cast<::hkReferencedObjectC905 *>((m_8))->FUN_00c905b0();
    m_8 = apObject;
}

extern "C" unsigned int WriteSwapped(void*, int, int);

// @fnv 0x00d609c0
unsigned int HashUInt(uintptr_t auiValue)
{
    return WriteSwapped(&auiValue, 4, 1);
}

struct hkOArchive
{
    void FUN_00d609e0(int n, int m);
};
struct FUN_00d60a20_class
{
    void FUN_00d60a20(const void* data, unsigned int size);
};

struct FUN_00d60600_class
{
};

struct FUN_00d60a60_class : public FUN_00d60600_class
{
    void FUN_00d60a60(intptr_t a, int b);
};

struct FUN_00d60a80_class
{
    void FUN_00d60a80(const void* p, unsigned int count);
};

struct FUN_00d60aa0_class
{
    void FUN_00d60aa0(const void* data, int count);
};

namespace fnv_00d60ac0 {
struct hkOArchive
{
    void WriteSwapped(const void* data, unsigned int size, unsigned int elementCount);
    void WriteArray(const void* data, unsigned int elementCount);
};
// @fnv 0x00d60ac0
void hkOArchive::WriteArray(const void* data, unsigned int elementCount)
{
    WriteSwapped(data, 8, elementCount);
}
}  // namespace fnv_00d60ac0

struct FUN_00d60ae0_Class
{
    void FUN_00d60ae0(intptr_t a, int b);
};
struct hkOArchive_2
{
    void WriteInt(intptr_t val);
};
// @fnv 0x00d60960
void FUN_00d60960(const float* p)
{
    WriteSwapped((void*)&p, 4, 1);
}

struct FUN_00d60980_class : public hkOArchive
{
    void FUN_00d60980(int a, int b);
};

struct FUN_00d609a0_Class
{
    void FUN_00d609a0(intptr_t value, int other);
};

struct FUN_00d605b0_writer
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void write(const void* data, int size) = 0;
};

struct FUN_00d605b0_class
{
    void FUN_00d605b0(unsigned char value);
};

// @fnv 0x00d605b0
void FUN_00d605b0_class::FUN_00d605b0(unsigned char value)
{
    FUN_00d605b0_writer* writer = *reinterpret_cast<FUN_00d605b0_writer**>(reinterpret_cast<char*>(this) + 8);
    writer->write(&value, 1);
}

struct FUN_00d605d0_impl
{
    virtual void FUN_00d605d0_a();
    virtual void FUN_00d605d0_b();
    virtual void FUN_00d605d0_c();
    virtual void FUN_00d605d0_d();
    virtual void write(const void* data, unsigned int size);
};

struct FUN_00d605d0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00d605d0(unsigned char value);
};

// @fnv 0x00d605d0
void FUN_00d605d0_class::FUN_00d605d0(unsigned char value)
{
    reinterpret_cast<FUN_00d605d0_impl*>(m_8)->write(&value, 1);
}

struct FUN_00d607e0_object
{
    virtual void FUN_00d607e0_virtual0();
    virtual void FUN_00d607e0_virtual1();
    virtual void FUN_00d607e0_virtual2();
    virtual void FUN_00d607e0_virtual3(intptr_t value);
};

struct FUN_00d607e0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    FUN_00d607e0_object* m_8;

    intptr_t ForwardValueToObject(intptr_t value);
};

// @fnv 0x00d607e0
intptr_t FUN_00d607e0_class::ForwardValueToObject(intptr_t value)
{
    m_8->FUN_00d607e0_virtual3(value);
    return value;
}


struct FUN_00d60830
{
    int m_iWordAt00;
    short m_iWordAt04;
    short m_6;
    hkReferencedObject* m_8;
    char m_iThirdValue;
    FUN_00d60830(hkReferencedObject* p, char b);
};

// @fnv 0x00d60830
FUN_00d60830::FUN_00d60830(hkReferencedObject* apObject, char b)
{
    m_6 = 1;
    *(int*)this = (intptr_t)&DAT_010d14f8;
    m_8 = apObject;
    m_iThirdValue = b;
    reinterpret_cast<::FUN_00c90510_class *>((apObject))->FUN_00c90510();
}

struct FUN_00d60a00_class : public hkOArchive
{
    void WriteData(const void* data, unsigned int size);
};

struct FUN_00d60a40_class : public hkOArchive
{
    void FUN_00d60a40(intptr_t a, int b);
};
struct FUN_00d60b00_class
{
    void WriteFloatArray(const float* data, unsigned int count);
};

// Swaps the two bytes stored at the given addresses.
// @fnv 0x00d605f0
static void FUN_00d605f0(unsigned char* pFirst, unsigned char* pSecond)
{
    unsigned char t = *pFirst;
    *pFirst = *pSecond;
    *pSecond = t;
}

// Keeps the helper referenced so the compiler emits its out-of-line body.
void swapBytesCaller(unsigned char* pLeft, unsigned char* pRight)
{
    FUN_00d605f0(pLeft, pRight);
}

struct hkStub
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10(intptr_t a);
};
struct FUN_00d607b0_class
{
    int unk00;
    int unk04;
    hkStub* unk08;
    void FUN_00d607b0(intptr_t a);
};
// @fnv 0x00d607b0
void FUN_00d607b0_class::FUN_00d607b0(intptr_t a)
{
    unk08->vf10(a);
}

struct S_00d607c0
{
    int unk0;
    int unk4;
    int unk8;
    char unkC;
    void FUN_00d607c0(char v);
};
// @fnv 0x00d607c0
void S_00d607c0::FUN_00d607c0(char v)
{
    unkC = v;
}


struct ObjectWriter
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void write(const void* data, int size) = 0;
};

struct Archive
{
    void* vtable;
    int unk04;
    ObjectWriter* m_pStreamWriter;
    char m_byteswap;

    void WriteSwapped(const void* data, int elementSize, int count);
};
// @fnv 0x00d609e0
void hkOArchive::FUN_00d609e0(int n, int m)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped(&n, 8, 1);
}
// @fnv 0x00d60a20
void FUN_00d60a20_class::FUN_00d60a20(const void* data, unsigned int size)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped(data, 1, size);
}
// @fnv 0x00d60a60
void FUN_00d60a60_class::FUN_00d60a60(intptr_t aiFirst, int aiSecond)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped((const void *)(aiFirst), 2, aiSecond);
}
// @fnv 0x00d60a80
void FUN_00d60a80_class::FUN_00d60a80(const void* apData, unsigned int count)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped(apData, 4, count);
}
// @fnv 0x00d60aa0
void FUN_00d60aa0_class::FUN_00d60aa0(const void* data, int count)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped(data, 4, count);
}
// @fnv 0x00d60ae0
void FUN_00d60ae0_Class::FUN_00d60ae0(intptr_t a, int b)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped((void*)a, 8, b);
}
// @fnv 0x00d60940
void hkOArchive_2::WriteInt(intptr_t aiValue)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped(&aiValue, 4, 1);
}
// @fnv 0x00d60980
void FUN_00d60980_class::FUN_00d60980(int aiValue, int aiUnused)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped(&aiValue, 8, 1);
}
// @fnv 0x00d609a0
void FUN_00d609a0_Class::FUN_00d609a0(intptr_t value, int)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped(&value, 8, 1);
}
// @fnv 0x00d60a00
void FUN_00d60a00_class::WriteData(const void* data, unsigned int size)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped((void*)data, 1, size);
}
// @fnv 0x00d60a40
void FUN_00d60a40_class::FUN_00d60a40(intptr_t apData, int b)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped((void*)apData, 2, b);
}
// @fnv 0x00d60b00
void FUN_00d60b00_class::WriteFloatArray(const float* data, unsigned int count)
{
    reinterpret_cast<::Archive *>((((hkOArchive*)this)))->WriteSwapped((void*)data, 4, (int)count);
}

inline void swapBytes(unsigned char& a, unsigned char& b)
{
    unsigned char t = a;
    a = b;
    b = t;
}

// @fnv 0x00d60600
void Archive::WriteSwapped(const void* data, int elementSize, int count)
{
    if (!m_byteswap)
    {
        m_pStreamWriter->write(data, elementSize * count);
        return;
    }

    int aiBuffer[128];
    int chunkSize = 512;
    int numInBlock = chunkSize / elementSize;
    const char* cur = (const char*)data;
    int totalBytes = elementSize * count;
    int remBytes = totalBytes % 512;
    int remCount = remBytes / elementSize;

    while (totalBytes > 0)
    {
        if (totalBytes < 512)
        {
            numInBlock = remCount;
            chunkSize = remBytes;
        }

        ::FUN_00cb1260(aiBuffer, cur, chunkSize);

        switch (elementSize)
        {
        case 2: {
            unsigned char* p = (unsigned char*)aiBuffer;
            for (int iIndex = 0; iIndex < numInBlock; ++iIndex)
            {
                swapBytes(p[0], p[1]);
                p += 2;
            }
        }
        break;
        case 4: {
            unsigned char* p = (unsigned char*)aiBuffer;
            for (int iIndex = 0; iIndex < numInBlock; ++iIndex)
            {
                swapBytes(p[0], p[3]);
                swapBytes(p[1], p[2]);
                p += 4;
            }
        }
        break;
        case 8: {
            unsigned char* p = (unsigned char*)aiBuffer;
            for (int iIndex = 0; iIndex < numInBlock; ++iIndex)
            {
                swapBytes(p[0], p[7]);
                swapBytes(p[1], p[6]);
                swapBytes(p[2], p[5]);
                swapBytes(p[3], p[4]);
                p += 8;
            }
        }
        break;
        }

        m_pStreamWriter->write(aiBuffer, chunkSize);
        cur += chunkSize;
        totalBytes -= chunkSize;
    }
}

struct FnvCpu_FUN_00d607d0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    unsigned char* FUN_00d607d0(unsigned char* output);
};
// @fnv 0x00d607d0
unsigned char* FnvCpu_FUN_00d607d0_CpuObject::FUN_00d607d0(unsigned char* output)
{
    *output = value;
    return output;
}

struct FUN_00d60800_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* FUN_00d60800();
};
// @fnv 0x00d60800
void* FUN_00d60800_class::FUN_00d60800()
{
    return m_8;
}

class hkMemoryAllocatorDBA;

struct hkMemoryRouterDBA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBA* m_pStreamAllocator;
    hkMemoryAllocatorDBA& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterDBA* __cdecl FUN_00c85750();

class hkMap64DBA
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

};

struct EntryDBA
{
    int m_uiFilterValue;
    int m_next;
};

class ListMapDBA
{
  public:
    EntryDBA* m_entries;
    int m_iNumberOfEntries;
    int m_pRayCursor;
    hkMap64DBA m_map;

    void Insert(unsigned __int64 key, const int& value);
};

// Allocates an entry slot, stores value and the existing next index for key, then inserts the key-to-slot mapping into m_map.
// @fnv 0x00dba360
void ListMapDBA::Insert(unsigned __int64 key, const int& value)
{
    int next = (int)reinterpret_cast<::MapCB1C *>((void *)&(m_map))->FUN_00cb1cb0(key, (unsigned __int64)-1);
    int iSlot = reinterpret_cast<::fnv_00dbe710::S_00dbe710 *>(this)->AllocateSlot();
    EntryDBA& e = m_entries[iSlot];
    e.m_uiFilterValue = value;
    e.m_next = next;
    hkMemoryAllocatorDBA& alloc = *FUN_00c85750()->m_pStreamAllocator;
    reinterpret_cast<::CB1BC0Map *>(&(m_map))->InsertKeyValue((::CB1BC0Allocator &)(alloc), key, iSlot);
}
