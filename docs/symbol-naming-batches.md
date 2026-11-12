# How VEGAS-11 chose names

VEGAS-11 asks that every address `build/units.json` binds is referred to by
one name in every unit. This document records the increments on the
integration branch that make names agree: the rule that chose each name, what
changed, the named exceptions and what stays open. The scripts that made the
changes are kept outside the repository.

The counts come from the messages of the commits named here. The recipe counts
and the address tables were read again from `build/units.json` in git. Link
counts are those of the forced link of every archive member with no error
limit; they were not measured again for this document. Windows execution: not
run for any step.

The ticket is not closed by these steps. At 2277431b8 the recipe binds 107,960
addresses, and 13,054 of them still carry more than one name; 294 names are
bound to more than one address. The steps make names agree. They do not give a
class one shared declaration, and they prove nothing about receivers, layouts
or lifetimes.

What the 13,054 counts: for each address, the distinct spellings in
`build/units.json`, taking every unit's `symbols` keys and the function-row
symbols together, over functions, data and imports alike. 8,092 of the
addresses have a function row and 4,962 are bound only by `symbols` maps. The
count includes addresses where several names are correct, such as folded
template members keyed per element type, so it is an upper bound on the work
that remains. It is not the measure behind the 36,551 and 7,851 addresses that
the pull request text quotes for VEGAS-11, and the figures cannot be compared.

## Steps

| Commit | Step | Names that leave the forced link | Undefined names, before to after |
| --- | --- | --- | --- |
| 300f702dc | one class-key per type, 368 types | 1,582 | 37,438 to 35,749 |
| 82eced425 | stand-in batch 1: 74 stand-ins in 23 units | 77 | 35,749 to 35,672 |
| 47eaf6070 | stand-in batch 2: 34 stand-ins in 22 units | 34 | 35,672 to 35,638 |
| ab31749ed | 46 free-function names in 14 units | 46 | 35,638 to 35,592 |
| 2d9c165cf | move 19 class definitions (and 6 they need) | 0 | 35,551, unchanged |
| 88e299932 | stand-in batch 3: 21 stand-ins in 19 units | 22 | 35,551 to 35,529 |
| 1acae4a58 | 3 stand-ins become the shared list | 5 | 35,271 to 35,266 |
| 09e7b0d91 | move 25 class definitions (and 10 blocks they need) | 0 | 35,266, unchanged |
| 2277431b8 | stand-in batch 4: 42 stand-ins in 22 units | 42 | 35,266 to 35,224 |
| d0d8fd469 | 19 stand-ins become the shared ImageSpaceEffectParam | 19 | 35,185 to 35,166 |
| ed5ed322a | 16 data externs of SIMD and float constants in 10 units | 16 | 35,133 to 35,117 |
| 247ffd346 | the TlsGetValue slot extern in `hkpworld.cpp` | 1 | 35,117 to 35,116 |
| f985938c4 | the keyring tile id in `inventorymenu.cpp` | 1 | 35,116 to 35,115 |
| e861b865e | the message extern in `hkdataobjectnative.cpp` | 1 | 35,115 to 35,114 |

No step leaves a name newly undefined, adds a duplicate symbol, or changes the
137 imports or the archive members and their order. The archive had 2,223
members at 2277431b8, by the review record of that step, and has 2,225 at
5b1781acf, measured; no step of this table added the member. The count moves
between the steps through other tickets' commits. The totals of the first four
rows, and the 1,582, are from the review record of those changes; their commit
messages give the names retired and not the totals.

For 300f702dc the count falls by 1,689: 1,582 names retire and 107 pairs that
differed only by key remain undefined under one spelling. The 1,689, the 1,582
and the 107 are from the review record of that change and were not measured
again.

1acae4a58 belongs to the shared list declaration and is described in
`docs/shared-simple-list.md`, under "Stand-in receivers". d0d8fd469 belongs
to the shared ImageSpaceEffectParam declaration and is described in
`docs/shared-image-space-effect-param.md`, under "Stand-in classes". The
rules page closed the stand-in route at 2277431b8; d0d8fd469 reopens it for
stand-ins with fields, under that document's storage and identity rule. The
runtime library names of VEGAS-23 are in `docs/runtime-library-map.md`.

## The rule: the definition's name

A unit often refers to a function under a name of its own: through a private
stand-in class it declares beside the real class, or through a prototype with
another identifier or in a private namespace. The reference then carries that
name and never meets the definition.

- **The name taken is the definition's**: the symbol the archive defines at
  the recipe address. No other candidate is picked.
- **A descriptive name is not replaced by a placeholder.** Where the
  definition's class, member or identifier carries only an address and the
  unit uses a descriptive name, the reference is left as it is, for a reviewed
  override table. A unit's identifier counts as a placeholder only when the
  address in it is the row's own address.
- **The recipe follows.** In each changed unit the key of the `symbols` map
  takes the 32-bit spelling of the function row at that address. A key that
  would repeat one the unit already has is merged into it. No address, size,
  function row or unit changes. The exception is folded template members
  (1acae4a58), where the key is the row's member with the unit's own element
  type.
- **Nothing is declared.** No class, member, cast, header or link-level alias
  is added. The real class is the one each unit already declares, through a
  header or its own copy.

The class-key step is the one exception to the first line, because a class-key
belongs to a type and not to one symbol. It is described next.

## One class-key per type (300f702dc)

Units disagreed on whether a type is a `struct` or a `class`, so one function
or global had two mangled names. The list is 375 type names (376 qualified):
every type whose key differs between an undefined name and the archive symbol
at the same address. 368 change: 227 become `class`, 141 become `struct`. The
key is chosen once per type, in this order:

- the key in the original release's RTTI type names: 38 types from
  `src/generated/data/rtti.cpp` and 3 from RTTI names quoted in source;
- else the key most definitions in the tree already use: 292 types;
- else, on a tie, the key of the symbols the archive defines: 35 types.

The ticket words the rule per symbol: a reference takes the name of its
definition. That cannot be applied to a key. Every symbol that mentions the
type changes with it, and definitions of one type existed under both keys.

- Matching is by simple name. The change also reaches 521 nested or namespaced
  types that share a simple name with a listed type, and
  `FNV_NiPoint3_Canonical`, which is `NiPoint3` through a macro.
- `NiGlobalStringTable` is kept from the earlier reviewed list although its
  one undefined name had since been retired: 22 definitions and 6 other
  declarations become `struct`.
- Edits: the keyword on 4,410 definitions and 8,297 other declarations and
  elaborated uses; the old default access written out as a label (1,703) and
  on bases without one (162); 797 quoted mangled names at 1,407 places (asm
  labels 797, `/alternatename` directives 603, comments 7), 1,404 of them in
  178 files under `src/generated/data` under the ruling in
  `docs/native-data-ownership.md`; 4 of the 16 pinned composition hashes.
- Recipe, counted again from git: 14,689 entries change spelling (12,258 keys
  of `symbols` maps and 2,431 function rows), and 184 of the keys merge
  because a unit bound both spellings to one address. The commit message
  counts 5,754 names; that is the script's own table. Nothing else in the
  recipe changes.
- One recipe name gained a second address:
  `??0?$NiPointer@VNavMesh@@@@QAE@PAVNavMesh@@@Z` is bound to `0x0042fa20` in
  `pathinglosgridmap.cpp` and to `0x00464ff0` in `navmesh_util.cpp`. Names
  bound to more than one address in the `symbols` maps: 285 before, 286 after.
