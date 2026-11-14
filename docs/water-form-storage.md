# Water form storage

This is the storage portion of VEGAS-71. `docs/placeable-water.md` recorded
that the declarations of `TESWaterForm` disagree on windows-x64 and that the
form factory allocates less than the owner's code addresses. This change makes
every site that allocates a water form provide the storage of the complete
type, and makes five functions of the owner reach their member by name. It
does not give the form a constructor; see "Outside this change".

## Which declaration is the form

`src/fallout_shared/teswaterform.cpp` owns the water form. Its recipe unit
holds the 27 function rows from `0x0057e9c0` to `0x005807a0`. The complete
declaration is `TESWaterForm` in
`src/fallout_shared/teswaterform_types_TESWaterForm.h`, which only the owner
includes.

Four declarations stated a layout at the previous tip. Each was measured with
the unit's own compile command, for windows-x64 and again with the 32-bit
target the recipe's addresses belong to:

| Declaration | Unit | 32-bit size | windows-x64 size |
| --- | --- | --- | --- |
| complete `TESWaterForm` | `teswaterform.cpp` | 404 | 520 |
| `TESForm` plus `0x17c` bytes | `tesdatahandler.cpp` | 404 | 424 |
| `TESForm` plus 33 fields of bytes | `bgsplaceablewater.cpp` | 404 | 456 |
| `FUN_0057eba0`, the class of the constructor body | `teswaterform.cpp` | 404 | 488 |

Nine more declarations name the class with a body and state no layout: an
empty class or a bare `TESForm` base in `extradatalist.cpp`,
`teswaterlistener.cpp`, `stars.cpp`, `tes.cpp`, `tesconditionfunctions.cpp`,
`tesobjectacti.cpp` and `tesworldspace.cpp`, one virtual function in
`tesscriptfunctions.cpp`, and one member function in
`include/fnv/decl/TESWaterForm.h`. None of them creates or embeds a form.

On the 32-bit target the four agree: 404 bytes, `0x194`, and every field of
the last two sits at the offset of the member it mirrors in the first. They
are four spellings of one class. They part on windows-x64 because only the
complete declaration gives its strings, smart pointers and form pointers
their native types. The others spell them as bytes or as 32-bit integers.

The complete declaration is the one the owner's code uses. The loader
`TESWaterForm::Load` (`0x0057ef80`), `InitItem` (`0x0057f8b0`),
`ResetFormData` (`0x0057ef10`), the copy, compare, save and load-game entries
and both placeable water producers are compiled against it. The constructor
body itself calls `ResetFormData` through it.

The recipe supports the same reading and adds nothing against it:

- The data handler's unit binds `??0TESWaterForm@@QAE@XZ` to `0x0057eba0`.
  The function row at that address is the owner's constructor body.
- The owner's unit binds the three vtables of the constructor body and of the
  destructor body (`0x0057ee10`) to the same three addresses, so both belong
  to one class with a `TESForm` base and two more polymorphic bases.
- The owner's unit binds the calls of the constructor body to
  `TESFullName::TESFullName` (`0x00402d00`),
  `TESAttackDamageForm::TESAttackDamageForm` (`0x0047fdc0`),
  `TESTexture::TESTexture` (`0x0048e270`) and `BSStringT<char>::BSStringT`
  (`0x004037b0`). Those are the bases and members of the complete declaration.

No generated unit holds a vtable or other data of the water form.
`src/generated/data/fallout_shared/teswaterform.inc` defines two float
constants.

## Allocation sites

A census of every line that names the class found two new-expressions, no
object, member or array of the class, and no `sizeof`. Thirteen classes
derived from it before this change and 18 do now: the five receiver classes
of the next section are added. All 18 are receiver classes in the owner
unit; no object of them is created and the owner's object holds no
constructor for any of them.

| Site | Storage before | Storage now |
| --- | --- | --- |
| `tesdatahandler.cpp:517`, `TESDataHandler::CreateFormForType`, type 78 | 424 | 520 |
| `tesdatahandler.cpp:2910`, `TESDataHandler::InitializeMagicSystem`, the default water | 424 | 520 |

Both sites now call `fnv::water::NewWaterForm`
(`include/fnv/water/water_form.h`). It runs `new TESWaterForm` in the owner
unit. In the objects, the two requests for `0x1a8` bytes and the two calls of
the constructor leave the data handler, and the owner requests `0x208` bytes
once.

The data handler keeps its view of the class for its casts and for the calls
it makes through the `TESForm` base. The view no longer has the `0x17c` bytes,
and its constructor is deleted, so the data handler cannot allocate the form.
`TESForm` is at offset 0 in the view and in the complete type.

What the owner's functions address in a form, measured in the owner's object.
The column holds the end of the highest store through a register: its
displacement plus its width, so the last byte written is one less. For
`SetNP` it is the address it passes to the smart pointer's assignment plus
the 8 bytes of the pointer, because the store is made by the callee.

