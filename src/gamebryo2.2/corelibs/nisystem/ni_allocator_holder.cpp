// The Ni allocator holder: its storage, its one writer, the options object
// that names the allocator, and the two entries that allocate and free
// through it. Original identities are provenance, not offsets.

#include "fnv/ni_allocator.h"
#include "fnv/decl/MemoryManager.h"

#include <cstddef>
#include <cstdlib>
#include <limits>
#include <new>

// 0x011f6080
HolderB3718* DAT_011f6080;
// 0x011f6118
void* DAT_011f6118;

// @fnv 0x00aa21d0
NiInitOptions::NiInitOptions(NiAllocator* allocator)
{
    this->allocator = allocator;
    ownsAllocator = false;
}

// @fnv 0x00aa21e0
NiInitOptions::~NiInitOptions()
{
    if (ownsAllocator)
        delete allocator;
}

// Allocates a holder from g_memoryManager, stores the options' allocator in it, publishes it and initializes the allocator.
// The recorded body writes through a null holder or null options. Native
// policy, not recovered behaviour: without options, or when the manager
// refuses the holder's storage, nothing is published and DAT_011f6080 keeps
// its previous value. This entry is extern "C" and reports neither case, so a
// caller that must know compares DAT_011f6080 before and after.
// A repeated call publishes a new holder and never frees the previous one, as
// recorded: 0x00866690 and 0x00aa3050 both call this during startup.
// @fnv 0x00aa2020
extern "C" void InitHolder()
{
    NiInitOptions* options = static_cast<NiInitOptions*>(DAT_011f6118);
    if (!options)
        return;
    void* storage = g_memoryManager.FUN_00aa3e40(sizeof(HolderB3718));
    if (!storage)
        return;
    DAT_011f6080 = new (storage) HolderB3718{options->allocator};
    DAT_011f6080->allocator->Initialize();
}

// The recorded statements are the two constructions, the options store and
// the writer call. Native policy, not recovered behaviour: a refused stage
// undoes the earlier ones and restores the previous options before throwing.
void fnv::memory::PublishManagerNiAllocator()
{
    BSNiAllocator* allocator = new BSNiAllocator;
    NiInitOptions* options;
    try
    {
        options = new NiInitOptions(allocator);
    }
    catch (...)
    {
        delete allocator;
        throw;
    }
    void* previousOptions = DAT_011f6118;
    HolderB3718* previousHolder = DAT_011f6080;
    DAT_011f6118 = options;
    InitHolder();
    // A published holder is always new storage: the previous one is not freed.
    if (DAT_011f6080 == previousHolder)
    {
        DAT_011f6118 = previousOptions;
        delete options;
        delete allocator;
        throw std::bad_alloc();
    }
}

void fnv::memory::RetireManagerNiAllocator() noexcept
{
    HolderB3718* holder = DAT_011f6080;
    NiInitOptions* options = static_cast<NiInitOptions*>(DAT_011f6118);
    DAT_011f6080 = nullptr;
    DAT_011f6118 = nullptr;
    g_memoryManager.FUN_00aa4060(holder);
    if (options)
    {
        NiAllocator* allocator = options->ownsAllocator ? nullptr : options->allocator;
        delete options;
        delete allocator;
    }
}

NiInitOptions* fnv::memory::RequirePublishedNiOptions() noexcept
{
    NiInitOptions* options = static_cast<NiInitOptions*>(DAT_011f6118);
    if (!options)
        std::abort();
    return options;
}

// Defaults the size to 1 if zero, then allocates through the holder's allocator (size, alignment 4, operator new) and returns the block.
// The recorded body narrows the size and reads through the holder unchecked.
// Native policy, not recovered behaviour: a size above the allocator's
// unsigned boundary, or a holder that is not published, is a failed
// allocation and returns null.
// @fnv 0x00aa13e0
void* FUN_00aa13e0(size_t value)
{
    if (!value)
        value = 1;
    if (value > std::numeric_limits<unsigned int>::max())
        return nullptr;
    HolderB3718* holder = DAT_011f6080;
    if (!holder)
        return nullptr;
    unsigned int size = static_cast<unsigned int>(value);
    unsigned int alignment = 4;
    return holder->allocator->Allocate(size, alignment, 1, true, 0, -1, 0);
}

// A block can only have come from a published holder. Native policy, not
// recovered behaviour: freeing one with no holder terminates, as release of an
// unknown domain does in the manager.
// @fnv 0x00aa1460
void FUN_00aa1460(void* memory, unsigned int size)
{
    if (memory)
    {
        HolderB3718* holder = DAT_011f6080;
        if (!holder)
            std::abort();
        holder->allocator->Deallocate(memory, 3, size);
    }
}
