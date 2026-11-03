// bsshader/volumetricfogshader.cpp: VolumetricFogShader (2 functions)

#include "fnv/symbols_00e76000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_010a1000.h"
#include "fnv/symbols_011f9000.h"
#include "volumetricfogshader_decls.h"

// @fnv 0x00bc59b0
BSShader* VolumetricFogShader::CreateShader()
{
    NiD3DVertexDeclaration* declaration = ::FUN_00e76700(DAT_011f9508, 2, 1);
    unsigned int zero = 0;
    NiConsoleShaderDeclarationVTable* declarationVTable =
        reinterpret_cast<NiConsoleShaderDeclarationVTable*>(declaration);
    declarationVTable->vfn_8c(zero, zero, zero, 2, zero);
    declarationVTable->vfn_b4();

    VolumetricFogShader* shader = new VolumetricFogShader;
    VolumetricFogShaderVTable* shaderVTable = reinterpret_cast<VolumetricFogShaderVTable*>(shader);
    shaderVTable->vfn_4c();
    shaderVTable->vfn_13c();
    shaderVTable->vfn_148();
    shaderVTable->vfn_11c();
    shaderVTable->vfn_c0(declaration);
    return reinterpret_cast<BSShader*>(shader);
}

// @fnv 0x00bc5a80
void VolumetricFogShader::UpdateShaderConstants()
{
    if (!m_spFirstShaderConstantMap.m_pObject)
    {
        m_spFirstShaderConstantMap = new NiD3DShaderConstantMap(m_pShaderObject, 2);
        m_spFirstShaderConstantMap->vfn_8(DAT_010babec, 0x10000007, 0, 0, 1, ::DAT_01011584, 16, 4, &m_data98,
                                          false);
    }

    if (!m_spSecondShaderConstantMap.m_pObject)
    {
        m_spSecondShaderConstantMap = new NiD3DShaderConstantMap(m_pShaderObject, 0);
        m_spSecondShaderConstantMap->vfn_68(DAT_010A1E50, 0x20000009, 0, ::DAT_01011584, 0, 0, 0, 0);
        m_spSecondShaderConstantMap->vfn_8(DAT_010bb0ac, 0x10000007, 0, 4, 1, ::DAT_01011584, 16, 4, &m_data88,
                                           false);
    }
}
