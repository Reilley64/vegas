
// src/gamebryo2.2/corelibs/niparticle/bsstripparticlesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/bsstripparticlesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/B1D0Node3D.h"
#include "fnv/decl/BSMultiBoundNode.h"
#include "fnv/decl/FUN_00c1b0b0_cls.h"
#include "fnv/decl/FUN_00c1b400_cls.h"
#include "fnv/decl/FUN_00c1b5c0.h"
#include "fnv/decl/FUN_00c1b850_cls.h"
#include "fnv/decl/Nps_c1b3a0.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c1b810__NiParticleSystem.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_010be000.h"
void* g_01202560;

// @fnv 0x00c257c0
void* __cdecl FUN_00c257c0()
{
    return &g_01202560;
}

struct NiRenderer
{
    void* _vt;
    char _pad0[508];
    int m_iRendererState;
    char _pad1[4];
    bool m_bRendererFlagA;
};
struct FUN_00a80610_shell
{
    void __thiscall FUN_00a80610(NiRenderer*);
    void __thiscall FUN_00c25730(NiRenderer*);
};
// @fnv 0x00c25730
void __thiscall FUN_00a80610_shell::FUN_00c25730(NiRenderer* apkRenderer)
{
    this->FUN_00a80610(apkRenderer);
    NiRenderer* pkRenderer = apkRenderer;
    if ((pkRenderer->m_iRendererState == 1 || pkRenderer->m_iRendererState == 2) && pkRenderer->m_bRendererFlagA == 1)
        ((void(__thiscall*)(NiRenderer*, FUN_00a80610_shell*))(*(void***)pkRenderer)[112])(pkRenderer, this);
}

struct StrArr
{
};
struct BSStripParticleSystem
{
    void AppendString(StrArr*);
};
// Calls WriteParticleSystemInfo, gets a string from g_01202560, grows pkStrings if its count reached capacity, then stores the string at the current count.
// @fnv 0x00c25770
void BSStripParticleSystem::AppendString(StrArr* pkStrings)
{
    reinterpret_cast<::FUN_00c1b850_cls *>(this)->WriteParticleSystemInfo((::FUN_00c1b850_list *)(pkStrings));
    char* s = ::FUN_00a7d330((const char *)(g_01202560));
    unsigned int n = *(unsigned short*)((char*)pkStrings + 0xa);
    if (n >= *(unsigned short*)((char*)pkStrings + 8))
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(n + *(unsigned short*)((char*)pkStrings + 0xe));
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(n, s);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
struct ParticleSystem
{
    unsigned int* vtable;
};
struct ParticleOwner
{
    ParticleSystem* __thiscall CreateParticleSystem(unsigned int flags);
};
// Allocates a 0x110-byte ParticleSystem, initialises it and its vtable, passes it to FUN_00c1b6f0 with flags, and returns it.
// @fnv 0x00c257d0
ParticleSystem* ParticleOwner::CreateParticleSystem(unsigned int flags)
{
    ParticleSystem* object = static_cast<ParticleSystem*>(FUN_00aa13e0(0x110));
    if (object)
    {
        new ((void *)(object)) ::FUN_00c1b5c0();
        object->vtable = &(*reinterpret_cast<unsigned int *>(&::DAT_010be35c));
    }
    else
    {
        object = 0;
    }
    reinterpret_cast<::BSMultiBoundNode *>((this))->FUN_00c1b6f0((::BSMultiBoundNode *)(object), (*(::CloningProcess *)(flags)));
    return object;
}

// @fnv 0x00c21940
void __cdecl FUN_00c21940()
{
    static_cast<::FUN_00c1b0b0_cls *>(nullptr)->FUN_00c1b0b0({});
}

struct NiCullingProcess
{
    void* p;
};
struct NiGeometry
{
    void __thiscall OnVisible(NiCullingProcess&);
};
struct FUN_00c256f0_cls : NiGeometry
{
    void __thiscall FUN_00c256f0(NiCullingProcess&);
};
// @fnv 0x00c256f0
void __thiscall FUN_00c256f0_cls::FUN_00c256f0(NiCullingProcess& a)
{
    NiGeometry::OnVisible(a);
}

// @fnv 0x00c25700
void __cdecl FUN_00c25700()
{
    static_cast<::Nps_c1b3a0 *>(nullptr)->FUN_00c1b3a0({});
}

// @fnv 0x00c25710
void __cdecl FUN_00c25710()
{
    static_cast<::fnv_00c1b810::NiParticleSystem *>(nullptr)->LoadModifiers({});
}

// @fnv 0x00c25720
void __cdecl FUN_00c25720()
{
    static_cast<::FUN_00c1b400_cls *>(nullptr)->FUN_00c1b400(*(::NiStreamC1B *)nullptr);
}


// @fnv 0x00c21950
void FUN_00c21950()
{
    static_cast<::B1D0Node3D *>(nullptr)->FUN_00c1b1d0({});
}
