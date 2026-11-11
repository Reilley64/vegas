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

Select-any means the linker will not refuse a second body for one of these
names if a unit adds one later; it keeps one and says nothing. The archive
scan for names with differing definitions is the only guard. It counts 528
such names before and after this change, and none of the eight is among
them.

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

The partition binds a requirement to the address through a symbol row of the
requiring unit. Of the 27 requirements above, 17 have a row under the
template's name at `0x0096a2d0`. Ten have none:

| Object | Element type without a row |
| --- | --- |
| `tesnpc`, `bsconsolefilecache` | `BGSHeadPart*` |
| `inventorymenu` | `TESBoundObject*` |
| `mapmenu`, `actor` | `TESObjectREFR*` |
| `playercharacter`, `testopicinfo` | `TESTopic*` |
| `statsmenu_h_unit` | `Tile*` |
| `levelupmenu`, `extradatalist` | `void*` |

Each of these ten units binds `0x0096a2d0` under another default
constructor's name: all ten under `fnv_00722f60::SL::SL()`, and
`inventorymenu` and `playercharacter` also under
`FUN_0096a2d0::FUN_0096a2d0()`. INFERENCE, not measured: the call the unit
makes under the template's name is that same call to `0x0096a2d0`.

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

`docs/shared-simple-list.md` records what a later change did about the
shared definition, the element types and the second copy.

- 119 undefined names are still bound to the address. 17 are the template's
  own name with an element type the owning unit does not declare:
  `LitWaterRef*`, `fnv_008ad1c0::MoveActor454*`, `TeammateEntry*`,
  `BSSimpleList<MenuTopic*>*`, `CombatAction*`, `ExtraDataList*`,
  `FactionReaction*`, `FileEntry*`, `MenuTopic*`, `MobileObject*`,
  `PaddedFloatRecord*`, `SkySound*`, `SoundDescriptor*`, `SoundListEntry*`,
  `TESCaravanCard*`, `TESQuest*` and `TESTopicInfo*`. Emitting them here
  would mean declaring other units' classes in this unit. The other 102 are
  constructors of other classes, which is naming work.
- The template has no shared definition. Under `src/` and `include/`, 673
  files mention `BSSimpleList`. 251 of them hold `class BSSimpleList` or
  `struct BSSimpleList` in some form, 234 hold a template declaration of the
  class, and 128 hold a body of the primary template. The constructor belongs
  with one shared definition that the requiring units include, so that each
  instantiates it for its own types.
- More list constructors are undefined that the partition does not bind to
  this address, because the requiring unit has no symbol row for them, such
  as `BSSimpleList<TESForm*>::BSSimpleList()`. They were not touched.
- The 8-byte list in `bsfacegenanimationdata.cpp` above. It must be repaired
  before any program links that unit: the constructor was undefined, so such
  a link failed, and it no longer fails on this name.
- `bssimplelist.cpp` still holds the second copy of the body. Both it and the
  owning unit emit the class for `InventoryStackRecord*`. Their two
  destructors for that type are written differently.
- Nothing executes these functions.

## Names bound to the address at b93461c52

VEGAS-72 measured every name bound to `0x0096a2d0` again, on the windows-x64
build of b93461c52 and of the VEGAS-72 head on top of it. The recipe binds
125 names to the address, in 253 symbol rows of 137 units. At b93461c52, 28
of them are defined, 2 are named by no object and 95 are undefined and
required. At the head, 30 are defined and 93 are undefined: the element
constructor of the hacking menu and the list of topic lists left (see
`docs/hacking-element-release.md` and `docs/shared-simple-list.md`).

The 93 names are required in 125 pairs of name and unit, in 62 units, at 298
construction sites. A compiler probe in each requiring unit, with the build's
own command line, measured the class the unit constructs and the smallest
storage any site gives it. The windows-x64 list body writes 16 bytes: two
8-byte words at offsets 0 and 8. The original 32-bit body at the address
writes 8 bytes: two 32-bit words.

