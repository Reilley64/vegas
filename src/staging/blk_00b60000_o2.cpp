
// src/staging/blk_00b60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "fnv/symbols_00ba8000.h"
#include "fnv/symbols_00bc3000.h"
#include "fnv/tls.h"
#include <cstdint>
#include <new>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/A72BB0_DataStreamOwner.h"
#include "fnv/decl/B9B3D0Shader.h"
#include "fnv/decl/B9F30Owner.h"
#include "fnv/decl/BA97B0Owner.h"
#include "fnv/decl/BSBatchRenderer__GeometryGroup.h"
#include "fnv/decl/BSRenderedTexture.h"
#include "fnv/decl/BSShaderLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CameraState4E9.h"
#include "fnv/decl/D3DRenderStateGroup.h"
#include "fnv/decl/E7DE90Owner.h"
#include "fnv/decl/E7DEF0TextureStage.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004bc320_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5be90_shell.h"
#include "fnv/decl/FUN_00a64ce0_shell.h"
#include "fnv/decl/FUN_00a726a0_cls.h"
#include "fnv/decl/FUN_00a72ca0_Class.h"
#include "fnv/decl/FUN_00b702b0_shell.h"
#include "fnv/decl/FUN_00b98970_shell.h"
#include "fnv/decl/FUN_00b9b3b0_class.h"
#include "fnv/decl/FUN_00bd8f90.h"
#include "fnv/decl/FUN_00c3a8a0_cls.h"
#include "fnv/decl/FUN_00c663d0.h"
#include "fnv/decl/FUN_00e7ecd0_cls.h"
#include "fnv/decl/FnvCpu_FUN_00a7b850_CpuObject.h"
#include "fnv/decl/Lighting30Shader.h"
#include "fnv/decl/LinkObjectA5.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiD3DPass.h"
#include "fnv/decl/NiGeometryData_shell.h"
#include "fnv/decl/RenderAccumulator.h"
#include "fnv/decl/RenderPassB71.h"
#include "fnv/decl/RenderTargetManager.h"
#include "fnv/decl/S_00b601a0_Map.h"
#include "fnv/decl/S_00ba92c0_Prop.h"
#include "fnv/decl/S_00ee8330_CubeMap.h"
#include "fnv/decl/ShaderPropertyRecord.h"
#include "fnv/decl/StateGroup.h"
#include "fnv/decl/TallGrassShader.h"
#include "fnv/decl/Tbl00b57f20.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a730e0__FUN_00a730e0_cls.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00b79de0__FUN_00b79de0.h"
#include "fnv/decl/fnv_00c1b4a0__RefObjectList.h"
#include "fnv/decl/fnv_00e814b0__UnkShader.h"
#include "fnv/symbols_0043a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0068b000.h"
#include "fnv/symbols_00a75000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a9f000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00b54000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_00b61000.h"
#include "fnv/symbols_00b63000.h"
#include "fnv/symbols_00b64000.h"
#include "fnv/symbols_00b65000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_00b6c000.h"
#include "fnv/symbols_00b70000.h"
#include "fnv/symbols_00b71000.h"
#include "fnv/symbols_00b7a000.h"
#include "fnv/symbols_00b7c000.h"
#include "fnv/symbols_00b97000.h"
#include "fnv/symbols_00b98000.h"
#include "fnv/symbols_00b99000.h"
#include "fnv/symbols_00ba9000.h"
#include "fnv/symbols_00c02000.h"
#include "fnv/symbols_00c03000.h"
#include "fnv/symbols_00e6e000.h"
#include "fnv/symbols_00e7f000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_00ee8000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010ad000.h"
#include "fnv/symbols_010ef000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ab000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_011fb000.h"
#include "fnv/symbols_011fc000.h"
#include "fnv/symbols_011fd000.h"
#include "fnv/symbols_011fe000.h"
#include "fnv/symbols_011ff000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01270000.h"
#include "fnv/symbols_01272000.h"
#include "../../include/layout_support.h"

#include "fnv/decl/NiTPointerListBase.h"

struct FUN_00b6f4a0_class
{
    float f0x00;
    float f0x04;
    float f0x08;
    float f0x0c;
    float f0x10;
    float f0x14;
    float f0x18;
    float f0x1c;
    float f0x20;
    float f0x24;
    float f0x28;
    float f0x2c;
    float f0x30;
    float f0x34;
    float f0x38;
    float f0x3c;
    float f0x40;
    float f0x44;
    float f0x48;
    float f0x4c;
    float f0x50;
    float f0x54;
    float f0x58;
    float f0x5c;
    float f0x60;
    float f0x64;
    float f0x68;
    float f0x6c;
    float f0x70;
    float f0x74;
    float f0x78;
    float f0x7c;
    void CopySourceValues(const float* src);
};

// Copies four floats from src into f0x70..f0x7c, skipping any field that currently equals -1.0f.
// @fnv 0x00b6f4a0
void FUN_00b6f4a0_class::CopySourceValues(const float* afSource)
{
    if (f0x70 != -1.0f)
        f0x70 = afSource[0];
    if (f0x74 != -1.0f)
        f0x74 = afSource[1];
    if (f0x78 != -1.0f)
        f0x78 = afSource[2];
    if (f0x7c != -1.0f)
        f0x7c = afSource[3];
}

extern float DAT_011f9ee0;
extern float DAT_011f9ee4;
extern float DAT_011f9ee8;
extern float DAT_011f9eec;

// Stores a and c into two globals and their differences b-a and d-c into two more globals.
// @fnv 0x00b60120
void FUN_00b60120(float a, float b, float c, float d)
{
    DAT_011f9ee0 = a;
    DAT_011f9ee4 = b - a;
    DAT_011f9ee8 = c;
    DAT_011f9eec = d - c;
}

extern int DAT_010ade18;
void NiFreeAlias(void* p);
struct NiTMapBaseStub
{
    void RemoveAll();
};
struct FUN_00b603e0_class
{
    intptr_t p0;
    int p4;
    void* p8;
    void FUN_00b603e0();
};
// @fnv 0x00b603e0
void FUN_00b603e0_class::FUN_00b603e0()
{
    p0 = (intptr_t)&DAT_010ade18;
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    NiFreeAlias(p8);
}

namespace fnv_00b60400 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
void __cdecl NiFreeAlias(void*);
struct FUN_00b60400_class
{
    int* pMap;
    int dummy;
    void* pValue;
    void FUN_00b60400();
};
// @fnv 0x00b60400
void FUN_00b60400_class::FUN_00b60400()
{
    pMap = &::DAT_010ade34;
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    NiFreeAlias(pValue);
}
}  // namespace fnv_00b60400

struct MemoryManager
{
    void Deallocate(void*);
};
struct FUN_00b60420_class
{
    void FUN_00b60420();
    void* FUN_00b60620(int flags);
};
namespace fnv_00b60c70 {
struct MemoryManager
{
    void Deallocate(void* p);
};
struct FUN_00b60c70_class
{
    void FUN_00b60360();
    void* DestroyIfRequested(bool dealloc);
};
// Calls FUN_00b60360, deallocates this via g_memoryManager when dealloc is set, and returns this.
// @fnv 0x00b60c70
void* FUN_00b60c70_class::DestroyIfRequested(bool dealloc)
{
    FUN_00b60360();
    if (dealloc & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00b60c70::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00b60c70

void __cdecl FUN_00b60d80(void);

struct FUN_00b61220_class
{
    void* DestroyIfFlagged(int flag);
};

// Calls FUN_00b60d80, deletes this with size 0x98 when flag has bit 0 set, and returns this.
// @fnv 0x00b61220
void* FUN_00b61220_class::DestroyIfFlagged(int aiFlags)
{
    FUN_00b60d80();
    if (aiFlags & 1)
        operator delete(this, 0x98);
    return this;
}

struct FUN_00b63bd0_Object
{
    void* vtbl;
    int unk04;
    char unk08;
};

// @fnv 0x00b63bd0
void FUN_00b63bd0(void* apObject, int aiValue, char c)
{
    FUN_00b63bd0_Object* pObject = (FUN_00b63bd0_Object*)apObject;
    pObject->unk04 = aiValue;
    pObject->unk08 = c;
}

namespace fnv_00b63d60 {
struct NiTMapBaseStub
{
    void RemoveAll();
};
void NiFreeAlias(void*);
struct FUN_00b63d60_class
{
    int* p;
    int x;
    intptr_t y;
    void FUN_00b63d60();
};
// @fnv 0x00b63d60
void FUN_00b63d60_class::FUN_00b63d60()
{
    p = &(*reinterpret_cast<int *>(&::DAT_010adfbc));
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    NiFreeAlias((void*)y);
}
}  // namespace fnv_00b63d60

void __cdecl FUN_00b656e0();

struct FUN_00b664f0_class
{
    void* FUN_00b664f0(unsigned int flags);
};

// Calls FUN_00b656e0, then deletes this with size 0x280 if flags has bit 0 set, and returns this.
// @fnv 0x00b664f0
void* FUN_00b664f0_class::FUN_00b664f0(unsigned int flags)
{
    FUN_00b656e0();
    if (flags & 1)
        operator delete(this, 0x280);
    return this;
}

struct NiAccumulator
{
    void ClearCamera();
};
struct NiRenderer
{
    void* vtbl;
    unsigned int m_uiRefCount;
    void* unk08;
    void* unk0c;
    static NiRenderer* ms_pRenderer;
};
struct FUN_00b66570_class
{
    char pad00[0x19c];
    int unk19c;
    void FUN_00b66570();
};
// @fnv 0x00b66570
void FUN_00b66570_class::FUN_00b66570()
{
    if (!this->unk19c)
        ::fnv_00b65c60::FUN_00b65c60((::AccumWIP *)(void *)(this));
    NiRenderer::ms_pRenderer->unk0c = 0;
    ((NiAccumulator*)this)->ClearCamera();
}

// @fnv 0x00b66760
int __cdecl FUN_00b66760(int a)
{
    if (a != 252 && a != 258)
        return 0;
    return 1;
}

void __cdecl FUN_00b6a520();


struct FUN_00b6adb0_class
{
    void* FUN_00b6adb0(int flags);
};

// Calls FUN_00b6a520, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00b6adb0
void* FUN_00b6adb0_class::FUN_00b6adb0(int flags)
{
    FUN_00b6a520();
    if (flags & 1)
        operator delete(this, 336);
    return this;
}

void __cdecl FUN_00b6aef0();

struct FUN_00b6b160_class
{
    FUN_00b6b160_class* FUN_00b6b160(int flags);
};

// Calls FUN_00b6aef0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00b6b160
FUN_00b6b160_class* FUN_00b6b160_class::FUN_00b6b160(int flags)
{
    FUN_00b6aef0();
    if (flags & 1)
        operator delete(this, 0x40);
    return this;
}


// @fnv 0x00b6b910
void __cdecl CopyBlock48(void* dst, const void* src)
{
    ::fnv_00ba91a0::FUN_00ba91a0((::fnv_00ba91a0::Obj *)(dst), 0x30, (bool)(src));
}

extern double DAT_010ae8b0;
extern double DAT_010ae8b8;
extern double DAT_010ae8c0;

struct FUN_00b719e0_class
{
    float f0;
    float f1;
    float f2;
    float ComputeWeightedSum();
};

// Returns f1*DAT_010ae8c0 + f0*DAT_010ae8b8 + f2*DAT_010ae8b0, a weighted sum of the three floats.
// @fnv 0x00b719e0
float FUN_00b719e0_class::ComputeWeightedSum()
{
    return f1 * DAT_010ae8c0 + f0 * DAT_010ae8b8 + f2 * DAT_010ae8b0;
}

struct StageReturn
{
    char pad00[0x60];
    int m_iObjectReferenceCount;
};

struct FUN_00b71b70_class
{
    StageReturn* m_stage;
    void ReleaseStage();
};

// @fnv 0x00b71b70
void FUN_00b71b70_class::ReleaseStage()
{
    StageReturn* stage = m_stage;
    if (stage)
    {
        if (--stage->m_iObjectReferenceCount == 0)
            reinterpret_cast<::FUN_00e7ecd0_cls *>((stage))->FUN_00e7ecd0();
    }
}


struct SetEntryField_Entry
{
    void* vtbl;
    int unk04;
    int unk08;
};
struct SetEntryField_Owner
{
    char pad00[0x24];
    SetEntryField_Entry** m_ppEntries;
};

// @fnv 0x00b7c150
void SetEntryField(int aiIndex)
{
    SetEntryField_Owner* base = (SetEntryField_Owner*)DAT_0126f74c;
    SetEntryField_Entry** p = base->m_ppEntries;
    p[aiIndex]->unk08 = DAT_011f95e4;
}

void __cdecl UpdateFogShaderConstants();

struct FUN_00b7deb0_class
{
    void UpdateSpawnedObjectFlags();
    void FUN_00b7c580();
    void FUN_00b7c600();
    void FUN_00b7deb0();
};

// @fnv 0x00b7deb0
void FUN_00b7deb0_class::FUN_00b7deb0()
{
    UpdateFogShaderConstants();
    UpdateSpawnedObjectFlags();
    FUN_00b7c580();
    FUN_00b7c600();
}

struct NiTexture
{
};
struct NiObjectNET_stub
{
};
class NiTexture;
template <class> class NiPointer;
struct BSShaderManager
{
    static void GetTexture(const char* name, bool a, NiTexture*& out, bool b, bool c);
public:
    static void SetRenderMode(unsigned int);
public:
    static void GetTexture(const char *, bool, ::NiPointer< ::NiTexture> &, bool, bool);
};
struct FUN_00b6f4f0_class
{
    int m_0x64;
    NiTexture* m_tex;
    void SetTextureByName(intptr_t a);
    char pad08[0x58];
    NiTexture * unk60;
    int unk64;
};
// Calls FUN_00a5c6a0 with a, then if the name at offset 0x64 is set, looks up that texture via BSShaderManager::GetTexture into the pointer at 0x60.
// @fnv 0x00b6f4f0
void FUN_00b6f4f0_class::SetTextureByName(intptr_t a)
{
    reinterpret_cast<::LinkObjectA5 *>((((NiObjectNET_stub*)this)))->FUN_00a5c6a0((*(::NiStream *)(a)));
    if (this->unk64)
        ::BSShaderManager::GetTexture((const char*)*(uintptr_t*)&this->unk64, true, (::NiPointer< ::NiTexture> &)(this->unk60),
                                    false, false);
}


// Returns 1 when DAT_011f9427 is 0, DAT_011f95e4 is nonzero, DAT_011f91d8 has bit 0x20 set, and _fnv_particle_shader_renderer_level is at least 2; otherwise 0.
// @fnv 0x00b60330
int __cdecl IsParticleShaderRendererEnabled()
{
    if (DAT_011f9427 == 0 && DAT_011f95e4 != 0 && ((*reinterpret_cast<unsigned char *>(&::fnv_005bf7b0::DAT_011f91d8)) & 0x20) && ::DAT_011f91c0 >= 2)
        return 1;
    return 0;
}

struct P03MM
{
};
// @fnv 0x00b603d0
void* __cdecl FUN_00b603d0()
{
    return reinterpret_cast<::MemoryManagerStandIn *>((((P03MM*)&g_memoryManager)))->FUN_00aa3e40(0xc);
}

struct NiFreeAliasStub
{
    void NiFree(void*);
};
struct FUN_00b605a0_class
{
    intptr_t m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    FUN_00b605a0_class* FUN_00b605a0(int flags);
};
// @fnv 0x00b605a0
FUN_00b605a0_class* FUN_00b605a0_class::FUN_00b605a0(int flags)
{
    m_iWordAt00 = (intptr_t)&DAT_010ade18;
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    NiFreeAlias(m_8);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

struct FUN_00b60d70_Object
{
    char pad00[0x90];
    int unk90;
};

// @fnv 0x00b60d70
void FUN_00b60d70(void* self, int, int value)
{
    ((FUN_00b60d70_Object*)self)->unk90 = value;
}

struct RecursiveSpinLock
{
};
extern unsigned int DAT_011c5f84;
struct NiTAbstractPoolAllocator_unsigned_int
{
    struct LinkedListEntry
    {
        void* m_pkNext;
        void* m_pkPrev;
        int m_uiSize;
    };
    static LinkedListEntry* ms_pFreeList;
};
// @fnv 0x00b63df0
void FreePoolNode(void* p)
{
    NiTAbstractPoolAllocator_unsigned_int::LinkedListEntry* n = (NiTAbstractPoolAllocator_unsigned_int::LinkedListEntry*)p;
    *(unsigned char*)&n->m_uiSize = 0;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(g_011c5f80))->FUN_0040fbf0((char *)(0));
    n->m_pkPrev = 0;
    n->m_pkNext = NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList;
    --DAT_011c5f84;
    NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList = n;
    if (!DAT_011c5f84)
        *(unsigned int*)&g_011c5f80 = 0;
}

extern int DAT_011ff9f0;
enum BSRENDERSTATE_LOCK;
struct BSRenderStateManager
{
public:
    static void SetDepthBufferEnabled(bool, ::BSRENDERSTATE_LOCK);
public:
    static void SetColorWriteMask(unsigned int, ::BSRENDERSTATE_LOCK);
};
struct AccumWIP
{
    void* vtbl;
    unsigned int m_uiRefCount;
    void* unk08;
};
// @fnv 0x00b64530
void __cdecl FUN_00b64530(AccumWIP* self)
{
    if (self->unk08)
    {
        ::BSRenderStateManager::SetDepthBufferEnabled(false, (::BSRENDERSTATE_LOCK)(1));
        reinterpret_cast<::RenderAccumulator *>((self))->FUN_00b63770(0x2d8, 0x2ef, false, -1);
        --DAT_011ff9f0;
        ::BSRenderStateManager::SetDepthBufferEnabled(false, (::BSRENDERSTATE_LOCK)(0));
    }
}

struct BSShaderManagerRenderMode
{
};
struct FUN_00b66520_class
{
    char pad00[0x19c];
    unsigned int unk19c;
    void ApplyRenderMode();
};
// @fnv 0x00b66520
void FUN_00b66520_class::ApplyRenderMode()
{
    ::BSShaderManager::SetRenderMode(this->unk19c);
    if (!*(int*)&this->unk19c)
    {
        ::fnv_00b65ae0::FUN_00b65ae0((::AccumWIP *)(void *)(this));
        return;
    }
    if ((*reinterpret_cast<void (*(*)[])(void *)>(&::DAT_011f9f40))[this->unk19c])
    {
        (*reinterpret_cast<void (*(*)[])(void *)>(&::DAT_011f9f40))[this->unk19c](this);
        return;
    }
    (*reinterpret_cast<void (*(*)[])(void *)>(&::DAT_011f9f40))[0](this);
}

bool FUN_00b70270(void*);
// @fnv 0x00b665c0
char FUN_00b665c0(std::intptr_t a)
{
    FUN_00b70270((void*)a);
    return 0;
}

struct NiStream
{
    void* GetLoadedObject();
};
class NiRTTI;
struct NiObject
{
    virtual ~NiObject();
    virtual void v1();
    long m_iRefCount;
public:
    ::NiObject *DynamicCast(const ::NiRTTI *);
};
struct FUN_00b6f460_class
{
    char pad00[0xa4];
    NiObject * unka4;
    void LoadAndSetAdditional(NiStream* kStream);
};
struct FUN_00b71ad0_class
{
    char pad00[0x1a8];
    char m_acSource[0x60];
    char m_bHasSource;
    void CopySourceData(const void* src);
};
// Copies 0x60 bytes from src into m_acSource and sets m_bHasSource, or clears that flag when src is null.
// @fnv 0x00b71ad0
void FUN_00b71ad0_class::CopySourceData(const void* src)
{
    if (src)
    {
        memmove(m_acSource, src, 0x60);
        m_bHasSource = 1;
    }
    else
        m_bHasSource = 0;
}

struct FUN_00b7b930_Matrix
{
    float m[4][4];
};
struct FUN_00b7b930_Point3
{
    float x, y, z;
};
struct FUN_00b7b930_Transform
{
    float rot[3][3];
    FUN_00b7b930_Point3 trans;
    float scale;
};
struct FUN_00b7b930_Entry
{
    int pad0;
    int pad4;
    bool bEnabled;
};
struct FUN_00b7b930_Target
{
    char pad[0x1c];
    int iIndex;
};
struct FUN_00b7b930_Arg
{
    char pad[0xc];
    FUN_00b7b930_Target* pTarget;
};
struct FUN_00b7b930_Ctx
{
    char pad[0x194];
    int iValue;
};


// If the entry is enabled, the target is valid and the context value is nonzero, writes a world or identity-offset matrix into DAT_011fd968.
// @fnv 0x00b7b930
void UpdateWorldMatrix(FUN_00b7b930_Arg* pkArg, const void* iIdentity, const FUN_00b7b930_Transform* pkWorld)
{
    if (!(*reinterpret_cast<::FUN_00b7b930_Entry * *>(&::DAT_011febe4))->bEnabled)
        return;
    if (!pkArg->pTarget || pkArg->pTarget->iIndex == -1)
        return;
    if (!((::FUN_00b7b930_Ctx *)(::FUN_00b4f5c0()))->iValue)
        return;
    FUN_00b7b930_Matrix kMat;
    if (!iIdentity)
    {
        kMat.m[0][0] = pkWorld->rot[0][0];
        kMat.m[0][1] = pkWorld->rot[0][1];
        kMat.m[0][2] = pkWorld->rot[0][2];
        kMat.m[0][3] = pkWorld->trans.x;
        kMat.m[1][0] = pkWorld->rot[1][0];
        kMat.m[1][1] = pkWorld->rot[1][1];
        kMat.m[1][2] = pkWorld->rot[1][2];
        kMat.m[1][3] = pkWorld->trans.y;
        kMat.m[2][0] = pkWorld->rot[2][0];
        kMat.m[2][1] = pkWorld->rot[2][1];
        kMat.m[2][2] = pkWorld->rot[2][2];
        kMat.m[2][3] = pkWorld->trans.z;
        kMat.m[3][0] = 0.0f;
        kMat.m[3][1] = 0.0f;
        kMat.m[3][2] = 0.0f;
        kMat.m[3][3] = pkWorld->scale;
        (*reinterpret_cast<::FUN_00b7b930_Matrix *>((void *)&::DAT_011fd968)) = kMat;
    }
    else
    {
        FUN_00b7b930_Point3 kAdjust = (*reinterpret_cast<::FUN_00b7b930_Point3 *>(&::DAT_011f474c));
        kMat.m[0][0] = 1.0f;
        kMat.m[0][1] = 0.0f;
        kMat.m[0][2] = 0.0f;
        kMat.m[0][3] = kAdjust.x;
        kMat.m[1][0] = 0.0f;
        kMat.m[1][1] = 1.0f;
        kMat.m[1][2] = 0.0f;
        kMat.m[1][3] = kAdjust.y;
        kMat.m[2][0] = 0.0f;
        kMat.m[2][1] = 0.0f;
        kMat.m[2][2] = 1.0f;
        kMat.m[2][3] = kAdjust.z;
        kMat.m[3][0] = 0.0f;
        kMat.m[3][1] = 0.0f;
        kMat.m[3][2] = 0.0f;
        kMat.m[3][3] = 1.0f;
        (*reinterpret_cast<::FUN_00b7b930_Matrix *>((void *)&::DAT_011fd968)) = kMat;
    }
}

struct _Base_00441d20
{
    ~_Base_00441d20();
};
struct BSStream
{
    ~BSStream();
};
struct FUN_00b606f0_class : _Base_00441d20
{
    char _00[0x31 - sizeof(_Base_00441d20)];
    BSStream _30;
    ~FUN_00b606f0_class();
};
// Destroys the embedded BSStream member and the base object.
// @fnv 0x00b606f0
FUN_00b606f0_class::~FUN_00b606f0_class()
{}

struct BSShaderAccumulatorRenderers
{
    char pad000[0x174];
    void* m_apkBatchRenderer[6];
    unsigned int m_uiBatchRendererCount;
};
struct BSShaderAccumulator : BSShaderAccumulatorRenderers
{
    void FUN_00b63120(unsigned int a, int b);
};
// Iterates the batch renderers, calling HasListedItemInRange on each until one returns true.
// @fnv 0x00b63120
void BSShaderAccumulator::FUN_00b63120(unsigned int auiArg, int aiArg)
{
    unsigned int i = 0;
    bool cVar1 = false;
    if (m_uiBatchRendererCount > i)
    {
        BSShaderAccumulator** ppEntry = (BSShaderAccumulator**)m_apkBatchRenderer;
        do
        {
            if (cVar1)
                break;
            cVar1 = reinterpret_cast<::FUN_00b98970_shell *>(((*ppEntry)))->HasListedItemInRange(auiArg, aiArg);
            ++i;
            ++ppEntry;
        } while (i < m_uiBatchRendererCount);
    }
}

class NiRenderTargetGroup;
struct GraphicsRenderer
{
public:
    bool BeginUsingRenderTargetGroup(::NiRenderTargetGroup *, unsigned int);
};
struct NiRendererHelper
{
    void TryUnlock();
};
void __cdecl FUN_00b6b0b0();
int __cdecl GetCurrentItem();

// @fnv 0x00b6b840
void FUN_00b6b840()
{
    if (DAT_011fa020 != 0)
    {
        ((NiRendererHelper*)NiRenderer::ms_pRenderer)->TryUnlock();
        ::fnv_00b6b0b0::FUN_00b6b0b0();
        intptr_t r = GetCurrentItem();
        if (r == 0)
        {
            NiRenderer* p = NiRenderer::ms_pRenderer;
            r = (*(int(**)(NiRenderer*))(*(uintptr_t*)p + 0xc8))(p);
        }
        ((GraphicsRenderer*)NiRenderer::ms_pRenderer)->BeginUsingRenderTargetGroup((::NiRenderTargetGroup *)(void *)((void*)r), 0);
    }
}

struct FUN_00b605e0_class
{
    int* pvt;
    int p4;
    void* p8;
    FUN_00b605e0_class(int flags);
};
// Initialises the vtable pointer, clears the map, frees p8, and deallocates this when flags has bit 0 set.
// @fnv 0x00b605e0
FUN_00b605e0_class::FUN_00b605e0_class(int flags)
{
    pvt = &DAT_010ade34;
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    NiFreeAlias(p8);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
}

struct FUN_00b60c90_class : FUN_00b606f0_class
{
    FUN_00b60c90_class* FUN_00b60c90(int flags);
};
// Runs the base class destructor, frees this via g_memoryManager when flags has bit 0 set, and returns this.
// @fnv 0x00b60c90
FUN_00b60c90_class* FUN_00b60c90_class::FUN_00b60c90(int flags)
{
    this->FUN_00b606f0_class::~FUN_00b606f0_class();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

void __cdecl FUN_00b60b50();
struct FUN_00b60f30_class
{
    FUN_00b60f30_class* FUN_00b60f30(int flags);
};
// Calls FUN_00b60b50, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00b60f30
FUN_00b60f30_class* FUN_00b60f30_class::FUN_00b60f30(int flags)
{
    FUN_00b60b50();
    if (flags & 1)
        operator delete(this, 0x38);
    return this;
}

struct BSBatchRenderer
{
};
struct FUN_00b630c0_class : BSShaderAccumulatorRenderers
{
    void FUN_00b630c0();
};
// Iterates the batch renderers and calls ClearAllGroups(0) on each.
// @fnv 0x00b630c0
void FUN_00b630c0_class::FUN_00b630c0()
{
    unsigned int i;
    for (i = 0; i < m_uiBatchRendererCount; i++)
    {
        ::ClearAllGroups((::BSBatchRenderer_View_00b99bc0 *)(((BSBatchRenderer*)m_apkBatchRenderer[i])), 0, {});
    }
}

namespace fnv_00b63b90 {
struct BSBatchRenderer
{
    struct PassTextureSlots
    {
    };
};

struct FUN_00b63b90_class
{
    struct BatchRenderer
    {
        char pad_3c[0x3c];
        BSBatchRenderer::PassTextureSlots* pGeometryGroups[6];
    };

    char pad_174[0x174];
    BatchRenderer* m_pkBatchRenderer[6];
    unsigned int m_uiBatchRendererCount;

    void FUN_00b63b90(unsigned int uiRenderPassIndex);
};

// @fnv 0x00b63b90
void FUN_00b63b90_class::FUN_00b63b90(unsigned int uiGeometryGroupIndex)
{
    for (unsigned int i = 0; i < m_uiBatchRendererCount; ++i)
        reinterpret_cast<::BSBatchRenderer__GeometryGroup *>((m_pkBatchRenderer[i]->pGeometryGroups[uiGeometryGroupIndex]))->ClearPassTextureSlots();
}
}  // namespace fnv_00b63b90

struct FUN_00b63d80_base
{
    ~FUN_00b63d80_base();
};
struct FUN_00b63e70_class : FUN_00b63d80_base
{
    FUN_00b63e70_class* FUN_00b63e70(bool bDelete);
};

struct FUN_00b64490_Response
{
    char pad00[0x68];
    int unk68;
};

// @fnv 0x00b64490
bool __cdecl FUN_00b64490(void* a, void* b, void* c, void* d, void* e)
{
    if (((FUN_00b64490_Response*)e)->unk68 == 0x16)
        return true;
    ::ProcessCommands((::RSSettings *)(a), b, c, (::RSPacket *)(d), (::RSResponse *)(e));
}

extern int DAT_010ae0c0;
extern long volatile DAT_011f4400;
extern void(* DAT_00fdf1c4)(void*);

struct FUN_00b66850_class
{
    void FUN_00b66850();
};

struct StrArr : ::NiTArray<char*, ::NiTMallocInterface<char*>>
{
};




// Appends the string returned by _FUN_00a7d330(g_011fa018) to arr, growing arr to idx plus the growth value when idx reaches capacity.
// @fnv 0x00b6a670
void FUN_00b6a670(StrArr* pStrArr)
{
    reinterpret_cast<::ShaderPropertyRecord *>((pStrArr))->WriteToSettingArray({});
    char* p = ::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_011fa018))));
    unsigned int idx = pStrArr->m_usSize;
    unsigned int uiCapacity = pStrArr->m_usMaxSize;
    if (idx >= uiCapacity)
    {
        unsigned int grow = pStrArr->m_usGrowBy;
        reinterpret_cast<::ViewerStrings *>((pStrArr))->SetSize(grow + idx);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pStrArr))->SetAt(idx, p);
}


struct PushRefCountedSlot_Ref
{
    void** vtbl;
    long m_lRefCount;
};

// @fnv 0x00b6b050
void PushRefCountedSlot(int* pObject)
{
    if ((unsigned int)DAT_011fa020 < 10)
    {
        int** slot = &(*reinterpret_cast<int * (*)[10]>(&::fnv_00b6b6c0::DAT_011fa024))[DAT_011fa020];
        int* old = *slot;
        if (old != pObject)
        {
            if (old != 0)
            {
                if (InterlockedDecrement(&((PushRefCountedSlot_Ref*)old)->m_lRefCount) == 0)
                {
                    ((void(*)(int*))((PushRefCountedSlot_Ref*)old)->vtbl[1])(old);
                }
            }
            *slot = pObject;
            if (pObject != 0)
            {
                InterlockedIncrement(&((PushRefCountedSlot_Ref*)pObject)->m_lRefCount);
            }
        }
        DAT_011fa020++;
    }
}

struct NiRendererVirtualStub
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f0a()
    {}
    virtual void f0b()
    {}
    virtual void f0c()
    {}
    virtual void f0d()
    {}
    virtual void f0e()
    {}
    virtual void f0f()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f1a()
    {}
    virtual void f1b()
    {}
    virtual void f1c()
    {}
    virtual void f1d()
    {}
    virtual void f1e()
    {}
    virtual void f1f()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
    virtual void f23()
    {}
    virtual void f24()
    {}
    virtual void f25()
    {}
    virtual void f26()
    {}
    virtual void f27()
    {}
    virtual void f28()
    {}
    virtual void f29()
    {}
    virtual void f2a()
    {}
    virtual void f2b()
    {}
    virtual void f2c()
    {}
    virtual void f2d()
    {}
    virtual void f2e()
    {}
    virtual void f2f()
    {}
    virtual void f30()
    {}
    virtual void f31()
    {}
    virtual void f32()
    {}
    virtual void f33()
    {}
    virtual void f34()
    {}
    virtual void f35()
    {}
    virtual void f36()
    {}
    virtual void f37()
    {}
    virtual void f38(int, int, int)
    {}
};

struct FUN_00b6f520_class
{
    char pad_00[0x60];
    int m_0x60;

    void FUN_00b6f520();
};

// @fnv 0x00b6f520
void FUN_00b6f520_class::FUN_00b6f520()
{
    int value = m_0x60;
    if (value != 0)
    {
        reinterpret_cast<NiRendererVirtualStub*>(NiRenderer::ms_pRenderer)->f38(value, 0, 0);
    }
}

// @fnv 0x00b6fd00
void* __cdecl FUN_00b6fd00()
{
    return &(*reinterpret_cast<void * *>(&::g_011fa05c));
}

struct BeamStage
{
};

struct NiD3DShader
{
    virtual unsigned int V0();
    virtual unsigned int V1();
    virtual unsigned int V2();
    virtual unsigned int V3();
    virtual unsigned int V4();
    virtual unsigned int V5();
    virtual unsigned int V6();
    virtual unsigned int V7();
    virtual unsigned int V8();
    virtual unsigned int V9();
    virtual unsigned int V10();
    virtual unsigned int V11();
    virtual unsigned int V12();
    virtual unsigned int V13();
    virtual unsigned int V14();
    virtual unsigned int V15();
    virtual unsigned int V16();
    virtual unsigned int V17();
    virtual unsigned int V18();
    virtual unsigned int V19();
    virtual unsigned int V20();
    virtual unsigned int V21();
    virtual unsigned int V22();
    virtual unsigned int V23();
    virtual unsigned int V24();
    virtual unsigned int V25();
    virtual unsigned int V26();
    virtual unsigned int V27();
    virtual unsigned int V28();
    virtual unsigned int V29();
    virtual unsigned int V30();
    virtual unsigned int V31();
    virtual unsigned int V32();
    virtual unsigned int V33();
    virtual unsigned int V34();
    virtual unsigned int V35();
    virtual unsigned int V36();
    virtual unsigned int V37();
    virtual unsigned int V38();
    virtual unsigned int V39();
    virtual unsigned int V40();
    virtual unsigned int V41();
    virtual unsigned int V42();
    virtual unsigned int V43();
    virtual unsigned int V44();
    virtual unsigned int V45();
    virtual unsigned int V46();
    virtual unsigned int V47();
    virtual unsigned int V48();
    virtual unsigned int V49();
    virtual unsigned int V50();
    virtual unsigned int V51();
    virtual unsigned int V52();
    virtual unsigned int V53();
    virtual unsigned int V54();
    virtual unsigned int V55();
    virtual unsigned int V56();
};

// If both textureStage and shader are non-null, passes the shader's V56() result to textureStage->ApplyPairToState.
// @fnv 0x00b71b10
void FUN_00b71b10(BeamStage* textureStage, NiD3DShader* shader)
{
    if (textureStage != 0 && shader != 0)
    {
        reinterpret_cast<::E7DE90Owner *>((textureStage))->ApplyPairToState(shader->V56());
    }
}

