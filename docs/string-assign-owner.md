# One provider of the old string assign

`std::basic_string<char>::assign(const char*, unsigned int)` had two
definitions in the game archive. It now has one. No repair-family ticket names
this symbol. The removed copy is in a unit of VEGAS-22, the kept one in a unit
of VEGAS-18, and what the function finally becomes belongs to VEGAS-23 and
VEGAS-73. This change is the bounded removal of the copy the recipe does not
own. Everything else is listed under "Not covered".

## What the name is

It is not the toolchain's string. The toolchain's `assign` takes a
`const char* const` and a `size_t` count and has a different symbol. No
archive member defines or requires that symbol.

This member exists only where a unit declares its own `basic_string` inside
`namespace std` to stand for the string class of the original release's
runtime library. Three units do that and each defined the member:

| Unit | Its declaration | Its definition | Count type on windows-x64 |
| --- | --- | --- | --- |
| `src/fallout_shared/modelloader_h_unit.cpp`, through `modelloader.h` | 24 opaque bytes, then the capacity | an explicit specialization with the address tag; an ordinary function | `unsigned int` |
| `src/unmapped/cuassembler.cpp` | an allocator member, the 16-byte buffer union, the size, the reserve | written inside the class; an inline function; removed here | `unsigned int` |
| `src/bsmenu/tileimage.cpp`, lines 1012 to 1403 | the 16-byte buffer union, the size, the reserve, with `size_t` as the size type | written inside the class; an inline function; not removed | `unsigned __int64` |

At 32-bit widths all three spell the count `unsigned int` and have the one
name the recipe lists. On windows-x64 the first two keep the `unsigned int`
name, which is the duplicate this change removes. `tileimage.cpp` gets a
different mangled name, so no link reports it.

All three are project code bound by the recipe to the same runtime-library
address. None is replaced by the toolchain's string here, and none is joined
to the native string owner of `docs/native-string-lifecycle.md`. That owner
is the class `FUN_0044a4c0`, and neither the recipe nor that document binds
this name to it.

So the recipe function `0x0044a7f0` was transcribed three times. This change
removes one transcription. The function still has two bodies in the archive,
under two names.

## The function

The function is at `0x0044a7f0`. `build/units.json` lists it once as a
function, 132 bytes, in the unit `src/fallout_shared/modelloader_h_unit.cpp`,
beside `0x0043fdf0` and `0x00712380`. That definition carries the address tag.

When the source pointer lies inside the string it forwards to the three
argument `assign`. Otherwise it grows the string to the count, copies the
characters and ends the string.

## The removed definition

The recipe gives `src/unmapped/cuassembler.cpp` one function, `0x00ac6540`.
The unit's symbol table binds this name to `0x0044a7f0`, as a name the unit
requires. Its inline body had no address tag. It was the same function
written a second time, not a second function. It is removed. The class keeps a
declaration, as it already did for the three-argument `assign`.

The recipe records no call edges. That the function at `0x00ac6540` calls
`0x0044a7f0` is inferred from the unit's symbol row for the name and from the
body tagged `0x00ac6540`, which assigns a literal in each of its fourteen
cases.

## Names the recipe binds to the address

| Recipe unit | Row | Name | Windows-x64 object |
| --- | --- | --- | --- |
| `modelloader_h_unit.cpp` | function, 132 bytes | this name | defines it |
| `cuassembler.cpp` | symbol | this name | defined it before; requires it now |
| `src/bsmenu/tileimage.cpp` | symbol | this name | does not emit this name; defines the same member with an `unsigned __int64` count |
| `src/fallout_shared/tesobject.cpp` | symbol | `FUN_0044a7f0_sub::FUN_0044a7f0(const void*, unsigned int)` | requires it, six relocations in five functions; no definition |
| `src/speedtree/speedtreert.cpp` | symbol | `std_string::assign(const char*, unsigned int)` | requires it; no definition |
| `src/staging/blk_00440000_od.cpp` | symbol | the same member of `fnv_0044a640::std::basic_string<char>` | requires it; no definition |
| `src/staging/blk_00ac0000_od.cpp` | symbol | `Ac6510Target::FUN_0044a7f0(char*, int)` | requires it; no definition |

`tileimage.cpp` does not include the toolchain's string. It declares its own
class, as above. Its object defines `assign(const char*, unsigned __int64)`:
select-any, 349 bytes, a different mangled name from this one and from the
toolchain's. It names the `unsigned int` name nowhere. One function of that
object, `FUN_00a06dd0`, calls its own copy; no other object requires it.

One more name carries the address in its spelling without a recipe row:
`blk_00ac0000_od.cpp.obj` requires
`FnvString::FUN_0044a7f0(const char*, unsigned int)`, which has no definition.
None of these other names is changed here.

## Requirers

Among the 2,223 archive members and every test object of the windows-x64
build, two objects name the function by this name.

| Object | Before | Now |
| --- | --- | --- |
| `modelloader_h_unit.cpp.obj` | defines, 124 bytes, no duplicate allowed; no call of its own | the same |
| `cuassembler.cpp.obj` | defines, 213 bytes, select-any; one call, in `0x00ac6540` | requires; the same call |

