# Pathing LOS map array lifecycle

VEGAS-77 replaces the empty `FUN_006e1020_shell` initialization and the
shell-member/derived-constructor mismatch with one native owner in
`los_map_array.cpp`. Every producer of the map's values allocates the actual
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
by a native `NavMeshInfo*`. Its source constructors 006e0e80, 006e0730 and
006e0a90 each run the array's 006e1020 and clear the pointer, and its
destructor 006e04b0 deletes the entries; none installs a table of its own, and
006e0480 calls 006e04b0 directly before the global delete. The record is therefore not a derived
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
failure retains the old pointer, capacity, elements and bytes.

Retirement is native, not recovered from the source, in two respects:

- Clear and destruction delete the entries in reverse index order. The source
  destructor 006e04b0 deletes them in ascending order.
- Shrink, and the rebuild below, delete the entries they drop. The source's
  shrink and its 006dfba0 drop the pointers without deleting the entries.

The retained `FUN_006e1020` entry releases the array's existing contents before
it returns. The source entry only initializes. The native one must therefore be
called on a constructed array, never on raw storage.

## Producers and retirers of the map's values

The map at offset 8 of the LOS grid map holds one `FUN_006e0480*` per nav mesh
ID. Three functions insert into it, and each allocates its record through
`NewLOSRecord` in the native owner, with the global `new`:

- `FUN_006e0d20`, the save loader, through `LOSMapLoad::NewRecord`. Source
  constructor 006e0e80: an empty array and a null `NavMeshInfo*`.
- `AddNavMeshes` (006e05f0). Source constructor 006e0730: an empty record that
  006dfba0 then builds from the nav mesh. `FUN_006e0480::Rebuild` is 006dfba0
  given the two values it reads from the nav mesh, the entry count and the
  info: unless the record already has an info and that many entries, it gets
  one entry per index, each with a zero flag, the info and its index. A nav
  mesh already in the map has its record rebuilt the same way.
- `UpdateFromNavMeshArray` (006e0920). Source constructor 006e0a90: an empty
  record given its info by 006dfb00, which stores the info, resolves its nav
  mesh and runs 006dfba0, and clears the info again when it has no nav mesh.

`ClearMap` (006e03e0) is the only function that removes values. It deletes each
one as a `FUN_006e0480` with the global `delete`, which reaches the same
`MemoryManager` as the `new`, and then empties the map. No function removes a
single value.

Each lookup and insert in the pathing unit passes the value at native width.

Exhausted storage is handled natively. A rebuild that cannot allocate leaves its
record as it was. A producer that cannot allocate a record makes none and
leaves that nav mesh out of the map.

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
records and the three trailing values have loaded. No failure return follows
the third value. It then hands each record to the map, in load order, stores
the values and loads the location, which is the source's order: records,
values, location. A record with a zero nav mesh ID is deleted as soon as it has
loaded.

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
inside a non-throwing boundary: an exception thrown inside it terminates the
process, so no caller can continue with only part of a load in the map.

This boundary does not alter location loading, nav-mesh ID remapping, map lock
semantics or unrelated pathfinding arrays. It does not touch generated data,
FaceGen, scene arrays, queued I/O or string ownership.

## Open remainder: consumers with historical views

The save, query and update functions of these records are not migrated. They
still read the records through their own 32-bit-shaped views, whose offsets do
not match the native record or entry:

- 006e08f0 (`pathinglosgridmap.cpp`) reads the record's `NavMeshInfo*` at
  offset 32; it is at 24.
- The entry save view 006df9c0 (`pathinglosgridmap.cpp`) reads the entry's
  value at offset 44; it is at 40.
- 006dffc0 (`blk_006c0000_od.cpp`) reads the record's `NavMeshInfo*` at offset
  16; it is at 24.
- 006df440 and 006df780 (`pathinglosgridmap.cpp`) view the entry's byte array
  without its table pointer, so their data pointer lies on that table pointer.

The other functions that receive a record or entry (006dfd20, 006dfd70,
006dfdc0, 006dfe90) reach it through the same generic array views and have not
been examined here. The historical bodies of 006e0730, 006e0a90, 006dfb00 and
006dfba0 remain in the tree with their old views; no producer calls them.

## Checks

`runtime.los_map_array` runs the production owner, map-load owner and bounded
reader with synthetic save bytes, under the production global `new` and
`delete`. Checks stay active under `NDEBUG` and cover:

- zero, one and many loaded LOS entries, with counts of each encoded width;
- allocation extents and high addresses;
- a flag byte other than 0 or 1, kept as saved and read as having no index
  bytes;
- records as each nav-mesh producer makes them, their rebuild, and their
  retirement through the same delete as loader-made records;
- grow through each path, with the reallocation entry counted, shrink at and
  above a quarter of the capacity, explicit delete, slot reuse and complete
  clear;
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
UndefinedBehaviorSanitizer and vptr checks. `FUN_006e0d20`, `FUN_006e0070`,
`AddNavMeshes`, `UpdateFromNavMeshArray` and `ClearMap` themselves are not
executed: their form-ID translation, nav mesh, map, lock and location belong to
owners that have no native provider yet. These focused
checks are not a full save load, Windows execution, executable link, boot or
gameplay acceptance.
