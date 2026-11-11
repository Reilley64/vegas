# One shared declaration of BSSimpleList

VEGAS-17 owns the `bscore` units. This change gives the list template
`BSSimpleList<T>` one declaration that units share, moves 559 units onto it,
has the owning unit emit the list for the element types other units require,
and removes a second copy of the member bodies (VEGAS-89). It is a first
increment: what stays open is under "Units that did not move" and "Not
covered". The checks that later changes to the list must pass are under
"Integration checks".

A second step, on a365fda14, is described under "Step 2". It declares two
more members, has the two units that own them emit them, moves 16 more units
onto the header, removes 23 private specialisations and replaces three
stand-in classes by the list. Sections above "Step 2" describe the first
step and keep its numbers, except where a sentence says "since step 2".

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

Since step 2 the header also declares the two members that the recipe gives
to other units under the template's name:

| Address | Member | Recipe size | Owning unit |
| --- | --- | --- | --- |
| `0x00726c60` | `void SetItem(const T& item)` | 33 | `fallout_shared/tesform.cpp` |
| `0x005ae380` | `unsigned int ItemsInList()` | 70 | `fallout/interface/interfacemanager.cpp` |

Nothing else is declared. `Remove`, `IsInList`, `Sort` and
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

Since step 2 there are three owners, and "the owner" of a member is the unit
with its function row. "How a member owned by another unit is emitted",
under "Step 2", has the mechanism.

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

The macro is transitional. Five units defined it after the first step. Since
step 2 one does: `vats.cpp`, which calls `Remove`. The macro and the old
text in `include/layout_support.h` leave when `Remove` has an owner.

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

(a) Layout per requirer. Take every name of `BSSimpleList<E>` that an
owning unit's object defines and that another object of the archive
requires. Not only the names a change adds: all of them. For each requiring
unit and each `E`, have the compiler measure `BSSimpleList<E>` in that unit
with the unit's own command line. It must be 16 bytes with fields at offsets
0 and 8. Result: 231 pairs of unit and list, in 106 units and 134 lists; 229
pass. The two that do not are older than this change and are recorded under
"Units that did not move" and "Not covered": `bsfacegenanimationdata.cpp`
and `projectile.cpp`. A new exception fails the check. Step 2: 236 pairs in
109 units and 135 lists; 234 pass; the same two exceptions.

(b) Differing definitions. Scan every definition of every external name in
every archive member. No name of a class named `BSSimpleList` may have two
definitions, and the count of names with differing definitions in the whole
archive may not rise. Result: 1,343 defined names of such classes, 0 with
two definitions; 528 names with differing definitions before and 525 after,
a change of −3 with none entering. Step 2: 1,356 defined names, 0 with two
definitions; 525 before and after, none entering.

Since step 2 check (b) is the only detector for two more names. They were
ordinary external definitions, for which a second definition is a
duplicate-symbol error at link time, and they are select-any now, for which
the linker keeps one definition and reports nothing:

- `BSSimpleList<TESFile*>::SetItem(TESFile* const&)`, defined by
  `tesform.cpp`;
- `BSSimpleList<EffectSetting*>::ItemsInList()`, defined by
  `interfacemanager.cpp`.

Check (b) must find each of the two with exactly one definition, in that
unit. Step 2: it does.

(c) Class-keys. For every forward declaration in
`bssimplelist_elements.inl`, compare its key with the key in the symbol of
every object that requires a name of that list, and with the key in the
owner's own definitions. All must be equal. Result: 127 forward
declarations, each required by another object, 0 mismatches. Since step 2
the check also reads the forward declarations in the two instantiation
blocks, at the end of `tesform.cpp` and of `interfacemanager.cpp`, against
the symbols of that member. Step 2: 127 and 12 forward declarations, 0
mismatches.

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

After the first step. "Units moved" under "Step 2" has what moved since.

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

22 such sites existed for emitted element types after the first step, 15
types in all. 21 were seen by 14 units of the archive; one is in a header
that no unit includes. Step 2 removed 16 of them: "Private specialisations".

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

## Step 2