The fourteen cases of `0x00ac6540` share that one call instruction. Its two
appends go to `StrA::FUN_00a0c430`, before and after.

So there was one ordinary definition and one select-any definition with
different content under the name. There is one ordinary definition now and no
inline body under this name. The inline body of `tileimage.cpp` remains under
its own name.

No object requires `0x00ac6540` under the name the unit defines.
`blk_00ac0000_od.cpp.obj` requires that address as `FUN_00ac6540(Str*)`, a
different name with no definition. No generated data names `0x0044a7f0` or
`0x00ac6540`.

## Which body the call reached, and reaches now

Measured from maps of forced links with every section kept.

| Link | Before | Now |
| --- | --- | --- |
| whole archive, forced | `modelloader_h_unit.cpp.obj`, the member loaded first | the same |
| worker-pool test, forced | `modelloader_h_unit.cpp.obj`; `cuassembler.cpp.obj` is not loaded | the same |

So no image that could be produced before changes which body the call
reaches. What changes is a link that loads `cuassembler.cpp.obj` without
forcing: it used to take that object's own inline copy and now takes the
recipe's function. No such link exists today; see "Programs".

## The three bodies

They are the same code on the original release's fixed offsets. Laid out at
32-bit widths all three declarations are 28 bytes with the reserve at
`+0x18`. Built for windows-x64 they differ in where the reserve is read.

| | Declaration | Buffer | Size | Reserve |
| --- | --- | --- | --- | --- |
| removed body, `cuassembler.cpp` | `0x20` bytes | `+0x08` | `+0x18`, 4 bytes | `+0x1c`, 4 bytes |
| kept body, `modelloader.h` | `0x1c` bytes | not declared | not declared | `+0x18`, 4 bytes |
| body left in `tileimage.cpp` | `0x28` bytes | `+0x08` | `+0x18`, 8 bytes | `+0x20`, 8 bytes |

The removed body did the inside test, the growth test, the copy and the
ending in line. It read the size at `+0x18` and the reserve at `+0x1c`, wrote
the size at `+0x18` and the terminator, and called `memcpy_s`,
`FUN_0044a970_Cls::FUN_0044a970()`, `_Copy`, `_Xlen` and the three-argument
`assign`.

The kept body's only access to the string is one 4-byte read at `+0x18`,
which it passes as the destination size of the copy. It writes nothing
itself. Everything else is a call: `_Inside`, `FUN_0044a970_Cls::FUN_0044a970()`,
the three-argument `assign`, `FUN_0044a8d0_Class::FUN_0044a8d0`,
`FUN_0044ccd0` and `_Eos`. Its read fits all three declarations.

The body left in `tileimage.cpp` reads the size at `+0x18` and the reserve at
`+0x20` as 8-byte fields and writes the size at `+0x18`. It calls
`FUN_0044a970_Cls::FUN_0044a970()` seven times, the function at `0x0044a970`,
which reads a 4-byte reserve at `+0x1c`.

## The kept body is not correct on windows-x64

The kept body is the recipe's function, so it is the one that stays. It has a
defect that is recorded here and not repaired.

Its declaration is the original release's 28-byte layout written as bytes.
Inference: the buffer union holds a pointer, so on windows-x64 the fields
after it move by four bytes, and `+0x18` is no longer the reserve. This is
inferred from the declarations that name the fields. It is not read from a
constructed string, because nothing constructs one.

The recipe functions of this class use three reserve offsets on windows-x64.
Each was measured on its rebuilt object:

| Reserve read at | Recipe function | Unit | What else it touches |
| --- | --- | --- | --- |
| `+0x18` | `0x0044a7f0`, the kept owner | `modelloader_h_unit.cpp` | nothing |
| `+0x18` | `0x0044a8d0`, the growth helper | `tesobject.cpp` | compares the count with `+0x18`; reads the size at raw `+0x14`; on its trim branch reads `+0x20` and the pointer at `+0x08` and stores 4 bytes at `+0x20` |
| `+0x1c` | `0x0044a970`, the buffer-pointer helper | `blk_00440000_od.cpp` | pointer at `+0x08` |
| `+0x1c` | `0x0044ab90`, the inside test | `blk_00440000_od.cpp` | pointer at `+0x08`, size at `+0x18` |
| `+0x1c` | the removed copy | `cuassembler.cpp` | size at `+0x18` |
| `+0x20` | `0x0044aa10`, the buffer resize | `tesobject.cpp` | stores the pointer at `+0x08` and 4 bytes at `+0x20` |
| `+0x20` | `0x0044a730`, the tidy | `tesobject.cpp` | pointer at `+0x08`; stores 4 bytes at `+0x20` |
| `+0x20` | `0x0044a580`, the three-argument assign | `tesobject.cpp` | nothing else of its own |

