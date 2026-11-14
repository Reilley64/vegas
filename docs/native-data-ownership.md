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
owner now defines that storage. It moves sole legacy definitions, unchanged in name, type, size and value, to
the module that now owns them. It does not replace required objects with stubs, rename
incompatible receivers or clone values. The genuine owner
modules and typed declarations remain the source of the native globals and
protocols. The patch covers forty hashed inputs. Twelve are the
retirements previously reviewed for VEGAS-1, unchanged, not additional engine
work. Four are the three retirements and the one move below. Sixteen are the
VEGAS-51 retirements below. Four are the VEGAS-102 label respellings below.
Two are the VEGAS-112 retirements below. One comes with the three VEGAS-127 moves below.
One is the VEGAS-129 retirement below. The VEGAS-130 retirement below adds
a hunk to an input that VEGAS-112 pinned, and no input.

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
now defines that storage once, described in `docs/animation-key-tables.md`,
and no unit refers to a retired name. Each of the 241 removed lines is one
definition without an initializer, so no value is lost or cloned. Every other
line of the sixteen inputs is unchanged. They are includes, not complete data
TUs, so the composed units stay four.

VEGAS-102 adds four staging includes: `staging/blk_00ba0000_o2.inc`,
`staging/blk_00c60000_o2.inc`, `staging/blk_00c80000_o2.inc` and
`staging/blk_00ca0000_o2.inc`. The body of `0x00cb9cb0` now takes the one
pointer it frees, so its windows-x64 name changes from
`?FUN_00cb9cb0@fnv_00cb9cb0@@YAXXZ` to
`?FUN_00cb9cb0@fnv_00cb9cb0@@YAXPEAX@Z`
(`docs/table-slot-reads.md`). Each of the four includes and
`vtables_010c.cpp`, already an input, declares the body through one asm
label of the old name. The patch rewrites those five label lines and no
other line of the five files. The four new hashes are those of the
committed bytes. The composed output differs from before in the five label
lines only, and the seven slots that hold the body keep their bytes. This
follows the earlier respellings of labels in `vtables_010c.cpp` after
signature changes, and the 2026-11-12 coordinator ruling.

VEGAS-112 adds `staging/blk_00c20000_od.inc`. It defined `DAT_01202b48`,
the destination of a WinMain log-path builder that writes up to 260
characters there, as one byte. `blk_00c20000_od.cpp`, the unit that includes it, then defined the buffer
(since VEGAS-127 `src/fallout/misc/log_paths.cpp` does) as an array of 260 characters
(`docs/data-pack-startup.md`). The patch removes the one line of the old
definition, which had no initializer, so no value is lost or cloned. Every
other line of the input is unchanged. Its pin is the hash of the committed bytes,
which do not change.

VEGAS-112 also adds `fallout/misc/main.inc`. It defined `DAT_01202e98`,
the buffer into which `BGSSaveLoadManager::GetSaveDirectory` copies a folder
of up to 260 characters, as a 4-byte `int`. `main.cpp`, the unit that
includes it, defined the buffer as an array of 260 characters; since
VEGAS-128 `fallout/misc/app_data_folder.cpp` defines it
(`docs/data-pack-startup.md`). The patch removes the one line of the old
definition, which had no initializer, so no value is lost or cloned. Every
other line of the input is unchanged. Its pin is the hash of the committed
bytes, which do not change.

