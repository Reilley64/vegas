# Reads past the end of generated tables

VEGAS-30. The fifteen generated vtable units,
`src/generated/data/vtables_01xx.cpp`, define 2,057 tables in the
windows-x64 archive: 2,047 with an initializer and 10 whose slots are all
null. Compiled as one section per unit, a unit's tables lie one after
another, so a read just past the end of a table reads whatever the compiler
placed next. After the five two-slot tables below that is the first slot of
the next table. After the three-slot `DAT_010cf9c8` it is 8 bytes of padding
before the next table. Either read is already wrong, because neither is the
original's slot. Once each table has a section of its own
(the per-table sections step below) the read would land on whatever the
linker places next. This page records how such reads were found, how each
was repaired, the checks that keep them out, and the per-table sections
step.

## Why the tables are short

The generator ended each table at the next address that the recipe,
`build/units.json`, names. For six tables that address is the table's next
slot. The recipe names it on its own as a function pointer:

| Table | Slots | The slot after it |
| --- | --- | --- |
| `DAT_010c4db8` | 2 | `DAT_010c4dc0` |
| `DAT_010c53b4` | 2 | `DAT_010c53bc` |
| `DAT_010c7310` | 2 | `DAT_010c7318` |
| `DAT_010c8d00` | 2 | `DAT_010c8d08` |
| `DAT_010c8d14` | 2 | `DAT_010c8d1c` |
| `DAT_010cf9c8` | 3 | `DAT_010cf9d4` |

Generated data defines each slot name but `DAT_010c4dc0` as its own variable,
holding the function the original's slot holds. `DAT_010c4dc0` had no
definition; `blk_00c60000_o2.cpp` now defines it (below). The code that uses
`DAT_010c8d00` and `DAT_010cf9c8` already calls the slot by its own name.
So do the destructors at `0x00ca0d70` and `0x00cba000` for `DAT_010c7310`
and `DAT_010c8d14`. That is the form the repairs below use.

## How the reads were found

Three scans ran at `973b5d612` and again at `e904ce163`. Their scripts are
kept with the review evidence, outside the repository.

- Relocations. Every relocation of every member of the game archive whose
  target is one of the tables, with its stored addend, against the table's
  length from the generated source. At `e904ce163` there are 4,300 such
  relocations to the 2,047 tables with an initializer, all `REL32`. 27 have
  an addend that is not 0, and 7 address a table at or past its end. Each of
  the 7 is a call through the slot 16 bytes past the start of a two-slot
  table: the windows-x64 view of the original's slot 8 bytes past it.
- Source. In every file outside `src/generated/data` that names a table: a
  cast of the table's address to a struct whose member is then read; a
  table pointer field that the file assigns a table to, cast to a struct
  whose member is then read; byte offsets and subscripts on a table; and
  classes with virtual functions whose objects get a table stored by hand,
  with their count of virtual functions against the table's slots. Member
  offsets come from the struct's definition in the same file. The scan
  finds the same 7 reads. It flags two more places, and neither reads a
  known table past its end. Both match by a field name that two structs of
  the file share. In `debugtextparticlesystem.cpp` the read is
  `SourceVec`'s, whose table `DAT_01071aec` has 32 bytes. In
  `blk_00980000_od.cpp` the struct whose field is read,
  `FUN_0098f7b0_Class`, never gets a table stored in the source.
- Recipe. The six tables above: tables whose next address in the recipe is
  a function pointer.

Two of the four repaired places read past the end since a later edit:
`FUN_00ca0d40` and `FUN_00cba080` read byte offset 8 of their table, the
original's 32-bit offset of the slot, until `d560f01b0` gave them a
three-slot view whose third slot lies 16 bytes in. On windows-x64 offset 8
was the table's second slot, so neither form read the original's slot.
`FUN_00c812d0` and `PointerVec`'s destructor have read the third slot of a
two-slot table since the first transcription. The fifth place,
`FUN_00c7a630`, named `DAT_010c4dc0` until `76ca21379`.

## Repaired

Each function now calls the slot by the name the recipe gives it. In the
windows-x64 object each call now goes through the slot's name instead of
the table's name plus 16. Nothing else in the function changes, apart from
the argument registers noted below and the code offsets that follow.