- Excluded, 7 types: `GlobalObject_0040e0b0`, `GlobalObject2_0040c150`,
  `GlobalObject2_0045cfe0`, `GlobalObjectO2_00a7b610`,
  `GlobalObject_0044f440`, `GlobalObject_0045cf30` and
  `GlobalObject_00a7b610`. With one key, objects that a unit and the generated
  initializers both define would become the same symbol. Removing one of the
  two is not a keyword change.

A key is one row of the script's table. Where the original key matters later
and neither RTTI nor the majority gave it, a type may need changing again. The
368 types are listed at the end.

## Stand-in substitution (82eced425, 47eaf6070, 88e299932, 2277431b8)

A row is a name the forced link leaves undefined that the recipe binds to an
address the archive defines under another name. A row is taken only if all of
this holds in every unit that references it. A row is all or nothing across
its units.

- The unit already declares the definition's exact mangled name on the real
  class. The compiler tests this, not a text search.
- The stand-in is declared in the unit's own `.cpp` and is a receiver only:
  never held, passed or returned as an object, sized, constructed, allocated,
  indexed, derived from or field-accessed.
- The stand-in declares no data field, has no bases or virtual functions and
  is not a template.
- It appears in no function signature, static variable's type or template
  argument, so no other symbol changes name.
- Parameters are equal. Return types are equal, or are two integer types of
  one width and signedness, an enumeration counting as one. Two differing
  pointer types are refused.
- The real class is defined before the stand-in's first use.
- The rewritten unit compiles, every rewritten call binds to the definition's
  name, and the unit's warnings are unchanged.

For a template the real type is the instance whose member the unit already
declares under the definition's mangled name. An existing cast to a stand-in
becomes a cast to the real class. That retargets the cast and does not settle
what its operand is; every such cast stays an open receiver question.

### Batch 1 (82eced425)

- Scope: `BSSimpleList`, `TESForm`, `TESAnimGroup`, `MobileObject` and `Tile`,
  309 rows of the stand-in census.
- 77 names retire at 6 addresses: `BSSimpleList` 39, `TESForm` 29,
  `TESAnimGroup` 7, `MobileObject` 2, `Tile` 0. The template instances are
  `BSSimpleList<InventoryStackRecord*>` for 38 names and
  `BSSimpleList<EffectSetting*>` for one.
- 80 stand-in declarations removed, 267 type names respelled (197 inside an
  existing cast), 96 member calls renamed. Recipe: 76 keys follow, 56 of them
  merged.
- Every accepted pair of return types that is not identical is `int` against a
  signed 32-bit enumeration: `ENUM_FORM_ID`, `ANIM_GROUP_ENUM` or
  `PROCESS_TYPE`.
- 232 rows left out, among them all 17 `Tile` rows.

### Batch 2 (47eaf6070)

- Scope: every class of the stand-in census instead of five named classes. A
  row is a name the forced link leaves undefined, bound to an address the
  archive defines under another name, where every referencing unit already
  declares the definition's exact name: 2,326 rows in 1,181 classes, 1,006 of
  them through stand-ins that the census marks as receiver-only.
- Tighter than batch 1 in five ways: a stand-in with a data field is refused,
  accessed or not; two differing pointer return types are refused; no further
  requirer is bound to a member name whose definitions in the archive differ;
  the override-table test also looks at the member's name; and the script
  compiles each unit before and after and refuses a unit whose object changes
  by more than the names.
- 34 names retire at 25 addresses: `PackageTargetRecord` 4,
  `BSShaderProperty::ShaderPassList` 4, `Calendar` 3, `MagicTarget` 3,
  `SettingT<INISettingCollection>` 2, `TESActorBase` 1, `TESObjectWEAP` 1,
  `StrOwner` 1, `PtrArray<NiPtr<RefObj>>` 1, and 14 classes that the defining
  unit itself names by address, one name each.
- Each of the 25 names bound has exactly one definition in the archive,
  counted under every COMDAT selection.
- 34 stand-in definitions and 1 forward declaration removed, 74 type names
  respelled (62 inside an existing cast, 6 local pointer variables, 6 pointer
  fields of unit-local structs), 91 member calls renamed. Recipe: 22 keys
  follow, 14 of them merged; 12 of the 34 names had no key under the old name.
- A const stand-in member against a non-const real member is refused. The
  reverse is accepted three times: `Ref::FUN_00822b40` in `frenzyeffect.cpp`
  and `FUN_00828120_z::FUN_00822b40` in `shieldeffect.cpp` bind
  `MagicTarget::GetOwnerActor() const`, and `Weapon445::GetType` in
  `modelloader.cpp` binds `TESObjectWEAP::GetWeaponType() const`.
- Accepted return-type pairs that are not identical: `int` against
  `PACKAGE_OBJECT_TYPE`, `CALENDAR_MONTH`, `WEAPON_TYPE` or `SEX`.
- 673 rows are left for the override table, 6 of them for that reason alone.
  2,292 rows are left out in all.

### Batch 3: move the real class, then substitute (2d9c165cf, 88e299932)

Until here a real class defined after the stand-in's first use was a refusal.
2d9c165cf moves such a definition earlier within its own `.cpp` file, and
88e299932 makes the substitutions the moves allow, with the substitution rules
unchanged. A move is allowed when all of this holds:

- it is one complete class definition, not a template, alone on its lines,
  with the comment lines directly above it, and holds no function body,
  default argument, default member initializer or elaborated type specifier
  that first declares a class;
- with it move at most three classes or enumerations it names that are first
  declared between the two places, unchanged and in their original order;
- the class stays in its own scope; complete named namespace blocks may lie
  between the two places, an unnamed or inline namespace block may not;
- no preprocessor directive lies between the two places, and no
  using-directive or using-declaration that makes a name visible that the
  moved text names;
- every reference to a moved class from outside the moved blocks names the
  same entity before and after, and every cast that names one keeps its cast
  kind;
- after the move alone the unit's object is the object from before, and its
  warnings are the same once line numbers are removed.

What changed and what was left out:

- Moved: 19 definitions and the 6 class definitions they need, 25 blocks and
  159 lines in 19 units. Each changed file is a permutation of its lines.
  Three moves pass a using-directive or using-declaration whose names the
  moved text does not name (`inventorychanges.cpp`, `navmesh_loadsave.cpp`,
  `tessaveloadgame.cpp`).
- 22 names retire at 16 addresses through 21 stand-ins in 19 units. 21
  stand-in definitions and 1 forward declaration removed, 45 type names
  respelled (35 inside an existing cast), 10 member calls renamed. Recipe: 22
  keys follow, 21 of them merged.
- Real classes with a base (2 names) or with virtual functions (3 names) are
  bound for the first time, under three conditions checked for all 22 names
  and 35 casts: the member bound is not virtual; it is declared in the real
  class itself and every call bound has an object of exactly that class; every
  retargeted cast is a bit cast, a no-op or an integer-to-pointer cast, and
  its operand's class is not related to the real class by inheritance.
- No const qualification and no return type differs.
- Left out: 51 stand-ins whose class could be moved fail the object check also
  with inlining off; in 44 only the order of functions differs, in 7 one
  function differs.

### Batch 4: the function-order tier (09e7b0d91, 2277431b8)

The last batch of this route. The move rule and the substitution rules are
unchanged. One thing is new: a named tier of the object check, for units where
the member now called is defined later in the same file. The compiler gives a
function its place in the object where it is first named, so the member's code
is written earlier once the call names the real class, although no function
changes.

- Moved: 25 class definitions, and with them 9 class definitions and 1 forward
  declaration, 35 blocks and 437 lines in 22 units. Three moves pass a
  using-directive or using-declaration whose names the moved text does not
  name (`interfacemanager.cpp`, `extradatalist.cpp`, `tessaveloadgame.cpp`).
