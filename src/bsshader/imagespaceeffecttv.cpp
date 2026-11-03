
// src/bsshader/imagespaceeffecttv.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffecttv.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstddef>
#include <windows.h>
#include "fnv/decl/BA3760Object.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00ba3780_struct.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/Holder00ba37f0.h"
#include "fnv/decl/ImageSpaceEffect.h"
#include "fnv/decl/ImageSpaceShaderParam.h"
#include "fnv/decl/fnv_00ba3ba0__Holder.h"
#include "fnv/decl/fnv_00bb8ea0__FUN_00bb8ea0.h"
#include "fnv/symbols_011ae000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01200000.h"

struct MemoryManagerStandIn
{
    void* FUN_00aa3e40(unsigned int uiSize);
};
void __cdecl PipboyFree(void* pvMem);

struct NiRefObjectStandIn
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct NiTextureStandIn : NiRefObjectStandIn
{
};


struct PipboySourceTexture
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
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();
};

struct PipboyPass
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    int unk04;
    int unk08;
    int unk0c;

    PipboyPass()
    {
        unk00 = 0;
        unk01 = 0;
        unk02 = 0;
        unk04 = 0;
        unk08 = 0;
        unk0c = 0;
    }
    static void* operator new(std::size_t uiSize)
    {
        return (*reinterpret_cast<::MemoryManagerStandIn *>(&::g_memoryManager)).FUN_00aa3e40(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        PipboyFree(pvMem);
    }
};

struct PipboyConstantsBase
{
    int unk00;
};

struct PipboyConstants : PipboyConstantsBase
{
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
    unsigned char unk054;
    unsigned char unk55;
    unsigned char unk56;
    unsigned char unk057;
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

    PipboyConstants();
    static void* operator new(std::size_t uiSize)
    {
        return (*reinterpret_cast<::MemoryManagerStandIn *>(&::g_memoryManager)).FUN_00aa3e40(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        PipboyFree(pvMem);
    }
};

template <class T> struct PipboyArray
{
    void* m_vtbl;
    T* m_pBase;
    void FUN_00a90180(unsigned int uiSize);
    __declspec(noalias) void FUN_00ba3aa0(unsigned int uiIndex, T const& kElem);
    T& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
};


struct PipboyGeometryData
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
    void* unk120;
    void* unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    void* unk134;
};
struct PipboyGeometry
{
    int unk00;
    int unk04;
    PipboyGeometryData* unk08;
};

static const char s_szScanlines[] = "Data\\Textures\\Pipboy3000\\PipboyScanlines.dds";
static const char s_szDistortMap[] = "Data\\Textures\\Pipboy3000\\PipboyDistortEffectMap.dds";
extern const char g_szPipboyEnd[] = "";

struct PipboyShader2
{
    int unk00;
    unsigned char unk04;
    unsigned char unk005;
    unsigned char unk006;
    unsigned char unk007;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    PipboyArray<PipboyConstantsBase*> m_kConstants;
    unsigned int unk020;
    unsigned int unk024;
    PipboyArray<PipboyPass*> m_kPasses;

    void SetupPipboyPasses(PipboyGeometry* pkGeometry, int iUnused);
};

// Configures the Pipboy shader passes, loads scanline and distortion textures, and sets up constants with texel size and global parameters.
// @fnv 0x00bb9200
void PipboyShader2::SetupPipboyPasses(PipboyGeometry* pkGeometry, int iUnused)
{
    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(1);
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_kPasses))->FUN_00a90180(4);

    ::BSShaderManager::GetTexture(s_szDistortMap, 1, (*(::NiPointer< ::NiTexture> *)(&(*reinterpret_cast<::NiTextureStandIn * *>(&::fnv_00bb8ea0::FUN_00bb8ea0::spObjB)))), 0, 0);
    ::BSShaderManager::GetTexture(s_szScanlines, 1, (*(::NiPointer< ::NiTexture> *)(&(*reinterpret_cast<::NiTextureStandIn * *>(&::fnv_00bb8ea0::FUN_00bb8ea0::spObjA)))), 0, 0);
    NiTextureStandIn* pkScanlines = (*reinterpret_cast<::NiTextureStandIn * *>(&::fnv_00bb8ea0::FUN_00bb8ea0::spObjA));
    NiTextureStandIn* pkDistort = (*reinterpret_cast<::NiTextureStandIn * *>(&::fnv_00bb8ea0::FUN_00bb8ea0::spObjB));

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_kPasses))->FUN_00ba3aa0(1, (::KeyPair **)&(const ::PipboyPass *const &)(new PipboyPass));
    reinterpret_cast<::BA3760Object *>((m_kPasses.GetAt(1)))->FUN_00ba3760(0);
    reinterpret_cast<::Holder00ba37f0 *>((m_kPasses.GetAt(1)))->FUN_00ba37f0((::Tex00ba37f0 *)(::NiTextureStandIn *)(0));
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_kPasses))->FUN_00ba3aa0(2, (::KeyPair **)&(const ::PipboyPass *const &)(new PipboyPass));
    reinterpret_cast<::BA3760Object *>((m_kPasses.GetAt(2)))->FUN_00ba3760(0);
    reinterpret_cast<::Holder00ba37f0 *>((m_kPasses.GetAt(2)))->FUN_00ba37f0((::Tex00ba37f0 *)(pkDistort));
    reinterpret_cast<::FUN_00a41520_cls *>(&(m_kPasses))->FUN_00ba3aa0(3, (::KeyPair **)&(const ::PipboyPass *const &)(new PipboyPass));
    reinterpret_cast<::BA3760Object *>((m_kPasses.GetAt(3)))->FUN_00ba3760(3);
    reinterpret_cast<::Holder00ba37f0 *>((m_kPasses.GetAt(3)))->FUN_00ba37f0((::Tex00ba37f0 *)(pkScanlines));

    float fTexelX = 0;
    float fTexelY = 0;
    if (m_kPasses.GetAt(0))
    {
        PipboySourceTexture* pkSource = ((::PipboySourceTexture *)(reinterpret_cast<::FUN_00ba3780_struct *>((m_kPasses.GetAt(0)))->FUN_00ba3780()));
        fTexelX = 1.0f / (float)pkSource->GetWidth();
        fTexelY = 1.0f / (float)pkSource->GetHeight();
    }

    PipboyConstants* pkConst = new PipboyConstants;
    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst))->AllocateShaderConstants(0, 5);
    pkConst->unk55 = 0;
    pkConst->unk56 = 0;
    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst))->SetShaderConstantVector4(0, fTexelX, fTexelY, 0.0f, 0.0f);
    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst))->SetShaderConstantVector4(1, ::DAT_011ae600, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst))->SetShaderConstantVector4(2, ::DAT_0120081c, ::DAT_01200820, ::DAT_011ae604, 0.0f);
    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst))->SetShaderConstantVector4(3, ::DAT_01200824, ::DAT_01200828, ::DAT_011ae608, 0.0f);
    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst))->SetShaderConstantVector4(4, ::DAT_0120082c, ::DAT_01200830, ::DAT_01200834, 1.0f);

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_kConstants))->FUN_00ba3aa0(0, (::KeyPair **)&(pkConst));
    reinterpret_cast<::fnv_00ba3ba0::Holder *>(this)->FUN_00ba3ba0(0, 1, 2, 3, 0, 0, 0);
    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, (::ImageSpaceEffect *)(pkGeometry->unk08->unk134), (::ImageSpaceEffectParam *)(pkConst), 0);
}

#include "generated/data/bsshader/imagespaceeffecttv.inc"
