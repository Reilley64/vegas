# One shared declaration of BSSimpleList

VEGAS-17 owns the `bscore` units. This change gives the list template
`BSSimpleList<T>` one declaration that units share, moves 559 units onto it,
has the owning unit emit the list for the element types other units require,
and removes a second copy of the member bodies (VEGAS-89). It is a first
increment: what stays open is under "Units that did not move" and "Not
covered". The checks that later changes to the list must pass are under
"Integration checks".

## Where the declaration lives

`include/fnv/bs_simple_list.h`. `include/fnv/` already holds the native
declarations that several units share, named in lower case after the class:
`ni_ref_object.h`, `native_fixed_string.h`, `simple_list_node_view.h`. The
headers in `include/fnv/decl/` are a different thing: they declare members
without a layout.

## What it declares

The two fields, and the ten members that `build/units.json` gives to
`src/bscore/bssimplelist_h_unit.cpp`, with that unit's signatures:

| Address | Member | Recipe size | Units with a symbol row at the address |
| --- | --- | --- | --- |
| `0x0096a2d0` | `BSSimpleList()` | 33 | 146 |
| `0x00470440` | `BSSimpleList(T& item)` | 36 | 6 |
| `0x0046ffb0` | `~BSSimpleList()` | 19 | 125 |
| `0x006815c0` | `T& GetItem()` | 14 | 444 |
| `0x00726070` | `BSSimpleList<T>* GetNext()` | 17 | 338 |
| `0x008256d0` | `bool IsEmpty()` | 49 | 182 |
| `0x00905820` | `void AddTail(T& item)` | 185 | 93 |
| `0x005ae3d0` | `void AddHead(T& item)` | 187 | 135 |
| `0x0063f7b0` | `void RemoveHead()` | 114 | 108 |
| `0x00470470` | `void RemoveAll()` | 110 | 120 |

The last column counts the units of the recipe that have a row in their
`symbols` table at the address, under any name.

Eight of the ten function rows of the owning unit carry the template's name,
`BSSimpleList<InventoryStackRecord*>`. Two carry a stand-in name:
`0x0096a2d0` is `fnv_00722f60::SL::SL()` and `0x0046ffb0` is
`EffectSettingList::~EffectSettingList()`. This change respells no recipe
key, so both stay. They are recorded against criterion 4 of VEGAS-11.

Nothing else is declared. The list has more members, but the recipe gives
them to other units: `SetItem` at `0x00726c60` to
`fallout_shared/tesform.cpp` and `ItemsInList` at `0x005ae380` to
`fallout/interface/interfacemanager.cpp`. `Remove`, `IsInList`, `Sort` and
`AddTail(const T&)` are declared by some copies and have no function row
under the template's name. They join the header when their owner is settled.

## How the bodies are provided

The header has no body. Each of the ten members has one function row in the
recipe, with a size, in the owning unit, and between 6 and 444 units carry a
symbol row that binds a name to its address. So the original called each of
them out of line, at one address for every element type. The owning unit
therefore defines them (`bssimplelist.inl`) and emits them, once per element
type, by explicit instantiation. This is the route of
`docs/simple-list-default-constructor.md`, now for the whole class.

No unit other than the owner may define a body of these members. A unit on
the shared header cannot: it sees declarations only.

## Element types

The owning unit emits the list for an element type when all of these hold.
The list is `src/bscore/bssimplelist_elements.inl`.

- A unit requires a name of that list that no object defines.
- The element type is a builtin, a pointer to a builtin, or a pointer to a
  class, struct or union named at global scope. The members need the
  pointee's name and class-key and nothing else, so the file forward declares
  the pointee. The key is the one the requiring units use.
- The pointee's name is not a placeholder: not `FUN_...`, `S_<address>...`,
  `...StandIn`, `..._ctx`, a nested name flattened with `__`, or a name with
  an address fragment. Such a pointee is replaced first.
