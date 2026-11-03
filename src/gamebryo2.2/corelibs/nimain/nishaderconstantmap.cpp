// gamebryo2.2/corelibs/nimain/nishaderconstantmap.cpp: NiShaderConstantMap (10 functions)

#include <cstdlib>
#include "runtime/crt.h"
#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/RefCountedPair.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f6000.h"
#include "nishaderconstantmap_decls.h"

// @fnv 0x00a9c2a0
void NiShaderConstantMap::InitializePoint3()
{
    ms_uiShaderConstantMapEntryCount = 136;
    (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024)) = new ShaderConstantMapEntry[ms_uiShaderConstantMapEntryCount];
    unsigned int index = 0;
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(0, NiFixedString("Invalid"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(1, NiFixedString("Proj"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(1, NiFixedString("Projection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(2, NiFixedString("InvProj"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(2, NiFixedString("InvProjection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(3, NiFixedString("View"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(4, NiFixedString("InvView"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(5, NiFixedString("World"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(6, NiFixedString("InvWorld"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(7, NiFixedString("WorldView"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(8, NiFixedString("InvWorldView"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(9, NiFixedString("ViewProj"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(9, NiFixedString("ViewProjection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(10, NiFixedString("InvViewProj"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(10, NiFixedString("InvViewProjection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(11, NiFixedString("WorldViewProj"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(11, NiFixedString("WorldViewProjection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(12, NiFixedString("InvWorldViewProj"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(12, NiFixedString("InvWorldViewProjection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(13, NiFixedString("ProjTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(13, NiFixedString("ProjectionTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(14, NiFixedString("InvProjTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(14, NiFixedString("InvProjectionTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(15, NiFixedString("ViewTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(16, NiFixedString("InvViewTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(17, NiFixedString("WorldTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(18, NiFixedString("InvWorldTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(19, NiFixedString("WorldViewTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(20, NiFixedString("InvWorldViewTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(21, NiFixedString("ViewProjTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(21, NiFixedString("ViewProjectionTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(22, NiFixedString("InvViewProjTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(22, NiFixedString("InvViewProjectionTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(23, NiFixedString("WorldViewProjTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(23, NiFixedString("WorldViewProjectionTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(24, NiFixedString("InvWorldViewProjTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(24, NiFixedString("InvWorldViewProjectionTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(25, NiFixedString("SkinWorldView"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(26, NiFixedString("InvSkinWorldView"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(27, NiFixedString("SkinWorldViewTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(28, NiFixedString("InvSkinWorldViewTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(29, NiFixedString("SkinWorldViewProj"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(29, NiFixedString("SkinWorldViewProjection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(30, NiFixedString("InvSkinWorldViewProj"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(30, NiFixedString("InvSkinWorldViewProjection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(31, NiFixedString("SkinWorldViewProjTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(31, NiFixedString("SkinWorldViewProjectionTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(32, NiFixedString("InvSkinWorldViewProjTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(32, NiFixedString("InvSkinWorldViewProjectionTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(33, NiFixedString("BoneMatrix3"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(34, NiFixedString("BoneMatrix4"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(35, NiFixedString("SkinBoneMatrix3"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(36, NiFixedString("SkinBoneMatrix4"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(37, NiFixedString("TexTransformBase"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(38, NiFixedString("InvTexTransformBase"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(39, NiFixedString("TexTransformBaseTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(40, NiFixedString("InvTexTransformBaseTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(41, NiFixedString("TexTransformDark"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(42, NiFixedString("InvTexTransformDark"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(43, NiFixedString("TexTransformDarkTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(44, NiFixedString("InvTexTransformDarkTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(45, NiFixedString("TexTransformDetail"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(46, NiFixedString("InvTexTransformDetail"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(47, NiFixedString("TexTransformDetailTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(48, NiFixedString("InvTexTransformDetailTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(49, NiFixedString("TexTransformGloss"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(50, NiFixedString("InvTexTransformGloss"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(51, NiFixedString("TexTransformGlossTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(52, NiFixedString("InvTexTransformGlossTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(53, NiFixedString("TexTransformGlow"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(54, NiFixedString("InvTexTransformGlow"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(55, NiFixedString("TexTransformGlowTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(56, NiFixedString("InvTexTransformGlowTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(57, NiFixedString("TexTransformBump"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(58, NiFixedString("InvTexTransformBump"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(59, NiFixedString("TexTransformBumpTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(60, NiFixedString("InvTexTransformBumpTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(61, NiFixedString("TexTransformDecal"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(62, NiFixedString("InvTexTransformDecal"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(63, NiFixedString("TexTransformDecalTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(64, NiFixedString("InvTexTransformDecalTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(65, NiFixedString("TexTransformShader"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(66, NiFixedString("InvTexTransformShader"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(67, NiFixedString("TexTransformShaderTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(68, NiFixedString("InvTexTransformShaderTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(69, NiFixedString("LightPosWS"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(70, NiFixedString("LightDirWS"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(71, NiFixedString("LightPosOS"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(72, NiFixedString("LightDirOS"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(73, NiFixedString("MaterialDiffuse"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(73, NiFixedString("Diffuse"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(74, NiFixedString("MaterialAmbient"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(74, NiFixedString("Ambient"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(75, NiFixedString("MaterialSpecular"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(75, NiFixedString("Specular"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(76, NiFixedString("MaterialEmissive"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(77, NiFixedString("MaterialPower"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(77, NiFixedString("SpecularPower"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(78, NiFixedString("EyePos"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(79, NiFixedString("EyeDir"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(80, NiFixedString("TaylorSin"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(81, NiFixedString("TaylorCos"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(82, NiFixedString("time"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(83, NiFixedString("sin_time"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(84, NiFixedString("cos_time"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(85, NiFixedString("tan_time"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(86, NiFixedString("time_sin_cos_tan"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(87, NiFixedString("AmbientLight"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(92, NiFixedString("TexTransformParallax"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(93, NiFixedString("InvTexTransformParallax"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(94, NiFixedString("TexTransformParallaxTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(95, NiFixedString("InvTexTransformParallaxTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(88, NiFixedString("TexTransformNormal"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(89, NiFixedString("InvTexTransformNormal"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(90, NiFixedString("TexTransformNormalTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(91, NiFixedString("InvTexTransformNormalTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(96, NiFixedString("SkinWorld"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(97, NiFixedString("InvSkinWorld"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(98, NiFixedString("SkinWorldTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(99, NiFixedString("InvSkinWorldTranspose"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(100, NiFixedString("FogDensity"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(101, NiFixedString("FogNearFar"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(102, NiFixedString("FogColor"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(103, NiFixedString("BumpMatrix"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(104, NiFixedString("BumpLumaAndScale"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(105, NiFixedString("ParallaxOffset"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(106, NiFixedString("TexSizeBase"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(107, NiFixedString("TexSizeDark"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(108, NiFixedString("TexSizeDetail"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(109, NiFixedString("TexSizeGloss"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(110, NiFixedString("TexSizeGlow"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(111, NiFixedString("TexSizeBump"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(111, NiFixedString("TexSizeNormal"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(111, NiFixedString("TexSizeParallax"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(114, NiFixedString("TexSizeDecal"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(115, NiFixedString("TexSizeShader"))));
    }

    ms_uiConstantMapEntryCount = 25;
    (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c)) = new ShaderConstantMapEntry[ms_uiConstantMapEntryCount];
    index = 0;
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(0, NiFixedString("Invalid"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(1, NiFixedString("Dimmer"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(2, NiFixedString("UndimmedAmbient"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(3, NiFixedString("UndimmedDiffuse"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(4, NiFixedString("UndimmedSpecular"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(5, NiFixedString("Ambient"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(6, NiFixedString("Diffuse"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(7, NiFixedString("Specular"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(8, NiFixedString("WorldPosition"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(9, NiFixedString("ModelPosition"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(10, NiFixedString("WorldDirection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(11, NiFixedString("ModelDirection"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(12, NiFixedString("WorldTransform"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(13, NiFixedString("ModelTransform"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(14, NiFixedString("SpotAttenuation"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(15, NiFixedString("Attenuation"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(16, NiFixedString("WorldProjectionMatrix"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(17, NiFixedString("ModelProjectionMatrix"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(18, NiFixedString("WorldProjectionTranslation"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(19, NiFixedString("ModelProjectionTranslation"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(20, NiFixedString("WorldClippingPlane"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(21, NiFixedString("ModelClippingPlane"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(22, NiFixedString("TexCoordGen"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(23, NiFixedString("WorldProjectionTransform"))));
    }
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[index++];
        reinterpret_cast<::RefCountedPair *>((void *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(entry))->Assign((const ::RefCountedPair *)&(const ::NiShaderConstantMap::ShaderConstantMapEntry &)(ShaderConstantMapEntry(24, NiFixedString("ModelProjectionTransform"))));
    }
}

// Copies key into name, and if key ends with _<digit>, strips that suffix and stores the parsed digit in extra.
// @fnv 0x00a9bee0
bool NiShaderConstantMap::ParseConstantName(const char* key, char* name, unsigned int size, unsigned int& extra)
{
    char buffer[260];
    if (sizeof(buffer) > size + 1)
        return false;
    fnv::crt::strcpy_s(buffer, sizeof(buffer), key);
    fnv::crt::strcpy_s(name, sizeof(buffer), key);
    char* suffix = strchr(buffer, '_');
    if (suffix && isdigit(suffix[1]) && suffix[2] == 0)
    {
        char* context;
        char* prefix = fnv::crt::strtok_s(buffer, "_", &context);
        char* number = fnv::crt::strtok_s(0, "_", &context);
        if (number)
        {
            extra = std::atoi(number);
            strcpy_s(name, size, prefix);
        }
    }
    return true;
}

// @fnv 0x00a9bfd0
bool NiShaderConstantMap::FindConstantMapping(const char* key, unsigned int& mapping, unsigned int& extra)
{
    char name[260];
    if (!ParseConstantName(key, name, sizeof(name), extra))
        return false;
    for (unsigned int i = 0; i < ms_uiShaderConstantMapEntryCount; ++i)
    {
        ShaderConstantMapEntry& entry = (*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f6024))[i];
        if (!NiStricmp(entry.m_kConstantName, name))
        {
            mapping = entry.m_uiConstantID;
            return true;
        }
    }
    return false;
}

enum NiShaderAttributeDesc_AttributeType
{
    NiShaderAttributeDesc_AttributeType_0 = 0,
    NiShaderAttributeDesc_AttributeType_1 = 1,
    NiShaderAttributeDesc_AttributeType_2 = 2,
    NiShaderAttributeDesc_AttributeType_3 = 3,
    NiShaderAttributeDesc_AttributeType_4 = 4,
    NiShaderAttributeDesc_AttributeType_5 = 5,
    NiShaderAttributeDesc_AttributeType_6 = 6,
    NiShaderAttributeDesc_AttributeType_7 = 7,
    NiShaderAttributeDesc_AttributeType_8 = 8,
    NiShaderAttributeDesc_AttributeType_9 = 9,
    NiShaderAttributeDesc_AttributeType_10 = 10,
    NiShaderAttributeDesc_AttributeType_11 = 11,
    NiShaderAttributeDesc_AttributeType_12 = 12,
    NiShaderAttributeDesc_AttributeType_13 = 13,
    NiShaderAttributeDesc_AttributeType_14 = 14,
    NiShaderAttributeDesc_AttributeType_15 = 15,
    NiShaderAttributeDesc_AttributeType_16 = 16,
    NiShaderAttributeDesc_AttributeType_17 = 17,
    NiShaderAttributeDesc_AttributeType_18 = 18,
    NiShaderAttributeDesc_AttributeType_19 = 19,
    NiShaderAttributeDesc_AttributeType_20 = 20,
    NiShaderAttributeDesc_AttributeType_21 = 21,
    NiShaderAttributeDesc_AttributeType_22 = 22,
    NiShaderAttributeDesc_AttributeType_23 = 23,
    NiShaderAttributeDesc_AttributeType_24 = 24
};

// Maps a 1-based mapping ID to an attribute type, setting the register and float counts, returning type 0 for unknown IDs.
// @fnv 0x00a9bcd0
NiShaderAttributeDesc_AttributeType __cdecl GetAttributeTypeForMapping(unsigned int uiMappingID,
                                                                       unsigned int& uiRegCount,
                                                                       unsigned int& uiFloatCount)
{
    uiMappingID--;
    uiRegCount = 1;
    uiFloatCount = 4;
    if (uiMappingID > 0x17)
        return NiShaderAttributeDesc_AttributeType_0;
    switch (uiMappingID)
    {
    case 0:
    case 21:
        uiFloatCount = 1;
        return NiShaderAttributeDesc_AttributeType_4;
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
    case 13:
    case 14:
    case 17:
    case 18:
    case 19:
    case 20:
        return NiShaderAttributeDesc_AttributeType_7;
    case 11:
    case 12:
    case 22:
    case 23:
        uiRegCount = 4;
        uiFloatCount = 0x10;
        return NiShaderAttributeDesc_AttributeType_9;
    case 15:
    case 16:
        uiRegCount = 3;
        uiFloatCount = 0xc;
        return NiShaderAttributeDesc_AttributeType_8;
    default:
        return NiShaderAttributeDesc_AttributeType_0;
    }
}

// @fnv 0x00a9bd60
unsigned int FUN_00a9bd60(const char*, unsigned int, unsigned int, const char*)
{
    return 0x30;
}

// @fnv 0x00a9bd70
int FUN_00a9bd70(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
    return 0x30;
}

// @fnv 0x00a9bd80
int FUN_00a9bd80(int a, int b, int c, int d, int e, int f)
{
    return 0x30;
}

// @fnv 0x00a9bd90
unsigned int FUN_00a9bd90(const char* pszKey, unsigned int uiShaderRegister, const char* pszVariableName,
                                    unsigned int uiObjectIndex, int eObjectType)
{
    return 0x30;
}


// Searches the shader constant map table for a case-insensitive name match and writes the matching entry's ID to uiMappingID, returning true if found.
// @fnv 0x00a9c0e0
bool __cdecl LookupShaderConstantMapping(const char* pcName, unsigned int* uiMappingID)
{
    unsigned int uiIndex;
    const NiShaderConstantMap::ShaderConstantMapEntry* pkMapping;

    for (uiIndex = 0; uiIndex < NiShaderConstantMap::ms_uiConstantMapEntryCount; ++uiIndex)
    {
        pkMapping = &(*reinterpret_cast<::NiShaderConstantMap::ShaderConstantMapEntry * *>(&::fnv_00a9fda0::DAT_011f602c))[uiIndex];
        if (::NiStricmp(pkMapping->m_kConstantName, pcName) == 0)
        {
            *uiMappingID = pkMapping->m_uiConstantID;
            return true;
        }
    }
    return false;
}

struct ShaderLight
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
    unsigned char enabled;
    unsigned char type;
};

struct ShaderLightNode
{
    ShaderLightNode* next;
    ShaderLight* data;

    static inline ShaderLight* GetNext(ShaderLightNode*& node)
    {
        if (!node)
            return 0;
        ShaderLight* light = node->data;
        node = node->next;
        return light;
    }
};

struct ShaderLights
{
    int unk00;
    int unk04;
    int unk08;
    ShaderLightNode* classified;
    ShaderLightNode* special;
    ShaderLightNode* ambient;
    ShaderLight* primary;
    ShaderLight* secondary;
};

// Returns the enabled light of the requested type at index wanted from the classified, ambient or special list, or the primary/secondary light.
// @fnv 0x00a9c130
ShaderLight* GetLightByType(ShaderLights* lights, unsigned int type, unsigned int wanted)
{
    ShaderLight* result = 0;
    if (lights)
    {
        switch (type)
        {
        case 1:
        case 2:
        case 3:
        case 4: {
            ShaderLightNode* pNode = lights->classified;
            unsigned int count = 0;
            while (pNode)
            {
                ShaderLight* light = ShaderLightNode::GetNext(pNode);
                unsigned char enabled = light->enabled;
                unsigned int special = (light->type > type && type == 1) ? type : 0;
                unsigned char match = (light->type == type) ^ (unsigned char)special;
                if (match && enabled)
                {
                    if (count++ == wanted)
                    {
                        result = light;
                        break;
                    }
                }
            }
            break;
        }
        case 5:
            result = lights->primary;
            if (result && !result->enabled)
                result = 0;
            break;
        case 6: {
            ShaderLightNode* pNode = lights->ambient;
            unsigned int found = 0;
            while (pNode)
            {
                ShaderLight* light = pNode->data;
                pNode = pNode->next;
                if (light && light->enabled && found++ == wanted)
                {
                    result = light;
                    break;
                }
            }
            break;
        }
        case 7: {
            ShaderLightNode* pNode = lights->special;
            unsigned int found = 0;
            while (pNode)
            {
                ShaderLight* light = pNode->data;
                pNode = pNode->next;
                if (light && light->enabled && found++ == wanted)
                {
                    result = light;
                    break;
                }
            }
            break;
        }
        case 8:
            result = lights->secondary;
            if (result && !result->enabled)
                result = 0;
            break;
        }
    }

    return result;
}
