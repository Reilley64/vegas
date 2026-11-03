// src/havok/physics/utilities/serialize/hkphavoksnapshot_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkphavoksnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_00d46d40_s.h"
#include "fnv/decl/FUN_00d47770.h"
#include "fnv/decl/FUN_00d49750.h"
#include "fnv/decl/FUN_00d4bab0.h"
#include "fnv/decl/FUN_00d4c220_s.h"
#include "fnv/decl/FUN_00d61700_cls.h"
#include "fnv/decl/FUN_00d61df0_cls.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/HostType.h"
#include "fnv/decl/ReferencedObjectHolder.h"
#include "fnv/decl/fnv_00cc0ae0__FUN_00cc0ae0_cls.h"
#include "fnv/decl/fnv_00d4aa70__FUN_00d4aa70.h"
#include "fnv/decl/fnv_00d4c250__FUN_00d4c250.h"
#include "fnv/decl/hkStringD618.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00cc0000.h"
#include "fnv/symbols_01044000.h"
#include "fnv/symbols_01063000.h"
#include "fnv/symbols_011b3000.h"
#include "fnv/symbols_01268000.h"
struct CallbackInterface
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void notify(void*, unsigned short);
};
struct State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    CallbackInterface* interface10;
};
struct Object
{
    void* unk00;
    unsigned short unk04;
    Object* FUN_00cc0dd0(unsigned int flags);
};
struct D481D0StringPtr
{
    const char* m_pcText;

    D481D0StringPtr();
    void operator=(const char* s);
};
struct D481D0Class
{
};
struct D481D0ReferencedObject;
struct D481D0RefVariant
{
    D481D0ReferencedObject* m_ptr;

    D481D0RefVariant() : m_ptr(0)
    {}
};
struct FUN_00d481d0
{
    D481D0StringPtr m_name;
    D481D0StringPtr m_pClassName;
    D481D0RefVariant m_pReferencedResource;

    FUN_00d481d0(const char* name, D481D0ReferencedObject* object, const D481D0Class* pClassInfo);
};
struct CC0D30Result
{
    CC0D30Result();

    int m_iResultCode;
    int m_data;
};
struct CC0D30Registry
{
    int unk00;
};
struct S_00cc0d60_R
{
    char v;
    S_00cc0d60_R()
    {}
};
struct S_00cc0d60_A
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};
struct Allocator
{
    virtual void* unk0();
    virtual void* allocate(unsigned int size);
};
struct hkBool
{
    char m_kPointB;
    hkBool()
    {}
    hkBool(bool b) : m_kPointB(b)
    {}
    operator bool() const
    {
        return m_kPointB != 0;
    }
};
struct PtrList;
struct PtrList
{
    void** m_00;
    unsigned int m_04;
    unsigned int m_08;

    void** Add(void* o)
    {
        unsigned int i = m_04;
        void** slot = &m_00[i];
        *slot = o;
        if (slot == 0)
        {
            return 0;
        }
        m_04++;
        return slot;
    }
};
struct Obj70
{
    unsigned int unk00;
    unsigned short m_04;
};
struct Obj110
{
    unsigned int unk00;
    unsigned short m_04;
};
struct Obj80
{
    unsigned int unk00;
    unsigned short m_04;
};
struct TypeMatcher
{
};
struct GlobalObjectO2_00d472a0 : TypeMatcher
{
};
struct FUN_00cc08f0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    PtrList m_08;

    void FUN_00cc08f0(void** a1, void** a2);
};

#include <windows.h>
struct DirAllocator
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void reserved0c();
    virtual void freeBuffer(void*, int);
    template <class T> inline void freeElements(void* p, int count)
    {
        const int itemSize = sizeof(T);
        freeBuffer(p, count * itemSize);
    }
};
struct DirRouter
{
    int unk00, unk04, unk08;
    DirAllocator* temporary;
};
namespace DirectoryMemory {
DirRouter& __cdecl FUN_00c85750();
}
__forceinline DirAllocator& tempAllocator()
{
    return *DirectoryMemory::FUN_00c85750().temporary;
}
void __cdecl reserveDirectoryBuffer(DirAllocator&, void*, int, int);

template <class T> struct DirArrayBase
{
    T* data;
    int count;
    int capacityFlags;
    __forceinline DirArrayBase(T* p, int n, int capacity) : data(p), count(n), capacityFlags(capacity | 0x80000000)
    {}
    __forceinline ~DirArrayBase()
    {}
    __forceinline int capacity() const
    {
        return capacityFlags & 0x3fffffff;
    }
    __forceinline void reserve(DirAllocator& allocator, int n)
    {
        int old = capacity();
        if (old < n)
        {
            int doubled = old * 2;
            reserveDirectoryBuffer(allocator, this, n < doubled ? doubled : n, sizeof(T));
        }
    }
    __forceinline void resize(DirAllocator& allocator, int n)
    {
        reserve(allocator, n);
        count = n;
    }
    __forceinline void release(DirAllocator& allocator)
    {
        count = 0;
        if ((capacityFlags & 0x80000000) == 0)
            allocator.freeElements<T>(data, capacity());
        data = 0;
        capacityFlags = 0x80000000;
    }
};
template <class T> struct DirTempArray : DirArrayBase<T>
{
    __forceinline DirTempArray(T* p, int n, int capacity) : DirArrayBase<T>(p, n, capacity)
    {}
    __forceinline ~DirTempArray()
    {
        DirRouter* router = &DirectoryMemory::FUN_00c85750();
        DirAllocator* allocator = router->temporary;
        this->count = 0;
        if ((this->capacityFlags & 0x80000000) == 0)
            allocator->freeBuffer(this->data, this->capacityFlags & 0x3fffffff);
        this->data = 0;
        this->capacityFlags = 0x80000000;
    }
    __forceinline void resize(int n)
    {
        DirArrayBase<T>::resize(tempAllocator(), n);
    }
};
template <class T, unsigned N> struct DirInlineArray : DirTempArray<T>
{
    T storage[N];
    __forceinline DirInlineArray() : DirTempArray<T>(storage, 0, N)
    {}
    __forceinline ~DirInlineArray()
    {}
};
struct DirectoryString
{
    DirInlineArray<char, 128> chars;
    __forceinline ~DirectoryString()
    {}
    inline int length() const
    {
        return chars.count - 1;
    }
    inline const char* text() const
    {
        return chars.data;
    }
    inline operator const char*() const
    {
        return chars.data;
    }
    inline void setLength(int n)
    {
        chars.resize(n + 1);
        chars.data[n] = 0;
    }
};