| Function | End of highest store | In 424 | In 520 |
| --- | --- | --- | --- |
| `InitItem` | 512 | no | yes |
| LOD producer `0x00580330` | 504 | no | yes |
| auto producer `0x00580130` | 496 | no | yes |
| `FUN_0057f890`, `Load`, the copy entry | 480 | no | yes |
| `ResetFormData` | 432 | no | yes |
| `SetNP` `0x005800c0`, before | 768 | no | no |
| `SetNP`, now | 488 | no | yes |

## Members reached by offset

Five functions of the owner unit addressed one member of their receiver
through a private class that spelled the member's 32-bit offset as padding.
The padding does not grow with the pointers before the member, and in one
case it grew too far.

| Function | 32-bit offset | Member there in the complete type | windows-x64 before | Now |
| --- | --- | --- | --- | --- |
| `SetNP` `0x005800c0`, stores the noise texture | 380 | `m_kNoiseTextureData` | 760 | 480 |
| `FUN_0057fef0`, sets the material name | 116 | `m_kMaterialId` | 116 | 176 |
| `FUN_0057fda0`, returns the material name | 116 | `m_kMaterialId` | 116 | 176 |
| `FUN_00580060`, tests bit 0 of the flags | 113 | `cFlags` | 113 | 169 |
| `FUN_00580100`, returns the opacity as a fraction | 112 | `m_ucOpacity` | 112 | 168 |

`SetNP` padded with 95 pointers, so its store landed 240 bytes past the end
of a 520-byte form. The material name setter wrote a 16-byte string into the
second and third scroll colours.

Each private class now derives from `TESWaterForm` and names the member. The
functions keep their linked names and call the same functions as before.
`src/generated` and `build/units.json` are unchanged.

Two callers in the owner unit change with them, because the compiler inlines
the material name functions into them:

- The copy entry `WaterEffectSetting::FUN_0057fde0` (`0x0057fde0`) read the
  source form's material name at 116 and set it at 116 in the copy. Offset
  116 in the complete type is in the scroll colour floats. Both now use 176.
- `SaveWaterForm` (`0x0057fbf0`) already took the name's length at 176
  (`0xb0`) but read the string at 116 (`0x74`). It now reads both at 176.

No other function of the owner's object changes. The functions that change
and their instructions are tabled in the evidence of this change.

The repaired functions still reach the member through classes of their own,
not through the member's type: `SetNP` assigns through `NP::operator=(void*)`,
the material name getter converts through `Flt::operator unsigned __int64()
const`, and the setter calls `TextString::FUN_004037f0`. All three callees are
stand-ins. The first two have no provider in the archive.

Each receiver is a water form by the types of its callers:

- `FUN_0057fef0` and `FUN_0057fda0` are called only in the owner unit, on
  `this` in the copy, compare and save entries and on the result of
  `dynamic_cast<TESWaterForm*>`.
- `SetNP` is called in `tes.cpp` on each item of the data handler's water
  form list. The two allocation sites above are the code that fills the list.
- `FUN_00580060` is called on results of `FUN_00547770`, declared to return
  `TESWaterForm*`, in `teswaterlistener.cpp`, `tesconditionfunctions.cpp` and
  `actor.cpp`.
- `FUN_00580100` is called in `teswater.cpp` on the result of
  `TESBoundObject::GetAssociatedWaterForm`, declared to return
  `TESWaterForm*`.

That those callers' own receivers are what their casts say is not audited
here.

## The view in the placeable water unit

The 456-byte view of the table above was in this unit, the unit that owns
`BGSPlaceableWater`, not in the water form's owner unit as the ticket says.
`bgsplaceablewater_decls.h` no longer lists fields for `TESWaterForm`. Its one
user, `bgsplaceablewater.cpp`, reads no member and creates no object of the
class. The object of that unit is byte-identical before and after.

## Tests

No test constructs a water form, and none was added. The stale offset repairs
have no test either. A test is a condition of the first provider of the
constructor. A form is created by
`fnv::water::NewWaterForm`, which needs `TESWaterForm::TESWaterForm`, and that
needs `TESForm::TESForm`. Neither has a definition in the archive, so no
program that contains the entry links. The owner unit also does not compile
for the host build targets of the test suite. The checks of this change are
measurements of the windows-x64 objects and of the four links.

## Outside this change

- The constructor body `FUN_0057eba0::FUN_0057eba0` (`0x0057eba0`) is still a
  class of its own, 488 bytes on windows-x64, with members at offsets the
  complete type does not have. The misplacement is wider than the two
  placeable water pointers. It constructs its texture at 128, its material
  name at 152 and its shader settings at 176, where the complete type has them
  at 144, 176 and 208, and it nulls the two placeable water pointers at 456
  and 464, not at 488 and 496. The end of its highest store is 481, so the
  last byte it writes is 480 and the complete type's members from 488 to 519
  would be left unwritten. Nothing calls it: the factory's name for it,
  `TESWaterForm::TESWaterForm`, has no definition. It is the gate before any
  provider of a `TESWaterForm` constructor: it must become the constructor of
  the complete type before that name gets one.
