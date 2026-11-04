// REVIEW-ONLY declaration closure. Requires selector_same_tu_types.h in existing modelloader.cpp.
// No function definitions, global objects, baseline changes or alternate TU.
#ifndef MODELLOADER_ADDON_GETTER_DECLARATIONS_H
#define MODELLOADER_ADDON_GETTER_DECLARATIONS_H


// Real public internal type. This declaration is ONLY for nonintegral STRUCTs;
// the actual source selects STRUCT as base for these instantiations. No helpers.
namespace _BitfieldInternal {
template <class TYPE, class STRUCT> class BitfieldBase : public STRUCT
{
};
}

class BGSAddonNode : public TESBoundObject, public TESModelTextureSwap
{
  public:
    struct _AddonNodeFlags
    {
        enum Flags
        {
            IS_MASTER_PARTICLE_SYSTEM = 1u << 0
        };
        bool bIsMasterParticleSystem : 1;
    };
    typedef _AddonNodeFlags::Flags AddonNodeFlags;
    struct AddonData
    {
        unsigned short m_usAddonNodeIndex;
        // Exact resolved public Bitfield<_AddonNodeFlags> type, no new alias.
        _BitfieldInternal::BitfieldBase<unsigned char, _AddonNodeFlags> m_ucEntryType;
    };
    unsigned int uiIndex;
    TESSound* SoundAssetTmp;
    AddonData kData;
    unsigned int uiParticleSystemIndex;
    bool IsMasterParticleSystem() const;
};

#endif
