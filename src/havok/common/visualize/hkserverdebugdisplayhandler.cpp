
// src/havok/common/visualize/hkserverdebugdisplayhandler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkserverdebugdisplayhandler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstddef>
#include <new>
#include <windows.h>
#include "fnv/decl/DDA8C0Writer.h"
#include "fnv/decl/FUN_00d605d0_class.h"
#include "fnv/decl/FUN_00d607b0_class.h"
#include "fnv/decl/FUN_00d607e0_class.h"
#include "fnv/decl/FUN_00d609a0_Class.h"
#include "fnv/decl/S_00dda740.h"
#include "fnv/decl/hkOArchiveStandIn.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00ce5000.h"
#include "fnv/symbols_00d60000.h"
#include "fnv/symbols_00dda000.h"
#include "fnv/symbols_010d7000.h"
struct FUN_00dd97c0
{
    int* m_p;
    FUN_00dd97c0(char f);
};
// @fnv 0x00dd97c0
FUN_00dd97c0::FUN_00dd97c0(char acFlags)
{
    m_p = &(*reinterpret_cast<int *>(&::fnv_00ddcaf0::DAT_010d7cfc));
    if (acFlags & 1)
        ::FUN_00401030(this);
}

struct FUN_00d605d0_Class
{
};
struct Record
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    bool SetConfigValues(unsigned int a, unsigned int b, unsigned int c, int d, unsigned int e);
};
// Locks the critical section, writes five values to config, reads back a string, and returns whether the read-back string is empty.
// @fnv 0x00dd9b40
bool Record::SetConfigValues(unsigned int uiValueA, unsigned int uiValueB, unsigned int uiValueC, int iValueD,
                             unsigned int uiValueE)
{
    EnterCriticalSection(criticalSection);
    if (config)
    {
        ::FUN_00d60960((const float *)(config));
        reinterpret_cast<::FUN_00d605d0_class *>((config))->FUN_00d605d0(8);
        ::FUN_00dda730((uintptr_t)(config));
        ::FUN_00dda730((uintptr_t)(config));
        ::FUN_00d60960((const float *)(config));
        reinterpret_cast<::FUN_00d609a0_Class *>((config))->FUN_00d609a0(iValueD, {});
        reinterpret_cast<::hkOArchive_2 *>((config))->WriteInt(uiValueE);
    }
    bool hasValue;
    if (config)
    {
        const char* value = ((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((config))->ForwardValueToObject((intptr_t)(&uiValueA))));
        if (value[0] == 0)
            goto noValue;
        hasValue = true;
        goto valueChecked;
    noValue:
        hasValue = false;
    valueChecked:;
    }
    else
        hasValue = false;
    LeaveCriticalSection(criticalSection);
    return !hasValue;
}

struct FUN_00dd9ab0_cls
{
    int unk00;
    FUN_00d605d0_Class* m_pConfiguration;
    void* m_pWorldLock;
    bool FUN_00dd9ab0(unsigned int a1, unsigned int a2, int a3, unsigned int a4);
};

// @fnv 0x00dd9ab0
bool FUN_00dd9ab0_cls::FUN_00dd9ab0(unsigned int a1, unsigned int a2, int a3, unsigned int a4)
{
    bool ok;
    EnterCriticalSection(m_pWorldLock);
    if (m_pConfiguration != 0)
    {
        ::FUN_00d60960((const float *)(m_pConfiguration));
        reinterpret_cast<::FUN_00d605d0_class *>((m_pConfiguration))->FUN_00d605d0(7);
        ::FUN_00dda730((uintptr_t)(m_pConfiguration));
        ::FUN_00d60960((const float *)(m_pConfiguration));
        reinterpret_cast<::FUN_00d609a0_Class *>((m_pConfiguration))->FUN_00d609a0(a3, {});
        reinterpret_cast<::hkOArchive_2 *>((m_pConfiguration))->WriteInt(a4);
    }
    if (m_pConfiguration == 0)
    {
        goto not_found;
    }
    {
        const char* s = ((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((m_pConfiguration))->ForwardValueToObject((intptr_t)(&a1))));
        if (*s != 0)
        {
            ok = true;
            goto done;
        }
    }
not_found:
    ok = false;
done:
    LeaveCriticalSection(m_pWorldLock);
    return !ok;
}

struct ConfigExt
{
};

struct FUN_00dd9be0_cls
{
    int unk00;
    FUN_00d605d0_Class* m_pConfiguration;
    void* m_cs;
    bool FUN_00dd9be0(unsigned int a, unsigned int b);
};