struct FUN_00b7ce60_class
{
    FUN_00b7ce60_class* FUN_00b7ce60(int a);
};
// Calls FUN_00b79de0, frees this with operator delete when bit 0 of a is set, and returns this.
// @fnv 0x00b7ce60
FUN_00b7ce60_class* FUN_00b7ce60_class::FUN_00b7ce60(int aiFlags)
{
    reinterpret_cast<::fnv_00b79de0::FUN_00b79de0 *>(this)->fnv_00b79de0::FUN_00b79de0::~FUN_00b79de0();
    if (aiFlags & 1)
        operator delete(this, 0x8c);
    return this;
}

// variant G: real constructor
struct FUN_00b600e0_cls
{
    int m_i0;
    int m_i4;
    float m_f8;
    float m_fC;
    float m_f10;
    float m_f14;
    float m_f18;
    FUN_00b600e0_cls();
};

// @fnv 0x00b600e0
FUN_00b600e0_cls::FUN_00b600e0_cls()
{
    m_f8 = 0.0f;
    m_i0 = 0;
    m_fC = 0.0f;
    m_f10 = 0.0f;
    m_f14 = 0.0f;
    m_f18 = 1.0f;
}

struct FUN_00b60100_cls
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
    int m_90;
    void FUN_00b60100(int value);
};

// @fnv 0x00b60100
void FUN_00b60100_cls::FUN_00b60100(int value)
{
    m_90 = (value != 3) ? 3 : 0;
}


// Returns the float value stored at DAT_011fd890 converted to an unsigned int.
// @fnv 0x00b60170
unsigned int __cdecl GetGlobalFloatAsUInt()
{
    return (unsigned int)DAT_011fd890;
}

// Reconstruction of FUN_00b60280.
//
// `this` owns a single pointer at offset 0.  Replacing it releases the old
// object first: the reference counter that lives at +8 of the old object is
// decremented and, when it drops to zero, the old object is destroyed - the
// deleting destructor is reached through vtable slot 0 with the deleting flag
// 1 pushed.  Afterwards the new pointer is stored at +0 and, when it is not
// null, its own counter at +8 is incremented.
//
// The two null tests on the old pointer are not redundant in the source: the
// outer one tests the member, the inner one is the null check that the delete
// operator performs on the pointer it is given.  The inner check survives
// because the pointer handed to `delete` is a second, independent copy of the
// member taken inside the guarded block, so the compiler does not carry the
// "known non-null" fact of the member test over to it.

struct FnvB60280Ref
{
    virtual ~FnvB60280Ref();
    int m_iWordAt04;
    long m_ref;
};

struct FnvB60280Owner
{
    FnvB60280Ref* m_pCur;
    FnvB60280Owner* FUN_00b60280(FnvB60280Ref* pNew);
};

// Releases the current reference if different, then stores pNew and increments its ref count.
// @fnv 0x00b60280
FnvB60280Owner* FnvB60280Owner::FUN_00b60280(FnvB60280Ref* pNew)
{
    if (m_pCur == pNew)
        return this;
    if (m_pCur)
    {
        FnvB60280Ref* q = m_pCur;
        if (InterlockedDecrement(&q->m_ref) == 0)
            delete q;
    }
    m_pCur = pNew;
    if (pNew)
        InterlockedIncrement(&pNew->m_ref);
    return this;
}

void* __cdecl FUN_00aa1070(unsigned int);

struct ManagedRef
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long refCount;
    void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
};

template <class T> struct RefPtr
{
    T* value;
    RefPtr(const RefPtr& other) : value(other.value)
    {
        if (value)
            value->IncRefCount();
    }
    ~RefPtr()
    {
        if (value)
            value->DecRefCount();
    }
    RefPtr& operator=(const RefPtr& other)
    {
        if (value != other.value)
        {
            if (value)
                value->DecRefCount();
            value = other.value;
            if (value)
                value->IncRefCount();
        }
        return *this;
    }
};

struct AssignedString
{
    int unk00;
    char* text;
    RefPtr<ManagedRef> object;
};

struct FUN_00b604b0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    bool copyText;
    void AssignString(AssignedString* out, const char* input, RefPtr<ManagedRef> ref);
};

// Copies or aliases input into out->text depending on copyText, then assigns ref to out->object.
// @fnv 0x00b604b0
void FUN_00b604b0_class::AssignString(AssignedString* out, const char* input, RefPtr<ManagedRef> ref)
{
    if (copyText)
    {
        unsigned int length = strlen(input) + 1;
        char* buffer = static_cast<char*>(FUN_00aa1070(length));
        out->text = buffer;
        fnv::crt::strcpy_s(buffer, length, input);
    }
    else
    {
        out->text = const_cast<char*>(input);
    }
    out->object = ref;
}

// FUN_00b60750 - a member that hands a block over to its caller
// and releases it again.
//
// The original reads two members of the object:
//   this+0x250 : a pointer to a pointer - the block that is handed out
//   this+0x258 : a flag - when it is clear, nothing is handed out
//
// and then does, in this exact order:
//   push ecx                                   ; frame slot for the scratch flag
//   cmp dword ptr [ecx+0x258], 0
//   mov dword ptr [esp], 0                     ; scratch flag = 0
//   je  <null>
//   mov eax, dword ptr [ecx+0x250]
//   mov eax, dword ptr [eax]
//   jmp <join>
// <null>: xor eax, eax
// <join>: push esi / mov esi,[esp+0xc]         ; the out parameter
//   mov dword ptr [esi], eax                   ; publish the block
//   test eax, eax / je <done>
//   add eax, 4 / push eax
//   call dword ptr [0x00fdf1c0]                ; the engine's deallocator
// <done>: mov eax, esi / pop esi / pop ecx / ret 4
//
// The deallocator is the global function pointer DAT_00fdf1c0 - a
// pointer with one void* argument - so the block is released as (block + 4).
//
// The scratch flag is a volatile int that the original only ever reads in a
// branch that is never taken, so the store of its zero value survives while
// the read itself disappears.  Writing it as an unreachable use keeps that
// shape: the local is referenced (so the compiler keeps the frame slot) but
// the reference is in code the optimiser deletes (so no load is emitted).

struct FUN_00b60750_owner
{
    char padding[0x250];
    void* unk250;  // +0x250
    char pad254[4];
    int unk258;  // +0x258
    void* FUN_00b60750(void* pOut);
};

extern void(* DAT_00fdf1c0)(void*);

struct FUN_00b60750_Block
{
    void* vtbl;
    long m_lRefCount;
};

// Stores the block pointer from unk250 (or null if unk258 is zero) into pOut and calls DAT_00fdf1c0 on the block's reference count when non-null.
// @fnv 0x00b60750
void* FUN_00b60750_owner::FUN_00b60750(void* pOut)
{
    volatile int unused = 0;
    if (0)
    {
        if (unused)
        {
        }
    }

    void* block;
    if (unk258)
    {
        block = *(void**)unk250;
    }
    else
    {
        block = 0;
    }

    *(void**)pOut = block;
    if (block)
    {
        DAT_00fdf1c0(&((FUN_00b60750_Block*)block)->m_lRefCount);
    }
    return pOut;
}

class B60A50RefObject
{
  public:
    virtual ~B60A50RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};

struct B60A50CloningProcess;

class B60A50Base
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
    int m_iFlags;

};

class B60A50Effect : public B60A50Base
{
  public:
    NiPointer<B60A50RefObject> m_spTexture;
    NiPointer<B60A50RefObject> m_spPalette;
    int unk88;
    int unk8C;
    int m_iTextureClamp;
    int m_iTextureFilter;

    void CloneTo(B60A50Effect* pkDest, B60A50CloningProcess& kCloning);
};

// @fnv 0x00b60a50
void B60A50Effect::CloneTo(B60A50Effect* pkDest, B60A50CloningProcess& kCloning)
{
    reinterpret_cast<::FUN_00b702b0_shell *>(this)->FUN_00b702b0((char *)(pkDest), (void *)&(kCloning));
    pkDest->m_spTexture = m_spTexture;
    pkDest->m_spPalette = m_spPalette;
    pkDest->m_iTextureClamp = m_iTextureClamp;
    pkDest->m_iTextureFilter = m_iTextureFilter;
    pkDest->m_iFlags = m_iFlags;
}


// @fnv 0x00b60d60
int* __cdecl FUN_00b60d60()
{
    return &(*reinterpret_cast<int *>(&::g_011f9f00));
}

struct S_00b63070_class
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

    void FUN_00b63070();
};

inline void S_00b63070_class::v00()
{}
inline void S_00b63070_class::v01()
{}
inline void S_00b63070_class::v02()
{}
inline void S_00b63070_class::v03()
{}
inline void S_00b63070_class::v04()
{}
inline void S_00b63070_class::v05()
{}
inline void S_00b63070_class::v06()
{}
inline void S_00b63070_class::v07()
{}
inline void S_00b63070_class::v08()
{}
inline void S_00b63070_class::v09()
{}
inline void S_00b63070_class::v10()
{}
inline void S_00b63070_class::v11()
{}
inline void S_00b63070_class::v12()
{}
inline void S_00b63070_class::v13()
{}
inline void S_00b63070_class::v14()
{}
inline void S_00b63070_class::v15()
{}
inline void S_00b63070_class::v16()
{}
inline void S_00b63070_class::v17()
{}
inline void S_00b63070_class::v18()
{}
inline void S_00b63070_class::v19()
{}
inline void S_00b63070_class::v20()
{}
inline void S_00b63070_class::v21()
{}
inline void S_00b63070_class::v22()
{}
inline void S_00b63070_class::v23()
{}
inline void S_00b63070_class::v24()
{}
inline void S_00b63070_class::v25()
{}
inline void S_00b63070_class::v26()
{}
inline void S_00b63070_class::v27()
{}
inline void S_00b63070_class::v28()
{}
inline void S_00b63070_class::v29()
{}
inline void S_00b63070_class::v30()
{}
inline void S_00b63070_class::v31()
{}
inline void S_00b63070_class::v32()
{}
inline void S_00b63070_class::v33()
{}
inline void S_00b63070_class::v34()
{}
inline void S_00b63070_class::v35()
{}
inline void S_00b63070_class::v36()
{}
inline void S_00b63070_class::v37()
{}
inline void S_00b63070_class::v38()
{}
inline void S_00b63070_class::v39()
{}
inline void S_00b63070_class::v40()
{}
inline void S_00b63070_class::v41()
{}
inline void S_00b63070_class::v42()
{}
inline void S_00b63070_class::v43()
{}

// @fnv 0x00b63070
void S_00b63070_class::FUN_00b63070()
{
    this->v42();
    this->v43();
}

// SumItemSubValues: sums a 16-bit value over the array elements at this+0x174.
// Count at +0x18c. Pairs (even, odd) are summed separately; an odd tail element
// is added last.

class FUN_00b63a90_cls;

class FUN_00b63a90_Sub
{
  public:
    unsigned short unk00;
    unsigned short m_usValue;
};

class FUN_00b63a90_Item
{
  public:
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
    FUN_00b63a90_Sub* m_pSub;
};

class FUN_00b63a90_cls
{
  public:
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
    FUN_00b63a90_Item* m_items[6];
    unsigned int m_uiCount;
    int SumItemSubValues();
};

// Sums m_usValue of each item's m_pSub over m_items[0..m_uiCount-1] and returns the total.
// @fnv 0x00b63a90
int FUN_00b63a90_cls::SumItemSubValues()
{
    int count = (int)m_uiCount;
    unsigned int tail = 0;
    unsigned int sumA = 0;
    unsigned int sumB = 0;
    unsigned int idx = 0;
    if (count >= 2)
    {
        unsigned int n = ((unsigned int)count - 2) / 2 + 1;
        FUN_00b63a90_Item** p = &m_items[1];
        idx = n * 2;
        do
        {
            sumA += (*(p - 1))->m_pSub->m_usValue;
            sumB += (*p)->m_pSub->m_usValue;
            p += 2;
        } while (--n != 0);
    }
    if (idx < (unsigned int)count)
    {
        tail = m_items[idx]->m_pSub->m_usValue;
    }
    return (int)(sumB + sumA + tail);
}

struct PoolAllocator_b8522
{
};

struct FUN_00b63bf0_cls
{
    unsigned short item;
    FUN_00b63bf0_cls* next;
    void AppendItem(const unsigned short* src);
};

// Walks to the last node of the list and appends a new node holding *src, or sets the last node's item if it is empty; returns early when *src is 0.
// @fnv 0x00b63bf0
void FUN_00b63bf0_cls::AppendItem(const unsigned short* src)
{
    unsigned short value = *src;
    if (value == 0)
        return;

    FUN_00b63bf0_cls* cur = this;
    if (this->next != 0)
    {
        FUN_00b63bf0_cls** ppLink = &this->next;
        do
        {
            cur = *ppLink;
            ppLink = &cur->next;
        } while (cur->next != 0);
    }

    if (cur->item != 0)
    {
        FUN_00b63bf0_cls* n = (FUN_00b63bf0_cls*)reinterpret_cast<::MemoryManagerStandIn *>((reinterpret_cast<PoolAllocator_b8522*>(&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa3e40(8);
        if (n != 0)
        {
            n->item = *src;
            n->next = 0;
        }
        else
        {
            n = 0;
        }
        cur->next = n;
        return;
    }
    cur->item = value;
}

void __cdecl FUN_00aa10f0(void* value);
struct Resource
{
    void* vtable;
    int unk04;
    void* unk08;
    Resource* DestroyResource(unsigned int flags);
};
// @fnv 0x00b63e30
Resource* Resource::DestroyResource(unsigned int flags)
{
    vtable = &DAT_010adfbc;
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
    FUN_00aa10f0(unk08);
    if (flags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    }
    return this;
}

struct B666D0Target
{
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
    virtual void SetEntry(unsigned int uiIndex, void* pvEntry);
};

class B666D0Source
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
    void* m_apvEntries[6];

    void CopyEntriesToTarget(B666D0Target* pkTarget);
};

// Copies the six entries of m_apvEntries into the target via SetEntry.
// @fnv 0x00b666d0
void B666D0Source::CopyEntriesToTarget(B666D0Target* pkTarget)
{
    for (unsigned int i = 0; i < 6; i++)
        pkTarget->SetEntry(i, m_apvEntries[i]);
}

// Decompilation of CheckAndNotify (0x00b667e0, 48 bytes)
//
// bool CheckAndNotify(int a)
//   if (!FUN_00bc3770(a)) return false;
//   if (this->m_pFlagTarget) this->m_pFlagTarget->v21(a);
//   return true;

struct DecompTarget
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
    virtual void v21(::NiStream& kStream);
};

struct DecompOwner
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
    DecompTarget* m_pFlagTarget;
    bool CheckAndNotify(::NiStream& kStream);
};

// Calls FUN_00bc3770(a); if it succeeds, invokes v21(a) on the stored target pointer when non-null and returns true, otherwise false.
// @fnv 0x00b667e0
bool DecompOwner::CheckAndNotify(::NiStream& kStream)
{
    if (!reinterpret_cast<::FUN_00bc3770_shell *>(this)->FUN_00bc3770(kStream))
        return false;
    DecompTarget* pTarget = this->m_pFlagTarget;
    if (pTarget != 0)
        pTarget->v21(kStream);
    return true;
}

extern volatile long DAT_011f4400;

struct S_00b669f0_Ref
{
    virtual void v0();
    virtual void v1();
    volatile long m_rc;
    void IncRefCount()
    {
        InterlockedIncrement(&m_rc);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_rc) == 0)
            v1();
    }
};

struct S_00b669f0_Base
{
    virtual void v0();
    int unk04;
    ~S_00b669f0_Base()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
};

struct FUN_00b669f0 : S_00b669f0_Base
{
    NiPointer<S_00b669f0_Ref> m_08;
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
    NiPointer<S_00b669f0_Ref> m_6c;
    ~FUN_00b669f0();
};

// Destructor that clears the two NiPointer reference holders m_08 and m_6c, releasing their references.
// @fnv 0x00b669f0
FUN_00b669f0::~FUN_00b669f0()
{
    m_08 = 0;
    m_6c = 0;
}

class MemoryManagerB66
{
  public:
    void Deallocate(void* pvMem);
};

class RenderPassB66
{
  public:
    RenderPassB66(void* pvOwner, int iType, ...);


    int unk00, unk04, unk08, unk0C;
};

class ShaderPropertyB66
{
  public:
    RenderPassB66* GetOrCreateRenderPass(void* pvOwner);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int m_uiValue1;
    int unk024, unk028, unk02C, unk030, unk034, unk038, unk03C, unk040;
    int unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060;
    int unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080;
    int unk084, unk088, unk08C, unk090, unk094, unk098, unk09C, unk0A0;
    int unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0;
    int unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0;
    int unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    RenderPassB66* m_pRenderPass;
};

// @fnv 0x00b66e20
RenderPassB66* ShaderPropertyB66::GetOrCreateRenderPass(void* pvOwner)
{
    if (!m_pRenderPass)
    {
        if ((m_uiValue1 & 2) > 0)
            m_pRenderPass = new RenderPassB66(pvOwner, 0x1e8, 1, 0, 0);
        else if ((m_uiValue1 & 0x1000) > 0)
            m_pRenderPass = new RenderPassB66(pvOwner, 0x1e9, 1, 0, 0);
        else
            m_pRenderPass = new RenderPassB66(pvOwner, 0x1e7, 1, 0, 0);
    }
    return m_pRenderPass;
}

class NiRTTI
{
  public:
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};


class NiObjectStub
{
  public:
    virtual ~NiObjectStub();
    virtual void v1();
    virtual const NiRTTI* GetRTTI() const;
};

inline bool StubIsKindOf(const NiRTTI* pkRTTI, NiObjectStub* pkObj)
{
    if (!pkObj)
        return false;
    for (const NiRTTI* p = pkObj->GetRTTI(); p; p = p->m_pBaseRTTI)
    {
        if (p == pkRTTI)
            return true;
    }
    return false;
}

struct TextureReceiver
{
};

typedef void(__cdecl* StubVisitFn)(NiObjectStub* pkObj, int iUnk, void* pvData);

struct VisitOwner
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
    NiObjectStub* m_pkObj;
    TextureReceiver* m_pkRecv0;
    TextureReceiver* m_pkRecv1;
    TextureReceiver* m_pkRecv2;
    TextureReceiver* m_pkRecv3;
    void VisitObjects(StubVisitFn pfnVisit, void* pvData);
};

// Calls pfnVisit on m_pkObj and on the object returned by FUN_004bc320(0) for each of m_pkRecv0..m_pkRecv3 when present.
// @fnv 0x00b69e10
void VisitOwner::VisitObjects(StubVisitFn pfnVisit, void* pvData)
{
    if (m_pkObj)
    {
        if (!StubIsKindOf(&(*reinterpret_cast<::NiRTTI *>(&::g_011f444c)), m_pkObj))
            StubIsKindOf(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4ac4)), m_pkObj);
        pfnVisit(m_pkObj, 0, pvData);
    }
    if (m_pkRecv0 && ((::NiObjectStub *)(uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((m_pkRecv0))->FUN_004bc320(0))))
    {
        NiObjectStub* p = ((::NiObjectStub *)(uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((m_pkRecv0))->FUN_004bc320(0)));
        pfnVisit(p, 0, pvData);
    }
    if (m_pkRecv1 && ((::NiObjectStub *)(uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((m_pkRecv1))->FUN_004bc320(0))))
    {
        NiObjectStub* p = ((::NiObjectStub *)(uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((m_pkRecv1))->FUN_004bc320(0)));
        pfnVisit(p, 0, pvData);
    }
    if (m_pkRecv2 && ((::NiObjectStub *)(uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((m_pkRecv2))->FUN_004bc320(0))))
    {
        NiObjectStub* p = ((::NiObjectStub *)(uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((m_pkRecv2))->FUN_004bc320(0)));
        pfnVisit(p, 0, pvData);
    }
    if (m_pkRecv3 && ((::NiObjectStub *)(uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((m_pkRecv3))->FUN_004bc320(0))))
    {
        NiObjectStub* p = ((::NiObjectStub *)(uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((m_pkRecv3))->FUN_004bc320(0)));
        pfnVisit(p, 0, pvData);
    }
}



struct TlsGuard
{
    int saved;
    TlsGuard()
    {
        saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x1d;
    }
    ~TlsGuard()
    {
        ::g_tlsBlock.memoryContext = saved;
    }
};

struct FlagSlot
{
    char unk00[3];
    unsigned char flag;
};

struct Obj3c
{
    char unk00[0x10];
    int m_10;
    void FUN_00ba9ee0(intptr_t a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

struct ArgQ
{
    char unk00[0x28];
    int m_28;
};
struct ArgP
{
    char unk00[0xb8];
    ArgQ* m_b8;
};

struct Ret30
{
    int m_iWordAt00;
    unsigned short m_iWordAt04;
};

struct ThisCls
{
    char unk00[0x3c];
    Obj3c* m_3c;
    char unk40[0x60 - 0x40];
    unsigned char m_60;
    unsigned char m_61;
    char unk62;
    unsigned char m_63;
    char unk64[0x7e - 0x64];
    unsigned char m_7e;
    char unk7f;
    unsigned char m_80;
    unsigned char m_81;
    char unk82;
    unsigned char m_83;
    char unk84[0x130 - 0x84];
    int m_130;
    Obj3c* FUN_00b69ff0(ArgP* p, int a2, int a3, int a4, int a5, int a6);
};

// @fnv 0x00b69ff0
Obj3c* ThisCls::FUN_00b69ff0(ArgP* p, int a2, int a3, int a4, int a5, int a6)
{
    TlsGuard guard;
    FlagSlot flagSlot;
    if ((*reinterpret_cast<unsigned char *>(&::DAT_011ad86e)) == 0)
    {
        return 0;
    }
    flagSlot.flag = 0;
    if (p->m_b8->m_28 != 0)
        flagSlot.flag = 1;
    if (DAT_011ff104 != m_7e)
    {
        if (m_3c)
        {
            m_3c->m_10 = 0;
        }
        m_7e = DAT_011ff104;
    }
    reinterpret_cast<::TallGrassShader *>(this)->InitializeConstants(-1);
    if (m_3c->m_10 == 0)
    {
        int code;
        if (m_7e != 0)
        {
            code = 0x2bd;
        }
        else if (flagSlot.flag)
        {
            if (m_60 != 0)
            {
                if ((*reinterpret_cast<unsigned char *>(&::waterHasWorld)) != 0)
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2a6 : 0x2aa;
                        else
                            code = m_63 ? 0x2a4 : 0x2a8;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2a5 : 0x2a9;
                        else
                            code = m_63 ? 0x2a3 : 0x2a7;
                    }
                }
                else
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x29e : 0x2a2;
                        else
                            code = m_63 ? 0x29c : 0x2a0;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x29d : 0x2a1;
                        else
                            code = m_63 ? 0x29b : 0x29f;
                    }
                }
            }
            else if (m_61 != 0)
            {
                code = m_80 ? 0x23f : 0x240;
            }
            else
            {
                if ((*reinterpret_cast<unsigned char *>(&::waterHasWorld)) != 0)
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2c3 : 0x2cb;
                        else
                            code = m_63 ? 0x2c5 : 0x2cd;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2c4 : 0x2cc;
                        else
                            code = m_63 ? 0x2c2 : 0x2ca;
                    }
                }
                else
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2bf : 0x2c9;
                        else
                            code = m_63 ? 0x2c1 : 0x2c7;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2c0 : 0x2c8;
                        else
                            code = m_63 ? 0x2be : 0x2c6;
                    }
                }
            }
        }
        else
        {
            if (m_60 != 0)
            {
                if ((*reinterpret_cast<unsigned char *>(&::waterHasWorld)) != 0)
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x293 : 0x297;
                        else
                            code = m_63 ? 0x295 : 0x299;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x294 : 0x298;
                        else
                            code = m_63 ? 0x292 : 0x296;
                    }
                }
                else
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x28b : 0x28f;
                        else
                            code = m_63 ? 0x28d : 0x291;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x28c : 0x290;
                        else
                            code = m_63 ? 0x28a : 0x28e;
                    }
                }
            }
            else if (m_61 != 0)
            {
                code = m_80 ? 0x23f : 0x240;
            }
            else
            {
                if ((*reinterpret_cast<unsigned char *>(&::waterHasWorld)) != 0)
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2b1 : 0x2b9;
                        else
                            code = m_63 ? 0x2b3 : 0x2bb;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2b2 : 0x2ba;
                        else
                            code = m_63 ? 0x2b0 : 0x2b8;
                    }
                }
                else
                {
                    if (m_80 == 0)
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2ad : 0x2b7;
                        else
                            code = m_63 ? 0x2af : 0x2b5;
                    }
                    else
                    {
                        if (m_81 == 0)
                            code = m_63 ? 0x2ae : 0x2b6;
                        else
                            code = m_63 ? 0x2ac : 0x2b4;
                    }
                }
            }
        }
        m_3c->FUN_00ba9ee0((intptr_t)p, code, 1, 0, 0, 0, 0, 0);
        if (m_60 == 0 && m_61 == 0)
        {
            Ret30* r = ((::Ret30 *)(reinterpret_cast<::B9F30Owner *>(this)->FUN_00b69f30((::B9F30Geometry *)(p))));
            m_3c->FUN_00ba9ee0(r->m_iWordAt00, r->m_iWordAt04, 1, 0, 0, 0, 0, 0);
        }
        if (m_83 != 0 && m_130 != 0)
        {
            if (m_60 != 0)
            {
                if (flagSlot.flag)
                {
                    m_3c->FUN_00ba9ee0((intptr_t)p, 0x2ab, 1, 0, 0, 0, 0, 0);
                }
                else
                {
                    m_3c->FUN_00ba9ee0((intptr_t)p, 0x29a, 1, 0, 0, 0, 0, 0);
                }
            }
            else
            {
                if (flagSlot.flag)
                {
                    m_3c->FUN_00ba9ee0((intptr_t)p, 0x2ce, 1, 0, 0, 0, 0, 0);
                }
                else
                {
                    m_3c->FUN_00ba9ee0((intptr_t)p, 0x2bc, 1, 0, 0, 0, 0, 0);
                }
            }
        }
    }
    return m_3c;
}

struct B6Base
{
    virtual ~B6Base();
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
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
};
struct B6Ref
{
    virtual void v0();
    virtual void DeleteThis();
    long refs;
};
struct B6Ptr
{
    B6Ref* ptr;
    ~B6Ptr()
    {
        B6Ref* p = ptr;
        if (p && !InterlockedDecrement(&p->refs))
            p->DeleteThis();
    }
};
struct B6List
{
    void* head;
    void* tail;
    unsigned count;
    ~B6List() throw()
    {
        reinterpret_cast<::NiTPointerListBaseRaw *>(this)->FUN_004ed900();
    }
};
struct FUN_00b6a520 : B6Base
{
    B6List list;
    B6Ptr p134, p138, p13c, p140, p144;
    B6Ref* p148;
    virtual ~FUN_00b6a520();
};
// @fnv 0x00b6a520
FUN_00b6a520::~FUN_00b6a520()
{
    reinterpret_cast<::NiTPointerListBaseRaw *>(&(list))->FUN_004ed900();
    B6Ref* p = p148;
    if (p && !InterlockedDecrement(&p->refs))
        p->DeleteThis();
}


// @fnv 0x00b6a660
int* __cdecl FUN_00b6a660()
{
    return &(*reinterpret_cast<int *>(&::g_011fa018));
}

class B6AED0RefObject
{
  public:
    virtual ~B6AED0RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
};

// NiPointer<T>::NiPointer(T*)
class FUN_00b6aed0
{
  public:
    B6AED0RefObject* m_pObject;

    FUN_00b6aed0(B6AED0RefObject* pObject);
};

// @fnv 0x00b6aed0
FUN_00b6aed0::FUN_00b6aed0(B6AED0RefObject* pObject)
{
    m_pObject = pObject;
    if (m_pObject)
        m_pObject->IncRefCount();
}


class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount();
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
public:
    static unsigned int ms_lObjectCount;
};
// @fnv 0x00b66850
void FUN_00b66850_class::FUN_00b66850()
{
    char* p = (char*)this;
    *(void**)p = (void*)&DAT_010ae0c0;
    if (p[8] && *(void**)(p + 0xc))
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(*(void**)(p + 0xc));
    *(void**)(p + 0xc) = 0;
    if (p[8] && *(void**)(p + 0x10))
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(*(void**)(p + 0x10));
    *(void**)(p + 0x10) = 0;
    *(void**)p = (void*)&::DAT_0101dce4;
    DAT_00fdf1c4((void*)&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
}

class NiD3DPixelShader : public NiRefObject
{
};
class NiNode : public NiRefObject
{
};
class NiSourceTexture_b6aef0 : public NiRefObject
{
};

class FUN_00b6aef0 : public NiRefObject
{
  public:
    NiPointer<NiD3DPixelShader> m_spPixelShaders[6];
    NiPointer<NiSourceTexture_b6aef0> m_spTex20;
    NiPointer<NiSourceTexture_b6aef0> m_spTex24;
    NiPointer<NiSourceTexture_b6aef0> m_spTex28;
    int unk2c;
    NiPointer<NiNode> m_vshaders[4];
    virtual ~FUN_00b6aef0();
};

// @fnv 0x00b6aef0
FUN_00b6aef0::~FUN_00b6aef0()
{
    unsigned int i;
    for (i = 0; i < 6; i++)
        m_spPixelShaders[i] = 0;
    for (i = 0; i < 4; i++)
        m_vshaders[i] = 0;
}

class B6B100RefObject
{
  public:
    virtual ~B6B100RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

struct B6B100Stack
{
    int m_iArrayLength;
    NiPointer<B6B100RefObject> m_aspItems[16];
};


class B6B100Manager
{
  public:
    static B6B100RefObject* GetCurrentItem();
};

// Returns the item at the top of g_kB6B100Stack, or null when the stack is empty.
// @fnv 0x00b6b100
B6B100RefObject* B6B100Manager::GetCurrentItem()
{
    return (*reinterpret_cast<::B6B100Stack *>(&::DAT_011fa020)).m_iArrayLength ? (*reinterpret_cast<::B6B100Stack *>(&::DAT_011fa020)).m_aspItems[(*reinterpret_cast<::B6B100Stack *>(&::DAT_011fa020)).m_iArrayLength - 1]
                                   : NiPointer<B6B100RefObject>(0);
}


struct B6B330CriticalSection : CRITICAL_SECTION
{
};

class B6B330Renderer
{
  public:
    virtual void vfunc000();
    virtual void vfunc001();
    virtual void vfunc002();
    virtual void vfunc003();
    virtual void vfunc004();
    virtual void vfunc005();
    virtual void vfunc006();
    virtual void vfunc007();
    virtual void vfunc008();
    virtual void vfunc009();
    virtual void vfunc00A();
    virtual void vfunc00B();
    virtual void vfunc00C();
    virtual void vfunc00D();
    virtual void vfunc00E();
    virtual void vfunc00F();
    virtual void vfunc010();
    virtual void vfunc011();
    virtual void vfunc012();
    virtual void vfunc013();
    virtual void vfunc014();
    virtual void vfunc015();
    virtual void vfunc016();
    virtual void vfunc017();
    virtual void vfunc018();
    virtual void vfunc019();
    virtual void vfunc01A();
    virtual void vfunc01B();
    virtual void vfunc01C();
    virtual void vfunc01D();
    virtual void vfunc01E();
    virtual void vfunc01F();
    virtual void vfunc020();
    virtual void vfunc021();
    virtual void vfunc022();
    virtual void vfunc023();
    virtual void vfunc024();
    virtual void vfunc025();
    virtual void vfunc026();
    virtual void vfunc027();
    virtual void vfunc028();
    virtual void vfunc029();
    virtual void vfunc02A();
    virtual void vfunc02B();
    virtual void vfunc02C();
    virtual void vfunc02D();
    virtual void vfunc02E();
    virtual void vfunc02F();
    virtual void vfunc030();
    virtual void vfunc031();
    virtual void vfunc032();
    virtual void vfunc033();
    virtual void vfunc034();
    virtual void vfunc035();
    virtual void vfunc036();
    virtual void vfunc037();
    virtual void vfunc038();
    virtual void vfunc039();
    virtual void vfunc03A();
    virtual void vfunc03B();
    virtual void vfunc03C();
    virtual void vfunc03D();
    virtual void vfunc03E();
    virtual void vfunc03F();
    virtual void vfunc040();
    virtual void vfunc041();
    virtual void vfunc042();
    virtual void vfunc043();
    virtual void vfunc044();
    virtual void vfunc045();
    virtual void vfunc046();
    virtual void vfunc047();
    virtual void vfunc048();
    virtual void vfunc049();
    virtual void vfunc04A();
    virtual void vfunc04B();
    virtual void vfunc04C();
    virtual void vfunc04D();
    virtual void vfunc04E();
    virtual void vfunc04F();
    virtual void vfunc050();
    virtual void vfunc051();
    virtual void vfunc052();
    virtual void vfunc053();
    virtual void vfunc054();
    virtual void vfunc055();
    virtual void vfunc056();
    virtual void vfunc057();
    virtual void vfunc058();
    virtual void vfunc059();
    virtual void vfunc05A();
    virtual void vfunc05B();
    virtual void vfunc05C();
    virtual void vfunc05D();
    virtual void vfunc05E();
    virtual void vfunc05F();
    virtual void vfunc060();
    virtual void vfunc061();
    virtual void vfunc062();
    virtual void vfunc063();
    virtual void vfunc064();
    virtual void vfunc065();
    virtual bool CanUnlock();

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
    B6B330CriticalSection m_kLock;
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
    int m_iMode;
    int unk204;
    unsigned char m_ucLocked;

    bool IsLocked() const
    {
        return (m_iMode == 1 || m_iMode == 2) && m_ucLocked == 1;
    }
    bool TryUnlock();
};

// Returns false if the object is not locked or cannot be unlocked; otherwise leaves m_kLock, clears m_ucLocked and returns true.
// @fnv 0x00b6b330
bool B6B330Renderer::TryUnlock()
{
    if (!IsLocked())
        return false;
    if (!CanUnlock())
        return false;
    LeaveCriticalSection(&m_kLock);
    m_ucLocked = 0;
    return true;
}

struct RendererSurface
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
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual bool CheckFeature();

    char pad004[0x200 - 0x4];
    int unk200;
    char pad204[0x288 - 0x204];
    void* m_pkD3DDevice;
};
extern "C" RendererSurface* DAT_011f4748;
// If DAT_011f4748's unk200 flag is unset, sets it when CheckFeature succeeds, then calls FUN_00b6b7d0 with b and a swapped.
// @fnv 0x00b6b890
void __cdecl FUN_00b6b890(int a, intptr_t b)
{
    int* initialized = &DAT_011f4748->unk200;
    if (*initialized == 0)
    {
        if (DAT_011f4748->CheckFeature())
        {
            *initialized = 1;
        }
    }
    ::FUN_00b6b7d0((::NiRenderTargetGroup *)(b), a);
}

struct FUN_00b6b930_Object
{
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
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
};

// @fnv 0x00b6b930
void __cdecl FUN_00b6b930(unsigned int unused, FUN_00b6b930_Object* obj)
{
    obj->vfAC();
}

class FUN_00b6c1a0_obj
{
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
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
    virtual FUN_00b6c1a0_obj* vf44(int a);
    unsigned int m_04;
    unsigned int m_08;
};
class FUN_00b6c1a0_cls
{
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
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
    virtual FUN_00b6c1a0_obj* vf50();
    unsigned int FUN_00b6c1a0();
};

// Calls vf50 to get the render target group, then vf44(0) for its first buffer, and returns that buffer's width (m_08), or 0 if either step fails.
// @fnv 0x00b6c1a0
unsigned int FUN_00b6c1a0_cls::FUN_00b6c1a0()
{
    FUN_00b6c1a0_obj* p = vf50();
    if (p == 0)
        return 0;
    FUN_00b6c1a0_obj* q = p->vf44(0);
    if (q == 0)
        return 0;
    return q->m_08;
}

struct FUN_00b6c1d0_Class
{
    virtual void VF00();
    virtual void VF04();
    virtual void VF08();
    virtual void VF0C();
    virtual void VF10();
    virtual void VF14();
    virtual void VF18();
    virtual void VF1C();
    virtual void VF20();
    virtual void VF24();
    virtual void VF28();
    virtual void VF2C();
    virtual void VF30();
    virtual void VF34();
    virtual void VF38();
    virtual void VF3C();
    virtual void VF40();
    virtual void VF44();
    virtual void VF48();
    virtual void VF4C();
    virtual void VF50();
    virtual void VF54();
    virtual void VF58();
    virtual void VF5C();
    virtual void VF60();
    virtual void VF64();
    virtual void VF68();
    virtual void VF6C();
    virtual void VF70();
    virtual void VF74();
    virtual void VF78();
    virtual void VF7C();
    virtual void VF80();
    virtual void VF84();
    virtual void VF88();
    virtual void VF8C();
    virtual void VF90();
    virtual void VF94();
    virtual void VF98();
    virtual void VF9C();
    virtual void VFA0();
    virtual void VFA4();
    virtual void VFA8();
    virtual void VFAC();
    virtual void VFB0();
    virtual void VFB4();
    virtual void VFB8();
    virtual void VFBC();
    virtual void VFC0();
    virtual void VFC4();
    virtual int* VF50_Call();
    int FUN_00b6c1d0();
};

struct FUN_00b6c1d0_SubClass
{
    virtual void VF00();
    virtual void VF04();
    virtual void VF08();
    virtual void VF0C();
    virtual void VF10();
    virtual void VF14();
    virtual void VF18();
    virtual void VF1C();
    virtual void VF20();
    virtual void VF24();
    virtual void VF28();
    virtual void VF2C();
    virtual void VF30();
    virtual void VF34();
    virtual void VF38();
    virtual void VF3C();
    virtual void VF40();
    virtual void VF44();
    virtual void VF48();
    virtual void VF4C();
    virtual void VF50();
    virtual void VF54();
    virtual void VF58();
    virtual void VF5C();
    virtual void VF60();
    virtual void VF64();
    virtual void VF68();
    virtual void VF6C();
    virtual void VF70();
    virtual void VF74();
    virtual void VF78();
    virtual void VF7C();
    virtual void VF80();
    virtual void VF84();
    virtual void VF88();
    virtual void VF8C();
    virtual void VF90();
    virtual void VF94();
    virtual void VF98();
    virtual void VF9C();
    virtual void VFA0();
    virtual void VFA4();
    virtual void VFA8();
    virtual void VFAC();
    virtual int* VF44_Call(int a);
};

// @fnv 0x00b6c1d0
int FUN_00b6c1d0_Class::FUN_00b6c1d0()
{
    int* piVar1 = this->VF50_Call();
    if (piVar1 == 0)
    {
        return 0;
    }

    int* iVar2 = reinterpret_cast<FUN_00b6c1d0_SubClass*>(piVar1)->VF44_Call(0);
    if (iVar2 == 0)
    {
        return 0;
    }

    return *(iVar2 + 3);
}

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
    void* value;
    void* FUN_00b6d120();
};
// @fnv 0x00b6d120
void* CpuObject::FUN_00b6d120()
{
    return value;
}

