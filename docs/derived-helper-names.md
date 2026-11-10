# Adjustor helper names: `Derived`

Nine units each declared a global class `Derived` with an out-of-line
constructor, so `Derived::Derived()` had nine definitions and a link of every
archive member reported eight duplicate blocks. No repair-family ticket
(VEGAS-56, VEGAS-60 to VEGAS-82) names this symbol. The units belong to three
folder tickets: VEGAS-20 (the two staging units, one of which is in all eight
blocks), VEGAS-18 (three `fallout_shared` units) and VEGAS-15 (four Havok
physics units). This change is filed under VEGAS-20.

This is a bounded change. Eight of the nine classes get their own names. The
ninth keeps the global name because a generated table consumes it. What stays
open is under "Not covered".

## The nine classes

Each unit declares two base classes and `Derived`, which overrides one virtual
function that both bases declare. The second table of `Derived` therefore
holds an adjustor thunk, and the thunk is what `build/units.json` lists. The
constructor is defined out of line only so that the unit emits the tables and
with them the thunk.

| Unit | Recipe function | 32-bit adjustment in the recipe's name | Bases |
| --- | --- | --- | --- |
| `staging/blk_00900000_o2.cpp` | `0x00905b90`, 8 bytes, thunk | `0x14` | `PrimaryBase`, `SecondaryBase` |
| `staging/blk_00820000_o2.cpp` | `0x00831ff0`, 10 bytes, `__cdecl` thunk | `4` | `PrimaryBase`, `SecondaryBase` |
| `fallout_shared/tesobjectanio.cpp` | `0x00511e30`, 8 bytes, thunk | `0x18` | `PrimaryBase`, `SecondaryBase` |
| `fallout_shared/teslevcharacter.cpp` | `0x0050ade0`, 8 bytes, thunk | `0x4c` | `PrimaryBase`, `SecondaryBase` |
| `fallout_shared/bgsstaticcollection.cpp` | `0x004fe630`, 8 bytes, thunk | `0x30` | `PrimaryBase`, `SecondaryBase` |
| `hkpgroupcollisionfilter.cpp` | `0x00cbfc00`, 8 bytes, thunk | `0x10` | `PrimaryBase`, `SecondaryBase` |
| `hkpcpuworldlinearcastjob.cpp` | `0x00df7190`, 8 bytes, thunk | `4` | `Base1`, `Base2` |
| `hkpgroupfilter.cpp` | `0x00e00c00`, 8 bytes, thunk | `0x10` | `PrimaryBase`, `SecondaryBase` |
| `hkpaabbtreeworldmanager.cpp` | `0x00d089c0`, 8 bytes, the override itself | none | `PrimaryBase`, `SecondaryBase` |

The recipe has no function row and no symbol row for `Derived::Derived()`, in
any unit, before or after this change. So none of the nine constructors is a
recipe function, and none can be called the owner of the name. The nine
classes differ in size, in the function they override and in recipe address.
They are nine classes under one stand-in name.

windows-x64, each size from the unit's own declaration compiled with that
unit's command, each write from the rebuilt objects. Equal before and after.

| Recipe address | First base / second base / `Derived` | Constructor, 25 bytes: stores | Highest write needs | Thunk adjustment |
| --- | --- | --- | --- | --- |
| `0x00905b90` | 24 / 8 / 32 | 8 bytes at `+0x0` and `+0x18` | `0x20` | 24 |
| `0x00831ff0` | 8 / 8 / 16 | `+0x0`, `+0x8` | `0x10` | 8 |
| `0x00511e30` | 32 / 8 / 40 | `+0x0`, `+0x20` | `0x28` | 32 |
| `0x0050ade0` | 80 / 8 / 88 | `+0x0`, `+0x50` | `0x58` | 80 |
| `0x004fe630` | 56 / 8 / 64 | `+0x0`, `+0x38` | `0x40` | 56 |
| `0x00cbfc00` | 24 / 8 / 32 | `+0x0`, `+0x18` | `0x20` | 24 |
| `0x00df7190` | 8 / 8 / 16 | `+0x0`, `+0x8` | `0x10` | 8 |
| `0x00e00c00` | 24 / 8 / 32 | `+0x0`, `+0x18` | `0x20` | 24 |
| `0x00d089c0` | 24 / 8 / 32 | `+0x0`, `+0x18` | `0x20` | no thunk |

Every constructor writes inside its own class. No object declares storage for
any of the nine classes and no object requires `Derived::Derived()`: the
archive has no relocation against the name, before or after. There is no
requiring unit to compare the write extent with.

## The names

