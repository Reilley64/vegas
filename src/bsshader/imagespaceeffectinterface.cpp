
// src/bsshader/imagespaceeffectinterface.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectinterface.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstddef>
#include <windows.h>
#include "fnv/decl/BA3760Object.h"
#include "fnv/decl/BBA3C00Shader.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00ba3780_struct.h"
#include "fnv/decl/FUN_00ba3c70_shell.h"
#include "fnv/decl/Holder00ba37f0.h"
#include "fnv/decl/ImageSpaceEffect.h"
#include "fnv/decl/ImageSpaceShaderParam.h"
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

struct PipboyParamBase
{
};

struct PipboyPass : PipboyParamBase
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

struct PipboyConstantsBase : PipboyParamBase
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
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00a90180(unsigned int uiSize);

    __declspec(noinline) void FUN_00ba3aa0(unsigned int uiIndex, T const& kElem)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (kElem)
                ++m_usESize;
        }
        else if (kElem)
        {
            if (!m_pBase[uiIndex])
                ++m_usESize;
        }
        else if (m_pBase[uiIndex])
            --m_usESize;
        m_pBase[uiIndex] = kElem;
    }

    __forceinline void Assign(unsigned int index, T value)
    {
        reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00ba3aa0(index, (::KeyPair **)&(value));
    }
    T GetAt(unsigned int uiIndex) const
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

struct PipboyShader
{

    int unk00;

    unsigned char unk04;

    unsigned char unk05;
    unsigned short unk06;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;

    PipboyArray<PipboyParamBase*> m_kConstants;

    PipboyArray<PipboyParamBase*> m_kPasses;




    void SetupScanlineDistortion(PipboyGeometry* pkGeometry, int iUnused);
};

// @fnv 0x00bb89b0
void PipboyShader::SetupScanlineDistortion(PipboyGeometry* pkGeometry, int iUnused)

