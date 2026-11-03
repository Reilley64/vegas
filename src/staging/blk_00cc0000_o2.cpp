// staging/blk_00cc0000_o2.cpp: CacheOwner_cls, Owner, Obj, hkVector4CDA and more (425 functions)
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c90000.h"
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <math.h>

// src/staging/blk_00cc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include "runtime/crt.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C89AC0_Owner.h"
#include "fnv/decl/C9FC00Object.h"
#include "fnv/decl/Cc7Owner.h"
#include "fnv/decl/Cls_00c9fbc0.h"
#include "fnv/decl/Cls_d48150.h"
#include "fnv/decl/ContactManifold.h"
#include "fnv/decl/ConvexVertsQ_d59200.h"
#include "fnv/decl/D53360Owner.h"
#include "fnv/decl/Dispatch_00c89dd0.h"
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0056e0b0.h"
#include "fnv/decl/FUN_00a5d3a0.h"
#include "fnv/decl/FUN_00a5d430_Class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/FUN_00c84d00_cls.h"
#include "fnv/decl/FUN_00c84d50_cls.h"
#include "fnv/decl/FUN_00c84dc0_cls.h"
#include "fnv/decl/FUN_00c84df0_cls.h"
#include "fnv/decl/FUN_00c867d0_cls.h"
#include "fnv/decl/FUN_00c86800_Class.h"
#include "fnv/decl/FUN_00c868b0_cls.h"
#include "fnv/decl/FUN_00c876d0_cls.h"
#include "fnv/decl/FUN_00c87c30_t.h"
#include "fnv/decl/FUN_00c89c80_obj.h"
#include "fnv/decl/FUN_00c8a7a0_cls.h"
#include "fnv/decl/FUN_00c8a800_cls.h"
#include "fnv/decl/FUN_00c903a0_class.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00ca9360_cls.h"
#include "fnv/decl/FUN_00ca9840_Class.h"
#include "fnv/decl/FUN_00ca9e50_Obj.h"
#include "fnv/decl/FUN_00cca8d0.h"
#include "fnv/decl/FUN_00cce900.h"
#include "fnv/decl/FUN_00ccea00Holder.h"
#include "fnv/decl/FUN_00ccf4f0_cls.h"
#include "fnv/decl/FUN_00ccf740_cls.h"
#include "fnv/decl/FUN_00cd2de0.h"
#include "fnv/decl/FUN_00d21ce0_cls.h"
#include "fnv/decl/FUN_00d274c0.h"
#include "fnv/decl/FUN_00d54960.h"
#include "fnv/decl/FUN_00d5e0c0_Obj.h"
#include "fnv/decl/FloatMatrix3.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/FnvCpu_FUN_00d58d50_CpuObject.h"
#include "fnv/decl/LunaTarget.h"
#include "fnv/decl/MProduct.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyOwner.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/Owner253.h"
#include "fnv/decl/Owner89730.h"
#include "fnv/decl/OwnerD500.h"
#include "fnv/decl/ProjectileListener.h"
#include "fnv/decl/QTF.h"
#include "fnv/decl/RefChainOwner.h"
#include "fnv/decl/S004b4db0_Quaternion.h"
#include "fnv/decl/S00c8bf40_Flags.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/S_00c8a280_Obj.h"
#include "fnv/decl/S_00ca4e10_Cls.h"
#include "fnv/decl/S_00ca4ec0.h"
#include "fnv/decl/ShapeViewerFields.h"
#include "fnv/decl/SkeletonPoseData.h"
#include "fnv/decl/SpawnedOwnerQ.h"
#include "fnv/decl/SphereShape.h"
#include "fnv/decl/StringBuilder_ca5190.h"
#include "fnv/decl/This_2.h"
#include "fnv/decl/VariantListD480.h"
#include "fnv/decl/WorldObjectCC3.h"
#include "fnv/decl/WorldObjectView.h"
#include "fnv/decl/Wrapper86b80.h"
#include "fnv/decl/bhkBoxShape.h"
#include "fnv/decl/bhkListShapeD53.h"
#include "fnv/decl/bhkViewerObject.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00a65800__NiObjectArrayRt.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c86790__Holder.h"
#include "fnv/decl/fnv_00c9ecb0__FUN_00c9ecb0_cls.h"
#include "fnv/decl/fnv_00ca9da0__FUN_00ca9da0_cls.h"
#include "fnv/decl/fnv_00cb2700__PerpendicularVector.h"
#include "fnv/decl/fnv_00cc49b0__FUN_00cc49b0_class.h"
#include "fnv/decl/fnv_00cc91c0__FUN_00cc91c0_cls.h"
#include "fnv/decl/fnv_00d4f850__FUN_00d4f850_class.h"
#include "fnv/decl/hkMalleableConstraintData.h"
#include "fnv/decl/hkMatrix3CD4B.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpCylinderShapeGetCylRadius.h"
#include "fnv/decl/hkpD500Object.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c84000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00c8a000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c9f000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00cc5000.h"
#include "fnv/symbols_00cca000.h"
#include "fnv/symbols_00cde000.h"
#include "fnv/symbols_00cf0000.h"
#include "fnv/symbols_00cf1000.h"
#include "fnv/symbols_00cf4000.h"
#include "fnv/symbols_00d27000.h"
#include "fnv/symbols_00d2c000.h"
#include "fnv/symbols_00d47000.h"
#include "fnv/symbols_00d48000.h"
#include "fnv/symbols_00d50000.h"
#include "fnv/symbols_00d5a000.h"
#include "fnv/symbols_00d6b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104f000.h"
#include "fnv/symbols_01050000.h"
#include "fnv/symbols_01053000.h"
#include "fnv/symbols_0108f000.h"
#include "fnv/symbols_01094000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010c5000.h"
#include "fnv/symbols_010c7000.h"
#include "fnv/symbols_010c9000.h"
#include "fnv/symbols_010ca000.h"
#include "fnv/symbols_011b1000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "../../include/layout_support.h"
#include <xmmintrin.h>
#include <string.h>
#include <intrin.h>
#include "fnv/symbols_simd.h"
#include "fnv/decl/FUN_004381b0_shell.h"
#include "fnv/decl/FUN_00a5d2f0_class.h"
#include "fnv/decl/FUN_00ccd080.h"
#include "fnv/decl/FUN_00d50020.h"
#include "fnv/decl/FUN_00d54e60.h"
#include "fnv/decl/FnvCpu_FUN_00c89720_CpuInterface.h"
#include "fnv/decl/S_00c6d5c0.h"
#include "fnv/decl/VectorSourceB00.h"
#include "fnv/decl/hkpCharacterStateView.h"
#include "fnv/symbols_00cc1000.h"
#include "fnv/symbols_00cc2000.h"
#include "fnv/symbols_00cc3000.h"
#include "fnv/symbols_00cc4000.h"
#include "fnv/symbols_00cc6000.h"
#include "fnv/symbols_00cc7000.h"
#include "fnv/symbols_00cc9000.h"
#include "fnv/symbols_00ccb000.h"
#include "fnv/symbols_00ccd000.h"
#include "fnv/symbols_00cce000.h"
#include "fnv/symbols_00cd7000.h"
#include "fnv/symbols_00cdf000.h"
#include "fnv/symbols_00d6a000.h"

struct hkReferencedObject {
};
struct hkOstream {
    void* m_pVtable;
    unsigned short m_iFlags;
    unsigned short m_iUnk;
    void* m_pSharedOwner;
    hkOstream* FUN_00cc00b0(void* owner);
};
// @fnv 0x00cc00b0
hkOstream* hkOstream::FUN_00cc00b0(void* owner)
{
    m_iUnk = 1;
    m_pVtable = &DAT_010c9314;
    m_pSharedOwner = owner;
    if (owner)
        reinterpret_cast<::FUN_00c903a0_class *>((((hkReferencedObject*)owner)))->FUN_00c903a0();
    return this;
}


void __cdecl FUN_00cc1520();

struct FUN_00cc1710_Class {
    FUN_00cc1710_Class* FUN_00cc1710(int a);
};

// Calls FUN_00cc1520, then if bit 0 of a is set frees this with _delete, and returns this.
// @fnv 0x00cc1710
FUN_00cc1710_Class* FUN_00cc1710_Class::FUN_00cc1710(int aiFlags)
{
    FUN_00cc1520();
    if (aiFlags & 1)
        ::FUN_00aa1460(this, 24);
    return this;
}

class NiObject;
struct NiStream {  public:
    ::NiObject *GetLoadedObject();
public:
    ::NiObject *DeserializeObject();
};
struct NiExtraData { void LoadBinary(NiStream&); };
struct FUN_00cc1970 : NiExtraData {
    void LoadBinary(NiStream& stream);
};
// @fnv 0x00cc1970
void FUN_00cc1970::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    reinterpret_cast<::S_00a64670_Foo *>(&(stream))->FUN_00a64670();
}

struct NiStream;

struct FUN_00a7b290_shell
{
};

struct FUN_00cc1990_class : FUN_00a7b290_shell
{
    bool FUN_00cc1990(NiStream* apStream);
};

// @fnv 0x00cc1990
bool FUN_00cc1990_class::FUN_00cc1990(NiStream* apStream)
{
    bool bResult = reinterpret_cast<::MyOwner *>(this)->FUN_00a7b290((*(::NiStream *)(apStream)));

    unsigned int ItemUpdateArray = *(unsigned int*)((char*)this + 0x1c);
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        void* pObject = *(void**)(*(char**)((char*)this + 0x10) + i * 4);
        if (pObject)
        {
            void** ppVtbl = *(void***)pObject;
            ((void (*)(void*, NiStream*))ppVtbl[21])(pObject, apStream);
        }
    }

    return bResult;
}

extern "C" void NiFreeAlias(void*);
extern int DAT_010c9490;

struct FUN_00cc1ab0_class {
    void DestroyAndFreeAlias();
};

// @fnv 0x00cc1ab0
void FUN_00cc1ab0_class::DestroyAndFreeAlias()
{
    *(int**)this = &DAT_010c9490;
    NiFreeAlias(*(void**)((char*)this + 4));
}

void __cdecl FUN_00cc1e40();


struct FUN_00cc1f60_Class {
    void* FUN_00cc1f60(bool flag);
};

// Calls FUN_00cc1e40, then deletes this (size 0x24) when flag bit 0 is set, and returns this.
// @fnv 0x00cc1f60
void* FUN_00cc1f60_Class::FUN_00cc1f60(bool flag)
{
    FUN_00cc1e40();
    if (flag & 1)
        operator delete(this, 0x24);
    return this;
}

void __cdecl FUN_00cc2ac0();
struct FUN_00cc2b40_class {
    FUN_00cc2b40_class* FUN_00cc2b40(int flag);
};
// Calls FUN_00cc2ac0, frees this with operator delete when flag bit 0 is set, and returns this.
// @fnv 0x00cc2b40
FUN_00cc2b40_class* FUN_00cc2b40_class::FUN_00cc2b40(int flag)
{
    FUN_00cc2ac0();
    if (flag & 1)
        operator delete(this, 0x10);
    return this;
}

namespace fnv_00cc3a30 {

void __cdecl FUN_00cc39b0();

struct GSGeometry
{
    GSGeometry();
    ~GSGeometry();
    GSGeometry* FUN_00cc3a30(int flags);
};

// Calls FUN_00cc39b0, deletes this with size 0x10 when flags has bit 0 set, and returns this.
// @fnv 0x00cc3a30
GSGeometry* GSGeometry::FUN_00cc3a30(int flags)
{
    FUN_00cc39b0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}
}  // namespace fnv_00cc3a30

namespace fnv_00cc5110 {

void FUN_00cc5090();

struct FUN_00cc5110_Class {
    FUN_00cc5110_Class* FUN_00cc5110(int flags);
};

// Calls FUN_00cc5090, then deletes this with size 0x10 if flags has bit 0 set, and returns this.
// @fnv 0x00cc5110
FUN_00cc5110_Class* FUN_00cc5110_Class::FUN_00cc5110(int flags)
{
    FUN_00cc5090();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}
}  // namespace fnv_00cc5110

namespace fnv_00cc74e0 {

void __cdecl FUN_00cc7450();

struct FUN_00cc74e0_Class {
    void FUN_00cc7450();
    void* FUN_00cc74e0(int flags);
};

// Calls FUN_00cc7450, then deletes this with size 16 when flags has bit 0 set, and returns this.
// @fnv 0x00cc74e0
void* FUN_00cc74e0_Class::FUN_00cc74e0(int flags)
{
    FUN_00cc7450();
    if (flags & 1)
        operator delete(this, 16);
    return this;
}
}  // namespace fnv_00cc74e0

namespace fnv_00cc8500 {

struct FUN_00cc8500_class {
    void FUN_00cc8480();
    void* FUN_00cc8500(int flags);
};

// Calls FUN_00cc8480, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00cc8500
void* FUN_00cc8500_class::FUN_00cc8500(int flags)
{
    FUN_00cc8480();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}
}  // namespace fnv_00cc8500

struct MemoryManager {  };
struct MM {  };
extern int DAT_0108ffb4;
struct FUN_009ba5f0_shell
{
public:
    void ReleaseObject(::hkReferencedObject *, int);
};
struct FUN_00cc8920_shell : FUN_009ba5f0_shell {
    int* m_p;
    FUN_00cc8920_shell* FUN_00cc8920(int a);
};
// Sets m_p to DAT_0108ffb4, calls SetChildObject(0), and if bit 0 of a is set deallocates this via g_memoryManager, returning this.
// @fnv 0x00cc8920
FUN_00cc8920_shell* FUN_00cc8920_shell::FUN_00cc8920(int a)
{
    m_p = &DAT_0108ffb4;
    reinterpret_cast<::C89AC0_Owner *>(this)->SetChildObject((::C89AC0_Child *)(0));
    if (a & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

namespace fnv_00cc8d80 {
void FUN_00d53220();


struct FUN_00cc8d80_class {
    FUN_00cc8d80_class* FUN_00cc8d80(int);
};

// Calls FUN_00d53220, deletes this with size 0x10 when bit 0 of arg is set, and returns this.
// @fnv 0x00cc8d80
FUN_00cc8d80_class* FUN_00cc8d80_class::FUN_00cc8d80(int arg)
{
    FUN_00d53220();
    if (arg & 1)
        operator delete(this, 0x10);
    return this;
}
}  // namespace fnv_00cc8d80

void __cdecl FUN_00cc8ce0();
struct FUN_00cc8da0_Class {
    FUN_00cc8da0_Class* FUN_00cc8da0(bool b);
};
// Calls FUN_00cc8ce0, then deletes this object with size 16 when b has bit 0 set, and returns this.
// @fnv 0x00cc8da0
FUN_00cc8da0_Class* FUN_00cc8da0_Class::FUN_00cc8da0(bool b)
{
    FUN_00cc8ce0();
    if (b & 1)
        operator delete(this, 16);
    return this;
}

extern "C" void __cdecl FUN_00d54e60();

struct FUN_00ccb160_class {
    void* FUN_00ccb160(int arg);
};

// @fnv 0x00ccb160
void* FUN_00ccb160_class::FUN_00ccb160(int arg)
{
    FUN_00d54e60();
    if (arg & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}

void __cdecl FUN_00ccbc00();


struct FUN_00ccc420_class {
    void* FUN_00ccc420(int);
};

// Calls FUN_00ccbc00, then if bit 0 of a is set frees this with size 0x18, and returns this.
// @fnv 0x00ccc420
void* FUN_00ccc420_class::FUN_00ccc420(int aiFlags)
{
    FUN_00ccbc00();
    if (aiFlags & 1)
        ::FUN_00aa1460(this, 0x18);
    return this;
}


struct FUN_00ccc720_holder {
    void FUN_00ccc720();
    void* DestroyHolder(int arg);
};

void FUN_00ccd080();


struct FUN_00ccd150_cls {
    FUN_00ccd150_cls* FUN_00ccd150(int flags);
};

// Calls FUN_00ccd080, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00ccd150
FUN_00ccd150_cls* FUN_00ccd150_cls::FUN_00ccd150(int flags)
{
    FUN_00ccd080();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}


struct FUN_00ccf870_class {
    int FUN_00ccf870(int flags);
};

// @fnv 0x00ccf870
int FUN_00ccf870_class::FUN_00ccf870(int flags)
{
    reinterpret_cast<::FUN_00ccf740_cls *>(this)->FUN_00ccf740_cls::~FUN_00ccf740_cls();
    if (flags & 1)
        ::FUN_00aa1460((void*)this, 0x14);
    return (int)this;
}


struct FUN_00cd3290_class {
    void FUN_00cd3290();
};

// @fnv 0x00cd3290
void FUN_00cd3290_class::FUN_00cd3290()
{
    *(float*)((char*)this + 4) = ::DAT_0104da48;
    *(int*)((char*)this + 0x14) = 0;
}

namespace fnv_00cd7f30 {

void __cdecl FUN_00ccdbc0();

struct FUN_00cd7f30_class {
    FUN_00cd7f30_class* FUN_00cd7f30(unsigned char flags);
};

// Calls FUN_00ccdbc0, then frees this with _delete when bit 0 of flags is set, and returns this.
// @fnv 0x00cd7f30
FUN_00cd7f30_class* FUN_00cd7f30_class::FUN_00cd7f30(unsigned char flags)
{
    FUN_00ccdbc0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}
}  // namespace fnv_00cd7f30

struct FUN_00cdea00_cls {
    void FUN_00cdea00(char param_2);
};

// @fnv 0x00cdea00
void FUN_00cdea00_cls::FUN_00cdea00(char param_2)
{
    ((char*)this)[0x116] = (param_2 != 0) * 0x38;
}

struct FUN_00cdf250_class {
    void FUN_00cdf250(int a);
};

// @fnv 0x00cdf250
void FUN_00cdf250_class::FUN_00cdf250(int a)
{
    reinterpret_cast<::MProduct *>((((FUN_00cdf250_class*)((char*)this + 0xb0))))->FUN_00cd55b0((*(const ::MProduct *)((int*)a)), (*(const ::MProduct *)((int)((char*)this + 0x20))));
}

namespace fnv_00cdf7a0 {
extern int DAT_010c82a4;
struct hkReferencedObject {  };
struct FUN_00cdf7a0Class {
    int m_vtbl;
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    hkReferencedObject* m_ref;
    void FUN_00cdf7a0();
};
// @fnv 0x00cdf7a0
void FUN_00cdf7a0Class::FUN_00cdf7a0()
{
    hkReferencedObject* ref = m_ref;
    *(void**)this = (void*)&DAT_010c82a4;
    reinterpret_cast<::hkReferencedObjectC905 *>((ref))->FUN_00c905b0();
    *(void**)this = (void*)&(*reinterpret_cast<int *>(&::DAT_0102e388));
}
}  // namespace fnv_00cdf7a0

void __cdecl NiFreeAlias(void* p);
struct FUN_00cc19e0_class {
    void* m_kPointA;
    void* m_p;
    void* FUN_00cc19e0(bool flag);
};
// @fnv 0x00cc19e0
void* FUN_00cc19e0_class::FUN_00cc19e0(bool abFree)
{
    void* p = m_p;
    m_kPointA = &DAT_010c9490;
    NiFreeAlias(p);
    if (abFree & 1) reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

extern int DAT_0126810c;
extern int DAT_01268238;
extern int DAT_01268208;
extern int DAT_012685a0;
struct bhkRefObject {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned char m_bFlag;
};
struct FUN_00cc23c0_class {
    bhkRefObject* InitializeRefObject();
};
// Calls Initialize, sets the vtable and clears data fields and a flag, incrementing four global counters along the way.
// @fnv 0x00cc23c0
bhkRefObject* FUN_00cc23c0_class::InitializeRefObject()
{
    bhkRefObject* self = (bhkRefObject*)this;
    reinterpret_cast<::FUN_00c87c30_t *>((self))->FUN_00c87c30();
    self->m_pVtable = (void*)&DAT_01030394;
    self->m_uiData1 = 0;
    self->m_uiData2 = 0;
    DAT_0126810c += 1;
    self->m_pVtable = (void*)&DAT_0103078c;
    DAT_01268238 += 1;
    self->m_pVtable = (void*)&DAT_010306b4;
    DAT_01268208 += 1;
    self->m_bFlag = 0;
    self->m_pVtable = (void*)&DAT_010c4694;
    DAT_012685a0 += 1;
    self->m_bFlag = 0;
    return self;
}

struct FUN_00cc3d30_class {
    void* m_p;
    void* m_pUnk0;
    void* m_pUnk1;
    void* m_pData;
    void FreeDataIfRequested(bool flag);
};

// If flag is set, deallocates the block preceding m_pData and clears m_pData.
// @fnv 0x00cc3d30
void FUN_00cc3d30_class::FreeDataIfRequested(bool abFree)
{
    if (abFree) {
        if (m_pData)
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060((char*)m_pData - *(unsigned char*)((char*)m_pData - 1));
        m_pData = 0;
    }
}

struct bhkConstraint {
    virtual ~bhkConstraint();
};
extern int DAT_0126860c;
struct FUN_00cc66b0 : bhkConstraint {
    ~FUN_00cc66b0();
};
// @fnv 0x00cc66b0
FUN_00cc66b0::~FUN_00cc66b0()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_0126860c;
}

namespace fnv_00cca950 {
extern int DAT_01268660;
extern int DAT_010ca3f4;
struct bhkRefObject {
};
struct FUN_00cca950_class {
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiValue2;
    unsigned int m_uiExtra2;
    FUN_00cca950_class* FUN_00cca950();
};
// @fnv 0x00cca950
FUN_00cca950_class* FUN_00cca950_class::FUN_00cca950()
{
    reinterpret_cast<::FUN_00c87c30_t *>((((bhkRefObject*)this)))->FUN_00c87c30();
    m_uiValue2 = 0;
    m_uiExtra2 = 0;
    m_ppVirtualMethodTable = (void*)&::DAT_01030bf4;
    ++DAT_012680f8;
    m_ppVirtualMethodTable = (void*)&::DAT_01030b0c;
    ++DAT_01268274;
    m_ppVirtualMethodTable = (void*)&::DAT_01030a24;
    ++DAT_01268250;
    m_ppVirtualMethodTable = (void*)&DAT_010ca3f4;
    ++DAT_01268660;
    return this;
}
}  // namespace fnv_00cca950

extern "C" void __cdecl FUN_00d54e60();
extern int DAT_010ca4dc;

struct FUN_00ccb180_class {
    int* m_p;
    FUN_00ccb180_class* FUN_00ccb180(int flag);
};

// Resets m_p to DAT_010ca4dc, decrements DAT_0126866c, calls FUN_00d54e60, and deletes this when flag bit 0 is set.
// @fnv 0x00ccb180
FUN_00ccb180_class* FUN_00ccb180_class::FUN_00ccb180(int flag)
{
    m_p = &DAT_010ca4dc;
    --DAT_0126866c;
    FUN_00d54e60();
    if (flag & 1)
        ::FUN_00aa1460(this, 20);
    return this;
}

namespace fnv_00ccd100 {
extern int DAT_010ca834;
extern int DAT_0126868c;
struct bhkRefObject {
    void* m_pVtable;
    int m_iRefCount;
    int m_iUnk;
    int m_iUnk2;
    int m_iUnk3;
    bhkRefObject* FUN_00ccd100();
};
// Calls Initialize, zeroes m_iUnk2 and m_iUnk3, assigns four successive vtables and increments four counters, then returns this.
// @fnv 0x00ccd100
bhkRefObject* bhkRefObject::FUN_00ccd100()
{
    reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
    m_iUnk2 = 0;
    m_iUnk3 = 0;
    m_pVtable = &::DAT_01030bf4;
    ++DAT_012680f8;
    m_pVtable = &::DAT_01030b0c;
    ++DAT_01268274;
    m_pVtable = &::DAT_01030a24;
    ++DAT_01268250;
    m_pVtable = &DAT_010ca834;
    ++DAT_0126868c;
    return this;
}
}  // namespace fnv_00ccd100

namespace fnv_00cce990 {
struct bhkRefObject {
    void* m_ppVirtualMethodTable;
    int m_iRefCount;
    int m_iFlags;
    int m_iUnk;
    int m_iUnk2;
};
extern int DAT_012686ac;
extern int DAT_010caa0c;
struct FUN_00cce990_shell : bhkRefObject {
    bhkRefObject* FUN_00cce990();
};
// @fnv 0x00cce990
bhkRefObject* FUN_00cce990_shell::FUN_00cce990()
{
    reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
    m_iUnk = 0;
    m_iUnk2 = 0;
    m_ppVirtualMethodTable = (void*)&::DAT_01030bf4;
    DAT_012680f8 += 1;
    m_ppVirtualMethodTable = (void*)&::DAT_01030b0c;
    DAT_01268274 += 1;
    m_ppVirtualMethodTable = (void*)&::DAT_01030a24;
    DAT_01268250 += 1;
    m_ppVirtualMethodTable = (void*)&DAT_010caa0c;
    DAT_012686ac += 1;
    return this;
}
}  // namespace fnv_00cce990

namespace fnv_00ccf7c0 {
extern int DAT_012686c0;
extern int DAT_010cabdc;
struct bhkRefObject {
    void* m_pVtable;
    int m_iRefCount;
    int m_iUnk;
    int m_iUnk2;
    int m_iUnk3;
};
struct FUN_00ccf7c0_class : bhkRefObject {
    FUN_00ccf7c0_class* FUN_00ccf7c0();
};
// Calls Initialize, zeroes m_iUnk2 and m_iUnk3, sets m_pVtable through four vtable assignments and increments four counters, then returns this.
// @fnv 0x00ccf7c0
FUN_00ccf7c0_class* FUN_00ccf7c0_class::FUN_00ccf7c0()
{
    reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
    m_iUnk2 = 0;
    m_iUnk3 = 0;
    m_pVtable = (void*)&::DAT_01030bf4;
    ++DAT_012680f8;
    m_pVtable = (void*)&::DAT_01030b0c;
    ++DAT_01268274;
    m_pVtable = (void*)&::DAT_01030a24;
    ++DAT_01268250;
    m_pVtable = (void*)&DAT_010cabdc;
    ++DAT_012686c0;
    return this;
}
}  // namespace fnv_00ccf7c0

void __cdecl ReleaseAllNodes();
struct H_00c8c810 {  };
struct FUN_00ccfe20_class {
    void FUN_00ccfe20(bool a);
};
// @fnv 0x00cde9f0
void FUN_00cde9f0(void* self, int, float v)
{
    *(float*)((char*)self + 0xf8) = v;
}

// @fnv 0x00cdea70
void hkMalleableConstraintData::FUN_00cdea70(hkMalleableContactNormal* normal)
{
    SetContactNormal(0, normal);
}

// @fnv 0x00cdea90
void hkMalleableConstraintData::FUN_00cdea90(hkMalleableContactNormal* normal)
{
    SetContactNormal(2, normal);
}

struct FUN_00cdf290_cls {
    void SetFlagAndClearFloats(intptr_t a, char b);
};

// Stores b at offset 0xa2 and its inverse at 0xf2, then zeroes twelve floats at the object reached via a+0x30 when present.
// @fnv 0x00cdf290
void FUN_00cdf290_cls::SetFlagAndClearFloats(intptr_t a, char b)
{
    ((char*)this)[0xa2] = b;
    ((char*)this)[0xf2] = !b;
    if (a && *(int*)(a + 0x30) && *(int*)(*(int*)(a + 0x30) + 0x1c)) {
        float* p = (float*)(*(int*)(*(int*)(a + 0x30) + 0x1c) + 0x18);
        *p = 0.0f;
        *(p + 1) = 0.0f;
        *(p + 2) = 0.0f;
        *(p + 3) = 0.0f;
        *(p + 4) = 0.0f;
        *(p + 5) = 0.0f;
        *(p - 6) = 0.0f;
        *(p - 5) = 0.0f;
        *(p - 4) = 0.0f;
        *(p - 3) = 0.0f;
        *(p - 2) = 0.0f;
        *(p - 1) = 0.0f;
    }
}

struct bhkLimitedHingeVector {
};
struct MyObj { void* m_kPointA; void* m_kPointB; void* m_iThirdValue; };
struct OutS {
    bhkLimitedHingeVector m_kPointA;
    bhkLimitedHingeVector m_kPointB;
    bhkLimitedHingeVector m_iThirdValue;
};
// @fnv 0x00ccaa30
void CopyHingeVectors(MyObj* self, int edx, OutS* out) {
    FUN_00c9fb70(self, edx, out);
    if (self && self->m_iThirdValue && (const char*)self->m_iThirdValue + 0x20) {
        const char* p = (const char*)self->m_iThirdValue + 0x20;
        reinterpret_cast<::S004b4db0_Quaternion *>((((bhkLimitedHingeVector*)((char*)out + 0x10))))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((const float*)p)));
        reinterpret_cast<::S004b4db0_Quaternion *>((((bhkLimitedHingeVector*)((char*)out + 0x20))))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((const float*)(p + 0x10))));
        reinterpret_cast<::S004b4db0_Quaternion *>((((bhkLimitedHingeVector*)((char*)out + 0x30))))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((const float*)(p + 0x20))));
    }
}

namespace fnv_00ccb1b0 {
struct bhkLimitedHingeVector {
};
struct MyObj {
};
struct FUN_00ccb1b0_class {
    void FUN_00ccb1b0(void* apStream);
};
// @fnv 0x00ccb1b0
void FUN_00ccb1b0_class::FUN_00ccb1b0(void* apStream)
{
    reinterpret_cast<::This *>((((MyObj*)this)))->FUN_00c84e20((unsigned int *)(apStream));
    if (this && *(void**)((char*)this + 8)) {
        void* p = *(void**)((char*)this + 8);
        reinterpret_cast<::S004b4db0_Quaternion *>((((bhkLimitedHingeVector*)((char*)apStream + 0x30))))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((const float*)((char*)p + 0x20))));
        reinterpret_cast<::S004b4db0_Quaternion *>((((bhkLimitedHingeVector*)((char*)apStream + 0x20))))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((const float*)((char*)p + 0x30))));
        p = (char*)p + 0x10;
        reinterpret_cast<::S004b4db0_Quaternion *>((((bhkLimitedHingeVector*)((char*)apStream + 0x10))))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((const float*)p)));
    }
}
}  // namespace fnv_00ccb1b0

extern int _data_011c16bc;
struct FUN_00cce990 {
    void* m_p;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cce990();
};
struct BSFadeNode {
};
// Allocates and returns a new FUN_00cce990 object via its operator new.
// @fnv 0x00ccea70
FUN_00cce990* FUN_00ccea70()
{
    return new FUN_00cce990;
}

struct FUN_00ccf060_stub { void ReleaseActiveResource(); };
struct FUN_00ccf100_class : H_00c8c810 {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    void* m_pData;
    void FUN_00ccf100(bool flag);
};

// @fnv 0x00ccf100
void FUN_00ccf100_class::FUN_00ccf100(bool abAddRef)
{
    if (abAddRef) {
        if (this && m_pData) {
            void* p1 = *(void**)((char*)m_pData + 0x18);
            if (p1) {
                void* p2 = *(void**)((char*)p1 + 8);
                if (p2) {
                    InterlockedIncrement((long*)((char*)p2 + 4));
                    reinterpret_cast<::bhkBoxShape *>(this)->FUN_00c84e50(abAddRef);
                    return;
                }
            }
        }
    } else {
        ((FUN_00ccf060_stub*)this)->ReleaseActiveResource();
    }
    reinterpret_cast<::bhkBoxShape *>(this)->FUN_00c84e50(abAddRef);
}

extern int DAT_010c5ef4;
extern int DAT_010c955c;
extern int DAT_01268154;
extern int DAT_01268194;

struct A51BF0Base {
};

struct S_00cb79d0_Base {
    void* m_pVtable;
    unsigned int m_uiField1;
    unsigned int m_uiField2;
    S_00cb79d0_Base();
};

struct DerivedStandin : A51BF0Base, S_00cb79d0_Base {
    unsigned int m_uiField3;

    DerivedStandin()
        : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c955c);
        DAT_012685ac += count;
    }
};

// Allocates and constructs a DerivedStandin object, returning its pointer.
// @fnv 0x00cc2bc0
void* CreateDerivedStandin()
{
    return new DerivedStandin;
}

struct FUN_00cc4180_Class {
    void FUN_00cc4180();
    void* FUN_00cc4200(int flag);
};
struct FUN_00cc47f0_t {
    void FUN_00cc47f0();
    FUN_00cc47f0_t* FUN_00cc48e0(int a);
};
extern int DAT_010c99e0;
struct FUN_00cc4990 {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cc4990();
};
// @fnv 0x00cc4990
FUN_00cc4990::FUN_00cc4990()
{
    m_uiRefCount = 0;
    m_uiValue1 = 1;
    m_uiData1 = 0;
    m_uiData2 = 0;
    m_pVtable = &DAT_010c99e0;
}

namespace fnv_00cc5130 {
extern int DAT_01268188;
extern int DAT_012685e8;

struct A51BF0Base {
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

struct Derived5130 : S_00cb79d0_Base {
    int* m_p;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;

    Derived5130()
    {
        m_p = &::DAT_0108febc;
        m_cByteAtOffset3 = 0;
        ++DAT_01268188;
        m_p = &DAT_010c9a14;
        ++DAT_012685e8;
    }
};

// Allocates and constructs a Derived5130 object, returning the new instance.
// @fnv 0x00cc5130
void* CreateDerived5130()
{
    return new Derived5130;
}
}  // namespace fnv_00cc5130

extern int DAT_010c9af0;

struct FUN_00cc51c0 {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cc51c0();
};

// @fnv 0x00cc51c0
FUN_00cc51c0::FUN_00cc51c0()
{
    m_uiRefCount = 0;
    m_uiValue1 = 1;
    m_uiData1 = 0;
    m_uiData2 = 0;
    m_pVtable = &DAT_010c9af0;
}

struct FUN_00cc5f10_Class {
    void FUN_00cc5e60();
    FUN_00cc5f10_Class* FUN_00cc5f10(unsigned int flag);
};

namespace fnv_00cc60b0 {
extern int DAT_01268188;
extern int DAT_01268600;

struct A51BF0Base {
    void* m_pVtable;
    unsigned char m_ucUnknownByte[8];

};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

struct FUN_cc60b0_object : S_00cb79d0_Base {
    unsigned int m_uiCurrentValue;

    FUN_cc60b0_object();
};

FUN_cc60b0_object::FUN_cc60b0_object()
    : S_00cb79d0_Base()
{
    m_pVtable = &::DAT_0108febc;
    m_uiCurrentValue = 0;
    ++DAT_01268188;
    m_pVtable = &DAT_010c9b0c;
    ++DAT_01268600;
}

// Allocates and constructs a new FUN_cc60b0_object, returning its pointer.
// @fnv 0x00cc60b0
void* __cdecl FUN_00cc60b0()
{
    return new FUN_cc60b0_object;
}
}  // namespace fnv_00cc60b0

struct NiPoint3 {
    float x;
    float y;
    float z;

    char* FUN_00a59af0(char const* name);
};

struct NiPoint3_local : NiPoint3 {};

struct hkVector4 {
    float x;
    float y;
    float z;
    float w;
};


struct StrArr
{
    void* m_pVtable;
    void* m_pData;
    unsigned short m_usSize;
    unsigned short m_usElementCount;
    unsigned char m_pad000C;
    unsigned short m_usIncrement;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};



struct FUN_00cc7090_Constraint {
    unsigned char m_pad0000[0x20];
    hkVector4 m_twistAxisA;
    hkVector4 m_planeAxisA;
    unsigned char m_pad0040[0x10];
    hkVector4 m_kPivotInA;
    hkVector4 m_twistAxisB;
    hkVector4 m_planeAxisB;
    unsigned char m_pad0080[0x10];
    hkVector4 m_kPivotInB;
    unsigned char m_pad00A0[0x58];
    float m_fMaxFrictionTrq;
    unsigned char m_pad00FC[0x08];
    float m_fTwistMinAngle;
    float m_fTwistMaxAngle;
    unsigned char m_pad010C[0x10];
    float m_fConeMinAngle;
    unsigned char m_pad0120[0x0C];
    float m_fPlaneMinAngle;
    float m_fPlaneMaxAngle;
};

struct FUN_00cc7090_class {
    void* m_pVtable;
    FUN_00cc7090_Constraint* m_pConstraint;

    void AppendConstraintParams(StrArr* strArr);
};

namespace fnv_00cc7500 {
struct A51BF0Base {
};

extern int DAT_010c9c84;
extern int DAT_01268188;
extern int DAT_01268618;

struct S_00cb79d0_Base : A51BF0Base {
    void* m_pVtable;
    unsigned int m_uiField1;
    unsigned int m_uiField2;
    unsigned int m_uiField3;

    S_00cb79d0_Base();
};

struct Object_00cc7500 : S_00cb79d0_Base {
    Object_00cc7500()
    {
        m_pVtable = reinterpret_cast<void*>(&::DAT_0108febc);
        m_uiField3 = 0;
        ++DAT_01268188;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c9c84);
        ++DAT_01268618;
    }
};

// Allocates and constructs a new Object_00cc7500, returning the new instance.
// @fnv 0x00cc7500
Object_00cc7500* FUN_00cc7500()
{
    return new Object_00cc7500;
}
}  // namespace fnv_00cc7500

extern int DAT_010c9d60;
struct FUN_00cc7590 {
    void* m_pVtable;
    int m_iRefCount;
    int m_iData1;
    int m_iData2;
    int m_iData3;
    FUN_00cc7590();
};
// @fnv 0x00cc7590
FUN_00cc7590::FUN_00cc7590()
{
    m_iRefCount = 0;
    m_iData1 = 1;
    m_iData2 = 0;
    m_iData3 = 0;
    m_pVtable = (void*)&DAT_010c9d60;
}

extern "C" void __cdecl FUN_00d50020();
struct FUN_00cc7da0_shell {
    FUN_00cc7da0_shell* FUN_00cc7da0(int flags);
};
// Calls FUN_00d50020, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00cc7da0
FUN_00cc7da0_shell* FUN_00cc7da0_shell::FUN_00cc7da0(int flags)
{
    FUN_00d50020();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}

extern int DAT_010c9f38;
struct FUN_00cc7f10 {
    int* m_pVTable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cc7f10();
};
// @fnv 0x00cc7f10
FUN_00cc7f10::FUN_00cc7f10()
{
    m_uiRefCount = 0;
    m_uiValue1 = 1;
    m_uiData1 = 0;
    m_uiData2 = 0;
    m_pVTable = &DAT_010c9f38;
}

namespace fnv_00cc8520 {
extern int DAT_010c9f74;
extern int DAT_01268188;
extern int DAT_01268630;

struct A51BF0Base {
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

struct Object_00cc8520 : S_00cb79d0_Base {
    int* m_pVtable;
    void* m_pA;
    void* m_pB;
    int m_iValue;

    Object_00cc8520()
        : m_pVtable(&::DAT_0108febc),
          m_iValue(0)
    {
        ++DAT_01268188;
        m_pVtable = &DAT_010c9f74;
        ++DAT_01268630;
    }
};

// Allocates and constructs a new Object_00cc8520 instance, returning its pointer.
// @fnv 0x00cc8520
void* FUN_00cc8520()
{
    return new Object_00cc8520;
}
}  // namespace fnv_00cc8520

struct FUN_00cc94b0_Class {
    void FreeSpawnedStorage();
};
struct FUN_00cc9540_Class : FUN_00cc94b0_Class {
    FUN_00cc9540_Class* FUN_00cc9540(char flag);
};

// @fnv 0x00cc9540
FUN_00cc9540_Class* FUN_00cc9540_Class::FUN_00cc9540(char flag)
{
    FUN_00cc94b0_Class::FreeSpawnedStorage();
    if (flag & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

namespace fnv_00cc9e60 {
struct A51BF0Base {
};

struct S_00cb79d0_Base {
    void* m_pVtable;
    unsigned int m_kPointA;
    unsigned int m_kPointB;

    S_00cb79d0_Base();
};

extern int DAT_010ca24c;
extern int _DAT_012682cc;
extern int DAT_01268654;

struct bhkBvTreeShape : S_00cb79d0_Base {
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;


    bhkBvTreeShape()
    {
        m_iThirdValue = 0;
        m_iFourthElementInteger = 0;

        m_pVtable = reinterpret_cast<void*>(&::DAT_01030bf4);
        ++DAT_012680f8;

        m_pVtable = reinterpret_cast<void*>(&(*reinterpret_cast<int *>(&::DAT_0104dbac)));
        ++_DAT_012682cc;

        m_pVtable = reinterpret_cast<void*>(&DAT_010ca24c);
        ++DAT_01268654;
    }
};

// Allocates and constructs a new bhkBvTreeShape, returning the pointer.
// @fnv 0x00cc9e60
bhkBvTreeShape* CreateBhkBvTreeShape()
{
    return new bhkBvTreeShape;
}
}  // namespace fnv_00cc9e60

struct FUN_00cca8d0_shell {
};

struct FUN_00cca9a0_class : FUN_00cca8d0_shell {
    FUN_00cca8d0_shell* DestroyOrDelete(int flags);
};

// @fnv 0x00cca9a0
FUN_00cca8d0_shell* FUN_00cca9a0_class::DestroyOrDelete(int flags)
{
    reinterpret_cast<::FUN_00cca8d0 *>(this)->FUN_00cca8d0::~FUN_00cca8d0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}

struct FUN_00cca9c0_class {
    void FUN_00cca9c0(float scale);
};

// Multiplies the twelve floats starting at offset 0x10 of this object by scale.
// @fnv 0x00cca9c0
void FUN_00cca9c0_class::FUN_00cca9c0(float scale)
{
    float s = scale;
    float* p = (float*)((char*)this + 0x10);
    p[0] = p[0] * s;
    p[1] *= s;
    p[2] *= s;
    p[3] *= s;
    p[4] *= s;
    p[5] *= s;
    p[6] *= s;
    p[7] *= s;
    p[8] *= s;
    p[9] *= s;
    p[10] *= s;
    p[11] *= s;
}

// @fnv 0x00ccba20
bool FUN_00ccba20(char* p, int, char* q)
{
    return q == p;
}

namespace fnv_00ccbd70 {
struct A51BF0Base {
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

extern int DAT_012686d0;

struct BD70_Object : S_00cb79d0_Base {
    void* m_pVtable;
    int m_unused04;
    int m_unused08;
    int m_field0C;
    int m_field10;
    int m_field14;

    BD70_Object()
    {
        m_pVtable = &::DAT_01030bf4;
        m_field0C = 0;
        m_field10 = 0;
        ++DAT_012680f8;
        m_pVtable = &::DAT_010c44e4;
        ++DAT_012686d0;
        m_pVtable = &::DAT_010ca744;
        m_field14 = 0;
        ++DAT_01268678;
    }
};

// Allocates and constructs a BD70_Object, returning it as an S_00cb79d0_Base pointer.
// @fnv 0x00ccbd70
S_00cb79d0_Base* __cdecl CreateBD70Object()
{
    return new BD70_Object;
}
}  // namespace fnv_00ccbd70

struct FUN_00ccd170_cls {
    void FUN_00ccd170(float scale);
};

// Multiplies the nine floats starting at offset 0x10 of this object by scale.
// @fnv 0x00ccd170
void FUN_00ccd170_cls::FUN_00ccd170(float scale)
{
    float s = scale;
    float* p = (float*)((char*)this + 0x10);
    p[0] *= s;
    p[1] *= s;
    p[2] *= s;
    p[3] *= s;
    p[4] *= s;
    p[5] *= s;
    p[6] *= s;
    p[7] *= s;
    p[8] *= s;
}

struct NiStreamResolveLinkID
{
};

struct NiStreamVirtual
{
    virtual void* m_pVtable00();
    virtual void* m_pVtable04();
    virtual void* m_pVtable08();
    virtual void* m_pVtable0C();
    virtual void* m_pVtable10();
    virtual void* m_pVtable14();
    virtual void* m_pVtable18();
    virtual void* m_pVtable1C();
    virtual void* m_pVtable20();
    virtual void* m_pVtable24();
    virtual void m_pVtable28(void*);
};

struct FUN_00ccf570_class
{
    void FUN_00ccf570(NiStream* stream);
};

// @fnv 0x00ccf570
void FUN_00ccf570_class::FUN_00ccf570(NiStream* stream)
{
    void* resolved = ((void *)(reinterpret_cast<::NiStream *>((reinterpret_cast<NiStreamResolveLinkID*>(stream)))->DeserializeObject()));
    reinterpret_cast<::Cls_00c9fbc0 *>(this)->FUN_00c9fbc0((::Arg_00c9fbc0 *)(stream));
    reinterpret_cast<NiStreamVirtual*>(stream)->m_pVtable28(resolved);
}


struct FUN_00ccf5b0_shell {
    FUN_00ccf5b0_shell* FUN_00ccf5b0(bool flag);
};

// Calls FUN_00ccf4f0, then frees this with _delete when flag bit 0 is set, and returns this.
// @fnv 0x00ccf5b0
FUN_00ccf5b0_shell* FUN_00ccf5b0_shell::FUN_00ccf5b0(bool abFree)
{
    reinterpret_cast<::FUN_00ccf4f0_cls *>(this)->FUN_00ccf4f0_cls::~FUN_00ccf4f0_cls();
    if (abFree & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}

namespace fnv_00cd2fd0 {
struct StrArr {
    unsigned char m_auiShapeKeys[8];
    unsigned short m_pRayCursor;
    unsigned short m_iElementCount;
    unsigned short m_unknown;
    unsigned short m_growth;

    void SetSize(unsigned int size);
};

struct Object {
    void FUN_00cd2fd0(StrArr* arr);
};


extern char const* const g_012681a8_arg1;


struct TLSGuard {
    unsigned int m_oldValue;

    TLSGuard()
    {
        m_oldValue = *reinterpret_cast<unsigned int*>((*reinterpret_cast<unsigned char (*)[696]>(&::g_tlsBlock)) + 0x2b4);
        *reinterpret_cast<unsigned int*>((*reinterpret_cast<unsigned char (*)[696]>(&::g_tlsBlock)) + 0x2b4) = 0x10;
    }

    ~TLSGuard()
    {
        *reinterpret_cast<unsigned int*>((*reinterpret_cast<unsigned char (*)[696]>(&::g_tlsBlock)) + 0x2b4) = m_oldValue;
    }
};

// @fnv 0x00cd2fd0
void Object::FUN_00cd2fd0(StrArr* pStrArr)
{
    TLSGuard guard;

    reinterpret_cast<::ShapeViewerFields *>((this))->FUN_00c851c0((::BCA05B0StringArray *)(pStrArr));

    char* value = ::FUN_00a7d330(g_012681a8_arg1);
    unsigned int index = pStrArr->m_iElementCount;

    if (index >= pStrArr->m_pRayCursor)
        pStrArr->SetSize(index + pStrArr->m_growth);

    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pStrArr))->SetAt(index, value);
}
}  // namespace fnv_00cd2fd0

extern int DAT_010cb3c4;
struct FUN_00cd44c0_cls {
    int m_vft;
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    FUN_00cd44c0_cls* FUN_00cd44c0();
};
// @fnv 0x00cd44c0
FUN_00cd44c0_cls* FUN_00cd44c0_cls::FUN_00cd44c0()
{
    m_kPointB = 1;
    m_vft = (int)&DAT_010cb3c4;
    return this;
}

extern int DAT_010cb3f0;
struct FUN_00cd47e0_t {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned char m_bFlag;
    unsigned short m_usFlags;
    FUN_00cd47e0_t();
};
// @fnv 0x00cd47e0
FUN_00cd47e0_t::FUN_00cd47e0_t()
{
    *(unsigned short*)((char*)this + 6) = 1;
    m_pVtable = (void*)&DAT_010cb3f0;
    m_bFlag = 1;
}

struct Matrix {
    unsigned char m_ucUnknownByte[0x30];
    bool* HasFiniteValues(bool* value);
};

struct FUN_00cda090_counter {
    unsigned char m_ucUnknownByte[0x1C];
    int m_uiItemCount;
};

struct FUN_00cda090_class {
    FUN_00cda090_counter* m_pCounter;
    Matrix* m_pMatrix1;
    void* m_pUnknown08;
    void* m_pUnknown0C;
    Matrix* m_pMatrix2;
    void* m_pUnknown14;
    void* m_pUnknown18;
    unsigned int* m_pFlags;

    bool* FUN_00cda090(bool* result);
};

// Loops over m_pFlags entries, returning false if a flag has both bits set or an unflagged matrix fails its check; otherwise true.
// @fnv 0x00cda090
bool* FUN_00cda090_class::FUN_00cda090(bool* result)
{
    bool value1;
    bool value2;
    int count = m_pCounter->m_uiItemCount;

    for (int i = 0; i < count; ++i) {
        if ((m_pFlags[i] & 2) && (m_pFlags[i] & 1)) {
            *result = false;
            return result;
        }

        if (!(m_pFlags[i] & 2)) {
            Matrix* matrix = m_pMatrix2 + i;
            if (!*matrix->HasFiniteValues(&value1)) {
                *result = false;
                return result;
            }
        }

        if (!(m_pFlags[i] & 1)) {
            Matrix* matrix = m_pMatrix1 + i;
            if (!*matrix->HasFiniteValues(&value2)) {
                *result = false;
                return result;
            }
        }
    }

    *result = true;
    return result;
}

// @fnv 0x00cdeab0
void hkMalleableConstraintData::FUN_00cdeab0(hkMalleableContactNormal* normal)
{
    SetContactNormal(1, normal);
}

struct hkMatrix3 {
};
// @fnv 0x00cdf270
void FUN_00cdf270(char* self, int, char* apMatrix)
{
    reinterpret_cast<::hkMatrix3CD4B *>((((hkMatrix3*)apMatrix)))->FUN_00cd4bf0((*(const ::hkMatrix3CD4B *)(self + 0x60)), (*(const ::hkMatrix3CD4B *)(self + 0xb0)));
}

class CC1AD0BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(CC1AD0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl *m_pfnWrite)(CC1AD0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count) {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class CC1AD0Object;

class CC1AD0Stream {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(CC1AD0Object* pkObject);

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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    CC1AD0BinaryStream* m_pBackingStream;
};

template <class T>
inline void CC1AD0BinaryStreamSave(CC1AD0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1) {
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CC1AD0SaveBinary(CC1AD0Stream& kStream, const T& value) {
    CC1AD0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class CC1AD0ExtraData {
public:

    int unk00; int unk04; int unk08; int unk0C;
};

class CC1AD0ListExtra : public CC1AD0ExtraData {
public:
    CC1AD0Object** m_ppkObjects;
    int unk14;
    int unk18;
    unsigned int m_uiCount;

    void FUN_00cc1ad0(CC1AD0Stream& kStream);
};

// SaveBinary
// Saves the base extra data, writes m_uiCount, then saves a link ID for each non-null object in m_ppkObjects.
// @fnv 0x00cc1ad0
void CC1AD0ListExtra::FUN_00cc1ad0(CC1AD0Stream& kStream) {
    reinterpret_cast<::FUN_00a7b2c0_shell *>(this)->FUN_00a7b2c0((::NiStream &)(kStream));
    unsigned int ItemUpdateArray = m_uiCount;
    CC1AD0SaveBinary(kStream, ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++) {
        CC1AD0Object* pkObject = m_ppkObjects[i];
        if (pkObject)
            kStream.SaveLinkID(pkObject);
    }
}

struct ArrayRefObject {
    virtual void vf0();
    virtual void DeleteThis();
    long volatile refs;
    void DecRef() { if (InterlockedDecrement(&refs) == 0) DeleteThis(); }
    void AcquireReference() { InterlockedIncrement(&refs); }
};
struct RefBool { bool value; RefBool(bool v): value(v) {} operator bool() const { return value; } };
struct ArrayRefPtr {
    ArrayRefObject* ptr;
    ArrayRefPtr() : ptr(0) {}
    ~ArrayRefPtr() { if (ptr) ptr->DecRef(); }
    RefBool operator!=(ArrayRefObject* other) const { return ptr != other; }
    ArrayRefPtr& operator=(const ArrayRefPtr& rhs) {
        if (ptr != rhs.ptr) {
            if (ptr) ptr->DecRef();
            ptr = rhs.ptr;
            if (ptr) ptr->AcquireReference();
        }
        return *this;
    }
};
void* __cdecl FUN_00aa1070(unsigned);
void __cdecl FUN_00aa10f0(void*);
struct ReferenceArray {
    void* vtable;
    ArrayRefPtr* data;
    unsigned capacity, used, live;
    void Resize(unsigned);
};
// Resizes the reference array to n slots: releases entries past n, reallocates storage, copies live entries and default-initialises the rest.
// @fnv 0x00cc1b40
void ReferenceArray::Resize(unsigned uiCapacity) {
    if (uiCapacity != capacity) {
        if (uiCapacity < used) {
            for (unsigned i = uiCapacity; i < used; ++i) {
                if (data[i] != (ArrayRefObject*)0) { data[i] = ArrayRefPtr(); --live; }
            }
            used = uiCapacity;
        }
        ArrayRefPtr* old = data;
        capacity = uiCapacity;
        if (uiCapacity > 0) {
            data = (ArrayRefPtr*)FUN_00aa1070(uiCapacity * sizeof(ArrayRefPtr));
            for (unsigned i = 0; i < used; ++i) data[i] = old[i];
            for (unsigned i = used; i < capacity; ++i) data[i] = ArrayRefPtr();
        } else data = 0;
        FUN_00aa10f0(old);
    }
}

extern int DAT_01268598;

// @fnv 0x00cc1e30
int __cdecl FUN_00cc1e30() {
    return reinterpret_cast<int>(&DAT_01268598);
}

struct FUN_00cc1e40_tls {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};

struct TlsFlagGuard_00cc1e40 {
    unsigned int m_saved;
    TlsFlagGuard_00cc1e40() {
        m_saved = (*reinterpret_cast<::FUN_00cc1e40_tls *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::FUN_00cc1e40_tls *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsFlagGuard_00cc1e40() {
        (*reinterpret_cast<::FUN_00cc1e40_tls *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

void __cdecl FUN_00aa10f0(void* apMemory);

struct Base_00cc1e40 {
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    ~Base_00cc1e40();
};

struct Member_00cc1e40 {
    virtual void unk00();
    void* m_04;
    void Destroy();
    ~Member_00cc1e40() {
        void* p = m_04;
        FUN_00aa10f0(p);
    }
};

class FUN_00cc1e40_cls : public Base_00cc1e40 {
public:
    Member_00cc1e40 m_0c;
    virtual ~FUN_00cc1e40_cls();
};

// @fnv 0x00cc1e40
FUN_00cc1e40_cls::~FUN_00cc1e40_cls() {
    {
        TlsFlagGuard_00cc1e40 guard;
        m_0c.Destroy();
    }

}

struct FUN_00cc1d80_object {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    FUN_00cc1d80_object();
};
// @fnv 0x00cc1ef0
FUN_00cc1d80_object* __cdecl CreateObjectWithGlobal()
{
    FUN_00cc1d80_object* value = new FUN_00cc1d80_object;
    ::AssignFixedString((char *)(value), (intptr_t)(&(*reinterpret_cast<char *>(&::DAT_011f49e0))), {});
    return value;
}


struct BCC1F80AllocTagScope {
    int m_iSaved;

    BCC1F80AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCC1F80AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class BCC1F80StringArray {
public:
    virtual ~BCC1F80StringArray();
    void SetSize(unsigned int uiMaxSize);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement) { return SetAtGrow(m_usSize, pcElement); }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcCC1F80Name;


class CC1F80Node {
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void CollectNames(BCC1F80StringArray* pkArray);
};

class CC1F80Group {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC1F80Node** m_ppkChildren;
    int unk14;
    int unk18;
    unsigned int m_uiChildCount;

    void CollectAllNames(BCC1F80StringArray* pkArray);
};

// @fnv 0x00cc1f80
void CC1F80Group::CollectAllNames(BCC1F80StringArray* pkArray)
{
    BCC1F80AllocTagScope kScope(0x10);
    reinterpret_cast<::ExtraDataStrings *>(this)->FUN_00a7b580((::StrArr *)(pkArray));
    char* pcName = FUN_00a7d330(g_pcCC1F80Name);
    pkArray->Add(pcName);

    unsigned int ItemUpdateArray = m_uiChildCount;
    for (unsigned int i = 0; i < ItemUpdateArray; i++) {
        CC1F80Node* pkChild = m_ppkChildren[i];
        if (pkChild)
            pkChild->CollectNames(pkArray);
    }
}

struct ThreadModeGuard {
    unsigned int previous;
    ThreadModeGuard() : previous(::currentAllocationContext) { ::currentAllocationContext = 16; }
    ~ThreadModeGuard() { ::currentAllocationContext = previous; }
};
struct OutputBuffer {
    void* unk00; void* unk04; void* unk08;
    struct ListStorage {  } list;
};
struct SceneNode {
    virtual void unknown_slot_00();
    virtual void unknown_slot_04();
    virtual void unknown_slot_08();
    virtual void unknown_slot_0c();
    virtual void unknown_slot_10();
    virtual void unknown_slot_14();
    virtual void unknown_slot_18();
    virtual void unknown_slot_1c();
    virtual void unknown_slot_20();
    virtual void unknown_slot_24();
    virtual void unknown_slot_28();
    virtual void unknown_slot_2c();
    virtual void unknown_slot_30();
    virtual void unknown_slot_34();
    virtual void unknown_slot_38();
    virtual void unknown_slot_3c();
    virtual void unknown_slot_40();
    virtual void unknown_slot_44();
    virtual void* ReadValue(void* context);
};
struct SceneList {
    void* unk00; void* unk04; void* unk08; void* unk0c;
    SceneNode** entries;
    void* unk14; void* unk18;
    unsigned int count;
    void WriteSceneList(OutputBuffer* dest, void* context);
};


struct ThreadHeapState
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};


struct TlsHeapGuard
{
    unsigned int saved;
    TlsHeapGuard() { saved = (*reinterpret_cast<::ThreadHeapState *>(&::g_tlsBlock)).m_2b4; (*reinterpret_cast<::ThreadHeapState *>(&::g_tlsBlock)).m_2b4 = 0x10; }
    ~TlsHeapGuard() { (*reinterpret_cast<::ThreadHeapState *>(&::g_tlsBlock)).m_2b4 = saved; }
};

class SpawnedThing
{
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    SpawnedThing();
};

class FUN_00cc22a0_cls
{
public:
    void* CreateAndAttach(unsigned int arg);
};


// Allocates a SpawnedThing with a TLS heap guard active, attaches it using arg, and returns the new object.
// @fnv 0x00cc22a0
void* FUN_00cc22a0_cls::CreateAndAttach(unsigned int uiValue)
{
    TlsHeapGuard guard;
    SpawnedThing* obj = new SpawnedThing();
    reinterpret_cast<::SceneList *>(this)->WriteSceneList((::OutputBuffer *)(obj), (void *)(uiValue));
    return obj;
}



struct RefObject24_b9018 {
    char m00[0x18];
    RefObject24_b9018();
};

// Allocates and constructs a RefObject24_b9018 via its operator new and returns the pointer.
// @fnv 0x00cc2410
RefObject24_b9018* CreateRefObject24() {
    return new RefObject24_b9018();
}

struct TlsBlock_t
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int m_2b4;
};

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t(int saved)
    {
        m_saved = saved;
        (*reinterpret_cast<::TlsBlock_t *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        (*reinterpret_cast<::TlsBlock_t *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4 = m_saved;
    }
};


class SpawnedObject_t
{
public:
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    SpawnedObject_t();
};


struct FUN_00cc2480_cls
{
    int unk00;
    int unk04;
    SpawnedObject_t* FUN_00cc2480(unsigned int arg);
};

// @fnv 0x00cc2480
SpawnedObject_t* FUN_00cc2480_cls::FUN_00cc2480(unsigned int arg)
{
    TlsGuard_t guard((*reinterpret_cast<::TlsBlock_t *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4);
    SpawnedObject_t* result = 0;
    FUN_00c876f0();
    result = new SpawnedObject_t();
    reinterpret_cast<::WorldObjectView *>(this)->FUN_00c85900((int)(result), arg);
    FUN_00c87700();
    return result;
}

struct ThreadTlsBlock {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};

struct TlsFlagGuard {
    unsigned int m_saved;
    TlsFlagGuard() { m_saved = (*reinterpret_cast<::ThreadTlsBlock *>(&::g_tlsBlock)).m_2b4; (*reinterpret_cast<::ThreadTlsBlock *>(&::g_tlsBlock)).m_2b4 = 0x10; }
    ~TlsFlagGuard() { (*reinterpret_cast<::ThreadTlsBlock *>(&::g_tlsBlock)).m_2b4 = m_saved; }
};

class FUN_00cc2a00_alloc {
public:
};

class FUN_00cc2a00_obj {
public:
    void Init();
};

class FUN_00cc2a00_cls {
public:
    unsigned int m_00;
    unsigned int m_04;
    FUN_00cc2a00_obj* m_08;
    FUN_00cc2a00_obj* m_0c;

    FUN_00cc2a00_obj* FUN_00cc2a00(bool* out);
};

// Returns m_0c, allocating and initialising a new object first if it is null; sets *out to whether it was created.
// @fnv 0x00cc2a00
FUN_00cc2a00_obj* FUN_00cc2a00_cls::FUN_00cc2a00(bool* abCreated) {
    TlsFlagGuard guard;
    bool created = (m_0c == 0);
    *abCreated = created;
    if (created) {
        unsigned char* p = ((unsigned char *)(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::FUN_00cc2a00_alloc *>(&::g_memoryManager))))->FUN_00aa3e40(0x70)));
        unsigned char adj = (unsigned char)(0x10 - ((unsigned char)(unsigned int)p & 0xf));
        p += adj;
        p[-1] = adj;
        FUN_00cc2a00_obj* obj = (FUN_00cc2a00_obj*)p;
        new ((void *)(obj)) ::FUN_0056e0b0();
        m_0c = obj;
        if (m_08 != 0) {
            reinterpret_cast<::fnv_00c9ecb0::FUN_00c9ecb0_cls *>(this)->FUN_00c9ecb0((::fnv_00c9ecb0::HingeVectorSet *)(obj));
        }
    }
    return m_0c;
}

extern int DAT_012685b0;

// @fnv 0x00cc2b30
void* __cdecl FUN_00cc2b30()
{
    return &DAT_012685b0;
}

namespace fnv_00cc2c60 {


extern unsigned int g_ctorCount1;
extern unsigned int g_ctorCount2;
extern unsigned int g_ctorCount3;

class NodeRoot_cls {
public:
    NodeRoot_cls();
    virtual void r00();
};

class NodeA_cls : public NodeRoot_cls {
public:
    int unk04;
    int unk08;
    volatile int m_0c;
    NodeA_cls() : NodeRoot_cls() {
        m_0c = 0;
        g_ctorCount1 += 1;
    }
    virtual void a00();
};

class NodeB_cls : public NodeA_cls {
public:
    NodeB_cls() : NodeA_cls() {
        g_ctorCount2++;
    }
    virtual void b00();
};

class NodeC_cls : public NodeB_cls {
public:
    NodeC_cls() : NodeB_cls() {
        g_ctorCount3++;
    }
    virtual void c00();
};

class FUN_00cc2c60_cls {
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
    virtual void v50();
    virtual void v51();
    virtual void v52(NodeC_cls* node, int a1);
    NodeC_cls* FUN_00cc2c60(int a1);
};

// Allocates a NodeC_cls, passes it with a1 to v52, and returns the new node.
// @fnv 0x00cc2c60
NodeC_cls* FUN_00cc2c60_cls::FUN_00cc2c60(int aiValue) {
    ::FUN_00c876f0();
    NodeC_cls* p = new NodeC_cls();
    this->v52(p, aiValue);
    ::FUN_00c87700();
    return p;
}
}  // namespace fnv_00cc2c60

struct Col4 { float r, g, b, a; Col4& operator*=(float s) { r *= s; g *= s; b *= s; a *= s; return *this; } };
struct S_00cc2d20_result {
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    Col4 m_kPointA;
    Col4 m_kPointB;
};

struct S_00cc2d20_argument {
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    float m_f10;
};

struct S_00cc2d20_class {
    virtual void* v00(char*) { return 0; }
    virtual void* v01(char*) { return 0; }
    virtual void* v02(char*) { return 0; }
    virtual void* v03(char*) { return 0; }
    virtual void* v04(char*) { return 0; }
    virtual void* v05(char*) { return 0; }
    virtual void* v06(char*) { return 0; }
    virtual void* v07(char*) { return 0; }
    virtual void* v08(char*) { return 0; }
    virtual void* v09(char*) { return 0; }
    virtual void* v10(char*) { return 0; }
    virtual void* v11(char*) { return 0; }
    virtual void* v12(char*) { return 0; }
    virtual void* v13(char*) { return 0; }
    virtual void* v14(char*) { return 0; }
    virtual void* v15(char*) { return 0; }
    virtual void* v16(char*) { return 0; }
    virtual void* v17(char*) { return 0; }
    virtual void* v18(char*) { return 0; }
    virtual void* v19(char*) { return 0; }
    virtual void* v20(char*) { return 0; }
    virtual void* v21(char*) { return 0; }
    virtual void* v22(char*) { return 0; }
    virtual void* v23(char*) { return 0; }
    virtual void* v24(char*) { return 0; }
    virtual void* v25(char*) { return 0; }
    virtual void* v26(char*) { return 0; }
    virtual void* v27(char*) { return 0; }
    virtual void* v28(char*) { return 0; }
    virtual void* v29(char*) { return 0; }
    virtual void* v30(char*) { return 0; }
    virtual void* v31(char*) { return 0; }
    virtual void* v32(char*) { return 0; }
    virtual void* v33(char*) { return 0; }
    virtual void* v34(char*) { return 0; }
    virtual void* v35(char*) { return 0; }
    virtual void* v36(char*) { return 0; }
    virtual void* v37(char*) { return 0; }
    virtual void* v38(char*) { return 0; }
    virtual void* v39(char*) { return 0; }
    virtual void* v40(char*) { return 0; }
    virtual void* v41(char*) { return 0; }
    virtual void* v42(char*) { return 0; }
    virtual void* v43(char*) { return 0; }
    virtual void* v44(char*) { return 0; }
    virtual S_00cc2d20_result* v45(char*) { return 0; }

    void FUN_00cc2d20(
        void* arg1,
        S_00cc2d20_argument* arg2);
};

// Gets a result via v45, scales its two Col4 members by arg2->m_f10 when not 1.0, then calls ClonePhysicsData.
// @fnv 0x00cc2d20
void S_00cc2d20_class::FUN_00cc2d20(
    void* arg1,
    S_00cc2d20_argument* apArgument)
{
    char local;
    S_00cc2d20_result* result = v45(&local);
    float scale = apArgument->m_f10;

    if (scale != 1.0f) {
        result->m_kPointA *= scale;
        result->m_kPointB *= scale;
    }

    reinterpret_cast<::Owner253 *>(this)->ClonePhysicsData(arg1, apArgument);
}


struct FUN_00cc2f40_cls {
    volatile unsigned int m_00;
    volatile unsigned int m_04;
    volatile unsigned int m_08;
    unsigned int unk0C;
    volatile float m_10;
    volatile float m_14;
    volatile float m_18;
    volatile float m_1c;
    volatile float m_20;
    volatile float m_24;
    volatile float m_28;
    volatile float m_2c;
    float m_30;
    float m_34;
    float m_38;
    unsigned char m_3c;
    unsigned char m_3d;
    FUN_00cc2f40_cls();
};

// @fnv 0x00cc2f40
FUN_00cc2f40_cls::FUN_00cc2f40_cls() {
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_10 = 0.0f;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_1c = 0.0f;
    m_20 = 0.0f;
    m_24 = 0.0f;
    m_28 = 0.0f;
    m_2c = 0.0f;
    m_30 = 1.0f;
    m_34 = DAT_01013974;
    m_38 = DAT_0101e2bc;
    m_3c = 1;
    m_3d = 1;
}

typedef unsigned int CC2F90size_t;

struct CC2F90MemoryManager {
    void* Allocate(unsigned int uiSize);
};


struct CC2F90AllocTagScope {
    int m_iSaved;

    CC2F90AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CC2F90AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

inline void* CC2F90AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::CC2F90MemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(unsigned int)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}

struct CC2F90Child {
    CC2F90Child();

};

struct CC2F90Owner {
    int unk00;
    int unk04;
    void* m_pParentNode;
    CC2F90Child* m_pkChild;

    CC2F90Child* FUN_00cc2f90(bool* pbCreated);
};

extern int DAT_012685b8;

struct FUN_00cc3270_base {
    virtual ~FUN_00cc3270_base();
};

struct FUN_00cc3270 : FUN_00cc3270_base {
    virtual ~FUN_00cc3270();
};

// @fnv 0x00cc3270
FUN_00cc3270::~FUN_00cc3270()
{
    reinterpret_cast<::ProjectileListener *>((((bhkConstraint*)this)))->FUN_00c876a0();
    --DAT_012685b8;
}

extern int DAT_012685bc;

// @fnv 0x00cc32e0
void* __cdecl FUN_00cc32e0()
{
    return &DAT_012685bc;
}

// @fnv 0x00cc32f0
int __cdecl FUN_00cc32f0() {
    return 0x30;
}

void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct S_00cc3300 {
    int unk00, unk04, unk08, unk0c;
    void FUN_00cc3270();
    S_00cc3300* FUN_00cc3300(unsigned int flags);
};
// @fnv 0x00cc3300
S_00cc3300* S_00cc3300::FUN_00cc3300(unsigned int flags)
{
    reinterpret_cast<::FUN_00cc3270 *>(this)->FUN_00cc3270::~FUN_00cc3270();
    if (flags & 1)
        FUN_00aa1460(this, 0x10);
    return this;
}


struct CC3320Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_afPivot[4];
    float m_fMinimum;
    float m_fMaximum;
};

struct CC3320Vector {
};

struct CC3320Info {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC3320Vector m_kPivot;
    int unk14;
    int unk18;
    int unk1C;
    float m_fMinimum;
    float m_fMaximum;
    bool m_bStreamFlag;
};

class CC3320Base {
public:
};

class CC3320Constraint : public CC3320Base {
public:
    int unk00;
    int unk04;
    CC3320Data* m_pUserData;

    static const float* GetPivot(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_afPivot : &DAT_01267e30;
    }
    static float GetMax(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMaximum : 0.0f;
    }
    static float GetMin(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMinimum : 0.0f;
    }

    void FUN_00cc3320(CC3320Info* pkInfo);
};

// @fnv 0x00cc3320
void CC3320Constraint::FUN_00cc3320(CC3320Info* pkInfo)
{
    reinterpret_cast<::FUN_00c867d0_cls *>(this)->FUN_00c867d0((::FUN_00c867d0_out *)(pkInfo));
    pkInfo->m_bStreamFlag = true;
    reinterpret_cast<::S004b4db0_Quaternion *>(&(pkInfo->m_kPivot))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(GetPivot(this))));
    pkInfo->m_fMaximum = GetMax(this);
    pkInfo->m_fMinimum = GetMin(this);
}

namespace fnv_00cc33a0 {

extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_012685b8;

struct PhysicsElement {
    void* vtable;
    unsigned int referenceCount;
    unsigned int flags;
    unsigned int payload;

    void FUN_00c87c30();


    PhysicsElement() {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        vtable = &::DAT_0102016c;
        payload = 0;
        ++DAT_01268154;
        vtable = &::DAT_0102009c;
        ++DAT_01268118;
        vtable = &::DAT_010c9634;
        ++DAT_012685b8;
    }
};

// Allocates and constructs a new PhysicsElement, returning the pointer.
// @fnv 0x00cc33a0
PhysicsElement* __cdecl CreatePhysicsElement() {
    return new PhysicsElement();
}
}  // namespace fnv_00cc33a0

struct FUN_00cc3440_obj
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
    unsigned char unk1E4;
    unsigned char m_1e5;
};

struct FUN_00cc3440_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual unsigned int* vGet(FUN_00cc3440_obj** pp);
    void SwapEndianFields(FUN_00cc3440_obj* a1);
};

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

// @fnv 0x00cc3440
void FUN_00cc3440_cls::SwapEndianFields(FUN_00cc3440_obj* volatile apObj)
{
    FUN_00cc3440_obj* obj;
    reinterpret_cast<::fnv_00c86790::Holder *>(this)->FUN_00c86790((::fnv_00c86790::NiStream *)(obj = apObj));
    if (obj->m_1e5 != 1)
    {
        volatile unsigned int* p = vGet((FUN_00cc3440_obj**)&apObj);
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
    }
}

struct PacketReader {
    void ReadPacketWithByteSwap(void* context);
};
typedef unsigned int* (*GetPacketBlock)(PacketReader*, unsigned char*);
// @fnv 0x00cc34a0
void PacketReader::ReadPacketWithByteSwap(void* context) {
    unsigned char format;
    volatile unsigned int* words = ((GetPacketBlock*)*(void**)this)[45](this, &format);
    if (((unsigned char*)context)[0x1E4] != 1) {
        words[4] = _byteswap_ulong(words[4]);
        words[5] = _byteswap_ulong(words[5]);
        words[6] = _byteswap_ulong(words[6]);
        words[7] = _byteswap_ulong(words[7]);
        words[8] = _byteswap_ulong(words[8]);
        words[9] = _byteswap_ulong(words[9]);
    }
    reinterpret_cast<::FUN_00c868b0_cls *>(this)->FUN_00c868b0((::C868_Iface *)(context));
    if (((unsigned char*)context)[0x1E4] != 1) {
        words[4] = _byteswap_ulong(words[4]);
        words[5] = _byteswap_ulong(words[5]);
        words[6] = _byteswap_ulong(words[6]);
        words[7] = _byteswap_ulong(words[7]);
        words[8] = _byteswap_ulong(words[8]);
        words[9] = _byteswap_ulong(words[9]);
    }
}

namespace fnv_00cc3630 {
struct TlsBlock_t
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t()
    {
        m_saved = (*reinterpret_cast<::fnv_00cc3630::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00cc3630::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        (*reinterpret_cast<::fnv_00cc3630::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

struct HeapAllocator_t
{
};
extern unsigned int DAT_0126fd98;

struct AlignedObj_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    unsigned char unk28;
};

class CacheOwner_cls
{
public:
    int unk00;
    int unk04;
    int m_08;
    AlignedObj_t* m_0c;
    AlignedObj_t* FUN_00cc3630(bool* out);
};

// @fnv 0x00cc3630
AlignedObj_t* CacheOwner_cls::FUN_00cc3630(bool* pbCreated)
{
    TlsGuard_t guard;
    *pbCreated = (m_0c == 0);
    if (*pbCreated)
    {
        AlignedObj_t* p = (AlignedObj_t*)((char *)(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00cc3630::HeapAllocator_t *>(&::g_memoryManager))))->FUN_00aa3e40(0x40)));
        unsigned char shift = (unsigned char)(0x10 - ((unsigned char)(unsigned int)p & 0xf));
        p = (AlignedObj_t*)((char*)p + shift);
        ((unsigned char*)p)[-1] = shift;
        p->unk00 = 0;
        p->unk04 = 0;
        ((volatile AlignedObj_t*)p)->unk10 = 0.0f;
        p->unk14 = 0.0f;
        p->unk18 = 0.0f;
        p->unk1C = 0.0f;
        p->unk20 = 0.0f;
        p->unk24 = ::DAT_010162c0;
        ((volatile AlignedObj_t*)p)->unk28 = 1;
        m_0c = p;
        if (m_08 != 0)
        {
            reinterpret_cast<::CC3320Constraint *>(this)->FUN_00cc3320((::CC3320Info *)(p));
        }
    }
    return m_0c;
}
}  // namespace fnv_00cc3630

extern int DAT_012685c4;

class FUN_00cc39b0_base {
public:
    virtual void unk00();
    ~FUN_00cc39b0_base();
    int unk04;
};

class FUN_00cc39b0 : public FUN_00cc39b0_base {
public:
    virtual ~FUN_00cc39b0();
    void unk08();
};

// Calls unk08 on this object and decrements the global counter DAT_012685c4.
// @fnv 0x00cc39b0
FUN_00cc39b0::~FUN_00cc39b0()
{
    reinterpret_cast<::ProjectileListener *>((this))->FUN_00c876a0();
    DAT_012685c4--;
}

extern int DAT_012685c8;

// @fnv 0x00cc3a20
void* __cdecl FUN_00cc3a20()
{
    return &DAT_012685c8;
}

extern int DAT_010c970c;
extern int DAT_012685c4;

struct DerivedStandin2 : A51BF0Base, S_00cb79d0_Base {
    unsigned int m_uiField3;

    DerivedStandin2()
        : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c970c);
        DAT_012685c4 += count;
    }
};

// Allocates and constructs a DerivedStandin2 object, returning its pointer.
// @fnv 0x00cc3b30
void* CreateDerivedStandin2() {
    return new DerivedStandin2();
}

struct FUN_00cc3bd0_arg
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
    unsigned char unk1E4;
    unsigned char m_1e5;
};

struct FUN_00cc3bd0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void FUN_00cc3bd0(FUN_00cc3bd0_arg* a1);
};

// Calls FUN_00c8a7a0 with the argument, then unless m_1e5 is 1, byte-swaps words 4 through 13 of the buffer returned by vGet.
// @fnv 0x00cc3bd0
void FUN_00cc3bd0_cls::FUN_00cc3bd0(FUN_00cc3bd0_arg* a1)
{
    unsigned int tmp;
    reinterpret_cast<::FUN_00c8a7a0_cls *>(this)->FUN_00c8a7a0((volatile unsigned int)(a1));
    if (a1->m_1e5 != 1)
    {
        volatile unsigned int* p = vGet((unsigned char*)&tmp);
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
    }
}

struct FUN_00cc3c50_arg
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
    unsigned char m_1e4;
};

struct FUN_00cc3c50_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void FUN_00cc3c50(FUN_00cc3c50_arg* a1);
};

// If a1->m_1e4 is not 1, byte-swaps p[4]..p[13] before and after calling DispatchChainNodes(a1).
// @fnv 0x00cc3c50
void FUN_00cc3c50_cls::FUN_00cc3c50(FUN_00cc3c50_arg* a1)
{
    unsigned int tmp;
    volatile unsigned int* p = vGet((unsigned char*)&tmp + 3);
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
    }
    reinterpret_cast<::RefChainOwner *>(this)->DispatchChainNodes((::Dispatcher *)(a1));
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
    }
}

namespace fnv_00cc3e50 {
struct TlsBlock_t
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t()
    {
        m_saved = (*reinterpret_cast<::fnv_00cc3e50::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00cc3e50::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        (*reinterpret_cast<::fnv_00cc3e50::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

struct HeapAllocator_t
{
};
extern unsigned int DAT_0126fd98;

struct AlignedObj_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
};

class CacheOwner_cls
{
public:
    int unk00;
    int unk04;
    int m_08;
    AlignedObj_t* m_0c;
    AlignedObj_t* FUN_00cc3e50(bool* out);
};

// @fnv 0x00cc3e50
AlignedObj_t* CacheOwner_cls::FUN_00cc3e50(bool* apIsNull)
{
    TlsGuard_t guard;
    *apIsNull = (m_0c == 0);
    if (*apIsNull)
    {
        AlignedObj_t* p = (AlignedObj_t*)((char *)(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00cc3e50::HeapAllocator_t *>(&::g_memoryManager))))->FUN_00aa3e40(0x50)));
        unsigned char shift = (unsigned char)(0x10 - ((unsigned char)(unsigned int)p & 0xf));
        p = (AlignedObj_t*)((char*)p + shift);
        ((unsigned char*)p)[-1] = shift;
        p->unk00 = 0;
        p->unk04 = 0;
        p->unk08 = 0;
        ((volatile AlignedObj_t*)p)->unk10 = 0.0f;
        p->unk14 = 0.0f;
        p->unk18 = 0.0f;
        p->unk1C = 0.0f;
        p->unk20 = 0.0f;
        p->unk24 = 0.0f;
        p->unk28 = 0.0f;
        p->unk2C = 0.0f;
        p->unk30 = ::DAT_0101e2bc;
        p->unk34 = ::DAT_01013ea4;
        m_0c = p;
        if (m_08 != 0)
        {
            reinterpret_cast<::WorldObjectCC3 *>(this)->FUN_00cc3a50((::PropertiesCC3 *)(p));
        }
    }
    return m_0c;
}
}  // namespace fnv_00cc3e50

extern int DAT_012685d4;

// @fnv 0x00cc41f0
int* __cdecl FUN_00cc41f0()
{
    return &DAT_012685d4;
}

struct FUN_00cc4220_source {
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
};

struct FUN_00cc4220_output {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
};

struct FUN_00cc4220_class {
    void* unk00;
    void* unk04;
    FUN_00cc4220_source* m_p;

    void FUN_00cc4220(void* p);
};


// Calls WriteScriptTargetInfo, then copies m_f34, the four floats at m_f20 and m_f30 from m_p into the output, using defaults when m_p is null.
// @fnv 0x00cc4220
void FUN_00cc4220_class::FUN_00cc4220(void* apOutput)
{
    FUN_00cc4220_output* out = static_cast<FUN_00cc4220_output*>(apOutput);

    reinterpret_cast<::FUN_00c8a800_cls *>((this))->WriteScriptTargetInfo((::ScriptOutBlock *)(apOutput));

    float value = (this != 0 && this->m_p != 0)
        ? this->m_p->m_f34
        : 0.0f;
    out->m_f24 = value;

    const float* values = (this != 0 && this->m_p != 0)
        ? &this->m_p->m_f20
        : &::DAT_012683b0;

    out->m_f10 = values[0];
    out->m_f14 = values[1];
    out->m_f18 = values[2];
    out->m_f1c = values[3];

    float position = (this != 0 && this->m_p != 0)
        ? this->m_p->m_f30
        : 0.0f;
    out->m_f20 = position;
}

namespace fnv_00cc4340 {


extern unsigned int g_ctorCount1;
extern unsigned int g_ctorCount2;
extern unsigned int g_ctorCount3;

class NodeRoot_cls {
public:
    NodeRoot_cls();
    virtual void r00();
};

class NodeA_cls : public NodeRoot_cls {
public:
    int unk04;
    int unk08;
    volatile int m_0c;
    NodeA_cls() : NodeRoot_cls() {
        m_0c = 0;
        g_ctorCount1 += 1;
    }
    virtual void a00();
};

class NodeB_cls : public NodeA_cls {
public:
    NodeB_cls() : NodeA_cls() {
        g_ctorCount2++;
    }
    virtual void b00();
};

class NodeC_cls : public NodeB_cls {
public:
    NodeC_cls() : NodeB_cls() {
        g_ctorCount3++;
    }
    virtual void c00();
};

class FUN_00cc4340_cls {
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
    virtual void v50();
    virtual void v51();
    virtual void v52(NodeC_cls* node, int a1);
    NodeC_cls* FUN_00cc4340(int a1);
};

// Allocates a NodeC_cls, passes it with a1 to v52, and returns the new node.
// @fnv 0x00cc4340
NodeC_cls* FUN_00cc4340_cls::FUN_00cc4340(int a1) {
    ::FUN_00c876f0();
    NodeC_cls* p = new NodeC_cls();
    this->v52(p, a1);
    ::FUN_00c87700();
    return p;
}
}  // namespace fnv_00cc4340

inline void CC4400Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}

struct CC4400Stream {
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
    unsigned char unk1E4;
    unsigned char m_ucPlatform;
};

struct CC4400Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_aulValues0;
    unsigned long m_aulValues1;
    unsigned long m_aulValues2;
    unsigned long m_aulValues3;
    unsigned long m_aulValues4;
    unsigned long m_aulValues5;
};

class CC4400Base {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual CC4400Data* GetData(unsigned int* puiSize);

};

class CC4400Object : public CC4400Base {
public:
    void FUN_00cc4400(CC4400Stream* pkStream);
};

// @fnv 0x00cc4400
void CC4400Object::FUN_00cc4400(CC4400Stream* pkStream)
{
    reinterpret_cast<::FUN_00c8a7a0_cls *>(this)->FUN_00c8a7a0((volatile unsigned int)(pkStream));
    if (pkStream->m_ucPlatform != 1) {
        unsigned int uiSize;
        CC4400Data* pkData = GetData(&uiSize);
        CC4400Swap(pkData->m_aulValues0);
        CC4400Swap(pkData->m_aulValues1);
        CC4400Swap(pkData->m_aulValues2);
        CC4400Swap(pkData->m_aulValues3);
        CC4400Swap(pkData->m_aulValues4);
        CC4400Swap(pkData->m_aulValues5);
    }
}

namespace fnv_00cc4500 {
extern "C" float DAT_012683b4;
extern "C" float DAT_012683b8;
extern "C" float DAT_012683bc;

class FUN_00cc4500_cls {
public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int unk0C;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;

    FUN_00cc4500_cls* FUN_00cc4500();
};

// Zeroes the first fields, then stores the global float constants into m_20, m_24 and m_10 through m_1c, and returns this.
// @fnv 0x00cc4500
FUN_00cc4500_cls* FUN_00cc4500_cls::FUN_00cc4500() {
    float zero = 0.0f;
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    *(volatile float*)&m_10 = zero;
    *(volatile float*)&m_14 = zero;
    *(volatile float*)&m_18 = zero;
    *(volatile float*)&m_1c = zero;
    m_20 = ::DAT_0101e2bc;
    m_24 = ::DAT_01013ea4;
    m_10 = DAT_012683b0;
    m_14 = DAT_012683b4;
    m_18 = DAT_012683b8;
    m_1c = DAT_012683bc;
    return this;
}
}  // namespace fnv_00cc4500


// @fnv 0x00cc4860
int* __cdecl FUN_00cc4860()
{
    return reinterpret_cast<int*>(&::g_012685e0);
}

extern int g_ctorCountA;
extern int g_ctorCountD;



struct OwnerBase {
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

};

struct ChainA_cls : public OwnerBase {
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_cls() {
        m_0c = 0;
        g_ctorCountA += 1;
    }
};

struct SpawnedObject : public ChainA_cls {
    virtual void unkD2();
    SpawnedObject() {
        g_ctorCountD += 1;
    }
};

// Allocates and constructs a new SpawnedObject via its operator new and returns the pointer.
// @fnv 0x00cc4900
SpawnedObject* FUN_00cc4900() {
    return new SpawnedObject();
}

struct S_00cc4b90_Tls {
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
    int ctx;
};
__declspec(thread) S_00cc4b90_Tls DAT_tls;

struct S_00cc4b90_Ctx {
    int saved;
    __forceinline S_00cc4b90_Ctx(int c) { saved = (*reinterpret_cast<::S_00cc4b90_Tls *>(&::g_tlsBlock)).ctx; (*reinterpret_cast<::S_00cc4b90_Tls *>(&::g_tlsBlock)).ctx = c; }
    __forceinline ~S_00cc4b90_Ctx() { (*reinterpret_cast<::S_00cc4b90_Tls *>(&::g_tlsBlock)).ctx = saved; }
};
struct S_00cc4b90_Alloc {
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00cc4b90_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00cc4b90_Alloc* unk10;
    S_00cc4b90_Alloc& heap() { return *unk10; }
};
struct S_00cc4b90_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00cc4b90_RefObj();
    void* operator new(std::size_t n) {
        S_00cc4b90_RefObj* b = static_cast<S_00cc4b90_RefObj*>(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*) {}
};
struct S_00cc4b90_Base : S_00cc4b90_RefObj {
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00cc4b90_Base(int a);
};
struct __declspec(novtable) S_00cc4b90_Mid : S_00cc4b90_Base {
    float f20;
    S_00cc4b90_Mid() : S_00cc4b90_Base(0), f20(DAT_01017b78) {}
};
struct S_00cc4b90_Obj : S_00cc4b90_Mid {
    unsigned char b24;
    unsigned char b25;
    S_00cc4b90_Obj() { b24 = 0; b25 = 0; }
};
struct S_00cc4b90_Cls {
    int unk0;
    S_00cc4b90_Obj* m_p;
    int GetObjSize();
};
// Ensures m_p is allocated via the heap allocator if null, then returns sizeof(S_00cc4b90_Obj).
// @fnv 0x00cc4b90
int S_00cc4b90_Cls::GetObjSize()
{
    S_00cc4b90_Ctx ctx(0x10);
    if (!m_p)
        m_p = new S_00cc4b90_Obj;
    return sizeof(S_00cc4b90_Obj);
}

namespace fnv_00cc4c60 {
struct TlsBlock_t
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

extern int g_ctrA;
extern int g_ctrD;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = (*reinterpret_cast<::fnv_00cc4c60::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00cc4c60::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        (*reinterpret_cast<::fnv_00cc4c60::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};



class OwnerBase_t
{
public:
    OwnerBase_t();
    virtual void unkB0();
    virtual ~OwnerBase_t();
    unsigned int m_04;
    unsigned int m_08;

};

class ChainA_t : public OwnerBase_t
{
public:
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_t()
    {
        m_0c = 0;
        g_ctrA += 1;
    }
};

class SpawnedObject_t : public ChainA_t
{
public:
    virtual void unkD2();
    SpawnedObject_t()
    {
        g_ctrD += 1;
    }
};

struct FUN_00cc4c60_cls
{
    int unk00;
    int unk04;
    SpawnedObject_t* FUN_00cc4c60(unsigned int arg);
};

// @fnv 0x00cc4c60
SpawnedObject_t* FUN_00cc4c60_cls::FUN_00cc4c60(unsigned int arg)
{
    TlsGuard_t guard;
    SpawnedObject_t* result = 0;
    ::FUN_00c876f0();
    result = new SpawnedObject_t();
    reinterpret_cast<::Owner89730 *>(this)->FUN_00c89730(result, (::Process89730 *)(arg));
    ::FUN_00c87700();
    return result;
}
}  // namespace fnv_00cc4c60

struct FUN_00cc4e90_stream;

typedef unsigned int (__cdecl* FUN_00cc4e90_readfn)(FUN_00cc4e90_stream* s, void* dst, unsigned int size, unsigned int* outCount, unsigned int count);

struct FUN_00cc4e90_stream
{
    int unk00;
    unsigned int m_04;
    int unk08;
    FUN_00cc4e90_readfn m_0c;
};

struct FUN_00cc4e90_sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
};


class FUN_00cc4e90_cls
{
public:
    int unk00;
    FUN_00cc4e90_sub* m_04;
    void LoadSubData(int a1);
};

// Calls FUN_00c8a280, passes m_04->m_18 to FUN_00cf4bc0, then reads 4 bytes into m_04->unk20 and 1 byte into m_04->unk24 from the stream at a1+0x250.
// @fnv 0x00cc4e90
void FUN_00cc4e90_cls::LoadSubData(int a1)
{
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((*(::S_00c8a280_Stream *)(a1)));
    FUN_00cc4e90_sub* b = m_04;
    ::FUN_00cf4bc0((*(::CF4BC0Stream *)(a1)), (::CF4BC0Object *)(b->m_18));
    FUN_00cc4e90_stream* s = *(FUN_00cc4e90_stream**)((char*)a1 + 0x250);
    { unsigned int n = 4; s->m_04 += s->m_0c(s, &b->unk20, 4, &n, 1); }
    s = *(FUN_00cc4e90_stream**)((char*)a1 + 0x250);
    { unsigned int n = 1; s->m_04 += s->m_0c(s, &b->unk24, 1, &n, 1); }
}

extern int DAT_012685e8;

struct SpawnedBase {
    virtual ~SpawnedBase();
};

struct FUN_00cc5090 : SpawnedBase {
    virtual ~FUN_00cc5090();
};

// @fnv 0x00cc5090
FUN_00cc5090::~FUN_00cc5090()
{
    reinterpret_cast<::ProjectileListener *>((((bhkConstraint*)this)))->FUN_00c876a0();
    DAT_012685e8--;
}

extern int g_unk012685ec;

// @fnv 0x00cc5100
void* __cdecl FUN_00cc5100(void)
{
    return &g_unk012685ec;
}

namespace fnv_00cc5340 {

struct Allocator {
    virtual void Release();
    virtual void* Allocate(unsigned int size);
};

struct MemorySystem {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    Allocator* allocator;

    void* Allocate(unsigned int bytes) {
        return allocator->Allocate(bytes);
    }
};


struct FUN_00d4edc0 {
    FUN_00d4edc0();
    static void* operator new(std::size_t size) {
        void* memory = static_cast<MemorySystem*>(::FUN_00c85750())->Allocate(0x160);
        *reinterpret_cast<unsigned short*>(
            static_cast<char*>(memory) + 4) = 0x160;
        return memory;
    }
};

struct AllocationContext {
    int previous;
    AllocationContext() {
        previous = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }
    ~AllocationContext() {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};

struct ObjectHolder {
    int m_00;
    FUN_00d4edc0* object;
    int EnsureObjectAllocated();
};

// Creates the object via new FUN_00d4edc0 if it is null, then returns 0x160.
// @fnv 0x00cc5340
int ObjectHolder::EnsureObjectAllocated() {
    AllocationContext context;
    if (object == 0) {
        object = new FUN_00d4edc0();
    }
    return 0x160;
}
}  // namespace fnv_00cc5340

namespace fnv_00cc53f0 {

extern int DAT_01268188;
extern int DAT_012685e8;

struct HavokRuntimeObject {
    void* vtable;
    int refCount;
    int heapFlags;
    int extra;
    void FUN_00c87c30();
    HavokRuntimeObject() {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        vtable = &::DAT_0108febc;
        extra = 0;
        ++DAT_01268188;
        vtable = &::fnv_00cc5130::DAT_010c9a14;
        ++DAT_012685e8;
    }
};
struct HavokThreadScope {
    int oldValue;
    HavokThreadScope() {
        oldValue = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~HavokThreadScope() {
        ::FUN_00c87700();
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = oldValue;
    }
};
struct HavokAllocator {
    HavokRuntimeObject* CreateRuntimeObject(int argument);
};
// @fnv 0x00cc53f0
HavokRuntimeObject* HavokAllocator::CreateRuntimeObject(int argument) {
    HavokThreadScope scope;
    ::FUN_00c876f0();
    HavokRuntimeObject* obj = new HavokRuntimeObject;
    reinterpret_cast<::Owner89730 *>(this)->FUN_00c89730(obj, (::Process89730 *)(argument));
    return obj;
}
}  // namespace fnv_00cc53f0

struct BinaryStream {
    void* m_ppVirtualMethodTable;
    unsigned int m_vContactPosition;
    void* m_pOwnerObject;
    int (__cdecl *m_write)(BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int count) {
        unsigned int actualCount = count;
        m_vContactPosition += m_write(this, data, count, &actualCount, 1);
    }
};
struct StreamContext {
    BinaryStream* OutputStream() {
        return *reinterpret_cast<BinaryStream**>(reinterpret_cast<unsigned char*>(this) + 0x250);
    }
};
struct FUN_00cc5730_class {
    void* m_ppVirtualMethodTable;
    unsigned char* m_objectData;
    void FUN_00cc5730(StreamContext* context);
};
// @fnv 0x00cc5730
void FUN_00cc5730_class::FUN_00cc5730(StreamContext* context) {
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((*(::S_00c8a280_Stream *)(context)));
    unsigned char* data = m_objectData;
    context->OutputStream()->Write(data + 0x20, 0x40);
    context->OutputStream()->Write(data + 0x60, 0x40);
    context->OutputStream()->Write(data + 0xd0, 0x30);
    context->OutputStream()->Write(data + 0x100, 0x30);
    context->OutputStream()->Write(data + 0x140, 0x10);
    context->OutputStream()->Write(data + 0x150, 0x10);
    context->OutputStream()->Write(data + 0xa4, 4);
    context->OutputStream()->Write(data + 0xa8, 4);
    context->OutputStream()->Write(data + 0xb0, 4);
    context->OutputStream()->Write(data + 0xb4, 4);
}

extern int DAT_012685f4;

class FUN_00cc58c0_base {
public:
    virtual void unk00();
    ~FUN_00cc58c0_base();
    int unk04;
};

class FUN_00cc58c0 : public FUN_00cc58c0_base {
public:
    virtual ~FUN_00cc58c0();
    void unk08();
};

// Calls unk08 on this object and decrements the global counter DAT_012685f4.
// @fnv 0x00cc58c0
FUN_00cc58c0::~FUN_00cc58c0()
{
    reinterpret_cast<::ProjectileListener *>((this))->FUN_00c876a0();
    DAT_012685f4--;
}

extern int DAT_01268188;
extern int DAT_012685f4;

struct CC5930_Base {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiData08;
    CC5930_Base();
};

struct CC5930_Obj : CC5930_Base {
    unsigned int m_uiData0C;

    CC5930_Obj()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0108febc);
        m_uiData0C = 0;
        DAT_01268188 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c52bc);
        DAT_012685f4 += count;
    }
};

// Allocates and constructs a CC5930_Obj, returning the new object.
// @fnv 0x00cc5930
CC5930_Obj* __cdecl CreateCC5930Obj()
{
    return new CC5930_Obj;
}

struct CC5D40BinaryStream {
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(CC5D40BinaryStream* pkStream, void* pvBuffer, unsigned int uiSize, unsigned int* puiSizes, unsigned int ItemUpdateArray);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

class CC5D40Stream {
public:
    int unk000;
    int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024; int unk028; int unk02C; int unk030;
    int unk034; int unk038; int unk03C; int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060;
    int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084; int unk088; int unk08C; int unk090;
    int unk094; int unk098; int unk09C; int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0;
    int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0;
    int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120;
    int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144; int unk148; int unk14C; int unk150;
    int unk154; int unk158; int unk15C; int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; int unk180;
    int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0;
    int unk1B4; int unk1B8; int unk1BC; int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC; int unk1E0;
    int unk1E4; int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200; int unk204; int unk208; int unk20C; int unk210;
    int unk214; int unk218; int unk21C; int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C; int unk240;
    int unk244; int unk248;
    CC5D40BinaryStream* m_pUnderlyingStream;
};

template <class T>
inline void CC5D40BinaryStreamLoad(CC5D40BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CC5D40LoadBinary(CC5D40Stream& kStream, T& value)
{
    CC5D40BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

struct CC5D40Vector4 {
    float x;
    float y;
    float z;
    float w;
};

struct CC5D40Constraint {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    CC5D40Vector4 m_kPivotA;
    CC5D40Vector4 m_kPivotB;
    int unk40;
    float m_fTau;
};

class CC5D40RefObject {
public:
    int unk00;
    CC5D40Constraint* m_pkConstraint;

};

class CC5D40BallJoint : public CC5D40RefObject {
public:
    void FUN_00cc5d40(CC5D40Stream& kStream);
};

class CC5DD0BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(CC5DD0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl *m_pfnWrite)(CC5DD0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count) {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class CC5DD0Object;

class CC5DD0Stream {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(CC5DD0Object* pkObject);

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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    CC5DD0BinaryStream* m_pBackingStream;
};

template <class T>
inline void CC5DD0BinaryStreamSave(CC5DD0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1) {
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CC5DD0SaveBinary(CC5DD0Stream& kStream, const T& value) {
    CC5DD0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

struct CC5DD0Vector4 {
    float x;
    float y;
    float z;
    float w;
};

struct CC5DD0Constraint {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    CC5DD0Vector4 m_kPivotA;
    CC5DD0Vector4 m_kPivotB;
    int unk40;
    float m_fTau;
};

class CC5DD0RefObject {
public:
    int unk00;
    CC5DD0Constraint* m_pkConstraint;

};

class CC5DD0BallJoint : public CC5DD0RefObject {
public:
    void FUN_00cc5dd0(CC5DD0Stream& kStream);
};

// SaveBinary
// Saves the base object, then writes the constraint's pivot A, pivot B and tau to the stream.
// @fnv 0x00cc5dd0
void CC5DD0BallJoint::FUN_00cc5dd0(CC5DD0Stream& kStream) {
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((::S_00c8a280_Stream &)(kStream));
    CC5DD0Constraint* pkConstraint = m_pkConstraint;
    CC5DD0SaveBinary(kStream, pkConstraint->m_kPivotA);
    CC5DD0SaveBinary(kStream, pkConstraint->m_kPivotB);
    CC5DD0SaveBinary(kStream, pkConstraint->m_fTau);
}

extern int DAT_01268600;

struct FUN_00cc5e60 : bhkConstraint {
    ~FUN_00cc5e60();
};
// @fnv 0x00cc5f10
FUN_00cc5f10_Class* FUN_00cc5f10_Class::FUN_00cc5f10(unsigned int flag)
{
    reinterpret_cast<::FUN_00cc5e60 *>(this)->FUN_00cc5e60::~FUN_00cc5e60();
    if (flag & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}

// @fnv 0x00cc5e60
FUN_00cc5e60::~FUN_00cc5e60()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_01268600;
}

extern int DAT_01268604;

// @fnv 0x00cc5ed0
int* __cdecl FUN_00cc5ed0()
{
    return &DAT_01268604;
}

struct FUN_00cc5ee0_interface
{
    virtual void FUN_00cc5ee0_call(int value) = 0;
};

struct FUN_00cc5ee0_class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;

    void ClearInterface(char param_2);
};

// @fnv 0x00cc5ee0
void FUN_00cc5ee0_class::ClearInterface(char abClear)
{
    if (abClear != 0)
    {
        if (unk0c != 0)
        {
            FUN_00cc5ee0_interface* object =
                reinterpret_cast<FUN_00cc5ee0_interface*>(
                    reinterpret_cast<unsigned char*>(unk0c) - 4);

            if (object != 0)
            {
                object->FUN_00cc5ee0_call(1);
            }
        }

        unk0c = 0;
    }
}

namespace fnv_00cc6140 {
struct Helper {
};

struct Helper2 {
    void* FUN_00c87c30();
};



extern int DAT_01268188;
extern int DAT_01268600;

struct Obj {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;


    Obj() {
        reinterpret_cast<::FUN_00c87c30_t *>((((Helper2*)this)))->FUN_00c87c30();
        m_pVtable = (void*)&::DAT_0108febc;
        int one = 1;
        m_uiData1 = 0;
        DAT_01268188 += one;
        m_pVtable = (void*)&::fnv_00cc60b0::DAT_010c9b0c;
        DAT_01268600 += one;
    }
};

struct C {
    void* FUN_00cc6140(int arg);
};

// Calls FUN_00c876f0, allocates an Obj, passes it with arg to FUN_00c89730, calls FUN_00c87700 and returns the Obj.
// @fnv 0x00cc6140
void* C::FUN_00cc6140(int arg) {
    ::FUN_00c876f0();
    Obj* esi = new Obj();
    reinterpret_cast<::Owner89730 *>((((Helper*)this)))->FUN_00c89730(esi, (::Process89730 *)(arg));
    ::FUN_00c87700();
    return esi;
}
}  // namespace fnv_00cc6140

namespace fnv_00cc6310 {
struct S_cc6310_Tls {
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
};
__declspec(thread) S_cc6310_Tls g_tls_cc6310;
struct S_cc6310_Guard {
    int saved;
    S_cc6310_Guard() { saved = (*reinterpret_cast<::fnv_00cc6310::S_cc6310_Tls *>(&::g_tlsBlock)).unk2B4; (*reinterpret_cast<::fnv_00cc6310::S_cc6310_Tls *>(&::g_tlsBlock)).unk2B4 = 0x10; }
    ~S_cc6310_Guard() { (*reinterpret_cast<::fnv_00cc6310::S_cc6310_Tls *>(&::g_tlsBlock)).unk2B4 = saved; }
};
struct S_cc6310_Pool {
};
extern int DAT_010c9be8;
struct S_cc6310_Base {
    int unk00;
};
struct S_cc6310_Obj {
    int* unk00;
    S_cc6310_Base base;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_cc6310 {
    int unk00;
    int unk04;
    int unk08;
    S_cc6310_Base* unk0c;
    S_cc6310_Base* GetOrCreateBase(bool* created);
};
// Sets *created when unk0c is null, allocates and initialises a new S_cc6310_Obj, stores its base in unk0c, and returns unk0c.
// @fnv 0x00cc6310
S_cc6310_Base* S_cc6310::GetOrCreateBase(bool* created) {
    S_cc6310_Guard guard;
    bool b = (unk0c == 0);
    *created = b;
    if (b) {
        S_cc6310_Obj* c = new S_cc6310_Obj;
        S_cc6310_Base* r;
        if (c) {
            S_cc6310_Base* pBase = &c->base;
            c->unk08 = 1;
            c->unk0c = 0;
            c->unk10 = 0;
            c->unk00 = &DAT_010c9be8;
            pBase->unk00 = 0;
            r = pBase;
        } else {
            r = 0;
        }
        unk0c = r;
        if (unk08)
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((void*)(unk0c ? (S_cc6310_Obj*)((char*)unk0c - 4) : 0));
    }
    return unk0c;
}
}  // namespace fnv_00cc6310

namespace fnv_00cc6720 {
struct hkMemoryAllocator {
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct AudioMgr {
    int unk00[4];
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap() { return *unk10; }
};

struct BSAudio;

class RefObj {
public:
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(std::size_t nbytes)
    {
        RefObj* b = (RefObj*)((AudioMgr*)static_cast<BSAudio*>(::FUN_00c85750()))->heap().AllocateMemoryBlock(nbytes);
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void __cdecl operator delete(void* p);
};

class Payload : public RefObj {
public:
    Payload();
    char m_08[0x140 - 8];
};

class Owner {
public:
    int m_00;
    Payload* m_pkPayload;
    int EnsurePayload();
};

// Allocates a Payload into m_pkPayload if it is null, then returns sizeof(Payload).
// @fnv 0x00cc6720
int Owner::EnsurePayload()
{
    if (!m_pkPayload)
        m_pkPayload = new Payload();
    return sizeof(Payload);
}
}  // namespace fnv_00cc6720

extern int DAT_01268618;

class FUN_00cc7450_base {
public:
    virtual void unk00();
    ~FUN_00cc7450_base();
    int unk04;
};

class FUN_00cc7450 : public FUN_00cc7450_base {
public:
    virtual ~FUN_00cc7450();
    void unk08();
};

// @fnv 0x00cc7450
FUN_00cc7450::~FUN_00cc7450()
{
    reinterpret_cast<::ProjectileListener *>((this))->FUN_00c876a0();
    DAT_01268618--;
}

extern int DAT_0126861c;

// @fnv 0x00cc74c0
void* __cdecl FUN_00cc74c0()
{
    return &DAT_0126861c;
}

// FUN_00cc74d0 : a one-line function - getter
extern int g_target_00cc74d0;
// @fnv 0x00cc74d0
void* FUN_00cc74d0() { return &g_target_00cc74d0; }

// FUN_00cc75b0: thiscall, one stack arg (int a1).
class FUN_00cc75b0_F {
public:
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
    float m_b4;
};

class FUN_00cc75b0_C {
public:
    FUN_00cc75b0_F* m_00;
};

class FUN_00cc75b0_B {
public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cc75b0_F* m_08;
    FUN_00cc75b0_F* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char unk1c;
    unsigned char m_1d;
};

class FUN_00cc75b0_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cc75b0_B* m_08;
    FUN_00cc75b0_C* m_0c;
    void FUN_00cc75b0(int a1);
};

// @fnv 0x00cc75b0
void FUN_00cc75b0_cls::FUN_00cc75b0(int aiArg) {
    FUN_00cc75b0_F* f = 0;
    reinterpret_cast<::Dispatch_00c89dd0 *>(this)->SpawnAndAttach(aiArg);
    if (this != 0 && this->m_08 != 0) {
        f = this->m_08->m_0c;
    } else {
        FUN_00cc75b0_C* c = this->m_0c;
        if (c != 0) f = c->m_00;
    }
    if (f != 0 && f->m_b4 != 0.0f) {
        FUN_00cc75b0_B* b = this->m_08;
        if (b != 0) b->m_1d = 1;
    }
}

namespace fnv_00cc7890 {


struct SpawnBase
{
    virtual ~SpawnBase();
    SpawnBase();
    unsigned int unk04;
    unsigned int unk08;
};

extern unsigned int g_spawnCountA;
extern unsigned int g_spawnCountB;

struct SpawnChainA : SpawnBase
{
    SpawnChainA();
    unsigned int m_0c;
};

struct SpawnedObject : SpawnChainA
{
    virtual ~SpawnedObject() {}
    SpawnedObject();
};


SpawnChainA::SpawnChainA()
{
    m_0c = 0;
    g_spawnCountA++;
}

SpawnedObject::SpawnedObject()
{
    g_spawnCountB++;
}

struct ThreadHeapState
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};



class FUN_00cc7890_cls
{
public:
    void* FUN_00cc7890(unsigned int arg);
};

struct TlsHeapGuard
{
    unsigned int saved;
    TlsHeapGuard() { saved = (*reinterpret_cast<::fnv_00cc7890::ThreadHeapState *>(&::g_tlsBlock)).m_2b4; (*reinterpret_cast<::fnv_00cc7890::ThreadHeapState *>(&::g_tlsBlock)).m_2b4 = 0x10; }
    ~TlsHeapGuard() { (*reinterpret_cast<::fnv_00cc7890::ThreadHeapState *>(&::g_tlsBlock)).m_2b4 = saved; }
};

// Allocates a SpawnedObject under a TLS heap guard, initializes it via SpawnInit with arg, calls FUN_00c87700 and returns the object.
// @fnv 0x00cc7890
void* FUN_00cc7890_cls::FUN_00cc7890(unsigned int arg)
{
    TlsHeapGuard guard;
    SpawnedObject* obj = new SpawnedObject();
    reinterpret_cast<::Owner89730 *>(this)->FUN_00c89730(obj, (::Process89730 *)(arg));
    ::FUN_00c87700();
    return obj;
}
}  // namespace fnv_00cc7890

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

struct NiBinaryStreamSI {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamSI* pThis, void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, 0, 0);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

template <class T> inline void NiStreamLoadBinarySI(NiBinaryStreamSI& kBinStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.BinaryRead(&value, uiSize, &uiSize, 1);
}

struct NiStreamSI {
    void* m_pVtable;
    unsigned int m_uiNifVersion;
    int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024;
    int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044;
    int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060; int unk064;
    int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084;
    int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0; int unk0A4;
    int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0; int unk0C4;
    int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4;
    int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104;
    int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124;
    int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144;
    int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C; int unk160; int unk164;
    int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; int unk180; int unk184;
    int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0; int unk1A4;
    int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC; int unk1C0; int unk1C4;
    int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC; int unk1E0; unsigned char unk1E4; unsigned char m_bLittleEndian; unsigned short unk1E6;
    int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200; int unk204;
    int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C; int unk220; int unk224;
    int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C; int unk240; int unk244;
    int unk248;
    NiBinaryStreamSI* m_pUnderlyingStream;
};

struct hkVector4SI {
    float x;
    float y;
    float z;
    float w;
};

struct hkRotationSI {
    hkVector4SI m_kColumn0;
    hkVector4SI m_kColumn1;
    hkVector4SI m_kColumn2;
};

struct hkTransformSI {
    hkRotationSI m_rotation;
    hkVector4SI m_vTranslation;
};


inline void Swap32SI(void* p)
{
    *(unsigned int*)p = _byteswap_ulong(*(unsigned int*)p);
}

inline void SwapVector4SI(hkVector4SI* v)
{
    Swap32SI(&v->x);
    Swap32SI(&v->y);
    Swap32SI(&v->z);
    Swap32SI(&v->w);
}

inline void SwapTransformSI(hkTransformSI* t)
{
    SwapVector4SI(&t->m_vTranslation);
    ::SwapEndianBlocks((unsigned int *)(t));
}

struct hkRefObjSI {
};

struct ConstraintDataSI {
    void* m_pVtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkTransformSI m_kBodyALocalFrame;
    hkTransformSI m_kBodyBLocalFrame;
    unsigned short unkA0;
    unsigned char m_bMotorEnabled;
    unsigned char unkA3;
    int unkA4; int unkA8; int unkAC; int unkB0;
    float m_fB4;
    int unkB8; int unkBC; int unkC0; int unkC4;
    float m_fC8;
    float m_fCC;
};

struct bhkConstraintBaseSI {
    void* m_pVtable;
    ConstraintDataSI* m_pData;
};

struct FUN_00cc7a40_class : bhkConstraintBaseSI {
    void FUN_00cc7a40(NiStreamSI& kStream);
};

extern int DAT_01268624;

class FUN_00cc7d00_base {
public:
    virtual void unk00();
    ~FUN_00cc7d00_base();
    int unk04;
};

class FUN_00cc7d00 : public FUN_00cc7d00_base {
public:
    virtual ~FUN_00cc7d00();
    void unk08();
};

// @fnv 0x00cc7d00
FUN_00cc7d00::~FUN_00cc7d00()
{
    reinterpret_cast<::ProjectileListener *>((this))->FUN_00c876a0();
    DAT_01268624--;
}

extern int DAT_01268628;

// @fnv 0x00cc7d70
int* __cdecl FUN_00cc7d70()
{
    return &DAT_01268628;
}

// @fnv 0x00cc7d80
int __cdecl FUN_00cc7d80()
{
    return 28;
}

struct CpuOpaque;
extern CpuOpaque DAT_01268f78;
// @fnv 0x00cc7d90
CpuOpaque* __cdecl FUN_00cc7d90()
{
    return &DAT_01268f78;
}

extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
struct S_00cc7dc0_Arg { int unk00; int unk04; };
struct __declspec(novtable) S_00cc7dc0_Root {
    unsigned int unk04;
    unsigned int unk08;
    int unk0c;
    S_00cc7dc0_Root() { reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30(); unk0c = 0; }
    virtual ~S_00cc7dc0_Root();
};
struct S_00cc7dc0_A : S_00cc7dc0_Root {
    S_00cc7dc0_A() { DAT_01268188++; }
    virtual ~S_00cc7dc0_A();
};
struct S_00cc7dc0_B : S_00cc7dc0_A {
    S_00cc7dc0_B() { DAT_01268f74++; }
    virtual ~S_00cc7dc0_B();
};
struct S_00cc7dc0_Init { void SpawnAndAttach(S_00cc7dc0_Arg* a); };
struct FUN_00cc7dc0 : S_00cc7dc0_B {
    FUN_00cc7dc0(S_00cc7dc0_Arg* a);
    void SpawnAndAttach(S_00cc7dc0_Arg* a);
    virtual ~FUN_00cc7dc0();
};
// @fnv 0x00cc7dc0
FUN_00cc7dc0::FUN_00cc7dc0(S_00cc7dc0_Arg* a) {
    reinterpret_cast<::Dispatch_00c89dd0 *>(this)->SpawnAndAttach((int)(a ? (S_00cc7dc0_Arg*)&a->unk04 : 0));
    DAT_01268624++;
}

namespace fnv_00cc83b0 {
extern int DAT_010c9f54;
struct AllocationManager {
};

struct RefBlock {
    void* vtable;
    void* payload;
    unsigned int referenceCount;
    unsigned int flags;
    unsigned int userData;
};
struct RefBlockArgument { RefBlock* block; };
struct FUN_00cc83b0_Class;

struct ScopedAllocationTag {
    unsigned int previous;
    ScopedAllocationTag() : previous(::currentAllocationContext) {
        ::currentAllocationContext = 16;
    }
    ~ScopedAllocationTag() {
        ::currentAllocationContext = previous;
    }
};

struct FUN_00cc83b0_Class {
    void* vtable;
    void* unknown04;
    void* owner;
    void* object;
    void* FUN_00cc83b0(bool* created);
};

// @fnv 0x00cc83b0
void* FUN_00cc83b0_Class::FUN_00cc83b0(bool* created) {
    ScopedAllocationTag allocationTag;
    bool missing = (object == 0);
    *created = missing;
    if (missing) {
        RefBlock* block = static_cast<RefBlock*>(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00cc83b0::AllocationManager *>(&::g_memoryManager))))->FUN_00aa3e40(28));
        void* reference;
        if (block != 0) {
            void** data = &block->payload;
            block->referenceCount = 1;
            block->flags = 0;
            block->userData = 0;
            block->vtable = &DAT_010c9f54;
            *data = 0;
            reference = data;
        } else {
            reference = 0;
        }
        object = reference;
        if (owner != 0) {
            RefBlockArgument header = { reference ? reinterpret_cast<RefBlock*>(static_cast<char*>(reference) - 4) : 0 };
            reinterpret_cast<::FUN_00c89c80_obj *>((this))->CopyFromSource(header.block);
        }
    }
    return object;
}
}  // namespace fnv_00cc83b0

extern int DAT_01268630;
struct FUN_00cc8480 : bhkConstraint {
    ~FUN_00cc8480();
};
// @fnv 0x00cc8480
FUN_00cc8480::~FUN_00cc8480()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    DAT_01268630--;
}

extern int g_unk01268634;

// @fnv 0x00cc84f0
void* __cdecl FUN_00cc84f0()
{
    return &g_unk01268634;
}


struct BCC8770AllocTagScope {
    int m_iSaved;

    BCC8770AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCC8770AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};


class BCC8770CloningProcess;

class BCC8770RefObject {
public:

    BCC8770RefObject();
    virtual ~BCC8770RefObject();

    int unk04;
    int unk08;
};

class BCC8770Shape : public BCC8770RefObject {
public:
    BCC8770Shape() : m_pkShape(0) { ms_uiInstances++; }
    virtual ~BCC8770Shape();

    void* m_pkShape;

    static unsigned int ms_uiInstances;
};

class BCC8770DerivedShape : public BCC8770Shape {
public:
    BCC8770DerivedShape() { ms_uiInstances++; }
    virtual ~BCC8770DerivedShape();

    static unsigned int ms_uiInstances;
};

class BCC8770Source {
public:
    BCC8770DerivedShape* CloneDerivedShape(BCC8770CloningProcess& kCloning);
};

// @fnv 0x00cc8770
BCC8770DerivedShape* BCC8770Source::CloneDerivedShape(BCC8770CloningProcess& kCloning)
{
    BCC8770AllocTagScope kScope(0x10);
    ::FUN_00c876f0();
    BCC8770DerivedShape* pkClone = new BCC8770DerivedShape;
    reinterpret_cast<::Owner89730 *>(this)->FUN_00c89730(pkClone, (::Process89730 *)&(kCloning));
    ::FUN_00c87700();
    return pkClone;
}


struct SerializationMemoryContext {
    int previous;
    SerializationMemoryContext() : previous((*reinterpret_cast<int *>(&::currentAllocationContext))) {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~SerializationMemoryContext() {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous;
    }
};

struct ConstraintSerializationData {
    hkVector4 unk00;
    hkVector4 unk10;
    hkVector4 unk20;
    hkVector4 planeA;
    hkVector4 axis;
    hkVector4 pivot;
    hkVector4 unk60;
    hkVector4 unk70;
    int unk80;
    float minAngle;
    float maxAngle;
};

struct ConstraintSerializer {
    void* m_vtbl;
    ConstraintSerializationData* data;
    void SerializeConstraintData(StrArr* strings);
};

extern const char DAT_010c8388[];
extern const char DAT_010c8378[];
extern const char DAT_010c8368[];
extern const char DAT_010c835c[];
extern const char DAT_010c8350[];

inline void AppendConstraintString(StrArr* strings, char* text)
{
    unsigned int index = strings->m_usElementCount;
    if (index >= strings->m_usSize) {
        strings->SetSize(index + strings->m_usIncrement);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strings))->SetAt(index, text);
}

extern int DAT_0126863c;
struct S_cc8ce0_Base {
    virtual ~S_cc8ce0_Base();
};
struct FUN_00cc8ce0 : S_cc8ce0_Base {
    ~FUN_00cc8ce0();
};
// @fnv 0x00cc8ce0
FUN_00cc8ce0::~FUN_00cc8ce0() {
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    DAT_0126863c--;
}

extern int DAT_01268640;

// @fnv 0x00cc8d50
int* __cdecl FUN_00cc8d50()
{
    return &DAT_01268640;
}

// @fnv 0x00cc8d60
int __cdecl FUN_00cc8d60()
{
    return 44;
}

extern int DAT_01268f84;

// @fnv 0x00cc8d70
int* FUN_00cc8d70()
{
    return &DAT_01268f84;
}

namespace fnv_00cc8dc0 {
extern int g_ctorCountA;
extern int g_ctorCountB;
extern int g_ctorCountD;



struct OwnerBase {
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

};

struct ChainA_cls : public OwnerBase {
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_cls() {
        m_0c = 0;
        g_ctorCountA += 1;
    }
};

struct ChainB_cls : public ChainA_cls {
    virtual void unkB1();
    ChainB_cls() {
        g_ctorCountB += 1;
    }
};

struct SpawnedObject : public ChainB_cls {
    virtual void unkD2();
    SpawnedObject() {
        g_ctorCountD += 1;
    }
};

// Allocates and constructs a new SpawnedObject via its operator new and returns the pointer.
// @fnv 0x00cc8dc0
SpawnedObject* FUN_00cc8dc0() {
    return new SpawnedObject();
}
}  // namespace fnv_00cc8dc0

struct NiBinaryStreamStandIn {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamStandIn* pkThis, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
    template <class T> unsigned int Write(const T* pArray, unsigned int ItemUpdateArray)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pArray, sizeof(T) * ItemUpdateArray, &uiSize, 1);
    }
};

struct NiStreamImpl {
    char pad[0x250];
    NiBinaryStreamStandIn* m_pBackingStream;
};

template <class T> inline void SerializeValue(NiStreamImpl& stream, const T& value)
{
    stream.m_pBackingStream->Write(&value);
}


struct HavokData_cc8 {
    char pad[0x24];
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
};

struct FUN_00cc8f60_cls {
    int unk00;
    HavokData_cc8* m_pUserData;
    char pad08[0x18];
    int m_20;

    void FUN_00cc8f60(NiStreamImpl& stream);
};

// @fnv 0x00cc8f60
void FUN_00cc8f60_cls::FUN_00cc8f60(NiStreamImpl& stream)
{
    HavokData_cc8* pkData = m_pUserData;
    ::FUN_00cf0cf0((::S00cf0cf0_Obj *)&(stream), (::S00cf0cf0_Arr *)(void *)(&m_20));
    SerializeValue(stream, pkData->m_f28);
    SerializeValue(stream, pkData->m_f24);
    SerializeValue(stream, pkData->m_f2c);
    SerializeValue(stream, pkData->m_f30);
    reinterpret_cast<::D53360Owner *>(this)->FUN_00d53360((::D53360Stream &)(stream));
}


class CC90D0MemContext {
public:
    CC90D0MemContext(int aiMemoryContext)
    {
        m_iPrevious = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~CC90D0MemContext() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iPrevious; }

    int m_iPrevious;
};


class CC90D0RefObject {
public:
    CC90D0RefObject();
    virtual ~CC90D0RefObject();


    int unk04;
    int unk08;
};

class CC90D0Level1 : public CC90D0RefObject {
public:
    CC90D0Level1() : m_pPointer(0) { ++ms_uiInstances; }
    virtual ~CC90D0Level1();

    void* m_pPointer;

    static unsigned int ms_uiInstances;
};

class CC90D0Level2 : public CC90D0Level1 {
public:
    CC90D0Level2() { ++ms_uiInstances; }
    virtual ~CC90D0Level2();

    static unsigned int ms_uiInstances;
};

class CC90D0Level3 : public CC90D0Level2 {
public:
    CC90D0Level3() { ++ms_uiInstances; }
    virtual ~CC90D0Level3();

    static unsigned int ms_uiInstances;
};

class CC90D0World {
public:
    void AddObject(CC90D0Level3* pkObject, void* pvInfo);

    CC90D0Level3* CreateAndAddObject(void* pvInfo);
};

// Creates a CC90D0Level3, adds it to the world with pvInfo, and returns it.
// @fnv 0x00cc90d0
CC90D0Level3* CC90D0World::CreateAndAddObject(void* pvInfo)
{
    CC90D0MemContext kContext(0x10);
    FUN_00c876f0();
    CC90D0Level3* pkObject = new CC90D0Level3;
    reinterpret_cast<::bhkListShapeD53 *>(this)->FUN_00d53a80((::NiObjectD53 *)(pkObject), (*(::NiCloningProcessD53 *)(pvInfo)));
    FUN_00c87700();
    return pkObject;
}

namespace fnv_00cc94b0 {
struct SpawnedAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    SpawnedAllocator* m_pAllocator;
};


struct SpawnedScopeOwner;

struct SpawnedScopeGuard {
    SpawnedScopeOwner* m_pSharedOwner;
    SpawnedScopeGuard(SpawnedScopeOwner* owner) : m_pSharedOwner(owner) {}
    ~SpawnedScopeGuard();
};

struct SpawnedScopeBase {
    void Cleanup();
};

struct SpawnedScopeOwner : public SpawnedScopeBase {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void FreeSpawnedStorage();
};

SpawnedScopeGuard::~SpawnedScopeGuard()
{
    m_pSharedOwner->Cleanup();
}

// Frees m_pData through the allocator when m_uCap is not flagged, then resets m_pData and m_uCap to the empty state.
// @fnv 0x00cc94b0
void SpawnedScopeOwner::FreeSpawnedStorage()
{
    SpawnedScopeGuard guard(this);

    AllocHolder* pHolder = static_cast<AllocHolder*>(::FUN_00c85750());
    SpawnedAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uCapacity = m_uCap;
    m_iArrayLength = 0;
    if ((uCapacity & 0x80000000u) == 0) {
        void* pData = m_pData;
        pAllocator->Free(pData, (uCapacity & 0x3fffffffu) * 16);
    }
    m_pData = 0;
    m_uCap = 0x80000000u;
}
}  // namespace fnv_00cc94b0

extern int DAT_01268648;

struct FUN_00cc9640 : bhkConstraint
{
    ~FUN_00cc9640();
};

// @fnv 0x00cc9640
FUN_00cc9640::~FUN_00cc9640()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --DAT_01268648;
}

extern int DAT_010c8b0c;
extern int DAT_01268188;
extern int DAT_01268648;

struct PhysicsAllocator {
};

struct PhysicsReference {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    PhysicsReference();
};

struct PhysicsObject : PhysicsAllocator, PhysicsReference {
    unsigned int m_uiData;

    PhysicsObject() : PhysicsReference()
    {
        unsigned int count = 1;
        m_pVtable = &DAT_0108febc;
        m_uiData = 0;
        DAT_01268188 += count;
        m_pVtable = &DAT_010c8b0c;
        DAT_01268648 += count;
    }
};

// Allocates and constructs a new PhysicsObject via PhysicsAllocator::operator new and returns it.
// @fnv 0x00cc9700
PhysicsObject* __cdecl CreatePhysicsObject()
{
    return new PhysicsObject;
}

// MakeClone for a Havok wrapper: under the world lock, create a new wrapper and copy our data into it.


struct CC9940AllocTagScope {
    int m_iSaved;

    CC9940AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CC9940AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};


extern int g_iCC9940RefObjectCount;
extern int g_iCC9940WrapperCount;

class CC9940Root {
public:
    CC9940Root();
    virtual ~CC9940Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};

class CC9940Holder : public CC9940Root {
public:
    CC9940Holder() : m_pkHavokObject(0) {}
    virtual ~CC9940Holder();
    void* m_pkHavokObject;
};

class CC9940RefObject : public CC9940Holder {
public:
    CC9940RefObject() { ++g_iCC9940RefObjectCount; }
    virtual ~CC9940RefObject();
};

class CC9940Wrapper : public CC9940RefObject {
public:
    CC9940Wrapper() { ++g_iCC9940WrapperCount; }
    virtual ~CC9940Wrapper();

    CC9940Wrapper* FUN_00cc9940(int iCloning);
};

// @fnv 0x00cc9940
CC9940Wrapper* CC9940Wrapper::FUN_00cc9940(int iCloning)
{
    CC9940AllocTagScope kScope(0x10);
    ::FUN_00c876f0();
    CC9940Wrapper* pkClone = new CC9940Wrapper;
    reinterpret_cast<::Owner89730 *>(this)->FUN_00c89730(pkClone, (::Process89730 *)(iCloning));
    ::FUN_00c87700();
    return pkClone;
}

class BCC9B80BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(BCC9B80BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BCC9B80Stream {
public:
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
    unsigned int m_uiFileVersion;
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCC9B80BinaryStream* m_pUnderlyingStream;
};

template <class T>
inline void BCC9B80BinaryStreamLoad(BCC9B80BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void BCC9B80LoadBinary(BCC9B80Stream& kStream, T& value)
{
    BCC9B80BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

struct BCC9B80Vector4 {
    float x;
    float y;
    float z;
    float w;
};

struct BCC9B80ShapeData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BCC9B80Vector4 m_kMin;
    BCC9B80Vector4 m_kMax;
};

class BCC9B80Base {
public:

    int unk00;
    BCC9B80ShapeData* m_pUserData;
};

class FUN_00cc9b80_cls : public BCC9B80Base {
public:
    void FUN_00cc9b80(BCC9B80Stream& kStream);
};

namespace fnv_00cc9bf0 {
struct NiBinaryStreamStandIn {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int (__cdecl* m_pfnWrite)(NiBinaryStreamStandIn* pkThis, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
    template <class T> unsigned int Write(const T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pValue, sizeof(T), &uiSize, 1);
    }
    template <class T> unsigned int Write(const T* pArray, unsigned int ItemUpdateArray)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryWrite(pArray, sizeof(T) * ItemUpdateArray, &uiSize, 1);
    }
};

struct NiStreamImpl {
    char pad[0x250];
    NiBinaryStreamStandIn* m_pBackingStream;
};

template <class T> inline void SerializeValue(NiStreamImpl& stream, const T& value)
{
    stream.m_pBackingStream->Write(&value);
}

struct Vec4_cc9 {
    float x, y, z, w;
};

struct HavokData_cc9 {
    char pad[0x20];
    Vec4_cc9 m_kA;
    Vec4_cc9 m_kB;
};

struct FUN_00cc9bf0_cls {
    int unk00;
    HavokData_cc9* m_pUserData;

    void WriteHavokData(NiStreamImpl& stream);
};

// @fnv 0x00cc9bf0
void FUN_00cc9bf0_cls::WriteHavokData(NiStreamImpl& stream)
{
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((::S_00c8a280_Stream &)(stream));
    HavokData_cc9* pkData = m_pUserData;
    SerializeValue(stream, pkData->m_kA);
    SerializeValue(stream, pkData->m_kB);
}
}  // namespace fnv_00cc9bf0

class CC9C60Base {
public:
    virtual ~CC9C60Base();

};

class FUN_00cc9c60 : public CC9C60Base {
public:
    virtual ~FUN_00cc9c60();

};

struct NiRefObjectStub {
    void IncRefCount();
};

struct BaseObject {
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
    BaseObject(int a, int b);
    virtual ~BaseObject();
};

struct FUN_00cc9d00 : BaseObject {
    NiRefObjectStub* m_pPointer;
    FUN_00cc9d00(int a, int b, NiRefObjectStub* pkObject);
    virtual ~FUN_00cc9d00();
};

// @fnv 0x00cc9d00
FUN_00cc9d00::FUN_00cc9d00(int aiArg1, int aiArg2, NiRefObjectStub* pkObject) : BaseObject(aiArg1, aiArg2) {
    m_pPointer = pkObject;
    if (pkObject)
        reinterpret_cast<::FUN_00c90510_class *>((pkObject))->FUN_00c90510();
}

struct CpuInterface {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void Invoke();
};
struct CpuObject
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
    CpuInterface* target;
    void FUN_00cc9d70();
public:
    unsigned int FUN_00cac910();
};
// @fnv 0x00cc9d70
void CpuObject::FUN_00cc9d70()
{
    target->Invoke();
}

namespace fnv_00cc9d80 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    AudioAllocator* m_pAllocator;
};


struct FUN_00cc9d80_cls {
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;


    FUN_00cc9d80_cls* FUN_00cc9d80(unsigned char acFlags);
};

// Calls FUN_00d54960, then if bit 0 of acFlags is set frees this via the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00cc9d80
FUN_00cc9d80_cls* FUN_00cc9d80_cls::FUN_00cc9d80(unsigned char acFlags)
{
    reinterpret_cast<::FUN_00d54960 *>(this)->FUN_00d54960::~FUN_00d54960();
    if (acFlags & 1) {
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00cc9d80

extern int DAT_01268658;

// @fnv 0x00cc9db0
void* __cdecl FUN_00cc9db0()
{
    return &DAT_01268658;
}

// @fnv 0x00cc9dc0
int __cdecl FUN_00cc9dc0() { return 16; }

struct S_00cc9df0_Val {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_f;
};
struct S_00cc9df0_Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S_00cc9df0_Val* m_kPointA;
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
    S_00cc9df0_Val* m_kPointB;
};
struct S_00cc9df0_Out {
    int unk00;
    int unk04;
    S_00cc9df0_Val* m_v;
    float m_fValue;
};
struct S_00cc9df0_Cls;
inline S_00cc9df0_Val* GetA(S_00cc9df0_Data* d) { return d ? d->m_kPointA : 0; }
inline S_00cc9df0_Val* GetB(S_00cc9df0_Data* d) { return d ? d->m_kPointB : 0; }
struct S_00cc9df0_Cls {
    int unk00;
    int unk04;
    S_00cc9df0_Data* m_iFourthElementInteger;
    void SetRatioFromValues(S_00cc9df0_Out* out);
};
inline S_00cc9df0_Data* GetD(S_00cc9df0_Cls* c) { return c ? c->m_iFourthElementInteger : 0; }
// @fnv 0x00cc9df0
void S_00cc9df0_Cls::SetRatioFromValues(S_00cc9df0_Out* out)
{
    reinterpret_cast<::S_00ca4e10_Cls *>(this)->FUN_00ca4e10((::S_00ca4e10_Out *)(out));
    out->m_v = GetB(GetD(this));
    S_00cc9df0_Data* pData = GetD(this);
    if (pData && pData->m_kPointA) {
        S_00cc9df0_Data* pData2 = GetD(this);
        if (GetB(pData2)) {
            S_00cc9df0_Val* a = GetA(GetD(this));
            S_00cc9df0_Val* b = GetB(GetD(this));
            out->m_fValue = a->m_f / b->m_f;
        }
    }
}

// Apply a scale: multiply the Havok shape's radius by the scale, refresh the shape, then the base handles the rest.

struct CC9F10Scale {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScale;
};

struct CC9F10Shape {
};

struct CC9F10HavokData {
    int unk00;
    int unk04;
    CC9F10Shape* m_pkShape;
    float m_fBoundRadius;
};

class CC9F10Object {
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual CC9F10HavokData* GetHavokData(bool* pbOwned);

    void FUN_00cc9f10(int iFlags, CC9F10Scale* pkScale);
};

// Gets the havok data, multiplies its scale by pkScale->m_fScale, refreshes the shape if present, then calls ApplyBaseScale.
// @fnv 0x00cc9f10
void CC9F10Object::FUN_00cc9f10(int iFlags, CC9F10Scale* pkScale)
{
    bool bIsValid;
    CC9F10HavokData* pkData = GetHavokData(&bIsValid);
    pkData->m_fBoundRadius = pkScale->m_fScale * pkData->m_fBoundRadius;
    if (pkData->m_pkShape)
        reinterpret_cast<::FUN_00c90510_class *>((pkData->m_pkShape))->FUN_00c90510();
    reinterpret_cast<::This *>(this)->FUN_00ca4e50(iFlags, (intptr_t)(pkScale));
}

struct Owner_Target {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};

class FUN_00cca0e0_cls {
public:
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual Owner_Target* v45(unsigned int* p);
    void FUN_00cca0e0(unsigned int param);
};


// Calls FUN_00ca4ec0 with param, gets an Owner_Target via v45, then stores the result of ReadBlobObject into its m_08 field.
// @fnv 0x00cca0e0
void FUN_00cca0e0_cls::FUN_00cca0e0(unsigned int uiValue) {
    unsigned int value = *(volatile unsigned int*)&uiValue;
    reinterpret_cast<::S_00ca4ec0 *>(this)->FUN_00ca4ec0((*(::S_00ca4ec0_Stream *)(value)));
    Owner_Target* o = v45(&uiValue);
    unsigned int local = 0;
    ::fnv_00cf1270::ReadBlobObject((::fnv_00cf1270::BlobStream *)(value), (::fnv_00cf1270::BlobObject **)(unsigned int *)(&local));
    o->m_08 = local;
}


class CCA1B0MemContext {
public:
    CCA1B0MemContext(int aiMemoryContext)
    {
        m_iPrevious = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~CCA1B0MemContext() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iPrevious; }

    int m_iPrevious;
};


class CCA1B0RefObject {
public:
    CCA1B0RefObject();
    virtual ~CCA1B0RefObject();


    int unk04;
    int unk08;
};

class CCA1B0Level1 : public CCA1B0RefObject {
public:
    CCA1B0Level1() : m_pkFirst(0), m_pkSecond(0) { ++ms_uiInstances; }
    virtual ~CCA1B0Level1();

    void* m_pkFirst;
    void* m_pkSecond;

    static unsigned int ms_uiInstances;
};

class CCA1B0Level2 : public CCA1B0Level1 {
public:
    CCA1B0Level2() { ++ms_uiInstances; }
    virtual ~CCA1B0Level2();

    static unsigned int ms_uiInstances;
};

class CCA1B0Level3 : public CCA1B0Level2 {
public:
    CCA1B0Level3() { ++ms_uiInstances; }
    virtual ~CCA1B0Level3();

    static unsigned int ms_uiInstances;
};
// Destructor that calls Shutdown and decrements the static instance counter ms_uiInstances.
// @fnv 0x00cc9c60
FUN_00cc9c60::~FUN_00cc9c60()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --::CCA1B0Level3::ms_uiInstances;
}

class CCA1B0World {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void AddObject(CCA1B0Level3* pkObject, void* pvInfo);

    CCA1B0Level3* FUN_00cca1b0(void* pvInfo);
};

// Creates a CCA1B0Level3, registers it via AddObject with pvInfo, and returns it.
// @fnv 0x00cca1b0
CCA1B0Level3* CCA1B0World::FUN_00cca1b0(void* pvInfo)
{
    CCA1B0MemContext kContext(0x10);
    FUN_00c876f0();
    CCA1B0Level3* pkObject = new CCA1B0Level3;
    AddObject(pkObject, pvInfo);
    FUN_00c87700();
    return pkObject;
}

namespace fnv_00cca4e0 {

struct FUN_00c87c30_owner {
    FUN_00c87c30_owner();
    virtual void unkB0();
    ~FUN_00c87c30_owner();
    unsigned int m_04;
    unsigned int m_08;
};

struct ChainA_cls : public FUN_00c87c30_owner {
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls() {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls {
    virtual void unkB1();
    ChainB_cls() {
        (*reinterpret_cast<int *>(&::CCA1B0Level2::ms_uiInstances)) += 1;
    }
};

struct FUN_00cca4e0 : public ChainB_cls {
    virtual void unkC2();
    FUN_00cca4e0(unsigned int a);
};

// Increments DAT_01268654 and calls FUN_00cca360 with the constructor argument.
// @fnv 0x00cca4e0
FUN_00cca4e0::FUN_00cca4e0(unsigned int uiValue) {
    (*reinterpret_cast<int *>(&::CCA1B0Level3::ms_uiInstances)) += 1;
    reinterpret_cast<::LunaTarget *>(this)->FUN_00cca360((::LunaArgument *)(uiValue));
}
}  // namespace fnv_00cca4e0

extern int DAT_01268664;

// @fnv 0x00cca940
int __cdecl FUN_00cca940() {
    return reinterpret_cast<int>(&DAT_01268664);
}

class CCAA80Object {
public:
    CCAA80Object();


    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

// Allocates and constructs a new CCAA80Object, returning the pointer.
// @fnv 0x00ccaa80
CCAA80Object* __cdecl CreateCCAA80Object()
{
    return new CCAA80Object;
}

extern "C" void _ReadWriteBarrier(void);

struct FUN_00ccab60_arg {
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
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
};

struct FUN_00ccab60_rec {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    unsigned int m1C;
    unsigned int m20;
    unsigned int m24;
    unsigned int m28;
    unsigned int m2C;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};

struct FUN_00ccab60_cls {
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual FUN_00ccab60_rec* GetRec(FUN_00ccab60_arg*& a);
    void ProcessRecord(FUN_00ccab60_arg* a1);
};

// Calls FUN_00c9fbc0 on the argument, then unless m1E5 is 1, byte-swaps the 12 unsigned fields m10 through m3C of the record returned by GetRec.
// @fnv 0x00ccab60
void FUN_00ccab60_cls::ProcessRecord(FUN_00ccab60_arg* a1)
{
    FUN_00ccab60_arg* volatile* pa = &a1;
    FUN_00ccab60_arg* a = *pa;
    reinterpret_cast<::Cls_00c9fbc0 *>(this)->FUN_00c9fbc0((::Arg_00c9fbc0 *)(a));
    if (a->m1E5 != 1) {
        FUN_00ccab60_rec* r = GetRec(a1);
        r->m10 = _byteswap_ulong(r->m10);
        _ReadWriteBarrier();
        r->m14 = _byteswap_ulong(r->m14);
        _ReadWriteBarrier();
        r->m18 = _byteswap_ulong(r->m18);
        _ReadWriteBarrier();
        r->m1C = _byteswap_ulong(r->m1C);
        _ReadWriteBarrier();
        r->m20 = _byteswap_ulong(r->m20);
        _ReadWriteBarrier();
        r->m24 = _byteswap_ulong(r->m24);
        _ReadWriteBarrier();
        r->m28 = _byteswap_ulong(r->m28);
        _ReadWriteBarrier();
        r->m2C = _byteswap_ulong(r->m2C);
        _ReadWriteBarrier();
        r->m30 = _byteswap_ulong(r->m30);
        _ReadWriteBarrier();
        r->m34 = _byteswap_ulong(r->m34);
        _ReadWriteBarrier();
        r->m38 = _byteswap_ulong(r->m38);
        _ReadWriteBarrier();
        r->m3C = _byteswap_ulong(r->m3C);
        _ReadWriteBarrier();
    }
}

struct FUN_00ccabf0_Param {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned char unk01e4;
};

struct FUN_00ccabf0_Data {
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0c;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
    volatile unsigned int unk18;
    volatile unsigned int unk1c;
    volatile unsigned int unk20;
    volatile unsigned int unk24;
    volatile unsigned int unk28;
    volatile unsigned int unk2c;
    volatile unsigned int unk30;
    volatile unsigned int unk34;
    volatile unsigned int unk38;
    volatile unsigned int unk3c;
};

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long value);

struct FUN_00ccabf0_class {
    virtual void FUN_00ccabf0_00();
    virtual void FUN_00ccabf0_01();
    virtual void FUN_00ccabf0_02();
    virtual void FUN_00ccabf0_03();
    virtual void FUN_00ccabf0_04();
    virtual void FUN_00ccabf0_05();
    virtual void FUN_00ccabf0_06();
    virtual void FUN_00ccabf0_07();
    virtual void FUN_00ccabf0_08();
    virtual void FUN_00ccabf0_09();
    virtual void FUN_00ccabf0_0a();
    virtual void FUN_00ccabf0_0b();
    virtual void FUN_00ccabf0_0c();
    virtual void FUN_00ccabf0_0d();
    virtual void FUN_00ccabf0_0e();
    virtual void FUN_00ccabf0_0f();
    virtual void FUN_00ccabf0_10();
    virtual void FUN_00ccabf0_11();
    virtual void FUN_00ccabf0_12();
    virtual void FUN_00ccabf0_13();
    virtual void FUN_00ccabf0_14();
    virtual void FUN_00ccabf0_15();
    virtual void FUN_00ccabf0_16();
    virtual void FUN_00ccabf0_17();
    virtual void FUN_00ccabf0_18();
    virtual void FUN_00ccabf0_19();
    virtual void FUN_00ccabf0_1a();
    virtual void FUN_00ccabf0_1b();
    virtual void FUN_00ccabf0_1c();
    virtual void FUN_00ccabf0_1d();
    virtual void FUN_00ccabf0_1e();
    virtual void FUN_00ccabf0_1f();
    virtual void FUN_00ccabf0_20();
    virtual void FUN_00ccabf0_21();
    virtual void FUN_00ccabf0_22();
    virtual void FUN_00ccabf0_23();
    virtual void FUN_00ccabf0_24();
    virtual void FUN_00ccabf0_25();
    virtual void FUN_00ccabf0_26();
    virtual void FUN_00ccabf0_27();
    virtual void FUN_00ccabf0_28();
    virtual void FUN_00ccabf0_29();
    virtual void FUN_00ccabf0_2a();
    virtual void FUN_00ccabf0_2b();
    virtual void FUN_00ccabf0_2c();

    virtual FUN_00ccabf0_Data* FUN_00ccabf0_45(unsigned char* value);

    void FUN_00ccabf0(FUN_00ccabf0_Param* param);
};

// @fnv 0x00ccabf0
void FUN_00ccabf0_class::FUN_00ccabf0(FUN_00ccabf0_Param* param)
{
    unsigned char local;
    FUN_00ccabf0_Data* data = this->FUN_00ccabf0_45(&local);

    if (param->unk01e4 != 1) {
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
        data->unk18 = _byteswap_ulong(data->unk18);
        data->unk1c = _byteswap_ulong(data->unk1c);
        data->unk20 = _byteswap_ulong(data->unk20);
        data->unk24 = _byteswap_ulong(data->unk24);
        data->unk28 = _byteswap_ulong(data->unk28);
        data->unk2c = _byteswap_ulong(data->unk2c);
        data->unk30 = _byteswap_ulong(data->unk30);
        data->unk34 = _byteswap_ulong(data->unk34);
        data->unk38 = _byteswap_ulong(data->unk38);
        data->unk3c = _byteswap_ulong(data->unk3c);
    }

    reinterpret_cast<::C9FC00Object *>((this))->FUN_00c9fc00((*(::C9FC00Stream *)(param)));

    if (param->unk01e4 != 1) {
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
        data->unk18 = _byteswap_ulong(data->unk18);
        data->unk1c = _byteswap_ulong(data->unk1c);
        data->unk20 = _byteswap_ulong(data->unk20);
        data->unk24 = _byteswap_ulong(data->unk24);
        data->unk28 = _byteswap_ulong(data->unk28);
        data->unk2c = _byteswap_ulong(data->unk2c);
        data->unk30 = _byteswap_ulong(data->unk30);
        data->unk34 = _byteswap_ulong(data->unk34);
        data->unk38 = _byteswap_ulong(data->unk38);
        data->unk3c = _byteswap_ulong(data->unk3c);
    }
}

namespace fnv_00ccacf0 {
struct S_00ccacf0_Tls {
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
    int ctx;
};
__declspec(thread) S_00ccacf0_Tls DAT_tls;

struct S_00ccacf0_Ctx {
    int saved;
    __forceinline S_00ccacf0_Ctx(int c) { saved = (*reinterpret_cast<::fnv_00ccacf0::S_00ccacf0_Tls *>(&::g_tlsBlock)).ctx; (*reinterpret_cast<::fnv_00ccacf0::S_00ccacf0_Tls *>(&::g_tlsBlock)).ctx = c; }
    __forceinline ~S_00ccacf0_Ctx() { (*reinterpret_cast<::fnv_00ccacf0::S_00ccacf0_Tls *>(&::g_tlsBlock)).ctx = saved; }
};



struct S_00ccacf0_Obj {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    S_00ccacf0_Obj();
};

struct S_00ccacf0_Owner {
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
    virtual void vfn_30();
    virtual void vfn_c4(S_00ccacf0_Obj* p, int a);
    S_00ccacf0_Obj* FUN_00ccacf0(int a);
};

// Sets the TLS context to 0x10, allocates a new S_00ccacf0_Obj, passes it with a to vfn_c4, and returns the object.
// @fnv 0x00ccacf0
S_00ccacf0_Obj* S_00ccacf0_Owner::FUN_00ccacf0(int a)
{
    S_00ccacf0_Ctx guard(0x10);
    ::FUN_00c876f0();
    S_00ccacf0_Obj* p = new S_00ccacf0_Obj;
    vfn_c4(p, a);
    ::FUN_00c87700();
    return p;
}
}  // namespace fnv_00ccacf0

namespace fnv_00ccae90 {
struct FUN_00ccae90_Object {
    unsigned int m_type;
    unsigned int m_sReferenceCount;
    unsigned int m_flags;
    void* m_resource;
    void ReleaseResource(char release);
};
struct ResourceManager {
    void FUN_00aa4060(void* resource);
};
// @fnv 0x00ccae90
void FUN_00ccae90_Object::ReleaseResource(char release) {
    unsigned int previousContext = ::currentAllocationContext;
    ::currentAllocationContext = 0x10;
    if (release) {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ccae90::ResourceManager *>(&::g_memoryManager))))->FUN_00aa4060(m_resource);
        m_resource = 0;
    }
    ::currentAllocationContext = previousContext;
}
}  // namespace fnv_00ccae90


struct BCCB080AllocTagScope {
    int m_iSaved;

    BCCB080AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCCB080AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class BCCB080StringArray {
public:
    virtual ~BCCB080StringArray();
    void SetSize(unsigned int uiMaxSize);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement) { return SetAtGrow(m_usSize, pcElement); }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcCCB080Name;


class FUN_00ccb080_cls {
public:
    void AddNameToArray(BCCB080StringArray* pkArray);
};

// Sets an allocation tag, calls FUN_00c9fc50 on the array, then appends the string returned by FUN_00a7d330(g_pcCCB080Name).
// @fnv 0x00ccb080
void FUN_00ccb080_cls::AddNameToArray(BCCB080StringArray* pkArray)
{
    BCCB080AllocTagScope kScope(0x10);
    reinterpret_cast<::SphereShape *>(this)->FUN_00c9fc50((::ViewerStringArray *)(pkArray));
    char* pcName = FUN_00a7d330(g_pcCCB080Name);
    pkArray->Add(pcName);
}

extern int DAT_01268670;
// @fnv 0x00ccb130
void* __cdecl FUN_00ccb130() {
    return &DAT_01268670;
}

// @fnv 0x00ccb140
int __cdecl FUN_00ccb140()
{
    return 64;
}

extern int g_unk01268f90;

// @fnv 0x00ccb150
void* FUN_00ccb150()
{
    return &g_unk01268f90;
}

extern int DAT_010ca5c4;
extern int DAT_010ca4dc;

struct AllocationBase {
};

struct S_00c87c30_Base {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    S_00c87c30_Base();
};

struct TargetObject : AllocationBase, S_00c87c30_Base {
    TargetObject() : S_00c87c30_Base() {
        m_pVtable = &DAT_01030bf4;
        unsigned int count = 1;
        m_uiData1 = 0;
        m_uiData2 = 0;
        DAT_012680f8 += count;
        m_pVtable = &DAT_010ca5c4;
        DAT_01268f8c += count;
        m_pVtable = &DAT_010ca4dc;
        DAT_0126866c += count;
    }
};

// Allocates and constructs a TargetObject, returning the new instance.
// @fnv 0x00ccb200
TargetObject* __cdecl CreateTargetObject() {
    return new TargetObject();
}

struct FUN_00ccb2b0_Param {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_f10;
};

struct FUN_00ccb2b0_Obj {
    void** m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3c;
};

class FUN_00ccb2b0_cls {
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual FUN_00ccb2b0_Obj* GetScale(unsigned char* flag);
    void FUN_00ccb2b0(int a1, FUN_00ccb2b0_Param* p2);
};

// Gets the scale object, multiplies its eight float fields by p2->m_f10 when it is not 1.0, then calls FUN_00c84df0.
// @fnv 0x00ccb2b0
void FUN_00ccb2b0_cls::FUN_00ccb2b0(int aiArg, FUN_00ccb2b0_Param* pParam)
{
    unsigned char flag;
    FUN_00ccb2b0_Obj* obj = this->GetScale(&flag);
    float t = pParam->m_f10;
    if (t != 1.0f) {
        obj->m_f20 *= t;
        obj->m_f24 *= t;
        obj->m_f28 *= t;
        obj->m_f2c *= t;
        obj->m_f30 *= t;
        obj->m_f34 *= t;
        obj->m_f38 *= t;
        obj->m_f3c *= t;
    }
    reinterpret_cast<::FUN_00c84df0_cls *>((this))->FUN_00c84df0((::FUN_00c84df0_cls *)(aiArg), (::FUN_00c84df0_cls *)(pParam));
}

inline void CCB350Swap(unsigned long& ulValue) { ulValue = _byteswap_ulong(ulValue); }

struct CCB350Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_aulValues[12];
};

class CCB350Stream {
public:
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
    char unk1E4;
    char m_cLittleEndian;
};

class CCB350Base {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual CCB350Data* GetData(unsigned int* puiSize);

};

class CCB350Object : public CCB350Base {
public:
    void FUN_00ccb350(CCB350Stream* pkStream);
};

// Loads the base data from the stream, then if the stream is not little-endian byte-swaps the first twelve values of the retrieved data block.
// @fnv 0x00ccb350
void CCB350Object::FUN_00ccb350(CCB350Stream* pkStream)
{
    reinterpret_cast<::FUN_00c84d00_cls *>(this)->FUN_00c84d00((::FUN_00c84d00_obj *)(pkStream));
    if (pkStream->m_cLittleEndian != 1) {
        unsigned int uiSize;
        CCB350Data* pkData = GetData(&uiSize);
        CCB350Swap(pkData->m_aulValues[0]);
        CCB350Swap(pkData->m_aulValues[1]);
        CCB350Swap(pkData->m_aulValues[2]);
        CCB350Swap(pkData->m_aulValues[3]);
        CCB350Swap(pkData->m_aulValues[4]);
        CCB350Swap(pkData->m_aulValues[5]);
        CCB350Swap(pkData->m_aulValues[6]);
        CCB350Swap(pkData->m_aulValues[7]);
        CCB350Swap(pkData->m_aulValues[8]);
        CCB350Swap(pkData->m_aulValues[9]);
        CCB350Swap(pkData->m_aulValues[10]);
        CCB350Swap(pkData->m_aulValues[11]);
    }
}

struct FUN_00ccb3e0_Data {
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0C;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
    volatile unsigned int unk18;
    volatile unsigned int unk1C;
    volatile unsigned int unk20;
    volatile unsigned int unk24;
    volatile unsigned int unk28;
    volatile unsigned int unk2C;
    volatile unsigned int unk30;
    volatile unsigned int unk34;
    volatile unsigned int unk38;
    volatile unsigned int unk3C;
};

struct FUN_00ccb3e0_Class {
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
    virtual void vf20();
    virtual void vf21();
    virtual void FUN_00ccb3e0(unsigned char* arg);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual FUN_00ccb3e0_Data* FUN_00ccb730(unsigned char* value);
};

// @fnv 0x00ccb3e0
void FUN_00ccb3e0_Class::FUN_00ccb3e0(unsigned char* arg)
{
    unsigned char value;
    FUN_00ccb3e0_Data* data = FUN_00ccb730(&value);

    if (arg[0x1e4] != 1)
    {
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
        data->unk18 = _byteswap_ulong(data->unk18);
        data->unk1C = _byteswap_ulong(data->unk1C);
        data->unk20 = _byteswap_ulong(data->unk20);
        data->unk24 = _byteswap_ulong(data->unk24);
        data->unk28 = _byteswap_ulong(data->unk28);
        data->unk2C = _byteswap_ulong(data->unk2C);
        data->unk30 = _byteswap_ulong(data->unk30);
        data->unk34 = _byteswap_ulong(data->unk34);
        data->unk38 = _byteswap_ulong(data->unk38);
        data->unk3C = _byteswap_ulong(data->unk3C);
    }

    reinterpret_cast<::FUN_00c84d50_cls *>(this)->FUN_00c84d50(arg);

    if (arg[0x1e4] != 1)
    {
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
        data->unk18 = _byteswap_ulong(data->unk18);
        data->unk1C = _byteswap_ulong(data->unk1C);
        data->unk20 = _byteswap_ulong(data->unk20);
        data->unk24 = _byteswap_ulong(data->unk24);
        data->unk28 = _byteswap_ulong(data->unk28);
        data->unk2C = _byteswap_ulong(data->unk2C);
        data->unk30 = _byteswap_ulong(data->unk30);
        data->unk34 = _byteswap_ulong(data->unk34);
        data->unk38 = _byteswap_ulong(data->unk38);
        data->unk3C = _byteswap_ulong(data->unk3C);
    }
}

namespace fnv_00ccb4e0 {
struct TlsBlock_t
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = (*reinterpret_cast<::fnv_00ccb4e0::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00ccb4e0::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        (*reinterpret_cast<::fnv_00ccb4e0::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};



struct SpawnRoot_cls
{
    virtual void v_root();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    SpawnRoot_cls();
};

struct SpawnA_cls : SpawnRoot_cls
{
    virtual void v_a0();
    SpawnA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct SpawnB_cls : SpawnA_cls
{
    virtual void v_b0();
    SpawnB_cls()
    {
        DAT_01268f8c += 1;
    }
};

struct SpawnC_cls : SpawnB_cls
{
    virtual void v_c0();
    SpawnC_cls()
    {
        DAT_0126866c += 1;
    }
};

struct FUN_00ccb4e0_cls
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void Dispatch(SpawnC_cls* obj, unsigned int param);
    SpawnC_cls* CreateSpawnC(unsigned int param);
};

// Sets up a TLS guard, allocates a SpawnC_cls, dispatches it with param, and returns the new object.
// @fnv 0x00ccb4e0
SpawnC_cls* FUN_00ccb4e0_cls::CreateSpawnC(unsigned int param)
{
    TlsGuard_t guard;
    ::FUN_00c876f0();
    SpawnC_cls* o = new SpawnC_cls;
    Dispatch(o, param);
    ::FUN_00c87700();
    return o;
}
}  // namespace fnv_00ccb4e0

typedef unsigned int CCB730size_t;

struct CCB730MemoryManager {
    void* Allocate(unsigned int uiSize);
};


struct CCB730AllocTagScope {
    int m_iSaved;

    CCB730AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CCB730AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

inline void* CCB730AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::CCB730MemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(unsigned int)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}

struct CCB730Child
{
    CCB730Child() throw()
        : m_pkOwnerManager(0), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f), m_f20(0.0f), m_f24(0.0f),
          m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {}

    void* m_pkOwnerManager;
    int unk04;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

};

struct CCB730Owner {
    int unk00;
    int unk04;
    void* m_pParentNode;
    CCB730Child* m_pkChild;

    CCB730Child* FUN_00ccb730(bool* pbCreated);
};

// @fnv 0x00ccb730
CCB730Child* CCB730Owner::FUN_00ccb730(bool* pbCreated)
{
    CCB730AllocTagScope kScope(0x10);
    *pbCreated = (m_pkChild == 0);
    if (*pbCreated) {
        m_pkChild = new (CCB730AlignedAlloc(0x50)) CCB730Child();
        if (m_pParentNode)
            reinterpret_cast<::fnv_00ccb1b0::FUN_00ccb1b0_class *>(this)->FUN_00ccb1b0(m_pkChild);
    }
    return m_pkChild;
}

extern int DAT_01268684;

// @fnv 0x00ccb990
void* __cdecl FUN_00ccb990()
{
    return &DAT_01268684;
}



struct FunObjBase_b9645 {
    FunObjBase_b9645();
    virtual void unk00();
    unsigned int m_04;
};

struct FunObj_b9645 : public FunObjBase_b9645 {
    virtual void unk10();
    unsigned int m_08;
    unsigned int m_0c;
    FunObj_b9645() {
        m_08 = 0;
        m_0c = 0;
    }
};

// Allocates and constructs a new FunObj_b9645, returning the new object.
// @fnv 0x00ccb9a0
FunObj_b9645* CreateFunObj() {
    return new FunObj_b9645();
}

// Decompilation candidate for FUN_00ccba30 (0x00ccba30, 32 bytes).
//
// Shape: a member function that (1) forwards its single argument to a virtual
// slot of an object held at offset 0x14 of itself and (2) hands the same
// argument to its own member helper FUN_00aa0ad0.

struct TargetObj
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v15(NiStream* stream);
};

struct NiStream;
struct HC1Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    TargetObj* m_pEntryObject;
    void FUN_00ccba30(NiStream* stream);
public:
    void FUN_00ca4f40(::NiStream *);
};

// @fnv 0x00ccba30
void HC1Base::FUN_00ccba30(NiStream* stream)
{
    m_pEntryObject->v15(stream);
    ::FUN_00aa0ad0();
}

struct FUN_00ccba50_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_14;
    char Equals(FUN_00ccba50_cls* p);
};

// @fnv 0x00ccba50
char FUN_00ccba50_cls::Equals(FUN_00ccba50_cls* apOther)
{
    char r = ((char)(reinterpret_cast<::FUN_00c84dc0_cls *>(this)->FUN_00c84dc0((::FUN_00c84dc0_param *)(apOther))));
    if (r)
        r = (m_14 == apOther->m_14);
    return r;
}

// GetValueForArg: thiscall, 37 bytes, 1 stack argument.
// Returns 0x24 when the argument is -1, otherwise it asks the object held in
// the member pointer at this+8 for a record and returns that record's +4 field.
struct FUN_00d55530_result {
    int m_00;
    int m_04;
};

struct FUN_00d55530_cls {
};

struct FUN_00ccba70_cls {
    int unk00;
    int unk04;
    FUN_00d55530_cls* m_08;
    int GetValueForArg(int arg);
};

// Returns 0x24 when arg is -1, otherwise returns m_04 of the result of FUN_00d55530(arg) on m_08 (or null if this is null).
// @fnv 0x00ccba70
int FUN_00ccba70_cls::GetValueForArg(int arg)
{
    int result = 0x24;
    FUN_00d55530_cls* pTarget = this ? m_08 : (FUN_00d55530_cls*)0;
    if (arg != -1) {
        result = ((::FUN_00d55530_result *)(reinterpret_cast<::SpawnedOwnerQ *>((pTarget))->FUN_00d55530(arg)))->m_04;
    }
    return result;
}


struct RefObjCC {
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T>
struct NiPtrCC {
    T* m_pObject;
    NiPtrCC(T* p = 0) : m_pObject(p) { if (m_pObject) m_pObject->IncRefCount(); }
    ~NiPtrCC();
    NiPtrCC& operator=(T* pObject)
    {
        if (m_pObject != pObject) {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct FUN_00ccbaa0 {
    void* m_p0;
    NiPtrCC<RefObjCC> m_sp;
    FUN_00ccbaa0(RefObjCC* p);
};

// Constructs the holder with a null pointer and stores the given RefObjCC in the smart pointer, incrementing its reference count.
// @fnv 0x00ccbaa0
FUN_00ccbaa0::FUN_00ccbaa0(RefObjCC* apObject)
    : m_p0(0), m_sp(0)
{
    m_sp = apObject;
}

extern int DAT_0126867c;

// @fnv 0x00ccbb30
int __cdecl FUN_00ccbb30() {
    return reinterpret_cast<int>(&DAT_0126867c);
}

// @fnv 0x00ccbb40
int __cdecl FUN_00ccbb40()
{
    return 0x20;
}

namespace fnv_00ccbb50 {
struct TlsBlock_t
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};



struct TlsFlagGuard
{
    int m_saved;
    TlsFlagGuard()
    {
        m_saved = (*reinterpret_cast<::fnv_00ccbb50::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00ccbb50::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        (*reinterpret_cast<::fnv_00ccbb50::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};

struct FUN_00ccbb50_pool
{
    void FUN_00aa4060(int p);
};

class FUN_00ccbb50_cls
{
public:
    unsigned int unk00;
    char* m_04;
    unsigned int unk08;
    char* m_0c;
    char* m_10;
    void FUN_00ccbb50();
};

// @fnv 0x00ccbb50
void FUN_00ccbb50_cls::FUN_00ccbb50()
{
    TlsFlagGuard guard;
    if (m_04 != 0)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ccbb50::FUN_00ccbb50_pool *>(&::g_memoryManager))))->FUN_00aa4060((void *)((int)m_04));
    }
    if (m_0c != 0)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ccbb50::FUN_00ccbb50_pool *>(&::g_memoryManager))))->FUN_00aa4060((void *)((int)m_0c));
    }
    char* p = m_10;
    if (p != 0)
    {
        unsigned char len = (unsigned char)p[-1];
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ccbb50::FUN_00ccbb50_pool *>(&::g_memoryManager))))->FUN_00aa4060((void *)((int)(p - len)));
    }
}
}  // namespace fnv_00ccbb50

namespace fnv_00ccc2f0 {

struct MemContextGuard {
    unsigned int uiOld;
    MemContextGuard(unsigned int uiNew) {
        uiOld = ::currentAllocationContext;
        ::currentAllocationContext = uiNew;
    }
    ~MemContextGuard() { ::currentAllocationContext = uiOld; }
};

struct MemMgrStub {
    void* Allocate(unsigned int auiSize);
};

struct StreamStub {
    int unk00;
    int iPos;
    int (__cdecl* pfnWrite)(StreamStub*, void*, unsigned int, int, int);
};

struct SaveCtx {
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
    StreamStub* pStream;
};

struct Saveable {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4();
    virtual unsigned int GetSaveSize();

    unsigned int FUN_00ccc2f0(SaveCtx* apCtx);
};

// Allocates a buffer of GetSaveSize() bytes, writes it to apCtx->pStream, advances the stream position, frees the buffer and returns the size.
// @fnv 0x00ccc2f0
unsigned int Saveable::FUN_00ccc2f0(SaveCtx* apCtx) {
    MemContextGuard kGuard(0x10);
    unsigned int uiSize = GetSaveSize();
    void* pBuffer = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00ccc2f0::MemMgrStub *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize);
    StreamStub* pStream = apCtx->pStream;
    pStream->iPos += pStream->pfnWrite(pStream, pBuffer, uiSize, 0, 0);
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ccc2f0::MemMgrStub *>(&::g_memoryManager))))->FUN_00aa4060(pBuffer);
    return uiSize;
}
}  // namespace fnv_00ccc2f0

struct FNVRefObj;
struct FNVRefVTable {
    void (*m_method00)(FNVRefObj*);
    void (*m_release)(FNVRefObj*);
};
struct FNVRefObj {
    FNVRefVTable* m_ppVirtualMethodTable;
    volatile long m_refcount;
};
struct FNVHolder {
    void* m_ppVirtualMethodTable;
    FNVRefObj* m_object;
};
struct FNVParam {
};
struct FNVTarget {
    void* m_ppVirtualMethodTable;
    void AssignRefObject(FNVParam*);
};
typedef FNVHolder* (*FNVQuery)(FNVTarget*, bool*);

// Queries a holder via vtable slot 45, swaps its m_object to the param's ref object with refcount updates, then calls FUN_00c84cc0.
// @fnv 0x00ccc3b0
void FNVTarget::AssignRefObject(FNVParam* param)
{
    bool initialized;
    FNVHolder* holder = reinterpret_cast<FNVQuery*>(m_ppVirtualMethodTable)[45](this, &initialized);
    FNVRefObj* object = ((::FNVRefObj *)(reinterpret_cast<::NiStream *>((param))->GetLoadedObject()));
    FNVRefObj* oldObject = holder->m_object;
    if (oldObject != object) {
        if (oldObject && InterlockedDecrement(&oldObject->m_refcount) == 0)
            oldObject->m_ppVirtualMethodTable->m_release(oldObject);
        holder->m_object = object;
        if (object)
            InterlockedIncrement(&object->m_refcount);
    }
    ::FUN_00c84cc0((int *)this, (unsigned int)(param));
}

struct S_00ccc620_BinStream {
    int unk00;
    unsigned int m_uiStreamFlags;
    int unk08;
    unsigned int (__cdecl *m_pfnWrite)(S_00ccc620_BinStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
struct S_00ccc620_Stream {
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
    S_00ccc620_BinStream* unk250;
};
template <class T> inline void WriteBinaryArray(S_00ccc620_BinStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    unsigned int uiBytes = uiNumEls * sizeof(T);
    kStream.Write(pkValue, uiBytes, &uiSize, 1);
}
struct S_00ccc620_Pair {
    int a;
    int b;
};
struct S_00ccc620_Obj {
    unsigned int unk00;
    float* unk04;
    unsigned int unk08;
    unsigned short* unk0c;
    S_00ccc620_Pair* unk10;
    void FUN_00ccc620(S_00ccc620_Stream& kStream);
};
// Writes unk00, the unk04 array (unk00*3 elements), unk08, the unk0c array (unk08*3 elements), and unk10->a and unk10->b to the stream.
// @fnv 0x00ccc620
void S_00ccc620_Obj::FUN_00ccc620(S_00ccc620_Stream& kStream)
{
    WriteBinaryArray(*kStream.unk250, &unk00, 1);
    WriteBinaryArray(*kStream.unk250, unk04, unk00 * 3);
    WriteBinaryArray(*kStream.unk250, &unk08, 1);
    WriteBinaryArray(*kStream.unk250, unk0c, unk08 * 3);
    WriteBinaryArray(*kStream.unk250, &unk10->a, 1);
    WriteBinaryArray(*kStream.unk250, &unk10->b, 1);
}

class CCCF00BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(CCCF00BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl *m_pfnWrite)(CCCF00BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count) {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n) {
        unsigned int size = n;
        return BinaryWrite(p, n, &size, 1);
    }
};

class CCCF00Stream {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(void* pvObject);

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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    CCCF00BinaryStream* m_pBackingStream;
};

struct CCCF00Vector4 {
    float x;
    float y;
    float z;
    float w;
};

struct CCCF00Entity {
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
    CCCF00Vector4 m_kValue;
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
    float m_fMass;
};

class CCCF00RigidBody {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void Unlock(bool bLocked);
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void Lock(bool& bLocked);

    int unk04;
    CCCF00Entity* m_pkEntity;
    int unk0C;
    int unk10;
    void* m_pvLinked;

    void FUN_00cccf00(CCCF00Stream& kStream);
};

// SaveBinary
// Locks the rigid body, writes the entity's mass and vector to the stream, saves the linked ID, then unlocks.
// @fnv 0x00cccf00
void CCCF00RigidBody::FUN_00cccf00(CCCF00Stream& kStream) {
    bool bLocked;
    Lock(bLocked);
    CCCF00Entity* pkEntity = m_pkEntity;
    reinterpret_cast<::FUN_00c84d50_cls *>(this)->FUN_00c84d50((void *)&(kStream));
    float fMass = pkEntity->m_fMass;
    kStream.m_pBackingStream->Write(&fMass, sizeof(fMass));
    kStream.m_pBackingStream->Write(&pkEntity->m_kValue, sizeof(CCCF00Vector4));
    kStream.SaveLinkID(m_pvLinked);
    Unlock(bLocked);
}

// FUN_00ccd0f0 : a one-line function - getter
extern int g_target_00ccd0f0;
// @fnv 0x00ccd0f0
void* FUN_00ccd0f0() { return &g_target_00ccd0f0; }

namespace fnv_00ccd1d0 {

struct ccd1_inner_t {
};

struct ccd1_stage_t {
};

struct FUN_00ccd1d0_cls {
    void* unk00;
    void* unk04;
    ccd1_inner_t* m_pInner;
    void WriteLimitedHingeData(void* out);
};

// @fnv 0x00ccd1d0
void FUN_00ccd1d0_cls::WriteLimitedHingeData(void* out) {
    ::FUN_00c9fb70((::MyObj *)(((ccd1_stage_t*)this)), 0, (::OutS *)(out));
    char* o = (char*)out;
    char* a;
    if (this != 0 && m_pInner != 0) {
        a = (char*)m_pInner + 0x20;
    } else {
        a = (char*)&(*reinterpret_cast<int *>(&::DAT_01267e30));
    }
    reinterpret_cast<::S004b4db0_Quaternion *>((((bhkLimitedHingeVector*)(o + 0x10))))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((const float*)a)));

    char* b;
    if (this != 0 && m_pInner != 0) {
        b = (char*)m_pInner + 0x30;
    } else {
        b = (char*)&(*reinterpret_cast<int *>(&::DAT_01267e30));
    }
    reinterpret_cast<::S004b4db0_Quaternion *>((((bhkLimitedHingeVector*)(o + 0x20))))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)((const float*)b)));

    volatile float r;
    if (this != 0 && m_pInner != 0) {
        r = reinterpret_cast<::hkpCylinderShapeGetCylRadius *>((m_pInner))->FUN_00d571a0();
    } else {
        r = 0.0f;
    }
    *(float*)(o + 0x30) = r;
}
}  // namespace fnv_00ccd1d0


struct FUN_00ccd100 {
    void* vtable;
    unsigned int refCount;
    unsigned int flags;
    unsigned int dataA;
    unsigned int dataB;
    FUN_00ccd100();
};
// Allocates and constructs a new FUN_00ccd100 object, returning its pointer.
// @fnv 0x00ccd250
FUN_00ccd100* __cdecl FUN_00ccd250() {
    return new FUN_00ccd100;
}

extern "C" void _ReadWriteBarrier(void);

struct S_00ccd330_Arg {
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
    unsigned char unk1E4;
    unsigned char m1E5;
};

struct S_00ccd330_Data {
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
};

struct S_00ccd330_Foo {
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual S_00ccd330_Data* FUN_v45(void** value);
    S_00ccd330_Data* m_pData;
    void FUN_00ccd330(S_00ccd330_Arg* a1);
};

// Calls FUN_00c9fbc0 on a1, returns early if m1E5 is 1, otherwise byte-swaps the 32-bit fields unk10 through unk2C of the data returned by FUN_v45.
// @fnv 0x00ccd330
void S_00ccd330_Foo::FUN_00ccd330(S_00ccd330_Arg* apArg)
{
    S_00ccd330_Arg* volatile* pa = &apArg;
    S_00ccd330_Arg* a = *pa;
    reinterpret_cast<::Cls_00c9fbc0 *>(this)->FUN_00c9fbc0((::Arg_00c9fbc0 *)(a));
    if (a->m1E5 == 1)
        return;
    S_00ccd330_Data* d = FUN_v45((void**)&apArg);
    d->unk10 = _byteswap_ulong(d->unk10);
    _ReadWriteBarrier();
    d->unk14 = _byteswap_ulong(d->unk14);
    _ReadWriteBarrier();
    d->unk18 = _byteswap_ulong(d->unk18);
    _ReadWriteBarrier();
    d->unk1C = _byteswap_ulong(d->unk1C);
    _ReadWriteBarrier();
    d->unk20 = _byteswap_ulong(d->unk20);
    _ReadWriteBarrier();
    d->unk24 = _byteswap_ulong(d->unk24);
    _ReadWriteBarrier();
    d->unk28 = _byteswap_ulong(d->unk28);
    _ReadWriteBarrier();
    d->unk2C = _byteswap_ulong(d->unk2C);
    _ReadWriteBarrier();
}

struct FUN_00ccd3a0_arg
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
    unsigned char m_1e4;
};

struct FUN_00ccd3a0_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void FUN_00ccd3a0(FUN_00ccd3a0_arg* a1);
};

// If the argument's m_1e4 is not 1, byte-swaps p[4] through p[11] before and after calling FUN_00c9fc00.
// @fnv 0x00ccd3a0
void FUN_00ccd3a0_cls::FUN_00ccd3a0(FUN_00ccd3a0_arg* a1)
{
    unsigned int tmp;
    volatile unsigned int* p = vGet((unsigned char*)&tmp + 3);
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
    }
    reinterpret_cast<::C9FC00Object *>(this)->FUN_00c9fc00((*(::C9FC00Stream *)(a1)));
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
    }
}

namespace fnv_00ccd520 {

struct MemoryHeap {
};

struct TransformRecord {
    unsigned int m_flags;
    float m_scalar;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    float m_translationX;
    float m_translationY;
    float m_translationZ;
    float m_translationW;
    volatile float m_rotationW;
    volatile float m_rotationX;
    volatile float m_rotationY;
    volatile float m_rotationZ;
    float m_other;
};

struct MemoryContextScope {
    int previousContext;
    MemoryContextScope() {
        previousContext = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }
    ~MemoryContextScope() {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = previousContext;
    }
};

struct TransformHolder {
    void* m_ppVirtualMethodTable;
    unsigned int m_iObjectReferenceCount;
    int m_enableCallback;
    TransformRecord* m_record;
    TransformRecord* GetOrCreateTransform(bool* created);
};

// Returns m_record, allocating and initialising a TransformRecord when it is null and invoking the callback if enabled.
// @fnv 0x00ccd520
TransformRecord* TransformHolder::GetOrCreateTransform(bool* created) {
    MemoryContextScope m_uiMemoryContext;
    bool isNew = m_record == 0;
    *created = isNew;
    if (isNew) {
        char* allocation = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00ccd520::MemoryHeap *>(&::g_memoryManager))))->FUN_00aa3e40(0x50); unsigned char delta=(unsigned char)(16 - (unsigned char)((unsigned int)allocation & 0xf)); allocation[delta - 1] = delta; allocation += delta; TransformRecord* record=(TransformRecord*)allocation;
        record->m_flags = 0;
        record->m_scalar = ::DAT_010c72bc;
        record->m_translationX = 0.0f;
        record->m_translationY = 0.0f;
        record->m_translationZ = 0.0f;
        record->m_translationW = 0.0f;
        record->m_rotationW = 0.0f;
        record->m_rotationX = 0.0f;
        record->m_rotationY = 0.0f;
        record->m_rotationZ = 0.0f;
        record->m_other = 0.0f;
        record->m_rotationW = 1.0f;
        record->m_rotationX = 0.0f;
        record->m_rotationY = 0.0f;
        record->m_rotationZ = 0.0f;
        m_record = record;
        if (m_enableCallback) {
            reinterpret_cast<::fnv_00ccd1d0::FUN_00ccd1d0_cls *>(this)->WriteLimitedHingeData(record);
        }
    }
    return m_record;
}
}  // namespace fnv_00ccd520

namespace fnv_00ccd610 {
struct S_00ccd610_Tls {
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
    int ctx;
};
__declspec(thread) S_00ccd610_Tls DAT_tls;

struct S_00ccd610_Ctx {
    int saved;
    __forceinline S_00ccd610_Ctx(int c) { saved = (*reinterpret_cast<::fnv_00ccd610::S_00ccd610_Tls *>(&::g_tlsBlock)).ctx; (*reinterpret_cast<::fnv_00ccd610::S_00ccd610_Tls *>(&::g_tlsBlock)).ctx = c; }
    __forceinline ~S_00ccd610_Ctx() { (*reinterpret_cast<::fnv_00ccd610::S_00ccd610_Tls *>(&::g_tlsBlock)).ctx = saved; }
};

struct S_00ccd610_Alloc {
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00ccd610_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00ccd610_Alloc* unk10;
    S_00ccd610_Alloc& heap() { return *unk10; }
};

struct S_00ccd610_RefObj {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00ccd610_RefObj();
    void* operator new(std::size_t n) {
        S_00ccd610_RefObj* b = static_cast<S_00ccd610_RefObj*>(static_cast<S_00ccd610_Router*>(::FUN_00c85750())->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*) {}
};
struct S_00ccd610_Obj : S_00ccd610_RefObj {
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
    S_00ccd610_Obj(intptr_t a, intptr_t b, float c, float d);
};

struct S_00ccd610_Cls {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c(S_00ccd610_RefObj* o);
    void CreateAndDispatchObject(intptr_t a, intptr_t b, float c);
};

// Allocates an S_00ccd610_Obj with the given arguments and DAT_011b153c, passes it to vfn_8c, then calls its FUN_00c905b0.
// @fnv 0x00ccd610
void S_00ccd610_Cls::CreateAndDispatchObject(intptr_t aiArg1, intptr_t aiArg2, float afValue)
{
    S_00ccd610_Ctx ctx(0x10);
    S_00ccd610_Obj* o = new S_00ccd610_Obj(aiArg1, aiArg2, afValue, ::DAT_011b153c);
    this->vfn_8c(o);
    reinterpret_cast<::hkReferencedObjectC905 *>((o))->FUN_00c905b0();
}
}  // namespace fnv_00ccd610


// @fnv 0x00ccdc30
int* __cdecl FUN_00ccdc30()
{
    return reinterpret_cast<int*>(&::g_012686a0);
}

// Constructor of a four-level Havok wrapper class: each level bumps its own live-instance counter.

extern int g_iCDC40LevelACount;
extern int g_iCDC40LevelBCount;
extern int g_iCDC40LevelCCount;
extern int g_iCDC40LevelDCount;

class CDC40Root {
public:
    CDC40Root();
    virtual ~CDC40Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};

class CDC40Holder : public CDC40Root {
public:
    CDC40Holder() : m_pkHavokObject(0), m_uiData(0) {}
    virtual ~CDC40Holder();
    void* m_pkHavokObject;
    unsigned int m_uiData;
};

class CDC40LevelA : public CDC40Holder {
public:
    CDC40LevelA() { ++g_iCDC40LevelACount; }
    virtual ~CDC40LevelA();
};

class CDC40LevelB : public CDC40LevelA {
public:
    CDC40LevelB() { ++g_iCDC40LevelBCount; }
    virtual ~CDC40LevelB();
};

class CDC40LevelC : public CDC40LevelB {
public:
    CDC40LevelC() { ++g_iCDC40LevelCCount; }
    virtual ~CDC40LevelC();
};

class FUN_00ccdc40 : public CDC40LevelC {
public:
    FUN_00ccdc40();
    virtual ~FUN_00ccdc40();
};

// Constructs a CDC40LevelD object and increments the global CDC40 level D instance counter.
// @fnv 0x00ccdc40
FUN_00ccdc40::FUN_00ccdc40()
{
    ++g_iCDC40LevelDCount;
}



struct RefObject20_b9084 {
    char m00[0x14];
    RefObject20_b9084();
};

// Allocates and constructs a RefObject20_b9084 via its operator new and returns the new object.
// @fnv 0x00ccdd00
RefObject20_b9084* CreateRefObject20() {
    return new RefObject20_b9084();
}

struct FUN_00ccdd70_arg {
    unsigned int m_u00;
    unsigned int m_u04;
    unsigned int m_u08;
    unsigned int m_u0C;
    float m_f10;
};

class CdResultObj {
public:
    virtual void v00();
    void FUN_00ccdc90(float value);
};

class FUN_00ccdd70_cls {
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
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual CdResultObj* GetResult(unsigned char* flag);
    void ApplyResultValue(int a1, FUN_00ccdd70_arg* a2);
};

// Gets a result object, applies a2->m_f10 to it when it is not 1.0, then forwards a1 and a2 to FUN_00c84df0.
// @fnv 0x00ccdd70
void FUN_00ccdd70_cls::ApplyResultValue(int a1, FUN_00ccdd70_arg* a2)
{
    unsigned char flag;
    CdResultObj* result = this->GetResult(&flag);
    float value = a2->m_f10;
    if (value != 1.0f) {
        result->FUN_00ccdc90(value);
    }
    reinterpret_cast<::FUN_00c84df0_cls *>((this))->FUN_00c84df0((::FUN_00c84df0_cls *)(a1), (::FUN_00c84df0_cls *)(a2));
}

struct CCDDE0Stream {
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
    unsigned char unk1E4;
    unsigned char m_ucPlatform;
};

struct CCDDE0Vector3 {
    float x;
    float y;
    float z;
};

struct CCDDE0Data {
    int unk00;
    float m_fScale;
    CCDDE0Vector3 m_kMin;
    CCDDE0Vector3 m_kMax;
};

struct CCDDE0Shape;



class CCDDE0Base {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual CCDDE0Shape* GetShape();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual CCDDE0Data* GetData(unsigned int* puiSize);

};

class CCDDE0Object : public CCDDE0Base {
public:
    void FUN_00ccdde0(CCDDE0Stream* pkStream);
};

// Loads the base data, sets m_fScale, swaps min/max vectors when the platform is not 1, then converts both vectors from the stream.
// @fnv 0x00ccdde0
void CCDDE0Object::FUN_00ccdde0(CCDDE0Stream* pkStream)
{
    reinterpret_cast<::Cls_00c9fbc0 *>(this)->FUN_00c9fbc0((::Arg_00c9fbc0 *)(pkStream));
    unsigned int uiSize;
    CCDDE0Data* pkData = GetData(&uiSize);
    pkData->m_fScale = DAT_010c72bc;
    if (pkStream->m_ucPlatform != 1) {
        CCDDE0Shape* pkShape = GetShape();
        ::FUN_00cf0930(pkData, (int)(pkShape), (::Vector3 *)(::CCDDE0Vector3 *)(&pkData->m_kMin));
        ::FUN_00cf0930(pkData, (int)(pkShape), (::Vector3 *)(::CCDDE0Vector3 *)(&pkData->m_kMax));
    }
    ::FUN_00cf0f40((::S00cf0f40_Owner *)(pkStream), (::S00cf0f40_Arr *)(::CCDDE0Vector3 *)(&pkData->m_kMin));
    ::FUN_00cf0f40((::S00cf0f40_Owner *)(pkStream), (::S00cf0f40_Arr *)(::CCDDE0Vector3 *)(&pkData->m_kMax));
}

namespace fnv_00cce0d0 {
struct SpawnedAllocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};

struct AllocHolder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    SpawnedAllocator* m_pAllocator;
};


struct FUN_00cce0d0_cls {
    void* m_pData;
    int m_04;
    unsigned int m_08;

    void ClearAndFree();
};

// @fnv 0x00cce0d0
void FUN_00cce0d0_cls::ClearAndFree()
{
    AllocHolder* holder = static_cast<AllocHolder*>(::FUN_00c85750());
    SpawnedAllocator* alloc = holder->m_pAllocator;
    unsigned int flags = m_08;
    m_04 = 0;
    if ((flags & 0x80000000u) == 0) {
        alloc->Free(m_pData, (flags & 0x3fffffffu) * 16u);
    }
    m_pData = 0;
    m_08 = 0x80000000u;
}
}  // namespace fnv_00cce0d0


struct BCCE110AllocTagScope {
    int m_iSaved;

    BCCE110AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCCE110AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class BCCE110StringArray {
public:
    virtual ~BCCE110StringArray();
    void SetSize(unsigned int uiMaxSize);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement) { return SetAtGrow(m_usSize, pcElement); }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcCCE110Name;


class FUN_00cce110_cls {
public:
    void AppendNameToArray(BCCE110StringArray* pkArray);
};

// Sets an allocation tag, calls FUN_00c9fc50 on the array, then appends the string returned by FUN_00a7d330(g_pcCCE110Name).
// @fnv 0x00cce110
void FUN_00cce110_cls::AppendNameToArray(BCCE110StringArray* pkArray)
{
    BCCE110AllocTagScope kScope(0x10);
    reinterpret_cast<::SphereShape *>(this)->FUN_00c9fc50((::ViewerStringArray *)(pkArray));
    char* pcName = FUN_00a7d330(g_pcCCE110Name);
    pkArray->Add(pcName);
}

namespace fnv_00cce290 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize);
};

struct AudioHolder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    AudioAllocator* m_pAllocator;
};


struct AudioScopeGuard {
    void* m_pSharedOwner;
    AudioScopeGuard(void* owner) { m_pSharedOwner = owner; }
    ~AudioScopeGuard() { m_pSharedOwner = 0; }
};

struct FUN_00cce290_cls {
    int unk00;
    int unk04;
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void FUN_00cce290();
};

// Frees both allocated arrays through the audio allocator and resets their pointers, counts and capacity bits.
// @fnv 0x00cce290
void FUN_00cce290_cls::FUN_00cce290()
{
    {
        AudioScopeGuard guard(this);
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapBits1 = m_uCapBits1;
        m_iCount1 = 0;
        if ((uCapBits1 & 0x80000000u) == 0) {
            void* pData1 = m_pData1;
            pAllocator->FreeArray(pData1, (uCapBits1 & 0x3fffffffu) * 16);
        }
        m_pData1 = 0;
        m_uCapBits1 = 0x80000000u;
    }

    AudioHolder* pHolder2 = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
    unsigned int uCapBits2 = m_uCapBits2;
    m_iCount2 = 0;
    if ((uCapBits2 & 0x80000000u) == 0) {
        pAllocator2->FreeArray(m_pData2, (uCapBits2 & 0x3fffffffu) * 16);
    }
    m_pData2 = 0;
    m_uCapBits2 = 0x80000000u;
}
}  // namespace fnv_00cce290

extern int DAT_012686b0;

// @fnv 0x00cce970
int* __cdecl FUN_00cce970()
{
    return &DAT_012686b0;
}

// @fnv 0x00cce980
int __cdecl FUN_00cce980()
{
    return 0x50;
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00cce9e0_cls {
    int unk00;


    FUN_00cce9e0_cls* FUN_00cce9e0(unsigned char acFlags);
};

// @fnv 0x00cce9e0
FUN_00cce9e0_cls* FUN_00cce9e0_cls::FUN_00cce9e0(unsigned char acFlags)
{
    reinterpret_cast<::FUN_00cce900 *>(this)->FUN_00cce900::~FUN_00cce900();
    if (acFlags & 1) {
        FUN_00aa1460(this, 0x14);
    }
    return this;
}

struct BCCECC0Data {
    int unk00;
    int unk04;
    void* m_pvUserData;
};

struct BCCECC0Extra {
    int unk00;
    int unk04;
    void* m_pvUserData;
};

class BCCECC0Node {
public:
};

class BCCECC0Wrapper {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual BCCECC0Data* GetData(bool* pbCreated);

    void SetUserDataFromNode(BCCECC0Node* pkNode);
};

// Copies the node's extra user data pointer into the wrapper's data, then calls FUN_00c84cc0 with the node.
// @fnv 0x00ccecc0
void BCCECC0Wrapper::SetUserDataFromNode(BCCECC0Node* pkNode)
{
    bool bCreated;
    BCCECC0Data* pkData = GetData(&bCreated);
    BCCECC0Extra* pkExtra = ((::BCCECC0Extra *)(reinterpret_cast<::NiStream *>((pkNode))->GetLoadedObject()));
    pkData->m_pvUserData = pkExtra ? pkExtra->m_pvUserData : 0;
    ::FUN_00c84cc0((int *)this, (unsigned int)(pkNode));
}

struct FUN_00cced20_C {
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
    virtual void v54(int a);
};

struct FUN_00cced20_B {
    int unk00;
    int unk04;
    FUN_00cced20_C* m_08;
};

struct FUN_00cced20_A {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00cced20_B* m_18;
};

struct FUN_00cced20_cls {
    int unk00;
    int unk04;
    FUN_00cced20_A* m_08;

    void ForwardToNestedVtable(int a1);
};

// Walks this->m_08->m_18->m_08 and, if non-null, calls its v54 with a1, then calls FUN_00aa0ad0(a1).
// @fnv 0x00cced20
void FUN_00cced20_cls::ForwardToNestedVtable(int aiValue)
{
    if (this != 0) {
        FUN_00cced20_A* pRoot = m_08;
        if (pRoot != 0) {
            FUN_00cced20_B* pMid = pRoot->m_18;
            if (pMid != 0) {
                FUN_00cced20_C* pLeaf = pMid->m_08;
                if (pLeaf != 0) {
                    pLeaf->v54(aiValue);
                }
            }
        }
    }
    ::FUN_00aa0ad0();
}

namespace fnv_00ccef50 {

struct AutoMemCtx {
    int m_iOld;
    AutoMemCtx(int ctx) { m_iOld = (*reinterpret_cast<int *>(&::currentAllocationContext)); (*reinterpret_cast<int *>(&::currentAllocationContext)) = ctx; }
    ~AutoMemCtx() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iOld; }
};

struct hkMemAllocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int size);
};

struct hkThreadMem {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    hkMemAllocator* m_pAllocator;
};


struct IntegerBlock18 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct hkObj {
    void* m_pVtable;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
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

    static void* operator new(std::size_t size) {
        hkThreadMem* t = static_cast<hkThreadMem*>(::FUN_00c85750());
        hkObj* p = (hkObj*)t->m_pAllocator->AllocateMemoryBlock(size);
        p->m_usMemSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
    hkObj(int a, IntegerBlock18* b, int c);
};

struct Inner2 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int unk10;
};

struct Inner1 {
    int unk00;
    int unk04;
    Inner2* unk08;
};

struct Inner0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Inner1* unk18;
};

struct Param {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    IntegerBlock18 info;
};

struct Holder {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void SetObject(hkObj* obj);
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8();
    virtual void SetParam(Param* p);

    int unk04;
    Inner0* unk08;
    int unk0C;
    unsigned int unk10;

    void SetObjectAndParam(Param* p);
};

// Allocates an hkObj from the param, passes it to SetObject, releases it, calls SetParam, then stores a masked value from the nested inner structures into unk10.
// @fnv 0x00ccef50
void Holder::SetObjectAndParam(Param* p)
{
    AutoMemCtx ctx(16);
    hkObj* obj = new hkObj(p->unk08, &p->info, 1);
    SetObject(obj);
    reinterpret_cast<::hkReferencedObjectC905 *>((obj))->FUN_00c905b0();
    SetParam(p);
    if (unk08) {
        if (Inner1* a = unk08->unk18) {
            if (Inner2* b = a->unk08) {
                unk10 = b->unk10 & 0x1f;
                return;
            }
            return;
        }
        return;
    }
}
}  // namespace fnv_00ccef50

struct ManagedReference {
    virtual void unused();
    virtual void destroy();
    volatile long references;
};
struct ResourceRecord {
    void* unk00;
    void* unk04;
    ManagedReference* resource;
};
struct OwnerRecord {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    ResourceRecord* active;
};
struct ScopedThreadSetting {
    int prior;
    ScopedThreadSetting() : prior((*reinterpret_cast<int *>(&::currentAllocationContext))) {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~ScopedThreadSetting() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = prior; }
};
// Sets the thread alloc state to 16, then decrements the active resource's reference count and destroys it when it reaches zero.
// @fnv 0x00ccf060
void FUN_00ccf060_stub::ReleaseActiveResource() {
    ScopedThreadSetting scope;
    if (this != 0) {
        OwnerRecord* owner = *(OwnerRecord**)((char*)this + 8);
        if (owner != 0 && owner->active != 0) {
            ManagedReference* p = owner->active->resource;
            if (p != 0 && InterlockedDecrement(&p->references) == 0)
                p->destroy();
        }
    }
}

struct TaskTls {
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
 int unk1E8;
 int unk1EC;
 int unk1F0;
 int unk1F4;
 int unk1F8;
 int unk1FC;
 int unk200;
 int unk204;
 int unk208;
 int unk20C;
 int unk210;
 int unk214;
 int unk218;
 int unk21C;
 int unk220;
 int unk224;
 int unk228;
 int unk22C;
 int unk230;
 int unk234;
 int unk238;
 int unk23C;
 int unk240;
 int unk244;
 int unk248;
 int unk24C;
 int unk250;
 int unk254;
 int unk258;
 int unk25C;
 int unk260;
 int unk264;
 int unk268;
 int unk26C;
 int unk270;
 int unk274;
 int unk278;
 int unk27C;
 int unk280;
 int unk284;
 int unk288;
 int unk28C;
 int unk290;
 int unk294;
 int unk298;
 int unk29C;
 int unk2A0;
 int unk2A4;
 int unk2A8;
 int unk2AC;
 int unk2B0;
 int context;
};
__declspec(thread) TaskTls g_taskTls;
struct AutoMemContext {
 int old;
 AutoMemContext(int value) { old=(*reinterpret_cast<::TaskTls *>(&::g_tlsBlock)).context; (*reinterpret_cast<::TaskTls *>(&::g_tlsBlock)).context=value; }
 ~AutoMemContext() { (*reinterpret_cast<::TaskTls *>(&::g_tlsBlock)).context=old; }
};
struct ThreeByThreeMatrix {
 float m00,m01,m02,m10,m11,m12,m20,m21,m22;
};
struct NiTransform { ThreeByThreeMatrix rotation; NiPoint3 translation; float scale; };
struct Transform403 { hkVector4 row0,row1,row2,translation; };
struct Output403 {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
 virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
 virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
 virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
 virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
 virtual void Output(StrArr*);
};
struct Link403 { int unk00,unk04; Output403* target; };
struct Data403 { int unk00,unk04,unk08,unk0c,unk10,unk14; Link403* link; int unk1c; Transform403 transform; };
extern const char g_010c6050[],g_010c604c[];
struct StringArray403 : StrArr {
 void Add(char* value) {
  unsigned int index=m_usElementCount;
  if(index >= m_usSize) SetSize(index+m_usIncrement);
  reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index,value);
 }
};
struct Holder403 {
 int unk00,unk04;
 Data403* data;
 const Transform403& GetTransform() const {
  if(this && data) return data->transform;
  return *reinterpret_cast<const Transform403*>(&::DAT_01268370);
 }
 void AppendTransformStrings(StringArray403*);
};
// @fnv 0x00ccf350
void Holder403::AppendTransformStrings(StringArray403* strings) {
 AutoMemContext context(16);
 reinterpret_cast<::SphereShape *>(this)->FUN_00c9fc50((::ViewerStringArray *)(strings));
 strings->Add(FUN_00a7d330(*reinterpret_cast<const char* const*>(&::g_012686b0)));
 const Transform403& transform=GetTransform();
 NiTransform converted;
 ::FUN_00624b10((::FUN_004769c0_shell *)(::NiTransform *)(&converted),(::FUN_004b4cf0_shell *)(&transform));
 ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&converted.translation)),(*(const ::hkVector4 *)(&transform.translation)));
 strings->Add(converted.translation.FUN_00a59af0(g_010c6050));
 strings->Add(reinterpret_cast<::FloatMatrix3 *>(&(converted.rotation))->ToString(g_010c604c));
 if(this) {
  Data403* object=data;
  if(object) {
   Link403* link=object->link;
   if(link) {
    Output403* output=link->target;
    if(output) output->Output(strings);
   }
  }
 }
}

extern int DAT_012686b8;

// @fnv 0x00ccf550
void* __cdecl FUN_00ccf550()
{
    return &DAT_012686b8;
}

// FUN_00ccf560 - a virtual forwarder.
//
// The object pointer arrives in ECX (a member).  The function reads
// the object's vtable pointer and tail-jumps to the virtual that lives at
// vtable offset 0xbc, forwarding its own 4-byte stack argument IN PLACE.
//
// Forwarding the argument in place is what keeps the frame frameless and puts
// the jump target in EAX (a forward with no forwarded argument would use EDX).
//
// The 47 dummy virtuals only place the forwarded virtual at vtable offset 0xbc:
// the first virtual of a class sits at vptr+0, so offset 0xbc is the 48th slot.

struct bhkConvexShape {
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
    virtual void v0BC(int arg);
};

struct bhkConvexSweepShape : public bhkConvexShape {
    void FUN_00ccf560(int arg);
};

// @fnv 0x00ccf560
void bhkConvexSweepShape::FUN_00ccf560(int arg) {
    v0BC(arg);
}

namespace fnv_00ccf5d0 {

extern "C" void __cdecl FUN_00c87c30();
extern "C" char DAT_010caaf4[];

struct PackedObj {
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    PackedObj() {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        m_vtbl = (void*)(*reinterpret_cast<char (*)[]>(&::DAT_01030bf4));
        unk0C = 0;
        unk10 = 0;
        unsigned int count = 1;
        DAT_012680f8 += count;
        m_vtbl = (void*)(*reinterpret_cast<char (*)[]>(&::DAT_01030b0c));
        DAT_01268274 += count;
        m_vtbl = (void*)(*reinterpret_cast<char (*)[]>(&::DAT_01030a24));
        DAT_01268250 += count;
        m_vtbl = (void*)DAT_010caaf4;
    }
};

// Allocates and constructs a PackedObj, returning the new object pointer.
// @fnv 0x00ccf5d0
void* __cdecl CreatePackedObj() {
    PackedObj* p = new PackedObj();
    return p;
}
}  // namespace fnv_00ccf5d0

extern int DAT_012686c4;

// @fnv 0x00ccf7b0
void* __cdecl FUN_00ccf7b0()
{
    return &DAT_012686c4;
}

// FUN_00ccf810: thiscall, 21 bytes, 2 stack args.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x38] / jmp eax / end: ret 8
// Forwards the two stack arguments to virtual slot 0x38 of the object
// pointed to by the member at this+8.
struct Target
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void Tail(int a, int b);
};

struct FUN_00ccf810_cls
{
    int unk00;
    int unk04;
    Target* volatile m_08;
    void FUN_00ccf810(int a, int b);
};

// @fnv 0x00ccf810
void FUN_00ccf810_cls::FUN_00ccf810(int a, int b)
{
    if (this) {
        Target* p = m_08;
        if (p) {
            p->Tail(a, b);
        }
    }
}

namespace fnv_00ccf830 {
// DispatchTail: thiscall, 21 bytes, 3 stack args.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x3c] / jmp eax / end: ret 0xc
// Forwards the three stack arguments to virtual slot 0x3c of the object
// pointed to by the member at this+8.
struct Target
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void Tail(int a, int b, int c);
};

struct FUN_00ccf830_cls
{
    int unk00;
    int unk04;
    Target* volatile m_08;
    void DispatchTail(int a, int b, int c);
};

// @fnv 0x00ccf830
void FUN_00ccf830_cls::DispatchTail(int a, int b, int c)
{
    if (this) {
        Target* p = m_08;
        if (p) {
            p->Tail(a, b, c);
        }
    }
}
}  // namespace fnv_00ccf830

namespace fnv_00ccf850 {
// FUN_00ccf850: thiscall, 21 bytes, 1 stack arg.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x34] / jmp eax / end: ret 4
// Forwards the stack argument to virtual slot 0x34 of the object pointed to
// by the member pointer at this+8.
struct Target
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void Tail(int a);
};

struct FUN_00ccf850_cls
{
    int unk00;
    int unk04;
    Target* volatile m_08;
    void FUN_00ccf850(int a);
};

// @fnv 0x00ccf850
void FUN_00ccf850_cls::FUN_00ccf850(int a)
{
    if (this) {
        Target* p = m_08;
        if (p) {
            p->Tail(a);
        }
    }
}
}  // namespace fnv_00ccf850

struct Link {
    void* m_type;
    unsigned int m_flags;
    void* m_object;
};
struct RefObject {
    void** m_ppVirtualMethodTable;
    unsigned int m_flags;
    Link* m_link;
};
struct LinkCollection {
    unsigned int m_type;
    unsigned int m_flags;
    unsigned int m_pRayCursor;
    unsigned int m_generation;
    Link** m_ppLinks;
    int m_uiItemCount;
};
struct Sink;
struct Owner {
    void** m_ppVirtualMethodTable;
    void FUN_00ccf900(void* item, void* key);
public:
    void FUN_00ca4f80(::Sink *);
};
typedef LinkCollection* (*AcquireLinks)(Owner*, unsigned char*);
typedef bool (*CheckRef)(RefObject*, void*);
typedef RefObject* (*FindRef)(RefObject*, void*);
// @fnv 0x00ccf900
void Owner::FUN_00ccf900(void* item, void* key)
{
    unsigned char unusedFlag;
    LinkCollection* list = ((AcquireLinks)m_ppVirtualMethodTable[0xb4 / 4])(this, &unusedFlag);
    for (int index = 0; index < list->m_uiItemCount; ++index) {
        Link* link = list->m_ppLinks[index];
        if (link) {
            RefObject* ref = (RefObject*)link->m_object;
            if (ref && !((CheckRef)ref->m_ppVirtualMethodTable[0xd0 / 4])(ref, key)) {
                RefObject* replacement = ((FindRef)ref->m_ppVirtualMethodTable[0x48 / 4])(ref, key);
                list->m_ppLinks[index] = replacement ? replacement->m_link : 0;
            }
        }
    }
    reinterpret_cast<::FUN_00c84df0_cls *>(this)->FUN_00c84df0((::FUN_00c84df0_cls *)(item), (::FUN_00c84df0_cls *)(key));
}

struct FNVCountInterface {
    virtual void Reserved();
    virtual unsigned int GetCount();
};

struct FNVNotificationReceiver {
    virtual void Reserved00();
    virtual void Reserved01();
    virtual void Reserved02();
    virtual void Reserved03();
    virtual void Reserved04();
    virtual void Reserved05();
    virtual void Reserved06();
    virtual void Reserved07();
    virtual void Reserved08();
    virtual void Reserved09();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Notify(int context);
};

struct FNVNotificationEntry {
    void* m_unknown00;
    void* m_unknown04;
    FNVNotificationReceiver* m_receiver;
};

struct FNVNotificationCollection {
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    unsigned int m_unknown08;
    unsigned int m_unknown0c;
    unsigned int m_unknown10;
    FNVCountInterface m_countInterface;
    unsigned int m_unknown18;
    unsigned int m_unknown1c;
    unsigned int m_unknown20;
    unsigned int m_unknown24;
    unsigned int m_unknown28;
    unsigned int m_unknown2c;
    unsigned int m_unknown30;
    unsigned int m_unknown34;
    unsigned int m_unknown38;
    unsigned int m_unknown3c;
    unsigned int m_unknown40;
    FNVNotificationEntry** m_entries;
};

struct FNVNotificationOwner {
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    FNVNotificationCollection* m_pShapeCollection;
    void NotifyAllReceivers(int context);
};

// Calls Notify(context) on each non-null receiver in the collection's entries, then calls FUN_00aa0ad0(context).
// @fnv 0x00ccf990
void FNVNotificationOwner::NotifyAllReceivers(int context)
{
    unsigned int count;
    FNVNotificationCollection* collection;
    if (this && (collection = m_pShapeCollection))
        count = collection->m_countInterface.GetCount();
    else
        count = 0;
    for (unsigned int index = 0; index < count; ++index) {
        if (this && m_pShapeCollection) {
            FNVNotificationEntry* entry = m_pShapeCollection->m_entries[index];
            if (entry) {
                FNVNotificationReceiver* receiver = entry->m_receiver;
                if (receiver)
                    receiver->Notify(context);
            }
        }
    }
    ::FUN_00aa0ad0();
}

class CCFA00RefObject {
public:
    virtual ~CCFA00RefObject();

    unsigned int m_uiRefCount;

    void IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
};

struct CCFA00Entry {
    int unk00;
    int unk04;
    CCFA00RefObject* m_pPointer;
};

class CCFA00List {
public:
    virtual void vfunc00();
    virtual int GetSize();
};

struct CCFA00Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    CCFA00List m_kList;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34;
    int unk38; int unk3C; int unk40;
    CCFA00Entry** m_ppkEntries;
};

class CCFA00Holder {
public:
    int unk00;
    int unk04;
    CCFA00Data* m_pUserData;

    void IncRefCountAllEntries();
};
// Calls IncRefCountAllEntries when a is true, otherwise ReleaseAllNodes, then forwards a to FUN_00c84e50 on this.
// @fnv 0x00ccfe20
void FUN_00ccfe20_class::FUN_00ccfe20(bool a)
{
    if (a)
        static_cast<::CCFA00Holder *>(nullptr)->IncRefCountAllEntries();
    else
        ReleaseAllNodes();
    reinterpret_cast<::bhkBoxShape *>((((H_00c8c810*)this)))->FUN_00c84e50(a);
}

// If the holder's data is valid, iterates its entries and increments the reference count of each entry's referenced object.
// @fnv 0x00ccfa00
void CCFA00Holder::IncRefCountAllEntries()
{
    CCFA00Data* pkData;
    if (this && (pkData = m_pUserData) != 0) {
        int i = pkData->m_kList.GetSize();
        while (i) {
            i--;
            if (m_pUserData) {
                CCFA00Entry* pkEntry = m_pUserData->m_ppkEntries[i];
                if (pkEntry && pkEntry->m_pPointer)
                    pkEntry->m_pPointer->IncRefCount();
            }
        }
    }
}

struct ObjC;

struct SubObj14 {
    virtual void vfn0();
    virtual int vfn1();
};

struct ObjA {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    SubObj14 m_14;
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
    ObjC** m_44;
};

struct ObjD {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53(int p1, int p2);
};

struct ObjC {
    unsigned int unk00;
    unsigned int unk04;
    ObjD* m_08;
};

class FUN_00ccfad0_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    ObjA* m_08;
    void FUN_00ccfad0(int a1, int a2);
};

// Calls v53(a1, a2) on the m_08 object of each element in m_44, iterating up to the count returned by m_14.vfn1().
// @fnv 0x00ccfad0
void FUN_00ccfad0_cls::FUN_00ccfad0(int a1, int a2) {
    int count;
    ObjA* a0 = (this != 0) ? this->m_08 : 0;
    if (a0 != 0) {
        count = a0->m_14.vfn1();
    } else {
        count = 0;
    }
    int i = 0;
    if (count > 0) {
        do {
            if (this != 0) {
                ObjA* a = this->m_08;
                if (a != 0) {
                    ObjC* c = a->m_44[i];
                    if (c != 0) {
                        ObjD* d = c->m_08;
                        if (d != 0) {
                            d->v53(a1, a2);
                        }
                    }
                }
            }
            ++i;
        } while (i < count);
    }
}

struct ItemFlags {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int flags;
};
struct ItemEntry {
    unsigned int unk00;
    unsigned int unk04;
    ItemFlags* details;
};
struct CountProvider {
    virtual void unused();
    virtual unsigned int LastIndex();
};
struct ItemContainer {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    CountProvider counter;
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
    ItemEntry** entries;
};
struct ItemCollection {
    unsigned int unk00;
    unsigned int unk04;
    ItemContainer* container;
    unsigned int unk0c;
    unsigned int defaultFlags;
    unsigned int GetItemFlags(unsigned int index);
};
// @fnv 0x00ccfb40
unsigned int ItemCollection::GetItemFlags(unsigned int index) {
    if (index != 0xffffffffu) {
        unsigned int lastIndex;
        if (this != 0) {
            ItemContainer* pContainer = container;
            if (pContainer != 0)
                lastIndex = pContainer->counter.LastIndex();
            else
                lastIndex = 0;
        } else
            lastIndex = 0;
        if (index <= lastIndex && this != 0 && container != 0) {
            ItemEntry* entry = container->entries[index];
            if (entry != 0 && entry->details != 0)
                return entry->details->flags & 0x1f;
        }
    }
    return defaultFlags & 0x1f;
}

namespace fnv_00ccfba0 {
struct TlsBlock_b9412 {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};



struct SpawnedObj_b9412 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SpawnedObj_b9412();
};

struct TlsGuard_b9412 {
    unsigned int m_saved;
    TlsGuard_b9412() { m_saved = (*reinterpret_cast<::fnv_00ccfba0::TlsBlock_b9412 *>(&::g_tlsBlock)).m_2b4; (*reinterpret_cast<::fnv_00ccfba0::TlsBlock_b9412 *>(&::g_tlsBlock)).m_2b4 = 0x10; }
    ~TlsGuard_b9412() { (*reinterpret_cast<::fnv_00ccfba0::TlsBlock_b9412 *>(&::g_tlsBlock)).m_2b4 = m_saved; }
};

struct Holder_b9412 {
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
    virtual void vSlot49(SpawnedObj_b9412* o, int p);
    SpawnedObj_b9412* CreateSpawnedObj(int p);
};

// @fnv 0x00ccfba0
SpawnedObj_b9412* Holder_b9412::CreateSpawnedObj(int p) {
    TlsGuard_b9412 guard;
    ::FUN_00c876f0();
    SpawnedObj_b9412* o = new SpawnedObj_b9412();
    vSlot49(o, p);
    ::FUN_00c87700();
    return o;
}
}  // namespace fnv_00ccfba0

namespace fnv_00ccfc60 {
struct CCFAllocator {
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct CCFMemoryRouter {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    CCFAllocator* m_pStreamAllocator;

    CCFAllocator& heap() { return *m_pStreamAllocator; }
};



struct CCFAllocTagScope {
    int m_iSaved;

    CCFAllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CCFAllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class hkReferencedObjectCCF {
public:
    virtual ~hkReferencedObjectCCF();

    static void* operator new(std::size_t uiSize) {
        void* p = (*static_cast<CCFMemoryRouter*>(::FUN_00c85750())).heap().AllocateMemoryBlock(uiSize);
        static_cast<hkReferencedObjectCCF*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeCCF : public hkReferencedObjectCCF {
public:
    hkpShapeCCF(int iA, int iB);

    int unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
};

struct ShapeInfoCCF {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iA;
    int m_iB;
};

class bhkShapeCCF {
public:
    virtual void unkv000();
    virtual void unkv004();
    virtual void unkv008();
    virtual void unkv00C();
    virtual void unkv010();
    virtual void unkv014();
    virtual void unkv018();
    virtual void unkv01C();
    virtual void unkv020();
    virtual void unkv024();
    virtual void unkv028();
    virtual void unkv02C();
    virtual void unkv030();
    virtual void unkv034();
    virtual void unkv038();
    virtual void unkv03C();
    virtual void unkv040();
    virtual void unkv044();
    virtual void unkv048();
    virtual void unkv04C();
    virtual void unkv050();
    virtual void unkv054();
    virtual void unkv058();
    virtual void unkv05C();
    virtual void unkv060();
    virtual void unkv064();
    virtual void unkv068();
    virtual void unkv06C();
    virtual void unkv070();
    virtual void unkv074();
    virtual void unkv078();
    virtual void unkv07C();
    virtual void unkv080();
    virtual void unkv084();
    virtual void unkv088();
    virtual void SetShape(hkpShapeCCF* pkShape);
    virtual void unkv090();
    virtual void unkv094();
    virtual void unkv098();
    virtual void unkv09C();
    virtual void unkv0A0();
    virtual void unkv0A4();
    virtual void unkv0A8();
    virtual void unkv0AC();
    virtual void unkv0B0();
    virtual void unkv0B4();
    virtual void unkv0B8();
    virtual void FinishInit(ShapeInfoCCF* pkInfo);

    void CreateShapeAndFinishInit(ShapeInfoCCF* pkInfo);
};

// Allocates an hkpShapeCCF from pkInfo's m_iA and m_iB, sets it as the shape, releases the reference, then calls FinishInit.
// @fnv 0x00ccfc60
void bhkShapeCCF::CreateShapeAndFinishInit(ShapeInfoCCF* pkInfo)
{
    CCFAllocTagScope kScope(0x10);
    int iA = pkInfo->m_iA;
    int iB = pkInfo->m_iB;
    hkpShapeCCF* pkShape = new hkpShapeCCF(iA, iB);
    SetShape(pkShape);
    reinterpret_cast<::hkReferencedObjectC905 *>((pkShape))->FUN_00c905b0();
    FinishInit(pkInfo);
}
}  // namespace fnv_00ccfc60

namespace fnv_00ccfd40 {
struct NodeRelease_tls {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int m_2b4;
};

struct NodeRelease_guard {
    unsigned int m_saved;
    NodeRelease_guard() {
        m_saved = (*reinterpret_cast<::fnv_00ccfd40::NodeRelease_tls *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00ccfd40::NodeRelease_tls *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~NodeRelease_guard() {
        (*reinterpret_cast<::fnv_00ccfd40::NodeRelease_tls *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4 = m_saved;
    }
};

class NodeRelease_sub {
public:
    virtual void vfn_0();
    virtual int vfn_4();
};

class NodeRelease_ref {
public:
    virtual void vfn_0();
    virtual void vfn_4();
    long m_04;
};

struct NodeRelease_node {
    unsigned int unk00;
    unsigned int unk04;
    NodeRelease_ref* m_08;
};

struct NodeRelease_mgr {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    NodeRelease_sub m_14;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    NodeRelease_node** m_44;
};

class NodeRelease_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    NodeRelease_mgr* m_08;
    void ReleaseAllNodes();
};

// Decrements the reference count of each node's ref in m_08's m_44 array and calls its vfn_4 when the count reaches zero.
// @fnv 0x00ccfd40
void NodeRelease_cls::ReleaseAllNodes() {
    NodeRelease_guard guard;
    if (this != 0) {
        NodeRelease_mgr* mgr = m_08;
        if (mgr != 0) {
            int i = mgr->m_14.vfn_4();
            if (i != 0) {
                do {
                    --i;
                    mgr = m_08;
                    if (mgr != 0) {
                        NodeRelease_node* node = mgr->m_44[i];
                        if (node != 0) {
                            NodeRelease_ref* ref = node->m_08;
                            if (ref != 0) {
                                if (InterlockedDecrement((volatile long*)&ref->m_04) == 0) {
                                    ref->vfn_4();
                                }
                            }
                        }
                    }
                } while (i != 0);
            }
        }
    }
}
}  // namespace fnv_00ccfd40

namespace fnv_00cd0480 {
class ContextScope {
 int previous;
public:
 ContextScope() { previous = (*reinterpret_cast<int *>(&::currentAllocationContext)); (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16; }
 ~ContextScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous; }
};
inline void Add(StrArr* array,char* value) {
 unsigned int index = array->m_usElementCount;
 if(index >= array->m_usSize) array->SetSize(index+array->m_usIncrement);
 reinterpret_cast<::fnv_00b5c7d0::StrArr *>((array))->SetAt(index,value);
}
struct CountInterface { virtual void unused(); virtual int count(); };
struct CountObject { int unk00,unk04,unk08,unk0c,unk10; CountInterface value; };
extern char* DAT_012686c4;
extern const char DAT_010c41b0[];
extern const char DAT_010c6040[];
struct ListOwner {
 int unk00,unk04; CountObject* object;
 void AppendCountInfo(StrArr*);
 static int GetCount(ListOwner* p) {
 CountObject* o = p ? p->object : 0;
 return o ? o->value.count() : 0;
 }
};
// @fnv 0x00cd0480
void ListOwner::AppendCountInfo(StrArr* output) {
 ContextScope scope;
 reinterpret_cast<::SphereShape *>(this)->FUN_00c9fc50((::ViewerStringArray *)(output));
 Add(output,::FUN_00a7d330(DAT_012686c4));
 int count = GetCount(this);
 Add(output,::FUN_00a7d4d0(DAT_010c41b0,count));
 for (int i=0;i<count;++i) {
 char buffer[32];
 ::FUN_00406d00(buffer,32,DAT_010c6040,i);
 }
}
}  // namespace fnv_00cd0480

struct FNVArray {
    int* m_data;
    int m_iElementCount;
    unsigned int m_capacityFlags;
    void FUN_00cd1d80(void* allocator, int index, int removeCount, const int* source, int insertCount);
};
// @fnv 0x00cd1d80
void FNVArray::FUN_00cd1d80(void* allocator, int index, int removeCount, const int* source, int insertCount) {
    int iNewCount = (m_iElementCount - removeCount) + insertCount;
    int p = (m_iElementCount - index) - removeCount;
    int cnt = m_capacityFlags & 0x3fffffff;
    if (cnt < iNewCount) {
        cnt += cnt;
        if (iNewCount >= cnt) cnt = iNewCount;
        ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(void *)(this), cnt, 4);
    }
    ::FUN_00d2cc70(m_data + (index + insertCount), (void *)(m_data + (index + removeCount)), p * 4);
    int* pInsertPos = m_data + index;
    for (int i = 0; i < insertCount; ++i) pInsertPos[i] = source[i];
    m_iElementCount = iNewCount;
}

// FUN_00cd3b00 : an empty function with four arguments.
// MSVC emits only the stack cleanup: ret 0x10.
// @fnv 0x00cd3b00
void FUN_00cd3b00(int a, int b, int c, int d) {
}

// FUN_00cd3c80: constant return 6
// @fnv 0x00cd3c80
int __cdecl FUN_00cd3c80()
{
    return 6;
}

extern int DAT_010cb344;

struct FUN_00cd3c90_cls
{
    void* m_pVtable;
    unsigned short m_uiValue1;
    unsigned short m_uiUnk;

    void* FUN_00cd3c90();
};

// @fnv 0x00cd3c90
void* FUN_00cd3c90_cls::FUN_00cd3c90()
{
    m_uiUnk = 1;
    m_pVtable = (void*)&DAT_010cb344;
    return this;
}


struct SpawnedObjectBase
{
    unsigned short m_unk00;
    unsigned short m_unk02;
    float m_unk04;

    SpawnedObjectBase()
    {
        m_unk04 = DAT_01013970;
        m_unk02 = 1;
    }
};

struct FUN_00cd3f90 : SpawnedObjectBase
{
    virtual void Unk00();

    FUN_00cd3f90();
};

// @fnv 0x00cd3f90
FUN_00cd3f90::FUN_00cd3f90()
{
}

extern char DAT_010cb398[];

struct FUN_00cd4260_cls {
    void* m_vptr;
    unsigned short unk04;
    unsigned short m_w06;

    FUN_00cd4260_cls* FUN_00cd4260();
};

// @fnv 0x00cd4260
FUN_00cd4260_cls* FUN_00cd4260_cls::FUN_00cd4260()
{
    m_w06 = 1;
    m_vptr = DAT_010cb398;
    return this;
}

namespace fnv_00cd7d60 {
struct TlsMemBlock {
    int unk000; int unk004; int unk008; int unk00c;
    int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c;
    int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c;
    int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c;
    int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c;
    int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac;
    int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc;
    int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec;
    int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c;
    int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c;
    int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c;
    int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c;
    int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c;
    int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac;
    int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc;
    int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec;
    int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c;
    int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c;
    int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248; int unk24c;
    int unk250; int unk254; int unk258; int unk25c;
    int unk260; int unk264; int unk268; int unk26c;
    int unk270; int unk274; int unk278; int unk27c;
    int unk280; int unk284; int unk288; int unk28c;
    int unk290; int unk294; int unk298; int unk29c;
    int unk2a0; int unk2a4; int unk2a8; int unk2ac;
    int unk2b0;
    int m_iTrailingValue;
};

struct MemClassGuard {
    int saved;
    MemClassGuard(int cls) { saved = (*reinterpret_cast<::fnv_00cd7d60::TlsMemBlock *>(&::g_tlsBlock)).m_iTrailingValue; (*reinterpret_cast<::fnv_00cd7d60::TlsMemBlock *>(&::g_tlsBlock)).m_iTrailingValue = cls; }
    ~MemClassGuard() { (*reinterpret_cast<::fnv_00cd7d60::TlsMemBlock *>(&::g_tlsBlock)).m_iTrailingValue = saved; }
};

struct ChunkAllocator {
    virtual void unk00();
    virtual void* allocateChunk(int size);
    virtual void freeChunk(void* p, int size);
};
struct MemHolder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    ChunkAllocator* allocator;
    void* allocateChunk(int n) { return allocator->allocateChunk(n); }
    void freeChunk(void* p, int n) { allocator->freeChunk(p, n); }
};
inline MemHolder* GetMemHolder() { return static_cast<MemHolder*>(::FUN_00c85750()); }

struct ShapeData {
    int data;
    int count;
    int stride;
};
struct ShapeParam {
    int unk00;
    float radius;
    int data;
    int count;
    int unk10;
    int extra;
};

struct RefObject {
    void* vtbl;
    unsigned short GetAllocationSize;
    short refCount;
    static void* operator new(std::size_t size) {
        RefObject* b = static_cast<RefObject*>(GetMemHolder()->allocateChunk(size));
        b->GetAllocationSize = static_cast<unsigned short>(size);
        return b;
    }
    static void operator delete(void* p, std::size_t size) {
        GetMemHolder()->freeChunk(p, size);
    }
};

struct ShapeBase : RefObject {
    int unk08;
    int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    ShapeBase(const ShapeData& d, int* extra, float radius);
};

extern void* ShapeDerived_vftable;
struct ShapeDerived : ShapeBase {
    ShapeDerived(const ShapeData& d, int* extra, float radius) : ShapeBase(ShapeData(d), extra, radius) {
        vtbl = &ShapeDerived_vftable;
    }
};

struct ShapeOwner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void SetShape(RefObject* shape);
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8();
    virtual void ApplyParam(ShapeParam* p);
    void CreateShapeAndApplyParam(ShapeParam* p);
};

// Builds a ShapeDerived from the ShapeParam's data, count, radius and extra, sets it on the owner, releases the reference, then applies the param.
// @fnv 0x00cd7d60
void ShapeOwner::CreateShapeAndApplyParam(ShapeParam* apParam) {
    MemClassGuard guard(0x10);
    ShapeData d;
    d.count = apParam->count;
    d.stride = 0x10;
    d.data = apParam->data;
    ShapeDerived* shape = new ShapeDerived(d, &apParam->extra, apParam->radius);
    SetShape(shape);
    reinterpret_cast<::hkReferencedObjectC905 *>((shape))->FUN_00c905b0();
    ApplyParam(apParam);
}
}  // namespace fnv_00cd7d60

namespace fnv_00cd7e80 {
extern unsigned int DAT_0126869c;

struct FUN_00c87c30_owner {
    FUN_00c87c30_owner();
    virtual void unkB0();
    ~FUN_00c87c30_owner();
    unsigned int m_04;
    unsigned int m_08;
};

struct ChainA_cls : public FUN_00c87c30_owner {
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls() {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls {
    virtual void unkB1();
    ChainB_cls() {
        DAT_01268274 += 1;
    }
};

struct ChainC_cls : public ChainB_cls {
    virtual void unkC2();
    ChainC_cls() {
        DAT_01268250 += 1;
    }
};

struct ChainD_cls : public ChainC_cls {
    virtual void unkD3();
    ChainD_cls() {
        DAT_0126869c += 1;
    }
};

struct FUN_00cd7e80 : public ChainD_cls {
    virtual void unkE4();
    FUN_00cd7e80(unsigned int a);
};

// Runs CreateShapeAndApplyParam with a, then increments DAT_0126869c.
// @fnv 0x00cd7e80
FUN_00cd7e80::FUN_00cd7e80(unsigned int auiValue) {
    reinterpret_cast<::fnv_00cd7d60::ShapeOwner *>(this)->CreateShapeAndApplyParam((::fnv_00cd7d60::ShapeParam *)(auiValue));
    DAT_0126869c += 1;
}
}  // namespace fnv_00cd7e80

extern int DAT_012686e8;

// @fnv 0x00cd7f20
int* __cdecl FUN_00cd7f20()
{
    return &DAT_012686e8;
}

namespace fnv_00cd8820 {
extern "C" int DAT_010cb644;

struct FUN_00cd8820_Block128 {
    unsigned int m_auiBitFieldWords[32];
};

struct FUN_00cd8820_Vec4 {
    unsigned int m_uiX;
    unsigned int m_uiY;
    unsigned int m_uiZ;
    unsigned int m_w;
};

class FUN_00cd8820_cls {
public:
    void* m_pVtable;
    unsigned short m_04;
    unsigned short m_06;
    unsigned int m_08;
    unsigned int m_0c;
    FUN_00cd8820_Block128 m_10;
    float m_90;
    float m_94;
    unsigned int m_98;
    unsigned int m_9c;
    FUN_00cd8820_Vec4 m_a0;
    float m_b0;
    unsigned char m_b4;
    unsigned char m_b5;
    unsigned char m_b6;
    unsigned char m_b7;
    unsigned int m_b8;
    unsigned int m_bc;
    FUN_00cd8820_Vec4 m_c0;
    FUN_00cd8820_Vec4 m_d0;
    FUN_00cd8820_Vec4 m_e0;
    FUN_00cd8820_cls(const FUN_00cd8820_Block128* src);
};

// Initializes the object: sets the vtable, copies the 128-byte block and a vector from src, zeroes floats and bytes, and copies three vectors from DAT_01267e30.
// @fnv 0x00cd8820
FUN_00cd8820_cls::FUN_00cd8820_cls(const FUN_00cd8820_Block128* apSource) {
    m_pVtable = (void*)&DAT_010cb644;
    m_06 = 1;
    m_10 = *apSource;
    m_90 = 0.0f;
    m_94 = 0.0f;
    m_a0 = *(const FUN_00cd8820_Vec4*)((const char*)apSource + 0x30);
    m_b0 = 0.0f;
    m_b4 = 0;
    m_c0 = *(const FUN_00cd8820_Vec4*)&(*reinterpret_cast<unsigned int *>(&::DAT_01267e30));
    m_d0 = *(const FUN_00cd8820_Vec4*)&(*reinterpret_cast<unsigned int *>(&::DAT_01267e30));
    m_e0 = *(const FUN_00cd8820_Vec4*)&(*reinterpret_cast<unsigned int *>(&::DAT_01267e30));
}
}  // namespace fnv_00cd8820


class FUN_00cd8a10_cls {
public:
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
    unsigned char m_60;
    unsigned char unk61;
    unsigned char unk62;
    unsigned char unk63;
    unsigned int m_64;
    float m_68;
    float m_6c;
    float m_70;
    float m_74;
    float m_78;
    float m_7c;
    unsigned int m_80;
    unsigned char m_84;

    FUN_00cd8a10_cls* InitializeDefaults();
};

// Sets the object's default values: m_68 from DAT_0101df44, m_60 to 1, several floats to 1.0f, and m_64, m_80, m_84 to 0, then returns this.
// @fnv 0x00cd8a10
FUN_00cd8a10_cls* FUN_00cd8a10_cls::InitializeDefaults()
{
    m_68 = DAT_0101df44;
    m_60 = 1;
    m_6c = 1.0f;
    m_64 = 0;
    m_70 = 1.0f;
    m_74 = 1.0f;
    m_78 = 1.0f;
    m_7c = 1.0f;
    m_80 = 0;
    m_84 = 0;
    return this;
}

// FUN_00cd9ed0 : sets a byte flag through its first argument.
//   mov eax,[esp+4] / mov byte ptr [eax],1 / ret 8
// @fnv 0x00cd9ed0
void FUN_00cd9ed0(unsigned char* flag, int unused) {
    *flag = 1;
}

struct FUN_00cd9ee0_info {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_uiItemCount;
};

class FUN_00cd9ee0_cls {
public:
    FUN_00cd9ee0_info* m_pObjectInfo;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int* m_pEntryData;
    int unk20;
    int unk24;
    unsigned char m_flag28;
    unsigned char m_flag29;
    void FUN_00cd9ee0();
};

// @fnv 0x00cd9ee0
void FUN_00cd9ee0_cls::FUN_00cd9ee0() {
    int count = m_pObjectInfo->m_uiItemCount;
    for (int i = 0; i < count; ++i) {
        m_pEntryData[i] = 3;
    }
    m_flag28 = 0;
    m_flag29 = 0;
}

struct FUN_00cd9f10_cls {
    void** m_ppVirtualMethodTable;
    void* m_pData04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int* m_pArr1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned char m_28;
    unsigned char m_29;
    void FUN_00cd9f10(void** p);
};


// @fnv 0x00cd9f10
void FUN_00cd9f10_cls::FUN_00cd9f10(void** p) {
    int count = (int)m_ppVirtualMethodTable[7];
    ::FUN_00cb1260(m_pData04, *p, count * 48);
    for (int i = 0; i < count; i++) {
        m_pArr1C[i] = 2;
    }
    m_29 = 1;
    *(volatile unsigned char*)&m_28 = 0;
}

class FUN_00cd9f60_cls {
public:
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void* m_10;
    unsigned int unk14;
    unsigned int unk18;
    int* m_1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned char m_28;
    unsigned char m_29;
    void FUN_00cd9f60(int* p);
};


// @fnv 0x00cd9f60
void FUN_00cd9f60_cls::FUN_00cd9f60(int* p)
{
    void** vt = *(void***)this;
    int count = *(int*)((char*)vt + 0x1c);
    ::FUN_00cb1260(m_10, (const void *)(*p), (unsigned int)(count * 3 * 16));
    int i = 0;
    unsigned char zero = 0;
    if (count > 0) {
        do {
            m_1c[i] = 1;
            ++i;
        } while (i < count);
    }
    *(volatile unsigned char*)&m_29 = zero;
    *(volatile unsigned char*)&m_28 = 1;
}

struct FlagTableOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int m_uiItemCount;
};

class FUN_00cd9fe0_cls
{
public:
    FlagTableOwner* m_pSharedOwner;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_10;
    unsigned int unk14;
    unsigned int unk18;
    int* m_pFlags;
    unsigned int unk20;
    unsigned int unk24;
    unsigned char m_28;
    unsigned char m_29;

    void* FUN_00cd9fe0();
};

// @fnv 0x00cd9fe0
void* FUN_00cd9fe0_cls::FUN_00cd9fe0()
{
    int count = m_pSharedOwner->m_uiItemCount;
    for (int i = 0; i < count; ++i)
    {
        m_pFlags[i] = 1;
    }
    m_29 = 0;
    m_28 = 1;
    return &m_10;
}

class FUN_00cda010_owner {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int m_iArrayLength;
};

class FUN_00cda010_cls {
public:
    FUN_00cda010_owner* m_pSharedOwner;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int* m_pFlags;
    unsigned int unk20;
    unsigned int unk24;
    unsigned char m_bCheck28;
    unsigned char m_bCheck29;
    bool* CheckFlagCombinations(bool* result);
};

// @fnv 0x00cda010
bool* FUN_00cda010_cls::CheckFlagCombinations(bool* result) {
    int count = m_pSharedOwner->m_iArrayLength;
    int i = 0;
    for (i = 0; i < count; i++) {
        unsigned int v = m_pFlags[i];
        if ((v & 1) != 0 && (v & 2) != 0) {
            goto fail;
        }
    }
    if (m_bCheck29 != 0) {
        for (i = 0; i < count; i++) {
            if ((m_pFlags[i] & 1) != 0) {
                goto fail;
            }
        }
    }
    if (m_bCheck28 != 0) {
        for (i = 0; i < count; i++) {
            if ((m_pFlags[i] & 2) != 0) {
                goto fail;
            }
        }
    }
    *result = true;
    return result;
fail:
    *result = false;
    return result;
}

struct hkMemoryAllocator;

struct NineIntegerRecord {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};

NineIntegerRecord& __cdecl GetMemoryRouter();

struct HavokArrayUtilities
{
    static void __cdecl GrowArrayCapacity(hkMemoryAllocator& alloc, void* array, int capacity, int elemSize);
};

struct RouterHeapAllocatorProvider {
    hkMemoryAllocator& get() { return GetMemoryRouter().heap(); }
};

template <class T>
struct hkArr {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void GrowArrayCapacity(hkMemoryAllocator& alloc, int n) {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = cap * 2;
            int newSize = n < cap2 ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }

    void _setSize(hkMemoryAllocator& alloc, int n) {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }

    void _setSize(hkMemoryAllocator& alloc, int n, T fill) {
        GrowArrayCapacity(alloc, n);
        int num = n - m_iElementCount;
        T* p = m_data + m_iElementCount;
        for (int i = 0; i < num; i++) {
            p[i] = fill;
        }
        m_iElementCount = n;
    }

    void _reserveExactly(hkMemoryAllocator& alloc, int n) {
        if (getCapacity() < n) {
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), n, sizeof(T));
        }
    }

    void SetSizeAndGrow(int n) { _setSize(RouterHeapAllocatorProvider().get(), n); }
    void SetSizeAndGrow(int n, T fill) { _setSize(RouterHeapAllocatorProvider().get(), n, fill); }
    void reserveExactly(int n) { _reserveExactly(RouterHeapAllocatorProvider().get(), n); }
};

struct Elem30 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
};

struct SolverInfo {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18;
    int m_iCapacityFlags;
    int unk20; int unk24; int unk28; int unk2C; int unk30;
    int m_numWords;
};

struct SolverBuffers {
    SolverInfo* m_info;
    hkArr<Elem30> m_arrayA;
    hkArr<Elem30> m_arrayB;
    hkArr<int> m_arrayC;
    int unk28;
    hkArr<unsigned int> m_bits;

    void InitBuffers(int mode, int unused, int arg);
};

// @fnv 0x00cdb150
void SolverBuffers::InitBuffers(int mode, int unused, int arg)
{
    int n = m_info->m_iCapacityFlags;
    m_arrayB.SetSizeAndGrow(n);
    m_arrayA.SetSizeAndGrow(n);
    m_arrayC.SetSizeAndGrow(n);
    if (mode == 1) {
        reinterpret_cast<::FUN_00cd9f10_cls *>(this)->FUN_00cd9f10((void **)(arg));
    } else {
        reinterpret_cast<::FUN_00cd9f60_cls *>(this)->FUN_00cd9f60((int *)(arg));
    }
    m_bits.reserveExactly((m_info->m_numWords + 3) & ~3);
    m_bits.SetSizeAndGrow(m_info->m_numWords, 0);
}

struct FUN_00cdb2a0_cls {
    volatile unsigned int m_i00;
    volatile unsigned int m_i04;
    volatile unsigned int m_i08;
    volatile unsigned int m_i0c;
    volatile unsigned int m_i10;
    volatile unsigned int m_i14;
    volatile unsigned int m_i18;
    volatile unsigned int m_i1c;
    volatile unsigned int m_i20;
    volatile unsigned int m_i24;
    volatile unsigned int m_i28;
    volatile unsigned int m_i2c;
    volatile unsigned int m_i30;
    volatile unsigned int m_i34;

    FUN_00cdb2a0_cls* FUN_00cdb2a0(unsigned int a1, unsigned int a2, unsigned int a3);
};

// @fnv 0x00cdb2a0
FUN_00cdb2a0_cls* FUN_00cdb2a0_cls::FUN_00cdb2a0(unsigned int a1, unsigned int a2, unsigned int a3)
{
    m_i00 = a2;
    m_i04 = 0;
    m_i08 = 0;
    m_i0c = 0x80000000;
    m_i10 = 0;
    m_i14 = 0;
    m_i18 = 0x80000000;
    m_i1c = 0;
    m_i20 = 0;
    m_i24 = 0x80000000;
    m_i2c = 0;
    m_i30 = 0;
    m_i34 = 0x80000000;
    reinterpret_cast<::SolverBuffers *>(this)->InitBuffers(a1, a2, a3);
    return this;
}

struct S_00cdb2f0_Arr {
    int* data;
    int size;
    unsigned int cap;
    S_00cdb2f0_Arr() : data(0), size(0), cap(0x80000000) {}
};
struct FUN_00cdb2f0 {
    int unk00;
    S_00cdb2f0_Arr a04;
    S_00cdb2f0_Arr a10;
    S_00cdb2f0_Arr a1c;
    int unk28;
    S_00cdb2f0_Arr a2c;
    FUN_00cdb2f0(int arg1, int arg2, int arg3, int arg4);
};

// Initialises unk00 from arg2 and calls InitBuffers with arg1, arg2 and a three-element array built from arg3 and arg4.
// @fnv 0x00cdb2f0
FUN_00cdb2f0::FUN_00cdb2f0(int arg1, int aiValue, int aiFirst, int aiSecond) : unk00(aiValue)
{
    int values[3];
    values[0] = aiFirst;
    values[1] = aiSecond;
    values[2] = aiSecond | 0x80000000u;
    reinterpret_cast<::SolverBuffers *>(this)->InitBuffers(arg1, aiValue, (int)(values));
}

class FUN_00cdb3d0_cls {
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
	int m_28;
	void FUN_00cdb3d0(int value);
};

// @fnv 0x00cdb3d0
void FUN_00cdb3d0_cls::FUN_00cdb3d0(int value)
{
	m_28 = value;
}

namespace fnv_00cdb6f0 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    AudioAllocator* m_pAllocator;
};


struct FUN_00cdb6f0_sub {
};

struct FUN_00cdb6f0_cls {
    void* m_pData4;
    int m_iCount4;
    unsigned int m_uCap4;
    void* m_pData3;
    int m_iCount3;
    unsigned int m_uCap3;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCap2;
    FUN_00cdb6f0_sub* m_pSub;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCap1;

    void ClearArrays();
};

// Resets m_pSub, then frees each of the four arrays through the audio allocator and clears its data pointer, count and capacity.
// @fnv 0x00cdb6f0
void FUN_00cdb6f0_cls::ClearArrays()
{
    reinterpret_cast<::hkReferencedObjectC905 *>((m_pSub))->FUN_00c905b0();

    AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uCap1 = m_uCap1;
    m_iCount1 = 0;
    if ((uCap1 & 0x80000000u) == 0) {
        pAllocator->FreeArray(m_pData1, (uCap1 & 0x3fffffffu) * 2);
    }
    m_pData1 = 0;
    m_uCap1 = 0x80000000u;

    AudioHolder* pHolder2 = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
    unsigned int uCap2 = m_uCap2;
    m_iCount2 = 0;
    if ((uCap2 & 0x80000000u) == 0) {
        pAllocator2->FreeArray(m_pData2, (uCap2 & 0x3fffffffu) * 64);
    }
    m_pData2 = 0;
    m_uCap2 = 0x80000000u;

    AudioHolder* pHolder3 = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator3 = pHolder3->m_pAllocator;
    unsigned int uCap3 = m_uCap3;
    m_iCount3 = 0;
    if ((uCap3 & 0x80000000u) == 0) {
        pAllocator3->FreeArray(m_pData3, (uCap3 & 0x3fffffffu) * 4);
    }
    m_pData3 = 0;
    m_uCap3 = 0x80000000u;

    AudioHolder* pHolder4 = static_cast<AudioHolder*>(::FUN_00c85750());
    AudioAllocator* pAllocator4 = pHolder4->m_pAllocator;
    unsigned int uCap4 = m_uCap4;
    m_iCount4 = 0;
    if ((uCap4 & 0x80000000u) == 0) {
        pAllocator4->FreeArray(m_pData4, (uCap4 & 0x3fffffffu) * 48);
    }
    m_pData4 = 0;
    m_uCap4 = 0x80000000u;
}
}  // namespace fnv_00cdb6f0

namespace fnv_00cde880 {
struct FUN_00cde880_cls {
    unsigned short* m_data;
    int m_len;
    unsigned int m_cap;

    void ReplaceRange(void* owner, int pos, int nRemove, const unsigned short* src, int nInsert);
};


// Grows the buffer if needed, shifts the tail right by nInsert-nRemove elements, copies nInsert elements from src at pos, and updates m_len.
// @fnv 0x00cde880
void FUN_00cde880_cls::ReplaceRange(void* owner, int pos, int nRemove, const unsigned short* src, int nInsert)
{
    int len = m_len;

    int iNewLength = len - nRemove + nInsert;
    int iTailCount = len - pos - nRemove;
    int cap = (int)(m_cap & 0x3fffffffu);
    if (cap < iNewLength) {
        int g = cap * 2;
        if (iNewLength >= g) {
            g = iNewLength;
        }
        ::FUN_00c908c0((::SpawnedObject *)(owner), (::SpawnedArray *)(::fnv_00cde880::FUN_00cde880_cls *)(this), g, 2);
    }
    ::FUN_00d2cc70(m_data + pos + nInsert, (void *)(m_data + pos + nRemove), (unsigned int)iTailCount * 2);
    unsigned short* dst = m_data + pos;
    for (int i = 0; i < nInsert; i++) {
        dst[i] = src[i];
    }
    m_len = iNewLength;
}
}  // namespace fnv_00cde880

struct CallTarget_00cde880 { int ReplaceRange(int, int, int, int, int); };
struct SearchObject {
    int FUN_00cde920(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00cde920
int SearchObject::FUN_00cde920(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int uiCallResult = (unsigned int)((CallTarget_00cde880*)this)->ReplaceRange((int)arg0, (int)arg1, (int)0u, (int)arg2, (int)arg3);
    return (int)uiCallResult;
}

class FUN_00cde940_cls {
public:
    void FUN_00cde940(intptr_t p1, int p2, intptr_t p3);
};

// @fnv 0x00cde940
void FUN_00cde940_cls::FUN_00cde940(intptr_t p1, int p2, intptr_t p3)
{
    reinterpret_cast<::SearchObject *>((this))->FUN_00cde920(p1, p2, p3, 1);
}

struct FUN_00cdea80_cls {
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
    int m_e8;
    int FUN_00cdea80();
};

// @fnv 0x00cdea80
int FUN_00cdea80_cls::FUN_00cdea80() {
    return m_e8;
}

class FUN_00cdeaa0_cls {
public:
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
    unsigned int m_iE4;
    unsigned int FUN_00cdeaa0();
};
// @fnv 0x00cdeaa0
unsigned int FUN_00cdeaa0_cls::FUN_00cdeaa0() { return m_iE4; }

struct FUN_00cdeac0_cls {
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
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char m_bA2;
    unsigned char* FUN_00cdeac0(unsigned char* pOut);
};

// @fnv 0x00cdeac0
unsigned char* FUN_00cdeac0_cls::FUN_00cdeac0(unsigned char* pOut)
{
    *pOut = m_bA2;
    return pOut;
}

class RefObj {
public:
    RefObj() { m_sReferenceCount = 1; }
    virtual void v0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

class RangeBase : public RefObj {
public:
    RangeBase() { m_bEnableState = false; }
    virtual void v0();
    struct HkBool { char m_cBooleanValue; HkBool() {} HkBool(bool b) { m_cBooleanValue = (char)b; } HkBool& operator=(bool b) { m_cBooleanValue = (char)b; return *this; } } m_bEnableState;
};

class FUN_00cdf560 : public RangeBase {
public:
    FUN_00cdf560(int iUnused);
    virtual void v0();
    float m_fMinimum;
    float m_fMaximum;
    float m_fFactor;
    float m_fScaleA;
    float m_fExponent;
    float m_fScaleB;
};

// Initializes the range bounds to -1000000 and 1000000, enables the range flag, and sets factor, scale and exponent defaults.
// @fnv 0x00cdf560
FUN_00cdf560::FUN_00cdf560(int iUnused)
{
    m_fMinimum = -1000000.0f;
    m_fMaximum = 1000000.0f;
    m_bEnableState = true;
    m_fFactor = 0.8f;
    m_fScaleA = 1.0f;
    m_fScaleB = 1.0f;
    m_fExponent = 2.0f;
}

struct CDF760FinishFlag {
    int m_bFinishing;
};

struct CDF760Member {
    int unk00;
    int unk04;
    void* m_pvOwner;


    CDF760Member(CDF760FinishFlag flag) {
        if (flag.m_bFinishing)
            reinterpret_cast<::FUN_00d21ce0_cls *>(this)->FUN_00d21ce0(m_pvOwner);
    }
};

class FUN_00cdf760 {
public:
    int unk04;
    int unk08;
    int unk0C;
    CDF760Member m_kMember;

    FUN_00cdf760(CDF760FinishFlag flag);
    virtual void vfunc00();
};

// @fnv 0x00cdf760
FUN_00cdf760::FUN_00cdf760(CDF760FinishFlag flag) : m_kMember(flag) {
    if (flag.m_bFinishing)
        reinterpret_cast<::FUN_00d21ce0_cls *>(&(m_kMember))->FUN_00d21ce0(this);
}


struct BCC2950AllocTagScope {
    int m_iSaved;

    BCC2950AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCC2950AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class BCC2950StringArray {
public:
    virtual ~BCC2950StringArray();
    void SetSize(unsigned int uiMaxSize);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement) { return SetAtGrow(m_usSize, pcElement); }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcCC2950Name;


class FUN_00cc2950_cls {
public:
    void AddNameToViewerStrings(BCC2950StringArray* pkArray);
};

// Sets an allocation tag, appends the base viewer strings, then adds the string returned by FUN_00a7d330(g_pcCC2950Name) to the array.
// @fnv 0x00cc2950
void FUN_00cc2950_cls::AddNameToViewerStrings(BCC2950StringArray* pkArray)
{
    BCC2950AllocTagScope kScope(0x10);
    reinterpret_cast<::bhkViewerObject *>(this)->FUN_00c9ed30((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(pkArray));
    char* pcName = FUN_00a7d330(g_pcCC2950Name);
    pkArray->Add(pcName);
}

struct S_arg
{
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00C;
    unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01C;
    unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02C;
    unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03C;
    unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04C;
    unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05C;
    unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06C;
    unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07C;
    unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08C;
    unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09C;
    unsigned int unk0A0; unsigned int unk0A4; unsigned int unk0A8; unsigned int unk0AC;
    unsigned int unk0B0; unsigned int unk0B4; unsigned int unk0B8; unsigned int unk0BC;
    unsigned int unk0C0; unsigned int unk0C4; unsigned int unk0C8; unsigned int unk0CC;
    unsigned int unk0D0; unsigned int unk0D4; unsigned int unk0D8; unsigned int unk0DC;
    unsigned int unk0E0; unsigned int unk0E4; unsigned int unk0E8; unsigned int unk0EC;
    unsigned int unk0F0; unsigned int unk0F4; unsigned int unk0F8; unsigned int unk0FC;
    unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10C;
    unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11C;
    unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12C;
    unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13C;
    unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14C;
    unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15C;
    unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16C;
    unsigned int unk170; unsigned int unk174; unsigned int unk178; unsigned int unk17C;
    unsigned int unk180; unsigned int unk184; unsigned int unk188; unsigned int unk18C;
    unsigned int unk190; unsigned int unk194; unsigned int unk198; unsigned int unk19C;
    unsigned int unk1A0; unsigned int unk1A4; unsigned int unk1A8; unsigned int unk1AC;
    unsigned int unk1B0; unsigned int unk1B4; unsigned int unk1B8; unsigned int unk1BC;
    unsigned int unk1C0; unsigned int unk1C4; unsigned int unk1C8; unsigned int unk1CC;
    unsigned int unk1D0; unsigned int unk1D4; unsigned int unk1D8; unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1E5;
};

struct S_res
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
};

class C
{
public:
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v0A();
    virtual void* v0B();
    virtual void* v0C();
    virtual void* v0D();
    virtual void* v0E();
    virtual void* v0F();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v1A();
    virtual void* v1B();
    virtual void* v1C();
    virtual void* v1D();
    virtual void* v1E();
    virtual void* v1F();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29();
    virtual void* v2A();
    virtual void* v2B();
    virtual void* v2C();
    virtual S_res* v45(S_arg** out);
    void ProcessAndByteSwapResult(S_arg* arg);
};

// Calls FUN_00c8a7a0 on arg, then unless arg->m_1E5 is 1, obtains a result via v45 and byte-swaps its fields m_10 through m_38.
// @fnv 0x00cc2dc0
void C::ProcessAndByteSwapResult(S_arg* arg)
{
    reinterpret_cast<::FUN_00c8a7a0_cls *>(this)->FUN_00c8a7a0((volatile unsigned int)(arg));
    if (arg->m_1E5 == 1)
        return;
    S_arg* out;
    volatile S_res* r = v45(&out);
    r->m_10 = _byteswap_ulong(r->m_10);
    r->m_14 = _byteswap_ulong(r->m_14);
    r->m_18 = _byteswap_ulong(r->m_18);
    r->m_1C = _byteswap_ulong(r->m_1C);
    r->m_20 = _byteswap_ulong(r->m_20);
    r->m_24 = _byteswap_ulong(r->m_24);
    r->m_28 = _byteswap_ulong(r->m_28);
    r->m_2C = _byteswap_ulong(r->m_2C);
    r->m_30 = _byteswap_ulong(r->m_30);
    r->m_34 = _byteswap_ulong(r->m_34);
    r->m_38 = _byteswap_ulong(r->m_38);
}

inline void CC2E50Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}

struct CC2E50Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_ul10;
    unsigned long m_ul14;
    unsigned long m_ul18;
    unsigned long m_ul1C;
    unsigned long m_ul20;
    unsigned long m_ul24;
    unsigned long m_ul28;
    unsigned long m_ul2C;
    unsigned long m_ul30;
    unsigned long m_ul34;
    unsigned long m_ul38;
};

__forceinline void CC2E50SwapData(CC2E50Data* pkData)
{
    CC2E50Swap(pkData->m_ul10);
    CC2E50Swap(pkData->m_ul14);
    CC2E50Swap(pkData->m_ul18);
    CC2E50Swap(pkData->m_ul1C);
    CC2E50Swap(pkData->m_ul20);
    CC2E50Swap(pkData->m_ul24);
    CC2E50Swap(pkData->m_ul28);
    CC2E50Swap(pkData->m_ul2C);
    CC2E50Swap(pkData->m_ul30);
    CC2E50Swap(pkData->m_ul34);
    CC2E50Swap(pkData->m_ul38);
}

struct CC2E50Stream {
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
    bool m_bLittleEndian;
};

class CC2E50Object {
public:
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual CC2E50Data* GetData(char* pcUnused);

    void FUN_00cc2e50(CC2E50Stream* pkStream);
};

// Gets the data, byte-swaps it when the stream is not little-endian, calls SaveBase, then swaps it back.
// @fnv 0x00cc2e50
void CC2E50Object::FUN_00cc2e50(CC2E50Stream* pkStream)
{
    char m_ucType;
    CC2E50Data* pkData = GetData(&m_ucType);
    if (pkStream->m_bLittleEndian != 1)
        CC2E50SwapData(pkData);
    reinterpret_cast<::RefChainOwner *>(this)->DispatchChainNodes((::Dispatcher *)(pkStream));
    if (pkStream->m_bLittleEndian != 1)
        CC2E50SwapData(pkData);
}

struct CC3840Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    float m_fSpinRate;
    float m_fGain;
};
extern const char* g_pcCC3840Name;

class CC3840Base {
public:
};

class CC3840Node : public CC3840Base {
public:
    int unk00;
    int unk04;
    CC3840Data* m_pUserData;

    static float GetSpinRate(CC3840Node* p) { return (p && p->m_pUserData) ? p->m_pUserData->m_fSpinRate : 0.0f; }
    static float GetGain(CC3840Node* p) { return (p && p->m_pUserData) ? p->m_pUserData->m_fGain : 0.0f; }
    void FUN_00cc3840(BCC1F80StringArray* pkArray);
};

// Collects base names, then adds the CC3840 name plus "SpinRate" and "Gain" entries with this node's values to the array.
// @fnv 0x00cc3840
void CC3840Node::FUN_00cc3840(BCC1F80StringArray* pkArray)
{
    TlsHeapGuard kGuard;
    reinterpret_cast<::Wrapper86b80 *>(this)->FUN_00c86b80((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(pkArray));
    pkArray->Add(FUN_00a7d330(g_pcCC3840Name));
    pkArray->Add(FUN_00a7d550("SpinRate", GetSpinRate(this)));
    pkArray->Add(FUN_00a7d550("Gain", GetGain(this)));
}

struct BinaryInput {
 int unk00; unsigned int position;
 unsigned int (__cdecl* reader)(BinaryInput*,void*,unsigned int,unsigned int*,unsigned int);
 void Read(void* dst,unsigned int size) {
  unsigned int componentSize=size;
  position+=reader(this,dst,size,&componentSize,1);
 }
};
struct LoadStream {
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
BinaryInput* input;
};
struct ConstraintData {
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
};
struct ConstraintLoader {
 int unk00; ConstraintData* data;
 void FUN_00cc55a0(LoadStream*);
};
// Lazily create the Havok helper object; report the object size.


struct CC5AE0AllocTagScope {
    int m_iSaved;

    CC5AE0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CC5AE0AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

struct CC5AE0Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct CC5AE0MemoryRouter {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    CC5AE0Allocator* m_pStreamAllocator;

    CC5AE0Allocator& heap() { return *m_pStreamAllocator; }
};

inline CC5AE0MemoryRouter& CC5AE0GetMemoryRouter() { return *static_cast<CC5AE0MemoryRouter*>(::FUN_00c85750()); }

class CC5AE0Helper {
public:
    CC5AE0Helper();
    virtual ~CC5AE0Helper();

    static void* operator new(std::size_t nbytes)
    {
        CC5AE0Helper* p = static_cast<CC5AE0Helper*>(CC5AE0GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, std::size_t nbytes) { CC5AE0GetMemoryRouter().heap().ReleaseBlock(p, nbytes); }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};

class CC5AE0Owner {
public:
    int unk00;
    CC5AE0Helper* m_pkHelper;

    unsigned int EnsureHelperAllocated();
};

// Allocates m_pkHelper with new CC5AE0Helper if it is null, then returns sizeof(CC5AE0Helper).
// @fnv 0x00cc5ae0
unsigned int CC5AE0Owner::EnsureHelperAllocated()
{
    CC5AE0AllocTagScope kScope(0x10);
    if (!m_pkHelper)
        m_pkHelper = new CC5AE0Helper;
    return sizeof(CC5AE0Helper);
}

struct CC61F0BinaryStream {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl* m_pfnRead)(CC61F0BinaryStream* pThis, void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, 0, 0);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
template <class T> inline void CC61F0LoadBinary(CC61F0BinaryStream& kBinStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.BinaryRead(&value, uiSize, &uiSize, 1);
}
struct CC61F0Stream {
    void* m_pVtable;
    unsigned int m_uiNifVersion;
    int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020; int unk024;
    int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040; int unk044;
    int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060; int unk064;
    int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080; int unk084;
    int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0; int unk0A4;
    int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0; int unk0C4;
    int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0; int unk0E4;
    int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100; int unk104;
    int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120; int unk124;
    int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140; int unk144;
    int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C; int unk160; int unk164;
    int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; int unk180; int unk184;
    int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0; int unk1A4;
    int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC; int unk1C0; int unk1C4;
    int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC; int unk1E0; unsigned char unk1E4; unsigned char m_bLittleEndian; unsigned short unk1E6;
    int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200; int unk204;
    int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C; int unk220; int unk224;
    int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C; int unk240; int unk244;
    int unk248;
    CC61F0BinaryStream* m_pUnderlyingStream;
};
struct CC61F0Vector4 { float x; float y; float z; float w; };
struct CC61F0Rotation { CC61F0Vector4 m_kColumn0; CC61F0Vector4 m_kColumn1; CC61F0Vector4 m_kColumn2; };
struct CC61F0ConstraintData {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    CC61F0Rotation m_kRotA;
    CC61F0Rotation m_kRotB;
    int unk80; int unk84;
    float m_f88;
    float m_f8C;
    int unk90; int unk94; int unk98; int unk9C;
    float m_fA0;
    int unkA4; int unkA8; int unkAC;
    float m_fB0;
    float m_fB4;
};
struct CC61F0ConstraintBase {
    int unk00;
    CC61F0ConstraintData* m_pUserData;
};
struct FUN_00cc61f0_class : CC61F0ConstraintBase {
    void FUN_00cc61f0(CC61F0Stream& kStream);
};

struct CC63E0_Stream {
    void* m_ppVirtualMethodTable;
    unsigned int m_vContactPosition;
    void* m_pOwnerObject;
    unsigned int (__cdecl *m_write)(CC63E0_Stream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int count) {
        unsigned int actualCount = count;
        m_vContactPosition += m_write(this, data, count, &actualCount, 1);
    }
};
struct CC63E0_Context {
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC;
    int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC;
    int unk1E0;
    unsigned char m_1e4; unsigned char unk1E5; unsigned char unk1E6; unsigned char unk1E7;
    int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC;
    int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C;
    int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C;
    int unk240; int unk244; int unk248; int unk24C;
    CC63E0_Stream* m_stream;
};
struct CC63E0_Block {
    float m00; float m04; float m08; float m0C; float m10; float m14; float m18; float m1C; float m20; float m24; float m28; float m2C;
};
struct CC63E0_Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    CC63E0_Block m_20;
    CC63E0_Block m_50;
    int unk80; int unk84;
    int m_88; int m_8C;
    int unk90; int unk94; int unk98; int unk9C;
    int m_A0; int unkA4; int unkA8; int unkAC;
    int m_B0; int m_B4;
};
struct CC63E0_Obj {
    void* m_ppVirtualMethodTable;
    CC63E0_Data* m_data;
    void FUN_00cc63e0(CC63E0_Context* ctx);
};
// @fnv 0x00cc63e0
void CC63E0_Obj::FUN_00cc63e0(CC63E0_Context* ctx)
{
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((*(::S_00c8a280_Stream *)(ctx)));
    CC63E0_Data* d = m_data;
    if (ctx->m_1e4 != 1) {
        ::SwapEndianBlocks((unsigned int *)(::CC63E0_Block *)(&d->m_20));
        ::SwapEndianBlocks((unsigned int *)(::CC63E0_Block *)(&d->m_50));
    }
    ctx->m_stream->Write(&d->m_20, 0x30);
    ctx->m_stream->Write(&d->m_50, 0x30);
    ctx->m_stream->Write(&d->m_A0, 4);
    ctx->m_stream->Write(&d->m_B0, 4);
    ctx->m_stream->Write(&d->m_B4, 4);
    ctx->m_stream->Write(&d->m_88, 4);
    ctx->m_stream->Write(&d->m_8C, 4);
    if (ctx->m_1e4 != 1) {
        ::SwapEndianBlocks((unsigned int *)(::CC63E0_Block *)(&d->m_20));
        ::SwapEndianBlocks((unsigned int *)(::CC63E0_Block *)(&d->m_50));
    }
}

struct __declspec(novtable) ReferenceRoot78 {
    unsigned int unk04;
    unsigned int unk08;
    virtual ~ReferenceRoot78();
    ReferenceRoot78() { reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30(); }
};
struct ConstraintBase78 : ReferenceRoot78 {
    unsigned int data;
    ConstraintBase78() { data = 0; ++DAT_01268188; }
    virtual ~ConstraintBase78();
};
struct Constraint78 : ConstraintBase78 {
    Constraint78() { ++DAT_0126860c; }
    virtual ~Constraint78();
};
// Allocates and constructs a new Constraint78 object, returning the pointer.
// @fnv 0x00cc67a0
Constraint78* __cdecl CreateConstraint()
{
    return new Constraint78;
}

// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.


struct CC69D0AllocTagScope {
    int m_iSaved;

    CC69D0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CC69D0AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};


class CC69D0RefObject {
public:
    CC69D0RefObject();
    virtual ~CC69D0RefObject();


    int unk04;
    int unk08;
};

class CC69D0Shape : public CC69D0RefObject {
public:
    CC69D0Shape() : m_pUserData(0) { ++ms_iCount; }
    virtual ~CC69D0Shape();

    void* m_pUserData;

    static int ms_iCount;
};

class CC69D0ListShape : public CC69D0Shape {
public:
    CC69D0ListShape() { ++ms_iCount; }
    virtual ~CC69D0ListShape();

    static int ms_iCount;
};

class CC69D0Owner {
public:
    void AddShape(CC69D0Shape* pkShape, int iIndex);
    CC69D0Shape* CreateListShape(int iIndex);
};

// Allocates a new CC69D0ListShape under a lock and allocation tag, adds it to the owner at iIndex, and returns it.
// @fnv 0x00cc69d0
CC69D0Shape* CC69D0Owner::CreateListShape(int iIndex)
{
    CC69D0AllocTagScope kScope(0x10);
    ::FUN_00c876f0();
    CC69D0Shape* pkShape = new CC69D0ListShape;
    reinterpret_cast<::Owner89730 *>(this)->FUN_00c89730(pkShape, (::Process89730 *)(iIndex));
    ::FUN_00c87700();
    return pkShape;
}

extern int DAT_010c8ce4;

struct Child_00cc6ab0
{
    void* m_pVtable;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;


    Child_00cc6ab0()
        : m_08(1), m_0c(0), m_10(0)
    {
        m_pVtable = &DAT_010c8ce4;
        m_04 = 0;
    }
};

static __forceinline Child_00cc6ab0* Make_00cc6ab0(Child_00cc6ab0* obj)
{
    Child_00cc6ab0* p = (Child_00cc6ab0*)((char*)obj + 4);
    new (obj) Child_00cc6ab0();
    return p;
}

struct Owner_00cc6ab0
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_08;
    Child_00cc6ab0* m_0c;

    Child_00cc6ab0* FUN_00cc6ab0(bool* out);
};

// @fnv 0x00cc6ab0
Child_00cc6ab0* Owner_00cc6ab0::FUN_00cc6ab0(bool* out)
{
    TlsGuard_t guard((*reinterpret_cast<::TlsBlock_t *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4);
    bool created = (m_0c == 0);
    *out = created;
    if (created)
    {
        Child_00cc6ab0* obj = (Child_00cc6ab0*)((unsigned char *)(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::FUN_00cc2a00_alloc *>(&::g_memoryManager))))->FUN_00aa3e40(0x14)));
        Child_00cc6ab0* pChild;
        if (obj != 0)
            pChild = Make_00cc6ab0(obj);
        else
            pChild = 0;
        m_0c = pChild;
        if (m_08)
        {
            void* base = pChild ? (char*)pChild - 4 : 0;
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((void*)(base));
        }
    }
    return m_0c;
}

struct CC77E0Allocator {
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct CC77E0MemoryRouter {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    CC77E0Allocator* m_pStreamAllocator;

    CC77E0Allocator& heap() { return *m_pStreamAllocator; }
};

inline CC77E0MemoryRouter& hkMemoryRouterCC77() { return *static_cast<CC77E0MemoryRouter*>(::FUN_00c85750()); }


struct CC77E0AllocTagScope {
    int m_iSaved;

    CC77E0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CC77E0AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class CC77E0Child {
public:
    CC77E0Child();
    virtual ~CC77E0Child();

    static void* operator new(std::size_t uiSize) {
        void* p = hkMemoryRouterCC77().heap().AllocateMemoryBlock(uiSize);
        static_cast<CC77E0Child*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    int unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    int unkC8, unkCC;
};

class CC77E0Owner {
public:
    int unk00;
    CC77E0Child* m_pkChild;

    int EnsureChildAllocated();
};

// Creates m_pkChild with new if it is null, then returns sizeof(CC77E0Child).
// @fnv 0x00cc77e0
int CC77E0Owner::EnsureChildAllocated()
{
    CC77E0AllocTagScope kScope(0x10);
    if (!m_pkChild)
        m_pkChild = new CC77E0Child();
    return sizeof(CC77E0Child);
}

struct NiBinaryStream {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents) {
        unsigned int uiWritten = m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiWritten;
        return uiWritten;
    }
};
struct NiStreamView {
    char pad[0x250];
    NiBinaryStream* m_pBackingStream;
};
template <class T> inline void WriteBinaryArray(NiBinaryStream& kBinStream, const T* pValue, unsigned int uiNumEls) {
    unsigned int uiSize = sizeof(T);
    kBinStream.Write(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void SerializeValue(NiStreamView& kStream, const T& kValue) {
    WriteBinaryArray(*kStream.m_pBackingStream, &kValue, 1);
}
struct SaveMatrix { float m[16]; };
struct SaveData {
    char pad00[0x20];
    SaveMatrix kFirst;
    SaveMatrix kSecond;
    char pad60[2];
    bool bFlag;
    char padA3[9];
    void* pLinked;
    char padB0[4];
    unsigned int uiB4;
    char padB8[0x10];
    unsigned int uiC8;
    unsigned int uiCC;
};
struct FUN_00cc7bc0_shell {
    void* m_pVtable;
    SaveData* m_pData;
    void FUN_00cc7bc0(NiStreamView& kStream);
};
// @fnv 0x00cc7bc0
void FUN_00cc7bc0_shell::FUN_00cc7bc0(NiStreamView& kStream) {
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((::S_00c8a280_Stream &)(kStream));
    SaveData* pData = m_pData;
    SerializeValue(kStream, pData->kFirst);
    SerializeValue(kStream, pData->kSecond);
    SerializeValue(kStream, pData->uiC8);
    SerializeValue(kStream, pData->uiCC);
    SerializeValue(kStream, pData->uiB4);
    ::SaveShape((::C8A4B0Shape *)this, (*(::C8A4B0Stream *)(pData->pLinked)));
    if (pData->pLinked)
        SerializeValue(kStream, pData->bFlag);
}


struct BCC7F30AllocTagScope {
    int m_iSaved;

    BCC7F30AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCC7F30AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class BCC7F30Allocator {
public:
    virtual void VFunc00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* pvMem, int iNumBytes);
};

class BCC7F30Router {
public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    BCC7F30Allocator* m_pkHeap;

    BCC7F30Allocator& heap() { return *m_pkHeap; }
};

inline BCC7F30Router* BCC7F30GetRouter() { return static_cast<BCC7F30Router*>(::FUN_00c85750()); }

class BCC7F30ReferencedObject {
public:
    void* operator new(std::size_t uiNumBytes)
    {
        BCC7F30ReferencedObject* pkObject = static_cast<BCC7F30ReferencedObject*>(BCC7F30GetRouter()->heap().AllocateMemoryBlock(uiNumBytes));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiNumBytes;
        return pkObject;
    }
    void operator delete(void* pvMem)
    {
        BCC7F30ReferencedObject* pkObject = static_cast<BCC7F30ReferencedObject*>(pvMem);
        BCC7F30GetRouter()->heap().ReleaseBlock(pvMem, pkObject->m_usMemSizeAndFlags);
    }

    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class BCC7F30Shape : public BCC7F30ReferencedObject {
public:
    BCC7F30Shape();

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

class BCC7F30Wrapper {
public:
    void Init(BCC7F30Shape* pkShape, int iArg);
    void InitWithShape(BCC7F30Shape* pkShape, int iArg);
};

// Creates a BCC7F30Shape if pkShape is null, then calls Init with the shape and iArg inside an allocation-tag scope.
// @fnv 0x00cc7f30
void BCC7F30Wrapper::InitWithShape(BCC7F30Shape* pkShape, int iArg)
{
    BCC7F30AllocTagScope kScope(0x10);
    if (!pkShape)
        pkShape = new BCC7F30Shape;
    reinterpret_cast<::OwnerD500 *>(this)->FUN_00d50090((::FUN_00d50c90 *)(pkShape), iArg);
}

class BCC8950BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(BCC8950BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BCC8950Stream {
public:
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
    unsigned int m_uiFileVersion;
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCC8950BinaryStream* m_pUnderlyingStream;
};

template <class T>
inline void BCC8950BinaryStreamLoad(BCC8950BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void BCC8950LoadBinary(BCC8950Stream& kStream, T& value)
{
    BCC8950BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

struct BCC8950Transform {
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
};

struct BCC8950ConstraintData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BCC8950Transform m_kTransformA;
    BCC8950Transform m_kTransformB;
    int unk80;
    float m_fMinAngle;
    float m_fMaxAngle;
};

class BCC8950Base {
public:
};

class BCC8950Constraint : public BCC8950Base {
public:
    void FUN_00cc8950(BCC8950Stream& kStream);

    int unk00;
    BCC8950ConstraintData* m_pUserData;
};

// Lazily create the Havok helper object; report the object size.


struct CC9890AllocTagScope {
    int m_iSaved;

    CC9890AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CC9890AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

struct CC9890Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct CC9890MemoryRouter {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    CC9890Allocator* m_pStreamAllocator;

    CC9890Allocator& heap() { return *m_pStreamAllocator; }
};

inline CC9890MemoryRouter& CC9890GetMemoryRouter() { return *static_cast<CC9890MemoryRouter*>(::FUN_00c85750()); }

class CC9890Helper {
public:
    CC9890Helper();
    virtual ~CC9890Helper();

    static void* operator new(std::size_t nbytes)
    {
        CC9890Helper* p = static_cast<CC9890Helper*>(CC9890GetMemoryRouter().heap().AllocateMemoryBlock(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, std::size_t nbytes) { CC9890GetMemoryRouter().heap().ReleaseBlock(p, nbytes); }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
};

class CC9890Owner {
public:
    int unk00;
    CC9890Helper* m_pkHelper;

    unsigned int GetOrCreateHelperSize();
};

// Allocates a CC9890Helper with allocation tag 0x10 if m_pkHelper is null, then returns sizeof(CC9890Helper).
// @fnv 0x00cc9890
unsigned int CC9890Owner::GetOrCreateHelperSize()
{
    CC9890AllocTagScope kScope(0x10);
    if (!m_pkHelper)
        m_pkHelper = new CC9890Helper;
    return sizeof(CC9890Helper);
}

struct CcaArg {
    int unkCur;
    int unkValue;
    int uNewnk;
    int unk00C;
    int uTmpnk;
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
    unsigned char m_b1e4;
};

struct CcaRes {
    int unk;
    int unk04;
    void* m_08;
    unsigned int m_0c;
};

struct CcaOwner {
    virtual ~CcaOwner() {}
    virtual void vf();
    virtual void vfCur();
    virtual void vfValue();
    virtual void vNewf();
    virtual void vTmpf();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
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
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41(int a);
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual CcaRes* vf45(int& out);
};


struct FUN_00cca130_cls : CcaOwner {
    void ProcessArg(CcaArg* a1);
};

// @fnv 0x00cca130
void FUN_00cca130_cls::ProcessArg(CcaArg* a1)
{
    int flag;
    CcaRes* res = this->vf45(flag);
    if (a1->m_b1e4 != 1) {
        { unsigned int v = res->m_0c; res->m_0c = _byteswap_ulong(v); }
    }
    reinterpret_cast<::Owner *>((this))->FUN_00ca4f80((::Sink *)(a1));
    ::FUN_00cf0dc0((*(::CF4BC0Stream *)(a1)), (::TargetType *)(res->m_08));
    this->vf41(flag);
    if (!(unsigned char)flag && a1->m_b1e4 != 1) {
        { unsigned int v = res->m_0c; res->m_0c = _byteswap_ulong(v); }
    }
}

__declspec(thread) unsigned int DAT_0126fd98;

struct FUN_00cca450_param_item {
    void* unk00;
    void* unk04;
    struct FUN_00cca450_hook* unk08;
};
struct FUN_00cca450_hook {
};
struct FUN_00cca450_class {
    void FUN_00cca450(FUN_00cca450_param_item*);
};
// @fnv 0x00cca450
void FUN_00cca450_class::FUN_00cca450(FUN_00cca450_param_item* pItem)
{
    AutoMemContext context(0x10);
    if (pItem->unk08)
        reinterpret_cast<::hkReferencedObjectC905 *>((pItem->unk08))->FUN_00c905b0();
    reinterpret_cast<::FUN_00c876d0_cls *>(this)->TailOne((int)(pItem));
}

struct MoppCode570 {
 int unk00, unk04, unk08, unk0c;
 hkVector4 offset;
};
struct MoppData570 {
 int unk00, unk04, unk08, unk0c, unk10;
 MoppCode570* code;
};
struct MoppOwner570 {
 int unk00, unk04;
 MoppData570* data;
 void OutputMoppCodeInfo(StringArray403*);
};
// @fnv 0x00cca570
void MoppOwner570::OutputMoppCodeInfo(StringArray403* output) {
 AutoMemContext context(16);
 reinterpret_cast<::StringBuilder_ca5190 *>(this)->FUN_00ca5190((::NiStringArray *)(output));
 output->Add(FUN_00a7d330(*reinterpret_cast<const char* const*>(&::g_01268658)));
 MoppCode570* code = this && data ? data->code : 0;
 char buffer[32];
 ::FUN_00406d00(buffer, 32, "0x%8X", code);
 output->Add(::fnv_00a7d5e0::FUN_00a7d5e0("MoppCode", buffer));
 NiPoint3 point;
 ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&point)), (*(const ::hkVector4 *)(&code->offset)));
 output->Add(point.FUN_00a59af0("MoppCode Offset"));
}

typedef unsigned int CCADB0size_t;

struct CCADB0MemoryManager {
    void* Allocate(unsigned int uiSize);
};


struct CCADB0AllocTagScope {
    int m_iSaved;

    CCADB0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CCADB0AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};


struct CCADB0Child {
    CCADB0Child() throw()
        : m_pkOwnerManager(0), m_fScale(::DAT_010c72bc), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f), m_f20(0.0f), m_f24(0.0f),
          m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {
    }

    void* m_pkOwnerManager;
    float m_fScale;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

};

struct CCADB0Owner {
    int unk00;
    int unk04;
    void* m_pParentNode;
    CCADB0Child* m_pkChild;

    CCADB0Child* FUN_00ccadb0(bool* pbCreated);
};

// @fnv 0x00ccadb0
CCADB0Child* CCADB0Owner::FUN_00ccadb0(bool* pbCreated)
{
    CCADB0AllocTagScope kScope(0x10);
    *pbCreated = (m_pkChild == 0);
    if (*pbCreated) {
        m_pkChild = new CCADB0Child;
        if (m_pParentNode)
            ::CopyHingeVectors((::MyObj *)this, (int)(m_pkChild), {});
    }
    return m_pkChild;
}

extern int DAT_012686d0;

struct BccObj : S_00c87c30_Base {
    unsigned int m_14;
    BccObj() : S_00c87c30_Base() {
        m_pVtable = &DAT_01030bf4;
        unsigned int* q = &m_uiData1;
        q[0] = 0;
        q[1] = 0;
        DAT_012680f8 += 1;
        m_pVtable = &DAT_010c44e4;
        DAT_012686d0 += 1;
        m_pVtable = &DAT_010ca744;
        m_14 = 0;
        DAT_01268678 += 1;
    }
};

struct BccOwner {
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
    virtual void v49(BccObj* node, int a1);
    BccObj* CreateBccObj(int a1);
};

// Allocates a BccObj, passes it with a1 to v49, and returns the new object.
// @fnv 0x00ccbe10
BccObj* BccOwner::CreateBccObj(int a1) {
    TlsGuard_t guard((*reinterpret_cast<::TlsBlock_t *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4);
    FUN_00c876f0();
    BccObj* p = new BccObj();
    this->v49(p, a1);
    FUN_00c87700();
    return p;
}

struct MeshMetadata654;

struct Mesh654
{
    unsigned int vertexCount;
    float* vertices;
    unsigned int triangleCount;
    unsigned short* triangles;
    MeshMetadata654* metadata;
    void FUN_00ccc440(BCC9B80Stream&);
};

namespace fnv_00ccc7e0 {
struct MemoryManagerAllocHelper { void* Allocate(unsigned int size); };


static int GetMemContext() { return (*reinterpret_cast<int *>(&::currentAllocationContext)); }
static void SetMemContext(int context) { (*reinterpret_cast<int *>(&::currentAllocationContext)) = context; }

struct TlsPoolGuard {
    int m_iOld;
    TlsPoolGuard(int context) { m_iOld = GetMemContext(); SetMemContext(context); }
    ~TlsPoolGuard() { Leave(); }
    void Leave() { SetMemContext(m_iOld); }
};

struct LoadStream;
typedef int (__cdecl *LoadStreamReadFn)(LoadStream* stream, void* buffer, int elemSize, int* count, int flag);
struct LoadStream {
    int unk00;
    int m_iPosition;
    LoadStreamReadFn m_pfnRead;
    void ReadUInt(unsigned int* value) {
        int count = 4;
        int read = m_pfnRead(this, value, 4, &count, 1);
        m_iPosition += read;
    }
};

struct LoadContext {
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    LoadStream* m_pBinaryStream;
};

struct FiveIntegerLoadRecord {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FiveIntegerLoadRecord();
    ~FiveIntegerLoadRecord();
};

struct FUN_00ccc7e0_class {
    int unk00;
    int unk04;
    unsigned int m_uiCount;
    FiveIntegerLoadRecord* m_pEntries;
    void LoadEntries(LoadContext* ctx);
};


// Reads a count from the stream, allocates an array of entries, and loads each entry from the context.
// @fnv 0x00ccc7e0
void FUN_00ccc7e0_class::LoadEntries(LoadContext* ctx)
{
    TlsPoolGuard guard(16);
    ctx->m_pBinaryStream->ReadUInt(&m_uiCount);
    m_pEntries = new FiveIntegerLoadRecord[m_uiCount];
    for (unsigned int i = 0; i < m_uiCount; i++)
        reinterpret_cast<::Mesh654 *>(&(m_pEntries[i]))->FUN_00ccc440((*(::BCC9B80Stream *)(ctx)));
}
}  // namespace fnv_00ccc7e0

// SaveBinary of an element array: the count, then each element saves itself.

class CCC920BinaryStream {
public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(CCC920BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int (__cdecl *m_pfnWrite)(CCC920BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count) {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n, unsigned int uiComponentSize) {
        unsigned int size = uiComponentSize;
        return BinaryWrite(p, n, &size, 1);
    }
};

class CCC920Stream {
public:
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    CCC920BinaryStream* m_pBackingStream;
};

template <class T>
inline void CCC920BinaryStreamSave(CCC920BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1) {
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CCC920SaveBinary(CCC920Stream& kStream, const T& value) {
    CCC920BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

template <class T>
inline void CCC920SaveBinary(CCC920Stream& kStream, const T* pValues, unsigned int ItemUpdateArray) {
    CCC920BinaryStreamSave(*kStream.m_pBackingStream, pValues, ItemUpdateArray);
}

struct CCC920Element {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

};

class CCC920Array {
public:
    void* m_pVtbl;
    int unk04;
    unsigned int m_uiCount;
    CCC920Element* m_pkVertexElements;

    void FUN_00ccc920(CCC920Stream& kStream);
};

// Writes m_uiCount to the stream, then calls SaveBinary on each of the m_uiCount elements in the array.
// @fnv 0x00ccc920
void CCC920Array::FUN_00ccc920(CCC920Stream& kStream)
{
    CCC920SaveBinary(kStream, m_uiCount);
    for (unsigned int i = 0; i < m_uiCount; i++)
        reinterpret_cast<::S_00ccc620_Obj *>(&(m_pkVertexElements[i]))->FUN_00ccc620((::S_00ccc620_Stream &)(kStream));
}


class CCDE60MemContext {
public:
    CCDE60MemContext(int aiMemoryContext)
    {
        m_iPrevious = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~CCDE60MemContext() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iPrevious; }

    int m_iPrevious;
};


class CCDE60Object {
public:
    CCDE60Object();
    virtual ~CCDE60Object();


    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class CCDE60World {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void AddObject(CCDE60Object* pkObject, void* pvInfo);

    CCDE60Object* FUN_00ccde60(void* pvInfo);
};

// Creates a new CCDE60Object, registers it with AddObject using pvInfo, and returns it.
// @fnv 0x00ccde60
CCDE60Object* CCDE60World::FUN_00ccde60(void* pvInfo)
{
    CCDE60MemContext kContext(0x10);
    FUN_00c876f0();
    CCDE60Object* pkObject = new CCDE60Object;
    AddObject(pkObject, pvInfo);
    FUN_00c87700();
    return pkObject;
}

class AllocatorCCD {
public:
    virtual void vfn00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};

struct MemoryCCD {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    AllocatorCCD* m_pHeapAllocator;

    AllocatorCCD& heap() { return *m_pHeapAllocator; }
};

inline MemoryCCD* GetMemoryCCD() { return static_cast<MemoryCCD*>(::FUN_00c85750()); }


struct AllocTagScopeCCD {
    int m_iSaved;

    AllocTagScopeCCD(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~AllocTagScopeCCD() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class ReferencedObjectCCD {
public:
    static void* operator new(std::size_t uiSize)
    {
        ReferencedObjectCCD* pkObject = static_cast<ReferencedObjectCCD*>(GetMemoryCCD()->heap().AllocateMemoryBlock(uiSize));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return pkObject;
    }
    static void operator delete(void* pvMem);

    virtual ~ReferencedObjectCCD();


    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

struct VectorCCD {
    float x, y, z, w;
};

struct ShapeCinfoCCD {
    int m_iVertices;
    int m_iArrayCapacity;
    int m_iFlags;
};


class ShapeCCD : public ReferencedObjectCCD {
public:
    ShapeCCD(const ShapeCinfoCCD& kCinfo, const VectorCCD& m_kPoint2, float fRadius);

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
};

struct InfoCCD {
    int unk00;
    int unk04;
    int m_iVertices;
    int m_iArrayCapacity;
    int unk10;
    VectorCCD m_kHalfExtents;
};

class BodyCCD {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void SetShape(ShapeCCD* pkShape);
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void SetInfo(const InfoCCD* pkInfo);

    void SetShapeFromInfo(const InfoCCD* pkInfo);
};

// Builds a ShapeCCD from pkInfo's vertex count, id and half extents, assigns it via SetShape, releases it, then calls SetInfo(pkInfo).
// @fnv 0x00ccdf20
void BodyCCD::SetShapeFromInfo(const InfoCCD* pkInfo)
{
    AllocTagScopeCCD kScope(0x10);
    ShapeCinfoCCD kCinfo;
    kCinfo.m_iArrayCapacity = pkInfo->m_iArrayCapacity;
    kCinfo.m_iFlags = 0x10;
    kCinfo.m_iVertices = pkInfo->m_iVertices;
    ShapeCCD* pkShape = new ShapeCCD(kCinfo, pkInfo->m_kHalfExtents, ::DAT_010c72bc);
    SetShape(pkShape);
    reinterpret_cast<::hkReferencedObjectC905 *>((pkShape))->FUN_00c905b0();
    SetInfo(pkInfo);
}

struct CE340Allocator {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct CE340Router {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    CE340Allocator* m_pStreamAllocator;
    CE340Allocator& heap() { return *m_pStreamAllocator; }
};
inline CE340Router* CE340GetRouter() { return static_cast<CE340Router*>(::FUN_00c85750()); }

struct CE340Vec4 {
    float x, y, z, w;
};

template <class T>
struct CE340Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    CE340Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~CE340Array() { _clearAndDeallocate(CE340GetRouter()->heap()); }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void _clearAndDeallocate(CE340Allocator& alloc) {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc.ReleaseBlock(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void swap(CE340Array& a) {
        T* d = m_data; m_data = a.m_data; a.m_data = d;
        int s = m_iElementCount; m_iElementCount = a.m_iElementCount; a.m_iElementCount = s;
        int c = m_iCapacityState; m_iCapacityState = a.m_iCapacityState; a.m_iCapacityState = c;
    }
};

struct CE340Data {
    int unk00;
    int unk04;
    CE340Array<CE340Vec4> m_arr08;
    CE340Array<CE340Vec4> m_arr14;
};

typedef FUN_00ccd3a0_arg CE340Stream;


struct CE340Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B();
    virtual void v1C(); virtual void v1D(); virtual void v1E(); virtual void v1F();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28();
    virtual void SetFlag(bool flag);
    virtual void* GetContext();
    virtual void v2B(); virtual void v2C();
    virtual CE340Data* GetData(bool* flag);
    void SaveWithArrays(CE340Stream* stream);
};

// @fnv 0x00cce340
void CE340Obj::SaveWithArrays(CE340Stream* stream)
{
    bool flag;
    CE340Data* data = GetData(&flag);
    CE340Array<CE340Vec4> arrFirst;
    CE340Array<CE340Vec4> arrSecond;
    arrFirst.swap(data->m_arr08);
    arrSecond.swap(data->m_arr14);
    if (stream->m_1e4 != 1) {
        void* ctx = GetContext();
        ::FUN_00cf0930(data, (int)(ctx), (::Vector3 *)(::CE340Array< ::CE340Vec4> *)(&data->m_arr08));
        ::FUN_00cf0930(data, (int)(ctx), (::Vector3 *)(::CE340Array< ::CE340Vec4> *)(&data->m_arr14));
    }
    reinterpret_cast<::C9FC00Object *>(this)->FUN_00c9fc00((*(::C9FC00Stream *)(stream)));
    ::FUN_00cf0cf0((::S00cf0cf0_Obj *)(stream), (::S00cf0cf0_Arr *)(void *)(&arrFirst));
    ::FUN_00cf0cf0((::S00cf0cf0_Obj *)(stream), (::S00cf0cf0_Arr *)(void *)(&arrSecond));
    SetFlag(flag);
    if (!flag && stream->m_1e4 != 1) {
        void* ctx = GetContext();
        ::FUN_00cf0930(data, (int)(ctx), (::Vector3 *)(::CE340Array< ::CE340Vec4> *)(&data->m_arr08));
        ::FUN_00cf0930(data, (int)(ctx), (::Vector3 *)(::CE340Array< ::CE340Vec4> *)(&data->m_arr14));
    }
}

// Release the cached Havok data when requested.


struct CCE860AllocTagScope {
    int m_iSaved;

    CCE860AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CCE860AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class CCE860MemoryManager {
public:
};


class CCE860Data {
public:
    ~CCE860Data();
    int unk00;
};

class CCE860Owner {
public:
    int unk00;
    int unk04;
    int unk08;
    CCE860Data* m_pUserData;

    void ReleaseData(bool bRelease);
};

// If bRelease is set, deletes the owned CCE860Data object and clears the pointer, under an allocation-tag scope.
// @fnv 0x00cce860
void CCE860Owner::ReleaseData(bool bRelease)
{
    CCE860AllocTagScope kScope(0x10);
    if (bRelease) {
        delete m_pUserData;
        m_pUserData = 0;
    }
}

class ArgCCE;

class TargetCCE {
public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8C();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9C();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual bool Process(ArgCCE* pkArg);
};

struct LinkCCE {
    int unk00;
    int unk04;
    TargetCCE* m_pkTarget;
};

struct BodyCCE {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    LinkCCE* m_pkLink;
};

class BaseCCE {
public:
    bool Process(ArgCCE* pkArg);

    void* m_ppVirtualMethodTable;
    int unk04;
    BodyCCE* m_pkBody;
};

inline TargetCCE* GetTargetCCE(BaseCCE* pkObject)
{
    if (pkObject && pkObject->m_pkBody && pkObject->m_pkBody->m_pkLink)
        return pkObject->m_pkBody->m_pkLink->m_pkTarget;
    return 0;
}

class DerivedCCE : public BaseCCE {
public:
    bool ProcessWithTarget(ArgCCE* pkArg);
};

// @fnv 0x00cced60
bool DerivedCCE::ProcessWithTarget(ArgCCE* pkArg)
{
    bool bResult = ((bool)(::FUN_00c84ec0((void *)this)));
    if (bResult) {
        TargetCCE* pkTarget = GetTargetCCE(this);
        if (pkTarget)
            return pkTarget->Process(pkArg);
    }
    return bResult;
}

unsigned int currentAllocationContext = 0x3b;

struct ThreadContextGuard
{
    unsigned int oldValue;
    ThreadContextGuard()
        : oldValue(currentAllocationContext)
    {
        currentAllocationContext = 0x10;
    }
    ~ThreadContextGuard()
    {
        currentAllocationContext = oldValue;
    }
};

struct StandinClass
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* m_pData;
    void* FUN_00ccf680(bool* result);
};

struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int size);
};


struct AllocatedBlock
{
    unsigned int unk00;
    float value04;
    unsigned int unk08;
    float value0c;
    float value10;
};

// Sets result to whether m_pData is null, allocates a 0x14-byte block with default values if so, stores it in m_pData, and returns m_pData.
// @fnv 0x00ccf680
void* StandinClass::FUN_00ccf680(bool* pbWasNull)
{
    ThreadContextGuard guard;
    *pbWasNull = (m_pData == 0);
    if (*pbWasNull)
    {
        MemoryManagerAllocHelper* allocator =
            reinterpret_cast<MemoryManagerAllocHelper*>(&(*reinterpret_cast<::MM *>(&::g_memoryManager)));
        AllocatedBlock* block =
            reinterpret_cast<AllocatedBlock*>(reinterpret_cast<::MemoryManagerStandIn *>((allocator))->FUN_00aa3e40(0x14));
        if (block != 0)
        {
            block->unk00 = 0;
            block->value04 = DAT_010c72bc;
            block->unk08 = 0;
            block->value0c = 20.0f;
            block->value10 = 5.0f;
        }
        else
        {
            block = reinterpret_cast<AllocatedBlock*>(0);
        }
        m_pData = block;
    }
    return m_pData;
}

class BCCFA50Arg;

class BCCFA50Shape {
public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void VFuncA4();
    virtual void VFuncA8();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual void VFuncB4();
    virtual void VFuncB8();
    virtual void VFuncBC();
    virtual void VFuncC0();
    virtual void VFuncC4();
    virtual void VFuncC8();
    virtual void VFuncCC();
    virtual bool Process(BCCFA50Arg* pkArg);
};

struct BCCFA50Child {
    int unk00;
    int unk04;
    BCCFA50Shape* m_pkShape;
};

class BCCFA50Counter {
public:
    virtual void VFunc00();
    virtual int GetCount();
};

struct BCCFA50HavokList {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    BCCFA50Counter m_kCounter;
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
    BCCFA50Child** m_ppkChildren;
};

class BCCFA50Wrapper {
public:
    bool BaseProcess(BCCFA50Arg* pkArg);
    __forceinline BCCFA50HavokList* GetList() { return this ? m_pkList : 0; }
    bool ProcessChildren(BCCFA50Arg* pkArg);

    int unk00;
    int unk04;
    BCCFA50HavokList* m_pkList;
};

// Calls BaseProcess, then processes each child shape in the list while the result stays true, returning the combined result.
// @fnv 0x00ccfa50
bool BCCFA50Wrapper::ProcessChildren(BCCFA50Arg* pkArg)
{
    bool bResult = ((bool)(::FUN_00c84ec0((void *)this)));
    if (bResult) {
        int iCount = GetList() ? GetList()->m_kCounter.GetCount() : 0;
        for (int i = 0; bResult && i < iCount; i++) {
            BCCFA50Child* pkChild = GetList() ? GetList()->m_ppkChildren[i] : 0;
            BCCFA50Shape* pkShape = pkChild ? pkChild->m_pkShape : 0;
            if (pkShape)
                bResult &= pkShape->Process(pkArg);
        }
    }
    return bResult;
}

// Returns the lazily created settings block, creating it under the Havok allocation tag and registering it when owned.


struct CCFFD0AllocTagScope {
    int m_iSaved;

    CCFFD0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CCFFD0AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

class CCFFD0MemoryManager {
public:
    void* Allocate(unsigned int uiSize);
};


class CCFFD0Settings {
public:
    CCFFD0Settings()
    {
        m_pUserData = 0;
        m_fScale = ::DAT_010c72bc;
        m_pEntries = 0;
        m_iEntryCount = 0;
        m_iCapacityAndFlags = 0x80000000;
    }


    void* m_pUserData;
    float m_fScale;
    int unk08;
    int unk0C;
    void* m_pEntries;
    int m_iEntryCount;
    int m_iCapacityAndFlags;
};

class CCFFD0Owner {
public:
    int unk00;
    int unk04;
    void* m_pkWorld;
    CCFFD0Settings* m_pkSettings;

    CCFFD0Settings* GetOrCreateSettings(bool* pbCreated);
};

struct hkMemoryAllocStub {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void deallocateChunk(void* p, int nbytes);
};

template <class T>
struct hkArrayRaw {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

};

template <class T>
struct hkArrayStub {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayStub() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~hkArrayStub()
    {
        hkMemoryAllocStub* mem = reinterpret_cast<hkMemoryAllocStub*>(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->unk10);
        if ((m_iCapacityState & 0x80000000) == 0)
            mem->deallocateChunk(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    hkArrayStub(const hkArrayRaw<T>& r) : m_data(r.m_data), m_iElementCount(r.m_iElementCount), m_iCapacityState(r.m_iCapacityState) {}
    __forceinline hkArrayRaw<T> release()
    {
        int s = m_iElementCount;
        T* d = m_data;
        m_data = 0;
        m_iElementCount = 0;
        int c = m_iCapacityState;
        m_iCapacityState = 0x80000000;
        hkArrayRaw<T> r;
        r.m_data = d;
        r.m_iElementCount = s;
        r.m_iCapacityState = c;
        return r;
    }
    void swap(hkArrayStub& a)
    {
        int s = a.m_iElementCount;
        T* d = a.m_data;
        a.m_data = m_data;
        a.m_iElementCount = m_iElementCount;
        m_data = d;
        m_iElementCount = s;
        int c = a.m_iCapacityState;
        a.m_iCapacityState = m_iCapacityState;
        m_iCapacityState = c;
    }
};

struct NiBinaryStreamStub {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStreamStub* stream, const void* buffer, unsigned int bytes,
                               unsigned int* componentSizes, unsigned int numComponents);

    void BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int numComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, buffer, bytes, componentSizes, numComponents);
    }
};

template <class T>
inline void SaveBinaryValue(NiBinaryStreamStub* stream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    stream->BinaryWrite(&value, sizeof(T), &uiSize, 1);
}

struct LinkedObjStub {
    int unk00;
    int unk04;
    void* m_pLinked;
};

struct SaveStreamStub {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void SaveLinkID(void* obj);
};

struct SaveStreamFields : SaveStreamStub {
    int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC;
    int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC;
    int unk1E0;
    unsigned char m_bUnk1E4;
    unsigned char unk1E5; unsigned short unk1E6;
    int unk1E8; int unk1EC;
    int unk1F0; int unk1F4; int unk1F8; int unk1FC;
    int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C;
    int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C;
    int unk240; int unk244; int unk248; int unk24C;
    NiBinaryStreamStub* m_pOstr;
};

struct CountedSub {
    virtual void v00();
    virtual int GetCount();
};

struct CountedOwner {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    CountedSub m_sub;
};

struct SavedData {
    int unk00;
    int unk04;
    char m_cUnk08;
    int m_iUnk0C;
    hkArrayStub<LinkedObjStub*> m_ppData;
};


struct bhkSaveOwner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4();
    virtual void* GetSource();
    virtual void vAC(); virtual void vB0();
    virtual SavedData* GetData(bool* pbOut);

    int unk04;
    CountedOwner* m_pSharedOwner;

    int GetCount() { CountedOwner* owner = m_pSharedOwner; return owner ? owner->m_sub.GetCount() : 0; }
    void SaveLinkedObjects(SaveStreamFields* stream);
};

// @fnv 0x00cd02d0
void bhkSaveOwner::SaveLinkedObjects(SaveStreamFields* stream)
{
    bool bOut;
    SavedData* data = GetData(&bOut);
    hkArrayStub<LinkedObjStub*> arr;
    arr.swap(data->m_ppData);
    if (stream->m_bUnk1E4 != 1) {
        void* source = GetSource();
        ::FUN_00cf0930(data, (int)(source), (::Vector3 *)(::hkArrayStub< ::LinkedObjStub *> *)(&data->m_ppData));
    }
    int count = arr.m_iElementCount;
    SaveBinaryValue(stream->m_pOstr, count);
    for (int i = 0; i < GetCount(); i++) {
        LinkedObjStub* obj = arr.m_data[i];
        stream->SaveLinkID(obj ? obj->m_pLinked : 0);
    }
    reinterpret_cast<::C9FC00Object *>(this)->FUN_00c9fc00((*(::C9FC00Stream *)(stream)));
    SaveBinaryValue(stream->m_pOstr, data->m_cUnk08);
    SaveBinaryValue(stream->m_pOstr, data->m_iUnk0C);
}

struct StateCountSource {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_iArrayLength;
};
struct StateResetPart {
    int unk00;
};
struct StateResetTarget {
    StateCountSource* m_pSource;
    StateResetPart m_kPart;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int* m_piStates;
    int unk20;
    int unk24;
    bool m_bFlag28;
    bool m_bFlag29;

    StateResetPart* ResetStates();
};

// @fnv 0x00cd9fb0
StateResetPart* StateResetTarget::ResetStates()
{
    int iCount = m_pSource->m_iArrayLength;
    for (int i = 0; i < iCount; ++i)
        m_piStates[i] = 2;
    m_bFlag28 = false;
    m_bFlag29 = true;
    return &m_kPart;
}

extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_012685b8;

struct C200125Base
{
    void FUN_00c87c30();
};

struct C200125Object : C200125Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;


    C200125Object()
    {
        unsigned int count = 1;
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_0102009c;
        DAT_01268118 += count;
        m_pVtable = &DAT_010c9634;
        DAT_012685b8 += count;
    }
};

struct C200125Owner
{
    C200125Object* FUN_00cc3540(unsigned int argument);
};

// @fnv 0x00cc3540
C200125Object* C200125Owner::FUN_00cc3540(unsigned int argument)
{
    TlsFlagGuard guard;
    FUN_00c876f0();

    C200125Object* object = new C200125Object;
    reinterpret_cast<::FUN_00c86800_Class *>(this)->FUN_00c86800((int)(object), (::FUN_00c86800_Table *)(argument));
    FUN_00c87700();
    return object;
}

struct CC4560Obj
{
    void* FUN_00cc4500();
};
struct CC4560Owner
{
    void* unk00;
    void* unk04;
    void* m_p;
    void* m_q;
    void* FUN_00cc4560(bool* pbCreated);
};
// @fnv 0x00cc4560
void* CC4560Owner::FUN_00cc4560(bool* pbCreated)
{
    TlsFlagGuard guard;
    bool bEmpty = (m_q == 0);
    *pbCreated = bEmpty;
    if (bEmpty)
    {
        unsigned char* pMem = ((unsigned char *)(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::FUN_00cc2a00_alloc *>(&::g_memoryManager))))->FUN_00aa3e40(0x30)));
        m_q = pMem ? ((CC4560Obj*)pMem)->FUN_00cc4500() : 0;
        if (m_p != 0)
            reinterpret_cast<::FUN_00cc4220_class *>(this)->FUN_00cc4220(m_q);
    }
    return m_q;
}

struct SaveStream;
typedef unsigned int (__cdecl *SaveStreamWriteFn)(SaveStream*, const void*, unsigned int, unsigned int*, unsigned int);

struct SaveStream {
    void* unk00;
    unsigned int m_04;
    void* unk08;
    SaveStreamWriteFn m_0c;
    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int num)
    { unsigned int r = m_0c(this, p, n, sizes, num); m_04 += r; return r; }
    unsigned int Write(const void* p, unsigned int n)
    { unsigned int cnt = n; return BinaryWrite(p, n, &cnt, 1); }
};

struct SaveCtx {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    SaveStream* m_pBinaryStream;
};

class FUN_00cc8a10_cls {
public:
    void* unk00;
    unsigned char* m_pSub;
    void WriteSubData(int a1);
};

static inline void CC8A10Write(SaveCtx* c, void* p, unsigned int n)
{
    c->m_pBinaryStream->Write(p, n);
}
// @fnv 0x00cc8a10
void FUN_00cc8a10_cls::WriteSubData(int apCtx) {
    SaveCtx* c = (SaveCtx*)apCtx;
    unsigned char* sub = m_pSub;
    CC8A10Write(c, sub + 0x20, 0x30);
    CC8A10Write(c, sub + 0x50, 0x30);
    CC8A10Write(c, sub + 0x84, 4);
    CC8A10Write(c, sub + 0x88, 4);
    reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((*(::S_00c8a280_Stream *)(c)));
}

// bhk wrapper LoadBinary: load the parent part, then fix up the Havok cinfo block when the
// stream's endianness differs (translation swapped inline, rotation through the shared helper).

struct NiStreamX {
    unsigned int m_000;
    unsigned int m_004;
    unsigned int m_008;
    unsigned int m_00c;
    unsigned int m_010;
    unsigned int m_014;
    unsigned int m_018;
    unsigned int m_01c;
    unsigned int m_020;
    unsigned int m_024;
    unsigned int m_028;
    unsigned int m_02c;
    unsigned int m_030;
    unsigned int m_034;
    unsigned int m_038;
    unsigned int m_03c;
    unsigned int m_040;
    unsigned int m_044;
    unsigned int m_048;
    unsigned int m_04c;
    unsigned int m_050;
    unsigned int m_054;
    unsigned int m_058;
    unsigned int m_05c;
    unsigned int m_060;
    unsigned int m_064;
    unsigned int m_068;
    unsigned int m_06c;
    unsigned int m_070;
    unsigned int m_074;
    unsigned int m_078;
    unsigned int m_07c;
    unsigned int m_080;
    unsigned int m_084;
    unsigned int m_088;
    unsigned int m_08c;
    unsigned int m_090;
    unsigned int m_094;
    unsigned int m_098;
    unsigned int m_09c;
    unsigned int m_0a0;
    unsigned int m_0a4;
    unsigned int m_0a8;
    unsigned int m_0ac;
    unsigned int m_0b0;
    unsigned int m_0b4;
    unsigned int m_0b8;
    unsigned int m_0bc;
    unsigned int m_0c0;
    unsigned int m_0c4;
    unsigned int m_0c8;
    unsigned int m_0cc;
    unsigned int m_0d0;
    unsigned int m_0d4;
    unsigned int m_0d8;
    unsigned int m_0dc;
    unsigned int m_0e0;
    unsigned int m_0e4;
    unsigned int m_0e8;
    unsigned int m_0ec;
    unsigned int m_0f0;
    unsigned int m_0f4;
    unsigned int m_0f8;
    unsigned int m_0fc;
    unsigned int m_100;
    unsigned int m_104;
    unsigned int m_108;
    unsigned int m_10c;
    unsigned int m_110;
    unsigned int m_114;
    unsigned int m_118;
    unsigned int m_11c;
    unsigned int m_120;
    unsigned int m_124;
    unsigned int m_128;
    unsigned int m_12c;
    unsigned int m_130;
    unsigned int m_134;
    unsigned int m_138;
    unsigned int m_13c;
    unsigned int m_140;
    unsigned int m_144;
    unsigned int m_148;
    unsigned int m_14c;
    unsigned int m_150;
    unsigned int m_154;
    unsigned int m_158;
    unsigned int m_15c;
    unsigned int m_160;
    unsigned int m_164;
    unsigned int m_168;
    unsigned int m_16c;
    unsigned int m_170;
    unsigned int m_174;
    unsigned int m_178;
    unsigned int m_17c;
    unsigned int m_180;
    unsigned int m_184;
    unsigned int m_188;
    unsigned int m_18c;
    unsigned int m_190;
    unsigned int m_194;
    unsigned int m_198;
    unsigned int m_19c;
    unsigned int m_1a0;
    unsigned int m_1a4;
    unsigned int m_1a8;
    unsigned int m_1ac;
    unsigned int m_1b0;
    unsigned int m_1b4;
    unsigned int m_1b8;
    unsigned int m_1bc;
    unsigned int m_1c0;
    unsigned int m_1c4;
    unsigned int m_1c8;
    unsigned int m_1cc;
    unsigned int m_1d0;
    unsigned int m_1d4;
    unsigned int m_1d8;
    unsigned int m_1dc;
    unsigned int m_1e0;
    unsigned char m_1e4;
    unsigned char m_bSameEndian;
};
struct TransformDataX {
    unsigned int m_rotation00, m_rotation04, m_rotation08, m_rotation0c;
    unsigned int m_rotation10, m_rotation14, m_rotation18, m_rotation1c;
    unsigned int m_rotation20, m_rotation24, m_rotation28, m_rotation2c;
    unsigned int m_uiX, m_uiY, m_uiZ, m_w;
};
struct CinfoX {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    TransformDataX m_kMotionTransform;
};
static inline void SwapDword(unsigned int& v) { v = _byteswap_ulong(v); }

struct bhkParentX {
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44();
    virtual CinfoX* GetCinfo(int* piSize);
};
struct bhkDerivedX : bhkParentX {
    void FUN_00cceb90(NiStreamX& kStream);
};

// @fnv 0x00cceb90
void bhkDerivedX::FUN_00cceb90(NiStreamX& kStream)
{
    reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
    reinterpret_cast<::Cls_00c9fbc0 *>(this)->FUN_00c9fbc0((::Arg_00c9fbc0 *)&(kStream));
    int iSize;
    CinfoX* pkCinfo = GetCinfo(&iSize);
    pkCinfo->m_08 = 0;
    if (kStream.m_bSameEndian != 1)
    {
        TransformDataX* pkTransform = &pkCinfo->m_kMotionTransform;
        SwapDword(pkTransform->m_uiX);
        SwapDword(pkTransform->m_uiY);
        SwapDword(pkTransform->m_uiZ);
        SwapDword(pkTransform->m_w);
        ::FUN_00c8c020((unsigned int *)(pkTransform));
    }
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

namespace cce {
struct Block { char pad[0x30]; unsigned long m_kPointA; unsigned long m_kPointB; unsigned long m_iThirdValue; unsigned long m_iFourthElementInteger; };
inline void Swap32(unsigned long& v) { v = _byteswap_ulong(v); }
inline void SwapBlock(Block* b) {
    Swap32(b->m_kPointA); Swap32(b->m_kPointB); Swap32(b->m_iThirdValue); Swap32(b->m_iFourthElementInteger);
    ::FUN_00c8c020((unsigned int *)(b));
}
struct Hdr { char pad[0x10]; Block m_kBlock; };
struct Info { int unk; int unkCur; void* m_pName; };
struct Meta { char pad[0x18]; Info* m_pObjectInfo; };
struct Writer {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void SetName(void* p);
    char pad[0x1e4 - 4]; unsigned char m_ucMode;
};
struct Obj {
    virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void v30();virtual void v34();virtual void v38();virtual void v3c();virtual void v40();virtual void v44();virtual void v48();virtual void v4c();virtual void v50();virtual void v54();virtual void v58();virtual void v5c();virtual void v60();virtual void v64();virtual void v68();virtual void v6c();virtual void v70();virtual void v74();virtual void v78();virtual void v7c();virtual void v80();virtual void v84();virtual void v88();virtual void v8c();virtual void v90();virtual void v94();virtual void v98();virtual void v9c();virtual void va();virtual void vaCur();virtual void vaValue();virtual void vac();virtual void vb();
    virtual Hdr* GetHeader(int* pSize);
    int unkCur; Meta* m_pMeta;
    void FUN_00ccec00(Writer* w);
};
static inline void* GetName(Obj* o) { return (o && o->m_pMeta && o->m_pMeta->m_pObjectInfo) ? o->m_pMeta->m_pObjectInfo->m_pName : 0; }
// @fnv 0x00ccec00
void Obj::FUN_00ccec00(Writer* w)
{
    w->SetName(GetName(this));
    int iSize;
    Hdr* h = GetHeader(&iSize);
    if (w->m_ucMode != 1) SwapBlock(&h->m_kBlock);
    reinterpret_cast<::C9FC00Object *>(this)->FUN_00c9fc00((*(::C9FC00Stream *)(w)));
    if (w->m_ucMode != 1) SwapBlock(&h->m_kBlock);
}
}

extern char g_vtblInst010cb300[];

struct ContactPointPair
{
    int m_00; int m_04; int m_08; int m_0c;
    int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c;
    int m_30; int m_34; int m_38; int m_3c;
    int m_40; int m_44; int m_48; int m_4c;
    int m_50; int m_54; int m_58; int m_5c;
    int m_60; int m_64; int m_68; int m_6c;
};

struct HavokElementArray
{
    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapFlags;
    void Init()
    {
        m_pData = 0;
        m_uiLogicalSize = 0;
        m_iCapFlags = (int)0x80000000;
    }
};

struct FUN_00cd3410
{
    void* volatile m_pVtable;           // 0x00
    volatile float m_fEarlyOutDistance;  // 0x04
    int m_unk08;                        // 0x08
    int m_unk0c;                        // 0x0c
    void* m_pHits;                      // 0x10
    int m_iHitsSize;                    // 0x14
    int m_iHitsCapFlags;                // 0x18
    int m_unk1c;                        // 0x1c
    ContactPointPair m_kHits[8];               // 0x20 (8 * 112 = 0x380)
    volatile unsigned int m_3a0;        // 0x3a0
    HavokElementArray m_a1;                   // 0x3a4
    HavokElementArray m_a2;                   // 0x3b0
    HavokElementArray m_a3;                   // 0x3bc

    FUN_00cd3410(unsigned int param);
};

// Initializes the object: sets vtable pointers, hit capacity flags, hit buffer to inline storage, stores param, and inits three sub-objects.
// @fnv 0x00cd3410
FUN_00cd3410::FUN_00cd3410(unsigned int param)
{
    m_fEarlyOutDistance = 3.40282e38F;
    m_pVtable = g_vtblInst0104da28;
    m_iHitsCapFlags = 0x80000008;
    m_pHits = m_kHits;
    m_fEarlyOutDistance = 3.40282e38F;
    m_3a0 = param;
    m_pVtable = g_vtblInst010cb300;
    m_a1.Init();
    m_a2.Init();
    m_a3.Init();
    m_iHitsSize = 0;
    m_fEarlyOutDistance = 3.40282e38F;
}






struct Defaults {
 float strength, damping, gain, recovery, maxVelocity, u14,u18,u1c,u20,u24,u28,u2c;
 Defaults() : strength(.17f),damping(0),gain(1),recovery(.6f),maxVelocity(.05f),u14(runtimeFloatSettingDefault92),u18(runtimeFloatSettingDefault506),u1c(.1f),u20(.3f),u24(.3f),u28(g_011db1d4_arg1),u2c(.1f) {}
 Defaults(int) {}
};
template<class T> struct Array {
 T* data; int size; int capacity;
 Array():data(0),size(0),capacity(0x80000000) {}
 __forceinline void reserve(S_00cc4b90_Alloc& alloc,int n) { int c=capacity&0x3fffffff; if(c<n) { int doubled=c*2; ::FUN_00c908c0((::SpawnedObject *)(void *)(&alloc),(::SpawnedArray *)(void *)(this),n<doubled?doubled:n,sizeof(T)); } }
 __forceinline void resizeUninitialized(int n) { reserve(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap(),n); size=n; }
 __forceinline void resize(int n) { reserve(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap(),n); int delta=n-size; T* start=data+size; for(int i=0;i<delta;i++) new(start+i) T; size=n; }
 __forceinline void resize(int n,T value) { reserve(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap(),n); int delta=n-size; T* start=data+size; for(int i=0;i<delta;i++) start[i]=value; size=n; }
};
struct Skeleton { int u00,u04,u08; short* parents; int u10,u14,u18; int count; };
struct Binding { int u00,u04; void* name; int boneCount; int u10,u14,u18,u1c; int* remapping; int u24,u28; Skeleton* skeleton;  };
struct Transform { float x00,x04,x08,x0c,x10,x14,x18,x1c,x20,x24,x28,x2c,x30,x34,x38,x3c; };
struct PoseView { int count; void* name; short* parents; };
struct FUN_00cdb400 {
 Array<Defaults> defaults;
 Array<int> auxiliary;
 PoseView pose;
 int u24,u28;
 Array<Transform> transforms;
 Binding* binding;
 Array<short> parents;
 FUN_00cdb400(Binding* input);
};
class hkTargetCC01 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void handle(void* pv);
};

class hkObjCC01 {
public:
    int unk00;
    int unk04;
    hkTargetCC01* m_target;

    void* DispatchToTarget(void* pv);
};

// @fnv 0x00cc0100
void* hkObjCC01::DispatchToTarget(void* pv)
{
    m_target->handle(pv);
    return pv;
}


struct hkStreamWriter {
    virtual void unk00() = 0;
    virtual void unk04() = 0;
    virtual void unk08() = 0;
    virtual void unk0c() = 0;
    virtual int write(const void* buf, int len) = 0;
};

static __declspec(noinline) void FUN_00cc0080(hkStreamWriter* writer, const char* str) {
    if (str) {
        writer->write(str, ::fnv_00cb10d0::FUN_00cb10d0(str));
    } else {
        writer->write("(null)", 6);
    }
}

struct FUN_00cc0370_Class : hkOstream {
    FUN_00cc0370_Class& WriteInt64(__int64 val);
};

// Formats val as a 64-bit integer into a buffer and writes the resulting string to the stream writer.
// @fnv 0x00cc0370
FUN_00cc0370_Class& FUN_00cc0370_Class::WriteInt64(__int64 val) {
    int buf[0x2728 / sizeof(int)];
    ::Vsnprintf((char*)buf, sizeof(buf), "%I64i", val);
    FUN_00cc0080((hkStreamWriter*)m_pSharedOwner, (char*)buf);
    return *this;
}


struct OwnerManager {
    virtual void* Reserved0();
    virtual void* Reserved1();
    virtual void* Reserved2();
    virtual void* Reserved3();
    virtual void* CreateOwner(void* owner);
};


struct FUN_00cc04d0_Class {
    void* m_pVtable;
    unsigned short m_iFlags;
    unsigned short m_iUnk;
    void* m_pSharedOwner;

    FUN_00cc04d0_Class* FUN_00cc04d0(void* owner);
};

// @fnv 0x00cc04d0
FUN_00cc04d0_Class* FUN_00cc04d0_Class::FUN_00cc04d0(void* owner)
{
    m_iUnk = 1;
    m_pVtable = &DAT_010c9314;
    m_pSharedOwner = reinterpret_cast<OwnerManager*>(::DAT_01268364)->CreateOwner(owner);
    return this;
}

struct FUN_00cc0550_VirtualObject {
    virtual void vf00();
    virtual void* vf04(int value);
};

struct FUN_00cc0550_Holder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    FUN_00cc0550_VirtualObject* unk10;
};

struct FUN_00cc0550_Allocated {
    void* m_pVtable;
    unsigned short m_usField04;
    unsigned short m_usField06;
    void* m_pField08;
    int m_iField0C;
};

extern "C" void* DAT_010c933c;

struct FUN_00cc0550_class {
    void* m_pVtable;
    unsigned short m_usField04;
    unsigned short m_usField06;
    FUN_00cc0550_Allocated* m_pField08;

    FUN_00cc0550_class* InitializeWithValue(int value);
};

// Sets the vtable and flags, allocates a 16-byte object via holder->unk10->vf04, stores value in it, and assigns it to m_pField08.
// @fnv 0x00cc0550
FUN_00cc0550_class* FUN_00cc0550_class::InitializeWithValue(int value) {
    m_usField06 = 1;
    m_pVtable = &DAT_010c9314;

    FUN_00cc0550_Holder* holder =
        reinterpret_cast<FUN_00cc0550_Holder*>(static_cast<S_00cc4b90_Router*>(::FUN_00c85750()));
    FUN_00cc0550_Allocated* pValueBlock =
        reinterpret_cast<FUN_00cc0550_Allocated*>(holder->unk10->vf04(0x10));

    pValueBlock->m_usField04 = 0x10;
    pValueBlock->m_usField06 = 1;
    pValueBlock->m_pVtable = &DAT_010c933c;
    pValueBlock->m_pField08 = reinterpret_cast<void*>(value);
    pValueBlock->m_iField0C = 1;

    m_pField08 = pValueBlock;
    return this;
}

struct FUN_00d46d40_s {
};


struct hkSourceCC08 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0C();
};


struct hkObjCC08 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18(const char* name, int value);

    void FUN_00cc0820();
};

// Reads an int from DAT_01268b08 and passes it with the string from FUN_00d47f90()->FUN_00d46d40() to v18.
// @fnv 0x00cc0820
void hkObjCC08::FUN_00cc0820()
{
    int value = reinterpret_cast<hkSourceCC08*>(::DAT_01268b08)->v0C();
    v18(reinterpret_cast<::FnvClassNameNode *>((((::FUN_00d46d40_s *)(::FUN_00d47f90()))))->FUN_00d46d40(), value);
}

struct CpuOpaque;
extern CpuOpaque DAT_01268590;
// @fnv 0x00cc1280
CpuOpaque* __cdecl FUN_00cc1280()
{
    return &DAT_01268590;
}

struct FUN_00a5d2f0_shell {
    bool FUN_00a5d2f0(void* apStream);
};
struct FUN_00cc1310_class : FUN_00a5d2f0_shell {
    unsigned int m_uiUnk0;
    unsigned int m_uiUnk4;
    unsigned int m_uiCount;
    void* m_pData;
    bool FUN_00cc1310(void* apStream);
};
// @fnv 0x00cc1310
bool FUN_00cc1310_class::FUN_00cc1310(void* apStream)
{
    bool b = FUN_00a5d2f0(apStream);
    if (b) {
        for (unsigned int i = 0; i < m_uiCount; ++i)
            ((void (*)(void*, void*))(*(void***)apStream)[8])(apStream, (char*)m_pData + i * 4);
    }
    return b;
}

struct Stream {
    int unk0;
    int total;
    int unk8;
    int (*io)(Stream* s, void* buf, int size, int* out, int n);
    void Rd(void* p) { int sz = 4; total += io(this, p, 4, &sz, 1); }
};
struct Item { unsigned int count; char** data; };
struct Loader {
    char pad[0x250];
    Stream* stream;
    void Read(unsigned int* p);
};
static inline void ReadU(Loader* l, void* p) { l->stream->Rd(p); }
struct Obj {
    int unk0, unk4;
    unsigned int count1;
    unsigned int* arr1;
    unsigned int count2;
    Item** arr2;
    void ReadFromStream(Loader* l);
};
// @fnv 0x00cc1610
void Obj::ReadFromStream(Loader* pLoader)
{
    ::FUN_00a89af0((std::intptr_t)(pLoader));
    ReadU(pLoader, &count1);
    for (unsigned int i = 0; i < count1; i++)
        reinterpret_cast<::FUN_00a641f0_cls *>((pLoader))->WriteObjectLink(&arr1[i]);
    ReadU(pLoader, &count2);
    for (unsigned int i = 0; i < count2; i++) {
        Item* it = arr2[i];
        ReadU(pLoader, it);
        for (unsigned int j = 0; j < it->count; j++)
            ::FUN_00cf09a0((::StreamOwner *)(pLoader), (::Record *)(char *)((char*)it->data + j * 0x30));
    }
}


// @fnv 0x00cc1960
void __cdecl FUN_00cc1960(void)
{
    static_cast<::FUN_00a5d430_Class *>(nullptr)->FUN_00a5d430({});
}

struct RefObjC {
    virtual ~RefObjC();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T>
struct LargeArrayC {
    virtual ~LargeArrayC();
    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void SetSize(unsigned int uiMaxSize);
    __declspec(noinline) void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_uiSize) {
            m_uiSize = uiIndex + 1;
            if (element.m_pObject)
                m_uiESize++;
        } else {
            if (element.m_pObject) {
                if (!m_pBase[uiIndex].m_pObject)
                    m_uiESize++;
            } else {
                if (m_pBase[uiIndex].m_pObject)
                    m_uiESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_uiMaxSize)
            reinterpret_cast<::ReferenceArray *>(this)->Resize(uiIndex + m_uiGrowBy);
        reinterpret_cast<::fnv_00a65800::NiObjectArrayRt *>(this)->FUN_00cc1a10(uiIndex, (const ::fnv_00a65800::NiPointerRt< ::fnv_00a65800::NiObjectRt> &)(element));
        return uiIndex;
    }
    unsigned int Add(const T& element) { return SetAtGrow(m_uiSize, element); }
};

struct OwnerC {
    int unk00, unk04, unk08;
    LargeArrayC<NiPointer<RefObjC> > m_kArray;
    void AddRefObject(RefObjC* pkObject);
};
// @fnv 0x00cc2120
void SceneList::WriteSceneList(OutputBuffer* dest, void* context) {
    ThreadModeGuard mode;
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330((::NiBinaryExtraData *)(dest), (::CloningProcess *)(context));
    unsigned int n = count;
    reinterpret_cast<::ReferenceArray *>(&(dest->list))->Resize(n);
    for (unsigned int i = 0; i < n; ++i) {
        SceneNode* node = entries[i];
        void* value = node;
        if (node) value = node->ReadValue(context);
        reinterpret_cast<::OwnerC *>((dest))->AddRefObject((::RefObjC *)(value));
    }
}

// If pkObject is non-null, appends it to m_kArray.
// @fnv 0x00cc2080
void OwnerC::AddRefObject(RefObjC* pkObject)
{
    if (pkObject)
        m_kArray.Add(pkObject);
}

void __cdecl FUN_00c8a560();

// @fnv 0x00cc5080
void __cdecl FUN_00cc5080() {
    FUN_00c8a560();
}

struct S_54d0_Poly {
    void* m_pVtable;
};

struct S_54d0_Child {
    void* m_pUnk00;

    S_54d0_Child() {}
};

struct S_54d0_Heap {
    void* Allocate(unsigned int uiSize);
};

extern int DAT_010c9af0;

struct S_54d0_Node : S_54d0_Poly, S_54d0_Child {
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;


    S_54d0_Node() {
        S_54d0_Child* pkSelf = this;
        m_uiRefCount = 1;
        m_uiValue1 = 0;
        m_uiData1 = 0;
        m_pVtable = (void*)&DAT_010c9af0;
        pkSelf->m_pUnk00 = 0;
    }
};

struct S_54d0_Owner {
    void* m_pUnk00;
    void* m_pUnk04;
    void* m_pUnk08;
    S_54d0_Child* m_pData;

    S_54d0_Child* FUN_00cc54d0(bool* pbCreated);
};

// Sets *pbCreated to whether m_pData is null, allocates a new S_54d0_Node when it is, attaches it if m_pUnk08 is set, and returns m_pData.
// @fnv 0x00cc54d0
S_54d0_Child* S_54d0_Owner::FUN_00cc54d0(bool* pbCreated) {
    SerializationMemoryContext kCtx;

    *pbCreated = (m_pData == 0);

    if (*pbCreated) {
        m_pData = new S_54d0_Node();

        if (m_pUnk08 != 0) {
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((void*)(S_54d0_Node*)m_pData);
        }
    }

    return m_pData;
}

struct CC7970_Allocator {  };
struct CC7970_RefData { unsigned int m_uiFilterValue; };
struct CC7970_RefObject {
    void* m_pVtable;
    CC7970_RefData m_data;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiReserved;
};
static __forceinline CC7970_RefData* CC7970_CreateReference() {
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<::MemoryManagerStandIn *>((reinterpret_cast<CC7970_Allocator*>(&(*reinterpret_cast<::FUN_00cc2a00_alloc *>(&::g_memoryManager)))))->FUN_00aa3e40(sizeof(CC7970_RefObject)));
    if (object) {
        CC7970_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010c9d60;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
struct CC7970_Owner {
    unsigned int m_unk00, m_unk04, m_flag08;
    CC7970_RefData* m_pData;
    CC7970_RefData* GetOrCreateRefData(bool* created);
};
// @fnv 0x00cc7970
CC7970_RefData* CC7970_Owner::GetOrCreateRefData(bool* created) {
    TlsFlagGuard tlsGuard;
    *created = (m_pData == 0);
    if (*created) {
        CC7970_RefData* data = CC7970_CreateReference();
        m_pData = data;
        if (m_flag08) {
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((void*)(data ? reinterpret_cast<CC7970_RefObject*>(reinterpret_cast<char*>(data) - 4) : 0));
        }
    }
    return m_pData;
}


// @fnv 0x00cc7ce0
void FUN_00cc7ce0() {
    ::FUN_00d50000({}, {});
}


// @fnv 0x00cc7cf0
void __cdecl FUN_00cc7cf0()
{
    static_cast<::hkpD500Object *>(nullptr)->FUN_00d50010({});
}


void FUN_00aa1460(void*,unsigned int);
extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
// Constructor stand-in for the twelve-byte bhkRefObject base.
struct FUN_00c87c30 {
    virtual ~FUN_00c87c30();
    unsigned int references;
    void* handle;
    FUN_00c87c30();
};
// The pack's bhkConstraint shell omits its base and data member.
// This stand-in models the actual sixteen-byte constraint layout.
class Constraint348 : public FUN_00c87c30 {
public:
    void* constraint;
    Constraint348() : constraint(0) { ++DAT_01268188; }
    virtual ~Constraint348();
};
class bhkGenericConstraint : public Constraint348 {
public:
    bhkGenericConstraint() { ++DAT_01268f74; }
    virtual ~bhkGenericConstraint();
};
class bhkFixedConstraint : public bhkGenericConstraint {
public:
    bhkFixedConstraint() { ++DAT_01268624; }
    virtual ~bhkFixedConstraint();
};
// Allocates and constructs a new bhkFixedConstraint object and returns it.
// @fnv 0x00cc7e70
bhkFixedConstraint* CreateFixedConstraint() { return new bhkFixedConstraint; }

struct FUN_00d53d90 : S_00cc4b90_RefObj {
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
    FUN_00d53d90();
};
struct S_00cc9020_Cls {
    int unk00;
    FUN_00d53d90* m_object;
    int EnsureObject();
};
// Constructs a 16-byte context, allocates a FUN_00d53d90 into m_object if null, and returns 52.
// @fnv 0x00cc9020
int S_00cc9020_Cls::EnsureObject()
{
    S_00cc4b90_Ctx m_uiMemoryContext(16);
    if (!m_object)
        m_object = new FUN_00d53d90();
    return 52;
}


// @fnv 0x00cc9cd0
void __cdecl FUN_00cc9cd0()
{
    static_cast<::QTF *>(nullptr)->FUN_00ca4f00({});
}

// Forward declaration of the target function

// Tail call wrapper - jumps to FUN_00ca4f40
// @fnv 0x00cc9ce0
void __cdecl FUN_00cc9ce0() {
    static_cast<::HC1Base *>(nullptr)->FUN_00ca4f40({});
}

// @fnv 0x00cc9cf0
void __cdecl FUN_00cc9cf0()
{
    static_cast<::S00c8bf40_Flags *>(nullptr)->FUN_00c8bf40({});
}

namespace fnv_00cca2a0 {
struct Vec4 {
    unsigned int x, y, z;
    float w;
    Vec4() : x(0), y(0), z(0), w(1.0f) {}
};
struct Allocator {
};
struct ScopedMemoryMode {
    int previous;
    ScopedMemoryMode() : previous((*reinterpret_cast<int *>(&::currentAllocationContext))) { (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16; }
    ~ScopedMemoryMode() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous; }
};
struct FUN_00cca2a0_class {
    void* m_ppVirtualMethodTable;
    void* m_object;
    void* m_parent;
    Vec4* m_vec;
    Vec4* GetOrCreateVec(bool* created);
};
// @fnv 0x00cca2a0
Vec4* FUN_00cca2a0_class::GetOrCreateVec(bool* created) {
    ScopedMemoryMode memoryMode;
    *created = (m_vec == 0);
    if (*created) {
        Vec4* vec = new (reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00cca2a0::Allocator *>(&::g_memoryManager))))->FUN_00aa3e40(sizeof(Vec4))) Vec4;
        m_vec = vec;
        if (m_parent)
            reinterpret_cast<::S_00cc9df0_Cls *>(this)->SetRatioFromValues((::S_00cc9df0_Out *)(vec));
    }
    return m_vec;
}
}  // namespace fnv_00cca2a0

struct FUN_00cce5e0_class {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
    FUN_00cce5e0_class* Construct();
};
// @fnv 0x00cce5e0
FUN_00cce5e0_class* FUN_00cce5e0_class::Construct()
{
    m_pVtable = 0;
    m_uiRefCount = 0;
    m_uiValue1 = 0x80000000;
    m_uiData1 = 0;
    m_uiData2 = 0;
    m_uiData3 = 0x80000000;
    return this;
}

struct Cls00ccf5a0 {
    void FUN_00ccf5a0(int a);
};

// @fnv 0x00ccf5a0
void Cls00ccf5a0::FUN_00ccf5a0(int a) {
    ::FUN_00c84cc0((int *)this, a);
}

struct FE50Router { int m0, m4, m8, mc; void* m10; };
struct FE50Iter {
    virtual void v00();
    virtual unsigned int GetCount();
    virtual void* GetFirst();
    virtual void* GetNext(void* it);
};
struct FE50Hk {
    char pad00[0x14];
    FE50Iter m_kIter;
    float m18;
    char pad1c[0x28];
    void** m44;
};
struct FE50Arr { void** m_data; int m_iElementCount; int m_iCapacityState; };
struct FE50Out {
    int m0, m4;
    unsigned char m8;
    float mc;
    Array<void*> m10;
};
struct FE50Wrap {
    int m0, m4;
    FE50Hk* m8;
    float GetF() { if (this && m8) return m8->m18; return 0.0f; }
    int GetB() { if (this && m8) return ((bool)(reinterpret_cast<::FUN_00d5e0c0_Obj *>((m8))->FUN_00d5e0c0())); return 0; }
    unsigned int GetCount() { FE50Hk* p; if (this && (p = m8) != 0) return p->m_kIter.GetCount(); if (0) return m8->m_kIter.GetCount(); return 0; }
    void* GetFirst() { FE50Hk* p; if (this && (p = m8) != 0) return p->m_kIter.GetFirst(); if (0) return m8->m_kIter.GetFirst(); return 0; }
    void* GetNext(void* it) { FE50Hk* p; if (this && (p = m8) != 0) return p->m_kIter.GetNext(it); if (0) return m8->m_kIter.GetNext(it); return 0; }
    void* GetAt(unsigned int i) { if (this && m8) return m8->m44[i]; return 0; }
    void FillOutput(FE50Out* out);
};
// Returns m_pkSettings, creating it via the memory manager and registering it with m_pkWorld when absent; sets *pbCreated accordingly.
// @fnv 0x00ccffd0
CCFFD0Settings* CCFFD0Owner::GetOrCreateSettings(bool* pbCreated)
{
    CCFFD0AllocTagScope kScope(0x10);
    bool bCreate = m_pkSettings == 0;
    *pbCreated = bCreate;
    if (bCreate)
    {
        m_pkSettings = new (reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::CCFFD0MemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(sizeof(CCFFD0Settings))) CCFFD0Settings;
        if (m_pkWorld)
            reinterpret_cast<::FE50Wrap *>(this)->FillOutput((::FE50Out *)(m_pkSettings));
    }
    return m_pkSettings;
}
// Calls FUN_00c9fb70, then fills out with GetF, GetB, and copies GetCount elements from GetAt into out->m10.
// @fnv 0x00ccfe50
void FE50Wrap::FillOutput(FE50Out* out)
{
    TlsHeapGuard kGuard;
    ::FUN_00c9fb70((::MyObj *)this, 0, (::OutS *)(out));
    out->mc = GetF();
    out->m8 = GetB();
    unsigned int n = GetCount();
    out->m10.size = 0;
    out->m10.resizeUninitialized(n);
    void* it = GetFirst();
    for (unsigned int i = 0; i < n; i++) {
        out->m10.data[i] = GetAt(i);
        it = GetNext(it);
    }
}

struct AGBinStream {
    void* m_pVtable;
    unsigned int m_uiStreamFlags;
    unsigned int (__cdecl *m_pfnRead)(AGBinStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void AGLoadBinary(AGBinStream& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, uiSize, &uiSize, 1);
}
struct AGStream : SaveStreamFields {
};
struct AGOwner : bhkSaveOwner {
    void LoadSavedData(AGStream* stream);
};

// @fnv 0x00cd00a0
void AGOwner::LoadSavedData(AGStream* stream)
{
    reinterpret_cast<::S_00a64670_Foo *>((stream))->FUN_00a64670();
    reinterpret_cast<::Cls_00c9fbc0 *>(this)->FUN_00c9fbc0((::Arg_00c9fbc0 *)(stream));
    bool bFlag;
    SavedData* data = GetData(&bFlag);
    if (stream->unk1E5 != 1)
        { void* src = GetSource(); ::FUN_00cf0930(data, (int)(src), (::Vector3 *)(::hkArrayStub< ::LinkedObjStub *> *)(&data->m_ppData)); }
    AGLoadBinary(*(AGBinStream*)stream->unk24C, data->m_cUnk08);
    AGLoadBinary(*(AGBinStream*)stream->unk24C, data->m_iUnk0C);
    if (stream->unk1E5 != 1)
        { void* src = GetSource(); ::FUN_00cf0930(data, (int)(src), (::Vector3 *)(::hkArrayStub< ::LinkedObjStub *> *)(&data->m_ppData)); }
}

struct FnvCpu_FUN_00cd0cf0_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    void FUN_00cd0cf0(unsigned char arg0);
};
// @fnv 0x00cd0cf0
void FnvCpu_FUN_00cd0cf0_CpuObject::FUN_00cd0cf0(unsigned char arg0)
{
    value = arg0;
}


struct hkWorldCD29 {
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
    CRITICAL_SECTION* m_pWorldLock;
};

class hkWorldObjectCD29 {
public:
    int unk00;
    int unk04;
    hkWorldCD29* m_pOwningWorld;

    void LockWorldCriticalSection(int iUnused);
};

// @fnv 0x00cd2940
void hkWorldObjectCD29::LockWorldCriticalSection(int iUnused)
{
    if (m_pOwningWorld && m_pOwningWorld->m_pWorldLock)
        EnterCriticalSection(m_pOwningWorld->m_pWorldLock);
}

extern void (*DAT_00fdf100)(int*);
struct B { char pad[0xc4]; int* f; };
struct A { int unk0; int unk4; B* b; void FUN_00cd2960(int a); };
// @fnv 0x00cd2960
void A::FUN_00cd2960(int a) {
    if (b) { if (b->f) DAT_00fdf100(b->f); }
}

// 0x00cd2980  bare ret
// @fnv 0x00cd2980
void FUN_00cd2980() {
}

// 0x00cd2990  bare ret
// @fnv 0x00cd2990
void FUN_00cd2990() {
}

// @fnv 0x00cd29a0
void __cdecl FUN_00cd29a0()
{
}

// @fnv 0x00cd29b0
int FUN_00cd29b0(char* self, int)
{
    return *reinterpret_cast<int*>(self + 0x84);
}

struct FUN_00cd29f0_cls {
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    unsigned int unk88;
    void FUN_00cd29f0(unsigned int v);
};

// @fnv 0x00cd29f0
void FUN_00cd29f0_cls::FUN_00cd29f0(unsigned int v)
{
    unk88 = v;
}

struct FnvCpu_FUN_00cd2a00_CpuObject {
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
    int value;
    int FUN_00cd2a00();
};
// @fnv 0x00cd2a00
int FnvCpu_FUN_00cd2a00_CpuObject::FUN_00cd2a00()
{
    return value;
}

struct hkPairCD2A {
    int m_kPointA;
    int m_kPointB;
};

struct hkEntryCD2A {
    int m_key;
    int m_04;
    hkPairCD2A m_uiFilterValue;
};

class hkObjCD2A {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    hkEntryCD2A* m_entries;
    int m_iNumberOfEntries;

    void SetEntryValue(int iKey, hkPairCD2A kValue, int iUnused);
};

// @fnv 0x00cd2a10
void hkObjCD2A::SetEntryValue(int iKey, hkPairCD2A kValue, int iUnused)
{
    for (int i = 0; i < m_iNumberOfEntries; i++)
    {
        if (m_entries[i].m_key == iKey)
        {
            m_entries[i].m_uiFilterValue = kValue;
            return;
        }
    }
}

// @fnv 0x00cd3b10
void FUN_00cd3b10(int, int, int, int) {
}

// @fnv 0x00cd7d10
int FUN_00cd7d10(int arg0, int arg1)
{
    return 112;
}

struct FUN_00cdb3c0_class {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* FUN_00cdb3c0();
};

// @fnv 0x00cdb3c0
void* FUN_00cdb3c0_class::FUN_00cdb3c0()
{
    return unk38;
}

extern "C" void* __cdecl fnv_zlib_memset(void* dest, int val, unsigned int count) throw();

struct hkMemoryAllocator {
    virtual void vfn0() throw() = 0;
    virtual void vfn1() throw() = 0;
    virtual void vfn2() throw() = 0;
    virtual void vfn3() throw() = 0;
    virtual void ReleaseBlock(void* p, int numBytes) throw() = 0;
};

template <typename T> inline void ConstructWithCopy(T* p, int n, const T& t) { for (int i = 0; i < n; i++) p[i] = t; }

template <typename T>
struct MyArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    enum {
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    __forceinline MyArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG) {}

    __forceinline int getCapacity() const throw() { return m_iCapacityState & 0x3fffffff; }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator* alloc, int n) throw() {
        int cap = getCapacity();
        if (cap < n) {
            int cap2 = cap * 2;
            int newCap = n < cap2 ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)(alloc), (::SpawnedArray *)(void *)(this), newCap, sizeof(T));
        }
    }

    __forceinline void SetSizeAndGrow(int n, T fill) throw() {
        NineIntegerRecord* router = (NineIntegerRecord*)static_cast<S_00cc4b90_Router*>(::FUN_00c85750());
        GrowArrayCapacity(router->m_pStreamAllocator, n);
        ConstructWithCopy<T>(m_data + m_iElementCount, n - m_iElementCount, fill);
        m_iElementCount = n;
    }

    __forceinline void AddBack(const T& val) throw() {
        NineIntegerRecord* router = (NineIntegerRecord*)static_cast<S_00cc4b90_Router*>(::FUN_00c85750());
        if (m_iElementCount == getCapacity()) {
            ::ResizeAudioStream((::AudioAllocator *)(router->m_pStreamAllocator), (::AudioStream *)(void *)(this), sizeof(T));
        }
        ConstructWithCopy<T>(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }

    __forceinline ~MyArray() throw() {
        NineIntegerRecord* router = (NineIntegerRecord*)static_cast<S_00cc4b90_Router*>(::FUN_00c85750());
        hkMemoryAllocator* alloc = router->m_pStreamAllocator;
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
            alloc->ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
        }
    }
};

template <typename T>
struct MyLocalArray : public MyArray<T> {
    void* m_initialStack;

    __forceinline MyLocalArray(int capacity) throw() {
        NineIntegerRecord* router = (NineIntegerRecord*)static_cast<S_00cc4b90_Router*>(::FUN_00c85750());
        int numBytes = capacity * sizeof(T);
        int aligned = (numBytes + 0x7f) & ~0x7f;
        void* p = router->unk00;
        router->unk00 = (char*)p + aligned;
        this->m_iCapacityState = capacity | MyArray<T>::DONT_DEALLOCATE_FLAG;
        this->m_data = (T*)p;
        this->m_initialStack = p;
    }

    __forceinline ~MyLocalArray() throw() {
        void* p = m_initialStack;
        if (p == this->m_data) {
            this->m_iElementCount = 0;
        }
        ((NineIntegerRecord*)static_cast<S_00cc4b90_Router*>(::FUN_00c85750()))->unk00 = p;
    }
};

struct SomeFilter {
    int unk00;
    int unk04;
    int unk08;
    const unsigned short* unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

// Marks entries referenced by filter->unk0c in a temporary byte array, then appends every unmarked index below filter->unk1c to out.
// @fnv 0x00cde5e0
void __cdecl CollectUnusedIndices(SomeFilter* filter, MyArray<short>& out) throw() {
    MyLocalArray<char> array(filter->unk1c);
    array.SetSizeAndGrow(filter->unk1c, 0);

    int i = 0;
    while (i < filter->unk10) {
        short val = (short)filter->unk0c[i];
        if (val != -1) {
            array.m_data[val] = 1;
        }
        i++;
    }

    for (short i = 0; i < filter->unk1c; i++) {
        if (array.m_data[i] == 0) {
            out.AddBack(i);
        }
    }
}

struct FUN_00cdea20_cls {
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
    intptr_t m_e0;

    intptr_t FUN_00cdea20() const;
};

// @fnv 0x00cdea20
intptr_t FUN_00cdea20_cls::FUN_00cdea20() const
{
    return m_e0;
}

struct CC0280Stream {
    virtual void Write(const char* str, int len);
};


static void __declspec(noinline) FUN_00cc0080(CC0280Stream* s, const char* str)
{
    if (str == 0) {
        s->Write("(null)", 6);
        return;
    }
    s->Write(str, ::fnv_00cb10d0::FUN_00cb10d0(str));
}

struct CC0280Writer : hkOstream {
    CC0280Writer* WriteBool(bool b);
};

// Writes the string "true" or "false" to the underlying stream based on the input boolean value and returns this.
// @fnv 0x00cc0170
CC0280Writer* CC0280Writer::WriteBool(bool abValue)
{
    FUN_00cc0080((CC0280Stream*)m_pSharedOwner, abValue ? "true" : "false");
    return this;
}


struct WriterObj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Write(const char* s, int len);
};

static __declspec(noinline) void FUN_00cc0080(WriterObj* obj, const char* str)
{
    if (!str)
        obj->Write("(null)", 6);
    else
        obj->Write(str, ::fnv_00cb10d0::FUN_00cb10d0(str));
}

struct FUN_00cc01e0_class {
    void* m_kPointA;
    void* m_kPointB;
    WriterObj* m_obj;
    FUN_00cc01e0_class* WriteShort(short v);
};

// Formats the short parameter v as a decimal integer into a local buffer and writes it to m_obj via FUN_00cc0080, returning this.
// @fnv 0x00cc01e0
FUN_00cc01e0_class* FUN_00cc01e0_class::WriteShort(short asValue)
{
    int buf[2506];
    ::Vsnprintf((char*)buf, 0x2728, "%i", asValue);
    FUN_00cc0080(m_obj, (char*)buf);
    return this;
}

struct Param4 { int value; };
struct D274C0Child {
void* m_ppVirtualMethodTable;unsigned short m_memorySize;unsigned short m_sReferenceCount;int unk08,unk0c,unk10,unk14,unk18;
};
struct FUN_00cc0500_Class {
void* m_ppVirtualMethodTable;unsigned short m_memorySize;unsigned short m_sReferenceCount;D274C0Child* m_pChildAtom;
FUN_00cc0500_Class* FUN_00cc0500(int first,int second,Param4 third);
};
// Initializes the object, allocates a 28-byte child atom block, and constructs it with the given arguments.
// @fnv 0x00cc0500
FUN_00cc0500_Class* FUN_00cc0500_Class::FUN_00cc0500(int first,int second,Param4 third)
{
m_sReferenceCount=1;m_ppVirtualMethodTable=&DAT_010c9314;
D274C0Child* child=static_cast<D274C0Child*>(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap().AllocateMemoryBlock(28));
child->m_memorySize=28;
m_pChildAtom=((::D274C0Child *)(new ((void *)(child)) ::FUN_00d274c0((void *)(first),second,(*(char *)&(const ::Param4 &)(third)))));
return this;
}

struct S00cc0850_Entry {
    void* FUN_00cc0820();
};

struct S00cc0850_Registry {
};

struct S00cc0850_Slot {
};

extern int DAT_01268b9c;
extern const char str_010c93d0[];

// Looks up a key, then two named entries, on an object obtained from owner; on success stores that object in result and returns the found item, else 0.
// @fnv 0x00cc0850
int __cdecl FUN_00cc0850(int owner, int* apEntry)
{
    if (owner == 0 || apEntry == 0)
        return 0;

    void* entry = ((void *)(::FUN_00d48d30((::S00d48d30_Stream *)(owner), (::S00d48d30_Result *)(0), 0)));
    if (entry != 0) {
        S00cc0850_Slot* slot = reinterpret_cast<S00cc0850_Slot*>(
            reinterpret_cast<S00cc0850_Entry*>(entry)->FUN_00cc0820());
        if (slot != 0) {
            void* key = ((void *)(reinterpret_cast<::FnvClassNameNode *>((reinterpret_cast<S00cc0850_Registry*>(&DAT_01268b9c)))->FUN_00d46d40()));
            void* found = reinterpret_cast<::VariantListD480 *>((slot))->FindByName((const char *)(key), {});
            if (found == 0) {
                const char* names[3];
                names[0] = str_010c93d0;
                names[1] = str_010c93c0;
                names[2] = 0;
                for (int i = 0; names[i] != 0; ++i) {
                    found = ((void *)(reinterpret_cast<::Cls_d48150 *>((slot))->FUN_00d48150((void *)(names[i]), 0)));
                    if (found != 0)
                        break;
                }
            }
            if (found != 0) {
                *apEntry = reinterpret_cast<int>(entry);
                return reinterpret_cast<int>(found);
            }
        }
    }

    return 0;
}

extern "C" void FUN_004381b0();
struct FUN_00a5d3d0 {
    virtual void dummy();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    ~FUN_00a5d3d0();
};
struct FUN_00cc1520 : FUN_00a5d3d0 {
    virtual void dummy();
    char* m_pName;
    unsigned int m_uiCount;
    void** m_pEntryData;
    ~FUN_00cc1520();
};
// Frees the name buffer, each entry in m_pEntryData, and the entry array itself under the TLS block guard.
// @fnv 0x00cc1520
FUN_00cc1520::~FUN_00cc1520() {
    {
        TlsGuard_t guard((*reinterpret_cast<::TlsBlock_t *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4);
        if (m_pName) {
            char* header = m_pName - 4;
            fnv::crt::vector_destructor(m_pName, 4, *reinterpret_cast<unsigned int*>(header), (void (*)(void *))(&FUN_004381b0));
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(header);
        }
        if (m_pEntryData) {
            for (unsigned int i = 0; i < m_uiCount; ++i) {
                void* item = m_pEntryData[i];
                if (item)
                    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(item);
            }
            void** releaseArray = m_pEntryData;
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(releaseArray);
        }
    }
}

extern int DAT_01268188;
extern int DAT_012685f4;

void __cdecl FUN_00aa4060(void* p);

struct S_00cc5b90_Node
{
    int* vtable;
    int data04;
    int data08;
    int data0c;
    void FUN_00c87c30();
};
struct S_00cc5b90_Scope
{
    volatile int savedState;
    S_00cc5b90_Scope()
    {
        int* currentState = reinterpret_cast<int*>(
            reinterpret_cast<char*>(&(*reinterpret_cast<int *>(&::g_tlsBlock))) + 0x2b4);
        savedState = *currentState;
        *currentState = 16;
    }
    __forceinline ~S_00cc5b90_Scope()
    {
        int* currentState = reinterpret_cast<int*>(
            reinterpret_cast<char*>(&(*reinterpret_cast<int *>(&::g_tlsBlock))) + 0x2b4);
        *currentState = savedState;
    }
};
struct S_00cc5b90_PendingAllocation
{
    S_00cc5b90_Node* object;
    explicit S_00cc5b90_PendingAllocation(S_00cc5b90_Node* p) : object(p) {}
    __forceinline ~S_00cc5b90_PendingAllocation() { if (object) FUN_00aa4060(object); }
    void Transfer() { object = 0; }
};
struct S_00cc5b90_Owner
{
    S_00cc5b90_Node* AllocateNode(int arg);
};
// Allocates and initializes a 16-byte S_00cc5b90_Node, passes it and arg to FUN_00c89730, and returns it (null if the allocation failed).
// @fnv 0x00cc5b90
S_00cc5b90_Node* S_00cc5b90_Owner::AllocateNode(int arg)
{
    S_00cc5b90_Scope scope;
    FUN_00c876f0();
    S_00cc5b90_Node* result;
    {
        S_00cc5b90_PendingAllocation allocation(static_cast<S_00cc5b90_Node*>(FUN_00aa13e0(16)));
        S_00cc5b90_Node* pRawNode = allocation.object;
        if (pRawNode)
        {
            reinterpret_cast<::FUN_00c87c30_t *>((pRawNode))->FUN_00c87c30();
            pRawNode->vtable = &DAT_0108febc;
            pRawNode->data0c = 0;
            ++DAT_01268188;
            pRawNode->vtable = &DAT_010c52bc;
            ++DAT_012685f4;
            result = pRawNode;
        }
        else
        {
            result = 0;
        }
        allocation.Transfer();
    }
    reinterpret_cast<::Owner89730 *>(this)->FUN_00c89730(result, (::Process89730 *)(arg));
    FUN_00c87700();
    return result;
}

struct SaveBody {
 unsigned int field000;
 unsigned int field004;
 unsigned int field008;
 unsigned int field00c;
 unsigned int field010;
 unsigned int field014;
 unsigned int field018;
 unsigned int field01c;
 SaveMatrix transform;
 SaveMatrix inverse;
 unsigned short flags;unsigned char enabled;unsigned char unk0a3;
 unsigned int field0a4;
 unsigned int field0a8;
 unsigned int field0ac;
 unsigned int field0b0;
 unsigned int field0b4;
 unsigned int field0b8;
 unsigned int field0bc;
 unsigned int field0c0;
 unsigned int field0c4;
 unsigned int field0c8;
 unsigned int field0cc;
 unsigned int field0d0;
 unsigned int field0d4;
 unsigned int field0d8;
 unsigned int field0dc;
 unsigned int field0e0;
 unsigned int field0e4;
 unsigned int field0e8;
 unsigned int field0ec;
 unsigned int field0f0;
 unsigned int field0f4;
 unsigned int field0f8;
 unsigned int field0fc;
 unsigned int field100;
 unsigned int field104;
 unsigned int field108;
 unsigned int field10c;
 unsigned int field110;
 unsigned int field114;
 unsigned int field118;
 unsigned int field11c;
 unsigned int field120;
 unsigned int field124;
 unsigned int field128;
 unsigned int field12c;
 unsigned int field130;
};
struct SaveObject {
 int unk00;SaveBody* body;
 void FUN_00cc6ef0(SaveCtx*);
};
// Calls FUN_00c8a280, writes transform, inverse and six more body fields to the stream, saves the shape, and writes enabled if field0e0 is nonzero.
// @fnv 0x00cc6ef0
void SaveObject::FUN_00cc6ef0(SaveCtx* stream) {
 reinterpret_cast<::S_00c8a280_Obj *>(this)->FUN_00c8a280((*(::S_00c8a280_Stream *)(stream)));
 SaveBody* data=body;
 stream->m_pBinaryStream->Write(&data->transform,64);
 stream->m_pBinaryStream->Write(&data->inverse,64);
 stream->m_pBinaryStream->Write(&data->field11c,4);
 stream->m_pBinaryStream->Write(&data->field12c,4);
 stream->m_pBinaryStream->Write(&data->field130,4);
 stream->m_pBinaryStream->Write(&data->field104,4);
 stream->m_pBinaryStream->Write(&data->field108,4);
 stream->m_pBinaryStream->Write(&data->field0f8,4);
 ::SaveShape((::C8A4B0Shape *)this, (*(::C8A4B0Stream *)(data->field0e0)));
 if(data->field0e0)stream->m_pBinaryStream->Write(&data->enabled,1);
}

 extern int DAT_010c9e5c; extern int DAT_010c9d7c;
extern int DAT_01268188; extern int DAT_01268f74; extern int DAT_01268624;
 

struct ThreadHeapContext { unsigned int m_allocationTag; };
struct PhysicsNode {
    void* m_ppVirtualMethodTable; unsigned int m_sReferenceCount; unsigned int m_flags; unsigned int m_data;
    void FUN_00c87c30();
    PhysicsNode() {
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30(); m_ppVirtualMethodTable = &DAT_0108febc;
        unsigned int increment = 1; m_data = 0;
        DAT_01268188 += increment; m_ppVirtualMethodTable = &DAT_010c9e5c;
        DAT_01268f74 += increment; m_ppVirtualMethodTable = &DAT_010c9d7c; DAT_01268624 += increment;
    }
};
struct AllocationScope {
    unsigned int m_previousTag;
    AllocationScope() {
        m_previousTag = (*reinterpret_cast<::ThreadHeapContext *>(&::currentAllocationContext)).m_allocationTag;
        (*reinterpret_cast<::ThreadHeapContext *>(&::currentAllocationContext)).m_allocationTag = 16;
    }
    __forceinline ~AllocationScope() throw() {
        FUN_00c87700();
        (*reinterpret_cast<::ThreadHeapContext *>(&::currentAllocationContext)).m_allocationTag = m_previousTag;
    }
};
struct PhysicsWorld {  PhysicsNode* CreateNode(bool); };
// Constructs a PhysicsNode under an allocation scope, passes it and the flag to FUN_00c89730, and returns the node.
// @fnv 0x00cc80d0
PhysicsNode* PhysicsWorld::CreateNode(bool argument) {
    AllocationScope scope;
    FUN_00c876f0();
    PhysicsNode* node = new PhysicsNode;
    reinterpret_cast<::Owner89730 *>(this)->FUN_00c89730(node, (::Process89730 *)(argument));
    return node;
}

namespace fnv_00cc8cd0 {

// @fnv 0x00cc8cd0
void FUN_00cc8cd0()
{
    ::FUN_00cc5080();
}
}  // namespace fnv_00cc8cd0

struct S00cc9af0_Inner {
    virtual void Run(int v);
};

struct S00cc9af0_Obj {
    int unk00;
    int unk04;
    int unk08;
    void* m_pData;
    void FUN_00cc9af0(bool b);
};

// If b is true and m_pData is set, calls Run(1) on the object at m_pData minus 4, then nulls m_pData.
// @fnv 0x00cc9af0
void S00cc9af0_Obj::FUN_00cc9af0(bool b)
{
    TlsFlagGuard_00cc1e40 guard;
    if (b) {
        if (m_pData) {
            S00cc9af0_Inner* obj = reinterpret_cast<S00cc9af0_Inner*>((char*)m_pData - 4);
            if (obj) {
                obj->Run(1);
            }
        }
        m_pData = 0;
    }
}


struct CCE1C0MemoryManager {
    void* Allocate(unsigned int uiSize);
};


struct CCE1C0AllocTagScope {
    int m_iSaved;

    CCE1C0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~CCE1C0AllocTagScope() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved; }
};

struct CCE1C0Vec {
    float x, y, z, w;
};

template <class T>
struct CCE1C0Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    CCE1C0Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
};

struct CCE1C0Child {
    CCE1C0Child() throw()
        : m_pkOwnerManager(0), m_fScale(::DAT_010c72bc), m_arr08(), m_arr14()
    {
    }

    void* m_pkOwnerManager;
    float m_fScale;
    CCE1C0Array<CCE1C0Vec> m_arr08;
    CCE1C0Array<CCE1C0Vec> m_arr14;

};

struct CCE1C0Owner {
    int unk00;
    int unk04;
    void* m_pParentNode;
    CCE1C0Child* m_pkChild;

    CCE1C0Child* GetOrCreateChild(bool* pbCreated);
};


class AutoMemContextC01 {
public:
    AutoMemContextC01(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = ::currentAllocationContext;
        ::currentAllocationContext = m_uiGeometryShaderFlags;
    }
    ~AutoMemContextC01() { ::currentAllocationContext = m_uiPrevious; }
    unsigned int m_uiPrevious;
};

class hkMemoryAllocatorC01 {
public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* p, int iNumBytes);
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* p, int iNumBytes);
};
struct hkMemoryRouterC01 {
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorC01* m_pTemp;
    hkMemoryAllocatorC01* m_pStreamAllocator;
    hkMemoryAllocatorC01& heap() { return *m_pStreamAllocator; }
};
hkMemoryRouterC01& __cdecl GetMemoryRouterC01();
template <typename T> __forceinline void constructWithCopyC01(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct hkArrayUtilC01
{
    static void __cdecl GrowArray(hkMemoryAllocatorC01& kAlloc, void* apvArray, int iSizeElem);
    static void __cdecl GrowArrayCapacity(hkMemoryAllocatorC01& kAlloc, void* apvArray, int iNumElements,
                                          int iSizeElem);
};

template <typename T> struct hkArrayC01 {
    hkArrayC01() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~hkArrayC01()
    {
        hkMemoryAllocatorC01& kAlloc = GetMemoryRouterC01().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    void clear() { m_iElementCount = 0; }
    __forceinline void ClearAndRelease()
    {
        hkMemoryAllocatorC01& kAlloc = GetMemoryRouterC01().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void AddBack(const T& t)
    {
        hkMemoryAllocatorC01& kAlloc = GetMemoryRouterC01().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)&(kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyC01(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void reserve(hkMemoryAllocatorC01& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n) {
            int iCap2 = 2 * iCap;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(GetMemoryRouterC01().heap(), n);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class NiCloningProcessC01;
class hkpShapeContainerC01;
class NiObjectC01 {
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
    virtual NiObjectC01* MakeClone(NiCloningProcessC01& kCloning);
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
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual hkpShapeContainerC01* GetContainer(char* pcOut);
};

template <class K, class V> struct NiTMapItemC01 {
    NiTMapItemC01* m_pkNext;
    K m_key;
    V m_val;
};
template <class K, class V> class NiTMapC01 {
public:
    virtual void v00();
    virtual unsigned int KeyToHashIndex(K key) const;
    virtual bool IsKeysEqual(K key1, K key2) const;
    bool GetAt(K key, V& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        NiTMapItemC01<K, V>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem) {
            if (IsKeysEqual(key, pkItem->m_key)) {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
    unsigned int m_uiHashSize;
    NiTMapItemC01<K, V>** m_ppkHashTable;
};

class NiCloningProcessC01 {
public:
    NiTMapC01<NiObjectC01*, NiObjectC01*>* m_pCloneMap;
};

class bhkRefObjectC01 : public NiObjectC01 {
public:
    unsigned int m_uiRefCount;
    void* m_phkObject;
};

class hkpShapeC01 {
public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    bhkRefObjectC01* m_pkWrapper;
};

class hkpShapeContainerC01 {
public:
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    hkArrayC01<hkpShapeC01*> m_kChildShapes;
};

class hkpListShapeC01 {
public:
    unsigned int unk00;
    unsigned int unk04;
};

class NiStreamC01 {
public:
};

class bhkListShapeC01 : public NiObjectC01 {
public:
    void FUN_00cd0170(NiStreamC01& kStream);
};

// Reads the child shape count from kStream, clears and reserves m_kChildShapes, loads each shape object, and calls LinkObjectBase.
// @fnv 0x00cd0170
void bhkListShapeC01::FUN_00cd0170(NiStreamC01& kStream)
{
    AutoMemContextC01 kContext(0x10);
    char cTmp;
    hkpShapeContainerC01* pkContainer = GetContainer(&cTmp);
    unsigned int ItemUpdateArray = reinterpret_cast<::FUN_00a63460_shell *>(&(kStream))->FUN_00a63460();
    hkArrayC01<hkpShapeC01*>& kShapes = pkContainer->m_kChildShapes;
    kShapes.ClearAndRelease();
    kShapes.reserve(GetMemoryRouterC01().heap(), ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++) {
        bhkRefObjectC01* pkObject = static_cast<bhkRefObjectC01*>(((::NiObjectC01 *)(reinterpret_cast<::NiStream *>(&(kStream))->GetLoadedObject())));
        if (pkObject)
            kShapes.AddBack(static_cast<hkpShapeC01*>(pkObject->m_phkObject));
    }
    ::FUN_00c84cc0((int *)this, (unsigned int)&(kStream));
}

class FUN_00cdb360_cls
{
public:
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    FUN_00cdb360_cls* FUN_00cdb360();
};
// @fnv 0x00cdb400
FUN_00cdb400::FUN_00cdb400(Binding* pBinding):u24(0),u28(0),binding(pBinding) {
 reinterpret_cast<::FUN_00c90510_class *>((pBinding))->FUN_00c90510();
 defaults.resize(1);
 Defaults temp(0);
 defaults.data[0]=*((::Defaults *)(reinterpret_cast<::FUN_00cdb360_cls *>(&(temp))->FUN_00cdb360()));
 int n=pBinding->boneCount;
 if(n!=pBinding->skeleton->count) {
  parents.resize(n,(short)-1);
  for(int i=0;i<pBinding->skeleton->count;i++) {
   int* pRemapping=pBinding->remapping;
   int iMappedIndex=pRemapping[i];
   if(iMappedIndex>=0) {
    int ancestor=i;
    int parent=-1;
    do { ancestor=pBinding->skeleton->parents[ancestor]; if(ancestor<0) break; parent=pRemapping[ancestor]; } while(parent<0);
    parents.data[iMappedIndex]=(short)parent;
   }
  }
 } else {
  parents.resize(n,(short)-1);
  for(int i=0;i<pBinding->skeleton->count;i++) parents.data[i]=pBinding->skeleton->parents[i];
 }
 pose.count=n;pose.name=pBinding->name;pose.parents=parents.data;
 transforms.resizeUninitialized(n);
 ::FUN_00d6b4b0((::BodyList *)(::PoseView *)(&pose),(::BodyOut *)(transforms.data));

}

// Sets the twelve float fields to fixed constants and returns this.
// @fnv 0x00cdb360
FUN_00cdb360_cls* FUN_00cdb360_cls::FUN_00cdb360()
{
    m_00 = 0.17f;
    m_04 = 0.0f;
    m_08 = 1.0f;
    m_0c = 0.6f;
    m_10 = 0.05f;
    m_14 = 1.4f;
    m_18 = 1.8f;
    m_1c = 0.1f;
    m_20 = 0.3f;
    m_24 = 0.3f;
    m_28 = 0.03f;
    m_2c = 0.1f;
    return this;
}

// 10024 bytes of scratch stack space with no array type (the original frame
// carries no /GS cookie), spelled as nested scalar blocks sized 8..8192.
struct CcScratch8 { int m0, m1; };
struct CcScratch32 { CcScratch8 m0, m1, m2, m3; };
struct CcScratch256 { CcScratch32 m0, m1, m2, m3, m4, m5, m6, m7; };
struct CcScratch512 { CcScratch256 m0, m1; };
struct CcScratch1K { CcScratch256 m0, m1, m2, m3; };
struct CcScratch8K { CcScratch1K m0, m1, m2, m3, m4, m5, m6, m7; };
struct CcScratchBuf { CcScratch8K a; CcScratch1K b; CcScratch512 c; CcScratch256 d; CcScratch32 e; CcScratch8 f; };

struct Cc0230Self {
	void* unk00;
	void* unk04;
	hkStreamWriter* unk08;
	Cc0230Self* WriteUInt16(unsigned short w);
};

// Formats w into a buffer and writes it to the stream in unk08, returning this.
// @fnv 0x00cc0230
Cc0230Self* Cc0230Self::WriteUInt16(unsigned short w)
{
	CcScratchBuf buffer;
	::Vsnprintf((char*)&buffer, 10024, "%u", w);
	FUN_00cc0080(unk08, (const char*)&buffer);
	return this;
}


struct FloatArgStream {
    void* m_pVtable;
    unsigned short m_iFlags;
    unsigned short m_iUnk;
    void* m_pSharedOwner;
    FloatArgStream* WriteFloat(float value);
};

// @fnv 0x00cc0320
FloatArgStream* FloatArgStream::WriteFloat(float value) {
    int buf[2506];
    ::Vsnprintf((char*)buf, 0x2728, str_01094cf0, value);
    FUN_00cc0080((hkStreamWriter*)m_pSharedOwner, (const char*)buf);
    return this;
}

extern const char str_010c9328[];

struct S00cc03c0_Obj {
    void* unk00;
    unsigned int unk04;
    hkStreamWriter* unk08;
    S00cc03c0_Obj* WriteToStream(unsigned __int64 v);
};

// Formats a string into a local buffer using Vsnprintf and writes it to the hkStreamWriter in unk08 via FUN_00cc0080.
// @fnv 0x00cc03c0
S00cc03c0_Obj* S00cc03c0_Obj::WriteToStream(unsigned __int64 v)
{
    int buf[0x9ca];
    ::Vsnprintf((char*)buf, 0x2728, str_010c9328, v);
    FUN_00cc0080(unk08, (const char*)buf);
    return this;
}

struct T { char pad[0x20]; unsigned short m_20; };
// @fnv 0x00cc0e00
static __declspec(noinline) T* FUN_00cc0e00(T* a, T* b)
{
    T* r = a;
    if (a->m_20 == 0xffff && b->m_20 != 0xffff)
        r = b;
    return r;
}
T* volatile g_a; T* volatile g_b; T* volatile g_sink;
void caller() { g_sink = FUN_00cc0e00(g_a, g_b); }

extern int DAT_010c93fc;



struct CC1290Object {


    CC1290Object() {
        new ((void *)this) struct ::FUN_00a5d3a0();
        m_pVtable = reinterpret_cast<void*>(&DAT_010c93fc);
        m_uiValue1 = 0;
        m_uiData1 = 0;
        m_uiData2 = 0;
        m_uiData3 = 0;
    }

    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
};

// Allocates and returns a new CC1290Object instance via its operator new.
// @fnv 0x00cc1290
CC1290Object* __cdecl CreateCC1290Object()
{
    return new CC1290Object;
}

struct LoadMM { void* Allocate(unsigned int); };
struct LoadTLS {
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
int context;
};
struct LoadScope { int old; LoadScope() { old=(*reinterpret_cast<::LoadTLS *>(&::g_tlsBlock)).context; (*reinterpret_cast<::LoadTLS *>(&::g_tlsBlock)).context=16; } ~LoadScope() { (*reinterpret_cast<::LoadTLS *>(&::g_tlsBlock)).context=old; } };
struct LoadIO { int unk00; unsigned int position; unsigned int (__cdecl *read)(LoadIO*,void*,unsigned int,unsigned int*,unsigned int); void Read(void* p) { unsigned int size=4; position+=read(this,p,4,&size,1); } };
struct LoadStringEntry { void* value; LoadStringEntry(); ~LoadStringEntry(); };
struct LoadElem { int a,b,c,d,e,f,g,h,i,j,k,l; };
struct LoadGroup { unsigned int count; LoadElem* data; LoadGroup() : count(0), data(0) {} };
struct LoadGroupPtr { LoadGroup* value; };
struct LoadStream278 {
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
LoadIO* io;  };
struct LoadObject { int unk00,unk04; unsigned int stringCount; LoadStringEntry* strings; unsigned int groupCount; LoadGroup** groups;  void FUN_00cc1730(LoadStream278&); };
// Reads string and group counts from the stream, allocates LoadStringEntry and LoadGroup arrays, and reads each string and group element.
// @fnv 0x00cc1730
void LoadObject::FUN_00cc1730(LoadStream278& stream) { LoadScope scope;unsigned& uiGroupCount=groupCount; reinterpret_cast<::FUN_00a5d610_Object *>(this)->ReadGroup((::NiStream *)&(stream)); stream.io->Read(&stringCount); if (stringCount>0) strings=new LoadStringEntry[stringCount]; for(unsigned int n=0;n<stringCount;++n) reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(stream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(strings[n])); stream.io->Read(&uiGroupCount); if(groupCount>0) groups=(LoadGroup**)new LoadGroupPtr[groupCount]; for(unsigned int n=0;n<groupCount;++n) { groups[n]=new LoadGroup; LoadGroup* group=groups[n]; stream.io->Read(&group->count); for(unsigned int j=0;j<group->count;++j) ::FUN_00cf0b00((::StreamViewCF0 *)&(stream),(::hkMatrixCF0 *)&(group->data[j])); } }

extern int DAT_010c970c;
extern int DAT_012685c4;
struct CC3D60Base
{
    void FUN_00c87c30();
};
struct CC3D60Object : CC3D60Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;


    CC3D60Object()
    {
        unsigned int count = 1;
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_010c5ef4;
        DAT_01268194 += count;
        m_pVtable = &DAT_010c970c;
        DAT_012685c4 += count;
    }
};
struct CC3D60Owner
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
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52(CC3D60Object* object, unsigned int argument);
    CC3D60Object* CreateObject(unsigned int argument);
};
// Allocates a CC3D60Object, passes it and the argument to virtual vf52, and returns it.
// @fnv 0x00cc3d60
CC3D60Object* CC3D60Owner::CreateObject(unsigned int argument)
{
    TlsHeapGuard guard;
    FUN_00c876f0();
    CC3D60Object* object = new CC3D60Object;
    vf52(object, argument);
    FUN_00c87700();
    return object;
}

struct ScopedMemoryCategory {
    unsigned int previous;
    ScopedMemoryCategory() : previous(::currentAllocationContext) { ::currentAllocationContext = 16; }
    ~ScopedMemoryCategory() { ::currentAllocationContext = previous; }
};

struct hkMemoryAllocatorCC3 {
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct hkMemoryRouterCC3 {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    hkMemoryAllocatorCC3* m_pStreamAllocator;
    hkMemoryAllocatorCC3& heap() { return *m_pStreamAllocator; }
};



struct CCVector {
    __m128 value;
    __forceinline void set(float x,float y,float z,float w) { value=_mm_setr_ps(x,y,z,w); }
    __forceinline CCVector& operator=(const CCVector& other) { value=other.value; return *this; }
};
struct ShapeInfoCC3 {
    unsigned int unk00;
    unsigned int m_uiArg1;
    unsigned int m_uiArg2;
    unsigned int unk0c;
    float pivotAx,pivotAy,pivotAz,pivotAw;
    float pivotBx,pivotBy,pivotBz,pivotBw;
    float m_fBoundRadius;
    float m_fFriction;
};

class hkReferencedObjectCC3 {
public:
    virtual ~hkReferencedObjectCC3();

    void* operator new(std::size_t nbytes)
    {
        hkReferencedObjectCC3* b = static_cast<hkReferencedObjectCC3*>(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    void operator delete(void* p, std::size_t nbytes)
    {
        ((hkMemoryRouterCC3*)static_cast<S_00cc4b90_Router*>(::FUN_00c85750()))->heap().ReleaseBlock(p, nbytes);
    }
     // removeReference

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00d4d980 : public hkReferencedObjectCC3 {
public:
    FUN_00d4d980(unsigned int a, unsigned int b, int c); // FUN_00d4d980

    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __forceinline void assign(float ax,float ay,float az,float aw,float bx,float by,float bz,float bw) { m_kMinimumCorner.value=_mm_setr_ps(ax,ay,az,aw);m_kMaximumCorner.value=_mm_setr_ps(bx,by,bz,bw); }
    CCVector m_kMinimumCorner;
    CCVector m_kMaximumCorner;
    float m_fBoundRadius;
    float m_fFriction;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
};

class ShapeOwnerCC3 {
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
    virtual void AddShape(FUN_00d4d980* pkShape);
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void Update(ShapeInfoCC3* pkInfo);
    void CreateShapeFromInfo(ShapeInfoCC3* pkInfo);
};

// Builds a shape from pkInfo's fields, adds it with AddShape, calls FUN_00c905b0 on it, then calls Update(pkInfo).
// @fnv 0x00cc3f40
void ShapeOwnerCC3::CreateShapeFromInfo(ShapeInfoCC3* pkInfo)
{
    ScopedMemoryCategory kScope;
    FUN_00d4d980* pkShape = new FUN_00d4d980(pkInfo->m_uiArg1, pkInfo->m_uiArg2, 0);
    pkShape->assign(pkInfo->pivotAx,pkInfo->pivotAy,pkInfo->pivotAz,pkInfo->pivotAw,pkInfo->pivotBx,pkInfo->pivotBy,pkInfo->pivotBz,pkInfo->pivotBw);
    pkShape->m_fBoundRadius = pkInfo->m_fBoundRadius;
    pkShape->m_fFriction = pkInfo->m_fFriction;
    AddShape(pkShape);
    reinterpret_cast<::hkReferencedObjectC905 *>((pkShape))->FUN_00c905b0();
    Update(pkInfo);
}

extern int DAT_010c97e4;
extern int DAT_012685d0;
struct CC42A0Base
{
    void FUN_00c87c30();
};
struct CC42A0Object : CC42A0Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;


    CC42A0Object()
    {
        unsigned int count = 1;
        reinterpret_cast<::FUN_00c87c30_t *>(this)->FUN_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_010c5ef4;
        DAT_01268194 += count;
        m_pVtable = &DAT_010c97e4;
        DAT_012685d0 += count;
    }
};
// Allocates and returns a new CC42A0Object instance via its operator new.
// @fnv 0x00cc42a0
CC42A0Object* CreateCC42A0Object()
{
    return new CC42A0Object;
}

struct SaveValues460 {
    unsigned long unk00, unk04, unk08, unk0C;
    volatile unsigned long value10, value14, value18, value1C, value20, value24;
};

struct SaveObject460 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B();
    virtual void v1C(); virtual void v1D(); virtual void v1E(); virtual void v1F();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v2A(); virtual void v2B();
    virtual void v2C();
    virtual SaveValues460* GetData(bool* flag);
    void FUN_00cc4460(FUN_00cc3c50_arg* stream);
};

inline void SwapValues460(SaveValues460* data) {
    data->value10 = _byteswap_ulong(data->value10);
    data->value14 = _byteswap_ulong(data->value14);
    data->value18 = _byteswap_ulong(data->value18);
    data->value1C = _byteswap_ulong(data->value1C);
    data->value20 = _byteswap_ulong(data->value20);
    data->value24 = _byteswap_ulong(data->value24);
}

// Byte-swaps value10 through value24 of the data when stream->m_1e4 is not 1, calls DispatchChainNodes, then swaps them back.
// @fnv 0x00cc4460
void SaveObject460::FUN_00cc4460(FUN_00cc3c50_arg* stream) {
    bool flag;
    SaveValues460* data = GetData(&flag);
    if (stream->m_1e4 != 1) SwapValues460(data);
    reinterpret_cast<::RefChainOwner *>(this)->DispatchChainNodes((::Dispatcher *)(stream));
    if (stream->m_1e4 != 1) SwapValues460(data);
}

struct ObjHook : S_00cc4b90_Obj {
};
namespace c4a80 {
struct Cls {
    int unk0;
    S_00cc4b90_Obj* m_p;
    int FUN_00cc4a80(S_00cc4b90_Obj* shape, int a2);
    int ReleaseObject(S_00cc4b90_Obj* shape, int a2);
};
// Uses shape or allocates one if null, attaches a child made from m_p->unk18, copies f20 and b24 from m_p, and returns ReleaseObject(shape, a2).
// @fnv 0x00cc4a80
int Cls::FUN_00cc4a80(S_00cc4b90_Obj* shape, int a2) {
    S_00cc4b90_Ctx ctx(0x10);
    S_00cc4b90_Obj* src = m_p;
    if (shape == 0)
        shape = new S_00cc4b90_Obj();
    if (src->unk18 != 0) {
        void* child = ((void *)(::CreateF4A30Result((::F4A30Node *)(void *)((void*)src->unk18), (void *)(a2))));
        if (child != 0) {
            reinterpret_cast<::fnv_00cc49b0::FUN_00cc49b0_class *>((((ObjHook*)shape)))->FUN_00cc49b0((::fnv_00cc49b0::FUN_00c90510_class *)(child));
            reinterpret_cast<::hkReferencedObjectC905 *>((((FUN_00cca450_hook*)child)))->FUN_00c905b0();
        }
    }
    shape->f20 = src->f20;
    unsigned char b = *(volatile unsigned char*)&src->b24;
    shape->b24 = b;
    return ReleaseObject(shape, a2);
}
}

inline unsigned int GetMemContext4D40()
{
    return ::currentAllocationContext;
}
inline void SetMemContext4D40(unsigned int m_uiGeometryShaderFlags)
{
    ::currentAllocationContext = m_uiGeometryShaderFlags;
}
class AutoMemContext4D40 {
public:
    AutoMemContext4D40(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContext4D40();
        SetMemContext4D40(m_uiGeometryShaderFlags);
    }
    ~AutoMemContext4D40() { SetMemContext4D40(m_uiPrevious); }
    unsigned int m_uiPrevious;
};

struct MemoryManager4D40 {
    void* Allocate(unsigned int uiSize);
};

class PolyBase4D40 {
public:
    void* m_pVtable;
};

struct Interface4D40 {
    Interface4D40() {}
    int m_iFirst;
    int m_iArrayLength;
    int m_iA;
    int m_iB;
};

class Object4D40 : public PolyBase4D40, public Interface4D40 {
public:
    Object4D40() { Interface4D40* self = this; m_iArrayLength = 1; m_iA = 0; m_iB = 0; m_pVtable = &DAT_010c99e0; self->m_iFirst = 0; }
};

class Owner4D40 {
public:
    Interface4D40* GetOrCreateInterface(bool* pbCreated);
    void SetObject(Object4D40* pkObject);

    int unk00;
    int unk04;
    int m_iActive;
    Interface4D40* m_pkInterface;
};

// Creates an Object4D40 if m_pkInterface is null, sets *pbCreated, and returns the interface pointer.
// @fnv 0x00cc4d40
Interface4D40* Owner4D40::GetOrCreateInterface(bool* pbCreated)
{
    AutoMemContext4D40 kContext(0x10);
    bool bCreate = m_pkInterface == 0;
    *pbCreated = bCreate;
    if (bCreate) {
        m_pkInterface = new Object4D40;
        if (m_iActive)
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((void*)(static_cast<Object4D40*>(m_pkInterface)));
    }
    return m_pkInterface;
}

struct ViewerMemoryContext {
    int previous;
    ViewerMemoryContext() : previous((*reinterpret_cast<int *>(&::currentAllocationContext))) { (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16; }
    ~ViewerMemoryContext() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = previous; }
};
struct ViewerStrings {
    void* vtable;
    char** values;
    unsigned short capacity, count, used, growth;
    void FUN_0096ad30(unsigned int);
    void Append(char* value) {
        unsigned int index = count;
        if (index >= capacity) FUN_0096ad30(index + growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
public:
    void SetSize(unsigned int);
};
inline void AppendViewerString(ViewerStrings* strings, char* value) {
    unsigned int index = strings->count;
    if (index >= strings->capacity) strings->SetSize(index + strings->growth);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strings))->SetAt(index, value);
}
class BC8AD40StringArray;
struct ViewerConstraint {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vC();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual int type();
public:
    void FUN_00c8a560(::BC8AD40StringArray *);
};
// @fnv 0x00cc7090
void FUN_00cc7090_class::AppendConstraintParams(StrArr* strArr)
{
    reinterpret_cast<::ViewerConstraint *>((this))->FUN_00c8a560((::BC8AD40StringArray *)(strArr));

    FUN_00cc7090_Constraint* constraint = m_pConstraint;
    if (!constraint)
        return;

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        ::FUN_004a3970((::NiPoint3_local &)(point), constraint->m_kPivotInA);
        value = point.FUN_00a59af0("PivotInA");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        ::FUN_004a3970((::NiPoint3_local &)(point), constraint->m_planeAxisA);
        value = point.FUN_00a59af0("planeAxisA");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        ::FUN_004a3970((::NiPoint3_local &)(point), constraint->m_twistAxisA);
        value = point.FUN_00a59af0("twistAxisA");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        ::FUN_004a3970((::NiPoint3_local &)(point), constraint->m_kPivotInB);
        value = point.FUN_00a59af0("PivotInB");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        ::FUN_004a3970((::NiPoint3_local &)(point), constraint->m_planeAxisB);
        value = point.FUN_00a59af0("planeAxisB");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        NiPoint3_local point;
        char* value;
        unsigned int index;

        ::FUN_004a3970((::NiPoint3_local &)(point), constraint->m_twistAxisB);
        value = point.FUN_00a59af0("twistAxisB");
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00a7d550("ConeMinAngle", constraint->m_fConeMinAngle * DAT_0102f248);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00a7d550("PlaneMinAngle", constraint->m_fPlaneMinAngle * DAT_0102f248);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00a7d550("PlaneMaxAngle", constraint->m_fPlaneMaxAngle * DAT_0102f248);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00a7d550("TwistMinAngle", constraint->m_fTwistMinAngle * DAT_0102f248);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00a7d550("TwistMaxAngle", constraint->m_fTwistMaxAngle * DAT_0102f248);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = FUN_00a7d550("MaxFrictionTrq", constraint->m_fMaxFrictionTrq);
        index = strArr->m_usElementCount;
        if (index >= strArr->m_usSize)
            reinterpret_cast<::ViewerStrings *>((strArr))->SetSize(strArr->m_usIncrement + index);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((strArr))->SetAt(index, value);
    }
}
// Serializes the base data, then appends formatted pivot, planeA, axis, minAngle and maxAngle strings from the constraint data to the string array.
// @fnv 0x00cc8ad0
void ConstraintSerializer::SerializeConstraintData(StrArr* strings)
{
    SerializationMemoryContext context;
    reinterpret_cast<::ViewerConstraint *>(this)->FUN_00c8a560((::BC8AD40StringArray *)(strings));
    ConstraintSerializationData* constraint = data;
    if (constraint) {
        NiPoint3 vector;
        ::FUN_004a3970((::NiPoint3_local &)(vector), constraint->pivot);
        AppendConstraintString(strings, vector.FUN_00a59af0(DAT_010c8388));
        ::FUN_004a3970((::NiPoint3_local &)(vector), constraint->planeA);
        AppendConstraintString(strings, vector.FUN_00a59af0(DAT_010c8378));
        ::FUN_004a3970((::NiPoint3_local &)(vector), constraint->axis);
        AppendConstraintString(strings, vector.FUN_00a59af0(DAT_010c8368));
        AppendConstraintString(strings, FUN_00a7d550(DAT_010c835c, constraint->minAngle));
        AppendConstraintString(strings, FUN_00a7d550(DAT_010c8350, constraint->maxAngle));
    }
}
struct ConstraintViewer {
    virtual ~ConstraintViewer();
    virtual void v4(); virtual void v8(); virtual void vC(); virtual void v10();
    virtual void GetStrings(ViewerStrings*);
};
extern const char DAT_010c9a04[], DAT_010c99f8[];
struct ViewerFlag { unsigned char value; operator bool() const { return value != 0; } };
struct ViewerData {
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    ViewerConstraint* constraint;
    int unk1C;
    float strength;
    ViewerFlag enabled;
    ViewerConstraint* GetConstraint() { return constraint; }
};
struct DataViewer {
    void* vtable;
    ViewerData* data;
    ViewerData* GetData() { return data; }
    float Strength() { return GetData() ? GetData()->strength : 0.0f; }
    bool Enabled() { return GetData() ? bool(GetData()->enabled) : false; }
    ViewerConstraint* Constraint() { return GetData() ? GetData()->GetConstraint() : 0; }
    void FUN_00cc4f00(ViewerStrings* strings);
};
// Appends strength and enabled strings, then appends constraint-specific strings via a ConstraintViewer created from the constraint type.
// @fnv 0x00cc4f00
void DataViewer::FUN_00cc4f00(ViewerStrings* strings) {
    ViewerMemoryContext context;
    reinterpret_cast<::ViewerConstraint *>(this)->FUN_00c8a560((::BC8AD40StringArray *)(strings));
    AppendViewerString(strings, FUN_00a7d550(DAT_010c9a04, Strength()));
    AppendViewerString(strings, FUN_00a7d370(DAT_010c99f8, Enabled()));
    ViewerConstraint* constraint = Constraint();
    if (constraint) {
        int t = constraint->type();
        ConstraintViewer* viewer = ((::ConstraintViewer *)(::CreateSaver(t)));
        if (viewer) {
            reinterpret_cast<::C89AC0_Owner *>((viewer))->SetChildObject((::C89AC0_Child *)(constraint));
            viewer->GetStrings(strings);
            delete viewer;
        }
    }
}

struct FUN_00d4f2a0 {
    int unk00;
    unsigned short m_us4;
    FUN_00d4f2a0();
    void* operator new(std::size_t, unsigned int n) {
        void* b = static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap().AllocateMemoryBlock(n);
        ((FUN_00d4f2a0*)b)->m_us4 = (unsigned short)n;
        return b;
    }
    void operator delete(void*, std::size_t) {}
};

struct S00cc6030_Cls {
    void* unk00;
    FUN_00d4f2a0* unk04;
    int FUN_00cc6030();
};

// Allocates a FUN_00d4f2a0 object of 0xc0 bytes into unk04 if it is null, then returns 0xc0.
// @fnv 0x00cc6030
int S00cc6030_Cls::FUN_00cc6030()
{
    if (unk04 == 0)
    {
        unk04 = new (0xc0u) FUN_00d4f2a0();
    }
    return 0xc0;
}

struct FUN_00d52fc0 : S_00cc4b90_RefObj
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
    FUN_00d52fc0();
};
struct CC86C0Owner
{
    int unk00;
    FUN_00d52fc0* m_pObject;
    int FUN_00cc86c0();
};
// Allocates m_pObject if null and returns the size of the FUN_00d52fc0 object.
// @fnv 0x00cc86c0
int CC86C0Owner::FUN_00cc86c0()
{
    TlsHeapGuard guard;
    if (!m_pObject)
        m_pObject = new FUN_00d52fc0;
    return sizeof(FUN_00d52fc0);
}

extern int DAT_010ca050;
static __forceinline CC7970_RefData* CC8850_CreateReference() {
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<::MemoryManagerStandIn *>((reinterpret_cast<CC7970_Allocator*>(&(*reinterpret_cast<::FUN_00cc2a00_alloc *>(&::g_memoryManager)))))->FUN_00aa3e40(sizeof(CC7970_RefObject)));
    if (object) {
        CC7970_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010ca050;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
struct CC8850_Owner {
    unsigned int m_unk00, m_unk04, m_flag08;
    CC7970_RefData* m_pData;
    CC7970_RefData* GetOrCreateReference(bool* created);
};
// Creates a CC7970_RefObject if m_pData is null, calls CopyFromSource on it when m_flag08 is set, and returns m_pData.
// @fnv 0x00cc8850
CC7970_RefData* CC8850_Owner::GetOrCreateReference(bool* created)
{
    TlsHeapGuard guard;
    *created = m_pData == 0;
    if (*created) {
        CC7970_RefData* data = CC8850_CreateReference();
        m_pData = data;
        if (m_flag08)
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((void*)(data ? reinterpret_cast<CC7970_RefObject*>(reinterpret_cast<char*>(data) - 4) : 0));
    }
    return m_pData;
}

struct A9410Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* pointer, unsigned int size);
};

struct O9410;

struct G9410
{
    O9410* m_pSharedOwner;
    G9410(void* p) { m_pSharedOwner = (O9410*)p; }
    ~G9410();
};

struct O9410
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    void* m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiValue1;

    void FUN_00cc9410();
};

G9410::~G9410()
{
    m_pSharedOwner->m_pVtable = &DAT_0108ffb4;
    reinterpret_cast<::C89AC0_Owner *>((m_pSharedOwner))->SetChildObject((::C89AC0_Child *)(0));
}

// @fnv 0x00cc9410
void O9410::FUN_00cc9410()
{
    G9410 guard(this);
    S_00cc4b90_Router* router = static_cast<S_00cc4b90_Router*>(::FUN_00c85750());
    A9410Alloc* alloc = (A9410Alloc*)router->unk10;
    m_uiCount = 0;
    if ((m_uiValue1 & 0x80000000u) == 0)
    {
        void* data = m_pData;
        unsigned int tmp0 = m_uiValue1 & 0x3fffffff;
        alloc->Free(data, (tmp0) * 4u);
    }
    m_pData = 0;
    m_uiValue1 = 0x80000000;
}

extern "C" void* DAT_010ca22c;

struct S00cc9560_TlsFlag {
    int m_saved;
    S00cc9560_TlsFlag() {
        m_saved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x10;
    }
    ~S00cc9560_TlsFlag() {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_saved;
    }
};

struct CacheValueVbase {
    void* m_pVtbl;
};
struct CacheValueFields {
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    CacheValueFields() {
        m_uiRefCount = 0;
        m_uiValue1 = 1;
        m_uiData1 = 0;
        m_uiData2 = 0;
    }
};
struct CacheValueMid {
    unsigned int m_uiData3;
    unsigned int m_uiData4;
    CacheValueMid() {
        m_uiData3 = 0;
        m_uiData4 = 0;
    }
};
struct CacheValue : CacheValueVbase, CacheValueFields, CacheValueMid {
    unsigned int m_uiCapacityAndFlags;
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiFinalFlags;
    CacheValue() : CacheValueFields(), CacheValueMid() {
        m_uiCapacityAndFlags = 0x80000000;
        m_pVtbl = &DAT_010ca22c;
        m_pData = 0;
        m_uiSize = 0;
        m_uiFinalFlags = 0x80000000;
    }
};

struct CacheOwner {
    unsigned int unk00;
    unsigned int unk04;
    void* m_pSharedOwner;
    CacheValueFields* m_pIntegerData;
    void* GetOrCreateCacheValue(bool* created);
};

// Ensures m_pIntegerData points to a CacheValue, creating one if absent and reporting via created whether it was newly created.
// @fnv 0x00cc9560
void* CacheOwner::GetOrCreateCacheValue(bool* created)
{
    S00cc9560_TlsFlag tlsGuard;
    bool wasEmpty = (m_pIntegerData == 0);
    *created = wasEmpty;
    if (wasEmpty) {
        CacheValue* object = new CacheValue;
        m_pIntegerData = object;
        if (m_pSharedOwner != 0) {
            reinterpret_cast<::fnv_00cc91c0::FUN_00cc91c0_cls *>(this)->FUN_00cc91c0((::fnv_00cc91c0::VectorOutput *)(void *)(static_cast<CacheValue*>(m_pIntegerData)));
        }
    }
    return m_pIntegerData;
}

extern int DAT_010c8cc8;
static __forceinline CC7970_RefData* CC9A20_CreateReference() {
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<::MemoryManagerStandIn *>((reinterpret_cast<CC7970_Allocator*>(&(*reinterpret_cast<::FUN_00cc2a00_alloc *>(&::g_memoryManager)))))->FUN_00aa3e40(sizeof(CC7970_RefObject)));
    if (object) {
        CC7970_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010c8cc8;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
struct CC9A20_Owner {
    unsigned int m_unk00, m_unk04, m_flag08;
    CC7970_RefData* m_pData;
    CC7970_RefData* EnsureReference(bool* created);
};
// Creates a CC7970_RefData reference on first call, copies source data if m_flag08 is set, and returns m_pData.
// @fnv 0x00cc9a20
CC7970_RefData* CC9A20_Owner::EnsureReference(bool* created)
{
    TlsHeapGuard guard;
    *created = m_pData == 0;
    if (*created) {
        CC7970_RefData* data = CC9A20_CreateReference();
        m_pData = data;
        if (m_flag08)
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((void*)(data ? reinterpret_cast<CC7970_RefObject*>(reinterpret_cast<char*>(data) - 4) : 0));
    }
    return m_pData;
}

extern "C" int (__cdecl *DAT_00fdf1c4)(void*);

class NiRefObject {
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};

struct FUN_00ccbc00_elem {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C;
    unsigned int unk10; unsigned int m_14; unsigned int unk18; unsigned int unk1C;
    unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2C;
    unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3C;
    unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4C;
    unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C;
};

struct FUN_00ccbc00_inner {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C;
    unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1C;
    unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2C;
    unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3C;
    unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4C;
    unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C;
    unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6C;
    unsigned int unk70; unsigned int unk74; unsigned int unk78; unsigned int unk7C;
    unsigned int unk80; unsigned int unk84; unsigned int unk88; unsigned int unk8C;
    unsigned int unk90; unsigned int unk94; unsigned int unk98; unsigned int unk9C;
    unsigned int unkA0; unsigned int unkA4; unsigned int unkA8; unsigned int unkAC;
    unsigned int unkB0; FUN_00ccbc00_elem* m_b4; unsigned int m_b8;
};


struct CcbcOwnerBase {
    ~CcbcOwnerBase() { reinterpret_cast<::FUN_00cd2de0 *>(this)->FUN_00cd2de0::~FUN_00cd2de0(); }
};

struct RefSmartPtr {
    NiRefObject* ptr;
    ~RefSmartPtr() {
        NiRefObject* p = ptr;
        if (p) {
            if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0) p->DeleteThis();
        }
    }
};

class FUN_00ccbc00 : public CcbcOwnerBase {
public:
    void* volatile m_pVtable;
    unsigned int unk04;
    FUN_00ccbc00_inner* volatile m_08;
    unsigned int unk0c;
    unsigned int unk10;
    RefSmartPtr m_14;
    ~FUN_00ccbc00();
};

// Sets vtable to DAT_010ca744, zeroes m_14 in each m_b4 element, calls FUN_00c876a0, decrements DAT_01268678, and releases m_14.ptr.
// @fnv 0x00ccbc00
FUN_00ccbc00::~FUN_00ccbc00() {
    m_pVtable = (void*)&DAT_010ca744;
    FUN_00ccbc00_inner* x = m_08;
    if ((int)x->m_b8 > 0) {
        int n = (int)x->m_b8;
        unsigned int off = 0;
        do {
            *(unsigned int*)((char*)x->m_b4 + off + 0x14) = 0;
            off += 0x60;
        } while (--n != 0);
    }
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    int one = 1;
    DAT_01268678 -= one;
    NiRefObject* p = m_14.ptr;
    if (p) {
        if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0) p->DeleteThis();
        m_14.ptr = 0;
    }

}

class S00ccd2c0_Obj {
};

struct S00ccd2c0_Arg2 {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    float m_10;
};

class S00ccd2c0_cls {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual S00ccd2c0_Obj* v45(bool* flag);
    int FUN_00c84df0(void* a1, S00ccd2c0_Arg2* a2);
    int FUN_00ccd2c0(void* a1, S00ccd2c0_Arg2* a2);
};

// Gets an object via v45, passes a2->m_10 to its FUN_00ccd170 when it is not 1.0f, then returns FUN_00c84df0(a1, a2).
// @fnv 0x00ccd2c0
int S00ccd2c0_cls::FUN_00ccd2c0(void* a1, S00ccd2c0_Arg2* a2)
{
    bool flag;
    S00ccd2c0_Obj* obj = v45(&flag);
    float f = a2->m_10;
    if (f != 1.0f) {
        reinterpret_cast<::FUN_00ccd170_cls *>((obj))->FUN_00ccd170(f);
    }
    return FUN_00c84df0(a1, a2);
}

struct CCD460Owner
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
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49(FUN_00ccd100* object, unsigned int argument);
    FUN_00ccd100* FUN_00ccd460(unsigned int argument);
};
// Allocates a new FUN_00ccd100, passes it and argument to vf49, and returns it, between calls to FUN_00c876f0 and FUN_00c87700.
// @fnv 0x00ccd460
FUN_00ccd100* CCD460Owner::FUN_00ccd460(unsigned int argument)
{
    TlsHeapGuard guard;
    FUN_00c876f0();
    FUN_00ccd100* object = new FUN_00ccd100;
    vf49(object, argument);
    FUN_00c87700();
    return object;
}

struct EE60Vec
{
    __m128 m_vComponents;

    __forceinline void operator=(const EE60Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
};

struct EE60Mat
{
    EE60Vec m_kColumn0;
    EE60Vec m_kColumn1;
    EE60Vec m_kColumn2;

    __forceinline void setIdentity()
    {
        EE60Vec zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn1 = zero;
        m_kColumn2 = zero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct EE60Xf
{
    EE60Mat m_rotation;
    EE60Vec m_vTranslation;

    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

inline int GetMemContext() { return (*reinterpret_cast<int *>(&::currentAllocationContext)); }
inline void SetMemContext(int aiMemoryContext) { (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext; }
struct MemContextGuard {
    int m_iSaved;
    MemContextGuard(int aiMemoryContext) { m_iSaved = GetMemContext(); SetMemContext(aiMemoryContext); }
    ~MemContextGuard() { SetMemContext(m_iSaved); }
};

class EE60MemMgr { public: void* Allocate(unsigned int); };


struct CcEE60Data
{
    int unk00;
    float m_f04;
    int unk08;
    int unk0C;
    EE60Xf m_kMotionTransform;

    static void* operator new(std::size_t nbytes)
    {
        unsigned char* p = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::EE60MemMgr *>(&::g_memoryManager))))->FUN_00aa3e40(nbytes + 16);
        unsigned char offset = (unsigned char)(16 - ((unsigned int)p & 15));
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void* p);

    CcEE60Data()
    {
        unk00 = 0;
        m_f04 = DAT_010c72bc;
        unk08 = 0;
        m_kMotionTransform.setIdentity();
    }
};

class CcEE60Self
{
public:
    int unk00;
    int unk04;
    int m_08;
    CcEE60Data* m_data;

    CcEE60Data* FUN_00ccee60(bool* created);
};

// Creates m_data if null, calls FUN_00ccea00 when m_08 is set, and returns m_data.
// @fnv 0x00ccee60
CcEE60Data* CcEE60Self::FUN_00ccee60(bool* created)
{
    MemContextGuard kGuard(16);
    *created = (m_data == 0);
    if (*created)
    {
        m_data = new CcEE60Data();
        if (m_08)
            reinterpret_cast<::FUN_00ccea00Holder *>(this)->FUN_00ccea00((::FUN_00ccea00Out *)(m_data));
    }
    return m_data;
}

struct CD05E0_Alloc { void FUN_00aa4060(void* p); };
struct CD05E0_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct CD05E0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct CD05E0_Owner
{
    int unk00;
    int unk04;
    int unk08;
    CD05E0_Obj* m_pEntryObject;
    void FUN_00cd05e0(bool release);
};
// If release is set, frees m_pEntryObject's data buffer and then the object itself, and sets m_pEntryObject to null.
// @fnv 0x00cd05e0
void CD05E0_Owner::FUN_00cd05e0(bool release)
{
    TlsHeapGuard guard;
    if (release) {
        CD05E0_Obj* obj = m_pEntryObject;
        if (obj) {
            S_00cc4b90_Router* router = static_cast<S_00cc4b90_Router*>(::FUN_00c85750());
            CD05E0_Heap* alloc = (CD05E0_Heap*)router->unk10;
            obj->m_iElementCount = 0;
            if ((obj->m_iCapacityState & 0x80000000) == 0)
                alloc->ReturnMemory(obj->m_data, (obj->m_iCapacityState & 0x3fffffff) * 4);
            obj->m_data = 0;
            obj->m_iCapacityState = 0x80000000;
            reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<CD05E0_Alloc*>(&(*reinterpret_cast<::FUN_00cc2a00_alloc *>(&::g_memoryManager)))))->FUN_00aa4060(obj);
        }
        m_pEntryObject = 0;
    }
}

struct WorkingState { __declspec(align(16)) unsigned char data[512]; };
struct Arg;
struct ActionTarget {
virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
virtual void v52();
    virtual void apply(Arg* first, Arg* second);
};
struct Result { int ReportDiagnostic; int unused4; ActionTarget* action; };
struct Cursor {
    virtual void reserved0();
    virtual void reserved1();
    virtual int first();
    virtual int next(int index);
    virtual void FunctionAtSlot4();
    virtual Result* lookup(int index, WorkingState* state);
};
struct Collection {
    int unk00, unk04, unk08, unk0C;
    Cursor cursor;
};
struct Dispatcher {
    int unk00, unk04;
    Collection* collection;
    void ApplyAll(Arg* argument1, Arg* argument2);
};
static inline ActionTarget* getAction(Dispatcher* d, int position, WorkingState& state) {
    Collection* c;
    if (d && (c = d->collection) != 0) {
        Result* result = c->cursor.lookup(position, &state);
        if (result) return result->action;
    }
    return 0;
}
// Iterates the collection cursor and calls apply on each action target, stopping when a lookup fails.
// @fnv 0x00cd2e50
void Dispatcher::ApplyAll(Arg* argument1, Arg* argument2) {
    WorkingState state;
    int position = (this ? collection : 0)->cursor.first();
    bool bContinue = true;
    while (bContinue && position != -1) {
        ActionTarget* action = getAction(this, position, state);
        position = (this ? collection : 0)->cursor.next(position);
        if (action) action->apply(argument1, argument2);
        else bContinue = false;
    }
}

struct TargetAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void ReleaseBlock(void* data, int size);
    void ReturnMemory(void* data, int size) { ReleaseBlock(data, size); }
};
struct TargetReferencedObject {  };
struct TargetContact {
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
};
template<class T> struct AllocatorArray {
    T* data;
    int size;
    int capacityAndFlags;
    static void deallocate(TargetAllocator& a, T* p, int n) { a.ReturnMemory(p, n * int(sizeof(T))); }
    int GetLogicalSize() const { return size; }
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void ClearAndRelease(TargetAllocator& allocator) {
        size = 0;
        if (!(capacityAndFlags & 0x80000000))
            deallocate(allocator, data, getCapacity());
        data = 0;
        capacityAndFlags = 0x80000000;
    }
    void ClearAndRelease() {
        ClearAndRelease(reinterpret_cast<TargetAllocator&>(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap()));
    }
    ~AllocatorArray() { ClearAndRelease(reinterpret_cast<TargetAllocator&>(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap())); }
};
struct TargetCollectorBase {
    virtual ~TargetCollectorBase();
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
};
struct FUN_00cd3490 : TargetCollectorBase {
    AllocatorArray<TargetReferencedObject*> references;
    AllocatorArray<unsigned int> indices;
    AllocatorArray<TargetContact> contacts;
    virtual ~FUN_00cd3490();
};
// Releases all TargetReferencedObject references, then clears and releases the references, contacts, and indices arrays.
// @fnv 0x00cd3490
FUN_00cd3490::~FUN_00cd3490() {
    for (int i = 0; i < references.GetLogicalSize(); ++i)
        reinterpret_cast<::hkReferencedObjectC905 *>((references.data[i]))->FUN_00c905b0();
    references.ClearAndRelease();
    contacts.ClearAndRelease();
    indices.ClearAndRelease();
}

struct __declspec(align(16)) hkMatrix3_Scaled {
    __m128 col0;
    __m128 col1;
    __m128 col2;
    const __m128* FUN_00cd4d40(const __m128* scale, const hkMatrix3_Scaled* source);
};
// Multiplies each column of source by the scalar broadcast from scale and stores the result in this hkMatrix3_Scaled.
// @fnv 0x00cd4d40
const __m128* hkMatrix3_Scaled::FUN_00cd4d40(const __m128* scale, const hkMatrix3_Scaled* source)
{
    col0 = _mm_mul_ps(_mm_shuffle_ps(*scale, *scale, 0), source->col0);
    col1 = _mm_mul_ps(_mm_shuffle_ps(*scale, *scale, 0), source->col1);
    col2 = _mm_mul_ps(_mm_shuffle_ps(*scale, *scale, 0), source->col2);
    return scale;
}

struct FUN_00cd7d20_Class {
    void FUN_00cd7d20(float* param1, float param2, float* param3);
};

// @fnv 0x00cd7d20
void FUN_00cd7d20_Class::FUN_00cd7d20(float* param1, float afScalar, float* apResult) {

    __m128 v_this30 = *reinterpret_cast<__m128*>(reinterpret_cast<char*>(this) + 0x30);

    __m128 v_param1_30 = *reinterpret_cast<__m128*>(param1 + 0x30 / sizeof(float));

    __m128 v_this20 = *reinterpret_cast<__m128*>(reinterpret_cast<char*>(this) + 0x20);

    __m128 sum1 = _mm_add_ps(v_param1_30, v_this30);

    __m128 vScalar = _mm_set1_ps(afScalar);
    __m128 sum2 = _mm_add_ps(vScalar, v_this20);

    __m128 diff = _mm_sub_ps(sum1, sum2);

    __m128 final_sum = _mm_add_ps(sum1, sum2);

    *reinterpret_cast<__m128*>(apResult) = diff;

    *reinterpret_cast<__m128*>(apResult + 4) = final_sum;
}


void __cdecl FUN_00aa1460(void* p);
namespace nd {
struct Arr { void* p; unsigned int n; unsigned int cap; Arr() : p(0), n(0), cap(0x80000000) {} };
}
class FUN_00cce290 {
public:
    int m_iWordAt00;
    float m_iWordAt04;
    nd::Arr m_8;
    nd::Arr m_14;
    FUN_00cce290() : m_iWordAt00(0) {}
    ~FUN_00cce290();
};
struct SrcD;
struct SrcD { int m_iWordAt00; int m_iWordAt04; };
class FUN_00cd7e80 {
public:
    char pad[0x14];
    FUN_00cd7e80(FUN_00cce290* data);
};
// Builds a FUN_00cd7e80 from a temporary data struct filled from src when src->m_iWordAt04 is nonzero, otherwise returns null.
// @fnv 0x00cd7f50
FUN_00cd7e80* CreateFromSource(SrcD* src)
{
    TlsHeapGuard guard;
    FUN_00cd7e80* result = 0;
    FUN_00cce290 data;
    data.m_iWordAt04 = DAT_010c72bc;
    if (src->m_iWordAt04 != 0) {
        ::LoadIntoArray((const ::InputBuffer *)(src), (unsigned int)(&data.m_14), (::ArrayData *)(::nd::Arr *)(&data.m_8));
        result = new FUN_00cd7e80(&data);
    }
    return result;
}

struct FUN_00cdb290 {
    StateResetPart* FUN_00cdb0a0();
};

namespace fnv_00cdb0b0 {
template<class T> struct PoseArray {
    T* data;
    int size;
    int capacity;
    T& operator[](int i) { return data[i]; }
};
struct PoseTransform {
    __m128 translation;
    __m128 rotation;
    __m128 scale;
};
struct PoseBone {
    const char* name;
    bool locked;
    unsigned char unk05;
    unsigned short unk06;
};
struct PoseSkeleton {
    int unk00;
    int unk04;
    int unk08;
    PoseArray<short> parents;
    PoseArray<PoseBone> bones;
    PoseArray<PoseTransform> referencePose;
};
struct FUN_00cdb290 {
    PoseSkeleton* skeleton;
    PoseArray<PoseTransform> localPose;
    PoseArray<PoseTransform> modelPose;
    PoseArray<unsigned int> flags;
    void FUN_00cda690();
    void UpdateLockedPoseFlags();
};
// @fnv 0x00cdb0b0
void FUN_00cdb290::UpdateLockedPoseFlags()
{
    int n = skeleton->bones.size;
    FUN_00cda690();
    for (int i = 0; i < n; ++i) {
        if (skeleton->bones[i].locked) {
            localPose[i].translation = skeleton->referencePose[i].translation;
            flags[i] |= 2;
            flags[i] |= 4;
        } else {
            short parent = skeleton->parents[i];
            if (parent != -1 && (flags[parent] & 4)) {
                flags[i] |= 2;
                flags[i] |= 4;
            }
        }
    }
    int flagCount = flags.size;
    for (int i = 0; i < flagCount; ++i)
        flags[i] &= ~28u;
}
}  // namespace fnv_00cdb0b0

struct EntryState { unsigned int id; unsigned char active,mode; unsigned short category; };
struct __declspec(align(16)) EntryData { __m128 coordinates,rotation,metadata; };
struct FUN_00cdd2d0_Input {
 int unk00,unk04,unk08,unk0c,unk10,unk14;
 EntryState* states;
 int size;
 int unk20;
 EntryData* entries;
};
// Copies EntryData records from input->entries to output for each active state in input->states, skipping inactive entries.
// @fnv 0x00cdd2d0
extern "C" void __cdecl FUN_00cdd2d0(FUN_00cdd2d0_Input* input, EntryData* output)
{
    int count = input->size;
    int index = 0;
    if (count <= 0) return;
    unsigned int offset = 0;
    do {
        if (input->states[index].active) {
            const __m128* value = (const __m128*)((const char*)input->entries + offset);
            __m128* destination = (__m128*)((char*)output + offset);
            *destination = *value;
        }
        ++index;
        offset += sizeof(EntryData);
    } while (index < count);
}

namespace fnv_00cdd320 {

struct FUN_00cdd320_Entry {
    int unk00;
    char unk04;
};

struct FUN_00cdd320_Elem {
    __m128 unk00;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct FUN_00cdd320_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00cdd320_Entry* unk18;
    int unk1C;
};

// Copies the first 16 bytes of each source element to the destination where the corresponding entry flag is set.
// @fnv 0x00cdd320
void __cdecl CopySelectedElements(FUN_00cdd320_Obj* obj, FUN_00cdd320_Elem* src, FUN_00cdd320_Elem* dst)
{
    int count = obj->unk1C;
    for (int i = 0; i < count; ++i) {
        if (obj->unk18[i].unk04) {
            *(__m128*)&dst[i].unk00 = *(const __m128*)&src[i].unk00;
        }
    }
}
}  // namespace fnv_00cdd320

namespace scdd360 {

struct Slot {
    int m_iData;
    bool m_bValueAt0C;
};

struct Table {
    int unk000;
    int unk004;
    int unk008;
    short* m_psCounts;
    int unk010;
    int unk014;
    Slot* m_pkSlots;
    int m_iArrayLength;
};

struct Flag {
    bool b;
};

// Sets m_bValueAt0C on each slot whose count is positive, or on all slots when kOnlyActive.b is false.
// @fnv 0x00cdd360
void FUN_00cdd360(Table* pkTable, Flag kOnlyActive)
{
    int iCount = pkTable->m_iArrayLength;
    for (int i = 0; i < iCount; ++i)
    {
        if (pkTable->m_psCounts[i] > 0 || !kOnlyActive.b)
            pkTable->m_pkSlots[i].m_bValueAt0C = true;
    }
}

}

struct hkVector4_s {
    __m128 m_vComponents;
    void setZero4() { m_vComponents = _mm_setzero_ps(); }
    float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
};

struct hkRotation_s {
    hkVector4_s m_kColumn0;
    hkVector4_s m_kColumn1;
    hkVector4_s m_kColumn2;
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransform_s {
    hkRotation_s m_rotation;
    hkVector4_s m_vTranslation;
    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

struct hkBool_s {
    char m_cBooleanValue;
    hkBool_s(bool b) { m_cBooleanValue = (char)b; }
};


struct RagdollAtoms_s {
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    RagdollAtoms_s();
};

struct RefObjectBase_s {
    virtual void vfunc00();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    RefObjectBase_s() { m_sReferenceCount = 1; }
};

struct ConstraintDataBase_s : RefObjectBase_s {
    int m_ulUserData;
    ConstraintDataBase_s() { m_ulUserData = 0; }
    void setSolvingFlag(hkBool_s flag);
};

struct FUN_00cdf2f0 : ConstraintDataBase_s {
    int unk0C;
    RagdollAtoms_s m_kBridgeAtoms;
    hkTransform_s m_kBodyALocalFrame;
    hkTransform_s m_kBodyBLocalFrame;
    unsigned short unkA0;
    unsigned char unkA2;
    unsigned char unkA3;
    volatile unsigned short unkA4;
    unsigned short unkA6;
    int unkA8;
    int unkAC;
    hkRotation_s m_rotationB0;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    unsigned char unkF0;
    unsigned char unkF1;
    unsigned char unkF2;
    unsigned char unkF3;
    unsigned char unkF4;
    unsigned char unkF5;
    unsigned char unkF6;
    unsigned char unkF7;
    float unkF8;
    unsigned char unkFC;
    unsigned char unkFD;
    unsigned char unkFE;
    unsigned char unkFF;
    unsigned char unk100;
    unsigned char unk101;
    unsigned char unk102;
    unsigned char unk103;
    float unk104;
    float unk108;
    float unk10C;
    unsigned char unk110;
    unsigned char unk111;
    unsigned char unk112;
    unsigned char unk113;
    unsigned char unk114;
    unsigned char unk115;
    unsigned char unk116;
    unsigned char unk117;
    float unk118;
    float unk11C;
    float unk120;
    unsigned char unk124;
    unsigned char unk125;
    unsigned char unk126;
    unsigned char unk127;
    unsigned char unk128;
    unsigned char unk129;
    unsigned char unk12A;
    unsigned char unk12B;
    float unk12C;
    float unk130;
    float unk134;

    FUN_00cdf2f0();
};

__declspec(noinline) void ConstraintDataBase_s::setSolvingFlag(hkBool_s flag)
{
    static_cast<FUN_00cdf2f0*>(this)->unk116 = (unsigned char)((flag.m_cBooleanValue != 0) * 0x38);
}

// @fnv 0x00cdf2f0
FUN_00cdf2f0::FUN_00cdf2f0()
{
    m_kBodyALocalFrame.setIdentity();
    m_kBodyBLocalFrame.setIdentity();
    unkF3 = 0;
    unkF8 = 0.0f;
    unkF4 = 3;
    unkA2 = 0;
    unkA4 = 0x60;
    unkA6 = 0x64;
    m_rotationB0.setIdentity();
    unk104 = -0.5236f;
    unkE0 = 0;
    unk108 = 0.5236f;
    unkE4 = 0;
    unkE8 = 0;
    unkFF = 0;
    unk100 = 1;
    unk10C = 0.8f;
    unk113 = 0;
    unk114 = 0;
    unk118 = -100.0f;
    unk115 = 0;
    unk11C = 1.0f;
    unk120 = 0.8f;
    reinterpret_cast<::FUN_00cdea00_cls *>(this)->FUN_00cdea00((*(char *)&(const ::hkBool_s &)(true)));
    unk12C = -0.025f;
    unk127 = 0;
    unk128 = 1;
    unk130 = 0.025f;
    unk129 = 1;
    unk134 = 0.8f;
}

extern "C" void _ReadWriteBarrier();

struct CdfSubObject
{
    volatile unsigned char m_00;
};

class CdfObject
{
public:
    volatile unsigned short m_00; // +0x0
    volatile unsigned char unk02; // +0x2
    volatile unsigned char unk03; // +0x3
    volatile unsigned char unk04; // +0x4
    volatile unsigned char unk05; // +0x5
    volatile unsigned char unk06; // +0x6
    volatile unsigned char unk07; // +0x7
    volatile unsigned char unk08; // +0x8
    volatile unsigned char unk09; // +0x9
    volatile unsigned char unk0a; // +0xa
    volatile unsigned char unk0b; // +0xb
    volatile unsigned char unk0c; // +0xc
    volatile unsigned char unk0d; // +0xd
    volatile unsigned char unk0e; // +0xe
    volatile unsigned char unk0f; // +0xf
    volatile unsigned char unk10; // +0x10
    volatile unsigned char unk11; // +0x11
    volatile unsigned char unk12; // +0x12
    volatile unsigned char unk13; // +0x13
    volatile unsigned char unk14; // +0x14
    volatile unsigned char unk15; // +0x15
    volatile unsigned char unk16; // +0x16
    volatile unsigned char unk17; // +0x17
    volatile unsigned char unk18; // +0x18
    volatile unsigned char unk19; // +0x19
    volatile unsigned char unk1a; // +0x1a
    volatile unsigned char unk1b; // +0x1b
    volatile unsigned char unk1c; // +0x1c
    volatile unsigned char unk1d; // +0x1d
    volatile unsigned char unk1e; // +0x1e
    volatile unsigned char unk1f; // +0x1f
    volatile unsigned char unk20; // +0x20
    volatile unsigned char unk21; // +0x21
    volatile unsigned char unk22; // +0x22
    volatile unsigned char unk23; // +0x23
    volatile unsigned char unk24; // +0x24
    volatile unsigned char unk25; // +0x25
    volatile unsigned char unk26; // +0x26
    volatile unsigned char unk27; // +0x27
    volatile unsigned char unk28; // +0x28
    volatile unsigned char unk29; // +0x29
    volatile unsigned char unk2a; // +0x2a
    volatile unsigned char unk2b; // +0x2b
    volatile unsigned char unk2c; // +0x2c
    volatile unsigned char unk2d; // +0x2d
    volatile unsigned char unk2e; // +0x2e
    volatile unsigned char unk2f; // +0x2f
    volatile unsigned char unk30; // +0x30
    volatile unsigned char unk31; // +0x31
    volatile unsigned char unk32; // +0x32
    volatile unsigned char unk33; // +0x33
    volatile unsigned char unk34; // +0x34
    volatile unsigned char unk35; // +0x35
    volatile unsigned char unk36; // +0x36
    volatile unsigned char unk37; // +0x37
    volatile unsigned char unk38; // +0x38
    volatile unsigned char unk39; // +0x39
    volatile unsigned char unk3a; // +0x3a
    volatile unsigned char unk3b; // +0x3b
    volatile unsigned char unk3c; // +0x3c
    volatile unsigned char unk3d; // +0x3d
    volatile unsigned char unk3e; // +0x3e
    volatile unsigned char unk3f; // +0x3f
    volatile unsigned char unk40; // +0x40
    volatile unsigned char unk41; // +0x41
    volatile unsigned char unk42; // +0x42
    volatile unsigned char unk43; // +0x43
    volatile unsigned char unk44; // +0x44
    volatile unsigned char unk45; // +0x45
    volatile unsigned char unk46; // +0x46
    volatile unsigned char unk47; // +0x47
    volatile unsigned char unk48; // +0x48
    volatile unsigned char unk49; // +0x49
    volatile unsigned char unk4a; // +0x4a
    volatile unsigned char unk4b; // +0x4b
    volatile unsigned char unk4c; // +0x4c
    volatile unsigned char unk4d; // +0x4d
    volatile unsigned char unk4e; // +0x4e
    volatile unsigned char unk4f; // +0x4f
    volatile unsigned char unk50; // +0x50
    volatile unsigned char unk51; // +0x51
    volatile unsigned char unk52; // +0x52
    volatile unsigned char unk53; // +0x53
    volatile unsigned char unk54; // +0x54
    volatile unsigned char unk55; // +0x55
    volatile unsigned char unk56; // +0x56
    volatile unsigned char unk57; // +0x57
    volatile unsigned char unk58; // +0x58
    volatile unsigned char unk59; // +0x59
    volatile unsigned char unk5a; // +0x5a
    volatile unsigned char unk5b; // +0x5b
    volatile unsigned char unk5c; // +0x5c
    volatile unsigned char unk5d; // +0x5d
    volatile unsigned char unk5e; // +0x5e
    volatile unsigned char unk5f; // +0x5f
    volatile unsigned char unk60; // +0x60
    volatile unsigned char unk61; // +0x61
    volatile unsigned char unk62; // +0x62
    volatile unsigned char unk63; // +0x63
    volatile unsigned char unk64; // +0x64
    volatile unsigned char unk65; // +0x65
    volatile unsigned char unk66; // +0x66
    volatile unsigned char unk67; // +0x67
    volatile unsigned char unk68; // +0x68
    volatile unsigned char unk69; // +0x69
    volatile unsigned char unk6a; // +0x6a
    volatile unsigned char unk6b; // +0x6b
    volatile unsigned char unk6c; // +0x6c
    volatile unsigned char unk6d; // +0x6d
    volatile unsigned char unk6e; // +0x6e
    volatile unsigned char unk6f; // +0x6f
    volatile unsigned char unk70; // +0x70
    volatile unsigned char unk71; // +0x71
    volatile unsigned char unk72; // +0x72
    volatile unsigned char unk73; // +0x73
    volatile unsigned char unk74; // +0x74
    volatile unsigned char unk75; // +0x75
    volatile unsigned char unk76; // +0x76
    volatile unsigned char unk77; // +0x77
    volatile unsigned char unk78; // +0x78
    volatile unsigned char unk79; // +0x79
    volatile unsigned char unk7a; // +0x7a
    volatile unsigned char unk7b; // +0x7b
    volatile unsigned char unk7c; // +0x7c
    volatile unsigned char unk7d; // +0x7d
    volatile unsigned char unk7e; // +0x7e
    volatile unsigned char unk7f; // +0x7f
    volatile unsigned char unk80; // +0x80
    volatile unsigned char unk81; // +0x81
    volatile unsigned char unk82; // +0x82
    volatile unsigned char unk83; // +0x83
    volatile unsigned char unk84; // +0x84
    volatile unsigned char unk85; // +0x85
    volatile unsigned char unk86; // +0x86
    volatile unsigned char unk87; // +0x87
    volatile unsigned char unk88; // +0x88
    volatile unsigned char unk89; // +0x89
    volatile unsigned char unk8a; // +0x8a
    volatile unsigned char unk8b; // +0x8b
    volatile unsigned char unk8c; // +0x8c
    volatile unsigned char unk8d; // +0x8d
    volatile unsigned char unk8e; // +0x8e
    volatile unsigned char unk8f; // +0x8f
    volatile unsigned short m_90; // +0x90
    volatile unsigned char m_92; // +0x92
    volatile unsigned char unk93; // +0x93
    unsigned short m_94; // +0x94
    unsigned short m_96; // +0x96
    volatile unsigned char unk98; // +0x98
    volatile unsigned char unk99; // +0x99
    volatile unsigned char unk9a; // +0x9a
    volatile unsigned char unk9b; // +0x9b
    volatile unsigned char unk9c; // +0x9c
    volatile unsigned char unk9d; // +0x9d
    volatile unsigned char unk9e; // +0x9e
    volatile unsigned char unk9f; // +0x9f
    volatile unsigned char unka0; // +0xa0
    volatile unsigned char unka1; // +0xa1
    volatile unsigned char unka2; // +0xa2
    volatile unsigned char unka3; // +0xa3
    volatile unsigned char unka4; // +0xa4
    volatile unsigned char unka5; // +0xa5
    volatile unsigned char unka6; // +0xa6
    volatile unsigned char unka7; // +0xa7
    volatile unsigned char unka8; // +0xa8
    volatile unsigned char unka9; // +0xa9
    volatile unsigned char unkaa; // +0xaa
    volatile unsigned char unkab; // +0xab
    volatile unsigned char unkac; // +0xac
    volatile unsigned char unkad; // +0xad
    volatile unsigned char unkae; // +0xae
    volatile unsigned char unkaf; // +0xaf
    volatile unsigned char unkb0; // +0xb0
    volatile unsigned char unkb1; // +0xb1
    volatile unsigned char unkb2; // +0xb2
    volatile unsigned char unkb3; // +0xb3
    volatile unsigned char unkb4; // +0xb4
    volatile unsigned char unkb5; // +0xb5
    volatile unsigned char unkb6; // +0xb6
    volatile unsigned char unkb7; // +0xb7
    volatile unsigned char unkb8; // +0xb8
    volatile unsigned char unkb9; // +0xb9
    volatile unsigned char unkba; // +0xba
    volatile unsigned char unkbb; // +0xbb
    volatile unsigned char unkbc; // +0xbc
    volatile unsigned char unkbd; // +0xbd
    volatile unsigned char unkbe; // +0xbe
    volatile unsigned char unkbf; // +0xbf
    volatile unsigned char unkc0; // +0xc0
    volatile unsigned char unkc1; // +0xc1
    volatile unsigned char unkc2; // +0xc2
    volatile unsigned char unkc3; // +0xc3
    volatile unsigned char unkc4; // +0xc4
    volatile unsigned char unkc5; // +0xc5
    volatile unsigned char unkc6; // +0xc6
    volatile unsigned char unkc7; // +0xc7
    volatile unsigned char unkc8; // +0xc8
    volatile unsigned char unkc9; // +0xc9
    volatile unsigned char unkca; // +0xca
    volatile unsigned char unkcb; // +0xcb
    volatile unsigned char unkcc; // +0xcc
    volatile unsigned char unkcd; // +0xcd
    volatile unsigned char unkce; // +0xce
    volatile unsigned char unkcf; // +0xcf
    volatile unsigned char unkd0; // +0xd0
    volatile unsigned char unkd1; // +0xd1
    volatile unsigned char unkd2; // +0xd2
    volatile unsigned char unkd3; // +0xd3
    volatile unsigned char unkd4; // +0xd4
    volatile unsigned char unkd5; // +0xd5
    volatile unsigned char unkd6; // +0xd6
    volatile unsigned char unkd7; // +0xd7
    volatile unsigned char unkd8; // +0xd8
    volatile unsigned char unkd9; // +0xd9
    volatile unsigned char unkda; // +0xda
    volatile unsigned char unkdb; // +0xdb
    volatile unsigned char unkdc; // +0xdc
    volatile unsigned char unkdd; // +0xdd
    volatile unsigned char unkde; // +0xde
    volatile unsigned char unkdf; // +0xdf
    volatile unsigned short m_e0; // +0xe0
    volatile unsigned char m_e2; // +0xe2
    volatile unsigned char unke3; // +0xe3
    volatile unsigned char m_e4; // +0xe4
    volatile unsigned char unke5; // +0xe5
    volatile unsigned char unke6; // +0xe6
    volatile unsigned char unke7; // +0xe7
    volatile unsigned char unke8; // +0xe8
    volatile unsigned char unke9; // +0xe9
    volatile unsigned char unkea; // +0xea
    volatile unsigned char unkeb; // +0xeb
    volatile unsigned short m_ec; // +0xec
    volatile unsigned char m_ee; // +0xee
    volatile unsigned char unkef; // +0xef
    volatile unsigned char unkf0; // +0xf0
    volatile unsigned char unkf1; // +0xf1
    volatile unsigned char unkf2; // +0xf2
    volatile unsigned char unkf3; // +0xf3
    volatile unsigned char unkf4; // +0xf4
    volatile unsigned char unkf5; // +0xf5
    volatile unsigned char unkf6; // +0xf6
    volatile unsigned char unkf7; // +0xf7
    volatile unsigned char unkf8; // +0xf8
    volatile unsigned char unkf9; // +0xf9
    volatile unsigned char unkfa; // +0xfa
    volatile unsigned char unkfb; // +0xfb
    volatile unsigned char unkfc; // +0xfc
    volatile unsigned char unkfd; // +0xfd
    volatile unsigned char unkfe; // +0xfe
    volatile unsigned char unkff; // +0xff
    volatile unsigned short m_100; // +0x100
    volatile unsigned char m_102; // +0x102
    volatile unsigned char unk103; // +0x103
    volatile unsigned char unk104; // +0x104
    volatile unsigned char unk105; // +0x105
    volatile unsigned char m_106; // +0x106
    volatile unsigned char unk107; // +0x107
    volatile unsigned char unk108; // +0x108
    volatile unsigned char unk109; // +0x109
    volatile unsigned char unk10a; // +0x10a
    volatile unsigned char unk10b; // +0x10b
    volatile unsigned char unk10c; // +0x10c
    volatile unsigned char unk10d; // +0x10d
    volatile unsigned char unk10e; // +0x10e
    volatile unsigned char unk10f; // +0x10f
    volatile unsigned char unk110; // +0x110
    volatile unsigned char unk111; // +0x111
    volatile unsigned char unk112; // +0x112
    volatile unsigned char unk113; // +0x113
    unsigned short m_114; // +0x114
    unsigned char m_116; // +0x116
    volatile unsigned char unk117; // +0x117
    volatile unsigned char unk118; // +0x118
    volatile unsigned char unk119; // +0x119
    volatile unsigned char m_11a; // +0x11a
    volatile unsigned char unk11b; // +0x11b
    volatile unsigned char unk11c; // +0x11c
    volatile unsigned char unk11d; // +0x11d
    volatile unsigned char unk11e; // +0x11e
    volatile unsigned char unk11f; // +0x11f
    volatile unsigned char unk120; // +0x120
    volatile unsigned char unk121; // +0x121
    volatile unsigned char unk122; // +0x122
    volatile unsigned char unk123; // +0x123
    volatile unsigned char unk124; // +0x124
    volatile unsigned char unk125; // +0x125
    volatile unsigned char unk126; // +0x126
    volatile unsigned char unk127; // +0x127
    unsigned short m_128; // +0x128
    volatile unsigned char m_12a; // +0x12a
    CdfSubObject m_12b; // +0x12b
    float m_12c; // +0x12c

    CdfObject* FUN_00cdf460();
};

// Sets fixed initial values in several fields, initializes m_12b via FUN_00ca9360 with 1.0f, and returns this.
// @fnv 0x00cdf460
CdfObject* CdfObject::FUN_00cdf460()
{
    float one = 1.0f;
    m_00 = 2;
    m_90 = 0x13;
    m_92 = 1;
    m_94 = 0;
    m_96 = 0;
    m_e2 = 1;
    m_e4 = 1;
    m_e0 = 0x11;
    m_ee = 1;
    m_ec = 0xf;
    m_106 = 0;
    m_102 = 1;
    m_100 = 0x10;
    m_11a = 0;
    m_114 = 0x10;
    m_116 = 1;
    m_12a = 0;
    m_128 = 5;
    reinterpret_cast<::FUN_00ca9360_cls *>(&(m_12b))->FUN_00ca9360(&one);
    m_12c = ::DAT_0104da48;
    return this;
}

struct NamedEntryC136 {
    const char* m_name;
    int m_uiFilterValue;
};

struct ClassInfoC136 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NamedEntryC136* m_entries;
    int m_iNumberOfEntries;
};

struct NameSetC136 {
    int unk00;
    int unk04;
    unsigned int m_numNames;
    const char** m_ppNames;
    bool ContainsAllNames(const ClassInfoC136* pkInfo);
};

// Returns true if every name in pkInfo's entries is present in this set's m_ppNames, using strcmp for each comparison.
// @fnv 0x00cc1360
bool NameSetC136::ContainsAllNames(const ClassInfoC136* pkInfo)
{
    bool bAllFound = true;
    int iEntryIndex = pkInfo->m_iNumberOfEntries;
    for (int i = 0; i < iEntryIndex && bAllFound; i++) {
        const char* pcName = (const char*)((unsigned int)pkInfo->m_entries[i].m_name & ~1u);
        bool bFound = false;
        for (unsigned int j = 0; j < m_numNames && !bFound; j++) {
            if (strcmp(pcName, m_ppNames[j]) == 0)
                bFound = true;
        }
        if (!bFound)
            bAllFound = false;
    }
    return bAllFound;
}

struct __declspec(align(16)) Q1420V4
{
    float x;
    float y;
    float z;
    float w;
    Q1420V4& operator=(const Q1420V4& o)
    {
        *(__m128*)this = *(const __m128*)&o;
        return *this;
    }
};

struct Q1420Xf
{
    Q1420V4 r0;
    Q1420V4 r1;
    Q1420V4 r2;
};

struct Q1420Entry
{
    int unk00;
    Q1420Xf* unk04;
};

struct Q1420Item
{
    const char* unk00;
    int unk04;
};

struct Q1420Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Q1420Item* unk18;
    int unk1C;
};

struct Q1420Helper
{
    int unk00;
    int unk04;
    unsigned int unk08;
    const char** unk0C;
    int unk10;
    Q1420Entry** unk14;

    void FUN_00cc1420(Q1420Xf* dest, Q1420Source* source, int index);
};

// For each source item whose name matches an entry in this->unk0C, copies a Q1420Xf from this->unk14[index]->unk04 into dest[i].
// @fnv 0x00cc1420
void Q1420Helper::FUN_00cc1420(Q1420Xf* dest, Q1420Source* source, int index)
{
    int count = source->unk1C;
    for (int i = 0; i < count; i++)
    {
        const char* name = (const char*)((unsigned int)source->unk18[i].unk00 & 0xFFFFFFFEu);
        bool found = false;
        unsigned int j;
        for (j = 0; j < unk08; j++)
        {
            if (found)
                break;
            if (strcmp(name, unk0C[j]) == 0)
                found = true;
        }
        if (found)
            dest[i] = unk14[index]->unk04[j - 1];
    }
}

extern char DAT_010c94a4, DAT_010c9498, str_010c9488;
struct FUN_00a7b2e0 {
 unsigned int unk04, unk08;

 FUN_00a7b2e0();
 virtual ~FUN_00a7b2e0();
};
struct ExtraMember {
 void* vptr; unsigned int unk10,unk14,unk18,unk1c,count;
 ExtraMember() { unk14=0; count=1; unk18=0; unk1c=0; unk10=0; vptr=&DAT_010c9498; }
 ~ExtraMember();
};
struct NameRef {
 char* name;
 NameRef(const char* n) { name=::NiGlobalStringTable::AddString(n); }
 ~NameRef() throw() { if ((unsigned int)name!=(*reinterpret_cast<unsigned int *>(&::DAT_0109b220))) InterlockedDecrement((long volatile*)(name-8)); }
};
struct FUN_00cc1d80 : FUN_00a7b2e0 {
 ExtraMember member;

 FUN_00cc1d80();
 ~FUN_00cc1d80();
};
// Constructs the object and calls AssignFixedString with a name reference built from the string at str_010c9488.
// @fnv 0x00cc1d80
FUN_00cc1d80::FUN_00cc1d80() {

 NameRef name(&str_010c9488);
 ::AssignFixedString((char *)this, 0, (char **)&name);
}

class CC4180Base {
public:
    virtual ~CC4180Base();

};

class FUN_00cc4180 : public CC4180Base {
public:
    virtual ~FUN_00cc4180();

    static unsigned int ms_uiInstances;
};
// @fnv 0x00cc4200
void* FUN_00cc4180_Class::FUN_00cc4200(int flag)
{
    reinterpret_cast<::FUN_00cc4180 *>(this)->FUN_00cc4180::~FUN_00cc4180();
    if (flag & 1)
        ::FUN_00aa1460(this, 16);
    return this;
}

// Calls Shutdown and decrements the static instance counter ms_uiInstances.
// @fnv 0x00cc4180
FUN_00cc4180::~FUN_00cc4180()
{
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --ms_uiInstances;
}

class CC47F0Base {
public:
    virtual ~CC47F0Base();
};

extern int g_iCC47F0Count;

class FUN_00cc47f0 : public CC47F0Base {
public:
    void Release();

    virtual ~FUN_00cc47f0();
};
// Calls FUN_00cc47f0, then deletes this with size 0x10 when bit 0 of a is set, and returns this.
// @fnv 0x00cc48e0
FUN_00cc47f0_t* FUN_00cc47f0_t::FUN_00cc48e0(int aiFlags)
{
    reinterpret_cast<::FUN_00cc47f0 *>(this)->FUN_00cc47f0::~FUN_00cc47f0();
    if (aiFlags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}

// Destructor that calls Release and decrements the global g_iCC47F0Count.
// @fnv 0x00cc47f0
FUN_00cc47f0::~FUN_00cc47f0() {
    reinterpret_cast<::ProjectileListener *>(this)->FUN_00c876a0();
    --g_iCC47F0Count;
}

extern "C" void __cdecl operator_delete_sized(void* pvMem, unsigned int uiSize);

class FUN_00cc7e50 {
public:
    FUN_00cc7e50();
    virtual ~FUN_00cc7e50();


    int unk04;
    int unk08;
    int unk0C;
};

// @fnv 0x00cc7e50
FUN_00cc7e50::FUN_00cc7e50()
{
}

struct FUN_00cc9dd0 {
    FUN_00cc9dd0();
    virtual ~FUN_00cc9dd0();


    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

// @fnv 0x00cc9dd0
FUN_00cc9dd0::FUN_00cc9dd0()
{
}



struct FUN_00ccbb50 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ~FUN_00ccbb50();
};

class FUN_00ccc720 : public NiRefObject {
public:
    unsigned int unk08;
    FUN_00ccbb50* entries;
    virtual ~FUN_00ccc720();
};
// Calls FUN_00ccc720, then frees this with operator delete when arg has bit 0 set, and returns this.
// @fnv 0x00cccfb0
void* FUN_00ccc720_holder::DestroyHolder(int aiFlags)
{
    reinterpret_cast<::FUN_00ccc720 *>(this)->FUN_00ccc720::~FUN_00ccc720();
    if (aiFlags & 1)
        operator delete(this, 0x10);
    return this;
}

// Destructor that deletes the entries array inside an AutoMemContext(16) scope.
// @fnv 0x00ccc720
FUN_00ccc720::~FUN_00ccc720() {
    AutoMemContext context(16);
    delete[] entries;
}

namespace fnv_00cd3ad0 {
struct CD3AD0Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct CD3AD0MemoryRouter {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    CD3AD0Allocator* m_pStreamAllocator;

    CD3AD0Allocator& heap() { return *m_pStreamAllocator; }
};


class FUN_00cd3ad0 {
// @fnv 0x00cd3ad0
public:
    FUN_00cd3ad0() {}
    virtual ~FUN_00cd3ad0();

    static void* operator new(std::size_t, void* p) { return p; }
    static void operator delete(void*, void*) {}
    static void operator delete(void* p, std::size_t nbytes)
    {
        if (p)
            (*static_cast<CD3AD0MemoryRouter*>(::FUN_00c85750())).heap().ReleaseBlock(p, nbytes);
    }

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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
};

void* CD3AD0Construct(void* pvMem)
{
    return new (pvMem) FUN_00cd3ad0;
}
}  // namespace fnv_00cd3ad0

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void* DAT_00fdf044;

struct FUN_00cdfe00_Object {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual int* vf40();
};


typedef void* (*TlsGetValueFunc)(int);

// If vf40 returns non-null, calls vf18 on param2, logs a TtClrSurfVel TLS entry, calls FUN_00d27690(result, param2, 0x1a), then logs an Et entry.
// @fnv 0x00cdfe00
void FUN_00cdfe00(FUN_00cdfe00_Object* param1, FUN_00cdfe00_Object* param2) {
    int* result = param1->vf40();
    if (result != 0) {
        param2->vf18();

        TlsGetValueFunc getTls = reinterpret_cast<TlsGetValueFunc>(DAT_00fdf044);
        char* pTlsBuffer = reinterpret_cast<char*>(getTls(DAT_0126835c));

        char* entry = *reinterpret_cast<char**>(pTlsBuffer + 4);
        if (entry < *reinterpret_cast<char**>(pTlsBuffer + 0xC)) {
            *reinterpret_cast<const char**>(entry) = "TtClrSurfVel";
            _ReadWriteBarrier();
            volatile unsigned int timestamp = __rdtsc();
            *reinterpret_cast<unsigned int*>(entry + 4) = timestamp;
            *reinterpret_cast<char**>(pTlsBuffer + 4) = entry + 12;
        }

        ::FUN_00d27690((::D27690_Instance *)(result), (::D27690_Owner *)(param2), 0x1a);

        pTlsBuffer = reinterpret_cast<char*>(getTls(DAT_0126835c));
        entry = *reinterpret_cast<char**>(pTlsBuffer + 4);
        if (entry < *reinterpret_cast<char**>(pTlsBuffer + 0xC)) {
            *reinterpret_cast<const char**>(entry) = "Et";
            _ReadWriteBarrier();
            volatile unsigned int timestamp = __rdtsc();
            *reinterpret_cast<unsigned int*>(entry + 4) = timestamp;
            *reinterpret_cast<char**>(pTlsBuffer + 4) = entry + 12;
        }
    }
}

struct LocalBinaryStream {
    void* vtable;
    unsigned int position;
    unsigned int (__cdecl *read)(LocalBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* p, unsigned int bytes, unsigned int* sizes, unsigned int count) {
        unsigned int result = read(this,p,bytes,sizes,count);
        position += result;
        return result;
    }
    void Read(void* p, unsigned int bytes) {
        unsigned int size = bytes;
        BinaryRead(p,bytes,&size,1);
    }
};

struct LocalStream {
    void* vtable;
    unsigned int version;
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
    LocalBinaryStream* input;
};

struct LocalReference {  };

struct RagdollConstraintData {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    __m128 axisA;
    __m128 planeA;
    __m128 binormalA;
    __m128 pivotA;
    __m128 axisB;
    __m128 planeB;
    __m128 binormalB;
    __m128 pivotB;
    unsigned short atomType;
    unsigned char enabled;
    unsigned char unk0a3;
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
    float maxFrictionTorque;
    unsigned int unk0fc;
    unsigned int unk100;
    float twistMin;
    float twistMax;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    float coneMax;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    float planeMin;
    float planeMax;
};

struct NiStream;
struct FUN_00d53200_class {
    void* vtable;
    RagdollConstraintData* data;
    void FUN_00cc6b80(LocalStream&);
public:
    void FUN_00c8a230(::NiStream &);
public:
    void FUN_00d53200(::NiStream &);
};
// LoadBinary
// Loads the base object, then reads the constraint's pivot A, pivot B and tau from the stream.
// @fnv 0x00cc5d40
void CC5D40BallJoint::FUN_00cc5d40(CC5D40Stream& kStream)
{
    reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00c8a230((::NiStream &)(kStream));
    CC5D40Constraint* pkConstraint = m_pkConstraint;
    CC5D40LoadBinary(kStream, pkConstraint->m_kPivotA);
    CC5D40LoadBinary(kStream, pkConstraint->m_kPivotB);
    CC5D40LoadBinary(kStream, pkConstraint->m_fTau);
}
// @fnv 0x00cc7a40
void FUN_00cc7a40_class::FUN_00cc7a40(NiStreamSI& kStream)
{
    reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00c8a230((::NiStream &)(kStream));
    ConstraintDataSI* pData = m_pData;
    kStream.m_pUnderlyingStream->Read(&pData->m_kBodyALocalFrame, 0x40);
    kStream.m_pUnderlyingStream->Read(&pData->m_kBodyBLocalFrame, 0x40);
    NiStreamLoadBinarySI(*kStream.m_pUnderlyingStream, pData->m_fC8);
    NiStreamLoadBinarySI(*kStream.m_pUnderlyingStream, pData->m_fCC);
    NiStreamLoadBinarySI(*kStream.m_pUnderlyingStream, pData->m_fB4);
    if (kStream.m_bLittleEndian != 1) {
        SwapTransformSI(&pData->m_kBodyALocalFrame);
        SwapTransformSI(&pData->m_kBodyBLocalFrame);
    }
    if (kStream.m_uiNifVersion > 0x1d) {
        hkRefObjSI* pMotor = ((::hkRefObjSI *)(::FUN_00c8a330((::Stream674 *)this)));
        reinterpret_cast<::fnv_00d4f850::FUN_00d4f850_class *>((pData))->SetReferencedObject((::hkReferencedObject *)(pMotor));
        if (pMotor) {
            NiStreamLoadBinarySI(*kStream.m_pUnderlyingStream, pData->m_bMotorEnabled);
            reinterpret_cast<::hkReferencedObjectC905 *>((pMotor))->FUN_00c905b0();
        }
    }
}
// Loads the base data, then reads the shape data's m_kMin and m_kMax vectors from the stream.
// @fnv 0x00cc9b80
void FUN_00cc9b80_cls::FUN_00cc9b80(BCC9B80Stream& kStream)
{
    reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00c8a230((::NiStream &)(kStream));

    BCC9B80ShapeData* pkData = m_pUserData;
    BCC9B80LoadBinary(kStream, pkData->m_kMin);
    BCC9B80LoadBinary(kStream, pkData->m_kMax);
}
// Calls FUN_00c8a230, then reads several blocks of ConstraintData fields from the stream's input.
// @fnv 0x00cc55a0
void ConstraintLoader::FUN_00cc55a0(LoadStream* stream) {
 reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00c8a230((*(::NiStream *)(stream)));
 ConstraintData* values=data;
 stream->input->Read(&values->unk020,64);
 stream->input->Read(&values->unk060,64);
 stream->input->Read(&values->unk0d0,48);
 stream->input->Read(&values->unk100,48);
 stream->input->Read(&values->unk140,16);
 stream->input->Read(&values->unk150,16);
 stream->input->Read(&values->unk0a4,4);
 stream->input->Read(&values->unk0a8,4);
 stream->input->Read(&values->unk0b0,4);
 stream->input->Read(&values->unk0b4,4);
}
// Loads the base constraint data, reads two rotations (byte-swapping them if the stream is not little-endian) and five floats into the constraint data.
// @fnv 0x00cc61f0
void FUN_00cc61f0_class::FUN_00cc61f0(CC61F0Stream& kStream)
{
    reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00c8a230((::NiStream &)(kStream));
    CC61F0ConstraintData* pkData = m_pUserData;
    kStream.m_pUnderlyingStream->Read(&pkData->m_kRotA, sizeof(CC61F0Rotation));
    kStream.m_pUnderlyingStream->Read(&pkData->m_kRotB, sizeof(CC61F0Rotation));
    if (kStream.m_bLittleEndian != 1) {
        ::SwapEndianBlocks((unsigned int *)(::CC61F0Rotation *)(&pkData->m_kRotA));
        ::SwapEndianBlocks((unsigned int *)(::CC61F0Rotation *)(&pkData->m_kRotB));
    }
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_fA0);
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_fB0);
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_fB4);
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_f88);
    CC61F0LoadBinary(*kStream.m_pUnderlyingStream, pkData->m_f8C);
}
// @fnv 0x00cc8950
void BCC8950Constraint::FUN_00cc8950(BCC8950Stream& kStream)
{
    reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00c8a230((::NiStream &)(kStream));
    BCC8950ConstraintData* pkData = m_pUserData;
    BCC8950LoadBinary(kStream, pkData->m_kTransformA);
    BCC8950LoadBinary(kStream, pkData->m_kTransformB);
    BCC8950LoadBinary(kStream, pkData->m_fMinAngle);
    BCC8950LoadBinary(kStream, pkData->m_fMaxAngle);
}


extern const float DAT_01011d78;
extern const float DAT_01017718;
__forceinline void Normalize(__m128& v) {
    __m128 vector = v;
    __m128 squared = _mm_mul_ps(vector,vector);
    __m128 sum = _mm_shuffle_ps(squared,squared,0x55);
    sum = _mm_add_ss(sum,squared);
    squared = _mm_shuffle_ps(squared,squared,0xaa);
    sum = _mm_add_ss(squared,sum);
    __m128 reciprocal = _mm_rsqrt_ss(sum);
    __m128 zero = _mm_set_ss(0.0f);
    __m128 three = _mm_set_ss(3.0f);
    __m128 half = _mm_set_ss(0.5f);
    __m128 correction = _mm_mul_ss(sum,reciprocal);
    correction = _mm_mul_ss(correction,reciprocal);
    correction = _mm_sub_ss(three,correction);
    __m128 scale = _mm_mul_ss(half,reciprocal);
    scale = _mm_mul_ss(scale,correction);
    sum = _mm_cmpeq_ss(sum,zero);
    scale = _mm_andnot_ps(sum,scale);
    scale = _mm_shuffle_ps(scale,scale,0);
    v = _mm_mul_ps(scale,vector);
}

// Reads constraint axes and limits, defaults zero friction torque to 100, normalizes four vectors, and for stream version above 29 may read an enabled byte.
// @fnv 0x00cc6b80
void FUN_00d53200_class::FUN_00cc6b80(LocalStream& stream)
{
    (void)stream;
    reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00c8a230((::NiStream &)(stream));
    RagdollConstraintData* constraint = data;
    stream.input->Read(&constraint->axisA, 64);
    stream.input->Read(&constraint->axisB, 64);
    stream.input->Read(&constraint->coneMax, 4);
    stream.input->Read(&constraint->planeMin, 4);
    stream.input->Read(&constraint->planeMax, 4);
    stream.input->Read(&constraint->twistMin, 4);
    stream.input->Read(&constraint->twistMax, 4);
    stream.input->Read(&constraint->maxFrictionTorque, 4);
    if (constraint->maxFrictionTorque == 0.0f)
        constraint->maxFrictionTorque = 100.0f;
    Normalize(constraint->planeA);
    Normalize(constraint->axisA);
    Normalize(constraint->planeB);
    Normalize(constraint->axisB);
    if (stream.version > 29) {
        LocalReference* object = ((::LocalReference *)(::FUN_00c8a330((::Stream674 *)this)));
        reinterpret_cast<::hkMalleableConstraintData *>(constraint)->FUN_00cdea70((::hkMalleableContactNormal *)object);
        reinterpret_cast<::hkMalleableConstraintData *>(constraint)->FUN_00cdeab0((::hkMalleableContactNormal *)object);
        reinterpret_cast<::hkMalleableConstraintData *>(constraint)->FUN_00cdea90((::hkMalleableContactNormal *)object);
        if (object) {
            stream.input->Read(&constraint->enabled,1);
            reinterpret_cast<::hkReferencedObjectC905 *>((object))->FUN_00c905b0();
        }
    }
}

namespace fnv_00cc8e60 {
struct ReadIO {
    int unk00;
    unsigned int m_04;
    unsigned int (__cdecl *m_08)(ReadIO*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* p) { unsigned int size = 4; unsigned int n = m_08(this, p, 4, &size, 1); m_04 += n; return n; }
};

struct ReadData {
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

    void Push(void* first, void* second);
};

struct ReadContext {
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
    ReadIO* io;
};




struct ReadVec { float x,y,z,w; };

struct FUN_00d53200_class {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();

    ReadData* m_04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ReadVec* m_20;
    int m_24;

    void FUN_00cc8e60(ReadContext* owner);
};

// Calls vf10 and FUN_00cf0f40, passes m_20 entries in pairs to Push, reads four fields via io, then calls FUN_00d53200.
// @fnv 0x00cc8e60
void FUN_00d53200_class::FUN_00cc8e60(ReadContext* owner)
{
    vf10();

    ::FUN_00cf0f40((::S00cf0f40_Owner *)(owner), (::S00cf0f40_Arr *)(void *)(&m_20));

    ReadData* pReadData = m_04;
    int index = 0;
    while (index < m_24) {
        pReadData->Push(&m_20[index], &m_20[index + 1]);
        index += 2;
    }

    owner->io->Read(&pReadData->unk28);
    owner->io->Read(&pReadData->unk24);
    owner->io->Read(&pReadData->unk2C);
    owner->io->Read(&pReadData->unk30);
    reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00d53200(*reinterpret_cast<NiStream*>(owner));
}
}  // namespace fnv_00cc8e60

struct CopyAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& bytes);
    virtual void ReleaseBlock(void* data, int bytes);
};

struct CopyArray {
    __m128* data;
    int size;
    int capacity;
};

struct CopyOutput {
    int unk00;
    int unk04;
    CopyArray vertices;
    CopyArray planes;
};

struct CopyShape {
};

struct CopyOwner {
    int unk00;
    int unk04;
    CopyShape* shape;
    void FUN_00cce010(CopyOutput* out);
};
// Sets *pbCreated if m_pkChild was null and then creates it, calling FUN_00cce010 with it when m_pParentNode is set; returns m_pkChild.
// @fnv 0x00cce1c0
CCE1C0Child* CCE1C0Owner::GetOrCreateChild(bool* pbCreated)
{
    CCE1C0AllocTagScope scope(0x10);

    *pbCreated = (m_pkChild == 0);
    if (*pbCreated) {
        m_pkChild = new CCE1C0Child();
        if (m_pParentNode) reinterpret_cast<::CopyOwner *>(this)->FUN_00cce010((::CopyOutput *)(m_pkChild));
    }
    return m_pkChild;
}

// Fills the output's vertices through the shape, then copies the shape's array into the output's planes buffer, growing it if capacity is too small.
// @fnv 0x00cce010
void CopyOwner::FUN_00cce010(CopyOutput* apOutput)
{
    ::FUN_00c9fb70((::MyObj *)this, 0, (::OutS *)(apOutput));
    CopyShape* p = this ? shape : 0;
    if (p) {
        reinterpret_cast<::ConvexVertsQ_d59200 *>((p))->FUN_00d59200((*(::VertArray96Q *)(&apOutput->vertices)));
        const CopyArray& src = (*(const ::CopyArray *)(reinterpret_cast<::FnvCpu_FUN_00d58d50_CpuObject *>((p))->FUN_00d58d50()));
        CopyAllocator* alloc = reinterpret_cast<CopyAllocator*>(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->unk10);
        int cap = apOutput->planes.capacity & 0x3fffffff;
        if (cap < src.size) {
            if ((apOutput->planes.capacity & 0x80000000) == 0)
                alloc->ReleaseBlock(apOutput->planes.data, cap * 16);
            int bytes = src.size * 16;
            apOutput->planes.data = static_cast<__m128*>(alloc->AllocateBufferWithSize(bytes));
            apOutput->planes.capacity = bytes / 16;
        }
        int count = src.size;
        apOutput->planes.size = count;
        __m128* dst = apOutput->planes.data;
        const __m128* input = src.data;
        for (int i = 0; i < count; ++i)
            dst[i] = input[i];
    }
}


struct ContactSource {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28;
    unsigned int m_uiCollisionFilterData;
};

struct ContactHit;

struct ContactListener {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void OnEnter(ContactHit* hit);
    virtual void OnStay(ContactHit* hit);
};

struct ContactHandler {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    ContactListener* m_kListener;
};

struct ContactUser {
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    ContactHandler* m_handler;
};

struct ContactOwner {
    int unk00; int unk04;
    ContactUser* m_user;
    void* getUserData() const { return m_user; }
};

struct ContactCollidable;
__forceinline void getUserOut(const ContactCollidable* c, ContactUser*& out);
struct ContactCollidable {
    int unk00; int unk04; int unk08; int unk0C;
    signed char m_iOwnerOffset;
    void* getOwner() const { return (char*)this + m_iOwnerOffset; }
};

struct ContactHit {
    int m_00; int m_04; int m_08; int m_0c;
    int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c;
    int m_30; int m_34; int m_38; int m_3c;
    int m_40; int m_44;
    ContactCollidable* m_kCollidable;
    int m_4c;
    int m_50; int m_54; int m_58; int m_5c;
    int m_60; int m_64; int m_68; int m_6c;
};

struct CopyBlock8 {
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

template <int N> struct MemCpyAligned {
    static __forceinline void copy(void* dst, const void* src)
    {
        const CopyBlock8* s = (const CopyBlock8*)src;
        CopyBlock8* d = (CopyBlock8*)dst;
        for (int i=0; i<N/8; i++) d[i]=s[i];
        if (N==4) *(unsigned int*)dst=*(const unsigned int*)src;
    }
};

__forceinline void getUserOut(const ContactCollidable* c, ContactUser*& out)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    out = owner ? owner->m_user : 0;
}

__forceinline void* getUserData(const ContactCollidable* c)
{
    const ContactOwner* owner = (const ContactOwner*)c->getOwner();
    return owner ? owner->getUserData() : 0;
}

__forceinline ContactUser* getUser(const ContactCollidable* c)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    return owner ? owner->m_user : 0;
}

__forceinline ContactUser* getUser2(const ContactCollidable* c)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    if (!owner) {
        return 0;
    }
    return owner->m_user;
}

template <class T> struct ContactArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index) {
            MemCpyAligned<sizeof(T)>::copy(&m_data[index], &m_data[m_iElementCount]);
        }
    }
};

struct TriggerCollector : FUN_00cd3410 {
    ContactArray<ContactSource*>& sources() { return *(ContactArray<ContactSource*>*)&m_a1; }
    ContactArray<int>& states() { return *(ContactArray<int>*)&m_a2; }
    ContactArray<ContactHit>& hits() { return *(ContactArray<ContactHit>*)&m_a3; }
    void ProcessContactEvents();
};

// Resets the hit count, dispatches OnEnter/OnStay for layer 14/16 contacts, then removes entries whose state is 1 and sets the others to 1.
// @fnv 0x00cd32b0
void TriggerCollector::ProcessContactEvents()
{
    double val = ::DAT_0104da48;
    int& cnt=m_iHitsSize;
    cnt = 0;
    m_fEarlyOutDistance = (float)val;
    int i;
    for (i = 0; i < states().GetLogicalSize(); i++) {
        unsigned int layer = sources()[i]->m_uiCollisionFilterData & 0x7f;
        ContactOwner* owner = (ContactOwner*)hits()[i].m_kCollidable->getOwner();
        void* ud = owner ? owner->getUserData() : 0;
        ContactUser* user = (ContactUser*)ud;
        if (user) {
            ContactHandler* handler = user->m_handler;
            if (handler) {
                switch (layer) {
                case 14:
                case 16: {
                    ContactListener* listener = handler->m_kListener;
                    if (listener) {
                        int state = states()[i];
                        if (state == 0) {
                            listener->OnEnter(&hits()[i]);
                        } else if (state == 1) {
                            listener->OnStay(&hits()[i]);
                        }
                    }
                    break;
                }
                }
            }
        }
    }
    for (i = states().GetLogicalSize() - 1; i >= 0; i--) {
        if (states()[i] == 1) {
            reinterpret_cast<::hkReferencedObjectC905 *>((sources()[i]))->FUN_00c905b0();
            sources().removeAt(i);
            hits().removeAt(i);
            states().removeAt(i);
        } else {
            states()[i] = 1;
        }
    }
}

struct __declspec(align(16)) QuadCDA { float x, y, z, w; };
__forceinline __m128& quad(QuadCDA& q) { return *(__m128*)&q; }
__forceinline const __m128& quad(const QuadCDA& q) { return *(const __m128*)&q; }



class hkQuaternionCDA;

class hkVector4CDA {
public:
    QuadCDA m_vComponents;

    __forceinline hkVector4CDA& operator=(const hkVector4CDA& v)
    {
        quad(m_vComponents) = quad(v.m_vComponents);
        return *this;
    }

    __forceinline void setAdd4(const hkVector4CDA& a, const hkVector4CDA& b) { quad(m_vComponents) = _mm_add_ps(quad(a.m_vComponents), quad(b.m_vComponents)); }
    __forceinline void add4(const hkVector4CDA& a) { quad(m_vComponents) = _mm_add_ps(quad(m_vComponents), quad(a.m_vComponents)); }
    __forceinline void setMul4(const hkVector4CDA& a, const hkVector4CDA& b) { quad(m_vComponents) = _mm_mul_ps(quad(a.m_vComponents), quad(b.m_vComponents)); }
    __forceinline void addMul4(const hkVector4CDA& a, const hkVector4CDA& b) { quad(m_vComponents) = _mm_add_ps(quad(m_vComponents), _mm_mul_ps(quad(a.m_vComponents), quad(b.m_vComponents))); }
    __forceinline void addMul4(__m128 s, const hkVector4CDA& b) { quad(m_vComponents) = _mm_add_ps(quad(m_vComponents), _mm_mul_ps(_mm_shuffle_ps(s, s, 0), quad(b.m_vComponents))); }
    __forceinline void setNeg4(const hkVector4CDA& a) { quad(m_vComponents) = _mm_xor_ps(quad(a.m_vComponents), DAT_010c44d0); }
    __forceinline void setCross(const hkVector4CDA& v1, const hkVector4CDA& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(quad(v1.m_vComponents), quad(v1.m_vComponents), 0xc9), _mm_shuffle_ps(quad(v2.m_vComponents), quad(v2.m_vComponents), 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(quad(v1.m_vComponents), quad(v1.m_vComponents), 0xd2), _mm_shuffle_ps(quad(v2.m_vComponents), quad(v2.m_vComponents), 0xc9));
        quad(m_vComponents) = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4CDA& v) const
    {
        __m128 x2 = _mm_mul_ps(quad(m_vComponents), quad(v.m_vComponents));
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void setReciprocal4(const hkVector4CDA& v)
    {
        quad(m_vComponents) = _mm_rcp_ps(quad(v.m_vComponents));
        __m128 rr = _mm_mul_ps(_mm_mul_ps(quad(m_vComponents), quad(v.m_vComponents)), quad(m_vComponents));
        quad(m_vComponents) = _mm_sub_ps(_mm_add_ps(quad(m_vComponents), quad(m_vComponents)), rr);
    }
    void SetRotatedDirection(const hkQuaternionCDA& q, const hkVector4CDA& dir);
    void setRotatedInverseDir(const hkQuaternionCDA& q, const hkVector4CDA& dir);
};

class hkQuaternionCDA {
public:
    hkVector4CDA m_vec;

    __forceinline void SetConjugate(const hkQuaternionCDA& q) { quad(m_vec.m_vComponents) = _mm_xor_ps(quad(q.m_vec.m_vComponents), ::DAT_010c4c00); }
};



__forceinline void hkVector4CDA::SetRotatedDirection(const hkQuaternionCDA& quat, const hkVector4CDA& direction)
{
    hkVector4CDA qreal;
    quad(qreal.m_vComponents) = _mm_shuffle_ps(quad(quat.m_vec.m_vComponents), quad(quat.m_vec.m_vComponents), 0xff);
    hkVector4CDA q2minus1;
    q2minus1.setMul4(qreal, qreal);
    quad(q2minus1.m_vComponents) = _mm_add_ps(quad(q2minus1.m_vComponents), DAT_010c71e0);
    hkVector4CDA ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CDA imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4CDA::setRotatedInverseDir(const hkQuaternionCDA& quat, const hkVector4CDA& direction)
{
    hkVector4CDA qreal;
    quad(qreal.m_vComponents) = _mm_shuffle_ps(quad(quat.m_vec.m_vComponents), quad(quat.m_vec.m_vComponents), 0xff);
    hkVector4CDA q2minus1;
    q2minus1.setMul4(qreal, qreal);
    quad(q2minus1.m_vComponents) = _mm_add_ps(quad(q2minus1.m_vComponents), DAT_010c71e0);
    hkVector4CDA ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CDA imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformCDA {
public:
    hkVector4CDA m_vTranslation;
    hkQuaternionCDA m_rotation;
    hkVector4CDA m_vScale;

    struct InvTR {
        hkVector4CDA m_vTranslation;
        hkQuaternionCDA m_rotation;
        hkVector4CDA m_vScale;

        __forceinline void SetConjugate(const hkQsTransformCDA& t)
        {
            m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
            m_vTranslation.setNeg4(m_vTranslation);
            m_rotation.SetConjugate(t.m_rotation);
            hkVector4CDA scale;
            quad(scale.m_vComponents) = _mm_shuffle_ps(quad(t.m_vScale.m_vComponents), _mm_unpackhi_ps(quad(t.m_vScale.m_vComponents), ::DAT_010c7170), 0xc4);
            m_vScale.setReciprocal4(scale);
            quad(m_vScale.m_vComponents) = _mm_and_ps(quad(m_vScale.m_vComponents), ::DAT_010c4c10);
        }
    };

    __forceinline void SetProduct(const InvTR& t1, const hkQsTransformCDA& t2)
    {
        hkVector4CDA temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), nullptr, (const __m128 *)&(t1.m_rotation), (const __m128 *)&(t2.m_rotation));
        quad(m_vScale.m_vComponents) = _mm_mul_ps(quad(t2.m_vScale.m_vComponents), quad(t1.m_vScale.m_vComponents));
    }
    __forceinline void SetMulInverse(const hkQsTransformCDA& a, const hkQsTransformCDA& b)
    {
        InvTR h;
        h.SetConjugate(a);
        SetProduct(h, b);
    }
};

template <typename T>
class hkArrayCDA
{
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
};

struct hkaSkeletonCDA
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int m_parentIndicesSize;
    int m_parentIndicesCap;
    int unk18;
    int m_iBoneCount;
};

struct hkBoolCDA {
    char m_cBooleanValue;
    __forceinline hkBoolCDA& operator=(bool b) { m_cBooleanValue = b; return *this; }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
};

class hkaPoseCDA
{
public:
    enum { F_DIRTY_LOCAL = 0x1, F_DIRTY_MODEL = 0x2, F_INTERNAL1 = 0x4 };
    hkaSkeletonCDA* m_pSkeleton;
    hkArrayCDA<hkQsTransformCDA> m_pLocalPose;
    hkArrayCDA<hkQsTransformCDA> m_pModelPose;
    hkArrayCDA<unsigned int> m_pBoneFlags;
    hkBoolCDA m_bPoseFlag;
    hkBoolCDA m_bPoseInitialized;


    __forceinline void makeFirstChildrenModelSpace(int boneIdx)
    {
        const int nb = m_pSkeleton->m_iBoneCount;
        for (int b = boneIdx + 1; b < nb; ++b)
        {
            const int i = b;
            if (m_pSkeleton->m_kParentIndices[i] == boneIdx)
            {
                if (m_pBoneFlags[i] & F_DIRTY_MODEL)
                    reinterpret_cast<::SkeletonPoseData *>(this)->FUN_00cda180(i);
                m_pBoneFlags[i] = F_DIRTY_LOCAL;
                m_bPoseInitialized = false;
            }
        }
    }

    __forceinline int isFlagOn(int boneIdx, int flag) const { return m_pBoneFlags[boneIdx] & flag; }
    __forceinline void setFlag(int boneIdx, unsigned int flag) { m_pBoneFlags[boneIdx] |= flag; }
    __forceinline void clearFlag(int boneIdx, unsigned int flag) { m_pBoneFlags[boneIdx] &= ~flag; }

    __forceinline const hkQsTransformCDA& calculateBoneLocalSpace(int boneIdx)
    {
        const hkQsTransformCDA& modelFromBone = m_pModelPose[boneIdx];
        const short parentIdx = m_pSkeleton->m_kParentIndices[boneIdx];
        if (parentIdx != -1)
        {
            const hkQsTransformCDA& modelFromParent = isFlagOn(parentIdx, F_DIRTY_MODEL) == 0
                ? m_pModelPose[parentIdx] : (*(const ::hkQsTransformCDA *)&(reinterpret_cast<::SkeletonPoseData *>(this)->FUN_00cda180(parentIdx)));
            m_pLocalPose[boneIdx].SetMulInverse(modelFromParent, modelFromBone);
        }
        else
        {
            m_pLocalPose[boneIdx] = m_pModelPose[boneIdx];
        }
        clearFlag(boneIdx, F_DIRTY_LOCAL);
        return m_pLocalPose[boneIdx];
    }

    __forceinline void makeAllChildrenLocalSpace(int boneIdx)
    {
        const int numBones = m_pSkeleton->m_iBoneCount;
        setFlag(boneIdx, F_INTERNAL1);
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            const short parentIdx = m_pSkeleton->m_kParentIndices[i];
            if (parentIdx != -1 && isFlagOn(parentIdx, F_INTERNAL1))
            {
                if (isFlagOn(i, F_DIRTY_LOCAL))
                    calculateBoneLocalSpace(i);
                setFlag(i, F_INTERNAL1);
                m_bPoseFlag = false;
            }
        }
        for (int i = boneIdx + 1; i < numBones; ++i)
        {
            unsigned int& f = m_pBoneFlags[i];
            if (f & F_INTERNAL1)
                f = (f & ~F_INTERNAL1) | F_DIRTY_MODEL;
        }
    }

    hkQsTransformCDA& FUN_00cdad80(int boneIdx, int propagate);
public:
    void FUN_00cda690();
};
// @fnv 0x00cdb0a0
StateResetPart* FUN_00cdb290::FUN_00cdb0a0()
{
    reinterpret_cast<::hkaPoseCDA *>(this)->FUN_00cda690();
    return reinterpret_cast<::StateResetTarget *>(this)->ResetStates();
}

// Updates child bone flags (mode chosen by propagate), recalculates the bone's model pose if dirty, sets its flags to local-dirty, and returns the model pose.
// @fnv 0x00cdad80
hkQsTransformCDA& hkaPoseCDA::FUN_00cdad80(int boneIdx, int propagate)
{
    if (propagate == 0)
        makeFirstChildrenModelSpace(boneIdx);
    else
        makeAllChildrenLocalSpace(boneIdx);
    if (m_pBoneFlags[boneIdx] & F_DIRTY_MODEL)
        reinterpret_cast<::SkeletonPoseData *>(this)->FUN_00cda180(boneIdx);
    m_pBoneFlags[boneIdx] = F_DIRTY_LOCAL;
    m_bPoseInitialized = false;
    return m_pModelPose[boneIdx];
}

namespace fnv_00cc1cf0 {


// Stand-in for the game's NiTimeController: a reference-counted, polymorphic
// object whose reference counter lives at +4 and whose "release" virtual sits
// in the second vtable slot.
struct FNV_TCtrl {
    virtual void FNV_v0();
    virtual void FNV_Release();
    virtual void FNV_DecRefCount();
    virtual void FNV_IncRefCount();
    unsigned int m_uiRefCount;
};

// Stand-in for the game's NiPointer<NiTimeController>: a single pointer whose
// destructor drops the reference (that destructor is what gives the enclosing
// function its exception-handling frame).
struct FNV_TCtrlPtr {
    FNV_TCtrl* m_pObject;
    FNV_TCtrlPtr(FNV_TCtrl* object = 0) { m_pObject = object; if (m_pObject) m_pObject->FNV_IncRefCount(); }
    ~FNV_TCtrlPtr() { if (m_pObject) m_pObject->FNV_DecRefCount(); }
};

// Stand-in for the game's NiTLargeArray<NiPointer<NiTimeController> >.
struct FNV_TCtrlArray {
    void** m_ppVirtualMethodTable;
    FNV_TCtrlPtr* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void FUN_00cc1cf0();
};

// Releases every element in the array by decrementing ref counts and calling FNV_Release when the count reaches zero, then resets m_uiSize and m_uiESize.
// @fnv 0x00cc1cf0
void FNV_TCtrlArray::FUN_00cc1cf0() {
    for (unsigned int i = 0; i < m_uiSize; i++) {
        FNV_TCtrlPtr ptr;
        FNV_TCtrlPtr* pElem = &m_pBase[i];
        FNV_TCtrl* pCtrl = pElem->m_pObject;
        if (pCtrl) {
            if (InterlockedDecrement((volatile LONG*)&pCtrl->m_uiRefCount) == 0) {
                pCtrl->FNV_Release();
            }
            pElem->m_pObject = 0;
        }
    }
    m_uiSize = 0;
    m_uiESize = 0;
}
}  // namespace fnv_00cc1cf0




unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern char DAT_010c9544[];

struct ProfRec
{
    const char *m_pName;
    unsigned long m_iTick;
    unsigned long unk08;
};

struct ProfBuf
{
    unsigned long unk00;
    ProfRec *m_pCur;
    unsigned long unk08;
    ProfRec *m_pRecordEnd;
};

struct Key4
{
    int v;
    Key4(const Key4& other) : v(other.v) {}
};

struct Mat4
{
    __m128 rows[4];
};

struct ObjInfo
{
    __m128 point;
    float dist;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
};

struct Query
{
    int f00;
    int f04;
    int f08;
    int f0c;
    ObjInfo info;
};

struct PointPair
{
    __m128 p0;
    __m128 p1;
    int key;
    int filter;
};

struct HitBool
{
    unsigned char value;
    HitBool(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};

class PickObj
{
public:
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual HitBool TestInfo(PointPair *pts, ObjInfo *info);
};

struct Entry
{
    PickObj *obj;
    int f04;
    Mat4 *mat;
    int f0c;
    int f10;
    int f14;
    int f18;
    Key4 key;
};

struct EntryPair
{
    int first;
    Entry *second;
};

struct SubObj
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50, f54, f58, f5c;
    int f60, f64, f68, f6c, f70, f74, f78;
    int f7c;
};

struct RayArg
{
    __m128 p0;
    __m128 p1;
    unsigned char f20;
    unsigned char f21;
    unsigned char f22;
    unsigned char f23;
    Key4 key;
};

struct BestOut
{
    __m128 v;
    float f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    Entry *entry;
};

void FUN_00c7f700(void *a, BestOut *b);

struct Rotation3 { __m128 a, b, c; };

static __forceinline void Transpose(Rotation3& out, const Mat4* m)
{
    __m128 r0 = m->rows[0];
    __m128 r1 = m->rows[1];
    __m128 r2 = m->rows[2];
    __m128 lo = _mm_unpacklo_ps(r0, r1);
    __m128 hi = _mm_unpackhi_ps(r0, r1);
    out.a = _mm_movelh_ps(lo, r2);
    out.b = _mm_shuffle_ps(_mm_movehl_ps(hi, lo), r2, 0xd4);
    out.c = _mm_shuffle_ps(hi, r2, 0xe4);
}

static __forceinline void TransformPoint(__m128 &out, const Mat4 *m, const __m128 &pt)
{
    __m128 t0 = _mm_sub_ps(pt, m->rows[3]);
    __m128 c0 = m->rows[0];
    __m128 c1 = m->rows[1];
    __m128 c2 = m->rows[2];
    {
        __m128 tmp = _mm_unpacklo_ps(c0, c1);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(tmp, c2);
        tmp = _mm_movehl_ps(c0, tmp);
        c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
        c2 = ctmp;
    }
    __m128 b0 = _mm_shuffle_ps(t0, t0, 0);
    __m128 b1 = _mm_shuffle_ps(t0, t0, 0x55);
    __m128 b2 = _mm_shuffle_ps(t0, t0, 0xaa);
    __m128 r0 = _mm_mul_ps(c0, b0);
    __m128 r1 = _mm_mul_ps(c1, b1);
    __m128 r2 = _mm_mul_ps(c2, b2);
    out = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

class PickSelf
{
public:
    int f00;
    int f04;
    SubObj *sub;
    int f0c, f10, f14, f18, f1c, f20, f24, f28, f2c;
    int f30, f34, f38, f3c, f40, f44, f48, f4c;
    int f50, f54, f58, f5c, f60, f64, f68, f6c;
    int f70, f74, f78, f7c, f80, f84, f88, f8c;
    int f90, f94, f98, f9c, fa0, fa4, fa8, fac;
    int fb0, fb4, fb8, fbc, fc0, fc4, fc8, fcc;
    int fd0, fd4, fd8, fdc, fe0, fe4, fe8, fec;
    int ff0, ff4, ff8, ffc, f100, f104, f108, f10c;
    int f110, f114, f118, f11c, f120, f124, f128, f12c;
    int f130, f134, f138, f13c, f140, f144, f148, f14c;
    int f150, f154, f158, f15c;
    EntryPair *pairs;
    int count;
    void FUN_00cc26c0(RayArg *arg1, BestOut *arg2);
};

// @fnv 0x00cc26c0
void PickSelf::FUN_00cc26c0(RayArg *arg1, BestOut *arg2)
{
    ProfBuf *buf = (ProfBuf *)TlsGetValue(DAT_0126835c);
    ProfRec *rec = buf->m_pCur;
    HitBool canWrite = rec < buf->m_pRecordEnd;
    if (canWrite)
    {
        rec->m_pName = DAT_010c9544;
        unsigned int stamp;
        stamp = (unsigned int)__rdtsc();
        rec->m_iTick = stamp;
        buf->m_pCur = rec + 1;
    }
    ObjInfo info;
    info.dist = 1.0f;
    info.f14 = -1;
    info.f20 = -1;
    info.f40 = 0;
    PointPair pts;
    pts.filter = 0;
    pts.key = arg1->key.v;
    pts.filter = arg1->f20 && sub->f7c ? sub->f7c + 0x10 : 0;
    bool flag = false;
    int n = count;
    int i = n - 1;
    if (i >= 0)
    {
        do
        {
            Entry *e = pairs[i].second;
            PickObj *o = e->obj;
            if (o != 0)
            {
                Key4 ek = e->key;
                if (::FUN_00c84740((*(unsigned int *)&(const ::Key4 &)(arg1->key)), (*(unsigned int *)&(const ::Key4 &)(ek))))
                {
                    Mat4 *mat = e->mat;
                    TransformPoint(pts.p0, mat, arg1->p0);
                    TransformPoint(pts.p1, mat, arg1->p1);
                    info.dist = 1.0f;
                    info.f14 = -1;
                    info.f40 = 0;
                    info.f20 = -1;
                    HitBool hit = o->TestInfo(&pts, &info);
                    if (hit)
                    {
                        if (!flag || info.dist < arg2->f10)
                        {
                            arg2->f10 = info.dist;
                            flag = true;
                            arg2->v = info.point;
                            arg2->entry = e;
                        }
                    }
                }
            }
        } while (--i >= 0);
    }
    if (arg2->entry != 0)
    {
        FUN_00c7f700(arg2->entry->mat, arg2);
    }
        ProfBuf *buf2 = (ProfBuf *)TlsGetValue(DAT_0126835c);
        ProfRec *rec2 = buf2->m_pCur;
        if (rec2 < buf2->m_pRecordEnd)
        {
            rec2->m_pName = DAT_010c41f8;
            unsigned int stamp;
            stamp = (unsigned int)__rdtsc();
            rec2->m_iTick = stamp;
            buf2->m_pCur = rec2 + 1;
        }
}

struct FUN_00c8a720 {
  void* vtable;
  virtual ~FUN_00c8a720();
};
struct FUN_00cc2ac0 : FUN_00c8a720 {
  virtual ~FUN_00cc2ac0();
};
// Destructor that calls FUN_00c876a0 and decrements the global DAT_012685ac.
// @fnv 0x00cc2ac0
FUN_00cc2ac0::~FUN_00cc2ac0() {
  static_cast<::ProjectileListener *>(nullptr)->FUN_00c876a0();
  --DAT_012685ac;
}

namespace fnv_00cc5c70 {
struct TlsBlock_t
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};
__declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = (*reinterpret_cast<::fnv_00cc5c70::TlsBlock_t *>(&::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::fnv_00cc5c70::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        (*reinterpret_cast<::fnv_00cc5c70::TlsBlock_t *>(&::g_tlsBlock)).m_2b4 = m_saved;
    }
};



struct PoolAlloc {  };
struct B0 { void* vf; };
struct Inner { Inner* p; int rc; int a; int b; };

struct NewObj : B0, Inner
{
    NewObj()
    {
        Inner* in = static_cast<Inner*>(this);
        rc = 1;
        a = 0;
        b = 0;
        vf = (void*)&::DAT_010c5398;
        in->p = 0;
    }
};

struct FUN_00cc5c70_cls
{
    int m_00;
    int m_04;
    int m_08;
    Inner* m_0c;
    Inner* FUN_00cc5c70(bool* out);
};

// Creates a NewObj if m_0c is null, sets out to whether it was newly created, and returns the m_0c pointer.
// @fnv 0x00cc5c70
Inner* FUN_00cc5c70_cls::FUN_00cc5c70(bool* abCreated)
{
    TlsGuard_t guard;
    *abCreated = (m_0c == 0);
    if (*abCreated)
    {
        NewObj* o = new NewObj;
        m_0c = o;
        if (m_08)
            reinterpret_cast<::FUN_00c89c80_obj *>(this)->CopyFromSource((void*)(static_cast<NewObj*>(m_0c)));
    }
    return m_0c;
}
}  // namespace fnv_00cc5c70

namespace fnv_00cc81c0 {

struct hkTransformStub { float m00, m04, m08, m0C, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C; };

struct ShapeInner { int unk00; int unk04; int unk08; };
struct ShapeHolder { int unk00; int unk04; int unk08; ShapeInner* unk0C; };

struct RigidBodyStub {
    int unk00;
    int unk04;
    int unk08;
    ShapeInner* unk0C;
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
    hkTransformStub m_kMotionTransform;
};

struct ParamStub {
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
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual RigidBodyStub* GetBodyCC();
    virtual ShapeHolder* GetD0();
};

struct RefBase {
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    RefBase() : unk04(0), unk08(1), unk0C(0), unk10(0) {}
    virtual ~RefBase() { reinterpret_cast<::C89AC0_Owner *>(this)->SetChildObject((::C89AC0_Child *)(0)); }
    void Release(int);
};

struct AllocTypeGuard {
    int m_saved;
    AllocTypeGuard(int type) { m_saved = (*reinterpret_cast<int *>(&::currentAllocationContext)); (*reinterpret_cast<int *>(&::currentAllocationContext)) = type; }
    ~AllocTypeGuard() { (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_saved; }
};

struct CinfoA : RefBase {
    int unk14;
    int unk18;
    CinfoA() {}
    ~CinfoA() {}
};

struct CinfoB : RefBase {
    CinfoB() {}
};

struct ResultBase {
    int unk00; int unk04; int unk08; int unk0C;
};
struct ResultA : ResultBase { ResultA(CinfoA& a); };
struct ResultB : ResultBase { ResultB(CinfoB& b); };

// Fills a CinfoA from the param's body and shape data and returns a ResultA, or a ResultB with SetScale(f) applied when f is below 1.0.
// @fnv 0x00cc81c0
ResultBase* __cdecl FUN_00cc81c0(ParamStub* apParam, float afScale)
{
    AllocTypeGuard guard(0x10);
    ResultBase* result;
    {
        CinfoA a;
        ShapeHolder* holder = apParam->GetD0();
        ShapeInner* pShapeInner = holder ? holder->unk0C : 0;
        RigidBodyStub* body = apParam->GetBodyCC();
        a.unk0C = (body && body->unk0C) ? body->unk0C->unk08 : 0;
        a.unk10 = pShapeInner ? pShapeInner->unk08 : 0;
        body = apParam->GetBodyCC();
        if (body) reinterpret_cast<::Cc7Owner *>(&(a))->FUN_00cc7fe0((void *)&(body->m_kMotionTransform)); else reinterpret_cast<::Cc7Owner *>(&(a))->FUN_00cc7fe0((void *)&(DAT_01268370));
        if (afScale < 1.0f) {
            CinfoB b;
            reinterpret_cast<::fnv_00ca9da0::FUN_00ca9da0_cls *>(&(b))->EnsureSpawnedObject();
            reinterpret_cast<::FUN_00ca9e50_Obj *>(&(b))->FUN_00ca9e50(a.unk04);
            b.unk0C = a.unk0C;
            b.unk10 = a.unk10;
            reinterpret_cast<::FUN_00ca9840_Class *>(&(b))->SetFieldValue(afScale);
            result = new ResultB(b);
        } else {
            result = new ResultA(a);
        }
    }
    return result;
}
}  // namespace fnv_00cc81c0

inline float scalar(const __m128& value) {float result; _mm_store_ss(&result,value); return result;}
static const __m128 signMask = {-0.0f,-0.0f,-0.0f,-0.0f};
inline float cosineAngle(float angle) {return static_cast<float>(cos(angle));}

__forceinline __m128 readQuad(const __m128* __restrict p){return *p;}
__forceinline const __m128& readQuadRef(const __m128* __restrict p){return *p;}
__forceinline __m128 readFloats(const float* __restrict p){return _mm_load_ps(p);}
__forceinline const __m128& readFloatsRef(const float* __restrict p){return *reinterpret_cast<const __m128*>(p);}

struct Bool {
    char value;
    Bool(bool v) : value(v) {}
    operator bool() const {return value!=0;}
};
struct Shape {
    int unk00, unk04, unk08, type;
    __m128 unk10, vertexA, vertexB, vertexC;
    Bool isTriangle() const {Bool result=type==3; _ReadWriteBarrier(); return result;}
};
struct Body {
    Shape* shape;
    int key;
    void* transform;
    Body* parent;
    signed char bodyOffset;
    char unk11,unk12,unk13;
    int unk14,unk18,unk1c,unk20,unk24;
    char kind,unk29,unk2a,unk2b;
    unsigned flags;
    Bool isSpecial() const {Bool result=kind==1; _ReadWriteBarrier(); return result;}
    Bool isFlagged() const {Bool result=(flags&0x7f)==30; _ReadWriteBarrier(); return result;}
};
struct Input { __m128 position,direction; Body* a; Body* b; };
struct ShapeKeys { unsigned keys[8]; };
struct Collision {
    __m128 position,direction;
    Body* a; int state;
    ShapeKeys shapeKeysA;
    Body* b; int key;
    ShapeKeys shapeKeysB;
    Collision() {}
    __forceinline Collision(const Collision& c) {_mm_store_ps(reinterpret_cast<float*>(&position),c.position); _mm_store_ps(reinterpret_cast<float*>(&direction),c.direction); a=c.a; state=c.state; shapeKeysA=c.shapeKeysA; b=c.b; key=c.key; shapeKeysB=c.shapeKeysB; }
};
struct PointMatrix { __m128 x,y,z; };
struct PointVector { __m128 value; void FUN_00c7f700(const PointMatrix&,const PointVector&); };

template<class T> struct PointArray {
    T* data; int count; unsigned capacity;
    void reserve() {
        S_00cc4b90_Router* ctx=static_cast<S_00cc4b90_Router*>(::FUN_00c85750());
        if(count==int(capacity&0x3fffffff)) ::ResizeAudioStream((::AudioAllocator *)(ctx->unk10),(::AudioStream *)(void *)(this),sizeof(T));
    }
    __forceinline void append(const T& value) {reserve(); new(data+count) T(value); ++count;}
    T& expand() {reserve(); return data[count++];}
    __forceinline void appendPointer(Body* value) {
        reserve(); T* item=data+count; _ReadWriteBarrier(); *item=value; ++count;
    }
    int find(Body* value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Collector {
    int unk00,unk04,unk08,unk0c;
    PointArray<Collision> collisions;
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
    PointArray<Body*> bodies;
    PointArray<int> states;
    PointArray<Collision> pending;
    void FUN_00cd36a0(Input* input);
};
// @fnv 0x00cd36a0
void Collector::FUN_00cd36a0(Input* input) {
    Body* root=input->b;
    while(root->parent) root=root->parent;
    Body* body=reinterpret_cast<Body*>(reinterpret_cast<char*>(root)+root->bodyOffset);
    if(!body) return;
    int index=bodies.find(body);
    if(index==-1) {
        reinterpret_cast<::FUN_00c90510_class *>((body))->FUN_00c90510();
        bodies.appendPointer(body);
        Collision collision;
        collision.position=input->position;
        collision.direction=input->direction;
        Body* a=input->a;
        while(a->parent) a=a->parent;
        collision.a=a;
        collision.state=input->a->key;
        Body* b=input->b;
        while(b->parent) b=b->parent;
        collision.b=b;
        collision.key=input->b->key;
        pending.append(collision);
        states.append(0);
    } else if(states.data[index]==1) states.data[index]=2;
    if(body->isSpecial() || body->isFlagged()) {
        Collision& collision=collisions.expand();
PointVector direction; (void)direction.value;
        collision.position=input->position;
        collision.direction=input->direction;
        Body* a=input->a;
        while(a->parent) a=a->parent;
        collision.a=a;
        Body* b=input->b;
        while(b->parent) b=b->parent;
        collision.b=b;
        collision.state=0;
        collision.key=input->b->key;
        float threshold=static_cast<float>(cosineAngle(0.008726646192371845f));
        if(input->b->shape->isTriangle()) {
            collision.state=2;
            Body* triangle=input->b;
            Shape* shape=triangle->shape;
            const __m128* __restrict p=&shape->vertexB;
            __m128 first=shape->vertexA;
            __m128 second=shape->vertexB;
            __m128 next=*p;
            __m128 u=_mm_sub_ps(second,first);
            __m128 v=_mm_sub_ps(shape->vertexC,next);
            __m128 normal=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(u,u,0xc9),_mm_shuffle_ps(v,v,0xd2)),_mm_mul_ps(_mm_shuffle_ps(u,u,0xd2),_mm_shuffle_ps(v,v,0xc9)));
            Normalize(normal);
            reinterpret_cast<PointVector&>(normal).FUN_00c7f700(*static_cast<PointMatrix*>(triangle->transform),reinterpret_cast<const PointVector&>(normal));
            direction.value=collision.direction;
            __m128 product=_mm_mul_ps(normal,direction.value);
            __m128 rotated=_mm_load_ps(reinterpret_cast<float*>(&normal));
            __m128 dot=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
            dot=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),dot);
            if(scalar(dot)<0.0f) rotated=_mm_xor_ps(rotated,signMask);
            product=_mm_mul_ps(direction.value,rotated);
            dot=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
            dot=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),dot);
            if(scalar(dot)>threshold) collision.state=1;
            reinterpret_cast<::ContactManifold *>(this)->FUN_00cd3080();
        }
    }
}


struct S00cd8920_Vec {
    float x;
    float y;
    float z;
    float w;
};

struct S00cd8920_Pair {
    short a;
    short b;
};

struct S00cd8920_Obj {
    const struct Skeleton* unk00;
    short unk04a;short unk04b;
    short unk08;
    unsigned short unk0A;
    unsigned int unk0C;
    S00cd8920_Vec unk10;
    S00cd8920_Vec unk20;
    S00cd8920_Vec unk30;
    S00cd8920_Vec unk40;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68;
    float unk6C;
    float unk70;
    bool unk74;

    S00cd8920_Obj* FUN_00cd8920();
};

// Initializes the object: null pointer, shorts set to -1, four vectors copied from one global, floats set to fixed defaults, flag cleared; returns this.
// @fnv 0x00cd8920
S00cd8920_Obj* S00cd8920_Obj::FUN_00cd8920()
{
    unk00 = 0;
    unk04a = -1;
    unk04b = -1;
    unk08 = -1;

    const S00cd8920_Vec& v = *(const S00cd8920_Vec*)&DAT_01267e30;
    unk10 = v;
    unk20 = v;
    unk30 = v;
    unk40 = v;

    unk50 = 0.0f;
    unk54 = 0.0f;
    unk58 = 0.0f;
    unk74 = 0;

    unk5C = 0.7f;
    unk60 = -0.1f;
    unk64 = -1.0f;
    unk68 = 1.0f;
    unk6C = 0.5f;
    unk70 = 0.8f;

    return this;
}

namespace fnv_00cd9d10 {

extern __m128 DAT_010cb620;
extern __m128 DAT_010c71d0;
extern __m128 DAT_010c71c0;
extern __m128 DAT_010cb630;
extern float DAT_01011d78;
extern float DAT_01017718;



struct VectorLocal {
 __m128 value;
 __forceinline VectorLocal() {}
 __forceinline VectorLocal(__m128 v):value(v){}
 __forceinline operator __m128() const { return value; }
 __forceinline VectorLocal& operator=(__m128 v) {value=v;return *this;}
};
static inline __m128 quadRsqrt(__m128 r)
{
    const VectorLocal e = _mm_rsqrt_ps(r);
    const __m128 he = _mm_mul_ps(DAT_010c71d0, e);
    const __m128 ree = _mm_mul_ps(_mm_mul_ps(e, r), e);
    return _mm_mul_ps(he, _mm_sub_ps(DAT_010c71c0, ree));
}

struct Q_00cd9d10 {
    __m128 q;
    void FUN_00cd9d10(const __m128* from, const __m128* to);
};

// Builds a quaternion from vectors from and to via their dot and cross products, with special cases for dot near 1 and near -1.
// @fnv 0x00cd9d10
void Q_00cd9d10::FUN_00cd9d10(const __m128* from, const __m128* to)
{
    __m128 vf = *from;
    __m128 nzero = (*reinterpret_cast<__m128 *>((void *)&::DAT_010c44d0));
    __m128 vt = *to;
    VectorLocal mul = _mm_mul_ps(vt, vf);
    __m128 y2 = _mm_shuffle_ps(mul, mul, 0x55);
    y2 = _mm_add_ss(y2, mul);
    __m128 z2 = _mm_shuffle_ps(mul, mul, 0xaa);
    z2 = _mm_add_ss(z2, y2);
    __m128 spl = _mm_shuffle_ps(z2, z2, 0);
    __m128 dot = spl;
    __m128 near1 = DAT_010cb620;
    nzero = _mm_xor_ps(nzero, near1);
    __m128 m1 = _mm_cmplt_ps(near1, dot);
    int mask1 = _mm_movemask_ps(m1);
    __m128 m2 = _mm_cmplt_ps(dot, nzero);
    if (mask1) {
        this->q = (*reinterpret_cast<__m128 *>((void *)&::DAT_010c71b0));
        return;
    }
    if (_mm_movemask_ps(m2)) {
        reinterpret_cast<::fnv_00cb2700::PerpendicularVector *>((void *)(from))->FUN_00cb2700({});
        return;
    }
    __m128 three = (*reinterpret_cast<__m128 *>(&::DAT_010c71c0));
    VectorLocal t = _mm_add_ps(_mm_mul_ps(DAT_010c71d0, dot), DAT_010c71d0);
    __m128 nr = quadRsqrt(t);
    __m128 s1 = _mm_shuffle_ps(vt, vt, 201);
    __m128 s2 = _mm_shuffle_ps(vf, vf, 210);
    __m128 mx1 = _mm_mul_ps(s1, s2);
    __m128 s3 = _mm_shuffle_ps(vf, vf, 201);
    __m128 s4 = _mm_shuffle_ps(vt, vt, 210);
    __m128 mx2 = _mm_mul_ps(s4, s3);
    __m128 cross = _mm_sub_ps(mx2, mx1);
    __m128 neg999 = DAT_010cb630;
    __m128 dc = dot;
    __m128 near180 = _mm_cmplt_ps(dc, neg999);
    int mask180 = _mm_movemask_ps(near180);
    __m128 w05 = _mm_mul_ps(nr, DAT_010c71d0);
    if (mask180) {
        __m128 z0 = _mm_set_ss(DAT_01011d78);
        __m128 l2c = cross;
        __m128 l2 = _mm_mul_ps(l2c, cross);
        __m128 yl = _mm_shuffle_ps(l2, l2, 0x55);
        yl = _mm_add_ss(yl, l2);
        __m128 zl = _mm_shuffle_ps(l2, l2, 0xaa);
        zl = _mm_add_ss(zl, yl);
        __m128 lc = zl;
        __m128 rs = _mm_rsqrt_ss(lc);
        __m128 u = _mm_sub_ps(t, dot);
        __m128 rsc = rs;
        __m128 cz = _mm_set_ss(DAT_01011d78);
        __m128 czc = cz;
        __m128 lc2 = zl;
        zl = _mm_mul_ss(zl, rsc);
        zl = _mm_mul_ss(zl, rsc);
        __m128 eq = _mm_cmpeq_ss(lc2, czc);
        __m128 t3 = _mm_set_ss(DAT_01017718);
        __m128 sub = _mm_sub_ss(t3, zl);
        __m128 t5 = _mm_set_ss(::fnv_00c88020::DAT_01016248);
        __m128 g1 = _mm_mul_ss(t5, rsc);
        __m128 g2 = _mm_mul_ss(g1, sub);
        __m128 guard = _mm_andnot_ps(eq, g2);
        __m128 r2 = _mm_rsqrt_ps(u);
        __m128 ur2 = _mm_mul_ps(_mm_mul_ps(r2, u), r2);
        r2 = _mm_mul_ps(r2, DAT_010c71d0);
        __m128 nr2 = _mm_sub_ps(three, ur2);
        nr2 = _mm_mul_ps(nr2, r2);
        nr2 = _mm_mul_ps(nr2, u);
        __m128 guardB = _mm_shuffle_ps(guard, guard, 0);
        nr2 = _mm_mul_ps(nr2, guardB);
        w05 = nr2;
    }
    __m128 xyz = _mm_mul_ps(w05, cross);
    __m128 loc = xyz;
    __m128 wv = _mm_mul_ps(t, nr);
    __m128 hi = _mm_unpackhi_ps(xyz, wv);
    __m128 res = _mm_shuffle_ps(loc, hi, 196);
    this->q = res;
}
}  // namespace fnv_00cd9d10




struct ConstraintInput {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void disable();
};
struct TimerEvent {
    const char* name;
    unsigned int ticks;
    unsigned int auxiliary;
};
struct TimerBuffer {
    TimerEvent* begin;
    TimerEvent* current;
    TimerEvent* storage;
    TimerEvent* end;
    void emit(const char* name) {
        TimerEvent* event = current;
        if (event < end) {
            event->name = name;
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            event->ticks = ticks;
            current = event + 1;
        }
    }
};
struct ConstraintRecord {
    unsigned short type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    unsigned short size;
    unsigned short unk12;
    unsigned int unk14, unk18, unk1c;
    ConstraintRecord() : type(27), size(32) {}
    static void* operator new(std::size_t n) {
        return static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap().AllocateMemoryBlock(n);
    }
};

// Disables the input, records a timer event, and if no ConstraintRecord exists on owner, allocates one and links it via FUN_00d27960.
// @fnv 0x00cdff60
void __cdecl FUN_00cdff60(void* owner, ConstraintInput* input) {
    input->disable();
    static_cast<TimerBuffer*>(TlsGetValue(DAT_0126835c))->emit("TtDsblConstr");
    if (!((void *)(::FindModifierConstraintAtom((::hkpConstraintInstance *)(owner), 27)))) {
        ConstraintRecord* record = new ConstraintRecord;
        ::FUN_00d27960((::hkpConstraintInstance *)(owner), (*(::hkpConstraintOwner *)(input)), (::hkpModifierConstraintAtom *)(record));
    }
    static_cast<TimerBuffer*>(TlsGetValue(DAT_0126835c))->emit("Et");
}

struct S00ccaaf0_arg {
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    float m_f10;
};

class S00ccaaf0_cls {
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual FUN_00cca9c0_class* vb4(unsigned char* out);
    void FUN_00ccaaf0(void* a1, S00ccaaf0_arg* a2);
};


// @fnv 0x00ccaaf0
void S00ccaaf0_cls::FUN_00ccaaf0(void* a1, S00ccaaf0_arg* a2)
{
    unsigned int tmp;
    FUN_00cca9c0_class* obj = vb4((unsigned char*)&tmp + 3);
    float f = a2->m_f10;
    if (f != 1.0f) {
        obj->FUN_00cca9c0(f);
    }
    reinterpret_cast<::FUN_00c84df0_cls *>((((Owner*)this)))->FUN_00c84df0((::FUN_00c84df0_cls *)(a1), (::FUN_00c84df0_cls *)(void *)((void*)a2));
}

struct bhkLimitedHingeVector_SV {
    float m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_iThirdValue;
};

struct CC2B60Src {
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
    float m_30[4];
    float m_40[4];
    float m_50;
    float m_54;
    float m_58;
    unsigned char m_5c;
    unsigned char m_5d;
};

struct CC2B60Dst {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    bhkLimitedHingeVector_SV m_10;
    bhkLimitedHingeVector_SV m_20;
    float m_30;
    float m_34;
    float m_38;
    unsigned char m_3c;
    unsigned char m_3d;
};

struct CC2F90Owner_SV {
    int unk00;
    int unk04;
    CC2B60Src* m_pParentNode;
    void* m_pkChild;

    void FUN_00cc2b60(CC2B60Dst* pkChild);
};
// @fnv 0x00cc2f90
CC2F90Child* CC2F90Owner::FUN_00cc2f90(bool* pbCreated)
{
    CC2F90AllocTagScope kScope(0x10);
    *pbCreated = (m_pkChild == 0);
    if (m_pkChild == 0) {
        m_pkChild = new (CC2F90AlignedAlloc(0x50)) CC2F90Child();
        if (m_pParentNode)
            reinterpret_cast<::CC2F90Owner_SV *>(this)->FUN_00cc2b60((::CC2B60Dst *)(m_pkChild));
    }
    return m_pkChild;
}

// Calls FUN_00c8a800 on pkChild, then if m_pParentNode is set copies three floats, two four-float vectors and two bytes from it into pkChild.
// @fnv 0x00cc2b60
void CC2F90Owner_SV::FUN_00cc2b60(CC2B60Dst* pkChild)
{
    reinterpret_cast<::FUN_00c8a800_cls *>(this)->WriteScriptTargetInfo((::ScriptOutBlock *)(pkChild));
    if (this && m_pParentNode)
    {
        CC2B60Src* pkSrc = m_pParentNode;
        pkChild->m_30 = pkSrc->m_50;
        pkChild->m_34 = pkSrc->m_54;
        pkChild->m_38 = pkSrc->m_58;
        reinterpret_cast<::S004b4db0_Quaternion *>(&(pkChild->m_10))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(pkSrc->m_30)));
        reinterpret_cast<::S004b4db0_Quaternion *>(&(pkChild->m_20))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(pkSrc->m_40)));
        pkChild->m_3c = pkSrc->m_5c ? pkSrc->m_5c : pkSrc->m_5c;
        pkChild->m_3d = pkSrc->m_5d ? pkSrc->m_5d : pkSrc->m_5d;
    }
}

struct MalleableConstraintStrength {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float strength;

    float FUN_00cdf680() const;
};

// @fnv 0x00cdf680
float MalleableConstraintStrength::FUN_00cdf680() const
{
    return strength;
}


struct FNVEffectRec
{
    unsigned short m_sType;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned short m_sSize;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    float m_fValue20;
    float m_fValue24;
};


// Disables a4, then sets two floats on p's type 0x17 record, creating and registering one via FUN_00d27960 if absent; brackets work with profiler marks.
// @fnv 0x00cdfbd0
void __cdecl FUN_00cdfbd0(FUN_00cdfe00_Object* a1, int aiUnk2, int aiUnk3, ConstraintInput* apConstraintInput, float afValue20, float afValue24)
{
    volatile unsigned long tick;
    void* p = a1->vf40();
    if (p == 0)
    {
        return;
    }
    apConstraintInput->disable();

    void* (*pfnTls)(unsigned long) = TlsGetValue;
    ProfBuf* pBuf = (ProfBuf*)pfnTls(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "TtSetSoftContact";
        _ReadWriteBarrier();
        tick = (unsigned long)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }

    FNVEffectRec* rec = (FNVEffectRec*)((void *)(::FindModifierConstraintAtom((::hkpConstraintInstance *)(p), 0x17)));
    if (rec != 0)
    {
        rec->m_fValue20 = afValue20;
        rec->m_fValue24 = afValue24;
    }
    else
    {
        S_00cc4b90_Router* holder = static_cast<S_00cc4b90_Router*>(::FUN_00c85750());
        S_00cc4b90_Alloc* alloc = holder->unk10;
        rec = (FNVEffectRec*)alloc->AllocateMemoryBlock(0x30);
        if (rec != 0)
        {
            rec->m_fValue20 = DAT_0101e2bc;
            rec->m_fValue24 = ::DAT_01017868;
            rec->m_sType = 0x17;
            rec->m_sSize = 0x30;
        }
        else
        {
            rec = 0;
        }
        rec->m_fValue20 = afValue20;
        rec->m_fValue24 = afValue24;
        ::FUN_00d27960((::hkpConstraintInstance *)(p), (*(::hkpConstraintOwner *)(apConstraintInput)), (::hkpModifierConstraintAtom *)(::ConstraintRecord *)((ConstraintRecord*)rec));
    }

    pBuf = (ProfBuf*)pfnTls(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "Et";
        _ReadWriteBarrier();
        tick = (unsigned long)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }
}

// If vf40 returns a handle, disables pObj and, when h has no atom of type 0x19, allocates one and passes it to FUN_00d27960.
// @fnv 0x00cdfe90
void __cdecl FUN_00cdfe90(FUN_00cdfe00_Object* pNode, ConstraintInput* pObj)
{
    volatile unsigned long ticks;
    void* h = pNode->vf40();
    if (h != 0)
    {
        pObj->disable();
        void* (*pfnTls)(unsigned long) = TlsGetValue;
        ProfBuf* pBuf = (ProfBuf*)pfnTls(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            ProfRec* pRec = pBuf->m_pCur;
            pRec->m_pName = "TtSetSurfVisc";
            _ReadWriteBarrier();
            ticks = (unsigned long)__rdtsc();
            pRec->m_iTick = ticks;
            pBuf->m_pCur = pRec + 1;
        }
        if (((void *)(::FindModifierConstraintAtom((::hkpConstraintInstance *)(h), 0x19))) == 0)
        {
            ConstraintRecord* m = (ConstraintRecord*)static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap().AllocateMemoryBlock(0x20);
            if (m)
            {
                m->type = 0x19;
                m->size = 0x20;
            }
            else
                m = 0;
            ::FUN_00d27960((::hkpConstraintInstance *)(h), (*(::hkpConstraintOwner *)(pObj)), (::hkpModifierConstraintAtom *)(m));
        }
        pBuf = (ProfBuf*)pfnTls(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            ProfRec* pRec = pBuf->m_pCur;
            pRec->m_pName = "Et";
            _ReadWriteBarrier();
            ticks = (unsigned long)__rdtsc();
            pRec->m_iTick = ticks;
            pBuf->m_pCur = pRec + 1;
        }
    }
}

namespace CE6Memory {
}

struct CE6Heap {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void Free(void* p,int n);
};
struct CE6Vec { __m128 v; };
struct CE6Array {
 CE6Vec* data; int size; int capacity;
 CE6Array():data(0),size(0),capacity(0x80000000) {}
 ~CE6Array() { clear(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap()); }
 void clear(S_00cc4b90_Alloc& alloc) { size=0; if(!(capacity&0x80000000)) reinterpret_cast<CE6Heap&>(alloc).Free(data,(capacity&0x3fffffff)*sizeof(CE6Vec)); data=0;capacity=0x80000000; }
 void reserve(S_00cc4b90_Alloc& heap,int n) { int cap=capacity&0x3fffffff; if(cap<n) { int doubled=cap*2; ::FUN_00c908c0((::SpawnedObject *)(void *)(&heap),(::SpawnedArray *)(void *)(this),n<doubled?doubled:n,sizeof(CE6Vec)); } }
 void resize(int n) { reserve(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap(),n); size=n; }
};
struct CE6Hull { CE6Array a,b; ~CE6Hull(); };
struct CE6View { CE6Vec* data; int count; int stride; CE6View(const CE6Array& a) { count=a.size; stride=sizeof(CE6Vec); data=a.data; } };
struct CE6Shape {
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
virtual int Count();
virtual CE6Vec* Vertices(CE6Vec* buffer);
};
struct CE6Owner {
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
virtual void v94();
virtual void v98();
virtual void v9c();
virtual void va0();
virtual void va4();
virtual void va8();
virtual void vac();
virtual void vb0();
virtual void vb4();
virtual void vb8();
virtual void vbc();
virtual void vc0();
virtual void vc4();
virtual void vc8();
virtual void vcc();
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void Output(void* first,CE6Hull* hull,void* second,const char* name);
 int unk04; CE6Shape* unk08;
 void FUN_00cce600(void* first,void* second);
};
// Computes the convex hull of the shape's vertices and calls Output with the hull and the name "bhkConvexVerticesShape".
// @fnv 0x00cce600
void CE6Owner::FUN_00cce600(void* first,void* second) {
 S_00cc4b90_Ctx context(0x10);
 CE6Shape* shape=this ? unk08 : 0;
 int n=shape->Count();
 CE6Array scratch;
 scratch.resize(n);
 CE6Vec* input=shape->Vertices(scratch.data);
 CE6Array vertices;
 vertices.resize(n);
 for(int i=0;i<n;++i) vertices.data[i].v=input[i].v;
 CE6View view(vertices);
 CE6Hull hull;
 ::InitAndSetB((void *)(&view),(intptr_t)(&hull));
 Output(first,&hull,second,"bhkConvexVerticesShape");
}

struct EdaTls_t
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
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};


struct TlsGuard_t_SV
{
    int m_saved;
    TlsGuard_t_SV()
    {
        m_saved = (*reinterpret_cast<::TlsBlock_t *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4;
        (*reinterpret_cast<::TlsBlock_t *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4 = 0x10;
    }
    ~TlsGuard_t_SV()
    {
        (*reinterpret_cast<::TlsBlock_t *>(&::fnv_00c9bef0::g_tlsBlock)).m_2b4 = m_saved;
    }
};



class FUN_00cceda0_cls
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
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void v0C4(void* p, unsigned int a);

    void* FUN_00cceda0(unsigned int arg);
};

// Creates a new FUN_00cce990 object, initializes it via v0C4 with the given argument, and returns the pointer.
// @fnv 0x00cceda0
void* FUN_00cceda0_cls::FUN_00cceda0(unsigned int arg)
{
    TlsGuard_t_SV guard;
    FUN_00c876f0();
    FUN_00cce990* res = 0;
    res = new FUN_00cce990();
    this->v0C4(res, arg);
    FUN_00c87700();
    return res;
}


struct hkReferencedObject;




bool FUN_00ccba20(char* p, int, char* q);

void FUN_00cdf270(char* self, int, char* apMatrix);



int __cdecl FUN_00cc1e30();



void* FUN_00aa13e0(unsigned int size);

void* __cdecl FUN_00aa13e0(unsigned int size);

extern __declspec(thread) TlsBlock_t g_tlsBlock;


void* __cdecl FUN_00cc2b30();



void* __cdecl FUN_00cc32e0();

int __cdecl FUN_00cc32f0();

typedef unsigned int*(* GetPacketBlock)(PacketReader*, unsigned char*);

void* __cdecl FUN_00cc3a20();

int* __cdecl FUN_00cc41f0();

int* __cdecl FUN_00cc4860();

void* __cdecl FUN_00aa13e0(unsigned int size);


typedef unsigned int(__cdecl* FUN_00cc4e90_readfn)(FUN_00cc4e90_stream* s, void* dst, unsigned int size,
                                                   unsigned int* outCount, unsigned int count);

void* __cdecl FUN_00cc5100(void);



int* __cdecl FUN_00cc5ed0();

void* __cdecl FUN_00cc74c0();

void* FUN_00cc74d0();


int* __cdecl FUN_00cc7d70();

int __cdecl FUN_00cc7d80();

CpuOpaque* __cdecl FUN_00cc7d90();

void* __cdecl FUN_00cc84f0();



int* __cdecl FUN_00cc8d50();

int __cdecl FUN_00cc8d60();

int* FUN_00cc8d70();








void* __cdecl FUN_00cc9db0();

int __cdecl FUN_00cc9dc0();


int __cdecl FUN_00cca940();


void* __cdecl FUN_00ccb130();

int __cdecl FUN_00ccb140();

void* FUN_00ccb150();



void* __cdecl FUN_00ccb990();

void* __cdecl FUN_00aa13e0(unsigned int size);

int __cdecl FUN_00ccbb30();

int __cdecl FUN_00ccbb40();


typedef FNVHolder*(* FNVQuery)(FNVTarget*, bool*);



// FUN_00ccd0f0 : a one-line function - getter
void* FUN_00ccd0f0();

extern void* __cdecl FUN_00aa13e0(unsigned int size);

int* __cdecl FUN_00ccdc30();




void* __cdecl FUN_00aa13e0(unsigned int size);


int* __cdecl FUN_00cce970();

int __cdecl FUN_00cce980();






extern const char g_010c6050[], g_010c604c[];



void* __cdecl FUN_00ccf550();

void* __cdecl FUN_00ccf7b0();

typedef LinkCollection*(* AcquireLinks)(Owner*, unsigned char*);

typedef bool(* CheckRef)(RefObject*, void*);

typedef RefObject*(* FindRef)(RefObject*, void*);


void FUN_00cd3b00(int a, int b, int c, int d);

int __cdecl FUN_00cd3c80();

int* __cdecl FUN_00cd7f20();

void FUN_00cd9ed0(unsigned char* flag, int unused);



















typedef unsigned int(__cdecl* SaveStreamWriteFn)(SaveStream*, const void*, unsigned int, unsigned int*, unsigned int);








CpuOpaque* __cdecl FUN_00cc1280();


void __cdecl FUN_00cc1960(void);



void FUN_00cc7ce0();

void __cdecl FUN_00cc7cf0();

void* FUN_00aa13e0(unsigned int);

void FUN_00aa1460(void*, unsigned int);

void __cdecl FUN_00cc9cd0();

// Forward declaration of the target function
void __cdecl FUN_00cc9ce0();

void __cdecl FUN_00cc9cf0();



extern void(* DAT_00fdf100)(int*);

void FUN_00cd2980();

void FUN_00cd2990();

void __cdecl FUN_00cd29a0();

int FUN_00cd29b0(char* self, int);

void FUN_00cd3b10(int, int, int, int);

int FUN_00cd7d10(int arg0, int arg1);




void __cdecl CollectUnusedIndices(SomeFilter* filter, MyArray<short>& out) throw();




int __cdecl FUN_00cc0850(int owner, int* result);

extern "C" void FUN_00ec5fce(void*, unsigned int, unsigned int, const void*);

extern void* __cdecl FUN_00aa13e0(unsigned int bytes);




void* FUN_00aa13e0(unsigned int size);





static T* FUN_00cc0e00(T* a, T* b);


void caller();

void* __cdecl FUN_00aa13e0(unsigned int size);











extern "C" int(__cdecl* DAT_00fdf1c4)(void*);




void* __cdecl FUN_00aa13e0(unsigned int size);









typedef void*(* TlsGetValueFunc)(int);

void FUN_00cdfe00(FUN_00cdfe00_Object* param1, FUN_00cdfe00_Object* param2);












void FUN_00c7f700(void* a, BestOut* b);
















void __cdecl FUN_00cdfbd0(FUN_00cdfe00_Object* a1, int a2, int a3, ConstraintInput* a4, float a5, float a6);

void __cdecl FUN_00cdfe90(FUN_00cdfe00_Object* pNode, ConstraintInput* pObj);

namespace CE6Memory {
}







struct Vector59
{
    __m128 m_vComponents;
    void operator=(const Vector59& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void mul4f(float s)
    {
        __m128 r = _mm_load_ss(&s);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

struct FUN_00d4f0f0
{
    int unk00;
    unsigned short GetAllocationSize;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Vector59 v0;
    Vector59 v1;
    int unk40;
    float scale;
    int unk48;
    int unk4C;

    void* operator new(std::size_t n)
    {
        S_00cc4b90_Router* r = static_cast<S_00cc4b90_Router*>(::FUN_00c85750());
        FUN_00d4f0f0* b = (FUN_00d4f0f0*)r->heap().AllocateMemoryBlock(n);
        b->GetAllocationSize = (unsigned short)n;
        return b;
    }
    void operator delete(void* p);
    FUN_00d4f0f0();
};

struct Params59
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float factor;
};

struct Owner59
{
    int unk00;
    FUN_00d4f0f0* src;
    void FUN_00cc59c0(FUN_00d4f0f0* node, Params59* params);
};

// @fnv 0x00cc59c0
void Owner59::FUN_00cc59c0(FUN_00d4f0f0* node, Params59* params)
{
    S_00cc4b90_Ctx ctx(0x10);
    FUN_00d4f0f0* s = src;
    if (!node)
    {
        node = new FUN_00d4f0f0();
    }
    node->v0.m_vComponents = s->v0.m_vComponents;
    node->v1.m_vComponents = s->v1.m_vComponents;
    node->scale = s->scale;
    float f = params->factor;
    if (f != 1.0f)
    {
        node->v0.mul4f(f);
        node->v1.mul4f(f);
    }
    reinterpret_cast<::FUN_009ba5f0_shell *>(this)->ReleaseObject((::hkReferencedObject *)(node), (intptr_t)(params));
}

struct Cc9Context
{
    int saved;
    __forceinline Cc9Context(int value)
    {
        saved = (*reinterpret_cast<::S_00cc4b90_Tls *>(&::g_tlsBlock)).ctx;
        (*reinterpret_cast<::S_00cc4b90_Tls *>(&::g_tlsBlock)).ctx = value;
    }
    __forceinline ~Cc9Context()
    {
        (*reinterpret_cast<::S_00cc4b90_Tls *>(&::g_tlsBlock)).ctx = saved;
    }
};

struct ScaleLane
{
    __m128 value;
    __forceinline ScaleLane(float v)
    {
        value = _mm_load_ss(&v);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};

struct Cc9Vector
{
    union
    {
        __m128 value;
        float lane[4];
    };
    __forceinline void multiply(const ScaleLane& factor)
    {
        value = _mm_mul_ps(factor.broadcast(), _mm_load_ps(reinterpret_cast<const float*>(&value)));
    }
    Cc9Vector& operator=(const Cc9Vector& other)
    {
        value = other.value;
        return *this;
    }
};

struct Pair
{
    Cc9Vector a, b;
};

struct Cc9Arr
{
    Pair* data;
    int size;
    int capFlags;
    __forceinline void reserve(S_00cc4b90_Alloc& allocator, int n)
    {
        int cap = capFlags & 0x3fffffff;
        if (cap < n)
        {
            int doubled = cap * 2;
            ::FUN_00c908c0((::SpawnedObject *)(void *)(&allocator), (::SpawnedArray *)(void *)(this), n < doubled ? doubled : n, sizeof(Pair));
        }
    }
    __forceinline void resizeUninitialized(int n)
    {
        reserve(static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap(), n);
        size = n;
    }
};

struct Cc9Src
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Pair* data;
    int size;
};

struct Cc9Arg
{
    unsigned int unk00, unk04, unk08, unk0c;
    float scale;
};

struct Cc9View
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Cc9Arr arr;
    unsigned int unk24, unk28, unk2c, unk30;
};

struct Cc9Owner
{
    unsigned int unk00;
    Cc9Src* src;
    void FUN_00cc9270(FUN_00d53d90* dest, Cc9Arg* arg);
};

// @fnv 0x00cc9270
void Cc9Owner::FUN_00cc9270(FUN_00d53d90* dest, Cc9Arg* arg)
{
    Cc9Context scope(16);
    Cc9Src* src = this->src;
    Cc9View* d;
    if (dest)
    {
        d = reinterpret_cast<Cc9View*>(dest);
    }
    else
    {
        d = reinterpret_cast<Cc9View*>(new FUN_00d53d90());
    }
    int count = src->size;
    Cc9Arr* arr = &d->arr;
    arr->resizeUninitialized(count);
    int n = src->size;
    Pair* s = src->data;
    Pair* dst = arr->data;
    for (int i = 0; i < n; i++)
    {
        dst[i].a = s[i].a;
        dst[i].b = s[i].b;
    }
    float scale = arg->scale;
    if (scale != 1.0f)
    {
        for (int j = 0; j < d->arr.size; j++)
        {
            Pair* p = arr->data;
            p[j].a.multiply(ScaleLane(scale));
            p = arr->data;
            p[j].b.multiply(ScaleLane(scale));
        }
    }
    reinterpret_cast<::FUN_009ba5f0_shell *>((this))->ReleaseObject((::hkReferencedObject *)(::FUN_00d53d90 *)(reinterpret_cast<FUN_00d53d90*>(d)), (int)(arg));
}

struct Cdc90Layout
{
    int unk00;
    int unk04;
    float* unk08;
    int unk0c;
    int unk10;
    float* unk14;
    int unk18;
};

// @fnv 0x00ccdc90
void CdResultObj::FUN_00ccdc90(float value)
{
    Cdc90Layout* self = reinterpret_cast<Cdc90Layout*>(this);

    for (int i = 0; i < self->unk0c; ++i)
    {
        __m128* vector = reinterpret_cast<__m128*>(self->unk08 + i * 4);
        __m128 scalar = _mm_load_ss(&value);
        __m128 multiplier = _mm_shuffle_ps(scalar, scalar, 0);
        *vector = _mm_mul_ps(multiplier, *vector);
    }

    for (int i = 0; i < self->unk18; ++i)
    {
        float* element = self->unk14 + i * 4 + 3;
        *element *= value;
    }
}

class GroundScalar
{
    __m128 lane;

  public:
    GroundScalar()
    {}
    GroundScalar(const __m128& value) : lane(value)
    {}
    GroundScalar(float value)
    {
        lane = _mm_load_ss(&value);
    }
    operator float() const
    {
        float result;
        _mm_store_ss(&result, lane);
        return result;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(lane, lane, 0);
    }
    __forceinline const __m128& quad() const
    {
        return lane;
    }
};

class GroundVector
{
    __m128 lanes;

  public:
    __forceinline GroundVector()
    {}
    __forceinline GroundVector(const GroundVector& value) : lanes(value.lanes)
    {}
    __forceinline GroundVector(const __m128& value) : lanes(value)
    {}
    __forceinline GroundVector(float x, float y, float z, float w = 0.0f)
    {
        set(x, y, z, w);
    }
    __forceinline void operator=(const GroundVector& value)
    {
        lanes = value.lanes;
    }
    __forceinline void operator=(const __m128& value)
    {
        lanes = value;
    }
    __forceinline void set(float x, float y, float z, float w = 0.0f)
    {
        lanes = _mm_setr_ps(x, y, z, w);
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&lanes)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&lanes)[i];
    }
    __forceinline void setSub4(const GroundVector& a, const GroundVector& b)
    {
        lanes = _mm_sub_ps(a.lanes, b.lanes);
    }
    __forceinline GroundScalar dot3(const GroundVector& b) const
    {
        __m128 product = _mm_mul_ps(lanes, b.lanes);
        __m128 y = _mm_shuffle_ps(product, product, 0x55);
        __m128 z = _mm_shuffle_ps(product, product, 0xaa);
        return _mm_add_ss(z, _mm_add_ss(y, product));
    }
    __forceinline GroundScalar length3() const
    {
        __m128 square = dot3(*this).quad();
        return _mm_sqrt_ss(square);
    }
    __forceinline GroundScalar getSimdAt(int i) const
    {
        switch (i)
        {
        case 0:
            return lanes;
        case 1:
            return _mm_shuffle_ps(lanes, lanes, 0x55);
        case 2:
            return _mm_shuffle_ps(lanes, lanes, 0xaa);
        default:
            return _mm_shuffle_ps(lanes, lanes, 0xff);
        }
    }
    __forceinline void mul4(const GroundScalar& factor)
    {
        lanes = _mm_mul_ps(factor.broadcast(), lanes);
    }
    __forceinline void addMul4(const GroundScalar& factor, const GroundVector& value)
    {
        lanes = _mm_add_ps(lanes, _mm_mul_ps(factor.broadcast(), value.lanes));
    }
};

struct SessionPoint
{
    float x, y, z;
};

struct MotionInput
{
    float step;
    GroundVector surface, forward, up, velocity, movement;
    float maxSpeed;
    GroundVector constraint;
};

struct MotionBasis
{
    GroundVector origin, forward;
};

struct FUN_00c6cba0_class;

struct MotionState
{

    virtual void slot0();

    virtual void slot1();

    virtual void slot2();

    virtual void slot3();

    virtual void slot4();

    virtual void slot5();

    virtual void slot6();

    virtual void slot7();

    virtual void enter(FUN_00c6cba0_class* character);
};

struct MotionStateManager
{
};

struct CharacterVtable
{

    void(* slot0)(FUN_00c6cba0_class*);

    void(* slot1)(FUN_00c6cba0_class*);

    void(* slot2)(FUN_00c6cba0_class*);

    void(* slot3)(FUN_00c6cba0_class*);

    void(* slot4)(FUN_00c6cba0_class*);

    void(* slot5)(FUN_00c6cba0_class*);

    void(* slot6)(FUN_00c6cba0_class*);

    void(* slot7)(FUN_00c6cba0_class*);

    void(* slot8)(FUN_00c6cba0_class*);

    void(* slot9)(FUN_00c6cba0_class*);

    void(* slot10)(FUN_00c6cba0_class*);

    void(* slot11)(FUN_00c6cba0_class*);

    void(* slot12)(FUN_00c6cba0_class*);

    void(* slot13)(FUN_00c6cba0_class*);

    void(* slot14)(FUN_00c6cba0_class*);

    void(* slot15)(FUN_00c6cba0_class*);

    void(* slot16)(FUN_00c6cba0_class*);

    void(* slot17)(FUN_00c6cba0_class*);

    void(* slot18)(FUN_00c6cba0_class*);

    void(* slot19)(FUN_00c6cba0_class*);

    void(* slot20)(FUN_00c6cba0_class*);

    void(* slot21)(FUN_00c6cba0_class*);

    void(* slot22)(FUN_00c6cba0_class*);

    void(* slot23)(FUN_00c6cba0_class*);

    void(* slot24)(FUN_00c6cba0_class*);

    void(* slot25)(FUN_00c6cba0_class*);

    void(* slot26)(FUN_00c6cba0_class*);

    void(* slot27)(FUN_00c6cba0_class*);

    void(* slot28)(FUN_00c6cba0_class*);

    void(* slot29)(FUN_00c6cba0_class*);

    void(* slot30)(FUN_00c6cba0_class*);

    void(* slot31)(FUN_00c6cba0_class*);

    void(* slot32)(FUN_00c6cba0_class*);

    void(* slot33)(FUN_00c6cba0_class*);

    void(* slot34)(FUN_00c6cba0_class*);

    void(* slot35)(FUN_00c6cba0_class*);

    void(* slot36)(FUN_00c6cba0_class*);

    MotionBasis*(* getBasis)(FUN_00c6cba0_class*);
};

struct CharacterFlags
{

    unsigned int bits;

    bool active() const
    {
        return (bits >> 8) & 1;
    }

    bool special() const
    {
        return (bits >> 10) & 1;
    }

    bool airborne() const
    {
        return (bits >> 11) & 1;
    }
};

struct FUN_00c6cba0_class
{

    CharacterVtable* vtable;

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

    MotionStateManager* stateManager;

    unsigned int stateId;

    unsigned int unk3f4;

    unsigned int unk3f8;

    unsigned int unk3fc;

    unsigned int unk400;

    unsigned int unk404;

    unsigned int unk408;

    unsigned int unk40c;

    unsigned int unk410;

    CharacterFlags flags;

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

    GroundVector up;

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

    GroundVector constraint;

    unsigned int unk4b0;

    unsigned int unk4b4;

    unsigned int unk4b8;

    unsigned int unk4bc;

    GroundVector forward;

    GroundVector surface;

    unsigned int unk4e0;

    unsigned int unk4e4;

    float timeStep;

    float getTimeStep() const
    {
        return timeStep;
    }

    unsigned int unk4ec;

    GroundVector velocity;

    unsigned int unk500;

    unsigned int unk504;

    unsigned int unk508;

    unsigned int unk50c;

    GroundVector movement;

    unsigned int motionState;

    unsigned int unk524;

    unsigned int unk528;

    unsigned int unk52c;

    unsigned int unk530;

    unsigned int unk534;

    unsigned int unk538;

    unsigned int unk53c;

    unsigned int unk540;

    float height;

    unsigned int unk548;

    float acceleration;

    unsigned int unk550;

    unsigned int unk554;

    unsigned int unk558;

    unsigned int unk55c;

    unsigned int unk560;

    unsigned int unk564;

    float scale;

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

    unsigned int unk594;

    unsigned int unk598;

    unsigned int unk59c;

    unsigned int unk5a0;

    unsigned int unk5a4;

    unsigned int unk5a8;

    unsigned int unk5ac;

    unsigned int unk5b0;

    unsigned int unk5b4;

    unsigned int unk5b8;

    unsigned int unk5bc;

    unsigned int unk5c0;

    unsigned int unk5c4;

    unsigned int unk5c8;

    unsigned int unk5cc;

    unsigned int unk5d0;

    unsigned int unk5d4;

    unsigned int unk5d8;

    unsigned int unk5dc;

    unsigned int unk5e0;

    unsigned int unk5e4;

    unsigned int unk5e8;

    unsigned int unk5ec;

    unsigned int unk5f0;

    unsigned int unk5f4;

    unsigned int unk5f8;

    unsigned int unk5fc;

    unsigned int unk600;

    unsigned int unk604;

    unsigned int unk608;

    unsigned int unk60c;

    bool following;

    unsigned char unk611;

    unsigned char unk612;

    unsigned char unk613;

    unsigned int unk614;

    unsigned int unk618;

    unsigned int unk61c;

    GroundVector goal;


    void SubtractVectors(GroundVector* result);

    void FUN_00c6cba0();

};

extern float DAT_012686e4;

struct MotionController
{

    unsigned int unk00;

    unsigned int unk04;

    bool stopVertical;

    void FUN_00cd4800(FUN_00c6cba0_class* character);
};

// @fnv 0x00cd4800
void MotionController::FUN_00cd4800(FUN_00c6cba0_class* character)
{
    if (!character->flags.active() && !character->following)
    {
        if (stopVertical)
            character->velocity(2) = 0.0f;
        SessionPoint position;
        reinterpret_cast<::VectorSourceB00 *>((character))->FUN_00812b00(&position);
        character->height = position.z;
        character->motionState = 2;
        character->FUN_00c6cba0();
        ((::MotionState *)(reinterpret_cast<::hkpCharacterStateView *>((character->stateManager))->FUN_00cbc510(character->stateId)))->enter(character);
        return;
    }
    if (character->following)
    {
        GroundVector goal = character->goal;
        GroundVector position;
        character->SubtractVectors(&position);
        GroundVector delta;
        delta.setSub4(position, goal);
        float distance = delta.length3();
        if (distance > float(DAT_012686e4 * 64.0) || character->motionState != 11)
            character->following = false;
    }
    MotionInput input;
    input.step = 1.0f;
    input.surface = character->surface;
    input.forward = character->forward;
    input.up = character->up;
    input.velocity = character->velocity;
    if (character->flags.airborne())
        input.movement.set(character->movement.getSimdAt(1), character->movement.getSimdAt(0),
                           character->movement.getSimdAt(2), 0.0f);
    else
        input.movement.set(character->movement.getSimdAt(1), character->movement.getSimdAt(0), 0.0f, 0.0f);
    input.maxSpeed = 500.0f;
    input.constraint = character->constraint;
    ::FUN_00d6aef0(&input, &character->velocity);
    if (!character->flags.airborne())
    {
        character->velocity(2) = input.velocity(2);
        MotionBasis* basis = character->vtable->getBasis(character);
        GroundVector gravity = basis->forward;
        gravity.mul4(GroundScalar(float(character->acceleration * 0.5 * character->scale)));
        character->velocity.addMul4(GroundScalar(character->getTimeStep()), gravity);
    }
    reinterpret_cast<::S_00c6d5c0 *>((character))->FUN_00c6d5c0();
    if (character->motionState != 11 && (character->motionState != 1 || character->flags.special()))
        character->FUN_00c6cba0();
}

namespace N {
}

struct TriangleVector
{
    union
    {
        __m128 m_vComponents;
        float lane[4];
    };

    __forceinline float& operator()(int i)
    {
        return lane[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return lane[i];
    }

    __forceinline void setSub4(const TriangleVector& a, const TriangleVector& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(float s)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, _mm_set_ps1(s));
    }
    __forceinline void setMul4(float s, const TriangleVector& a)
    {
        m_vComponents = _mm_mul_ps(_mm_set_ps1(s), a.m_vComponents);
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setCross(const TriangleVector& a, const TriangleVector& b)
    {
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                                    _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2)),
                                      _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                                    _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9)));
    }
};

template <class T> __forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

struct TriangleMatrix
{
    TriangleVector m_kColumn0;
    TriangleVector m_kColumn1;
    TriangleVector m_kColumn2;
    TriangleVector m_kColumn3;

    __forceinline float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }

    __forceinline void transpose3()
    {
        hkSwap((*this)(0, 1), (*this)(1, 0));
        hkSwap((*this)(0, 2), (*this)(2, 0));
        hkSwap((*this)(1, 2), (*this)(2, 1));
    }
};

struct TriangleInput
{
    TriangleVector m_kPointA;
    TriangleVector m_kPointB;
    TriangleVector m_iThirdValue;
};

struct TriangleWeights
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
    float m_iFourthElementInteger;
};

// @fnv 0x00cd73e0
void FUN_00cd73e0(const TriangleInput* tri, const TriangleWeights* p, TriangleMatrix* out, TriangleVector* nrm)
{
    TriangleVector e0;
    e0.setSub4(tri->m_iThirdValue, tri->m_kPointB);
    TriangleVector e2;
    e2.setSub4(tri->m_kPointA, tri->m_iThirdValue);
    TriangleVector e1;
    e1.setSub4(tri->m_kPointB, tri->m_kPointA);
    __m128 weight = _mm_load_ss(&p->m_w);
    weight = _mm_shuffle_ps(weight, weight, 0);

    TriangleVector n;
    n.setCross(e0, e2);
    n.m_vComponents = _mm_mul_ps(n.m_vComponents, weight);
    nrm->m_vComponents = n.m_vComponents;

    TriangleVector v0;
    v0.setMul4(p->m_uiX, e0);
    TriangleVector v1;
    v1.setMul4(p->m_uiY, e2);
    TriangleVector v2;
    v2.setMul4(p->m_uiZ, e1);

    __m128 normal9 = _mm_shuffle_ps(n.m_vComponents, n.m_vComponents, 0xc9);
    __m128 normal2 = _mm_shuffle_ps(n.m_vComponents, n.m_vComponents, 0xd2);
    out->m_kColumn0.m_vComponents =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), normal2),
                      _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), normal9));
    out->m_kColumn1.m_vComponents =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9), normal2),
                      _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2), normal9));
    out->m_kColumn2.m_vComponents =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9), normal2),
                      _mm_mul_ps(_mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2), normal9));
    out->transpose3();

    out->m_kColumn0(3) = (*nrm)(0);
    out->m_kColumn1(3) = (*nrm)(1);
    out->m_kColumn2(3) = (*nrm)(2);
    out->m_kColumn3.setZero4();
    out->m_kColumn3(0) = -p->m_uiX * p->m_iFourthElementInteger;
}

namespace fnv_00cd8a50 {
namespace N {



}

static __forceinline __m128 broadcast(float f)
{

    __m128 scalar = _mm_load_ss(&f);

    return _mm_shuffle_ps(scalar, scalar, 0);
}





class ScalarLane
{
    __m128 value;

  public:
    ScalarLane()
    {}
    ScalarLane(const __m128& v) : value(v)
    {}
    ScalarLane(float f)
    {
        value = _mm_load_ss(&f);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const __m128& raw() const
    {
        return value;
    }
};
inline ScalarLane operator-(const ScalarLane& s)
{
    return _mm_sub_ss((*reinterpret_cast<__m128 *>(&::DAT_010c7160)), s.raw());
}
class FootVector
{
    __m128 value;

  public:
    FootVector()
    {}
    FootVector(const FootVector& a) : value(a.value)
    {}
    FootVector(const __m128& a) : value(a)
    {}
    operator __m128() const
    {
        return value;
    }
    __forceinline void operator=(const FootVector& a)
    {
        value = a.value;
    }
    __forceinline void operator=(const __m128& a)
    {
        value = a;
    }
    __forceinline void addScaled(const FootVector& base, const FootVector& axis, const ScalarLane& scale)
    {
        value = _mm_add_ps(base.value, _mm_mul_ps(scale.splat(), axis.value));
    }
    __forceinline void subtract(const FootVector& a, const FootVector& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline ScalarLane dot(const FootVector& a) const
    {
        __m128 p = _mm_mul_ps(value, a.value);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline int close3(const FootVector& other) const
    {
        __m128 delta = _mm_and_ps(_mm_sub_ps(value, other.value), (*reinterpret_cast<__m128 *>((void *)&::DAT_01017d10)));
        __m128 limit = _mm_load_ps1(&::AngularDashpotApplyD4DCB0::DAT_01017d00);
        return (_mm_movemask_ps(_mm_cmple_ps(delta, limit)) & 7) == 7;
    }
};
struct RaycastInterface
{
    virtual void unused() = 0;
    virtual HitBool castFilteredRay(const FootVector&, const FootVector&, unsigned int, float&, FootVector&) = 0;
    virtual HitBool RayCast(const FootVector&, const FootVector&, float&, FootVector&) = 0;
};
struct FootCastInput
{
    FootVector transform0, transform1, transform2, transform3, transform4, transform5;
    int enabled;
    RaycastInterface* world;
    float onOffGain, ascendingGain, descendingGain, plantedGain, raisedGain, unlockGain;
    unsigned int collisionFilter;
    bool useFilter;
};
struct FootPlacementSolver
{
    FootVector transform0, transform1, transform2, transform3;
    FootVector up;
    FootVector unk50, unk60;
    float unk70, unk74, unk78, rayUpDistance, rayDownDistance;
    __forceinline bool query(const FootCastInput& c, const FootVector& a, const FootVector& b, float& f,
                             FootVector& n) const
    {
        return c.useFilter ? bool(c.world->castFilteredRay(a, b, c.collisionFilter, f, n))
                           : bool(c.world->RayCast(a, b, f, n));
    }
    bool FUN_00cd8a50(const FootCastInput&, const FootVector&, const FootVector&, FootVector&, FootVector&) const;
};
// @fnv 0x00cd8a50
bool FootPlacementSolver::FUN_00cd8a50(const FootCastInput& context, const FootVector& start, const FootVector& end,
                                       FootVector& position, FootVector& normal) const
{
    const float r = rayUpDistance;
    const float h = rayDownDistance;
    const float length = h + r;
    HitBool startHit = false;
    float startFraction = ::DAT_0104da48;
    FootVector startNormal;
    {
        FootVector low, high;
        low.addScaled(start, up, -h);
        high.addScaled(start, up, r);
        startHit = query(context, high, low, startFraction, startNormal);
    }
    HitBool endHit = false;
    float endFraction = ::DAT_0104da48;
    FootVector endNormal;
    if (!end.close3(start))
    {
        FootVector low, high;
        low.addScaled(end, up, -h);
        high.addScaled(end, up, r);
        float queryFraction;
        endHit = query(context, high, low, queryFraction, endNormal);
        if (endHit)
        {
            const float projection = endNormal.dot(up);
            if (projection <= 0.0f)
                endHit = false;
            else
            {
                FootVector ray, hit;
                ray.subtract(low, high);
                hit.addScaled(high, ray, queryFraction);
                const float planeDistance = -hit.dot(endNormal);
                FootVector from;
                from.addScaled(start, up, r);
                const float denominator = -length * projection;
                const float numerator = -(float(endNormal.dot(from)) + planeDistance);
                const float fraction = numerator / denominator;
                endFraction = fraction;
            }
        }
    }
    if (!startHit && !endHit)
        return false;
    float chosenFraction;
    if (!startHit || startFraction > endFraction)
    {
        chosenFraction = endFraction;
        normal = endNormal;
    }
    else
    {
        chosenFraction = startFraction;
        normal = startNormal;
    }
    const float displacement = chosenFraction * length - r;
    position.addScaled(start, up, -displacement);
    return true;
}
}

// namespace fnv_00cd8a50

extern "C" unsigned __int64 __rdtsc();

extern char DAT_010cb7b8[];

struct Vec4
{
    union
    {
        __m128 value;
        float lane[4];
    };
    Vec4& operator=(const Vec4& v)
    {
        value = v.value;
        return *this;
    }
    void zero()
    {
        __m128 t = _mm_load_ss(&::DAT_01012068);
        value = _mm_shuffle_ps(t, t, 0);
    }
};

struct Property
{
    unsigned short type, unk02;
    int unk04, unk08, unk0c;
    unsigned short size, unk12;
    int unk14, unk18, unk1c;
    Vec4 value20, value30;
    Property()
    {
        type = 0x18;
        size = 0x40;
    }
    static void* operator new(std::size_t n)
    {
        return static_cast<S_00cc4b90_Router*>(::FUN_00c85750())->heap().AllocateMemoryBlock(n);
    }
};

struct ObjectData
{
    int unk00, unk04, unk08, unk0c, unk10;
    int index;
};

struct Obj40
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
    virtual ObjectData* v40();
};

struct ObjArg
{
    Obj40* p;
    ObjArg(Obj40* q) : p(q)
    {}
};

// @fnv 0x00cdf960
void FUN_00cdf960(Obj40* a, int b, ObjArg c, const Vec4* d)
{
    ObjectData* p = a->v40();
    if (p)
    {
        Obj40* other = c.p;
        _ReadWriteBarrier();
        other->v18();
        TimerBuffer* timer = (TimerBuffer*)TlsGetValue((*reinterpret_cast<int *>(&::DAT_0126835c)));
        TimerEvent* entry = timer->current;
        if (entry < timer->end)
        {
            entry->name = DAT_010cb7b8;
            _ReadWriteBarrier();
            volatile unsigned stamp = (unsigned)__rdtsc();
            entry->ticks = stamp;
            timer->current = entry + 1;
        }
        Property* q = ((::Property *)(::FindModifierConstraintAtom((::hkpConstraintInstance *)(p), 0x18)));
        if (!q)
        {
            Property* created = new Property;
            ::FUN_00d27960((::hkpConstraintInstance *)(p), (*(::hkpConstraintOwner *)(other)), (::hkpModifierConstraintAtom *)(created));
            if (b == p->index)
            {
                created->value20 = *d;
                created->value30.zero();
            }
            else
            {
                created->value20.zero();
                created->value30 = *d;
            }
        }
        else
        {
            if (b == p->index)
                q->value20 = *d;
            else
                q->value30 = *d;
            if (q->value20.lane[3] == 0.0f && q->value30.lane[3] == 0.0f)
            {
                q->value20.lane[3] = 1.0f;
                q->value30.lane[3] = 1.0f;
            }
        }
        timer = (TimerBuffer*)TlsGetValue((*reinterpret_cast<int *>(&::DAT_0126835c)));
        entry = timer->current;
        if (entry < timer->end)
        {
            entry->name = DAT_010c41f8;
            _ReadWriteBarrier();
            volatile unsigned stamp = (unsigned)__rdtsc();
            entry->ticks = stamp;
            timer->current = entry + 1;
        }
    }
}

namespace fnv_00cd44e0 {
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
inline float altScalar(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}
extern const float DAT_01011d78;
inline float laneXn(const __m128& source, float& scratch)
{
    _mm_store_ss(&scratch, source);
    return scratch;
}
inline float laneZn(const __m128& source, float& scratch)
{
    _mm_store_ss(&scratch, _mm_shuffle_ps(source, source, 0xaa));
    return scratch;
}

inline __m128 factors(__m128 x, float y, float z)
{
    return _mm_set_ps(DAT_01011d78, z, y, _mm_cvtss_f32(x));
}
inline bool flag(unsigned int f, unsigned int shift)
{
    return ((unsigned char)(f >> shift) & 1) != 0;
}
class SwimScale
{
    __m128 value;

  public:
    SwimScale(float a)
    {
        value = _mm_load_ss(&a);
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
__forceinline void applyVelocity(__m128& velocity, float acceleration, const __m128& direction, float factor)
{
    SwimScale a(factor);
    __m128 g = _mm_mul_ps(a.splat(), direction);
    SwimScale b(acceleration);
    velocity = _mm_add_ps(velocity, _mm_mul_ps(b.splat(), g));
}
inline float laneX(const __m128& source, volatile float& scratch)
{
    _mm_store_ss(const_cast<float*>(&scratch), source);
    return scratch;
}
inline float laneZ(const __m128& source, volatile float& scratch)
{
    __m128 v = source;
    _mm_store_ss(const_cast<float*>(&scratch), _mm_shuffle_ps(v, v, 0xaa));
    return scratch;
}
struct MotionState;
struct MotionBasis
{
    __m128 x, y, z;
};
struct MotionState
{
    void** methods;
    MotionBasis* GetBasis()
    {
        typedef MotionBasis*(* Fn)(MotionState*);
        return reinterpret_cast<Fn>(methods[37])(this);
    }
    unsigned int field004;
    MotionState* field008;
    unsigned int field00c;
    unsigned int field010;
    unsigned int field014;
    unsigned int field018;
    unsigned int field01c;
    unsigned int field020;
    unsigned int field024;
    unsigned int field028;
    unsigned int field02c;
    unsigned int field030;
    unsigned int field034;
    unsigned int field038;
    unsigned int field03c;
    unsigned int field040;
    unsigned int field044;
    unsigned int field048;
    unsigned int field04c;
    unsigned int field050;
    unsigned int field054;
    unsigned int field058;
    unsigned int field05c;
    unsigned int field060;
    unsigned int field064;
    unsigned int field068;
    unsigned int field06c;
    unsigned int field070;
    unsigned int field074;
    unsigned int field078;
    unsigned int field07c;
    unsigned int field080;
    unsigned int field084;
    unsigned int field088;
    unsigned int field08c;
    unsigned int field090;
    unsigned int field094;
    unsigned int field098;
    unsigned int field09c;
    unsigned int field0a0;
    unsigned int field0a4;
    unsigned int field0a8;
    unsigned int field0ac;
    unsigned int field0b0;
    unsigned int field0b4;
    unsigned int field0b8;
    unsigned int field0bc;
    unsigned int field0c0;
    unsigned int field0c4;
    unsigned int field0c8;
    unsigned int field0cc;
    unsigned int field0d0;
    unsigned int field0d4;
    unsigned int field0d8;
    unsigned int field0dc;
    unsigned int field0e0;
    unsigned int field0e4;
    unsigned int field0e8;
    unsigned int field0ec;
    unsigned int field0f0;
    unsigned int field0f4;
    unsigned int field0f8;
    unsigned int field0fc;
    unsigned int field100;
    unsigned int field104;
    unsigned int field108;
    unsigned int field10c;
    unsigned int field110;
    unsigned int field114;
    unsigned int field118;
    unsigned int field11c;
    unsigned int field120;
    unsigned int field124;
    unsigned int field128;
    unsigned int field12c;
    unsigned int field130;
    unsigned int field134;
    unsigned int field138;
    unsigned int field13c;
    unsigned int field140;
    unsigned int field144;
    unsigned int field148;
    unsigned int field14c;
    unsigned int field150;
    unsigned int field154;
    unsigned int field158;
    unsigned int field15c;
    unsigned int field160;
    unsigned int field164;
    unsigned int field168;
    unsigned int field16c;
    unsigned int field170;
    unsigned int field174;
    unsigned int field178;
    unsigned int field17c;
    unsigned int field180;
    unsigned int field184;
    unsigned int field188;
    unsigned int field18c;
    unsigned int field190;
    unsigned int field194;
    unsigned int field198;
    unsigned int field19c;
    unsigned int field1a0;
    unsigned int field1a4;
    unsigned int field1a8;
    unsigned int field1ac;
    unsigned int field1b0;
    unsigned int field1b4;
    unsigned int field1b8;
    unsigned int field1bc;
    unsigned int field1c0;
    unsigned int field1c4;
    unsigned int field1c8;
    unsigned int field1cc;
    unsigned int field1d0;
    unsigned int field1d4;
    unsigned int field1d8;
    unsigned int field1dc;
    unsigned int field1e0;
    unsigned int field1e4;
    unsigned int field1e8;
    unsigned int field1ec;
    unsigned int field1f0;
    unsigned int field1f4;
    unsigned int field1f8;
    unsigned int field1fc;
    unsigned int field200;
    unsigned int field204;
    unsigned int field208;
    unsigned int field20c;
    unsigned int field210;
    unsigned int field214;
    unsigned int field218;
    unsigned int field21c;
    unsigned int field220;
    unsigned int field224;
    unsigned int field228;
    unsigned int field22c;
    unsigned int field230;
    unsigned int field234;
    unsigned int field238;
    unsigned int field23c;
    unsigned int field240;
    unsigned int field244;
    unsigned int field248;
    unsigned int field24c;
    unsigned int field250;
    unsigned int field254;
    unsigned int field258;
    unsigned int field25c;
    unsigned int field260;
    unsigned int field264;
    unsigned int field268;
    unsigned int field26c;
    unsigned int field270;
    unsigned int field274;
    unsigned int field278;
    unsigned int field27c;
    unsigned int field280;
    unsigned int field284;
    unsigned int field288;
    unsigned int field28c;
    unsigned int field290;
    unsigned int field294;
    unsigned int field298;
    unsigned int field29c;
    unsigned int field2a0;
    unsigned int field2a4;
    unsigned int field2a8;
    unsigned int field2ac;
    unsigned int field2b0;
    unsigned int field2b4;
    unsigned int field2b8;
    unsigned int field2bc;
    unsigned int field2c0;
    unsigned int field2c4;
    unsigned int field2c8;
    unsigned int field2cc;
    unsigned int field2d0;
    unsigned int field2d4;
    unsigned int field2d8;
    unsigned int field2dc;
    unsigned int field2e0;
    unsigned int field2e4;
    unsigned int field2e8;
    unsigned int field2ec;
    unsigned int field2f0;
    unsigned int field2f4;
    unsigned int field2f8;
    unsigned int field2fc;
    unsigned int field300;
    unsigned int field304;
    unsigned int field308;
    unsigned int field30c;
    unsigned int field310;
    unsigned int field314;
    unsigned int field318;
    unsigned int field31c;
    unsigned int field320;
    unsigned int field324;
    unsigned int field328;
    unsigned int field32c;
    unsigned int field330;
    unsigned int field334;
    unsigned int field338;
    unsigned int field33c;
    unsigned int field340;
    unsigned int field344;
    unsigned int field348;
    unsigned int field34c;
    unsigned int field350;
    unsigned int field354;
    unsigned int field358;
    unsigned int field35c;
    unsigned int field360;
    unsigned int field364;
    unsigned int field368;
    unsigned int field36c;
    unsigned int field370;
    unsigned int field374;
    unsigned int field378;
    unsigned int field37c;
    unsigned int field380;
    unsigned int field384;
    unsigned int field388;
    unsigned int field38c;
    unsigned int field390;
    unsigned int field394;
    unsigned int field398;
    unsigned int field39c;
    unsigned int field3a0;
    unsigned int field3a4;
    unsigned int field3a8;
    unsigned int field3ac;
    unsigned int field3b0;
    unsigned int field3b4;
    unsigned int field3b8;
    unsigned int field3bc;
    unsigned int field3c0;
    unsigned int field3c4;
    unsigned int field3c8;
    unsigned int field3cc;
    unsigned int field3d0;
    unsigned int field3d4;
    unsigned int field3d8;
    unsigned int field3dc;
    unsigned int field3e0;
    unsigned int field3e4;
    unsigned int field3e8;
    unsigned int field3ec;
    unsigned int field3f0;
    unsigned int field3f4;
    unsigned int field3f8;
    unsigned int field3fc;
    unsigned int field400;
    unsigned int field404;
    unsigned int field408;
    unsigned int field40c;
    unsigned int field410;
    unsigned int field414;
    unsigned int field418;
    unsigned int field41c;
    unsigned int field420;
    unsigned int field424;
    unsigned int field428;
    unsigned int field42c;
    unsigned int field430;
    unsigned int field434;
    unsigned int field438;
    unsigned int field43c;
    unsigned int field440;
    unsigned int field444;
    unsigned int field448;
    unsigned int field44c;
    __m128 field450;
    unsigned int field460;
    unsigned int field464;
    unsigned int field468;
    unsigned int field46c;
    unsigned int field470;
    unsigned int field474;
    unsigned int field478;
    unsigned int field47c;
    unsigned int field480;
    unsigned int field484;
    unsigned int field488;
    unsigned int field48c;
    unsigned int field490;
    unsigned int field494;
    unsigned int field498;
    unsigned int field49c;
    __m128 field4a0;
    unsigned int field4b0;
    unsigned int field4b4;
    unsigned int field4b8;
    unsigned int field4bc;
    __m128 field4c0;
    __m128 field4d0;
    unsigned int field4e0;
    unsigned int field4e4;
    float field4e8;
    unsigned int field4ec;
    __m128 field4f0;
    unsigned int field500;
    unsigned int field504;
    unsigned int field508;
    unsigned int field50c;
    __m128 field510;
    unsigned int field520;
    unsigned int field524;
    unsigned int field528;
    unsigned int field52c;
    unsigned int field530;
    unsigned int field534;
    unsigned int field538;
    float field53c;
    unsigned int field540;
    unsigned int field544;
    unsigned int field548;
    float field54c;
    unsigned int field550;
    unsigned int field554;
    unsigned int field558;
    unsigned int field55c;
    float field560;
    float field564;
    unsigned int field568;
    unsigned int field56c;
    unsigned int field570;
    unsigned int field574;
    float field578;
    unsigned int field57c;
    float getScale() const
    {
        return field54c;
    }
    float getStep() const
    {
        return field4e8;
    }
};

extern float DAT_012686e0;
__forceinline void applyVelocityP(__m128& velocity, MotionState* o, const __m128& direction, float factor)
{
    SwimScale a(factor);
    __m128 g = _mm_mul_ps(a.splat(), direction);
    SwimScale b(o->getStep());
    velocity = _mm_add_ps(velocity, _mm_mul_ps(b.splat(), g));
}
__forceinline void applyVelocityN(__m128& velocity, MotionState* o, const __m128& direction, float factor)
{
    SwimScale a(factor);
    __m128 g = _mm_mul_ps(a.splat(), direction);
    SwimScale b(-o->getStep());
    velocity = _mm_add_ps(velocity, _mm_mul_ps(b.splat(), g));
}

struct Snapshot
{
    float weight;
    __m128 position, rotation, previous, velocity, factors;
    float scale;
    __m128 extra;
};
// @fnv 0x00cd44e0
__declspec(noinline) void FUN_00cd44e0(MotionState* object)
{
    Snapshot state;
    state.weight = 1.0f;
    state.position = object->field4d0;
    __m128 rotation = object->field4c0;
    state.rotation = rotation;
    state.velocity = object->field4f0;
    {
        const __m128* p = &object->field510;
        const __m128* q = reinterpret_cast<const __m128*>(&object->field500);
        float scratch;
        _mm_store_ss(&scratch, _mm_shuffle_ps(object->field510, object->field510, 0xaa));
        float z = scratch;
        _mm_store_ss(&scratch, *p);
        float x = scratch;
        float y;
        _mm_store_ss(&y, _mm_shuffle_ps(q[1], q[1], 0x55));
        state.factors = _mm_setr_ps(y, x, z, 0.0f);
    }
    state.scale = 100.0f;
    state.extra = object->field4a0;
    unsigned int f = *(unsigned int*)&object->field414;
    bool initialSupported = flag(f, 8) && flag(f, 8);
    if (initialSupported)
        state.previous = object->field450;
    else
        state.previous = rotation;
    __m128* __restrict velocity = &object->field4f0;
    ::FUN_00d6aef0((const ::MotionInput *)(void *)(&state), velocity);
    __m128* parent = (__m128*)&DAT_01267e30;
    MotionState* parentObject = object->field008;
    if (parentObject)
    {
        reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>((object))->FUN_00c89720();
        parent = ((__m128 *)(reinterpret_cast<::CpuObject *>((parentObject))->FUN_00cac910()));
        reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>((object))->FUN_00c89720();
    }
    float height = altScalar(_mm_shuffle_ps(*parent, *parent, 0xaa)) - object->field578;
    if (object->field560 >= 0.5f)
        height += 0.5 * object->field564 * object->field560;
    object->GetBasis();
    __m128 direction = object->GetBasis()->y;
    object->GetBasis();
    {
        unsigned int* pf = (unsigned int*)&object->field414;
        *pf |= 0x400;
    }
    if (height > object->field53c)
    {
        if (object->field520 == 1)
        {
            reinterpret_cast<::FUN_00c6cba0_class *>((object))->FUN_00c6cba0();
            goto done;
        }
        if (altScalar(_mm_shuffle_ps(*velocity, *velocity, 0xaa)) > 0.0f)
        {
            object->field4f0[2] = 0.0f;
        }
        else
        {
            _ReadWriteBarrier();
        }
    }
    else if (object->field560 < 0.5f)
    {
        if (object->field520 == 1 && flag(object->field414, 10))
        {
            reinterpret_cast<::FUN_00c6cba0_class *>((object))->FUN_00c6cba0();
            goto done;
        }
        if (!(height < object->field53c - float(DAT_012686e0 * 10.0)))
            goto done;
        applyVelocityN(*velocity, object, direction, object->getScale());
        goto done;
    }
    else
    {
        if (object->field54c == 1.0f)
            goto done;
        unsigned int flags = object->field414;
        if (flag(flags, 8) || flag(flags, 9))
            goto done;
    }
    applyVelocityP(*velocity, object, direction, object->getScale());
done:
    reinterpret_cast<::S_00c6d5c0 *>((object))->FUN_00c6d5c0();
    if (object->field520 == 0)
        reinterpret_cast<::FUN_00c6cba0_class *>((object))->FUN_00c6cba0();
}
}




void FUN_00cdf270(char* self, int, char* arg);








struct MeshMetadata654
{
    unsigned int a, b;
    static void* operator new(std::size_t size)
    {
        char* p = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa3e40(size + 16);
        unsigned char offset = (unsigned char)(16 - ((unsigned char)(unsigned int)p & 15));
        p += offset;
        p[-1] = offset;
        return p;
    }
    MeshMetadata654(unsigned int x, unsigned int y)
    {
        b = y;
        a = x;
    }
};

// @fnv 0x00ccc440
void Mesh654::FUN_00ccc440(BCC9B80Stream& stream)
{
    TlsFlagGuard guard;
    BCC9B80LoadBinary(stream, vertexCount);
    vertices = new float[vertexCount * 3];
    BCC9B80BinaryStreamLoad(*stream.m_pUnderlyingStream, vertices, vertexCount * 3);
    BCC9B80LoadBinary(stream, triangleCount);
    triangles = new unsigned short[triangleCount * 3];
    BCC9B80BinaryStreamLoad(*stream.m_pUnderlyingStream, triangles, triangleCount * 3);
    unsigned int a, b;
    BCC9B80LoadBinary(stream, b);
    BCC9B80LoadBinary(stream, a);
    metadata = new MeshMetadata654(b, a);
}

struct hkVector4Stub
{
    __m128 m_vComponents;
};

static inline float Dot3(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    float r;
    _mm_store_ss(&r, s);
    return r;
}

struct Metrics
{
  public:
    float a, b, c, d;
};

struct Triangle
{
    __m128 p0, p1, p2;
    Metrics __cdecl FUN_00cd7160(...) const;
};

// @fnv 0x00cd7160
Metrics __cdecl Triangle::FUN_00cd7160(...) const
{
    Metrics result;
    float raw_d00, raw_d11, raw_d01;
    // Establish the scalar first-use order before storing the dot products.
    (void)raw_d11;
    (void)raw_d00;
    (void)raw_d01;
    __m128 e0 = _mm_sub_ps(p0, p1);
    __m128 e1 = _mm_sub_ps(p2, p1);
    {
        __m128 p = _mm_mul_ps(e0, e0);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        _mm_store_ss(&raw_d00, s);
    }
    {
        __m128 p = _mm_mul_ps(e1, e1);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        _mm_store_ss(&raw_d11, s);
    }
    {
        __m128 p = _mm_mul_ps(e1, e0);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        _mm_store_ss(&raw_d01, s);
    }
    float d11 = raw_d11;
    float d00 = raw_d00;
    float d01 = raw_d01;
    __m128 a = _mm_shuffle_ps(e1, e1, 0xd2);
    __m128 b = _mm_shuffle_ps(e0, e0, 0xc9);
    __m128 c = _mm_shuffle_ps(e1, e1, 0xc9);
    __m128 d = _mm_shuffle_ps(e0, e0, 0xd2);
    __m128 n = _mm_sub_ps(_mm_mul_ps(a, b), _mm_mul_ps(c, d));
    float det = float(float(d00 * d11) - float(d01 * d01));
    float inv = float(1.0f / det);
    result.a = d00 * inv;
    result.b = d11 * inv;
    result.c = d01 * inv;
    __m128 n2 = _mm_mul_ps(n, n);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(n2, n2, 0x55), n2);
    s = _mm_add_ss(_mm_shuffle_ps(n2, n2, 0xaa), s);
    s = _mm_sqrt_ss(s);
    float len;
    _mm_store_ss(&len, s);
    result.d = 1.0f / len;
    return result;
}

#include "generated/data/staging/blk_00cc0000_o2.inc"
#include "generated/data/staging/blk_00cc0000_o2_rtm_variant.inc"