Made on a365fda14, in six code commits. Forced link of every archive member,
windows-x64, 2,223 members in the same order at every commit:

| | a365fda14 | Header | Owners emit | 14 units | 23 specialisations | One more type | Stand-ins |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Undefined names | 35,283 | 35,283 | 35,271 | 35,271 | 35,271 | 35,271 | 35,266 |
| Left / entered | | 0 / 0 | 12 / 0 | 0 / 0 | 0 / 0 | 0 / 0 | 5 / 0 |
| Duplicate symbols | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| Imports | 137 | the same | the same | the same | the same | the same | the same |
| Objects that differ from the column before | | 0 | 2 | 0 | 0 | 1 | 3 |
| Names with differing definitions in the archive | 525 | 525 | 525 | 525 | 525 | 525 | 525 |

Every build has 2,317 steps, none failed, and 20,786 warning lines that are
equal once line and column are removed. `src/generated` is untouched.

The fifth commit, "One more type", goes with the sixth: it emits
`ItemsInList` for `TESObjectREFR*`, a name that nothing requires until the
sixth commit replaces the stand-in that calls it. The two are integrated
or reverted together.

### How a member owned by another unit is emitted

The recipe has one function row for `SetItem`, in `tesform.cpp` under
`BSSimpleList<TESFile*>`, and one for `ItemsInList`, in
`interfacemanager.cpp` under `BSSimpleList<EffectSetting*>`. Other units
bind the same address under the name of other element types. So each is one
folded body, as the first ten are, with one mangled name per element type.

- The shared header declares the member and has no body.
- The owning unit defines it as a template member. Before, it defined an
  explicit specialisation for its one element type; the body text is the
  same.
- At the end of the owning unit stands one member-level explicit
  instantiation per element type, for example
  `template void BSSimpleList<TESQuest*>::SetItem(TESQuest* const&);`.
  It defines that member and no other member of the class.
- `bssimplelist_h_unit.cpp` instantiates the whole class per element type. A
  whole-class explicit instantiation defines only the members whose
  definition is visible at that point. That unit sees no definition of
  `SetItem` or `ItemsInList`, so it does not define them. Measured: its
  object is byte-identical before and after the two members were declared,
  and each of the 15 names of the two members has one definition in the
  archive, in the owning unit's object.

The two definitions the owners had before were ordinary external functions.
They are select-any now, each with the bytes it had. Check (b) lists the
two names.

"One folded body" describes the original, which is x86: there an
`unsigned int` and a pointer are both four bytes, so one body serves every
element type. In the windows-x64 archive the fold holds for pointer element
types only:

- `SetItem` for the eleven pointer types is 12 bytes with one content.
- `SetItem` for `unsigned int` is a body of its own: 9 bytes, with a 32-bit
  store.
- `ItemsInList` is emitted for pointer element types only. Its body reads
  the item through `SimpleListNodeView`, a pointer-sized field, whatever `T`
  is, so for a four-byte item it would read eight bytes. A `static_assert`
  in the body requires `sizeof(T) == sizeof(void*)`. The object is
  byte-identical with and without the assertion. The three instances are
  44 bytes with one content.

The recipe also binds `0x005ae380` for a type that is not a pointer:
`RegionListAccess<unsigned int>::FUN_005ae380`, a symbol row of
`tesregiondatasound.cpp`. That is a stand-in name, not the template's.
Nothing is emitted for it, and `ItemsInList` for `unsigned int` cannot be
emitted from this body.

An element type is listed for a member when another object requires that
name, every requiring unit has a recipe row that binds the name to the
member's address, every requiring unit declares the list as 16 bytes with
fields at 0 and 8, and the pointee passes the rule under "Element types".
The owner's instantiation defines one name per type, so the last rule of
that section reduces to: no other unit has a function row for that name.