// @fnv 0x00dd9be0
bool FUN_00dd9be0_cls::FUN_00dd9be0(unsigned int auiValue, unsigned int auiParam)
{
    EnterCriticalSection(m_cs);
    if (m_pConfiguration != 0)
    {
        unsigned int v = auiParam;
        ::FUN_00d60960((const float *)(m_pConfiguration));
        reinterpret_cast<::FUN_00d605d0_class *>((m_pConfiguration))->FUN_00d605d0(0xf);
        reinterpret_cast<::hkOArchive_2 *>((m_pConfiguration))->WriteInt(v);
        reinterpret_cast<::FUN_00d607b0_class *>((((ConfigExt*)m_pConfiguration)))->FUN_00d607b0(auiValue);
    }
    bool result;
    if (m_pConfiguration != 0)
    {
        const char* s = ((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((m_pConfiguration))->ForwardValueToObject((intptr_t)(&auiParam))));
        if (*s == 0)
        {
            goto zero;
        }
        result = true;
        goto done;
    }
zero:
    result = false;
done:
    LeaveCriticalSection(m_cs);
    return !result;
}

struct S_00dd9c60
{
    int unk00;
    FUN_00d605d0_Class* unk04;
    void* unk08;
    bool FUN_00dd9c60();
};
// @fnv 0x00dd9c60
bool S_00dd9c60::FUN_00dd9c60()
{
    EnterCriticalSection(unk08);
    if (unk04)
    {
        ::FUN_00d60960((const float *)(unk04));
        reinterpret_cast<::FUN_00d605d0_class *>((unk04))->FUN_00d605d0(0xb);
    }
    bool r;
    char c;
    if (unk04 && *((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((unk04))->ForwardValueToObject((intptr_t)((unsigned int*)&c)))) != 0)
        r = true;
    else
        r = false;
    LeaveCriticalSection(unk08);
    return !r;
}


struct DD9D70StringArray
{
    const char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// @fnv 0x00dd9d70
static __declspec(noinline) int FUN_00dd9d70(const DD9D70StringArray& strings)
{
    int size = 4;
    for (int i = 0; i < strings.m_iElementCount; i++)
    {
        const char* const& s = strings.m_data[i];
        size += ::FUN_00dda850((intptr_t)(s));
    }
    return size;
}

// Caller so the file-static helper is emitted with its register calling convention.
int DD9D70ComputeSize(const DD9D70StringArray* a, const DD9D70StringArray* b)
{
    return FUN_00dd9d70(*a) + FUN_00dd9d70(*b);
}


class ConfigStub
{
  public:
};

struct ItemList
{
    unsigned int* m_pItems;
    int m_iArrayLength;
};

class FUN_00dd9da0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00d605d0_Class* m_pConfig;
    void* m_pUserData;

    void ApplyItemList(ItemList* pList);
};

// @fnv 0x00dd9da0
void FUN_00dd9da0_cls::ApplyItemList(ItemList* pItemList)
{
    int i;

    EnterCriticalSection(m_pUserData);
    reinterpret_cast<::hkOArchive_2 *>((m_pConfig))->WriteInt(pItemList->m_iArrayLength);
    for (i = 0; i < pItemList->m_iArrayLength; i++)
    {
        reinterpret_cast<::DDA8C0Writer *>((((ConfigStub*)m_pConfig)))->WriteShape((::Shape *)(pItemList->m_pItems[i]));
    }
    LeaveCriticalSection(m_pUserData);
}


struct ParentRec
{
};

struct ConfigAux
{
};

unsigned int FUN_00dd9d70();

struct FUN_00dd9df0_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    bool FUN_00dd9df0(unsigned int a1, uintptr_t a2, unsigned int a3, unsigned int a4, unsigned int a5);
};

