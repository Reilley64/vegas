#include "check.h"
#include "fileformat/pack_catalogue.h"

#include <array>
#include <cstddef>
#include <cstdint>

namespace
{

using fileformat::PackCatalogueEntry;
using fileformat::SingleInstanceStrings;

// The test spells catalogue version 1 itself, so a change to the source's
// catalogue fails here instead of agreeing with itself.
constexpr std::array<char, 4> singleInstanceKey{'I', 'N', 'S', 'T'};

constexpr bool SameEntry(const PackCatalogueEntry& entry, std::array<char, 4> key, std::uint32_t version,
                         std::size_t bytes)
{
    return entry.key == key && entry.version == version && entry.bytes == bytes;
}

static_assert(fileformat::packCatalogueVersion == 1);
static_assert(fileformat::packCatalogue.size() == 1);
static_assert(SameEntry(fileformat::packCatalogue[0], singleInstanceKey, 1, 140));
static_assert(SameEntry(fileformat::singleInstanceEntry, singleInstanceKey, 1, 140));

// C1's four fields at the capacities of D8.
static_assert(sizeof(SingleInstanceStrings::mutexName) == 20);
static_assert(sizeof(SingleInstanceStrings::firstMessageText) == 60);
static_assert(sizeof(SingleInstanceStrings::messageCaption) == 8);
static_assert(sizeof(SingleInstanceStrings::secondMessageText) == 52);

} // namespace

int main()
{
    Checks check("data pack catalogue");
    return check.ExitCode();
}
