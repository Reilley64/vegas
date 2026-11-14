# One shared declaration of TESAnimGroup

VEGAS-11 asks that a class have one declaration every unit shares. VEGAS-18
owns `src/fallout_shared/tesanimgroup.cpp`, the unit that holds every
function row the recipe gives under the name `TESAnimGroup`. This change
moves that unit's class into a shared header and moves six more units onto
it. What stays open is under "Units that did not move", "Defects" and "Not
covered". The method is the one of `docs/shared-simple-list.md`.

## Where the declaration lives

`include/fnv/tes_anim_group.h`, next to the other shared native
declarations in `include/fnv/`. `include/fnv/decl/TESAnimGroup.h` is a
different thing: a member-only declaration without a layout. Since this
change it holds that text only for the units that define
`FNV_KEEPS_OWN_TESANIMGROUP`, and gives the other units that include it a
forward declaration of the class.

## What it declares

- The base `NiRefObject`, from `fnv/ni_ref_object.h`.
- The 13 fields of the owning unit's class, in its order, with the nested
  `AnimGroupSound`.
- The destructor, virtual, declared and not defined (see "Not covered").
- The 13 members that have a function row under the class's name, with the
  owning unit's signatures:

| Address | Member | Recipe size | Units with a symbol row at the address |
| --- | --- | --- | --- |
| `0x005f2370` | `static unsigned short AnimGroup(ANIM_GROUP_MOVE_ENUM, ANIM_GROUP_WEAPON_ENUM, ANIM_GROUP_ENUM, bool)` | 34 | 6 |
| `0x005f23c0` | `static ANIM_GROUP_MOVE_ENUM GetMoveType(unsigned short)` | 17 | 4 |
| `0x005f2420` | `ANIM_GROUP_ENUM GetType() const` | 27 | 13 |
| `0x005f2440` | `static ANIM_GROUP_ENUM GetType(unsigned short)` | 14 | 13 |
| `0x005f2540` | `static bool IsActionTypeValid(unsigned short)` | 84 | 6 |
| `0x005f25a0` | `static bool IsActionTypeValid(ANIM_GROUP_ACTION_TYPE)` | 34 | 1 |
| `0x005f2630` | `static bool IsAimAnimation(unsigned short)` | 57 | 4 |
| `0x005f2670` | `static bool IsValidAnimationGroup(unsigned short)` | 51 | 6 |
| `0x005f26b0` | `static bool IsValidAnimationGroup(ANIM_GROUP_ACTION_TYPE)` | 14 | 1 |
| `0x005f3870` | `static char* FindNextLine(char*)` | 94 | 1 |
| `0x005f4c70` | `float GetAnimationSpeed() const` | 22 | 2 |
| `0x005f4d00` | `void SetSoundsFromSequence(NiControllerSequence*)` | 90 | 1 |
| `0x005f4d60` | `bool IsJumpAnimation() const` | 67 | 3 |

`_AnimationGroupActionType` and its typedef `ANIM_GROUP_ACTION_TYPE` move
into the header with the class: two members take the enumeration, and no
other unit declares it.

The header has no body. The owning unit defines all 13 members, and each is
defined once in the archive, in `tesanimgroup.cpp.obj`.

### What the including unit supplies

The header names `NiPoint3` and the enumerations `ANIM_GROUP_ENUM`,
`ANIM_GROUP_MOVE_ENUM` and `ANIM_GROUP_WEAPON_ENUM`, and does not declare
them. The tree holds many private copies of each, and a unit that has one
cannot take a second. The including unit declares them first, all complete.
Assertions after the class stop the build of a unit where:

- `NiPoint3` is not 12 bytes with alignment 4. The assertion checks the size
  and the alignment, not that the type holds three floats.
- one of the three enumerations is not 4 bytes. A unit whose enumeration had
  a fixed underlying type of another width would otherwise give `GetType`,
  `GetMoveType` and `AnimGroup` another signature, and so another symbol,
  without a diagnostic.
- the class is not 88 bytes with alignment 8, or `AnimGroupSound` is not 24
  bytes.

