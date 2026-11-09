# Pathing LOS map array lifecycle

VEGAS-77 replaces the empty `FUN_006e1020_shell` initialization and the
shell-member/derived-constructor mismatch with one native owner in
`los_map_array.cpp`. The production map loader allocates the actual
`FUN_006e0e80` derived record, whose base owns typed `FUN_006e0190*` elements.
The record extent, array pointer and element stride now follow the native target;
serialized counts, values and bytes remain 32-bit or narrower as stored in the
save format.

## Ownership and allocation

`FUN_006e1020_shell` is the source identity for the LOS record-pointer array. It
has a genuine C++ virtual allocation/free/reallocation protocol. The default
implementation uses the canonical game allocation and release entries, so the
same `MemoryManager` domain supplies and retires pointer storage, records and
nested byte arrays. There is no generated vptr, host container or provider
setter.

Growth allocates replacement storage before copying and retiring the old block.
Failure retains the old pointer, capacity, elements and bytes. Shrink and clear
destroy records in reverse index order. The derived record constructor starts
with an empty owner and null native `NavMeshInfo*`; normal deletion and exception
unwinding run the same virtual destructor chain.

The accepted 2,218-member archive sequence remains the prefix. CMake appends the
native LOS owner as one justified member; no accepted member is omitted or
reordered. The incompatible staging provider is retired, while the retained
`FUN_006e1020` entry has one definition in the native owner.

## Loading and publication

`BGSLoadGameBuffer::TryReadRaw` checks the complete payload and required `|`
separator before changing the cursor or destination. `TryReadElementCount`
preserves the source one-, two- and four-byte compressed-count encoding and
rejects the reserved tag or truncation.

`FUN_006e0480::TryLoadEntries` builds a temporary owner, constructs each real
record, loads its fixed fields and optional byte indices, and publishes by swap
only after the complete record array succeeds. Malformed input, allocation
failure or a throwing caller retires partially constructed records in reverse
order and leaves the previously published owner intact. The production
`FUN_006e0070` path supplies the resolved `NavMeshInfo*`; a scoped production
record guard holds the derived record until the existing map accepts it, so zero
IDs and exceptions do not leak it.

This boundary does not alter location loading, nav-mesh ID remapping, map lock
semantics or unrelated pathfinding arrays. It does not touch generated data,
FaceGen, scene arrays, queued I/O or string ownership.

## Checks

`runtime.los_map_array` calls the production owner and bounded reader with
synthetic save bytes. Checks stay active under `NDEBUG` and cover:

- zero, one and many loaded LOS entries;
- native pointer stride, high addresses and derived-record construction;
- grow, shrink, explicit delete, slot reuse and complete clear;
- canonical-manager reallocation failure preservation and retry after fixed-pool
  publication;
- malformed compressed counts, truncated partial construction and retry;
- normal and exception-unwind retirement.

The same target is run optimized and with AddressSanitizer,
UndefinedBehaviorSanitizer and vptr checks. These focused checks are not a full
save load, Windows execution, executable link, boot or gameplay acceptance.
