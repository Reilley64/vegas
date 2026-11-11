
// src/staging/blk_00d60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "fnv/symbols_00c85000.h"
#include "havok/hkMemoryRouter.h"
#include "havok/InlineStorageString.h"
#include "fnv/symbols_00c90000.h"
#include <xmmintrin.h>
#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/Archive.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BufferOwner.h"
#include "fnv/decl/CC0280Writer.h"
#include "fnv/decl/D81340Cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00c90e00.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00d63280_cls.h"
#include "fnv/decl/FUN_00ddccb0_cls.h"
#include "fnv/decl/FUN_00ddf030_Class.h"
#include "fnv/decl/FUN_00de29b0.h"
#include "fnv/decl/FUN_00de8f10_Class.h"
#include "fnv/decl/HkHull.h"
#include "fnv/decl/S_00dd9380.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/fnv_00d7e740__ExportShape.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpContactPointViewer.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d2c000.h"
#include "fnv/symbols_00d63000.h"
#include "fnv/symbols_00d64000.h"
#include "fnv/symbols_00d68000.h"
#include "fnv/symbols_00d79000.h"
#include "fnv/symbols_00ddf000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010c8000.h"
#include "fnv/symbols_010c9000.h"
#include "fnv/symbols_010d1000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"
#include "../../include/layout_support.h"
#include <stdarg.h>
#include <cmath>
#include "fnv/decl/CMatrixOps.h"
#include "fnv/decl/D625A0CharArray.h"
#include "fnv/decl/FUN_005611c0_t.h"
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/FUN_00827200_class.h"
#include "fnv/decl/FUN_00cb20b0_shell.h"
#include "fnv/decl/FUN_00cb21e0_shell.h"
#include "fnv/decl/FUN_00de9080_Class.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/decl/S_00cd4b60.h"
#include "fnv/decl/hkMatrix3.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00d60000.h"
#include "fnv/symbols_00d61000.h"
#include "fnv/symbols_00d62000.h"
#include "fnv/symbols_00d6a000.h"
#include "fnv/symbols_00d6b000.h"
#include "fnv/symbols_00d72000.h"
#include "fnv/symbols_00d74000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_0126a000.h"
#include "fnv/symbols_simd.h"
#include "fnv/symbols_00dcf000.h"
#include <math.h>


struct Registry_00dd9380
{
    void* Register(char const*, void(__cdecl*)(void));
};


// @fnv 0x00d68800
void RegisterContactPointsInactive()
{
    Registry_00dd9380* reg = (Registry_00dd9380*)::DAT_01269cd0;
    DAT_01269008 = ((void *)(reinterpret_cast<::S_00dd9380 *>((reg))->FUN_00dd9380("Contact Points (Inactive)", (intptr_t)(((void (&)())::FUN_00d687c0)))));
}

namespace fnv_00d688d0 {
struct Registry_00dd9380_StandIn
{
};
// @fnv 0x00d688d0
int RegisterContactPointsActive()
{
    ::DAT_0126900c = (int)reinterpret_cast<::S_00dd9380 *>(((*reinterpret_cast<::fnv_00d688d0::Registry_00dd9380_StandIn * *>(&::DAT_01269cd0))))->FUN_00dd9380("Contact Points (Active)", (intptr_t)(((void (&)())::fnv_00d68890::FUN_00d68890)));
    return ::DAT_0126900c;
}
}  // namespace fnv_00d688d0

// Constructor of the class whose vftables live at 0x010d1fb0 / 0x010d1f90 /
// 0x010d1f80 / 0x010d1f70: it calls the immediate base constructor and then
// installs the derived vftable pointers for the four base sub-objects.
extern int DAT_010d1fb0;
extern int DAT_010d1f90;
extern int DAT_010d1f80;
extern int DAT_010d1f70;

struct FUN_00d68770_cls
{
    int* m_pVtbl00;
    int m_unk04;
    int* m_pVtbl08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int* m_pVtbl20;
    int m_unk24;
    int* m_pVtbl28;

    void BaseConstruct(int aParam, int aFlags);
    FUN_00d68770_cls* Construct(intptr_t aParam);
};

// @fnv 0x00d68770
FUN_00d68770_cls* FUN_00d68770_cls::Construct(intptr_t aParam)
{
    new ((void *)this) struct ::FUN_00de29b0((void *)(aParam), (void *)(0xff008000));
    m_pVtbl00 = &DAT_010d1fb0;
    m_pVtbl08 = &DAT_010d1f90;
    m_pVtbl20 = &DAT_010d1f80;
    m_pVtbl28 = &DAT_010d1f70;
    return this;
}

// @fnv 0x00d687b0
void* FUN_00d687b0(char* a1)
{
    return a1 + 0x34;
}

// A Havok viewer as its create function sees it: the hkProcess interface follows
// the hkReferencedObject base (the header in include/havok clashes with this unit's
// own hkVector4 and hkStringPtr), and create returns that interface.
struct D60ReferencedObject
{
    virtual void D60ReferencedObject_v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct D60ViewerProcess
{
    virtual void D60ViewerProcess_v00();
};
struct D60Viewer : D60ReferencedObject, D60ViewerProcess
{
};
static inline void* D60ProcessOf(void* pViewer)
{
    return static_cast<D60ViewerProcess*>(static_cast<D60Viewer*>(pViewer));
}

struct FnvCpu_FUN_00d687c0_CpuBlock;
struct FnvCpu_FUN_00d687c0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d687c0_CpuBlock* Construct(uintptr_t value);
};
// @fnv 0x00d687c0
void* __cdecl FUN_00d687c0(uintptr_t value)
{
    hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
    FnvCpu_FUN_00d687c0_CpuBlock* block = static_cast<FnvCpu_FUN_00d687c0_CpuBlock*>(holder->m_heap->blockAlloc(52));
    block->size = 52;
    block = ((::FnvCpu_FUN_00d687c0_CpuBlock *)(reinterpret_cast<::FUN_00d68770_cls *>((block))->Construct(value)));
    return D60ProcessOf(block);
}

extern "C" int DAT_010d203c;
extern "C" int DAT_010d201c;
extern "C" int DAT_010d200c;
extern "C" int DAT_010d1ffc;


struct FUN_00d68840_cls
{
    void* m_p00;
    int m_i04;
    void* m_p08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    void* m_p20;
    int m_i24;
    void* m_p28;

    void* Init(intptr_t a);
};

// @fnv 0x00d68840
void* FUN_00d68840_cls::Init(intptr_t aiValue)
{
    new ((void *)(aiValue)) struct ::FUN_00de29b0((void *)(0xff0000ff), {});
    m_p00 = (void*)&DAT_010d203c;
    m_p08 = (void*)&DAT_010d201c;
    m_p20 = (void*)&DAT_010d200c;
    m_p28 = (void*)&DAT_010d1ffc;
    return this;
}

// hkpActiveContactPointViewer (Havok Physics) - virtual at vftable offset 0x0c
// of the primary base (complete-object base offset 0) and at slot 11 of the
// base that lives at complete-object offset +0x08.
//
// The routine ignores `this` entirely and converts its single 4-byte stack
// argument into a pointer to the sub-object that sits 0x28 bytes further up.
//
// Original bytes:
//   00d68880  8b 44 24 04   mov eax, dword ptr [esp+4]
//   00d68884  83 c0 28      add eax, 0x28
//   00d68887  c2 04 00      ret 4

// @fnv 0x00d68880
void* FUN_00d68880(void* pObject)
{
    return (void*)((char*)pObject + 0x28);
}

namespace fnv_00d68890 {
struct FNV_Buffer
{
    int unk00;
    unsigned short m_w04;
    unsigned short m_w06;
    int unk08;

};


// @fnv 0x00d68890
void* __cdecl FUN_00d68890(int aiArg)
{
    hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
    hkMemoryAllocator* allocator = holder->m_heap;
    FNV_Buffer* pBuffer = (FNV_Buffer*)allocator->blockAlloc(0x34);
    pBuffer->m_w04 = 0x34;
    void* r = reinterpret_cast<::FUN_00d68840_cls *>((pBuffer))->Init(aiArg);
    return ::D60ProcessOf(r);
}
}  // namespace fnv_00d68890

// FUN_00d688f0 : tiny global getter.
// Reads the 4-byte global at DAT_0126900c and returns it in eax.


// @fnv 0x00d688f0
int __cdecl FUN_00d688f0()
{
    return DAT_0126900c;
}

namespace fnv_00d68910 {

class D68910Object
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    ~D68910Object();
    D68910Object* DestroyAndFree(unsigned int uiFlags);
};

// @fnv 0x00d68910
D68910Object* D68910Object::DestroyAndFree(unsigned int uiFlags)
{
    reinterpret_cast<::hkpContactPointViewer *>((this))->DestroyContactPointViewer();
    if (uiFlags & 1)
        hkMemoryRouter::getInstance().heap().blockFree(this, m_usMemSizeAndFlags);
    return this;
}
}  // namespace fnv_00d68910


// @fnv 0x00d6ade0
void* __cdecl FUN_00d6ade0()
{
    return &(*reinterpret_cast<char *>(&::g_0126905c));
}

struct S_00d6adf0_Obj
{
    virtual void vfn00(int arg);
};
// @fnv 0x00d6adf0
void __cdecl FUN_00d6adf0(S_00d6adf0_Obj* obj)
{
    obj->vfn00(0);
}


// @fnv 0x00d6ae00
int* __cdecl FUN_00d6ae00()
{
    return &(*reinterpret_cast<int *>(&::g_0126908c));
}

struct FUN_00c90e00_Obj
{
    void FUN_00c90e00(int value);
};

// @fnv 0x00d6ae90
void __cdecl FUN_00d6ae90(FUN_00c90e00_Obj* pObj, int iValue)
{
    if (pObj != 0)
    {
        new ((void *)(pObj)) ::FUN_00c90e00(iValue);
    }
}

// 13-byte cdecl forwarder: loads the object pointer, fetches its vtable and
// calls the first virtual slot with a literal 0 argument.
struct VtblForwarder
{
    virtual int v0(int);
};

// @fnv 0x00d6aeb0
int __cdecl FUN_00d6aeb0(VtblForwarder* p)
{
    return p->v0(0);
}


// @fnv 0x00d6aee0
void* __cdecl FUN_00d6aee0()
{
    return &(*reinterpret_cast<int *>(&::g_01269104));
}

struct ResultFlag
{
    bool value;
    ResultFlag(bool flag) : value(flag)
    {}
    operator bool() const
    {
        return value;
    }
    ResultFlag& operator=(bool flag)
    {
        value = flag;
        return *this;
    }
};
struct MotionSettings
{
    float value0;
    float value1;
    float value2;
    float value3;
    float value4;
    float value5;
    float value6;
    float value7;
    float value8;
    float value9;
    float value10;
    float value11;
    ResultFlag IsValid();
};
// Checks that value0 through value4 lie in [0,1] and that value5 through value11 are non-negative, returning the combined result.
// @fnv 0x00d6b1c0
ResultFlag MotionSettings::IsValid()
{
    ResultFlag result(true);
    result = result && value0 >= 0.0f && value0 <= 1.0f;
    result = result && value1 >= 0.0f && value1 <= 1.0f;
    result = result && value2 >= 0.0f && value2 <= 1.0f;
    result = result && value3 >= 0.0f && value3 <= 1.0f;
    result = result && value4 >= 0.0f && value4 <= 1.0f;
    result = result && value5 >= 0.0f;
    result = result && value6 >= 0.0f;
    result = result && value7 >= 0.0f;
    result = result && value8 >= 0.0f;
    result = result && value9 >= 0.0f;
    result = result && value10 >= 0.0f;
    result = result && value11 >= 0.0f;
    return result;
}

struct D6C180Command
{
    union
    {
        float m_fValue;
        unsigned char m_ucType;
    };
    unsigned char m_ucFlag;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
};


// @fnv 0x00d6c180
void WriteCommand(D6C180Command** ppkCursor, unsigned char ucFlag)
{
    D6C180Command* pkCommand = *ppkCursor;
    pkCommand->m_ucFlag = ucFlag;
    pkCommand->m_fValue = (float)(pkCommand->m_fValue + ::DAT_010c9300);
    pkCommand->m_ucType = 3;
    *ppkCursor = pkCommand + 1;
}

struct Inner
{
    void Tail();
};

struct FUN_00d76f90_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    void FUN_00d76f90();
};

// @fnv 0x00d76f90
void FUN_00d76f90_cls::FUN_00d76f90()
{
    reinterpret_cast<::HkHull *>((m_08))->FUN_00d80f90(*(::hkArray<int> *)nullptr, *(::hkArray<int> *)nullptr);
}

namespace fnv_00d68820 {

// @fnv 0x00d68820
int FUN_00d68820()
{
    return (*reinterpret_cast<int *>(&::DAT_01269008));
}
}  // namespace fnv_00d68820


struct hkFinishLoadedObjectFlagD6A
{
    int m_bFinishing;
};

template <class T> class hkSmallArrayD6A
{
  public:
    hkSmallArrayD6A() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000)
    {}

    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};

class hkMemberD6A
{
  public:
    hkMemberD6A(hkFinishLoadedObjectFlagD6A flag) throw();

    int unk00;
    int unk04;
    int unk08;
};

class hkBaseD6A
{
  public:
    __forceinline hkBaseD6A()
    {}
    virtual ~hkBaseD6A();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
};

class hkDerivedD6A : public hkBaseD6A
{
  public:
    __forceinline hkDerivedD6A(hkFinishLoadedObjectFlagD6A flag) : m_kMemberDescriptor(flag)
    {
        m_iType = -16;
    }
    virtual ~hkDerivedD6A();

    hkSmallArrayD6A<int> m_ppData;
    hkMemberD6A m_kMemberDescriptor;
    int m_iType;
};

// Placement-constructs an hkDerivedD6A at pvObject with a finish-loaded flag built from iFinishing, if pvObject is non-null.
// @fnv 0x00d6ae10
void __cdecl ConstructHkDerived(void* pvObject, int iFinishFlag)
{
    if (pvObject)
    {
        hkFinishLoadedObjectFlagD6A flag;
        flag.m_bFinishing = iFinishFlag;
        new (pvObject) hkDerivedD6A(flag);
    }
}

struct hkFinishLoadedObjectFlagD605
{
    int m_bFinishing;
};

class hkReferencedObjectD605
{
  public:
    hkReferencedObjectD605(hkFinishLoadedObjectFlagD605 flag)
    {}
    virtual ~hkReferencedObjectD605();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00d60540 : public hkReferencedObjectD605
{
  public:
    FUN_00d60540(hkFinishLoadedObjectFlagD605 flag);
    virtual ~FUN_00d60540();
};

// @fnv 0x00d60540
FUN_00d60540::FUN_00d60540(hkFinishLoadedObjectFlagD605 flag) : hkReferencedObjectD605(flag)
{}


struct D60590Callback
{
    void FUN_00c905b0();
};

struct D60590Object
{
    int* vtable;
    int unk04;
    D60590Callback* callback;

    void FUN_00d60590();
};

// @fnv 0x00d60590
void D60590Object::FUN_00d60590()
{
    vtable = &DAT_010d14f8;
    reinterpret_cast<::hkReferencedObjectC905 *>((callback))->FUN_00c905b0();
    vtable = &(*reinterpret_cast<int *>(&::DAT_0102e388));
}

namespace fnv_00d60860 {
struct HKMemoryManager
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(void*);
};
struct FUN_00d60860
{
    char* m_pVtbl;
    unsigned char m_uc04;
    unsigned short m_usSize;
    void* m_pData;
    unsigned char m_ucType;
    FUN_00d60860(void* pData, unsigned char ucType);
};
// Sets the vtable, size to 1 and type, and stores the result of DAT_01268364->v4(pData) in m_pData.
// @fnv 0x00d60860
FUN_00d60860::FUN_00d60860(void* pData, unsigned char ucType)
{
    m_usSize = 1;
    m_pVtbl = &(*reinterpret_cast<char *>(&::DAT_010d14f8));
    m_ucType = ucType;
    m_pData = (*reinterpret_cast<::fnv_00d60860::HKMemoryManager * *>(&::DAT_01268364))->v4(pData);
}
}  // namespace fnv_00d60860


