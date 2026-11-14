# Function relocations check

Checks, function by function, which names the code of a function refers to
in the windows-x64 object of its unit. For every function of a table it finds
the COMDAT code section that defines the function's name, counts that
section's relocations by target name, and fails when:

- the section has a relocation to a name the table forbids,
- the section has a relocation that addresses a name at or past the length
  the table gives that name, or before it, or
- the section has no relocation to a name the table requires of that function.

It looks at the function's own section, not at the whole object. An object
may keep a forbidden name in other functions.

It needs Go 1.24.11 or newer and no other module. It reads objects with the
standard library's `debug/pe`.

```text
go test -race ./...
go vet ./...
go run . --table d3dx-call-arguments.tsv --objects OBJECT_LIST [--batch NAME]
```

`OBJECT_LIST` is a file with one object path per line. Each function's object
is the one path that ends in `/UNIT.obj`, where `UNIT` is the table's unit,
such as `src/fallout_shared/teswater.cpp`.

## Where it runs

CTest runs it in every windows-x64 build, the cross build and the Windows CI
job's, like `archive.differing_definitions`: `objects.d3dx_call_arguments_BATCH`, one test
per batch of `d3dx-call-arguments.tsv`,
`objects.hacking_array_retirement` for `hacking-array-retirement.tsv`,
`objects.navmesh_pointer_result` for `navmesh-pointer-result.tsv`,
`objects.winmain_boot_calls` for `winmain-boot-calls.tsv`,
`objects.boot_call_repairs` for `boot-call-repairs.tsv`,
`objects.table_slot_reads` for `table-slot-reads.tsv`,
`objects.slot_free_calls` for `slot-free-calls.tsv`,
`objects.mask_constants`, one test for all of `mask-constants.tsv`,
`objects.integer_width_calls` for `integer-width-calls.tsv`,
`objects.log_path_buffer` for `log-path-buffer.tsv`,
`objects.setting_value_accessor_callers` for `setting-value-accessor.tsv`,
`objects.float_setting_accessor_callers` for `float-setting-accessor.tsv`,
`objects.setting_member_calls` for `setting-member-calls.tsv`,
`objects.batch_bindings` for `batch-bindings.tsv`, and
`objects.void_result_repairs` for `void-result-repairs.tsv`. CMake
writes the object list of the game archive to `game-objects.txt` in the
build's `tests` folder.

## The table

Tab-separated. Blank lines and lines that start with `#` are skipped.

```text
forbid<TAB>NAME
past<TAB>NAME<TAB>LENGTH
function<TAB>BATCH<TAB>UNIT<TAB>NAME<TAB>REQUIRED[ REQUIRED...]
```

Every `forbid` name is forbidden in every function. A `past` line gives a
name's length in bytes: in every function, each relocation to that name must
address it at an offset from 0 to below `LENGTH`. The offset is the addend
stored in the code at the relocation. For a `REL32` relocation the stored
addend leaves out the bytes of an immediate that follows the displacement,
up to 4, so the check takes the addend plus 4 as the highest offset used.
The same addend plus 4 is the offset it compares with 0: a read at offset 0
followed by an immediate is stored as an addend from -1 to -4 and passes. A
table needs at least one `forbid` or `past` line. `REQUIRED` names are
separated by spaces. A `REQUIRED` field of `-` requires no name.

`d3dx-call-arguments.tsv` lists the 12 functions whose calls of the D3DX
matrix inverse (`0x00ee6dda`), transpose (`0x00ee6dd4`) and vector normal
transform (`0x00ee6df2`) got their arguments back (VEGAS-90). It forbids the
three argument-less names and requires the native names each function calls.
`0x00bbef90` stands for the frustum update that it inlines. With the unit's
own flags the optimizer may merge equal calls, so the check counts names, not
calls.

`hacking-array-retirement.tsv` lists the function at `0x007687d0`, which
deletes the hacking menu's array of `HackingArrayElement` (VEGAS-72). It
forbids the transcribed vector deleting destructor at `0x007021b0` and the
three names its array path calls, and requires the element's destructor and
the sized array delete, which `delete[]` of the element type calls. The count
before the array, the element size and the size passed to the array delete
are not relocations; docs/hacking-element-release.md records them from the
instructions.

