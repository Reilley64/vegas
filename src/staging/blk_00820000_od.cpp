
// src/staging/blk_00820000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <windows.h>
#include <objbase.h>
#include <new>
#include "fnv/decl/B83C270Conversation.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BasePinStub.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/C6760Ref.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0045cec0_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_005215a0_shell.h"
#include "fnv/decl/FUN_00522440_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_009fdc10.h"
#include "fnv/decl/FUN_00ad78e0_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89b0_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8ad0_s.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8be0_shell.h"
#include "fnv/decl/FUN_00ad8c20_h.h"
#include "fnv/decl/FUN_00ad8c70_Class.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FUN_00ad9030_shell.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/ParticleEmitter.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/Radio652.h"
#include "fnv/decl/RefC7.h"
#include "fnv/decl/S2f760.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_00522470.h"
#include "fnv/decl/S_0082f1f0_Lock.h"
#include "fnv/decl/S_8c4f10_Cls.h"
#include "fnv/decl/SoundPlaybackManager.h"
#include "fnv/decl/StandIn.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00454b10__TESObjectCELL.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_005de0f0__FUN_005de0f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00ad8100__FUN_00ad8100_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/fnv_00ad8e20__FUN_00ad8e20_h.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e3000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_0082d000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_00839000.h"
#include "fnv/symbols_00890000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_0107c000.h"
#include "fnv/symbols_0107d000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "../../include/layout_support.h"
#include "fnv/decl/FORenderedMenu.h"
#include "fnv/decl/FUN_004615d0_shell.h"
#include "fnv/decl/SoundWrapper.h"
#include "fnv/symbols_00831000.h"
#include "fnv/symbols_0083a000.h"
#include "../../include/layout_support_decl_blk_00820000_od.h"

struct FUN_00821620_Class
{
    void FUN_00821620(float value);
};

// @fnv 0x00821620
void FUN_00821620_Class::FUN_00821620(float value)
{
    *(float*)((char*)this + 0x130) = value;
}

struct FUN_00821680_Class
{
    float FUN_00821680() const;
};

// @fnv 0x00821680
float FUN_00821680_Class::FUN_00821680() const
{
    return *(const float*)((const char*)this + 0x140);
}

struct FUN_008216a0_class
{
    float GetValue() const;
};

// @fnv 0x008216a0
float FUN_008216a0_class::GetValue() const
{
    return *(const float*)((const char*)this + 0x148);
}

struct FUN_00824080_Class
{
    bool IsFlag200Set();
};

// @fnv 0x00824080
bool FUN_00824080_Class::IsFlag200Set()
{
    return (reinterpret_cast<const unsigned int*>(this)[6] & 0x200) != 0;
}

struct FUN_00827200_class
{
    void FUN_00cb26e0(int);
    FUN_00827200_class* FUN_00827200(int a);
};
struct FUN_0082d660_class
{
    char GetByteAtOffset44();
};

// @fnv 0x0082d660
char FUN_0082d660_class::GetByteAtOffset44()
{
    return *(char*)((char*)this + 0x44);
}

struct FUN_0082d6a0_Class
{
    unsigned short GetShortAt(int index);
};

// @fnv 0x0082d6a0
unsigned short FUN_0082d6a0_Class::GetShortAt(int index)
{
    return *(unsigned short*)((char*)this + 0x50 + index * 2);
}

struct FUN_0082d6c0_class
{
    unsigned short GetShortAtOffset5A();
};

// @fnv 0x0082d6c0
unsigned short FUN_0082d6c0_class::GetShortAtOffset5A()
{
    return *(unsigned short*)((char*)this + 0x5a);
}

// @fnv 0x0082d700
int FUN_0082d700(void* self)
{
    return *(unsigned short*)((char*)self + 0x4e) & 0xff;
}

struct FUN_0082d720_Class
{
    unsigned int FUN_0082d720();
};
// @fnv 0x0082d720
unsigned int FUN_0082d720_Class::FUN_0082d720()
{
    return ((const unsigned int*)this)[0x5c / 4] & 0xff;
}

extern int DAT_0107ca44;
void __cdecl InitArray(int);
struct FUN_0082ee80_class
{
    int* m_p;
    void InitArray(int);
    FUN_0082ee80_class* InitializeWithGlobal(int a);
};

struct FUN_0082f140_class
{
    void FUN_0082f140();
};

// @fnv 0x0082f140
void FUN_0082f140_class::FUN_0082f140()
{
    *reinterpret_cast<void**>(this) = &DAT_0107cb6c;
}


struct FUN_0082f190_class
{
    void FUN_0082f190();
};

// @fnv 0x0082f190
void FUN_0082f190_class::FUN_0082f190()
{
    ::fnv_0082f1b0::FUN_0082f1b0(reinterpret_cast<char*>(this) + 0x10c);
}

struct RecursiveLock
{
};

struct CBSAStream
{
    void FUN_0082f1d0();
};

// @fnv 0x0082f1d0
void CBSAStream::FUN_0082f1d0()
{
    reinterpret_cast<::S_0082f1f0_Lock *>((reinterpret_cast<RecursiveLock*>(reinterpret_cast<char*>(this) + 0x10c)))->FUN_0082f1f0();
}

namespace fnv_0082f240 {

struct FUN_0082f240_class
{
    void* vtbl;
    FUN_0082f240_class();
};

// @fnv 0x0082f240
FUN_0082f240_class::FUN_0082f240_class()
{
    vtbl = &(*reinterpret_cast<int *>(&::DAT_0107cb6c));
}
}  // namespace fnv_0082f240


struct FUN_0082f520Class
{
    void* p;
    void* FUN_0082f520(void* v);
};

// Stores v into p, calls FUN_0082f1b0 on p, and returns this.
// @fnv 0x0082f520
void* FUN_0082f520Class::FUN_0082f520(void* pValue)
{
    p = pValue;
    ::fnv_0082f1b0::FUN_0082f1b0(p);
    return this;
}

namespace fnv_0082f550 {
struct RecursiveLock
{
};

// @fnv 0x0082f550
void LeaveObject(void* p)
{
    reinterpret_cast<::S_0082f1f0_Lock *>((((RecursiveLock**)(int*)p)[0]))->FUN_0082f1f0();
}
}  // namespace fnv_0082f550

struct FUN_00831e00_class
{
    int IsFlagSet();
};

// @fnv 0x00831e00
int FUN_00831e00_class::IsFlagSet()
{
    return (*(int*)((char*)this + 8) & 1) != 0;
}


struct FUN_00831f40_Class
{
    void FUN_00831f40(int a, int b);
};

// @fnv 0x00831f40
void FUN_00831f40_Class::FUN_00831f40(int aiArg1, int aiArg2)
{
    reinterpret_cast<::BasePinStub *>(((int)this + 0x104))->ReceiveConnection((void *)(aiArg1), (void *)(aiArg2));
}

struct FUN_008321c0_Class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void FUN_008321c0();
};
struct BGSLoadFormBuffer
{
};
struct FUN_00836240
{
};
struct FUN_00836630
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};
// @fnv 0x00836630
void FUN_00836630::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(this));
    reinterpret_cast<::Radio652 *>((reinterpret_cast<FUN_00836240*>(reinterpret_cast<char*>(this) + 4)))->FUN_00836240((::Buffer652 *)(buffer));
}

extern int DAT_011a1888[];

// Returns the entry at index from DAT_011dd87c if non-zero, otherwise the entry at index from DAT_011a1888.
// @fnv 0x008374b0
int __cdecl FUN_008374b0(int index)
{
    if (DAT_011dd87c[index])
        return DAT_011dd87c[index];
    return DAT_011a1888[index];
}

namespace fnv_008374e0 {

// @fnv 0x008374e0
void __cdecl SetGlobalPointerAtOffset(int aiOffset, const char* apValue)
{
    *(int*)(&(*reinterpret_cast<int *>(&::DAT_011dd87c)) + aiOffset) = (int)apValue;
}
}  // namespace fnv_008374e0


// @fnv 0x00837500
void FUN_00837500()
{
    DAT_011dd85c = 0;
    ::fnv_00839ab0::InitFootstepImpacts();
}

extern "C" void* DAT_0107d9c4;

struct FUN_0083b5e0_class
{
    void* m_ptr;
    void InitBuffer(int);
    void* FUN_0083b5e0(int a);
};

// Calls InitBuffer with the argument, sets m_ptr to DAT_0107d9c4, and returns this.
// @fnv 0x0083b5e0
void* FUN_0083b5e0_class::FUN_0083b5e0(int a)
{
    InitBuffer(a);
    m_ptr = &DAT_0107d9c4;
    return this;
}

struct S7010
{
};
struct FUN_0083dea0_class
{
    unsigned int FUN_0083dea0();
};
// @fnv 0x0083dea0
unsigned int FUN_0083dea0_class::FUN_0083dea0()
{
    return 0 < ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((S7010*)((char*)this + 0x34))))->FUN_004048e0()));
}

namespace fnv_0083e0a0 {
struct S7010
{
};
struct FUN_0083e0a0_Class
{
    unsigned int GetLength();
};
// @fnv 0x0083e0a0
unsigned int FUN_0083e0a0_Class::GetLength()
{
    return ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((S7010*)((char*)this + 0x18))))->FUN_004048e0()));
}
}  // namespace fnv_0083e0a0

extern "C" void __cdecl _NiFreeAlias(void*);
extern void* DAT_0107ca64;

struct FUN_0082efb0
{
    void FUN_0082efb0_init();
};

// Sets the vtable pointer, clears the pointer map, and frees the pointer stored at offset 8.
// @fnv 0x0082efb0
void FUN_0082efb0::FUN_0082efb0_init()
{
    *(void**)((char*)this + 0) = (void*)&DAT_0107ca64;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)(this + 8));
}

namespace fnv_0083b710 {
extern "C" void __cdecl _NiFreeAlias(void*);

struct FUN_0083b710_cls : public NiTPointerMap<int, int>
{
    void FUN_0083b710();
};

// @fnv 0x0083b710
void FUN_0083b710_cls::FUN_0083b710()
{
    *reinterpret_cast<void**>(this) = &::fnv_0083b640::DAT_0107d9e4;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    _NiFreeAlias(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[2]));
}
}  // namespace fnv_0083b710

struct FUN_00438690
{
    ~FUN_00438690();
};
struct FUN_00822630
{
    ~FUN_00822630();
};
struct FUN_008224b0_Class
{
    FUN_00822630 a;
    int pad[3];
    FUN_00438690 b;
    ~FUN_008224b0_Class();
};
// @fnv 0x008224b0
FUN_008224b0_Class::~FUN_008224b0_Class()
{}