// Locks the critical section, applies the given values to config and parent, then returns whether the config's check fails.
// @fnv 0x00dd9df0
bool FUN_00dd9df0_cls::FUN_00dd9df0(unsigned int a1, uintptr_t a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
    EnterCriticalSection(this->criticalSection);
    if (this->config != 0)
    {
        uintptr_t uiValue1Copy = a1;
        unsigned int v = FUN_00dd9d70();
        reinterpret_cast<::hkOArchive_2 *>((this->config))->WriteInt(v + 0x29);
        reinterpret_cast<::FUN_00d605d0_class *>((this->config))->FUN_00d605d0(1);
        reinterpret_cast<::FUN_00dd9da0_cls *>((((ParentRec*)((char*)this - 8))))->ApplyItemList((::ItemList *)(uiValue1Copy));
        reinterpret_cast<::S_00dda740 *>((((ConfigAux*)this->config)))->WriteTransform((*(const ::S_00dda740_Transform *)(a2)));
        reinterpret_cast<::FUN_00d609a0_Class *>((this->config))->FUN_00d609a0(a3, {});
        reinterpret_cast<::hkOArchive_2 *>((this->config))->WriteInt(a4);
    }
    bool ok;
    if (this->config == 0)
    {
        goto notok;
    }
    if (*((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((this->config))->ForwardValueToObject((intptr_t)(&a1)))) != 0)
    {
        ok = true;
        goto done;
    }
notok:
    ok = false;
done:
    LeaveCriticalSection(this->criticalSection);
    return !ok;
}

unsigned int FUN_00dd9d70();

struct FUN_00dd9da0_ext
{
};

struct FUN_00dd9f40_cls
{
    int unk00;
    FUN_00d605d0_Class* m_pConfiguration;
    void* m_pWorldLock;
    bool SetAndCheck(unsigned int a1, unsigned int a2, int a3, unsigned int a4);
};

// @fnv 0x00dd9f40
bool FUN_00dd9f40_cls::SetAndCheck(unsigned int uiValue, unsigned int a2, int a3, unsigned int a4)
{
    bool ok;
    EnterCriticalSection(m_pWorldLock);
    if (m_pConfiguration != 0)
    {
        uintptr_t v = uiValue;
        reinterpret_cast<::hkOArchive_2 *>((m_pConfiguration))->WriteInt(FUN_00dd9d70() + 0x11);
        reinterpret_cast<::FUN_00d605d0_class *>((m_pConfiguration))->FUN_00d605d0(6);
        reinterpret_cast<::FUN_00dd9da0_cls *>((reinterpret_cast<FUN_00dd9da0_ext*>((char*)this - 8)))->ApplyItemList((::ItemList *)(v));
        ::FUN_00d60960((const float *)(m_pConfiguration));
        reinterpret_cast<::FUN_00d609a0_Class *>((m_pConfiguration))->FUN_00d609a0((__int64)a3, {});
        reinterpret_cast<::hkOArchive_2 *>((m_pConfiguration))->WriteInt(a4);
    }
    if (m_pConfiguration == 0)
    {
        goto not_found;
    }
    {
        const char* s = ((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((m_pConfiguration))->ForwardValueToObject((intptr_t)(&uiValue))));
        if (*s != 0)
        {
            ok = true;
            goto done;
        }
    }
not_found:
    ok = false;
done:
    LeaveCriticalSection(m_pWorldLock);
    return !ok;
}

struct FUN_00d605d0_ext
{
};


struct FUN_00dda0e0_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    int FUN_00dda0e0(unsigned int a, unsigned int b, int c, unsigned int d);
};

// @fnv 0x00dda0e0
int FUN_00dda0e0_cls::FUN_00dda0e0(volatile unsigned int auiValue, unsigned int b, int c, unsigned int d)
{
    EnterCriticalSection(criticalSection);
    if (config != 0)
    {
        uintptr_t v = auiValue;
        intptr_t len = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(v));
        intptr_t n = (len < 0xffff) ? len : 0xffff;
        ::FUN_00d60960((const float *)(config));
        reinterpret_cast<::FUN_00d605d0_class *>((config))->FUN_00d605d0(9);
        reinterpret_cast<::hkOArchiveStandIn *>((reinterpret_cast<FUN_00d605d0_ext*>(config)))->WriteUInt16(n);
        reinterpret_cast<::FUN_00d607b0_class *>((reinterpret_cast<FUN_00d605d0_ext*>(config)))->FUN_00d607b0(v);
        reinterpret_cast<::hkOArchive_2 *>((config))->WriteInt(b);
        reinterpret_cast<::FUN_00d609a0_Class *>((config))->FUN_00d609a0((__int64)c, {});
        reinterpret_cast<::hkOArchive_2 *>((config))->WriteInt(d);
    }
    bool ok = (config != 0) && (((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((config))->ForwardValueToObject((intptr_t)((unsigned int*)&auiValue))))[0] != 0);
    LeaveCriticalSection(criticalSection);
    return !ok;
}


struct FUN_00d605d0_ext_cls
{
};

struct FUN_00dda1a0_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;

    bool WriteConfigEntry(const char* name, const float* vec, unsigned int a, int b, unsigned int c);
};