VEGAS-130 retires four more lines of `fallout/misc/main.inc`:
`UNK_01082a00`, `UNK_01082a10`, `UNK_01082a28` and `UNK_01082a38`, each one
`unsigned char` with an initializer. The recipe binds the four addresses to
the strings that `WinMain`'s log-path builders append, of 16, 16, 24 and 16
bytes (`data-pack-catalogue.md`), so each definition held one byte of its
string: an incompatible byte-layout declaration of it. `FUN_0086a850` in
`main.cpp`, the one unit that named them, now passes the fields of the log
path suffixes' owner, which the data pack fills (`data-pack-startup.md`),
and no object of the build defines or refers to the four names any more.
The patch removes the four lines in a hunk of their own, before the hunk of
`DAT_01202e98`. Each line's one byte is dropped, not moved or cloned: the
owner holds the whole string, from the pack. Every other line of the input
is unchanged. The input was already pinned, with `eol=lf`, so its pin, the
count of forty inputs and `.gitattributes` do not change. The recipe keeps
the four keys in `main.cpp`'s entry, and setup still reads the strings at
their addresses under them (`src/setup/log_path_suffix_ranges.h`).

VEGAS-127 moves WinMain's four log-path builders, the functions that return
three of their buffers, and the buffers into a unit of their own,
`src/fallout/misc/log_paths.cpp` (`docs/data-pack-startup.md`). That unit
now defines `DAT_01202938`, `DAT_01202a40` and `DAT_01202c50`, each an
array of 260 characters as before. These are moves of VEGAS-57's kind: name, type, size and the zero initial
value are unchanged, and every user still resolves each by its name. The
patch removes their generated definitions, which had no initializer, so no
value is lost or cloned: the
lines of the first two from `staging/blk_00c20000_od.inc`, in the same hunk
as `DAT_01202b48`'s, and the line of the third from
`fallout_shared/tesfile.inc`, which becomes an input. Every other line of
both inputs is unchanged. The new pin is the hash of the committed bytes,
which do not change.

VEGAS-129 adds `bsaudio/bsaudio.inc`. It defined `DAT_01202800`, the
`int` that the setting value accessor `FUN_0043d4d0` sets to zero and
returns for a null setting (`docs/setting-value-offset.md`). The accessor
and that `int` now live in a unit of their own,
`src/fallout_shared/setting_value_accessor.cpp`, which defines it with the
same name and type. The patch removes the one line of the old definition,
which had no initializer, so no value is lost or cloned. `bsaudio.cpp`,
the unit that includes the input, still names the `int` in its source, now
the new unit's; its object refers to it only with `/Od /Gy`. Every other
line of the input is unchanged. Its pin is the hash of the committed bytes,
which do not change.

Native CMake verifies the forty committed input hashes, copies them into
the build directory, and applies that patch using the existing Git patch
engine.
It fails closed if any input changes or the patch no longer applies. Git is
therefore required at configure time, including builds from source archives.
No original executable, game data, extractor or proprietary input is needed.
A new pin needs its own `text eol=lf` line in `.gitattributes`: when the
source root is the top of a Git work tree, the configure stops when a pinned
input or the patch has neither `eol=lf` nor `-text`, since a Windows checkout
would change its bytes.

The composed include directory precedes the legacy source directory. Each of
the four affected complete data TUs replaces its original target entry at
the same position; every other definition in those TUs and every unrelated
unit is retained. Their build object paths change, so archive verification
must record that explicit four-TU mapping, verify all physical payloads and
relative logical-member order, and must not claim literal old member names
are unchanged. Actual definitions/initializer bytes and complete production
links remain required; a successful patch application alone is not proof.

VEGAS-30 compiles the fifteen generated vtable units with `/Gw` in builds
whose compiler takes the MSVC command line, so that each of their tables
gets a COMDAT data section of its own and a link keeps only the tables
something refers to. It is a compile option set in `CMakeLists.txt`: no
generated file changes, and the composed units are compiled from their
composed copies as before. The table bytes and relocations are unchanged.
`vtables_010c.cpp` took the option last, once the read past the end of its
table `DAT_010c4db8` was repaired (`docs/table-slot-reads.md`).

Changing these retirements requires reviewing the source owners and all real
consumers, composing and inspecting the exact bytes, rebuilding affected
complete TUs, and independently reviewing the final source composition.
The historical generator is not recreated, relabelled or used by this seam.
Full executable/runtime/provenance/manual acceptance remains separate.
