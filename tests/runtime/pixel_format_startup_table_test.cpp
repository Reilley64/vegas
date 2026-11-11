#include "fnv/ni_point3_startup_table.h"

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
    return 0;
}