// @fnv 0x00dda1a0
bool FUN_00dda1a0_cls::WriteConfigEntry(const char* name, const float* vec, unsigned int uiValueA, int iValueB,
                                        unsigned int uiValueC)
{
    EnterCriticalSection(criticalSection);
    if (config != 0)
    {
        intptr_t n = ::fnv_00cb10d0::FUN_00cb10d0(name);
        intptr_t length = (n < 0xffff) ? n : 0xffff;
        ::FUN_00d60960((const float *)(config));
        reinterpret_cast<::FUN_00d605d0_class *>((config))->FUN_00d605d0(0x11);
        reinterpret_cast<::hkOArchiveStandIn *>((reinterpret_cast<FUN_00d605d0_ext_cls*>(config)))->WriteUInt16(length);
        reinterpret_cast<::FUN_00d607b0_class *>((reinterpret_cast<FUN_00d605d0_ext_cls*>(config)))->FUN_00d607b0((intptr_t)(name));
        reinterpret_cast<::hkOArchive_2 *>((config))->WriteInt(uiValueA);
        reinterpret_cast<::FUN_00d609a0_Class *>((config))->FUN_00d609a0((__int64)iValueB, {});
        reinterpret_cast<::hkOArchive_2 *>((config))->WriteInt(uiValueC);
        ::HashUInt((uintptr_t)(reinterpret_cast<FUN_00d605d0_ext_cls*>(config)));
        ::HashUInt((uintptr_t)(reinterpret_cast<FUN_00d605d0_ext_cls*>(config)));
        ::HashUInt((uintptr_t)(reinterpret_cast<FUN_00d605d0_ext_cls*>(config)));
    }
    bool result;
    if (config == 0)
    {
        goto done;
    }
    {
        unsigned int id;
        const char* text = ((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((config))->ForwardValueToObject((intptr_t)(&id))));
        if (text[0] != 0)
        {
            result = true;
            goto out;
        }
    }
done:
    result = false;
out:
    LeaveCriticalSection(criticalSection);
    return !result;
}

struct FUN_00dda290_ext
{
};


struct FUN_00dda290_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    int WriteConfigValue(unsigned int a, int b, unsigned int c);
};

// @fnv 0x00dda290
int FUN_00dda290_cls::WriteConfigValue(volatile unsigned int a, int aiValue, unsigned int c)
{
    EnterCriticalSection(criticalSection);
    if (config != 0)
    {
        uintptr_t v = a;
        intptr_t len = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(v));
        intptr_t n = (len < 0xffff) ? len : 0xffff;
        ::FUN_00d60960((const float *)(config));
        reinterpret_cast<::FUN_00d605d0_class *>((config))->FUN_00d605d0(0x14);
        reinterpret_cast<::hkOArchiveStandIn *>((reinterpret_cast<FUN_00dda290_ext*>(config)))->WriteUInt16(n);
        reinterpret_cast<::FUN_00d607b0_class *>((reinterpret_cast<FUN_00dda290_ext*>(config)))->FUN_00d607b0(v);
        reinterpret_cast<::FUN_00d609a0_Class *>((config))->FUN_00d609a0((__int64)aiValue, {});
        reinterpret_cast<::hkOArchive_2 *>((config))->WriteInt(c);
    }
    bool ok = (config != 0) && (((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((config))->ForwardValueToObject((intptr_t)((unsigned int*)&a))))[0] != 0);
    LeaveCriticalSection(criticalSection);
    return !ok;
}

#include <xmmintrin.h>
#include <windows.h>
struct DD97E0Vector4
{
    __m128 m_vComponents;
};

struct __declspec(align(16)) DD97E0Point
{
    float x;
    float y;
    float z;
    float w;
};

struct DD97E0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD97E0OStream
{
    void writeCommand(unsigned int value);
    void writeCount(unsigned int value);
    void writeVector(const DD97E0Point& v);
    void writeUint64(unsigned __int64 value);
    void writeTag(int value);
    DD97E0Bool IsStreamValid();
};

struct DD97E0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

struct DD97E0DisplayHandler
{
    int unk00;
    DD97E0OStream* m_pDisplayStream;
    DD97E0CriticalSection* m_pSynchronizationLock;

    int FUN_00dd97e0(int a, int b, int c, int d, int e);
};

// Locks m_pSynchronizationLock, checks m_pDisplayStream and its IsStreamValid, then returns 0 if valid or 1 otherwise.
// @fnv 0x00dd97e0
int DD97E0DisplayHandler::FUN_00dd97e0(int aUnused, int bUnused, int c, int dUnused, int eUnused)
{
    m_pSynchronizationLock->enter();
    bool ok = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    m_pSynchronizationLock->leave();
    return ok ? 0 : 1;
}

