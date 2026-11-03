
// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/A89210IntsExtraData.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C613A0_Extra.h"
#include "fnv/decl/Collector62.h"
#include "fnv/decl/ExtraDataObject.h"
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/Extra_00a998e0.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045bb20_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a64160_cls.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00a64ce0_shell.h"
#include "fnv/decl/FUN_00a698a0_class.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a89ae0_shell.h"
#include "fnv/decl/FUN_00a99870_shell.h"
#include "fnv/decl/FUN_00a99a90_IntsExtraData.h"
#include "fnv/decl/FUN_00c319e0_cls.h"
#include "fnv/decl/FUN_00c31b80_This.h"
#include "fnv/decl/FUN_00c31db0_cls.h"
#include "fnv/decl/FUN_00c5fd50_cls.h"
#include "fnv/decl/FUN_00c62390_cls.h"
#include "fnv/decl/FUN_00c64e70.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyOwner.h"
#include "fnv/decl/NiObject_00a7b3d0.h"
#include "fnv/decl/NiPSysBoxEmitterWrapper.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/ObjX.h"
#include "fnv/decl/ParticleModifierBinary.h"
#include "fnv/decl/PositionState.h"
#include "fnv/decl/S00c62f40_Array.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/S_00a742a0.h"
#include "fnv/decl/SetAtArray.h"
#include "fnv/decl/Stub_00c31b60.h"
#include "fnv/decl/X.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_00a9a4e0__Cls_00a9a4e0.h"
#include "fnv/decl/fnv_00c63b40__FUN_00c63b40.h"
#include "fnv/decl/fnv_00c65490__C65490_Owner.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a26000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a3d000.h"
#include "fnv/symbols_00a41000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00a9a000.h"
#include "fnv/symbols_00c63000.h"
#include "fnv/symbols_0109d000.h"
#include "fnv/symbols_010a0000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01204000.h"
#include "../../include/layout_support.h"


struct FUN_00c600f0_Class
{
    void* FUN_00c600f0();
};

// @fnv 0x00c600f0
void* FUN_00c600f0_Class::FUN_00c600f0()
{
    return &(*reinterpret_cast<void * *>(&::g_01204388));
}

struct NiStream;

class CloningProcess;
class NiStream;
struct NiPSysModifier
{
    virtual void LinkObject(NiStream&);
public:
    void CopyMemberData(::NiPSysModifier *, ::CloningProcess &);
public:
    void LoadBinary(::NiStream &);
};

struct BSPSysSimpleColorModifier : public NiPSysModifier
{
    void FUN_00c60910(NiStream& stream);
};

// @fnv 0x00c60910
void BSPSysSimpleColorModifier::FUN_00c60910(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
}

struct FUN_00c60930_class
{
    void FUN_00c60930(void* a);
};

// @fnv 0x00c60930
void FUN_00c60930_class::FUN_00c60930(void* a)
{
    reinterpret_cast<::X *>(this)->FUN_00c31670((*(::NiStream *)(a)));
}


struct FUN_00c60d40_Class
{
    void* FUN_00c60d40();
};

// @fnv 0x00c60d40
void* FUN_00c60d40_Class::FUN_00c60d40()
{
    return &(*reinterpret_cast<void * *>(&::g_01204390));
}

struct FUN_00c61420_Class
{
    void* FUN_00c61420(void* p);
};

// @fnv 0x00c61420
void* FUN_00c61420_Class::FUN_00c61420(void* apUnused)
{
    return this;
}

struct FUN_00a99870_Class
{
    void FUN_00a99870(int, int);
};

void FUN_00a99870_Class::FUN_00a99870(int, int)
{}

struct FUN_00c61430_Class
{
    void FUN_00c61430(int, int);
};

// @fnv 0x00c61430
void FUN_00c61430_Class::FUN_00c61430(int a, int b)
{
    reinterpret_cast<::FUN_00a99870_shell *>((((FUN_00a99870_Class*)this)))->FUN_00a99870((::FUN_00a99870_shell *)(a), (void *)(b));
}

struct FUN_00c61450_Class
{
    void FUN_00c61450(int a);
};

// @fnv 0x00c61450
void FUN_00c61450_Class::FUN_00c61450(int aiValue)
{
    reinterpret_cast<::FUN_00a99a90_IntsExtraData *>(this)->LoadBinary((*(::BA99A90Stream *)(aiValue)));
}

struct FUN_00a9af00_class
{
};

struct FUN_00c61470_class : FUN_00a9af00_class
{
    void CallBaseWithArg(int a);
};

// @fnv 0x00c61470
void FUN_00c61470_class::CallBaseWithArg(int aiValue)
{
    ::FUN_00a9af00();
}

struct FUN_00c61490_Class
{
    bool IsNot(const void* arg);
};

// Returns the logical negation of FUN_00a89ae0(arg).
// @fnv 0x00c61490
bool FUN_00c61490_Class::IsNot(const void* arg)
{
    return !reinterpret_cast<::FUN_00a89ae0_shell *>(this)->FUN_00a89ae0((int)(arg));
}

struct FUN_00c614c0_Class
{
    void FUN_00c614c0(void* ap);
};

// @fnv 0x00c614c0
void FUN_00c614c0_Class::FUN_00c614c0(void* ap)
{
    reinterpret_cast<::A89210IntsExtraData *>(this)->FUN_00a89210((*(::A89210Stream *)(ap)));
}

struct FUN_00c614e0_Class
{
    char FUN_00c614e0(int arg);
};
// Calls FUN_00a998e0 with arg and returns its result.
// @fnv 0x00c614e0
char FUN_00c614e0_Class::FUN_00c614e0(int arg)
{
    char result = ((char)(reinterpret_cast<::Extra_00a998e0 *>(this)->FUN_00a998e0((::Extra_00a998e0 *)(arg))));
    return result;
}

struct NiFixedString;
struct NiAVObject
{
    void FUN_00c61610();
};

// @fnv 0x00c61610
void NiAVObject::FUN_00c61610()
{
    ::AssignFixedString((char *)this, (int)&(*DAT_012043a0), {});
}


struct FUN_00c61810_class
{
    void* FUN_00c61810();
};

// @fnv 0x00c61810
void* FUN_00c61810_class::FUN_00c61810()
{
    return &(*reinterpret_cast<void * *>(&::g_012043a4));
}

struct FUN_00c61820_class
{
    void* FUN_00c61820(int);
};

// @fnv 0x00c61820
void* FUN_00c61820_class::FUN_00c61820(int)
{
    return this;
}

struct NiStream;

class NiStream;
struct NiPSysVolumeEmitter
{
    void LoadBinary(NiStream&);
    void LoadBinaryFromStream(NiStream* stream);
public:
    void LinkObject(::NiStream &);
};

// @fnv 0x00c61ef0
void NiPSysVolumeEmitter::LoadBinaryFromStream(NiStream* stream)
{
    LoadBinary(*stream);
}

namespace fnv_00c61f10 {
struct NiStream;
struct NiPSysVolumeEmitter
{
    void FUN_00c61f10(NiStream& stream);
};

// @fnv 0x00c61f10
void NiPSysVolumeEmitter::FUN_00c61f10(NiStream& stream)
{
    reinterpret_cast<::NiPSysVolumeEmitter *>(this)->LinkObject((::NiStream &)(stream));
}
}  // namespace fnv_00c61f10

struct NiStream;
struct NiObject
{
    void FUN_00c61f30(NiStream& stream);
};
struct FUN_00c61f60_class
{
    void FUN_00c2f4f0(int);
    void FUN_00c61f60(int);
};

// @fnv 0x00c61f60
void FUN_00c61f60_class::FUN_00c61f60(int arg)
{
    FUN_00c2f4f0(arg);
}

struct FUN_00c61f80_cls
{
    void FUN_00c61f80(void* apParam);
};

// @fnv 0x00c61f80
void FUN_00c61f80_cls::FUN_00c61f80(void* apParam)
{
    reinterpret_cast<::Stub_00c31b60 *>(this)->FUN_00c31b60(apParam);
}

struct NiAVObject;
struct NiPSysCylinderEmitter
{
    bool FUN_00c61fa0(NiAVObject*);
};

// @fnv 0x00c61fa0
bool NiPSysCylinderEmitter::FUN_00c61fa0(NiAVObject* ap)
{
    return reinterpret_cast<::FUN_00c31b80_This *>(this)->FUN_00c31b80(ap);
}

struct FUN_00c627e0_Class
{
    void FUN_00c627e0(void* p);
};


struct FUN_00c632e0_Class
{
    void* FUN_00c632e0();
};

// @fnv 0x00c632e0
void* FUN_00c632e0_Class::FUN_00c632e0()
{
    return &(*reinterpret_cast<void * *>(&::g_012043b8));
}

namespace fnv_00c63930 {
struct NiStream;
struct NiPSysModifier
{
    virtual void LinkObject(NiStream&);
};
struct FUN_00c63930_Class : public NiPSysModifier
{
    void FUN_00c63930(NiStream&);
};
// @fnv 0x00c63930
void FUN_00c63930_Class::FUN_00c63930(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
}
}  // namespace fnv_00c63930

struct FUN_00c31670_class
{
};

struct FUN_00c63950_class
{
    void ForwardToOther(int a);
};

// @fnv 0x00c63950
void FUN_00c63950_class::ForwardToOther(int aiValue)
{
    reinterpret_cast<::X *>((((FUN_00c31670_class*)this)))->FUN_00c31670((*(::NiStream *)(aiValue)));
}