struct b6d130_Counted
{
    virtual void v00();
    virtual void Release();
    int m_iObjectReferenceCount;
};

struct FUN_00b6d130_cls
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
    b6d130_Counted* m_pCounted;

    void ReleaseCounted();
};

// Decrements the reference count of m_pCounted and calls Release when it reaches zero, then clears m_pCounted.
// @fnv 0x00b6d130
void FUN_00b6d130_cls::ReleaseCounted()
{
    b6d130_Counted* pCounted = m_pCounted;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->m_iObjectReferenceCount) == 0)
        {
            pCounted->Release();
        }
        m_pCounted = 0;
    }
}

struct NiGlobalStringTable
{
    static char* AddString(const char* s);
};

struct FixedStr_b6d170
{
    char* m_handle;
    FixedStr_b6d170(const char* s)
    {
        m_handle = NiGlobalStringTable::AddString(s);
    }
    ~FixedStr_b6d170()
    {
        if (m_handle != DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_handle - 8));
    }
};

struct TexPrefs_b6d170
{
    int m_pixelLayout;
    int m_alphaFmt;
    int m_mipMapped;
};

struct NiRenderer_b6d170;
extern int DAT_011bf400;


struct RenderTarget_b6d170
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
    RenderTarget_b6d170(void* tex, int a, void* depth);
};

struct RTManager_b6d170
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
    void* unkA8;
    RenderTarget_b6d170* CreateRenderTarget(std::intptr_t a1, unsigned int width, unsigned int height, int a4, int a5,
                                            unsigned int flags, int a7, int msaaType, intptr_t a9, intptr_t a10);
};

// @fnv 0x00b6d170
RenderTarget_b6d170* RTManager_b6d170::CreateRenderTarget(std::intptr_t aiUnused, unsigned int width, unsigned int height, int a4,
                                                          int aiUnused2, unsigned int flags, int aiUnused3,
                                                          int msaaType, intptr_t a9, intptr_t a10)
{
    void* depth = 0;
    intptr_t msaa = 0;
    RenderTarget_b6d170* result = 0;
    TexPrefs_b6d170 prefs;
    prefs.m_mipMapped = 2;
    uintptr_t w;
    uintptr_t h;
    if (DAT_011f9183)
    {
        w = width;
        h = height;
    }
    else
    {
        unsigned int m = width > height ? width : height;
        unsigned int p = 1;
        while (p < m)
            p += p;
        h = p;
        w = p;
    }
    prefs.m_pixelLayout = 2;
    prefs.m_alphaFmt = 2;

    if (a4)
    {
        DAT_011f4ac0 = true;
        DAT_011ab3c8 = a4;
    }
    unsigned int uiFlag8 = flags & 8;
    if (uiFlag8)
        DAT_011ab3c4 = false;
    unsigned int uiFlag80 = flags & 0x80;
    if (uiFlag80)
        DAT_011bf400 = 0;
    if (!(flags & 0x100))
        depth = unkA8;
    if (flags & 0x40)
    {
        switch (msaaType)
        {
        case 2:
            msaa = 1;
            break;
        case 4:
            msaa = 2;
            break;
        case 8:
            msaa = 3;
            break;
        default:
            msaa = 0;
            break;
        }
    }
    bool b = !((flags >> 2) & 1);
    if (flags & 0x10)
    {
        void* tex = ((void *)(::S_00ee8330_CubeMap::FUN_00ee8330(w, (::S_00ee8330_Renderer *)((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508))), (::S_00ee8330_FormatPrefs &)(prefs))));
        if (tex)
            result = new RenderTarget_b6d170(tex, 1, depth);
    }
    else
    {
        result =
            ((::RenderTarget_b6d170 *)(::CreateWrapperFromGeometry((void *)&(const ::FixedStr_b6d170 &)(FixedStr_b6d170("")), (void *)(w), (void *)(h), &prefs, (void *)(msaa), (void *)(b), depth, (void *)(a9), (void *)(a10))));
    }
    if (a4)
        DAT_011f4ac0 = false;
    if (uiFlag8)
        DAT_011ab3c4 = true;
    if (uiFlag80)
        DAT_011bf400 = 1;
    return result;
}

class FUN_00b6d370_cls
{
  public:
    void FUN_00b6d370(intptr_t iA, intptr_t iB, int iC, int iD);
};

// Computes six values from iA and iB via GetRenderTargetDesc, then passes them with iA, iB, iC and iD to CreateRenderTarget.
// @fnv 0x00b6d370
void FUN_00b6d370_cls::FUN_00b6d370(intptr_t iA, intptr_t iB, int iC, int iD)
{
    int i0, i1, i2, i3, i4, i5;
    ::GetRenderTargetDesc((::RenderConfigSurface *)(iA), iB, (unsigned int *)(&i0), (unsigned int *)(&i1), (unsigned int *)(&i2), (unsigned int *)(&i3), (unsigned int *)(&i4), (unsigned int *)(&i5));
    reinterpret_cast<::RTManager_b6d170 *>(this)->CreateRenderTarget(iA, i0, i1, i2, i3, i4, iB, i5, iC, iD);
}

struct FUN_00b6f480_cls
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
    int m_i6c;
    void FUN_00b6f480(int a);
};

// Stores 3 when the incoming value differs from 3, otherwise 0.
// @fnv 0x00b6f480
void FUN_00b6f480_cls::FUN_00b6f480(int a)
{
    m_i6c = (a != 3) ? 3 : 0;
}

namespace fnv_00b6f8d0 {
struct S_00b6f8d0_Node
{
    int unk00;
    S_00b6f8d0_Node* unk04;
};

struct S_00b6f8d0_Object
{
    void** vtable;
};

typedef S_00b6f8d0_Node*(* S_00b6f8d0_GetNext)(S_00b6f8d0_Object*);


struct FUN_00b6f8d0_class
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
    S_00b6f8d0_Object* unk60;

    void FUN_00b6f8d0(void(__cdecl* callback)(void*, int, int), int value);
};

// Walks the linked list returned by unk60's vtable[2] looking for DAT_011f444c or DAT_011f4ac4, then calls callback with unk60, 0 and value.
// @fnv 0x00b6f8d0
void FUN_00b6f8d0_class::FUN_00b6f8d0(void(__cdecl* callback)(void*, int, int), int value)
{
    S_00b6f8d0_Object* object = this->unk60;

    if (object)
    {
        S_00b6f8d0_Node* node = ((S_00b6f8d0_GetNext)object->vtable[2])(object);

        if (node)
        {
            while (node)
            {
                if (node == (S_00b6f8d0_Node*)&(*reinterpret_cast<int *>(&::g_011f444c)))
                    goto call_callback;

                node = node->unk04;
            }
        }

        object = this->unk60;

        if (object)
        {
            node = ((S_00b6f8d0_GetNext)object->vtable[2])(object);

            if (node)
            {
                while (node)
                {
                    if (node == (S_00b6f8d0_Node*)&(*reinterpret_cast<int *>(&::g_011f4ac4)))
                        goto call_callback;

                    node = node->unk04;
                }
            }
        }

    call_callback:
        callback(this->unk60, 0, value);
    }
}
}  // namespace fnv_00b6f8d0

class NiStream;

typedef unsigned int(__cdecl* StreamReadFn)(NiStream* stream, void* buf, unsigned int size, unsigned int* io,
                                            unsigned int count);

class Sub64
{
  public:
};

class ObjOwner
{
  public:

  public:
    unsigned int unk00;
    unsigned int m_04;
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
    NiStream* m_24c;
};

void __cdecl FUN_00aa10f0(void* apMemory);

struct NiBinaryStreamView
{
    void* vtbl;
    unsigned int m_uiAbsoluteCurrentPos;
    StreamReadFn m_pfnRead;
};

static unsigned int ReadRaw(NiStream* stream, void* buf, unsigned int size)
{
    NiBinaryStreamView* pBinary = (NiBinaryStreamView*)stream;
    unsigned int io = size;
    unsigned int r = pBinary->m_pfnRead(stream, buf, size, &io, 1);
    pBinary->m_uiAbsoluteCurrentPos += r;
    return r;
}

class FUN_00b6fb20_cls
{
  public:
    void LoadFromStream(ObjOwner* p);

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
    Sub64 m_64;
    unsigned int m_68;
    unsigned int m_6C;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7C;
};

// Calls FUN_00ba92c0, reads m_6C from the stream, stores a value from FUN_00a64ce0 into m_64, and reads m_70..m_7C when p->m_04 is at least 0x1f.
// @fnv 0x00b6fb20
void FUN_00b6fb20_cls::LoadFromStream(ObjOwner* p)
{
    reinterpret_cast<::S_00ba92c0_Prop *>(this)->FUN_00ba92c0((*(::S_00ba92c0_Stream *)(p)));
    ReadRaw(p->m_24c, &m_6C, 4);
    void* v = 0;
    reinterpret_cast<::FUN_00a64ce0_shell *>((p))->FUN_00a64ce0((char **)(void **)(&v));
    reinterpret_cast<::TextString *>(&(m_64))->FUN_004037f0((const char *)(v), 0);
    FUN_00aa10f0(v);
    if (p->m_04 >= 0x1f)
    {
        ReadRaw(p->m_24c, &m_70, 4);
        ReadRaw(p->m_24c, &m_74, 4);
        ReadRaw(p->m_24c, &m_78, 4);
        ReadRaw(p->m_24c, &m_7C, 4);
    }
}

// SetValue: thiscall setter, stores its single stack argument at this+0x6c.
struct FUN_00b6fd10_cls
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
    int m_6c;
    void SetValue(int value);
};

// @fnv 0x00b6fd10
void FUN_00b6fd10_cls::SetValue(int value)
{
    m_6c = value;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct Blob60_cls
{
    int m_00;
    int m_04;
    int m_08;
};

class BlobBase_cls
{
  public:
    BlobBase_cls();
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int m_1c;
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

};

class BlobObj_cls : public BlobBase_cls
{
  public:
    virtual void unk60();
    Blob60_cls m_60;
    float m_6c;
    int m_70;
    unsigned char m_74;
    int m_78;
    BlobObj_cls()
    {
        Blob60_cls* sub = &m_60;
        sub->m_08 = 0;
        sub->m_00 = 0;
        sub->m_04 = 0;
        reinterpret_cast<::BSShaderLightingProperty *>((sub))->ClearLights();
        m_6c = 1.0f;
        m_70 = 0;
        m_74 = 0;
        m_1c = 1;
        m_78 = 0;
    }
};

// Allocates and constructs a BlobObj_cls via its constructor, returning the new object.
// @fnv 0x00b71920
BlobObj_cls* CreateBlobObj()
{
    return new BlobObj_cls();
}

// @fnv 0x00b719c0
double FUN_00b719c0(double dA, double dB)
{
    return dA < dB ? dA : dB;
}

struct Vector3Words
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
struct FUN_00b71b40_shell
{
    char pad000[0x1e4];
    Vector3Words m_kPosition;
    Vector3Words FUN_00b71b40() const;
};
// Returns the Vector3Words stored in m_kPosition.
// @fnv 0x00b71b40
Vector3Words FUN_00b71b40_shell::FUN_00b71b40() const
{
    const Vector3Words& position = m_kPosition;
    return position;
}

struct FUN_00b71b90_VirtualObject
{
    void** vtable;
};

typedef void(* FUN_00b71b90_VirtualFunction)(FUN_00b71b90_VirtualObject*);


struct FUN_00b71b90_class
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

    void FUN_00b71b90();
};

// @fnv 0x00b71b90
void FUN_00b71b90_class::FUN_00b71b90()
{
    if (unk28 != 0)
    {
        unsigned int i;
        for (i = 0; i < 0x270 / sizeof(void*); ++i)
        {
            FUN_00b71b90_VirtualObject* object = (*reinterpret_cast<FUN_00b71b90_VirtualObject * (*)[156]>(&::fnv_00b79de0::DAT_011fdd88))[i];
            if (object != 0)
            {
                FUN_00b71b90_VirtualFunction function =
                    reinterpret_cast<FUN_00b71b90_VirtualFunction>(object->vtable[0xa0 / sizeof(void*)]);
                function(object);
            }
        }
    }

    unsigned int i;
    for (i = 0; i < 0x340 / sizeof(void*); ++i)
    {
        FUN_00b71b90_VirtualObject* object = (*reinterpret_cast<FUN_00b71b90_VirtualObject * (*)[208]>(&::DAT_011fda48))[i];
        if (object != 0)
        {
            FUN_00b71b90_VirtualFunction function =
                reinterpret_cast<FUN_00b71b90_VirtualFunction>(object->vtable[0x88 / sizeof(void*)]);
            function(object);
        }
    }

    reinterpret_cast<::fnv_00e814b0::UnkShader *>((this))->FUN_00e814b0();
}

struct S_00b7ac20_Node
{
    int unk00;
    int unk04;
    unsigned char unk08;
};



struct S_00b7ac20_Callable
{
    // Empty virtual no-op body; does nothing.
// @fnv 0x00b7ac20
    virtual void FUN_00b7ac20_v00()
    {}
    virtual void FUN_00b7ac20_v04()
    {}
    virtual void FUN_00b7ac20_v08()
    {}
    virtual void FUN_00b7ac20_v0c()
    {}
    virtual void FUN_00b7ac20_v10()
    {}
    virtual void FUN_00b7ac20_v14()
    {}
    virtual void FUN_00b7ac20_v18()
    {}
    virtual void FUN_00b7ac20_v1c()
    {}
    virtual void FUN_00b7ac20_v20()
    {}
    virtual void FUN_00b7ac20_v24()
    {}
};

struct S_00b7ac20_Class
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
    S_00b7ac20_Callable* unk30;
    S_00b7ac20_Callable* unk34;

    void FUN_00b7ac20(int index);
};

void S_00b7ac20_Class::FUN_00b7ac20(int index)
{
    if (DAT_011fb4c0[index] != 0)
    {
        unsigned int eax = 1;
        S_00b7ac20_Node** esi = (*reinterpret_cast<S_00b7ac20_Node * (*)[]>(&::DAT_011febdc));

        do
        {
            S_00b7ac20_Node* node = esi[-1];
            if (node != 0)
            {
                if (node->unk08 != 0)
                {
                    unsigned int mask = (eax << 1) | (eax >> 31);
                    node->unk08 = (DAT_011fb4c0[index] & mask) == 0;
                }
            }

            eax = (eax << 1) | (eax >> 31);

            node = esi[0];
            if (node != 0)
            {
                if (node->unk08 != 0)
                {
                    unsigned int mask = (eax << 1) | (eax >> 31);
                    node->unk08 = (DAT_011fb4c0[index] & mask) == 0;
                }
            }

            esi += 2;
            eax = (eax << 1) | (eax >> 31);
        } while ((intptr_t)esi < (intptr_t)(*reinterpret_cast<S_00b7ac20_Node * (*)[]>(&::DAT_011fec34)));

        unk34->FUN_00b7ac20_v24();
    }

    if (DAT_011fa8e0[index] != 0)
    {
        int* selected = &DAT_011fa8e0[index];
        unsigned int eax = 1;
        S_00b7ac20_Node** esi = (*reinterpret_cast<S_00b7ac20_Node * (*)[]>(&::DAT_011fec34));

        do
        {
            S_00b7ac20_Node* node = esi[-1];
            if (node != 0)
            {
                if (node->unk08 != 0)
                {
                    unsigned int mask = (eax << 1) | (eax >> 31);
                    node->unk08 = (*selected & mask) == 0;
                }
            }

            eax = (eax << 1) | (eax >> 31);

            node = esi[0];
            if (node != 0)
            {
                if (node->unk08 != 0)
                {
                    unsigned int mask = (eax << 1) | (eax >> 31);
                    node->unk08 = (*selected & mask) == 0;
                }
            }

            esi += 2;
            eax = (eax << 1) | (eax >> 31);
        } while ((intptr_t)esi < (intptr_t)(*reinterpret_cast<S_00b7ac20_Node * (*)[]>(&::DAT_011fec8c)));

        unk30->FUN_00b7ac20_v24();
    }
}

struct V4
{
    float x, y, z, w;
    V4()
    {}
    V4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct V3
{
    float x, y, z;
};
struct LightData
{
    int unk00, unk04, unk08;
    V4 first, second;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    float x, y, z;
};
struct Context
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
    LightData* light;
};
struct BSFogProperty
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    V3 color;
    float nearDepth, farDepth;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    float density;
};
extern float DAT_011fd918;
// Copies the context's light data into global light vectors and, when enabled, stores fog color and depth/density into global fog vectors.
// @fnv 0x00b7ad80
void UpdateLightAndFogGlobals(intptr_t enabled, Context* context)
{
    if (context)
    {
        LightData* data = context->light;
        if (data)
        {
            (*reinterpret_cast<::V4 *>((void *)&::DAT_011fd8f4)) = data->first;
            (*reinterpret_cast<::V4 *>((void *)&::DAT_011fd904)) = data->second;
            DAT_011fd85c = data->x;
            DAT_011fd860 = data->y;
            DAT_011fd914 = data->z;
            DAT_011fd918 = 1.0f;
        }
        (*reinterpret_cast<::V4 *>((void *)&::DAT_011fd924)) = V4(0, 0, 0, 0);
        (*reinterpret_cast<::V4 *>((void *)&::DAT_011fd934)) = V4(0, 0, 0, 0);
        if (enabled)
        {
            BSFogProperty* fog = ::FUN_00b55520(DAT_011f91c4);
            if (fog)
            {
                float nearDepth = fog->nearDepth;
                float farDepth = fog->farDepth;
                float density = fog->density;
                if (farDepth != 0 || nearDepth != 0)
                {
                    V3 color = fog->color;
                    (*reinterpret_cast<::V4 *>((void *)&::DAT_011fd934)) = V4(farDepth, farDepth - nearDepth, density, 0);
                    (*reinterpret_cast<::V4 *>((void *)&::DAT_011fd924)) = V4(color.x, color.y, color.z, 0);
                }
            }
        }
    }
}

struct TexStageStub
{
    int unk00;
    int unk04;
    uintptr_t m_08;
};
struct StageMgrStub
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
    TexStageStub** m_pElems;
};
struct ShaderFieldsStub
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
    unsigned int* m_pArr;
};

// Stores shader's m_pArr[j] into stage i's m_08 and calls the stage's ApplyPairToState with shader->V56().
// @fnv 0x00b7c0a0
void FUN_00b7c0a0(NiD3DShader* shader, unsigned int uiStageIndex, unsigned int j)
{
    StageMgrStub* pStageMgr = reinterpret_cast<StageMgrStub*>(DAT_0126f74c);
    TexStageStub* stage = pStageMgr->m_pElems[uiStageIndex];
    ShaderFieldsStub* sh = reinterpret_cast<ShaderFieldsStub*>(shader);
    stage->m_08 = sh->m_pArr[j];
    reinterpret_cast<::E7DE90Owner *>((stage))->ApplyPairToState(shader->V56());
}

struct S_00b7c120_Target
{
    int unk00;
    int unk04;
    void* unk08;
};

struct S_00b7c120_Global1
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
    S_00b7c120_Target** unk24;
};

struct S_00b7c120_Callback
{
};

struct S_00b7c120_Inner
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
    S_00b7c120_Callback* unk10c;
};

struct S_00b7c120_Outer
{
    S_00b7c120_Inner* unk00;
};

struct S_00b7c120_Global2
{
    int unk00;
    int unk04;
    int unk08;
    S_00b7c120_Outer* unk0c;
};


// Looks up targets[index] and stores the result of callback->FUN_004bc320(0) into its unk08 field.
// @fnv 0x00b7c120
void FUN_00b7c120(int index)
{
    S_00b7c120_Global1* global1 = reinterpret_cast<S_00b7c120_Global1*>(DAT_0126f74c);
    S_00b7c120_Target** targets = global1->unk24;
    S_00b7c120_Global2* global2 = (*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0));
    S_00b7c120_Target* target = targets[index];
    S_00b7c120_Outer* outer = global2->unk0c;
    S_00b7c120_Inner* inner = outer->unk00;
    S_00b7c120_Callback* callback = inner->unk10c;

    target->unk08 = ((void *)(uintptr_t)(reinterpret_cast<::FUN_004bc320_shell *>((callback))->FUN_004bc320(0)));
}

struct FUN_00b7c170_Entry
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_00b7c170_Container
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
    FUN_00b7c170_Entry** unk24;
};


// @fnv 0x00b7c170
void FUN_00b7c170(int index)
{
    FUN_00b7c170_Container* container = reinterpret_cast<FUN_00b7c170_Container*>(DAT_0126f74c);
    container->unk24[index]->unk08 = DAT_011f95e8;
}

struct B7C1F0Texture;

struct B7C1F0Stage
{
    int unk00;
    int unk04;
    B7C1F0Texture* m_pkTexture;
};

struct B7C1F0Pass
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
    B7C1F0Stage** m_ppkStages;
};

struct B7C1F0Property
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
    B7C1F0Texture** m_ppkTextures;
};


// Assigns the property's texture at uiTexture to the pass stage at uiStage, falling back to the default texture or null when none is set.
// @fnv 0x00b7c1f0
void FUN_00b7c1f0(B7C1F0Property* pkProperty, unsigned int uiStage, unsigned int uiTexture, bool bUseDefault)
{
    B7C1F0Stage* pkStage = (*reinterpret_cast<::B7C1F0Pass * *>(&::DAT_0126f74c))->m_ppkStages[uiStage];
    B7C1F0Texture* pkTexture = pkProperty->m_ppkTextures[uiTexture];
    if (pkTexture)
        pkStage->m_pkTexture = pkTexture;
    else
        pkStage->m_pkTexture = bUseDefault ? (*reinterpret_cast<::B7C1F0Texture * *>(&::DAT_011f951c)) : 0;
}


typedef int(* FUN_00b7c230_VFn)(void* self, int a, int b);

// @fnv 0x00b7c230
void FUN_00b7c230(char* self, unsigned int uiIndex, int a3, unsigned char ucFlag)
{
    char* g = (char*)DAT_0126f74c;
    uintptr_t* table = *(uintptr_t**)(g + 0x24);
    char* e = (char*)table[uiIndex];
    if (((FUN_00b7c230_VFn) * (void**)(*(char**)self + 0xf4))(self, 3, a3))
    {
        *(int*)(e + 8) = ((FUN_00b7c230_VFn) * (void**)(*(char**)self + 0xf4))(self, 3, a3);
        return;
    }
    *(int*)(e + 8) = ucFlag ? (*reinterpret_cast<int *>(&::DAT_011f951c)) : 0;
}

struct SlotObject
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
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual int GetValue(int a, int b);
};
struct SlotElem
{
    int unk00;
    int unk04;
    int m_08;
};
struct SlotGlobal
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
    SlotElem** m_24;
};

// Looks up the slot element at index and stores obj->GetValue(5, arg) into its m_08, or DAT_011f9514 when that returns 0.
// @fnv 0x00b7c2c0
void SetSlotValue(SlotObject* obj, int index, int arg)
{
    SlotGlobal* g = (SlotGlobal*)DAT_0126f74c;
    SlotElem* elem = g->m_24[index];
    if (obj->GetValue(5, arg) != 0)
    {
        elem->m_08 = obj->GetValue(5, arg);
    }
    else
    {
        elem->m_08 = (*reinterpret_cast<int *>(&::g_pkC0BC90DefaultTexture));
    }
}


struct RenderFlagInfo
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int flags18;
};
struct RenderState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int flags20;
};
struct RenderArguments
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    RenderState* state;
    RenderFlagInfo* info;
};

// @fnv 0x00b7c320
void ApplyRenderModeState(RenderArguments* args)
{
    const unsigned int mode = DAT_011f91e4;
    if (mode == 0x250 || mode == 0x251)
    {
        FUN_00b97e80(3, 0);
    }

    RenderFlagInfo* info = args->info;
    if (info && (info->flags18 & 1u))
    {
        ::UpdateRendererStateCount(0, 0);
    }

    RenderState* state = args->state;
    if ((mode == 6 || mode == 8) && (state->flags20 & 0x40000u) > 0)
    {
        --DAT_011ff9dc;
        ::FUN_00b97e30(1, 0);
        --DAT_011ffa18;
        ::BSRenderStateManager::SetColorWriteMask(7, (::BSRENDERSTATE_LOCK)(0));
    }
}

namespace fnv_00b7c510 {
struct SpawnedObject
{
    int m_00;
    int m_04;
    unsigned char m_flag;
};


struct FlagTarget
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
};

static unsigned int RotL1(unsigned int x)
{
    return (x << 1) | (x >> 31);
}

struct FUN_00b7c510_cls
{
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
    FlagTarget* m_30;
    void UpdateSpawnedObjectFlags();
};

// @fnv 0x00b7c510
void FUN_00b7c510_cls::UpdateSpawnedObjectFlags()
{
    unsigned int rot = 1;
    SpawnedObject** p = &(*reinterpret_cast<fnv_00b7c510::SpawnedObject * (*)[]>(&::DAT_011fec30))[1];
    do
    {
        SpawnedObject* a = p[-1];
        if (a != 0)
        {
            a->m_flag = ((*reinterpret_cast<unsigned int (*)[]>(&::DAT_011fc0a0))[(*reinterpret_cast<int *>(&::DAT_011f91e4))] & RotL1(rot)) != 0;
        }
        rot = RotL1(rot);
        SpawnedObject* b = *p;
        if (b != 0)
        {
            b->m_flag = ((*reinterpret_cast<unsigned int (*)[]>(&::DAT_011fc0a0))[(*reinterpret_cast<int *>(&::DAT_011f91e4))] & RotL1(rot)) != 0;
        }
        rot = RotL1(rot);
        p += 2;
    } while ((intptr_t)p < (intptr_t)&(*reinterpret_cast<fnv_00b7c510::SpawnedObject * (*)[]>(&::DAT_011fec30))[23]);
    m_30->v09();
}
}  // namespace fnv_00b7c510

namespace fnv_00b7ce90 {
struct NiTexture;
struct RenderState;

struct TexStage
{
    int unk00;
    int unk04;
    NiTexture* m_texture;
};

struct StageList
{
    TexStage* m_pHeadNode;
    TexStage* m_iSecondInteger;
};

struct ShaderPass
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
    StageList* m_kTextureStages;
    RenderState* GetRenderState();
};

struct RenderState
{
    virtual void r00();
    virtual void r01();
    virtual void r02();
    virtual void r03();
    virtual void r04();
    virtual void r05();
    virtual void r06();
    virtual void r07();
    virtual void r08();
    virtual void r09();
    virtual void r0a();
    virtual void r0b();
    virtual void r0c();
    virtual void r0d();
    virtual void r0e();
    virtual void r0f();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void SetBlend(int, int, int, int);
    virtual void q18();
    virtual void q19();
    virtual void SetRS(int, int, int, int);
};

struct PassKey
{
    int unk00;
    unsigned short m_type;
};

struct ShaderProps
{
    int unk00;
    int unk04;
    NiTexture* m_texture;
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
    int m_srcBlend;
    int m_dstBlend;
    int m_alphaTestRef;
    int m_zFunc;
};

struct Geometry
{
    virtual void g00();
    virtual void g01();
    virtual void g02();
    virtual void g03();
    virtual void g04();
    virtual void g05();
    virtual void g06();
    virtual void g07();
    virtual void g08();
    virtual void g09();
    virtual void g0a();
    virtual void g0b();
    virtual void g0c();
    virtual void g0d();
    virtual void g0e();
    virtual void g0f();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g1a();
    virtual void g1b();
    virtual void g1c();
    virtual void g1d();
    virtual void g1e();
    virtual void g1f();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g2a();
    virtual void g2b();
    virtual void g2c();
    virtual void g2d();
    virtual void g2e();
    virtual void g2f();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual void g33();
    virtual void g34();
    virtual void g35();
    virtual void g36();
    virtual void g37();
    virtual unsigned int GetUVSet();
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
    ShaderProps* m_props;
};


struct FUN_00b7ce90_class
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0a();
    virtual void s0b();
    virtual void s0c();
    virtual void s0d();
    virtual void s0e();
    virtual void s0f();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1a();
    virtual void s1b();
    virtual void s1c();
    virtual void s1d();
    virtual void s1e();
    virtual void s1f();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s2a();
    virtual void s2b();
    virtual void s2c();
    virtual void s2d();
    virtual void s2e();
    virtual void s2f();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s3a();
    virtual void s3b();
    virtual void s3c();
    virtual void s3d();
    virtual void s3e();
    virtual void s3f();
    virtual void s40();
    virtual void s41();
    virtual void Finish();
    NiTexture* GetTexture(Geometry* geom, int a);
    void SetupPass(void* a, Geometry* geom, PassKey* key);
};

// Selects the shader pass for the key's type, assigns textures and UV sets to its stages, sets blend and render states, then makes it the current pass.
// @fnv 0x00b7ce90
void FUN_00b7ce90_class::SetupPass(void* a, Geometry* geom, PassKey* key)
{
    if (!key)
        return;
    ShaderPass* pass = (*reinterpret_cast<fnv_00b7ce90::ShaderPass * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[key->m_type];
    ShaderProps* props = geom->m_props;
    if (!props)
        return;
    TexStage* stage = pass->m_kTextureStages->m_pHeadNode;
    stage->m_texture = ((::fnv_00b7ce90::NiTexture *)(::GetTextureByIndex((char *)(geom), 0)));
    reinterpret_cast<::E7DE90Owner *>((stage))->ApplyPairToState(geom->GetUVSet());
    stage = pass->m_kTextureStages->m_iSecondInteger;
    if (props->m_texture)
        stage->m_texture = props->m_texture;
    else
        stage->m_texture = (*reinterpret_cast<::fnv_00b7ce90::NiTexture * *>(&::DAT_011f952c));
    reinterpret_cast<::E7DE90Owner *>((stage))->ApplyPairToState(geom->GetUVSet());
    ((::fnv_00b7ce90::RenderState *)((*reinterpret_cast<::fnv_00b7ce90::ShaderPass * *>(&::DAT_0126f74c))->GetRenderState()))->SetBlend(props->m_srcBlend, props->m_dstBlend, 0, 0);
    ((::fnv_00b7ce90::RenderState *)((*reinterpret_cast<::fnv_00b7ce90::ShaderPass * *>(&::DAT_0126f74c))->GetRenderState()))->SetRS(0xab, props->m_alphaTestRef, 0, 0);
    ((::fnv_00b7ce90::RenderState *)((*reinterpret_cast<::fnv_00b7ce90::ShaderPass * *>(&::DAT_0126f74c))->GetRenderState()))->SetRS(0x17, props->m_zFunc, 0, 0);
    ::UpdateLightAndFogGlobals((intptr_t)(a), (::Context *)(geom));
    Finish();
    (*reinterpret_cast<::fnv_00b7ce90::ShaderPass * *>(&::DAT_0126f74c)) = pass;
}
}  // namespace fnv_00b7ce90

struct RenderContext
{
};
struct RenderNode
{
    int unk00, unk04, unk08, unk0c, unk10;
    RenderContext* unk14;
};
struct RenderGlobals
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    RenderNode* unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    void* unk44;
};
struct FeatureFlags
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int active20;
};
struct NiQuaternion
{
    float w, x, y, z;
};
struct ThreeByThreeMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct NiPoint3
{
    float x, y, z;
public:
    float ComputeMagnitude() const;
public:
    ::NiPoint3 *ScaleTo(::NiPoint3 *, float);
};
struct NiTransform
{
    ThreeByThreeMatrix rotate;
    NiPoint3 translate;
    float scale;
};
struct RenderOutput
{
    NiQuaternion orientation;
    NiTransform transform;
};
struct Callback;
typedef void(* RenderCallback)(Callback*, void*, int, int, int, int, int, int, NiTransform*, NiQuaternion*,
                                         int, int);
