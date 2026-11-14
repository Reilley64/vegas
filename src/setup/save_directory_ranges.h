#ifndef VEGAS_SETUP_SAVE_DIRECTORY_RANGES_H
#define VEGAS_SETUP_SAVE_DIRECTORY_RANGES_H

#include "fileformat/pack_catalogue.h"
#include "setup/main_window_class_range.h"
#include "setup/single_instance_ranges.h"

#include <array>

namespace setup
{

// Where setup reads the save directory strings in the original release: the
// ten strings BGSSaveLoadManager::GetSaveDirectory (0x00876ad0) reads. Eight
// are read at addresses the recipe binds for
// src/fallout/misc/saveload/save_directory.cpp, each with the recipe
// bound as its capacity, the distance to the next address any unit of the
// recipe binds. Two are reached through pointers that unit binds: the first
// INI name's pointer must hold 0x01039c8c, which the recipe binds, and its
// capacity is the recipe bound there; the second INI name's target is not
// bound, and its capacity is 256 bytes, the main window class's (ruling of
// 2026-11-14). No literal of the recipe names a text at these addresses, so
// no content is known. Setup reads the fields in catalogue order, the order
// of fileformat::SaveDirectoryStrings: the format, the first INI name, the
// section, the setting key, the second INI name, the three folders, the
// working folder and the default INI name. The CTest setup.recipe_ranges (tools/setup-recipe-ranges) fails when
// a value no longer matches the recipe.
inline constexpr std::array<RecipeRange, 8> saveDirectoryRanges{{
    {"INI path format", "?DAT_01082dc4@@3QBDB", 0x01082dc4, 8, {}, {}},
    {"INI section", "?g_011d3eb0_arg1@@3QBDB", 0x0105d548, 8, {}, {}},
    {"setting key", "?DAT_01082dac@@3QBDB", 0x01082dac, 24, {}, {}},
    {"local folder", "?DAT_01082da0@@3QBDB", 0x01082da0, 12, {}, {}},
    {"documents folder", "?DAT_01082d94@@3QBDB", 0x01082d94, 12, {}, {}},
    {"game folder", "?DAT_01082d88@@3QBDB", 0x01082d88, 12, {}, {}},
    {"working folder", "?g_011dece4_arg1@@3QBDB", 0x01082d84, 4, {}, {}},
    {"default INI name", "?DAT_01082d70@@3QBDB", 0x01082d70, 20, {}, {}},
}};

inline constexpr std::array<PointerRange, 2> saveDirectoryPointerRanges{{
    {"first INI name", "?DAT_011a2ff4@@3PBDB", 0x011a2ff4, 12, "?str_01039c8c@fnv_005ba7c0@@3QBDB", 0x01039c8c},
    {"second INI name", "?_DAT_011a2ff0@@3PADA", 0x011a2ff0, 256, {}, 0},
}};

static_assert(saveDirectoryRanges[0].capacity == sizeof(fileformat::SaveDirectoryStrings::iniPathFormat));
static_assert(saveDirectoryPointerRanges[0].capacity == sizeof(fileformat::SaveDirectoryStrings::firstIniName));
static_assert(saveDirectoryRanges[1].capacity == sizeof(fileformat::SaveDirectoryStrings::iniSection));
static_assert(saveDirectoryRanges[2].capacity == sizeof(fileformat::SaveDirectoryStrings::settingKey));
static_assert(saveDirectoryPointerRanges[1].capacity == sizeof(fileformat::SaveDirectoryStrings::secondIniName));
static_assert(saveDirectoryRanges[3].capacity == sizeof(fileformat::SaveDirectoryStrings::localFolder));
static_assert(saveDirectoryRanges[4].capacity == sizeof(fileformat::SaveDirectoryStrings::documentsFolder));
static_assert(saveDirectoryRanges[5].capacity == sizeof(fileformat::SaveDirectoryStrings::gameFolder));
static_assert(saveDirectoryRanges[6].capacity == sizeof(fileformat::SaveDirectoryStrings::workingFolder));
static_assert(saveDirectoryRanges[7].capacity == sizeof(fileformat::SaveDirectoryStrings::defaultIniName));

} // namespace setup

#endif
