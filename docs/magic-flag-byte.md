# Magic record flag-byte operations

This is the constrained storage/operation portion of VEGAS-56, not completion
of the native spell/enchantment receiver migration.

`fnv::magic::FlagByte` owns exactly one unsigned byte. Spell and enchantment
reset/copy fields, the byte-mask setter and the existing flag predicate use the
same operations:

- `ContainsAnyFlag` returns an `int` normalized to zero or one. Any matching bit
  suffices; zero masks and masks containing only bits above the byte return zero.
- `SetFlags` sets or clears only the selected bits. The full unsigned mask is
  accepted, but cannot widen the stored byte.
- `Reset` clears the byte. Ordinary copy copies its value, not an alias.
- Default initialization remains trivial and does not initialize the byte;
  value initialization clears it, as with the replaced unsigned-byte fields.

Compile-time constraints preserve one-byte size/alignment, standard layout,
trivial default initialization and trivial copy/cleanup. They do not assert a
complete form's layout, construct its bases or validate any receiver adjustment.
The existing reset, copy and setter entry points remain in their complete
production translation units; no lifecycle or game function is extracted into a
test implementation. No virtual protocol, allocation domain, external signature,
generated data or archive membership is changed.

The focused `runtime.magic_flag_byte` test exercises this value interface with
active checks under `NDEBUG`, including every bit, combined/zero/high masks,
normalized results, selective mutations, reset and independent copies. It can
run as a standalone CMake target without linking the unfinished game owners.
It is not an actual spell/enchantment construction, UI, casting, cost or
vtable-wrapper test.

## One provider of the flag query

`FlaggedData::ContainsAnyFlag(unsigned int)` is the function at `0x0040e210`.
Its one definition is in `src/fallout_shared/magic/magicformulas.cpp` and
delegates to `FlagByte::ContainsAnyFlag`.

`src/staging/blk_008c0000_od.cpp` used to define the same function a second
time, returning zero for every mask. That body carried no address, and no
address is recorded for a second flag query: `include/fnv/decl/FlaggedData.h`
lists `0x0040e210` once. It was a placeholder for the callee of
`FlaggedData::FUN_008c2e30` (`0x008c2e30`), not a second semantic owner. It is
removed. The staging unit keeps its declaration and `FUN_008c2e30`, which now
calls the one definition with mask 4.

The one production caller of `FUN_008c2e30` is `ApplyActorSpells`
(`0x008c2b60`) in `src/fallout/ai/actor_magic.cpp`. It walks the spell list of
the actor's base and passes each `SpellItem*` unadjusted. It dispels the spell
from the actor only when the query returns zero, so a spell with bit 4 set is
no longer dispelled there. This is the recovered behaviour of the two
addresses, not a native policy.

No generated data names either function. No archive member is added, removed or
reordered.

## What the receivers are, and what is not established

The definition reads the byte `0x40` past its receiver. No call site holds a
`FlaggedData` object. Each passes a pointer to another type through a cast:

| Caller | Receiver passed |
| --- | --- |
| `FUN_008c2e30`, from `ApplyActorSpells` | a `SpellItem*` from the base spell list, unadjusted |
| `MagicCaster` units, masks `0x10` and `0x80` | a spell form pointer, unadjusted |
| `FUN_00823c20`, mask 2, from `MagicTarget::AddActiveEffect` | the `MagicItem*` argument less `0x18` |
| `interface.cpp` and `recipemenu.cpp`, mask 4 | the result of `FindFormEnchantment`, unadjusted |
| `FUN_004094a0` in `enchantmentitem.cpp`, mask 1 | `this` less `0x24` |
| `FUN_0040e670`, `FUN_0040e1e0`, `FUN_0040e650` in `spellitem.cpp` | `this` less `0x18` |
| `FUN_0040e600` in `spellitem.cpp`, mask 1 | `this`, unadjusted |
| `FUN_0040e520` in `spellitem.cpp`, mask 1 | `this` less 36 |

These adjustments and the `0x40` offset are the original release's 32-bit
layout. This change does not show that any windows-x64 producer places the flag
byte where a given receiver reads it, and it endorses none of the casts. The
removed body could not have been right for any of them: it ignored its receiver.

Neither affected unit compiles for the host, so no host test reaches
`FUN_008c2e30` or the definition. The evidence for this change is the rebuilt
windows-x64 object, the composed archive and the complete links.

## Explicitly outside this change

The legacy `FlaggedData` receiver declarations, their opaque prefixes and caller
adjustments are not repaired or endorsed. `FindFormEnchantment`, the native
owner/lifecycle, tests on constructed, loaded and copied spells and
enchantments, and the sixteen-byte load/save contracts remain VEGAS-56 work.
The rejected generic form-lifetime candidate is not included here.