struct Callback
{
    RenderCallback* vtable;
};
struct Renderer
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Callback* target30;
    void FUN_00b7dd50();
};
// @fnv 0x00b7dd50
void Renderer::FUN_00b7dd50()
{
    RenderOutput renderOutput;
    reinterpret_cast<::NiD3DPass *>((reinterpret_cast<RenderGlobals*>(DAT_0126f74c)->unk24->unk14))->ApplyRenderStateChanges(0);
    ::UpdateFogShaderConstants();
    (*reinterpret_cast<::FeatureFlags * *>(&::DAT_011febf0))->active20 = 1;
    (*reinterpret_cast<::FeatureFlags * *>(&::DAT_011fec38))->active20 = 1;
    reinterpret_cast<::fnv_00b7c510::FUN_00b7c510_cls *>(this)->UpdateSpawnedObjectFlags();
    reinterpret_cast<::FUN_00b7deb0_class *>(this)->FUN_00b7c580();
    reinterpret_cast<::FUN_00b7deb0_class *>(this)->FUN_00b7c600();
    Callback* callback = target30;
    if (callback && reinterpret_cast<RenderGlobals*>(DAT_0126f74c)->unk44)
        callback->vtable[30](callback, reinterpret_cast<RenderGlobals*>(DAT_0126f74c)->unk44, 0, 0, 0, 0, 0, 0,
                             &renderOutput.transform, &renderOutput.orientation, 0, 1);
}

namespace fnv_00b7e300 {
// Destructor of a pooled object: releases the element array held at +4 and
// restores the class vtable pointer stored at +0.
struct FUN_00b7e300_cls
{
    void* m_pVTable;
    int** m_pData;
    void DestroyDataArray();
};

// Global memory manager that takes back a released block.
struct FUN_00b7e300_pool
{
};

extern void __cdecl FUN_0045cec0(void* pElement);

// Sets the vtable, then frees the m_pData array with its element destructor and releases the block.
// @fnv 0x00b7e300
void FUN_00b7e300_cls::DestroyDataArray()
{
    int** pData = m_pData;
    m_pVTable = &(*reinterpret_cast<char *>(&::DAT_010ef53c));
    if (pData != 0)
    {
        int count = (int)((std::size_t*)pData)[-1];  // element count stored in the block header
        fnv::crt::vector_destructor(pData, sizeof(int*), count, FUN_0045cec0);
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00b7e300::FUN_00b7e300_pool *>(&::g_memoryManager))))->FUN_00aa4060(pData - 1);
    }
}
}  // namespace fnv_00b7e300

struct ShaderResourceRelease
{
    void FUN_00b7fbe0();
    ShaderResourceRelease* FUN_00b7fd00(unsigned int flags);
};

void __cdecl NiFreeB60(void* pvMem);

struct NiTMapItemB60;

class NiTMapBaseB60
{
  public:
    virtual ~NiTMapBaseB60()
    {
        reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
        NiFreeB60(m_ppkHashTable);
    }

    void RemoveAll();

    unsigned int m_uiHashSize;
    NiTMapItemB60** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00b60360 : public NiTMapBaseB60
{
  public:
    virtual ~FUN_00b60360();
};

// Destructor for the map class that calls RemoveAll() to clear all entries.
// @fnv 0x00b60360
FUN_00b60360::~FUN_00b60360()
{
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
}

namespace fnv_00b60b50 {
class NiRefObject
{
  public:
    virtual ~NiRefObject()
    {
        InterlockedDecrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    }
    long refCount;
};
class ReleaseObject
{
  public:
    virtual void V0();
    virtual void DeleteThis();
    long references;
    void Release()
    {
        if (InterlockedDecrement(&references) == 0)
            DeleteThis();
    }
};
struct ReleasePointer
{
    ReleaseObject* ptr;
    ~ReleasePointer()
    {
        if (ptr)
            ptr->Release();
    }
};
class DeleteObjectRef
{
  public:
    virtual ~DeleteObjectRef();
    int unk04;
    long references;
    void Release()
    {
        if (InterlockedDecrement(&references) == 0)
            delete this;
    }
};
struct DeletePointer
{
    DeleteObjectRef* ptr;
    ~DeletePointer()
    {
        if (ptr)
            ptr->Release();
    }
};
struct FUN_00b60b50
{
    NiRefObject baseObject;
    ReleasePointer member08;
    int unk0c, unk10;
    ReleasePointer member14;
    ReleasePointer member18;
    ReleasePointer member1c;
    ReleasePointer member20;
    DeletePointer member24;
    ~FUN_00b60b50();
};
// Destructor of a struct holding reference-counted pointers; the member destructors release them.
// @fnv 0x00b60b50
FUN_00b60b50::~FUN_00b60b50()
{}
}  // namespace fnv_00b60b50

struct RefCounted_b60
{
    int m_iRefCount;
    virtual void Unk00();
    virtual void Destroy();
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_iRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_iRefCount) == 0)
            Destroy();
    }
};
struct RefSlot88_b60
{
    RefCounted_b60* ptr;
    RefSlot88_b60()
    {}
    ~RefSlot88_b60()
    {
        if (ptr)
            ptr->DecRefCount();
    }
};
class BaseObj_b60
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    BaseObj_b60();
    virtual ~BaseObj_b60();
};
class FUN_00b60cb0 : public BaseObj_b60
{
  public:
    unsigned int m_1c;
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
    unsigned int m_7c;
    NiPointer<RefCounted_b60> m_80;
    NiPointer<RefCounted_b60> m_84;
    RefSlot88_b60 m_88;
    unsigned short m_8c;
    unsigned short m_8e;
    FUN_00b60cb0();
    virtual ~FUN_00b60cb0();
};
// Initializes the object: clears m_88.ptr, m_8c, m_8e, m_80, m_7c and sets m_1c to 4.
// @fnv 0x00b60cb0
FUN_00b60cb0::FUN_00b60cb0()
{
    m_88.ptr = 0;
    m_8c = 0;
    m_8e = 0;
    m_80 = (RefCounted_b60*)0;
    m_7c = 0;
    m_1c = 4;
}


struct B61250RefObj
{
    virtual void Unk00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
    void DecRef()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            DeleteThis();
    }
};

struct B61250Ptr
{
    B61250RefObj* m_p;
    ~B61250Ptr()
    {
        if (m_p)
            m_p->DecRef();
    }
    void Release()
    {
        if (m_p)
        {
            m_p->DecRef();
            m_p = 0;
        }
    }
};

struct B61250Item
{
    ~B61250Item()
    {
        reinterpret_cast<::FUN_00bd8f90 *>(this)->FUN_00bd8f90::~FUN_00bd8f90();
    }
};

struct B61250Node
{
    B61250Node* next;
    B61250Node* prev;
    B61250Item* data;
};

struct B61250List
{
    B61250Node* head;
    B61250Node* tail;
    int count;
    void RemoveAll() throw();
    B61250Item*& GetNext(B61250Node*& pos)
    {
        B61250Item*& r = pos->data;
        pos = pos->next;
        return r;
    }
    ~B61250List()
    {
        reinterpret_cast<::BSShaderLightingProperty *>(this)->ClearLights();
    }
};

struct B61250Map
{
    void RemoveAll();
    ~B61250Map();
};

struct FUN_00b61250
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    B61250List m_kNode;
    B61250Ptr m_ptr;
    B61250Map m_map;
    ~FUN_00b61250();
};

// @fnv 0x00b61250
FUN_00b61250::~FUN_00b61250()
{
    m_ptr.Release();
    reinterpret_cast<::S_00b601a0_Map *>(&(m_map))->FUN_00b601a0();
    for (B61250Node* node = m_kNode.head; node;)
    {
        B61250Item* p = m_kNode.GetNext(node);
        delete p;
    }
    reinterpret_cast<::BSShaderLightingProperty *>(&(m_kNode))->ClearLights();
    m_ptr.Release();
    reinterpret_cast<::S_00b601a0_Map *>(&(m_map))->FUN_00b601a0();
}

void __cdecl NiFreeB63(void* pvMem);

struct NiTMapItemB63;

class NiTMapBaseB63
{
  public:
    virtual ~NiTMapBaseB63()
    {
        reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
        NiFreeB63(m_ppkHashTable);
    }

    void RemoveAll();

    unsigned int m_uiHashSize;
    NiTMapItemB63** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00b63d80 : public NiTMapBaseB63
{
  public:
    virtual ~FUN_00b63d80();
};
// Runs the base destructor, then frees this object via g_memoryManager when bDelete is set, and returns this.
// @fnv 0x00b63e70
FUN_00b63e70_class* FUN_00b63e70_class::FUN_00b63e70(bool bDelete)
{
    reinterpret_cast<::FUN_00b63d80 *>(this)->FUN_00b63d80::~FUN_00b63d80();
    if ((unsigned char)bDelete & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

// Destructor that calls RemoveAll() to clear the map's entries.
// @fnv 0x00b63d80
FUN_00b63d80::~FUN_00b63d80()
{
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
}

// Feed every entry of the owner's list for this key into the current thread's accumulator.


struct B644B0Entry
{
    int unk00;
    unsigned short m_usIndex;
};

struct B644B0EntryList
{
    int unk00;
    B644B0Entry** m_ppkEntries;
    int unk08;
    int unk0C;
    unsigned int m_uiCount;
};

class B644B0Accumulator
{
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
    virtual void Add(B644B0Entry* pkEntry, unsigned int uiIndex);
};

class B644B0Owner
{
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
    virtual void Unk_2D();
    virtual B644B0EntryList* GetEntries(void* pvKey);
};

struct B644B0Shape
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
    char unk164;
    bool m_bEnableState;
    char unk166;
    char unk167;
    int unk168;
    int unk16C;
    int unk170;
    B644B0Accumulator* m_apkAccumulators[4];
};

// If the shape's flag is set, fetches the entry list for pvKey and adds each entry to the thread's accumulator, returning true.
// @fnv 0x00b644b0
bool __cdecl AddEntriesToAccumulator(B644B0Shape* pkShape, void* pvKey, int iUnused, B644B0Owner* pkOwner)
{
    if (pkShape->m_bEnableState)
    {
        B644B0EntryList* pkList = pkOwner->GetEntries(pvKey);
        if (pkList)
        {
            for (unsigned int i = 0; i < pkList->m_uiCount; i++)
            {
                B644B0Entry* pkEntry = pkList->m_ppkEntries[i];
                pkShape->m_apkAccumulators[::g_tlsBlock.renderThreadIndex]->Add(pkEntry, pkEntry->m_usIndex);
            }
        }
    }
    return true;
}

namespace fnv_00b66810 {


struct SpawnedBaseObject
{
    virtual ~SpawnedBaseObject();
    int m_04;

    SpawnedBaseObject()
    {
        m_04 = 0;
        InterlockedIncrement(&(*reinterpret_cast<long *>(&::NiRefObject::ms_lObjectCount)));
    }
};

struct FUN_00b66810 : SpawnedBaseObject
{
    bool m_08;
    int m_0c;
    int m_10;

    FUN_00b66810(bool flag);
    virtual ~FUN_00b66810();
};

// Initializes the object with the given flag and zeroes the two integer members m_0c and m_10.
// @fnv 0x00b66810
FUN_00b66810::FUN_00b66810(bool flag)
{
    m_08 = flag;
    m_0c = 0;
    m_10 = 0;
}
}  // namespace fnv_00b66810

class NiRefObject2
{
  public:
    NiRefObject2() : m_uiRefCount(0)
    {
        InterlockedIncrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    }
    virtual ~NiRefObject2();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

struct ZeroQuad
{
    float a, b, c, d;
    ZeroQuad() : a(0.0f), b(0.0f), c(0.0f), d(0.0f)
    {}
};

class FUN_00b668b0 : public NiRefObject2
{
  public:
    FUN_00b668b0();
    virtual ~FUN_00b668b0();

    NiPointer<NiRefObject2> m_pReferencedObject;
    ZeroQuad m_akRows[4];
    float m_afExtra[4];
    int m_iMode;
    int m_iScaleA;
    int m_iScaleB;
    int m_iType;
    NiPointer<NiRefObject2> m_spOther;
    int m_iFlags;
};

// @fnv 0x00b668b0
FUN_00b668b0::FUN_00b668b0()
{
    m_pReferencedObject = 0;
    for (int i = 0; i < 4; i++)
    {
        m_akRows[i].a = 0.0f;
        m_akRows[i].b = 0.0f;
        m_akRows[i].c = 0.0f;
        m_akRows[i].d = 0.0f;
    }
    m_afExtra[0] = 0.0f;
    m_afExtra[1] = 0.0f;
    m_afExtra[2] = 0.0f;
    m_afExtra[3] = 0.0f;
    m_iMode = 2;
    m_iScaleA = 1;
    m_iScaleB = 1;
    m_iType = 3;
    m_spOther = 0;
    m_iFlags = 0;
}

struct TargetGroup
{
    virtual void Virtual00();
    virtual void Virtual01();
    virtual void Virtual02();
    virtual void Virtual03();
    virtual void Virtual04();
    virtual void Virtual05();
    virtual void Virtual06();
    virtual void Virtual07();
    virtual void Virtual08();
    virtual void Virtual09();
    virtual void Virtual10();
    virtual void Virtual11();
    virtual void Virtual12();
    virtual void Virtual13();
    virtual void Virtual14();
    virtual void Virtual15();
    virtual void Virtual16();
    virtual void Virtual17();
    virtual void Virtual18();
    virtual void Virtual19();
    virtual void Virtual20();
    virtual void Virtual21();
    virtual void Virtual22();
    virtual void Virtual23();
    virtual void Virtual24();
    virtual void Virtual25();
    virtual void Virtual26();
    virtual void Virtual27();
    virtual void Virtual28();
    virtual void Virtual29();
    virtual void Virtual30();
    virtual void Virtual31();
    virtual void Virtual32();
    virtual void Virtual33();
    virtual void Virtual34();
    virtual unsigned int Width(unsigned int);
    virtual unsigned int Height(unsigned int);
};
struct RenderConfigSurface
{
    virtual void Virtual00();
    virtual void Virtual01();
    virtual void Virtual02();
    virtual void Virtual03();
    virtual void Virtual04();
    virtual void Virtual05();
    virtual void Virtual06();
    virtual void Virtual07();
    virtual void Virtual08();
    virtual void Virtual09();
    virtual void Virtual10();
    virtual void Virtual11();
    virtual void Virtual12();
    virtual void Virtual13();
    virtual void Virtual14();
    virtual void Virtual15();
    virtual void Virtual16();
    virtual void Virtual17();
    virtual void Virtual18();
    virtual void Virtual19();
    virtual void Virtual20();
    virtual void Virtual21();
    virtual void Virtual22();
    virtual void Virtual23();
    virtual void Virtual24();
    virtual void Virtual25();
    virtual void Virtual26();
    virtual void Virtual27();
    virtual void Virtual28();
    virtual void Virtual29();
    virtual void Virtual30();
    virtual void Virtual31();
    virtual void Virtual32();
    virtual void Virtual33();
    virtual void Virtual34();
    virtual void Virtual35();
    virtual void Virtual36();
    virtual void Virtual37();
    virtual void Virtual38();
    virtual void Virtual39();
    virtual void Virtual40();
    virtual void Virtual41();
    virtual void Virtual42();
    virtual void Virtual43();
    virtual void Virtual44();
    virtual void Virtual45();
    virtual void Virtual46();
    virtual void Virtual47();
    virtual void Virtual48();
    virtual void Virtual49();
    virtual TargetGroup* Group();
};
struct GroupDispatch
{
    void* slot00;
    void* slot01;
    void* slot02;
    void* slot03;
    void* slot04;
    void* slot05;
    void* slot06;
    void* slot07;
    void* slot08;
    void* slot09;
    void* slot10;
    void* slot11;
    void* slot12;
    void* slot13;
    void* slot14;
    void* slot15;
    void* slot16;
    void* slot17;
    void* slot18;
    void* slot19;
    void* slot20;
    void* slot21;
    void* slot22;
    void* slot23;
    void* slot24;
    void* slot25;
    void* slot26;
    void* slot27;
    void* slot28;
    void* slot29;
    void* slot30;
    void* slot31;
    void* slot32;
    void* slot33;
    void* slot34;
    void* slot35;
    void* slot36;
    void* slot37;
    void* slot38;
    void* slot39;
    void* slot40;
    void* slot41;
    void* slot42;
    void* slot43;
    void* slot44;
    void* slot45;
    void* slot46;
    void* slot47;
    void* slot48;
    void* slot49;
    TargetGroup*(* group)(RenderConfigSurface*, GroupDispatch*);
};
struct GroupReceiver
{
    GroupDispatch* dispatch;
};
int __cdecl FUN_00b6c200(int);
extern unsigned int DAT_011adbc8;
extern bool DAT_012004fc;
// @fnv 0x00b6c2c0
void GetRenderTargetDesc(RenderConfigSurface* renderer, unsigned int type, unsigned int* width,
                                   unsigned int* height, unsigned int* format, unsigned int* unused,
                                   unsigned int* flags, unsigned int* samples)
{
    *unused = 0;
    *samples = FUN_00b6c200(DAT_011f9490);
    switch (type)
    {
        {
        case 0:
            *flags = 0x26;
            if (renderer->Group()->Width(0) > 0x500)
            {
                *width = DAT_011f9426 ? DAT_011f9430 / 4 : renderer->Group()->Width(0) / 4;
                *height = DAT_011f9426 ? DAT_011f9434 / 4 : renderer->Group()->Height(0) / 4;
            }
            else
            {
                *height = 0x100;
                *width = 0x100;
            }
            *format = 0x71;
            break;
        }
        {
        case 1:
            *flags = 0x26;
            unsigned int size = (unsigned int)((float)((uintptr_t)(reinterpret_cast<::FUN_00b6c1a0_cls *>((renderer))->FUN_00b6c1a0())) * 0.5);
            if (size < 0x100)
                size = 0x100;
            *width = size;
            *height = 0x100;
            *format = 0x71;
            break;
        }
        {
        case 2:
            *flags = 0x26;
            if (renderer->Group()->Width(0) > 0x500)
            {
                *width = DAT_011f9426 ? DAT_011f9430 / 4 : renderer->Group()->Width(0) / 4;
                *height = DAT_011f9426 ? DAT_011f9434 / 4 : renderer->Group()->Height(0) / 4;
            }
            else
            {
                *height = 0x100;
                *width = 0x100;
            }
            *format = 0x71;
            break;
        }
        {
        case 3:
            if (!DAT_011f9426)
            {
                *width = ((unsigned int)(reinterpret_cast<::FUN_00b6c1a0_cls *>((renderer))->FUN_00b6c1a0()));
                *height = ((unsigned int)(reinterpret_cast<::FUN_00b6c1d0_Class *>((renderer))->FUN_00b6c1d0()));
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x26;
            *format = 0;
            break;
        }
        {
        case 4:
            if (!DAT_011f9426)
            {
                *width = ((unsigned int)(reinterpret_cast<::FUN_00b6c1a0_cls *>((renderer))->FUN_00b6c1a0()));
                *height = ((unsigned int)(reinterpret_cast<::FUN_00b6c1d0_Class *>((renderer))->FUN_00b6c1d0()));
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = FUN_00b6c200(DAT_011f9490) > 0 ? 0x62 : 0x22;
            *format = DAT_011f941e ? 0x71 : 0;
            break;
        }
        {
        case 6:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0);
                *height = renderer->Group()->Height(0);
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 6;
            *format = 0;
            break;
        }
        {
        case 7:
            *height = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *width = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *flags = 6;
            *format = 0x74;
            break;
        }
        {
        case 13:
            *width = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *height = 1;
            *flags = 0xc;
            *format = 0x51;
            break;
        }
        {
        case 14:
            *width = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *height = 0x10;
            *flags = 0xc;
            *format = 0x74;
            break;
        }
        {
        case 15:
            *height = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *width = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *flags = 0xc;
            *format = 0x72;
            break;
        }
        {
        case 17:
            *width = 0x200;
            *height = 0x200;
            *flags = 0x122;
            *format = 0x15;
            break;
        }
        {
        case 18:
            *width = (*reinterpret_cast<unsigned int *>(&::DAT_011ad81c));
            *height = (*reinterpret_cast<unsigned int *>(&::DAT_011ad820));
            *flags = 0xc;
            *format = 0x15;
            break;
        }
        {
        case 19:
            *width = (*reinterpret_cast<unsigned int *>(&::DAT_011ad81c));
            *height = (*reinterpret_cast<unsigned int *>(&::DAT_011ad820));
            *flags = 4;
            *format = 0x15;
            *flags |= 0x20;
            break;
        }
        {
        case 20:
            *width = *height = 0x200;
            *flags = 6;
            *format = 0x71;
            break;
        }
        {
        case 16:
            *height = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *width = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *flags = 0xc;
            *format = 0x74;
            break;
        }
        {
        case 8:
            *width = *height = 0x200;
            *flags = 2;
            *format = 0x24;
            break;
        }
        {
        case 9:
            *width = (*reinterpret_cast<unsigned int *>(&::fnv_004da670::DAT_011ad814));
            *height = (*reinterpret_cast<unsigned int *>(&::fnv_004da670::DAT_011ad818));
            *flags = 0x40;
            *format = 0;
            *samples = (*reinterpret_cast<unsigned int *>(&::fnv_004da670::DAT_011ad810));
            *flags |= 0x20;
            break;
        }
        {
        case 22:
            *width = (*reinterpret_cast<unsigned int *>(&::fnv_004da670::DAT_011ad814));
            *height = (*reinterpret_cast<unsigned int *>(&::fnv_004da670::DAT_011ad818));
            *flags = 0x40;
            *format = 0;
            *samples = (*reinterpret_cast<unsigned int *>(&::fnv_004da670::DAT_011ad810));
            *flags |= 0x20;
            break;
        }
        {
        case 10:
            *width = *height = 0x200;
            *flags = 0x40;
            *format = 0;
            break;
        }
        {
        case 12:
            *width = *height = 0x80;
            *flags = 6;
            *format = 0x24;
            break;
        }
        {
        case 21:
            *height = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *width = (*reinterpret_cast<unsigned int *>(&::DAT_01200054));
            *flags = 4;
            *format = 0;
            break;
        }
        {
        case 23:
            *width = *height = 0x100;
            *flags = 6;
            *format = 0;
            break;
        }
        {
        case 24:
            if (!DAT_011f9426)
            {
                GroupDispatch* dispatch = reinterpret_cast<GroupReceiver*>(renderer)->dispatch;
                *width = (dispatch->group(renderer, dispatch))->Width(0) / 4;
                *height = renderer->Group()->Height(0) / 4;
            }
            else
            {
                *width = DAT_011f9430 / 4;
                *height = DAT_011f9434 / 4;
            }
            *flags = 6;
            *format = 0;
            break;
        }
        {
        case 26:
        case 27:
            *height = DAT_011adbc8;
            *width = DAT_011adbc8;
            *flags = 6;
            *format = 0;
            break;
        }
        {
        case 31:
            if (!DAT_011f9426)
            {
                *width = ((unsigned int)(reinterpret_cast<::FUN_00b6c1a0_cls *>((renderer))->FUN_00b6c1a0()));
                *height = ((unsigned int)(reinterpret_cast<::FUN_00b6c1d0_Class *>((renderer))->FUN_00b6c1d0()));
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 6;
            if (FUN_00b6c200(DAT_011f9490) > 0)
                *flags = 0x46;
            *format = 0;
            break;
        }
        {
        case 32:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0);
                *height = renderer->Group()->Height(0);
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x42;
            *format = DAT_011ad80e ? 0x71 : 0x15;
            break;
        }
        {
        case 33:
            if (!DAT_011f9426)
            {
                *width = ((unsigned int)(reinterpret_cast<::FUN_00b6c1a0_cls *>((renderer))->FUN_00b6c1a0()));
                *height = ((unsigned int)(reinterpret_cast<::FUN_00b6c1d0_Class *>((renderer))->FUN_00b6c1d0()));
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 2;
            *format = DAT_011ad80e ? 0x72 : 0x15;
            break;
        }
        {
        case 25:
        case 34:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0);
                *height = renderer->Group()->Height(0);
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x26;
            *format = 0;
            break;
        }
        {
        case 35:
        case 36:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0);
                *height = renderer->Group()->Height(0);
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x42;
            *format = 0x15;
            break;
        }
        {
        case 37:
        case 38:
        case 40:
            if (!DAT_011f9426)
            {
                *width = ((unsigned int)(reinterpret_cast<::FUN_00b6c1a0_cls *>((renderer))->FUN_00b6c1a0())) / 4;
                *height = ((unsigned int)(reinterpret_cast<::FUN_00b6c1d0_Class *>((renderer))->FUN_00b6c1d0())) / 4;
            }
            else
            {
                *width = DAT_011f9430 / 4;
                *height = DAT_011f9434 / 4;
            }
            *flags = 6;
            *format = 0x15;
            break;
        }
        {
        case 39:
            if (!DAT_011f9426)
            {
                *width = ((unsigned int)(reinterpret_cast<::FUN_00b6c1a0_cls *>((renderer))->FUN_00b6c1a0()));
                *height = ((unsigned int)(reinterpret_cast<::FUN_00b6c1d0_Class *>((renderer))->FUN_00b6c1d0()));
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 2;
            *format = 0x15;
            break;
        }
        {
        case 5:
            if (!DAT_011f9426)
            {
                *width = ((unsigned int)(reinterpret_cast<::FUN_00b6c1a0_cls *>((renderer))->FUN_00b6c1a0()));
                *height = ((unsigned int)(reinterpret_cast<::FUN_00b6c1d0_Class *>((renderer))->FUN_00b6c1d0()));
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x22;
            *format = 0x71;
            break;
        }
        {
        case 41:
            *width = *height = 0x100;
            *flags = 2;
            *format = 0;
            break;
        }
        {
        case 42:
            *width = *height = 0x200;
            *flags = 6;
            *format = 0x72;
            break;
        }
        {
        case 43:
            *width = *height = (*reinterpret_cast<unsigned short *>(&::fnv_004da670::DAT_011ad830));
            *flags = 6;
            *format = (*reinterpret_cast<unsigned int *>(&::DAT_011ad870));
            break;
        }
        {
        case 44:
            *width = *height = 0x100;
            *flags = 0x10;
            *format = 0;
            break;
        }
        {
        case 45:
        case 49:
            *width = 0x500;
            TargetGroup* pHeightGroup = renderer->Group();
            TargetGroup* pWidthGroup = renderer->Group();
            *height = (unsigned int)((float)pHeightGroup->Height(0) / (float)pWidthGroup->Width(0) * (float)*width);
            *flags = 4;
            *format = 0;
            break;
        }
        {
        case 46:
            if (!DAT_011f9426)
            {
                *width = renderer->Group()->Width(0) / 2;
                *height = renderer->Group()->Height(0) / 2;
            }
            else
            {
                *width = DAT_011f9430 / 2;
                *height = DAT_011f9434 / 2;
            }
            *flags = 4;
            *format = 0;
            break;
        }
        {
        case 47:
            if (!DAT_011f9426)
            {
                *width = ((unsigned int)(reinterpret_cast<::FUN_00b6c1a0_cls *>((renderer))->FUN_00b6c1a0()));
                *height = ((unsigned int)(reinterpret_cast<::FUN_00b6c1d0_Class *>((renderer))->FUN_00b6c1d0()));
            }
            else
            {
                *width = DAT_011f9430;
                *height = DAT_011f9434;
            }
            *flags = 0x40;
            *format = 0;
            break;
        }
        {
        case 48:
            *width = 0x500;
            TargetGroup* pHeightGroup = renderer->Group();
            TargetGroup* pWidthGroup = renderer->Group();
            *height = (unsigned int)((float)pHeightGroup->Height(0) / (float)pWidthGroup->Width(0) * (float)*width);
            *flags = 0x40;
            *format = 0;
            break;
        }
        {
        case 50:
            *width = *height = 0x100;
            *flags = 4;
            *format = 0;
            break;
        }
        {
        case 51:
            *width = *height = 8;
            *flags = 0;
            *format = 0;
            break;
        }
        {
        case 29:
        case 30:
            *width = *height = DAT_012004fc ? 0x200 : 0x80;
            *flags = 0;
            *format = 0x17;
            break;
        }
        {
        case 28:
            *width = *height = DAT_012004fc ? 0x200 : 0x80;
            *flags = 4;
            *format = 0x17;
            break;
        }
    }
    if (!(*flags & 0x40))
        *samples = 0;
}

struct B6F930Props
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_usFlags;
};

struct B6F930Geom
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
    B6F930Props* m_pkProps;
};

struct B6F930PassArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iArrayLength;
    void Add(B6F930Geom* pkGeom, int iPass, int a3, int a4, int a5, int a6, int a7, int a8);
};

struct B6F930Shader
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m_uiFlags20;
    unsigned int m_uiFlags24;
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
    B6F930PassArray* m_pkPasses;
    B6F930PassArray* AddGeomPass(B6F930Geom* pkGeom);
};

// @fnv 0x00b6f930
B6F930PassArray* B6F930Shader::AddGeomPass(B6F930Geom* pkGeom)
{
    bool bPropsFlag = false;
    if (pkGeom->m_pkProps)
        bPropsFlag = (pkGeom->m_pkProps->m_usFlags >> 9) & 1;
    bool bAlt = (m_uiFlags24 & 0x20) > 0;
    reinterpret_cast<::BA97B0Owner *>(this)->CreateChildIfMissing(1);
    if (m_pkPasses->m_iArrayLength == 0)
    {
        if (bAlt)
        {
            if (bPropsFlag)
            {
                if ((m_uiFlags20 & 2) > 0)
                    m_pkPasses->Add(pkGeom, 0x2ef, 0, 0, 0, 0, 0, 0);
                else
                    m_pkPasses->Add(pkGeom, 0x2ee, 0, 0, 0, 0, 0, 0);
            }
            else
            {
                if ((m_uiFlags20 & 2) > 0)
                    m_pkPasses->Add(pkGeom, 0x2e9, 0, 0, 0, 0, 0, 0);
                else
                    m_pkPasses->Add(pkGeom, 0x2e8, 0, 0, 0, 0, 0, 0);
            }
        }
        else
        {
            if (bPropsFlag)
            {
                if ((m_uiFlags20 & 2) > 0)
                    m_pkPasses->Add(pkGeom, 0x2e3, 0, 0, 0, 0, 0, 0);
                else
                    m_pkPasses->Add(pkGeom, 0x2e2, 0, 0, 0, 0, 0, 0);
            }
            else
            {
                if ((m_uiFlags20 & 2) > 0)
                    m_pkPasses->Add(pkGeom, 0x2dd, 0, 0, 0, 0, 0, 0);
                else
                    m_pkPasses->Add(pkGeom, 0x2dc, 0, 0, 0, 0, 0, 0);
            }
        }
    }
    return m_pkPasses;
}

struct SmartPtr
{
    void* ptr;
    SmartPtr& operator=(const SmartPtr& other);
};

struct MyContext
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
    SmartPtr unk30;
    SmartPtr unk34;
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
    SmartPtr unk7c;
    SmartPtr unk80;
    SmartPtr unk84;
    SmartPtr unk88;
};

struct StagePropSub
{
};


struct StageMgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int unk18;
    int unk1c;
    int unk20;
    TexStageStub** m_pElems;
    int unk28;
    int unk2c;
    StagePropSub* unk30;

    void SetProperty(int prop, int val)
    {
        if (!unk30)
        {
            unk30 = ((::StagePropSub *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
        }
        reinterpret_cast<::StateGroup *>((unk30))->SetNodeValue(prop, val, 1);
    }

};

void __cdecl SetShaderConstantMapEntryFlags(int a1);

extern V4 DAT_011ad850;

// Looks up contexts 1, 14, 15 and 13 and copies their unk7c/unk80 or unk84/unk88 into unk30/unk34 based on a1, then sets properties on DAT_011fdff8[a1].
// @fnv 0x00b7a870
void __cdecl FUN_00b7a870(unsigned int uiStageId)
{
    MyContext* p1 = ((::MyContext *)(::FUN_00b55560(1)));
    MyContext* pContext14 = ((::MyContext *)(::FUN_00b55560(14)));
    MyContext* pContext15 = ((::MyContext *)(::FUN_00b55560(15)));
    MyContext* pContext13 = ((::MyContext *)(::FUN_00b55560(13)));

    if (uiStageId - 0x24e <= 3)
    {
        if (p1)
        {
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(p1->unk30))->operator=((const ::FUN_00c663d0 &)(p1->unk7c));
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(p1->unk34))->operator=((const ::FUN_00c663d0 &)(p1->unk80));
        }
        if (pContext14)
        {
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext14->unk30))->operator=((const ::FUN_00c663d0 &)(pContext14->unk7c));
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext14->unk34))->operator=((const ::FUN_00c663d0 &)(pContext14->unk80));
        }
        if (pContext15)
        {
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext15->unk30))->operator=((const ::FUN_00c663d0 &)(pContext15->unk7c));
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext15->unk34))->operator=((const ::FUN_00c663d0 &)(pContext15->unk80));
        }
        if (pContext13)
        {
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext13->unk30))->operator=((const ::FUN_00c663d0 &)(pContext13->unk7c));
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext13->unk34))->operator=((const ::FUN_00c663d0 &)(pContext13->unk80));
        }
    }
    else
    {
        if (p1)
        {
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(p1->unk30))->operator=((const ::FUN_00c663d0 &)(p1->unk84));
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(p1->unk34))->operator=((const ::FUN_00c663d0 &)(p1->unk88));
        }
        if (pContext14)
        {
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext14->unk30))->operator=((const ::FUN_00c663d0 &)(pContext14->unk84));
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext14->unk34))->operator=((const ::FUN_00c663d0 &)(pContext14->unk88));
        }
        if (pContext15)
        {
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext15->unk30))->operator=((const ::FUN_00c663d0 &)(pContext15->unk84));
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext15->unk34))->operator=((const ::FUN_00c663d0 &)(pContext15->unk88));
        }
        if (pContext13)
        {
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext13->unk30))->operator=((const ::FUN_00c663d0 &)(pContext13->unk84));
            reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::SmartPtr &)(pContext13->unk34))->operator=((const ::FUN_00c663d0 &)(pContext13->unk88));
        }

        if (DAT_011f91c0 >= 2)
        {
            SetShaderConstantMapEntryFlags(uiStageId);
        }
        else if (DAT_011f91c0 == 1)
        {
            ::UpdateFlagHolders(uiStageId);
        }
    }

    if (uiStageId < 0x2f7)
    {
        (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]->SetProperty(0x1c, 0);

        if ((DAT_011f941c & 1) > 0)
        {
            (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]->SetProperty(0xa8, 0);
        }
        else
        {
            if ((uiStageId >= 0x1e2 && uiStageId <= 0x1e6) || (uiStageId - 0x1ec) <= 2)
            {
                reinterpret_cast<::RenderPassB71 *>(((*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]))->FUN_00b71a10(0xa8, 15, 0);
            }
            else if (uiStageId - 0x154 <= 0x23)
            {
                reinterpret_cast<::RenderPassB71 *>(((*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]))->FUN_00b71a10(0xa8, 15, 0);
            }
            else if (uiStageId == 0x2d6 || uiStageId == 0x2d7 || uiStageId == 0x14 || uiStageId == 0x15)
            {
                reinterpret_cast<::RenderPassB71 *>(((*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]))->FUN_00b71a10(0xa8, 8, 0);
            }
            else if (uiStageId - 1 <= 4)
            {
                reinterpret_cast<::RenderPassB71 *>(((*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]))->FUN_00b71a10(0xa8, 0, 0);
            }
            else if (uiStageId - 6 <= 2)
            {
                reinterpret_cast<::RenderPassB71 *>(((*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]))->FUN_00b71a10(0xa8, 15, 0);
            }
            else if (uiStageId == 9)
            {
                reinterpret_cast<::RenderPassB71 *>(((*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]))->FUN_00b71a10(0xa8, 0, 0);
            }
            else
            {
                reinterpret_cast<::RenderPassB71 *>(((*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]))->FUN_00b71a10(0xa8, 7, 0);
            }
        }

        if (DAT_011f91b8 == 6)
        {
            (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]->SetProperty(0x34, 1);
            (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]->SetProperty(0x38, 8);
            (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]->SetProperty(0x37, 7);
            (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]->SetProperty(0x35, 1);
            (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]->SetProperty(0x36, 1);
        }

        if (uiStageId != 0x235)
        {
            for (unsigned int i = 0; i < (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]->unk18; ++i)
            {
                TexStageStub* stage = (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[uiStageId]->m_pElems[i];
                if (stage && stage->m_08 && stage->m_08 != DAT_011f9534 && i != 7)
                {
                    reinterpret_cast<::E7DE90Owner *>((stage))->ApplyPairToState(3);
                }
            }
        }
    }

    if (uiStageId == 0x235)
    {
        (*reinterpret_cast<::V4 *>((void *)&::DAT_011fa2f0)) = DAT_011ad850;
    }
}