struct GO
{
    ~GO();
    GO* FUN_008228f0(unsigned int flags);
};
// Runs the destructor and, if flags has bit 0 set, frees the object; returns the pointer.
// @fnv 0x008228f0
GO* GO::FUN_008228f0(unsigned int flags)
{
    reinterpret_cast<::FUN_0045cec0_Class *>(this)->FUN_0045cec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0082eee0_class
{
    void* InitArray(int size);
};
// Calls InitArray with the argument, stores the address of DAT_0107ca44 in m_p, and returns this.
// @fnv 0x0082ee80
FUN_0082ee80_class* FUN_0082ee80_class::InitializeWithGlobal(int a)
{
    reinterpret_cast<::FUN_0082eee0_class *>(this)->InitArray(a);
    m_p = &DAT_0107ca44;
    return this;
}
// @fnv 0x0082eee0
void* FUN_0082eee0_class::InitArray(int aiCount)
{
    *(void***)this = &DAT_0107ca64;
    ((int*)this)[1] = aiCount;
    ((int*)this)[3] = 0;
    unsigned int len = ((int*)this)[1] << 2;
    ((int*)this)[2] = (int)::FUN_00aa1070(len);
    ::FUN_00403d30(*(void**)((int*)this + 2), 0, ((int*)this)[1] << 2);
    return this;
}

struct FUN_00831f80_class
{
    void* FUN_00831f80(unsigned int flags);
};
extern int DAT_0107cd54;
extern int DAT_0107cd6c;
extern int DAT_0107cdac;
struct FUN_00831fb0_class
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    void FUN_00831fb0();
};
// Calls FUN_00831fb0, then frees this with Deallocate if flags has bit 0 set, and returns this.
// @fnv 0x00831f80
void* FUN_00831f80_class::FUN_00831f80(unsigned int flags)
{
    reinterpret_cast<::FUN_00831fb0_class *>(this)->FUN_00831fb0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Sets the object's vtbl and two fields to the given globals, then calls FUN_009fdc10 on this.
// @fnv 0x00831fb0
void FUN_00831fb0_class::FUN_00831fb0()
{
    vtbl = &DAT_0107cdac;
    c = (int)&DAT_0107cd6c;
    d = (int)&DAT_0107cd54;
    reinterpret_cast<class ::FUN_009fdc10 *>((this))->FUN_009fdc10::~FUN_009fdc10();
}

struct BGSSaveFormBuffer
{
};
struct FUN_00836600_class
{
    void FUN_00836600(BGSLoadFormBuffer* buffer);
};
struct FUN_00837280_Class
{
    char FUN_00837280();
};
// @fnv 0x00837280
char FUN_00837280_Class::FUN_00837280()
{
    return 3;
}

namespace fnv_0083b640 {
struct FUN_0083b640_class
{
    void* m_vt;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_0083b640_class* InitBuffer(int a);
};
// Sets the vtable, stores a count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x0083b640
FUN_0083b640_class* FUN_0083b640_class::InitBuffer(int aiCount)
{
    m_vt = &DAT_0107d9e4;
    m_uiItemCount = aiCount;
    m_auiShapeKeys = 0;
    unsigned int size = m_uiItemCount * 4;
    m_data = ::FUN_00aa1070(size);
    ::FUN_00403d30(m_data, 0, m_uiItemCount * 4);
    return this;
}
}  // namespace fnv_0083b640

struct FUN_0083b740_Class
{
    void* FUN_0083b740(unsigned int flags);
};
// Calls FUN_0083b710, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0083b740
void* FUN_0083b740_Class::FUN_0083b740(unsigned int flags)
{
    reinterpret_cast<::fnv_0083b710::FUN_0083b710_cls *>(this)->FUN_0083b710();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct SoundPlaybackHandle
{
    int x;
    int y;
    int z;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
public:
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
public:
    bool IsValid() const;
public:
    bool Release();
};
struct FUN_0083b770
{
    SoundPlaybackHandle a;
    SoundPlaybackHandle b;
    FUN_0083b770();
};
// @fnv 0x0083b770
FUN_0083b770::FUN_0083b770()
{}

struct Date
{
    ~Date();
};
struct FUN_0083b7d0
{
    Date a;
    int b;
    int c;
    Date d;
    ~FUN_0083b7d0();
};
// Destructor for a structure holding two Date members and two ints; it performs no work.
// @fnv 0x0083b7d0
FUN_0083b7d0::~FUN_0083b7d0()
{}

struct FUN_0083c750_class
{
    void FUN_0083c750();
    void* FUN_0083c720(unsigned int flags);
};
struct TESForm
{
    virtual ~TESForm();
    public:
    ::ENUM_FORM_ID GetFormType() const;
};
struct TESObjectREFR : TESForm
{
    virtual ~TESObjectREFR();
};
struct FUN_0083d0d0_Class
{
    void RefreshObjectRef(int a);
};
// Re-casts the TESForm pointer at offset 0x18 to TESObjectREFR via ref_004839c0, storing the result or null if the pointer was null.
// @fnv 0x0083d0d0
void FUN_0083d0d0_Class::RefreshObjectRef(int a)
{
    *(TESObjectREFR**)((char*)this + 0x18) =
        *(TESObjectREFR**)((char*)this + 0x18)
            ? (TESObjectREFR*)dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(*(TESForm**)((char*)this + 0x18))))
            : 0;
}

struct WeatherEntry
{
    int a;
    int b;
    int c;
    WeatherEntry();
};
struct G2
{
    void AddHead(WeatherEntry**);
};
struct FUN_00824290_class
{
    void AddWeatherEntry(int a, int b, int c);
};
// Allocates a WeatherEntry storing the three arguments and adds it to the head of the list at this+8.
// @fnv 0x00824290
void FUN_00824290_class::AddWeatherEntry(int aiFirst, int aiSecond, int aiThird)
{
    WeatherEntry* pEntry = new WeatherEntry;
    pEntry->a = aiFirst;
    pEntry->b = aiSecond;
    pEntry->c = aiThird;
    ((G2*)((char*)this + 8))->AddHead(&pEntry);
}

struct SoundDataDummy
{
    char pad[28];
    int a;
    int b;
};
struct TESSound
{
public:
    unsigned char GetField45();
};
// If self is non-null and its sound data has a non-zero a or b, writes a and b to outA and outB and returns true; otherwise returns false.
// @fnv 0x0082d740
bool FUN_0082d740(TESSound* self, int* outA, int* outB)
{
    if (!self)
        return false;
    TESSound* p = self;
    if ((*(::SoundDataDummy *)(reinterpret_cast<::Holder *>((p))->CopyBig({}))).a || (*(::SoundDataDummy *)(reinterpret_cast<::Holder *>((p))->CopyBig({}))).b)
    {
        *outA = (*(::SoundDataDummy *)(reinterpret_cast<::Holder *>((p))->CopyBig({}))).a;
        *outB = (*(::SoundDataDummy *)(reinterpret_cast<::Holder *>((p))->CopyBig({}))).b;
        return true;
    }
    return false;
}

struct BSAudio
{
    unsigned int GetSynchTime();
};
struct EffectSetting
{
};
struct TESObject
{
};
struct SndX
{
    int a, b, c;
    void Stop();
};
struct SndItem
{
    TESObject* obj;
    SndX first;
    SndX second;
    bool active;
};
int FNV_GetFormType(TESForm*);
struct ContNode
{
};
bool FUN_008256d0(ContNode*);
struct Q
{
    ~Q();
};
struct S_00836470
{
    Q* m_p;
    int m_iWordAt04;
    unsigned int m_uiCommandId;
    int m_uiItemCount;
    int m_10;
    int m_14;
    ContNode m_kNode;
    void UpdateSoundItems(int);
};

struct TESTopic : TESForm
{
    virtual ~TESTopic();
};
struct TESTopicInfo : TESForm
{
    virtual ~TESTopicInfo();
};
struct TESQuest : TESForm
{
    virtual ~TESQuest();
};
struct BGSLoadGameBuffer
{
};
struct FUN_0083d1e0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    FUN_0083d1e0();
};
struct DialogueResponseList
{
    FUN_0083d1e0* item;
    DialogueResponseList* next;
    void AddTail(FUN_0083d1e0* const& data);
};
struct DialogueItem_shell
{
    DialogueResponseList responses;
    unsigned int unk08;
    TESTopicInfo* topicInfo;
    TESTopic* topic;
    TESQuest* quest;
    unsigned int speaker;
    FUN_0083d1e0* GetResponseByIndex(short id);
    void LoadDialogueItem(BGSLoadFormBuffer* buffer);
};
struct ListX
{
    ~ListX();
};
struct FUN_00836030_class
{
    Q* a;
    Q* b;
    int pad[4];
    ListX c;
    ~FUN_00836030_class();
};
// @fnv 0x008321c0
void FUN_008321c0_Class::FUN_008321c0()
{
    reinterpret_cast<::FUN_00836030_class *>((((FUN_008321c0_Class*)((char*)this + 4))))->FUN_00836030_class::~FUN_00836030_class();
}
// @fnv 0x00836030
FUN_00836030_class::~FUN_00836030_class()
{
    if (b != a)
    {
        delete b;
        b = 0;
    }
    b = 0;
    if (a)
    {
        delete a;
        a = 0;
    }
    a = 0;
}

struct SL
{
    SL();
    int alignment;
};

struct FUN_00822a40_Class
{
    int* vtbl;
    unsigned char flag4;
    unsigned char flag5;
    SL sl;

    FUN_00822a40_Class();
};

extern int DAT_0107bc28;

// Initializes the object's vtable pointer to DAT_0107bc28 and clears flag4 and flag5.
// @fnv 0x00822a40
FUN_00822a40_Class::FUN_00822a40_Class() : vtbl(&DAT_0107bc28)
{
    flag4 = 0;
    flag5 = 0;
}

struct FUN_0080d930
{
    ~FUN_0080d930();
};
struct FUN_00825740 : FUN_0080d930
{
    ~FUN_00825740();
};
// @fnv 0x00825740
FUN_00825740::~FUN_00825740()
{}

struct BE
{
    void* vtable;
    void* field_04;
    void* field_08;

    BE(unsigned char value);
    ~BE();
};

struct BCaster_S
{
    void* vtable;
    void* field_04;
    void* field_08;

    BCaster_S();
    ~BCaster_S();
};

extern int DAT_0107be2c;
extern int DAT_0107be80;
extern int _data_011c16bc;

struct FUN_00825a10 : BE
{
    BCaster_S m_caster;
    int m_18;
    int m_1c;
    int m_20;

    FUN_00825a10();
};

// Initializes the object: sets both vtables, zeroes m_18, m_1c and m_20, and constructs the base with value 0x32.
// @fnv 0x00825a10
FUN_00825a10::FUN_00825a10() : BE((unsigned char)0x32), m_caster()
{
    this->vtable = reinterpret_cast<void*>(&DAT_0107be80);
    this->m_caster.vtable = reinterpret_cast<void*>(&DAT_0107be2c);
    this->m_20 = 0;
    this->m_18 = 0;
    this->m_1c = 0;
}

extern int DAT_0107bf1c;
struct MagicCaster;
struct MagicItem;
struct EffectItem;
struct ActiveEffect
{
    void* vtbl;
    ActiveEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};
