# Pathing LOS map array lifecycle

VEGAS-77 replaces the empty `FUN_006e1020_shell` initialization and the
shell-member/derived-constructor mismatch with one native owner in
`los_map_array.cpp`. The production map loader allocates the actual
`FUN_006e0e80` derived record, whose base owns typed `FUN_006e0190*` elements.
The record extent, array pointer and element stride follow the native target;
serialized counts, values and bytes remain 32-bit or narrower as stored in the
save format.

## Ownership and allocation

`FUN_006e1020_shell` is the source identity for the LOS record-pointer array,
and keeps the struct identity its retained `FUN_006e1020` entry is linked by.
`LOSByteArray` is the byte array embedded in each `FUN_006e0190` record. Each
has the four virtual entries of its source table, in the source order: destroy,
allocate, free and reallocate. An array is therefore a table pointer, a native
pointer and two 32-bit counts, and a record is its flag, that array, a native
`NavMeshInfo*` and a 32-bit value.

The default entries use the canonical game allocation, release and
reallocation entries, so one `MemoryManager` domain supplies and retires
pointer storage, records and index bytes. There is no generated vptr, host
container or provider setter.

Growth follows the source: an empty array allocates, a full block goes through
the reallocation entry, and a partly used block is copied to a new allocation
before the old one is freed. Each path obtains the replacement first, so a
failure retains the old pointer, capacity, elements and bytes. Shrink and clear
destroy records in reverse index order.

`FUN_006e0d20` allocates each `FUN_006e0e80` with the global `new` and the map
deletes it through its `FUN_006e0480` base pointer; both reach the same
`MemoryManager`. The record's constructor starts with an empty owner and a null
`NavMeshInfo*`. Normal deletion and exception unwinding run the same virtual
destructor chain.

llvm-lib stores archive members in reverse input order, so CMake lists the
native LOS owner first. It is stored after the accepted 2,218 members, which
keep their order. The incompatible staging provider is retired, and the
retained `FUN_006e1020` entry has one definition in the native owner.

## Loading and publication

`LOSSaveReader` is a bounded view of the save-load buffer. It borrows the
buffer's bytes and advances the buffer's own cursor, so its reads interleave
with the form-ID reads that other owners perform on the same buffer.
`TryReadRaw` checks the complete payload and the required `|` separator before
it changes the cursor or the destination. `TryReadElementCount` keeps the
source one-, two- and four-byte count encoding and rejects the reserved tag.
The boundary does not define the save-load buffer's construction, destruction
or buffer release; those stay with the save-load owner.

`FUN_006e0480::TryLoadEntries` builds a temporary owner, constructs each real
record, loads its fixed fields and optional byte indices, and publishes by swap
only after the complete record array succeeds. A count that the remaining bytes
cannot hold is refused before storage is requested.

`FUN_006e0d20` holds every record of one map load in a `LOSMapLoad` until all
records and the three trailing values have loaded and the location has loaded.
Only then does it store the values and hand each record to the map, in load
order. A record with a zero nav mesh ID is deleted as soon as it has loaded.
Malformed or truncated data and allocation failure throw; the unwind deletes
every record the map has not accepted and leaves the map and the three values
as they were. Only a failure inside the map while it accepts records can leave
it holding part of a load.

The source reader reports a wrong separator and continues, reads a reserved
count tag as zero and does not check the buffer's extent. Rejecting those
inputs is a deliberate difference of the native boundary.

This boundary does not alter location loading, nav-mesh ID remapping, map lock
semantics or unrelated pathfinding arrays. The save, query and update paths of
these records still read them through their historical views. It does not touch
generated data, FaceGen, scene arrays, queued I/O or string ownership.

## Checks

`runtime.los_map_array` runs the production owner, map-load owner and bounded
reader with synthetic save bytes, under the production global `new` and
`delete`. Checks stay active under `NDEBUG` and cover:

- zero, one and many loaded LOS entries, with counts of each encoded width;
- allocation extents, high addresses and derived-record construction;
- grow through each path, shrink, explicit delete, slot reuse and complete clear;
- canonical-manager allocation failure, preservation, and retry after
  fixed-pool publication, for the pointer array, index bytes, record and slots;
- every truncation point and every missing separator of a multi-record
  payload, malformed and oversized counts, and retry;
- map-load publication, zero-ID deletion, deletion through the base pointer,
  rollback of held records on failure and partial publication;
- normal and exception-unwind retirement.

The same target is run optimized and with AddressSanitizer,
UndefinedBehaviorSanitizer and vptr checks. `FUN_006e0d20` and `FUN_006e0070`
themselves are not executed: their form-ID translation, nav mesh lookup, map
and location belong to owners that have no native provider yet. These focused
checks are not a full save load, Windows execution, executable link, boot or
gameplay acceptance.