namespace fnv_00b7af80 {
class NiGPUProgram : public ManagedRef
{
};
struct ShaderPointer
{
    ManagedRef* value;
    ShaderPointer& operator=(const ShaderPointer& other)
    {
        if (value != other.value)
        {
            if (value)
                value->DecRefCount();
            value = other.value;
            if (value)
                value->IncRefCount();
        }
        return *this;
    }
};
struct ShaderSelector
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
    NiPointer<NiGPUProgram> program;
    int unk2c;
    ShaderPointer vertex;
    ShaderPointer pixel;
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
    NiGPUProgram* defaultProgram;
    NiGPUProgram* mainProgram;
    NiGPUProgram* specialProgram;
    NiGPUProgram* alternateProgram;
    ShaderPointer specialVertex;
    ShaderPointer specialPixel;
    ShaderPointer defaultVertex;
    ShaderPointer defaultPixel;
    void SelectShaderProgram(unsigned int mode);
};
// Looks up DAT_011fdff8[mode] into DAT_0126f74c, picks program/vertex/pixel shader pointers by mode, using special shaders for modes 592 and 593.
// @fnv 0x00b7af80
void ShaderSelector::SelectShaderProgram(unsigned int mode)
{
    DAT_0126f74c = (*reinterpret_cast<int (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[mode];
    switch (mode)
    {
    case 97:
    case 254:
    case 267:
    case 489:
        program = specialProgram;
        break;
    case 3:
    case 5:
    case 8:
    case 18:
    case 19:
    case 21:
    case 92:
    case 93:
    case 94:
    case 95:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 125:
    case 137:
    case 138:
    case 139:
    case 140:
    case 141:
    case 142:
    case 143:
    case 144:
    case 145:
    case 146:
    case 155:
    case 156:
    case 157:
    case 166:
    case 167:
    case 168:
    case 177:
    case 178:
    case 179:
    case 188:
    case 189:
    case 190:
    case 198:
    case 199:
    case 205:
    case 206:
    case 212:
    case 213:
    case 220:
    case 221:
    case 229:
    case 230:
    case 238:
    case 239:
    case 247:
    case 248:
    case 261:
    case 262:
    case 265:
    case 273:
    case 274:
    case 277:
    case 284:
    case 285:
    case 288:
    case 295:
    case 296:
    case 299:
    case 302:
    case 303:
    case 309:
    case 310:
    case 315:
    case 316:
    case 321:
    case 322:
    case 327:
    case 328:
    case 333:
    case 335:
    case 336:
    case 338:
    case 342:
    case 343:
    case 349:
    case 350:
    case 355:
    case 356:
    case 361:
    case 362:
    case 367:
    case 368:
    case 373:
    case 374:
    case 483:
    case 486:
    case 488:
    case 491:
    case 493:
    case 562:
    case 582:
    case 583:
    case 585:
    case 591:
    case 593:
    case 596:
    case 597:
    case 727:
    case 729:
    case 735:
    case 741:
    case 747:
        program = mainProgram;
        break;
    case 147:
    case 148:
    case 495:
    case 496:
    case 497:
    case 498:
    case 499:
    case 500:
    case 501:
    case 502:
    case 503:
    case 504:
    case 505:
    case 506:
    case 507:
    case 508:
    case 509:
    case 510:
    case 511:
    case 512:
    case 513:
    case 514:
    case 515:
    case 516:
    case 517:
    case 518:
    case 519:
    case 520:
    case 521:
    case 522:
    case 523:
    case 524:
    case 525:
    case 526:
    case 527:
    case 528:
    case 529:
    case 530:
    case 531:
    case 532:
    case 533:
    case 534:
    case 535:
    case 536:
    case 537:
    case 538:
    case 539:
    case 540:
    case 541:
    case 542:
    case 543:
    case 544:
    case 545:
    case 546:
    case 547:
    case 548:
    case 549:
    case 550:
    case 551:
    case 552:
    case 553:
    case 554:
    case 555:
    case 556:
    case 557:
    case 558:
    case 559:
    case 560:
    case 563:
        program = alternateProgram;
        break;
    default:
        program = defaultProgram;
        break;
    }
    if (mode == 592 || mode == 593)
    {
        vertex = specialVertex;
        pixel = specialPixel;
    }
    else
    {
        reinterpret_cast<::FUN_00c663d0 *>(&(vertex))->operator=((const ::FUN_00c663d0 &)(defaultVertex));
        reinterpret_cast<::FUN_00c663d0 *>(&(pixel))->operator=((const ::FUN_00c663d0 &)(defaultPixel));
    }
}
}  // namespace fnv_00b7af80

// Member function: looks up the texture stage for index a2 on the global renderer, assigns it the
// value computed by a sibling member called on this (keeps ecx live), then applies it.
struct ShaderStageSetter
{
    void FUN_00b7c290(intptr_t a1, int a2, int a3);
};
// Looks up the texture stage at index a2, stores the result of FUN_00c02f30(a1, a3) in its m_08 field, then calls ApplyPairToState(0) on it.
// @fnv 0x00b7c290
void ShaderStageSetter::FUN_00b7c290(intptr_t a1, int aiStageIndex, int a3)
{
    TexStageStub* elem = (TexStageStub*)((SlotGlobal*)DAT_0126f74c)->m_24[aiStageIndex];
    elem->m_08 = ((unsigned int)(::FUN_00c02f30((::FNV_Node *)(a1), a3)));
    reinterpret_cast<::E7DE90Owner *>((elem))->ApplyPairToState(0);
}

// NiTMap destructor: remove all entries, then the base map frees its hash table.

void __cdecl B7FBE0NiFree(void* pvMem);

class B7FBE0MapBase
{
  public:
    virtual ~B7FBE0MapBase()
    {
        reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
        B7FBE0NiFree(m_ppkHashTable);
    }
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00b7fbe0 : public B7FBE0MapBase
{
  public:
    virtual ~FUN_00b7fbe0();
};
// Calls FUN_00b7fbe0, then deallocates this via g_memoryManager if flags has bit 0 set, and returns this.
// @fnv 0x00b7fd00
ShaderResourceRelease* ShaderResourceRelease::FUN_00b7fd00(unsigned int flags)
{
    reinterpret_cast<::FUN_00b7fbe0 *>(this)->FUN_00b7fbe0::~FUN_00b7fbe0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

// @fnv 0x00b7fbe0
FUN_00b7fbe0::~FUN_00b7fbe0()
{
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
}

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        ::g_tlsBlock.memoryContext = m_iSaved;
    }
};

class NiMemObject
{
  public:
};

class FUN_00b60cb0_Clone : public NiMemObject
{  // clone type, ctor at 0x00b60cb0
  public:
    FUN_00b60cb0_Clone();
    char unk00[0x98];
};

class CloneSource
{
  public:
      // CopyMemberData
    FUN_00b60cb0_Clone* CloneObject(void* pvCloningProcess);
};

// Allocates a FUN_00b60cb0_Clone, runs CloneTo on it with pvCloningProcess, and returns the clone.
// @fnv 0x00b60e80
FUN_00b60cb0_Clone* CloneSource::CloneObject(void* pvCloningProcess)
{
    MemContextGuard kGuard(0x1c);
    FUN_00b60cb0_Clone* pkClone = new FUN_00b60cb0_Clone;
    reinterpret_cast<::B60A50Effect *>(this)->CloneTo((::B60A50Effect *)(pkClone), (*(::B60A50CloningProcess *)(pvCloningProcess)));
    return pkClone;
}

struct CopyObject;
struct RefCopy
{
    virtual void v0();
    virtual void DeleteThis();
    long refs;
};
struct CopyBase
{
};
struct CopyNode
{
    CopyNode* next;
    CopyNode* prev;
    void* data;
};
struct CopyList
{
    CopyNode* head;
    CopyNode* tail;
    unsigned count;
    void RemoveAll();
};
extern unsigned DAT_011c5f80;
extern unsigned DAT_011c5f84;
struct CopyObject : CopyBase
{
    unsigned f000;
    unsigned f004;
    unsigned f008;
    unsigned f00c;
    unsigned f010;
    unsigned f014;
    unsigned f018;
    unsigned f01c;
    unsigned f020;
    unsigned f024;
    unsigned f028;
    unsigned f02c;
    unsigned f030;
    unsigned f034;
    unsigned f038;
    unsigned f03c;
    unsigned f040;
    unsigned f044;
    unsigned f048;
    unsigned f04c;
    unsigned f050;
    unsigned f054;
    unsigned f058;
    unsigned f05c;
    unsigned char f060;
    unsigned char f061;
    unsigned char f062;
    unsigned char f063;
    unsigned f064;
    unsigned f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    unsigned char f07c;
    unsigned char f07d;
    unsigned char f07e;
    unsigned char f07f;
    unsigned char f080;
    unsigned char f081;
    unsigned char f082;
    unsigned char f083;
    unsigned f084;
    unsigned f088;
    unsigned f08c;
    unsigned f090;
    unsigned f094;
    unsigned f098;
    unsigned f09c;
    unsigned f0a0;
    unsigned f0a4;
    unsigned f0a8;
    unsigned f0ac;
    unsigned f0b0;
    unsigned f0b4;
    unsigned f0b8;
    unsigned f0bc;
    unsigned f0c0;
    unsigned f0c4;
    unsigned f0c8;
    unsigned f0cc;
    unsigned f0d0;
    unsigned f0d4;
    unsigned f0d8;
    unsigned f0dc;
    unsigned f0e0;
    unsigned f0e4;
    unsigned f0e8;
    unsigned f0ec;
    unsigned f0f0;
    unsigned f0f4;
    unsigned f0f8;
    unsigned f0fc;
    unsigned f100;
    unsigned f104;
    unsigned f108;
    unsigned f10c;
    unsigned f110;
    unsigned f114;
    float f118;
    float f11c;
    float f120;
    float f124;
    CopyList list;
    unsigned f134;
    RefCopy* f138;
    RefCopy* f13c;
    RefCopy* f140;
    RefCopy* f144;
    RefCopy* f148;
    void FUN_00b6a6c0(CopyObject* dst, std::intptr_t arg);
};
static __forceinline void AssignRef(RefCopy*& dst, RefCopy* const& src)
{
    RefCopy* old = dst;
    if (old != src)
    {
        if (old && !InterlockedDecrement(&old->refs))
            old->DeleteThis();
        dst = src;
        if (dst)
            InterlockedIncrement(&dst->refs);
    }
}
static __forceinline void AppendCopy(CopyList* dest, void* const& value, unsigned count)
{
    void* data = value;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(g_011c5f80))->FUN_0040fbf0((char *)(0));
    NiTAbstractPoolAllocator_unsigned_int::LinkedListEntry* raw = NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList;
    if (!raw)
    {
        ::FUN_0043a080();
        raw = NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList;
    }
    NiTAbstractPoolAllocator_unsigned_int::ms_pFreeList =
        (NiTAbstractPoolAllocator_unsigned_int::LinkedListEntry*)raw->m_pkNext;
    raw->m_uiSize = 0;
    raw->m_pkNext = 0;
    raw->m_pkPrev = 0;
    if (!(DAT_011c5f84 -= count))
        DAT_011c5f80 = 0;
    CopyNode* item = (CopyNode*)raw;
    item->data = data;
    item->next = 0;
    item->prev = dest->tail;
    if (dest->tail)
    {
        dest->tail->next = item;
        dest->count += count;
    }
    else
    {
        dest->head = item;
        dest->count += count;
    }
    dest->tail = item;
}
// Copies base fields and a fixed set of member values into dst, reassigns the reference-counted pointers, and deep-copies the list into dst->list.
// @fnv 0x00b6a6c0
void CopyObject::FUN_00b6a6c0(CopyObject* dst, std::intptr_t arg)
{
    ::FUN_00ba8b10((::BSSP_stub4 *)this, 0, (::BSSP_stub4 *)(dst), (::CloningProcess *)(arg));
    AssignRef(dst->f148, f148);
    dst->f061 = f061;
    dst->f062 = f062;
    dst->f063 = f063;
    dst->f064 = f064;
    dst->f068 = f068;
    dst->f06c = f06c;
    dst->f070 = f070;
    dst->f07d = f07d;
    dst->f07c = f07c;
    dst->f07f = f07f;
    dst->f080 = f080;
    dst->f081 = f081;
    dst->f088 = f088;
    dst->f08c = f08c;
    dst->f090 = f090;
    dst->f094 = f094;
    dst->f098 = f098;
    dst->f09c = f09c;
    dst->f0a0 = f0a0;
    dst->f0a4 = f0a4;
    dst->f0a8 = f0a8;
    dst->f0ac = f0ac;
    dst->f0b0 = f0b0;
    dst->f0b4 = f0b4;
    dst->f0b8 = f0b8;
    dst->f0bc = f0bc;
    dst->f0c0 = f0c0;
    dst->f0c4 = f0c4;
    dst->f0c8 = f0c8;
    dst->f0cc = f0cc;
    dst->f0d0 = f0d0;
    dst->f0d4 = f0d4;
    dst->f0d8 = f0d8;
    dst->f0dc = f0dc;
    dst->f0e0 = f0e0;
    dst->f0e4 = f0e4;
    dst->f0e8 = f0e8;
    dst->f0ec = f0ec;
    dst->f0f0 = f0f0;
    dst->f0f4 = f0f4;
    dst->f0f8 = f0f8;
    dst->f0fc = f0fc;
    dst->f100 = f100;
    dst->f104 = f104;
    dst->f108 = f108;
    dst->f10c = f10c;
    dst->f110 = f110;
    dst->f114 = f114;
    dst->f118 = f118;
    dst->f124 = f124;
    dst->f11c = f11c;
    dst->f120 = f120;
    dst->f074 = f074;
    dst->f078 = f078;
    dst->f082 = f082;
    AssignRef(dst->f13c, f13c);
    AssignRef(dst->f140, f140);
    AssignRef(dst->f138, f138);
    AssignRef(dst->f144, f144);
    dst->f084 = f084;
    dst->f083 = f083;
    CopyList* dest = &dst->list;
    reinterpret_cast<::NiTPointerListBaseRaw *>((dest))->FUN_004ed900();
    CopyNode* pos = list.head;
    while (pos)
    {
        void*& data = pos->data;
        pos = pos->next;
        if (data)
        {
            AppendCopy(dest, data, 1);
        }
    }
}

struct B6AE60Obj
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
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
    int unk144;
    int unk148;
    int unk14c;
    B6AE60Obj();
};
// Allocates and constructs a B6AE60Obj via its operator new and returns the new object.
// @fnv 0x00b6ae60
B6AE60Obj* __cdecl CreateB6AE60Obj()
{
    return new B6AE60Obj();
}

typedef void(* FUN_00b7c190_VFn)(void*, int, int, int);

// @fnv 0x00b7c190
void UpdateSlotFromGlobal(int index)
{
    SlotGlobal* global = (SlotGlobal*)DAT_0126f74c;
    SlotElem* element = global->m_24[index];
    int* source;

    if (DAT_011ad80c)
        source = &(*reinterpret_cast<int *>(&::DAT_011f953c));
    else
        source = &(*reinterpret_cast<int *>(&::DAT_011f9540));

    element->m_08 = *source;

    if (DAT_011f9425)
        reinterpret_cast<::E7DEF0TextureStage *>((7))->FUN_00e7def0({});

    void* object = DAT_011f4748->m_pkD3DDevice;
    void** vtable = *(void***)object;
    ((FUN_00b7c190_VFn)vtable[69])(object, index, 8, (*reinterpret_cast<int *>(&::fnv_004da670::DAT_011f9428)));
}

struct FogVector
{
    float x, y, z, w;
    FogVector(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct FogDevice
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual long SetVertexShaderConstantF(unsigned int, const float*, unsigned int);
};
struct FogRenderState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    FogDevice* device;
    void SetVertexConstants(unsigned int reg, const float* values, unsigned int count)
    {
        device->SetVertexShaderConstantF(reg, values, count);
    }
};
struct FogRenderOwner
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
    FogRenderState* state;
};
// @fnv 0x00b7c3a0
void UpdateFogShaderConstants()
{
    BSFogProperty* fog = ::FUN_00b55520(DAT_011f91c4);
    if (fog)
    {
        float fNearDepth = fog->nearDepth;
        float fFarDepth = fog->farDepth;
        float power = fog->density;
        if (fFarDepth == 0.0f && fNearDepth == 0.0f)
        {
            (*reinterpret_cast<FogVector (*)[2]>((void *)&::DAT_011FA280))[0] = FogVector(500000.0f, 0.0f, 0.0f, 0.0f);
            (*reinterpret_cast<FogVector (*)[2]>((void *)&::DAT_011FA280))[1] = (*reinterpret_cast<const ::FogVector *>(&::DAT_011a9bd0));
        }
        else
        {
            V3 color = fog->color;
            (*reinterpret_cast<FogVector (*)[2]>((void *)&::DAT_011FA280))[0] = FogVector(fFarDepth, fFarDepth - fNearDepth, power, 0.0f);
            (*reinterpret_cast<FogVector (*)[2]>((void *)&::DAT_011FA280))[1] = FogVector(color.x, color.y, color.z, 0.0f);
        }
    }
    FogRenderOwner* owner = reinterpret_cast<FogRenderOwner*>(DAT_0126f74c);
    owner->state->SetVertexConstants(14, &(*reinterpret_cast<FogVector (*)[2]>((void *)&::DAT_011FA280))[0].x, 2);
}

struct FnvB60150Thunk : FUN_00b6f460_class
{
    void FUN_00b60150(NiStream* stream);
};

struct FUN_00b60160_shell
{
    bool FUN_00b60160(::NiStream& kStream);
};

// @fnv 0x00b60160
bool FUN_00b60160_shell::FUN_00b60160(::NiStream& kStream)
{
    return reinterpret_cast<::FUN_00bc3770_shell *>(this)->FUN_00bc3770(kStream);
}

struct ZeroPtr08
{
    void* m_p;
    ZeroPtr08() : m_p(0)
    {}
};
class FUN_00b60b10 : public NiRefObject2
{
  public:
    FUN_00b60b10();
    virtual ~FUN_00b60b10();

    ZeroPtr08 m_i08;
    int unk0C;
    int unk10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
};
// Initializes the five integer members m_i14 through m_i24 to zero.
// @fnv 0x00b60b10
FUN_00b60b10::FUN_00b60b10()
{
    m_i14 = 0;
    m_i18 = 0;
    m_i1C = 0;
    m_i20 = 0;
    m_i24 = 0;
}


struct FUN_00b6a510_shell
{
    void FUN_00b6a510();
};

// @fnv 0x00b6a510
void FUN_00b6a510_shell::FUN_00b6a510()
{
    reinterpret_cast<::NiTPointerListBaseRaw *>(this)->FUN_004ed900();
}

void* __cdecl FUN_00aa13e0(unsigned int size);
struct FUN_00b6abb0
{
    FUN_00b6abb0();
    static void* operator new(std::size_t size, unsigned int requestedSize)
    {
        return FUN_00aa13e0(requestedSize);
    }
    unsigned int m_type;
};
struct EntityManagerB6
{
    FUN_00b6abb0* CreateObject(int context);
};
// @fnv 0x00b6ade0
FUN_00b6abb0* EntityManagerB6::CreateObject(int context)
{
    FUN_00b6abb0* object = new (0x150) FUN_00b6abb0();
    reinterpret_cast<::CopyObject *>(this)->FUN_00b6a6c0((::CopyObject *)(object), context);
    return object;
}


struct FUN_00b6b180_Fmt
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int unk10;
};

struct FUN_00b6b180_Tex
{
    int unk00;
    int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_00b6b180_Fmt* unk10;
};

struct FUN_00b6b180_Obj : NiObjectStub
{
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
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();
    virtual void v9c();
    virtual void va0();
    virtual FUN_00b6b180_Tex* GetBuffer();
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
    FUN_00b6b180_Tex* unk4c;
};


// @fnv 0x00b6b180
FUN_00b6b180_Tex* __cdecl FUN_00b6b180(FUN_00b6b180_Obj* apObj, FUN_00b6b180_Tex* apOther)
{
    if (!StubIsKindOf(&(*reinterpret_cast<::NiRTTI *>(&::g_012708e4)), apObj))
    {
        if (apOther)
        {
            unsigned int uiWidth = apOther->unk08;
            if (uiWidth >= apObj->GetWidth())
            {
                unsigned int uiHeight = apOther->unk0c;
                if (uiHeight >= apObj->GetHeight())
                {
                    unsigned int uiFormat = apOther->unk10 ? apOther->unk10->unk10 : 0;
                    FUN_00b6b180_Tex* pBuffer = apObj->GetBuffer();
                    unsigned int uiBufferFormat = pBuffer->unk10 ? pBuffer->unk10->unk10 : 0;
                    if (uiFormat == uiBufferFormat)
                        return apOther;
                }
            }
        }
        return ((::FUN_00b6b180_Tex *)(::ProcessArgWithObj((::FUN_00a9ff00_Arg *)(::FUN_00b6b180_Tex *)(apObj->GetBuffer()), (::FUN_00a9ff00_Obj *)((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508))))));
    }
    FUN_00b6b180_Tex* pTarget = apObj->unk4c;
    if (apOther && apOther->unk08 >= pTarget->unk08 && apOther->unk0c >= pTarget->unk0c)
        return apOther;
    return ((::FUN_00b6b180_Tex *)(::ProcessArgWithObj((::FUN_00a9ff00_Arg *)(pTarget), (::FUN_00a9ff00_Obj *)((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508))))));
}

struct FUN_00b6fd20_cls
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
    int FUN_00b6fd20();
};
// @fnv 0x00b6fd20
int FUN_00b6fd20_cls::FUN_00b6fd20()
{
    return unk60;
}


struct MemoryContextGuard
{
    int m_iSaved;
    MemoryContextGuard(int aiMemoryContext)
    {
        m_iSaved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = aiMemoryContext;
    }
    ~MemoryContextGuard()
    {
        ::g_tlsBlock.memoryContext = m_iSaved;
    }
};


struct StringOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short unk10;
    unsigned short m_usNumStrings;
    int unk14;
    const char** m_ppcStrings;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    unsigned int m_uiKeyA;
    unsigned int m_uiKeyB;

    ~StringOwner();
};

template <class T> inline void NiTPointerAllocator<T>::Deallocate(void* pointer)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(g_011c5f80))->FUN_0040fbf0((char *)(0));
    typename PoolAllocatorBase<T>::LinkedListEntry* pkDelNode =
        (typename PoolAllocatorBase<T>::LinkedListEntry*)pointer;
    pkDelNode->m_pUserData = 0;
    pkDelNode->m_pkNext = PoolAllocatorBase<T>::ms_pFreeList;
    PoolAllocatorBase<T>::ms_pFreeList = pkDelNode;
    if (--DAT_011c5f84 == 0)
        DAT_011c5f80 = 0;
}

template <class Allocator, class T> inline void NiTPointerListBase<Allocator, T>::DeleteItem(NiTListItem<T>* pkItem)
{
    pkItem->m_element = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>(&(this->m_kItemCount))->FUN_0045cee0(pkItem);
}

template <class Allocator, class T> inline T NiTPointerListBase<Allocator, T>::RemoveHead()
{
    NiTListItem<T>* pkNode = this->m_pkHead;
    this->m_pkHead = this->m_pkHead->m_pkNext;
    if (this->m_pkHead)
        this->m_pkHead->m_pkPrev = 0;
    else
        this->m_pkTail = 0;
    T element = pkNode->m_element;
    ::FUN_00e6e8a0((::LinkedListEntry *)this);
    this->m_kItemCount.m_uiCount--;
    return element;
}

template <class Allocator, class T> inline T NiTPointerListBase<Allocator, T>::RemovePos(void*& kPos)
{
    NiTListItem<T>* pkDelNode = (NiTListItem<T>*)kPos;
    if (pkDelNode == this->m_pkHead)
    {
        kPos = pkDelNode->m_pkNext;
        return RemoveHead();
    }
    if (pkDelNode == this->m_pkTail)
    {
        kPos = 0;
        return RemoveTail();
    }
    NiTListItem<T>* pkPrev = pkDelNode->m_pkPrev;
    NiTListItem<T>* pkNext = pkDelNode->m_pkNext;
    kPos = pkNext;
    if (pkPrev)
        pkPrev->m_pkNext = pkNext;
    if (pkNext)
        pkNext->m_pkPrev = pkPrev;
    T element = pkDelNode->m_element;
    ::FUN_00e6e8a0((::LinkedListEntry *)this);
    this->m_kItemCount.m_uiCount--;
    return element;
}

typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*> OwnerList;

struct OwnerListEx : OwnerList
{
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    char* GetNext(void*& kPos) const
    {
        char* const& element = ((NiTListItem<char*>*)kPos)->m_element;
        kPos = ((NiTListItem<char*>*)kPos)->m_pkNext;
        return element;
    }
};

class NiTMapBase
{
  public:
    bool RemoveAt(const char* key);
};

struct OwnerBucket
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    OwnerListEx m_kList;
    int unk2c;
    NiTMapBase m_kStrings;
};

struct OwnerMap
{
    int unk00;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;

    unsigned int GetCount() const
    {
        return m_uiCount;
    }
    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
};


// Finds and removes the StringOwner with matching m_uiKeyA and m_uiKeyB from the owner map, removing its strings from the bucket's string map.
// @fnv 0x00b61570
void FUN_00b61570(unsigned int a, unsigned int b)
{
    MemoryContextGuard kGuard(0x1c);
    void* kFirst = ((::OwnerMap *)(::fnv_00b61170::GetArrayHolder()))->GetFirstPos();
    void* kIter = kFirst;
    OwnerBucket* pkBucket = 0;
    if (((::OwnerMap *)(::fnv_00b61170::GetArrayHolder()))->GetCount() > 0 && kFirst)
    {
        do
        {
            unsigned int key;
            reinterpret_cast<::Tbl00b57f20 *>((((::OwnerMap *)(::fnv_00b61170::GetArrayHolder()))))->AdvanceToNextEntry((::Ent00b57f20 **)&(kIter), (int *)&(key), (int *)&(pkBucket));
            if (pkBucket)
            {
                void* kPos = pkBucket->m_kList.GetHeadPos();
                while (kPos)
                {
                    void* kCur = kPos;
                    StringOwner* pkOwner = (StringOwner*)pkBucket->m_kList.GetNext(kPos);
                    if (pkOwner && a == pkOwner->m_uiKeyA && b == pkOwner->m_uiKeyB)
                    {
                        int m_iScrollPosition = pkOwner->m_usNumStrings;
                        const char** ppcStrings = pkOwner->m_ppcStrings;
                        for (int i = 0; i < m_iScrollPosition; i++)
                            pkBucket->m_kStrings.RemoveAt(ppcStrings[i]);
                        pkBucket->m_kList.RemovePos(kCur);
                        delete pkOwner;
                    }
                }
            }
        } while (kIter);
    }
}

void* __cdecl FUN_00aa1070(unsigned int);
extern int DAT_010ade50;
struct B617FloatPart
{
    int first, unused04;
    float x, y, z, w, scale, unused1c;
    B617FloatPart()
    {
        float zero = 0.0f;
        x = zero;
        first = 0;
        w = z = y = zero;
        scale = 1.0f;
    }
};
struct B617IntPart
{
    int index20, index24, index28;
    B617IntPart()
    {
        index28 = 0;
        index20 = 0;
        index24 = 0;
    }
};
struct B617Head
{
    B617FloatPart f;
    B617IntPart i;
    ~B617Head();
};
struct B617Holder
{
    int index2c;
    int* vtable;
    int hashSize;
    void* hashTable;
    int count;
    B617Holder() : index2c(0)
    {}
    ~B617Holder();
};
struct FUN_00b617f0 : B617Head, B617Holder
{
    FUN_00b617f0();
};
// Constructor that sets hashSize to 0x65 and count to 0, allocates and zeroes a 0x194-byte hashTable via FUN_00aa1070, then sets the vtable to DAT_010ade50.
// @fnv 0x00b617f0
FUN_00b617f0::FUN_00b617f0()
{
    vtable = &DAT_010ade18;
    hashSize = 0x65;
    count = 0;
    hashTable = FUN_00aa1070(0x194);
    std::memset(hashTable, 0, hashSize * 4);
    vtable = &DAT_010ade50;
}

class NiCamera;

struct RendererSurfaceB6BA : public RendererSurface
{
};

namespace gfxB6BA {
extern RendererSurfaceB6BA* DAT_011f4748;
}

class ShaderAccB6BA
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2C();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3C();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4C();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5C();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6C();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7C();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8C(NiCamera* camera);
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9C();
    virtual void vfn_A0();
    virtual void vfn_A4();
    virtual void vfn_A8();
};


// If the surface DAT_011f4748 and camera are set, calls SetFromCamera, sets DAT_011f917c, then FUN_00b54b10(acc), acc->vfn_8C(camera) and acc->vfn_A8().
// @fnv 0x00b6ba20
void __cdecl FUN_00b6ba20(NiCamera* camera, ShaderAccB6BA* acc)
{
    if (gfxB6BA::DAT_011f4748 && camera)
    {
        reinterpret_cast<::CameraState4E9 *>((gfxB6BA::DAT_011f4748))->SetFromCamera((*(const ::Camera4E9 *)(camera)));
        DAT_011f917c = camera;
        ::FUN_00b54b10((::BSShaderAccumulator *)(acc));
        acc->vfn_8C(camera);
        acc->vfn_A8();
    }
}

class NiTextureB7A;

class NiPassB7A
{
  public:
    int unk00;
    int unk04;
    NiTextureB7A* m_texture;
};

struct NiPropertyB7A
{
    int unk00;
    unsigned short m_type;
};

struct NiMaterialB7A
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68;
    NiTextureB7A* m_texture;
    int m_stage;
};

class NiGeometryB7A
{
  public:
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
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void* GetWorldTransform();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8;
    NiMaterialB7A* m_iMaterialIndex;
};



class FUN_00b7ad00_Class
{
  public:
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
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void RestoreState();

    void FUN_00b7ad00(void* unused, NiGeometryB7A* geom, NiPropertyB7A* prop);
};

// Takes the DAT_011fdff8 entry for prop->m_type, sets its pass texture from geom's material or DAT_011f952c, applies the world transform, and calls RestoreState.
// @fnv 0x00b7ad00
void FUN_00b7ad00_Class::FUN_00b7ad00(void* unused, NiGeometryB7A* geom, NiPropertyB7A* prop)
{
    if (!prop)
        return;
    StageMgr* shader = (*reinterpret_cast<StageMgr * (*)[]>(&::fnv_00b7a730::DAT_011fdff8))[prop->m_type];
    NiMaterialB7A* material = geom->m_iMaterialIndex;
    if (!material)
        return;
    NiPassB7A* pass = reinterpret_cast<NiPassB7A*>(*shader->m_pElems);
    if (material->m_texture)
        pass->m_texture = material->m_texture;
    else
        pass->m_texture = (*reinterpret_cast<::NiTextureB7A * *>(&::DAT_011f952c));
    reinterpret_cast<::E7DE90Owner *>((pass))->ApplyPairToState((uintptr_t)(geom->GetWorldTransform()));
    ::FUN_00b97ed0(true, 0);
    FUN_00b97f20(4, material->m_stage, 0);
    RestoreState();
    DAT_0126f74c = reinterpret_cast<intptr_t>(shader);
}

// @fnv 0x00b606e0
unsigned char __cdecl FUN_00b606e0()
{
    return 1;
}

class RefObject_b60d
{
  public:
    virtual ~RefObject_b60d();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class Pointer_b60d
{
  public:
    ~Pointer_b60d()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    Pointer_b60d& operator=(T* pObject)
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

class TexturePool_b60d
{
  public:
};

struct PooledTexture_b60d
{
    void* m_pvHandle;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
    ~PooledTexture_b60d()
    {
        if (m_pvHandle)
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::TexturePool_b60d *>(&::g_memoryManager))))->FUN_00aa4060(m_pvHandle);
        m_pvHandle = 0;
        m_usSecondValue = 0;
        m_usFirstValue = 0;
    }
};

class ShaderBase_b60d
{
  public:
    virtual void v00();
    ~ShaderBase_b60d();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78;
};

class FUN_00b60d80 : public ShaderBase_b60d
{
  public:
    virtual void v00();
    ~FUN_00b60d80();
    int m_iTextureIndex;
    Pointer_b60d<RefObject_b60d> m_spTexture0;
    Pointer_b60d<RefObject_b60d> m_spTexture1;
    PooledTexture_b60d m_kPooled;
};

// Destructor that resets m_spTexture0 to null and m_iTextureIndex to zero.
// @fnv 0x00b60d80
FUN_00b60d80::~FUN_00b60d80()
{
    m_spTexture0 = 0;
    m_iTextureIndex = 0;
}

struct FUN_00b63320_Property
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_type;
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
    float m_vScale;
};

struct FUN_00b71360_water;

struct FUN_00b63320_Geometry
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
    virtual void vf37(RendererSurface* surface);

};

struct FUN_00b63320_Pass
{
    FUN_00b63320_Geometry* m_pSourceGeometry;
    int unk04;
    unsigned char unk08;
    unsigned char m_numLights;
    unsigned short unk0a;
    FUN_00b71360_water** m_ppLights;
};

void __cdecl ResetColorSlots(int);

