// Native data of a placeable water form and the owner's creation entry.
// See docs/placeable-water.md.
#ifndef FNV_WATER_PLACEABLE_WATER_H
#define FNV_WATER_PLACEABLE_WATER_H

#include <cstddef>
#include <cstdint>

struct BGSPlaceableWater;
class TESForm;
struct TESWaterForm;

// The data member of BGSPlaceableWater. The flags keep the record's 32 bits;
// the water form is a native pointer.
class PlaceableWaterData
{
  public:
    std::uint32_t ulFlags = 0;
    TESWaterForm* m_pOwningWater = nullptr;

    // Sets or clears exactly the bits of auiMask.
    void SetFlags(std::uint32_t auiMask, bool abSet)
    {
        if (abSet)
            ulFlags |= auiMask;
        else
            ulFlags &= ~auiMask;
    }

    // True when any bit of auiMask is set.
    bool HasFlags(std::uint32_t auiMask) const { return (ulFlags & auiMask) ? true : false; }

    // Stores the water form that owns this placeable water. The flags are kept.
    void SetOwningWater(TESWaterForm* apOwner) { m_pOwningWater = apOwner; }

    void Clear()
    {
        ulFlags = 0;
        m_pOwningWater = nullptr;
    }

    bool operator==(const PlaceableWaterData& arOther) const
    {
        return ulFlags == arOther.ulFlags && m_pOwningWater == arOther.m_pOwningWater;
    }
};

static_assert(offsetof(PlaceableWaterData, ulFlags) == 0);

namespace fnv::water
{
// The owner unit's entries for a caller that cannot see the complete type.
// NewPlaceableWater allocates and constructs one complete BGSPlaceableWater.
// PlaceableWaterForm returns its TESForm base.
// SetOwningWater stores the water form that owns apWater in its data.
::BGSPlaceableWater* NewPlaceableWater();
::TESForm* PlaceableWaterForm(::BGSPlaceableWater* apWater);
void SetOwningWater(::BGSPlaceableWater* apWater, ::TESWaterForm* apOwner);
}  // namespace fnv::water

#endif