| Function | Unit | Table | Slot called |
| --- | --- | --- | --- |
| `FUN_00ca0d40` | `src/staging/blk_00ca0000_o2.cpp` | `DAT_010c7310` | `DAT_010c7318` |
| `FUN_00cba080` | `src/staging/blk_00ca0000_o2.cpp` | `DAT_010c8d14` | `DAT_010c8d1c` |
| `FUN_00c812d0`, twice: the normal path and the unwind path | `src/fallout/ai/creature.cpp` | `DAT_010c53b4` | `DAT_010c53bc` |
| `Manager::FUN_00ca2ad0`, twice: `PointerVec`'s destructor, inlined | `src/unmapped/debugtextparticlesystem.cpp` | `DAT_010c7310` | `DAT_010c7318` |

The first two passed one pointer before and still do. The other two passed
the array and the data pointer, and now pass the data pointer alone:

- The recipe types the slots as `__stdcall` functions of one pointer:
  `?DAT_010c53bc@@3P6GXPAH@ZA` and `?DAT_010c7318@@3P6GXPAX@ZA`.
- Every other caller of these slots passes one pointer: `FUN_00c80630` and
  `FUN_00c80660` in `blk_00c80000_o2.cpp` for `DAT_010c53bc`;
  `FUN_00ca0d40`, `FUN_00ca0d70` and the `ChildLayout` destructor of
  `fnv_00ca2140` in `blk_00ca0000_o2.cpp` for `DAT_010c7318`; and
  `FUN_00cba000` for `DAT_010c8d1c`, which holds the same function.
- The slots hold the function at `0x00cb9cb0`, whose recipe row is 10 bytes.
  By inference that is a forwarder of one argument to the memory manager.
- The two-argument form never matched the original.

In `creature.cpp` the argument is `static_cast<int *>(data)`: a conversion
between data pointers that keeps the address, as the final conversion into
the slot's parameter type. In `debugtextparticlesystem.cpp` the `Item **`
data pointer converts to `void *` without a cast. In the objects the load of
the array's address into the first argument register is gone, and the data
pointer moves into it.

In `blk_00ca0000_o2.cpp` the private three-slot struct `FUN_00ca0d40_vtable`,
which only the two calls used, is removed. In `creature.cpp` only the `Free`
member of the private struct `DAT_010c53b4_t` goes; the struct stays. In
`debugtextparticlesystem.cpp` the `VecTable` view stays, for two other tables
of 32 bytes. The declaration of `DAT_010c53bc` joins
`include/fnv/symbols_010c5000.h`. The recipe entries of `creature.cpp` that
hold the `0x00c812d0` row and of `debugtextparticlesystem.cpp` gain the keys
of the slot names they now use, in the spelling the recipe already has at
those addresses.

What the repairs establish is which storage each call reads. Receivers,
layouts and lifetimes of the four functions stay open.

### `0x00cb9cb0` frees its argument (VEGAS-102)

The windows-x64 body of `0x00cb9cb0`, `fnv_00cb9cb0::FUN_00cb9cb0` in
`blk_00ca0000_o2.cpp`, took no parameter and passed a null pointer to the
memory manager's free, so every caller of the slots that hold it leaked the
pointer it meant to free. It now takes that one pointer and passes it on.
The source declares it with no calling-convention keyword, as VEGAS-12
requires of game code; the host test `source.calling_convention_keywords`
fails when one is written there. The recipe spells it stdcall, as do the
keys of the slots that hold it but for `DAT_010c8d08` (`__cdecl`) and
`DAT_010c4cec` (a data pointer), because the recipe records the original's
convention; on windows-x64 the convention changes nothing.
In the object the body is `movq %rcx, %rdx`, the address of the memory
manager in `rcx`, and a jump to the free, where it was `xorl %edx, %edx`
before the jump.

The body's windows-x64 name changes from
`?FUN_00cb9cb0@fnv_00cb9cb0@@YAXXZ` to
`?FUN_00cb9cb0@fnv_00cb9cb0@@YAXPEAX@Z` (route A of the 2026-11-12
ruling). Five generated files name it through an asm label: the staging
includes of `blk_00ba0000_o2`, `blk_00c60000_o2`, `blk_00c80000_o2` and
`blk_00ca0000_o2`, and `vtables_010c.cpp`. The native data composition
respells the five labels (`docs/native-data-ownership.md`); the generated
files are unchanged. Through those labels seven slots hold the body:
`DAT_010b7f08`, `DAT_010c4cec`, `DAT_010c53bc`, `DAT_010c7318`,
`DAT_010c8d08`, `DAT_010c8d1c` and slot 2 of the table at `DAT_010c8d28`.
Each slot keeps its bytes; its relocation now names the new symbol. The
recipe's function row at `0x00cb9cb0` is respelled to the 32-bit stdcall
name of the new signature, `?FUN_00cb9cb0@fnv_00cb9cb0@@YGXPAX@Z`, with its
address, size and unit unchanged.