struct GlobalObject_00a7b610;

struct FUN_00c63aa0_class
{
    GlobalObject_00a7b610* FUN_00c63aa0();
};

// @fnv 0x00c63aa0
GlobalObject_00a7b610* FUN_00c63aa0_class::FUN_00c63aa0()
{
    return &::g_012043c8;
}


// @fnv 0x00c63c10
void __cdecl CallWithSameArgumentTwice(int aiValue)
{
    ::fnv_00c63c30::FUN_00c63c30((::fnv_00c63c30::ObjC63 *)(aiValue), (::fnv_00c63c30::ObjC63 *)(aiValue));
}

struct NiBinaryExtraData
{
};

struct BSDecalPlacementVectorExtraData : NiBinaryExtraData
{
    void LinkToObject(void*);
};

// @fnv 0x00c644b0
void BSDecalPlacementVectorExtraData::LinkToObject(void* apObject)
{
    ::FUN_00a9af00();
}

struct FUN_00c644d0_Class
{
    unsigned char FUN_00c644d0(const char*);
};
// Calls Equals with arg and returns its result.
// @fnv 0x00c644d0
unsigned char FUN_00c644d0_Class::FUN_00c644d0(const char* arg)
{
    unsigned char result = reinterpret_cast<::S_00a742a0 *>(this)->Equals((::S_00a742a0 *)(arg));
    return result;
}


struct FUN_00c64600_Class
{
    void* GetGlobalPointer();
};

// @fnv 0x00c64600
void* FUN_00c64600_Class::GetGlobalPointer()
{
    return &(*reinterpret_cast<void * *>(&::g_012043d4));
}

namespace fnv_00c64950 {
struct NiStream
{
};
struct NiObject
{
    void FUN_00c64950(NiStream* stream);
};
// Links this object to the stream, then passes the string pointer at offset 8 to the stream's FUN_00a64160.
// @fnv 0x00c64950
void NiObject::FUN_00c64950(NiStream* stream)
{
    ::FUN_00a89af0((int)this);
    reinterpret_cast<::FUN_00a64160_cls *>((stream))->FUN_00a64160(*(const char**)((char*)this + 8));
}
}  // namespace fnv_00c64950

namespace fnv_00c64aa0 {
struct NiStream
{
};

struct NiObject
{
    void FUN_00c64aa0(NiStream& stream);
};

// @fnv 0x00c64aa0
void NiObject::FUN_00c64aa0(NiStream& stream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(stream));
    reinterpret_cast<::S_00a64670_Foo *>(&(stream))->FUN_00a64670();
}
}  // namespace fnv_00c64aa0

struct NiStream;
struct NiObjectBase
{
    bool RegisterStreamables(NiStream&);
};
struct FUN_00c64b70 : NiObjectBase
{
    bool RegisterStreamables(NiStream& stream);
};
// @fnv 0x00c64b70
bool FUN_00c64b70::RegisterStreamables(NiStream& stream)
{
    return NiObjectBase::RegisterStreamables(stream);
}

struct FUN_00c64fc0_class
{
    int GetThisAddress(int);
};

// @fnv 0x00c64fc0
int FUN_00c64fc0_class::GetThisAddress(int)
{
    return (int)this;
}

struct NiStream;
struct NiExtraData
{
    void LinkObject(NiStream& stream);
    void FUN_00c65160(NiStream& stream);
};

// @fnv 0x00c65160
void NiExtraData::FUN_00c65160(NiStream& stream)
{
    LinkObject(stream);
}

struct C00c541e0
{
    bool FUN_00c65290(int a);
};

// Calls FUN_00a7b3d0 with the given int and returns its bool result.
// @fnv 0x00c65290
bool C00c541e0::FUN_00c65290(int aiValue)
{
    bool result = ((bool)(reinterpret_cast<::NiObject_00a7b3d0 *>(this)->FUN_00a7b3d0((::NiObject_00a7b3d0 *)(aiValue))));
    return result;
}

extern "C" void* DAT_012043f0;

struct FUN_00c657e0_class
{
    void* GetGlobalDataPtr();
};

// @fnv 0x00c657e0
void* FUN_00c657e0_class::GetGlobalDataPtr()
{
    return &DAT_012043f0;
}

extern "C" void NiFreeAlias(void*);
extern int DAT_010c377c;

struct NiTPointerList_00c62890
{
    void* m_pObjectItem;
    void* m_pNext;
    void FUN_00c62890();
};

// @fnv 0x00c62890
void NiTPointerList_00c62890::FUN_00c62890()
{
    m_pObjectItem = &DAT_010c377c;
    void* result = m_pNext;
    NiFreeAlias(result);
}

extern "C" void NiFreeAlias(void*);
extern int DAT_010c3a08;
struct FUN_00c65680_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void FUN_00c65680();
};
// @fnv 0x00c65680
void FUN_00c65680_Class::FUN_00c65680()
{
    m_iWordAt00 = &DAT_010c3a08;
    void* p = m_iWordAt04;
    NiFreeAlias(p);
}

struct FUN_00c600c0_class
{
    void* FUN_00c600c0(unsigned int flags);
};

