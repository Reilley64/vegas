
// src/fallout/ai/actor_magic_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESActorBase). The skeleton of src/fallout/ai/actor_magic.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/Actor8c37.h"
#include "fnv/decl/B88B5A0Actor.h"
#include "fnv/decl/B8B10Owner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSAnimGroupSequence.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00422820_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_0049bb50_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f9ad0_shell.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_008845a0_shell.h"
#include "fnv/decl/FUN_0088b510_cls.h"
#include "fnv/decl/FUN_00893500_shell.h"
#include "fnv/decl/FUN_008aced0_cls.h"
#include "fnv/decl/FUN_008adcb0_shell.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_008c4560_shell.h"
#include "fnv/decl/FUN_008c47d0_shell.h"
#include "fnv/decl/FUN_008c51c0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_0096d490_shell.h"
#include "fnv/decl/FUN_00ad8570_S.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/RestoreActionPointsDetail__RestoreActionPointsEntry.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00418940__FUN_00418940_shell.h"
#include "fnv/decl/fnv_0041a090__FUN_0041a090_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00887d00__InitActor.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00804000.h"
#include "fnv/symbols_008bc000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "actor_magic_decls_rtti2_actor_magic.h"
#include "actor_magic_actor.h"
#include "BaseProcess.h"
// HighProcess call targets used by actor magic (canonical HighProcess
// header has no method declarations yet; only calls are emitted here,
// so no layout is required).
class HighProcess
{
  public:
};
class NiNode;
struct BSShaderRenderUtility
{
    static void SetAlphaOnNode(NiNode* pNode, float fAlpha);
public:
    bool IsRenderTargetId(unsigned int);
};
// Node getter behind 0x00950bb0. It reads a node pointer at +0x694, which
// only exists on PlayerCharacter-sized objects, so it is declared here on
// a minimal PlayerCharacter until its canonical home is confirmed.
class PlayerCharacter
{
  public:
};


class TESCreature
{
  public:
public:
    signed char GetCreatureType() const;
};

struct ActorCreatureStandIn
{
    float FUN_0088b850();
// @fnv 0x008d4750
    float FUN_008d4750()
    {
        float j = 0.0f;
        TESCreature* p = dynamic_cast< ::TESCreature*>(((::Actor*)this)->GetActorBase());
        if (!p)
        {
            j = FUN_0088b850();
        }
        else
        {
            j = (float)reinterpret_cast<::FUN_005f9ad0_shell *>((p))->FUN_005f9ad0();
            if (p->GetCreatureType() == 7)
            {
                j *= ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting704))))))->f;
            }
        }
        return j;
    }
};

float (ActorCreatureStandIn::*fnv_008d4750_entry)() = &ActorCreatureStandIn::FUN_008d4750;
