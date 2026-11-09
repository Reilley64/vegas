# Native engine heap suppliers

These modules are **not yet registered in the game target**. They implement the
heap-owned portion of VEGAS-79, not the complete MemoryManager connection. The
shared declaration and startup join must be serialized before publication.
Passing the supplier test does not establish engine startup or TLS routing.

## Ownership

`fnv::memory::EngineHeapSet` owns three actual heaps. Its initialization uses the
capacities and context assignments in `appmemory_console.cpp`'s `00866e00`:

| Heap | Reserve | Initial commit | Contexts |
| --- | --- | --- | --- |
| Main arena | `0xc800000` | `0x5500000` | 65 and the default |
| Auxiliary linear heap | `0x183800` | whole allocation | 0, 3, 9 |
| Context arena | `0x4000000` | `0x200000` | 23 |

All 66 mappings start empty; context 36 uses Main. Failed initialization releases
acquired reservations before reporting failure. No external pointer table, raw
receiver prefix, captured vptr, CRT allocator or test supplier supplies these
heaps. There is no global manager definition in this increment.

The arena and linear heap reuse the separately authored native heap work, with
narrow changes to remove its pool/diagnostic dependencies. The algorithms retain
the source reserve/commit, size-class reuse, splitting, coalescing, tail trimming
and collective linear-release contracts. Native pointer-sized headers and
`max_align_t` payload alignment replace the PC representation. Synchronization
uses standard C++ mutexes; no game allocator is needed to initialize the heaps.
OS reservation extents round to page size. The linear heap's allocation capacity
remains the requested source capacity, not the larger rounded reservation.

`Contains` reports reservation membership, not allocation ownership. `Size` and
`OwnerOf` accept only exact payload starts found in initialized, live metadata;
they do not dereference headers derived from arbitrary or uncommitted pointers.
Address comparisons retain `uintptr_t` width. Unknown deallocations fail closed.
Linear individual deallocation deliberately does not reclaim storage, just as
`ZeroOverheadHeap::Deallocate` does not. Shutdown releases it collectively.

Allocation rejects sizes outside the source 28-bit arena boundary before
alignment. A full selected heap falls back to the actual Main arena. Exhausting
Main returns failure; this module does not invent gameplay recovery callbacks.
Reallocation obtains the replacement first, checks failure before copying and
leaves the original owned on failure. Its destination follows the supplied
context; retirement always follows the original allocation's owner.

Initialize, shutdown and reset require detached external clients. The set's
operations serialize initialization and use. This is not a shutdown protocol for
Ni, pools, scrap heaps, TLS users or other engine clients.

## Required production join

The coordinator must serialize changes to `include/fnv/decl/MemoryManager.h` and
the partial declaration in `src/bscore/memorymanager_memory.h` before the manager
can embed this owner. The actual startup, allocation, free, size and reallocation
providers must then use that same complete type, without stand-in receiver casts.
The duplicate empty globals cannot be retired until that complete initialized
owner and its requiring clients are joined.

The allocation provider must read the real allocation TLS field after its pool
choice and pass that context into the heap set. This module neither reads nor
changes the independently owned AutoMemContext protocol. It must not be tested
as a replacement for that production consumption path.

No CMake source registration, existing provider retirement, generated data
change, manager-init or context hunk is included. The full ordered archive,
ordinary and unlimited executable links, global-new boundary, actual startup
callbacks, pool/physical-range users, bootstrap ownership and scrap/client
shutdown remain unverified by this increment. VEGAS-79 remains incomplete.

## Supplier checks

`tests/runtime/engine_heap_set_test.cpp` executes the actual supplier modules,
with checks active under `NDEBUG`. It checks distinct heaps for 9 and 23, default
36 and all other mapping slots; matching release including the linear no-op;
high native addresses; exact allocation identity; real reservation exhaustion
and fallback; failed and successful reallocation; split/coalesce/trim; automatic
owner cleanup during exception unwinding; overlapping threads; and
shutdown/reinitialization. It is a supplier test, not a production manager,
AutoMemContext, global-new, gameplay or full-ticket acceptance test.
