
// src/havok/common/base/reflection/hkclassenum.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassenum.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkClassEnum_decl_hkclassenum.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d86000.h"
#include "fnv/decl/ClassMember_d869.h"
#include "fnv/decl/FUN_00d46cf0_C.h"
#include "fnv/symbols_00c90000.h"
#include "havok/hkClassEnum.h"


// Reads a signed char, short or int from p depending on the size returned by FUN_00d86980, defaulting to 0.
// @fnv 0x00d86b80
int ReadSignedValueBySize(const void* apData)
{
    int r = 0;
    switch (static_cast<::ClassMember_d869 *>(nullptr)->FUN_00d86980())
    {
    case 1:
        r = *(const signed char*)apData;
        break;
    case 2:
        r = *(const signed short*)apData;
        break;
    case 4:
        r = *(const int*)apData;
        break;
    }
    return r;
}

struct hkCustomAttributes
{
};

struct FUN_00db76a0_Class
{
    void* GetAttribute(void* arg);
};

// @fnv 0x00db76a0
void* FUN_00db76a0_Class::GetAttribute(void* arg)
{
    hkCustomAttributes* a = *(hkCustomAttributes**)((char*)this + 0xc);
    if (a)
        return reinterpret_cast<::FUN_00d46cf0_C *>((a))->FindEntry((const char *)(arg));
    return 0;
}

struct FUN_00db7860
{
    int m_00;
    int m_04;
    int m_08;
    ~FUN_00db7860() throw();
};

struct FUN_00db7870 : public FUN_00db7860
{
    FUN_00db7870(int n) throw();
};

struct hkObjDB76
{
    void FUN_00db76c0();
};

// Constructs a temporary FUN_00db7870 with 0 and passes it to FUN_00db7600.
// @fnv 0x00db76c0
void hkObjDB76::FUN_00db76c0()
{
    FUN_00db7870 tmp(0);
    reinterpret_cast<::hkClassEnum *>(this)->FUN_00db7600((::hkStreamWriter *)(::FUN_00db7860 *)(&tmp));
}

template <int SIZE> __forceinline void memCpyOneAlignedXdb76f0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXdb76f0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXdb76f0 {
extern "C" hkMemoryRouterXdb76f0& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayXdb76f0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXdb76f0& router = hkRouterXdb76f0::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(router.m_pStreamAllocator), (::AudioStream *)(void *)(this), sizeof(T));
        memCpyOneAlignedXdb76f0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

struct hkEntryXdb76f0
{
    unsigned int m_flags;
    void* m_uiFilterValue;
};

class hkOwnerXdb76f0
{
  public:
    int unk00;
    hkArrayXdb76f0<hkEntryXdb76f0> m_entries;

    bool CollectMatchingEntries(unsigned int flags, hkArrayXdb76f0<void*>& out, unsigned int* remaining);
};

// Iterates m_entries in reverse, adds entries whose m_flags are a subset of flags to out, and stores the unmatched bits in remaining.
// @fnv 0x00db76f0
bool hkOwnerXdb76f0::CollectMatchingEntries(unsigned int flags, hkArrayXdb76f0<void*>& out, unsigned int* remaining)
{
    out.m_iElementCount = 0;
    for (int i = m_entries.m_iElementCount - 1; i >= 0 && flags; i--)
    {
        hkEntryXdb76f0& e = m_entries.m_data[i];
        unsigned int f = e.m_flags;
        if ((f & flags) == f)
        {
            void* value = e.m_uiFilterValue;
            out.AddBack(value);
            flags &= ~f;
        }
    }
    *remaining = flags;
    return flags != 0;
}


class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short memSizeAndFlags;
    short referenceCount;
};
class hkStreamWriter;
class hkOArchive : public hkReferencedObject
{
  public:
    hkStreamWriter* writer;
    hkBool byteSwap;
    hkOArchive(hkStreamWriter*, hkBool);
    virtual ~hkOArchive();
};
class hkClassEnumItem
{
  public:
    int value;
    const char* name;
};
// @fnv 0x00db7600
void hkClassEnum::FUN_00db7600(hkStreamWriter* writer) const
{
    hkOArchive archive(writer, false);
    const char* name = m_name;
    reinterpret_cast<::FUN_00d607b0_class *>(&(archive))->FUN_00d607b0((int)(name));
    int count = m_items.m_iElementCount;
    for (int i = 0; i < count; ++i)
    {
        const hkClassEnumItem& item = m_items.m_data[i];
        const char* itemName = item.name;
        reinterpret_cast<::FUN_00d607b0_class *>(&(archive))->FUN_00d607b0((int)(itemName));
        reinterpret_cast<::hkOArchive_2 *>(&(archive))->WriteInt(item.value);
    }
    reinterpret_cast<::hkOArchive_2 *>(&(archive))->WriteInt(count);
}
