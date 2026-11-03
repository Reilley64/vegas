// bsshader/bsshadersdm.cpp: BSShaderInitializer (3 functions)

#include "fnv/decl/FUN_00bc1cc0_class.h"
#include "fnv/decl/FUN_00bc2660_cls.h"
#include "fnv/decl/ShaderPropertyRecord.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01201000.h"
#include "bsshadersdm_decls.h"

// @fnv 0x00bc2940
void BSShaderInitializer::InitializeMultiBounds()
{
    if (!DAT_01201f70)
    {
        BSFadeNode::InitializeMultiBounds();
        BSShaderRenderUtility::InitializeMultiBounds();
        DAT_01201f70 = true;
    }
}

// Calls FUN_00bc2660 with a and b when flag is false, otherwise calls FUN_00bc1cc0 with a and c.
// @fnv 0x00bc28b0
void DispatchFloatPair(float afFirst, float afSecond, float afThird, bool abUseThird)
{
    if (!abUseThird)
    {
        reinterpret_cast<::FUN_00bc2660_cls *>((afFirst))->FUN_00bc2660(afSecond, {});
        return;
    }
    reinterpret_cast<::FUN_00bc1cc0_class *>((afFirst))->FUN_00bc1cc0(afThird, {});
}

struct StrArr
{
    char _pad[8];
    unsigned short m8;
    unsigned short mA;
    char _padC[2];
    unsigned short mE;
};
struct GlobalObjectO2_00a7b610
{
    const char* f0;
};
// @fnv 0x00bc28f0
void FUN_00bc28f0(StrArr* pStrArr)
{
    reinterpret_cast<::ShaderPropertyRecord *>((pStrArr))->WriteToSettingArray({});
    char* pStr = ::FUN_00a7d330(::g_01201f68.f0);
    unsigned int uiIndex = pStrArr->mA;
    unsigned int cnt = pStrArr->m8;
    if (uiIndex >= cnt)
    {
        reinterpret_cast<::ViewerStrings *>((pStrArr))->SetSize(pStrArr->mE + uiIndex);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pStrArr))->SetAt(uiIndex, pStr);
}

#include "generated/data/bsshader/bsshadersdm.inc"
