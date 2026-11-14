# One shared declaration of TESForm

`TESForm` is the base class of the game's data forms. VEGAS-18 owns
`src/fallout_shared`, where its owning unit `tesform.cpp` is; VEGAS-11 owns
shared declarations. This change measures every definition of the class,
gives it one declaration in `include/fnv/tes_form.h`, and moves the owning
unit and 72 other units onto it. It is a first increment. What stays open is
under "Open items" and "Not covered". The checks later changes must pass are
under "Integration checks".

The method is that of `docs/shared-simple-list.md`: a census of sites, classes
of equal copies, one header, a move that leaves the objects equal. One thing
differs. A list is two fields and ten members that each have a function row.
`TESForm` is a polymorphic class with a layout, and such a class cannot be
declared unless every virtual slot is declared. So the declaration says,
slot by slot and field by field, what is ESTABLISHED and what is OPEN.

Every statement here rests on the repository: the windows-x64 build,
`build/units.json` (the recipe) and `src/generated`. Where a question could
only be answered from the original release's own code or data, this
document says "not shown by the repository".

## What was measured

The census below was measured on 15297e447. Its tables are byte-identical
to those of the same measurement on 2277431b8. The commits rest on
49f4e9d1b, which changes one unit of the archive,
`src/staging/blk_00b60000_o2.cpp`; that unit defines no `TESForm`, derives
no class from one and includes none of the files these commits touch.
Builds and links are measured on 49f4e9d1b.

A compiler plugin ran in each of the 2,223 units of the windows-x64 archive
with the unit's own command line. For every definition of a class named
`TESForm` it recorded size, alignment, bases with offsets, fields with
offsets and sizes, member functions with their symbols, and the vftable slot
by slot. It also recorded every use: field accesses, virtual calls with
their slot, direct calls, constructions, objects held by value, casts and
derived classes. It did the same for every class whose members
`build/units.json` binds to an address of the owning unit.

| | Count |
| --- | --- |
| Definitions of a class named `TESForm` | 423, in 393 units, at 259 sites |
| At global scope | 388 units, 224 sites |
| In a namespace | 35 definitions, 35 sites |
| Different layouts among the global definitions | 40 |
| Different vftables among the global definitions | 84 |
| Different classes, counting layout, vftable and members | 184 |

No unit sees two global definitions. The global definitions by layout:

| Layout | Units | Sites |
| --- | --- | --- |
| The owner's: 40 bytes, base `BaseFormComponent`, the four fields | 158 | 42 |
| The same offsets and sizes, the list field of another type | 2 | 2 |
| 40 bytes with other fields or without the base | 9 | 9 |
| 8 bytes: a vfptr and no field | 125 | 123 |
| 1 byte: members only, no layout | 73 | 29 |
| 32 bytes | 15 | 15 |
| 56, 24 or 264 bytes | 6 | 6 |

Of the 158 units with the owner's layout, only the owner has the owner's
vftable. In all 157 others slots 52, 53 and 54 are `Unk_34`, `Unk_35` and
`Unk_36`, with the owner's parameters. By what else differs:

| Other slots whose symbol differs from the owner's | Units | Sites |
| --- | --- | --- |
| None | 72 | 11 |
| 8 and 28 | 56 | 1, `include/TESForm.h` |
| 8 | 24 | 24 |
| 8, 23 and 28 | 3 | 3 |
| 8 and 23 | 1 | 1 |
| 8, 39 and 64 | 1 | 1 |

Slot 8 is `LoadForm` in those copies and `Load` in the owner's, with the
same parameter. Slot 28 is `Revert(BGSLoadFormBuffer*)` against the owner's
`Revert(unsigned int)`. Slot 23 is `LoadGame(BGSLoadFormBuffer*)` against
the owner's `LoadGame(void*)`.

Uses through a global definition, over all units:

| Use | Units | Uses |
| --- | --- | --- |
| Virtual call | 143 | 1,034, through 73 pairs of slot and name; 169 through an established slot |
| Direct call of a member | 254 | 1,236 |
| Field access | 18 | 81 |
| Construction | 4 | 4 |
| `sizeof` | 3 | 5 |
| Held by value | 4 | 4 |
| `delete` | 1 | 1 |

Fields accessed: `m_uiFormFlags` at 12 (52 accesses, 9 units), `iFormID` at
16 (17, 5 units), `m_ucFormType` at 8 (4, 2 units), and four fields of
copies with other layouts. No unit accesses the source-file list through a
field.

Derived classes: 5,340 definitions of a class that derives from a `TESForm`,
in 299 units, under 1,519 names, at 2,321 sites. The `TESForm` base is at
offset 0 in 5,332 of them.

Stand-ins: 1,737 pairs of unit and class have a member that the recipe binds
to an address of the owning unit, under 424 class names in 370 units. 285
of the pairs are a `TESForm`, 32 derive from one, one has its layout, 1,195
have another layout and 224 could not be measured, because the unit does not
define the class or is not in the archive. 216 declare fields and 358 have a
vftable.

`src/fallout_shared/tesobjectanio.cpp` defines a look-alike `TESForm` of 32
bytes with one field and 78 slots, 5 of them with symbols other than the
owner's. It is the only object of the archive that defines
`??_7TESForm@@6B@`, the vftable symbol of the class, so that vftable comes
from the look-alike.

## The owning unit

`src/fallout_shared/tesform.cpp` has 128 function rows. The classes they are
defined on:

| Receiver of the row | Rows |
| --- | --- |
| `TESForm` | 24 |
| A class of the unit that derives from `TESForm` | 24 |
| A class with the layout of `TESForm`: the constructor row `0x00483370` | 1 |
| A class with another layout | 62 |
| A free function | 17 |