struct InitBuffer : DirectoryString
{
    __forceinline ~InitBuffer()
    {}
    InitBuffer()
    {
        setLength(0);
        chars.data[0] = 0;
    }
};
struct FUN_00d61a50 : DirectoryString
{
    __forceinline ~FUN_00d61a50()
    {}
    FUN_00d61a50(const char*);
};

struct DirectoryFlags
{
    unsigned bits;
    inline DirectoryFlags()
    {}
    inline DirectoryFlags(unsigned b) : bits(b)
    {}
};
struct DirectoryItem
{
    const char* name;
    unsigned modified;
    DirectoryFlags flags;
};
struct DirectoryArray
{
    DirectoryItem* data;
    int count, capacityFlags;
    __forceinline DirectoryItem& expand(DirAllocator& allocator)
    {
        if (count == (capacityFlags & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)&(allocator), (::AudioStream *)(void *)(this), sizeof(DirectoryItem));
        return data[count++];
    }
};
struct DirectoryOutput
{
    DirectoryArray entries;
    DirAllocator* allocator;
    __forceinline void add(const char* name, DirectoryFlags flags, unsigned modified = 0)
    {
        DirectoryItem& item = entries.expand(*allocator);
        item.name = ::FUN_00cb1160(name, (void *)&(*allocator));
        item.flags = flags;
        item.modified = modified;
    }
    __forceinline void addDirectory(const char* name)
    {
        add(name, 2);
    }
    __forceinline void addFile(const char* name, unsigned modified = 0)
    {
        add(name, 1, modified);
    }
};
typedef const char*(__cdecl* DirectoryConvert)(const char*, DirectoryString&);
extern const char DAT_0101ffbc[], DAT_010a2560[];
struct DirectoryBool
{
    char value;
    inline DirectoryBool()
    {}
    inline DirectoryBool(bool b)
    {
        value = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return value != 0;
    }
    inline DirectoryBool& operator=(bool b)
    {
        value = static_cast<char>(b);
        return *this;
    }
};
enum DirectoryResult
{
    DirectorySuccess,
    DirectoryFailure
};

// @fnv 0x00da25a0
DirectoryResult __cdecl FUN_00da25a0(const char* input, DirectoryOutput& listing)
{
    InitBuffer path;
    {
        FUN_00d61a50 normalized(input);
        if (normalized.length() > 0)
        {
            reinterpret_cast<::hkStringD618 *>(&(normalized))->ReplaceChar('\\', '/', 1);
            if (!reinterpret_cast<::FUN_00d61700_cls *>((void *)&(normalized))->EndsWith((char *)(DAT_01063cbc)))
                reinterpret_cast<::FUN_00d61df0_cls *>(&(normalized))->FUN_00d61df0((int)(DAT_01063cbc));
            (*reinterpret_cast<const char *(**)(const char *, DirectoryString &)>(&::DAT_011b3dc0))(normalized.text(), path);
        }
    }
    DWORD attrs = GetFileAttributesA(path);
    if (attrs == INVALID_FILE_ATTRIBUTES)
        return DirectoryFailure;
    bool valid = (attrs & FILE_ATTRIBUTE_DIRECTORY) != 0;
    if (!valid)
        return DirectoryFailure;
    if (path.length())
        reinterpret_cast<::FUN_00d61df0_cls *>(&(path))->FUN_00d61df0((int)(DAT_0101ffbc));
    WIN32_FIND_DATAA found;
    HANDLE handle = FindFirstFileA(path, &found);
    DirectoryBool more = handle != INVALID_HANDLE_VALUE;
    while (more)
    {
        if (::fnv_00cb0fa0::FUN_00cb0fa0(found.cFileName, DAT_01044c28) && ::fnv_00cb0fa0::FUN_00cb0fa0(found.cFileName, DAT_010a2560))
        {
            bool directory = (found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
            if (directory)
            {
                listing.addDirectory(found.cFileName);
            }
            else
            {
                LARGE_INTEGER epoch = {0};
                epoch.QuadPart = 0x19db1ded53e8000LL;
                __int64 seconds = (*(__int64*)&found.ftLastWriteTime - epoch.QuadPart) / 10000000;
                listing.addFile(found.cFileName, (unsigned)seconds);
            }
        }
        more = FindNextFileA(handle, &found) != 0;
    }
    FindClose(handle);
    return DirectorySuccess;
}

#include "generated/data/havok/physics/utilities/serialize/hkphavoksnapshot_gs_ehsc_nogs_noehsc_variant.inc"
