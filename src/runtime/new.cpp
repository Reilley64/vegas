#include "fnv/symbols_00401000.h"

#include <cstddef>
#include <new>

// The replaceable global allocation functions. The original release's
// operator new and operator delete (0x00401000, 0x00401030) take memory from
// the game's MemoryManager, and so do new and delete expressions for game
// objects, the standard library and the array and sized forms here. Gamebryo's
// NiMemObject allocations reach the same MemoryManager through BSNiAllocator,
// so a block is always freed into the heap it came from.