| Family | Names |
| --- | --- |
| The stand-in name `SL`, in a namespace | 13 |
| A class named after the address, such as `FUN_0096a2d0` | 11 |
| Another class | 64 |
| Another template named after the list | 4 |
| The list template | 1 |

The storage a unit gives a class shows only whether the folded body fits.
Whether a class that fits is a list or another class folded onto the same
code needs function-level evidence in its unit, as the hacking menu element
had. The table records that evidence where the unit has it: another list
member of the class bound to a list address.

A class whose units give it two 32-bit fields has the shape of the original
body. The hacking menu element had that shape and was a distinct folded
class. So such a class is filed W, to decide whether it is a list or a
distinct class. It is not filed S, where a declaration is repaired first.

| Need | What it needs | Names |
| --- | --- | --- |
| S | A requiring unit gives the class less than 16 bytes in another shape: 4 bytes, one field, a byte or `int` array, or a base. That declaration is repaired first. | 14 |
| W | Every requiring unit that gives the class less than 16 bytes gives it two 32-bit fields at offsets 0 and 4, the shape of the original body. Decide in the unit whether it is a list or a distinct class folded here. | 19 |
| D | The class has another shape of at least 16 bytes. Decide in the unit whether it is a list with stale fields or a distinct class folded here. | 14 |
| D1 | Two pointers, 16 bytes, but no other list member is bound for the class and it has members at other addresses. Decide as for D. | 2 |
| V | The class has a virtual table pointer at offset 0, where the body writes. The binding or the declaration is wrong. | 1 |
| H | Two pointers, 16 bytes, and the unit binds other list members of the class, evidence that it is a list. The unit holds objects of the stand-in, which the stand-in rule of `docs/shared-simple-list.md` refuses. It needs a rule that admits such a stand-in. | 29 |
| H1 | As H, but no other list member is bound for the class. | 9 |
| T | The unit declares its own template: it moves onto the shared declaration, or the copy gets its own identity. | 4 |
| E | The list template, for `fnv_008ad1c0::MoveActor454*`: the pointee is nested in a namespace, which the element type rule refuses. | 1 |

None of the 93 falls under a rule that exists. The table, by need and then
by class:

| Need | Class | Requiring units: storage the compiler gives the class there |
| --- | --- | --- |
| S | `fnv_00433010::SL` | `extradataobjects.cpp`: 8 bytes, 1 field, too small at 1 of 1 sites |
| S | `fnv_005a8d20::SL` | `tesscript.cpp`: 8 bytes, 1 field, too small at 1 of 1 sites |
| S | `fnv_007a43a0::SL` | `listbox.cpp`: 8 bytes, 1 field, too small at 1 of 1 sites |
| S | `fnv_0096dcb0::FUN_0096a2d0` | `processlists.cpp`: 8 bytes, 1 field, too small at 1 of 1 sites |
| S | `FUN_0075cc90_Local` | `containermenu.cpp`: 4 bytes, 1 field, too small at 1 of 1 sites |
| S | `FUN_007a36e0_m4` | `listbox.cpp`: 4 bytes, 1 field, too small at 1 of 1 sites |
| S | `GlobalObject2_0096a2d0` | `interfacemanager.cpp`: 16 bytes, two pointers; `navmeshobstaclemanager.cpp`: 16 bytes, two pointers; `global_object_initializers2.cpp`: 4 bytes, 1 field, too small at 30 of 30 sites |
| S | `GlobalObject_0096a2d0` | `explosion.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites; `tesworldspace.cpp`: 16 bytes, two pointers; `global_object_initializers.cpp`: 4 bytes, 1 field, too small at 8 of 8 sites; `blk_00440000_od.cpp`: 8 bytes, 2 fields, too small at 59 of 59 sites; `blk_00960000_od.cpp`: 8 bytes, 2 fields, too small at 2 of 2 sites |
| S | `List009` | `alarmpackage.cpp`: 8 bytes, 1 field, too small at 1 of 1 sites |
| S | `List970` | `processlists.cpp`: 8 bytes, 1 field, too small at 1 of 1 sites |
| S | `Rebuild004d0650::FUN_0096a2d0` | `inventorychanges.cpp`: 8 bytes, 1 field, too small at 1 of 1 sites |
| S | `RecursiveSpinLock` | `threadsafestructures_h_unit.cpp`: 32 bytes, 2 fields; `bgsquestobjective.cpp`: 8 bytes, 1 field, too small at 1 of 1 sites; `extradataobjects.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites; `tesactorbasedata.cpp`: 4 bytes, 1 field, too small at 1 of 1 sites; `tesdatahandler.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites; `tesfile.cpp`: 8 bytes, 2 fields, too small at 3 of 3 sites; `testopicinfo.cpp`: 8 bytes, 1 field, too small at 3 of 3 sites |
| S | `RefListNode_587D10` | `tesworldspace.cpp`: 8 bytes, 1 base, too small at 1 of 1 sites |
| S | `StrList` | `conversation.cpp`: 16 bytes, two pointers; `extradataobjects.cpp`: 16 bytes, two pointers; `modelloader.cpp`: 8 bytes, 1 field, too small at 1 of 1 sites; `navmeshobstaclemanager.cpp`: 16 bytes, two pointers; `setting.cpp`: 16 bytes, two pointers |
| W | `CastTargets::Context` | `magiccaster.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `DxNode` | `playercharacter.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `fnv_004329d0::SL` | `extradataobjects.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `fnv_00436cb0::RecursiveSpinLock` | `extradataobjects.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `fnv_005878d0::StrList` | `tesworldspace.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `fnv_0075c280::FUN_0096a2d0` | `containermenu.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `fnv_007d6eb0::SubObjA` | `startmenu.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `fnv_0094cae0::kRList2` | `actor.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `fnv_009715c0::RetCls` | `processlists.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `fnv_009721f0::SL` | `processlists.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `FNVElement` | `mapmenu.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `FNVLoadEntry` | `extradataobjects.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `FUN_0096a2d0` | `highprocess.cpp`: 16 bytes, two pointers; `middlehighprocess.cpp`: 8 bytes, 2 fields, too small at 4 of 4 sites; `detailedactorpathhandler.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites; `playercharacter.cpp`: 8 bytes, 2 fields, too small at 3 of 3 sites; `processlists.cpp`: 16 bytes, two pointers; `blackjackmenu.cpp`: 16 bytes, two pointers; `dialogmenu.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites; `inventorymenu.cpp`: 16 bytes, two pointers; `surgerymenu.cpp`: 16 bytes, two pointers; `inventorychanges.cpp`: 16 bytes, two pointers; `teslevspell.cpp`: 16 bytes, two pointers; `tesobjectcell.cpp`: 16 bytes, two pointers; `tessaveloadgame.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites; `blk_005a0000_od.cpp`: 8 bytes, 2 fields, too small at 3 of 3 sites; `blk_006c0000_od.cpp`: 16 bytes, two pointers |
| W | `List122` | `blk_00920000_od.cpp`: 8 bytes, 2 fields, too small at 17 of 19 sites |
| W | `loader::Power` | `extradatalist.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `MenuList` | `caravanmenu.cpp`: 8 bytes, 2 fields, too small at 2 of 2 sites |
| W | `Obj8` | `combatgroup.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `SpawnedEntry` | `inventorychanges.cpp`: 8 bytes, 2 fields, too small at 1 of 1 sites |
| W | `WkL8` | `playercharacter.cpp`: 8 bytes, 2 fields, too small at 5 of 5 sites |
| D | `ExtraNodeShell` | `inventorychanges.cpp`: 16 bytes, 1 base |
| D | `fnv_004346f0::ReflectedReferenceRecord` | `extradataobjects.cpp`: 16 bytes, 2 fields |
| D | `fnv_005ac020::SL` | `tesscript.cpp`: 16 bytes, 2 fields |
| D | `fnv_0061a5a0::SL` | `testopic.cpp`: 16 bytes, 2 fields, 1 base |
| D | `fnv_006c6e60::TSQueueNode` | `blk_006c0000_od.cpp`: 16 bytes, 2 fields |
| D | `fnv_00855660::SL` | `tessaveloadgame.cpp`: 16 bytes, 2 fields |
| D | `fnv_00971fd0::SL` | `processlists.cpp`: 16 bytes, 1 base |
| D | `fnv_009a06c0::SL` | `combatstate.cpp`: 16 bytes, 2 fields |
| D | `fnv_009eb500::DispatchMembers` | `processlists.cpp`: 24 bytes, 6 fields |
| D | `LoadBoundPair` | `combatstate.cpp`: 16 bytes, 2 fields |
| D | `LocalList` | `bartermenu.cpp`: 16 bytes, two pointers; `navmeshinfomap.cpp`: 24 bytes, 4 fields |
| D | `OwnList` | `bartermenu.cpp`: 16 bytes, 2 fields, 1 base |
| D | `TemporaryList` | `listbox.cpp`: 16 bytes, 1 base |
| D | `ThreadInterfaceManager<class LockFreeQueue<class bhkRigidBody *>::QueueDeleteManagerTag>::ThreadInterfaceEntry` | `threadsafestructures_h_unit.cpp`: 16 bytes, 2 fields |
| D1 | `RebuildResult` | `bgsreconstructformsinallfilesmap.cpp`: 16 bytes, two pointers |
| D1 | `ScriptExecutor` | `tesscriptrunmanager.cpp`: 16 bytes, two pointers |
| V | `Res9711` | `processlists.cpp`: 16 bytes, a virtual table pointer at 0 |
| H | `AddNode` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H | `AmmoEffectList` | `tesammoeffect.cpp`: 16 bytes, two pointers |
| H | `AnimList` | `modelloader.cpp`: 16 bytes, two pointers |
| H | `AvoidAreaList` | `highprocess.cpp`: 16 bytes, two pointers |
| H | `CandidateList` | `actor.cpp`: 16 bytes, two pointers |
| H | `CopyList` | `bssimplelist_h_unit.cpp`: 16 bytes, two pointers |
| H | `EntryListNode` | `inventorymenu.cpp`: 16 bytes, two pointers; `blk_00960000_od.cpp`: 16 bytes, two pointers |
| H | `EquipList` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H | `ExpiredCellList` | `tessaveloadgame.cpp`: 16 bytes, two pointers |
| H | `ExtraList_bdb40` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H | `ExtraListList_4bd5c0` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H | `ExtraListListX` | `hudmainmenu.cpp`: 16 bytes, two pointers |
| H | `ExtraNode64` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H | `fnv_004a8bb0::GlobalObject2_0096a2d0` | `bgssceneinfo.cpp`: 16 bytes, two pointers |
| H | `fnv_004d1960::FUN_0096a2d0` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H | `fnv_0050c1d0::FUN_0096a2d0` | `teslevspell.cpp`: 16 bytes, two pointers |
| H | `fnv_0063d5e0::SL` | `sky.cpp`: 16 bytes, two pointers |
| H | `fnv_0070f6e0::TileSimpleList` | `interfacemanager.cpp`: 16 bytes, two pointers |
| H | `fnv_0087e130::StrList` | `actor.cpp`: 16 bytes, two pointers |
| H | `fnv_00911b00::List_009e03e0` | `lowprocess.cpp`: 16 bytes, two pointers |
| H | `fnv_00914c60::FUN_0096a2d0` | `middlehighprocess.cpp`: 16 bytes, two pointers |
| H | `fnv_00963eb0::FUN_0096a2d0` | `playercharacter.cpp`: 16 bytes, two pointers |
| H | `InventoryOutputExtras4ca330` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H | `InventoryTransfer::ExtraNode` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H | `InvNode` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H | `PointerListNode` | `middlehighprocess.cpp`: 16 bytes, two pointers |
| H | `ReferenceList` | `tesobjectcell.cpp`: 16 bytes, two pointers |
| H | `TickList` | `blk_00920000_od.cpp`: 16 bytes, two pointers |
| H | `W20ExtraList` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H1 | `EntryNode` | `itemmodmenu.cpp`: 16 bytes, two pointers |
| H1 | `fnv_00430dd0::SL` | `extradataobjects.cpp`: 16 bytes, two pointers |
| H1 | `fnv_005cbdb0::InventoryList` | `tesscriptfunctions.cpp`: 16 bytes, two pointers |
| H1 | `fnv_007b6aa0::ItemNode` | `repairmenu.cpp`: 16 bytes, two pointers |
| H1 | `fnv_009293b0::SL` | `middlehighprocess.cpp`: 16 bytes, two pointers |
| H1 | `LockFreeQueue<class bhkRigidBody *>::LockFreeQueueEntry` | `threadsafestructures_h_unit.cpp`: 16 bytes, two pointers |
| H1 | `TopicInfoList` | `extradataobjects.cpp`: 16 bytes, two pointers |
| H1 | `Transfer4c37Obj96` | `inventorychanges.cpp`: 16 bytes, two pointers |
| H1 | `WsNameList` | `tesworldspace.cpp`: 16 bytes, two pointers |
| T | `BSSimpleListEx<class RadioStationRef *>` | `falloutradio.cpp`: 16 bytes, 1 base |
| T | `BSSimpleListEx<struct S_008356e0_Item *>` | `falloutradio.cpp`: 16 bytes, 1 base |
| T | `fnv_007b8d30::BSSimpleList<void *>` | `menumanager.cpp`: 16 bytes, two pointers |
| T | `SimpleList<class TESForm *>` | `inventorychanges.cpp`: 16 bytes, two pointers |
| E | `BSSimpleList<struct fnv_008ad1c0::MoveActor454 *>` | `actor.cpp`: 16 bytes, 1 base |

