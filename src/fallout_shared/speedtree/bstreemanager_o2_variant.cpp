
// src/fallout_shared/speedtree/bstreemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/speedtree/bstreemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/B6B330Renderer.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LookupHandler.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0051d000.h"
#include "fnv/symbols_0054e000.h"
#include "fnv/symbols_00664000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fd000.h"
#include "bstreemanager_decls.h"
void ClampAndStoreValue(float value);
struct NP
{
    NP& operator=(void*);
};
struct FUN_006652c0_shell
{
    void SetByteAtOffset44(unsigned char value);
};
struct Setting_S
{
    float f;
};
struct originalRuntimeFloatSetting1295_t
{
};
float FUN_006655a0();

struct NiRenderTargetGroup;

struct NiRenderer
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual NiRenderTargetGroup* GetCurrentRenderTargetGroup();
    static NiRenderer* ms_pRenderer;
};

struct GraphicsRenderer : public NiRenderer
{
    bool BeginUsingRenderTargetGroup(NiRenderTargetGroup* pkTarget, unsigned int uiClone);
};


// @fnv 0x00b6b7d0
void FUN_00b6b7d0(NiRenderTargetGroup* pkTarget, unsigned int uiClone)
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (pkTarget == 0)
    {
        pkTarget = pkRenderer->GetCurrentRenderTargetGroup();
    }
    if (*(bool*)((char*)pkRenderer + 0x208))
    {
        reinterpret_cast<::B6B330Renderer *>((pkRenderer))->TryUnlock();
    }
    NiRenderTargetGroup* pkTarget2 = pkTarget;
    if (pkTarget2 == 0)
    {
        pkTarget2 = NiRenderer::ms_pRenderer->GetCurrentRenderTargetGroup();
    }
    ((GraphicsRenderer*)NiRenderer::ms_pRenderer)->BeginUsingRenderTargetGroup(pkTarget2, uiClone);
    ::PushRefCountedSlot((int *)(pkTarget));
}
