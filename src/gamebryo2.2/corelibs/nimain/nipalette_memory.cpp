#include "fnv/memory/palette_allocation.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/symbols_00401000.h"

void fnv::memory::ReleasePaletteAllocation(void* memory)
{
    FUN_00401020()->FUN_00aa4060(memory);
}