// @fnv 0x00b63320
void __cdecl FUN_00b63320(FUN_00b63320_Pass* pass, unsigned int pixelShader)
{
    RendererSurface* surface = DAT_011f4748;
    DAT_011f91e4 = pixelShader;
    (*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0)) = (S_00b7c120_Global2*)pass;
    FUN_00b63320_Property* prop = ((::FUN_00b63320_Property *)(reinterpret_cast<::FUN_00a59d30_C *>((pass->m_pSourceGeometry))->FUN_00a59d30(3)));
    if (prop)
    {
        switch (prop->m_type)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12: {
            float scale = prop->m_vScale;
            if (DAT_011f94a6)
                ::Lighting30Shader::InvalidateShaderConstants();
            if ((pixelShader < 0x10 || pixelShader > 0x13) && pixelShader != 0x1c8 && pixelShader != 0x1ca &&
                pixelShader != 0x1c9 && pixelShader != 0x1cb)
                ResetColorSlots(0);
            for (unsigned char i = 0; i < pass->m_numLights; ++i)
                FUN_00b71360(i, pass->m_ppLights[i], scale);
            if (DAT_011f91a7)
                (*reinterpret_cast<::FogVector *>((void *)&::DAT_011FA0D0)) = (*reinterpret_cast<const ::FogVector *>(&::DAT_011a9bd0));
            break;
        }
        }
    }
    pass->m_pSourceGeometry->vf37(surface);
}

class BB63F90Shader;

struct BB63F90Pass
{

    int unk00;

    unsigned short m_usPassCount;
};

struct BB63F90PassArray
{

    int unk00;

    BB63F90Pass** m_ppkPasses;

    int unk08;

    int unk0C;

    unsigned int m_uiCount;
};

class BB63F90Renderer
{

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

    virtual void ShaderPassEntry(BB63F90Pass* pkPass, unsigned int ItemUpdateArray);
};

class BB63F90Accumulator
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

    BB63F90Renderer* m_apkRenderers[10];
    void* m_pvCamera;
    __forceinline void* Camera() const
    {
        return m_pvCamera;
    }
};

class BB63F90Geometry
{

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

    virtual BB63F90PassArray* CreateRenderPasses(int iArg, unsigned int uiFlags, unsigned int* puiCount, void* pvCamera,
                                                 BB63F90Accumulator* pkAccum, bool bFlag);
};

extern unsigned int g_uiB63F90PassFlags;


// Creates render passes from pkGeometry and submits each pass with a nonzero pass count to the selected renderer.
// @fnv 0x00b63f90
bool __cdecl AccumulateRenderPasses(BB63F90Accumulator* pkAccum, int iArg, int iUnused, BB63F90Geometry* pkGeometry)

{

    unsigned int ItemUpdateArray = 0;

    BB63F90PassArray* pkPasses =
        pkGeometry->CreateRenderPasses(iArg, *(unsigned int*)&(*reinterpret_cast<unsigned char *>(&::fnv_005bf7b0::DAT_011f91d8)), &ItemUpdateArray, pkAccum->Camera(), pkAccum, true);

    if (pkPasses && pkPasses->m_uiCount)
    {

        for (unsigned int i = 0; i < pkPasses->m_uiCount; i++)
        {

            BB63F90Pass* pkPass = pkPasses->m_ppkPasses[i];

            unsigned short usPassCount = pkPass->m_usPassCount;

            if (usPassCount)

                pkAccum->m_apkRenderers[::g_tlsBlock.renderThreadIndex]->ShaderPassEntry(pkPass, usPassCount);
        }
    }

    return true;
}

struct RSCmdOwnerParam
{
    unsigned int unk00;
    unsigned int unk04;
    float m_fValue;
};
struct RSCmdOwner
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    RSCmdOwnerParam* m_pParam;
};
struct RSCommand
{
    RSCmdOwner* m_pSharedOwner;
    unsigned short m_usId;
    unsigned char m_ucType;
};
struct RSCommandList
{
    void* m_pVtbl;
    RSCommand** m_ppItems;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_uiCount;
};
struct RSGroup
{
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
    virtual void Submit(RSCommand* pCmd, unsigned int usId);
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
    int m_iArrayLength;
    bool m_bModifierActive;
    int IsActive()
    {
        return (m_iArrayLength > 0 && m_bModifierActive) ? 1 : 0;
    }
};
struct RSDirty
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_uiCurrentValue;
};
struct RSPacket
{
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
    virtual RSCommandList* GetCommands(void* pRef, void* pGlobalForm, unsigned int* puiCount, void* pData, void* pSettings,
                                       int iFlag);
    virtual void vA4();
    virtual RSCommandList* GetExtraCommands();
    virtual RSCommand* GetCommand(void* pRef);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int m_uiValue1;
    unsigned int m_uiFlags2;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int m_uiStamp;
    RSDirty* m_pDirty;
    int GetBit(const unsigned int& ruiFlags, unsigned int uiMask)
    {
        return (ruiFlags & uiMask) > 0;
    }
    void SetBit(unsigned int& ruiFlags, unsigned int uiMask)
    {
        if (!(ruiFlags & uiMask))
            m_uiStamp = 0;
        ruiFlags |= uiMask;
    }
    void ClearBit(unsigned int& ruiFlags, unsigned int uiMask)
    {
        if (ruiFlags & uiMask)
            m_uiStamp = 0;
        ruiFlags &= ~uiMask;
    }
};
struct RSResponse
{
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
    int m_iType;
};
struct RSNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void Update();
};
struct RSEffect
{
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
    RSNode* m_pNode30;
    RSNode* m_pNode34;
};
struct RSSettings
{
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
    unsigned short unk38;
    bool m_bSubmitExtra;
    bool unk3B;
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
    bool m_bAlt;
    bool m_bExtra;
    bool unk86;
    bool unk87;
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
    bool m_bSkipShadow;
    bool unk165;
    bool m_bLodTest;
    bool unk167;
    int m_iLodLevel;
    bool m_bDecals;
    bool unk16D;
    bool unk16E;
    bool unk16F;
    unsigned int unk170;
    RSGroup* m_apGroups[6];
    unsigned int m_uiGroupCount;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    void* m_pData;
};
struct RSThreadData
{
    unsigned int unk00;
};
struct RSHelpers
{
};

// Dispatches RSCommands from pPacket to the current thread's RSGroup slot, applying LOD and settings filters, and handles extra commands when enabled.
// @fnv 0x00b64020
bool __cdecl ProcessCommands(RSSettings* pSettings, void* pRef, void* pUnused, RSPacket* pPacket, RSResponse* pResponse)
{
    if (pSettings->m_bSkipShadow && pResponse->m_iType == 13)
        return true;
    if (pSettings->m_bSubmitExtra)
    {
        RSCommand* pCmd = pPacket->GetCommand(pRef);
        if (pCmd)
        {
            if (pSettings->m_bExtra)
                reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 12, 0);
            else
                reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 11, 0);
        }
    }
    RSGroup* pGroup = pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex % pSettings->m_uiGroupCount];
    if (pGroup->IsActive() != pPacket->GetBit(pPacket->m_uiValue1, 0x200))
    {
        if (pGroup->IsActive())
            pPacket->SetBit(pPacket->m_uiValue1, 0x200);
        else
            pPacket->ClearBit(pPacket->m_uiValue1, 0x200);
        if (pPacket->m_pDirty)
            pPacket->m_pDirty->m_uiCurrentValue = 0;
    }
    unsigned int i;
    unsigned int ItemUpdateArray = 0;
    RSCommandList* pList =
        pPacket->GetCommands(pRef, *(void**)&(*reinterpret_cast<unsigned char *>(&::fnv_005bf7b0::DAT_011f91d8)), &ItemUpdateArray, pSettings->m_pData, pSettings, 1);
    if (pSettings->m_bExtra)
        pPacket->SetBit(pPacket->m_uiFlags2, 0x40);
    else
        pPacket->ClearBit(pPacket->m_uiFlags2, 0x40);
    if (pList && pList->m_uiCount)
    {
        for (i = 0; i < pList->m_uiCount; ++i)
        {
            RSCommand* pCmd = pList->m_ppItems[i];
            unsigned short usId = pCmd->m_usId;
            if (!usId)
                continue;
            switch (pCmd->m_ucType)
            {
            case 1:
                if (pSettings->m_bLodTest)
                {
                    RSCmdOwner* pOwner = pCmd->m_pSharedOwner;
                    RSCmdOwnerParam* pParam = pOwner->m_pParam ? pOwner->m_pParam : &(*reinterpret_cast<::RSCmdOwnerParam *>(&::g_defaultBound));
                    if (pParam->m_fValue < pSettings->m_iLodLevel)
                    {
                        reinterpret_cast<::B9B3D0Shader *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->SetupStage((::B9B3D0Pass *)(pCmd), 1);
                        break;
                    }
                }
                reinterpret_cast<::B9B3D0Shader *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->SetupStage((::B9B3D0Pass *)(pCmd), 0);
                break;
            case 2:
                reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 10, 0);
                break;
            case 3:
                reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 1, 0);
                break;
            case 4:
                if (pSettings->m_bDecals)
                    reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 2, 1);
                break;
            case 5:
                if (pSettings->m_bDecals)
                    reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 3, 0);
                break;
            case 6:
                reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 6, 0);
                break;
            case 7:
                reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 8, 0);
                break;
            case 8:
            case 9:
            case 11:
            case 12:
            case 13:
                break;
            case 10:
                reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 0, 0);
                break;
            case 14:
                reinterpret_cast<::FUN_00b9b3b0_class *>((pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]))->DispatchToSlot((uintptr_t)(pCmd), 9, 0);
                break;
            default:
                pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]->Submit(pCmd, usId);
                break;
            }
        }
        if (pSettings->m_bExtra && pSettings->m_bAlt)
        {
            pList = pPacket->GetExtraCommands();
            if (pList)
            {
                for (i = 0; i < pList->m_uiCount; ++i)
                {
                    RSCommand* pCmd = pList->m_ppItems[i];
                    if (pSettings->m_bAlt)
                    {
                        pSettings->m_apGroups[::g_tlsBlock.renderThreadIndex]->Submit(pCmd, 0);
                    }
                    else
                    {
                        RSEffect* pEffect = ((::RSEffect *)(::FUN_00b55560(1)));
                        ::FUN_00b7a870(pCmd->m_usId);
                        if (pEffect)
                        {
                            pEffect->m_pNode34->Update();
                            pEffect->m_pNode30->Update();
                        }
                        ::FUN_00b63320((::FUN_00b63320_Pass *)(pCmd), pCmd->m_usId);
                    }
                }
            }
        }
    }
    return true;
}

struct FUN_00b66700_class
{
    char m_auiShapeKeys[0xe0];
    float m_fE0;
    void SetClamped(float f);
};
inline float Max0(float v)
{
    return (v < ::_DAT_01012060) ? 0.0f : v;
}
inline float Min1(float v)
{
    return (v < 1.0f) ? v : 1.0f;
}
// Stores f clamped to the range [0, 1] into m_fE0.
// @fnv 0x00b66700
void FUN_00b66700_class::SetClamped(float afValue)
{
    m_fE0 = Min1(Max0(afValue));
}

struct StrHolder_b6c130
{
    char* m_handle;
    ~StrHolder_b6c130()
    {
        if (m_handle != DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_handle - 8));
    }
};
struct Pool_b6c130
{
};
static inline void DeleteHolder(StrHolder_b6c130* p)
{
    if (p)
    {
        p->~StrHolder_b6c130();
        reinterpret_cast<::FNV_MemoryManager *>((((Pool_b6c130*)&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(p);
    }
}
// Releases the two global string holders and nulls their pointers.
// @fnv 0x00b6c130
void __cdecl ReleaseStringHolders()
{
    DeleteHolder((*reinterpret_cast<::StrHolder_b6c130 * *>(&::DAT_011fa050)));
    DeleteHolder((*reinterpret_cast<::StrHolder_b6c130 * *>(&::DAT_011fa054)));
    (*reinterpret_cast<::StrHolder_b6c130 * *>(&::DAT_011fa050)) = 0;
    (*reinterpret_cast<::StrHolder_b6c130 * *>(&::DAT_011fa054)) = 0;
}

// Returns 1 if the high bit is set, otherwise returns the value if it is between 2 and 16, else 0.
// @fnv 0x00b6c200
int __cdecl FUN_00b6c200(int aiValue)
{
    if (aiValue & 0x80000000)
        return 1;
    switch (aiValue)
    {
    case 0:
    case 1:
        return 0;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    case 10:
        return 10;
    case 11:
        return 11;
    case 12:
        return 12;
    case 13:
        return 13;
    case 14:
        return 14;
    case 15:
        return 15;
    case 16:
        return 16;
    }
    return 0;
}

struct RefObj;

struct PoolRef
{
    RefObj* m_pObject;
    PoolRef(RefObj* p);
    ~PoolRef();
};

struct ListNode
{
    ListNode* m_pkNext;
    ListNode* m_pkPrev;
    RefObj* m_element;
};

struct RefList
{
    ListNode* m_pkHead;
    ListNode* m_pkTail;
    unsigned int m_uiCount;
    PoolRef RemoveHead();
};

struct RefSet
{
    int unk00;
    int unk04;
    int unk08;
    void Add(const PoolRef& p);
    __forceinline void Insert(RefObj* obj)
    {
        reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(this)->FUN_00c1b4a0((const ::fnv_00c1b4a0::NiRefObjectPtr &)((const ::PoolRef &)(obj)));
    }
};

struct Pool
{
    RefList m_list0;
    RefList m_list1;
    RefList m_list2;
    RefList m_list3;
    RefList m_list4;
    RefSet m_set0;
    RefSet m_set1;
    RefSet m_set2;
    RefSet m_set3;
    RefSet m_set4;

    RefObj* Create(unsigned int a, unsigned int p0, unsigned int p1, unsigned int flags, unsigned int p2,
                   unsigned int p3, unsigned int type, unsigned int p5, int zero, unsigned int e);
    __forceinline RefObj* CreateNew(uintptr_t a, uintptr_t type, unsigned int flags, unsigned int e)
    {
        unsigned int p5;
        struct Properties
        {
            unsigned int unused, format, flags, height, width;
        } props;
        ::GetRenderTargetDesc((::RenderConfigSurface *)this, a, (unsigned int *)(type), &props.width, &props.height, &props.format, &props.unused, &props.flags);
        return ((::RefObj *)(reinterpret_cast<::RenderTargetManager *>(this)->FUN_00b6d5e0((::NiRenderer *)(a), props.width, props.height, props.flags | flags, props.format, props.unused, type, p5, 0, e)));
    }
    RefObj* FUN_00b6e110(std::uintptr_t a, unsigned int type, unsigned int flags, unsigned int noReuse, unsigned int e);
};

// With noReuse 0, returns the head of the type's list (adding it to its set) or else CreateNew's result; with noReuse nonzero, returns 0.
// @fnv 0x00b6e110
RefObj* Pool::FUN_00b6e110(std::uintptr_t a, unsigned int type, unsigned int flags, unsigned int noReuse, unsigned int e)
{
    if (noReuse == 0)
    {
        switch (type)
        {
        case 43:
            if (m_list0.m_uiCount > 0)
            {
                RefObj* obj = m_list0.m_pkHead->m_element;
                m_set0.Insert(obj);
                m_list0.RemoveHead();
                return obj;
            }
            break;
        case 17:
            if (m_list1.m_uiCount > 0)
            {
                RefObj* obj = m_list1.m_pkHead->m_element;
                m_set1.Insert(obj);
                m_list1.RemoveHead();
                return obj;
            }
            break;
        case 9:
            if (m_list2.m_uiCount > 0)
            {
                RefObj* obj = m_list2.m_pkHead->m_element;
                m_set2.Insert(obj);
                m_list2.RemoveHead();
                return obj;
            }
            break;
        case 22:
            if (m_list3.m_uiCount > 0)
            {
                RefObj* obj = m_list3.m_pkHead->m_element;
                m_set3.Insert(obj);
                m_list3.RemoveHead();
                return obj;
            }
            break;
        case 19:
            if (m_list4.m_uiCount > 0)
            {
                RefObj* obj = m_list4.m_pkHead->m_element;
                m_set4.Insert(obj);
                m_list4.RemoveHead();
                return obj;
            }
            break;
        }
    }
    if (noReuse != 0)
        return 0;
    {
        return CreateNew(a, type, flags, e);
    }
}

struct PoolGuard
{
    int saved;
    PoolGuard()
    {
        saved = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 32;
    }
    ~PoolGuard()
    {
        ::g_tlsBlock.memoryContext = saved;
    }
};
struct PoolGroup
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void Set(int);
};
struct PoolTexture
{
    virtual void slot0();
    virtual void Delete();
    long refs;
};
struct PoolPtr
{
    PoolTexture* ptr;
    PoolPtr(const PoolPtr& other) : ptr(other.ptr)
    {
        if (ptr)
            InterlockedIncrement(&ptr->refs);
    }
    PoolPtr(PoolTexture* p) : ptr(p)
    {
        if (p)
            InterlockedIncrement(&p->refs);
    }
    __forceinline ~PoolPtr()
    {
        if (ptr)
        {
            PoolTexture* p = ptr;
            if (!InterlockedDecrement(&p->refs))
                p->Delete();
        }
    }
};
struct PoolList
{
    intptr_t head, tail;
    unsigned count;
    PoolPtr PopBack();
    __declspec(noinline) void AddTail(const PoolPtr& p)
    {
        if (p.ptr)
            head = (intptr_t)p.ptr;
    }
};
struct OutlinePtr
{
    PoolTexture* ptr;
    OutlinePtr(PoolTexture*);
    OutlinePtr(const OutlinePtr&);
    ~OutlinePtr();
};
struct AvailableNode
{
    AvailableNode* next;
    AvailableNode* prev;
    PoolTexture* element;
};
struct AvailableList
{
    AvailableNode* head;
    AvailableNode* tail;
    unsigned count;
    OutlinePtr PopFront();
};
struct PoolHolder
{
};
struct TexturePool
{
    AvailableList available;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    PoolHolder holder;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    PoolList active;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    void ResizeActivePool(intptr_t kind, unsigned count);
};
struct ShaderStageManager
{
    void FUN_00b7c0e0(NiD3DShader* shader, unsigned int i, unsigned int j);
};

// Sets the texture for a stage by index and applies the stage's texture pair to the shader state if the shader is not null.
// @fnv 0x00b7c0e0
void ShaderStageManager::FUN_00b7c0e0(NiD3DShader* shader, unsigned int i, unsigned int j)
{
    TexStageStub* stage = ((StageMgr*)DAT_0126f74c)->m_pElems[i];
    stage->m_08 = ((uintptr_t)(::GetTextureByIndex((char *)(shader), j)));
    if (shader != 0)
        reinterpret_cast<::E7DE90Owner *>((stage))->ApplyPairToState(shader->V56());
}

struct Vec3
{
    float x, y, z;
    Vec3 operator+(const Vec3& b) const
    {
        Vec3 r = {x + b.x, y + b.y, z + b.z};
        return r;
    }
    Vec3 operator*(float b) const
    {
        Vec3 r = *this;
        r.x *= b;
        r.y *= b;
        r.z *= b;
        return r;
    }
};
struct Vec4
{
    float x, y, z, w;
};
struct Matrix
{
    float m[4][4];
};

struct IDirect3DDevice9
{
    virtual void dummy0() = 0;
    virtual void dummy1() = 0;
    virtual void dummy2() = 0;
    virtual void dummy3() = 0;
    virtual void dummy4() = 0;
    virtual void dummy5() = 0;
    virtual void dummy6() = 0;
    virtual void dummy7() = 0;
    virtual void dummy8() = 0;
    virtual void dummy9() = 0;
    virtual void dummy10() = 0;
    virtual void dummy11() = 0;
    virtual void dummy12() = 0;
    virtual void dummy13() = 0;
    virtual void dummy14() = 0;
    virtual void dummy15() = 0;
    virtual void dummy16() = 0;
    virtual void dummy17() = 0;
    virtual void dummy18() = 0;
    virtual void dummy19() = 0;
    virtual void dummy20() = 0;
    virtual void dummy21() = 0;
    virtual void dummy22() = 0;
    virtual void dummy23() = 0;
    virtual void dummy24() = 0;
    virtual void dummy25() = 0;
    virtual void dummy26() = 0;
    virtual void dummy27() = 0;
    virtual void dummy28() = 0;
    virtual void dummy29() = 0;
    virtual void dummy30() = 0;
    virtual void dummy31() = 0;
    virtual void dummy32() = 0;
    virtual void dummy33() = 0;
    virtual void dummy34() = 0;
    virtual void dummy35() = 0;
    virtual void dummy36() = 0;
    virtual void dummy37() = 0;
    virtual void dummy38() = 0;
    virtual void dummy39() = 0;
    virtual void dummy40() = 0;
    virtual void dummy41() = 0;
    virtual void dummy42() = 0;
    virtual void dummy43() = 0;
    virtual void dummy44() = 0;
    virtual void dummy45() = 0;
    virtual void dummy46() = 0;
    virtual void dummy47() = 0;
    virtual void dummy48() = 0;
    virtual void dummy49() = 0;
    virtual void dummy50() = 0;
    virtual void dummy51() = 0;
    virtual void dummy52() = 0;
    virtual void dummy53() = 0;
    virtual void dummy54() = 0;
    virtual void dummy55() = 0;
    virtual void dummy56() = 0;
    virtual void dummy57() = 0;
    virtual void dummy58() = 0;
    virtual void dummy59() = 0;
    virtual void dummy60() = 0;
    virtual void dummy61() = 0;
    virtual void dummy62() = 0;
    virtual void dummy63() = 0;
    virtual void dummy64() = 0;
    virtual void dummy65() = 0;
    virtual void dummy66() = 0;
    virtual void dummy67() = 0;
    virtual void dummy68() = 0;
    virtual void dummy69() = 0;
    virtual void dummy70() = 0;
    virtual void dummy71() = 0;
    virtual void dummy72() = 0;
    virtual void dummy73() = 0;
    virtual void dummy74() = 0;
    virtual void dummy75() = 0;
    virtual void dummy76() = 0;
    virtual void dummy77() = 0;
    virtual void dummy78() = 0;
    virtual void dummy79() = 0;
    virtual void dummy80() = 0;
    virtual void dummy81() = 0;
    virtual void dummy82() = 0;
    virtual void dummy83() = 0;
    virtual void dummy84() = 0;
    virtual void dummy85() = 0;
    virtual void dummy86() = 0;
    virtual void dummy87() = 0;
    virtual void dummy88() = 0;
    virtual void dummy89() = 0;
    virtual void dummy90() = 0;
    virtual void dummy91() = 0;
    virtual void dummy92() = 0;
    virtual void dummy93() = 0;
    virtual long SetVertexShaderConstantF(unsigned int StartRegister, const float* pConstantData,
                                                    unsigned int Vector4fCount) = 0;
};

struct Light
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88;
    Vec3 position;
    int unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4;
    int unkb8, unkbc, unkc0;
    float dimmer;
    int unkc8, unkcc, unkd0;
    Vec3 diffuse;
    float radius;
};

struct Geometry
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    float alpha;
    float GetAlpha() const
    {
        return alpha;
    }
    int unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4;
    Light* light;
};

struct Collection
{
    int unk00, unk04;
    unsigned char unk08, count;
    unsigned short unk0a;
    Geometry** objects;
};

struct Camera
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    int unk1e0;
    Vec3 offset;
};

struct FeatureEntry
{
    int unk00, unk04;
    bool enabled;
    char unk09;
    short unk0a;
    int unk0c, unk10, unk14, unk18, unk1c;
    int count;
};

struct Item;
struct Manager
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    IDirect3DDevice9* device;
    void SetVertexShaderConstantF(unsigned int reg, const float* data, unsigned int count)
    {
        device->SetVertexShaderConstantF(reg, data, count);
    }
public:
    void FUN_00b6da10(::Item *);
};
// Adjusts the active texture pool to hold count+1 entries by popping surplus textures or allocating new ones from the available list or a new render target.
// @fnv 0x00b6ee70
void TexturePool::ResizeActivePool(intptr_t kind, unsigned count)
{
    PoolGuard guard;
    if (!unka4)
    {
        unsigned cur = active.count;
        unsigned wanted = count + 1;
        if (cur > wanted)
        {
            PoolList& list = active;
            unsigned remaining = cur - wanted;
            do
            {
                PoolPtr texture = list.PopBack();
                ((::PoolGroup *)(reinterpret_cast<::BSRenderedTexture *>((texture.ptr))->GetGroup()))->Set(0);
                reinterpret_cast<::Manager *>(this)->FUN_00b6da10((::Item *)(texture.ptr));
            } while (--remaining);
        }
        else if (cur < wanted)
        {
            PoolList& list = active;
            unsigned remaining = wanted - cur;
            do
            {
                PoolTexture* texture;
                if (available.count > 0)
                {
                    texture = available.head->element;
                    {
                        OutlinePtr key(texture);
                        reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(holder))->FUN_00c1b4a0((*(const ::fnv_00c1b4a0::NiRefObjectPtr *)(&key)));
                    }
                    available.PopFront();
                    if (0)
                    {
                        { OutlinePtr kNull(0); reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(holder))->FUN_00c1b4a0((*(const ::fnv_00c1b4a0::NiRefObjectPtr *)(&kNull))); }
                        { OutlinePtr kNull(0); reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(holder))->FUN_00c1b4a0((*(const ::fnv_00c1b4a0::NiRefObjectPtr *)(&kNull))); }
                        { OutlinePtr kNull(0); reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(holder))->FUN_00c1b4a0((*(const ::fnv_00c1b4a0::NiRefObjectPtr *)(&kNull))); }
                        { OutlinePtr kNull(0); reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(&(holder))->FUN_00c1b4a0((*(const ::fnv_00c1b4a0::NiRefObjectPtr *)(&kNull))); }
                    }
                }
                else
                {
                    int a, b, c, d, e, f;
                    ::GetRenderTargetDesc((::RenderConfigSurface *)(kind), 43, (unsigned int *)(&a), (unsigned int *)(&b), (unsigned int *)(&c), (unsigned int *)(&d), (unsigned int *)(&e), (unsigned int *)(&f));
                    texture = ((::PoolTexture *)(reinterpret_cast<::RenderTargetManager *>(this)->FUN_00b6d5e0((::NiRenderer *)(kind), a, b, e, c, d, 43, f, 0, 0)));
                }
                PoolPtr ptr(texture);
                PoolGroup* g = ((::PoolGroup *)(reinterpret_cast<::BSRenderedTexture *>((texture))->GetGroup()));
                int u = unka8;
                g->Set(u);
                list.AddTail(ptr);
            } while (--remaining);
        }
    }
}

struct Shader
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    Manager* manager;
};


// For lights 1 and up, uploads the transformed position and radius as vertex shader constants and stores the colour in _DAT_011FA0C0.
// @fnv 0x00b7c850
void UpdateLightShaderConstants(const Matrix* matrix, float scale)
{
    Collection* collection = (Collection*)(*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0));
    float count = (float)collection->count - 1.0f;
    Vec4 base;
    base.z = base.y = base.x = 9.0f;
    base.w = count;
    ((Shader*)DAT_0126f74c)->manager->SetVertexShaderConstantF(25, &base.x, 1);
    (*reinterpret_cast<::FeatureFlags * *>(&::DAT_011fec38))->active20 = collection->count - 1;
    if ((*reinterpret_cast<::FeatureEntry * *>(&::DAT_011fec4c))->enabled)
        (*reinterpret_cast<::FeatureEntry * *>(&::DAT_011fec4c))->count = collection->count - 1;
    float total = (float)collection->count - 1.0f;
    Vec4 color4;
    for (unsigned char i = 1; i < collection->count; ++i)
    {
        Geometry* geometry = collection->objects[i];
        Light* light = geometry->light;
        Vec3 pos = light->position;
        Vec3 offset = (*reinterpret_cast<::Camera * *>(&::DAT_011f91c8))->offset;
        pos.x += offset.x;
        pos.y += offset.y;
        pos.z += offset.z;
        Vec3 transformed;
        ::FUN_00ee6df8(&transformed, &pos, matrix);
        float radius = light->radius / scale;
        (*reinterpret_cast<Vec4 (*)[]>((void *)&::DAT_011fd9a8))[i].x = transformed.x;
        (*reinterpret_cast<Vec4 (*)[]>((void *)&::DAT_011fd9a8))[i].y = transformed.y;
        (*reinterpret_cast<Vec4 (*)[]>((void *)&::DAT_011fd9a8))[i].z = transformed.z;
        (*reinterpret_cast<Vec4 (*)[]>((void *)&::DAT_011fd9a8))[i].w = radius;
        ((Shader*)DAT_0126f74c)->manager->SetVertexShaderConstantF(i + 25, &(*reinterpret_cast<Vec4 (*)[]>((void *)&::DAT_011fd9a8))[i].x, 1);
        float intensity = light->dimmer;
        if (!DAT_011f941e && intensity > ::g_01012070)
            intensity = 1.0f;
        Vec3 color = light->diffuse * intensity * geometry->GetAlpha();
        color4.x = color.x;
        color4.y = color.y;
        color4.z = color.z;
        color4.w = total;
        (*reinterpret_cast<Vec4 (*)[]>((void *)&::DAT_011FA0C0))[i] = color4;
    }
}

namespace fnv_00b7cb00 {
struct LightVector
{
    float x, y, z;
    LightVector operator*(float b) const
    {
        LightVector r = *this;
        r.x *= b;
        r.y *= b;
        r.z *= b;
        return r;
    }
};
struct ShaderVector
{
    float x, y, z, w;
    ShaderVector()
    {}
    ShaderVector(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct ShaderLightData
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
    float dimmer;
    int unkc8;
    int unkcc;
    int unkd0;
    LightVector diffuse;
    float radius;
};
struct LightEntry
{
    float GetDimmer() const
    {
        return dimmer;
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
    float dimmer;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    ShaderLightData* light;
};
struct LightProperty
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
    struct AlphaSource* alpha;
};
struct AlphaVTable
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    float(* GetAlpha)(struct AlphaSource*);
};
struct AlphaSource
{
    AlphaVTable* vtable;
};
struct LightSet
{
    LightProperty* property;
    int unk04;
    unsigned char unk08, count;
    LightEntry** entries;
};
struct ShaderDevice
{
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0c() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1c() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2c() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3c() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4c() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5c() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void slot6c() = 0;
    virtual void slot70() = 0;
    virtual void slot74() = 0;
    virtual void slot78() = 0;
    virtual void slot7c() = 0;
    virtual void slot80() = 0;
    virtual void slot84() = 0;
    virtual void slot88() = 0;
    virtual void slot8c() = 0;
    virtual void slot90() = 0;
    virtual void slot94() = 0;
    virtual void slot98() = 0;
    virtual void slot9c() = 0;
    virtual void slota0() = 0;
    virtual void slota4() = 0;
    virtual void slota8() = 0;
    virtual void slotac() = 0;
    virtual void slotb0() = 0;
    virtual void slotb4() = 0;
    virtual void slotb8() = 0;
    virtual void slotbc() = 0;
    virtual void slotc0() = 0;
    virtual void slotc4() = 0;
    virtual void slotc8() = 0;
    virtual void slotcc() = 0;
    virtual void slotd0() = 0;
    virtual void slotd4() = 0;
    virtual void slotd8() = 0;
    virtual void slotdc() = 0;
    virtual void slote0() = 0;
    virtual void slote4() = 0;
    virtual void slote8() = 0;
    virtual void slotec() = 0;
    virtual void slotf0() = 0;
    virtual void slotf4() = 0;
    virtual void slotf8() = 0;
    virtual void slotfc() = 0;
    virtual void slot100() = 0;
    virtual void slot104() = 0;
    virtual void slot108() = 0;
    virtual void slot10c() = 0;
    virtual void slot110() = 0;
    virtual void slot114() = 0;
    virtual void slot118() = 0;
    virtual void slot11c() = 0;
    virtual void slot120() = 0;
    virtual void slot124() = 0;
    virtual void slot128() = 0;
    virtual void slot12c() = 0;
    virtual void slot130() = 0;
    virtual void slot134() = 0;
    virtual void slot138() = 0;
    virtual void slot13c() = 0;
    virtual void slot140() = 0;
    virtual void slot144() = 0;
    virtual void slot148() = 0;
    virtual void slot14c() = 0;
    virtual void slot150() = 0;
    virtual void slot154() = 0;
    virtual void slot158() = 0;
    virtual void slot15c() = 0;
    virtual void slot160() = 0;
    virtual void slot164() = 0;
    virtual void slot168() = 0;
    virtual void slot16c() = 0;
    virtual void slot170() = 0;
    virtual void slot174() = 0;
    virtual long SetVertexShaderConstantF(unsigned int, const float*, unsigned int) = 0;
};
struct DeviceHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    ShaderDevice* device;
    void SetVSConst(unsigned int r, const float* v, unsigned int n)
    {
        device->SetVertexShaderConstantF(r, v, n);
    }
};
struct ShaderManager
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
    DeviceHolder* holder;
};
struct ConstantEntry
{
    int unk00;
    int unk04;
    bool enabled;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int count;
};
struct SceneTranslation
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
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
    NiPoint3 translate;
};
struct ScaleSource
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
    float scale;
};
struct LightMatrix;
// Fills shader constant arrays with transformed light positions, radii, and colors from the active light set.
// @fnv 0x00b7cb00
void UpdateShaderLights(const LightMatrix* matrix, float radiusScale, ScaleSource* source)
{
    LightSet* lights = reinterpret_cast<LightSet*>((*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0)));
    float alpha = lights->property->alpha->vtable->GetAlpha(lights->property->alpha);
    ShaderVector ambient(99.0f, 99.0f, 99.0f, alpha);
    reinterpret_cast<ShaderManager*>(DAT_0126f74c)->holder->SetVSConst(25, &ambient.x, 1);
    int count = (int)lights->count - 1;
    if (count < 2)
        count = 2;
    (*reinterpret_cast<::FeatureFlags * *>(&::DAT_011fec38))->active20 = count;
    if ((*reinterpret_cast<::fnv_00b7cb00::ConstantEntry * *>(&::DAT_011fec4c))->enabled)
        (*reinterpret_cast<::fnv_00b7cb00::ConstantEntry * *>(&::DAT_011fec4c))->count = (int)lights->count - 1;
    float lightCount;
    float scale = source ? source->scale : 30.0f;
    lightCount = (float)lights->count - 1.0;
    ShaderVector result;
    for (unsigned char i = 1; i < lights->count; ++i)
    {
        LightEntry* entry = lights->entries[i];
        ShaderLightData* light = entry->light;
        NiPoint3 position = light->position;
        NiPoint3 offset = (*reinterpret_cast<::fnv_00b7cb00::SceneTranslation * *>(&::DAT_011f91c8))->translate;
        position.x += offset.x;
        position.y += offset.y;
        position.z += offset.z;
        NiPoint3 transformed;
        ::FUN_00ee6df8(&transformed, &position, matrix);
        float radius = light->radius / radiusScale;
        (*reinterpret_cast<fnv_00b7cb00::ShaderVector (*)[]>((void *)&::DAT_011fd9a8))[i].x = transformed.x;
        (*reinterpret_cast<fnv_00b7cb00::ShaderVector (*)[]>((void *)&::DAT_011fd9a8))[i].y = transformed.y;
        (*reinterpret_cast<fnv_00b7cb00::ShaderVector (*)[]>((void *)&::DAT_011fd9a8))[i].z = transformed.z;
        (*reinterpret_cast<fnv_00b7cb00::ShaderVector (*)[]>((void *)&::DAT_011fd9a8))[i].w = radius;
        reinterpret_cast<ShaderManager*>(DAT_0126f74c)->holder->SetVSConst(25 + i, &(*reinterpret_cast<fnv_00b7cb00::ShaderVector (*)[]>((void *)&::DAT_011fd9a8))[i].x, 1);
        float dimmer = light->dimmer;
        if (!::DAT_011f941e && 1.0 < dimmer)
            dimmer = 1.0f;
        LightVector color = light->diffuse * dimmer * entry->GetDimmer();
        result = ShaderVector(color.x, color.y, color.z, lightCount);
        (*reinterpret_cast<fnv_00b7cb00::ShaderVector (*)[]>((void *)&::DAT_011FA0C0))[i] = result;
        lightCount = scale;
    }
    if (lights->count == 2)
    {
        result = ShaderVector(0.0f, 0.0f, 0.0f, scale);
        (*reinterpret_cast<fnv_00b7cb00::ShaderVector (*)[]>((void *)&::DAT_011FA0C0))[2] = result;
    }
}
}  // namespace fnv_00b7cb00

