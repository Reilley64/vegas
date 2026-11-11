
// src/staging/blk_00c60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "fnv/symbols_00c85000.h"
#include "havok/hkMemoryRouter.h"
#include "havok/SphereConstruction.h"
#include <cstdint>
#include <new>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/A89210IntsExtraData.h"
#include "fnv/decl/BSShaderRenderUtility.h"
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
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyOwner.h"
#include "fnv/decl/NiObject_00a7b3d0.h"
#include "fnv/decl/NiPSysBoxEmitterWrapper.h"
struct FUN_00438fc0_file;
struct NiPoint3
{
  public:
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& b) const
    {
        return NiPoint3(x - b.x, y - b.y, z - b.z);
    }
    NiPoint3 operator/(float f) const
    {
        float reciprocal = 1.0f / f;
        return NiPoint3(x * reciprocal, y * reciprocal, z * reciprocal);
    }
    NiPoint3 operator*(float scale) const
    {
        return NiPoint3(x * scale, y * scale, z * scale);
    }
    NiPoint3& operator+=(const NiPoint3& b);
    bool operator!=(const NiPoint3& b);
    __forceinline bool operator==(const NiPoint3& b) const
    {
        return x == b.x && y == b.y && z == b.z;
    }
public:
    ::NiPoint3 &Subtract(const ::NiPoint3 &);
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
public:
    unsigned char ReadFromFile(::FUN_00438fc0_file *);
    bool FUN_004390c0(const ::NiPoint3 &);
    float GetLengthSquared();
    ::NiPoint3 Cross(const ::NiPoint3 &) const;
    ::NiPoint3 CrossProduct(const ::NiPoint3 &) const;
    ::NiPoint3 *ScaleTo(::NiPoint3 *, float);
    char *FUN_00a59af0(const char *);
    ::NiPoint3 &FUN_00b2a1c0(const ::NiPoint3 &);
};
#include "fnv/decl/ParticleModifierBinary.h"
#include "fnv/decl/PositionState.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/S_00a742a0.h"
#include "fnv/decl/Stub_00c31b60.h"
#include "fnv/decl/X.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_00a9a4e0__Cls_00a9a4e0.h"
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
#include <cstddef>
#include <windows.h>
#include <cstdlib>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00a5d2f0_class.h"
#include "fnv/decl/FUN_00a99c40_shell.h"
#include "fnv/decl/FUN_00a99d70_shell.h"
#include "fnv/decl/FUN_00c31c90_shell.h"
#include "fnv/decl/FUN_00c4c920_class.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiIntegerExtraData.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/StrArr.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_0068ac40__FUN_0068ac40_class.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c60000.h"
#include "fnv/symbols_00c61000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_01069000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c1000.h"
#include "fnv/symbols_011c1000.h"
#include <xmmintrin.h>
#include <cmath>
#include "fnv/decl/C75850Body.h"
#include "fnv/decl/CacObj.h"
#include "fnv/decl/Capsule.h"
#include "fnv/decl/CbfOwner.h"
#include "fnv/decl/ControllerC73.h"
#include "fnv/decl/ControllerShell.h"
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/FUN_00458840_Class.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_004b4ab0_Class.h"
#include "fnv/decl/FUN_004f0180_Class.h"
#include "fnv/decl/FUN_0056e0b0.h"
#include "fnv/decl/FUN_009c1a70_shell.h"
#include "fnv/decl/FUN_009c1aa0_Class.h"
#include "fnv/decl/FUN_00c663d0.h"
#include "fnv/decl/FUN_00c71120.h"
#include "fnv/decl/FUN_00c747b0_Class.h"
#include "fnv/decl/FUN_00c855f0_cls.h"
#include "fnv/decl/FUN_00cac110_Class.h"
#include "fnv/decl/FUN_00cac980_class.h"
#include "fnv/decl/FUN_00cafbd0_Class.h"
#include "fnv/decl/FUN_00cb24c0_cls.h"
#include "fnv/decl/FUN_00cb2e30_cls.h"
#include "fnv/decl/FnvCpu_FUN_00c89720_CpuInterface.h"
#include "fnv/decl/FnvCpu_FUN_00cac950_CpuObject.h"
#include "fnv/decl/Holder_cffa0.h"
#include "fnv/decl/InversePositionVector.h"
#include "fnv/decl/NameSetC136.h"
#include "fnv/decl/NiQuaternion.h"
#include "fnv/decl/PoseState.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/decl/SkeletonPoseData.h"
#include "fnv/decl/TransformedPosDAD.h"
#include "fnv/decl/TriggerCollector.h"
#include "fnv/decl/VirtualReader.h"
#include "fnv/decl/fnv_00c91f70__RayWorld.h"
#include "fnv/decl/fnv_00c92040__S00c92040_Obj.h"
#include "fnv/decl/hkaPoseCDA.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0056d000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00c55000.h"
#include "fnv/symbols_00c70000.h"
#include "fnv/symbols_00c75000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cdd000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_0104f000.h"
#include "fnv/symbols_01064000.h"
#include "fnv/symbols_01066000.h"
#include "fnv/symbols_010c3000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010c7000.h"
#include "fnv/symbols_011b0000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/tls.h"
#include "fnv/symbols_01272000.h"
#include "fnv/decl/C74C20Quat.h"
#include "fnv/decl/Quat74.h"
#include "fnv/symbols_simd.h"
#include "fnv/decl/FUN_0070c440_stub.h"
#include "fnv/symbols_00c6d000.h"
#include "fnv/decl/FUN_00560e10_cls.h"
#include "fnv/decl/FUN_006211b0_cls.h"
#include "fnv/decl/FUN_00c67850_Class.h"
#include "fnv/decl/FUN_00c7f690_cls.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00c936a0_World.h"
#include "fnv/decl/FUN_00cd5680_cls.h"
#include "fnv/decl/FUN_00cd8a10_cls.h"
#include "fnv/decl/MalleableGetterStandIn.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/decl/S_Owner.h"
#include "fnv/decl/ScriptX.h"
#include "fnv/decl/SortableArray.h"
#include "fnv/decl/This676.h"
#include "fnv/decl/ThisCls.h"
#include "fnv/decl/fnv_00c6aac0__FUN_00c6aac0_Owner.h"
#include "fnv/decl/fnv_00cbc7b0__FUN_00cbc7b0_cls.h"
#include "fnv/decl/hkQuaternion.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpWorldC914.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c74000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00ca9000.h"
#include "fnv/symbols_00cd8000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_0102c000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_011af000.h"

// The byte before an aligned block holds the distance back to the start of its allocation.
struct AlignedBlockPrefix
{
    unsigned char m_ucOffset;
};
inline AlignedBlockPrefix* GetAlignedBlockPrefix(void* apBlock)
{
    return static_cast<AlignedBlockPrefix*>(apBlock) - 1;
}

// The global string table stores a reference count and the length before each string.
struct GlobalStringHeader
{
    volatile long m_lRefCount;
    unsigned int m_uiLength;
};
inline GlobalStringHeader* GetGlobalStringHeader(const void* apString)
{
    return const_cast<GlobalStringHeader*>(static_cast<const GlobalStringHeader*>(apString) - 1);
}

// NiObject's members.
struct NiObjectFields
{
    void* m_pVtbl;
    unsigned int m_uiRefCount;
};
// The name that follows NiObject in NiObjectNET and NiPSysModifier.
struct NamedObjectFields : NiObjectFields
{
    const char* m_kName;
};
// NiPSysModifier's members.
struct NiPSysModifierFields : NamedObjectFields
{
    unsigned int m_uiOrder;
    void* m_pkTarget;
    bool m_bActive;
};
// BSPSysSimpleColorModifier's members after NiPSysModifier.
struct SimpleColorModifierFields : NiPSysModifierFields
{
    float m_afColor1[4];
    float m_afColor2[4];
    float m_afColor3[4];
    float m_fFadeIn;
    float m_fFadeOut;
    float m_fColor1End;
    float m_fColor2Start;
    float m_fColor2End;
    float m_fColor3Start;
};
// BSParentVelocityModifier's members after NiPSysModifier.
struct ParentVelocityModifierFields : NiPSysModifierFields
{
    char pad18[8];
    float m_fDamping;
};


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

struct CloningProcess;
struct NiStream;
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
    void FUN_00c61430(intptr_t, intptr_t);
};

// @fnv 0x00c61430
void FUN_00c61430_Class::FUN_00c61430(intptr_t a, intptr_t b)
{
    reinterpret_cast<::FUN_00a99870_shell *>((((FUN_00a99870_Class*)this)))->FUN_00a99870((::FUN_00a99870_shell *)(a), (void *)(b));
}

struct FUN_00c61450_Class
{
    void FUN_00c61450(intptr_t a);
};

// @fnv 0x00c61450
void FUN_00c61450_Class::FUN_00c61450(intptr_t aiValue)
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
    return !reinterpret_cast<::FUN_00a89ae0_shell *>(this)->FUN_00a89ae0((intptr_t)(arg));
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
    char FUN_00c614e0(intptr_t arg);
};
// Calls FUN_00a998e0 with arg and returns its result.
// @fnv 0x00c614e0
char FUN_00c614e0_Class::FUN_00c614e0(intptr_t arg)
{
    char result = ((char)(reinterpret_cast<::Extra_00a998e0 *>(this)->FUN_00a998e0((::Extra_00a998e0 *)(arg))));
    return result;
}

class NiFixedString;
class NiAVObject
{
  public:
    void FUN_00c61610();
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
};

// @fnv 0x00c61610
void NiAVObject::FUN_00c61610()
{
    ::AssignFixedString((char *)this, (intptr_t)&(*DAT_012043a0), {});
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

struct NiStream;
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
public:
    ::NiObject *DynamicCast(const ::NiRTTI *);
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

class NiAVObject;
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
    char pad[0x54];
    void* m_p54;
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
    void ForwardToOther(intptr_t a);
};

// @fnv 0x00c63950
void FUN_00c63950_class::ForwardToOther(intptr_t aiValue)
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
void __cdecl CallWithSameArgumentTwice(intptr_t aiValue)
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
// Links this object to the stream, then passes its name to the stream's FUN_00a64160.
// @fnv 0x00c64950
void NiObject::FUN_00c64950(NiStream* stream)
{
    ::FUN_00a89af0((std::intptr_t)this);
    reinterpret_cast<::FUN_00a64160_cls *>((stream))->FUN_00a64160(reinterpret_cast<NamedObjectFields*>(this)->m_kName);
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
    intptr_t GetThisAddress(int);
};

// @fnv 0x00c64fc0
intptr_t FUN_00c64fc0_class::GetThisAddress(int)
{
    return (intptr_t)this;
}

struct NiStream;
class NiExtraData
{
  public:
    void LinkObject(NiStream& stream);
    void FUN_00c65160(NiStream& stream);
    void LoadBinary(::NiStream &);
};

// @fnv 0x00c65160
void NiExtraData::FUN_00c65160(NiStream& stream)
{
    LinkObject(stream);
}

struct C00c541e0
{
    bool FUN_00c65290(intptr_t a);
};

// Calls FUN_00a7b3d0 with the given int and returns its bool result.
// @fnv 0x00c65290
bool C00c541e0::FUN_00c65290(intptr_t aiValue)
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

void __cdecl FUN_00aa10f0(void* p);
struct FUN_00a7b300
{
    virtual void vf00();
    int m_04;
    int m_08;
    int m_0C;
    ~FUN_00a7b300();
};
struct C613A0_StringsData : FUN_00a7b300
{
    void* m_pData;
    ~C613A0_StringsData()
    {
        FUN_00aa10f0(m_pData);
        m_pData = 0;
    }
};
struct C613A0_Extra : C613A0_StringsData
{
    ~C613A0_Extra();
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
    void Deallocate(void*);
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
    float value = reinterpret_cast<ParentVelocityModifierFields*>(this)->m_fDamping;
    reinterpret_cast<ParentVelocityModifierFields*>(dst)->m_fDamping = value;
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
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)(reinterpret_cast<SStream*>(stream)), (intptr_t)(reinterpret_cast<SObj*>(this + 0x20)));
}

void __cdecl FUN_00c63b40(void* p);
struct FUN_00c64610_Class
{
    void FUN_00c63b40();
    void* FUN_00c64610(unsigned int flags);
};

namespace fnv_00c64710 {
struct MemoryManager
{
};
struct FUN_00c64710_node
{
    void* m_pNext;
    void* m_p04;
    void* m_p08;
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
        FUN_00c64710_node* next = static_cast<FUN_00c64710_node*>(p);
        p = next->m_pNext;
        next->m_p08 = 0;
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
    FUN_00c60240();
};
// Constructor: sets the vtable pointer and zeroes the three colours.
// @fnv 0x00c60240
FUN_00c60240::FUN_00c60240()
{
    SimpleColorModifierFields* pkFields = reinterpret_cast<SimpleColorModifierFields*>(this);
    pkFields->m_pVtbl = &DAT_010c3384;
    {
        float* p = pkFields->m_afColor1;
        p[0] = 0.0f;
        p[1] = 0.0f;
        p[2] = 0.0f;
        p[3] = 0.0f;
    }
    {
        float* q = pkFields->m_afColor2;
        q[0] = 0.0f;
        q[1] = 0.0f;
        q[2] = 0.0f;
        q[3] = 0.0f;
    }
    {
        float* r = pkFields->m_afColor3;
        r[0] = 0.0f;
        r[1] = 0.0f;
        r[2] = 0.0f;
        r[3] = 0.0f;
    }
}

struct NiStream;
struct NiStream;
struct RgbaColor
{
public:
    char *ToString(const char *);
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
    SimpleColorModifierFields* pkFields = reinterpret_cast<SimpleColorModifierFields*>(this);
    reinterpret_cast<::ParticleModifierBinary *>(this)->FUN_00c31950((*(::OutputStream *)(stream)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (intptr_t)(&pkFields->m_fFadeIn));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (intptr_t)(&pkFields->m_fFadeOut));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (intptr_t)(&pkFields->m_fColor1End));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (intptr_t)(&pkFields->m_fColor2Start));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (intptr_t)(&pkFields->m_fColor2End));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (intptr_t)(&pkFields->m_fColor3Start));
    reinterpret_cast<::FUN_00a698a0_class *>(((RgbaColor*)pkFields->m_afColor1))->FUN_00a698a0((void *)&(*stream));
    reinterpret_cast<::FUN_00a698a0_class *>(((RgbaColor*)pkFields->m_afColor2))->FUN_00a698a0((void *)&(*stream));
    reinterpret_cast<::FUN_00a698a0_class *>(((RgbaColor*)pkFields->m_afColor3))->FUN_00a698a0((void *)&(*stream));
}

struct P03MM
{
    void* Allocate(unsigned int);
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
    ::FUN_0044adf0((::MiddleHighProcess *)&(stream), (intptr_t)&(count));
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
struct FUN_00c63330_fields : NiPSysModifierFields
{
    float m_f18;
    float m_f1c;
    float m_f20;
    NiPoint3_ZERO m_k24;
    NiPoint3_ZERO m_k30;
};
struct FUN_00c63330 : NiPSysPositionModifier
{
    FUN_00c63330();
};
// Initializes the object's vtable pointer, sets the modifier order to 0xbb8, zeroes the two NiPoint3 members, and clears m_f20 and m_f18.
// @fnv 0x00c63330
FUN_00c63330::FUN_00c63330()
{
    FUN_00c63330_fields* pkFields = reinterpret_cast<FUN_00c63330_fields*>(this);
    pkFields->m_pVtbl = &DAT_010c37fc;
    pkFields->m_uiOrder = 0xbb8;
    pkFields->m_k24 = (*reinterpret_cast<struct ::NiPoint3_ZERO *>((void *)&::NiPoint3::ZERO));
    pkFields->m_k30 = (*reinterpret_cast<struct ::NiPoint3_ZERO *>((void *)&::NiPoint3::ZERO));
    pkFields->m_f20 = 0.0f;
    pkFields->m_f18 = 0.0f;
}

int strcpy_s(char* dst, unsigned int size, const char* src);
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
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

struct FUN_00c60000_fields : NiPSysModifierFields
{
    float m_f18;
};
struct FUN_00c60000_Class
{
    bool IsEqualWithFloat(void* arg);
};

// Calls IsEqual on arg, then returns whether arg's m_f18 equals this one's.
// @fnv 0x00c60000
bool FUN_00c60000_Class::IsEqualWithFloat(void* apObject)
{
    if (!((IsEqualHelper*)this)->IsEqual((NiObject*)apObject))
        return false;
    void* p = apObject;
    if (static_cast<FUN_00c60000_fields*>(p)->m_f18 == reinterpret_cast<FUN_00c60000_fields*>(this)->m_f18)
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
    SimpleColorModifierFields* pkFields = reinterpret_cast<SimpleColorModifierFields*>(this);
    reinterpret_cast<::NiPSysModifier *>((reinterpret_cast<NiPSysModifierLoadBinary_StandIn*>(this)))->LoadBinary(stream);

    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&pkFields->m_fFadeIn);
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&pkFields->m_fFadeOut);
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&pkFields->m_fColor1End);
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&pkFields->m_fColor2Start);
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&pkFields->m_fColor2End);
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&pkFields->m_fColor3Start);

    reinterpret_cast<::RgbaColor *>((reinterpret_cast<NiColorALoadBinary_StandIn*>(pkFields->m_afColor1)))->LoadBinary(stream);
    reinterpret_cast<::RgbaColor *>((reinterpret_cast<NiColorALoadBinary_StandIn*>(pkFields->m_afColor2)))->LoadBinary(stream);
    reinterpret_cast<::RgbaColor *>((reinterpret_cast<NiColorALoadBinary_StandIn*>(pkFields->m_afColor3)))->LoadBinary(stream);
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
    ::AssignFixedString((char *)(object), (intptr_t)&(::DAT_011f49e0), {});
    return object;
}

struct NiBinaryExtraData;
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
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&reinterpret_cast<ParentVelocityModifierFields*>(this)->m_fDamping);
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

}  // namespace fnv_00c64060

struct FUN_00c64500_Class : FUN_00c61490_Class
{
    bool FUN_00c64500(const void* arg);
};

// Returns the negation of FUN_00a89ae0(arg).
// @fnv 0x00c64500
bool FUN_00c64500_Class::FUN_00c64500(const void* arg)
{
    return !reinterpret_cast<::FUN_00a89ae0_shell *>(this)->FUN_00a89ae0((intptr_t)(arg));
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
    ::AssignFixedString((char *)(result), (intptr_t)&(::DAT_011f49e0), {});
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

// Returns true when IsEqual(arg) holds and both objects' names are non-null and __stricmp-equal.
// @fnv 0x00c64980
bool FUN_00c64980_Class::FUN_00c64980(A46BB0Object* apOther)
{
    if (reinterpret_cast<::A5d470Class *>((this))->IsSameAs((::A5d470Object *)(apOther)))
    {
        A46BB0Object* p = apOther;
        if (reinterpret_cast<NamedObjectFields*>(this)->m_kName != 0)
        {
            const char* a = reinterpret_cast<NamedObjectFields*>(p)->m_kName;
            if (a != 0)
            {
                const char* b = reinterpret_cast<NamedObjectFields*>(p)->m_kName;
                const char* c = reinterpret_cast<NamedObjectFields*>(this)->m_kName;
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
    FUN_0043ba10_shell* FUN_00c64dc0(uintptr_t a);
};
// @fnv 0x00c64dc0
FUN_0043ba10_shell* FUN_00c64dc0_Class::FUN_00c64dc0(uintptr_t a)
{
    int v0;
    int v1;
    int v2;
    return reinterpret_cast<::FUN_0043ba10_shell *>(&(m_iWordAt04))->FUN_0043ba10((::FUN_0043ba10_shell *)(a));
}



void* __cdecl FUN_00aa13e0(size_t size);

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

struct FUN_00c61c50_cls
{
    unsigned int pad0[0x18];
    unsigned int* m_60;
    unsigned short pad1[1];
    unsigned short m_66;
    void FUN_00c61c50(uintptr_t x, uintptr_t y);
};

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
    ::FUN_00a89af0((std::intptr_t)this);
}
// @fnv 0x00c627e0
void FUN_00c627e0_Class::FUN_00c627e0(void* pValue)
{
    m_p54 = pValue;
    reinterpret_cast<::FUN_00c62140_cls *>(this)->FUN_00c62140();
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
    unsigned int FUN_00c62cc0(uintptr_t arg);
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
    reinterpret_cast<::NiPoint3 *>(&(mm[usIndex]))->Subtract((*(const ::NiPoint3 *)(((uintptr_t)(reinterpret_cast<::FUN_0045bb20_cls *>(&(m_30))->ApplyScaled((::FUN_0045bb20_target *)(::XVec12 *)(&xx), {}))))));
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
extern "C" void* __cdecl FUN_00aa13e0(size_t size);
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

void* __cdecl FUN_00aa13e0(size_t size);
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
    char* r1;
    char* r2;
    const char* g;
    Pad32 pad;
    reinterpret_cast<::FUN_00c319e0_cls *>(this)->FUN_00c319e0((::StrArr *)(a1));
    g = *reinterpret_cast<const char* const*>(&::g_012043c8);
    r1 = ::FUN_00a7d330(g);
    reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((intptr_t)(&r1));
    r2 = ::FUN_00a7d550("Damping", reinterpret_cast<ParentVelocityModifierFields*>(this)->m_fDamping);
    reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((intptr_t)(&r2));
}

// A count followed by two arrays of up to 8 triples.
struct S_00c643d0_Entry
{
    unsigned short m_usCount;
    unsigned int m_auiFirst[24];
    unsigned int m_auiSecond[24];
};
struct S_00c643d0_Foo
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    unsigned short m_uiItemCount;
    S_00c643d0_Entry* m_entries[16];

    void FUN_00c643d0(intptr_t arg);
};


// @fnv 0x00c643d0
void S_00c643d0_Foo::FUN_00c643d0(intptr_t arg)
{
    reinterpret_cast<::fnv_00a9a4e0::Cls_00a9a4e0 *>((this))->FUN_00a9a4e0((*(::fnv_00a9a4e0::NiStream *)(arg)));

    ::fnv_00a303a0::FUN_00a303a0((::fnv_00a303a0::Stream *)(arg), &this->m_uiItemCount);

    for (int i = 0; i < this->m_uiItemCount; ++i)
    {
        ::fnv_00a303a0::FUN_00a303a0((::fnv_00a303a0::Stream *)(arg), this->m_entries[i]);

        int count2 = this->m_entries[i]->m_usCount;
        void* count = this->m_entries[i]->m_auiFirst;

        ::FUN_00a417b0((void *)(arg), count, count2 * 3);

        int data = this->m_entries[i]->m_usCount;
        void* pDataB = this->m_entries[i]->m_auiSecond;

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
    virtual void v30(uintptr_t value);
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
    ::FUN_00a89af0((std::intptr_t)this);
    count = m_14;
    bytes = count * 2;
    ::FUN_0044adf0((::MiddleHighProcess *)(apTarget), (intptr_t)(&bytes));
    for (i = 0; i < count; i++)
    {
        item3 = m_0c[i];
        if (item3 != 0)
        {
            v2 = item3->m_18;
            apTarget->v30(v2);
            apTarget->v30((uintptr_t)item3);
        }
    }
}

struct FUN_00c64da0_cls
{
    int unk00;
    void FUN_00c64da0(intptr_t a);
};

// @fnv 0x00c64da0
void FUN_00c64da0_cls::FUN_00c64da0(intptr_t a)
{
    int unkLoc0;
    int unkLoc1;
    int unkLoc2;
    reinterpret_cast<::FUN_0043ba10_shell *>((this))->FUN_0043ba10((::FUN_0043ba10_shell *)(a));
}

// A key/value pair of global-string handles.
struct DispatchStub_c64_pair
{
    const char* m_pcKey;
    const char* m_pcValue;
};
struct DispatchStub_c64
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DispatchStub_c64_pair** m10;
    int unk14;
    unsigned short m18;
    void DispatchToItems(intptr_t a8, intptr_t cc);
};
struct ItemCallee_c64
{
};


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
    DispatchStub_c64_pair** m_10;
    int m_14;
    unsigned short m_18;

    unsigned char VisitEntries(FUN_00c65180_VTable* p);
};

// Calls FUN_00a7b290; if it succeeds, iterates m_10 up to m_18 times, passing each pair's key and value to the vtable's FUN_00c65180_v8, and returns the result.
// @fnv 0x00c65180
unsigned char FUN_00c65180_Class::VisitEntries(FUN_00c65180_VTable* p)
{
    unsigned char result = ((unsigned char)(reinterpret_cast<::MyOwner *>(this)->FUN_00a7b290((*(::NiStream *)(p)))));

    if (result)
    {
        unsigned int count = m_18;

        for (unsigned int i = 0; i < count; ++i)
        {
            DispatchStub_c64_pair* item = m_10[i];

            p->FUN_00c65180_v8(&item->m_pcKey);
            p->FUN_00c65180_v8(&item->m_pcValue);
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
    char* first = ::FUN_00a7d330((const char *)(::GlobalObject_00a7b610 *)((GlobalObject_00a7b610*)global_ptr));
    reinterpret_cast<::S_0060ba10 *>((values))->FUN_0096a610((intptr_t)&(first));
    char* second = (char*)FUN_00a7d510(str_0109df4c, unk0c);
    reinterpret_cast<::S_0060ba10 *>((values))->FUN_0096a610((intptr_t)&(second));
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
    const char* m_pcName;
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
    const char* ra;
    int oa;
    const char* v1;
    char* cur;
    FUN_00c61fc0_Item* x;
    long qa;
    int ta;
    void* mb;
    int xa;
    long gb;
    reinterpret_cast<::FUN_00c31db0_cls *>(this)->FUN_00c31db0((::NameArray_b9457 *)(apTarget));
    v1 = *reinterpret_cast<const char* const*>(&::g_012043b0);
    mb = ::FUN_00a7d330(v1);
    reinterpret_cast<::S_0060ba10 *>((((FUN_0096a610_Target*)apTarget)))->FUN_0096a610((intptr_t)(&mb));
    xa = unk58;
    ib = reinterpret_cast<::FUN_00c62090_Class *>(this)->BuildAttachTypeString("ArrayType", xa);
    reinterpret_cast<::S_0060ba10 *>((((FUN_0096a610_Target*)apTarget)))->FUN_0096a610((intptr_t)(&ib));
    mid = m_iArrayLength;
    while (0 != mid--)
    {
        b = &m_ppItems[mid];
        x = *b;
        if (!!x)
        {
            ra = x->m_pcName;
            cur = ::fnv_00a7d5e0::FUN_00a7d5e0((const char *)(int *)(&DAT_01063e84), ra);
            reinterpret_cast<::S_0060ba10 *>((((FUN_0096a610_Target*)apTarget)))->FUN_0096a610((intptr_t)(&cur));
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
    char* uiName = ::FUN_00a7d330((const char *)(obj));
    reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)pkStrings)))->FUN_0096a610((intptr_t)&(uiName));

    char* uiValue = ::FUN_00a7d550("fUpdateDeltaTime", m_fValue);
    reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)pkStrings)))->FUN_0096a610((intptr_t)&(uiValue));

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


// If DAT_012043a0 is set, calls InterlockedDecrement on its header unless it holds DAT_0109b220, frees it via FUN_00aa4060, then sets DAT_012043a0 to 0.
// @fnv 0x00c61760
void FUN_00c61760()
{
    NiFixedString* tmp = DAT_012043a0;
    NiFixedString* p = tmp;
    NiFixedString* result;

    if (p != 0)
    {
        void* pcHandle = *reinterpret_cast<void**>(p);
        if (pcHandle == DAT_0109b220)
        {
        }
        else
        {
            InterlockedDecrement(&GetGlobalStringHeader(pcHandle)->m_lRefCount);
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

struct S61990Obj
{
    char* vt;
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
        unsigned int uiLinkID = (unsigned int)(uintptr_t)unk08;
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
        reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(pcViewerStr));
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
            reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(unk2));
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

class NiExtraData;

class NiFixedString;




void __cdecl CallWithSameArgumentTwice(int a);





FUN_00c61b10* FUN_00c61e70();




int __cdecl __stricmp(const char*, const char*);


struct NiGlobalStringTable
{
    static char* AddString(const char*);
};

class NiFixedString
{
  public:
    char* handle;
    __forceinline NiFixedString(const char* value)
    {
        if (!value)
            handle = DAT_0109b220;
        else
            handle = NiGlobalStringTable::AddString(value);
    }
    __forceinline ~NiFixedString()
    {
        if (handle == DAT_0109b220)
            return;
        long* count = reinterpret_cast<long*>(handle - 8);
        InterlockedDecrement(count);
    }
};

struct Color316
{
    float r, g, b, a;
};

struct Base316
{
    virtual void vf0();
    int unk04, unk08, unk0c, unk10, unk14;
    Base316(const NiFixedString&, unsigned int);
};

struct FUN_00c60100 : Base316
{
    Color316 first, second, third;
    float f48, f4c, f50, f54, f58, f5c;
    FUN_00c60100(const char*, const Color316&, const Color316&, const Color316&, float, float, float, float, float,
                 float);
};

// @fnv 0x00c60100
FUN_00c60100::FUN_00c60100(const char* name, const Color316& c1, const Color316& c2, const Color316& c3, float a,
                           float b, float c, float d, float e, float f)
    : Base316(NiFixedString(name), 3000), first(c1), second(c2), third(c3), f48(a), f4c(b), f50(c), f54(d), f58(e),
      f5c(f)
{}

struct EmitBaseB10
{
    virtual ~EmitBaseB10();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    unsigned int unk44, unk48, unk4c, unk50, unk54;
    EmitBaseB10();
};

struct PrimArrayBaseB10
{
    virtual ~PrimArrayBaseB10();
    void* m_data;
    unsigned short m_pRayCursor, m_iElementCount, m_uiItemCount, m_growBy;
    PrimArrayBaseB10(unsigned short initial, unsigned short grow)
    {
        m_pRayCursor = initial;
        m_growBy = grow;
        m_iElementCount = 0;
        m_uiItemCount = 0;
        if (m_pRayCursor > 0)
        {
            unsigned int uiBytes = m_pRayCursor * 4;
            m_data = NiMalloc(uiBytes);
        }
        else
            m_data = 0;
    }
};

template <class T> struct PrimArrayB10 : PrimArrayBaseB10
{
    PrimArrayB10(unsigned short capacity = 0, unsigned short grow = 1) : PrimArrayBaseB10(capacity, grow)
    {}
};

namespace emitB10 {
struct FUN_00c61b10 : EmitBaseB10
{
    unsigned int unk58;
    PrimArrayB10<void*> m_kThirdFollowingStreamField;
    virtual ~FUN_00c61b10();
    FUN_00c61b10();
};
// @fnv 0x00c61b10
FUN_00c61b10::FUN_00c61b10() : unk58(2), m_kThirdFollowingStreamField(0, 1)
{}
}

extern char* g_pcEmptyString;

class NiPSysPositionModifierBase
{
  public:
    NiPSysPositionModifierBase(const NiFixedString& kName, unsigned int uiOrder);
    virtual void v00();
    unsigned int m_04;
    char* m_pcName;
    unsigned int m_uiUpdateOrder;
    unsigned int m_uiValue1;
    unsigned char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;
};

class FUN_00c633b0 : public NiPSysPositionModifierBase
{
  public:
    FUN_00c633b0(const char* pcName);
    float m_f18;
    int m_1c;
    float m_f20;
    NiPoint3_c m_kPoint24;
    NiPoint3_c m_kPoint30;
};

struct NiRTTI645
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};

void* NiMalloc645(unsigned int uiSize);

void NiFree645(void* p);

template <class T> struct PrimArray645
{
    void* m_vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    static T* Allocate(unsigned int auiCount)
    {
        return (T*)NiMalloc645(sizeof(T) * auiCount);
    }
    void SetSize(unsigned int uiMaxSize)
    {
        if (uiMaxSize == m_usMaxSize)
            return;
        unsigned int i;
        if (uiMaxSize < m_usSize)
        {
            for (i = uiMaxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != T(0))
                {
                    m_pBase[i] = T(0);
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)uiMaxSize;
        }
        T* pSaveBase = m_pBase;
        m_usMaxSize = (unsigned short)uiMaxSize;
        if (uiMaxSize > 0)
        {
            m_pBase = Allocate(m_usMaxSize);
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = pSaveBase[i];
            for (i = m_usSize; i < m_usMaxSize; i++)
                m_pBase[i] = T(0);
        }
        else
        {
            m_pBase = 0;
        }
        NiFree645(pSaveBase);
    }
    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int FUN_0096a610(const T& element)
    {
        return SetAtGrow(m_usSize, element);
    }
};

typedef PrimArray645<char*> ViewerStrings645;

struct Parent645
{
};

struct Obj645 : Parent645
{
    void FUN_00c645c0(ViewerStrings645* pkStrings);
};

// @fnv 0x00c645c0
void Obj645::FUN_00c645c0(ViewerStrings645* pkStrings)
{
    reinterpret_cast<::FUN_00a99d70_shell *>(this)->FUN_00a99d70((::A89C70StringArray *)(pkStrings));
    reinterpret_cast<::S_0060ba10 *>((pkStrings))->FUN_0096a610((intptr_t)&(const char *const &)(FUN_00a7d330((*reinterpret_cast<::NiRTTI645 *>(&::g_011f4428)).GetName())));
}

void* NiMalloc64d(unsigned int uiSize);

struct ModBase64d
{
    virtual void V00();
    int m_04;
    int m_08;
    ModBase64d(const char* pcName);
    ~ModBase64d();
};

struct ArrBase64d
{
    virtual void V00();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    static void* Allocate(unsigned int auiCount)
    {
        return NiMalloc64d(4 * auiCount);
    }
    ArrBase64d(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
        {
            m_pBase = Allocate(m_usMaxSize);
        }
        else
        {
            m_pBase = 0;
        }
    }
};

struct Arr64d : ArrBase64d
{
    Arr64d(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) : ArrBase64d(uiMaxSize, uiGrowBy)
    {}
    virtual void V00();
};

inline const char* GetDefaultName64d()
{
    return DAT_012043ec;
}

struct FUN_00c64de0 : ModBase64d
{
    Arr64d m_kArray;
    FUN_00c64de0();
    virtual void V00();
};

// @fnv 0x00c64de0
FUN_00c64de0::FUN_00c64de0() : ModBase64d(GetDefaultName64d())
{}

// Allocates a FUN_00c64de0 object, sets its name to DAT_011f49e0, and returns the new pointer.
// @fnv 0x00c652c0
FUN_00c64de0* __cdecl FUN_00c652c0()
{
    FUN_00c64de0* object = new FUN_00c64de0;
    ::AssignFixedString((char *)(object), (intptr_t)&(::DAT_011f49e0), {});
    return object;
}

namespace fnv_00c60b20 {
extern const char str_010c3494[];
extern const char str_010c3480[];
extern const char str_010c3470[];
extern const char str_010c345c[];
extern const char str_010c3450[];
extern const char str_010c3440[];
extern const char str_010c3438[];
extern const char str_010c3430[];
extern const char str_010c3428[];

struct ViewerStrings
{
};

struct RTTI_Stub
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};

char* __cdecl FUN_00a7d330(const char* name);

unsigned int __cdecl strlen(const char*);
void* __cdecl FUN_00aa1070(unsigned int);
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
extern const char str_0109dcec[];
extern const char str_0109c360[];
inline char* __cdecl FUN_00a7d550(const char* label, float value)
{
    unsigned int length = strlen(label) + 20;
    char* result = static_cast<char*>(FUN_00aa1070(length));
    FUN_00a305b0(result, length, str_0109dcec, value);
    return result;
}

extern const char str_0109dca0[];
inline char* __cdecl FUN_00a7d330(const char* name)
{
    char* result = static_cast<char*>(FUN_00aa1070(strlen(name) + 9));
    FUN_00a305b0(result, strlen(name) + 9, str_0109dca0, name);
    return result;
}

struct ColorA_Stub
{
    float r;
    float g;
    float b;
    float a;
    char* ToString(const char* label)
    {
        unsigned int length = strlen(label) + 36;
        char* result = static_cast<char*>(FUN_00aa1070(length));
        FUN_00a305b0(result, length, str_0109c360, r, g, b, a);
        return result;
    }
};

struct ModifierBase_Stub
{
};

struct SimpleColorModifier_Stub : ModifierBase_Stub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ColorA_Stub color1;
    ColorA_Stub color2;
    ColorA_Stub color3;
    float fadeIn;
    float fadeOut;
    float color1End;
    float color2Start;
    float color2End;
    float color3Start;

    void FUN_00c60b20(ViewerStrings* strings);
};