So the owner itself reaches the class under many names. Two rows matter
most. The constructor `0x00483370` is defined as
`fnv_00483370::FUN_00483370`, a look-alike class laid out from the same
four field types, with its own vftable. The destructor `0x00483630` is
defined as `FUN_00483630_holder`, 32 bytes: a vfptr, 12 bytes of padding
and an 8-byte list.

The recipe puts the vftable of the class at `0x0101c794`, under the two
names `??_7FUN_00483370@fnv_00483370@@6B@` and `??_7FUN_00483630_holder@@6B@`.
No generated table describes it. The next recipe symbol of any unit is a
string of the owner at `0x0101c8cc`, which is 78 four-byte entries later. So
the table has at most 78 slots.

`src/generated/data/vtables_*.cpp` holds 24 tables of classes derived from
`TESForm`: tables of 78 slots or more that hold at least three of the
owner's `TESForm` virtual functions in the slot the compiler gives them.
They are the evidence for slots. A table holds in slot *n* either the entry
its class inherits or an override of its own; where the 24 tables disagree
in a slot, the slot table says how the owner's row was told apart.

## The field table

The class is 40 bytes with alignment 8 on windows-x64. The 32-bit columns
are the layout the compiler gives the same declaration, the header's, for
i686-pc-windows-msvc: 24 bytes with alignment 4.

| Field | Type | x64 offset | x64 size | 32-bit offset | 32-bit size | Status |
| --- | --- | --- | --- | --- | --- | --- |
| vfptr, through `BaseFormComponent` | pointer | 0 | 8 | 0 | 4 | ESTABLISHED |
| `m_ucFormType` | `unsigned char` | 8 | 1 | 4 | 1 | ESTABLISHED |
| `m_uiFormFlags` | `unsigned int` | 12 | 4 | 8 | 4 | ESTABLISHED; 7 owner rows use the 32-bit offset |
| `iFormID` | `unsigned int` | 16 | 4 | 12 | 4 | ESTABLISHED |
| `m_kSourceFiles` | `BSSimpleList<TESFile*>` | 24 | 16 | 16 | 8 | ESTABLISHED; 4 owner rows use a 32-bit layout |

The original release is 32-bit only, and the owner's bodies are 32-bit
transcriptions. The basis is the rule for fields of such classes on the
rules page (2026-11-11): a field is ESTABLISHED on windows-x64 when

- (a) its order and size are taken from the transcribed declaration: they
  are the owner's own declaration, moved unchanged into the header;
- (b) its x64 offset is the ABI consequence of the declared types, measured
  by the compiler in every unit on the header: integration check (a), 73
  units, all at 8, 12, 16 and 24;
- (c) every x64 body that disagrees uses the 32-bit layout of the same
  declaration and is recorded below as a defect with its address;
- (d) no agreeing body contradicts it.

The constructor row's object code is not counted as evidence. Its class is
a look-alike laid out from the same types, so the offsets it uses are (b)
again, not an independent observation. Bodies that reach a field at its x64
offset agree with the table; they are listed because (d) asks that none of
them contradicts it, not because the status needs them:

- `m_ucFormType`: `TESForm::GetFormType` (`0x00401170`) and the rows
  `0x00485340` and `0x004853e0` read the byte at 8.
- `m_uiFormFlags`: 21 rows other than the constructor reach it at 12, among
  them `GetDisabled`, `SetMasterFile`, `MarkForDeletion`, `SetDestroyed` and
  `LoadGame`.
- `iFormID`: the rows `0x00483c70` and `0x00485c10` reach it at 16.
- `m_kSourceFiles`: no row other than the constructor reaches it.

The defects. Each row below uses the 32-bit layout on windows-x64. Offsets
are read from the row's object code in this build:

| Row | Defined as | What it does on windows-x64 | 32-bit field there |
| --- | --- | --- | --- |
| `0x004011b0` | `FUN_004011b0_shell::IsFlagSet` | reads the byte at `0xa` | byte 2 of the flags at 8 |
| `0x00401210` | `FUN_00401210_shell::HasFlag` | reads the byte at `0xb` | byte 3 of the flags at 8 |
| `0x00401250` | `FUN_00401250_shell::IsFlag200Set` | reads the byte at `0x9` | byte 1 of the flags at 8 |
| `0x00484610` | `FUN_00484610_shell::SetFlag2000` | reads and writes four bytes at `0x8` | the flags at 8 |
| `0x004849d0` | `FUN_004849d0_shell::SetFlag200` | reads and writes four bytes at `0x8` | the flags at 8 |
| `0x00484a70` | `FUN_00484a70_shell::FUN_00484a70` | reads and writes four bytes at `0x8` | the flags at 8 |
| `0x00484d60` | `FakeForm::SaveIfChanged` | passes four bytes at `0x8` to the save buffer | the flags at 8 |
| `0x00484e60` | `TESForm::GetFile` | takes the list from `FUN_00460140`, which returns the receiver plus `0x10` | the list at 16 |
| `0x00484ee0` | `TESForm::GetOwnerMaster` | the same, once | the list at 16 |
| `0x00484f50` | `TESForm::SetFile` | the same, five times | the list at 16 |
| `0x00483630` | `FUN_00483630_holder`, the destructor row | destroys an 8-byte list at `0x14` | the list at 16, 8 bytes |

