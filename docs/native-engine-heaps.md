# Native engine heap suppliers

The game target compiles these modules and the canonical `MemoryManager` heap
owner. The production heap-startup, allocation, size/reallocation and release
entries now use that owner. This is a **bounded prerequisite**, not a safe global
manager publication or completion of VEGAS-79. Neither empty global is retired.

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

## Canonical heap-owned manager seam

`include/fnv/decl/MemoryManager.h` now declares the real native owner, embedding
`EngineHeapSet` and an individually tracked bootstrap allocation list. The
competing padded manager/map declarations are gone. Allocation and release entry
types are real empty bases in a single inheritance chain, preserving the entry
names. A standard-layout assertion requires C++ base/owner pointer
interconvertibility on each build target; no historical offset is assumed.

`InitializeHeaps` initializes that same owned set, propagating initialization
failure as `bad_alloc`. `FUN_00aa3e40` consumes the actual typed
`g_tlsBlock.memoryContext` through `AllocateFromHeaps`. `Size`, `Reallocate` and
`FUN_00aa4060` find exact ownership before copying or releasing. A bootstrap
allocation retains its CRT bootstrap domain after heap initialization. Unknown
or interior pointers never reach CRT size/reallocate/free. Release of an unknown
domain terminates; the nonterminating `ReleaseOwned` query reports rejection.
The actual NiPalette consumers call the canonical release entry directly.

Heap startup does **not** assert that pools exist. The real pool-startup body
installs its own existing pool-selection operation after construction; there is
no public provider setter or fixture callback. Until that operation is installed,
small requests with pooling enabled fail closed instead of claiming pool startup.
Requests above pool selection exercise the complete native heap entry without a
pool supplier. A separate native thread-id/linked scrap association preserves the
actual scrap constructor and destructor, not a dummy map prefix. Its nonempty
lifecycle remains unmeasured. Heap-only shutdown requires no remaining scrap
objects; automatic owner destruction retires those objects before their backing
storage.

## Required whole-engine join

Global publication remains unsafe: pool allocations do not yet have admitted
native size/reallocation/release ownership, the physical/range and direct legacy
bootstrap domains are not in the new ownership index, and failure recovery is
not wired to native heap types. Returning heap failure is not proof of the old
recovery protocol. The existing `00aa3880` constructor and `00aa39c0` startup
shell still require the actual owner/callback join; their byte-prefix writes and
TESForm receiver must not be applied to this native owner. Detached-client and
whole-engine shutdown remain separate work. The two empty globals and the
existing getter are deliberately not selected as an initialized owner.

No generated data or context-guard implementation changes are included. The
`runtime/new.cpp` legacy unsigned boundary now rejects overflow before casting,
but the global-new/getter/full-startup chain is not executed by these tests.
The independent guard candidate has not been composed here, so nested guard
restoration through heap routing remains unmeasured. VEGAS-79 remains incomplete.

## Manager checks

`tests/runtime/canonical_memory_manager_test.cpp` constructs the actual canonical
owner and executes the production `InitializeHeaps`, allocation entry, size,
reallocation and matching release, with the real production TLS owner. It covers
all 66 contexts, distinct non-pool 9/23 domains, default 36, high pointers, exact
ownership/rejection, bootstrap survival across initialization, failed/successful
resize, thread isolation, explicit heap retirement/reinitialization and automatic
owner cleanup during unwinding. It does not construct substitute heaps/managers,
install a provider, or claim the full engine constructor ran.

## Supplier checks

`tests/runtime/engine_heap_set_test.cpp` executes the actual supplier modules,
with checks active under `NDEBUG`. It checks distinct heaps for 9 and 23, default
36 and all other mapping slots; matching release including the linear no-op;
high native addresses; exact allocation identity; real reservation exhaustion
and fallback; failed and successful reallocation; split/coalesce/trim; automatic
owner cleanup during exception unwinding; overlapping threads; and
shutdown/reinitialization. It is a supplier test, not a production manager,
AutoMemContext, global-new, gameplay or full-ticket acceptance test.
