# One definition of the repair menu class id

VEGAS-19 owns the `fallout` units. No repair-family ticket names this
symbol. This change is bounded: `RepairMenu::GetClass()` now has one
definition. Everything else is listed under "Not covered".

## The function

`RepairMenu::GetClass()` is the function at `0x007b54b0`. It returns the
constant 1035 and reads nothing. This is the recovered behaviour and it is
unchanged.

## What the recipe says

| Address | Function row | Unit | Recipe size |
| --- | --- | --- | --- |
| `0x007b54b0` | `RepairMenu::GetClass()` | `src/fallout/interface/menus/repairmenu.cpp` | 16 |
| `0x007b54c0` | `RepairMenu::AssignTileByID(int, Tile*)` | `src/fallout/interface/menus/repairmenu_h_unit.cpp` | 38 |

`repairmenu_h_unit.cpp` has that one function row and no other. No unit has
a symbol row for `GetClass`, and no other name is bound to `0x007b54b0`. The
one symbol row at `0x007b54c0` is the header unit's own.

## The removed definition

`repairmenu.cpp` defines `GetClass` with the address tag. That is the
recipe's function.

`repairmenu.h` defined it a second time, with the same tag, beside
`AssignTileByID`. Only `repairmenu_h_unit.cpp` includes that header, so the
header unit emitted both members. The recipe gives the header unit
`0x007b54c0` only. So the header's `GetClass` was a second transcription of
a function another unit owns. It is removed, with the constant only it used.
The header keeps `AssignTileByID`. `repairmenu.cpp` is untouched.

## The two definitions were the same code

At the previous tip both objects defined the name as an ordinary function in
a section that refuses a second definition: 6 bytes, no relocation, the same
bytes. Neither was select-any. Now `repairmenu.cpp.obj` alone defines it,
with the same bytes.

## Requirers

No object of the windows-x64 build requires the name: none of the 2,223
archive members, and no test. No generated dispatch table names the function
or its address. Which table of the original release holds it is not
established here.

## Which body a link kept

`repairmenu_h_unit.cpp.obj` precedes `repairmenu.cpp.obj` in the archive.

| Forced link with a map | Previous tip | Now |
| --- | --- | --- |
| whole archive, unreferenced sections kept | `repairmenu_h_unit.cpp.obj` | `repairmenu.cpp.obj` |
| whole archive, unreferenced sections collected | not in the image | not in the image |
| worker-pool test, unreferenced sections kept | `repairmenu.cpp.obj` | the same |
| worker-pool test, unreferenced sections collected | not in the image | not in the image |

One image changes which copy it holds: the forced whole-archive link that
keeps unreferenced sections. The two copies were the same six bytes, and
nothing in that image calls the function. So no call reaches a different
body.

## Programs

- The game executable loads archive members on demand. It loads neither
  object, before or after. Its map is unchanged below the header.
- Of the 55 test programs, 54 link and none contains either object.
- The worker-pool test does not link. Forced, its closure contains
  `repairmenu.cpp.obj` and not `repairmenu_h_unit.cpp.obj`, before and
  after.

## Measured links

Windows-x64, 2,223 archive members in the same order. Against the commit
before this one, one object differs, `repairmenu_h_unit.cpp.obj`: it loses
the one definition.

| Link | Before | This change |
| --- | --- | --- |
| on demand, ordinary and unlimited | links, 78 imports | every list identical |
| forced, whole archive: duplicate symbols / blocks | 4 / 11 | 3 / 10 |
| forced unlimited: undefined names | 35,674 | the same 35,674 |
| forced unlimited: imports | 137 | the same 137 |

The symbol that leaves is `RepairMenu::GetClass()`, one block. None enters.

Three duplicate symbols remain in the forced link, in ten blocks:
`Derived::Derived()` in eight, `FUN_00488400_shell::SaveLeveledList()` in
one, and `std::basic_string<char>::assign(const char*, unsigned int)` in
one.

## Not covered

These were open before this change and remain open.

- The class is declared four times: in `repairmenu_decls.h` for the header
  unit, in `repairmenu_packet.h` for `repairmenu.cpp`, in
  `include/RepairMenu.h` and in `include/fnv/decl/RepairMenu.h`. They do not
  list the same members or bases. Whether they agree on the windows-x64
  offsets of the tile array was not measured. `GetClass` reads no member, so
  it does not depend on the answer; `AssignTileByID` does.
- A caller. Nothing requires `GetClass`, so nothing shows how the original
  release reaches it.
- Nothing executes the function. In the forced links `repairmenu.cpp.obj`
  loads beside 35,674 undefined names.

`build/units.json` is unchanged: no name in it changed.
