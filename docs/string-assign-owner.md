# One provider of the old string assign

`std::basic_string<char>::assign(const char*, unsigned int)` had two
definitions in the game archive. It now has one. No repair-family ticket names
this symbol. The removed copy is in a unit of VEGAS-22, the kept one in a unit
of VEGAS-18, and what the function finally becomes belongs to VEGAS-23 and
VEGAS-73. This change is the bounded removal of the copy the recipe does not
own. Everything else is listed under "Not covered".

## What the name is

It is not the toolchain's string. The toolchain's `assign` takes a
`size_t` count and has a different symbol. This name, with an `unsigned int`
count, exists only where a unit declares its own `basic_string` inside
`namespace std` to stand for the string class of the original release's
runtime library. Two units did that and each defined the member:

| Unit | Its declaration | Its definition |
| --- | --- | --- |
| `src/fallout_shared/modelloader_h_unit.cpp`, through `modelloader.h` | 24 opaque bytes, then the capacity | an explicit specialization with the address tag; an ordinary function |
| `src/unmapped/cuassembler.cpp` | an allocator member, the 16-byte buffer union, the size, the reserve | written inside the class; an inline function |

Both are project code bound by the recipe to the same runtime-library address.
Neither is replaced by the toolchain's string here, and neither is joined to
the native string owner of `docs/native-string-lifecycle.md`. That owner is
the class `FUN_0044a4c0`, and neither the recipe nor that document binds this
name to it.

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
| `src/bsmenu/tileimage.cpp` | symbol | this name | does not emit it |
| `src/fallout_shared/tesobject.cpp` | symbol | `FUN_0044a7f0_sub::FUN_0044a7f0(const void*, unsigned int)` | requires it, six relocations in five functions; no definition |
| `src/speedtree/speedtreert.cpp` | symbol | `std_string::assign(const char*, unsigned int)` | requires it; no definition |
| `src/staging/blk_00440000_od.cpp` | symbol | the same member of `fnv_0044a640::std::basic_string<char>` | requires it; no definition |
| `src/staging/blk_00ac0000_od.cpp` | symbol | `Ac6510Target::FUN_0044a7f0(char*, int)` | requires it; no definition |

`tileimage.cpp` includes the toolchain's string. Its object defines the
toolchain's `assign` with a `size_t` count, a different symbol, and names
this one nowhere.

One more name carries the address in its spelling without a recipe row:
`blk_00ac0000_od.cpp.obj` requires
`FnvString::FUN_0044a7f0(const char*, unsigned int)`, which has no definition.
None of these other names is changed here.

## Requirers

Among the 2,223 archive members and every test object of the windows-x64
build, two objects name the function.

| Object | Before | Now |
| --- | --- | --- |
| `modelloader_h_unit.cpp.obj` | defines, 124 bytes, no duplicate allowed; no call of its own | the same |
| `cuassembler.cpp.obj` | defines, 213 bytes, select-any; one call, in `0x00ac6540` | requires; the same call |

The fourteen cases of `0x00ac6540` share that one call instruction. Its two
appends go to `StrA::FUN_00a0c430`, before and after.

So there was one ordinary definition and one select-any definition with
different content under the name. There is one ordinary definition now and no
inline body.

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

## The two bodies

They are the same code on the original release's fixed offsets. Laid out at
32-bit widths both declarations are 28 bytes with the reserve at `+0x18`.
Built for windows-x64 they differ in where the reserve is read.

| | Declaration | Buffer | Size | Reserve |
| --- | --- | --- | --- | --- |
| removed body, `cuassembler.cpp` | `0x20` bytes | `+0x08` | `+0x18` | `+0x1c` |
| kept body, `modelloader.h` | `0x1c` bytes | not declared | not declared | `+0x18` |

The removed body did the inside test, the growth test, the copy and the
ending in line. It read the size at `+0x18` and the reserve at `+0x1c`, wrote
the size at `+0x18` and the terminator, and called `memcpy_s`,
`FUN_0044a970_Cls::FUN_0044a970()`, `_Copy`, `_Xlen` and the three-argument
`assign`.

The kept body's only access to the string is one 4-byte read at `+0x18`,
which it passes as the destination size of the copy. It writes nothing
itself. Everything else is a call: `_Inside`, `FUN_0044a970_Cls::FUN_0044a970()`,
the three-argument `assign`, `FUN_0044a8d0_Class::FUN_0044a8d0`,
`FUN_0044ccd0` and `_Eos`. Its read fits both declarations.

## The kept body is not correct on windows-x64

The kept body is the recipe's function, so it is the one that stays. It has a
defect that is recorded here and not repaired.

Its declaration is the original release's 28-byte layout written as bytes.
The buffer union holds a pointer, so on windows-x64 the fields after it move
by four bytes, and `+0x18` is no longer the reserve. The helpers it calls
were measured on their rebuilt objects:

| Helper | Unit | What it reads on windows-x64 |
| --- | --- | --- |
| `FUN_0044a970_Cls::FUN_0044a970()`, the buffer pointer | `blk_00440000_od.cpp` | reserve at `+0x1c`, pointer at `+0x08` |
| `FUN_0044a8d0_Class::FUN_0044a8d0`, the growth | `tesobject.cpp` | compares the count with `+0x18`; also reads `+0x14` and `+0x20` |

So the kept body passes as the copy's destination size the field that its own
buffer-pointer helper treats as the size, and its growth helper uses a third
layout. For a string as `cuassembler.cpp` declares it, the destination size
passed is the current length, not the reserve.

Before this change the forced link of the whole archive already bound the
call in `0x00ac6540` to this body. The defect is therefore not new on any
path. It stays because the layout of this string on windows-x64 is not
established: three declarations disagree and nothing constructs one.

## Storage

`0x0044a7f0` is not a constructor and the kept body writes nothing to the
string itself. Nothing in the archive constructs the string that `0x00ac6540`
receives: the function takes it by reference, no object calls the function
under its defined name, and the declaration in `cuassembler.cpp` has no
constructor. So there is no allocation to compare with a write extent.

## Programs

No program that links today contains either object.

- The game executable, which loads archive members on demand, loads neither
  object, before or after. Its lists are unchanged and its map is identical
  below the header.
- Of the 55 test programs, 54 link and none of them contains either object.
  The table of test links is identical before and after.
- The worker-pool test does not link. Forced, its image contains
  `modelloader_h_unit.cpp.obj` and not `cuassembler.cpp.obj`, before and
  after, and its list of undefined names is unchanged.

## Link lists

`cuassembler.cpp.obj` no longer requires `_Copy(unsigned int, unsigned int)`,
`_Xlen()`, the three-argument `assign`, `FUN_0044a970_Cls::FUN_0044a970()` or
`memcpy_s`. Nothing else required the first two, so the forced link of the
whole archive lists two undefined names fewer and adds none. The
three-argument `assign` is still required by the kept body.

## Not covered

These were open before this change and remain open.

- The defect of the kept body, as measured above.
- One declaration of this string. `modelloader.h`, `cuassembler.cpp`,
  `blk_00440000_od.cpp` and `tesobject.cpp` each give it a different
  windows-x64 layout. Which one a constructed string has is not established,
  because nothing constructs one.
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
- The toolchain's string in `tileimage.cpp` against its recipe row.
- No test executes the function.

No archive member is added, removed or reordered. `build/units.json` is
unchanged: no name in it changed.
