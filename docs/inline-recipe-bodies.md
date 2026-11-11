# Inline bodies their owning units never emitted

`build/units.json` gives each function row to one unit. Eleven functions had
a body in the tree that no object emitted, because the body was inline and
clang emits an inline body only where it is used and not inlined. Each is now
defined out of line, once, in the unit its row names. The bodies are
unchanged.

The units belong to four folder tickets: VEGAS-17 (`bsaudio`, `bsshader`),
VEGAS-18 (`fallout_shared`, and `region system`, which the link-frontier
partition counts with it), VEGAS-22 (`src/niobject_h_unit.cpp`, a unit at the
top of the source folder) and VEGAS-16 (its header, in the Gamebryo folder).
Their criterion is "each function that existed in several variant units has
one definition". No repair-family ticket names any of these symbols.

This change checks no acceptance criterion of those tickets. None of the
eleven functions existed in several variant units: each had one tagged body
in the tree and one function row in the recipe. The one function here that does have
a second tagged copy, the list constructor at `0x0096a2d0` in
`bssimplelist.cpp`, keeps it (`docs/simple-list-default-constructor.md`).
The change is credited with two things only: each of these names now has one
emitted definition, and the link measure below.

This is a bounded change. What stays open is under "Not covered" and "The
rest of the category".

## The functions

| Address | Function | Recipe size | Owning unit | Body was |
| --- | --- | --- | --- | --- |
| `0x00653290` | `NiObject::DynamicCast(const NiRTTI*)` | 35 | `src/niobject_h_unit.cpp` | `inline`, in `niobject.h` |
| `0x0045a120` | `BSFaceGenMorphData::DynamicCast()` | 25 | `src/niobject_h_unit.cpp` | `inline`, in `niobject.h` |
| `0x005d8a70` | `TESRegion::GetDiffuseColor()` | 17 | `region system/tesregion_h_unit.cpp` | in the class body, `tesregion.h` |
| `0x008d8520` | `BSShaderNoLightingProperty::GetBaseTexture()` | 17 | `bsshader/bsshadernolightingproperty_h_unit.cpp` | in the class body of its header |
| `0x00b00a00` | `GetTaskletManager()` | 118 | `fallout_shared/pathfinding/astarsearch_h_unit.cpp` | `inline`, in `astarsearch.h` |
| `0x00ae8770` | `BSAudioDefinition::BSAudioDefinition()` | 189 | `bsaudio/bsaudiodefines_h_unit.cpp` | in the class body, `bsaudiodefines.h` |
| `0x00ae8830` | `BSAudioDefinition::~BSAudioDefinition()` | 129 | the same | the same |
| `0x00ae88c0` | `BSAudioDefinition::operator=(const BSAudioDefinition&)` | 304 | the same | the same |
| `0x00ae8af0` | `BSSoundInfo::~BSSoundInfo()` | 74 | the same | the same |
| `0x0050ea10` | `FUN_0050ea10_class::FUN_0050ea10(NiPoint3&) const` | 56 | `fallout_shared/tesobject.cpp` | in the class body, in the unit |
| `0x009dfdf0` | `ActorPathHandler::CompleteNoPathUpdate(float)` | 18 | `fallout_shared/magic/effectitemlist.cpp` | in the class body, `effectitemlist.h` |

Each address has one function row in the recipe, in the unit shown. Each
header is included by its owning unit and by no other file.

## Why no object emitted them

- Four units call the function once, to keep it. The windows-x64 build
  optimises, so the call was inlined and the inline body discarded. This is
  the case for `GetDiffuseColor`, `GetBaseTexture`, `CompleteNoPathUpdate`
  and the four audio members.
- The two `DynamicCast` members and `GetTaskletManager` were `inline` and not
  used in their unit at all.
- `FUN_0050ea10` was named only by a static member pointer that nothing reads,
  which the compiler also discards. The pointer is still there.

At 6df85ec36, the commit this change was made on, no archive member defined
any of the eleven names.

## The change

Each header now declares the function and its owning unit defines it, with
the address tag. In `tesobject.cpp` the definition moves out of the class
body, in the same file. Two unit comments said the body lived in the header
and are corrected.

`build/units.json` is unchanged: no name in it changed.

## Measured links

Windows-x64, 2,223 archive members in the same order before and after. Seven
objects differ, one per owning unit.

| Link | At 6df85ec36 | This change and the list constructor change |
| --- | --- | --- |
| on demand, ordinary and unlimited | links, 78 imports | every list identical, map identical |
| forced, whole archive: duplicate symbols | 0 | 0 |
| forced unlimited: undefined names | 35,672 | 35,654 |
| forced unlimited: imports | 137 | the same 137 |