// @fnv 0x00c60b20
void SimpleColorModifier_Stub::FUN_00c60b20(ViewerStrings* strings)
{
    reinterpret_cast<::FUN_00c319e0_cls *>(this)->FUN_00c319e0((::StrArr *)(strings));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)((uintptr_t)::FUN_00a7d330(reinterpret_cast<RTTI_Stub*>(&(*reinterpret_cast<void * *>(&::g_01204390)))->GetName())));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)(((uintptr_t)(::FUN_00a7d550(str_010c3494, color1End * 100.0)))));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)(((uintptr_t)(::FUN_00a7d550(str_010c3480, color2Start * 100.0)))));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)(((uintptr_t)(::FUN_00a7d550(str_010c3470, color2End * 100.0)))));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)(((uintptr_t)(::FUN_00a7d550(str_010c345c, color3Start * 100.0)))));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)(((uintptr_t)(::FUN_00a7d550(str_010c3450, fadeIn * 100.0)))));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)(((uintptr_t)(::FUN_00a7d550(str_010c3440, fadeOut * 100.0)))));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)((uintptr_t)reinterpret_cast<::RgbaColor *>(&(color1))->ToString(str_010c3438)));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)((uintptr_t)reinterpret_cast<::RgbaColor *>(&(color2))->ToString(str_010c3430)));
    reinterpret_cast<::S_0060ba10 *>((strings))->FUN_0096a610((intptr_t)&(const uintptr_t &)((uintptr_t)reinterpret_cast<::RgbaColor *>(&(color3))->ToString(str_010c3428)));
}
}

// namespace fnv_00c60b20

void* NiMalloc(unsigned int size);

void NiFree(void* p);

struct CmpRefObject
{
    virtual ~CmpRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct CmpPtr
{
    CmpRefObject* m_pObject;
    CmpPtr(CmpRefObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~CmpPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    CmpPtr& operator=(const CmpPtr& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator!=(const CmpPtr& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

struct CmpPtrArray
{
    virtual ~CmpPtrArray();
    CmpPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    static CmpPtr* Allocate(unsigned int auiCount)
    {
        return (CmpPtr*)NiMalloc(sizeof(CmpPtr) * auiCount);
    }
    void FUN_00c63030();
};

// @fnv 0x00c63030
void CmpPtrArray::FUN_00c63030()
{
    if (m_usESize == m_usSize)
        return;

    if (m_usESize)
    {
        for (unsigned short i = 0, j = 0; i < m_usSize; i++)
        {
            if (m_pBase[i] != CmpPtr(0))
            {
                if (m_pBase[j] != m_pBase[i])
                    m_pBase[j] = m_pBase[i];
                j++;
            }
        }
    }

    CmpPtr* pSaveBase = m_pBase;
    m_usMaxSize = m_usSize = m_usESize;
    if (m_usMaxSize > 0)
    {
        m_pBase = Allocate(m_usMaxSize);
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pSaveBase);
}


// @fnv 0x00c633b0
FUN_00c633b0::FUN_00c633b0(const char* pcName) : NiPSysPositionModifierBase(NiFixedString(pcName), 0xbb8)
{
    m_kPoint24 = (*reinterpret_cast<::NiPoint3_c *>((void *)&::NiPoint3::ZERO));
    m_kPoint30 = (*reinterpret_cast<::NiPoint3_c *>((void *)&::NiPoint3::ZERO));
    m_f20 = 0.0f;
    m_f18 = 0.0f;
}

inline NiPoint3 operator*(float f, const NiPoint3& b)
{
    return NiPoint3(f * b.x, f * b.y, f * b.z);
}

struct MovingObject
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    NiPoint3 position;
};

struct MovingObjectOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    MovingObject* object;
    inline MovingObject* GetObject() const
    {
        const MovingObjectOwner* source = this;
        return source->object;
    }
};

struct Particle
{
    NiPoint3 position;
    int unk0c, unk10, unk14, unk18;
};

struct System
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned short count;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Particle* particles;
    __forceinline unsigned short GetCount() const
    {
        return count;
    }
};

struct Modifier
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void Reset();
    int unk04, unk08, unk0c;
    MovingObjectOwner* owner;
    int unk14;
    float elapsed, lastTime, scale;
    NiPoint3 previous, offset;
    void FUN_00c63520(float time, System* system);
};

// @fnv 0x00c63520
void Modifier::FUN_00c63520(float time, System* system)
{
    if (!system->GetCount())
        return;
    MovingObject* object5 = owner->GetObject();
    if (!object5)
    {
        Reset();
        return;
    }
    if (previous == (*reinterpret_cast<const NiPoint3*>(&(*reinterpret_cast<unsigned char *>((void *)&::NiPoint3::ZERO)))))
    {
        offset = (*reinterpret_cast<const NiPoint3*>(&(*reinterpret_cast<unsigned char *>((void *)&::NiPoint3::ZERO))));
        lastTime = time;
        previous = object5->position;
    }
    unsigned int count2 = system->GetCount();
    NiPoint3 position = object5->position;
    float delta8 = time - lastTime;
    if (delta8 != 0.0)
    {
        NiPoint3 movement = reinterpret_cast<::Point3_0053d280 *>((void *)&(const ::NiPoint3 &)((scale * (position - previous))))->FUN_0053d280(delta8);
        NiPoint3 difference2 = movement - offset;
        if (reinterpret_cast<::NiPlane *>((void *)&(const ::NiPoint3 &)(difference2))->operator==((const ::NiPlane &)((*reinterpret_cast<const NiPoint3*>(&(*reinterpret_cast<unsigned char *>((void *)&::NiPoint3::ZERO)))))))
        {
            Particle* particle = system->particles;
            while (count2--)
            {
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(particle->position))->FUN_0063c8a0((void *)&(difference2));
                ++particle;
            }
        }
        offset = movement;
    }
    elapsed = delta8;
    lastTime = time;
    previous = position;
}

struct PoolX
{
};

struct V3
{
    float x, y, z;
};

struct FUN_00c64640
{
    unsigned short m_usPassCountLocal;
    short pad;
    V3 a[8];
    V3 b[8];
    FUN_00c64640();
};

struct BaseX
{
};

struct ObjX : BaseX
{
    int pad[4];
    unsigned short m10;
    FUN_00c64640* m14[1];
    void FUN_00c640f0(ObjX* p, intptr_t a);
};

namespace fnv_00c64060 {
// Allocates a FUN_00c63ab0 with value 0, passes it to FUN_00c640f0 with value, and returns the new object.
// @fnv 0x00c64060
void* BSDecalPlacementVectorExtraData_StandIn::FUN_00c64060(int value)
{
    FUN_00c63ab0* pObject = new FUN_00c63ab0(0);
    reinterpret_cast<::ObjX *>((this))->FUN_00c640f0((::ObjX *)(pObject), value);
    return pObject;
}
}  // namespace fnv_00c64060

inline void DbgX()
{
    const char* a;
    const char* b;
    const char* c;
    const char* d;
    const char* e;
}

// @fnv 0x00c640f0
void ObjX::FUN_00c640f0(ObjX* p, intptr_t a)
{
    reinterpret_cast<::FUN_00a99c40_shell *>(this)->FUN_00a99c40((::NiBinaryExtraData *)(p), (::CloningProcess *)(a));
    p->m10 = m10;
    for (int i = 0; i < m10; i++)
    {
        p->m14[i] = new FUN_00c64640;
        p->m14[i]->m_usPassCountLocal = m14[i]->m_usPassCountLocal;
        for (int j = 0; j < m14[i]->m_usPassCountLocal; j++)
        {
            p->m14[i]->a[j] = m14[i]->a[j];
            p->m14[i]->b[j] = m14[i]->b[j];
        }
    }
    DbgX();
}

namespace fnv_00c64270 {
struct StreamY;
struct MemMgrY
{
};
struct Pt3Y
{
    float x, y, z;
};
inline void ReadPointsFromFile(StreamY& kStream, Pt3Y* pkPts, unsigned int uiElementCount)
{
    ::ReadElements((::NiStreamM *)&(kStream), (const unsigned int *)(float *)(&pkPts->x), uiElementCount * 3);
}
struct FUN_00c64640
{
    unsigned short m_usNum;
    Pt3Y m_akA[8];
    Pt3Y m_akB[8];
    FUN_00c64640();
};
struct BaseY
{
    int m_ai[4];
};
struct ObjY : BaseY
{
    unsigned short m_usElementCount;
    FUN_00c64640* m_apRecs[1];
    void FUN_00c64270(StreamY& kStream);
};
// @fnv 0x00c64270
void ObjY::FUN_00c64270(StreamY& kStream)
{
    reinterpret_cast<::NiIntegerExtraData *>(this)->LoadBinary((::NiStream &)(kStream));
    ::FUN_00a30370((::Stream *)&(kStream), &m_usElementCount);
    for (int i = 0; i < m_usElementCount; i++)
    {
        m_apRecs[i] = new FUN_00c64640;
        ::FUN_00a30370((::Stream *)&(kStream), &m_apRecs[i]->m_usNum);
        ReadPointsFromFile(kStream, m_apRecs[i]->m_akA, m_apRecs[i]->m_usNum);
        ReadPointsFromFile(kStream, m_apRecs[i]->m_akB, m_apRecs[i]->m_usNum);
    }
}
}

// namespace fnv_00c64270

namespace fnv_00c65040 {
struct FStrX
{
    char* m_kHandle;
    FStrX()
    {
        m_kHandle = ::DAT_0109b220;
    }
    ~FStrX()
    {
        if (m_kHandle == ::DAT_0109b220)
            return;
        long* plRef = (long*)(m_kHandle - 8);
        InterlockedDecrement(plRef);
    }
};
struct StreamX
{
};
struct MapX
{
};
struct BaseX
{
};
struct ObjM : BaseX
{
    int m_i0, m_i4, m_i8;
    MapX m_kFormatEntries;
    void FUN_00c65490(FStrX& kKey, FStrX& kVal);
    void Insert(FStrX& kKey, FStrX& kVal)
    {
        int aiD[3];
        FUN_00c65490(kKey, kVal);
    }
    void FUN_00c65040(StreamX& kStream);
};
// @fnv 0x00c65040
void ObjM::FUN_00c65040(StreamX& kStream)
{
    reinterpret_cast<::NiExtraData *>(this)->LoadBinary((::NiStream &)(kStream));
    unsigned int ItemUpdateArray = 0;
    ::FUN_00a26df0((::MyStream *)&(kStream), (void *)&(ItemUpdateArray));
    reinterpret_cast<::FUN_00c4c920_class *>(&(m_kFormatEntries))->FUN_00c4c920(ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        FStrX kKey;
        FStrX kVal;
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(kKey));
        reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(kVal));
        Insert(kKey, kVal);
    }
}
}

// namespace fnv_00c65040

// BSWArray derives from NiIntegersExtraData, which owns a count and int buffer.
struct ExtraData244
{
    virtual ~ExtraData244();
    int references;
    void* name;
    ExtraData244();
};

struct IntegerExtraData244 : ExtraData244
{
    unsigned int count;
    int* values;
    virtual ~IntegerExtraData244();
    IntegerExtraData244()
    {
        values = 0;
        count = 0;
    }
};

struct FUN_00c612b0 : IntegerExtraData244
{
    virtual ~FUN_00c612b0();
    FUN_00c612b0();
};

// @fnv 0x00c612b0
FUN_00c612b0::FUN_00c612b0()
{
    reinterpret_cast<::NiAVObject *>(this)->FUN_00c61610();
}

struct C616Node
{
    int m_unk00;
    C616Node* m_pNext;
};

struct C616Obj
{
    virtual void* v0();
    virtual void* v1();
    virtual C616Node* GetList();
};

struct C616Host
{
};

inline bool C616Contains(C616Node* node)
{
    while (node != 0)
    {
        if ((void*)node == (void*)&(*reinterpret_cast<void * *>(&::g_012043a4)))
            return true;
        node = node->m_pNext;
    }
    return false;
}

// @fnv 0x00c61630
void* FUN_00c61630(C616Host* host)
{
    void* result2 = 0;
    if (host != 0)
    {
        NiFixedString* key = DAT_012043a0;
        C616Obj* obj2 = ((::C616Obj *)(reinterpret_cast<::NiAVObject *>((host))->GetExtraData((*(const ::NiFixedString *)(key)))));
        if (obj2 == 0)
        {
            result2 = 0;
        }
        else
        {
            result2 = C616Contains(obj2->GetList()) ? (void*)obj2 : 0;
        }
    }
    return result2;
}

namespace fnv_00c616c0 {
struct MemMgr
{
};

extern char str_010c3610[];


class NiFixedString
{
  public:
    char* m_pData;
    __forceinline NiFixedString(const char* s)
    {
        if (s == 0)
            m_pData = (char*)(*reinterpret_cast<void * *>(&::DAT_0109b220));
        else
            m_pData = ::NiGlobalStringTable::AddString(s);
    }
};


// @fnv 0x00c616c0
void __cdecl FUN_00c616c0()
{
    (*reinterpret_cast<void * *>(&::DAT_012043a0)) = new NiFixedString(str_010c3610);
}
}

// namespace fnv_00c616c0

struct Quad16
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};

struct SubBase
{
    SubBase(unsigned short x, unsigned short y);
    virtual ~SubBase();
    int m_data;
    unsigned short m_uiX;
    unsigned short m_uiY;
};

struct SubObj : SubBase
{
    SubObj() : SubBase(0, 1)
    {}
    virtual ~SubObj();
};

struct BaseObj
{
    BaseObj(int a, int b, float f0, float f1, float f2, float f3, float f4, float f5, Quad16 q, float g0, float g1,
            float g2, float g3);
    virtual ~BaseObj();
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
};

struct FUN_00c61a10 : BaseObj
{
    int m_58;
    SubObj m_5c;
    FUN_00c61a10(int p1, int p2, int p3, float f0, float f1, float f2, float f3, float f4, float f5, Quad16 q, float g0,
                 float g1, float g2, float g3);
    virtual ~FUN_00c61a10();
};

// @fnv 0x00c61a10
FUN_00c61a10::FUN_00c61a10(int p1, int p2, int p3, float f0, float f1, float f2, float f3, float f4, float f5, Quad16 q,
                           float g0, float g1, float g2, float g3)
    : BaseObj(p1, p2, f0, f1, f2, f3, f4, f5, q, g0, g1, g2, g3), m_58(p3)
{
    SubObj* sub;
    reinterpret_cast<::FUN_00c62140_cls *>(this)->FUN_00c62140();
}

struct RefObj62
{
    virtual void V0();
    virtual void DeleteThis();
    int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct FixedStr62
{
    const char* m_kHandle;
    const char* GetHandle() const
    {
        return m_kHandle;
    }
};

struct Node62;

struct AVObj62 : RefObj62
{
    virtual void V8();
    virtual Node62* IsNode62();
    virtual void V10();
    virtual void V14();
    virtual AVObj62* V18();
};

struct Node62
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    NiPointer<AVObj62>* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    NiPointer<AVObj62>& GetAt(unsigned int index)
    {
        return m_pBase[index];
    }
};

struct Item62
{
    Item62* m_pkNext;
    Item62* m_pkPrev;
    NiPointer<AVObj62> m_element;
    void SetElement(const NiPointer<AVObj62>& p);
};

struct List62
{
    Item62* m_pkHead;
    Item62* m_pkTail;
    unsigned int m_uiCount;
    Item62* NewItem();
    void* Add62(const NiPointer<AVObj62>& p)
    {
        Item62* pkItem = NewItem();
        pkItem->SetElement(p);
        pkItem->m_pkNext = 0;
        pkItem->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkItem;
        else
            m_pkHead = pkItem;
        m_pkTail = pkItem;
        ++m_uiCount;
        return pkItem;
    }
};

struct Collector62
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    AVObj62* unk54;
    int unk58;
    List62 unk5c;
    int GetMode() const
    {
        return unk58;
    }
    void FUN_00c62200(AVObj62* pkObj);
};


// @fnv 0x00c62200
void Collector62::FUN_00c62200(AVObj62* pkObj)
{
    if (pkObj)
    {
        Node62* pkNode2 = pkObj->IsNode62();
        AVObj62* pkExcl = unk54;
        if (pkObj == pkExcl)
            return;
        bool bAdd2;
        switch (GetMode())
        {
        case 0:
            bAdd2 = bool(pkObj->V18());
            break;
        case 1:
            bAdd2 = ((void *)(reinterpret_cast<::NiAVObject *>((pkObj))->GetExtraData((*(const ::NiFixedString *)((*reinterpret_cast<::FixedStr62 *>(&::fnv_00c61990::DAT_012043ac)).GetHandle()))))) != 0;
            break;
        default:
            bAdd2 = pkNode2 != 0;
            break;
        }
        if (bAdd2)
        {
            reinterpret_cast<::S_00c62cc0_Class *>(&(unk5c))->FUN_00c62cc0((uintptr_t)&(const ::NiPointer< ::AVObj62> &)(pkObj));
        }
        if (pkNode2)
        {
            unsigned int i2 = pkNode2->GetSize();
            while (i2--)
                FUN_00c62200(pkNode2->GetAt(i2));
        }
    }
}

inline float UnitRandom()
{
    return (float)(std::rand() / DAT_01029790);
}

struct CamQ;
class FUN_00c62390_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CamQ* unk10;
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
    int m_58;
    int unk5C;
    void** m_60;
    unsigned short unk64;
    unsigned short m_66;

    int GetMode() const
    {
        return m_58;
    }
    void* GetAt(unsigned int i)
    {
        void*& r = m_60[i];
        return r;
    }
    void FUN_00c625f0(void* a, void* b, void* c);
    void FUN_00c62470(void* a, void* b, void* c);
    void FUN_00c62390(void* a1, void* a2);
};

// @fnv 0x00c61ba0
void FUN_00c61ba0_class::ForwardToBase(void* apUnused, void* apArg1, void* apArg2)
{
    reinterpret_cast<::FUN_00c62390_cls *>(this)->FUN_00c62390(apArg1, apArg2);
}

// @fnv 0x00c62390
void FUN_00c62390_cls::FUN_00c62390(void* a1, void* a2)
{
    void* pick;
    unsigned int n = m_66;
    if (n != 0)
    {
        unsigned int idx = (unsigned int)((double)n * UnitRandom());
        if (idx == n)
        {
            idx--;
        }
        pick = GetAt(idx);
    }
    else
    {
        pick = 0;
    }
    switch (GetMode())
    {
    case 0:
        FUN_00c625f0(pick, a1, a2);
        break;
    default:
        FUN_00c62470(pick, a1, a2);
        break;
    }
}

namespace fnv_00c625f0 {
float FUN_004579e0(float);

struct NiPoint3
{
  public:
    float x;
    float y;
    float z;
    NiPoint3& operator*=(float scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        return *this;
    }
    NiPoint3 operator*(float scale) const
    {
        return NiPoint3(scale * x, scale * y, scale * z);
    }
    float Length() const
    {
        float squared = x * x + y * y + z * z;
        return FUN_004579e0(squared);
    }
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

struct Matrix9
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    NiPoint3 FUN_004b4500(const NiPoint3& point)
    {
        return NiPoint3(m00 * point.x + m01 * point.y + m02 * point.z, m10 * point.x + m11 * point.y + m12 * point.z,
                        m20 * point.x + m21 * point.y + m22 * point.z);
    }
};

struct GeometryData
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual unsigned short GetVertexCount();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* vertices;
    NiPoint3* normals;
};

struct Geometry
{
    void** vtable;
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    struct DataPtr
    {
        GeometryData* object;
        GeometryData* operator->() const
        {
            return object;
        }
    } modelData;
    NiPoint3* GetVertices() const
    {
        return modelData->vertices;
    }
    NiPoint3* GetNormals() const
    {
        return modelData->normals;
    }
};

struct EmitterObject
{
    void** vtable;
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    Matrix9 rotation;
    int unk8c;
    int unk90;
    int unk94;
    float scale;
    float GetScale() const
    {
        return scale;
    }
};

typedef Geometry*(* GetGeometryFunction)(EmitterObject*);
typedef unsigned short(* GetVertexCountFunction)(GeometryData*);

struct EmitterSampler
{
    void FUN_00c625f0(EmitterObject* object, NiPoint3& position, NiPoint3& direction);
};

// @fnv 0x00c625f0
void EmitterSampler::FUN_00c625f0(EmitterObject* object, NiPoint3& position, NiPoint3& direction)
{
    Geometry* geometry = object ? ((GetGeometryFunction)object->vtable[6])(object) : 0;
    if (geometry)
    {
        unsigned short count = geometry->modelData->GetVertexCount();
        int index = (unsigned int)((double)count * (float)(std::rand() / ::DAT_01029790));
        if (index == count)
            index--;
        position = geometry->GetVertices()[index];
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::fnv_00c625f0::NiPoint3 &)(position))->FUN_00439180(object->GetScale());
        if (geometry->GetNormals())
        {
            NiPoint3 normal = geometry->GetNormals()[index];
            normal = object->rotation.FUN_004b4500(normal);
            direction = normal * reinterpret_cast<::NiPoint3 *>((void *)&(direction))->ComputeMagnitude();
        }
    }
    else
    {
        position = *(NiPoint3*)&(*reinterpret_cast<struct ::NiPoint3_ZERO *>((void *)&::NiPoint3::ZERO));
    }
}
}

// namespace fnv_00c625f0


struct S00c62800_Arr
{
    int vptr;
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline ~S00c62800_Arr();
};

__forceinline S00c62800_Arr::~S00c62800_Arr()
{
    *(void**)this = (void*)&DAT_010c377c;
    void* data = m_data;
    FUN_00aa10f0(data);
}

struct S00c62800_Base
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    __forceinline ~S00c62800_Base();
};

__forceinline S00c62800_Base::~S00c62800_Base()
{
    reinterpret_cast<::PositionState *>((((FUN_00c31750_Class*)this)))->FUN_00c31750();
}

struct S00c62800_Obj : S00c62800_Base
{
    S00c62800_Arr m_aiIndexedValues;
    __forceinline ~S00c62800_Obj();
    void* FUN_00c62800(unsigned int flags);
};

__forceinline S00c62800_Obj::~S00c62800_Obj()
{}

// @fnv 0x00c62800
void* S00c62800_Obj::FUN_00c62800(unsigned int flags)
{
    this->S00c62800_Obj::~S00c62800_Obj();
    if (flags & 1)
        operator delete(this, 0x6c);
    return this;
}

extern "C" void __cdecl NiFree(void* p);

struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPtr
{
  public:
    T* m_pObject;
    __forceinline NiPtr(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPtr<T>& operator=(const NiPtr<T>& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    __forceinline bool operator!=(const NiPtr<T>& other) const
    {
        return m_pObject != other.m_pObject;
    }
};

template <class T> struct MallocIf
{
    static T* Allocate(unsigned int auiCount)
    {
        return (T*)NiMalloc(sizeof(T) * auiCount);
    }
};

template <class T> class PtrArray
{
  public:
    virtual ~PtrArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00c628c0(unsigned int uiMaxSize);
};

// @fnv 0x00c628c0
template <class T> void PtrArray<T>::FUN_00c628c0(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != T(0))
            {
                m_pBase[i] = T(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    T* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = MallocIf<T>::Allocate(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = T(0);
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pSaveBase);
}

template class PtrArray<NiPtr<RefObj> >;

struct RefC62
{
    virtual void v00();
    virtual void v04();
    volatile long m_04;
    void Inc()
    {
        InterlockedIncrement(&m_04);
    }
    void Dec()
    {
        if (!InterlockedDecrement(&m_04))
            v04();
    }
};

struct PtrC62
{
    RefC62* m_00;
    PtrC62(RefC62* p = 0)
    {
        m_00 = p;
        if (m_00)
            m_00->Inc();
    }
    PtrC62(const PtrC62& p)
    {
        m_00 = p.m_00;
        if (m_00)
            m_00->Inc();
    }
    ~PtrC62()
    {
        if (m_00)
            m_00->Dec();
    }
    PtrC62& operator=(const PtrC62&);
    bool operator!=(const PtrC62& p) const
    {
        return m_00 != p.m_00;
    }
};

struct ArrayC62
{
    void* m_00;
    PtrC62* m_04;
    unsigned short m_08, m_0a, m_0c, m_0e;
    PtrC62 FUN_00c62d10(unsigned int i);
};

inline void FrameC62()
{
    struct Slots
    {
        unsigned int m_00, m_04;
    } slots;
    (void)&slots;
}

// @fnv 0x00c62d10
PtrC62 ArrayC62::FUN_00c62d10(unsigned int i)
{
    if (i >= m_0a)
        return PtrC62();
    PtrC62 result = m_04[i];
    m_04[i] = PtrC62(), FrameC62();
    if (result != PtrC62())
        --m_0c;
    if (i == (unsigned short)(m_0a - 1))
        --m_0a;
    return result;
}

namespace fnv_00c63c30 {
struct NiAllocator630
{
    virtual void v0();
    virtual void* Allocate(unsigned&, unsigned&, int, bool, bool, int, const char*);
};
struct NiManager630
{
    NiAllocator630* allocator;
};
extern NiManager630* DAT_011f6080;
extern const double DAT_01017cf8;
float FUN_004579e0(float);
extern void* DAT_012043d0;

struct MM630
{
    void* Allocate(unsigned int);
};


struct StrMem
{
    char* m_pChar;
    unsigned short m_usLen;
    unsigned short m_usMax;
    StrMem(const char* s);
    char* GetText() const
    {
        return m_pChar;
    }
    unsigned int GetLength() const
    {
        return m_usLen == 0xffff ? (unsigned int)std::strlen(GetText()) : (unsigned int)m_usLen;
    }
    ~StrMem()
    {
        reinterpret_cast<::TextString *>(this)->FUN_004037f0(0, 0);
    }
};

struct NameHolder
{
    const char* m_pChar;
    __forceinline NameHolder(const char* s)
    {
        if (!s)
            m_pChar = ::DAT_0109b220;
        else
            m_pChar = ::NiGlobalStringTable::AddString(s);
    }
};

struct Vec3
{
    float f[3];

    float Length() const
    {
        float squared = f[0] * f[0] + f[1] * f[1] + f[2] * f[2];
        return FUN_004579e0(squared);
    }
    void FUN_004a0c10()
    {
        float length = Length();
        if (length > DAT_01017cf8)
        {
            float reciprocal = 1.0f / length;
            f[0] *= reciprocal;
            f[1] *= reciprocal;
            f[2] *= reciprocal;
        }
        else
        {
            f[0] = 0;
            f[1] = 0;
            f[2] = 0;
        }
    }
};
struct Mat3
{
    Vec3 r0, r1, r2;
    void GetColumn(unsigned int col, Vec3& out) const
    {
        out.f[0] = r0.f[col];
        out.f[1] = r1.f[col];
        out.f[2] = r2.f[col];
    }
};
struct Child
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
    Mat3 m34;
    Vec3 m58;
};

struct ExtraX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m10;
    unsigned short pad12;
    void* m14[8];
};

extern const Vec3 ZERO;
struct VecGroup
{
    unsigned short m0;
    unsigned short pad2;
    Vec3 m4[8];
    Vec3 m64[8];
    VecGroup()
    {
        Vec3* position = m4;
        Vec3* normal = m64;
        m0 = 0;
        for (int i = 0; i < 8; i++)
        {
            position[i].f[0] = ZERO.f[0];
            position[i].f[1] = ZERO.f[1];
            position[i].f[2] = ZERO.f[2];
            normal[i].f[0] = ZERO.f[0];
            normal[i].f[1] = ZERO.f[1];
            normal[i].f[2] = ZERO.f[2];
        }
    }
};

extern int DAT_010a0d24, DAT_010c38ac;
struct ExtraRoot
{
    int* vfptr;
    int references;
    void* name;
    ExtraRoot();
};
struct ExtraBinary : ExtraRoot
{
    int value;
    ExtraBinary(int v)
    {
        vfptr = &DAT_010a0d24;
        value = v;
    }
};
struct ExtraList
{
    void* head;
    void* tail;
    unsigned size;
    ExtraList()
    {
        size = 0;
        head = 0;
        tail = 0;
    }
};
struct TESObjectDoorController : ExtraBinary
{
    unsigned short count, unk12;
    void* groups[8];
    ExtraList list;
    TESObjectDoorController(int v) : ExtraBinary(v)
    {
        vfptr = &DAT_010c38ac;
        count = 0;
        for (int i = 0; i < 8; i++)
            groups[i] = 0;
    }
    static void* operator new(std::size_t n)
    {
        unsigned size = n ? n : 1;
        unsigned alignment = 4;
        return DAT_011f6080->allocator->Allocate(size, alignment, 1, true, false, -1, 0);
    }
};

struct ChildPtr
{
    Child* object;
    operator Child*() const
    {
        Child* element = object;
        return element;
    }
};
struct ChildArray
{
    ChildPtr* data;
    unsigned short capacity, size, used, grow;
    ChildPtr& GetAt(unsigned int i) const
    {
        return data[i];
    }
};
struct ObjC63
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    int m4;
    char* m8;
    void* GetMesh()
    {
        void* name = m8;
        return name;
    }
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    ChildArray children;
};

// @fnv 0x00c63c30
bool __cdecl FUN_00c63c30(ObjC63* obj, ObjC63* root)
{
    if (obj->v0c())
    {
        if (!DAT_012043d0)
            DAT_012043d0 = new NameHolder("DVPG");
        ExtraX* extra = ((::fnv_00c63c30::ExtraX *)(reinterpret_cast<::NiAVObject *>((root))->GetExtraData((*(const ::NiFixedString *)(DAT_012043d0)))));
        ObjC63* p = obj;
        if (p->GetMesh() && ((intptr_t)(::FUN_004b75a0((const char *)(void *)(p->GetMesh()), "DecalPlacementVectorGroup"))))
        {
            if (!extra)
            {
                extra = (ExtraX*)new TESObjectDoorController(0);
                reinterpret_cast<::Holder *>((root))->FUN_00a5bc40((*(const ::NiFixedString *)(DAT_012043d0)), (::NiTexture *)(extra));
            }
            StrMem str4("DecalPlacementVectorGroup");
            const char* suffix3 = (const char*)p->GetMesh();
            suffix3 += str4.GetLength();
            int idx = (int)std::atoi(suffix3);
            if ((int)extra->m10 < 8 && idx < 8 && extra->m14[idx] == 0)
            {
                VecGroup* pv = new VecGroup();
                for (int i = 0; i < (int)p->children.used; i++)
                {
                    if (i < 8)
                    {
                        Child* child = (Child*)p->children.GetAt(i);
                        Mat3 m = child->m34;
                        Vec3 v5;
                        m.GetColumn(2, v5);
                        reinterpret_cast<::FUN_004a0c10_s *>(&(v5))->FUN_004a0c10();
                        pv->m4[pv->m0] = child->m58;
                        pv->m64[pv->m0] = v5;
                        pv->m0++;
                    }
                }
                extra->m14[idx] = pv;
                extra->m10++;
            }
            return true;
        }
        else
        {
            unsigned i = 0;
            while (i < p->children.size)
            {
                Child* c = (Child*)p->children.GetAt(i);
                if (c)
                {
                    if (FUN_00c63c30((ObjC63*)c, root))
                        c = 0;
                }
                i++;
            }
        }
    }
    return false;
}
}

class FUN_00a5d3a0 : public BSFaceGenMorphData
{
  public:
    FUN_00a5d3a0();
    int* vfptr;
    int references;
};

class FactoryObject : public FUN_00a5d3a0
{
  public:
    FactoryObject()
    {
        vfptr = &(*reinterpret_cast<int *>((void *)&::DAT_010c1364));
        value = 0;
    }
    int value;
};

// @fnv 0x00c64810
FactoryObject* __cdecl FUN_00c64810()
{
    return new FactoryObject;
}

namespace fnv_00c649f0 {
extern int DAT_010c13f4;
class FUN_00a5d3a0
{
  public:
    virtual void vf00();
    int m_04;
    FUN_00a5d3a0();
    ~FUN_00a5d3a0();
};
class C649F0_SubBase
{
  public:
};
class C649F0_Sub : public C649F0_SubBase
{
  public:
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    __forceinline C649F0_Sub()
    {
        int unused;
        (void)unused;
        reinterpret_cast<::fnv_0068ac40::FUN_0068ac40_class *>(this)->FUN_0068ac40(0, 1);
        m_00 = &::DAT_01069d84;
    }
};
class C649F0_Object : public FUN_00a5d3a0
{
  public:
    C649F0_Sub m_08;
    virtual void vf00();
};
// @fnv 0x00c649f0
C649F0_Object* __cdecl FUN_00c649f0()
{
    return new C649F0_Object;
}
}

// namespace fnv_00c649f0


class FNVListObj
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};

class FNVSubHelper
{
  public:
};

class FNVCtxHelper
{
  public:
};

// NiRTTI: a name and the base class's RTTI.
struct FNVRtti
{
    const char* m_pcName;
    FNVRtti* m_pkBaseRTTI;
};

inline bool InList(void*& p)
{
    while (p != 0)
    {
        if (p == (void*)&(*reinterpret_cast<int *>(&::g_011f4280)))
            return true;
        p = static_cast<FNVRtti*>(p)->m_pkBaseRTTI;
    }
    return false;
}

struct FUN_00c64c40_link
{
    char pad[8];
    void* m_p08;
};

struct FUN_00c64c40_object
{
    char pad[0x18];
    FUN_00c64c40_link* m_p18;
};

struct FUN_00c64c40_stream
{
    char pad[0x5c4];
    FNVCtxHelper* m_pkLinkMap;
};

class FUN_00c64c40_cls
{
  public:
    char pad[8];
    FNVSubHelper m_kList;
    bool FUN_00c64c40(void* a1, FNVListObj* a2);
};

// @fnv 0x00c64c40
bool FUN_00c64c40_cls::FUN_00c64c40(void* a1, FNVListObj* a2)
{
    void* local2;
    void* m18;
    void* p3;
    bool found2;
    void* r9;
    void* m9;
    {
        void* out;
        {
            unsigned int pad[6];
        }

        if (a2 == 0)
        {
            r9 = 0;
        }
        else
        {
            p3 = a2->v2();
            found2 = InList(p3);
            r9 = (void*)((found2 ? -1 : 0) & (intptr_t)a2);
        }

        local2 = r9;
        if (local2 != 0)
        {
            FUN_00c64c40_link* pkLink = static_cast<FUN_00c64c40_object*>(local2)->m_p18;
            m18 = pkLink;
            if (m18 != 0)
            {
                m9 = pkLink->m_p08;
                out = 0;
                FNVCtxHelper* pkLinkMap = static_cast<FUN_00c64c40_stream*>(a1)->m_pkLinkMap;
                if (pkLinkMap != 0 && m9 != 0)
                {
                    reinterpret_cast<::fnv_00853130::NiTMapBase *>(pkLinkMap)->FUN_00853130((uintptr_t)(m9), (*(::fnv_00853130::CombatThreatRecord * *)(&out)));
                }
                if (out != 0)
                {
                    reinterpret_cast<::StrArr *>(&m_kList)->FUN_00c4c8d0((*(char * *)(&local2)));
                    return true;
                }
            }
        }
    }
    return false;
}

