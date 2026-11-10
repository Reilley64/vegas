
// src/staging/blk_00600000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include <new>
#include <cctype>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004612e0_shell.h"
#include "fnv/decl/FUN_005545f0.h"
#include "fnv/decl/FUN_005c3bd0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00604780_shell.h"
#include "fnv/decl/FUN_0060c120_cls.h"
#include "fnv/decl/FUN_0060f5f0.h"
#include "fnv/decl/FUN_0061f260_shell.h"
#include "fnv/decl/FUN_0061f340_shell.h"
#include "fnv/decl/FUN_00659210_Class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/Holder_FUN_0060b9b0.h"
#include "fnv/decl/Host615730.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/NiFormArray.h"
#include "fnv/decl/NiTObjectArrayA47.h"
#include "fnv/decl/PlayerMover.h"
#include "fnv/decl/RTTIEntry.h"
#include "fnv/decl/ReputationTracker.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TESResponse.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0060f2c0__FUN_0060f2c0_shell.h"
#include "fnv/decl/fnv_00619a90__FUN_00619a90_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_005dc000.h"
#include "fnv/symbols_0060b000.h"
#include "fnv/symbols_0060c000.h"
#include "fnv/symbols_00617000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0065f000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01044000.h"
#include "fnv/symbols_0104a000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_011c3000.h"
#include "../../include/layout_support.h"

struct FUN_00600ad0_cls
{
    const char* v;
    void FUN_00600fd0(int, int);
    FUN_00600ad0_cls* FUN_00600ad0(int a, bool b);
};

struct FUN_00600d70_shell
{
    void FUN_00600d70();
};

struct FUN_00600b00_shell
{
    const char* m_p;
    ~FUN_00600b00_shell();
};

// @fnv 0x00600b00
FUN_00600b00_shell::~FUN_00600b00_shell()
{
    m_p = "@\r`";
    reinterpret_cast<::FUN_00600d70_shell *>(this)->FUN_00600d70();
}

extern int DAT_0104a068;
struct FUN_00600d10_class
{
    int* m_vft;
    void FUN_00601000(int a, int b);
    FUN_00600d10_class(int a, int b);
};
extern "C" void __cdecl FUN_00601100(int);
extern int DAT_0104a090;

struct FUN_006010d0_Class
{
    void* m_field_0;
    int FUN_00601100(int);
    void* InitializeWithGlobal(int param);
};

struct FUN_006053f0_class
{
    char pad[0x1f8];
    float unk1f8;
    void FUN_006053f0(float value);
};