Carried onto 6221c1167 and measured again, both builds from the same export
path: 35,592 undefined names before and 35,574 after, 0 duplicate symbols,
the same 137 imports and the same 2,223 members. The same 18 names leave and
none enters.

The two changes were measured together. Ten of the 18 names that leave are
from this change, and none enters:

- `NiObject::DynamicCast(const NiRTTI*)`
- `BSFaceGenMorphData::DynamicCast()`
- `TESRegion::GetDiffuseColor()`
- `BSShaderNoLightingProperty::GetBaseTexture()`
- `GetTaskletManager()` returning `class BSWin32TaskletManager&`
- `BSAudioDefinition::BSAudioDefinition()`
- `BSAudioDefinition::~BSAudioDefinition()`
- `BSSoundInfo::~BSSoundInfo()`
- `FUN_0050ea10_class::FUN_0050ea10(NiPoint3&) const`
- `ActorPathHandler::CompleteNoPathUpdate(float)`

`BSAudioDefinition::operator=` is emitted too, with no requirer under its
name. Its one requirer, `bsaudiomanager`, spells the return and argument type
`struct BSAudioDefinition&` and stays undefined. It is emitted because the
recipe's function row at `0x00ae88c0` owns that name in this unit, not
because an object requires it. Since the shared declaration of the class
(`docs/shared-audio-definition.md`) `bsaudiomanager` uses the class key and
its six calls are bound to this definition.

Each of the eleven definitions is an ordinary function in a section that
refuses a second definition. None is select-any. The build has the same
warning count and the same warning classes.

## Requirers

From the objects of the windows-x64 build, before and after:

| Function | Objects that require it | Other undefined names in the archive at the address |
| --- | --- | --- |
| `NiObject::DynamicCast` | 36 | 13, still undefined |
| `BSFaceGenMorphData::DynamicCast` | 2 | none |
| `TESRegion::GetDiffuseColor` | 14 | 7, still undefined |
| `BSShaderNoLightingProperty::GetBaseTexture` | 143 | 1, still undefined |
| `GetTaskletManager`, `class` spelling | 8 | the `struct` spelling, 3 objects, still undefined |
| `BSAudioDefinition` constructor | 1, `bsaudiomanager` | none |
| `BSAudioDefinition` destructor | 1, `bsaudiomanager` | none |
| `BSAudioDefinition::operator=`, `class` spelling | 0 | the `struct` spelling, `bsaudiomanager`, still undefined |
| `BSSoundInfo` destructor | 1, `bsaudiomanager` | 1, still undefined |
| `FUN_0050ea10` | 2, `mobileobject` and `tesobjectrefr` | none |
| `CompleteNoPathUpdate` | 1, the generated table object `vtables_0109` | none |

The other names at an address are second names for the same function under
another class or signature. They now have a definition to be joined to, which
is naming work and not part of this change.

The last column counts undefined names in the archive, not recipe rows. The
recipe binds one more name to `0x00ae8770`:
`SoundDebugDescription::SoundDebugDescription()`, a symbol row of
`bsaudiomanager.cpp`. That unit defines it inline and no object requires it.

`vtables_0109.cpp` does not name `CompleteNoPathUpdate` in C++. It declares a
generated label, `fnv_fn_009dfdf0`, with the member's linker name and stores
its address in two table slots.

## Programs

- The game executable loads archive members on demand. It loads 15 members,
  none of them an owning unit or a requirer, before and after.
- Of the 55 test programs, 54 link, before and after. None loads an owning
  unit or a requirer.
- The worker-pool test does not link. Forced, with every section kept, each
  name binds to its owning unit's object.

So no linking program reaches any of these bodies. No test is added: no
owning unit can be linked into a test with a genuinely constructed receiver.
`TESRegion` and `BSShaderNoLightingProperty` have base classes with virtual
functions that their units do not define, and the other units require names
the archive does not define.

## Not covered

These were open before this change and it closed none of them. A later
change repaired the first part of one, the `BSAudioDefinition` storage; that
item says what still stands.