// Sets two global values into specific slots of DAT_0126f74c based on which pass identifier is supplied.
// @fnv 0x00b7cfb0
void SetPassValues(unsigned int uiPass)
{
    switch (uiPass)
    {
    case 0xa0:
    case 0xa1:
    case 0xa2:
    case 0xa6:
    case 0xa7:
    case 0xa8:
    case 0xb6:
    case 0xb7:
    case 0xb8:
    case 0xbc:
    case 0xbd:
    case 0xbe:
    case 0x10a:
    case 0x10b:
    case 0x10c:
    case 0x110:
    case 0x111:
    case 0x112:
    case 0x115:
    case 0x121:
    case 0x122:
    case 0x126:
    case 0x127:
    case 0x128:
    case 0x12b:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[6]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[7]->unk08 = DAT_011f95e8;
        break;
    case 0xe0:
    case 0xe1:
    case 0xe5:
    case 0xe6:
    case 0xf2:
    case 0xf3:
    case 0xf7:
    case 0xf8:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[5]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[6]->unk08 = DAT_011f95e8;
        break;
    case 0x160:
    case 0x161:
    case 0x163:
    case 0x164:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[4]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[5]->unk08 = DAT_011f95e8;
        break;
    case 0x94:
    case 0x1f3:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[2]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[3]->unk08 = DAT_011f95e8;
        break;
    case 0x1f8:
    case 0x1fc:
    case 0x200:
    case 0x204:
    case 0x208:
    case 0x20c:
    case 0x210:
    case 0x214:
    case 0x218:
    case 0x21c:
    case 0x220:
    case 0x224:
    case 0x228:
    case 0x22c:
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[14]->unk08 = DAT_011f95e4;
        ((FUN_00b7c170_Container*)DAT_0126f74c)->unk24[15]->unk08 = DAT_011f95e8;
        break;
    }
}


// Returns an index derived from DAT_011f91c0 and the DAT_011f94a4, DAT_011f941e, DAT_011f941f flags.
// @fnv 0x00b7faf0
int __cdecl FUN_00b7faf0()
{
    int result = 0;
    switch (DAT_011f91c0)
    {
    case 1:
        result = 1;
        break;
    case 2:
        result = 2;
        break;
    case 3:
        result = 5;
        break;
    case 4:
        result = 8;
        break;
    case 5:
        if (DAT_011f94a4)
        {
            if (DAT_011f941e)
                result = DAT_011f941f ? 13 : 12;
            else
                result = 4;
        }
        else
        {
            if (DAT_011f941e)
                result = DAT_011f941f ? 11 : 10;
            else
                result = 3;
        }
        break;
    case 6:
        if (DAT_011f94a4)
        {
            if (DAT_011f941e)
                result = DAT_011f941f ? 17 : 16;
            else
                result = 7;
        }
        else
        {
            if (DAT_011f941e)
                result = DAT_011f941f ? 15 : 14;
            else
                result = 6;
        }
        break;
    case 7:
        if (DAT_011f941e)
            result = DAT_011f941f ? 19 : 18;
        else
            result = 9;
        break;
    }
    return result;
}

struct RendererCleanup
{
    void FUN_00b7fc50();
    RendererCleanup* FUN_00b7fd20(unsigned int flags);
};

// Calls FUN_00b7fc50, deallocates this via g_memoryManager when the low bit of flags is set, and returns this.
// @fnv 0x00b7fd20
RendererCleanup* RendererCleanup::FUN_00b7fd20(unsigned int flags)
{
    FUN_00b7fc50();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

// @fnv 0x00b7fd40
void __cdecl FUN_00b7fd40()
{
    extern void FUN_00b7fc50(void);
    FUN_00b7fc50();
}

struct SweepBucketNode
{
    SweepBucketNode* next;
    void* value;
};
void __cdecl FUN_00aa10f0(void*);
struct FUN_00b580a0_base
{
    virtual ~FUN_00b580a0_base();
};
struct FUN_00b60420 : FUN_00b580a0_base
{
    unsigned int numBuckets;
    SweepBucketNode** buckets;
    unsigned int unk0c;
    bool freeEntries;
    virtual ~FUN_00b60420();
};
// @fnv 0x00b60620
void* FUN_00b60420_class::FUN_00b60620(int flags)
{
    reinterpret_cast<::FUN_00b60420 *>(this)->FUN_00b60420::~FUN_00b60420();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
// Destroys the sweep bucket table, freeing each entry value via FUN_00aa10f0 when freeEntries is set.
// @fnv 0x00b60420
FUN_00b60420::~FUN_00b60420()
{
    if (freeEntries)
    {
        for (unsigned int i = 0; i < numBuckets; ++i)
        {
            SweepBucketNode* node = buckets[i];
            while (node)
            {
                SweepBucketNode* current = node;
                node = node->next;
                FUN_00aa10f0(current->value);
            }
        }
    }
}

#include <string.h>
struct MorphPoint3
{
    float x, y, z;
    MorphPoint3()
    {}
};
struct MorphGeomData
{
    int unk00, unk04;
    unsigned short vertexCount, unk0a, flags, unk0e;
    int unk10, unk14, unk18, unk1c;
    MorphPoint3* data20;
    MorphPoint3* vertices;
    void* data28;
    void* data2c;
    unsigned short GetNormalFlag() const
    {
        return flags & 1;
    }
    MorphPoint3* GetVertices() const
    {
        return vertices;
    }
};
struct ExtraGeometryData
{
    int unk00, unk04, unk08;
    void* data;
    int count;
};
struct ExtraDataOwner
{
    ExtraGeometryData* FUN_00a5bdd0(void*);
};
struct GeometryInput
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ExtraDataOwner* extraData;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4;
    MorphGeomData* geometry;
    ExtraGeometryData* FUN_00a5bdd0(void*);
};
struct AuxiliaryVertices
{
    int unk00, unk04, unk08;
    MorphPoint3* first;
    MorphPoint3* second;
    MorphPoint3* GetFirst() const
    {
        return first;
    }
    MorphPoint3* GetSecond() const
    {
        return second;
    }
};
struct FUN_00537bf0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    FUN_00537bf0(unsigned int);
};
struct ShaderGeometryOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int flags;
    int unk24, unk28, unk2c, unk30, unk34;
    volatile int cached;
    int unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    AuxiliaryVertices* auxiliary;
    void* extraVertices;
    unsigned int HasExtraData() const
    {
        return flags & 0x4000;
    }
    void SetExtra()
    {
        if (!HasExtraData())
            cached = 0;
        flags |= 0x4000;
    }
    void ClearExtra()
    {
        if (HasExtraData())
            cached = 0;
        flags &= ~0x4000;
    }
    FUN_00537bf0* BuildShaderGeometry(GeometryInput* input);
};
// Merges auxiliary vertex streams into geometry and allocates a vertex buffer from extra geometry data, returning it or null.
// @fnv 0x00b69be0
FUN_00537bf0* ShaderGeometryOwner::BuildShaderGeometry(GeometryInput* input)
{
    unsigned int count = input->geometry->vertexCount;
    MorphGeomData* geometry = input->geometry;
    if (auxiliary && auxiliary->first && auxiliary->second && !(geometry->flags & 0xf000))
    {
        MorphPoint3* vertices = new MorphPoint3[(unsigned short)count * 3];
        MorphPoint3* original = geometry->GetVertices();
        MorphPoint3* second = auxiliary->GetSecond();
        MorphPoint3* first = auxiliary->GetFirst();
        memcpy(vertices, original, (unsigned short)count * sizeof(MorphPoint3));
        memcpy(vertices + (unsigned short)count, second, (unsigned short)count * sizeof(MorphPoint3));
        memcpy(vertices + (unsigned short)count * 2, first, (unsigned short)count * sizeof(MorphPoint3));
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MemoryManagerB66 *>(&::g_memoryManager))))->FUN_00aa4060(original);
        unsigned short normalFlag = geometry->flags;
        void* streamC = geometry->data2c;
        void* stream8 = geometry->data28;
        MorphPoint3* stream0 = geometry->data20;
        normalFlag &= 1;
        reinterpret_cast<::NiGeometryData_shell *>((geometry))->FUN_00a66bb0(count, (::NiPoint3 *)(stream0), (::NiPoint3 *)(vertices), (::RgbaColor *)(stream8), (::NiPoint2 *)(streamC), normalFlag, 0x1000);
    }
    if (input->extraData)
    {
        ExtraGeometryData* extra = ((::ExtraGeometryData *)(reinterpret_cast<::NiAVObject *>((input->extraData))->GetExtraData((*(const ::NiFixedString *)((*reinterpret_cast<void * *>(&::g_00539f40)))))));
        if (extra)
        {
            void* pExtraVertices = extra->data;
            extraVertices = pExtraVertices;
            if (pExtraVertices)
                SetExtra();
            else
                ClearExtra();
            FUN_00537bf0* buffer = new FUN_00537bf0(count);
            reinterpret_cast<::FUN_00a72ca0_Class *>((buffer))->FUN_00a72ca0(2);
            reinterpret_cast<::fnv_00a730e0::FUN_00a730e0_cls *>((buffer))->FUN_00a730e0(2);
            reinterpret_cast<::A72BB0_DataStreamOwner *>((buffer))->FUN_00a72bb0(1, extraVertices, (unsigned short)count * 32, 0);
            reinterpret_cast<::FUN_00a726a0_cls *>((buffer))->FUN_00a726a0(0, 1, 0, (void *)(4), count, 16, 32);
            reinterpret_cast<::FUN_00a726a0_cls *>((buffer))->FUN_00a726a0(1, 1, 16, (void *)(4), count, 16, 32);
            extra->count = 0;
            extra->data = 0;
            reinterpret_cast<::FUN_00a5be90_shell *>((input))->DeleteExtraDataByKey((*(const ::NiFixedString *)((*reinterpret_cast<void * *>(&::g_00539f40)))));
            return buffer;
        }
    }
    return 0;
}

struct TailTarget
{
};

struct C_00b6f460
{
    void FUN_00b6f460(::NiStream& kStream);
};
// @fnv 0x00b66780
void FUN_00b6f460_class::LoadAndSetAdditional(NiStream* kStream)
{
    reinterpret_cast<::C_00b6f460 *>(this)->FUN_00b6f460(*(::NiStream *)kStream);
    NiObject* pkAdditional = (NiObject*)kStream->GetLoadedObject();
    NiObject* old = this->unka4;
    if (old != pkAdditional)
    {
        if (old)
        {
            if (InterlockedDecrement(&old->m_iRefCount) == 0)
                old->v1();
        }
        this->unka4 = pkAdditional;
        if (pkAdditional)
            InterlockedIncrement(&pkAdditional->m_iRefCount);
    }
}
// @fnv 0x00b60150
void FnvB60150Thunk::FUN_00b60150(NiStream* stream)
{
    reinterpret_cast<::C_00b6f460 *>(this)->FUN_00b6f460(*(::NiStream *)stream);
}

// @fnv 0x00b6f460
void C_00b6f460::FUN_00b6f460(::NiStream& kStream)
{
    reinterpret_cast<::FUN_00ba8a70_shell *>(this)->FUN_00ba8a70(kStream);
}

namespace fnv_00b6b6c0 {
extern "C" void _ReadWriteBarrier();



void __cdecl FUN_00b6b0b0()
{
    if (DAT_011fa020)
    {
        NiRefObject*& slot = DAT_011fa024[--DAT_011fa020];
        NiRefObject* object = slot;
        if (object)
        {
            object->DecRefCount();
            slot = 0;
        }
    }
}

// Drains the DAT_011fa024 reference list via FUN_00b6b0b0, then unlocks DAT_011f4748 if m_ucLocked is set.
// @fnv 0x00b6b6c0
void __cdecl ClearAndUnlockRenderer()
{
    while (DAT_011fa020)
        FUN_00b6b0b0();
    B6B330Renderer* renderer = reinterpret_cast<B6B330Renderer*>(DAT_011f4748);
    if (renderer->m_ucLocked)
        renderer->TryUnlock();
}
}  // namespace fnv_00b6b6c0

struct PixelData
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    int m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiRevID;
};

// For mipmap levels 1 and up, sets pixel bytes 0, 1 and/or 2 to 0xff according to the level (1 to 6), then increments m_uiRevID.
// @fnv 0x00b6b940
void __cdecl FUN_00b6b940(PixelData* pkData)
{
    if (pkData)
    {
        unsigned int uiLevels = pkData->m_uiMipmapLevels;
        for (unsigned int i = 1; i < uiLevels; i++)
        {
            unsigned int uiWidth = pkData->m_puiWidth[i];
            unsigned int uiHeight = pkData->m_puiHeight[i];
            unsigned char* pucPixels = pkData->m_pucPixels + pkData->m_puiOffsetInBytes[i];
            unsigned int stride = uiWidth * 4;
            for (unsigned int y = 0; y < uiHeight; y++)
            {
                unsigned int uiRowOffset = y * stride;
                for (unsigned int x = 0; x < uiWidth; x++)
                {
                    switch (i - 1)
                    {
                    case 0:
                        pucPixels[uiRowOffset + 0] = 0xff;
                        break;
                    case 1:
                        pucPixels[uiRowOffset + 1] = 0xff;
                        break;
                    case 2:
                        pucPixels[uiRowOffset + 2] = 0xff;
                        break;
                    case 3:
                        pucPixels[uiRowOffset + 1] = 0xff;
                        pucPixels[uiRowOffset + 0] = 0xff;
                        break;
                    case 4:
                        pucPixels[uiRowOffset + 1] = 0xff;
                        pucPixels[uiRowOffset + 2] = 0xff;
                        break;
                    case 5:
                        pucPixels[uiRowOffset + 2] = 0xff;
                        pucPixels[uiRowOffset + 0] = 0xff;
                        break;
                    }
                    uiRowOffset += 4;
                }
            }
        }
        pkData->m_uiRevID++;
    }
}

struct Surface051
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
};
struct Target051
{
    virtual void Slot0();
    virtual void DeleteThis();
    long refs;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    Surface051* surface;
    int unk28;
    int kind;
    NiPointer<Target051> texture;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
__forceinline Target051* TextureOf(Target051* p)
{
    NiPointer<Target051> kNull;
    return *(p ? &p->texture : &kNull);
}
struct FencePtr
{
    Target051* value;
    FencePtr(Target051* p) : value(p)
    {
        if (value)
            value->IncRefCount();
    }
    __forceinline ~FencePtr()
    {
        if (value)
            value->DecRefCount();
    }
};
struct RefPtr_b9e7c0
{
    Target051* value;
    __forceinline ~RefPtr_b9e7c0()
    {
        if (value)
            value->DecRefCount();
    }
};
struct Node051
{
    Node051* next;
    Node051* prev;
    Target051* object;
};
struct Alloc051
{
    unsigned int count;
    Node051* FUN_0043a010();
};
struct FUN_00b9e7c0_list
{
    Node051* head;
    Node051* tail;
    union
    {
        unsigned int count;
        Alloc051 allocator;
    };
    __forceinline unsigned int Count() const
    {
        return count;
    }
    RefPtr_b9e7c0 PopFront();
};
struct FUN_00c1b4a0_holder : FUN_00b9e7c0_list
{
    __declspec(noinline) void FUN_00c1b4a0(FencePtr* p);
    __forceinline void Insert(Target051* obj)
    {
        FencePtr kFence(obj);
        reinterpret_cast<::fnv_00c1b4a0::RefObjectList *>(this)->FUN_00c1b4a0((*(const ::fnv_00c1b4a0::NiRefObjectPtr *)(&kFence)));
    }
};
void FUN_00c1b4a0_holder::FUN_00c1b4a0(FencePtr* p)
{
    Node051* node = allocator.FUN_0043a010();
    if (node->object != p->value)
    {
        if (node->object)
            node->object->DecRefCount();
        node->object = p->value;
        if (node->object)
            node->object->IncRefCount();
    }
    node->prev = 0;
    node->next = head;
    if (head)
        head->prev = node;
    else
        tail = node;
    head = node;
    ++count;
}
struct ImageSpaceManager
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
    Target051* rendered;
};
struct Setup051
{
    union
    {
        struct
        {
            int unk00, unk04, unk08;
        };
        FUN_00c1b4a0_holder first;
    };
    FUN_00c1b4a0_holder active0, active1, active2, active3;
    FUN_00c1b4a0_holder spare;
    FUN_00c1b4a0_holder inactive0, inactive1, inactive2, inactive3;
    __forceinline Target051* Create(NiRenderer_b6d170* r, int kind)
    {
        unsigned int width, height, format, unused, flags, samples;
        ::GetRenderTargetDesc((::RenderConfigSurface *)(r), kind, &width, &height, &format, &unused, &flags, &samples);
        return ((::Target051 *)(reinterpret_cast<::RenderTargetManager *>(this)->FUN_00b6d5e0((::NiRenderer *)(r), width, height, flags, format, unused, kind, samples, 0, 0)));
    }
    __forceinline Target051* Acquire(NiRenderer_b6d170* r, int kind, int flags = 0, int noReuse = 0, int e = 0)
    {
        if (noReuse == 0)
        {
            switch (kind)
            {
            case 43:
                if (unk08)
                {
                    Target051* p = first.head->object;
                    spare.Insert(p);
                    first.PopFront();
                    return p;
                }
                break;
            case 17:
                if (active0.Count() > 0)
                {
                    Target051* p = active0.head->object;
                    inactive0.Insert(p);
                    active0.PopFront();
                    return p;
                }
                break;
            case 9:
                if (active1.Count() > 0)
                {
                    Target051* p = active1.head->object;
                    inactive1.Insert(p);
                    active1.PopFront();
                    return p;
                }
                break;
            case 22:
                if (active2.Count() > 0)
                {
                    Target051* p = active2.head->object;
                    inactive2.Insert(p);
                    active2.PopFront();
                    return p;
                }
                break;
            case 19:
                if (active3.Count() > 0)
                {
                    Target051* p = active3.head->object;
                    inactive3.Insert(p);
                    active3.PopFront();
                    return p;
                }
                break;
            }
        }
        if (noReuse != 0)
            return 0;
        return Create(r, kind);
    }
    __forceinline Target051* GetTexture(NiRenderer_b6d170* r, int kind)
    {
        if (kind == -1)
            return TextureOf(DAT_011f91ac->rendered);
        NiPointer<Target051> held = Acquire(r, kind);
        return TextureOf(held);
    }
    void FUN_00b6e450(NiRenderer_b6d170* renderer);
};
// Acquires render targets and calls FUN_00b6da10 on them, then adds acquired kinds 17, 9, 22 and 19 to the active lists and calls Slot37 on their textures.
// @fnv 0x00b6e450
void Setup051::FUN_00b6e450(NiRenderer_b6d170* renderer)
{
    Target051* targets[50];
    int count = 0;
    {
        if (DAT_011f941e)
        {
            targets[0] = ((::Target051 *)(reinterpret_cast<::RenderTargetManager *>(this)->FUN_00b6d5e0((::NiRenderer *)((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508))), 1, 1, 36, 0x71, 0, -1, 0, 0, 0)));
            targets[1] = ((::Target051 *)(reinterpret_cast<::RenderTargetManager *>(this)->FUN_00b6d5e0((::NiRenderer *)((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508))), 1, 1, 36, 0x71, 0, -1, 0, 0, 0)));
            targets[2] = ((::Target051 *)(reinterpret_cast<::RenderTargetManager *>(this)->FUN_00b6d5e0((::NiRenderer *)((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508))), 1, 1, 36, 0x71, 0, -1, 0, 0, 0)));
            targets[3] = ((::Target051 *)(reinterpret_cast<::RenderTargetManager *>(this)->FUN_00b6d5e0((::NiRenderer *)((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508))), 4, 4, 38, 0x71, 0, -1, 0, 0, 0)));
            targets[4] = ((::Target051 *)(reinterpret_cast<::RenderTargetManager *>(this)->FUN_00b6d5e0((::NiRenderer *)((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508))), 16, 16, 38, 0x71, 0, -1, 0, 0, 0)));
            targets[5] = ((::Target051 *)(reinterpret_cast<::RenderTargetManager *>(this)->FUN_00b6d5e0((::NiRenderer *)((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508))), 64, 64, 38, 0x71, 0, -1, 0, 0, 0)));
            targets[6] = Acquire((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508)), 2);
            targets[7] = Acquire((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508)), 0);
            targets[8] = Acquire((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508)), 4);
            if (DAT_011f941f && DAT_011f9420)
            {
                targets[9] = Acquire((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508)), 1);
            }
            else
                targets[9] = 0;
            count = 10;
        }
        targets[count++] = Acquire((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508)), 3);
        targets[count++] = Acquire((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508)), 6);
        targets[count++] = Acquire((*reinterpret_cast<::NiRenderer_b6d170 * *>(&::DAT_011f9508)), 6);
        for (int i = 0; i < count; ++i)
            if (targets[i])
                reinterpret_cast<::Manager *>(this)->FUN_00b6da10((::Item *)(targets[i]));
    }
    GetTexture(renderer, -1)->surface->Slot37();
    Target051* target;
    target = Acquire(renderer, 17);
    if (target)
    {
        active0.Insert(target);
        target->kind = 17;
        TextureOf(target)->surface->Slot37();
    }
    target = Acquire(renderer, 9);
    if (target)
    {
        active1.Insert(target);
        target->kind = 9;
        TextureOf(target)->surface->Slot37();
    }
    target = Acquire(renderer, 22);
    if (target)
    {
        active2.Insert(target);
        target->kind = 22;
        TextureOf(target)->surface->Slot37();
    }
    target = Acquire(renderer, 19);
    if (target)
    {
        active3.Insert(target);
        target->kind = 19;
        TextureOf(target)->surface->Slot37();
    }
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(&m_uiRefCount);
}
typedef NiRefObject B61Ref;
struct B61Point3
{
    float x, y, z;
};
struct B61Bound
{
    float x, y, z, r;
};
struct B61Alloc
{
};
struct B61Vec3 : B61Alloc
{
    float x, y, z;
};
struct B61UV : B61Alloc
{
    float u, v;
};
struct B61Float : B61Alloc
{
    float f;
};
struct B61Index : B61Alloc
{
    unsigned short us;
};
struct B61Color : B61Alloc
{
    float r, g, b, a;
    B61Color();
};
class B61Data : public B61Ref
{
  public:
    unsigned short m_usVertices;
    unsigned short m_usGeometryFlags;
    int unk0c;
    B61Bound m_kBound;
    B61Vec3* m_pkVertex;
    B61Vec3* m_pkNormal;
    B61Color* m_pkColor;
    B61UV* m_pkTexture;
    int unk30, unk34, unk38, unk3c, unk40;
    unsigned int m_uiTriListLength;
    unsigned short* m_pusStripLengths;
};
class B61Property : public B61Ref
{
  public:
    int unk08, unk0c, unk10, unk14;
    unsigned short m_usFlags;
    unsigned char m_ucTestRef;
    unsigned char unk1b;
};
class B61TexProp : public B61Property
{
  public:
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
    virtual B61Ref* GetGeometryShaderObject();
    int m_iType;
    int IsShaderType() const
    {
        int iType = m_iType;
        int b = (iType == 4);
        return b;
    }
};
class B61PropBase
{
  public:
    void* m_pvVtbl;
    long m_lRefCount;
    int unk08, unk0c, unk10, unk14;
    unsigned short m_usFlags;
    unsigned char m_ucTestRef;
    unsigned char unk1b;
    B61PropBase();
};
class B61AlphaProperty : public B61PropBase
{
  public:
    B61AlphaProperty()
    {
        m_pvVtbl = vftable_NiAlphaProperty;
        m_usFlags = 0xec;
        m_ucTestRef = 0;
    }
};
class B61AVObject : public B61Ref
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    virtual B61AVObject* GetAsNode();
    virtual void v04();
    virtual void v05();
    virtual B61AVObject* GetAsGeometry();
    virtual void v07();
    virtual int IsStrips();
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    int unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    B61AVObject** m_ppkChildren;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    int unka8, unkac, unkb0, unkb4;
    NiPointer<B61Data> m_pUserData;
};
inline bool B61IsKindOf(const NiRTTI* pkRTTI, B61AVObject* pkObj)
{
    if (!pkObj)
        return false;
    const NiRTTI* pkType = pkObj->GetRTTI();
    while (pkType)
    {
        if (pkType == pkRTTI)
            return true;
        pkType = pkType->m_pBaseRTTI;
    }
    return false;
}
class B61TriShapeData : public B61Ref
{
  public:
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
    B61TriShapeData(unsigned short usVertices, B61Vec3* pkVertex, B61Vec3* pkNormal, B61Color* pkColor,
                    B61UV* pkTexture, unsigned short usNumTextureSets, int eNBTMethod, unsigned short usTriangles,
                    B61Index* pusTriList, unsigned short usActive, unsigned short usActiveTris);
};
class B61TriStripsData : public B61Ref
{
  public:
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
    B61TriStripsData(unsigned short uiVertices, B61Vec3* pkVertex, B61Vec3* pkNormal, B61Color* pkColor,
                     B61UV* pkTexture, unsigned short uiNumTextureSets, int eNBTMethod, unsigned short uiTriangles,
                     unsigned short uiStrips, unsigned short* pusStripLengths, B61Index* pusStripLists,
                     unsigned short usActive, unsigned short usActiveTris);
};
class B61Loaded : public FnvB60280Ref
{
  public:
    int m_iFadeIndex;
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
    B61AVObject** m_ppkTop;
    unsigned int m_uiTopMax;
    unsigned int m_uiTopSize;
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
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    void IncRefCount()
    {
        DAT_00fdf1c0((void*)&m_ref);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_ref) == 0)
            delete this;
    }
    B61Loaded(const char* pcName);
    NiPointer<B61AVObject> FUN_00b60750()
    {
        return NiPointer<B61AVObject>(m_uiTopSize ? m_ppkTop[0] : 0);
    }
};
class B61Holder
{
  public:
    B61Loaded* m_pkLoaded;
    void FUN_00b60280(B61Loaded* pkNew);
    __forceinline void Clear()
    {
        if (m_pkLoaded)
        {
            m_pkLoaded->DecRefCount();
            m_pkLoaded = 0;
        }
    }
};
class B61Entry : public B61Ref
{
  public:
    NiPointer<B61Ref> m_spTransformData;
    B61Float* m_pkNumbers;
    int m_iWidth;
    NiPointer<B61Ref> m_pGeometryShader;
    NiPointer<B61Property> m_spAlpha;
    NiPointer<B61Property> m_spAlpha2;
    NiPointer<B61Property> m_spExtra;
    NiPointer<B61Loaded> m_spLoaded;
    float m_fBoundRadius;
    int m_iCopies;
    unsigned char m_ucStrips;
    unsigned char m_ucKind;
    unsigned char m_ucPending;
    unsigned short m_usGroup;
    B61Entry();
};
struct B61MapItem
{
    B61MapItem* m_pkNext;
    const char* m_key;
    NiPointer<B61Entry> m_val;
};
class B61Map
{
  public:
    virtual ~B61Map();
    virtual unsigned int KeyToHashIndex(const char* pcKey) const;
    virtual bool IsKeysEqual(const char* pcKey1, const char* pcKey2) const;
    unsigned int m_uiHashSize;
    B61MapItem** m_ppkHashTable;
    unsigned int m_uiCount;
    bool FUN_00e92760(const char* pcKey, NiPointer<B61Entry>& spVal) const
    {
        unsigned int uiIndex = KeyToHashIndex(pcKey);
        for (B61MapItem* pkItem = m_ppkHashTable[uiIndex]; pkItem; pkItem = pkItem->m_pkNext)
        {
            if (IsKeysEqual(pcKey, pkItem->m_key))
            {
                spVal = pkItem->m_val;
                return true;
            }
        }
        return false;
    }
    void FUN_00b61010(const char* pcName, NiPointer<B61Entry> spEntry);
};
struct B61IOManager
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
    virtual void QueueTask(B61Loaded* pkTask);
};
extern unsigned char DAT_011ad86c;
extern void(__cdecl* DAT_011f91e8)(const char*);
class B61Stream
{
  public:
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
    void* m_pvTopVtbl;
    B61AVObject** m_ppkTop;
    unsigned int m_uiTopMax;
    unsigned int m_uiTopSize;
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
    int unk5c4;
    int unk5c8;
    B61Stream();
    virtual ~B61Stream();
};