// @fnv 0x00d60900
void FUN_00d60900(char* p)
{
    reinterpret_cast<::Archive *>((&p))->WriteSwapped((const void *)(2), 1, {});
}

struct FUN_00d60600_class
{
    void WriteSwapped(int a, int b, int c);
    void FUN_00d60b20(intptr_t a, int b);
};

// @fnv 0x00d60b20
void FUN_00d60600_class::FUN_00d60b20(intptr_t a, int aiValue)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped((const void *)(a), 8, aiValue);
}

struct FUN_00d61470_Class
{
    void* FUN_00d61470();
};

// @fnv 0x00d61470
void* FUN_00d61470_Class::FUN_00d61470()
{
    return this;
}


class hkStringBufD614
{
  public:
    char* m_data;

    int FindSubstring(const char* pcNeedle, int iStartIndex, int iEndIndex) throw();
};

// Searches m_data from iStartIndex for pcNeedle and returns its offset, or -1 if not found.
// @fnv 0x00d61480
int hkStringBufD614::FindSubstring(const char* pcNeedle, int iStartIndex, int iEndIndex) throw()
{
    char* pData = m_data;
    const char* p = ::fnv_00cb1130::FUN_00cb1130(pData + iStartIndex, pcNeedle);
    if (p)
        return static_cast<int>(p - m_data);
    return -1;
}

inline char toLowerD614(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

struct hkStringD614
{
    const char* m_kStringBuffer;

    int FindCaseInsensitive(const char* needle) const;
};

// Returns the index of the first case-insensitive occurrence of needle in the string, or -1 if not found.
// @fnv 0x00d614b0
int hkStringD614::FindCaseInsensitive(const char* needle) const
{
    const char* str = m_kStringBuffer;
    for (int i = 0; str[i] != 0; ++i)
    {
        int j;
        for (j = 0; needle[j] != 0; ++j)
        {
            if (toLowerD614(str[i + j]) != toLowerD614(needle[j]))
                break;
        }
        if (needle[j] == 0)
            return i;
    }
    return -1;
}

struct FUN_00d61520_cls
{
    const char* m_pcData;
    int FindOffset(intptr_t a, int b, int c);
};
// @fnv 0x00d61520
int FUN_00d61520_cls::FindOffset(intptr_t aiValue, int aiUnused1, int aiUnused2)
{
    int esi = -1;
    const char* r = ::fnv_00cb1130::FUN_00cb1130(m_pcData, (const char *)(aiValue));
    if (r != 0)
    {
        do
        {
            esi = (int)(r - m_pcData);
            r = ::fnv_00cb1130::FUN_00cb1130(r + 1, (const char *)(aiValue));
        } while (r != 0);
    }
    return esi;
}

struct FnvString
{
    const char* text;
    int FUN_00d61560(const char* other);
};

// @fnv 0x00d61560
int FnvString::FUN_00d61560(const char* other)
{
    unsigned int i = 0;
    while (text[i] != 0)
    {
        if (other[i] == 0)
            break;
        if (text[i] != other[i])
            return 0;
        ++i;
    }
    return other[i] == 0;
}

inline char toLowerD615(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

struct hkStringD615
{
    const char* m_kStringBuffer;

    int FUN_00d615a0(const char* other) const;
};

// @fnv 0x00d615a0
int hkStringD615::FUN_00d615a0(const char* other) const
{
    for (int i = 0; m_kStringBuffer[i] != 0; ++i)
    {
        if (other[i] == 0)
            return 1;
        if (toLowerD615(m_kStringBuffer[i]) != toLowerD615(other[i]))
            return 0;
    }
    return 1;
}

struct FNV_00d61600_Buffer
{
    unsigned char* data;
    int length;
    int FindCharacter(unsigned char character, int start, int limit);
};
// Scans data from start up to limit (clamped to length-1) and returns the index of the first byte equal to character, or -1 if none is found.
// @fnv 0x00d61600
int FNV_00d61600_Buffer::FindCharacter(unsigned char character, int start, int limit)
{
    int end = limit;
    int last = length - 1;
    if (end >= last)
        end = last;
    for (int index = start; index < end; ++index)
    {
        if (data[index] == character)
            return index;
    }
    return -1;
}

struct FUN_00d61640_cls
{
    char* m_data;
    int m_fRestLength;

    int FindLastCharInRange(char c, int startIndex, int endIndex);
};

// Searches m_data backwards from endIndex-1 down to startIndex for character c and returns its index, or -1 if not found.
// @fnv 0x00d61640
int FUN_00d61640_cls::FindLastCharInRange(char c, int startIndex, int endIndex)
{
    if (endIndex > m_fRestLength - 1)
        endIndex = m_fRestLength - 1;

    for (int i = endIndex - 1; i >= startIndex; --i)
    {
        if (m_data[i] == c)
            return i;
    }
    return -1;
}

struct FUN_00d61680_Obj
{
    const char* unk00;
    int FUN_00d61680(const char* pcValue);
    int FUN_00d616e0(const char* pcValue);
};

// @fnv 0x00d61680
int FUN_00d61680_Obj::FUN_00d61680(const char* pcValue)
{
    return ::fnv_00cb0fa0::FUN_00cb0fa0(unk00, pcValue);
}

void __cdecl CompareStringsCaseInsensitive(void* pvOwner, int iValue);

struct FUN_00d616a0_cls
{
    void* m_pOwnerObject;

    void FUN_00d616a0(int iValue);
};

// @fnv 0x00d616a0
void FUN_00d616a0_cls::FUN_00d616a0(int iValue)
{
    CompareStringsCaseInsensitive(m_pOwnerObject, iValue);
}

// @fnv 0x00d616e0
int FUN_00d61680_Obj::FUN_00d616e0(const char* pcValue)
{
    return FUN_00d61680(pcValue) == 0;
}

struct FUN_00d61700_cls
{
    char* m_00;
    int m_04;
    int EndsWith(char* s);
};
// @fnv 0x00d61700
int FUN_00d61700_cls::EndsWith(char* aString)
{
    int len = ::fnv_00cb10d0::FUN_00cb10d0(aString);
    if (len > m_04 - 1)
    {
        return 0;
    }
    int start = m_04 - len - 1;
    for (int i = 0; i < len; ++i)
    {
        if (m_00[start + i] != aString[i])
        {
            return 0;
        }
    }
    return 1;
}


static inline int tolower_custom(char c)
{
    if ((unsigned char)(c - 'A') <= 25)
        return c + 0x20;
    return c;
}

struct FUN_00d61750_cls
{
    char* m_data;
    int m_fRestLength;

    int EndsWithIgnoreCase(const char* suffix);
};

// Case-insensitively compares the tail of m_data with suffix, returning 1 if it matches and fits within the buffer length.
// @fnv 0x00d61750
int FUN_00d61750_cls::EndsWithIgnoreCase(const char* suffix)
{
    int len = ::fnv_00cb10d0::FUN_00cb10d0(suffix);
    if (len > m_fRestLength - 1)
        return 0;

    int offset = m_fRestLength - len - 1;
    for (int i = 0; i < len; ++i)
    {
        char c1 = tolower_custom(m_data[offset + i]);
        char c2 = tolower_custom(suffix[i]);
        if (c1 != c2)
            return 0;
    }
    return 1;
}

struct FUN_00d617d0_cls
{
    char* m_p00;
    int m_i04;
    void RemoveFront(int count);
};
// Removes count bytes from the front of the buffer by shifting the remaining bytes down and reducing m_i04.
// @fnv 0x00d617d0
void FUN_00d617d0_cls::RemoveFront(int count)
{
    if (count > 0)
    {
        m_i04 -= count;
        int remaining = m_i04;
        char* destination = m_p00;
        char* source = destination + count;
        if (remaining > 0)
        {
            for (int i = 0; i < remaining; ++i)
            {
                destination[i] = source[i];
            }
        }
    }
}

struct hkMathD618
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
};

class hkStringBufD618
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int FindLastCharInRange(char c, int iStartIndex, int iEndIndex) const;
    void RemoveFront(int n);
    void TrimToFileName();
};

// Finds the last '\\' or '/' in the buffer and, if found, truncates the string to start just after it.
// @fnv 0x00d61800
void hkStringBufD618::TrimToFileName()
{
    int iLastSeparator =
        hkMathD618::max2(reinterpret_cast<::FUN_00d61640_cls *>((void *)this)->FindLastCharInRange('\\', 0, 0x7fffffff), reinterpret_cast<::FUN_00d61640_cls *>((void *)this)->FindLastCharInRange('/', 0, 0x7fffffff));
    if (iLastSeparator >= 0)
        reinterpret_cast<::FUN_00d617d0_cls *>(this)->RemoveFront(iLastSeparator + 1);
}

struct hkStringD618
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getLength() const
    {
        return m_iElementCount - 1;
    }

    int ReplaceChar(char from, char to, int replaceType);
};

// @fnv 0x00d61840
int hkStringD618::ReplaceChar(char from, char to, int replaceType)
{
    int replaced = 0;
    for (int i = 0; i < getLength(); i++)
    {
        if (m_data[i] == from)
        {
            m_data[i] = to;
            replaced = 1;
            if (replaceType == 0)
                break;
        }
    }
    return replaced;
}

namespace fnv_00d61890 {
struct hkStringD618
{
    static int toLower(char c)
    {
        return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
    }
};

template <class T> class hkArrayD618
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkStringBufD618
{
  public:
    hkArrayD618<char> m_kStringBuffer;

    void ToLower();
};

// Converts every character of the string buffer except the last to lowercase in place.
// @fnv 0x00d61890
void hkStringBufD618::ToLower()
{
    for (int i = 0; i < m_kStringBuffer.GetLogicalSize() - 1; i++)
        m_kStringBuffer[i] = hkStringD618::toLower(m_kStringBuffer[i]);
}
}  // namespace fnv_00d61890

struct FUN_00d62630_Obj
{
    void FUN_00d62630(int a1, int a2, int a3, int a4);
};
struct FUN_00d61df0_cls
{
    int unk00;
    int unk04;
    FUN_00d61df0_cls* FUN_00d61df0(intptr_t arg);
};

namespace hkRouterD620 {
}

class hkStringBufD620
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewCap, sizeof(char));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkMemoryRouter::getInstance().temp(), n);
        m_iElementCount = n;
    }

    void Assign(void* src, int len);
};

// Reserves len+1 bytes, null-terminates the buffer at index len, then copies len bytes from src into m_data.
// @fnv 0x00d62020
void hkStringBufD620::Assign(void* src, int len)
{
    SetSizeAndGrow(len + 1);
    m_data[len] = 0;
    ::fnv_00d2caa0::FUN_00d2caa0(m_data, src, len);
}


struct D62080_Object
{
    unsigned char* m_data;
    int m_uiItemCount;
    unsigned int m_pRayCursor;

    void FUN_00d62080(intptr_t param2, int param3);
};

// @fnv 0x00d62080
void D62080_Object::FUN_00d62080(intptr_t aData, int param3)
{
    if (param3 < 0)
        param3 = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(aData));

    int oldCount = m_uiItemCount;
    oldCount--;

    int index = oldCount + param3;
    int newCount = index + 1;

    hkMemoryRouter* audio = &hkMemoryRouter::getInstance();
    void* audioValue = audio->m_temp;

    int capacity = (int)(m_pRayCursor & 0x3fffffff);
    if (capacity < newCount)
    {
        capacity *= 2;
        if (newCount >= capacity)
            capacity = newCount;

        ::FUN_00c908c0((::SpawnedObject *)(audioValue), (::SpawnedArray *)(void *)(this), capacity, 1);
    }

    m_uiItemCount = newCount;
    m_data[index] = 0;

    ::fnv_00d2caa0::FUN_00d2caa0(m_data + oldCount, (void *)(aData), param3);
}

struct FUN_00d62100_Class
{
    int FUN_00d62630(int context, int first, int second, int third);
    int FUN_00d62100(int first, intptr_t second, int third);
};
struct hkStringPtr
{
    const char* m_stringAndFlags;
    const char* cString() const
    {
        return (const char*)((uintptr_t)m_stringAndFlags & ~(uintptr_t)1);
    }
};

struct FUN_00d623a0
{
    char* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;
    char m_kStorage;

    void FUN_00d61c10(const char* str);

    FUN_00d623a0(const hkStringPtr& str);
};

// @fnv 0x00d623a0
FUN_00d623a0::FUN_00d623a0(const hkStringPtr& str)
{
    m_data = &m_kStorage;
    m_iElementCount = 0;
    m_iCapacityState = 0x80000080;
    FUN_00d61c10(str.cString());
}

struct FUN_00d62100_Obj
{
    int FUN_00d62100(int a, intptr_t b, int c);
};
struct FUN_00d62580_Cls
{
    int FUN_00d62580(intptr_t a, int b);
};
// @fnv 0x00d62580
int FUN_00d62580_Cls::FUN_00d62580(intptr_t a, int b)
{
    return reinterpret_cast<::FUN_00d62100_Class *>((reinterpret_cast<FUN_00d62100_Obj*>(this)))->FUN_00d62100(0, a, b);
}

class hkObjectD626
{
  public:
    int ReplaceRange(intptr_t a, int b, int c, intptr_t d, int e);
    int FUN_00d62630(intptr_t a, int b, intptr_t d, int e);
};
// Computes a value from arg and calls FUN_00d62630 with the temp allocator, unk04-1, arg and that value; returns this.
// @fnv 0x00d61df0
FUN_00d61df0_cls* FUN_00d61df0_cls::FUN_00d61df0(intptr_t arg)
{
    int ebx = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(arg));
    int ebp = unk04;
    hkMemoryRouter* router = &hkMemoryRouter::getInstance();
    reinterpret_cast<::hkObjectD626 *>((reinterpret_cast<FUN_00d62630_Obj*>(this)))->FUN_00d62630((intptr_t)router->m_temp, ebp - 1, arg, ebx);
    return this;
}
// @fnv 0x00d62100
int FUN_00d62100_Class::FUN_00d62100(int first, intptr_t second, int third)
{
    if (third < 0)
        third = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(second));
    hkMemoryRouter* router = &hkMemoryRouter::getInstance();
    return reinterpret_cast<::hkObjectD626 *>(this)->FUN_00d62630((intptr_t)router->m_temp, first, second, third);
}

// @fnv 0x00d62630
int hkObjectD626::FUN_00d62630(intptr_t a, int b, intptr_t d, int e)
{
    return ReplaceRange(a, b, 0, d, e);
}

struct FUN_00ddccb0_Obj
{
    void FUN_00ddccb0(int a1);
};

struct FUN_00d62ef0_cls
{
    int* unk00;
    int unk04;
    int* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int* unk20;
    int unk24;
    unsigned char unk28;

    FUN_00d62ef0_cls* FUN_00d62ef0(intptr_t aParam, unsigned char aValue);
};

extern int DAT_010d1720;
extern int DAT_010d1700;
extern int DAT_010d16f0;

