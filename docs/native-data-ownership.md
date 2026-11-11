# Native data ownership composition

The historical files under `src/generated/data/` are committed legacy inputs,
not the native source of truth. Do not edit them, except for the
respellings described below, or run an extractor against the original game to
build the native reconstruction.

One mechanical edit of these files is permitted by coordinator ruling for
VEGAS-11. The VEGAS-11 class-key script, which is kept outside the repository,
may respell mangled names inside `src/generated/data/` so that they follow a
type's single `struct` or `class` key: in quoted asm labels, in
`/alternatename` directives, and in comments that repeat a respelled symbol.
Three conditions hold together. The retirement patch stays byte-unchanged and
still applies. A pinned hash is recomputed only for a file the script changed,
after every existing pin has been checked against the bytes before the
rewrite. The diff of the composed output is recorded and consists of key-only
respellings. When a script kept outside the repository respells mangled names
in pinned composition inputs, that diff of the composed output is kept with
the review evidence of the change, not in the repository.

A second ruling for VEGAS-17 (R1 of the Tile work, `docs/shared-tile.md`)
permits a script kept outside the repository to respell a generated virtual
table's label so that it names a real class's virtual member. Only the class
name changes, and the member's access code changes from non-virtual to
virtual (`Q` to `U`); the member name and parameters stay. The slot is read
from the generated table itself and must be that member's slot in the real
class. The respelled file must not be a pinned composition input, so no pin
is recomputed and the retirement patch is untouched. No other edit of the
generated files is permitted.

`src/runtime/native_data_retirements.patch` is the narrowly audited native
ownership delta. It retires duplicate scalar storage and incompatible,
source-audited unused byte-layout tables/declarations. It retires sole,
zero-initialized definitions that nothing refers to any more because a typed
owner now defines that storage. It moves one sole legacy definition to its
owner module. It does not replace required objects with stubs, rename
incompatible receivers or clone values. The genuine owner
modules and typed declarations remain the source of the native globals and
protocols. The patch covers thirty-two hashed inputs. Twelve are the
retirements previously reviewed for VEGAS-1, unchanged, not additional engine
work. Four are the three retirements and the one move below. Sixteen are the
VEGAS-51 retirements below.

VEGAS-86 adds three for the Ni allocator join, described in
`docs/ni-allocator.md`: the base allocator table at `0x010a24d0` and its
`vtables.h` declaration, and the generated definitions of `DAT_011f6080` and
`DAT_011f6118`. Native source now owns all three.

VEGAS-57 adds that move: the `NiRefObject::ms_lObjectCount` definition in
`bshavok/bhkrigidbody_h_unit.inc`. It was the only definition of the count, not
a duplicate. The zero-initialized 32-bit count is now defined once by
`nirefobject_lifetime.cpp`, beside the constructor's and destructor's use of
it, so the object lifetime has one closed owner that host and Windows tests
link unchanged. The symbol name, type, size and initial value are the same;
every consumer, including the legacy `DAT_011f4400` alternate names, still
resolves it by that name. No other line of that input changes.

VEGAS-51 adds sixteen generated includes: the fourteen `nianimation` key and
key data includes, `niparticle/nipsysemitterctlrdata.inc` and
`generated/crt_callback_status_o2_variant.inc`. Together they defined the 241
names inside NiAnimationKey's key sizes and function tables, recipe addresses
`0x011f3758` to `0x011f3e3f`, each as its own variable. `NiAnimationKeyTables`
now defines that storage once, and no unit refers to a retired name. Each of
the 241 removed lines is one definition without an initializer, so no value is
lost or cloned. Every other line of the sixteen inputs is unchanged. They are
includes, not complete data TUs, so the composed units stay four.

Native CMake verifies the thirty-two committed input hashes, copies them into
the build directory, and applies that patch using the existing Git patch
engine.
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