The header has no test of its own. Its assertions are the layout guard, as
for `include/fnv/bs_audio_definition.h`.

## Fields and what establishes them

The owner's bodies are transcriptions of 32-bit code. The rulings page
"Symbol naming and native ownership" (2026-11-11 (2)) calls a field of such a
class established on x64 when (a) its order and size are taken from the
transcribed declaration; (b) its x64 offset is the ABI consequence of the
declared types, measured by the compiler in every unit on the header; (c)
every x64 body that disagrees uses exactly the 32-bit offset of the same
declaration and is recorded as a defect with its address; (d) no agreeing
body contradicts it.

The 13 fields of the class's own meet (a) and (b): their order and types
are the owning unit's transcribed declaration, and the compiler measured the
windows-x64 offsets below in each of the seven units on the header, with
that unit's own command line. (c) and (d) were checked
only in the owning unit's object and in the bodies that `0x005f3a20` calls on
the object it builds. Bodies elsewhere were not searched for access to the
class, so no field is called established here.

| Field | Size | 32-bit offset | windows-x64 | (c) and (d) in the searched bodies |
| --- | --- | --- | --- | --- |
| vtable pointer, `m_uiRefCount` | 8, 4 | 0, 4 | 0, 8 | from `NiRefObject` |
| `m_ucSectionPriorities[8]` | 8 | 8 | 16 | no disagreeing body found |
| `sType` | 2 | 16 | 24 | no other disagreeing body found; defect 1 reads bytes 24 to 31 as `times` |
| `frameCount` | 4 | 20 | 28 | as `sType` |
| `times` | 8 | 24 | 32 | disagreeing: defect 1 (32-bit offset 24) |
| `speed` | 12 | 28 | 40 | no body reads or writes it at another offset; defect 3 writes bytes 41 to 44, the 32-bit offsets of four other fields; `0x00974d90` reads byte 40 (see "Not covered") |
| `m_cByteAfterSpeed` | 1 | 40 | 52 | open: `0x00974d90` and `0x00929260` (see "Not covered") |
| `m_ucBlendCount`, `m_ucBlendInCount`, `m_ucBlendOutCount` | 1 each | 41, 42, 43 | 53, 54, 55 | disagreeing: defect 3 (32-bit offsets); `0x005f3a20` reads them at 53 to 55 |
| `m_ucDecal` | 1 | 44 | 56 | disagreeing: defect 3 (32-bit offset) |
| `pParentName` | 8 | 48 | 64 | not met: defect 5 writes the parent at 88, neither offset |
| `m_uiSoundEntryCount` | 4 | 52 | 72 | not met: defect 5 reads the count from 56, neither offset; disagreeing at the 32-bit offset: defects 1 and 4 |
| `sounds` | 8 | 56 | 80 | disagreeing: defects 1 and 4 (32-bit offset); `0x005f2820` reaches it at 80 and sizes its block by `sizeof(AnimGroupSound)` (defect 2, repaired) |

The 32-bit offsets are those of the transcribed declaration with 4-byte
pointers. The windows-x64 offsets start each derived field after the 16
bytes of `NiRefObject`.

Owner access seen, from the disassembly of the owning unit's object, through
the declared members and at the x64 offsets: `0x005f4d00` writes
`m_ucSectionPriorities`; `0x005f2450` writes `sType` and reads and writes
`frameCount` and `times`; `0x005f2420`, `0x005f4d60`, `0x0047d3b0`,
`0x005f26c0`, `0x005f23e0` and `0x005f23a0` read `sType`; `0x005f3740` and
`0x005f3780` read `frameCount` and `times`; `0x005f4c70` passes the address
of `speed` to `NiPoint3::ComputeMagnitude` and `0x005f4c40` writes its 12
bytes; `0x005f2820` reads and writes `m_uiSoundEntryCount` and `sounds`;
`0x005f3a20` reads the three blend counts. No owner body was seen to reach
`m_cByteAfterSpeed`, `m_ucDecal` or `pParentName` through the member.

