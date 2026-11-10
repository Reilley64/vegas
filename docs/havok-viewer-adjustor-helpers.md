# Two Havok adjustor helpers under their own names

VEGAS-80 asks for distinct identities for two Havok helper constructors and
for five other clients to construct their real types. This change is the
bounded first part: the two helpers no longer share the global name
`SpawnedObject`. The five clients are not repaired; see "Not covered".

## The shared name

Seven different functions used the one name `SpawnedObject::SpawnedObject()`.

`build/units.json` lists that name as a function of no unit. Five units
require it, and each binds it to a different address:

| Unit | Address the unit binds the name to | Function the recipe lists at that address |
| --- | --- | --- |
| `src/bsshader/bsorderednode.cpp` | `0x00bc2bd0` | `FUN_00bc2bd0_class::FUN_00bc2bd0`, 68 bytes, `src/staging/blk_00bc0000_o2.cpp` |
| `src/bsshader/precipitationshader.cpp` | `0x00bb04b0` | `FUN_00bb04b0::FUN_00bb04b0()`, 142 bytes, the client's own unit |
| `src/bsshader/skyshader.cpp` | `0x00b8a1f0` | `fnv_00b8a1f0::FUN_00b8a1f0::FUN_00b8a1f0()`, 360 bytes, the client's own unit |
| `src/staging/blk_004e0000_od.cpp` | `0x004f6fc0` | `fnv_004f6fc0::MyClass004f6fc0::FUN_004f6fc0`, 50 bytes, the client's own unit |
| `src/staging/blk_00ba0000_o2.cpp` | `0x0051d0d0` | `FUN_0051d0d0::FUN_0051d0d0()`, 113 bytes, `src/gamebryo2.2/corelibs/nimain/nitribasedgeom.cpp` |

Two Havok units defined the name, each for a class of its own that it also
called `SpawnedObject`:

- `src/havok/common/visualize/process/hkdebugdisplayprocess.cpp`
- `src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusviewer.cpp`

The recipe gives neither unit a row for that constructor, as a function or as
a required name. So neither definition was any of the five functions above,
and neither was the other.

## The two helpers

Each helper is a class with two bases that both declare one virtual function.
It exists so that the compiler emits the adjustor thunk the recipe lists for
the unit. Its constructor is defined so that the tables, and with them the
thunk, are emitted.

| Thunk | Recipe size | 32-bit adjustment | windows-x64 adjustment | Unit |
| --- | --- | --- | --- | --- |
| `0x00ddcbf0` | 8 | `0x20` | `0x28` | `hkdebugdisplayprocess.cpp` |
| `0x00d691b0` | 8 | `0x28` | `0x30` | `hkpconvexradiusviewer.cpp` |

Each helper, its two bases and its constructor are now inside a namespace
named after the thunk's address: `fnv_00ddcbf0` and `fnv_00d691b0`. This is
the form the recipe already uses for other adjustor helpers of the same name,
`fnv_00cd28d0::SpawnedObject` and `fnv_00b92440::SpawnedObject`, and the form
`hkdebugdisplayprocess.cpp` already uses for the next thunk,
`fnv_00ddcc00::Derived`. The names state an address and nothing else.

The bodies are unchanged. On windows-x64 each constructor stores two table
pointers, at `+0x00` and at the second base: `+0x28` in the debug-display
helper and `+0x30` in the convex-radius helper.

Three recipe names follow the source. No address, size or unit changes.

| Unit | Address | Old name | New name |
| --- | --- | --- | --- |
| `hkdebugdisplayprocess.cpp`, function | `0x00ddcbf0` | `?FUN_00ddcbf0@SpawnedObject@@WCA@AEXXZ` | `?FUN_00ddcbf0@SpawnedObject@fnv_00ddcbf0@@WCA@AEXXZ` |
| `hkdebugdisplayprocess.cpp`, required name | `0x00ddcc10` | `?FUN_00ddcbf0@SpawnedObject@@UAEXXZ` | `?FUN_00ddcbf0@SpawnedObject@fnv_00ddcbf0@@UAEXXZ` |
| `hkpconvexradiusviewer.cpp`, function | `0x00d691b0` | `?FUN_00d691b0@SpawnedObject@@WCI@AEXXZ` | `?FUN_00d691b0@SpawnedObject@fnv_00d691b0@@WCI@AEXXZ` |

