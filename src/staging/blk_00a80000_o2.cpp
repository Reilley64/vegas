
// src/staging/blk_00a80000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include <windows.h>
#include <new>
#include <cmath>
#include <cstring>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Bound88.h"
#include "fnv/decl/C_00aa0dc0.h"
#include "fnv/decl/ExtraDataObject.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00a311e0_s.h"
#include "fnv/decl/FUN_00a5c200.h"
#include "fnv/decl/FUN_00a5c240_shell.h"
#include "fnv/decl/FUN_00a5d3a0.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/FUN_00a5d610_Object.h"
#include "fnv/decl/FUN_00a5ecb0.h"
#include "fnv/decl/FUN_00a67b20.h"
#include "fnv/decl/FUN_00a67c00.h"
#include "fnv/decl/FUN_00a6db50_V.h"
#include "fnv/decl/FUN_00a71f60_cls.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/FUN_00a7b690.h"
#include "fnv/decl/FUN_00a981d0.h"
#include "fnv/decl/HashTableBase.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiDepthStencilBuffer.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/NiPoint2_shell.h"
#include "fnv/decl/NiTObjectArrayA47.h"
#include "fnv/decl/fnv_00a67c70__FUN_00a67c70_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00714000.h"
#include "fnv/symbols_00a47000.h"
#include "fnv/symbols_00a5d000.h"
#include "fnv/symbols_00a71000.h"
#include "fnv/symbols_00a7e000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00a8d000.h"
#include "fnv/symbols_00a90000.h"
#include "fnv/symbols_00a98000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_0109e000.h"
#include "fnv/symbols_0109f000.h"
#include "fnv/symbols_010a0000.h"
#include "fnv/symbols_010a1000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_00aa1000.h"
#include "../../include/layout_support.h"

extern "C" void __cdecl _Call_a5d3a0();

struct NiCollisionObject {
    void* vft;
    int m_kPointA;
    int m_kPointB;
    NiCollisionObject();
    NiCollisionObject* Construct();
};
NiCollisionObject::NiCollisionObject()
{
    _Call_a5d3a0();
}
// @fnv 0x00a80fa0
NiCollisionObject* NiCollisionObject::Construct()
{
    new (this) NiCollisionObject();
    vft = (void*)&::DAT_0109e174;
    m_kPointB = 0;
    return this;
}


// @fnv 0x00a81a20
void __cdecl FUN_00a81a20()
{
    if (DAT_011f5b04)
    {
        DAT_011f5b04[0x1b0] = 1;
        ::FUN_00714960(-1);
    }
}

// @fnv 0x00a81b80
int __cdecl FUN_00a81b80(const unsigned short* ausLeft, const unsigned short* ausRight)
{
    if (*ausLeft < *ausRight)
        return -1;
    return *ausLeft > *ausRight;
}

struct FUN_00a744a0 {  public:
    FUN_00a744a0();
};
struct BSFadeNode {
    void* vtbl;
};
// Allocates a 0xc4-byte BSFadeNode, runs Init on it, sets its vtbl to DAT_0109e984 and returns it, or returns 0 on allocation failure.
// @fnv 0x00a877a0
BSFadeNode* FUN_00a877a0()
{
    BSFadeNode* node = static_cast<BSFadeNode*>(::operator new(0xc4));
    if (node) {
        new ((void *)(reinterpret_cast<FUN_00a744a0*>(node))) ::FUN_00a744a0();
        node->vtbl = &DAT_0109e984;
        return node;
    }
    return 0;
}

struct NiBound {
};

struct FUN_00a87900_class {
    void FUN_00a87900();
};

// @fnv 0x00a87900
void FUN_00a87900_class::FUN_00a87900()
{
    *(unsigned char*)((char*)this + 0x6e) = 0;
    if (*(unsigned short*)((char*)this + 8) > 0) {
        reinterpret_cast<::Bound88 *>((((NiBound*)((char*)this + 0x10))))->ComputeBoundingSphere(*(unsigned short*)((char*)this + 8), (const ::Vec88 *)(*(const NiPoint3**)((char*)this + 0x20)));
    }
}

extern int DAT_011f5b84;
void __cdecl InitializeGameSystems();
void __cdecl FUN_00a8a280();
struct FUN_00a8a5f0_class {
    void* FUN_00a8a5f0();
};
// @fnv 0x00a8a5f0
void* FUN_00a8a5f0_class::FUN_00a8a5f0()
{
    int old = DAT_011f5b84;
    ++DAT_011f5b84;
    if (!old)
        ::FUN_00aa2060((void (*)())&InitializeGameSystems, (void (*)())&FUN_00a8a280);
    return this;
}

struct FUN_00a8f060_class {
    void FUN_00a8f060();
};

extern "C" void NiFreeAlias(void*);

// @fnv 0x00a8f060
void FUN_00a8f060_class::FUN_00a8f060()
{
    NiFreeAlias(*(void**)((char*)this + 0x50));
    *(int*)((char*)this + 0x5C) = 0;
    *(int*)((char*)this + 0x58) = 0;
    *(int*)((char*)this + 0x54) = 0;
    *(int*)((char*)this + 0x50) = 0;
}

struct FUN_00a8f080_Class {
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void SetValues(int a, int b);
};

// @fnv 0x00a8f080
void FUN_00a8f080_Class::SetValues(int aiValue, int aiOther)
{
    m_8 = aiValue;
    m_iThirdValue = aiOther;
}

struct SdmBase;

struct FUN_00a8f730 {
    void Release();
};

// @fnv 0x00a8f730
void FUN_00a8f730::Release()
{
    if (DAT_011f5e34)
        reinterpret_cast<void(*)(void*, int)>(reinterpret_cast<void***>(DAT_011f5e34)[0][0])(DAT_011f5e34, 1);
    DAT_011f5e34 = 0;
}


// @fnv 0x00a8f750
intptr_t __cdecl GetGlobalDataPtr()
{
    return DAT_011f5d30 ? (intptr_t)&DAT_011f5d30 : 0;
}

extern intptr_t DAT_011f5e44;
extern int DAT_011f5e4c;

struct NiStreamLinkIDSet {
};

// @fnv 0x00a8ff30
void ResetStreamLinkIDSet()
{
    DAT_011f5e4c = 0;
    reinterpret_cast<::FUN_00a311e0_s *>((((NiStreamLinkIDSet*)&DAT_011f5e44)))->FUN_00a311e0(0);
}

extern int DAT_0109f814;

struct FUN_00a8ff50 {
    intptr_t m_p;
    short m_s1;
    short m_s2;
    int m_i1;
    int m_i2;
    int m_i3;
    FUN_00a8ff50();
};

// @fnv 0x00a8ff50
FUN_00a8ff50::FUN_00a8ff50()
{
    m_p = (intptr_t)&DAT_0109f814;
    m_s1 = 0;
    m_s2 = 0;
    m_i1 = 0;
    m_i2 = 0;
    m_i3 = 0;
}

void __cdecl NiFreeAlias(void*);

struct FUN_00a96440_class {
    char m_auiShapeKeys[0x4c];
    void* m_pField;
    void SetField(void* pNew);
};

// @fnv 0x00a96440
void FUN_00a96440_class::SetField(void* pNew)
{
    NiFreeAlias(m_pField);
    m_pField = pNew;
}

void NiFree(void*);
struct FUN_00a96460_class {
    char pad[0x54];
    void* m_0x54;
    void FUN_00a96460(void* p);
};
// @fnv 0x00a96460
void FUN_00a96460_class::FUN_00a96460(void* apPointer)
{
    NiFree(m_0x54);
    m_0x54 = apPointer;
}

void NiFreeAlias(void*);

struct FUN_00a96480_Class {
    void* m_5c;
    void FUN_00a96480(void* p);
};

// @fnv 0x00a96480
void FUN_00a96480_Class::FUN_00a96480(void* p)
{
    NiFreeAlias(*(void**)((char*)this + 0x5c));
    *(void**)((char*)this + 0x5c) = p;
}

extern "C" void __cdecl NiFreeAlias(void*);

struct FUN_00a964a0_Class {
    void* m_p;
    void FUN_00a964a0(void* p);
};

// @fnv 0x00a964a0
void FUN_00a964a0_Class::FUN_00a964a0(void* apValue) {
    NiFreeAlias(*(void**)((char*)this + 0x64));
    *(void**)((char*)this + 0x64) = apValue;
}

namespace fnv_00a982d0 {
struct BSFadeNode {
};

// @fnv 0x00a982d0
void* FUN_00a982d0()
{
    void* p = ::operator new(0x94);
    if (p)
        return ((void *)(new ((void *)(((BSFadeNode*)p))) ::FUN_00a981d0()));
    return 0;
}
}  // namespace fnv_00a982d0

struct CloningProcess;
struct NiBinaryExtraData;
struct NiFloatsExtraData;
struct NiExtraData {
    void* p;
};
struct FUN_00a99c40_shell : public NiExtraData {
    void FUN_00a99c40(NiBinaryExtraData* dst, CloningProcess* cp);
};
// @fnv 0x00a99c40
void FUN_00a99c40_shell::FUN_00a99c40(NiBinaryExtraData* dst, CloningProcess* cp)
{
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330((::NiBinaryExtraData *)(dst), cp);
    *(void**)((char*)dst + 0xc) = *(void**)((char*)this + 0xc);
}

struct NiLODData {
    NiLODData();
};
// @fnv 0x00a81fb0
BSFadeNode* FUN_00a81fb0()
{
    BSFadeNode* p = static_cast<BSFadeNode*>(::operator new(0x10));
    if (p) {
        new (static_cast<void*>(p)) NiLODData;
        p->vtbl = &(*reinterpret_cast<const void * *>(&::DAT_0109e47c));
        *(int*)((char*)p + 0xc) = 0;
        return p;
    }
    return 0;
}

// @fnv 0x00a88ac0
unsigned int __cdecl FUN_00a88ac0(unsigned int auiValue)
{
    if (auiValue < 32)
        return 32;
    if (auiValue < 64)
        return 64;
    if (auiValue < 128)
        return 128;
    if (auiValue < 255)
        return 255;
    if (auiValue < 512)
        return 512;
    if (auiValue < 1024)
        return 1024;
    return auiValue + 1;
}

struct NiExtraDataHelper {
};
extern int DAT_0109fb94;
// @fnv 0x00a91fe0
void* __cdecl FUN_00a91fe0()
{
    void* p = ::operator new(0x1c);
    if (p) {
        reinterpret_cast<::ExtraDataObject *>((((NiExtraDataHelper*)p)))->FUN_00a7b2e0();
        *(float*)((char*)p + 0x18) = 0.0f;
        *(uintptr_t*)p = (uintptr_t)&DAT_0109fb94;
        *(float*)((char*)p + 0x14) = 0.0f;
        *(float*)((char*)p + 0x10) = 0.0f;
        *(float*)((char*)p + 0xc) = 0.0f;
        return p;
    }
    return 0;
}

extern int DAT_010a02e4;
struct NiProperty {
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    short m_18;
    short m_1a;
    int m_1c;
    NiProperty();
};
// Allocates a 0x1c-byte NiProperty, constructs it, sets m_18 to 0 and its vtbl to DAT_010a02e4, returning the object or null on allocation failure.
// @fnv 0x00a95160
NiProperty* __cdecl FUN_00a95160()
{
    NiProperty* p = 0;
    if (void* mem = ::operator new(0x1c))
    {
        p = (NiProperty*)mem;
        new ((void *)(p)) struct ::FUN_00a5c200();
        p->m_18 = 0;
        p->vtbl = &DAT_010a02e4;
    }
    else
        return 0;
    return p;
}

struct NiParticleMeshes {
    void* vft;
    int m_kPointA;
    int m_kPointB;
    char m_auiShapeKeys[0xbc];
    char m_flag;
    NiParticleMeshes();
};
// Allocates a 0xcc-byte NiParticleMeshes, calls Init, sets its vtable and m_flag to 1, and returns it (or null on allocation failure).
// @fnv 0x00a98e70
NiParticleMeshes* __cdecl FUN_00a98e70() {
    NiParticleMeshes* p = (NiParticleMeshes*)::operator new(0xcc);
    if (p) {
        new ((void *)(p)) ::NiParticleMeshes();
        p->vft = &DAT_010a0a6c;
        p->m_flag = 1;
        return p;
    }
    return 0;
}

void __cdecl NiFree(void*);
void* __cdecl NiMalloc(unsigned int);
struct FUN_00a99800_shell {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    unsigned int m_iThirdValue;
    void* m_10;
    void AssignPointerArray(unsigned int count, const void* src);
};
// @fnv 0x00a99800
void FUN_00a99800_shell::AssignPointerArray(unsigned int count, const void* src)
{
    NiFree(m_10);
    if (!src || count <= 0) {
        m_iThirdValue = 0;
        m_10 = 0;
    } else {
        m_iThirdValue = count;
        m_10 = NiMalloc(count * 4);
        for (unsigned int i = 0; i < count; ++i)
            ((void**)m_10)[i] = (void*)((const void**)src)[i];
    }
}

extern const void* DAT_010a12cc;


// @fnv 0x00a9b330
void* __cdecl FUN_00a9b330()
{
    void* p = ::operator new(0xf0);
    if (p) {
        new ((void *)(p)) ::FUN_00a71f60_cls();
        *(const void**)p = &DAT_010a12cc;
        ((unsigned char*)p)[0x9d] = 0;
        return p;
    }
    return 0;
}

struct NiAlphaAccumulator {
    NiAlphaAccumulator();
};
// Allocates a 0x34-byte NiAlphaAccumulator, runs its constructor, sets the vtable and initializes bytes at offsets 0x30-0x32, returning the object or null.
// @fnv 0x00a9b4b0
NiAlphaAccumulator* CreateNiAlphaAccumulator()
{
    NiAlphaAccumulator* p = static_cast<NiAlphaAccumulator*>(::operator new(0x34));
    if (p) {
        p->NiAlphaAccumulator::NiAlphaAccumulator();
        *(uintptr_t*)p = (uintptr_t)&kVtbl_NiAlphaAccumulator;
        *(unsigned char*)(p + 0x30) = 1;
        *( char*)(p + 0x31) = 0;
        *( char*)(p + 0x32) = 0;
        return p;
    }
    return 0;
}

struct FUN_00a9be80 {
    const void* m_vft;
    int m_ref;
    int m_data;
    FUN_00a9be80(int data);
};
extern const void* DAT_010a1478;
struct FUN_00a84c90_class {
    char pad[0x44];
    int field44;
    short field48;
    FUN_00a84c90_class* ResetFields();
};

// @fnv 0x00a84c90
FUN_00a84c90_class* FUN_00a84c90_class::ResetFields()
{
    field44 = 0;
    field48 = 0;
    return this;
}

extern unsigned char DAT_011f5fb5;
extern unsigned char DAT_011f5fb6;
extern unsigned char DAT_011f5fb7;
extern unsigned char DAT_011f5fb8;
extern unsigned char DAT_011f5fb9;
extern unsigned char DAT_011f5fba;
extern unsigned char DAT_011f5fbb;
extern unsigned char DAT_011f5fbc;
extern unsigned char DAT_011f5fbd;
extern unsigned char DAT_011f5fbe;
extern unsigned char DAT_011f5fbf;
extern unsigned char DAT_011f5fc0;
extern unsigned char DAT_011f5fc1;
extern int DAT_011f5fc8;
extern int DAT_011f5fcc;
extern int DAT_011f5fd0;
extern int DAT_011f5fd4;
extern int DAT_011f5fd8;
extern int DAT_011f5fdc;
extern int DAT_011f5fe0;
extern int DAT_011f5fe4;
extern int DAT_011f5fe8;
extern int DAT_011f5fec;
extern int DAT_011f5ff0;
extern int DAT_011f5ff4;
extern int DAT_011f5ff8;
extern unsigned char DAT_011f6000;