| Member | Emitted for | Not emitted |
| --- | --- | --- |
| `SetItem` | `TESFile*` (own), `BGSCameraShot*`, `MediaSet*`, `TESCaravanCard*`, `TESForm*`, `TESGrass*`, `TESObjectREFR*`, `TESPackage*`, `TESQuest*`, `TESTopic*`, `TESTopicInfo*`, `unsigned int` | `TESClass*` and `TESRace*`: the requirers declare `SetItem(T&)`, a non-const reference |
| `ItemsInList` | `EffectSetting*` (own), `TESPackage*`, `TESObjectREFR*` | `TESRegionData*`: required as `class` and as `struct`. `BGSMusicType::MusicTrack*`: nested. Any type that is not pointer-sized, such as `unsigned int` |

`GetSize` is a second name at `0x005ae380`, with return type `int`, that
three units declare for `TESClass*` and `TESRace*`. It is a rename and was
not made. `Remove` (one name, `VATSCommand*`) and `IsInList` (one name) have
no recipe row and no owner.

`interfacemanager.cpp` declared the template without fields and reaches it
through pointers only. On the 16-byte declaration each of its 291 functions
has the same instructions and relocations.

### Units moved

16 units, the two owners among them: 575 units use the header's declaration
now, 559 before.

- Four drop the keep macro: `bgscamerapath.cpp`, `bgsdehydration.cpp`,
  `medialocationcontroller.cpp`, `tescaravan.cpp`. The old text leaves
  `src/fallout_shared/layout_support.h`.
- Ten single-unit copies are replaced by the include: `lowprocess.cpp`,
  `falloutradio.cpp`, `magicitemform.cpp`, `magicitemobject.cpp`,
  `packagelist.cpp`, `tesregiondataimposter.cpp`, `tesregiondatalist.cpp`,
  `tesspelllist.cpp`, `testopicinfo.cpp`, `teslandtexture.cpp`.
- The two owners, `tesform.cpp` and `interfacemanager.cpp`.

Each of the 14 objects that are not an owner's is byte-identical to the
object before.

Of the 16 compatible single-unit copies of the first step, 11 moved. Each of
the other five was tried and put back:

| Unit | Why it stays |
| --- | --- |
| `effectsetting.cpp` | Its copy declares no destructor, and `EffectSettingList` derives from the list. The shared declaration has a destructor, so the unit would gain a call of it. The object differs. |
| `bgstextureusemap.cpp` | Calls the list's `IsEmpty` under the member name `FUN_008256d0`. |
| `processlists.cpp` | Passes `AddHead` an argument that only a const reference accepts. |
| `bgsmusictype.cpp`, `navmeshobstaclemanager.cpp` | Rename the template with a macro. |

`vats.cpp` keeps the macro: it calls `Remove`.

### The four copies with bodies in the class

None moved. For each, the question was whether the recipe shows that the
unit calls the owner's address where the copy has a body of its own. Each
of the first three was also tried on the shared declaration.

| Copy | Bodies in the class | Recipe rows of the unit at list addresses | Verdict |
| --- | --- | --- | --- |
| `src/bsmenu/menu.cpp:110` | default constructor, same text as the owner's | none | Same class, same layout. No row shows a call of `0x0096a2d0`. Moving would replace the body by a requirement of the constructor for `Tile__TileTemplate*`, a placeholder pointee that the owner cannot emit. Tried: the object differs. Stays. |
| `src/bssystem/filefinder.cpp:289` | default constructor, destructor, `IsEmpty` | `AddHead(Actor* const&)` at `0x005ae3d0`, `RemoveAll` at `0x00470470` | Same class, same layout. The unit has rows for the two members it only declares and none for the three it defines, and its recipe flags have `/Ob1`, which expands such bodies in line. Its `AddHead` takes a const reference, which the shared signature does not. Tried: it does not compile. Stays. |
| `src/fallout_shared/bgsheadpart.cpp:95` | destructor, empty | default constructor under the template's name at `0x0096a2d0`; `0x0046ffb0` under `EffectSettingList::~EffectSettingList` | Same class with a differing transcription: fields `T* item`, `next`, private, 16 bytes. Moving would give `BGSHeadPart::BGSHeadPart()`, the function row at `0x005e72c0`, a cleanup call of the list destructor. The unit does bind `0x0046ffb0`, but a symbol row belongs to the unit, not to a function: it does not attribute the call to the constructor. The unit also holds the destructor of the class, written through a stand-in with its own list member. Tried: the object differs. The unit stays on its copy until function-level evidence shows the call in the constructor. A lead, INFERRED and not verified here: the exception handlers of the constructor and of a destructor share an address. |
| `src/fallout/ai/combat/explosion.cpp:679` | 22 virtual functions, no fields | none for this class | Another class under the list's name: a table of virtual slots, used once to call slot 21 on an object another function returns. It is a different class and needs its own identity, a name and a declaration of its own, which is VEGAS-11 work. Not renamed here: replacing a class template is not a substitution of the stand-in batches. `BSSimpleList<BGSRagdoll*>` is an emitted element type; the unit's object neither defines nor requires a name of it. |