`0x8` to `0xb` are the form type and its padding on windows-x64, and the
receiver plus `0x10` is `iFormID`. Both lie inside fields that are
established. `FUN_00460140` is a function row of `bgsdecalmanager.cpp`.
The destructor row's class places the list after a vfptr and 12 bytes of
padding: on 32-bit that is offset 16, the declared one; on windows-x64 the
vfptr is 8 bytes and the list lands at `0x14`, which is neither the x64
offset nor the 32-bit one. It is a stale 32-bit layout, not the 32-bit
offset itself, and the list size it destroys is the 32-bit 8 bytes.

These are 64-bit defects of those rows, of the kind VEGAS-18 exists to fix.
They are recorded and not changed: this change alters no function. Five of
them sit in slots of the form vftables, so a form reaches them:
`0x004011b0` (slots 39 and 40), `0x00401210` (44), `0x00401250` (46),
`0x004849d0` (47) and `0x00484d60` (21).

## The base

`include/fnv/base_form_component.h` declares `BaseFormComponent` with no
field and four virtual functions, as every copy does. The recipe has no
function row under its name. What the repository shows of it:

- The recipe binds `??0BaseFormComponent@@QAE@XZ`, in the symbols map of
  `src/fallout_shared/testexture.cpp`, to `0x00402d30`, a function row of
  `src/fallout_shared/magic/alchemyitem.cpp` whose body stores
  `&DAT_01011d68` into the object.
- `src/generated/data/vtables_0101.cpp` has that table, `?DAT_01011d68@@3HA`:
  four entries, each `_purecall`.

So the class's own four virtual functions are pure. The copies, and the
header with them, declare them as not pure; that keeps the four names
`BaseFormComponent::Init`, `Free`, `CopyFromBase` and `CompareWithBase`
undefined in the forced link, as they were before this change. Declaring
them pure is a separate change: it changes every object that emits a
vftable of the class.

That `TESForm` derives from `BaseFormComponent` rests on the copies, which
agree on it, and on the generated tables: the 24 tables of classes derived
from `TESForm` hold in slots 0 to 3 rows of the owner, two of them taking a
`BaseFormComponent*`, and the base's own table has four slots.
`src/generated/data/rtti.cpp` has a type descriptor for each class and no
hierarchy descriptor.

## The slot table

How many slots the class has: at most 78, by the recipe, above. At least
75, because all 24 generated tables hold the owner row `0x00485c10` in slot
74. The repository does not tell 76, 77 and 78 apart. The header declares
78, as every copy with a full vftable does; slots 75 to 77 are declared
because a copy had them, not because the repository shows them.

A slot is ESTABLISHED when the owner defines the member under `TESForm`'s
name, the compiler gives it that slot, and generated tables hold its address
in that slot and no other address of the owner. Otherwise it is OPEN.
"Tables" counts the generated tables, of 24, that hold the row in the slot.

A slot has an owner row when a row of the owning unit is the entry the
class passes down. Where the 24 tables hold several entries, a row of the
owning unit held by some tables can also be an override that a derived
class holds. That is the case in slots 73 and 75: `0x0050f670` is held by
9 tables, `TESBoundObject`'s among them, and `0x00401270`, a row of
`src/staging/blk_00400000_od.cpp`, by 12; `0x0067acd0` is held by one table
and `0x00401280`, a row of the same staging unit, by 23. So neither slot has
an owner row.