struct FUN_00d60940_Class
{
};
struct Stream : FUN_00d605d0_Class
{
};
struct Output
{
    int state;
    Stream* stream;
    CRITICAL_SECTION* lock;
    int WriteRecord(unsigned int, unsigned int, unsigned int);
};
// Under the lock, writes command 17, count 3, and the three arguments, then returns the negation of the forwarded value's first byte.
// @fnv 0x00dd9830
int Output::WriteRecord(unsigned int first, unsigned int second, unsigned int third)
{
    EnterCriticalSection(lock);
    if (stream)
    {
        ::FUN_00d60960((const float *)(stream));
        reinterpret_cast<::FUN_00d605d0_class *>((stream))->FUN_00d605d0(3);
        ::FUN_00d60960((const float *)(stream));
        reinterpret_cast<::FUN_00d609a0_Class *>((stream))->FUN_00d609a0(second, 0);
        reinterpret_cast<::hkOArchive_2 *>((((FUN_00d60940_Class*)stream)))->WriteInt(third);
    }
    bool failed = stream && *((char *)(reinterpret_cast<::FUN_00d607e0_class *>((stream))->ForwardValueToObject((intptr_t)(&first))));
    LeaveCriticalSection(lock);
    return !failed;
}

enum S_00dd98c0_Result
{
    S_00dd98c0_SUCCESS = 0,
    S_00dd98c0_FAILURE = 1
};
struct S_00dd98c0_Bool
{
    char m_cBooleanValue;
    S_00dd98c0_Bool()
    {}
};
struct S_00dd98c0_Target
{
    S_00dd98c0_Bool ForwardValueToObject();
};
struct S_00dd98c0
{
    int unk0;
    S_00dd98c0_Target* unk4;
    CRITICAL_SECTION* unk8;
    S_00dd98c0_Result WriteValue(intptr_t a1, int a2, int a3);
};
// Writes a1, a2, a3 to unk4 under unk8, then returns SUCCESS if unk4 and ForwardValueToObject() are true, else FAILURE.
// @fnv 0x00dd98c0
S_00dd98c0_Result S_00dd98c0::WriteValue(intptr_t a1, int a2, int a3)
{
    EnterCriticalSection(unk8);
    if (unk4)
    {
        ::FUN_00d60960((const float *)(unk4));
        reinterpret_cast<::FUN_00d605d0_class *>((unk4))->FUN_00d605d0(2);
        reinterpret_cast<::S_00dda740 *>((unk4))->WriteTransform((*(const ::S_00dda740_Transform *)(a1)));
        reinterpret_cast<::FUN_00d609a0_Class *>((unk4))->FUN_00d609a0(a2, 0);
        reinterpret_cast<::hkOArchive_2 *>((unk4))->WriteInt(a3);
    }
    bool ok = unk4 && unk4->ForwardValueToObject().m_cBooleanValue;
    LeaveCriticalSection(unk8);
    return ok ? S_00dd98c0_SUCCESS : S_00dd98c0_FAILURE;
}

struct DD9950Bool
{
    char m_cBooleanValue;

    DD9950Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

enum DD9950Result
{
    DD9950_SUCCESS = 0,
    DD9950_FAILURE = 1
};

struct DD9950CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

struct DD9950OArchive
{
    DD9950Bool IsStreamValid() const;
};

struct DD9950DisplayServer
{
    int unk00;
    DD9950OArchive* m_pDisplayStream;
    DD9950CriticalSection* m_outStreamLock;

    DD9950Result FUN_00dd9950(unsigned long id, int tag, unsigned long shapeIdHint);
};

// @fnv 0x00dd9950
DD9950Result DD9950DisplayServer::FUN_00dd9950(unsigned long id, int tag, unsigned long shapeIdHint)
{
    m_outStreamLock->enter();
    if (m_pDisplayStream)
    {
        ::FUN_00d60960((const float *)(m_pDisplayStream));
        reinterpret_cast<::FUN_00d605d0_class *>((m_pDisplayStream))->FUN_00d605d0(4);
        reinterpret_cast<::FUN_00d609a0_Class *>((m_pDisplayStream))->FUN_00d609a0(id, {});
        reinterpret_cast<::hkOArchive_2 *>((m_pDisplayStream))->WriteInt(tag);
    }
    bool streamOk = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    m_outStreamLock->leave();
    return streamOk ? DD9950_SUCCESS : DD9950_FAILURE;
}

namespace fnv_00dd99d0 {
struct DD99D0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD99D0OStream
{
    void writeCommand(unsigned int value);
    void writeVector(const void* v);
    DD99D0Bool IsStreamValid();
};

struct DD99D0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};


struct DD99D0DisplayHandler
{
    int unk00;
    DD99D0OStream* m_pDisplayStream;
    DD99D0CriticalSection* m_pSynchronizationLock;

