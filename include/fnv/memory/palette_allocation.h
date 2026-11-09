#pragma once

namespace fnv::memory {
// Actual NiPalette array-retirement boundary. Uses the same native manager
// returned to production allocation clients; foreign allocations fail closed.
void ReleasePaletteAllocation(void*);
}