struct FUN_008260b0 : ActiveEffect
{
    FUN_008260b0(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};
// Constructs the ActiveEffect base from caster, item and effect, then sets the vtable pointer to DAT_0107bf1c.
// @fnv 0x008260b0
FUN_008260b0::FUN_008260b0(MagicCaster* caster, MagicItem* item, EffectItem* effect)
    : ActiveEffect(caster, item, effect)
{
    this->vtbl = &DAT_0107bf1c;
}

namespace fnv_00826260 {
struct FUN_008260b0
{
    unsigned char m_auiShapeKeys[0x48];
    FUN_008260b0(void*, void*, void*);
};

// Allocates and constructs a FUN_008260b0 object from the three given arguments, returning the new instance.
// @fnv 0x00826260
FUN_008260b0* __cdecl CreateFUN008260b0(void* a, void* b, void* c)
{
    return new FUN_008260b0(a, b, c);
}
}  // namespace fnv_00826260

struct FUN_0082b370
{
    unsigned char _pad[0x4c];
    FUN_0082b370(int a, int b, int c);
};

// Allocates a FUN_0082b370 object by calling its constructor with the three arguments and returns the new pointer.
// @fnv 0x0082b6d0
FUN_0082b370* CreateFUN0082b370(int a, int b, int c)
{
    return new FUN_0082b370(a, b, c);
}

struct FUN_0082cf80
{
    unsigned char m_data[0x48];
    FUN_0082cf80(int, int, int);
};

// Allocates a FUN_0082cf80 object by calling its constructor with the three arguments and returns the pointer.
// @fnv 0x0082d090
void* __cdecl CreateFUN0082cf80(int a, int b, int c)
{
    return new FUN_0082cf80(a, b, c);
}

struct FUN_0082d6e0_Class
{
    unsigned char GetHighByteOfField4E();
};
// @fnv 0x0082d6e0
unsigned char FUN_0082d6e0_Class::GetHighByteOfField4E()
{
    return (unsigned char)((*(unsigned short*)((char*)this + 0x4e) & 0xff00) >> 8);
}

struct GlobalObject_0082ee80
{
    ~GlobalObject_0082ee80();
    GlobalObject_0082ee80* FUN_0082eeb0(unsigned int flags);
};
struct FUN_0082efb0_Ext : FUN_0082efb0
{
    FUN_0082efb0* FUN_0082efe0(unsigned int flags);
};
// Initializes the object, deallocates it when bit 0 of flags is set, and returns this.
// @fnv 0x0082efe0
FUN_0082efb0* FUN_0082efb0_Ext::FUN_0082efe0(unsigned int flags)
{
    FUN_0082efb0_init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0082f160_class : public FUN_0082f140_class
{
    void* FUN_0082f160(unsigned int flags);
};

// @fnv 0x0082f160
void* FUN_0082f160_class::FUN_0082f160(unsigned int flags)
{
    FUN_0082f140();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0082f260_class
{
    void* FUN_0082f210(unsigned int flags);
};
struct FUN_00831de0_Class
{
    char m_00[0x14];
    FUN_00831e00_class m_14;
    int ForwardToMember();
};

// @fnv 0x00831de0
int FUN_00831de0_Class::ForwardToMember()
{
    return m_14.IsFlagSet();
}

typedef void(* FUN_00831eb0_callback)(void*, int, int);

// @fnv 0x00831eb0
void FUN_00831eb0(void* object, int aiArg1, int aiArg2)
{
    BSSimpleList<ContNode>* next =
        ((::BSSimpleList< ::ContNode> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<ContNode>*>(reinterpret_cast<char*>(object) - 0x0C)))->FUN_00726070()));

    reinterpret_cast<FUN_00831eb0_callback>(*reinterpret_cast<void**>(*reinterpret_cast<void**>(next)))(next, aiArg1,
                                                                                                        aiArg2);
}

struct FUN_00831ee0_class
{
    virtual void FUN_00831ee0_virtual0();
    virtual void FUN_00831ee0_virtual1();
};

// Retrieves the ContNode at p-0xc via FUN_00726070 and calls its first virtual method.
// @fnv 0x00831ee0
void FUN_00831ee0(void* p)
{
    FUN_00831ee0_class* node = (FUN_00831ee0_class*)((::ContNode *)(reinterpret_cast<::Callees *>(((ContNode*)((char*)p - 0xc)))->FUN_00726070()));

    node->FUN_00831ee0_virtual1();
}

struct BSSimpleListEx
{
    virtual ~BSSimpleListEx();
};
struct FUN_00837480 : BSSimpleListEx
{
    void* DeleteThis(unsigned int flags);
};
// Destroys the BSSimpleListEx base and, when flags has bit 0 set, deallocates this object; returns this.
// @fnv 0x00837480
void* FUN_00837480::DeleteThis(unsigned int flags)
{
    ::FUN_008373f0((void *)(this));
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct GlobalObject_0083b5e0
{
    ~GlobalObject_0083b5e0();
    void* FUN_0083b610(unsigned int flags);
};

struct BSStr
{
};

struct BGSLoadGameBufferHelper
{
};

struct TESIdleForm : TESForm
{
    virtual ~TESIdleForm()
    {}
};


struct FUN_0083d740_Class
{
    void FUN_0083d740(BGSLoadGameBuffer* buffer);
};
// Reads a response count and its responses, an optional current response id, topic info, topic, quest and speaker from the load buffer.
// @fnv 0x0083cf40
void DialogueItem_shell::LoadDialogueItem(BGSLoadFormBuffer* buffer)
{
    short currentID;
    {
        unsigned int count = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((((BGSLoadGameBuffer*)buffer)))->FUN_00864a60();
        for (unsigned int i = 0; i < count; ++i)
        {
            FUN_0083d1e0* response = new FUN_0083d1e0;
            reinterpret_cast<::FUN_0083d740_Class *>((response))->FUN_0083d740((::BGSLoadGameBuffer *)(buffer));
            reinterpret_cast<::Callees *>(&(responses))->FUN_00905820((void *)&(response));
        }
    }
    currentID = -1;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadGameBuffer*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&currentID), 2);
    if (currentID != -1)
        reinterpret_cast<::StandIn *>(this)->FUN_0083c8a0((::DialogueResponse *)(::FUN_0083d1e0 *)(GetResponseByIndex(currentID)));
    topicInfo = dynamic_cast<TESTopicInfo*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((((BGSLoadGameBuffer*)buffer)))->FUN_008648a0()));
    topic = dynamic_cast<TESTopic*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((((BGSLoadGameBuffer*)buffer)))->FUN_008648a0()));
    quest = dynamic_cast<TESQuest*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((((BGSLoadGameBuffer*)buffer)))->FUN_008648a0()));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&speaker));
}

// @fnv 0x0083d740
void FUN_0083d740_Class::FUN_0083d740(BGSLoadGameBuffer* buffer)
{
    char text[1000];

    reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((reinterpret_cast<BGSLoadGameBufferHelper*>(buffer)))->FUN_008649a0(text);
    reinterpret_cast<::TextString *>((reinterpret_cast<BSStr*>(this)))->FUN_004037f0(text, 0);

    reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((reinterpret_cast<BGSLoadGameBufferHelper*>(buffer)))->FUN_008649a0(text);
    reinterpret_cast<::TextString *>((reinterpret_cast<BSStr*>(reinterpret_cast<char*>(this) + 0x10)))->FUN_004037f0(text, 0);

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 8), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xc), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0x24), 1);

    *reinterpret_cast<TESIdleForm**>(reinterpret_cast<char*>(this) + 0x18) =
        dynamic_cast<TESIdleForm*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));

    *reinterpret_cast<TESIdleForm**>(reinterpret_cast<char*>(this) + 0x1c) =
        dynamic_cast<TESIdleForm*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));

    *reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x20) =
        dynamic_cast<TESSound*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
}

namespace fnv_0083da50 {
struct BSStr
{
    unsigned char m_data[9];

    BSStr();
    ~BSStr();
};

struct StrMem
{
    BSStr m_bsstr;
    unsigned char m_9;
    unsigned char m_kPointA;
    unsigned char m_kPointB;

    StrMem();
    ~StrMem();
};

struct SL
{
    int m_iWordAt00;
    int m_iWordAt04;

    SL();
    ~SL();
};

struct FUN_0083da50 : StrMem
{
    SL m_sl;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;

    FUN_0083da50();
};

extern char $SG3295[];

BSStr::BSStr()
{}

BSStr::~BSStr()
{}

StrMem::StrMem()
{}

StrMem::~StrMem()
{}

SL::SL()
{}

SL::~SL()
{}

// @fnv 0x0083da50
FUN_0083da50::FUN_0083da50() : StrMem(), m_sl()
{
    m_20 = 0;
    m_14 = 0;
    m_28 = 0;
    m_18 = 0;
    reinterpret_cast<::TextString *>(&(m_bsstr))->FUN_004037f0($SG3295, 0);
    m_9 = 0;
    m_kPointA = 0;
}
}  // namespace fnv_0083da50

struct Str6a70
{
    Str6a70& operator=(char const*);
};

struct BGSLoadGameBufferLoadStringHelper
{
};

struct BGSLoadFormBufferHelper
{
};

extern void* _DAT_01183028;

struct FUN_0083fbe0_Class
{
    void FUN_0083fbe0(BGSLoadGameBuffer* buffer);
};

// @fnv 0x0083fbe0
void FUN_0083fbe0_Class::FUN_0083fbe0(BGSLoadGameBuffer* buffer)
{
    char string[500];

    reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((reinterpret_cast<BGSLoadGameBufferLoadStringHelper*>(buffer)))->FUN_008649a0(string);
    reinterpret_cast<Str6a70*>(this)->operator=(string);

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0x08), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0x24), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0x25), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0x09), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0x0A), 1);

    *reinterpret_cast<TESQuest**>(reinterpret_cast<char*>(this) + 0x14) = dynamic_cast<TESQuest*>(
        ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)))->FUN_008648a0()));

    *reinterpret_cast<TESTopic**>(reinterpret_cast<char*>(this) + 0x28) = dynamic_cast<TESTopic*>(
        ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)))->FUN_008648a0()));

    *reinterpret_cast<TESTopic**>(reinterpret_cast<char*>(this) + 0x1C) = dynamic_cast<TESTopic*>(
        ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)))->FUN_008648a0()));

    *reinterpret_cast<TESTopicInfo**>(reinterpret_cast<char*>(this) + 0x18) = dynamic_cast<TESTopicInfo*>(
        ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((reinterpret_cast<BGSLoadFormBufferHelper*>(buffer)))->FUN_008648a0()));
}

// FUN_00822440 - 0x00822440, 99 bytes.
//
// The constructor of the game class that owns
//   +0x00  BSSimpleArray<void*, 0xEAA>   (vftable 0x0107b84c, ctor 0x00822600,
//                                          dtor 0x00822630)
//   +0x10  BSSimpleArray<int, 0xEAA>     (vftable 0x01016024, ctor 0x00438660,
//                                          dtor 0x00438690)
//   +0x20  int                           (zeroed by the constructor)
//
// The class itself is NOT polymorphic: the original's constructor never writes
// a vftable pointer of its own, the vtable at +0x00 comes from the
// BSSimpleArray<void*> MEMBER constructor at 0x00822600.  The matching
// destructor is 0x008224b0; it destroys the members in reverse order
// (0x00438690 at +0x10 first, then 0x00822630 at +0x00).
//
// The original's code:
//   push ebp / mov ebp,esp / push -1 / push __ehhandler$ / mov eax,fs:[0] /
//   push eax / push ecx / mov eax,[__security_cookie] / xor eax,ebp /
//   push eax / lea eax,[ebp-0xc] / mov fs:[0],eax
//   mov  [ebp-0x10],ecx                 ; the /Od home slot of `this`
//   mov  ecx,[ebp-0x10] / call 0x822600 ; BSSimpleArray<void*> ctor
//   mov  dword ptr [ebp-4],0           ; EH state variable
//   mov  ecx,[ebp-0x10] / add ecx,0x10 / call 0x438660 ; BSSimpleArray<int> ctor
//   mov  eax,[ebp-0x10] / mov dword ptr [eax+0x20],0
//   mov  dword ptr [ebp-4],-1          ; EH state variable
//   mov  eax,[ebp-0x10] / mov ecx,[ebp-0xc] / mov fs:[0],ecx /
//   pop ecx / mov esp,ebp / pop ebp / ret
//
// The class name has to carry the FUN_00822440 tag (the constructor's mangled
// name is the only symbol the checker can find), so the destructor is DECLARED
// but never defined: an undefined destructor is never emitted into the object
// file, which keeps exactly ONE defined function symbol carrying the tag.

// Stand-in for BSSimpleArray<void*, 0xEAA>.
struct FnvSimpleArrayPtr
{
    void** m_ppVirtualMethodTable;
    void* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    FnvSimpleArrayPtr();
    ~FnvSimpleArrayPtr();
};

// Stand-in for BSSimpleArray<int, 0xEAA>.
struct FnvSimpleArrayInt
{
    void** m_ppVirtualMethodTable;
    int* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    FnvSimpleArrayInt();
    ~FnvSimpleArrayInt();
};

struct FUN_00822440_Class
{
    FnvSimpleArrayPtr m_arrPtr;  // +0x00
    FnvSimpleArrayInt m_arrInt;  // +0x10
    int m_unk20;                 // +0x20
    FUN_00822440_Class();
    ~FUN_00822440_Class();
};

// Constructs the object, default-initializing m_arrPtr and m_arrInt and setting m_unk20 to 0.
// @fnv 0x00822440
FUN_00822440_Class::FUN_00822440_Class() : m_arrPtr(), m_arrInt(), m_unk20(0)
{}

struct PrimaryBase_b5774
{
    virtual ~PrimaryBase_b5774();
    unsigned int unk04;
    unsigned int unk08;
};

struct SecondaryBase_b5774
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ~SecondaryBase_b5774();
};

struct GlobalMgr_b5774
{
};


struct Holder_b5774
{
    void Release();
};

class FUN_00825b60 : public PrimaryBase_b5774, public SecondaryBase_b5774
{
  public:
    Holder_b5774* m_20;
    virtual ~FUN_00825b60();
};

struct S_00825ea0_A
{
    unsigned char unk04;
    int unk08;
    S_00825ea0_A(unsigned char c);
    virtual ~S_00825ea0_A();
};
struct S_00825ea0_B
{
    unsigned char unk04;
    unsigned char unk05;
    int unk08;
    int unk0c;
    S_00825ea0_B();
    virtual ~S_00825ea0_B();
};
struct S_00825ea0_P
{
    int unk00;
    int unk04;
    S_00825ea0_P();
};
struct FUN_00825ea0 : S_00825ea0_A, S_00825ea0_B
{
    int unk1c;
    S_00825ea0_P unk20;
    FUN_00825ea0();
    virtual ~FUN_00825ea0();
};
// Initializes the base subobject with 0x33 and sets unk1c to 0.
// @fnv 0x00825ea0
FUN_00825ea0::FUN_00825ea0() : S_00825ea0_A(0x33)
{
    unk1c = 0;
}

struct SoundDataEx
{
    unsigned int unk00;
    unsigned int flags;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
};

struct TESSoundEx : TESSound
{
};

struct DataHandler
{
    TESSoundEx* LookupSound(unsigned int formID);
};