// Calls FUN_00ddccb0 with aParam, then stores three global addresses and aValue into the object's fields and returns this.
// @fnv 0x00d62ef0
FUN_00d62ef0_cls* FUN_00d62ef0_cls::FUN_00d62ef0(intptr_t aParam, unsigned char aValue)
{
    new ((void *)(((FUN_00ddccb0_Obj*)this))) ::FUN_00ddccb0_cls((*(const ::BDDCCB0Array< ::BDDCCB0ProcessContext *> *)(aParam)));
    unk00 = &DAT_010d1720;
    unk08 = &DAT_010d1700;
    unk20 = &DAT_010d16f0;
    unk28 = aValue;
    return this;
}

struct HeapBlockMetadata
{
    unsigned int flags;
    unsigned short size;
    unsigned short reserved;
    HeapBlockMetadata* FUN_00d62ef0(void* data, unsigned int enabled);
};
// @fnv 0x00d62f60
void* __cdecl AllocateRecordWithData(void* data)
{
    hkMemoryRouter* memory = &hkMemoryRouter::getInstance();
    HeapBlockMetadata* record = static_cast<HeapBlockMetadata*>(memory->m_heap->blockAlloc(44));
    record->size = 44;
    HeapBlockMetadata* result = ((::HeapBlockMetadata *)(reinterpret_cast<::FUN_00d62ef0_cls *>((record))->FUN_00d62ef0((intptr_t)(data), 1)));
    return D60ProcessOf(result);
}

struct Base1_d632c0
{
    virtual void vfn1();
    unsigned short size;
    unsigned short ref;
};

struct Base2_d632c0
{
    virtual void vfn2();
};

struct Obj_d632c0 : Base1_d632c0, Base2_d632c0
{
    Obj_d632c0* FUN_00d63280(int a, const void* b);
};

// @fnv 0x00d632c0
Base2_d632c0* FUN_00d632c0(const void* aiValue)
{
    hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
    Obj_d632c0* obj = (Obj_d632c0*)holder->m_heap->blockAlloc(0x54);
    obj->size = 0x54;
    obj = ((::Obj_d632c0 *)(reinterpret_cast<::FUN_00d63280_cls *>((obj))->FUN_00d63280(0, aiValue)));
    return obj;
}

struct hkContainerD633
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    void** m_items;
    int m_uiItemCount;
};

struct hkListenerD633
{
    virtual void v00(void* p);
    virtual void v04(void* p);
};

struct hkObjD633
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkListenerD633 m_kListener;
    hkContainerD633* m_container;

    void FUN_00d63300();
};

// Iterates the container's items and passes each to the listener's v04 callback when m_container is set.
// @fnv 0x00d63300
void hkObjD633::FUN_00d63300()
{
    if (m_container)
    {
        for (int i = 0; i < m_container->m_uiItemCount; i++)
            m_kListener.v04(m_container->m_items[i]);
    }
}

class FUN_00ddf050_cls
{
  public:
    virtual ~FUN_00ddf050_cls() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addObject(const char* pcName, const void* pvObject, int iFlags) throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char* m_data;
    int m_iElementCount;

    void ClearContainer() throw();
    void FUN_00ddf030(int i) throw();
    void FUN_00ddf040() throw();

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    bool hasData() const
    {
        return m_iElementCount > 0 && m_data;
    }
    char* getData() const
    {
        return m_iElementCount > 0 ? m_data : 0;
    }
};

class hkDisplayHandlerD633
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void V18() throw();
    virtual void V1C() throw();
    virtual void V20() throw();
    virtual void V24() throw();
    virtual void V28() throw();
    virtual void V2C() throw();
    virtual void V30() throw();
    virtual void V34() throw();
    virtual void V38() throw();
    virtual void V3C() throw();
    virtual void WriteOutput(const char* pcData, int iLength) throw();
};

class hkpWorldD633;

class hkpPhysicsContextD633
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
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    hkpWorldD633** m_ppWorlds;
    int m_numWorlds;
};

class FUN_00d63370_class
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkDisplayHandlerD633* m_pDisplayHandler;
    int unk14;
    int unk18;
    hkpPhysicsContextD633* m_iValueAtOffset0C;
    FUN_00ddf050_cls m_pStreamWriter;

    void UpdatePhysicsDebugDisplay(float fFrameTime) throw();
};

// Rebuilds the debug display buffer with each physics world, then passes the buffer and its length to the display handler.
// @fnv 0x00d63370
void FUN_00d63370_class::UpdatePhysicsDebugDisplay(float fFrameTime) throw()
{
    m_pStreamWriter.ClearContainer();
    reinterpret_cast<::FUN_00ddf030_Class *>(&(m_pStreamWriter))->FUN_00ddf030(0);
    for (int i = 0; i < m_iValueAtOffset0C->m_numWorlds; i++)
        m_pStreamWriter.addObject("World", m_iValueAtOffset0C->m_ppWorlds[i], 0);
    ::fnv_00ddf040::FUN_00ddf040((char *)&(m_pStreamWriter), {});
    if (m_pStreamWriter.hasData())
        m_pDisplayHandler->WriteOutput(m_pStreamWriter.getData(), m_pStreamWriter.GetLogicalSize());
}

namespace fnv_00d63400 {
class FUN_00dd9380_class
{
  public:
};



// @fnv 0x00d63400
void __cdecl InitWorldMemory()
{
    (*reinterpret_cast<void * *>(&::DAT_01268fc8)) =
        ((void *)(reinterpret_cast<::S_00dd9380 *>((reinterpret_cast<FUN_00dd9380_class*>(::DAT_01269cd0)))->FUN_00dd9380("World Memory", (intptr_t)((void*)((void (&)())::FUN_00d632c0)))));
}
}  // namespace fnv_00d63400

// @fnv 0x00d63420
int __cdecl FUN_00d63420()
{
    return DAT_01268fc8;
}

class FUN_00d63340
{
  public:
    virtual ~FUN_00d63340() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter::getInstance().heap()
            .blockFree(p, static_cast<FUN_00d63340*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d63340* Destroy(unsigned int uiFlags) throw();
};

// Calls the destructor, and if bit 0 of uiFlags is set, frees the object through operator delete; returns this.
// @fnv 0x00d63450
FUN_00d63340* FUN_00d63340::Destroy(unsigned int uiFlags) throw()
{
    this->FUN_00d63340::~FUN_00d63340();
    if (uiFlags & 1)
        FUN_00d63340::operator delete(this);
    return this;
}

class hkPart0D642
{
  public:
    virtual ~hkPart0D642() throw();
    int unk04;
};

class hkPart8D642
{
  public:
    virtual void p8() = 0;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class hkPart20D642
{
  public:
    virtual void p20() = 0;
    int unk24;
};

class hkBaseD642 : public hkPart0D642, public hkPart8D642, public hkPart20D642
{
};

class FUN_00ddccb0 : public hkBaseD642
{
  public:
    FUN_00ddccb0(void* p) throw();
};

class hkIfaceAD642
{
  public:
    virtual void a0() = 0;
};

class hkIfaceBD642
{
  public:
    virtual void b0() = 0;
};

template <class T> struct hkArrayD642
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayD642() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class FUN_00d64260 : public FUN_00ddccb0, public hkIfaceAD642, public hkIfaceBD642
{
  public:
    hkArrayD642<void*> m_ppData;

    FUN_00d64260(void* p) throw();
    virtual ~FUN_00d64260() throw();
    virtual void p8();
    virtual void p20();
    virtual void a0();
    virtual void b0();
};

// Constructs the object by forwarding p to the base constructor and default-initializing the void* array member.
// @fnv 0x00d64260
FUN_00d64260::FUN_00d64260(void* p) throw() : FUN_00ddccb0(p)
{}

struct FnvCpu_FUN_00d645f0_CpuBlock;
struct FnvCpu_FUN_00d645f0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d645f0_CpuBlock* FUN_00d64260(unsigned int value);
};
// @fnv 0x00d645f0
void* __cdecl FUN_00d645f0(uintptr_t value)
{
    hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
    FnvCpu_FUN_00d645f0_CpuBlock* block = static_cast<FnvCpu_FUN_00d645f0_CpuBlock*>(holder->m_heap->blockAlloc(60));
    block->size = 60;
    block = ((::FnvCpu_FUN_00d645f0_CpuBlock *)(new ((void *)(block)) ::FUN_00d64260((void *)(value))));
    return D60ProcessOf(block);
}

namespace fnv_00d64630 {
class FUN_00dd9380_class
{
  public:
};


// @fnv 0x00d64630
void __cdecl RegisterSweptTransformsTask()
{
    (*reinterpret_cast<void * *>(&::g_ptr_0x1268fd0)) =
        ((void *)(reinterpret_cast<::S_00dd9380 *>((reinterpret_cast<FUN_00dd9380_class*>(::DAT_01269cd0)))->FUN_00dd9380("Swept Transforms", (intptr_t)((void*)((void (&)())::FUN_00d645f0)))));
}
}  // namespace fnv_00d64630

struct FUN_00d65250_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    unsigned char unk60;
    unsigned char unk61;

    void FUN_00d65250(unsigned char value);
};

// @fnv 0x00d65250
void FUN_00d65250_cls::FUN_00d65250(unsigned char value)
{
    unk61 = value;
}

struct FnvCpu_FUN_00d65260_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned char unk64;
    unsigned char value;
    void FUN_00d65260(unsigned char arg0);
};
// @fnv 0x00d65260
void FnvCpu_FUN_00d65260_CpuObject::FUN_00d65260(unsigned char arg0)
{
    value = arg0;
}

struct FnvCpu_FUN_00d65270_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned char unk60;
    unsigned char unk61;
    unsigned char value;
    void FUN_00d65270(unsigned char arg0);
};
// @fnv 0x00d65270
void FnvCpu_FUN_00d65270_CpuObject::FUN_00d65270(unsigned char arg0)
{
    value = arg0;
}

struct FUN_00d65280_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    char unk60;
    char unk61;
    char unk62;
    bool m_63;

    void FUN_00d65280(bool bValue);
};

// @fnv 0x00d65280
void FUN_00d65280_cls::FUN_00d65280(bool bValue)
{
    m_63 = bValue;
}

struct FnvCpu_FUN_00d65290_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned char value;
    void FUN_00d65290(unsigned char arg0);
};
// @fnv 0x00d65290
void FnvCpu_FUN_00d65290_CpuObject::FUN_00d65290(unsigned char arg0)
{
    value = arg0;
}

// @fnv 0x00d6add0
void __cdecl FUN_00d6add0()
{}

extern "C" void __cdecl FUN_00d72e90();
// @fnv 0x00d73380
void __cdecl FUN_00d73380()
{
    FUN_00d72e90();
}

class FUN_00d733e0
{
  public:
    FUN_00d733e0();

    int m_iFirst;
    int m_iSecond;
    bool m_bEnableState;
};

// @fnv 0x00d733e0
FUN_00d733e0::FUN_00d733e0()
{
    m_iFirst = 0;
    m_iSecond = 0;
    m_bEnableState = true;
}

struct FUN_00d73400_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    void FUN_00d73400();
};

// @fnv 0x00d73400
void FUN_00d73400_cls::FUN_00d73400()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
    unk0C = 0;
}

class hkOstreamD734
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;


    hkOstreamD734(void* pvBuffer, int iSize)
    {
        new ((void *)this) ::FUN_00cb1600(pvBuffer, iSize);
    }
    ~hkOstreamD734()
    {
        reinterpret_cast<struct ::FUN_00cc00e0 *>(this)->FUN_00cc00e0::~FUN_00cc00e0();
    }
};

class hkErrorD734
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};

struct hkpTransformCollapseUtilResultsD734
{
    int m_iFirstResult;
    int m_iSecondResult;
    int m_iThirdResult;
    int m_iFourthResult;

    void PrintResults() throw();
};

// Logs four counters (collapsed shapes, removed identity transforms, specialized shapes, propagated transforms) via hkErrorD734::message.
// @fnv 0x00d73430
void hkpTransformCollapseUtilResultsD734::PrintResults() throw()
{
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        reinterpret_cast<::CC0280Writer *>(&((*(::hkOstreamD734 *)(reinterpret_cast<::SinkOwner *>(&(kStream))->FUN_00cc01c0("Number of collapsed shapes :")))))->WriteInt(m_iFirstResult);
        (*reinterpret_cast<::hkErrorD734 * *>(&::DAT_01268360))->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 57);
    }
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        reinterpret_cast<::CC0280Writer *>(&((*(::hkOstreamD734 *)(reinterpret_cast<::SinkOwner *>(&(kStream))->FUN_00cc01c0("Number of identity transforms removed : ")))))->WriteInt(m_iSecondResult);
        (*reinterpret_cast<::hkErrorD734 * *>(&::DAT_01268360))->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 58);
    }
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        reinterpret_cast<::CC0280Writer *>(&((*(::hkOstreamD734 *)(reinterpret_cast<::SinkOwner *>(&(kStream))->FUN_00cc01c0("Number of specialized transform shapes : ")))))->WriteInt(m_iThirdResult);
        (*reinterpret_cast<::hkErrorD734 * *>(&::DAT_01268360))->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 59);
    }
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        reinterpret_cast<::CC0280Writer *>(&((*(::hkOstreamD734 *)(reinterpret_cast<::SinkOwner *>(&(kStream))->FUN_00cc01c0("Number of propagated transforms to lists : ")))))->WriteInt(m_iFourthResult);
        (*reinterpret_cast<::hkErrorD734 * *>(&::DAT_01268360))->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 60);
    }
}

struct FnvCpu_FUN_00d76d80_CpuTarget
{
    void FUN_00d81340();
};
struct FnvCpu_FUN_00d76d80_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00d76d80_CpuTarget* target;
    void FUN_00d76d80();
};
// @fnv 0x00d76d80
void FnvCpu_FUN_00d76d80_CpuOwner::FUN_00d76d80()
{
    reinterpret_cast<::D81340Cls *>((target))->FUN_00d81340(*(::D81340Vec4 *)nullptr, *(::D81340Transform *)nullptr);
}

struct hkBoolD608
{
    unsigned char value;
    hkBoolD608(bool enabled = false) : value(enabled)
    {}
    hkBoolD608(const hkBoolD608& other) : value(other.value)
    {}
};
struct FUN_00d274c0
{
    void* unk00;
    unsigned short allocatedSize;
    FUN_00d274c0(int first, int second, hkBoolD608 enabled);
};
struct FUN_00d608a0
{
    void* vptr;
    unsigned short unk04;
    unsigned short count;
    FUN_00d274c0* child;
    unsigned char mode;
    FUN_00d608a0(int first, int second, unsigned char mode);
};
// Initializes count, vptr, and mode, then allocates and constructs a FUN_00d274c0 child node via the router allocator.
// @fnv 0x00d608a0
FUN_00d608a0::FUN_00d608a0(int first, int second, unsigned char mode)
{
    count = 1;
    vptr = &DAT_010d14f8;
    this->mode = mode;
    hkMemoryRouter* router = &hkMemoryRouter::getInstance();
    FUN_00d274c0* next = static_cast<FUN_00d274c0*>(router->m_heap->blockAlloc(28));
    next->allocatedSize = 28;
    child = new (next) FUN_00d274c0(first, second, hkBoolD608());
}

int __cdecl FUN_00cb0fa0(int, int);
struct R
{
    volatile char value;
    R(bool b) : value(b)
    {}
};
struct S
{
    int value;
    R IsLessThan(int other) const;
};
// @fnv 0x00d616c0
R S::IsLessThan(int other) const
{
    return FUN_00cb0fa0(value, other) < 0;
}

namespace hkRouterD619 {
}


