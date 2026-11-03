
// src/staging/blk_00c40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <windows.h>
#include <new>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/B44F890Collection.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSWin32TaskletManager.h"
#include "fnv/decl/B_004b6100.h"
#include "fnv/decl/Builder.h"
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_0044e010_class.h"
#include "fnv/decl/FUN_0045bb20_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00559a70_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0069dee0_class.h"
#include "fnv/decl/FUN_0078d200_cls.h"
#include "fnv/decl/FUN_008c77c0_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5e930.h"
#include "fnv/decl/FUN_00a5ea70_t.h"
#include "fnv/decl/FUN_00a699d0_Class.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/FUN_00a89760_cls.h"
#include "fnv/decl/FUN_00a89ae0_shell.h"
#include "fnv/decl/FUN_00a99c40_shell.h"
#include "fnv/decl/FUN_00a99d70_shell.h"
#include "fnv/decl/FUN_00aa54a0_s.h"
#include "fnv/decl/FUN_00b00ec0.h"
#include "fnv/decl/FUN_00c1c280_cls.h"
#include "fnv/decl/FUN_00c1c390.h"
#include "fnv/decl/FUN_00c1ce70_shell.h"
#include "fnv/decl/FUN_00c25d40_shell.h"
#include "fnv/decl/FUN_00c25de0_shell.h"
#include "fnv/decl/FUN_00c32fb0_cls.h"
#include "fnv/decl/FUN_00c347d0_cls.h"
#include "fnv/decl/FUN_00c3fa70_cls.h"
#include "fnv/decl/FUN_00c5db90.h"
#include "fnv/decl/FrustumPlanes__Planes.h"
#include "fnv/decl/GraphicsRenderer.h"
#include "fnv/decl/HashTableBase.h"
#include "fnv/decl/LinkObjectA5.h"
#include "fnv/decl/List250.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/MyIsEqual.h"
#include "fnv/decl/MyOwner.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiNodeEq.h"
#include "fnv/decl/NiObject_00a7b3d0.h"
#include "fnv/decl/NiRenderer.h"
#include "fnv/decl/NodeA5E8.h"
#include "fnv/decl/PaletteFieldFlags.h"
#include "fnv/decl/ParticleModifierBinary.h"
#include "fnv/decl/PositionState.h"
#include "fnv/decl/RectangleClip.h"
#include "fnv/decl/SHStub.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_00a59e00.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/S_00a742a0.h"
#include "fnv/decl/S_00c1c300.h"
#include "fnv/decl/SettingS.h"
#include "fnv/decl/Sphere.h"
#include "fnv/decl/StrArr.h"
#include "fnv/decl/TrailSystem.h"
#include "fnv/decl/X.h"
#include "fnv/decl/fnv_00a5dd40__FUN_00a5dd40_shell.h"
#include "fnv/decl/fnv_00a74690__FUN_00a74690_shell.h"
#include "fnv/decl/fnv_00a9a4e0__Cls_00a9a4e0.h"
#include "fnv/decl/fnv_00c1be60__NiBaseC1B.h"
#include "fnv/decl/fnv_00c34350__RectangleClip.h"
#include "fnv/decl/fnv_00c344c0__SSNode.h"
#include "fnv/decl/fnv_00c3f8c0__FUN_00c3f8c0.h"
#include "fnv/decl/sa5e9d0__Node.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00a26000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a3d000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a5e000.h"
#include "fnv/symbols_00a64000.h"
#include "fnv/symbols_00a74000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a9a000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b00000.h"
#include "fnv/symbols_00c33000.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_00c46000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00c50000.h"
#include "fnv/symbols_00c51000.h"
#include "fnv/symbols_00c54000.h"
#include "fnv/symbols_00c55000.h"
#include "fnv/symbols_00c5f000.h"
#include "fnv/symbols_00c61000.h"
#include "fnv/symbols_00c65000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01034000.h"
#include "fnv/symbols_010a0000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_010c1000.h"
#include "fnv/symbols_010c2000.h"
#include "fnv/symbols_010c3000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_01203000.h"
#include "fnv/symbols_01204000.h"
#include <cstddef>
#include <cstdio>
#include "fnv/decl/B00C20Pool.h"
#include "fnv/decl/BSShaderLightingProperty.h"
#include "fnv/decl/BSThread.h"
#include "fnv/decl/ControllerOwner.h"
#include "fnv/decl/FUN_0042fc00_shell.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b0260_shell.h"
#include "fnv/decl/FUN_005efdd0_class.h"
#include "fnv/decl/FUN_00691820_arr.h"
#include "fnv/decl/FUN_00692290_class.h"
#include "fnv/decl/FUN_0084d310_class.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00a53c90_cls.h"
#include "fnv/decl/FUN_00a54060_class.h"
#include "fnv/decl/FUN_00a54110.h"
#include "fnv/decl/FUN_00a5bca0_shell.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00a745c0_This.h"
#include "fnv/decl/FUN_00b00ae0_class.h"
#include "fnv/decl/FUN_00b00b40_cls.h"
#include "fnv/decl/FUN_00b00bc0_cls.h"
#include "fnv/decl/FUN_00c35980_Class.h"
#include "fnv/decl/FUN_00c3f750_Class.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/NiObject_b.h"
#include "fnv/decl/NiStreamLinkIDSetShell.h"
#include "fnv/decl/NiTimeController.h"
#include "fnv/decl/Node2.h"
#include "fnv/decl/Owner62B.h"
#include "fnv/decl/ParticleModifier.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S654.h"
#include "fnv/decl/S_00a5eb20_Arr.h"
#include "fnv/decl/Tbl00b57f20.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008c74b0__FUN_008c74b0_shell.h"
#include "fnv/decl/fnv_00a5e780__NodeStandIn.h"
#include "fnv/decl/fnv_00a5ed10__ChildNode.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_00c42000.h"
#include "fnv/symbols_00c44000.h"
#include "fnv/symbols_00c52000.h"
#include "fnv/symbols_00c5c000.h"
#include "fnv/symbols_00c5d000.h"
#include "fnv/symbols_00c5e000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_0106a000.h"
#include "fnv/symbols_01083000.h"
#include "fnv/symbols_0109a000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01272000.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_00c4a000.h"
#include "fnv/symbols_00c58000.h"
#include "../../include/layout_support.h"
class NiBoolInterpolator;

// Glue functions for the shared non-template NiTPointerListBase methods; layout_support.h makes NiTPointerListBase a template here.
void ClearPointerList(void* list);
void RemovePointerListPos(void* list, void*& position);

extern int DAT_010c1670;

struct FUN_00c40990_Class {
    void FUN_00c40990();
};

// @fnv 0x00c40990
void FUN_00c40990_Class::FUN_00c40990()
{
    *(void**)this = (void*)&DAT_010c1670;
}

struct FUN_00c42b60_class {
    int a;
    int b;
    void FUN_00c42b60();
};



struct FUN_00c42da0_Class {
    virtual void vfn_0000();
    virtual void vfn_0004();
};

// @fnv 0x00c42da0
int FUN_00c42da0(FUN_00c42da0_Class* p)
{
    ::EnsureArenaAllocated((::ArenaOwner *)(void *)((char*)p + 0x24));
    p->vfn_0004();
    return 0;
}

struct FUN_00c430a0_class
{
    int FUN_00c430a0(int);
};

// @fnv 0x00c430a0
int FUN_00c430a0_class::FUN_00c430a0(int)
{
    return (intptr_t)this;
}

struct FUN_00c430b0_class {
    void FUN_00c430b0(int a1, int a2);
};

// @fnv 0x00c430b0
void FUN_00c430b0_class::FUN_00c430b0(int a1, int a2)
{
    reinterpret_cast<::FUN_00a99c40_shell *>(this)->FUN_00a99c40((::NiBinaryExtraData *)(a1), (::CloningProcess *)(a2));
}

struct NiStream;
struct NiIntegerExtraData { void LoadBinary(NiStream&); };
struct FUN_00c430d0 : public NiIntegerExtraData { void LoadBinary(NiStream&); };
// @fnv 0x00c430d0
void FUN_00c430d0::LoadBinary(NiStream& stream)
{
    NiIntegerExtraData::LoadBinary(stream);
}

struct NiAVObject;
struct NiBinaryExtraData {
    void FUN_00c430f0(NiAVObject* a);
};
// @fnv 0x00c430f0
void NiBinaryExtraData::FUN_00c430f0(NiAVObject* apObject)
{
    ::FUN_00a9af00();
}

namespace fnv_00c43110 {
struct NiBinaryExtraData {
    bool FUN_00c43110(void* arg);
};
// Returns the negation of FUN_00a89ae0(arg).
// @fnv 0x00c43110
bool NiBinaryExtraData::FUN_00c43110(void* apData)
{
    return !reinterpret_cast<::FUN_00a89ae0_shell *>(this)->FUN_00a89ae0((intptr_t)(apData));
}
}  // namespace fnv_00c43110

struct FUN_00c43140_StandIn {
    void FUN_00c43140(int a);
};

// @fnv 0x00c43140
void FUN_00c43140_StandIn::FUN_00c43140(int aiValue)
{
    reinterpret_cast<::fnv_00a9a4e0::Cls_00a9a4e0 *>(this)->FUN_00a9a4e0((*(::fnv_00a9a4e0::NiStream *)(aiValue)));
}

struct NiStringExtraData {
    char* m_p;
    char IsEqual(const char*);
    char FUN_00c43160(const char* other);
};

char NiStringExtraData::IsEqual(const char* other)
{
    return 0;
}

// @fnv 0x00c43160
char NiStringExtraData::FUN_00c43160(const char* other)
{
    char result = ((char)(reinterpret_cast<::S_00a742a0 *>(this)->Equals((::S_00a742a0 *)(other))));
    return result;
}

struct NiFixedString;
class NiExtraData;
class NiFixedString;
class NiUpdateData;
struct NiAVObject {  void FUN_00c43470(); public:
    void EnsureWorldBound();
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
    void SetName(const NiFixedString&);
    void UpdateWorldData(::NiUpdateData &);
};
// @fnv 0x00c43470
void NiAVObject::FUN_00c43470()
{
    ::AssignFixedString((char *)this, (intptr_t)&(*DAT_01202ddc), {});
}


struct FUN_00c43650_Class {
    void* FUN_00c43650();
};

// @fnv 0x00c43650
void* FUN_00c43650_Class::FUN_00c43650()
{
    return &(*reinterpret_cast<void * *>(&::g_01202de0));
}

class CloningProcess;
class NiUpdateData;
struct NiNode {
public:
    void CopyMemberData(::NiNode *, ::CloningProcess &);
public:
    void UpdateDownwardPass(::NiUpdateData &, unsigned int);
public:
    void UpdateSelectedDownwardPass(::NiUpdateData &, unsigned int);
};

struct FUN_00c43900_class {
    void FUN_00c43900(void* apParam);
};

// @fnv 0x00c43900
void FUN_00c43900_class::FUN_00c43900(void* apParam)
{
    reinterpret_cast<::sa5e9d0::Node *>((((NiNode*)this)))->ReadChildListFromStream((::sa5e9d0::Stream *)(apParam));
}


struct FUN_00c43cf0_Class {
    void* FUN_00c43cf0();
};

// @fnv 0x00c43cf0
void* FUN_00c43cf0_Class::FUN_00c43cf0()
{
    return &(*reinterpret_cast<void * *>(&::g_01202de8));
}

struct FUN_00c43d60_cls {
    char pad[0x108];
    int m_pSelf;
    char InitSelfPointer(int a);
};

// @fnv 0x00c43d60
char FUN_00c43d60_cls::InitSelfPointer(int aiUnused)
{
    m_pSelf = (intptr_t)this;
    return 1;
}


struct FUN_00c44940_Class {
    void FUN_00c44940();
};

// @fnv 0x00c44940
void FUN_00c44940_Class::FUN_00c44940()
{
    ::FUN_00c80240((::ArenaManagedOwner *)(void *)(this + 0x50));
}

struct FUN_00c44960_class {
    void FUN_00c44960();
};

struct FUN_00c44cb0_class {
    void* m0;
    void* m1;
    void* m2;
    void CallStoredCallback();
};
// @fnv 0x00c44960
void FUN_00c44960_class::FUN_00c44960()
{
    reinterpret_cast<::FUN_00c44cb0_class *>((((FUN_00c44960_class**)((char*)this + 0x4c))[0]))->CallStoredCallback();
}

// @fnv 0x00c44cb0
void FUN_00c44cb0_class::CallStoredCallback()
{
    ((void (*)(void*))m1)(m2);
}

struct FUN_00c44e20 {
    ~FUN_00c44e20();
};
// @fnv 0x00c44e20
FUN_00c44e20::~FUN_00c44e20()
{
    *reinterpret_cast<int**>(this) = &DAT_010178bc;
    reinterpret_cast<class ::FUN_00a5e930 *>(this)->FUN_00a5e930::~FUN_00a5e930();
}

struct FUN_00c452a0_Class {
    void FUN_00c452a0(int a);
};

// @fnv 0x00c452a0
void FUN_00c452a0_Class::FUN_00c452a0(int aiValue)
{
    reinterpret_cast<::sa5e9d0::Node *>(this)->ReadChildListFromStream((::sa5e9d0::Stream *)(aiValue));
}

struct NiStream;

struct FUN_00a5e5b0_helper {
};

struct FUN_00c452c0_class {
    unsigned char FUN_00c452c0(NiStream*);
};

// @fnv 0x00c452c0
unsigned char FUN_00c452c0_class::FUN_00c452c0(NiStream* stream)
{
    if (!((unsigned char)(::fnv_00a5e5b0::RegisterChildStreamables((::NiNode *)(((FUN_00a5e5b0_helper*)this)), (std::intptr_t)(stream), *(::fnv_00a5e5b0::NiStream *)nullptr))))
        return 0;
    return 1;
}


struct FUN_00c457d0_Class
{
    char const* const* FUN_00c457d0();
};

// @fnv 0x00c457d0
char const* const* FUN_00c457d0_Class::FUN_00c457d0()
{
    return &(*reinterpret_cast<const char *const *>(&::g_01202e0c));
}

extern unsigned short DAT_01202e2c;

// @fnv 0x00c45ab0
bool FUN_00c45ab0()
{
    if (DAT_01202e2c)
        return false;
    return true;
}

struct NiStream;
class CloningProcess;
class NiStream;
struct NiPSysModifier {
    void LinkObject(NiStream&);
    void FUN_00c467f0(NiStream& stream);
public:
    void CopyMemberData(::NiPSysModifier *, ::CloningProcess &);
public:
    void LoadBinary(::NiStream &);
};
// @fnv 0x00c467f0
void NiPSysModifier::FUN_00c467f0(NiStream& stream)
{
    LinkObject(stream);
}

struct FUN_00c46810_Class {
    void FUN_00c46810(int);
};

// @fnv 0x00c46810
void FUN_00c46810_Class::FUN_00c46810(int aiValue)
{
    reinterpret_cast<::X *>(this)->FUN_00c31670((*(::NiStream *)(aiValue)));
}

namespace fnv_00c46ca0 {
struct NiStream {
    void ResetStreamState();
};

struct NiNode {
    void FUN_00c46ca0(NiStream& stream);
};

// @fnv 0x00c46ca0
void NiNode::FUN_00c46ca0(NiStream& stream)
{
    reinterpret_cast<::fnv_00a5dd40::FUN_00a5dd40_shell *>(this)->FUN_00a5dd40((::NiStream *)&(stream));
    stream.ResetStreamState();
}
}  // namespace fnv_00c46ca0


struct FUN_00c47650_Class {
    void* FUN_00c47650();
};

// @fnv 0x00c47650
void* FUN_00c47650_Class::FUN_00c47650()
{
    return &(*reinterpret_cast<void * *>(&::g_01202e74));
}

struct P03MM
{
    void* Allocate(unsigned int);
    void* AllocateScaled(unsigned int count);
};

// @fnv 0x00c4a860
void* P03MM::AllocateScaled(unsigned int count)
{
    void* result = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(count * 100);
    return result;
}

namespace fnv_00c4a890 {
struct MemoryManager { void Deallocate(void*); };
struct FUN_00c4a890 { void Deallocate(void* p); };
// @fnv 0x00c4a890
void FUN_00c4a890::Deallocate(void* apMemory)
{
    (*reinterpret_cast<::fnv_00c4a890::MemoryManager *>(&::g_memoryManager)).Deallocate(apMemory);
}
}  // namespace fnv_00c4a890

namespace fnv_00c4a900 {
struct P03MM {
    void* FUN_00c4a900(unsigned int a);
};

// @fnv 0x00c4a900
void* P03MM::FUN_00c4a900(unsigned int a)
{
    void* r = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00c4a900::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(a * 12);
    return r;
}
}  // namespace fnv_00c4a900

namespace fnv_00c4a930 {
struct MemoryManager { void* Reallocate(void* p, unsigned int size); };

struct FUN_00c4a930_Class {
    void* AllocateArray(void* oldPtr, unsigned int count);
};

// @fnv 0x00c4a930
void* FUN_00c4a930_Class::AllocateArray(void* oldPtr, unsigned int count)
{
    return (*reinterpret_cast<::fnv_00c4a930::MemoryManager *>(&::g_memoryManager)).Reallocate(oldPtr, count * 0xc);
}
}  // namespace fnv_00c4a930

struct FUN_00c4aae0_class {
    void FUN_00c4aae0(intptr_t a, int b);
};

struct FUN_00c4ab40_class {
    void FUN_00c4ab40(int);
};

struct FUN_00c452a0_class {
    void FUN_00c452a0(int a);
};

void FUN_00c452a0_class::FUN_00c452a0(int a)
{
}

struct FUN_00c4ab60_class {
    void FUN_00c4ab60(int a);
};

// @fnv 0x00c4ab60
void FUN_00c4ab60_class::FUN_00c4ab60(int a)
{
    reinterpret_cast<::FUN_00c452a0_Class *>((((FUN_00c452a0_class*)this)))->FUN_00c452a0(a);
}

struct FUN_00c4abb0_class {
    void FUN_00c4abb0(int a);
};

struct FUN_00c4abd0_class {
    char FUN_00c4abd0(int a1);
};


struct FUN_00c4ac90_Class {
    void* FUN_00c4ac90();
};

// @fnv 0x00c4ac90
void* FUN_00c4ac90_Class::FUN_00c4ac90()
{
    return &(*reinterpret_cast<void * *>(&::g_01202e7c));
}

struct FUN_00c4ad40_class {
    void FUN_00c4ad40(intptr_t a, int b);
};

extern "C" void __cdecl FUN_00c45220(int);

struct FUN_00c4ada0_Class {
    void FUN_00c4ada0(int a);
};

// @fnv 0x00c4ada0
void FUN_00c4ada0_Class::FUN_00c4ada0(int a)
{
    ((void (*)(void*, int))FUN_00c45220)(this, a);
}

namespace fnv_00c4adc0 {
struct FUN_00c4adc0_class {
    void FUN_00c4adc0(int);
};

struct FUN_00c452a0_class {
};

// @fnv 0x00c4adc0
void FUN_00c4adc0_class::FUN_00c4adc0(int arg)
{
    reinterpret_cast<::FUN_00c452a0_Class *>((((FUN_00c452a0_class*)this)))->FUN_00c452a0(arg);
}
}  // namespace fnv_00c4adc0

struct FUN_00c4ade0_class {
    unsigned char FUN_00c4ade0(int);
};
// @fnv 0x00c4ade0
unsigned char FUN_00c4ade0_class::FUN_00c4ade0(int a)
{
    if (!reinterpret_cast<::FUN_00c452c0_class *>(this)->FUN_00c452c0((::NiStream *)(a)))
        return 0;
    return 1;
}

struct FUN_00c4ae10_Class {
    void FUN_00c4ae10(int a);
};

struct FUN_00c4ae30_class {
    unsigned char FUN_00c4ae30(unsigned int a);
};


struct FUN_00c4aef0_Class {
    int* FUN_00c4aef0();
};

// @fnv 0x00c4aef0
int* FUN_00c4aef0_Class::FUN_00c4aef0()
{
    return &(*reinterpret_cast<int *>(&::g_01202e84));
}

struct FUN_00c4afa0_class {
    void FUN_00c4afa0(intptr_t a, int b);
};

struct FUN_00c4b000_class {
    void FUN_00c4b000(int a);
};

struct FUN_00c4b020_Class {
    void FUN_00c4b020(int a);
};

// @fnv 0x00c4b020
void FUN_00c4b020_Class::FUN_00c4b020(int aiValue)
{
    reinterpret_cast<::FUN_00c452a0_Class *>(this)->FUN_00c452a0(aiValue);
}

namespace fnv_00c4b040 {
struct FUN_00c452c0_class {
    unsigned char FUN_00c452c0(int);
    char IsNonZero(int a);
};

unsigned char FUN_00c452c0_class::FUN_00c452c0(int a) { return (unsigned char)a; }

// Returns 1 when FUN_00c452c0(a) is non-zero, otherwise returns 0.
// @fnv 0x00c4b040
char FUN_00c452c0_class::IsNonZero(int aiValue)
{
    if (!reinterpret_cast<::FUN_00c452c0_class *>(this)->FUN_00c452c0((::NiStream *)(aiValue)))
        return 0;
    return 1;
}
}  // namespace fnv_00c4b040

struct FUN_00c452f0_cls {
    void FUN_00c452f0(int a1);
};
// @fnv 0x00c4abb0
void FUN_00c4abb0_class::FUN_00c4abb0(int a)
{
    reinterpret_cast<::FUN_00c452f0_cls *>(this)->FUN_00c452f0(a);
}
// @fnv 0x00c4ae10
void FUN_00c4ae10_Class::FUN_00c4ae10(int a)
{
    reinterpret_cast<::FUN_00c452f0_cls *>(this)->FUN_00c452f0(a);
}

void FUN_00c452f0_cls::FUN_00c452f0(int a1)
{
}

struct FUN_00c4b070_cls {
    void FUN_00c4b070(int a1);
};

// @fnv 0x00c4b070
void FUN_00c4b070_cls::FUN_00c4b070(int a1)
{
    ((FUN_00c452f0_cls*)this)->FUN_00c452f0(a1);
}

struct GlobalObject_00a7b610;

struct FUN_00c4b210_Class {
    GlobalObject_00a7b610* FUN_00c4b210();
};

// @fnv 0x00c4b210
GlobalObject_00a7b610* FUN_00c4b210_Class::FUN_00c4b210()
{
    return &::g_01202e8c;
}

struct NiNode;
struct NiNode_Helper {  };
struct FUN_00c51550 : NiNode_Helper { void Copy(NiNode* a, void* b); };
// @fnv 0x00c51550
void FUN_00c51550::Copy(NiNode* apNode, void* b)
{
    reinterpret_cast<::NiNode *>(this)->CopyMemberData(apNode, (*(::CloningProcess *)(b)));
}

struct FUN_00c51570_Class {
    void* FUN_00a5ea70(void* arg);
    void* FUN_00c51570(void* arg);
};

// @fnv 0x00c51570
void* FUN_00c51570_Class::FUN_00c51570(void* arg)
{
    return FUN_00a5ea70(arg);
}

struct BaseT {
    ~BaseT();
};

struct FUN_00c516d0 : BaseT {
    void DoIt();
};

// @fnv 0x00c516d0
void FUN_00c516d0::DoIt()
{
    reinterpret_cast<::FUN_00b00ec0 *>(this)->FUN_00b00ec0::~FUN_00b00ec0();
}


struct FUN_00c516f0_Class {
    void* FUN_00c516f0();
};

// @fnv 0x00c516f0
void* FUN_00c516f0_Class::FUN_00c516f0()
{
    return &(*reinterpret_cast<void * *>(&::g_01203110));
}


struct FUN_00c52870_class
{
    const char* const* FUN_00c52870();
};

// @fnv 0x00c52870
const char* const* FUN_00c52870_class::FUN_00c52870()
{
    return &(*reinterpret_cast<const char *const *>(&::g_01203180));
}

struct FUN_00c54dc0_class {
    int FUN_00c54dc0(int);
};
// @fnv 0x00c54dc0
int FUN_00c54dc0_class::FUN_00c54dc0(int)
{
    return (intptr_t)this;
}

struct NiStream;
class NiStream;
struct NiExtraData {
    void LinkObject(NiStream&);
public:
    void LoadBinary(::NiStream &);
};
struct BSBound : NiExtraData {
    void FUN_00c54e70(NiStream& stream);
};
// @fnv 0x00c54e70
void BSBound::FUN_00c54e70(NiStream& stream)
{
    NiExtraData::LinkObject(stream);
}

struct FUN_00a7b290_shell {
    int FUN_00c54e90(int arg);
};

// Returns the logical negation of FUN_00a7b290(arg).
// @fnv 0x00c54e90
int FUN_00a7b290_shell::FUN_00c54e90(int arg)
{
    return !reinterpret_cast<::MyOwner *>(this)->FUN_00a7b290((*(::NiStream *)(arg)));
}


struct FUN_00c55320_Class {
    void* FUN_00c55320();
};

// @fnv 0x00c55320
void* FUN_00c55320_Class::FUN_00c55320()
{
    return &(*reinterpret_cast<void * *>(&::g_012031e8));
}

struct FUN_00c5b5d0_class {
    unsigned int FUN_00c5b5d0();
};

// @fnv 0x00c5b5d0
unsigned int FUN_00c5b5d0_class::FUN_00c5b5d0()
{
    return *(unsigned short*)((char*)this + 0x48);
}

struct NiStream;

class CloningProcess;
class NiStream;
struct NiPSysEmitterCtlr {
    void LinkObject(NiStream&);
public:
    void CopyMemberData(::NiPSysEmitterCtlr *, ::CloningProcess &);
public:
    void ProcessClone(::CloningProcess &);
public:
    void LoadBinary(::NiStream &);
};

struct BSPSysMultiTargetEmitterCtlr : NiPSysEmitterCtlr {
    void FUN_00c5cc90(NiStream& stream);
};

// @fnv 0x00c5cc90
void BSPSysMultiTargetEmitterCtlr::FUN_00c5cc90(NiStream& stream)
{
    NiPSysEmitterCtlr::LinkObject(stream);
}

struct NiStream;
struct FUN_00c1be10_shell {
    bool RegisterEmitterInterpolatorStreamables(NiStream&);
    char FUN_00c5ccb0(NiStream&);
};
// @fnv 0x00c5ccb0
char FUN_00c1be10_shell::FUN_00c5ccb0(NiStream& stream)
{
    if (!RegisterEmitterInterpolatorStreamables(stream))
        return 0;
    return 1;
}


struct FUN_00c5cea0_Class {
    int* FUN_00c5cea0();
};

// @fnv 0x00c5cea0
int* FUN_00c5cea0_Class::FUN_00c5cea0()
{
    return &(*reinterpret_cast<int *>(&::g_01203340));
}

extern int DAT_010c2e7c;

struct FUN_00a744a0 {
    void* vtbl;
    FUN_00a744a0();
};

FUN_00a744a0::FUN_00a744a0()
{
}

struct FUN_00c5ceb0 : public FUN_00a744a0 {
    FUN_00c5ceb0();
};

// @fnv 0x00c5ceb0
FUN_00c5ceb0::FUN_00c5ceb0()
{
    vtbl = &DAT_010c2e7c;
}

extern "C" void FUN_00a89760(void*);
extern int DAT_010c2e7c;

struct FUN_00c5cfb0 {
    virtual void vfn();
    void FUN_00a89760();
    ~FUN_00c5cfb0();
};

// @fnv 0x00c5cfb0
FUN_00c5cfb0::~FUN_00c5cfb0()
{
    reinterpret_cast<::FUN_00a89760_cls *>(this)->FUN_00a89760_cls::~FUN_00a89760_cls();
}

struct StrArr;
struct Caller74690 {
    void ForwardTo74690(StrArr* p);
};

// @fnv 0x00c5d0f0
void Caller74690::ForwardTo74690(StrArr* pStrArr)
{
    reinterpret_cast<::fnv_00a74690::FUN_00a74690_shell *>(this)->FUN_00a74690((::fnv_00a74690::StrArr *)(pStrArr));
}


struct FUN_00c5d2a0_Class {
    void* FUN_00c5d2a0();
};

// @fnv 0x00c5d2a0
void* FUN_00c5d2a0_Class::FUN_00c5d2a0()
{
    return &(*reinterpret_cast<void * *>(&::g_01203348));
}

struct FUN_00c5dcb0_class {
    void SetShortAtOffsetBA(short param);
};

// @fnv 0x00c5dcb0
void FUN_00c5dcb0_class::SetShortAtOffsetBA(short asValue)
{
    *(short*)((char*)this + 0xba) = asValue;
}


struct FUN_00c5ec90_class
{
    void* GetGlobalPtr();
};

// @fnv 0x00c5ec90
void* FUN_00c5ec90_class::GetGlobalPtr()
{
    return &(*reinterpret_cast<void * *>(&::g_0120436c));
}

struct GlobalObject_00a7b610 {
    GlobalObject_00a7b610* GetGlobalInstance();
};


// @fnv 0x00c5f560
GlobalObject_00a7b610* GlobalObject_00a7b610::GetGlobalInstance()
{
    return &::g_01204378;
}

namespace fnv_00c5f570 {

struct NiNode {
    NiNode(unsigned short);
};

struct FUN_00c5f570 : NiNode {
    FUN_00c5f570();
};

// @fnv 0x00c5f570
FUN_00c5f570::FUN_00c5f570() : NiNode(0)
{
    *reinterpret_cast<int**>(this) = &::DAT_010c31a4;
}
}  // namespace fnv_00c5f570

struct Unk_00a5e930 {
};
struct FUN_00c5faa0 {
    void FUN_00a5e930();
};
// @fnv 0x00c5faa0
void FUN_00c5faa0::FUN_00a5e930()
{
    *reinterpret_cast<int**>(this) = &DAT_010c31a4;
    reinterpret_cast<class ::FUN_00a5e930 *>((reinterpret_cast<Unk_00a5e930*>(this)))->FUN_00a5e930::~FUN_00a5e930();
}


struct FUN_00c5fc60_class {
    const char* const* FUN_00c5fc60();
};

// @fnv 0x00c5fc60
const char* const* FUN_00c5fc60_class::FUN_00c5fc60()
{
    return &(*reinterpret_cast<const char *const *>(&::g_01204380));
}

extern void* DAT_010c32c4;
struct NiPSysPositionModifier { NiPSysPositionModifier(); };
struct FUN_00c5fd30 : NiPSysPositionModifier {
    FUN_00c5fd30();
};
NiPSysPositionModifier::NiPSysPositionModifier() {}
// @fnv 0x00c5fd30
FUN_00c5fd30::FUN_00c5fd30()
{
    *(void**)this = &DAT_010c32c4;
}

namespace fnv_00c5fec0 {
struct CloningProcess { };
struct NiPSysModifier {
    void FUN_00c5fec0(NiPSysModifier* apDest, CloningProcess& apProcess);
};
// @fnv 0x00c5fec0
void NiPSysModifier::FUN_00c5fec0(NiPSysModifier* apDest, CloningProcess& apProcess)
{
    reinterpret_cast<::NiPSysModifier *>((this))->CopyMemberData((::NiPSysModifier *)(apDest), (::CloningProcess &)(apProcess));
}
}  // namespace fnv_00c5fec0

namespace fnv_00c5ff90 {
struct NiStream;

struct NiPSysModifier {
    virtual void LinkObject(NiStream&);
};

struct NiPSysModifierSub : NiPSysModifier {
    void FUN_00c5ff90(NiStream& stream);
};

// @fnv 0x00c5ff90
void NiPSysModifierSub::FUN_00c5ff90(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
}
}  // namespace fnv_00c5ff90

struct FUN_00c5ffb0_Class {
    void FUN_00c5ffb0(int param);
};

// @fnv 0x00c5ffb0
void FUN_00c5ffb0_Class::FUN_00c5ffb0(int param)
{
    reinterpret_cast<::X *>(this)->FUN_00c31670((*(::NiStream *)(param)));
}

void NiFreeAlias(void*);
struct FUN_00c5eb60_Class {
    int m0;
    int m1;
    void ResetAndFreeAlias();
};
// Stores the address of DAT_010c30b8 into m0, then frees m1 through NiFreeAlias.
// @fnv 0x00c5eb60
void FUN_00c5eb60_Class::ResetAndFreeAlias()
{
    m0 = (intptr_t)&DAT_010c30b8;
    void* alias = (void*)m1;
    NiFreeAlias(alias);
}

void __cdecl FUN_00c3f8c0();
class ScrapHeapBuffer;
struct MemoryManager { void Deallocate(void*); public:
    void *Reallocate(void *, unsigned int);
public:
    ::ScrapHeapBuffer *GetGeneralAllocator();
};
struct FUN_00c40930_Class {
    void FUN_00c3f8c0();
    void* FUN_00c40930(unsigned int flags);
};
namespace fnv_00c40960 {
struct MemoryManager { void Deallocate(void*); };
struct FUN_00c40960_Class {
    void* FUN_00c40960(int flags);
};
// @fnv 0x00c40960
void* FUN_00c40960_Class::FUN_00c40960(int flags)
{
    reinterpret_cast<::FUN_00c3fa70_cls *>(this)->FUN_00c3fa70_cls::~FUN_00c3fa70_cls();
    if (flags & 1)
        reinterpret_cast<MemoryManager*>(&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))->Deallocate(this);
    return this;
}
}  // namespace fnv_00c40960

namespace fnv_00c409b0 {
struct FUN_00c409e0_Class {
};
struct MemoryManager {
    void Deallocate(void*);
};
struct FUN_00c409b0_Class {
    void* FUN_00c409b0(unsigned int flags);
};
}  // namespace fnv_00c409b0

namespace fnv_00c40a70 {
struct MemoryManager { void Deallocate(void*); };
struct FUN_00c40a70_Class {
    void* FUN_00c40a70(unsigned int flags);
};
}  // namespace fnv_00c40a70

namespace fnv_00c40b40 {
struct MemoryManager {
    void Deallocate(void*);
};
struct FUN_00c40b40_class {
    int vtbl;
    FUN_00c40b40_class* FUN_00c40b40(int a);
};
// Sets the vtable pointer, and if bit 0 of a is set, deallocates this object through g_memoryManager; returns this.
// @fnv 0x00c40b40
FUN_00c40b40_class* FUN_00c40b40_class::FUN_00c40b40(int a)
{
    vtbl = (intptr_t)&DAT_010c1670;
    if (a & 1)
        reinterpret_cast<MemoryManager*>(&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))->Deallocate(this);
    return this;
}
}  // namespace fnv_00c40b40

void __cdecl FUN_00c43070(void*);
struct FUN_00c43620_Class {
    void FUN_00c43070();
    void* FUN_00c43620(unsigned int flags);
};
struct FUN_00c43850_Class {
    void FUN_00c43850(void* dst, unsigned int size);
};
// @fnv 0x00c43da0
void __cdecl CopyMainNameFromPath(int param_1, char* pDest)
{
    const char* name = "MAIN";
    if (pDest) {
        const char* path = *(const char**)((char*)param_1 + 8);
        if (path) {
            const char* colon = std::strchr((char *)(path), ':');
            if (colon) name = colon + 1;
        }
        fnv::crt::strcpy_s(pDest, 0x40, name);
    }
}

struct FUN_00c448f0_Class {
    char pad[0x24];
    int unk24;
    char pad28[0x28];
    int m50;
    int m54;
    int m58;
    void FUN_00c448f0();
};
// Zeroes m50 and m54, copies the int at offset 0x24 into m58, then calls EnsureArenaAllocated with &m50.
// @fnv 0x00c448f0
void FUN_00c448f0_Class::FUN_00c448f0()
{
    m50 = 0;
    m54 = 0;
    int tmp = this->unk24;
    m58 = tmp;
    ::EnsureArenaAllocated((::ArenaOwner *)(void *)(&m50));
}

struct FUN_00c44cd0_class {
    void FUN_00c44cd0();
};
struct FUN_00c44c40_class {
    void FUN_00c44c40(int a1, int a2);
};
namespace fnv_00c44df0 {
struct MemoryManager { void Deallocate(void*); };
struct FUN_00c44df0_class {
    void* FUN_00c44df0(unsigned int flags);
};
// @fnv 0x00c44df0
void* FUN_00c44df0_class::FUN_00c44df0(unsigned int flags)
{
    reinterpret_cast<::FUN_008c77c0_Class *>(this)->FUN_008c77c0_Class::~FUN_008c77c0_Class();
    if (flags & 1)
        (*reinterpret_cast<::fnv_00c44df0::MemoryManager *>(&::g_memoryManager)).Deallocate(this);
    return this;
}
}  // namespace fnv_00c44df0

struct FUN_00c455a0_Class {
};
struct FUN_00c5fb60_Class {
};
struct FUN_00c451b0_class {
    void CopyStateTo(intptr_t a, intptr_t b);
};
extern int DAT_011af758;
// @fnv 0x00c45820
void FUN_00c45820(int value)
{
    DAT_011af758 = value;
}

// @fnv 0x00c45ad0
int FUN_00c45ad0()
{
    return DAT_01202e2c;
}

extern unsigned short DAT_01202e2e;

// @fnv 0x00c45b10
void __cdecl FUN_00c45b10(unsigned short value)
{
    DAT_01202e2e = value;
}

struct NiPSysModifier;
struct CloningProcess;
struct NiPSysModifier_StandIn : public NiPSysModifier {
    char pad[0x18];
    float m_f;
    void CopyModifier(NiPSysModifier_StandIn* dst, CloningProcess& proc);
};
// @fnv 0x00c46700
void NiPSysModifier_StandIn::CopyModifier(NiPSysModifier_StandIn* dst, CloningProcess& proc)
{
    reinterpret_cast<::NiPSysModifier *>((this))->CopyMemberData(dst, proc);
    float f = this->m_f;
    dst->m_f = f;
}

struct SStream;
struct SObj;
struct FUN_00c46830_class {
    void Load(NiStream* stream);
};
// Calls FUN_00c31950 on the stream, then CallAnimCallback with the stream and the object at this+0x18.
// @fnv 0x00c46830
void FUN_00c46830_class::Load(NiStream* stream)
{
    reinterpret_cast<::ParticleModifierBinary *>(this)->FUN_00c31950((*(::OutputStream *)(stream)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)(reinterpret_cast<SStream*>(stream)), (intptr_t)(reinterpret_cast<SObj*>(this + 0x18)));
}

struct FUN_00c4a640_class {
    void FUN_00c4a640(char* dst, char* src, unsigned int count);
};
// @fnv 0x00c4a640
void FUN_00c4a640_class::FUN_00c4a640(char* dst, char* src, unsigned int count)
{
    if (count <= 0)
        return;
    if (dst < src) {
        for (unsigned int i = 0; i < count; i++)
            std::memmove(dst + i * 100, src + i * 100, 100);
    } else if (dst > src) {
        for (int i = (int)count - 1; i >= 0; i--)
            std::memmove(dst + i * 100, src + i * 100, 100);
    }
}

namespace fnv_00c4a990 {
struct MemoryManager {
    void Deallocate(void*);
};
void __cdecl FUN_00c4a8e0(void*);
struct FUN_00c4a990_class {
    void FUN_00c4a8e0();
    void* FUN_00c4a990(unsigned int flags);
};
// @fnv 0x00c4a990
void* FUN_00c4a990_class::FUN_00c4a990(unsigned int flags)
{
    FUN_00c4a8e0();
    if (flags & 1)
        ((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))->Deallocate(this);
    return this;
}
}  // namespace fnv_00c4a990

struct NiTPrimitiveArray_unsigned_int_
{
    void AddFirstEmpty(unsigned int&);
};
struct FUN_00c4ab00_Class {
    void FUN_00c4ab00(int a);
};
struct FUN_00c4f2d0_class {
    void FUN_00c4f2d0();
};
// Decrements the counter at offset 0xbc, reads the item at that index from the array at 0x94, and stores it at 0x90.
// @fnv 0x00c4f2d0
void FUN_00c4f2d0_class::FUN_00c4f2d0()
{
    *(int*)((char*)this + 0xbc) = *(int*)((char*)this + 0xbc) - 1;
    int item = *(int*)((char*)this + 0x94 + *(int*)((char*)this + 0xbc) * 4);
    *(int*)((char*)this + 0x90) = item;
}

struct FUN_00c5dcd0_Class {
};
struct FUN_00c50f30_Class {
};
struct FUN_00c505c0_Class {
    void FUN_00c505c0(int a, void* b);
};
struct FUN_00c50f30_class {
    int GetEntryValue(int a);
};

// @fnv 0x00c50f30
int FUN_00c50f30_class::GetEntryValue(int aiIndex)
{
    int r = 0;
    if (aiIndex < *(unsigned int*)(this + 0xb0)) {
        int v = ((int*)*(void**)(this + 0xac))[aiIndex];
        if (v != -1) {
            int* p = (int*)(*(void**)(this + 0xa0)) + v;
            int t = *p;
            r = t;
        }
    }
    return r;
}

extern int DAT_0106c814;
extern int DAT_010c256c;
struct FUN_00c51640_Class {
    const char* s;
    int i;
    unsigned char b;
    int d;
    unsigned char c;
    int p;
    void* FUN_00c51640();
};
// Initializes the object's fields: clears the byte at offset 4, the int at offset 8, sets the byte at 0xc to 1, and clears the int at 0x10.
// @fnv 0x00c51640
void* FUN_00c51640_Class::FUN_00c51640()
{
    s = (const char*)&DAT_0106c814;
    *(unsigned char*)&this->i = 0;
    s = "@yl";
    *(int*)((char*)this + 8) = 0;
    *(unsigned char*)&this->d = 1;
    int* q = (int*)((char*)this + 0x10);
    *q = 0;
    s = (const char*)&DAT_010c256c;
    return this;
}

struct FUN_00878690_shell
{
    void FUN_00c51df0();
};
struct FUN_00c52830_class {
    void* FUN_00c52830(unsigned int flags);
};

namespace fnv_00c54d70 {
struct MemoryManager { void Deallocate(void*); };
struct FUN_00c54d70_class {
    int* vtbl;
    void* data;
    FUN_00c54d70_class* FUN_00c54d70(unsigned int flags);
};
// Sets the vtable pointer, deallocates the data pointer, and if flags has bit 0 set, deallocates this object.
// @fnv 0x00c54d70
FUN_00c54d70_class* FUN_00c54d70_class::FUN_00c54d70(unsigned int flags)
{
    vtbl = &::FNV_vtbl_NiTArrayBase;
    void* tmp2 = data;
    void* tmp = tmp2;
    (*reinterpret_cast<::fnv_00c54d70::MemoryManager *>(&::g_memoryManager)).Deallocate(tmp);
    if (flags & 1)
        (*reinterpret_cast<::fnv_00c54d70::MemoryManager *>(&::g_memoryManager)).Deallocate(this);
    return this;
}
}  // namespace fnv_00c54d70

struct NiStream;
class NiStream;
struct NiColor {
    void SaveBinary(NiStream&);
public:
    void LoadBinary(::NiStream &);
};
struct NiExtraDataSaveHelper {
};
struct FUN_00c54ec0_class {
    void FUN_00c54ec0(NiStream& stream);
};
// Saves the extra data helper and two NiColor members at offsets 0xc and 0x18 to the stream.
// @fnv 0x00c54ec0
void FUN_00c54ec0_class::FUN_00c54ec0(NiStream& stream)
{
    reinterpret_cast<::FUN_00a7b2c0_shell *>((((NiExtraDataSaveHelper*)this)))->FUN_00a7b2c0(stream);
    ((NiColor*)((char*)this + 0xc))->SaveBinary(stream);
    ((NiColor*)((char*)this + 0x18))->SaveBinary(stream);
}

struct FUN_00a7b300_shell { void FUN_00a7b300(); };
struct FUN_00c55330_class {
    void* FUN_00c55330(unsigned int flags);
};
// @fnv 0x00c55330
void* FUN_00c55330_class::FUN_00c55330(unsigned int flags)
{
    reinterpret_cast<FUN_00a7b300_shell*>(this)->FUN_00a7b300();
    if (flags & 1)
        operator delete(this, 0x24);
    return this;
}

namespace fnv_00c5bae0 {

struct FUN_00c5ac00_class {
    void* FUN_00c5bae0(unsigned int flags);
};

}  // namespace fnv_00c5bae0

extern int DAT_010c2d54;
struct FUN_00c1c280_class {
};
struct FUN_00c5c3c0_class : FUN_00c1c280_class {
    int InitWithParams(int a, int b, unsigned short c);
};
// @fnv 0x00c5c3c0
int FUN_00c5c3c0_class::InitWithParams(int aiArg, int aiValue, unsigned short ausValue)
{
    new ((void *)this) ::FUN_00c1c280_cls((const char *)(aiArg));
    *(void**)this = (void*)&DAT_010c2d54;
    *(int*)(this + 0x5c) = aiValue;
    *(unsigned short*)(this + 0x60) = ausValue;
    return (intptr_t)this;
}

extern int DAT_010c2d54;
struct FUN_00c1c390_Class {
};
struct FUN_00c5c400_Class : FUN_00c1c390_Class {
    void* vtbl;
    char pad[0x5c - 4];
    int m_0x5c;
    unsigned short m_0x60;
    FUN_00c5c400_Class* FUN_00c5c400();
};
// @fnv 0x00c5c400
FUN_00c5c400_Class* FUN_00c5c400_Class::FUN_00c5c400()
{
    new ((void *)this) ::FUN_00c1c390(); vtbl = (void*)&DAT_010c2d54; m_0x5c = 0; m_0x60 = 0; return this; }

struct NiStream;
struct S_00c1be40 {
    void FUN_00c1be40(NiStream& stream);
};
struct FUN_00c5cce0_Class {
    char pad[0x5c];
    int m_0x5c;
    void FUN_00c5cce0(NiStream& stream);
};
// @fnv 0x00c5cce0
void FUN_00c5cce0_Class::FUN_00c5cce0(NiStream& stream)
{
    ((S_00c1be40*)this)->FUN_00c1be40(stream);
    ::fnv_00a303a0::FUN_00a303a0((::fnv_00a303a0::Stream *)&(stream), (unsigned short*)((char*)this + 0x60));
    ((void (*)(NiStream*, int))*((void***)*(void**)&stream + 12))(&stream, m_0x5c);
}

struct FUN_00c1be60_StandIn {
    char FUN_00c5cd20(void* other);
};
// @fnv 0x00c5cd20
char FUN_00c1be60_StandIn::FUN_00c5cd20(void* other)
{
    if (!((unsigned char)(reinterpret_cast<::fnv_00c1be60::NiBaseC1B *>(this)->FUN_00c1be60((::fnv_00c1be60::NiObjectC1B *)(other)))))
        return 0;
    void* p = other;
    if (*(int*)((char*)this + 0x5c) == *(int*)((char*)p + 0x5c) &&
        *(unsigned short*)((char*)this + 0x60) == *(unsigned short*)((char*)p + 0x60))
        return 1;
    else
        return 0;
}

namespace fnv_00c5ce10 {
struct FUN_00c5ce10_Class {
    void Constructor();
    void* FUN_00c5ce10(unsigned int a);
};
// Calls Constructor on this, deletes this with size 0x64 when bit 0 of a is set, and returns this.
// @fnv 0x00c5ce10
void* FUN_00c5ce10_Class::FUN_00c5ce10(unsigned int uiFlags)
{
    this->Constructor();
    if (uiFlags & 1)
        operator delete(this, 0x64);
    return this;
}
}  // namespace fnv_00c5ce10

struct FUN_00c5ced0 : FUN_00a744a0 {
    FUN_00c5ced0(int a, int b, int c, int d);
};
// Sets the vtable pointer and stores the four constructor arguments at offsets 0xc4, 0xc8, 0xcc and 0xd0.
// @fnv 0x00c5ced0
FUN_00c5ced0::FUN_00c5ced0(int a, int b, int c, int d)
{
    *(int**)((char*)this + 0) = (int*)&DAT_010c2e7c;
    *(int*)((char*)this + 0xc4) = a;
    *(int*)((char*)this + 0xc8) = b;
    *(int*)((char*)this + 0xcc) = c;
    *(int*)((char*)this + 0xd0) = d;
}

struct FUN_00c5cfd0_class {
    void FUN_00c5cfd0(int a, int b, int c, int d);
};
// Stores the four int arguments into the object's fields at offsets 0xc4, 0xc8, 0xcc and 0xd0.
// @fnv 0x00c5cfd0
void FUN_00c5cfd0_class::FUN_00c5cfd0(int a, int b, int c, int d)
{
    *(int*)((char*)this + 0xc4) = a;
    *(int*)((char*)this + 0xc8) = b;
    *(int*)((char*)this + 0xcc) = c;
    *(int*)((char*)this + 0xd0) = d;
}

extern "C" void __cdecl FUN_00c55200();
extern "C" unsigned char DAT_01204364;


extern unsigned char DAT_01204364;
void __cdecl FUN_00c552a0();
void __cdecl FUN_00c54760();
void __cdecl FUN_00c61760();

// @fnv 0x00c5d520
void __cdecl FUN_00c5d520()
{
    if (DAT_01204364) {
        ::fnv_00c655d0::FUN_00c655d0();
        FUN_00c552a0();
        FUN_00c54760();
        ::fnv_00c61990::FUN_00c61990();
        ::fnv_00c5f2e0::FUN_00c5f2e0();
        FUN_00c61760();
        ::fnv_00c435a0::FUN_00c435a0();
        DAT_01204364 = 0;
    }
}

struct FUN_00c5dea0_Entry {
    unsigned char mFlag;
};
struct FUN_00c5dea0_Class {
    int* pData;
    unsigned short mCount;
    void FUN_00c5dea0();
};
// Iterates the entries in the array at offset 0xd0 up to the count at 0xd6 and sets byte 0xd8 to 1 on each non-null entry.
// @fnv 0x00c5dea0
void FUN_00c5dea0_Class::FUN_00c5dea0()
{
    unsigned int count = *(unsigned short*)((char*)this + 0xd6);
    for (unsigned int i = 0; i < count; i++) {
        FUN_00c5dea0_Entry* e = (FUN_00c5dea0_Entry*)((*(int**)((char*)this + 0xd0))[i]);
        if (e)
            ((unsigned char*)e)[0xd8] = 1;
    }
}

struct FUN_00c5e560_class : public NiNode_Helper {
    void FUN_00c5e560(NiNode* a, void* b);
};
// @fnv 0x00c5e560
void FUN_00c5e560_class::FUN_00c5e560(NiNode* pNode, void* b)
{
    reinterpret_cast<::NiNode *>(this)->CopyMemberData(pNode, (*(::CloningProcess *)(b)));
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pNode) + 0xba) =
        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0xba);
}

struct FUN_00c5db90_Class {
};
struct FUN_00c5eb20_Class {
    void* FUN_00c5eb20(unsigned int flags);
};
// @fnv 0x00c5eb20
void* FUN_00c5eb20_Class::FUN_00c5eb20(unsigned int flags)
{
    reinterpret_cast<::FUN_00c5db90 *>((((FUN_00c5db90_Class*)this)))->FUN_00c5db90::~FUN_00c5db90();
    if (flags & 1) operator delete(this, 0xe0);
    return this;
}

namespace fnv_00c5eca0 {
extern "C" void __cdecl NiFree(void*);
struct MemoryManager {
    void Deallocate(void*);
};
struct P03MM_Deallocate {
    void Deallocate(void*);
};
struct FUN_00c5eca0_Class {
    int* FUN_00c5eca0(int arg);
};
// @fnv 0x00c5eca0
int* FUN_00c5eca0_Class::FUN_00c5eca0(int aiFlags)
{
    int* result;
    *(void**)this = (void*)&::DAT_010c30b8;
    result = *(int**)((char*)this + 4);
    NiFree(result);
    if (aiFlags & 1)
        ((P03MM_Deallocate*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))->Deallocate(this);
    return (int*)this;
}
}  // namespace fnv_00c5eca0


struct FUN_00c5ed60_Class {
    void FUN_00c5ed60();
};

struct FUN_00c5f360_Class {
    void* FUN_00c5f360(unsigned int flags);
};

struct FUN_00c5f390_class {
};
struct FUN_00c5f500_class {
    void FUN_00c5f500(FUN_00c5f500_class* other);
    int pad;
    int* data;
    unsigned int count;
};

struct FUN_00c5fc20_class {
    void* FUN_00c5fc20(unsigned int flags);
    void FUN_00c5faa0();
};
// Calls FUN_00c5faa0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c5fc20
void* FUN_00c5fc20_class::FUN_00c5fc20(unsigned int flags)
{
    reinterpret_cast<struct ::FUN_00c5faa0 *>(this)->FUN_00a5e930();
    if (flags & 1)
        operator delete(this, 0xac);
    return this;
}

struct BaseForCall {  };
struct NiObject {
    char pad[0xac];
    unsigned char unkac;
    char padad[0x3];
    int p;
    unsigned char flag;
};
struct FUN_00c439b0_class : BaseForCall {
    char FUN_00c439b0(NiObject* apParam);
};
// Calls FUN_00a5e600 on apParam; if true, returns whether this and apParam have equal p and byte at 0xac.
// @fnv 0x00c439b0
char FUN_00c439b0_class::FUN_00c439b0(NiObject* apParam)
{
    bool result2 = reinterpret_cast<::NiNodeEq *>(this)->FUN_00a5e600((::NiAVObject *)(apParam));
    if (result2) {
        NiObject* localParam2 = apParam;
        int localOther3 = ((NiObject*)this)->p;
        int localThis = localParam2->p;
        result2 = (localOther3 == localThis && ((unsigned char*)this)[0xac] == localParam2->unkac) ? 1 : 0;
    }
    return result2;
}

struct RefCountedObject {
    virtual ~RefCountedObject();
    virtual void vfn_0004();
    volatile long m_lObjectReferenceCount;
};
struct FUN_00c46270_Class {
    RefCountedObject* m_pObject;
    FUN_00c46270_Class& AssignRefCounted(const FUN_00c46270_Class& other);
};
// Copy-assigns the held RefCountedObject pointer, releasing the old one and incrementing the new one's reference count.
// @fnv 0x00c46270
FUN_00c46270_Class& FUN_00c46270_Class::AssignRefCounted(const FUN_00c46270_Class& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
        {
            RefCountedObject* object = m_pObject;
            if (InterlockedDecrement(&object->m_lObjectReferenceCount) == 0)
                object->vfn_0004();
        }
        m_pObject = other.m_pObject;
        if (m_pObject)
        {
            RefCountedObject* object = m_pObject;
            InterlockedIncrement(&object->m_lObjectReferenceCount);
        }
    }
    return *this;
}


struct FUN_00c46960_Class {
    GlobalObject_00a7b610* FUN_00c46960();
};

// @fnv 0x00c46960
GlobalObject_00a7b610* FUN_00c46960_Class::FUN_00c46960()
{
    return &::g_01202e60;
}

struct Elem_00c48a10 { int p; int a; int b; };
struct ElemY
{
    int a, b, c;
};
struct FUN_00c4a1e0
{
    virtual void v00();
    virtual ElemY* Allocate(unsigned int uiElementCount);
    ElemY* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void ConstructItems(ElemY* pkItems, unsigned int uiElementCount)
    {
        int aiA[4];
        for (unsigned int i = 0; i < uiElementCount; i++)
            new (&pkItems[i]) ElemY;
    }
    void ConstructItems2(ElemY* pkItems, unsigned int uiElementCount)
    {
        int aiB[3];
        for (unsigned int i = 0; i < uiElementCount; i++)
            new (&pkItems[i]) ElemY;
    }
    void DestructItems(ElemY* pkItems, unsigned int uiElementCount)
    {
        for (unsigned int i = 0; i < uiElementCount; i++)
            pkItems[i].~ElemY();
    }
    void SetSize(unsigned int uiNewSize, bool bFree);
};

struct Arr_00c48a10
{
    int _0;
    Elem_00c48a10* m_pData;
    int _8;
    int m_iCapacity;
    void FUN_00c4a1e0(int, bool);
};
struct FUN_00c48a10_t {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Arr_00c48a10 m_kArray;
    int _24;
    int m_iArrayLength;
    void ShiftElements(int iDelta, bool bClear);
};

// @fnv 0x00c48a10
void FUN_00c48a10_t::ShiftElements(int iDelta, bool bClear)
{
    int i;
    int j;
    int iNegShift;
    int iShift;
    if (iDelta > 0)
    {
        iShift = iDelta;
        int iCap = m_kArray.m_iCapacity;
        if (m_iArrayLength + iShift >= iCap)
        {
            int iOldCap;
            reinterpret_cast<::FUN_00c4a1e0 *>(&(m_kArray))->SetSize((iOldCap = m_kArray.m_iCapacity) + (iShift > 10 ? iShift : 10), true);
        }
        i = 0;
        for (i = m_iArrayLength + iShift - 1; i >= iShift; i--)
        {
            Elem_00c48a10* pSrc = &m_kArray.m_pData[i - iShift];
            m_kArray.m_pData[i].p = pSrc->p;
        }
        if (bClear)
        {
            for (; i > 0; i--)
                m_kArray.m_pData[i].p = 0;
        }
        m_iArrayLength += iShift;
    }
    else if (iDelta < 0)
    {
        iNegShift = -iDelta;
        if (m_iArrayLength > iNegShift)
        {
            for (j = 0; j < m_iArrayLength - iNegShift; j++)
            {
                Elem_00c48a10* pSrc2 = &m_kArray.m_pData[j + iNegShift];
                m_kArray.m_pData[j].p = pSrc2->p;
            }
            m_iArrayLength -= iNegShift;
        }
        else
        {
            m_iArrayLength = 0;
        }
    }
}

struct FUN_00c4a9c0_class {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08(void*);
    void* m_p;
    unsigned int m_uiItemCount;
    int m_auiShapeKeys;
    void ReleaseBuffer(unsigned char a);
};
// @fnv 0x00c4a9c0
void FUN_00c4a9c0_class::ReleaseBuffer(unsigned char a)
{
    if (m_p) {
        for (int i = 0; i < m_uiItemCount; ++i) {
        }
        if (a) {
            vfn_08(m_p);
            m_p = 0;
            m_p = 0;
            m_auiShapeKeys = 0;
        }
        m_uiItemCount = 0;
    }
}

void* __cdecl NiMalloc(unsigned int);

struct FUN_00c5ec10_Class {
    int* vtbl;
    void* m0;
    unsigned short m1;
    unsigned short m2;
    unsigned short m3;
    unsigned short m4;
    FUN_00c5ec10_Class(unsigned short a, unsigned short b);
};

// @fnv 0x00c5ec10
FUN_00c5ec10_Class::FUN_00c5ec10_Class(unsigned short ausCount, unsigned short b)
{
    vtbl = (int*)&DAT_010c30b8;
    m1 = ausCount;
    m4 = b;
    m2 = 0;
    m3 = 0;
    if (m1 > 0) {
        unsigned int n = m1;
        m0 = NiMalloc(n * 4);
    } else {
        m0 = 0;
    }
}

extern int DAT_010c1b2c;
struct FUN_00c5f570_Class {
    void FUN_00c5f570();
};
struct FUN_00c450d0 : FUN_00c5f570_Class {
    int vtbl;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char ba;
    unsigned char bb;
    unsigned char bc;
    unsigned char bd;
    unsigned char be;
    unsigned char bf;
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;
    unsigned char c5;
    unsigned char c6;
    unsigned char c7;
    unsigned char c8;
    unsigned char c9;
    unsigned char ca;
    unsigned char cb;
    unsigned char cc;
    unsigned char cd;
    unsigned char ce;
    unsigned char cf;
    unsigned char d0;
    unsigned char d1;
    unsigned char d2;
    unsigned char d3;
    unsigned char d4;
    unsigned char d5;
    unsigned char d6;
    unsigned char d7;
    unsigned char d8;
    unsigned char d9;
    unsigned char da;
    unsigned char db;
    unsigned char dc;
    unsigned char dd;
    unsigned char de;
    unsigned char df;
    unsigned char e0;
    unsigned char e1;
    unsigned char e2;
    unsigned char e3;
    unsigned char e4;
    unsigned char e5;
    unsigned char e6;
    unsigned char e7;
    unsigned char e8;
    unsigned char e9;
    unsigned char ea;
    unsigned char eb;
    unsigned char ec;
    unsigned char ed;
    unsigned char ee;
    unsigned char ef;
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    unsigned char a0;
    unsigned char a1;
    unsigned char a2;
    unsigned char a3;
    unsigned char a4;
    unsigned char a5;
    unsigned char a6;
    unsigned char a7;
    unsigned char a8;
    unsigned char a9;
    unsigned char aa;
    unsigned char ab;
    unsigned char ac;
    unsigned char ad;
    unsigned char ae;
    unsigned char af;
    FUN_00c450d0();
};
// Calls the base constructor, installs the vtable, and initialises the bytes at offsets 0xac-0xaf to 1, 0, 0, 0xff.
// @fnv 0x00c450d0
FUN_00c450d0::FUN_00c450d0()
{
    new ((void *)this) ::fnv_00c5f570::FUN_00c5f570();
    vtbl = (intptr_t)&DAT_010c1b2c;
    *(unsigned char*)((char*)this + 0xae) = 0;
    *(unsigned char*)((char*)this + 0xaf) = 0xff;
    *(unsigned char*)((char*)this + 0xad) = 0;
    *(unsigned char*)((char*)this + 0xac) = 1;
}

struct FUN_00c465a0_class {
    FUN_00c465a0_class();
    char pad[0x1c];
};
struct FUN_00c46670_class {
    void* FUN_00c46670(CloningProcess& process);
};
// Allocates a FUN_00c465a0_class object, passes it with process to CopyModifier, and returns the new object.
// @fnv 0x00c46670
void* FUN_00c46670_class::FUN_00c46670(CloningProcess& process)
{
    NiPSysModifier_StandIn* p = (NiPSysModifier_StandIn*)new FUN_00c465a0_class;
    ((NiPSysModifier_StandIn*)this)->CopyModifier(p, process);
    return (void*)p;
}

struct FUN_00c465a0 {
    char* p;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    FUN_00c465a0();
    ~FUN_00c465a0();
};
// Allocates and constructs a new FUN_00c465a0 object, returning its pointer.
// @fnv 0x00c46740
FUN_00c465a0* __cdecl FUN_00c46740()
{
    return new FUN_00c465a0;
}

struct FUN_00c48fe0_Class {
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int FUN_00c48fe0();
};

// Counts entries in the array at m_0018 whose first int is 7 or 8, skipping the following entry each time.
// @fnv 0x00c48fe0
int FUN_00c48fe0_Class::FUN_00c48fe0()
{
    int iCount = 0;
    for (int i = 0; i < m_0028; i++) {
        if (*((int*)((char*)m_0018 + i * 12)) == 7 || *((int*)((char*)m_0018 + i * 12)) == 8) {
            iCount++;
            i++;
        }
    }
    return iCount;
}

struct FUN_00c4a5a0_class {
    virtual void vfn_0000();
    virtual void* vfn_0004(unsigned int);
    void* m1;
    unsigned int m2;
    unsigned int m3;
    void FUN_00c4a5a0(unsigned int a, unsigned int b);
};

// @fnv 0x00c4a5a0
void FUN_00c4a5a0_class::FUN_00c4a5a0(unsigned int uiCapacity, unsigned int b)
{
    m1 = 0;
    m2 = 0;
    m3 = 0;
    if (b > uiCapacity)
        uiCapacity = b;
    if (uiCapacity > 0) {
        m1 = vfn_0004(uiCapacity);
        m3 = uiCapacity;
    }
    if (b > 0) {
        for (unsigned int i = 0; i < b; ++i) {
            void* p = &((char*)m1)[i * 12];
        }
        m2 = b;
    }
}

struct CloningProcess;
struct NiBinaryExtraData;
struct NiFloatsExtraData;
struct NiExtraData_Shell {
};
struct FUN_00c54dd0 : NiExtraData_Shell {
    void FUN_00a7b330(NiBinaryExtraData*, CloningProcess*);
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
};
struct FUN_00c54dd0_3i {
    int x;
    int y;
    int z;
};
// @fnv 0x00c54dd0
void FUN_00c54dd0::FUN_00a7b330(NiBinaryExtraData* dest, CloningProcess* proc)
{
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330(dest, proc);
    *(FUN_00c54dd0_3i*)((char*)dest + 0xc) = *(FUN_00c54dd0_3i*)((char*)this + 0xc);
    *(FUN_00c54dd0_3i*)((char*)dest + 0x18) = *(FUN_00c54dd0_3i*)((char*)this + 0x18);
}

struct Elem4 {  };
struct FUN_0042fb60_shell { void FUN_0042fb60(char*, char*, unsigned int); };
struct FUN_00c5bef0_class {
    char* m0;
    char* m1;
    unsigned int m2;
    void RemoveRange(unsigned int a, unsigned int b);
};
struct NiObject;
class NiObject;
struct NiStream {
    NiObject* DeserializeObject();
public:
    ::NiObject *GetLoadedObject();
};
struct FUN_00c5cc30_class {
    void FUN_00c5cc30(NiStream&);
};
// @fnv 0x00c5cc30
void FUN_00c5cc30_class::FUN_00c5cc30(NiStream& stream)
{
    reinterpret_cast<::NiPSysEmitterCtlr *>(this)->LoadBinary(stream);
    ::FUN_00a30370((::Stream *)(::NiStream *)(&stream), (void*)((char*)this + 0x60));
    if (*((unsigned short*)((char*)this + 0x60)) < 1)
        *((unsigned short*)((char*)this + 0x60)) = 1;
    *((NiObject**)((char*)this + 0x5c)) = stream.DeserializeObject();
}

struct FUN_00c5d610_StandIn {
};
struct FUN_00c5d610_Class {
    unsigned int AddRegSettingsStrings(NiTPrimitiveArray_unsigned_int_& arr);
};
// @fnv 0x00c5d610
unsigned int FUN_00c5d610_Class::AddRegSettingsStrings(NiTPrimitiveArray_unsigned_int_& arrStrings)
{
    char pad[0x38];
    unsigned int p = (uintptr_t)FUN_00a7d330("RegSettings");
    reinterpret_cast<::S_0060ba10 *>(&(arrStrings))->FUN_0096a610((intptr_t)&(p));
    unsigned int v6 = ((unsigned int)(reinterpret_cast<::B44F890Collection *>((((FUN_00c5d610_StandIn*)this)))->FUN_0044f890((int)&(arrStrings))));
    unsigned int p2 = (uintptr_t)FUN_00a7d510("Total RegSettings", v6);
    reinterpret_cast<::S_0060ba10 *>(&(arrStrings))->FUN_0096a610((intptr_t)&(p2));
    return v6;
}


// Calls FUN_00c33090 on apParams[2] and maps the returned state to 3, 1, or 4.
// @fnv 0x00c5da10
int __cdecl GetStateResult(int* apParams)
{
    int iResult = 0;
    int iState = ::FUN_00c33090((const char *)(apParams[2]));
    switch (iState)
    {
    case 0: iResult = 3; break;
    case 6: iResult = 1; break;
    default: iResult = 4; break;
    }
    return iResult;
}

struct FUN_00c5e620_Class {
    void FUN_00c5e620(NiStream* stream);
};

struct NiNode_LoadBinary_StandIn {
};

struct NiStream_ReadMultipleLinkIDs_Helper {
};

// @fnv 0x00c5e620
void FUN_00c5e620_Class::FUN_00c5e620(NiStream* stream)
{
    reinterpret_cast<::fnv_00a5dd40::FUN_00a5dd40_shell *>((((NiNode_LoadBinary_StandIn*)this)))->FUN_00a5dd40(stream);
    ::FUN_00a30370((::Stream *)(stream), (char*)this + 0xba);
    if (*(unsigned int*)((char*)stream + 4) > 0xf) {
        reinterpret_cast<::S_00a64670_Foo *>((((NiStream_ReadMultipleLinkIDs_Helper*)stream)))->FUN_00a64670();
    }
}

struct ObjA
{
    void FUN_0044dd60();
};
struct FUN_00c40910_Class {
    ObjA* m_p;
    void CallObjA();
};
// @fnv 0x00c40910
void FUN_00c40910_Class::CallObjA()
{
    int a;
    int b;
    int c;
    if (m_p)
        ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_p));
}

struct FUN_00c42060_Class {
    virtual void vfn_0000();
    virtual void vfn_0004();
    int m4;            // +0x4
    int m8;            // +0x8
    char pad[0xc];
    unsigned char m18; // +0x18
    void SetArg(int arg);
};

// @fnv 0x00c42060
void FUN_00c42060_Class::SetArg(int arg)
{
    vfn_0004();
    m8 = arg;
    if (0) {
        m18 |= 1;
    } else {
        m18 &= ~1;
    }
    if (0) {
        m18 |= 2;
    } else {
        m18 &= ~2;
    }
}

extern int DAT_010c1844;

// @fnv 0x00c42f00
void DestroyResources(void* thisPtr)
{
    *(void**)thisPtr = (void*)&DAT_010c1844;
    SuspendThread(*(void**)((char*)thisPtr + 4));
    CloseHandle(*(void**)((char*)thisPtr + 4));
    CloseHandle(*(void**)((char*)thisPtr + 0x1c));
    CloseHandle(*(void**)((char*)thisPtr + 0x10));
}

extern int DAT_010c1854;
struct FUN_00c43070_shell {
    void FUN_00a7b300();
    void FUN_00c43070();
};
// @fnv 0x00c43620
void* FUN_00c43620_Class::FUN_00c43620(unsigned int flags)
{
    reinterpret_cast<::FUN_00c43070_shell *>(this)->FUN_00c43070();
    if (flags & 1)
        operator delete(this, 16);
    return this;
}
// @fnv 0x00c43070
void FUN_00c43070_shell::FUN_00c43070()
{
    *reinterpret_cast<int**>(this) = &DAT_010c1854;
    *reinterpret_cast<int**>(this) = &DAT_010a0d24;
    reinterpret_cast<::FUN_00a7b300_shell *>(this)->FUN_00a7b300();
}

struct NiExtraDataX {
    virtual void vfn_0000();
    virtual void* vfn_0004();
    virtual void* vfn_0008();
};

struct NiAVObjectX
{
    NiExtraDataX* GetExtraData(NiFixedString* name);
};


// Returns the extra data attached to obj under DAT_01202ddc if its vfn_0008 matches _g_01202de0, otherwise null.
// @fnv 0x00c43490
void* GetExtraDataChecked(NiAVObjectX* obj)
{
    void* result5 = 0;
    if (obj != 0) {
        NiExtraDataX* extra;
        NiFixedString* name = DAT_01202ddc;
        extra = ((::NiExtraDataX *)(reinterpret_cast<::NiAVObject *>((obj))->GetExtraData((*(const ::NiFixedString *)(name)))));
        bool ok2;
        if (extra == 0) {
            ok2 = false;
        } else {
            ok2 = (extra->vfn_0008() == (void*)&(*reinterpret_cast<void * *>(&::g_01202de0)));
        }
        if (ok2) {
            result5 = extra;
        }
    }
    return result5;
}

extern int DAT_010c195c;

struct FUN_00c43660 : FUN_00c5f570_Class {
    char pad[0xb0];
    int f1;
    int f2;
    FUN_00c43660();
};
// @fnv 0x00c43660
FUN_00c43660::FUN_00c43660()
{
    new ((void *)this) ::fnv_00c5f570::FUN_00c5f570();
    *(void**)this = (void*)&DAT_010c195c;
    f1 = 0;
    f2 = 0;
}

struct NiNode_StandIn {
};


struct BSValueNode_StandIn : NiNode_StandIn {
    char pad[0xac];
    unsigned int m_field_ac;
    unsigned int m_field_b0;
    void FUN_00c438a0(NiStream& stream);
};

// @fnv 0x00c438a0
void BSValueNode_StandIn::FUN_00c438a0(NiStream& stream)
{
    unsigned int local2;
    reinterpret_cast<::fnv_00a5dd40::FUN_00a5dd40_shell *>(this)->FUN_00a5dd40((::NiStream *)&(stream));
    ::FUN_00a26df0((::MyStream *)&(stream), (void *)&(local2));
    unsigned int val = local2;
    m_field_b0 = val;
    if (*(unsigned int*)((char*)&stream + 4) > 0x18) {
        ::FUN_00a643b0((::BA643B0Stream &)(stream), (char *)&(m_field_ac));
    }
}

struct FUN_00c43920_class {
    char FUN_00c43920(NiStream* stream);
};

// @fnv 0x00c43920
char FUN_00c43920_class::FUN_00c43920(NiStream* stream)
{
    if (!((unsigned char)(::fnv_00a5e5b0::RegisterChildStreamables((::NiNode *)(((FUN_00a5e5b0_helper*)this)), (std::intptr_t)(stream), *(::fnv_00a5e5b0::NiStream *)nullptr))))
        return 0;
    return 1;
}

struct MyBase {
};


struct FUN_00c43950_Class : MyBase {
    void FUN_00c43950(NiStream& stream);
};

// @fnv 0x00c43950
void FUN_00c43950_Class::FUN_00c43950(NiStream& stream)
{
    reinterpret_cast<::NodeA5E8 *>(this)->FUN_00a5e880((::NiStreamA5E8 &)(stream));
    int b = *(int*)((char*)this + 0xb0);
    int a = b;
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)&stream), (intptr_t)((SObj*)&a));
    ::FUN_00a29550((intptr_t)&(stream), (intptr_t)((unsigned char*)this + 0xac));
}

struct FUN_00c43cb0_class {
    void FUN_00c5faa0();
    void* FUN_00c43cb0(unsigned int flags);
};
// Calls FUN_00c5faa0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c43cb0
void* FUN_00c43cb0_class::FUN_00c43cb0(unsigned int flags)
{
    reinterpret_cast<struct ::FUN_00c5faa0 *>(this)->FUN_00a5e930();
    if (flags & 1)
        operator delete(this, 0xb8);
    return this;
}

struct FUN_00c457e0_class {
    char pad[0xb0];
    void FUN_00c5faa0();
    void* FUN_00c457e0(unsigned int flags);
};

// Calls FUN_00c5faa0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c457e0
void* FUN_00c457e0_class::FUN_00c457e0(unsigned int flags)
{
    reinterpret_cast<struct ::FUN_00c5faa0 *>(this)->FUN_00a5e930();
    if (flags & 1)
        operator delete(this, 0xb0);
    return this;
}

struct FUN_00c46230_Class {
    void* m0;
    void FUN_00c46230();
};
// @fnv 0x00c46230
void FUN_00c46230_Class::FUN_00c46230()
{
    void* tmp;
    m0 = 0;
    if (m0)
    {
        tmp = m0;
        InterlockedIncrement((long*)((char*)tmp + 4));
    }
}


struct FUN_00c46930_class {
    void* FUN_00c46930(unsigned int flags);
};

// @fnv 0x00c46930
void* FUN_00c46930_class::FUN_00c46930(unsigned int flags)
{
    reinterpret_cast<::PositionState *>(this)->FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

struct A51BF0Base {
    char pad[0xb4];

    A51BF0Base();

    A51BF0Base* FUN_00c46ba0(int a);
};


struct GO {
    void operator=(void*);
public:
    ::GO *FUN_008228f0(unsigned int);
};
// Clears b elements starting at index a, moves the tail block down by count elements, and shrinks m2 by b.
// @fnv 0x00c5bef0
void FUN_00c5bef0_class::RemoveRange(unsigned int uiStart, unsigned int b)
{
    unsigned int i;
    unsigned int count;
    char* dst2;
    unsigned int aLimit;
    unsigned int unused1;
    unsigned int unused2;
    unsigned int FlushUsageData;
    aLimit = m2 - uiStart - b;
    count = aLimit < b ? aLimit : b;
    dst2 = m1 + uiStart * 4;
    for (i = 0; i < b; i++)
        reinterpret_cast<::GO *>((((Elem4*)(dst2 + i * 4))))->FUN_008228f0(0);
    ((FUN_0042fb60_shell*)this)->FUN_0042fb60(m1 + uiStart * 4, m1 + m2 * 4 - count * 4, count);
    m2 -= b;
}

struct NiStreamHelper {
};

struct FUN_00c46cd0_Class {
    char pad[0xac];
    GO m_go;

    void LoadFromStream(void* stream);
};

// @fnv 0x00c46cd0
void FUN_00c46cd0_Class::LoadFromStream(void* stream)
{
    void* unused1;
    void* unused2;

    reinterpret_cast<::sa5e9d0::Node *>((reinterpret_cast<NiNode*>(this)))->ReadChildListFromStream((::sa5e9d0::Stream *)(stream));
    m_go = ((void *)(reinterpret_cast<::NiStream *>((reinterpret_cast<NiStreamHelper*>(stream)))->GetLoadedObject()));
}

struct FUN_00c46af0 {
    void* FUN_00c47610(unsigned int flags);
};

struct FUN_00c47a00_Class {
    char pad0[0x18];
    char* m18;             // +0x18
    char pad1[0x4];
    int m20;               // +0x20
    char pad2[0x4];
    int m28;               // +0x28
    void FUN_00c47a00();
};

// @fnv 0x00c47a00
void FUN_00c47a00_Class::FUN_00c47a00()
{
    int count = m20;
    if (!(m28 + 1 < count))
    {
        int c = m20;
        reinterpret_cast<::FUN_00c4a1e0 *>((((Arr_00c48a10*)((char*)this + 0x14))))->SetSize(c + 0xa, true);
    }
    *(int*)(m18 + m28 * 0xc) = 4;
    m28 = m28 + 1;
}

struct FUN_00c47a70_Class {
    void FUN_00c47a70();
};

// @fnv 0x00c47a70
void FUN_00c47a70_Class::FUN_00c47a70()
{
    int cap = *(int*)((char*)this + 0x20);
    if (*(int*)((char*)this + 0x28) + 1 >= cap) {
        int c = *(int*)((char*)this + 0x20);
        reinterpret_cast<::FUN_00c4a1e0 *>((((Arr_00c48a10*)((char*)this + 0x14))))->SetSize(c + 0xa, true);
    }
    *(char*)this = 0;
    *(int*)(*(int*)((char*)this + 0x18) + *(int*)((char*)this + 0x28) * 0xc) = 5;
    *(int*)((char*)this + 0x28) = *(int*)((char*)this + 0x28) + 1;
}

struct FUN_006dc6e0_Class
{
    virtual void* v0();
    virtual char* v4(unsigned int);
    virtual void v8(char*);
    virtual char* vc(char*, unsigned int);

    char* m_p;
    unsigned int m_ucUnknownByte;
    unsigned int m_uiFilterValue;

    void FUN_006dc6e0(char*, char*, unsigned int);
    void FUN_00c4a4e0(unsigned int, unsigned int);
};

// @fnv 0x00c4a4e0
void FUN_006dc6e0_Class::FUN_00c4a4e0(unsigned int a, unsigned int b)
{
    char* GetObject;
    {
        void* unused;
        {
            void* unused;
        }
    }

    if (m_p != 0)
    {
        if (b == m_uiFilterValue)
        {
            m_p = vc(m_p, a);
        }
        else
        {
            GetObject = v4(a);
            FUN_006dc6e0(GetObject, m_p, b);
            v8(m_p);
            m_p = 0;
            m_p = GetObject;
        }
    }
    else
    {
        m_p = v4(a);
        m_uiFilterValue = a;
    }
}

struct FUN_00c4a960_Class {
    void FUN_00c4a840();
    void* FUN_00c4a960(unsigned int flags);
};
struct FUN_00c4ab80_class {
    char FUN_00c4ab80(int a);
};

// @fnv 0x00c4ab80
char FUN_00c4ab80_class::FUN_00c4ab80(int a)
{
    if (!reinterpret_cast<::FUN_00c452c0_class *>(this)->FUN_00c452c0((::NiStream *)(a)))
        return 0;
    return 1;
}


struct FUN_00c4ad60_class : public FUN_00c4ab00_Class {
    void AddFirstEmptyFromGlobal(int a);
};

template <class T>
class NiTPrimitiveArray {
public:
    unsigned int AddFirstEmpty(const T& value);
};


struct FUN_00c4afc0_class {
    void AddValueToArray(NiTPrimitiveArray<unsigned int>* array);
};

struct FUN_00c4b090_class {
    char FUN_00c4b090(int a1);
};

struct FUN_00c4c920_class {
    unsigned int reserved;
    unsigned int* data;
    unsigned short capacity;
    unsigned short used;
    unsigned short nonNullCount;

    void FUN_00c4c920(unsigned int count);
};

void* _NiMalloc(unsigned int size);
void NiFree(void* ptr);

// Resizes the array to count entries, zeroing dropped slots, reallocating storage, copying existing entries and freeing the old buffer.
// @fnv 0x00c4c920
void FUN_00c4c920_class::FUN_00c4c920(unsigned int count)
{
    unsigned short i;
    unsigned int* oldData;
    unsigned int capacitySize;

    if (count == this->capacity)
        return;

    if (count < this->used) {
        for (i = (unsigned short)count; i < this->used; ++i) {
            if (this->data[i] != 0) {
                this->data[i] = 0;
                --this->nonNullCount;
            }
        }
        this->used = (unsigned short)count;
    }

    oldData = this->data;
    this->capacity = (unsigned short)count;

    if (count > 0) {
        capacitySize = this->capacity;
        this->data = (unsigned int*)_NiMalloc(capacitySize << 2);

        for (i = 0; i < this->used; ++i)
            this->data[i] = oldData[i];

        for (i = this->used; i < this->capacity; ++i)
            this->data[i] = 0;
    } else {
        this->data = 0;
    }

    NiFree(oldData);
}

namespace fnv_00c4e160 {
struct A51BF0Base {
};

struct FUN_00a74480 : A51BF0Base {
    char pad[0xc4];
    FUN_00a74480(unsigned int);
};

struct FUN_00c4e160_Class {
    FUN_00a74480* CreateInstance(unsigned int);
};

// Allocates and constructs a FUN_00a74480 object with the given value, returning the new instance.
// @fnv 0x00c4e160
FUN_00a74480* FUN_00c4e160_Class::CreateInstance(unsigned int auiValue)
{
    return new FUN_00a74480(auiValue);
}
}  // namespace fnv_00c4e160

struct FUN_00c4f270_Class {
    char pad[0x90];
    int m_type;
    int unk94;
    char pad98[0x24];
    int m_uiItemCount;
    int m_aiEntries[1];
    void FUN_00c4f270(int aeType);
};

// @fnv 0x00c4f270
void FUN_00c4f270_Class::FUN_00c4f270(int aeType)
{
    int saved = m_type;
    (&this->unk94)[m_uiItemCount] = saved;
    m_uiItemCount = m_uiItemCount + 1;
    m_type = aeType;
}

namespace fnv_00c513f0 {
struct A51BF0Base {
};

struct FUN_00c5da70 : public A51BF0Base {
    char pad[0xdc];

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
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(int, int);

    void FUN_00c5de70();

    FUN_00c5da70();
};

FUN_00c5da70::FUN_00c5da70()
{
}


// @fnv 0x00c513f0
FUN_00c5da70* __cdecl CreateAndInitObject(int a)
{
    FUN_00c5da70* result = 0;

    if (((unsigned char)(::FUN_00c50f90((::C50Object *)(a), (void *)(0))))) {
        result = new FUN_00c5da70;
        ::SetParticleSystemTarget((::NiAVObjectStub *)(a), (intptr_t)(result));
        result->v55(a, 1);
        result->FUN_00c5de70();
    }

    return result;
}
}  // namespace fnv_00c513f0

namespace fnv_00c514c0 {
struct A51BF0Base {
};

int _data_011c16bc;

struct FUN_00c503d0 : public A51BF0Base {
    char pad[0xb8];
    FUN_00c503d0();
};

struct FUN_00c514c0_Class : public FUN_00c51550 {
    void* FUN_00c514c0(void* source);
};

// @fnv 0x00c514c0
void* FUN_00c514c0_Class::FUN_00c514c0(void* source)
{
    FUN_00c503d0* copy = new FUN_00c503d0;
    Copy(reinterpret_cast<NiNode*>(copy), source);
    return copy;
}
}  // namespace fnv_00c514c0

struct NiPSysEmitterCtlr_StandIn
{
    void FUN_00c5cb20(NiPSysEmitterCtlr_StandIn* a, void* b);
public:
    ::NiBoolInterpolator *FUN_00639b60();
};

// @fnv 0x00c5cb20
void NiPSysEmitterCtlr_StandIn::FUN_00c5cb20(NiPSysEmitterCtlr_StandIn* apTarget, void* apArg)
{
    reinterpret_cast<::NiPSysEmitterCtlr *>(this)->CopyMemberData((::NiPSysEmitterCtlr *)(apTarget), (*(::CloningProcess *)(apArg)));
    *(unsigned short*)((char*)apTarget + 0x60) = *(unsigned short*)((char*)this + 0x60);
}

struct FUN_00c5ce40_Class {
    int PopFrontNode();
};

// @fnv 0x00c5ce40
int FUN_00c5ce40_Class::PopFrontNode()
{
    int* pList = (int*)((char*)this + 0xc0);
    int* pNode2 = (int*)(*pList + 8);
    *pList = *(int*)*pList;
    int result2 = *pNode2;
    if (*(int*)((char*)this + 0xc0) == 0) {
        int v2 = *(int*)((char*)this + 0xac);
        *(int*)((char*)this + 0xc0) = v2;
    }
    return result2;
}

struct FUN_00c5d260_view {
};
struct FUN_00c5d260 : FUN_00c5d260_view {
    void* FUN_00c5d260_method(unsigned int flags);
};
// Calls Destruct, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c5d260
void* FUN_00c5d260::FUN_00c5d260_method(unsigned int flags)
{
    reinterpret_cast<::FUN_00c5cfb0 *>((reinterpret_cast<FUN_00c5d260_view*>(this)))->FUN_00c5cfb0::~FUN_00c5cfb0();
    if (flags & 1)
        ::operator delete(this, 0xd4);
    return this;
}


// Evaluates a quintic polynomial in x using two global double constants and returns the float result.
// @fnv 0x00c5d2b0
float __cdecl EvaluateQuinticPolynomial(float x)
{
    float result;
    result = x * x * x * x * x * DAT_01034208
           - x * x * x * x * ::runtimeInitializationDouble5
           + x * x * x * 10.0;
    return result;
}

// @fnv 0x00c5d300
float FUN_00c5d300(float afFactor, float afStart, float afEnd)
{
    return afFactor * (afEnd - afStart) + afStart;
}

namespace fnv_00c5e4d0 {
struct A51BF0Base {
};

struct FUN_00c5da70 : public NiNode, public A51BF0Base {
    char pad[0xdf];

    FUN_00c5da70();
};

FUN_00c5da70::FUN_00c5da70()
{
}

struct FUN_00c5e4d0_class : public FUN_00c5e560_class {
    FUN_00c5da70* CreateNode(void*);
};

// @fnv 0x00c5e4d0
FUN_00c5da70* FUN_00c5e4d0_class::CreateNode(void* arg)
{
    FUN_00c5da70* object = new FUN_00c5da70;
    this->FUN_00c5e560(object, arg);
    return object;
}
}  // namespace fnv_00c5e4d0

namespace fnv_00c5e5a0 {
struct A51BF0Base {
};

struct FUN_00c5da70_Class : public A51BF0Base {
    char pad[0xe0];
    FUN_00c5da70_Class();
};

// Allocates and constructs a FUN_00c5da70_Class object, returning the new instance.
// @fnv 0x00c5e5a0
FUN_00c5da70_Class* __cdecl FUN_00c5e5a0()
{
    FUN_00c5da70_Class* result = new FUN_00c5da70_Class;
    return result;
}
}  // namespace fnv_00c5e5a0

struct NiObjectNET_stub {
};
struct FUN_00c5de70_stub {
};
struct FUN_00c5e6f0_class {
    void FUN_00c5e6f0(int a);
};
struct FUN_00c5e720_Class {
    unsigned char FUN_00c5e720(NiStream* stream);
};

// @fnv 0x00c5e720
unsigned char FUN_00c5e720_Class::FUN_00c5e720(NiStream* stream)
{
    unsigned int i;
    void* obj;

    if (!((unsigned char)(::fnv_00a5e5b0::RegisterChildStreamables((::NiNode *)(((FUN_00a5e5b0_helper*)this)), (std::intptr_t)(stream), *(::fnv_00a5e5b0::NiStream *)nullptr))))
        return 0;

    for (i = 0; i < *(unsigned short*)((char*)this + 0xd6); ++i)
    {
        obj = *(void**)(*(int*)((char*)this + 0xd0) + i * 4);
        if (obj)
            (*(void(**)(void*, NiStream*))(*(int*)obj + 0x54))(obj, stream);
    }
    return 1;
}

struct FUN_00c5ede0_Class {
    int GetEntryAt(int a);
};
// @fnv 0x00c5ede0
int FUN_00c5ede0_Class::GetEntryAt(int aiIndex)
{
    return ((int*)*(int**)((char*)this + 0x10))[aiIndex];
}

namespace fnv_00c5ee00 {
struct A51BF0Base {
};

struct FUN_00c5ecf0 : A51BF0Base {
    char m_data[0x1c];
    FUN_00c5ecf0();
};

struct FUN_00c5ee00_Class {
    void FUN_00c5ee90(A51BF0Base* object, int value);
    A51BF0Base* CreateObjectWithValue(int value);
};

// Allocates a FUN_00c5ecf0 object, passes it with value to FUN_00c5ee90, and returns the object.
// @fnv 0x00c5ee00
A51BF0Base* FUN_00c5ee00_Class::CreateObjectWithValue(int value)
{
    A51BF0Base* object = new FUN_00c5ecf0;

    this->FUN_00c5ee90(object, value);
    return object;
}
}  // namespace fnv_00c5ee00

struct S_00a953b0_Node {
};

struct FUN_00c5fb60_class : public S_00a953b0_Node {
    void ForwardToBase(S_00a953b0_Node*, void*);
};
// @fnv 0x00c43850
void FUN_00c43850_Class::FUN_00c43850(void* dst, unsigned int size)
{
    int v;
    reinterpret_cast<::FUN_00c5fb60_class *>(this)->ForwardToBase((::S_00a953b0_Node *)(dst), (void *)(size));
    v = *(int*)((char*)this + 0xb0);
    *(int*)((char*)dst + 0xb0) = v;
    *(char*)((char*)dst + 0xac) = *(char*)((char*)this + 0xac);
}
// @fnv 0x00c4aae0
void FUN_00c4aae0_class::FUN_00c4aae0(intptr_t a, int b)
{
    reinterpret_cast<::FUN_00c451b0_class *>(this)->CopyStateTo(a, b);
}
// @fnv 0x00c4ad40
void FUN_00c4ad40_class::FUN_00c4ad40(intptr_t a, int b)
{
    reinterpret_cast<::FUN_00c451b0_class *>(this)->CopyStateTo(a, b);
}
// @fnv 0x00c4afa0
void FUN_00c4afa0_class::FUN_00c4afa0(intptr_t aiArg1, int aiArg2)
{
    reinterpret_cast<::FUN_00c451b0_class *>(this)->CopyStateTo(aiArg1, aiArg2);
}

// @fnv 0x00c5fb60
void FUN_00c5fb60_class::ForwardToBase(S_00a953b0_Node* apNode, void* apArg)
{
    reinterpret_cast<::NiNode *>(this)->CopyMemberData((::NiNode *)(apNode), (*(::CloningProcess *)(apArg)));
}

struct FUN_00c25d40_Class {
};
struct FUN_00c5fd70_Class {
    void FUN_00c5fd70(void* a, unsigned short b);
};
// Forwards the unsigned short argument to the target object's ResetEntry method.
// @fnv 0x00c5fd70
void FUN_00c5fd70_Class::FUN_00c5fd70(void* pTarget, unsigned short usValue)
{
    void* t = pTarget;
    reinterpret_cast<::FUN_00c25d40_shell *>((((FUN_00c25d40_Class*)t)))->ResetEntry(usValue);
}

struct NiPSysModifier_00c31950 {
};
struct FUN_00c5ffd0 : NiPSysModifier_00c31950 {
    void Method(NiStream* stream);
};
// @fnv 0x00c5ffd0
void FUN_00c5ffd0::Method(NiStream* stream)
{
    reinterpret_cast<::ParticleModifierBinary *>(this)->FUN_00c31950((*(::OutputStream *)(stream)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(::SStream *)((SStream*)stream), (intptr_t)((SObj*)((char*)this + 0x18)));
}

struct C40B20Timer {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned __int64 m_uiElapsedTime;

    void FUN_00c40b20();
};

// @fnv 0x00c40b20
void C40B20Timer::FUN_00c40b20()
{
    m_uiElapsedTime = 0;
}

struct S_0044dd60
{
    void FUN_0044dd60();
};

extern "C" void (*FUN_00fdf1c0)(void*);

struct FUN_00c41050_Class {
    S_0044dd60* m_pIntegerData;

    FUN_00c41050_Class* AssignRef(S_0044dd60** other);
};

// @fnv 0x00c41050
FUN_00c41050_Class* FUN_00c41050_Class::AssignRef(S_0044dd60** other)
{
    S_0044dd60* unk0;
    int unk1;
    int unk2;
    if (m_pIntegerData != *other) {
        if (m_pIntegerData) {
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_pIntegerData));
        }

        m_pIntegerData = *other;

        if (m_pIntegerData) {
            S_0044dd60* temp = m_pIntegerData;
            FUN_00fdf1c0(reinterpret_cast<char*>(temp) + 8);
        }
    }

    return this;
}

struct FUN_00c42b60_class;
struct SpawnHeap_cls { void FUN_00aa4060(void* pObject); };
typedef void (*S_00c422d0_IAT_Fn)(void*);
extern "C" S_00c422d0_IAT_Fn DAT_0fdf050;
struct S_00c422d0_Entry { unsigned int unk00; FUN_00c42b60_class* m_pObject; };
struct S_00c422d0_Foo {
    unsigned int m_uiItemCount;
    unsigned int m_unk04;
    S_00c422d0_Entry* m_pEntries;
    void DestroyEntries();
};
class FUN_00c42b40_cls
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
    int m_20;
    void FUN_00c42b40();
};


void* __cdecl FUN_00aa13e0(size_t size);

struct SpawnedObject_b9874 {
    char m00[0x10];
    SpawnedObject_b9874();
};

// @fnv 0x00c43190
SpawnedObject_b9874* FUN_00c43190() {
    SpawnedObject_b9874* obj = new SpawnedObject_b9874();
    ::AssignFixedString((char *)(obj), (intptr_t)(&(*reinterpret_cast<int *>(&::DAT_011f49e0))), {});
    return obj;
}

struct S_00c437c0_Obj {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    S_00c437c0_Obj();
};
struct S_00c437c0 : FUN_00c43850_Class {
    S_00c437c0_Obj* CreateObject(unsigned int stream);
};
// @fnv 0x00c437c0
S_00c437c0_Obj* S_00c437c0::CreateObject(unsigned int stream)
{
    S_00c437c0_Obj* p = new S_00c437c0_Obj;
    this->FUN_00c43850(p, stream);
    return p;
}

void* __cdecl FUN_00aa13e0(size_t size);

struct SpawnedObject_b9504 : FUN_00c43660 {
};

// Allocates and returns a new SpawnedObject_b9504 instance via its class-specific operator new.
// @fnv 0x00c43a30
FUN_00c43660* __cdecl FUN_00c43a30() {
    return new SpawnedObject_b9504();
}

class FUN_00c43be0_cls {
public:
    int unk00;
    int unk04;
    char* m_08;
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
    int m_b0;
    bool HasTrailingSuffix();
};


// @fnv 0x00c43be0
bool FUN_00c43be0_cls::HasTrailingSuffix()
{
    bool found3 = false;
    char* name = m_08;
    char* p4 = name;
    int len4 = std::strlen(p4);
    int i = 1;
    while (((p4[len4 - i] >= 0x30 && p4[len4 - i] <= 0x39) || p4[len4 - i] == 0x23 || p4[len4 - i] == 0x40) && (unsigned int)i <= (unsigned int)len4) {
        i++;
    }
    p4 = p4 + (len4 - i) + 1;
    if (*p4 != 0) {
        found3 = true;
    }
    m_b0 = std::atoi(p4);
    return found3;
}

// CopyStringBeforeColon
// Copies the leading part of a path (up to the first ':') into a caller buffer.

struct FUN_00c43e00_Obj {
    int unk00;
    int unk04;
    char* m_pStr;
};


// Copies the object's string into pDest up to the first ':' (or the whole string), null-terminating it; clears pDest if the string is null.
// @fnv 0x00c43e00
void __cdecl CopyStringBeforeColon(FUN_00c43e00_Obj* pObj, char* pDest)
{
    if (pDest) {
        unsigned int nLen = 0;
        *pDest = 0;
        const char* pStr = pObj->m_pStr;
        if (pStr) {
            const char* pColon = std::strchr((char *)(pStr), ':');
            nLen = pColon ? (unsigned int)(pColon - pStr) : std::strlen(pStr);
            fnv::crt::strncpy_s(pDest, nLen + 1, pStr, nLen);
            pDest[nLen] = 0;
        }
    }
}

struct S_00c44d90_Item;

struct S_00c44d90_Cls {
    void (__cdecl *m_pfnWork)(int, int);
    int* m_pArg;
    unsigned int m_uiCount;
    volatile long m_lIndex;
};

// Calls m_pfnWork for each index obtained by incrementing m_lIndex, while the index is below m_uiCount.
// @fnv 0x00c44d90
void __cdecl RunWorkItems(S_00c44d90_Cls* pWorkQueue)
{
    S_00c44d90_Cls* p = pWorkQueue;
    unsigned int i = 0;
    while (i < p->m_uiCount) {
        i = InterlockedIncrement(&p->m_lIndex);
        i = i - 1;
        if (i < p->m_uiCount)
            p->m_pfnWork(*(int*)&p->m_pArg, i);
    }
}

class NiStream;


class NiNodeC45 {
public:
    virtual ~NiNodeC45();

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
    short unkAC;
    bool m_bFlagAE;
    bool m_bFlagAF;
};

class BSNodeC45 : public NiNodeC45
{
  public:
    void SetFlag(bool m_bHeaderParsed);
    void FUN_00c45220(NiStream& kStream);
};
// @fnv 0x00c4ab40
void FUN_00c4ab40_class::FUN_00c4ab40(int aiValue)
{
    reinterpret_cast<::BSNodeC45 *>(this)->FUN_00c45220((*(::NiStream *)(aiValue)));
}
// @fnv 0x00c4b000
void FUN_00c4b000_class::FUN_00c4b000(int aiValue)
{
    reinterpret_cast<::BSNodeC45 *>(this)->FUN_00c45220((*(::NiStream *)(aiValue)));
}


struct S_00c45380_Base {  };
struct S_00c45380_Obj : S_00c45380_Base {
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
    unsigned char unkAC;
    unsigned char unkAD;
    unsigned char unkAE;
    unsigned char unkAF;
    char FUN_00c45380(S_00c45380_Obj* other);
};
// Calls FUN_00c45380 with a1 and returns its result.
// @fnv 0x00c4abd0
char FUN_00c4abd0_class::FUN_00c4abd0(int a1)
{
    char result = reinterpret_cast<::S_00c45380_Obj *>(this)->FUN_00c45380((::S_00c45380_Obj *)(a1));
    return result;
}
// Calls FUN_00c45380 with a and returns its result.
// @fnv 0x00c4ae30
unsigned char FUN_00c4ae30_class::FUN_00c4ae30(unsigned int a)
{
    unsigned char result = ((unsigned char)(reinterpret_cast<::S_00c45380_Obj *>(this)->FUN_00c45380((::S_00c45380_Obj *)(a))));
    return result;
}
// Calls FUN_00c45380 on this with a1 and returns its char result.
// @fnv 0x00c4b090
char FUN_00c4b090_class::FUN_00c4b090(int a1)
{
    char result = reinterpret_cast<::S_00c45380_Obj *>((((FUN_00c4abd0_class*)this)))->FUN_00c45380((::S_00c45380_Obj *)(a1));
    return result;
}

// Calls FUN_00a5e600 on other, then if true compares unkAE, unkAF and unkAD against other's and returns the result.
// @fnv 0x00c45380
char S_00c45380_Obj::FUN_00c45380(S_00c45380_Obj* other) {
    bool r7 = reinterpret_cast<::NiNodeEq *>(this)->FUN_00a5e600((::NiAVObject *)(other));
    if (r7) {
        S_00c45380_Obj* oB = other;
        unsigned char a8, b, c5, d, e, f7;
        r7 = ((a8 = unkAE, b = oB->unkAE, a8 == b) && (c5 = unkAF, d = oB->unkAF, c5 == d) && (e = unkAD, f7 = oB->unkAD, e == f7)) ? 1 : 0;
    }
    return r7;
}


class GameLockA
{
  public:
    void FUN_0040fbf0(int a);
};

class GameLockB {
public:
};

extern unsigned int DAT_01202e44;


struct FUN_00c459d0_frame {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};


namespace fnv_00c45a80 {
// TruncateStringToMaxLength: clamps the maximum length of the global fixed string object
// DAT_01202e20 down to 100 characters when it has grown past that limit.

struct FUN_00c45a80_cls
{
    unsigned int m_uiUnknown;    // +0x00
    char*        m_pString;      // +0x04
    unsigned short m_usLength;   // +0x08
    unsigned short m_usMaxLength;// +0x0a
};


// Scratch space kept by the original implementation.
struct ScratchBuffer
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i12;
    int m_i16;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i32;
    int m_i36;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i52;
    int m_i56;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i72;
    int m_i76;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i92;
    int m_i96;
    int m_i100;
};

}  // namespace fnv_00c45a80

namespace fnv_00c45ae0 {

struct FUN_00c45b20_Class {
};


struct FUN_00c45ae0_LocalState {
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
};

}  // namespace fnv_00c45ae0

// AppendElement @ 0x00c45e00 (75 bytes) - member, 1 stack parameter (ret 4).
// Add(element) of an NiTArray-style growable array:
//   +0x00 vtable, +0x04 m_pBase, +0x08 m_usMaxSize (u16),
//   +0x0A m_usSize (u16), +0x0C m_usESize (u16), +0x0E m_usGrowBy (u16).
// index = m_usSize; if (index >= m_usMaxSize) grow via FUN_00c45b20
// (m_usGrowBy + index); store element at index via SetSlot; return index.

struct FUN_00c45e00_class
{
    int unk00;                  // +0x00 vtable pointer (not accessed here)
    int unk04;                  // +0x04 element base pointer (not accessed here)
    unsigned short m_usMaxSize; // +0x08 allocated capacity
    unsigned short m_usSize;    // +0x0A live element count
    unsigned short m_usESize;   // +0x0C (not accessed here)
    unsigned short m_usGrowBy;  // +0x0E grow increment

                            // ensure capacity
      // store element
    unsigned int AppendElement(uintptr_t uiElement);
};

namespace fnv_00c46420 {
struct S_00c46420_Callback
{
    virtual void unk00();
    virtual void Slot1();
    void* unk08;
};

struct S_00c46420_Class
{
    S_00c46420_Callback* unk00;

    void* FUN_00c46420(unsigned int flags);
};

struct S_00aa4060_Class
{
    void FUN_00aa4060(void*);
};


extern "C" void* DAT_00fdf1c4;

extern "C" void __cdecl FUN_00ae9290();

// @fnv 0x00c46420
void* S_00c46420_Class::FUN_00c46420(unsigned int flags)
{
    if (flags & 2)
    {
        fnv::crt::vector_destructor(
            this,
            4,
            reinterpret_cast<int*>(this)[-1],
            (void (*)(void *))(FUN_00ae9290)
        );

        if (flags & 1)
        {
            (*reinterpret_cast<::fnv_00c46420::S_00aa4060_Class *>(&::g_memoryManager)).FUN_00aa4060(
                reinterpret_cast<char*>(this) - 4
            );
        }

        return reinterpret_cast<char*>(this) - 4;
    }

    if (this->unk00 != 0)
    {
        S_00c46420_Callback* p = this->unk00;

        if (reinterpret_cast<int (*)(void*)>(DAT_00fdf1c4)(
                reinterpret_cast<char*>(&p->unk08)) == 0)
        {
            p->Slot1();
        }
    }

    if (flags & 1)
    {
        (*reinterpret_cast<::fnv_00c46420::S_00aa4060_Class *>(&::g_memoryManager)).FUN_00aa4060(this);
    }

    return this;
}
}  // namespace fnv_00c46420

namespace fnv_00c464c0 {

class FUN_00c464c0_child {
public:
};

class AudioPool {
public:
    void FUN_00aa4060(void* apMemory);
};

struct FUN_00c464c0_cls {
    int m_vptr;
    FUN_00c464c0_child* m_04;

    FUN_00c464c0_cls* FUN_00c464c0(unsigned int acFlags);
};

// @fnv 0x00c464c0
FUN_00c464c0_cls* FUN_00c464c0_cls::FUN_00c464c0(unsigned int acFlags)
{
    m_vptr = (intptr_t)&::DAT_010c1c5c;
    FUN_00c464c0_child* pObj = m_04;
    FUN_00c464c0_child* pChild_;
    FUN_00c464c0_child* pExtra;
    FUN_00c464c0_child* pSecond = pObj;
    pChild_ = pSecond;
    (pChild_ != 0) ? reinterpret_cast<::fnv_00c46420::S_00c46420_Class *>((pChild_))->FUN_00c46420(3) : 0;
    if (acFlags & 1) {
        (*reinterpret_cast<::fnv_00c464c0::AudioPool *>(&::g_memoryManager)).FUN_00aa4060(this);
    }
    return this;
}
}  // namespace fnv_00c464c0


struct S_00c46530_Class {
    void* m_vtbl;
    void* m_result;
    unsigned short m_uiItemCount;
    unsigned short m_field_0a;
    unsigned short m_field_0c;
    unsigned short m_field_0e;

    S_00c46530_Class* FUN_00c46530(unsigned short param1,
                                               unsigned short param2);
};

// Sets the vtable, stores param1 and param2, zeroes two fields, and allocates m_result for param1 entries when param1 is greater than zero.
// Initializes the object by setting the vtable, storing param1 and usValue, zeroing two fields, and allocating m_result via FUN_00c46170 when param1 is positive.
// @fnv 0x00c46530
S_00c46530_Class*
S_00c46530_Class::FUN_00c46530(unsigned short param1, unsigned short usValue)
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    this->m_vtbl = &DAT_010c1c5c;
    this->m_uiItemCount = param1;
    this->m_field_0e = usValue;
    this->m_field_0a = 0;
    this->m_field_0c = 0;

    if (this->m_uiItemCount > 0) {
        this->m_result = FUN_00c46170(this->m_uiItemCount);
    } else {
        this->m_result = 0;
    }

    return this;
}

class FUN_00c46860_cls {
public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    float m_18;

    bool FUN_00c46860(FUN_00c46860_cls* other);
};

// Calls unkCheck on other and, if it passes, returns whether m_18 equals other's m_18.
// @fnv 0x00c46860
bool FUN_00c46860_cls::FUN_00c46860(FUN_00c46860_cls* other) {
    bool ok = reinterpret_cast<::MyIsEqual *>(this)->FUN_00c31830((::NiObject *)(other));
    if (ok) {
        FUN_00c46860_cls* p = other;
        float a = m_18;
        ok = (a == p->m_18) ? 1 : 0;
    }
    return ok;
}


struct FNVPad18
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct FNVPad1C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct FNVVec3B
{
    float x;
    float y;
    float z;
};

extern FNVVec3B DAT_01202e68;


// Scales a1 by DAT_01017a40, builds a vector from it and a2, combines them, and stores the result in DAT_01202e68.
// @fnv 0x00c468c0
void __cdecl FUN_00c468c0(float a1, float a2)
{
    FNVVec3B da7;
    {
    FNVVec3B erdl2;
    FNVVec3B acgt2;
    FNVPad18 eui;
    FNVPad1C tlp;

    a1 = (float)((double)a1 * ::g_d100);
    da7.x = 0.0f;
    da7.y = a1;
    da7.z = 0.0f;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(erdl2))->FUN_004a0c90(a2);
    DAT_01202e68 = *((::FNVVec3B *)(::FUN_004b3ae0((::NiPoint3 *)(::FNVVec3B *)(&acgt2), (*(const ::NiPoint3 *)(&da7)), (const float *)(::FNVVec3B *)(&erdl2))));
    }}

class C46D60Stream {
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
};

class C46D60Base {
public:
};

class C46D60Node : public C46D60Base {
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
    void* m_pkChild;

    void FUN_00c46d60(C46D60Stream& kStream);
};

// @fnv 0x00c46d60
void C46D60Node::FUN_00c46d60(C46D60Stream& kStream) {
    reinterpret_cast<::NodeA5E8 *>(this)->FUN_00a5e880((::NiStreamA5E8 &)(kStream));
    void* pkChild = m_pkChild;
    kStream.SaveLinkID(pkChild);
}

struct FUN_00c46da0_class : BaseForCall {
    bool FUN_00c46da0(NiObject* other);
};
// Calls FUN_00a5e600 on other, then returns whether the int at offset 0xAC matches between this and other.
// @fnv 0x00c46da0
bool FUN_00c46da0_class::FUN_00c46da0(NiObject* other)
{
    bool result = reinterpret_cast<::NiNodeEq *>(this)->FUN_00a5e600((::NiAVObject *)(other));
    NiObject* comparison = other;
    if (static_cast<int>(static_cast<unsigned char>(static_cast<int>(
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xAC) ==
        *reinterpret_cast<int*>(reinterpret_cast<char*>(comparison) + 0xAC))))) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

void* __cdecl FUN_00aa13e0(size_t size);

struct NewObject_b9649 {
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
    NewObject_b9649();
};

// Allocates and constructs a NewObject_b9649 via its operator new and returns the pointer.
// @fnv 0x00c46df0
NewObject_b9649* CreateNewObject() {
    return new NewObject_b9649();
}

struct UpdateContext {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
 int unk80,unk84,unk88,unk8c;
 int state;
};
struct BoundBase {
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
 virtual bool Test(void*);
};
struct BoundTester : BoundBase {
 int unk04;
 int state;
};
struct BoundReference { int unk00,unk04,unk08; BoundTester* object; };
struct UpdateChild {  };
struct UpdateOwner {
 int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c;
 int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
 int unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
 int unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
 int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
 UpdateChild** children;
 unsigned short capacity,count,enabled,unkAA;
 BoundReference* reference;
 int replacement;
 void FUN_00c46f60(UpdateContext*);
};
// @fnv 0x00c46f60
void UpdateOwner::FUN_00c46f60(UpdateContext* pContext) {
 UpdateChild** slot;
 int replacementState2;
 BoundTester* cacheObject5;
 BoundReference* cacheReference;
 BoundTester* volatile _unknownObject;
 BoundReference* unknownReference;
 BoundTester* volatile specialObject2;
 BoundReference* specialReference6;
 int kRequestState;
 BoundTester* aReadObject;
 BoundReference* readReference8;
 BoundReference* checkReference;
 UpdateChild* child;
 unsigned int i;
 int state2;
 bool accepted9;
 int oldState9;
 UpdateContext* context4;

 context4=0;
 oldState9=0;
 if (!enabled) return;
 context4=pContext;
 oldState9=context4->state;
 accepted9=true;
 if (oldState9!=3 && oldState9!=1) {
  checkReference=reference;
  if (checkReference) {
   readReference8=reference;
   aReadObject=readReference8->object;
   state2=aReadObject->state;
   kRequestState=context4->state;
   if (kRequestState==4) {
    specialReference6=reference;
    specialObject2=specialReference6->object;
    accepted9=specialObject2->Test(reinterpret_cast<char*>(&pContext->unk2c));
    state2=accepted9?1:2;
   }
   switch(state2) {
   case 0:
    unknownReference=reference;
    _unknownObject=unknownReference->object;
    accepted9=_unknownObject->Test(reinterpret_cast<char*>(&pContext->unk2c));
    cacheReference=reference;
    cacheObject5=cacheReference->object;
    cacheObject5->state=accepted9?1:2;
    break;
   case 1: accepted9=true;break;
   default:accepted9=false;break;
   }
  }
 }
 if (!accepted9) return;
 if (oldState9!=3) {
  replacementState2=replacement;
  context4->state=replacementState2;
 }
 for (i=0;i<count;i++) {
  slot=&children[i];
  child=*slot;
  if (child) reinterpret_cast<::S_00a59e00 *>((child))->FUN_00a59e00((::S_00a59e00_Arg *)(pContext));
 }
 context4->state=oldState9;
}

// Stand-in model of CheckProcStateAndPlane (0x00c47150, 252 bytes) - an /Od member function.
//
// The original is:
//   bool CheckProcStateAndPlane(Vec3 pt, Proc* proc, Plane* plane)
//   {
//       if (proc->unk90 == 3 || proc->unk90 == 1) return true;
//       if (plane) {
//           obj.FUN_0045c620();                  // 0x0045c620
//           plane->FUN_00c33870(pt, &obj);      // 0x00c33870
//           Target* t = this->unkAC->unk0c;
//           if (t->v40(&obj)) {                 // vtable slot 0xA0
//               Target* u = this->unkAC->unk0c;
//               u->unk08 = 2;
//               return false;
//           }
//       }
//       return true;
//   }
//
// The local NAMES below are not arbitrary: under /Od the frame slot of every local is
// decided by the 16-bucket hash of its name, so the names are chosen to put each local on
// the frame slot the original uses (see attempts.txt).  The three dead int locals exist
// only to reserve the four unused 4-byte slots that the original's frame shows.

struct FNV_Vec3 {
    float x;
    float y;
    float z;
};

struct FNV_Proc {
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
};

struct GeometryPoint
{
    float x, y, z;
    GeometryPoint()
    {}
};
struct FUN_00a699d0
{
    GeometryPoint normal;
    float distance;
    FUN_00a699d0();
    FUN_00a699d0(const GeometryPoint*, const GeometryPoint*, const GeometryPoint*);
    int ClassifyPoint(const GeometryPoint* point)
    {
        float value = normal.x * point->x + normal.y * point->y + normal.z * point->z - distance;
        if (value < 0.0)
            return 2;
        else if (value > 0.0)
            return 1;
        else
            return 0;
    }
};

struct FUN_0045c620
{
    FUN_00a699d0 planes[6];
    int unk60;
    FUN_0045c620()
    {
        unk60 = 0x3f;
    }
    __forceinline void ClearPlane(int bit)
    {
        unk60 &= ~(1 << bit);
    }
};

struct FNV_Local
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
    void FUN_0045c620();
};

struct FNV_Target {
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
    virtual bool v40(FNV_Local* pObj);
    int unk04;
    int unk08;
};

struct FNV_Holder {
    int unk00;
    int unk04;
    int unk08;
    FNV_Target* unk0c;
};

struct FNV_Plane {
    void FUN_00c33870(FNV_Vec3 pt, FNV_Local* pObj);
};

struct FNV_Owner {
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
    FNV_Holder* unkAC;
    bool CheckProcStateAndPlane(FNV_Vec3 pt, FNV_Proc* proc, FNV_Plane* plane);
};

// @fnv 0x00c47150
bool FNV_Owner::CheckProcStateAndPlane(FNV_Vec3 vecPoint, FNV_Proc* proc, FNV_Plane* plane)
{
    int F;                       // dead local, frame filler only
    int C;                       // dead local, frame filler only
    int EG;                      // dead local, frame filler only
    FNV_Local B;                 // the 0x64-byte object at [ebp-0x70]

    FNV_Proc* J = proc;          // the copied pointer, [ebp-4]
    int K;                       // the first state,  [ebp-0x74]
    int b;                       // the second state, [ebp-0x78]
    if ((K = J->unk90) == 3 || (b = J->unk90) == 1) return true;
    if (plane) {
        new ((void *)&(B)) ::FUN_0045c620();        // the object's initialiser, 0x0045c620
        plane->FUN_00c33870(vecPoint, &B);
        FNV_Holder* A = this->unkAC;             // [ebp-0x84]
        FNV_Target* volatile c = A->unk0c;      // [ebp-0x88]
        if (c->v40(&B)) {
            FNV_Holder* I = this->unkAC;         // [ebp-0x8c]
            FNV_Target* L = I->unk0c;            // [ebp-0x90]
            L->unk08 = 2;
            return false;
        }
    }
    return true;
}

struct TargetCls {
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
    virtual void v35(int a);
};

struct OwnerCls {
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    int unk34;
    int unk35;
    int unk36;
    int unk37;
    int unk38;
    int unk39;
    int unk40;
    int unk41;
    int unk42;
    TargetCls* m_pFlagTarget;
    void CallVirtual35(int a);
};

// @fnv 0x00c47530
void OwnerCls::CallVirtual35(int aiValue)
{
    TargetCls* volatile pTarget = m_pFlagTarget;
    pTarget->v35(aiValue);
}

struct Rec64 {
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
};
struct Vec12 { int x; int y; int z; };
struct Elem0C { int a; int b; int c; };
struct ArrRec64 {
    void* vtbl;
    Rec64* m_pData;
    int unk08;
    unsigned int m_uiSize;
};
struct ArrElem0C {
    void* vtbl;
    Elem0C* m_pData;
    int unk08;
    unsigned int m_uiSize;
};
struct Obj_c477f0 {
    unsigned char b00;
    ArrRec64 m_kArr04;
    ArrElem0C m_kArr14;
    int unk24;
    int unk28;
    int unk2C;
    Rec64 m_kRec30;
    Vec12 m_kVec94;
    void CopyTo(Obj_c477f0* dst);
};

class FUN_00c47980_sub
{
public:
};

class FUN_00c47980_arg
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
};

class FUN_00c47980_vec3
{
public:
    int x;
    int y;
    int z;
};

class FUN_00c47980_cls
{
public:
    void InitFromArg(FUN_00c47980_arg* a1);

    unsigned char m_00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_24;
    int m_28;
    int m_2c;
    FUN_00c47980_sub m_30;
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
    FUN_00c47980_vec3 m_94;
    unsigned char m_A0;
};

// @fnv 0x00c47980
void FUN_00c47980_cls::InitFromArg(FUN_00c47980_arg* a1)
{
    if (a1 != 0)
    {
        reinterpret_cast<::FrustumPlanes::Planes *>(&(m_30))->SetFromFrustum((const ::FrustumPlanes::Frustum *)(void *)((void*)&a1->unkDC), (const ::FrustumPlanes::Transform *)(void *)((void*)&a1->unk68));
        m_94 = *(FUN_00c47980_vec3*)&a1->unk8C;
    }
    m_24 = 0;
    m_28 = 0;
    m_00 = 0;
    m_2c = 0;
    m_A0 = 0;
}

struct Sub_c47ae0
{
    int unk00;
    void FUN_00c4a1e0(int, bool);
};

struct FUN_00c47ae0_cls
{
    unsigned char m_00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Sub_c47ae0 m_14;
    char* m_18;
    int unk1C;
    int m_20;
    int unk24;
    int m_28;
    void FUN_00c47ae0();
};

// @fnv 0x00c47ae0
void FUN_00c47ae0_cls::FUN_00c47ae0()
{
    int cap = m_20;
    if (m_28 + 1 >= cap)
    {
        int a = m_20;
        reinterpret_cast<::FUN_00c4a1e0 *>(&(m_14))->SetSize(a + 10, true);
    }
    m_00 = 0;
    *(int*)(m_18 + m_28 * 12) = 6;
    m_28 = m_28 + 1;
}

struct NavEntryItem {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_60;
};

class NavAllocator
{
  public:
    int* Alloc(unsigned int size, unsigned int tag);
};

class NavHolder {
public:
};


class NavEntryOwner {
public:
    int unk00;
    int unk04;
    NavEntryItem* m_08;
    int unk0C;
    int m_10;
    int unk14, unk18, unk1C, unk20;
    int m_24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C;
    int m_90;

    int* BuildEntryValueArray();
};

// @fnv 0x00c49050
int* NavEntryOwner::BuildEntryValueArray() {
    NavAllocator* alloc7 = ((::NavAllocator *)(reinterpret_cast<::MemoryManager *>(&((*reinterpret_cast<::NavHolder *>(&::g_memoryManager))))->GetGeneralAllocator()));
    int count = this->m_10;
    int* result5 = ((int *)(reinterpret_cast<::FUN_00aa54a0_s *>((alloc7))->FUN_00aa54a0(count * 4, ::DAT_010a2720)));
    int firstB = this->m_90;
    result5[0] = firstB;
    int i6;
    int limit;
    NavEntryItem* item;
    int value7;
    for (i6 = 1; i6 < this->m_24 + 1 && i6 < (limit = this->m_10); i6++) {
        item = this->m_08 + (i6 - 1);
        value7 = item->m_60;
        result5[i6] = value7;
    }
    return result5;
}

namespace fnv_00c49100 {
struct FUN_00aa42e0_holder;

struct GlobalGetter
{
};


class ActorTable
{
public:
    unsigned char unk00[8];
    char* m_08;
    unsigned char unk0C[4];
    int m_10;
    unsigned char unk14[0x10];
    int m_24;
    unsigned char unk28[0x68];
    int m_90;

    void SetActorList(int* list);
};

struct FUN_00aa42e0_holder
{
};

// @fnv 0x00c49100
void ActorTable::SetActorList(int* list)
{
    int _first = *list;
    m_90 = _first;
    int i;
    int count4;
    for (i = 1; i < m_24 + 1 && i < (count4 = m_10); i++)
    {
        int value7 = list[i];
        char* entry = m_08 + (i - 1) * 100;
        *(int*)(entry + 0x60) = value7;
    }
    FUN_00aa42e0_holder* holder = ((::fnv_00c49100::FUN_00aa42e0_holder *)(reinterpret_cast<::MemoryManager *>((reinterpret_cast<GlobalGetter*>(&(*reinterpret_cast<unsigned char *>(&::g_memoryManager)))))->GetGeneralAllocator()));
    reinterpret_cast<::SHStub *>((holder))->FUN_00aa5610(list);
}
}  // namespace fnv_00c49100

class NiPoint3 { public: float x,y,z; public:
    char *FUN_00a59af0(const char *);
public:
    bool FUN_004390c0(const ::NiPoint3 &);
    float GetLengthSquared();
    static const ::NiPoint3 ZERO;
};
struct SSNode {
};
struct DecisionNode { int type; int trueIndex; int falseIndex; };
struct VolumeRecord {
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
};
struct DecisionTree {
 int unk00;
 int unk04;
 VolumeRecord* volumes;
 int unk0c;
 int unk10;
 int unk14;
 DecisionNode* nodes;
 int unk1c;
 int unk20;
 int unk24;
 int nodeCount;
 int rootIndex;
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
 bool skipBounds;
 bool EvaluateQuery(SSNode* query);
};
// @fnv 0x00c49560
bool DecisionTree::EvaluateQuery(SSNode* query) {
 VolumeRecord* result = 0;
 bool bResult = true;
 if (!skipBounds)
  bResult = reinterpret_cast<::fnv_00c344c0::SSNode *>((query))->FUN_00c344c0(&unk30, (*(const ::fnv_00c344c0::NiPoint3 *)(&unk94)));
 if (bResult && nodeCount > 0) {
  int index = rootIndex;
  while (nodes[index].type != 2 && nodes[index].type != 3) {
   bool passed = false;
   switch (nodes[index].type) {
   case 7: {
    DecisionNode* next = &nodes[index+1];
    result = &volumes[next->type];
    passed = reinterpret_cast<::RectangleClip *>((query))->FUN_00c33cf0((::ClipVolume *)(result), 0, ::NiPoint3::ZERO);
    break;
   }
   case 8: {
    DecisionNode* next = &nodes[index+1];
    result = &volumes[next->type];
    passed = !reinterpret_cast<::FUN_00c347d0_cls *>((query))->FUN_00c347d0((::FUN_00c347d0_Obj *)(result));
    break;
   }
   }
   index = passed ? nodes[index].trueIndex : nodes[index].falseIndex;
  }
  bResult = nodes[index].type == 2;
 }
 return bResult;
}

extern int DAT_010c1e9c;

struct FUN_00c4a1b0_cls
{
    int m_vptr;

    FUN_00c4a1b0_cls* FUN_00c4a1b0();
};

// Sets m_vptr to &DAT_010c1e9c, calls FUN_00c4a5a0 with 0, 0, and returns this.
// @fnv 0x00c4a1b0
FUN_00c4a1b0_cls* FUN_00c4a1b0_cls::FUN_00c4a1b0()
{
    // two spare scratch words; they only shape the stack frame of the
    // original routine.
    int iScratch0;
    int iScratch1;

    m_vptr = reinterpret_cast<intptr_t>(&DAT_010c1e9c);
    reinterpret_cast<FUN_00c4a5a0_class*>(this)->FUN_00c4a5a0(0, 0);
    return this;
}

class CachedRef_b5611 {
public:
    virtual void v00();
    virtual void* v01(unsigned int a);
    virtual void v02(void* a);
    virtual void* v03(void* b, unsigned int a);
    void UpdateCachedRef(unsigned int a1, unsigned int a2);

    void* m_pCachedReference;
    unsigned int unk08;
    unsigned int m_key;
};

// @fnv 0x00c4a420
void CachedRef_b5611::UpdateCachedRef(unsigned int uiKey, unsigned int a2)
{
    if (m_pCachedReference != 0) {
        if (a2 == m_key) {
            m_pCachedReference = v03(m_pCachedReference, uiKey);
        } else {
            unsigned int uiUnusedA;
            unsigned int uiUnusedB;
            void* tmp = v01(uiKey);
            reinterpret_cast<::FUN_00c4a640_class *>(this)->FUN_00c4a640((char *)(tmp), (char *)(m_pCachedReference), a2);
            v02(m_pCachedReference);
            m_pCachedReference = 0;
            m_pCachedReference = tmp;
        }
    } else {
        m_pCachedReference = v01(uiKey);
        m_key = uiKey;
    }
}

struct FUN_00c4a6e0_cls
{
    int unk00;
    bool ProcessEntries(struct CallerObj_b3918* a1, struct EntrySet_b3918* a2);
};

struct CallerObj_b3918
{
    int ClassifySphereAgainstPlane(void* p);
};

struct EntrySet_b3918
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
    unsigned int m_60;
};

// Iterates the six bits of m_60, calls ClassifySphereAgainstPlane on each 16-byte entry, clears bits returning 1, and returns false if any returns 2.
// @fnv 0x00c4a6e0
bool FUN_00c4a6e0_cls::ProcessEntries(CallerObj_b3918* apCaller, EntrySet_b3918* apEntries)
{
    int i;
    int tmp;
    int code;
    (void)tmp;
    if (!(bool)(apEntries->m_60 != 0))
    {
        return true;
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            if ((bool)((apEntries->m_60 & (1u << i)) != 0))
            {
                code = reinterpret_cast<::B_004b6100 *>((apCaller))->ClassifySphereAgainstPlane((::NiPlane_004b6100 *)(void *)((char*)apEntries + i * 16));
                if (code == 2)
                {
                    break;
                }
                if (code == 1)
                {
                    apEntries->m_60 &= ~(1u << i);
                }
            }
        }
        if (i == 6)
        {
            return true;
        }
    }
    return false;
}

namespace fnv_00c4a8b0 {
struct ParticleAllocator {
};

struct ParticleArrayAllocator {
    void* AllocateParticleArray(void* memory, unsigned int count);
};

// Allocates count particles of 100 bytes each from the particle allocator and returns the resulting pointer.
// @fnv 0x00c4a8b0
void* ParticleArrayAllocator::AllocateParticleArray(void* memory, unsigned int count)
{
    return reinterpret_cast<::MemoryManager *>(&((*reinterpret_cast<::fnv_00c4a8b0::ParticleAllocator *>(&::g_memoryManager))))->Reallocate(memory, count * 100);
}
}  // namespace fnv_00c4a8b0

struct FUN_00c4a8e0
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual ~FUN_00c4a8e0();
};

// Destructor that calls ReleaseBuffer with argument 1 on this object.
// @fnv 0x00c4a8e0
FUN_00c4a8e0::~FUN_00c4a8e0()
{
    int unk04;
    ((FUN_00c4a9c0_class*)this)->ReleaseBuffer(1);
}

struct FUN_00c4b150_cls {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C;
    int m_30;
    void CallIfNotFlagged(int a1, int a2);
};
// Calls FUN_00a5dd70 with the two arguments unless bit 0 of m_30 is set.
// @fnv 0x00c4b150
void FUN_00c4b150_cls::CallIfNotFlagged(int a1, int a2)
{
    if (!(bool)((m_30 & 1) != 0 ? 1 : 0)) {
        reinterpret_cast<::NiNode *>(this)->UpdateDownwardPass((*(::NiUpdateData *)(a1)), a2);
    }
}

struct S_c4b190_Base {  };
struct S_c4b190 : S_c4b190_Base {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30;
    void CallBaseIfFlagClear(int a, int b);
};
// Calls the base FUN_00a5ded0 with a and b when bit 0 of unk30 is clear.
// @fnv 0x00c4b190
void S_c4b190::CallBaseIfFlagClear(int a, int b) {
    if (!(unsigned char)(-((unk30 & 1) != 0 ? -1 : 0))) reinterpret_cast<::NiNode *>(this)->UpdateSelectedDownwardPass((*(::NiUpdateData *)(a)), b);
}

struct S_00c4b1d0_Cls {
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
    unsigned int flags;
    void FUN_00c4b1d0(int a, int b);
};
// If the flags bit 0 is clear, forwards a and b to FUN_00a5e1f0.
// @fnv 0x00c4b1d0
void S_00c4b1d0_Cls::FUN_00c4b1d0(int a, int b) {
    if (!(bool)(flags & 1 ? 1 : 0)) {
        ::FUN_00a5e1f0((::NiNode *)this, a, (*(::NiUpdateData *)(b)), {});
    }
}

class FUN_00c4b470_owner {
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
    virtual int v35(void** a2);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual int v39(void** a2);
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    unsigned int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    unsigned int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    unsigned int unk64, unk68, unk6C, unk70, unk74;
    FUN_00c4b470_owner* unk78;
};


// Looks up a node via FUN_00a5c570, calls its unk78 object's v35 with a2, and falls back to a1->v39 when a3 is nonzero.
// @fnv 0x00c4b470
int __cdecl FUN_00c4b470(FUN_00c4b470_owner* pOwner, void** a2, unsigned char bFallback)
{
    FUN_00c4b470_owner* node7;
    int r7;
    void* cur;
    FUN_00c4b470_owner* m78;
    FUN_00c4b470_owner* obj;
    if (pOwner == 0 || (cur = *a2) == 0) {
        return 0;
    }
    node7 = ((::FUN_00c4b470_owner *)(reinterpret_cast<::MyHost *>((pOwner))->FUN_00a5c570((const ::MyRTTI *)(void *)(&(*reinterpret_cast<char *>(&::g_011f36ac))))));
    if (node7 != 0) {
        m78 = node7->unk78;
        obj = m78;
        r7 = obj->v35(a2);
        if (r7 != 0) {
            return r7;
        }
    }
    if (bFallback != 0) {
        return pOwner->v39(a2);
    }
    return 0;
}


struct FUN_00c4cdc0_child
{
};

struct FUN_00c4cdc0_cls
{
    FUN_00c4cdc0_child* m_pChildObject;
    void FUN_00c4cdc0();
};

struct FUN_00c4cf00_Entry {
    int m_iA;
    int m_iB;
    float m_fC;
};

struct FUN_00c4cf00_Data {
    int unk00;
    FUN_00c4cf00_Entry* m_pItems;
};

struct FUN_00c4cf00_cls {
    FUN_00c4cf00_Data* m_pData;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_iArrayLength;

    void FUN_00c4cf00();
};

// @fnv 0x00c4cf00
void FUN_00c4cf00_cls::FUN_00c4cf00()
{
    for (int i = 0; i < m_iArrayLength; i++) {
        FUN_00c4cf00_Entry tmp = m_pData->m_pItems[i];
        tmp.m_fC = 0.0f;
        {
            FUN_00c4cf00_Data* pData = m_pData;
            pData->m_pItems[i] = tmp;
        }
    }
}

struct S_00c4dcf0 {
    int GetPointSide(float a, float b, float c, float d, float e, float f, float g, float h, float i);
};
// @fnv 0x00c4dcf0
int S_00c4dcf0::GetPointSide(float afX1, float afY1, float afUnused1, float afX2, float afY2, float afUnused2, float afX3, float afY3, float afUnused3) {
    float r = (afX1 - afX2) * (afY3 - afY1) - (afY1 - afY2) * (afX3 - afX1);
    if (r < 0.0) {
        return 1;
    } else if (r > 0.0) {
        return -1;
    } else {
        return 0;
    }
}

struct S_00c4e0a0_Data {
    int unk00;
    unsigned short* m_pValues;
};

struct S_00c4e0a0_Class {
    int unk00;
    int unk04;
    S_00c4e0a0_Data* m_pData;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int m_iArrayLength;

    bool ContainsMatchingTriple(int arg1, int arg2);
};

struct S_00c4e900_Elem {
    int a;
    int b;
    int c;
};
struct S_00c4e900_Arr {
    int unk00;
    S_00c4e900_Elem* data;
    int count;
    void ReverseElements();
};
// Reverses the array in place by swapping elements from both ends toward the middle.
// @fnv 0x00c4e900
void S_00c4e900_Arr::ReverseElements() {
    int i = 0;
    int iRight = count - 1;
    for (; i < iRight; i++, iRight--) {
        S_00c4e900_Elem tmp = data[i];
        S_00c4e900_Elem* p3 = &data[iRight];
        data[i] = *p3;
        data[iRight] = tmp;
    }
}

extern unsigned char DAT_012030a4;

struct S_00c4ed70_Object {
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018(int);
};

struct S_00c4ed70_Class {
    S_00c4ed70_Object* m_pObject;
    bool FUN_00c4ed70();
};

void S_00c4ed70_Object::vfn_0000() {}
void S_00c4ed70_Object::vfn_0004() {}
void S_00c4ed70_Object::vfn_0008() {}
void S_00c4ed70_Object::vfn_000c() {}
void S_00c4ed70_Object::vfn_0010() {}
void S_00c4ed70_Object::vfn_0014() {}
void S_00c4ed70_Object::vfn_0018(int) {}

// If DAT_012030a4 is unset, sets it to 1, calls vfn_0018(2) on m_pObject, and returns true; otherwise returns false.
// @fnv 0x00c4ed70
bool S_00c4ed70_Class::FUN_00c4ed70() {
    if (DAT_012030a4) {
        return false;
    } else {
        DAT_012030a4 = 1;
    }

    m_pObject->vfn_0018(2);
    return true;
}

// Candidate v2 for FUN_00c4edb0 (zai_04).
// Same guard logic; callee hypothesis: virtual member taking one int,
// called as m_p->vfn(1). MSVC passes this as the first stack argument
// (push 1 then push m_p), vtable slot 6 (+0x18), no ecx requirement at call.

extern unsigned char DAT_012030a4;

struct FUN_00c4edb0_Virt {
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018(int one);
};

struct FUN_00c4edb0_Class {
    FUN_00c4edb0_Virt* m_p;
    void FUN_00c4edb0();
};

// If DAT_012030a4 is set, clears it and calls vfn_0018(1) on m_p.
// @fnv 0x00c4edb0
void FUN_00c4edb0_Class::FUN_00c4edb0() {
    if (DAT_012030a4) {
        DAT_012030a4 = 0;
        m_p->vfn_0018(1);
    }
}

struct S_00c4edf0_Obj {
    virtual void vfn00(); virtual void vfn04(); virtual void vfn08(); virtual void vfn0c();
    virtual void vfn10(); virtual void vfn14(); virtual void vfn18();
    virtual int vfn1c(int, int, int);
};
struct S_00c4edf0_cls {
    S_00c4edf0_Obj* unk00;
    bool FUN_00c4edf0(std::intptr_t a1, bool a2);
};
// Calls vfn1c on unk00 with a1, 4 and a flag derived from a2, returning true when the call returns 0.
// @fnv 0x00c4edf0
bool S_00c4edf0_cls::FUN_00c4edf0(std::intptr_t a1, bool abFlag)
{
    int flag = 0;
    if (abFlag)
        flag = 1;
    int r = unk00->vfn1c(a1, 4, flag);
    if (r == 0)
        return true;
    return false;
}

struct DispatchObject {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void FunctionAtSlot4();
    virtual void FunctionAtSlot5();
    virtual void FunctionAtSlot6();
    virtual int Execute(int code, int mode, int flag);
};
struct DispatchOwner {
    DispatchObject* object;
    bool FUN_00c4ee40(std::intptr_t code, unsigned char enabled);
};
// Forwards code, mode 4 and a 0/1 flag derived from enabled to object->Execute and returns true when it returns 0.
// @fnv 0x00c4ee40
bool DispatchOwner::FUN_00c4ee40(std::intptr_t code, unsigned char enabled) {
    int flag = 0;
    int result;
    if (enabled) flag = 1;
    result = object->Execute(code, 4, flag);
    if (result == 0) return true;
    return false;
}

namespace fnv_00c503d0 {
struct FUN_00a5ecb0 {
 virtual void v0();
 ~FUN_00a5ecb0();
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
 FUN_00a5ecb0(unsigned int);
};
struct WorkerMemory {  };
struct WorkerTask { unsigned int value; };
struct WorkerTaskManager {  };
struct FUN_00c503d0 : FUN_00a5ecb0 {
    unsigned int* data;
    unsigned int count;
    WorkerTask* task;
    FUN_00c503d0();
};
// @fnv 0x00c503d0
FUN_00c503d0::FUN_00c503d0() : FUN_00a5ecb0(0) {
    count = 10;
    void* allocated = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00c503d0::WorkerMemory *>(&::g_memoryManager))))->FUN_00aa3e40(40);
    data = (unsigned int*)allocated;
    unsigned int result = count * 4;
    void* destination = data;
    std::memset(destination,-1,result);
    WorkerTask* storage = (WorkerTask*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00c503d0::WorkerMemory *>(&::g_memoryManager))))->FUN_00aa3e40(4);
    WorkerTask* size = storage ? (storage->value = 0, storage) : 0;
    task = size;
    reinterpret_cast<::BSWin32TaskletManager *>(&((*(::fnv_00c503d0::WorkerTaskManager *)&(::GetTaskletManager()))))->GetTaskletValue({});
}
}  // namespace fnv_00c503d0

struct FUN_00c509a0_Class {
    void FUN_00c509a0(int);
};

extern "C" char DAT_010c2580;


// FUN_00c50dd0: clears (releases) the pointer held by the second argument's
// smart-pointer holder. The two dword locals reproduce the original /Od frame
// layout (named locals above the hidden 'this' spill at [ebp-0xc]).
struct FUN_00c50dd0_Holder {
    void* FUN_0066b0d0(void* value);
};

struct FUN_00c50dd0_cls {
    int unk00;
    void FUN_00c50dd0(int* p1, FUN_00c50dd0_Holder* p2);
};

// @fnv 0x00c50dd0
void FUN_00c50dd0_cls::FUN_00c50dd0(int* pUnused, FUN_00c50dd0_Holder* pHolder)
{
    int m_iUnusedA;
    int m_iUnusedB;
    pHolder->FUN_0066b0d0(0);
}

struct S_00c50ea0_T {
    void FUN_0066b0d0(int a);
};
struct S_00c50ea0 {
    void FUN_00c50ea0(int a1, int a2, S_00c50ea0_T* a3);
};
// @fnv 0x00c50ea0
void S_00c50ea0::FUN_00c50ea0(int a1, int a2, S_00c50ea0_T* pTarget)
{
    int unk1;
    int unk2;
    pTarget->FUN_0066b0d0(0);
}

// Layout up to the item array (+0xa0) and the 16-bit item count (+0xa8).
struct FUN_00c50ec0_cls {
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
    int* m_pItems;
    unsigned int unkA4;
    unsigned short m_usElementCount;

    int FindItemIndex(intptr_t key);
};
// @fnv 0x00c50ec0
int FUN_00c50ec0_cls::FindItemIndex(intptr_t key) {
    unsigned int n = m_usElementCount;
    unsigned int i;
    for (i = 0; i < n; i++) {
        int* pItem = &m_pItems[i];
        int item = *pItem;
        int value = item;
        if (value == key) {
            return i;
        }
    }
    return -1;
}

struct NiRTTI { const char* m_pcName; const NiRTTI* m_pBaseRTTI; };



struct NiNodeStub;

struct NiAVObjectStub {
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNodeStub* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual int IsParticleSystem();
    int unk04;
    const char* m_pcName;
};

struct EmitterModifier : NiAVObjectStub {
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    EmitterModifier* m_pkNext;
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
    int m_iTarget;
};

struct MasterPSys : NiAVObjectStub {
    EmitterModifier* m_pkModifiers;
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
    bool m_bFlag;
};

struct NiNodeStub : NiAVObjectStub {
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
    NiAVObjectStub** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};

// Recursively finds the multi-target emitter under a master particle system and sets its m_iTarget, warning if none is found.
// @fnv 0x00c51250
bool __cdecl SetParticleSystemTarget(NiAVObjectStub* pkObject, intptr_t iTarget)
{
    NiAVObjectStub* pkObj;
    unsigned int j;
    unsigned int uiChildren;
    NiNodeStub* pkNode;
    EmitterModifier* pkEmitter;
    EmitterModifier* pkMod;
    MasterPSys* pkMaster;

    if (!pkObject)
        return false;

    if (pkObject->IsParticleSystem())
    {
        {
            bool bIsMaster;
            if (!pkObject)
                bIsMaster = false;
            else
                bIsMaster = pkObject->GetRTTI() == &(*reinterpret_cast<const ::NiRTTI *>(&::g_012024e0));
            if (bIsMaster)
            {
                pkMaster = (MasterPSys*)pkObject;
                pkMaster->m_bFlag = true;
                {
                    EmitterModifier* pkCurrentObject = pkMaster->m_pkModifiers;
                    pkMod = pkCurrentObject;
                }
                while (pkMod)
                {
                    bool bIsEmitter;
                    if (!pkMod)
                        bIsEmitter = false;
                    else
                        bIsEmitter = pkMod->GetRTTI() == &(*reinterpret_cast<const ::NiRTTI *>(&::g_01203340));
                    if (bIsEmitter)
                    {
                        pkEmitter = pkMod;
                        pkEmitter->m_iTarget = iTarget;
                        return true;
                    }
                    else
                    {
                        EmitterModifier* pkNext = pkMod->m_pkNext;
                        pkMod = pkNext;
                    }
                }
            }
        }
        {
            const char* pcName = pkObject->m_pcName;
            ::FUN_005b5e40();
        }
        return false;
    }
    else
    {
        pkNode = pkObject ? pkObject->IsSceneNode() : 0;
        if (pkNode)
        {
            uiChildren = pkNode->m_usSize;
            for (j = 0; j < uiChildren; j++)
            {
                {
                    NiAVObjectStub** ppkSlot = &pkNode->m_pBase[j];
                    NiAVObjectStub* pkTmp = *ppkSlot;
                    pkObj = pkTmp;
                }
                if (pkObj)
                {
                    if (!SetParticleSystemTarget(pkObj, iTarget))
                        return false;
                }
            }
        }
    }
    return true;
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00c51590_cls {
    int unk00;


    FUN_00c51590_cls* FUN_00c51590(unsigned int acFlags);
};


namespace fnv_00c515d0 {
struct FNVHeap {
    void FUN_00aa4060(void* allocation);
};
extern "C" void __cdecl FUN_00c516d0();
extern "C" void FUN_00ec5fce(void* objects, unsigned int objectSize, unsigned int count, void (__cdecl *destructor)());

struct DynamicObject {
    void* FUN_00c515d0(unsigned int flags);
};
// @fnv 0x00c515d0
void* DynamicObject::FUN_00c515d0(unsigned int flags)
{
    if (flags & 2) {
        FUN_00ec5fce(this, 0x20, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) - 4), &FUN_00c516d0);
        if (flags & 1) {
            (*reinterpret_cast<::fnv_00c515d0::FNVHeap *>(&::g_memoryManager)).FUN_00aa4060(reinterpret_cast<char*>(this) - 4);
        }
        return reinterpret_cast<char*>(this) - 4;
    }
    reinterpret_cast<::FUN_00b00ec0 *>(this)->FUN_00b00ec0::~FUN_00b00ec0();
    if (flags & 1) {
        (*reinterpret_cast<::fnv_00c515d0::FNVHeap *>(&::g_memoryManager)).FUN_00aa4060(this);
    }
    return this;
}
}  // namespace fnv_00c515d0

struct FUN_00c516a0_Virtual {
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
    virtual void v41(void*, int);
};

struct FUN_00c516a0_Class {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00c516a0_Virtual* unk18;
    void* unk1C;

    void FUN_00c516a0();
};

// Calls the virtual method v41 on unk18 with unk1C and 0 as arguments.
// @fnv 0x00c516a0
void FUN_00c516a0_Class::FUN_00c516a0()
{
    unk18->v41(unk1C, 0);
}

struct Node_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0c();
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
    Node_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct ItemCtx_cls
{
};

struct FUN_00c53280_cls
{
    void UpdateMaxValue(Node_cls* a1, ItemCtx_cls* a2, unsigned int* out);
};

// @fnv 0x00c53280
void FUN_00c53280_cls::UpdateMaxValue(Node_cls* pNode, ItemCtx_cls* pContext, unsigned int* puiMax)
{
    unsigned int bestX = *puiMax;
    unsigned int local2;
    for (unsigned int i = 0; i < pNode->m_a6; i++) {
        Node_cls* item3;
        Node_cls** slot = pNode->m_a0 + i;
        Node_cls* cur4 = *slot;
        item3 = cur4;
        unsigned int local;
        unsigned int spare[5];
        if (item3 != 0 && item3->v0c()) {
            local = bestX;
            UpdateMaxValue(item3, pContext, &local);
            if (local > *puiMax) {
                *puiMax = local;
            }
        }
    }
    if (reinterpret_cast<::A54440Hash *>((pContext))->FUN_00a53c30((::A54440Manager *)(pNode), (::A54440Manager **)(unsigned int *)(&local2))) {
        if (local2 > *puiMax) {
            *puiMax = local2;
        }
    } else {
        reinterpret_cast<::HashTableBase *>((pContext))->InsertOrUpdate((uintptr_t)(pNode), *puiMax);
    }
}

// Stand-in model of the destructor at 0x00c53fa0 (an /Od member function of a
// polymorphic class with a non-trivial base).
//
// The original is:
//   push ebp / mov ebp,esp / push -1 / push <eh handler> / mov eax,fs:[0] / push eax
//   sub esp,0x10 / <security cookie> / lea eax,[ebp-0xc] / mov fs:[0],eax
//   mov dword ptr [ebp-0x1c], ecx      ; the 'this' home
//   mov eax,dword ptr [ebp-0x1c]
//   mov dword ptr [eax], 0x10c2a94     ; the class' own vftable
//   mov dword ptr [ebp - 4], 0         ; EH state 0
//   mov ecx,dword ptr [ebp-0x1c] / add ecx,0xc / mov dword ptr [ebp-0x18],ecx
//   mov edx,dword ptr [ebp-0x18] / mov dword ptr [edx], 0x10c2b2c
//   mov eax,dword ptr [ebp-0x18] / mov ecx,dword ptr [eax+4]
//   mov dword ptr [ebp-0x14], ecx
//   mov edx,dword ptr [ebp-0x14] / mov dword ptr [ebp-0x10], edx
//   mov eax,dword ptr [ebp-0x10] / push eax
//   mov ecx, 0x11f6238 / call 0xaa4060   ; g_memoryManager.Deallocate(...)
//   mov dword ptr [ebp - 4], -1        ; EH state -1
//   mov ecx,dword ptr [ebp-0x1c] / call 0xa7b300   ; the base destructor


struct FNV_Item;

struct FNV_MemoryManager {
    void Deallocate(void* p);
public:
    void FUN_00aa4060(void *);
};
// @fnv 0x00c40930
void* FUN_00c40930_Class::FUN_00c40930(unsigned int flags)
{
    reinterpret_cast<::fnv_00c3f8c0::FUN_00c3f8c0 *>(this)->fnv_00c3f8c0::FUN_00c3f8c0::~FUN_00c3f8c0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
// Calls FUN_00c4a840, then deallocates this via the memory manager if flags has bit 0 set, and returns this.
// @fnv 0x00c4a960
void* FUN_00c4a960_Class::FUN_00c4a960(unsigned int flags)
{
    FUN_00c4a840();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
// @fnv 0x00c422d0
void S_00c422d0_Foo::DestroyEntries()
{
    unsigned int uiIndex;
    unsigned int V_h;
    FUN_00c42b60_class* pItem;
    FUN_00c42b60_class* pBase;
    FUN_00c42b60_class* V_k;
    S_00c422d0_Entry* pObject;
    unsigned int V_n;
    for (uiIndex = 0; uiIndex < (V_h = m_uiItemCount); uiIndex++) {
        pItem = m_pEntries[uiIndex].m_pObject;
        pBase = pItem;
        pBase != 0 ? (V_k = pBase, V_k->FUN_00c42b60(), ((0,1)&1) ? reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<SpawnHeap_cls*>(&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(V_k) : (void)0, V_k) : 0;
    }
    pObject = (S_00c422d0_Entry*)m_pEntries;
    reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<SpawnHeap_cls*>(&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(pObject);
    V_n = m_unk04;
    DAT_0fdf050((void*)V_n);
}

struct FNV_SubObject {
    int* m_vtbl;         // +0x00
    FNV_Item* m_pBase;   // +0x04
};

struct FNV_Base {
    int unk00;           // +0x04
    int unk04;           // +0x08
    virtual void vfn();
    ~FNV_Base();
};

struct FUN_00c53fa0_Class : public FNV_Base {
    FNV_SubObject m_sub;    // +0x0c
    ~FUN_00c53fa0_Class();
};

// Destructor: sets m_sub's vtable to FNV_vtbl_NiTArrayBase and deallocates m_sub.m_pBase via FNV_g_memoryManager.
// @fnv 0x00c53fa0
FUN_00c53fa0_Class::~FUN_00c53fa0_Class()
{
    FNV_SubObject* p3 = &m_sub;
    p3->m_vtbl = &FNV_vtbl_NiTArrayBase;
    FNV_Item* q = p3->m_pBase;
    void* r6 = q;
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FNV_MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(r6);
}

struct SpawnedSubObject
{
    int unk00;
    int unk04;
    int unk08;
    void Attach(int a1);
};

struct FUN_00c54e30_cls
{
    int unk00;
    int unk04;
    int unk08;
    SpawnedSubObject m_0c;
    SpawnedSubObject m_18;
    void BindAndAttachSubObjects(int a1);
};

// Calls BindOwner with a1, then attaches both contained sub-objects to a1.
// @fnv 0x00c54e30
void FUN_00c54e30_cls::BindAndAttachSubObjects(int a1)
{
    reinterpret_cast<::NiExtraData *>(this)->LoadBinary((*(::NiStream *)(a1)));
    reinterpret_cast<::NiColor *>(&(m_0c))->LoadBinary((*(::NiStream *)(a1)));
    reinterpret_cast<::NiColor *>(&(m_18))->LoadBinary((*(::NiStream *)(a1)));
}

struct Point3_c54f00 {
    float x;
    float y;
    float z;
};

struct C00c541e0 {
    int unk00;
    int unk04;
    int unk08;
};

struct C00c54f00 : C00c541e0 {
    Point3_c54f00 m_vec0C;
    Point3_c54f00 m_vec18;
    bool FUN_00c54f00(int other);
};

// Calls the base comparison and, if it passes, also compares m_vec0C and m_vec18 component-wise with the other object's vectors.
// @fnv 0x00c54f00
bool C00c54f00::FUN_00c54f00(int other)
{
    bool result = ((bool)(reinterpret_cast<::NiObject_00a7b3d0 *>(this)->FUN_00a7b3d0((::NiObject_00a7b3d0 *)(other))));
    if (result) {
        C00c54f00* pOther = (C00c54f00*)other;
        {
            const Point3_c54f00& b = pOther->m_vec0C;
            const Point3_c54f00& a = m_vec0C;
            result = a.x == b.x && a.y == b.y && a.z == b.z;
        }
        {
            const Point3_c54f00& b = pOther->m_vec18;
            const Point3_c54f00& a = m_vec18;
            result &= (bool)(int)(a.x == b.x && a.y == b.y && a.z == b.z);
        }
    }
    return result;
}

struct C55CD0Point3 {
    float x;
    float y;
    float z;
};


// @fnv 0x00c55cd0
void FUN_00c55cd0(const C55CD0Point3& aCenter, float fSize, unsigned int uiColor)
{
    C55CD0Point3 kMinBoundsCur = aCenter;
    kMinBoundsCur.y -= fSize;
    C55CD0Point3 kMaxPoint = aCenter;
    kMaxPoint.y += fSize;
    ::FUN_00c55d50((::Point3 *)&(kMinBoundsCur), (::Point3 *)&(kMaxPoint), fSize, fSize, fSize, fSize, (::FilterData *)(uiColor), (::FilterData *)(uiColor));
}

struct S_00c5ae70_Result {
    int unk00;
    int unk04;
    int unk08;
};

struct S_00c5ae70_Inner2 {
    int unk00;
    int unk04;
    int unk08;

};

struct S_00c5ae70_Inner1 {
    int unk00;
    int unk04;
    S_00c5ae70_Inner2 m_inner2;

};

struct S_00c5ae70_Class {
    int unk00;
    int unk04;
    S_00c5ae70_Inner1 m_inner1;

    void FUN_00c5ae70(int param);
};

// If param is non-zero, obtains a result object from m_inner1.m_inner2, stores param in its unk08, and passes it to m_inner1.FUN_00559a70.
// @fnv 0x00c5ae70
void S_00c5ae70_Class::FUN_00c5ae70(int aiValue)
{
    S_00c5ae70_Result* res2;
    int ie;
    int el;
    int a;
    int c;
    int e;
    int g;
    int k;

    if (aiValue != 0) {
        S_00c5ae70_Inner1* p = &m_inner1;
        res2 = ((::S_00c5ae70_Result *)(reinterpret_cast<::FUN_0043a010_shell *>(&(p->m_inner2))->FUN_0043a010()));
        res2->unk08 = aiValue;
        reinterpret_cast<::FUN_00559a70_Class *>((p))->FUN_00559a70(res2);
    }
}

struct FUN_00c3a250_Obj {
    void FUN_00c3a250(int* a1);
};

void FUN_00c3a250_Obj::FUN_00c3a250(int* a1) {
}

struct FUN_00c5aec0_Class {
    int unk00;
    int unk04;
    void FUN_00c5aec0(int a1);
};

// If a1 is non-zero, calls FUN_00c3a250 on the object at this+8, passing the address of a1.
// @fnv 0x00c5aec0
void FUN_00c5aec0_Class::FUN_00c5aec0(int aiValue) {
    int dummy00;
    int dummy01;
    int dummy02;
    int dummy03;
    int dummy04;
    int dummy05;
    int dummy06;
    int dummy07;
    int dummy08;
    int dummy09;
    int dummy10;
    int dummy11;
    int dummy12;
    int dummy13;
    int dummy14;
    int dummy15;
    int dummy16;
    int dummy17;
    int dummy18;

    if (aiValue != 0) {
        reinterpret_cast<::List250 *>((((FUN_00c3a250_Obj*)((char*)this + 8))))->FUN_00c3a250((*(void * *)(&aiValue)));
    }
}

struct FUN_00c5b190_Sub {
    void Process(int* p);
};


struct FUN_00c5b190_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00c5b190_Sub m_14;
    void FUN_00c5b190(int a1);
};

// If a1 is non-zero, calls m_14.Process with the address of a1.
// @fnv 0x00c5b190
void FUN_00c5b190_cls::FUN_00c5b190(int aiValue) {
    int loc1;
    int loc2;
    int loc3;
    int loc4;
    int loc5;
    int loc6;
    int loc7;
    int loc8;
    int loc9;
    int loc10;
    int loc11;
    int loc12;
    int loc13;
    int loc14;
    int loc15;
    int loc16;
    int loc17;
    int loc18;
    int loc19;
    if (aiValue != 0) { m_14.Process(&aiValue); }
}

// Constructor: member routine that installs the class vtable pointer into
// the object, clears the flag member at +0x5c and then hands the object to
// the shared cleanup routine (FUN_00c1c300).
extern int DAT_010c2d54;

struct FUN_00c5c440_cls
{
    void* m_pVTable;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    void Constructor();
};

// Sets the vtable pointer, clears m_5c, then calls FUN_00c1c300.
// @fnv 0x00c5c440
void FUN_00c5c440_cls::Constructor()
{
    // four spare scratch words; they only shape the stack frame of the
    // original routine.
    int iScratch0;
    int iScratch1;
    int iScratch2;
    int iScratch3;

    m_pVTable = (void*)&DAT_010c2d54;
    m_5c = 0;
    reinterpret_cast<::S_00c1c300 *>(this)->FUN_00c1c300();
}

struct FUN_00c5c400 {
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
    unsigned int m_0x5c;
    unsigned int m_0x60;
    FUN_00c5c400();
};
struct NiPSysEmitterCtlr_CloneShell {
    FUN_00c5c400* FUN_00c5ca90(void* process);
};
// @fnv 0x00c5ca90
FUN_00c5c400* NiPSysEmitterCtlr_CloneShell::FUN_00c5ca90(void* process) {
    FUN_00c5c400* clone = new FUN_00c5c400;
    reinterpret_cast<::NiPSysEmitterCtlr_StandIn *>(this)->FUN_00c5cb20((::NiPSysEmitterCtlr_StandIn *)(clone), process);
    return clone;
}

struct FUN_00a53c30_cls {
};

struct FUN_00c5cb50_pad {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct FUN_00c5cb50_cls {
    void FUN_00c5cb50(int a1);
};

// @fnv 0x00c5cb50
void FUN_00c5cb50_cls::FUN_00c5cb50(int a1)
{
    FUN_00c5cb50_pad pad;
    void* found;
    void* value;
    bool ok;

    reinterpret_cast<::NiPSysEmitterCtlr *>((this))->ProcessClone((*(::CloningProcess *)(a1)));
    value = 0;
    ok = reinterpret_cast<::A54440Hash *>((((FUN_00a53c30_cls*)*(void**)a1)))->FUN_00a53c30((::A54440Manager *)((uintptr_t)this), (::A54440Manager **)(void **)(&value));
    found = value;
    ok = reinterpret_cast<::A54440Hash *>((((FUN_00a53c30_cls*)*(void**)a1)))->FUN_00a53c30((::A54440Manager *)(*(unsigned int*)((char*)this + 0x5c)), (::A54440Manager **)(void **)(&value));
    *(void**)((char*)found + 0x5c) = value;
}

class BC5CBB0Object {
public:
};

class BC5CBB0Controller : public BC5CBB0Object {
public:
    BC5CBB0Controller();

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
};

// Allocates and constructs a BC5CBB0Controller, returning it as a BC5CBB0Object pointer.
// @fnv 0x00c5cbb0
BC5CBB0Object* __cdecl FUN_00c5cbb0()
{
    BC5CBB0Controller* pkController = new BC5CBB0Controller;
    return pkController;
}

struct EmitterObjectStub {
    void* m_ppVirtualMethodTable;
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
    EmitterObjectStub();
};

struct EmitterOwnerStub
{
    void Attach(EmitterObjectStub* pkObject, int iParam);
    EmitterObjectStub* CreateAndAttachEmitterObject(int iParam);
};

struct FUN_00c5d0a0_cls;
struct FUN_00c5d0a0_Vec4 { int x; int y; int z; int w; };
struct FUN_00c5d0a0_cls {
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
    FUN_00c5d0a0_Vec4 m_c4;
    void CopyVec4AndHelper(FUN_00c5d0a0_cls* a1, int a2);
};
// Allocates a new EmitterObjectStub, attaches it to this owner with iParam, and returns the new object.
// @fnv 0x00c5d010
EmitterObjectStub* EmitterOwnerStub::CreateAndAttachEmitterObject(int iParam) {
    EmitterObjectStub* pkObject = new EmitterObjectStub;
    reinterpret_cast<::FUN_00c5d0a0_cls *>(this)->CopyVec4AndHelper((::FUN_00c5d0a0_cls *)(pkObject), iParam);
    return pkObject;
}
// Copies m_c4 into a1->m_c4, then calls Helper(a1, a2).
// @fnv 0x00c5d0a0
void FUN_00c5d0a0_cls::CopyVec4AndHelper(FUN_00c5d0a0_cls* apOther, int aiArg) {
    apOther->m_c4 = m_c4;
    ::FUN_00a744c0();
}

typedef HKEY HKEY_t;

struct RegSetting {
    int unk00;
    int value;
    char* pName;
    unsigned int GetSize();
};

struct RegStore {
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void Open(bool bWrite);
    virtual void Close();
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
    HKEY_t m_hKey;

    bool WriteSetting(RegSetting* pSetting);
};

// @fnv 0x00c5d670
bool RegStore::WriteSetting(RegSetting* pSetting)
{
    bool bResultTmp = false;
    char* pName4 = pSetting->pName;
    bool bOpened5;
    HKEY_t hKey1;
    HKEY_t hKey2;
    HKEY_t hKey7;
    unsigned int uiSize;
    int iType7;
    char acName[64];
    if (pName4 != 0) {
        hKey1 = m_hKey;
        bOpened5 = (hKey1 == 0);
        if (bOpened5)
            Open(true);
        hKey2 = m_hKey;
        if (hKey2 != 0) {
            uiSize = ((unsigned int)(reinterpret_cast<::FUN_00c32fb0_cls *>((pSetting))->GetFormatSize()));
            iType7 = ::FUN_00c33090((const char *)((intptr_t)pName4));
            if (iType7 == 1) {
                fnv::crt::strcpy_s(acName, 64, pName4);
                acName[0] = 's';
                pName4 = acName;
            }
            hKey7 = m_hKey;
            bResultTmp = RegSetValueExA(hKey7, pName4, 0, iType7, (const unsigned char*)&pSetting->value, uiSize) == 0;
        }
        if (bOpened5)
            Close();
    }
    return bResultTmp;
}

typedef struct HKEY__* HKEY;
typedef unsigned long DWORD;
typedef unsigned char BYTE;


struct Setting {
    int unk00;
    int value;
    const char* name;
};

int __cdecl GetStateResult(int* apParams);

struct RegSettingCollection {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Open(int a);
    virtual void Close();
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104;
    HKEY hKey;
    bool ReadFromRegistry(Setting* pSetting);
};

// @fnv 0x00c5d780
bool RegSettingCollection::ReadFromRegistry(Setting* pSetting) {
    bool bResultTmp = false;
    char shortName6[64];
    char strBuf_[260];
    const char* pName4 = pSetting->name;
    if (pName4) {
        bool bOpened5;
        DWORD dwSize3;
        DWORD kDwType;
        BYTE* pData6;
        {
            HKEY hOpenKeyX = hKey;
            bOpened5 = hOpenKeyX == 0;
        }
        if (bOpened5) {
            Open(0);
        }
        {
            HKEY hCurKey5 = hKey;
            if (hCurKey5) {
                dwSize3 = ((unsigned int)(reinterpret_cast<::FUN_00c32fb0_cls *>((pSetting))->GetFormatSize()));
                kDwType = GetStateResult((int*)pSetting);
                if (kDwType == 1) {
                    fnv::crt::strcpy_s(shortName6, 0x40, pName4);
                    shortName6[0] = 's';
                    pName4 = shortName6;
                    strBuf_[0] = 0;
                    dwSize3 = 0x104;
                    pData6 = (BYTE*)strBuf_;
                } else {
                    pData6 = (BYTE*)&pSetting->value;
                }
                HKEY hQueryKey = hKey;
                bResultTmp = RegQueryValueExA(hQueryKey, pName4, 0, &kDwType, pData6, &dwSize3) == 0;
                if (bResultTmp && kDwType == 1) {
                    reinterpret_cast<::SettingS *>((pSetting))->FUN_00c33170(strBuf_);
                }
            }
        }
        if (bOpened5) {
            Close();
        }
    }
    return bResultTmp;
}

// FUN_00c5de30: thiscall, zero two fields, reset sub-object at +0xac
struct ResetHelper {
    unsigned int unk00, unk04, unk08;
    void Reset();
};
class FUN_00c5de30_cls {
public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    ResetHelper m_ac;
    unsigned short m_b8;
    unsigned short unkBA;
    unsigned int unkBC;
    unsigned int m_c0;
    void FUN_00c5de30();
};
// Clears m_b8 and m_c0 and resets the m_ac helper.
// @fnv 0x00c5de30
void FUN_00c5de30_cls::FUN_00c5de30() {
    ResetHelper scratch;
    unsigned int scratchBuf[4];
    m_b8 = 0;
    m_c0 = 0;
    m_ac.Reset();
}

struct FUN_00c5de70_sub {
};

struct FUN_00c5de70_cls
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
    FUN_00c5de70_sub m_cc;
    void FUN_00c5de70();
};
// Calls FUN_00a5c6a0 with a, then calls FUN_00c5de70 if the value at a+4 is below 0x10.
// @fnv 0x00c5e6f0
void FUN_00c5e6f0_class::FUN_00c5e6f0(int a)
{
    reinterpret_cast<::LinkObjectA5 *>((((NiObjectNET_stub*)this)))->FUN_00a5c6a0((*(::NiStream *)(a)));
    if (*(unsigned int*)(a + 4) < 0x10) {
        reinterpret_cast<::FUN_00c5de70_cls *>((((FUN_00c5de70_stub*)this)))->FUN_00c5de70();
    }
}


struct FUN_00c5e010_Node {
    virtual void vf00();
    virtual void vf04();
    virtual int vf08();

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
    FUN_00c5e010_Node* next;
};

// @fnv 0x00c5e010
inline void FUN_00c5e010_Node::vf00() {}
inline void FUN_00c5e010_Node::vf04() {}
inline int FUN_00c5e010_Node::vf08() { return 0; }

bool __cdecl FUN_00c5e010(int object) {
    FUN_00c5e010_Node* initial =
        *reinterpret_cast<FUN_00c5e010_Node**>(
            reinterpret_cast<char*>(object) + 0x0C);
    FUN_00c5e010_Node* current = initial;

    while (current != 0) {
        bool found;
        if (current == 0)
            found = false;
        else
            found = current->vf08() ==
                reinterpret_cast<intptr_t>(&(*reinterpret_cast<int *>(&::g_01203340)));

        if (found)
            return true;

        FUN_00c5e010_Node* next = current->next;
        current = next;
    }

    return false;
}

struct Walk_TreeNode_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Walk_TreeNode_cls* v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual int v12();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    Walk_TreeNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct Walk_Helper_cls
{
};

struct Walk_Walker_cls
{
    void WalkTree(Walk_TreeNode_cls* node, intptr_t a2);
};
// Calls FUN_005e03d0 on m_cc, then WalkTree with this and &m_cc.
// @fnv 0x00c5de70
void FUN_00c5de70_cls::FUN_00c5de70()
{
    int tmp;
    ::FUN_005e03d0((::NiTArray_Layout *)&(m_cc));
    reinterpret_cast<::Walk_Walker_cls *>(this)->WalkTree((::Walk_TreeNode_cls *)(::FUN_00c5de70_cls *)(this), (intptr_t)(&m_cc));
}

// Recursively walks a tree node: if the node has a non-null v12 result it is passed to the helper, otherwise each child in m_a0 is visited recursively.
// @fnv 0x00c5e280
void Walk_Walker_cls::WalkTree(Walk_TreeNode_cls* node, intptr_t pHelper)
{
    if (0 == node)
        return;
    if (node->v12() != 0) {
        Walk_TreeNode_cls* j;
        j = node;
        reinterpret_cast<::StrArr *>((((Walk_Helper_cls*)pHelper)))->FUN_00c4c8d0((*(char * *)(&j)));
        return;
    }
    {
    Walk_TreeNode_cls* tmp3 = node != 0 ? node->v03() : 0;
    if (!!tmp3) {
        long v;
        v = tmp3->m_a6;
        for (unsigned int uiIndex = 0; uiIndex < v; uiIndex++) {
            unsigned int scratchA, scratchB, scratchC, scratchD;
            Walk_TreeNode_cls** item = &tmp3->m_a0[uiIndex];
            Walk_TreeNode_cls* value7 = *item;
            Walk_TreeNode_cls* p = value7;
            if (0 != p)
                this->WalkTree(p, pHelper);
        }
    }
    }}

struct S_00c5e3d0 {
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
    unsigned short unkb8;
    unsigned short unkba;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    float unkdc;
    void FUN_00c5e080();
    void FUN_00c5e3d0(float* p, int b);
};
struct S_00c5e3d0_pad { int a, b, c, d; float saved; };

struct FUN_00c5e450_cls {
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
    unsigned short m_b8;
    unsigned short unkBA;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    float m_dc;

    void FUN_00c5e450(float* f, int b);
};


class C5E7A0Object;

class C5E7A0Stream {
public:
    virtual void vfunc00(); virtual void vfunc01(); virtual void vfunc02(); virtual void vfunc03();
    virtual void vfunc04(); virtual void vfunc05(); virtual void vfunc06(); virtual void vfunc07();
    virtual void vfunc08(); virtual void vfunc09(); virtual void vfunc0A(); virtual void vfunc0B();
    virtual void SaveLinkID(C5E7A0Object* pkObject);
};


class C5E7A0Node {
public:
};

class C5E7A0Switch : public C5E7A0Node {
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
    unsigned short unkB8;
    unsigned short m_usFlags;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    C5E7A0Object** m_ppkChildren;
    unsigned short unkD4;
    unsigned short m_usChildCount;

    void FUN_00c5e7a0(C5E7A0Stream& kStream);
};

// SaveBinary
// Saves the node via C5E7A0Node::SaveBinary, then writes m_usFlags, the child count and each child's link ID to kStream.
// @fnv 0x00c5e7a0
void C5E7A0Switch::FUN_00c5e7a0(C5E7A0Stream& kStream)
{
    reinterpret_cast<::NodeA5E8 *>(this)->FUN_00a5e880((::NiStreamA5E8 &)(kStream));
    ::fnv_00a303a0::FUN_00a303a0((::fnv_00a303a0::Stream *)&(kStream), &m_usFlags);
    unsigned int ItemUpdateArray = m_usChildCount;
    ::FUN_0044adf0((::MiddleHighProcess *)&(kStream), (intptr_t)(&ItemUpdateArray));
    for (unsigned int i = 0; i < ItemUpdateArray; i++) {
        C5E7A0Object* pkChild = m_ppkChildren[i];
        kStream.SaveLinkID(pkChild);
    }
}

struct SwitchChild {
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58();
    virtual bool IsEqual(SwitchChild* pOther);
};

struct ListNode {
    ListNode* m_pkNext;
    ListNode* m_pkPrev;
    int m_element;
};

struct ListOwner_c5e830 : BaseForCall {
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
    ListNode* m_pkHead;
    int unkB0;
    int unkB4;
    unsigned short m_usB8;
    unsigned short m_usBA;
    unsigned short m_usBC;
    unsigned short unkBE;
    int unkC0;
    int m_iC4;
    int unkC8;
    int unkCC;
    SwitchChild** m_ppChildren;
    unsigned short unkD4;
    unsigned short m_usChildCount;

    bool FUN_00c5e830(NiObject* pObject);
};

// @fnv 0x00c5e830
bool ListOwner_c5e830::FUN_00c5e830(NiObject* pObject)
{
    ListOwner_c5e830* kPOther;
    ListNode* kPos8;
    ListNode* kPos4;
    int a7;
    int b2;
    unsigned int aUiCount1;
    unsigned int uiCount2;
    unsigned int i_;
    SwitchChild* p1;
    SwitchChild* p6;

    if (!reinterpret_cast<::NiNodeEq *>(this)->FUN_00a5e600((::NiAVObject *)(pObject)))
        return false;

    kPOther = (ListOwner_c5e830*)pObject;
    {
        ListNode* pHead4 = m_pkHead;
        kPos8 = pHead4;
    }
    {
        ListNode* pHead7 = kPOther->m_pkHead;
        kPos4 = pHead7;
    }

    if (m_usB8 != kPOther->m_usB8 || m_usBA != kPOther->m_usBA || m_iC4 != kPOther->m_iC4
        || m_usBC != kPOther->m_usBC)
        return false;

    while (kPos8 && kPos4)
    {
        {
            int* pElemA = &kPos8->m_element;
            kPos8 = kPos8->m_pkNext;
            a7 = *pElemA;
        }
        {
            int* pElem4 = &kPos4->m_element;
            kPos4 = kPos4->m_pkNext;
            b2 = *pElem4;
        }
        if (a7 != b2)
            return false;
    }

    aUiCount1 = m_usChildCount;
    uiCount2 = kPOther->m_usChildCount;
    if (aUiCount1 != uiCount2)
        return false;

    for (i_ = 0; i_ < aUiCount1; i_++)
    {
        p1 = m_ppChildren[i_];
        p6 = kPOther->m_ppChildren[i_];
        if ((p1 && !p6) || (!p1 && p6))
            return false;
        if (p1 && !p1->IsEqual(p6))
            return false;
    }

    if (kPos8 || kPos4)
        return false;
    else
        return true;
}

struct FUN_007530a0 {
    virtual ~FUN_007530a0() {}
};

struct FUN_00a7b300 {
    virtual ~FUN_00a7b300() {}
};

struct FUN_00c5ed60 : FUN_00a7b300 {
    int unk04;
    int unk08;
    FUN_007530a0 m_00c;
    virtual ~FUN_00c5ed60();
};
// Calls FUN_00c5ed60 on this, then deletes this with size 0x1c if flags has bit 0 set, and returns this.
// @fnv 0x00c5f360
void* FUN_00c5f360_Class::FUN_00c5f360(unsigned int flags)
{
    reinterpret_cast<::FUN_00c5ed60 *>((((FUN_00c5ed60_Class*)this)))->FUN_00c5ed60::~FUN_00c5ed60();
    if (flags & 1)
        operator delete(this, 0x1c);
    return this;
}

// Destructs a FUN_00c5ed60 object, destroying its embedded FUN_007530a0 member and base FUN_00a7b300.
// @fnv 0x00c5ed60
FUN_00c5ed60::~FUN_00c5ed60() {}

struct BSShaderAccumulator {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    BSShaderAccumulator();
};
// Allocates a BSShaderAccumulator and returns it as a NiObject pointer.
// @fnv 0x00c5eed0
NiObject* __cdecl CreateShaderAccumulator(void) {
    NiObject* obj = (NiObject*)new BSShaderAccumulator();
    return obj;
}

struct FUN_00a7b4a0_cls {
};

struct FUN_00a645b0_cls {
    void FUN_00a645b0();
};


class FUN_00c5ef50_cls {
public:
    void FUN_00c5ef50(int a1);
};


class FUN_00c5f100_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void** m_ppItems;
    unsigned int m_uiCount;

    bool Equals(FUN_00c5f100_cls* other);
};

// Returns false if other is null or its item count or any item pointer differs from this object's; otherwise returns true.
// @fnv 0x00c5f100
bool FUN_00c5f100_cls::Equals(FUN_00c5f100_cls* other) {
    if (other == 0) {
        return false;
    }
    FUN_00c5f100_cls* rhs3 = other;
    unsigned int lhsCountB = m_uiCount;
    unsigned int rhsCount = rhs3->m_uiCount;
    if (lhsCountB != rhsCount) {
        return false;
    }
    unsigned int i;
    unsigned int n3;
    for (i = 0; i < (n3 = m_uiCount); i++) {
        void** item = &m_ppItems[i];
        if (*item != rhs3->m_ppItems[i]) {
            return false;
        }
    }
    return true;
}

class NiMemObject {
public:
};
struct NiTransformView {
    float rotation[9];
    float translation[3];
    float scale;
};
struct NiBoundView {
    float center[3];
    float radius;
};
struct CloneNode : NiMemObject {
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    CloneNode();
    unsigned int referenceCount;
    const char* name;
    void* extraData;
    unsigned short extraDataCount;
    unsigned short extraDataCapacity;
    void* controller;
    CloneNode* parent;
    void* collisionObject;
    unsigned int flags;
    NiTransformView localTransform;
    NiTransformView worldTransform;
    NiBoundView worldBound;
    CloneNode** children;
    unsigned int childCapacity;
    unsigned int childCount;
    void* runtimeState;
};
struct CloneOwnerObj : FUN_00c5fb60_Class {
    CloneNode* FUN_00c5fac0(void* context);
};
// @fnv 0x00c5fac0
CloneNode* CloneOwnerObj::FUN_00c5fac0(void* context)
{
    CloneNode* clone = new CloneNode();
    reinterpret_cast<::FUN_00c5fb60_class *>(this)->ForwardToBase((::S_00a953b0_Node *)(reinterpret_cast<intptr_t>(clone)), (void *)(reinterpret_cast<intptr_t>(context)));
    clone->vfn_00bc();
    return clone;
}

struct FUN_00c5fb80_str
{
    char* m_p;
};

struct FUN_00c5fb80_rec
{
    int unk00;
    int unk04;
    FUN_00c5fb80_str m_08;
};

struct FUN_00c5fb80_pool
{
    char* Alloc(unsigned int size);
};



// Allocates a buffer sized for the record's prefix plus the suffix, copies the prefix if present, appends the suffix and returns the result.
// @fnv 0x00c5fb80
char* __cdecl ConcatPrefixAndSuffix(FUN_00c5fb80_rec* rec, const char* suffix)
{
    FUN_00c5fb80_str pre = rec->m_08;
    char* prefix = pre.m_p;
    unsigned int prefixLen2;
    if (prefix != 0)
        prefixLen2 = std::strlen(prefix);
    else
        prefixLen2 = 0;
    unsigned int total = prefixLen2 + std::strlen(suffix) + 1;
    char* allocated4 = ((char *)(reinterpret_cast<::MemoryManagerStandIn *>((reinterpret_cast<FUN_00c5fb80_pool*>(&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa3e40(total)));
    char* buf3 = allocated4;
    if (prefix != 0)
        fnv::crt::strcpy_s(buf3, total, prefix);
    return ((char *)(std::uintptr_t)(fnv::crt::strcat_s(buf3, total, suffix)));
}

extern void* DAT_010c32c4;

struct FUN_00c5fd50_cls
{
    void* m_vtbl;
    void FUN_00c5fd50();
};

// @fnv 0x00c5fd50
void FUN_00c5fd50_cls::FUN_00c5fd50()
{
    m_vtbl = &DAT_010c32c4;
    reinterpret_cast<::PositionState *>(this)->FUN_00c31750();
}

void* __cdecl FUN_00aa13e0(size_t);
struct PositionModifierInstance {
    FUN_00c5fd30 modifier;
    void* name;
    unsigned int order;
    void* target;
    bool active;
    float lastTime;
    void* next;
};
// Allocates a PositionModifierInstance and returns a pointer to its modifier member.
// @fnv 0x00c5fee0
FUN_00c5fd30* __cdecl CreatePositionModifierInstance() {
    PositionModifierInstance* instance = new PositionModifierInstance;
    return &instance->modifier;
}

struct MyStream;

struct ParticlePositionModifier {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    void FUN_00c5ff60(MyStream* stream);
};

// @fnv 0x00c5ff60
void ParticlePositionModifier::FUN_00c5ff60(MyStream* stream)
{
    reinterpret_cast<::NiPSysModifier *>(this)->LoadBinary((*(::NiStream *)(stream)));
    FUN_00a26df0(stream, &unk18);
}

namespace fnv_00c41610 {


class SlotValueSource {
public:
    virtual void Reserved0();
    virtual unsigned int GetSlotValue(unsigned int index);
};

struct FUN_00c41610_Entry {
    unsigned int m_uiThreadId;
    unsigned int m_uiFilterValue;
};

class FUN_00c41610_cls {
public:
    unsigned int m_uiItemCount;             // +0x00
    unsigned int m_tlsIndex;          // +0x04
    FUN_00c41610_Entry* m_entries;    // +0x08
    LONG m_seq;                       // +0x0c

    unsigned int SetSlotValue(SlotValueSource* source);
};

// @fnv 0x00c41610
unsigned int FUN_00c41610_cls::SetSlotValue(SlotValueSource* source) {
    unsigned int uiSlotValue = 0;
    unsigned int c = (unsigned int)(InterlockedIncrement(&m_seq) - 1);
    if (c < m_uiItemCount) {
        uiSlotValue = source->GetSlotValue(c);
        m_entries[c].m_uiFilterValue = uiSlotValue;
        DWORD threadId;
        threadId = GetCurrentThreadId();
        m_entries[c].m_uiThreadId = threadId;
        DWORD result = m_tlsIndex;
        TlsSetValue(result, (LPVOID)uiSlotValue);
    }
    return uiSlotValue;
}
}  // namespace fnv_00c41610


struct ArrC43220 {
    int f00;
    int f04;
    unsigned short f08;
    unsigned short m_usSize;
    void FUN_00470000(unsigned int index, unsigned int& elem);
};

struct KwHi {
    int n0;
    char c4;
    char c5;
    char c6;
    bool bDynamic;
    int n8;
    char c12;
    char c13;
    char c14;
    bool bEditorMarker;
    int n16;
    char c20;
    char c21;
    char c22;
    bool bAddon;
    int n24;
    char c28;
    char c29;
    char c30;
    bool bComplex;
    int n32;
    char c36;
    char c37;
    char c38;
    bool bRagDoll;
    int n40;
    short s44;
    bool bHavok;
    bool bAnimated;
};

struct KwLo {
    int n0;
    int n4;
    int n8;
    int n12;
    char c16;
    char c17;
    char c18;
    bool bIKTarget;
    int n20;
    int n24;
    int n28;
    int n32;
    char c36;
    char c37;
    char c38;
    bool bArticulated;
};

struct ThisC43220 {
    int f00;
    int f04;
    int f08;
    unsigned int m_flags;
    void AppendKeywordFlags(ArrC43220* arr);
};

// @fnv 0x00c43220
void ThisC43220::AppendKeywordFlags(ArrC43220* arr)
{
    unsigned int v6;
    unsigned int e4;
    unsigned int v3;
    unsigned int e0;
    unsigned int v1;
    unsigned int e6;
    unsigned int n4;
    unsigned int e3;
    unsigned int id2;
    unsigned int id8;
    void* s2;
    KwHi v8;
    KwLo obj;
    reinterpret_cast<::FUN_00a99d70_shell *>((this))->FUN_00a99d70((::A89C70StringArray *)(arr));
    s2 = (*reinterpret_cast<void * *>(&::g_01202de0));
    v6 = (uintptr_t)((void *)(::FUN_00a7d330((const char *)(s2))));
    arr->FUN_00470000(arr->m_usSize, v6);
    v8.bAnimated = (this->m_flags & 1) != 0;
    e4 = (uintptr_t)FUN_00a7d370("bAnimated", v8.bAnimated);
    arr->FUN_00470000(arr->m_usSize, e4);
    v8.bHavok = (this->m_flags & 2) != 0;
    v3 = (uintptr_t)FUN_00a7d370("bHavok", v8.bHavok);
    reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(v3));
    v8.bRagDoll = (this->m_flags & 4) != 0;
    e0 = (uintptr_t)FUN_00a7d370("bRagDoll", v8.bRagDoll);
    reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(e0));
    v8.bComplex = (this->m_flags & 8) != 0;
    v1 = (uintptr_t)FUN_00a7d370("bComplex", v8.bComplex);
    reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(v1));
    v8.bAddon = (this->m_flags & 0x10) != 0;
    e6 = (uintptr_t)FUN_00a7d370("bAddon", v8.bAddon);
    reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(e6));
    v8.bEditorMarker = (this->m_flags & 0x20) != 0;
    n4 = (uintptr_t)FUN_00a7d370("bEditorMarker", v8.bEditorMarker);
    reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(n4));
    v8.bDynamic = (this->m_flags & 0x40) != 0;
    e3 = (uintptr_t)FUN_00a7d370("bDynamic", v8.bDynamic);
    reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(e3));
    obj.bArticulated = (this->m_flags & 0x80) != 0;
    id2 = (uintptr_t)FUN_00a7d370("bArticulated", obj.bArticulated);
    reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(id2));
    obj.bIKTarget = (this->m_flags & 0x100) != 0;
    id8 = (uintptr_t)FUN_00a7d370("bIKTarget", obj.bIKTarget);
    reinterpret_cast<::S_0060ba10 *>((arr))->FUN_0096a610((intptr_t)&(id8));
}

class BC45120CloningProcess;

class BC45120Object {
public:

    BC45120Object();
    virtual ~BC45120Object();

    BC45120Object* Clone(BC45120CloningProcess& kCloning);

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
};

// @fnv 0x00c45120
BC45120Object* BC45120Object::Clone(BC45120CloningProcess& kCloning)
{
    BC45120Object* pkClone = new BC45120Object;
    reinterpret_cast<::FUN_00c451b0_class *>(this)->CopyStateTo((intptr_t)(pkClone), (intptr_t)&(kCloning));
    return pkClone;
}

struct Ref462f0 { void* vtable; volatile long references; };
struct Slot462f0 { Ref462f0* p;  };
extern Ref462f0* DAT_01202e14;
extern unsigned int DAT_01202e18;
void __cdecl FUN_00fdd690();
struct Target462f0 {
 void* vtable;
 Slot462f0* data;
 unsigned short capacity;
 unsigned short size;
 unsigned short count;
 unsigned short grow;
 void SetSlot(unsigned int index, const Slot462f0& value);
};
// @fnv 0x00c462f0
void Target462f0::SetSlot(unsigned int index, const Slot462f0& aSlot) {
 Ref462f0* j;
 if (!(DAT_01202e18 & 1)) {
  DAT_01202e18 |= 1;
  DAT_01202e14 = 0;
  if (DAT_01202e14) {
   j = DAT_01202e14;
   Slot462f0* destination;
   Ref462f0* previous;
   InterlockedIncrement(&j->references);
  }
  std::atexit(FUN_00fdd690);
 }
 if (index >= size) {
  size = index + 1;
  if ((bool)(int)(aSlot.p != DAT_01202e14)) ++count;
 } else {
  if ((bool)(int)(aSlot.p != DAT_01202e14)) {
   if ((bool)(int)(data[index].p == DAT_01202e14)) ++count;
  } else {
   if ((bool)(int)(data[index].p != DAT_01202e14)) --count;
  }
 }
 reinterpret_cast<::FUN_00c46270_Class *>(&(data[index]))->AssignRefCounted((const ::FUN_00c46270_Class &)(aSlot));
}

struct Entry { int type; int a; int b; };
struct Target {
 int unk00, unk04, unk08, unk0c, unk10, unk14;
 Entry* data;
 int unk1c, unk20, unk24;
 int count;
 void CompactEntries();
};
// Compacts the entry array in place, skipping type 4/5 pairs followed by type 6 and copying type 7/8 entries with their following entry.
// @fnv 0x00c49700
void Target::CompactEntries() {
 int original = 0;
 int removed = count;
 for (int i = 0; i < count; i++) {
  while (i < count && count > 0 && (data[i + original].type == 4 || data[i + original].type == 5) && data[i + original + 1].type == 6) {
   original += 2;
   count -= 2;
  }
  if (i + original < removed) {
   int* source = &data[i + original].type;
   data[i].type = *source;
   if (data[i].type == 7 || data[i].type == 8) {
    int* next = &data[i + original + 1].type;
    data[i + 1].type = *next;
    i++;
   }
  }
 }
}

struct MeshStatsData {
    unsigned int unk00,unk04;
    unsigned short vertices,unk0a;
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
    unsigned short triangles;
};
struct MeshStatsEntry {
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
    unsigned int unkb0;
    unsigned int unkb4;
    MeshStatsData* data;
    unsigned int unkbc,unkc0,unkc4,unkc8,unkcc;
    unsigned int bytes;
};
struct Statistics { unsigned int meshes,triangles,vertices,materials,other,bytes; };
struct MeshCollection {
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
    unsigned int unkb0;
    unsigned int other;
    unsigned short materials,unkba;
    unsigned int unkbc,unkc0,unkc4,unkc8,unkcc;
    MeshStatsEntry** meshes;
    unsigned short capacity,used;
    void AccumulateStatistics(Statistics*);
};
// Sums triangles, vertices and bytes over the used mesh entries and writes them, along with materials, other and mesh count, into output.
// @fnv 0x00c5df00
void MeshCollection::AccumulateStatistics(Statistics* pStats)
{
    unsigned int cf = 0;
    unsigned int eb = 0;
    unsigned int f = 0;
    unsigned int s = used;
    unsigned int q;
    MeshStatsEntry* b;
    MeshStatsData* ba;
    __declspec(align(2)) unsigned short k;
    MeshStatsData* l;
    __declspec(align(2)) unsigned short c;
    unsigned int e;
    unsigned int j;
    for (q = 0; q < s; ++q) {
        b = meshes[q];
        if (b) {
            ba = b->data;
            k = ba->triangles;
            cf += k;
            l = b->data;
            c = l->vertices;
            eb += c;
            e = b->bytes;
            f += e;
        }
    }
    pStats->triangles = cf;
    pStats->vertices = eb;
    pStats->bytes = f;
    pStats->materials = materials;
    j = other;
    pStats->other = j;
    pStats->meshes = s;
}

namespace fnv_00c5e350 {
struct Target {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4;
    unsigned short count_b8, unkba;
    int unkbc, unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8;
    float elapsed_dc;
    void UpdateTimed(float* time, int arg);
};
}  // namespace fnv_00c5e350

// Refresh every key whose time lags the given time by more than the controller's threshold.

struct FDA0Key {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

class FDA0Data {
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
    unsigned short m_usKeyCount;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    FDA0Key* m_pKeyArray;

};

class FDA0Controller {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_fThreshold;

    void UpdateKeyTimes(float fTime, FDA0Data* pkArg);
};

// For each key, if the elapsed time since its stored time exceeds m_fThreshold, resets that key's time to fTime.
// @fnv 0x00c5fda0
void FDA0Controller::UpdateKeyTimes(float fTime, FDA0Data* pkArg)
{
    FDA0Data* pkData = pkArg;
    unsigned short usKeyCount = pkArg->m_usKeyCount;
    FDA0Key* pkKey = pkArg->m_pKeyArray;
    for (unsigned short i = 0; i < usKeyCount; i++, pkKey++) {
        float fTimeSinceScaleStart = fTime - reinterpret_cast<::FUN_00c25de0_shell *>((pkData))->GetEntryFloat(i);
        if (fTimeSinceScaleStart > m_fThreshold)
            reinterpret_cast<::TrailSystem *>((pkData))->AddTrailPoint(i, fTime);
    }
}


struct Inner5b
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
    virtual void Fire();
};

struct Tag5b
{
    unsigned int bits;
};

struct Scratch5b
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
};

struct Pad16_5b { unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C; };

struct Lock5b
{
    Inner5b* m00;
    unsigned int* m04;
    unsigned int* m08;
    unsigned int* m0c;
    unsigned int* m10;
    unsigned int m14;
    unsigned int m18;

    bool TryAcquireAndFire(unsigned int a, unsigned int b, unsigned int c);
};


struct RefObj {
    int unk00;
    int unk04;
    volatile long m_iObjectReferenceCount;
};

struct RefPtr {
    RefObj* m_pObject;
};

struct NodeKey {
    int a;
    int b;
};

struct NodeFlags {
    unsigned int m_uiValue1;
};

struct Node {
    NodeKey m_key;
    RefPtr m_pReferencedObject;
    NodeFlags m_flags;
};

struct TaggedNodePtr {
    unsigned int m_uiBits;
};

struct Handler {
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
    virtual void Process(NodeKey key, NodeKey* pKey);
};

struct NodeQueue {
    Handler* m_pHandler;
    int* m_p04;
    int* m_p08;
    int* m_p0C;
    int unk10;
    TaggedNodePtr m_kSecond;
    TaggedNodePtr m_kFirst;

    bool FUN_00c42560(intptr_t arg, NodeKey* pKey, RefPtr* pOut);
};

struct FUN_00c42560_pad {
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
};


struct C45440_Obj : FUN_00c450d0 {
    int u64;
    int u68;
    int u6C;
    int u70;
    int u74;
    int u78;
    int u7C;
    int u80;
    int u84;
    int u88;
    int u8C;
    int u90;
    int u94;
    int u98;
    int u9C;
    int uA0;
    int uA4;
    int uA8;
    int uAC;
};

// Allocates and returns a new C45440_Obj instance via its operator new.
// @fnv 0x00c45440
C45440_Obj* __cdecl CreateC45440Obj(void) {
    return new C45440_Obj;
}

struct Animation;

struct C5EDC0_AnimArray {
    unsigned int Add(Animation*& apAnim);
};

struct C5EDC0_AnimExtra {
    int unk00;
    int unk04;
    int unk08;
    C5EDC0_AnimArray m_kAnimations;
    unsigned int AddAnimation(Animation* apAnim);
};


struct BSFaceGenMorphData { };
namespace c30 {
struct FUN_00c5fd30 : BSFaceGenMorphData { FUN_00c5fd30(); int m[7]; };
struct Owner30 {
    void FUN_00c5fec0(FUN_00c5fd30* mod, int arg);
    FUN_00c5fd30* CreateMorphData(int arg);
};
// Allocates a FUN_00c5fd30, initialises it via FUN_00c5fec0 with arg, and returns the new object.
// @fnv 0x00c5fe30
FUN_00c5fd30* Owner30::CreateMorphData(int arg)
{
    FUN_00c5fd30* mod = new FUN_00c5fd30;
    FUN_00c5fec0(mod, arg);
    return mod;
}
}

struct SemaphoreC44 {
    volatile long m_lCount;
    void* m_pSemaphore;
};
struct WorkerC44 {
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
    SemaphoreC44 m_kCompletionSemaphore;
};
struct FUN_00c44d30_cls {
    WorkerC44** m_ppkWorkers;
    void WaitForWorkers();
};
// Stores a1 and a2 into fields at offsets 4 and 8, sets the byte at 0xc, then calls FUN_00c44cd0, CallStoredCallback and WaitForWorkers before clearing the byte at 0xc.
// @fnv 0x00c44c40
void FUN_00c44c40_class::FUN_00c44c40(int a1, int a2)
{
    *(char*)((char*)this + 0xc) = 1;
    *(int*)((char*)this + 4) = a1;
    *(int*)((char*)this + 8) = a2;
    ((FUN_00c44cd0_class*)this)->FUN_00c44cd0();
    ((FUN_00c44cb0_class*)this)->CallStoredCallback();
    reinterpret_cast<::FUN_00c44d30_cls *>((((FUN_00c44cd0_class*)this)))->WaitForWorkers();
    *(char*)((char*)this + 0xc) = 0;
}
// Waits on each worker's semaphore handle and decrements its count.
// @fnv 0x00c44d30
void FUN_00c44d30_cls::WaitForWorkers() {
    for (unsigned int i = 0; i < 1; i++) {
        WorkerC44* pkWorker2 = m_ppkWorkers[i];
        SemaphoreC44* pkSemaphore = &pkWorker2->m_kCompletionSemaphore;
        WaitForSingleObject(pkSemaphore->m_pSemaphore, 0xffffffff);
        InterlockedDecrement(&pkSemaphore->m_lCount);
    }
}

struct FUN_00c467c0_cls : ParticlePositionModifier {
    void FUN_00c467c0(MyStream* stream);
};
// Calls FUN_00c318b0 on stream, then FUN_00a26df0 on stream and unk18.
// @fnv 0x00c467c0
void FUN_00c467c0_cls::FUN_00c467c0(MyStream* stream) {
    reinterpret_cast<::NiPSysModifier *>(this)->LoadBinary((*(::NiStream *)(stream)));
    FUN_00a26df0(stream, &unk18);
}

struct FUN_00c47b50Vec3;

struct FUN_00c47b50Transform { float v0; float v1; float v2; float v3; float v4; float v5; };

struct FUN_00c47b50Record {

    int m00; int m04; int m08; int m0c; int m10; int m14; int m18; int m1c;

    int m20; int m24; int m28; int m2c; int m30; int m34; int m38; int m3c;

    int m40; int m44; int m48; int m4c; int m50; int m54; int m58; int m5c;

    int m60;

};

struct FUN_00c47b50Vec3 {

    float x; float y; float z;



};

struct FUN_00c47b50Arg {


    void FUN_00c33870(FUN_00c47b50Vec3, FUN_00c47b50Record*);

};

struct FUN_00c47b50Array {

    int unk00;

    FUN_00c47b50Record* m_pData;

    int unk08;

    int m_iCapacity;


};

struct FUN_00c47b50Elem { int value; int index; int unused; };

struct FUN_00c47b50SmallArray {

    int unk00;

    FUN_00c47b50Elem* m_pData;

    int unk08;

    int m_iCapacity;


};

struct FUN_00c47b50Class {

    int unk00;

    FUN_00c47b50Array first;

    FUN_00c47b50SmallArray second;

    int index;

    int count;

    int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48;

    int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68;

    int unk6c; int unk70; int unk74; int unk78; int unk7c; int unk80; int unk84; int unk88;

    int unk8c; int unk90;

    FUN_00c47b50Vec3 position;

    void UpdateRecords(FUN_00c47b50Arg*, int);

};



struct S_00c4dd60_Key {
    unsigned short unk00;
    unsigned short w16;
};

struct S_00c4dd60_Vec2 {
    float x;
    float y;
};

struct S_00c4dd60_Elem {
    S_00c4dd60_Vec2 v;
    int unk08;
};

struct S_00c4dd60_Table {
    int unk00;
    S_00c4dd60_Elem* m_pElems;
};

struct S_00c4dd60_Words {
    int unk00;
    unsigned short* m_pWords;
    unsigned int m_uiItemCount;

};

struct S_00c4dd60_Owner {
    S_00c4dd60_Table* m_pTable;
    S_00c4dd60_Words* m_pWords;

    bool IsKeyValid(int key, int a, int b);
};

struct FUN_00c5ee90_cls : NiExtraData_Shell {
    int unk00;
    int unk04;
    int unk08;
    FUN_00c5f500_class unk0C;
    void FUN_00c5ee90(NiBinaryExtraData* dest, CloningProcess* cloning);
};
// @fnv 0x00c5ee90
void FUN_00c5ee90_cls::FUN_00c5ee90(NiBinaryExtraData* dest, CloningProcess* cloning) {
    FUN_00c5ee90_cls* other;
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330(dest, cloning);
    unk0C.FUN_00c5f500(&((FUN_00c5ee90_cls*)dest)->unk0C);
}

struct FUN_00a63430_Obj {
};

struct FUN_00c5efb0_Class : NiExtraData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int* unk10;
    unsigned int unk14;
    void FUN_00c5efb0(NiStream& stream);
};

// Links the stream, then reads unk14 unsigned ints from the stream into the array at unk10.
// @fnv 0x00c5efb0
void FUN_00c5efb0_Class::FUN_00c5efb0(NiStream& stream)
{
    unsigned int i;
    unsigned int count;
    LinkObject(stream);
    for (count = 0; count < (i = unk14); count++) {
        unsigned int* slot = unk10 + count;
        *slot = ((uintptr_t)(reinterpret_cast<::NiStream *>((((FUN_00a63430_Obj*)&stream)))->GetLoadedObject()));
    }
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

// FUN_00c43d00: builds the INISettings list snapshot ("INISettings" name + AddFirstEmpty,
// then count via FUN_0044f890 and "Total INISettings" message + AddFirstEmpty).
// SinkSave is a stand-in for the TU's local aggregate frame reservation.

struct SinkSave { unsigned int data[15]; };

struct FUN_00c43d00_Host {
    unsigned int FUN_00c43d00(NiTPrimitiveArray_unsigned_int_& arr);
};

// @fnv 0x00c43d00
unsigned int FUN_00c43d00_Host::FUN_00c43d00(NiTPrimitiveArray_unsigned_int_& arr)
{
    SinkSave save;
    unsigned int key = (uintptr_t)FUN_00a7d330("INISettings");
    reinterpret_cast<::S_0060ba10 *>((((ArrC43220*)&arr)))->FUN_0096a610((intptr_t)&(key));
    unsigned int count = ((unsigned int)(reinterpret_cast<::B44F890Collection *>(this)->FUN_0044f890((int)&(arr))));
    unsigned int msg = (uintptr_t)FUN_00a7d510("Total INISettings", count);
    reinterpret_cast<::S_0060ba10 *>((((ArrC43220*)&arr)))->FUN_0096a610((intptr_t)&(msg));
    return count;
}

struct SetView {
    int unk00;
    union {
        int i;
        unsigned int u;
        float f;
        char* s;
    } data;
    char* name;
};


struct IniFile {
    virtual void z0();
    virtual void z1();
    virtual void z2();
    virtual void z3();
    virtual void z4();
    virtual void z5();
    virtual void Open(int);
    virtual void Close();
    char path[0x104];
    int fileHandle;
    bool FUN_00c43e90(SetView* setting);
};

// Writes setting to the INI file at path via WritePrivateProfileStringA, formatting data by the type from FUN_00c33090(name); opens and closes the file if needed.
// @fnv 0x00c43e90
bool IniFile::FUN_00c43e90(SetView* setting) {
    bool handle;
    bool result = false;
    {
        char Dir[0x40];
        int Dir2;
        char Left[0x40];
        char EndLoc2[0x100];
        unsigned int Diff;
        unsigned int EndLoc;
        unsigned int EndLoc9;
        unsigned int LeftX;
        unsigned int Right;
        unsigned int Dir4;
        unsigned int Diff4;
        unsigned int Diff7;
        char* Diff3 = setting->name;
        unsigned int Dir3;
        unsigned int EndLoc5;
        if (Diff3 != 0) {
            handle = (this->fileHandle == 0);
            if (handle)
                this->Open(1);
            if (this->fileHandle != 0) {
                Dir2 = ::FUN_00c33090((const char *)((intptr_t)setting->name));
                CopyMainNameFromPath((intptr_t)setting, Dir);
                CopyStringBeforeColon((FUN_00c43e00_Obj*)setting, Left);
                switch (Dir2) {
                case 6:
                    result = WritePrivateProfileStringA(Dir, Left, setting ? setting->data.s : 0, this->path) != 0;
                    break;
                case 1:
                case 3:
                    ::FUN_00406d00(EndLoc2, 0x100, "%d", setting->data.i);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                case 5:
                    ::FUN_00406d00(EndLoc2, 0x100, "%.4f", setting->data.f);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                case 7:
                    Dir3 = setting->data.u;
                    LeftX = (Dir3 >> 24) & 0xFF;
                    EndLoc9 = (Dir3 >> 16) & 0xFF;
                    EndLoc = (Dir3 >> 8) & 0xFF;
                    Diff = Dir3 & 0xFF;
                    ::FUN_00406d00(EndLoc2, 0x100, "%u,%u,%u", LeftX, EndLoc9, EndLoc);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                case 8:
                    EndLoc5 = setting->data.u;
                    Diff7 = (EndLoc5 >> 24) & 0xFF;
                    Diff4 = (EndLoc5 >> 16) & 0xFF;
                    Dir4 = (EndLoc5 >> 8) & 0xFF;
                    Right = EndLoc5 & 0xFF;
                    ::FUN_00406d00(EndLoc2, 0x100, "%u,%u,%u,%u", Diff7, Diff4, Dir4, Right);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                case 2:
                case 4:
                default:
                    ::FUN_00406d00(EndLoc2, 0x100, "%u", setting->data.u);
                    result = WritePrivateProfileStringA(Dir, Left, EndLoc2, this->path) != 0;
                    break;
                }
            }
            if (handle)
                this->Close();
        }
    }
    return result;
}

struct S_00c454c0_Stream {
};
extern const char str_010c1c40[];
extern const char str_010c1c3c[];
extern const char str_010c1c34[];
extern const char str_0109c7d8[];
struct S_00c454c0_Bool8 {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    bool v;
};
struct S_00c454c0_Pad {
    int unkP00;
    int unkP04;
    int unkP08;
};
struct S_00c454c0_Low {
    int unkL00;
    int unkL04;
    int unkL08;
};
struct S_00c454c0_Byte8 {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char v;
};
struct S_00c454c0 {
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
    unsigned char unkac;
    unsigned char unkad;
    unsigned char unkae;
    unsigned char unkaf;
    void FUN_00c454c0(S_00c454c0_Stream* s);
};
// @fnv 0x00c4ab00
void FUN_00c4ab00_Class::FUN_00c4ab00(int pArray)
{
    void* v;
    unsigned int x8;
    int pad1;
    int pad2;
    int pad3;
    int pad4;
    reinterpret_cast<::S_00c454c0 *>(this)->FUN_00c454c0((::S_00c454c0_Stream *)(pArray));
    v = (*reinterpret_cast<void * *>(&::g_01202e7c));
    x8 = (uintptr_t)((void *)(::FUN_00a7d330((const char *)(v))));
    reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)pArray)))->FUN_0096a610((intptr_t)&(x8));
}
// @fnv 0x00c4ad60
void FUN_00c4ad60_class::AddFirstEmptyFromGlobal(int pArray)
{
    reinterpret_cast<::S_00c454c0 *>(this)->FUN_00c454c0((::S_00c454c0_Stream *)(pArray));

    unsigned int result;
    {
        int value = (*reinterpret_cast<int *>(&::g_01202e84));
        {
            int padding1;
            int padding2;
            int padding3;
            int padding4;
        }
        result = ((uintptr_t)(::FUN_00a7d330((const char *)(value))));
    }

    reinterpret_cast<::S_0060ba10 *>((reinterpret_cast<NiTPrimitiveArray_unsigned_int_*>(pArray)))->FUN_0096a610((intptr_t)&(result));
}
// @fnv 0x00c4afc0
void FUN_00c4afc0_class::AddValueToArray(NiTPrimitiveArray<unsigned int>* array)
{
    {
        int padding[4];
    }

    unsigned int p;
    void* value;

    reinterpret_cast<::S_00c454c0 *>((reinterpret_cast<FUN_00c4ab00_Class*>(this)))->FUN_00c454c0((::S_00c454c0_Stream *)(reinterpret_cast<intptr_t>(array)));

    value = *reinterpret_cast<void**>(&::g_01202e8c);
    p = ((uintptr_t)(::FUN_00a7d330((const char *)(value))));

    reinterpret_cast<::S_0060ba10 *>((array))->FUN_0096a610((intptr_t)&(p));
}
// Calls FUN_00a5ea70, then writes formatted strings for unkae, unkaf, unkad, and a bool derived from unkac into the stream s.
// @fnv 0x00c454c0
void S_00c454c0::FUN_00c454c0(S_00c454c0_Stream* s) {
    S_00c454c0_Pad pad;
    S_00c454c0_Low CNVal;
    reinterpret_cast<::FUN_00a5ea70_t *>(this)->FUN_00a5ea70((::StrArr *)(s));
    S_00c454c0_Byte8 aT1;
    aT1.v = unkae;
    char* a = FUN_00a7d410(str_010c1c40, aT1.v);
    reinterpret_cast<::S_0060ba10 *>((s))->FUN_0096a610((intptr_t)(&a));
    S_00c454c0_Byte8 t2;
    t2.v = unkaf;
    char* b9 = FUN_00a7d410(str_010c1c3c, t2.v);
    reinterpret_cast<::S_0060ba10 *>((s))->FUN_0096a610((intptr_t)(&b9));
    S_00c454c0_Byte8 t3;
    t3.v = unkad;
    char* aC = FUN_00a7d410(str_010c1c34, t3.v);
    reinterpret_cast<::S_0060ba10 *>((s))->FUN_0096a610((intptr_t)(&aC));
    S_00c454c0_Bool8 t4;
    t4.v = unkac != 0;
    char* d_ = FUN_00a7d370(str_0109c7d8, t4.v);
    reinterpret_cast<::S_0060ba10 *>((s))->FUN_0096a610((intptr_t)(&d_));
}

struct P465 {
    float x;
    float y;
    float z;
};

struct R465 {
    P465 point;
    int unk0c;
    int unk10;
    float time;
    int unk18;
};

struct A465 {
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
    unsigned short unk50;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    R465* unk70;
};

struct H465 {
    unsigned short n;
    unsigned short scale;
};

struct C465 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float unk18;

    void FUN_00c465e0(float value, A465* arg);
};

// For each of arg->unk50 entries at arg->unk70, scales DAT_01202e68 by (value - time)*unk18 and passes the result to the entry point's FUN_0063c8a0.
// @fnv 0x00c465e0
void C465::FUN_00c465e0(float value, A465* arg)
{
    H465 half;
    R465* h;
    int w;
    P465 x;
    P465 block;

    half.scale = arg->unk50;
    if (half.scale == 0) {
    } else {
        h = arg->unk70;
        half.n = arg->unk50;
        w = half.n;
        while (w-- != 0) {
            reinterpret_cast<::FUN_0045bb20_cls *>(&(reinterpret_cast<P465&>(DAT_01202e68)))->ApplyScaled((::FUN_0045bb20_target *)(::P465 *)(&x), (value - h->time) * unk18);
            reinterpret_cast<::FUN_0063c8a0_shell *>(&(h->point))->FUN_0063c8a0((void *)&(x));
            ++h;
        }
    }
}

struct StrArr;

struct E70Target
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
    virtual void v24(StrArr* stream);
};

struct E70LinkRef
{
    int unk00;
    int unk04;
    int unk08;
    E70Target* object;
};

// link is the only live field. The two words above it are the frame holes at -0x14 and -0x10.
struct E70FirstSlot
{
    E70LinkRef* link;
    int unk04;
    int unk08;
};

extern char str_01090d1c[];
extern char str_010c1e3c[];
extern char str_010c1e34[];
extern char str_010c1e28[];


struct E70Owner : UpdateOwner
{
    void FUN_00c46e70(StrArr* stream);
};

// Calls FUN_00a5ea70, adds a name string and a string chosen by replacement to the stream, then calls v24 on the linked object with the stream.
// @fnv 0x00c46e70
void E70Owner::FUN_00c46e70(StrArr* stream)
{
    reinterpret_cast<::FUN_00a5ea70_t *>(this)->FUN_00a5ea70(stream);

    void* _global = (*reinterpret_cast<void * *>(&::g_01202e74));
    char* name5 = FUN_00a7d330((const char*)_global);
    reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)stream)))->FUN_0096a610((intptr_t)&(*(unsigned int*)&name5));

    unsigned int value = ((uintptr_t)(::fnv_00a7d5e0::FUN_00a7d5e0(str_010c1e28,
        replacement == 0 ? str_01090d1c : (replacement == 1 ? str_010c1e3c : str_010c1e34))));
    reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)stream)))->FUN_0096a610((intptr_t)&(value));
    {
        E70FirstSlot slot;
        slot.link = (E70LinkRef*)reference;
        if (slot.link != 0) {
            E70LinkRef* second = (E70LinkRef*)reference;
            E70Target* target2 = second->object;
            if (target2 != 0) {
                E70LinkRef* thirdB = (E70LinkRef*)reference;
                E70Target* volatile found3 = thirdB->object;
                found3->v24(stream);
            }
        }
    }
}

struct Bound47250 {
    struct XYZ { unsigned int m_00, m_04, m_08; } m_00;
    float m_0c;
};
struct Provider47250 {
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
    virtual void va0(); virtual void va4(Bound47250*);
};
struct Ref47250 { unsigned int m_00,m_04,m_08; Provider47250* m_0c; };
struct Node47250 {
    unsigned int m_00[8]; Bound47250* m_20;
    unsigned int m_24[3]; unsigned int m_30;
    unsigned int m_34[27]; Node47250** m_a0;
    unsigned short m_a4,m_a6,m_a8,m_aa; Ref47250* m_ac;
    void FUN_00c47250();
};
struct Pad47250 { unsigned int m_00,m_04,m_08; };
// Fills m_20 via the m_ac provider if present, else copies the first child bound with nonzero m_0c and merges later such bounds via FUN_00a7f3f0.
// @fnv 0x00c47250
void Node47250::FUN_00c47250() {
    const Bound47250* local14;
    float local35;
    Node47250** local37;
    Bound47250* local40;
    float local49;
    const Bound47250* local69;
    Pad47250 local78;
    float local100;
    Node47250** local104;
    Bound47250* local108;
    Pad47250 local150;
    Provider47250* local154;
    Ref47250* local158;
    Ref47250* local163;
    Node47250* local167;
    unsigned int local172;
    unsigned int local176;
    Provider47250* local260;
    bool local264 = true;
    local163 = m_ac;
    if (local163) {
        local158 = m_ac;
        local154 = local158->m_0c;
        local260 = local154;
        if (local260) { reinterpret_cast<::NiAVObject *>(this)->EnsureWorldBound(); local260->va4(m_20); local264 = false; }
    }
    if (local264) {
        if (m_20 && (bool)(m_30 & 0x80000 ? 1 : 0)) {
            local108 = m_20; local108->m_0c = 0.0f;
        }
        local172 = m_a6;
        for (local176 = 0; local176 < local172; ++local176) {
            local104 = &m_a0[local176]; local167 = *local104;
            if (local167) {
                if (local167->m_20 && (local100 = local167->m_20->m_0c) != 0.0 ? 1 : 0) {
                    reinterpret_cast<::NiAVObject *>(this)->EnsureWorldBound();
                    local69 = local167->m_20 ? local167->m_20 : &(*reinterpret_cast<::Bound47250 *>(&::g_defaultBound));
                    local40 = m_20;
                    local49 = local69->m_0c;
                    local40->m_00 = local69->m_00;
                    local40->m_0c = local49;
                    ++local176; break;
                }
            }
        }
        for (; local176 < local172; ++local176) {
            local37 = &m_a0[local176]; local167 = *local37;
            if (local167) {
                if (local167->m_20 && (local35 = local167->m_20->m_0c) != 0.0 ? 1 : 0) {
                    local14 = local167->m_20 ? local167->m_20 : &(*reinterpret_cast<::Bound47250 *>(&::g_defaultBound));
                    reinterpret_cast<::Sphere *>((m_20))->FUN_00a7f3f0((*(const ::Sphere *)(local14)));
                }
            }
        }
    }
}

struct TargetClass {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
    virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26();
    virtual bool vfn_9c(void*);
    virtual bool vfn_a0(void*);
};

struct QueryParam {
    int unk00;
    int unk04;
    int unk08;
    TargetClass* target;
};

struct DecisionTreeExt : DecisionTree {
    bool FUN_00c493a0(QueryParam* query);
};

// Checks the target against bounds unless skipBounds is set, then walks the nodes using vfn_9c/vfn_a0 on volumes and returns whether the end node's type is 2.
// @fnv 0x00c493a0
bool DecisionTreeExt::FUN_00c493a0(QueryParam* query) {
    VolumeRecord* vol = 0;
    bool result5 = true;
    int iNodeIndex;
    bool branchTaken;
    if (!this->skipBounds) {
        TargetClass* volatile target = query->target;
        result5 = target->vfn_9c((VolumeRecord*)&this->unk30);
    }
    if (result5) {
        if (this->nodeCount > 0) {
            iNodeIndex = this->rootIndex;
            while (this->nodes[iNodeIndex].type != 2 && this->nodes[iNodeIndex].type != 3) {
                branchTaken = false;
                switch (this->nodes[iNodeIndex].type) {
                case 7: {
                    DecisionNode* pNext = &this->nodes[iNodeIndex + 1];
                    vol = &this->volumes[pNext->type];
                    TargetClass* volatile target = query->target;
                    branchTaken = target->vfn_9c(vol);
                    break;
                }
                case 8: {
                    DecisionNode* pNext = &this->nodes[iNodeIndex + 1];
                    vol = &this->volumes[pNext->type];
                    TargetClass* volatile target = query->target;
                    branchTaken = !target->vfn_a0(vol);
                    break;
                }
                }
                iNodeIndex = branchTaken ? this->nodes[iNodeIndex].trueIndex : this->nodes[iNodeIndex].falseIndex;
            }
            result5 = (this->nodes[iNodeIndex].type == 2);
        }
    }
    return result5;
}

struct GraphRecord { int kind, yes, no; };
struct RecordArray {
    int unk00;
    GraphRecord* data;
    int unk08;
    int capacity;
};
struct GraphHeap {
    void Deallocate(void*);
};
struct GraphMemory {  };
extern char DAT_010c1e44[];
struct ControlGraph {
    bool ready;
    int unk04, unk08, unk0c, unk10;
    RecordArray records;
    int unk24;
    int count;
    int first;
    void FUN_00c49850();
};

// If not ready, assigns yes/no target indices to records by kind, shortens kind 7/8 links past intermediate records, then sets ready.
// @fnv 0x00c49850
void ControlGraph::FUN_00c49850() {
    if (!ready && count > 0) {
        GraphRecord* local60;
        GraphRecord* recordE4;
        GraphRecord* recordD5;
        GraphRecord* recordCTmp;
        GraphRecord* recordB3;
        GraphRecord* local57;
        int grow8;
        int capacity;
        int local55;
        int local53;
        int kd;
        int j8;
        int i22;
        bool found3;
        GraphHeap* heapA;
        int* local26;
        int depth5;
        int* endsX;
        int* groups_;
        int endIndex9;
        int stackCapacity7;
        int local19;
        int local8;
        endIndex9 = count + 1;
        local19 = count + 2;
        capacity = records.capacity;
        if (count + 3 >= capacity) {
            grow8 = records.capacity;
            reinterpret_cast<::FUN_00c4a1e0 *>(&(records))->SetSize(grow8 + 10, true);
        }
        records.data[count].kind = 1;
        records.data[count + 1].kind = 2;
        records.data[count + 2].kind = 3;
        stackCapacity7 = count / 2;
        heapA = ((::GraphHeap *)(reinterpret_cast<::MemoryManager *>(&((*reinterpret_cast<::GraphMemory *>(&::g_memoryManager))))->GetGeneralAllocator()));
        local26 = (int*)reinterpret_cast<::FUN_00aa54a0_s *>((heapA))->FUN_00aa54a0(stackCapacity7 * sizeof(int), DAT_010a2720);
        local26[0] = 0;
        depth5 = 0;
        local8 = 1;
        endsX = (int*)reinterpret_cast<::FUN_00aa54a0_s *>((heapA))->FUN_00aa54a0(stackCapacity7 * sizeof(int), DAT_010a2720);
        groups_ = (int*)reinterpret_cast<::FUN_00aa54a0_s *>((heapA))->FUN_00aa54a0(stackCapacity7 * sizeof(int), DAT_010a2720);
        for (i22 = 0; i22 < count + 1; ++i22) {
            switch (records.data[i22].kind) {
            case 1:
                endsX[0] = i22;
                if (depth5 != 0) { count = 0; return; }
                break;
            case 4:
            case 5:
                ++depth5;
                local26[depth5] = local8;
                ++local8;
                break;
            case 6:
                endsX[local26[depth5]] = i22;
                --depth5;
                break;
            case 7:
            case 8:
                ++i22;
                break;
            }
        }
        std::memset(local26, 0, stackCapacity7 * sizeof(int));
        local26[0] = 0;
        groups_[0] = 0;
        depth5 = 1;
        local8 = 1;
        found3 = false;
        for (j8 = 0; j8 < count + 1; ++j8) {
            switch (records.data[j8].kind) {
            case 1:
                records.data[j8].yes = endIndex9;
                records.data[j8].no = local19;
                break;
            case 6:
                --depth5;
                switch (local26[depth5 - 1]) {
                case 0:
                    records.data[j8].yes = j8 + 1;
                    records.data[j8].no = j8 + 1;
                    break;
                case 5:
                    records.data[j8].yes = endsX[groups_[depth5 - 1]];
                    records.data[j8].no = j8 + 1;
                    break;
                case 4:
                    records.data[j8].yes = j8 + 1;
                    records.data[j8].no = endsX[groups_[depth5 - 1]];
                    break;
                }
                break;
            case 7:
            case 8:
                if (!found3) { first = j8; found3 = true; }
                switch (local26[depth5 - 1]) {
                case 0:
                    records.data[j8].yes = count;
                    records.data[j8].no = count;
                    break;
                case 5:
                    records.data[j8].yes = endsX[groups_[depth5 - 1]];
                    records.data[j8].no = j8 + 2;
                    break;
                case 4:
                    records.data[j8].yes = j8 + 2;
                    records.data[j8].no = endsX[groups_[depth5 - 1]];
                    break;
                }
                ++j8;
                break;
            case 4:
            case 5:
                local26[depth5] = records.data[j8].kind;
                groups_[depth5] = local8;
                ++local8;
                ++depth5;
                records.data[j8].yes = j8 + 1;
                records.data[j8].no = j8 + 1;
                break;
            }
        }
        if (!found3) {
            ::FUN_005b5e40();
            first = endIndex9;
            ready = true;
            return;
        }
        for (kd = first; kd < count; ++kd) {
            switch (records.data[kd].kind) {
            case 7:
            case 8:
                while (true) {
                    local57 = &records.data[kd];
                    local53 = records.data[local57->yes].kind;
                    if (local53 == 7 || local53 == 8 || local53 == 2 || local53 == 3) break;
                    else {
                        recordB3 = &records.data[kd];
                        recordCTmp = &records.data[recordB3->yes];
                        records.data[kd].yes = recordCTmp->yes;
                    }
                }
                while (true) {
                    recordD5 = &records.data[kd];
                    local55 = records.data[recordD5->no].kind;
                    if (local55 == 7 || local55 == 8 || local55 == 2 || local55 == 3) break;
                    else {
                        recordE4 = &records.data[kd];
                        local60 = &records.data[recordE4->no];
                        records.data[kd].no = local60->no;
                    }
                }
                ++kd;
                break;
            }
        }
        reinterpret_cast<::SHStub *>((heapA))->FUN_00aa5610(local26);
        reinterpret_cast<::SHStub *>((heapA))->FUN_00aa5610(endsX);
        reinterpret_cast<::SHStub *>((heapA))->FUN_00aa5610(groups_);
    }
    ready = true;
}

extern int DAT_010c1e88;

struct S00c49fe0_Vt
{
    virtual void v0();
    virtual void* v1(unsigned int n);
};

struct FUN_00c49fe0_Cls
{
    void* vtbl;
    void* data;
    int unk08;
    int unk0C;

    FUN_00c49fe0_Cls();
};


struct c4a790_Plane {
    unsigned int normalX;
    unsigned int normalY;
    unsigned int normalZ;
    unsigned int constant;
};

struct c4a790_Obj {
    c4a790_Plane planes[6];
    unsigned int mask;
};

struct c4a790_Side {
    int unusedSide;
    int value;
};

struct c4a790_Owner {
    bool FUN_00c4a790(CallerObj_b3918* target, c4a790_Obj* object);
};

// Clears mask bit i while target->ClassifySphereAgainstPlane(plane i) returns 1; returns true if a masked plane returned another value, else false.
// @fnv 0x00c4a790
bool c4a790_Owner::FUN_00c4a790(CallerObj_b3918* target, c4a790_Obj* apPlanes)
{
    int i;
    c4a790_Side result;

    if (!(apPlanes->mask != 0 ? true : false)) {
        return false;
    } else {
        for (i = 0; i < 6; i++) {
            if ((apPlanes->mask & (1u << i)) != 0 ? true : false) {
                result.value = reinterpret_cast<::B_004b6100 *>((target))->ClassifySphereAgainstPlane((::NiPlane_004b6100 *)(void *)(&apPlanes->planes[i]));
                if (result.value != 1) {
                    break;
                } else if (result.value == 1) {
                    apPlanes->mask = apPlanes->mask & ~(1u << i);
                }
            }
        }
        if (i == 6)
            return false;
    }
    return true;
}

extern int DAT_010c1e88;

// Sets the vtable pointer to DAT_010c1e88 and calls ReleaseBuffer(1) on the object.
// @fnv 0x00c4a840
void FUN_00c4a960_Class::FUN_00c4a840() {
    int x;
    *(int**)this = &DAT_010c1e88;
    ((FUN_00c4a9c0_class*)this)->ReleaseBuffer(1);
}

struct VertexDE80 {
    float m_00, m_04, m_08;
};
struct DataDE80 {
    int m_00;
    VertexDE80* m_04;
};
struct ObjectDE80 {
    DataDE80* m_00;
    bool FUN_00c4de80(float x, float y, int A, int B, int C);
};
// @fnv 0x00c4e0a0
bool S_00c4e0a0_Class::ContainsMatchingTriple(int arg1, int arg2) {
    for (int i = 0; i < this->m_iArrayLength; i = i + 1) {
        int value0 = i * 3;
        int value1 = i * 3 + 1;
        int valueTmp = i * 3 + 2;

        unsigned short* pA = this->m_pData->m_pValues + valueTmp;
        unsigned short* p1 = this->m_pData->m_pValues + value1;
        unsigned short* p5 = this->m_pData->m_pValues + value0;

        if (reinterpret_cast<::ObjectDE80 *>((this))->FUN_00c4de80(arg1, arg2, *p5, *p1, *pA)) {
            return true;
        }
    }

    return false;
}
// Checks whether key is absent from m_pWords and no other word's element position passes Helper00c4de80; returns false if either check fails.
// @fnv 0x00c4dd60
bool S_00c4dd60_Owner::IsKeyValid(int key, int aiExcludeA, int aiExcludeB)
{
    int w;
    S_00c4dd60_Vec2 pos2;
    int TJ;
    if (m_pWords != 0) {
        unsigned int cnt5;
        S_00c4dd60_Key k;
        cnt5 = m_pWords->m_uiItemCount;
        if (cnt5 > 0) {
            S_00c4dd60_Vec2 pad2;
            k.w16 = (unsigned short)key;
            if (!reinterpret_cast<::FUN_0069dee0_class *>((m_pWords))->Contains((*(const unsigned short *)(&k.w16)))) {
                unsigned int count2;
                for (TJ = 0; TJ < (count2 = m_pWords->m_uiItemCount); ++TJ) {
                    w = m_pWords->m_pWords[TJ];
                    if (w == aiExcludeA || w == aiExcludeB) {
                        continue;
                    }
                    S_00c4dd60_Elem* AE = &m_pTable->m_pElems[w];
                    float FX = m_pTable->m_pElems[w].v.x;
                    float fy = AE->v.y;
                    pos2.x = FX;
                    pos2.y = fy;
                    if (reinterpret_cast<::ObjectDE80 *>(this)->FUN_00c4de80((*(float *)&(const ::S_00c4dd60_Vec2 &)(pos2)), aiExcludeA, key, aiExcludeB, {})) {
                        return false;
                    }
                }
                return true;
            } else {
                return false;
            }
        }
    }
    return true;
}

// Checks whether point (x, y) lies inside the triangle formed by vertices A, B, C using cross-product sign tests.
// @fnv 0x00c4de80
bool ObjectDE80::FUN_00c4de80(float x, float y, int A, int B, int C)
{
    float p, h, a, i, s, f, eb, cf, q, b, ba, k, l, c, e;
    VertexDE80& j = m_00->m_04[C];
    eb = (double)j.m_00 - m_00->m_04[B].m_00;
    {
        VertexDE80* j;
        a = (j = &m_00->m_04[C])->m_04 - m_00->m_04[B].m_04;
        {
            VertexDE80* j;
            cf = (double)(j = &m_00->m_04[A])->m_00 - m_00->m_04[C].m_00;
            {
                VertexDE80* j;
                e = (j = &m_00->m_04[A])->m_04 - m_00->m_04[C].m_04;
                {
                    VertexDE80* j;
                    h = (double)(j = &m_00->m_04[B])->m_00 - m_00->m_04[A].m_00;
                    {
                        VertexDE80* j;
                        k = (j = &m_00->m_04[B])->m_04 - m_00->m_04[A].m_04;
                        p = (double)x - m_00->m_04[A].m_00;
                        f = y - m_00->m_04[A].m_04;
                        ba = (double)x - m_00->m_04[B].m_00;
                        b = y - m_00->m_04[B].m_04;
                        q = (double)x - m_00->m_04[C].m_00;
                        c = y - m_00->m_04[C].m_04;
                        l = eb * b - a * ba;
                        i = h * f - k * p;
                        s = cf * c - e * q;
                        return l <= 0.0 && s <= 0.0 && i <= 0.0;
                    }
                }
            }
        }
    }
}

class FUN_00c511f0_cls {
public:
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};



// If obj is non-null and obj->v2() equals &g_sentinel_0120436c, returns FUN_00c50f90(obj, obj); otherwise returns false.
// @fnv 0x00c511f0
bool __cdecl FUN_00c511f0(FUN_00c511f0_cls* obj)
{
    bool result2 = false;
    FUN_00c511f0_cls* tmp;
    {
        bool gate;
        if (obj == 0) {
            gate = false;
        } else {
            gate = obj->v2() == (void*)&(*reinterpret_cast<char *>(&::g_0120436c));
        }
        if (gate) {
            tmp = obj;
            result2 = ::FUN_00c50f90((::C50Object *)(obj), tmp);
        }
    }
    return result2;
}

// 0x00c52020  1072 bytes  /MT /Od /Oy- /GS /EHsc /Gy   -- byte-identical reconstruction
// thiscall (ret 0x10): (float fov, unsigned char flag, C52020Obj* obj, unsigned char arg4)
// called from 0xc51d67 as FUN_00c52020(*pSetting, 1, 0, 0).
//
// Frame 0xcc + push esi.  Named band -0x04..-0x88 (bucket-sorted: descending name-hash
// bucket, ties by reverse declaration order), expression temps -0x8c..-0xcc in code order.
// Slot roles are annotated on the declarations below; aFlag is the 0x18-byte hole at
// -0x6c that nothing ever reads, and the two setting divides use a two-member record
// read because only a "computed" right operand makes MSVC9 /Od emit
// `mov edx,[p] / fld [edx] / fdivr [ebp+8]` instead of the mirrored
// `fld [ebp+8] / mov edx,[p] / fdiv [edx]`.
struct C52020Dev;

struct NiFrustum {
    NiFrustum(bool);
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};

struct NiUpdateData {
    float m_fTime;
    bool m_b0;
    bool m_b1;
    bool m_b2;
    bool m_b3;
    bool m_b4;
};

struct C52020Res {
    char pad0[8];
    unsigned int m_08;
    unsigned int m_0c;
};

struct C52020Obj;

struct C52020Dev {
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual C52020Res* vfn_b0(int);
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual C52020Dev* vfn_c8();
    virtual C52020Dev* vfn_cc();
};

struct C52020Setting { float m_fReserved; float m_fValue; };

struct C52020Filler {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct CameraViewportC52
{
    float left, right, top, bottom;
    inline CameraViewportC52()
    {}
    inline CameraViewportC52(float x0, float x1, float y1, float y0) : left(x0), right(x1), top(y1), bottom(y0)
    {}
};
struct C52020Obj {
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual float vfn_100();
    char pad0[0xa8];
    C52020Obj* m_ac;
    char pad1[8];
    unsigned char m_b8;
    char pad2[3];
    float m_bc;
    char pad3[0x3c];
    float m_fc;
    CameraViewportC52 viewport;
    float m_110;
    void FUN_00c52020(float m_fFirstFloat, unsigned char ucFlag, C52020Obj* pObj, unsigned char ucArg4);
};

// Builds a NiFrustum from m_fFirstFloat and a width/height ratio (from DAT_011f4748 when set), applies it to the target (pObj or m_ac) and calls Update.
// @fnv 0x00c52020
void C52020Obj::FUN_00c52020(float afFov, unsigned char ucFlag, C52020Obj* apTarget, unsigned char ucArg4)
{
    C52020Obj* aTarget;      // pTarget          [ebp-0x08]
    float aStart;
    float aState;            // fAspect          [ebp-0x0c]
    C52020Dev* aValue;       // pDev             [ebp-0x10]
    float aSize;             // fScale           [ebp-0x30]
    float aLen;
    float aHdr;              // fHalfFov         [ebp-0x44]
    float* aPtr;             // pSetting         [ebp-0x48]
    float aKey;              // fRatio           [ebp-0x4c]
    float* aTmp;             // pSet             [ebp-0x50]
    C52020Filler aFlag;      // 0x18-byte unreferenced local -> frame hole [ebp-0x6c]
    float aPath;             // fLOD             [ebp-0x54]
    C52020Res* aNode;        // pRes             [ebp-0x70]
    unsigned int aObj;       // uiHeight         [ebp-0x74]
    float aHandle;           // fRatio2          [ebp-0x84]
    float* aPData;           // pSetting2        [ebp-0x80]
    unsigned int aHit;       // uiWidth          [ebp-0x7c]
    C52020Res* aRef;         // pRes2            [ebp-0x78]

    aTarget = apTarget;
    if (!aTarget)
        aTarget = this->m_ac;

    if (!apTarget)
    {
        if (!ucFlag && this->m_bc == afFov)
        {
            if (ucArg4)
            {
                aPtr = (*reinterpret_cast<char (*)[]>(&::g_01203150)) ? (float*)&(*reinterpret_cast<char (*)[]>(&::g_01203150))[4]
                                    : ((*reinterpret_cast<float *>(&::DAT_01202800)) = 0.0f, (float*)&(*reinterpret_cast<float *>(&::DAT_01202800)));
                aKey = afFov / (((C52020Setting*)((char*)aPtr - 4))->m_fReserved,
                               ((C52020Setting*)((char*)aPtr - 4))->m_fValue);
                aTarget->m_110 = aKey;
            }
            return;
        }
        this->m_bc = afFov;
    }

    aHdr = afFov * ::DAT_01023128 * ::DAT_01011588;
    NiFrustum aTile(false);
    aTile.m_fFarPlane = vfn_100();
    aTmp = (*reinterpret_cast<char (*)[]>(&::g_01203144)) ? (float*)&(*reinterpret_cast<char (*)[]>(&::g_01203144))[4]
                        : ((*reinterpret_cast<float *>(&::DAT_01202800)) = 0.0f, (float*)&(*reinterpret_cast<float *>(&::DAT_01202800)));
    // the near-plane store inside the divisor is the original's assignment-expression
    // form: it is what produces `fld [near]/fdivr` (a plain two-statement version
    // emits `fld far / fdiv [near]`).
    aPath = aTile.m_fFarPlane / (aTile.m_fNearPlane = *aTmp);
    aTarget->m_fc = aPath;

    aValue = (*reinterpret_cast<::C52020Dev * *>(&::NiRenderer::ms_pRenderer));
    if (aValue)
    {
        aStart = (float)reinterpret_cast<::GraphicsRenderer *>((aValue))->GetRenderTargetHeight() * (aTarget->viewport.top - aTarget->viewport.bottom);
        aLen = (float)reinterpret_cast<::GraphicsRenderer *>((aValue))->GetRenderTargetWidth() * (aTarget->viewport.right - aTarget->viewport.left);
    }
    else
    {
        aStart = aTarget->viewport.top - aTarget->viewport.bottom;
        aLen = aTarget->viewport.right - aTarget->viewport.left;
    }
    if (aValue)
    {
        if (aValue->vfn_cc() && aValue->vfn_cc() != aValue->vfn_c8())
        {
            aNode = aValue->vfn_cc()->vfn_b0(0);
            aObj = aNode->m_0c;
            aStart = (float)aObj;
            aRef = aValue->vfn_cc()->vfn_b0(0);
            aHit = aRef->m_08;
            aLen = (float)aHit;
        }
    }
    aState = aStart / aLen;
    if (this->m_b8 && !apTarget)
        aSize = 1.0f;
    else
        aSize = 0.75 / (aStart / aLen);

    aTile.m_fLeftBound = -(float)tan(aHdr) * aSize;
    aTile.m_fRightBound = (float)tan(aHdr) * aSize;
    aTile.m_fBottomBound = -(float)tan(aHdr) * aState * aSize;
    aTile.m_fTopBound = (float)tan(aHdr) * aState * aSize;

    reinterpret_cast<::NiCamera *>((aTarget))->UpdateViewFrustum((*(const ::NiFrustum *)(&aTile)));

    NiUpdateData aOut = { 0.0f, false, false, false, false, false };
    reinterpret_cast<::FUN_00a59c60_cls *>((aTarget))->FUN_00a59c60((std::intptr_t)&(aOut));

    if (ucArg4)
    {
        aPData = (*reinterpret_cast<char (*)[]>(&::g_01203150)) ? (float*)&(*reinterpret_cast<char (*)[]>(&::g_01203150))[4]
                              : ((*reinterpret_cast<float *>(&::DAT_01202800)) = 0.0f, (float*)&(*reinterpret_cast<float *>(&::DAT_01202800)));
        aHandle = afFov / (((C52020Setting*)((char*)aPData - 4))->m_fReserved,
                          ((C52020Setting*)((char*)aPData - 4))->m_fValue);
        aTarget->m_110 = aHandle;
    }
}

extern unsigned int DAT_010c1040;
extern unsigned int DAT_010c2bf8;

struct W5Sub {
    int pad;
};

struct W5Big {
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    void* p;
};

struct W5Self {
    int f00;
    int f04;
    int f08;
    W5Sub subC;
    int f10;
    int f14;
    W5Sub sub18;
    void FUN_00c550f0(ArrC43220* a1);
};

// Calls FUN_00a7b580(a1), then a1->FUN_0096a610 with FUN_00a7d330(g_012031e8), then with the results of FUN_00a59af0 on subC and sub18.
// @fnv 0x00c550f0
void W5Self::FUN_00c550f0(ArrC43220* a1) {
    reinterpret_cast<::ExtraDataStrings *>(this)->FUN_00a7b580((::StrArr *)(a1));
    unsigned int r1;
    unsigned int p;
    unsigned int r2;
    {
        W5Big big;
        big.p = (*reinterpret_cast<void * *>(&::g_012031e8));
        p = (uintptr_t)((void *)(::FUN_00a7d330((const char *)(big.p))));
        reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((intptr_t)&(p));
        r1 = ((uintptr_t)(reinterpret_cast<::NiPoint3 *>(&(subC))->FUN_00a59af0((const char *)(void *)(&DAT_010c1040))));
        reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((intptr_t)&(r1));
        r2 = ((uintptr_t)(reinterpret_cast<::NiPoint3 *>(&(sub18))->FUN_00a59af0((const char *)(void *)(&DAT_010c2bf8))));
        reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((intptr_t)&(r2));
    }
}

struct S_00c5b140_Node {
    int unk00;
    int unk04;
    void* unk08;
};

struct S_00c5b140_Allocator {
};

struct S_00c5b140_List {
    int unk00;
    int unk04;
    S_00c5b140_Allocator unk08;
};

struct S_00c5b140 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_00c5b140_List unk14;
    void FUN_00c5b140(void* value);
};

// If value is non-null, gets a node from unk14.unk08.FUN_0043a010, stores value in it, and passes the node to unk14.FUN_00559a70.
// @fnv 0x00c5b140
void S_00c5b140::FUN_00c5b140(void* value)
{
    if (value != 0) {
        // The original frame reserves seven dead slots between the two live
        // locals (reserved-but-untouched region); kept as unused scalars.
        int item; int entry; int data; int pElem; int val; int keep; int next;
        S_00c5b140_List* pool = &this->unk14;
        S_00c5b140_Node* pNode = ((::S_00c5b140_Node *)(reinterpret_cast<::FUN_0043a010_shell *>(&(pool->unk08))->FUN_0043a010()));
        pNode->unk08 = value;
        reinterpret_cast<::FUN_00559a70_Class *>((pool))->FUN_00559a70(pNode);
    }
}


typedef NiTListItem<NiPointer<NiProperty> > SpawnNode;
typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> > SpawnList;

struct SpawnedObject {
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
    SpawnList m_50;
    SpawnList m_5c;
    void FUN_00c5b8d0();
};

struct LoopPadA { unsigned int a; unsigned int b; unsigned int c; unsigned int d; };
struct LoopPadB { unsigned int a; unsigned int b; unsigned int c; unsigned int d; unsigned int e; unsigned int f; unsigned int g; };



struct S00c5cd80_Scratch {
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
};

struct S00c5cd80_Owner {
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
    int m_5c;
    unsigned short m_60;
    void FUN_00c5cd80(NiTPrimitiveArray_unsigned_int_* arg);
};

// Calls FUN_00c1ce70, then appends to arg a global-derived entry, one for "Master Particle System" with m_5c, and one for "Max Full Emitters" with m_60.
// @fnv 0x00c5cd80
void S00c5cd80_Owner::FUN_00c5cd80(NiTPrimitiveArray_unsigned_int_* apArray) {
    S00c5cd80_Scratch j;
    reinterpret_cast<::FUN_00c1ce70_shell *>(this)->FUN_00c1ce70((::StrArr *)(apArray));
    int global = (*reinterpret_cast<int *>(&::g_01203340));
    unsigned int full = (uintptr_t)((void *)(::FUN_00a7d330((const char *)(void *)((void*)global))));
    reinterpret_cast<::S_0060ba10 *>((apArray))->FUN_0096a610((intptr_t)&(full));
    unsigned int named = ((uintptr_t)(::FUN_00a7d5a0("Master Particle System", (void *)(m_5c))));
    reinterpret_cast<::S_0060ba10 *>((apArray))->FUN_0096a610((intptr_t)&(named));
    unsigned int slot = ((uintptr_t)(::FUN_00a7d490("Max Full Emitters", m_60)));
    reinterpret_cast<::S_0060ba10 *>((apArray))->FUN_0096a610((intptr_t)&(slot));
}

struct Node_00c5e080 {
    virtual void vfunc00();
    virtual void DeleteThis();
    volatile long m_uiRefCount; // offset 4
    char pad08[0x28];           // 0x08..0x2f
    unsigned int m_uiValue1;     // 0x30
};

struct MapHelper_00c5e080 {
};

struct Limits_00c5e080 {
    unsigned short maxCount; // offset 0 -> [ebp - 0x2c]
    unsigned short curCount; // offset 2 -> [ebp - 0x2a]
};

// Scans entries from cursor unkc0, removing those whose object has refcount 1 or m_uiValue1 bit 0 set, and recounts kept entries in unkb8, capped at unkba.
// @fnv 0x00c5e080
void S_00c5e3d0::FUN_00c5e080()
{
    int p;
    unsigned int v;
    Node_00c5e080* a;
    Node_00c5e080* n;
    int s;
    Node_00c5e080** f;
    int Flag;
    Node_00c5e080* Tmp;
    int BB;
    int b;
    Limits_00c5e080 Mgr;

    this->unkb8 = 0;
    if (!this->unkc0) {
        s = this->unkac;
        this->unkc0 = s;
    }
    p = 0;
    v = this->unkb4;
    while (this->unkc0 && v-- > 0) {
        f = (Node_00c5e080**)((char*)this->unkc0 + 8);
        a = *f;
        Flag = a->m_uiRefCount;
        if (Flag == 1 || (bool)(a->m_uiValue1 & 1 ? 1 : 0)) {
            RemovePointerListPos(&this->unkac, reinterpret_cast<void*&>(n));
            if (n) {
                Tmp = n;
                if (!InterlockedDecrement(&Tmp->m_uiRefCount)) {
                    Tmp->DeleteThis();
                }
            }
        } else {
            if (this->unkb8 == this->unkba) {
                p = this->unkc0;
            }
            this->unkb8++;
            BB = this->unkc0;
            this->unkc0 = BB ? *(int*)BB : 0;
        }
        if (!this->unkc0) {
            b = this->unkac;
            this->unkc0 = b;
        }
    }
    if (p) {
        this->unkc0 = p;
    }
    Mgr.maxCount = this->unkba;
    Mgr.curCount = this->unkb8;
    this->unkb8 = (Mgr.curCount < Mgr.maxCount) ? Mgr.curCount : Mgr.maxCount;
    if (!this->unkb8) {
        this->unkc0 = 0;
    }
}

struct C48Entry { int type; int a; int b; };

struct C48Rec {
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
    int m_60;
};

struct C48Sub {
    int m_04;
    C48Rec* m_08;
    int m_0c;
    int m_10;
};

struct C48Arr {
    int m_14;
    C48Entry* m_18;
    int m_1c;
    int m_20;
};

struct C48Obj {
};

struct C48Owner {
    int unk00;
    C48Sub m_04;
    C48Arr m_14;
    int m_24;
    int m_28;
    void FUN_00c48db0(C48Owner* src, C48Obj* obj);
};


struct S_Pt {
    float x;
    float y;
    float z;
};

struct S_Poly {
    int unk00;
    S_Pt* pts;

};

class S_cls {
public:
    S_Poly* m_pPoly;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_uiItemCount;
    float FUN_00c4d9d0();
};
// @fnv 0x00c4d9d0
float S_cls::FUN_00c4d9d0()
{
    int i;
    float area8 = 0.0f;
    for (i = 0; i < m_uiItemCount; i++) {
        int j3 = (i + 1) % m_uiItemCount;
        S_Pt* a9 = &m_pPoly->pts[i];
        area8 += a9->x * m_pPoly->pts[j3].y;
        S_Pt* b = &m_pPoly->pts[i]; area8 -= (double)b->y * m_pPoly->pts[j3].x;
    }
    return area8 * 0.5;
}

struct FUN_00c31720_base
{
};

extern char g_unkVtable[];

// Calls Init on the FUN_00c31720_base part, sets p to g_unkVtable, f to 1.0f and c to 4000.
// @fnv 0x00c465a0
FUN_00c465a0::FUN_00c465a0()
{
    new ((void *)(reinterpret_cast<FUN_00c31720_base*>(this))) ::NiPSysPositionModifier();
    p = g_unkVtable;
    *(float*)&f = 1.0f;
    c = 4000;
}

struct NiPoint3;
struct NiPoint2;
struct RgbaColor;
enum NiGeometryDataFlags { NI_GEOM_DATA_DEFAULT = 0 };
class NiTriShape
{
  public:
    NiTriShape(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal,
               RgbaColor* pkColor, NiPoint2* pkTexture, unsigned short usNumTextureSets,
               NiGeometryDataFlags eNBTMethod, unsigned short usTriangles,
               unsigned short* pusTriList);
    virtual ~NiTriShape();
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
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void Method58();
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
};
struct FUN_00c5cf30 : NiTriShape {
    FUN_00c5cf30(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal,
                      RgbaColor* pkColor, NiPoint2* pkTexture, unsigned short usNumTextureSets,
                      NiGeometryDataFlags eNBTMethod, unsigned short usTriangles,
                      unsigned short* pusTriList, int aiLeft, int aiTop, int aiRight,
                      int aiBottom);
};
// Constructs the NiTriShape base, sets its vtable, and stores aiLeft, aiTop, aiRight and aiBottom at offsets 0xc4 through 0xd0.
// @fnv 0x00c5cf30
FUN_00c5cf30::FUN_00c5cf30(unsigned short usVertices, NiPoint3* pkVertex,
    NiPoint3* pkNormal, RgbaColor* pkColor, NiPoint2* pkTexture,
    unsigned short usNumTextureSets, NiGeometryDataFlags eNBTMethod,
    unsigned short usTriangles, unsigned short* pusTriList, int aiLeft, int aiTop,
    int aiRight, int aiBottom)
    : NiTriShape(usVertices, pkVertex, pkNormal, pkColor, pkTexture, usNumTextureSets,
                 eNBTMethod, usTriangles, pusTriList)
{
    *(int*)((char*)this + 0x0) = (intptr_t)&DAT_010c2e7c;
    *(int*)((char*)this + 0xc4) = aiLeft;
    *(int*)((char*)this + 0xc8) = aiTop;
    *(int*)((char*)this + 0xcc) = aiRight;
    *(int*)((char*)this + 0xd0) = aiBottom;
}

namespace fnv_00c4b500 {

struct Node;
struct NodeV { void* v0; void* v1; void* v2; Node* (*GetNode)(Node*); };
struct Node {
    NodeV* vt;
    char unk04[0x2C];
    unsigned int flags;
    char unk34[0x6C];
    Node** children;
    char unkA4[2];
    unsigned short count;
};
// Sets flag bits 2 and 4 and clears 0x10 on n, then recurses on each child of the node returned by its GetNode virtual.
// @fnv 0x00c4b500
void FUN_00c4b500(Node* apNode)
{
    if (apNode) {
                if (1) apNode->flags |= 2; else apNode->flags &= ~(unsigned)(apNode, 2);
                if (1) apNode->flags |= 4; else apNode->flags &= ~(unsigned)(apNode, 4);
                if (0) apNode->flags |= 0x10; else apNode->flags &= ~(unsigned)(apNode, 0x10);
        Node* g = apNode->vt->GetNode(apNode);
        if (g) {
            for (unsigned i = 0; i < g->count; i++) {
                Node** p = &g->children[i];
                Node* pChildNode = *p;
                FUN_00c4b500(pChildNode);
            }
        }
    }
}
}  // namespace fnv_00c4b500

// for each of one listed worker, release its semaphore and bump its counter.

struct WorkerItemC44 {
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
    SemaphoreC44 m_kCompletionSemaphore;
};

// Releases the completion semaphore of the worker item at index 0 and increments its count.
// @fnv 0x00c44cd0
void FUN_00c44cd0_class::FUN_00c44cd0() {
    for (unsigned int i = 0; i < 1; i++) {
        WorkerItemC44* item = (*(WorkerItemC44***)this)[i];
        SemaphoreC44* sem = &item->m_kCompletionSemaphore;
        ReleaseSemaphore(sem->m_pSemaphore, 1, 0);
        InterlockedIncrement(&sem->m_lCount);
    }
}


struct FUN_00c49f10_Entry {
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_00c49f10_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00c49f10_Entry* unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;

    void FUN_00c49f10();
};

// Walks the entry array, tracking a running balance from entry types, and triggers DebugBreak if the balance goes negative or is non-zero at the end.
// @fnv 0x00c49f10
void FUN_00c49f10_Obj::FUN_00c49f10() {
    int balance = 0;

    for (int index = 0; index < this->unk28; ++index) {
        if (this->unk18[index].unk00 == 4 ||
            this->unk18[index].unk00 == 5) {
            ++balance;
        }
        else if (this->unk18[index].unk00 == 6) {
            --balance;
        }
        else if (this->unk18[index].unk00 == 7 ||
                 this->unk18[index].unk00 == 8) {
            ++index;
        }

        if (balance < 0) {
            DebugBreak();
        }
    }

    if (balance != 0) {
        DebugBreak();
    }
}

struct RangeNameObj {
    int unk00;
    int unk04;
    const char* m_pcName;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    short unkAC;
    unsigned char m_ucMin;
    unsigned char m_ucMax;
    void FUN_00c45670();
};

// Parses a trailing numeric range from m_pcName, extracting min and max values into m_ucMin and m_ucMax.
// @fnv 0x00c45670
void RangeNameObj::FUN_00c45670()
{
    const char* pcName2 = m_pcName;
    const char* pcStr = pcName2;
    unsigned int uiLen = strlen(pcStr);
    unsigned int i = 1;
    while (((pcStr[uiLen - i] >= '0' && pcStr[uiLen - i] <= '9') || pcStr[uiLen - i] == '-') && i <= uiLen)
        i++;
    pcStr = pcStr + (uiLen - i) + 1;
    int iMin = 0;
    int iMax_2 = 0xff;
    const char* pcDash = strstr(pcStr, "-");
    if (pcDash) {
        if (pcDash != pcStr)
            iMin = std::atoi(pcStr);
        pcStr = pcDash + 1;
        if (*pcStr)
            iMax_2 = std::atoi(pcStr);
    } else if (*pcStr) {
        iMin = std::atoi(pcStr);
        iMax_2 = iMin;
    }
    int iLow6;
    if (iMin < iMax_2)
        iLow6 = iMin;
    else
        iLow6 = iMax_2;
    m_ucMin = (unsigned char)iLow6;
    int iHigh4;
    if (iMin > iMax_2)
        iHigh4 = iMin;
    else
        iHigh4 = iMax_2;
    m_ucMax = (unsigned char)iHigh4;
}


struct RegistryClose : RegSettingCollection
{
    bool FUN_00c5d9b0();
};

// Closes the open registry key hKey via RegCloseKey, clears hKey to zero, and returns whether the close succeeded.
// @fnv 0x00c5d9b0
bool RegistryClose::FUN_00c5d9b0()
{
    bool ok = true;
    HKEY key = hKey;
    if (key != 0)
    {
        HKEY h = hKey;
        ok = (RegCloseKey(h) == 0);
        hKey = 0;
    }
    return ok;
}

class C5F080Node : public NiExtraDataSaveHelper {

public:

    unsigned int unk00;

    unsigned int unk04;

    unsigned int unk08;

    unsigned int unk0C;

    C5E7A0Object** items;

    unsigned int count;



    void FUN_00c5f080(C5E7A0Stream& stream);

};



// Saves the node's binary data by calling the base class, writing the item count, and saving the link ID of each item in the items array.
// @fnv 0x00c5f080
void C5F080Node::FUN_00c5f080(C5E7A0Stream& stream)

{

    unsigned int iterationCount;

    unsigned int initialCount;

    unsigned int countToWrite;

    unsigned int index;



    reinterpret_cast<::FUN_00a7b2c0_shell *>(this)->FUN_00a7b2c0(reinterpret_cast<NiStream&>(stream));



    initialCount = count;

    countToWrite = initialCount;

    ::FUN_0044adf0((::MiddleHighProcess *)&(stream), (intptr_t)(&countToWrite));



    for (index = 0; index < (iterationCount = count); ++index)

        stream.SaveLinkID(items[index]);

}


struct TaskThreadResume {
    void* virtualTable;
    void* threadHandle;
    void FUN_00c42f50();
};

// @fnv 0x00c42f50
void TaskThreadResume::FUN_00c42f50()
{
    ResumeThread(threadHandle);
}

struct Base_00c452f0 {
};


struct FUN_00c452f0_fields {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    unsigned char m_ac;
    unsigned char field_ad;
    unsigned char field_ae;
    unsigned char field_af;
    void FUN_00c452f0(int a1);
};

// Calls the base class stream write, then writes field_ae, field_af, and field_ad to the NiStream via FUN_00a29550.
// @fnv 0x00c452f0
void FUN_00c452f0_fields::FUN_00c452f0(int apStream)
{
    unsigned char value;

    reinterpret_cast<::NodeA5E8 *>((((Base_00c452f0*)this)))->FUN_00a5e880(
        (::NiStreamA5E8 &)(*reinterpret_cast<NiStream*>(apStream)));

    {
        unsigned char value_ae;
        value_ae = field_ae;
        value = value_ae;
        ::FUN_00a29550(
            (intptr_t)&(*reinterpret_cast<NiStream*>(apStream)),
            (intptr_t)(&value));

        {
            unsigned char value_af;
            value_af = field_af;
            value = value_af;
            ::FUN_00a29550(
                (intptr_t)&(*reinterpret_cast<NiStream*>(apStream)),
                (intptr_t)(&value));

            {
                unsigned char value_ad;
                value_ad = field_ad;
                value = value_ad;
                ::FUN_00a29550(
                    (intptr_t)&(*reinterpret_cast<NiStream*>(apStream)),
                    (intptr_t)(&value));
            }
        }
    }
}


struct RegistryOpen : RegSettingCollection {
    bool FUN_00c5d920(bool create);
};

// Opens or creates the registry key under HKEY_LOCAL_MACHINE using RegOpenKeyExA or RegCreateKeyExA depending on the create flag.
// @fnv 0x00c5d920
bool RegistryOpen::FUN_00c5d920(bool create)
{
    DWORD disposition;
    bool result;
    result = false;
    if (create) {
        result = (RegCreateKeyExA((HKEY)0x80000002, reinterpret_cast<const char*>(&unk004), 0, 0, 0, 0xf003f, 0, &hKey, &disposition) == 0);
    } else {
        result = (RegOpenKeyExA((HKEY)0x80000002, reinterpret_cast<const char*>(&unk004), 0, 0xf003f, &hKey) == 0);
    }
    return result;
}

int FUN_00c42da0(FUN_00c42da0_Class* p);



bool FUN_00c45ab0();












extern "C" char* __cdecl _strchr(const char*, int);

extern "C" int __cdecl _strcpy_s(char*, unsigned int, const char*);

void __cdecl CopyMainNameFromPath(int param_1, char* param_2);


void FUN_00c45820(int value);

int FUN_00c45ad0();

void __cdecl FUN_00c45b10(unsigned short value);

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);








FUN_00c465a0* __cdecl FUN_00c46740();







float __cdecl EvaluateQuinticPolynomial(float x);


extern "C" void(* FUN_00fdf1c0)(void*);

extern "C" char DAT_011f6238;

typedef void(* S_00c422d0_IAT_Fn)(void*);

extern "C" int __cdecl FUN_00ec6130(const char* s);

extern "C" int __cdecl FUN_00eca6d3(const char* s);

extern "C" char* __cdecl FNV_StrChr(const char* s, int c);

extern "C" unsigned int __cdecl FNV_StrLen(const char* s);

extern "C" void __cdecl FNV_CopyPath(char* dest, unsigned int destSize, const char* src, unsigned int count);

void __cdecl CopyStringBeforeColon(FUN_00c43e00_Obj* pObj, char* pDest);




extern void* __cdecl FUN_00c46170(unsigned int count);


void __cdecl FUN_00c468c0(float a1, float a2);








extern NavHolder g_navHolder;




extern FNV_MemoryManager FNV_g_memoryManager;


void FUN_00c55cd0(const C55CD0Point3& kTargetCenter, float fSize, unsigned int uiColor);





extern "C" char DAT_011f6238;

unsigned int __cdecl FUN_00c5fb80_strlen(const char* s);

void __cdecl FUN_00c5fb80_copyPrefix(char* dst, unsigned int len, const char* src);

char* __cdecl FUN_00c5fb80_appendTail(char* dst, unsigned int len, const char* src);

char* __cdecl ConcatPrefixAndSuffix(FUN_00c5fb80_rec* rec, const char* suffix);

int __cdecl FUN_00ec658f(void(__cdecl*)());





C45440_Obj* __cdecl CreateC45440Obj(void);

struct ShapeEntry
{
    virtual ~ShapeEntry();
};

extern void* DAT_010c16dc;

struct ShapeList
{
    void* vtable;
    ShapeEntry** data;
    unsigned count;
    void FUN_00c409e0();
};

namespace fnv_00c409b0 {
// @fnv 0x00c409b0
void* FUN_00c409b0_Class::FUN_00c409b0(unsigned int flags)
{
    reinterpret_cast<::ShapeList *>((((FUN_00c409e0_Class*)this)))->FUN_00c409e0();
    if (flags & 1)
        ((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))->Deallocate(this);
    return this;
}
}  // namespace fnv_00c409b0

static inline void FreeShapeArray(void* memory)
{
    reinterpret_cast<::FNV_MemoryManager *>((((SpawnHeap_cls*)&DAT_011f6238)))->FUN_00aa4060(memory);
}

// @fnv 0x00c409e0
void ShapeList::FUN_00c409e0()
{
    vtable = &DAT_010c16dc;
    unsigned index;
    for (index = 0; index < count; ++index)
    {
        delete data[index];
    }
    FreeShapeArray(data);
}

struct FNV_Base_c40aa0
{
    virtual __forceinline ~FNV_Base_c40aa0()
    {}
};

struct FNV_MM_c40aa0
{
};

extern "C" char DAT_011f6238;

struct FUN_00c40aa0 : FNV_Base_c40aa0
{
    int unk04;
    int unk08;
    int unk0c;
    void* m_pData;
    virtual ~FUN_00c40aa0();
};

namespace fnv_00c40a70 {
// @fnv 0x00c40a70
void* FUN_00c40a70_Class::FUN_00c40a70(unsigned int flags)
{
    reinterpret_cast<::FUN_00c40aa0 *>(this)->FUN_00c40aa0::~FUN_00c40aa0();
    if (flags & 1)
        ((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))->Deallocate(this);
    return this;
}
}  // namespace fnv_00c40a70

typedef void* HANDLE;

typedef unsigned long(* LPTHREAD_START_ROUTINE)(void*);

struct Semaphore42A
{
    long count;
    HANDLE handle;
    long maximum;
    Semaphore42A()
    {
        count = 0;
        maximum = 0x7fffffff;
        handle = CreateSemaphoreA(0, count, maximum, 0);
    }
    ~Semaphore42A();
};

struct Semaphore42B
{
    long count;
    HANDLE handle;
    long maximum;
    Semaphore42B()
    {
        count = 1;
        maximum = 1;
        handle = CreateSemaphoreA(0, count, maximum, 0);
    }
    ~Semaphore42B();
};

struct FUN_00c42dd0
{
    virtual void vfn();
    HANDLE thread;
    unsigned long threadId;
    Semaphore42A first;
    Semaphore42B second;
    int unk24;
    int unk28;
    unsigned long unk2c;
    FUN_00c42dd0(int, const char* name);
};

// @fnv 0x00c42dd0
FUN_00c42dd0::FUN_00c42dd0(int, const char* name)
{
    thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)FUN_00c42da0, this, 4, &threadId);
    if (name)
        ::SetDebuggerThreadName(threadId, name);
    unk24 = 0;
    unk28 = 0;
    unk2c = threadId;
}

struct Ref354
{
    virtual void v00();
    virtual void Destroy();
    volatile long references;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&references))
            Destroy();
    }
};

struct Pointer354
{
    Ref354* value;
    ~Pointer354()
    {
        if (value)
            value->DecRefCount();
    }
};

struct Array354
{
    Pointer354 FUN_00c45e50(unsigned int index);
};

struct LockState354
{
    unsigned int owner, recursion;
    void FUN_0040fbf0(int);
};

unsigned int gm_GetCurrentThreadId();

long FUN_0043b460(volatile long*, long comparand, long exchange);

inline void LockState354::FUN_0040fbf0(int)
{
    unsigned int thread = gm_GetCurrentThreadId();
    if (owner == thread)
    {
        ++recursion;
    }
    else
    {
        unsigned int attempts = 0;
        while (FUN_0043b460((volatile long*)&owner, 0, thread))
        {
            ++attempts;
            if (attempts > 10000)
                FUN_0040fca0(1);
            else
                FUN_0040fca0(0);
        }
        FUN_0040fbe0();
        recursion = 1;
    }
}

inline unsigned int CleanupDeadline354()
{
    unsigned int start = GetTickCount();
    return start + DAT_011af758;
}

// @fnv 0x00c458f0
void FUN_00c458f0()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::LockState354 *>(&::DAT_01202e40))))->FUN_0040fbf0((char *)(0));
    unsigned int deadline = CleanupDeadline354();
    unsigned int now5 = 0;
    unsigned int remaining7 = DAT_01202e2c;
    if (remaining7 > 200)
        deadline += 1000;
    for (; remaining7 > 0 && now5 < deadline; --remaining7)
    {
        (*reinterpret_cast<::Array354 *>(&::DAT_01202e20)).FUN_00c45e50(remaining7 - 1);
        now5 = GetTickCount();
    }
    if (remaining7 == 0)
        ::fnv_00c45a80::TruncateStringToMaxLength();
    --DAT_01202e44;
    if (!DAT_01202e44)
        (*reinterpret_cast<::LockState354 *>(&::DAT_01202e40)).owner = 0;
}

struct Ref351
{
    virtual void v00();
    virtual void Destroy();
    volatile long references;
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

struct Pointer351
{
    Ref351* pointer;
    Pointer351() : pointer(0)
    {
        if (pointer)
            pointer->IncRefCount();
    }
    ~Pointer351()
    {
        if (pointer)
            pointer->DecRefCount();
    }
};

// @fnv 0x00c46170
void* FUN_00c46170(unsigned int count)
{
    return new Pointer351[count];
}

struct C46Child
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
    virtual void v54(NiStream* s);
};

struct C46Class : FUN_00a5e5b0_helper
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8;
    C46Child* m_pChildObject;
    C46Child* GetChild() const
    {
        return m_pChildObject;
    }
    bool FUN_00c46d10(NiStream* s);
};

// @fnv 0x00c46d10
bool C46Class::FUN_00c46d10(NiStream* s)
{
    if (!((unsigned char)(::fnv_00a5e5b0::RegisterChildStreamables((::NiNode *)this, (std::intptr_t)(s), *(::fnv_00a5e5b0::NiStream *)nullptr))))
        return false;
    GetChild()->v54(s);
    return true;
}

struct Node_00c474a0
{
    virtual void vf00();
    virtual void vf04();
    virtual void* vf08();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Node_00c474a0* next;
};

inline void Node_00c474a0::vf00()
{}

inline void Node_00c474a0::vf04()
{}

inline void* Node_00c474a0::vf08()
{
    return 0;
}

__forceinline bool ContainsActor(Node_00c474a0* p)
{
    bool found;
    if (p == 0)
        found = false;
    else
        found = p->vf08() == &(*reinterpret_cast<void * *>(&::g_01202e74));
    return found;
}

// @fnv 0x00c474a0
Node_00c474a0* __cdecl FUN_00c474a0(Node_00c474a0* a1)
{
    Node_00c474a0* cur = a1;

    while (cur != 0 && !ContainsActor(cur))
        cur = cur->next;

    if (ContainsActor(cur))
        return cur;

    return 0;
}

struct ChainInner
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07();
    virtual void v08(), v09(), v10(), v11(), v12(), v13(), v14(), v15();
    virtual void v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23();
    virtual void v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31();
    virtual void v32(), v33(), v34(), v35(), v36();
    virtual int v37(int a);
};

struct ChainMid
{
    int unk00, unk04, unk08;
    ChainInner* m_0c;
};

struct ChainOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8;
    ChainMid* m_ac;
    ChainInner* GetInner()
    {
        ChainMid* mid = m_ac;
        ChainInner* inner = mid->m_0c;
        return inner;
    }
    int FUN_00c475c0(int a);
};

// @fnv 0x00c475c0
int ChainOwner::FUN_00c475c0(int a)
{
    int r = GetInner()->v37(a);
    return r;
}

struct SimpleArrayBase
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void Free(void* p);
    void* m_p;
    unsigned int m_uiItemCount;
    unsigned int m_alloc;
    void Clear(bool bFree)
    {
        if (m_p)
        {
            for (unsigned int i = 0; i < m_uiItemCount; i++)
            {
            }
            if (bFree)
            {
                Free(m_p);
                m_p = 0;
                m_p = 0;
                m_alloc = 0;
            }
            m_uiItemCount = 0;
        }
    }
};

struct SimpleArrayA : SimpleArrayBase
{
    ~SimpleArrayA();
};

struct SimpleArrayB : SimpleArrayBase
{
    ~SimpleArrayB();
};

struct FUN_00c47770
{
    int m_00;
    SimpleArrayA m_kList1;
    SimpleArrayB m_kList2;
    ~FUN_00c47770();
};

// @fnv 0x00c47770
FUN_00c47770::~FUN_00c47770()
{
    reinterpret_cast<::FUN_00c4a9c0_class *>(&(m_kList1))->ReleaseBuffer(true);
    reinterpret_cast<::FUN_00c4a9c0_class *>(&(m_kList2))->ReleaseBuffer(true);
}

struct TokElem_c48ca0
{
    int iType;
    int a;
    int b;
};

struct TokArr_c48ca0
{
    int _0;
    TokElem_c48ca0* m_pData;
    int _8;
    int m_iCapacity;
    void FUN_00c4a1e0(int, bool);
};

struct TokStack_c48ca0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    TokArr_c48ca0 m_kArray;
    int _24;
    int m_iArrayLength;
    int TopIdx()
    {
        return 0;
    }
    void FUN_00c48ca0();
};

TokStack_c48ca0 g_ts;

void __cdecl use_all()
{
    g_ts.FUN_00c48ca0();
}

struct C4F320Child
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c();
    virtual void v20(), v24(), v28(), v2c(), v30(), v34(), v38(), v3c();
    virtual void v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c();
    virtual void v60(), v64(), v68(), v6c(), v70(), v74(), v78(), v7c();
    virtual void v80(), v84(), v88(), v8c(), v90(), v94(), v98();
    virtual void V9c(int a);
};

template <class T> struct C4F320Ptr
{
    T* m_pObject;
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
};

struct C4F320Obj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    C4F320Child* m_pc4;
    C4F320Child* GetChild() const
    {
        return m_pc4;
    }
    void FUN_00c4f320(int a);
};

// @fnv 0x00c4f320
void C4F320Obj::FUN_00c4f320(int a)
{
    GetChild()->V9c(a);
}

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
public:
    static unsigned int ms_lObjectCount;
};

struct Mgr_00c50b80
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57(NiRefObject* a1, NiPointer<NiRefObject>& out);
    void FUN_00c50b80(NiRefObject* a1);
};

// @fnv 0x00c50b80
void Mgr_00c50b80::FUN_00c50b80(NiRefObject* a1)
{
    NiPointer<NiRefObject> tmp(0);
    v57(a1, tmp);
}

class DispatchRef
{
  public:
    virtual void vfn_00();
    virtual void Destroy();
    volatile long m_lRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            Destroy();
    }
};

class DispatchRefPtr
{
  public:
    DispatchRef* m_pObject;
    __forceinline DispatchRefPtr(DispatchRef* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~DispatchRefPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

class DispatchHelper
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void Invoke(int a, int b, DispatchRefPtr* out);
    void FUN_00c50df0(int a, int b);
};

// @fnv 0x00c50df0
void DispatchHelper::FUN_00c50df0(int a, int b)
{
    DispatchRefPtr ref;
    Invoke(a, b, &ref);
}

struct RefTarget
{
    virtual void Reserved();
    virtual void DeleteThis();
    volatile long refCount;
};

struct ScopedRef
{
    RefTarget* object;
    __forceinline ScopedRef() : object(0)
    {
        if (object)
        {
            RefTarget* retained = object;
            InterlockedIncrement(&retained->refCount);
        }
    }
    __forceinline ~ScopedRef()
    {
        if (object)
        {
            RefTarget* released = object;
            if (InterlockedDecrement(&released->refCount) == 0)
                released->DeleteThis();
        }
    }
};

struct Owner
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void GetRefTarget(int, RefTarget**);
    void FUN_00c51700(intptr_t);
};

// @fnv 0x00c51700
void Owner::FUN_00c51700(intptr_t arg)
{
    ScopedRef ptr;
    GetRefTarget(arg, &ptr.object);
}

extern "C" char DAT_011f6238;

struct HeapAB
{
};

void __cdecl FUN_00aa10f0(void* p);

inline void FreeAB(void* p)
{
    FUN_00aa10f0(p);
}

struct ItemAB
{
    void* m_pData;
    ~ItemAB()
    {
        FreeAB(m_pData);
    }
};

template <class T> class ArrAB
{
  public:
    virtual ~ArrAB();
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
    __forceinline void RemoveAll()
    {
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

struct OwnerAB
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    ArrAB<ItemAB*> m_kArray;
    void FUN_00c52880();
};

// @fnv 0x00c52880
void OwnerAB::FUN_00c52880()
{
    for (unsigned int i = 0; i < m_kArray.GetSize(); i++)
    {
        ItemAB* pkItem = m_kArray.GetAt(i);
        delete pkItem;
    }
    m_kArray.RemoveAll();
}

struct Heap_c55
{
};

extern int EmptyFS_c55;

struct FixedString_c55
{
    int m_str;
    ~FixedString_c55()
    {
        if (m_str == EmptyFS_c55)
        {
        }
        else
        {
            long* p = (long*)(m_str - 8);
            InterlockedDecrement(p);
        }
    }
};

// @fnv 0x00c552a0
void FUN_00c552a0()
{
    delete g_pkString_c55;
    g_pkString_c55 = 0;
}

struct Vec3A
{
    float x, y, z;
    Vec3A()
    {}
    Vec3A(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

struct Vec2A
{
    float x, y;
    Vec2A()
    {}
    Vec2A(float a, float b) : x(a), y(b)
    {}
};

struct ColorA
{
    float r, g, b, a;
    ColorA() : r(0), g(0), b(0), a(0)
    {}
};

class NiPoint2
{
  public:
    float x, y;
};


// @fnv 0x00c55360
NiTriShape* __cdecl FUN_00c55360(float extent, NiPoint3* center, ColorA* color)
{
    const NiPoint3* srcPtr4 = center ? center : &::NiPoint3::ZERO;
    NiPoint3 centerVal2 = *srcPtr4;
    Vec3A* verts = new Vec3A[4];
    Vec3A* normals = new Vec3A[4];
    ColorA* colors = color ? new ColorA[4] : 0;
    Vec2A* tex = new Vec2A[4];
    unsigned short* indices = new unsigned short[6];
    verts[0] = Vec3A(centerVal2.x - extent, centerVal2.y + extent, 0.0f);
    normals[0] = *(const Vec3A*)&DAT_011a9484;
    if (color)
        colors[0] = *color;
    tex[0] = Vec2A(0.0f, 0.0f);
    verts[1] = Vec3A(centerVal2.x + extent, centerVal2.y + extent, 0.0f);
    normals[1] = *(const Vec3A*)&DAT_011a9484;
    if (color)
        colors[1] = *color;
    tex[1] = Vec2A(1.0f, 0.0f);
    verts[2] = Vec3A(centerVal2.x - extent, centerVal2.y - extent, 0.0f);
    normals[2] = *(const Vec3A*)&DAT_011a9484;
    if (color)
        colors[2] = *color;
    tex[2] = Vec2A(0.0f, 1.0f);
    verts[3] = Vec3A(centerVal2.x + extent, centerVal2.y - extent, 0.0f);
    normals[3] = *(const Vec3A*)&DAT_011a9484;
    if (color)
        colors[3] = *color;
    tex[3] = Vec2A(1.0f, 1.0f);
    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;
    indices[3] = 2;
    indices[4] = 1;
    indices[5] = 3;
    NiTriShape* shape5 =
        new NiTriShape(4, (NiPoint3*)verts, (NiPoint3*)normals, (RgbaColor*)colors, (NiPoint2*)tex, 0, (NiGeometryDataFlags)0, 2, indices);
    shape5->Method58();
    return shape5;
}

struct RefObj5b
{

    virtual ~RefObj5b();

    virtual void DeleteThis();

    volatile long m_uiRefCount;

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

    unsigned int m_uiValue1;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    void SetBit(bool bVal, unsigned int uiMask)
    {

        if (bVal)
            m_uiValue1 |= uiMask;

        else
            m_uiValue1 &= ~uiMask;
    }
};

struct SPtr5b
{

    RefObj5b* m_pObject;

    SPtr5b(const SPtr5b& other)
    {

        m_pObject = other.m_pObject;

        if (m_pObject)
            m_pObject->IncRefCount();
    }

    ~SPtr5b()
    {

        if (m_pObject)
        {

            m_pObject->DecRefCount();
        }
    }

    operator RefObj5b*() const
    {
        return m_pObject;
    }

    RefObj5b* operator->() const
    {
        return m_pObject;
    }

    bool operator==(RefObj5b* p) const
    {
        return m_pObject == p;
    }
};

struct SArray5b
{
    virtual ~SArray5b();
    SPtr5b* data;
    unsigned short capacity, size, used, grow;
    const SPtr5b& GetAt(unsigned int i) const
    {
        return data[i];
    }
    unsigned short GetSize() const
    {
        return size;
    }

    SPtr5b FUN_00c5bb60(unsigned int uiIndex);
};

struct Owner5b
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

    SArray5b m_kArray;

    SPtr5b* m_pBase;

    unsigned short unk44;

    unsigned short m_usSize;

    void FUN_00c5b740(RefObj5b* pkObj);
};


// @fnv 0x00c5b740
void Owner5b::FUN_00c5b740(RefObj5b* pkObj)

{

    for (unsigned int i = 0; i < m_kArray.size; i++)
    {

        SPtr5b pSceneObject = m_kArray.GetAt(i);

        if (pSceneObject && pSceneObject == pkObj)
        {

            m_kArray.FUN_00c5bb60(i);

            pSceneObject->SetBit(false, 1);

            break;
        }
    }
}

struct EmptyBase332
{
    ~EmptyBase332()
    {}
};

int FUN_004019a0(long*);

unsigned int FUN_0040b460(void*);

struct PathingSolution332
{
    virtual void v00();
    virtual void Destroy();
    long references;
    void FUN_00401970()
    {
        if (!FUN_004019a0(&references))
            Destroy();
    }
    void FUN_0040f6e0()
    {
        FUN_0040b460(&references);
    }
};

struct PathReference332
{
    PathingSolution332* value;
    void Reset(PathingSolution332* replacement)
    {
        if (value != replacement)
        {
            if (value)
                value->FUN_00401970();
            value = replacement;
            if (value)
                value->FUN_0040f6e0();
        }
    }
};

struct ListNode332
{
    ListNode332* next;
    ListNode332* previous;
    PathReference332 path;
};

unsigned int gm_GetCurrentThreadId();

long FUN_0043b460(volatile long* target, long comparand, long exchange);

struct PoolLock332
{
    volatile long owner;
    unsigned int recursion;
    void Lock(const char*)
    {
        unsigned int thread = gm_GetCurrentThreadId();
        if ((unsigned int)owner == thread)
        {
            ++recursion;
        }
        else
        {
            unsigned int attempts = 0;
            while (FUN_0043b460(&owner, 0, thread))
            {
                ++attempts;
                FUN_0040fca0(attempts > 10000 ? 1 : 0);
            }
            FUN_0040fbe0();
            recursion = 1;
        }
    }
    void Unlock()
    {
        FUN_0040fbe0();
        --recursion;
        if (!recursion)
            owner = 0;
    }
};

extern PoolLock332 g_011c5f80;

extern ListNode332* NiTAbstractPoolAllocator_unsigned_int_instance;

struct Pool332
{
    unsigned int count;
    void FUN_0045cee0(void* memory)
    {
        g_011c5f80.Lock(0);
        ListNode332* node = (ListNode332*)memory;
        node->previous = 0;
        node->next = NiTAbstractPoolAllocator_unsigned_int_instance;
        NiTAbstractPoolAllocator_unsigned_int_instance = node;
        g_011c5f80.Unlock();
    }
};

struct List332 : EmptyBase332
{
    ListNode332* head;
    ListNode332* tail;
    Pool332 pool;
    void FUN_004a4930(void* memory)
    {
        ((ListNode332*)memory)->path.Reset(0);
        pool.FUN_0045cee0(memory);
    }
    void FUN_004a4650()
    {
        ListNode332* current = head;
        while (current)
        {
            ListNode332* retired = current;
            current = current->next;
            FUN_004a4930(retired);
        }
        pool.count = 0;
        head = 0;
        tail = 0;
    }
};

struct FUN_00c5bb10 : List332
{
    ~FUN_00c5bb10();
};

// @fnv 0x00c5bb10
FUN_00c5bb10::~FUN_00c5bb10()
{
    ::FUN_004a4650((::FUN_004a4650_ListBase *)this);
}

struct RefObjSI
{
    virtual ~RefObjSI();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
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

struct RefPtrSI
{
    RefObjSI* m_pObject;
    RefPtrSI(const RefPtrSI& o) : m_pObject(o.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~RefPtrSI()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    bool operator==(const RefPtrSI& o) const
    {
        return m_pObject == o.m_pObject;
    }
};

struct ListItemSI
{
    ListItemSI* m_pkNext;
    ListItemSI* m_pkPrev;
    RefPtrSI m_element;
};

struct MapSI
{
    ListItemSI* m_pkHead;
    ListItemSI* GetHeadPos() const
    {
        return m_pkHead;
    }
    RefPtrSI& GetNext(ListItemSI*& pos) const
    {
        RefPtrSI& e = pos->m_element;
        pos = pos->m_pkNext;
        return e;
    }
    ListItemSI* FindPos(const RefPtrSI& key, ListItemSI* pos = 0) const
    {
        if (!pos)
            pos = GetHeadPos();
        while (pos)
        {
            ListItemSI* cur = pos;
            if (key == GetNext(pos))
                return cur;
        }
        return 0;
    }
    RefPtrSI Resolve(ListItemSI* const& pos);
    RefPtrSI FUN_00c5bda0(const RefPtrSI& key);
};

// @fnv 0x00c5bda0
RefPtrSI MapSI::FUN_00c5bda0(const RefPtrSI& key)
{
    ListItemSI* pos = FindPos(key);
    return pos ? Resolve(pos) : key;
}

void* NiMalloc660(unsigned int uiSize);

void NiFree660(void* p);

template <class T> struct PrimArray660
{
    void* m_vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    static T* Allocate(unsigned int auiCount)
    {
        return (T*)NiMalloc660(sizeof(T) * auiCount);
    }
    void FUN_00c4c920(unsigned int uiMaxSize)
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
        NiFree660(pSaveBase);
    }
    void FUN_0096ae90(unsigned int uiIndex, const T& element)
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
};

struct Stream660
{
    int m_00;
    unsigned int m_uiFormatVersion;
};

struct Base660
{
};

struct Obj660 : Base660
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8;
    PrimArray660<void*> m_kLinks;

    void FUN_00c5e660(Stream660* pkStream);
};

// @fnv 0x00c5e660
void Obj660::FUN_00c5e660(Stream660* pkStream)
{
    reinterpret_cast<::sa5e9d0::Node *>(this)->ReadChildListFromStream((::sa5e9d0::Stream *)(pkStream));
    if (pkStream->m_uiFormatVersion > 0xf)
    {
        unsigned int ItemUpdateArray = reinterpret_cast<::FUN_00a63460_shell *>((pkStream))->FUN_00a63460();
        if (ItemUpdateArray)
        {
            reinterpret_cast<::FUN_00c4c920_class *>(&(m_kLinks))->FUN_00c4c920(ItemUpdateArray);
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                void* pkLink = ((void *)(reinterpret_cast<::NiStream *>((pkStream))->GetLoadedObject()));
                reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kLinks))->SetAt(i, (char *&)(pkLink));
            }
        }
    }
}

struct Key8
{
    int a;
    int b;
};

struct Lock40
{
    int owner;
    int count;
    void Unlock()
    {
        count--;
        if (count == 0)
            owner = 0;
    }
};

struct Iter40
{
    int u00;
    int u04;
    unsigned int idx;
    int u0C;
    __int64 key;
    unsigned char flags;
    bool GetFlag1()
    {
        return (flags & 1) ? true : false;
    }
    bool GetFlag2()
    {
        int aiD[46];
        return flags & 2;
    }
    void SetFlag1(bool v)
    {
        if (v)
            flags |= 1;
        else
            flags &= ~1;
    }
    void SetFlag2(bool v)
    {
        if (v)
            flags |= 2;
        else
            flags &= ~2;
    }
};

struct Bucket40
{
};

class Map40
{
  public:
    int u00;
    int u04;
    unsigned int cap;
    int u0C, u10, u14, u18, u1C;
    Lock40 lock;
    unsigned int GetCap()
    {
        return cap;
    }
    bool FUN_00c40e70(Iter40* it, __int64* out, intptr_t arg, bool b);
};

struct MM
{
    void* Allocate(unsigned int size);
};

extern MM _g_memoryManager;

__forceinline int GetTlsHeapState()
{
    return (*reinterpret_cast<int *>(&::currentAllocationContext));
}
__forceinline void SetTlsHeapState(int v)
{
    (*reinterpret_cast<int *>(&::currentAllocationContext)) = v;
}

struct TlsHeapStateGuard
{
    int saved;
    __forceinline TlsHeapStateGuard(int v)
    {
        saved = GetTlsHeapState();
        SetTlsHeapState(v);
    }
    __forceinline ~TlsHeapStateGuard()
    {
        SetTlsHeapState(saved);
    }
};

struct QueueRefObj
{
    int unk00;
    int unk04;
    volatile long refCount;
    void FUN_0044dd60();
    __forceinline void AcquireReference()
    {
        InterlockedIncrement(&refCount);
    }
};

struct QueueRefPtr
{
    QueueRefObj* m_p;
    __forceinline QueueRefPtr(QueueRefObj* p = 0)
    {
        m_p = p;
        if (m_p)
            m_p->AcquireReference();
    }
    __forceinline ~QueueRefPtr()
    {
        if (m_p)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_p));
    }
    __forceinline QueueRefPtr& operator=(QueueRefObj* p)
    {
        if (m_p != p)
        {
            if (m_p)
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_p));
            m_p = p;
            if (m_p)
                m_p->AcquireReference();
        }
        return *this;
    }
};

struct HandlerRegistration
{
    HandlerRegistration* next;
    QueueRefPtr item;
    __forceinline HandlerRegistration() : next(0)
    {}
};

struct InnerOwnedItem
{
    ~InnerOwnedItem();
};

struct InnerEntry
{
    unsigned int key;
    InnerOwnedItem* object;
};

struct Inner
{
    unsigned int unk00;
    void* unk04;
    InnerEntry* unk08;
    int unk0C;
    __forceinline int GetCount()
    {
        return unk00;
    }
    Inner(int a);
    ~Inner()
    {
        for (unsigned int i = 0; i < unk00; ++i)
            delete unk08[i].object;
        reinterpret_cast<::FNV_MemoryManager *>(&(_g_memoryManager))->FUN_00aa4060(unk08);
        DAT_0fdf050(unk04);
    }
};

unsigned int gm_GetCurrentThreadId();

struct Lock
{
    int owner;
    int count;
    void Acquire(const char* name)
    {
        unsigned int currentThread = gm_GetCurrentThreadId();
        if (owner == currentThread)
        {
            count = count + 1;
        }
        else
        {
            unsigned int spins = 0;
            while (FUN_0043b460((volatile long*)&owner, 0, currentThread))
            {
                spins = spins + 1;
                if (spins > 10000)
                    FUN_0040fca0(1);
                else
                    FUN_0040fca0(0);
            }
            FUN_0040fbe0();
            count = 1;
        }
    }
    __forceinline void Release()
    {
        count = count - 1;
        if (count == 0)
            owner = 0;
    }
};

struct Queue
{
    int unk00;
    HandlerRegistration* head;
    HandlerRegistration* tail;
    int unk0C;
    int unk10;
    Inner* inner;
    int unk18;
    int unk1C;
    Lock lock;
    void FUN_00c41330(bool keep);
};

// @fnv 0x00c40aa0
FUN_00c40aa0::~FUN_00c40aa0()
{
    reinterpret_cast<::Queue *>(this)->FUN_00c41330(1);
    void* pData = m_pData;
    void* pvMem = pData;
    reinterpret_cast<::FNV_MemoryManager *>((((FNV_MM_c40aa0*)&DAT_011f6238)))->FUN_00aa4060(pvMem);
}

// @fnv 0x00c41330
void Queue::FUN_00c41330(bool keep)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    TlsHeapStateGuard guard(6);
    int first = inner->GetCount();
    delete inner;
    inner = 0;
    unk18 = 0;
    while (head)
    {
        HandlerRegistration* next = head->next;
        head->item = 0;
        delete head;
        head = next;
    }
    if (!keep)
    {
        head = new HandlerRegistration;
        tail = head;
        inner = new Inner(first);
    }
    lock.Release();
}

namespace fnv_00c416a0 {
// Byte-identical with the pack's accepted /Ob1 flag set (1044 bytes).
// Nested declaration scopes preserve slot order; unused retains the 16-byte frame gap.
struct HandlerRegistration;
struct QueuePtr
{
    unsigned int bits;
};
struct HandlerRegistration
{
    NodeKey key;
    unsigned int object;
    QueuePtr next;
};
__forceinline unsigned int MaskExplicit(QueuePtr* p)
{
    return p->bits & ~1u;
}
struct QueueHandler
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
    virtual bool Test(NodeKey, NodeKey);
    virtual bool Result(NodeKey, NodeKey);
    int padding04, padding08;
    QueuePtr* buckets;
};
struct QueueSearch
{
    QueueHandler* handler;
    HandlerRegistration** outNext;
    HandlerRegistration** outCurrent;
    HandlerRegistration** outPrevious;
    QueuePtr* link;
    QueuePtr current;
    QueuePtr next;
    void FUN_00c41f40(HandlerRegistration*);
    bool FUN_00c416a0(int index, NodeKey key);
};
// @fnv 0x00c416a0
bool QueueSearch::FUN_00c416a0(int index, NodeKey key)
{
    QueuePtr* bucket;
    {
        bool retry;
        {
            QueuePtr initial;
            {
                QueuePtr expected;
                {
                    NodeKey found;
                    {
                        QueuePtr replacement;
                        {
                            QueuePtr* t20;
                            {
                                QueuePtr* t24;
                                {
                                    unsigned int t28;
                                    {
                                        QueuePtr* t2c;
                                        {
                                            unsigned int t30;
                                            {
                                                QueuePtr* t34;
                                                {
                                                    QueuePtr* t38;
                                                    {
                                                        QueuePtr* t3c;
                                                        {
                                                            QueuePtr* t40;
                                                            {
                                                                QueuePtr* t44;
                                                                {
                                                                    unsigned int t48;
                                                                    {
                                                                        QueuePtr* t4c;
                                                                        {
                                                                            HandlerRegistration* t50;
                                                                            {
                                                                                QueuePtr* t54;
                                                                                {
                                                                                    QueuePtr* t58;
                                                                                    {
                                                                                        QueuePtr* t5c;
                                                                                        {
                                                                                            QueuePtr* t60;
                                                                                            {
                                                                                                unsigned int t64;
                                                                                                {
                                                                                                    QueuePtr* t68;
                                                                                                    {
                                                                                                        unsigned int
                                                                                                            t6c;
                                                                                                        {
                                                                                                            QueuePtr*
                                                                                                                t70;
                                                                                                            {
                                                                                                                QueuePtr*
                                                                                                                    t74;
                                                                                                                {
                                                                                                                    QueuePtr*
                                                                                                                        t78;
                                                                                                                    {
                                                                                                                        QueuePtr*
                                                                                                                            t7c;
                                                                                                                        {
                                                                                                                            QueuePtr*
                                                                                                                                t80;
                                                                                                                            {
                                                                                                                                QueuePtr*
                                                                                                                                    t84;
                                                                                                                                {
                                                                                                                                    unsigned int
                                                                                                                                        t88;
                                                                                                                                    {
                                                                                                                                        QueuePtr*
                                                                                                                                            t8c;
                                                                                                                                        {
                                                                                                                                            unsigned int
                                                                                                                                                t90;
                                                                                                                                            {
                                                                                                                                                QueuePtr*
                                                                                                                                                    t94;
                                                                                                                                                {
                                                                                                                                                    unsigned int
                                                                                                                                                        t98;
                                                                                                                                                    {
                                                                                                                                                        bool
                                                                                                                                                            t99;
                                                                                                                                                        {
                                                                                                                                                            QueuePtr*
                                                                                                                                                                ta0;
                                                                                                                                                            {
                                                                                                                                                                QueuePtr*
                                                                                                                                                                    ta4;
                                                                                                                                                                {
                                                                                                                                                                    struct
                                                                                                                                                                        Unused
                                                                                                                                                                    {
                                                                                                                                                                        int a,
                                                                                                                                                                            b,
                                                                                                                                                                            c,
                                                                                                                                                                            d;
                                                                                                                                                                    } unused;
                                                                                                                                                                    {
                                                                                                                                                                        QueuePtr*
                                                                                                                                                                            tb8;
                                                                                                                                                                        bucket =
                                                                                                                                                                            &handler
                                                                                                                                                                                 ->buckets
                                                                                                                                                                                     [index];
                                                                                                                                                                        while (
                                                                                                                                                                            true)
                                                                                                                                                                        {
                                                                                                                                                                            retry =
                                                                                                                                                                                false;
                                                                                                                                                                            link =
                                                                                                                                                                                bucket;
                                                                                                                                                                            current =
                                                                                                                                                                                *link;
                                                                                                                                                                            t20 =
                                                                                                                                                                                &current;
                                                                                                                                                                            *outCurrent =
                                                                                                                                                                                (HandlerRegistration*)
                                                                                                                                                                                    MaskExplicit(
                                                                                                                                                                                        t20);
                                                                                                                                                                            t24 =
                                                                                                                                                                                &current;
                                                                                                                                                                            t28 =
                                                                                                                                                                                t24->bits &
                                                                                                                                                                                ~1u;
                                                                                                                                                                            initial
                                                                                                                                                                                .bits =
                                                                                                                                                                                t28;
                                                                                                                                                                            reinterpret_cast<::FUN_0044e010_class *>(&(initial))->FUN_0044e010(
                                                                                                                                                                                    false);
                                                                                                                                                                            t2c =
                                                                                                                                                                                link;
                                                                                                                                                                            t30 =
                                                                                                                                                                                t2c->bits;
                                                                                                                                                                            t34 =
                                                                                                                                                                                &initial;
                                                                                                                                                                            if (t30 !=
                                                                                                                                                                                (volatile unsigned int&)
                                                                                                                                                                                    t34->bits)
                                                                                                                                                                                continue;
                                                                                                                                                                            while (
                                                                                                                                                                                true)
                                                                                                                                                                            {
                                                                                                                                                                                t38 =
                                                                                                                                                                                    &current;
                                                                                                                                                                                if (!(t38->bits &
                                                                                                                                                                                      ~1u))
                                                                                                                                                                                    return false;
                                                                                                                                                                                t3c =
                                                                                                                                                                                    &current;
                                                                                                                                                                                next =
                                                                                                                                                                                    ((HandlerRegistration*)(t3c->bits &
                                                                                                                                                                                                            ~1u))
                                                                                                                                                                                        ->next;
                                                                                                                                                                                t40 =
                                                                                                                                                                                    &next;
                                                                                                                                                                                *outNext =
                                                                                                                                                                                    (HandlerRegistration*)
                                                                                                                                                                                        MaskExplicit(
                                                                                                                                                                                            t40);
                                                                                                                                                                                t44 =
                                                                                                                                                                                    &next;
                                                                                                                                                                                t48 =
                                                                                                                                                                                    t44->bits;
                                                                                                                                                                                t4c =
                                                                                                                                                                                    &current;
                                                                                                                                                                                t50 =
                                                                                                                                                                                    (HandlerRegistration*)(t4c->bits &
                                                                                                                                                                                                           ~1u);
                                                                                                                                                                                t54 =
                                                                                                                                                                                    &t50->next;
                                                                                                                                                                                if (t48 !=
                                                                                                                                                                                    (volatile unsigned int&)
                                                                                                                                                                                        t54->bits)
                                                                                                                                                                                {
                                                                                                                                                                                    retry =
                                                                                                                                                                                        true;
                                                                                                                                                                                    break;
                                                                                                                                                                                }
                                                                                                                                                                                t58 =
                                                                                                                                                                                    &current;
                                                                                                                                                                                *(__int64*)&found =
                                                                                                                                                                                    *(__int64*)&(
                                                                                                                                                                                         (HandlerRegistration*)(t58->bits &
                                                                                                                                                                                                                ~1u))
                                                                                                                                                                                         ->key;
                                                                                                                                                                                t5c =
                                                                                                                                                                                    &current;
                                                                                                                                                                                t64 =
                                                                                                                                                                                    t5c->bits &
                                                                                                                                                                                    ~1u;
                                                                                                                                                                                expected
                                                                                                                                                                                    .bits =
                                                                                                                                                                                    t64;
                                                                                                                                                                                t60 =
                                                                                                                                                                                    &expected;
                                                                                                                                                                                if (false)
                                                                                                                                                                                    t60->bits |=
                                                                                                                                                                                        1;
                                                                                                                                                                                else
                                                                                                                                                                                    t60->bits &=
                                                                                                                                                                                        ~1u;
                                                                                                                                                                                t68 =
                                                                                                                                                                                    link;
                                                                                                                                                                                t6c =
                                                                                                                                                                                    t68->bits;
                                                                                                                                                                                t70 =
                                                                                                                                                                                    &expected;
                                                                                                                                                                                if (t6c !=
                                                                                                                                                                                    (volatile unsigned int&)
                                                                                                                                                                                        t70->bits)
                                                                                                                                                                                {
                                                                                                                                                                                    retry =
                                                                                                                                                                                        true;
                                                                                                                                                                                    break;
                                                                                                                                                                                }
                                                                                                                                                                                t74 =
                                                                                                                                                                                    &next;
                                                                                                                                                                                if ((unsigned char)((t74->bits &
                                                                                                                                                                                                     1) !=
                                                                                                                                                                                                    0) ==
                                                                                                                                                                                    0)
                                                                                                                                                                                {
                                                                                                                                                                                    if (handler
                                                                                                                                                                                            ->Test(
                                                                                                                                                                                                found,
                                                                                                                                                                                                key))
                                                                                                                                                                                        return handler
                                                                                                                                                                                            ->Result(
                                                                                                                                                                                                found,
                                                                                                                                                                                                key);
                                                                                                                                                                                    t78 =
                                                                                                                                                                                        &current;
                                                                                                                                                                                    link =
                                                                                                                                                                                        &((HandlerRegistration*)(t78->bits &
                                                                                                                                                                                                                 ~1u))
                                                                                                                                                                                             ->next;
                                                                                                                                                                                    t7c =
                                                                                                                                                                                        &current;
                                                                                                                                                                                    *outPrevious =
                                                                                                                                                                                        (HandlerRegistration*)
                                                                                                                                                                                            MaskExplicit(
                                                                                                                                                                                                t7c);
                                                                                                                                                                                }
                                                                                                                                                                                else
                                                                                                                                                                                {
                                                                                                                                                                                    t80 =
                                                                                                                                                                                        &next;
                                                                                                                                                                                    t88 =
                                                                                                                                                                                        t80->bits &
                                                                                                                                                                                        ~1u;
                                                                                                                                                                                    replacement
                                                                                                                                                                                        .bits =
                                                                                                                                                                                        t88;
                                                                                                                                                                                    t84 =
                                                                                                                                                                                        &replacement;
                                                                                                                                                                                    if (false)
                                                                                                                                                                                        t84->bits |=
                                                                                                                                                                                            1;
                                                                                                                                                                                    else
                                                                                                                                                                                        t84->bits &=
                                                                                                                                                                                            ~1u;
                                                                                                                                                                                    t8c =
                                                                                                                                                                                        &expected;
                                                                                                                                                                                    t90 =
                                                                                                                                                                                        t8c->bits;
                                                                                                                                                                                    t94 =
                                                                                                                                                                                        &replacement;
                                                                                                                                                                                    t98 =
                                                                                                                                                                                        t94->bits;
                                                                                                                                                                                    ta0 =
                                                                                                                                                                                        link;
                                                                                                                                                                                    t99 =
                                                                                                                                                                                        InterlockedCompareExchange(
                                                                                                                                                                                            (volatile long*)
                                                                                                                                                                                                ta0,
                                                                                                                                                                                            t98,
                                                                                                                                                                                            t90) ==
                                                                                                                                                                                        t90;
                                                                                                                                                                                    if (t99)
                                                                                                                                                                                    {
                                                                                                                                                                                        ta4 =
                                                                                                                                                                                            &current;
                                                                                                                                                                                        FUN_00c41f40((
                                                                                                                                                                                            HandlerRegistration*)(ta4->bits &
                                                                                                                                                                                                                  ~1u));
                                                                                                                                                                                    }
                                                                                                                                                                                    else
                                                                                                                                                                                    {
                                                                                                                                                                                        retry =
                                                                                                                                                                                            true;
                                                                                                                                                                                        break;
                                                                                                                                                                                    }
                                                                                                                                                                                }
                                                                                                                                                                                current =
                                                                                                                                                                                    next;
                                                                                                                                                                                tb8 =
                                                                                                                                                                                    &next;
                                                                                                                                                                                *outCurrent =
                                                                                                                                                                                    (HandlerRegistration*)
                                                                                                                                                                                        MaskExplicit(
                                                                                                                                                                                            tb8);
                                                                                                                                                                            }
                                                                                                                                                                            if (retry)
                                                                                                                                                                                continue;
                                                                                                                                                                        }
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
}


// @fnv 0x00c42560
bool NodeQueue::FUN_00c42560(intptr_t arg, NodeKey* pKey, RefPtr* pOut)
{
    FUN_00c42560_pad pad;
    bool it;
    {
        RefObj* bit;
        int AA;
        int AC;
        int BL;
        NodeFlags* it9;
        Node* aIt;
        TaggedNodePtr* nx;
        RefPtr* itP;
        RefObj* itZ;
        TaggedNodePtr* nx5;
        TaggedNodePtr* unX;
        NodeFlags* enX;
        Node* itK;
        TaggedNodePtr* ret;
        TaggedNodePtr* val;
        RefObj* itH;
        NodeFlags* itX;
        Node* hit;
        TaggedNodePtr* itC;
        RefPtr* src1;
        RefObj* nX;
        TaggedNodePtr* aIT;
        TaggedNodePtr* aNx;
        NodeFlags* it7;
        Node* lim;
        TaggedNodePtr* tag;
        TaggedNodePtr* iT;
        int A9;
        it = false;
        while (1) {
            it = reinterpret_cast<::fnv_00c416a0::QueueSearch *>(this)->FUN_00c416a0(arg, *pKey);
            if (it) {
                iT = &m_kFirst;
                if ((iT->m_uiBits & ~1u) != 0) {
                    tag = &m_kFirst;
                    lim = (Node*)(tag->m_uiBits & ~1u);
                    it7 = &lim->m_flags;
                    if (it7->m_uiValue1 & 1 ? true : false)
                        continue;
                    aNx = &m_kFirst;
                    m_pHandler->Process(((Node*)(aNx->m_uiBits & ~1u))->m_key, pKey);
                    aIT = &m_kFirst;
                    src1 = &((Node*)(aIT->m_uiBits & ~1u))->m_pReferencedObject;
                    if (pOut->m_pObject != src1->m_pObject) {
                        if (pOut->m_pObject)
                            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(((ObjA*)pOut->m_pObject)));
                        pOut->m_pObject = src1->m_pObject;
                        if (pOut->m_pObject) {
                            nX = pOut->m_pObject;
                            FUN_00fdf1c0((void*)&nX->m_iObjectReferenceCount);
                        }
                    }
                    it = true;
                    itC = &m_kFirst;
                    hit = (Node*)(itC->m_uiBits & ~1u);
                    itX = &hit->m_flags;
                    if (itX->m_uiValue1 & 1 ? true : false) {
                        if (pOut->m_pObject != 0) {
                            if (pOut->m_pObject)
                                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(((ObjA*)pOut->m_pObject)));
                            pOut->m_pObject = 0;
                            if (pOut->m_pObject) {
                                itH = pOut->m_pObject;
                                FUN_00fdf1c0((void*)&itH->m_iObjectReferenceCount);
                            }
                        }
                        continue;
                    }
                    break;
                } else {
                    it = false;
                    break;
                }
            } else {
                val = &m_kSecond;
                if ((val->m_uiBits & ~1u) != 0) {
                    ret = &m_kSecond;
                    itK = (Node*)(ret->m_uiBits & ~1u);
                    enX = &itK->m_flags;
                    if (enX->m_uiValue1 & 1 ? true : false)
                        continue;
                    unX = &m_kSecond;
                    m_pHandler->Process(((Node*)(unX->m_uiBits & ~1u))->m_key, pKey);
                    nx5 = &m_kSecond;
                    itP = &((Node*)(nx5->m_uiBits & ~1u))->m_pReferencedObject;
                    if (pOut->m_pObject != itP->m_pObject) {
                        if (pOut->m_pObject)
                            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(((ObjA*)pOut->m_pObject)));
                        pOut->m_pObject = itP->m_pObject;
                        if (pOut->m_pObject) {
                            itZ = pOut->m_pObject;
                            FUN_00fdf1c0((void*)&itZ->m_iObjectReferenceCount);
                        }
                    }
                    it = true;
                    nx = &m_kSecond;
                    aIt = (Node*)(nx->m_uiBits & ~1u);
                    it9 = &aIt->m_flags;
                    if (it9->m_uiValue1 & 1 ? true : false) {
                        if (pOut->m_pObject != 0) {
                            if (pOut->m_pObject)
                                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(((ObjA*)pOut->m_pObject)));
                            pOut->m_pObject = 0;
                            if (pOut->m_pObject) {
                                bit = pOut->m_pObject;
                                FUN_00fdf1c0((void*)&bit->m_iObjectReferenceCount);
                            }
                        }
                        continue;
                    }
                    break;
                } else {
                    it = false;
                    break;
                }
            }
        }
        *m_p04 = 0;
        *m_p08 = 0;
        *m_p0C = 0;
    }
    return it;
}

// namespace fnv_00c416a0

struct RttiX
{
    const char* m_pcName;
    const RttiX* m_pBaseRTTI;
};

struct ObjX
{
    virtual void v00();
    virtual void v01();
    virtual const RttiX* GetRTTI() const;
};

inline bool IsDerivedType(const RttiX* pkRTTI, const RttiX* pkTarget)
{
    while (pkRTTI)
    {
        if (pkRTTI == pkTarget)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}

inline bool IsKindOfType(const RttiX& kRTTI, const ObjX* pkObj)
{
    if (!pkObj)
        return false;
    return IsDerivedType(pkObj->GetRTTI(), &kRTTI);
}

struct AVX : ObjX
{
    char pad[0xa8];
    unsigned short m_usFlags;
    unsigned short GetField(unsigned short usMask, unsigned short usPos) const
    {
        return (m_usFlags & usMask) >> usPos;
    }
};

struct FUN_00c5f680
{
    char pad[0xac];
    unsigned char m_ucFlags;
    FUN_00c5f680(AVX* pkObj, int i);
    ~FUN_00c5f680();
    void SetBit(bool bVal, unsigned char ucMask)
    {
        if (bVal)
            m_ucFlags |= ucMask;
        else
            m_ucFlags &= ~ucMask;
    }
};

struct FUN_00c436a0 : FUN_00c5f680
{
    FUN_00c436a0(AVX* pkObj);
};

// @fnv 0x00c436a0
FUN_00c436a0::FUN_00c436a0(AVX* pkObj) : FUN_00c5f680(pkObj, 0)
{
    *(int**)this = &DAT_010c195c;
    if (IsKindOfType((*reinterpret_cast<::RttiX *>(&::g_011f4aa0)), pkObj))
    {
        AVX* pkAV = pkObj;
        if (pkAV->GetField(7, 0) == 5)
            SetBit(true, 1);
    }
}

struct ElemX
{
    char ac[0x64];
};

struct FUN_00c4a070
{
    virtual void v00();
    virtual ElemX* Allocate(unsigned int uiElementCount);
    ElemX* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void DestructItems(ElemX* pkItems, unsigned int uiElementCount)
    {
        int aiA[9];
        for (unsigned int i = 0; i < uiElementCount; i++)
            pkItems[i].~ElemX();
    }
    void Shrink(unsigned int uiNewSize)
    {
        int aiB[8];
        reinterpret_cast<::CachedRef_b5611 *>(this)->UpdateCachedRef(uiNewSize, uiNewSize);
        m_uiCapacity = uiNewSize;
    }
    void SetSize(unsigned int uiNewSize, bool bFree);
};

// Copies scalar fields, m_kVec94, m_kRec30 and both arrays (resizing the destination arrays first) from this object into dst.
// @fnv 0x00c477f0
void Obj_c477f0::CopyTo(Obj_c477f0* apDest)
{
    unsigned int i;
    unsigned int j;
    apDest->unk28 = unk28;
    apDest->unk24 = unk24;
    apDest->unk2C = unk2C;
    apDest->m_kVec94 = m_kVec94;
    apDest->m_kRec30 = m_kRec30;
    apDest->b00 = b00;
    {
        unsigned int uiSize = m_kArr14.m_uiSize;
        reinterpret_cast<::FUN_00c4a1e0 *>(&(apDest->m_kArr14))->SetSize(uiSize, true);
    }
    {
    unsigned int ItemUpdateArray;
    for (i = 0; i < (ItemUpdateArray = m_kArr14.m_uiSize); i++) {
        {
            Elem0C* pA = &m_kArr14.m_pData[i];
            apDest->m_kArr14.m_pData[i].a = pA->a;
        }
        {
            Elem0C* pB = &m_kArr14.m_pData[i];
            apDest->m_kArr14.m_pData[i].b = pB->b;
        }
        {
            Elem0C* pC = &m_kArr14.m_pData[i];
            apDest->m_kArr14.m_pData[i].c = pC->c;
        }
    }
    }
    {
        unsigned int uiRecCount = m_kArr04.m_uiSize;
        reinterpret_cast<::FUN_00c4a070 *>(&(apDest->m_kArr04))->SetSize(uiRecCount, true);
    }
    {
    unsigned int uiCount2;
    for (j = 0; j < (uiCount2 = m_kArr04.m_uiSize); j++) {
        {
            Rec64* pR = &m_kArr04.m_pData[j];
            apDest->m_kArr04.m_pData[j] = *pR;
        }
    }
    }
}

// @fnv 0x00c47b50
void FUN_00c47b50Class::UpdateRecords(FUN_00c47b50Arg* arg, int unused)
{
    long itemsCapacity5;
    int itemsCapacityAgain5;
    int recordsCapacity;
    long recordsCapacityAgain;
    FUN_00c47b50Vec3 v1;
    FUN_00c47b50Transform matrix8;
    FUN_00c47b50Vec3 v;
    FUN_00c47b50Vec3 aV2;
    float fStack_8;
    int iStack_5c7;
    FUN_00c47b50Vec3* p5;

    itemsCapacity5 = second.m_iCapacity;
    if (count + 2 >= itemsCapacity5) {
        itemsCapacityAgain5 = second.m_iCapacity;
        reinterpret_cast<::FUN_00c4a1e0 *>(&(second))->SetSize(itemsCapacityAgain5 + 10, true);
    }
    recordsCapacity = first.m_iCapacity;
    if (1 + index >= recordsCapacity) {
        recordsCapacityAgain = first.m_iCapacity;
        reinterpret_cast<::FUN_00c4a070 *>(&(first))->SetSize(recordsCapacityAgain + 4, true);
    }
    iStack_5c7 = 4;
    p5 = &v1;
    while (--iStack_5c7 >= 0) {
        p5++;
    }
    reinterpret_cast<::Builder *>((arg))->FUN_00c35c10((::Point *)(::FUN_00c47b50Vec3 *)(&v1));
    reinterpret_cast<::FUN_00a699d0_Class *>(&(v))->FUN_00a699d0((const ::NiPoint3 *)(::FUN_00c47b50Vec3 *)(&v1), (const ::NiPoint3 *)(::FUN_00c47b50Vec3 *)(&aV2), (const ::NiPoint3 *)(::FUN_00c47b50Transform *)(&matrix8));
    second.m_pData[count].value = 7;
    count += 1;
    second.m_pData[count].value = index;
    count++;
    arg->FUN_00c33870(position, &first.m_pData[index]);
    {
        float records;
        records = reinterpret_cast<::FUN_004b6190_shell *>(&(v))->DotProduct(&position) - fStack_8;
    if ((float)std::fabs((double)records) > 5.0) {
        FUN_00c47b50Record* r1 = &first.m_pData[index];
        r1->m60 = 0x3f;
    } else {
        FUN_00c47b50Record* r2 = &first.m_pData[index];
        r2->m60 = 0;
    }
    }
    index++;
}

// Copies entry data from src into this owner, compacting the entry array and updating the record table.
// @fnv 0x00c48db0
void C48Owner::FUN_00c48db0(C48Owner* src, C48Obj* obj)
{
    int kRemovedZ = 0;
    int TKz3 = 0;
    int BN = src->m_28;
    int PIn;
    bool ok;
    C48Entry* nXT;
    C48Rec* rec;
    C48Entry* FCur;
    C48Entry* unXT;
    C48Rec* rec2;
    C48Entry* aNxT;
    C48Entry* nxT;
    C48Rec* aDst4;
    C48Entry* sCur;

    reinterpret_cast<::FUN_00c4a1e0 *>(&(m_14))->SetSize(BN, true);
    reinterpret_cast<::FUN_00c4a070 *>(&(m_04))->SetSize(src->m_24, true);

    for (PIn = 0; PIn < BN; PIn++) {
        ok = true;
        switch (src->m_14.m_18[PIn].type) {
        case 7:
        case 8:
            {
                nXT = &src->m_14.m_18[PIn + 1];
                rec = &src->m_04.m_08[nXT->type];
                ok = ((bool)(reinterpret_cast<::fnv_00c34350::RectangleClip *>((obj))->FUN_00c34350((::fnv_00c34350::ClipVolume *)(rec))));
                FCur = &src->m_14.m_18[PIn];
                m_14.m_18[PIn - kRemovedZ].type = FCur->type;
                m_28++;
                m_14.m_18[PIn - kRemovedZ + 1].type = m_24;
                m_28++;
                unXT = &src->m_14.m_18[PIn + 1];
                rec2 = &src->m_04.m_08[unXT->type];
                aNxT = &src->m_14.m_18[PIn + 1];
                m_04.m_08[aNxT->type - TKz3] = *rec2;
                m_24++;
                if (ok && ((int)(reinterpret_cast<::PaletteFieldFlags *>((obj))->GetPackedZeroFlags())) == 0xf) {
                    nxT = &src->m_14.m_18[PIn + 1];
                    aDst4 = &m_04.m_08[nxT->type - TKz3];
                    aDst4->m_60 = 0;
                }
                PIn++;
            }
            break;
        default:
            sCur = &src->m_14.m_18[PIn];
            m_14.m_18[PIn - kRemovedZ].type = sCur->type;
            m_28++;
            break;
        }
    }
    m_28 = BN - kRemovedZ;
    reinterpret_cast<::Target *>(this)->CompactEntries();
}




// @fnv 0x00c48ca0
void TokStack_c48ca0::FUN_00c48ca0()
{
    bool bPush = true;
    if (m_kArray.m_pData[TopIdx()].iType == 4)
    {
        int iLevel = 1;
        int i = 1;
        while (iLevel > 0 && i < m_iArrayLength)
        {
            switch (m_kArray.m_pData[i].iType)
            {
            case 4:
            case 5:
                iLevel++;
                break;
            case 6:
                iLevel--;
                break;
            }
            i++;
        }
        if (i == m_iArrayLength && iLevel == 0)
            bPush = false;
    }
    if (bPush)
    {
        int iCap = m_kArray.m_iCapacity;
        if (m_iArrayLength + 1 >= iCap)
        {
            int iOld = m_kArray.m_iCapacity;
            reinterpret_cast<::FUN_00c4a1e0 *>(&(m_kArray))->SetSize(iOld + 10, true);
        }
        reinterpret_cast<::FUN_00c48a10_t *>(this)->ShiftElements(1, false);
        m_kArray.m_pData[TopIdx()].iType = 4;
    }
    else
    {
        m_iArrayLength--;
    }
}

// @fnv 0x00c4a1e0
void FUN_00c4a1e0::SetSize(unsigned int uiNewSize, bool bFree)
{
    if (uiNewSize == 0)
    {
        reinterpret_cast<::FUN_00c4a9c0_class *>(this)->ReleaseBuffer(bFree);
        return;
    }
    if (uiNewSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pBuffer = Allocate(uiNewSize);
            m_uiCapacity = uiNewSize;
        }
        else
        {
            reinterpret_cast<::FUN_006dc6e0_Class *>(this)->FUN_00c4a4e0(uiNewSize, m_uiSize);
            m_uiCapacity = uiNewSize;
        }
        ConstructItems(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
    else if (uiNewSize < m_uiSize)
    {
        DestructItems(m_pBuffer + uiNewSize, m_uiSize - uiNewSize);
        m_uiSize = uiNewSize;
        if (bFree && uiNewSize <= m_uiCapacity >> 2)
        {
            reinterpret_cast<::FUN_006dc6e0_Class *>(this)->FUN_00c4a4e0(uiNewSize, uiNewSize);
            m_uiCapacity = uiNewSize;
        }
    }
    else
    {
        ConstructItems2(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
}

extern char DAT_010c1eb4;

struct DerQ : FUN_00c450d0
{
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0,
        unkA4, unkA8, unkAC;
    DerQ()
    {
        vtbl = (intptr_t)&DAT_010c1eb4;
    }
};

// @fnv 0x00c4ac00
DerQ* FUN_00c4ac00()
{
    return new DerQ;
}

struct S_00c4aca0_Base
{
    S_00c4aca0_Base();
    virtual void vf0();
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
};

struct S_00c4aca0_Obj : S_00c4aca0_Base
{
    S_00c4aca0_Obj()
    {}
    virtual void vf0();
};

struct S_00c4aca0_Self
{
    S_00c4aca0_Obj* FUN_00c4aca0(int arg);
};

// @fnv 0x00c4aca0
S_00c4aca0_Obj* S_00c4aca0_Self::FUN_00c4aca0(int arg)
{
    S_00c4aca0_Obj* p = new S_00c4aca0_Obj;
    reinterpret_cast<::FUN_00c4ad40_class *>((this))->FUN_00c4ad40((intptr_t)(p), arg);
    return p;
}

struct ItemW
{
    int a, b, c;
};

struct ArrW
{
    virtual void v00();
    virtual ItemW* Allocate(unsigned int uiElementCount);
    virtual void Free(ItemW* pkItems);
    ItemW* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void FUN_006dc6e0(ItemW* pkDst, ItemW* pkSrc, unsigned int uiElementCount)
    {
        if (pkDst < pkSrc)
        {
            for (unsigned int i = 0; i < uiElementCount; i++)
                memcpy(&pkDst[i], &pkSrc[i], sizeof(ItemW));
        }
        else
        {
            for (unsigned int i = uiElementCount; i > 0; i--)
                memcpy(&pkDst[i - 1], &pkSrc[i - 1], sizeof(ItemW));
        }
    }
    void DestructItems(ItemW* pkItems, unsigned int uiElementCount)
    {
        for (unsigned int i = 0; i < uiElementCount; i++)
            pkItems[i].~ItemW();
    }
    bool ShouldShrink()
    {
        if (m_uiCapacity > 0x400)
        {
            if (m_uiSize <= m_uiCapacity - 0x800)
                return true;
        }
        else if (m_uiSize <= m_uiCapacity >> 2)
            return true;
        return false;
    }
    void FUN_00c4e760(unsigned int uiIndex, bool bShrink);
};

// @fnv 0x00c4e760
void ArrW::FUN_00c4e760(unsigned int uiIndex, bool bShrink)
{
    if (bShrink && ShouldShrink())
    {
        unsigned int uiNew = m_uiCapacity > 0x800 ? m_uiCapacity - 0x400 : m_uiCapacity >> 1;
        ItemW* pkNew = Allocate(uiNew);
        reinterpret_cast<::FUN_006dc6e0_Class *>(this)->FUN_006dc6e0((char *)(pkNew), (char *)(m_pBuffer), uiIndex);
        DestructItems(m_pBuffer + uiIndex, 1);
        reinterpret_cast<::FUN_006dc6e0_Class *>(this)->FUN_006dc6e0((char *)(::ItemW *)(pkNew + uiIndex), (char *)(::ItemW *)(m_pBuffer + uiIndex + 1), m_uiSize - 1);
        Free(m_pBuffer);
        m_pBuffer = 0;
        m_pBuffer = pkNew;
        m_uiCapacity = uiNew;
    }
    else
    {
        DestructItems(m_pBuffer + uiIndex, 1);
        reinterpret_cast<::FUN_006dc6e0_Class *>(this)->FUN_006dc6e0((char *)(::ItemW *)(m_pBuffer + uiIndex), (char *)(::ItemW *)(m_pBuffer + uiIndex + 1), m_uiSize - uiIndex - 1);
    }
    m_uiSize--;
}

// strstr

struct BoneRootRTTI
{
    const char* m_pcName;
    const BoneRootRTTI* m_pBaseRTTI;
};

struct FixedQ
{
    char* m;
    operator const char*() const
    {
        return m;
    }
};

class BoneRootExtraData
{
  public:
    virtual void v00();
    virtual void v01();
    virtual const BoneRootRTTI* GetRTTI() const;
    int unk04;
    int unk08;
    FixedQ m_kString;  // +0x0c

    bool IsKindOfType(const BoneRootRTTI* pkTarget) const
    {
        const BoneRootRTTI* pkRTTI = GetRTTI();
        while (pkRTTI)
        {
            if (pkRTTI == pkTarget)
                return true;
            pkRTTI = pkRTTI->m_pBaseRTTI;
        }
        return false;
    }
    const char* GetValue() const
    {
        return m_kString;
    }
};

class BoneRootNode;

class BoneRootChild
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual BoneRootNode* IsSceneNode();  // +0x0c
};

struct PtrQ
{
    BoneRootChild* m;
    operator BoneRootChild*() const
    {
        return m;
    }
};

class BoneRootChildArray
{
  public:
    void* m_pvVtbl;
    BoneRootChild** m_ppkBase;  // +0xa0
    unsigned short m_usMaxSize;
    unsigned short m_usSize;  // +0xa6
    BoneRootChild*& Ref(unsigned int uiIndex)
    {
        return m_ppkBase[uiIndex];
    }
    const PtrQ& GetAt(unsigned int uiIndex)
    {
        return ((PtrQ*)m_ppkBase)[uiIndex];
    }
};

class BoneRootNode
{
  public:
    int unk00[4];
    BoneRootExtraData** m_ppExtraData;  // +0x10
    unsigned short m_usExtraCount;      // +0x14
    unsigned short unk16;
    int unk18[33];
    BoneRootChildArray m_kChildList;  // +0x9c

    BoneRootChild* GetChild(unsigned int ui)
    {
        int aiD[3];
        return m_kChildList.GetAt(ui);
    }
    unsigned short GetExtraDataSize() const
    {
        return m_usExtraCount;
    }
};

class BoneRootSet
{
  public:
};

// @fnv 0x00c52c30
void __cdecl FUN_00c52c30(BoneRootNode* pkNode, BoneRootSet* pkSet)
{
    unsigned int i;
    BoneRootExtraData* pkExtra;
    for (i = 0; i < pkNode->GetExtraDataSize(); i++)
    {
        BoneRootExtraData* pkString;
        pkExtra = pkNode->m_ppExtraData[(unsigned short)i];
        if (!pkExtra)
            pkString = 0;
        else
            pkString = pkExtra->IsKindOfType(&(*reinterpret_cast<::BoneRootRTTI *>(&::g_011f4a38))) ? pkExtra : 0;
        if (pkString)
        {
            const char* pcValue = pkString->GetValue();
            if (pcValue && std::strstr((char *)(pcValue), "BSBoneLOD#BoneRoot#"))
            {
                reinterpret_cast<::NiStreamLinkIDSetShell *>((pkSet))->AppendLinkID((unsigned int *)&(pkNode));
                return;
            }
        }
    }
    for (i = 0; i < pkNode->m_kChildList.m_usSize; i++)
    {
        BoneRootChild* pkChild = pkNode->GetChild(i);
        if (pkChild && pkChild->IsSceneNode())
            FUN_00c52c30((BoneRootNode*)pkChild, pkSet);
    }
}

struct NiFixedString
{
    int m_chars;
};

extern int DAT_010c2b64;

struct NiExtraDataStandIn
{
    void* m_vtbl;
    NiFixedString m_name;
    NiExtraDataStandIn(const NiFixedString& name);
};

struct C55010Obj : NiExtraDataStandIn
{
    int m_08;
    NiPoint3 m_0c;
    NiPoint3 m_18;
    C55010Obj(const NiFixedString& name) : NiExtraDataStandIn(name)
    {
        m_vtbl = &DAT_010c2b64;
        m_0c = ::NiPoint3::ZERO;
        m_18 = ::NiPoint3::ZERO;
    }
};

// @fnv 0x00c55010
C55010Obj* FUN_00c55010()
{
    C55010Obj* p = new C55010Obj(*(*reinterpret_cast<::NiFixedString * *>(&::g_pkString_c55)));
    ::AssignFixedString((char *)(((NiAVObject*)p)), (intptr_t)&(*(const NiFixedString*)&(*reinterpret_cast<int *>(&::DAT_011f49e0))), {});
    return p;
}

namespace fnv_00c5f390 {
struct T4
{
    int v;
};
inline void Construct(T4* p, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        new (&p[i]) T4;
}
inline void DeadB()
{
    int d0;
    int d1;
    int d2;
}
inline void Destroy(T4* p, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        p[i].~T4();
    DeadB();
}
inline void DeadA()
{
    int a0;
    int a1;
    int a2;
    int a3;
}
struct ArrX
{
    virtual void V0();
    virtual T4* Alloc(unsigned int n);
    T4* m4;
    unsigned int m8;
    unsigned int mc;
    void FUN_00c5f390(unsigned int n, bool b);
};
// @fnv 0x00c5f390
void ArrX::FUN_00c5f390(unsigned int n, bool b)
{
    DeadA();
    if (n == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(b);
    }
    else if (n > mc)
    {
        if (mc == 0)
        {
            m4 = Alloc(n);
            mc = n;
        }
        else
        {
            reinterpret_cast<::FUN_0042fc00_shell *>(this)->FUN_0042fc00((void *)(n), m8);
            mc = n;
        }
        Construct(m4 + m8, n - m8);
        m8 = n;
    }
    else if (n < m8)
    {
        Destroy(m4 + n, m8 - n);
        m8 = n;
        if (b && n <= mc >> 2)
        {
            reinterpret_cast<::FUN_0042fc00_shell *>(this)->FUN_0042fc00((void *)(n), n);
            mc = n;
        }
    }
    else
    {
        Construct(m4 + m8, n - m8);
        m8 = n;
    }
}
}

// Calls FUN_00c5f390 on other with count and 1, then copies count elements from data into other->data.
// @fnv 0x00c5f500
void FUN_00c5f500_class::FUN_00c5f500(FUN_00c5f500_class* other)
{
    reinterpret_cast<::fnv_00c5f390::ArrX *>((((FUN_00c5f390_class*)other)))->FUN_00c5f390(count, 1);
    for (unsigned int i = 0; i < count; ++i)
        other->data[i] = data[i];
}

// @fnv 0x00c5ef50
void FUN_00c5ef50_cls::FUN_00c5ef50(int pTarget) {
    int n;
    reinterpret_cast<::NiExtraData *>((((FUN_00a7b4a0_cls*)this)))->LoadBinary((*(::NiStream *)(pTarget)));
    ::FUN_00a26df0((::MyStream *)(pTarget), &n);
    for (int i = 0; i < n; ++i) {
        ((FUN_00a645b0_cls*)pTarget)->FUN_00a645b0();
    }
    reinterpret_cast<::fnv_00c5f390::ArrX *>((((FUN_00c5f390_class*)((char*)this + 0xc))))->FUN_00c5f390(n, 1);
}

// namespace fnv_00c5f390


struct MemMgr
{
    void* Allocate(unsigned int size);
};

extern MemMgr g_memMgr;


struct MapThreadData
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
    int heapContext;
};

__declspec(thread) MapThreadData mapTls;

inline int GetHeapContext()
{
    int value = (*reinterpret_cast<::MapThreadData *>(&::g_tlsBlock)).heapContext;
    return value;
}

inline void SetHeapContext(int value)
{
    (*reinterpret_cast<::MapThreadData *>(&::g_tlsBlock)).heapContext = value;
}

struct HeapCtxGuard
{
    int saved;
    __forceinline HeapCtxGuard(int ctx)
    {
        saved = GetHeapContext();
        SetHeapContext(ctx);
    }
    __forceinline ~HeapCtxGuard()
    {
        int v = saved;
        SetHeapContext(v);
    }
};

long __cdecl FinishMapRef(void*);

struct MapRefObj
{
    virtual ~MapRefObj();
    int unk04;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        long refs = FinishMapRef(&m_uiRefCount);
        if (refs == 0)
            delete this;
    }
};

struct MapRefPtr
{
    MapRefObj* m_pObject;
    ~MapRefPtr()
    {
        if (m_pObject)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_pObject));
    }
    MapRefPtr& operator=(MapRefObj* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_pObject));
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct WeightedMapNode;

struct TaggedMapLink
{
    unsigned int value;
    WeightedMapNode* Get()
    {
        TaggedMapLink* link = this;
        return (WeightedMapNode*)(link->value & ~1);
    }
    void Clear()
    {
        value = 0;
    }
    void Detach()
    {
        TaggedMapLink* link = this;
        link->value = 0;
    }
};

struct WeightedMapNode
{
    int unk00;
    int unk04;
    MapRefPtr m_spObj;
    TaggedMapLink m_next;
};

unsigned int __cdecl GetMapThreadId();

int __cdecl CompareMapLock(volatile long*, long, long);

void __cdecl YieldMapThread(unsigned long);

void __cdecl MapLockBarrier();

struct SpinLock
{
    int owner;
    int count;
    void Lock(const char* name)
    {
        unsigned int threadId = GetMapThreadId();
        if (owner == threadId)
        {
            count = count + 1;
        }
        else
        {
            unsigned int spins = 0;
            while (CompareMapLock((volatile long*)&owner, 0, threadId))
            {
                ++spins;
                if (spins > 10000)
                    YieldMapThread(1);
                else
                    YieldMapThread(0);
            }
            MapLockBarrier();
            count = 1;
        }
    }
    void Unlock()
    {
        count = count - 1;
        if (count == 0)
            owner = 0;
    }
};

struct Pool
{
    int unk00, unk04, unk08, unk0C;
    int GetSize()
    {
        return unk00;
    }
    Pool(int a);
    ~Pool();
};

struct NodeMap
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
    virtual void ReleaseKey(int, int);
    int unk04;
    unsigned int m_uiHashSize;
    TaggedMapLink* m_ppBuckets;
    int unk10;
    Pool* m_pLinkPool;
    int m_uiCount;
    int unk1C;
    SpinLock m_lock;
    void FreeNode(WeightedMapNode* node)
    {
        ReleaseKey(node->unk00, node->unk04);
        delete node;
    }
    void FUN_00c40b70(bool keepPool);
};

// @fnv 0x00c40b70
void NodeMap::FUN_00c40b70(bool keepPool)
{
    HeapCtxGuard heapContext(6);
    if (m_pLinkPool == 0)
        return;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_lock))->FUN_0040fbf0((char *)(0));
    int poolSize = m_pLinkPool->GetSize();
    delete m_pLinkPool;
    m_pLinkPool = 0;
    m_uiCount = 0;
    for (unsigned int i = 0; i < m_uiHashSize; i++)
    {
        WeightedMapNode* node = m_ppBuckets[i].Get();
        m_ppBuckets[i].Clear();
        while (node)
        {
            WeightedMapNode* next = node->m_next.Get();
            node->m_next.Detach();
            node->m_spObj = 0;
            FreeNode(node);
            node = next;
        }
    }
    if (!keepPool)
    {
        m_pLinkPool = new Pool(poolSize);
    }
    m_lock.Unlock();
}

typedef unsigned int U32;

int __cdecl FUN_004019a0(void*);

struct C41RefObject
{
    virtual ~C41RefObject();
    void Release();
    U32 m_04, m_08;
    inline void FUN_0044dd60()
    {
        int count = ((int)(::WaitForSingleObjectEx((long *)(void *)(&m_08))));
        if (!count)
        {
            delete this;
        }
    }
};

struct C41Object : C41RefObject
{
};

extern "C" void(* FUN_00fdf1c0)(void*);

extern "C" U32(* FUN_00fdf1bc)(void*, U32, U32);

struct C41Guard
{
    C41Object* m_00;
    C41Guard(C41Object* const& p) : m_00(p)
    {
        if (m_00)
        {
            C41Object* object = m_00;
            FUN_00fdf1c0(&object->m_08);
        }
    }
    inline ~C41Guard()
    {
        if (m_00)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_00));
    }
};

struct C41Node;

struct C41Link
{
    U32 m_00;
    C41Link()
    {}
    C41Link(C41Node* p) : m_00((uintptr_t)p)
    {}
    inline void Initialize(C41Node* p, bool b)
    {
        m_00 = (uintptr_t)p;
        Flag(b);
    }
    inline C41Node* Get() volatile
    {
        return (C41Node*)(m_00 & ~1U);
    }
    inline U32 Raw() volatile
    {
        return m_00;
    }
    inline U32 Flag()
    {
        C41Link* link = this;
        return link->m_00 & 1U;
    }
    inline void Flag(bool b) volatile
    {
        if (b)
            m_00 |= 1;
        else
            m_00 &= ~1U;
    }
    inline bool Compare(U32 desired, U32 expected) volatile
    {
        bool success = FUN_00fdf1bc((void*)this, desired, expected) == expected;
        return success;
    }
    inline bool Equal(const C41Link& r) const
    {
        return m_00 == r.m_00;
    }
};

struct C41ObjectSlot
{
    C41Object* value;
    inline void operator=(C41Object* p)
    {
        if (value != p)
        {
            if (value)
                value->Release();
            value = p;
            if (value)
            {
                C41Object* object = value;
                FUN_00fdf1c0(&object->m_08);
            }
        }
    }
};

struct C41Node
{
    U32 m_00, m_04;
    C41ObjectSlot m_08;
    C41Link m_0c;
};

struct C41Table
{
    U32 m_00, m_04, m_08;
    C41Link* m_0c;
    U32 m_10;
};

struct C41DestSingle
{
    C41Node* ptr;
};

struct C41Owner
{
    C41Table* m_00;
    C41DestSingle* m_04;
    C41DestSingle* m_08;
    C41DestSingle* m_0c;
    C41Link* m_10;
    C41Link m_14, m_18;
    C41Node* retired;
    U32 retiredCount;
    void FUN_00c42960();
    inline void FUN_00c41f40(C41Node* node)
    {
        node->m_08 = 0;
        C41Node* head = retired;
        node->m_08.value = (C41Object*)head;
        retired = node;
        ++retiredCount;
        U32 threshold = m_00->m_10;
        if (retiredCount == threshold)
            FUN_00c42960();
    }
    bool FUN_00c41ac0(int, C41Object**);
};

// @fnv 0x00c403d0
bool Lock5b::TryAcquireAndFire(unsigned int a, unsigned int b, unsigned int c)
{
    bool result2 = false;
    Tag5b t1;
    Tag5b t2;
    Tag5b t7;
    {
        Scratch5b scratch;
    }
    while (true)
    {
        unsigned int* aP_m10;
        bool _ok5;
        unsigned int aNVv;
        Tag5b* _pt1;
        unsigned int AEQ;
        Tag5b* pt3_2;
        unsigned int node;
        Tag5b* pt3b;
        unsigned int* p14b3;
        bool aOk5;
        unsigned int nodeB5;
        unsigned int* p14bLen;
        unsigned int inv5;
        Tag5b* pt2_2;
        unsigned int _oldJk;
        Tag5b* pt1bPtr;
        unsigned int _v18;
        unsigned int* _p18a;
        unsigned int v18a;
        unsigned int* p18aP;

        if (!reinterpret_cast<::fnv_00c416a0::QueueSearch *>(this)->FUN_00c416a0(a, (::NodeKey)(b)))
        {
            result2 = false;
            break;
        }

        p18aP = &m18;
        v18a = *p18aP & ~1u;
        t1.bits = v18a;
        reinterpret_cast<::FUN_0044e010_class *>(&(t1))->FUN_0044e010(0);

        _p18a = &m18;
        _v18 = *_p18a & ~1u;
        t2.bits = _v18;
        reinterpret_cast<::FUN_0044e010_class *>(&(t2))->FUN_0044e010(1);

        pt1bPtr = &t1;
        _oldJk = pt1bPtr->bits;
        pt2_2 = &t2;
        inv5 = pt2_2->bits;
        p14bLen = &m14;
        nodeB5 = *p14bLen & ~1u;
        aOk5 = InterlockedCompareExchange((long volatile*)(nodeB5 + 0xc), (long)inv5, (long)_oldJk) == (long)_oldJk;
        if (!aOk5)
            continue;

        p14b3 = &m14;
        node = *p14b3 & ~1u;
        t7.bits = node;
        pt3b = &t7;
        if (0)
            pt3b->bits |= 1u;
        else
            pt3b->bits &= ~1u;

        pt3_2 = &t7;
        AEQ = pt3_2->bits;
        _pt1 = &t1;
        aNVv = _pt1->bits;
        aP_m10 = m10;
        _ok5 = InterlockedCompareExchange((long volatile*)aP_m10, (long)aNVv, (long)AEQ) == (long)AEQ;
        if (_ok5)
        {
            Pad16_5b aOld2;
            unsigned int* p14c = &m14;
            reinterpret_cast<::C41Owner *>(this)->FUN_00c41f40((::C41Node *)(*p14c & ~1u));
        }
        else
        {
            reinterpret_cast<::fnv_00c416a0::QueueSearch *>(this)->FUN_00c416a0(a, (::NodeKey)(b));
        }

        m00->Fire();
        result2 = true;
        break;
    }

    *m04 = 0;
    *m08 = 0;
    *m0c = 0;
    return result2;
}

// @fnv 0x00c41ac0
bool C41Owner::FUN_00c41ac0(int index, C41Object** wanted)
{
    C41Link* bucket = &m_00->m_0c[index];
    bool retry;
    while (true)
    {
        retry = false;
        m_10 = bucket;
        m_14 = *m_10;
        m_08->ptr = m_14.Get();
        C41Link initial(m_14.Get());
        reinterpret_cast<::FUN_0044e010_class *>(&(initial))->FUN_0044e010(false);
        if (m_10->Raw() != initial.Raw())
            continue;
        while (true)
        {
            if (!m_14.Get())
                return false;
            m_18 = m_14.Get()->m_0c;
            m_04->ptr = m_18.Get();
            if (m_18.Raw() != m_14.Get()->m_0c.Raw())
            {
                retry = true;
                break;
            }
            C41Guard object(m_14.Get()->m_08.value);
            C41Link current(m_14.Get());
            reinterpret_cast<::FUN_0044e010_class *>(&(current))->FUN_0044e010(false);
            if (m_10->Raw() != current.Raw())
            {
                retry = true;
                goto retryIteration;
            }
            if (!(bool)(int)m_18.Flag())
            {
                if ((bool)(int)(object.m_00 == *wanted))
                    return true;
                m_10 = &m_14.Get()->m_0c;
                m_0c->ptr = m_14.Get();
            }
            else
            {
                C41Link next;
                next.Initialize(m_18.Get(), false);
                if (m_10->Compare(next.Raw(), current.Raw()))
                    FUN_00c41f40(m_14.Get());
                else
                {
                    retry = true;
                    break;
                }
            }
            m_14 = m_18;
            m_08->ptr = m_18.Get();
        }
    retryIteration:
        if (retry)
            continue;
    }
}

struct Pair41fe0
{
    unsigned int m_00;
    unsigned int m_04;
};

struct Ref41fe0
{
    ObjA* m_pObject;
    ~Ref41fe0()
    {
        if (m_pObject)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_pObject));
    }
};

struct DtorScratch41fe0
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    DtorScratch41fe0()
    {}
};

struct Arg41fe0
{
    Pair41fe0 pair;
    Ref41fe0 m_08;
    ~Arg41fe0()
    {
        DtorScratch41fe0 scratch;
    }
};

class C41FE0_Owner
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
    virtual void v10(Pair41fe0 pair);

    void FUN_00c41fe0(Arg41fe0* p);
};

// @fnv 0x00c41fe0
void C41FE0_Owner::FUN_00c41fe0(Arg41fe0* p)
{
    v10(p->pair);
    delete p;
}

extern char DAT_011f6238;

inline int S00c420d0_One()
{
    return 1;
}

struct S00c420d0_Item
{
    void FUN_00c42b40();
};

struct S00c420d0_Pair
{
    unsigned int unk00;
    S00c420d0_Item* m_pObject;
};

struct S00c420d0_cls
{
    unsigned int m_uiItemCount;
    unsigned int m_unk04;
    S00c420d0_Pair* m_pairs;
    void FUN_00c420d0();
};

// @fnv 0x00c420d0
void S00c420d0_cls::FUN_00c420d0()
{
    unsigned int i = 0;
    {
        S00c420d0_Item* item;
        S00c420d0_Item* p;
        {
            S00c420d0_Pair* pairs;
            {
                unsigned int count;
                S00c420d0_Item* r;
                for (; i < (count = this->m_uiItemCount); ++i)
                {
                    item = this->m_pairs[i].m_pObject;
                    p = item;
                    (p != 0) ? (r = p, reinterpret_cast<FUN_00c42b40_cls*>(r)->FUN_00c42b40(),
                                (S00c420d0_One() & 1) ? reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<SpawnHeap_cls*>(&DAT_011f6238)))->FUN_00aa4060(r)
                                                      : (void)0,
                                r)
                             : 0;
                }
                pairs = this->m_pairs;
                reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<SpawnHeap_cls*>(&DAT_011f6238)))->FUN_00aa4060(pairs);
            }
        }
    }
    {
        unsigned int tls = this->m_unk04;
        DAT_0fdf050((void*)tls);
    }
}

namespace fnv_00c42180 {
struct TlsMem
{
    char pad[0x2b4];
    int iCtx;
};
struct MemMgrQ
{
    void* FUN_00aa3e40(unsigned int size);
};
extern "C" char DAT_011f6238;
typedef unsigned long(* TidFnQ)();
extern "C" TidFnQ DAT_00fdf048;
inline int GetMemCtx()
{
    return (*reinterpret_cast<::fnv_00c42180::TlsMem *>(&::g_tlsBlock)).iCtx;
}
inline void SetMemCtx(int c)
{
    (*reinterpret_cast<::fnv_00c42180::TlsMem *>(&::g_tlsBlock)).iCtx = c;
}
struct AutoMemContext
{
    int iSaved;
    AutoMemContext(int c)
    {
        iSaved = GetMemCtx();
        (*reinterpret_cast<::fnv_00c42180::TlsMem *>(&::g_tlsBlock)).iCtx = c;
    }
    ~AutoMemContext()
    {
        SetMemCtx(iSaved);
    }
};
struct BucketQ
{
    void* p0;
    void* p4;
    BucketQ()
    {
        BucketQ* pThis = this;
        pThis->p0 = 0;
        pThis->p4 = 0;
    }
};
struct FUN_00c42180
{
    unsigned int m_uiItemCount;
    unsigned long m_tid;
    BucketQ* m_pBuckets;
    int m_C;
    FUN_00c42180(unsigned int n);
};
// @fnv 0x00c42180
FUN_00c42180::FUN_00c42180(unsigned int n)
{
    AutoMemContext ctx(6);
    m_C = 0;
    m_uiItemCount = n;
    m_pBuckets = new BucketQ[m_uiItemCount];
    m_tid = DAT_00fdf048();
}
}

// namespace fnv_00c42180


struct RefObject
{
    virtual ~RefObject();
    int unk04;
    long references;
    inline void FUN_0044dd60()
    {
        long count = ((int)(::WaitForSingleObjectEx((long *)(void *)(&references))));
        if (count == 0)
            delete this;
    }
    __forceinline void AddRef()
    {
        InterlockedIncrement(&references);
    }
};

struct ObjectRef
{
    RefObject* ptr;
    __forceinline ObjectRef& operator=(const ObjectRef& rhs)
    {
        if (ptr != rhs.ptr)
        {
            if (ptr)
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(ptr));
            ptr = rhs.ptr;
            if (ptr)
                ptr->AddRef();
        }
        return *this;
    }
};

struct MapEntry;

struct TaggedPointer
{
    unsigned int raw;
    __forceinline MapEntry* Get() const
    {
        return reinterpret_cast<MapEntry*>(raw & ~1u);
    }
    __forceinline unsigned int Bits() const
    {
        return raw;
    }
    __forceinline bool NextMarked() const;
};

struct MapEntry
{
    unsigned __int64 key;
    ObjectRef value;
    TaggedPointer next;
};

__forceinline bool TaggedPointer::NextMarked() const
{
    const TaggedPointer* self = this;
    MapEntry* n6 = reinterpret_cast<MapEntry*>(self->raw & ~1u);
    TaggedPointer* nX2 = &n6->next;
    return (nX2->raw & 1) != 0 ? true : false;
}

struct BucketMap
{
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
    virtual void Visit(unsigned __int64, int);
    int unk04, unk08;
    TaggedPointer* buckets;
};

struct Iterator
{
    BucketMap* map;
    MapEntry** hazard0;
    MapEntry** hazard1;
    MapEntry** hazard2;
    TaggedPointer* slot;
    TaggedPointer current;
    bool FUN_00c42380(uintptr_t, int, ObjectRef&);
};

// @fnv 0x00c40e70
bool Map40::FUN_00c40e70(Iter40* it, __int64* out, intptr_t arg, bool b)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool r = false;
    if (it->GetFlag2())
    {
        r = false;
    }
    else
    {
        while (1)
        {
            if (!it->GetFlag1())
            {
                r = reinterpret_cast<::Iterator *>((((::Bucket40 *)(reinterpret_cast<::FUN_00c3f750_Class *>(this)->FUN_00c3f750()))))->FUN_00c42380((uintptr_t)(&it->key), arg, *(::ObjectRef *)nullptr);
                it->SetFlag1(true);
            }
            else
            {
                r = reinterpret_cast<::NodeQueue *>((((::Bucket40 *)(reinterpret_cast<::FUN_00c3f750_Class *>(this)->FUN_00c3f750()))))->FUN_00c42560((intptr_t)(&it->key), (::NodeKey *)(arg), {});
            }
            if (!r)
            {
                it->idx++;
                if (it->idx >= GetCap())
                {
                    it->SetFlag2(true);
                }
                else if (b)
                {
                    it->SetFlag1(false);
                    continue;
                }
            }
            else
            {
                *out = it->key;
            }
            break;
        }
    }
    lock.Unlock();
    return r;
}

// @fnv 0x00c42380
bool Iterator::FUN_00c42380(uintptr_t index, int context, ObjectRef& output)
{
    bool success = false;
    while (true)
    {
        TaggedPointer* c5;
        TaggedPointer* cY;
        TaggedPointer* CSA;
        TaggedPointer* sn;
        unsigned int _raw;
        TaggedPointer* s;
        MapEntry* PN;
        TaggedPointer* sp;
        TaggedPointer* cR;
        TaggedPointer* CN;
        TaggedPointer* en;
        TaggedPointer sN7;

        en = &map->buckets[index];
        slot = en;
        current = *slot;
        CN = &current;
        *hazard1 = CN->Get();
        cR = &current;
        PN = reinterpret_cast<MapEntry*>(cR->raw & ~1u);
        sN7.raw = reinterpret_cast<uintptr_t>(PN);
        sp = &sN7;
        if (0)
            sp->raw |= 1;
        else
            sp->raw &= ~1u;
        s = slot;
        _raw = s->raw;
        sn = &sN7;
        if (_raw != static_cast<volatile TaggedPointer*>(sn)->raw)
            continue;
        CSA = &current;
        if ((CSA->raw & ~1u) == 0)
        {
            success = false;
            break;
        }
        cY = &current;
        map->Visit(reinterpret_cast<MapEntry*>(cY->raw & ~1u)->key, context);
        c5 = &current;
        output = reinterpret_cast<MapEntry*>(c5->raw & ~1u)->value;
        success = true;
        if (current.NextMarked())
            continue;
        break;
    }
    *hazard0 = 0;
    *hazard1 = 0;
    *hazard2 = 0;
    return success;
}

struct AllocationTLS
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
    int context;
};

__declspec(thread) AllocationTLS g_allocationTLS;

struct S_00c42960_Scope
{
    int m_old;
    __forceinline S_00c42960_Scope(int context) : m_old(Get())
    {
        Set(context);
    }
    __forceinline ~S_00c42960_Scope()
    {
        Set(m_old);
    }
    static __forceinline int Get()
    {
        return (*reinterpret_cast<::AllocationTLS *>(&::g_tlsBlock)).context;
    }
    static __forceinline void Set(int context)
    {
        (*reinterpret_cast<::AllocationTLS *>(&::g_tlsBlock)).context = context;
    }
};

extern "C" char DAT_011f6238;

struct S_00c42960_Heap
{
    void* FUN_00aa3e40(unsigned int size);
};

struct ReleaseObject
{
    virtual ~ReleaseObject();
    int unk04;
    long refs;
    inline void FUN_0044dd60()
    {
        long remaining = InterlockedDecrement(&refs);
        if (remaining == 0)
            delete this;
    }
};

struct S_00c42960_Node;

struct NodeLink
{
    S_00c42960_Node* value;
    __forceinline ~NodeLink();
};

struct S_00c42960_Node
{
    int unk00;
    int unk04;
    NodeLink m_pNext;
    void FUN_0044dd60();
    __forceinline S_00c42960_Node* GetNext()
    {
        return m_pNext.value;
    }
};

__forceinline NodeLink::~NodeLink()
{
    if (value)
        reinterpret_cast<ReleaseObject*>(value)->FUN_0044dd60();
}

struct S_00c42960_Slot
{
    S_00c42960_Node* m_pReferencedNode;
};

struct S_00c42960_Counter
{
    unsigned int m_uiItemCount;
    __forceinline unsigned int GetCount()
    {
        return m_uiItemCount;
    }
};

struct S_00c42960_Owner
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
    virtual void FreePair(int key, int value);
    S_00c42960_Slot* m_pEntryData;
    int unk08;
    int unk0C;
    int unk10;
    S_00c42960_Counter* m_pCounter;
    __forceinline S_00c42960_Slot* GetArray()
    {
        return m_pEntryData;
    }
    __forceinline S_00c42960_Counter* GetCounter()
    {
        return m_pCounter;
    }
    inline void FUN_00c41fe0(S_00c42960_Node* node)
    {
        FreePair(node->unk00, node->unk04);
        delete node;
    }
};

struct S_00c42960
{
    S_00c42960_Owner* m_pSharedOwner;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    S_00c42960_Node* m_pHead;
    unsigned int m_uiItemCount;
    void FUN_00c42960();
};

// Calls Step repeatedly while m_20 is non-zero, stopping once it reaches zero.
// @fnv 0x00c42b40
void FUN_00c42b40_cls::FUN_00c42b40()
{
    unsigned int scratch[22];
    int tmp;
    while (m_20 != 0)
    {
        reinterpret_cast<::S_00c42960 *>(this)->FUN_00c42960();
    }
}

// @fnv 0x00c42960
void S_00c42960::FUN_00c42960()
{
    S_00c42960_Scope scope2(6);
    unsigned int n9 = m_pSharedOwner->GetCounter()->GetCount() * 3;
    S_00c42960_Slot* p = new S_00c42960_Slot[n9];
    std::memmove(p, m_pSharedOwner->GetArray(), n9 * 4);
    S_00c42960_Node* headR = 0;
    unsigned int cnt2 = 0;
    while (m_pHead)
    {
        S_00c42960_Node* node2 = m_pHead;
        m_pHead = m_pHead->GetNext();
        bool found2 = false;
        for (unsigned int i = 0; i < n9; ++i)
        {
            if (node2 == p[i].m_pReferencedNode)
            {
                found2 = true;
                break;
            }
        }
        if (found2)
        {
            node2->m_pNext.value = headR;
            headR = node2;
            ++cnt2;
        }
        else
        {
            node2->m_pNext.value = 0;
            reinterpret_cast<::NodeMap *>((m_pSharedOwner))->FreeNode((::WeightedMapNode *)(node2));
        }
    }
    delete[] p;
    m_pHead = headR;
    m_uiItemCount = cnt2;
}

struct ExtraBase_c42ff0
{
    int m_vtbl;
    int unk04;
    int unk08;
    ExtraBase_c42ff0();
};

struct IntMid_c42ff0 : ExtraBase_c42ff0
{
    __forceinline IntMid_c42ff0()
    {
        m_vtbl = (intptr_t)&DAT_010a0d24;
    }
};

struct IntData_c42ff0 : IntMid_c42ff0
{
    int m_iValue;
    __forceinline IntData_c42ff0(int v) : m_iValue(v)
    {}
    ~IntData_c42ff0();
};

struct FUN_00c42ff0 : IntData_c42ff0
{
    FUN_00c42ff0(int v);
};

// @fnv 0x00c42ff0
FUN_00c42ff0::FUN_00c42ff0(int v) : IntData_c42ff0(v)
{
    m_vtbl = (intptr_t)&DAT_010c1854;
    reinterpret_cast<::NiAVObject *>(this)->FUN_00c43470();
}

extern "C" void* __cdecl FUN_00a7d5e0(const char*, const char*);

inline bool TestBit(unsigned char value, unsigned mask, unsigned zero)
{
    return (value & (mask | zero)) != 0;
}

class ObjArg
{
  public:
};

class FUN_00c43ab0_cls
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
    unsigned char m_ac;
    unsigned char unkAD;
    unsigned char unkAE;
    unsigned char unkAF;
    unsigned int m_b0;

    void FUN_00c43ab0(ObjArg* a1);
};

struct ValKeep
{
    unsigned u0;
    unsigned u1;
    unsigned u2;
    unsigned u3;
    unsigned u4;
    unsigned val;
    unsigned u5;
};

// @fnv 0x00c43ab0
void FUN_00c43ab0_cls::FUN_00c43ab0(ObjArg* a1)
{
    void* text;
    void* vtext;
    void* line;
    void* rtti;
    ValKeep stored;

    reinterpret_cast<::FUN_00a5ea70_t *>((this))->FUN_00a5ea70((::StrArr *)(a1));
    rtti = (*reinterpret_cast<void * *>(&::g_01202de8));
    text = ((void *)(::FUN_00a7d330((const char *)(rtti))));
    reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((intptr_t)(&text));
    stored.val = this->m_b0;
    vtext = ((void *)(::FUN_00a7d4d0("Value", (intptr_t)((void*)stored.val))));
    reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((intptr_t)(&vtext));
    if (TestBit(this->m_ac, 1u, 0u))
    {
        line = ((void *)(::fnv_00a7d5e0::FUN_00a7d5e0("Billboard", TestBit(this->m_ac, 1u, 0u) ? "true" : "false")));
        reinterpret_cast<::S_0060ba10 *>((a1))->FUN_0096a610((intptr_t)(&line));
    }
}

struct NiUpdateData;

struct S00c43b90_Bound
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
};

struct S00c43b90_t
{
    void* unk00;
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
    S00c43b90_Bound unk68;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    unsigned char unkAC;

    inline bool GetBit(unsigned char mask) const
    {
        return (unkAC & mask) != 0;
    }
    void FUN_00c43b90(NiUpdateData& data);
};

// @fnv 0x00c43b90
void S00c43b90_t::FUN_00c43b90(NiUpdateData& data)
{
    reinterpret_cast<::NiAVObject *>(this)->UpdateWorldData(data);

    if (GetBit(1))
    {
        unk68 = *reinterpret_cast<S00c43b90_Bound*>(&(*reinterpret_cast<::S00c43b90_Bound *>(&::DAT_011a9448)));
    }
}

union SettingValue
{
    char character;
    bool boolean;
    int integer;
    unsigned int color;
    float real;
    char* string;
};

struct IniSetting
{
    int flags;
    SettingValue value;
    char* name;
    __forceinline char* GetName()
    {
        char* resultName = name;
        return resultName;
    }
    __forceinline int& GetInteger()
    {
        SettingValue* original = this ? &value : ((*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).integer = 0, &(*reinterpret_cast<::SettingValue *>(&::DAT_01202800)));
        return original->integer;
    }
    __forceinline float& GetReal()
    {
        SettingValue* original = this ? &value : ((*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).real = 0.0f, &(*reinterpret_cast<::SettingValue *>(&::DAT_01202800)));
        return original->real;
    }
    __forceinline bool& GetBoolean()
    {
        SettingValue* original = this ? &value : ((*reinterpret_cast<::SettingValue *>(&::DAT_01202800)).boolean = false, &(*reinterpret_cast<::SettingValue *>(&::DAT_01202800)));
        return original->boolean;
    }
    __forceinline void SetInteger(int number)
    {
        if (this)
            value.integer = number;
    }
};

struct LanguageSetting
{
    int flags;
    char* value;
    __forceinline char* GetString()
    {
        return this ? value : 0;
    }
};

__forceinline unsigned int MakeIniColor(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha)
{
    unsigned int color = red << 24;
    color |= (green & 255) << 16;
    color |= (blue & 255) << 8;
    color |= alpha & 255;
    return color;
}

struct IniCollection
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void Open(bool create);
    virtual void Close();
    char filename[260];
    void* file;
    bool FUN_00c44280(IniSetting* setting);
};

// @fnv 0x00c44280
bool IniCollection::FUN_00c44280(IniSetting* setting)
{
    bool success3 = false;
    bool opened3;
    DWORD count;
    {
        char defaultValue3[256];
        char key17[64];
        unsigned int type6;
        char section2[64];
        char value2[256];
        char stringValue2[1024];
        char language[1024];
        if (setting->GetName())
        {
            opened3 = file == 0;
            if (opened3)
                Open(true);
            if (file)
            {
                type6 = ((unsigned int)(::FUN_00c33090(setting->name)));
                CopyMainNameFromPath((intptr_t)setting, key17);
                CopyStringBeforeColon((FUN_00c43e00_Obj*)setting, section2);
                switch (type6)
                {
                case 6:
                    if (std::strcmp(key17, "LANGUAGE") == 0)
                    {
                        count = GetPrivateProfileStringA("General", "sLanguage", (*reinterpret_cast<::LanguageSetting *>(&::g_011c3cb4)).GetString(), language,
                                                         256, filename);
                        std::strcpy(key17, language);
                    }
                    {
                        count = GetPrivateProfileStringA(key17, section2, setting ? setting->value.string : 0,
                                                         stringValue2, 256, filename);
                        reinterpret_cast<::SettingS *>((setting))->FUN_00c33170(stringValue2);
                    }
                    break;
                case 1: {
                    setting->value.character =
                        (char)GetPrivateProfileIntA(key17, section2, setting->GetInteger(), filename);
                }
                break;
                case 3: {
                    setting->SetInteger(GetPrivateProfileIntA(key17, section2, setting->GetInteger(), filename));
                }
                break;
                case 5: {
                    ::FUN_00406d00(defaultValue3, 256, "%f", setting->GetReal());
                    count = GetPrivateProfileStringA(key17, section2, defaultValue3, value2, 256, filename);
                    if (count)
                        success3 = std::sscanf(value2, "%f", &setting->value.real) == 1;
                }
                break;
                case 7: {
                    count = GetPrivateProfileStringA(key17, section2, "", value2, 256, filename);
                    if (count)
                    {
                        unsigned int red, green2, blue3;
                        success3 = std::sscanf(value2, "%u,%u,%u", &red, &green2, &blue3) == 3;
                        setting->value.color = MakeIniColor(red, green2, blue3, 255);
                    }
                }
                break;
                case 8: {
                    count = GetPrivateProfileStringA(key17, section2, "", value2, 256, filename);
                    if (count)
                    {
                        unsigned int red, green2, blue3, alpha;
                        success3 = std::sscanf(value2, "%u,%u,%u,%u", &red, &green2, &blue3, &alpha) == 4;
                        setting->value.color = MakeIniColor(red, green2, blue3, alpha);
                    }
                }
                break;
                case 0: {
                    int defaultBoolean = setting->GetBoolean() ? 1 : 0;
                    int number6 = GetPrivateProfileIntA(key17, section2, defaultBoolean, filename);
                    setting->value.boolean = number6 != 0;
                }
                break;
                default: {
                    setting->SetInteger(GetPrivateProfileIntA(key17, section2, setting->GetInteger(), filename));
                }
                break;
                }
            }
            if (opened3)
                Close();
        }
    }
    return success3;
}

typedef void(__cdecl* CbQ)(void*, bool);

struct FUN_00c455a0_cls
{
    char pad[0x30];
    unsigned int m_uiObjectFlags;
    char pad2[0xae - 0x34];
    unsigned char m_ucLo;
    unsigned char m_ucHi;
    void SetBitQ(bool b, unsigned int m)
    {
        if (b)
            m_uiObjectFlags |= m;
        else
            m_uiObjectFlags &= ~m;
    }
    bool IsHiddenQ()
    {
        return (m_uiObjectFlags & 1) != 0;
    }
    unsigned char GetLo()
    {
        unsigned char c = m_ucLo;
        return c;
    }
    unsigned char GetHi()
    {
        unsigned char c = m_ucHi;
        return c;
    }
    bool FUN_00c455a0(unsigned char ucLevel);
};

// @fnv 0x00c451b0
void FUN_00c451b0_class::CopyStateTo(intptr_t pTarget, intptr_t b)
{
    reinterpret_cast<::FUN_00c5fb60_class *>((((FUN_00c5fb60_Class*)this)))->ForwardToBase((::S_00a953b0_Node *)(pTarget), (void *)(b));
    char c3 = *(char*)((char*)this + 0xae);
    *(char*)(pTarget + 0xae) = c3;
    char c1 = *(char*)((char*)this + 0xaf);
    *(char*)(pTarget + 0xaf) = c1;
    unsigned char c2 = *(unsigned char*)((char*)this + 0xad);
    reinterpret_cast<::FUN_00c455a0_cls *>((((FUN_00c455a0_Class*)pTarget)))->FUN_00c455a0(c2);
}

// Loads the base node binary, reads three booleans from the stream into m_bFlagAE, m_bFlagAF and SetFlag.
// @fnv 0x00c45220
void BSNodeC45::FUN_00c45220(NiStream& kStream)
{
    reinterpret_cast<::fnv_00a5dd40::FUN_00a5dd40_shell *>(this)->FUN_00a5dd40((::NiStream *)&(kStream));

    bool m_bHeaderParsed;
    ::FUN_00a643b0((::BA643B0Stream &)(kStream), (char *)&(m_bHeaderParsed));
    bool bFirst = m_bHeaderParsed;
    m_bFlagAE = bFirst;

    ::FUN_00a643b0((::BA643B0Stream &)(kStream), (char *)&(m_bHeaderParsed));
    bool bSecond = m_bHeaderParsed;
    m_bFlagAF = bSecond;

    ::FUN_00a643b0((::BA643B0Stream &)(kStream), (char *)&(m_bHeaderParsed));
    reinterpret_cast<::FUN_00c455a0_cls *>(this)->FUN_00c455a0(m_bHeaderParsed);
}

// @fnv 0x00c455a0
bool FUN_00c455a0_cls::FUN_00c455a0(unsigned char ucLevel)
{
    bool bNew;
    bool bOld = !IsHiddenQ();
    bNew = ucLevel >= GetLo() && ucLevel <= GetHi();
    if (bOld != bNew)
    {
        SetBitQ(!bNew, 1);
        if (DAT_01202e08)
            DAT_01202e08(this, bNew);
    }
    return bNew;
}

struct MyRef
{
    virtual void vf00();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
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

struct OwnerWord
{
    int owner;
};

// /Ob1 tries to inline these and then refuses on size. The refused locals stay
// in the caller's frame (two for the lock, one for the insert) and the calls remain.
inline void GameLockA::FUN_0040fbf0(int a)
{
    int passes;
    int spins;
    passes = a;
    spins = passes;
    passes = passes + 1;
    passes = passes + 2;
    passes = passes + 3;
    passes = passes + 4;
    passes = passes + 5;
    passes = passes + 6;
    passes = passes + 7;
    passes = passes + 8;
    passes = passes + 9;
    passes = passes + 10;
    passes = passes + 11;
    passes = passes + 12;
    passes = passes + 13;
    passes = passes + 14;
    passes = passes + 15;
    passes = passes + 16;
    passes = passes + 17;
    passes = passes + 18;
    passes = passes + 19;
    passes = passes + 20;
    passes = passes + 21;
    passes = passes + 22;
    passes = passes + 23;
    passes = passes + 24;
    passes = passes + 25;
    passes = passes + 26;
    passes = passes + 27;
    passes = passes + 28;
    passes = passes + 29;
    passes = passes + 30;
    passes = passes + 31;
    passes = passes + 32;
    passes = passes + 33;
    passes = passes + 34;
    passes = passes + 35;
    passes = passes + 36;
    passes = passes + 37;
    passes = passes + 38;
    passes = passes + 39;
    passes = passes + 40;
    spins = passes;
}


// @fnv 0x00c45830
void __cdecl FUN_00c45830(MyRef* object)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(DAT_01202e40))->FUN_0040fbf0((char *)(0));
    {
        NiPointer<MyRef> local(object);
        reinterpret_cast<FUN_00c45e00_class&>(DAT_01202e20).AppendElement((uintptr_t)&local);
    }
    DAT_01202e44 = DAT_01202e44 - 1;
    if (DAT_01202e44 == 0)
        reinterpret_cast<OwnerWord&>(DAT_01202e40).owner = 0;
}

struct C45Object
{
    virtual void v00();
    virtual void v04();
    volatile long m04;
    void Inc()
    {
        InterlockedIncrement(&m04);
    }
    void Dec()
    {
        if (!InterlockedDecrement(&m04))
            v04();
    }
};

struct C45Pointer
{
    C45Object* m00;
    C45Pointer(C45Object* p = 0) : m00(p)
    {
        if (m00)
            m00->Inc();
    }
    C45Pointer(const C45Pointer& p) : m00(p.m00)
    {
        if (m00)
            m00->Inc();
    }
    ~C45Pointer()
    {
        if (m00)
            m00->Dec();
    }
    bool operator!=(const C45Pointer& p) const
    {
        return m00 != p.m00;
    }
};

struct C45Array
{
    void* m00;
    C45Pointer* m04;
    unsigned short m08, m0a, m0c, m0e;
    C45Pointer FUN_00c45e50(unsigned int index);
};

inline void C45TemporaryStorage()
{
    struct Storage
    {
        int m00, m04;
    } storage;
    (void)&storage;
}

// @fnv 0x00c45e50
C45Pointer C45Array::FUN_00c45e50(unsigned int index)
{
    if (index >= m0a)
        return C45Pointer();
    C45Pointer result = m04[index];
    ((*(::C45Pointer *)&(reinterpret_cast<::FUN_00c46270_Class *>(&(m04[index]))->AssignRefCounted((const ::FUN_00c46270_Class &)((const ::C45Pointer &)(C45Pointer()))))), C45TemporaryStorage());
    if (result != C45Pointer())
        --m0c;
    if (index == (unsigned short)(m0a - 1))
        --m0a;
    return result;
}

struct S00c46080_Tmp : public FUN_00c46270_Class
{
    S00c46080_Tmp(RefCountedObject* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
        {
            RefCountedObject* obj = m_pObject;
            InterlockedIncrement(&obj->m_lObjectReferenceCount);
        }
    }
    ~S00c46080_Tmp()
    {
        int u1;
        int u2;
        if (m_pObject)
        {
            RefCountedObject* obj = m_pObject;
            if (InterlockedDecrement(&obj->m_lObjectReferenceCount) == 0)
            {
                obj->vfn_0004();
            }
        }
    }
};

struct S00c46080_Arr
{
    void** m_ppVirtualMethodTable;
    FUN_00c46270_Class* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00c46080();
};

// @fnv 0x00c459d0
void __cdecl FUN_00c459d0(unsigned char a1)
{
    FUN_00c459d0_frame frame;
    bool flag = true;
    bool got;
    if (a1 != 0) {
        flag = reinterpret_cast<::FUN_0078d200_cls *>(&(DAT_01202e40))->FUN_0078d200();
    } else {
        reinterpret_cast<::FUN_0040fbf0_shell *>(&(DAT_01202e40))->FUN_0040fbf0((char *)(0));
    }
    if (flag) {
        got = TryEnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_011f4380)) ? true : false;
        if (!got) {
            if (--DAT_01202e44 == 0) {
                *reinterpret_cast<unsigned int*>(&DAT_01202e40) = 0;
            }
            return;
        }
    }
    if (flag) {
        reinterpret_cast<::S00c46080_Arr *>(&(DAT_01202e20))->FUN_00c46080();
        ::fnv_00c45a80::TruncateStringToMaxLength();
        LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_011f4380));
        if (--DAT_01202e44 == 0) {
            *reinterpret_cast<unsigned int*>(&DAT_01202e40) = 0;
        }
    }
}

// @fnv 0x00c46080
void S00c46080_Arr::FUN_00c46080()
{
    for (unsigned short i = 0; i < m_usSize; ++i)
    {
        m_pBase[i].AssignRefCounted(S00c46080_Tmp());
    }
    m_usSize = 0;
    m_usESize = 0;
}

struct RefC46
{
    virtual void V0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

// BSNiNode is 0xAC. The multibound smart pointer sits at the end of that base.
struct BSNiNodeC46
{
    virtual ~BSNiNodeC46();
    int m04, m08, m0C, m10, m14, m18, m1C, m20;
    int m24, m28, m2C, m30, m34, m38, m3C, m40;
    int m44, m48, m4C, m50, m54, m58, m5C, m60;
    int m64, m68, m6C, m70, m74, m78, m7C, m80;
    int m84, m88, m8C, m90, m94, m98, m9C, mA0;
    int mA4, mA8;
};

// operator= is inline but far past VC9's /Ob1 size limit, so the call stays
// out of line and its two locals remain reserved in the caller frame.
template <class T> struct MultiBoundPtr
{
    T* m_pObject;
    __forceinline ~MultiBoundPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    inline MultiBoundPtr& operator=(T* p);
};

template <class T> inline MultiBoundPtr<T>& MultiBoundPtr<T>::operator=(T* p)
{
    int gap0;
    int gap1;
    gap0 = (intptr_t)p;
    gap1 = gap0;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    gap0 = gap1 + 1;
    gap1 = gap0 + 2;
    gap0 = gap1 + 3;
    gap1 = gap0 + 4;
    if (p == (T*)1)
        return operator=((T*)0);
    return *this;
}

namespace mb {
struct FUN_00c46af0 : BSNiNodeC46
{
    MultiBoundPtr<RefC46> multiBound;
    ~FUN_00c46af0();
};
}

// Calls Destruct, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c47610
void* FUN_00c46af0::FUN_00c47610(unsigned int flags)
{
    reinterpret_cast<::mb::FUN_00c46af0 *>(this)->mb::FUN_00c46af0::~FUN_00c46af0();
    if (flags & 1)
        operator delete(this, 0xb4);
    return this;
}

// @fnv 0x00c46af0
mb::FUN_00c46af0::~FUN_00c46af0()
{
    multiBound = 0;
}

// FUN_00c47570 candidate
class FNV_Base_cls
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
    virtual int v98(int a1);
};

class FNV_Inner_cls : public FNV_Base_cls
{
};

class FNV_Mid_cls
{
  public:
    int unk00, unk04, unk08;
    FNV_Inner_cls* m_0c;
};

inline FNV_Base_cls* AsBase(FNV_Inner_cls* p)
{
    return p;
}

class FUN_00c47570_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C,
        unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;
    FNV_Mid_cls* m_ac;
    int FUN_00c47570(int a1);
};

// @fnv 0x00c47570
int FUN_00c47570_cls::FUN_00c47570(int a1)
{
    FNV_Mid_cls* p2 = m_ac;
    FNV_Inner_cls* q = p2->m_0c;
    int res = AsBase(q)->v98(a1);
    return res;
}

// Geometry command emission for a polygon and its adjoining polygon.



struct CommandPolygon
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int type;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8;
    CommandPolygon* neighbors[4];
    void FUN_00c33870(GeometryPoint, void*);
    __forceinline CommandPolygon* NeighborAt(int i) const
    {
        return neighbors[i];
    }
    __forceinline int GetType() const
    {
        int value = type;
        return value;
    }
    __forceinline int SideIndex() const
    {
        int value = neighbors[1] ? 1 : 3;
        return value;
    }
    __forceinline int EndIndex() const
    {
        int value = neighbors[0] ? 0 : 2;
        return value;
    }
    __forceinline CommandPolygon* SideNeighbor() const
    {
        int index1 = SideIndex();
        return NeighborAt(index1);
    }
    __forceinline CommandPolygon* EndNeighbor() const
    {
        int index1 = neighbors[0] ? 0 : 2;
        return NeighborAt(index1);
    }
};

struct CommandRecords
{
    void* vtable;
    FUN_0045c620* data;
    int allocated;
    int capacity;
    void FUN_00c4a070(int, bool);
    __forceinline int GetCapacity() const
    {
        int value = capacity;
        return value;
    }
    __forceinline FUN_0045c620& operator[](int i)
    {
        return data[i];
    }
};

struct CommandArray
{
    void* vtable;
    Elem0C* m_pData;
    int allocated, m_uiSize;
    void FUN_00c4a1e0(int, bool);
    __forceinline int GetCapacity() const
    {
        int value = m_uiSize;
        return value;
    }
    __forceinline Elem0C& operator[](int i)
    {
        return m_pData[i];
    }
};

struct GeometryCommands
{
    unsigned char state;
    CommandRecords records;
    CommandArray commands;
    int recordCount, commandCount, unknown2c;
    FNV_Local workingRecord;
    GeometryPoint origin;
    void FUN_00c47d20(CommandPolygon* polygon);
};

// @fnv 0x00c47d20
void GeometryCommands::FUN_00c47d20(CommandPolygon* polygon)
{
    int type = reinterpret_cast<::FUN_00c35980_Class *>((polygon))->FUN_00c35980();
    CommandPolygon* neighborTriangleA =
        type == 1 ? polygon->NeighborAt(polygon->SideIndex()) : polygon->NeighborAt(polygon->EndIndex());
    bool kA1_1 = false;
    int side = 0;
    if (neighborTriangleA)
    {
        GeometryPoint verticesCheck2[4];
        FUN_0045c620 record2_2;
        polygon->FUN_00c33870(origin, &record2_2);
        reinterpret_cast<::Builder *>((polygon))->FUN_00c35c10((::Point *)(verticesCheck2));
        FUN_00a699d0 plane4(&verticesCheck2[0], &verticesCheck2[1], &verticesCheck2[2]);
        side = reinterpret_cast<::NiCamera *>(&(plane4))->ClassifyPoint((const ::NiPoint3 *)(const ::GeometryPoint *)(&origin));
        neighborTriangleA->FUN_00c33870(origin, &record2_2);
        reinterpret_cast<::Builder *>((neighborTriangleA))->FUN_00c35c10((::Point *)(verticesCheck2));
        plane4 = FUN_00a699d0(&verticesCheck2[0], &verticesCheck2[1], &verticesCheck2[2]);
        kA1_1 = side == reinterpret_cast<::NiCamera *>(&(plane4))->ClassifyPoint((const ::NiPoint3 *)(const ::GeometryPoint *)(&origin));
    }
    if ((neighborTriangleA && neighborTriangleA->GetType() != 1) || !kA1_1)
    {
        if (commandCount + 2 >= commands.GetCapacity())
        {
            reinterpret_cast<::FUN_00c4a1e0 *>(&(commands))->SetSize(commands.GetCapacity() + 10, true);
        }
        if (recordCount + 1 >= records.GetCapacity())
            reinterpret_cast<::FUN_00c4a070 *>(&(records))->SetSize(records.GetCapacity() + 4, true);
        commands[commandCount].a = 8;
        ++commandCount;
        commands[commandCount].a = recordCount;
        ++commandCount;
        polygon->FUN_00c33870(origin, &records[recordCount]);
        ++recordCount;
        return;
    }
    switch (type)
    {
    case 0: {
        if (commandCount + 2 >= commands.GetCapacity())
        {
            reinterpret_cast<::FUN_00c4a1e0 *>(&(commands))->SetSize(commands.GetCapacity() + 10, true);
        }
        if (recordCount + 1 >= records.GetCapacity())
            reinterpret_cast<::FUN_00c4a070 *>(&(records))->SetSize(records.GetCapacity() + 4, true);
        commands[commandCount].a = 8;
        ++commandCount;
        commands[commandCount].a = recordCount;
        ++commandCount;
        polygon->FUN_00c33870(origin, &records[recordCount]);
        ++recordCount;
        return;
        break;
    }
    case 1: {
        if (commandCount + 12 >= commands.GetCapacity())
        {
            reinterpret_cast<::FUN_00c4a1e0 *>(&(commands))->SetSize(commands.GetCapacity() + 12, true);
        }
        if (recordCount + 4 >= records.GetCapacity())
            reinterpret_cast<::FUN_00c4a070 *>(&(records))->SetSize(records.GetCapacity() + 4, true);
        commands[commandCount++].a = 4;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount + 1;
        commands[commandCount++].a = 5;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount + 2;
        commands[commandCount++].a = 8;
        commands[commandCount++].a = recordCount + 3;
        commands[commandCount++].a = 6;
        commands[commandCount++].a = 6;
        polygon->FUN_00c33870(origin, &records[recordCount]);
        polygon->FUN_00c33870(origin, &records[recordCount + 2]);
        int index1 = polygon->neighbors[1] ? 1 : 3;
        int kA114_2 = 0;
        side = 1;
        if (index1 == 1)
            kA114_2 = side == 1 ? 2 : 3;
        else
            kA114_2 = side == 1 ? 3 : 5;
        records[recordCount + 2].ClearPlane(kA114_2);
        CommandPolygon* adjacent3 = polygon->neighbors[index1];
        adjacent3->FUN_00c33870(origin, &records[recordCount + 1]);
        adjacent3->FUN_00c33870(origin, &records[recordCount + 3]);
        if (index1 == 1)
            kA114_2 = kA114_2 == 2 ? 3 : 2;
        else
            kA114_2 = kA114_2 == 4 ? 5 : 4;
        records[recordCount + 3].ClearPlane(kA114_2);
        recordCount += 4;
        break;
    }
    }
}

struct Elem_c48800
{
    int field0;
    int field4;
    int field8;
};

__forceinline Elem_c48800* elemAt(Elem_c48800* p, int i)
{
    return &p[i];
}

struct Sub_c4a070
{
    int unk00;
    void FUN_00c4a070(int, bool);
};

struct Sub_c4a1e0
{
    int unk00;
    void FUN_00c4a1e0(int, bool);
};

struct FUN_00c48800_cls
{
    char m_00;
    char unk01;
    char unk02;
    char unk03;
    Sub_c4a070 m_04;
    NavEntryItem* m_08;
    int unk0C;
    int m_10;
    Sub_c4a1e0 m_14;
    Elem_c48800* m_18;
    int unk1C;
    int m_20;
    int m_24;
    int m_28;

    void FUN_00c48800(FUN_00c48800_cls* arg);
};

// @fnv 0x00c48800
void FUN_00c48800_cls::FUN_00c48800(FUN_00c48800_cls* arg)
{
    int cf;
    int q;
    int b;
    int ba;
    int k;
    int l;
    int c;
    Elem_c48800* e;
    NavEntryItem* j;

    ba = this->m_20;
    if (arg->m_28 + this->m_28 + 1 >= ba)
    {
        reinterpret_cast<::FUN_00c4a1e0 *>(&(this->m_14))->SetSize((k = this->m_20) + (arg->m_28 + 1 > 10 ? arg->m_28 + 1 : 10), true);
    }
    l = this->m_10;
    if (arg->m_24 + this->m_24 + 1 >= l)
    {
        reinterpret_cast<::FUN_00c4a070 *>(&(this->m_04))->SetSize((c = this->m_10) + (arg->m_24 + 1 > 4 ? arg->m_24 + 1 : 4), true);
    }
    this->m_00 = 0;
    for (cf = 0; cf < arg->m_28; ++cf)
    {
        e = &arg->m_18[cf];
        this->m_18[this->m_28 + cf].field0 = e->field0;
    }
    for (q = 0; q < arg->m_24; ++q)
    {
        j = &arg->m_08[q];
        this->m_08[this->m_24 + q] = *j;
    }
    if (this->m_24 != 0)
    {
        for (b = this->m_28; b < this->m_28 + arg->m_28; ++b)
        {
            switch (this->m_18[b].field0)
            {
            case 7:
            case 8:
                elemAt(this->m_18, b + 1)->field0 += this->m_24;
                b++;
                break;
            }
        }
    }
    this->m_28 += arg->m_28;
    this->m_24 += arg->m_24;
}

struct Q48Tok
{
    int m_type;
    int m_kPointA;
    int m_kPointB;
};

struct Q48Arr
{
    void* vtbl;
    Q48Tok* m_data;
    int m_auiShapeKeys;
    int m_alloc;
    inline Q48Tok& At(int i)
    {
        return m_data[i];
    }
    inline int Alloc()
    {
        return m_alloc;
    }
    void FUN_00c4a1e0(int n, bool b);
};

struct Q48Obj
{
    char pad[0x14];
    Q48Arr m_toks;
    int m_24;
    int m_uiItemCount;
    void FUN_00c48b90();
};

// @fnv 0x00c48b90
void Q48Obj::FUN_00c48b90()
{
    bool ok = true;
    if (m_toks.At(0).m_type == 5)
    {
        int iDepth = 1;
        int iTok5 = 1;
        while (iDepth > 0 && iTok5 < m_uiItemCount)
        {
            switch (m_toks.At(iTok5).m_type)
            {
            case 4:
            case 5:
                iDepth++;
                break;
            case 6:
                iDepth--;
                break;
            }
            iTok5++;
        }
        if (iTok5 == m_uiItemCount && iDepth == 0)
            ok = false;
    }
    if (ok)
    {
        if (m_uiItemCount + 1 >= m_toks.Alloc())
            reinterpret_cast<::FUN_00c4a1e0 *>(&(m_toks))->SetSize(m_toks.Alloc() + 10, true);
        reinterpret_cast<::FUN_00c48a10_t *>(this)->ShiftElements(true, false);
        m_toks.At(0).m_type = 5;
    }
    else
    {
        m_uiItemCount--;
    }
}

struct TreeVector;

struct TreePlane
{
    float x, y, z, distance;
    float EvaluatePlane(const TreeVector& vector) const;
};

struct TreeVector
{
    float x;
    float y;
    float z;
    float w;
    float GetW() const
    {
        return w;
    }
    int ClassifySphereAgainstPlane(TreePlane* plane) const;
    int ClassifySphereAgainstPlane(TreePlane* plane)
    {
        float distance = plane->EvaluatePlane(*this);
        if (distance < -w)
            return 2;
        else if (distance > w)
            return 1;
        else
            return 0;
    }
};

struct TreeQuery
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    TreeVector* m_pkVector;  // +0x20

    int HasVector() const
    {
        return m_pkVector && m_pkVector->GetW() != 0.0;
    }
    const TreeVector& GetAudioPosition() const
    {
        return m_pkVector ? *m_pkVector : (*reinterpret_cast<::TreeVector *>(&::g_defaultBound));
    }
};

struct TreeEntry
{
    TreePlane planes[6];
    unsigned int activePlanes;
};

struct TreeNode
{
    int m_iType;
    int m_iField04;
    int m_iFail;
};

class TreeEvaluator
{
  public:
    int unk00;
    int unk04;
    TreeEntry* m_pkEntryArray;  // +0x08
    int unk0c;
    int unk10;
    int unk14;
    TreeNode* m_pkNodes;  // +0x18
    int unk1c;
    int unk20;
    int unk24;
    int m_iNodeCount;        // +0x28
    int m_iRoot;             // +0x2c
    TreeEntry m_kRootEntry;  // +0x30
    int unk94;
    int unk98;
    int unk9c;
    bool m_bSkipRoot;  // +0xa0

    TreeEntry* GetEntry(int index)
    {
        TreeNode* pkNext = &m_pkNodes[index];
        return &m_pkEntryArray[pkNext->m_iType];
    }
    template <class Bound> bool ProcessEntries(Bound* pkVector, TreeEntry* pkEntry)
    {
        if (!pkEntry->activePlanes)
            return true;
        else
        {
            int planeIndex;
            for (planeIndex = 0; planeIndex < 6; ++planeIndex)
            {
                if (pkEntry->activePlanes & (1 << planeIndex))
                {
                    int side = pkVector->ClassifySphereAgainstPlane(&pkEntry->planes[planeIndex]);
                    if (side == 2)
                        break;
                    if (side == 1)
                        pkEntry->activePlanes &= ~(1 << planeIndex);
                }
            }
            if (planeIndex == 6)
                return true;
        }
        return false;
    }
    bool FUN_00c4a790(TreeVector* pkVector, TreeEntry* pkEntry)
    {
        if (!pkEntry->activePlanes)
            return false;
        else
        {
            int planeIndex;
            for (planeIndex = 0; planeIndex < 6; ++planeIndex)
            {
                if (pkEntry->activePlanes & (1 << planeIndex))
                {
                    int side = pkVector->ClassifySphereAgainstPlane(&pkEntry->planes[planeIndex]);
                    if (side != 1)
                        break;
                    else if (side == 1)
                        pkEntry->activePlanes &= ~(1 << planeIndex);
                }
            }
            if (planeIndex == 6)
                return false;
        }
        return true;
    }
    bool FUN_00c491a0(TreeQuery* pkQuery);
};

// @fnv 0x00c491a0
bool TreeEvaluator::FUN_00c491a0(TreeQuery* pkQuery)
{
    if (!pkQuery->HasVector())
        return false;
    TreeEntry* pkEntry = 0;
    TreeVector kVector = pkQuery->GetAudioPosition();
    bool bResultTmp = true;
    if (!m_bSkipRoot)
        bResultTmp = reinterpret_cast<::FUN_00c4a6e0_cls *>(this)->ProcessEntries((::CallerObj_b3918 *)(static_cast<const TreeVector*>(&kVector)), (::EntrySet_b3918 *)(::TreeEntry *)(&m_kRootEntry));
    if (bResultTmp && m_iNodeCount > 0)
    {
        int i = m_iRoot;
        while (m_pkNodes[i].m_iType != 2 && m_pkNodes[i].m_iType != 3)
        {
            bool bPass = false;
            switch (m_pkNodes[i].m_iType)
            {
            case 7: {
                pkEntry = GetEntry(i + 1);
                bPass = reinterpret_cast<::FUN_00c4a6e0_cls *>(this)->ProcessEntries((::CallerObj_b3918 *)(::TreeVector *)(&kVector), (::EntrySet_b3918 *)(pkEntry));
                break;
            }
            case 8: {
                pkEntry = GetEntry(i + 1);
                bPass = reinterpret_cast<::c4a790_Owner *>(this)->FUN_00c4a790((::CallerObj_b3918 *)(::TreeVector *)(&kVector), (::c4a790_Obj *)(pkEntry));
                break;
            }
            }
            i = bPass ? m_pkNodes[i].m_iField04 : m_pkNodes[i].m_iFail;
        }
        bResultTmp = m_pkNodes[i].m_iType == 2;
    }
    return bResultTmp;
}

struct ObjC4aa40 : FUN_00c450d0
{
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
    __forceinline ObjC4aa40()
    {
        vtbl = (intptr_t)&DAT_010c1eb4;
    }
};

struct OwnerC4aa40 : FUN_00c4aae0_class
{
    ObjC4aa40* FUN_00c4aa40(int a1);
};

// @fnv 0x00c4aa40
ObjC4aa40* OwnerC4aa40::FUN_00c4aa40(int a1)
{
    ObjC4aa40* p = new ObjC4aa40();
    this->FUN_00c4aae0((intptr_t)p, a1);
    return p;
}

extern unsigned int DAT_010c1fc4;

// BSDebrisNode : BSRangeNode. The range-node constructor is FUN_00c450d0;
// this derived constructor only replaces the vtable (0x10c1fc4).
struct BSDebrisNode : FUN_00c450d0
{
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
    BSDebrisNode()
    {
        vtbl = (intptr_t)&DAT_010c1fc4;
    }
};

// @fnv 0x00c4ae60
BSDebrisNode* __cdecl FUN_00c4ae60()
{
    return new BSDebrisNode;
}

extern int DAT_010c20d4;

struct S00c4af00_Obj : FUN_00c450d0
{
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
    S00c4af00_Obj() : FUN_00c450d0()
    {
        vtbl = (intptr_t)&DAT_010c20d4;
    }
};

struct S00c4af00_Cls
{
    S00c4af00_Obj* FUN_00c4af00(unsigned int arg);
};

// @fnv 0x00c4af00
S00c4af00_Obj* S00c4af00_Cls::FUN_00c4af00(unsigned int arg)
{
    S00c4af00_Obj* obj = new S00c4af00_Obj();
    reinterpret_cast<::FUN_00c4afa0_class *>((this))->FUN_00c4afa0((intptr_t)(obj), arg);
    return obj;
}

extern int DAT_010c20d4;

struct C4B0C0_Obj : FUN_00c450d0
{
    int u64;
    int u68;
    int u6C;
    int u70;
    int u74;
    int u78;
    int u7C;
    int u80;
    int u84;
    int u88;
    int u8C;
    int u90;
    int u94;
    int u98;
    int u9C;
    int uA0;
    int uA4;
    int uA8;
    int uAC;
    __forceinline C4B0C0_Obj()
    {
        vtbl = (intptr_t)&DAT_010c20d4;
    }
};

// @fnv 0x00c4b0c0
C4B0C0_Obj* FUN_00c4b0c0()
{
    return new C4B0C0_Obj;
}

// Same-TU body is visible, so /Ob1 tries to inline it and refuses.
// The four locals are the caller's unreferenced 16-byte hole; the call stays.
struct FUN_00546780_shell
{
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
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
    unsigned int flags30;
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
    FUN_00546780_shell** children;
    unsigned short unkA4;
    unsigned short count;

    void FUN_00546780(bool b)
    {
        int a = b ? 1 : 2;
        int c = a + 1;
        int d = c + 2;
        int e = d + 3;
        a = e + 4;
        c = a + 5;
        d = c + 6;
        e = d + 7;
        a = e + 8;
        c = a + 9;
        d = c + 10;
        e = d + 11;
        a = e + 12;
        c = a + 13;
        d = c + 14;
        e = d + 15;
        flags30 = a + c + d + e;
    }

    void SetFlag(bool b, unsigned int mask)
    {
        if (b)
            flags30 |= mask;
        else
            flags30 &= ~mask;
    }
};

inline bool KindOfShell(const NiRTTI& query, const NiRTTI* p)
{
    while (p)
    {
        if (p == &query)
            return true;
        p = p->m_pBaseRTTI;
    }
    return false;
}

inline FUN_00546780_shell* ChildAtShell(FUN_00546780_shell* node, unsigned int i)
{
    FUN_00546780_shell** slot = &node->children[i];
    return *slot;
}

// @fnv 0x00c4b220
void __cdecl FUN_00c4b220(FUN_00546780_shell* obj)
{
    if (obj != 0)
    {
        obj->FUN_00546780(true);
        obj->SetFlag(true, 0x2000);
    }
    FUN_00546780_shell* node;
    if (!obj)
        node = 0;
    else
        node = KindOfShell((*reinterpret_cast<::NiRTTI *>(&::g_011f4428)), obj->GetRTTI()) ? obj : 0;
    if (node)
    {
        for (unsigned int i = 0; i < node->count; ++i)
            FUN_00c4b220(ChildAtShell(node, i));
    }
}

extern const double DAT_01017cf8;

class BasisVector : public NiPoint3
{
  public:
    float SquaredLength() const;
    inline void FUN_004a0c10()
    {
        float squaredLength = SquaredLength();
        float length = FUN_004579e0(squaredLength);
        if (length > DAT_01017cf8)
        {
            float inverse = 1.0f / length;
            x *= inverse;
            y *= inverse;
            z *= inverse;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
    inline BasisVector Cross(const BasisVector& other) const
    {
        return BasisVector(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
    __forceinline BasisVector()
    {}
    __forceinline BasisVector(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};

class ThreeByThreeMatrix
{
  public:
    float m[3][3];
    __forceinline void SetCol(unsigned int col, const BasisVector& v)
    {
        m[0][col] = v.x;
        m[1][col] = v.y;
        m[2][col] = v.z;
    }
};

// @fnv 0x00c4b8a0
ThreeByThreeMatrix __cdecl FUN_00c4b8a0(NiPoint3 direction)
{
    BasisVector normal_2;
    static_cast<NiPoint3&>(normal_2) = direction;
    reinterpret_cast<::FUN_004a0c10_s *>(&(normal_2))->FUN_004a0c10();
    float ax = fabs(normal_2.x);
    float ayVal = fabs(normal_2.y);
    float normal7 = fabs(normal_2.z);
    BasisVector cross2;
    if (ax <= ayVal && ax <= normal7)
    {
        cross2 = BasisVector(0.0f, -normal_2.z, normal_2.y);
    }
    else if (ayVal <= ax && ayVal <= normal7)
    {
        cross2 = BasisVector(-normal_2.z, 0.0f, normal_2.x);
    }
    else
    {
        cross2 = BasisVector(-normal_2.y, normal_2.x, 0.0f);
    }
    reinterpret_cast<::FUN_004a0c10_s *>(&(cross2))->FUN_004a0c10();
    BasisVector crossTmp;
    crossTmp = cross2.Cross(normal_2);
    reinterpret_cast<::FUN_004a0c10_s *>(&(crossTmp))->FUN_004a0c10();
    cross2 = crossTmp.Cross(normal_2);
    reinterpret_cast<::FUN_004a0c10_s *>(&(cross2))->FUN_004a0c10();
    ThreeByThreeMatrix rotationB;
    rotationB.SetCol(0, cross2);
    rotationB.SetCol(1, crossTmp);
    rotationB.SetCol(2, normal_2);
    return rotationB;
}

struct RefQ
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
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

struct SPQ
{
    RefQ* m_pObject;
    SPQ(RefQ* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SPQ()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    SPQ& FUN_0066b0d0(RefQ* p);
};

inline void DeadQ4()
{
    int aiQ[4];
}

struct FUN_00c4ca80
{
    void* m_00;
    void* m_04;
    void* m_08;
    char pad0c[0x24 - 0x0c];
    void* m_24;
    void* m_28;
    SPQ m_sp2c;
    SPQ m_sp30;
    NiPoint3 m_pt34;
    FUN_00c4ca80();
};

// @fnv 0x00c4ca80
FUN_00c4ca80::FUN_00c4ca80()
{
    m_24 = 0;
    m_00 = 0;
    m_08 = 0;
    m_04 = 0;
    m_28 = 0;
    m_sp30.FUN_0066b0d0(0);
    m_sp2c.FUN_0066b0d0(0);
    m_pt34 = ::NiPoint3::ZERO;
    DeadQ4();
}

namespace fnv_00c4cba0 {
struct RefQ
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
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
struct SPQ
{
    RefQ* m_pObject;
    SPQ(RefQ* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SPQ()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    SPQ& FUN_0066b0d0(RefQ* p);
};
inline void DeadQ4()
{
    int aiQ[4];
}
struct OwnerQ
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* GetM8()
    {
        return m_08;
    }
};
struct FUN_00c4cba0
{
    OwnerQ* m_00;
    void* m_04;
    void* m_08;
    char pad0c[0x24 - 0x0c];
    void* m_24;
    void* m_28;
    SPQ m_sp2c;
    SPQ m_sp30;
    NiPoint3 m_pt34;
    FUN_00c4cba0(OwnerQ* p);
};
// @fnv 0x00c4cba0
FUN_00c4cba0::FUN_00c4cba0(OwnerQ* p)
{
    m_24 = p->GetM8();
    m_00 = p;
    m_08 = 0;
    m_04 = 0;
    m_28 = 0;
    m_sp30.FUN_0066b0d0(0);
    m_sp2c.FUN_0066b0d0(0);
    m_pt34 = ::NiPoint3::ZERO;
    reinterpret_cast<::FUN_00c4cdc0_cls *>(this)->FUN_00c4cdc0();
    DeadQ4();
}
}

// namespace fnv_00c4cba0

struct Obj
{
    virtual int V0(int a);
    virtual void V1();
    long rc;
};

struct Ref
{
    Obj* p;
    ~Ref()
    {
        if (p)
        {
            Obj* q = p;
            if (InterlockedDecrement(&q->rc) == 0)
                q->V1();
        }
    }
};

struct FUN_00c4ccd0
{
    Obj* m00;
    int u04, u08, u0c, u10, u14, u18, u1c, u20, u24;
    int m28;
    Ref r2c;
    Ref r30;
    ~FUN_00c4ccd0();
};

// @fnv 0x00c4ccd0
FUN_00c4ccd0::~FUN_00c4ccd0()
{
    if (m28 == 0)
    {
        Obj* o = m00;
        Obj* p = o;
        (void)(p ? p->V0(1) : 0);
    }
}

struct Point370
{
    float x, y, z;
    Point370()
    {}
    Point370* FUN_00416870(float, float, float);
    Point370(float a, float b, float c)
    {
        FUN_00416870(a, b, c);
    }
    Point370 FUN_0053d280(float scale) const
    {
        float inverse = 1.0f / scale;
        return Point370(x * inverse, y * inverse, z * inverse);
    }
    Point370 FUN_00439ef0(const Point370& other) const
    {
        return Point370(x - other.x, y - other.y, z - other.z);
    }
};

struct Points370
{
    unsigned int unk00;
    Point370* points;
    Point370& GetPoint(int index)
    {
        return points[index];
    }
    void SetPoint(int index, const Point370& point)
    {
        points[index] = point;
    }
};

struct Mesh370
{
    Points370* data;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int count;
    unsigned int unk28, unk2c, unk30;
    Point370 center;
    void FUN_00c4ce00();
};

// @fnv 0x00c4ce00
void Mesh370::FUN_00c4ce00()
{
    Point370 sum = (*reinterpret_cast<::Point370 *>((void *)&::NiPoint3::ZERO));
    for (int i = 0; i < count; ++i)
        reinterpret_cast<::FUN_0063c8a0_shell *>(&(sum))->FUN_0063c8a0((void *)&(data->points[i]));
    Point370 average = sum.FUN_0053d280((float)count);
    for (int j = 0; j < count; ++j)
    {
        data->SetPoint(j, (*(::Point370 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(data->GetPoint(j)))->FUN_00439ef0((::NiPoint3 *)&(average), *(const ::NiPoint3 *)nullptr))));
    }
    center = average;
}

inline long NiIncrement086(volatile long* value)
{
    long result = InterlockedIncrement(value);
    return result;
}

inline long NiDecrement086(volatile long* value)
{
    long result = InterlockedDecrement(value);
    return result;
}

struct NiAlloc086
{
    virtual void v00();
    virtual void* Allocate(unsigned int&, unsigned int&, int, bool, const char*, int, const char*);
};

struct NiMemManager086
{
    NiAlloc086* allocator;
};


struct FUN_00438690
{
    int* table;
    unsigned int* data;
    unsigned int size;
    unsigned int capacity;
    void FUN_006b3eb0(unsigned int, unsigned int);
    unsigned int FUN_007cad50();
    void Construct(unsigned int*, unsigned int);
    inline unsigned int FUN_007cb2e0(unsigned int* value)
    {
        unsigned int index = FUN_007cad50();
        Construct(&data[index], 1);
        data[index] = *value;
        return index;
    }
    __forceinline FUN_00438690()
    {
        table = &DAT_01016024;
        FUN_006b3eb0(0, 0);
    }
    __forceinline void Wrap(int& index)
    {
        volatile int divisor = size;
        if (divisor < 0)
            return;
        if (index < 0)
        {
            index = index % divisor + divisor;
            return;
        }
        else
            index = index % divisor;
    }
    __forceinline unsigned int GetSize() const
    {
        return size;
    }
    __forceinline const unsigned int& GetAt(unsigned int index)
    {
        return data[index];
    }
    __forceinline unsigned int& operator[](unsigned int index)
    {
        return data[index];
    }
    ~FUN_00438690();
};

// @fnv 0x00c5edc0
unsigned int C5EDC0_AnimExtra::AddAnimation(Animation* apAnim)
{
    unsigned int uiIndex;
    unsigned int ItemUpdateArray;
    unsigned int uiCapacity;
    return reinterpret_cast<::FUN_00438690 *>(&(m_kAnimations))->FUN_007cb2e0((unsigned int *)&(apAnim));
}

struct WrappedIndex086
{
    union
    {
        int value;
        unsigned int bits : 32;
    };
    __forceinline void Wrap(const FUN_00438690& array)
    {
        volatile int divisor = array.size;
        if (divisor < 0)
            return;
        if (value < 0)
        {
            value = (int)bits % divisor + divisor;
            return;
        }
        else
            value = (int)bits % divisor;
    }
};

struct Vertex086
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float coordinates[3];
    };
    inline bool operator==(const Vertex086& rhs) const
    {
        for (unsigned int i = 0; i < 3; i++)
            if (coordinates[i] != rhs.coordinates[i])
                return false;
        return true;
    }
    inline bool operator!=(const Vertex086& rhs) const
    {
        return !(reinterpret_cast<::NiPoint3 *>((void *)&(const ::Vertex086 &)(*this))->FUN_004390c0((const ::NiPoint3 &)(rhs)));
    }
};

struct Vertices086
{
    int table;
    Vertex086* data;
    unsigned int size;
    __forceinline unsigned int GetSize() const
    {
        return size;
    }
    __forceinline Vertex086& operator[](unsigned int index)
    {
        return data[index];
    }
};

__forceinline bool ShortEquals(const unsigned short& a, const unsigned int& b)
{
    return a == b;
}

struct Shorts086
{
    int* table;
    unsigned short* data;
    unsigned int size;
    unsigned int capacity;
    unsigned int GetNextPosition();
    void FUN_005ef650(unsigned short*, unsigned int);
    inline unsigned int Append(const unsigned short& value)
    {
        unsigned int index = GetNextPosition();
        FUN_005ef650(&data[index], 1);
        data[index] = value;
        return index;
    }
    __forceinline unsigned int Find(const unsigned int& value)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            if (data && ShortEquals(data[i], value))
                return i;
        }
        return -1;
    }
};

struct Alloc086
{
    void* FUN_00aa3e40(unsigned int);
};

extern "C" char DAT_011f6238;

struct NewShorts086 : Shorts086
{
    __forceinline NewShorts086()
    {
        table = &DAT_0106abe4;
        reinterpret_cast<::FUN_00692290_class *>(this)->FUN_00692290(0, 0);
    }
};

struct RefBase086
{
    virtual void v0();
    virtual void v1();
    int unk04;
    inline void AcquireReference()
    {
        NiIncrement086((volatile long*)&unk04);
    }
    inline void DecRef()
    {
        if (!NiDecrement086((volatile long*)&unk04))
            v1();
    }
};

struct FUN_00a5ecb0 : RefBase086
{
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
    virtual void v53();
    virtual void v54();
    virtual void Attach(void*, int);
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
    FUN_00a5ecb0(unsigned int);
    static inline void* operator new(std::size_t size)
    {
        if (size == 0)
            size = 1;
        unsigned int requested = size;
        unsigned int alignment = 4;
        return reinterpret_cast<NiMemManager086*>(DAT_011f6080)->allocator->Allocate(requested, alignment, 1, true, 0, -1, 0);
    }
    static void operator delete(void*);
};

struct Holder086
{
    FUN_00a5ecb0* value;
    inline Holder086& operator=(FUN_00a5ecb0* object)
    {
        if (value != object)
        {
            if (value)
                value->DecRef();
            value = object;
            if (value)
                value->AcquireReference();
        }
        return *this;
    }
    __forceinline operator FUN_00a5ecb0*() const
    {
        return value;
    }
    __forceinline FUN_00a5ecb0* operator->() const
    {
        return value;
    }
};

struct Triangulator086
{
    Vertices086* vertices;
    Shorts086* reflex;
    Shorts086* triangles;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int count;
    Holder086 node, mesh;
    void FUN_00c4cf80();
};

__forceinline void WrapIndex(int& index, const int& size)
{
    if (size < 0)
        return;
    if (index < 0)
    {
        index = index % size + size;
        return;
    }
    else
        index = index % size;
}

struct Point299
{
    float x, y, z;
    Point299(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Point299 operator-(const Point299& other) const
    {
        return Point299(x - other.x, y - other.y, z - other.z);
    }
};

struct PointArray299
{
    int unk00;
    Point299* data;
    Point299& GetAt(int index) const
    {
        return data[index];
    }
};

struct Owner299
{
    PointArray299* points;
    float FUN_00c4da80(int first, int second, int third);
};

// @fnv 0x00c4da80
float Owner299::FUN_00c4da80(int first, int second, int third)
{
    struct Pair
    {
        Point299 first;
        Point299 second;
    };
    Pair delta = {points->GetAt(second) - points->GetAt(first), points->GetAt(third) - points->GetAt(first)};
    return (float)fabs((float)((delta.first.x * delta.second.y - delta.first.y * delta.second.x) / 2.0));
}

struct S00c4db20_Pt
{
    float x, y, z;
};

struct FUN_006917d0_Arr
{
    int unk00, unk04, unk08, unk0c;
    FUN_006917d0_Arr();
};

struct S00c4db20_Child
{
    int unk00;
    S00c4db20_Pt* m_pPoints;
    S00c4db20_Pt& GetPt(int n)
    {
        return m_pPoints[n];
    }
};

struct S00c4db20_Self
{
    S00c4db20_Child* m_pChildObject;
    FUN_006917d0_Arr* m_pArr;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_iArrayLength;

    void FUN_00c4db20();
    void RemovePt(int n)
    {
        S00c4db20_Pt u;
        reinterpret_cast<::ArrW *>((m_pChildObject))->FUN_00c4e760(n, 1);
    }
};

// @fnv 0x00c4cdc0
void FUN_00c4cdc0_cls::FUN_00c4cdc0()
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    if (((double)(reinterpret_cast<::S_cls *>(this)->FUN_00c4d9d0())) >= ::_DAT_01012060)
    {
        reinterpret_cast<::S_00c4e900_Arr *>((m_pChildObject))->ReverseElements();
    }
    reinterpret_cast<::S00c4db20_Self *>(this)->FUN_00c4db20();
}

// @fnv 0x00c4db20
void S00c4db20_Self::FUN_00c4db20()
{
    if (m_pArr == 0)
    {
        m_pArr = new FUN_006917d0_Arr();
        bool removed3 = false;
        for (int iA = 0; iA < m_iArrayLength; iA++)
        {
            if (removed3)
            {
                iA--;
            }
            int prevA = (iA == 0) ? (m_iArrayLength - 1) : (iA - 1);
            int next = (iA + 1) % m_iArrayLength;
            int res3 =
                reinterpret_cast<::S_00c4dcf0 *>(this)->GetPointSide((*(float *)&(const ::S00c4db20_Pt &)(m_pChildObject->GetPt(iA))), (*(float *)&(const ::S00c4db20_Pt &)(m_pChildObject->GetPt(prevA))), (*(float *)&(const ::S00c4db20_Pt &)(m_pChildObject->GetPt(next))), {}, {}, {}, {}, {}, {});
            removed3 = false;
            if (res3 == -1)
            {
                reinterpret_cast<::FUN_00691820_arr *>((m_pArr))->Append((const unsigned short *)&(const unsigned short &)((unsigned short)iA));
            }
            else if (res3 == 0)
            {
                RemovePt(iA);
                m_iArrayLength--;
                removed3 = true;
            }
        }
    }
}

// Reconstruction of 0x00c4e1e0

struct MMgr
{
    void* Allocate(unsigned int);
};

extern "C" char DAT_011f6238;

inline void* NiAlloc(unsigned int n)
{
    return reinterpret_cast<::MemoryManagerStandIn *>((((MMgr*)&DAT_011f6238)))->FUN_00aa3e40(n);
}

struct NP3
{
    float x, y, z;
    NP3()
    {}
    NP3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};

struct NP2
{
    float x, y;
    NP2()
    {}
    NP2(float a, float b)
    {
        x = a;
        y = b;
    }
};

struct NC4
{
    float r, g, b, a;
    NC4() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}
    NC4(float q, float w, float e, float t)
    {
        r = q;
        g = w;
        b = e;
        a = t;
    }
};

inline NP3* At3(NP3* p, int i)
{
    return p + i;
}

inline unsigned short* At2(unsigned short* p, int i)
{
    return p + i;
}

inline void CopyMem(void* dest, const void* src, unsigned int size)
{
    memmove(dest, src, size);
}

struct P3Arr
{
    int unk0;
    NP3* p;
};

struct ShArr
{
    int unk0;
    unsigned short* p;
};

struct TESObjectDoorController
{
    char pad[0x58];
    TESObjectDoorController(unsigned short a1, NP3* a2, NP3* a3, NC4* a4, NP2* a5, int a6, int a7, unsigned short a8,
                            void* a9);
};

struct C4E1E0
{
    P3Arr* m0;
    int m4;
    ShArr* m8;
    NP3* m0c;
    unsigned char* m10;
    NP3* m14;
    NP2* m18;
    NC4* m1c;
    int m20;
    int m24;
    int m28;
    TESObjectDoorController* FUN_00c4e1e0();
};

// @fnv 0x00c4e1e0
TESObjectDoorController* C4E1E0::FUN_00c4e1e0()
{
    m0c = new NP3[m24];
    m14 = new NP3[m24];
    m18 = new NP2[m24];
    m1c = new NC4[m24];
    m10 = (unsigned char*)NiMalloc(m28 * 3 * 2);
    CopyMem(m0c, At3(m0->p, 0), m24 * 12);
    CopyMem(m10, At2(m8->p, 0), m28 * 6);
    for (int i = 0; i < m24; i++)
    {
        m14[i] = NP3(0.0f, 0.0f, 1.0f);
    }
    float fDiv = 100.0f;
    for (int j = 0; j < m24; j++)
    {
        m18[j] = NP2(m0c[j].x / fDiv, m0c[j].y / fDiv);
    }
    for (int k = 0; k < m24; k++)
    {
        m1c[k] = NC4(1.0f, 1.0f, 1.0f, 1.0f);
    }
    TESObjectDoorController* pCtrl =
        new TESObjectDoorController((unsigned short)m24, m0c, m14, m1c, m18, 1, 0, (unsigned short)m28, m10);
    return pCtrl;
}

struct Q4E9
{
    virtual void v0();
    virtual int* Allocate(unsigned n);
    virtual void Free(int* p);
    int* m_data;
    unsigned m_iElementCount;
    unsigned m_alloc;
    inline bool ShouldShrink()
    {
        if (m_alloc > 0x400)
        {
            if (m_iElementCount <= m_alloc - 0x800)
                return true;
        }
        else
        {
            if (m_iElementCount <= m_alloc >> 2)
                return true;
        }
        return false;
    }
    inline unsigned GetShrinkSize()
    {
        return m_alloc > 0x800 ? m_alloc - 0x400 : m_alloc >> 1;
    }
    inline void DestructItemsA(int* p, unsigned n)
    {
        int pad[1];
        unsigned uiIdx;
        int pad2[2];
        for (uiIdx = 0; uiIdx < n; uiIdx++)
        {
        }
    }
    inline void DestructItems(int* p, unsigned n)
    {
        int pad[2];
        unsigned uiIdx;
        int pad2[1];
        for (uiIdx = 0; uiIdx < n; uiIdx++)
        {
        }
    }
    void FUN_00c4e9b0(unsigned idx, bool resize);
};

// @fnv 0x00c4e9b0
void Q4E9::FUN_00c4e9b0(unsigned idx, bool resize)
{
    if (resize && ShouldShrink())
    {
        unsigned newSize = GetShrinkSize();
        int* newData2 = Allocate(newSize);
        reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(newData2), (char *)(m_data), idx);
        DestructItemsA(m_data + idx, 1);
        reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(int *)(newData2 + idx), (char *)(int *)(m_data + idx + 1), m_iElementCount - 1);
        Free(m_data);
        m_data = 0;
        m_data = newData2;
        m_alloc = newSize;
    }
    else
    {
        DestructItems(m_data + idx, 1);
        reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(int *)(m_data + idx), (char *)(int *)(m_data + idx + 1), m_iElementCount - idx - 1);
    }
    m_iElementCount--;
}

struct Q4E
{
    virtual void v0();
    virtual short* Allocate(unsigned n);
    virtual void Free(short* p);
    short* m_data;
    unsigned m_iElementCount;
    unsigned m_alloc;
    inline bool ShouldShrink()
    {
        if (m_alloc > 0x400)
        {
            if (m_iElementCount <= m_alloc - 0x800)
                return true;
        }
        else
        {
            if (m_iElementCount <= m_alloc >> 2)
                return true;
        }
        return false;
    }
    inline unsigned GetShrinkSize()
    {
        return m_alloc > 0x800 ? m_alloc - 0x400 : m_alloc >> 1;
    }
    inline void DestructItemsA(short* p, unsigned n)
    {
        int pad[1];
        unsigned uiIdx;
        int pad2[2];
        for (uiIdx = 0; uiIdx < n; uiIdx++)
        {
        }
    }
    inline void DestructItems(short* p, unsigned n)
    {
        int pad[2];
        unsigned uiIdx;
        int pad2[1];
        for (uiIdx = 0; uiIdx < n; uiIdx++)
        {
        }
    }
    void FUN_00c4eb50(unsigned idx, bool resize);
};

// @fnv 0x00c4cf80
void Triangulator086::FUN_00c4cf80()
{
    FUN_00438690 remainingVal;
    unsigned int currentItem;
    Vertex086 point21, first;
    unsigned int i1;
    WrappedIndex086 indexC_, previous4, old44, before8, after4;
    unsigned int foundPos8;
    int direction5, dir5;
    unsigned int total3;
    for (i1 = 0; i1 < vertices->GetSize(); i1++)
        remainingVal.FUN_007cb2e0(&i1);
    currentItem = 2;
    point21 = (*vertices)[currentItem];
    first = (*vertices)[0];
    while (point21 != first && remainingVal.GetSize() > 3)
    {
        indexC_.value = currentItem - 2;
        previous4.value = currentItem - 1;
        indexC_.Wrap(remainingVal);
        previous4.Wrap(remainingVal);
        if (reinterpret_cast<::S_00c4dd60_Owner *>(this)->IsKeyValid(remainingVal[previous4.value], remainingVal[indexC_.value], remainingVal[currentItem]))
        {
            if (!triangles)
                triangles = new NewShorts086;
            reinterpret_cast<::FUN_00691820_arr *>((triangles))->Append((const unsigned short *)&(const unsigned short &)((unsigned short)remainingVal.GetAt(currentItem)));
            reinterpret_cast<::FUN_00691820_arr *>((triangles))->Append((const unsigned short *)&(const unsigned short &)((unsigned short)remainingVal.GetAt(previous4.value)));
            reinterpret_cast<::FUN_00691820_arr *>((triangles))->Append((const unsigned short *)&(const unsigned short &)((unsigned short)remainingVal.GetAt(indexC_.value)));
            count++;
            currentItem--;
            reinterpret_cast<::Q4E9 *>(&(remainingVal))->FUN_00c4e9b0(currentItem, 1);
            if (reflex)
            {
                before8.value = currentItem - 1;
                after4.value = currentItem + 1;
                before8.Wrap(remainingVal);
                after4.Wrap(remainingVal);
                foundPos8 = reflex->Find(remainingVal[currentItem]);
                if (foundPos8 != -1)
                {
                    direction5 =
                        reinterpret_cast<::S_00c4dcf0 *>(this)->GetPointSide((*(float *)&(const ::Vertex086 &)((*vertices)[remainingVal[currentItem]])), (*(float *)&(const ::Vertex086 &)((*vertices)[remainingVal[before8.value]])),
                                     (*(float *)&(const ::Vertex086 &)((*vertices)[remainingVal[after4.value]])), {}, {}, {}, {}, {}, {});
                    if (direction5 == 1)
                        reinterpret_cast<::Q4E *>((reflex))->FUN_00c4eb50(foundPos8, 1);
                }
                before8.value = currentItem - 1;
                after4.value = currentItem - 2;
                before8.Wrap(remainingVal);
                after4.Wrap(remainingVal);
                foundPos8 = reflex->Find(remainingVal[before8.value]);
                if (foundPos8 != -1)
                {
                    dir5 =
                        reinterpret_cast<::S_00c4dcf0 *>(this)->GetPointSide((*(float *)&(const ::Vertex086 &)((*vertices)[remainingVal[before8.value]])), (*(float *)&(const ::Vertex086 &)((*vertices)[remainingVal[after4.value]])),
                                     (*(float *)&(const ::Vertex086 &)((*vertices)[remainingVal[currentItem]])), {}, {}, {}, {}, {}, {});
                    if (dir5 == 1)
                        reinterpret_cast<::Q4E *>((reflex))->FUN_00c4eb50(foundPos8, 1);
                }
            }
            old44.value = currentItem - 1;
            old44.Wrap(remainingVal);
            if (remainingVal.GetAt(old44.value) == 0)
            {
                currentItem++;
                point21 = (*vertices)[remainingVal[currentItem % remainingVal.GetSize()]];
            }
        }
        else
        {
            currentItem++;
            point21 = (*vertices)[remainingVal[currentItem % remainingVal.GetSize()]];
        }
    }
    if (triangles && remainingVal.GetSize() == 3)
    {
        reinterpret_cast<::FUN_00691820_arr *>((triangles))->Append((const unsigned short *)&(const unsigned short &)((unsigned short)remainingVal.GetAt(2)));
        reinterpret_cast<::FUN_00691820_arr *>((triangles))->Append((const unsigned short *)&(const unsigned short &)((unsigned short)remainingVal.GetAt(1)));
        reinterpret_cast<::FUN_00691820_arr *>((triangles))->Append((const unsigned short *)&(const unsigned short &)((unsigned short)remainingVal.GetAt(0)));
        count++;
    }
    if (count > 0)
    {
        total3 = ((uintptr_t)(reinterpret_cast<::C4E1E0 *>(this)->FUN_00c4e1e0()));
        mesh = (FUN_00a5ecb0*)((void *)(reinterpret_cast<::fnv_00c4e160::FUN_00c4e160_Class *>(this)->CreateInstance(total3)));
        node = new FUN_00a5ecb0(0);
        node->Attach(mesh, 1);
        if (mesh)
        {
            unk0c = 0;
            unk14 = 0;
            unk18 = 0;
            unk1c = 0;
            unk10 = 0;
        }
    }
}

// @fnv 0x00c4eb50
void Q4E::FUN_00c4eb50(unsigned idx, bool resize)
{
    if (resize && ShouldShrink())
    {
        unsigned newSize = GetShrinkSize();
        short* newData2 = Allocate(newSize);
        reinterpret_cast<::FUN_005efdd0_class *>(this)->FUN_005efdd0((char *)(newData2), (char *)(m_data), idx);
        DestructItemsA(m_data + idx, 1);
        reinterpret_cast<::FUN_005efdd0_class *>(this)->FUN_005efdd0((char *)(short *)(newData2 + idx), (char *)(short *)(m_data + idx + 1), m_iElementCount - 1);
        Free(m_data);
        m_data = 0;
        m_data = newData2;
        m_alloc = newSize;
    }
    else
    {
        DestructItems(m_data + idx, 1);
        reinterpret_cast<::FUN_005efdd0_class *>(this)->FUN_005efdd0((char *)(short *)(m_data + idx), (char *)(short *)(m_data + idx + 1), m_iElementCount - idx - 1);
    }
    m_iElementCount--;
}

class QueryTarget
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void Unk_28();
};

class QueryOwner
{
  public:
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
    QueryTarget* m_pkTarget;
    QueryTarget* GetTarget()
    {
        return m_pkTarget;
    }
    void FUN_00c4f360();
};

// @fnv 0x00c4f360
void QueryOwner::FUN_00c4f360()
{
    GetTarget()->Unk_28();
}

struct FUN_00c504e0_pool
{
};

struct FUN_00c504e0_mgr
{
};

struct FUN_00c504e0_task
{
// @fnv 0x00c504e0
    ~FUN_00c504e0_task()
    {}
};

struct ScopeBase_c5
{
    virtual ~ScopeBase_c5();
};

struct FUN_00c504e0 : ScopeBase_c5
{
    virtual ~FUN_00c504e0();
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
    void* m_ac;
    int m_b0;
    FUN_00c504e0_task* m_b4;
};

// @fnv 0x00c51590
FUN_00c51590_cls* FUN_00c51590_cls::FUN_00c51590(unsigned int acFlags)
{
    reinterpret_cast<::FUN_00c504e0 *>(this)->FUN_00c504e0::~FUN_00c504e0();
    if (acFlags & 1) {
        FUN_00aa1460(this, 0xb8);
    }
    return this;
}

FUN_00c504e0::~FUN_00c504e0()
{
    void* old = m_ac;
    reinterpret_cast<::FNV_MemoryManager *>((((FUN_00c504e0_pool*)&DAT_011f6238)))->FUN_00aa4060(old);
    m_ac = 0;
    m_b0 = 0;
    reinterpret_cast<::B00C20Pool *>((((::FUN_00c504e0_mgr *)&(::GetTaskletManager()))))->ReleaseItem((*(::B00C20Item * *)(m_b4)));
    delete m_b4;
}

struct C50Type
{
    const char* field_00;
    C50Type* field_04;
};

struct C50Object
{
    virtual void slot_00();
    virtual void slot_04();
    virtual C50Type* slot_08();
    virtual C50Object* slot_0c();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1c();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2c();
    virtual C50Object* slot_30();
    inline bool GetParentWorldSpace()
    {
        return field_c4;
    }
    inline const char* GetName()
    {
        return field_08;
    }
    inline C50Object* GetModifiers()
    {
        C50Object* head = field_0c;
        return head;
    }
    inline C50Object* GetNext()
    {
        C50Object* next = field_30;
        return next;
    }
    inline void* GetRoot()
    {
        return field_5c;
    }
    unsigned field_04;
    const char* field_08;
    C50Object* field_0c;
    unsigned field_10;
    unsigned field_14;
    unsigned field_18;
    unsigned field_1c;
    unsigned field_20;
    unsigned field_24;
    unsigned field_28;
    unsigned field_2c;
    C50Object* field_30;
    unsigned field_34;
    unsigned field_38;
    C50Object* field_3c;
    unsigned field_40;
    unsigned field_44;
    unsigned field_48;
    unsigned field_4c;
    unsigned field_50;
    unsigned field_54;
    unsigned field_58;
    void* field_5c;
    unsigned field_60;
    unsigned field_64;
    unsigned field_68;
    unsigned field_6c;
    unsigned field_70;
    unsigned field_74;
    unsigned field_78;
    unsigned field_7c;
    unsigned field_80;
    unsigned field_84;
    unsigned field_88;
    unsigned field_8c;
    unsigned field_90;
    unsigned field_94;
    unsigned field_98;
    unsigned field_9c;
    C50Object** field_a0;
    unsigned short field_a4, field_a6;
    unsigned field_a8;
    unsigned field_ac;
    unsigned field_b0;
    unsigned field_b4;
    unsigned field_b8;
    unsigned field_bc;
    unsigned field_c0;
    bool field_c4;
};

extern char DAT_010c2678[], DAT_010c2628[], DAT_010c25d8[];

inline bool C50Exact(C50Object* object, const void* type)
{
    if (!object)
        return false;
    return object->slot_08() == type;
}

inline bool C50Kind(C50Object* object)
{
    C50Type* type = object->slot_08();
    while (type)
    {
        if (type == &(*reinterpret_cast<::C50Type *>(&::g_012027d8)))
            return true;
        type = type->field_04;
    }
    return false;
}

inline bool C50IsKind(C50Object* object)
{
    if (!object)
        return false;
    return C50Kind(object);
}

struct C50ChildLookup
{
    C50Object* value;
    C50Object** entry;
};

inline C50Object* C50ChildAt(C50Object* node, unsigned int index)
{
    C50ChildLookup lookup;
    lookup.entry = &node->field_a0[index];
    lookup.value = *lookup.entry;
    return lookup.value;
}

// @fnv 0x00c50f90
bool __cdecl FUN_00c50f90(C50Object* object, void* material)
{
    if (!object)
        return false;
    if (object->slot_30())
    {
        if (C50Exact(object, &(*reinterpret_cast<const ::NiRTTI *>(&::g_012024e0))))
        {
            C50Object* system = object;
            if (!system->GetParentWorldSpace())
            {
                ::FUN_005b5e40();
                return false;
            }
            C50Object* modifier = system->GetModifiers();
            while (modifier)
            {
                if (C50Exact(modifier, &(*reinterpret_cast<const ::NiRTTI *>(&::g_01203340))))
                {
                    C50Object* emitter = modifier;
                    C50Object* target7 = emitter->field_3c;
                    if (material)
                    {
                        if (emitter->GetRoot() != material)
                        {
                            ::FUN_005b5e40();
                            return false;
                        }
                    }
                    if (C50IsKind(target7))
                        return true;
                    return false;
                }
                else
                {
                    modifier = modifier->GetNext();
                }
            }
        }
        ::FUN_005b5e40();
        return false;
    }
    else
    {
        C50Object* node = object ? object->slot_0c() : 0;
        if (node)
        {
            unsigned int count = node->field_a6;
            for (unsigned int index = 0; index < count; ++index)
            {
                C50Object* child = C50ChildAt(node, index);
                if (child && !FUN_00c50f90(child, material))
                    return false;
            }
        }
    }
    return true;
}

namespace fnv_00c517b0 {
class NiFixedString;
struct NiVisibleArray;

extern char* DAT_0109b220;


inline unsigned int NiAtomicIncrement(unsigned int& uiValue)
{
    return InterlockedIncrement((long*)&uiValue);
}
inline unsigned int NiAtomicSubtract(unsigned int& uiValue)
{
    return InterlockedDecrement((long*)&uiValue);
}

static __forceinline void fnvDead4()
{
    int aiDead[4];
}

class NiGlobalStringTable
{
  public:
    static char* GetRealBufferStart(char* const& kHandle)
    {
        return kHandle - 2 * sizeof(unsigned int);
    }
    static void DecRefCount(char*& kHandle);
    static __forceinline void DecRefCountI(char*& kHandle)
    {
        if (kHandle == DAT_0109b220)
            return;
        __assume(kHandle != 0);
        unsigned int* pkMem = (unsigned int*)GetRealBufferStart(kHandle);
        __assume(pkMem != 0);
        NiAtomicSubtract(pkMem[0]);
        fnvDead4();
    }
};

class NiFixedString
{
  public:
    NiFixedString(const char* pcString)
    {
        if (pcString == 0)
            m_kHandle = DAT_0109b220;
        else
            m_kHandle = ::NiGlobalStringTable::AddString(pcString);
    }
    ~NiFixedString()
    {
        ::FUN_004381d0((void *)&(m_kHandle));
    }
    char* m_kHandle;
};

class NiFixedStringI
{
  public:
    NiFixedStringI(const char* pcString)
    {
        if (pcString == 0)
            m_kHandle = DAT_0109b220;
        else
            m_kHandle = ::NiGlobalStringTable::AddString(pcString);
    }
    ~NiFixedStringI()
    {
        NiGlobalStringTable::DecRefCountI(m_kHandle);
    }
    char* m_kHandle;
};

template <class T> class NiRect
{
  public:
    NiRect(T left = 0, T right = 0, T top = 0, T bottom = 0)
    {
        m_fMinimumU = left;
        m_fMaximumU = right;
        m_fMinimumV = top;
        m_fMaximumV = bottom;
    }
    T m_fMinimumU;
    T m_fMaximumU;
    T m_fMinimumV;
    T m_fMaximumV;
};

class ThreeByThreeMatrix
{
  public:
    ThreeByThreeMatrix()
    {}
    void SetRow(unsigned int uiRow, float f0, float f1, float f2)
    {
        m_afEntries[uiRow][0] = f0;
        m_afEntries[uiRow][1] = f1;
        m_afEntries[uiRow][2] = f2;
    }
    float m_afEntries[3][3];
};

class Setting_01017720_011f96a0
{
  public:
    float& GetFloat()
    {
        return this ? m_fValue : ((*reinterpret_cast<float *>(&::DAT_01202800)) = 0.0f, (*reinterpret_cast<float *>(&::DAT_01202800)));
    }
    void* m_pVtbl;
    float m_fValue;
};

class NiRefObjectStandIn : public NiMemObject
{
  public:
    virtual ~NiRefObjectStandIn();
    virtual void DeleteThis();
    void IncRefCount()
    {
        NiAtomicIncrement(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (NiAtomicSubtract(m_uiRefCount) == 0)
            DeleteThis();
    }
    void AssignFixedString(const NiFixedString& kName);
    void AssignFixedString(const NiFixedStringI& kName);
    unsigned int m_uiRefCount;
};

class FUN_00a5ecb0;

class NiAVObjectStandIn : public NiRefObjectStandIn
{
  public:
    float FUN_00c52450();
    void FUN_00c52020(float fValue, int iArg1, int iArg2, int iArg3);
    void FUN_00c51f20();
    void SetLocalRotation(const ThreeByThreeMatrix& kRot)
    {
        m_kRotate = kRot;
    }
    void SetBit(bool bVal, unsigned int uMask)
    {
        if (bVal)
            m_uiObjectFlags |= uMask;
        else
            m_uiObjectFlags &= ~uMask;
    }
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
    unsigned int m_uiObjectFlags;
    ThreeByThreeMatrix m_kRotate;
};

class FUN_00a712f0 : public NiAVObjectStandIn
{
  public:
    FUN_00a712f0();
    void SetMinNearPlaneDist(float fDist)
    {
        m_fMinNearPlaneDist = fDist;
    }
    void SetMaxFarNearRatio(float fRatio)
    {
        m_fMaxFarNearRatio = fRatio;
    }
    void SetViewPort(const NiRect<float>& kPort)
    {
        m_kPort = kPort;
    }
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
    float m_fMinNearPlaneDist;
    float m_fMaxFarNearRatio;
    NiRect<float> m_kPort;
    float m_fTrailingValue;
};

class FUN_00a5ecb0 : public NiAVObjectStandIn
{
  public:
    FUN_00a5ecb0(unsigned int uiChildCount);
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
};

class FUN_004a0eb0
{
  public:
    FUN_004a0eb0(NiVisibleArray* pkArray);
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
};

class CamPointer
{
  public:
    CamPointer(FUN_00a712f0* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~CamPointer();
    CamPointer& operator=(FUN_00a712f0* object);
    FUN_00a712f0* operator->() const
    {
        return m_pObject;
    }
    FUN_00a712f0* m_pObject;
};

class FUN_00c517b0 : public FUN_00a5ecb0
{
  public:
    FUN_00c517b0(const char* pcName, bool bFlag, FUN_00a712f0* pkCamera);
    virtual ~FUN_00c517b0();
    CamPointer m_spCamera;
    int unkB0;
    FUN_004a0eb0* m_pkVisible;
    bool m_bFlag;
};

// @fnv 0x00c517b0
FUN_00c517b0::FUN_00c517b0(const char* pcName, bool bFlag, FUN_00a712f0* pkCamera) : FUN_00a5ecb0(0)
{
    m_bFlag = bFlag;
    m_pkVisible = new FUN_004a0eb0(0);
    unkB0 = 0;

    char acName[512];
    ::FUN_00406d00(acName, 512, "%sRoot Node", pcName);
    ::AssignFixedString((char *)this, (intptr_t)&(const ::fnv_00c517b0::NiFixedStringI &)(NiFixedStringI(acName)), {});

    FUN_00a5ecb0* pkCameraNode = new FUN_00a5ecb0(0);
    ::FUN_00406d00(acName, 512, "%sRoot CameraNode", pcName);
    ::AssignFixedString((char *)(pkCameraNode), (intptr_t)&(const ::fnv_00c517b0::NiFixedString &)(NiFixedString(acName)), {});
    reinterpret_cast<::fnv_00a5ed10::ChildNode *>(this)->FUN_00a5ed10((::fnv_00a5ed10::ChildObj *)(pkCameraNode), true);

    if (pkCamera)
    {
        m_spCamera = pkCamera;
    }
    else
    {
        m_spCamera = new FUN_00a712f0;
        ::FUN_00406d00(acName, 512, "%sRoot Camera", pcName);
        ::AssignFixedString((char *)((m_spCamera).operator->()), (intptr_t)&(const ::fnv_00c517b0::NiFixedString &)(NiFixedString(acName)), {});
        NiRect<float> kPort(0.0f, 1.0f, 1.0f, 0.0f);
        m_spCamera->SetViewPort(kPort);
        ThreeByThreeMatrix kRot2;
        kRot2.SetRow(0, 0.0f, 0.0f, 1.0f);
        kRot2.SetRow(1, 1.0f, 0.0f, 0.0f);
        kRot2.SetRow(2, 0.0f, 1.0f, 0.0f);
        m_spCamera->SetLocalRotation(kRot2);
        m_spCamera->SetMinNearPlaneDist(1.0f);
        m_spCamera->SetMaxFarNearRatio(FUN_00c52450() / (*reinterpret_cast<::fnv_00c517b0::Setting_01017720_011f96a0 *>(&::g_01203144)).GetFloat());
        FUN_00c52020((*reinterpret_cast<::fnv_00c517b0::Setting_01017720_011f96a0 *>(&::g_01203150)).GetFloat(), 1, 0, 0);
        fnvDead4();
    }
    FUN_00c51f20();
    reinterpret_cast<::FUN_00546780_shell *>(this)->FUN_00546780(true);
    SetBit(true, 0x2000);
}
}

// namespace fnv_00c517b0

struct BaseForC51df0
{
    virtual ~BaseForC51df0();
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
};

inline long NiAtomicIncrementC51(long& lValue)
{
    return InterlockedIncrement(&lValue);
}

inline long NiAtomicDecrementC51(long& lValue)
{
    return InterlockedDecrement(&lValue);
}

class RefObjectC51
{
  public:
    virtual ~RefObjectC51();
    virtual void DeleteThis();
    void IncRefCount()
    {
        NiAtomicIncrementC51(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (NiAtomicDecrementC51(m_uiRefCount) == 0)
            DeleteThis();
    }
    long m_uiRefCount;
};

template <class T> class NiPointerC51
{
  public:
    ~NiPointerC51()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerC51& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

struct OwnedA
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual ~OwnedA();
};

extern MemoryManager g_011f6238;

struct OwnedB
{
    void* data;
    ~OwnedB()
    {
        NiFree(data);
    }
};

struct FUN_00c51df0 : BaseForC51df0
{
    NiPointerC51<RefObjectC51> m_spNode;
    OwnedB* m_pUserData;
    OwnedA* m_pkOwned;
    virtual ~FUN_00c51df0();
};

// @fnv 0x00c52830
void* FUN_00c52830_class::FUN_00c52830(unsigned int flags)
{
    reinterpret_cast<::FUN_00c51df0 *>((reinterpret_cast<FUN_00878690_shell*>(this)))->FUN_00c51df0::~FUN_00c51df0();
    if (flags & 1)
        operator delete(this, 0xc0);
    return this;
}

// @fnv 0x00c51df0
FUN_00c51df0::~FUN_00c51df0()
{
    m_spNode = 0;
    delete m_pkOwned;
    delete m_pUserData;
}

namespace fn_00c51f20 {

struct ParamBlock
{
    float fValue;
    unsigned char ucFlag0;
    unsigned char ucFlag1;
    unsigned char ucFlag2;
    unsigned char ucFlag3;
    unsigned char ucFlag4;
};

struct Target
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* pKey;
};

struct Child
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00C();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01C();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02C();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03C();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04C();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05C();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06C();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07C();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08C();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09C();
    virtual void vfn_0A0();
    virtual void vfn_0A4();
    virtual void vfn_0A8();
    virtual void vfn_0AC();
    virtual void vfn_0B0();
    virtual void vfn_0B4();
    virtual void vfn_0B8();
    virtual void vfn_0BC();
    virtual void vfn_0C0();
    virtual void vfn_0C4();
    virtual void vfn_0C8();
    virtual void vfn_0CC();
    virtual void vfn_0D0();
    virtual void vfn_0D4();
    virtual void vfn_0D8();
    virtual void vfn_0DC(Target* target, int flag);
};

struct Owner
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
    void* pChildrenVtbl;
    Child** m_ppObjects;
    unsigned short m_usMaxChildren;
    unsigned short m_usChildren;
    unsigned int unkA8;
    Target* pTarget;
    Child*& GetChildRef(unsigned int i)
    {
        return m_ppObjects[i];
    }
    Target* GetTarget()
    {
        return pTarget;
    }
    Child* GetFirstChild()
    {
        return GetChild(0);
    }
    void* GetKey()
    {
        return GetTarget()->pKey;
    }
    Child* GetChild(unsigned int i)
    {
        if (i >= m_usChildren)
        {
            return 0;
        }
        else
        {
            Child*& ref = GetChildRef(i);
            Child* pkChild = ref;
            return pkChild;
        }
    }
    void FUN_00c51f20();
};

// @fnv 0x00c51f20
void Owner::FUN_00c51f20()
{
    if (GetKey() != GetChild(0))
    {
        GetFirstChild()->vfn_0DC(GetTarget(), 1);
        ParamBlock block;
        block.fValue = 0.0f;
        block.ucFlag0 = 0;
        block.ucFlag1 = 0;
        block.ucFlag2 = 0;
        block.ucFlag3 = 0;
        block.ucFlag4 = 0;
        reinterpret_cast<::FUN_00a59c60_cls *>((GetTarget()))->FUN_00a59c60((std::intptr_t)(&block));
    }
}

}

// @fnv 0x00c509a0
void FUN_00c509a0_Class::FUN_00c509a0(int a)
{
    int local1;
    int local2;
    int local3;
    void* p = ((void *)(reinterpret_cast<::FUN_00c50f30_class *>((this))->GetEntryValue(a)));

    if (p != 0) {
        reinterpret_cast<::Owner *>((this))->FUN_00c51700((intptr_t)(p));
    } else {
        ::FUN_005b5e40();
    }
}

namespace fnv_00c52450 {
extern float DAT_01203130;
extern float DAT_0120313c;
extern float DAT_01203124;

// Inlined under /Ob1. Argument order keeps (max-min) on the x87 stack under the
// normalized percent, so the addend is the right operand and becomes faddp.
inline float MapNoLODFar(float value, float inMin, float inMax, float outMin, float outMax)
{
    return ((value - inMin) / (inMax - inMin)) * (outMax - outMin) + outMin;
}

class FUN_00c52450_cls
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
    unsigned char unkB8;
    float FUN_00c52450();
};

// @fnv 0x00c52450
float FUN_00c52450_cls::FUN_00c52450()
{
    float result5;
    float a;
    float b;
    float* pA3;
    float* pB6;
    float* pC;
    if (unkB8 != 0)
    {
        result5 = ::DAT_01083c64;
    }
    else
    {
        pA3 = (&(*reinterpret_cast<float *>(&::g_0120312c)) != 0) ? &DAT_01203130 : ((*reinterpret_cast<float *>(&::DAT_01202800)) = 0.0f, &(*reinterpret_cast<float *>(&::DAT_01202800)));
        a = *pA3;
        pB6 = (&(*reinterpret_cast<float *>(&::g_01203138)) != 0) ? &DAT_0120313c : ((*reinterpret_cast<float *>(&::DAT_01202800)) = 0.0f, &(*reinterpret_cast<float *>(&::DAT_01202800)));
        pC = (&(*reinterpret_cast<float *>(&::g_01203120)) != 0) ? &DAT_01203124 : ((*reinterpret_cast<float *>(&::DAT_01202800)) = 0.0f, &(*reinterpret_cast<float *>(&::DAT_01202800)));
        b = *pC;
        result5 = MapNoLODFar(*pB6, 0.0f, 1.0f, b, a);
    }
    return result5;
}
}

// namespace fnv_00c52450

namespace fnv_00c52590 {
union SettingValue189
{
    bool boolean;
    int integer;
};
struct Setting189
{
    void* vtable;
    SettingValue189 value;
    const char* name;
    inline const bool& GetBool() const
    {
        const bool* selected = this ? &value.boolean : ((*reinterpret_cast<::fnv_00c52590::SettingValue189 *>(&::DAT_01202800)).boolean = false, &(*reinterpret_cast<::fnv_00c52590::SettingValue189 *>(&::DAT_01202800)).boolean);
        return *selected;
    }
    inline const int& GetInt() const
    {
        const int* selected = this ? &value.integer : ((*reinterpret_cast<::fnv_00c52590::SettingValue189 *>(&::DAT_01202800)).integer = 0, &(*reinterpret_cast<::fnv_00c52590::SettingValue189 *>(&::DAT_01202800)).integer);
        return *selected;
    }
};
struct Frustum189
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool orthographic;
};
struct Camera189
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    Frustum189 frustum;
};
struct DistanceController189
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
    virtual float GetFarPlane();
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    Camera189* camera;
    inline Camera189* GetCamera() const
    {
        Camera189* result = camera;
        return result;
    }
    void FUN_00c52590(float deltaTime);
};
// @fnv 0x00c52590
void DistanceController189::FUN_00c52590(float deltaTime)
{
    if ((*reinterpret_cast<::fnv_00c52590::Setting189 *>(&::g_01203188)).GetBool())
    {
        static float previous = GetFarPlane();
        float blend_ = deltaTime;
        if (1.0 / (*reinterpret_cast<::fnv_00c52590::Setting189 *>(&::g_01203194)).GetInt() < blend_ || 1.0 / (*reinterpret_cast<::fnv_00c52590::Setting189 *>(&::g_012031a0)).GetInt() > blend_)
        {
            float current4 = GetFarPlane();
            float minimum2 = (float)(*reinterpret_cast<::fnv_00c52590::Setting189 *>(&::g_012031ac)).GetInt();
            float target7 = minimum2;
            blend_ = (1.0 / deltaTime - (*reinterpret_cast<::fnv_00c52590::Setting189 *>(&::g_01203194)).GetInt()) * 1.0 / (*reinterpret_cast<::fnv_00c52590::Setting189 *>(&::g_012031a0)).GetInt();
            if (blend_ > 1.0)
                target7 = current4;
            else if (blend_ > 0.0)
                target7 += (current4 - minimum2) * blend_;
            float difference = target7 - previous;
            if (fabs(difference) > 10.0)
            {
                Camera189* viewCamera = GetCamera();
                Frustum189 view = viewCamera->frustum;
                previous += difference * deltaTime;
                view.farPlane = previous;
                reinterpret_cast<::NiCamera *>((viewCamera))->UpdateViewFrustum((*(const ::NiFrustum *)(&view)));
            }
        }
    }
}
}

// namespace fnv_00c52590

struct Q52Ent
{
    char pad[0x30];
    unsigned m_flags;
    inline void SetFlag(unsigned m, bool b)
    {
        if (b)
            m_flags |= m;
        else
            m_flags &= ~m;
    }
};

struct Q52Arr
{
    Q52Ent** m_data;
    unsigned pad4;
    unsigned m_uiItemCount;
    inline unsigned Count()
    {
        return m_uiItemCount;
    }
};

struct Q52Obj
{
    char pad[0x34];
    unsigned m_cur;
    unsigned m_num;
    char pad3c[4];
    Q52Arr** m_arrs;
    char pad44[2];
    unsigned short m_arrCount;
    bool FUN_00c52960(uintptr_t idx);
};

// @fnv 0x00c52960
bool Q52Obj::FUN_00c52960(uintptr_t idx)
{
    if (m_num > 0 && m_cur != idx)
    {
        if (idx == -1 || ((int)idx > -1 && idx < m_num))
        {
            unsigned i;
            bool sel = false;
            unsigned j;
            for (i = 0; i < m_arrCount; i++)
            {
                Q52Arr* arr = m_arrs[i];
                if (arr)
                {
                    if (i == idx)
                        sel = true;
                    for (j = 0; j < arr->Count(); j++)
                    {
                        if (arr->m_data[j])
                        {
                            arr->m_data[j]->SetFlag(2, sel);
                        }
                    }
                }
            }
            m_cur = idx;
            return true;
        }
    }
    return false;
}

void* __cdecl FUN_00aa1070(unsigned int);

void __cdecl FUN_00aa10f0(void*);

struct Q5Item;

struct Q5Hold
{
    Q5Item** m_data;
    unsigned m_alloc;
    unsigned m_uiItemCount;
    inline Q5Hold(unsigned n = 0)
    {
        if (n > 0)
            m_data = (Q5Item**)FUN_00aa1070(n * 4);
        else
            m_data = 0;
        m_alloc = 0;
        m_uiItemCount = 0;
    }
    inline ~Q5Hold()
    {
        void* p = m_data;
        FUN_00aa10f0(p);
    }
    inline unsigned Count()
    {
        return m_uiItemCount;
    }
};

struct Q5Obj
{
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c(), v20(), v24(), v28(), v2c(), v30(), v34(),
        v38(), v3c(), v40(), v44(), v48(), v4c(), v50(), v54(), v58(), v5c(), v60(), v64(), v68(), v6c(), v70(), v74(),
        v78(), v7c(), v80(), v84(), v88(), v8c(), v90(), v94();
    virtual void v98(Q5Item*);
    char pad[0x48];
    Q5Obj();
    bool FUN_00c52d80(Q5Item* it);
};

struct Q5Item
{
};

// @fnv 0x00c52a80
bool __cdecl FUN_00c52a80(void* param)
{
    Q5Hold items9;
    ::FUN_00c52c30((::BoneRootNode *)(param), (::BoneRootSet *)(::Q5Hold *)(&items9));
    if (items9.Count() == 0)
        return false;
    for (unsigned i6 = 0; i6 < items9.Count(); i6++)
    {
        Q5Item* it2 = items9.m_data[i6];
        Q5Obj* obj = new Q5Obj;
        obj->v98(it2);
        bool ok = obj->FUN_00c52d80(it2);
        if (ok)
            reinterpret_cast<::Q52Obj *>((obj))->FUN_00c52960(0);
        if (!ok)
        {
            reinterpret_cast<::ControllerOwner *>((it2))->FUN_00a5c480((::NiTimeController *)(obj));
            return false;
        }
    }
    return true;
}

namespace reconstruct_c5a9d0 {
struct Base
{
    virtual ~Base();
    int field_04;
    __forceinline Base()
    {
        field_04 = 0;
        InterlockedIncrement((volatile long*)&(*reinterpret_cast<int *>(&::NiRefObject::ms_lObjectCount)));
    }
};
struct List
{
    int field_00, field_04, field_08;
    __forceinline List()
    {
        field_08 = 0;
        field_00 = 0;
        field_04 = 0;
    }
    ~List();
};
struct Object
{
    int field_00;
    volatile long field_04;
};
struct Ref
{
    Object* field_00;
    __forceinline Ref()
    {
        field_00 = 0;
        if (field_00)
        {
            Object* object = field_00;
            InterlockedIncrement(&object->field_04);
        }
    }
    ~Ref();
    void Reset(void*);
};
struct ArrayBase
{
    int field_00, field_04, field_08, field_0c;
};
struct Array : ArrayBase
{
    __forceinline Array()
    {
        new ((void *)this) ::FUN_004b0260_shell(0, 1);
        field_00 = (intptr_t)&DAT_0101fbd4;
    }
    ~Array();
    static int DAT_0101fbd4;
};
struct Tail
{
    int field_00;
    void FUN_00822860(unsigned int, bool);
    __forceinline Tail()
    {
        field_00 = (intptr_t)&DAT_010840e4;
        FUN_00822860(0, false);
    }
    ~Tail();
    static int DAT_010840e4;
};
struct FUN_00c5a9d0 : Base
{
    List field_08, field_14, field_20;
    Ref field_2c;
    List field_30;
    Array field_3c;
    Ref field_4c;
    List field_50, field_5c;
    Tail field_68;
    FUN_00c5a9d0();
    virtual ~FUN_00c5a9d0();
};
__forceinline void Reserve()
{
    struct
    {
        int field_00, field_04, field_08, field_0c;
    } unused;
    (void)&unused;
}
// @fnv 0x00c5a9d0
FUN_00c5a9d0::FUN_00c5a9d0()
{
    Reserve();
    field_2c.Reset(0);
    field_4c.Reset(0);
}
}

namespace fnv_00c5ac00 {
inline long RefDecrement(volatile long* count)
{
    return InterlockedDecrement(count);
}
inline long RefIncrement(volatile long* count)
{
    return InterlockedIncrement(count);
}
struct PTRefBase
{
    virtual __forceinline ~PTRefBase()
    {
        InterlockedDecrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    }
    virtual void Destroy();
    inline void DecRef()
    {
        if (!RefDecrement(&refs))
            Destroy();
    }
    inline void AcquireReference()
    {
        RefIncrement(&refs);
    }
    volatile long refs;
};
struct PTSmart
{
    PTRefBase* ptr;
    PTSmart(PTRefBase*);
    PTSmart& operator=(const PTSmart&);
    inline PTSmart& FUN_0066b0d0(PTRefBase* value)
    {
        PTRefBase* previous = ptr;
        PTRefBase* replacement = value;
        if (previous != replacement)
        {
            if (previous)
                previous->DecRef();
            ptr = replacement;
            if (ptr)
                ptr->AcquireReference();
        }
        return *this;
    }
    __forceinline ~PTSmart()
    {
        if (ptr)
        {
            PTRefBase* old = ptr;
            if (!InterlockedDecrement(&old->refs))
                old->Destroy();
        }
    }
};
struct PTListItem
{
    PTListItem* next;
    PTListItem* prev;
    PTRefBase* data;
};
struct ListFields
{
    PTListItem* head;
    PTListItem* tail;
    int count;
    __forceinline ~ListFields()
    {}
};
struct FUN_00b71300_class : ListFields
{
    void DeleteItem(PTListItem*);
    inline void FUN_00b71300()
    {
        PTListItem* item = head;
        while (item)
        {
            PTListItem* old = item;
            item = item->next;
            DeleteItem(old);
        }
        count = 0;
        head = 0;
        tail = 0;
    }
    __forceinline ~FUN_00b71300_class()
    {
        reinterpret_cast<::BSShaderLightingProperty *>(this)->ClearLights();
    }
};
struct FUN_004a4650_class : ListFields
{
    __forceinline ~FUN_004a4650_class()
    {
        ::FUN_004a4650((::FUN_004a4650_ListBase *)this);
    }
};
struct FUN_004ed900_class : ListFields
{
    void DeleteItem(PTListItem*);
    inline void FUN_004ed900()
    {
        PTListItem* item = head;
        while (item)
        {
            PTListItem* old = item;
            item = item->next;
            DeleteItem(old);
        }
        count = 0;
        head = 0;
        tail = 0;
    }
    __forceinline ~FUN_004ed900_class()
    {
        ClearPointerList(this);
    }
};
struct FUN_00e74d40_class : ListFields
{
    void FUN_00e74d40();
    __forceinline ~FUN_00e74d40_class()
    {
        FUN_00e74d40();
    }
};
struct FUN_0087d480_class
{
    int head, tail, count;
    ~FUN_0087d480_class();
};
struct PTElement
{
    PTRefBase* ptr;
    PTElement(PTRefBase* value)
    {
        ptr = value;
        if (ptr)
            ptr->AcquireReference();
    }
    PTElement& operator=(const PTElement&);
    ~PTElement();
};
struct ArrObj
{
    PTElement* elements;
    unsigned short capacity, size, grow, used;
    virtual __forceinline ~ArrObj()
    {
        Free(elements);
    }
    static __forceinline void Free(PTElement* data)
    {
        delete[] data;
    }
    inline void FUN_004dffa0()
    {
        for (unsigned short i = 0; i < size; ++i)
            elements[i] = PTElement(0);
        size = 0;
        grow = 0;
    }
};
struct FUN_00c5ac00 : PTRefBase
{
    FUN_004ed900_class sub08;
    FUN_00b71300_class sub14;
    FUN_004a4650_class sub20;
    PTSmart ptr2c;
    FUN_004a4650_class sub30;
    ArrObj arr3c;
    PTSmart ptr4c;
    FUN_00e74d40_class sub50, sub5c;
    FUN_0087d480_class sub68;
    virtual ~FUN_00c5ac00();
};
// @fnv 0x00c5ac00
FUN_00c5ac00::~FUN_00c5ac00()
{
    reinterpret_cast<::BSShaderLightingProperty *>(&(sub14))->ClearLights();
    ::FUN_004a4650((::FUN_004a4650_ListBase *)&(sub20));
    ClearPointerList(&sub08);
    arr3c.FUN_004dffa0();
    ptr2c.FUN_0066b0d0(0);
    ptr4c.FUN_0066b0d0(0);
}
}

namespace fnv_00c5bae0 {
// Calls FUN_00c5ac00, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00c5bae0
void* FUN_00c5ac00_class::FUN_00c5bae0(unsigned int flags)
{
    reinterpret_cast<::fnv_00c5ac00::FUN_00c5ac00 *>(this)->fnv_00c5ac00::FUN_00c5ac00::~FUN_00c5ac00();
    if (flags & 1)
        operator delete(this, 0x78);
    return this;
}
}  // namespace fnv_00c5bae0

// namespace fnv_00c5ac00

namespace fnv_00c5aef0 {
struct RefQ
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
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
template <class T> struct ItemQ
{
    ItemQ* m_pkNext;
    ItemQ* m_pkPrev;
    T m_element;
};
template <class T> struct PtrListQ
{
    ItemQ<T>* m_pkHead;
    ItemQ<T>* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(void*& pos) const
    {
        T& e = ((ItemQ<T>*)pos)->m_element;
        pos = ((ItemQ<T>*)pos)->m_pkNext;
        return e;
    }
    void* FindPos(const T& val, void* pos = 0) const
    {
        if (pos == 0)
            pos = GetHeadPos();
        while (pos)
        {
            void* pkFound = pos;
            if (val == GetNext(pos))
                return pkFound;
        }
        return 0;
    }
    void FUN_00a5a310(const T& item);
};
inline void DeadQ4()
{
    int aiQ[4];
}
struct FUN_00c5aef0_cls
{
    char pad[0x20];
    PtrListQ<NiPointer<RefQ> > m_kNode;
    void FUN_00c5aef0(RefQ* pObj);
};
// @fnv 0x00c5aef0
void FUN_00c5aef0_cls::FUN_00c5aef0(RefQ* pObj)
{
    if (pObj)
    {
        if (!m_kNode.FindPos(pObj))
        {
            m_kNode.FUN_00a5a310(pObj), DeadQ4();
        }
    }
}
}

// namespace fnv_00c5aef0


inline long NiAtomicIncrementB06(long& lValue)
{
    return InterlockedIncrement(&lValue);
}

inline long NiAtomicDecrementB06(long& lValue)
{
    return InterlockedDecrement(&lValue);
}

class RefObjectB06
{
  public:
    virtual ~RefObjectB06();
    virtual void DeleteThis();
    void IncRefCount()
    {
        NiAtomicIncrementB06(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (NiAtomicDecrementB06(m_uiRefCount) == 0)
            DeleteThis();
    }
    long m_uiRefCount;
};

template <class T> class NiPointerB06
{
  public:
    NiPointerB06(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerB06()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};

struct RefSetB06
{
    NiPointerB06<RefObjectB06> FUN_00c5bda0(const NiPointerB06<RefObjectB06>& spRetainedObject);
    void* m_pUserData;
};

struct OwnerB06
{
    void* m_pVTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    RefSetB06 m_kSet;

    void FUN_00c5b060(RefObjectB06* pkObject);
};

// @fnv 0x00c5b060
void OwnerB06::FUN_00c5b060(RefObjectB06* pkObject)
{
    if (pkObject)
    {
        NiPointerB06<RefObjectB06> spRetainedObject(pkObject);
        m_kSet.FUN_00c5bda0(spRetainedObject);
    }
}

struct S_C5B4D0_Node
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
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
    unsigned int m_uiValue1;

    __forceinline void SetBit(bool bSet, unsigned int uiMask)
    {
        if (bSet)
            m_uiValue1 |= uiMask;
        else
            m_uiValue1 &= ~uiMask;
    }
};

// /Od /Ob1 tries to inline this, keeps its six locals in the caller, then leaves the call.
struct FUN_004dffa0_Class
{
    inline void FUN_004dffa0();
};

inline void FUN_004dffa0_Class::FUN_004dffa0()
{
    int l0, l1, l2, l3, l4, l5;
    l0 = 1;
    l1 = 2;
    l2 = 3;
    l3 = 4;
    l4 = 5;
    l5 = 6;
    l0 = l5 + 0;
    l1 = l0 + 0;
    l2 = l1 + 0;
    l3 = l2 + 0;
    l4 = l3 + 0;
    l5 = l4 + 0;
    l0 = l5 + 1;
    l1 = l0 + 1;
    l2 = l1 + 1;
    l3 = l2 + 1;
    l4 = l3 + 1;
    l5 = l4 + 1;
    l0 = l5 + 2;
    l1 = l0 + 2;
    l2 = l1 + 2;
    l3 = l2 + 2;
    l4 = l3 + 2;
    l5 = l4 + 2;
    l0 = l5 + 3;
    l1 = l0 + 3;
    l2 = l1 + 3;
    l3 = l2 + 3;
    l4 = l3 + 3;
    l5 = l4 + 3;
    l0 = l5 + 4;
    l1 = l0 + 4;
    l2 = l1 + 4;
    l3 = l2 + 4;
    l4 = l3 + 4;
    l5 = l4 + 4;
    l0 = l5 + 5;
    l1 = l0 + 5;
    l2 = l1 + 5;
    l3 = l2 + 5;
    l4 = l3 + 5;
    l5 = l4 + 5;
    l0 = l5 + 6;
    l1 = l0 + 6;
    l2 = l1 + 6;
    l3 = l2 + 6;
    l4 = l3 + 6;
    l5 = l4 + 6;
    l0 = l5 + 7;
    l1 = l0 + 7;
    l2 = l1 + 7;
    l3 = l2 + 7;
    l4 = l3 + 7;
    l5 = l4 + 7;
}

struct TempEffectList
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
    FUN_004dffa0_Class unk3c;
    S_C5B4D0_Node** unk40;
    unsigned short unk44;
    unsigned short unk46;

    void FUN_00c5b4d0();
};

// @fnv 0x00c5b4d0
void TempEffectList::FUN_00c5b4d0()
{
    unsigned int i = 0;
    for (; i < (unsigned int)unk46; ++i)
    {
        S_C5B4D0_Node** element = &unk40[i];
        S_C5B4D0_Node* p = *element;
        if (p)
        {
            S_C5B4D0_Node* p1 = p;
            InterlockedIncrement(&p1->m_uiRefCount);
        }
        if (p)
        {
            S_C5B4D0_Node* p2 = p;
            p2->SetBit(false, 1u);
        }
        if (p)
        {
            S_C5B4D0_Node* p3 = p;
            if (InterlockedDecrement(&p3->m_uiRefCount) == 0)
                p3->DeleteThis();
        }
    }
    reinterpret_cast<::fnv_00c5ac00::ArrObj *>(&(unk3c))->FUN_004dffa0();
}

namespace fnv5b5f0 {
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_uiRefCount;
    __forceinline void AcquireReference()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRef()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct RefPtr
{
    RefObj* m_pObject;
    __forceinline RefPtr(RefObj* pkObj)
    {
        m_pObject = pkObj;
        if (m_pObject)
            m_pObject->AcquireReference();
    }
    __forceinline RefPtr(const RefPtr& kOther)
    {
        m_pObject = kOther.m_pObject;
        if (m_pObject)
            m_pObject->AcquireReference();
    }
    __forceinline ~RefPtr()
    {
        if (m_pObject)
            m_pObject->DecRef();
    }
    __forceinline operator RefObj*() const
    {
        return m_pObject;
    }
    __forceinline bool operator==(RefObj* pkObj) const
    {
        return m_pObject == pkObj;
    }
};

struct PtrArray
{
    void* m_pVtbl;
    RefPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __forceinline RefPtr& operator[](unsigned int uiIndex)
    {
        return m_pBase[uiIndex];
    }
    void Grow(unsigned int uiGrowBy);
    unsigned int FUN_00a5eb20(const RefPtr& kElement)
    {
        int pad0, pad1, pad2, pad3, pad4, pad5, pad6, pad7, pad8, pad9, pad10, pad11, pad12;
        pad0 = m_usSize;
        pad1 = m_usSize;
        pad2 = m_usSize;
        pad3 = m_usSize;
        pad4 = m_usSize;
        pad5 = m_usSize;
        pad6 = m_usSize;
        pad7 = m_usSize;
        pad8 = m_usSize;
        pad9 = m_usSize;
        pad10 = m_usSize;
        pad11 = m_usSize;
        pad12 = m_usSize;
        if (kElement.m_pObject == 0)
            return (unsigned int)(pad0 + pad1 + pad2 + pad3 + pad4 + pad5 + pad6 + pad7 + pad8 + pad9 + pad10 + pad11 +
                                  pad12);
        unsigned int uiIndex = 0;
        while (uiIndex < m_usSize)
        {
            if (m_pBase[uiIndex].m_pObject == 0)
                break;
            uiIndex++;
        }
        if (uiIndex >= m_usSize)
        {
            if (m_usSize >= m_usMaxSize)
                Grow(m_usGrowBy);
            uiIndex = m_usSize;
            m_usSize++;
        }
        m_pBase[uiIndex] = kElement;
        return uiIndex + (pad0 + pad1 + pad2 + pad3 + pad4 + pad5 + pad6 + pad7 + pad8 + pad9 + pad10 + pad11 + pad12);
    }
};

struct Owner_c5b5f0
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
    PtrArray m_kArray;
    void FUN_00c5b5f0(RefObj* pkObj);
};

// @fnv 0x00c5b5f0
void Owner_c5b5f0::FUN_00c5b5f0(RefObj* pkObj)
{
    if (pkObj == 0)
        return;
    bool bFound = false;
    for (unsigned int i = 0; i < m_kArray.m_usSize; i++)
    {
        RefPtr spEntry = m_kArray[i];
        if (spEntry && spEntry == pkObj)
            bFound = true;
    }
    if (!bFound)
    {
        RefPtr spNew = pkObj;
        reinterpret_cast<::S_00a5eb20_Arr *>(&(m_kArray))->FUN_00a5eb20((const ::S_00a5eb20_Ptr &)(spNew));
    }
}
}

// Under a critical section, calls FUN_00c5b5f0 on each element of m_50 and FUN_00c5b740 on each of m_5c, removing all entries from each list afterward.
// @fnv 0x00c5b8d0
void SpawnedObject::FUN_00c5b8d0()
{
    EnterCriticalSection(&DAT_01203328);
    void* value;
    SpawnNode* node;
    {
        SpawnNode* head = m_50.m_pkHead;
        node = head;
        value = 0;
        while (node != 0) {
            NiPointer<NiProperty>* ref = &node->m_element;
            LoopPadA tmp;
            node = node->m_pkNext;
            value = ref->m_pObject;
            if (value != 0) {
                reinterpret_cast<::fnv5b5f0::Owner_c5b5f0 *>(this)->FUN_00c5b5f0((::fnv5b5f0::RefObj *)(value));
            }
        }
    }
    m_50.RemoveAll();
    {
        SpawnNode* head = m_5c.m_pkHead;
        node = head;
        value = 0;
        while (node != 0) {
            NiPointer<NiProperty>* ref = &node->m_element;
            LoopPadB tmp;
            node = node->m_pkNext;
            value = ref->m_pObject;
            if (value != 0) {
                reinterpret_cast<::Owner5b *>(this)->FUN_00c5b740((::RefObj5b *)(value));
            }
        }
    }
    m_5c.RemoveAll();
    LeaveCriticalSection(&DAT_01203328);
}

struct NavObject
{
    virtual void Dtor();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
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

struct NavMeshPtr
{
    NavObject* m_pObject;
    __forceinline NavMeshPtr(NavObject* object)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NavMeshPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct S2f850
{
    unsigned int FUN_006c61b0(const NavMeshPtr& value);
};

// Body is past the /Ob1 size cutoff, so the call stays out of line and these
// eight locals stay reserved in the caller between the pointer ctor and dtor.
inline unsigned int S2f850::FUN_006c61b0(const NavMeshPtr& value)
{
    unsigned int s0, s1, s2, s3, s4, s5, s6, s7;
    s0 = s0 + 0;
    s0 = s0 + 1;
    s0 = s0 + 2;
    s0 = s0 + 3;
    s0 = s0 + 4;
    s0 = s0 + 5;
    s0 = s0 + 6;
    s0 = s0 + 7;
    s0 = s0 + 8;
    s0 = s0 + 9;
    s0 = s0 + 10;
    s0 = s0 + 11;
    s0 = s0 + 12;
    s0 = s0 + 13;
    s0 = s0 + 14;
    s0 = s0 + 15;
    s0 = s0 + 16;
    s0 = s0 + 17;
    s0 = s0 + 18;
    s0 = s0 + 19;
    s0 = s0 + 20;
    s0 = s0 + 21;
    s0 = s0 + 22;
    s0 = s0 + 23;
    s0 = s0 + 24;
    s0 = s0 + 25;
    s0 = s0 + 26;
    s0 = s0 + 27;
    s0 = s0 + 28;
    s0 = s0 + 29;
    s0 = s0 + 30;
    s0 = s0 + 31;
    s0 = s0 + 32;
    s0 = s0 + 33;
    s0 = s0 + 34;
    s0 = s0 + 35;
    s0 = s0 + 36;
    s0 = s0 + 37;
    s0 = s0 + 38;
    s0 = s0 + 39;
    s0 = s0 + 40;
    s0 = s0 + 41;
    s0 = s0 + 42;
    s0 = s0 + 43;
    s0 = s0 + 44;
    s0 = s0 + 45;
    s0 = s0 + 46;
    s0 = s0 + 47;
    s0 = s0 + 48;
    s0 = s0 + 49;
    s0 = s0 + 50;
    s0 = s0 + 51;
    s0 = s0 + 52;
    s0 = s0 + 53;
    s0 = s0 + 54;
    s0 = s0 + 55;
    s0 = s0 + 56;
    s0 = s0 + 57;
    s0 = s0 + 58;
    s0 = s0 + 59;
    s0 = s0 + 60;
    s0 = s0 + 61;
    s0 = s0 + 62;
    s0 = s0 + 63;
    s0 = s0 + 64;
    s0 = s0 + 65;
    s0 = s0 + 66;
    s0 = s0 + 67;
    s0 = s0 + 68;
    s0 = s0 + 69;
    s0 = s0 + 70;
    s0 = s0 + 71;
    s0 = s0 + 72;
    s0 = s0 + 73;
    s0 = s0 + 74;
    s0 = s0 + 75;
    s0 = s0 + 76;
    s0 = s0 + 77;
    s0 = s0 + 78;
    s0 = s0 + 79;
    return s0;
}

struct OwnerC5
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64;
    S2f850 unk68;
    void FUN_00c5b9a0(NavObject* arg);
};

// @fnv 0x00c5b9a0
void OwnerC5::FUN_00c5b9a0(NavObject* arg)
{
    if (arg)
    {
        NavMeshPtr local(arg);
        unk68.FUN_006c61b0(local);
    }
}

// Find's bool compare and the declined RemoveAt inline are /Ob1 (accept_also).
// The size-refused body reserves the 7 dead slots between this and the array temp.
inline bool ElemEq(unsigned int a, unsigned int b)
{
    return a == b;
}

inline unsigned int FindIndex(FUN_00c5bef0_class* self, unsigned int value)
{
    unsigned int i;
    for (i = 0; i < self->m2; ++i)
    {
        if (self->m1 != 0 && ElemEq(reinterpret_cast<unsigned int*>(self->m1)[i], value))
            return i;
    }
    return 0xffffffffu;
}


struct S_00c5ba50_Class
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
    FUN_00c5bef0_class unk68;

    void FUN_00c5ba50(unsigned int value);
};

// @fnv 0x00c5ba50
void S_00c5ba50_Class::FUN_00c5ba50(unsigned int value)
{
    unsigned int result2;
    result2 = FindIndex(&unk68, value);
    if (result2 != 0xffffffffu)
        unk68.RemoveRange(result2, 1);
}

struct RefC5BB
{
    virtual void v_00();
    virtual void v_04();
    volatile long field_04;
    void IncRefCount()
    {
        InterlockedIncrement(&field_04);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&field_04))
            v_04();
    }
};

struct PtrC5BB
{
    RefC5BB* field_00;
    PtrC5BB(RefC5BB* p = 0)
    {
        field_00 = p;
        if (field_00)
            field_00->IncRefCount();
    }
    PtrC5BB(const PtrC5BB& p)
    {
        field_00 = p.field_00;
        if (field_00)
            field_00->IncRefCount();
    }
    ~PtrC5BB()
    {
        if (field_00)
            field_00->DecRefCount();
    }
    PtrC5BB& operator=(const PtrC5BB& other)
    {
        if (field_00 != other.field_00)
        {
            if (field_00)
                field_00->DecRefCount();
            field_00 = other.field_00;
            if (field_00)
                field_00->IncRefCount();
        }
        return *this;
    }
    bool operator!=(const PtrC5BB& p) const
    {
        return field_00 != p.field_00;
    }
};

struct ArrayC5BB
{
    unsigned int field_00;
    PtrC5BB* field_04;
    unsigned short field_08, field_0a, field_0c, field_0e;
    PtrC5BB FUN_00c5bb60(unsigned int index);
};

// @fnv 0x00c5bb60
PtrC5BB ArrayC5BB::FUN_00c5bb60(unsigned int index)
{
    if (index >= field_0a)
        return PtrC5BB();
    --field_0a;
    PtrC5BB value = field_04[index];
    field_04[index] = field_04[field_0a];
    field_04[field_0a] = PtrC5BB();
    if (value != PtrC5BB())
        --field_0c;
    return value;
}

namespace fnv_00c5c290 {
struct RefQ
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
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
struct SPQ
{
    RefQ* m_pObject;
    SPQ(const SPQ& o)
    {
        m_pObject = o.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SPQ()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    SPQ& FUN_0066b0d0(RefQ* p);
};
inline void DeadQ5()
{
    int aiQ[5];
}
struct ItemQ
{
    ItemQ* m_pkNext;
    ItemQ* m_pkPrev;
    SPQ m_element;
};
struct AllocQ
{
    unsigned int m_uiCount;
    void FUN_0045cee0(ItemQ* p);
};
struct FUN_00c5c290_cls
{
    ItemQ* m_pkHead;
    ItemQ* m_pkTail;
    AllocQ m_kItemCount;
    SPQ FUN_00c5c290();
};
// @fnv 0x00c5c290
SPQ FUN_00c5c290_cls::FUN_00c5c290()
{
    ItemQ* pkNode = m_pkTail;
    m_pkTail = m_pkTail->m_pkPrev;
    if (m_pkTail)
        m_pkTail->m_pkNext = 0;
    else
        m_pkHead = 0;
    SPQ element = pkNode->m_element;
    pkNode->m_element.FUN_0066b0d0(0);
    reinterpret_cast<::FUN_0045cee0_shell *>(&(m_kItemCount))->FUN_0045cee0(pkNode);
    m_kItemCount.m_uiCount--;
    DeadQ5();
    return element;
}
}

// namespace fnv_00c5c290

inline float FMod(float x, float y)
{
    return ((float)std::fmod((double)x, (double)y));
}

extern float DAT_010c2d4c;

struct SeqNode
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c, u60, u64, u68, u6c, u70, u74, u78, u7c;
    int u80, u84, u88, u8c, u90, u94, u98, u9c, ua0, ua4, ua8, uac, ub0, ub4, ub8, ubc;
    int uc0, uc4, uc8, ucc, ud0;
    float m_d4;
};

struct SeqInner
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c, u60, u64, u68, u6c, u70, u74, u78, u7c;
    int u80, u84, u88, u8c, u90, u94, u98, u9c, ua0, ua4, ua8, uac, ub0, ub4;
    unsigned short m_b8;
};

struct SeqIface
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
    virtual bool v27(float t, SeqNode* n, float* out);
};

struct SeqBase
{
    int unk00;
    int unk04;
    unsigned short m_flags;
    unsigned short unk0A;
    float m_0c;
    float m_10;
    int unk14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    SeqNode* m_2c;
    int unk30;
    int unk34;
    int unk38;
    int m_3c;
    int unk40;
    int unk44;
    float m_48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    SeqInner* m_5c;

    inline bool GetBit(unsigned short mask) const
    {
        return (m_flags & mask) != 0;
    }
    inline bool GetActive() const
    {
        return GetBit(8);
    }
    inline bool GetForceUpdate() const
    {
        return GetBit(0x80);
    }

    inline SeqIface* FUN_00639b60()
    {
        unsigned a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
        if (m_flags)
            return ((::SeqIface *)(reinterpret_cast<::NiPSysEmitterCtlr_StandIn *>(this)->FUN_00639b60()));
        a0 = a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = a9 = a10 = 0;
        return 0;
    }
};

struct NW
{
    unsigned short n;
    char unk;
    bool w;
};

struct FUN_00c5c470_cls : SeqBase
{
    void FUN_00c5c470(float* pTime);
};

inline int MinCount(unsigned short a, int b)
{
    return a < b ? a : b;
}

struct Emitted
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
    unsigned int flags;
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
    float time;
    float GetTime() const
    {
        return time;
    }
};

struct ParticleNode
{
    ParticleNode* next;
    ParticleNode* previous;
    Emitted* value;
};

struct Emitter
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
    ParticleNode* first;
    int unkb0;
    int unkb4;
    unsigned short count;
    unsigned short GetCount() const
    {
        return count;
    }
    int unkbc;
    ParticleNode* next;
    inline Emitted* PopFrontNode()
    {
        ParticleNode** cursor = &next;
        Emitted** value = &(*cursor)->value;
        *cursor = (*cursor)->next;
        Emitted* result = *value;
        if (!next)
        {
            ParticleNode* head = first;
            next = head;
        }
        return result;
    }
};

struct S240
{
    float* data;
    float* GetData() const
    {
        return data;
    }
    unsigned int capacity;
    unsigned int count;
    void PushBack(const float& value);
};

struct ParticleSystem
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
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void Emit(float now, unsigned short count, float* times);
    virtual void va8();
    virtual void SetCurrent(Emitted* particle);
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
    float time;
    Emitted* current;
    void SetTime(float value)
    {
        time = value;
    }
};

extern unsigned short DAT_011afa9c;

struct Controller
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
    ParticleSystem* system;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    S240 times;
    Emitter* emitter;
    unsigned short maxCount;
    void FUN_00c5c790(float now, float start, float end, float emitStart, float emitEnd, float rate);
};

// @fnv 0x00c5c470
void FUN_00c5c470_cls::FUN_00c5c470(float* pTime)
{
    float fx2;
    NW nw;
    SeqIface* obj5;
    float dt6;
    float out4;
    float c3;
    float d8;
    float lim;
    obj5 = 0;
    c3 = 0.0f;
    lim = 0.0f;
    nw.n = m_5c->m_b8;
    if (nw.n == 0)
    {
        m_20 = *pTime;
        return;
    }
    else
    {
        if (m_20 > *pTime)
            m_48 = -DAT_010c2d4c;
        if (m_2c == 0 || m_3c == 0)
        {
            return;
        }
        else
        {
            if (!GetActive() || (m_20 == *pTime && !GetForceUpdate()))
            {
                return;
            }
            else
            {
                if (m_1c == -DAT_010c2d4c)
                    m_1c = *pTime;
                if (m_20 == -DAT_010c2d4c)
                    dt6 = 0.0f;
                else
                    dt6 = *pTime - m_20;
                m_24 = dt6 * m_0c + m_24;
                m_28 = m_24 + m_10;
                m_20 = *pTime;
                lim = m_18;
                if (lim != ::_DAT_01012060)
                {
                    fx2 = m_28;
                    m_28 = FMod(fx2, lim);
                    if (m_28 < ::_DAT_01012060)
                        m_28 = m_28 + lim;
                }
                else
                {
                    m_28 = 0.0f;
                }
                if (m_48 == -DAT_010c2d4c)
                {
                    if (m_28 > ::_DAT_01012060)
                    {
                        m_48 = 0.0f;
                    }
                    else
                    {
                        m_48 = m_28;
                        return;
                        return;
                    }
                }
                obj5 = ((::SeqIface *)(reinterpret_cast<::NiPSysEmitterCtlr_StandIn *>(this)->FUN_00639b60()));
                c3 = m_2c->m_d4;
                nw.w = false;
                if (m_28 > m_48)
                {
                    d8 = m_28 - m_48;
                }
                else
                {
                    d8 = m_18 - m_48 + m_28;
                    nw.w = true;
                }
                if (obj5 != 0)
                {
                    if (obj5->v27(0.0f, m_2c, &out4))
                    {
                        reinterpret_cast<::Controller *>(this)->FUN_00c5c790(c3 + d8, nw.w ? m_18 : m_28, m_48, 0.0f, m_18, out4);
                    }
                }
                m_48 = m_28;
            }
        }
    }
}

// @fnv 0x00c5c790
void Controller::FUN_00c5c790(float now, float start, float end, float emitStart, float emitEnd, float rate)
{
    float age;
    Emitted* particle5;
    unsigned short idx2;
    float interval;
    ParticleSystem* ps1;
    unsigned short count2;
    unsigned short steps2;
    unsigned short remainingVal;
    float savedTime;
    unsigned short limitA5;
    Emitted* saved;
    unsigned short previousB;
    unsigned short addedB;
    unsigned short total_13;
    float duration20;
    float elapsed_2;

    if (emitter && rate > 0.0 && emitStart < emitEnd && start > emitStart && end < emitEnd)
    {

        if (start <= emitEnd)
            duration20 = start - emitStart;
        else
            duration20 = emitEnd - emitStart;
        elapsed_2 = 0.0f;
        if (end >= emitStart)
            elapsed_2 = end - emitStart;
        if (emitter->GetCount())
        {
            total_13 = (unsigned short)(rate * duration20);
            previousB = (unsigned short)(rate * elapsed_2);
            addedB = total_13 - previousB;
            if (addedB > 0)
            {
                remainingVal = emitter->count;
                limitA5 = maxCount * addedB;
                count2 = MinCount(limitA5, addedB * remainingVal);
                steps2 = count2 / remainingVal;
                if (steps2 > DAT_011afa9c)
                    steps2 = DAT_011afa9c;
                if (!steps2)
                {
                    remainingVal = count2;
                    steps2 = 1;
                }
                interval = 1.0f / rate;
                times.count = 0;
                for (idx2 = 0; idx2 < steps2; idx2++)
                {
                    previousB++;
                    age = duration20 - previousB * interval;
                    times.PushBack(age);
                }
                ps1 = system;
                saved = ps1->current;
                savedTime = ps1->time;
                while (remainingVal > 0)
                {
                    particle5 = ((::Emitted *)(reinterpret_cast<::FUN_00c5ce40_Class *>((emitter))->PopFrontNode()));
                    if (particle5 && !(bool)(particle5->flags & 1 ? 1 : 0))
                    {
                        ps1->SetCurrent(particle5);
                        ps1->SetTime(particle5->GetTime());
                        ps1->Emit(now, steps2, times.GetData());
                        remainingVal--;
                    }
                }
                ps1->SetCurrent(saved);
                ps1->time = savedTime;
            }
        }
    }
}

struct D3DRect_Stub
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D3DDevice_Stub
{
    virtual long v000();
    virtual long v004();
    virtual long v008();
    virtual long v00c();
    virtual long v010();
    virtual long v014();
    virtual long v018();
    virtual long v01c();
    virtual long v020();
    virtual long v024();
    virtual long v028();
    virtual long v02c();
    virtual long v030();
    virtual long v034();
    virtual long v038();
    virtual long v03c();
    virtual long v040();
    virtual long v044();
    virtual long v048();
    virtual long v04c();
    virtual long v050();
    virtual long v054();
    virtual long v058();
    virtual long v05c();
    virtual long v060();
    virtual long v064();
    virtual long v068();
    virtual long v06c();
    virtual long v070();
    virtual long v074();
    virtual long v078();
    virtual long v07c();
    virtual long v080();
    virtual long v084();
    virtual long v088();
    virtual long v08c();
    virtual long v090();
    virtual long v094();
    virtual long v098();
    virtual long v09c();
    virtual long v0a0();
    virtual long v0a4();
    virtual long v0a8();
    virtual long v0ac();
    virtual long v0b0();
    virtual long v0b4();
    virtual long v0b8();
    virtual long v0bc();
    virtual long v0c0();
    virtual long v0c4();
    virtual long v0c8();
    virtual long v0cc();
    virtual long v0d0();
    virtual long v0d4();
    virtual long v0d8();
    virtual long v0dc();
    virtual long v0e0();
    virtual long SetRenderState(int eState, unsigned long dwValue);
    virtual long v0e8();
    virtual long v0ec();
    virtual long v0f0();
    virtual long v0f4();
    virtual long v0f8();
    virtual long v0fc();
    virtual long v100();
    virtual long v104();
    virtual long v108();
    virtual long v10c();
    virtual long v110();
    virtual long v114();
    virtual long v118();
    virtual long v11c();
    virtual long v120();
    virtual long v124();
    virtual long v128();
    virtual long SetScissorRect(const D3DRect_Stub* pRect);
};

struct NiDX9Renderer_Stub
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
    D3DDevice_Stub* m_pDirect3DDevice;
    D3DDevice_Stub* GetD3DDevice()
    {
        return m_pDirect3DDevice;
    }
};

struct ScissorBase_Stub
{
};

struct ScissorProperty_Stub : ScissorBase_Stub
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
    D3DRect_Stub m_kScissorRect;

    void FUN_00c5d110(NiDX9Renderer_Stub* pkRenderer);
};

// @fnv 0x00c5d110
void ScissorProperty_Stub::FUN_00c5d110(NiDX9Renderer_Stub* pkRenderer)
{
    NiDX9Renderer_Stub* pkDX9Renderer = pkRenderer;
    unsigned long dwOldValue = 0;
    bool bScissorSetRes = false;

    if (m_kScissorRect.bottom != 0 || m_kScissorRect.top != 0 || m_kScissorRect.left != 0 || m_kScissorRect.right != 0)
    {
        if ((m_kScissorRect.left < 0 && m_kScissorRect.right < 0) ||
            (m_kScissorRect.left > 1 && m_kScissorRect.right > 1) ||
            (m_kScissorRect.top < 0 && m_kScissorRect.bottom < 0) ||
            (m_kScissorRect.top > 1 && m_kScissorRect.bottom > 1))
        {
            pkDX9Renderer->GetD3DDevice()->SetRenderState(0xae, 1);
            pkDX9Renderer->GetD3DDevice()->SetScissorRect(&m_kScissorRect);
            bScissorSetRes = true;
        }
    }

    reinterpret_cast<::FUN_00a745c0_This *>(this)->FUN_00a745c0(pkRenderer);

    if (bScissorSetRes)
        pkDX9Renderer->GetD3DDevice()->SetRenderState(0xae, dwOldValue);
}

extern "C" char DAT_010c2fb4;

extern "C" char DAT_010c2fa8;

inline void DeadQ1()
{
    int aiQ[1];
}

inline void DeadQ7()
{
    int aiQ[7];
}

struct NodeBaseQ
{
    virtual ~NodeBaseQ();
    char pad[0xa8];
    NodeBaseQ(unsigned int n);
};

struct ListQ
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    ListQ()
    {
        m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
    ~ListQ();
    void FUN_00e74d40();
};

struct ArrBaseQ
{
    int* vtbl;
    void* m0;
    unsigned short m1, m2, m3, m4;
    ArrBaseQ(unsigned short a, unsigned short b);
    ~ArrBaseQ();
};

struct ArrQ : ArrBaseQ
{
    ArrQ() : ArrBaseQ(0, 1)
    {
        DeadQ1();
        *(void**)this = &DAT_010c2fa8;
    }
};

struct FUN_00c5da70 : NodeBaseQ
{
    virtual void v0();
    ListQ m_kNode;
    unsigned short m_b8, m_ba, m_bc;
    unsigned int m_c0;
    int m_c4, m_c8;
    ArrQ m_aiIndexedValues;
    float m_dc;
    FUN_00c5da70();
};

// @fnv 0x00c5da70
FUN_00c5da70::FUN_00c5da70() : NodeBaseQ(0)
{
    m_c4 = -1;
    m_c8 = -1;
    m_ba = 0x14;
    m_bc = 0;
    m_b8 = 0;
    m_c0 = 0;
    m_kNode.FUN_00e74d40();
    m_dc = 0.0f;
    DeadQ7();
}

namespace fnv_00c5dcd0 {
struct RefQ
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
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
template <class T> struct ItemQ
{
    ItemQ* m_pkNext;
    ItemQ* m_pkPrev;
    T m_element;
};
template <class T> struct PtrListQ
{
    ItemQ<T>* m_pkHead;
    ItemQ<T>* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(void*& pos) const
    {
        T& e = ((ItemQ<T>*)pos)->m_element;
        pos = ((ItemQ<T>*)pos)->m_pkNext;
        return e;
    }
    void* FindPos(const T& val, void* pos = 0) const
    {
        if (pos == 0)
            pos = GetHeadPos();
        while (pos)
        {
            void* pkFound = pos;
            if (val == GetNext(pos))
                return pkFound;
        }
        return 0;
    }
    void FUN_00a5a310(const T& item);
};
inline void DeadQ4()
{
    int aiQ[4];
}
struct FUN_00c5dcd0_cls
{
    char pad[0xac];
    PtrListQ<NiPointer<RefQ> > m_kNode;
    void FUN_00c5dcd0(RefQ* pObj);
};
// @fnv 0x00c5dcd0
void FUN_00c5dcd0_cls::FUN_00c5dcd0(RefQ* pObj)
{
    void* pos = m_kNode.FindPos(pObj);
    if (!pos)
        m_kNode.FUN_00a5a310(pObj), DeadQ4();
}
}

// @fnv 0x00c505c0
void FUN_00c505c0_Class::FUN_00c505c0(int aiIndex, void* pEmitter)
{
    FUN_00c5dcd0_Class* p = ((::FUN_00c5dcd0_Class *)(reinterpret_cast<::FUN_00c50f30_class *>((reinterpret_cast<FUN_00c50f30_Class*>(this)))->GetEntryValue(aiIndex)));
    if (p)
        reinterpret_cast<::fnv_00c5dcd0::FUN_00c5dcd0_cls *>((p))->FUN_00c5dcd0((::fnv_00c5dcd0::RefQ *)(pEmitter));
    else {
        void* s = *(void**)((char*)pEmitter + 8);
        ::FUN_005b5e40();
    }
}

// namespace fnv_00c5dcd0

struct EB90Sub
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
    virtual unsigned short GetFlags();
};

struct EB90Item
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4;
    EB90Sub* m_pSub;
};

struct EB90Obj
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC;
    EB90Item** m_ppItems;
    unsigned short unkD4;
    unsigned short m_usElementCount;

    bool FUN_00c5eb90();
};

// Calls FUN_00c5e080, then if unkb8 > 0 or FUN_00c5eb90() adds *p to unkdc, passes the sum to FUN_00a5ded0, and restores *p.
// @fnv 0x00c5e3d0
void S_00c5e3d0::FUN_00c5e3d0(float* p, int b)
{
    S_00c5e3d0_pad tmp;
    FUN_00c5e080();
    if (unkb8 > 0 || reinterpret_cast<::EB90Obj *>(this)->FUN_00c5eb90()) {
        unkdc += *p;
        tmp.saved = *p;
        *p = unkdc;
        reinterpret_cast<::NiNode *>(this)->UpdateSelectedDownwardPass((*(::NiUpdateData *)(p)), b);
        *p = tmp.saved;
    }
}

// Calls FUN_00c5e080, then if m_b8 > 0 or FUN_00c5eb90() is true, adds *f to m_dc, passes the sum to FUN_00a5e1f0, and restores *f.
// @fnv 0x00c5e450
void FUN_00c5e450_cls::FUN_00c5e450(float* pfValue, int b)
{
    float saved;
    int a0;
    int a1;
    int a2;
    int a3;
    reinterpret_cast<::S_00c5e3d0 *>(this)->FUN_00c5e080();
    if (m_b8 > 0 || ((unsigned char)(reinterpret_cast<::EB90Obj *>(this)->FUN_00c5eb90())))
    {
        m_dc += *pfValue;
        saved = *pfValue;
        *pfValue = m_dc;
        ::FUN_00a5e1f0((::NiNode *)this, (intptr_t)(pfValue), (*(::NiUpdateData *)(b)), {});
        *pfValue = saved;
    }
}

namespace fnv_00c5e350 {
// Calls FUN_00c5e080, then if count_b8 > 0 or FUN_00c5eb90() adds *time to elapsed_dc and calls FUN_00a5dd70 with elapsed_dc, restoring *time.
// @fnv 0x00c5e350
void Target::UpdateTimed(float* time, int arg) {
    float savedTime;
    reinterpret_cast<::S_00c5e3d0 *>(this)->FUN_00c5e080();
    if (count_b8 > 0 || ((unsigned char)(reinterpret_cast<::EB90Obj *>(this)->FUN_00c5eb90()))) {
        elapsed_dc += *time;
        float previousTime, accumulatedTime, updateTime, deltaTime;
        savedTime = *time;
        *time = elapsed_dc;
        reinterpret_cast<::NiNode *>(this)->UpdateDownwardPass((*(::NiUpdateData *)(time)), arg);
        *time = savedTime;
    }
}
}  // namespace fnv_00c5e350

// /Ob1 inlines this. The comma reads the uninitialized parameter slot, then
// overwrites that return temporary with the real pointer. That is the
// never-written load into the slot below `this`.
__forceinline EB90Sub* eb90_pick(EB90Sub* b)
{
    return (b, b);
}

// @fnv 0x00c5eb90
bool EB90Obj::FUN_00c5eb90()
{
    unsigned int count = m_usElementCount;
    for (unsigned int i = 0; i < count; i++)
    {
        EB90Item* item3 = m_ppItems[i];
        if (item3)
            if ((int)eb90_pick(item3->m_pSub)->GetFlags() > 0)
                return true;
    }
    return false;
}

struct NiSmallValue
{
    int unk00;
};

struct NiBaseStandIn
{
    virtual void vfn_0000();
    int unk04;
    int unk08;
    ~NiBaseStandIn();
    NiBaseStandIn(NiSmallValue value);
};

struct NiMemberStandIn
{
    int unk00;
    NiMemberStandIn();
    ~NiMemberStandIn();
};

struct FUN_00c5ecf0 : public NiBaseStandIn
{
    virtual void vfn_0000();
    NiMemberStandIn m_0c;
    FUN_00c5ecf0();
};

inline NiSmallValue c5ecf0_base_arg()
{
    int a;
    int b;
    int c;
    return DAT_01204374;
}

// @fnv 0x00c5ecf0
FUN_00c5ecf0::FUN_00c5ecf0() : NiBaseStandIn(c5ecf0_base_arg()), m_0c()
{}

class F010Item
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
    virtual void v54(void* a);
};

class F010Cls
{
  public:
    int m_00, m_04, m_08, m_0c;
    F010Item** m_10;
    unsigned int m_14;
    unsigned int Count() const
    {
        return m_14;
    }
    F010Item*& Get(unsigned int i) const
    {
        return m_10[i];
    }
    bool FUN_00c5f010(void* a);
};

// @fnv 0x00c5f010
bool F010Cls::FUN_00c5f010(void* a)
{
    if (!reinterpret_cast<::MyOwner *>(this)->FUN_00a7b290((*(::NiStream *)(a))))
        return false;

    for (unsigned int i = 0; i < Count(); ++i)
    {

        Get(i)->v54(a);
    }
    return true;
}

namespace fnv_00c5f190 {
struct C5F190Elem
{
    int unk00;
    int unk04;
    const char* m_pcObjectName;
};

struct C5F190Global
{
    const char* m_pcName;
    int m_unk04;
};

struct C5F190Line
{
    int gap;
    void* pc;
};

struct C5F190Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    C5F190Elem** m_ppItems;
    unsigned int m_uiCount;

    // /Ob1 tries to inline this and refuses on size. The four locals stay
    // reserved in the caller; the call itself stays out of line.
    inline void FUN_00a7b580(NiTPrimitiveArray_unsigned_int_* out)
    {
        unsigned int w0, w1, w2, w3;
        w0 = (uintptr_t)out;
        w1 = w0 + 1;
        w2 = w1 + 4;
        w3 = w2 + 7;
        w0 = w3 + 10;
        w1 = w0 + 13;
        w2 = w1 + 16;
        w3 = w2 + 19;
        w0 = w3 + 22;
        w1 = w0 + 25;
        w2 = w1 + 28;
        w3 = w2 + 31;
        w0 = w3 + 34;
        w1 = w0 + 37;
        w2 = w1 + 40;
        w3 = w2 + 43;
        w0 = w3 + 46;
        w1 = w0 + 49;
        w2 = w1 + 52;
        w3 = w2 + 55;
        w0 = w3 + 58;
        w1 = w0 + 61;
        w2 = w1 + 64;
        w3 = w2 + 67;
        w0 = w3 + 70;
        w1 = w0 + 73;
        w2 = w1 + 76;
        w3 = w2 + 79;
        w0 = w3 + 82;
        w1 = w0 + 85;
        w2 = w1 + 88;
        w3 = w2 + 91;
        w0 = w3 + 94;
        w1 = w0 + 97;
        w2 = w1 + 100;
        w3 = w2 + 103;
        w0 = w3 + 106;
        w1 = w0 + 109;
        w2 = w1 + 112;
        w3 = w2 + 115;
        w0 = w3 + 118;
        w1 = w0 + 121;
        w2 = w1 + 124;
        w3 = w2 + 127;
        w0 = w3 + 130;
        w1 = w0 + 133;
        w2 = w1 + 136;
        w3 = w2 + 139;
        w0 = w3 + 142;
        w1 = w0 + 145;
        w2 = w1 + 148;
        w3 = w2 + 151;
        w0 = w3 + 154;
        w1 = w0 + 157;
        w2 = w1 + 160;
        w3 = w2 + 163;
        w0 = w3 + 166;
        w1 = w0 + 169;
        w2 = w1 + 172;
        w3 = w2 + 175;
        w0 = w3 + 178;
        w1 = w0 + 181;
        w2 = w1 + 184;
        w3 = w2 + 187;
        w0 = w3 + 190;
        w1 = w0 + 193;
        w2 = w1 + 196;
        w3 = w2 + 199;
        w0 = w3 + 202;
        w1 = w0 + 205;
        w2 = w1 + 208;
        w3 = w2 + 211;
        w0 = w3 + 214;
        w1 = w0 + 217;
        w2 = w1 + 220;
        w3 = w2 + 223;
        w0 = w3 + 226;
        w1 = w0 + 229;
        w2 = w1 + 232;
        w3 = w2 + 235;
        w0 = w3 + 238;
        (void)w0;
        (void)w1;
        (void)w2;
        (void)w3;
    }

    void FUN_00c5f190(NiTPrimitiveArray_unsigned_int_* out);
};


// @fnv 0x00c5f190
void C5F190Holder::FUN_00c5f190(NiTPrimitiveArray_unsigned_int_* out)
{
    C5F190Line line;
    unsigned int res;
    unsigned int elem;
    unsigned int cur;
    unsigned int it;
    reinterpret_cast<::ExtraDataStrings *>(this)->FUN_00a7b580((::StrArr *)(out));
    line.pc = (void*)((C5F190Global&)::g_01204378).m_pcName;
    res = (uintptr_t)((void *)(::FUN_00a7d330((const char *)(line.pc))));
    reinterpret_cast<::S_0060ba10 *>((out))->FUN_0096a610((intptr_t)&(res));
    for (it = 0; it < (cur = m_uiCount); it++)
    {
        C5F190Elem** ptr = m_ppItems + it;
        const char** row = &(*ptr)->m_pcObjectName;
        const char* pName = *row;
        elem = (uintptr_t)::fnv_00a7d5e0::FUN_00a7d5e0("ObjectName", pName);
        reinterpret_cast<::S_0060ba10 *>((out))->FUN_0096a610((intptr_t)&(elem));
    }
}
}

// namespace fnv_00c5f190

namespace fnv_00c5f240 {
struct S00c5f240_MM
{
    void* FUN_00aa3e40(unsigned int size);
};
extern char DAT_011f6238;
extern const char str_010c3194[];
extern char* DAT_0109b220;
char* __cdecl FUN_00a5b690(const char* name);

struct S00c5f240_Holder
{
    char* m_uiFilterValue;
    __forceinline S00c5f240_Holder(const char* text)
    {
        if (!text)
            m_uiFilterValue = DAT_0109b220;
        else
            m_uiFilterValue = ::NiGlobalStringTable::AddString(text);
    }
    static void FUN_00c5f240();
};


// @fnv 0x00c5f240
void S00c5f240_Holder::FUN_00c5f240()
{
    (*reinterpret_cast<::fnv_00c5f240::S00c5f240_Holder * *>(&::DAT_01204374)) = new S00c5f240_Holder(str_010c3194);
}
}


// namespace fnv_00c5f240

namespace fnv_00c5f5a0 {
struct SubQ
{
    char pad[0x10];
    void* m_10;
};
struct GeomQ
{
    char pad[0xbc];
    SubQ* m_pkSub;
    SubQ* GetSub()
    {
        return m_pkSub;
    }
};
struct AVQ
{
    virtual void v00(), v01(), v02();
    virtual void* AsNode();
    virtual void v04(), v05();
    virtual GeomQ* AsGeom();
};
struct AVPtrQ
{
    AVQ* m_pObject;
    operator AVQ*() const
    {
        AVQ* p = m_pObject;
        return p;
    }
};
struct ArrQ
{
    void* vtbl;
    AVPtrQ* m_pBase;
    unsigned short m_usMax;
    unsigned short m_usSize;
    AVPtrQ& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
struct NodeQ
{
    char pad[0x9c];
    ArrQ m_kChildList;
};
struct FUN_00c5f5a0_cls
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(),
        v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44(), v45(),
        v46(), v47(), v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v60(), v61(),
        v62(), v63();
    virtual void Apply(void* pNode, void* pVal);
    void FUN_00c5f5a0(NodeQ* pNode, void* pVal);
};
// @fnv 0x00c5f5a0
void FUN_00c5f5a0_cls::FUN_00c5f5a0(NodeQ* pParent, void* pVal)
{
    if (pParent && pVal)
    {
        for (unsigned int i = 0; i < pParent->m_kChildList.m_usSize; i++)
        {
            AVQ* pChild = pParent->m_kChildList.GetAt(i);
            if (pChild)
            {
                void* pNode = pChild->AsNode();
                if (pNode)
                    Apply(pNode, pVal);
                else
                {
                    GeomQ* pGeom = pChild->AsGeom();
                    if (pGeom && pGeom->GetSub())
                        pGeom->GetSub()->m_10 = pVal;
                }
            }
        }
    }
}
}

// namespace fnv_00c5f5a0



struct S00c5fc70_Source;

void* __cdecl FUN_00a5b690(S00c5fc70_Source* p);

class S00c5fc70_FixedString
{
  public:
    S00c5fc70_FixedString(S00c5fc70_Source* pSource)
    {
        if (pSource == 0)
            m_handle = DAT_0109b220;
        else
            m_handle = ((void *)(::NiGlobalStringTable::AddString((const char *)(pSource))));
    }
    ~S00c5fc70_FixedString()
    {
        if (m_handle == DAT_0109b220)
            return;
        long* pRef = (long*)((char*)m_handle - 8);
        InterlockedDecrement(pRef);
    }
    void* m_handle;
};

class S00c5fc70_Object
{
  public:
    S00c5fc70_Object* FUN_00c5fc70(S00c5fc70_Source* pSource, float f);
    void* m_vt;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_f18;
};

// @fnv 0x00c5fc70
S00c5fc70_Object* S00c5fc70_Object::FUN_00c5fc70(S00c5fc70_Source* pSource, float f)
{
    reinterpret_cast<::ParticleModifier *>(this)->FUN_00c316a0((char *volatile *)&(const ::S00c5fc70_FixedString &)(S00c5fc70_FixedString(pSource)), 0x9c4);
    m_vt = &DAT_010c32c4;
    m_f18 = f;
    return this;
}

namespace fnv_00c4ecf0 {
struct D3DQuery_Stub;

struct D3DDevice_Stub
{
    virtual long v000();
    virtual long v004();
    virtual long v008();
    virtual long v00c();
    virtual long v010();
    virtual long v014();
    virtual long v018();
    virtual long v01c();
    virtual long v020();
    virtual long v024();
    virtual long v028();
    virtual long v02c();
    virtual long v030();
    virtual long v034();
    virtual long v038();
    virtual long v03c();
    virtual long v040();
    virtual long v044();
    virtual long v048();
    virtual long v04c();
    virtual long v050();
    virtual long v054();
    virtual long v058();
    virtual long v05c();
    virtual long v060();
    virtual long v064();
    virtual long v068();
    virtual long v06c();
    virtual long v070();
    virtual long v074();
    virtual long v078();
    virtual long v07c();
    virtual long v080();
    virtual long v084();
    virtual long v088();
    virtual long v08c();
    virtual long v090();
    virtual long v094();
    virtual long v098();
    virtual long v09c();
    virtual long v0a0();
    virtual long v0a4();
    virtual long v0a8();
    virtual long v0ac();
    virtual long v0b0();
    virtual long v0b4();
    virtual long v0b8();
    virtual long v0bc();
    virtual long v0c0();
    virtual long v0c4();
    virtual long v0c8();
    virtual long v0cc();
    virtual long v0d0();
    virtual long v0d4();
    virtual long v0d8();
    virtual long v0dc();
    virtual long v0e0();
    virtual long v0e4();
    virtual long v0e8();
    virtual long v0ec();
    virtual long v0f0();
    virtual long v0f4();
    virtual long v0f8();
    virtual long v0fc();
    virtual long v100();
    virtual long v104();
    virtual long v108();
    virtual long v10c();
    virtual long v110();
    virtual long v114();
    virtual long v118();
    virtual long v11c();
    virtual long v120();
    virtual long v124();
    virtual long v128();
    virtual long v12c();
    virtual long v130();
    virtual long v134();
    virtual long v138();
    virtual long v13c();
    virtual long v140();
    virtual long v144();
    virtual long v148();
    virtual long v14c();
    virtual long v150();
    virtual long v154();
    virtual long v158();
    virtual long v15c();
    virtual long v160();
    virtual long v164();
    virtual long v168();
    virtual long v16c();
    virtual long v170();
    virtual long v174();
    virtual long v178();
    virtual long v17c();
    virtual long v180();
    virtual long v184();
    virtual long v188();
    virtual long v18c();
    virtual long v190();
    virtual long v194();
    virtual long v198();
    virtual long v19c();
    virtual long v1a0();
    virtual long v1a4();
    virtual long v1a8();
    virtual long v1ac();
    virtual long v1b0();
    virtual long v1b4();
    virtual long v1b8();
    virtual long v1bc();
    virtual long v1c0();
    virtual long v1c4();
    virtual long v1c8();
    virtual long v1cc();
    virtual long v1d0();
    virtual long v1d4();
    virtual long CreateQuery(int eType, D3DQuery_Stub** ppQuery);
};

struct NiDX9Renderer_Stub
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
    D3DDevice_Stub* m_pDirect3DDevice;
    D3DDevice_Stub* GetD3DDevice()
    {
        return m_pDirect3DDevice;
    }
};


class OcclusionQuery
{
  public:
    D3DQuery_Stub* m_pkQuery;
    OcclusionQuery();
};

// @fnv 0x00c4ecf0
OcclusionQuery::OcclusionQuery()
{
    m_pkQuery = 0;
    NiDX9Renderer_Stub* pkRenderer = (*reinterpret_cast<::fnv_00c4ecf0::NiDX9Renderer_Stub * *>(&::NiRenderer::ms_pRenderer));
    pkRenderer->GetD3DDevice()->CreateQuery(9, &m_pkQuery);
}
}

// namespace fnv_00c4ecf0

unsigned int __cdecl FUN_0040fc90();

class RecursiveSpinLock
{
  public:
    volatile long owner;
    unsigned int recursion;
    void Lock(const char*)
    {
        unsigned int thread = FUN_0040fc90();
        if (owner == (long)thread)
            ++recursion;
        else
        {
            unsigned int attempts = 0;
            while (FUN_0043b460(&owner, 0, thread))
            {
                ++attempts;
                FUN_0040fca0(attempts > 10000 ? 1 : 0);
            }
            FUN_0040fbe0();
            recursion = 1;
        }
    }
    void Unlock()
    {
        FUN_0040fbe0();
        if (--recursion == 0)
            owner = 0;
    }
public:
    void FUN_0040fba0();
};

template <> inline void NiTPointerAllocator<unsigned int>::Deallocate(void* pointer)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(ms_kPoolState))->FUN_0040fbf0((char *)(0));
    LinkedListEntry* node = static_cast<LinkedListEntry*>(pointer);
    node->m_pUserData = 0;
    node->m_pkNext = ms_pFreeList;
    ms_pFreeList = node;
    reinterpret_cast<::RecursiveSpinLock *>(&(ms_kPoolState))->FUN_0040fba0();
}

struct MyNode
{
    virtual void vfn_0000();
    virtual void DeleteThis();
    volatile long refs;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
        {
            DeleteThis();
        }
    }
};

template <> class NiPointer<MyNode>
{
  public:
    MyNode* m_pObject;
    __forceinline NiPointer() : m_pObject(0)
    {}
    __forceinline NiPointer(MyNode* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline NiPointer(const NiPointer<MyNode>& other) : m_pObject(other.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer<MyNode>& operator=(MyNode* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct PointerListPop_Class : NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<MyNode> >
{
    NiPointer<MyNode> FUN_00c5c160();
};

// @fnv 0x00c5c160
NiPointer<MyNode> PointerListPop_Class::FUN_00c5c160()
{
    NiTListItem<NiPointer<MyNode> >* pkNode = this->m_pkHead;
    this->m_pkHead = this->m_pkHead->m_pkNext;
    if (this->m_pkHead)
        this->m_pkHead->m_pkPrev = 0;
    else
        this->m_pkTail = 0;

    NiPointer<MyNode> element = pkNode->m_element;
    pkNode->m_element = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>(&(this->m_kItemCount))->FUN_0045cee0(pkNode);
    this->m_kItemCount.m_uiCount--;
    return element;
}

struct Pool41f40_obj : S_0044dd60
{
    int unk00;
    int unk04;
    long m_iRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_iRefCount);
    }
};

struct Pool41f40_ptr
{
    Pool41f40_obj* m_pObject;
    Pool41f40_ptr& operator=(Pool41f40_obj* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(m_pObject));
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct Pool41f40_node
{
    int unk00;
    int unk04;
    union
    {
        Pool41f40_ptr m_pReferencedObject;
        Pool41f40_node* m_pkNext;
    };
};

struct Pool41f40_owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_uiMaxFree;
};

struct Pool41f40_cls
{
    Pool41f40_owner* m_pkOwnerManager;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Pool41f40_node* m_pkFreeList;
    unsigned int m_uiFreeCount;
    Pool41f40_node* GetFreeList()
    {
        Pool41f40_node* p = m_pkFreeList;
        return p;
    }
    unsigned int GetMaxFree()
    {
        unsigned int u = m_pkOwnerManager->m_uiMaxFree;
        return u;
    }
    void FUN_00c42960();
    void FUN_00c41f40(Pool41f40_node* pkNode);
};

static __forceinline void Dead23()
{
    int aiD[23];
}

// @fnv 0x00c41f40
void Pool41f40_cls::FUN_00c41f40(Pool41f40_node* pkNode)
{
    int iA, iB, iC;
    pkNode->m_pReferencedObject = 0;
    pkNode->m_pkNext = GetFreeList();
    m_pkFreeList = pkNode;
    m_uiFreeCount++;
    if (m_uiFreeCount == GetMaxFree())
        reinterpret_cast<::S_00c42960 *>(this)->FUN_00c42960();
    Dead23();
}

struct FUN_00a7b2e0
{
    int unk04;
    int unk08;
    FUN_00a7b2e0();
    virtual ~FUN_00a7b2e0();
};

struct Mid_c42f70 : FUN_00a7b2e0
{
    int m_0c;
    Mid_c42f70()
    {
        m_0c = 0;
    }
    virtual ~Mid_c42f70()
    {}
};

struct Node_c42f70 : Mid_c42f70
{
    Node_c42f70();
    virtual ~Node_c42f70();
};

// @fnv 0x00c42f70
Node_c42f70::Node_c42f70()
{
    reinterpret_cast<::NiAVObject *>(this)->FUN_00c43470();
}

class CloneObj
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
    virtual CloneObj* MakeClone(unsigned int cloning);
    volatile long m_uiRefCount;
    void DeleteThis();
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

struct CloneOwner
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
    NiPointer<CloneObj> m_ac;
    unsigned int m_b0;
    void SetB0(unsigned int v)
    {
        m_b0 = v;
    }
    void FUN_00c46c30(CloneOwner* a1, unsigned int a2);
};

// Allocates a new A51BF0Base, initialises it from a via FUN_00c46c30, and returns the new object.
// @fnv 0x00c46ba0
A51BF0Base* A51BF0Base::FUN_00c46ba0(int aiValue)
{
    A51BF0Base* copy = new A51BF0Base;
    reinterpret_cast<::CloneOwner *>(this)->FUN_00c46c30((::CloneOwner *)(copy), aiValue);
    return copy;
}

// @fnv 0x00c46c30
void CloneOwner::FUN_00c46c30(CloneOwner* pDest, unsigned int kCloning)
{
    reinterpret_cast<::FUN_00c5fb60_class *>(this)->ForwardToBase((::S_00a953b0_Node *)(pDest), (void *)(kCloning));
    CloneObj* pNewInstance = m_ac->MakeClone(kCloning);
    pDest->m_ac = pNewInstance;
    pDest->SetB0(m_b0);
}

namespace fnv_00c44980 {
extern unsigned int DAT_011af714[];
extern char DAT_010c1ad4[];
extern int DAT_010c1af0[];
unsigned long RunThreadProc(void*);

struct ThreadCriticalSection : CRITICAL_SECTION
{
    ThreadCriticalSection()
    {
        InitializeCriticalSection(this);
    }
    ~ThreadCriticalSection();
};
class BSThread
{
  public:
    virtual ~BSThread();
    ThreadCriticalSection section;
    void* handle;
    void* parentHandle;
    unsigned long threadId, parentId;
    bool running;
    BSThread() : handle(0), parentHandle(0), threadId(0), parentId(0), running(false)
    {}
    void FUN_00aa6430(int stackSize, const char* name, bool suspended)
    {
        if (handle)
            return;
        parentHandle = GetCurrentThread();
        parentId = GetCurrentThreadId();
        handle = CreateThread(0, stackSize, RunThreadProc, this, suspended ? 4 : 0, &threadId);
        EnterCriticalSection(&section);
        reinterpret_cast<::BSThread *>(this)->SetThreadPriority(-1);
        running = true;
        unsigned long previousSuspendCount = ResumeThread(handle);
        LeaveCriticalSection(&section);
    }
};
struct ThreadSemaphore
{
    long count;
    void* handle;
    long limit;
    ThreadSemaphore();
    ~ThreadSemaphore();
};
struct BSLinearTaskThread : BSThread
{
    ThreadSemaphore request, completion;
    bool stopping;
    BSLinearTaskThread() : stopping(false)
    {}
    virtual ~BSLinearTaskThread();
};
struct FUN_00c44980;
struct WorkerThread : BSLinearTaskThread
{
    FUN_00c44980* manager;
    int unk50, unk54, unk58;
    virtual ~WorkerThread();
    WorkerThread(FUN_00c44980* owner)
    {
        manager = owner;
    }
};
struct FUN_00c44980
{
    WorkerThread** threads;
    int unk04;
    int unk08;
    bool unk0c;
    FUN_00c44980();
};
// @fnv 0x00c44980
FUN_00c44980::FUN_00c44980()
{
    threads = 0;
    unk04 = 0;
    unk08 = 0;
    unk0c = false;
    if (1)
    {
        threads = new WorkerThread*[1];
        for (unsigned int i = 0; i < 1; ++i)
        {
            threads[i] = new WorkerThread(this);
            char name[260];
            ::FUN_00406d00(name, 260, DAT_010c1ad4, DAT_011af714[i]);
            threads[i]->FUN_00aa6430(0x8000, name, false);
            reinterpret_cast<::BSThread *>((threads[i]))->SetName(name);
            reinterpret_cast<::BSThread *>((threads[i]))->SetSchedulingPriority(DAT_011af714[i]);
            reinterpret_cast<::BSThread *>((threads[i]))->SetThreadPriority(15);
        }
    }
}
}

// namespace fnv_00c44980


struct SyncC44
{
    volatile long count;
    void* handle;
};

// 8-byte local: only the pointer is stored. The second dword is the unreferenced
// slot at [ebp-0x14]; VC9 /Od places this struct at [ebp-0x18].
struct SyncPtrC44
{
    SyncC44* p;
    int unk04;
};

struct ObjC44
{
    virtual ~ObjC44();
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
    SyncC44 sync;
    __forceinline void WaitDec()
    {
        SyncPtrC44 b;
        b.p = &sync;
        WaitForSingleObject(b.p->handle, 0xFFFFFFFF);
        InterlockedDecrement(&b.p->count);
    }
};

struct OwnerC44
{
    ObjC44** unk00;
    void FUN_00c44b70();
};

// @fnv 0x00c44b70
void OwnerC44::FUN_00c44b70()
{
    for (unsigned int i = 0; i < 1; ++i)
    {
        reinterpret_cast<::fnv_008c74b0::FUN_008c74b0_shell *>((unk00[i]))->SignalThread();
        unk00[i]->WaitDec();
        delete unk00[i];
        unk00[i] = 0;
    }
    delete[] unk00;
}

namespace fnv_00c45b20 {
struct ResizeObject
{
    virtual void first();
    virtual void destroy();
    volatile long refs;
    __forceinline void retain()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void release()
    {
        if (!InterlockedDecrement(&refs))
            destroy();
    }
};
struct ResizePointer
{
    ResizeObject* object;
    __forceinline ResizePointer(ResizeObject* value = 0)
    {
        object = value;
        if (object)
            object->retain();
    }
    __forceinline ~ResizePointer()
    {
        if (object)
            object->release();
    }
    __forceinline bool operator!=(const ResizePointer& other) const
    {
        return object != other.object;
    }
    ResizePointer& assign(const ResizePointer& other)
    {
        if (object != other.object)
        {
            if (object)
                object->release();
            object = other.object;
            if (object)
                object->retain();
        }
        return *this;
    }
};
inline ResizePointer* __cdecl allocatePointers(unsigned int count)
{
    return new ResizePointer[count];
}
inline void freePointers(ResizePointer* data)
{
    delete[] data;
}
struct ResizeArray
{
    int unk00;
    ResizePointer* data;
    unsigned short capacity, size, count, growth;
    void FUN_00c45b20(unsigned int newSize);
};
// @fnv 0x00c45b20
void ResizeArray::FUN_00c45b20(unsigned int newSize)
{
    if (newSize == capacity)
        return;
    unsigned short index3;
    if (newSize < size)
    {
        for (index3 = (unsigned short)newSize; index3 < size; index3++)
        {
            if (data[index3] != ResizePointer())
            {
                reinterpret_cast<::FUN_00c46270_Class *>(&(data[index3]))->AssignRefCounted((const ::FUN_00c46270_Class &)((const ::fnv_00c45b20::ResizePointer &)(ResizePointer())));
                count--;
            }
        }
        size = (unsigned short)newSize;
    }
    ResizePointer* oldData = data;
    capacity = (unsigned short)newSize;
    if (newSize > 0)
    {
        data = ((::fnv_00c45b20::ResizePointer *)(::FUN_00c46170(capacity)));
        for (index3 = 0; index3 < size; index3++)
            reinterpret_cast<::FUN_00c46270_Class *>(&(data[index3]))->AssignRefCounted((const ::FUN_00c46270_Class &)(oldData[index3]));
        for (index3 = size; index3 < capacity; index3++)
            reinterpret_cast<::FUN_00c46270_Class *>(&(data[index3]))->AssignRefCounted((const ::FUN_00c46270_Class &)((const ::fnv_00c45b20::ResizePointer &)(ResizePointer())));
    }
    else
        data = 0;
    freePointers(oldData);
}
}

namespace fnv_00c45a80 {
// If the string's length exceeds 100, resizes it to a maximum length of 100 via FUN_00c45b20.
// @fnv 0x00c45a80
void TruncateStringToMaxLength()
{
    ScratchBuffer scratch;
    if ((unsigned int)::fnv_00c45ae0::DAT_01202e2a > 100u)
    {
        reinterpret_cast<::fnv_00c45b20::ResizeArray *>(&((*reinterpret_cast<::fnv_00c45a80::FUN_00c45a80_cls *>(&::DAT_01202e20))))->FUN_00c45b20(100);
    }
}
}  // namespace fnv_00c45a80

namespace fnv_00c45ae0 {
// If the global DAT_01202e2a is less than value, calls FUN_00c45b20 on DAT_01202e20 with value.
// @fnv 0x00c45ae0
void __cdecl FUN_00c45ae0(unsigned int value)
{
    FUN_00c45ae0_LocalState localState;

    if (DAT_01202e2a < value) {
        reinterpret_cast<::fnv_00c45b20::ResizeArray *>(&((*reinterpret_cast<::fnv_00c45ae0::FUN_00c45b20_Class *>(&::DAT_01202e20))))->FUN_00c45b20(value);
    }
}
}  // namespace fnv_00c45ae0

// Appends uiElement to the array, growing it by m_usGrowBy if full, and returns the index where it was stored.
// @fnv 0x00c45e00
unsigned int FUN_00c45e00_class::AppendElement(uintptr_t uiElement)
{
    struct FUN_00c45e00_pad
    {
        int m00; int m04; int m08; int m0c; int m10; int m14;
        int m18; int m1c; int m20; int m24; int m28; int m2c;
        int m30; int m34; int m38; int m3c; int m40; int m44;
        int m48; int m4c; int m50; int m54; int m58; int m5c;
    };
    FUN_00c45e00_pad kPad;
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
        {
            reinterpret_cast<::fnv_00c45b20::ResizeArray *>(this)->FUN_00c45b20(m_usGrowBy + uiIndex);
        }
        reinterpret_cast<::Target462f0 *>(this)->SetSlot(uiIndex, (*(const ::Slot462f0 *)(uiElement)));
        return uiIndex;
    }
}

// namespace fnv_00c45b20

namespace fnv_00c46970 {


struct SpawnedBase
{
    SpawnedBase();
    ~SpawnedBase();
};

struct NodeObj
{
    void* vtbl;
    volatile long refs;
    __forceinline void AcquireReference()
    {
        InterlockedIncrement(&refs);
    }
};

struct SpawnedHolder
{
    NodeObj* m_p;
    __forceinline SpawnedHolder()
    {
        m_p = 0;
        if (m_p)
            m_p->AcquireReference();
    }
    ~SpawnedHolder();
    void FUN_0066b0d0(int flag);
};

struct FUN_00c46970 : SpawnedBase
{
    void* m_vtbl;
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
    int m_30;
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
    SpawnedHolder m_ac;
    __forceinline void SetFormFlag(int flag, bool set)
    {
        int maskHome;
        int setHome;
        if (set)
            m_30 |= flag;
        else
            m_30 &= ~flag;
    }
    FUN_00c46970();
};

// @fnv 0x00c46970
FUN_00c46970::FUN_00c46970() : SpawnedBase(), m_vtbl(&DAT_010c1d14)
{
    m_ac.FUN_0066b0d0(0);
    SetFormFlag(0x800, true);
}
}

// namespace fnv_00c46970

namespace fnv_00c46a40 {
extern "C" void(* FUN_00fdf1c0)(void*);
extern "C" long(* FUN_00fdf1c4)(void*);

struct FUN_00c5f680
{
    FUN_00c5f680(int a, int b);
    ~FUN_00c5f680();
};
FUN_00c5f680::~FUN_00c5f680()
{}

struct NodeRef
{
    virtual void v0();
    virtual void v1();
    __forceinline void IncRefCount()
    {
        FUN_00fdf1c0((char*)this + 4);
    }
    __forceinline void DecRefCount()
    {
        if (FUN_00fdf1c4((char*)this + 4) == 0)
            v1();
    }
};

template <class T> class ObjPtr
{
  public:
    T* m_pObject;
    __forceinline ObjPtr(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~ObjPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    inline ObjPtr<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct FUN_00c46a40 : FUN_00c5f680
{
    int* vfptr;
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
    ObjPtr<NodeRef> node;
    FUN_00c46a40(int a);
};

// @fnv 0x00c46a40
FUN_00c46a40::FUN_00c46a40(int a) : FUN_00c5f680(a, 1), vfptr(&::fnv_00c46970::DAT_010c1d14)
{
    node = 0;
}
}

// namespace fnv_00c46a40

namespace fnv_00c50c30 {
static __forceinline void fnvDead2()
{
    int aiDead[2];
}
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        fnvDead2();
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};
template <class T> class SmartPtr
{
  public:
    T* m_pObject;
    SmartPtr(T* object = 0)
    {
        m_pObject = object;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SmartPtr()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    bool operator!=(T* object) const
    {
        return m_pObject != object;
    }
};
struct NodeC4 : NiRefObject
{
    int GetIndex()
    {
        return unkC4;
    }
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
};
struct SpOwner
{
    void FUN_006e5cc0(SmartPtr<NodeC4>* p);
};
struct C50c30
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
    int* unkAC;
    void FUN_00c50c30(int a, SpOwner* b);
};
// @fnv 0x00c50c30
void C50c30::FUN_00c50c30(int a, SpOwner* b)
{
    SmartPtr<NodeC4> m_pController;
    reinterpret_cast<::fnv_00a5e780::NodeStandIn *>(this)->FUN_00a5e780((::fnv_00a5e780::RefObj *)(a), (*(::fnv_00a5e780::RefPtr *)(&m_pController)));
    if (m_pController != 0)
    {
        NodeC4* pNode = m_pController;
        unkAC[pNode->GetIndex()] = -1;
    }
    b->FUN_006e5cc0(&m_pController);
}
}

// namespace fnv_00c50c30

namespace fnv_00c52d80 {
extern int DAT_01030f8c;
struct MapItem
{
    MapItem* next;
    unsigned int key;
    unsigned int value;
};
struct MapVTable
{
    void(* destroy)(void*);
    unsigned int(* hash)(const void*, unsigned int);
};
struct FUN_00a54060_class
{
};
struct ArrA : FUN_00a54060_class
{
    int* vtable;
    unsigned int count;
    unsigned int* data;
    unsigned int cap;
    __forceinline ArrA(unsigned int n)
    {
        reinterpret_cast<::FUN_00a54060_class *>(this)->InitBuffer(n);
        vtable = &::DAT_0109a284;
    }
    ~ArrA();
    __forceinline unsigned int First() const
    {
        for (unsigned int i = 0; i < count; ++i)
            if (data[i])
                return data[i];
        return 0;
    }
    inline void AdvanceToNextEntry(unsigned int* cur, unsigned int* idxOut, unsigned int* valOut)
    {
        MapItem* item = (MapItem*)*cur;
        *idxOut = item->key;
        *valOut = item->value;
        if (item->next)
            *cur = (uintptr_t)item->next;
        else
        {
            unsigned int bucket = ((MapVTable*)vtable)->hash(this, item->key) + 1;
            for (; bucket < count; ++bucket)
                if (data[bucket])
                {
                    *cur = data[bucket];
                    return;
                }
            *cur = 0;
        }
    }
};
struct FUN_0057c960
{
    int* vtable;
    unsigned int count;
    unsigned int* data;
    unsigned int cap;
    FUN_0057c960(int n);
};
struct ArrB : FUN_0057c960
{
    __forceinline ArrB(int n) : FUN_0057c960(n)
    {
        vtable = &DAT_01030f8c;
    }
    ~ArrB();
    __forceinline unsigned int First() const
    {
        for (unsigned int i = 0; i < count; ++i)
            if (data[i])
                return data[i];
        return 0;
    }
    inline void GetNextEntry(unsigned int* cur, unsigned int* out, unsigned char* outB)
    {
        MapItem* item = (MapItem*)*cur;
        *out = item->key;
        *outB = (unsigned char)item->value;
        if (item->next)
            *cur = (uintptr_t)item->next;
        else
        {
            unsigned int bucket = ((MapVTable*)vtable)->hash(this, item->key) + 1;
            for (; bucket < count; ++bucket)
                if (data[bucket])
                {
                    *cur = data[bucket];
                    return;
                }
            *cur = 0;
        }
    }
};
struct LinkAllocator
{
    void* FUN_00aa3e40(unsigned int);
};
struct LinkSet
{
    int* data;
    unsigned int count;
    unsigned int capacity;
    __forceinline LinkSet(int n)
    {
        new ((void *)this) ::FUN_00a54110(n);
    }
};
struct SubObj
{
    int* vtable;
    LinkSet** data;
    unsigned short capacity, high, used, grow;
    inline void FUN_00a90180(unsigned int n);
};
void* __cdecl FUN_00aa1070(unsigned int);
void __cdecl FUN_00aa10f0(void*);
inline void SubObj::FUN_00a90180(unsigned int n)
{
    if (n == capacity)
        return;
    if (n < high)
    {
        for (unsigned short i = (unsigned short)n; i < high; ++i)
        {
            if (data[i])
            {
                data[i] = 0;
                --used;
            }
        }
        high = (unsigned short)n;
    }
    LinkSet** oldData = data;
    capacity = (unsigned short)n;
    if (n > 0)
    {
        data = (LinkSet**)FUN_00aa1070(capacity * sizeof(LinkSet*));
        unsigned short i;
        for (i = 0; i < high; ++i)
            data[i] = oldData[i];
        for (i = high; i < capacity; ++i)
            data[i] = 0;
    }
    else
        data = 0;
    FUN_00aa10f0(oldData);
}
struct NiBSBoneLODController
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    unsigned int f38;
    SubObj sub;
    void FUN_00c53030(Node_cls* a, ArrA* b, ArrB* c);
    bool FUN_00c52d80(Node_cls* arg);
};
// @fnv 0x00c52d80
bool NiBSBoneLODController::FUN_00c52d80(Node_cls* arg)
{
    reinterpret_cast<::OwnerAB *>(this)->FUN_00c52880();
    ArrA a9(0x25);
    ArrB b2(0x25);
    FUN_00c53030(arg, &a9, &b2);
    unsigned int maxVal = 0;
    unsigned int cur5 = b2.First();
    unsigned int i5;
    while (cur5)
    {
        unsigned int kOut1;
        unsigned char outB6;
        reinterpret_cast<::FUN_00a53c90_cls *>(&(b2))->GetNextEntry((::FUN_00a53c90_Node **)(unsigned int *)(&cur5), &kOut1, &outB6);
        if (kOut1 > maxVal)
            maxVal = kOut1;
    }
    f38 = maxVal + 1;
    reinterpret_cast<::FUN_00a41520_cls *>(&(sub))->FUN_00a90180(f38);
    for (i5 = 0; i5 < f38; ++i5)
    {
        reinterpret_cast<::FUN_00a41520_cls *>(&(sub))->FUN_00ba3aa0(i5, (::KeyPair **)&(const ::fnv_00c52d80::LinkSet *const &)(0));
    }
    cur5 = a9.First();
    while (cur5)
    {
        unsigned int idxOutVal;
        unsigned int valOut8;
        reinterpret_cast<::Tbl00b57f20 *>(&(a9))->AdvanceToNextEntry((::Ent00b57f20 **)(unsigned int *)(&cur5), (int *)(unsigned int *)(&idxOutVal), (int *)(unsigned int *)(&valOut8));
        LinkSet* entry = sub.data[valOut8];
        if (!entry)
        {
            entry = new LinkSet(0);
            reinterpret_cast<::FUN_00a41520_cls *>(&(sub))->FUN_00ba3aa0(valOut8, (::KeyPair **)&(entry));
        }
        reinterpret_cast<::NiStreamLinkIDSetShell *>((entry))->AppendLinkID(&idxOutVal);
    }
    unsigned int out5 = 0;
    reinterpret_cast<::FUN_00c53280_cls *>(this)->UpdateMaxValue(arg, (::ItemCtx_cls *)(::fnv_00c52d80::ArrA *)(&a9), &out5);
    reinterpret_cast<::Q52Obj *>(this)->FUN_00c52960((uintptr_t)((void*)-1));
    return true;
}
}

// namespace fnv_00c52d80

namespace fnv_00c53030 {


struct TreeNode
{
    virtual void First();
    virtual void Second();
    virtual const NiRTTI* GetTypeList();
    virtual void* IsActive();
    int unk04;
    int unk08;
    const char* descriptor;
    TreeNode** elements;
    unsigned short elementCount;
    unsigned short unk16;
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
    TreeNode** children;
    unsigned short unka4;
    unsigned short childCount;
};

struct MemoryMgr
{
    void* FUN_00aa3e40(unsigned int);
};
extern "C" char DAT_011f6238;

struct CollectionSink
{
};
struct ValueSink
{
};

// Two leading bytes keep the count at +2, which is where this frame spills elementCount.
struct ElementCount
{
    char align0;
    char align1;
    unsigned short value;
};

struct FUN_00c53030_Shell
{
    void FUN_00c53030(TreeNode* group, CollectionSink* collector, ValueSink* values);
};

// /Ob1 inline. return stores the caller bool and jumps once to the ternary.
__forceinline void IsBoneLODExtra(TreeNode* node, const NiRTTI*& inner, bool& prior)
{
    inner = node->GetTypeList();
    while (inner)
    {
        if (inner == &(*reinterpret_cast<::NiRTTI *>(&::g_011f4a38)))
        {
            prior = true;
            return;
        }
        inner = inner->m_pBaseRTTI;
    }
    prior = false;
}

// @fnv 0x00c53030
void FUN_00c53030_Shell::FUN_00c53030(TreeNode* group, CollectionSink* collector, ValueSink* values)
{
    TreeNode* component;
    unsigned int b;
    {
        TreeNode* descriptorFromObject;
        {
            const char* kIter;
            char* slot;
            char* child;
            {
                char* token;
                unsigned long loadedChild;
                unsigned int s;
                {
                    TreeNode* count;
                    char* allocatedBuffer;
                    char* freedBuffer5;
                    ElementCount lod;
                    const NiRTTI* inner;
                    bool prior;
                    const char* z;
                    unsigned int edge, feed, fire, frac, head, heap;
                    TreeNode** state5;
                    TreeNode* length4;

                    for (b = 0; lod.value = group->elementCount, b < lod.value; b++)
                    {
                        component = group->elements[(unsigned short)b];
                        if (0 == component)
                        {
                            descriptorFromObject = 0;
                        }
                        else
                        {
                            IsBoneLODExtra(component, inner, prior);
                            descriptorFromObject = prior ? component : 0;
                        }
                        if (descriptorFromObject)
                        {
                            z = descriptorFromObject->descriptor;
                            kIter = z;
                            if (kIter && strstr(kIter, "BSBoneLOD#Bone#"))
                            {
                                loadedChild = strlen(kIter) + 1;
                                allocatedBuffer = (char*)reinterpret_cast<::MemoryManagerStandIn *>((((MemoryMgr*)&DAT_011f6238)))->FUN_00aa3e40(loadedChild);
                                child = allocatedBuffer;
                                fnv::crt::strcpy_s(child, loadedChild, kIter);
                                token = strtok_s(child, "#", &slot);
                                if (token && !strcmp(token, "BSBoneLOD"))
                                {
                                    token = strtok_s(0, "#", &slot);
                                    if (token && !strcmp(token, "Bone"))
                                    {
                                        token = strtok_s(0, "#", &slot);
                                        if (token)
                                        {
                                            s = atoi(token);
                                            reinterpret_cast<::HashTableBase *>((collector))->InsertOrUpdate((uintptr_t)(group), s);
                                            reinterpret_cast<::FUN_0084d310_class *>((values))->FUN_0084d310(s, true);
                                        }
                                    }
                                }
                                freedBuffer5 = child;
                                reinterpret_cast<::FNV_MemoryManager *>((((MemoryMgr*)&DAT_011f6238)))->FUN_00aa4060(freedBuffer5);
                                break;
                            }
                        }
                    }

                    for (b = 0; b < group->childCount; b++)
                    {
                        state5 = &group->children[b];
                        length4 = *state5;
                        count = length4;
                        if (count && count->IsActive())
                        {
                            FUN_00c53030(count, collector, values);
                        }
                    }
                }
            }
        }
    }
}
}

// namespace fnv_00c53030

namespace fnv_00c55170 {

struct AvCaller
{
};

// Inlined under /Ob1. GetRTTI stays outside so the virtual call keeps the
// caller's registers; kind and node are caller locals.
inline void WalkRTTI(const NiRTTI*& kind, const NiRTTI* target, bool& node)
{
    while (kind)
    {
        if (kind == target)
        {
            node = true;
            return;
        }
        kind = kind->m_pBaseRTTI;
    }
    node = false;
}

// @fnv 0x00c55170
NiExtraDataX* __cdecl FUN_00c55170(AvCaller* a)
{
    NiExtraDataX* result = 0;
    if (a)
    {
        NiFixedString* name = (NiFixedString*)(*reinterpret_cast<int *>(&::g_pkString_c55));
        NiExtraDataX* extra = ((::NiExtraDataX *)(reinterpret_cast<::NiAVObject *>((a))->GetExtraData(*name)));
        if (!extra)
        {
            result = 0;
        }
        else
        {
            const NiRTTI* kind = ((NiAVObjectStub*)extra)->GetRTTI();
            bool node;
            WalkRTTI(kind, (const NiRTTI*)&(*reinterpret_cast<void * *>(&::g_012031e8)), node);
            result = node ? extra : 0;
        }
    }
    return result;
}
}

namespace fnv_00c57d70 {

extern float DAT_010c2c34;
extern double DAT_01011590;
extern char DAT_010c2c98[];
double __cdecl FUN_00ec9f30(double);
double __cdecl FUN_00eca060(double);
inline float TrigCos(float a)
{
    return (float)FUN_00ec9f30((double)a);
}
inline float TrigSin(float a)
{
    return (float)FUN_00eca060((double)a);
}
struct Vec3
{
    float x, y, z;
    Vec3()
    {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
struct Vec4
{
    float x, y, z, w;
    Vec4() : x(0), y(0), z(0), w(0)
    {}
};
struct TESObjectDoorController
{
};
char* __cdecl FUN_00a5b690(const char*);
extern char* DAT_0109b220;
struct NiFixedString
{
    char* m_p;
    NiFixedString(const char* text)
    {
        if (!text)
            m_p = DAT_0109b220;
        else
            m_p = ::NiGlobalStringTable::AddString(text);
    }
    ~NiFixedString()
    {
        if (m_p == DAT_0109b220)
            return;
        volatile long* count = reinterpret_cast<volatile long*>(m_p) - 2;
        InterlockedDecrement(count);
    }
};
struct NiObjectNET
{
    void SetName(const NiFixedString& name);
};
struct ObjC57 : TESObjectDoorController
{
    void SetName(const NiFixedString& name);
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    virtual void vfn_00dc();
    virtual void vfn_00e0();
    virtual void vfn_00e4();
    virtual ObjC57* vfn_00e8();
    int f_04;
    int f_08;
    int f_0c;
    int f_10;
    int f_14;
    int f_18;
    int f_1c;
    int f_20;
    int f_24;
    int f_28;
    int f_2c;
    int f_30;
    int f_34;
    int f_38;
    int f_3c;
    int f_40;
    int f_44;
    int f_48;
    int f_4c;
    int f_50;
    int f_54;
    int f_58;
    int f_5c;
    int f_60;
    int f_64;
    int f_68;
    int f_6c;
    int f_70;
    int f_74;
    int f_78;
    int f_7c;
    int f_80;
    int f_84;
    int f_88;
    int f_8c;
    int f_90;
    int f_94;
    int f_98;
    int f_9c;
    int f_a0;
    int f_a4;
    int f_a8;
    int f_ac;
    int f_b0;
    int f_b4;
    int f_b8;
    int f_bc;
    int f_c0;
    ObjC57(int a1, Vec3* a2, Vec3* a3, Vec4* a4, int a5, int a6, int a7, int a8, int a9, unsigned short* a10,
           unsigned short* a11);
};
// @fnv 0x00c57d70
ObjC57* __cdecl FUN_00c57d70(float p0, float p1, unsigned short w, unsigned short h, Vec4* src)
{
    float angleStep8;
    angleStep8 = (float)(::DAT_010c2c34 * ::DAT_01011590 / (float)w);
    float step9;
    step9 = (float)(::DAT_010c2c34 * ::DAT_01011590 / (float)h);
    unsigned short n24;
    n24 = (unsigned short)(2 * h + 2);
    unsigned int capacity19;
    capacity19 = w * n24;
    Vec3* ver654;
    ver654 = new Vec3[capacity19];
    Vec3* norm_2;
    norm_2 = new Vec3[capacity19];
    Vec4* q0;
    q0 = src ? new Vec4[capacity19] : 0;
    unsigned short* idxA6;
    idxA6 = new unsigned short[w];
    unsigned short* indices5;
    indices5 = new unsigned short[capacity19];
    unsigned short indexA6;
    indexA6 = 0;
    unsigned short strip3;
    strip3 = 0;
    float angle3;
    angle3 = 0.0f;
    float cosPrev4;
    cosPrev4 = 1.0f;
    float sineA;
    sineA = 0.0f;
    for (int i = w - 1; i >= 0; --i)
    {
        float angA4;
        angA4 = angle3 + angleStep8;
        float c3;
        c3 = (float)cos(angA4);
        float sine2;
        sine2 = (float)sin(angA4);
        float angB3;
        angB3 = 0.0f;
        for (int j = h; j >= 0; --j)
        {
            angB3 += step9;
            float cosBA;
            cosBA = (float)cos(angB3);
            float r16;
            r16 = (float)sin(angB3);
            float radius9;
            radius9 = p0 * cosBA + p1;
            ver654[indexA6] = Vec3(c3 * radius9, -sine2 * radius9, p0 * r16);
            norm_2[indexA6] = Vec3(c3 * cosBA, -sine2 * cosBA, r16);
            if (src)
                q0[indexA6] = *src;
            indices5[indexA6] = indexA6;
            ++indexA6;
            ver654[indexA6] = Vec3(cosPrev4 * radius9, -sineA * radius9, p0 * r16);
            norm_2[indexA6] = Vec3(cosPrev4 * cosBA, -sineA * cosBA, r16);
            if (src)
                q0[indexA6] = *src;
            indices5[indexA6] = indexA6;
            ++indexA6;
        }
        idxA6[strip3] = n24;
        ++strip3;
        angle3 = angA4;
        cosPrev4 = c3;
        sineA = sine2;
    }
    ObjC57* obj15;
    obj15 = new ObjC57(indexA6, ver654, norm_2, q0, 0, 0, 0, 2 * w * h, w, idxA6, indices5);
    ::AssignFixedString((char *)(obj15), (intptr_t)&(const ::fnv_00c57d70::NiFixedString &)(NiFixedString(DAT_010c2c98)), {});
    obj15->vfn_00e8();
    return obj15;
}
}

namespace fnv_00c584a0 {
struct MeshAllocator
{
    void* Allocate(unsigned int);
};
extern MeshAllocator meshMemory;
struct MeshPoint
{
    float x, y, z;
    __forceinline MeshPoint()
    {}
    __forceinline MeshPoint(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};
struct MeshUV
{
    float x, y;
    __forceinline MeshUV()
    {}
    __forceinline MeshUV(float a, float b)
    {
        x = a;
        y = b;
    }
};
struct MeshColor
{
    float r, g, b, a;
    __forceinline MeshColor() : r(0), g(0), b(0), a(0)
    {}
};
extern float DAT_010c2c34;
extern char* DAT_0109b220;
struct StringHeader
{
    long refs;
    long length;
    char text;
};
struct MeshName
{
    char* value;
    __forceinline MeshName(const char* name)
    {
        if (!name)
            value = DAT_0109b220;
        else
            value = ::NiGlobalStringTable::AddString(name);
    }
    __forceinline ~MeshName()
    {
        if (value == DAT_0109b220)
            return;
        long* refs = (long*)value - 2;
        InterlockedDecrement(refs);
    }
};
struct CylinderMesh
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void Update();
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
    CylinderMesh(unsigned short, MeshPoint*, MeshPoint*, MeshColor*, MeshUV*, unsigned short, int, unsigned short,
                 unsigned short, unsigned short*, unsigned short*);
};
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
__forceinline float meshSin(float a)
{
    return float(sin(a));
}
__forceinline float meshCos(float a)
{
    return float(cos(a));
}
// @fnv 0x00c584a0
CylinderMesh* __cdecl FUN_00c584a0(float bottom, float top, float height, unsigned short slices, unsigned short stacks,
                                   MeshColor* color)
{
    unsigned short stripSizeX = 2 * slices + 2;
    unsigned int count7 = stacks * stripSizeX;
    MeshPoint* point15 = new MeshPoint[count7];
    MeshPoint* normal6 = new MeshPoint[count7];
    MeshColor* pkColors8 = color ? new MeshColor[count7] : 0;
    MeshUV* finalTexcoords6 = new MeshUV[count7];
    unsigned short* lengthsVal = new unsigned short[stacks];
    unsigned short* indices_19 = new unsigned short[count7];
    unsigned short index4 = 0;
    float angleStep6 = 2.0f * ::DAT_010c2c34 / slices;
    float radiusStep2 = (top - bottom) / stacks;
    float heightStep = height / stacks;
    float uStep9 = 1.0f / slices;
    float kVStep = 1.0f / stacks;
    float v2 = 1.0f;
    float zl = 0.0f;
    float rRadius = bottom;
    float _normal = (bottom - top) / height;  // Z component of the unnormalized surface normal.
    float aNormalScale = 1.0f;
    for (unsigned int row = 0; row < stacks; row++)
    {
        float u = 0.0f;
        for (unsigned int col = 0; col <= slices; col++)
        {
            float sine, cosine;
            if (col == slices)
            {
                sine = 0.0f;
                cosine = 1.0f;
            }
            else
            {
                sine = (double)meshSin(col * angleStep6);
                cosine = (double)meshCos(col * angleStep6);
            }
            point15[index4] = MeshPoint(sine * rRadius, cosine * rRadius, zl);
            normal6[index4] = MeshPoint(sine * aNormalScale, cosine * aNormalScale, _normal * aNormalScale);
            if (color)
                pkColors8[index4] = *color;
            finalTexcoords6[index4] = MeshUV(u, v2);
            indices_19[index4] = index4;
            index4++;
            point15[index4] =
                MeshPoint(sine * (rRadius + radiusStep2), cosine * (rRadius + radiusStep2), zl + heightStep);
            normal6[index4] = MeshPoint(sine * aNormalScale, cosine * aNormalScale, _normal * aNormalScale);
            if (color)
                pkColors8[index4] = *color;
            finalTexcoords6[index4] = MeshUV(u, v2 - kVStep);
            indices_19[index4] = index4;
            index4++;
            u += uStep9;
        }
        rRadius += radiusStep2;
        v2 -= kVStep;
        zl += heightStep;
        lengthsVal[row] = stripSizeX;
    }
    CylinderMesh* mesh2 = new CylinderMesh(index4, point15, normal6, pkColors8, finalTexcoords6, 1, 0,
                                           2 * stacks * slices, stacks, lengthsVal, indices_19);
    ::AssignFixedString((char *)(mesh2), (intptr_t)&(const ::fnv_00c584a0::MeshName &)(MeshName("BSTestObjects Cylinder")), {});
    mesh2->Update();
    return mesh2;
}
}

namespace fnv_00c58f00 {
struct FUN_00aa3e40_alloc
{
    void* FUN_00aa3e40(unsigned int size);
};
extern "C" char DAT_011f6238;
void* __cdecl FUN_00aa13e0(size_t size);
extern "C" double __cdecl cos(double angle);
extern "C" double __cdecl sin(double angle);

struct Vec3Item
{
    float x;
    float y;
    float z;
    __forceinline Vec3Item()
    {}
    __forceinline Vec3Item(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

struct Vec4Item
{
    float x;
    float y;
    float z;
    float w;
    __forceinline Vec4Item() : x(0), y(0), z(0), w(0)
    {}
};

struct SpawnedObject_b10495 : NiMemObject
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
    SpawnedObject_b10495(unsigned short count, Vec3Item* a, Vec4Item* b, int c, int d, int e, unsigned char* flags);
};

__forceinline float CircleTrigA(float a)
{
    return (double)(float)cos(a);
}
__forceinline float CircleTrigB(float a)
{
    return (double)(float)sin(a);
}

// @fnv 0x00c58f00
void* __cdecl FUN_00c58f00(float radius, unsigned short count, Vec4Item* color)
{
    Vec3Item* aVal = new Vec3Item[count];
    unsigned char* flagsB = new unsigned char[count];
    Vec4Item* b5 = color ? new Vec4Item[count] : 0;
    float step3 = 6.2831854820251465 / (int)count;
    for (unsigned int i = 0; i < count; ++i)
    {
        if (b5 != 0)
        {
            b5[i] = *color;
        }
        flagsB[i] = 1;
        aVal[i] = Vec3Item(CircleTrigB(step3 * i) * radius, CircleTrigA(step3 * i) * radius, 0.0f);
    }
    SpawnedObject_b10495* result5 = new SpawnedObject_b10495(count, aVal, b5, 0, 1, 0, flagsB);
    return result5;
}
}

namespace fnv_00c5a0f0 {

struct Vec3
{
    float x, y, z;
    Vec3()
    {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vec3 FUN_00439ef0(const Vec3&) const;
    Vec3 FUN_00439e90(const Vec3&) const;
    Vec3 FUN_004b3800(const Vec3&) const;
    float FUN_00457910();
    float FUN_00457990() const;
    Vec3 operator*(float f) const
    {
        return Vec3(f * x, f * y, f * z);
    }
    Vec3 operator+(const Vec3& v) const
    {
        return Vec3(v.x + x, v.y + y, v.z + z);
    }
    Vec3 operator-(const Vec3& v) const
    {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }
    Vec3& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
};
struct Vec2
{
    float u, v;
    Vec2()
    {}
    Vec2(float a, float b) : u(a), v(b)
    {}
};
struct Color4
{
    float r, g, b, a;
    Color4() : r(0), g(0), b(0), a(0)
    {}
};

extern float DAT_010c2c34;
extern double DAT_01011590;
extern const float DAT_01016248;
extern const float DAT_01012054;
extern char DAT_010c2c80[];

void* __cdecl FUN_00aa13e0(size_t size);
int* __cdecl FUN_00a5b690(const char* value);
extern int DAT_0109b220;

struct Mesh : NiMemObject
{
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
    Mesh(unsigned short vertexCount, Vec3* verticesX3, Vec3* normals, Color4* colors, Vec2* uv, bool hasNormals,
         bool flag, unsigned short triangleCount, unsigned short* indices);
    Mesh(unsigned short vertexCount, Vec3* verticesX3, Vec3* normals, Color4* colors, Vec2* uv, bool hasNormals,
         bool flag, unsigned short triangleCount, unsigned short stripCount, unsigned short* stripLengths,
         unsigned short* indices);
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
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void Update();
};

struct ScopedName;
struct NiMemObjectAllocation
{
};
struct FUN_00a5ecb0 : NiMemObjectAllocation, Node_cls
{
    unsigned int childrenGrowBy;
    FUN_00a5ecb0(int growBy);

    void AssignFixedString(const ScopedName& source);
    virtual void nodeV10();
    virtual void nodeV14();
    virtual void nodeV18();
    virtual void nodeV1c();
    virtual void nodeV20();
    virtual void nodeV24();
    virtual void nodeV28();
    virtual void nodeV2c();
    virtual void nodeV30();
    virtual void nodeV34();
    virtual void nodeV38();
    virtual void nodeV3c();
    virtual void nodeV40();
    virtual void nodeV44();
    virtual void nodeV48();
    virtual void nodeV4c();
    virtual void nodeV50();
    virtual void nodeV54();
    virtual void nodeV58();
    virtual void nodeV5c();
    virtual void nodeV60();
    virtual void nodeV64();
    virtual void nodeV68();
    virtual void nodeV6c();
    virtual void nodeV70();
    virtual void nodeV74();
    virtual void nodeV78();
    virtual void nodeV7c();
    virtual void nodeV80();
    virtual void nodeV84();
    virtual void nodeV88();
    virtual void nodeV8c();
    virtual void nodeV90();
    virtual void nodeV94();
    virtual void nodeV98();
    virtual void nodeV9c();
    virtual void nodeVa0();
    virtual void nodeVa4();
    virtual void nodeVa8();
    virtual void nodeVac();
    virtual void nodeVb0();
    virtual void nodeVb4();
    virtual void nodeVb8();
    virtual void nodeVbc();
    virtual void nodeVc0();
    virtual void nodeVc4();
    virtual void nodeVc8();
    virtual void nodeVcc();
    virtual void nodeVd0();
    virtual void nodeVd4();
    virtual void nodeVd8();
    virtual void AttachChildInAvailableSlot(Mesh* geometry, bool updateProperties);
};

typedef FUN_00a5ecb0 MeshRoot;

extern const double DAT_01017cf8;
inline float Vec3::FUN_00457990() const
{
    return sqrt(x * x + y * y + z * z);
}
inline float Vec3::FUN_00457910()
{
    float magnitude = FUN_00457990();
    if (magnitude > DAT_01017cf8)
    {
        float inverse = 1.0f / magnitude;
        x *= inverse;
        y *= inverse;
        z *= inverse;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        magnitude = 0.0f;
    }
    return magnitude;
}
inline Vec3 Vec3::FUN_00439ef0(const Vec3& v) const
{
    return Vec3(x - v.x, y - v.y, z - v.z);
}
inline Vec3 Vec3::FUN_00439e90(const Vec3& v) const
{
    return Vec3(x + v.x, y + v.y, z + v.z);
}
inline Vec3 Vec3::FUN_004b3800(const Vec3& v) const
{
    return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
void* FUN_00aa1070(unsigned int);
extern const unsigned short DAT_010c2d10[];
// @fnv 0x00c5a0f0
MeshRoot* FUN_00c5a0f0(const Vec3& start, const Vec3& end, float width, float height, const Color4* shaftColor,
                       const Color4* tipColor)
{
    MeshRoot* rootNode4 = new MeshRoot(0);
    Vec3 direction6 = (*(::fnv_00c5a0f0::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(end))->FUN_00439ef0((::NiPoint3 *)&(start), *(const ::NiPoint3 *)nullptr)));
    float lengthX = reinterpret_cast<::NiPoint3 *>(&(direction6))->GetLengthSquared();
    float length = 0.0f;
    float tipLength3 = width * ::DAT_01034208;
    if (lengthX > tipLength3)
        length = lengthX - tipLength3;
    else
        tipLength3 = lengthX;
    Vec3 nearEnd4 = (*(::fnv_00c5a0f0::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(start))->ProjectileLaunched((::NiPoint3 *)&(const ::fnv_00c5a0f0::Vec3 &)(direction6 * length), {})));
    if (length > ::_DAT_01012060)
    {
        Mesh* shaft2 = ((::fnv_00c5a0f0::Mesh *)(::FUN_00c55d50((::Point3 *)&(start), (::Point3 *)&(nearEnd4), width, width, height, 0.0f, (::FilterData *)(shaftColor), (::FilterData *)(tipColor))));
        rootNode4->AttachChildInAvailableSlot(shaft2, true);
    }
    Vec3* verticesX3 = new Vec3[6];
    Vec3 up4(0.0f, 0.0f, 1.0f);
    Vec3 sideC7 = direction6.FUN_004b3800(up4);
    sideC7 *= width * ::DBL_0101db80;
    Vec3 elevation5(0.0f, 0.0f, height);
    verticesX3[0] = elevation5 + end;
    verticesX3[1] = elevation5 + (sideC7 + nearEnd4);
    verticesX3[2] = end;
    verticesX3[3] = sideC7 + nearEnd4;
    verticesX3[4] = elevation5 + (nearEnd4 - sideC7);
    verticesX3[5] = nearEnd4 - sideC7;
    if (shaftColor && !tipColor)
        tipColor = shaftColor;
    Color4* colors = tipColor ? new Color4[6] : 0;
    if (colors)
    {
        for (unsigned int i2 = 0; i2 < 6; ++i2)
            colors[i2] = *tipColor;
    }
    unsigned short* indices_10 = (unsigned short*)FUN_00aa1070(48);
    std::memmove(indices_10, DAT_010c2d10, 48);
    Mesh* meshTmp = new Mesh(6, verticesX3, 0, colors, 0, 0, 0, 8, indices_10);
    meshTmp->Update();
    rootNode4->AttachChildInAvailableSlot(meshTmp, true);
    return rootNode4;
}
}

namespace fnv_00c5a800 {

struct PerpPoint
{
    float x, y, z;
    PerpPoint()
    {}
    PerpPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    float Length() const
    {
        return (float)sqrt(x * x + y * y + z * z);
    }
    PerpPoint operator/(float length) const
    {
        float inverse = 1.0f / length;
        return PerpPoint(x * inverse, y * inverse, z * inverse);
    }
    PerpPoint CrossProduct(const PerpPoint& v) const
    {
        PerpPoint cross(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
        float length = cross.Length();
        if (length > 0.0)
            return cross / length;
        else
            return PerpPoint(0.0f, 0.0f, 0.0f);
    }
    PerpPoint FUN_00c5a800() const;
};
// @fnv 0x00c5a800
PerpPoint PerpPoint::FUN_00c5a800() const
{
    if (fabs(x) < fabs(y))
    {
        if (fabs(z) < fabs(x))
            return CrossProduct((*reinterpret_cast<const ::fnv_00c5a800::PerpPoint *>((void *)&::DAT_011a9484)));
        else
            return CrossProduct((*reinterpret_cast<::fnv_00c5a800::PerpPoint *>(&::DAT_011a946c)));
    }
    else
    {
        if (fabs(z) < fabs(y))
            return CrossProduct((*reinterpret_cast<const ::fnv_00c5a800::PerpPoint *>((void *)&::DAT_011a9484)));
        else
            return CrossProduct((*reinterpret_cast<::fnv_00c5a800::PerpPoint *>(&::DAT_011a9478)));
    }
}
}

// namespace fnv_00c5a800

namespace fnv_00c5f2e0 {
extern char* DAT_0109b220;
extern MemoryManager _g_memoryManager;

struct NiFixedString
{
    char* m_kHandle;
    ~NiFixedString()
    {
        if (m_kHandle == DAT_0109b220)
            return;
        volatile long* count = (volatile long*)m_kHandle - 2;
        InterlockedDecrement(count);
    }
};


// @fnv 0x00c5f2e0
void __cdecl FUN_00c5f2e0()
{
    delete (*reinterpret_cast<::fnv_00c5f2e0::NiFixedString * *>(&::DAT_01204374));
    (*reinterpret_cast<::fnv_00c5f2e0::NiFixedString * *>(&::DAT_01204374)) = 0;
}
}

// namespace fnv_00c5f2e0

struct RemovalMapNode;

struct RemovalMapLink
{
    long bits;
    inline long Pointer()
    {
        RemovalMapLink* source = this;
        return source->bits & ~1;
    }
    inline long Value()
    {
        RemovalMapLink* source = this;
        return source->bits;
    }
    inline const long& Raw() const
    {
        const RemovalMapLink* source = this;
        return source->bits;
    }
    inline bool IsMarked()
    {
        RemovalMapLink* source = this;
        return (source->bits & 1) != 0;
    }
    RemovalMapLink()
    {}
    inline RemovalMapLink(long pointer)
    {
        bits = pointer;
    }
    inline RemovalMapLink(long pointer, bool mark)
    {
        bits = pointer;
        Mark(mark);
    }
    inline bool Compare(long replacement, long expected)
    {
        bool succeeded = InterlockedCompareExchange(&bits, replacement, expected) == expected;
        return succeeded;
    }
    inline void Mark(bool mark)
    {
        RemovalMapLink* target = this;
        if (mark)
            target->bits |= 1;
        else
            target->bits &= ~1;
    }
};

struct RemovalMapObject
{
    long unk00, unk04;
    volatile long count;
    void FUN_0044dd60();
};

struct RemovalMapHold
{
    RemovalMapObject* object;
    inline RemovalMapHold(RemovalMapObject* p) : object(p)
    {
        if (object)
            InterlockedIncrement(&object->count);
    }
    inline ~RemovalMapHold()
    {
        if (object)
            object->FUN_0044dd60();
    }
};

struct RemovalMapHeader
{
    long unk00, unk04, unk08;
    volatile long* entries;
    unsigned int threshold;
};

struct RemovalMapNode
{
    long unk00, unk04;
    RemovalMapObject* object;
    RemovalMapLink next;
    inline bool CompareNext(long replacement, long expected)
    {
        bool succeeded = InterlockedCompareExchange(&next.bits, replacement, expected) == expected;
        return succeeded;
    }
};

struct RemovalMapState
{
    RemovalMapHeader* owner;
    long* slot04;
    long* slot08;
    long* slot0c;
    volatile long* head;
    RemovalMapLink current;
    RemovalMapLink next;
    RemovalMapNode* retired;
    unsigned int retiredCount;
    inline bool FUN_00c41ac0(int index, int value)
    {
        volatile long* link = &owner->entries[index];
        while (true)
        {
            bool retry = false;
            head = link;
            current.bits = *head;
            *slot08 = current.Pointer();
            RemovalMapLink observed(current.Pointer());
            reinterpret_cast<::FUN_0044e010_class *>(&(observed))->FUN_0044e010(false);
            if (((RemovalMapLink*)head)->Value() != observed.Raw())
                continue;
            while (true)
            {
                if (!current.Pointer())
                    return false;
                next = ((RemovalMapNode*)current.Pointer())->next;
                *slot04 = next.Pointer();
                if (next.Value() != ((RemovalMapNode*)current.Pointer())->next.Raw())
                {
                    retry = true;
                    break;
                }
                RemovalMapHold hold(((RemovalMapNode*)current.Pointer())->object);
                RemovalMapLink previous(current.Pointer());
                reinterpret_cast<::FUN_0044e010_class *>(&(previous))->FUN_0044e010(false);
                if (((RemovalMapLink*)head)->Value() != previous.Raw())
                {
                    retry = true;
                    break;
                }
                if (!next.IsMarked())
                {
                    if (hold.object == *(RemovalMapObject**)value)
                        return true;
                    head = &((RemovalMapNode*)current.Pointer())->next.bits;
                    *slot0c = current.Pointer();
                }
                else
                {
                    RemovalMapLink replacement(next.Pointer(), false);
                    if (((RemovalMapLink*)head)->Compare(replacement.Value(), previous.Value()))
                        reinterpret_cast<::C41Owner *>(this)->FUN_00c41f40((::C41Node *)(::RemovalMapNode *)((RemovalMapNode*)current.Pointer()));
                    else
                    {
                        retry = true;
                        break;
                    }
                }
                current = next;
                *slot08 = next.Pointer();
            }
            if (retry)
                continue;
        }
    }
    inline void FUN_00c41f40(RemovalMapNode* node)
    {
        RemovalMapObject** object = &node->object;
        if (*object)
        {
            if (*object)
                (*object)->FUN_0044dd60();
            *object = 0;
            if (*object)
            {
                RemovalMapObject* incoming = *object;
                InterlockedIncrement(&incoming->count);
            }
        }
        RemovalMapNode* previous = retired;
        node->object = (RemovalMapObject*)previous;
        retired = node;
        ++retiredCount;
        unsigned int limit = owner->threshold;
        if (retiredCount == limit)
            Collect();
    }
    void Collect();
    bool FUN_00c40680(int, int);
};

// @fnv 0x00c40680
bool RemovalMapState::FUN_00c40680(int arg1, int arg2)
{
    bool result = false;
    while (true)
    {
        if (!reinterpret_cast<::C41Owner *>(this)->FUN_00c41ac0(arg1, (::C41Object **)(arg2)))
        {
            result = false;
            break;
        }
        RemovalMapLink expected(next.Pointer());
        reinterpret_cast<::FUN_0044e010_class *>(&(expected))->FUN_0044e010(false);
        RemovalMapLink desired(next.Pointer());
        reinterpret_cast<::FUN_0044e010_class *>(&(desired))->FUN_0044e010(true);
        if (!((RemovalMapNode*)current.Pointer())->CompareNext(desired.Value(), expected.Value()))
            continue;
        RemovalMapLink old(current.Pointer(), false);
        if (((RemovalMapLink*)head)->Compare(expected.Value(), old.Value()))
            reinterpret_cast<::C41Owner *>(this)->FUN_00c41f40((::C41Node *)(::RemovalMapNode *)((RemovalMapNode*)current.Pointer()));
        else
            reinterpret_cast<::C41Owner *>(this)->FUN_00c41ac0(arg1, (::C41Object **)(arg2));
        result = true;
        break;
    }
    *slot04 = 0;
    *slot08 = 0;
    *slot0c = 0;
    return result;
}

struct WorkerSemaphore
{
    volatile long count;
    void* handle;
    inline void Wait()
    {
        WaitForSingleObject(handle, ~0UL);
        InterlockedDecrement(&count);
    }
    inline bool IsEmpty()
    {
        return WaitForSingleObject(handle, 0) == 258;
    }
    inline void Signal()
    {
        ReleaseSemaphore(handle, 1, 0);
        InterlockedIncrement(&count);
    }
};

struct WorkerEventBase
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char flags;
    inline WorkerEventBase() : unk08(0), unk10(0), unk14(0), flags(0)
    {}
    virtual ~WorkerEventBase()
    {}
};

struct WorkerEvent : WorkerEventBase
{
    int unk1c;
    inline WorkerEvent()
    {}
    inline bool Done()
    {
        return (flags & 2) != 0;
    }
    inline void SetFlag(unsigned int mask, bool value)
    {
        if (value)
            flags |= mask;
        else
            flags &= ~mask;
    }
};

struct WorkerJob
{
    virtual ~WorkerJob();
    int unk04;
    volatile long refs;
    volatile long state;
    inline void AddRef()
    {
        InterlockedIncrement(&refs);
    }
    inline void FUN_0044dd60()
    {
        long remaining = InterlockedDecrement(&refs);
        if (remaining == 0)
            delete this;
    }
};

inline bool WorkerTryStart(WorkerJob*& job)
{
    WorkerJob* self = job;
    {
        bool result = InterlockedCompareExchange(&self->state, 3, 1) == 1;
        return result;
    }
}

struct WorkerJobRef
{
    WorkerJob* value;
    inline WorkerJobRef(WorkerJob* p = 0) : value(p)
    {
        if (value)
            value->AddRef();
    }
    inline ~WorkerJobRef()
    {
        if (value)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(value));
    }
    inline void operator=(WorkerJob* p)
    {
        if (value)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(value));
        value = p;
        if (value)
            value->AddRef();
    }
};

struct WorkerQueueLock
{
    long owner, depth;
    void Lock(const char*);
    inline void Unlock()
    {
        --depth;
        if (depth == 0)
            owner = 0;
    }
};

struct WorkerJobContainer
{
    bool First(unsigned int, unsigned __int64*, WorkerJobRef*);
    bool Next(unsigned int, unsigned __int64*, WorkerJobRef*);
};

struct WorkerQueue;

struct WorkerQueueTLS
{
    int unk00;
    unsigned long index;
    WorkerJobContainer* Create(WorkerQueue*);
};

struct WorkerQueue
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
    virtual void Process(WorkerJob*);
    virtual void Finish(WorkerJob*);
    int unk04, unk08, unk0c, unk10;
    WorkerQueueTLS* tls;
    int unk18, unk1c;
    WorkerQueueLock lock;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned char stopping;
    bool FUN_00c40e70(WorkerEvent*, unsigned __int64*, WorkerJobRef*, bool);
    inline WorkerJobContainer* Container()
    {
        unsigned long index = tls->index;
        WorkerJobContainer* value = static_cast<WorkerJobContainer*>(TlsGetValue(index));
        return value ? value : tls->Create(this);
    }
};

inline bool WorkerQueue::FUN_00c40e70(WorkerEvent* event, unsigned __int64* output, WorkerJobRef* job, bool wait)
{
    lock.Lock(0);
    bool found = false;
    if (static_cast<bool>(event->flags & 2))
    {
        found = false;
    }
    else
    {
        while (true)
        {
            if (!static_cast<bool>(event->flags & 1))
            {
                found = Container()->First(event->unk08, reinterpret_cast<unsigned __int64*>(&event->unk10), job);
                event->SetFlag(1, true);
            }
            else
            {
                found = Container()->Next(event->unk08, reinterpret_cast<unsigned __int64*>(&event->unk10), job);
            }
            if (!found)
            {
                ++event->unk08;
                unsigned int count = unk08;
                if (static_cast<unsigned int>(event->unk08) >= count)
                {
                    event->SetFlag(2, true);
                }
                else if (wait)
                {
                    event->SetFlag(1, false);
                    continue;
                }
            }
            else
            {
                *output = *reinterpret_cast<unsigned __int64*>(&event->unk10);
            }
            break;
        }
    }
    lock.Unlock();
    return found;
}

struct WorkerThread
{
    int unk00, unk04, unk08;
    WorkerSemaphore start;
    int unk14;
    WorkerSemaphore available;
    int unk20, unk24, unk28, unk2c;
    WorkerQueue* queue;
    void FUN_00c410b0();
};

// @fnv 0x00c410b0
void WorkerThread::FUN_00c410b0()
{
    while (queue->stopping != 1)
    {
        start.Wait();
        WorkerEvent event;
        bool result = false;
        while (!static_cast<bool>(event.flags & 2))
        {
            if (available.IsEmpty())
            {
                available.Wait();
                reinterpret_cast<::FUN_00c42060_Class *>(&(event))->SetArg(0);
            }
            WorkerJobRef job;
            unsigned __int64 output;
            if (reinterpret_cast<::Map40 *>((queue))->FUN_00c40e70((::Iter40 *)(::WorkerEvent *)(&event), (long long *)(unsigned long long *)(&output), (intptr_t)(&job), !result))
            {
                if (job.value->state == 1 && WorkerTryStart(job.value))
                {
                    result = true;
                    queue->Process(job.value);
                    queue->Finish(job.value);
                }
            }
            else if (!static_cast<bool>(event.flags & 2))
            {
                reinterpret_cast<::FUN_00c42060_Class *>(&(event))->SetArg(0);
                result = false;
            }
            if (job.value)
                job = 0;
            available.Signal();
        }
    }
}

extern "C++" void* __cdecl FUN_00a5b690(const char* text);

class NiFixedStringQ
{
  public:
    void* m_p;
    __forceinline NiFixedStringQ(const char* text)
    {
        if (!text)
            m_p = DAT_0109b220;
        else
            m_p = ((void *)(::NiGlobalStringTable::AddString(text)));
    }
};

struct NiFixedString_c43500
{
    static void __cdecl FUN_00c43500();
};

// @fnv 0x00c5d4e0
void __cdecl FUN_00c5d4e0()
{
    if (!DAT_01204364) {
        ::fnv_00c65530::FUN_00c65530();
        FUN_00c55200();
        ::fnv_00c546c0::FUN_00c546c0();
        ::fnv_00c618f0::FUN_00c618f0();
        ::fnv_00c5f240::S00c5f240_Holder::FUN_00c5f240();
        ::fnv_00c616c0::FUN_00c616c0();
        ::NiFixedString_c43500::FUN_00c43500();
        DAT_01204364 = 1;
    }
}

// @fnv 0x00c43500
void __cdecl NiFixedString_c43500::FUN_00c43500()
{
    ::DAT_01202ddc = (NiFixedString*)new NiFixedStringQ("BSX");
}

namespace fnv_00c435a0 {
struct NiFixedStringQ
{
    char* m_kHandle;
    ~NiFixedStringQ()
    {
        if (m_kHandle == (char*)DAT_0109b220)
        {
        }
        else
        {
            volatile long* off = (volatile long*)(m_kHandle - 8);
            InterlockedDecrement(off);
        }
    }
};

// @fnv 0x00c435a0
void __cdecl FUN_00c435a0()
{
    delete (NiFixedStringQ*)::DAT_01202ddc;
    ::DAT_01202ddc = 0;
}
}

// namespace fnv_00c435a0



struct C52520Camera
{
    virtual void vfn_00();
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
    C52020Obj* m_ac;
    int unkb0;
    int unkb4;
    unsigned char m_b8;
    float m_bc;
    inline C52020Obj* GetObj() const
    {
        return m_ac;
    }
    void FUN_00c52520();
};

// @fnv 0x00c52520
void C52520Camera::FUN_00c52520()
{
    CameraViewportC52 port(0.0f, 1.0f, 1.0f, 0.0f);
    GetObj()->viewport = port;
    reinterpret_cast<::C52020Obj *>(this)->FUN_00c52020(m_bc, 1, 0, 0);
}

struct BoxColor
{
    float r, g, b, a;
};


// Inlined under /Ob1. Its locals are reserved after the caller's new-expression
// temps, which is where this function's frame puts the cursor and colour state.
__forceinline void buildBox(NiPoint3* boxCorners, const NiPoint3& size, const BoxColor* color, BoxColor*& colors,
                            unsigned short*& indices, NiPoint3*& vertices, int& i, unsigned int& j,
                            NiPoint3*& vertexResult, NiPoint3*& vertexAllocation, BoxColor*& colorResult,
                            BoxColor*& colorAllocation, unsigned short*& indexAllocation)
{
    {
        NiPoint3* vertexCursor;
        int vertexRemaining;
        {
            BoxColor* colorCursor;
            {
                int colorRemaining;
                {
                    NiPoint3* vertexInitialized;
                    vertexAllocation = (NiPoint3*)reinterpret_cast<::MemoryManagerStandIn *>(&(g_memoryManager))->FUN_00aa3e40(96);
                    if (vertexAllocation)
                    {
                        vertexRemaining = 8;
                        vertexCursor = vertexAllocation;
                        while (--vertexRemaining >= 0)
                        {
                            ++vertexCursor;
                        }
                        vertexInitialized = vertexAllocation;
                    }
                    else
                    {
                        vertexInitialized = 0;
                    }
                    vertexResult = vertexInitialized;
                    vertices = vertexResult;
                    {
                        volatile float fx, afDepth, fy;
                        for (i = 0; i < 8; ++i)
                        {
                            fx = (float)(boxCorners[i].x * size.x);
                            vertices[i].x = fx;
                            afDepth = (float)(boxCorners[i].y * size.y);
                            vertices[i].y = afDepth;
                            fy = (float)(boxCorners[i].z * size.z);
                            vertices[i].z = fy;
                        }
                        {
                            BoxColor* colorInitialized;
                            {
                                BoxColor* conditionalColor;
                                if (color)
                                {
                                    colorAllocation = (BoxColor*)reinterpret_cast<::MemoryManagerStandIn *>(&(g_memoryManager))->FUN_00aa3e40(128);
                                    if (colorAllocation)
                                    {
                                        colorRemaining = 8;
                                        colorCursor = colorAllocation;
                                        while (--colorRemaining >= 0)
                                        {
                                            colorCursor->r = 0.0f;
                                            colorCursor->g = 0.0f;
                                            colorCursor->b = 0.0f;
                                            colorCursor->a = 0.0f;
                                            ++colorCursor;
                                        }
                                        colorInitialized = colorAllocation;
                                    }
                                    else
                                    {
                                        colorInitialized = 0;
                                    }
                                    colorResult = colorInitialized;
                                    conditionalColor = colorResult;
                                }
                                else
                                {
                                    conditionalColor = 0;
                                }
                                colors = conditionalColor;
                            }
                        }
                    }
                    if (colors)
                    {
                        for (j = 0; j < 8; ++j)
                        {
                            colors[j] = *color;
                        }
                    }
                    indexAllocation = (unsigned short*)reinterpret_cast<::MemoryManagerStandIn *>(&(g_memoryManager))->FUN_00aa3e40(72);
                    indices = indexAllocation;
                    memcpy(indices, DAT_010c2c38, 72);
                }
            }
        }
    }
}

// @fnv 0x00c55920
NiTriShape* __cdecl FUN_00c55920(const NiPoint3& size, const BoxColor* color)
{
    static NiPoint3 corners[8] = {
        {::fnv_00c88020::DAT_01016248, ::fnv_00c88020::DAT_01016248, ::fnv_00c88020::DAT_01016248}, {::fnv_00c88020::DAT_01016248, ::fnv_00c88020::DAT_01016248, ::DAT_0102295c},
        {::fnv_00c88020::DAT_01016248, ::DAT_0102295c, ::fnv_00c88020::DAT_01016248}, {::fnv_00c88020::DAT_01016248, ::DAT_0102295c, ::DAT_0102295c},
        {::DAT_0102295c, ::fnv_00c88020::DAT_01016248, ::fnv_00c88020::DAT_01016248}, {::DAT_0102295c, ::fnv_00c88020::DAT_01016248, ::DAT_0102295c},
        {::DAT_0102295c, ::DAT_0102295c, ::fnv_00c88020::DAT_01016248}, {::DAT_0102295c, ::DAT_0102295c, ::DAT_0102295c}};
    {
        BoxColor* colors;
        unsigned short* indices;
        NiPoint3* vertices;
        NiTriShape* shape;
        {
            int i;
            {
                unsigned int j;
                {
                    NiPoint3* vertexResult;
                    NiPoint3* vertexAllocation;
                    {
                        BoxColor* colorResult;
                        {
                            BoxColor* colorAllocation;
                            {
                                unsigned short* indexAllocation;
                                buildBox(corners, size, color, colors, indices, vertices, i, j, vertexResult,
                                         vertexAllocation, colorResult, colorAllocation, indexAllocation);
                                shape = new NiTriShape(8, vertices, 0, (RgbaColor*)colors, 0, 0, (NiGeometryDataFlags)0, 12, indices);
                                shape->Method58();
                                return shape;
                            }
                        }
                    }
                }
            }
        }
    }
}

struct S00c59660_Pt3 : public NiPoint3
{
    S00c59660_Pt3()
    {}
    S00c59660_Pt3(float fx, float fy, float afDepth)
    {
        x = fx;
        y = fy;
        z = afDepth;
    }
};

inline void* operator new[](std::size_t size, S_00c42960_Heap& pool)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&(pool))->FUN_00aa3e40(size);
}

inline void operator delete[](void*, S_00c42960_Heap&)
{}

class FUN_00a746e0 : public NiAVObject
{
  public:
    FUN_00a746e0(int n, NiPoint3* pts, ColorA* cols, int a, int b, int c, unsigned char* flags);
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
    ThreeByThreeMatrix m34;
    NiPoint3 m58;
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
};

// @fnv 0x00c59660
FUN_00a746e0* __cdecl FUN_00c59660(float length, ColorA* color)
{
    float dBA = length / 6.0;
    S00c59660_Pt3* pts = new (*(S_00c42960_Heap*)&DAT_011f6238) S00c59660_Pt3[5];
    pts[0] = S00c59660_Pt3(0.0f, 0.0f, 0.0f);
    pts[1] = S00c59660_Pt3(0.0f, 0.0f, length);
    pts[2] = S00c59660_Pt3(dBA, 0.0f, length - dBA);
    pts[3] = S00c59660_Pt3(0.0f, 0.0f, length);
    pts[4] = S00c59660_Pt3(-dBA, 0.0f, length - dBA);
    if (!color)
    {
        color = &DAT_012032f8;
    }
    ColorA* cols = new (*(S_00c42960_Heap*)&DAT_011f6238) ColorA[6];
    cols[0] = *color;
    cols[1] = *color;
    cols[2] = *color;
    cols[3] = *color;
    cols[4] = *color;
    unsigned char* flags2 = new (*(S_00c42960_Heap*)&DAT_011f6238) unsigned char[6];
    flags2[0] = 1;
    flags2[1] = 1;
    flags2[2] = 0;
    flags2[3] = 1;
    flags2[4] = 0;
    FUN_00a746e0* obj4 = new FUN_00a746e0(5, pts, cols, 0, 0, 0, flags2);
    obj4->m58 = ::NiPoint3::ZERO;
    obj4->m34 = *(ThreeByThreeMatrix*)&(*reinterpret_cast<::S00c43b90_Bound *>(&::DAT_011a9448));
    {
        S00c5fc70_FixedString kName((S00c5fc70_Source*)"BSTestObjects Arrow");
        obj4->SetName((const NiFixedString&)kName);
    }
    return obj4;
}

// Scene-graph ownership-transfer constructor.
// Copies a source node's controller chain, properties, extra data, transform and
// children onto "this", guarded by an is-kind-of test on the source.

extern "C" char DAT_010c32a8;

struct C5RTTI
{
    const char* m_pcName;
    C5RTTI* m_pkBase;
};

struct C5Fixed
{
    int m_p;
};

struct C5RefObj
{
    virtual void vfn_00();
    virtual void vfn_04();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            vfn_04();
    }
    volatile long m_uiRefCount;
};

struct C5Mat3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

struct C5Vec3
{
    float x, y, z;
};

struct C5TimeCtl
{
};

struct C5Chain
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual C5RTTI* vfn_08();
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98(void* pkArg);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    NiPointer<C5Chain> next;
    C5Chain* GetNext() const
    {
        return next;
    }
};

struct C5Ctl
{
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc(void* pkArg, int iFlag);
    virtual void vfn_e0();
    virtual void vfn_e4(void* pkArg, NiPointer<C5RefObj>* pkOut);
};

struct C5Base;

struct C5Collision : C5RefObj
{
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
    virtual void SetOwner(C5Base*);
    C5Base* owner;
    C5Base* GetOwner() const
    {
        return owner;
    }
};

struct C5ListItem
{
    C5ListItem* next;
    C5ListItem* prev;
    NiPointer<C5RefObj> value;
    NiPointer<C5RefObj>& GetElement()
    {
        return value;
    }
};

struct C5List
{
    C5ListItem* head;
    C5ListItem* tail;
    unsigned int count;
    NiPointer<C5RefObj> Remove(NiPointer<C5RefObj>&);
    bool IsEmpty() const
    {
        return count == 0;
    }
    NiPointer<C5RefObj>& GetHead() const
    {
        return head->GetElement();
    }
};

struct C5Children
{
    void* vtable;
    NiPointer<C5RefObj>* data;
    unsigned short capacity, size, effective, grow;
    unsigned short GetSize() const
    {
        return size;
    }
    const NiPointer<C5RefObj>& GetAt(unsigned int index) const
    {
        return data[index];
    }
};

struct C5Base
{
    C5Base(unsigned int uiFlags);
    ~C5Base();
    virtual void vfn_base();
    int unk04;
    C5Fixed name;
    NiPointer<C5Chain> chain;
    void** extraData;
    unsigned short extraCount, extraCapacity;
    C5Ctl* controller;
    NiPointer<C5Collision> collision;
    int unk20;
    C5List properties;
    int unk30;
    C5Mat3 rotation;
    C5Vec3 translation;
    float scale;
    C5Mat3 worldRotation;
    C5Vec3 worldTranslation;
    float worldScale;
    C5Children children;
    C5Chain* GetControllers() const
    {
        return chain;
    }
    void* GetChild(unsigned int index) const
    {
        return children.GetAt(index);
    }
    void* GetCollision() const
    {
        return collision;
    }
    unsigned short GetExtraCount() const
    {
        return extraCount;
    }
    void* GetExtra(unsigned short index) const
    {
        return extraData[index];
    }
    float GetScale() const
    {
        return scale;
    }
    void SetName(const C5Fixed& kName);
    void AttachChildInAvailableSlot(void* pkChild, bool bFlag);
    void AttachTarget(void* pkArg)
    {
        collision = static_cast<C5Collision*>(pkArg);
        if (collision && collision->GetOwner() != this)
            collision->SetOwner(this);
    }
    void ForwardToSubobject(std::intptr_t iValue)
    {
        NiPointer<C5RefObj> property(reinterpret_cast<C5RefObj*>(iValue));
        C5List& propertyList = properties;
        propertyList.Remove(property);
    }
};

typedef C5Base C5Src;

__forceinline bool SafeSource(C5Src* source)
{
    if (source == 0)
        return false;
    return reinterpret_cast<::NiObject_b *>((source))->FUN_006532c0((const ::NiRTTI_b *)(const void *)(&(*reinterpret_cast<::RttiX *>(&::g_011f4aa0))));
}
__forceinline bool ControllerKind(C5Chain* object)
{
    C5RTTI* type = object->vfn_08();
    while (type != 0)
    {
        if (type == (C5RTTI*)&(*reinterpret_cast<char *>(&::g_011f36ac)))
            return true;
        type = type->m_pkBase;
    }
    return false;
}
__forceinline bool SafeController(C5Chain* object)
{
    if (object == 0)
        return false;
    return ControllerKind(object);
}

namespace C5Transfer {
struct FUN_00c5f680 : C5Base
{
    FUN_00c5f680(C5Src* pkSource, bool bCopy);
    ~FUN_00c5f680();
    virtual void vfn_00();
};

// @fnv 0x00c5f680
FUN_00c5f680::FUN_00c5f680(C5Src* pkSource, bool bCopy) : C5Base(0)
{
    bool ok5 = true;
    C5Ctl* pCtl = pkSource->controller;
    ::AssignFixedString((char *)this, (intptr_t)&(pkSource->name), {});

    if (bCopy)
    {
        if (pkSource->GetControllers() != 0 || SafeSource(pkSource))
        {
            ok5 = false;
            ConcatPrefixAndSuffix((FUN_00c5fb80_rec*)pkSource, &DAT_010c32a8);
        }
    }

    if (ok5)
    {
        C5Chain* p = pkSource->GetControllers();
        while (p != 0)
        {
            C5Chain* pNext = p->GetNext();
            if (SafeController(p))
                reinterpret_cast<::NiTimeController *>((((C5TimeCtl*)p)))->SetTarget((::NiObjectNET *)(void *)(this));
            else
                p->vfn_98(this);
            p = pNext;
        }

        reinterpret_cast<::Owner62B *>(this)->AttachTarget(pkSource->GetCollision());
        reinterpret_cast<::Owner62B *>((pkSource))->AttachTarget(0);

        for (unsigned int i = 0; i < pkSource->children.size; i++)
        {
            void* pkChild = pkSource->GetChild(i);
            if (pkChild != 0)
                reinterpret_cast<::fnv_00a5ed10::ChildNode *>(this)->FUN_00a5ed10((::fnv_00a5ed10::ChildObj *)(pkChild), true);
        }

        while (!pkSource->properties.IsEmpty())
        {
            void* pkProperty = pkSource->properties.GetHead();
            reinterpret_cast<::FUN_00439410_cls *>(this)->FUN_00439410((::ArgObject *)(pkProperty));
            reinterpret_cast<::S654 *>((pkSource))->ForwardToSubobject((std::intptr_t)pkProperty);
        }

        translation = pkSource->translation;
        rotation = pkSource->rotation;
        scale = (float)fabs(pkSource->GetScale());

        EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_011f4380));
        reinterpret_cast<::NiObjectNET *>(this)->ResizeExtraData(pkSource->GetExtraCount());
        while (pkSource->GetExtraCount() != 0)
        {
            void* pkExtra = pkSource->GetExtra(0);
            reinterpret_cast<::FUN_00a5bca0_shell *>(this)->SetExtraDataName((::NiExtraData *)(pkExtra));
            reinterpret_cast<::NiObjectNET *>((pkSource))->FUN_00a5bf50(0);
        }
        LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_011f4380));

        if (pCtl != 0)
        {
            NiPointer<C5RefObj> spRetainedObject;
            pCtl->vfn_e4(pkSource, &spRetainedObject);
        }

        reinterpret_cast<::fnv_00c5f5a0::FUN_00c5f5a0_cls *>(this)->FUN_00c5f5a0((::fnv_00c5f5a0::NodeQ *)(void *)(this), this);
    }
    else
    {
        reinterpret_cast<::fnv_00a5ed10::ChildNode *>(this)->FUN_00a5ed10((::fnv_00a5ed10::ChildObj *)(pkSource), true);
    }

    if (pCtl != 0)
        pCtl->vfn_dc(this, 1);

    reinterpret_cast<::Node2 *>(this)->UpdateWorldBoundFromChildren();
}
}

struct WorkItem_j61
{
    virtual ~WorkItem_j61();
    int unk04, unk08, unk0c, unk10, unk14;
    void* child4;
    void* context;
    WorkItem_j61();
    void Setup(void* c, void* x)
    {
        child4 = c;
        context = x;
    }
};

struct TaskEvent_j61
{
    virtual void v00();
    virtual void Wait(int);
    virtual void Signal(int);
    bool ready;
};

struct EventRef_j61;

struct TaskManager_j61
{
    void Begin(EventRef_j61*);
    void Queue(EventRef_j61*, void*, int);
    void Finish(EventRef_j61*);
};

struct EventRef_j61
{
    TaskEvent_j61* value;
    void Signal(int x)
    {
        if (value)
            value->Signal(x);
    }
    void Begin()
    {
        reinterpret_cast<::FUN_00b00ae0_class *>(&((*(::TaskManager_j61 *)&(::GetTaskletManager()))))->FUN_00b00ae0((void **)(::EventRef_j61 *)(this));
    }
    void Queue(void* task, int x)
    {
        reinterpret_cast<::FUN_00b00b40_cls *>(&((*(::TaskManager_j61 *)&(::GetTaskletManager()))))->TryProcessPair((void **)(::EventRef_j61 *)(this), (void **)(task), x);
    }
    void Finish()
    {
        reinterpret_cast<::FUN_00b00bc0_cls *>(&((*(::TaskManager_j61 *)&(::GetTaskletManager()))))->FUN_00b00bc0((void **)(::EventRef_j61 *)(this));
    }
    void Wait(int x)
    {
        if (value)
        {
            bool ready = value->ready;
            if (!ready)
                value->Wait(x);
        }
    }
};

struct TaskRef_j61
{
    virtual ~TaskRef_j61()
    {}
    WorkItem_j61* value;
    TaskRef_j61() : value(0)
    {}
};

struct ChildObject_j61
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
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void Process(void*, int);
};

__forceinline ChildObject_j61*& ChildAt(ChildObject_j61** children, unsigned int index)
{
    ChildObject_j61** entry = &children[index];
    return *entry;
}

struct ProcessOwner_j61
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
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void Finish();
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
    ChildObject_j61** children;
    unsigned short capacity, count;
    int unka8, unkac, unkb0;
    EventRef_j61* event;
    void FUN_00c50610(void* context);
};

// @fnv 0x00c50610
void ProcessOwner_j61::FUN_00c50610(void* context)
{
    unsigned int total8 = count;
    WorkItem_j61* jobs3 = 0;
    bool parallelA = false;
    unsigned int queued = 0;
    if (parallelA)
    {
        jobs3 = new WorkItem_j61[total8];
        event->Signal(0);
        event->Begin();
    }
    ChildObject_j61* child4;
    for (unsigned int index = 0; index < total8; ++index)
    {
        child4 = ChildAt(children, index);
        if (child4)
        {
            if (parallelA)
            {
                TaskRef_j61 task;
                jobs3[index].Setup(child4, context);
                task.value = &jobs3[index];
                event->Queue(&task, 0);
                ++queued;
            }
            else
                child4->Process(context, 0);
        }
    }
    if (parallelA)
    {
        event->Finish();
        if (queued != 0)
        {
            event->Signal(99);
            event->Wait(0);
        }
        delete[] jobs3;
    }
    Finish();
}

inline float SphereCosValue(float angle)
{
    return static_cast<float>(std::sin(static_cast<double>(angle)));
}

inline float SphereSinValue(float angle)
{
    return static_cast<float>(std::cos(static_cast<double>(angle)));
}

inline float SphereCos(float angle)
{
    return static_cast<double>(SphereCosValue(angle));
}

inline float SphereSin(float angle)
{
    return static_cast<double>(SphereSinValue(angle));
}

struct Vec3
{
    float x, y, z;
    Vec3()
    {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

struct Vec2
{
    float u, v;
    Vec2()
    {}
    Vec2(float a, float b) : u(a), v(b)
    {}
};

struct Color4
{
    float r, g, b, a;
    Color4() : r(0), g(0), b(0), a(0)
    {}
};

extern float DAT_010c2c34;

extern double DAT_01011590;


extern const float DAT_01012054;

extern char DAT_010c2c80[];

struct Mesh : NiMemObject
{
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
    Mesh(unsigned short vertexCount, Vec3* vertices, Vec3* normals, Color4* colors, Vec2* uv, bool hasNormals,
         bool flag, unsigned short triangleCount, unsigned short* indices);
    Mesh(unsigned short vertexCount, Vec3* vertices, Vec3* normals, Color4* colors, Vec2* uv, bool hasNormals,
         bool flag, unsigned short triangleCount, unsigned short stripCount, unsigned short* stripLengths,
         unsigned short* indices);
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
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void Update();
};

struct ScopedName;

struct NiMemObjectAllocation
{
};

namespace SphereBuild {
struct FUN_00a5ecb0 : NiMemObjectAllocation, Node_cls
{
    unsigned int childrenGrowBy;
    FUN_00a5ecb0(int growBy);

    void AssignFixedString(const ScopedName& source);
    virtual void nodeV10();
    virtual void nodeV14();
    virtual void nodeV18();
    virtual void nodeV1c();
    virtual void nodeV20();
    virtual void nodeV24();
    virtual void nodeV28();
    virtual void nodeV2c();
    virtual void nodeV30();
    virtual void nodeV34();
    virtual void nodeV38();
    virtual void nodeV3c();
    virtual void nodeV40();
    virtual void nodeV44();
    virtual void nodeV48();
    virtual void nodeV4c();
    virtual void nodeV50();
    virtual void nodeV54();
    virtual void nodeV58();
    virtual void nodeV5c();
    virtual void nodeV60();
    virtual void nodeV64();
    virtual void nodeV68();
    virtual void nodeV6c();
    virtual void nodeV70();
    virtual void nodeV74();
    virtual void nodeV78();
    virtual void nodeV7c();
    virtual void nodeV80();
    virtual void nodeV84();
    virtual void nodeV88();
    virtual void nodeV8c();
    virtual void nodeV90();
    virtual void nodeV94();
    virtual void nodeV98();
    virtual void nodeV9c();
    virtual void nodeVa0();
    virtual void nodeVa4();
    virtual void nodeVa8();
    virtual void nodeVac();
    virtual void nodeVb0();
    virtual void nodeVb4();
    virtual void nodeVb8();
    virtual void nodeVbc();
    virtual void nodeVc0();
    virtual void nodeVc4();
    virtual void nodeVc8();
    virtual void nodeVcc();
    virtual void nodeVd0();
    virtual void nodeVd4();
    virtual void nodeVd8();
    virtual void AttachChildInAvailableSlot(Mesh* geometry, bool updateProperties);
};

}

typedef SphereBuild::FUN_00a5ecb0 MeshRoot;

struct ScopedName
{
    int* value;
    ScopedName(const char* text)
    {
        if (!text)
            value = reinterpret_cast<int*>(DAT_0109b220);
        else
            value = reinterpret_cast<int*>(((void *)(::NiGlobalStringTable::AddString(text))));
    }
    ~ScopedName()
    {
        if (value == reinterpret_cast<int*>(DAT_0109b220))
            return;
        volatile long* count = reinterpret_cast<volatile long*>(value) - 2;
        InterlockedDecrement(count);
    }
};

// @fnv 0x00c56680
MeshRoot* __cdecl FUN_00c56680(float radius, unsigned short slices, unsigned short stacks, const Color4* color)
{
    MeshRoot* rootUpdate6;
    Vec3* capNormals7;
    unsigned int capacity0;
    float angle36;
    float vStep3;
    Vec2* capUVs2;
    float uvX;
    float radius5;
    Mesh* capShape2;
    Vec3* capVertices2;
    unsigned short poleIndex8;
    float southernLatitude7;
    Mesh* sideShape8;
    float uStep;
    unsigned short* strips2;
    unsigned short vertexCount5;
    unsigned short* sideD3;
    unsigned short* capIndicesA;
    float angle28;
    Color4* color9;
    unsigned short indexB;
    float capUX;
    unsigned short intermediateBands5;
    unsigned short strip;
    rootUpdate6 = new MeshRoot(0);
    ::AssignFixedString((char *)(rootUpdate6), (intptr_t)&(const ::ScopedName &)(ScopedName(DAT_010c2c80)), {});

    radius5 = 1.0f;
    angle36 = DAT_010c2c34 / static_cast<float>(stacks);
    angle28 = DAT_010c2c34 * DAT_01011590 / static_cast<float>(slices);
    uStep = 1.0f / static_cast<float>(slices);
    vStep3 = 1.0f / static_cast<float>(stacks);

    capVertices2 = new Vec3[2 * slices + 2];
    capNormals7 = new Vec3[2 * slices + 2];
    color9 = color ? new Color4[2 * slices + 2] : 0;
    capUVs2 = new Vec2[2 * slices + 2];
    capIndicesA = new unsigned short[slices * 6];

    vertexCount5 = 0;
    indexB = 0;
    poleIndex8 = vertexCount5;

    capVertices2[vertexCount5] = Vec3(0.0f, 0.0f, radius5 * radius);
    capNormals7[vertexCount5] = Vec3(0.0f, 0.0f, 1.0f);
    if (color)
        color9[vertexCount5] = *color;
    capUVs2[vertexCount5] = Vec2(0.5f, 0.0f);
    ++vertexCount5;
    capUX = 0.0f;
    uvX = vStep3;
    for (unsigned int slice9 = 0; slice9 < slices; ++slice9)
    {
        float angle44;
        float z6;
        float x15;
        float y23;
        angle44 = static_cast<float>(slice9) * angle28;
        x15 = -static_cast<float>(SphereCos(angle44)) * static_cast<float>(SphereCosValue(angle36));
        y23 = static_cast<float>(SphereSin(angle44)) * static_cast<float>(SphereCosValue(angle36));
        z6 = radius5 * static_cast<float>(SphereSinValue(angle36));
        capVertices2[vertexCount5] = Vec3(x15 * radius, y23 * radius, z6 * radius);
        capNormals7[vertexCount5] = Vec3(x15 * radius5, y23 * radius5, z6 * radius5);
        if (color)
            color9[vertexCount5] = *color;
        capUVs2[vertexCount5] = Vec2(capUX, uvX);
        ++vertexCount5;
        capUX += uStep;
        if (slice9 > 0)
        {
            capIndicesA[indexB++] = poleIndex8;
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 2);
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
        }
    }
    capIndicesA[indexB++] = poleIndex8;
    capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
    capIndicesA[indexB++] = static_cast<unsigned short>(poleIndex8 + 1);

    poleIndex8 = vertexCount5;

    capVertices2[vertexCount5] = Vec3(0.0f, 0.0f, -radius * radius5);
    capNormals7[vertexCount5] = Vec3(0.0f, 0.0f, -1.0f);
    if (color)
        color9[vertexCount5] = *color;
    capUVs2[vertexCount5] = Vec2(0.5f, 1.0f);
    ++vertexCount5;
    southernLatitude7 = DAT_010c2c34 - angle36;
    capUX = 1.0f;
    uvX = 1.0f - vStep3;
    for (unsigned int indexA4 = slices; indexA4 > 0; --indexA4)
    {
        float angle57;
        float z7;
        float x26;
        float fY5;
        angle57 = indexA4 == slices ? 0.0f : static_cast<float>(indexA4) * angle28;
        x26 = -static_cast<float>(SphereCos(angle57)) * static_cast<float>(SphereCosValue(southernLatitude7));
        fY5 = static_cast<float>(SphereSin(angle57)) * static_cast<float>(SphereCosValue(southernLatitude7));
        z7 = radius5 * static_cast<float>(SphereSinValue(southernLatitude7));
        capVertices2[vertexCount5] = Vec3(x26 * radius, fY5 * radius, z7 * radius);
        capNormals7[vertexCount5] = Vec3(x26 * radius5, fY5 * radius5, z7 * radius5);
        if (color)
            color9[vertexCount5] = *color;
        capUVs2[vertexCount5] = Vec2(capUX, uvX);
        ++vertexCount5;
        capUX -= uStep;
        if (indexA4 != slices)
        {
            capIndicesA[indexB++] = poleIndex8;
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 2);
            capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
        }
    }
    capIndicesA[indexB++] = poleIndex8;
    capIndicesA[indexB++] = static_cast<unsigned short>(vertexCount5 - 1);
    capIndicesA[indexB++] = static_cast<unsigned short>(poleIndex8 + 1);

    capShape2 =
        new Mesh(vertexCount5, capVertices2, capNormals7, color9, capUVs2, true, false, indexB / 3, capIndicesA);
    capShape2->Update();
    rootUpdate6->AttachChildInAvailableSlot(capShape2, true);

    uvX = 0.0f;
    intermediateBands5 = static_cast<unsigned short>(stacks - 2);
    strip = static_cast<unsigned short>(2 * slices + 2);
    capacity0 = static_cast<unsigned int>(intermediateBands5) * strip;
    capVertices2 = new Vec3[capacity0];
    capNormals7 = new Vec3[capacity0];
    color9 = color ? new Color4[capacity0] : 0;
    capUVs2 = new Vec2[capacity0];
    strips2 = new unsigned short[intermediateBands5];
    sideD3 = new unsigned short[capacity0];
    vertexCount5 = 0;
    for (unsigned int band = 0; band < intermediateBands5; ++band)
    {
        southernLatitude7 = (band + 1) * angle36;
        capUX = 0.0f;
        for (unsigned int vertexCount9 = 0; vertexCount9 <= slices; ++vertexCount9)
        {
            float angle72;
            float zq;
            float x29;
            float fYA;
            angle72 = vertexCount9 == slices ? 0.0f : static_cast<float>(vertexCount9) * angle28;
            x29 = -static_cast<float>(SphereCos(angle72)) * static_cast<float>(SphereCosValue(southernLatitude7));
            fYA = static_cast<float>(SphereSin(angle72)) * static_cast<float>(SphereCosValue(southernLatitude7));
            zq = radius5 * static_cast<float>(SphereSinValue(southernLatitude7));
            capVertices2[vertexCount5] = Vec3(x29 * radius, fYA * radius, zq * radius);
            capNormals7[vertexCount5] = Vec3(x29 * radius5, fYA * radius5, zq * radius5);
            if (color)
                color9[vertexCount5] = *color;
            capUVs2[vertexCount5] = Vec2(capUX, uvX);
            sideD3[vertexCount5] = vertexCount5;
            ++vertexCount5;
            x29 = -static_cast<float>(SphereCos(angle72)) *
                  static_cast<float>(SphereCosValue(southernLatitude7 + angle36));
            fYA = static_cast<float>(SphereSin(angle72)) *
                  static_cast<float>(SphereCosValue(southernLatitude7 + angle36));
            zq = radius5 * static_cast<float>(SphereSinValue(southernLatitude7 + angle36));
            capVertices2[vertexCount5] = Vec3(x29 * radius, fYA * radius, zq * radius);
            capNormals7[vertexCount5] = Vec3(x29 * radius5, fYA * radius5, zq * radius5);
            if (color)
                color9[vertexCount5] = *color;
            capUVs2[vertexCount5] = Vec2(capUX, uvX + vStep3);
            sideD3[vertexCount5] = vertexCount5;
            ++vertexCount5;
            capUX += uStep;
        }
        uvX += vStep3;
        strips2[band] = strip;
    }

    sideShape8 = new Mesh(vertexCount5, capVertices2, capNormals7, color9, capUVs2, true, false,
                          intermediateBands5 * (slices * 2), intermediateBands5, strips2, sideD3);
    sideShape8->Update();
    rootUpdate6->AttachChildInAvailableSlot(sideShape8, true);
    return rootUpdate6;
}

namespace fnv_00c42b80 {
// Diagnostic /Ob1 build matches all 540 bytes; shipped flag set does not.
struct C42Tls
{
    int m_000[173];
    int m_2b4;
};
inline int C42GetState()
{
    return (*reinterpret_cast<::fnv_00c42b80::C42Tls *>(&::g_tlsBlock)).m_2b4;
}
inline void C42SetState(int x)
{
    (*reinterpret_cast<::fnv_00c42b80::C42Tls *>(&::g_tlsBlock)).m_2b4 = x;
}
struct C42Guard
{
    int m_00;
    C42Guard(int x)
    {
        m_00 = C42GetState();
        C42SetState(x);
    }
    ~C42Guard()
    {
        C42SetState(m_00);
    }
};
struct C42Heap
{
    void* FUN_00aa3e40(unsigned);
};
extern "C" C42Heap c42heap;
struct C42Object
{
    void FUN_0044dd60();
};
struct C42Node;
// Preserve the target's unreferenced 12-byte inline-local region.
struct C42Hole
{
    int m_00, m_04, m_08;
};
inline void C42Padding()
{
    C42Hole hole;
    (void)&hole;
}
struct C42Ref
{
    C42Node* m_00;
    ~C42Ref()
    {
        if (m_00)
            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(((C42Object*)m_00)));
    }
};
struct C42Node
{
    int m_00;
    C42Ref m_04;
    C42Node* Next()
    {
        return m_04.m_00;
    }
};
struct C42Count
{
    unsigned m_00;
    unsigned Get()
    {
        return m_00;
    }
};
struct C42Owner
{
    int m_00, m_04, m_08, m_0c;
    C42Node** m_10;
    C42Count* m_14;
    unsigned Count()
    {
        return m_14->Get();
    }
    C42Node** Data()
    {
        return m_10;
    }
};
struct C42List
{
    C42Owner* m_00;
    int m_04, m_08;
    unsigned m_0c;
    C42Node* m_10;
    void FUN_00c42b80();
};
// @fnv 0x00c42b80
void C42List::FUN_00c42b80()
{
    C42Guard _ctx(6);
    unsigned _iCount = m_00->Count() * 2;
    C42Node** _file = new C42Node*[_iCount];
    memmove(_file, m_00->Data(), _iCount * 4);
    C42Node* _count = 0;
    unsigned _len = 0;
    while (m_10)
    {
        C42Node* _handle = m_10;
        m_10 = m_10->Next();
        bool _found = false;
        for (unsigned i = 0; i < _iCount; ++i)
        {
            if (_handle == _file[i])
            {
                _found = true;
                break;
            }
        }
        if (_found)
        {
            _handle->m_04.m_00 = _count;
            _count = _handle;
            ++_len;
        }
        else
        {
            _handle->m_04.m_00 = 0;
            C42Padding();
            delete _handle;
        }
    }
    delete[] _file;
    m_10 = _count;
    m_0c = _len;
}
}

// @fnv 0x00c42b60
void FUN_00c42b60_class::FUN_00c42b60()
{
    while (*(int*)((char*)this + 0xc))
        reinterpret_cast<::fnv_00c42b80::C42List *>(this)->FUN_00c42b80();
}





int __cdecl FUN_00ec658f(void (__cdecl*)());


extern "C" double __cdecl FUN_00ec6cde(double);


void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

struct BBXHeap
{
    void FUN_00aa4060(void *p);
};

struct BBXRef
{
    int m_uiFilterValue;


    BBXRef(const char *s)
    {
        if (!s)
            m_uiFilterValue = (*reinterpret_cast<int *>(&::DAT_0109b220));
        else
            m_uiFilterValue = ((intptr_t)(::NiGlobalStringTable::AddString(s)));
    }
};

// @fnv 0x00c55200
void __cdecl FUN_00c55200()
{
    (*reinterpret_cast<::BBXRef * *>(&::g_pkString_c55)) = new BBXRef("BBX");
}




Node_00c474a0* __cdecl FUN_00c474a0(Node_00c474a0* a1);

void __cdecl use_all();


void FUN_00c552a0();

NiTriShape* __cdecl FUN_00c55360(float extent, NiPoint3* center, ColorA* color);



extern "C" char* __cdecl FUN_00ec7750(const char* pcString, const char* pcSearch);



void* __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int n);

int __cdecl FUN_00ec6da0(const char*, const char*);

char* __cdecl FUN_00ec6370(char*, const char*);

int __cdecl FUN_00eca4a6(const char*, const char*, ...);


void __cdecl FUN_00c4b220(FUN_00546780_shell* obj);




bool __cdecl FUN_00c52a80(void* param);


double __cdecl FUN_00ec9130(double x, double y);




extern "C++" 

FUN_00a746e0* __cdecl FUN_00c59660(float length, ColorA* color);


inline void NiMemcpyC509(void* pvDest, const void* pvSrc, unsigned int ItemUpdateArray)
{
    memcpy(pvDest, pvSrc, ItemUpdateArray);
}

class NiObjectC509
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
};

class TrackedNodeC509 : public NiObjectC509
{
  public:
    static bool IsExactKindOf(const NiRTTI* pkRTTI, const NiObjectC509* pkObject)
    {
        if (!pkObject)
            return false;
        return pkObject->GetRTTI() == pkRTTI;
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
    unsigned int m_uiTrackIndex;
};

class NiNodeC509
{
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
};

class TrackingNodeC509 : public NiNodeC509
{
  public:
    void FUN_00c509f0(NiObjectC509* pkChild, bool abFirstAvailableSlot);
    int* m_piChildSlots;
    unsigned int m_uiNumChildSlots;
};

// @fnv 0x00c509f0
void TrackingNodeC509::FUN_00c509f0(NiObjectC509* pkChild, bool abFirstAvailableSlot)
{
    if (!TrackedNodeC509::IsExactKindOf(&(*reinterpret_cast<const ::NiRTTI *>(&::g_0120436c)), pkChild))
        return;
    TrackedNodeC509* pkTracked = (TrackedNodeC509*)pkChild;
    unsigned int uiTrackIndex = pkTracked->m_uiTrackIndex;
    if (uiTrackIndex == (unsigned int)-1)
        return;
    if (uiTrackIndex < m_uiNumChildSlots)
    {
        if (m_piChildSlots[uiTrackIndex] != -1)
            return;
    }
    else
    {
        unsigned int uiGrowBlocks = (uiTrackIndex - m_uiNumChildSlots + 1) / 10 + 1;
        unsigned int uiNewSize = uiGrowBlocks * 10 + m_uiNumChildSlots;
        int* piMap = new int[uiNewSize];
        memset(piMap, -1, uiNewSize * sizeof(int));
        NiMemcpyC509(piMap, m_piChildSlots, m_uiNumChildSlots * sizeof(int));
        delete[] m_piChildSlots;
        m_piChildSlots = piMap;
        m_uiNumChildSlots = uiNewSize;
    }
    reinterpret_cast<::fnv_00a5ed10::ChildNode *>(this)->FUN_00a5ed10((::fnv_00a5ed10::ChildObj *)(pkChild), abFirstAvailableSlot);
    m_piChildSlots[uiTrackIndex] = reinterpret_cast<::FUN_00c50ec0_cls *>(this)->FindItemIndex((intptr_t)(pkChild));
}

struct NiPlane : ::NiMemObject
{
    ::NiPoint3 normal;
    float constant;
    NiPlane();
};

struct FrustumPlaneSet : ::NiMemObject
{
    NiPlane planes[6];
    unsigned int activePlanes;
    __forceinline FrustumPlaneSet()
    {
        activePlanes = 63;
    }
};

struct FrustumArrayConstruction
{
    void FUN_00c4a360(void* elements, int count);
};

// Sets vtbl to DAT_010c1e88 and zeroes data, unk08 and unk0C; the size is a constant 0, so the allocation path is never reached.
// @fnv 0x00c49fe0
FUN_00c49fe0_Cls::FUN_00c49fe0_Cls()
{
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    vtbl = (void*)&DAT_010c1e88;
    {
    unsigned int nSize = 0;
    data = 0;
    unk08 = 0;
    unk0C = 0;
    if (nSize < 0)
        nSize = 0;
    if (nSize > 0) {
        data = ((S00c49fe0_Vt*)this)->v1(nSize);
        unk0C = nSize;
    }
    }
    if ((0, (unsigned)0) > 0u) {
        reinterpret_cast<::FrustumArrayConstruction *>(this)->FUN_00c4a360(data, 0);
        unk08 = 0;
    }}

// @fnv 0x00c4a070
void FUN_00c4a070::SetSize(unsigned int uiNewSize, bool bFree)
{
    if (uiNewSize == 0)
    {
        reinterpret_cast<::FUN_00c4a9c0_class *>(this)->ReleaseBuffer(bFree);
        return;
    }
    if (uiNewSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pBuffer = Allocate(uiNewSize);
            m_uiCapacity = uiNewSize;
        }
        else
        {
            reinterpret_cast<::CachedRef_b5611 *>(this)->UpdateCachedRef(uiNewSize, m_uiSize);
            m_uiCapacity = uiNewSize;
        }
        reinterpret_cast<::FrustumArrayConstruction *>(this)->FUN_00c4a360(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
    else if (uiNewSize < m_uiSize)
    {
        DestructItems(m_pBuffer + uiNewSize, m_uiSize - uiNewSize);
        m_uiSize = uiNewSize;
        if (bFree && uiNewSize <= m_uiCapacity >> 2)
        {
            Shrink(uiNewSize);
        }
    }
    else
    {
        reinterpret_cast<::FrustumArrayConstruction *>(this)->FUN_00c4a360(m_pBuffer + m_uiSize, uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
}

// @fnv 0x00c4a360
void FrustumArrayConstruction::FUN_00c4a360(void* elements, int count)
{
    for (unsigned int index = 0; index < static_cast<unsigned int>(count); ++index)
    {
        new (static_cast<FrustumPlaneSet*>(elements) + index) FrustumPlaneSet;
    }
}





typedef unsigned long (*LPTHREAD_START_ROUTINE)(void*);












extern "C" U32 (*FUN_00fdf1bc)(void*, U32, U32);





typedef void (__cdecl *CbQ)(void*, bool);


































struct ParticleDetachAt {

    virtual void vfn_0000(); virtual void vfn_0004(); virtual void vfn_0008(); virtual void vfn_000c();

    virtual void vfn_0010(); virtual void vfn_0014(); virtual void vfn_0018(); virtual void vfn_001c();

    virtual void vfn_0020(); virtual void vfn_0024(); virtual void vfn_0028(); virtual void vfn_002c();

    virtual void vfn_0030(); virtual void vfn_0034(); virtual void vfn_0038(); virtual void vfn_003c();

    virtual void vfn_0040(); virtual void vfn_0044(); virtual void vfn_0048(); virtual void vfn_004c();

    virtual void vfn_0050(); virtual void vfn_0054(); virtual void vfn_0058(); virtual void vfn_005c();

    virtual void vfn_0060(); virtual void vfn_0064(); virtual void vfn_0068(); virtual void vfn_006c();

    virtual void vfn_0070(); virtual void vfn_0074(); virtual void vfn_0078(); virtual void vfn_007c();

    virtual void vfn_0080(); virtual void vfn_0084(); virtual void vfn_0088(); virtual void vfn_008c();

    virtual void vfn_0090(); virtual void vfn_0094(); virtual void vfn_0098(); virtual void vfn_009c();

    virtual void vfn_00a0(); virtual void vfn_00a4(); virtual void vfn_00a8(); virtual void vfn_00ac();

    virtual void vfn_00b0(); virtual void vfn_00b4(); virtual void vfn_00b8(); virtual void vfn_00bc();

    virtual void vfn_00c0(); virtual void vfn_00c4(); virtual void vfn_00c8(); virtual void vfn_00cc();

    virtual void vfn_00d0(); virtual void vfn_00d4(); virtual void vfn_00d8(); virtual void vfn_00dc();

    virtual void vfn_00e0(); virtual void vfn_00e4(); virtual void vfn_00e8();

    virtual void vfn_00ec(int, NiPointer<NiRefObject>*);

    void FUN_00c50d20(int arg);

};

// @fnv 0x00c50d20
void ParticleDetachAt::FUN_00c50d20(int arg)

{

    NiPointer<NiRefObject> p;

    vfn_00ec(arg, &p);

}

class TPoint3
{
public:
    float x, y, z;
    TPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};

class TMatrix3
{
public:
    float m_afEntries[3][3];

    void SetXRotation(float fAngleDifference)
    {
        float sn, cs;
        ::fnv_SinCos(fAngleDifference, sn, cs);

        m_afEntries[0][0] = 1.0f;
        m_afEntries[0][1] = 0.0f;
        m_afEntries[0][2] = 0.0f;
        m_afEntries[1][0] = 0.0f;
        m_afEntries[1][1] = cs;
        m_afEntries[1][2] = sn;
        m_afEntries[2][0] = 0.0f;
        m_afEntries[2][1] = -sn;
        m_afEntries[2][2] = cs;
    }
};

class TAVObject
{
public:
    void* m_vtbl;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30;
    TMatrix3 m_kRotate;
    TPoint3 m_kTranslate;

    void SetLocalRotation(const TMatrix3& kRot) { m_kRotate = kRot; }
    void GetTransformScale(const TPoint3& kTrans) { m_kTranslate = kTrans; }
    void GetTransformScale(float x, float y, float z) { GetTransformScale(TPoint3(x, y, z)); }
};

class BoundingVolumeNode
{
public:
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8;

    BoundingVolumeNode(unsigned short usNumChildren);

    virtual void Unk00(); virtual void Unk01(); virtual void Unk02(); virtual void Unk03();
    virtual void Unk04(); virtual void Unk05(); virtual void Unk06(); virtual void Unk07();
    virtual void Unk08(); virtual void Unk09(); virtual void Unk0A(); virtual void Unk0B();
    virtual void Unk0C(); virtual void Unk0D(); virtual void Unk0E(); virtual void Unk0F();
    virtual void Unk10(); virtual void Unk11(); virtual void Unk12(); virtual void Unk13();
    virtual void Unk14(); virtual void Unk15(); virtual void Unk16(); virtual void Unk17();
    virtual void Unk18(); virtual void Unk19(); virtual void Unk1A(); virtual void Unk1B();
    virtual void Unk1C(); virtual void Unk1D(); virtual void Unk1E(); virtual void Unk1F();
    virtual void Unk20(); virtual void Unk21(); virtual void Unk22(); virtual void Unk23();
    virtual void Unk24(); virtual void Unk25(); virtual void Unk26(); virtual void Unk27();
    virtual void Unk28(); virtual void Unk29(); virtual void Unk2A(); virtual void Unk2B();
    virtual void Unk2C(); virtual void Unk2D(); virtual void Unk2E(); virtual void Unk2F();
    virtual void Unk30(); virtual void Unk31(); virtual void Unk32(); virtual void Unk33();
    virtual void Unk34(); virtual void Unk35(); virtual void Unk36();
    virtual void AttachChildInAvailableSlot(TAVObject* pkChild, bool abFirstAvailableSlot);
};

// @fnv 0x00c58d30
BoundingVolumeNode* FUN_00c58d30(float fRadius, float m_fGlyphExtent, float fZ,
    unsigned short usA, unsigned short usB, int iParam)
{
    TAVObject* pkShape3;
    BoundingVolumeNode* pkNode;
    TAVObject* pkShape;
    TMatrix3 kRot;
    TAVObject* pkGeomX;

    pkNode = new BoundingVolumeNode(0);

    pkShape3 = ((::TAVObject *)(::fnv_00c584a0::FUN_00c584a0(fRadius, m_fGlyphExtent, fZ, usA, usB, (::fnv_00c584a0::MeshColor *)(iParam))));

    pkShape = ((::TAVObject *)(::fnv_00c584a0::FUN_00c584a0(fRadius, 0.0f, 0.0f, usA, 1, (::fnv_00c584a0::MeshColor *)(iParam))));
    kRot.SetXRotation(::DAT_010c2c34);
    pkShape->SetLocalRotation(kRot);

    pkGeomX = ((::TAVObject *)(::fnv_00c584a0::FUN_00c584a0(fRadius, 0.0f, 0.0f, usA, 1, (::fnv_00c584a0::MeshColor *)(iParam))));
    pkGeomX->GetTransformScale(0.0f, 0.0f, fZ);

    pkNode->AttachChildInAvailableSlot(pkShape3, true);
    pkNode->AttachChildInAvailableSlot(pkShape, true);
    pkNode->AttachChildInAvailableSlot(pkGeomX, true);
    return pkNode;
}

#include "generated/data/staging/blk_00c40000_od.inc"
#include "generated/data/staging/blk_00c40000_od_ob1_variant.inc"
#include "generated/data/staging/blk_00c40000_od_ehs_ob1_noehsc_variant.inc"
#include "generated/data/staging/blk_00c40000_od_ob1_variant_rtm_variant.inc"
#include "generated/data/staging/blk_00c40000_od_ob1_variant_helpers_variant.inc"