    int WriteDisplayCommand(const void* a, const void* b, const void* c, float x, float y, float z, const char* text);
};

// Writes a display command with three vectors, three floats, and a text string to m_pDisplayStream under m_pSynchronizationLock.
// @fnv 0x00dd99d0
int DD99D0DisplayHandler::WriteDisplayCommand(const void* apVector1, const void* apVector2, const void* apVector3,
                                              float x, float y, float z, const char* text)
{
    m_pSynchronizationLock->enter();
    if (m_pDisplayStream)
    {
        intptr_t length = ::fnv_00cb10d0::FUN_00cb10d0(text);
        ::FUN_00d60960((const float *)(m_pDisplayStream));
        reinterpret_cast<::FUN_00d605d0_class *>((m_pDisplayStream))->FUN_00d605d0(0xd);
        ::FUN_00dda730((uintptr_t)(m_pDisplayStream));
        ::FUN_00dda730((uintptr_t)(m_pDisplayStream));
        ::FUN_00dda730((uintptr_t)(m_pDisplayStream));
        ::HashUInt((uintptr_t)(m_pDisplayStream));
        ::HashUInt((uintptr_t)(m_pDisplayStream));
        ::HashUInt((uintptr_t)(m_pDisplayStream));
        reinterpret_cast<::hkOArchiveStandIn *>((m_pDisplayStream))->WriteUInt16(length);
        reinterpret_cast<::FUN_00d607b0_class *>((m_pDisplayStream))->FUN_00d607b0((intptr_t)(text));
    }
    bool ok = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    m_pSynchronizationLock->leave();
    return ok ? 0 : 1;
}
}  // namespace fnv_00dd99d0

struct DD9FE0Vector4
{
    __m128 m_vComponents;
};

struct __declspec(align(16)) DD9FE0Point
{
    float x;
    float y;
    float z;
    float w;
};

struct DD9FE0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD9FE0OStream
{
    void writeCommand(unsigned int value);
    void writeCount(unsigned int value);
    void writeVector(const DD9FE0Point& v);
    void writeUint64(unsigned __int64 value);
    void writeTag(int value);
    DD9FE0Bool IsStreamValid();
};

struct DD9FE0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

struct DD9FE0DisplayHandler
{
    int unk00;
    DD9FE0OStream* m_pDisplayStream;
    DD9FE0CriticalSection* m_pSynchronizationLock;

    int WriteTriangle(const DD9FE0Vector4& a, const DD9FE0Vector4& b, const DD9FE0Vector4& c, unsigned int color,
                      int id, int tag);
};

// Writes three line segments forming a triangle to the display stream under a critical section, returning 0 on success or 1 if the stream is missing or invalid.
// @fnv 0x00dd9fe0
int DD9FE0DisplayHandler::WriteTriangle(const DD9FE0Vector4& a, const DD9FE0Vector4& b, const DD9FE0Vector4& c,
                                        unsigned int color, int id, int tag)
{
    m_pSynchronizationLock->enter();
    if (m_pDisplayStream)
    {
        DD9FE0Point verts[4];
        *(__m128*)&verts[0] = a.m_vComponents;
        *(__m128*)&verts[1] = b.m_vComponents;
        *(__m128*)&verts[2] = c.m_vComponents;
        *(__m128*)&verts[3] = a.m_vComponents;
        unsigned __int64 id64 = id;
        for (int i = 0; i < 3; i++)
        {
            ::FUN_00d60960((const float *)(m_pDisplayStream));
            reinterpret_cast<::FUN_00d605d0_class *>((m_pDisplayStream))->FUN_00d605d0(8);
            ::FUN_00dda730((uintptr_t)(m_pDisplayStream));
            ::FUN_00dda730((uintptr_t)(m_pDisplayStream));
            ::FUN_00d60960((const float *)(m_pDisplayStream));
            reinterpret_cast<::FUN_00d609a0_Class *>((m_pDisplayStream))->FUN_00d609a0(id64, {});
            reinterpret_cast<::hkOArchive_2 *>((m_pDisplayStream))->WriteInt(tag);
        }
    }
    bool ok = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    m_pSynchronizationLock->leave();
    return ok ? 0 : 1;
}