// @fnv 0x00a9b8b0
void __cdecl FUN_00a9b8b0()
{
    int v = 1;
    int w = 12;
    int x = 13;
    DAT_011f5fc4 = 0;
    DAT_011f5fc8 = v;
    DAT_011f5fcc = 2;
    DAT_011f5fd0 = 3;
    DAT_011f5fd4 = 4;
    DAT_011f5fd8 = 5;
    DAT_011f5fdc = 6;
    DAT_011f5fe0 = 7;
    DAT_011f5fe4 = 8;
    DAT_011f5fe8 = 9;
    DAT_011f5fec = 10;
    DAT_011f5ff0 = 11;
    DAT_011f5ff4 = w;
    DAT_011f5ff8 = x;
    DAT_011f5fb4 = 0;
    DAT_011f5fb5 = v;
    DAT_011f5fb6 = 2;
    DAT_011f5fb7 = 3;
    DAT_011f5fb8 = 4;
    DAT_011f5fb9 = 5;
    DAT_011f5fba = 6;
    DAT_011f5fbb = 7;
    DAT_011f5fbc = 8;
    DAT_011f5fbd = 9;
    DAT_011f5fbe = 10;
    DAT_011f5fbf = 11;
    DAT_011f5fc0 = w;
    DAT_011f5fc1 = x;
    DAT_011f6000 = v;
}

struct FUN_00a85520_class {
    void FUN_00a85520(float* dst, float scale);
};

// Multiplies the nine floats starting at this by scale and writes the results to dst.
// @fnv 0x00a85520
void FUN_00a85520_class::FUN_00a85520(float* afOut, float scale)
{
    *afOut = *(float*)this * scale;
    afOut[1] = ((float*)this)[1] * scale;
    afOut[2] = ((float*)this)[2] * scale;
    afOut[3] = ((float*)this)[3] * scale;
    afOut[4] = ((float*)this)[4] * scale;
    afOut[5] = ((float*)this)[5] * scale;
    afOut[6] = ((float*)this)[6] * scale;
    afOut[7] = ((float*)this)[7] * scale;
    afOut[8] = ((float*)this)[8] * scale;
}

struct FUN_00a87140_class {
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
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
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    char m_cc;
};
// @fnv 0x00a87140
FUN_00a87140_class* FUN_00a87140() {
    FUN_00a87140_class* p = (FUN_00a87140_class*)::operator new(0xd0);
    if (p) {
        new ((void *)(p)) ::FUN_00a744a0();
        p->vtbl = (void*)&DAT_0109e834;
        p->m_c4 = 0;
        p->m_c8 = 0;
        p->m_cc = 0;
    } else {
        p = 0;
    }
    return p;
}

struct NiDirectionalLight {
    void FUN_00a7d6a0(NiDirectionalLight* dst, CloningProcess& cp);
};
struct FUN_00a94c00_shell {
    char m_iWordAt00[0xfc];
    int m_fc;
    int m_100;
    int m_104;
    float m_108;
    float m_10c;
    float m_110;
    void FUN_00a94c00(NiDirectionalLight* dst, CloningProcess& cp);
};
// @fnv 0x00a94c00
void FUN_00a94c00_shell::FUN_00a94c00(NiDirectionalLight* dst, CloningProcess& cp)
{
    ((NiDirectionalLight*)this)->FUN_00a7d6a0(dst, cp);
    FUN_00a94c00_shell* d = (FUN_00a94c00_shell*)dst;
    d->m_fc = m_fc;
    d->m_100 = m_100;
    d->m_104 = m_104;
    d->m_108 = m_108;
    d->m_10c = m_10c;
    d->m_110 = m_110;
}

struct MemoryManager {  };
extern char* DAT_010a05e4;
struct FUN_00a96800_shell {
    char m_auiShapeKeys[0x44];
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void FUN_00a96800();
};
// @fnv 0x00a96800
void FUN_00a96800_shell::FUN_00a96800()
{
    void* pOld = m_4c;
    *(void**)this = &DAT_010a05e4;
    NiFree(pOld);
    NiFree(m_54);
    reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(m_58);
    NiFree(m_5c);
    reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(m_60);
    if (m_44) reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(m_44);
    if (m_48) reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(m_48);
    if (m_64) NiFree(m_64);
    if (m_68) NiFree(m_68);
    reinterpret_cast<::fnv_00a67c70::FUN_00a67c70_shell *>(this)->DestroyGeometryData();
}

extern int DAT_0109e470;
void NiFree(void*);

struct FUN_00a81bd0_class {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void FUN_00a81bd0();
};

// @fnv 0x00a81bd0
void FUN_00a81bd0_class::FUN_00a81bd0()
{
    m_iWordAt00 = &DAT_0109e470;
    NiFree(m_iWordAt04);
    NiFree(m_8);
    NiFree(m_iThirdValue);
    NiFree(m_10);
    NiFree(m_14);
    NiFree(m_18);
}

struct Stub {
};
extern int DAT_0109f73c;
extern int (* DAT_00fdf1c4)(void*);

struct FUN_00a8f810_class {
    void FUN_00a8f810();
};

struct CloningProcess;
struct NiCullingProperty {
    void FUN_00a81430(void* dst, CloningProcess& proc);
};
// @fnv 0x00a81430
void NiCullingProperty::FUN_00a81430(void* dst, CloningProcess& proc)
{
    reinterpret_cast<::FUN_00a5d7a0_shell *>(this)->FUN_00a5d7a0((::NiObjectNET *)dst, (::fnv_00a5c290::CloningProcess *)&proc);
    *(unsigned short*)((char*)dst + 0x18) = *(unsigned short*)((char*)this + 0x18);
}

void __cdecl NiFree(void*);
struct FUN_00a8a670_shell {
    void* m_iWordAt00;
    void* m_iWordAt04;
    void FUN_00a8a670();
};
// @fnv 0x00a8a670
void FUN_00a8a670_shell::FUN_00a8a670()
{
    NiFree(m_iWordAt04);
}

struct NiTFixedStringMap_NiAVObject___ {
    void RemoveAll();
};
extern const void* vftable_SdmDerived;
extern const void* vftable_SdmBase;
void _NiFree(void*);

struct SdmDerived {
    void* m_vt;
    void* m_iWordAt04;
    void* m_8;
    void* FUN_00a8fa10(char flag);
};

// @fnv 0x00a8fa10
void* SdmDerived::FUN_00a8fa10(char flag)
{
    m_vt = (void*)&vftable_SdmDerived;
    ((NiTFixedStringMap_NiAVObject___*)this)->RemoveAll();
    m_vt = (void*)&vftable_SdmBase;
    ((NiTFixedStringMap_NiAVObject___*)this)->RemoveAll();
    _NiFree(m_8);
    if (flag & 1) {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    }
    return this;
}

extern char DAT_0109f9a4[];
extern void __cdecl _NiFree(void*);

struct FUN_00a90260_class
{
    void* m_vft;
    void* m_iWordAt04;

    void* FUN_00a90260(int flags);
};

// @fnv 0x00a90260
void* FUN_00a90260_class::FUN_00a90260(int flags)
{
    void* p = m_iWordAt04;
    m_vft = DAT_0109f9a4;
    _NiFree(p);

    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);

    return this;
}

struct FUN_00a5a390_shell {
    FUN_00a5a390_shell* FUN_00a950f0(bool bDel);
public:
    void FUN_00a5a390();
};
// Calls DestroyFogProperty, then deletes this with size 0x1c if bDel is set, and returns this.
// @fnv 0x00a950f0
FUN_00a5a390_shell* FUN_00a5a390_shell::FUN_00a950f0(bool bDel)
{
    reinterpret_cast<::FUN_00a5c240_shell *>(this)->DestroyFogProperty();
    if (bDel & 1)
        operator delete(this, 0x1c);
    return this;
}

namespace fnv_00a99e00 {
struct NiCullingData {
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};

struct NiCullingProperty {
    char m_auiShapeKeys[0x18];
    unsigned short m_18;
    float m_1c;
    NiCullingData m_20;

    void FUN_00a99e00(void*, CloningProcess&);
};

// Copies this NiCullingProperty's m_18, m_1c and m_20 into the destination after calling FUN_00a5d7a0.
// @fnv 0x00a99e00
void NiCullingProperty::FUN_00a99e00(
    void* destination, CloningProcess& cloningProcess)
{
    NiCullingProperty* dest = static_cast<NiCullingProperty*>(destination);

    reinterpret_cast<::FUN_00a5d7a0_shell *>(this)->FUN_00a5d7a0((::NiObjectNET *)dest, (::fnv_00a5c290::CloningProcess *)&cloningProcess);
    dest->m_18 = m_18;
    dest->m_1c = m_1c;
    dest->m_20 = m_20;
}
}  // namespace fnv_00a99e00

void __cdecl FUN_00a9b8b0();
void __cdecl FUN_00a9b9b0();
// @fnv 0x00a9ba80
void __cdecl FUN_00a9ba80()
{
    FUN_00a9b8b0();
    FUN_00a9b9b0();
}

struct SpawnedRef {
    virtual void Vslot00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};

extern int DAT_0109e04c;

struct FUN_00a80580_sub {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

};

struct FUN_00a80580_cls {
    void* m_vptr;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98;
    FUN_00a80580_sub m_sub9c;
    SpawnedRef* m_b8;
    SpawnedRef* m_bc;

    void FUN_00a80580();
};

// Releases the two SpawnedRef members via reference counting, cleans up m_sub9c, then calls BaseTeardown.
// @fnv 0x00a80580
void FUN_00a80580_cls::FUN_00a80580()
{
    *(void* volatile*)&m_vptr = (void*)&DAT_0109e04c;
    SpawnedRef* first = *(SpawnedRef* volatile*)&m_b8;
    if (first != 0) {
        if (InterlockedDecrement(&first->m_iObjectReferenceCount) == 0) {
            first->DeleteThis();
        }
        m_b8 = 0;
    }
    SpawnedRef* second = m_bc;
    if (second != 0) {
        if (InterlockedDecrement(&second->m_iObjectReferenceCount) == 0) {
            second->DeleteThis();
        }
    }
    SpawnedRef* third = m_b8;
    if (third != 0) {
        if (InterlockedDecrement(&third->m_iObjectReferenceCount) == 0) {
            third->DeleteThis();
        }
    }
    ::fnv_00a89890::ReleaseAllRefs((::fnv_00a89890::ArrStub *)&(m_sub9c));
    reinterpret_cast<::FUN_00a5a390_shell *>(this)->FUN_00a5a390();
}


void FUN_00a5d3d0();

struct FUN_00a80fc0_class {
    void FUN_00a80fc0();
};

// @fnv 0x00a80fc0
void FUN_00a80fc0_class::FUN_00a80fc0() {
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_0109e174);
    FUN_00a5d3d0();
}

extern float DAT_011ab3f8;
static const float kPi = 3.1415927f;
// Computes the angle of the vector (x, y) using a polynomial approximation of atan, handling zero and quadrant cases.
// @fnv 0x00a811f0
float __cdecl FUN_00a811f0(float y, float x)
{
    if (x == 0.0f && y == 0.0f)
        return 0.0f;

    float k = 0.0f;
    float fRatio;
    if ((float)fabs(y) > (float)fabs(x)) {
        fRatio = x / y;
        if (fRatio > 0.0f)
            k = DAT_011ab3f8;
        else if (fRatio < 0.0f)
            k = -DAT_011ab3f8;
        else
            return y > 0.0f ? DAT_011ab3f8 : -DAT_011ab3f8;
    } else {
        fRatio = y / x;
        if (fRatio == 0.0f)
            return x > 0.0f ? 0.0f : kPi;
    }

    float s = fRatio * fRatio;
    float r = 0.0208351f * s;
    r = r - 0.085133f;
    r = r * s;
    r = r + 0.180141f;
    r = r * s;
    r = r - 0.3302995f;
    r = r * s;
    r = r + 0.999866f;
    r = r * fRatio;

    if (k != 0.0f)
        r = k - r;
    if (y < 0.0f && x < 0.0f)
        r -= 3.1415927f;
    if (y > 0.0f && x < 0.0f)
        r += 3.1415927f;
    return r;
}

extern int DAT_0109e32c;

struct FUN_00a81760_obj
{
    void* m_pVTable;
    char unk04[0x54];
    unsigned short m_58;
    unsigned short m_5a;

};

// @fnv 0x00a81760
FUN_00a81760_obj* __cdecl FUN_00a81760()
{
    FUN_00a81760_obj* p = (FUN_00a81760_obj*)FUN_00aa13e0(0x5c);
    if (p != 0)
    {
        new ((void *)(p)) ::FUN_00a7b690();
        p->m_58 = 0;
        p->m_pVTable = (void*)&DAT_0109e32c;
        p->m_5a = 0;
    }
    else
    {
        p = 0;
    }
    return p;
}

struct S_a819e0_O {
virtual ~S_a819e0_O() {}
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
};
// @fnv 0x00a819e0
void FUN_00a819e0() {
    if (DAT_011f5b04) {
        ((S_a819e0_O*)DAT_011f5b04)->v39();
        if (DAT_011f5b04) delete (S_a819e0_O*)DAT_011f5b04;
        DAT_011f5b04 = 0;
    }
}

// FUN_00a81ba0 : constructor of a plain object whose first member is the
// class vtable pointer. Clears the dword fields at +4..+0x18, a word at +0x22
// and a dword at +0x28.

extern int DAT_0109e470;

struct FUN_00a81ba0_cls
{
    void* m_pVTable;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int unk1c;
    unsigned short unk20;
    volatile unsigned short m_22;
    unsigned int unk24;
    unsigned int m_28;

    FUN_00a81ba0_cls();
};

// @fnv 0x00a81ba0
FUN_00a81ba0_cls::FUN_00a81ba0_cls()
{
    m_pVTable = (void*)&DAT_0109e470;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_22 = 0;
    m_28 = 0;
}

struct FUN_00a84c60_cls
{
    unsigned short m_00;
    FUN_00a84c60_cls* FUN_00a84c60();
};

// @fnv 0x00a84c60
FUN_00a84c60_cls* FUN_00a84c60_cls::FUN_00a84c60()
{
    m_00 = 0;
    return this;
}

struct FUN_00a84ca0_entry {
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
    void* unk44;
    int unk48;
};




struct FUN_00a84ca0_class {
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
    void* m_40;
    unsigned int m_44;

    void FreeEntryResources();
};

// Iterates m_44 entries in the array at m_40, deallocating each entry's unk44 pointer and clearing it.
// @fnv 0x00a84ca0
void FUN_00a84ca0_class::FreeEntryResources()
{
    if (m_40 != 0) {
        for (unsigned int i = 0; i < m_44; ++i) {
            reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(
                reinterpret_cast<FUN_00a84ca0_entry*>(m_40)[i].unk44);
            reinterpret_cast<FUN_00a84ca0_entry*>(m_40)[i].unk44 = 0;
        }
    }
}


struct RefCountedObject {
    virtual void UnknownVirtual();
    virtual void DeleteThis();
    volatile long referenceCount;
};

struct CloneObject {
    int unk00;
    int unk04;
    RefCountedObject* first;
    RefCountedObject* second;

    void CopyRefCountedPointers(CloneObject* destination, void* process);
};