namespace fnv_00c64d10 {
struct C64D10_Handle
{
    const char* m_uiFilterValue;
    C64D10_Handle(const C64D10_Handle& other) : m_uiFilterValue(other.m_uiFilterValue)
    {}
    ~C64D10_Handle();
};
struct FUN_00c64d10
{
    C64D10_Handle m_pHeadNode;
    C64D10_Handle m_iSecondInteger;
    FUN_00c64d10(intptr_t first, intptr_t second);
};
// @fnv 0x00c64d10
FUN_00c64d10::FUN_00c64d10(intptr_t first, intptr_t second) : m_pHeadNode((*reinterpret_cast<::fnv_00c64d10::C64D10_Handle *>(&::DAT_0109b220))), m_iSecondInteger((*reinterpret_cast<::fnv_00c64d10::C64D10_Handle *>(&::DAT_0109b220)))
{
    reinterpret_cast<::FUN_00c64da0_cls *>(this)->FUN_00c64da0(first);
    reinterpret_cast<::FUN_00c64dc0_Class *>(this)->FUN_00c64dc0(second);
}
}

// namespace fnv_00c64d10

extern const char* g_c64e70Empty;

struct C64e70Str
{
    const char* m_kHandle;
    ~C64e70Str()
    {
        if (m_kHandle == g_c64e70Empty)
        {
        }
        else
        {
            InterlockedDecrement(&GetGlobalStringHeader(m_kHandle)->m_lRefCount);
        }
    }
};

struct C64e70Elem
{
    C64e70Str m_name;
    C64e70Str m_target;
    ~C64e70Elem()
    {}
};

struct C64e70Array
{
    static void Free(C64e70Elem** p)
    {
        NiFree(p);
    }
    virtual ~C64e70Array()
    {
        Free(m_pBase);
    }
    C64e70Elem** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};

struct C64e70Base
{
    virtual ~C64e70Base();
    int unk04;
    int unk08;
};

struct FUN_00c64e70 : C64e70Base
{
    C64e70Array m_ppData;
    virtual ~FUN_00c64e70();
};

struct FUN_00c64e70_Class
{
    void FUN_00c64e70();
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

// @fnv 0x00c64e70
FUN_00c64e70::~FUN_00c64e70()
{
    unsigned int count = m_ppData.m_usESize;
    for (unsigned int i = 0; i < count; i++)
    {
        delete m_ppData.m_pBase[i];
    }
    m_ppData.RemoveAll();
}

namespace fnv_00c65490 {
struct C65490_Pool
{
};
struct FUN_00c64d10
{
    const char* m_pHeadNode;
    const char* m_iSecondInteger;
    FUN_00c64d10(intptr_t first, intptr_t second);
};
struct C65490_List
{
};
struct C65490_Owner
{
    int unk00;
    int unk04;
    int unk08;
    C65490_List m_kNode;
    void FUN_00c65490(intptr_t first, intptr_t second);
};
// @fnv 0x00c65490
void C65490_Owner::FUN_00c65490(intptr_t first, intptr_t second)
{
    FUN_00c64d10* item = new FUN_00c64d10(first, second);
    reinterpret_cast<::StrArr *>(&(m_kNode))->FUN_00c4c8d0((char *&)(item));
}
}

// Calls FUN_00a7b330 with a8 and cc, then for each of the m18 pairs in m10 calls FUN_00c65490 on the pair's key and value.
// @fnv 0x00c64fd0
void DispatchStub_c64::DispatchToItems(intptr_t pTarget, intptr_t cc)
{
    reinterpret_cast<FUN_00a7b330_shell*>(this)->FUN_00a7b330((::NiBinaryExtraData *)(void *)((void*)pTarget), (::CloningProcess *)(void *)((void*)cc));
    unsigned int count = m18;
    for (unsigned int i = 0; i < count; i++)
    {
        DispatchStub_c64_pair* item = m10[i];
        reinterpret_cast<::fnv_00c65490::C65490_Owner *>((reinterpret_cast<ItemCallee_c64*>(pTarget)))->FUN_00c65490((intptr_t)&item->m_pcKey, (intptr_t)&item->m_pcValue);
    }
}

// namespace fnv_00c65490

namespace fnv_00c65530 {
struct DynamicMemoryAllocator
{
};

struct AtpRef
{
    const char* m_uiFilterValue;
    AtpRef(const char* s)
    {
        if (s == 0)
            m_uiFilterValue = ::DAT_0109b220;
        else
            m_uiFilterValue = ::NiGlobalStringTable::AddString(s);
    }
};


// @fnv 0x00c65530
void __cdecl FUN_00c65530()
{
    (*reinterpret_cast<::fnv_00c65530::AtpRef * *>((void *)&::DAT_012043ec)) = new AtpRef("ATP");
}
}

// namespace fnv_00c65530

namespace fnv_00c655d0 {
struct FixedStringAllocator
{
};
class NiFixedString
{
  public:
    const char* m_pcString;
    inline ~NiFixedString()
    {
        if (m_pcString == ::DAT_0109b220)
            return;
        InterlockedDecrement(&GetGlobalStringHeader(m_pcString)->m_lRefCount);
    }
};
// @fnv 0x00c655d0
void FUN_00c655d0()
{
    delete (*reinterpret_cast<::fnv_00c655d0::NiFixedString * *>((void *)&::DAT_012043ec));
    (*reinterpret_cast<::fnv_00c655d0::NiFixedString * *>((void *)&::DAT_012043ec)) = 0;
}
}

// namespace fnv_00c655d0

void __cdecl FUN_00aa10f0(void* p);




// @fnv 0x00c613a0
C613A0_Extra::~C613A0_Extra()
{}

struct SetAtRefObject
{
    virtual ~SetAtRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

typedef NiPointer<SetAtRefObject> SetAtPointer;

struct SetAtArray
{
    void* m_ppVirtualMethodTable;
    SetAtPointer* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00c62b90(unsigned int uiIndex, const SetAtPointer& element);
};

// @fnv 0x00c61c50
void FUN_00c61c50_cls::FUN_00c61c50(uintptr_t x, uintptr_t y)
{
    unsigned int pad[0xf];
    reinterpret_cast<::NiPSysBoxEmitterWrapper *>(this)->FUN_00c31b10((::NiPSysModifier *)(x), (*(::CloningProcess *)(y)));
    unsigned int n = m_66;
    if (n != 0)
    {
        ((::PtrArray< ::NiPtr< ::RefObj>>*)(x + 0x5c))->FUN_00c628c0(n);
        while (n-- != 0)
        {
            reinterpret_cast<::SetAtArray *>((((::PtrArray< ::NiPtr< ::RefObj>>*)(x + 0x5c))))->FUN_00c62b90(n, (*(const ::NiPointer< ::SetAtRefObject> *)(&m_60[n])));
        }
    }
}

// @fnv 0x00c62cc0
unsigned int S_00c62cc0_Class::FUN_00c62cc0(uintptr_t uiValue)
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

// @fnv 0x00c62b90
void SetAtArray::FUN_00c62b90(unsigned int uiIndex, const SetAtPointer& element)
{
    static SetAtPointer kNull(0);
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != kNull)
            m_usESize++;
    }
    else
    {
        if (element != kNull)
        {
            if (m_pBase[uiIndex] == kNull)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != kNull)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}



class S00c62f40_RefObject
{
  public:
    virtual void vf00();
    virtual void vf04();

    int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)(&m_uiRefCount)) == 0)
            vf04();
    }
};

class S00c62f40_Pointer
{
  public:
    __forceinline S00c62f40_Pointer(S00c62f40_RefObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
        {
            m_pObject->IncRefCount();
        }
    }

    __forceinline ~S00c62f40_Pointer()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }

    S00c62f40_Pointer& FUN_006e5cc0(const S00c62f40_Pointer& source)
    {
        if (m_pObject != source.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = source.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    S00c62f40_RefObject* m_pObject;
};

class S00c62f40_Array
{
  public:
    void* m_ppVirtualMethodTable;
    S00c62f40_Pointer* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00c62f40();
};

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
        reinterpret_cast<::FUN_00a59c60_cls *>((pItem))->FUN_00a59c60((std::intptr_t)(&val));
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

// @fnv 0x00c62f40
void S00c62f40_Array::FUN_00c62f40()
{
    unsigned short index;

    for (index = 0; index < m_usSize; ++index)
    {
        {
            m_pBase[index].FUN_006e5cc0(S00c62f40_Pointer());
        }
    }

    m_usSize = 0;
    m_usESize = 0;
}

namespace fnv_00c63b40 {
struct BaseB3
{
    virtual ~BaseB3();
    int unk04, unk08, unk0c, unk10;
};
struct MidB3 : BaseB3
{
    __forceinline virtual ~MidB3()
    {}
};
struct ListBaseB3
{
    __forceinline ~ListBaseB3()
    {}
};
struct ListB3 : ListBaseB3
{
    int unk00, unk04, unk08;
    __forceinline ~ListB3()
    {
        int a, b, c;
        reinterpret_cast<::fnv_00c64710::FUN_00c64710_Class *>(this)->FUN_00c64710();
    }
};
struct MMB3
{
};
struct FUN_00c63b40 : MidB3
{
    void* unk14[8];
    ListB3 unk34;
    virtual ~FUN_00c63b40();
};
// @fnv 0x00c63b40
FUN_00c63b40::~FUN_00c63b40()
{
    for (int i = 0; i < 8; i++)
    {
        if (unk14[i])
        {
            void* p = unk14[i];
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00c63b40::MMB3 *>(&::g_memoryManager))))->FUN_00aa4060(p);
        }
        unk14[i] = 0;
    }
}
}

// Calls FUN_00c63b40, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c64610
void* FUN_00c64610_Class::FUN_00c64610(unsigned int flags)
{
    reinterpret_cast<::fnv_00c63b40::FUN_00c63b40 *>(this)->fnv_00c63b40::FUN_00c63b40::~FUN_00c63b40();
    if (flags & 1)
        operator delete(this, 0x40);
    return this;
}

// namespace fnv_00c63b40

struct V3Op : V3
{
    V3Op ApplyScaled(float f) const;
    void Scale(float f)
    {
        reinterpret_cast<::MyPoint439180 *>(this)->FUN_00439180(f);
    }
};

struct M68Q
{
    V3Op FUN_004b4500(const V3Op& v) const;
};

struct NodeQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NodeQ* m_pkParent;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    M68Q k68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    V3Op kPos;
};

struct CamQ
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    float f98;
};

inline void Dead3()
{
    int d1;
    int d2;
    int d3;
}

inline void Dead6()
{
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
}

inline float Rand01()
{
    return std::rand() / 32767.0;
}

// @fnv 0x00c62470
void FUN_00c62390_cls::FUN_00c62470(void* a, void* b, void* c)
{
    if (a)
    {
        NodeQ* pParent = static_cast<NodeQ*>(a)->m_pkParent;
        if (GetMode() != 1 && pParent)
        {
            *(V3Op*)b = (*(::V3Op *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(((NodeQ*)a)->kPos))->FUN_00439ef0((::NiPoint3 *)&(pParent->kPos), *(const ::NiPoint3 *)nullptr)));
            Dead3();
            *(V3Op*)b = (*(::V3Op *)(reinterpret_cast<::Point3Offset *>((void *)&(pParent->kPos))->ProjectileLaunched((::NiPoint3 *)&(const ::V3Op &)(((V3Op*)b)->ApplyScaled(Rand01())), {})));
            Dead6();
            if (unk10)
            {
                float fScale = ((CamQ*)unk10)->f98;
                if (fScale != 1.0 && fScale != 0.0)
                    ((V3Op*)b)->Scale(1.0f / fScale);
            }
        }
        else
        {
            *(V3Op*)b = ((NodeQ*)a)->kPos;
            if (GetMode() == 1)
                *(V3Op*)c = ((NodeQ*)a)->k68.FUN_004b4500(*(V3Op*)c);
            Dead3();
        }
    }
    else
    {
        *(V3*)b = *(V3*)&(*reinterpret_cast<unsigned char *>((void *)&::NiPoint3::ZERO));
    }
}

struct ExtraDataBase850
{
    virtual ~ExtraDataBase850();
    void* m_pcName;
    void* m_pNext;
    ExtraDataBase850(const NiFixedString& kName);
};

struct ExtraData850 : ExtraDataBase850
{
    ExtraData850(const NiFixedString& kName) : ExtraDataBase850(kName)
    {}
    virtual ~ExtraData850();
};

// @fnv 0x00c61850
ExtraData850* __cdecl FUN_00c61850()
{
    ExtraData850* pkData = new ExtraData850(*(*reinterpret_cast<::NiFixedString * *>(&::fnv_00c61990::DAT_012043ac)));
    ::AssignFixedString((char *)(pkData), (intptr_t)&(::DAT_011f49e0), {});
    return pkData;
}

struct FUN_00c656b0
{
    NiFixedString m_kName;
    NiFixedString m_kValue;
    ~FUN_00c656b0();
};

// @fnv 0x00c656b0
FUN_00c656b0::~FUN_00c656b0()
{}

namespace fnv_00c618f0 {
struct Pool_11f6238
{
};

extern const char str_010c36b0[];
void __cdecl FUN_00401030(void* buffer);

class NiFixedString
{
  public:
    char* m_handle;

    NiFixedString(const char* text)
    {
        if (!text)
            m_handle = ::DAT_0109b220;
        else
            m_handle = ::NiGlobalStringTable::AddString(text);
    }



};


// @fnv 0x00c618f0
void FUN_00c618f0()
{
    (*reinterpret_cast<::fnv_00c618f0::NiFixedString * *>(&::fnv_00c61990::DAT_012043ac)) = new NiFixedString(str_010c36b0);
}
}

// namespace fnv_00c618f0

inline void S61_Pad1()
{
    int a;
}

inline void S61_Pad2()
{
    int a;
    int b;
}

inline void S61_Pad12()
{
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    int a8;
    int a9;
    int a10;
    int a11;
}

struct RefObjV61
{
    virtual void Unk00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPointer61
{
  public:
    T* m_pObject;
    NiPointer61(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer61()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
};

typedef NiPointer61<RefObjV61> Ptr61;

struct CloneMap61
{
};

struct Cloning61
{
    CloneMap61* m_pCloneMap;
};

struct PtrArray61
{
    void* vtbl;
    Ptr61* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    Ptr61& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
    Ptr61 FUN_00c62d10(unsigned int i);
};

struct Base61
{
};

struct Emitter61 : Base61
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    PtrArray61 m_kArray;
    void FUN_00c61cc0(Cloning61& kCloning);
};

// @fnv 0x00c61cc0
void Emitter61::FUN_00c61cc0(Cloning61& kCloning)
{
    reinterpret_cast<::FUN_00c31c90_shell *>(this)->FUN_00c31c90((::CloningProcess *)&(kCloning));
    void* pkClone4;
    Emitter61* pkDest9;
    bool bCloned3 = reinterpret_cast<::A54440Hash *>((kCloning.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)(void *)(this), (::A54440Manager **)&(pkClone4));
    if (bCloned3)
    {
        pkDest9 = (Emitter61*)pkClone4;
        unsigned int uiCount4 = pkDest9->m_kArray.GetSize();
        unsigned int uiFound2 = 0;
        while (uiCount4--)
        {
            void* pkNew;
            S61_Pad2();
            bool bNewA = reinterpret_cast<::A54440Hash *>((kCloning.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)(void *)(pkDest9->m_kArray.GetAt(uiCount4)), (::A54440Manager **)&(pkNew));
            if (bNewA)
            {
                uiFound2++;
                S61_Pad2();
                Ptr61 spNew3 = (RefObjV61*)pkNew;
                S61_Pad1();
                reinterpret_cast<::SetAtArray *>(&(pkDest9->m_kArray))->FUN_00c62b90(uiCount4, (const ::NiPointer< ::SetAtRefObject> &)(spNew3));
            }
            else
            {
                pkDest9->m_kArray.FUN_00c62d10(uiCount4);
            }
        }
        S61_Pad12();
        if (uiFound2 != pkDest9->m_kArray.GetSize())
            reinterpret_cast<::CmpPtrArray *>(&(pkDest9->m_kArray))->FUN_00c63030();
    }
}

struct NiRTTI;




size_t _strlen(const char*);

struct VirtualResult
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

class __declspec(align(16)) AlignedOwnerNode
{
  public:
    AlignedOwnerNode(AlignedOwnerNode* owner);
    ~AlignedOwnerNode();

    int m_000;
    int m_004;
    int m_008;
    int m_00c;
    int m_010;
    int m_014;
    int m_018;
    int m_01c;
    char m_20[8];
    int m_028;
    int m_02c;
    int m_030;
    int m_034;
    int m_038;
    int m_03c;
    int m_040;
    int m_044;
    int m_048;
    int m_04c;
    int m_050;
    int m_054;
    int m_058;
    int m_05c;
    int m_060;
    int m_064;
    int m_068;
    int m_06c;
    int m_070;
    int m_074;
    int m_078;
    int m_07c;
    int m_080;
    int m_084;
    int m_088;
    int m_08c;
    int m_090;
    int m_094;
    int m_098;
    int m_09c;
    int m_0a0;
    int m_0a4;
    int m_0a8;
    int m_0ac;
    int m_0b0;
    int m_0b4;
    int m_0b8;
    int m_0bc;
    int m_0c0;
    int m_0c4;
    int m_0c8;
    int m_0cc;
    int m_0d0;
    int m_0d4;
    int m_0d8;
    int m_0dc;
    int m_0e0;
    int m_0e4;
    int m_0e8;
    int m_0ec;
    int m_0f0;
    int m_0f4;
    int m_0f8;
    int m_0fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    int m_2c4;
    int m_2c8;
    int m_2cc;
    int m_2d0;
    int m_2d4;
    int m_2d8;
    int m_2dc;
    int m_2e0;
    int m_2e4;
    int m_2e8;
    int m_2ec;
    int m_2f0;
    int m_2f4;
    int m_2f8;
    int m_2fc;
    int m_300;
    int m_304;
    int m_308;
    int m_30c;
    int m_310;
    int m_314;
    int m_318;
    int m_31c;
    int m_320;
    int m_324;
    int m_328;
    int m_32c;
    int m_330;
    int m_334;
    int m_338;
    int m_33c;
    int m_340;
    int m_344;
    int m_348;
    int m_34c;
    int m_350;
    int m_354;
    int m_358;
    int m_35c;
    int m_360;
    int m_364;
    int m_368;
    int m_36c;
    int m_370;
    int m_374;
    int m_378;
    int m_37c;
    int m_380;
    int m_384;
    int m_388;
    int m_38c;
    int m_390;
    int m_394;
    int m_398;
    int m_39c;
    int m_3a0;
    int m_3a4;
    int m_3a8;
    int m_3ac;
    int m_3b0;
    int m_3b4;
    int m_3b8;
    int m_3bc;
    int m_3c0;
    int m_3c4;
};

class ProxyBase
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual VirtualResult* v37();
    virtual void v38();
    int m_04;
    void* m_08;
    int m_0c;
};

class CharacterProxy : public ProxyBase
{
  public:
    AlignedOwnerNode m_kPoints;

    void FUN_00c6cf30(uintptr_t formID);
};

struct PointLoader
{
};

// @fnv 0x00c6cf30
void CharacterProxy::FUN_00c6cf30(uintptr_t formID)
{
    volatile uintptr_t id = formID;
    reinterpret_cast<::FUN_00cac110_Class *>((this))->FUN_00cac110();
    if (this)
    {
        PointLoader* loader = (PointLoader*)this->m_08;
        if (loader)
        {
            AlignedOwnerNode tmp(&this->m_kPoints);
            VirtualResult* result = this->v37();
            reinterpret_cast<::FUN_00cafbd0_Class *>((loader))->FUN_00cafbd0((const void*)id, &result->m_10, &tmp, &this->m_kPoints);
            reinterpret_cast<::TriggerCollector *>(&(this->m_kPoints))->ProcessContactEvents();
        }
    }
    reinterpret_cast<::FUN_00cac110_Class *>((this))->FUN_00cac110();
}


struct hkVector4
{
    __m128 m_vComponents;
};

extern float DAT_01267e30;

struct hkpShapeInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_flags;
};

struct hkpShape
{
    int unk00;
    int unk04;
    hkpShapeInfo* m_info;
};

class hkpCdBody
{
  public:
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;

    const hkpCdBody* getRootCollidable() const
    {
        const hkpCdBody* body = this;
        while (body->m_parent)
        {
            body = body->m_parent;
        }
        return body;
    }
};

struct hkpCollidable : hkpCdBody
{
    signed char m_iOwnerOffset;
    char unk11;
    short unk12;
    int m_broadPhaseId;
    char m_type;
    char unk19;
    short unk1a;
    unsigned int m_uiCollisionFilterData;

    void* getOwner() const
    {
        return (void*)((char*)this + m_iOwnerOffset);
    }
};

struct hkpRigidBody
{
    int unk000;
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
    hkVector4 m_kTranslationalVelocity;

    const hkVector4& getLinearVelocity() const
    {
        return m_kTranslationalVelocity;
    }
};

__forceinline hkpRigidBody* hkGetRigidBody(const hkpCollidable* collidable)
{
    if (collidable->m_type == 1)
    {
        return (hkpRigidBody*)collidable->getOwner();
    }
    return 0;
}

struct MaterialSource
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual int getMaterial(unsigned int shapeKey);
};

inline bool IsSpecialMaterial(int material)
{
    if (!DAT_01267bc8)
    {
        return false;
    }
    return DAT_01267bc8(material);
}

struct GroundPoint
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    const hkpCdBody* m_kCollidable;
    int m_uiCollisionShapeKey;
};

struct GroundController
{
    int unk000;
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
    unsigned int m_flags;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int m_iMaterialIndex;
    int m_layer;
    int unk43c;
    hkVector4 m_fVelocity;

    void SetFlag(unsigned int uiMask, bool bSet)
    {
        if (bSet)
        {
            m_flags |= uiMask;
        }
        else
        {
            m_flags &= ~uiMask;
        }
    }
    bool GetFlag(unsigned int uiMask) const
    {
        return (m_flags & uiMask) != 0;
    }

    void FUN_00c6e980(const GroundPoint* point);
};

// @fnv 0x00c6e980
void GroundController::FUN_00c6e980(const GroundPoint* point)
{
    if (m_iMaterialIndex == 0xf)
    {
        return;
    }
    const hkpCdBody* body = point->m_kCollidable;
    int material = 0x24;
    if (!body)
    {
        return;
    }
    int layer = ((const hkpCollidable*)body->getRootCollidable())->m_uiCollisionFilterData & 0x7f;
    m_layer = layer;
    hkpRigidBody* rb = hkGetRigidBody((const hkpCollidable*)body->getRootCollidable());
    const hkVector4* velocity = rb ? &rb->getLinearVelocity() : (const hkVector4*)&DAT_01267e30;
    m_fVelocity.m_vComponents = velocity->m_vComponents;

    if (point->m_uiCollisionShapeKey == -1)
    {
        const hkpShape* shape = body->m_pCollisionShape;
        if (shape && shape->m_info)
        {
            material = shape->m_info->m_flags & 0x1f;
        }
    }
    else if (layer != 0x11)
    {
        MaterialSource* src = ((::MaterialSource *)(::FUN_00c7ffd0((::XRef *)(body))));
        if (src)
        {
            material = src->getMaterial(point->m_uiCollisionShapeKey);
        }
    }

    if (m_iMaterialIndex == 0x24 || material == 0xf)
    {
        m_iMaterialIndex = material;
        bool b = false;
        if (DAT_01267bc8)
        {
            b = DAT_01267bc8(material);
        }
        _ReadWriteBarrier();
        if (b)
        {
            m_flags |= 0x1000000;
        }
        else
        {
            m_flags &= ~0x1000000;
        }
        _ReadWriteBarrier();
        if (((unsigned char)(m_flags >> 16) & 1) || material == 0xf)
        {
            _ReadWriteBarrier();
            if (m_iMaterialIndex == 0xf)
            {
                m_flags |= 0x20000;
            }
            else
            {
                m_flags &= ~0x20000;
            }
        }
    }
}

namespace fnv_00c741e0 {

union T741_V
{
    __forceinline T741_V(const __m128& q)
    {
        m_vComponents = q;
    }
    __m128 m_vComponents;
    float m_f[4];
    unsigned char m_kPointB[16];
};

struct T741_Src
{
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int fa4;
    float fa8;
    float fac;
};


struct T741_B0
{
    T741_B0();
    virtual ~T741_B0();
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    int f0e0;
    int f0e4;
    int f0e8;
    int f0ec;
    int f0f0;
    int f0f4;
    int f0f8;
    int f0fc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    int f168;
    int f16c;
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    int f228;
    int f22c;
    int f230;
    int f234;
    int f238;
    int f23c;
    int f240;
    int f244;
    int f248;
    int f24c;
    int f250;
    int f254;
    int f258;
    int f25c;
    int f260;
    int f264;
    int f268;
    int f26c;
    int f270;
    int f274;
    int f278;
    int f27c;
    int f280;
    int f284;
    int f288;
    int f28c;
    int f290;
    int f294;
    int f298;
    int f29c;
    int f2a0;
    int f2a4;
    int f2a8;
    int f2ac;
    int f2b0;
    int f2b4;
    int f2b8;
    int f2bc;
    int f2c0;
    int f2c4;
    int f2c8;
    int f2cc;
    int f2d0;
    int f2d4;
    int f2d8;
    int f2dc;
    int f2e0;
    int f2e4;
    int f2e8;
    int f2ec;
    int f2f0;
    int f2f4;
    int f2f8;
    int f2fc;
    int f300;
    int f304;
    int f308;
    int f30c;
    int f310;
    int f314;
    int f318;
    int f31c;
    int f320;
    int f324;
    int f328;
    int f32c;
    int f330;
    int f334;
    int f338;
    int f33c;
    int f340;
    int f344;
    int f348;
    int f34c;
    int f350;
    int f354;
    int f358;
    int f35c;
    int f360;
    int f364;
    int f368;
    int f36c;
    int f370;
    int f374;
    int f378;
    int f37c;
    int f380;
    int f384;
    int f388;
    int f38c;
    int f390;
    int f394;
    int f398;
    int f39c;
    int f3a0;
    int f3a4;
    int f3a8;
    int f3ac;
    int f3b0;
    int f3b4;
    int f3b8;
    int f3bc;
    int f3c0;
    int f3c4;
    int f3c8;
    int f3cc;
    int f3d0;
    int f3d4;
    int f3d8;
    int f3dc;
};
struct T741_B1
{
    T741_B1(int a, int b);
    virtual ~T741_B1();
    int f3e4;
    int f3e8;
    int f3ec;
    int f3f0;
    int f3f4;
    int f3f8;
    int f3fc;
    int f400;
    int f404;
    int f408;
    int f40c;
};
struct T741_B2a
{
    T741_B2a(const T741_V& v, float a, float b);
    virtual ~T741_B2a();
    int f414;
    int f418;
    int f41c;
    int f420;
    int f424;
    int f428;
    int f42c;
    int f430;
    int f434;
    int f438;
    int f43c;
    int f440;
    int f444;
    int f448;
    int f44c;
    float f450[4];
    __forceinline void Reset()
    {
        f414 = 0;
        *(__m128*)f450 = _mm_setzero_ps();
    }
};
struct T741_B3
{
    int f460;
    int f464;
    int f468;
    int f46c;
    int f470;
    int f474;
    int f478;
    int f47c;
    int f480;
    int f484;
    int f488;
    int f48c;
    float f490[4];
    float f4a0[4];
    float f4b0;
    bool f4b4;
    int f4b8;
    int f4bc;
    __forceinline T741_B3()
    {
        f4b0 = 0.0f;
        _mm_store_ps(f490, _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f));
        f480 = 2;
        _mm_store_ps(f4a0, _mm_setr_ps(0.0f, 0.0f, 0.0f, 0.0f));
        f4b4 = false;
    }
};
struct T741_M3
{
    float f4c0[4];
    float f4d0[4];
    int f4e0;
    int f4e4;
    int f4e8;
    int f4ec;
    int f4f0;
    int f4f4;
    int f4f8;
    int f4fc;
    __forceinline T741_M3()
    {
        _mm_store_ps(f4c0, _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f));
        _mm_store_ps(f4d0, _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f));
    }
    ~T741_M3();
};
struct T741_M4
{
    float f500[4];
    int f510;
    int f514;
    int f518;
    int f51c;
    int f520;
    float f524;
    float f528;
    float f52c;
    float f530;
    float f534;
    float f538;
    int f53c;
    int f540;
    float f544;
    float f548;
    float f54c;
    float f550;
    float f554;
    float f558;
    int f55c;
    int f560;
    int f564;
    int f568;
    int f56c;
    float f570[4];
    int f580;
    int f584;
    int f588;
    int f58c;
    int f590;
    int f594;
    int f598;
    __forceinline T741_M4()
    {
        _mm_store_ps(f500, (*reinterpret_cast<__m128 *>(&::DAT_01267e30)));
        f520 = 0;
        f524 = 0.0f;
        f528 = 0.0f;
        f52c = 0.0f;
        f530 = 0.0f;
        f534 = 0.0f;
        f538 = 0.0f;
        f544 = 0.0f;
        f548 = 0.0f;
        f54c = 1.0f;
        f550 = 0.0f;
        f554 = 0.0f;
        f558 = 1.0f;
        _mm_store_ps(f570, (*reinterpret_cast<__m128 *>(&::DAT_01267e30)));
        f594 = 0;
        f598 = 0;
    }
    ~T741_M4();
};
struct T741_E
{
    int v;
    T741_E();
    ~T741_E();
};
struct T741_M6
{
    float f5f0;
    float f5f4;
    float f5f8;
    float f5fc;
    int f600;
    int f604;
    int f608;
    __forceinline T741_M6()
    {
        f5f0 = 2.0f;
        f600 = 0;
        f5f4 = 10.0f;
        f604 = 0;
        f5f8 = 2.0f;
        f608 = 0;
        f5fc = -1.0f;
    }
    ~T741_M6();
};
struct T741_M7
{
    float f620[4];
    int f630;
    __forceinline T741_M7()
    {
        _mm_store_ps(f620, (*reinterpret_cast<__m128 *>(&::DAT_01267e30)));
        f630 = 0;
    }
    ~T741_M7();
};
struct T741_M8
{
    float f634;
    int f638;
    __forceinline T741_M8()
    {
        f634 = 0.0f;
        f638 = 0;
    }
    ~T741_M8();
};
struct T741_Arr
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline T741_Arr()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
        int n = 5;
        int bytes = n * 112;
        void* data = hkMemoryRouter::getInstance().heap().bufAlloc(bytes);
        n = bytes / 112;
        int cap = n;
        if (!n)
            cap = 0x80000000;
        m_data = data;
        m_iElementCount = n;
        m_cap = cap;
    }
    ~T741_Arr();
};
struct T741_M10
{
    int f648;
    int f64c;
    __forceinline T741_M10()
    {
        f648 = 0;
        f64c = 0;
    }
    ~T741_M10();
};
struct T741_Guard
{
    int m_old;
    __forceinline T741_Guard()
    {
        m_old = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 0x10;
    }
    __forceinline ~T741_Guard()
    {
        g_tlsBlock.memoryContext = m_old;
    }
};

struct FUN_00c741e0 : T741_B0, T741_B1, T741_B2a, T741_B3
{
    T741_M3 m4c0;
    T741_M4 m500;
    int f59c;
    int f5a0;
    T741_E m5a4[2];
    int f5ac;
    int f5b0;
    int f5b4;
    int f5b8;
    int f5bc;
    int f5c0;
    int f5c4;
    int f5c8;
    int f5cc;
    int f5d0;
    int f5d4;
    int f5d8;
    int f5dc;
    int f5e0;
    int f5e4;
    int f5e8;
    int f5ec;
    T741_M6 m5f0;
    int f60c;
    bool f610;
    int f614;
    int f618;
    int f61c;
    T741_M7 m620;
    T741_M8 m630;
    T741_Arr m63c;
    T741_M10 m648;
    FUN_00c741e0(T741_Src* p);
    virtual ~FUN_00c741e0();
};

// @fnv 0x00c741e0
FUN_00c741e0::FUN_00c741e0(T741_Src* p)
    : T741_B1(p->fa4, p->f09c),
      T741_B2a(T741_V(_mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f)), (float)(::DAT_011b0148 * ::DAT_01023128), p->fac * p->fa8),
      f59c(2), f5a0(2), f60c(0), f610(false)
{
    T741_Guard guard;
    Reset();
    m63c.m_iElementCount = 0;
    reinterpret_cast<::ControllerC73 *>(this)->FUN_00c73ed0((::InputC73 *)(p));
}
}

// namespace fnv_00c741e0

namespace fnv_00c66320 {

static __forceinline void multiply(__m128* out, const __m128* a, const __m128* b);

// @fnv 0x00c66320
void FUN_00c66320(__m128* out, void*, const __m128* a, const __m128* b)
{
    __declspec(align(16)) char result[16];
    __m128 value;
    multiply(&value, a, b);
    _mm_store_ps((float*)result, value);
    *out = _mm_load_ps((const float*)result);
}

static __forceinline void multiply(__m128* out, const __m128* a, const __m128* b)
{
    __m128 x = *a;
    __m128 y = *b;
    __m128 t0 = _mm_shuffle_ps(x, x, 0xd2);
    __m128 t1 = _mm_shuffle_ps(y, y, 0xc9);
    t1 = _mm_mul_ps(t1, t0);
    __m128 t2 = _mm_shuffle_ps(x, x, 0xc9);
    t0 = _mm_shuffle_ps(y, y, 0xd2);
    t0 = _mm_mul_ps(t0, t2);
    t0 = _mm_sub_ps(t0, t1);
    t1 = _mm_shuffle_ps(x, x, 0xff);
    t1 = _mm_shuffle_ps(t1, t1, 0);
    t1 = _mm_mul_ps(t1, y);
    t1 = _mm_add_ps(t1, t0);
    t0 = _mm_shuffle_ps(y, y, 0xff);
    y = _mm_mul_ps(y, x);
    t0 = _mm_shuffle_ps(t0, t0, 0);
    t0 = _mm_mul_ps(t0, x);
    t0 = _mm_add_ps(t0, t1);
    t1 = _mm_shuffle_ps(y, y, 0x55);
    t1 = _mm_add_ss(t1, y);
    x = _mm_shuffle_ps(y, y, 0xaa);
    x = _mm_add_ss(x, t1);
    t1 = t0;
    x = _mm_shuffle_ps(x, x, 0);
    y = _mm_sub_ps(y, x);
    t0 = _mm_unpackhi_ps(t0, y);
    *out = _mm_shuffle_ps(t1, t0, 0xc4);
}
}

// namespace fnv_00c66320

extern unsigned char DAT_012677cc;

extern float DAT_011afe78, DAT_011afe74, DAT_012677c4;

extern char str_010c41fc[];

extern int DAT_010c3bd4;



struct Result;

union Scratch
{
    float threshold;
    Result* result;
    volatile unsigned int stamp;
};

