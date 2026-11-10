# Native data ownership composition

The historical files under `src/generated/data/` are committed legacy inputs,
not the native source of truth. Do not edit them or run an extractor against
the original game to build the native reconstruction.

`src/runtime/native_data_retirements.patch` is the narrowly audited native
ownership delta. It retires duplicate scalar storage and incompatible,
source-audited unused byte-layout tables/declarations; it does not replace
required objects with stubs, rename incompatible receivers or clone values.
The genuine owner modules and typed declarations remain the source of the
native globals and protocols. This patch preserves the same twelve-file
retirements previously reviewed for VEGAS-1, not additional engine work.

VEGAS-86 adds three inputs for the Ni allocator join, described in
`docs/ni-allocator.md`: the base allocator table at `0x010a24d0` and its
`vtables.h` declaration, and the generated definitions of `DAT_011f6080` and
`DAT_011f6118`. Native source now owns all three.

Native CMake verifies the fifteen committed input hashes, copies them into the
build directory, and applies that patch using the existing Git patch engine.
It fails closed if any input changes or the patch no longer applies. Git is
therefore required at configure time, including builds from source archives.
No original executable, game data, extractor or proprietary input is needed.

The composed include directory precedes the legacy source directory. Each of
the four affected complete data TUs replaces its original target entry at
the same position; every other definition in those TUs and every unrelated
unit is retained. Their build object paths change, so archive verification
must record that explicit four-TU mapping, verify all physical payloads and
relative logical-member order, and must not claim literal old member names
are unchanged. Actual definitions/initializer bytes and complete production
links remain required; a successful patch application alone is not proof.

Changing these retirements requires reviewing the source owners and all real
consumers, composing and inspecting the exact bytes, rebuilding affected
complete TUs, and independently reviewing the final source composition.
The historical generator is not recreated, relabelled or used by this seam.
Full executable/runtime/provenance/manual acceptance remains separate.