`navmesh-pointer-result.tsv` lists the function at `0x005436e0` in
`tesobjectcell.cpp`, which calls `MakeNavMeshPointer` (`0x00464fc0`)
(VEGAS-96). It requires that name and the destructor of the
`NiPointer<NavMesh>` it returns. A caller that sees that class as trivial
never calls the destructor, and on windows-x64 it is also the caller that
expects the result in a register instead of passing its address: a class with
a destructor of its own is always returned through that address. The table
forbids the name under which the unit's recipe symbols name the callee, with
a `NavMeshPtr` result; no object defines it. Which register carries which
argument is not a relocation; docs/navmesh-pointer-result.md records it from
the instructions.

`winmain-boot-calls.tsv` lists WinMain (`0x0086a850`) in
`src/fallout/misc/main.cpp`, whose calls of boot functions are bound by name
to the bodies at the recipe's rows (VEGAS-30). It forbids each name a call
used before, which no object defines, and requires the name of the body.
Its batch `callees` lists five more functions of the same unit on the boot
path, bound the same way (docs/winmain-boot-names.md).

`boot-call-repairs.tsv` lists the functions on the boot path whose calls were
repaired to match the body at the recipe's row and then bound to it by name
(VEGAS-90, VEGAS-30, docs/winmain-boot-names.md). It forbids each name a call
used before, which no object defines, and requires the name of the body.
Batch `definition` holds the two definitions whose texture parameter was an
integer (VEGAS-97), which must be defined under their recipe rows' names; it
forbids their former names. With the unit's flags the callers inline
`0x00876830`, so no call of it is a relocation there.

`table-slot-reads.tsv` lists the functions that read the slot after the end
of a two-slot generated table (VEGAS-30, docs/table-slot-reads.md). Each read
16 bytes past the start of the table: the windows-x64 view of the original's
slot 8 bytes past it, which the recipe names on its own and generated data
defines as its own variable, or, for `DAT_010c4dc0`, `blk_00c60000_o2.cpp`.
The table gives each generated table's length in a `past` line, so a listed
function that again addresses one at or past its end fails, and requires
the name of the slot that the function now calls through. The function still
stores the table's address, so the table's name is not forbidden. It also
lists `FUN_00c7a690`, which never read past its table, and requires the
one-pointer name of the slot it calls.

`slot-free-calls.tsv` lists the functions of `actor.cpp` that free an
array's data through the slot after a generated table, which holds
`0x00cb9cb0`, a function of one pointer (VEGAS-103,
docs/table-slot-reads.md). It forbids the names under which they called the
slot with the object and the data, which no object defines, and requires the
name of the slot they now call through.

`mask-constants.tsv` lists the 18 functions whose numeric masks, flags,
counts and limits were spelled as the addresses of data names (VEGAS-93,
docs/mask-constants.md). It forbids the six names and requires none.

`integer-width-calls.tsv` lists the functions that call or take the address
of a function whose caller and callee disagreed on an integer width only
(VEGAS-97, docs/integer-width-calls.md). Batch `requirer` holds the calls
whose declaration took the callee's width: it forbids each declaration's
former name and requires the definition's. Batch `definition` holds the two
definitions that took their callers' width, which must be defined under the
agreed name, and the functions that call them. Whether a caller passes a
32-bit variable through a widened declaration is not a relocation; the
document lists the names held back for that reason.

`log-path-buffer.tsv` lists the seven functions that read or write the user
folder buffer at `0x01202fa0` (VEGAS-109): WinMain's four log-path builders,
the function at `0x004dc110` that returns the buffer, and the two functions
that build the Controls INI path. The buffer was defined as an 8-byte pointer:
three of them passed its null value to `strcpy_s` as the source, and the
others read or returned the 8-byte object as the buffer. The table forbids
the pointer's name, gives the buffer's 260 bytes in a `past` line and
requires the buffer's name. Whether a function passes the buffer's address
or a value loaded from it is not told apart by a relocation; with the buffer
declared as an array of 260 characters, a loaded value would need a cast.
A smaller array under the same name is not caught by
`objects.log_path_buffer`; the `static_assert` in `FUN_004dc110` covers the
size of the buffer's definition.

