# Native engine heap suppliers

The game target compiles these modules and the canonical `MemoryManager` heap
owner. The production heap-startup, allocation, size/reallocation and release
entries now use that owner. Both empty definitions are retired, rather than
selecting either one. A single source-owned, constant-initialized native object
supplies the getter and production allocation/release receivers for the full
process lifetime. Clang's `no_destroy` attribute suppresses only that object's
static destructor registration; it does not alter local-owner cleanup. This is a
**bounded heap/bootstrap/fixed-pool connection**, not completion of VEGAS-79 or permission
to run the incompatible full startup sequence. `main` starts the heaps, the
pools and the Ni allocator through the composition in "Process startup" below.

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
heaps; its complete lifetime begins during constant initialization. Its static
destructor is deliberately not registered, so late allocation clients retain
live heaps, metadata and mutexes. Process storage reclamation ends the global
service lifetime; this is not proof of ordered whole-engine shutdown. Detached
local owners retain ordinary destruction.

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
Ni, scrap heaps, TLS users or other engine clients.

The same canonical owner embeds the 37 fixed-pool families registered by
`FUN_00866770`. Their block sizes, reservation capacities, names and source
order remain those of the source entry; the native producer executes the same
transactional `CreateMemoryPool` body for every family. Each pool reserves its source byte
capacity, commits pages on demand and keeps native free links plus allocation
bits in its own OS-backed metadata. Payloads are `max_align_t` aligned. Exact
payload starts, not reservation membership, establish size and ownership. Pool
lookup scans this owner's reservations with full-width addresses; the historical
256-slot `address >> 24` cache is not used.

Pool startup is transactional. The route remains unavailable until all 37
owners are constructed, and any failure retires every staged reservation so the
same owner can retry. Selection preserves the direct rounded-four-byte family,
then the source 16/32-byte fallback policy and 576-byte fallback. An exhausted
selected pool falls through to the context-selected heaps in the existing
order. Pool allocation, size, replacement and matching release all use the same
owner and serialize against pool retirement. Shutdown requires detached clients;
local owners retire pools before heaps, while the process-lifetime global remains
available to late static clients.

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
`FUN_00aa4060` find exact ownership before copying or releasing. Null and
heap-owned reallocation requests cross the same unavailable-pool gate as ordinary
allocation; failed replacement preserves the original allocation and bytes. The existing
unsigned `Reallocate` entry widens into native-size `ResizeOwned`, preserving
requiring objects without an ambiguous overloaded-size boundary. A bootstrap
allocation retains its CRT bootstrap domain after heap initialization. Unknown
or interior pointers never reach CRT size/reallocate/free. Release of an unknown
domain terminates; the nonterminating `ReleaseOwned` query reports rejection.
All three changed NiPalette releases call `ReleasePaletteAllocation`, whose
production definition obtains that same owner through the actual getter and
calls the canonical release entry. No local test owner supplies that connection.

Heap startup alone does **not** assert that pools exist. Small requests with
pooling enabled fail closed until the actual fixed-pool startup completes; there
is no public provider setter or fixture callback. Once published, pool and heap
blocks share the canonical size/reallocation/release boundary. Replacement is
allocated through the same pool-policy gate before the old block is retired, so
failure preserves its exact owner and bytes. Requests not selected by a fixed
family continue through the complete native heap entry. A separate native
thread-id/linked scrap association preserves the
actual scrap constructor and destructor, not a dummy map prefix. Its nonempty
lifecycle remains unmeasured. Heap-only shutdown requires no remaining scrap
objects; local-owner destruction retires those objects before their backing
storage. The process-lifetime global does not perform automatic retirement
before potentially still-attached static clients.

## Process startup

`fnv::memory::StartProcessMemory` in `src/bscore/memory_manager_startup.cpp` is
the production startup of the global manager. `main` calls it first and
returns 1 when it reports failure.

Where startup happens is decided by this evidence:

- No recorded unit calls the constructor `00aa3880`. `build/units.json` lists
  its definition and its exception handler and no other reference, so it is
  the dynamic initializer of the global at `0x011f6238`.
- The native global is constant-initialized. A constructor that runs later
  cannot construct it, and `FUN_00aa3880` is a 32-bit shell that must never be
  laid over the native owner.
- The legacy constructor also needs the table constructor and the page-file
  preflight. Both are defined in the staging unit `blk_00aa0000_od.cpp`, which
  the executable cannot link yet: it brings unresolved names with it.

So the two legacy entries keep rejecting, and the startup statements of
`00aa3880` are composed at `main` instead, in the recorded order:

| Recorded statement | Native startup |
| --- | --- |
| slot clear, member initializers | constant initialization of the global |
| page-file preflight | not composed: it is defined in that staging unit and needs user32, which the executable's link does not name |
| `00aa39c0`: pool-table clear `00aa6840` | not composed: the native owner has no such tables, and the recorded loop writes 256 entries into a generated array of 144 |
| `00aa39c0`: heap startup `00866e00` | `InitializeHeaps` |
| `00aa39c0`: first-byte write | the owner's own initialized state |
| `00aa39c0`: pool startup `00866770` | `FUN_00866770` |
| `00aa39c0`: `00483710` | nothing: the recorded body is empty |
| `00aa39c0`: allocation context 0 | `g_tlsBlock.memoryContext = 0` |
| `00866690`: allocator, options, holder | `PublishManagerNiAllocator` |
| `00866690`: system-utility call | not composed: the name is undefined |
| `00aa58d0`: scrap heap object | not composed: 32-bit layout code |

Native policy, not recovered behaviour:

- **`main` calls startup explicitly.** The original relies on dynamic
  initializer order. Allocations made before `main` use the bootstrap domain
  and stay valid afterwards, as already admitted.
- **A refused stage is reported.** The function returns false. Stages that did
  start stay started, so blocks taken from them stay valid, and a later call
  resumes at the refused stage. A refused publication leaves nothing allocated.
- **A second call does nothing.**

Startup leaves the calling thread in allocation context 0, as recorded. That
context selects the linear heap, so a request on that thread with no pool
family is not reclaimed one block at a time.

`fnv::memory::RetireProcessMemory` retires the publication, then the pools,
then the heaps and the remaining bootstrap blocks. It requires detached
clients. Source records no retirement of the manager: the recorded exit path
runs `00aa2170` and returns. So `main` does not call it, and the manager
serves static destructors until the process ends.

`runtime.process_startup` runs `StartProcessMemory` itself, in optimized and
ASan/UBSan (with vptr) builds. It covers a heap reservation that the operating
system refuses, the retry, a second startup, the Ni entries and global `new`
and `delete` in pools and in the heaps of contexts 0, 9, 23 and 36, a
bootstrap block that outlives startup, retirement, and startup after
retirement. A refused pool or publication stage is not exercised.

## Required whole-engine join

The complete global is available to heap/bootstrap/fixed-pool allocation clients,
and to Ni clients after process startup, but the legacy startup entries stay
explicitly unavailable. The physical/range and direct
legacy bootstrap domains are not in the new ownership index, and failure
recovery is not wired to native heap types. Returning heap failure is not proof
of the old recovery protocol. No arbitrary host/heap route replaces another
allocation domain.

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
unavailable-pool failure before fixed startup. This does not establish complete global-new coverage
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
resize (including unavailable-pool shrink before pool startup, successful pool
cross-class replacement after startup, native-width failure and actual
main-reservation exhaustion), payload preservation, thread isolation,
explicit heap retirement/reinitialization and automatic
owner cleanup during unwinding. It also exercises accepted guard restoration
through actual allocation routing. It does not construct substitute heaps/managers,
install a provider, or claim successful full engine startup.

The common three-pointer list-node owner is another bounded client of this same
manager. Its refill blocks follow the caller's typed TLS context, recycle under
one native owner lock, and retire through the original allocation domain before
heap shutdown. See `docs/native-list-node-lifecycle.md`. It adds no host pool or
successful full-startup claim.

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
and native-size overflow. The two `runtime.manager_static_*` tests retain real
pre-main bootstrap and heap allocations through another TU's static destructor,
read and delete them there, and allocate/delete again after main. Their actual
production provider/client object groups are linked in both orders. Checks stay
active under `NDEBUG`; no test allocator or replacement lifecycle is supplied.
The canonical suite verifies all 37 source families, exact capacities/names,
zero/one/many allocations, exhaustion/fallback/reuse, high pointers, alignment,
foreign/interior rejection, 0x60 and filename-sized requests, rollback/retry,
cross-class replacement, matching release, threads and local-owner retirement.
These are bounded production-entry tests. Complete manager startup success,
physical/range domains, recovery, nonempty scrap, full engine shutdown and actual
Windows execution remain separate, unclaimed coverage.

## Supplier checks

`tests/runtime/engine_heap_set_test.cpp` executes the actual supplier modules,
with checks active under `NDEBUG`. It checks distinct heaps for 9 and 23, default
36 and all other mapping slots; matching release including the linear no-op;
high native addresses; exact allocation identity; real reservation exhaustion
and fallback; failed and successful reallocation; split/coalesce/trim; automatic
owner cleanup during exception unwinding; overlapping threads; and
shutdown/reinitialization. It is a supplier test, not a production manager,
AutoMemContext, global-new, gameplay or full-ticket acceptance test.
