# Placeable water construction and flags

This is the bounded construction and flag portion of VEGAS-71. It gives each of
the three colliding operations one definition and connects every producer of a
placeable water form to the one complete type. It does not make the form
linkable or runnable; see "Outside this change".

## Owner

`src/fallout_shared/bgsplaceablewater.cpp` owns `BGSPlaceableWater`. Its data
member is `PlaceableWaterData` from `include/fnv/water/placeable_water.h`:
32 flag bits and a native pointer to the owning water form.

| Operation | Definition |
| --- | --- |
| `BGSPlaceableWater::BGSPlaceableWater()` (`004fc1b0`) | owner |
| `FUN_005802d0_shell::FUN_005802d0` (`005802d0`), flag `0x10` | owner |
| `FUN_00580310_t::SetFlag400` (`00580310`), flag `0x400` | `src/staging/blk_00580000_od.cpp` |

`src/fallout_shared/teswaterform.cpp` no longer defines any of the three. Its
`TESForm`-plus-padding `BGSPlaceableWater`, the empty constructor and the empty
`FUN_004fc450`, `FUN_004fc3a0`, `SetFlag400` and `FUN_005802d0` bodies are
removed. The empty `FUN_00589f50_shell::SetSound` body was removed later; see
`docs/owning-water-setter.md`.

## Producers

Three source sites create a placeable water form. Each now calls
`fnv::water::NewPlaceableWater`, which runs `new BGSPlaceableWater` in the
owner, so the allocation has the size of the complete type.

| Producer | Before |
| --- | --- |
| `TESDataHandler::CreateFormForType`, type 35 | sized by a private `TESBoundObject` plus `0x20` bytes |
| `FUN_00580130_shell::FUN_00580130`, auto water | sized by `TESForm` plus `0x38` bytes, empty constructor |
| `fnv_00580330::FUN_00580330_shell::FUN_00580330`, LOD water | sized as `0x50` bytes, constructor without a definition |

The LOD producer now derives from `TESWaterForm` and uses its
`m_pPlaceableWater` member, as the auto producer uses `m_pPlaceableAutoWater`.
It used to read and write the pointer through a private view of the receiver
with `0x184` bytes of padding before the member, which on windows-x64 put the
pointer at `0x188` (392). Its return type is `::BGSPlaceableWater*`; the separate
`fnv_00580330::BGSPlaceableWater` name is gone, which changes the function's
linked name for its one caller in `teswater.cpp`.

If construction throws, the new-expression in the owner releases the storage
and the producer's member stays null, because the member is assigned after the
entry returns. The producers publish the pointer before they set flags and the
editor name, in the source's order.

## Flags

`FUN_004fc990_t::FUN_004fc990` (`004fc990`) sets or clears bits in the `Data`
member of its receiver. It used to go through `FUN_00624700`, which is the head
part's accessor for its extra-parts list and stays unchanged for head parts.
Every caller of `FUN_004fc990` is one of the flag entries below, and every
caller of those entries passes a `BGSPlaceableWater` built by its constructor:
the owner's own `this`, or the object a water-form producer just created.

- owner: `FUN_004fc360`, `FUN_004fc380`, `FUN_004fc3a0`, `FUN_004fc3c0`,
  `FUN_004fc3e0`, `SetFlag800`, `FUN_004fc420`, `FUN_004fc450`, `FUN_004fc470`,
  `FUN_004fc490`, `FUN_005802d0`
- `teswaterform.cpp`: `FUN_005802f0`
- `blk_00580000_od.cpp`: `SetFlag400`, `SetValue`, `SetFlag80`, `SetFlag100`,
  `SetFlag8000000`

`BGSPlaceableWater::HasFlags` (`00452460`) moves from `tes.cpp` to the owner
and reads the same member. Its callers in `tes.cpp`, `teswater.cpp` and
`blk_004e0000_od.cpp` reach it through receiver casts that this change does not
audit.