struct Vec4_dda340
{
    float x;
    float y;
    float z;
    float w;
};

struct __declspec(align(16)) Transform_dda340
{
    Vec4_dda340 rotation0;
    Vec4_dda340 rotation1;
    Vec4_dda340 rotation2;
    Vec4_dda340 translation;
};

struct QsTransform_dda340
{
    Vec4_dda340 translation;
    Vec4_dda340 rotation;
    Vec4_dda340 scale;

};

struct MemoryAllocator_dda340
{
    virtual void* vfn0() = 0;
    virtual void* vfn1() = 0;
    virtual void* vfn2() = 0;
    virtual void* vfn3() = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;
};

struct ThreadMemory_dda340
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemoryAllocator_dda340* m_pMemoryAllocator;
};

ThreadMemory_dda340* FUN_00c85750();

template <typename T> struct ArrayRef_dda340
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class Array_dda340
{
  public:
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    Array_dda340() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    void ClearAndRelease()
    {
        ThreadMemory_dda340* mem = FUN_00c85750();
        MemoryAllocator_dda340* alloc = mem->m_pMemoryAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc->ReleaseBlock(m_data, (cap & 0x3fffffff) * sizeof(int));
        }
    }

    void AddBack(intptr_t val)
    {
        ThreadMemory_dda340* mem = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ::ResizeAudioStream((::AudioAllocator *)(mem->m_pMemoryAllocator), (::AudioStream *)(void *)(this), sizeof(int));
        }
        m_data[m_iElementCount++] = val;
    }
};

struct Config_dda340 : public FUN_00d605d0_Class
{
};

struct Writer_dda340
{
    int unk00;
    Config_dda340* config;
    void* criticalSection;

    bool Write(const ArrayRef_dda340<unsigned int>& a1, const ArrayRef_dda340<unsigned int>& a2,
               const ArrayRef_dda340<unsigned int>& a3, const ArrayRef_dda340<Vec4_dda340>& a4,
               const ArrayRef_dda340<const char*>& a5, const ArrayRef_dda340<unsigned int>& a6,
               const ArrayRef_dda340<unsigned int>& a7, const ArrayRef_dda340<QsTransform_dda340>& a8);
};

// Writes supplied data when a config exists; returns false only when the forwarded value is nonzero.
// @fnv 0x00dda340
bool Writer_dda340::Write(const ArrayRef_dda340<unsigned int>& a1, const ArrayRef_dda340<unsigned int>& a2,
                          const ArrayRef_dda340<unsigned int>& a3, const ArrayRef_dda340<Vec4_dda340>& a4,
                          const ArrayRef_dda340<const char*>& a5, const ArrayRef_dda340<unsigned int>& a6,
                          const ArrayRef_dda340<unsigned int>& a7, const ArrayRef_dda340<QsTransform_dda340>& a8)
{
    EnterCriticalSection(this->criticalSection);
    if (this->config)
    {
        int size2 = a2.m_iElementCount;
        int iVec4Count = a4.m_iElementCount;
        int totalSize = ((size2 + iVec4Count * 2) * 2 + a8.m_iElementCount * 7 + a6.m_iElementCount + a7.m_iElementCount) * 4 + 25;
        Array_dda340 stringLengths;
        for (int i = 0; i < a5.m_iElementCount; ++i)
        {
            if (a5.m_data[i] != 0)
            {
                totalSize += 2;
                intptr_t len = ::fnv_00cb10d0::FUN_00cb10d0(a5.m_data[i]);
                stringLengths.AddBack(len);
                totalSize += len;
            }
            else
            {
                stringLengths.AddBack(0);
            }
        }

        ::FUN_00d60960((const float *)(this->config));
        reinterpret_cast<::FUN_00d605d0_class *>((this->config))->FUN_00d605d0(0x12);
        ::FUN_00d60960((const float *)(this->config));

        for (int i = 0; i < a2.m_iElementCount; ++i)
        {
            ::FUN_00d60960((const float *)(this->config));
            ::FUN_00d60960((const float *)(this->config));
        }

        ::FUN_00d60960((const float *)(this->config));

        for (int i = 0; i < a4.m_iElementCount; ++i)
        {
            ::FUN_00d60960((const float *)(this->config));
            ::FUN_00dda730((uintptr_t)(this->config));
        }

        ::FUN_00d60960((const float *)(this->config));

        for (int i = 0; i < a5.m_iElementCount; ++i)
        {
            if (a5.m_data[i] != 0)
            {
                unsigned int len = stringLengths.m_data[i];
                reinterpret_cast<::hkOArchiveStandIn *>((this->config))->WriteUInt16(len);
                reinterpret_cast<::FUN_00d607b0_class *>((this->config))->FUN_00d607b0((intptr_t)(a5.m_data[i]));
            }
        }

        ::FUN_00d60960((const float *)(this->config));

        for (int i = 0; i < a8.m_iElementCount; ++i)
        {
            Transform_dda340 t;
            ::FUN_00ce5300();
            reinterpret_cast<::S_00dda740 *>((this->config))->WriteTransform((*(const ::S_00dda740_Transform *)(&t)));
        }

        ::FUN_00d60960((const float *)(this->config));

        for (int i = 0; i < a6.m_iElementCount; ++i)
        {
            ::FUN_00d60960((const float *)(this->config));
        }

        ::FUN_00d60960((const float *)(this->config));

        for (int i = 0; i < a7.m_iElementCount; ++i)
        {
            ::FUN_00d60960((const float *)(this->config));
        }

        stringLengths.ClearAndRelease();
    }

    char status;
    bool failed = (this->config != 0 && *((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((this->config))->ForwardValueToObject((intptr_t)((unsigned int*)&status)))) != 0);

    LeaveCriticalSection(this->criticalSection);
    return !failed;
}

