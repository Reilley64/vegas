# Pointer truncation census

VEGAS-44 asks that no cast truncates a pointer to 32 bits and that pointer
array moves use the element size, not 4. This document records a census of
those places in the game units, taken from the compiler's syntax tree, and the
part that is repaired. No criterion of VEGAS-44 closes with it.

The rows are in `docs/pointer-truncation-census.tsv`. The table is generated
by `tools/pointer-truncation-census/`: regenerate it, do not edit it by hand.
It describes commit `fc332bdea`, before the repairs, and marks the places that
commit `92b5c307a` repairs. The README of the tool gives the commands; run on
those two commits they write this table byte for byte.

## How the places were found

`clang-query` ran the matchers of `queries.cq` over each of the 2,224
windows-x64 compile commands of the game archive. Every unit parsed without an
error. A place in a header counts once, however many units include it. Places
in compiler and SDK headers are dropped. Pointers are 8 bytes on this build
target; "narrower" means any integer type other than the two 64-bit ones.

| Kind | What the matcher finds |
| --- | --- |
| pointer cast to a narrower integer | A pointer-to-integer conversion whose result type is narrower than a pointer. |
| pointer cast to a pointer-sized integer, then narrowed | An integer narrowing whose operand is a pointer-to-integer conversion to a 64-bit type, such as `(int)(uintptr_t)p`. |
| narrowing of a variable that holds a converted pointer | An integer narrowing of a 64-bit variable whose initializer is a pointer-to-integer conversion. One step only. |
| narrower integer cast to a pointer | An integer-to-pointer conversion from a narrower integer that is not an integer literal. |
| memory call on a pointer array | A memory call with an argument that, under its casts, points to a pointer or is an array of pointers. `*(T*)&member` counts as the member. |
| memory call with a byte count scaled by 4 | A memory call whose byte count multiplies by 4 or shifts left by 2, directly or through a variable initialised so. |
| pointer array from an allocation by byte count | An explicit cast to pointer-to-pointer of a call that returns `void*` and takes an integer literal or a value scaled by 4, `_alloca` included. |

A memory call is a call of any function whose qualified name contains `mem`
or `Mem` followed by `cpy`, `copy`, `move`, `set` or `cmp`, the first letter of
that word in either case (`memcpy`, `MemCpy`, `memMove`), and does not contain
`wmem`. A name written in other letter case, such as `MEMCPY`, does not match;
a text scan of `src` and `include` at `fc332bdea` finds no call of such a
name. Pointer arguments and the byte count are found by type,
not by position, so `memcpy_s` and `memmove_s`, whose byte count is not the
third argument, need no special case. The byte count is the last argument
that is not a pointer. The places matched call these names:

| Name | Calls |
| --- | ---: |
| `memset` | 601 |
| `__memcpy` | 31 |
| `memmove` | 25 |
| `memcpy` | 11 |
| `memcmp` | 5 |
| `memmove_s` | 2 |
| `C44E4A0MemMoveS`, `MemsetWrapper`, `memCpy4_d65f` | 1 each |

The tree spells memory functions under more names than these. A text scan of
`src` and `include` at `fc332bdea` counts each name written before `(`,
declarations included. Besides the standard four it finds `__memcpy` (247),
`fnv::crt::memmove_s` (37), `_memmove` (14), `fnv::crt::memcpy_s` (11),
`_memcmp` (2), `memmove_s` and `memcpy_s` with no or a global qualifier,
`NiMemcpy`, `NiMemset` and more than twenty unit-local copies such as
`C44E4A0MemMoveS` or `MemoryUtils::memCpy16NonEmpty`. Every one of them falls
under the name rule. `memcpy_s` is called 77 times in 17 files, outside its
declarations and its definition in `src/runtime/crt.cpp`: for example
`fnv::crt::memcpy_s` in `src/bsmenu/font.cpp` and `::memcpy_s` in
`src/bsmenu/tileimage.cpp`. None of these calls is a place of the census.
Some of the local copies count in 4- or
16-byte units, not bytes; the census reads their last integer argument as a
byte count all the same.

Each byte count is put in one class: `sizeof`, `sizeof` with an added literal,
`sizeof` of a 4-byte type, a count times 4 (`n * 4`, `n << 2`, `n * 4 + 4`), a
count times another constant, a literal alone, or a variable.