`setting-value-accessor.tsv` lists a sample of the callers of the setting
value accessor at `0x0043d4d0` (VEGAS-111, docs/setting-value-offset.md). It
forbids the accessor's 32-bit form, which took an `int *` and read 4 bytes
into the setting and which no object defines, and requires the form that
takes the shared `Setting`. The sample holds three readers of the processor
count setting and one caller for each other form of argument. Its batch
`main` lists the 14 functions of `src/fallout/misc/main.cpp` that call the
accessor (VEGAS-115). The batches `beamprojectile`, `computersmenu`,
`explosion`, `package`, `interface`, `tesscriptfunctions`, `renderer` and
`bstempeffectsimpledecal`
list the functions of those units whose calls moved once the unit's own
`Setting` went (VEGAS-117). Whether an argument is a setting is
not a relocation;
the document classifies every call.

`float-setting-accessor.tsv` does the same for the float setting accessor
at `0x00403e20` (VEGAS-116, docs/setting-value-offset.md). It forbids the
form that took a `float *`, which no object defines, and requires the form
that takes the shared `Setting`. The sample holds three readers of the HUD
opacity setting and one caller for each other form of argument. Its batch
`main` lists the four functions of `src/fallout/misc/main.cpp` that call the
accessor (VEGAS-122). The batches `blk_00940000_od`, `bgsterminal`,
`sleepwaitmenu`, `magicfogprojectile`, `explosion`, `character`,
`itemmodmenu`, `combatcontroller`, `package`, `telekinesiseffect` and
`interface` do the same for those units (VEGAS-122).

`setting-member-calls.tsv` lists the functions whose call of a member of
the unit's own `Setting` now calls `SettingT<INISettingCollection>::Bool`,
the recipe's row at `0x00408d60` (VEGAS-117,
docs/setting-value-offset.md). It forbids the copy's member, which no
object defines, and requires the row's member. The receiver is a
generated setting derived from that class at offset 0; which member of
the result the caller reads is not a relocation.

`batch-bindings.tsv` lists the functions whose calls `tools/bind-batch` bound
to the body at the recipe's row (VEGAS-125, docs/symbol-naming-batches.md).
`bind_batch.py apply` writes it: a `forbid` line for each stand-in name once
every call of it is bound, which no object defines, and a `function` line
requiring the row owner's name of each function that held a bound call at
the unit's flags, as the object proof's retargets list it. The receiver of
each retargeted cast stays open.

`void-result-repairs.tsv` lists the bodies that returned `void` while
every caller that uses the result declares the type of the value the body
computed and dropped, and that now return it (VEGAS-124,
docs/void-result-bodies.md). Each must be defined under its recipe row's
name, which now carries the result; the table forbids the former `void`
name, which no object defines. Which value a body leaves in the return
register is not a relocation; the object proof of each repair shows it.

## Exit status

| Status | Meaning |
| --- | --- |
| 0 | Every function of the batch passes. Each prints an `ok` line. |
| 1 | A function fails. It prints a `FAIL` line with each forbidden name's relocation count, each relocation that reaches past a name's length with its addend, and each missing required name. |
| 2 | The check could not be completed: bad arguments or table; no batch function; a unit with no object or several; an object that is not an x64 COFF object; a function name that is not defined, defined twice, or not in a COMDAT code section; a section whose relocation count overflows; a relocation to a `past` name of a type whose addend the command does not read (it reads `ADDR64`, `ADDR32`, `ADDR32NB` and the `REL32` types). |

## What it does not see

- Calls through a pointer. They have no relocation to the callee's name.
- A read of a `past` name through a pointer loaded from memory, such as a
  call through an object's table pointer. It has no relocation to the name.
- How many calls a relocation stands for, and what their arguments are. The
  arguments were checked at source and in objects built with `/Od /Ob0`
  (docs/d3dx-replacement.md).
- Unwind records and other sections associated with the function.
- A call through another argument-less declaration of the same address under a
  different mangled name (another namespace or signature). Only the three
  global names in the table are forbidden.
- A restored call deleted outright while the function keeps another call to the
  required native name. The check counts names, not calls, so exact relocation
  counts are not compared (the optimizer merges calls).