The kept owner calls helpers from two of these groups under names that have a
definition: `0x0044a8d0` from the first and `0x0044a970` from the second. Its
symbol rows bind `_Inside` to `0x0044ab90`, in the second group, and the
three-argument `assign` to `0x0044a580`, in the third; neither has a
definition under the name the kept body requires. So no single layout is
established.

The kept body passes as the copy's destination size the field that its own
buffer-pointer helper treats as the size. For a string as `cuassembler.cpp`
declares it, the destination size passed is the current length, not the
reserve.

Before this change the forced link of the whole archive already bound the
call in `0x00ac6540` to this body. The defect is therefore not new on any
path. It stays because the layout of this string on windows-x64 is not
established: the declarations disagree and nothing constructs one.

## Storage

`0x0044a7f0` is not a constructor and the kept body writes nothing to the
string itself. Its callees write, as measured on their rebuilt objects:

| Callee | Store | Against the `0x1c`-byte and `0x20`-byte declarations |
| --- | --- | --- |
| `0x0044a8d0`, own body, trim branch | 4 bytes at `+0x20` | past the end of both |
| `0x0044aa10`, called by `0x0044a8d0` on its grow branch | 4 bytes at `+0x20`, 8 bytes at `+0x08` | the first is past the end of both |
| `0x0044a880`, the ending, bound to `_Eos` by the recipe | 4 bytes at `+0x14` | inside both; inside the buffer union of the `0x20`-byte one |

The kept body calls `0x0044a8d0` with the trim flag false, so of these its
call reaches the grow branch. This is unchanged from 39c4fbb99: no helper is
edited here.

Nothing in the archive constructs the string that `0x00ac6540` receives: the
function takes it by reference, no object calls the function under its
defined name, and the declaration in `cuassembler.cpp` has no constructor. So
there is no allocation to compare these stores with.

## Programs

No program that links today contains either object, or `tileimage.cpp.obj`.

- The game executable, which loads archive members on demand, loads neither
  object, before or after. Its lists are unchanged and its map is identical
  below the header.
- Of the 55 test programs, 54 link and none of them contains either object.
  The table of test links is identical before and after.
- The worker-pool test does not link. Forced, its image contains
  `modelloader_h_unit.cpp.obj` and not `cuassembler.cpp.obj`, before and
  after, and its list of undefined names is unchanged. It also contains
  `tileimage.cpp.obj`, so that image holds both bodies of `0x0044a7f0`.

## Link lists

`cuassembler.cpp.obj` no longer requires `_Copy(unsigned int, unsigned int)`,
`_Xlen()`, the three-argument `assign`, `FUN_0044a970_Cls::FUN_0044a970()` or
`memcpy_s`. Nothing else required the first two, so the forced link of the
whole archive lists two undefined names fewer and adds none. The
three-argument `assign` is still required by the kept body.

## Not covered

These were open before this change and remain open.

- The defect of the kept body, as measured above.
- One declaration of this string. The declarations give four windows-x64
  layouts:

  | Declaration | Size | Buffer | Size field | Reserve |
  | --- | --- | --- | --- | --- |
  | `modelloader.h` | `0x1c` | not declared | not declared | `+0x18` |
  | `cuassembler.cpp`, and `FUN_0044a970_Cls` in `blk_00440000_od.cpp` | `0x20` | `+0x08` | `+0x18` | `+0x1c` |
  | `GrowString` in `tesobject.cpp` | `0x28` | `+0x08` | `+0x1c` | `+0x20` |
  | `tileimage.cpp` | `0x28` | `+0x08` | `+0x18`, 8 bytes | `+0x20`, 8 bytes |

  `cuassembler.cpp` and `FUN_0044a970_Cls` agree. The class of `0x0044a730`
  in `tesobject.cpp` has the size and reserve offset of `GrowString`.
  `tesobject.cpp` also reaches the string through raw offsets in
  `0x0044a8d0`, `+0x14` and `+0x18`, which are not those of `GrowString`.
  Which layout a constructed string has is not established, because nothing
  constructs one.
- The third transcription of `0x0044a7f0`, in `tileimage.cpp`. It is not
  removed here. With it the unit also defines the three-argument `assign` in
  line, 363 bytes, select-any, which its symbol row binds to `0x0044a580`, a
  function `tesobject.cpp` owns.
- The kept body's callees `_Inside`, `_Eos` and the three-argument `assign`
  have no definition under this class's name. A program that contains the
  function does not link without forcing.
- The other names for `0x0044a7f0` in the table above, and
  `FnvString::FUN_0044a7f0`. Each is required and none is defined. Whether
  they join this function or the native string owner is VEGAS-73 and VEGAS-23
  work.
- The members that `cuassembler.cpp` still defines in line and that nothing
  in the unit uses now: the two-argument `append`, `_Grow`, `_Inside`, `_Eos`
  and `max_size`. They emit nothing and are left as they were.
- `0x00ac6540` under its other name, `FUN_00ac6540(Str*)`.
- The own string class of `tileimage.cpp` against its recipe rows, as above.
- No test executes the function.

No archive member is added, removed or reordered. `build/units.json` is
unchanged: no name in it changed.