// @fnv 0x00a86660
void CloneObject::CopyRefCountedPointers(CloneObject* destination, void* process)
{
    reinterpret_cast<::FUN_00a5d450_class *>(this)->CreateVertexBufferSet((uintptr_t)(destination), process);

    RefCountedObject* previous = destination->first;
    if (previous != first) {
        if (previous && InterlockedDecrement(&previous->referenceCount) == 0) {
            previous->DeleteThis();
        }
        RefCountedObject* replacement = first;
        destination->first = replacement;
        if (replacement) {
            InterlockedIncrement(&replacement->referenceCount);
        }
    }

    previous = destination->second;
    if (previous != second) {
        if (previous && InterlockedDecrement(&previous->referenceCount) == 0) {
            previous->DeleteThis();
        }
        RefCountedObject* replacement = second;
        destination->second = replacement;
        if (replacement) {
            InterlockedIncrement(&replacement->referenceCount);
        }
    }
}

extern int DAT_01069b14;

struct SpawnedObject
{
    void* m_pVTable;
    int unk04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int unk2c;
    int m30;

    void InitBase() throw();
};

// Allocates a 0x34-byte SpawnedObject, runs InitBase, installs the vtable, zeroes most fields, sets m18 to -1, and returns it (or null).
// @fnv 0x00a866f0
SpawnedObject* __cdecl FUN_00a866f0() throw()
{
    SpawnedObject* p = (SpawnedObject*)FUN_00aa13e0(0x34);
    if (p != 0)
    {
        new ((void *)(p)) struct ::FUN_00a5d3a0();
        *(void* volatile*)&p->m_pVTable = (void*)&DAT_01069b14;
        *(int volatile*)&p->m08 = 0;
        *(int volatile*)&p->m0c = 0;
        *(int volatile*)&p->m10 = 0;
        *(int volatile*)&p->m14 = 0;
        *(int volatile*)&p->m1c = 0;
        *(int volatile*)&p->m20 = 0;
        *(int volatile*)&p->m24 = 0;
        *(int volatile*)&p->m28 = 0;
        *(int volatile*)&p->m30 = 0;
        *(int volatile*)&p->m18 = -1;
        return p;
    }
    return 0;
}

// FUN_00a87790: thiscall, 10 bytes.
// Loads the vtable pointer of this, reads the function pointer stored in
// vtable slot 0xdc and tail-jumps to it, forwarding the single stack
// argument of this method.
struct FUN_00a87790_cls
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
    virtual void Tail(int a);
    void FUN_00a87790(std::intptr_t a);
};

// @fnv 0x00a87790
void FUN_00a87790_cls::FUN_00a87790(std::intptr_t a)
{
    this->Tail(a);
}

struct FUN_00a88c60_Point2 {
    float unk00;
    float unk04;

};

struct FUN_00a88c60_Class {
    float unk00;
    float unk04;
    float unk08;
    FUN_00a88c60_Point2 unk0C;
    FUN_00a88c60_Point2 unk14;
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

    int FUN_00a88c60(FUN_00a88c60_Class* other);
};

// @fnv 0x00a88c60
int FUN_00a88c60_Class::FUN_00a88c60(FUN_00a88c60_Class* other) {
    if (unk08 == other->unk08 && unk00 == other->unk00 && unk04 == other->unk04) {
        if (!reinterpret_cast<::NiPoint2_shell *>(&(unk0C))->FUN_0051c330((*(const ::NiPoint2 *)(&other->unk0C))) && unk44 == other->unk44) {
            if (!reinterpret_cast<::NiPoint2_shell *>(&(unk14))->FUN_0051c330((*(const ::NiPoint2 *)(&other->unk14)))) {
                return 0;
            }
        }
    }

    return 1;
}

// @fnv 0x00a89650
void FUN_00a89650(const short* psCompressed, unsigned int uiUnused, float afBase, float fHalfRange, float* pfValues,
                  unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        pfValues[i] = (float)(psCompressed[i] / 32767.0 * fHalfRange + afBase);
}

struct FUN_00a89760_base {
    virtual ~FUN_00a89760_base();
};

struct FUN_00a89760_cls : FUN_00a89760_base {
    virtual ~FUN_00a89760_cls();
};

// @fnv 0x00a89760
FUN_00a89760_cls::~FUN_00a89760_cls()
{
}

struct BaseCls {
};


extern int DAT_0109f23c;

struct FUN_00a8a680_cls {
    void* m_vft;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
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
    void* m_40;
    void* InitWithBuffer(int a0, intptr_t a1, intptr_t a2, intptr_t a3, int a4, int a5, intptr_t a6);
};

// @fnv 0x00a8a680
void* FUN_00a8a680_cls::InitWithBuffer(int ausLength, intptr_t a1, intptr_t a2, intptr_t a3, int a4, int a5, intptr_t apBuffer)
{
    new ((void *)(((BaseCls*)this))) ::FUN_00a67b20(ausLength, (::NiPoint3 *)(a1), (::NiPoint3 *)(0), (::RgbaColor *)(a2), (::NiPoint2 *)(a3), a4, a5);
    m_vft = (void*)&DAT_0109f23c;
    if (apBuffer != 0) {
        m_40 = (void*)apBuffer;
    } else {
        unsigned short usLength = (unsigned short)ausLength;
        m_40 = FUN_00aa1070(usLength);
        for (unsigned short i = 0; i < usLength; i++) {
            ((unsigned char*)m_40)[i] = (unsigned char)((~i) & 1);
        }
    }
    return this;
}

struct DecodePair {unsigned char first,second;};
struct Decoder {
 unsigned int unk00,unk04;
 unsigned char* input;
 unsigned int unk0c;
 DecodePair table[256];
 void DecodeToOutput(unsigned int* output);
};
// Decodes 8 input bytes through the lookup table, writing each pair's two bytes into the output buffer.
// @fnv 0x00a8b4b0
void Decoder::DecodeToOutput(unsigned int* output) {
 for(unsigned int i=0;i<8;++i) {
  *(unsigned char*)output=table[*input].first;
  ++output;
  *(unsigned char*)output=table[*input].second;
  ++output;
  ++input;
 }
}

struct BlockColorDecoder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;

    unsigned int ReadWord()
    {
        unsigned int value = (unsigned short)(cursor[1] * (unsigned short)256 + cursor[0]);
        cursor += 2;
        return value;
    }

    void DecodeBlockColors(unsigned char* output);
};

// Reads two 16-bit words into four RGB colors (two endpoints plus two interpolated), then writes 16 pixels selected by 2-bit indices from the cursor.
// @fnv 0x00a8b8c0
void BlockColorDecoder::DecodeBlockColors(unsigned char* output)
{
    unsigned int first = ReadWord();
    unsigned int second = ReadWord();
    unsigned char colors[4][3];
    colors[0][0] = (first >> 8) & 0xf8;
    colors[0][1] = (first >> 3) & 0xfe;
    colors[0][2] = first << 3;
    colors[1][0] = (second >> 8) & 0xf8;
    colors[1][1] = (second >> 3) & 0xfe;
    colors[1][2] = second << 3;
    colors[2][0] = (2u * colors[0][0] + colors[1][0]) / 3u;
    colors[2][1] = (2u * colors[0][1] + colors[1][1]) / 3u;
    colors[2][2] = (2u * colors[0][2] + colors[1][2]) / 3u;
    colors[3][0] = (colors[0][0] + 2u * colors[1][0]) / 3u;
    colors[3][1] = (colors[0][1] + 2u * colors[1][1]) / 3u;
    colors[3][2] = (colors[0][2] + 2u * colors[1][2]) / 3u;

    for (unsigned int row = 0; row < 4; ++row) {
        unsigned char indices = *cursor;
        for (unsigned int column = 0; column < 4; ++column) {
            unsigned char* color = colors[indices & 3];
            output[0] = *color++;
            output[1] = *color++;
            output[2] = *color;
            output += 4;
            indices >>= 2;
        }
        ++cursor;
    }
}


void DecodeBlockColors();

struct A8BD20Entry {
    unsigned char m_ucLow;
    unsigned char m_ucHigh;
};

class FUN_00a8bd20 {
public:
    int unk00;
    void (*m_pfnCallback)();
    int unk08;
    int unk0C;
    A8BD20Entry m_akTable[256];

    FUN_00a8bd20();
};

// Initializes the object's fields, sets the callback to DecodeBlockColors, and fills a 256-entry table with scaled low/high nibble values.
// @fnv 0x00a8bd20
FUN_00a8bd20::FUN_00a8bd20() {
    double dMax = runtimeInitializationDouble5;
    unk00 = 0;
    m_pfnCallback = DecodeBlockColors;
    unk08 = 0;
    unk0C = 0;
    for (unsigned int i = 0; i < 256; i++) {
        m_akTable[i].m_ucLow = (unsigned char)((float)(i & 0xf) / dMax * 255.0);
        m_akTable[i].m_ucHigh = (unsigned char)((float)((i >> 4) & 0xf) / dMax * 255.0);
    }
}


struct FUN_00a8bdf0_cls {
    void (* m_00)(FUN_00a8bdf0_cls* self, unsigned char* out);
    void (* m_04)(FUN_00a8bdf0_cls* self, unsigned char* out);
    int m_08;
    int m_0c;
    void FUN_00a8bdf0(unsigned char* dst, unsigned int a2, unsigned int count);
};

// Fills a 0x40-byte buffer via m_00 and m_04, then copies a2*4 bytes from it into dst count times, advancing dst by m_0c and src by 0x10 each iteration.
// @fnv 0x00a8bdf0
void FUN_00a8bdf0_cls::FUN_00a8bdf0(unsigned char* dst, unsigned int a2, unsigned int count)
{
    
    unsigned char aucBuffer[0x40];
    unsigned char* src = aucBuffer;
    if (m_00 != 0) {
        m_00(this, &aucBuffer[3]);
    }
    m_04(this, aucBuffer);
    unsigned int size = a2 * 4;
    if (count > 0) {
        unsigned int n = count;
        do {
            std::memmove(dst, src, size);
            dst += m_0c;
            src += 0x10;
        } while (--n != 0);
    }
}

