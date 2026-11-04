#include <cstddef>
// bsshader/speedtreeleafshader.cpp: SpeedTreeLeafShader (5 functions)

#include <cstddef>
#include <cstring>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00bb1c10.h"
#include "fnv/decl/ShaderSetup.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00e76000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_010a1000.h"
#include "fnv/symbols_010af000.h"
#include "fnv/symbols_010b8000.h"
#include "fnv/symbols_010b9000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_01200000.h"
#include "speedtreeleafshader_decls.h"
#include "speedtreeleafshader_types_SpeedTreeLeafShader.h"
#include "speedtreeleafshader_types_NiD3DShaderConstantMap.h"
#include "speedtreeleafshader_types_SpeedTreeShader.h"

class SpeedTreeLeafShaderConstantMapCalls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual unsigned int AddConstant(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*,
                                     unsigned int, unsigned int, const void*, bool);
};

struct SpeedTreeLeafShaderColor
{
    float r, g, b, a;
    SpeedTreeLeafShaderColor(float R, float G, float B, float A) : r(R), g(G), b(B), a(A)
    {}
};

// @fnv 0x00bb2a00
SpeedTreeLeafShader::SpeedTreeLeafShader() : BSShader()
{
    m_iPassId = 9;
    std::memset(m_afShaderConstants, 0, sizeof(m_afShaderConstants));
    reinterpret_cast<SpeedTreeLeafShaderColor&>(DAT_01200638) = SpeedTreeLeafShaderColor(1, 1, 1, 1);
    reinterpret_cast<SpeedTreeLeafShaderColor&>(DAT_01200648) = SpeedTreeLeafShaderColor(1, 1, 1, 1);
    reinterpret_cast<SpeedTreeLeafShaderColor&>(DAT_01200658) = SpeedTreeLeafShaderColor(0, 0, 0, 0);
    reinterpret_cast<SpeedTreeLeafShaderColor&>(DAT_01200668) = SpeedTreeLeafShaderColor(0, 0, 0, 0);
}

// Creates the vertex shader constant map if absent and registers the leaf shader constants, including a conditional one when DAT_011F941E is set.
// @fnv 0x00bb2d10
void SpeedTreeLeafShader::UpdateShaderConstants()
{
    if (m_spSecondShaderConstantMap.m_pObject)
        return;

    m_spSecondShaderConstantMap = new NiD3DShaderConstantMap(m_pShaderObject, NiGPUProgram__ProgramType_PROGRAM_VERTEX);

    reinterpret_cast<SpeedTreeLeafShaderConstantMapCalls*>(m_spSecondShaderConstantMap.m_pObject)
        ->AddConstant(DAT_010A1E50, 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
    reinterpret_cast<SpeedTreeLeafShaderConstantMapCalls*>(m_spSecondShaderConstantMap.m_pObject)
        ->AddConstant(DAT_010AF568, 0x10000007, 0, 5, 1, ::DAT_01011584, 0x10, 4, DAT_011FA0C0, false);
    reinterpret_cast<SpeedTreeLeafShaderConstantMapCalls*>(m_spSecondShaderConstantMap.m_pObject)
        ->AddConstant(DAT_010B92F8, 0x10000007, 0, 6, 1, ::DAT_01011584, 0x10, 4, DAT_011FA0D0, false);
    reinterpret_cast<SpeedTreeLeafShaderConstantMapCalls*>(m_spSecondShaderConstantMap.m_pObject)
        ->AddConstant(DAT_010B92E8, 0x10000007, 0, 7, 1, ::DAT_01011584, 0x10, 4, DAT_011FA0E0, false);
    reinterpret_cast<SpeedTreeLeafShaderConstantMapCalls*>(m_spSecondShaderConstantMap.m_pObject)
        ->AddConstant(DAT_010AF60C, 0x10000007, 0, 8, 1, ::DAT_01011584, 0x10, 4, DAT_011FA280, false);
    reinterpret_cast<SpeedTreeLeafShaderConstantMapCalls*>(m_spSecondShaderConstantMap.m_pObject)
        ->AddConstant(DAT_010AF5E4, 0x10000007, 0, 9, 1, ::DAT_01011584, 0x10, 4, DAT_011FA290, false);

    if ((*reinterpret_cast<unsigned char *>(&::DAT_011f941e)))
    {
        reinterpret_cast<SpeedTreeLeafShaderConstantMapCalls*>(m_spSecondShaderConstantMap.m_pObject)
            ->AddConstant(DAT_010B92DC, 0x10000004, 0, 10, 1, ::DAT_01011584, 4, 4, (*reinterpret_cast<const unsigned char (*)[]>(&::DAT_011f918c)), false);
    }

    reinterpret_cast<SpeedTreeLeafShaderConstantMapCalls*>(m_spSecondShaderConstantMap.m_pObject)
        ->AddConstant(DAT_010B8C34, 0x10000009, 0, 11, 6, ::DAT_01011584, 0x60, 4, DAT_01200618, false);

    SpeedTreeLeafShaderConstantMapSetup::ConfigureShaderConstantMap(m_spSecondShaderConstantMap.m_pObject, 0x11);

    reinterpret_cast<SpeedTreeLeafShaderConstantMapCalls*>(m_spSecondShaderConstantMap.m_pObject)
        ->AddConstant(DAT_010B92D0, 0x10000009, 0, 0x22, 0x30, ::DAT_01011584, 0x300, 4, m_afShaderConstants, false);
}

struct FUN_00bb2bb0_holder
{
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00bb2bb0
void* FUN_00bb2bb0_holder::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00bb1c10 *>(this)->FUN_00bb1c10::~FUN_00bb1c10();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x38C);
    return this;
}