Not every caller passed one pointer. A census of the windows-x64 archive
lists every function with a relocation to one of these slots or to the
table before it, every call through such a slot by name, and every call
through offset 16 of a table pointer in a function that stores one of the
tables. All but two pass the pointer to free as their one argument:

- `FUN_00cbaec0_Obj::ReleaseAndDestroy` (`0x00cbaec0`) in
  `blk_00ca0000_o2.cpp` stores `DAT_010c8d28` as the object's table and
  then called slot 2 of it as a member function, `vf08(m_pData)`, which
  passes the object in `rcx` and the data in `rdx`. With the repaired body
  it would have freed the object, and freed it again when flags bit 0 is
  set. The recipe names no symbol at the slot's address, so the function
  now calls slot 2 of the table it stored through a function type of one
  pointer, with no calling-convention keyword, and passes `m_pData`
  alone; the private struct loses `vf08`. In the object only the argument
  registers change: `movq 0x8(%rsi), %rdx; movq %rsi, %rcx` became
  `movq 0x8(%rsi), %rcx` before the same `callq *0x10(%rax)`. This repair
  comes before the body's, so no commit frees the object.
- `FUN_00ba11e0` in `blk_00ba0000_o2.cpp` calls `DAT_010b7f08` with a
  pointer sign-extended from the 32-bit field `m_04` of its `Buffer`. That
  is VEGAS-104 and is not changed here (below).

`actor.cpp`'s `TempArray` destructor and `FUN_00c7f060` called
`DAT_010c4dc0` with a `TempArray` and a count under a name that no member
defined, so they did not reach the body. They and four more callers of the
same kind now pass one pointer (VEGAS-103, below).

`DAT_010b7f08` is declared and defined as `HLOCAL (*)(HLOCAL)`, a function
that returns a pointer, and its recipe key `?DAT_010b7f08@@3P6GPAXPAX@ZA`
says the same, while `0x00cb9cb0` returns nothing. Its only caller,
`FUN_00ba11e0` in `blk_00ba0000_o2.cpp`, discards the result: in the object
nothing reads `rax` after the call. It is not repaired here, because its
type is that of a generated definition. The call through a pointer of
another function type stays open, as does that `FUN_00ba11e0` passes a
pointer read from the 32-bit field `m_04` of its `Buffer`. Both are
VEGAS-104.

## `FUN_00c7a630` and the slot `DAT_010c4dc0`

`FUN_00c7a630` in `src/staging/blk_00c60000_o2.cpp` called through the slot
16 bytes past the start of `DAT_010c4db8`. In the object that read slot 0
of the next table, `FUN_00c7e970` of `Outer`. The original's slot is
`0x010c4dc0`. By coordinator ruling (R2) the call was not repaired with a
cast before the declaration of `DAT_010c4dc0` was settled:

- The recipe spelled the slot `?DAT_010c4dc0@@3P6EXPAUTempArray@@I@ZA`: a
  `__thiscall` function of a `TempArray *` and an `unsigned int`. Its
  siblings above are `__stdcall` functions of one pointer. `FUN_00c7a630`
  and its neighbour `FUN_00c7a690`, which called `DAT_010c4dc0` through a
  cast to `void (*)(void *)`, pass one pointer.
- No unit defined `DAT_010c4dc0`. Generated data has no variable for it.
- `actor.cpp` declares `TempArray` with 32-bit `unsigned int` fields, and its
  destructor, which has no recipe row, stores `DAT_010c4db8` and frees its
  data through `DAT_010c4dc0(this, data)`: the shape of `0x00c7a630`. It is
  likely a stale 32-bit second transcription of that function, and the
  source of the `TempArray` spelling.

The 2026-11-12 rulings settled it:

- `include/fnv/symbols_010c4000.h` declares `DAT_010c4dc0` as
  `void (*)(void *)`, as its recipe key, the siblings and both callers
  establish. The key spells the pointer stdcall; the source writes no
  calling-convention keyword (VEGAS-12).
- `blk_00c60000_o2.cpp`, the unit the recipe binds the name to and which
  holds the rows of the table's functions, defines the slot with the
  one-pointer body of `0x00cb9cb0`, without a cast. The value follows from
  the siblings, which all hold `0x00cb9cb0`. The repository's earlier
  generated data (`d4a5c0038`) gave the slot the same value; it is
  corroboration only. The recipe key of `blk_00c60000_o2.cpp` is respelled
  to the siblings' spelling, `?DAT_010c4dc0@@3P6GXPAX@ZA`, and the unit's
  entry gains the key of the body it now names,
  `?FUN_00cb9cb0@fnv_00cb9cb0@@YGXPAX@Z`.
- `FUN_00c7a690` calls the slot by name, without its cast, and so does
  `FUN_00c7a630`, with the same one argument, `m_p`. Its private three-slot
  view `FUN_00c7a630_vtable` is removed. In the object its call now goes
  through `DAT_010c4dc0` at offset 0 instead of `DAT_010c4db8` plus 16.
- `actor.cpp`'s `TempArray` is tabled (VEGAS-103). The unit no longer
  includes `fnv/symbols_010c4000.h` and declares the two names it used from
  it, `DAT_010c4db8` and its two-argument view of `DAT_010c4dc0`, so its
  object and the name it requires, `?DAT_010c4dc0@@3P6AXPEAUTempArray@@I@ZEA`,
  do not change. That name stays undefined, and the recipe keys of
  `actor.cpp` and of `clamped_acos.cpp`, whose source does not use the name,
  keep the `TempArray` spelling. One storage thus had two declarations of
  different type in two units until VEGAS-103 repaired `TempArray` (below):
  the unit includes the header again, and its recipe key has the shared
  spelling. `clamped_acos.cpp`'s key keeps the `TempArray` spelling.

What this establishes is which storage the two calls read and that the slot
has one definition. Receivers, layouts and lifetimes of `FUN_00c7a630` and
`FUN_00c7a690` stay open.

## Array classes whose slot 2 frees one pointer (VEGAS-103)

Three of the original's tables hold `0x00cb9cb0` in their third entry, the
slot that frees an array's data. For the first two, generated data defines
that entry as a variable of its own after a two-slot table. The recipe's
rows and keys tie each table to classes in two units:

| Table | Slot 0, slot 1 | Slot 2 | Rows of its functions | Classes in the source |
| --- | --- | --- | --- | --- |
| `DAT_010c4db8` | `0x00c7a690`, `0x00c7a5d0` | `DAT_010c4dc0` | `0x00c7a630`, `0x00c7a690` | `FUN_00c7a630_class`, `FUN_00c7a690_class` in `blk_00c60000_o2.cpp`; `TempArray` in `actor.cpp` |
| `DAT_010c4ce4` | `0x00c7a6e0`, `0x00c75f40` | `DAT_010c4cec` | `0x00c7a660`, `0x00c7a6e0` | `S_00c7a660_Foo`, `FUN_00c7a6e0_class` in `blk_00c60000_o2.cpp`; `SkeletonBuild::BoneRecordArray` in `actor.cpp` |
| `DAT_010c8d28` | `0x00cbaec0`, `0x00c75f40` | slot 2 (slot 3 `0x00cb9cc0`) | `0x00cbaec0`, `0x00cbadb0` | `FUN_00cbaec0_Obj`, `FUN_00cbadb0_Obj`, `ArrayCBAF90`, `AryType` in `blk_00ca0000_o2.cpp` |

Slot 0 of each is the deleting destructor; the other row is the destructor.
The recipe binds `??_7BoneRecordArray@SkeletonBuild@@6B@` to `0x010c4ce4`
and the tables of `ArrayCBAF90`, `FUN_00cbadb0_Obj` and `AryType` to
`0x010c8d28`. `TempArray` stores `DAT_010c4db8` by hand.

### The layout the bodies use

Every class is a table pointer, the data, a count and a capacity. On
windows-x64 the bodies that use these arrays read the data as a pointer at
8, and the count and the capacity as 32-bit integers at 16 and 20, 24 bytes
in all:

- `AppendSlot` (`0x00c7a730`), which `FUN_00c7bcb0` calls on the
  `TempArray` of `FUN_00c7f060`, compares the count at 16 with the capacity
  at 20, stores the allocated data at 8 and increments the count.
- `RestoreNodeTransforms` (`0x00c75c00`) reads the data at 8 and the count
  at 16 of the same array.
- `actor.cpp`'s `BoneRecordArray`, whose fields `FUN_00c7e3b0` reads, and
  the four classes of `DAT_010c8d28` declare that layout.

Two declarations disagree:

- `actor.cpp`'s `TempArray` declared the data as a 32-bit `unsigned int`.
  That put the count at 12 and the capacity at 16, and its constructor left
  the bytes at 20 unset. It is a stale 32-bit view and is repaired (below).
- The four destructors in `blk_00c60000_o2.cpp`, `0x00c7a630`,
  `0x00c7a690`, `0x00c7a660` and `0x00c7a6e0`, declare the count and the
  capacity as pointers, at 16 and 24. Each stores 16 zero bytes at 8 and 8
  zero bytes at 24, which is past the end of a 24-byte array. Their offsets
  are neither the 32-bit ones nor those of the other bodies. They are not
  changed here, because that changes four functions of the recipe's rows
  (open, below).

### Repaired

Each call passes the data alone, as the slot's one-pointer body takes it.
None of them is reached by a linked program today: the names they called
had no definition, or the tables they read are those the compiler emits for
the source's classes, whose slot 2 is a member that no unit defines.

| Function | Unit | Before | Now |
| --- | --- | --- | --- |
| `TempArray`'s destructor, and inlined twice into `FUN_00c7f060` (normal and unwind path) | `actor.cpp` | `DAT_010c4dc0(this, data)`, data 32-bit, under `?DAT_010c4dc0@@3P6AXPEAUTempArray@@I@ZEA` | `DAT_010c4dc0(data)` through the shared declaration |
| `BoneRecordArray`'s destructor and `RemoveAll`, inlined into `FUN_00c7e3b0` | `actor.cpp` | member call `Free(m_pBase)`: through `__imp_?Free@BoneRecordArray@SkeletonBuild@@UEAAXPEAX@Z`, and through slot 2 of the object's table | `DAT_010c4cec` by name, through a function type of one pointer |
| `~FUN_00cbadb0_Obj` and its deleting destructor | `blk_00ca0000_o2.cpp` | member call `releaseItem(m_items)` through slot 2 of the object's table | slot 2 of the object's table, through a function type of one pointer |
| `ArrayCBAF90::RemoveAll`, inlined into the deleting destructors of `ArrayCBAF90` and `FUN_00cbaf90`, into `~FUN_00cbaf90` and into `FUN_00cbb130` | `blk_00ca0000_o2.cpp` | member call `Deallocate(m_pBase)` through slot 2 of the object's table | the same |

- `TempArray`'s data is now a pointer, so its count and capacity are at 16
  and 20, as the bodies above read them, and its constructor clears all 16
  bytes after the table pointer. The unit includes `fnv/symbols_010c4000.h`
  again, and its own declarations of `DAT_010c4db8` and `DAT_010c4dc0` go.
  `actor.cpp`'s recipe key of the slot is respelled to
  `?DAT_010c4dc0@@3P6GXPAX@ZA`.
- `DAT_010c4cec` is declared in `fnv/symbols_010c4000.h` as `void *`, the
  type of its generated definition, and is called through a cast to a
  function of one pointer, as the destructors of the same table in
  `blk_00c60000_o2.cpp` call it. `actor.cpp`'s recipe key at `0x010c4cec`,
  `__imp_?Free@BoneRecordArray@SkeletonBuild@@UAEXPAX@Z`, is respelled to the
  slot's own name, `?DAT_010c4cec@@3PAXA`. The undefined name
  `__imp_?Free@BoneRecordArray@SkeletonBuild@@UEAAXPEAX@Z` leaves.
- In `blk_00ca0000_o2.cpp` the calls take the form `ReleaseAndDestroy`
  has used since VEGAS-102. The private struct `FUN_00cbadb0_Dispatch`,
  which only the call used, is removed.
- The classes keep their declared virtual functions, so the tables the
  compiler emits for them do not change; those tables still name the
  members `Free`, `releaseItem` and `Deallocate`, which stay undefined.

