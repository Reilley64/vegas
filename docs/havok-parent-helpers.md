# Havok adjustor helper names

VEGAS-81 asks for distinct Havok helper identities and for the real
construction, registration and retirement of the list box. This change is the
bounded first part: the two Havok helper classes that were both called `Parent`
now have their own names, so `Parent::Parent()` is no longer defined twice.
Everything else on the ticket is listed under "Not covered".

## The two helpers

`hkpvehicleviewer.cpp` and `hkprigidbodycentreofmassviewer.cpp` each declared
three global classes, `FirstBase`, `Receiver` and `Parent : FirstBase,
Receiver`. Each `Parent` overrides one virtual function that both bases
declare, so its second table holds an adjustor thunk. The thunk is what
`build/units.json` lists; the classes exist to make the unit emit it.

| | Vehicle | Rigid body |
| --- | --- | --- |
| Unit | `hkpvehicleviewer.cpp`, 17 functions | `hkprigidbodycentreofmassviewer.cpp`, 19 functions |
| Recipe function | `0x00d63df0`, 8 bytes | `0x00d6a1e0`, 8 bytes |
| Adjustment in the recipe's name | `0x28` | `0x20` |
| Words after the table pointer in `FirstBase` | 9 | 7 |
| windows-x64 `FirstBase` / `Receiver` / `Parent` | 48 / 8 / 56 bytes | 40 / 8 / 48 bytes |
| windows-x64 second table pointer | `+0x30` | `+0x28` |
| windows-x64 constructor | 25 bytes, stores at `+0x0` and `+0x30` | 25 bytes, stores at `+0x0` and `+0x28` |

They are different classes: different sizes, different virtual functions and
different recipe addresses.

The recipe has no function and no symbol row for either constructor, in any
unit, before or after this change. Each constructor is defined out of line
only so that the unit emits the class's tables and with them the thunk.

## What shared a name

At 9c2ebaf55 both windows-x64 objects defined these names with different
content:

| Name | Selection | Reported by a link |
| --- | --- | --- |
| `Parent::Parent()` | no duplicates | yes, as a duplicate |
| the two tables of `Parent` | largest, both 16 bytes | no |
| four type records of `Parent` | any | no |

`blk_00c00000_o2.cpp` defines three of the four type records a third time, for
a `Parent` of its own. Fourteen more tables and type records of the three
classes were defined more than once with equal content.

A link that loaded both objects kept the first definition of each name. In the
two complete forced links measured here, with unreferenced sections kept, that
was the vehicle unit's constructor and both of its tables. The rigid-body
thunk was present and no table pointed to it.

## The names

The classes are now `fnv_00d63df0::FirstBase`, `Receiver` and `Parent`
(vehicle) and `fnv_00d6a1e0::FirstBase`, `Receiver` and `Parent` (rigid body).
The recipe already scopes a function's own helper by `fnv_<address>`; both
files do so for their neighbouring helpers. The namespaces are the addresses
of the two recipe functions and claim nothing else about the classes.

Three recipe rows change name. No address, size, flag or order changes.

| Unit | Row | Address | Old name | New name |
| --- | --- | --- | --- | --- |
| `hkpvehicleviewer.cpp` | function | `0x00d63df0` | `?FUN_00d63df0@Parent@@WCI@AEPAU1@I@Z` | `?FUN_00d63df0@Parent@fnv_00d63df0@@WCI@AEPAU12@I@Z` |
| `hkpvehicleviewer.cpp` | symbol | `0x00d63e10` | `?FUN_00d63df0@Parent@@UAEPAU1@I@Z` | `?FUN_00d63df0@Parent@fnv_00d63df0@@UAEPAU12@I@Z` |
| `hkprigidbodycentreofmassviewer.cpp` | function | `0x00d6a1e0` | `?FUN_00d6a1e0@Parent@@WCA@AEPAU1@I@Z` | `?FUN_00d6a1e0@Parent@fnv_00d6a1e0@@WCA@AEPAU12@I@Z` |

The new 32-bit spellings were read from a 32-bit compile of the same
declarations.

Every name the recipe binds to the addresses involved:

- `0x00d63df0`: the function row above. No symbol row in any unit.
- `0x00d6a1e0`: the function row above. No symbol row in any unit.
- `0x00d63e10`: the vehicle unit's function
  `fnv_00d63e10::FUN_00d63e10_cls::Destroy`, 42 bytes, and five symbol rows of
  the same unit: that name, the renamed override above, `TO::FUN_00d63dd0`,
  `FnvHavok00d63de0_Derived::FUN_00d63de0` and `Own_00d63e00::FUN_00d63e00`.
  The last three are the overrides of the unit's other adjustor helpers and
  are not changed.
- The rigid-body unit has no symbol row for its override.
- `0x00730810`: see the next section.

In the windows-x64 archive two members change, by 24 symbol rows each: the
constructor, the thunk, the override, four tables and seventeen type records
take the new names. No other member's symbols change. No member is added,
removed or reordered.

## The requirer of `Parent::Parent()`

One object requires the global name: `listbox.cpp`, in the constructor
`FUN_00730810::FUN_00730810()`.

`listbox.cpp` declares a `Parent` of its own, one pointer, as the base of
`FUN_00730810`. It is a third class under the name. The recipe lists
`0x00730810` as a function of the `listbox.cpp` unit, 204 bytes, and five
other units bind `FUN_00730810::FUN_00730810()` to that address:
`bartermenu.cpp`, `inventorymenu.cpp`, `itemmodmenu.cpp`,
`repairservicesmenu.cpp` and `blk_00740000_od.cpp`. No unit has a row for the
name `Parent::Parent()`. The recipe therefore gives the list box base
constructor no address, and neither helper constructor is it.