class NiRefObject {
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0) DeleteThis(); }
public:
    static unsigned int ms_lObjectCount;
};
// @fnv 0x00a9be80
FUN_00a9be80::FUN_00a9be80(int data) {
    m_vft = &(*reinterpret_cast<const void * *>(&::DAT_0101dce4));
    m_ref = 0;
    InterlockedIncrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    m_data = data;
    m_vft = &DAT_010a1478;
}
// @fnv 0x00a8f810
void FUN_00a8f810_class::FUN_00a8f810()
{
    *(const void**)this = &DAT_0109f73c;
    Stub* s = (Stub*)DAT_011f5e34;
    reinterpret_cast<::HashTableBase *>((s))->FUN_00aa0250((const unsigned int *)(void *)((char*)this + 8));
    void* p = *(void**)((char*)this + 8);
    int (* fn)(void*) = DAT_00fdf1c4;
    if (p != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
        fn((char*)p - 8);
    *(const void**)this = &(*reinterpret_cast<const void * *>(&::DAT_0101dce4));
    fn((void*)&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
}

class FUN_00a8f140_cls {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    NiRefObject* m_10;

    void SetRefObject(NiRefObject* obj);
};

// Assigns obj to m_10, releasing the previous reference and incrementing the new one's ref count.
// @fnv 0x00a8f140
void FUN_00a8f140_cls::SetRefObject(NiRefObject* obj)
{
    NiRefObject* old = m_10;
    if (old != obj) {
        if (old != 0) {
            old->DecRefCount();
        }
        m_10 = obj;
        if (obj != 0) {
            obj->IncRefCount();
        }
    }
}

namespace fnv_00a8f1c0 {
struct SpawnedRef {
    virtual void Vslot00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};


struct FUN_00a8f1c0_cls {
    void* m_vptr00;
    unsigned int unk04, unk08, unk0C;
    SpawnedRef* m_10;

    void FUN_00a8f1c0();
};

// Sets the vtable, releases the reference at m_10 via an interlocked decrement and deletes it at zero, then calls BaseTeardown.
// @fnv 0x00a8f1c0
void FUN_00a8f1c0_cls::FUN_00a8f1c0() {
    *(void* volatile*)&m_vptr00 = (void*)&(*reinterpret_cast<int *>((void *)&::DAT_0109f4dc));
    SpawnedRef* p = *(SpawnedRef* volatile*)&m_10;
    if (p != 0) {
        if (InterlockedDecrement(&p->m_iObjectReferenceCount) == 0) {
            p->DeleteThis();
        }
    }
    reinterpret_cast<class ::FUN_00a5d3d0 *>(this)->FUN_00a5d3d0::~FUN_00a5d3d0();
}
}  // namespace fnv_00a8f1c0

struct S_00a8f2c0_Arg { int unk00; int unk04; int unk08; int unk0c; };

struct S_00a8f2c0_Sub {
    int unk00;
    void FUN_00a5f860(S_00a8f2c0_Arg* c);
};

struct S_00a8f2c0_Obj {
    void* vft;
    int unk04;
    int unk08;
    int unk0c;
    S_00a8f2c0_Sub sub;
    S_00a8f2c0_Obj() throw() {
        new ((void *)this) struct ::FUN_00a5d3a0();
        vft = (void*)&DAT_0109f4dc;
        unk08 = 0;
        unk0c = 0;
        sub.unk00 = 0;
    }
};

// Allocates an object, stores a and b, then calls the sub-object and object methods with c and returns it; returns 0 if c or c->unk0c is null.
// @fnv 0x00a8f2c0
S_00a8f2c0_Obj* __cdecl CreateFadeNodeFromArg(int aiValueA, int aiValueB, S_00a8f2c0_Arg* c) {
    if (c == 0) return 0;
    if (c->unk0c == 0) return 0;
    S_00a8f2c0_Obj* p = new S_00a8f2c0_Obj();
    p->unk08 = aiValueA;
    p->unk0c = aiValueB;
    p->sub.FUN_00a5f860(c);
    reinterpret_cast<::FUN_00a8f140_cls *>((p))->SetRefObject((::NiRefObject *)(c));
    return p;
}

extern const void* DAT_0109f9bc;
struct FUN_00a910f0_class {
    void* vft;
    void* buffer;
    FUN_00a910f0_class* FUN_00a910f0(unsigned char flags);
};
struct FUN_00aa4060_class {
};
// @fnv 0x00a910f0
FUN_00a910f0_class* FUN_00a910f0_class::FUN_00a910f0(unsigned char flags) {
    vft = &DAT_0109f9bc;
    ::ReleaseObjectArray((::Obj00a47600 **)(buffer));
    if (flags & 1) reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_class *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

namespace fnv_00a91120 {
struct S_a91120_Alloc {  };
struct S_a91120_Blk {
    unsigned char* unk00;
    unsigned int unk04;
    S_a91120_Blk* unk08;
    S_a91120_Blk(unsigned int n) throw() {
        unk04 = n;
        unk08 = 0;
        if (n > 0) unk00 = (unsigned char*)((void *)(::FUN_00a90290(n)));
        else unk00 = 0;
    }
    unsigned char* GetAt(unsigned int i) {
        if (i >= unk04) return 0;
        return unk00 + i * 0x14;
    }
};
struct S_a91120 {
    void** unk00;
    unsigned int unk04;
    unsigned int unk08;
    S_a91120_Blk* unk0c;
    void AppendItems(unsigned int n);
};
// Allocates a block of n items, appends each item pointer to unk00, growing via FUN_00a311e0 when full, then links the block into unk0c.
// @fnv 0x00a91120
void S_a91120::AppendItems(unsigned int n) {
    S_a91120_Blk* pBlock = new S_a91120_Blk(n);
    for (unsigned int i = 0; i < n; i++) {
        unsigned char* item = pBlock->GetAt(i);
        if (unk08 == unk04)
            reinterpret_cast<::FUN_00a311e0_s *>(this)->FUN_00a311e0(unk04 > 0 ? unk04 * 2 : 1);
        unk00[unk08] = item;
        unk08++;
    }
    pBlock->unk08 = unk0c;
    unk0c = pBlock;
}
}  // namespace fnv_00a91120

namespace fnv_00a98240 {
extern "C" const void* DAT_010a08ac;
void __cdecl NiFree(void*);
struct NiRefObject {
    virtual void Reserved();
    virtual void Release();
    volatile long referenceCount;
};
struct NiObjectShell {
    void* volatile vtable;
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
    void* allocation;
    unsigned int capacity;
    unsigned int length;
    unsigned int increment;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    NiRefObject* volatile reference;
    void FUN_00a98240();
};
// @fnv 0x00a98240
void NiObjectShell::FUN_00a98240() {
    vtable = (void*)&DAT_010a08ac;
    NiRefObject* oldReference = reference;
    if (oldReference) {
        if (InterlockedDecrement(&oldReference->referenceCount) == 0)
            oldReference->Release();
        reference = 0;
    }
    if (allocation) {
        NiFree(allocation);
        increment = 0;
        length = 0;
        capacity = 0;
        allocation = 0;
    }
    NiRefObject* lastReference = reference;
    if (lastReference) {
        if (InterlockedDecrement(&lastReference->referenceCount) == 0)
            lastReference->Release();
    }
    vtable = (void*)&(*reinterpret_cast<const void * *>(&::DAT_010a080c));
    reinterpret_cast<class ::FUN_00a5d3d0 *>(this)->FUN_00a5d3d0::~FUN_00a5d3d0();
}
}  // namespace fnv_00a98240

struct NiParticleBase {
    void* vtable;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    unsigned int unknown98;
};
struct NiParticleBuffer {
    void* data;
    unsigned int count;
    unsigned short capacity;
    unsigned short used;
    unsigned short growth;
    unsigned short flags;
};
struct NiParticleSubobject {
    void* first;
    void* second;
    void* third;
    void* fourth;
};
struct NiParticleObject : NiParticleBase {
    NiParticleBuffer buffer;
    NiParticleSubobject firstMember;
    NiParticleSubobject secondMember;
};
// @fnv 0x00a9aea0
NiParticleObject* __cdecl CreateNiParticleObject() {
    NiParticleObject* object =
        (NiParticleObject*)FUN_00aa13e0(0xcc);
    if (object) {
        new ((void *)(object)) ::FUN_00a5ecb0(0);
        object->vtable = (void*)&DAT_010a1024;
        new ((void *)&(object->firstMember)) ::NiPlane();
        new ((void *)&(object->secondMember)) ::NiPlane();
        reinterpret_cast<::NiTObjectArrayA47 *>(&(object->buffer))->FUN_0060bef0(2);
        object->buffer.flags = 0;
        return object;
    }
    return 0;
}



struct FUN_00a9b4a0_Class {
    void FUN_00a9b4a0();
};

// @fnv 0x00a9b4a0
void FUN_00a9b4a0_Class::FUN_00a9b4a0() {
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&(*reinterpret_cast<int *>(&::kVtbl_NiAlphaAccumulator)));
    reinterpret_cast<::C_00aa0dc0 *>(this)->FUN_00aa0dc0();
}

extern unsigned short DAT_011f5f7e;
extern unsigned short DAT_011f5f80;
extern unsigned short DAT_011f5f82;
extern unsigned short DAT_011f5f84;
extern unsigned short DAT_011f5f86;
extern unsigned short DAT_011f5f88;
extern unsigned short DAT_011f5f8a;
extern unsigned short DAT_011f5f8c;
extern int DAT_011f5f94;
extern int DAT_011f5f98;
extern int DAT_011f5f9c;
extern int DAT_011f5fa0;
extern int DAT_011f5fa4;
extern int DAT_011f5fa8;
extern int DAT_011f5fac;
extern int DAT_011f5fb0;
extern unsigned char DAT_011f6001;

// @fnv 0x00a9b9b0
void __cdecl FUN_00a9b9b0()
{
    DAT_011f5f90 = 0;
    DAT_011f5f94 = 1;
    DAT_011f5f7c = 0x0;
    DAT_011f5f7e = 0x100;
    DAT_011f5f80 = 0x200;
    DAT_011f5f82 = 0x300;
    DAT_011f5f84 = 0x400;
    DAT_011f5f86 = 0x500;
    DAT_011f5f88 = 0x600;
    DAT_011f5f98 = 2;
    DAT_011f5f9c = 3;
    DAT_011f5fa0 = 4;
    DAT_011f5fa4 = 5;
    DAT_011f5fa8 = 6;
    DAT_011f5fac = 7;
    DAT_011f5fb0 = 8;
    DAT_011f5f8a = 0x700;
    DAT_011f5f8c = 0x800;
    DAT_011f6001 = 1;
}


struct ReferenceHandle
{
    volatile long* value;
    void operator=(const ReferenceHandle& other)
    {
        volatile long* next = other.value;
        if (value != next) {
            if (next != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
                InterlockedIncrement(next - 2);
            if (value != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
                InterlockedDecrement(value - 2);
            value = next;
        }
    }
};

struct RefCountedPair
{
    unsigned int identifier;
    ReferenceHandle handle;
    RefCountedPair* Assign(const RefCountedPair* other);
};

// Copies the identifier and reference handle from another RefCountedPair into this one and returns this.
// @fnv 0x00a9be30
RefCountedPair* RefCountedPair::Assign(const RefCountedPair* other)
{
    identifier = other->identifier;
    handle = other->handle;
    return this;
}

namespace fnv_00a9fda0 {
struct FUN_00a9fda0_holder {
};

struct FUN_00a9fda0_pair {
    unsigned int m_key;
    uintptr_t m_uiFilterValue;
};


// @fnv 0x00a9fda0
void DestroyPairArrays()
{
    FUN_00a9fda0_pair* arr = DAT_011f602c;
    int (* fp)(void*) = DAT_00fdf1c4;
    if (arr != 0) {
        int i = ((int*)arr)[-1];
        FUN_00a9fda0_pair* p = arr + i;
        if (--i >= 0) {
            do {
                p--;
                uintptr_t value = p->m_uiFilterValue;
                if (value != (uintptr_t)(::DAT_0109b220)) {
                    fp((void*)(value - 8));
                }
            } while (--i >= 0);
        }
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a9fda0::FUN_00a9fda0_holder *>(&::g_memoryManager))))->FUN_00aa4060((void*)((char*)arr - 4));
    }
    FUN_00a9fda0_pair* arr2 = DAT_011f6024;
    DAT_011f602c = 0;
    if (arr2 != 0) {
        int i = ((int*)arr2)[-1];
        FUN_00a9fda0_pair* p = arr2 + i;
        if (--i >= 0) {
            do {
                p--;
                uintptr_t value = p->m_uiFilterValue;
                if (value != (uintptr_t)(::DAT_0109b220)) {
                    fp((void*)(value - 8));
                }
            } while (--i >= 0);
        }
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a9fda0::FUN_00a9fda0_holder *>(&::g_memoryManager))))->FUN_00aa4060((void*)((char*)arr2 - 4));
    }
    DAT_011f6024 = 0;
}
}  // namespace fnv_00a9fda0

struct FUN_00a9ff00_Child
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct FUN_00a9ff00_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00a9ff00_Child* unk10;
};

struct FUN_00a9ff00_Obj
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
    virtual const void* v37(int a, int b, int c);
};


// Validates a and b, reads two fields from a->unk10, calls b->v37 and passes the results to FUN_00a9fe90.
// @fnv 0x00a9ff00
NiDepthStencilBuffer* __cdecl ProcessArgWithObj(FUN_00a9ff00_Arg* a, FUN_00a9ff00_Obj* pObj)
{
    if (a == 0 || pObj == 0)
    {
        return 0;
    }
    int x = a->unk10 != 0 ? a->unk10->unk0C : 0;
    const void* r = pObj->v37(x, 0x20, 8);
    int y = a->unk10 != 0 ? a->unk10->unk10 : 0;
    int w = a->unk0C;
    int u = a->unk08;
    return ::NiDepthStencilBuffer::Create(u, w, (::NiRenderer *)(pObj), (*(const ::NiPixelFormat *)(r)), y);
}


struct FnvRing {
    unsigned int unk00;
    unsigned int m_pRayCursor;
    unsigned int m_pFirstNode;
    unsigned int m_pTail;

    unsigned int Count() const {
        if (m_pFirstNode == 0xffffffffu) {
            return 0;
        }
        if (m_pFirstNode >= m_pTail) {
            return m_pRayCursor - m_pFirstNode + m_pTail;
        }
        return m_pTail - m_pFirstNode;
    }
};

struct FnvQueueState {
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
    virtual void va0(int a, void* p, int b, int c);
    int Probe(int kind);
    unsigned int unk04;
    FnvRing m_r0;
    FnvRing m_r1;
    FnvRing m_r2;
    FnvRing m_r3;
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
    void* m_19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned char m_1b0;
};

// @fnv 0x00a81a80
void __cdecl FUN_00a81a80()
{
    FnvQueueState* s = (FnvQueueState*)DAT_011f5b04;
    if (s == 0) {
        return;
    }
    if (s->m_r0.Count() != 0 || s->m_r1.Count() != 0 ||
        s->Probe(2) != 0 || s->Probe(3) != 0) {
        s->va0(1, &s->m_19c, 0, 0);
    } else {
        FUN_00714900();
    }
    ((FnvQueueState*)DAT_011f5b04)->m_1b0 = 0;
}

class BA87920Base {
public:

    BA87920Base() throw();
    virtual ~BA87920Base();

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

class BA87920Object : public BA87920Base {
public:
    __forceinline BA87920Object()
        : m_pkFirst(0), m_pkSecond(0), m_usA(0), m_usB(0), m_usC(0), m_usD(0), m_usE(0), m_usF(0), m_usG(0), m_bFlag(false)
    {
    }
    virtual ~BA87920Object();

    void* m_pkFirst;
    void* m_pkSecond;
    unsigned short m_usA;
    unsigned short m_usB;
    unsigned short m_usC;
    unsigned short m_usD;
    unsigned short m_usE;
    unsigned short m_usF;
    unsigned short m_usG;
    bool m_bFlag;
};

// Allocates and default-constructs a new BA87920Object, returning the pointer.
// @fnv 0x00a87920
BA87920Object* __cdecl CreateBA87920Object()
{
    return new BA87920Object;
}

extern float g_fRadiansPerRevolution;

struct TexXformPoint2 {
    float x;
    float y;
};

inline void TexXformSinCos(float fRadians, float& fSin, float& fCos)
{
    int iIndex = (int)(512.0 / g_fRadiansPerRevolution * fRadians) & 0x1ff;
    fSin = DAT_011f52e0[iIndex];
    fCos = DAT_011f4ae0[iIndex];
}

struct TexXformMatrix3 {
    float m_afEntries[3][3];
    void SetCol(unsigned int uiCol, float f0, float f1, float f2)
    {
        m_afEntries[0][uiCol] = f0;
        m_afEntries[1][uiCol] = f1;
        m_afEntries[2][uiCol] = f2;
    }
};

struct TexXform {
    TexXformPoint2 m_kTranslate;
    float m_fRotation;
    TexXformPoint2 m_kScaleFactors;
    TexXformPoint2 m_kCenter;
    bool m_bTransform;
    TexXformMatrix3 m_kTransformMatrix;
    int m_eTransformMethod;

    void UpdateMatrix();
};

// @fnv 0x00a88cd0
void TexXform::UpdateMatrix()
{
    float fSin, fCos;
    TexXformSinCos(m_fRotation, fSin, fCos);

    switch (m_eTransformMethod)
    {
    case 0:
        m_kTransformMatrix.SetCol(0, fCos * m_kScaleFactors.x, fSin * m_kScaleFactors.x, 0.0f);
        m_kTransformMatrix.SetCol(1, -fSin * m_kScaleFactors.y, fCos * m_kScaleFactors.y, 0.0f);
        m_kTransformMatrix.SetCol(2,
            (fCos * (m_kTranslate.x - m_kCenter.x) + (-fSin) * (m_kTranslate.y - m_kCenter.y)) + m_kCenter.x,
            fSin * (m_kTranslate.x - m_kCenter.x) + fCos * (m_kTranslate.y - m_kCenter.y) + m_kCenter.y,
            1.0f);
        break;
    case 1:
        m_kTransformMatrix.SetCol(0, fCos * m_kScaleFactors.x, -fSin * m_kScaleFactors.y, 0.0f);
        m_kTransformMatrix.SetCol(1, fSin * m_kScaleFactors.x, fCos * m_kScaleFactors.y, 0.0f);
        m_kTransformMatrix.SetCol(2,
            (fSin * (m_kTranslate.y - m_kCenter.y) + fCos * (-m_kCenter.x - m_kTranslate.x)) * m_kScaleFactors.x + m_kCenter.x,
            (fCos * (m_kTranslate.y - m_kCenter.y) - fSin * (-m_kCenter.x - m_kTranslate.x)) * m_kScaleFactors.y + m_kCenter.y,
            1.0f);
        break;
    case 2:
        m_kTransformMatrix.SetCol(0, fCos * m_kScaleFactors.x, -fSin * m_kScaleFactors.x, 0.0f);
        m_kTransformMatrix.SetCol(1, -fSin * m_kScaleFactors.y, -fCos * m_kScaleFactors.y, 0.0f);
        m_kTransformMatrix.SetCol(2,
            fSin * (1.0f - (m_kTranslate.y + m_kCenter.y)) + fCos * (m_kTranslate.x - m_kCenter.x) + m_kCenter.x,
            fSin * (m_kCenter.x - m_kTranslate.x) + fCos * (1.0f - (m_kTranslate.y + m_kCenter.y)) + m_kCenter.y,
            1.0f);
        break;
    }
    m_bTransform = false;
}

extern int DAT_0109f23c;

struct NiPairHolder {
    void* m_vt;
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
};

// @fnv 0x00a8a700
NiPairHolder* __cdecl CreateNiPairHolder(void)
{
    NiPairHolder* obj = (NiPairHolder*)::operator new(0x44);
    if (obj != 0) {
        new ((void *)(obj)) struct ::FUN_00a67c00();
        obj->m_vt = &DAT_0109f23c;
        obj->unk40 = 0;
        return obj;
    }
    return 0;
}

struct AlphaBlockDecoder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;
    void DecodeAlphaBlock(unsigned char* output);
};