| Slot | Declared member | Owner row in the generated tables | Tables | Status |
| --- | --- | --- | --- | --- |
| 0 | `BaseFormComponent::Init` | `0x00483710`, defined as `TESForm::ClearData` | 24 | OPEN |
| 1 | `BaseFormComponent::Free` | `0x00483710`, defined as `TESForm::ClearData` | 24 | OPEN |
| 2 | `BaseFormComponent::CopyFromBase` | `0x00485340`, defined as `fnv_00485340::FUN_00485340_shell::FUN_00485340` | 24 | OPEN |
| 3 | `BaseFormComponent::CompareWithBase` | `0x004853e0`, defined as `CompareForm::FUN_004853e0` | 24 | OPEN |
| 4 | `~TESForm` | none |  | OPEN |
| 5 | `InitializeComponent` | `0x00483710`, defined as `TESForm::ClearData` | 4 | OPEN |
| 6 | `ClearData` | `0x00483710` | 16 | ESTABLISHED |
| 7 | `Unk_07` | none |  | OPEN |
| 8 | `Load` | none |  | OPEN |
| 9 | `Unk_09` | none |  | OPEN |
| 10 | `AppendForm` | `0x00483d20`, defined as `FUN_00483d20_shell::SaveIfNotTemporary` | 24 | OPEN |
| 11 | `SaveForm` | `0x00483710`, defined as `TESForm::ClearData` | 3 | OPEN |
| 12 | `LoadForm2` | none |  | OPEN |
| 13 | `WriteFormInfo` | `0x00483fc0`, defined as `FUN_00483fc0_shell::WriteToFile` | 24 | OPEN |
| 14 | `Unk_0E` | `0x00484150`, defined as `FUN_00484150_shell::IsFormTypeBelowThreshold` | 17 | OPEN |
| 15 | `Sort` | `0x00484020`, defined as `TESFormSortProxy::IsLessThan` | 17 | OPEN |
| 16 | `CreateForm` | `0x004867a0`, defined as `FUN_004867a0_cls::FUN_004867a0` | 17 | OPEN |
| 17 | `Unk_11` | none |  | OPEN |
| 18 | `MarkAsModified` | `0x00484b60` | 24 | ESTABLISHED |
| 19 | `MarkAsUnmodified` | `0x00484bc0` | 24 | ESTABLISHED |
| 20 | `GetSaveSize` | `0x00484bf0`, defined as `FUN_00484bf0_shell::FUN_00484bf0` | 13 | OPEN |
| 21 | `Unk_15` | `0x00484d60`, defined as `FakeForm::SaveIfChanged` | 10 | OPEN |
| 22 | `SaveGame` | `0x00484c20`, defined as `PC7d::FUN_00484c20` | 13 | OPEN |
| 23 | `LoadGame` | `0x00484da0` | 10 | ESTABLISHED |
| 24 | `LoadGame2` | `0x00484c50`, defined as `form_load_legacy::TESFormLoadProxy::FUN_00484c50` | 12 | OPEN |
| 25 | `Unk_19` | none |  | OPEN |
| 26 | `Unk_1A` | none |  | OPEN |
| 27 | `Unk_1B` | none |  | OPEN |
| 28 | `Revert` | none |  | OPEN |
| 29 | `Unk_1D` | none |  | OPEN |
| 30 | `Unk_1E` | none |  | OPEN |
| 31 | `Unk_1F` | none |  | OPEN |
| 32 | `Unk_20` | none |  | OPEN |
| 33 | `Unk_21` | none |  | OPEN |
| 34 | `InitItem` | `0x00483710`, defined as `TESForm::ClearData` | 5 | OPEN |
| 35 | `GetTypeID` | none |  | OPEN |
| 36 | `GetDebugName` | `0x004868f0`, defined as `S4868f0_host::FUN_004868f0` | 18 | OPEN |
| 37 | `IsQuestItem` | none |  | OPEN |
| 38 | `Unk_26` | `0x00549580`, defined as `FUN_00549580_shell::FUN_00549580` | 24 | OPEN |
| 39 | `Unk_27` | `0x004011b0`, defined as `FUN_004011b0_shell::IsFlagSet` | 24 | OPEN |
| 40 | `Unk_28` | `0x004011b0`, defined as `FUN_004011b0_shell::IsFlagSet` | 24 | OPEN |
| 41 | `Unk_29` | `0x004011d0`, defined as `FUN_004011d0_shell::FUN_004011d0` | 24 | OPEN |
| 42 | `Unk_2A` | `0x004011d0`, defined as `FUN_004011d0_shell::FUN_004011d0` | 24 | OPEN |
| 43 | `Unk_2B` | `0x004011f0`, defined as `fnv_004011f0::FUN_004011f0_shell::FUN_004011f0` | 24 | OPEN |
| 44 | `Unk_2C` | `0x00401210`, defined as `FUN_00401210_shell::HasFlag` | 24 | OPEN |
| 45 | `Unk_2D` | none |  | OPEN |
| 46 | `Unk_2E` | `0x00401250`, defined as `FUN_00401250_shell::IsFlag200Set` | 18 | OPEN |
| 47 | `Unk_2F` | `0x004849d0`, defined as `FUN_004849d0_shell::SetFlag200` | 18 | OPEN |
| 48 | `Unk_30` | none |  | OPEN |
| 49 | `MarkForDeletion` | `0x00484530` | 18 | ESTABLISHED |
| 50 | `SetAltered` | `0x00484730`, defined as `fnv_00484730::FUN_00484730_shell::FUN_00484730` | 16 | OPEN |
| 51 | `SetQuestItem` | `0x00484860`, defined as `Fake84860::FUN_00484860` | 18 | OPEN |
| 52 | `SetFormFlag40` | `0x004848b0` | 24 | ESTABLISHED |
| 53 | `SetHavokDeath` | `0x00484900` | 24 | ESTABLISHED |
| 54 | `SetNeedToChangeProcess` | `0x00484950` | 24 | ESTABLISHED |
| 55 | `Unk_37` | `0x00483710`, defined as `TESForm::ClearData` | 12 | OPEN |
| 56 | `readOBNDSubRecord` | none |  | OPEN |
| 57 | `IsActor_InEditor` | none |  | OPEN |
| 58 | `IsBoundObject` | none |  | OPEN |
| 59 | `Unk_3B` | none |  | OPEN |
| 60 | `GetIsReference` | none |  | OPEN |
| 61 | `Unk_3D` | none |  | OPEN |
| 62 | `Unk_3E` | none |  | OPEN |
| 63 | `IsMobileObject` | none |  | OPEN |
| 64 | `IsActor` | none |  | OPEN |
| 65 | `Unk_41` | none |  | OPEN |
| 66 | `CopyFrom` | `0x00485130`, defined as `FUN_00485130_shell::WarnCopyUnsupported` | 4 | OPEN |
| 67 | `Compare` | `0x00485170`, defined as `Mid485170::FUN_00485170` | 5 | OPEN |
| 68 | `CheckFormGRUP` | `0x004854e0`, defined as `FUN_004854e0_shell::IsGroupFormOfType` | 17 | OPEN |
| 69 | `InitFormGRUP` | `0x00485530`, defined as `FUN_00485530_shell::InitGroupForm` | 17 | OPEN |
| 70 | `Unk_46` | none |  | OPEN |
| 71 | `Unk_47` | none |  | OPEN |
| 72 | `Unk_48` | none |  | OPEN |
| 73 | `Unk_49` | none: `0x0050f670`, above, is an override |  | OPEN |
| 74 | `SetRefID` | `0x00485c10`, defined as `FUN_00485c10_shell::FUN_00485c10` | 24 | OPEN |
| 75 | `GetName2` | none: `0x0067acd0`, above, is an override |  | OPEN |
| 76 | `GetName` | none |  | OPEN |
| 77 | `SetEditorID_AtRuntime` | none |  | OPEN |

8 slots are established. 34 are open with an owner row: the generated
tables show which body the class passes down there, and the owner defines
that body under another class name, so the declared name is not bound to it.
36 are open without an owner row: every generated table overrides the slot
or holds a row of another unit.