Five names bound to the address are defined by a unit that does not own its
function row. The owner, `bssimplelist_h_unit.cpp`, defines none of them.

| Name | Defined by | Units that define or require it | Body |
| --- | --- | --- | --- |
| `HackingArrayElement::HackingArrayElement()` | `hackingmenu.cpp` | 1 | 18 bytes: zeroes the pointer and the 32-bit length (VEGAS-72) |
| `Node_00855010::Node_00855010()` | `tessaveloadgame.cpp` | 1 | 4 bytes: returns `this` and writes nothing; the class is 8 bytes |
| `SL::SL()` | `recipemenu.cpp` | 36 | 4 bytes, the same |
| `fnv_00722f60::SL::SL()` | `listbox.cpp` | 7 | 4 bytes, the same; this is the name of the owner's function row |
| `fnv_0083da50::SL::SL()` | `blk_00820000_od.cpp` | 1 | 4 bytes, the same |

## Live hazard: empty constructors at the address

This was there before VEGAS-72. Its owner is VEGAS-17, which owns the
function row at `0x0096a2d0`.

`src/fallout/interface/listbox.cpp` defines `fnv_00722f60::SL::SL()` with
an empty body. That is the name of the owner's function row at
`0x0096a2d0`, and this empty body is the only definition of it, so it is
the one the forced link picks. Six other units require it: they construct
the class with placement new. The original body zeroes 8 bytes, and the
empty body writes nothing. Those six units declare the class empty, 1 byte,
so the owner's body cannot replace it until their storage is repaired. The
S repairs come first.

The other three empty bodies in the table above, for `Node_00855010`, `SL`
and `fnv_0083da50::SL`, are placeholders without an address tag too. Each
needs the same decision as the hacking menu element: its class's own
identity and the body the recipe shows, or no body. None of the four is
changed here.