Eight classes and their bases are now scoped by the address of their recipe
function: `fnv_00905b90`, `fnv_00831ff0`, `fnv_00511e30`, `fnv_0050ade0`,
`fnv_004fe630`, `fnv_00cbfc00`, `fnv_00df7190` and `fnv_00e00c00`. The recipe
already scopes a function's own helper this way. Four of the eight files
already use such namespaces, and the forced link's map of 39c4fbb99 lists 103
`fnv_<address>::Derived` constructors. The namespace is the address of the
recipe function and claims nothing else about the class.

The source change is two lines per file: the opening and the closing of the
namespace.

Ten recipe rows change name. No address, size, flag or order changes.

| Unit | Row | Address | Old name | New name |
| --- | --- | --- | --- | --- |
| `blk_00900000_o2.cpp` | function | `0x00905b90` | `?FUN_00905b90@Derived@@WBE@AEXXZ` | `?FUN_00905b90@Derived@fnv_00905b90@@WBE@AEXXZ` |
| `blk_00820000_o2.cpp` | function | `0x00831ff0` | `?FUN_00831ff0@Derived@@W3AAXXZ` | `?FUN_00831ff0@Derived@fnv_00831ff0@@W3AAXXZ` |
| `tesobjectanio.cpp` | function | `0x00511e30` | `?FUN_00511e30@Derived@@WBI@AEXXZ` | `?FUN_00511e30@Derived@fnv_00511e30@@WBI@AEXXZ` |
| `teslevcharacter.cpp` | function | `0x0050ade0` | `?FUN_0050ade0@Derived@@WEM@AEXXZ` | `?FUN_0050ade0@Derived@fnv_0050ade0@@WEM@AEXXZ` |
| `bgsstaticcollection.cpp` | function | `0x004fe630` | `?FUN_004fe630@Derived@@WDA@AEXXZ` | `?FUN_004fe630@Derived@fnv_004fe630@@WDA@AEXXZ` |
| `hkpgroupcollisionfilter.cpp` | function | `0x00cbfc00` | `?FUN_00cbfc00@Derived@@WBA@AEXXZ` | `?FUN_00cbfc00@Derived@fnv_00cbfc00@@WBA@AEXXZ` |
| `hkpgroupcollisionfilter.cpp` | symbol | `0x00dff470` | `?FUN_00cbfc00@Derived@@UAEXXZ` | `?FUN_00cbfc00@Derived@fnv_00cbfc00@@UAEXXZ` |
| `hkpcpuworldlinearcastjob.cpp` | function | `0x00df7190` | `?FUN_00df7190@Derived@@W3AEXXZ` | `?FUN_00df7190@Derived@fnv_00df7190@@W3AEXXZ` |
| `hkpcpuworldlinearcastjob.cpp` | symbol | `0x00df71d0` | `?FUN_00df7190@Derived@@UAEXXZ` | `?FUN_00df7190@Derived@fnv_00df7190@@UAEXXZ` |
| `hkpgroupfilter.cpp` | function | `0x00e00c00` | `?FUN_00e00c00@Derived@@WBA@AEXXZ` | `?FUN_00e00c00@Derived@fnv_00e00c00@@WBA@AEXXZ` |

The new 32-bit spellings were read from a 32-bit compile of the same
declarations. The adjustment in each matches the old name.

Every name the recipe binds to the addresses involved:

- `0x00905b90`, `0x00831ff0`, `0x00511e30`, `0x0050ade0`, `0x004fe630`,
  `0x00cbfc00`, `0x00df7190`, `0x00e00c00`: the function row above and no
  symbol row in any unit.
- `0x00d089c0`: the function row `?FUN_00d089c0@Derived@@UAEXXZ` of
  `hkpaabbtreeworldmanager.cpp`, 8 bytes, and no symbol row. Not changed.
- `0x00dff470`: the function `fnv_00dff470::FUN_00dff470_cls::DestroySelf` of
  `blk_00de0000_o2.cpp`, 71 bytes, and thirteen symbol rows: that name, the
  renamed override above, and eleven rows for the overrides of seven other
  adjustor helpers, in `blk_00c60000_o2.cpp`, `blk_00de0000_o2.cpp` and
  `clamped_acos.cpp`.
- `0x00df71d0`: the function `FUN_00df71d0`'s deleting destructor in
  `hkpcpuworldlinearcastjob.cpp`, 64 bytes, and three symbol rows of the same
  unit: the renamed override above, `fnv_00df71a0::Derived::FUN_00df71a0` and
  `DF71B0Object::FUN_00df71b0`.

In the windows-x64 archive eight members change, by 26 symbol rows each: the
constructor, the thunk, three undefined virtual functions, four tables and
seventeen type records take the new names. No other member's symbols change,
and `hkpaabbtreeworldmanager.cpp.obj` is byte for byte the same. No member is
added, removed or reordered.

## The class that keeps the global name