// Calls FUN_00c5fd50, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c600c0
void* FUN_00c600c0_class::FUN_00c600c0(unsigned int flags)
{
    reinterpret_cast<::FUN_00c5fd50_cls *>(this)->FUN_00c5fd50();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

struct FUN_00c613a0_Class
{
    void* FUN_00c617e0(unsigned int flags);
};
// @fnv 0x00c617e0
void* FUN_00c613a0_Class::FUN_00c617e0(unsigned int flags)
{
    reinterpret_cast<::C613A0_Extra *>((this))->C613A0_Extra::~C613A0_Extra();
    if (flags & 1)
        ::operator delete(this, 20);
    return this;
}

extern "C" void NiFree(void*);
struct MemoryManager
{
};
struct FUN_00c63210_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* FUN_00c63210(int flag);
};
// Sets the first field to a global, frees the second field with NiFree, and deallocates this if flag bit 0 is set.
// @fnv 0x00c63210
void* FUN_00c63210_Class::FUN_00c63210(int flag)
{
    m_iWordAt00 = &DAT_010c377c;
    void* p = m_iWordAt04;
    NiFree(p);
    if (flag & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct FUN_00a7b300_shell
{
    void FUN_00a7b300();
};
struct FUN_00c632f0_class
{
    void* FUN_00c632f0(unsigned int flags);
};
// @fnv 0x00c632f0
void* FUN_00c632f0_class::FUN_00c632f0(unsigned int flags)
{
    reinterpret_cast<FUN_00a7b300_shell*>(this)->FUN_00a7b300();
    if (flags & 1)
        operator delete(this, 12);
    return this;
}

struct CloningProcess;
struct NiPSysModifierCopy : NiPSysModifier
{
};
struct FUN_00c63840_Class : NiPSysModifier
{
    void CopyModifierWithValue(NiPSysModifier* dst, CloningProcess* proc);
};
// @fnv 0x00c63840
void FUN_00c63840_Class::CopyModifierWithValue(NiPSysModifier* dst, CloningProcess* proc)
{
    reinterpret_cast<::NiPSysModifier *>((((NiPSysModifierCopy*)this)))->CopyMemberData(dst, *proc);
    float value = *(float*)((char*)this + 0x20);
    *(float*)((char*)dst + 0x20) = value;
}

struct SStream;
struct SObj;
struct NiPSysModifier_00c31950
{
};
struct FUN_00c63970_class : NiPSysModifier_00c31950
{
    void FUN_00c63970(void* stream);
};
// @fnv 0x00c63970
void FUN_00c63970_class::FUN_00c63970(void* stream)
{
    reinterpret_cast<::ParticleModifierBinary *>(this)->FUN_00c31950((*(::OutputStream *)(stream)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)(reinterpret_cast<SStream*>(stream)), (int)(reinterpret_cast<SObj*>(this + 0x20)));
}

void __cdecl FUN_00c63b40(void* p);
struct FUN_00c64610_Class
{
    void FUN_00c63b40();
    void* FUN_00c64610(unsigned int flags);
};
// Calls FUN_00c63b40, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c64610
void* FUN_00c64610_Class::FUN_00c64610(unsigned int flags)
{
    reinterpret_cast<::fnv_00c63b40::FUN_00c63b40 *>(this)->fnv_00c63b40::FUN_00c63b40::~FUN_00c63b40();
    if (flags & 1)
        operator delete(this, 0x40);
    return this;
}

namespace fnv_00c64710 {
struct MemoryManager
{
};
struct FUN_00c64710_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00c64710();
};
// @fnv 0x00c64710
void FUN_00c64710_Class::FUN_00c64710()
{
    void* p = m_iWordAt00;
    while (p)
    {
        void* next = p;
        p = *reinterpret_cast<void**>(p);
        *reinterpret_cast<void**>(reinterpret_cast<char*>(next) + 8) = 0;
        void* pFreed = next;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00c64710::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(pFreed);
    }
    m_8 = 0;
    m_iWordAt00 = 0;
    m_iWordAt04 = 0;
}
}  // namespace fnv_00c64710

struct FUN_00c64930_Class
{
    void FUN_00c64930(int a);
};

// @fnv 0x00c64930
void FUN_00c64930_Class::FUN_00c64930(int a)
{}

struct FUN_00c64940_Class
{
    bool FUN_00c64940(int a);
};
// @fnv 0x00c64940
bool FUN_00c64940_Class::FUN_00c64940(int a)
{
    return true;
}

struct FUN_00c64c30_Class
{
    bool FUN_00c64c30(int a);
};

// @fnv 0x00c64c30
bool FUN_00c64c30_Class::FUN_00c64c30(int a)
{
    return false;
}

extern int DAT_010c3384;
struct NiPSysPositionModifier
{
    NiPSysPositionModifier();
    ~NiPSysPositionModifier();
};
struct FUN_00c60240 : NiPSysPositionModifier
{
    int m_vt;
    float m_f[4];
    float m_v[4];
    float m_w[4];
    FUN_00c60240();
};
// Constructor: sets the vtable pointer and zeroes the four-float arrays at offsets 0x18, 0x28 and 0x38.
// @fnv 0x00c60240
FUN_00c60240::FUN_00c60240()
{
    m_vt = (int)&DAT_010c3384;
    {
        float* p = &this->m_v[1];
        p[0] = 0.0f;
        p[1] = 0.0f;
        p[2] = 0.0f;
        p[3] = 0.0f;
    }
    {
        float* q = &this->m_w[1];
        q[0] = 0.0f;
        q[1] = 0.0f;
        q[2] = 0.0f;
        q[3] = 0.0f;
    }
    {
        float* r = (float*)((char*)this + 0x38);
        r[0] = 0.0f;
        r[1] = 0.0f;
        r[2] = 0.0f;
        r[3] = 0.0f;
    }
}

struct NiStream;
class NiStream;
struct RgbaColor
{
public:
    void LoadBinary(::NiStream &);
};
struct FUN_00c60950_class : NiPSysModifier_00c31950
{
    void FUN_00c60950(NiStream* stream);
};
// @fnv 0x00c60950
void FUN_00c60950_class::FUN_00c60950(NiStream* stream)
{
    reinterpret_cast<::ParticleModifierBinary *>(this)->FUN_00c31950((*(::OutputStream *)(stream)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (int)((SObj*)((char*)this + 0x48)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (int)((SObj*)((char*)this + 0x4c)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (int)((SObj*)((char*)this + 0x50)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (int)((SObj*)((char*)this + 0x54)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (int)((SObj*)((char*)this + 0x58)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (int)((SObj*)((char*)this + 0x5c)));
    reinterpret_cast<::FUN_00a698a0_class *>((((RgbaColor*)((char*)this + 0x18))))->FUN_00a698a0((void *)&(*stream));
    reinterpret_cast<::FUN_00a698a0_class *>((((RgbaColor*)((char*)this + 0x28))))->FUN_00a698a0((void *)&(*stream));
    reinterpret_cast<::FUN_00a698a0_class *>((((RgbaColor*)((char*)this + 0x38))))->FUN_00a698a0((void *)&(*stream));
}

struct P03MM
{
};
struct FUN_00c62090_Class
{
    char* BuildAttachTypeString(const char* name, int type);
};
// Allocates strlen(name)+0x10 bytes and formats name with an AT_* attach-type suffix chosen by type (0 vertices, 1 specific objs, 2 nodes).
// @fnv 0x00c62090
char* FUN_00c62090_Class::BuildAttachTypeString(const char* name, int type)
{
    unsigned int size = std::strlen(name) + 0x10;
    char* buffer = (char*)reinterpret_cast<::MemoryManagerStandIn *>((((P03MM*)&g_memoryManager)))->FUN_00aa3e40(size);
    char* result = buffer;
    switch (type)
    {
    case 0:
        ::FUN_00406d00(result, size, "%s = AT_VERTICES", name);
        break;
    case 1:
        ::FUN_00406d00(result, size, "%s = AT_SPECIFICOBJS", name);
        break;
    case 2:
        ::FUN_00406d00(result, size, "%s = AT_NODES", name);
        break;
    }
    return result;
}


struct FUN_00c63320_Class
{
    GlobalObject_00a7b610* FUN_00c63320();
};

// @fnv 0x00c63320
GlobalObject_00a7b610* FUN_00c63320_Class::FUN_00c63320()
{
    return &::g_012043b0;
}

struct NiStream
{
};
struct NiExtraDataSaveHelper
{
};
struct FUN_00c65210_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    unsigned short m_18;
    void FUN_00c65210(NiStream& stream);
};
// @fnv 0x00c65210
void FUN_00c65210_class::FUN_00c65210(NiStream& stream)
{
    reinterpret_cast<::FUN_00a7b2c0_shell *>((((NiExtraDataSaveHelper*)this)))->FUN_00a7b2c0(stream);
    unsigned int count = m_18;
    ::FUN_0044adf0((::MiddleHighProcess *)&(stream), (int)&(count));
    for (unsigned int i = 0; i < count; i++)
    {
        const char* pcString = ((const char**)m_10)[i];
        reinterpret_cast<::FUN_00a641f0_cls *>(&(stream))->WriteObjectLink((void *)(pcString));
        reinterpret_cast<::FUN_00a641f0_cls *>(&(stream))->WriteObjectLink((void *)(pcString + 4));
    }
}

extern "C" void* __cdecl NiMalloc(unsigned int size);
struct FUN_00c65760_Class
{
    int* m_pVtbl;
    void* m_pData;
    unsigned short m_iArrayLength;
    unsigned short m_iFlags;
    unsigned short m_iPad;
    unsigned short m_iType;
    void* InitArray(unsigned short count, unsigned short type);
};
// Sets the vtable, stores count and type, clears flags, and allocates count ints into m_pData (or null when count is 0).
// @fnv 0x00c65760
void* FUN_00c65760_Class::InitArray(unsigned short count, unsigned short type)
{
    m_pVtbl = (int*)&DAT_010c3a08;
    m_iArrayLength = count;
    m_iType = type;
    m_iFlags = 0;
    m_iPad = 0;
    if (m_iArrayLength > 0)
    {
        unsigned int n = m_iArrayLength;
        m_pData = NiMalloc(n * sizeof(int));
    }
    else
        m_pData = 0;
    return this;
}

struct FUN_00c61b10
{
    char m_iWordAt00[0x6c];
    FUN_00c61b10();
    ~FUN_00c61b10();
};
// Allocates and constructs a new FUN_00c61b10 object, returning the pointer.
// @fnv 0x00c61e70
FUN_00c61b10* FUN_00c61e70()
{
    return new FUN_00c61b10;
}

extern "C" void* __cdecl NiMalloc(unsigned int);

struct FUN_00c63260_class
{
    int* m_ppVirtualMethodTable;
    void* m_data;
    unsigned short m_uiX;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_uiY;
    FUN_00c63260_class(unsigned short x, unsigned short y);
};

// @fnv 0x00c63260
FUN_00c63260_class::FUN_00c63260_class(unsigned short x, unsigned short y)
{
    m_ppVirtualMethodTable = &DAT_010c377c;
    m_uiX = x;
    m_uiY = y;
    m_iElementCount = 0;
    m_uiItemCount = 0;
    if (m_uiX > 0)
    {
        int i = m_uiX;
        m_data = NiMalloc(i << 2);
    }
    else
        m_data = 0;
}

struct NiPoint3_ZERO
{
    int x;
    int y;
    int z;
};
extern int DAT_010c37fc;
struct FUN_00c63330 : NiPSysPositionModifier
{
    FUN_00c63330();
};
// Initializes the object's vtable pointer, sets field 3 to 0xbb8, zeroes two NiPoint3 members at offsets 0x24 and 0x30, and clears floats at indices 6 and 8.
// @fnv 0x00c63330
FUN_00c63330::FUN_00c63330()
{
    ((int*)this)[0] = (int)&DAT_010c37fc;
    ((int*)this)[3] = 0xbb8;
    *(NiPoint3_ZERO*)((char*)this + 0x24) = (*reinterpret_cast<struct ::NiPoint3_ZERO *>((void *)&::NiPoint3::ZERO));
    *(NiPoint3_ZERO*)((char*)this + 0x30) = (*reinterpret_cast<struct ::NiPoint3_ZERO *>((void *)&::NiPoint3::ZERO));
    ((float*)this)[8] = 0.0f;
    ((float*)this)[6] = 0.0f;
}

int strcpy_s(char* dst, unsigned int size, const char* src);
struct MemoryManagerAllocHelper
{
};
struct FUN_00c64780_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_00c64780(const char* apName);
};
// Frees the stored string, then allocates a copy of apName (if non-null) and stores it in m_8.
// @fnv 0x00c64780
void FUN_00c64780_Class::FUN_00c64780(const char* apName)
{
    unsigned int uiSize;
    void* pOld7 = m_8;
    reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(pOld7);
    m_8 = 0;
    if (apName)
    {
        uiSize = strlen(apName) + 1;
        void* pNew = reinterpret_cast<::MemoryManagerStandIn *>((((MemoryManagerAllocHelper*)&g_memoryManager)))->FUN_00aa3e40(uiSize);
        m_8 = pNew;
        if (m_8)
        {
            char* pBuffer2 = (char*)m_8;
            strcpy_s(pBuffer2, uiSize, apName);
        }
    }
}

struct FUN_00c65710_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* FUN_00c65710(unsigned int flags);
};
// @fnv 0x00c65710
void* FUN_00c65710_Class::FUN_00c65710(unsigned int flags)
{
    void* p;
    m_iWordAt00 = &DAT_010c3a08;
    p = m_iWordAt04;
    NiFree(p);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct IsEqualHelper
{
    bool IsEqual(NiObject* arg);
};

struct FUN_00c60000_Class
{
    bool IsEqualWithFloat(void* arg);
};

// Calls IsEqual on arg, then returns whether the float at offset 24 of arg equals the one at offset 24 of this.
// @fnv 0x00c60000
bool FUN_00c60000_Class::IsEqualWithFloat(void* apObject)
{
    if (!((IsEqualHelper*)this)->IsEqual((NiObject*)apObject))
        return false;
    void* p = apObject;
    if (((float*)p)[6] == ((float*)this)[6])
        return true;
    return false;
}

struct FUN_00c60700_Group
{
    unsigned int value00;
    unsigned int value04;
    unsigned int value08;
    unsigned int value0c;
};

struct FUN_00c60700_Data
{
    unsigned char padding[0x18];
    FUN_00c60700_Group group00;
    FUN_00c60700_Group group10;
    FUN_00c60700_Group group20;
    float value30;
    float value34;
    float value38;
    float value3c;
    float value40;
    float value44;
};

struct FUN_00c60700_Class : NiPSysModifierCopy
{
    void FUN_00c60700(NiPSysModifier* dst, CloningProcess& proc);
};

// @fnv 0x00c60700
void FUN_00c60700_Class::FUN_00c60700(NiPSysModifier* dst, CloningProcess& proc)
{
    reinterpret_cast<::NiPSysModifier *>((this))->CopyMemberData(dst, proc);

    ((FUN_00c60700_Data*)dst)->group00 = ((FUN_00c60700_Data*)this)->group00;
    ((FUN_00c60700_Data*)dst)->group10 = ((FUN_00c60700_Data*)this)->group10;
    ((FUN_00c60700_Data*)dst)->group20 = ((FUN_00c60700_Data*)this)->group20;

    ((FUN_00c60700_Data*)dst)->value30 = ((FUN_00c60700_Data*)this)->value30;
    ((FUN_00c60700_Data*)dst)->value34 = ((FUN_00c60700_Data*)this)->value34;
    ((FUN_00c60700_Data*)dst)->value38 = ((FUN_00c60700_Data*)this)->value38;
    ((FUN_00c60700_Data*)dst)->value3c = ((FUN_00c60700_Data*)this)->value3c;
    ((FUN_00c60700_Data*)dst)->value40 = ((FUN_00c60700_Data*)this)->value40;
    ((FUN_00c60700_Data*)dst)->value44 = ((FUN_00c60700_Data*)this)->value44;
}

template <class T> void __cdecl ReadBinaryValue(NiStream& stream, T& value);

struct NiPSysModifierLoadBinary_StandIn
{
};

struct NiColorALoadBinary_StandIn
{
};

struct FUN_00c60850_Class : public NiPSysModifier
{
    void FUN_00c60850(NiStream& stream);
};

// @fnv 0x00c60850
void FUN_00c60850_Class::FUN_00c60850(NiStream& stream)
{
    reinterpret_cast<::NiPSysModifier *>((reinterpret_cast<NiPSysModifierLoadBinary_StandIn*>(this)))->LoadBinary(stream);

    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x48)));
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x4c)));
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x50)));
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x54)));
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x58)));
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x5c)));

    reinterpret_cast<::RgbaColor *>((reinterpret_cast<NiColorALoadBinary_StandIn*>(reinterpret_cast<char*>(this) + 0x18)))->LoadBinary(stream);
    reinterpret_cast<::RgbaColor *>((reinterpret_cast<NiColorALoadBinary_StandIn*>(reinterpret_cast<char*>(this) + 0x28)))->LoadBinary(stream);
    reinterpret_cast<::RgbaColor *>((reinterpret_cast<NiColorALoadBinary_StandIn*>(reinterpret_cast<char*>(this) + 0x38)))->LoadBinary(stream);
}