Pointer-derived values are told from ordinary narrowing by the conversion kind
in the syntax tree, not by the text. For the cast kinds the census also records
what the operand is: `this`, the address of an object, a function, an array, a
string literal or a `dynamic_cast` result (a live address for certain), or a
value read from a variable, a member or a call. The second group truncates
only if the value is an address. Many of these values come from declarations
that stand in for the real one and give a pointer type to what is a count or
an id.

## What the census cannot see

Each blind spot is listed with what measures it. The counted-only kinds are
matchers whose places are counted but not put in the table.

| Blind spot | Measure at `fc332bdea` |
| --- | --- |
| A pointer read through a 32-bit member of a padded layout, with no cast in the source | Not measured. One family is tabled below ("Buffers of the physics world"): 17 stand-in records of 5 buffers place the array at an offset that differs from the constructor's. |
| A pointer that reaches a narrowing through more than one variable, a member or a call | Narrowings of a 64-bit variable not initialised from a pointer conversion: 2,066 places (counted only). |
| A pointer array copied by a loop | Pointer assignments between subscripts inside a loop: 88 places (counted only). |
| Storage declared `void*` or `char*` whose element is not visible | Memory calls scaled by 4 on such storage: 63 places, in the table as open. A literal or variable byte count on such storage is not matched. |
| Storage allocated elsewhere by a literal or a count times 4 | Calls that return `void*` with such an argument and are not cast at once: 980 places (counted only). The world buffers below are of this kind. |
| A count scaled by 4 on a declared 4-byte scalar | 30 places, labelled by declared type only; one is hand-checked and open. |

An integer literal cast to a pointer is excluded on purpose; it is not a
truncation.

## Counts

A row of the table is one file, function, kind and disposition, with the
number of places. There are 3,713 places in 536 files and 1,897 rows.
The function is the qualified name of the enclosing function definition.
Initializers outside any function are `(file scope)`.

| Kind | Before | After |
| --- | ---: | ---: |
| pointer cast to a narrower integer | 50 | 47 |
| pointer cast to a pointer-sized integer, then narrowed | 2,074 | 2,074 |
| narrowing of a variable that holds a converted pointer | 113 | 113 |
| narrower integer cast to a pointer | 755 | 755 |
| memory call on a pointer array | 579 | 579 |
| memory call with a byte count scaled by 4 | 122 | 113 |
| pointer array from an allocation by byte count | 20 | 15 |

A memory call on a pointer array that also scales by 4 is counted under both
kinds. The count of memory calls on pointer arrays does not fall when a call is
repaired; its byte count now uses `sizeof`.

| Disposition | Places |
| --- | ---: |
| repaired | 26 |
| no action: the byte count uses `sizeof`, or the operand is a constant | 198 |
| declared 4-byte scalar (declared type only) | 29 |
| open: the address of a live object cut to 32 bits | 151 |
| open: a pointer-typed value cut to 32 bits | 2,080 |
| open: a pointer rebuilt from a 32-bit value (8 of them in a generated file) | 733 |
| open: literal byte count on a pointer array | 356 |
| open: `sizeof` with an added literal | 16 |
| open: the bytes of pointer storage copied into storage of another type | 6 |
| open: variable byte count on a pointer array | 4 |
| open: count times 4 on a pointer array, the storage it covers not established | 24 |
| open: count times 4, the element type not visible | 63 |
| open: count times 4, the element a structure not checked against 4 | 5 |
| open: a pointer table seen through an `int*`, checked by hand | 1 |
| open: a stale stand-in, `RemoveAt` of the idle form array, checked by hand | 4 |
| open: count times 4 on an array of one-pointer structures, checked by hand | 1 |
| open: a 4-byte local passed through a `void*` parameter, checked by hand | 1 |
| open: a pointer array allocated as a count times 4 bytes | 11 |
| open: a pointer array allocated from a literal byte count | 4 |

The 26 repaired places are 17 statements: 3 casts, 9 memory calls (each
counted under two kinds) and 5 allocations.

## Repaired

The byte count or allocation at these statements uses the declared element
size, shown at source and object level, never executed. Each takes the
element from the unit's own declaration of the array, through `sizeof` of the
element. No changed unit compiles for the host, so no host test runs them; a
test is owed when a unit first compiles for the host or a Windows path reaches
it. In the windows-x64 objects only the functions that hold the changed
statements, and the functions that inline them, differ.

- `fnv_00a1cb80::MemoryManager::Deallocate` in `src/bsmenu/menu.cpp` held
  three casts. It was an inline body that nothing called, and it is removed.
  The object has the same code, relocations and symbols.
