
// src/bsshader/bsshaderbloodsplatter_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshaderbloodsplatter.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/E7DEF0TextureStage.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0068ab80_class.h"
#include "fnv/decl/FUN_00be1750_shell.h"
#include "fnv/decl/FUN_00e7ecd0_cls.h"
#include "fnv/decl/StageSet.h"
#include "fnv/decl/StateGroup.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_00e76000.h"
#include "fnv/symbols_00e7e000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fe000.h"
#include "fnv/symbols_0126f000.h"
#include "bsshaderbloodsplatter_types_BSShaderBloodSplatter.h"
#include "bsshaderbloodsplatter_types_BSShaderManager.h"
#include "bsshaderbloodsplatter_types_NiConsoleShaderDeclaration.h"
extern char g_splatterWhiteFlashPath[];
struct SplatterFloat4
{
    float x;
    float y;
    float z;
    float w;
};
#include "bsshaderbloodsplatter_decls.h"
struct SplatterShaderInfo
{
    const char* file;
    _D3DXMACRO macros[9];
};
struct FUN_00b807c0_shell
{
    int FUN_00b807c0(void* a, void* b);
};
int* __cdecl FUN_00b807b0();

struct FUN_0068ab60_shell
{
    void FUN_0068ab60();
};
// @fnv 0x0068ab60
void FUN_0068ab60_shell::FUN_0068ab60()
{
    reinterpret_cast<::FUN_0068ab80_class *>(this)->FUN_0068ab80();
}