template <class T> __forceinline void constructWithCopyD619(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayD619
{
  public:
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

    void _pushBack(hkMemoryAllocator& kAlloc, T t)
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)&(kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyD619(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void AddBack(T t)
    {
        _pushBack(hkMemoryRouter::getInstance().temp(), t);
    }
};

class hkStringD619
{
  public:
    char* m_kStringBuffer;

    int FindCharacter(int c, int iStart, int iEnd) const;
    int SplitString(int c, hkArrayD619<const char*>& kBits);
};

// Splits m_kStringBuffer in place at each c found from index 1 by writing nulls, appends each piece pointer to kBits, and returns kBits's size.
// @fnv 0x00d61910
int hkStringD619::SplitString(int c, hkArrayD619<const char*>& kBits)
{
    kBits.AddBack(m_kStringBuffer);
    int iNumBits = kBits.GetLogicalSize();
    int iCur = reinterpret_cast<::FNV_00d61600_Buffer *>((void *)this)->FindCharacter(c, 1, 0x7fffffff);
    while (iCur >= 0)
    {
        m_kStringBuffer[iCur] = 0;
        int iStart = iCur + 1;
        kBits.AddBack(m_kStringBuffer + iStart);
        iNumBits = kBits.GetLogicalSize();
        iCur = reinterpret_cast<::FNV_00d61600_Buffer *>((void *)this)->FindCharacter(c, iStart, 0x7fffffff);
    }
    return iNumBits;
}

template <class T> inline void hkArrayCopyD61(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

class FUN_00d619d0
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    FUN_00d619d0& operator=(const FUN_00d619d0& a);
};

// Copies the source array, growing the buffer via the memory router if the source size exceeds the current capacity.
// @fnv 0x00d619d0
FUN_00d619d0& FUN_00d619d0::operator=(const FUN_00d619d0& aSource)
{
    hkMemoryAllocator& alloc = *hkMemoryRouter::getInstance().m_temp;
    if ((m_iCapacityState & 0x3fffffff) < aSource.m_iElementCount)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff));
        int n = aSource.m_iElementCount;
        m_data = (char*)alloc.bufAlloc(n);
        m_iCapacityState = n;
    }
    m_iElementCount = aSource.m_iElementCount;
    hkArrayCopyD61(m_data, aSource.m_data, m_iElementCount);
    return *this;
}

struct FUN_00d61a50_cls
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_acStorage[128];

    int* FUN_00d61a50(intptr_t value);
};


// Initializes the string buffer, grows capacity if needed, copies value into m_data, and returns this.
// @fnv 0x00d61a50
int* FUN_00d61a50_cls::FUN_00d61a50(intptr_t value)
{
    m_data = m_acStorage;
    m_iElementCount = 0;
    m_iCapacityState = 0x80000080;

    if (value != 0)
    {
        int length = ::fnv_00cb10d0::FUN_00cb10d0((const char *)(value));
        int count = length + 1;

        hkMemoryAllocator* allocator = hkMemoryRouter::getInstance().m_temp;
        int capacity = m_iCapacityState & 0x3FFFFFFF;

        if (capacity < count)
        {
            capacity = capacity * 2;
            if (count >= capacity)
                capacity = count;
            ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(::FUN_00d61a50_cls *)(this), capacity, 1);
        }

        m_iElementCount = count;
        m_data[length] = 0;
        ::FUN_00cb1260(m_data, (const void *)(value), length);
    }
    else
    {
        hkMemoryAllocator* allocator = hkMemoryRouter::getInstance().m_temp;
        int capacity = m_iCapacityState & 0x3FFFFFFF;

        if (capacity < 1)
        {
            capacity = capacity * 2;
            if (capacity <= 1)
                capacity = 1;
            ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(::FUN_00d61a50_cls *)(this), capacity, 1);
        }

        m_iElementCount = 1;
        *(char*)m_data = 0;
    }

    return (int*)this;
}

namespace hkRouterD61F {
}

template <class T> class hkArrayD61F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkMemoryRouter::getInstance().temp(), n);
        m_iElementCount = n;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

class hkStringBufD61F
{
  public:
    hkArrayD61F<char> m_kStringBuffer;

    void FUN_00d61f70(int n);
};

// If n > 0, removes the last n characters by resizing the buffer to its size minus n and null-terminating it.
// @fnv 0x00d61f70
void hkStringBufD61F::FUN_00d61f70(int n)
{
    if (n > 0)
    {
        int iLen = m_kStringBuffer.GetLogicalSize() - n - 1;
        m_kStringBuffer.SetSizeAndGrow(iLen + 1);
        m_kStringBuffer[iLen] = 0;
    }
}

namespace fnv_00d61fc0 {
namespace hkRouterD61F {
}

class hkStringBufD61F
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void FUN_00d61fc0(int iOffset, int iLength);
};

// @fnv 0x00d61fc0
void hkStringBufD61F::FUN_00d61fc0(int iOffset, int iLength)
{
    if (iOffset)
        ::FUN_00d2cc70(m_data, m_data + iOffset, iLength);
    int n = iLength + 1;
    hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().temp();
    const int iCap = getCapacity();
    if (iCap < n)
    {
        int iCap2 = 2 * iCap;
        int iNewCap = (n < iCap2) ? iCap2 : n;
        ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewCap, sizeof(char));
    }
    m_iElementCount = n;
    m_data[iLength] = 0;
}
}  // namespace fnv_00d61fc0

namespace hkRouterD62 {
}

class hkReferencedObjectD62
{
  public:
    virtual ~hkReferencedObjectD62();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(std::size_t nbytes)
    {
        hkReferencedObjectD62* b =
            static_cast<hkReferencedObjectD62*>(hkMemoryRouter::getInstance().heap().blockAlloc((int)nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class hkpCollisionAgentD62
{
  public:
    virtual void cleanup();
};

class FUN_00d62ef0 : public hkReferencedObjectD62, public hkpCollisionAgentD62
{
  public:
    FUN_00d62ef0(void* contactMgr, int flags) throw();

    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
};

// Allocates a FUN_00d62ef0 object via the hkReferencedObjectD62 operator new, passing contactMgr and 0 as flags, and returns it as hkpCollisionAgentD62*.
// @fnv 0x00d62f20
hkpCollisionAgentD62* __cdecl FUN_00d62f20(void* contactMgr)
{
    return new FUN_00d62ef0(contactMgr, 0);
}

// @fnv 0x00d6c1a0
__declspec(noinline) static void FUN_00d6c1a0(int* piValue)
{
    *piValue -= 16;
}

void E6C1A0Adjust(int* piValue)
{
    FUN_00d6c1a0(piValue);
}

class FUN_00d73410;

struct Z0
{
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    int m_iUnk0C;
};

class FUN_00d73410
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    int m_iUnk0C;
    FUN_00d73410();
};

// @fnv 0x00d73410
FUN_00d73410::FUN_00d73410()
{
    m_iUnk00 = 0;
    m_iUnk04 = 0;
    m_iUnk08 = 0;
    m_iUnk0C = 0;
    reinterpret_cast<::FUN_00d73400_cls *>((((Z0*)this)))->FUN_00d73400();
}

struct Node
{
    unsigned unk00, unk04, unk08, unk0c;
    void* active;
    Node* left;
    Node* right;
    unsigned unk1c, unk20, unk24, unk28, flags;
};
// For each node whose left and right children are both active, rewrites their flags with seed and 5-bit ids from a running counter or the other child.
// @fnv 0x00d74b70
void __cdecl AssignNodeFlags(Node** nodes, int count, unsigned auSeed)
{
    unsigned nextId = 0;
    int index = 0;
    if (count > 0)
    {
        do
        {
            Node* item = nodes[index];
            Node* left = item->left;
            Node* right = item->right;
            if (left && left->active && right && right->active)
            {
                unsigned leftPacked = left->flags;
                unsigned rightPacked = right->flags;
                unsigned midLeft = (leftPacked >> 5) & 31;
                unsigned midRight = (rightPacked >> 5) & 31;
                unsigned highLeft = (leftPacked >> 10) & 31;
                unsigned highRight = (rightPacked >> 10) & 31;
                unsigned lowLeft = leftPacked & 31;
                unsigned lowRight = rightPacked & 31;
                if (!midLeft)
                    midLeft = nextId++;
                if (!midRight)
                    midRight = nextId++;
                if (!highLeft)
                    highLeft = midRight;
                else
                    highRight = midLeft;
                left->flags = ((((auSeed << 6) | highLeft) << 5) | midLeft) << 5 | lowLeft;
                right->flags = ((((auSeed << 6) | highRight) << 5) | midRight) << 5 | lowRight;
            }
            ++index;
        } while (index < count);
    }
}

struct FUN_00d7e740_cls
{
    int FUN_00d7e740(int iArg0, int iArg1, bool iFlag, int iArg2);
};

struct FUN_00d76c20_cls
{
    int m_00;
    int m_04;
    FUN_00d7e740_cls* m_target;

    int ForwardToTarget(int iSelector, intptr_t iArg0, intptr_t iArg1, intptr_t iArg2);
};

// Forwards a call to m_target->FUN_00d7e740, passing iSelector == 0 as the third argument.
// @fnv 0x00d76c20
int FUN_00d76c20_cls::ForwardToTarget(int iSelector, intptr_t iArg0, intptr_t iArg1, intptr_t iArg2)
{
    return reinterpret_cast<::fnv_00d7e740::ExportShape *>((m_target))->FUN_00d7e740((*(::fnv_00d7e740::ExportArray<unsigned char> *)(iArg0)), (*(::fnv_00d7e740::ExportArray<unsigned short> *)(iArg1)), iSelector == 0, iArg2);
}

struct hkResultD794
{
    int m_bHasHit;
};


// Calls FUN_00d79250 with flags 0 and returns whether out->m_bHasHit is set.
// @fnv 0x00d794e0
bool __cdecl FUN_00d794e0(void* a, void* b, hkResultD794* apResult, float f)
{
    ::FUN_00d79250((::S00d79250_World *)(a), (::S00d79250_Shape *)(b), (::S00d79250_Obj **)(apResult), (::S00d79250_Objs *)(0), f);
    return apResult->m_bHasHit != 0;
}

// @fnv 0x00d61430
static __declspec(noinline) int ToLowerCase(char c)
{
    return ((unsigned char)(c - 'A') <= 25) ? c + 0x20 : c;
}

volatile char g_d61430_c;
char g_d61430_sink;

void d61430_caller()
{
    g_d61430_sink = (char)ToLowerCase(g_d61430_c);
}

// @fnv 0x00d61450
static __declspec(noinline) int FUN_00d61450(char c)
{
    return ((unsigned char)(c - 'a') <= 25) ? c - 0x20 : c;
}

volatile char g_d61450_c;
char g_d61450_sink;

void d61450_caller()
{
    g_d61450_sink = (char)FUN_00d61450(g_d61450_c);
}

struct D6C1B0Owner
{
    int unk00;
    void(__cdecl* unk04)(int, int, D6C180Command**);
    int unk08;
};

extern "C" D6C180Command** d6c1b0_cursor_src(void);
volatile int g_d6c1b0_a1;
D6C1B0Owner* volatile g_d6c1b0_owner;

// @fnv 0x00d6c1b0
static __declspec(noinline) void FUN_00d6c1b0(D6C180Command** ppkCursor, D6C1B0Owner* pOwner, int a1)
{
    *ppkCursor -= 1;
    pOwner->unk04(pOwner->unk08, a1, ppkCursor);
}

void d6c1b0_caller(void)
{
    FUN_00d6c1b0(d6c1b0_cursor_src(), g_d6c1b0_owner, g_d6c1b0_a1);
}



extern "C" __m128 g_d6c1d0_src[4];
extern "C" __m128 g_d6c1d0_mat[4];
extern "C" __m128 g_d6c1d0_out[4];

// For i=0..3 sets out[i] to b[i].x*a[0] + b[i].y*a[1] + b[i].z*a[2], then adds a[3] to out[3].
// @fnv 0x00d6c1d0
static __declspec(noinline) void FUN_00d6c1d0(__m128* __restrict out, const __m128* __restrict a,
                                              const __m128* __restrict b)
{
    const __m128& c1 = a[1];
    const __m128& c0 = a[0];
    const __m128& c2 = a[2];
    for (int i = 3; i >= 0; i--)
    {
        const __m128& v = b[i];
        out[i] =
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0), _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1)),
                       _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));
    }
    out[3] = _mm_add_ps(a[3], out[3]);
}

void fnv_probe_d6c1d0()
{
    FUN_00d6c1d0(g_d6c1d0_out, g_d6c1d0_mat, g_d6c1d0_src);
}

#include "havok/SimpleContactSettings.h"
struct IntegratorD720
{
    float unk00;
    float offset;
    float unk08;
    float unk0c;
    float state;
};
// @fnv 0x00d720a0
static __declspec(noinline) float FUN_00d720a0(IntegratorD720* self, float input, float step)
{
    float value = self->state;
    float delta = input - value;
    float error = -self->offset - delta;
    float limit = DAT_011b6924 * step;
    float proposed = -DAT_011b6928 * value;
    float change = proposed < limit ? proposed : limit;
    value += change;
    delta -= change;
    if (error > limit + 2.0f * change)
    {
        value -= error;
        delta += error;
    }
    self->state = ::DAT_010c8440 > value ? value : ::DAT_010c8440;
    return delta;
}

IntegratorD720* volatile integratorD720;
volatile float inputD720, stepD720, resultD720;
void invokeD720()
{
    resultD720 = FUN_00d720a0(integratorD720, inputD720, stepD720);
}

struct FUN_00d74dc0_cls
{
    void* FUN_00d74dc0();
};

// @fnv 0x00d74dc0
void* FUN_00d74dc0_cls::FUN_00d74dc0()
{
    return (char*)this + 0x10;
}

int __cdecl FUN_00cb0f50(char* pcBuf, int iBufSize, const char* pcFormat, va_list kArgs) throw();

template <typename T> struct hkArrayD624
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T* begin()
    {
        return m_data;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(hkMemoryRouter::getInstance().temp(), n);
        m_iElementCount = n;
    }
    __forceinline ~hkArrayD624()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, m_iCapacityState & 0x3fffffff);
    }
};

class hkStringBufD624
{
  public:
    hkArrayD624<char> m_kStringBuffer;
    unsigned int m_kStorage[32];

    hkStringBufD624()
    {
        reinterpret_cast<::BufferOwner *>(this)->InitBuffer();
    }

    const char* cString() const
    {
        return m_kStringBuffer.m_data;
    }
    __forceinline void setLength(int iLength)
    {
        m_kStringBuffer.SetSizeAndGrow(iLength + 1);
        m_kStringBuffer[iLength] = 0;
    }
};

class hkOstreamD624
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;

    void FUN_00d62080(const char* pcBuf, int iNumBytes) throw();
    void WriteFormatted(const char* pcFormat, ...) throw();
};

// Formats pcFormat and varargs into a growable buffer via FUN_00cb0f50, resizing and retrying until it fits, then passes it to FUN_00d62080 with length -1.
// @fnv 0x00d62420
void hkOstreamD624::WriteFormatted(const char* pcFormat, ...) throw()
{
    hkStringBufD624 kBuf;
    while (1)
    {
        int iSize = kBuf.m_kStringBuffer.getCapacity();
        va_list kArgs;
        va_start(kArgs, pcFormat);
        int iNumChars = FUN_00cb0f50(kBuf.m_kStringBuffer.begin(), iSize, pcFormat, kArgs);
        va_end(kArgs);
        if (iNumChars >= 0 && iNumChars < iSize)
        {
            kBuf.setLength(iNumChars);
            break;
        }
        else if (iNumChars < 0)
        {
            kBuf.setLength((2 * iSize > 255) ? 2 * iSize : 255);
        }
        else
        {
            kBuf.setLength(iNumChars);
        }
    }
    reinterpret_cast<::D62080_Object *>(this)->FUN_00d62080((intptr_t)(kBuf.cString()), -1);
}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase_00d68830
{
    virtual void FUN_00d68830();
    int unk04;
};