// @fnv 0x0082d150
bool GetSoundPathAndFlags(unsigned int formID, char* path, unsigned int* flags, TESSoundEx** outSound)
{
    TESSoundEx* sound = (*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))->LookupSound(formID);
    if (sound && ::FUN_00511840((char *)(sound)) && path)
    {
        ::TaskQueueInterface::CopyStringToBuffer(path, 0x104, ::FUN_00511840((char *)(sound)));
    }
    else
    {
        return false;
    }
    if ((*(::SoundDataEx *)(reinterpret_cast<::Holder *>((sound))->CopyBig({}))).flags & 0x40)
    {
        *flags |= 1;
        *flags &= ~2;
    }
    else if (!(*flags & 1) && !(*flags & 2))
    {
        *flags |= 2;
        *flags &= ~1;
    }
    if ((*(::SoundDataEx *)(reinterpret_cast<::Holder *>((sound))->CopyBig({}))).flags & 1)
    {
        *flags |= 0x40;
    }
    if ((*(::SoundDataEx *)(reinterpret_cast<::Holder *>((sound))->CopyBig({}))).flags & 0x800)
    {
        *flags |= 0x8000000;
    }
    *flags |= ((unsigned int)(::GetFlagMask((*(::SoundDataEx *)(reinterpret_cast<::Holder *>((sound))->CopyBig({}))).flags)));
    *outSound = sound;
    return true;
}

struct Base_82efb0
{
    virtual ~Base_82efb0();
};

struct FUN_0082ef50 : public Base_82efb0
{
    void RemoveAll();
    virtual ~FUN_0082ef50();
};
// Runs the destructor, frees the object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0082eeb0
GlobalObject_0082ee80* GlobalObject_0082ee80::FUN_0082eeb0(unsigned int flags)
{
    reinterpret_cast<::FUN_0082ef50 *>((this))->FUN_0082ef50::~FUN_0082ef50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0082ef50
FUN_0082ef50::~FUN_0082ef50()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

extern "C" void* __cdecl FUN_00afdf20(const char*, int, int, int);
struct FNVHandle
{
    virtual ~FNVHandle();
};
struct FUN_0082f240
{
    FUN_0082f240();
    virtual ~FUN_0082f240();
};
struct FUN_0044fae0
{
    FUN_0044fae0();
    ~FUN_0044fae0();
    unsigned int state00;
    unsigned int state04;
    unsigned int state08;
    unsigned int state0c;
    unsigned int state10;
    unsigned int state14;
    unsigned int state18;
    unsigned int state1c;
    unsigned int state20;
};
struct FUN_0082f010 : FUN_0082f240
{
    char path[0x104];
    FNVHandle* handle;
    FUN_0044fae0 lock;
    unsigned __int64 counter;
    FUN_0082f010(const char* pathName);
    virtual ~FUN_0082f010();
};

// @fnv 0x0082f010
FUN_0082f010::FUN_0082f010(const char* pathName)
{
    counter = 0;
    ::TaskQueueInterface::CopyStringToBuffer(path, 0x104, pathName);
    handle = (FNVHandle*)FUN_00afdf20(path, 0, 0x4000, 8);
    if (!handle || !::FUN_008905f0((bool *)(handle)))
    {
        if (handle)
        {
            delete handle;
        }
        handle = 0;
    }
}

struct ProbeTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14(int a, int b);
};
class FUN_0082f310_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    ProbeTarget* m_108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    __int64 m_128;
    __int64 m_130;

  public:
    int FUN_0082f310(__int64 value);
};
// Validates value against m_128 and the m_108 probe, then stores it in m_130 and calls m_108->v14(value, DAT_010a2480); returns 1 on failure, 0 on success.
// @fnv 0x0082f310
int FUN_0082f310_cls::FUN_0082f310(__int64 value)
{
    if (value < 0 || value > this->m_128 || this->m_108 == 0 || ::FUN_008905f0((bool *)(this->m_108)) == 0)
    {
        return 1;
    }
    else
    {
        this->m_130 = value;
        this->m_108->v14((int)value, DAT_010a2480);
        return 0;
    }
}

struct StreamLock
{
    void* m_cs;
    StreamLock(void* cs);
    ~StreamLock();
};

struct StreamFile
{
};

struct ArchiveStream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    StreamFile* file;
    int lock;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    __int64 size;
    __int64 pos;
    int FUN_0082f3c0(void* buffer, unsigned int count, int unused, unsigned int* bytesRead);
};

// @fnv 0x0082f3c0
int ArchiveStream::FUN_0082f3c0(void* buffer, unsigned int count, int unused, unsigned int* bytesRead)
{
    StreamLock guard(&lock);
    if (!file || !::FUN_008905f0((bool *)(file)))
        return 1;
    unsigned int uiToAdvance;
    if (pos + count > size)
        uiToAdvance = (unsigned int)(size - pos);
    else
        uiToAdvance = count;
    *bytesRead = reinterpret_cast<::FUN_00462d80_shell *>((file))->ReadBytes(buffer, count);
    pos += uiToAdvance;
    return 0;
}

// FUN_0082f6c0 @ 0x0082f6c0 (size 150)
// Base-object destructor of a thread-like class: clears the "running" flag bit,
// signals the object at +0x34, waits for the worker thread to leave, closes its
// handle, then runs the base class destructor.



struct FUN_00aa63c0
{
    virtual ~FUN_00aa63c0();
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
};

struct FUN_0082f6c0 : FUN_00aa63c0
{
    void* unk30;
    int unk34;
    int unk38;
    unsigned int unk3C;

    virtual ~FUN_0082f6c0();
};

// Clears the low bit of unk3C, calls CopyAndSleep on unk34, waits while bit 1 of unk3C is set, then closes unk30.
// @fnv 0x0082f6c0
FUN_0082f6c0::~FUN_0082f6c0()
{
    unk3C &= 0xFFFFFFFE;
    reinterpret_cast<::S2f760 *>(this)->CopyAndSleep(&unk34);
    while (unk3C & 2)
        ::FUN_0040fca0(10);
    CloseHandle(unk30);
}



struct FUN_0082f9c0_obj
{
    virtual int unk00(int a);
};

// @fnv 0x0082f9c0
void __cdecl FUN_0082f9c0()
{
    unsigned int a = DAT_011dd1f4;
    unsigned int b_2 = a;
    unsigned int c7 = b_2;
    unsigned int r_2;
    unsigned int s;
    if (c7 != 0)
    {
        if (*(unsigned int*)(c7 - 4) != 0)
        {
            r_2 = (unsigned int)((FUN_0082f9c0_obj*)b_2)->unk00(3);
        }
        else
        {
            ::FUN_00401030((void *)(c7 - 4));
            r_2 = 0;
        }
        s = r_2;
    }
    else
    {
        s = 0;
    }
    DAT_011dd1f4 = 0;
}

// FUN_00831f70: stdcall stub taking one stack argument and returning 0.
// @fnv 0x00831f70
int FUN_00831f70(int unused)
{
    return 0;
}

