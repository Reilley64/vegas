#pragma once

#include "fileformat/pack_catalogue.h"

namespace fileformat
{
class ValidatedPack;
}

// The native owner of the log path suffixes, the LOGS entry of the data
// pack: the four strings that WinMain's (0x0086a850) log-path builders, its
// statements S2 to S5, append to the user folder. Its storage is one
// fileformat::LogPathSuffixes, the declaration whose four capacities fix the
// size of the pack's entry (docs/data-pack-catalogue.md, D6).
//
// The values come from the data pack only: the one writer takes a
// ValidatedPack, which holds decoded values and no raw bytes.
namespace fnv::startup
{
// Copies the pack's log path suffixes into the owner. A later call replaces
// them. Call it on the main thread before any other thread exists.
void PublishLogPathSuffixes(const fileformat::ValidatedPack& pack) noexcept;

// The published log path suffixes. Native policy, not recovered behaviour: a
// read before any publication terminates the process, so no consumer runs on
// suffixes that did not come from a validated pack.
const fileformat::LogPathSuffixes& PublishedLogPathSuffixes() noexcept;
}