struct MyIsEqual
{
    bool FUN_00c31830(NiObject*);
};

struct FUN_004a4cc0_shell
{
    bool FUN_004a4cc0(void*);
};

struct FUN_00c60a10_Class
{
    unsigned char m_00[0x48];
    float m_48;
    float m_4c;
    float m_50;
    float m_54;
    float m_58;
    float m_5c;

    bool FUN_00c60a10(NiObject*);
};

// @fnv 0x00c60a10
bool FUN_00c60a10_Class::FUN_00c60a10(NiObject* pObject)
{
    if (!reinterpret_cast<MyIsEqual*>(this)->FUN_00c31830(pObject))
        return false;

    FUN_00c60a10_Class* pOther = reinterpret_cast<FUN_00c60a10_Class*>(pObject);

    if (pOther->m_48 == m_48 && pOther->m_4c == m_4c && pOther->m_50 == m_50 && pOther->m_54 == m_54 &&
        pOther->m_58 == m_58 && pOther->m_5c == m_5c &&
        reinterpret_cast<FUN_004a4cc0_shell*>(&pOther->m_00[24])
            ->FUN_004a4cc0(reinterpret_cast<char*>(&this->m_00[24])) &&
        reinterpret_cast<FUN_004a4cc0_shell*>(&pOther->m_00[40])
            ->FUN_004a4cc0(reinterpret_cast<char*>(&this->m_00[40])) &&
        reinterpret_cast<FUN_004a4cc0_shell*>(&pOther->m_00[56])
            ->FUN_004a4cc0(reinterpret_cast<char*>(&this->m_00[56])))
        return true;

    return false;
}


struct FUN_00c60d10_Class
{
    void* FUN_00c60d10(unsigned int flags);
};

// @fnv 0x00c60d10
void* FUN_00c60d10_Class::FUN_00c60d10(unsigned int flags)
{
    reinterpret_cast<::PositionState *>(this)->FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x60);
    return this;
}

struct A51BF0Base
{
};

struct FUN_00c612b0_Class : NiAVObject, A51BF0Base
{
    unsigned char m_data[19];

    FUN_00c612b0_Class();
};


// Allocates a FUN_00c612b0_Class object, sets its name to DAT_011f49e0, and returns it as an NiAVObject.
// @fnv 0x00c61510
NiAVObject* __cdecl FUN_00c61510()
{
    NiAVObject* object = new FUN_00c612b0_Class;
    ::AssignFixedString((char *)(object), (int)&(::DAT_011f49e0), {});
    return object;
}

class NiBinaryExtraData;
struct CloningProcess;
struct FUN_00a7b330_shell
{
public:
    void FUN_00a7b330(::NiBinaryExtraData *, ::CloningProcess *);
};
struct FUN_00c61830_class
{
    void FUN_00c61830(void* a, void* b);
};
// @fnv 0x00c61830
void FUN_00c61830_class::FUN_00c61830(void* a, void* b)
{
    ((FUN_00a7b330_shell*)this)->FUN_00a7b330((::NiBinaryExtraData *)(a), (::CloningProcess *)(b));
}

struct FUN_00c62390_class
{
};
struct FUN_00c61ba0_class : FUN_00c62390_class
{
    void ForwardToBase(void* a, void* b, void* c);
};
// @fnv 0x00c61ba0
void FUN_00c61ba0_class::ForwardToBase(void* apUnused, void* apArg1, void* apArg2)
{
    reinterpret_cast<::FUN_00c62390_cls *>(this)->FUN_00c62390(apArg1, apArg2);
}

namespace fnv_00c61bc0 {
extern unsigned int _data_011c16bc;

struct A51BF0Base
{
};

struct FUN_00c61bc0_class
{
    void FUN_00c61c50(FUN_00c61b10* object, int arg);
    FUN_00c61b10* CreateObject(int arg);
};

// Allocates a new FUN_00c61b10, initialises it via FUN_00c61c50 with arg, and returns the object.
// @fnv 0x00c61bc0
FUN_00c61b10* FUN_00c61bc0_class::CreateObject(int arg)
{
    FUN_00c61b10* object = new FUN_00c61b10;
    FUN_00c61c50(object, arg);
    return object;
}
}  // namespace fnv_00c61bc0

template <class T> void ReadBinaryValue(NiStream&, T&);
struct NiPSysModifierStub
{
    virtual void LoadBinary(NiStream&);
};
struct FUN_00c63900_class : NiPSysModifierStub
{
    void LoadModifierData(NiStream& stream);
};
// @fnv 0x00c63900
void FUN_00c63900_class::LoadModifierData(NiStream& stream)
{
    reinterpret_cast<::NiPSysModifier *>(this)->LoadBinary(stream);
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x20)));
}


struct FUN_00c31750_Class
{
};

struct FUN_00c63a70_Class
{
    void* FUN_00c63a70(unsigned int flags);
};

// Calls FUN_00c31750 on this, deletes this with size 0x3c when flags has bit 1 set, and returns this.
// @fnv 0x00c63a70
void* FUN_00c63a70_Class::FUN_00c63a70(unsigned int flags)
{
    reinterpret_cast<::PositionState *>((((FUN_00c31750_Class*)this)))->FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x3c);
    return this;
}

namespace fnv_00c64060 {
extern unsigned int _data_011c16bc;

struct A51BF0Base
{
};

struct FUN_00c63ab0 : A51BF0Base
{
    void* m_pData;
    char m_auiShapeKeys[0x3c];