`AnimGroupSound` is 24 bytes on windows-x64, with `fTime` at 0, the
`ucVolume`/`eType` union at 4, the `fCurrentSpeed`/`uiEnumData` union at 8
and `SoundAssetTmp` at 16. In the 32-bit declaration it is 16 bytes, with
`SoundAssetTmp` at 12.

### The sound entry type

The bodies searched for access to the entries are every function row from
`0x005f2200` to `0x005f4e00`, and the two callers of `0x005f2b60`
(`animation.cpp` and `actor.cpp`), which pass the object and do not reach
an entry. The rows in that range are in `tesanimgroup.cpp` and
`blk_005e0000_od.cpp`, and two more: `0x005f36f0` in `navmesh.cpp` and
`0x005f4bb0` in `bgscamerapath.cpp` (defect 5), which do not reach an
entry. `0x005f4bd0` and `0x005f4c00`, in `blk_005e0000_od.cpp`, reach
16-byte entries through a count at 0xc and a pointer at 0x18 (0x14 in the
32-bit layout) of the `apSequence` that `tesanimgroup.cpp` passes them, not
of a `TESAnimGroup`; they are left out of the table. The row of `0x007f7c90`
(defect 3) is in `tesscriptcompiler.cpp`, outside the range.

In the stated search scope `AnimGroupSound` meets rules (a) to (d) of the
rulings page: its fields and their order are the transcribed declaration's,
the compiler measures 24 bytes in each unit on the header, every body that
disagrees uses exactly the 32-bit size and offsets, and no body uses a
third.

| Body | Stride | Fields reached | Agrees |
| --- | --- | --- | --- |
| `0x005f2820`, resize (defect 2, repaired) | 24 | 0, 4, 8, 16 (8 bytes) | yes |
| `0x005f2b60`, `FUN_005f2b60_cls::ProcessSoundEntries` | from `0x005f3710` | reads 0, 4, 8, 16 (8 bytes) | yes, for the fields |
| `0x005f3710`, `FUN_005f3710_Class::GetEntryAt` | 16 | none | no: 32-bit size |
| `0x005f29f0`, `0x005f2a30`, `0x005f2a70`, `0x005f2ac0`, `0x005f2b20` (defect 4) | 16 | 0, 4, 8, and 12 (4 bytes) | no: 32-bit size and offsets |

`0x005f2b60` takes each entry's address from `0x005f3710`, which the
compiler inlines, so its entries are 16 bytes apart while it reads the
fields at their x64 offsets (defect 4). Bodies in other units that reach
the entries through another getter or a raw offset would not be in this
table: the units that name the class or `GetAnimGroup` were searched as
text only.

A probe kept outside the repository compiled the header on the host (macOS,
arm64) and checked every offset there. `m_ucSectionPriorities`, `sType` and
`frameCount` are at 12, 20 and 24, four bytes lower than on windows-x64:
that ABI, unlike the one of windows-x64, starts a derived class's fields in
the padding that ends the base. From `times` on, and in size (88) and
alignment (8), the two agree. No body may reach a field by a fixed offset.

## Defects

Each of these bodies reaches the object at offsets or with sizes that
disagree with the declared members. They are recorded here and are not
layout evidence. Each was read in the source and in the windows-x64 object
of its unit. Defect 2 is repaired; the others stand, each for the reason
given with it.

1. `0x005f22d0`, the destructor, `FUN_005f22d0::~FUN_005f22d0` in
   `tesanimgroup.cpp`, on a stand-in class that derives from `EBase` and
   places its fields with padding arrays. It frees the pointer at offset
   0x18 and zeroes it, frees the pointer at 0x38 and zeroes it, and zeroes 4
   bytes at 0x34: the 32-bit offsets of `times`, `sounds` and
   `m_uiSoundEntryCount`. Under the declared layout the first pointer is
   assembled from `sType`, the padding after it and `frameCount`; the second
   is `m_ucDecal` and the padding after it; the 4 bytes are
   `m_cByteAfterSpeed` and the three blend counts. `0x005f22a0`, through
   `TESAnimGroupDestructionView`, calls it on a `TESAnimGroup`, and the
   compiler inlines it there. On windows-x64 both bodies also store the
   stand-in's table pointer, `??_7FUN_005f22d0@@6B@`, at offset 0 of the
   object and then call `EBase`'s destructor, which no object defines.
   Not repaired: the 4 bytes it zeroes are `m_uiSoundEntryCount`, which is
   not established (defect 5), and a body on the declared members is
   `~TESAnimGroup`, whose definition emits the class's table (see "Not
   covered").