struct TraceBool
{
    char value;
    TraceBool(bool b)
    {
        value = (char)b;
    }
    operator bool() const
    {
        return value != 0;
    }
};

struct TraceEntry
{
    const char* tag;
    unsigned int time;
    unsigned int extra;
    void SetTime()
    {
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        time = stamp;
    }
};

struct TraceBuffer
{
    int unk00;
    TraceEntry* current;
    int unk08;
    TraceEntry* end;
    static TraceBuffer& GetInstance()
    {
        return *(TraceBuffer*)TlsGetValue(DAT_0126835c);
    }
    TraceBool MemoryAvailable() const
    {
        return current < end;
    }
    TraceEntry* Expand()
    {
        TraceEntry* e = current;
        return e;
    }
};

inline void TraceBegin(const char* tag, Scratch& scratch)
{
    TraceBuffer& stream = TraceBuffer::GetInstance();
    if (stream.MemoryAvailable())
    {
        TraceEntry* e = stream.Expand();
        e->tag = tag;
        _ReadWriteBarrier();
        scratch.stamp = (unsigned int)__rdtsc();
        e->time = scratch.stamp;
        stream.current = e + 1;
    }
}

inline void TraceEnd(const char* tag, Scratch& scratch)
{
    TraceBuffer& stream = TraceBuffer::GetInstance();
    if (stream.MemoryAvailable())
    {
        TraceEntry* e = stream.Expand();
        e->tag = tag;
        _ReadWriteBarrier();
        scratch.stamp = (unsigned int)__rdtsc();
        e->time = scratch.stamp;
        stream.current = e + 1;
    }
}

struct Result
{
    int field00;
    int field04;
    int field08;
    int field0c;
    float field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    void Clear()
    {
        field10 = 1.0f;
        field50 = 0;
        field14 = -1;
        field40 = 0;
        field20 = -1;
    }
};

struct Collector
{
    int field00;
    float fraction;
    int field08, field0c;
    Result result;
    void Finalize();
};

struct Query
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    Result result;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    void* filter;
    Collector* collector;
    struct HitResultList* hits;
    bool disabled;
};

struct HitResultList
{
    int field00, field04, field08, field0c;
    Result* result;
    int count;
};

struct World
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    void* field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    void* field7c;
};

struct __declspec(align(16)) CastVector
{
    float x, y, z, w;
};

struct CastCollectorBase
{
    int* vtable;
    ~CastCollectorBase()
    {
        vtable = &DAT_010c3bb8;
    }
};

struct __declspec(align(16)) WorldRayCaster : CastCollectorBase
{
    int field04;
    int field08;
    int field0c;
    CastVector from;
    CastVector to;
    CastVector direction;
    int field40;
    int field44;
    WorldRayCaster()
    {
        vtable = &DAT_010c3bd4;
        field40 = 0;
        field44 = 0;
    }
};

struct FilterCast : WorldRayCaster
{
    __forceinline FilterCast(World* world, Query* query, void* cache, void* collector)
    {
        void* mode = world->field7c;
        reinterpret_cast<::CbfOwner *>(this)->FUN_00cbf860((::CbfTarget *)(world->field58), (::CbfSrc *)(query), (int *)(mode), (intptr_t)(cache), (intptr_t)(collector));
    }
};

struct RayCaster
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual World* GetWorld();
    bool FUN_00c696d0(Query* query);
};

// @fnv 0x00c696d0
bool RayCaster::FUN_00c696d0(Query* query)
{
    __declspec(align(16)) unsigned char storage[sizeof(FilterCast)];
    Scratch scratch;
    if (!DAT_012677a3)
    {
        scratch.threshold = DAT_012677cc ? DAT_011afe78 : DAT_011afe74;
        if (DAT_012677c4 > scratch.threshold)
        {
            query->disabled = true;
            query->result.Clear();
            return false;
        }
    }
    TraceBegin(str_010c41fc, scratch);
    bool found = false;
    World* world = GetWorld();
    if (world)
    {
        reinterpret_cast<::FUN_00458840_Class *>((query))->FUN_00458840();
        scratch.result = &query->result;
        scratch.result->Clear();
        HitResultList* hits = query->hits;
        if (hits)
        {
            void* cache = query->filter;
            if (cache)
            {
                ((FilterCast*)storage)->FilterCast::FilterCast(world, query, cache, hits);
            }
            else
                reinterpret_cast<::fnv_00c91f70::RayWorld *>((world))->FUN_00c91f70(query, hits);
            if (hits->count)
            {
                reinterpret_cast<::FUN_00c855f0_cls *>((hits))->FUN_00c855f0();
                Result* hit = hits->result;
                reinterpret_cast<::FUN_009c1aa0_Class *>((scratch.result))->FUN_009c1aa0((*(const ::FUN_009c1aa0_Class *)(hit)));
                scratch.result->field50 = hit->field50;
                found = true;
            }
        }
        else
        {
            Collector* collector = query->collector;
            if (collector)
            {
                Result* collected = &collector->result;
                collected->Clear();
                collector->fraction = 1.0f;
                void* cache = query->filter;
                if (cache)
                {
                    ((FilterCast*)storage)->FilterCast::FilterCast(world, query, cache, collector);
                }
                else
                    reinterpret_cast<::fnv_00c91f70::RayWorld *>((world))->FUN_00c91f70(query, collector);
                if (collector->result.field50)
                {
                    reinterpret_cast<::FUN_009c1a70_shell *>((scratch.result))->FUN_009c1a70(collected);
                    found = true;
                }
            }
            else
            {
                reinterpret_cast<::fnv_00c92040::S00c92040_Obj *>((world))->FUN_00c92040((intptr_t)(query), (intptr_t)(scratch.result));
                found = query->result.field50 != 0;
            }
        }
    }
    TraceEnd(::DAT_010c41f8, scratch);
    return found;
}

// hkMatrix4-style copy: assign four 16-byte columns and return *this.

struct hkVector4CD60
{
    __m128 m_vComponents;
    void operator=(const hkVector4CD60& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkMatrix4CD60
{
    hkVector4CD60 m_kColumn0;
    hkVector4CD60 m_kColumn1;
    hkVector4CD60 m_kColumn2;
    hkVector4CD60 m_kColumn3;
    hkMatrix4CD60& FUN_00c6cd60(const hkMatrix4CD60& other);
};

// @fnv 0x00c6cd60
hkMatrix4CD60& hkMatrix4CD60::FUN_00c6cd60(const hkMatrix4CD60& other)
{
    m_kColumn0 = other.m_kColumn0;
    m_kColumn1 = other.m_kColumn1;
    m_kColumn2 = other.m_kColumn2;
    m_kColumn3 = other.m_kColumn3;
    return *this;
}

struct SseBlock
{
    __m128 m_00;
    __m128 m_10;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    int m_30;

    SseBlock& FUN_00c6d670(const SseBlock& o);
};

// @fnv 0x00c6d670
SseBlock& SseBlock::FUN_00c6d670(const SseBlock& o)
{
    m_00 = o.m_00;
    m_10 = o.m_10;
    m_20 = o.m_20;
    m_24 = o.m_24;
    m_28 = o.m_28;
    m_2c = o.m_2c;
    m_30 = o.m_30;
    return *this;
}


struct FxRTTI
{
    const char* m_pcName;
    const FxRTTI* m_pBaseRTTI;
};

extern const double DAT_0102fc70;


struct Vec4
{
    union
    {
        __m128 m_vComponents;
        signed char m_ai8[16];
    };
    __forceinline Vec4()
    {}
    __forceinline Vec4(const Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    __forceinline void operator=(const Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setSub4(const Vec4& a, const Vec4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline float length3() const
    {
        float result;
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), sum);
        _mm_store_ss(&result, _mm_sqrt_ss(sum));
        return result;
    }
    __forceinline void normalize3()
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), sum);
        __m128 inv = _mm_rsqrt_ss(sum);
        __m128 zero = _mm_set_ss(DAT_01011d78);
        __m128 three = _mm_set_ss(DAT_01017718);
        __m128 half = _mm_set_ss(::fnv_00c88020::DAT_01016248);
        __m128 isZero = _mm_cmpeq_ss(sum, zero);
        __m128 r = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(sum, inv), inv));
        r = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(half, inv), r));
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

struct FxString
{
    const char* m_kHandle;
    FxString(const char* pcString)
    {
        if (!pcString)
            m_kHandle = ::DAT_0109b220;
        else
            m_kHandle = ::NiGlobalStringTable::AddString(pcString);
    }
    ~FxString()
    {
        if (m_kHandle != ::DAT_0109b220)
            InterlockedDecrement((volatile long*)((long*)(m_kHandle - 8)));
    }
};

struct FxObject;

struct ExtraData
{
    unsigned unk00, unk04, unk08, unk0c, unk10;
    FxObject* m_pkProperties;
    FxObject** GetProperties()
    {
        return &m_pkProperties;
    }
};

struct CastResult
{
    unsigned unk00, unk04, unk08, unk0c;
    ExtraData* m_pkExtra;
    ExtraData* GetExtra() const
    {
        return m_pkExtra;
    }
};

struct CastObject
{
};

struct FxAVObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual FxAVObject* IsSceneNode();
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18;
    CastObject* m_pkCast;
};

struct FxNode : FxAVObject
{
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    FxNode** m_ppkChildren;
    unsigned short m_usMaxSize, m_usSize;
};

__forceinline FxNode* FirstChild(FxNode* pkNode)
{
    return pkNode && pkNode->IsSceneNode() && pkNode->m_usSize > 0 ? pkNode->m_ppkChildren[0] : 0;
}
__forceinline FxNode* FirstChildP(FxNode* pkNode)
{
    if (!pkNode)
        return pkNode;
    return pkNode->IsSceneNode() && pkNode->m_usSize > 0 ? pkNode->m_ppkChildren[0] : 0;
}
__forceinline FxObject** Properties(FxNode* pkNode)
{
    if (pkNode->m_pkCast)
    {
        CastResult* pkCast = ((::CastResult *)(reinterpret_cast<::NiObject *>((pkNode->m_pkCast))->DynamicCast((const ::NiRTTI *)(const ::FxRTTI *)(&(*reinterpret_cast<const ::FxRTTI *>(&::g_012043f8))))));
        if (pkCast && pkCast->GetExtra())
            return pkCast->GetExtra()->GetProperties();
    }
    return 0;
}

struct SceneObject
{
    unsigned unk00, unk04, unk08, unk0c;
    struct Point
    {
        float x, y, z, w;
    };
    Point origin, end;
};

__forceinline Vec4 DifferenceOf(const SceneObject* o)
{
    Vec4 v;
    v.m_vComponents = _mm_sub_ps(_mm_setr_ps(o->origin.x, o->origin.y, o->origin.z, o->origin.w),
                                 _mm_setr_ps(o->end.x, o->end.y, o->end.z, o->end.w));
    return v;
}
__forceinline Vec4 DifferenceOfMid(const SceneObject* o)
{
    Vec4 v;
    __m128 a = _mm_setr_ps(o->origin.x, o->origin.y, o->origin.z, o->origin.w);
    __m128 b = _mm_setr_ps(o->end.x, o->end.y, o->end.z, o->end.w);
    _ReadWriteBarrier();
    v.m_vComponents = _mm_sub_ps(a, b);
    return v;
}

struct VfxSource
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int Type();
    unsigned unk10, unk14, unk18, unk1c;
    Vec4 m_kInitialDirection;
    unsigned unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    Vec4 m_kFinalDirection;
    unsigned unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    unsigned unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    float m_fOriginAngle;
    float m_fFinalAngle;
};

struct SourceLink
{
    unsigned unk00;
    VfxSource* m_pkSource;
    VfxSource* GetSource() const
    {
        return m_pkSource;
    }
};

struct SourceProperty
{
};

struct ShaderHolder
{
    unsigned unk00, unk04, unk08;
    VfxSource* m_pkSource;
    VfxSource* GetSource() const
    {
        return m_pkSource;
    }
};

struct ShaderLink
{
    unsigned unk00;
    ShaderHolder* m_pkHolder;
    ShaderHolder* GetHolder() const
    {
        return m_pkHolder;
    }
};

struct ShaderProperty
{
};

__forceinline VfxSource* FindSource(FxObject** ppkProperties)
{
    FxObject* pkInitial = *ppkProperties;
    SourceProperty* pkProp = (SourceProperty*)((::FxObject *)(::FUN_00653270((const ::NiRTTI *)(const ::FxRTTI *)(&(*reinterpret_cast<const ::FxRTTI *>(&::g_0126831c))), (::NiObject *)(pkInitial))));
    VfxSource* pkSource = pkProp ? ((::SourceLink *)(reinterpret_cast<::VirtualReader *>((pkProp))->ReadCompleteObject()))->GetSource() : 0;
    if (!pkProp)
    {
        FxObject* pkFallback = *ppkProperties;
        ShaderProperty* pkShader = (ShaderProperty*)((::FxObject *)(::FUN_00653270((const ::NiRTTI *)(const ::FxRTTI *)(&(*reinterpret_cast<const ::FxRTTI *>(&::g_01268310))), (::NiObject *)(pkFallback))));
        if (pkShader)
        {
            ShaderHolder* pkHolder = ((::ShaderLink *)(reinterpret_cast<::VirtualReader *>((pkShader))->ReadCompleteObject()))->GetHolder();
            VfxSource* pkAlt = pkHolder ? pkHolder->GetSource() : 0;
            if (pkAlt && pkAlt->Type() == 2)
                pkSource = pkAlt;
        }
    }
    return pkSource;
}

struct Setting
{
};

extern Setting DAT_01267d98, DAT_01267de0;

struct EffectOutput
{
    unsigned unk00, unk04, unk08, unk0c;
    Vec4 m_kLightVector;
    Vec4 m_kDisplacement;
    unsigned unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    float m_fOriginX, m_fOriginY, m_fOriginZ, m_fAngleZ, m_fAngleX, m_fAngleY;
};

struct EffectName
{
    const char* m_pcText;
};

struct EffectRequest
{
    unsigned unk00;
    EffectName* m_pkName;
};

struct SceneEffect
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    unsigned unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    void* m_pkScene;
    bool FUN_00c77ac0(EffectOutput* pkOutput, EffectRequest* pkRequest);
};

// @fnv 0x00c77ac0
bool SceneEffect::FUN_00c77ac0(EffectOutput* pkOutput, EffectRequest* pkRequest)
{
    struct MidContext
    {
        SceneObject* object;
        float angleY;
        float angleX;
    };
    MidContext context;
    EffectName* pkName = pkRequest->m_pkName;
    FxNode* pkRoot;
    {
        FxString kName(pkName->m_pcText);
        pkRoot = ((::FxNode *)(::FUN_00c4b470((::FUN_00c4b470_owner *)(m_pkScene), (void **)(&kName), 1)));
    }
    FxNode* pkMid = FirstChild(pkRoot);
    _ReadWriteBarrier();
    FxNode* pkEnd = FirstChildP(pkMid);
    if (!pkRoot || !pkMid || !pkEnd)
        return false;

    SceneObject* pkRootObj = ((::SceneObject *)(::FUN_00c75180((::Input134 *)this)));
    context.object = ((::SceneObject *)(::FUN_00c75180((::Input134 *)this)));
    SceneObject* pkEndObj = ((::SceneObject *)(::FUN_00c75180((::Input134 *)this)));
    FxObject** ppkMidProps = Properties(pkMid);
    FxObject** ppkEndProps = Properties(pkEnd);
    if (!pkRootObj || !context.object || !pkEndObj || !ppkMidProps || !ppkEndProps)
        return false;

    VfxSource* pkBase = FindSource(ppkMidProps);
    if (!pkBase)
        return false;

    float fAngleDifference = DAT_01066808 - pkBase->m_fFinalAngle * DAT_0102f248 - DAT_01020758;
    fAngleDifference = fAngleDifference * DAT_01023128;
    fAngleDifference = static_cast<float>(std::cos(static_cast<double>(fAngleDifference)));
    context.angleX = -fAngleDifference;
    fAngleDifference = pkBase->m_fOriginAngle * DAT_0102f248 + DAT_01066808 - DAT_0102fc70;
    fAngleDifference = fAngleDifference * DAT_01023128;
    fAngleDifference = static_cast<float>(std::cos(static_cast<double>(fAngleDifference)));
    context.angleY = fAngleDifference;
    Vec4 kDirection;
    kDirection = pkBase->m_kInitialDirection;

    VfxSource* pkFinal = FindSource(ppkEndProps);
    VfxSource* pkSpecial = 0;
    if (!pkFinal)
    {
        FxObject* pkSpecialObject = *ppkEndProps;
        SourceProperty* pkProp = (SourceProperty*)((::FxObject *)(::FUN_00653270((const ::NiRTTI *)(const ::FxRTTI *)(&(*reinterpret_cast<const ::FxRTTI *>(&::g_0126864c))), (::NiObject *)(pkSpecialObject))));
        pkSpecial = pkProp ? ((::SourceLink *)(reinterpret_cast<::FUN_00c747b0_Class *>((pkProp))->FUN_00c747b0()))->GetSource() : 0;
        if (!pkSpecial)
            return false;
    }
    Vec4 kFinal;
    if (pkFinal)
        kFinal = pkFinal->m_kFinalDirection;
    else
        kFinal = pkSpecial->m_kInitialDirection;
    Vec4 kDisplacement = DifferenceOf(pkEndObj);
    fAngleDifference = *((float *)&(::FUN_00403e20((float *)&(DAT_01267d98)))) + kFinal(0);
    if (pkSpecial)
    {
        DifferenceOf(pkRootObj).length3();
        DifferenceOfMid(context.object).length3();
    }

    EffectOutput* __restrict result = pkOutput;
    result->m_kLightVector = kDirection;
    result->m_kLightVector.normalize3();
    if (kDisplacement.length3() < 0.5f)
        kDisplacement.m_vComponents = _mm_setzero_ps();
    pkOutput->m_kDisplacement = kDisplacement;
    pkOutput->m_fAngleZ = -*((float *)&(::FUN_00403e20((float *)&(DAT_01267de0))));
    pkOutput->m_fOriginZ =
        (context.object->origin.x - context.object->end.x) + 2.0 * pkEndObj->origin.x + fAngleDifference;
    pkOutput->m_fOriginX = pkEndObj->origin.x;
    pkOutput->m_fOriginY = pkOutput->m_fOriginZ - 2.0 * fAngleDifference;
    pkOutput->m_fAngleX = context.angleX;
    pkOutput->m_fAngleY = context.angleY;
    return true;
}

namespace fnv_00c7b1f0 {

// Full SIMD storage views mirror the VC9 intrinsic type; the pack supplies only its float/qword views.
union __declspec(align(16)) Vector_c7
{
    __m128 q;
    unsigned char bytes[16];
    float data[4];
};

struct StringHeader_c7
{
    volatile long refs;
    unsigned int length;
};

struct Root_c7
{
    unsigned int pad00_000;
    unsigned int pad00_001;
    unsigned int pad00_002;
    unsigned int m0c;
    unsigned int pad10_000;
    unsigned int pad10_001;
    unsigned int pad10_002;
    unsigned int m1c;
    unsigned int pad20_000;
    unsigned int pad20_001;
    unsigned int m28;
    unsigned int m2c;
    unsigned int m30;
};

struct Holder_c7
{
    unsigned int pad00_000;
    unsigned int pad00_001;
    Root_c7* root;
};

struct Matrix_c7
{
    __m128 row0, row1, row2;
    Matrix_c7& operator=(const Matrix_c7& r)
    {
        _mm_store_ps((float*)&row0, _mm_load_ps((const float*)&r.row0));
        _mm_store_ps((float*)&row1, _mm_load_ps((const float*)&r.row1));
        _mm_store_ps((float*)&row2, _mm_load_ps((const float*)&r.row2));
        return *this;
    }
};

struct Elem_c7
{
    unsigned int pad00;
    Matrix_c7* m4;
};

struct List_c7
{
    unsigned int pad00_000;
    unsigned int pad00_001;
    unsigned int pad00_002;
    unsigned int pad00_003;
    unsigned int count;
    Elem_c7** items;
    unsigned int pad18_000;
};

struct Cursor_c7
{
    unsigned char* saved;
    unsigned int count;
    Cursor_c7(unsigned int n);
    Cursor_c7(unsigned int n, const int& c, int& result);
    ~Cursor_c7();
};

struct ListPtr_c7
{
    List_c7* data;
    List_c7* operator->() const
    {
        return data;
    }
    operator List_c7*() const
    {
        return data;
    }
    unsigned int GetSize() const
    {
        return data->count;
    }
};

struct Glob_c7
{
    void FUN_00e92760(void* a, ListPtr_c7* pp);
};

struct FUN_00ce14b0
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
    FUN_00ce14b0(unsigned int a, unsigned int b, unsigned int c, Vector_c7* v);
    static void* operator new(std::size_t size);
    static void operator delete(void* p);
};


inline void* FUN_00ce14b0::operator new(std::size_t size)
{
    return hkMemoryRouter::getInstance().heap().blockAlloc(int(size));
}
inline Cursor_c7::Cursor_c7(unsigned int n)
{
    unsigned int bytes = (((n * 3) << 4) + 0x7f) & 0xffffff80;
    saved = static_cast<unsigned char*>(hkMemoryRouter::getInstance().allocateStack(int(bytes)));
}
inline Cursor_c7::Cursor_c7(unsigned int n, const int& c, int& result)
{
    result = c;
    unsigned int bytes = (((n * 3) << 4) + 0x7f) & 0xffffff80;
    saved = static_cast<unsigned char*>(hkMemoryRouter::getInstance().allocateStack(int(bytes)));
}
inline Cursor_c7::~Cursor_c7()
{
    hkMemoryRouter::getInstance().deallocateStack(saved);
}

struct Actor_c7
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned char unk040, unk041;
    unsigned char m_42;
    unsigned char unk043;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    FUN_00ce14b0* m_248;
    void* m_24c;
    ListPtr_c7 m_250;
    unsigned char m_254;
    unsigned char unk255, unk256, unk257;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    Holder_c7* m_2a4;
    void FUN_00c7b1f0(void* a1, short a2, short a3, short a4);
};

}

// namespace fnv_00c7b1f0

struct SRC
{
    int m_00, m_04, m_08, m_0c;
    float m_10, m_14, m_18, m_1c;
    __m128 m_20;
};

struct DST
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    float m_30;
};

struct VEC
{
    float q[4];
};

// @fnv 0x00c74d50
struct LOC
{
    float s;
    char quat[16];
};

DST* __cdecl FUN_00c74d50(DST* dst, const SRC* src)
{
    LOC a;
    VEC* q = (VEC*)&a.quat;
    q->q[1] = src->m_10;
    q->q[2] = src->m_14;
    q->q[3] = src->m_18;
    q->q[0] = src->m_1c;
    reinterpret_cast<::NiQuaternion *>((q))->MakeUnitLength();
    reinterpret_cast<::FUN_004f0180_Class *>((q))->FUN_004f0180((::M3_ *)(dst));
    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&dst->m_24)), (*(const ::hkVector4 *)(src)));
    _mm_store_ss(&a.s, src->m_20);
    dst->m_30 = a.s;
    return dst;
}



inline const NiPoint3& ZeroPoint()
{
    return reinterpret_cast<const NiPoint3&>((*reinterpret_cast<::NiPoint3_c *>((void *)&::NiPoint3::ZERO)));
}

struct Bound
{
    union
    {
        struct
        {
            float x, y, z, radius;
        };
        float coordinates[4];
    };
};

extern float DAT_011b0194;

static float DAT_01267bcc;

extern const double DAT_010c4ab8;

struct ShapeRef
{
    virtual void Reserved();
    virtual void Destroy();
    long references;
    void* shape;
    int unk0c;
    float radius;
    void IncRefCount()
    {
        InterlockedIncrement(&references);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&references))
            Destroy();
    }
};

struct ShapePointer : NiPointer<ShapeRef>
{
    ShapePointer& operator=(ShapeRef* incoming)
    {
        NiPointer<ShapeRef>::operator=(incoming);
        return *this;
    }
    void FUN_0066b0d0(ShapeRef*);
};

struct Geometry
{
    int unk00, unk04, unk08;
    NiPoint3 center, extents;
};

struct NodeBounds
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Bound* bound;
    Bound* GetBound() const
    {
        return bound ? bound : &(*reinterpret_cast<::Bound *>(&::g_defaultBound));
    }
};

void* __cdecl FUN_00aa13e0(size_t);

struct RawArray
{
    void** data;
    int count;
    unsigned int capacity;
    __forceinline void Add(void* value)
    {
        hkMemoryAllocator* allocator = hkMemoryRouter::getInstance().m_heap;
        if (count == (capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(allocator), (::AudioStream *)(void *)(this), 4);
        data[count++] = value;
    }
    void Clear8()
    {
        hkMemoryAllocator* allocator = hkMemoryRouter::getInstance().m_heap;
        count = 0;
        if (!(capacity & 0x80000000))
            allocator->bufFree(data, (capacity & 0x3fffffff) * 8);
    }
};
struct ShapePtrArray : RawArray
{
};


struct CompoundInfo
{
    int material;
    RawArray shapes;
    RawArray extra;
    CompoundInfo() : material(0)
    {
        shapes.data = 0;
        shapes.count = 0;
        shapes.capacity = 0x80000000;
        extra.data = 0;
        extra.count = 0;
        extra.capacity = 0x80000000;
    }
    ~CompoundInfo()
    {
        reinterpret_cast<::FUN_00c71120 *>(this)->FUN_00c71120::~FUN_00c71120();
    }
};

struct FUN_00cab710 : ShapeRef
{
    FUN_00cab710(NiPoint3 const&, NiPoint3 const&, float);
};

struct FUN_00c6d290 : ShapeRef
{
    FUN_00c6d290(CompoundInfo const&);
};

struct ShapeInput;

struct __declspec(align(16)) AuxInfo
{
    unsigned int flags;
    hkpSphereShape* shape;
    int unk08;
    ShapePtrArray entries;
    int unk18, unk1c;
    unsigned char transform[64];
    ~AuxInfo()
    {
        entries.Clear8();
    }
    AuxInfo(ShapeInput* input, NodeBounds*& nodeOut, unsigned int& flagsOut);
};

struct ShapeInput;

struct ShapeOwner;

struct MemoryManagerLocal
{
};

struct FUN_00c6d1e0 : ShapeRef
{
    int unk14, unk18, unk1c;
    FUN_00c6d1e0(AuxInfo const&, ShapeOwner*);
    static void* operator new(std::size_t n)
    {
        unsigned char* p = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::MemoryManagerLocal *>(&::g_memoryManager))))->FUN_00aa3e40(n + 16);
        unsigned char offset = 16 - ((uintptr_t)p & 15);
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void*);
};

struct ShapeInput
{
    int unk000;
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
    float margin;
    float maxSize;
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
    NodeBounds* node;
    unsigned int flags;
    int unk088;
    int unk08c;
    int unk090;
    unsigned char flag94, flag95, flag96, flag97;
    int unk098;
    int unk09c;
    ShapeRef* existingShape;
    int unk0a4;
    int unk0a8;
    float scale;
    unsigned int index;
    unsigned int GetFlags() const
    {
        return flags;
    }
    float GetScale() const
    {
        return scale;
    }
    ShapeRef* GetShape() const
    {
        return existingShape;
    }
    unsigned int GetIndex() const
    {
        if (existingShape)
            return 0;
        return index;
    }
};

__forceinline AuxInfo::AuxInfo(ShapeInput* input, NodeBounds*& nodeOut, unsigned int& flagsOut)
{
    new ((void *)this) ::FUN_0056e0b0();
    unsigned int f = input->GetFlags() & 0xffffff80;
    nodeOut = input->node;
    _ReadWriteBarrier();
    flagsOut = f | 0x20;
}

struct ShapeOwner
{
    int unk000;
    int unk004;
    NodeBounds* node;
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
    unsigned int flags;
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
    float maxRadius;
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
    float height;
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
    float fullHeight;
    int unk568;
    int unk56c;
    float centerX;
    float centerY;
    float heightAccum;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    ShapePointer aux;
    int unk59c;
    unsigned int shapeCount;
    ShapePointer shapes[2];
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    NiPoint3 dimensions;
    __forceinline void SetShape(unsigned int index, ShapeRef* incoming)
    {
        shapes[index] = incoming;
    }
    float GetMaxRadius() const
    {
        return maxRadius;
    }
    float GetBoundRadius(ShapeRef* bound) const
    {
        return bound && bound->shape ? ((ShapeRef*)bound->shape)->radius : DAT_010c72bc;
    }
    void FUN_00c72410(ShapeInput* input);
};

// @fnv 0x00c72410
void ShapeOwner::FUN_00c72410(ShapeInput* input)
{
    shapeCount = 2;
    float diameter, radius;
    float scratch;
    NiPoint3 extents, center;
    if (input->GetShape())
    {
        shapes[input->GetIndex()] = input->GetShape();
        ShapeRef* bound = ((::ShapeRef *)(reinterpret_cast<::Holder *>(this)->GetCurrentObject()));
        radius = GetBoundRadius(bound) * DAT_011b0194;
        diameter = 0;
    }
    else
    {
        NiPoint3 scaled, b;
        if (input->node && !input->flag96)
        {
            Geometry* geometry;
            geometry = ((::Geometry *)(::fnv_00c55170::FUN_00c55170((::fnv_00c55170::AvCaller *)(input->node))));
            if (geometry)
            {
                extents = geometry->extents * input->GetScale();
                center = geometry->center * input->GetScale();
                scaled = ZeroPoint();
            }
            else
            {
                NodeBounds* fallbackNode = input->node;
                Bound* local = fallbackNode->GetBound();
                if (flags & 1)
                {
                    extents.y = local->radius;
                    scratch = (float)(input->scale * DAT_0104f2f0);
                    extents.z = scratch;
                    extents.x = scratch;
                }
                else
                {
                    extents.z = local->radius;
                    scratch = (float)(input->scale * DAT_0104f2f0);
                    extents.y = scratch;
                    extents.x = scratch;
                }
                center = ZeroPoint();
                scaled = ZeroPoint();
            }
        }
        else
        {
            float scale = input->flag96 ? 1.0f : input->scale;
            extents.x = (float)(23.0 * scale);
            extents.y = (float)(DAT_010c4ab8 * scale);
            extents.z = (float)(DAT_010240c0 * scale);
            center = ZeroPoint();
            scaled = ZeroPoint();
        }
        if (extents.x > extents.z || extents.y > extents.z)
            flags |= 1;
        float z;
        diameter = 0;
        if (flags & 1)
        {
            scaled = center;
            scaled.z = 0;
            if (extents.x > extents.y)
            {
                diameter = (float)(2.0 * extents.x);
                if (extents.y < extents.z)
                {
                    radius = extents.y;
                    z = extents.z;
                }
                else
                {
                    radius = extents.z;
                    z = extents.y;
                }
                scaled.x += extents.x - radius;
                b = scaled;
                b.x = (float)(scaled.x * -1.0);
            }
            else
            {
                diameter = (float)(2.0 * extents.y);
                if (extents.x < extents.z)
                {
                    radius = extents.x;
                    z = extents.z;
                }
                else
                {
                    radius = extents.z;
                    z = extents.x;
                }
                scaled.y += extents.y - radius;
                b = scaled;
                b.y = (float)(scaled.y * -1.0);
            }
            if (z * 0.75 > radius)
            {
                z -= radius;
                scaled.z = (float)(z * 2.0 + radius + scaled.z);
                b.z = scaled.z;
                height = (float)(input->margin * 2.0);
                heightAccum += height;
                if (input->maxSize == 0)
                    input->maxSize = radius * DAT_01267bcc;
                CompoundInfo info;
                ShapeRef* halfLength = new FUN_00cab710(scaled, b, radius);
                scaled.z = z;
                scaled.y = (float)(scaled.y - 8.0);
                NiPoint3 sideA = scaled;
                float sideZ = (float)(z + 1.0);
                scaled.z = sideZ;
                sideA.z = (float)(sideA.z - 1.0);
                ShapeRef* left = new FUN_00cab710(scaled, sideA, (float)(z - 1.0));
                b.z = z;
                b.y = (float)(b.y + 8.0);
                NiPoint3 sideB = b;
                b.z = sideZ;
                sideB.z = (float)(sideB.z - 1.0);
                ShapeRef* right = new FUN_00cab710(b, sideB, (float)(z - 1.0));
                info.shapes.Add(halfLength ? halfLength->shape : 0);
                info.shapes.Add(left ? left->shape : 0);
                info.shapes.Add(right ? right->shape : 0);
                info.extra.Add(0);
                info.extra.Add(0);
                info.extra.Add(0);
                input->index = 0;
                shapes[input->GetIndex()].FUN_0066b0d0(new FUN_00c6d290(info));
            }
        }
        else
        {
            diameter = extents.z + extents.z;
            radius = (float)((extents.x + extents.y) * 0.5);
            scaled.z += extents.z - radius;
            b = scaled;
            b.z = (float)(scaled.z * -1.0);
            float limit = (float)(radius * 0.75);
            limit *= DAT_01267bcc;
            if (maxRadius < limit)
                maxRadius = limit;
        }
        centerX = center.x * DAT_01267bcc;
        centerY = center.y * DAT_01267bcc;
        ShapePointer& first = shapes[0];
        if (!first.m_pObject)
        {
            float h = scaled.z + radius;
            h *= DAT_01267bcc;
            h += input->margin * 2;
            height = h;
            heightAccum += height;
            if (input->maxSize == 0)
                input->maxSize = radius * DAT_01267bcc;
            if (flags & 1)
            {
                input->index = 0;
                shapes[input->GetIndex()].FUN_0066b0d0(new FUN_00cab710(scaled, b, radius));
            }
            else
            {
                first.FUN_0066b0d0(new FUN_00cab710(scaled, b, radius));
                if (input->flag96)
                {
                    if (DAT_01267be0.m_pObject == 0)
                        DAT_01267be0.FUN_0066b0d0(((::ShapeRef *)(::FUN_00c70de0((float *)&(scaled), (float *)&(b), radius, GetMaxRadius()))));
                    reinterpret_cast<::FUN_00c663d0 *>(&(shapes[1]))->operator=((const ::FUN_00c663d0 &)(DAT_01267be0));
                }
                else
                    shapes[1].FUN_0066b0d0(((::ShapeRef *)(::FUN_00c70de0((float *)&(scaled), (float *)&(b), radius, GetMaxRadius()))));
            }
        }
    }
    float units = DAT_01267bcc;
    float width = radius * units;
    dimensions.x = width;
    dimensions.z = width;
    dimensions.y = units * diameter;
    float total = extents.z * 2;
    fullHeight = units * total;
    reinterpret_cast<::ControllerShell *>(this)->SetMode(input->GetIndex());
    if (input->flag94)
        hkMemoryRouter::getInstance();
    if (input->flag95)
    {
        NodeBounds* auxNode;
        unsigned int preparedFlags;
        float auxRadius;
        AuxInfo info(input, auxNode, preparedFlags);
        info.flags = preparedFlags;
        info.shape = 0;

        if (auxNode)
        {
            Bound* local = auxNode->bound;
            Bound existing = local ? *local : (*reinterpret_cast<::Bound *>(&::g_defaultBound));
            auxRadius = existing.radius;
        }
        else
        {
            NodeBounds* n = node;
            if (n)
            {
                reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>(this)->FUN_00c89720();
                reinterpret_cast<::CpuObject *>((n))->FUN_00cac910();
                reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>(this)->FUN_00c89720();
            }
            auxRadius = 1;
        }
        if (!(auxRadius > 0))
            auxRadius = 1;
        info.shape = havok::createSphere(auxRadius * DAT_01267bcc);
        aux = new FUN_00c6d1e0(info, this);
    }
}