- The recipe's binding row for `??0TESWaterForm@@QAE@XZ` (`0x0057eba0`) is in
  the data handler's recipe unit, `tesdatahandler.cpp`. After this change the
  only reference to the constructor is in the owner's object, from
  `fnv::water::NewWaterForm`. The row is moved or respelled in the commit that
  defines the constructor.
- `fnv::water::NewWaterForm` has no recipe row, like
  `fnv::water::NewPlaceableWater`. It must stay an entry that only allocates
  and constructs. It is removed once a shared declaration of the class lets
  the data handler see the complete type.
- Doing that needs definitions under the complete type's own names for what
  the body constructs. On the 32-bit target the recipe binds them to
  `0x00483370` (`TESForm`), `0x00402d00` (`TESFullName`), `0x0047fdc0`
  (`TESAttackDamageForm`), `0x00633c90` (a smart pointer from a null
  pointer, twice), `0x00414430` (a four-float colour, three times),
  `0x0048e270` (`TESTexture`), `0x004037b0` (`BSStringT<char>`), `0x0057e9a0`
  (the shader settings) and `0x004f15a0` (the form type setter). Today
  `TESFullName` and `TESTexture` have no declared constructor in their shared
  headers, the colour and the shader settings are defined under other class
  names in other units, and the two smart pointers need the complete texture
  types for their release.
- The destructor body `FUN_0057ee10::~FUN_0057ee10` (`0x0057ee10`) is in the
  same state: a class of 400 bytes whose four members sit at 64, 116, 132 and
  396, where the complete type has them at 88, 144, 176 and 480. It is called
  by `Unk_57::FUN_0057ede0` in `tesattackdamageform.cpp`, which nothing calls.
- `FUN_005806e0_s::FUN_005806e0` (`0x005806e0`) reads a pointer at offset 128.
  The complete type has `m_pWaterForm` at 200. It has no caller in source. It
  may be a slot of a save-game virtual table that is not built yet, so its
  receiver is not established and it is unchanged.
- The declarations of the data handler (`tesdatahandler_forms.h`) and of
  `bgsplaceablewater_decls.h`, both with a `TESForm` base, and the nine other
  bodies listed under "Which declaration is the form" are still second
  definitions of `TESWaterForm` with base lists that differ from the complete
  type's. That is ill-formed under the one-definition rule, and no diagnostic
  is required. They emit nothing that depends on the size, and in the data
  handler's view `TESForm` is at offset 0 as in the complete type, but that
  does not make the program well-formed. The end state is one of two: one
  shared declaration of the complete type by the method of
  `docs/shared-simple-list.md`, or the data handler holding only a forward
  declaration and using owner entries that return `TESForm*`, as
  `fnv::water::PlaceableWaterForm` does for the placeable water.
- The callers of three repaired functions include copies under
  `include/fnv/decl/` that declare the receiver classes with no base:
  `FUN_00580060_shell.h` (included by `teswaterlistener.cpp`,
  `tesconditionfunctions.cpp` and `actor.cpp`), `FUN_005800c0_shell.h`
  (`tes.cpp`) and `FUN_00580100_obj.h` (`teswater.cpp`). The owner's classes
  of those names now derive from `TESWaterForm`.
- Three calls in the owner reach a function of another class with the form
  as its receiver, and that function uses its own class's windows-x64 offset:

  | Call | Defined in | Byte it uses | Member the 32-bit offset names | That member's offset |
  | --- | --- | --- | --- | --- |
  | `EffectSetting::SetEnchantEffectShader`, in `Load` and the copy entry | `bgstalkingactivator.cpp` | writes 128 to 135 | `m_pWaterSound` (`0x7c`) | 192 |
  | `TESPackage::GetRefCount`, in the copy and compare entries | `speedtreeshaderproperty_h_unit.cpp` | reads 124 to 127 | `m_pWaterSound` (`0x7c`) | 192 |
  | `FUN_0047ff50_class::FUN_0047ff50`, in `Load` | `blk_00460000_od.cpp` | writes 4 and 5 | not established | |

  All three stay inside the form. The first two are the sound role that
  VEGAS-71 excludes and VEGAS-78 owns. The third stores a zero into the upper
  half of the form's first vtable pointer; which member the original reaches
  is not established.
- The constructor body is blocked on constructors under the shared names for
  `TESForm`, `TESFullName`, `TESTexture`, the colour and shader settings
  types, the two smart pointers and the form type setter.
- `TESForm`'s constructor and destructor and the form type setter with the
  signature the constructor body calls have no definition. No water form can
  exist in a linked program.
- The data handler's other form types are still sized by its private views.
- Record load and save, the three entries without a consumer and the
  callers' receiver casts are as `docs/placeable-water.md` records them.