- `FUN_00454fc0_shell::CompactQueuedCells` in `src/fallout_shared/tes.cpp`
  moves `TESObjectCELL*` slots. No statement in the tree allocates
  `m_ppCellBufferB` under that name, so the size of the buffer is not shown;
  the moved slots lie between two indexes the function already reads.
- `Controller::FUN_00a2feb0` and `FUN_00a30160_cls::FUN_00a30160`
  (`nimultitargettransformcontroller.cpp`), `Map::Map`
  (`nidefaultavobjectpalette.cpp`) and `SkinWeights::WeightMap::Initialize`
  (`niskinpartition.cpp`) allocate the array and clear it.
- `Holder::FUN_00a5ba40` (`src/staging/blk_00a40000_o2.cpp`) grows the
  extra-data array of `NiObjectNET`; `NiObjectNET::ResizeExtraData` in
  `niobjectnet.cpp` already sizes the same array by `sizeof(NiExtraData*)`.
- `BGSIdleCollection::Load`, `BGSIdleCollection_shell::IsDifferentFrom` and
  `FUN_00479850_shell::FUN_00479850` (`bgsidlecollection.cpp`) clear, compare
  and copy `m_ppIdleForms`. Every destination is a typed `new[]` in the same
  unit. `IdleCollectionStandIn::RemoveAt` is not repaired; see "The idle form
  array".

## Open places recorded with the repair

### Buffers of the physics world

The constructor at `0x00c69010` (`fnv_00c69010::FUN_00c69010` in
`src/staging/blk_00c60000_o2.cpp`) allocates five buffers by literal byte
counts, 12000, 800, 400, 800 and 12000, and clears each. Functions at
`0x00c676e0` to `0x00c6b320` handle arrays of pointers through stand-in
declarations of the same object. In the 32-bit layout every one of their array
members sits at the offset of one buffer, 0x2c, 0x34, 0x3c, 0x44 or 0x4c, and
each caps its count at 3000, 200, 100, 200 or 3000: the byte count of that
buffer divided by 4. The destructor at `0x00c6aca0` frees the same five.

On windows-x64 the join does not hold. The constructor and the destructor
place the buffers at 0x38, 0x48, 0x58, 0x68 and 0x78, and the constructor
zeroes the 4-byte words that follow them, at 0x40, 0x50, 0x60, 0x70 and 0x80.
The stand-ins place their arrays at 0x30, 0x38, 0x40, 0x48 and 0x50 and their
counts 8 bytes further on, because each pads its record for a 4-byte pointer.
Laid over the constructor's object, measured from the record layouts of the
windows-x64 compile:

- Array at 0x38, count at 0x40 (`ClearIndexedValues`, `ClearReferences`,
  `C68CB0World`): they read the 12000-byte buffer, which by the 32-bit join is
  the wrong one, and a count the constructor zeroes. Their cap of 200 keeps
  every access and both clears within the 12000 bytes.
- Array at 0x48, count at 0x50 (`WorldImpl` in `ProcessConstraints`,
  `PendingWorld`, `C68D50World`, `FUN_00c6b320_Class`): they read the 800-byte
  buffer. Their count is capped at 200 and the adders store 8-byte entries, so
  they write up to 1,600 bytes into 800, and both clears cover the same 1,600.
  That is a live defect on x64, though nothing runs it today.
- Array at 0x40, count at 0x48 (`FUN_00c6aac0`, `ReleaseBodies`, `AddItem`,
  and the shapes of `QueueManager`): the array is the zeroed word at 0x40 and
  the 4 bytes of padding after it, read as a pointer; the count is the low half
  of the 800-byte buffer's pointer.
- Array at 0x50, count at 0x58 (`World::ClearEntries`, `FlushEntries`,
  `WorldC68BF0`): the array is the zeroed word at 0x50 and its padding; the
  count is the low half of the 400-byte buffer's pointer. `ClearEntries` caps
  that count at 3000 and then clears `count * 4` bytes at the array.
- Array at 0x30, count at 0x38 (`FUN_00c68a40`, the bodies of
  `QueueManager`): the array is the word at 0x30 and its padding; the count is
  the low half of the 12000-byte buffer's pointer.

No stand-in reads the buffers at 0x58, 0x68 or 0x78.

