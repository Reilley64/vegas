# Owning water setter

This is the bounded water portion of VEGAS-78. It removes the second
definition of `FUN_00589f50_shell::SetSound(void*)` and gives the two callers
that used it a typed operation in the placeable water owner. The sound, status
and topic-marker receivers are not repaired; see "Outside this change".

## What the recipe records

`build/units.json` is the authority for addresses.

| Unit | Entry | Address | Size |
| --- | --- | --- | --- |
| `src/fallout_shared/bgsacousticspace.cpp` | function `FUN_00589f50_shell::SetSound(void*)` | `0x00589f50` | 22 |
| `src/fallout_shared/bgsacousticspace.cpp` | symbol, the same name | `0x00589f50` | |
| `src/fallout_shared/teswaterform.cpp` | symbol, the same name | `0x00589f50` | |
| `src/fallout_shared/bgsimpactdata.cpp` | symbol, the same name | `0x00589f50` | |
| `src/fallout/magic/magictarget.cpp` | symbol, the same name | `0x00589f50` | |
| `src/staging/blk_00460000_od.cpp` | symbol, the same name | `0x00589f50` | |
| `src/fallout_shared/water_record_converters.cpp` | symbol, the same name | `0x00589f50` | |

The recipe lists 00589f50 as a function of the acoustic space unit only. Every
unit that names it binds the name to that one address. The recipe binds no
other name to the address. `teswaterform.cpp` lists it as a name it requires,
not as one of its 27 functions, and the empty body it defined carried no
address. That body was a placeholder that let the unit compile.

The rows are unchanged by this change. No name changes, so no recipe key
changes. The row of `teswaterform.cpp` stays as the record of what the
original unit bound, as its rows for the placeable water constructor did after
VEGAS-71. Neither the source nor the rebuilt object of
`water_record_converters.cpp` refers to the name.

## One address, several receivers

The body at 00589f50 in `bgsacousticspace.cpp` is one store: it writes its
pointer-sized argument over `m_eCellEnvironmentType`. The unit's header records
that member at `+0x4C` in the original layout.

The placeable water header records `Data` at `+0x48` with 8 bytes: the flags
word and, at `+0x4C`, the owning water. The class's recorded member signatures
hold exactly one `void (TESWaterForm*)`, and `BGSPlaceableWater::InitItem`
reads the same word as the owning water and falls back to the default water
when it is null.

Inference, not a recorded fact: at the original layout a one-store setter of
`+0x4C` is the environment type setter of an acoustic space and the owning
water setter of a placeable water, so the original program has one function at
one address for both, and the two water form producers bind it. The recipe
records bindings per unit, not call edges. That the producers' last call is
this one comes from their source, which passes the water form itself.

The native types do not share that offset. Measured on windows-x64 with each
unit's own recipe:

| Type, in the unit that declares it | Size | Offset written or held |
| --- | --- | --- |
| `BGSAcousticSpace` | 136 | `m_eCellEnvironmentType` at 128, 4 bytes; `m_iFlags` at 132 |
| store of the body at 00589f50 | | bytes 128 to 135 of its receiver |
| `BGSPlaceableWater` | 144 | flags at 128; `m_pOwningWater` at 136 |
| store of `fnv::water::SetOwningWater` | | bytes 136 to 143 of the placeable water |

Removing only the placeholder would have bound both producers to the acoustic
body. On windows-x64 that body would write the water form's address over the
flags the producer had just set, and leave the owning water null. That is why
the producers get a typed operation instead.

## The change

- `src/fallout_shared/teswaterform.cpp` no longer declares
  `FUN_00589f50_shell`, defines its empty `SetSound`, or declares the empty
  `fnv_00580330::FUN_00589f50_shell`. `FUN_00580130` and `FUN_00580330` end
  with `fnv::water::SetOwningWater(water, this)`.
- `src/fallout_shared/bgsplaceablewater.cpp` defines
  `fnv::water::SetOwningWater`, which assigns `Data.m_pOwningWater`.
  `include/fnv/water/placeable_water.h` declares it beside the owner's two
  other entries.
- `src/fallout_shared/bgsacousticspace.cpp` is unchanged and holds the one
  definition of `FUN_00589f50_shell::SetSound`.

## Every definition and requirer

Read from the rebuilt windows-x64 objects before and after the change. No
other object defines or requires either name, and no generated data names
them.