    FUN_00c63ab0(int value);
};

FUN_00c63ab0::FUN_00c63ab0(int value)
{
    m_pData = 0;
}

struct BSDecalPlacementVectorExtraData_StandIn
{
    void* FUN_00c64060(int value);
};

// Allocates a FUN_00c63ab0 with value 0, passes it to FUN_00c640f0 with value, and returns the new object.
// @fnv 0x00c64060
void* BSDecalPlacementVectorExtraData_StandIn::FUN_00c64060(int value)
{
    FUN_00c63ab0* pObject = new FUN_00c63ab0(0);
    reinterpret_cast<::ObjX *>((this))->FUN_00c640f0((::ObjX *)(pObject), value);
    return pObject;
}
}  // namespace fnv_00c64060

struct FUN_00c64500_Class : FUN_00c61490_Class
{
    bool FUN_00c64500(const void* arg);
};

// Returns the negation of FUN_00a89ae0(arg).
// @fnv 0x00c64500
bool FUN_00c64500_Class::FUN_00c64500(const void* arg)
{
    return !reinterpret_cast<::FUN_00a89ae0_shell *>(this)->FUN_00a89ae0((int)(arg));
}

namespace fnv_00c64530 {
struct A51BF0Base : public NiAVObject
{
    char m_ucUnknownByte[0x40];

};

struct FUN_00c63ab0 : public A51BF0Base
{
    FUN_00c63ab0(int a);
};


// Allocates a FUN_00c63ab0 with argument 0, sets its name to DAT_011f49e0, and returns it.
// @fnv 0x00c64530
void* CreateNamedNode()
{
    FUN_00c63ab0* result = new FUN_00c63ab0(0);
    ::AssignFixedString((char *)(result), (int)&(::DAT_011f49e0), {});
    return result;
}
}  // namespace fnv_00c64530

struct A46BB0Object
{
};


struct FUN_00c64980_Class : A46BB0Object
{
    bool FUN_00c64980(A46BB0Object* arg);
};

// Returns true when IsEqual(arg) holds and both objects' string pointers at offset 8 are non-null and __stricmp-equal.
// @fnv 0x00c64980
bool FUN_00c64980_Class::FUN_00c64980(A46BB0Object* apOther)
{
    if (reinterpret_cast<::A5d470Class *>((this))->IsSameAs((::A5d470Object *)(apOther)))
    {
        A46BB0Object* p = apOther;
        if (*(void**)((char*)this + 8) != 0)
        {
            void* a = *(void**)((char*)p + 8);
            if (a != 0)
            {
                void* b = *(void**)((char*)p + 8);
                void* c = *(void**)((char*)this + 8);
                return fnv::crt::stricmp((const char*)c, (const char*)b) == 0;
            }
        }
    }
    return false;
}

struct FUN_0043ba10_shell
{
public:
    ::FUN_0043ba10_shell *FUN_0043ba10(::FUN_0043ba10_shell *);
};
struct FUN_00c64dc0_Class
{
    char m_iWordAt00;
    char m_cByteAtOffset1;
    char m_cByteAtOffset2;
    char m_cByteAtOffset3;
    FUN_0043ba10_shell m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_0043ba10_shell* FUN_00c64dc0(unsigned int a);
};
// @fnv 0x00c64dc0
FUN_0043ba10_shell* FUN_00c64dc0_Class::FUN_00c64dc0(unsigned int a)
{
    int v0;
    int v1;
    int v2;
    return reinterpret_cast<::FUN_0043ba10_shell *>(&(m_iWordAt04))->FUN_0043ba10((::FUN_0043ba10_shell *)(a));
}


struct FUN_00c64e70_Class
{
    void* FUN_00c65650(unsigned int flags);
};

// Calls FUN_00c64e70, then frees this with operator delete when flags has bit 1 set, and returns this.
// @fnv 0x00c65650
void* FUN_00c64e70_Class::FUN_00c65650(unsigned int flags)
{
    reinterpret_cast<::FUN_00c64e70 *>((this))->FUN_00c64e70::~FUN_00c64e70();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject_b9118
{
    char m00[0x60];
    SpawnedObject_b9118();
};

// Allocates and constructs a SpawnedObject_b9118 via its custom operator new and returns the pointer.
// @fnv 0x00c607d0
SpawnedObject_b9118* FUN_00c607d0()
{
    SpawnedObject_b9118* result = new SpawnedObject_b9118();
    return result;
}

class C61330Base
{
  public:
    C61330Base(int iA, int iB);
    virtual ~C61330Base();

    int unk04;
};

class FUN_00c61330 : public C61330Base
{
  public:

    FUN_00c61330(int iA, int iB);
    virtual ~FUN_00c61330();
};

// Constructs the object by forwarding iA and iB to the C61330Base constructor, then calls Initialize().
// @fnv 0x00c61330
FUN_00c61330::FUN_00c61330(int iA, int iB) : C61330Base(iA, iB)
{
    reinterpret_cast<::NiAVObject *>(this)->FUN_00c61610();
}

struct FUN_00c61c50_sub
{
    void FUN_00c628c0(unsigned int n);
};
struct FUN_00c61c50_cls
{
    unsigned int pad0[0x18];
    unsigned int* m_60;
    unsigned short pad1[1];
    unsigned short m_66;
    void FUN_00c61c50(unsigned int x, unsigned int y);
};
// @fnv 0x00c61c50
void FUN_00c61c50_cls::FUN_00c61c50(unsigned int x, unsigned int y)
{
    unsigned int pad[0xf];
    reinterpret_cast<::NiPSysBoxEmitterWrapper *>(this)->FUN_00c31b10((::NiPSysModifier *)(x), (*(::CloningProcess *)(y)));
    unsigned int n = m_66;
    if (n != 0)
    {
        ((FUN_00c61c50_sub*)(x + 0x5c))->FUN_00c628c0(n);
        while (n-- != 0)
        {
            reinterpret_cast<::SetAtArray *>((((FUN_00c61c50_sub*)(x + 0x5c))))->FUN_00c62b90(n, (*(const ::NiPointer< ::SetAtRefObject> *)(&m_60[n])));
        }
    }
}

struct FUN_00c62140_Elem;
struct FUN_00c62140_Item;

struct FUN_00c62140_Val
{
    float m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
};

struct FUN_00c62140_Item
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
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
    FUN_00c62140_Elem** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct FUN_00c62140_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual FUN_00c62140_Item* v03();
};

struct FUN_00c62140_Pad
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_00c62140_Pad5
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct FUN_00c62140_Sub
{
};

struct FUN_00c62140_cls
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
    FUN_00c62140_Obj* m_54;
    int unk58;
    FUN_00c62140_Sub m_5c;

    void FUN_00c62140();
};
// @fnv 0x00c61f30
void NiObject::FUN_00c61f30(NiStream& stream)
{
    reinterpret_cast<::FUN_00c62140_cls *>(this)->FUN_00c62140();
    ::FUN_00a89af0((int)this);
}
// @fnv 0x00c627e0
void FUN_00c627e0_Class::FUN_00c627e0(void* pValue)
{
    *(void**)((char*)this + 0x54) = pValue;
    reinterpret_cast<::FUN_00c62140_cls *>(this)->FUN_00c62140();
}

// @fnv 0x00c62140
void FUN_00c62140_cls::FUN_00c62140()
{
    reinterpret_cast<::S00c62f40_Array *>(&(m_5c))->FUN_00c62f40();
    FUN_00c62140_Obj* pad;
    pad = m_54;
    FUN_00c62140_Item* pItem = (0 != pad) ? pad->v03() : 0;
    if (!!pItem)
    {
        FUN_00c62140_Val val;
        val.m_00 = 0.0f;
        val.m_04 = 0;
        val.m_05 = 0;
        val.m_06 = 0;
        val.m_07 = 0;
        val.m_08 = 0;
        reinterpret_cast<::FUN_00a59c60_cls *>((pItem))->FUN_00a59c60((int)(&val));
        unsigned int slot = pItem->m_a6;
        while (slot-- != 0)
        {
            FUN_00c62140_Pad5 objTmp;
            FUN_00c62140_Elem** i;
            i = &pItem->m_a0[slot];
            FUN_00c62140_Elem* e = *i;
            reinterpret_cast<::Collector62 *>(this)->FUN_00c62200((::AVObj62 *)(e));
        }
    }
}

struct S_00c62cc0_Class
{
    void* unk0;
    void* unk4;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short unk_c;
    unsigned short m_usTrailingValue;

    void FUN_00c628c0(unsigned int arg);
    unsigned int FUN_00c62cc0(unsigned int arg);
};

struct S_00c62cc0_Locals
{
    unsigned int value;
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
};

// @fnv 0x00c62cc0
unsigned int S_00c62cc0_Class::FUN_00c62cc0(unsigned int uiValue)
{
    S_00c62cc0_Locals locals;
    locals.value = m_kPointA;

    if (locals.value >= m_8)
    {
        FUN_00c628c0(m_usTrailingValue + locals.value);
    }

    reinterpret_cast<::SetAtArray *>(this)->FUN_00c62b90(locals.value, (*(const ::NiPointer< ::SetAtRefObject> *)(uiValue)));
    return locals.value;
}

// FUN_00c634b0: thiscall (this in ecx), 2 stack params (a1 pointer, unsigned short index).

class XVec12
{
  public:
    float m_00;
    float m_04;
    float m_08;
};

class XSub30
{
  public:
    unsigned int unk00;
};

class XItem12
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

class XItem28
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
};

class XObj70
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    XItem12* m_20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58,
        unk5c, unk60, unk64, unk68, unk6c;
    XItem28* m_70;
};

