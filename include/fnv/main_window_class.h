#pragma once

#include "fileformat/pack_catalogue.h"

namespace fileformat
{
class ValidatedPack;
}

// The native owner of the main window class, the WNDC entry of the data
// pack: the class name that the second-window check of WinMain (0x0086a850)
// reads. Its storage is one fileformat::MainWindowClass, the declaration
// whose capacity fixes the size of the pack's entry
// (docs/data-pack-catalogue.md, D6).
//
// The value comes from the data pack only: the one writer takes a
// ValidatedPack, which holds decoded values and no raw bytes.
namespace fnv::startup
{
// Copies the pack's main window class into the owner. A later call replaces
// it. Call it on the main thread before any other thread exists.
void PublishMainWindowClass(const fileformat::ValidatedPack& pack) noexcept;

// The published main window class. Native policy, not recovered behaviour: a
// read before any publication terminates the process, so no consumer runs on
// a class name that did not come from a validated pack.
const fileformat::MainWindowClass& PublishedMainWindowClass() noexcept;
}