2. `0x005f2820`, `FUN_005f2820_shell::FUN_005f2820` in `tesanimgroup.cpp`,
   resizes `sounds`. High priority. It allocates and copies `count << 4`
   bytes, the 32-bit size of `AnimGroupSound`, and then writes the new
   entries through `sounds[i]`, 0x18 bytes apart, with fields up to offset
   0x17 of each entry. Every call that adds entries writes past the end of
   the block it allocated. `0x005f3a20` calls it twice, at the `Enum:` and
   the `Sound:` keys (`tesanimgroup.cpp` lines 810 and 826), and
   `NamedObjectLoader::FUN_0043b7e0` (`0x0043b7e0`,
   `src/staging/blk_00420000_od.cpp` line 3869) calls `0x005f3a20`. The
   lazy link of the program does not reach these bodies today.

   Repaired: the four sizes the body passes to `FUN_00401000`,
   `Reallocate` and `__memcpy` are the count times
   `sizeof(AnimGroupSound)`, in the `unsigned int` the callees take, and
   the temporary copy is an array of `AnimGroupSound`. In the object the
   four `shl` by 4 became a multiplication by 24, and nothing else in the
   function changed: the count is still read and written at 72, `sounds` at
   80, and the entries 24 bytes apart. The other sections of the unit's
   object are unchanged apart from the end address of the function's
   unwind entry. `objects.anim_group_sound_entry_size` fails when the
   function scales a count by 16 or no longer steps through its entries 24
   bytes apart. The count it is given is still defect 5's.