| Buffer | Bytes | Cap | Functions on the array (recipe address) |
| --- | ---: | ---: | --- |
| 0x2c | 12000 | 3000 | `FUN_00c68a40_Class::FUN_00c68a40` (`0x00c68a40`), `QueueManager::FUN_00c6b0a0` (`0x00c6b0a0`, adds) |
| 0x34 | 800 | 200 | `This676::ClearIndexedValues` (`0x00c676e0`), `Owner::ClearReferences` (`0x00c67bc0`), `C68CB0World::FUN_00c68cb0` (`0x00c68cb0`, adds) |
| 0x3c | 400 | 100 | `fnv_00c6aac0::FUN_00c6aac0_Owner::FUN_00c6aac0` (`0x00c6aac0`), `WorldView::ReleaseBodies` (`0x00c67cd0`), `S69580_World::AddItem` (`0x00c69580`, adds) |
| 0x44 | 800 | 200 | `FUN_00c67850_Class::ProcessConstraints` (`0x00c67850`), `PendingWorld::ProcessPendingItems` (`0x00c67df0`), `C68D50World::FUN_00c68d50` (`0x00c68d50`, adds), `FUN_00c6b320_Class::FUN_00c6b320` (`0x00c6b320`, adds) |
| 0x4c | 12000 | 3000 | `World::ClearEntries` (`0x00c679a0`), `FUN_00c67aa0_Class::FlushEntries` (`0x00c67aa0`), `WorldC68BF0::FUN_00c68bf0` (`0x00c68bf0`, adds) |

Four of the clears, `ClearIndexedValues`, `ClearReferences`, `FUN_00c6aac0`
and `ClearEntries`, use the count times 4. Three others, `ReleaseBodies`,
`ProcessConstraints` and `ProcessPendingItems`, already use `sizeof` of a
pointer, and every adder stores at pointer stride up to the cap. If the 32-bit
join is the real one, each buffer holds half the slots its users address. None
of it is changed here, and every row above stays open: the overflow of the
800-byte buffer, the reads of count words and padding as pointers, and the
counts taken from buffer pointers. The repair needs one declaration of the
world that the constructor and every user share, so that the array each
function reads is the buffer that was allocated (open decision 6).

### The idle form array

`BGSIdleCollection::Load` reads 4-byte form IDs from the file into the slots
of `m_ppIdleForms`, which are 8 bytes, and `InitItem` reads them back one slot
per ID. The array holds form IDs first and pointers after `InitItem`. Whether
to keep both in one array needs a decision; the load path is not changed.

`IdleCollectionStandIn::RemoveAt` (`0x00479ea0`) is a stale stand-in and
stays open. `InitItem` calls it through `reinterpret_cast` of `this`. The
stand-in reads the count at 0x5 and the array at 0x8; `BGSIdleCollection` has
them at 0x9 and 0x10 on x64. So on x64 `RemoveAt` never reaches the array the
class allocates, and its two copies keep the count times 4 until the stand-in
is replaced by the class. The table gives its four places their own
disposition through `overrides.tsv`. Out of scope here and already in the
tree: `RemoveAt` releases the `new[]` storage with `delete`, not `delete[]`,
at lines 352 and 370.

### The lock-free queue scanners

`fnv_00c42b80::C42List::FUN_00c42b80` (`src/staging/blk_00c40000_od.cpp`) and
`OwnerX::FUN_0044eed0` (`src/staging/blk_00440000_od.cpp`) are two copies of
one template: the scan for deleted nodes of a lock-free queue, which copies
the owner's buffer of `count * 2` node pointers by `n * 4` bytes. The 32-bit
layout of `C42Owner` matches `LockFreeQueue`, with the buffer at 0x10 and the
manager at 0x14. The only allocations of that buffer in the tree are the two
`LockFreeQueue` constructors in `threadsafestructures.inl` (`0x0044b350` and
`0x006c6450`), each a typed `new LockFreeQueueEntry*[maxThreads * 2]`. Nothing
in the tree or the recipe ties either constructor to the queue that
`0x00c42b80` scans; its nodes hold a reference-counted pointer, so it is
another instantiation. Both copies stay open.

### Other memory calls scaled by 4 on a pointer array

Twelve such calls stay open, in nine functions, besides the two copies of
`RemoveAt`, which have their own disposition. Six are above: the four world
clears and the two queue scanners. The other six were not examined in this
round:

- `LFFreeList::PruneFreeList` (`bstreemanager.cpp`, `0x006c7610`) is a third
  copy of the queue scan. Its address lies next to the `LockFreeQueue`
  constructor at `0x006c6450`; nothing in the tree joins the two.
- `fnv_00e95140::NiDynamicGeometryGroup::FUN_00e95140`
  (`niunsharedgeometrygroup.cpp`) clears `m_ppkVertexBuffers`, which no
  statement in the tree allocates under that name, and reads no slot.