In slots 5, 11, 34, 55, 66 and 67 the owner row is held by 3 to 12 tables
and other tables hold other entries: in each but 55, 6 tables hold a row of
`src/fallout_shared/tesobjectrefr.cpp`, and in 55, 12 tables hold a row of
`src/fallout_shared/tesobject.cpp`. The repository does not show, for these
six, that the owner row is the entry the class passes down rather than an
override. They are counted as owner rows; a later change that binds one of
them must show it first.

Seven slots hold `0x00483710`, an 11-byte function whose body is empty: 0,
1, 5, 6, 11, 34 and 55. One address serves seven slots. The owner defines it
once, as `ClearData`, and the compiler gives that member slot 6.

Slot 4 is the deleting destructor. Each generated table has its own class's
there. The owner has the row `0x00483600`, 44 bytes, defined as
`FUN_00483600_holder::DestroyHolder`.

## The declaration

`include/fnv/tes_form.h`, beside the other shared declarations, and
`include/fnv/base_form_component.h` for the base. The headers have no body.

The text is the declaration the owner compiled before. It declares:

- the base and the four fields;
- 74 virtual functions after the four of the base. The 8 established ones
  carry their address and slot in a comment;
- the 17 other members the owner defines or calls, each with a function row
  under `TESForm`'s name: 16 in the owner and `GetInitialized`
  (`0x004013e0`) in `bgsdehydration.cpp`;
- the constructor, and the static pointer `ms_pAllForms`, bound at
  `0x011c54c4`.

This departs from the shared-declaration method's "exactly the members whose
recipe function rows exist": the 70 open slots and the constructor are
declared without a function row under the class's name. The open slots are
65 virtual functions and the destructor in `tes_form.h` and the base's four
in `base_form_component.h`. A real polymorphic class with a layout needs them: a
class with a vftable cannot omit a slot, and a constructor left undeclared
would be generated inline and change the objects that construct a form. The
rules page records this exception for real polymorphic classes
(2026-11-11). It does not admit a member-only declaration of a real class.

How an open part is written. A slot cannot be left out, because every later
slot would lose its index, and a virtual function cannot be declared without
a name and parameters. So an open slot is declared with the spelling the
owner and the 72 moved units already used, and the header says that this
spelling is not a finding. An open slot leaves its name and parameters
open, never its index. Three consequences are rules:

1. Nothing may be concluded from the name or the parameters of an open
   slot. In particular a body may not be given that name on the strength of
   the header.
2. A unit may move only if the move changes nothing it does through an open
   slot: same index, same symbol. The object comparison below shows that.
3. When a slot becomes established under another name or other parameters,
   the header changes and every unit on it is compared again.

The constructor and the destructor are declared because units construct
forms and the class has a virtual destructor in slot 4. Their names,
`TESForm::TESForm` and `TESForm::~TESForm`, have no definition: the bodies
are the two rows named under "The owning unit".

Two function rows carry `TESForm`'s name in units that are not on the
header: `RevertWithFlagClear` (`0x00679760`, `package.cpp`) and
`SetCollisionDisabled` (`0x00693ef0`, `navmesh_loadsave.cpp`). They are not
declared. They join when their unit moves.

## The rule for moving a unit

A unit's copy is replaced by `#include "fnv/tes_form.h"` when all hold:

1. Layout. The compiler, in that unit, measures the copy as 40 bytes,
   alignment 8, base `BaseFormComponent` at 0, and the four fields with the
   shared names, types, offsets and sizes.
2. Slots. The copy has 78 slots. Each has the shared symbol, so the same
   name and parameters, with one exception: an established slot may carry
   another name with the same parameters. Today that is slots 52, 53 and 54.
3. Base. The `BaseFormComponent` the unit sees has the shared four slots and
   no field. Its text is replaced by `fnv/base_form_component.h` too, and
   only when every unit that sees that text passes.
4. Members. The unit compiles, so it calls no member the header lacks.
5. Object. The unit's object is byte-identical to the object before, with
   the COFF timestamp zeroed, or it differs only in that the old names of
   rule 2 are respelled: the symbol table exchanges exactly those undefined
   names, and every section has the same bytes and relocations afterwards.
6. Derived tables. Where the move makes a vftable of a derived class name
   an owner body in a slot, the change records, per vftable, whether the
   generated table at that vftable's recipe address holds the same body in
   the same slot, and lists every other vftable as unconfirmed.

Rule 5 covers what the first four cannot see: a virtual call that would use
another index, an override in a derived class that would stop overriding,
a call that would bind another overload. Each changes a byte or a symbol.

A unit whose copy fails rule 1, 2 or 3 stays on its copy. Where a header
serves several units and some fail, the header keeps the old text under
`#ifdef FNV_KEEPS_OWN_TESFORM` and each failing unit defines the macro before
its includes, with the reason.

A move credits one declaration and, for the respelled names, a binding to
the owner's body. It does not show that the receivers are forms, or
anything about lifetimes.

## What moved

Three code commits. Forced link of every archive member, windows-x64, 2,223
members in the same order at every commit:

| | 49f4e9d1b | Header and owner | 62 units | 10 units |
| --- | --- | --- | --- | --- |
| Undefined names | 35,223 | 35,223 | 35,223 | 35,223 |
| Left / entered | | 0 / 0 | 0 / 0 | 0 / 0 |
| Duplicate symbols | 0 | 0 | 0 | 0 |
| Imports | 137 | the same | the same | the same |
| Objects that differ from the column before | | 0 | 29 | 8 |
| Names with differing definitions in the archive | 525 | 525 | 525 | 525 |