typedef __m128 P064Quad;

struct P064Bool
{
    char value;
    P064Bool(bool b) : value(b)
    {}
    operator bool() const
    {
        return value != 0;
    }
};

struct P064Quaternion
{
    P064Quad value;

    __declspec(noinline) void FUN_00c66320(const P064Quaternion*, const P064Quaternion*);
    __declspec(noinline) void FUN_00c74ac0(const P064Quaternion*, const P064Quaternion*);
    float GetAngle();
    void FUN_00c74c90(P064Quad*);
    void FUN_00cb2450(const P064Quad*, float);
    void FUN_005611c0();
};

struct P064Transform
{
    P064Quad translation;
    P064Quaternion rotation;
    P064Quad scale;
    __forceinline P064Transform& operator=(const P064Transform& other)
    {
        translation = other.translation;
        rotation.value = other.rotation.value;
        scale = other.scale;
        return *this;
    }
    __forceinline P064Transform(const P064Transform& other)
    {
        *this = other;
    }
    P064Transform()
    {}
};

struct P064Skeleton
{
    int unk00, unk04, unk08;
    short* parents;
    int unk10, unk14, unk18;
    int count;
};

struct P064Pose
{
    P064Skeleton* skeleton;
    P064Transform* local;
    int unk08, unk0c;
    P064Transform* model;
    int unk14, unk18;
    unsigned int* flags;
    int unk20, unk24;
    bool synchronized;
};

struct P064Point
{
    P064Quad value;
};

struct P064Slot
{
    P064Pose* pose;
    short bone;
    short referenceBone;
    float weight;
    int unk0c;
    P064Quad target;
    P064Quad direction;
    P064Quaternion previous;
    bool initialized;
    bool active;
    short unk42;
    int unk44, unk48, unk4c;
};

struct P064Aim
{
    P064Quad target;
    P064Quad offset;
    P064Quad direction;
    float weight;
};

P064Bool __cdecl FUN_00ce0290(const P064Aim*, const P064Point*, float, P064Transform*, int);

extern float DAT_01267d3c, DAT_01267d30, DAT_01267d24;



extern P064Quad DAT_010c7170, DAT_010c4c00, DAT_010c4c10;

static __forceinline void P064Assign(P064Quad& dst, const P064Quad& src)
{
    dst = src;
}

static __forceinline P064Quad P064Dot(const P064Quad& a, const P064Quad& b)
{
    P064Quad p = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 170),
                                      _mm_add_ss(_mm_shuffle_ps(p, p, 85), p));
}

static __forceinline P064Quad P064Cross(const P064Quad& a, const P064Quad& b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 201),
                                                                 _mm_shuffle_ps(b, b, 210)),
                                      _mm_mul_ps(_mm_shuffle_ps(a, a, 210),
                                                                 _mm_shuffle_ps(b, b, 201)));
}

static __forceinline P064Quad P064Rotate(const P064Quad& q, P064Quad v, bool inverse = false)
{
    P064Quad w = _mm_shuffle_ps(q, q, 255);
    P064Quad dot = P064Dot(v, q);
    P064Quad crossA = _mm_mul_ps(_mm_shuffle_ps(v, v, 201),
                                                 _mm_shuffle_ps(q, q, 210));
    P064Quad crossB = _mm_mul_ps(_mm_shuffle_ps(v, v, 210),
                                                 _mm_shuffle_ps(q, q, 201));
    P064Quad cross;
    if (inverse)
        cross = _mm_sub_ps(crossA, crossB);
    else
        cross = _mm_sub_ps(crossB, crossA);
    P064Quad sum = _mm_add_ps(
        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v),
        _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    P064Quad result = _mm_add_ps(_mm_mul_ps(cross, w), sum);
    return _mm_add_ps(result, result);
}

static __forceinline P064Quad P064InitialRotate(const P064Quad& q, const P064Quad& v, bool inverse = false)
{
    P064Quad w = _mm_shuffle_ps(q, q, 255);
    P064Quad dot = P064Dot(v, q);
    P064Quad crossA = _mm_mul_ps(_mm_shuffle_ps(v, v, 201),
                                                 _mm_shuffle_ps(q, q, 210));
    P064Quad crossB = _mm_mul_ps(_mm_shuffle_ps(v, v, 210),
                                                 _mm_shuffle_ps(q, q, 201));
    P064Quad cross;
    if (inverse)
        cross = _mm_sub_ps(crossA, crossB);
    else
        cross = _mm_sub_ps(crossB, crossA);
    P064Quad sum = _mm_add_ps(
        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v),
        _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    P064Quad result = _mm_add_ps(_mm_mul_ps(cross, w), sum);
    return _mm_add_ps(result, result);
}

static __forceinline P064Quad P064InverseRotate(const P064Quad& q, const P064Quad& v)
{
    P064Quad w = _mm_shuffle_ps(q, q, 255);
    P064Quad dot = P064Dot(v, q);
    P064Quad crossA = _mm_mul_ps(_mm_shuffle_ps(v, v, 201),
                                                 _mm_shuffle_ps(q, q, 210));
    P064Quad crossB = _mm_mul_ps(_mm_shuffle_ps(v, v, 210),
                                                 _mm_shuffle_ps(q, q, 201));
    P064Quad cross = _mm_sub_ps(crossA, crossB);
    P064Quad sum = _mm_add_ps(
        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v),
        _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    P064Quad result = _mm_add_ps(_mm_mul_ps(cross, w), sum);
    return _mm_add_ps(result, result);
}

static __forceinline P064Quad P064Normalize(const P064Quad& v, const P064Quad& zero, const P064Quad& three,
                                            const P064Quad& half)
{
    P064Quad length = P064Dot(v, v);
    P064Quad r = _mm_rsqrt_ss(length);
    P064Quad corrected = _mm_mul_ss(
        _mm_mul_ss(half, r),
        _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(length, r), r)));
    corrected = _mm_andnot_ps(_mm_cmpeq_ss(length, zero), corrected);
    return _mm_mul_ps(_mm_shuffle_ps(corrected, corrected, 0), v);
}

static __forceinline float P064Length(const P064Quad& v)
{
    return _mm_cvtss_f32(_mm_sqrt_ss(P064Dot(v, v)));
}

static __forceinline P064Transform* P064Model(P064Pose* pose, int bone)
{
    if (!(pose->flags[bone] & 2))
        return pose->model + bone;
    return ((::P064Transform *)&(reinterpret_cast<::SkeletonPoseData *>((pose))->FUN_00cda180(bone)));
}

static __forceinline P064Transform* P064Local(P064Pose* pose, int bone, P064Transform* __restrict scratch)
{
    if (!(pose->flags[bone] & 1))
        return pose->local + bone;
    {
        P064Transform* models = pose->model;
        P064Transform* src = models + bone;
        short parent = pose->skeleton->parents[bone];
        if (parent != -1)
        {
            P064Transform* p = P064Model(pose, parent);
            P064Transform* dst = pose->local + bone;
            P064Transform& inverse = *scratch;
            inverse.translation =
                _mm_xor_ps(P064InverseRotate(p->rotation.value, p->translation), DAT_010c44d0);
            inverse.rotation.value = _mm_xor_ps(p->rotation.value, DAT_010c4c00);
            P064Quad scale = _mm_shuffle_ps(
                _mm_load_ps(reinterpret_cast<float*>(&p->scale)),
                _mm_unpackhi_ps(_mm_load_ps(reinterpret_cast<float*>(&p->scale)), DAT_010c7170), 196);
            P064Quad r = _mm_rcp_ps(scale);
            inverse.scale = _mm_and_ps(
                _mm_sub_ps(_mm_add_ps(r, r),
                                           _mm_mul_ps(_mm_mul_ps(r, scale), r)),
                DAT_010c4c10);
            dst->translation =
                _mm_add_ps(P064Rotate(inverse.rotation.value, src->translation), inverse.translation);
            dst->rotation.FUN_00c66320(&inverse.rotation, &src->rotation);
            dst->scale = _mm_mul_ps(src->scale, inverse.scale);
        }
        else
        {
            pose->local[bone] = models[bone];
        }
        pose->flags[bone] &= ~1u;
    }
    return pose->local + bone;
}

struct P064Controller
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    short unkb0;
    bool enabled;
    bool running;
    int unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    P064Quad transformTranslation;
    P064Quaternion transformRotation;
    P064Slot slots[2];
    bool constrained;
    int activeSlot;
    __declspec(noinline) float FUN_00c755e0(int, P064Quaternion*);
    bool FUN_00c78610(int, const P064Point*);
};

struct P064Scalar
{
    union
    {
        P064Quad value;
        float lanes[4];
    };
    P064Scalar(float f) : value(_mm_set_ss(f))
    {}
};

__declspec(noinline) void P064Quaternion::FUN_00c66320(const P064Quaternion* first, const P064Quaternion* second)
{
    P064Quad left = first->value;
    P064Quad right = second->value;
    P064Quad product = _mm_mul_ps(right, left);
    P064Quad sum = P064Dot(left, right);
    P064Quad realPart = _mm_sub_ps(product, _mm_shuffle_ps(sum, sum, 0));
    P064Quad ca = _mm_mul_ps(_mm_shuffle_ps(right, right, 210),
                                             _mm_shuffle_ps(left, left, 201));
    P064Quad cb = _mm_mul_ps(_mm_shuffle_ps(right, right, 201),
                                             _mm_shuffle_ps(left, left, 210));
    P064Quad cross = _mm_sub_ps(ca, cb);
    P064Quad leftW = _mm_shuffle_ps(left, left, 255);
    leftW = _mm_shuffle_ps(leftW, leftW, 0);
    P064Quad lv = _mm_mul_ps(leftW, right);
    P064Quad rightW = _mm_shuffle_ps(right, right, 255);
    rightW = _mm_shuffle_ps(rightW, rightW, 0);
    P064Quad rv = _mm_mul_ps(rightW, left);
    P064Quad vectorPart = _mm_add_ps(rv, _mm_add_ps(lv, cross));
    P064Quaternion result;
    result.value =
        _mm_shuffle_ps(vectorPart, _mm_unpackhi_ps(vectorPart, realPart), 196);
    *this = result;
}

__declspec(noinline) void P064Quaternion::FUN_00c74ac0(const P064Quaternion* a, const P064Quaternion* b)
{
    P064Quad x = a->value, y = b->value;
    P064Quad cross = P064Cross(y, x);
    P064Quad xw = _mm_shuffle_ps(x, x, 255);
    P064Quad yw = _mm_shuffle_ps(y, y, 255);
    P064Quad vectorPart =
        _mm_sub_ps(cross, _mm_mul_ps(_mm_shuffle_ps(xw, xw, 0), y));
    vectorPart = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(yw, yw, 0), x),
                                            vectorPart);
    P064Quad product = _mm_mul_ps(y, x);
    P064Quad pairs = _mm_add_ps(_mm_shuffle_ps(product, product, 78), product);
    P064Quad sum = _mm_add_ps(_mm_shuffle_ps(pairs, pairs, 177), pairs);
    sum = _mm_shuffle_ps(sum, sum, 0);
    P064Quaternion result;
    result.value = _mm_shuffle_ps(vectorPart, _mm_unpackhi_ps(vectorPart, sum), 196);
    *this = result;
}

__declspec(noinline) float P064Controller::FUN_00c755e0(int index, P064Quaternion* current)
{
    float angle = 0.0f;
    P064Slot& slot = slots[index];
    P064Quad difference =
        _mm_and_ps(_mm_sub_ps(current->value, slot.previous.value), DAT_01017d10);
    if ((_mm_movemask_ps(
             _mm_cmple_ps(difference, _mm_set_ps1(::AngularDashpotApplyD4DCB0::DAT_01017d00))) &
         7) != 7)
    {
        P064Quaternion delta;
        delta.FUN_00c74ac0(current, &slot.previous);
        angle = delta.GetAngle();
        float degrees = enabled ? DAT_01267d30 : DAT_01267d24;
        double limit = degrees * 0.01745329238474369;
        if (angle > limit)
        {
            angle = (float)limit;
            P064Quad axis;
            delta.FUN_00c74c90(&axis);
            P064Quad z = _mm_set_ss(DAT_01011d78), t = _mm_set_ss(DAT_01017718),
                     h = _mm_set_ss(::fnv_00c88020::DAT_01016248);
            axis = P064Normalize(axis, z, t, h);
            delta.FUN_00cb2450(&axis, angle);
        }
        P064Quaternion rotation;
        rotation.FUN_00c66320(&delta, &slot.previous);
        rotation.FUN_005611c0();
        P064Transform* destination = reinterpret_cast<P064Transform*>(((__m128 *)&(reinterpret_cast<::PoseState *>((slot.pose))->FUN_00cda8e0(slot.bone))));
        destination->rotation.value = rotation.value;
        slot.previous.value = rotation.value;
    }
    return angle;
}

// @fnv 0x00c78610
bool P064Controller::FUN_00c78610(int index, const P064Point* point)
{
    P064Aim aim;
    aim.weight = slots[index].weight;
    aim.offset = _mm_setzero_ps();
    aim.target = slots[index].target;
    P064Quad direction = P064InitialRotate(P064Model(slots[index].pose, slots[index].referenceBone)->rotation.value,
                                           slots[index].direction);
    P064Quad directionLength = P064Dot(direction, direction);
    P064Quad directionReciprocal = _mm_rsqrt_ss(directionLength);
    P064Scalar zero(DAT_01011d78);
    P064Scalar three(DAT_01017718);
    P064Scalar half(::fnv_00c88020::DAT_01016248);
    P064Quad directionScale = _mm_mul_ss(
        _mm_mul_ss(half.value, directionReciprocal),
        _mm_sub_ss(
            three.value, _mm_mul_ss(_mm_mul_ss(directionLength, directionReciprocal),
                                                    directionReciprocal)));
    directionScale =
        _mm_andnot_ps(_mm_cmpeq_ss(directionLength, zero.value), directionScale);
    aim.direction =
        _mm_mul_ps(_mm_shuffle_ps(directionScale, directionScale, 0), direction);
    P064Point position;
    reinterpret_cast<::InversePositionVector *>(&(position))->FUN_00c7f840((const ::Vec4 *)(point), (const ::Vec4 *)(const void *)(&transformTranslation));
    if (constrained && index == 1)
    {
        const P064Quad* referenceAddress = ((__m128 *)&(reinterpret_cast<::PoseState *>((slots[0].pose))->FUN_00cda8e0(index)));
        P064Quad normalTarget = slots[1].target;
        P064Quad reference = *referenceAddress;
        P064Quad normal = P064Normalize(P064Cross(normalTarget, reference), zero.value, three.value, half.value);
        P064Quad projected = P064Normalize(P064Cross(normal, slots[1].target), zero.value, three.value, half.value);
        P064Quad projectedSquared = _mm_mul_ps(projected, projected);
        reference = *((__m128 *)&(reinterpret_cast<::PoseState *>((slots[0].pose))->FUN_00cda8e0(index)));
        P064Quad squaredLength = _mm_add_ss(
            _mm_shuffle_ps(projectedSquared, projectedSquared, 170),
            _mm_add_ss(_mm_shuffle_ps(projectedSquared, projectedSquared, 85),
                                       projectedSquared));
        float rawDistance;
        _mm_store_ss(
            &rawDistance,
            _mm_div_ss(P064Dot(projected, reference), _mm_sqrt_ss(squaredLength)));
        float distance = rawDistance;
        P064Quad delta =
            _mm_sub_ps(position.value, P064Model(slots[1].pose, slots[1].bone)->translation);
        float magnitude;
        _mm_store_ss(&magnitude, _mm_sqrt_ss(P064Dot(delta, delta)));
        P064Quad unit = P064Normalize(delta, zero.value, three.value, half.value);
        if (magnitude < rawDistance)
            position.value = _mm_add_ps(
                position.value, _mm_mul_ps(unit, _mm_set_ps1(distance)));
        aim.offset = *((__m128 *)&(reinterpret_cast<::PoseState *>((slots[0].pose))->FUN_00cda8e0(1)));
    }
    P064Transform saved;
    saved = *P064Local(slots[index].pose, slots[index].bone, &saved);
    P064Quad previousDelta = _mm_and_ps(
        _mm_sub_ps(slots[index].previous.value, *reinterpret_cast<const P064Quad*>(&DAT_01267e30)),
        DAT_01017d10);
    if ((_mm_movemask_ps(
             _mm_cmple_ps(previousDelta, _mm_set_ps1(::AngularDashpotApplyD4DCB0::DAT_01017d00))) &
         7) == 7)
        P064Assign(slots[index].previous.value, saved.rotation.value);
    bool changed = FUN_00ce0290(&aim, &position, 1.0f, ((::P064Transform *)&(reinterpret_cast<::hkaPoseCDA *>((slots[index].pose))->FUN_00cdad80(slots[index].bone, 1))), 0);
    P064Transform updated;
    updated = *P064Local(slots[index].pose, slots[index].bone, &updated);
    float angle = slots[index].initialized ? FUN_00c755e0(index, &updated.rotation) : 0.0f;
    if (!(*(::P064Bool *)(reinterpret_cast<::FUN_00cb24c0_cls *>(&(P064Model(slots[index].pose, slots[index].bone)->rotation))->IsNormalized({}))))
    {
        int bone = slots[index].bone;
        P064Pose* pose = slots[index].pose;
        int count = pose->skeleton->count;
        pose->flags[bone] |= 4;
        for (int child = bone + 1; child < count; ++child)
        {
            short parent = pose->skeleton->parents[child];
            if (parent != -1 && (pose->flags[parent] & 4))
            {
                P064Local(pose, child, &updated);
                pose->flags[child] |= 4;
                pose->synchronized = false;
            }
        }
        for (int child = bone + 1; child < count; ++child)
        {
            unsigned int& flag = pose->flags[child];
            unsigned int value = flag;
            if (value & 4)
                flag = (value & ~4u) | 2;
        }
        pose->local[bone] = saved;
        pose->flags[bone] = 2;
        pose->synchronized = false;
    }
    slots[index].initialized = true;
    if (enabled && angle < DAT_01267d3c * 0.01745329238474369)
    {
        slots[index].previous.value = DAT_010c71b0;
        if (index != 0 && constrained)
        {
            slots[activeSlot].active = false;
            --activeSlot;
        }
        else
        {
            enabled = false;
            running = false;
        }
    }
    return !changed;
}

union CharacterVector
{
    hkVector4 vector;
    signed char bytes[16];
    float& component(int index)
    {
        return reinterpret_cast<float*>(bytes)[index];
    }
    void set(float a, float b, float c, float d)
    {
        vector.m_vComponents = _mm_setr_ps(a, b, c, d);
    }
};

struct ParticleArgument
{
    int unk00;
    int unk04;
    int unk08;
    int type;
};

struct ParticleResult
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ParticleArgument* inner;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
};

struct ParticleOwner
{
};

struct ParticleSlot
{
    int unk00;
    int unk04;
    float value;
    int unk0c;
    void FUN_00c7f640(void* argument, hkVector4* vector);
};

struct CharacterProbeLocal
{
    int unk00;
    int unk04;
    ParticleOwner* owner;
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
    unsigned char flags;
    unsigned char unk415, unk416, unk417;
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
    float elevation;
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
    ParticleSlot firstSlots[2];
    ParticleSlot secondSlots[2];
    float baseOffset;
    float height;
    void FUN_00c6e820();
};

// @fnv 0x00c6e820
void CharacterProbeLocal::FUN_00c6e820()
{
    if ((flags & 1) == 0)
        return;

    ParticleResult* result = owner ? ((::ParticleResult *)(reinterpret_cast<::FUN_00cac980_class *>((owner))->FUN_00cac980())) : 0;
    float base = baseOffset;
    float offset = height * 0.5 - base;
    float opposite = offset * -1.0;
    if (result->inner->type != 9)
        base = -baseOffset * 0.5;

    CharacterVector vector;
    vector.set(DAT_01011d78, offset, base, DAT_01011d78);
    ParticleSlot* slots = firstSlots;
    for (int i = 0; i < 2; i++)
    {
        slots[i].FUN_00c7f640(&result->unkb0, &vector.vector);
        float previous = slots[i].value;
        slots[i].value = elevation + previous;
        vector.component(1) = opposite;
    }

    vector.set(opposite, DAT_01011d78, base, DAT_01011d78);
    slots = secondSlots;
    for (int i = 0; i < 2; i++)
    {
        slots[i].FUN_00c7f640(&result->unkb0, &vector.vector);
        slots[i].value = slots[i].value + elevation;
        vector.component(0) = offset;
    }
}

__forceinline float AimMin(float a, float b)
{
    return a < b ? a : b;
}
__forceinline float AimMax(float a, float b)
{
    return a > b ? a : b;
}

struct AimVector_c70060
{
    P064Quad q;
};

struct AimNode_c70060
{
    int unk00, unk04;
    char* object;
};

struct AimController_c70060
{
    unsigned int field_000;
    unsigned int field_004;
    unsigned int field_008;
    unsigned int field_00c;
    unsigned int field_010;
    unsigned int field_014;
    unsigned int field_018;
    unsigned int field_01c;
    unsigned int field_020;
    unsigned int field_024;
    unsigned int field_028;
    unsigned int field_02c;
    unsigned int field_030;
    unsigned int field_034;
    unsigned int field_038;
    unsigned int field_03c;
    unsigned int field_040;
    unsigned int field_044;
    unsigned int field_048;
    unsigned int field_04c;
    unsigned int field_050;
    unsigned int field_054;
    unsigned int field_058;
    unsigned int field_05c;
    unsigned int field_060;
    unsigned int field_064;
    unsigned int field_068;
    unsigned int field_06c;
    unsigned int field_070;
    unsigned int field_074;
    unsigned int field_078;
    unsigned int field_07c;
    unsigned int field_080;
    unsigned int field_084;
    unsigned int field_088;
    unsigned int field_08c;
    unsigned int field_090;
    unsigned int field_094;
    unsigned int field_098;
    unsigned int field_09c;
    unsigned int field_0a0;
    unsigned int field_0a4;
    unsigned int field_0a8;
    unsigned int field_0ac;
    unsigned int field_0b0;
    unsigned int field_0b4;
    unsigned int field_0b8;
    unsigned int field_0bc;
    unsigned int field_0c0;
    unsigned int field_0c4;
    unsigned int field_0c8;
    unsigned int field_0cc;
    unsigned int field_0d0;
    unsigned int field_0d4;
    unsigned int field_0d8;
    unsigned int field_0dc;
    unsigned int field_0e0;
    unsigned int field_0e4;
    unsigned int field_0e8;
    unsigned int field_0ec;
    unsigned int field_0f0;
    unsigned int field_0f4;
    unsigned int field_0f8;
    unsigned int field_0fc;
    unsigned int field_100;
    unsigned int field_104;
    unsigned int field_108;
    unsigned int field_10c;
    unsigned int field_110;
    unsigned int field_114;
    unsigned int field_118;
    unsigned int field_11c;
    unsigned int field_120;
    unsigned int field_124;
    unsigned int field_128;
    unsigned int field_12c;
    unsigned int field_130;
    unsigned int field_134;
    unsigned int field_138;
    unsigned int field_13c;
    unsigned int field_140;
    unsigned int field_144;
    unsigned int field_148;
    unsigned int field_14c;
    unsigned int field_150;
    unsigned int field_154;
    unsigned int field_158;
    unsigned int field_15c;
    unsigned int field_160;
    unsigned int field_164;
    unsigned int field_168;
    unsigned int field_16c;
    unsigned int field_170;
    unsigned int field_174;
    unsigned int field_178;
    unsigned int field_17c;
    unsigned int field_180;
    unsigned int field_184;
    unsigned int field_188;
    unsigned int field_18c;
    unsigned int field_190;
    unsigned int field_194;
    unsigned int field_198;
    unsigned int field_19c;
    unsigned int field_1a0;
    unsigned int field_1a4;
    unsigned int field_1a8;
    unsigned int field_1ac;
    unsigned int field_1b0;
    unsigned int field_1b4;
    unsigned int field_1b8;
    unsigned int field_1bc;
    unsigned int field_1c0;
    unsigned int field_1c4;
    unsigned int field_1c8;
    unsigned int field_1cc;
    unsigned int field_1d0;
    unsigned int field_1d4;
    unsigned int field_1d8;
    unsigned int field_1dc;
    unsigned int field_1e0;
    unsigned int field_1e4;
    unsigned int field_1e8;
    unsigned int field_1ec;
    unsigned int field_1f0;
    unsigned int field_1f4;
    unsigned int field_1f8;
    unsigned int field_1fc;
    unsigned int field_200;
    unsigned int field_204;
    unsigned int field_208;
    unsigned int field_20c;
    unsigned int field_210;
    unsigned int field_214;
    unsigned int field_218;
    unsigned int field_21c;
    unsigned int field_220;
    unsigned int field_224;
    unsigned int field_228;
    unsigned int field_22c;
    unsigned int field_230;
    unsigned int field_234;
    unsigned int field_238;
    unsigned int field_23c;
    unsigned int field_240;
    unsigned int field_244;
    unsigned int field_248;
    unsigned int field_24c;
    unsigned int field_250;
    unsigned int field_254;
    unsigned int field_258;
    unsigned int field_25c;
    unsigned int field_260;
    unsigned int field_264;
    unsigned int field_268;
    unsigned int field_26c;
    unsigned int field_270;
    unsigned int field_274;
    unsigned int field_278;
    unsigned int field_27c;
    unsigned int field_280;
    unsigned int field_284;
    unsigned int field_288;
    unsigned int field_28c;
    unsigned int field_290;
    unsigned int field_294;
    unsigned int field_298;
    unsigned int field_29c;
    unsigned int field_2a0;
    unsigned int field_2a4;
    unsigned int field_2a8;
    unsigned int field_2ac;
    unsigned int field_2b0;
    unsigned int field_2b4;
    unsigned int field_2b8;
    unsigned int field_2bc;
    unsigned int field_2c0;
    unsigned int field_2c4;
    unsigned int field_2c8;
    unsigned int field_2cc;
    unsigned int field_2d0;
    unsigned int field_2d4;
    unsigned int field_2d8;
    unsigned int field_2dc;
    unsigned int field_2e0;
    unsigned int field_2e4;
    unsigned int field_2e8;
    unsigned int field_2ec;
    unsigned int field_2f0;
    unsigned int field_2f4;
    unsigned int field_2f8;
    unsigned int field_2fc;
    unsigned int field_300;
    unsigned int field_304;
    unsigned int field_308;
    unsigned int field_30c;
    unsigned int field_310;
    unsigned int field_314;
    unsigned int field_318;
    unsigned int field_31c;
    unsigned int field_320;
    unsigned int field_324;
    unsigned int field_328;
    unsigned int field_32c;
    unsigned int field_330;
    unsigned int field_334;
    unsigned int field_338;
    unsigned int field_33c;
    unsigned int field_340;
    unsigned int field_344;
    unsigned int field_348;
    unsigned int field_34c;
    unsigned int field_350;
    unsigned int field_354;
    unsigned int field_358;
    unsigned int field_35c;
    unsigned int field_360;
    unsigned int field_364;
    unsigned int field_368;
    unsigned int field_36c;
    unsigned int field_370;
    unsigned int field_374;
    unsigned int field_378;
    unsigned int field_37c;
    unsigned int field_380;
    unsigned int field_384;
    unsigned int field_388;
    unsigned int field_38c;
    unsigned int field_390;
    unsigned int field_394;
    unsigned int field_398;
    unsigned int field_39c;
    unsigned int field_3a0;
    unsigned int field_3a4;
    unsigned int field_3a8;
    unsigned int field_3ac;
    unsigned int field_3b0;
    unsigned int field_3b4;
    unsigned int field_3b8;
    unsigned int field_3bc;
    unsigned int field_3c0;
    unsigned int field_3c4;
    unsigned int field_3c8;
    unsigned int field_3cc;
    unsigned int field_3d0;
    unsigned int field_3d4;
    unsigned int field_3d8;
    unsigned int field_3dc;
    unsigned int field_3e0;
    unsigned int field_3e4;
    unsigned int field_3e8;
    unsigned int field_3ec;
    unsigned int field_3f0;
    unsigned int field_3f4;
    unsigned int field_3f8;
    unsigned int field_3fc;
    unsigned int field_400;
    unsigned int field_404;
    unsigned int field_408;
    unsigned int field_40c;
    unsigned int field_410;
    unsigned int field_414;
    unsigned int field_418;
    unsigned int field_41c;
    unsigned int field_420;
    unsigned int field_424;
    unsigned int field_428;
    unsigned int field_42c;
    unsigned int field_430;
    unsigned int field_434;
    unsigned int field_438;
    unsigned int field_43c;
    unsigned int field_440;
    unsigned int field_444;
    unsigned int field_448;
    unsigned int field_44c;
    float field_450;
    float field_454;
    float field_458;
    float field_45c;
    float field_460;
    float field_464;
    float field_468;
    float field_46c;
    unsigned int field_470;
    unsigned int field_474;
    unsigned int field_478;
    unsigned int field_47c;
    unsigned int field_480;
    unsigned int field_484;
    unsigned int field_488;
    unsigned int field_48c;
    unsigned int field_490;
    unsigned int field_494;
    unsigned int field_498;
    unsigned int field_49c;
    unsigned int field_4a0;
    unsigned int field_4a4;
    unsigned int field_4a8;
    unsigned int field_4ac;
    unsigned int field_4b0;
    unsigned int field_4b4;
    unsigned int field_4b8;
    unsigned int field_4bc;
    unsigned int field_4c0;
    unsigned int field_4c4;
    unsigned int field_4c8;
    unsigned int field_4cc;
    unsigned int field_4d0;
    unsigned int field_4d4;
    unsigned int field_4d8;
    unsigned int field_4dc;
    unsigned int field_4e0;
    unsigned int field_4e4;
    unsigned int field_4e8;
    unsigned int field_4ec;
    unsigned int field_4f0;
    unsigned int field_4f4;
    unsigned int field_4f8;
    unsigned int field_4fc;
    unsigned int field_500;
    unsigned int field_504;
    unsigned int field_508;
    unsigned int field_50c;
    unsigned int field_510;
    unsigned int field_514;
    unsigned int field_518;
    unsigned int field_51c;
    unsigned int field_520;
    unsigned int field_524;
    unsigned int field_528;
    unsigned int field_52c;
    float field_530;
    unsigned int field_534;
    unsigned int field_538;
    unsigned int field_53c;
    unsigned int field_540;
    unsigned int field_544;
    unsigned int field_548;
    unsigned int field_54c;
    float field_550;
    float field_554;
    float field_558;
    unsigned int field_55c;
    unsigned int field_560;
    unsigned int field_564;
    unsigned int field_568;
    unsigned int field_56c;
    unsigned int field_570;
    unsigned int field_574;
    unsigned int field_578;
    unsigned int field_57c;
    unsigned int field_580;
    unsigned int field_584;
    unsigned int field_588;
    unsigned int field_58c;
    unsigned int field_590;
    AimNode_c70060* field_594;
    unsigned int field_598;
    unsigned int field_59c;
    unsigned int field_5a0;
    unsigned int field_5a4;
    unsigned int field_5a8;
    unsigned int field_5ac;
    unsigned int field_5b0;
    unsigned int field_5b4;
    unsigned int field_5b8;
    unsigned int field_5bc;
    unsigned int field_5c0;
    unsigned int field_5c4;
    unsigned int field_5c8;
    unsigned int field_5cc;
    unsigned int field_5d0;
    unsigned int field_5d4;
    unsigned int field_5d8;
    unsigned int field_5dc;
    unsigned int field_5e0;
    unsigned int field_5e4;
    unsigned int field_5e8;
    unsigned int field_5ec;
    unsigned int field_5f0;
    float field_5f4;
    void FUN_00c6e680(int index, AimVector_c70060* result);
    void FUN_00c70060();
};

// @fnv 0x00c70060
void AimController_c70060::FUN_00c70060()
{
    AimVector_c70060 position;
    float difference, angle;
    if (((unsigned char)(field_414 >> 18) & 1) || !(field_530 > 0.0f))
        return;
    if ((field_414 & 1))
    {
        if (((unsigned char)(field_414 >> 25) & 1))
        {
            difference = field_460;
            angle = field_464;
            if (difference == 1.1754943508222875e-38f)
            {
                FUN_00c6e680(0, &position);
                difference =
                    _mm_cvtss_f32(_mm_shuffle_ps(position.q, position.q, 0xaa));
            }
            if (angle == 1.1754943508222875e-38f)
            {
                FUN_00c6e680(1, &position);
                angle = _mm_cvtss_f32(_mm_shuffle_ps(position.q, position.q, 0xaa));
            }
            difference = angle - difference;
            if (difference != 0.0f)
            {
                difference /= field_5f4;
                volatile float roundedAngle = (float)atan(difference);
                angle = roundedAngle;
                if (angle > 0.0f)
                {
                    if (angle > DAT_011b0148 * 0.01745329238474369)
                        angle = (float)(DAT_011b0148 * 0.01745329238474369);
                }
                else
                {
                    if (angle < DAT_011b0148 * -0.01745329238474369)
                        angle = (float)(DAT_011b0148 * -0.01745329238474369);
                }
            }
            else
                angle = 0.0f;
            difference = angle - field_550;
            if (difference != 0.0f)
            {
                if (field_558 > 1.0f)
                    field_558 = 1.0f;
                field_550 += difference * field_558;
            }
        }
        if (((unsigned char)(field_414 >> 26) & 1))
        {
            difference = field_468;
            angle = field_46c;
            if (difference == 1.1754943508222875e-38f)
            {
                FUN_00c6e680(2, &position);
                difference =
                    _mm_cvtss_f32(_mm_shuffle_ps(position.q, position.q, 0xaa));
            }
            if (angle == 1.1754943508222875e-38f)
            {
                FUN_00c6e680(3, &position);
                angle = _mm_cvtss_f32(_mm_shuffle_ps(position.q, position.q, 0xaa));
            }
            difference = angle - difference;
            if (difference != 0.0f)
            {
                difference /= field_5f4;
                volatile float roundedAngle = (float)atan(difference);
                angle = roundedAngle;
                if (angle > 0.0f)
                {
                    if (angle > DAT_011b0148 * 0.01745329238474369)
                        angle = (float)(DAT_011b0148 * 0.01745329238474369);
                }
                else
                {
                    if (angle < DAT_011b0148 * -0.01745329238474369)
                        angle = (float)(DAT_011b0148 * -0.01745329238474369);
                }
            }
            else
                angle = 0.0f;
            difference = angle - field_554;
            if (difference != 0.0f)
            {
                if (field_558 > 1.0f)
                    field_558 = 1.0f;
                field_554 += difference * field_558;
            }
        }
    }
    else
    {
        char* object = field_594 ? field_594->object : 0;
        reinterpret_cast<::FUN_004b4ab0_Class *>(&(position))->FUN_004b4ab0((intptr_t)(object + 0xb0), (intptr_t)&field_450);
        double ucLimitOffset = DAT_011b0148 * 0.01745329238474369;
        unsigned int flags = field_414;
        P064Quad rotation;
        rotation = _mm_load_ps((const float*)&position);
        float limit = (float)ucLimitOffset;
        if (((unsigned char)(flags >> 26) & 1))
        {
            float angle = AimMax(AimMin((float)(_mm_cvtss_f32(rotation) * -1.0), limit), -limit);
            float difference = angle - field_554;
            if (difference != 0.0f)
            {
                if (field_558 > 1.0f)
                    field_558 = 1.0f;
                field_554 += difference * field_558;
            }
        }
        if (((unsigned char)(flags >> 25) & 1))
        {
            double raw = _mm_cvtss_f32(_mm_shuffle_ps(rotation, rotation, 0x55));
            float angle = AimMax(raw < limit ? (float)raw : limit, -limit);
            float difference = angle - field_550;
            if (difference != 0.0f)
            {
                if (field_558 > 1.0f)
                    field_558 = 1.0f;
                field_550 += difference * field_558;
            }
        }
    }
}