// @fnv 0x00a8b5e0
void AlphaBlockDecoder::DecodeAlphaBlock(unsigned char* output)
{
    unsigned char alphaTable[8];
    unsigned int first = alphaTable[0] = *cursor++;
    unsigned int second = alphaTable[1] = *cursor++;
    if (first > second) {
        alphaTable[2] = (unsigned char)((6 * first + second) / 7);
        alphaTable[3] = (unsigned char)((5 * first + 2 * second) / 7);
        alphaTable[4] = (unsigned char)((4 * first + 3 * second) / 7);
        alphaTable[5] = (unsigned char)((3 * first + 4 * second) / 7);
        alphaTable[6] = (unsigned char)((2 * first + 5 * second) / 7);
        alphaTable[7] = (unsigned char)((first + 6 * second) / 7);
    } else {
        alphaTable[2] = (unsigned char)((4 * first + second) / 5);
        alphaTable[3] = (unsigned char)((3 * first + 2 * second) / 5);
        alphaTable[4] = (unsigned char)((2 * first + 3 * second) / 5);
        alphaTable[5] = (unsigned char)((first + 4 * second) / 5);
        alphaTable[6] = 0;
        alphaTable[7] = 255;
    }
    for (unsigned int group = 0; group < 2; ++group) {
        *output = alphaTable[cursor[0] & 7]; output += 4;
        *output = alphaTable[(cursor[0] >> 3) & 7]; output += 4;
        *output = alphaTable[(cursor[0] >> 6) + ((cursor[1] & 1) << 2)]; output += 4;
        *output = alphaTable[(cursor[1] >> 1) & 7]; output += 4;
        *output = alphaTable[(cursor[1] >> 4) & 7]; output += 4;
        *output = alphaTable[(cursor[1] >> 7) + ((cursor[2] & 3) << 1)]; output += 4;
        *output = alphaTable[(cursor[2] >> 2) & 7]; output += 4;
        *output = alphaTable[cursor[2] >> 5]; output += 4;
        cursor += 3;
    }
}

struct HashNode_cls {
    HashNode_cls* m_pNext;
    uintptr_t m_key;
    uintptr_t m_uiFilterValue;
};

struct SdmBase {
    unsigned int m_unk00;
    unsigned int m_bucketCount;
    HashNode_cls** m_buckets;
};

// Looks up pKey's value in the global hash table's bucket chain and returns the matching node's stored value, or 0 if not found.
// @fnv 0x00a8fe20
uintptr_t __cdecl FUN_00a8fe20(unsigned int* pKey)
{
    uintptr_t key = *(const uintptr_t*)pKey;
    if (key == (uintptr_t)(::DAT_0109b220)) goto zero;
    unsigned int tag = *(unsigned int*)(key - 4);
    if (tag == 0) return tag;
    {
        uintptr_t result = 0;
        unsigned int idx = key % DAT_011f5e34->m_bucketCount;
        HashNode_cls** buckets = DAT_011f5e34->m_buckets;
        HashNode_cls* node = buckets[idx];
        while (node != 0) {
            if (key == node->m_key) {
                result = node->m_uiFilterValue;
                break;
            }
            node = node->m_pNext;
        }
        return result;
    }
zero:
    return 0;
}

extern const void* DAT_0109f7f4;
extern unsigned int DAT_011f5e48;
struct FNVObj {
    const void* vft;
    unsigned int references;
    ReferenceHandle handle;
    FNVObj* FUN_00a8fe70(const ReferenceHandle& src);
};
// Initializes the object's vtable and reference count, copies src into handle, and appends this to the global object array, growing it if full.
// @fnv 0x00a8fe70
FNVObj* FNVObj::FUN_00a8fe70(const ReferenceHandle& src) {
    vft = &(*reinterpret_cast<const void * *>(&::DAT_0101dce4));
    references = 0;
    InterlockedIncrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    vft = &DAT_0109f7f4;
    handle.value = (volatile long*)(*reinterpret_cast<void * *>(&::DAT_0109b220));
    handle = src;
    unsigned int capacity = DAT_011f5e48;
    if (DAT_011f5e4c == capacity) {
        if (capacity > 0)
            capacity += capacity;
        else
            capacity = 1;
        reinterpret_cast<::FUN_00a311e0_s *>((((NiStreamLinkIDSet*)&DAT_011f5e44)))->FUN_00a311e0(capacity);
    }
    ((FNVObj**)DAT_011f5e44)[DAT_011f5e4c] = this;
    ++DAT_011f5e4c;
    return this;
}


struct HandleSlot
{
    volatile long* value;