// FUN_00dda650 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00dda650
{
    A1_00dda650();
    virtual void FUN_00dda650();
    char pad[0x04];
};
struct A2_00dda650
{
    A2_00dda650();
    virtual void FUN_00dda650();
};
struct Own_00dda650 : A1_00dda650, A2_00dda650
{
    Own_00dda650();
    virtual void key_fn();
// @fnv 0x00dda650
    void FUN_00dda650();
};
Own_00dda650::Own_00dda650()
{}
void Own_00dda650::key_fn()
{}
Own_00dda650* make_00dda650()
{
    static Own_00dda650 o;
    return &o;
}

namespace fnv_00dda660 {
struct FUN_00dda660_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct FUN_00dda660_MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00dda660_Allocator* m_pStreamAllocator;

    FUN_00dda660_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" FUN_00dda660_MemoryRouter& __cdecl FUN_00c85750();

struct FUN_00dda660
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dda660();
    virtual ~FUN_00dda660();

    static void operator delete(void* p, std::size_t nbytes)
    {
        FUN_00dda660* b = static_cast<FUN_00dda660*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// The constructor has an empty body.
// @fnv 0x00dda660
FUN_00dda660::FUN_00dda660()
{}
}  // namespace fnv_00dda660

unsigned int FUN_00dd9d70();

struct FUN_00dd9da0_owner
{
};

struct ConfigQ : FUN_00d605d0_Class
{
};

struct SecondaryDisplay
{
    int unk00;
    ConfigQ* config;
    void* criticalSection;

    bool FUN_00dd9e90(unsigned int a, uintptr_t b, unsigned int c, int d, unsigned int e);
};

// Locks criticalSection, writes values through config when present, and returns true if config is absent or the returned first character is zero.
// @fnv 0x00dd9e90
bool SecondaryDisplay::FUN_00dd9e90(unsigned int a, uintptr_t b, unsigned int c, int d, unsigned int e)
{
    EnterCriticalSection(criticalSection);
    if (config)
    {
        uintptr_t a2 = a;
        reinterpret_cast<::hkOArchive_2 *>((config))->WriteInt(FUN_00dd9d70() + 0x2d);
        reinterpret_cast<::FUN_00d605d0_class *>((config))->FUN_00d605d0(5);
        reinterpret_cast<::FUN_00dd9da0_cls *>((reinterpret_cast<FUN_00dd9da0_owner*>((char*)this - 8)))->ApplyItemList((::ItemList *)(a2));
        reinterpret_cast<::S_00dda740 *>((config))->WriteTransform((*(const ::S_00dda740_Transform *)(b)));
        ::FUN_00d60960((const float *)(config));
        reinterpret_cast<::FUN_00d609a0_Class *>((config))->FUN_00d609a0((__int64)d, {});
        reinterpret_cast<::hkOArchive_2 *>((config))->WriteInt(e);
    }
    bool ok = config != 0 && ((const char *)(reinterpret_cast<::FUN_00d607e0_class *>((config))->ForwardValueToObject((intptr_t)(&a))))[0] != 0;
    LeaveCriticalSection(criticalSection);
    return !ok;
}