union S00c70550_Vector
{
    __int8 m_i8[16];
    __m128 m_vComponents;
    struct
    {
        float x, y, z, w;
    };
};

struct S00c70550_Point3
{
    float x, y, z;
};

void SubtractVectors(S00c70550_Vector* pOut);

class FUN_00c70550_cls
{
  public:
    float FUN_00c70550();
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    float m_fOriginZ;
};

// @fnv 0x00c70550
float FUN_00c70550_cls::FUN_00c70550()
{
    float fResult = 0.0f;
    if (m_fOriginZ != 0.0f)
    {
        S00c70550_Vector kPos;
        SubtractVectors(&kPos);
        S00c70550_Point3 kPoint;
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&kPoint)), (*(const ::hkVector4 *)(&kPos)));
        fResult = m_fOriginZ - kPoint.z;
    }
    return fResult;
}

union C74570_Vec
{
    __m128 q;
    char bytes[16];  // the real xmmintrin __m128 also overlays __int8 m128_i8[16]
};

struct C74570_Ctrl
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void Apply(float t, void* data);
};

struct C74570_Obj
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    C74570_Ctrl ctrl;
};

struct C74570_Item
{
    int unk00;
    int unk04;
    C74570_Obj* obj;
};

struct C74570_Node
{
    C74570_Item* item;
    C74570_Node* next;
};

struct C74570_Mat
{
    C74570_Vec r0;
    C74570_Vec r1;
    C74570_Vec r2;
};

struct C74570_Xf
{
    C74570_Vec a;
    void Combine(void* p, void* q);
};

extern float DAT_01267c14;

extern float DAT_01267c18;

extern float DAT_011b02dc;

extern float DAT_011b02e0;

extern double DAT_010c4b20;

struct C74570_This
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
    virtual float Eval(float t);
    int unk04;
    bool enabled;
    C74570_Node list;
    void FUN_00c74570(float dt);
};

// @fnv 0x00c74570
void C74570_This::FUN_00c74570(float dt)
{
    if (!enabled)
        return;
    if (DAT_01267c14 == 0.0f)
        return;
    C74570_Node* node = &list;
    C74570_Node*& n = node;
    float sign = (float)(1 - (int)(dt / DAT_010c4b20));
    for (; n; n = n->next)
    {
        {
            if (!n->item)
                break;
            C74570_Obj* obj = n->item->obj;
            float a = Eval(DAT_01267c14) + DAT_01267c14 * 0.25;
            if (a < 0.0f)
                a = 0.0f;
            if (a > DAT_011b02dc)
                a = DAT_011b02dc;
            a *= sign;
            float b = Eval(DAT_01064f60);
            b = DAT_01267c18 + b;
            if (b > DAT_011b02e0)
                b -= DAT_011b02e0;
            else if (b < 0.0f)
                b += DAT_011b02e0;
            C74570_Vec v0;
            C74570_Xf xf;
            C74570_Vec v1;
            v1.q = _mm_setr_ps(0.0f, a, 0.0f, 0.0f);
            v0.q = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
            C74570_Mat m;
            reinterpret_cast<::FUN_00cb2e30_cls *>(&(m))->SpawnSnap((intptr_t)(&v0), b);
            xf.Combine(&m, &v1);
            if (obj)
            {
                reinterpret_cast<::hkpEntityC9C *>((obj))->FUN_00c9c1d0();
                obj->ctrl.Apply(dt, &xf);
            }
        }
    }
}

struct P064Vector
{
    P064Quad value;
};

struct MainClass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    P064Quad m_10;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    P064Pose* m_88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    P064Pose* m_f0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    short m_144;
    short unk146;
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
    unsigned char m_190;
    bool FUN_00c757b0(void* out);
};

// @fnv 0x00c757b0
bool MainClass::FUN_00c757b0(void* out)
{
    bool result = false;
    if (m_190)
    {
        P064Vector local;
        local.value = *((__m128 *)&(reinterpret_cast<::PoseState *>((m_f0))->FUN_00cda8e0(1)));
        P064Transform* ptr = P064Model(m_88, m_144);
        reinterpret_cast<::TransformedPosDAD *>(&(local))->FUN_00c7f7a0((*(const ::hkQsTransformDAD *)(ptr)), (*(const ::hkVector4DAD *)(&local)));
        reinterpret_cast<::TransformedPosDAD *>(&(local))->FUN_00c7f7a0((*(const ::hkQsTransformDAD *)(&m_10)), (*(const ::hkVector4DAD *)(&local)));
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(out)), (*(const ::hkVector4 *)(&local)));
        result = true;
    }
    return result;
}

class SupportScalar
{
    P064Quad value;

  public:
    __forceinline SupportScalar(const P064Quad& q) : value(q)
    {}
    __forceinline operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
};

class SupportVector
{
    P064Quad value;

  public:
    __forceinline SupportVector()
    {}
    __forceinline void Difference(const SupportVector& a, const SupportVector& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline float& operator()(int lane)
    {
        return reinterpret_cast<float*>(&value)[lane];
    }
    __forceinline SupportScalar Dot(const SupportVector& b) const
    {
        P064Quad product = _mm_mul_ps(value, b.value);
        P064Quad xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline SupportScalar SquaredLength() const
    {
        return Dot(*this);
    }
    __forceinline SupportScalar Component(int lane) const
    {
        switch (lane)
        {
        case 0:
            return value;
        case 1:
            return _mm_shuffle_ps(value, value, 0x55);
        case 2:
            return _mm_shuffle_ps(value, value, 0xaa);
        default:
            return _mm_shuffle_ps(value, value, 0xff);
        }
    }
};

struct SupportListener
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
    float m_fGlyphExtent[4];

    void Blend(unsigned index, float elevation)
    {
        if (m_fGlyphExtent[index] == 1.17549435e-38f)
            m_fGlyphExtent[index] = elevation;
        else
        {
            m_fGlyphExtent[index] += elevation;
            m_fGlyphExtent[index] *= 0.5;
        }
    }
    void FUN_00c6c890(const SupportVector* corners, const SupportVector& point);
};

// @fnv 0x00c6c890
void SupportListener::FUN_00c6c890(const SupportVector* corners, const SupportVector& point)
{
    SupportVector delta[4];
    for (unsigned i = 0; i < 4; i++)
    {
        delta[i].Difference(point, corners[i]);
        delta[i](2) = 0.0f;
    }
    unsigned nearIndex = (float(delta[0].SquaredLength()) < float(delta[1].SquaredLength())) ? 0 : 1;
    Blend(nearIndex, point.Component(2));
    nearIndex = (float(delta[2].SquaredLength()) < float(delta[3].SquaredLength())) ? 2 : 3;
    Blend(nearIndex, point.Component(2));
}

// Exact matching requires correcting the compiler settings: the original is optimized, while these checks use /Od.
extern int DAT_01034ec4;

struct S00c6e680_C6RayInput
{
    __m128 from;
    __m128 to;
    bool enableShapeCollectionFilter;
    unsigned int filterInfo;
    unsigned int unk28;
    unsigned int unk2C;

    __forceinline S00c6e680_C6RayInput() : enableShapeCollectionFilter(false), filterInfo(0)
    {}
};

struct S00c6e680_C6RayOutput
{
    __m128 normal;
    float hitFraction;
    int m_uiExtraInfo;
    int unk18;
    int unk1C;
    unsigned int shapeKeys[8];
    void* rootCollidable;

    __forceinline S00c6e680_C6RayOutput() : hitFraction(1.0f), m_uiExtraInfo(-1), rootCollidable(0)
    {
        shapeKeys[0] = -1;
    }
};

struct S00c6e680_C6RayOutputPlain
{
    __m128 normal;
    float hitFraction;
    int m_uiExtraInfo;
    int unk18;
    int unk1C;
    unsigned int shapeKeys[8];
    void* rootCollidable;

    __forceinline void reset()
    {
        hitFraction = 1.0f;
        m_uiExtraInfo = -1;
        rootCollidable = 0;
        shapeKeys[0] = -1;
    }
};

struct S00c6e680_C6Collector
{
    void* table;
    float earlyOutHitFraction;
    unsigned int unk08;
    unsigned int unk0C;
    S00c6e680_C6RayOutputPlain output;
    void* unk60;

    __forceinline S00c6e680_C6Collector() : table(&DAT_01034ec4), unk60(0)
    {
        output.reset();
        earlyOutHitFraction = 1.0f;
    }
    __forceinline ~S00c6e680_C6Collector()
    {
        table = &DAT_01034ec4;
    }
};

struct S00c6e680_C6PickData
{
    S00c6e680_C6RayInput input;
    S00c6e680_C6RayOutput output;
    void* unk80;
    char unk84[12];
    __m128 unk90;
    unsigned int unkA0;
    S00c6e680_C6Collector* collectorPointer;
    unsigned int unkA8;
    bool unkAC;
    S00c6e680_C6Collector collector;

    __forceinline S00c6e680_C6PickData() : unk80(0), unkA0(0), unkAC(false)
    {}

    __forceinline ~S00c6e680_C6PickData()
    {}
};

struct S00c6e680_C6Bool
{
    char m_cBooleanValue;
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S00c6e680_C6World
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual bool Pick(S00c6e680_C6PickData&);
};

struct S00c6e680_C6WorldObject
{
    char pad[0x350];
    S00c6e680_C6World* m_pkWorld;
    __forceinline S00c6e680_C6World* GetWorld()
    {
        return m_pkWorld;
    }
};

struct S00c6e680_C6HolderResult
{
    unsigned int unk00;
    unsigned int unk04;
    S00c6e680_C6WorldObject* object;
};

struct S00c6e680_Holder
{
};

struct S00c6e680_Ctrl
{
    void FUN_0070c440(unsigned int&);
};

struct S00c6e680_Class : S00c6e680_Ctrl
{
    char pad[8];
    S00c6e680_Holder* m_pkHolder;
    char pad0c[0x5b0 - 0x0c];
    __m128 m_akPositions[1];
    void FUN_00c6e680(int index, __m128* position);
};

// @fnv 0x00c6e680
void S00c6e680_Class::FUN_00c6e680(int index, __m128* position)
{
    unsigned int pick;
    bool none = false;
    S00c6e680_C6PickData filterInfo;
    filterInfo.collectorPointer = &filterInfo.collector;
    filterInfo.unkA8 = 0;

    *position = m_akPositions[index];
    filterInfo.input.from = *position;
    (*position)[2] = (*position)[2] - DAT_0104f2f0;

    filterInfo.unk90 = (*(__m128*)&DAT_01267e30);
    filterInfo.input.to = *position;

    FUN_0070c440(pick);
    filterInfo.input.filterInfo = pick;

    S00c6e680_C6WorldObject* v =
        ((S00c6e680_C6HolderResult*)(m_pkHolder
                                         ? reinterpret_cast<::FUN_00cac980_class *>(m_pkHolder)->FUN_00cac980()
                                         : 0))
            ->object;

    S00c6e680_C6World* world = v ? v->GetWorld() : 0;
    bool hit = world->Pick(filterInfo);
    if (hit != none && hit)
    {
        float fraction;
        fraction = 1.0f - filterInfo.collector.output.hitFraction;
        (*position)[2] = fraction * DAT_0104f2f0 + (*position)[2];
    }
}

struct VectorData
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float m_10;
    float unk14;
    float unk18;
    float unk1c;
    P064Quad m_20;
};

struct Vec4Sink
{
    void FUN_00c7f640(intptr_t arg, P064Quad* value);
};

// @fnv 0x00c6d620
void __cdecl FUN_00c6d620(VectorData* data, intptr_t arg, Vec4Sink* callee)
{
    P064Quad value = data->m_20;
    value[2] += data->m_10;
    callee->FUN_00c7f640(arg, &value);
}

struct __declspec(align(16)) hkVector4C66
{
    void setSub4(const hkVector4C66& a, const hkVector4C66& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4C66& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __m128 m_vComponents;
};

class BodyC66
{
  public:
    void MarkForWrite()
    {}
    void unmarkForWrite()
    {}
    void FUN_00c96a20(const hkVector4C66& delta, hkVector4C66& out, int flags);
};

class ControllerBaseC66
{
  public:
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual BodyC66* GetBody();

    int m_unk04[23];
};

class ControllerC66 : public ControllerBaseC66
{
  public:
    void FUN_00c66c00(const hkVector4C66& position);

    hkVector4C66 m_v60;
};

// @fnv 0x00c66c00
void ControllerC66::FUN_00c66c00(const hkVector4C66& position)
{
    hkVector4C66 delta;
    delta.setSub4(position, m_v60);
    BodyC66* pkBody = GetBody();
    GetBody()->MarkForWrite();
    hkVector4C66 moved;
    pkBody->FUN_00c96a20(delta, moved, 0);
    GetBody()->unmarkForWrite();
    m_v60.add4(moved);
}

union __declspec(align(16)) VecBoxQ
{
    __m128 q;
    __int8 i8[16];
};

extern const float DAT_01013ea4;

struct ProxyHolder
{
    const char* FUN_00cac950();
};

struct VecSrc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __m128 vec10;
};

// @fnv 0x00c6ca30
void FUN_00c6ca30(ProxyHolder* a, ProxyHolder* b, VecSrc* src)
{
    __m128 p = *(const __m128*)reinterpret_cast<::FnvCpu_FUN_00cac950_CpuObject *>((a))->FUN_00cac950();
    VecBoxQ db;
    db.q = _mm_and_ps(_mm_sub_ps(p, *(const __m128*)&DAT_01267e30), *(const __m128*)&DAT_01017d10);
    __m128& d = db.q;
    if ((_mm_movemask_ps(_mm_cmple_ps(d, _mm_set_ps1(DAT_01013ea4))) & 7) == 7)
        return;
    __m128 zero = _mm_set_ss(DAT_01011d78);
    __m128 dir = src->vec10;
    dir[2] = 0.0f;
    p[2] = 0.0f;
    __m128 three = _mm_set_ss(DAT_01017718);
    __m128 sq = _mm_mul_ps(dir, dir);
    __m128 len = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    __m128 r = _mm_rsqrt_ss(len);
    __m128 inv =
        _mm_andnot_ps(_mm_cmpeq_ss(len, zero), _mm_mul_ss(_mm_mul_ss(_mm_set_ss(::fnv_00c88020::DAT_01016248), r),
                                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, r), r))));
    dir = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), dir), p);
    p = _mm_add_ps(*(const __m128*)b->FUN_00cac950(), dir);
    reinterpret_cast<::CacObj *>((b))->FUN_00cac960((const ::CacV4 *)(const __m128 *)(&p));
}

struct S00c7fcc0_Out
{
    void* node;
    int unk04;
    int unk08;
    int unk0c;
    P064Quad m10;
    P064Quad m20;
};

struct S00c7fcc0_Spill
{
    intptr_t key;
    struct S00c7fcc0_Type* ti;
};

struct S00c7fcc0_Ctx
{
    P064Quad a0;
    P064Quad a1;
    P064Quad a2;
    P064Quad a3;
    P064Quad b0;
    P064Quad b1;
    P064Quad c0;
    P064Quad c1;
    P064Quad c2;
    P064Quad c3;
    P064Quad d;
    P064Quad e0;
    P064Quad e1;
    P064Quad f;
};

struct S00c7fcc0_Flags
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    unsigned int flags;
};

struct S00c7fcc0_Sub
{
    int t00;
    int t04;
    int t08;
    int t0c;
    S00c7fcc0_Flags base;
};

struct S00c7fcc0_Node
{
    void** vtbl;
    int unk04;
    S00c7fcc0_Sub* sub;
    int n0c;
    int n10;
    int n14;
    int n18;
    int n1c;
    P064Quad m20;
    P064Quad m30;
};

struct S00c7fcc0_Type
{
    int s00;
    int s04;
    int s08;
    int s0c;
    S00c7fcc0_Node* node;
    int unk14;
    float f18;
};

struct S00c7fcc0_Child;

struct S00c7fcc0_Obj
{
    void** vtbl;
    int q04;
    int q08;
    int q0c;
    int q10;
    int q14;
    int q18;
    S00c7fcc0_Obj* unk1c;
    int o20;
    int o24;
    int o28;
    int o2c;
    int o30;
    int o34;
    int o38;
    int o3c;
    int o40;
    int o44;
    int o48;
    int o4c;
    int o50;
    int o54;
    int o58;
    int o5c;
    int o60;
    int o64;
    float f68;
};

struct S00c7fcc0_Child
{
    int c00;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    int c28;
    int c2c;
    int c30;
    int c34;
    int c38;
    int c3c;
    int c40;
    int c44;
    int c48;
    int c4c;
    int c50;
    int c54;
    int c58;
    int c5c;
    int c60;
    int c64;
    int c68;
    int c6c;
    int c70;
    int c74;
    int c78;
    int c7c;
    int c80;
    int c84;
    int c88;
    int c8c;
    int c90;
    int c94;
    int c98;
    int c9c;
    S00c7fcc0_Obj** kids;
    unsigned short unkA4;
    unsigned short count;
};

struct S00c7fcc0_M
{
    void FUN_00cb2240(void* p, void* q);
};

// @fnv 0x00c7fcc0
bool FUN_00c7fcc0(S00c7fcc0_Obj* self, intptr_t a2, S00c7fcc0_Out* out, bool flag)
{
    S00c7fcc0_Ctx ctx;
    volatile S00c7fcc0_Spill sp;
    sp.key = a2;
    bool result = false;
    S00c7fcc0_Obj* me = self;
    S00c7fcc0_Child* ch;
    if (me)
    {
        if (me->unk1c)
        {
            S00c7fcc0_Type* t0 = ((::S00c7fcc0_Type *)(reinterpret_cast<::NiObject *>((me->unk1c))->DynamicCast((const ::NiRTTI *)(const ::FxRTTI *)(&(*reinterpret_cast<const ::FxRTTI *>(&::g_012043f8))))));
            sp.ti = t0;
            if (t0)
            {
                S00c7fcc0_Node* node = t0->node;
                if (node)
                {
                    S00c7fcc0_Flags* b = node->sub ? &node->sub->base : 0;
                    unsigned int v = b ? b->flags : 0;
                    unsigned int k = v & 0x7f;
                    if (k != 8 && k != 0x1d)
                        goto done;
                    unsigned int s = (v >> 8) & 0x1f;
                    bool ok;
                    if (s != 1)
                    {
                        if (s - 2 <= 0xe)
                            ok = true;
                        else
                            goto done;
                    }
                    else
                    {
                        ok = (flag == 0);
                    }
                    if (!ok)
                        goto done;
                    void* a = ((void *)(reinterpret_cast<::FUN_004ae6a0_shell *>((node))->FUN_004ae6a0()));
                    if (!a)
                        goto done;
                    S00c7fcc0_Child* edi = (S00c7fcc0_Child*)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<char *>(&::g_0126832c))), (::NiObject *)(a))));
                    if (!edi)
                        goto done;
                    (*(void(**)(void*, void*))(*(char**)node + 0xf4))(node, &ctx.a0);
                    if (::FUN_0043b300((const ::NiRTTI *)(void *)(&(*reinterpret_cast<char *>(&::g_01267e64))), (::NiAVObject *)(sp.ti)))
                    {
                        if (!reinterpret_cast<::Holder_cffa0 *>((node))->FUN_008cffa0() || sp.ti->f18 == 1.0f)
                        {
                            ::FromHK((*(::hkTransform *)(&ctx.a0)), (*(const ::NiTransform *)(&me->f68)));
                            if (::FUN_0043b300((const ::NiRTTI *)(void *)(&(*reinterpret_cast<char *>(&::g_012683c8))), (::NiAVObject *)(node)))
                            {
                                ctx.c0 = ctx.a0;
                                ctx.c1 = ctx.a1;
                                ctx.c2 = ctx.a2;
                                ctx.c3 = ctx.a3;
                                reinterpret_cast<::RotationRows *>((((S00c7fcc0_M*)&ctx.d)))->FUN_00cb2d90(&node->m20);
                                ctx.f = node->m30;
                                ((S00c7fcc0_M*)&ctx.a0)->FUN_00cb2240(&ctx.c0, &ctx.d);
                            }
                        }
                    }
                    else
                    {
                        (*(void(**)(void*, void*))(*(char**)node + 0xf4))(node, &ctx.a0);
                    }
                    if (reinterpret_cast<::Capsule *>((edi))->FUN_00cab3c0((::Sphere *)(sp.key), (::Matrix *)(void *)(&ctx.a0), (::Contact *)(void *)(&ctx.b0)))
                    {
                        if (!out->node || ((float*)&out->m20)[3] > ctx.b1[3])
                        {
                            P064Quad t0 = ctx.b0;
                            out->node = node;
                            _ReadWriteBarrier();
                            out->m10 = t0;
                            P064Quad t1 = ctx.b1;
                            out->m20 = t1;
                        }
                    }
                }
            }
        }
    done:
        ch = ((S00c7fcc0_Child * (*)(S00c7fcc0_Obj*)) me->vtbl[3])(me);
        if (ch)
        {
            for (unsigned int i = 0; i < ch->count; i++)
            {
                S00c7fcc0_Obj* kid = ch->kids[i];
                result |= FUN_00c7fcc0(kid, sp.key, out, flag);
            }
        }
    }
    return result;
}

struct Vector
{
    __m128 value;
    void FUN_00c74c90(Vector*);
    void FUN_00cb2450(const Vector*, float);
    inline void FUN_00c66320(const Vector*, const Vector*);
    inline void FUN_005611c0();
    Vector()
    {}
    __forceinline void operator=(const Vector& v)
    {
        value = v.value;
    }
    __forceinline void normalize()
    {
        __m128 squared = _mm_mul_ps(value, value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
        sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), sum);
        __m128 estimate = _mm_rsqrt_ss(sum);
        __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(sum, estimate), estimate));
        __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
        inverse = _mm_andnot_ps(_mm_cmpeq_ss(sum, _mm_set_ss(::DAT_01011d78)), inverse);
        value = _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), value);
    }
};

struct InputRef
{
    const Vector* p;
    InputRef(const Vector* q) : p(q)
    {}
    operator const Vector*() const
    {
        return p;
    }
    const Vector* operator->() const
    {
        return p;
    }
};

struct TargetVector
{
    unsigned int unk00, unk04, unk08, unk0c;
    Vector vector;
};

struct Entry
{
    Holder* holder;
    short index;
    short unk06;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Vector position;
    unsigned int unk40, unk44, unk48, unk4c;
};

extern float DAT_01267d30, DAT_01267d24;

struct Constraint
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
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned short unkb0;
    bool enabled;
    unsigned char unkb3;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    Entry entries[1];
    float FUN_00c755e0(unsigned int, InputRef);
};


static __forceinline __m128 cross3(__m128 a, __m128 b)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(first, second);
}

static __forceinline __m128 dot4(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ps(_mm_shuffle_ps(p, p, 0x4e), p);
    return _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xb1));
}

static __forceinline __m128 blendXYZW(__m128 a, __m128 b)
{
    return _mm_shuffle_ps(a, _mm_unpackhi_ps(a, b), 0xc4);
}

inline void Vector::FUN_00c66320(const Vector* a, const Vector* b)
{
    __m128 xyz = cross3(a->value, b->value);
    xyz = _mm_add_ps(xyz, _mm_mul_ps(_mm_shuffle_ps(a->value, a->value, 0xff), b->value));
    xyz = _mm_add_ps(xyz, _mm_mul_ps(_mm_shuffle_ps(b->value, b->value, 0xff), a->value));
    __m128 p = _mm_mul_ps(a->value, b->value);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    __m128 w = _mm_sub_ps(p, _mm_shuffle_ps(s, s, 0));
    value = blendXYZW(xyz, w);
}

inline void Vector::FUN_005611c0()
{
    __m128 s = dot4(value, value);
    __m128 e = _mm_rsqrt_ss(s);
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(s, e), e));
    __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), correction);
    inverse = _mm_andnot_ps(_mm_cmpeq_ss(s, _mm_set_ss(0.0f)), inverse);
    value = _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), value);
}








extern float DAT_012677d8;

struct __declspec(align(16)) ScaledVector
{
    __m128 m_vComponents;

    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents[0] = x;
        m_vComponents[1] = y;
        m_vComponents[2] = z;
        m_vComponents[3] = w;
    }
};

struct SourcePoint
{
    float x;
    float y;
    float z;
};

// @fnv 0x00c68750
void FUN_00c68750(const SourcePoint* p)
{
    ScaledVector v;
    v.set(p->x * DAT_012677d8, p->y * DAT_012677d8, p->z * DAT_012677d8);
    reinterpret_cast<::ControllerC66 *>((&v))->FUN_00c66c00(*(const ::hkVector4C66 *)nullptr);
}

extern const float DAT_01011d78;

namespace P064Intrinsics {
}

extern const float DAT_01011d78;


extern P064Quad probe_vectors[16];

extern void probe_consume(char*, int);

namespace P064Intrinsics {
}

extern bool DAT_011b0c44;

union Vec_c6b0a0
{
    P064Quad q;
    void setSub4(const Vec_c6b0a0& a, const Vec_c6b0a0& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    void setAnd(const Vec_c6b0a0& a, const Vec_c6b0a0& b)
    {
        q = _mm_and_ps(a.q, b.q);
    }
    int lessEqual3(const Vec_c6b0a0& b) const
    {
        return _mm_movemask_ps(_mm_cmple_ps(q, b.q)) & 7;
    }
};

struct bhkFilter
{
    unsigned int bits;
};

struct bhkWorldObject
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int flags;
    bhkFilter FUN_0043b4f0();
    P064Quad* FUN_00560e10();
};

struct QueuedShape
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned char flags;
};

struct ShapeLink
{
    unsigned int unk00, unk04, unk08;
    QueuedShape* shape;
    signed char displacement;
    unsigned char unk11, unk12, unk13;
    unsigned int unk14;
    unsigned char kind;
};

struct IntegerMapEntry
{
    unsigned int unk00, unk04, unk08;
    bhkWorldObject* body;
    ShapeLink link;
};

struct QueueReceiver
{
};

struct QueueManager
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual QueueReceiver* receiver();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int deferred;
    unsigned int unk1c, unk20, unk24, unk28;
    IntegerMapEntry** bodies;
    unsigned int bodyCount;
    IntegerMapEntry** shapes;
    unsigned int shapeCount;
    void FUN_00c6b0a0(IntegerMapEntry* entry);
};

// @fnv 0x00c6b0a0
void QueueManager::FUN_00c6b0a0(IntegerMapEntry* entry)
{
    if (!this)
        return;
    QueueReceiver* destination = receiver();
    if (!destination)
        return;
    if (entry->link.kind == 1)
    {
        if (deferred > 0)
        {
            bhkWorldObject* body = entry->body;
            if (!body || (body->flags & 0x30))
                return;
            if (bodyCount >= 3000)
            {
                if (bodyCount > 0)
                {
                    bodyCount = 3000;
                    unsigned int removeCount = DAT_011afe80;
                    if (removeCount > 3000)
                        removeCount = 3000;
                    unsigned int remaining = 3000 - removeCount;
                    reinterpret_cast<::S_Owner *>(this)->FUN_00c674d0((::S_Item **)(::IntegerMapEntry **)(bodies + remaining), removeCount);
                    bodyCount = remaining;
                    DAT_012677a2 = 1;
                }
                reinterpret_cast<::This676 *>(this)->ClearIndexedValues();
                reinterpret_cast<::fnv_00c6aac0::FUN_00c6aac0_Owner *>(this)->FUN_00c6aac0();
                reinterpret_cast<::FUN_00c67850_Class *>(this)->ProcessConstraints();
            }
            body->flags |= 0x10;
            reinterpret_cast<::FUN_00c90510_class *>((entry))->FUN_00c90510();
            bodies[bodyCount++] = entry;
        }
        else
        {
            bhkWorldObject* body = entry->body;
            if (!body || (body->flags & 0x30))
                return;
            int active = 1;
            if (DAT_011b0c44)
            {
                if ((body->FUN_0043b4f0().bits & 0x7f) == 8)
                {
                }
                else
                {
                    Vec_c6b0a0 d0;
                    d0.setSub4(*(const Vec_c6b0a0*)((__m128 *)&(::fnv_00560d80::FUN_00560d80((void *)(body)))), *(const Vec_c6b0a0*)&DAT_01267e30);
                    Vec_c6b0a0 tolerance;
                    P064Quad tolss = _mm_load_ss(&::AngularDashpotApplyD4DCB0::DAT_01017d00);
                    tolerance.q = _mm_shuffle_ps(tolss, tolss, 0);
                    d0.setAnd(d0, *(const Vec_c6b0a0*)&DAT_01017d10);
                    if (d0.lessEqual3(tolerance) == 7)
                    {
                        Vec_c6b0a0 d1;
                        d1.setSub4(*(const Vec_c6b0a0*)((__m128 *)(reinterpret_cast<::FUN_00560e10_cls *>((body))->FUN_00560e10())), *(const Vec_c6b0a0*)&DAT_01267e30);
                        d1.setAnd(d1, *(const Vec_c6b0a0*)&DAT_01017d10);
                        if (d1.lessEqual3(tolerance) == 7)
                            active = 0;
                    }
                }
            }
            reinterpret_cast<::hkpWorldC914 *>((destination))->FUN_00c914d0((::hkpEntityC914 *)(entry), active);
        }
    }
    else
    {
        if (deferred > 0)
        {
            ShapeLink* link = &entry->link;
            if (link->kind != 2)
                return;
            ShapeLink* owner = reinterpret_cast<ShapeLink*>(reinterpret_cast<char*>(link) + link->displacement);
            if (!owner)
                return;
            QueuedShape* shape = owner->shape;
            if (!shape || (shape->flags & 0x30))
                return;
            if (shapeCount >= 200)
            {
                if (bodyCount > 0 && !DAT_012677a2)
                {
                    if (bodyCount >= 3000)
                        bodyCount = 3000;
                    unsigned int currentCount = bodyCount;
                    unsigned int removeCount = DAT_011afe80;
                    if (currentCount < removeCount)
                        removeCount = currentCount;
                    unsigned int remaining = currentCount - removeCount;
                    reinterpret_cast<::S_Owner *>(this)->FUN_00c674d0((::S_Item **)(::IntegerMapEntry **)(bodies + remaining), removeCount);
                    bodyCount = remaining;
                    DAT_012677a2 = 1;
                }
                reinterpret_cast<::This676 *>(this)->ClearIndexedValues();
                reinterpret_cast<::fnv_00c6aac0::FUN_00c6aac0_Owner *>(this)->FUN_00c6aac0();
                reinterpret_cast<::FUN_00c67850_Class *>(this)->ProcessConstraints();
            }
            shape->flags |= 0x10;
            reinterpret_cast<::FUN_00c90510_class *>((entry))->FUN_00c90510();
            shapes[shapeCount++] = entry;
        }
        else
        {
            ShapeLink* link = &entry->link;
            if (link->kind != 2)
                return;
            ShapeLink* owner = reinterpret_cast<ShapeLink*>(reinterpret_cast<char*>(link) + link->displacement);
            if (!owner)
                return;
            QueuedShape* shape = owner->shape;
            if (!shape || (shape->flags & 0x30))
                return;
            reinterpret_cast<::FUN_00c936a0_World *>((destination))->FUN_00c936a0((::hkpPhantom *)(entry));
        }
    }
}

__declspec(noinline) P064Quad* bhkWorldObject::FUN_00560e10()
{
    P064Quad a0 = probe_vectors[0];
    P064Quad a1 = probe_vectors[1];
    P064Quad a2 = probe_vectors[2];
    P064Quad a3 = probe_vectors[3];
    P064Quad a4 = probe_vectors[4];
    P064Quad a5 = probe_vectors[5];
    P064Quad a6 = probe_vectors[6];
    P064Quad a7 = probe_vectors[7];
    probe_vectors[0] = _mm_sub_ps(a0, a1);
    probe_vectors[1] = _mm_sub_ps(a1, a2);
    probe_vectors[2] = _mm_sub_ps(a2, a3);
    probe_vectors[3] = _mm_sub_ps(a3, a4);
    probe_vectors[4] = _mm_sub_ps(a4, a5);
    probe_vectors[5] = _mm_sub_ps(a5, a6);
    probe_vectors[6] = _mm_sub_ps(a6, a7);
    probe_vectors[7] = _mm_sub_ps(a7, a0);
    return probe_vectors;
}

struct ScalarRead
{
    float value;
    operator float() const
    {
        return value;
    }
};

struct ScaleValue
{
};

struct PhysicsBody
{
    int unk000;
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
    unsigned int unk02c;
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
    ScaleValue scale;
};

struct ContactInput
{
    __m128 position;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    PhysicsBody* body;
    PhysicsBody* GetBody()
    {
        return body;
    }
};

struct Prefix
{
    int unk000;
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
};

struct ControllerPrefix
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
};

struct ControllerFields
{
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    __m128 unk0e0;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    float unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    PhysicsBody* unk220;
    float unk224;
};

struct Controller : ControllerPrefix, ControllerFields
{
    bool HasFirst() const
    {
        return (unk004 & 1) != 0;
    }
    bool HasFourth() const
    {
        return ((unk004 >> 3) & 1) != 0;
    }
    void FUN_00c6f280(void*, ContactInput*, __m128*);
};

struct Owner : Prefix, Controller
{
    void getPosition(__m128*);
    int FUN_00ce1420(void*, int, float);
};