    void operator=(const ReferenceHandle& other)
    {
        volatile long* next = other.value;
        if (value != next) {
            if (next != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
                InterlockedIncrement(next - 2);
            if (value != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
                InterlockedDecrement(value - 2);
            value = next;
        }
    }
};

struct FUN_00a9bda0
{
    unsigned int identifier;
    HandleSlot handle;

    FUN_00a9bda0(unsigned int id, const ReferenceHandle* src);
};

// Initializes the slot with a default handle, stores the identifier, then copies the handle from src.
// @fnv 0x00a9bda0
FUN_00a9bda0::FUN_00a9bda0(unsigned int id, const ReferenceHandle* src)
{
    *(void* volatile*)&handle.value = (*reinterpret_cast<void * *>(&::DAT_0109b220));
    identifier = id;
    handle = *src;
}

extern int (* DAT_00fdf1c4)(void*);

struct Pair {
    volatile unsigned int id;
    void* volatile value;
    Pair* Reset();
};

// @fnv 0x00a9bdf0
Pair* Pair::Reset()
{
    value = (*reinterpret_cast<void * *>(&::DAT_0109b220));
    id = 0;
    volatile void* old = value;
    if (old) {
        value = ((void *)(::NiGlobalStringTable::AddString((const char *)(0))));
        if (old != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            DAT_00fdf1c4((void*)((char*)old - 8));
    }
    return this;
}


class NiRefObjectA9F {
public:
    virtual ~NiRefObjectA9F() throw();
    virtual void DeleteThis() throw();

    void IncRefCount() throw() { InterlockedIncrement((long volatile*)&m_uiRefCount); }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

template <class T> class NiPointerA9F {
public:
    NiPointerA9F& operator=(T* pObject) throw()
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

    T* m_pObject;
};

class RendererDataA9F : public NiRefObjectA9F {
};

class Ni2DBufferA9F : public NiRefObjectA9F {
public:

    Ni2DBufferA9F() throw();
    virtual ~Ni2DBufferA9F() throw();

    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
    NiPointerA9F<RendererDataA9F> m_pRendererData;
};

class NiDepthStencilBufferA9F : public Ni2DBufferA9F {
public:
    __forceinline NiDepthStencilBufferA9F() throw() {}
    virtual ~NiDepthStencilBufferA9F() throw();

    static NiDepthStencilBufferA9F* FUN_00a9ff60(unsigned int uiWidth, unsigned int uiHeight,
        RendererDataA9F* pkRendererData);
};

// Allocates a NiDepthStencilBufferA9F, stores the width, height and renderer data, and returns it.
// @fnv 0x00a9ff60
NiDepthStencilBufferA9F* NiDepthStencilBufferA9F::FUN_00a9ff60(unsigned int uiWidth, unsigned int uiHeight,
    RendererDataA9F* pkRendererData)
{
    NiDepthStencilBufferA9F* pkBuffer = new NiDepthStencilBufferA9F;
    pkBuffer->m_uiImageWidth = uiWidth;
    pkBuffer->m_uiImageHeight = uiHeight;
    pkBuffer->m_pRendererData = pkRendererData;
    return pkBuffer;
}

struct S{int a; float f;};
// Compares the f fields of two S objects, returning -1 if the first is greater, 1 if smaller, and 0 if equal.
// @fnv 0x00a81b30
int CompareFloatDescending(S* pA, S* pB){ float a=pA->f; float b=pB->f; if(a>b) return -1; if(a<b) return 1; return 0; }

struct CustomBlockDecoder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned char* cursor;

    unsigned short ReadWord()
    {
        unsigned short value = (unsigned short)(cursor[1] * (unsigned short)256 + cursor[0]);
        cursor += 2;
        return value;
    }

    void DecodePaletteBlock(unsigned char* dst);
};

// Reads two 16-bit colors, builds a 16-entry RGBA palette with interpolated entries, then expands 16 two-bit indices from the cursor into dst.
// @fnv 0x00a8bab0
void CustomBlockDecoder::DecodePaletteBlock(unsigned char* pDest)
{
    unsigned char palette[16];
    unsigned short color0 = ReadWord();
    unsigned short color1 = ReadWord();

    palette[0] = (unsigned char)((color0 >> 8) & 0xf8);
    palette[1] = (unsigned char)((color0 >> 3) & 0xfe);
    palette[2] = (unsigned char)(color0 << 3);
    palette[3] = 0xff;

    palette[4] = (unsigned char)((color1 >> 8) & 0xf8);
    palette[5] = (unsigned char)((color1 >> 3) & 0xfe);
    palette[6] = (unsigned char)(color1 << 3);
    palette[7] = 0xff;

    palette[11] = 0xff;

    if (color0 > color1) {
        unsigned int red0 = palette[0];
        unsigned int green0 = palette[1];
        unsigned int red1 = palette[4];
        palette[8] = (unsigned char)((red1 + red0 * 2) / 3u);
        palette[9] = (unsigned char)((palette[5] + green0 * 2) / 3u);
        palette[10] = (unsigned char)((palette[6] + palette[2] * 2) / 3u);

        palette[12] = (unsigned char)((red0 + red1 * 2) / 3u);
        palette[13] = (unsigned char)((green0 + palette[5] * 2) / 3u);
        palette[14] = (unsigned char)((palette[2] + palette[6] * 2) / 3u);
        palette[15] = 0xff;
    } else {
        palette[8] = (unsigned char)((palette[0] + palette[4]) / 2u);
        palette[9] = (unsigned char)((palette[1] + palette[5]) / 2u);
        palette[10] = (unsigned char)((palette[2] + palette[6]) / 2u);

        palette[12] = palette[8];
        palette[13] = palette[9];
        palette[14] = palette[10];
        palette[15] = 0;
    }

    for (int row = 0; row < 4; ++row) {
        unsigned char b = *cursor;
        for (int k = 0; k < 4; ++k) {
            unsigned char* p = &palette[(b & 3) * 4];
            pDest[0] = *p++;
            pDest[1] = *p++;
            pDest[2] = *p++;
            pDest[3] = *p++;
            pDest += 4;
            b >>= 2;
        }
        cursor++;
    }
}

struct NiBinaryStream {
 void* vtable;
 unsigned int position;
 unsigned int (__cdecl *read)(NiBinaryStream*,void*,unsigned int,unsigned int*,unsigned int);
 void Read(void* data,unsigned int bytes) { unsigned int uiComponentSize = 1; position += read(this,data,bytes,&uiComponentSize,1); }
};
struct RleDecoder {
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
 unsigned short unk10c,count;
 unsigned int unk110;
 unsigned char stride,unk115,unk116,unk117;
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
 unsigned int run;
 bool repeat;
 unsigned char value0,value1,value2;
 unsigned char value3;
 void Decode(NiBinaryStream& stream, unsigned char* dest,unsigned int unused);
};
// @fnv 0x00a8d8e0
void RleDecoder::Decode(NiBinaryStream& stream,unsigned char* dest,unsigned int unused) {
 unsigned int i=0, n;
 for(; i < count; i += n) {
  if(run==0) {
   unsigned char ucPacketHeader=0;
   stream.Read(&ucPacketHeader,1);
   repeat=(ucPacketHeader & 128)!=0;
   if(ucPacketHeader & 128) {
    run=(unsigned int)ucPacketHeader-127;
    repeat=true;
    stream.Read(&value0,stride);
   } else {
    repeat=false;
    run=(unsigned int)ucPacketHeader+1;
   }
  }
  n=count-i;
  if(run<n) n=run;
  if(repeat) {
   for(unsigned int j=0;j<n;++j) {
    std::memmove(dest,&value0,stride);
    dest+=stride;
   }
  } else {
   stream.Read(dest,stride*n);
   dest+=stride*n;
  }
  run-=n;
 }
}

// 0x00a85510  ret 0x20
// @fnv 0x00a85510
void FUN_00a85510(intptr_t, intptr_t, intptr_t, intptr_t, intptr_t, int, intptr_t, intptr_t) {
}

// @fnv 0x00a877d0
void __cdecl FUN_00a877d0() {
    FUN_00a98ea0();
}


// @fnv 0x00a877e0
void __cdecl FUN_00a877e0()
{
    ::FUN_00a71d10();
}

// @fnv 0x00a88a40
void __cdecl FUN_00a88a40()
{
    static_cast<::FUN_00a5d610_Object *>(nullptr)->ReadGroup({});
}

// 0x00a89af0  ret 4
// @fnv 0x00a89af0
void FUN_00a89af0(intptr_t) {
}

struct S_00a8d8b0;
struct FUN_00a5e3a0_Helper {  };
struct PixelRow4 {
    unsigned char rgba[4];
    PixelRow4() {}
};
struct ImageConverter {
    unsigned int unknown000;
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    unsigned int unknown0d0;
    unsigned int unknown0d4;
    unsigned int unknown0d8;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned short unknown104;
    unsigned short pixelCount;
    unsigned char bitsPerPixel;
    unsigned char unknown109;
    unsigned short unknown10a;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    unsigned int unknown150;
    unsigned int unknown154;
    unsigned int unknown158;
    unsigned int unknown15c;
    unsigned int inputCapacity;
    unsigned char* inputBuffer;
    unsigned int outputCapacity;
    PixelRow4* outputBuffer;
    void ReadPixels(S_00a8d8b0* stream);
};
// Grows the output and input buffers to fit pixelCount, reads pixel data from the stream by bitsPerPixel, and expands it into RGBA rows in outputBuffer.
// @fnv 0x00a8da50
void ImageConverter::ReadPixels(S_00a8d8b0* stream)
{
    if (outputCapacity < pixelCount) {
        outputCapacity = pixelCount;
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(outputBuffer);
        outputBuffer = new PixelRow4[outputCapacity];
    }
    if (inputCapacity < (unsigned int)pixelCount * 4) {
        inputCapacity = (unsigned int)pixelCount * 4;
        NiFree(inputBuffer);
        inputBuffer = (unsigned char*)FUN_00aa1070(inputCapacity);
    }
    unsigned char* out = (unsigned char*)outputBuffer;
    switch (bitsPerPixel) {
    case 8: {
        unsigned char* in = inputBuffer;
        AdvancePosition(stream, in, pixelCount);
        for (unsigned int i = 0; i < pixelCount; ++i) {
            out[0] = out[1] = out[2] = *in;
            out[3] = 255;
            out += 4;
            ++in;
        }
        break;
    }
    case 15:
    case 16: {
        unsigned char* in = inputBuffer;
        AdvancePosition(stream, in, pixelCount * 2);
        for (unsigned int i = 0; i < pixelCount; ++i) {
            out[0] = (in[1] & 0xfc) << 1;
            out[1] = ((in[0] >> 2) & 0x38) + (in[1] << 6);
            out[2] = in[0] << 3;
            out[3] = 255;
            out += 4;
            in += 2;
        }
        break;
    }
    case 24: {
        unsigned char* in = inputBuffer;
        AdvancePosition(stream, in, pixelCount * 3);
        for (unsigned int i = 0; i < pixelCount; ++i) {
            out[2] = *in++;
            out[1] = *in++;
            out[0] = *in++;
            out[3] = 255;
            out += 4;
        }
        break;
    }
    case 32: {
        unsigned char* in = inputBuffer;
        AdvancePosition(stream, in, pixelCount * 4);
        for (unsigned int i = 0; i < pixelCount; ++i) {
            out[2] = *in++;
            out[1] = *in++;
            out[0] = *in++;
            out[3] = *in++;
            out += 4;
        }
        break;
    }
    }
}

inline NiRefObject::~NiRefObject() {
    InterlockedDecrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
}
struct StringHandle_a8f {
    volatile long* value;
    ~StringHandle_a8f() throw() {
        if (value != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            InterlockedDecrement(value - 2);
    }
};
class FUN_00a8f490 : public NiRefObject {
public:
    virtual ~FUN_00a8f490();
    StringHandle_a8f m_08;
};
// Destructor of a NiRefObject-derived class holding a StringHandle_a8f member; the member's destructor releases the string reference.
// @fnv 0x00a8f490
FUN_00a8f490::~FUN_00a8f490() {
}

struct FUN_00a923a0_class {
    unsigned short FUN_00a923a0();
};

// @fnv 0x00a923a0
unsigned short FUN_00a923a0_class::FUN_00a923a0()
{
    return *reinterpret_cast<unsigned short*>(this + 0x50);
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

#include <math.h>
extern "C" float epsilon;
struct FUN_00a88970_q { float w, x, y, z;  };
struct FUN_00a88970_v { void* m_pvVtbl; float x, y, z; };
// @fnv 0x00a88970
FUN_00a88970_q FUN_00a88970(const FUN_00a88970_v& v)
{
    float fScaleMultiplier = v.x * v.x + v.y * v.y + v.z * v.z;
    fScaleMultiplier = sqrt(fScaleMultiplier);
    float fAngleDifference = fScaleMultiplier;
    float fSin, fCos;
    fnv_SinCos(fAngleDifference, fSin, fCos);
    float fScale = fabs(fSin);
    if (fScale < epsilon) fScale = 1.0f; else fScale = fSin / fAngleDifference;
    FUN_00a88970_q q;
    reinterpret_cast<::FUN_00a6db50_V *>(&(q))->Set(fCos, v.x * fScale, v.y * fScale, v.z * fScale);
    return q;
}

struct FUN_00a81a40_shell {
    int FUN_00a81a40(int ai);
};

// Reads the 16-byte slot at this+8+ai*16; returns 0 if its +8 value is -1, otherwise a difference built from its +4, +8 and +12 values.
// @fnv 0x00a81a40
int FUN_00a81a40_shell::FUN_00a81a40(int ai)
{
    char* pSlot = (char*)this + 8 + ai * 16;
    int value = *(int*)(pSlot + 8);
    return value == -1 ? 0
        : ((unsigned)value >= (unsigned)*(int*)(pSlot + 12)
        ? *(int*)(pSlot + 4) - value + *(int*)(pSlot + 12)
        : *(int*)(pSlot + 12) - value);
}

void* NiMalloc(unsigned int uiSize);

struct FUN_00a8a620 {
    unsigned int m_uiSize;
    void* m_pBuffer;
    void* m_pCursor;
    int m_iUsed;

    FUN_00a8a620(unsigned int uiSize);
};
// Initializes the buffer size, allocates m_pBuffer with NiMalloc if uiSize is non-zero, sets m_pCursor to m_pBuffer, and resets m_iUsed to 0.
// @fnv 0x00a8a620
FUN_00a8a620::FUN_00a8a620(unsigned int uiSize)
{
    m_uiSize = uiSize;
    if (uiSize)
        m_pBuffer = NiMalloc(uiSize);
    else
        m_pBuffer = 0;
    m_pCursor = m_pBuffer;
    m_iUsed = 0;
}

struct ByteDecoder {
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
    unsigned char bias;
    unsigned char unk105;
    unsigned short unk106;
    unsigned int unk108;
    unsigned short unk10c;
    unsigned short count;

    void DecodeBytes(unsigned char* src, unsigned char* dst);
};

// Subtracts bias from each of count/2 source bytes and writes the results to dst.
// @fnv 0x00a8d460
void ByteDecoder::DecodeBytes(unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < (count >> 1); i++) {
        unsigned char b = *src++ - bias;
        *dst++ = b;
    }
}

#include <string.h>
#include <cstddef>
#include "fnv/decl/ActiveArray.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00a826b0_shell.h"
#include "fnv/decl/NormalizedWeights.h"
#include "fnv/decl/SkinBuilder.h"
#include "fnv/decl/SkinWeights__Processor.h"
#include "fnv/decl/Skp_00a828d0_cls.h"
#include "fnv/symbols_00a81000.h"
#include "fnv/symbols_00a84000.h"
#include "fnv/symbols_00a86000.h"
#include "fnv/symbols_00a87000.h"
#include "fnv/symbols_00a8f000.h"
#include "fnv/symbols_00a91000.h"
#include "fnv/symbols_00a95000.h"
#include "fnv/symbols_00a9a000.h"
#include "fnv/symbols_00a9b000.h"
#include "fnv/symbols_00a9f000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_00a85000.h"
#include "fnv/symbols_00a88000.h"
#include "fnv/symbols_00a8a000.h"
// Returns 1 if a is null, -1 if b is null, otherwise returns the result of comparing the two strings pointed to by a and b.
// @fnv 0x00a86280
int __cdecl FUN_00a86280(const char** apStrA, const char** apStrB)
{
    if (apStrA == 0)
        return 1;

    if (apStrB == 0)
        return -1;

    return strcmp(*apStrA, *apStrB);
}

struct StaticKeyB5542 {
    StaticKeyB5542(int v) throw() { m_00 = v; }
    ~StaticKeyB5542() throw() {}
    unsigned int m_00;
};

class NiRefStubB5542 {
public:
    virtual void Slot0();
    virtual void Destroy();
    long m_iObjectReferenceCount;
};

class FUN_00a9ba90_cls {
public:
    unsigned int unk00;
    NiRefStubB5542** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void FUN_00a9ba90(unsigned int idx, NiRefStubB5542** a2);
};

// Sets the NiRefStub at idx, updating m_0a/m_0c and swapping the reference with ref-counted destroy/increment.
// @fnv 0x00a9ba90
void FUN_00a9ba90_cls::FUN_00a9ba90(unsigned int idx, NiRefStubB5542** apRefStub) {
    static StaticKeyB5542 key(0);
    if (idx >= m_0a) {
        m_0a = (unsigned short)(idx + 1);
        if ((uintptr_t)*apRefStub == key.m_00) {
        } else {
            m_0c++;
        }
    } else {
        if ((uintptr_t)*apRefStub != key.m_00) {
            if ((uintptr_t)m_04[idx] == key.m_00) {
                m_0c++;
            }
        } else {
            if ((uintptr_t)m_04[idx] != key.m_00) {
                m_0c--;
            }
        }
    }
    NiRefStubB5542** slot = &m_04[idx];
    NiRefStubB5542* old = *slot;
    if (old != *apRefStub) {
        if (old != 0) {
            if (InterlockedDecrement(&old->m_iObjectReferenceCount) == 0) {
                old->Destroy();
            }
        }
        NiRefStubB5542* pNew = *apRefStub;
        *slot = pNew;
        if (pNew != 0) {
            InterlockedIncrement(&pNew->m_iObjectReferenceCount);
        }
    }
}

struct BitmapStreamVtable {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void (* seek)(NiBinaryStream*, int);
};
extern void (* DAT_00fdf05c)(void*);
extern void (* DAT_00fdf100)(void*);
class NiPixelFormat {
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
    NiPixelFormat();
    bool operator==(const NiPixelFormat&) const;
};
struct BitmapReader {
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
    unsigned int width;
    unsigned int height;
    NiPixelFormat format;
    unsigned short bitsPerPixel;
    unsigned short unk14e;
    unsigned int colorsUsed;
    unsigned int pixelOffset;
    bool bottomUp;
    bool ReadBitmapHeader(NiBinaryStream& stream, unsigned int& outWidth,
        unsigned int& outHeight, NiPixelFormat& outFormat, bool& outFlag, unsigned int& outMips);
};
template<class T> inline void ReadValue(NiBinaryStream& stream, T& value) {
    unsigned int componentSize = sizeof(T);
    stream.position += stream.read(&stream, &value, sizeof(T), &componentSize, 1);
}
// @fnv 0x00a8e4b0
bool BitmapReader::ReadBitmapHeader(NiBinaryStream& stream, unsigned int& outWidth,
    unsigned int& outHeight, NiPixelFormat& outFormat, bool& outFlag, unsigned int& outMips)
{
    ((BitmapStreamVtable*)stream.vtable)->seek(&stream, 0);
    outMips = 1;
    unsigned short signature;
    ReadValue(stream, signature);
    if (signature != 0x4d42)
        return false;
    DAT_00fdf05c(&unk080);
    unsigned int fileSize;
    ReadValue(stream, fileSize);
    ReadValue(stream, signature);
    ReadValue(stream, signature);
    ReadValue(stream, pixelOffset);
    unsigned int headerSize;
    int imageWidth, imageHeight;
    unsigned int compression;
    int resolution;
    ReadValue(stream, headerSize);
    ReadValue(stream, imageWidth);
    ReadValue(stream, imageHeight);
    ReadValue(stream, signature);
    ReadValue(stream, bitsPerPixel);
    ReadValue(stream, compression);
    ReadValue(stream, fileSize);
    ReadValue(stream, resolution);
    ReadValue(stream, resolution);
    ReadValue(stream, colorsUsed);
    ReadValue(stream, fileSize);
    if (headerSize == 4) {
        DAT_00fdf100(&unk080);
        return false;
    }
    switch (bitsPerPixel) {
    case 4:
    case 8: format = (*reinterpret_cast<const ::NiPixelFormat *>((void *)&::DAT_011aa210)); break;
    case 24: format = DAT_011aa2e8; break;
    case 32: format = (*reinterpret_cast<const ::NiPixelFormat *>(&::gNiPoint3StartupSrc)); break;
    default:
        DAT_00fdf100(&unk080);
        return false;
    }
    if (compression == 2 || compression == 1) {
        DAT_00fdf100(&unk080);
        return false;
    }
    width = imageWidth;
    bottomUp = imageHeight >= 0;
    height = imageHeight > 0 ? imageHeight : -imageHeight;
    if (colorsUsed == 0 && bitsPerPixel != 24 && bitsPerPixel != 32)
        colorsUsed = 1 << bitsPerPixel;
    outWidth = width;
    outHeight = height;
    outFormat = format;
    outFlag = true;
    DAT_00fdf100(&unk080);
    return true;
}

class NiPoint3 {
public:
    float x, y, z;
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
float Readx() const { return x; }
float Ready() const { return y; }
    NiPoint3() {}
    NiPoint3(float a, float b, float c) { x=a; y=b; z=c; }
    NiPoint3 operator*(float s) const {
        NiPoint3 p; p.x=s*x; p.y=s*y; p.z=s*z; return p;
    }
    NiPoint3& operator+=(const NiPoint3& p) {
        x += p.x; y += p.y; z += p.z;
        return *this;
    }
 void AddByValue(NiPoint3 p) {x += p[0]; y += p[1]; z += p[2];}


public:
    static const ::NiPoint3 ZERO;
};
class ThreeByThreeMatrix {
public:
    float m[3][3];
    ThreeByThreeMatrix() {}
    ThreeByThreeMatrix(const ThreeByThreeMatrix& o) {
        m[0][0]=o.m[0][0];
        m[0][1]=o.m[0][1];
        m[0][2]=o.m[0][2];
        m[1][0]=o.m[1][0];
        m[1][1]=o.m[1][1];
        m[1][2]=o.m[1][2];
        m[2][0]=o.m[2][0];
        m[2][1]=o.m[2][1];
        m[2][2]=o.m[2][2];
    }
    float Entry(unsigned int row, unsigned int col) const { return m[row][col]; }
    ThreeByThreeMatrix operator*(float s) const {
        ThreeByThreeMatrix r;
        r.m[0][0] = Entry(0,0) * s;
        r.m[0][1] = Entry(0,1) * s;
        r.m[0][2] = Entry(0,2) * s;
        r.m[1][0] = Entry(1,0) * s;
        r.m[1][1] = Entry(1,1) * s;
        r.m[1][2] = Entry(1,2) * s;
        r.m[2][0] = Entry(2,0) * s;
        r.m[2][1] = Entry(2,1) * s;
        r.m[2][2] = Entry(2,2) * s;
        return r;
    }
    NiPoint3 operator*(const NiPoint3& p) const {
        return NiPoint3(
            m[0][0]*p.x + m[0][1]*p.y + m[0][2]*p.z,
            m[1][0]*p.x + m[1][1]*p.y + m[1][2]*p.z,
            m[2][0]*p.x + m[2][1]*p.y + m[2][2]*p.z);
    }
    NiPoint3 MulAddFirst(const NiPoint3& p, const NiPoint3& t) const {
        return NiPoint3(
            Entry(0,0)*p.Readx() + Entry(0,1)*p.Ready() + Entry(0,2)*p.z + t.x,
            ((Entry(1,0)*p.Readx() + Entry(1,1)*p.Ready()) + Entry(1,2)*p.z + t.y),
            Entry(2,0)*p.Readx() + Entry(2,1)*p.Ready() + Entry(2,2)*p.z + t.z);
    }
    NiPoint3 MulAddSecond(const NiPoint3& p, const NiPoint3& t) const {
        return NiPoint3(
            Entry(0,0)*p.Readx() + Entry(0,1)*p.Ready() + Entry(0,2)*p.z + t.x,
            Entry(1,0)*p.Readx() + (Entry(1,1)*p.Ready()) + Entry(1,2)*p.z + t.y,
            (Entry(2,0)*p.Readx() + Entry(2,1)*p.Ready()) + Entry(2,2)*p.z + t.z);
    }
};
static __forceinline ThreeByThreeMatrix operator*(float s, const ThreeByThreeMatrix& m) { return m*s; }
static __forceinline void XformZ(const ThreeByThreeMatrix& m, const float& x, const float& y, const float& z, const NiPoint3& t, NiPoint3& r) {
        r.x = m.Entry(0,0)*x + m.Entry(0,1)*y + m.Entry(0,2)*z + t.x;
        r.y = m.Entry(1,0)*x + (m.Entry(1,1)*y) + m.Entry(1,2)*z + t.y;
        r.z = m.Entry(2,0)*x + (m.Entry(2,1)*y) + m.Entry(2,2)*z + t.z;
}
struct NiTransform {
    ThreeByThreeMatrix rotate;
    NiPoint3 translate;
    float scale;
    NiTransform operator*(const NiTransform&) const;
public:
    void CalculateInverse(::NiTransform &);
};
struct SkinObject {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64;
    NiTransform world;
    const NiTransform& GetWorld() const { return world; }
};
struct SkinData {
    struct Weight {
        unsigned short vertex;
        unsigned short unk02;
        float weight;
    };
    struct Bone {
        NiTransform skinToBone;
        NiPoint3 center;
        float radius;
        Weight* weights;
        unsigned short count;
        unsigned short unk4a;
    };
    void* vtable;
    unsigned int refs;
    void* partition;
    NiTransform rootToSkin;
    Bone* bones;
    unsigned int count;
    const NiTransform& GetRootToSkin() const { return rootToSkin; }
    const Bone* GetBones() const { return bones; }
    unsigned int GetCount() const { return count; }
};
template<class T> struct SkinPointer {
    T* ptr;
    T* operator->() const { return ptr; }
};
struct SkinInstance {
    void* vtable;
    unsigned int refs;
    SkinPointer<SkinData> data;
    void* partition;
    SkinObject* root;
    SkinObject** bones;
    void FUN_00a855f0(const NiPoint3* positions, const NiPoint3* normals,
        unsigned int count, NiPoint3* dstPos, NiPoint3* dstNorm,
        NiPoint3* dstTan, NiPoint3* dstBin, unsigned int stride) const;
};
// Applies per-bone weighted transforms to positions, normals, tangents and binormals, accumulating results into the destination arrays.
// @fnv 0x00a855f0
void SkinInstance::FUN_00a855f0(const NiPoint3* positions, const NiPoint3* normals,
    unsigned int count, NiPoint3* dstPos, NiPoint3* dstNorm,
    NiPoint3* dstTan, NiPoint3* dstBin, unsigned int stride) const
{
    NiTransform rootTransform;
    reinterpret_cast<::NiTransform *>((void *)&(root->GetWorld()))->CalculateInverse((*(::NiTransform *)(&rootTransform)));
    rootTransform = data->GetRootToSkin() * rootTransform;
    const SkinData::Bone* boneData = data->GetBones();
    unsigned int boneCount = data->GetCount();
    unsigned int boneIndex;
    NiTransform boneTransform;
    ThreeByThreeMatrix scaledRotation;
    unsigned short vertexIndex;
    if (normals && dstNorm) {
        if (dstTan && dstBin) {
            const NiPoint3* tangents = normals + count;
            const NiPoint3* binormals = tangents + count;
            if (stride == sizeof(NiPoint3)) {
                std::memset(dstPos, 0, count * sizeof(NiPoint3));
                std::memset(dstNorm, 0, count * sizeof(NiPoint3));
                std::memset(dstTan, 0, count * sizeof(NiPoint3));
                std::memset(dstBin, 0, count * sizeof(NiPoint3));
            } else {
                NiPoint3* p = dstPos;
                NiPoint3* n = dstNorm;
                NiPoint3* t = dstTan;
                NiPoint3* b = dstBin;
                for (unsigned int i = 0; i < count; ++i) {
                    *p = ::NiPoint3::ZERO;
                    p = (NiPoint3*)((char*)p + stride);
                    *n = ::NiPoint3::ZERO;
                    n = (NiPoint3*)((char*)n + stride);
                    *t = ::NiPoint3::ZERO;
                    t = (NiPoint3*)((char*)t + stride);
                    *b = ::NiPoint3::ZERO;
                    b = (NiPoint3*)((char*)b + stride);
                }
            }
            for (boneIndex = 0; boneIndex < boneCount; ++boneIndex) {
                NiPoint3 p, n, t, b;
                const SkinData::Bone& bone = boneData[boneIndex];
                unsigned int vertexCount = bone.count;
                boneTransform = rootTransform * bones[boneIndex]->GetWorld() * bone.skinToBone;
                scaledRotation = boneTransform.scale * boneTransform.rotate;
                const SkinData::Weight* weights = bone.weights;
                for (unsigned int j = 0; j < vertexCount; ++j) {
                    const SkinData::Weight& w = weights[j];
                    vertexIndex = w.vertex;
                    float weight = w.weight;
                    unsigned int offset = vertexIndex * stride;
                    p = scaledRotation.MulAddFirst(positions[vertexIndex], boneTransform.translate);
                    {
                    n.x = boneTransform.rotate.Entry(0, 0) * normals[vertexIndex].Readx() + boneTransform.rotate.Entry(0, 1) * normals[vertexIndex].y + boneTransform.rotate.Entry(0, 2) * normals[vertexIndex].z;
                    n.y = boneTransform.rotate.Entry(1, 0) * normals[vertexIndex].x + boneTransform.rotate.Entry(1, 1) * normals[vertexIndex].y + boneTransform.rotate.Entry(1, 2) * normals[vertexIndex].z;
                    n.z = boneTransform.rotate.Entry(2, 0) * normals[vertexIndex].x + boneTransform.rotate.Entry(2, 1) * normals[vertexIndex].Ready() + boneTransform.rotate.Entry(2, 2) * normals[vertexIndex].z;
                    }
                    t = boneTransform.rotate * tangents[vertexIndex];
                    b = boneTransform.rotate * binormals[vertexIndex];
                    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(*(NiPoint3*)((char*)dstPos + offset)))->FUN_0063c8a0((void *)&(const ::NiPoint3 &)(p * weight));
                    ((NiPoint3*)((char*)dstNorm + offset))->AddByValue(n * weight);
                    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(*(NiPoint3*)((char*)dstTan + offset)))->FUN_0063c8a0((void *)&(const ::NiPoint3 &)(t * weight));
                    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(*(NiPoint3*)((char*)dstBin + offset)))->FUN_0063c8a0((void *)&(const ::NiPoint3 &)(b * weight));
                }
            }
            NormalizePoints(dstNorm, count, stride);
            NormalizePoints(dstTan, count, stride);
            NormalizePoints(dstBin, count, stride);
            return;
        }
        if (stride == sizeof(NiPoint3)) {
            std::memset(dstPos, 0, count * sizeof(NiPoint3));
            std::memset(dstNorm, 0, count * sizeof(NiPoint3));
        } else {
            NiPoint3* p = dstPos;
            NiPoint3* n = dstNorm;
            for (unsigned int i = 0; i < count; ++i) {
                *p = ::NiPoint3::ZERO;
                p = (NiPoint3*)((char*)p + stride);
                *n = ::NiPoint3::ZERO;
                n = (NiPoint3*)((char*)n + stride);
            }
        }
        for (boneIndex = 0; boneIndex < boneCount; ++boneIndex) {
            NiPoint3 p, n;
            const SkinData::Bone& bone = boneData[boneIndex];
            unsigned int vertexCount = bone.count;
            boneTransform = rootTransform * bones[boneIndex]->GetWorld() * bone.skinToBone;
            scaledRotation = boneTransform.rotate * boneTransform.scale;
            const SkinData::Weight* weights = bone.weights;
            const NiPoint3& translate = boneTransform.translate;
            for (unsigned int j = 0; j < vertexCount; ++j) {
                vertexIndex = weights[j].vertex;
                float weight = weights[j].weight;
                unsigned int offset = vertexIndex * stride;
                p = scaledRotation.MulAddSecond(positions[vertexIndex], translate);
                    {
                    n.x = boneTransform.rotate.Entry(0, 0) * normals[vertexIndex].x + boneTransform.rotate.Entry(0, 1) * normals[vertexIndex].y + boneTransform.rotate.Entry(0, 2) * normals[vertexIndex].z;
                    n.y = boneTransform.rotate.Entry(1, 0) * normals[vertexIndex].x + boneTransform.rotate.Entry(1, 1) * normals[vertexIndex].y + boneTransform.rotate.Entry(1, 2) * normals[vertexIndex].z;
                    n.z = boneTransform.rotate.Entry(2, 0) * normals[vertexIndex].x + boneTransform.rotate.Entry(2, 1) * normals[vertexIndex].y + boneTransform.rotate.Entry(2, 2) * normals[vertexIndex].z;
                    }
                reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(*(NiPoint3*)((char*)dstPos + offset)))->FUN_0063c8a0((void *)&(const ::NiPoint3 &)(p * weight));
                ((NiPoint3*)((char*)dstNorm + offset))->AddByValue(n * weight);
            }
        }
        NormalizePoints(dstNorm, count, stride);
        return;
    }
    if (stride == sizeof(NiPoint3)) {
        std::memset(dstPos, 0, count * sizeof(NiPoint3));
    } else {
        NiPoint3* p = dstPos;
        for (unsigned int i = 0; i < count; ++i) {
            *p = ::NiPoint3::ZERO;
            p = (NiPoint3*)((char*)p + stride);
        }
    }
    for (boneIndex = 0; boneIndex < boneCount; ++boneIndex) {
        NiPoint3 p;
        const SkinData::Bone& bone = boneData[boneIndex];
        unsigned int vertexCount = bone.count;
        boneTransform = rootTransform * bones[boneIndex]->GetWorld() * bone.skinToBone;
        scaledRotation = boneTransform.scale * boneTransform.rotate;
        const SkinData::Weight* weights = bone.weights;
        const NiPoint3& translate = boneTransform.translate;
        for (unsigned int j = 0; j < vertexCount; ++j) {
            const SkinData::Weight& w = weights[j];
            unsigned short vertexIndex = w.vertex;
            float weight = w.weight;
            unsigned int offset = vertexIndex * stride;
            NiPoint3* out = (NiPoint3*)((char*)dstPos + offset);
            const float* point = &p.x;
            XformZ(scaledRotation, positions[vertexIndex].x, positions[vertexIndex].y, positions[vertexIndex].z, translate, p);
            fnv_AddWeightedPoint(out, point, weight);
        }
    }
}

