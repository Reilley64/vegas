#include "fnv/ni_point3_startup_table.h"
#include "gamebryo2.2/corelibs/nimain/nipixelformat_decls.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace
{
constexpr unsigned int count = 17;
static_assert(sizeof(NiPoint3StartupTable) == count * sizeof(int));

// A record of the same extent, read one byte at a time.
struct Bytes
{
    unsigned char bytes[sizeof(NiPoint3StartupTable)];
};

void require(bool condition, const char* message)
{
    if (!condition)
    {
        std::fprintf(stderr, "FAIL: %s\n", message);
        std::abort();
    }
}

// The owner-approved native default of VEGAS-85 (2026-11-12), and the list
// the owner stored before it, which lacks the zero before the first 264.
constexpr NiPoint3StartupTable approved = {{8193, 1, 0, -1, 0, 0, 0, 264, 1, 0, 264, 2, 0, 264, 3, 0, 264}};
constexpr NiPoint3StartupTable before = {{8193, 1, 0, -1, 0, 0, 264, 1, 0, 264, 2, 0, 264, 3, 0, 264, 3}};

// The bit offsets of red, green, blue and alpha that
// NiPixelFormat::GetPixelBitData, 0x00a62230, reads from a record.
// CreateCheckerboardTexture shifts each channel by a call to that address.
bool rgba_offsets(NiPoint3StartupTable& table)
{
    const NiPixelFormat& format = NiPoint3StartupTableAs<NiPixelFormat>(table);
    return format.GetPixelBitData(NiPixelFormat::COMP_RED) == 0 &&
           format.GetPixelBitData(NiPixelFormat::COMP_GREEN) == 8 &&
           format.GetPixelBitData(NiPixelFormat::COMP_BLUE) == 16 &&
           format.GetPixelBitData(NiPixelFormat::COMP_ALPHA) == 24;
}

bool same_bytes()
{
    return std::memcmp(NiPoint3StartupTableAs<Bytes>(gNiPoint3StartupDst).bytes,
                       NiPoint3StartupTableAs<Bytes>(gNiPoint3StartupSrc).bytes, sizeof(Bytes)) == 0;
}
} // namespace

int main()
{
    // The two globals do not share storage. The addresses are compared as
    // integers: ordering pointers into two different objects is unspecified.
    const std::uintptr_t source = reinterpret_cast<std::uintptr_t>(&gNiPoint3StartupSrc);
    const std::uintptr_t destination = reinterpret_cast<std::uintptr_t>(&gNiPoint3StartupDst);
    require(source + sizeof(NiPoint3StartupTable) <= destination ||
                destination + sizeof(NiPoint3StartupTable) <= source,
            "separate storage");

    // The owning unit's startup copy has filled the whole destination.
    for (unsigned int i = 0; i < count; ++i)
        require(gNiPoint3StartupDst.data[i] == gNiPoint3StartupSrc.data[i], "startup copy of each element");
    require(same_bytes(), "startup copy of every byte");

    // A change of any one destination element leaves the source as it was,
    // and the comparison above notices it.
    const NiPoint3StartupTable original = gNiPoint3StartupSrc;
    for (unsigned int i = 0; i < count; ++i)
    {
        gNiPoint3StartupDst.data[i] ^= 1;
        require(std::memcmp(&gNiPoint3StartupSrc, &original, sizeof(original)) == 0, "source unchanged");
        require(!same_bytes(), "changed element noticed");
        gNiPoint3StartupDst.data[i] ^= 1;
    }
    require(same_bytes(), "destination restored");

    // The readers obtain a usable format from both globals: four components
    // at the offsets of 32-bit RGBA, and a record equal to the approved one.
    require(rgba_offsets(gNiPoint3StartupSrc), "source component offsets");
    require(rgba_offsets(gNiPoint3StartupDst), "destination component offsets");
    NiPoint3StartupTable expected = approved;
    const NiPixelFormat& sourceFormat = NiPoint3StartupTableAs<NiPixelFormat>(gNiPoint3StartupSrc);
    const NiPixelFormat& expectedFormat = NiPoint3StartupTableAs<NiPixelFormat>(expected);
    require(sourceFormat == expectedFormat, "source equals the approved record");
    require(!(sourceFormat != expectedFormat), "source not unequal to the approved record");

    // The source holds the approved list in all 17 ints. operator== does not
    // compare the extra data, and treats a renderer hint of -1 as any hint.
    require(std::memcmp(&gNiPoint3StartupSrc, &approved, sizeof(approved)) == 0, "source holds the approved list");

    // Wrong-slot control: the list without the inserted zero fails the
    // offsets. It is not given to operator==, which would load its 264 as a
    // Representation, a value outside that enum.
    NiPoint3StartupTable shifted = before;
    require(!rgba_offsets(shifted), "shifted list rejected by the offsets");
    return 0;
}