- 42 names retire at 25 addresses through 42 stand-ins in 22 units, bound to
  25 members. Each of the 25 names has exactly one definition in the archive.
  42 stand-in definitions removed, 59 type names respelled (58 inside an
  existing cast), no member call renamed. Recipe: 42 keys follow, 33 of them
  merged.
- The tier, per unit, with inlining off and again without optimisation: every
  code section holds one function and is compared by its COMDAT key, with its
  bytes, relocations and unwind data; the symbol table is equal apart from the
  retired names; the sections that are no function are identical and in the
  same order, so static initialisation order cannot move; and with the newly
  bound members taken out, the section sequences are identical.
- At the unit's own flags the same holds in 6 units. In the other 16, 17
  callers of a bound member differ by the inlined body of that member. The
  tier accepts a caller only by its relocation targets: the 17 targets that
  disappear are all calls of a bound member, and the 30 that appear are all
  targets of the inlined body.
- 23 names bind a class with a base, 2 a class with virtual functions, under
  the three conditions of batch 3, checked for all 42 names and 59 casts.
- Refused by the tier: `sky.cpp` and `bstreemanager.cpp` (1 name each), where
  floating-point constants move with the bound member; and 5 units (7 names)
  where one function differs with inlining off.

## Free functions (ab31749ed)

A row is a free function the forced link leaves undefined, bound to an address
the archive defines as a free function with the same signature under another
name: 143 rows.

- 46 names at 26 addresses take the definition's name. 43 carry the
  definition's identifier in another namespace, 2 differ in identifier and
  namespace (`fnv_0078eb50::xF404010`, `fnv_005bd780::_FUN_00703da0`) and 1 in
  the identifier alone (`xFUN_00705780`). Each of the 26 has exactly one
  definition in the archive.
- 50 prototypes of the old name removed and 65 uses renamed to the fully
  qualified name, in 14 `.cpp` files. Every new name was already declared by a
  page header the file includes. Recipe: 46 keys follow, 25 of them merged.
- Override table: 53 rows at 12 addresses are not renamed, among them
  `NiMalloc`, `NiFree` and their copies against `FUN_00aa1070` and
  `FUN_00aa10f0`, and `DebugLog` against `FUN_00703c00`. `FreeArr_00a35b90`, a
  name for the function at `0x00aa1490` that carries its caller's address, is
  descriptive and left out.
- Seven of the names taken sit at three of those addresses: 4 names with 5
  uses at `0x00703da0`, 2 names with 2 uses at `0x00aa1070` and 1 name with 1
  use at `0x00aa10f0`. They are copies of the placeholder itself, so they take
  the placeholder now. If the override table later picks the descriptive name,
  those uses are renamed a second time.
- 44 more rows are left out: a page header that declares another function
  differently (11), the new identifier declared with another signature (10),
  signatures that differ once integer widths are not folded (7), the object
  check (7), a name in namespace `std` (4), and one row each for five other
  reasons.

## Data externs (ed5ed322a, 247ffd346, f985938c4, e861b865e)

A unit declares a global under a name of its own, often inside a private
namespace, while the archive defines the object at the same recipe address
under another name. The four commits respell 19 such declarations to the
definition's name. A name is respelled only when all of these hold:

- the requiring unit's `symbols` map binds the defined name to the address;
- the archive has exactly one definition of that name;
- the declared type is the definition's, apart from a `const` that the
  declaration lacked, and the unit only reads the object;
- each use agrees with the value the definition holds.

The edit removes the private declaration where a global one is already
visible, moves it to global scope where none is, or respells it in place to
`extern "C"` where the definition has C linkage. In `hkdataobjectnative.cpp`
two uses take the name of the string the unit defines from its generated data
include, `str_010d64bc`, which a third use in the unit already reads. One use
takes a descriptive name: `UpdateCurrentValue` reads
`InventoryMenu::ms_iKeyringOpenTileID` instead of `DAT_011d9eb8`. Its
unit's key for the old name merges into its key for the member at the
same address. No other key changes, because no other unit had a key for
the old spelling. Nothing else is declared, and no cast is added.

Every object is equal to its tip object once the old names are respelled,
except one function. In `hkdataobjectnative.cpp` the old name's undefined
symbol merges into the unit's definition of `str_010d64bc`. In
`blk_00da0000_o2.cpp`, `CleanSimd::FUN_00dad110` now sees the 0.5f constant
at `0x01016248` as `const`. The compiler folds the load into a `mulss`
operand: `half * rs` becomes `rs * half`, the same IEEE product, because
multiplication is commutative and 0.5f is not NaN. The function is 5 bytes
shorter and its unwind entry follows.

The census of undefined names at 2fa5deb28 lists 380 names in this class.
The other 361 stay as they are:

| Reason | Names |
| --- | --- |
| One of the seven GlobalObject types that the class-key step excluded. The requiring unit declares its own type of that name, not the definition's `SettingT` class or its storage class. | 261 |
| The types differ: a named array against a string literal (19), a virtual table (3), or another type (25) | 47 |
| Two or three definitions at the address, so there is no single name to take | 40 |
| The requiring unit's recipe binds neither name, so the address is known only from the identifier | 6 |
| Integer width, a call-behaviour repair under 2026-11-11 (3) | 3 |
| The value differs: `g_010173f0`, below | 2 |
| The recipe binds the requiring name to four other addresses | 1 |
| Storage: `DAT_011b5a90` is defined as `int[1]`, and the requiring unit reads past its end into `DAT_011b5a94`, an interior alias (VEGAS-51) | 1 |

On x64 an array object's mangled name has no `E` after its `P` or `Q`, so
`extern const char a[]` is `?a@@3QBDB`, while a pointer's has one. The
demangler prints both as a pointer. A first pass of the table read the
array spelling as a 32-bit pointer and put four names in a class of their
own. They are counted above by their real reason: `DAT_010d64bc` is
respelled; `DAT_010954cc` is a name the requiring unit's recipe does not
bind; `DAT_010a05e4` is declared `char*`, but the definition is a virtual
table array behind an asm label; `DAT_011b5a90` is the storage row.

The definition of `g_010173f0` in `speedtree/frondengine.cpp` is writable
and zero. The recipe binds the name in 17 units, and `blk_00b20000_od.cpp`
already passes it as the length of two other `AssignSubstring` calls. The two
requiring declarations are `const`, and their class passes `(unsigned int)-1`
in the same role. Binding them would knowingly give them 0 where they expect
`npos`, and a `const` declaration would name writable storage. They wait for
the repair of the value, VEGAS-100.

## The object check and its named exceptions

In every step the objects of the changed units are compared with the objects
from before; from batch 2 on the script makes the comparison itself and
refuses a unit. A unit is accepted when its object is equal once the old names
are respelled, or when it differs only because a call now binds to a body in
the same unit and the objects are equal with inlining off (`/Ob0`). The check
is a required gate: the row test compares types only, and does not see an
attribute on the definition or a body that always throws.

Eight units are accepted through the second path, equal with inlining off:
`interfacemanager.cpp` in batch 1, `actor.cpp` and `bgsentrypointfunction.cpp`
in batch 2, `computersmenu.cpp` in batch 3, and `archive.cpp`,
`bsfacegenmanager.cpp`, `tesobjectrefr.cpp` and `tesscriptcompiler.cpp` in
ab31749ed. Anything else is a named exception:

- `bssimplelist_h_unit.cpp`, batch 1. With `/Ob0` it differs in one
  destructor: the compiler now sees that the callee cannot throw, so two
  one-byte fillers around the call go, the unwind table follows and one
  funclet label is renumbered. Its instructions are otherwise the same and no
  section changes size.
