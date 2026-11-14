#ifndef VEGAS_SETUP_SINGLE_INSTANCE_RANGES_H
#define VEGAS_SETUP_SINGLE_INSTANCE_RANGES_H

#include "fileformat/pack_catalogue.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <string_view>

namespace setup
{

// Where setup reads one string field in the original release: a field of C1
// here, or a log path suffix (log_path_suffix_ranges.h). Every value is a
// fact of the recipe, build/units.json, written here as data: no byte of the
// original release is. The CTest setup.recipe_ranges
// (tools/setup-recipe-ranges) fails when a value no longer matches the
// recipe.
struct RecipeRange
{
    std::string_view field;       // the field's name in messages
    std::string_view recipeName;  // the str_ or UNK_ name the recipe binds at `address` for src/fallout/misc/main.cpp
    std::uint32_t address;        // where the string starts in the original's memory, image base included
    std::size_t capacity;         // the recipe bound: the distance to the next address the recipe binds
    std::string_view literalName; // a recipe string literal at `address` whose name spells its whole text, or empty
    std::string_view literalText; // that text, without its zero byte
};

// C1's fields in catalogue order. The recipe binds the caption's address also
// as the literal ??_C@_05NAOIJFC@Error?$AA@, a 6-byte "Error" and its zero
// byte, so the caption must be exactly that. No content is known for the
// other three.
inline constexpr std::array<RecipeRange, 4> singleInstanceRanges{{
    {"mutex name", "?str_01082ab8@@3PADA", 0x01082ab8, 20, {}, {}},
    {"first message text", "?str_01082a7c@@3PADA", 0x01082a7c, 60, {}, {}},
    {"message caption", "?str_0104df38@@3PADA", 0x0104df38, 8, "??_C@_05NAOIJFC@Error?$AA@", "Error"},
    {"second message text", "?str_01082a48@@3PADA", 0x01082a48, 52, {}, {}},
}};

static_assert(singleInstanceRanges[0].capacity == sizeof(fileformat::SingleInstanceStrings::mutexName));
static_assert(singleInstanceRanges[1].capacity == sizeof(fileformat::SingleInstanceStrings::firstMessageText));
static_assert(singleInstanceRanges[2].capacity == sizeof(fileformat::SingleInstanceStrings::messageCaption));
static_assert(singleInstanceRanges[3].capacity == sizeof(fileformat::SingleInstanceStrings::secondMessageText));
static_assert(singleInstanceRanges[2].literalText.size() < singleInstanceRanges[2].capacity);

} // namespace setup

#endif