- Every unit that requires the name declares the list as 16 bytes with the
  item at offset 0 and the next pointer at offset 8, measured by the compiler
  in that unit.
- No row of the recipe gives one of the ten members of that list to another
  unit. The owner instantiates the whole class, so it would define all ten
  names for the type. If a function row or a symbol row of any unit binds
  one of those names to an address whose function row is in a unit other
  than the owner, the body is that unit's, and the type is not emitted.

The last rule keeps out one type today. The recipe binds
`BSSimpleList<unsigned short>::RemoveAll` to `0x00b64ec0`, a function row of
`bsshader/bsshaderaccumulator.cpp`, and
`BSSimpleList<unsigned short>::RemoveHead` to `0x00b99730`, a function row
of `bsshader/bsbatchrenderer.cpp`. No unit requires an undefined name of
that list yet, so nothing changed, but the type must not enter the list.
The rule looks at the ten member names only. For 20 other element types
the recipe gives `SetItem`, `ItemsInList`, `GetSize` or a placeholder member
to `tesform.cpp`, `interfacemanager.cpp` or `modelloader.cpp`. The owner
does not define those members, so those types may be emitted.

The list is kept by hand under these rules. Check it again whenever a
requiring unit changes the class-key of a pointee, as VEGAS-11 batches do.
The key in the list is the requiring units' key, and another declaration in
the tree may have the other one: `TileCollection` is a `class` in
`include/fnv/decl` and `MagicEffectContext` is a `class` in
`include/layout_support.h`, and both are listed as `struct`. 60 of the 127
pointees are declared with the other key somewhere in the tree.

Of 176 element types that undefined names use, 131 are emitted. One more,
`ModifierEntryView*`, is emitted for the unit that lost its second copy
(below). The other 45:

| Reason | Element types | Undefined names that stay |
| --- | --- | --- |
| The pointee has a placeholder name | 19 | 27 |
| The pointee is nested in a class or in a namespace, so the owner would have to declare the enclosing scope | 12 | 19 |
| A requiring unit declares the list as an empty class, 1 byte | 5 | 18 |
| Not a pointer or builtin: a list of lists, a struct by value, two list-box items | 4 | 8 |
| `TESRegionData*`, required as `class` by some units and as `struct` by others; counted once per key | 2 | 6 |
| A Windows SDK tag, `_ULARGE_INTEGER` | 1 | 2 |
| The owning unit declares its own `struct EnchantmentItem`; the requirer says `class` | 1 | 1 |
| `SpellItem*`: the one name required is `AddHead`, which the owning unit declares as an explicit specialisation and never defines | 1 | 1 |

The default constructor for `const char*` stays emitted alone, as before:
`surgerymenu`, `activeeffect` and `tesobjectcell` require other members of
that list and declare it as an empty class.

Inside the emitted element types, 22 names stay undefined because the name
itself is not a shared member: `SetItem`, `ItemsInList`, `GetSize` and
`Remove` (14), `AddHead` taking a const reference (7), and one placeholder
member name, `FUN_008256d0`.

The owner instantiates the whole class, so it defines names that no unit
requires yet. Of its 1,333 definitions of list members, 262 are required by
another object and 1,071 are not; 1,065 of the 1,071 came with this change.
A definition counts as required when another archive member has an
undefined symbol of that name. An unrequired definition binds the first
unit that names it, with no edit and no diagnostic. Checks (a) and (b)
under "Integration checks" are the guards for that.

## The rule for moving a unit

A unit's own copy of the template is replaced by
`#include "fnv/bs_simple_list.h"` when both hold:

1. The compiler, in that unit, shows the copy to be compatible: two public
   fields `T m_item; BSSimpleList<T>* m_pkNext;` in that order, no base
   class, no member with a body in the class, none virtual or static.
2. After the replacement the unit compiles, and its object is byte-identical
   to the object before, with only the COFF timestamp masked.

Condition 2 covers what condition 1 cannot see. A unit that calls a member
the header lacks stops compiling. A call that would bind to another overload
changes a relocation. Neither passes.

