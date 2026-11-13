# The setting value accessor at its x64 offset

VEGAS-111. The recipe has one function row at `0x0043d4d0`, 56 bytes, in
`src/fallout_shared/magic/magicitem.cpp`: `FUN_0043d4d0`. It returns a
reference to a setting's integer value, or to `DAT_01202800`, set to zero,
when it is given null. 122 units call it.

Everything below was measured on the windows-x64 cross build of 64f08c9d9
and of the two code commits, built from one source path. Nothing was run on
Windows.

## The defect

The body was `return pThis ? pThis[1] : ...` with `int* pThis`: the int 4
bytes into the object. That is the value's offset in the 32-bit layout,
after a 4-byte table pointer. The settings the 406 moved calls pass are
objects of the shared `Setting` (`include/Setting.h`), through
`SettingT<...>` and the generated `GlobalObject` classes. The compiler
lays each of them out with the table pointer in bytes 0 to 7 and `uValue`
at 8, 24 bytes in all, measured in the unit that defines them. The
setting's constructor writes the value at 8.

So as built for windows-x64, a read through the accessor of such a
setting would return bytes 4 to 7 of the setting, the upper half of its
table pointer, and a write would overwrite them. No program that links
today contains the accessor or a caller: the lazy link of FalloutNV.exe's
inputs with `user32.lib` at 64f08c9d9 loads 24 members of the game
archive, none of them `magicitem.cpp` or one of the 122 units that call
the accessor. Nothing was run. This is the defect class of rule (c) of
the 2026-11-11 (2) ruling: a body that uses the 32-bit offset of an
established declaration.

## The change

1. `SETTING_VALUE` and `Setting` move unchanged into
   `include/fnv/setting_value_union.h` and `include/fnv/setting_class.h`,
   which `SETTING_VALUE.h` and `Setting.h` include where the declarations
   were. `magicitem.cpp` cannot include `Setting.h`: that header includes
   `layout_support.h`, whose `fnv/ni_pointer.h` redefines the unit's own
   `NiPointer` in `magicitem_decls.h`. All 2,360 objects of the build are
   the same as before once the COFF timestamp is masked. The new names avoid
   `fnv/setting.h`, which the include of `"Setting.h"` in
   `fnv/setting_t.h` would find first on a file system that ignores case.
2. The accessor takes the shared `Setting` and returns `pThis->uValue.i`.
   In its object one instruction changes, `addq $0x4, %rax` to
   `addq $0x8, %rax`. Its windows-x64 name becomes
   `?FUN_0043d4d0@@YAAEAHPEAVSetting@@@Z`. The recipe row becomes
   `?FUN_0043d4d0@@YAAAHPAVSetting@@@Z`, at the same address, size and
   unit.

`include/fnv/symbols_0043d000.h` declares both forms. The `int *` form has
no definition; the calls that this change does not move stay on it, so
none of them reaches the repaired body.

## The calls

Every free call of the accessor in the tree, 692, classified by its
argument. A global's identity is the name the unit's object refers to,
followed through the `/alternatename` pragmas to the archive's definition.

| Class | Calls | Units |
| --- | --- | --- |
| Moved: a global that generated data defines as a setting of the shared class, in a unit that can name the shared `Setting` | 406 | 101 |
| Tabled: the unit defines a `::Setting` of its own | 109 | 10 |
| Tabled: no object defines the name | 89 | 11 |
| Tabled: the global is defined as an empty class | 16 | 7 |
| Tabled: the argument is not a global | 31 | 9 files |
| Tabled: `src/fallout/misc/main.cpp` | 41 | 1 |

A moved call's conversion of its argument to `int *` becomes a conversion
to `::Setting *`. The address is the same. Every moved unit's object is
the same as before once the accessor's name is respelled, with one
exception: in `FUN_004a9050` (`bgssceneinfo.cpp`) the two arms of an `if`
shared one call; one arm now calls the new form and the other stays on the
old one, so the compiler emits a call in each arm. Each arm passes the
address it passed before. Ten units call both forms. Their objects gain
that one undefined symbol; apart from `FUN_004a9050` nothing else in them
changes.

The recipe entries of the 101 units respell each key of the old name, in
its two spellings, or add the new key beside it in the ten units that keep
both: 182 keys, 169 once the entries of a source are merged.

The 31 sources that keep a call on the old form keep its key (51 keys, two
spellings) at `0x0043d4d0`. The key records where the call went in the
original; it is not a definition, and nothing may bind the old name to the
new body. A unit's old key is removed in the commit that moves its last
tabled call. The projected boot model follows the old name to the new body
through these keys (one more aliased name); that is a statement about the
model, not a link.

### Moved calls to note