// PlayWeaponSound v2 (worker11): pack types reused; extra callees via shell classes
struct NiPoint3
{
    float x, y, z;
    NiPoint3();
public:
    static const ::NiPoint3 ZERO;
};
struct Vec3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& rhs) const;
public:
    Vec3();
};
// Calls _ref_006815c0, then FUN_00cb26e0 with a, and returns this.
// @fnv 0x00827200
FUN_00827200_class* FUN_00827200_class::FUN_00827200(int a)
{
    new ((void *)this) ::Vec3();
    FUN_00cb26e0(a);
    return this;
}
// @fnv 0x00836470
void S_00836470::UpdateSoundItems(int)
{
    if (::FUN_00453a70()->GetSynchTime() < m_uiCommandId || m_uiItemCount <= 0)
    {
        m_uiCommandId = 0;
        m_uiItemCount = 1;
        delete m_p;
        m_p = 0;
    }
    else
    {
        m_uiCommandId = ::FUN_00453a70()->GetSynchTime() - m_uiCommandId;
    }
    ContNode* node = &m_kNode;
    while (node && !FUN_008256d0(node) && *((::SndItem **)(new ((void *)(node)) ::Vec3())))
    {
        if (!(*((::SndItem **)(new ((void *)(node)) ::Vec3())))->obj || !((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*((::SndItem **)(new ((void *)(node)) ::Vec3())))->obj))->FUN_007af430())) ||
            (FNV_GetFormType((TESForm*)((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*((::SndItem **)(new ((void *)(node)) ::Vec3())))->obj))->FUN_007af430()))) == 0x15 &&
             !((void *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((EffectSetting*)((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*((::SndItem **)(new ((void *)(node)) ::Vec3())))->obj))->FUN_007af430())))))))))
        {
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*((::SndItem **)(new ((void *)(node)) ::Vec3())))->first))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&((*((::SndItem **)(new ((void *)(node)) ::Vec3())))->first))->Release();
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*((::SndItem **)(new ((void *)(node)) ::Vec3())))->second))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&((*((::SndItem **)(new ((void *)(node)) ::Vec3())))->second))->Release();
            (*((::SndItem **)(new ((void *)(node)) ::Vec3())))->active = false;
        }
        node = ((::ContNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
}
struct AudioPlaybackHandle;
struct SndXShell
{
};
struct Entry
{
    SndX ch0;
    SndX ch1;
    void* f18;
    unsigned int f1c;
    float f20;
};
struct GlobalObject_0041a250
{
    int f00, f04, f08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};
struct AudioPlaybackHandle
{
    int f00, f04, f08;
    ~AudioPlaybackHandle();
};
struct BSAudioShell
{
    AudioPlaybackHandle FUN_00ad7480(const char* name);
};
struct TESSoundShell
{
};
struct Weap
{
};
struct VObj1d0
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* VCall1d0();
};
struct VObj148
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void* VCall148();
};
struct ProcResult
{
};
struct Cell
{
};
struct Player
{
};
struct ListObj
{
};
struct SettingObj
{
};
bool __cdecl FUN_00839da0();
extern Entry DAT_011dd9e8[20];
// @fnv 0x0083ac30
void __cdecl PlayWeaponSound(Weap* apWeapon, VObj1d0* apSource, ListObj* apListObj, bool a3)
{
    if (!FUN_00839da0())
        return;
    GlobalObject_0041a250 bobj24;
    GlobalObject_0041a250 iobj48;
    Vec3 jvec;
    jvec = (*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO));
    bool ib15 = false;
    int iflags = 0;
    bool kb52 = !::FUN_00524d10((bool *)((*reinterpret_cast<::Player * *>(&::_g_thePlayer))));
    bool b83d = false;
    NiPoint3 cpt;
    float ef60 = ::DAT_01016970;
    Entry* aentry140 = 0;
    Entry* mentry3c = 0;
    Entry* tentry64 = 0;
    Entry* sentry58 = 0;
    bool ab51 = true;
    float cf38 = 1.0f;
    float yf50 = 1.0f;
    float if68 = 1.0f;
    float cf4c = 1.0f;
    unsigned char gb31 = 0;
    unsigned char qb75 = 0;
    unsigned char cg59 = 0;
    unsigned char sb0d = 0;
    if (((::Cell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetTarget())) != 0)
    {
        if (reinterpret_cast<::TESObjectCELL *>((((::Cell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetTarget()))))->IsCellInterior())
        {
            if (!((bool)(reinterpret_cast<::fnv_00454b10::TESObjectCELL *>((((::Cell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetTarget()))))->GetFakeExterior())))
            {
                cf38 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingObj *>(&::g_011dd008))))));
                if68 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingObj *>(&::g_011dd034))))));
                yf50 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingObj *>(&::g_011dd0ac))))));
                cf4c = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingObj *>(&::g_011dcff4))))));
            }
        }
    }
    if (a3)
    {
        iflags = iflags | 0x200000;
        if (((::VObj148 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetBaseTexture())) != 0)
        {
            if (((::VObj148 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetBaseTexture()))->VCall148() != 0)
            {
                ProcResult* res84 = (ProcResult*)((::VObj148 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetBaseTexture()))->VCall148();
                if (res84 != 0)
                {
                    if (reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((res84))->HasEffect(11) || reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((res84))->HasEffect(16))
                    {
                        b83d = true;
                    }
                }
            }
        }
    }
    if (apWeapon != 0)
    {
        if (a3)
        {
            if (reinterpret_cast<::S_00522470 *>((apWeapon))->GetPointerByFlag(false) != 0)
                ib15 = true;
        }
        if (ib15)
        {
            iflags = 0x20181;
        }
        else if (a3 && kb52)
        {
            iflags = 0x60182;
        }
        else
        {
            iflags = 0x20182;
        }
        if (!a3 && apListObj != 0)
        {
            jvec = *((::Vec3 *)(::FUN_0045bb80((int)(apListObj))));
        }
        else if (apSource->VCall1d0() != 0)
        {
            jvec = *((::Vec3 *)(::FUN_0045bb80((int)(((ListObj*)apSource->VCall1d0())))));
        }
        if (reinterpret_cast<::FUN_005215a0_shell *>((apWeapon))->FUN_005215a0(b83d) != 0)
        {
            TESSound* sndA = 0;
            TESSound* sndB = 0;
            if (ib15)
            {
                sndA = (TESSound*)reinterpret_cast<::S_00522470 *>((apWeapon))->GetPointerByFlag(b83d);
            }
            else
            {
                sndA = reinterpret_cast<::FUN_005215a0_shell *>((apWeapon))->FUN_005215a0(b83d);
                sndB = ((::TESSound *)(reinterpret_cast<::FUN_00522440_shell *>((apWeapon))->GetValueByFlag(b83d)));
            }
            bool a86 = ::SoundPlaybackManager::CanPlaySoundAt((::TESSound *)(sndA), (*(::NiPoint3 *)&(const ::Vec3 &)(jvec)), yf50);
            bool b85 = ::SoundPlaybackManager::CanPlaySoundAt((::TESSound *)(sndB), (*(::NiPoint3 *)&(const ::Vec3 &)(jvec)), cf4c);
            if (!a86 && !b85)
                return;
            if (!a86)
                sndA = 0;
            if (!b85)
                sndB = 0;
            cpt = jvec - reinterpret_cast<::FUN_00ad78e0_cls *>((((BSAudioShell*)((void *)(::FUN_00453a70())))))->FUN_00ad78e0();
            ef60 = cpt.x * cpt.x + cpt.y * cpt.y + cpt.z * cpt.z;
            int ai;
            for (ai = 0; ai < 20; ai++)
            {
                if (DAT_011dd9e8[ai].f18 == apSource)
                {
                    sentry58 = &DAT_011dd9e8[ai];
                    if (!a3)
                        break;
                }
                if (mentry3c == 0)
                {
                    mentry3c = &DAT_011dd9e8[ai];
                }
                else if (DAT_011dd9e8[ai].f1c <= mentry3c->f1c)
                {
                    mentry3c = &DAT_011dd9e8[ai];
                }
                if (!a3 || DAT_011dd9e8[ai].f18 == (*reinterpret_cast<::Player * *>(&::_g_thePlayer)))
                    continue;
                if (tentry64 == 0)
                {
                    tentry64 = &DAT_011dd9e8[ai];
                }
                else if (tentry64->f20 < DAT_011dd9e8[ai].f20 && ef60 < DAT_011dd9e8[ai].f20)
                {
                    tentry64 = &DAT_011dd9e8[ai];
                }
            }
            if (mentry3c != 0)
                ab51 = reinterpret_cast<::SoundPlaybackHandle *>((mentry3c))->IsValid();
            if (mentry3c != 0 && !ab51)
            {
                aentry140 = mentry3c;
                mentry3c->f18 = apSource;
                mentry3c->f1c = ((unsigned int)(::FUN_00457fe0()));
                mentry3c->f20 = ef60;
            }
            else if (sentry58 != 0)
            {
                aentry140 = sentry58;
                sentry58->f1c = ((unsigned int)(::FUN_00457fe0()));
                sentry58->f20 = ef60;
            }
            else if (tentry64 != 0)
            {
                aentry140 = tentry64;
                tentry64->f18 = apSource;
                tentry64->f1c = ((unsigned int)(::FUN_00457fe0()));
                tentry64->f20 = ef60;
            }
            if (aentry140 != 0)
            {
                if (sndA != 0)
                {
                    reinterpret_cast<::FUN_00ad89e0_shell *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad89e0(0.0f);
                    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad88f0();
                    reinterpret_cast<::SoundPlaybackHandle *>((((SndXShell*)&aentry140->ch0)))->operator=((const ::SoundPlaybackHandle &)((const ::AudioPlaybackHandle &)(((BSAudioShell*)((void *)(::FUN_00453a70())))
                                           ->FUN_00ad7480(::FUN_00511840((char *)(((TESSoundShell*)sndA)))))));
                    gb31 = (unsigned char)reinterpret_cast<::FUN_0082d660_class *>((((TESSoundShell*)sndA)))->GetByteAtOffset44();
                    cg59 = reinterpret_cast<::TESSound *>((((TESSoundShell*)sndA)))->GetField45();
                }
                if (sndB != 0)
                {
                    reinterpret_cast<::FUN_00ad89e0_shell *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad89e0(0.0f);
                    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad88f0();
                    reinterpret_cast<::SoundPlaybackHandle *>((((SndXShell*)&aentry140->ch1)))->operator=((const ::SoundPlaybackHandle &)((const ::AudioPlaybackHandle &)(((BSAudioShell*)((void *)(::FUN_00453a70())))
                                           ->FUN_00ad7480(::FUN_00511840((char *)(((TESSoundShell*)sndB)))))));
                    qb75 = (unsigned char)reinterpret_cast<::FUN_0082d660_class *>((((TESSoundShell*)sndB)))->GetByteAtOffset44();
                    sb0d = reinterpret_cast<::TESSound *>((((TESSoundShell*)sndB)))->GetField45();
                }
                if (!a3 && apListObj != 0)
                {
                    reinterpret_cast<::FUN_00ad8f20_shell *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad8f20((::NiAVObject *)(apListObj));
                    reinterpret_cast<::FUN_00ad8f20_shell *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad8f20((::NiAVObject *)(apListObj));
                }
                else if (apSource->VCall1d0() != 0)
                {
                    if (!(a3 && kb52))
                    {
                        reinterpret_cast<::FUN_00ad8f20_shell *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad8f20((::NiAVObject *)(void *)(apSource->VCall1d0()));
                        reinterpret_cast<::FUN_00ad8f20_shell *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad8f20((::NiAVObject *)(void *)(apSource->VCall1d0()));
                    }
                }
                if (sndA != 0)
                {
                    reinterpret_cast<::FUN_00ad9030_shell *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad9030(1);
                    reinterpret_cast<::FUN_00ad8b60_h *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad8b60(jvec.x, jvec.y, jvec.z);
                    reinterpret_cast<::FUN_00ad89e0_shell *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad89e0(cf38);
                    reinterpret_cast<::FUN_00ad8830_shell *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad8830(false);
                }
                if (sndB != 0)
                {
                    reinterpret_cast<::FUN_00ad9030_shell *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad9030(1);
                    reinterpret_cast<::FUN_00ad8b60_h *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad8b60(jvec.x, jvec.y, jvec.z);
                    reinterpret_cast<::FUN_00ad89e0_shell *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad89e0(if68);
                    reinterpret_cast<::FUN_00ad8830_shell *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad8830(false);
                }
                if (!ib15)
                {
                    reinterpret_cast<::FUN_00ad8be0_shell *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad8be0((float)gb31 * 5.0, (float)cg59 * yf50 * 100.0);
                    reinterpret_cast<::FUN_00ad8be0_shell *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad8be0((float)gb31 * 5.0, (float)cg59 * yf50 * 100.0);
                    reinterpret_cast<::FUN_00ad8b60_h *>((((SndXShell*)&aentry140->ch0)))->FUN_00ad8b60(jvec.x, jvec.y, jvec.z);
                    reinterpret_cast<::FUN_00ad8b60_h *>((((SndXShell*)&aentry140->ch1)))->FUN_00ad8b60(jvec.x, jvec.y, jvec.z);
                }
            }
        }
    }
}

class B3B6B0MapBase
{
  public:
    virtual ~B3B6B0MapBase();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_0083b6b0 : public B3B6B0MapBase
{
  public:
    virtual ~FUN_0083b6b0();
};
// Runs the destructor, then frees the object with Deallocate when flags has bit 0 set, and returns the object pointer.
// @fnv 0x0083b610
void* GlobalObject_0083b5e0::FUN_0083b610(unsigned int flags)
{
    reinterpret_cast<::FUN_0083b6b0 *>((this))->FUN_0083b6b0::~FUN_0083b6b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0083b6b0
FUN_0083b6b0::~FUN_0083b6b0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

namespace fnv_0083d130 {
struct S_0083d130_Str
{
};
struct S_0083d130_Obj
{
};
struct S_0083d130_Node
{
};
struct S_0083d130_Mgr
{
};
bool FUN_008256d0(S_0083d130_Node*);

struct S_0083d130_Class : S_0083d130_Node
{
    void ProcessNodeChain();
};

// @fnv 0x0083d130
void S_0083d130_Class::ProcessNodeChain()
{
    S_0083d130_Node* node = this;
    while (node && !FUN_008256d0(node))
    {
        if (((const char *)(::FUN_00559450((int *)(((::fnv_0083d130::S_0083d130_Str *)(new ((void *)((*((::fnv_0083d130::S_0083d130_Obj **)(new ((void *)(node)) ::Vec3()))))) ::Vec3())))))))
        {
            if (::FUN_0044a670(((const char *)(::FUN_00559450((int *)(((::fnv_0083d130::S_0083d130_Str *)(new ((void *)((*((::fnv_0083d130::S_0083d130_Obj **)(new ((void *)(node)) ::Vec3()))))) ::Vec3()))))))) > 1)
            {
                reinterpret_cast<::fnv_00ad8100::FUN_00ad8100_shell *>((((::fnv_0083d130::S_0083d130_Mgr *)(::FUN_00453a70()))))->FUN_00ad8100((char *)(((const char *)(::FUN_00559450((int *)(((::fnv_0083d130::S_0083d130_Str *)(::FUN_00460140((int)((*((::fnv_0083d130::S_0083d130_Obj **)(new ((void *)(node)) ::Vec3())))))))))))), 0x20100001, (void *)(0));
            }
        }
        node = ((::fnv_0083d130::S_0083d130_Node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
}
}  // namespace fnv_0083d130

struct FUN_0083da30_cls
{
    int m_00;

    int ApplyMaskedOffset(int aValue);
};

// @fnv 0x0083da30
int FUN_0083da30_cls::ApplyMaskedOffset(int aValue)
{
    return (((m_00 != 0) ? -1 : 0) & aValue) + (unsigned int)m_00;
}

struct EffectTime
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    float time38;
    unsigned int unk3C, unk40, unk44;
    float time48;
};
struct EffectHandle
{
};
struct SpellTimes
{
};
struct EffectCollection
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};
struct FUN_008216c0_shell
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    bool reset;
    unsigned int unk2C;
    SpellTimes* spell;
    float time;
    EffectCollection effects;
    EffectHandle active;
    void UpdateEffectTimes();
};
// Computes a time from the active effect's times (or zero if reset), scales it by the spell's times, and applies it to every effect in the collection.
// @fnv 0x008216c0
void FUN_008216c0_shell::UpdateEffectTimes()
{
    float value = 0.0f;
    if (((::EffectTime *)(::FUN_00559450((int *)&(active)))))
        value = FUN_00404010(((::EffectTime *)(::FUN_00559450((int *)&(active))))->time38, ((::EffectTime *)(::FUN_00559450((int *)&(active))))->time48);
    if (reset)
    {
        value = 0.0f;
        ((::EffectTime *)(::FUN_00559450((int *)&(active))))->time38 = 0.0f;
        ((::EffectTime *)(::FUN_00559450((int *)&(active))))->time48 = 0.0f;
    }
    if (value < reinterpret_cast<::PathingRequest *>((spell))->GetActorRadius())
        time = reinterpret_cast<::FUN_00759450_shell *>((spell))->FUN_00759450() * (value / reinterpret_cast<::PathingRequest *>((spell))->GetActorRadius());
    else
        time = reinterpret_cast<::FUN_00759450_shell *>((spell))->FUN_00759450();
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(effects))->GetName())); ++i)
        reinterpret_cast<::ParticleEmitter *>((((::EffectTime *)(::FUN_00559450((int *)(((::EffectHandle *)(reinterpret_cast<::S3e60 *>(&(effects))->FUN_006a7ad0(i)))))))))->AdvanceParticleTimes(time);
}