extern intptr_t DAT_011f5e44;
extern int DAT_011f5e4c;
extern int (* DAT_00fdf1c4)(void*);


struct MaterialLibraryView {
    void* vtbl;
    int m_iWordAt04;
    intptr_t m_8;
    void FUN_00a8fdb0();
};

// Swap-removes this from the pointer array at DAT_011f5e44, releases m_8 via DAT_00fdf1c4 unless it is _EmptyFS, and sets the NiRefObject vtable.
// @fnv 0x00a8fdb0
void MaterialLibraryView::FUN_00a8fdb0()
{
    vtbl = &DAT_0109f7f4;
    unsigned int count = DAT_011f5e4c;
    unsigned int i = 0;
    if (count > 0) {
        intptr_t* arr = (intptr_t*)DAT_011f5e44;
        do {
            if (arr[i] == (intptr_t)this) {
                if ((int)i >= 0) {
                    count--;
                    DAT_011f5e4c = count;
                    arr[i] = arr[count];
                }
                break;
            }
            i++;
        } while (i < count);
    }
    intptr_t h = m_8;
    int (* fn)(void*) = DAT_00fdf1c4;
    if (h != (intptr_t)(::DAT_0109b220)) {
        fn((void*)(h - 8));
    }
    vtbl = (void*)&(*reinterpret_cast<const void * *>(&::DAT_0101dce4));
    fn((void*)&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
}

intptr_t __cdecl GetGlobalDataPtr();

void ResetStreamLinkIDSet();

unsigned int __cdecl FUN_00a88ac0(unsigned int a);

extern int(* DAT_00fdf1c4)(void*);

void __cdecl FUN_00a9ba80();

float __cdecl FUN_00a811f0(float y, float x);

void FUN_00a89650(const short* psCompressed, unsigned int uiUnused, float fProjectionAlongAim, float fHalfRange,
                  float* pfValues, unsigned int ItemUpdateArray);

extern "C" void __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int size);

struct MemMgr : MemoryManager
{
};

struct WeightEntry
{
    unsigned int index;
    float weight;
};

struct WeightArray
{
    WeightEntry* m_data;
    unsigned int m_pRayCursor;
    unsigned int m_iElementCount;

    WeightArray() throw();
    ~WeightArray()
    {
        ::FUN_00aa10f0(m_data);
    }

    void Add(const WeightEntry& entry)
    {
        if (m_iElementCount == m_pRayCursor)
            reinterpret_cast<::FUN_00a826b0_shell *>(this)->FUN_00a826b0(m_pRayCursor > 0 ? m_pRayCursor * 2 : 1);
        m_data[m_iElementCount] = entry;
        m_iElementCount++;
    }

};

struct BoneWeight
{
    unsigned short vertex;
    unsigned short pad02;
    float weight;
};

struct SkinBone
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
    BoneWeight* weights;
    unsigned short weightCount;
    unsigned short unk4A;
};

// @fnv 0x00a84810
WeightArray* FUN_00a84810(unsigned int vertexCount, SkinData* skin)
{
    WeightArray* arrays = new WeightArray[vertexCount];
    unsigned int boneCount = skin->count;
    for (unsigned int i = 0; i < boneCount; i++)
    {
        const SkinData::Bone* bone = &skin->bones[i];
        for (unsigned int j = 0; j < bone->count; j++)
        {
            WeightEntry entry;
            entry.index = i;
            entry.weight = bone->weights[j].weight;
            arrays[bone->weights[j].vertex].Add(entry);
        }
    }
    for (unsigned int k = 0; k < vertexCount; k++)
    {
        if (arrays[k].m_iElementCount == 0)
        {
            delete[] arrays;
            return 0;
        }
        reinterpret_cast<::NormalizedWeights *>(&(arrays[k]))->NormalizeWeights();
        reinterpret_cast<::NormalizedWeights *>(&(arrays[k]))->NormalizeWeights();
    }
    return arrays;
}

// NiFree

struct S911d0_Entry
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_pkName0;
    void* m_pkName1;
    void* m_pkName2;
};

class S911d0_EntryPool
{
  public:
      // Delete
};

template <class T> class S911d0_ArrayBase
{
  public:
    virtual ~S911d0_ArrayBase()
    {
        FUN_00aa10f0(m_pBase);
    }

    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else if (m_pBase[uiIndex] != 0)
        {
            m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
    void FUN_00a90180(int iFlags);

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class S911d0_Base
{
  public:
    virtual ~S911d0_Base();  // FUN_00a7b8c0
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
};

class FUN_00a911d0 : public S911d0_Base
{
  public:
    virtual ~FUN_00a911d0();
    S911d0_ArrayBase<S911d0_Entry*> m_kEntries;
};

// @fnv 0x00a911d0
FUN_00a911d0::~FUN_00a911d0()
{
    for (unsigned int i = 0; i < m_kEntries.GetSize(); i++)
    {
        S911d0_Entry* pkEntry = m_kEntries.GetAt(i);
        m_kEntries.SetAt(i, 0);
        if (pkEntry)
        {
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_class *>(&::g_memoryManager))))->FUN_00aa4060(pkEntry->m_pkName0);
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_class *>(&::g_memoryManager))))->FUN_00aa4060(pkEntry->m_pkName1);
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_class *>(&::g_memoryManager))))->FUN_00aa4060(pkEntry->m_pkName2);
            S911d0_Entry* pkDelete = pkEntry;
            reinterpret_cast<::ActiveArray *>(((*reinterpret_cast<::S911d0_EntryPool * *>(&::DAT_011f5e50))))->FindOrAdd((*(void *const *)(&pkDelete)));
        }
    }
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_kEntries))->FUN_00a90180(0);
}

extern void(* DAT_00fdf05c)(void*);

extern void(* DAT_00fdf100)(void*);

struct BmpColor
{
    unsigned char r, g, b, a;
};

class FUN_00a8b110 : public NiRefObject
{
  public:
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    FUN_00a8b110(bool, unsigned int, const BmpColor*);
};

class NiPixelData
{
  public:
    void* vtable;
    unsigned int refs;
    NiPixelFormat format;
    FUN_00a8b110* palette;
    unsigned char* pixels;
    unsigned int* width;
    unsigned int* height;
    unsigned int* offsets;
    unsigned int levels;
    unsigned int stride;
    unsigned int unk68, unk6c, unk70;
    NiPixelData(unsigned int, unsigned int, const NiPixelFormat&, unsigned int = 1, unsigned int = 1);
    unsigned char* Pixels()
    {
        return pixels + offsets[0];
    }
    void SetPalette(FUN_00a8b110* p)
    {
        if (palette != p)
        {
            if (palette)
                palette->DecRefCount();
            palette = p;
            if (palette)
                palette->IncRefCount();
        }
    }
};

struct BmpStream
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Seek(int, int);
    unsigned int position;
    unsigned int(__cdecl* read)(BmpStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* dst, unsigned int size)
    {
        unsigned int component = 1;
        position += read(this, dst, size, &component, 1);
    }
};

struct BmpReader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Header(BmpStream&, unsigned int&, unsigned int&, NiPixelFormat&, bool&, unsigned int&);
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
    unsigned int width, height;
    NiPixelFormat format;
    unsigned short bpp;
    unsigned int colorCount, dataOffset;
    bool flip;
    NiPixelData* FUN_00a8e810(BmpStream& stream, NiPixelData* optional);
};