- Receivers. Every requirer reaches these members through a cast to a class
  declared without members in `include/fnv/decl/`. Whether the object it
  passes has the owning unit's layout is not established. Measured in the
  windows-x64 objects:

  | Function | 32-bit original | windows-x64 body |
  | --- | --- | --- |
  | `TESRegion::GetDiffuseColor` | returns `this + 0x2c` | returns `this + 0x4c` |
  | `GetBaseTexture` | reads the pointer at `0x68` | reads the pointer at `0xa0` |
  | `BSFaceGenMorphData::DynamicCast` | passes `this + 0x1ec` on | the same `0x1ec`; the class declares 0x1ec bytes of padding |
  | `FUN_0050ea10` | reads at `0xc` and `0x18` | the same; the class declares 0xc bytes of padding |

  The two getters are 17-byte bodies in the original, and the recipe binds
  each address under other class names too. `0x005d8a70` has seven:
  `FormNode::FUN_005d8a70`, `FUN_0047d410_cls::FUN_005d8a70`,
  `FUN_0047d800_shell::FUN_005d8a70`, `FUN_0047e4a0_cls::GetFactionHead`,
  `fnv_0047e6f0::TESActorBaseData_Shell::FUN_005d8a70` and
  `TESRegion::GetDiffuseColor` in the namespaces `fnv_0047ca20` and
  `fnv_0047d680`. `0x008d8520` has one, `PlayerQuestData::GetLogDate`. 14
  objects require the `TESRegion` getter and 143 the `GetBaseTexture` getter,
  149 distinct objects.

  INFERENCE, not measured: these are accessors of several classes that the
  original linker folded into one address because their bytes were equal. If
  so, many of the requirers pass a receiver of another class, and for that
  receiver the windows-x64 offsets `+0x4c` and `+0xa0` are wrong.

- `BSAudioDefinition` storage. The class is 572 bytes in the original and 584
  in the windows-x64 build, with the second pointer at `0x110`. The emitted
  constructor stores into bytes 0 to 583; its last store covers
  `[0x240, 0x248)`. `bsaudiomanager.cpp` declares the storage four ways, not
  three: its own `BSAudioDefinition` without members, 1 byte, as the member
  `_18` of `FUN_00ae89f0`; `Sub18_00ae5a50`; `DebugInfo`; and `DebugPlain`.
  Measured in that unit:

  | Record in `bsaudiomanager.cpp` | Size | Where the definition sits |
  | --- | --- | --- |
  | `FUN_00ae89f0` | 28, alignment 4 | member `_18` at `0x18`, 1 byte |
  | `SoundInfoWrap` | 596, alignment 4 | that record as its head, then 568 bytes of padding |
  | `Msg_00ae5a50` | 608 | `Sub18_00ae5a50` at `0x18`, 584 bytes, second pointer at `0x110` |
  | `DebugInfo`, `DebugPlain` | 576 each | at offset 0, second pointer at `0x108` |
  | `TempInfo` | 600 | a `DebugPlain` at `0x18` |

  The owning unit's `BSSoundInfo` is 608 bytes with the definition at `0x18`.
  The object has six relocations to the constructor:

  | Site | Storage constructed | Written range in the record | Past the record |
  | --- | --- | --- | --- |
  | `FUN_00ae89f0::FUN_00ae89f0()`, out of line | `this + 0x18` of the caller's record | `[0x18, 0x260)` | depends on the enclosing record; 580 bytes for a bare 28-byte one |
  | `Mgr_00ae5a50::FUN_00ae5a50`, `new Msg_00ae5a50` | `0x18` of a 608-byte heap block | `[0x18, 0x260)` | 0, fits |
  | `ThisClsAda::FUN_00ada5d0`, local `info15` | `0x18` of the 596-byte `SoundInfoWrap` | `[0x18, 0x260)` | 12 |
  | the same function, local `descB_` | offset 0 of the 576-byte `DebugInfo` | `[0, 0x248)` | 8 |
  | the same function, local `debug4` | offset 0 of the 576-byte `DebugInfo` | `[0, 0x248)` | 8 |
  | the same function, temporary `TempInfo` | its `debug` member, `0x18` of 600 bytes | `[0x18, 0x260)` | 8 |

  So four of the six sites would be written past their record, and the three
  576-byte ones have the second pointer at another offset. The sizes and
  offsets are compiler-evaluated in the unit; the sites are the relocations
  and the instructions before them in the windows-x64 object.

  The `BSAudioDefinition` sites are repaired
  (`docs/shared-audio-definition.md`): every one of them provides 584 bytes
  with the second pointer at `0x110`, and the two tables above are the state
  before that repair. Before a program links `bsaudiomanager`, the items
  under "Not covered" of that document still stand: the undefined
  `BSSoundInfoC` constructor and the eight records that stand for
  `BSSoundInfo`; the release size of 8 bytes in `AudioMgr70::FUN_00ad9870`,
  at two sites; and `SoundDebugDescription`. The 8-byte lists in
  `bsfacegenanimationdata` (`docs/simple-list-default-constructor.md`) and
  in `projectile` must still be repaired before any program links those
  units. Until this change the constructors were undefined, so such a link
  failed. It no longer fails on these names. `bsaudiomanager` is in no
  linking program today.