namespace fnv_00c7b1f0 {
// @fnv 0x00c7b1f0
void Actor_c7::FUN_00c7b1f0(void* a1, short a2, short a3, short a4)
{
    if (m_42 == 0)
    {
        return;
    }
    void* old = m_24c;
    if (old != a1)
    {
        m_24c = ((void *)(::NiGlobalStringTable::AddString((const char *)(a1))));
        if (old != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
        {
            StringHeader_c7* header = (StringHeader_c7*)old - 1;
            InterlockedDecrement(&header->refs);
        }
    }
    Holder_c7* holder = m_2a4;
    Root_c7* root = holder->root;
    unsigned int idx1, idx2;
    unsigned int idx3;
    if (a2 != -1)
    {
        idx1 = (unsigned short)a2;
    }
    else
    {
        idx1 = ((unsigned short)(::FindIndexByKey((::S_00cdd390_Table *)(root), "Bip01 NonAccum", (int (*)(const void *, const void *))(0))));
    }
    if (a3 != -1)
    {
        idx2 = (unsigned short)a3;
    }
    else
    {
        idx2 = ((unsigned short)(::FindIndexByKey((::S_00cdd390_Table *)(root), "Bip01 Head", (int (*)(const void *, const void *))(0))));
    }
    if (a4 != -1)
    {
        idx3 = (unsigned short)a4;
    }
    else
    {
        idx3 = ((unsigned short)(::FindIndexByKey((::S_00cdd390_Table *)(root), "Bip01 R UpperArm", (int (*)(const void *, const void *))(0))));
    }
    Vector_c7 vec;
    vec.q = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
    if (!((bool)(reinterpret_cast<::C75850Body *>(this)->IsBodyValid())))
    {
        if ((short)idx1 != -1 && (short)idx2 != -1 && (short)idx3 != -1)
        {
            return;
        }
    }
    m_248 = new FUN_00ce14b0(idx1, idx2, idx3, &vec);
    (*reinterpret_cast<::fnv_00c7b1f0::Glob_c7 *>(&::DAT_011b02f0)).FUN_00e92760(a1, &m_250);
    if (m_250 == 0)
    {
        return;
    }
    for (unsigned int i = 0; i < m_250.GetSize(); i++)
    {
        Elem_c7* volatile e = m_250->items[i];
        int n = root->m1c;
        int count = n;
        Cursor_c7 g1(n);
        Matrix_c7* dst = (Matrix_c7*)g1.saved;
        int copyCount;
        Cursor_c7 g2(n, count, copyCount);
        unsigned char* old2 = g2.saved;
        if (copyCount > 0)
        {
            for (int k = 0; k < copyCount; k++)
            {
                Matrix_c7* mats = e->m4;
                dst[k] = mats[k];
            }
            copyCount = count;
        }
        unsigned int data = root->m0c;
        ::CallWithGlobal(copyCount, data, (intptr_t)(dst), (intptr_t)(old2));
        reinterpret_cast<::Owner *>((m_248))->FUN_00ce1420(old2, 0, 0.0f);
    }
    m_254 = ((unsigned char)(reinterpret_cast<::NameSetC136 *>(((m_250).operator->()))->ContainsAllNames((const ::ClassInfoC136 *)(root))));
}
}  // namespace fnv_00c7b1f0

extern float DAT_011b0128;

extern const float DAT_01011d78;

// @fnv 0x00c6f280
void Controller::FUN_00c6f280(void*, ContactInput* contact, __m128* velocity)
{
    ScaleValue* scaleValue = &contact->GetBody()->scale;
    float scale = reinterpret_cast<::MotionMassView *>((scaleValue))->FUN_00c86430();
    __m128 square = _mm_mul_ps(*velocity, *velocity);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square);
    sum = _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa), sum);
    ScalarRead length;
    _mm_store_ss(&length.value, _mm_sqrt_ss(sum));
    float result = length;
    if (scale > 0.0f && scale < DAT_011b0128)
    {
        unsigned int kind = contact->body->unk02c & 0x7f;
        float factor;
        switch (kind)
        {
        case 6:
            factor = 0.0f;
            break;
        case 10:
            if (scale > DAT_011b0128 * 0.5)
                factor = 0.1f;
            else
                factor = 3.0f;
            break;
        case 14:
            factor = 0.1f;
            break;
        default:
            factor = 2.0f;
            break;
        }
        float ratio = length / scale;
        if (ratio > 1000.0)
            factor *= 1000.0 / ratio;
        if (!HasFirst() && HasFourth())
        {
            Vec4 delta;
            (this->*static_cast<void (Controller::*)(__m128*)>(&Owner::getPosition))(&delta.m_vComponents);
            delta.m_vComponents = _mm_sub_ps(contact->position, delta.m_vComponents);
            if (delta.m_vComponents[2] > unk1e4 * 0.8999999761581421)
            {
                __m128 v = unk0e0;
                __m128 sq = _mm_mul_ps(v, v);
                __m128 mag = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
                mag = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), mag);
                __m128 inv = _mm_rsqrt_ss(mag);
                __m128 normalized = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inv),
                                               _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(mag, inv), inv)));
                normalized = _mm_andnot_ps(_mm_cmpeq_ss(mag, _mm_set_ss(DAT_01011d78)), normalized);
                *velocity = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(normalized, normalized, 0), v), _mm_set_ps1(result));
            }
        }
        __m128 scalar = _mm_load_ss(&factor);
        __m128 splat = _mm_shuffle_ps(scalar, scalar, 0);
        *velocity = _mm_mul_ps(splat, *velocity);
        result = factor * (float)length;
    }
    else
        *velocity = _mm_setzero_ps();
    if (result > unk224)
    {
        unk224 = result;
        PhysicsBody* body = contact->body;
        if (body)
            reinterpret_cast<::FUN_00c90510_class *>((body))->FUN_00c90510();
        if (unk220)
            reinterpret_cast<::hkReferencedObjectC905 *>((unk220))->FUN_00c905b0();
        unk220 = body;
    }
}


struct Vec3C
{
    float x, y, z;
    float dot(const Vec3C& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    Vec3C operator*(float scale) const
    {
        Vec3C r = {scale * x, scale * y, scale * z};
        return r;
    }
    Vec3C& operator-=(const Vec3C& b)
    {
        x -= b.x;
        y -= b.y;
        z -= b.z;
        return *this;
    }
};

struct NP3
{
    float x, y, z;
    NP3()
    {}
    NP3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    NP3 operator*(float s) const
    {
        return NP3(x * s, y * s, z * s);
    }
    NP3 operator/(float s) const
    {
        float inv = 1.0f / s;
        return NP3(x * inv, y * inv, z * inv);
    }
};

struct BodyC;

struct ShapeC;

struct CollidableC;

struct WorldC;

struct ParentC;

struct RayInputC;

struct RayOutputC;

struct HkBoolC
{
    char value;
};

struct Vec4C
{
    __m128 value;
    Vec4C()
    {}
    Vec4C(__m128 x) : value(x)
    {}
    operator __m128() const
    {
        return value;
    }
    Vec4C& operator=(__m128 x)
    {
        value = x;
        return *this;
    }
    Vec4C& operator=(const Vec4C& o)
    {
        value = o.value;
        return *this;
    }
};

struct NodeC
{
    unsigned int unk00, unk04;
    BodyC* body;
};

struct MaterialC
{
    unsigned int unk00, unk04, unk08, unk0c;
    union
    {
        unsigned int flags;
        struct
        {
            unsigned char flagLo, flagMid, flagHi, flagTop;
        };
    };
    char typeC() const
    {
        return flags & 0x1f;
    }
    unsigned char typeU() const
    {
        return flags & 0x1f;
    }
    int typeI() const
    {
        return flags & 0x1f;
    }
};

struct ShapeC
{
    virtual void v00();
    virtual int type();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual HkBoolC RayCast(RayInputC*, RayOutputC*);
    unsigned int unk04;
    MaterialC* material;
    int kind;
    float radius;
};

struct ShapeChildrenC
{
    unsigned int unk00, unk04, unk08, unk0c;
    ShapeC* first;
    unsigned int unk14, unk18, unk1c;
    ShapeC* second;
};

struct ShapeInterfaceC
{
    virtual void v00();
    virtual int type();
};

struct WrappedShapeC
{
    unsigned int unk00, unk04, unk08;
    int kind;
    ShapeInterfaceC shape;
    unsigned int unk14;
    ShapeChildrenC* children;
};

struct CollidableC
{
    ShapeC* shape;
    unsigned int unk04, unk08, unk0c;
    signed char ownerOffset;
    unsigned char unk11, unk12, unk13;
    unsigned int unk14;
    unsigned char ownerType, unk19, unk1a, unk1b;
    unsigned int material;
    __forceinline unsigned char ownerKind() const
    {
        return ownerType;
    }
    BodyC* owner()
    {
        return ownerType == 1 ? reinterpret_cast<BodyC*>(reinterpret_cast<char*>(this) + ownerOffset) : 0;
    }
};

struct ContactC
{
    __m128 position, normal;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    CollidableC* collidable;
    unsigned int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};

struct ContactListC
{
    ContactC* data;
    int count;
};

struct ResponseC
{
    __m128 normal, other;
    float unk20, unk24, friction, weight;
    unsigned int unk30, unk34, unk38, unk3c;
};

struct ResultC
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44;
    ResponseC* data;
    int count;
};

struct TransformC
{
    __m128 axisX, axisY, axisZ, translation;
};

struct BodyC
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    NodeC* sceneNode;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int filter;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    __m128 transform;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    float motionValue;
    unsigned int unk0e4;
    unsigned char motionType;
    unsigned char unk0e9;
    unsigned short unk0ea;
    unsigned int unk0ec;
    TransformC worldTransform;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    CollidableC** collidables;
    int collidableCount;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    Vec3C velocity;
};

struct ProxyC
{
};

struct ParentPrefixC
{
    virtual void pv00();
    unsigned int unk004;
    ProxyC* proxy;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int nearProxy;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
};

struct ListenerC
{
    virtual void lv00();
    virtual void FUN_00c711d0(void*, ContactListC*, ResultC*);
};

struct ParentC : ParentPrefixC, ListenerC
{
    union
    {
        unsigned int flags;
        struct
        {
            unsigned char flagLo, flagMid, flagHi, flagTop;
        };
    };
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    float threshold;
    unsigned int unk024;
    unsigned int material;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    Vec4C normal;
    float minX;
    float minY;
    float minZ;
    float minW;
    float height;
    unsigned int unk064;
    bool allAuxiliary;
    unsigned char unk069;
    unsigned short unk06a;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    __m128 initialNormal;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    float scale;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    NodeC* node;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    NodeC* shapeNode;
    unsigned int unk198;
    unsigned int unk19c;
    TransformC transform;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    int accepted;
    BodyC* reference;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int entries;
    char getFlag(unsigned int n) const
    {
        return (unsigned char)(flags >> n) & 1;
    }
    void SetFlag(unsigned int m, bool b)
    {
        if (b)
            flags |= m;
        else
            flags &= ~m;
    }
    virtual void FUN_00c711d0(void*, ContactListC*, ResultC*);
    void SubtractVectors(Vec4C*);
};

struct ContextC
{
    unsigned int old;
    __forceinline ContextC()
    {
        old = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 16;
    }
    __forceinline ~ContextC()
    {
        g_tlsBlock.memoryContext = old;
    }
};

struct PointerArrayC
{
    CollidableC** data;
    int count;
    int capacity;
    PointerArrayC() : data(0), count(0), capacity(0x80000000)
    {}
    ~PointerArrayC()
    {
        hkMemoryAllocator* a = hkMemoryRouter::getInstance().m_heap;
        count = 0;
        if (!(static_cast<unsigned int>(capacity) & 0x80000000))
            a->bufFree(data, (capacity & 0x3fffffff) * 4);
        data = 0;
        capacity = 0x80000000;
    }
};

extern float DAT_011c3d18;

struct ComponentC
{
    __m128 value;
    float FUN_004586d0();
};

struct ComponentSourceC
{
    ComponentC FUN_00458700(int) const;
};

__declspec(noinline) Vec3C* FUN_00458620(Vec3C* output, const void* input)
{
    const ComponentSourceC* src = reinterpret_cast<const ComponentSourceC*>(input);
    output->x = FUN_004587d0(src->FUN_00458700(0).FUN_004586d0());
    output->y = FUN_004587d0(src->FUN_00458700(1).FUN_004586d0());
    output->z = FUN_004587d0(src->FUN_00458700(2).FUN_004586d0());
    return output;
}

struct PointerC
{
    void FUN_0066b0d0(void*);
};

struct FUN_00c6d9f0
{
    PointerC object;
    Vec3C position, normal, velocity;
    FUN_00c6d9f0() throw();
};

struct EntryListC
{
};

extern float DAT_01267bb0;

extern __m128 DAT_01267c00, DAT_01267bf0;

extern unsigned int DAT_01267c10;

extern float DAT_010c4aa0, DAT_010c4a9c, DAT_010a5898, DAT_010c4a98, DAT_011b0128;

extern double DAT_010c4aa8;

struct MotionC
{
};

struct RayVecC
{
    __m128 value;
};

struct RayInputC
{
    RayVecC from, to;
    int filter;
    int collectionFilter;
    unsigned int unk28, unk2c;
};

struct RayOutputFieldsC
{
    __m128 normal;
    float fraction;
    int key, unk18, unk1c;
    int keys[8];
    void* root;
    void reset()
    {
        fraction = 1.0f;
        key = -1;
        root = 0;
        keys[0] = -1;
    }
};

struct RayOutputC : RayOutputFieldsC
{
    RayOutputC()
    {
        reset();
    }
};

struct RayHitCollectorC
{
    float fraction;
    RayHitCollectorC()
    {
        fraction = 1.0f;
    }
    virtual void CollectRayHit(const void*, const void*) = 0;
    virtual ~RayHitCollectorC()
    {}
};

struct CollectorC : RayHitCollectorC
{
    unsigned int unk08, unk0c;
    RayOutputFieldsC result;
    void* object;
    CollectorC()
    {
        object = 0;
        result.reset();
        fraction = 1.0f;
    }
    virtual void CollectRayHit(const void*, const void*);
};

static __forceinline float laneValue(__m128 v)
{
    return v[0];
}

static __forceinline float laneStored(__m128 v)
{
    float out;
    _mm_store_ss(&out, v);
    return out;
}

static __forceinline __m128 zaxis(float z)
{
    return _mm_setr_ps(0.0f, 0.0f, z, 0.0f);
}

static __forceinline void lengthSquared(__m128 v, float& out)
{
    __m128 q = _mm_mul_ps(v, v);
    _mm_store_ss(&out, _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa),
                                                _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q)));
}

static __forceinline float lengthSquaredValue(__m128 v)
{
    float out;
    lengthSquared(v, out);
    return out;
}

static const float kZero = 0.0f;

static __forceinline __m128 normalized(__m128 v)
{
    __m128 q = _mm_mul_ps(v, v);
    __m128 d =
        _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q));
    __m128 r = _mm_rsqrt_ss(d);
    __m128 mask = _mm_cmpeq_ss(d, _mm_set_ss(kZero));
    __m128 n =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), r),
                          _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(d, r), r)));
    n = _mm_andnot_ps(mask, n);
    return _mm_mul_ps(_mm_shuffle_ps(n, n, 0), v);
}

static __forceinline float mulf(float a, float b)
{
    return a * b;
}

static __forceinline float invf(float a)
{
    return 1.0f / a;
}

static __forceinline void normalize3InPlace(__m128* v)
{
    __m128 n = *v;
    float len2;
    lengthSquared(n, len2);
    if (len2 != 0.0f)
    {
        float inv = 1.0f / (float)sqrt((double)len2);
        __m128 s = _mm_load_ss(&inv);
        *v = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), n);
    }
}

static __forceinline void normInPlace(__m128* v)
{
    float len2;
    lengthSquared(*v, len2);
    if (len2 != 0.0f)
    {
        float inv = 1.0f / (float)sqrt((double)len2);
        __m128 s = _mm_load_ss(&inv);
        *v = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), *v);
    }
}

static __forceinline void normP(__m128* v, __m128 n)
{
    float len2;
    lengthSquared(n, len2);
    if (len2 != 0.0f)
    {
        float inv = 1.0f / (float)sqrt((double)len2);
        __m128 s = _mm_load_ss(&inv);
        *v = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), n);
    }
}

static __forceinline void normR(__m128& v)
{
    float len2;
    lengthSquared(v, len2);
    if (len2 != 0.0f)
    {
        float inv = 1.0f / (float)sqrt((double)len2);
        __m128 s = _mm_load_ss(&inv);
        v = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), v);
    }
}

static __forceinline float lenSqV(__m128 v)
{
    float o;
    lengthSquared(v, o);
    return o;
}

static __forceinline void constructPointers(CollidableC** dst, CollidableC** src, int count)
{
    for (int i = 0; i < count; ++i)
    {
        CollidableC** p = dst + i;
        if (p)
            *p = src[i];
    }
}

static __forceinline int countMinValue(int a, int b)
{
    return a < b ? a : b;
}

// @fnv 0x00c711d0
void ParentC::FUN_00c711d0(void*, ContactListC* contacts, ResultC* results)
{
    ContextC contextGuard;
    flags &= ~4u;
    minX = minY = minZ = minW = 1.1754943508222875e-38f;
    normal = _mm_setzero_ps();
    if (flagHi & 1)
    {
        if (reference)
            reinterpret_cast<::hkReferencedObjectC905 *>((reference))->FUN_00c905b0();
        reference = 0;
    }
    Vec4C zeroVector = _mm_setzero_ps();
    accepted = 0;
    float radiusSquared = 0.0f;
    int additionalResponses = 0, auxiliary = 0;
    bool haveNormal = false;
    normal.value = initialNormal;
    bool haveSphere = false;
    Vec4C sphere0, sphere1;
    BodyC* sphereTransformBody;
    if (!(flagLo & 1) && !getFlag(5) && node && (sphereTransformBody = node->body) != 0 && shapeNode && shapeNode->body)
    {
        BodyC* bodyOwner;
        bodyOwner = shapeNode->body;
        WrappedShapeC* wrappedShape = reinterpret_cast<WrappedShapeC*>(bodyOwner);
        if (wrappedShape->kind == 9 && wrappedShape->shape.type() == 3)
        {
            ShapeC* firstSphere = wrappedShape->children->first;
            if (firstSphere && firstSphere->kind == 5)
            {
                ::FUN_00c6d620((::VectorData *)(firstSphere), (intptr_t)(&sphereTransformBody->transform), (::Vec4Sink *)(__m128 *)(&sphere0.value));
                ShapeC* b;
                b = wrappedShape->children->second;
                if (b && b->kind == 5)
                {
                    ::FUN_00c6d620((::VectorData *)(b), (intptr_t)(&sphereTransformBody->transform), (::Vec4Sink *)(__m128 *)(&sphere1.value));
                    float accumulated = b->radius;
                    radiusSquared = (float)(accumulated * ::ArrowDraw::DAT_010c4ab0);
                    radiusSquared *= radiusSquared;
                    haveSphere = true;
                }
            }
        }
    }
    int contactCount = countMinValue(results->count, contacts->count);
    bool hasMaterial2;
    hasMaterial2 = false;
    for (int contactIndex = 0; contactIndex < contactCount; ++contactIndex)
    {
        ResponseC* response = &results->data[contactIndex];
        ContactC* contact = &contacts->data[contactIndex];
        CollidableC* source = contact->collidable;
        BodyC* bodyOwner = source->owner();
        unsigned int materialByte = source->material;
        if (getFlag(16) && (flags & 0x200000) && ::FUN_00c6def0((::FUN_00c6def0_obj *)(bodyOwner)) && bodyOwner)
        {
            // The owner carries a scene node at offset 0x0c.
            NodeC* nodeBody;
            nodeBody = bodyOwner->sceneNode;
            if (nodeBody)
            {
                Vec3C velocity;
                BodyC* rb = nodeBody->body;
                ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&velocity)), (*(const ::hkVector4 *)(rb ? &rb->velocity : reinterpret_cast<Vec3C*>(&DAT_01267e30))));
                float squaredMagnitude = velocity.y * velocity.y + velocity.x * velocity.x + velocity.z * velocity.z;
                if (squaredMagnitude > 0.0f)
                {
                    Vec3C other = {0, 0, 0};
                    ParentC* owner = this;
                    ProxyC* proxy;
                    proxy = owner->proxy;
                    if (proxy)
                    {
                        reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>((owner))->FUN_00c89720();
                        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&other)), (*(const ::hkVector4 *)(reinterpret_cast<::FnvCpu_FUN_00cac950_CpuObject *>((proxy))->FUN_00cac950())));
                        reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>((owner))->FUN_00c89720();
                    }
                    float velocityDot = other.dot(velocity);
                    NP3 sc(velocityDot * velocity.x, velocityDot * velocity.y, velocityDot * velocity.z);
                    float inverse = 1.0f / squaredMagnitude;
                    float projectedX, projectedY, projectedZ;
                    projectedX = sc.x * inverse;
                    projectedY = sc.y * inverse;
                    projectedZ = sc.z * inverse;
                    float projectionDot = projectedY * velocity.y + projectedX * velocity.x + projectedZ * velocity.z;
                    if (projectionDot > 0.0f)
                    {
                        velocity.x -= projectedX;
                        velocity.y -= projectedY;
                        velocity.z -= projectedZ;
                        squaredMagnitude = velocity.dot(velocity);
                    }
                    if (squaredMagnitude > 0.0f)
                    {
                        FUN_00c6d9f0* entry = new FUN_00c6d9f0;
                        {
                            FUN_00c6d9f0* added = entry;
                            entry->object.FUN_0066b0d0(nodeBody);
                            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&entry->position)), (*(const ::hkVector4 *)(contact)));
                            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&entry->normal)), (*(const ::hkVector4 *)(&contact->normal)));
                            memcpy(&entry->velocity, &velocity, sizeof(velocity));
                            reinterpret_cast<::fnv_00cbc7b0::FUN_00cbc7b0_cls *>((reinterpret_cast<EntryListC*>(&entries)))->PushItem((void **)(::FUN_00c6d9f0 **)(&added));
                        }
                    }
                }
            }
        }
        unsigned long materialKind;
        materialKind = materialByte & 0x7f;
        hasMaterial2 |= materialKind == 2;
        bool eligibleContact = !getFlag(11);
        __m128 normalLane = _mm_shuffle_ps(contact->normal, contact->normal, 0xaa);
        float normalZ = laneStored(normalLane);
        bool acceptContact = eligibleContact;
        if (bodyOwner && normalZ > DAT_010c4aa8 && bodyOwner->motionType == 4 && !DAT_01267bb4)
        {
            ParentC* owner = this;
            Vec4C transformBody;
            SubtractVectors(&transformBody);
            transformBody.value[2] += height;
            __m128 contactPosition = contact->position;
            float contactZ = laneStored(_mm_shuffle_ps(contactPosition, contactPosition, 0xaa));
            if (contactZ <= laneStored(_mm_shuffle_ps(transformBody, transformBody, 0xaa)))
            {
                CollectorC collectorState;
                PointerArrayC array;
                NodeC* n = node;
                BodyC* sourceBody = n->body;
                hkMemoryAllocator* memoryAllocator = hkMemoryRouter::getInstance().m_heap;
                long pObj;
                int px = sourceBody->collidableCount;
                pObj = px > array.count ? array.count : px;
                int capacity = array.capacity & 0x3fffffff;
                if (capacity < px)
                {
                    int next = capacity * 2;
                    if (px >= next)
                        next = px;
                    ::FUN_00c908c0((::SpawnedObject *)(memoryAllocator), (::SpawnedArray *)(::PointerArrayC *)(&array), next, 4);
                }
                CollidableC** sourceData = sourceBody->collidables;
                CollidableC** copyData;
                copyData = array.data;
                for (int copyIndex = 0; copyIndex < pObj; ++copyIndex)
                    copyData[copyIndex] = sourceData[copyIndex];
                constructPointers(array.data + pObj, sourceBody->collidables + pObj, px - pObj);
                array.count = px;
                static const Vec4C upOffset(zaxis(DAT_010c4aa0));
                static const Vec4C downOffset(zaxis(DAT_010c4a9c));
                Vec4C rayFrom = _mm_add_ps(contact->position, upOffset);
                Vec4C rayTo = _mm_sub_ps(rayFrom, downOffset);
                DAT_01267bb0 = DAT_01015f5c;
                for (int rayIndex = 0; rayIndex < array.count; ++rayIndex)
                {
                    CollidableC* tmp = array.data[rayIndex];
                    BodyC* b = tmp->owner();
                    if (!b || b->motionType != 4)
                        continue;
                    RayInputC input;
                    input.filter = 0;
                    input.collectionFilter = 0;
                    RayOutputC rayOutput;
                    reinterpret_cast<::FUN_00c7f690_cls *>(&(input.from))->FUN_00c7f690((const ::S_00c7f690_M *)(::TransformC *)(&b->worldTransform), (const ::S_00c7f690_V *)(__m128 *)(&rayFrom.value));
                    reinterpret_cast<::FUN_00c7f690_cls *>(&(input.to))->FUN_00c7f690((const ::S_00c7f690_M *)(::TransformC *)(&b->worldTransform), (const ::S_00c7f690_V *)(__m128 *)(&rayTo.value));
                    tmp->shape->RayCast(&input, &rayOutput);
                    if (rayOutput.fraction < 1.0f)
                    {
                        this->material = b->filter & 0x7f;
                        int layer = this->material;
                        int idx;
                        idx = -1;
                        for (int k = 0; 8 > k; ++k)
                        {
                            int next = rayOutput.keys[k];
                            if (next == -1)
                                break;
                            idx = next;
                        }
                        if (idx == -1)
                        {
                            ShapeC* s = tmp->shape;
                            if (!s)
                                continue;
                            MaterialC* m = s->material;
                            if (!m)
                                continue;
                            if (m->typeI() != 0xf)
                                continue;
                        }
                        else
                        {
                            if (layer == 0x11)
                                continue;
                            MaterialC* m = ((::MaterialC *)(::FUN_00c7ffd0((::XRef *)(tmp))));
                            if (!m || m->typeI() != 0xf)
                                continue;
                        }
                        {
                            __m128 frac = _mm_load_ss(&rayOutput.fraction);
                            __m128 to4 = rayTo, from4 = rayFrom;
                            __m128 fromZ = _mm_shuffle_ps(from4, from4, 0xaa);
                            __m128 toZ = _mm_shuffle_ps(to4, to4, 0xaa);
                            float intersectionHeight;
                            _mm_store_ss(
                                &intersectionHeight,
                                _mm_add_ss(fromZ, _mm_mul_ss(_mm_sub_ss(toZ, fromZ), frac)));
                            if (intersectionHeight > DAT_01267bb0)
                            {
                                DAT_01267bb0 = intersectionHeight;
                                DAT_01267bb4 = b;
                            }
                        }
                    }
                }
            }
        }
        Vec4C direction;
        direction = response->normal;
        if (bodyOwner)
        {
            switch (materialKind)
            {
            case 2: {
                long n = bodyOwner->motionType;
                if (4 == n || n == 5)
                {
                    response->friction = DAT_010a5898;
                    break;
                }
            }
            case 10: {
                if (!(flagHi & 1))
                {
                    direction = zaxis(1.0f);
                    normalZ = 1.0f;
                    response->weight = 0;
                    if (((bool)(::FUN_00c8cce0((int *)&(bodyOwner->motionType)))))
                        response->other = zeroVector;
                }
                eligibleContact = false;
                break;
            }
            case 4:
            case 5:
            case 6:
                if (!(flagHi & 1))
                {
                    float f;
                    f = reinterpret_cast<::MotionMassView *>((reinterpret_cast<MotionC*>(&bodyOwner->motionValue)))->FUN_00c86430();
                    if (f < DAT_011b0128)
                        response->other = zeroVector;
                    direction = zaxis(1.0f);
                    normalZ = 1.0f;
                }
                eligibleContact = false;
                break;
            default:
                if (haveSphere && !getFlag(5))
                {
                    ContactC* sphereContact = contact;
                    if (lengthSquaredValue(_mm_sub_ps(sphereContact->position, sphere0)) < radiusSquared)
                    {
                        SetFlag(0x20, true);
                    }
                    else if (lengthSquaredValue(_mm_sub_ps(sphereContact->position, sphere1)) < radiusSquared)
                    {
                        SetFlag(0x20, true);
                    }
                }
                break;
            }
        }
        if (!bodyOwner)
        {
            switch (materialKind)
            {
            case 12:
            case 16:
            case 22:
            case 23:
            case 24:
            case 41:
                response->other = zeroVector;
                continue;
            case 14:
                if (flagHi & 1)
                    response->other = zeroVector;
                break;
            case 30: {
                CollidableC* tmp = contact->collidable;
                void* ownerObject = tmp->ownerKind() == 2 ? reinterpret_cast<char*>(tmp) + tmp->ownerOffset : 0;
                ParentC* collidable = ((::ParentC *)(::FUN_00c6d900((::SearchOwner *)(this))));
                if (collidable->flags & 0x8000000)
                {
                    response->normal = zeroVector;
                    response->other = zeroVector;
                }
                else
                {
                    response->normal[2] = 0;
                    normInPlace(&response->normal);
                }
                break;
            }
            default:
                break;
            }
            continue;
        }
        if (normalZ >= 0.0f)
        {
            acceptContact = true;
            if (normalZ < threshold)
            {
                if (!((bool)(reinterpret_cast<::ThisCls *>(this)->FUN_00c6eb00((::ArgObj *)(contact)))))
                {
                    if ((eligibleContact || getFlag(11)) && normalZ < (double)(float)0.2f)
                        acceptContact = false;
                    if (additionalResponses < 4 && eligibleContact)
                    {
                        ResponseC* accumulated = &results->data[results->count];
                        reinterpret_cast<::SseBlock *>((accumulated))->FUN_00c6d670((*(const ::SseBlock *)(response)));
                        _mm_store_ps(reinterpret_cast<float*>(&accumulated->other), zeroVector);
                        accumulated->normal[2] = 0;
                        accumulated->normal = normalized(accumulated->normal);
                        additionalResponses += 1;
                        results->count += 1;
                        if (acceptContact)
                            auxiliary++;
                    }
                }
                else
                {
                    if (!(flags & 0x1800))
                        response->weight = 0;
                    direction.value[2] = 1.0f;
                    {
                        Vec4C& d = direction;
                        d = normalized(d);
                    }
                    flags |= 0x404;
                    response->normal = direction;
                }
            }
            else
            {
                if (!(flagHi & 1) && (flagLo & 1))
                    reinterpret_cast<::SupportListener *>(this)->FUN_00c6c890((const ::SupportVector *)(::TransformC *)(&transform), (*(const ::SupportVector *)(contact)));
                flags |= 0x400;
                if (!getFlag(3))
                    response->friction = DAT_010c4a98;
            }
            if (!::FUN_00ca9600((char *)(void *)(&this->nearProxy)))
                response->weight *= scale;
            if (acceptContact)
            {
                {
                    unsigned int& f = flags;
                    f |= 0x200;
                }
                accepted += 1;
                reinterpret_cast<::GroundController *>((this))->FUN_00c6e980((const ::GroundPoint *)(::ContactC *)(&contacts->data[contactIndex]));
                if (haveNormal)
                    direction = _mm_add_ps(direction, normal);
                else
                    haveNormal = true;
                normal = direction;
                if (flagHi & 1)
                {
                    reinterpret_cast<::FUN_00c90510_class *>((bodyOwner))->FUN_00c90510();
                    if (reference)
                        reinterpret_cast<::hkReferencedObjectC905 *>((reference))->FUN_00c905b0();
                    reference = bodyOwner;
                }
            }
        }
    }
    if (hasMaterial2)
        flags |= 0x20000000;
    else
        flags &= ~0x20000000;
    allAuxiliary = accepted == auxiliary;
    {
        Vec4C& nr = normal;
        normP(&nr.value, nr.value);
    }
}

struct hkBoolStub
{
    char value;
    hkBoolStub(bool b) : value(b)
    {}
    operator bool() const
    {
        return value != 0;
    }
};

template <class T> struct RefPtrStub
{
    T* ptr;
    operator T*() const
    {
        return ptr;
    }
    T* operator->() const
    {
        return ptr;
    }
};

struct SimdScalar
{
    __m128 quad;
    SimdScalar(float f)
    {
        quad = _mm_load_ps1(&f);
    }
};

struct FourFloatVector
{
    __m128 quad;
    void setAddMul(const FourFloatVector& a, const FourFloatVector& b, const SimdScalar& s)
    {
        __m128 product = _mm_mul_ps(b.quad, s.quad);
        quad = _mm_add_ps(a.quad, product);
    }
    void addMul(const float& f, const FourFloatVector& b)
    {
        __m128 scalar = _mm_load_ss(&f);
        __m128 splat = _mm_shuffle_ps(scalar, scalar, 0);
        __m128 product = _mm_mul_ps(splat, b.quad);
        quad = _mm_add_ps(product, quad);
    }
};

struct CdPoint
{
    __m128 m0;
    __m128 m1;
    __m128 m2;
    __m128 m3;
    __m128 m4;
    __m128 m5;
    __m128 m6;
};

struct hkpCdPointCollectorStub
{
    void* m_ppVirtualMethodTable;
    float m_fEarlyOutDistance;
    int unk08;
    int unk0c;
};

struct hkpAllCdPointCollector : hkpCdPointCollectorStub
{
    CdPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int unk1c;
    CdPoint m_s0;
    CdPoint m_s1;
    CdPoint m_s2;
    CdPoint m_s3;
    CdPoint m_s4;
    CdPoint m_s5;
    CdPoint m_s6;
    CdPoint m_s7;
    hkpAllCdPointCollector()
    {
        m_fEarlyOutDistance = ::DAT_0104da48;
        m_ppVirtualMethodTable = &(*reinterpret_cast<void * *>(&::g_vtblInst0104da28));
        m_data = &m_s0;
        m_iCapacityState = 0x80000008;
        m_iElementCount = 0;
    }
    ~hkpAllCdPointCollector()
    {
        reinterpret_cast<::FUN_006211b0_cls *>(this)->FUN_006211b0_cls::~FUN_006211b0_cls();
    }
    hkBoolStub DidHit() const
    {
        return m_iElementCount > 0;
    }
};

struct LinearCastInput
{
    FourFloatVector m_vTo;
    float m_fMaxExtraPenetration;
    float m_fMaxExtraPenetrationAgainstFixed;
};

struct ShapePhantom
{
};

struct ContactListener
{
    virtual void unk0();
    virtual void unk4();
    virtual void processPoint(int a, CdPoint* p);
};

struct CharProxy
{
    int unk000;
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
    ContactListener m_kListener;  // 0x410
    unsigned int m_flags;         // 0x414
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
    FourFloatVector m_fVelocity;  // 0x4f0
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
    RefPtrStub<ShapePhantom> m_pPhantom;  // 0x594
    void SubtractVectors(FourFloatVector& out);
    void FUN_00c6e390(const FourFloatVector& in);
    void FUN_00c72250(float dt);
};

// @fnv 0x00c72250
void CharProxy::FUN_00c72250(float dt)
{
    FourFloatVector pos;
    if ((unsigned char)(m_flags >> 19) & 1 && m_pPhantom != 0)
    {
        hkpAllCdPointCollector collector;
        LinearCastInput input;
        input.m_fMaxExtraPenetration = ::DAT_0104da4c;
        input.m_fMaxExtraPenetrationAgainstFixed = ::DAT_0104da4c;
        SubtractVectors(pos);
        input.m_vTo.setAddMul(pos, m_fVelocity, SimdScalar(dt));
        reinterpret_cast<::ScriptX *>(((m_pPhantom).operator->()))->InvokeInterfaceCall((intptr_t)&(pos), (intptr_t)&(input), (intptr_t)&(collector), (int)(0));
        if (collector.DidHit())
        {
            reinterpret_cast<::SortableArray *>(&(collector))->FUN_00cabad0();
            for (int i = 0; i < collector.m_iElementCount; i++)
                m_kListener.processPoint(0, &collector.m_data[i]);
        }
        FUN_00c6e390(input.m_vTo);
    }
    else
    {
        SubtractVectors(pos);
        pos.addMul(dt, m_fVelocity);
        FUN_00c6e390(pos);
    }
}

struct ThreeByThreeMatrix
{
    float m[9];
};

union __declspec(align(16)) Lane128Q
{
    float f32[4];
    unsigned __int64 u64[2];
    __int8 i8[16];
};

struct QsTransform
{
    Lane128Q translation, rotation, scale;
};

union TransformWorkspace
{
    ThreeByThreeMatrix matrix;
    QsTransform transform;
};

class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};

struct Obj1C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __m128 m_10;
    __m128 m_20;
};

struct MidObj
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* m_0c;
};

struct SObj
{
    int unk00;
    int unk04;
    int unk08;
    MidObj* m_0c;
    int unk10;
    int unk14;
    int unk18;
    Obj1C* m_1c;
};

struct Src58
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    NiTransform m_68;
};

struct Rec48
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __m128 m_10;
    __m128 m_20;
};

struct Param1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Rec48* m_10;
    int unk14;
    int unk18;
    unsigned int* m_1c;
};

struct SubR
{
    ThreeByThreeMatrix* FUN_0043f8d0(ThreeByThreeMatrix*, const ThreeByThreeMatrix*);
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
};