### Private specialisations

37 explicit specialisations `template <> class BSSimpleList<E>` are seen by
units of the archive. 23 were removed, in 12 units: the unit takes the list
for `E` from the shared declaration.

- 13 had the shared layout by the compiler's record layout.
- 10 had no fields, 1 byte. Each unit was first compiled with the
  specialisation's default constructor, copy constructor and destructor
  deleted. All compiled, so no unit constructs, copies or destroys such a
  list. This does not rule out a list that is a member of a class the unit
  never constructs; the object comparison covers what code depends on it.

For all 23 the unit's object is byte-identical to the object before.

17 of the 23 are for an element type the owner emits the ten members for:
16 in `bssimplelist_elements.inl` and the owner's own
`InventoryStackRecord*`. For these the removal ends a private copy that
could disagree with the owner's layout. The other six are for element types
the owner does not emit:

| Site | Element type | Layout of the removed specialisation |
| --- | --- | --- |
| `src/fallout/magic/activeeffect_local.h:209` | `const char*`; the owner emits its default constructor only | no fields |
| `src/fallout/misc/saveload/bgssaveloadhistory_decls.h:49` | `ActorCause*` | no fields |
| `src/fallout_shared/bgsbipedmodellist_decls.h:102` | `BGSCameraShot*`; `tesform.cpp` emits `SetItem` for it, the ten are not emitted | no fields |
| `src/fallout_shared/bgslistform_decls.h:205` | `BGSCameraShot*`, the same | shared layout |
| `src/fallout_shared/region system/tesregiondataimposter_decls.h:37` | `QuantityData*` | no fields |
| `src/fallout_shared/tesweather.cpp:458` | `TESRegionData*` | shared layout |

For these six nothing binds to an owner's body: a member the unit comes to
call is an undefined name until the type is emitted. The objects are
byte-identical either way.

Of the 22 sites the first step tabled for emitted element types, 16 are
among the 23, one is in a header no unit includes, and five remain:

| Site | Element type | Why it stays |
| --- | --- | --- |
| `src/fallout/ai/middlehighprocess.cpp:574` | `TESClass*` | The unit calls `GetSize`. |
| `src/fallout_shared/tesweatherlist_decls.h:39` | `WeatherEntry*` | The unit passes `AddHead` a temporary. |
| `src/staging/blk_00400000_od.cpp:1007` | `TESForm*` | The unit holds the list as a member; the shared destructor changes its object. |
| `src/fallout_shared/tesobjectcell_packet.h:157` | `TESObjectREFR*` | The unit is not on the shared header. Fields named `item`, `next`. |
| `src/fallout_shared/facegen/bsfacegenmorphdata_decls.h:27` | `BGSPerkEntry*` | The unit is not on the shared header. Empty class: the one latent silent binding left among compiled sites. |

The other nine that stay: `interface.cpp:1966` (`TESRace*`, calls
`GetSize`), `tesreactionform_decls.h:81` (`BGSCameraShot*`, reads a field
named `item`), `vatsmenu.cpp:405` and `tesobjectcell.cpp:1247` (units not on
the shared header), four whose element type is nested in a namespace or is a
class by value, and the owning unit's own specialisation for
`TESWeather::WeatherSound*`.

`bgsdecalmanager_decls.h` declared a member `FUN_0043b1b0` in its
specialisation for `TESTopic*`. The unit never calls it. Its recipe symbols
map still has a row under that name.