// @fnv 0x00a8e810
NiPixelData* BmpReader::FUN_00a8e810(BmpStream& stream, NiPixelData* optional)
{
    bool mipmap;
    unsigned int w, h, faces;
    NiPixelFormat headerFormat;
    DAT_00fdf05c(&unk080);
    if (!Header(stream, w, h, headerFormat, mipmap, faces))
    {
        DAT_00fdf100(&unk080);
        return 0;
    }
    NiPixelData* dest;
    if (optional && optional->width[0] == width && optional->height[0] == height && optional->format == format)
        dest = optional;
    else
        dest = new NiPixelData(width, height, format);
    if (format == (*reinterpret_cast<const ::NiPixelFormat *>((void *)&::DAT_011aa210)))
    {
        BmpColor colors[256];
        stream.Read(colors, colorCount * sizeof(BmpColor));
        BmpColor* color = colors;
        for (unsigned int i = 0; i < colorCount; ++i, ++color)
        {
            unsigned char temp = color->r;
            color->r = color->b;
            color->b = temp;
            color->a = 255;
        }
        dest->SetPalette(new FUN_00a8b110(false, 256, colors));
    }
    else
    {
        stream.Seek(colorCount * sizeof(BmpColor), DAT_010a2484);
    }
    int extra = dataOffset - 54 - colorCount * sizeof(BmpColor);
    if (extra > 0)
        stream.Seek(extra, DAT_010a2484);
    unsigned int imageSize = (((width * bpp + 31) & ~31) >> 3) * height;
    unsigned int rowSize = dest->width[0] * dest->stride;
    if (bpp == 4)
    {
        unsigned int packedSize = (width >> 1) + (width & 1);
        unsigned int padding = (packedSize & 3) ? 4 - (packedSize & 3) : 0;
        unsigned char* input = (unsigned char*)::FUN_00aa1070(packedSize + padding);
        unsigned char* row;
        int step;
        if (flip)
        {
            row = dest->Pixels() + rowSize * (dest->height[0] - 1);
            step = -(int)rowSize;
        }
        else
        {
            row = dest->Pixels();
            step = rowSize;
        }
        for (unsigned int y = 0; y < height; ++y, row += step)
        {
            stream.Read(input, packedSize + padding);
            unsigned char* out = row;
            unsigned char* in = input;
            for (unsigned int x = 0; x < packedSize; ++x)
            {
                *out++ = *in >> 4;
                *out++ = *in & 15;
                ++in;
            }
        }
        ::FUN_00aa10f0(input);
    }
    else
    {
        if (flip)
        {
            unsigned char* row = dest->Pixels() + rowSize * (height - 1);
            unsigned int y;
            if (rowSize & 3)
            {
                unsigned int padding = 4 - (rowSize & 3);
                unsigned char dummy[4];
                for (y = 0; y < height; ++y)
                {
                    stream.Read(row, rowSize);
                    stream.Read(dummy, padding);
                    row -= rowSize;
                }
            }
            else
            {
                for (y = 0; y < height; ++y)
                {
                    stream.Read(row, rowSize);
                    row -= rowSize;
                }
            }
        }
        else
        {
            if (rowSize & 3)
            {
                unsigned int padding = 4 - (rowSize & 3);
                unsigned char* row = dest->Pixels();
                unsigned char dummy[4];
                for (unsigned int y = 0; y < height; ++y, row += rowSize)
                {
                    stream.Read(row, rowSize);
                    stream.Read(dummy, padding);
                }
            }
            else
            {
                stream.Read(dest->Pixels(), imageSize);
            }
        }
    }
    if (format == DAT_011aa2e8 || format == (*reinterpret_cast<const ::NiPixelFormat *>(&::gNiPoint3StartupSrc)))
    {
        unsigned int pixelStride = dest->stride;
        unsigned int count = width * height;
        unsigned char* pixel = dest->Pixels();
        for (unsigned int i = 0; i < count; ++i, pixel += pixelStride)
        {
            unsigned char swap = pixel[0];
            pixel[0] = pixel[2];
            pixel[2] = swap;
        }
    }
    DAT_00fdf100(&unk080);
    return dest;
}

inline void* operator new[](std::size_t size, int) throw()
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&(static_cast<MemMgr&>(g_memoryManager)))->FUN_00aa3e40(size);
}

struct Interaction
{
    unsigned int bone;
    float weight;
};

struct TempRecord
{
    void* data;
    unsigned int size;
    unsigned int count;
    ~TempRecord()
    {
        ::FUN_00aa10f0(data);
    }
};

struct Holder
{
    void* data;
    unsigned int size;
    unsigned int count;
    unsigned short index;
    unsigned short flags;
    ~Holder()
    {
        ::FUN_00aa10f0(data);
    }
    bool ContainsSortedSubset(const Holder* other);
};

__declspec(noinline) bool Holder::ContainsSortedSubset(const Holder* other)
{
    unsigned int i = 0;
    for (unsigned int j = 0; j < other->count; ++j, ++i)
    {
        while (i < count &&
               static_cast<const unsigned short*>(data)[i] < static_cast<const unsigned short*>(other->data)[j])
            ++i;
        if (i == count ||
            static_cast<const unsigned short*>(data)[i] != static_cast<const unsigned short*>(other->data)[j])
            return false;
    }
    return true;
}

struct SourceGeometry
{
    unsigned int unk00, unk04;
    unsigned short vertexCount, unk0a;
    unsigned int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned short triangleCount, unk42;
    unsigned short GetCount() const
    {
        return vertexCount;
    }
    unsigned short GetTriangleCount() const
    {
        return triangleCount;
    }
};

struct SkinBuildData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short unk1c;
    unsigned short triangleTotal;
    unsigned int unk20;
    unsigned short influencesPerVertex;
    unsigned short unk26;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int boneCount;
};

struct C082d30
{
    void* data;
    unsigned int size;
    unsigned int count;
    void AppendMatchingIndices(int, void*, unsigned int);
    void Grow(unsigned int);
public:
    void AppendMatchingIndices(int, int *, unsigned int);
};

__declspec(noinline) void C082d30::AppendMatchingIndices(int partition, void* assignments, unsigned int triangleTotal)
{
    const int* map = static_cast<const int*>(assignments);
    for (unsigned int triangle = 0; triangle < triangleTotal; ++triangle)
    {
        if (map[triangle] != partition)
            continue;
        if (count == size)
            Grow(size == 0 ? 1 : 2 * size);
        static_cast<unsigned short*>(data)[count] = static_cast<unsigned short>(triangle);
        ++count;
    }
}

struct FUN_00a81ba0
{
    void* m_pVTable;
    unsigned short* m_04;
    float* m_08;
    unsigned short* m_0c;
    unsigned char* m_10;
    unsigned short* m_14;
    unsigned short* m_18;
    unsigned short unk1c;
    unsigned short triangleTotal;
    unsigned short unk20;
    volatile unsigned short m_22;
    unsigned short influencesPerVertex;
    unsigned short unk26;
    unsigned int m_28;

    FUN_00a81ba0() throw();
    ~FUN_00a81ba0()
    {}
    unsigned short* BuildVertexRemapTable(C082d30*, SourceGeometry*);
    void BuildTriangleList(C082d30*, SourceGeometry*, unsigned short*);
    void PopulateSkinData(C082d30*, Holder*, SourceGeometry*, TempRecord*, bool, bool, unsigned char, unsigned int);
};

typedef FUN_00a81ba0 OutputRecord;

struct HolderArray
{
    Holder** volatile data;
    unsigned int capacity;
    unsigned int count;
};

struct GeometryBuilder
{
    unsigned int unk00, unk04, count;
    OutputRecord* output;
    bool FUN_00a84980(SourceGeometry*, SkinBuildData*, unsigned char, unsigned char, bool, OutputRecord**,
                      unsigned short*, unsigned char*);
};

__declspec(noinline) void FUN_00a81ba0::PopulateSkinData(C082d30* triangles, Holder* bones, SourceGeometry* geometry,
                                                         TempRecord* interactions, bool padBones, bool makePalette,
                                                         unsigned char width, unsigned int totalBones)
{
    unsigned int paletteCount = bones->count;
    if (paletteCount < width)
        paletteCount = width;
    unk20 = static_cast<unsigned short>(paletteCount);
    triangleTotal = static_cast<unsigned short>(triangles->count);
    m_04 = static_cast<unsigned short*>(::FUN_00aa1070(2 * unk20));
    for (unsigned int i = 0; i < unk20; ++i)
        m_04[i] = i < bones->count ? static_cast<unsigned short*>(bones->data)[i] : 0;
    unsigned short* translation = BuildVertexRemapTable(triangles, geometry);
    BuildTriangleList(triangles, geometry, translation);
    ::FUN_00aa10f0(translation);
    float* destination;
    if (padBones)
    {
        influencesPerVertex = width;
        unsigned int count = influencesPerVertex * unk1c;
        m_08 = static_cast<float*>(::FUN_00aa1070(sizeof(float) * count));
        m_10 = static_cast<unsigned char*>(::FUN_00aa1070(count));
        unsigned int* remap = static_cast<unsigned int*>(::FUN_00aa1070(sizeof(unsigned int) * totalBones));
        for (unsigned int bone = 0; bone < bones->count; ++bone)
            remap[m_04[bone]] = bone;
        destination = m_08;
        unsigned char* palette = m_10;
        float* weights = static_cast<float*>(::FUN_00aa1070(sizeof(float) * influencesPerVertex));
        unsigned char* paletteIndices = static_cast<unsigned char*>(::FUN_00aa1070(influencesPerVertex));
        for (unsigned int vertex = 0; vertex < unk1c; ++vertex)
        {
            const TempRecord& record = interactions[m_0c[vertex]];
            const Interaction* entries = static_cast<const Interaction*>(record.data);
            unsigned int slot = 0;
            for (; slot < record.count; ++slot)
            {
                weights[slot] = entries[slot].weight;
                paletteIndices[slot] = static_cast<unsigned char>(remap[entries[slot].bone]);
            }
            for (; slot < influencesPerVertex; ++slot)
            {
                weights[slot] = 0.0f;
                paletteIndices[slot] = 0;
            }
            for (unsigned int outputSlot = 0; outputSlot < influencesPerVertex; ++outputSlot)
            {
                unsigned int selected = 0;
                float largest = weights[0];
                for (unsigned int candidate = 1; candidate < influencesPerVertex; ++candidate)
                {
                    if (weights[candidate] > largest)
                    {
                        selected = candidate;
                        largest = weights[candidate];
                    }
                }
                *destination++ = weights[selected];
                *palette++ = paletteIndices[selected];
                weights[selected] = -1.0f;
            }
        }
        ::FUN_00aa10f0(weights);
        ::FUN_00aa10f0(paletteIndices);
        ::FUN_00aa10f0(remap);
    }
    else
    {
        influencesPerVertex = unk20;
        unsigned int count = influencesPerVertex * unk1c;
        m_08 = static_cast<float*>(::FUN_00aa1070(sizeof(float) * count));
        destination = m_08;
        for (unsigned int vertex = 0; vertex < unk1c; ++vertex)
        {
            const TempRecord& record = interactions[m_0c[vertex]];
            const Interaction* entries = static_cast<const Interaction*>(record.data);
            unsigned int slot = 0;
            for (; slot < bones->count; ++slot)
            {
                float weight = 0.0f;
                unsigned int bone = static_cast<const unsigned short*>(bones->data)[slot];
                for (unsigned int interaction = 0; interaction < record.count; ++interaction)
                {
                    if (entries[interaction].bone == bone)
                    {
                        weight = entries[interaction].weight;
                        break;
                    }
                }
                *destination++ = weight;
            }
            for (; slot < unk20; ++slot)
                *destination++ = 0.0f;
        }
        if (makePalette)
        {
            m_10 = static_cast<unsigned char*>(::FUN_00aa1070(count));
            unsigned char* palette = m_10;
            for (unsigned int vertex = 0; vertex < unk1c; ++vertex)
                for (unsigned int bone = 0; bone < unk20; ++bone)
                    *palette++ = static_cast<unsigned char>(bone);
        }
    }
}

// @fnv 0x00a84980
bool GeometryBuilder::FUN_00a84980(SourceGeometry* source, SkinBuildData* other, unsigned char first,
                                   unsigned char second, bool mode, OutputRecord** outputs, unsigned short* indices,
                                   unsigned char* changes)
{
    HolderArray holders = {0, 0, 0};
    void* data;
    TempRecord* records = ((::TempRecord *)(::FUN_00a84810((unsigned int)(source->GetCount()), (::SkinData *)(other))));
    if (!records)
    {
        ::FUN_00aa10f0(records);
        return false;
    }

    bool success = reinterpret_cast<::SkinWeights::Processor *>(this)->ReduceGroupWeights((::SkinWeights::Geometry *)(source), first, second, (::SkinWeights::Group *)(records));
    if (success)
    {
        success = reinterpret_cast<::SkinBuilder *>(this)->BuildTriangleSetMapping((::SkinGeom *)(source), other, first, records, (::SkinItems *)(::HolderArray *)(&holders), (int **)(void **)(&data), (int *)(outputs));
        if (outputs && indices && changes)
        {
            for (unsigned int i = 0; i < holders.count; ++i)
            {
                Holder** entries = holders.data;
                Holder* current = entries[i];
                indices[i] = current->index;
                if (i)
                {
                    Holder* previous = entries[i - 1];
                    if (current->ContainsSortedSubset(previous) && current->count == previous->count)
                        changes[i] = 0;
                    else
                        changes[i] = 1;
                }
                else
                {
                    changes[0] = 1;
                }
            }
        }
        OutputRecord* result = new (0) OutputRecord[count];
        bool padBones = (first != second);
        C082d30 scratch;
        scratch.data = 0;
        scratch.size = 0;
        scratch.count = 0;
        for (unsigned int i = 0; i < count; ++i)
        {
            reinterpret_cast<::C082d30 *>(&(scratch))->AppendMatchingIndices(i, (int *)(data), source->GetTriangleCount());
            Holder* current = const_cast<Holder**&>(holders.data)[i];
            reinterpret_cast<::Skp_00a828d0_cls *>(&(result[i]))->PopulateSkinData((::GeomData *)(::C082d30 *)(&scratch), (::Skp_00a828d0_src *)(current), source, (::Skp_00a828d0_grp *)(records), padBones, mode, second,
                                       (*(SkinBuildData* volatile*)&other)->boneCount);
            scratch.count = 0;
            delete current;
        }
        ::FUN_00aa10f0(data);
        while (count)
        {
            unsigned int i = 0;
            for (; i < count; ++i)
            {
                if (!(unsigned short)result[i].unk1c)
                {
                    for (unsigned int j = i; j < count - 1; ++j)
                    {
                        std::memmove(&result[j], &result[j + 1], sizeof(OutputRecord));
                        outputs[j] = outputs[j + 1];
                        indices[j] = indices[j + 1];
                        changes[j] = changes[j + 1];
                    }
                    --count;
                    break;
                }
            }
            if (i == count)
                break;
        }
        output = result;
        ::FUN_00aa10f0(scratch.data);
    }
    delete[] records;
    ::FUN_00aa10f0(holders.data);
    return success;
}

void __cdecl _memmove(void*,const void*,unsigned int);

void __cdecl FUN_00a877d0();

void __cdecl FUN_00a877e0();

struct P03MM {  };

struct SpawnedRecord {
    int m_p;
    short m_s1;
    short m_s2;
    int m_i1;
    int m_i2;
    int m_i3;
    SpawnedRecord() throw();
    ~SpawnedRecord() {}
};

// @fnv 0x00a90290
SpawnedRecord* FUN_00a90290(unsigned int n) {
    return new SpawnedRecord[n];
}

#include "generated/data/staging/blk_00a80000_o2.inc"
