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

## Explicitly outside this change

The legacy `FlaggedData` receiver declarations, their opaque prefixes and caller
adjustments are not repaired or endorsed. The competing always-zero provider is
not removed, weakened or selected by link order. The duplicate diagnostics and
full-executable acceptance therefore remain open. `FindFormEnchantment`, the
native owner/lifecycle and sixteen-byte load/save contracts also remain VEGAS-56
work. The rejected generic form-lifetime candidate is not included here.
