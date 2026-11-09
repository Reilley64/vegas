# Native engine heap suppliers

The game target compiles these modules and the canonical `MemoryManager` heap
owner. The production heap-startup, allocation, size/reallocation and release
entries now use that owner. Both empty definitions are retired, rather than
selecting either one. A single source-owned, `constinit` native global supplies
the actual getter and production allocation/release receivers. This is a
**bounded heap/bootstrap connection**, not completion of VEGAS-79 or permission
to run the incompatible full startup sequence.

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
heaps. The global manager is constructed without allocating or initializing
heaps; its complete lifetime begins during constant initialization.

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
That assertion does not prove construction: the actual native global definition
and constant initialization supply the receiver lifetime, including calls from
other translation units before dynamic initialization.

`InitializeHeaps` initializes that same owned set, propagating initialization
failure as `bad_alloc`. `FUN_00aa3e40` consumes the actual typed
`g_tlsBlock.memoryContext` through `AllocateFromHeaps`. `Size`, `Reallocate` and
`FUN_00aa4060` find exact ownership before copying or releasing. The existing
unsigned `Reallocate` entry widens into native-size `ResizeOwned`, preserving
requiring objects without an ambiguous overloaded-size boundary. A bootstrap
allocation retains its CRT bootstrap domain after heap initialization. Unknown
or interior pointers never reach CRT size/reallocate/free. Release of an unknown
domain terminates; the nonterminating `ReleaseOwned` query reports rejection.
All three changed NiPalette releases call `ReleasePaletteAllocation`, whose
production definition obtains that same owner through the actual getter and
calls the canonical release entry. No local test owner supplies that connection.

Heap startup does **not** assert that pools exist. Pool allocation remains
unavailable even after the existing pool-construction calls: this owner must
first gain matching pool size/reallocation/release operations. There is no public
provider setter or fixture callback. Small requests with pooling enabled fail
closed instead of publishing an unsupported allocation domain.
Requests above pool selection exercise the complete native heap entry without a
pool supplier. A separate native thread-id/linked scrap association preserves the
actual scrap constructor and destructor, not a dummy map prefix. Its nonempty
lifecycle remains unmeasured. Heap-only shutdown requires no remaining scrap
objects; automatic owner destruction retires those objects before their backing
storage.

## Required whole-engine join

The complete global is available to heap/bootstrap allocation clients, but full
startup is explicitly unavailable. Pool allocations still lack admitted native
size/reallocation/release ownership; the physical/range and direct legacy
bootstrap domains are not in the new ownership index, and failure recovery is
not wired to native heap types. Returning heap failure is not proof of the old
recovery protocol. No arbitrary host/heap route replaces pools.

The original `00aa3880` constructor now checks admission in its first member
initializer, before the real table supplier can run. `00aa39c0` also rejects
before any receiver access, pool-table clear, heap initialization, byte-prefix
write or TESForm callback. Both throw `MemoryManagerStartupUnavailable` without
allocating manager storage (the C++ exception runtime still owns exception
storage). The original table, OS preflight and later constructor calls remain
source inputs, but are not executed on failure. The incompatible startup shell
is never cast to the native owner. Its final typed TLS clear remains after the
admission boundary and cannot run on failure. This is deliberate failure, not a
stubbed success or a replacement engine-startup protocol. Detached-client and
whole-engine shutdown remain separate work. Other legacy layout, callback,
physical/range and scrap protocols are not certified by the bounded entries.

No generated data or context-guard implementation changes are included. The
`runtime/new.cpp` legacy unsigned boundary now rejects overflow before casting,
and `runtime.manager_new` now executes the actual global new/getter/native
owner/matching delete connection, including failed-constructor delete and
unavailable-pool failure. This does not establish complete global-new coverage
or successful full startup.
The accepted guard is composed unchanged. Nested 9/23/36 scopes, early return
and exception restoration now execute through the same real heap allocation
entry; this does not establish the full engine startup chain. VEGAS-79 remains
incomplete.

## Manager checks

`tests/runtime/canonical_memory_manager_test.cpp` constructs the actual canonical
owner and executes the production `InitializeHeaps`, allocation entry, size,
reallocation and matching release, with the real production TLS owner. It covers
all 66 contexts, distinct non-pool 9/23 domains, default 36, high pointers, exact
ownership/rejection, bootstrap survival across initialization, failed/successful
resize (including actual main-reservation exhaustion), thread isolation,
explicit heap retirement/reinitialization and automatic
owner cleanup during unwinding. It also exercises accepted guard restoration
through actual allocation routing. It does not construct substitute heaps/managers,
install a provider, or claim successful full engine startup.

The suite also uses the actual production getter/global, allocation boundary
and NiPalette retirement boundary. It executes both original startup rejection
entries (including the exact `00aa3880` constructor) before and after heap init;
failed startup preserves existing allocation bytes, ownership, heap state and
TLS, never overwriting the native owner prefix. Real global allocations under
9/23/36 use the expected heaps and retire through the same NiPalette release.
Pool-sized requests remain unavailable; bounded detached retirement and
reinitialization use that same global.

`tests/runtime/manager_new_test.cpp` links the actual replaceable allocation
functions, not the isolated runtime.new forwarding fixture. A pre-main new
expression tests cross-TU constant-initialization safety. Main covers native
heap allocation, array delete, failed-constructor cleanup, pool unavailability
and native-size overflow. These are bounded production-entry tests. Complete
startup success, OS initialization failure, nonempty scrap, full engine shutdown
and actual Windows execution remain separate, unclaimed coverage.

## Supplier checks

`tests/runtime/engine_heap_set_test.cpp` executes the actual supplier modules,
with checks active under `NDEBUG`. It checks distinct heaps for 9 and 23, default
36 and all other mapping slots; matching release including the linear no-op;
high native addresses; exact allocation identity; real reservation exhaustion
and fallback; failed and successful reallocation; split/coalesce/trim; automatic
owner cleanup during exception unwinding; overlapping threads; and
shutdown/reinitialization. It is a supplier test, not a production manager,
AutoMemContext, global-new, gameplay or full-ticket acceptance test.
