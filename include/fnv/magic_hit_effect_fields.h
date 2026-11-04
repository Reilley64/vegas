#pragma once

class ActiveEffect;
class TESObjectREFR;

// The leading data members of MagicHitEffect (as in magic/magicshaderhiteffect_decls.h), for hit effect units whose
// stand-ins declare no fields. The release build reads `pCell` through the folded 4-byte getter at 0x0084e3a0 and
// `pTarget` through the one at 0x00441110 (BGSTerrainManager::GetMinLevel).
struct MagicHitEffectFields
{
    void* vtable;
    unsigned int refCount;
    float m_fParticleParameter5;
    void* pCell;
    float tempAge;
    bool bInitialized;
    ActiveEffect* pEffect;
    TESObjectREFR* pTarget;
};
