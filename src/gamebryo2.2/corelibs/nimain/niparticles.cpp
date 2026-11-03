
// src/gamebryo2.2/corelibs/nimain/niparticles.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niparticles.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00a9b1b0
#include <new>
#include "fnv/decl/FUN_00a80580_cls.h"
#include "fnv/decl/FUN_00a80610_shell.h"
#include "fnv/decl/NiGeometry.h"
#include "fnv/decl/NiLines.h"
#include "fnv/decl/ParticleViewData.h"
#include "fnv/decl/ViewerGeometry.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_010a1000.h"
#include "fnv/symbols_011f5000.h"
char const* const* __cdecl FUN_00a9b1b0()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f5f64));
}

struct NiGeometryData
{
    enum Consistency
    {
    };
    void SetDataConsistency(Consistency);
};

struct NiParticles
{
    void FUN_00a9b230(bool bTool);
};

// @fnv 0x00a9b230
void NiParticles::FUN_00a9b230(bool bTool)
{
    NiGeometryData* p = *(NiGeometryData**)((char*)this + 0xb8);
    p->SetDataConsistency((NiGeometryData::Consistency)0);
}

struct DtorObj
{
};
void __cdecl _delete(void*, unsigned int);
struct S00a9b1c0
{
    void* FUN_00a9b1c0(unsigned int);
};
// Calls FUN_00a80580 on this, frees this with _delete when bit 0 of f is set, and returns this.
// @fnv 0x00a9b1c0
void* S00a9b1c0::FUN_00a9b1c0(unsigned int auiFlags)
{
    reinterpret_cast<::FUN_00a80580_cls *>((((DtorObj*)this)))->FUN_00a80580();
    if (auiFlags & 1)
        _delete(this, 0xC4);
    return this;
}

struct NiRenderer
{
    void* __vtbl;
    char _pad0[508];
    int m_iRendererState;
    char _pad1[4];
    bool m_bRendererFlagA;
};
struct FUN_00a80610_This
{
};
struct FUN_00a9b1f0_shell
{
    void SetupRenderer(NiRenderer*);
};
// @fnv 0x00a9b1f0
void FUN_00a9b1f0_shell::SetupRenderer(NiRenderer* apkRenderer)
{
    NiRenderer* pkRenderer = apkRenderer;
    reinterpret_cast<::FUN_00a80610_shell *>((((FUN_00a80610_This*)this)))->FUN_00a80610((::NiRenderer *)(pkRenderer));
    if ((pkRenderer->m_iRendererState == 1 || pkRenderer->m_iRendererState == 2) && pkRenderer->m_bRendererFlagA == 1)
    {
        ((void(__thiscall*)(NiRenderer*, void*))(*(void***)pkRenderer)[111])(pkRenderer, this);
    }
}

struct StrArr
{
    char _0[8];
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short _c;
    unsigned short m_usGrow;
};
// Grows the StrArr if it is full, then appends the string returned by _FUN_00a7d330(g_011f5f14_arg1) at the current size.
// @fnv 0x00a9b2e0
void __stdcall FUN_00a9b2e0(StrArr* apStrArr)
{
    reinterpret_cast<::ViewerGeometry *>((apStrArr))->FUN_00a80e70({});
    char* psz = ::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f5f64)));
    unsigned int uiSize = apStrArr->m_usSize;
    unsigned int uiMax = apStrArr->m_usMax;
    if (uiSize >= uiMax)
        reinterpret_cast<::ViewerStrings *>((apStrArr))->SetSize(apStrArr->m_usGrow + uiSize);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apStrArr))->SetAt(uiSize, psz);
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct FUN_00a9b250_obj
{
    void* m_pVTable;
    char unk04[0xc0];

};

struct FUN_00a9b250_cls
{
    FUN_00a9b250_obj* CreateAndInitObject(unsigned int arg);
};

// @fnv 0x00a9b250
FUN_00a9b250_obj* FUN_00a9b250_cls::CreateAndInitObject(unsigned int arg)
{
    FUN_00a9b250_obj* p = (FUN_00a9b250_obj*)FUN_00aa13e0(0xc4);
    if (p != 0)
    {
        new ((void *)(p)) ::NiGeometry();
        p->m_pVTable = (void*)&DAT_010a11d4;
    }
    else
    {
        p = 0;
    }
    reinterpret_cast<::NiLines *>(this)->CopyMemberData((::NiLines *)(p), (*(::CloningProcess *)(arg)));
    return p;
}

struct ObjHdr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    union
    {
        unsigned char m_18b;
        unsigned short m_18w;
    };
};

struct HolderB8
{
};

struct ArgRec
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0C;
};

struct FUN_00a9b2a0_cls
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
    ObjHdr* m_9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    HolderB8* m_B8;
    void ProcessArgIfFlagged(ArgRec* pArg);
};

// If m_9C is set and its flag bits are set, forwards pArg->m_0C to m_B8, then calls FUN_00a7fd90(pArg).
// @fnv 0x00a9b2a0
void FUN_00a9b2a0_cls::ProcessArgIfFlagged(ArgRec* pArg)
{
    ObjHdr* pObjHdr = m_9C;
    if (pObjHdr != 0 && (pObjHdr->m_18b & 1) != 0 && (pObjHdr->m_18w & 0x1E0) != 0)
    {
        reinterpret_cast<::ParticleViewData *>((m_B8))->FUN_00a96910((::ParticleViewFrame *)(pArg->m_0C));
    }
    reinterpret_cast<::NiGeometry *>(this)->OnVisible((*(::NiCullingProcess *)(pArg)));
}
