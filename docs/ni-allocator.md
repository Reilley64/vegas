# Ni allocator join

Gamebryo allocation entries do not call the memory manager. They read the
holder at `DAT_011f6080` and dispatch through the allocator it names. This
document covers the native owner of that route. It is a bounded join under
VEGAS-86 and VEGAS-79, not the whole Ni memory layer.

## Types

`include/fnv/ni_allocator.h` is the one shared declaration.

| Type | Role |
| --- | --- |
| `NiAllocator` | Abstract interface with a compiler-owned virtual table |
| `BSNiAllocator` | Forwards every request to the canonical `g_memoryManager` |
| `NiStandardAllocator` | The recorded bodies of `nistandardallocator.cpp`, bound as overrides |
| `NiInitOptions` | The object `DAT_011f6118` points to: an allocator and whether the options own it |
| `HolderB3718` | The object `DAT_011f6080` points to: one allocator pointer |

`ni_allocator_holder.cpp` defines both globals. The generated definitions and
the generated base table `0x010a24d0` are retired through the audited
composition in `docs/native-data-ownership.md`.

## Slots

The three original tables are ten slots each: `0x010a24d0`, `0x010a24fc` and
`0x010a2528` are 44 bytes apart, which is ten entries and a type-information
pointer. A comment in the former stand-in said fourteen; it was wrong.

Body order in both units matches slot order, and the call sites agree on the
events each slot receives.

| Slot | Virtual | Call-site evidence | `BSNiAllocator` | `NiStandardAllocator` |
| --- | --- | --- | --- | --- |
| 0 | destructor | `0x00aa21e0` deletes through it | base `0x00aa24a0` | base `0x00aa24a0` |
| 1 | `Allocate` | events 1, 2, 5, 7 from `0x00aa13e0`, `0x00aa1420`, `0x00aa1070`, `0x00aa10b0` | `0x00aa2240`, aligned for 7 | `0x00aa30c0` |
| 2 | `Deallocate` | events 3, 4, 9, 10 from `0x00aa1460`, `0x00aa1490`, `0x00aa10f0`, `0x00aa1110` | `0x00aa22b0`, aligned for 10 | `0x00aa3150` |
| 3 | `Reallocate` | no holder call site; `0x00aa31b0` is typed | `0x00aa22f0`, aligned for 8 | `0x00aa31b0` |
| 4 | `Alloc` | events `0xb`, `0xd` from `0x00aa11b0`, `0x00aa1130`, `0x00aa1250` | `0x00aa2370`, aligned for `0xd` | `0x00aa3300` |
| 5 | `Free` | events `0xf`, `0x10` from `0x00aa1170`, `0x00aa1190`, `0x00aa1250` | `0x00aa23e0`, aligned for `0x10` | `0x00aa3370` |
| 6 | `Realloc` | events `0xc`, `0xe` from `0x00aa11b0`, `0x00aa1250` | `0x00aa2420`, aligned for 14 | `0x00aa33a0` |
| 7 | `Initialize` | `0x00aa2020` calls it with no arguments | no body identified | `0x00aa3430` |
| 8 | `Shutdown` | none | no body identified | `0x00aa3460`, by body order and its pairing with slot 7 |
| 9 | not declared | none | no body identified | no body identified |

The names of slots 1 to 6 are the ones the existing call-site views used.
`Initialize` and `Shutdown` are native names.

Slot 9 has no body or caller in either class, so it has no signature and is
not declared. Native dispatch is by name, so this changes no call. Declare it
when a body or a caller is identified.

## Native policy

These are decisions of this source, not recovered behaviour. Each applies
only to the bodies it names.

- **`BSNiAllocator` slots 7 and 8 do nothing.** No body is identified. The
  recorded bodies from `0x00aa2240` to `0x00aa24c1` are contiguous apart from
  alignment padding, so none lies among them. An empty body shared with
  another function elsewhere would leave no trace there, and the table
  `0x010a2528` is not in the generated data. So the slot targets are not
  established. The object has no state.
- **A refused request returns null.** This covers `BSNiAllocator`'s six
  allocating bodies: `Allocate`, `Alloc`, and both event forms of `Reallocate`
  and `Realloc`. The recorded bodies write the zero fill, the alignment byte or
  the copied payload through the manager's result without a check. A
  successful request behaves as recorded, including the zero fill. A refused
  reallocation keeps the old block and its bytes.
- **Size plus alignment must fit the manager's unsigned entry.** This covers
  the aligned events of the same six bodies. The recorded sum wraps. A request
  that would wrap returns null.
- **Reallocation never reaches the CRT.** The recorded `0x00aa4200`, behind the
  non-aligned events of `Reallocate` and `Realloc`, passes a block the manager
  does not own to the CRT's `realloc`. Here such a block, null included,
  returns null and is left alone. Source shows no foreign block arriving: the
  two bodies are reached only from `0x00aa11b0` and `0x00aa1250`, which handle
  a null block and a zero size themselves and pass blocks this allocator
  returned.