In each object only the arguments of these calls change, and the
registers and stack slots that follow from them; the per-function
comparison is kept with the review evidence. `TempArray` also moves its
count and capacity, as above.

### Open

The classes stay private copies in their units; none moves onto one shared
class.

- No shared declaration exists for any of the three. A shared header of a
  real polymorphic class declares every slot (the 2026-11-11 ruling), but
  slot 2 holds a function of one pointer, which a virtual member of the
  class cannot be on windows-x64. How such a class declares its table needs
  a ruling.
- A shared layout with 32-bit counts changes the code of the four
  destructors in `blk_00c60000_o2.cpp`, which store at 24. Until that is
  decided, calling `0x00c7a630` from `actor.cpp` in place of `TempArray`'s
  own destructor, which has no row, would store past the end of the 24-byte
  stack array.
- `AppendSlot` inlines `FUN_00c76180_cls::SetValue` (`0x00c76180`), whose
  class declares the data as a 32-bit `int` at 8.
- `CBADDynamicArray::FUN_00cbadf0` (`0x00cbadf0`) calls `CA0E60Array::Free`
  with the object and the buffer, and `FUN_00cb9d50` (`0x00cb9d50`) with the
  object as the array and the end of the buffer, converted to an integer, as
  the count; in the parent of `3f0599801` it passed the end and the number
  of new items. The second call is inlined as a fill of the object with zero
  bytes. The recipe maps no table to `CA0E60Array`, so whether its slot 2
  holds `0x00cb9cb0` is not established.

## ReleaseItems (VEGAS-106)

`ReleaseItems` (`0x00cba0d0`, `blk_00ca0000_o2.cpp`) releases each of
`count` items of an array: it decrements each item's reference count and
destroys the item through its table when the count reaches zero. Its recipe
row, `?ReleaseItems@@YAXPAPAVFUN_00cba0d0_cls@@I@Z`, and the declaration in
`fnv/symbols_00cba000.h` take the array and a 32-bit count, as its
definition did in the parent of `3f0599801`. Five calls passed the object
as the array and a pointer converted to an integer as the count, and
`1fbc6eb1f` widened the definition's count to `uintptr_t` to keep the
converted pointer's width:

| Caller | Passed in the parent of `3f0599801` |
| --- | --- |
| `FUN_00cbaec0_Obj::ReleaseAndDestroy` | the data and the size |
| `~FUN_00cbadb0_Obj` | the items and their count |
| `ArrayCBAF90::RemoveAll` | the data and the size |
| `CBADDynamicArray::FUN_00cbadf0`, emptying | the buffer and the size |
| `CBADDynamicArray::FUN_00cbadf0`, shrinking | the buffer from the new size, and the number of items past it |

Each call passes those again, the array converted to the parameter's type,
and the definition takes the row's 32-bit count, so it is defined under the
row's name. `ReleaseItems` is inlined into each caller; in the objects the
inlined loop now walks the array loaded from the object's data field, up to
the count loaded from the size field, where it walked the object itself up
to the data pointer's value.

## The checks

- `objects.table_slot_reads` runs `tools/function-relocations` with
  `table-slot-reads.tsv`. It fails when a repaired function addresses one of
  the four tables at or past 16 bytes, or no longer refers to the slot's
  name. It fails on the objects before the repairs. It also requires the
  one-pointer name of the slot of `FUN_00c7a690`.
- `objects.table_bounds` runs `tools/table-bounds`. It fails when any
  relocation of any object of the game archive addresses any of the 2,057
  tables at or past its end, or before it. Each table's length is its slot
  count in the source the build compiles. Its allow file lists no read. On
  the objects before the first four repairs it failed with six reads, the
  four functions and two unwind funclets of theirs, besides the read of
  `FUN_00c7a630` it then allowed. On the objects before `FUN_00c7a630`'s
  repair it now fails with that read.
- `objects.memory_free_forwarder` disassembles `0x00cb9cb0` from the
  archive. It fails when the body zeroes the free's pointer argument, or no
  longer moves its own argument into it, or when no member or more than one
  defines its name.
- `objects.release_and_destroy_slot_call` disassembles `0x00cbaec0` from
  the archive. It traces `rcx` at the slot call back to where it was set
  and fails unless that is the load of the data pointer at offset 8; the
  member call passed the object there and the data in `rdx`. It matches
  registers, not values. Until VEGAS-106 it matched the load into `rcx`
  itself.
