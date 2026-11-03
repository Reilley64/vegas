
// src/havok/common/scenedata/environment/hkxenvironment.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/environment/hkxenvironment.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include "fnv/decl/FUN_00d619d0.h"
#include "fnv/decl/FUN_00d61df0_cls.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_01268000.h"
#include <new>
#include "fnv/decl/CB0StringPtr.h"
#include "fnv/decl/FUN_00cb0a60.h"
#include "fnv/decl/FUN_00e3f230_cls.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "havok/hkxEnvironment.h"

struct HKXMemoryManager
{
    virtual void Unused1()
    {}
    virtual void Unused2()
    {}
    virtual void Free(void* p, unsigned short size) = 0;
};

struct HKXMemoryRouter
{
    void* padding[4];
    HKXMemoryManager* manager;
};

struct HKXEnvironmentStandIn
{
    char padding[4];
    unsigned short size;
    void DestroyEnvironment();
    HKXEnvironmentStandIn* FUN_00e3f8a0(unsigned char flags);
};

HKXMemoryRouter* _D1A0E0GetMemoryRouter();

// Calls DestroyEnvironment, then if bit 0 of flags is set frees this through the memory router's manager, and returns this.
// @fnv 0x00e3f8a0
HKXEnvironmentStandIn* HKXEnvironmentStandIn::FUN_00e3f8a0(unsigned char flags)
{
    DestroyEnvironment();

    if (flags & 1)
    {
        HKXMemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->manager->Free(this, size);
    }

    return this;
}

extern int DAT_010ebab8;

struct FnvVtObj
{
    intptr_t m_vptr;

    FnvVtObj* FUN_00e3f510(unsigned int unusedArg);
};

// @fnv 0x00e3f510
FnvVtObj* FnvVtObj::FUN_00e3f510(unsigned int unusedArg)
{
    m_vptr = (intptr_t)&DAT_010ebab8;
    return this;
}

struct HavokString
{
    char* text;
};
struct EnvironmentVariable
{
    HavokString name;
    HavokString value;
};
struct HavokAllocator
{
    virtual ~HavokAllocator();
    virtual void* AllocateMemoryBlock(int);
    virtual void ReleaseBlock(void*, int);
    virtual void* AllocateBufferWithSize(int&);
    virtual void ReturnMemory(void*, int);
};
struct EnvironmentArray
{
    EnvironmentVariable* data;
    int size;
    int capacityAndFlags;

    __forceinline void release()
    {
        HavokAllocator* allocator = reinterpret_cast<HavokAllocator*>(static_cast<HKXMemoryRouter*>(::FUN_00c85750())->manager);
        EnvironmentVariable* entry = data;
        if (size > 0)
        {
            int remaining = size;
            do
            {
                ::FUN_00cb0c00((intptr_t)(&entry->value));
                ::FUN_00cb0c00((intptr_t)(&entry->name));
                ++entry;
            } while (--remaining != 0);
        }
        size = 0;
        if ((static_cast<unsigned int>(capacityAndFlags) & 0x80000000u) == 0)
            allocator->ReturnMemory(data, (capacityAndFlags & 0x3fffffff) * sizeof(EnvironmentVariable));
        data = 0;
        capacityAndFlags = 0x80000000;
    }
};
struct EnvironmentLayout
{
    void** vtable;
    unsigned short memoryFlags;
    short referenceCount;
    EnvironmentArray variables;
};
hkBaseObject::~hkBaseObject()
{}
// Releases the environment's variable array, then calls the hkBaseObject destructor.
// @fnv 0x00e3f820
void HKXEnvironmentStandIn::DestroyEnvironment()
{
    EnvironmentLayout* environment = reinterpret_cast<EnvironmentLayout*>(this);
    environment->variables.release();
    reinterpret_cast<hkBaseObject*>(environment)->hkBaseObject::~hkBaseObject();
}


struct PlaceTagE3F3
{
};
inline void* operator new(std::size_t, void* p, PlaceTagE3F3) throw()
{
    return p;
}
inline void operator delete(void*, void*, PlaceTagE3F3) throw()
{}