struct SecondaryBase_00d68830
{
    virtual void FUN_00d68830();
};

struct Derived_00d68830 : PrimaryBase_00d68830, SecondaryBase_00d68830
{
    Derived_00d68830();
// @fnv 0x00d68830
    virtual void FUN_00d68830();
};

Derived_00d68830::Derived_00d68830()
{}

namespace fnv_00d68900 {
// sub ecx,0x20; jmp target  ==  MSVC adjustor thunk (second base's vtable entry).
// PrimaryBase is 0x20 bytes: vptr + seven ints.
struct PrimaryBase
{
    virtual void FUN_00d68900();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct SecondaryBase
{
    virtual void FUN_00d68900();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68900
    virtual void FUN_00d68900();
};

Derived::Derived()
{}
}  // namespace fnv_00d68900

struct Node_d6c580
{
    unsigned short m_type;
    char pad[0x12];
    Node_d6c580* m_parent;
};

// @fnv 0x00d6c580
static __declspec(noinline) Node_d6c580* FUN_00d6c580(Node_d6c580* n)
{
    do
    {
        n = n->m_parent;
    } while (n->m_type >= 0x17);
    return n;
}

Node_d6c580* zz_probe_d6c580(Node_d6c580* n)
{
    return FUN_00d6c580(n);
}

// @fnv 0x00d6c590
static __declspec(noinline) void FUN_00d6c590(int* p)
{
    *p -= 0x10;
}

void zz_probe_d6c590(int* p)
{
    FUN_00d6c590(p);
}

namespace fnv_00d61c10 {
namespace hkRouterD61C {
}

template <class T> class hkArrayD61C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkMemoryRouter::getInstance().temp(), n);
        m_iElementCount = n;
    }
    T* begin()
    {
        return m_data;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkStringBufD61C
{
  public:
    hkArrayD61C<char> m_kStringBuffer;

    hkStringBufD61C& FUN_00d61c10(const char* s);
};

// Copies a null-terminated string into the internal buffer, growing it as needed, or clears it to an empty string when the input is null.
// @fnv 0x00d61c10
hkStringBufD61C& hkStringBufD61C::FUN_00d61c10(const char* apcString)
{
    if (apcString)
    {
        int len = ::fnv_00cb10d0::FUN_00cb10d0(apcString);
        m_kStringBuffer.SetSizeAndGrow(len + 1);
        m_kStringBuffer[len] = 0;
        ::FUN_00cb1260(m_kStringBuffer.begin(), apcString, len);
    }
    else
    {
        m_kStringBuffer.SetSizeAndGrow(1);
        m_kStringBuffer[0] = 0;
    }
    return *this;
}
}  // namespace fnv_00d61c10

namespace fnv_00d63340 {
namespace FUN_00ddcc60 {
class hkpWorldViewerBase
{
  public:
    virtual ~hkpWorldViewerBase();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
}

class hkpWorldDeletionListenerD633
{
  public:
    virtual void WorldDeletedCallback(void* pkWorld) = 0;
    int unk04, unk08, unk0C, unk10, unk14;
};

class hkpActionListenerD633
{
  public:
    virtual void ActionAddedCallback(void* pkAction) = 0;
};

namespace FUN_00ddf240 {
class hkArrayD633
{
  public:
    ~hkArrayD633() throw();
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
}

namespace FUN_00d63340 {
class hkpWorldMemoryViewer : public FUN_00ddcc60::hkpWorldViewerBase,
                             public hkpWorldDeletionListenerD633,
                             public hkpActionListenerD633
{
  public:
    virtual ~hkpWorldMemoryViewer();
    virtual void WorldDeletedCallback(void* pkWorld);
    virtual void ActionAddedCallback(void* pkAction);

    int unk24;
    FUN_00ddf240::hkArrayD633 m_kArray;
};

// @fnv 0x00d63340
hkpWorldMemoryViewer::~hkpWorldMemoryViewer()
{}
}
}  // namespace fnv_00d63340

class RotationColumns;

class QuadDirection
{
  public:
    __forceinline QuadDirection()
    {}
    __forceinline QuadDirection(const QuadDirection& other)
    {
        value = other.value;
    }
    __forceinline void operator=(const QuadDirection& other)
    {
        value = other.value;
    }
    __forceinline void multiply(const RotationColumns& rotation, const QuadDirection& input);
    __m128 value;
};

class RotationColumns
{
  public:
    __forceinline RotationColumns()
    {}
    __forceinline RotationColumns(const RotationColumns& other)
    {
        columns[0] = other.columns[0];
        columns[1] = other.columns[1];
        columns[2] = other.columns[2];
    }
    __forceinline QuadDirection& column(int i)
    {
        return columns[i];
    }
    __forceinline const QuadDirection& column(int i) const
    {
        return columns[i];
    }
    QuadDirection columns[3];
};

__forceinline void QuadDirection::multiply(const RotationColumns& rotation, const QuadDirection& input)
{
    const __m128 componentX = _mm_shuffle_ps(input.value, input.value, 0);
    const __m128 termX = _mm_mul_ps(rotation.column(0).value, componentX);
    const __m128 componentY = _mm_shuffle_ps(input.value, input.value, 0x55);
    const __m128 termY = _mm_mul_ps(rotation.column(1).value, componentY);
    const __m128 componentZ = _mm_shuffle_ps(input.value, input.value, 0xaa);
    const __m128 termZ = _mm_mul_ps(rotation.column(2).value, componentZ);
    value = _mm_add_ps(_mm_add_ps(termX, termY), termZ);
}

class Orientation : public RotationColumns
{
};

class RigidTransform
{
  public:
    __forceinline Orientation& rotation()
    {
        return orientation;
    }
    __forceinline const Orientation& rotation() const
    {
        return orientation;
    }
    Orientation orientation;
    QuadDirection translation;
};

template <class T> class QueryValue
{
  public:
    __forceinline T get() const
    {
        return value;
    }
    T value;
};

struct ConstraintQuery
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    QueryValue<const RigidTransform*> transformA;
    QueryValue<const RigidTransform*> transformB;
};

struct LocalOrientations
{
    int unk00, unk04, unk08, unk0c;
    Orientation localA;
    Orientation localB;
};

static __forceinline void RotateDirections(const RotationColumns& rotation, const QuadDirection* source, int count,
                                           QuadDirection* destination)
{
    RotationColumns saved = rotation;
    int i = count - 1;
    do
    {
        destination[i].multiply(saved, source[i]);
    } while (--i >= 0);
}

// Rotates four vectors from local.localA and local.localB by the rotations of input.transformA and transformB, storing them in outputA and outputB.
// @fnv 0x00d6c3c0
static __declspec(noinline) void FUN_00d6c3c0(const LocalOrientations& local, const ConstraintQuery& input,
                                              RigidTransform& outputA, RigidTransform& outputB)
{
    RotateDirections(input.transformA.get()->rotation(), &local.localA.column(0), 4, &outputA.rotation().column(0));
    RotateDirections(input.transformB.get()->rotation(), &local.localB.column(0), 4, &outputB.rotation().column(0));
}

void RotateLocalFrames(const LocalOrientations& local, const ConstraintQuery& input, RigidTransform& outputA,
                       RigidTransform& outputB)
{
    FUN_00d6c3c0(local, input, outputA, outputB);
}



struct D73390Source
{
    float value0[4];
    float value1[4];
    float value2[4];
};

struct D73390Data
{
    float value0[4];
    float value1[4];
    float value2[4];
    float value3[4];

};

// Copies three float arrays from source into data, loads a fourth from DAT_01267e30, calls FUN_00de8f10, then calls FUN_00d73380 with data and count.
// @fnv 0x00d73390
void __cdecl FUN_00d73390(D73390Source* source, int count)
{
    D73390Data data;

    _mm_store_ps(data.value0, _mm_load_ps(source->value0));
    _mm_store_ps(data.value1, _mm_load_ps(source->value1));
    _mm_store_ps(data.value2, _mm_load_ps(source->value2));
    _mm_store_ps(data.value3, _mm_load_ps((const float*)&(*reinterpret_cast<__m128 *>(&::DAT_01267e30))));

    reinterpret_cast<::FUN_00de8f10_Class *>(&(data))->FUN_00de8f10();
    ((void(__cdecl*)(int*, int))FUN_00d73380)((int*)&data, count);
}

inline char hkToUpperD618(char c)
{
    return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
}

class UpperCaseBufferD618 : public hkStringBufD618
{
  public:
    int getLength() const
    {
        return m_iElementCount - 1;
    }
    void FUN_00d618d0();
};

// Converts every character in the buffer to its uppercase equivalent using hkToUpperD618.
// @fnv 0x00d618d0
void UpperCaseBufferD618::FUN_00d618d0()
{
    for (int i = 0; i < getLength(); i++)
    {
        m_data[i] = hkToUpperD618(m_data[i]);
    }
}

struct TransformContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    const __m128* m_pM1;
    const __m128* m_pM2;
};

struct TransformPair
{
    __m128 m_row[4];
};

// Transforms four src vectors by the rows at ctx->m_pM1 into dest->m_row and four more by ctx->m_pM2 into out, adding the fourth row of each as an offset.
// @fnv 0x00d6c240
static __declspec(noinline) void FUN_00d6c240(TransformPair* dest, const __m128* src, const TransformContext* ctx,
                                              __m128* out)
{
    const __m128* pMatrix = ctx->m_pM1;
    __m128 a = pMatrix[0];
    __m128 b = pMatrix[1];
    __m128 c = pMatrix[2];
    for (int n = 3; n >= 0; --n)
    {
        __m128 v = src[n + 1];
        __m128 r = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(&src[n + 1])), _mm_load_ps(reinterpret_cast<const float*>(&src[n + 1])), 0), a),
            _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b));
        dest->m_row[n] = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c));
    }
    dest->m_row[3] = _mm_add_ps(dest->m_row[3], pMatrix[3]);

    pMatrix = ctx->m_pM2;
    a = pMatrix[0];
    b = pMatrix[1];
    c = pMatrix[2];
    for (int n = 3; n >= 0; --n)
    {
        __m128 v = src[n + 5];
        __m128 r = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(&src[n + 5])), _mm_load_ps(reinterpret_cast<const float*>(&src[n + 5])), 0), a),
            _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b));
        out[n] = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c));
    }
    out[3] = _mm_add_ps(out[3], pMatrix[3]);
}

TransformPair* volatile inputDest;
const __m128* volatile inputSource;
const TransformContext* volatile inputContext;
__m128* volatile inputOut;
void invokeTransform()
{
    FUN_00d6c240(inputDest, inputSource, inputContext, inputOut);
}

inline void SetTransformedPositionC320(QuadDirection& output, const RigidTransform& frame, const QuadDirection& input)
{
    const __m128 v = input.value;
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), frame.orientation.column(1).value);
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), frame.orientation.column(0).value);
    __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), frame.orientation.column(2).value);
    output.value = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, frame.translation.value));
}

struct PivotsC320
{
    QuadDirection m_unk00;
    QuadDirection m_kPivotA;
    QuadDirection m_kPivotB;
};

struct TransformOutputC320
{
    RigidTransform* p;
    TransformOutputC320(RigidTransform* value) : p(value)
    {}
};

// Applies the rigid transforms of two bodies to their respective pivot points, writing the resulting translations into the output transforms.
// @fnv 0x00d6c320
static __declspec(noinline) void __cdecl FUN_00d6c320(const PivotsC320* pivots, const ConstraintQuery* bodies,
                                                      TransformOutputC320 outA, TransformOutputC320 outB)
{
    SetTransformedPositionC320(outA.p->translation, *bodies->transformA.get(), pivots->m_kPivotA);
    SetTransformedPositionC320(outB.p->translation, *bodies->transformB.get(), pivots->m_kPivotB);
}

const ConstraintQuery* volatile bodiesSourceC320;
const PivotsC320* volatile pivotsSourceC320;
RigidTransform* volatile outASourceC320;
RigidTransform* volatile outBSourceC320;
void InvokeTransformC320()
{
    const ConstraintQuery* bodies = bodiesSourceC320;
    const PivotsC320* pivots = pivotsSourceC320;
    RigidTransform* a = outASourceC320;
    RigidTransform* b = outBSourceC320;
    FUN_00d6c320(pivots, bodies, a, b);
}

void RegisterContactPointsInactive();

void* FUN_00d687b0(char* a1);

void* FUN_00d68880(void* pObject);

// FUN_00d688f0 : tiny global getter.
// Reads the 4-byte global at DAT_0126900c and returns it in eax.
int __cdecl FUN_00d688f0();

void* __cdecl FUN_00d6ade0();

int* __cdecl FUN_00d6ae00();

void* __cdecl FUN_00d6aee0();

void WriteCommand(D6C180Command** ppkCursor, unsigned char ucFlag);












int __cdecl FUN_00d63420();

void __cdecl FUN_00d6add0();

void __cdecl FUN_00d73380();




void __cdecl ArrayReserveImpl(void*, void*, int, int);



static void FUN_00d6c1a0(int* piValue);

void E6C1A0Adjust(int* piValue);

bool __cdecl FUN_00d794e0(void* a, void* b, hkResultD794* out, float f);

static int ToLowerCase(char c);


void d61430_caller();

static int FUN_00d61450(char c);


void d61450_caller();

static void FUN_00d6c1b0(D6C180Command** ppkCursor, D6C1B0Owner* pOwner, int a1);

void d6c1b0_caller(void);

static void FUN_00d6c1d0(__m128* __restrict out, const __m128* __restrict a, const __m128* __restrict b);

void fnv_probe_d6c1d0();

static float FUN_00d720a0(IntegratorD720* self, float input, float step);


void invokeD720();



static Node_d6c580* FUN_00d6c580(Node_d6c580* n);

Node_d6c580* zz_probe_d6c580(Node_d6c580* n);

static void FUN_00d6c590(int* p);

void zz_probe_d6c590(int* p);

static void FUN_00d6c3c0(const LocalOrientations& local, const ConstraintQuery& input, RigidTransform& outputA,
                         RigidTransform& outputB);

void RotateLocalFrames(const LocalOrientations& local, const ConstraintQuery& input, RigidTransform& outputA,
                       RigidTransform& outputB);

void __cdecl FUN_00d73390(D73390Source* source, int count);

static void FUN_00d6c240(TransformPair* dest, const __m128* src, const TransformContext* ctx, __m128* out);


void invokeTransform();

static void __cdecl FUN_00d6c320(const PivotsC320* pivots, const ConstraintQuery* bodies, TransformOutputC320 outA,
                                 TransformOutputC320 outB);

void InvokeTransformC320();

static __forceinline float localSqrt(float x)
{
    return (float)sqrt((double)x);
}

typedef float hkReal;

typedef __m128 hkQuadReal;

// absMask
       // default equals4 epsilon

static __forceinline hkQuadReal hkLoadSs(const hkReal& x)
{
    return _mm_load_ss(&x);
}

class VectorComponentValue
{
  public:
    VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    VectorComponentValue(hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    VectorComponentValue()
    {}
    operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
};

typedef const VectorComponentValue& hkSimdRealParameter;

class CompareBits
{
  public:
    enum Mask
    {
        ALL = 15
    };
    hkQuadReal bits;
    __forceinline int allAreSet(Mask m) const
    {
        return (_mm_movemask_ps(bits) & m) == m;
    }
};

struct hkVector4
{
  private:
    hkQuadReal m_vComponents;