When a copy sits in a header that many units include and some of them fail
condition 2, the header keeps the old text under
`#ifdef FNV_KEEPS_OWN_BSSIMPLELIST`, and each failing unit defines that macro
before its includes, with the reason. Those units are on their copy; the
others are on the shared header.

The macro is transitional. The five units that define it call `SetItem`
(`0x00726c60`, owned by `tesform.cpp`) or `Remove`. It is removed, with the
old text behind it, when `SetItem`, `Remove` and `ItemsInList` (`0x005ae380`,
owned by `interfacemanager.cpp`) are declared in the header and emitted by
their owners.

Later steps change objects, so they need a wider proof. The steps of this
change use three, each measured per object against the build of the parent
commit from the same path:

| Step | Objects that may differ | What may differ in them |
| --- | --- | --- |
| Replace a copy by the include | none | nothing |
| The owner emits more element types | the owner's | added select-any definitions; every function that existed has the same instructions and relocations; no new undefined symbol |
| Remove a second copy of the bodies | the unit that held the copy, and the owner | the copy's definitions leave; a function that expanded a removed body in line may call the owner's definition of the same member instead; each such function is listed |

Replacing a stand-in class by the template, which is the next step, renames
symbols. Its proof is the one the stand-in batches of VEGAS-11 used: the
object is equal once the retired names are respelled.

## Integration checks

Run these three on every change that touches the header, the element list,
a copy of the template, or the class-key of a pointee. They were run on this
change, on the windows-x64 archive of its last commit.

(a) Layout per requirer. Take every name of `BSSimpleList<E>` that the
owning unit's object defines and that another object of the archive
requires. Not only the names a change adds: all of them. For each requiring
unit and each `E`, have the compiler measure `BSSimpleList<E>` in that unit
with the unit's own command line. It must be 16 bytes with fields at offsets
0 and 8. Result: 231 pairs of unit and list, in 106 units and 134 lists; 229
pass. The two that do not are older than this change and are recorded under
"Units that did not move" and "Not covered": `bsfacegenanimationdata.cpp`
and `projectile.cpp`. A new exception fails the check.

(b) Differing definitions. Scan every definition of every external name in
every archive member. No name of a class named `BSSimpleList` may have two
definitions, and the count of names with differing definitions in the whole
archive may not rise. Result: 1,343 defined names of such classes, 0 with
two definitions; 528 names with differing definitions before and 525 after,
a change of −3 with none entering.

(c) Class-keys. For every forward declaration in
`bssimplelist_elements.inl`, compare its key with the key in the symbol of
every object that requires a name of that list, and with the key in the
owner's own definitions. All must be equal. Result: 127 forward
declarations, each required by another object, 0 mismatches.

## What was measured

At 88e299932 the compiler sees 105 declarations of the global template with
a body, in the 2,223 units of the windows-x64 archive. By fields and member
signatures they fall into 67 classes:

| Class | Declarations | Units | Moved to the header |
| --- | --- | --- | --- |
| The ten shared members exactly, declared only (1 class; 20 token-identical copies) | 20 | 21 | 20 declarations, 21 units |
| A subset of the ten, declared only (14 classes) | 19 | 19 | 19 declarations, 19 units |
| The same fields, declared only, with members the header lacks (23 classes) | 31 | 540 | 15 declarations, 519 units |
| Other fields, no fields, or bodies in the class (29 classes) | 35 | 35 | none |

Two of the declarations in the third row carry 507 of its units:
`include/layout_support.h` (412, of which 411 moved) and
`src/fallout_shared/layout_support.h` (95, of which 91 moved). The tree also
holds 19 bodies of the template and 2 specialisations that no unit of the
archive includes; they were left alone.