class hkStringPtrE3F3
{
  public:
    const char* m_pcText;


    hkStringPtrE3F3()
    {
        new ((void *)this) struct ::FUN_00cb0a60();
    }
    hkStringPtrE3F3(const hkStringPtrE3F3& kOther)
    {
        new ((void *)this) ::CB0StringPtr((const ::CB0StringPtr &)(kOther));
    }
    ~hkStringPtrE3F3()
    {
        ::FUN_00cb0c00((intptr_t)this);
    }
    void operator=(const char* pcString)
    {
        reinterpret_cast<::SStringPtr *>(this)->FUN_00cb0c10(pcString);
    }
};

struct hkxAttributePairE3F3
{
    hkStringPtrE3F3 m_name;
    hkStringPtrE3F3 m_uiFilterValue;
};

template <int ELEMENTSIZE> __forceinline void memCpyOneAlignedE3F3(void* pvDst, const void* pvSrc)
{
    for (int i = 0; i < ELEMENTSIZE / 4; ++i)
        static_cast<unsigned int*>(pvDst)[i] = static_cast<const unsigned int*>(pvSrc)[i];
}

template <typename T> __forceinline void destructE3F3(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}

template <typename T> struct hkArrayE3F3
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
    __forceinline void removeAt(int iIndex)
    {
        destructE3F3<T>(&m_data[iIndex], 1);
        m_iElementCount--;
        if (m_iElementCount != iIndex)
            memCpyOneAlignedE3F3<sizeof(T)>(m_data + iIndex, m_data + m_iElementCount);
    }
    __forceinline void AddBack(const T& kElem)
    {
        HKXMemoryRouter* pRouter = static_cast<HKXMemoryRouter*>(::FUN_00c85750());
        HavokAllocator* pAlloc = reinterpret_cast<HavokAllocator*>(pRouter->manager);
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(pAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        new (&m_data[m_iElementCount], PlaceTagE3F3()) T(kElem);
        m_iElementCount++;
    }
};

class hkxAttributeMapE3F3
{
  public:
    virtual void V0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkArrayE3F3<hkxAttributePairE3F3> m_pCustomAttributes;

    int FUN_00e3f3b0(const char* pcName, const char* pcValue) throw();
};

// Sets or removes a custom attribute by name, returning 1 if a missing attribute was requested for removal, otherwise 0.
// @fnv 0x00e3f3b0
int hkxAttributeMapE3F3::FUN_00e3f3b0(const char* pcName, const char* pcValue) throw()
{
    int iIndex = reinterpret_cast<::FUN_00e3f230_cls *>(this)->FindEntryByKey((intptr_t)(pcName));
    if (pcValue == 0)
    {
        if (iIndex == -1)
            return 1;
        m_pCustomAttributes.removeAt(iIndex);
        return 0;
    }
    if (iIndex != -1)
    {
        m_pCustomAttributes[iIndex].m_uiFilterValue = pcValue;
        return 0;
    }
    hkxAttributePairE3F3 kPair;
    kPair.m_name = pcName;
    kPair.m_uiFilterValue = pcValue;
    m_pCustomAttributes.AddBack(kPair);
    return 0;
}


struct hkMemoryAllocator
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct hkMemoryRouterStandIn
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterStandIn* getMemoryRouter();

class InlineStorageString
{
  public:
    InlineStorageString();
    __forceinline ~InlineStorageString()
    {
        hkMemoryAllocator& a = getMemoryRouter()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            a.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    InlineStorageString& operator=(const InlineStorageString& other);
    InlineStorageString& operator=(const char* s);
    InlineStorageString& operator+=(const char* s);
    const char* cString() const
    {
        return m_data;
    }

    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_kStorage[128];
};

class hkOstream
{
  public:
    hkOstream(void* buf, int bufSize);
    ~hkOstream();
    hkOstream& operator<<(const char* s);

    int unk00;
    int unk04;
    int unk08;
};

class hkError
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual int message(int type, int id, const char* description, const char* file, int line);

};