- Five moved calls are established only through `/alternatename` pragmas
  in `src/generated/data`. The unit declares the global under a `DAT_`
  name with a type of its own, its object refers to that name, and the
  pragma maps it to the generated setting:
  - `bgssceneinfo.cpp` line 1164, `DAT_011c5a90` declared as
    `fnv_004a82d0::StatTextureCount`, and line 1282, `DAT_011c63cc` as
    `fnv_004a8bb0::GlobalObject2_0045cfe0`: pragmas at lines 7 and 11 of
    `src/generated/data/fallout_shared/bgssceneinfo.inc`.
  - `playercharacter.cpp` lines 1901 (`DAT_011c3c3c`, `IntSetting`), 1948
    (`DAT_011c3ea4`, `IntSetting`) and 1976 (`DAT_011c3e38`,
    `CountSetting`): pragmas at lines 9, 26 and 22 of
    `src/generated/data/fallout/ai/playercharacter.inc`.
- `hudmainmenu.cpp`'s moved call (line 8918) reads
  `originalRuntimeFloatSetting87`, a float setting
  (`src/generated/setting_float_initializers.cpp`), through the int
  accessor and multiplies a float by the result. This oddity predates
  this change: the call passes the same address as before.

### Tabled calls

- **A `::Setting` of the unit's own.** `actor.cpp`, `beamprojectile.cpp`,
  `explosion.cpp`, `highprocess.cpp`, `interface.cpp`, `computersmenu.cpp`,
  `package.cpp`, `renderer.cpp`, `bstempeffectsimpledecal.cpp` and
  `tesscriptfunctions.cpp` define a global `struct Setting` with member
  functions only; the compiler measures it at 1 byte. The unit's
  declaration of the new form would name that class, not the shared one.
  The units stay on their copy.
- **No object defines the name.** Each of these 11 units defines an empty
  struct of its own named `GlobalObject2_0040c150` or
  `GlobalObject2_0045cfe0` (one has only a member `int* Int()`); generated
  data defines the class of that name with the class-key `class`. The
  unit's name for the global therefore differs from the defined one and no
  member defines it. The unit's type is not the shared class. 63 names.
  They move when the unit's copy is removed.
- **An empty class.** `DAT_011c3c90` (`CountSetting`, generated data of
  `playercharacter.cpp`; called from `tes.cpp` and `playercharacter.cpp`)
  and `DAT_011cf788` (`SettingT_GameSettingCollection_`, generated data of
  `highprocess.cpp`) are 1-byte objects. So are the definitions of
  `g_011cd3b4`, `g_011cd538` and `g_011cdde0` in `bgsexplosion.cpp`, of
  `g_011c59e0` in `bgssceneinfo.cpp` and of `g_011f9148` in
  `forenderedterminal.cpp`, each of a class of the unit's own with the
  name of a generated setting class; `actor.cpp` refers to one of them.
  Neither the old offset nor the new one is inside these objects. No
  recipe key or generated initializer names a setting at `0x011c3c90` or
  `0x011cf788`.
- **Not a global.** The evidence that the pointer is a setting is missing:
  - `ailineartaskthreadmanager.cpp`: four casts of the integers
    `0x011c3ea4`, `0x011dfb34` and `0x011dfb18`, addresses of the original
    release, which are not the x64 objects.
  - `lockpickmenu.cpp`: ten elements of `g_apLockNodes0_011a0328` to
    `..3_011a0364`, which generated data fills with `fnv_data_` names, not
    with setting objects.
  - `tesobjectcell.cpp`: `this`, a cell.
  - `blk_00660000_od.cpp`: the members of a pair table passed in.
  - `interfacemanager.cpp`, `interfacemanager.h`, `racesexmenu.cpp`,
    `interface.cpp` and `tesscriptfunctions.cpp`: pointers from a
    parameter, a field or a collection lookup whose producer is a
    stand-in.
- **`main.cpp`.** Its 41 calls stay for the owner of that unit. 26 of them
  are on `g_011c3ea4`, the processor count, among them WinMain's three
  writes. They would move the same way.

## What the settings were

From the source and the objects; nothing was run.

- 405 of the moved calls read and one writes: the increment of
  `iScreenShotIndex:Display` after a screenshot (`0x00878860`,
  `blk_00860000_od.cpp`), whose read is moved too. Before this change it
  would have written into the upper half of that setting's table pointer.
- The most read settings among the moved calls are `uGridsToLoad:General`
  (135 calls), `iNumHWThreads:General` (27), `uInterior Cell
  Buffer:General` (8), `iConsoleFont:Menu` and `iConsoleVisibleLines:Menu`
  (7 each). On windows-x64 each read would return half of a table
  pointer, a value that depends on where the executable is loaded and
  that no constructor, INI file or game setting sets.
- The INI reader, `IniCollection::FUN_00c44280` in `blk_00c40000_od.cpp`,
  writes through a class of its unit's own whose value the compiler puts
  at 8 (its class starts with an int, and the value's 8-byte alignment
  puts it at 8; this agrees with the shared layout but is not independent
  evidence of it), the offset the repaired accessor reads. Its values
  would not reach the accessor's readers; whether the reader is handed
  these objects was not traced.