- **`0x00aa13e0` never narrows.** A size above the unsigned boundary returns
  null instead of allocating a truncated block.
- **An unpublished holder fails closed.** `0x00aa13e0` returns null.
  `0x00aa1460` with a block and no holder terminates, as release of an unknown
  domain does in the manager.
- **`0x00aa2020` publishes nothing without options or holder storage.** The
  holder stays as it was. The function is `extern "C"`, does not throw and
  reports neither case; a caller that must know compares `DAT_011f6080` before
  and after. The publication step does, and throws.
- **`0x00aa20b0` requires published options.** With none it terminates, in
  `fnv::memory::RequirePublishedNiOptions`, before either branch that would
  build or accept other options. So the `NiStandardAllocator` fallback is
  never entered: after process startup the published options are kept, and
  without it the entry fails closed.
- **The publication step is all or nothing.** A refused allocator, options or
  holder undoes the earlier steps and restores the previous options.

`NiStandardAllocator` keeps its recorded bodies unchanged, including their
unchecked writes. None of the policy above applies to it.

## Deleting an allocator

`0x00aa21e0` deletes an owned allocator through slot 0. The compiler-owned
deleting destructor ends in the sized global `operator delete`, which
`src/runtime/new.cpp` forwards to the manager's release entry. An allocator
that options own must therefore come from global `new`, as `0x00aa2200`
allocates it. The publication step allocates the Bethesda allocator and its
options the same way and retires them with `delete`.

## Publication and retirement

The recorded startup order is heap startup, fixed-pool startup, then
`0x00866690`, which constructs the Bethesda allocator and non-owning options
and calls the holder's writer. `fnv::memory::PublishManagerNiAllocator` holds
those statements. Production reaches it from `main` through
`fnv::memory::StartProcessMemory`, described in `docs/native-engine-heaps.md`,
not through the rejected `0x00aa3880` constructor. `0x00866690` also calls it
and then makes its one remaining call, which is a system-utility connection
that is not joined.

`0x00aa20b0` keeps options that are already published and builds
`NiStandardAllocator` options only when there are none. It then reaches the
writer again through `0x00aa3050`. So startup publishes the holder twice. Each
publication allocates a new holder and the previous one is never freed, as
recorded.

The recorded shutdown `0x00aa2170` destroys and frees the options only when
`0x00aa20b0` built them. Options that name the Bethesda allocator do not own
it, and nothing in source retires that allocator or any holder. They live as
long as the process-lifetime manager, so late frees still have a route.

`fnv::memory::RetireManagerNiAllocator` is native, for detached-client
retirement of the manager only. It unpublishes the holder and the options and
returns the holder, the options and the allocator to the manager, in that
order. Holders and options left behind by a repeated publication are not
tracked, as recorded, and go with the manager's heaps.

## Tests and limits

`runtime.ni_allocator_join` runs the manager's heap and pool startup, the
publication step, `0x00aa2020`, `0x00aa13e0` and `0x00aa1460` on host, in
optimized and ASan/UBSan (with vptr) builds. Every allocator, options and
holder object is constructed by those entries. It covers the zero fill on
reused blocks, alignment, the owning heap for contexts 9, 23 and 36, pooled
sizes, refused and oversized requests, the unpublished route, repeated
publication, and retirement of non-owning options.
`runtime.ni_allocator_join.unpublished_free` checks the termination case.

The same test covers aligned `Realloc` (event 14), both non-aligned
reallocation paths across pool and heap, a refused replacement, and blocks the
manager does not own. `runtime.process_startup` runs the production startup
and the fence in front of `0x00aa20b0`.

Two values are checked only as far as behaviour shows them:

- `0x00aa1460` frees with a plain event. `BSNiAllocator` treats events 3, 4
  and 9 alike, so the literal 3 is not separable. `runtime.ni_allocator_join.
  aligned_block_free` shows the event is not the aligned one.
- `0x00aa13e0` serves a zero size from the one-byte family with a zeroed first
  byte. The manager also rounds zero up to its smallest family, and a released
  pool block starts with the pool's free links, so a size passed through as
  zero is not separable.

Not covered, because their callees are not native:

- `0x00aa20b0` and `0x00aa2170` call the serialized-IO startup and shutdown
  (`0x00aa7eb0`, `0x00aa81d0`) and the system descriptor. They are typed and
  compiled for windows-x64 but not executed.
- `0x00866690` is compiled but not executed, for its unjoined last call.
- `NiStandardAllocator` depends on the small-object pools, which are still
  32-bit layout code. Owning options are therefore never constructed in a test.
- `0x00aa4200` still receives the manager through a reinterpreted helper
  pointer that it casts back. Its behaviour is covered; its receiver type is
  not converted.

The other holder readers still use their own views of the holder and
allocator: `0x00aa1420`, `0x00aa1490`, the entries in `nimemorydefines.cpp`,
`0x00aa1110`, and three staging and animation copies. They are unchanged.