- `modelloader.cpp`, batch 2, 4 names. With `/Ob0` its instructions, section
  sizes, symbols and the targets and order of all 7,146 relocations are equal.
  The compiler now sees that `FUN_0043c3d0_shell::FUN_0043c3d0` cannot throw,
  so in `CQueuedTexture::FUN_0043c150` the one-byte filler after each of two
  calls goes; 22 relocation offsets shift, the unwind tables follow and two
  funclet labels are renumbered.
- The 22 units of batch 4, through the function-order tier above.
- Refused by the check in ab31749ed: seven rows in `niconsolerenderer.cpp`
  (1), `nid3dshaderconstantmap.cpp` (1) and `blk_00640000_od.cpp` (5). None
  was shown to change behaviour; the objects could not be shown equal.

## Open naming questions

Where a stand-in and the real class both carry a descriptive name and the
names differ, the definition's name is taken. Which name is right is not
settled.

| Unit | Name the unit used | Name taken | Address |
| --- | --- | --- | --- |
| `tesobjectweap.cpp` | `FireString::GetModelLength` | `TESActorBase::GetSex` | `0x0048cee0` |
| `blk_00bc0000_o2.cpp` | `RenderPassSink::SubmitPass` | `BSShaderProperty::ShaderPassList::Add` | `0x00ba9ee0` |
| `modelloader.cpp` | `Weapon445::GetType` | `TESObjectWEAP::GetWeaponType` | `0x00446390` |
| `vatsmenu.cpp` | `PromptTile::SetInt` | `Tile::Set` | `0x00700320` |

Stand-in class names that differ from the real class and are not address
placeholders: in batch 3 `Req` (`PathingRequest`), `TileX` (`TileWork` and
`Tile`), `NiAVObject` (`WaitableObject`; `NiAVObject` is a real engine class
name), `PLArr` (`PathingLocationArray`), `PromptTile` (`Tile`) and
`SaveEntryStandIn` (`FUN_008467b0_shell`); in batch 4 `SM7d6` (`ThisT`),
`TESPackageEx` (`PackageEx`), `ZX2` (`SpellListTask`) and `RefObj2`
(`hkReferencedObjectC905`).

## What these steps do not establish

- **An address the archive does not define.** Every step takes the name of a
  definition in the archive. No step handles an address that the recipe binds
  and the archive does not define, so the ticket's second branch, "or one
  declaration's name otherwise", is not exercised.
- **One shared declaration per class.** Every unit still binds through a class
  it declares itself or takes from a header. The ticket's criterion of a
  single declaration in a shared header is open, except where a later change
  provides the declaration, as `include/fnv/bs_simple_list.h` does for the
  list.
- **Receivers.** Every substituted call tells the compiler that the receiver
  has the size and alignment of that unit's copy of the class. Where units
  carry different copies, or a copy disagrees with the true object, that can
  be wrong. The retargeted casts, 197 in batch 1, 62 in batch 2, 35 in batch 3
  and 58 in batch 4, are open receiver questions.
- **Link-time optimisation.** The object check at the unit's flags is the
  acceptance basis and would have to be redone if it were ever enabled.
- **The remaining rows.** After batch 4, 2,220 rows of the stand-in census
  remain, 338 refused by a single rule and 1,882 by two or more (from the
  review record of batch 4). The substitution-only route has no further tier
  to offer on them.
- **Two definitions under one name.** Batch 1 retired four stand-in names onto
  `BSSimpleList<InventoryStackRecord*>::RemoveHead` while the archive held two
  differing definitions of it (VEGAS-89). The second copy was removed later,
  in 29ba6dda5.

## Addresses and the names the changed keys took

Read from `build/units.json` in git: for each commit, every address at which a
key of a unit's `symbols` map changed. "Respelled" counts keys that took the
new spelling, "merged" keys that went into a key the unit already had at the
address. A retired name whose unit had no key for it is not in these tables.
In every row the changed keys now spell the function row shown.

Other units may still bind an address under other names. At 2277431b8, 31 of
the 86 addresses in the five tables that follow still carry more than one name
in the recipe, for example `0x00401170` with 320 spellings and `0x008256d0`
with 512 spellings. A row says what the changed keys spell, not that every
unit agrees.

### Batch 1, 82eced425

| Address | Name the changed keys now spell (recipe function row) | Row's unit | Keys respelled | Keys merged | Units |
| --- | --- | --- | --- | --- | --- |
| `0x00401170` | `?GetFormType@TESForm@@QBE?AW4ENUM_FORM_ID@@XZ` | `fallout_shared/tesform.cpp` | 10 | 18 | 14 |
| `0x005ae380` | `?ItemsInList@?$BSSimpleList@PAVEffectSetting@@@@QAEIXZ` | `fallout/interface/interfacemanager.cpp` | 1 | 0 | 1 |
| `0x005f2420` | `?GetType@TESAnimGroup@@QBE?AW4ANIM_GROUP_ENUM@@XZ` | `fallout_shared/tesanimgroup.cpp` | 4 | 3 | 5 |
| `0x0063f7b0` | `?RemoveHead@?$BSSimpleList@PAVInventoryStackRecord@@@@QAEXXZ` | `bscore/bssimplelist_h_unit.cpp` | 1 | 3 | 2 |
| `0x008256d0` | `?IsEmpty@?$BSSimpleList@PAVInventoryStackRecord@@@@QAE_NXZ` | `bscore/bssimplelist_h_unit.cpp` | 3 | 31 | 4 |
| `0x00931850` | `?GetCurrentProcessLevel@MobileObject@@QAE?AW4PROCESS_TYPE@@XZ` | `fallout/ai/movement/actormover.cpp` | 1 | 1 | 2 |

6 addresses, 20 keys respelled and 56 merged.

### Batch 2, 47eaf6070

| Address | Name the changed keys now spell (recipe function row) | Row's unit | Keys respelled | Keys merged | Units |
| --- | --- | --- | --- | --- | --- |
| `0x00408d60` | `?Bool@?$SettingT@VINISettingCollection@@@@QAEPATSETTING_VALUE@@XZ` | `fallout/ai/processlists.cpp` | 0 | 2 | 2 |
| `0x0043d450` | `?FUN_0043d450@FUN_0043d450_Owner@@QAEPAUNiBound@@XZ` | `fallout/ai/combat/combatthreatmap.cpp` | 0 | 1 | 1 |
| `0x0043ea30` | `?FUN_0043ea30@FUN_0043ea30_shell@fnv_0043ea30@@QAEXXZ` | `fallout_shared/modelloader.cpp` | 1 | 0 | 1 |
| `0x00446390` | `?GetWeaponType@TESObjectWEAP@@QBE?AW4Type@_WeaponType@@XZ` | `fallout_shared/modelloader.cpp` | 1 | 0 | 1 |
| `0x0048cee0` | `?GetSex@TESActorBase@@QAE?AW4SEX@@XZ` | `fallout_shared/tesactorbase.cpp` | 1 | 0 | 1 |
| `0x00680080` | `?GetTargetObjectType@PackageTargetRecord@@QAE?AW4PACKAGE_OBJECT_TYPE@@XZ` | `fallout_shared/packagetarget.cpp` | 1 | 2 | 1 |
| `0x00680110` | `?SetTargetObjectReference@PackageTargetRecord@@QAEXPAVTESObjectREFR@@@Z` | `fallout_shared/packagetarget.cpp` | 0 | 1 | 1 |
| `0x00822b40` | `?GetOwnerActor@MagicTarget@@QBEPAVActor@@XZ` | `fallout/magic/magictarget.cpp` | 0 | 3 | 3 |
| `0x00867d20` | `?GetCurrentMonth@Calendar@@QAE?AW4CALENDAR_MONTH@@XZ` | `fallout/misc/calendar.cpp` | 2 | 0 | 2 |
| `0x009314d0` | `?FUN_009314d0@FUN_009314d0_class@fnv_009314d0@@QAEXM@Z` | `fallout/ai/actor.cpp` | 1 | 0 | 1 |
| `0x00a03c90` | `?FUN_00a03c90@FUN_00a03c90_shell@@QAEPAVMenu@@XZ` | `bsmenu/tile.cpp` | 0 | 1 | 1 |
| `0x00ba9ee0` | `?Add@ShaderPassList@BSShaderProperty@@QAEXPAVNiGeometry@@G_NEPAVShadowSceneLight@@222@Z` | `bsshader/bsshaderproperty.cpp` | 0 | 4 | 1 |
| `0x00c628c0` | `?FUN_00c628c0@?$PtrArray@V?$NiPtr@URefObj@@@@@@QAEXI@Z` | `staging/blk_00c60000_od.cpp` | 1 | 0 | 1 |