// @fnv 0x006053f0
void FUN_006053f0_class::FUN_006053f0(float value)
{
    unk1f8 = value;
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

GlobalObject_0045cf30 g_011cb99c;

// @fnv 0x00605d50
unsigned char FUN_00605d50()
{
    return g_011cb99c.Bool()[0];
}

struct GlobalObject_00869f00
{
    void Clear(bool);
    void Reset();
};
// @fnv 0x0060bac0
void GlobalObject_00869f00::Reset()
{
    *(void**)this = &DAT_0104ab04;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((this))->Clear(true);
}


struct FUN_0060bb40_class
{
    char pad[0x8];
    char unk08;
    void FUN_0060bb40(void* a, void* b, void* c);
};

// @fnv 0x0060bb40
void FUN_0060bb40_class::FUN_0060bb40(void* apArg1, void* apArg2, void* apArg3)
{
    ::FUN_0060be00((::C60BE00Element *)(apArg1), (::C60BE00Element *)(apArg2), (::C60BE00Element *)(apArg3), (::C60BE00Allocator *)(void *)&unk08);
}

namespace fnv_0060bdd0 {
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_0060bdd0();
};
// @fnv 0x0060bdd0
AX* AX::FUN_0060bdd0()
{
    *reinterpret_cast<void**>(this) = &(*reinterpret_cast<void * *>(&::DAT_0104ab04));
    FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_0060bdd0

// @fnv 0x0060be50
void FUN_0060be50(intptr_t start, int end, const float* apfSrc)
{
    for (; start != end; start += 4)
        *(float*)start = *apfSrc;
}

extern "C" void __cdecl CallWithFlagValues(void*, void*, void*);

// @fnv 0x0060bed0
void __cdecl FUN_0060bed0(void* apArg1, void* apArg2, void* apArg3)
{
    CallWithFlagValues(apArg1, apArg2, apArg3);
}


// @fnv 0x0060c270
void __cdecl FUN_0060c270(intptr_t aiArg1, intptr_t aiArg2, intptr_t aiArg3, intptr_t aiArg4)
{
    ::UninitCopyChecked((int *)(aiArg1), (int *)(aiArg2), (int *)(aiArg3), aiArg4);
}

struct FUN_0060c5c0_class
{
    char unk00;
    char unk01;
    char pad02[0x2];
    float unk04;
    FUN_0060c5c0_class* FUN_0060c5c0();
};

// Clears the two leading bytes and the float at offset 4 of this object, then returns this.
// @fnv 0x0060c5c0
FUN_0060c5c0_class* FUN_0060c5c0_class::FUN_0060c5c0()
{
    unk00 = 0;
    unk01 = 0;
    unk04 = 0.0f;
    return this;
}

struct FUN_0060fd90_Class
{
    bool IsFlag2Set();
};
// @fnv 0x0060fd90
bool FUN_0060fd90_Class::IsFlag2Set()
{
    return (((unsigned char*)this)[0] & 2) != 0;
}

struct FUN_00610190_cls
{
    bool IsFlagSet();
};

// @fnv 0x00610190
bool FUN_00610190_cls::IsFlagSet()
{
    if (*(unsigned char*)this & 1)
        return true;
    return false;
}

struct FUN_006130c0_Class
{
    void* FUN_006130c0(int index);
};

// @fnv 0x006130c0
void* FUN_006130c0_Class::FUN_006130c0(int index)
{
    return &((char*)this)[0x50 + index * 2];
}

struct FUN_00613870_Class
{
    char pad[0x94];
    int unk94[1];
    int FUN_00613870(int index);
};

// @fnv 0x00613870
int FUN_00613870_Class::FUN_00613870(int index)
{
    return unk94[index];
}

struct FUN_00613890_Class
{
    char pad[0x94];
    int unk94[1];
    void SetIndexedInt(int index, int value);
};

// @fnv 0x00613890
void FUN_00613890_Class::SetIndexedInt(int index, int value)
{
    unk94[index] = value;
}

void FUN_00618940(void*);

// @fnv 0x00618920
void FUN_00618920(void* self)
{
    FUN_00618940(self);
}

// @fnv 0x0061bbf0
char FUN_0061bbf0(unsigned char a)
{
    if (a == 0x46)
        return 1;
    return 0;
}

extern int DAT_0104d450;
struct FUN_0061bef0_class
{
    void* vtbl;
    void FUN_0061c120(void* a, void* b);
    FUN_0061bef0_class(void* a, void* b);
};
// Calls FUN_0061c120 with the two arguments, then sets the object's vtbl to &DAT_0104d450.
// @fnv 0x0061bef0
FUN_0061bef0_class::FUN_0061bef0_class(void* apArg1, void* apArg2)
{
    FUN_0061c120(apArg1, apArg2);
    vtbl = &DAT_0104d450;
}

namespace fnv_0061bf50 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0061bf50_Class
{
    void InitAndClear();
};
// @fnv 0x0061bf50
void FUN_0061bf50_Class::InitAndClear()
{
    *reinterpret_cast<int**>(this) = &::DAT_0104d458;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}
}  // namespace fnv_0061bf50

// @fnv 0x0061f420
bool FUN_0061f420(std::uintptr_t auiValue, std::uintptr_t auiOther)
{
    if (auiValue < auiOther)
        return true;
    return false;
}

class TESResponseList
{
  public:
    void ClearResponses();
};

struct FUN_0061f440 : TESResponseList
{
    void ClearResponses();
};

// @fnv 0x0061f440
void FUN_0061f440::ClearResponses()
{
    TESResponseList::ClearResponses();
}

extern int DAT_0104d948;
struct FUN_0061fa10_class
{
    void FUN_0061fa70(int);
    void* FUN_0061fa10(int a);
};
// Calls FUN_0061fa70 with a, stores the address of DAT_0104d948 at this, and returns this.
// @fnv 0x0061fa10
void* FUN_0061fa10_class::FUN_0061fa10(int a)
{
    FUN_0061fa70(a);
    *reinterpret_cast<void**>(this) = &DAT_0104d948;
    return this;
}

extern int DAT_0104a0b0;

struct FUN_00600eb0_cls
{
    void* vtbl;
    int a;
    void* b;
    void RemoveAll();
    void FUN_00600eb0();
};

// Sets the vtable pointer, calls RemoveAll, then frees the b pointer via NiFreeAlias.
// @fnv 0x00600eb0
void FUN_00600eb0_cls::FUN_00600eb0()
{
    *reinterpret_cast<void**>(this) = &DAT_0104a0b0;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(b);
}

extern int DAT_0104d968;

struct NiTPointerMapIntInt : public NiTPointerMap<int, int>
{
    void FUN_0061fb40();
};

// Resets the vtable pointer, removes all entries, then frees the pointer stored at offset 8.
// @fnv 0x0061fb40
void NiTPointerMapIntInt::FUN_0061fb40()
{
    *(int**)this = &DAT_0104d968;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

extern int DAT_0104a060;
struct FUN_00600b90_Cls
{
    void* m0;
    void* m4;
    void FUN_00600b90();
};
// Sets m0 to the address of DAT_0104a060 and frees the m4 pointer via MyDeallocate.
// @fnv 0x00600b90
void FUN_00600b90_Cls::FUN_00600b90()
{
    m0 = (void*)&DAT_0104a060;
    ::FUN_004ede70(m4);
}


struct FUN_00600ee0_cls
{
    void* FUN_00600ee0(unsigned int flags);
};

// Calls FUN_00600eb0 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00600ee0
void* FUN_00600ee0_cls::FUN_00600ee0(unsigned int flags)
{
    ((FUN_00600eb0_cls*)this)->FUN_00600eb0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_00600e50_class
{
    void FUN_00600e50();
    void* FUN_00600f10(unsigned int flags);
};

struct FUN_00600d90_shell
{
    void FUN_00600d90();
    void* FUN_00600f40(unsigned int flags);
};
struct FUN_005ffbd0_cls
{
public:
    void FUN_005ffbd0();
};
struct FUN_00600f70_cls
{
    void* FUN_00600f70(unsigned int flags);
};
// @fnv 0x00600f70
void* FUN_00600f70_cls::FUN_00600f70(unsigned int flags)
{
    reinterpret_cast<::FUN_00600b90_Cls *>((((FUN_005ffbd0_cls*)this)))->FUN_00600b90();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00600fa0 {
struct FUN_005ffbd0_cls
{
    void* FUN_00600fa0(unsigned int flags);
};
// Calls FUN_005ffbd0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x00600fa0
void* FUN_005ffbd0_cls::FUN_00600fa0(unsigned int flags)
{
    reinterpret_cast<::FUN_005ffbd0_cls *>(this)->FUN_005ffbd0();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_00600fa0

extern int DAT_0104a0d0;
struct FUN_006010a0_holder
{
};
struct FUN_00600fd0 : FUN_006010a0_holder
{
    FUN_00600fd0(int, bool);
};
struct FUN_00601070_shell : FUN_00600b00_shell
{
    void* FUN_00601070(unsigned int flags);
};

// Calls FUN_00600d70, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x00601070
void* FUN_00601070_shell::FUN_00601070(unsigned int flags)
{
    reinterpret_cast<::FUN_00600d70_shell *>(this)->FUN_00600d70();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern int DAT_0104a070;
struct FUN_006010a0_Class
{
    int* m_vft;
    int m_field_4;
    int m_field_8;
    int m_field_c;
    unsigned char m_field_10;
    FUN_006010a0_Class* FUN_006010a0(int a, unsigned char b);
};
// Calls FUN_00600fd0 with the two arguments, sets v to a string literal, and returns this.
// @fnv 0x00600ad0
FUN_00600ad0_cls* FUN_00600ad0_cls::FUN_00600ad0(int a, bool b)
{
    new ((void *)this) ::FUN_00600fd0(a, b);
    v = "@\r`";
    return this;
}
// @fnv 0x00600fd0
FUN_00600fd0::FUN_00600fd0(int a, bool b)
{
    reinterpret_cast<::FUN_006010a0_Class *>(this)->FUN_006010a0(a, b);
    *(void**)this = (void*)&DAT_0104a0d0;
}
// Calls InitializeWithGlobal on this, sets the vtable to DAT_0104a070, stores b in m_field_10 and returns this.
// @fnv 0x006010a0
FUN_006010a0_Class* FUN_006010a0_Class::FUN_006010a0(int a, unsigned char b)
{
    ((FUN_006010d0_Class*)this)->InitializeWithGlobal(a);
    m_vft = &DAT_0104a070;
    m_field_10 = b;
    return this;
}

struct FUN_00601100_cls
{
    void* vtbl;
    int a;
    void* b;
    int c;
    FUN_00601100_cls* FUN_00601100(int size);
};
// Calls FUN_00601100 with param, stores the address of DAT_0104a090 in m_field_0, and returns this.
// @fnv 0x006010d0
void* FUN_006010d0_Class::InitializeWithGlobal(int param)
{
    reinterpret_cast<::FUN_00601100_cls *>(this)->FUN_00601100(param);
    m_field_0 = &DAT_0104a090;
    return this;
}
// Sets the vtable, stores size, allocates size*4 bytes, zeroes them into b, and returns this.
// @fnv 0x00601100
FUN_00601100_cls* FUN_00601100_cls::FUN_00601100(int size)
{
    int n;
    vtbl = &DAT_0104a0b0;
    a = size;
    c = 0;
    n = a * 4;
    b = (void*)::FUN_00aa1070(n);
    ::FUN_00403d30(b, 0, a * 4);
    return this;
}

extern "C" void* __cdecl DAT_01199fc4[];

// @fnv 0x00605d40
void* __cdecl FUN_00605d40(int index)
{
    return DAT_01199fc4[index];
}

int __cdecl CallWithFlag(int*);
// Computes a value from a and b via CallWithFlag and passes both results with c to FUN_0060be50.
// @fnv 0x0060bb70
void __cdecl FUN_0060bb70(int a, int b, float const* c)
{
    FUN_0060be50(CallWithFlag(&a), CallWithFlag(&b), c);
}

namespace fnv_0060bc60 {

struct FUN_006013a0_shell
{
    void* FUN_0060bc60(int flags);
};

// Calls FUN_0060b9b0, frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0060bc60
void* FUN_006013a0_shell::FUN_0060bc60(int flags)
{
    reinterpret_cast<::Holder_FUN_0060b9b0 *>(this)->FUN_0060b9b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0060bc60

struct FUN_006013a0_shell
{
    void FUN_006013a0();
    FUN_006013a0_shell* FUN_0060bc90(unsigned int flags);
};

// Calls FUN_006013a0, deletes this when flags has bit 1 set, and returns this.
// @fnv 0x0060bc90
FUN_006013a0_shell* FUN_006013a0_shell::FUN_0060bc90(unsigned int flags)
{
    FUN_006013a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0060bcc0_holder
{
    void* FUN_0060bcc0(unsigned int);
};
// Calls Reset on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0060bcc0
void* FUN_0060bcc0_holder::FUN_0060bcc0(unsigned int flags)
{
    ((GlobalObject_00869f00*)this)->Reset();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0060bcf0_class
{
    void* FUN_0060bcf0(unsigned int flags);
};
template <typename T, typename A> class NiTArray;
template <> class NiTArray<int, int>
{
};
struct FUN_0060bd90_cls
{
    char _0[8];
    unsigned short m8;
    char _a[4];
    unsigned short mE;
    unsigned int FUN_0060bd90(unsigned int, uintptr_t);
};
// Grows the array to mE + a when a is at least m8, then calls FUN_0060c120(a, b) and returns a.
// @fnv 0x0060bd90
unsigned int FUN_0060bd90_cls::FUN_0060bd90(unsigned int uiIndex, uintptr_t b)
{
    if (uiIndex >= m8)
    {
        reinterpret_cast<::NiTObjectArrayA47 *>((((NiTArray<int, int>*)this)))->FUN_0060bef0((unsigned int)(mE + uiIndex));
    }
    reinterpret_cast<::FUN_0060c120_cls *>(this)->FUN_0060c120(uiIndex, (::SlotTarget *)(b));
    return uiIndex;
}


// @fnv 0x0060c290
void* __cdecl FUN_0060c290(char* apSource, char* pDest, char* pEnd)
{
    int nCount = (pDest - apSource) >> 2;
    void* pResult4 = (void*)(pEnd - nCount * 4);
    if (nCount > 0)
        fnv::crt::memmove_s(pResult4, nCount * 4, apSource, nCount * 4);
    return pResult4;
}

// Copies the float value pointed to by param_3 into param_2 consecutive floats starting at param_1.
// @fnv 0x0060c410
void __cdecl FUN_0060c410(float* afDest, unsigned int auiCount, float* afValue)
{
    for (; auiCount > 0; auiCount--, afDest++)
    {
        *afDest = *afValue;
    }
}

struct FUN_0060f410_class
{
    void* FUN_0060f410(unsigned int flags);
};
// Calls FUN_0060f5f0, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0060f410
void* FUN_0060f410_class::FUN_0060f410(unsigned int flags)
{
    reinterpret_cast<::FUN_0060f5f0 *>(this)->FUN_0060f5f0::~FUN_0060f5f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct S_00616a60
{
    void FUN_00616a60(int);
};
struct FUN_00618890_cls
{
    void FUN_006188c0();
    FUN_00618890_cls* FUN_00618890(unsigned int flags);
};
struct FUN_0061c090_class
{
    void* FUN_0061c090(unsigned int flags);
};
// @fnv 0x0061c090
void* FUN_0061c090_class::FUN_0061c090(unsigned int flags)
{
    reinterpret_cast<::RTTIEntry *>((this))->FUN_0061bcf0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void FUN_00618940(void*);
struct FUN_0061c0c0_class
{
    void* FUN_0061c0c0(unsigned int flags);
};
// Calls FUN_00618940 on this, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0061c0c0
void* FUN_0061c0c0_class::FUN_0061c0c0(unsigned int flags)
{
    FUN_00618940(this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0061bf50_class
{
    void* FUN_0061c0f0(unsigned int flags);
};

// Calls InitAndClear, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0061c0f0
void* FUN_0061bf50_class::FUN_0061c0f0(unsigned int flags)
{
    reinterpret_cast<::fnv_0061bf50::FUN_0061bf50_Class *>(this)->InitAndClear();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

class TESTopicInfo
{
  public:
    virtual void F00() = 0;
    virtual void F01() = 0;
    virtual void F02() = 0;
    virtual void F03() = 0;
    virtual void F04() = 0;
    virtual void F05() = 0;
    virtual void F06() = 0;
    virtual void F07() = 0;
    virtual void F08() = 0;
    virtual void F09() = 0;
    virtual void F10() = 0;
    virtual void F11() = 0;
    virtual void F12() = 0;
    virtual void F13() = 0;
    virtual void F14() = 0;
    virtual void F15() = 0;
    virtual void F16() = 0;
    virtual void F17() = 0;
    virtual void F18(unsigned int) = 0;
    void MarkAsRefusal();
    char _pad[30];
    unsigned char m_22;
};
// @fnv 0x0061f220
void TESTopicInfo::MarkAsRefusal()
{
    if (!reinterpret_cast<::FUN_0061f260_shell *>(this)->FUN_0061f260())
    {
        m_22 = 1;
        F18(0x80000000);
    }
}

struct FUN_005545d0_Class
{
    void* FUN_0061f550(unsigned int flags);
};
// Calls FUN_005545f0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0061f550
void* FUN_005545d0_Class::FUN_0061f550(unsigned int flags)
{
    reinterpret_cast<::FUN_005545f0 *>(this)->FUN_005545f0::~FUN_005545f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_0061fa40_class
{
    void FUN_0061fae0();
    void* FUN_0061fa40(unsigned int flags);
};

namespace fnv_0061fa70 {
struct FUN_0061fa70_class
{
    void* FUN_0061fa70(int a);
};
// Sets the vtable, stores the count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x0061fa70
void* FUN_0061fa70_class::FUN_0061fa70(int aiCount)
{
    struct Layout
    {
        void* m_pVtbl;
        int m_iCount;
        void* m_pData;
        int m_iUnk0c;
    };
    Layout* self = reinterpret_cast<Layout*>(this);
    self->m_pVtbl = &DAT_0104d968;
    self->m_iCount = aiCount;
    self->m_iUnk0c = 0;
    unsigned int iAllocationSize = (unsigned int)self->m_iCount << 2;
    self->m_pData = ::FUN_00aa1070(iAllocationSize);
    memset(self->m_pData, 0, (unsigned int)self->m_iCount << 2);
    return this;
}
}  // namespace fnv_0061fa70

struct FUN_0061fb70_Cls
{
    void* FUN_0061fb70(unsigned int flags);
};
// @fnv 0x0061fb70
void* FUN_0061fb70_Cls::FUN_0061fb70(unsigned int flags)
{
    ((NiTPointerMapIntInt*)this)->FUN_0061fb40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct ActorCombatGroup;
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short size);
};
struct FUN_00601000
{
    int* vft;
    ActorCombatGroup** p;
    unsigned short a;
    unsigned short c;
    unsigned short b;
    unsigned short d;
    FUN_00601000(short x, short y);
};
// Calls FUN_00601000 with the two arguments, then stores the address of DAT_0104a068 into m_vft.
// @fnv 0x00600d10
FUN_00600d10_class::FUN_00600d10_class(int aiArg1, int aiArg2)
{
    new ((void *)this) ::FUN_00601000(aiArg1, aiArg2);
    m_vft = &DAT_0104a068;
}
// Sets the vtable, stores x and y, zeroes c and b, and allocates a elements into p when a is positive, otherwise p is null.
// @fnv 0x00601000
FUN_00601000::FUN_00601000(short x, short y)
{
    vft = (int*)&DAT_0104a060;
    a = x;
    d = y;
    c = 0;
    b = 0;
    if (a > 0)
        p = NiTMallocInterface_0096afc0::Allocate(a);
    else
        p = 0;
}

namespace fnv_0060bd20 {
struct ActorCombatGroup;
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
struct FUN_0060bd20_class
{
    int* m_vft;
    ActorCombatGroup** m_p;
    unsigned short m8;
    unsigned short m_kPointA;
    unsigned short m_iThirdValue;
    unsigned short m_usTrailingValue;
    FUN_0060bd20_class(unsigned short a, unsigned short b);
};
// @fnv 0x0060bd20
FUN_0060bd20_class::FUN_0060bd20_class(unsigned short a, unsigned short b)
{
    m_vft = &::DAT_0104aae0;
    m8 = a;
    m_usTrailingValue = b;
    m_kPointA = 0;
    m_iThirdValue = 0;
    if (m8 > 0)
        m_p = NiTMallocInterface_0096afc0::Allocate(m8);
    else
        m_p = 0;
}
}  // namespace fnv_0060bd20

struct Setting_S
{
};
struct FUN_00616c20_cls
{
};
extern Setting_S originalRuntimeFloatSetting51;
extern Setting_S originalRuntimeFloatSetting50;
struct FUN_00616c20_shell : FUN_00616c20_cls
{
    void FUN_00616c20(bool b);
};
// Reads one of two runtime float settings depending on b and passes it to FUN_00615730 with index 0.
// @fnv 0x00616c20
void FUN_00616c20_shell::FUN_00616c20(bool abUseFirstSetting)
{
    float f;
    if (abUseFirstSetting)
        f = *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting51))));
    else
        f = *((float *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting50))));
    reinterpret_cast<::Host615730 *>(this)->FUN_00615730(0, f);
}

struct FUN_00619a90_shell
{
};
struct BSSimpleListShell
{
    bool _ref_008256d0();
};
struct DH
{
};
// If a is non-zero, walks the list from g_dataHandler and calls ProcessTopicInfoList(a) on each item until _ref_008256d0 is true.
// @fnv 0x00619b60
void FUN_00619b60(intptr_t a)
{
    if (a)
    {
        BSSimpleListShell* list = ((::BSSimpleListShell *)(reinterpret_cast<::FUN_004612e0_shell *>((g_dataHandler))->FUN_004612e0()));
        while (list && !list->_ref_008256d0())
        {
            reinterpret_cast<::fnv_00619a90::FUN_00619a90_shell *>(((*((::FUN_00619a90_shell **)(new ((void *)(list)) ::Vec3())))))->ProcessTopicInfoList(a);
            list = ((::BSSimpleListShell *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
        }
    }
}

namespace fnv_0061c120 {
struct ActorCombatGroup;
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned int size);
};
struct FUN_0061c120
{
    void* vtbl;
    ActorCombatGroup** m_pData;
    unsigned int m_usSize;
    unsigned int m_usAllocSize;
    unsigned int m_uiMaxSize;
    unsigned int m_uiMax;
    FUN_0061c120(unsigned int size, unsigned int max);
};
// Initialises the array: sets the vtable, stores size and max, zeroes allocation fields, and allocates m_pData when size is non-zero.
// @fnv 0x0061c120
FUN_0061c120::FUN_0061c120(unsigned int size, unsigned int max)
{
    vtbl = (void*)&(*reinterpret_cast<int *>((void *)&::DAT_0104d448));
    m_usSize = size;
    m_uiMax = max;
    m_usAllocSize = 0;
    m_uiMaxSize = 0;
    if (m_usSize > 0)
        m_pData = NiTMallocInterface_0096afc0::Allocate(m_usSize);
    else
        m_pData = 0;
}
}  // namespace fnv_0061c120


// Computes the element count between param_1 and param_2, copies that many 4-byte elements from param_1 to param_3, and returns the end pointer in param_3.
// @fnv 0x0060c3c0
void* __cdecl FUN_0060c3c0(void* pBegin, void* pEnd, void* pDest)
{
    unsigned int count = ((char*)pEnd - (char*)pBegin) >> 2;
    void* result = (char*)pDest + count * 4;
    if (count > 0)
    {
        fnv::crt::memmove_s(pDest, count << 2, pBegin, count << 2);
    }
    return result;
}

struct StartMenu
{
    char const* GetMenuTitle();
};

class GlobalObject_0040c150 : public StartMenu
{
  public:
    char const* FUN_006167d0();
};

extern GlobalObject_0040c150 g_011cba18;
extern GlobalObject_0040c150 g_011cba4c;
extern GlobalObject_0040c150 g_011cba64;
extern GlobalObject_0040c150 g_011cbaa0;
extern GlobalObject_0040c150 g_011cbab0;
extern GlobalObject_0040c150 g_011cbbaec;
extern GlobalObject_0040c150 g_011cbb40;
extern GlobalObject_0040c150 g_011cbb4c;
extern GlobalObject_0040c150 g_011cbb80;
extern GlobalObject_0040c150 g_011cbb8c;
extern GlobalObject_0040c150 g_011cbbcc;
extern GlobalObject_0040c150 g_011cbbfc;
extern GlobalObject_0040c150 g_011cbcf0;
extern GlobalObject_0040c150 g_011cbd08;
extern GlobalObject_0040c150 g_011cbd38;
extern GlobalObject_0040c150 g_011cbd44;

// @fnv 0x006167d0
char const* GlobalObject_0040c150::FUN_006167d0()
{
    StartMenu* menuTable[4][4] = {{&g_011cbbfc, &g_011cbbcc, &g_011cbbaec, &g_011cbd44},
                                  {&g_011cbcf0, &g_011cba4c, &g_011cbb4c, &g_011cbb8c},
                                  {&g_011cbb80, &g_011cba18, &g_011cbab0, &g_011cbd08},
                                  {&g_011cbb40, &g_011cbaa0, &g_011cba64, &g_011cbd38}};

    char row = 0;
    char column = 0;
    row = ((bool)(reinterpret_cast<::ReputationTracker *>((this))->GetReputationRank(1)));
    column = ((bool)(reinterpret_cast<::ReputationTracker *>((this))->GetReputationRank(0)));
    return menuTable[column][row]->GetMenuTitle();
}

extern int DAT_0104d9cc[];
struct FUN_0061fea0_shell
{
    void ClearList();
};
struct FUN_0061fc50 : FUN_0061fea0_shell
{
    virtual ~FUN_0061fc50();
};
// @fnv 0x0061fc50
FUN_0061fc50::~FUN_0061fc50()
{
    reinterpret_cast<FUN_0061fea0_shell*>(this)->ClearList();
}

class FNVNode;
class FNVHeap;


class FNVHeap
{
  public:
};

class FNVBaseObj
{
  public:
    virtual ~FNVBaseObj();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FNVBaseObj();
};

class FUN_0060ba40_cls : public FNVBaseObj
{
  public:
    virtual ~FUN_0060ba40_cls();
    FNVNode* m_10;
    FUN_0060ba40_cls();
    void FUN_006b3eb0(unsigned int a, unsigned int b);
};

// Initializes m_10 from FUN_00401020()->FUN_00aa42e0() and calls FUN_006b3eb0 with 0, 0.
// @fnv 0x0060ba40
FUN_0060ba40_cls::FUN_0060ba40_cls()
{
    m_10 = ((::FNVNode *)(reinterpret_cast<::MemoryManager *>((((::FNVHeap *)(::FUN_00401020()))))->GetGeneralAllocator()));
    FUN_006b3eb0(0, 0);
}

class FUN_0060bac0_base
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    ~FUN_0060bac0_base();
};

class FUN_0060bae0_cls : public FUN_0060bac0_base
{
  public:
    virtual void unk00();
    void Clear(int flag);
    ~FUN_0060bae0_cls();
};
// Calls FUN_0060bae0, then frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0060bcf0
void* FUN_0060bcf0_class::FUN_0060bcf0(unsigned int flags)
{
    reinterpret_cast<::FUN_0060bae0_cls *>(this)->FUN_0060bae0_cls::~FUN_0060bae0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0060bae0
FUN_0060bae0_cls::~FUN_0060bae0_cls()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(1);
}

struct S_0060bba0_TagBase
{
};
struct S_0060bba0_TagA : S_0060bba0_TagBase
{
};
struct S_0060bba0_TagB
{
};
struct S_0060bba0_TagC
{
};
S_0060bba0_TagB FUN_0065e750(int*);
S_0060bba0_TagA FUN_0065fd70(int*, int*);
int CallWithFlag(int*);

// Calls CallWithFlagByte with CallWithFlag results for param1 and param2, param3, and FUN_0065fd70/FUN_0065e750 results plus a TagC.
// @fnv 0x0060bba0
void __cdecl FUN_0060bba0(int param1, int param2, intptr_t param3)
{
    ::CallWithFlagByte((void *)(intptr_t)(CallWithFlag(&param1)), (void *)(intptr_t)(CallWithFlag(&param2)), (void *)(param3), (*(unsigned char *)&(const ::S_0060bba0_TagA &)(FUN_0065fd70(&param1, (int*)&param3))));
}

struct B60BC10PtrCatTag
{
};

struct B60BC10RangeCheckedTag
{
};

B60BC10PtrCatTag __cdecl B60BC10PtrCat(void*& first, void*& dest);

// Calls B60BC10FillOpt with first, last, value and extra, passing a pointer-category tag built from first and a range-checked tag.
// @fnv 0x0060bc10
void __cdecl FillRange(void* first, void* last, void* value, void* extra)
{
    ::FUN_0060bed0(first, last, value);
}

struct C60BE00CheckedTag
{
};

struct C60BE00PtrCategory
{
};

struct C60BE00Element;
struct C60BE00Allocator;

C60BE00PtrCategory C60BE00PtrCat(C60BE00Element** ppDest);
C60BE00Element* C60BE00Unchecked(C60BE00Element** ppIter);

// std::uninitialized_copy
// Copies the element range [_First, _Last) to _Dest using _Al, passing the destination pointer category and a checked tag to C60BE00UninitCopy.
// @fnv 0x0060be00
void FUN_0060be00(C60BE00Element* _First, C60BE00Element* _Last, C60BE00Element* _Dest, C60BE00Allocator* _Al)
{
    ::FUN_0060c270((intptr_t)(C60BE00Unchecked(&_First)), (intptr_t)(C60BE00Unchecked(&_Last)), (intptr_t)(_Dest), (intptr_t)(_Al));
}

// A one-byte class.  Under /Od an empty brace initialiser zero-initialises the
// object in place, which is the "xor eax,eax" + byte store the original shows.
struct FNV_Flag1
{
    unsigned char m_kPointB;
};

// Stand-ins for the two game callees.  The names are not canonical symbols, so
// the checker binds the call targets from the original's own bytes.
extern "C" unsigned char __cdecl FUN_0065e750_standin(void* a, void* b);

// Calls FUN_0065e750_standin with &p1 and &p3, then passes p1, p2, p3, p4, the returned byte and a zero flag byte to FUN_0060c290_standin.
// @fnv 0x0060be80
void CallWithFlagByte(void* p1, void* apArg2, void* apArg3, unsigned char p4)
{
    unsigned char ucResult;
    FNV_Flag1 RunFourthVirtual = {};
    ucResult = FUN_0065e750_standin(&p1, &apArg3);
    ::FUN_0060c290((char *)(p1), (char *)(apArg2), (char *)(apArg3));
}

struct S_0060c2e0_Flag
{
    unsigned char v;
};

struct S_0060c2e0_Ret
{
    unsigned char v;
    S_0060c2e0_Ret(int);
};

extern "C" S_0060c2e0_Ret __cdecl FUN_0065fd70(void* value);

// Calls ProcessFloatRange with a1, a2, a3 plus the byte returned by FUN_0065fd70(&a1) and a zero flag byte.
// @fnv 0x0060c2e0
void __cdecl CallWithFlagValues(void* a1, void* a2, void* a3)
{
    ::ProcessFloatRange((float *)(a1), (uintptr_t)(a2), (float *)(a3));
}

class B616A20Meter
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
    float m_fMaximum;
    float m_fCurrent;
    float FUN_00616a20();
};

// @fnv 0x00616a20
float B616A20Meter::FUN_00616a20()
{
    return m_fCurrent / m_fMaximum;
}

// variant A: direct member expression
struct FUN_00616a40_cls
{
    unsigned int m_i00;
    unsigned int m_i04;
    unsigned int m_i08;
    unsigned int m_i0C;
    unsigned int m_i10;
    unsigned int m_i14;
    unsigned int m_i18;
    unsigned int m_i1C;
    unsigned int m_i20;
    unsigned int m_i24;
    unsigned int m_i28;
    unsigned int m_i2C;
    unsigned int m_i30;
    unsigned int m_i34;
    unsigned int m_i38;
    unsigned int m_i3C;
    float m_f40;
    float m_f44;
    float m_f48;
    float FUN_00616a40();
};
// Calls FUN_00616a20 when a equals 1, otherwise calls FUN_00616a40.
// @fnv 0x00616a60
void S_00616a60::FUN_00616a60(int a)
{
    if (a == 1)
    {
        reinterpret_cast<::B616A20Meter *>(this)->FUN_00616a20();
        return;
        return;
    }
    reinterpret_cast<::FUN_00616a40_cls *>(this)->FUN_00616a40();
}

// @fnv 0x00616a40
float FUN_00616a40_cls::FUN_00616a40()
{
    return m_f48 / m_f40;
}

struct Comparison
{
    char FUN_00616a90(char mode);
};
// Reads two comparison results and maps their combination, depending on mode, to a result code (0-6).
// @fnv 0x00616a90
char Comparison::FUN_00616a90(char mode)
{
    char second = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(1)));
    char first = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(0)));
    if (second == 0 && first == 0)
        return 1;
    if (mode == 0)
    {
        if (second == 1 && first == 1)
            return 3;
        if (second == 3)
        {
            if (first == 2)
                return 2;
            if (first == 3)
                return 5;
        }
        if (second == 2)
        {
            if (first == 3)
                return 2;
            else if (first == 2)
                return 4;
        }
    }
    else if (mode == 1)
    {
        if (second == 1 && first == 0)
            return 4;
        if (second == 2)
        {
            if (first == 0)
                return 5;
            if (first == 1)
                return 2;
        }
        if (second == 3)
        {
            if (first == 0)
                return 6;
            else if (first == 1)
                return 3;
        }
    }
    else if (mode == 2)
    {
        if (first == 1 && second == 0)
            return 4;
        if (first == 2)
        {
            if (second == 0)
                return 5;
            if (second == 1)
                return 2;
        }
        if (first == 3)
        {
            if (second == 0)
                return 6;
            else if (second == 1)
                return 3;
        }
    }
    return 0;
}


struct FUN_00616c70_flag
{
    bool m_bValue;
};

struct FUN_00616c70_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void InitializeFields();
};

// Initializes the four fields at offsets 0, 4, 8 and 0x10 by calling FUN_00401080 on each with a default flag value.
// @fnv 0x00616c70
void FUN_00616c70_cls::InitializeFields()
{
    FUN_00616c70_flag a = {};
    ::FUN_00401080((int *)(void *)(this));
    FUN_00616c70_flag b = {};
    ::FUN_00401080((int *)(void *)((char*)&this->unk04));
    FUN_00616c70_flag c5 = {};
    ::FUN_00401080((int *)(void *)((char*)&this->unk08));
    FUN_00616c70_flag d = {};
    ::FUN_00401080((int *)(void *)((char*)&this->unk10));
}

int __cdecl FUN_00406d50(char* destination, unsigned int capacity, const char* source);

struct OutputStringDC
{
    void FUN_00438390(const char* text);
};

struct FUN_00616e20_shell
{
    bool FUN_00616e20(OutputStringDC* output, const char* first, const char* second, const char* third,
                      const char* fourth, const char* fifth);
};

// @fnv 0x00616e20
bool FUN_00616e20_shell::FUN_00616e20(OutputStringDC* output, const char* pcFirst, const char* pcSecond,
                                      const char* pcThird, const char* pcFourth, const char* pcFifth)
{
    bool succeeded2;
    char buffer[260];
    char* destination = buffer;
    destination[0] = 0;
    FUN_00406d50(destination, 260, pcFirst);
    FUN_00406d50(destination, 260, ::DAT_01013444);
    FUN_00406d50(destination, 260, pcSecond);
    FUN_00406d50(destination, 260, ::DAT_01013444);
    FUN_00406d50(destination, 260, pcThird);
    FUN_00406d50(destination, 260, ::DAT_01013444);
    FUN_00406d50(destination, 260, pcFourth);
    FUN_00406d50(destination, 260, DAT_01044c28);
    FUN_00406d50(destination, 260, pcFifth);
    succeeded2 = true;
    output->FUN_00438390(buffer);
    return succeeded2;
}

struct KeyObj
{
};

struct Entry
{
    KeyObj* key;
};

struct EntryListNode
{
    void SetItem(Entry* const& item);
    int GetSize();
};

struct SortOwner
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    bool SortList();
};

// Bubble-sorts the linked list by comparing each entry's key and swapping adjacent items when the next key is greater, then returns true.
// @fnv 0x0061ba90
bool SortOwner::SortList()
{
    V34();
    int count = ((::EntryListNode *)(reinterpret_cast<::TESRegion *>(this)->GetDiffuseColor()))->GetSize();
    for (int i = 0; i < count - 1; i++)
    {
        EntryListNode* nodeB = ((::EntryListNode *)(reinterpret_cast<::TESRegion *>(this)->GetDiffuseColor()));
        while (nodeB && *((::Entry **)(new ((void *)(nodeB)) ::Vec3())))
        {
            if (((::EntryListNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070())))
            {
                Entry* first4 = *((::Entry **)(new ((void *)(nodeB)) ::Vec3()));
                Entry* second3 = *((::Entry **)(new ((void *)(((::EntryListNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070())))) ::Vec3()));
                if (first4 && second3)
                {
                    int firstKey = first4->key ? reinterpret_cast<::FUN_005c3bd0_shell *>((first4->key))->FUN_005c3bd0() : -1;
                    int kSecondKey = second3->key ? reinterpret_cast<::FUN_005c3bd0_shell *>((second3->key))->FUN_005c3bd0() : -1;
                    if (kSecondKey > firstKey)
                    {
                        nodeB->SetItem(second3);
                        ((::EntryListNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()))->SetItem(first4);
                    }
                }
            }
            nodeB = ((::EntryListNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
        }
    }
    return true;
}

class ThisBase_b5727
{
  public:
    virtual ~ThisBase_b5727();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    ThisBase_b5727(int aValue);
};

class ThisMember_b5727
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ThisMember_b5727(int aValue);
    ~ThisMember_b5727();
};

class FUN_0061f460 : public ThisBase_b5727
{
  public:
    virtual ~FUN_0061f460();
    unsigned char m_14;
    ThisMember_b5727 m_18;

    FUN_0061f460();
};

// Initializes the base with 0, sets m_14 to 1 and constructs m_18 with 0x25.
// @fnv 0x0061f460
FUN_0061f460::FUN_0061f460() : ThisBase_b5727(0), m_18(0x25)
{
    m_14 = 1;
}

class F4D0Base
{
  public:
    F4D0Base();
    virtual ~F4D0Base();
};

struct F4D0List
{
    F4D0List();
    int unk00;
    int unk04;
};

class FUN_0061f4d0 : public F4D0Base
{
  public:
    FUN_0061f4d0(void* pkOwner);
    virtual ~FUN_0061f4d0();

    void* m_pkOwnerManager;
    bool m_bEnableState;
    F4D0List m_kList;
};

// @fnv 0x0061f4d0
FUN_0061f4d0::FUN_0061f4d0(void* pkOwner)
{
    m_pkOwnerManager = pkOwner;
    m_bEnableState = true;
}

struct RangeCheckedTag60C
{
};

struct ScalarPtrTag60C
{
};

typedef int* Iter60C;
typedef int Alloc60C;

ScalarPtrTag60C __cdecl PtrCat60C(Iter60C& kFirst, Iter60C& kDest);
Iter60C __cdecl CheckedBase60C(Iter60C& kIter);

// Copies elements from the checked range [kFirst, kLast) into kDest using UninitCopy60C with a PtrCat60C tag.
// @fnv 0x0060c320
void __cdecl UninitCopyChecked(Iter60C kFirst, Iter60C kLast, Iter60C kDest, Alloc60C kAlloc)
{
    ::FUN_0060c3c0(CheckedBase60C(kFirst), CheckedBase60C(kLast), kDest);
}

// Range helper: compute the range end, then forward the unwrapped start, count and output with an empty tag.

struct C380Tag
{
};

float* C380Unwrap(float** ppfFirst);

// @fnv 0x0060c380
void ProcessFloatRange(float* pfFirst, uintptr_t ItemUpdateArray, float* pfOut)
{
    float* pfLast = pfFirst + ItemUpdateArray;
    ::FUN_0060c410(C380Unwrap(&pfFirst), ItemUpdateArray, pfOut);
}

// Find the list entry that resolves to the given form and return its key (0 when none).

class F1A0Form
{
  public:
};

class F1A0Entry
{
  public:
};

class F1A0Node
{
  public:
    bool IsEmpty();
};

class F1A0Owner
{
  public:
    unsigned char GetKeyForForm(F1A0Form* pkForm);
};

// Walks the owner's list and returns the key of the entry whose form matches pkForm, or 0 if none matches.
// @fnv 0x0060f1a0
unsigned char F1A0Owner::GetKeyForForm(F1A0Form* pkForm)
{
    F1A0Node* pkNode = ((::F1A0Node *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (pkNode && !pkNode->IsEmpty())
    {
        F1A0Entry* pkEntry = *((::F1A0Entry **)(new ((void *)(pkNode)) ::Vec3()));
        if (pkForm == ((::F1A0Form *)(reinterpret_cast<::fnv_0060f2c0::FUN_0060f2c0_shell *>((pkEntry))->FindItemByDoneFlag(((bool)(::FUN_005dc980((const char *)(pkForm))))))))
            return ((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>((pkEntry))->FUN_009373f0()));
        pkNode = ((::F1A0Node *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
    }
    return 0;
}

class B616890Setting
{
  public:
    const char* String();
};

extern B616890Setting g_k616890A0;
extern B616890Setting g_k616890A1;
extern B616890Setting g_k616890A2;
extern B616890Setting g_k616890A3;
extern B616890Setting g_k616890B0;
extern B616890Setting g_k616890B1;
extern B616890Setting g_k616890B2;
extern B616890Setting g_k616890B3;
extern B616890Setting g_k616890C0;
extern B616890Setting g_k616890C1;
extern B616890Setting g_k616890C2;
extern B616890Setting g_k616890C3;
extern B616890Setting g_k616890D0;
extern B616890Setting g_k616890D1;
extern B616890Setting g_k616890D2;
extern B616890Setting g_k616890D3;

class B616890Menu
{
  public:
    const char* GetSelectedSettingString();
};

// Reads the selected row and column via GetIndex, then returns the String() of the matching entry in the 4x4 settings table.
// @fnv 0x00616890
const char* B616890Menu::GetSelectedSettingString()
{
    B616890Setting* aapkSettings3[4][4] = {{&g_k616890A0, &g_k616890A1, &g_k616890A2, &g_k616890A3},
                                           {&g_k616890B0, &g_k616890B1, &g_k616890B2, &g_k616890B3},
                                           {&g_k616890C0, &g_k616890C1, &g_k616890C2, &g_k616890C3},
                                           {&g_k616890D0, &g_k616890D1, &g_k616890D2, &g_k616890D3}};
    char cColumn = 0;
    char cRow3 = 0;
    cColumn = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(true)));
    cRow3 = ((char)(reinterpret_cast<::ReputationTracker *>(this)->GetReputationRank(false)));
    return aapkSettings3[cRow3][cColumn]->String();
}

struct CleanupItem
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual ~CleanupItem();
};
struct CleanupArray
{
};
struct CleanupTopic
{
    ~CleanupTopic();
};
struct CleanupList
{
    void FUN_0063f7b0();
};
struct CleanupBase
{
    virtual ~CleanupBase();
    unsigned int field04, field08, field0c, field10, field14;
};
struct CleanupSecondary
{
    virtual ~CleanupSecondary();
    unsigned int field04, field08, field0c, field10;
};
struct CleanupMember8
{
    unsigned int field00, field04;
    ~CleanupMember8();
};
struct CleanupMember12
{
    unsigned int field00, field04, field08;
    ~CleanupMember12();
};
struct FUN_006186d0 : CleanupBase, CleanupSecondary
{
    CleanupMember8 field2c;
    CleanupMember12 field34;
    CleanupMember12 field40;
    virtual ~FUN_006186d0();
};
struct VFString
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;

    VFString();
    ~VFString();
    operator const char*() const;
};

struct VFVoiceType
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual const char* GetEditorID();
};

struct VFBaseData
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual VFVoiceType* GetVoiceType();
};

struct VFForm
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
    VFBaseData kBaseData;
    int GetFormType();
};