### Stand-in receivers

1,361 undefined names at a365fda14 reach one of twelve list addresses, the
ten of the first table and those of `SetItem` and `ItemsInList`, through a
class that is not the global template. A stand-in is replaced by
`BSSimpleList<E>` when all of this holds.

1. Every unit that requires the name is on the shared header, and its recipe
   symbols map binds the stand-in member to the address of the list member
   it becomes.
2. The stand-in is unit-local, declares no field, has no base and no
   virtual function, and the unit holds no object of it: no variable,
   member, parameter by value, new- or delete-expression, array, base
   class. The scanner of stand-in batch 3 reports each such use and each one
   refuses. So no storage is compared: there is none.
3. The element type is spelled by the stand-in's own members: the parameter
   of `AddHead`, `AddTail`, `SetItem` or the item constructor, or the return
   type of `GetItem`. All must agree. No existing cast in the unit may pair
   the stand-in with a list of another element type.
4. The owning unit already emits the list for that element type. The
   element list is never extended for a stand-in. A pointer to a builtin,
   `void*` or `int*`, is accepted only when the owner already emits it for
   a unit that requires it under the template's name and the stand-in's own
   signature spells it. Such a row is recorded as "element type
   unresolved": the list is real, the pointee is not known.
5. The substitution rules and assertions of stand-in batch 3 hold: the
   definition leaves, type names and member names are respelled, nothing is
   declared, no cast is added; a bound member is not virtual; the object is
   equal once the old names are respelled; the warnings are the same; each
   new name has one definition in the archive.
6. A constructor or destructor of another class folded into `GetItem`'s
   address `0x006815c0` is never a candidate.

| | Names |
| --- | --- |
| Constructors and destructors folded at `0x006815c0`, left out | 353 |
| The stand-in's members name no element type, or more than one | 562 |
| A requiring unit is not on the shared header | 347 |
| A free function | 18 |
| A requiring unit has no row that binds the name to the address | 6 |
| Candidates: 47 pairs of unit and stand-in | 75 |

Of the 47 pairs, 3 were replaced and 5 names left:

| Unit | Stand-in | List | Members |
| --- | --- | --- | --- |
| `middlehighprocess.cpp` | `FurnitureSearchDetail::FurnitureList` | `BSSimpleList<TESObjectREFR*>` | `AddHead`, `SetItem`, `ItemsInList` |
| `extradatalist.cpp` | `ListHelper` | `BSSimpleList<void*>` | `AddHead` |
| `inventorychanges.cpp` | `G2` | `BSSimpleList<ExtraDataList*>` | `AddHead` |

The 44 refused, by first rule:

| Rule | Pairs |
| --- | --- |
| The owner does not emit the element type: a unit-local or placeholder pointee, a nested one, `SpellItem*` for `AddHead` | 28 |
| The unit holds an object of the stand-in | 8 |
| A cast pairs the stand-in with a list of another element type | 5 |
| Another class derives from the stand-in; it has a base; it is defined inside a declarator | 3 |

11 existing casts name the list afterwards: 6 bit casts from `void*` or from
an incomplete class, 5 no-ops from the same list.

`build/units.json`: 5 symbols keys of the three units leave and 4 enter; 1
of the 5 is merged into a key the unit already had at the address. The rule
for the key of a folded template member, per element type:

- the new key is the function row's symbol with only the template argument
  replaced, consistently in class and parameters, by the unit's element
  type;
- the object's undefined symbol is the x64 spelling of that key;
- that name has exactly one definition, in the unit holding the function
  row.

The key cannot be the row's own spelling, which names
`InventoryStackRecord*`, `TESFile*` or `EffectSetting*`. All five keys pass
the three points.

Element type unresolved: `ListHelper` in `extradatalist.cpp` became
`BSSimpleList<void*>`. `ListHelper::AddHead(void*&)` spells `void*`, and
the owner already emitted `BSSimpleList<void*>` for units that require it
under the template's name, `extradatalist.cpp` among them. The substitution
keeps the unit's spelling and claims no more than the unit did. No accepted
row uses `int*`.