13 addresses, 8 keys respelled and 14 merged.

### Free functions, ab31749ed

| Address | Name the changed keys now spell (recipe function row) | Row's unit | Keys respelled | Keys merged | Units |
| --- | --- | --- | --- | --- | --- |
| `0x00404010` | `?FUN_00404010@@YAMMM@Z` | `fallout_shared/magic/effectitem.cpp` | 0 | 1 | 1 |
| `0x00406d90` | `?FUN_00406d90@@YAHM@Z` | `fallout_shared/tesland.cpp` | 1 | 0 | 1 |
| `0x0057acc0` | `?FUN_0057acc0@@YAXI@Z` | `fallout_shared/tesobjectrefr.cpp` | 1 | 0 | 1 |
| `0x0059e650` | `?FUN_0059e650@fnv_0059e650@@YA_NPAVTESObjectREFR@@PAX1AAN@Z` | `fallout_shared/tesconditionfunctions.cpp` | 1 | 0 | 1 |
| `0x005a0800` | `?FUN_005a0800@fnv_005a0800@@YA_NPAVTESObjectREFR@@PAX1AAN@Z` | `fallout_shared/tesconditionfunctions.cpp` | 1 | 0 | 1 |
| `0x005a1ad0` | `?FUN_005a1ad0@fnv_005a1ad0@@YA_NPAVTESObjectREFR@@PAX1AAN@Z` | `fallout_shared/tesconditionfunctions.cpp` | 1 | 0 | 1 |
| `0x005a1c30` | `?FUN_005a1c30@fnv_005a1c30@@YA_NPAVTESObjectREFR@@PAX1AAN@Z` | `fallout_shared/tesconditionfunctions.cpp` | 1 | 0 | 1 |
| `0x005a1e50` | `?FUN_005a1e50@@YA_NPB_N@Z` | `fallout_shared/tesconditionfunctions.cpp` | 1 | 0 | 1 |
| `0x005a1e70` | `?FUN_005a1e70@fnv_005a1e70@@YA_NPAVTESObjectREFR@@PAX1AAN@Z` | `fallout_shared/tesconditionfunctions.cpp` | 1 | 0 | 1 |
| `0x005afeb0` | `?FUN_005afeb0@fnv_005afeb0@@YA_NPBD@Z` | `fallout_shared/tesscriptcompiler.cpp` | 1 | 0 | 1 |
| `0x00651e30` | `?FUN_00651e30@@YAXXZ` | `fallout_shared/facegen/bsfacegenmanager.cpp` | 1 | 0 | 1 |
| `0x00652140` | `?FUN_00652140@@YAXXZ` | `fallout_shared/facegen/bsfacegenmanager.cpp` | 0 | 6 | 1 |
| `0x00652160` | `?FUN_00652160@fnv_00652160@@YA_NXZ` | `fallout_shared/facegen/bsfacegenmanager.cpp` | 1 | 0 | 1 |
| `0x00652190` | `?FUN_00652190@fnv_00652190@@YAXXZ` | `fallout_shared/facegen/bsfacegenmanager.cpp` | 1 | 6 | 1 |
| `0x00703000` | `?FUN_00703000@fnv_00703000@@YAXXZ` | `fallout/interface/interface.cpp` | 1 | 1 | 1 |
| `0x00703810` | `?FUN_00703810@fnv_00703810@@YAX_N@Z` | `fallout/interface/interface.cpp` | 1 | 0 | 1 |
| `0x00703d50` | `?FUN_00703d50@fnv_00703d50@@YA_NXZ` | `fallout/interface/interface.cpp` | 1 | 0 | 1 |
| `0x00703da0` | `?FUN_00703da0@fnv_00703da0@@YAXXZ` | `fallout/interface/interface.cpp` | 1 | 3 | 1 |
| `0x00705780` | `?FUN_00705780@@YAXXZ` | `fallout/interface/interface.cpp` | 0 | 2 | 1 |
| `0x00706230` | `?FUN_00706230@fnv_00706230@@YAXHH@Z` | `fallout/interface/interface.cpp` | 1 | 0 | 1 |
| `0x00782a90` | `?FUN_00782a90@@YAXXZ` | `fallout/interface/menus/inventorymenu.cpp` | 0 | 1 | 1 |
| `0x00aa1070` | `?FUN_00aa1070@@YAPAXI@Z` | `gamebryo2.2/corelibs/nisystem/nimemorydefines.cpp` | 1 | 1 | 2 |
| `0x00aa10f0` | `?FUN_00aa10f0@@YAXPAX@Z` | `gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp` | 1 | 0 | 1 |
| `0x00aa12f0` | `?GetElapsedSeconds@@YAMXZ` | `staging/blk_00aa0000_o2.cpp` | 1 | 0 | 1 |
| `0x00b014b0` | `?SkipDataPrefix@@YAPBDPBD@Z` | `bssystem/archive.cpp` | 0 | 4 | 1 |
| `0x00cb1130` | `?FUN_00cb1130@fnv_00cb1130@@YAPBDPBD0@Z` | `havok/common/base/container/string/hkstring.cpp` | 1 | 0 | 1 |

26 addresses, 21 keys respelled and 25 merged.

### Batch 3, 88e299932