`hkpaabbtreeworldmanager.cpp` is different from the other eight. Its recipe
function is not a thunk but the override `Derived::FUN_00d089c0` itself, and
a generated table calls it by that name:
`src/generated/data/vtables_010c.cpp` declares `fnv_fn_00d089c0` as
`?FUN_00d089c0@Derived@@UEAAXXZ` and stores it in the table
`fnv_00d08cf0::FUN_00d08cf0` for `MyBase2`. That file is generated and is not
edited, so renaming the class would leave the table entry without a
definition. The class, its two bases and its constructor are unchanged, and
it is now the only definition of `Derived::Derived()`.

This is the generated dispatch consumer of the change. It binds the same
definition before and after, in an object whose bytes did not change. No
generated file names any of the eight renamed thunks or overrides in code.
One comment, in `src/generated/data/vtables_0107.cpp`, keeps the old name of
the `0x00831ff0` thunk beside a null entry.

## What shared a name

At 39c4fbb99 the windows-x64 objects defined these names more than once with
different content:

| Name | Selection | Definitions / distinct | Reported by a link |
| --- | --- | --- | --- |
| `Derived::Derived()` | no duplicates | 9 / 6 | yes, as a duplicate |
| table of `Derived` for `PrimaryBase` | largest, all 16 bytes | 8 / 8 | no |
| table of `Derived` for `SecondaryBase` | largest, all 16 bytes | 8 / 8 | no |
| two type records of `Derived` | any | 9 / 6 and 8 / 5 | no |
| table of `PrimaryBase` | largest, all 16 bytes | 10 / 10 | no |
| table of `SecondaryBase` | largest, all 16 bytes | 9 / 9 | no |
| two type records of `PrimaryBase` | any | 13 / 2 and 10 / 2 | no |

Four of the nine constructors are equal in bytes and relocation names, those
of `0x00905b90`, `0x00cbfc00`, `0x00e00c00` and `0x00d089c0`: all four store
at `+0x0` and `+0x18` and name the tables by the shared global names.

## Behaviour

No path that runs today changes. Nothing calls any of the nine constructors,
and no table of any of the nine classes is referenced from outside its own
constructor and type records.

What a link forced past the duplicate bound, read from the `/force
/opt:noref` map of every archive member:

| Name | At 39c4fbb99 | Now |
| --- | --- | --- |
| `Derived::Derived()` | `blk_00900000_o2`, the first of the nine in archive order | `hkpaabbtreeworldmanager`, the only definition |
| both tables of the global `Derived` | `blk_00900000_o2` | `hkpaabbtreeworldmanager` |
| `Derived::FUN_00d089c0` | `hkpaabbtreeworldmanager` | the same |
| tables and constructors of the eight renamed classes | not present under a name of their own | each in its own object |
| table of the global `PrimaryBase`, of `SecondaryBase` | `blk_00900000_o2` | `tesvalueform`, the first of those left |

- The global constructor name. Before, it was the `0x00905b90` helper's body,
  which stored that helper's two tables: an entry for the undefined
  `Derived::FUN_00905b90` and the thunk to it. Now it is the AABB-tree
  helper's body, equal in bytes, which stores that helper's own two tables,
  with `Derived::FUN_00d089c0` in the second. No object requires the name, so
  no call reaches either.
- The other eight constructors. Before, the linker kept the `0x00905b90`
  helper's constructor and dropped the other eight as duplicates. All eight
  thunks were present, and no table pointed to six of them: the tables kept
  under the shared names were the `0x00905b90` helper's.
  `hkpcpuworldlinearcastjob.cpp` names its tables after `Base1` and `Base2`,
  so its own tables were kept, but its constructor was not. Now all nine
  constructors are present, each stores the two tables of its own class, and
  each thunk is in its own class's second table.
- The tables of the global `PrimaryBase` and `SecondaryBase`. No relocation
  in any archive member refers to either name, before or after, so which copy
  a link keeps reaches nothing. This is unchanged data, listed under "Not
  covered".
- The worker pool test's forced link loads `hkpaabbtreeworldmanager.cpp.obj`
  and none of the other eight. It bound `Derived::Derived()` and the tables
  to that object before and binds the same now.

With the linker's default settings both forced links discard all nine
constructors as unreferenced, before and after.

No program that links today contains any of this:

- The game executable's ordinary link loads 15 archive members. None is one
  of the nine objects. Its map is the same below the header.
- 54 of the 55 test executables link ordinarily. None loads any of the nine.
- `tests/runtime_havok_worker_pool_test` does not link, before or after, on
  the same 35,362 undefined-symbol errors.

## Links

Measured on full windows-x64 builds of 39c4fbb99 and of this change, exported
to the same path.