3. The setters `0x005f3a20` calls on the object it builds, a
   `TESAnimGroupEx` derived from the class, for the text keys that set the
   blend counts and the decal. Each writes one byte at a fixed offset of a
   stand-in class with a padding array:

   | Address | Function | Unit | Key | Writes |
   | --- | --- | --- | --- | --- |
   | `0x005f4b70` | `FUN_005f4b70_Class::FUN_005f4b70` | `src/staging/blk_005e0000_od.cpp` | `Blend:` | `0x29` |
   | `0x007f7c90` | `S7f::SetValue` | `src/fallout_shared/tesscriptcompiler.cpp` | `BlendIn:` | `0x2a` |
   | `0x005f4b90` | `FUN_005f4b90_Class::SetByteAtOffset2B` | `src/staging/blk_005e0000_od.cpp` | `BlendOut:` | `0x2b` |
   | `0x008bf4e0` | `FUN_008bf4e0_cls::set` | `src/fallout/ai/actor.cpp` | `Decal:` | `0x2c` |

   Bytes 41 to 44 are the 32-bit offsets of `m_ucBlendCount`,
   `m_ucBlendInCount`, `m_ucBlendOutCount` and `m_ucDecal`. On windows-x64
   they lie inside `speed` (bytes 40 to 51): the last three bytes of
   `speed.x` and the first byte of `speed.y`. So every load with one of
   these keys changes `speed`, while the same body of `0x005f3a20` reads the
   blend counts at their x64 offsets, 53 to 55, and does not see the values
   it set.

   Not repaired. `0x005f4b70` and `0x005f4b90` are in
   `blk_005e0000_od.cpp`, which does not see the shared header ("Units that
   did not move", rule 3). `0x007f7c90` and `0x008bf4e0` are bodies the
   recipe also binds for other classes (`fopipboymanager.cpp`,
   `package.cpp`), so a body that writes the class's field would change
   theirs; `actor.cpp` does not see the header either.
4. The setters `0x005f3a20` calls for the sound entries, all in
   `src/staging/blk_005e0000_od.cpp`: `FUN_005f29f0_Class::SetValueAtIndex`
   (`0x005f29f0`), `FUN_005f2a30_Class::SetEntryValue` (`0x005f2a30`),
   `FUN_005f2a70_cls::SetRecordFlagAndValue` (`0x005f2a70`),
   `FUN_005f2ac0_cls::SetRecordValue` (`0x005f2ac0`) and
   `FUN_005f2b20_Class::SetEntryFloat` (`0x005f2b20`). Each compares the
   index with 4 bytes at 0x34, reads the entry pointer from 0x38, and writes
   entries 16 bytes apart, at offset 0, 4, 8 or 12 of an entry: the 32-bit
   offsets of `m_uiSoundEntryCount` and `sounds`, the 32-bit size of
   `AnimGroupSound`, and the 32-bit offsets of its fields. On windows-x64
   the pointer is assembled from `m_ucDecal` and the padding after it. The
   call of `0x005f3a20` to `SetEntryValue` passes a 64-bit value and so
   names a symbol that no object defines; the other four calls name the
   defined bodies. The repair does not change these setters. Their writes
   go through the 8 bytes at 0x38, which on windows-x64 are `m_ucDecal` and
   padding, not `sounds` (at 80); they remain a memory-safety defect.

   `FUN_005f3710_Class::GetEntryAt` (`0x005f3710`, the same unit) has the
   same fault: it compares the index with 4 bytes at 0x34 and returns the
   pointer at 0x38 plus 16 times the index.
   `FUN_005f2b60_cls::ProcessSoundEntries` (`0x005f2b60`) inlines it and
   reads each entry it returns; the bound of its loop is the value
   `BGSCameraPath::GetPrevPath` returns (defect 5).

   Not repaired: the recipe has their rows in `blk_005e0000_od.cpp`, which
   does not see the shared header, and each setter and `GetEntryAt` also
   compares the index with `m_uiSoundEntryCount`, which is not established.
5. Two members of `BGSCameraPath` that `0x005f3a20` calls on the object:
   `BGSCameraPath::GetPrevPath` (`0x005f36f0`,
   `src/fallout_shared/pathfinding/navmesh.cpp`) reads 8 bytes at 0x38,
   which `0x005f3a20` uses as the count of sound entries, and
   `BGSCameraPath::AssignParentPath` (`0x005f4bb0`,
   `src/fallout_shared/bgscamerapath.cpp`) writes the parent name, for the
   `prn:` key, at 0x58. These are the windows-x64 offsets of
   `BGSCameraPath`'s own fields, neither the x64 nor the 32-bit offsets of
   `m_uiSoundEntryCount` (72, 52) and `pParentName` (64, 48). 0x58 is 88,
   the size of the class: every load with a `prn:` key writes 8 bytes past
   the end of the object. Rule (c) is not met for these two fields while
   these calls stand.

## What was measured

At the base of this change the compiler sees 36 class definitions named
`TESAnimGroup`, the global class and classes in `fnv_...` namespaces, in the
38 units of the windows-x64 archive whose text or recipe rows name the class.
By fields, bases and member signatures they fall into 15 groups. One has
fields: the owning unit's, 88 bytes, derived from `NiRefObject`. Every other
definition is 1 byte without a field, except one namespaced copy with a
single `unsigned short` field. 17 units other than the owner define the
global class without a field: 10 through `include/fnv/decl/TESAnimGroup.h`
and 7 through a copy in their own files.

The recipe has 100 symbol rows and 13 function rows at the 13 addresses, in
22 units, under 66 names.

## The rule for moving a unit

A unit that defines the global class leaves its copy for the shared header
when all of this holds, the first four measured by the compiler in that
unit:

1. Its copy has no field, base, virtual function or body, and declares only
   members that the shared header declares with the same signature.
2. The unit defines no `NiMemObject` or `NiRefObject` of its own.
3. Its `NiPoint3` is complete, 12 bytes with alignment 4.
4. It declares the three enumerations, complete, 4 bytes each.
5. With the include on the first line at which its `NiPoint3` is complete,
   the unit compiles, its object is byte-identical to the object before
   with only the COFF timestamp masked, and its warnings are the same.

As for `BSSimpleList`, a header that gives a copy to several units keeps the
old text under `#ifdef FNV_KEEPS_OWN_TESANIMGROUP`; a unit that cannot move
defines the macro before its includes, with the reason. The macro is
transitional and leaves with the last such unit.

## Units moved

| Unit | Copy it had |
| --- | --- |
| `src/fallout_shared/tesanimgroup.cpp` (owner) | its own, in `tesanimgroup_types.h`, with its private `NiMemObject` and `NiRefObject` |
| `src/fallout/ai/combat/combatprocedureattackmelee.cpp` | `include/fnv/decl/TESAnimGroup.h` |
| `src/fallout/ai/combat/combatutilities.cpp` | `include/fnv/decl/TESAnimGroup.h` |
| `src/fallout/ai/combatcontroller.cpp` | `include/fnv/decl/TESAnimGroup.h` |
| `src/fallout/ai/middlehighprocess.cpp` | `include/fnv/decl/TESAnimGroup.h` |
| `src/fallout_shared/combatformulas.cpp` | `include/fnv/decl/TESAnimGroup.h` |
| `src/fallout/ai/playercharacter.cpp` | `src/fallout/ai/playercharacter_decls.h`, now a forward declaration for this unit |

Every object of the archive is byte-identical to the base's, apart from the
COFF timestamp. No symbol, recipe row or generated file changes.

## Units that did not move

| Unit | Copy | Rule | Reason |
| --- | --- | --- | --- |
| `src/fallout/ai/actor.cpp` | `fnv/decl/TESAnimGroup.h` | 2 | defines its own `NiMemObject` |
| `src/fallout_shared/tesobjectrefr.cpp` | `fnv/decl/TESAnimGroup.h` | 2 | defines its own `NiMemObject` |
| `src/fallout/ai/highprocess.cpp` | `fnv/decl/TESAnimGroup.h` | 2 | takes its own `NiMemObject` from `highprocess_decls.h` |
| `src/fallout_shared/animation.cpp` | its own | 2 | takes its own `NiRefObject` from `include/fnv/decl/NiRefObject.h` |
| `src/staging/blk_005e0000_od.cpp` | `fnv/decl/TESAnimGroup.h` | 3 | its `NiPoint3` is the 1-byte member-only class of `include/fnv/decl/NiPoint3.h` |
| `src/staging/blk_00920000_od.cpp` | `fnv/decl/TESAnimGroup.h` | 3 | as above |
| `src/fallout_shared/tesidlemanager.cpp` | `tesidlemanager_decls.h` | 3 | has no complete `NiPoint3` |
| `src/fallout/ai/movement/playermover.cpp` | `playermover_decls.h` | 4 | declares neither `ANIM_GROUP_MOVE_ENUM` nor `ANIM_GROUP_WEAPON_ENUM` |
| `src/fallout/ai/actor_magic.cpp` | `actor_magic_decls.h` | 1 | declares `unsigned int GetType()`, which the header lacks |
| `src/fallout_shared/bsanimgroupsequence.cpp` | `bsanimgroupsequence_decls.h` | 1 | as above |
| `src/fallout/ai/playercharacter_h_unit.cpp` | `playercharacter_decls.h` | 5 | names a member of the class before its `NiPoint3` is complete, so it does not compile on the header |

Six of them define `FNV_KEEPS_OWN_TESANIMGROUP`: `actor.cpp`,
`tesobjectrefr.cpp`, `highprocess.cpp`, the two `staging` units and
`playercharacter_h_unit.cpp`. The other five keep a copy that is their own.

Rules 2 and 3 wait on shared declarations of other classes:
`NiMemObject` and `NiRefObject` for rule 2, `NiPoint3` for rule 3. The
non-const `unsigned int GetType()` of rule 1 has no function row; the
recipe binds both units' name to `0x005f2420`, the const member that
returns `ANIM_GROUP_ENUM`.

## Calls the cross-unit conflict table lists

The class-copy conflict table of the four stand-in batches lists 5 bound
rows for `TESAnimGroup::GetType() const`, in 5 units, each call made on a
declared object of a copy without fields. Two units now see the real class:
`combatutilities.cpp` and `playercharacter.cpp`. Three do not:
`actor.cpp`, `animation.cpp` and `blk_00920000_od.cpp`, for the reasons in
the table above. Seeing the real class settles the declared type of those
calls' objects only; where each object comes from, and its lifetime, stay
open.

## Stand-in rows

The stand-in census has 21 rows that name a member of the class through
another name. None is replaced here. 19 are in units that are not on the
shared header. Two are in `middlehighprocess.cpp`, which is:

- `fnv_00923960::TESAnimGroupX::GetType` returns `unsigned int` against the
  signed enumeration `ANIM_GROUP_ENUM`, a pair the substitution rules
  refuse.
- `fnv_009231d0::EquipSequence::FUN_005f2420` returns `int`, a pair the
  rules accept. Calling `GetType()` on the real class makes the unit's
  `switch` run on `ANIM_GROUP_ENUM`, and the compiler then gives one more
  warning (`-Wswitch`), which the rules refuse. The stand-in also casts a
  second object that is not an animation group.

## Integration checks

Run these on every change that touches the header, a copy of the class, or
the units that include it.

(a) Every unit that includes `fnv/tes_anim_group.h` builds. The assertions
in the header check its `NiPoint3`, the three enumerations and the class's
size there.

(b) The 13 members are defined once in the archive, each in
`tesanimgroup.cpp.obj`, and no other unit defines a name of the global
class. At this change: 13 names, one definition each.

(c) The count of names with differing COMDAT definitions in the archive does
not rise. At the declaration move: 525 before and after; at the repair of
defect 2: 519 before and after.

(d) `objects.anim_group_sound_entry_size` passes: the sound entry resize
sizes its block by the x64 entry size.

The checks of `docs/shared-simple-list.md` hold unchanged. For a change that
only moves declarations, no object of the archive changes apart from the
timestamp; the repair of defect 2 changes `tesanimgroup.cpp.obj`.

## Not covered

- The destructor. The recipe has the body at `0x005f22d0` under the stand-in
  `FUN_005f22d0`, and that body uses the 32-bit offsets of defect 1. Until
  it is rewritten on the declared members, `~TESAnimGroup` stays undefined
  and the class has no vtable in the archive. No object refers to either.
- The constructor. The owning unit calls
  `fnv_005f3a20::TESAnimGroupEx::TESAnimGroupEx(unsigned short)`, which no
  object defines, before and after this change.
- The defects above.
- `FOPipboyManager::IsUnk28Set` (`0x00974d90`,
  `src/fallout/ai/processlists.cpp`) and `MiddleHighProcess::FUN_00929260`
  (`0x00929260`, `src/fallout/ai/middlehighprocess.cpp`), which `0x005f3a20`
  calls on the object for the key that `g_kTextKeyA` names: the first reads
  a byte and, when it is zero, the second writes one. On windows-x64 the
  first reads offset 0x28 and the second writes 0x3c, the offsets of those
  classes' own fields. Which field of `TESAnimGroup` each stands for was not
  established, so neither is classified: 0x28 is the 32-bit offset of
  `m_cByteAfterSpeed` and byte 40 of `speed` on windows-x64, and 0x3c is
  padding after `m_ucDecal` on windows-x64 and no field of the 32-bit
  declaration.
- Five units forward declare the global class as `struct`:
  `processlists.cpp`, `extradataobjects.cpp`, `inventorychanges.cpp`,
  `tes.cpp` and `tesconditionfunctions.cpp`. No symbol in the archive names
  the global class with the `struct` key today, so these declarations change
  no name; a symbol made in one of those units would name the class with
  that key, which is not the owner's. They are to be made `class` in the
  class-key step, or at the latest when one of those units moves. Two moved
  units already see a `struct` declaration of the global class beside the
  definition: `combatformulas.cpp` before it, through
  `fnv/decl/HackAnim.h`, and `middlehighprocess.cpp` after it. Their builds
  report no `-Wmismatched-tags` warning, so that warning does not detect
  the mix in this build.
- Bodies outside the owning unit and the calls of `0x005f3a20`, and how they
  reach the fields.
