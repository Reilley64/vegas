# Pathing LOS map array lifecycle

VEGAS-77 replaces the empty `FUN_006e1020_shell` initialization and the
shell-member/derived-constructor mismatch with one native owner in
`los_map_array.cpp`. The production map loader allocates the actual
`FUN_006e0480` record, whose array owns typed `FUN_006e0190*` elements.
The record extent, array pointer and element stride follow the native target;
serialized counts, values and bytes remain 32-bit or narrower as stored in the
save format.

## Ownership and allocation

`FUN_006e1020_shell` is the source identity for the LOS record-pointer array,
and keeps the struct identity its retained `FUN_006e1020` entry is linked by.
`LOSByteArray` is the byte array embedded in each `FUN_006e0190` record. Each
has the four virtual entries of its source table, in the source order: destroy,
allocate, free and reallocate. An array is therefore a table pointer, a native
pointer and two 32-bit counts, and an entry is its flag, that array, a native
`NavMeshInfo*` and a 32-bit value.

The map record `FUN_006e0480` contains its entry array at its start, followed
by a native `NavMeshInfo*`. Its source constructor 006e0e80 runs the array's
006e1020 and clears the pointer, and its destructor 006e04b0 deletes the
entries; neither installs a table of its own, and 006e0480 calls 006e04b0
directly before the global delete. The record is therefore not a derived
polymorphic type: it has a plain destructor and is deleted through its own
type. The historical name `FUN_006e0e80` was that constructor, not a second
type.

The default entries use the canonical game allocation, release and
reallocation entries, so one `MemoryManager` domain supplies and retires
pointer storage, records and index bytes. There is no generated vptr, host
container or provider setter.

Growth follows the source: an empty array allocates, a full block goes through
the reallocation entry, and a partly used block is copied to a new allocation
before the old one is freed. Each path obtains the replacement first, so a
failure retains the old pointer, capacity, elements and bytes. Shrink and clear
destroy records in reverse index order.

`FUN_006e0d20` allocates each `FUN_006e0480` with the global `new` and the map
deletes it with the global `delete`; both reach the same `MemoryManager`. The
record's constructor starts with an empty array and a null `NavMeshInfo*`.

llvm-lib stores archive members in reverse input order, so CMake lists the
native LOS owner first. It is stored after the accepted 2,218 members, which
keep their order. The incompatible staging provider is retired, and the
retained `FUN_006e1020` entry has one definition in the native owner.

## Loading and publication

`LOSSaveReader` is a bounded view of the save-load buffer. It borrows the
buffer's bytes and advances the buffer's own cursor, so its reads interleave
with the form-ID reads that other owners perform on the same buffer. The
boundary does not define the save-load buffer's construction, destruction or
buffer release; those stay with the save-load owner.

Within the buffer's extent the reader behaves as the source readers do:

- `TryReadRaw` (00864820) copies the payload and steps over the byte after it.
  If that byte is not `|` it reports
  `SAVELOAD: Invalid spacer hit while loading data from the buffer` through
  00845cc0 and loading continues.
- `TryReadElementCount` (00864a60) reads a one-, two- or four-byte count
  selected by the low two bits of the first byte. The fourth tag value reads
  as zero and consumes nothing.

The source reads the entry fields and the three trailing values through
00864980. The save side writes every one of them through 00865e50, which
appends the payload and one `|`, the same form 00864820 reads. For any buffer
the source writes, the reader therefore consumes the same bytes.

`FUN_006e0480::TryLoadEntries` builds a temporary array, constructs each real
entry, loads its fixed fields and optional byte indices, and replaces the live
array by swap only after the complete array has loaded.

`FUN_006e0d20` holds every record of one map load in a `LOSMapLoad` until all
records and the three trailing values have loaded and the location has loaded.
Only then does it store the values and hand each record to the map, in load
order. A record with a zero nav mesh ID is deleted as soon as it has loaded.

## Deliberate difference: reads stay inside the buffer

The source readers do not check the buffer's extent. Reading past it is the
one case the native loader treats differently, as a memory-safety policy:

- A read whose payload or separator byte lies outside the extent is refused
  and changes neither the cursor nor its destination.
- A count that the remaining bytes cannot hold is refused before storage is
  requested. Each record consumes at least 8 bytes, each entry 7 and each
  index byte 2, so such a count always runs past the extent.
- An empty buffer makes the source's raw read do nothing, but every sequence
  here then reads a count tag outside the extent, so the first read is refused.

`FUN_006e0d20` and `FUN_006e0070` return nothing in the source, and their
caller has no exception handler, so a refused read ends the load by returning:

- `FUN_006e0d20` deletes every record of this load, and leaves the map, the
  three values and the location as they were before the call. The location's
  own load is not called.
- `FUN_006e0070` leaves its record as it was.
- The buffer's cursor rests after the last complete read. The caller goes on
  reading the buffer from there, as it does after a successful load.
- Nothing is reported, because the source has no message for this case.

Exhausted storage ends the load the same way. The global `new` reports it by
throwing; the map load turns that into a refused record.

The map's insert 00844700 has no failure result: it finds or links a node and
returns, and it uses the node it is given without a check. Publication runs
inside a non-throwing boundary, so no caller can continue with only part of a
load in the map.

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
- every truncation point of a multi-entry payload and of a whole map payload
  with its trailing values, with the map, values and prior array unchanged and
  every record of the failed load retired, then retry;
- every wrong separator, reported once, with the same result as the undamaged
  payload;
- the fourth count tag as zero at each of the three counts, and counts the
  remaining bytes cannot hold, refused with the cursor after the count;
- map-load publication, zero-ID deletion, deletion by the map's delete,
  rollback of held records on failure and partial publication;
- normal and exception-unwind retirement.

The test defines 00845cc0 itself to observe the report.

The same target is run optimized and with AddressSanitizer,
UndefinedBehaviorSanitizer and vptr checks. `FUN_006e0d20` and `FUN_006e0070`
themselves are not executed: their form-ID translation, nav mesh lookup, map
and location belong to owners that have no native provider yet. These focused
checks are not a full save load, Windows execution, executable link, boot or
gameplay acceptance.