// Minimal declarations for the process list and its polymorphic entries.
class MobileObject
{
  public:
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual bool IsActor();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual bool IsMagicProjectile();
};
class Actor : public MobileObject
{
  public:
};
class MagicProjectile : public MobileObject
{
  public:
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void UpdateCaster(BCaster_S* caster);
};
struct MobileObjectProcessArray
{
};
struct ProcessRegistry
{
};
struct CasterUpdate : BE, BCaster_S
{
    void UpdateCasters();
};
// If the global manager check fails, releases m_20 when non-null and calls Cleanup.
// @fnv 0x00825b60
FUN_00825b60::~FUN_00825b60()
{
    if (!reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::GlobalMgr_b5774 * *>(&::g_dataHandler))))->FUN_004226e0())
    {
        if (m_20 != 0)
        {
            reinterpret_cast<::C6760Ref *>((m_20))->FUN_00576760();
        }
        reinterpret_cast<::CasterUpdate *>(this)->UpdateCasters();
    }
}

// Iterates the process list's groups 0 and 1, calling FUN_008c4f10 on actors and UpdateCaster on magic projectiles, then updates the player.
// @fnv 0x00825c20
void CasterUpdate::UpdateCasters()
{
    MobileObjectProcessArray* pProcessList = ((::MobileObjectProcessArray *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ProcessRegistry *>(&::g_011e0e80))))->GetCurrentProcessData()));
    for (unsigned int i = 0; i < reinterpret_cast<::FUN_005be5c0_shell *>((pProcessList))->FUN_005be5c0(0); ++i)
    {
        MagicProjectile* object;
        MobileObject* pMobileObject = ((::MobileObject *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((pProcessList))->FUN_00968670(i)));
        Actor* actor = pMobileObject && pMobileObject->IsActor() ? static_cast<Actor*>(pMobileObject) : 0;
        object =
            pMobileObject && pMobileObject->IsMagicProjectile() ? dynamic_cast<MagicProjectile*>(pMobileObject) : 0;
        if (actor)
            reinterpret_cast<::S_8c4f10_Cls *>((actor))->FUN_008c4f10((int)(this));
        else if (object)
            object->UpdateCaster(this);
    }
    for (unsigned int j = reinterpret_cast<::fnv_005de0f0::FUN_005de0f0_shell *>((pProcessList))->FUN_005de0f0(1); j < reinterpret_cast<::FUN_005be5c0_shell *>((pProcessList))->FUN_005be5c0(1); ++j)
    {
        MobileObject* pMobileObject2 = ((::MobileObject *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((pProcessList))->FUN_00968670(j)));
        Actor* actor2 = pMobileObject2 && pMobileObject2->IsActor() ? static_cast<Actor*>(pMobileObject2) : 0;
        MagicProjectile* pMagicProjectile2 =
            pMobileObject2 && pMobileObject2->IsMagicProjectile() ? dynamic_cast<MagicProjectile*>(pMobileObject2) : 0;
        if (actor2)
            reinterpret_cast<::S_8c4f10_Cls *>((actor2))->FUN_008c4f10((int)(this));
        else if (pMagicProjectile2)
            pMagicProjectile2->UpdateCaster(this);
    }
    if ((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))
        reinterpret_cast<::S_8c4f10_Cls *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_008c4f10((int)(this));
}

namespace fnv_0082cf80 {
class C82CF80MagicCaster;
class C82CF80MagicItem;
class C82CF80EffectItem;

class C82CF80ActiveEffect
{
  public:
    C82CF80ActiveEffect(C82CF80MagicCaster* pkCaster, C82CF80MagicItem* pkItem, C82CF80EffectItem* pkEffect);
    virtual ~C82CF80ActiveEffect();
};

class FUN_0082cf80 : public C82CF80ActiveEffect
{
  public:
    FUN_0082cf80(C82CF80MagicCaster* pkCaster, C82CF80MagicItem* pkItem, C82CF80EffectItem* pkEffect);
    virtual ~FUN_0082cf80();
};

// Constructs the object by forwarding the caster, item and effect pointers to the C82CF80ActiveEffect base constructor.
// @fnv 0x0082cf80
FUN_0082cf80::FUN_0082cf80(C82CF80MagicCaster* pkCaster, C82CF80MagicItem* pkItem, C82CF80EffectItem* pkEffect)
    : C82CF80ActiveEffect(pkCaster, pkItem, pkEffect)
{}
}  // namespace fnv_0082cf80


struct SoundFormData
{
    unsigned char ucMinAtten;
    unsigned char ucMaxAtten;
    unsigned char ucStaticAtten;
    unsigned char ucPad03;
    unsigned int uiFlags;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct SoundForm
{
};

struct GameSound
{
};

// @fnv 0x0082d400
unsigned int __cdecl ApplySoundFormToGameSound(GameSound* apSound, void* apForm, unsigned int* apFlags)
{
    unsigned int uiMax2;
    unsigned int uiMin;
    SoundForm* SoundAssetTmp;
    unsigned int uiFlags;

    if (!apForm)
        return 0;

    uiFlags = 0;
    SoundAssetTmp = (SoundForm*)apForm;
    reinterpret_cast<::FUN_00ad89b0_shell *>((apSound))->SetStaticAttenuation(reinterpret_cast<::TESGrass *>((SoundAssetTmp))->GetUnitsFromSurface());
    uiMin = ((unsigned char)(reinterpret_cast<::FUN_0082d660_class *>((SoundAssetTmp))->GetByteAtOffset44()));
    uiMax2 = reinterpret_cast<::TESSound *>((SoundAssetTmp))->GetField45();
    if (!uiMin)
        uiMin = 0xe;
    if (!uiMax2)
        uiMax2 = 0x3c;
    if (reinterpret_cast<::FUN_0082d6e0_Class *>((SoundAssetTmp))->GetHighByteOfField4E() || ((unsigned char)(::FUN_0082d700((void *)(SoundAssetTmp)))))
        reinterpret_cast<::fnv_00ad8e20::FUN_00ad8e20_h *>((apSound))->FUN_00ad8e20(reinterpret_cast<::FUN_0082d6e0_Class *>((SoundAssetTmp))->GetHighByteOfField4E(), ((unsigned char)(::FUN_0082d700((void *)(SoundAssetTmp)))));
    reinterpret_cast<::FUN_00ad8be0_shell *>((apSound))->FUN_00ad8be0(uiMin * 5.0, uiMax2 * 100.0);
    reinterpret_cast<::FUN_00ad8c20_h *>((apSound))->FUN_00ad8c20(reinterpret_cast<::FUN_0082d6a0_Class *>((SoundAssetTmp))->GetShortAt(0), reinterpret_cast<::FUN_0082d6a0_Class *>((SoundAssetTmp))->GetShortAt(1), reinterpret_cast<::FUN_0082d6a0_Class *>((SoundAssetTmp))->GetShortAt(2), reinterpret_cast<::FUN_0082d6a0_Class *>((SoundAssetTmp))->GetShortAt(3),
                          reinterpret_cast<::FUN_0082d6a0_Class *>((SoundAssetTmp))->GetShortAt(4));
    reinterpret_cast<::FUN_00ad8c70_Class *>((apSound))->FUN_00ad8c70(reinterpret_cast<::FUN_0082d6c0_class *>((SoundAssetTmp))->GetShortAtOffset5A());
    reinterpret_cast<::FUN_00ad9030_shell *>((apSound))->FUN_00ad9030(((unsigned char)(reinterpret_cast<::FUN_0082d720_Class *>((SoundAssetTmp))->FUN_0082d720())));
    if ((*(::SoundFormData *)(reinterpret_cast<::Holder *>((SoundAssetTmp))->CopyBig({}))).uiFlags & 1)
    {
        uiFlags |= 0x40;
        reinterpret_cast<::FUN_00ad8ad0_s *>((apSound))->FUN_00ad8ad0((*(::SoundFormData *)(reinterpret_cast<::Holder *>((SoundAssetTmp))->CopyBig({}))).ucStaticAtten);
    }
    if ((*(::SoundFormData *)(reinterpret_cast<::Holder *>((SoundAssetTmp))->CopyBig({}))).uiFlags & 0x800)
        uiFlags |= 0x8000000;
    if (apFlags)
    {
        if ((*(::SoundFormData *)(reinterpret_cast<::Holder *>((SoundAssetTmp))->CopyBig({}))).uiFlags & 0x1000)
            *apFlags |= 1;
        if ((*(::SoundFormData *)(reinterpret_cast<::Holder *>((SoundAssetTmp))->CopyBig({}))).uiFlags & 0x2000)
            *apFlags |= 2;
    }
    uiFlags |= ((unsigned int)(::GetFlagMask((*(::SoundFormData *)(reinterpret_cast<::Holder *>((SoundAssetTmp))->CopyBig({}))).uiFlags)));
    return uiFlags;
}

class Thread82F
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual unsigned int GetPosition();

};

class Stream82F
{
  public:
    unsigned __int64 GetStreamPosition(unsigned __int64* puiPosition);

    void* m_ppVirtualMethodTable;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    Thread82F* m_pBackgroundLoadThread;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    unsigned __int64 m_uiPosition;
};

// If the thread is running, stores its position in m_uiPosition and in puiPosition and returns it; otherwise writes 0 and returns 0.
// @fnv 0x0082f570
unsigned __int64 Stream82F::GetStreamPosition(unsigned __int64* puiPosition)
{
    if (!m_pBackgroundLoadThread || !::FUN_008905f0((bool *)(m_pBackgroundLoadThread)))
    {
        *puiPosition = 0;
        return 0;
    }
    m_uiPosition = m_pBackgroundLoadThread->GetPosition();
    *puiPosition = m_uiPosition;
    return m_uiPosition;
}

struct AudGuid
{
    unsigned long d0;
    unsigned long d1;
    unsigned long d2;
    unsigned long d3;
};


struct IAudUnk
{
    virtual long QueryInterface(const AudGuid& iid, void** out);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};
struct IAudGraph : IAudUnk
{
    virtual long AddFilter(IAudUnk* filter, const wchar_t* name);
};
struct IAudBuilder : IAudUnk
{
    virtual long v0C();
    virtual long v10();
    virtual long v14();
    virtual long v18();
    virtual long v1C();
    virtual long v20();
    virtual long v24();
    virtual long v28();
    virtual long v2C();
    virtual long Render(IAudUnk* pin);
};
struct IAudDispatch : IAudUnk
{
    virtual long d0C();
    virtual long d10();
    virtual long d14();
    virtual long d18();
};
struct IAudBasicAudio : IAudDispatch
{
    virtual long put_Volume(long volume);
};
struct IAudControl : IAudDispatch
{
    virtual long Run();
    virtual long Pause();
    virtual long Stop();
};
struct IAudPosition : IAudDispatch
{
    virtual long get_Duration(double* len);
    virtual long put_CurrentPosition(double t);
    virtual long get_CurrentPosition(double* t);
};
struct IAudEvent : IAudDispatch
{
    virtual long e1C();
    virtual long GetEvent(long* code, long* p1, long* p2, long timeout);
    virtual long e24();
    virtual long e28();
    virtual long e2C();
    virtual long FreeEventParams(long code, long p1, long p2);
};

struct AudMediaType
{
    AudGuid majortype;
    AudGuid subtype;
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
    AudMediaType();
    ~AudMediaType();
};

struct AudReader
{
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    AudReader(char* path);
    virtual ~AudReader();
    bool IsOpen();
};

struct AudPinBase
{
    virtual void p00();
    int unk04;
    int unk08;
};
struct AudPin : AudPinBase, IAudUnk
{
};

struct AudFilterBase
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0C();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual AudPin* GetPin(int index);
    int unk04;
    int unk08;
};
struct AudFilter : AudFilterBase, IAudUnk
{
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    AudFilter(AudReader* reader, AudMediaType* mt, long* hr);
};

struct AudSetting
{
};
struct AudTimer
{
    unsigned int GetTime();
    void Reset();
};

extern int DAT_011dd370;
extern void* DAT_011dd3b0;
extern AudGuid DAT_0107cae8;
extern AudGuid DAT_0107caf8;
extern AudGuid DAT_0107cb18;
extern AudGuid DAT_01093c0c;
extern AudGuid DAT_01093b5c;
extern AudGuid DAT_0107cad8;
extern AudGuid DAT_0107caa8;
extern AudGuid DAT_0107cac8;
extern AudGuid DAT_0107cab8;

extern float DAT_011dd300;
extern float DAT_011dd304;
extern float DAT_011dd308;
extern char DAT_011dd310;

extern float DAT_011dd338;
extern float DAT_011dd33c;
extern float DAT_011dd340;
extern char DAT_011dd311;