class FUN_00c634b0_cls
{
  public:
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14;
    float m_18;
    unsigned int m_1c;
    unsigned int m_20, m_24, m_28, m_2c;
    XSub30 m_30;
    void FUN_00c634b0(XObj70* a1, unsigned short idx);
};

// @fnv 0x00c634b0
void FUN_00c634b0_cls::FUN_00c634b0(XObj70* pObj, unsigned short usIndex)
{
    XItem28* p = pObj->m_70;
    p = p + usIndex;
    reinterpret_cast<::FUN_0063c8a0_shell *>((p))->FUN_0063c8a0(&m_30);
    XVec12 qq;
    XItem12* mm = pObj->m_20;
    XVec12 xx;
    reinterpret_cast<::NiPoint3 *>(&(mm[usIndex]))->Subtract((*(const ::NiPoint3 *)(((unsigned int)(reinterpret_cast<::FUN_0045bb20_cls *>(&(m_30))->ApplyScaled((::FUN_0045bb20_target *)(::XVec12 *)(&xx), {}))))));
}

struct NiPoint3_c
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
extern NiPoint3_c NiPoint3_ZERO;

struct FUN_00c63780_c
{
    int pad[9];
    NiPoint3_c v;
    void ResetVector();
};

// Sets the vector member v to NiPoint3_ZERO.
// @fnv 0x00c63780
void FUN_00c63780_c::ResetVector()
{
    v = (*reinterpret_cast<::NiPoint3_c *>((void *)&::NiPoint3::ZERO));
}

namespace fnv_00c637b0 {
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
struct ParticleVector3
{
    float x, y, z;
};
struct ParticlePositionClone : FUN_00c63330
{
    unsigned int referenceCount;
    const char* name;
    unsigned int order;
    void* targetSystem;
    bool active;
    ParticleVector3 position;
    ParticleVector3 velocity;
    ParticleVector3 previousPosition;
    float lastUpdateTime;

};
struct FUN_00c637b0_Class : FUN_00c63840_Class
{
    ParticlePositionClone* CreateParticlePositionClone(CloningProcess* process);
};
// Allocates a ParticlePositionClone, initialises it via CopyModifierWithValue with the given process, and returns it.
// @fnv 0x00c637b0
ParticlePositionClone* FUN_00c637b0_Class::CreateParticlePositionClone(CloningProcess* process)
{
    ParticlePositionClone* clone = new ParticlePositionClone();
    CopyModifierWithValue(reinterpret_cast<NiPSysModifier*>(clone), process);
    return clone;
}
}  // namespace fnv_00c637b0

void* __cdecl FUN_00aa13e0(unsigned int size);
struct PositionModifierObject_b9439
{
    char m00[0x3c];
    PositionModifierObject_b9439();
};
// Allocates and constructs a PositionModifierObject_b9439 via its custom operator new and returns the pointer.
// @fnv 0x00c63880
PositionModifierObject_b9439* CreatePositionModifierObject()
{
    return new PositionModifierObject_b9439();
}

struct Pad32
{
    unsigned int a0, a1, a2, a3, a4, a5, a6, a7;
};

struct ArgObj
{
};

struct FUN_00c63a00_cls
{
    void FUN_00c63a00(ArgObj* a1);
};


// @fnv 0x00c63a00
void FUN_00c63a00_cls::FUN_00c63a00(ArgObj* a1)
{
    unsigned int r1;
    unsigned int r2;
    unsigned int g;
    Pad32 pad;
    reinterpret_cast<::FUN_00c319e0_cls *>(this)->FUN_00c319e0((::StrArr *)(a1));
    g = *(unsigned int*)&::g_012043c8;
    r1 = ((unsigned int)(::FUN_00a7d330((const char *)(g))));
    reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((int)(&r1));
    r2 = ((unsigned int)(::FUN_00a7d550("Damping", *(float*)((char*)this + 0x20))));
    reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((int)(&r2));
}

struct S_00c643d0_Foo
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    unsigned short m_uiItemCount;
    void* m_entries[16];

    void FUN_00c643d0(int arg);
};


// @fnv 0x00c643d0
void S_00c643d0_Foo::FUN_00c643d0(int arg)
{
    reinterpret_cast<::fnv_00a9a4e0::Cls_00a9a4e0 *>((this))->FUN_00a9a4e0((*(::fnv_00a9a4e0::NiStream *)(arg)));

    ::fnv_00a303a0::FUN_00a303a0((::fnv_00a303a0::Stream *)(arg), &this->m_uiItemCount);

    for (int i = 0; i < this->m_uiItemCount; ++i)
    {
        ::fnv_00a303a0::FUN_00a303a0((::fnv_00a303a0::Stream *)(arg), this->m_entries[i]);

        int count2 = *reinterpret_cast<unsigned short*>(this->m_entries[i]);
        void* count = reinterpret_cast<char*>(this->m_entries[i]) + 4;

        ::FUN_00a417b0((void *)(arg), count, count2 * 3);

        int data = *reinterpret_cast<unsigned short*>(this->m_entries[i]);
        void* pDataB = reinterpret_cast<char*>(this->m_entries[i]) + 0x64;

        ::FUN_00a417b0((void *)(arg), pDataB, data * 3);
    }
}

class FUN_00c64b90_target;

class FUN_00c64b90_item
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_18;
};

class FUN_00c64b90_target
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30(unsigned int value);
};

class FUN_00c64b90_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00c64b90_item** m_0c;
    int unk10;
    unsigned short m_14;
    void FUN_00c64b90(FUN_00c64b90_target* a1);
};


// @fnv 0x00c64b90
void FUN_00c64b90_cls::FUN_00c64b90(FUN_00c64b90_target* apTarget)
{
    unsigned int count;
    unsigned int i;
    FUN_00c64b90_item* item3;
    unsigned int v2;
    unsigned int bytes;
    ::FUN_00a89af0((int)this);
    count = m_14;
    bytes = count * 2;
    ::FUN_0044adf0((::MiddleHighProcess *)(apTarget), (int)(&bytes));
    for (i = 0; i < count; i++)
    {
        item3 = m_0c[i];
        if (item3 != 0)
        {
            v2 = item3->m_18;
            apTarget->v30(v2);
            apTarget->v30((unsigned int)item3);
        }
    }
}

struct FUN_00c64da0_cls
{
    int unk00;
    void FUN_00c64da0(int a);
};

// @fnv 0x00c64da0
void FUN_00c64da0_cls::FUN_00c64da0(int a)
{
    int unkLoc0;
    int unkLoc1;
    int unkLoc2;
    reinterpret_cast<::FUN_0043ba10_shell *>((this))->FUN_0043ba10((::FUN_0043ba10_shell *)(a));
}

struct DispatchStub_c64
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void** m10;
    int unk14;
    unsigned short m18;
    void DispatchToItems(int a8, int cc);
};
struct ItemCallee_c64
{
};

// Calls FUN_00a7b330 with a8 and cc, then for each of m18 entries in m10 calls FUN_00c65490 on the item and item+4.
// @fnv 0x00c64fd0
void DispatchStub_c64::DispatchToItems(int pTarget, int cc)
{
    reinterpret_cast<FUN_00a7b330_shell*>(this)->FUN_00a7b330((::NiBinaryExtraData *)(void *)((void*)pTarget), (::CloningProcess *)(void *)((void*)cc));
    unsigned int count = m18;
    for (unsigned int i = 0; i < count; i++)
    {
        int item = (int)m10[i];
        reinterpret_cast<::fnv_00c65490::C65490_Owner *>((reinterpret_cast<ItemCallee_c64*>(pTarget)))->FUN_00c65490(item, item + 4);
    }
}

struct FUN_00c65180_VTable
{
    virtual void FUN_00c65180_v0();
    virtual void FUN_00c65180_v1();
    virtual void FUN_00c65180_v2();
    virtual void FUN_00c65180_v3();
    virtual void FUN_00c65180_v4();
    virtual void FUN_00c65180_v5();
    virtual void FUN_00c65180_v6();
    virtual void FUN_00c65180_v7();
    virtual void FUN_00c65180_v8(void* p);
};

struct FUN_00c65180_Class
{

    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void** m_10;
    int m_14;
    unsigned short m_18;

    unsigned char VisitEntries(FUN_00c65180_VTable* p);
};

// Calls FUN_00a7b290; if it succeeds, iterates m_10 up to m_18 times, passing each item and item+4 to the vtable's FUN_00c65180_v8, and returns the result.
// @fnv 0x00c65180
unsigned char FUN_00c65180_Class::VisitEntries(FUN_00c65180_VTable* p)
{
    unsigned char result = ((unsigned char)(reinterpret_cast<::MyOwner *>(this)->FUN_00a7b290((*(::NiStream *)(p)))));

    if (result)
    {
        unsigned int count = m_18;

        for (unsigned int i = 0; i < count; ++i)
        {
            void* item = m_10[i];

            p->FUN_00c65180_v8(item);
            p->FUN_00c65180_v8(static_cast<char*>(item) + 4);
        }
    }

    return result;
}

struct MyColorA
{
    float r;
    float g;
    float b;
    float a;
};

struct Point3ParameterData
{
    float unk00;
    float unk04;
    float unk08;
    float m_fXValue;
    float m_fYValue;
    float unk14;
    float unk18;
};