struct FrameRecord
{
    int state;
    short indexA;
    short indexB;
    int unk08;
    int unk0c;
    __m128 directionA;
    __m128 directionB;
    __m128 unk30;
    __m128 unk40;
};

struct Cls79340
{
    bool FUN_00c79340(Param1* a1, const char* a2, int a3);
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    Src58* m_58;
    int unk5c;
    SubR m_60;
    int m_88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    short unkb0;
    char m_b2;
    char unkb3;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    FrameRecord records[2];
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
    SObj* m_2a4;
};

// @fnv 0x00c79340
bool Cls79340::FUN_00c79340(Param1* a1, const char* a2, int a3)
{
    bool ok = true;
    Param1* pA1 = a1;
    MidObj* mo = m_2a4->m_0c;
    int r = ((int)(::FindIndexByKey((::S_00cdd390_Table *)(mo), a2, (int (*)(const void *, const void *))(0))));

    records[a3].indexA = r;
    if ((short)r == -1)
    {
        ok = false;
    }
    else
    {
        unsigned short* tab = m_2a4->m_0c->m_0c;
        short r2 = (short)tab[(short)r];
        records[a3].indexB = r2;
        if (r2 == -1)
            ok = false;
    }
    m_b2 = 0;
    if (ok)
    {

        NiTransform t;
        t = m_58->m_68;
        TransformWorkspace xformBuf;
        ThreeByThreeMatrix* pm = m_60.FUN_0043f8d0(&xformBuf.matrix, &t.m_kOrientation);
        t.m_kOrientation = *pm;
        t.m_fScale = 1.0f;
        ::FUN_00c74dd0((::C74QsTransform *)(void *)(&xformBuf.transform), (const ::C74Transform *)(::NiTransform *)(&t));

        VecBoxQ Vb;
        Vb.q =
            _mm_setr_ps(*reinterpret_cast<const float*>(&DAT_01011d78), *reinterpret_cast<const float*>(&(*reinterpret_cast<unsigned int *>(&::DAT_01012068))),
                        *reinterpret_cast<const float*>(&DAT_01011d78), *reinterpret_cast<const float*>(&DAT_01011d78));
        int w1 = records[a3].indexA;
        Rec48* ptrA;
        if (!(pA1->m_1c[w1] & 2))
            ptrA = pA1->m_10 + w1;
        else
            ptrA = ((::Rec48 *)&(reinterpret_cast<::SkeletonPoseData *>((pA1))->FUN_00cda180(w1)));
        int w2 = records[a3].indexB;
        Rec48* ptrB;
        if (!(pA1->m_1c[w2] & 2))
            ptrB = pA1->m_10 + w2;
        else
            ptrB = ((::Rec48 *)&(reinterpret_cast<::SkeletonPoseData *>((pA1))->FUN_00cda180(w2)));

        __m128 vd2;
        __m128 vc9;
        {
            __m128 q = ptrB->m_10;
            __m128 qw = _mm_shuffle_ps(q, q, 0xff);
            __m128 prod = _mm_mul_ps(q, Vb.q);
            __m128 sy = _mm_shuffle_ps(prod, prod, 0x55);
            sy = _mm_add_ss(sy, prod);
            __m128 sz = _mm_shuffle_ps(prod, prod, 0xaa);
            __m128 dot = _mm_add_ss(sz, sy);
            __m128 qd2 = _mm_shuffle_ps(q, q, 0xd2);
            __m128 qc9 = _mm_shuffle_ps(q, q, 0xc9);
            vd2 = _mm_shuffle_ps(Vb.q, Vb.q, 0xd2);
            __m128 t1 = _mm_mul_ps(qc9, vd2);
            vc9 = _mm_shuffle_ps(Vb.q, Vb.q, 0xc9);
            __m128 t2 = _mm_mul_ps(qd2, vc9);
            t2 = _mm_sub_ps(t2, t1);
            t2 = _mm_mul_ps(t2, qw);
            __m128 ww = _mm_mul_ps(qw, qw);
            ww = _mm_add_ps(ww, *reinterpret_cast<const __m128*>(&DAT_010c71e0));
            ww = _mm_mul_ps(ww, Vb.q);
            __m128 dq = _mm_shuffle_ps(dot, dot, 0);
            dq = _mm_mul_ps(dq, q);
            __m128 res = _mm_add_ps(ww, dq);
            res = _mm_add_ps(t2, res);
            res = _mm_add_ps(res, res);
            records[a3].directionB = res;
        }
        {
            __m128 q = ptrA->m_10;
            __m128 prod = _mm_mul_ps(q, Vb.q);
            __m128 sy = _mm_shuffle_ps(prod, prod, 0x55);
            sy = _mm_add_ss(sy, prod);
            __m128 sz = _mm_shuffle_ps(prod, prod, 0xaa);
            __m128 qd2 = _mm_shuffle_ps(q, q, 0xd2);
            __m128 qc9 = _mm_shuffle_ps(q, q, 0xc9);
            __m128 qw = _mm_shuffle_ps(q, q, 0xff);
            __m128 t1 = _mm_mul_ps(qc9, vd2);
            __m128 t2 = _mm_mul_ps(qd2, vc9);
            t2 = _mm_sub_ps(t2, t1);
            t2 = _mm_mul_ps(t2, qw);
            __m128 ww = _mm_mul_ps(qw, qw);
            ww = _mm_add_ps(ww, *reinterpret_cast<const __m128*>(&DAT_010c71e0));
            ww = _mm_mul_ps(ww, Vb.q);
            __m128 dot = _mm_add_ss(sz, sy);
            __m128 dq = _mm_shuffle_ps(dot, dot, 0);
            dq = _mm_mul_ps(dq, q);
            __m128 res = _mm_add_ps(ww, dq);
            res = _mm_add_ps(t2, res);
            res = _mm_add_ps(res, res);
            records[a3].directionA = res;
        }
        {
            const __m128* pv = &records[a3].directionA;
            __m128 v = *pv;
            __m128 sq = _mm_mul_ps(v, v);
            __m128 ny = _mm_shuffle_ps(sq, sq, 0x55);
            ny = _mm_add_ss(ny, sq);
            __m128 nz = _mm_shuffle_ps(sq, sq, 0xaa);
            __m128 len = _mm_add_ss(nz, ny);
            __m128 rr = _mm_rsqrt_ss(len);
            __m128 lr = _mm_mul_ss(len, rr);
            lr = _mm_mul_ss(lr, rr);
            __m128 f = _mm_sub_ss(_mm_set_ss(DAT_01017718), lr);
            __m128 inv = _mm_mul_ss(_mm_set_ss(::fnv_00c88020::DAT_01016248), rr);
            inv = _mm_mul_ss(inv, f);
            __m128 isz = _mm_cmpeq_ss(len, _mm_load_ss(reinterpret_cast<const float*>(&DAT_01011d78)));
            __m128 sel = _mm_andnot_ps(isz, inv);
            __m128 splat = _mm_shuffle_ps(sel, sel, 0);
            records[a3].directionA = _mm_mul_ps(splat, v);
        }

        Obj1C* o = m_2a4->m_1c;
        if (o != 0 && a3 == 1)
        {
            _mm_store_ps(reinterpret_cast<float*>(&records[1].directionB), o->m_10);
            records[1].directionA = m_2a4->m_1c->m_20;
        }
        records[a3].state = m_88;
    }
    return ok;
}

union __declspec(align(16)) PitchRollQuad
{
    __m128 value;
    signed char m128_i8[16];
    PitchRollQuad& operator=(const PitchRollQuad& v)
    {
        value = v.value;
        return *this;
    }
    PitchRollQuad& operator=(const __m128& v)
    {
        value = v;
        return *this;
    }
};


struct __declspec(align(16)) FUN_005611c0_t
{
    PitchRollQuad value;
    void FUN_005611c0();
};

// @fnv 0x00c755e0
float Constraint::FUN_00c755e0(unsigned int index, InputRef input)
{
    float distance = 0.0f;
    __m128 oldPosition = entries[index].position.value;
    __m128 newPosition = input->value;
    __m128 difference = _mm_and_ps(_mm_sub_ps(newPosition, oldPosition), ::DAT_01017d10);
    __m128 epsilon;
    epsilon = _mm_set1_ps(::AngularDashpotApplyD4DCB0::DAT_01017d00);
    if ((_mm_movemask_ps(_mm_cmple_ps(difference, epsilon)) & 7) != 7)
    {
        Vector delta;
        reinterpret_cast<::Quat74 *>(&(delta))->FUN_00c74ac0((*(const ::Quat74 *)(const Vector*)(input)), (*(const ::Quat74 *)(&entries[index].position)));
        distance = reinterpret_cast<::C74C20Quat *>(&(delta))->GetAngle();
        float limit = enabled ? DAT_01267d30 : DAT_01267d24;
        if (distance > limit * ::DAT_01023128)
        {
            distance = (float)(limit * ::DAT_01023128);
            Vector axis;
            delta.FUN_00c74c90(&axis);
            axis.normalize();
            delta.FUN_00cb2450(&axis, distance);
        }
        {
            Vector result;
            ::fnv_00c66320::FUN_00c66320((__m128 *)&(result), (void *)(&delta), (const __m128 *)(const ::Vector *)(&entries[index].position), {});
            reinterpret_cast<::FUN_005611c0_t *>(&(result))->FUN_005611c0();
            TargetVector* target = ((::TargetVector *)&(reinterpret_cast<::PoseState *>((entries[index].holder))->FUN_00cda8e0(entries[index].index)));
            __m128 updated = result.value;
            target->vector.value = updated;
            entries[index].position.value = updated;
        }
    }
    return distance;
}

struct __declspec(align(16)) Rotation
{
    PitchRollQuad r0, r1, r2;
};

struct __declspec(align(16)) FUN_008cd6a0_Class
{
    PitchRollQuad r0, r1, r2, r3;
};

struct FUN_00c9e910_Class
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    FUN_008cd6a0_Class transform;
    void FUN_00c9e910(intptr_t);
};

struct TargetObject
{
    unsigned int unk00, unk04;
    FUN_00c9e910_Class* object;
};

struct RotationOwner
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int flags;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    float angle1;
    float angle2;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    TargetObject* target;
    void FUN_00c6e420(FUN_005611c0_t* arg);
};

// @fnv 0x00c6e420
void RotationOwner::FUN_00c6e420(FUN_005611c0_t* arg)
{
    FUN_005611c0_t vector;
    vector.value = arg->value;
    vector.FUN_005611c0();
    TargetObject* t = target;
    FUN_00c9e910_Class* object = t ? t->object : 0;
    FUN_008cd6a0_Class transform;
    transform.r0 = object->transform.r0;
    transform.r1 = object->transform.r1;
    transform.r2 = object->transform.r2;
    transform.r3 = object->transform.r3;
    reinterpret_cast<::RotationRows *>(&(transform))->FUN_00cb2d90(&vector);
    Rotation rotation;
    if (angle1 != 0.0f && (static_cast<unsigned char>(flags >> 25) & 1))
    {
        float c = static_cast<float>(std::cos(static_cast<double>(angle1)));
        float s = static_cast<float>(std::sin(static_cast<double>(angle1)));
        rotation.r0 = (_mm_setr_ps)(1.0f, 0.0f, 0.0f, 0.0f);
        rotation.r1 = (_mm_setr_ps)(0.0f, c, -s, 0.0f);
        rotation.r2 = (_mm_setr_ps)(0.0f, s, c, 0.0f);
        reinterpret_cast<::FUN_00cd5680_cls *>(&(transform))->FUN_00cd5680((intptr_t)(&rotation));
    }
    if (angle2 != 0.0f && (static_cast<unsigned char>(flags >> 26) & 1))
    {
        float c = static_cast<float>(std::cos(static_cast<double>(angle2)));
        float s = static_cast<float>(std::sin(static_cast<double>(angle2)));
        rotation.r0 = (_mm_setr_ps)(c, 0.0f, s, 0.0f);
        rotation.r1 = (_mm_setr_ps)(0.0f, 1.0f, 0.0f, 0.0f);
        rotation.r2 = (_mm_setr_ps)(-s, 0.0f, c, 0.0f);
        reinterpret_cast<::FUN_00cd5680_cls *>(&(transform))->FUN_00cd5680((intptr_t)(&rotation));
    }
    if (t)
    {
        FUN_00c9e910_Class* object = t->object;
        if (object)
        {
            ::FUN_00a29680();
            object->FUN_00c9e910((intptr_t)&transform);
            ::FUN_00a29680();
        }
    }
}

extern float DAT_01267d48, DAT_01267d54, DAT_01267d60, DAT_01267d6c, DAT_01267d78;

extern float DAT_01267dc0, DAT_01267dd8, DAT_01267da8, DAT_01267db4;

extern int DAT_01267dcc;

extern const float DAT_01011d78;

extern const P064Quad DAT_010ec7f0;

namespace FootIKDetail {

struct __declspec(align(16)) Scalar
{
    P064Quad value;
    __forceinline Scalar(const Scalar& x)
    {
        value = x.value;
    }
    __forceinline Scalar& operator=(const Scalar& x)
    {
        value = x.value;
        return *this;
    }
    __forceinline Scalar(float x)
    {
        value = _mm_load_ss(&x);
    }
    __forceinline Scalar(P064Quad x)
    {
        value = x;
    }
    __forceinline operator float() const
    {
        float x;
        _mm_store_ss(&x, value);
        return x;
    }
    __forceinline P064Quad splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline Scalar operator-() const
    {
        return Scalar(_mm_sub_ss(DAT_010c7160, value));
    }
};
struct __declspec(align(16)) Vec
{
    P064Quad v;
    __forceinline Vec()
    {}
    __forceinline Vec(const Vec& a)
    {
        v = a.v;
    }
    __forceinline Vec& operator=(const Vec& a)
    {
        v = a.v;
        return *this;
    }
    __forceinline void interpolateVector(const Vec& a, const Vec& b, const Scalar& t)
    {
        P064Quad w = t.splat();
        P064Quad remaining = _mm_sub_ps(DAT_010ec7f0, w);
        v = _mm_add_ps(_mm_mul_ps(remaining, a.v), _mm_mul_ps(w, b.v));
    }
};
struct __declspec(align(16)) Quaternion
{
    P064Quad v;
    __forceinline Quaternion()
    {}
    __forceinline Quaternion(const Quaternion& a)
    {
        v = a.v;
    }
    __forceinline Quaternion& operator=(const Quaternion& a)
    {
        v = a.v;
        return *this;
    }
    __declspec(noalias) void FUN_00c66320(const Quaternion&, const Quaternion&);
    void FUN_005611c0();
    void FUN_00cb2450(const Vec&, float);
};
struct __declspec(align(16)) Transform
{
    Vec translation;
    Quaternion rotation;
    Vec scale;
    __forceinline Transform()
    {}
    __forceinline Transform(const Transform& a)
    {
        translation.v = a.translation.v;
        rotation.v = a.rotation.v;
        scale.v = a.scale.v;
    }
    __forceinline void interpolate(const Transform&, const Transform&, const Scalar&);
    __forceinline void setInverseAfter(const Transform&);
    __forceinline void setInverseFinal(const Transform&);
    __forceinline void SetConjugate(const Transform&);
    __forceinline void setMulFinal(const Transform&, const Transform&);
    __forceinline void SetProduct(const Transform&, const Transform&);
    __forceinline Transform& operator=(const Transform& a)
    {
        translation.v = a.translation.v;
        rotation.v = a.rotation.v;
        scale.v = a.scale.v;
        return *this;
    }
};
template <class T> struct Array
{
    T* data;
    int size, capacity;
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
};
struct Skeleton
{
    int unk00, unk04, unk08;
    short* parents;
    int unk10, unk14, unk18;
    int count;
};
struct Pose
{
    Skeleton* skeleton;
    Transform* local;
    int unk08, unk0c;
    Transform* model;
    int unk14, unk18;
    // Cache bits: local invalid, model invalid, and temporary descendant mark.
    Array<unsigned int> flags;
    bool localDirty, modelDirty;
    __forceinline Transform& getModel(int i)
    {
        if (!(flags[i] & 2))
            return model[i];
        return (*(::FootIKDetail::Transform *)&(reinterpret_cast<::SkeletonPoseData *>(this)->FUN_00cda180(i)));
    }
    __forceinline Transform& getLocalAfter(int i);
    __forceinline Transform& getLocalFinal(int i);
    __forceinline Transform& getLocal(int i);
    __forceinline void propagateFinal(int i);
    __forceinline void propagate(int i);
};
struct Input
{
    Transform modelFromWorld;
    Transform worldFromModel;
    bool enabled;
    void* raycast;
    float gain, upGain, downGain, verticalError, ascendingGain, ungroundedGain;
    int unk80;
    bool unk84;
};
struct Output
{
    float height;
    bool hit;
};
struct Solver
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    short bone;
    short unk1a;
    int unk1c, unk20, unk24, unk28, unk2c;
    Vec target;
    Vec unk40, unk50, unk60, unk70;
    float offset;
    int unk84, unk88, unk8c;
};
struct Leg
{
    Solver* solver;
    float height;
    int unk08, unk0c;
    Vec unk10, unk20, unk30, unk40, unk50, unk60, unk70, unk80;
    Transform previous;
    short body;
    short unkc2;
    int unkc4, unkc8, unkcc;
};
struct Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int type();
    int unk04, unk08, unk0c;
    Vec vertices[10];
    unsigned char unkc0, unkc1, unkc2, vertex;
};
struct Body
{
    int unk00, unk04, unk08;
    Shape* shape;
};
struct Bodies
{
    int unk00, unk04, unk08, unk0c, unk10;
    Body** data;
    int unk18, unk1c;
    int* lookup;
};
struct Controller
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    Bodies* bodies;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84;
    Pose* pose;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    bool unk220, disabled, unk222, fullGain;
    int unk224;
    int frames;
    Leg* legs;
    int legCount;
    int unk234;
    short unk238, currentLeg;
    float height;
    bool blend, keepTarget, reset, fullBlend;
    float offset;
    void FUN_00c76350(const Transform&);
};
__forceinline float realValue(P064Quad v)
{
    float value;
    _mm_store_ss(&value, v);
    return value;
}

template <class C, class V> __forceinline V& component(C& object, V C::*entry)
{
    return object.*entry;
}
template <class C, class V> __forceinline const V& component(const C& object, V C::*entry)
{
    return object.*entry;
}
__forceinline void rotateInverseOut(P064Quad& out, const P064Quad& v, const P064Quad& q)
{
    P064Quad w = _mm_shuffle_ps(q, q, 0xff);
    P064Quad prod = _mm_mul_ps(v, q);
    P064Quad sum2 =
        _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa),
                                   _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9),
                                                                           _mm_shuffle_ps(q, q, 0xd2)),
                                                _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2),
                                                                           _mm_shuffle_ps(q, q, 0xc9)));
    cross = _mm_mul_ps(cross, w);
    P064Quad b =
        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    P064Quad c = _mm_mul_ps(_mm_shuffle_ps(sum2, sum2, 0), q);
    P064Quad r = _mm_add_ps(cross, _mm_add_ps(b, c));
    out = _mm_add_ps(r, r);
}
__forceinline void rotateForwardOut(P064Quad& out, const P064Quad& v, const P064Quad& q)
{
    P064Quad w = _mm_shuffle_ps(q, q, 0xff);
    P064Quad prod = _mm_mul_ps(q, v);
    P064Quad dot =
        _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa),
                                   _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2),
                                                                           _mm_shuffle_ps(q, q, 0xc9)),
                                                _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9),
                                                                           _mm_shuffle_ps(q, q, 0xd2)));
    P064Quad a = _mm_mul_ps(cross, w);
    P064Quad b =
        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    P064Quad c = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    P064Quad r = _mm_add_ps(a, _mm_add_ps(b, c));
    out = _mm_add_ps(r, r);
}
__forceinline void Transform::SetConjugate(const Transform& parent)
{
    rotateInverseOut(translation.v, parent.translation.v, parent.rotation.v);
    translation.v = _mm_xor_ps(translation.v, DAT_010c44d0);
    rotation.v = _mm_xor_ps(parent.rotation.v, DAT_010c4c00);
    P064Quad s = _mm_shuffle_ps(parent.scale.v,
                                                _mm_unpackhi_ps(parent.scale.v, DAT_010c7170), 0xc4);
    P064Quad r = _mm_rcp_ps(s);
    P064Quad correction = _mm_mul_ps(r, s);
    correction = _mm_mul_ps(correction, r);
    P064Quad twice = _mm_add_ps(r, r);
    r = _mm_sub_ps(twice, correction);
    scale.v = _mm_and_ps(r, DAT_010c4c10);
}
__forceinline void Transform::SetProduct(const Transform& a, const Transform& b)
{
    P064Quad rotated;
    rotateForwardOut(rotated, b.translation.v, a.rotation.v);
    translation.v = _mm_add_ps(rotated, a.translation.v);
    rotation.FUN_00c66320(a.rotation, b.rotation);
    scale.v = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&b.scale.v)), a.scale.v);
}
__forceinline void Transform::interpolate(const Transform& a, const Transform& b, const Scalar& t)
{
    scale.interpolateVector(a.scale, b.scale, t);
    translation.interpolateVector(a.translation, b.translation, t);
    float remaining = 1.0f - float(t);
    P064Quad prod = _mm_mul_ps(a.rotation.v, b.rotation.v);
    P064Quad pair = _mm_add_ps(_mm_shuffle_ps(prod, prod, 0x4e), prod);
    Scalar dot(_mm_add_ps(_mm_shuffle_ps(pair, pair, 0xb1), pair));
    const Scalar& signedT = float(dot) < 0.0f ? -t : t;
    float signedWeight = float(signedT);
    Quaternion mixed;
    P064Quad right = _mm_mul_ps(Scalar(signedWeight).splat(), b.rotation.v);
    mixed.v = _mm_add_ps(right, _mm_mul_ps(Scalar(remaining).splat(), a.rotation.v));
    reinterpret_cast<::FUN_005611c0_t *>(&(mixed))->FUN_005611c0();
    rotation = mixed;
}
__forceinline void relative(Pose* pose, int i, const Transform& parent, const Transform& child)
{
    Transform inverseTransform;
    Transform& destination = pose->local[i];
    inverseTransform.SetConjugate(parent);
    destination.SetProduct(inverseTransform, child);
}
__forceinline Transform& Pose::getLocal(int i)
{
    if (!(flags[i] & 1))
        return local[i];
    {
        const Transform& child = model[i];
        short p = skeleton->parents[i];
        if (p != -1)
        {
            const Transform& parent = getModel(p);
            relative(this, i, parent, child);
        }
        else
            local[i] = child;
        flags[i] &= ~1;
    }
    return local[i];
}
__forceinline void Pose::propagate(int i)
{
    // Preserve descendant locals before invalidating their model transforms.
    int n = skeleton->count;
    flags[i] |= 4;
    for (int j = i + 1; j < n; ++j)
    {
        short p = skeleton->parents[j];
        if (p != -1 && (flags[p] & 4))
        {
            getLocal(j);
            flags[j] |= 4;
            localDirty = false;
        }
    }
    for (int j = i + 1; j < n; ++j)
    {
        unsigned int& f = flags[j];
        if (f & 4)
            f = (f & ~4) | 2;
    }
}
__forceinline float lower(float a, float b)
{
    return a < b ? a : b;
}
__forceinline float upper(float a, float b)
{
    return a > b ? a : b;
}

struct RealRef
{
    const float* data;
    __forceinline RealRef(const float& x) : data(&x)
    {}
    __forceinline operator float() const
    {
        return *data;
    }
};

__forceinline void adjustRoot(Vec& position, const float& height, float& adjustment)
{
    RealRef oldHeight(position.v[2]);
    float target = oldHeight;
    target += height;
    RealRef gain(DAT_01267dc0);
    float smooth = height * gain + oldHeight;
    float delta = smooth - target;
    float maxDelta = DAT_01267dd8;
    if (delta > maxDelta)
        smooth = target + maxDelta;
    if (delta < -maxDelta)
        smooth = target - maxDelta;
    adjustment = smooth - oldHeight;
    component(position, &Vec::v)[2] = smooth;
}

__forceinline void Transform::setInverseAfter(const Transform& parent)
{
    rotateInverseOut(translation.v, parent.translation.v, parent.rotation.v);
    translation.v = _mm_xor_ps(translation.v, DAT_010c44d0);
    rotation.v = _mm_xor_ps(parent.rotation.v, _mm_load_ps(reinterpret_cast<float*>(&DAT_010c4c00)));
    P064Quad s = _mm_shuffle_ps(parent.scale.v,
                                                _mm_unpackhi_ps(parent.scale.v, DAT_010c7170), 0xc4);
    P064Quad r = _mm_rcp_ps(s);
    P064Quad correction = _mm_mul_ps(r, s);
    correction = _mm_mul_ps(correction, r);
    P064Quad twice = _mm_add_ps(r, r);
    r = _mm_sub_ps(twice, correction);
    scale.v = _mm_and_ps(r, DAT_010c4c10);
}

__forceinline void relativeAfter(Pose* pose, int i, const Transform& parent, const Transform& child)
{
    Transform inverseTransform;
    Transform& destination = pose->local[i];
    inverseTransform.setInverseAfter(parent);
    destination.SetProduct(inverseTransform, child);
}

__forceinline Transform& Pose::getLocalAfter(int i)
{
    if (!(flags[i] & 1))
        return local[i];
    {
        const Transform& child = model[i];
        short p = skeleton->parents[i];
        if (p != -1)
        {
            const Transform& parent = getModel(p);
            relativeAfter(this, i, parent, child);
        }
        else
            local[i] = child;
        flags[i] &= ~1;
    }
    return local[i];
}

__forceinline void rotateInverseOutFinal(P064Quad& out, const P064Quad& v, const P064Quad& q)
{
    P064Quad w = _mm_shuffle_ps(q, q, 0xff);
    P064Quad prod = _mm_mul_ps(v, q);
    P064Quad sum2 =
        _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa),
                                   _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9),
                                                                           _mm_shuffle_ps(q, q, 0xd2)),
                                                _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2),
                                                                           _mm_shuffle_ps(q, q, 0xc9)));
    cross = _mm_mul_ps(cross, w);
    P064Quad b =
        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    P064Quad c = _mm_mul_ps(_mm_shuffle_ps(sum2, sum2, 0), q);
    P064Quad r = _mm_add_ps(cross, _mm_add_ps(b, c));
    out = _mm_add_ps(r, r);
}

__forceinline void rotateForwardOutFinal(P064Quad& out, const P064Quad& v, const P064Quad& q)
{
    P064Quad w = _mm_shuffle_ps(q, q, 0xff);
    P064Quad prod = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&q)), v);
    P064Quad dot =
        _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa),
                                   _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2),
                                                                           _mm_shuffle_ps(q, q, 0xc9)),
                                                _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9),
                                                                           _mm_shuffle_ps(q, q, 0xd2)));
    P064Quad a = _mm_mul_ps(cross, w);
    P064Quad b =
        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
    P064Quad c = _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q);
    P064Quad r = _mm_add_ps(a, _mm_add_ps(b, c));
    out = _mm_add_ps(r, r);
}

__forceinline void Transform::setInverseFinal(const Transform& parent)
{
    rotateInverseOutFinal(translation.v, parent.translation.v, parent.rotation.v);
    translation.v = _mm_xor_ps(translation.v, DAT_010c44d0);
    rotation.v = _mm_xor_ps(parent.rotation.v, DAT_010c4c00);
    P064Quad s = _mm_shuffle_ps(parent.scale.v,
                                                _mm_unpackhi_ps(parent.scale.v, DAT_010c7170), 0xc4);
    P064Quad r = _mm_rcp_ps(s);
    P064Quad correction = _mm_mul_ps(r, s);
    correction = _mm_mul_ps(correction, r);
    P064Quad twice = _mm_add_ps(r, r);
    r = _mm_sub_ps(twice, correction);
    scale.v = _mm_and_ps(r, DAT_010c4c10);
}

__forceinline void Transform::setMulFinal(const Transform& a, const Transform& b)
{
    P064Quad rotated;
    rotateForwardOutFinal(rotated, b.translation.v, a.rotation.v);
    translation.v = _mm_add_ps(rotated, a.translation.v);
    rotation.FUN_00c66320(a.rotation, b.rotation);
    scale.v = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&b.scale.v)), a.scale.v);
}

__forceinline void relativeFinal(Pose* pose, int i, const Transform& parent, const Transform& child)
{
    Transform inverseTransform;
    Transform& destination = pose->local[i];
    inverseTransform.setInverseFinal(parent);
    destination.setMulFinal(inverseTransform, child);
}

__forceinline Transform& Pose::getLocalFinal(int i)
{
    if (!(flags[i] & 1))
        return local[i];
    {
        const Transform& child = model[i];
        short p = skeleton->parents[i];
        if (p != -1)
        {
            const Transform& parent = getModel(p);
            relativeFinal(this, i, parent, child);
        }
        else
            local[i] = child;
        flags[i] &= ~1;
    }
    return local[i];
}

__forceinline void Pose::propagateFinal(int i)
{
    // Preserve descendant locals before invalidating their model transforms.
    int n = skeleton->count;
    flags[i] |= 4;
    for (int j = i + 1; j < n; ++j)
    {
        short p = skeleton->parents[j];
        if (p != -1 && (flags[p] & 4))
        {
            getLocalFinal(j);
            flags[j] |= 4;
            localDirty = false;
        }
    }
    for (int j = i + 1; j < n; ++j)
    {
        unsigned int& f = flags[j];
        if (f & 4)
            f = (f & ~4) | 2;
    }
}

// @fnv 0x00c76350
void Controller::FUN_00c76350(const Transform& world)
{
    Input inputData;
    reinterpret_cast<::FUN_00cd8a10_cls *>(&(inputData))->InitializeDefaults();
    Output result;
    inputData.worldFromModel = world;
    inputData.gain = !fullGain ? DAT_01267d48 : 1.0f;
    inputData.upGain = DAT_01267d54;
    inputData.downGain = DAT_01267d60;
    inputData.ascendingGain = DAT_01267d6c;
    inputData.verticalError = DAT_01267d78;
    if (!fullGain)
        inputData.enabled = !disabled;
    else
        inputData.enabled = false;
    inputData.raycast = this;
    {
        Transform rootTransform = pose->getModel(0);
        Vec rootPosition = rootTransform.translation;
        float adjustment;
        adjustRoot(rootPosition, height, adjustment);
        rootTransform.translation = rootPosition;
        P064Quad shift = _mm_setr_ps(DAT_01011d78, DAT_01011d78, adjustment, DAT_01011d78);
        inputData.worldFromModel.translation.v =
            _mm_add_ps(shift, inputData.worldFromModel.translation.v);
        Pose* p = pose;
        p->propagate(0);
        Transform& saved = p->model[0];
        saved = rootTransform;
        p->flags[0] = 1;
        p->modelDirty = false;
    }
    for (int i = 0; i < legCount; ++i)
    {

        Vec rootOut = legs[i].solver->target;
        legs[i].solver->offset = offset;
        if (!keepTarget)
            legs[i].solver->target.v = _mm_setzero_ps();
        short bone = legs[i].solver->bone;
        Transform original = pose->getLocal(bone);
        component(inputData, &Input::modelFromWorld) = pose->getModel(legs[i].solver->bone);
        currentLeg = (short)i;
        unk238 = 0;
        float start = ::GetElapsedSeconds();

        ::FUN_00cd8d90((::NativeSolver *)(legs[i].solver), (void *)&(inputData), (const ::NativeInput &)(result), (*(::NativeOutput *)(pose)), *(::NativePose *)nullptr);
        float q = ::GetElapsedSeconds();
        legs[i].height = component(result, &Output::height);
        ::DAT_01267c1c += (q - start) * 1000.0;
        Transform solved = pose->getLocalAfter(bone);
        if (blend)
        {
            if (reset)
                legs[i].previous = solved;
            short high = legs[i].body;
            if (high != -1)
            {
                int index = bodies->lookup[high] - 1;
                Body* body = 0 > index ? 0 : bodies->data[index];
                Shape* shape = body->shape;
                if (shape->type() == 13)
                    shape = ((::FootIKDetail::Shape *)(reinterpret_cast<::MalleableGetterStandIn *>((shape))->FUN_00cdf6c0()));
                if (shape->type() == 2)
                {
                    Vec axis = shape->vertices[shape->vertex];
                    Vec perpendicular;
                    float end;
                    reinterpret_cast<::hkQuaternion *>(&(solved.rotation))->FUN_00cb2ca0((const ::hkVector4 &)(axis), (::hkQuaternion &)(perpendicular), end);
                    solved.rotation.FUN_00cb2450(axis, end);
                }
            }
            Scalar t(::fnv_00c88020::DAT_01016248);
            original.interpolate(solved, legs[i].previous, t);
            legs[i].previous = original;
        }
        Pose* p = pose;
        p->propagateFinal(bone);
        p->local[bone] = original;
        p->flags[bone] = 2;
        p->localDirty = false;
        legs[i].solver->target = rootOut;
    }
    if (reset)
        reset = false;
    float weight = fullBlend ? 1.0f : DAT_01267da8;
    float a = legs[0].height;
    float b = legs[1].height;
    float low = lower(a, b);
    float a2 = legs[0].height;
    float b2 = legs[1].height;
    float bodyIndex = upper(a2, b2);
    if (!disabled)
    {
        float delta = weight * low + (1.0f - weight) * bodyIndex;
        delta *= DAT_01267db4;
        height += delta;
    }
    float second = height;
    float raised = ::g_011da6a4_arg1 < second ? second : ::g_011da6a4_arg1;
    float capped = ::DAT_0101712c > raised ? raised : ::DAT_0101712c;
    height = capped;
    if (disabled)
    {
        height *= DAT_010217d8;
        frames++;
        int frameCount = frames;
        _ReadWriteBarrier();
        if (DAT_01267dcc == frameCount)
        {
            fullGain = false;
            frames = 0;
            disabled = false;
            unk222 = false;
            reset = true;
            return;
        }
        fullGain = false;
    }
    else
    {
        _ReadWriteBarrier();
        fullGain = false;
    }
}

inline void quaternionProduct(P064Quad& out, const Quaternion& a, const Quaternion& b)
{

    P064Quad left = a.v;
    P064Quad right = b.v;
    P064Quad cross =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(right, right, 0xd2),
                                                              _mm_shuffle_ps(left, left, 0xc9)),
                                   _mm_mul_ps(_mm_shuffle_ps(right, right, 0xc9),
                                                              _mm_shuffle_ps(left, left, 0xd2)));
    P064Quad lw = _mm_shuffle_ps(left, left, 0xff);
    P064Quad rw = _mm_shuffle_ps(right, right, 0xff);
    P064Quad xyz =
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(lw, lw, 0), right), cross);
    xyz = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(rw, rw, 0), left), xyz);
    P064Quad prod = _mm_mul_ps(right, left);
    P064Quad dot =
        _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa),
                                   _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
    P064Quad w = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
    Quaternion result;
    result.v = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, w), 0xc4);
    out = result.v;
}

__declspec(noinline) void Quaternion::FUN_00c66320(const Quaternion& a, const Quaternion& b)
{
    P064Quad value;
    quaternionProduct(value, a, b);
    v = value;
}

}


#include "generated/data/staging/blk_00c60000_od.inc"
#include "generated/data/staging/blk_00c60000_od_ob1_variant.inc"
#include "generated/data/staging/blk_00c60000_od_o2_nood_variant.inc"
#include "generated/data/staging/blk_00c60000_od_o2_gf_nood_variant.inc"
#include "generated/data/staging/blk_00c60000_od_o2_nood_variant_iso_variant.inc"
#include "generated/data/staging/blk_00c60000_od_o2_nood_variant_rtm_variant.inc"