// @fnv 0x00830b30
int __cdecl RunAudioChannel(int* param)
{
    unsigned int fadeTimeNow;
    unsigned int duration3;
    char flags;
    unsigned int position;
    IAudPosition* seeking;
    IAudEvent* events;
    unsigned int now;
    AudReader* reader4;
    int channel;
    int id2;
    char path8[0x104];
    float baseVolumeM;
    unsigned int startTime;
    IAudBasicAudio* audio3;
    AudFilter* filter6;
    double seconds;
    float targetParam3;
    IAudBuilder* builder3;
    IAudControl* controlTmp;
    unsigned int syncLimitTmp;
    bool ok4;
    float volumeA;
    unsigned int fadeEnd2;
    int curveType;
    IAudGraph* graphS;
    unsigned int totalLength2;

    channel = param[1];
    id2 = param[0];
    ok4 = true;
    now = 0;
    volumeA = 0.0f;
    baseVolumeM = 0.0f;
    targetParam3 = 0.0f;
    flags = 0;
    curveType = 9;
    startTime = 0;
    position = 0;
    duration3 = 0;
    totalLength2 = 0;
    fadeTimeNow = 0;
    fadeEnd2 = 0;

    syncLimitTmp = ((unsigned int)(::FUN_00647b70(500, *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::AudSetting *>(&::g_011dcfd4)))))) + 500)));
    ::FUN_00830470();
    DAT_011dd370 = DAT_011dd370 + 1;
    if ((channel == 0 && (id2 != DAT_011dd334 || (DAT_011dd310 & 1))) ||
        (channel == 1 && (id2 != DAT_011dd368 || (DAT_011dd311 & 1))))
    {
        ok4 = false;
    }
    now = ((::AudTimer *)(::FUN_00453a70()))->GetTime();
    if (channel == 0)
    {
        DAT_011dd300 = volumeA;
        DAT_011dd330 = now;
        DAT_011dd31c = position;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd320)) = duration3;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd324)) = totalLength2;
        baseVolumeM = DAT_011dd304;
        targetParam3 = DAT_011dd30c;
        flags = DAT_011dd310;
        curveType = DAT_011dd314;
        startTime = (*reinterpret_cast<unsigned int *>(&::DAT_011dd318));
        fadeTimeNow = DAT_011dd328;
        fadeEnd2 = DAT_011dd32c;
        ::TaskQueueInterface::CopyStringToBuffer(path8, 0x104, DAT_011dd0f0);
    }
    else
    {
        DAT_011dd338 = volumeA;
        DAT_011dd364 = now;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd350)) = position;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd354)) = duration3;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd358)) = totalLength2;
        baseVolumeM = DAT_011dd33c;
        targetParam3 = DAT_011dd344;
        flags = DAT_011dd311;
        curveType = DAT_011dd348;
        startTime = (*reinterpret_cast<unsigned int *>(&::DAT_011dd34c));
        fadeTimeNow = DAT_011dd35c;
        fadeEnd2 = DAT_011dd360;
        ::TaskQueueInterface::CopyStringToBuffer(path8, 0x104, DAT_011dd1f8);
    }
    ::fnv_00830490::FUN_00830490();

    graphS = 0;
    builder3 = 0;
    audio3 = 0;
    reader4 = 0;
    filter6 = 0;
    seeking = 0;
    controlTmp = 0;
    events = 0;
    seconds = 0.0;

    reader4 = new AudReader(path8);
    if (!reader4->IsOpen())
    {
        ::FUN_005b5e40();
        ok4 = false;
    }
    else
    {
        long hr = 0;
        AudMediaType mt;
        mt.majortype = DAT_0107cae8;
        if (((int)(::FUN_004812f0(path8, ".mp3"))) != 0)
        {
            mt.subtype = DAT_0107caf8;
        }
        else
        {
            ok4 = false;
            ::FUN_005b5e40();
        }
        if (ok4)
        {
            filter6 = new AudFilter(reader4, &mt, &hr);
            filter6->AddRef();
            CoInitializeEx(0, 0);
            hr = CoCreateInstance(*reinterpret_cast<const CLSID*>(&DAT_0107cb18), 0, 1, *reinterpret_cast<const IID*>(&DAT_01093c0c), (void**)&graphS);
            if (hr < 0)
                ok4 = false;
            hr = graphS->AddFilter(filter6, 0);
            if (hr < 0)
                ok4 = false;
            hr = graphS->QueryInterface(DAT_01093b5c, (void**)&builder3);
            if (hr < 0)
                ok4 = false;
            IAudUnk* pin = filter6->GetPin(0);
            hr = builder3->Render(pin);
            if (hr < 0)
                ok4 = false;
            hr = builder3->QueryInterface(DAT_0107cad8, (void**)&audio3);
            if (hr < 0)
                ok4 = false;
            hr = graphS->QueryInterface(DAT_0107caa8, (void**)&controlTmp);
            if (hr < 0)
                ok4 = false;
            hr = builder3->QueryInterface(DAT_0107cac8, (void**)&seeking);
            if (hr < 0)
                ok4 = false;
            hr = builder3->QueryInterface(DAT_0107cab8, (void**)&events);
            if (hr < 0)
                ok4 = false;
        }
    }

    if (graphS != 0 && seeking != 0)
    {
        seeking->get_Duration(&seconds);
        totalLength2 = (unsigned int)(seconds * 1000.0);
    }
    else
    {
        totalLength2 = 0;
    }

    while (ok4)
    {
        long p1;
        float target;
        long p22;
        long codeC;
        WaitForSingleObject(DAT_011dd3b0, 100);
        ::FUN_00830470();
        now = ((::AudTimer *)(::FUN_00453a70()))->GetTime();
        if (graphS != 0 && seeking != 0)
        {
            seeking->get_CurrentPosition(&seconds);
            position = (unsigned int)(seconds * 1000.0);
        }
        else
        {
            position = 0;
        }
        if (graphS != 0 && seeking != 0)
        {
            seeking->get_Duration(&seconds);
            duration3 = (unsigned int)(seconds * 1000.0);
        }
        else
        {
            duration3 = 0;
        }
        if (channel == 0)
        {
            DAT_011dd300 = volumeA;
            DAT_011dd330 = now;
            DAT_011dd31c = position;
            (*reinterpret_cast<unsigned int *>(&::DAT_011dd320)) = duration3;
            (*reinterpret_cast<unsigned int *>(&::DAT_011dd324)) = totalLength2;
            baseVolumeM = DAT_011dd304;
            targetParam3 = DAT_011dd30c;
            flags = DAT_011dd310;
            curveType = DAT_011dd314;
            startTime = (*reinterpret_cast<unsigned int *>(&::DAT_011dd318));
            fadeTimeNow = DAT_011dd328;
            fadeEnd2 = DAT_011dd32c;
        }
        else
        {
            DAT_011dd338 = volumeA;
            DAT_011dd364 = now;
            (*reinterpret_cast<unsigned int *>(&::DAT_011dd350)) = position;
            (*reinterpret_cast<unsigned int *>(&::DAT_011dd354)) = duration3;
            (*reinterpret_cast<unsigned int *>(&::DAT_011dd358)) = totalLength2;
            baseVolumeM = DAT_011dd33c;
            targetParam3 = DAT_011dd344;
            flags = DAT_011dd311;
            curveType = DAT_011dd348;
            startTime = (*reinterpret_cast<unsigned int *>(&::DAT_011dd34c));
            fadeTimeNow = DAT_011dd35c;
            fadeEnd2 = DAT_011dd360;
        }
        ::fnv_00830490::FUN_00830490();

        target = (flags & 8) ? 0.0f : ::ComputeAttenuatedVolume(curveType, targetParam3);
        if ((flags & 0x10) && now < fadeEnd2)
        {
            float fade = fadeTimeNow > 0 ? ((double)fadeEnd2 - (double)now) / (double)fadeTimeNow : 0.0;
            fade = fade < 1.0 ? fade : 1.0f;
            fade = fade > 0.0 ? fade : 0.0f;
            if (flags & 8)
            {
                volumeA = fade * baseVolumeM;
            }
            else
            {
                volumeA = (1.0f - fade) * (target - baseVolumeM) + baseVolumeM;
            }
        }
        else if (volumeA > target)
        {
            volumeA = volumeA - (double)0.05f;
            volumeA = volumeA > target ? volumeA : target;
        }
        else if (volumeA < target)
        {
            volumeA = volumeA + (double)0.05f;
            volumeA = volumeA < target ? volumeA : target;
        }
        if ((flags & 8) && volumeA < (double)0.01f)
        {
            ok4 = false;
        }
        if (audio3 != 0)
        {
            audio3->put_Volume(volumeA < DAT_01032980 ? -10000 : (int)(::FUN_0082ffd0(volumeA) * 2000.0));
        }
        if (startTime != 0)
        {
            unsigned int current3 = 0;
            if (graphS != 0 && seeking != 0)
            {
                seeking->get_CurrentPosition(&seconds);
                current3 = (unsigned int)(seconds * 1000.0);
            }
            else
            {
                current3 = 0;
            }
            unsigned int nowTime = ((::AudTimer *)(::FUN_00453a70()))->GetTime();
            unsigned int expected = nowTime - startTime;
            while (expected > duration3)
            {
                expected = expected - duration3;
            }
            if (nowTime < startTime)
            {
                expected = 0;
                ::FUN_005b5e40();
            }
            int drift = 0;
            if (current3 > expected)
            {
                drift = current3 - expected;
            }
            else
            {
                drift = expected - current3;
            }
            if (drift > syncLimitTmp)
            {
                if (drift < 80000 || current3 == 0)
                {
                    ::FUN_005b5e40();
                    expected = expected + 50;
                    if (graphS != 0 && seeking != 0)
                    {
                        seeking->put_CurrentPosition((double)expected / 1000.0);
                    }
                }
                else
                {
                    expected = current3;
                }
            }
        }
        if (flags & 2)
        {
            if (builder3 != 0 && controlTmp != 0)
            {
                controlTmp->Stop();
            }
        }
        else if ((flags & 4) || DAT_011dd312 || ((bool)(reinterpret_cast<::FUN_00831de0_Class *>((((::AudTimer *)(::FUN_00453a70()))))->ForwardToMember())))
        {
            if (builder3 != 0 && controlTmp != 0)
            {
                controlTmp->Pause();
            }
        }
        else
        {
            if (seeking != 0 && controlTmp != 0)
            {
                controlTmp->Run();
            }
        }
        if (events != 0)
        {
            while (events->GetEvent(&codeC, &p1, &p22, 0) >= 0)
            {
                switch (codeC)
                {
                    break;
                case 1:
                case 2:
                case 3:
                    events->FreeEventParams(codeC, p1, p22);
                    if (flags & 0x20)
                    {
                        if (builder3 != 0 && controlTmp != 0)
                        {
                            controlTmp->Stop();
                        }
                        if (graphS != 0 && seeking != 0)
                        {
                            seeking->put_CurrentPosition(0.0);
                        }
                        if (!(flags & 2) && seeking != 0 && controlTmp != 0)
                        {
                            controlTmp->Run();
                        }
                    }
                    else
                    {
                        ok4 = false;
                    }
                    break;
                }
                events->FreeEventParams(codeC, p1, p22);
            }
        }
        else
        {
            ok4 = false;
        }
        ::FUN_00830470();
        if ((channel == 0 && (id2 != DAT_011dd334 || (DAT_011dd310 & 1))) ||
            (channel == 1 && (id2 != DAT_011dd368 || (DAT_011dd311 & 1))))
        {
            ok4 = false;
        }
        ::fnv_00830490::FUN_00830490();
    }

    ::FUN_00830470();
    if (channel == 0 && id2 == DAT_011dd334)
    {
        DAT_011dd300 = 0.0f;
        DAT_011dd304 = 0.0f;
        DAT_011dd308 = 0.0f;
        DAT_011dd30c = 0.0f;
        DAT_011dd310 = 0;
        ::TaskQueueInterface::CopyStringToBuffer(DAT_011dd0f0, 0x104, "NONE");
        DAT_011dd314 = 0;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd318)) = 0;
        DAT_011dd31c = 0;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd320)) = 0;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd324)) = 0;
        DAT_011dd328 = 0;
        DAT_011dd32c = 0;
        DAT_011dd330 = 0;
        DAT_011dd334 = 0;
    }
    else if (channel == 1 && id2 == DAT_011dd368)
    {
        DAT_011dd338 = 0.0f;
        DAT_011dd33c = 0.0f;
        DAT_011dd340 = 0.0f;
        DAT_011dd344 = 0.0f;
        DAT_011dd311 = 0;
        ::TaskQueueInterface::CopyStringToBuffer(DAT_011dd1f8, 0x104, "NONE");
        DAT_011dd348 = 0;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd34c)) = 0;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd350)) = 0;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd354)) = 0;
        (*reinterpret_cast<unsigned int *>(&::DAT_011dd358)) = 0;
        DAT_011dd35c = 0;
        DAT_011dd360 = 0;
        DAT_011dd364 = 0;
        DAT_011dd368 = 0;
    }
    DAT_011dd370 = DAT_011dd370 - 1;
    ::fnv_00830490::FUN_00830490();

    if (events != 0)
    {
        events->Release();
        events = 0;
    }
    if (seeking != 0)
    {
        seeking->Release();
        seeking = 0;
    }
    if (controlTmp != 0)
    {
        controlTmp->Release();
        controlTmp = 0;
    }
    if (audio3 != 0)
    {
        audio3->Release();
        audio3 = 0;
    }
    if (builder3 != 0)
    {
        builder3->Release();
        builder3 = 0;
    }
    if (graphS != 0)
    {
        graphS->Release();
        graphS = 0;
    }
    if (filter6 != 0)
    {
        filter6->Release();
        filter6 = 0;
    }
    if (reader4 != 0)
    {
        delete reader4;
    }
    return 0;
}