| Address | Name the changed keys now spell (recipe function row) | Row's unit | Keys respelled | Keys merged | Units |
| --- | --- | --- | --- | --- | --- |
| `0x00401970` | `?FUN_00401970@WaitableObject@@QAEXXZ` | `fallout_shared/bgsdehydration.cpp` | 0 | 1 | 1 |
| `0x00418b10` | `?FUN_00418b10@FUN_00418b10_shell@@QAE_NXZ` | `fallout_shared/extradatalist.cpp` | 0 | 1 | 1 |
| `0x00425fd0` | `?IsCellInterior@TESObjectCELL@@QBE_NXZ` | `fallout_shared/tesworldspace.cpp` | 0 | 1 | 1 |
| `0x00485e00` | `?FUN_00485e00@FUN_00485e00_shell@@QAEXXZ` | `fallout_shared/tesform.cpp` | 0 | 1 | 1 |
| `0x00493830` | `?FUN_00493830@FUN_00493830_shell@@QAE_NXZ` | `fallout_shared/animation.cpp` | 0 | 1 | 1 |
| `0x006cf1b0` | `?FUN_006cf1b0@PathingLocationArray@@QAEIABUPathingLocation@@@Z` | `unmapped/bssimplearray.cpp` | 0 | 1 | 1 |
| `0x00700320` | `?Set@Tile@@QAEXHH@Z` | `bsmenu/tile.cpp` | 0 | 5 | 4 |
| `0x0072ba80` | `?FUN_0072ba80@FUN_0072ba80_shell@@QAEXPAXI@Z` | `fallout/interface/menus/recipemenu.cpp` | 0 | 2 | 2 |
| `0x00759850` | `?FUN_00759850@Holder@@QAEXXZ` | `fallout/interface/menus/computersmenu.cpp` | 1 | 0 | 1 |
| `0x007adc60` | `?FUN_007adc60@FUN_007adc60_shell@@QAEXH_N@Z` | `bsmenu/device.cpp` | 0 | 1 | 1 |
| `0x008467b0` | `?LoadSaveEntry@FUN_008467b0_shell@@QAE_NXZ` | `fallout/misc/saveload/bgssaveloadfile.cpp` | 0 | 1 | 1 |
| `0x008579e0` | `?FUN_008579e0@FUN_008579e0_shell@@QAEXPAXI@Z` | `fallout/misc/saveload/bgsloadgamebuffer.cpp` | 0 | 2 | 1 |
| `0x0096e870` | `?AddMobileObjectToList@ProcessLists@@QAEXPAVMobileObject@@@Z` | `fallout/ai/processlists.cpp` | 0 | 1 | 1 |
| `0x0096f400` | `?RemoveMobileObjectFromList@ProcessLists@@QAEXPAVMobileObject@@@Z` | `fallout/ai/processlists.cpp` | 0 | 1 | 1 |
| `0x009b0bd0` | `?GetCenterRadius@PathingRequest@@QAEMXZ` | `fallout_shared/tesobjecttree_h_unit.cpp` | 0 | 1 | 1 |
| `0x00a0b520` | `?FUN_00a0b520@TileWork@@QAEXXZ` | `bsmenu/tile.cpp` | 0 | 1 | 1 |

16 addresses, 1 key respelled and 21 merged.

### Batch 4, 2277431b8

| Address | Name the changed keys now spell (recipe function row) | Row's unit | Keys respelled | Keys merged | Units |
| --- | --- | --- | --- | --- | --- |
| `0x00410020` | `?FUN_00410020@FUN_00410020_t@@QAEXPAVBSExtraData@@_N@Z` | `fallout_shared/extradatalist.cpp` | 0 | 16 | 1 |
| `0x0042f000` | `?FUN_0042f000@FUN_0042f000_cls@@QAEXXZ` | `fallout_shared/extradatalist.cpp` | 1 | 0 | 1 |
| `0x0044adb0` | `?FUN_0044adb0@FUN_0044adb0_class@@QAEXXZ` | `fallout_shared/modelloader.cpp` | 1 | 0 | 1 |
| `0x0048d210` | `?FUN_0048d210@SpellListTask@@QAE_NPAVTESLevSpell@@@Z` | `fallout_shared/tesspelllist.cpp` | 0 | 1 | 1 |
| `0x004964a0` | `?FUN_004964a0@FUN_004964a0_shell@@QAEX_N@Z` | `fallout_shared/animation.cpp` | 1 | 0 | 1 |
| `0x004b4ee0` | `?FUN_004b4ee0@FUN_004b4ee0_cls@@QAEXXZ` | `fallout_shared/globalfunc.cpp` | 1 | 0 | 1 |
| `0x004f8220` | `?FUN_004f8220@PointList@@QAE_N_N@Z` | `fallout_shared/region system/tesregionpointlist.cpp` | 0 | 1 | 1 |
| `0x006606e0` | `?SetVTable@FUN_006606e0_shell@@QAEXXZ` | `fallout_shared/facegen/bsfacegenmorph.cpp` | 0 | 2 | 1 |
| `0x00670fc0` | `?SetPackageType@PackageEx@@QAEXH@Z` | `fallout_shared/package.cpp` | 0 | 1 | 1 |
| `0x0069d2d0` | `?FUN_0069d2d0@D2d0Cls@@QAEXXZ` | `fallout_shared/pathfinding/navmesh.cpp` | 1 | 0 | 1 |
| `0x006d32c0` | `?FUN_006d32c0@FUN_006d32c0_StandIn@@QAEXXZ` | `staging/blk_006c0000_od.cpp` | 1 | 0 | 1 |
| `0x006e9af0` | `?MeasurePathLength@FUN_006e9af0_cls@@QAEMMMI@Z` | `fallout_shared/pathfinding/pathingsolution.cpp` | 0 | 1 | 1 |
| `0x00716b00` | `?FUN_00716b00@TextInputField@@QAEXH@Z` | `fallout/interface/interfacemanager.cpp` | 1 | 0 | 1 |
| `0x007b18f0` | `?HandleMenuKey@B7B18F0Menu@@QAEXH@Z` | `fallout/interface/menus/racesexmenu.cpp` | 0 | 1 | 1 |
| `0x007b25a0` | `?FUN_007b25a0@Menu511@@QAEXXZ` | `fallout/interface/menus/racesexmenu.cpp` | 0 | 1 | 1 |
| `0x007d42b0` | `?PopulateList@ThisT@@QAEXH@Z` | `fallout/interface/menus/startmenu.cpp` | 0 | 2 | 1 |
| `0x00861ee0` | `?FUN_00861ee0@FUN_00861ee0_Class@@QAEXE@Z` | `fallout_shared/tessaveloadgame.cpp` | 1 | 0 | 1 |
| `0x00881830` | `?FUN_00881830@FUN_00881830_Class@@QAEXH@Z` | `fallout/ai/actor.cpp` | 0 | 1 | 1 |
| `0x009e4c60` | `?UpdateLookingAngle@FUN_009e4c60_t@@QAEXMM@Z` | `fallout/ai/movement/detailedactorpathhandler.cpp` | 0 | 1 | 1 |
| `0x009e7d70` | `?FUN_009e7d70@FUN_009e7d70_shell@@QAEMM@Z` | `fallout/ai/movement/detailedactorpathhandler.cpp` | 0 | 1 | 1 |
| `0x00a12300` | `?ClearArray@S_00a12300_Obj@@QAEXXZ` | `bsmenu/font.cpp` | 0 | 1 | 1 |
| `0x00aa7260` | `?FUN_00aa7260@FUN_00aa7260_holder@@QAEXXZ` | `bscore/memorypool.cpp` | 0 | 1 | 1 |
| `0x00aa7300` | `?FUN_00aa7300@FUN_00aa7300_cls@@QAEXXZ` | `staging/blk_00aa0000_od.cpp` | 1 | 0 | 1 |
| `0x00c905b0` | `?FUN_00c905b0@hkReferencedObjectC905@@QAEXXZ` | `havok/common/base/object/hkreferencedobject.cpp` | 0 | 1 | 1 |
| `0x00e7b550` | `?DeleteAllItems@FUN_00e7b550_cls@@QAEXXZ` | `staging/blk_00e60000_o2.cpp` | 0 | 1 | 1 |

25 addresses, 9 keys respelled and 33 merged.

### Shared list, 1acae4a58

Here the new key is the 32-bit spelling of the list member for the stand-in's
own element type. Members of different element types fold to one address, so
the function row can carry another element type.