A 32-bit compile of both files emits these three names.

### Every name the recipe binds to these addresses

- `0x00ddcbf0`: the one function row above. No other unit names the address.
- `0x00ddcc10`: the function `fnv_00ddcc10::Process::FUN_00ddcc10`, 42 bytes,
  of the same unit, and two required names of that unit: the row renamed
  above and `?FUN_00ddcc00@Derived@fnv_00ddcc00@@UAEXXZ`. Both are the jump
  targets of thunks. No object defines either name.
- `0x00d691b0`: the one function row above. The recipe has no row for the
  thunk's jump target, and none is added.

`src/generated/data/vtables_010d.cpp` repeats the old name of `0x00ddcbf0` in
a comment on the first entry of the table at `0x010d7e5c`. The entry itself
is null. Generated files are not edited, so the comment keeps the old
spelling.

That table is the one the constructor at `0x00ddcaf0` stores at `+0x20` of
the debug-display process, which matches the thunk's 32-bit adjustment. For
`0x00d691b0` the match is an inference: the recipe names five tables of the
convex-radius viewer, one of them for a base it labels `D28`, and the thunk
adjusts by `0x28`. Neither helper is that class. Each only reproduces its
thunk.

## Requirers

Counted from the objects of the rebuilt archive. The recipe records what a
unit binds, not which function calls which.

No object requires either helper's constructor, before or after. Inside each
unit the constructor refers to the helper's two tables, and the second table
refers to the thunk.

Five objects require the global `SpawnedObject::SpawnedObject()`, once each.
Their code is unchanged by this change.

| Object | Function | Bytes it allocates on windows-x64 |
| --- | --- | --- |
| `bsorderednode.cpp` | `0x00bc2e00` | `0xc0` |
| `precipitationshader.cpp` | `0x00bb0660` | `0xb0` |
| `skyshader.cpp` | `0x00b8a390` | `0xf8` |
| `blk_004e0000_od.cpp` | `0x004f7130`, only when its argument is null | `0x08` |
| `blk_00ba0000_o2.cpp` | `0x00ba8a00` | `0x38` |

Each of the five declares its own, different `SpawnedObject` at global scope.

What each client allocates on windows-x64, against the function the recipe
binds the name to in that client's unit:

| Client | Allocation | Recipe function at the bound address | Bytes | Constructor |
| --- | --- | --- | --- | --- |
| `bsorderednode.cpp` | `0xc0` | `FUN_00bc2bd0_class::FUN_00bc2bd0` | 68 | no |
| `precipitationshader.cpp` | `0xb0` | `FUN_00bb04b0::FUN_00bb04b0()` | 142 | yes |
| `skyshader.cpp` | `0xf8` | `fnv_00b8a1f0::FUN_00b8a1f0::FUN_00b8a1f0()` | 360 | yes |
| `blk_004e0000_od.cpp` | `0x08` | `fnv_004f6fc0::MyClass004f6fc0::FUN_004f6fc0` | 50 | no |
| `blk_00ba0000_o2.cpp` | `0x38` | `FUN_0051d0d0::FUN_0051d0d0()`, in `nitribasedgeom.cpp` | 113 | yes |

The byte counts are the recipe's sizes of the original functions. Two of the
five names the recipe gives those functions are not constructors, although
each client binds a constructor name to the address.

## Behaviour before and after

Before, a link that was forced past the duplicate gave all five clients the
debug-display helper's constructor: it was the first of the two definitions
loaded, both in the link of the whole archive and in the link of
`tests/runtime_havok_worker_pool_test`. That constructor needs `0x30` bytes
and knows nothing of the client's class.