struct FUN_00831f10_Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
};
// @fnv 0x00831f10
void CallVirtualOnContainedNode(char* a1)
{
    FUN_00831f10_Target* target = (FUN_00831f10_Target*)((::ContNode *)(reinterpret_cast<::Callees *>(((ContNode*)(a1 - 0xc)))->FUN_00726070()));
    target->unk08();
}

struct SaveFormBufferEx : BGSSaveFormBuffer
{
    unsigned int GetPosition();
};

struct SoundForm;

struct SoundEntry
{
    SoundForm* form;
};

struct SoundListNode
{
};

struct SoundQueue
{
};

struct SoundTimer
{
    SoundQueue* m_queue;
    int unk04;
    unsigned int m_uiStartTime;
    int m_fAnimationDuration;
    unsigned char m_flag10;
    unsigned char m_flag11;
    int unk14;
    SoundListNode m_kNode;
    void FUN_00836110(SaveFormBufferEx* buffer);
};
// @fnv 0x00836600
void FUN_00836600_class::FUN_00836600(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((reinterpret_cast<BGSSaveFormBuffer*>(buffer)))->FUN_00865df0(
        (::fnv_00865df0::TESForm *)(void *)(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[0])), 0);
    reinterpret_cast<::SoundTimer *>((reinterpret_cast<FUN_00836600_class*>(reinterpret_cast<char*>(this) + 4)))->FUN_00836110((::SaveFormBufferEx *)(buffer));
}

// Writes elapsed time, timer fields, and queued sound forms to the buffer, patches the count, then saves the queue if present.
// @fnv 0x00836110
void SoundTimer::FUN_00836110(SaveFormBufferEx* buffer)
{
    int elapsed_2 = ::FUN_00453a70()->GetSynchTime() - m_uiStartTime;
    if (m_fAnimationDuration <= 0)
        elapsed_2 = 0;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&elapsed_2, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_fAnimationDuration, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_flag10, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_flag11, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk14, 4, 0);
    int count = 0;
    unsigned int position = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();
    SoundListNode* node3 = &m_kNode;
    while (node3)
    {
        SoundEntry* entry = *((::SoundEntry **)(new ((void *)(node3)) ::Vec3()));
        if (entry)
        {
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(entry->form), 0);
            count++;
        }
        node3 = ((::SoundListNode *)(reinterpret_cast<::Callees *>((node3))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count, position);
    bool hasQueue7 = (bool)(m_queue != 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&hasQueue7, 1, 0);
    if (hasQueue7)
        reinterpret_cast<::B83C270Conversation *>((m_queue))->FUN_0083c270((::B83C270Buffer *)(buffer));
}

extern int DAT_0107cdac;
extern int DAT_0107cd6c;
extern int DAT_0107cd54;

struct FUN_009f9d10_cls
{
    int CallAndReturnThis(int a);
};

struct SpawnedBase
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    void* unk0C;
    void* unk10;
    SpawnedBase(int a, int b, int c, int d);
    ~SpawnedBase();
};

struct FUN_00831e20 : SpawnedBase
{
    FUN_00831e20(int a, int b, int c);
};

// @fnv 0x00831e20
FUN_00831e20::FUN_00831e20(int aiArg1, int aiArg2, int aiArg3) : SpawnedBase(0, 0, aiArg1, aiArg3)
{
    unk00 = &DAT_0107cdac;
    unk0C = &DAT_0107cd6c;
    unk10 = &DAT_0107cd54;
    reinterpret_cast<FUN_009f9d10_cls*>(reinterpret_cast<char*>(this) + 0x1a0)->CallAndReturnThis(aiArg2);
}

struct NiPoint3_8229
{
    float x, y, z;
};

class PrimaryBase8229
{
  public:
    virtual ~PrimaryBase8229();
    int unk04, unk08, unk0C, unk10, unk14;
};

class SecondaryBase8229
{
  public:
    virtual void vfn_00();
};

class FUN_0081dd00 : public PrimaryBase8229, public SecondaryBase8229
{
  public:
    FUN_0081dd00(int iParam1, int iParam2, int iParam3, int iParam4, NiPoint3_8229 kPoint1, NiPoint3_8229 kPoint2);
};

class FUN_00822920 : public FUN_0081dd00
{
  public:
    FUN_00822920(int iParam1, int iParam2, int iParam3, int iParam4, NiPoint3_8229 kPoint1, NiPoint3_8229 kPoint2);
    virtual ~FUN_00822920();
};

// @fnv 0x00822920
FUN_00822920::FUN_00822920(int iParam1, int iParam2, int iParam3, int iParam4, NiPoint3_8229 kPoint1,
                           NiPoint3_8229 kPoint2)
    : FUN_0081dd00(iParam1, iParam2, iParam3, iParam4, kPoint1, kPoint2)
{
    reinterpret_cast<::RefC7 *>(this)->FUN_00930c70();
}

class List8321E0
{
  public:
    ~List8321E0();
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};
class FUN_008321e0
{
  public:
    ~FUN_008321e0();
    int unk00;
    List8321E0 m_kFirst;
    List8321E0 m_kSecond;
};

// Destructor for the FUN_008321e0 class, which contains two List8321E0 members and an int field.
// @fnv 0x008321e0
FUN_008321e0::~FUN_008321e0()
{}

struct FUN_0082f260_tex
{
    virtual int v00(unsigned int flags);
};

struct FUN_0082f260_mem
{
    int unk00;
    ~FUN_0082f260_mem();
};

struct FUN_0082f260_base
{
    virtual ~FUN_0082f260_base();
    int unk04;
};

struct FUN_0082f260_cls : FUN_0082f260_base
{
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    FUN_0082f260_tex* m_108;
    FUN_0082f260_mem m_10c;
    virtual ~FUN_0082f260_cls();
};
// @fnv 0x0082f210
void* FUN_0082f260_class::FUN_0082f210(unsigned int flags)
{
    reinterpret_cast<::FUN_0082f260_cls *>(this)->FUN_0082f260_cls::~FUN_0082f260_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor: if m_108 is non-null, calls its virtual v00(1).
// @fnv 0x0082f260
FUN_0082f260_cls::~FUN_0082f260_cls()
{
    FUN_0082f260_tex* copy;
    FUN_0082f260_tex* tmp;
    if (m_108 != 0)
    {
        copy = m_108;
        tmp = copy;
        tmp != 0 ? tmp->v00(1) : 0;
    }
}

// FUN_00831fe0: __cdecl adjustor thunk (sub dword ptr [esp+4],4; jmp target).
// A __cdecl virtual member passes "this" as the first stack argument, so the
// multiple-inheritance adjustor thunk subtracts the secondary-base offset from
// that stack slot instead of from ecx. Primary base is 4 bytes (vptr only);
// the secondary base subobject sits at +4 inside Derived.
struct PrimaryBase_00831fe0
{
    virtual void __cdecl FUN_00831fe0();
};

struct SecondaryBase_00831fe0
{
    virtual void __cdecl FUN_00831fe0();
};

struct Derived_00831fe0 : PrimaryBase_00831fe0, SecondaryBase_00831fe0
{
    Derived_00831fe0();
// @fnv 0x00831fe0
    virtual void __cdecl FUN_00831fe0();
};

Derived_00831fe0::Derived_00831fe0()
{}

struct BSS
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    ~BSS();
};
struct FUN_0083c750 : BSS
{
    BSS m_uiX;
    ~FUN_0083c750();
};
// Calls FUN_0083c750, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0083c720
void* FUN_0083c750_class::FUN_0083c720(unsigned int flags)
{
    reinterpret_cast<::FUN_0083c750 *>(this)->FUN_0083c750::~FUN_0083c750();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor with an empty body; the m_uiX member and the BSS base are destroyed implicitly.
// @fnv 0x0083c750
FUN_0083c750::~FUN_0083c750()
{}

namespace fnv_0082f1b0 {
#include <windows.h>

// Wrapper around the Win32 critical-section API: locks the section owned by
// the object passed in the fastcall register (ecx).
// @fnv 0x0082f1b0
void FUN_0082f1b0(void* apCriticalSection)
{
    EnterCriticalSection((LPCRITICAL_SECTION)apCriticalSection);
}
}  // namespace fnv_0082f1b0

// FUN_0082b370 - constructor of the argument holder object: runs the base
// constructor (FUN_00803d30), installs its own vtable and clears the flag byte
// at +0x48.

extern void* DAT_0107c53c[];

struct ArgHolderBaseCtor
{
    void FUN_00803d30(int a, int b, int c);
};

// Calls FUN_00803d30 with a, b and c, sets the vtable pointer to DAT_0107c53c, and zeroes _pad[0x48].
// @fnv 0x0082b370
FUN_0082b370::FUN_0082b370(int a, int b, int c)
{
    ((ArgHolderBaseCtor*)this)->FUN_00803d30(a, b, c);
    *(void***)this = DAT_0107c53c;
    _pad[0x48] = 0;
}

void FUN_00837500();

enum ENUM_FORM_ID;

bool FUN_0082d740(TESSound* self, int* outA, int* outB);

FUN_0082b370* CreateFUN0082b370(int a, int b, int c);

void* __cdecl CreateFUN0082cf80(int a, int b, int c);

int strcpy_s(char* dest, unsigned int size, const char* src);

int FUN_00831f70(int unused);

// These declarations name the existing BSStringT ABI accessors omitted from
// the supplied class declaration; they add no storage or replacement bodies.
struct StringAccess530
{
};

struct BraceString530 : BSStringT<char>
{
    BSStringT<char> FUN_0083d8b0();
};

// @fnv 0x0083d8b0
BSStringT<char> BraceString530::FUN_0083d8b0()
{
    unsigned int output6 = 0;  // next output character
    int depth_ = 0;            // nesting depth
    unsigned int index4;       // input character index
    BSStringT<char> result;
    reinterpret_cast<::TextString *>(&(result))->FUN_004037f0(((const char *)(::FUN_00559450((int *)this))), 0);
    for (index4 = 0; index4 < ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((StringAccess530*)this)))->FUN_004048e0())); ++index4)
    {
        if (((const char *)(::FUN_00559450((int *)this)))[index4] == '{')
        {
            ++depth_;
        }
        else if (((const char *)(::FUN_00559450((int *)this)))[index4] == '}')
        {
            depth_ = depth_ == 0 ? 0 : depth_ - 1;
        }
        if (depth_ == 0)
        {
            if (((const char *)(::FUN_00559450((int *)this)))[index4] != '}')
            {
                *((char *)(reinterpret_cast<::FUN_0083da30_cls *>((((StringAccess530*)&result)))->ApplyMaskedOffset(output6))) = ((const char *)(::FUN_00559450((int *)this)))[index4];
                ++output6;
            }
        }
    }
    if (output6 < ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((StringAccess530*)&result)))->FUN_004048e0())))
    {
        *((char *)(reinterpret_cast<::FUN_0083da30_cls *>((((StringAccess530*)&result)))->ApplyMaskedOffset(output6))) = 0;
    }
    result.SetLength(output6);
    return result;
}

#include "generated/data/staging/blk_00820000_od.inc"