The same commits on 15297e447 were built in full: 2,318 steps each, none
failed, and 20,788 warning lines that are equal once line and column are
removed; the counts of objects that differ were the same there. On
49f4e9d1b each column was rebuilt incrementally from those builds in the
same build tree: 160 units each, none failed, warnings equal, and the one
object that 49f4e9d1b changes is identical in all four. `src/generated`
and `build/units.json` are untouched.

- Header and owner. `tesform_TESForm.h` and `tesform_BaseFormComponent.h`
  include the shared headers. All objects are byte-identical.
- 62 units. `src/fallout_shared/TESForm.h` serves 63 units. 62 pass and now
  get the shared header; so does `src/fallout_shared/BaseFormComponent.h`.
  33 objects are identical and 29 differ by the three names only.
- 10 units with a copy of their own: `actorvalue`, `bgsdefaultobjectmanager`,
  `bgsragdoll`, `bgstalkingactivator`, `mediaset`, `tesregion`, `tesclass`,
  `tesfurniture`, `tesnpc`, `tesscriptrunmanager`. Three more copies of the
  base are replaced, `include/BaseFormComponent.h` among them. 2 objects are
  identical and 8 differ by the three names only.

The 37 objects that differ emit 63 vftables for classes derived from
`TESForm`. Every reference to `SetFormFlag40` is in one of them, in slot
52. Those tables named `TESForm::Unk_34`, `Unk_35` and `Unk_36`, which
nothing defines, and now name `SetFormFlag40`, `SetHavokDeath` and
`SetNeedToChangeProcess`, which the owner defines at `0x004848b0`,
`0x00484900` and `0x00484950`. No name leaves the link, because 20
units on other copies still require the three old names.

Rule 6 for those 63 vftables. The generated tables confirm 5: they hold
the three owner bodies in slots 52 to 54 at the recipe address of the
vftable name.

| Object | Vftable | Recipe address | Generated table |
| --- | --- | --- | --- |
| `bgsacousticspace.cpp` | `??_7FUN_005898c0@@6B@` | `0x010320fc` | `?DAT_010320fc@@3HA` |
| `bgsdefaultobjectmanager.cpp` | `??_7FUN_0058d760@@6B@` | `0x01032dc4` | `?DAT_01032dc4@@3HA` |
| `bgstalkingactivator.cpp` | `??_7TESBoundObject@@6B@` | `0x0102960c` | `?vftable_TESBoundObject@@3QBQEBXB` |
| `tescaravan.cpp` | `??_7TESBoundObject@@6B@` | `0x0102960c` | `?vftable_TESBoundObject@@3QBQEBXB` |
| `tesobjectcont.cpp` | `??_7TESBoundObject@@6B@` | `0x0102960c` | `?vftable_TESBoundObject@@3QBQEBXB` |

The address of `??_7TESBoundObject@@6B@` comes from the symbols map of
another unit; the three emitting units do not name it. The other 58 are
unconfirmed, not shown by the repository: for 55 the recipe gives an
address at which no generated table is, and for 3, `??_7TESObject@@6B@`,
the recipe has no address. By object:

- `actorvalue`: `??_7ActorValueInfo@@6BTESForm@@@`
- `bgsaddonnode`: `??_7BGSAddonNode@@6BTESBoundObject@@@`, `??_7FUN_004f8bc0@@6BTESBoundObject@@@`
- `bgsbodypartdata`: `??_7BGSBodyPartData@@6BTESForm@@@`
- `bgscamerapath`: `??_7BGSCameraPath@@6B@`, `??_7FUN_0058a450@@6B@`
- `bgsdebris`: `??_7MagicItemForm@@6B@`, `??_7FUN_004f9cd0@@6BTESForm@@@`, `??_7FUN_004f9db0@@6BFUN_004f9db0_Base@@@`
- `bgsdefaultobjectmanager`: `??_7NavMesh@@6BTESForm@@@`
- `bgsdehydration`: `??_7BGSDehydrationStage@@6B@`, `??_7BGSHungerStage@@6B@`, `??_7FUN_004012d0_shell@@6B@`
- `bgsexplosion`: `??_7BGSExplosion@@6BTESBoundObject@@@`
- `bgsimpactdata`: `??_7BGSImpactData@@6BTESForm@@@`, `??_7FUN_0058dc10@@6BFUN_00483630_Base@@@`
- `bgslightingtemplate`: `??_7BGSLightingTemplate@@6B@`
- `bgsmessage`: `??_7BGSMessage@@6BTESForm@@@`
- `bgsplaceablewater`: `??_7BGSPlaceableWater@@6BTESBoundObject@@@`
- `bgsragdoll`: `??_7BGSRagdoll@@6BTESForm@@@`
- `bgssleepdeprevation`: `??_7FUN_004020f0@@6B@`
- `bgstalkingactivator`: `??_7FUN_004fe640@@6BTESBoundAnimObject@@@`, `??_7TESObjectACTI@@6BTESBoundAnimObject@@@`, `??_7TESBoundAnimObject@@6B@`, `??_7TESObject@@6B@`
- `bgstextureset`: `??_7BGSTextureSet@@6BTESBoundObject@@@`
- `medialocationcontroller`: `??_7MediaLocationController@@6BTESForm@@@`
- `mediaset`: `??_7MediaSet@@6BTESForm@@@`
- `tesammo`: `??_7TESAmmo@@6BTESBoundObject@@@`
- `tescaravan`: `??_7TESCaravanCard@@6BTESBoundObject@@@`, `??_7TESCaravanDeck@@6BTESForm@@@`, `??_7FUN_0059a4f0@@6BTESBoundObject@@@`, `??_7TESObject@@6B@`
- `tescasinochips`: `??_7TESCasinoChips@@6BTESBoundObject@@@`, `??_7FUN_00504480@@6BTESForm@@@`, `??_7FUN_00503d40_shell@@6BTESBoundObject@@@`
- `tescombatstyle`: `??_7TESCombatStyle@@6B@`
- `teseyes`: `??_7TESEyes@@6BTESForm@@@`
- `tesfurniture`: `??_7TESObjectACTI@@6BTESBoundAnimObject@@@`, `??_7FUN_00508e00@@6BTESBoundAnimObject@@@`, `??_7FUN_00508ee0@@6BTESBoundAnimObject@@@`
- `tesglobal`: `??_7TESImageSpace@@6B@`
- `teshair`: `??_7TESHair@@6BTESForm@@@`
- `tesimagespacemodifier`: `??_7TESImageSpaceModifier@@6B@`
- `teslevitem`: `??_7FUN_0050b400@@6BB1_4fe@@@`
- `tesnpc`: `??_7TESNPC@@6BTESBoundObject@@@`, `??_7FUN_006013c0@fnv_006013c0@@6BTESBoundObject@@@`
- `tesobjectcont`: `??_7TESBoundAnimObject@@6B@`, `??_7TESObject@@6B@`
- `tesobjectstat`: `??_7TESGlobal@@6B@`, `??_7TESObjectSTAT@@6BTESBoundObject@@@`
- `tesobjectweap`: `??_7TESObjectWEAP@@6BTESBoundObject@@@`, `??_7FUN_0051db00@@6BTESBoundObject@@@`
- `tesregion`: `??_7FUN_004f0770@@6B@`
- `tessound`: `??_7TESSound@@6BTESBoundAnimObject@@@`
- `teswaterform`: `??_7FUN_0057eba0@@6BTESForm@@@`
- `tesweather`: `??_7TESWeather@@6BTESForm@@@`, `??_7FUN_005808e0@@6BW5808E0FormBase@@@`