| Client | Allocation | What the bound helper constructor did |
| --- | --- | --- |
| `bsorderednode.cpp` | `0xc0` | overwrote the fields at `+0x00` and `+0x28` with helper tables |
| `precipitationshader.cpp` | `0xb0` | the same, and the client's next call reads entry 19 of a helper table that has one entry |
| `skyshader.cpp` | `0xf8` | the same as the precipitation shader |
| `blk_004e0000_od.cpp` | `0x08` | wrote 8 bytes at `+0x28`, which is `0x28` bytes past the end of the allocation |
| `blk_00ba0000_o2.cpp` | `0x38` | overwrote the fields at `+0x00` and `+0x28` with helper tables |

After, no object defines the global name. A link without forcing reports it
as undefined. A forced link leaves the five calls unresolved. No client
reaches a real constructor body through this change, so there is no new write
extent to compare with these allocations.

In a forced link the helper's constructor, its tables and the thunk at
`0x00ddcbf0` were kept only because the five clients referred to the
constructor. Now nothing refers to it and the linker discards all of them, as
it already discarded the convex-radius helper's. The thunks remain in the
objects.

## Programs that contain these objects

Measured on the rebuilt windows-x64 tree, before and after.

- The game executable, which takes only the archive members it needs,
  contains none of the seven objects. Its link map is the same before and
  after apart from the timestamp.
- 54 of the 55 test executables link. None contains any of the seven objects.
- `tests/runtime_havok_worker_pool_test` contains all seven and does not
  link. This duplicate was one of the ten that stopped it; nine remain.

So no program that links today changes.

## One name, one content

Checked over every member of the rebuilt archive, comparing the bytes and
relocations of every definition of a name.

Before, the two units gave differing definitions to seven names:

- `SpawnedObject::SpawnedObject()`
- the table of `SpawnedObject` for `PrimaryBase`
- the table of `SpawnedObject` for `SecondaryBase`
- the type record of that second table
- the base-class list among the type records of `SpawnedObject`
- the table of `PrimaryBase`
- the table of `SecondaryBase`

The linker reports only the first; for the other six it keeps whichever it
loads first. The first four stop having differing definitions anywhere in the
archive, because no other unit emits them. The last three are still emitted by
other units, with differing content.

The scan's archive-wide count of names with differing definitions covers
select-any definitions only. Of the seven, the two type records are
select-any; the constructor allows no duplicate and the four tables are kept
by largest size. So that count falls by one with this change, for the type
record of the second table.

After, each of the 52 names the two helpers now emit or require has at most
one definition, and none of them existed before. The global
`SpawnedObject::SpawnedObject()` has none.

The two units also emitted tables and type records for global `PrimaryBase`
and `SecondaryBase`. They no longer do. Other units still emit those names
with differing content: the table of `PrimaryBase` comes from ten units and
the table of `SecondaryBase` from nine, each with content of its own, and
five units emit type records for a global `SpawnedObject`. This change does
not touch them.

## Not covered

These were open before this change and remain open.

- The five clients. Each still requires the global constructor and each
  needs a different function, listed in the first table. The recipe lists all
  five functions under other class names. Binding a client to its function
  means replacing the client's own declaration with that class, and the
  allocations above have to be checked against what each real constructor
  writes. None of that is done here.
- The process factory. Its global is zero-initialised storage, nothing
  publishes it, and registration reads it. The ticket's completion conditions
  for construction, allocation, publication, registration and retirement are
  untouched.
- The helpers reproduce thunks; they are not the debug-display process or the
  convex-radius viewer. The functions the thunks jump to are required under
  the helpers' names and have no definition under those names.
- The other global `PrimaryBase`, `SecondaryBase` and `SpawnedObject`
  declarations across the tree.
- The comment in the generated table file.

Neither unit builds for a host test, and a windows-x64 program that contains
them does not link, so no test executes this code. The evidence is the
rebuilt windows-x64 objects, the composed archive and the complete links. No
archive member is added, removed or reordered.