template <class T> __forceinline void B61Set(NiPointer<T>& sp, T* p)
{
    if (sp.m_pObject != p)
    {
        if (sp.m_pObject)
            sp.m_pObject->DecRefCount();
        sp.m_pObject = p;
        if (p)
            p->IncRefCount();
    }
}
inline void B61Notify(const char* pcName)
{
    if (DAT_011f91e8)
        DAT_011f91e8(pcName);
}
__forceinline int B61Promote(const unsigned short& a)
{
    return a;
}
// Loads or creates a B61Entry for the given particle name, building duplicated vertex/index data and shader properties, then returns the entry.
// @fnv 0x00b61980
B61Entry* __cdecl FUN_00b61980(const char** ppcName)
{
    unsigned short usVerts;
    (void)usVerts;
    MemContextGuard kGuard(0x1c);
    if (::DAT_011f91c0 == 0)
        return 0;
    B61AVObject* pkGeom = 0;
    if (!*ppcName)
        return 0;
    NiPointer<B61Entry> spEntry;
    B61Entry* pkNew;
    if (!((::B61Map *)(::FUN_00b61890()))->FUN_00e92760(*ppcName, spEntry))
    {
        spEntry = new B61Entry;
        pkNew = spEntry;
        pkNew->m_ucPending = 1;
        reinterpret_cast<::FnvB60280Owner *>((void *)&(const ::NiPointer< ::B61Loaded> &)(pkNew->m_spLoaded))->FUN_00b60280((::FnvB60280Ref *)(::B61Loaded *)(0));
        ((::B61Map *)(::FUN_00b61890()))->FUN_00b61010(*ppcName, pkNew);
        if (DAT_011ad86c)
        {
            reinterpret_cast<::FnvB60280Owner *>((void *)&(const ::NiPointer< ::B61Loaded> &)(pkNew->m_spLoaded))->FUN_00b60280((::FnvB60280Ref *)(::B61Loaded *)((new B61Loaded(*ppcName))));
            (*reinterpret_cast<::B61IOManager * *>(&::DAT_01202d98))->QueueTask(pkNew->m_spLoaded);
            return 0;
        }
    }
    else
        pkNew = spEntry;
    if (pkNew->m_ucPending)
    {
        NiPointer<B61AVObject> m_pRootNode;
        if (DAT_011ad86c && !spEntry->m_spLoaded)
        {
            reinterpret_cast<::FnvB60280Owner *>((void *)&(const ::NiPointer< ::B61Loaded> &)(spEntry->m_spLoaded))->FUN_00b60280((::FnvB60280Ref *)(::B61Loaded *)((new B61Loaded(*ppcName))));
            (*reinterpret_cast<::B61IOManager * *>(&::DAT_01202d98))->QueueTask(spEntry->m_spLoaded);
            return 0;
        }
        if (spEntry->m_spLoaded)
        {
            if (spEntry->m_spLoaded->m_iFadeIndex >= 4)
            {
                NiPointer< ::B61AVObject> loaded;
                reinterpret_cast<::FUN_00c663d0 *>((void *)&(const ::NiPointer< ::B61AVObject> &)(m_pRootNode))->operator=((const ::FUN_00c663d0 &)((const ::NiPointer< ::B61AVObject> &)((*(::NiPointer< ::B61AVObject> *)(reinterpret_cast<::FUN_00b60750_owner *>(((spEntry->m_spLoaded).operator->()))->FUN_00b60750((void *)(&loaded)))))));
                reinterpret_cast<::FnvB60280Owner *>((void *)&(const ::NiPointer< ::B61Loaded> &)(spEntry->m_spLoaded))->FUN_00b60280((::FnvB60280Ref *)(::B61Loaded *)((0)));
            }
        }
        else
        {
            char acPath[0x104];
            BuildAssetPath(*ppcName, acPath, 0x104);
            B61Stream kStream;
            reinterpret_cast<::FUN_00c3a8a0_cls *>(&(kStream))->FUN_00c3a8a0((uintptr_t)(acPath), false);
            if (kStream.m_uiTopSize)
            {
                B61AVObject* root = kStream.m_ppkTop[0];
                m_pRootNode = root;
            }
        }
        if (m_pRootNode)
        {
            spEntry->m_ucPending = 0;
            B61AVObject* kIter = ((::B61AVObject *)(reinterpret_cast<::NiObject *>(((m_pRootNode).operator->()))->DynamicCast(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4280)))))->GetAsNode();
            do
            {
                if (!kIter)
                    break;
                for (unsigned int i = 0; i < kIter->m_usSize; i++)
                {
                    B61AVObject* pkChild = kIter->m_ppkChildren[i];
                    if (pkChild)
                    {
                        pkGeom = pkChild->GetAsGeometry();
                        if (pkGeom)
                            break;
                    }
                }
            } while (!pkGeom);
            long iStrips = pkGeom->IsStrips();
            unsigned short usCopies;
            if (2 <= ::DAT_011f91c0)
                usCopies = 0xe4;
            else
                usCopies = 0x50;
            unsigned short usGroup;
            unsigned char ucStrips;
            B61Ref* pkNewData;
            B61Float* pkNumbers;

            if (!iStrips)
            {
                B61Data* pkData = pkGeom->m_pUserData;
                ucStrips = 0;
                usVerts = pkData->m_usVertices;
                B61Vec3* n = pkData->m_pkVertex;
                unsigned long uiTriListLength = pkData->m_uiTriListLength;
                unsigned short* pusTriList = ((unsigned short *)(reinterpret_cast<::FnvCpu_FUN_00a7b850_CpuObject *>((pkData))->FUN_00a7b850()));
                unsigned short usMax = 0xffff / usVerts;
                if (usCopies >= usMax)
                    usCopies = usMax;
                unsigned short iListLen = (unsigned short)uiTriListLength;
                usMax = 0xffff / iListLen;
                if (usCopies >= usMax)
                    usCopies = usMax;
                unsigned int iTotalVertexCount = usCopies * usVerts;
                B61Vec3* pkVertex = new B61Vec3[iTotalVertexCount];
                B61Vec3* pkNormal = new B61Vec3[iTotalVertexCount];
                B61Color* pkColor = new B61Color[iTotalVertexCount];
                B61UV* pkTexture = new B61UV[iTotalVertexCount];
                pkNumbers = new B61Float[iTotalVertexCount];
                B61Index* v = new B61Index[B61Promote(iListLen) * usCopies];
                int pkSrcVertex = 0;
                B61Vec3* pkSrcNormal = pkData->m_pkNormal;
                B61Color* pkSrcColor = pkData->m_pkColor;
                B61UV* pkSrcTexture = pkData->m_pkTexture;
                for (int iRow = 0; iRow < usCopies; iRow++)
                {
                    unsigned int iBase = iRow * usVerts;
                    for (int i = 0; i < usVerts; i++)
                    {
                        long k = iBase + i;
                        pkVertex[k] = n[i];
                        pkNormal[k] = pkSrcNormal[i];
                        pkColor[k] = pkSrcColor[i];
                        pkTexture[k] = pkSrcTexture[i];
                        pkNumbers[k].f = (float)iRow;
                    }
                    for (int j = 0; j < iListLen; j++)
                    {
                        v[pkSrcVertex].us = pusTriList[j] + iBase;
                        pkSrcVertex++;
                    }
                }
                int iTris = iListLen / 3;
                usGroup = iTris;
                pkNewData = new B61TriShapeData(usCopies * usVerts, pkVertex, pkNormal, pkColor, pkTexture, 1, 0,
                                                iTris * usCopies, v, usCopies * usVerts, 0);
            }
            else
            {
                ucStrips = 1;
                B61Data* pkData = pkGeom->m_pUserData;
                usVerts = pkData->m_usVertices;
                unsigned short* pusLengths = pkData->m_pusStripLengths;
                B61Vec3* n = pkData->m_pkVertex;
                unsigned short* pusStrips = ((unsigned short *)(::FUN_00a75f10((char *)(pkData))));
                unsigned short usMax = 0xffff / usVerts;
                if (usCopies >= usMax)
                    usCopies = usMax;
                long iLen = *pusLengths;
                usMax = 0xffff / (iLen + (iLen % 2 ? 3 : 2));
                if (usCopies >= usMax)
                    usCopies = usMax;
                B61Vec3* pkVertex;
                pkVertex = new B61Vec3[usCopies * usVerts];
                B61Vec3* pkNormal = new B61Vec3[usCopies * usVerts];
                B61Color* pkColor = new B61Color[usCopies * usVerts];
                B61UV* pkTexture = new B61UV[usCopies * usVerts];
                pkNumbers = new B61Float[usCopies * usVerts];
                unsigned short usLen = *pusLengths;
                unsigned short usStride = usLen + (usLen % 2 ? 3 : 2);
                B61Index* v = new B61Index[(usCopies - 1) * usStride + usLen];
                int pkSrcVertex = 0;
                B61Vec3* pkSrcNormal = pkData->m_pkNormal;
                B61Color* pkSrcColor = pkData->m_pkColor;
                B61UV* pkSrcTexture = pkData->m_pkTexture;
                for (int iRow = 0; iRow < usCopies; iRow++)
                {
                    long pObj = iRow * usVerts;
                    std::memmove(&pkVertex[pObj], n, usVerts * sizeof(B61Vec3));
                    std::memmove(&pkNormal[pObj], pkSrcNormal, usVerts * sizeof(B61Vec3));
                    std::memmove(&pkColor[pObj], pkSrcColor, usVerts * sizeof(B61Color));
                    std::memmove(&pkTexture[pObj], pkSrcTexture, usVerts * sizeof(B61UV));
                    for (int i = 0; i < usVerts; i++)
                        pkNumbers[i + pObj].f = (float)iRow;
                    for (int j = 0; j < *pusLengths; j++)
                        v[pkSrcVertex++].us = pusStrips[j] + iRow * usVerts;
                    if (iRow < (int)usCopies - 1)
                    {
                        long usRow = iRow;
                        v[pkSrcVertex++].us = pusStrips[*pusLengths - 1] + usRow * usVerts;
                        v[pkSrcVertex++].us = pusStrips[0] + (usRow + 1) * usVerts;
                        if (*pusLengths % 2 == 1)
                            v[pkSrcVertex++].us = pusStrips[0] + (usRow + 1) * usVerts;
                    }
                }
                unsigned short* pusNewLengths = (unsigned short*)reinterpret_cast<::MemoryManagerStandIn *>((((P03MM*)&g_memoryManager)))->FUN_00aa3e40(2);
                pusNewLengths[0] = pkSrcVertex;
                int length = *pusLengths;
                if (length % 2 == 1)
                    usGroup = length + 3;
                else
                    usGroup = length + 2;
                pkNewData = new B61TriStripsData(usCopies * usVerts, pkVertex, pkNormal, pkColor, pkTexture, 1, 0,
                                                 pkSrcVertex - 2, 1, pusNewLengths, v, usCopies * usVerts, 0);
            }
            NiPointer<B61Ref> spShader;
            if (((::B61Property *)(reinterpret_cast<::FUN_00a59d30_C *>((pkGeom))->FUN_00a59d30(3))) && ((B61TexProp*)((::B61Property *)(reinterpret_cast<::FUN_00a59d30_C *>((pkGeom))->FUN_00a59d30(3))))->IsShaderType())
            {
                B61TexProp* pkTex = (B61TexProp*)((::B61Property *)(reinterpret_cast<::FUN_00a59d30_C *>((pkGeom))->FUN_00a59d30(3)));
                if (pkTex)
                {
                    B61Ref* pkShader = pkTex->GetGeometryShaderObject();
                    B61Set(spShader, pkShader);
                }
            }
            B61Property* resultAlpha = ((::B61Property *)(reinterpret_cast<::FUN_00a59d30_C *>((pkGeom))->FUN_00a59d30(0)));
            unsigned int uiTestRef = 0;
            B61Property* pkAlpha = resultAlpha;
            if (pkAlpha)
                uiTestRef = pkAlpha->m_ucTestRef;
            else
                pkAlpha = (B61Property*)new B61AlphaProperty;
            pkAlpha->m_ucTestRef = uiTestRef;
            pkAlpha->m_usFlags = (pkAlpha->m_usFlags & 0xf3ff) | 0x1201;
            B61Property* q = (B61Property*)new B61AlphaProperty;
            q->m_ucTestRef = uiTestRef;
            q->m_usFlags = (q->m_usFlags & 0xf3fe) | 0x1200;
            B61Property* pkExtra = ((::B61Property *)(reinterpret_cast<::FUN_00a59d30_C *>((pkGeom))->FUN_00a59d30(4)));
            B61Bound kBound = pkGeom->m_pUserData->m_kBound;
            spEntry->m_ucStrips = ucStrips;
            spEntry->m_spTransformData = pkNewData;
            spEntry->m_pkNumbers = pkNumbers;
            spEntry->m_iWidth = usVerts;
            spEntry->m_pGeometryShader = spShader;
            spEntry->m_spAlpha2 = q;
            spEntry->m_spAlpha = pkAlpha;
            spEntry->m_spExtra = pkExtra;
            spEntry->m_fBoundRadius = kBound.r;
            spEntry->m_iCopies = usCopies;
            spEntry->m_usGroup = usGroup;
            spEntry->m_ucKind = 0;
            if (kIter)
            {
                B61AVObject* pkKind = B61IsKindOf(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4aa0)), kIter) ? kIter : 0;
                if (pkKind)
                    spEntry->m_ucKind = 1;
            }
            B61Notify(*ppcName);
        }
        else
            return 0;
    }
    return spEntry;
}

struct ShaderVector
{
    float x, y, z;
    float Luminance() const
    {
        return static_cast<float>(y * DAT_010ae8c0 + x * DAT_010ae8b8 + z * DAT_010ae8b0);
    }
};
struct ShaderColor
{
    float r, g, b, a;
    ShaderColor()
    {}
    ShaderColor(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha)
    {}
};
struct ShaderTransform
{
    int unk00;
};
struct RenderProperty
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual float GetOpacity();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int flags20, flags24;
    float alpha;
};
struct ShaderCameraBlock
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    ShaderVector* position;
    __forceinline ShaderVector*& PositionRef()
    {
        return position;
    }
};
struct ShaderType
{
    void* vtable;
    unsigned short type;
    unsigned short unk06;
    unsigned char unk08;
    unsigned char count;
};
struct FadeConfig
{
    int unk00, unk04;
    bool enabled;
};
extern float DAT_011fd95c;
extern float DAT_011fa27c;
double __cdecl FUN_00b719c0(double maximum, double value);
struct SceneVectorData
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88;
    ShaderTransform transform;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC;
    int unkC0;
    float factor;
    int unkC8, unkCC, unkD0;
    ShaderVector color;
    float radius;
    ShaderVector GetColor() const
    {
        return color;
    }
};
struct ShaderLink
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC;
    ShaderLink* linkE0;
    int unkE4, unkE8, unkEC, unkF0, unkF4;
    SceneVectorData* scene;
};
struct ShaderSourceRecord
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    union
    {
        unsigned short flags;
        unsigned char flagsLo;
        struct
        {
            unsigned short low9 : 9;
            unsigned short m_bBit9 : 1;
        } bits;
    };
};
struct ShaderGeometry
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98;
    ShaderSourceRecord* property;
};
static inline double S00b7ba70_Max(double a, double b)
{
    return a > b ? a : b;
}
static inline double S00b7ba70_Inv(double c)
{
    return 1.0 - c;
}
static inline ShaderType* S00b7ba70_Index()
{
    return reinterpret_cast<ShaderType*>((*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0)));
}
struct S00b7ba70_Updater
{
    void FUN_00b7ba70(RenderProperty*, ShaderType*, ShaderGeometry*, void*);
};
// Updates global shader color and alpha based on property flags, light falloff, and shader type, then applies mode-specific overrides.
// @fnv 0x00b7ba70
void S00b7ba70_Updater::FUN_00b7ba70(RenderProperty* property, ShaderType* shader, ShaderGeometry* geometry,
                                     void* state)
{
    ShaderColor& kShaderColor = *reinterpret_cast<ShaderColor*>(const_cast<unsigned char*>(DAT_011FA0C0));
    ShaderColor current = kShaderColor;
    kShaderColor = ShaderColor(current.r, current.g, current.b, property->alpha);
    ShaderType* index = S00b7ba70_Index();
    if ((*reinterpret_cast<::FadeConfig * *>(&::DAT_011fec3c))->enabled && (shader->type < 195 || shader->type > 214))
        ::ApplySourceColor((::Source374 *)(state));
    else
        ::AccumulateLightColor((::L08 *)(state));
    if (shader->type >= 195 && shader->type <= 214)
    {
        DAT_011fd95c = static_cast<float>(shader->count);
        DAT_011fa27c = static_cast<float>(shader->count);
    }
    if (DAT_011f91a7)
        kShaderColor = ShaderColor(1.0f, 1.0f, 1.0f, 1.0f);
    if ((property->flags24 & 0x8000) > 0 && (property->flags20 & 0x20000) <= 0 && index->type >= 580 &&
        index->type <= 587)
    {
        unsigned int alpha = 0;
        float x = 0.0f;
        ShaderLink* light = static_cast<ShaderLink*>(((void *)(::FUN_00b70600((::FUN_00b70600_list *)(property), 0, (::FUN_00b70600_node **)(&alpha)))));
        ShaderVector falloff = reinterpret_cast<ShaderLink*>((*reinterpret_cast<::Camera * *>(&::DAT_011f91c8)))->linkE0->scene->GetColor();
        float gp = falloff.Luminance();
        if (light)
        {
            ShaderLink* __restrict view = light;
            ShaderVector* source = (*reinterpret_cast<ShaderCameraBlock* volatile*>((*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0))))->PositionRef();
            ShaderVector* position = source;
            if (position == 0)
                position = reinterpret_cast<ShaderVector*>(&(*reinterpret_cast<::RSCmdOwnerParam *>(&::g_defaultBound)));
            SceneVectorData* scene = view->scene;
            ShaderVector relative, scaled;
            reinterpret_cast<::FUN_00439ef0_class *>(&(scene->transform))->FUN_00439ef0((::NiPoint3 *)(::ShaderVector *)(&relative), (*(const ::NiPoint3 *)(position)));
            SceneVectorData* colourScene = light->scene;
            reinterpret_cast<::NiPoint3 *>(&(colourScene->color))->ScaleTo((::NiPoint3 *)(::ShaderVector *)(&scaled), colourScene->factor);
            float distance = reinterpret_cast<::NiPoint3 *>(&(relative))->ComputeMagnitude() / scene->radius;
            float color = static_cast<float>(FUN_00b719c0(1.0, FUN_0068b050(0.0, distance)));
            volatile float inverse = static_cast<float>(S00b7ba70_Inv(color));
            x = inverse;
            x *= reinterpret_cast<::FUN_00b719e0_class *>(&(scaled))->ComputeWeightedSum();
        }
        x = static_cast<float>(S00b7ba70_Max(x, gp));
        kShaderColor.a *= x;
    }
    unsigned int mode = DAT_011f91b8;
    if (mode == 8)
    {
        float active = (property->flags24 & 0x20000) > 0 ? 0.0f : 1.0f;
        ShaderSourceRecord* z = geometry->property;
        float blue = (!(z->flagsLo & 1) && !((unsigned char)(z->flags >> 9) & 1)) ? 1.0f : 0.0f;
        kShaderColor = ShaderColor(0.0f, 0.0f, blue, active);
    }
    if (DAT_011f91e4 - 580 <= 7 && 10 != mode)
    {
        kShaderColor.a *= property->GetOpacity();
    }
}

struct ScaleValue
{
    float value;
    ScaleValue(float x) : value(x)
    {}
    operator float() const
    {
        return value;
    }
};
inline float RoundScale(float x)
{
    const float& result = x;
    return result;
}
struct WorkerColor
{
    float r, g, b;
    WorkerColor& operator*=(float value)
    {
        r *= value;
        g *= value;
        b *= value;
        return *this;
    }
};
struct WorkerMaterial
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
    float intensity;
    int unkc8;
    int unkcc;
    int unkd0;
    WorkerColor color;
    WorkerColor GetColor() const
    {
        return color;
    }
};
struct ScaleObject
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
    float dimmer;
    float alpha;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    WorkerMaterial* material;
};
// Computes a fog color from the material intensity, dimmer scale, and global flags, then stores it in DAT_011fa0d0.
// @fnv 0x00b7c600
void FUN_00b7deb0_class::FUN_00b7c600()
{
    ScaleObject*& object = (ScaleObject*&)(*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0))->unk0c->unk00;
    WorkerMaterial* material = object->material;
    float intensity = material->intensity;
    if (!DAT_011f941e && intensity > ::g_01012070)
        intensity = 1.0f;
    ScaleValue dimmer = RoundScale(object->dimmer);
    WorkerColor source = material->GetColor();
    source *= intensity;
    WorkerColor color = source;
    color *= dimmer;
    if (DAT_011f941e && !DAT_011f9427)
        color *= DAT_011f9190;
    (*reinterpret_cast<::FogVector *>((void *)&::DAT_011FA0D0)) = FogVector(color.r, color.g, color.b, object->alpha);
}

namespace fnv_00b60790 {
#include <intrin.h>

struct MemScope
{
    int old;
    __forceinline MemScope()
    {
        old = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 0x1c;
    }
    __forceinline ~MemScope()
    {
        ::g_tlsBlock.memoryContext = old;
    }
};
struct PassArray
{
    int unk00;
    void** passes;
    int unk08, unk0c;
    unsigned int count;
    void FUN_00ba9ee0(void* geometry, unsigned short pass, bool enabled, unsigned char lights, void* l0, void* l1,
                      void* l2, void* l3);
};
struct PassPointer
{
    PassArray* pointer;
    __forceinline PassArray* operator->() const
    {
        return pointer;
    }
    __forceinline operator PassArray*() const
    {
        return pointer;
    }
};
struct Light
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
    int unke0;
    int unke4;
    int unke8;
    unsigned char active;
};
void __cdecl FUN_00ba8c50(void*, int, void*);
inline int ShadowFeatureEnabled()
{
    return (::fnv_005bf7b0::DAT_011f91d8 & 16) > 0;
}
struct ShaderPassBuilder
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int flags;
    int unk28, unk2c, unk30, unk34;
    unsigned int cached;
    PassPointer array;
    PassArray* FUN_00b60790(void*, uintptr_t, int, unsigned int, int, int);
};
// @fnv 0x00b60790
PassArray* ShaderPassBuilder::FUN_00b60790(void* geometry, uintptr_t mode, int unused, unsigned int variant,
                                           int unused2, int FlushUsageData)
{
    MemScope scope;
    if (cached != mode)
    {
        reinterpret_cast<::TallGrassShader *>(this)->InitializeConstants(2);
        array->count = 0;
        void* position = 0;
        unsigned short lightCount = (*reinterpret_cast<unsigned char *>(&::DAT_011f9ef0)) ? ((unsigned short)(::FUN_00b707d0((void *)this))) : 0;
        bool special = (flags & 0x400) > 0;
        bool textured = (flags & 0x1000) > 0;
        bool alternate = (flags & 0x2000) > 0;
        bool extra = !::DAT_011f9427 && ::DAT_011f95e4 && (::fnv_005bf7b0::DAT_011f91d8 & 0x20) && ::DAT_011f91c0 >= 2 &&
                     (unsigned int)::DAT_011fd890 != 0;
        unsigned int pass = ((*reinterpret_cast<unsigned char *>(&::DAT_011f941e)) ? 0x246 : 0);
        unsigned short noLights = 0;
        pass += lightCount > noLights ? 0x14 : 0;
        if (special)
        {
            if (textured)
            {
                if (!extra)
                    array->FUN_00ba9ee0(geometry, pass + 0x19, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00ba9ee0(geometry, pass + 0x21, true, 0, 0, 0, 0, 0);
            }
            else
            {
                if (!extra)
                    array->FUN_00ba9ee0(geometry, pass + 0x17, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00ba9ee0(geometry, pass + 0x1f, true, 0, 0, 0, 0, 0);
            }
        }
        else if (textured)
        {
            if (alternate)
                array->FUN_00ba9ee0(geometry, pass + 0x27, true, 0, 0, 0, 0, 0);
            else
            {
                if (!extra)
                    array->FUN_00ba9ee0(geometry, pass + 0x18, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00ba9ee0(geometry, pass + 0x20, true, 0, 0, 0, 0, 0);
            }
        }
        else
        {
            if (alternate)
                array->FUN_00ba9ee0(geometry, pass + 0x26, true, 0, 0, 0, 0, 0);
            else
            {
                if (!extra)
                    array->FUN_00ba9ee0(geometry, pass + 0x16, true, 0, 0, 0, 0, 0);
                else
                    array->FUN_00ba9ee0(geometry, pass + 0x1e, true, 0, 0, 0, 0, 0);
            }
        }
        if (lightCount > 0)
        {
            void* light = ((void *)(::FUN_00b70600((::FUN_00b70600_list *)this, 0, (::FUN_00b70600_node **)(&position))));
            FUN_00ba8c50(array->passes[array->count - 1], 1, light);
        }
        if (::DAT_011f91c0 >= 3)
        {
            int enabled = ShadowFeatureEnabled();
            const bool& bShadow = *(bool*)&enabled;
            if (bShadow)
            {
                Light* light = ((::fnv_00b60790::Light *)(reinterpret_cast<::BSShaderLightingProperty *>(this)->GetFirstActiveLight((*(void * *)(&position)))));
                while (light)
                {
                    if (light->active)
                    {
                        if (textured)
                        {
                            if (alternate)
                                array->FUN_00ba9ee0(geometry, 0x287, false, 1, light, 0, 0, 0);
                            else
                                array->FUN_00ba9ee0(geometry, 0x285, false, 1, light, 0, 0, 0);
                        }
                        else
                        {
                            if (alternate)
                                array->FUN_00ba9ee0(geometry, 0x286, false, 1, light, 0, 0, 0);
                            else
                                array->FUN_00ba9ee0(geometry, 0x284, false, 1, light, 0, 0, 0);
                        }
                    }
                    light = ((::fnv_00b60790::Light *)(::FUN_00b70680(*reinterpret_cast<::NiTListItem< ::ShadowSceneLight *> **>(&position))));
                }
            }
        }
        cached = mode | (variant << 8);
    }
    return array;
}
}  // namespace fnv_00b60790

namespace fnv_00b6b0b0 {
#include <windows.h>

struct PoolRefObj
{
    virtual void v0();
    virtual void Destroy();
    long m_iRef;
};
// Pops the last entry from the pool reference array, decrements its reference count, and destroys the object if the count reaches zero.
// @fnv 0x00b6b0b0
void __cdecl FUN_00b6b0b0()
{
    if (::DAT_011fa020 == 0)
        return;
    --::DAT_011fa020;
    PoolRefObj** slot = &(*reinterpret_cast<fnv_00b6b0b0::PoolRefObj * (*)[]>(&::fnv_00b6b6c0::DAT_011fa024))[::DAT_011fa020];
    PoolRefObj* obj = *slot;
    if (obj != 0)
    {
        if (InterlockedDecrement(&obj->m_iRef) == 0)
            obj->Destroy();
        *slot = 0;
    }
}
}  // namespace fnv_00b6b0b0

namespace fnv_00b6b380 {
struct Rtti
{
    const char* name;
    Rtti* parent;
};
struct Ref
{
    virtual void Slot0();
    virtual void Destroy();
    virtual Rtti* GetRTTI();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void* GetTexture();
    long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            Destroy();
    }
};
struct Base
{
    Base();
    virtual ~Base();
    int refs;
};
struct Pixel : Ref
{
};
struct Node : Ref
{
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
    void* faces[6];
};
struct FUN_00b6b380 : Base
{
    NiPointer<Pixel> textures[6];
    NiPointer<Node> extra0, extra1, extra2;
    int state;
    NiPointer<Node> nodes[4];
    FUN_00b6b380(Node* source, bool option, intptr_t arg);
    virtual ~FUN_00b6b380();
};
inline Node* CastCube(Node* source)
{
    Rtti* type = source ? source->GetRTTI() : 0;
    while (type)
    {
        if (type == &(*reinterpret_cast<::fnv_00b6b380::Rtti *>(&::g_012708e4)))
            return source;
        type = type->parent;
    }
    return 0;
}
// Initializes textures from a Node's faces or texture, setting extra pointers to null and state to -1.
// @fnv 0x00b6b380
FUN_00b6b380::FUN_00b6b380(Node* source, bool option, intptr_t arg)
{
    nodes[0] = source;
    intptr_t mode = option ? ((intptr_t)(::FUN_00b6b180((::FUN_00b6b180_Obj *)(source), (::FUN_00b6b180_Tex *)(arg)))) : 0;
    Node* cube = CastCube(source);
    if (!cube)
    {
        textures[0] = ((::fnv_00b6b380::Pixel *)(::FUN_00ee8760(source->GetTexture(), (::SourceObject *)(DAT_011f4748), (void *)(mode))));
        for (int index = 1; index < 6; ++index)
            textures[index] = 0;
    }
    else
    {
        for (int index = 0; index < 6; ++index)
        {
            void* surface = cube->faces[index];
            textures[index] = ((::fnv_00b6b380::Pixel *)(::FUN_00ee8760(surface, (::SourceObject *)(DAT_011f4748), (void *)(mode))));
        }
    }
    extra0 = 0;
    extra1 = 0;
    extra2 = 0;
    state = -1;
}
}  // namespace fnv_00b6b380

struct Mode200
{
    int unk00;
    unsigned short id;
    unsigned short unk06;
    unsigned char unk08, unk09, unk0a, flag;
};

struct Texture200
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
};
struct Shader200
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    Texture200* unkac;
    Texture200* unkb0;
    int* unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    unsigned unkc8;
    unsigned unkcc;
    unsigned unkd0;
    unsigned unkd4;
    unsigned unkd8;
    Texture200* unkdc;
};
struct Arg200
{
    int unk00, unk04, unk08;
    Shader200* shader;
};
struct Stage200
{
    int unk00, unk04;
    intptr_t texture;
};
struct Stages200
{
    Stage200* unk00;
    Stage200* unk04;
    Stage200* unk08;
    Stage200* unk0c;
    Stage200* unk10;
    Stage200* unk14;
    Stage200* unk18;
    Stage200* unk1c;
    Stage200* unk20;
    Stage200* unk24;
    Stage200* unk28;
    Stage200* unk2c;
    Stage200* unk30;
    Stage200* unk34;
};
struct Renderer200
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
    Stages200* unk24;
};
struct Host200
{
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
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    void FUN_00b7d200(Arg200*);
};
// Switches on the current mode id to call stage helpers and set renderer stage textures from the argument's shader or fallback textures, then calls v108.
// @fnv 0x00b7d200
void Host200::FUN_00b7d200(Arg200* arg)
{
    unsigned mode = ((Mode200*)(*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0)))->id;
    Shader200* shader = arg->shader;
    Renderer200* renderer = (Renderer200*)DAT_0126f74c;
    bool enabled = true;
    if ((shader->unk24 & 0x100000) > 0)
        enabled = false;
    switch (mode)
    {
    case 196:
    case 199:
    case 203:
    case 206:
    case 255:
    case 262:
    case 268:
    case 274:
    case 279:
    case 285:
    case 290:
    case 296:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 1, false);
        {
            Stage200* stage = ((Renderer200*)DAT_0126f74c)->unk24->unk10;
            int texture = *shader->unkb4;
            if (texture)
                stage->texture = texture;
            else
                stage->texture = (*reinterpret_cast<int *>(&::DAT_011f951c));
        }
        break;
    case 216:
    case 221:
    case 225:
    case 230:
    case 234:
    case 239:
    case 243:
    case 248:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 1, false);
        {
            Stage200* stage = ((Renderer200*)DAT_0126f74c)->unk24->unk0c;
            intptr_t texture = *shader->unkb4;
            if (texture)
                stage->texture = texture;
            else
                stage->texture = (*reinterpret_cast<int *>(&::DAT_011f951c));
        }
        break;
    case 102:
    case 103:
    case 107:
    case 108:
    case 113:
    case 114:
    case 118:
    case 119:
    case 129:
    case 130:
    case 134:
    case 135:
    case 139:
    case 140:
    case 144:
    case 145: {
        Stage200* stage = ((Renderer200*)DAT_0126f74c)->unk24->unk08;
        intptr_t texture = *shader->unkb4;
        if (texture)
            stage->texture = texture;
        else
            stage->texture = (*reinterpret_cast<int *>(&::DAT_011f951c));
    }
    case 100:
    case 101:
    case 105:
    case 106:
    case 111:
    case 112:
    case 116:
    case 117:
    case 127:
    case 128:
    case 131:
    case 132:
    case 137:
    case 138:
    case 141:
    case 142:
    case 195:
    case 198:
    case 201:
    case 205:
    case 215:
    case 220:
    case 224:
    case 229:
    case 233:
    case 238:
    case 242:
    case 247:
    case 251:
    case 261:
    case 266:
    case 273:
    case 278:
    case 284:
    case 289:
    case 295:
    case 565:
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 1, false);
    case 2:
    case 6:
    case 7:
    case 8:
    case 17:
    case 19:
    case 88:
    case 90:
    case 92:
    case 94:
    case 98:
    case 99:
    case 330:
    case 333:
    case 334:
    case 335:
    case 595:
    case 597:
    case 734:
    case 735:
    case 746:
    case 747:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        break;
    case 150:
    case 156:
    case 161:
    case 167:
    case 172:
    case 178:
    case 183:
    case 189:
    case 210:
    case 213: {
        Stage200* stage = ((Renderer200*)DAT_0126f74c)->unk24->unk10;
        intptr_t texture = *shader->unkb4;
        if (texture)
            stage->texture = texture;
        else
            stage->texture = (*reinterpret_cast<int *>(&::DAT_011f951c));
    }
    case 149:
    case 155:
    case 160:
    case 166:
    case 171:
    case 177:
    case 182:
    case 188:
    case 208:
    case 212:
    case 267:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 1, false);
        break;
    case 584:
    case 585:
    case 586:
        ::SetSlotValue((::SlotObject *)(shader), 3, false);
        reinterpret_cast<::ShaderStageSetter *>(this)->FUN_00b7c290((intptr_t)(shader), 1, false);
    case 341:
    case 343:
    case 346:
    case 347:
    case 349:
    case 350:
    case 352:
    case 353:
    case 355:
    case 356:
    case 358:
    case 359:
    case 361:
    case 362:
    case 364:
    case 365:
    case 367:
    case 368:
    case 370:
    case 371:
    case 373:
    case 374:
    case 587:
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 0, false);
        break;
    case 580:
    case 581:
    case 582:
    case 583:
        ::SetSlotValue((::SlotObject *)(shader), 2, false);
        reinterpret_cast<::ShaderStageSetter *>(this)->FUN_00b7c290((intptr_t)(shader), 3, false);
    case 124:
    case 125:
    case 300:
    case 301:
    case 302:
    case 303:
    case 306:
    case 309:
    case 318:
    case 321:
    case 340:
    case 342:
    case 482:
    case 483:
    case 484:
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 0, false);
        break;
    case 89:
    case 91:
    case 93:
    case 95:
    case 497:
    case 500:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        {
            Stage200* stage = ((Renderer200*)DAT_0126f74c)->unk24->unk04;
            intptr_t texture = *shader->unkb4;
            if (texture)
                stage->texture = texture;
            else
                stage->texture = (*reinterpret_cast<int *>(&::DAT_011f951c));
        }
        break;
    case 726:
    case 727: {
        Stage200* stage = ((Renderer200*)DAT_0126f74c)->unk24->unk00;
        intptr_t texture = *shader->unkb4;
        if (texture)
            stage->texture = texture;
        else
            stage->texture = (*reinterpret_cast<int *>(&::DAT_011f951c));
    }
    break;
    case 331:
    case 336:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 1, true);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 2, true);
        break;
    case 104:
    case 109:
    case 115:
    case 120:
    case 133:
    case 143:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 1, false);
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 2, true);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 3, true);
        break;
    case 332:
    case 338:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 1, true);
        break;
    case 151:
    case 157:
    case 162:
    case 168:
    case 173:
    case 179:
    case 184:
    case 190:
    case 260:
    case 265:
    case 272:
    case 277:
    case 283:
    case 288:
    case 294:
    case 299:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 1, false);
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 4, true);
        break;
    case 254:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 1, false);
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 4, true);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 6, true);
        ::UpdateSlotFromGlobal(7);
        break;
    case 561:
    case 562:
    case 563:
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, false);
        ::FUN_00b7c120(6);
        break;
    case 147:
    case 148:
    case 495:
    case 496:
    case 498:
    case 499:
    case 501:
    case 502: {
        int flag = ((Mode200*)(*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0)))->flag;
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, flag);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 1, flag);
    }
    break;
    case 560: {
        int flag = ((Mode200*)(*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0)))->flag;
        ::FUN_00b7c0a0((::NiD3DShader *)(shader), 0, flag);
        reinterpret_cast<::ShaderStageManager *>(this)->FUN_00b7c0e0((::NiD3DShader *)(shader), 1, flag);
        ::UpdateSlotFromGlobal(2);
    }
    break;
    case 551:
    case 552:
    case 553:
    case 554:
    case 555:
    case 556:
    case 557:
    case 558:
        renderer->unk24->unk18->texture = shader->unkac->unk18;
        if (enabled)
            renderer->unk24->unk34->texture = shader->unkb0->unk18;
    case 543:
    case 544:
    case 545:
    case 546:
    case 547:
    case 548:
    case 549:
    case 550:
        renderer->unk24->unk14->texture = shader->unkac->unk14;
        if (enabled)
            renderer->unk24->unk30->texture = shader->unkb0->unk14;
    case 535:
    case 536:
    case 537:
    case 538:
    case 539:
    case 540:
    case 541:
    case 542:
        renderer->unk24->unk10->texture = shader->unkac->unk10;
        if (enabled)
            renderer->unk24->unk2c->texture = shader->unkb0->unk10;
    case 527:
    case 528:
    case 529:
    case 530:
    case 531:
    case 532:
    case 533:
    case 534:
        renderer->unk24->unk0c->texture = shader->unkac->unk0c;
        if (enabled)
            renderer->unk24->unk28->texture = shader->unkb0->unk0c;
    case 519:
    case 520:
    case 521:
    case 522:
    case 523:
    case 524:
    case 525:
    case 526:
        renderer->unk24->unk08->texture = shader->unkac->unk08;
        if (enabled)
            renderer->unk24->unk24->texture = shader->unkb0->unk08;
    case 511:
    case 512:
    case 513:
    case 514:
    case 515:
    case 516:
    case 517:
    case 518:
        renderer->unk24->unk04->texture = shader->unkac->unk04;
        if (enabled)
            renderer->unk24->unk20->texture = shader->unkb0->unk04;
    case 503:
    case 504:
    case 505:
    case 506:
    case 507:
    case 508:
    case 509:
    case 510:
        renderer->unk24->unk00->texture = shader->unkac->unk00;
        if (enabled)
            renderer->unk24->unk1c->texture = shader->unkb0->unk00;
        break;
    case 4:
    case 5: {
        Stage200* stage = renderer->unk24->unk00;
        Texture200* texture = shader->unkdc;
        if (texture && texture->unk6c)
            stage->texture = texture->unk6c;
        else
            stage->texture = (intptr_t)(*reinterpret_cast<::NiTextureB7A * *>(&::DAT_011f952c));
        ::FUN_00b71b10((::BeamStage *)(stage), (::NiD3DShader *)(shader));
    }
    break;
    default:
        return;
    }
    v108();
}

struct FNVColorRGB
{
    float red, green, blue;
};
struct FNVColorRGBA
{
    float red, green, blue, alpha;
};

// Reads the current RGB color from the active renderer's state and stores it as an RGBA value with full opacity into DAT_011fa0c0.
// @fnv 0x00b7c580
void FUN_00b7deb0_class::FUN_00b7c580()
{
    char* manager = reinterpret_cast<char*>((*reinterpret_cast<::S_00b7c120_Global2 * *>(&::DAT_011f91e0)));
    char* slot = *reinterpret_cast<char**>(manager + 0x0c);
    char* renderer = *reinterpret_cast<char**>(slot);
    char* state = *reinterpret_cast<char**>(renderer + 0xf8);
    FNVColorRGB rgb = *reinterpret_cast<FNVColorRGB*>(state + 0xc8);
    FNVColorRGBA color = {rgb.red, rgb.green, rgb.blue, 1.0f};
    *reinterpret_cast<FNVColorRGBA*>(&(*reinterpret_cast<float *>((void *)&::DAT_011FA0C0))) = color;
}

struct B64440Q
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float m_1c;
};

struct B64440A2
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
    B64440Q* m_b8;
};

// @fnv 0x00b64440
bool __cdecl FUN_00b64440(RSSettings* apSettings, B64440A2* a2, void* a3, RSPacket* apPacket, RSResponse* apResponse)
{
    if (a2->m_b8->m_1c < 50.0)
        return true;
    if (apResponse->m_iType == 0x16)
        return true;
    if ((apPacket->m_uiFlags2 & 0x40000) <= 0)
        return true;
    return ProcessCommands(apSettings, a2, a3, apPacket, apResponse);
}


struct FUN_00b63b60_class
{
    char pad000[0x1b4];
    NiTMapBaseStub m_kMap;
    char pad1b5[0x200 - 0x1b5];
    CRITICAL_SECTION m_kLock;
    void FUN_00b63b60();
};

// Removes all entries from m_kMap while holding m_kLock.
// @fnv 0x00b63b60
void FUN_00b63b60_class::FUN_00b63b60()
{
    EnterCriticalSection(&m_kLock);
    reinterpret_cast<::S_00b601a0_Map *>(&m_kMap)->FUN_00b601a0();
    LeaveCriticalSection(&m_kLock);
}

#include "generated/data/staging/blk_00b60000_o2.inc"