  public:
    __forceinline operator hkQuadReal() const
    {
        return m_vComponents;
    }
    __forceinline void operator=(const hkQuadReal& q)
    {
        m_vComponents = q;
    }
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vComponents;
    }
    __forceinline VectorComponentValue getSimdAt(int i) const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 255);
    }
    __forceinline hkQuadReal& getQuad()
    {
        return m_vComponents;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void SetAllComponents(hkReal a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    __forceinline void add4(const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void sub4(const hkVector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(hkSimdRealParameter s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline void subMul4(hkSimdRealParameter r, const hkVector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents);
    }
    __forceinline void addMul4(hkSimdRealParameter r, const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void addMul4(const hkVector4& x, const hkVector4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        hkQuadReal lhs = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                                    _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        hkQuadReal rhs = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                                    _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(lhs, rhs);
    }
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter _t)
    {
        hkQuadReal t = _t.broadcast();
        hkQuadReal s = _mm_sub_ps(::DAT_010ec7f0, t);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
    }
    __forceinline void setAbs4(const hkVector4& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10);
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline VectorComponentValue lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline void broadcast0()
    {
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0);
    }
    __forceinline void setBroadcast3(const hkVector4& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    void SetRotatedDirection(const class hkQuaternion& quat, const hkVector4& direction);
    __forceinline CompareBits compareLessThanEqual4(const hkVector4& v) const
    {
        CompareBits c;
        c.bits = _mm_cmple_ps(m_vComponents, v.m_vComponents);
        return c;
    }
    __forceinline int equals4(const hkVector4& v, hkReal epsilon) const
    {
        hkVector4 t;
        t.setSub4(*this, v);
        t.setAbs4(t);
        hkVector4 epsilon_v;
        epsilon_v.SetAllComponents(epsilon);
        return t.compareLessThanEqual4(epsilon_v).allAreSet(CompareBits::ALL);
    }
};

struct hkQuaternion
{
  public:
    hkVector4 m_vec;
    __forceinline const hkVector4& getImag() const
    {
        return m_vec;
    }
    __forceinline void operator=(const hkQuaternion& q)
    {
        m_vec = q.m_vec;
    }
                // SetProduct
    void FUN_00cb2850(const hkQuaternion& q0, const hkQuaternion& q1, hkReal t);  // setSlerp
    void FUN_00d6bec0(const hkQuaternion& to, hkVector4& angleOut) const;  // estimateAngleTo
};

extern const hkQuadReal DAT_01017d20;

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 minusHalf;
    minusHalf.getQuad() = DAT_010c71e0;
    hkVector4 qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    hkVector4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast0();
    ret.addMul4(imagDotDir, quat.getImag());
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);
    this->setAdd4(ret, ret);
}

struct hkQsTransform
{
  public:
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
    __forceinline const hkVector4& getTranslation() const
    {
        return m_vTranslation;
    }
    __forceinline const hkQuaternion& getRotation() const
    {
        return m_rotation;
    }
    __forceinline void set(const hkVector4& t, const hkQuaternion& r, const hkVector4& s)
    {
        m_vTranslation = t;
        m_rotation = r;
        m_vScale = s;
    }
    __forceinline void SetProduct(const hkQsTransform& aTb, const hkQsTransform& bTc)
    {
        hkVector4 extraTrans;
        extraTrans.SetRotatedDirection(aTb.m_rotation, bTc.m_vTranslation);
        m_vTranslation.setAdd4(aTb.m_vTranslation, extraTrans);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), nullptr, (const __m128 *)&(aTb.m_rotation), (const __m128 *)&(bTc.m_rotation));
        m_vScale.setMul4(aTb.m_vScale, bTc.m_vScale);
    }
};

struct BodySweptPose
{
    hkVector4 center0, center1;
    hkQuaternion rotation0, rotation1;
    hkVector4 localCenter;
};

struct BodyTransform
{
    hkVector4 axis0, axis1, axis2, translation;
    __forceinline const hkVector4& getTranslation() const
    {
        return translation;
    }
};

struct BodyMotionState
{
    BodyTransform transform;
    BodySweptPose swept;
    hkVector4 rates0, rates1, rates2;
    __forceinline const BodySweptPose& getSweptTransform() const
    {
        return swept;
    }
    __forceinline const BodyTransform& getTransform() const
    {
        return transform;
    }
};

struct MotionObjectBase
{
    virtual void slot0();
    unsigned short objectSize;
    short referenceCount;
};

struct RigidMotion : MotionObjectBase
{
    int unk08, unk0c;
    BodyMotionState state;
    hkVector4 linear, angular;
    __forceinline const hkVector4& getLinearVelocity() const
    {
        return linear;
    }
    __forceinline const hkVector4& getAngularVelocity() const
    {
        return angular;
    }
    __forceinline const hkVector4& getCenterOfMassInWorld() const
    {
        return state.getSweptTransform().center1;
    }
    __forceinline const hkVector4& getCenterOfMassLocal() const
    {
        return state.getSweptTransform().localCenter;
    }
    __forceinline const hkQuaternion& getRotation() const
    {
        return state.getSweptTransform().rotation1;
    }
    __forceinline const hkVector4& getPosition() const
    {
        return state.getTransform().getTranslation();
    }
};

struct MaxMotion : RigidMotion
{
};

class EntityBody : public MotionObjectBase
{
  public:
    int unk08, unk0c;
    hkVector4 unk10, unk20, unk30, unk40, unk50, unk60, unk70, unk80, unk90, unka0, unkb0, unkc0, unkd0;
    MaxMotion motion;
};

struct hkpRigidBody : public EntityBody
{
  public:
    __forceinline RigidMotion* getRigidMotion() const
    {
        return const_cast<MaxMotion*>(&motion);
    }
    __forceinline const hkVector4& getCenterOfMassInWorld() const
    {
        return getRigidMotion()->getCenterOfMassInWorld();
    }
    __forceinline const hkVector4& getCenterOfMassLocal() const
    {
        return getRigidMotion()->getCenterOfMassLocal();
    }
    __forceinline const hkVector4& getPosition() const
    {
        return getRigidMotion()->getPosition();
    }
    __forceinline const hkQuaternion& getRotation() const
    {
        return getRigidMotion()->getRotation();
    }
    __forceinline const hkVector4& getLinearVelocity() const
    {
        return getRigidMotion()->getLinearVelocity();
    }
    __forceinline const hkVector4& getAngularVelocity() const
    {
        return getRigidMotion()->getAngularVelocity();
    }
};

template <typename T> class HkDynamicArray
{
  public:
    T* m_data;
    __forceinline void init(int n)
    {
        hkMemoryRouter& mem = hkMemoryRouter::getInstance();
        m_data = static_cast<T*>(mem.allocateStack((n * (int)sizeof(T) + 127) & ~127));
    }
    __forceinline void destroy()
    {
        hkMemoryRouter::getInstance().deallocateStack(static_cast<void*>(m_data));
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
};

struct BoneAndCenterOfMassPose
{
    hkQsTransform m_comPose;
    hkQsTransform m_bonePose;
};

struct ControlData
{
    hkReal m_fHierarchyGain;
    hkReal m_fVelocityDamping;
    hkReal m_fAccelerationGain;
    hkReal m_fVelocityGain;
    hkReal m_positionGain;
    hkReal m_fPositionMaxLinearVelocity;
    hkReal m_fPositionMaxAngularVelocity;
    hkReal m_snapGain;
    hkReal m_fSnapMaxLinearVelocity;
    hkReal m_fSnapMaxAngularVelocity;
    hkReal m_fSnapMaxLinearDistance;
    hkReal m_fSnapMaxAngularDistance;
};

struct HavokVectorQuaternionRecord
{
    hkVector4 m_kFirstVector;
    hkQuaternion m_kOrientation;
    hkVector4 m_kSecondVector;
    hkVector4 m_kThirdVector;
};

struct TransformReferenceData
{
    hkQsTransform m_kTransform;
    const hkQsTransform* m_pReferencedTransform;
    HavokVectorQuaternionRecord* m_pTransformContext;
};

struct IntegerTriple
{
    int m_iRigidBodyCount;
    hkpRigidBody* const* m_ppRigidBodies;
    const short* m_kParentIndices;
    int* m_piBodyPartIndices;
    const hkReal* m_pfRigidBodyWeights;
};

struct Output
{
    hkReal m_fOutputValue;
};

static __declspec(noinline) void FUN_00d6b510(const hkQsTransform* poseLocalSpace, const IntegerTriple& body,
                                              const ControlData* controlPalette, const hkQsTransform& worldFromRoot,
                                              BoneAndCenterOfMassPose* cache)
{
    for (int i = 0; i < body.m_iRigidBodyCount; i++)
    {
        hkQsTransform& worldFromBone = cache[i].m_bonePose;
        const int parentIndex = body.m_kParentIndices[i];
        const hkQsTransform& worldFromParent = parentIndex >= 0 ? cache[parentIndex].m_bonePose : worldFromRoot;
        worldFromBone.SetProduct(worldFromParent, poseLocalSpace[i]);
        hkQuaternion rotation = worldFromBone.getRotation();
        hkVector4 position = worldFromBone.getTranslation();
        const int controlIndex = body.m_piBodyPartIndices ? body.m_piBodyPartIndices[i] : 0;
        if (controlIndex == -1)
            continue;
        hkReal hierarchyGain = controlPalette[controlIndex].m_fHierarchyGain;
        if (body.m_pfRigidBodyWeights)
            hierarchyGain *= body.m_pfRigidBodyWeights[i];
        if (hierarchyGain > 0.0f && parentIndex >= 0)
        {
            hkpRigidBody* parentBody = body.m_ppRigidBodies[parentIndex];
            hkQsTransform worldFromParentBody;
            worldFromParentBody.m_vTranslation = parentBody->getPosition();
            worldFromParentBody.m_rotation = parentBody->getRotation();
            hkQsTransform blended;
            blended.SetProduct(worldFromParentBody, poseLocalSpace[i]);
            rotation.FUN_00cb2850(rotation, blended.getRotation(), hierarchyGain);
            position.setInterpolate4(position, blended.getTranslation(), hierarchyGain);
        }
        hkpRigidBody* rigidBody = body.m_ppRigidBodies[i];
        hkVector4 comOffset;
        comOffset.SetRotatedDirection(rotation, rigidBody->getCenterOfMassLocal());
        position.add4(comOffset);
        hkVector4 identity;
        identity.getQuad() = (*reinterpret_cast<__m128 *>(&::DAT_01267e30));
        cache[i].m_comPose.set(position, rotation, identity);
    }
}

static __declspec(noinline) float FUN_00d6b3c0(__m128* p, float a1, float a2);

static __declspec(noinline) void FUN_00d6b330(hkReal maxLength, hkVector4& v)
{
    const hkReal lengthSquared = v.lengthSquared3();
    const hkReal maxSquared = maxLength * maxLength;
    if (lengthSquared > maxSquared)
    {
        const hkReal factor = (1.0f / localSqrt(lengthSquared)) * maxLength;
        v.mul4(factor);
    }
}

// @fnv 0x00d6b8e0
__declspec(noinline) void __cdecl FUN_00d6b8e0(hkReal m_fTimeStep, const TransformReferenceData& pose, const IntegerTriple& body,
                                               const ControlData* controlPalette, Output* output)
{
    HkDynamicArray<BoneAndCenterOfMassPose> matrixCache;
    matrixCache.init(body.m_iRigidBodyCount);
    FUN_00d6b510(pose.m_pReferencedTransform, body, controlPalette, pose.m_kTransform, &matrixCache[0]);

    const hkReal invDeltaTime = 1.0f / m_fTimeStep;
    const VectorComponentValue invDeltaTimeS = invDeltaTime;

    for (int i = 0; i < body.m_iRigidBodyCount; i++)
    {
        const int controlIndex = body.m_piBodyPartIndices ? body.m_piBodyPartIndices[i] : 0;
        if (controlIndex == -1)
            continue;
        const ControlData& controlData = controlPalette[controlIndex];
        hkpRigidBody* rigidBody = body.m_ppRigidBodies[i];

        hkReal accelerationGain = controlData.m_fAccelerationGain;
        hkReal velocityGain = controlData.m_fVelocityGain;
        hkReal positionGain = controlData.m_positionGain;
        hkReal snapGain = controlData.m_snapGain;
        if (body.m_pfRigidBodyWeights)
        {
            const hkReal boneWeight = body.m_pfRigidBodyWeights[i];
            accelerationGain *= boneWeight;
            velocityGain *= boneWeight;
            positionGain *= boneWeight;
            snapGain *= boneWeight;
        }
        const VectorComponentValue velocityDamping = 1.0f - controlData.m_fVelocityDamping;

        const BoneAndCenterOfMassPose& cache = matrixCache[i];
        HavokVectorQuaternionRecord& workElem = pose.m_pTransformContext[i];

        // Linear velocity
        hkVector4 linearDiff, linearRate, linearAccel;
        {
            const hkVector4& desiredPosition = cache.m_comPose.getTranslation();
            linearDiff.setSub4(desiredPosition, rigidBody->getCenterOfMassInWorld());
            linearDiff.mul4(invDeltaTimeS);
            linearRate.setSub4(desiredPosition, workElem.m_kFirstVector);
            workElem.m_kFirstVector = desiredPosition;
            linearRate.mul4(invDeltaTimeS);
            linearAccel.setSub4(linearRate, workElem.m_kSecondVector);
            workElem.m_kSecondVector = linearRate;
        }
        hkVector4 linearCurrent = rigidBody->getLinearVelocity();
        hkVector4 linearNew;
        linearNew.setMul4(velocityDamping, linearCurrent);
        linearNew.addMul4(accelerationGain, linearAccel);
        linearRate.sub4(linearNew);
        {
            hkVector4 linearVelCorrection;
            linearVelCorrection.setMul4(velocityGain, linearRate);
            linearNew.add4(linearVelCorrection);
        }
        linearDiff.sub4(linearNew);
        {
            hkVector4 linearPosCorrection;
            linearPosCorrection.setMul4(positionGain, linearDiff);
            FUN_00d6b330(controlData.m_fPositionMaxLinearVelocity, linearPosCorrection);
            linearNew.add4(linearPosCorrection);
        }
        if (snapGain != 0.0f)
        {
            hkVector4 snapPosition;
            snapPosition.SetRotatedDirection(cache.m_bonePose.getRotation(), rigidBody->getCenterOfMassLocal());
            snapPosition.add4(cache.m_bonePose.getTranslation());
            hkVector4 snapVelocity;
            snapVelocity.setSub4(snapPosition, rigidBody->getCenterOfMassInWorld());
            snapVelocity.mul4(invDeltaTimeS);
            snapVelocity.sub4(linearNew);
            snapVelocity.mul4(snapGain);
            const hkReal maxDistance = controlData.m_fSnapMaxLinearDistance * invDeltaTime * snapGain;
            const hkReal stress = FUN_00d6b3c0((__m128*)&snapVelocity, controlData.m_fSnapMaxLinearVelocity, maxDistance);
            if (output)
                output[i].m_fOutputValue = stress;
            linearNew.add4(snapVelocity);
        }
        if (!rigidBody->getLinearVelocity().equals4(linearNew, 0.001f))
            reinterpret_cast<::FUN_005616d0_Owner *>((rigidBody))->OnTrigger((::TriggerContext *)&(linearNew));

        // Angular velocity
        hkVector4 angularDiff, angularRate, angularAccel;
        {
            const hkQuaternion& desiredRotation = cache.m_comPose.getRotation();
            rigidBody->getRotation().FUN_00d6bec0(desiredRotation, angularDiff);
            angularDiff.mul4(invDeltaTimeS);
            workElem.m_kOrientation.FUN_00d6bec0(desiredRotation, angularRate);
            workElem.m_kOrientation = desiredRotation;
            angularRate.mul4(invDeltaTimeS);
            angularAccel.setSub4(angularRate, workElem.m_kThirdVector);
            workElem.m_kThirdVector = angularRate;
        }
        hkVector4 angularCurrent = rigidBody->getAngularVelocity();
        hkVector4 angularNew;
        angularNew.setMul4(velocityDamping, angularCurrent);
        angularNew.addMul4(accelerationGain, angularAccel);
        angularRate.sub4(angularNew);
        {
            hkVector4 angularVelCorrection;
            angularVelCorrection.setMul4(velocityGain, angularRate);
            angularNew.add4(angularVelCorrection);
        }
        angularDiff.sub4(angularNew);
        {
            hkVector4 angularPosCorrection;
            angularPosCorrection.setMul4(positionGain, angularDiff);
            FUN_00d6b330(controlData.m_fPositionMaxAngularVelocity, angularPosCorrection);
            angularNew.add4(angularPosCorrection);
        }
        if (snapGain != 0.0f)
        {
            hkVector4 snapVelocity;
            rigidBody->getRotation().FUN_00d6bec0(cache.m_bonePose.getRotation(), snapVelocity);
            snapVelocity.mul4(invDeltaTimeS);
            snapVelocity.sub4(angularNew);
            snapVelocity.mul4(snapGain);
            const hkReal maxDistance = controlData.m_fSnapMaxAngularDistance * invDeltaTime * snapGain;
            const hkReal stress = FUN_00d6b3c0((__m128*)&snapVelocity, controlData.m_fSnapMaxAngularVelocity, maxDistance);
            if (output)
                output[i].m_fOutputValue += stress;
            angularNew.add4(snapVelocity);
        }
        if (!rigidBody->getAngularVelocity().equals4(angularNew, 0.001f))
            reinterpret_cast<::FUN_00561800_Class *>((rigidBody))->FUN_00561800((::FUN_00561730_Obj *)&(angularNew));
    }
    matrixCache.destroy();
}

void(__cdecl* volatile retainKeyFrameEntry)(hkReal, const TransformReferenceData&, const IntegerTriple&, const ControlData*,
                                            Output*) = &FUN_00d6b8e0;

class ScalarR2
{
    __m128 value;

  public:
    ScalarR2()
    {}
    ScalarR2(const __m128& v) : value(v)
    {}
    ScalarR2(float x)
    {
        value = _mm_load_ss(&x);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return value;
    }
};

struct RotationR2;

struct MatrixR2;

class FUN_004b4ab0_Class
{
    __m128 value;

  public:
    __forceinline FUN_004b4ab0_Class()
    {}
    __forceinline FUN_004b4ab0_Class(const __m128& x) : value(x)
    {}
    __forceinline FUN_004b4ab0_Class(const FUN_004b4ab0_Class& x) : value(x.value)
    {}
    __forceinline void operator=(const FUN_004b4ab0_Class& x)
    {
        value = x.value;
    }
    __forceinline void operator=(const __m128& x)
    {
        value = x;
    }
    operator __m128() const
    {
        return value;
    }
    __forceinline __m128& getQuad()
    {
        return value;
    }
    __forceinline const __m128& getQuad() const
    {
        return value;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&value)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&value)[i];
    }
    __forceinline void setSub4(const FUN_004b4ab0_Class& a, const FUN_004b4ab0_Class& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void setAdd4(const FUN_004b4ab0_Class& a, const FUN_004b4ab0_Class& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void setMul4(const FUN_004b4ab0_Class& a, const FUN_004b4ab0_Class& b)
    {
        value = _mm_mul_ps(a.value, b.value);
    }
    __forceinline void mul4(const FUN_004b4ab0_Class& a)
    {
        value = _mm_mul_ps(value, a.value);
    }
    __forceinline void add4(const FUN_004b4ab0_Class& a)
    {
        value = _mm_add_ps(value, a.value);
    }
    __forceinline void setCross(const FUN_004b4ab0_Class& a, const FUN_004b4ab0_Class& b)
    {
        __m128 left = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 right = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(left, right);
    }
    __forceinline ScalarR2 dot3(const FUN_004b4ab0_Class& a) const
    {
        __m128 p = _mm_mul_ps(value, a.value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), sum);
    }
    __forceinline ScalarR2 lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline void addMul4(const ScalarR2& s, const FUN_004b4ab0_Class& a)
    {
        value = _mm_add_ps(value, _mm_mul_ps(s.broadcast(), a.value));
    }
    __forceinline void subMul4(const ScalarR2& s, const FUN_004b4ab0_Class& a)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(s.broadcast(), a.value));
    }
    __forceinline void _setRotatedDir(const RotationR2& r, const FUN_004b4ab0_Class& v);
    __forceinline void _setMul3(const MatrixR2& r, const FUN_004b4ab0_Class& v);
    void FUN_004b4ab0(intptr_t r, intptr_t v);
    __forceinline void setRotatedInverseDir(const RotationR2& r, const FUN_004b4ab0_Class& v)
    {
        FUN_004b4ab0((intptr_t)&r, (intptr_t)&v);
    }
};