559 units use the header's declaration: each sees a declaration that was
replaced, and does not define the keep macro. 561 units of the archive
include the header. The other two, `bgsmusictype.cpp` and
`navmeshobstaclemanager.cpp`, rename the template with a macro and use
their own copy under the real name; they include `layout_support.h` too, so
they compile the header's text as a declaration of the renamed template.

After the first commit all 2,299 objects of the build are byte-identical to
the parent's.

Forced link of every archive member, windows-x64, 2,223 members in the same
order:

| | 88e299932 | Header and units | Owner emits | Second copy removed |
| --- | --- | --- | --- | --- |
| Undefined names | 35,529 | 35,529 | 35,283 | 35,283 |
| Duplicate symbols | 0 | 0 | 0 | 0 |
| Imports | 137 | the same | the same | the same |
| Objects that differ from the column before | | 0 | 1 | 2 |
| Names with differing definitions in the archive | 528 | 528 | 528 | 525 |

246 names leave and none enters. Each is a member of the template under its
own name that the owning unit now defines. The partition of undefined names
bound 173 of them to an address of the table above: 74 to `AddHead`, 53 to
`IsEmpty`, 30 to `RemoveHead`, 15 to the default constructor and 1 to
`RemoveAll`. It bound no address for the other 73.

Counted against the recipe instead, 74 of the 246 have no row with the same
name in any unit that requires them. The count is per name: the name's
demangled text, with the calling convention and the pointer-size spellings
folded, is compared with every function row and symbol row of each requiring
unit. For one more name, some but not all requiring units have such a row.
No recipe row was added for any of them. The 74 split in two:

- 47: a requiring unit has a row at the member's address under another
  name, a stand-in or a folded constructor. The binding is recorded, under
  the other name.
- 27: no requiring unit has any row at the member's address. These bindings
  are INFERRED from the template's name alone:
  - the destructor, `0x0046ffb0`, for `BGSHeadPart*`,
    `DistantTreeTextureInfo*`, `EffectSetting*`, `ExtraDataList*`,
    `IdleReplayDelayEntry*`, `MediaSet*`, `PaddedFloatRecord*`,
    `RegionPointList*`, `ScriptLocalVariable*`, `ScriptReferencedObject*`,
    `ScriptVariableInfo*`, `SkySound*`, `SoundDescriptor*`,
    `TESAmmoEffect*`, `TESObjectREFR*`, `int*`, `InventoryItemEntry*`,
    `KFModel*`, `LitWaterRef*` and `TileCollection*` (20);
  - the default constructor, `0x0096a2d0`, for `EffectSetting*`,
    `ScriptReferencedObject*`, `ScriptVariableInfo*`, `TESAmmoEffect*`,
    `TESConditionItem*` and `InventoryItemEntry*` (6);
  - `GetItem`, `0x006815c0`, for `VATSCommand*` (1).

The owning unit's object gains 1,302 definitions with the 131 element
types, and ten more with `ModifierEntryView*`. Each is select-any and each
name has one definition in the archive.

## The second copy (VEGAS-89)

`src/bscore/bssimplelist.cpp` held the ten bodies again, with the same
address tags, and instantiated the class for `InventoryStackRecord*` as the
owner does. It has no function row at any of the ten addresses. Nine bodies
were token-identical to the owner's. The destructor called `RemoveAll`
through a cast to the stand-in `FileMatchList`.

So `~BSSimpleList`, `RemoveAll` and `RemoveHead` of that list had two
select-any definitions each with different content, and the linker kept the
one it loaded first. The copy and its instantiation are removed. In that
unit's object the ten definitions and their three cleanup blocks leave, and
two functions change:

| Function | Before | After |
| --- | --- | --- |
| `ItemChangeList::SortItems` | expanded the item constructor of the copy in line | calls `BSSimpleList<InventoryStackRecord*>::BSSimpleList(InventoryStackRecord*&)`, and has a cleanup block because the call may throw |
| `ModifierRoutingList::FUN_00937380` | expanded `AddHead` of the copy in line | calls `BSSimpleList<ModifierEntryView*>::AddHead` |