struct NiPSysData
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
    MyColorA* m_pkParticleColors;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned short m_usNumParticles;
    short pad52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Point3ParameterData* m_pkParticleInfo;
};

struct BSPSysSimpleColorModifierCand
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MyColorA m_kColor1;
    MyColorA m_kColor2;
    MyColorA m_kColor3;
    float m_fFadeInPercent;
    float m_fFadeOutPercent;
    float m_fColor1End;
    float m_fColor2Start;
    float m_fColor2End;
    float m_fColor3Start;

    void UpdateParticleColors(float fTime, NiPSysData* pkData);
};

// For each particle, lerps RGB between m_kColor1/2/3 by normalized age and sets alpha from the fade-in/out percentages.
// @fnv 0x00c602e0
void BSPSysSimpleColorModifierCand::UpdateParticleColors(float fTime, NiPSysData* pkData)
{
    unsigned short usNumParticlesTmp;
    MyColorA* pkColors8;
    float fRangeVal;
    float fRange4;
    unsigned short us4;
    float fNormAge3;
    Point3ParameterData* pkInfo3;
    float kFLerp1;
    float fLerp4;
    float fFadeOutLerpA;
    float fFadeInLerp3;
    Point3ParameterData* pkParticleInfo3;

    pkColors8 = pkData->m_pkParticleColors;
    if (!pkColors8)
        return;

    fRange4 = m_fColor2Start - m_fColor1End;
    fRangeVal = m_fColor3Start - m_fColor2End;

    usNumParticlesTmp = pkData->m_usNumParticles;
    for (us4 = 0; us4 < usNumParticlesTmp; us4++)
    {
        pkParticleInfo3 = pkData->m_pkParticleInfo;
        pkInfo3 = &pkParticleInfo3[us4];
        fNormAge3 = pkInfo3->m_fXValue / pkInfo3->m_fYValue;

        if (fRange4 != 0.0 && fNormAge3 < m_fColor2Start)
        {
            if (fNormAge3 < m_fColor1End)
            {
                pkColors8[us4].r = m_kColor1.r;
                pkColors8[us4].g = m_kColor1.g;
                pkColors8[us4].b = m_kColor1.b;
            }
            else
            {
                kFLerp1 = (fNormAge3 - m_fColor1End) / fRange4;
                pkColors8[us4].r = m_kColor1.r + (m_kColor2.r - m_kColor1.r) * kFLerp1;
                pkColors8[us4].g = m_kColor1.g + (m_kColor2.g - m_kColor1.g) * kFLerp1;
                pkColors8[us4].b = m_kColor1.b + (m_kColor2.b - m_kColor1.b) * kFLerp1;
            }
        }
        else if (fRangeVal != 0.0 && fNormAge3 > m_fColor2End)
        {
            if (fNormAge3 > m_fColor3Start)
            {
                pkColors8[us4].r = m_kColor3.r;
                pkColors8[us4].g = m_kColor3.g;
                pkColors8[us4].b = m_kColor3.b;
            }
            else
            {
                fLerp4 = (fNormAge3 - m_fColor2End) / fRangeVal;
                pkColors8[us4].r = m_kColor2.r + (m_kColor3.r - m_kColor2.r) * fLerp4;
                pkColors8[us4].g = m_kColor2.g + (m_kColor3.g - m_kColor2.g) * fLerp4;
                pkColors8[us4].b = m_kColor2.b + (m_kColor3.b - m_kColor2.b) * fLerp4;
            }
        }
        else
        {
            pkColors8[us4].r = m_kColor2.r;
            pkColors8[us4].g = m_kColor2.g;
            pkColors8[us4].b = m_kColor2.b;
        }

        if (m_fFadeOutPercent != 0.0 && fNormAge3 > m_fFadeOutPercent)
        {
            fFadeOutLerpA = (fNormAge3 - m_fFadeOutPercent) / (1.0f - m_fFadeOutPercent);
            pkColors8[us4].a = m_kColor2.a + (m_kColor3.a - m_kColor2.a) * fFadeOutLerpA;
        }
        else if (m_fFadeInPercent != 0.0 && fNormAge3 < m_fFadeInPercent)
        {
            fFadeInLerp3 = fNormAge3 / (float)(m_fFadeInPercent);
            pkColors8[us4].a = m_kColor1.a + (m_kColor2.a - m_kColor1.a) * fFadeInLerp3;
        }
        else
        {
            pkColors8[us4].a = m_kColor2.a;
        }
    }
}

class NiObjectC60
{
  public:
    NiObjectC60();
    virtual ~NiObjectC60();


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
};

class NiCloningProcessC60;

class NiOwnerC60
{
  public:
    NiObjectC60* CloneObject(NiCloningProcessC60& kCloning);
};

// @fnv 0x00c60670
NiObjectC60* NiOwnerC60::CloneObject(NiCloningProcessC60& kCloning)
{
    NiObjectC60* pkClone = new NiObjectC60;
    reinterpret_cast<::FUN_00c60700_Class *>(this)->FUN_00c60700((::NiPSysModifier *)(pkClone), (::CloningProcess &)(kCloning));
    return pkClone;
}

struct NiTPrimitiveArray_unsigned_int_
{
};
struct FUN_00c615a0_class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0c;
    void FUN_00a99b20(NiTPrimitiveArray_unsigned_int_* values);
    void AppendGlobalAndFormatValues(NiTPrimitiveArray_unsigned_int_* values);
};
struct GlobalObject_00a7b610;

struct Unused20
{
    int a, b, c, d, e, f, g, h;
};
// Calls FUN_00a99b20, then appends the result of FUN_00a7d330 on g_012043a4 and of FUN_00a7d510(str_0109df4c, unk0c) to the values array.
// @fnv 0x00c615a0
void FUN_00c615a0_class::AppendGlobalAndFormatValues(NiTPrimitiveArray_unsigned_int_* values)
{
    FUN_00a99b20(values);
    void* global_ptr = (*reinterpret_cast<void * *>(&::g_012043a4));
    unsigned int first = (unsigned int)::FUN_00a7d330((const char *)(::GlobalObject_00a7b610 *)((GlobalObject_00a7b610*)global_ptr));
    reinterpret_cast<::S_0060ba10 *>((values))->FUN_0096a610((int)&(first));
    unsigned int second = (unsigned int)FUN_00a7d510(str_0109df4c, unk0c);
    reinterpret_cast<::S_0060ba10 *>((values))->FUN_0096a610((int)&(second));
    Unused20 tmp;
}

struct C639a0Cls : MyIsEqual
{
    char pad[0x20];
    float m_20;
    bool FUN_00c639a0(NiObject* pObject);
};
// Compares this object with pObject: first via FUN_00c31830, then checks that m_20 matches.
// @fnv 0x00c639a0
bool C639a0Cls::FUN_00c639a0(NiObject* pObject)
{
    bool bEqual = FUN_00c31830(pObject);
    if (bEqual)
    {
        C639a0Cls* pOther = (C639a0Cls*)pObject;
        bEqual = pOther->m_20 == m_20;
    }
    return bEqual;
}

struct FUN_00c61fc0_Item
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_0096a610_Target
{
};

struct FUN_00c61fc0_Pad
{
    int a, b, c, d;
};

struct FUN_00c61fc0_cls
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
    FUN_00c61fc0_Item** m_ppItems;
    unsigned short unk64;
    unsigned short m_iArrayLength;
    void Serialize(void* a1);
};

extern int DAT_01063e84;

// After FUN_00c31db0, passes FUN_00a7d330's value, an "ArrayType" string for unk58, and each item's unk08 (last to first) to a1->FUN_0096a610.
// @fnv 0x00c61fc0
void FUN_00c61fc0_cls::Serialize(void* apTarget)
{
    char* ib;
    FUN_00c61fc0_Item** b;
    int mid;
    int r;
    unsigned long ptr2;
    unsigned int ra;
    int oa;
    int v1;
    long cur;
    FUN_00c61fc0_Item* x;
    long qa;
    int ta;
    void* mb;
    int xa;
    long gb;
    reinterpret_cast<::FUN_00c31db0_cls *>(this)->FUN_00c31db0((::NameArray_b9457 *)(apTarget));
    v1 = *(int*)&::g_012043b0;
    mb = ((void *)(::FUN_00a7d330((const char *)(v1))));
    reinterpret_cast<::S_0060ba10 *>((((FUN_0096a610_Target*)apTarget)))->FUN_0096a610((int)(&mb));
    xa = unk58;
    ib = reinterpret_cast<::FUN_00c62090_Class *>(this)->BuildAttachTypeString("ArrayType", xa);
    reinterpret_cast<::S_0060ba10 *>((((FUN_0096a610_Target*)apTarget)))->FUN_0096a610((int)(&ib));
    mid = m_iArrayLength;
    while (0 != mid--)
    {
        b = &m_ppItems[mid];
        x = *b;
        if (!!x)
        {
            ra = x->unk08;
            cur = ((int)(::fnv_00a7d5e0::FUN_00a7d5e0((const char *)(int *)(&DAT_01063e84), (const char *)(ra))));
            reinterpret_cast<::S_0060ba10 *>((((FUN_0096a610_Target*)apTarget)))->FUN_0096a610((int)(&cur));
        }
    }
}

struct StrArr;


class Base00c319e0
{
  public:
    virtual ~Base00c319e0();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();

};

class Mod600 : public Base00c319e0
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_fValue;

    void FUN_00c60050(StrArr* pkStrings);
    virtual ~Mod600();
};