- `iNumHWThreads:General` (`g_011c3ea4`) is on the boot path. WinMain
  (`0x0086a850`, `main.cpp`) writes the processor count into it and then
  2 when the count is 1 (WinMain's three writes, through the old form),
  and reads it at four; the main loop (`0x0086e650`) reads it seven
  times. `main.cpp` also reads `iFileLogging:MESSAGES`, `iFPSClamp:General`,
  `iActorShadowCountExt:Display`, `iActorShadowCountInt:Display`,
  `uGridsToLoad:General` and the three `iRetain...:Archive` settings this
  way. These calls are tabled; the moved readers of `g_011c3ea4` in
  `aitaskmanager.cpp`, `processlists.cpp`, `tes.cpp`, `tesobjectcell.cpp`
  and eight other units now read the value at 8.

## Not changed: other reads 4 bytes into a setting

The archive has 22 more relocations that address a setting global 4 bytes
in, in 9 members. They read through a class or a function of the unit's
own, not through this accessor:

| Member | Functions | Settings |
| --- | --- | --- |
| `bsaudiomanager.cpp` | `Owner::AddSound`, `MgrX::FUN_00ad9640` | `g_011f6ec8`, `g_011f6ed4`, `g_011f6d9c` |
| `bsgamesound.cpp` | `C::SetWindow` | `g_011f6d9c` |
| `debugtext.cpp` | `LayoutObject::UpdateLayoutPositions`, two more | `g_011debac`, `g_011deec0`, `g_011f33c8` |
| `extradatalist.cpp` | `FUN_006463e0` | `originalRuntimeFloatSetting594` |
| `bstempeffectdebris.cpp` | `~FUN_00682f40` | `g_011c3ea4`, through `0x00683480` and `0x006834a0` |
| `blk_00a20000_od.cpp` | `Mgr::FUN_00a22660` | `g_011f35d0`, `g_011f35dc`, `g_011f35e8` |
| `blk_00ae0000_od.cpp` | `FUN_00aec530`, `AF1430::FUN_00af1430` | `g_011f7154`, `g_011f7130`, `g_011f713c` |
| `blk_00c40000_od.cpp` | `C52020Obj::FUN_00c52020` | `g_01203144` |
| `blk_00ec0000_od.cpp` | `MoviePlayerA::FUN_00ec2760` | `g_0126fac8` |

The float accessor `FUN_00403e20` (`0x00403e20`, `extradatalist.cpp`) has
the same body on floats, `pThis[1]`. The archive holds 2,315 calls of it in
201 members; 2,128 pass a global that the archive defines under the name
of a setting class. These calls are not classified further here. It is the
same repair at another address.

## Checks

- `objects.setting_value_accessor` disassembles the accessor from the
  archive. It fails when it adds 4 to the setting's address, or adds no 8,
  and when no member or more than one defines the new name. A build of
  `magicitem.cpp` with the old body under the new name fails it.
- `objects.setting_value_accessor_callers` (`tools/function-relocations`,
  `setting-value-accessor.tsv`) forbids the old form in eight callers and
  requires the new one: three readers of `g_011c3ea4` and one caller for
  each other argument form. It fails on the objects of 64f08c9d9.
- No host test compiles `magicitem.cpp` or a caller, so no test runs the
  accessor.

## Measured

Link cells with `user32.lib` and without, ordinary and unlimited, lazy and
forced: the same lists as at 64f08c9d9 but one name. The forced unlimited
cells gain `int & __cdecl FUN_0043d4d0(int *)` as undefined: 35,030 to
35,031 with `user32.lib`, 35,070 to 35,071 without. The rise is
deliberate: the old name is what the tabled calls refer to, and no object
defines it. The entry link rooted at WinMain gains the same name (34,755
to 34,756 undefined), and so does its member model (34,764 to 34,765
unresolved). The projected model's unresolved names are unchanged; its
aliased names go from 13,430 to 13,431. Duplicates 0, imports, the
archive's members and their order are unchanged. The new name has one
definition, in `magicitem.cpp.obj`.

Per name, over every definition in the archive and in FalloutNV's link
inputs: the old name leaves, the new one enters with one definition, and
219 definitions change their content hash, each still one variant in the
same member. With the new name read as the old one, two definitions change:
the accessor and `FUN_004a9050`. The names with differing definitions stay
519 in the archive and 521 in the link inputs, the same names.

## Remainder

Each part stays open; tickets follow.

- `main.cpp`: 41 calls, among them WinMain's S6 and S8, the writes of the
  processor count (docs/data-pack-startup.md).
- The 10 units that define a `::Setting` of their own: 109 calls.
- The 11 units' own copies of generated classes: 89 calls, 63 names.
- 16 calls on 1-byte objects, among them those on the objects at
  `0x011c3c90` and `0x011cf788`, which need an owner.
- 31 calls whose argument is not a global.
- The float accessor `FUN_00403e20`: 2,315 calls in 201 members, the same
  body on floats.
- 22 direct reads 4 bytes into a setting, in 9 members.
- A standing check that only the listed members refer to the old name (31
  members at 64f08c9d9 with this change).