struct hkxEnvironmentTransition
{
    int m_uiContentCount;
    int m_pRayCastInput;
    int m_newState;
    int m_pAction;
};

extern const hkxEnvironmentTransition s_transitionTable[32];

struct hkxEnvironmentParser : public hkxEnvironment
{
    int FUN_00e3f520(const char* str);
};

// @fnv 0x00e3f520
int hkxEnvironmentParser::FUN_00e3f520(const char* str)
{
    int state = 0;
    int pos = 0;
    InlineStorageString name;
    InlineStorageString value;
    const intptr_t length = ::fnv_00cb10d0::FUN_00cb10d0(str);

    do
    {
        int input = 4;
        if (pos >= length)
        {
            input = 5;
        }
        else
        {
            const char c = str[pos];
            if (c <= ' ')
            {
                input = 0;
            }
            if (c == '"')
            {
                input = 1;
            }
            else if (c == '=')
            {
                input = 2;
            }
            else if (c == ';')
            {
                input = 3;
            }
        }

        int action = 6;
        int newState = 9;
        int i = 0;
        do
        {
            if (s_transitionTable[i].m_uiContentCount == state && s_transitionTable[i].m_pRayCastInput == input)
            {
                newState = s_transitionTable[i].m_newState;
                action = s_transitionTable[i].m_pAction;
            }
        } while (++i < 32);
        switch (action)
        {
        case 6: {
            char assertBuf[512];
            hkOstream ostr(assertBuf, sizeof(assertBuf));
            reinterpret_cast<::SinkOwner *>((void *)(reinterpret_cast<::SinkOwner *>((void *)(reinterpret_cast<::SinkOwner *>((void *)&(ostr))->FUN_00cc01c0("Error parsing environment string: '")))->FUN_00cc01c0(str)))->FUN_00cc01c0("'");
            (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabba7881, assertBuf, ".\\Environment\\hkxEnvironment.cpp", 308);
            return 1;
        }
        case 0:
            pos++;
            break;
        case 1: {
            char tmp[2] = {str[pos], 0};
            reinterpret_cast<::FUN_00d61df0_cls *>((void *)&(const ::InlineStorageString &)(name))->FUN_00d61df0((intptr_t)(tmp));
            pos++;
            break;
        }
        case 2: {
            char tmp[2] = {str[pos], 0};
            reinterpret_cast<::FUN_00d61df0_cls *>((void *)&(const ::InlineStorageString &)(value))->FUN_00d61df0((intptr_t)(tmp));
            pos++;
            break;
        }
        case 3:
            reinterpret_cast<::hkxAttributeMapE3F3 *>(this)->FUN_00e3f3b0(name.cString(), value.cString());
            reinterpret_cast<::FUN_00d619d0 *>((void *)&(const ::InlineStorageString &)(name))->operator=((const ::FUN_00d619d0 &)(value = ""));
            pos++;
            break;
        case 4:
            reinterpret_cast<::hkxAttributeMapE3F3 *>(this)->FUN_00e3f3b0(name.cString(), 0);
            reinterpret_cast<::FUN_00d619d0 *>((void *)&(const ::InlineStorageString &)(name))->operator=((const ::FUN_00d619d0 &)(value = ""));
            pos++;
            break;
        case 5:
            break;
        default: {
            char assertBuf[512];
            hkOstream ostr(assertBuf, sizeof(assertBuf));
            reinterpret_cast<::SinkOwner *>((void *)(reinterpret_cast<::SinkOwner *>((void *)(reinterpret_cast<::SinkOwner *>((void *)&(ostr))->FUN_00cc01c0("Internal Error: Unknown action parsing environment string: '")))->FUN_00cc01c0(str)))->FUN_00cc01c0("'");
            (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabba0032, assertBuf, ".\\Environment\\hkxEnvironment.cpp", 320);
            return 1;
        }
        }
        state = newState;
    } while (state != 8);
    return 0;
}

#include "generated/data/havok/common/scenedata/environment/hkxenvironment.inc"