{

    unk04 = 0;

    reinterpret_cast<::ImageSpaceEffect *>(this)->SetTextureArraySize(2);

    reinterpret_cast<::FUN_00a41520_cls *>(&(m_kPasses))->FUN_00a90180(5);

    ::BSShaderManager::GetTexture(s_szScanlines, 1, (*(::NiPointer< ::NiTexture> *)(&(*reinterpret_cast<::NiTextureStandIn * *>(&::recon7fbee0::DAT_01200810)))), 0, 0);

    NiTextureStandIn* pkScanlines = (*reinterpret_cast<::NiTextureStandIn * *>(&::recon7fbee0::DAT_01200810));

    ::BSShaderManager::GetTexture(s_szDistortMap, 1, (*(::NiPointer< ::NiTexture> *)(&g_pkDistortMap_01200814)), 0, 0);

    // The distortion snapshot is dead before the texel scale is computed.
    union DistortionTexel
    {
        NiTextureStandIn* pointer;
        float texel;
    } distortion;
    distortion.pointer = g_pkDistortMap_01200814;

    {
        PipboyParamBase* pPass = new PipboyPass;
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_kPasses))->FUN_00ba3aa0(3, (::KeyPair **)&(pPass));
    }

    reinterpret_cast<::Holder00ba37f0 *>((static_cast<PipboyPass*>(m_kPasses.GetAt(3))))->FUN_00ba37f0((::Tex00ba37f0 *)(pkScanlines));

    reinterpret_cast<::BA3760Object *>((static_cast<PipboyPass*>(m_kPasses.GetAt(3))))->FUN_00ba3760(3);

    {
        PipboyParamBase* pPass = new PipboyPass;
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_kPasses))->FUN_00ba3aa0(4, (::KeyPair **)&(pPass));
    }

    NiTextureStandIn* pkDistort = distortion.pointer;
    reinterpret_cast<::Holder00ba37f0 *>((static_cast<PipboyPass*>(m_kPasses.m_pBase[4])))->FUN_00ba37f0((::Tex00ba37f0 *)(pkDistort));

    reinterpret_cast<::BA3760Object *>((static_cast<PipboyPass*>(m_kPasses.GetAt(4))))->FUN_00ba3760(0);

    {
        PipboyParamBase* pPass = new PipboyPass;
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_kPasses))->FUN_00ba3aa0(2, (::KeyPair **)&(pPass));
    }

    reinterpret_cast<::BA3760Object *>((static_cast<PipboyPass*>(m_kPasses.GetAt(2))))->FUN_00ba3760(0);

    reinterpret_cast<::Holder00ba37f0 *>((static_cast<PipboyPass*>(m_kPasses.GetAt(2))))->FUN_00ba37f0((::Tex00ba37f0 *)(::NiTextureStandIn *)(0));

    if ((*reinterpret_cast<::NiTextureStandIn * *>(&::recon7fbee0::DAT_01200818)))
    {

        (*reinterpret_cast<::NiTextureStandIn * *>(&::recon7fbee0::DAT_01200818))->DecRefCount();

        (*reinterpret_cast<::NiTextureStandIn * *>(&::recon7fbee0::DAT_01200818)) = 0;
    }

    float fTexelX = 0.0f;

    float fTexelY = 0.0f;

    if (m_kPasses.m_pBase[0])
    {

        PipboySourceTexture* pkSource = ((::PipboySourceTexture *)(reinterpret_cast<::FUN_00ba3780_struct *>((static_cast<PipboyPass*>(m_kPasses.m_pBase[0])))->FUN_00ba3780()));

        fTexelX = 1.0f / (float)pkSource->GetWidth() * ::DAT_011ae5e8;

        fTexelY = 1.0f / (float)pkSource->GetHeight() * ::DAT_011ae5e8;
    }

    PipboyConstants* pkConst0 = new PipboyConstants;

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst0))->AllocateShaderConstants(0, 4);

    pkConst0->unk55 = 1;

    pkConst0->unk56 = 1;

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst0))->SetShaderConstantVector4(0, ::DAT_011ae5ec, ::DAT_012007e8, ::DAT_011ae5f4, ::DAT_011ae5f0);

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst0))->SetShaderConstantVector4(1, ::DAT_012007f0, ::DAT_012007f4, ::DAT_011ae5f8, (*reinterpret_cast<bool *>(&::recon7fbee0::DAT_012007f8)) ? 1.0f : 0.0f);

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst0))->SetShaderConstantVector4(2, (*reinterpret_cast<float (*)[4]>(&::recon7fbee0::DAT_01200800))[0], (*reinterpret_cast<float (*)[4]>(&::recon7fbee0::DAT_01200800))[1], (*reinterpret_cast<float (*)[4]>(&::recon7fbee0::DAT_01200800))[2], (*reinterpret_cast<float (*)[4]>(&::recon7fbee0::DAT_01200800))[3]);

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst0))->SetShaderConstantVector4(3, fTexelX, fTexelY, 0.0f, 0.0f);

    PipboyConstants* pkConst1 = new PipboyConstants;

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst1))->AllocateShaderConstants(0, 5);

    pkConst1->unk55 = 1;

    pkConst1->unk56 = 1;

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst1))->SetShaderConstantVector4(0, ::DAT_011ae5ec, ::DAT_012007e8, ::DAT_011ae5f4, ::DAT_011ae5f0);

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst1))->SetShaderConstantVector4(1, ::DAT_012007f0, ::DAT_012007f4, ::DAT_011ae5f8, (*reinterpret_cast<bool *>(&::recon7fbee0::DAT_012007f8)) ? 1.0f : 0.0f);

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst1))->SetShaderConstantVector4(2, (*reinterpret_cast<float (*)[4]>(&::recon7fbee0::DAT_01200800))[0], (*reinterpret_cast<float (*)[4]>(&::recon7fbee0::DAT_01200800))[1], (*reinterpret_cast<float (*)[4]>(&::recon7fbee0::DAT_01200800))[2], (*reinterpret_cast<float (*)[4]>(&::recon7fbee0::DAT_01200800))[3]);

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst1))->SetShaderConstantVector4(3, fTexelX, fTexelY, 0.0f, 0.0f);

    reinterpret_cast<::ImageSpaceShaderParam *>((pkConst1))->SetShaderConstantVector4(4, 1.0f, 0.0f, 0.0f, 0.0f);

    m_kConstants.Assign(0, pkConst0);

    m_kConstants.Assign(1, pkConst1);

    reinterpret_cast<::BBA3C00Shader *>(this)->SetEntryRanges(0, 2, 1, 3, 4, 0, 0, 0, 0);

    reinterpret_cast<::BBA3C00Shader *>(this)->SetEntryRanges(1, 2, 1, 3, 4, 0, 0, 0, 0);

    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(0, (::ImageSpaceEffect *)(pkGeometry->unk08->unk120), (::ImageSpaceEffectParam *)(pkConst0), 0);

    reinterpret_cast<::FUN_00ba3c70_shell *>(this)->SetEffectAt(1, (::ImageSpaceEffect *)(pkGeometry->unk08->unk124), (::ImageSpaceEffectParam *)(pkConst1), 0);
}

#include "generated/data/bsshader/imagespaceeffectinterface.inc"