No definition is kept under the global name, because none describes the list
box base. `Parent::Parent()` is now a name that `listbox.cpp` requires and no
object defines. This is the one new undefined name of the change.

Nothing else requires any of the names. No object calls either helper
constructor. No object requires either thunk: the two tables in
`src/generated/data/vtables_010d.cpp` that would hold them have a null entry
there, with the old 32-bit name in a comment. That file is generated and is
not edited.

## Behaviour of the list box constructor

The call to the base constructor is the only path that changes.

Before, only in a link forced past the duplicate, it reached the vehicle
helper's constructor. Now it reaches no definition, and a forced link gives
the call address 0.

Storage on windows-x64, each size from the unit's own declaration compiled
with that unit's command, each write from the rebuilt objects:

| | Bytes |
| --- | --- |
| Vehicle helper constructor, highest write | 8 bytes at `+0x30`, needs `0x38` |
| Rigid-body helper constructor, highest write | 8 bytes at `+0x28`, needs `0x30` |
| `Parent` as `listbox.cpp` declares it | 8 |
| `FUN_00730810` as `listbox.cpp` declares it | 72 |
| `FUN_00730810::FUN_00730810()` itself, highest write | 8 bytes at `+0x3a`, needs `0x42` |
| `FUN_00730810` as `repairservicesmenu.cpp` declares it | 1 |

So before, the helper constructor wrote 48 bytes past the list box's own base
and stayed inside the 72-byte object as `listbox.cpp` declares it. The
constructor body then overwrote all of it except the two padding bytes at
`+0x32`.

The next call in the same function is `Section::Section()`, which no object
defines, before or after. The function could not complete in a forced link at
the tip either.

No program that links today contains any of this:

- The game executable's ordinary link loads 15 archive members. None is
  `listbox.cpp`, `hkpvehicleviewer.cpp` or
  `hkprigidbodycentreofmassviewer.cpp`.
- 54 of the 55 test executables link ordinarily. None loads any of the three.
- `tests/runtime_havok_worker_pool_test` does not link, before or after. Its
  forced link and the forced link of every member load all three objects.
  With the linker's default settings both discard the list box constructor
  and both helper constructors as unreferenced, before and after.

`listbox.cpp` required 115 names that no object defines; it now requires 116.

## Links

Measured on full windows-x64 builds of 9c2ebaf55 and of this change.

| Link | Before | After |
| --- | --- | --- |
| Game, ordinary | links, 78 imports | same |
| Every member, forced, no error limit: duplicate blocks / symbols | 25 / 17 | 24 / 16 |
| Every member, forced: undefined names | 35,748 | 35,749 |
| Worker pool test, no error limit: duplicates | 10 | 9 |
| Worker pool test, forced: undefined names | 35,426 | 35,427 |

The duplicate that leaves is `Parent::Parent()`. The undefined lists change by
three names in and two out: `Parent::Parent()` enters, and the two helper
overrides, undefined before, appear under their new names. Imports and every
other list are equal.

## Names with two definitions

Every COMDAT section of the 2,223 archive members was read, and each name's
definitions compared by section bytes and relocations.

| Names touched here | Before | After |
| --- | --- | --- |
| defined in more than one member | 21 | 0 |
| of those, with differing content | 7 | 0 |

Across the archive, 489 names with selection "any" had differing definitions
before and 485 have now. The four that leave are the type records of `Parent`.
None enters.

## Not covered

These were open before this change and remain open.

- The list box base. `listbox.cpp`'s `Parent` has no constructor definition
  and no recipe address. Whether the original release has a separate base
  constructor is not established here.
- The rest of the list box: the real base, derived and `Section`
  declarations, `Section::Section()` and `Section::~Section()`,
  `G2::AddHead`, the order of `FUN_007a1950` and the list insertion, and
  cleanup on failure.
- `repairservicesmenu.cpp` declares `FUN_00730810` as an empty class of 1
  byte and embeds it, while the constructor writes `0x42` bytes. The other
  four units that bind `0x00730810` in the recipe do not require the name in
  their windows-x64 objects.
- The two overrides, `fnv_00d63df0::Parent::FUN_00d63df0` and
  `fnv_00d6a1e0::Parent::FUN_00d6a1e0`, have no definition. The recipe binds
  the first to `0x00d63e10` and has no row for the second. That the second
  belongs to `0x00d6a1f0`, the 42-byte function that follows its thunk, is an
  inference from the vehicle unit's pattern.
- The helpers are stand-ins. Their 32-bit adjustments match the recipe; their
  windows-x64 adjustments, `0x30` and `0x28`, follow from the stand-in
  declarations and not from the viewer classes whose generated tables have
  the null entries. Connecting each thunk to its viewer class is open.
- The two comments in `src/generated/data/vtables_010d.cpp` keep the old
  names.
- Other units declare global classes named `Parent`, `FirstBase` or
  `Receiver` of their own, among them `blk_00c00000_o2.cpp`,
  `hkstatisticsprocess.cpp` and `hkpmidphaseviewer.cpp`. Each name they emit
  now has one definition. They are not renamed here.

Neither Havok unit nor `listbox.cpp` builds for a host test, nothing calls
the helper constructors, and no windows-x64 program that contains
`listbox.cpp` links. No test executes these paths. The evidence for this
change is the rebuilt windows-x64 objects, the composed archive and the
complete links.
