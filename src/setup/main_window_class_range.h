#ifndef VEGAS_SETUP_MAIN_WINDOW_CLASS_RANGE_H
#define VEGAS_SETUP_MAIN_WINDOW_CLASS_RANGE_H

#include "fileformat/pack_catalogue.h"

#include <cstddef>
#include <cstdint>
#include <string_view>

namespace setup
{

// Where setup reads a string that the original release reaches through a
// stored pointer: the 32-bit pointer at `slotAddress`, which the recipe
// binds, and the string it points to. When the recipe binds the string's
// address too, the row names it, the pointer must hold it, and the capacity
// is the recipe bound there; otherwise the capacity is a documented limit.
// The addresses and names are facts of the recipe, build/units.json, written
// here as data: no byte of the original release is. The CTest
// setup.recipe_ranges (tools/setup-recipe-ranges) fails when they no longer
// match the recipe.
struct PointerRange
{
    std::string_view field;         // the field's name in messages
    std::string_view recipeName;    // the char pointer the recipe binds at `slotAddress` for the consumer's unit
    std::uint32_t slotAddress;      // where the pointer is stored in the original's memory, image base included
    std::size_t capacity;           // the field's capacity: the recipe bound at `targetAddress`, or a documented limit
    std::string_view targetName{};  // the name the recipe binds at the string's address, or empty when it binds none
    std::uint32_t targetAddress{0}; // that address, image base included, or 0 when the recipe binds none
};

// The main window class's one field. The capacity is 256 bytes, the length
// limit Windows documents for a window class name (ruling of 2026-11-13),
// and nothing else is known of the string: no recipe bound and no known text.
inline constexpr PointerRange mainWindowClassRange{"class name", "?_DAT_011a2fe8@@3PADA", 0x011a2fe8, 256};

static_assert(mainWindowClassRange.capacity == sizeof(fileformat::MainWindowClass::className));

} // namespace setup

#endif
