#pragma once

#include "fileformat/pack_catalogue.h"

namespace fileformat
{
class ValidatedPack;
}

// The native owner of C1, the four strings that the single-instance and
// remote-session checks at the start of WinMain (0x0086a850) read: the mutex
// name, the two message texts and their caption. Its storage is one
// fileformat::SingleInstanceStrings, the declaration whose four capacities fix
// the size of the pack's entry (docs/data-pack-catalogue.md, D6 and D8).
//
// The values come from the data pack only: the one writer takes a
// ValidatedPack, which holds decoded values and no raw bytes.
namespace fnv::startup
{
// Copies the pack's C1 strings into the owner. A later call replaces them.
// Call it on the main thread before any other thread exists.
void PublishSingleInstanceStrings(const fileformat::ValidatedPack& pack) noexcept;

// The published strings. Native policy, not recovered behaviour: a read
// before any publication terminates the process, so no consumer runs on
// strings that did not come from a validated pack.
const fileformat::SingleInstanceStrings& PublishedSingleInstanceStrings() noexcept;
}
