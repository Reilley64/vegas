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
linker places next. This page records how such reads were found, which were
repaired, the one that stays open, the check that keeps them out, and the
per-table sections step.

## Why the tables are short

The generator ended each table at the next address that the recipe,
`build/units.json`, names. For six tables that address is the table's next
slot. The recipe names it on its own as a function pointer:

| Table | Slots | The slot after it |
| --- | --- | --- |
| `DAT_010c4db8` | 2 | `DAT_010c4dc0`, no definition |
| `DAT_010c53b4` | 2 | `DAT_010c53bc` |
| `DAT_010c7310` | 2 | `DAT_010c7318` |
| `DAT_010c8d00` | 2 | `DAT_010c8d08` |
| `DAT_010c8d14` | 2 | `DAT_010c8d1c` |
| `DAT_010cf9c8` | 3 | `DAT_010cf9d4` |

Generated data defines each slot name but `DAT_010c4dc0` as its own variable,
holding the function the original's slot holds. The code that uses
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
two-slot table since the first transcription. The open place,
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

### Remainder: `0x00cb9cb0` frees nothing (VEGAS-102)

The windows-x64 body of `0x00cb9cb0`, `fnv_00cb9cb0::FUN_00cb9cb0` in
`blk_00ca0000_o2.cpp`, takes no parameter and passes a null pointer to the
memory manager's free. Every caller of the slots that hold it therefore
leaks the pointer it means to free, the repaired ones included. The repairs
do not change that; VEGAS-102 tracks it.

## Open: `FUN_00c7a630`

`FUN_00c7a630` in `src/staging/blk_00c60000_o2.cpp` still calls through the
slot 16 bytes past the start of `DAT_010c4db8`. In the object that reads
slot 0 of the next table, `FUN_00c7e970` of `Outer`. The original's slot is
`0x010c4dc0`. By coordinator ruling (R2) the call is not repaired with a
cast; the declaration of `DAT_010c4dc0` must be settled first:

- The recipe spells the slot `?DAT_010c4dc0@@3P6EXPAUTempArray@@I@ZA`: a
  `__thiscall` function of a `TempArray *` and an `unsigned int`. Its
  siblings above are `__stdcall` functions of one pointer. `FUN_00c7a630`
  and its neighbour `FUN_00c7a690`, which calls `DAT_010c4dc0` through a cast
  to `void (*)(void *)`, pass one pointer.
- No unit defines `DAT_010c4dc0`. Generated data has no variable for it.
- `actor.cpp` declares `TempArray` with 32-bit `unsigned int` fields, and its
  destructor, which has no recipe row, stores `DAT_010c4db8` and frees its
  data through `DAT_010c4dc0(this, data)`: the shape of `0x00c7a630`. It is
  likely a stale 32-bit second transcription of that function, and the
  source of the `TempArray` spelling.

`tools/table-bounds/allow.tsv` lists this read, so the standing check below
passes with it, and `vtables_010c.cpp` stays out of the per-table sections
step until it is repaired.

## The checks

- `objects.table_slot_reads` runs `tools/function-relocations` with
  `table-slot-reads.tsv`. It fails when a repaired function addresses one of
  the three tables at or past 16 bytes, or no longer refers to the slot's
  name. It fails on the objects before the repairs.
- `objects.table_bounds` runs `tools/table-bounds`. It fails when any
  relocation of any object of the game archive addresses any of the 2,057
  tables at or past its end, or before it, other than the read of
  `FUN_00c7a630` above, or when that read is gone. Each table's length is
  its slot count in the source the build compiles. On the objects before
  the repairs it fails with six reads: the four functions and two unwind
  funclets of theirs.

Both run in the windows-x64 cross build only. For the `REL32` types both
take the stored addend plus 4 as the offset used, because the addend leaves
out an immediate that follows the displacement. A relocation whose stored
addend lies in the last 4 bytes of a table therefore fails, although
without an immediate the read is inside the table.

## Per-table sections

Fourteen of the fifteen vtable units are compiled with `/Gw` in builds whose
compiler takes the MSVC command line, so each of their tables has a COMDAT
data section of its own and a link keeps only the tables something refers
to. `vtables_010c.cpp`, which holds `DAT_010c4db8`, keeps one section for
its tables until `FUN_00c7a630` is repaired. The host build is unchanged.
The bytes and relocations of every table are unchanged; each table's
section selection changes from a plain section to `NoDuplicates`.

Measured at `e904ce163` on the windows-x64 cross build, against the same
build before the step: the forced link of every member keeps its
undefined and duplicate names, its members and the members it loads from
the runtime libraries, and loses 29 of 137 imports, among them the
registry, thread and profile string functions. Each was reached only from
tables that nothing refers to. The lazy links and today's FalloutNV link
are unchanged. In the function-level model of what a link from WinMain
keeps, the names left unresolved, with the projection of known aliases,
go from 22,987 to 21,486; from the main loop from 21,791 to 20,138; and
from the start menu from 20,425 to 18,627. The model's cut without any
vtable unit stays at 15,601 names.

## What the scans do not see

- A call through a table pointer that is loaded from an object, when the
  same function did not store the table. Such a read has no relocation to
  the table, and which table the object holds is only known at run time.
  Objects that hold one of the six tables above can be read this way.
- Uses of a table that none of the source scan's patterns match, and flows
  of a table's address between files or through function arguments.
- A relocation to another name of the same storage, such as an
  `/alternatename` target.
