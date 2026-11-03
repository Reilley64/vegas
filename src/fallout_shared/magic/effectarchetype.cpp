// fallout_shared/magic/effectarchetype.cpp: free functions (1 function)

#include <cstdint>

#include "fnv/decl/FUN_008041c0_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "effectarchetype_decls.h"
// Looks up the effect archetype's factory by the effect's archetype and creates an ActiveEffect via it, then passes source to the created effect.
// @fnv 0x00403ab0
ActiveEffect* MagicEffectSystem::Activate(MagicCaster* caster, MagicItem* item, EffectItem* effect,
                                          TESBoundObject* source)
{
    ActiveEffect* pCreateEffect = 0;
    EffectSetting* m_pLinkedEffect = effect ? (EffectSetting*)((std::uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((AnimIdle*)effect)))->FUN_00825c00())) : 0;
    int m_eEffectTypeItem = m_pLinkedEffect->GetArchetype();
    EffectFactory pFactory = DAT_01183324[m_eEffectTypeItem].factory;
    if (pFactory)
        pCreateEffect = pFactory(caster, item, effect);
    if (pCreateEffect)
        reinterpret_cast<::FUN_008041c0_shell *>((pCreateEffect))->InitFromSource(source);
    return pCreateEffect;
}

#include "generated/data/fallout_shared/magic/effectarchetype.inc"
