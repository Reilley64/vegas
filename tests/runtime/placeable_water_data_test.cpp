#include "fnv/water/placeable_water.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <new>
#include <type_traits>

static_assert(std::is_same_v<decltype(PlaceableWaterData::ulFlags), std::uint32_t>);
static_assert(std::is_same_v<decltype(PlaceableWaterData::m_pOwningWater), TESWaterForm*>);

namespace
{
int failures;

void Check(bool condition, const char* name)
{
    if (!condition)
    {
        std::fprintf(stderr, "placeable water data: %s\n", name);
        ++failures;
    }
}

// Two distinct addresses to store as the owning water. They are compared, never read through.
alignas(void*) unsigned char waterAddresses[2 * sizeof(void*)];

TESWaterForm* Water(int index)
{
    return reinterpret_cast<TESWaterForm*>(&waterAddresses[index * sizeof(void*)]);
}

void Construction()
{
    alignas(PlaceableWaterData) unsigned char storage[sizeof(PlaceableWaterData)];
    std::memset(storage, 0xff, sizeof(storage));
    const PlaceableWaterData* data = new (storage) PlaceableWaterData;
    Check(data->ulFlags == 0, "construction clears the flags");
    Check(data->m_pOwningWater == nullptr, "construction clears the owning water");
}

void EveryBit()
{
    for (int bit = 0; bit < 32; ++bit)
    {
        const std::uint32_t mask = std::uint32_t{1} << bit;

        PlaceableWaterData empty;
        empty.SetFlags(mask, true);
        Check(empty.ulFlags == mask, "setting one bit sets only that bit");
        Check(empty.HasFlags(mask), "a set bit is reported");
        Check(!empty.HasFlags(~mask), "no other bit is reported");

        PlaceableWaterData full;
        full.ulFlags = 0xffffffffu;
        full.SetFlags(mask, false);
        Check(full.ulFlags == ~mask, "clearing one bit clears only that bit");
        Check(!full.HasFlags(mask), "a cleared bit is not reported");
        Check(full.HasFlags(~mask), "the other bits are still reported");
    }
}

void Mutation()
{
    PlaceableWaterData data;
    data.m_pOwningWater = Water(0);
    data.ulFlags = 0xa5;

    data.SetFlags(0x400, true);
    Check(data.ulFlags == 0x4a5, "flag 0x400 is set beside the existing flags");
    data.SetFlags(0x10, true);
    Check(data.ulFlags == 0x4b5, "flag 0x10 is set beside the existing flags");
    data.SetFlags(0x400, true);
    Check(data.ulFlags == 0x4b5, "setting a set flag changes nothing");
    data.SetFlags(0x10, false);
    Check(data.ulFlags == 0x4a5, "flag 0x10 is cleared alone");
    data.SetFlags(0x400, false);
    Check(data.ulFlags == 0xa5, "flag 0x400 is cleared alone");
    data.SetFlags(0x400, false);
    Check(data.ulFlags == 0xa5, "clearing a clear flag changes nothing");

    data.SetFlags(0x21, true);
    Check(data.ulFlags == 0xa5, "setting set bits of a combined mask keeps them");
    data.SetFlags(0x42, true);
    Check(data.ulFlags == 0xe7, "a combined mask sets each of its bits");
    data.SetFlags(0x21, false);
    Check(data.ulFlags == 0xc6, "a combined mask clears each of its bits");
    data.SetFlags(0, true);
    data.SetFlags(0, false);
    Check(data.ulFlags == 0xc6, "a zero mask changes nothing");

    // The flag entry takes its mask as an int; the top bit arrives negative.
    const int topBit = static_cast<int>(0x80000000u);
    data.SetFlags(static_cast<std::uint32_t>(topBit), true);
    Check(data.ulFlags == 0x800000c6u, "the top bit is set from a negative int mask");
    data.SetFlags(static_cast<std::uint32_t>(topBit), false);
    Check(data.ulFlags == 0xc6, "the top bit is cleared from a negative int mask");

    Check(data.m_pOwningWater == Water(0), "flag changes keep the owning water");
}

void Query()
{
    PlaceableWaterData data;
    Check(!data.HasFlags(0xffffffffu), "empty flags report no mask");
    data.ulFlags = 0x40000410u;
    Check(data.HasFlags(0x400), "flag 0x400");
    Check(data.HasFlags(0x10), "flag 0x10");
    Check(data.HasFlags(0x40000000u), "flag 0x40000000");
    Check(!data.HasFlags(0x20), "missing flag 0x20");
    Check(!data.HasFlags(0x80000000u), "missing top bit");
    Check(data.HasFlags(0x30), "a combined mask means any bit, not all");
    Check(!data.HasFlags(0), "a zero mask reports nothing");
}

void OwningWater()
{
    PlaceableWaterData data;
    data.ulFlags = 0x800000a5u;
    data.SetOwningWater(Water(1));
    Check(data.m_pOwningWater == Water(1), "the owning water set is the one read back");
    Check(data.ulFlags == 0x800000a5u, "setting the owning water keeps the flags");
}

void ClearCopyAndCompare()
{
    PlaceableWaterData original;
    original.ulFlags = 0x410;
    original.m_pOwningWater = Water(0);

    PlaceableWaterData copy;
    copy = original;
    Check(copy.ulFlags == 0x410, "assignment copies the flags");
    Check(copy.m_pOwningWater == Water(0), "assignment copies the owning water");
    Check(copy == original, "a copy compares equal");

    copy.SetFlags(0x20, true);
    Check(original.ulFlags == 0x410, "a copy does not alias the original's flags");
    Check(!(copy == original), "different flags compare unequal");
    copy.SetFlags(0x20, false);
    Check(copy == original, "restored flags compare equal");

    copy.SetFlags(0x80000000u, true);
    Check(!(copy == original), "flags that differ only in a high bit compare unequal");
    copy.SetFlags(0x80000000u, false);

    copy.m_pOwningWater = Water(1);
    Check(original.m_pOwningWater == Water(0), "a copy does not alias the original's owning water");
    Check(!(copy == original), "a different owning water compares unequal");
    copy.m_pOwningWater = nullptr;
    Check(!(copy == original), "a missing owning water compares unequal");

    original.Clear();
    Check(original.ulFlags == 0, "clear empties the flags");
    Check(original.m_pOwningWater == nullptr, "clear drops the owning water");
    Check(copy.ulFlags == 0x410, "clear leaves a copy's flags");
}
}  // namespace

int main()
{
    Construction();
    EveryBit();
    Mutation();
    Query();
    OwningWater();
    ClearCopyAndCompare();
    return failures == 0 ? 0 : 1;
}