| Object | Before | After |
| --- | --- | --- |
| `bgsacousticspace.cpp` | defines `SetSound`, 8 bytes; its two local calls in `Load` and `CopyFromAcousticSpace` are inlined | the same; symbol table unchanged |
| `teswaterform.cpp` | defines `SetSound`, 1 byte; the two producers' calls compiled to nothing | no `SetSound`; each producer calls `SetOwningWater` |
| `bgsplaceablewater.cpp` | neither name | defines `SetOwningWater`, 8 bytes |
| `bgsimpactdata.cpp` | requires `SetSound`, from `BGSImpactData::Load` | the same; symbol table unchanged |
| `magictarget.cpp` | requires `SetSound`, from `MagicTarget::AddActiveEffect` | the same; symbol table unchanged |
| `blk_00460000_od.cpp` | requires `SetSound`, from `LoadHandler::FUN_00467780` | the same; symbol table unchanged |
| `water_record_converters.cpp` | neither name | the same |

Both definitions of `SetSound` were in COMDAT sections with the no-duplicates
selection, not select-any ones, so a link that needed the name reported a
duplicate and did not pick one silently. Across the archive each of the two
names has one definition after the change.

## Behaviour change

`FUN_00580130` (auto water) and `FUN_00580330` (LOD water) create a placeable
water when the water form has none. Before, the new form's owning water stayed
null. Now it is the water form that created it. Nothing else in the two
functions changes: the pointer is published first, the flags and editor name
are set, and the owning water is stored last, in the source's order.

This is recovered behaviour of the producers. The entry
`fnv::water::SetOwningWater` is a deliberate native policy: the water form unit
cannot include the complete placeable water type, so the store lives in the
owner, as creation does.

The pointer is borrowed. The placeable water does not retain the water form,
and no source path destroys either.

Two readers of the member now see a non-null value for a produced form. Both
are unchanged and neither can run yet.

- `BGSPlaceableWater::InitItem` treats the member as a pending form ID when
  the form is not yet initialised: it truncates the value to 32 bits, resolves
  it and replaces the pointer. For a produced form the value is a native
  pointer. Before, the member was null and `InitItem` installed the default
  water. Whether `InitItem` runs on a produced form is not established.
- The save entry `FUN_004fc7b0` calls 0084e3a0 on a non-null owning water and
  writes the result in the pointer's place. No object references that entry.

## Which programs contain the affected objects

- The lazy game link succeeds before and after. Its map lists no member of
  `teswaterform.cpp`, `bgsplaceablewater.cpp`, `bgsacousticspace.cpp`,
  `bgsimpactdata.cpp`, `magictarget.cpp` or `blk_00460000_od.cpp`.
- Of the 55 test executables, 54 link before and after. None of their maps
  lists one of those objects.
- `tests/runtime_havok_worker_pool_test.exe` does not link. Its closure
  contains all six objects. With duplicates and unresolved names forced, the
  linker bound `SetSound` to the empty body before and to the acoustic body
  now.

No program that links today reaches the changed code.

## Outside this change

These remain open in VEGAS-78.

- The body at 00589f50 writes 8 bytes through a 4-byte enumeration member. On
  windows-x64 the second half covers `m_iFlags`. Its two local callers also
  read 8 bytes from a 4-byte temporary. The acoustic role needs an operation
  that stores the environment type as its own type.
- The three external requirers still reach the acoustic body with receivers
  that are not acoustic spaces. Measured on windows-x64 against the store at
  bytes 128 to 135:

  | Requirer | Receiver it passes | Storage that unit declares for it |
  | --- | --- | --- |
  | `BGSImpactData::Load`, `SNAM` | the impact data | 176 bytes; primary sound at 120, secondary sound at 128 |
  | `MagicTarget::AddActiveEffect` | a `ValueAndConditionsEffect` or `LimbConditionEffect` | 8 bytes each in that unit's view |
  | `LoadHandler::FUN_00467780` | the object `DAT_011c3f38` points to | `LoadTopic`, an empty view |

  The impact data call therefore stores the form ID of its first sound in the
  slot of the second. Each of the three needs its own typed operation: a
  pending sound ID, an active-effect status and a topic group marker. Before
  this change a complete link could not choose between the two bodies for
  them; now there is only the acoustic one.
- `BGSPlaceableWater::InitItem`, `Load` and the save entry keep a wire form ID
  and a native pointer in the same member.
- No test executes the producers or `SetOwningWater`. A complete placeable
  water cannot be linked, for the reasons in `docs/placeable-water.md`, and
  the water form layout gap recorded there still applies to both producers.
  `runtime.placeable_water_data` covers assignment of the member through the
  header only.