struct NiRenderer;
struct NiD3DVertexDeclaration
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
    virtual bool SetEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void v36();
    virtual bool SetEntry8(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                           unsigned int, unsigned int);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void Finalize();
};
struct LeafV
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
    virtual void Init19();
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
    virtual void SetDecl(NiD3DVertexDeclaration*);
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
    virtual void Init71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void Init79();
};
struct BSFadeNode
{
};
struct FadeTag
{
};
inline void* operator new(std::size_t sz, FadeTag*)
{
    return ::operator new(sz);
}
inline void operator delete(void* p, FadeTag*)
{
    ::operator delete(p);
}
struct FUN_00bb1d40_t
{
};

// @fnv 0x00bb2c00
SpeedTreeLeafShader* CreateSpeedTreeLeafShader()
{
    NiD3DVertexDeclaration* pDecl = ::FUN_00e76700(::DAT_011f9508, 4, 1);
    pDecl->SetEntry(0, 0, 0, 2, 0);
    pDecl->SetEntry(1, 3, 3, 2, 0);
    pDecl->SetEntry(2, 7, 5, 1, 0);
    pDecl->SetEntry8(0, 3, 8, 0x80000000, 3, 2, 0, 0);
    pDecl->Finalize();
    SpeedTreeLeafShader* pLeafShader = new ((FadeTag*)0) SpeedTreeLeafShader;
    ((LeafV*)pLeafShader)->Init19();
    ((LeafV*)pLeafShader)->Init79();
    reinterpret_cast<::ShaderSetup *>((((FUN_00bb1d40_t*)pLeafShader)))->CreatePasses();
    ((LeafV*)pLeafShader)->Init71();
    ((LeafV*)pLeafShader)->SetDecl(pDecl);
    return pLeafShader;
}

struct FUN_00bb2be0_shell : LeafV
{
    void FUN_00bb2be0();
};

// @fnv 0x00bb2be0
void FUN_00bb2be0_shell::FUN_00bb2be0()
{
    this->Init79();
    reinterpret_cast<::ShaderSetup *>((reinterpret_cast<FUN_00bb1d40_t*>(this)))->CreatePasses();
}

#include "generated/data/bsshader/speedtreeleafshader.inc"