- `FUN_0050ea10` calls `NiPoint3::operator-(const NiPoint3&) const`. No object
  defines it. 46 objects require it, `tesobject` newly.
- The two destructors are a single return in the windows-x64 build. Their
  bodies only store into the object being destroyed, and the compiler removes
  such stores. The original bodies are 129 and 74 bytes.
- `GetTaskletManager` constructs its static manager with the constructor and
  destructor of `BSWin32TaskletManager`, which no object defines.
- `NiObject::DynamicCast` and `BSFaceGenMorphData::DynamicCast` call
  `NiObject_b::FUN_006532c0` and `FUN_00658930_class::GetShortAtOffsetA`
  through casts to stand-in classes, as before.
- `BSSoundInfo::BSSoundInfo(BSSoundInfo*)` at `0x00ae8a40` was defined in the
  class body at this change, and the unit emitted it because it is too large
  to inline. It is defined out of line now, in the owning unit
  (`docs/shared-audio-definition.md`). This item is closed.
- Nothing executes these functions.

## The rest of the category

The link-frontier partition calls an undefined name category (b) when the
recipe has a function row at its address and the owning unit emits no
linkable body under the recipe's name. At 6df85ec36 that was 492 names over
60 addresses. After this change and the list constructor change
(`docs/simple-list-default-constructor.md`) it is 450 names over 49
addresses. Of the 42 names that left, 18 are now defined and 24 are second
names at an address that now has a definition.

The rule applied: emit a body when it exists under the name a requirer uses
and no object emits it. A member that the recipe's function row names in the
same unit is emitted with it even when no object requires that spelling;
`BSAudioDefinition::operator=` is the one case. A body that exists only
under another name or signature is naming work and was left alone.

What remains, by reason:

| Reason | Addresses | Names |
| --- | --- | --- |
| Another unit, not the one in the recipe row, defines the function. Emitting it in the recipe's unit would define it twice. The requirers use other names. | 18 | 262 |
| The list constructor at `0x0096a2d0`: other class names, and element types its unit does not declare | 1 | 119 |
| The owning unit holds the body as a template member, under the template's name. The requirers use the recipe's name, a class declared without members, or other names. | 14 | 37 |
| The body is `static` in its unit and every requirer uses another name or signature | 13 | 24 |
| The vector constructor helper at `0x00401050`, which the compiler supplied and no source defines | 1 | 6 |
| An inline empty destructor at `0x00ad6a30` whose one requirer is a different member | 1 | 1 |
| Refused: `Vec::FUN_00acac40` at `0x00acac40` | 1 | 1 |

- Another unit defines it: `0x00c85750`, `0x00438170`, `0x0048af40`,
  `0x00a5b690`, `0x0044a4c0`, `0x00aa1460`, `0x00aa13e0`, `0x00aa4060`,
  `0x00aa3e40`, `0x00aa4150`, `0x00401030`, `0x00401020`, `0x00436aa0`,
  `0x0044a500`, `0x00d472a0`, `0x00dc4710`, `0x00d544f0` and `0x00d543e0`.
  Most are the native owners accepted earlier, such as the memory manager
  and the fixed string table.
- Template member: `0x0096ad30`, `0x0096ae90`, `0x00470000`, `0x004dffa0`,
  `0x00869260`, `0x004b0310`, `0x007cb2e0`, `0x00a0cf60`, `0x00a1bfa0`,
  `0x00e8ea60`, `0x00a11db0`, `0x00ae7f90`, `0x0046ffb0` and `0x004037d0`.
  Defining the recipe's name would need the layout of a class that is
  declared without members, or a cast to the template.
- Static: `0x00d470f0`, `0x00e03360`, `0x00c926a0`, `0x00d234e0`,
  `0x00d48950`, `0x00dd9d70`, `0x00df9ae0`, `0x00db0aa0`, `0x00e0c690`,
  `0x00c92950`, `0x00cb0ad0`, `0x00e349c0` and `0x00e08380`. Six of these
  units hold a second static function of the same name with other
  arguments.
- `Vec::FUN_00acac40` in `staging/blk_00ac0000_od.cpp` is inline and has one
  requirer under its own name, `tesobject`. It was refused. Its only callee
  in the unit is an inline placeholder that returns its first argument, so
  the emitted body checks two pointers and does nothing else. Emitting it
  would bind the requirer to a clear that does not clear. It belongs to
  VEGAS-21.