Seven of the 72 moved units also include `include/TESForm.h`, which
declares another copy of the class under the same include guard,
`FNV_TESFORM_H`, as the moved headers: `bgscamerashot`,
`containeritemextra`, `packagedatadialogue`, `packageeventaction`,
`teleportdata`, `tesparameters` and `tesscriptrunmanager`. They reach the
shared header only because their include order brings a moved header
first and the guard then skips `include/TESForm.h`. A change of that order
would bring the other copy back. Check (a) catches it, since it requires
the unit to see the class from `include/fnv/tes_form.h`; the object
comparison catches it wherever the object depends on a slot in which the
two copies differ.

The copy in `src/fallout_shared/TESForm.h` declared `IsFormInitialized` and
`GetFormByID`. Neither has a function row under `TESForm`'s name and none of
the 62 units calls them, so the shared declaration does not have them.

## Units that did not move

By first reason, in the order of the rule:

| Reason | Units | Sites |
| --- | --- | --- |
| Another layout: 8 bytes 125, 1 byte 73, 32 bytes 15, others 15 | 228 | 182 |
| The owner's layout, another symbol in a slot other than 52, 53, 54 | 85 | 30 |
| The same offsets and sizes, the list field of another type | 2 | 2 |

With the owner and the 72 that moved this is all 388 units that see a
global definition.

- 56 units on `include/TESForm.h`: slot 8 is `LoadForm`, slot 28 takes a
  `BGSLoadFormBuffer*`.
- 29 units with a copy of their own: slot 8 is `LoadForm` in all. Three
  also differ in slots 23 and 28, one in 23, one in 39 and 64.
- `bgsmusictype.cpp` and `navmeshobstaclemanager.cpp` rename the list
  template with a macro, as `docs/shared-simple-list.md` records, so the
  source-file list in their `TESForm` is another type. The first is on
  `src/fallout_shared/TESForm.h` and defines `FNV_KEEPS_OWN_TESFORM`; its
  object is byte-identical. The second is on `include/TESForm.h`.
- 73 units see a `TESForm` of 1 byte: members without a layout, 45 of them
  through `include/fnv/decl/TESForm.h`. That header declares `ClearData`,
  `MarkForDeletion`, `MarkAsModified`, `MarkAsUnmodified` and `LoadGame`
  without `virtual`, so those units require five names that differ from the
  owner's definitions in that one letter.
- 35 definitions sit in a namespace and were not candidates.

## Derived classes

A derived class is laid out from the `TESForm` its unit sees. So a derived
class can have one shared declaration only when every unit that defines it
is on the shared `TESForm`. Until then its copies stay per unit, and they
are not compared here.

For the 72 moved units nothing changes in a derived class: the objects are
equal, so sizes, offsets, vftables and calls are what they were. What
changes is that their derived classes now override, or inherit from, the one
declaration, so a later change to a slot reaches all of them at once.

One derived class is deleted with two sizes. The scalar deleting destructor
`??_GTESObjectREFR@@UEAAPEAXI@Z` frees `0x98` bytes in
`inventorychanges.cpp` and `0x28` bytes in `tesscript.cpp`; the two
definitions differ, and the linker keeps one. Neither unit is on the shared
header. It is the first item for this family after the defective rows.

## Integration checks

Run these on every change that touches the two headers, a copy of the
class, or a unit on the header.

(a) Layout per unit. In every unit that includes `fnv/tes_form.h`, the
compiler measures `TESForm` as 40 bytes with the fields at 8, 12, 16 and 24
and the 78 symbols of the owner's vftable. Result on the last code commit,
measured before the rebase, which changes no object of these units: 73
units, the owner and the 72, all pass; the build's dependency records
show exactly 73 objects that include `include/fnv/tes_form.h`. 315 units
see a global `TESForm` from another site.