- `Arr994350::InsertSortedEntry` (`src/staging/blk_00980000_od.cpp`) moves
  slots of `m_items` with four `__memcpy` calls; the census sees them since its
  name rule matches `__memcpy`.

### Byte counts written as sizeof minus a member offset

Sixteen calls in `src/staging/blk_00b80000_o2.cpp`, two in each of eight
`Create…Shaders` functions, clear part of a stack object as
`memset(&k.m_akMacros[0].m_pcDefinition, 0, sizeof(k) - 8)` or `- 0x10`. The
literal is the 32-bit offset of the member. On windows-x64 the member lies
further in, so each call writes 8 or 16 bytes past the object. They are open
defects; the table lists each with its function.

### Places checked by hand

Each of these has its disposition in `overrides.tsv`, besides the four places
of `RemoveAt` above. All stay open.

- `CreateCreatorMap` in `nid3dshaderprogramfactory.cpp` (`0x00e93d80`)
  allocates a 37-bucket table by `FUN_00aa1070(0x94)` and clears `4 * p[1]`
  bytes through an `int*`. The table holds pointers.
- `S_00c42960::FUN_00c42960` (`src/staging/blk_00c40000_od.cpp`,
  `0x00c42960`) allocates `n9` slots of `S_00c42960_Slot`, a structure that
  holds a single pointer, and copies `n9 * 4` bytes into them. On x64 that
  copies half the slots.
- `Script::IsCurrentFurnitureRef` (`tesscriptfunctions.cpp`, `0x005c6e70`)
  passes a 4-byte local, named `formID` and filled by `ExtractArgs`, through
  the `void*` parameter of `FUN_0059df40`, which compares it with the pointer
  a virtual call returns. Whether the local holds a form ID or a reference is
  not established; the row is labelled by what the code does.

## The 256-slot pool map

The original finds the pool of a block as `ms_pPoolAddressMap[address >> 24]`
(`0x011f63b8`), a table of 256 slots of 16 MB. The canonical manager does not
use it: its release looks the owner up with full-width addresses
(`docs/native-engine-heaps.md`).

How "no object reads it" was measured: `llvm-nm` over every object of the
windows-x64 build of `fc332bdea` finds the symbol in two objects only.
`memorymanager_console.cpp` defines it; `memorypool.cpp` requires it.
`llvm-objdump -dr` of the two lists seven relocations to it. Each is a `lea`
whose result is used only as the address of a store or as the destination of
`memset`: `ClearMemoryPoolTables`, the legacy pool constructor
(`0x00aa66a0`), its destructor (`0x00aa6800`), the registration
(`0x00aa6980`) and the removal (`0x00aa6a10`). No instruction loads from it.
Two units carried three lookups through it, each an inline body of a padded
stand-in manager that no function calls, so none is in an object. The one in
`menu.cpp` truncated the address and is removed. The two in
`src/staging/blk_00aa0000_od.cpp` (`MM::Deallocate` and
`MMDealloc::FUN_00aa4060`) index with `uintptr_t` and are left in place.

Decision needed: retire the legacy registration and the map with it, or keep
them as recorded source that the native startup never runs.

## Open decisions

1. The open cast places and the open rebuilds need the receiving declaration
   widened: a parameter, a member or a return type that is 32-bit today. That
   changes names other units require, so it belongs with the work on shared
   declarations, not with a local edit.
2. The literal byte counts on pointer arrays need the array bound from the
   declaration of each array. Most clear a `const char**` table with a count
   such as 68, which is 17 slots of 4 bytes.
3. The pointer arrays allocated as a count times 4 need only the element size
   in place of the 4, as the repaired ones show; each needs its readers checked
   first. The ones allocated from a literal byte count need the bound as in 2.
4. The scaled memory calls on `void*` or `char*` storage and on structures need
   the element type of each buffer.
5. The sixteen byte counts written as `sizeof` minus a 32-bit member offset
   need the offset taken from the member, with `offsetof` or the member's
   address.
6. The buffers of the physics world need one shared declaration of the world
   before their allocation and clears can be widened together.
7. The idle form array needs a decision on form IDs and pointers in one array.
   `IdleCollectionStandIn::RemoveAt` needs its stand-in replaced by
   `BGSIdleCollection` before its copies can be sized.
8. `BSFile::Seek(int, int)` in `src/bssystem/console/bsfile_console.cpp`
   (`0x00b00590`) keeps a 32-bit offset and position. It is outside this
   census.