Both bodies were token-identical to the owner's. The owner emits the list
for `ModifierEntryView*`, so the second call has a definition.

## Units that did not move

- Five units keep the old text under `FNV_KEEPS_OWN_BSSIMPLELIST`:
  `vats.cpp` calls `Remove`; `bgscamerapath.cpp`, `bgsdehydration.cpp`,
  `medialocationcontroller.cpp` and `tescaravan.cpp` call `SetItem`.
- 16 compatible copies that one unit each uses were left: 8 units call
  `SetItem`, 5 call `ItemsInList`, 2 rename the template with a macro, and
  `processlists.cpp` passes a list member an argument that only a const
  reference accepts.
- 35 copies differ: 15 name the fields `item` and `next`, 11 have no fields,
  7 have other fields, and 2 have the shared fields with bodies in the
  class. Four of the 35 define member bodies in the class, so the unit
  compiles its own body where the owner has one. They move first in the
  next step:
  - `src/bsmenu/menu.cpp:110` and `src/bssystem/filefinder.cpp:289`, with
    the shared fields;
  - `src/fallout_shared/bgsheadpart.cpp:95`, whose destructor is empty
    where the owner's calls `RemoveAll`;
  - `src/fallout/ai/combat/explosion.cpp:679`, which has no fields.
- Two of the 35 declare the list as 8 bytes and require names that the
  owner defines for a 16-byte list. Both were so before this change, and
  check (a) records them:
  - `src/fallout_shared/facegen/bsfacegenanimationdata.cpp`: the list is
    two `int` members, 8 bytes, alignment 4. The unit requires the default
    constructor of `BSSimpleList<Actor*>`, which writes 16 bytes.
  - `src/fallout/ai/combat/projectile.cpp`: the template at
    `src/fallout/ai/combat/projectile_decls.h:77` has one field,
    `unsigned int items[2]` at line 82, 8 bytes, alignment 4. The unit
    requires the default constructor and the destructor of
    `BSSimpleList<InventoryStackRecord*>`.
- Units that reach the list through another class name were not touched.

## Explicit specialisations in other units

A unit that declares `template <> class BSSimpleList<E*>` has a private
copy of the list for that element type. The owner emits the list for `E*`
from the shared declaration. Where the two disagree, a member that the unit
names binds to the owner's body for another layout, and nothing reports it.
Where the unit requires no such member today the binding is latent.

22 such sites exist for emitted element types, 15 types in all. 21 are seen
by 14 units of the archive; one is in a header that no unit includes.

