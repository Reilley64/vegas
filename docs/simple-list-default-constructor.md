# The list default constructor, emitted for eight element types

VEGAS-17 owns the `bscore` units. No repair-family ticket names these
symbols. This change is bounded: the default constructor of `BSSimpleList`,
which `src/bscore/bssimplelist_h_unit.cpp` owns, is now emitted for eight
element types instead of one. Everything else is listed under "Not covered".

## The function

| Address | Function | Recipe size |
| --- | --- | --- |
| `0x0096a2d0` | `BSSimpleList<T>::BSSimpleList()` | 33 |

The body sets the item and the next pointer to null. The original linker
folded the constructors of every pointer list into this one address. This is
the recovered behaviour and it is unchanged.

## What the recipe says

The recipe has one function row at `0x0096a2d0`, in
`src/bscore/bssimplelist_h_unit.cpp`. The row's name is a stand-in,
`fnv_00722f60::SL::SL()`. The unit's header `bssimplelist.inl` holds the body
as the template member, with the address tag.

The recipe's symbol rows bind 125 names to the address. Among them are the
template's own name for many element types, such as
`BSSimpleList<Actor*>::BSSimpleList()` in six units.

`src/bscore/bssimplelist.cpp` holds a second copy of the template body with
the same tag. It has no function row at this address.

## Why no object emitted it

A template member is emitted only for the element types a unit instantiates.
The owning unit instantiated the whole class for one type,
`InventoryStackRecord*`. Other units construct lists of other types from
their own declaration of the template, which has no body, so each requires a
constructor that no object defines.

At 6df85ec36, the commit this change was made on, 127 undefined names were
bound to this address. Of these, 25 are the template's own name with some
element type.

## The change

The owning unit now instantiates the constructor for the eight element types
that it already declares and that another unit constructs: `Actor*`,
`BGSHeadPart*`, `TESBoundObject*`, `TESObjectREFR*`, `TESTopic*`, `Tile*`,
`void*` and `const char*`. The eight lines are at the end of the unit, after
its own declarations of those classes. Nothing else changed.

`build/units.json` is unchanged: no name in it changed.

## Measured links

Windows-x64, 2,223 archive members in the same order before and after. One
object differs, `bssimplelist_h_unit.cpp.obj`: it gains eight definitions and
requires nothing new. The links were measured together with the inline body
change (`docs/inline-recipe-bodies.md`); its table gives the totals. Eight of
the 18 undefined names that leave are from this change, and none enters:
`BSSimpleList<T>::BSSimpleList()` for the eight element types above.

Each new definition is select-any, 10 bytes, with no relocation, and all
eight have the same bytes. Each name has one definition in the archive.

## Requirers

From the objects of the windows-x64 build, before and after:

| Element type | Objects that require the constructor |
| --- | --- |
| `Actor*` | 6: `aitaskmanager`, `alarmpackage`, `highprocess`, `processlists`, `bsfacegenanimationdata`, `tesobjectdoor` |
| `const char*` | 5: `magiccaster`, `tesidlemanager`, `tesnpc`, `tesscriptfunctions`, `testerrainlodmanager` |
| `BGSHeadPart*` | 3: `bsconsolefilecache`, `bgsheadpart`, `tesnpc` |
| `TESObjectREFR*` | 3: `actor`, `mapmenu`, `tesobjectcell` |
| `TESTopic*` | 3: `playercharacter`, `dialogmenu`, `testopicinfo` |
| `void*` | 3: `levelupmenu`, `extradatalist`, `extradataobjects` |
| `TESBoundObject*` | 2: `lowprocess`, `inventorymenu` |
| `Tile*` | 2: `mapmenu`, `statsmenu_h_unit` |

These are 25 distinct objects. Each declares the template itself. The
windows-x64 body writes 16 bytes: an 8-byte item and an 8-byte next pointer.
In 24 of the 25 objects the declaration is those two members, 16 bytes. In
`bsfacegenanimationdata.cpp` it is two `int` members, 8 bytes, so the
constructor would write 8 bytes past a list that unit declares.

No test names the constructor.

## Programs

- The game executable loads archive members on demand. It loads neither the
  owning unit nor any of the 25 requirers, before and after.
- Of the 55 test programs, 54 link, and none loads the owning unit or a
  requirer.
- The worker-pool test does not link. Forced, with every section kept, each
  of the eight names binds to `bssimplelist_h_unit.cpp.obj`.

So no linking program reaches these bodies. No test is added: the owning unit
requires names the archive does not define, so it cannot be linked into a
test.

## Not covered

These were open before this change and remain open.

- 119 undefined names are still bound to the address. 17 are the template's
  own name with an element type the owning unit does not declare:
  `LitWaterRef*`, `fnv_008ad1c0::MoveActor454*`, `TeammateEntry*`,
  `BSSimpleList<MenuTopic*>*`, `CombatAction*`, `ExtraDataList*`,
  `FactionReaction*`, `FileEntry*`, `MenuTopic*`, `MobileObject*`,
  `PaddedFloatRecord*`, `SkySound*`, `SoundDescriptor*`, `SoundListEntry*`,
  `TESCaravanCard*`, `TESQuest*` and `TESTopicInfo*`. Emitting them here
  would mean declaring other units' classes in this unit. The other 102 are
  constructors of other classes, which is naming work.
- The template is declared separately in 251 files. The constructor belongs
  with one shared definition that the requiring units include, so that each
  instantiates it for its own types.
- More list constructors are undefined that the partition does not bind to
  this address, because the requiring unit has no symbol row for them, such
  as `BSSimpleList<TESForm*>::BSSimpleList()`. They were not touched.
- The 8-byte list in `bsfacegenanimationdata.cpp` above.
- `bssimplelist.cpp` still holds the second copy of the body. Both it and the
  owning unit emit the class for `InventoryStackRecord*`. Their two
  destructors for that type are written differently.
- Nothing executes these functions.