struct LocalStackSpace
{
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
};

// Calls base FUN_00c319e0, then adds a name string and a string formatted from fUpdateDeltaTime and m_fValue to pkStrings.
// @fnv 0x00c60050
void Mod600::FUN_00c60050(StrArr* pkStrings)
{
    reinterpret_cast<::FUN_00c319e0_cls *>(this)->FUN_00c319e0(pkStrings);

    GlobalObject_00a7b610* obj = (GlobalObject_00a7b610*)(*reinterpret_cast<void * *>(&::g_01204388));
    unsigned int uiName = (unsigned int)::FUN_00a7d330((const char *)(obj));
    reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)pkStrings)))->FUN_0096a610((int)&(uiName));

    unsigned int uiValue = ((unsigned int)(::FUN_00a7d550("fUpdateDeltaTime", m_fValue)));
    reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)pkStrings)))->FUN_0096a610((int)&(uiValue));

    {
        LocalStackSpace localSpace;
        if (localSpace.field0)
        {
        }
    }
}

Base00c319e0::~Base00c319e0()
{}
void Base00c319e0::vf04()
{}
void Base00c319e0::vf08()
{}
void Base00c319e0::vf0C()
{}
void Base00c319e0::vf10()
{}
void Base00c319e0::vf14()
{}
void Base00c319e0::vf18()
{}

Mod600::~Mod600()
{}

struct SpawnHeap_cls
{
};

extern "C" void* DAT_0109b220;
extern "C" void(* DAT_00fdf1c4)(void*);

// If DAT_012043a0 is set, calls DAT_00fdf1c4 on its header unless it holds DAT_0109b220, frees it via FUN_00aa4060, then sets DAT_012043a0 to 0.
// @fnv 0x00c61760
void FUN_00c61760()
{
    NiFixedString* tmp = DAT_012043a0;
    NiFixedString* p = tmp;
    NiFixedString* result;
    unsigned int hdr;

    if (p != 0)
    {
        if (*(void**)p == DAT_0109b220)
        {
        }
        else
        {
            hdr = *(unsigned int*)p - 8;
            DAT_00fdf1c4((void*)hdr);
        }

        if ((1, 1) & 1)
        {
            reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<SpawnHeap_cls*>(&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(p);
        }

        result = p;
    }
    else
    {
        result = 0;
    }

    DAT_012043a0 = 0;
}

namespace fnv_00c61990 {
extern "C" int DAT_0109b220;

struct S61990Obj
{
    int vt;
};

// Takes the global at DAT_012043ac, decrements the count at vt-8 unless vt equals DAT_0109b220, deallocates the object, and clears the global.
// @fnv 0x00c61990
void __cdecl FUN_00c61990()
{
    S61990Obj* ptr = (S61990Obj*)DAT_012043ac;
    S61990Obj* mgr = ptr;
    S61990Obj* beta;
    volatile long* temp;
    if (mgr != 0)
    {
        if (mgr->vt == DAT_0109b220)
        {
        }
        else
        {
            temp = (volatile long*)(mgr->vt - 8);
            InterlockedDecrement(temp);
        }
        if ((1, 1) & 1)
        {
            reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(mgr);
        }
        beta = mgr;
    }
    else
    {
        beta = 0;
    }
    DAT_012043ac = 0;
}
}  // namespace fnv_00c61990

struct Pt3c64640
{
    float x;
    float y;
    float z;
    Pt3c64640()
    {}
};


struct Box0c64640
{
    unsigned short unk00;
    Pt3c64640 unk04[8];
    Pt3c64640 unk64[8];
    Box0c64640* FUN_00c64640();
};

// Sets unk00 to 0 and fills the unk04 and unk64 arrays with the global DAT_011f426c value, then returns this.
// @fnv 0x00c64640
Box0c64640* Box0c64640::FUN_00c64640()
{
    int i;
    {
        int n = 8;
        Pt3c64640* p = unk04;
        while (--n >= 0)
            p++;
    }
    {
        int m = 8;
        Pt3c64640* q = unk64;
        while (--m >= 0)
            q++;
    }
    unk00 = 0;
    for (i = 0; i < 8; i++)
    {
        unk04[i] = (*reinterpret_cast<::Pt3c64640 *>((void *)&::NiPoint3::ZERO));
        unk64[i] = (*reinterpret_cast<::Pt3c64640 *>((void *)&::NiPoint3::ZERO));
    }
    return this;
}

struct S_00c648a0_Map
{
};

struct S_00c648a0_Stream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28(void* apObject);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    S_00c648a0_Map* unk5c4;
};

struct S_00c648a0_Base
{
    int unk00;
    int unk04;
    void* unk08;
};

struct S_00c648a0 : S_00c648a0_Base
{
    void FUN_00c648a0(S_00c648a0_Stream* apStream);
};

// Calls ReadGroup, reads unk08 from the stream, looks it up in the stream's map, and passes any found object to apStream->v28.
// @fnv 0x00c648a0
void S_00c648a0::FUN_00c648a0(S_00c648a0_Stream* apStream)
{
    reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)(apStream));
    reinterpret_cast<::FUN_00a64ce0_shell *>((apStream))->FUN_00a64ce0((char **)(void **)(&unk08));

    void* pObject;
    {
        S_00c648a0_Stream* pStream = apStream;
        unsigned int uiLinkID = (unsigned int)unk08;
        void* pFound = 0;
        if (pStream->unk5c4 && uiLinkID)
            reinterpret_cast<::fnv_00853130::NiTMapBase *>((pStream->unk5c4))->FUN_00853130(uiLinkID, (*(::fnv_00853130::CombatThreatRecord * *)(&pFound)));
        pObject = pFound;
    }
    if (pObject)
        apStream->v28(pObject);
    {
        int ReportDiagnostic;
        int unused1;
    }
}

class BSFaceGenMorphData
{
  public:
};

struct FUN_00c64de0 : NiAVObject, BSFaceGenMorphData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00c64de0();
};

// Allocates a FUN_00c64de0 object, sets its name to DAT_011f49e0, and returns the new pointer.
// @fnv 0x00c652c0
FUN_00c64de0* __cdecl FUN_00c652c0()
{
    FUN_00c64de0* object = new FUN_00c64de0;
    ::AssignFixedString((char *)(object), (int)&(::DAT_011f49e0), {});
    return object;
}


class NiViewerStringsArray
{
  public:
    unsigned int Add(char* const& item);
};


class AttachPointName
{
  public:
    const char* m_kHandle;
    operator const char*() const
    {
        return m_kHandle;
    }
};

class AttachPoint
{
  public:
    AttachPointName m_kParent;
    AttachPointName m_kNode;
};

class NiExtraDataBase
{
  public:
};

class BSAttachPoints : public NiExtraDataBase
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AttachPoint** m_ppkPoints;
    int unk14;
    unsigned short m_usElementCount;
    void FUN_00c65350(NiViewerStringsArray* pkStrings);
};

struct FillPad3
{
    int unk00;
    int unk04;
    int unk08;
};

struct FillPad4
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct FillPad5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

// Appends the RTTI name and one formatted string per attach point (index, parent, node) to pkStrings.
// @fnv 0x00c65350
void BSAttachPoints::FUN_00c65350(NiViewerStringsArray* pkStrings)
{
    char acBuffer[260];
    unsigned int i;
    unsigned int kUiCount;
    AttachPoint* pkPoint;
    const char* pcParent;
    const char* pcNode2;
    reinterpret_cast<::ExtraDataStrings *>(this)->FUN_00a7b580((::StrArr *)(pkStrings));
    {
        unsigned int unk0;
        const char* pcRTTIName = (const char*)DAT_012043f0;
        char* unk2;
        char* pcViewerStr = ::FUN_00a7d330(pcRTTIName);
        reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(pcViewerStr));
        kUiCount = m_usElementCount;
        for (i = 0; i < kUiCount; i++)
        {
            {
                FillPad4 nc;
            }
            pkPoint = m_ppkPoints[i];
            const char* nb6 = pkPoint->m_kParent.m_kHandle;
            pcParent = nb6;
            const char* hNode = pkPoint->m_kNode.m_kHandle;
            pcNode2 = hNode;
            ::FUN_00406d00(acBuffer, 260, "%d: %s - %s", i, pcParent, pcNode2);
            unk2 = acBuffer;
            reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((int)&(unk2));
        }
    }
}

extern "C" void* VTABLE_010c38ac;
struct Vector3i
{
    int x;
    int y;
    int z;
};
struct FUN_00c63ab0
{
    void* vtable;
    int field04;
    int field08;
    int parameter0c;
    unsigned short count10;
    unsigned short status12;
    unsigned int entries[8];
    Vector3i bounds;
    FUN_00c63ab0(int parameter);
};
// @fnv 0x00c63ab0
FUN_00c63ab0::FUN_00c63ab0(int parameter)
{
    reinterpret_cast<::ExtraDataObject *>(this)->FUN_00a7b2e0();
    vtable = &(*reinterpret_cast<void * *>(&::DAT_010a0d24));
    parameter0c = parameter;
    vtable = &VTABLE_010c38ac;
    int index;
    Vector3i* coordinate = &bounds;
    coordinate->z = 0;
    coordinate->x = 0;
    coordinate->y = 0;
    count10 = 0;
    for (index = 0; index < 8; ++index)
    {
        entries[index] = 0;
    }
}

#include "generated/data/staging/blk_00c60000_od.inc"