typedef FUN_004b4ab0_Class VectorR2;

struct MatrixR2
{
    VectorR2 col0, col1, col2;
    __forceinline VectorR2& getColumn(int i)
    {
        return (&col0)[i];
    }
    __forceinline const VectorR2& getColumn(int i) const
    {
        return (&col0)[i];
    }
};

struct RotationR2 : MatrixR2
{
};

__forceinline void VectorR2::_setRotatedDir(const RotationR2& r, const VectorR2& v)
{
    _setMul3(r, v);
}
__forceinline void VectorR2::_setMul3(const MatrixR2& r, const VectorR2& v)
{
    __m128 sx = _mm_shuffle_ps(v.value, v.value, 0);
    __m128 px = _mm_mul_ps(r.getColumn(0).value, sx);
    __m128 sy = _mm_shuffle_ps(v.value, v.value, 0x55);
    __m128 py = _mm_mul_ps(r.getColumn(1).value, sy);
    __m128 sz = _mm_shuffle_ps(v.value, v.value, 0xaa);
    __m128 pz = _mm_mul_ps(r.getColumn(2).value, sz);
    value = _mm_add_ps(_mm_add_ps(px, py), pz);
}

template <class T> class PaddedR2
{
    T data;

  public:
    __forceinline operator T() const
    {
        return data;
    }
    __forceinline T operator->() const
    {
        return data;
    }
    __forceinline T val() const
    {
        return data;
    }
    __forceinline void operator=(T x)
    {
        data = x;
    }
};

struct BodyR2
{
    int unk00, unk04, unk08, unk0c;
    VectorR2 m_vLinearVelocity, m_vAngularVelocity, m_vInverseInertiaAndMass, m_vCenterOfMass;
    RotationR2 m_kCoreFromWorldMatrix;
    __forceinline const VectorR2& getCenterOfMassInWorld() const
    {
        return m_vCenterOfMass;
    }
    __forceinline const RotationR2& getCoreFromWorldMatrix() const
    {
        return m_kCoreFromWorldMatrix;
    }
};

struct OwnerR2;

struct NoticeR2
{
    unsigned m_uiConstraintCount;
    OwnerR2* m_ppConstraints[128];
};

struct QueryR2
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    PaddedR2<float> m_fThirdQueryValue, m_fFourthQueryValue;
    int unk28, unk2c;
    PaddedR2<const BodyR2*> m_pBodyA, m_pBodyB;
    int unk38, unk3c, unk40, unk44, unk48, unk4c;
    ScalarR2 m_fMaxConstraintViolationSquared;
    PaddedR2<OwnerR2*> m_pConstraintChainInstance;
    int unk64;
    PaddedR2<NoticeR2*> m_pOpaqueData;
};

struct SchemaR2;

struct OutputR2
{
    PaddedR2<SchemaR2*> m_pQueryResultSchema;
};

extern long(* DAT_00fdf1ec)(volatile long*, long);

struct NativeRow
{
    VectorR2 linear, angularA, angularB;
    __forceinline float diagonal(const BodyR2& a, const BodyR2& b, double offset) const
    {
        __m128 anballSocketPivotA = angularA;
        __m128 anballSocketPivotB = angularB;
        VectorR2 sqA, sqB;
        sqA.getQuad() = _mm_mul_ps(anballSocketPivotA, anballSocketPivotA);
        sqB.getQuad() = _mm_mul_ps(anballSocketPivotB, anballSocketPivotB);
        sqA.mul4(a.m_vInverseInertiaAndMass);
        sqB.mul4(b.m_vInverseInertiaAndMass);
        sqB.add4(sqA);
        VectorR2 m;
        m.setAdd4(a.m_vInverseInertiaAndMass, b.m_vInverseInertiaAndMass);
        __m128 weighted = sqB;
        __m128 high = _mm_unpackhi_ps(weighted, m);
        __m128 all = _mm_shuffle_ps(weighted, high, 0xc4);
        __m128 pairs = _mm_add_ps(_mm_shuffle_ps(all, all, 0x4e), all);
        __m128 sum = _mm_add_ps(_mm_shuffle_ps(pairs, pairs, 0xb1), pairs);
        float x;
        _mm_store_ss(&x, sum);
        return (float)(x + offset);
    }
};

static __forceinline void stabilized(const BodyR2* a, const BodyR2* b, const VectorR2& pa, const VectorR2& pb,
                                     float rhs, float factor, VectorR2& error)
{
    ScalarR2 scale = (1.0f / rhs) * factor;
    error.setSub4(pb, pa);
    VectorR2 armA;
    armA.setSub4(pa, a->getCenterOfMassInWorld());
    VectorR2 armB;
    armB.setSub4(pb, b->getCenterOfMassInWorld());
    const RotationR2& ma = a->getCoreFromWorldMatrix();
    VectorR2 velocityA;
    velocityA.setRotatedInverseDir(ma, a->m_vAngularVelocity);
    const RotationR2& mb = b->getCoreFromWorldMatrix();
    VectorR2 velocityB;
    velocityB.setRotatedInverseDir(mb, b->m_vAngularVelocity);
    VectorR2 spinA;
    spinA.setCross(armA, velocityA);
    VectorR2 spinB;
    spinB.setCross(armB, velocityB);
    error.addMul4(scale, spinB);
    error.subMul4(scale, spinA);
}

static __forceinline void buildRow(const BodyR2* a, const BodyR2* b, const VectorR2& pa, const VectorR2& pb,
                                   const VectorR2& axis, float scale, float strength, NativeRow& row, double offset)
{
    row.linear = axis;
    VectorR2 armA;
    armA.setSub4(pa, a->getCenterOfMassInWorld());
    VectorR2 armB;
    armB.setSub4(pb, b->getCenterOfMassInWorld());
    VectorR2 crossA;
    crossA.setCross(armA, axis);
    VectorR2 crossB;
    crossB.setCross(axis, armB);
    row.angularA._setRotatedDir(a->getCoreFromWorldMatrix(), crossA);
    row.angularB._setRotatedDir(b->getCoreFromWorldMatrix(), crossB);
    float diag = row.diagonal(*a, *b, offset);
    row.angularB(3) = diag;
    row.angularA(3) = strength / diag;
    VectorR2 diff;
    diff.setSub4(pb, pa);
    float p = diff.dot3(axis);
    row.linear(3) = p * scale;
}

static __declspec(noinline) void FUN_00d6c630(const VectorR2& pa, const VectorR2& pb, const QueryR2& ctx,
                                              OutputR2& cursor, float mode, float dt);

const QueryR2* volatile ballSocketContext;

VectorR2* volatile ballSocketPivotA;

VectorR2* volatile ballSocketPivotB;

OutputR2* volatile ballSocketOutput;

volatile float ballSocketImpulse, ballSocketStep;

void BuildBallSocketRows()
{
    FUN_00d6c630(*ballSocketPivotA, *ballSocketPivotB, *ballSocketContext, *ballSocketOutput, ballSocketImpulse,
                 ballSocketStep);
}

// @fnv 0x00d6c630
static __declspec(noinline) void FUN_00d6c630(const VectorR2& pa, const VectorR2& pb, const QueryR2& ctx,
                                              OutputR2& cursor, float mode, float dt)
{
    const BodyR2* a = ctx.m_pBodyA;
    const BodyR2* b = ctx.m_pBodyB;
    NativeRow* out = (NativeRow*)cursor.m_pQueryResultSchema.val();
    VectorR2 error;
    stabilized(a, b, pa, pb, ctx.m_fThirdQueryValue, dt, error);
    if (ctx.m_pOpaqueData &&
        (_mm_movemask_ps(_mm_sub_ss(ctx.m_fMaxConstraintViolationSquared.getQuad(), error.lengthSquared3().getQuad())) &
         1))
    {
        unsigned idx = DAT_00fdf1ec((volatile long*)&ctx.m_pOpaqueData->m_uiConstraintCount, 1);
        if (idx < 128)
            ctx.m_pOpaqueData->m_ppConstraints[idx] = ctx.m_pConstraintChainInstance;
    }
    double target = mode, offset = DAT_010c9300, zero = DAT_0104e138;
    const VectorR2* axis = (*reinterpret_cast<FUN_004b4ab0_Class (*)[3]>(&::DAT_01268370));
    for (int i = 0; i < 3; ++i)
    {
        NativeRow* row = out;
        buildRow(a, b, pa, pb, *axis, ctx.m_fThirdQueryValue, ctx.m_fFourthQueryValue, *row, offset);
        row->linear(3) = error(i) * ctx.m_fThirdQueryValue;
        if (zero == target)
        {
            row->linear(0) = (float)(row->linear(0) + offset);
            *(unsigned char*)&row->linear(0) = 5;
        }
        else
        {
            row->linear(0) = (float)(row->linear(0) + offset);
            *(unsigned char*)&row->linear(0) = 6;
            row->angularB(3) = (float)target;
        }
        ++out;
        ++axis;
    }
    cursor.m_pQueryResultSchema = (SchemaR2*)out;
}


struct BoolD72
{
    unsigned char value;
    operator bool() const
    {
        return value != 0;
    }
};

struct Matrix3D72
{
    __m128 x, y, z;
    void FUN_00cd5140(const Matrix3D72& other);
    void FUN_00cd4d40(const __m128& factor, const Matrix3D72& other);
};

struct QuaternionD72
{
    __m128 value;
};

struct TransformD72
{
    Matrix3D72 rotation;
    __m128 translation;
};

struct Matrix4D72
{
    union
    {
        __m128 x;
        struct
        {
            float xx, xy, xz, xw;
        };
    };
    union
    {
        __m128 y;
        struct
        {
            float yx, yy, yz, yw;
        };
    };
    union
    {
        __m128 z;
        struct
        {
            float zx, zy, zz, zw;
        };
    };
    union
    {
        __m128 w;
        struct
        {
            float wx, wy, wz, ww;
        };
    };
    __declspec(noalias) void FUN_00de8da0(const Matrix4D72& left, const Matrix4D72& right);
};

struct DecompositionD72
{
    __m128 translation;
    QuaternionD72 rotation;
    union
    {
        __m128 scale;
        struct
        {
            float scaleX, scaleY, scaleZ, scaleW;
        };
    };
    unsigned char hasScale, hasSkew, flips;
    Matrix4D72 scaleSkew;
    Matrix4D72 skew;
    Matrix3D72 basis;
};

