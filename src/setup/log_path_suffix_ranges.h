#ifndef VEGAS_SETUP_LOG_PATH_SUFFIX_RANGES_H
#define VEGAS_SETUP_LOG_PATH_SUFFIX_RANGES_H

#include "fileformat/pack_catalogue.h"
#include "setup/single_instance_ranges.h"

#include <array>

namespace setup
{

// Where setup reads the log path suffixes in the original release: the four
// strings whose addresses WinMain (0x0086a850) passes to its log-path
// builders, statements S2 to S5, in that order. The recipe binds each address
// for src/fallout/misc/main.cpp under a one-byte UNK_ name; each capacity is
// the recipe bound, the distance to the next address any unit of the recipe
// binds. No literal of the recipe names a text at these addresses, so no
// content is known. The CTest setup.recipe_ranges
// (tools/setup-recipe-ranges) fails when a value no longer matches the recipe.
inline constexpr std::array<RecipeRange, 4> logPathSuffixRanges{{
    {"first log path suffix", "?UNK_01082a38@@3EA", 0x01082a38, 16, {}, {}},
    {"second log path suffix", "?UNK_01082a28@@3EA", 0x01082a28, 16, {}, {}},
    {"third log path suffix", "?UNK_01082a10@@3EA", 0x01082a10, 24, {}, {}},
    {"fourth log path suffix", "?UNK_01082a00@@3EA", 0x01082a00, 16, {}, {}},
}};

static_assert(logPathSuffixRanges[0].capacity == sizeof(fileformat::LogPathSuffixes::firstSuffix));
static_assert(logPathSuffixRanges[1].capacity == sizeof(fileformat::LogPathSuffixes::secondSuffix));
static_assert(logPathSuffixRanges[2].capacity == sizeof(fileformat::LogPathSuffixes::thirdSuffix));
static_assert(logPathSuffixRanges[3].capacity == sizeof(fileformat::LogPathSuffixes::fourthSuffix));

} // namespace setup

#endif