The owner's reset, copy and compare entries also use `Data` directly.

## Deliberate native policies

- Producers create the form through `fnv::water::NewPlaceableWater` and reach
  its `TESForm` base through `fnv::water::PlaceableWaterForm`, not through a
  new-expression or cast of their own. The data handler has private views of
  the form types, and the water form unit has a private `TESModel`, so neither
  can include the complete type.
- Construction and reset clear the flags and the pointer. The replaced code
  cleared eight bytes, which on a 64-bit target left the pointer unset.
- Copy and compare use both members. The replaced eight-byte copy and compare
  covered the flags and padding on a 64-bit target.
- The owner's three calls that clear flag `0x40000000` now reach the real
  `fnv_004fc450::FUN_004fc450_shell::FUN_004fc450`. They were bound to the
  empty body in `teswaterform.cpp`. Loading a `DNAM` record from a file with
  form version below 9 therefore clears the bit.

## Tests

`runtime.placeable_water_data` covers `PlaceableWaterData` with checks that
stay active under `NDEBUG`: construction over dirty storage, every bit set and
cleared alone, flags `0x400` and `0x10`, the top bit from an `int` mask, any-bit
queries, clear, copy and compare including the pointer. It needs only the
header. It is not a test of form construction, publication or retirement.

## Outside this change

- `TESForm`'s constructor and destructor, `TESModel`'s constructor and the
  form-type setter with the signature the constructor calls have no definition
  in the archive, so a complete placeable water cannot be linked or run. No
  test constructs one.
- `Load` and the save entry `FUN_004fc7b0` still read and write the eight-byte
  record through the native `Data` object, and the save entry still constructs
  a `HungerStageData` in a local `PlaceableWaterData`. The owning water's form
  ID is not carried between the record and the pointer on a 64-bit target.
  This is unchanged from the previous tip.
- `FUN_004fc860` (copy), `FUN_004fc8c0` (compare) and `FUN_004fc7b0` (save)
  have no consumer: no object in the archive references them. They run only
  once the form's dispatch is wired.
- The producers ended with the empty `SetSound` body. They now store the
  owning water; see `docs/owning-water-setter.md`.
- No source path destroys the forms the two water-form producers publish.
- Each producer has one caller, and both pass a `TESWaterForm*`:
  `bgsautowater.cpp` calls `FUN_00580130` on the result of `FUN_00547770`, and
  `teswater.cpp` calls `FUN_00580330` on the result of `FUN_005860c0`. Both of
  those return `::TESWaterForm*`. The receivers that callers cast for
  `HasFlags` are not established to be the complete type.
- No water form can exist in a linkable program, and the views of
  `TESWaterForm` do not agree. Measured on windows-x64:

  | View | Size or offset in bytes |
  | --- | --- |
  | shared `TESWaterForm` declaration (`teswaterform_types_TESWaterForm.h`) | 520 |
  | its `m_pPlaceableAutoWater` | 488 |
  | its `m_pPlaceableWater` | 496 |
  | the data handler's private `TESWaterForm`, which sizes the factory's `new TESWaterForm` | 424 |
  | pointers the constructor body `FUN_0057eba0` nulls | 456 and 464 |
  | auto producer's read and write, at the previous tip and now | 488 |
  | LOD producer's read and write at the previous tip | 392 (`0x188`) |
  | LOD producer's read and write now | 496 |

  Both producers therefore write past the end of a form the factory made, and
  at offsets the constructor body does not null. None of this can run yet:
  `TESWaterForm::TESWaterForm`, which the factory calls, has no provider, and
  nothing references `FUN_0057eba0`. The factory's allocation and the
  constructor body must be bound to the complete type before any provider of
  that constructor lands.
- The owner and `tesobject.cpp` each declare `TESBoundObject`; that the two
  agree is not established.
- The data handler's other form types are still sized by its private views.