| Link | Before | After |
| --- | --- | --- |
| Game, ordinary and forced without error limit | links, 78 imports | same |
| Every member, ordinary | fails, 14 duplicate blocks / 7 symbols | fails, 6 / 6 |
| Every member, forced, no error limit: duplicate blocks / symbols | 14 / 7 | 6 / 6 |
| Every member, forced: undefined names | 35,674 | 35,674 |
| Every member, forced: imports | 137 | the same 137 |
| Worker pool test, no error limit | 0 duplicates, 35,362 undefined | same |
| Worker pool test, forced: undefined names | 35,352 | the same 35,352 |

The duplicate that leaves is `Derived::Derived()` with its eight blocks. None
enters. The undefined list changes by 24 names out and the same 24 in under
their new scope: the override of each of the eight classes and the undeclared
virtual function of each of their sixteen bases. No object defined them
before and none defines them now. Every other list is equal.

## Names with two definitions

Every COMDAT section of the 2,223 archive members was read, all selections,
and each name's definitions compared by section bytes and relocations.

| | Before | After |
| --- | --- | --- |
| Names the eight members gained: defined in more than one member | | 0 of 208 |
| Names the eight members lost: with differing definitions | 9 | 4 |
| Archive, every selection: names with differing definitions | 535 | 530 |
| Archive, selection "any": names with differing definitions | 483 | 481 |

The five that leave are `Derived::Derived()`, the two tables of `Derived` and
two type records of `Derived`. None enters. Each name of the global `Derived`
now has one definition.

## Not covered

These were open before this change and remain open.

- Four names of the global `PrimaryBase` and `SecondaryBase` still have
  differing definitions, in units this change does not touch:

  | Name | Before | After | Members now |
  | --- | --- | --- | --- |
  | table of `PrimaryBase` | 10 / 10 | 3 / 3 | `tesvalueform`, `hkptoicountviewer`, `hkpaabbtreeworldmanager` |
  | table of `SecondaryBase` | 9 / 9 | 2 / 2 | `tesvalueform`, `hkpaabbtreeworldmanager` |
  | type record `??_R1A@?0A@EA@PrimaryBase@@8` | 13 / 2 | 6 / 2 | those three, `blk_00ca0000_o2`, `enchantmentitem`, `hkpbroadphaseviewer` |
  | type record `??_R4PrimaryBase@@6B@` | 10 / 2 | 3 / 2 | the first three |

  No link reports them. Nothing refers to the two tables. Giving these
  classes their own names needs `tesvalueform.cpp` and
  `hkptoicountviewer.cpp`, which have no part in the duplicate.
- The AABB-tree helper keeps the global names `Derived`, `PrimaryBase` and
  `SecondaryBase` because the generated table binds
  `Derived::FUN_00d089c0`. Giving it its own name needs the generator, which
  is outside the repository, to emit the new name.
- Six more archive members name a global class `Derived` in a symbol without
  defining its constructor: `blk_00aa0000_od`, `niposdata`, `nianimationsdm`,
  `hkpcollisioncallbackutil`, `hkpendofstepcallbackutil` and the generated
  `vtables_010a`. `blk_00aa0000_od.cpp` defines
  `Derived::FUN_00aa88d0`, a recipe function at `0x00aa88d0` that
  `vtables_010a` consumes. If one of them required `Derived::Derived()`
  later, it would bind to the AABB-tree helper's constructor and no link
  would report it.
- The eight overrides and the sixteen base functions have no definition. The
  recipe binds two of the overrides, to `0x00dff470` and `0x00df71d0`, and
  has no row for the other six. That each of the six belongs to the function
  its thunk jumps to in the original release is an inference from those two
  rows and from the comments in `teslevcharacter.cpp`; it is not read from
  the original here.
- The helpers are stand-ins. Their 32-bit adjustments match the recipe; their
  windows-x64 adjustments follow from the stand-in declarations and not from
  the real classes whose tables hold the thunks. Connecting each thunk to its
  class is open.
- The tag `// @fnv 0x00df7190` in `hkpcpuworldlinearcastjob.cpp` sits on the
  constructor, while the recipe function at that address is the thunk. It is
  not moved here.
- The other six duplicate symbols of the forced link:
  `RepairMenu::GetClass()`, `FUN_00488400_shell::SaveLeveledList()`,
  `std::basic_string<char>::assign(const char*, unsigned int)`,
  `bhkCollisionObject::GetRTTI() const`,
  `bhkCollisionObject::GetFromNiAVObject(NiAVObject*)` and
  `bhkCollisionObject::GetFromRigidBody(const hkpRigidBody*)`, one block
  each.

None of the nine units builds for a host test, nothing calls the helper
constructors, and no windows-x64 program that contains any of the nine
objects links. No test executes these paths. The evidence for this change is
the rebuilt windows-x64 objects, the composed archive and the complete links.
