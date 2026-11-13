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
  The units stay on their copy. VEGAS-117 removed the copies of
  `beamprojectile.cpp`, `computersmenu.cpp` and `explosion.cpp`, which had
  no members; see "Units with a `Setting` of their own" at the end.
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
- **`main.cpp`.** Its 41 calls stayed for the owner of that unit. 26 of
  them are on `g_011c3ea4`, the processor count, among them WinMain's three
  writes. VEGAS-115 moved all 41 (see "main.cpp" below).

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
  2 when the count is 1 (WinMain's three writes, through the old form until VEGAS-115),
  and reads it at four; the main loop (`0x0086e650`) reads it seven
  times. `main.cpp` also reads `iFileLogging:MESSAGES`, `iFPSClamp:General`,
  `iActorShadowCountExt:Display`, `iActorShadowCountInt:Display`,
  `uGridsToLoad:General` and the three `iRetain...:Archive` settings this
  way. VEGAS-111 tabled these calls and VEGAS-115 moved them; the moved
  readers of `g_011c3ea4` in
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
of a setting class. VEGAS-116 repairs it the same way; see "The float
accessor" below. That change also repairs the `extradatalist.cpp` row of
the table: 21 of these relocations remain, in 8 members.

## Checks

- `objects.setting_value_accessor` disassembles the accessor from the
  archive. It fails when it adds 4 to the setting's address, or adds no 8,
  and when no member or more than one defines the new name. A build of
  `magicitem.cpp` with the old body under the new name fails it.
- `objects.setting_value_accessor_callers` (`tools/function-relocations`,
  `setting-value-accessor.tsv`) forbids the old form in eight callers and
  requires the new one: three readers of `g_011c3ea4` and one caller for
  each other argument form. It fails on the objects of 64f08c9d9. Its
  batch `main` (VEGAS-115) adds the 14 functions of `main.cpp` that call
  the accessor.
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

## main.cpp

VEGAS-115, measured on the windows-x64 cross build of 142e4676c and of the
two code commits, built from one source path. Nothing was run. `main.cpp`'s 41 calls, classified by the
rule above, all take the shared `Setting`. The first commit moved 40. The
41st moved in a second commit, once `main.cpp`'s own copy of a generated
class was removed:

| Class | Calls |
| --- | --- |
| Moved: a global that generated data defines as a setting of the shared class | 41 |

`main.cpp` defines no `::Setting` of its own. At its end it sees only the
declaration that `include/fnv/symbols_0043d000.h` gives the shared class,
which is incomplete there. Its own types for these globals are the targets of the
`reinterpret_cast` inside each argument, and they are not changed. Most are
empty: the namespaced copies of `GlobalObject2_0040c150` and
`GlobalObject_0045cfe0`, `Setting86`, `InitSetting`, `ShadowIntSetting` and
`Options86`. Two have fields of their own, `FrameUpdate::Service` (the main
loop's seven calls) and `fnv_00873200::ViewNode` (one call). No call reads a
field through them: only the address is passed on. A moved call's conversion to `int *` becomes a
conversion to `::Setting *`. The address is the same. The first 40 calls
pass 11 globals, each defined in
`src/generated/global_object_initializers.cpp` as a
`GlobalObject_0045cfe0` or a `GlobalObject_004a4a40`. The compiler lays out
both there at 24 bytes, with `uValue` at 8. The 41st passes `g_011d10d4`,
defined in `src/generated/global_object_initializers2.cpp` as a
`GlobalObject2_0040c150`. The compiler lays out that class there at 24
bytes with `uValue` at 8, and at 12 bytes with `uValue` at 4 in the i686
compile, the same offsets as `Setting` in that unit.

| Setting | Global | Reads | Writes |
| --- | --- | --- | --- |
| `iNumHWThreads:General` | `g_011c3ea4` | 23 | 3 |
| `uGridsToLoad:General` | `g_011c63cc` | 2 | |
| `iActorShadowCountInt:Display` | `g_011c72d8` | 2 | |
| `iActorShadowCountExt:Display` | `g_011c72e4` | 2 | |
| `iTake:CameraPath` | `g_011deecc` | 2 | |
| `iActivatePickLength` | `g_011d10d4` | 1 | |
| `iRetainFilenameStringTable:Archive` | `g_011deaa0` | 1 | |
| `iRetainDirectoryStringTable:Archive` | `g_011deb24` | 1 | |
| `iRetainFilenameOffsetTable:Archive` | `g_011dec40` | 1 | |
| `iFPS:CameraPath` | `g_011dee00` | 1 | |
| `iFPSClamp:General` | `g_011dee60` | 1 | |
| `iFileLogging:MESSAGES` | `g_011dee6c` | 1 | |

The three writes are WinMain's (`0x0086a850`). S6 of
docs/data-pack-startup.md writes the processor count, S8 writes 2 when it
is 1, and a statement after the second-window check does the same again.
WinMain reads the processor count four times, and the main loop
(`0x0086e650`) reads it seven times.

The 41st call is in `0x0086f6a0`. It passes `iActivatePickLength`,
`g_011d10d4`, to `TaskQueueInterface::ThreadProcessInput`. `main.cpp`
defined an empty `struct GlobalObject2_0040c150` at global scope, and
generated data defines the class of that name with the class-key `class`.
So `main.cpp`'s object referred to
`?g_011d10d4@@3UGlobalObject2_0040c150@@A`, which no object defines, and
the first commit left the call on the old form, the case of the 89 calls
above. The second commit removes the struct, as VEGAS-117 prescribes for a
unit's own copy of a generated class. `main.cpp` then sees only the
declaration of the generated class that its symbol headers give, so its
object refers to the `V` spelling, which
`global_object_initializers2.cpp.obj` defines and `main.cpp`'s recipe key
already spelled. The class's ten other uses at global scope in `main.cpp`
are targets of an existing `reinterpret_cast` of the address of
`g_011c3ea4`. They compile against the declaration with no cast added. The
class is incomplete in `main.cpp`, so no layout of it is used there. The
four namespaced copies of the name are not changed. On windows-x64 and in
the i686 compile, every class layout of `main.cpp` is the same apart from
the removed struct.

In the first commit `main.cpp`'s recipe kept its two keys of the old name,
`YA` and `YI`, and gained the new name beside each in the same spelling.
The second commit removes both old keys, so the new keys remain.

At the unit's flags, with `/Ob0` and with `/Od /Gy`, no instruction
changes in either commit:

- First commit: with the old name respelled as the new one in the base
  object, the objects differ at one site: the 41st call's relocation in
  `0x0086f6a0` still targets the old name, so the old name stays an
  undefined symbol beside the new one. With `/Od /Gy` the address significance
  table also lists the added name. The moved calls are in 14 functions;
  in `0x0086f6a0` two of its three calls moved.
- Second commit: two relocations in `0x0086f6a0` change target, from the
  `U` spelling of `g_011d10d4` to the `V` spelling and from the old form
  to the new one. The undefined symbols of the old form and of the `U`
  spelling leave the object, and the `V` spelling enters. The address
  significance table names the `V` spelling in place of the `U` one, and
  with `/Od /Gy` it no longer lists the old form.

`setting-value-accessor.tsv`'s batch `main` lists all 14 functions. It
fails on the objects of 142e4676c, and for `0x0086f6a0` on those of the
first commit.

The link cells with `user32.lib` and without have the same lists at
142e4676c and after each commit. The forced unlimited cell with
`user32.lib` has 35,031 undefined names throughout, the old name among
them. 31 members referred to it at 142e4676c, with 283 relocations; 31
with 245 after the first commit; 30 with 244 after the second, and
`main.cpp` is no longer among them. The `U` spelling of `g_011d10d4` stays
undefined too, because `actor.cpp` refers to it. The entry link rooted at
WinMain has 34,756 undefined names throughout and loads the same members.
After the first commit it loads `magicitem.cpp.obj` earlier, for the new
name that WinMain now calls. So the section model of that link takes nine
select-any sections from `magicitem.cpp.obj` instead of from other
members: six RTTI type descriptors and three string literals. Each of the
nine names has one content in all of its definitions, and none of the 30
names that `magicitem.cpp.obj` defines has more than one. After the second
commit the section model has one unresolved name fewer, 10,912 to 10,911:
the `U` spelling of `g_011d10d4`, which `0x0086f6a0` no longer reaches. No
section changes member. No program that links today contains
`main.cpp.obj` or `magicitem.cpp.obj`: the lazy link of FalloutNV.exe's
inputs loads 24 members of the game archive, neither of them.

## Remainder

Each part stays open under the ticket named with it. `main.cpp` is done:
41 of its 41 calls take the shared `Setting` (VEGAS-115).

- VEGAS-117, the other 245 calls and a guard:
  - The 7 units that define a `::Setting` of their own: 88 calls, since
    VEGAS-117 moved the 21 calls of three units (109 in 10 before; see
    "Units with a `Setting` of their own").
  - The 11 units' own copies of generated classes: 89 calls, 63 names.
  - 16 calls on 1-byte objects, among them those on the objects at
    `0x011c3c90` and `0x011cf788`, which need an owner.
  - 31 calls whose argument is not a global.
  - A standing check that only the listed members refer to the old name
    (30 members after VEGAS-115, `main.cpp` no longer among them; 27 since
    VEGAS-117's three units moved).
- The float accessor `FUN_00403e20`: repaired by VEGAS-116; its own
  remainder is listed under "The float accessor".
- VEGAS-118: 21 direct reads 4 bytes into a setting, in 8 members, since
  VEGAS-116 (22 in 9 before it).

## The float accessor (VEGAS-116)

The recipe has one function row at `0x00403e20`, 54 bytes, in
`src/fallout_shared/extradatalist.cpp`: `FUN_00403e20`. It returns a
reference to a setting's float value, or to `DAT_01202800`, set to zero,
when it is given null. The archive holds 2,315 calls of it in 201 members;
the tree has 2,359 free calls of it in 202 files.

Everything in this section was measured on the windows-x64 cross build of
d586c94f0 and of the code commit, built from one source path. Nothing was
run on Windows.

### The defect

The body was `return pThis ? pThis[1] : ...` with `float* pThis`, the int
accessor's body on floats. In the object of `extradatalist.cpp` it adds 4 to
the setting's address (`addq $0x4, %rax`). The settings that the moved
calls pass are objects of the shared `Setting`, 24 bytes with `uValue` at
8, measured in the unit that defines each of their classes. As built for
windows-x64, a read through the accessor of such a setting would return
bytes 4 to 7 of the setting, the upper half of its table pointer, as a
float, and a write would overwrite them. No program that links today
contains the accessor or a caller: the lazy link of FalloutNV.exe's inputs
with `user32.lib` at d586c94f0 loads 24 members of the game archive, none
of them one of the 202 members that define or call the accessor. Nothing
was run.

### The change

The accessor takes the shared `Setting`, from `include/fnv/setting_class.h`,
which `extradatalist.cpp` now includes, and returns `pThis->uValue.f`. In
its object one instruction changes, `addq $0x4, %rax` to
`addq $0x8, %rax`. Its windows-x64 name becomes
`?FUN_00403e20@@YAAEAMPEAVSetting@@@Z`, with one definition, in
`extradatalist.cpp.obj`, as the old name had. The recipe row becomes
`?FUN_00403e20@@YAAAMPAVSetting@@@Z`, at the same address, size and unit.

`include/fnv/symbols_00403000.h` declares both forms. The `float *` form has
no definition; the calls that this change does not move stay on it, so
none of them reaches the repaired body.

In the same unit `FUN_006463e0` multiplies its argument by
`originalRuntimeFloatSetting594`, a generated
`SettingT<GameSettingCollection>`, through the accessor, which the compiler
inlines there as one load. The load now reads the setting 8 bytes in
instead of 4: `mulss 0x4(%rip)` becomes `mulss 0x8(%rip)` against the same
relocation. It is the `extradatalist.cpp` row of the table under "Not
changed".

### The calls

Every free call of the accessor in the tree, classified by its argument
with the int accessor's rules. A global's identity is the name the unit's
object refers to, followed through the `/alternatename` pragmas to the
archive's definition, and the class of that definition is measured in the
unit that defines it.

| Class | Calls | Files |
| --- | --- | --- |
| Moved: a global that generated data defines as a setting of the shared class, in a unit that can name the shared `Setting` | 1,845 | 173 |
| Tabled: the unit defines a `::Setting` of its own | 345 | 15 |
| Tabled: no object defines the name | 68 | 16 |
| Tabled: the global is a 1-byte object of a class of the unit's own | 36 | 10 |
| Tabled: the argument is not a global | 32 | 12 |
| Tabled: `src/fallout/misc/main.cpp` | 13 | 1 |
| Not decided: kinds the int accessor's calls did not have | 20 | 9 |

A moved call's conversion of its argument to `float *` becomes a
conversion to `::Setting *`. The address is the same. Every moved unit's
object is the same as before once the accessor's name is respelled, apart
from `extradatalist.cpp`, whose two changed functions are described above.
21 units call both forms; their objects gain that one undefined symbol.

The recipe entries of the 173 units respell each key of the old name, in
its two spellings, or add the new key beside it in the 25 units that keep
a call on the old form: 334 keys, 294 once the entries of a source are
merged.

57 sources keep a key of the old name (119 keys, 94 merged) at
`0x00403e20`. 50 of them are the units whose objects call the old form.
Four, `actor_magic.cpp`, `projectile.cpp`, `forenderedmenuracesex.cpp` and
`tesobjectweap.cpp`, keep calls on the old form that the windows-x64 build
emits no code for. The other three, `actor_h_unit.cpp`,
`water_record_converters.cpp` and `clamped_acos.cpp`, had the key before
this change and their objects refer to neither form. As for the int accessor, a key records where the call
went in the original; it is not a definition, and nothing may bind the old
name to the new body.

### Moved calls to note

- 76 moved calls, in 7 files, are established only through `/alternatename`
  pragmas in `src/generated/data`. 34 pass the global under another name:
  12 in `playercharacter.cpp` (lines 1891 to 1923), 11 in
  `hudmainmenu.cpp`, all on `g_011d9774` (`fHudOpacity:Interface`) through
  `DAT_011d9774`, `xsLockAlpha` and `ammoSetting`, 4 in
  `interfacemanager.cpp` and 7 in `blk_00640000_od.cpp`. 42 pass it under
  its own name with another class-key or inside a namespace: 16 in
  `teswater.cpp`, 11 in `blk_00640000_od.cpp`, 7 in `hudmainmenu.cpp`, 4 in
  `interfacemanager.cpp`, 2 in `bstreemodel.cpp` and 2 in
  `blk_00600000_od.cpp`.
- `blk_00640000_od.cpp` line 7825 adds two settings through `DAT_011cf264`
  and `DAT_011cfb5c`. The unit's recipe keys give each name the other's
  address, and the pragmas at lines 5 and 6 of
  `src/generated/data/staging/blk_00640000_od.inc` follow the keys: the
  names reach `g_011cfb5c` (`fDamageGunWeapCondBase`) and `g_011cf264`
  (`fDamageGunWeapCondMult`). Both are `GlobalObject_0040e0b0`, so the
  offset is right for both, the sum is the same either way, and the moved
  call passes the addresses it passed before. Whether the source's names or
  the keys are wrong is not decided here.

### Tabled calls

- **A `::Setting` of the unit's own.** `actor.cpp` (132 calls),
  `highprocess.cpp` (101), `renderer.cpp` (22), `telekinesiseffect.cpp`
  (19), `blk_00940000_od.cpp` (17), `combatcontroller.cpp` (10),
  `explosion.cpp`, `magicfogprojectile.cpp` (9 each), `character.cpp` (7),
  `package.cpp`, `tesreputation.cpp` (5 each), `itemmodmenu.cpp` (3),
  `interface.cpp`, `sleepwaitmenu.cpp` and `bgsterminal.cpp` (2 each). The
  unit's declaration of the new form would name that class, not the shared
  one. The units stay on their copy. VEGAS-122 removed the copies of
  `blk_00940000_od.cpp`, `explosion.cpp`, `magicfogprojectile.cpp`,
  `character.cpp`, `sleepwaitmenu.cpp` and `bgsterminal.cpp`, which had no
  members; see "Units with a `Setting` of their own" at the end.
- **No object defines the name.** 62 names in 16 units. The unit declares
  `GlobalObject_0044f440` (47 calls) or `GlobalObject_0040e0b0` (21) with
  the class-key `struct`, and generated data defines the class with
  `class`, so the unit's name for the global differs from the defined one.
- **A 1-byte object.** The global the unit refers to is defined, in the
  calling unit or another, as a 1-byte object of a class of the defining
  unit's own. The calls are in
  `actor.cpp`, `mobileobject.cpp`, `startmenu.cpp`, `renderer.cpp`,
  `bstreemodel.cpp`, `testerrainlodmanager.cpp`, `blk_00640000_od.cpp`,
  `blk_006e0000_od.cpp`, `blk_00c60000_o2.cpp` and `blk_00c60000_od.cpp`.
  Neither the old offset nor the new one is inside these objects. Six of
  the calls write, in `startmenu.cpp` (lines 2152, 2186, 2220, 3579, 3625
  and 3670); each would write 4 bytes outside its object.
- **Not a global.** The evidence that the pointer is a setting is missing:
  21 elements of tables of setting pointers (`aiformulas.cpp`,
  `combatformulas.cpp`, `bgsentrypointfunction.cpp`, `bgssceneinfo.cpp`,
  `tesfurniture.cpp`, `extradataobjects.cpp`, `taskqueueinterface.cpp`,
  `tesreputation.cpp`, `blk_00980000_od.cpp`), 4 fields of a slot in
  `aiformulas.cpp`, 6 parameters or locals (`tesscriptfunctions.cpp` 5,
  `interface.cpp` 1) and `this` in `blk_00440000_od.cpp`.
- **`main.cpp`.** Its 13 calls stayed for the owner of that unit. All read:
  `fHavokTauRatio`, `fAnimationMult:General`, nine `fLODFadeOut...:LOD`
  settings, `fScopeScissorAmount:Display` and `fLODLandDropAmount:LOD`.
  Each argument is a global that generated data defines as a setting of
  the shared class. VEGAS-122 moved all 13 (see "main.cpp (VEGAS-122)"
  below).

### Not decided

These kinds did not occur among the int accessor's calls. Their calls stay
on the old form and nothing here decides them.

- 15 calls for which the compiler emits no code, in `combatgroup.cpp` (8,
  on `originalRuntimeFloatSetting106`), `actor_magic.cpp` (2),
  `forenderedmenuracesex.cpp` (2), `explosion.cpp`, `projectile.cpp` and
  `tesobjectweap.cpp` (1 each). The windows-x64 object, built at `/O2`,
  does not refer to the global. Compiled at `/Od /Gy`, the optimisation
  level of these units' recipe entries, each object refers to it, and each
  is a setting that generated data defines with the shared class. No unit
  has another call on the same global, so the calls stay on the old form
  here and their units keep the old key; `explosion.cpp`'s stayed with that
  unit's own `::Setting`, and since that copy went it stays on the old form
  as an undecided call.
- 1 call in a header, `highprocess.h` line 488, on
  `originalRuntimeFloatSetting244`. One unit compiles the header,
  `highprocess_h_unit.cpp`; its object calls the old form there once, in
  `HighProcess::StopAllActorSounds`, with the address of the generated
  `SettingT<GameSettingCollection>`. The call meets the rule for a moved
  call and stays on the old form in this change.
- 2 calls on a 4-byte object of a class of the unit's own:
  `bstreemanager.cpp` lines 285 and 293, `DAT_011f9158`.
- 2 calls on a function-local static of a class of the unit's own:
  `teswater.cpp` lines 12823 and 12825, `s_kAlpha` in `FUN_004e7770`.
- Outside the free calls: two member functions of classes of a unit's own
  carry recipe keys at `0x00403e20`,
  `SettingT<GameSettingCollection>::FUN_00403e20()` in the entry of
  `magiccaster.cpp` and `SettingT_GameSettingCollection_::Float()` in the
  entry of `actor.cpp`. They are called at `magiccaster.cpp` line 4908 and
  at `actor.h` lines 399 to 404; the objects of `magiccaster.cpp` and
  `actor_h_unit.cpp` refer to them once each, and no object defines them.

### What the settings were

From the source and the objects; nothing was run.

- 1,844 of the moved calls read and one writes: `0x007d2eb0`
  (`startmenu.cpp` line 975) stores `fMouseSensitivity:Controls`
  (`g_011e0a6c`), which eight moved calls read. Before this change it
  would have written into the upper half of that setting's table pointer.
- The most read settings among the moved calls are
  `fHudOpacity:Interface` (19 calls), `fSneakMaxDistance` (15),
  `g_01203150` (14; generated data gives it 75.0 and the key string
  `s_010c289c`), `fCollisionSoundHeavyThreshold:Audio` (13),
  `fWadingWaterQuadSize:Water` and `fProjectileDebugDuration:Combat` (11
  each). On windows-x64 each read would return half of a table pointer as a
  float, a value that depends on where the executable is loaded and that
  no constructor, INI file or game setting sets.

### Checks

- `objects.float_setting_accessor` disassembles the accessor from the
  archive. It fails when it adds 4 to the setting's address, or adds no 8,
  and when no member or more than one defines the new name. A build of
  `extradatalist.cpp` with the old body under the new name fails it, and so
  does the archive of d586c94f0.
- `objects.float_setting_accessor_callers` (`tools/function-relocations`,
  `float-setting-accessor.tsv`) forbids the old form in eight callers and
  requires the new one: three readers of `g_011d9774` and one caller for
  each other argument form. It fails on the objects of d586c94f0.
- No host test compiles `extradatalist.cpp` or a caller, so no test runs
  the accessor.

### Measured

Link cells with `user32.lib` and without, ordinary and unlimited, lazy and
forced: the same lists as at d586c94f0 but one name. The forced unlimited
cells gain `float & __cdecl FUN_00403e20(float *)` as undefined: 35,030 to
35,031 with `user32.lib`, 35,070 to 35,071 without. The forced ordinary
cells, which stop at 20 names, list it among their 20. The rise is
deliberate: the old name is what the tabled calls refer to, and no object
defines it. The entry link rooted at WinMain gains the same name (34,755
to 34,756 undefined), and so does its member model (34,764 to 34,765
unresolved). The projected model's unresolved names are unchanged (7,540);
its aliased names go from 13,430 to 13,431. Duplicates 0, imports, the
archive's members and their order are unchanged.

Per name, over every definition in the archive and in FalloutNV's link
inputs: the old name leaves, the new one enters with one definition in the
same member, and 600 definitions change their content hash, each still one
variant in the same member with the same selection. With the new name
read as the old one, two definitions change: the accessor and
`FUN_006463e0`. The names with differing definitions stay 519 in the
archive and 521 in the link inputs, the same names.

### main.cpp (VEGAS-122)

Measured on the windows-x64 cross build of 4567abc37 and of the code
commit, built from one source path. Nothing was run. `main.cpp`'s 13 calls,
classified by the rule above, all take the shared `Setting`:

| Class | Calls |
| --- | --- |
| Moved: a global that generated data defines as a setting of the shared class | 13 |

`main.cpp`'s object refers to each argument under the name that one object
of the archive defines, with no `/alternatename` pragma between them. One
is `originalRuntimeFloatSetting807`, a `SettingT<GameSettingCollection>`
defined in `src/generated/setting_float_initializers.cpp`; twelve are
`GlobalObject_0044f440`, defined in
`src/generated/global_object_initializers.cpp`. Measured in those two
units, both classes derive from `Setting` of `include/fnv/setting_class.h`
and are 24 bytes with `uValue` at 8, and 12 bytes with `uValue` at 4 in the
i686 compile. `main.cpp` defines no `::Setting` of its own and sees the
declaration that `include/fnv/symbols_00403000.h` gives the shared class.
Its own types inside each argument, the empty structs `SetA`,
`SettingFloat` and two `SettingView`, are only the targets of the existing
`reinterpret_cast` of the address, and they are not changed. A moved
call's conversion of its argument to `float *` becomes a conversion to
`::Setting *`. The address is the same, and no cast is added.

| Setting | Global | Function | Reads |
| --- | --- | --- | --- |
| `fHavokTauRatio` | `originalRuntimeFloatSetting807` | `0x0086f260` | 1 |
| `fAnimationMult:General` | `g_011c5724` | `0x0086f260` | 1 |
| `fLODFadeOutObjectMultComplex:LOD` | `g_011dec24` | `0x0086efe0` | 1 |
| `fLODFadeOutItemMultComplex:LOD` | `g_011deb10` | `0x0086efe0` | 1 |
| `fLODFadeOutActorMultComplex:LOD` | `g_011ded8c` | `0x0086efe0` | 1 |
| `fLODFadeOutObjectMultCity:LOD` | `g_011dec7c` | `0x0086efe0` | 1 |
| `fLODFadeOutItemMultCity:LOD` | `g_011dee54` | `0x0086efe0` | 1 |
| `fLODFadeOutActorMultCity:LOD` | `g_011ded98` | `0x0086efe0` | 1 |
| `fLODFadeOutObjectMultInterior:LOD` | `g_011dea80` | `0x0086efe0` | 1 |
| `fLODFadeOutItemMultInterior:LOD` | `g_011deddc` | `0x0086efe0` | 1 |
| `fLODFadeOutActorMultInterior:LOD` | `g_011decc8` | `0x0086efe0` | 1 |
| `fScopeScissorAmount:Display` | `g_011dea8c` | `0x00870bd0` | 1 |
| `fLODLandDropAmount:LOD` | `g_011dedc8` | `0x0086d590` | 1 |

All 13 calls move, so `main.cpp`'s recipe entry respells both keys of the
old name, `YA` and `YI`, to the new name in the same spelling. 56 sources
now keep a key of the old name (117 keys, 92 merged), and 174 have a key of
the new one (336 keys, 296 merged).

At the unit's flags, with `/Ob0` and with `/Od /Gy`, the object of
`main.cpp` is the same as before once the old name is read as the new one:
no instruction changes. At the unit's flags the four functions hold 11
relocations to the accessor for the 13 calls, because the compiler shares
calls between the branches of `0x0086efe0`; all 11 now target the new
form, and the undefined symbol of the old form leaves the object.

`float-setting-accessor.tsv`'s batch `main` lists the four functions. It
fails on the objects of 4567abc37.

The link cells with `user32.lib` and without have the same lists before
and after. The forced unlimited cell with `user32.lib` has 35,031
undefined names, the old form among them: 50 members of the archive referred
to it at 4567abc37, and 49 after the change. Per name, over every
definition in the archive and in FalloutNV's link inputs, the four functions
change their content hash, each still one variant in `main.cpp.obj` with
the same selection; no name enters or leaves. The names with differing
definitions stay 519 in the archive and 521 in the link inputs, the same
names. No program that links today contains `main.cpp.obj`: the lazy link
of FalloutNV.exe's inputs loads 24 members of the game archive, not it.

### Remainder

`main.cpp` is done: 13 of its 13 calls take the shared `Setting`
(VEGAS-122). Each other part stays open.

- The 9 units that define a `::Setting` of their own: 299 calls, since
  VEGAS-122 moved the 46 calls of six units (345 in 15 before; see "Units
  with a `Setting` of their own").
- The 16 units' declarations of generated classes with the key `struct`:
  68 calls, 62 names.
- 36 calls on 1-byte objects, six of them writes.
- 32 calls whose argument is not a global.
- The kinds not decided: 15 calls without code, 1 in a header, 2 on a
  4-byte object, 2 on a function-local static, and the two member
  functions with keys at `0x00403e20`.
- The names `DAT_011cf264` and `DAT_011cfb5c` in `blk_00640000_od.cpp`,
  whose recipe keys and pragmas give each the other's address.
- A standing check that only the listed members refer to the old name (50
  members at d586c94f0 with this change; 49 since `main.cpp`'s calls
  moved; 44 since VEGAS-122's units moved).

## Units with a `Setting` of their own (VEGAS-117, VEGAS-122)

Measured on the windows-x64 cross build of 1a4404c01 and of the eight code
commits, built from one source path. Nothing was run.

19 units defined a global `::Setting` of their own, which the compiler
measures at 1 byte: the 10 of the int accessor's table and the 15 of the
float accessor's, six of them in both. A unit's declaration of an
accessor's new form named that class, so its calls stayed on the old form,
whatever their argument. What each copy declares:

| Copy | Units |
| --- | --- |
| An empty `struct Setting` | `beamprojectile.cpp`, `blk_00940000_od.cpp`, `computersmenu.cpp`, `bgsterminal.cpp`, `sleepwaitmenu.cpp`, `magicfogprojectile.cpp`, `explosion.cpp`, `character.cpp`, `itemmodmenu.cpp`, `combatcontroller.cpp`, `package.cpp`, `telekinesiseffect.cpp` |
| An empty `class Setting` | `interface.cpp` |
| `struct Setting` with a member function | `actor.cpp` (`Bool()`), `highprocess.cpp` (`Get()`), `bstempeffectsimpledecal.cpp` (`Bool()`), `tesreputation.cpp` (`FUN_00403df0()`), `tesscriptfunctions.cpp` (`FUN_005e0190(const char *)`, which the unit defines: the recipe's function row at `0x005e0190` is a member of `Setting`) |
| `include/fnv/decl/Setting.h`, a `struct Setting` with `FUN_005e0190(const char *)` | `renderer.cpp`, the one unit that includes it |

Each unit calls the members of its copy at least once. The shared
`Setting` has none of them, so these six units stay on their copy: whether
the shared class takes those members is a naming decision.

### The change

Eight units with an empty copy moved, one commit each, as VEGAS-115 removed
`main.cpp`'s copy of a generated class. The three lines of the copy go. The
unit then sees only the declaration `class Setting;` that
`include/fnv/symbols_0043d000.h` and `include/fnv/symbols_00403000.h` give
the shared class, beside the accessors' new forms. Each other use of the
name in these units is the target of an existing `reinterpret_cast` of an
address, and compiles against the declaration with no cast added: the class
is incomplete there, so no layout of it is used. On windows-x64 and in the
i686 compile, every record layout of each unit is the same as before apart
from the removed copy.

The calls were then classified by the rule above, with the unit's object
of the base for each global's identity. A moved call's conversion of its
argument to `int *` or `float *` becomes a conversion to `::Setting *`; the
address is the same.

| Unit | int calls moved | float calls moved | Kept on the old form |
| --- | --- | --- | --- |
| `beamprojectile.cpp` | 2 | | |
| `blk_00940000_od.cpp` | | 17 | |
| `computersmenu.cpp` | 9 | | |
| `bgsterminal.cpp` | | 2 | 5 float |
| `sleepwaitmenu.cpp` | | 2 | |
| `magicfogprojectile.cpp` | | 9 | |
| `explosion.cpp` | 10 | 9 | 1 float |
| `character.cpp` | | 7 | |
| Total | 21 | 46 | 6 |

Each moved call passes a global that generated data defines as a setting
of the shared class (`GlobalObject2_0040c150`, `GlobalObject_0040e0b0`,
`GlobalObject_0044f440`, `Setting_01017720_011f96a0` or
`SettingT<GameSettingCollection>`), each measured at 24 bytes with
`uValue` at 8 in the unit that defines it. All read; none writes.

The six kept calls:

- `bgsterminal.cpp`, five calls in `0x005017a0`, on the five
  `fHackingMinSkill...:Hacking` settings. The unit names their globals
  through a struct of its own, `GlobalObject_0044f440`, which generated data
  defines with the class-key `class`, so no object defines the names the
  unit refers to: the case "No object defines the name".
- `explosion.cpp`, one call in `0x009ae6e0` on
  `fGunParticleCameraDistance`, for which the windows-x64 build emits no
  code: a kind not decided (see "Not decided").

Recipe: in the units whose object no longer refers to an old form, every
key of it, `YA` and `YI`, is respelled to the new form. `bgsterminal.cpp`
keeps its old float key and gains the new one beside it. `explosion.cpp`
respells its six old int keys and keeps its four old float keys with the
new key beside each, as the units of the not-decided calls do. Old int keys
go from 63 (49 merged, 30 sources) to 53 (43 merged, 27 sources), new int
keys from 184 (171) to 194 (177). Old float keys go from 117 (92 merged, 56
sources) to 105 (84 merged, 52 sources), new float keys from 336 (296) to
353 (307).

### Object proof

`tools/object-proof` at the unit's flags, with `/Ob0` and with `/Od /Gy`,
base and head compiled from one export. With each old form read as the
new one, six units are the same, at all three variants, apart from the
moved relocations' targets: the undefined symbol of an old form leaves the
object, and the new one is there instead. No instruction changes. The
mixed units:

- `bgsterminal.cpp`: the same except the expected kept sites, three at the
  unit's flags (`0x005017a0` inlined into two callers) and one with
  `/Ob0`. With `/Od /Gy` the five kept calls in `0x005017a0` come before
  the moved ones, so the address-significance table lists the new form
  later (at 125 instead of 68 once the kept sites are undone). Nothing else
  differs.
- `explosion.cpp`: the same at the unit's flags and with `/Ob0`, where the
  kept call has no code; with `/Od /Gy` the same except that one expected
  kept site.

26 functions change, by relocation targets only: each keeps one definition
in its unit, with the same selection, section and size.

### Checks

Each unit has a batch named after it in `setting-value-accessor.tsv` or
`float-setting-accessor.tsv` (both for `explosion.cpp`): the functions in
which a relocation moved and none stays on the old form. Each batch fails
on the objects of the base. `bgsterminal.cpp`'s lists `0x005011a0` only:
`ActivateTerminal` holds a kept call through inlining.

### Measured

The link cells with `user32.lib` and without have the same lists at
1a4404c01 and after each commit: 35,031 undefined names in the forced
unlimited cell with `user32.lib`, the two old forms among them, 0
duplicates, the same imports and members. No name leaves or enters. The
members that refer to the old int form go from 30 to 27, and those that
refer to the old float form from 49 to 44. The names with differing
definitions stay 519 in the archive and 521 in the link inputs, the same
names. The boot model's figures are the same. None of the eight units is
loaded by the lazy link of FalloutNV.exe's inputs.

### Not moved

- `itemmodmenu.cpp`, `combatcontroller.cpp`, `package.cpp`,
  `telekinesiseffect.cpp` (37 float and 8 int calls): empty copies, not
  reached in this change.
- `interface.cpp` (4 int and 2 float calls): its empty copy has the
  class-key `class`, so it already spells the shared class's name.
- The six units with members (above): 76 int and 260 float calls.