### Open after step 2

One accounting, on twelve addresses: the ten of `bssimplelist_h_unit.cpp`,
`0x00726c60` (`SetItem`) and `0x005ae380` (`ItemsInList`). A name is counted
when no archive member defines it, at least one requires it, and either its
class is the global template, or the recipe of a requiring unit binds it to
one of the twelve addresses. The same rule was applied to the archive of
a365fda14 and to the archive of the last code commit, so the two totals have
one base. Each name has one cause, the first that applies in the order of
the table, so the rows sum to the total.

| Cause | a365fda14 | After step 2 |
| --- | --- | --- |
| The template's own name | 104 | 92 |
| A constructor or destructor of another class folded at `0x006815c0` | 353 | 353 |
| A free function | 18 | 18 |
| A requiring unit has no row that binds the name to the address | 6 | 6 |
| A requiring unit is not on the shared header | 347 | 347 |
| The stand-in's members name no element type, or more than one | 562 | 562 |
| Candidate: the owner does not emit the element type | 42 | 42 |
| Candidate: the unit holds an object of the stand-in | 14 | 14 |
| Candidate: a cast pairs the stand-in with a list of another element type | 10 | 10 |
| Candidate: derived from, has a base, or defined inside a declarator | 4 | 4 |
| Candidate: replaced in step 2 | 5 | 0 |
| Total | 1,465 | 1,448 |

17 names leave and none enters or changes row: 12 of the first row and the
5 of the last. A unit counts as on the shared header when it is at the last
commit, in both columns. The candidate rows count names; the table of the
44 refused above counts pairs of unit and stand-in, and one name is
required through two pairs.

This total does not continue the first step's 1,398 under "Not covered".
That figure used ten addresses and the address the link-frontier partition
gave each name, and it counted classes named after the list without a
bound address. The two are different measures, and no figure of this
document subtracts one from the other.

The 92 names of the template itself, by member:

| Member | Names |
| --- | --- |
| One of the ten member names, for an element type that is not emitted or with another signature; 7 of them `AddHead(const T&)` | 78 |
| A placeholder member name: `FUN_008256d0` (3), `FUN_005ae3d0` (1), `FUN_006815c0` (1) | 5 |
| `ItemsInList`: `TESRegionData*` as `class` and as `struct`, `BGSMusicType::MusicTrack*` | 3 |
| `SetItem(T&)`: `TESClass*`, `TESRace*` | 2 |
| `GetSize`: `TESClass*`, `TESRace*` | 2 |
| `Remove`: `VATSCommand*` | 1 |
| `IsInList` | 1 |

What each row waits for:

- Element type not emitted, 42 names: the pointee is unit-local or a
  placeholder and needs a shared declaration first.
- No element type named, 562 names: the next rule to write reads the
  element type from the operand of an existing cast.
- Units not on the shared header, 347 names: they follow the 35 differing
  copies.
- Held by value, 14 names: a storage comparison of the stand-in with the
  16-byte list, which this step did not make.
- The element types the first step refused because a requiring unit
  declared the list as an empty class were not looked at again. Some of
  those declarations are among the 23 removed, such as the one for
  `const char*` in `activeeffect.cpp`.

## Not covered

This list is the first step's. "Open after step 2" has what changed, and
counts the remainder again on another base.

- 1,398 undefined names are still attributable to the list, by the first
  step's measure: 1,340 are bound to one of the ten addresses and 58 use a
  list name for a member that another unit owns or that has no row. By
  cause:

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
- `Remove`, `IsInList` and `Sort` are not in the header. `SetItem` and
  `ItemsInList` are, since step 2.
- The owning unit still declares a specialisation of the list for
  `TESWeather::WeatherSound*` with a two-argument constructor at
  `0x004b0680`, and explicit specialisations of `RemoveAll` for
  `ActorCause*` and `AddHead` for `SpellItem*` that it never defines.
- Nothing executes these functions. No linking program loads the owning
  unit, and it cannot be linked into a test, because it requires names the
  archive does not define. Windows execution: not run.