| Address | Recipe function row | Row's unit | New keys | Keys respelled | Keys merged | Units |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005ae380` | `?ItemsInList@?$BSSimpleList@PAVEffectSetting@@@@QAEIXZ` | `fallout/interface/interfacemanager.cpp` | `?ItemsInList@?$BSSimpleList@PAVTESObjectREFR@@@@QAEIXZ` | 1 | 0 | 1 |
| `0x005ae3d0` | `?AddHead@?$BSSimpleList@PAVInventoryStackRecord@@@@QAEXAAPAVInventoryStackRecord@@@Z` | `bscore/bssimplelist_h_unit.cpp` | `?AddHead@?$BSSimpleList@PAVTESObjectREFR@@@@QAEXAAPAVTESObjectREFR@@@Z`, `?AddHead@?$BSSimpleList@PAX@@QAEXAAPAX@Z` | 2 | 1 | 3 |
| `0x00726c60` | `?SetItem@?$BSSimpleList@PAVTESFile@@@@QAEXABQAVTESFile@@@Z` | `fallout_shared/tesform.cpp` | `?SetItem@?$BSSimpleList@PAVTESObjectREFR@@@@QAEXABQAVTESObjectREFR@@@Z` | 1 | 0 | 1 |

3 addresses, 4 keys respelled and 1 merged. All 3 still carry more than one
name at 2277431b8.

### Shared ImageSpaceEffectParam, d0d8fd469

One address. Every old key is the constructor of a stand-in; each unit now
carries the key of the function row.

| Address | Recipe function row | Row's unit | New key | Keys respelled | Keys merged | Units |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00414430` | `??0ImageSpaceEffectParam@@QAE@MMMM@Z` | `bsshader/imagespaceeffectparam_h_unit.cpp` | `??0ImageSpaceEffectParam@@QAE@MMMM@Z` | 14 | 5 | 16 |

The 19 old keys:

| Unit | Old key | Into the new key |
| --- | --- | --- |
| `fallout/ai/actor.cpp` | `??0ImpactColor@@QAE@MMMM@Z` | respelled |
| `fallout/ai/combat/combatmanager.cpp` | `??0RgbaColor@fnv_00991770@@QAE@MMMM@Z` | respelled |
| `fallout/ai/combat/explosion.cpp` | `??0Color810@@QAE@MMMM@Z` | merged |
| `fallout/ai/combat/missileprojectile.cpp` | `??0UpdateColor@@QAE@MMMM@Z` | respelled |
| `fallout/ai/combat/projectile.cpp` | `??0NiColorAPB@@QAE@MMMM@Z` | respelled |
| `fallout/ai/combat/projectile.cpp` | `??0NiColorAP9@@QAE@MMMM@Z` | merged |
| `fallout/interface/menus/computersmenu.cpp` | `??0Color@fnv_00757b70@@QAE@MMMM@Z` | respelled |
| `fallout/interface/menus/hackingmenu.cpp` | `??0Color84@fnv_00765b80@@QAE@MMMM@Z` | respelled |
| `fallout/interface/menus/racesexmenu.cpp` | `??0ColorB50@fnv_007b2b50@@QAE@MMMM@Z` | respelled |
| `fallout/magic/absorbeffect.cpp` | `??0NiColorAStandIn@fnv_008034c0@@QAE@MMMM@Z` | respelled |
| `fallout/magic/bhkcharacterlistenerspell.cpp` | `??0ColorA807@@QAE@MMMM@Z` | respelled |
| `fallout_shared/facegen/bsfacegenmanager.cpp` | `??0RgbaColor@fnv_00655fa0@@QAE@MMMM@Z` | respelled |
| `fallout_shared/sky/sun.cpp` | `??0RgbaColor@fnv_00641830@@QAE@MMMM@Z` | respelled |
| `fallout_shared/tempeffects/bstempeffectsimpledecal.cpp` | `??0Color4@@QAE@MMMM@Z` | respelled |
| `fallout_shared/tempeffects/bstempeffectsimpledecal.cpp` | `??0DecalColor@@QAE@MMMM@Z` | merged |
| `fallout_shared/tesobjectweap.cpp` | `??0FireColor@@QAE@MMMM@Z` | respelled |
| `fallout_shared/tesscriptfunctions.cpp` | `??0ImageSpaceEffectParam@fnv_005d3780@@QAE@MMMM@Z` | merged |
| `fallout_shared/tesscriptfunctions.cpp` | `??0ImageSpaceEffectParam@fnv_005d3930@@QAE@MMMM@Z` | merged |
| `fallout_shared/testerrainlodmanager.cpp` | `??0FUN_00414430_Color@fnv_0057de00@@QAE@MMMM@Z` | respelled |

At d0d8fd469 the address still carries 65 names in 73 units.

## The 368 types and their keys

From the class-key script's table. Checked against git: before 300f702dc every
one of these names appeared with the other key, and after it, and at
2277431b8, none does outside template parameter lists.

**RTTI type name in `src/generated/data/rtti.cpp`, `class` (38):**
`ActiveEffect`, `Actor`, `BaseFormComponent`, `BGSEncounterZone`, `BGSPerk`,
`BSExtraData`, `EffectSetting`, `ExtraFollower`, `HighProcess`, `MagicCaster`,
`MagicItem`, `MagicTarget`, `Menu`, `MobileObject`, `PlayerCharacter`,
`Projectile`, `TESActorBase`, `TESBoundObject`, `TESCreature`, `TESForm`,
`TESFullName`, `TESIdleForm`, `TESModel`, `TESModelTextureSwap`, `TESNPC`,
`TESObject`, `TESObjectARMO`, `TESObjectBOOK`, `TESObjectCELL`,
`TESObjectLAND`, `TESObjectREFR`, `TESObjectWEAP`, `TESPackage`, `TESQuest`,
`TESTexture`, `TESWorldSpace`, `Tile`, `TileMenu`.

**RTTI type name quoted in source, `class` (3):** `NiD3DGeometryGroupManager`,
`NiRenderTargetGroup`, `TESLeveledList`.