- `objects.slot_free_calls` runs `tools/function-relocations` with
  `slot-free-calls.tsv`. It fails when a repaired function of `actor.cpp`
  refers to the old name of the slot it calls, or no longer to the slot's
  own name.
- `objects.slot_free_argument.*` traces `rcx` at each repaired call back
  to where it was set and fails unless that is the load of the data field:
  for `TempArray`'s destructor, the deleting destructor of
  `BoneRecordArray`, and the six functions of `blk_00ca0000_o2.cpp`.
- `objects.release_items_array.*` traces the array of each inlined loop of
  `ReleaseItems` back to the load of the data field, in the eight functions
  that inline it, and fails when it reaches the object or the address of a
  member. `objects.release_items_count` fails unless `ReleaseItems` is
  defined under the row's name and tests a 32-bit count.

The tracing checks run `tests/archive/expect_register_origin.cmake`. They
follow address order, not control flow, and do not check the count
`ReleaseItems` is given.

The first four ran in the windows-x64 cross build only; since VEGAS-95 they
run in the Windows CI job as well. The checks after them are registered
under the same condition. For the `REL32` types
the first two take the stored addend plus 4 as the offset used, because
the addend leaves out an immediate that follows the displacement. A relocation whose stored
addend lies in the last 4 bytes of a table therefore fails, although
without an immediate the read is inside the table.

## Per-table sections

The fifteen vtable units are compiled with `/Gw` in builds whose compiler
takes the MSVC command line, so each of their tables has a COMDAT data
section of its own and a link keeps only the tables something refers to.
The host build is unchanged. The bytes and relocations of every table are
unchanged; each table's section selection changes from a plain section to
`NoDuplicates`.

Measured at `e904ce163` on the windows-x64 cross build, for the first
fourteen units against the same build before the step: the forced link of
every member keeps its undefined and duplicate names, its members and the
members it loads from the runtime libraries, and loses 29 of 137 imports,
among them the registry, thread and profile string functions. Each was
reached only from tables that nothing refers to. The lazy links and today's
FalloutNV link are unchanged. In the function-level model of what a link
from WinMain keeps, the names left unresolved, with the projection of known
aliases, go from 22,987 to 21,486; from the main loop from 21,791 to 20,138;
and from the start menu from 20,425 to 18,627. The model's cut without any
vtable unit stays at 15,601 names.

`vtables_010c.cpp` took the option once `FUN_00c7a630` no longer read past
`DAT_010c4db8`. Measured on the cross build of that step against the build
before it, from one export of each commit on `c7abe570e`: its 318 tables keep their bytes
and relocations, 71 of them without the 8 bytes of zero padding that
followed them in the shared section. The forced link of every member keeps
its undefined and duplicate names and its members, and loses one of 114
imports, `SuspendThread`. The lazy links and today's FalloutNV link are
unchanged, and the links rooted at WinMain, the main loop and the start
menu load the same members and leave the same names undefined, with one
import fewer each. In the model, with the projection, the names left
unresolved go from 21,471 to 20,979 from WinMain, from 20,124 to 19,585
from the main loop and from 18,614 to 18,085 from the start menu. A few
names enter: 1 from WinMain and the main loop, 19 from the start menu. The
model takes a section of a name with differing definitions from a member
it reaches, and with fewer members reached it takes another member's copy,
which refers to names the earlier copy did not. The two traced cases are
the deleting destructor of `NiFloatInterpolator` and the table of
`hkpSymmetricAgentFlipCollector`. The real links load the same members in
the same order before and after, so the linker keeps the same copies. The
model's cut without any vtable unit stays at 15,586 names.

## What the scans do not see

- A call through a table pointer that is loaded from an object, when the
  same function did not store the table. Such a read has no relocation to
  the table, and which table the object holds is only known at run time.
  Objects that hold one of the six tables above can be read this way.
- Uses of a table that none of the source scan's patterns match, and flows
  of a table's address between files or through function arguments.
- A relocation to another name of the same storage, such as an
  `/alternatename` target.
- For the census of the callers of `0x00cb9cb0`: a call through offset 16
  of a table pointer in a function other than the one that stored the
  table, and a call through a copy of a slot's value.