struct VFFile
{
};

struct VFTopicInfo
{
};

struct VFVoiceOwner
{
    VFVoiceType* GetVoiceType(int aiUnk);
};

struct VFSetting
{
    const char* GetString();
};


extern VFSetting g_kVoiceExtension;

struct VFDialogue
{
    bool BuildVoiceFilePath(VFForm* apSpeaker, void* apTopic, void* apQuest, VFTopicInfo* apInfo, char* apBuffer);
};

struct CopyMap
{
};
struct FUN_0061f870_shell
{
    char _0[0x18];
    CopyMap unk18;
    void SetCopyMapEntry(unsigned int a);
};
// @fnv 0x0061f870
void FUN_0061f870_shell::SetCopyMapEntry(unsigned int uiKey)
{
    reinterpret_cast<::FUN_00844700_Class *>((&unk18))->FUN_00844700(uiKey, 5);
}

struct AHPtrMapBase
{
    virtual ~AHPtrMapBase();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
struct FUN_0061fae0 : public AHPtrMapBase
{
    virtual ~FUN_0061fae0();
    void RemoveAll();
};
// Calls FUN_0061fae0, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0061fa40
void* FUN_0061fa40_class::FUN_0061fa40(unsigned int flags)
{
    reinterpret_cast<::FUN_0061fae0 *>(this)->FUN_0061fae0::~FUN_0061fae0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x0061fae0
FUN_0061fae0::~FUN_0061fae0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

class StringHashTable
{
  public:
    int unk00;
    unsigned int m_uiBuckets;
    unsigned int HashKey(const char* pcKey);
};

// Computes a hash of pcKey by folding lowercased characters through FUN_00659210 and returns the result modulo m_uiBuckets.
// @fnv 0x00600b20
unsigned int StringHashTable::HashKey(const char* pcKey)
{
    unsigned int uiHash = 0;
    if (1)
    {
    }
    if (1)
    {
    }
    while (*pcKey)
        uiHash = ((unsigned int)(reinterpret_cast<::FUN_00659210_Class *>(this)->FUN_00659210((unsigned char)tolower(*pcKey++), uiHash)));
    return uiHash % m_uiBuckets;
}

struct FUN_00600d40 : FUN_00600b00_shell
{
    virtual ~FUN_00600d40();
};
// @fnv 0x00600d40
FUN_00600d40::~FUN_00600d40()
{}

struct FUN_00600d90_node
{
    FUN_00600d90_node* next;
    void* value;
};


struct FUN_00600e50
{
    virtual ~FUN_00600e50();
    unsigned int bucketCount;
    FUN_00600d90_node** buckets;
    unsigned int reserved;
    unsigned char ownsValues;
};

struct FUN_00600d90 : FUN_00600e50
{
    virtual ~FUN_00600d90();
};
// @fnv 0x00600f40
void* FUN_00600d90_shell::FUN_00600f40(unsigned int flags)
{
    reinterpret_cast<::FUN_00600d90 *>(this)->FUN_00600d90::~FUN_00600d90();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// If ownsValues is set, walks every bucket's node list and calls FUN_00aa10f0 on each node's value.
// @fnv 0x00600d90
FUN_00600d90::~FUN_00600d90()
{
    if (ownsValues)
    {
        for (unsigned int i = 0; i < bucketCount; ++i)
        {
            FUN_00600d90_node* node = buckets[i];
            while (node != 0)
            {
                FUN_00600d90_node* current = node;
                node = node->next;
                FUN_00aa10f0(current->value);
            }
        }
    }
}

struct FUN_00600eb0_base
{
    virtual ~FUN_00600eb0_base();
};

struct FUN_00600e50_cls : public FUN_00600eb0_base
{
    virtual ~FUN_00600e50_cls();
};
// Calls FUN_00600e50, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00600f10
void* FUN_00600e50_class::FUN_00600f10(unsigned int flags)
{
    reinterpret_cast<::FUN_00600e50_cls *>(this)->FUN_00600e50_cls::~FUN_00600e50_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls FUN_00438af0.
// @fnv 0x00600e50
FUN_00600e50_cls::~FUN_00600e50_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct TopicInfoArray
{
    virtual ~TopicInfoArray();
};
struct FUN_006197f0 : TopicInfoArray
{
    virtual ~FUN_006197f0();
};
// Destructor of FUN_006197f0, which derives from TopicInfoArray; the body is empty.
// @fnv 0x006197f0
FUN_006197f0::~FUN_006197f0()
{}

struct Path618
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ~Path618();
};

struct Queue618
{
    int unk00;
    int unk04;
    ~Queue618();
};

struct FUN_006188c0
{
    int m_iId;
    Path618 m_kPath;
    Queue618 m_kQueue;
    ~FUN_006188c0();
};
// Calls FUN_006188c0, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x00618890
FUN_00618890_cls* FUN_00618890_cls::FUN_00618890(unsigned int flags)
{
    reinterpret_cast<::FUN_006188c0 *>(this)->FUN_006188c0::~FUN_006188c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor with an empty body; members m_kPath and m_kQueue are destroyed implicitly.
// @fnv 0x006188c0
FUN_006188c0::~FUN_006188c0()
{}

class TESFile;
class TESForm
{
  public:
    virtual ~TESForm();
public:
    void ClearData();
public:
    ::TESFile *GetFile(int);
};
// Walks the cleanup list, deletes each topic's items and the topic itself, then calls FUN_00483710.
// @fnv 0x006186d0
FUN_006186d0::~FUN_006186d0()
{
    CleanupList* list = ((::CleanupList *)(reinterpret_cast<::TESRegion *>(this)->GetDiffuseColor()));
    while (list && *((::CleanupTopic **)(new ((void *)(list)) ::Vec3())))
    {
        CleanupTopic* topic = *((::CleanupTopic **)(new ((void *)(list)) ::Vec3()));
        unsigned int count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::CleanupArray *)(reinterpret_cast<::BaseProcess *>((topic))->GetCurrentProcessData()))))->FUN_0084e3a0()));
        for (unsigned int i = 0; i < count; ++i)
        {
            CleanupItem* item = ((::CleanupItem *)(::GetTopicInfoByIndex((::QuestDialogueInfo *)(topic), i)));
            if (item)
            {
                CleanupItem* pNullItem = 0;
                reinterpret_cast<::NiFormArray *>((((::CleanupArray *)(reinterpret_cast<::BaseProcess *>((topic))->GetCurrentProcessData()))))->SetSize(i, (unsigned int *)&(pNullItem));
                reinterpret_cast<::FUN_0061f340_shell *>((item))->FUN_0061f340(0xffff);
                delete item;
            }
        }
        delete topic;
        topic = 0;
        list->FUN_0063f7b0();
    }
    reinterpret_cast<::TESForm *>(this)->ClearData();
}
// @fnv 0x00616fa0
bool VFDialogue::BuildVoiceFilePath(VFForm* apSpeaker, void* apTopic, void* apQuest, VFTopicInfo* apInfo,
                                    char* apBuffer)
{
    VFString kUnused;
    VFString kName2;
    reinterpret_cast<::TESResponse *>(this)->BuildResponseFileName((::TESQuest *)(apTopic), (::TESTopic *)(apQuest), (::TESTopicInfo *)(apInfo), (*(::BSStringT<char> *)(&kName2)));
    VFVoiceType* pVoice4 = 0;
    VFFile* pFile = ((::VFFile *)(reinterpret_cast<::TESForm *>((apInfo))->GetFile(0)));
    if (!pFile)
        return false;

    const char* pPlugin = 0;
    if (apInfo && ((::VFForm *)(reinterpret_cast<::Twin_00639b40 *>((apInfo))->GetEntryPoint())))
        pVoice4 = ((::VFForm *)(reinterpret_cast<::Twin_00639b40 *>((apInfo))->GetEntryPoint()))->kBaseData.GetVoiceType();
    if (!pVoice4)
    {
        if (apSpeaker->GetFormType() == 0x2a)
            pVoice4 = apSpeaker->kBaseData.GetVoiceType();
        else if (apSpeaker->GetFormType() == 0x2b)
            pVoice4 = apSpeaker->kBaseData.GetVoiceType();
        else if (apSpeaker->GetFormType() == 0x16)
            pVoice4 = ((::VFVoiceType *)(uintptr_t)(reinterpret_cast<::PlayerMover *>((apSpeaker))->GetActorStateFlags()));
        else
        {
            VFVoiceOwner* pOwner4 = ((::VFVoiceOwner *)(::FUN_00617270((::TESForm *)(apSpeaker))));
            if (!pOwner4)
                return false;
            pVoice4 = ((::VFVoiceType *)(uintptr_t)(reinterpret_cast<::FUN_00604780_shell *>((pOwner4))->FUN_00604780(0)));
        }
    }
    if (!pVoice4)
        return false;

    const char* pVoiceName2 = pVoice4->GetEditorID();
    if (!pVoiceName2)
        return false;

    const char* pPrefix5 = "Data\\Sound\\Voice";
    if (pFile)
    {
        pPlugin = ((const char *)(reinterpret_cast<::BGSCameraPath *>((pFile))->GetShotList()));
        if (!pPlugin)
            return false;
    }
    const char* pExtension_ = g_kVoiceExtension.GetString();
    bool bResult = reinterpret_cast<::FUN_00616e20_shell *>(this)->FUN_00616e20((::OutputStringDC *)(apBuffer), pPrefix5, pPlugin, pVoiceName2, kName2, pExtension_);
    if (bResult)
        return true;
    return true;
}

class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};

class TESRace;
class TESRaceForm : public BaseFormComponent
{
  public:
    TESRace* race;
};

// Casts the form to TESRaceForm and returns its race via FUN_00726070, or null if the cast fails.
// @fnv 0x00617270
TESRace* __cdecl FUN_00617270(TESForm* form)
{
    TESRaceForm* pRaceForm;
    pRaceForm = dynamic_cast<TESRaceForm*>(form);
    {
        TESRace* result;
        if (pRaceForm)
            result = ((::TESRace *)(reinterpret_cast<::Callees *>((pRaceForm))->FUN_00726070()));
        else
            result = 0;
        return result;
    }
}

#include "generated/data/staging/blk_00600000_od.inc"