__forceinline void copyMatrix(Matrix3D72& d, const Matrix3D72& s)
{
    d.x = s.x;
    d.y = s.y;
    d.z = s.z;
}

union WorkA
{
    Matrix3D72 m3;
    TransformD72 t4;
    Matrix4D72 m4;
};

union WorkB
{
    Matrix3D72 m3;
    TransformD72 t4;
};

union WorkC
{
    Matrix3D72 m3;
    Matrix4D72 m4;
};

struct ScratchPairD72
{
    WorkB previous;
    WorkC inverse;
};

__forceinline __m128 dot3D72(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
__forceinline __m128 normalizedD72(__m128 v)
{
    __m128 lengthSquared = dot3D72(v, v);
    __m128 reciprocal = _mm_rsqrt_ss(lengthSquared);
    __m128 three = _mm_set_ss(DAT_01017718);
    __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(lengthSquared, reciprocal), reciprocal));
    __m128 scale = _mm_mul_ss(_mm_mul_ss(_mm_load_ss(&::fnv_00c88020::DAT_01016248), reciprocal), correction);
    scale = _mm_andnot_ps(_mm_cmpeq_ss(lengthSquared, _mm_load_ss(&DAT_01011d78)), scale);
    return _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), v);
}

__forceinline float scalarD72(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}
__forceinline void diagD72(Matrix4D72& m, float x, float y, float z)
{
    m.x = _mm_setzero_ps();
    m.y = _mm_setzero_ps();
    m.z = _mm_setzero_ps();
    m.w = _mm_setzero_ps();
    m.xx = 1.0f / x;
    m.yy = 1.0f / y;
    m.zz = 1.0f / z;
    m.ww = 1.0f;
}

struct OutputD72
{
    DecompositionD72* p;
    OutputD72(DecompositionD72* q) : p(q)
    {}
};

// @fnv 0x00d72e90
void __cdecl FUN_00d72e90(const float* source, OutputD72 output)
{
    TransformD72 transform;
    reinterpret_cast<::FUN_00cb20b0_shell *>(&(transform))->FUN_00cb20b0((const ::Matrix44 *)(source));
    Matrix4D72 original;
    reinterpret_cast<::FUN_00de9080_Class *>(&(original))->CopyFromFloats(source);
    reinterpret_cast<::FUN_00de8f10_Class *>(&(original))->FUN_00de8f10();
    DecompositionD72* __restrict result = output.p;
    result->translation = transform.translation;
    {
        Matrix3D72 current;
        int iteration = 0;
        copyMatrix(current, transform.rotation);
        bool equal;
        Matrix3D72 previous;
        do
        {
            copyMatrix(previous, current);
            Matrix3D72 inverse;
            copyMatrix(inverse, current);
            reinterpret_cast<::hkMatrix3 *>(&(inverse))->FUN_00cd4f10(DAT_0104da4c);
            reinterpret_cast<::S_00cd4b60 *>(&(inverse))->FUN_00cd4b60();
            Matrix3D72 sum;
            copyMatrix(sum, previous);
            sum.FUN_00cd5140(inverse);
            __m128 half = _mm_load_ss(&::fnv_00c88020::DAT_01016248);
            current.FUN_00cd4d40(half, sum);
        } while (++iteration < 30 && !((bool)(reinterpret_cast<::CMatrixOps *>(&(current))->FUN_00cd4e00((unsigned char *)&(equal), (const ::Matrix3x4 *)&(previous), DAT_0104da4c))));
        copyMatrix(result->basis, current);
    }
    __m128 x = normalizedD72(result->basis.x);
    __m128 y = normalizedD72(result->basis.y);
    __m128 z = normalizedD72(result->basis.z);
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(z, z, 0xd2), _mm_shuffle_ps(y, y, 0xc9)),
                              _mm_mul_ps(_mm_shuffle_ps(z, z, 0xc9), _mm_shuffle_ps(y, y, 0xd2)));
    __m128 determinant = dot3D72(cross, x);
    if (scalarD72(determinant) < 0.0f)
    {
        __m128 minusOne = _mm_load_ss(&DAT_01012054);
        x = _mm_mul_ps(_mm_shuffle_ps(minusOne, minusOne, 0), x);
    }
    result->flips = scalarD72(determinant) < 0.0f;
    {
        Matrix3D72 rotation;
        rotation.x = x;
        rotation.y = y;
        rotation.z = z;
        QuaternionD72 quaternion;
        reinterpret_cast<::FUN_00827200_class *>(&(quaternion))->FUN_00cb26e0((intptr_t)&(rotation));
        result->rotation.value = quaternion.value;
    }
    reinterpret_cast<::FUN_005611c0_t *>(&(result->rotation))->FUN_005611c0();
    Matrix4D72 inverseMatrix;
    {
        TransformD72 rotationTransform;
        reinterpret_cast<::RotationRows *>(&(rotationTransform))->FUN_00cb2d90((void *)&(result->rotation));
        rotationTransform.translation = result->translation;
        TransformD72 inverseTransform;
        reinterpret_cast<::FUN_00cb21e0_shell *>(&(inverseTransform))->FUN_00cb21e0((const ::Matrix44 *)&(rotationTransform));
        reinterpret_cast<::FUN_00de9080_Class *>(&(inverseMatrix))->CopyFromFloats(reinterpret_cast<const float*>(&inverseTransform));
    }
    reinterpret_cast<::FUN_00de8f10_Class *>(&(inverseMatrix))->FUN_00de8f10();
    Matrix4D72* scaleSkew = &result->scaleSkew;
    scaleSkew->FUN_00de8da0(inverseMatrix, original);
    Matrix4D72* skew = &result->skew;
    result->scale = _mm_setr_ps(result->scaleSkew.xx, result->scaleSkew.yy, result->scaleSkew.zz, DAT_01011d78);
    __m128 one = _mm_load_ss(&::DAT_01012068);
    __m128 delta = _mm_sub_ps(result->scale, _mm_shuffle_ps(one, one, 0));
    __m128 tolerance = _mm_load_ss(&::AngularDashpotApplyD4DCB0::DAT_01017d00);
    tolerance = _mm_shuffle_ps(tolerance, tolerance, 0);
    unsigned char* flagAddress = &result->hasScale;
    *flagAddress = (_mm_movemask_ps(_mm_cmple_ps(_mm_and_ps(delta, DAT_01017d10), tolerance)) & 7) != 7;
    Matrix4D72 inverseScale;
    diagD72(inverseScale, result->scaleX, result->scaleY, result->scaleZ);
    skew->FUN_00de8da0(inverseScale, *scaleSkew);
    __m128 dz = _mm_and_ps(_mm_sub_ps(skew->z, (*reinterpret_cast<const ::Matrix4D72 *>(&::DAT_0126a3e0)).z), DAT_01017d10);
    __m128 dw = _mm_and_ps(_mm_sub_ps(skew->w, (*reinterpret_cast<const ::Matrix4D72 *>(&::DAT_0126a3e0)).w), DAT_01017d10);
    __m128 dx = _mm_and_ps(_mm_sub_ps(skew->x, (*reinterpret_cast<const ::Matrix4D72 *>(&::DAT_0126a3e0)).x), DAT_01017d10);
    __m128 dy = _mm_and_ps(_mm_sub_ps(skew->y, (*reinterpret_cast<const ::Matrix4D72 *>(&::DAT_0126a3e0)).y), DAT_01017d10);
    __m128 difference = _mm_max_ps(_mm_max_ps(dx, dy), _mm_max_ps(dz, dw));
    result->hasSkew = (_mm_movemask_ps(_mm_cmple_ps(difference, tolerance)) & 15) != 15;
}


void __cdecl FUN_00d687c0(void);



extern void* DAT_01269008;



void* __cdecl FUN_00d687c0(uintptr_t value);

void FUN_00de29b0(int a, int b);

// FUN_00d688f0 : tiny global getter.
// Reads the 4-byte global at DAT_0126900c and returns it in eax.
extern int DAT_0126900c;

extern char DAT_0126905c;

void __cdecl FUN_00d6adf0(S_00d6adf0_Obj* obj);

extern int DAT_0126908c;


void __cdecl FUN_00d6ae90(FUN_00c90e00_Obj* param_1, int param_2);

int __cdecl FUN_00d6aeb0(VtblForwarder* p);

extern int DAT_01269104;

extern const double g_dD6C180Offset;

void __cdecl ConstructHkDerived(void* pvObject, int iFinishing);

extern int DAT_010d14f8;



void WriteSwapped(char**, int, int);

void FUN_00d60900(char* p);













void __cdecl FUN_00d2caa0(void* pvDst, void* pvSrc, unsigned int uiNumBytes);


void __cdecl FUN_00d2caa0(void* value1, unsigned int value2, unsigned int value3);






void* __cdecl AllocateRecordWithData(void* data);


Base2_d632c0* FUN_00d632c0(const void* a1);


extern int DAT_01268fc8;

void* __cdecl FUN_00d645f0(uintptr_t value);




extern int DAT_010d14f8;



hkpCollisionAgentD62* __cdecl FUN_00d62f20(void* contactMgr);

void __cdecl AssignNodeFlags(Node** nodes, int count, unsigned seed);


void __cdecl FUN_00d79250(void* a, void* b, hkResultD794* out, int flags, float f);




struct StiffSpringBodyBF60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    __m128 v30;
};

union StiffSpringSegmentBF60
{
    struct
    {
        __m128 from;
        __m128 to;
        __m128 dir;
    };
};

struct StiffSpringAtomBF60
{
    int unk00;
    float value;
};

// @fnv 0x00d6bf60
static __declspec(noinline) void FUN_00d6bf60(StiffSpringBodyBF60* oa, StiffSpringBodyBF60* ob, StiffSpringAtomBF60* ps,
                                              void* p4, intptr_t p5)
{
    StiffSpringSegmentBF60 v;
    v.from = oa->v30;
    v.to = ob->v30;
    __m128 d = _mm_sub_ps(v.from, v.to);
    __m128 sq = _mm_mul_ps(d, d);
    __m128 sy = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 sz = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 sum = _mm_add_ss(sz, _mm_add_ss(sy, sq));
    float dist;
    _mm_store_ss(&dist, _mm_sqrt_ss(sum));
    float scale = dist;
    if (dist <= ::DAT_0104da4c)
    {
        v.dir = (*reinterpret_cast<__m128 *>(&::DAT_01268370));
        scale = 0.0f;
    }
    else
    {
        float inv = 1.0f / dist;
        v.dir = d;
        _ReadWriteBarrier();
        __m128 s = _mm_load_ss(&inv);
        v.dir = _mm_mul_ps(d, _mm_shuffle_ps(s, s, 0));
    }
    ::FUN_00dcf5b0((::Input_dcf5b0 *)(::StiffSpringSegmentBF60 *)(&v), (::S_00dcf100_Cfg *)(p4), (::Jacobian_dcf5b0 **)(p5), ps->value - scale);
}

__declspec(noinline) void InvokeStiffSpringBF60(StiffSpringBodyBF60* a, StiffSpringBodyBF60* b, StiffSpringAtomBF60* s,
                                                void* p4, intptr_t p5)
{
    FUN_00d6bf60(a, b, s, p4, p5);
    FUN_00d6bf60(b, a, s, p4, p5);
}

namespace fnv_00d6c080 {


struct F4
{
    float x;
    float y;
    float z;
    float w;
};

struct FUN_004b4ab0_Class
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        __m128 m;
    };

};

struct Obj4
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    F4 u20;
    F4 u30;
    F4 u40;
    int u50;
    int u54;
    int u58;
    int u5c;
};

static __m128 cross4(__m128 a, __m128 b)
{
    __m128 a_yzx = _mm_shuffle_ps(a, a, 0xC9);
    __m128 b_zxy = _mm_shuffle_ps(b, b, 0xD2);
    __m128 a_zxy = _mm_shuffle_ps(a, a, 0xD2);
    __m128 b_yzx = _mm_shuffle_ps(b, b, 0xC9);
    return _mm_sub_ps(_mm_mul_ps(a_yzx, b_zxy), _mm_mul_ps(a_zxy, b_yzx));
}

// @fnv 0x00d6c080
static __declspec(noinline) void FUN_00d6c080(Obj4* firstObject, F4* second, F4* first, Obj4* secondObject,
                                              float divisor, float multiplier, F4* out)
{
    float scale = (1.0f / divisor) * multiplier;
    __m128 s0 = _mm_load_ss(&scale);
    __m128 diff = _mm_sub_ps(_mm_load_ps(&first->x), _mm_load_ps(&second->x));
    _mm_store_ps(&out->x, diff);
    __m128 d1 = _mm_sub_ps(_mm_load_ps(&second->x), _mm_load_ps(&firstObject->u40.x));
    __m128 d2 = _mm_sub_ps(_mm_load_ps(&first->x), _mm_load_ps(&secondObject->u40.x));
    FUN_004b4ab0_Class r1;
    FUN_004b4ab0_Class r2;
    reinterpret_cast<::FUN_004b4ab0_Class *>(&(r1))->FUN_004b4ab0((intptr_t)&firstObject->u50, (intptr_t)&firstObject->u20);
    reinterpret_cast<::FUN_004b4ab0_Class *>(&(r2))->FUN_004b4ab0((intptr_t)&secondObject->u50, (intptr_t)&secondObject->u20);
    __m128 s = _mm_shuffle_ps(s0, s0, 0);
    __m128 c2 = cross4(d2, r2.m);
    __m128 c1 = cross4(d1, r1.m);
    _mm_store_ps(&out->x, _mm_sub_ps(_mm_add_ps(diff, _mm_mul_ps(c2, s)), _mm_mul_ps(c1, s)));
}

F4 g_first;
F4 g_second;
F4 g_out;
Obj4 g_obj1;
Obj4 g_obj2;
float g_div = 2.0f;
float g_mul = 3.0f;

void dummy_caller()
{
    FUN_00d6c080(&g_obj1, &g_second, &g_first, &g_obj2, g_div, g_mul, &g_out);
}
}

inline float Fwd(float x)
{
    return x;
}

// @fnv 0x00d6b3c0
static __declspec(noinline) float FUN_00d6b3c0(__m128* p, float a1, float a2)
{
    __m128 value = _mm_load_ps((const float*)p);
    float minSq = a1 * a1;
    __m128 sq = _mm_mul_ps(value, value);
    __m128 y2 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 z2 = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 s1 = _mm_add_ss(y2, sq);
    __m128 s2 = _mm_add_ss(z2, s1);
    float lenSq;
    _mm_store_ss(&lenSq, s2);
    float ratio = lenSq / minSq;
    if (minSq < lenSq)
    {
        float maxSq = a2 * a2;
        if (maxSq > lenSq)
        {
            float q = minSq / lenSq;
            float r = sqrtf(q);
            float scale = Fwd(r);
            __m128 s = _mm_load_ss(&scale);
            __m128 b = _mm_shuffle_ps(s, s, 0);
            __m128 res = _mm_mul_ps(b, value);
            _mm_store_ps((float*)p, res);
        }
        else
        {
            float scale = (a1 * a2) / lenSq;
            __m128 s = _mm_load_ss(&scale);
            __m128 b = _mm_shuffle_ps(s, s, 0);
            __m128 res = _mm_mul_ps(b, value);
            _mm_store_ps((float*)p, res);
        }
        return ratio;
    }
    return ratio;
}

volatile __m128* g_vec;

volatile float g_a1, g_a2, g_sink;

void zz_caller(void)
{
    g_sink = FUN_00d6b3c0((__m128*)g_vec, g_a1, g_a2);
}

#include "generated/data/staging/blk_00d60000_o2.inc"