| Site | Element type | Size in the unit | Against the shared declaration | Owner members the unit requires now |
| --- | --- | --- | --- | --- |
| `src/fallout/ai/highprocess_decls.h:879` | `TESForm*` | 16 | same fields | none |
| `src/fallout/ai/highprocess_decls.h:886` | `TESTopicInfo*` | 16 | same fields | default constructor, destructor, `AddHead`, `IsEmpty`, `RemoveHead` |
| `src/fallout/ai/middlehighprocess.cpp:574` | `TESClass*` | 16 | same fields | none |
| `src/fallout/interface/menus/dialogmenu_runtime.h:70` | `MediaSet*` | 16 | same fields | none |
| `src/fallout/magic/activeeffect_local.h:137` | `BGSPerkEntry*` | 1 | empty class | none |
| `src/fallout/magic/activeeffect_local.h:142` | `MagicHitEffect*` | 16 | same fields | `IsEmpty` |
| `src/fallout/magic/activeeffect_local.h:170` | `ActiveEffect*` | 1 | empty class | none |
| `src/fallout_shared/bgscamerapath.h:91` | `ScriptVariableInfo*` | 1 | empty class | none |
| `src/fallout_shared/bgsdecalmanager_decls.h:75` | `TESTopic*` | 1 | no fields, one member | none |
| `src/fallout_shared/bgslistform_decls.h:117` | `TESForm*` | 16 | same fields | none |
| `src/fallout_shared/bgslistform_decls.h:145` | `BGSQuestObjective*` | 16 | same fields | none |
| `src/fallout_shared/bgslistform_decls.h:152` | `EffectSetting*` | 16 | same fields | `AddHead` |
| `src/fallout_shared/bgslistform_decls.h:160` | `MediaSet*` | 16 | same fields | none |
| `src/fallout_shared/bgslistform_decls.h:214` | `BGSPerkEntry*` | 16 | same fields | none |
| `src/fallout_shared/facegen/bsfacegenmorphdata_decls.h:27` | `BGSPerkEntry*` | 1 | empty class | none |
| `src/fallout_shared/region system/tesregiondataimposter_decls.h:32` | `TESGrass*` | 1 | empty class | none |
| `src/fallout_shared/teshair_decls.h:25` | `BGSQuestObjective*` | 16 | same fields | none |
| `src/fallout_shared/tesobjectcell_packet.h:157` | `TESObjectREFR*` | 16 | fields named `item`, `next` | default constructor, destructor |
| `src/fallout_shared/tesspelllist.cpp:66` | `int` | 16 | fields named `item`, `next` | destructor |
| `src/fallout_shared/tesweatherlist_decls.h:39` | `WeatherEntry*` | 16 | same fields | none |
| `src/staging/blk_00400000_od.cpp:1007` | `TESForm*` | 16 | same fields | none |
| `src/fallout_shared/region system/tesregiondataimposter.h:21` | `TESGrass*` | not compiled | no fields, one member | none |

Seven sites declare an emitted type without fields: the six 1-byte rows and
the uncompiled one. None of their units requires a member of the owner
today, which is why check (a) passes; each is a latent silent binding. The
five rows with a member in the last column bind to the owner now, at the
same size and offsets.

## Not covered

- 1,398 undefined names are still attributable to the list: 1,340 are bound
  to one of the ten addresses and 58 use a list name for a member that
  another unit owns or that has no row. By cause:

  | Cause | Names |
  | --- | --- |
  | A stand-in class with another name, used as the receiver | 851 |
  | A constructor or destructor of another class that the original linker folded into `GetItem`'s 14 bytes | 353 |
  | The template's own name: the reasons under "Element types" | 104 |
  | A differently named copy of the template, or a class named after the list | 45 |
  | A free function, or a name the recipe binds by another route | 45 |

  The 851 are the next step: replace the stand-in by `BSSimpleList<T>` in
  units that are on the shared header. The unit declares the stand-in as 16
  bytes for 269 of them, without members for 478, and with another size or
  an unmeasured one for 104.
- Receivers. Emitting a name does not show that every requirer passes a
  16-byte list. Check (a) measures the requirer's own declaration of the
  list, not the object it passes.
- The two 8-byte lists. `bsfacegenanimationdata.cpp` (8 bytes, two `int`
  members) requires the default constructor of `BSSimpleList<Actor*>`, and
  `projectile.cpp` (8 bytes, `unsigned int items[2]`) requires the default
  constructor and the destructor of `BSSimpleList<InventoryStackRecord*>`.
  The owner's bodies write 16 bytes. Both units required those names before
  this change and nothing here alters them.
- The 27 INFERRED bindings and the two stand-in names in the owner's
  function rows, above. No recipe row was added or respelled.
- The explicit specialisations of the table above, and the four copies with
  bodies in the class.
- `SetItem`, `ItemsInList`, `Remove`, `IsInList` and `Sort` are not in the
  header.
- The owning unit still declares a specialisation of the list for
  `TESWeather::WeatherSound*` with a two-argument constructor at
  `0x004b0680`, and explicit specialisations of `RemoveAll` for
  `ActorCause*` and `AddHead` for `SpellItem*` that it never defines.
- Nothing executes these functions. No linking program loads the owning
  unit, and it cannot be linked into a test, because it requires names the
  archive does not define. Windows execution: not run.