**The key most definitions used, `class` (160):** `AccumWIP`,
`ActorPackageContext`, `ActorValueModifierList`, `ActorValueOwner`,
`AnimationKey`, `AnimSequenceBase`, `AStarNode`, `BaseExtraList`, `BeamStage`,
`BGSAcousticSpace`, `BGSAddonNode`, `BGSCameraPath`, `BGSDehydrationStage`,
`BGSDestructibleObjectForm`, `BGSHungerStage`, `BGSImpactData`,
`BGSImpactDataSet`, `BGSLoadedReferenceCollection`, `BGSLoadGameSubBuffer`,
`BGSMoviePlayer`, `BGSPrimitive`, `BGSQuestObjective`, `BGSRadiationStage`,
`BGSSaveLoadManager`, `BipedAnimObject`, `BSAnimGroupSequence`,
`BSFaceGenAnimationData`, `BSFaceGenManager`, `BSFileCache`, `BSFogProperty`,
`BSPackedTask`, `BSShaderAccumulator`, `BSSimpleArray`, `BSSimpleList`,
`CombatAction`, `CombatGoal`, `CombatProcedure`, `ContainerItemExtra`,
`D3DRenderStateGroup`, `DialogueItem`, `DurationData`, `EdgeExtraInfo`,
`EffectItem`, `EffectItemList`, `ExtraDataList`, `ExtraDismemberedLimbs`,
`ExtraFactionChanges`, `ExtraLeveledItem`, `ExtraRefractionProperty`,
`FindTriangleForLocationFilter`, `FontManager`, `FOPipboyManager`,
`FORenderedMenu`, `FormChangeMask`, `FUN_00649680`, `FUN_00ac05b0`,
`FUN_00d065e0`, `GlobalObject_004037b0`, `GlobalObject_0040c150`,
`GlobalObject_008c71d0`, `HeapFreeList`, `hkAabb`, `hkContactPoint`,
`hkOstream`, `hkpAction`, `hkpCdBody`, `hkpConstraintInstance`, `hkpPhantom`,
`hkReferencedObject`, `hkTransform`, `HUDMainMenu`, `IdleAnimationManager`,
`IdleSystem`, `ImageSpaceEffect`, `ImageSpaceModifierInstanceDOF`,
`ImageSpaceModifierInstanceForm`, `InventoryStackRecord`, `LockExtraData`,
`MapMarkerData`, `MediaLocationController`, `MessageHandler`, `NavMesh`,
`NavMeshClosedDoorInfo`, `NavMeshEdgeData`, `NavMeshInfo`, `NavMeshTriangle`,
`NavMeshTriangleEdgeReference`, `NavMeshTriangleReference`, `Ni2DBuffer`,
`NiAccumulator`, `NiAVObject`, `NiBlendInterpolator`, `NiCamera`,
`NiControllerSequence`, `NiCullingProcess`, `NiD3DPixelShader`,
`NiD3DShaderConstantMap`, `NiD3DShaderInterface`, `NiD3DVertexDeclaration`,
`NiDX9AdditionalDepthStencilBufferData`, `NiExtraData`, `NiFile`,
`NiFixedString`, `NiFloatData`, `NiGeometry`, `NiGeometryData`,
`NiGPUProgram`, `NiNode`, `NiNodeBooleanState`, `NiPixelFormat`, `NiPointer`,
`NiPropertyState`, `NiPSysAirFieldAirFrictionCtlr`, `NiPSysEmitterCtlr`,
`NiQuaternion`, `NiRefObject`, `NiShader`, `NiShaderConstantMapEntry`,
`NiSourceTexture`, `NiTArray`, `NiTexture`, `NiTimeController`,
`NiTMallocInterface`, `NiTPrimitiveArray`, `NiTransform`,
`NiTransformInterpolator`, `NiTriBasedGeom`, `NiUnionBV`,
`PackageTargetRecord`, `PathingActorData`, `PathingAvoidNodeArray`,
`PathingSolution`, `PathManager`, `PerkEntryConditionSet`, `Point3Offset`,
`QueuedFile`, `RagDollData`, `RecipeCraftingInfo`, `RecursiveSpinLock`,
`RegionObjectEntry`, `SaveLoadChangeHistory`, `SaveLoadFile`, `Script`,
`Setting_01017720_011f96a0`, `SettingT`, `ShadowSceneLight`,
`TaskThreadManager`, `TESContainer`, `TESDataHandler`, `TESDescription`,
`TESEffectShader`, `TESFile`, `TESImageSpaceModifier`, `TESObjectSTAT`,
`TESRegion`, `TESSound`, `TESTopic`, `TESTopicInfo`, `Tile__TileTemplate`,
`TimedRotationKey`.

**The key most definitions used, `struct` (132):** `Animation`, `ArgObj`,
`Arr`, `BGSLoadFormBuffer`, `BGSLoadGameBuffer`, `BGSMessageInitAccess`,
`BGSPlaceableWater`, `BGSSaveFormBuffer`, `BGSSaveLoadGame`,
`BGSTextureModel`, `bhkCollisionObject`, `bhkRagdollController`,
`BooleanFloatQuery`, `BSAudio`, `BSAudioSoundHandle`, `BSRenderedTexture`,
`BSTextureManager`, `BSTreeNode`, `CellView`, `CloningProcess`,
`CombatController`, `CombatCoverPointData`, `CombatState`,
`CombatTargetTimestamp`, `ContactRecord`, `CoordinateTriple`, `Crime`,
`DetectionViewData`, `ExtraRadioData`, `ExtraSayToTopicInfo`, `FaceGenMatrix`,
`FileNameHash`, `FormRecordHeader`, `FUN_008cd6a0_Class`, `FUN_00dba680_cls`,
`FUN_00dd0420_Class`, `GameSettingCollection`, `GlobalObject2_0096a2d0`,
`GlobalObject_0044fae0`, `GlobalObject_0045cfe0`, `GlobalObject_0045d060`,
`GlobalObject_004a4a40`, `GlobalObject_004a9bf0`, `GlobalObject_004a9d80`,
`GlobalObject_004a9e90`, `GlobalObject_004ee810`, `GlobalObject_00633c90`,
`GlobalObject_006836f0`, `GlobalObject_007da090`, `GlobalObject_0083b5e0`,
`GlobalObject_00869f00`, `GlobalObject_008caae0`, `GlobalObject_0096a2d0`,
`GlobalObject_00b3f100`, `GlobalObjectO2_00b8a9e0`, `GlobalObjectO2_00d472a0`,
`GridCell`, `hkaSkeleton`, `hkpConstraintAtom`, `hkpModifierConstraintAtom`,
`hkpRigidBody`, `hkQsTransform`, `hkVector4`, `ImageSpaceEffectParam`,
`ImageSpaceManager`, `ImpactSwap`, `Interface`, `InventoryChanges`,
`InventoryEntry`, `InventoryItemEntry`, `IOManager`, `Item`, `KFModel`,
`LoadBuffer`, `LocationDescriptor`, `MobileObjectCellAccess`, `ModelLoader`,
`Modifier`, `NavMeshGrid`, `NavMeshPtr`, `NiAlphaController`,
`NiBinaryExtraData`, `NiBoolData`, `NiBound`, `NiColor`,
`NiControllerManager`, `NiD3DShaderProgramCreator`, `NiFrustum`,
`NiGeometryBufferData`, `NiGlobalStringTable`, `NiObject`, `NiObjectNET`,
`NiPalette`, `NiParticleSystem`, `NiPick`, `NiPlane`, `NiPoint2`, `NiPoint3`,
`NiPSysData`, `NiPSysModifier`, `NiRenderer`, `NiRTTI`, `NiStream`,
`NiUpdateData`, `Node`, `Obj`, `Owner`, `ParticleShaderProperty`,
`PathingLocation`, `PathingRequest`, `Point3ParameterData`, `Program`,
`QuantityData`, `QueuedHelmet`, `Ref`, `RefX`, `RgbaColor`, `ScrapHeapBuffer`,
`ScriptLocals`, `ShaderBufferRecord`, `ShadowSceneNode`, `Sky`,
`SoundPlaybackHandle`, `SpawnedObject`, `Src`, `TaskQueueInterface`,
`TeleportableReference`, `TESClimate`, `TESQueuedCellManager`,
`ThreeByThreeMatrix`, `VATSCommand`, `Vector3D`.

**Tie: the key of the symbols the archive defines, `class` (26):**
`BGSSleepDeprevationStage`, `bhkCharacterController`, `BSStream`,
`CombatWorldStateListNode`, `ConsoleManager`, `DebrisModelEntry`,
`DialogueResponse`, `ExtraAmmo`, `GlobalObject_004aa1b0`,
`GlobalObject_00559cc0`, `GlobalObject_00680890`, `GlobalObject_0076b930`,
`GlobalObject_007d9f90`, `GlobalObject_007da010`, `GlobalObjectO2_00c67fe0`,
`HeapFreeBlock`, `MersenneTwister`, `NiD3DPass`, `NiDirectionalLight`,
`NiPSysPlanarCollider`, `NiShaderFactory`, `OSGlobals`, `SpectatorPackage`,
`StandardLibrarySingletonObject`, `TESRegionList`, `TESResponseList`.

**Tie: the key of the symbols the archive defines, `struct` (9):**
`AbstractHeapLogger`, `ActorProcessView`, `BGSPrimitiveBox`,
`BSBatchRenderer__PassList`, `FormFlagRecord`, `Matrix4f`,
`MenuValueDescriptor`, `TESWaterForm`, `TimedTextEntry`.