(b) Differing definitions. No function or data member of `TESForm` or
`BaseFormComponent` has two definitions in the archive, no name of the two
classes enters the set of names with differing definitions, and the count of
such names in the whole archive does not rise. Result: 0 functions or data
members of the two classes with two definitions, of 87 defined names;
525 names with differing definitions before and after, the same names.

Three of the 525 belong to `TESForm`, before and after: the RTTI names
`??_R1A@?0A@EA@TESForm@@8`, `??_R2TESForm@@8` and `??_R3TESForm@@8`, the
base class descriptor, the base class array and the class hierarchy
descriptor that the compiler emits. 70 units emit them, select-any, each
name in 3 variants, in 58, 11 and 1 units: the base class array is 12, 8
and 16 bytes, so the copies differ in how many classes lie above
`TESForm`, one, none or two. The linker keeps one and reports nothing.
They leave the set when every unit that emits them is on one declaration.
The check fails when a name enters the set, not because these three are in
it.

(c) The three bound names. `SetFormFlag40`, `SetHavokDeath` and
`SetNeedToChangeProcess` each have one definition, in the owner's object.
Result: each has one, in `tesform.cpp`.

The standing checks of `docs/shared-simple-list.md` hold on the last code
commit: 0 defined names of list classes with two definitions; 525 names
with differing definitions, none entering.

## Open items

Each needs a decision before the next step.

1. Slot 8. `Load` in the owner and the 72 units, `LoadForm` in 85 units and
   in `navmeshobstaclemanager.cpp`, the same parameter, no body under
   either name in the owner. The recipe has 63 virtual function rows named
   `Load` that take a `TESFile*`, and one named `LoadForm`
   (`TESTopicInfo`, `testopicinfo.cpp`) whose parameter is a `TESFile*`.
   The name follows VEGAS-11's rule and the coordinator decides it:
   `Load`. The next step respells the slot in the 24 units that differ from
   the shared declaration in slot 8 alone; their derived classes override
   the slot and are respelled with it.
2. Slot 23. The recipe row is `?LoadGame@TESForm@@UAEXPAX@Z`, a `void*`.
   The owner's body casts that parameter to `BGSLoadFormBuffer*`, and 7 of
   the recipe's other virtual rows of `LoadGame` take a
   `BGSLoadFormBuffer*`; the eighth, `0x0059adf0` in `tescaravan.cpp`, takes
   a `void*`. A pointer either way, so this is a spelling question for the
   recipe row.
3. Slot 28. The header's `Revert(unsigned int)` is contradicted: the
   overriding rows dereference the parameter (`BGSListForm::Revert` in
   `bgslistform.cpp`, `TESQuest::Revert` in `tesquest.cpp`), the recipe's
   4 virtual rows of `Revert` take a `BGSLoadFormBuffer*`, and the generated
   tables name `?Revert@TESNPC@@QEAAXPEAUBGSLoadFormBuffer@@@Z`. On
   windows-x64 an `unsigned int` cannot carry that pointer, so the open
   spelling truncates it: a VEGAS-18 defect, to be settled by evidence.
   Items 1 to 3 together move 60 more units: the 56 on `include/TESForm.h`
   (slots 8 and 28), 3 that differ in slots 8, 23 and 28, and one in 8
   and 23.
4. The 11 defective rows of the field table. Fixing them changes what those
   functions do on windows-x64, which this change may not do.
5. The constructor and destructor rows. Naming them `TESForm::TESForm` and
   `TESForm::~TESForm` retires those names and removes the two extra
   vftables of the owner. The destructor row must first destroy a 16-byte
   list at 24.
6. The 34 open slots with an owner row. The body exists under a stand-in
   name. Binding it to the declared member is a definer-side rename, and
   for three addresses one body serves several slots: `0x00483710` seven,
   `0x004011b0` two, `0x004011d0` two.
7. The 36 open slots without an owner row.
8. `BaseFormComponent`'s four pure virtual functions, under "The base".

## What this credits

One declaration of `TESForm` and `BaseFormComponent` for the owner and 72
units, and 63 vftables in 37 objects that now require the owner's three
bodies in slots 52 to 54, 5 of them confirmed by a generated table. No
undefined name leaves.

No VEGAS-18 acceptance criterion closes. The 11 defective rows violate its
criterion that no access by a fixed byte offset remains; five of them are
reached through slots 21, 39, 40, 44, 46 and 47 of the form vftables. The
open spelling of slot 28 is the kind its criterion that no pointer is
stored in a 32-bit integer is about. The next
change for this family repairs them, each with the original release's
disassembly and the windows-x64 one, the layout probe, the receiver type
at each call site, and a host test where one can be built.

## Not covered

- Receiver-only stand-ins were not replaced. 368 undefined names are bound
  by the recipe to 22 addresses of the owner. 327 are at a row that carries
  `TESForm`'s name, and 318 of those are spelled as a member of another
  class or as a free function, most at `GetFormType`, `0x00401170`. That
  row is 18 bytes by the recipe and reads `m_ucFormType`, at 4 in the
  32-bit layout; the recipe binds the same address under names of other
  classes too, such as `BGSClipRoundsForm::GetClipRounds`. So a name bound
  there is not shown to be a `TESForm` member by its address alone.
- 251 undefined names are members of the global `TESForm`. 234 are virtual
  functions that vftables of derived classes inherit. This change retires
  none.
- The 228 units with another layout, and the stand-ins measured above.
- The slot counts of the 63 derived vftables against the original
  release's: not shown by the repository beyond the 5 confirmed tables.
- The base relation and the slot count are as strong as stated in their
  sections and no stronger.
- Nothing executes these functions. Windows execution: not run.
