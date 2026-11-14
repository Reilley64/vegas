#pragma once

#include "fileformat/pack_catalogue.h"

namespace fileformat
{
class ValidatedPack;
}

// The native owner of the save directory strings, the SDIR entry of the data
// pack: the ten strings that BGSSaveLoadManager::GetSaveDirectory
// (0x00876ad0), WinMain's statement S7, reads. Its storage is one
// fileformat::SaveDirectoryStrings, the declaration whose ten capacities fix
// the size of the pack's entry (docs/data-pack-catalogue.md, D6).
//
// The values come from the data pack only: the one writer takes a
// ValidatedPack, which holds decoded values and no raw bytes, so the format of
// the INI paths holds exactly one %s and no other conversion.
namespace fnv::startup
{
// Copies the pack's save directory strings into the owner. A later call
// replaces them. Call it on the main thread before any other thread exists.
void PublishSaveDirectoryStrings(const fileformat::ValidatedPack& pack) noexcept;

// The published save directory strings. Native policy, not recovered
// behaviour: a read before any publication terminates the process, so no
// consumer runs on strings that did not come from a validated pack.
const fileformat::SaveDirectoryStrings& PublishedSaveDirectoryStrings() noexcept;
}
