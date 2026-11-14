# Data pack validation and opening (VEGAS-52)

## Scope

`fileformat::CheckPackOriginal` in `src/fileformat/pack_validation.h` is
the step after the structural reader of `data-pack-structure.md`: it
decides whether a well-formed pack records a supported original release.
`fileformat::ValidatePack`, in the same header, is the complete validator
of ADR 0001: it runs that check, then checks the pack against catalogue
version 4 of `src/fileformat/pack_catalogue.h` and decodes its entries.
`fileformat::OpenPack` in `src/fileformat/pack_open.h` reads the file of a
pack and checks its original; `fileformat::OpenAndValidatePack` beside it
is the step a later startup calls: it reads the file and validates it.
All are game library code in `src/fileformat`, beside the reader and the
writer, because the pack decision record, ADR 0001, has setup and the
engine use the same validator. The engine's stage that calls
`OpenAndValidatePack` is `fnv::startup::LoadDataPack`, described in
`data-pack-startup.md`.

`CheckPackOriginal` and `OpenPack` are a named intermediate stage: a pack
that passes them is not a complete pack and does not allow the engine to
start. Only `ValidatePack` makes a `ValidatedPack`. The engine's `main`
reaches `OpenAndValidatePack` through the stage of `data-pack-startup.md`;
nothing in the archive calls `OpenPack` or `CheckPackOriginal` directly.

## Checking the original

`CheckPackOriginal` takes the bytes of a file and no set. It checks them
against `SupportedOriginals()`, the one release the source owns, described
in `pe-file-reader.md`. Each release is an `OriginalIdentity`, the version
and SHA-256 that `IdentifyOriginal` of `pe-file-reader.md` returns.
`CheckPackOriginalAgainst` takes a set as well. It is for the tests of the
comparison only, and no file under `src/` calls it. Both use one
comparison, which runs in this order:

| Check | Error | Problem |
| --- | --- | --- |
| The bytes are a well-formed container | `PackStructureError` | each `PackStructureProblem` |
| A supported identity has the original version the header records | `UnsupportedOriginalError` | `Version` |
| One of those has the original SHA-256 the header records | `UnsupportedOriginalError` | `Digest` |

The container checks include the four revision and target fields and that
every payload lies inside the file, so an unsupported revision and an
entry out of bounds are refused before the original is compared. An empty
set given to `CheckPackOriginalAgainst` refuses every pack.

Only `CheckPackOriginal` and `CheckPackOriginalAgainst` construct an
`OriginalCheckedPack`. It can be moved, not copied, and no constructor,
conversion or flag makes one from a `PackStructure`. It gives:

- `Original()`, the supported identity the header matched;
- `Entries()`, the directory in order, keys and versions as stored;
- `EntryBytes(index)`, the payload of an entry, which throws
  `std::out_of_range` for an index past the last entry.

All three point into the pack, so none is offered on a temporary. A pack
that has been moved from still reports its original but has no entries.

## What it leaves unchecked

`OriginalCheckedPack::Unchecked()` lists, as `UncheckedPackRequirement`,
what `CheckPackOriginal` does not check. `ValidatePack` checks both:

- `Catalogue`: which keys exist, which version of each is supported and
  which entries a pack needs. No key is refused or required, so a pack of
  any entries passes. Keys are not required to be ASCII here: that is left
  to the catalogue.
- `EntryValues`: what an entry's bytes mean. No entry is decoded.

A third, `SourceOwnedOriginals`, was removed when the source took
ownership of the supported set and production code could no longer pass a
set of its own.

The comparison is of what the pack claims. Nothing here reads an
executable or computes a digest, and a match does not prove where the
pack came from. Both stay on the list: it describes what an
`OriginalCheckedPack` has not checked, and `ValidatePack` checks them.

## Validating against the catalogue

`ValidatePack` takes the bytes of a file only. The supported set and the
required entries are the source's, `SupportedOriginals()` and
`packCatalogue`; neither is a parameter. It runs `CheckPackOriginal` and
then these checks, in this order:

| Check | Error | Problem |
| --- | --- | --- |
| The checks of `CheckPackOriginal` | `PackStructureError`, `UnsupportedOriginalError` | as above |
| Each catalogue entry, in turn, has an entry of its key in the pack | `PackCatalogueError` | `MissingEntry` |
| Each entry of the pack, in turn, has a key of the catalogue | `PackCatalogueError` | `UnknownKey` |
| ... with the catalogue's version for that key | `PackCatalogueError` | `EntryVersion` |
| ... and the catalogue's size for that key | `PackCatalogueError` | `EntrySize` |
| Each field, in turn, holds a zero byte: C1's four, then the four log path suffixes, then the ten save directory strings, then the class name | `PackCatalogueError` | `FieldTerminator` |
| ... and each log path suffix, right after its zero byte, holds no `\`, `/`, colon or byte below 0x20 and is not `..` | `PackCatalogueError` | `SuffixPath` |
| ... and the INI path format, right after its zero byte, holds exactly one `%s` and no other conversion | `PackCatalogueError` | `FormatConversion` |
| ... and each of the four save directory folders, right after its zero byte, holds no colon or byte below 0x20 and has no `..` part | `PackCatalogueError` | `FolderPath` |

The catalogue version is checked by the structural reader, which accepts
only the catalogue's `packCatalogueVersion`, now 4, so a pack of another
catalogue version, a pack of version 1, 2 or 3 among them, fails with
`PackStructureError` and `CatalogueVersion`. `PackCatalogueError` is a
`FormatError`. Its message names the entry and, for a field, the field;
an unknown key is not printed, since it may hold any byte.

A missing entry is checked before the keys of the pack, not after them as
the boundary table of `data-pack-catalogue.md` lists. The container
requires at least one entry and unique keys, so when every key of a pack
was in catalogue version 1, which had one entry, the pack held that entry:
in the other order no pack could have failed with `MissingEntry`. Versions
2 to 4 keep the order, the catalogue's entries in key order.

Catalogue version 4 has four entries, C1, the log path suffixes, the save
directory strings and the main window class of `data-pack-catalogue.md`. C1 has the key `INST`,
version 1, 140 bytes, four fields of 20, 60, 8 and 52 bytes, end to end,
each holding a string of the single-instance and remote-session checks. The
log path suffixes have the key `LOGS`, version 1, 72 bytes, four fields of
16, 16, 24 and 16 bytes, each holding the suffix of one of `WinMain`'s
log-path builders. The save directory strings have the key `SDIR`, version
1, 368 bytes, ten fields of 8, 12, 8, 24, 256, 12, 12, 12, 4 and 20 bytes,
each holding a string that `BGSSaveLoadManager::GetSaveDirectory` reads.
The main window class has the key `WNDC`, version 1, 256 bytes, one field
holding the class name. The field capacities are those of
`SingleInstanceStrings`, `LogPathSuffixes`, `SaveDirectoryStrings` and
`MainWindowClass`, so each size is fixed by its declaration. The decoder
reads each field with `ByteReader`, copies it through its first zero byte
and fills the rest of the decoded field with zeros. A byte after the zero
byte is not copied and does not refuse the pack.

Since VEGAS-130 a log path suffix is also refused, as `SuffixPath`, when
it holds a path separator, `\` or `/`, a colon or a byte below 0x20, or is
`..`, the reasons checked in that order; the message names the field and
the reason, never the suffix (`data-pack-startup.md`, "Log path
rulings"). `fileformat.pack_catalogue` refuses 14 such suffixes in each
field, accepts 9 ordinary ones, among them `.`, `...` and a space, and
keeps every other byte value but zero.

The first save directory field, the INI path format, is passed to a
`vsnprintf` with one string argument, so `fileformat::HoldsOneStringConversion`
must accept it: each `%` is followed by `s`, exactly once in the field, or
by a second `%`, which writes a `%` and reads no argument. A `%` with a
flag, width, precision or length, any other conversion, `%n` among them, a
second `%s`, no `%s` and a `%` at the end are refused with
`FormatConversion`. The check reads the field through its zero byte only.

The four save directory folders, the local, documents, game and working
folders, hold path separators by nature, so the suffix rule does not apply
to them. Under the coordinator's ruling of 2026-11-14
`fileformat::FolderPathRefusal` refuses a folder, as `FolderPath`, that
holds a colon, which names a drive or a stream, or a byte below 0x20, or
has a `..` part, a part between separators or the ends that is `..`, the
reasons checked in that order. A separator, `\` or `/`, leading, inner or
last, is allowed. The message names the field and the reason, never the
folder. The other six fields are not folders and are not checked so.
Neither the format's text around its `%s` nor the three INI names is
checked as a path, though `GetSaveDirectory` builds the INI paths and the
default INI's copy from them, and the folder rule checks each folder alone,
not the joined path; a rule for these is open until S7 is composed.
Setup applies the same rule before it writes a pack (`setup.md`). The rule
waited on a private run: on 2026-11-14 setup built from `64fd87149`, the
commit that adds the rule to setup, ran once on the supported original and
ended with status 0, so the rule did not narrow. Only the status, the
status line and the pack's existence and size were recorded (`setup.md`,
"The save directory folder rule").

`ValidatedPack` keeps the decoded values only, not the file, its
directory or any entry's bytes. It offers `Original()`, the supported
identity the pack matched, `SingleInstance()`, C1's four strings,
`PathSuffixes()`, the four log path suffixes, `SaveDirectory()`, the ten
save directory strings, and `WindowClass()`, the class name; each is
refused on a temporary. It can be
moved, not copied; no constructor, conversion or flag makes one from bytes,
a `PackStructure`, an `OriginalCheckedPack` or decoded values, and a
moved-from pack keeps its values. The original is compared, not proved:
nothing reads an executable or computes a digest.

No entry holds a reference to other data, so there is no reference
for the validator to resolve. The original reaches the class name and the
two INI names through pointers; the pack holds the strings, never the
pointers (D10).

## Rulings on the next stages

These were ruled for this stage:

- `OpenPack` is not called from the engine's `main` until both of these
  exist in the source: a supported-original set, version 1.4.0.525 with
  the SHA-256 of the supported release's complete `FalloutNV.exe`, adopted
  by the owner under the reviewed procedure; and the complete catalogue,
  its keys, entry versions, required entries and decoding. The set exists
  now, adopted on VEGAS-52 on 2026-11-12, and so does the catalogue, now
  version 4.
  The pack stage joins `main` with C1's consumer, the next increment of
  `data-pack-catalogue.md`, through `OpenAndValidatePack`. It has now
  joined, with that consumer (`data-pack-startup.md`).
- No production function takes a supported set. `OpenPack`,
  `CheckPackOriginal` and `IdentifyOriginal` check against
  `SupportedOriginals()`. The forms that take a set,
  `CheckPackOriginalAgainst` and `IdentifyOriginalAgainst`, are for tests
  of the comparison only, and no file under `src/` calls them. A set is
  never an input to whatever constructs `ValidatedPack`: the complete
  validator takes no set parameter.
- Removing `SourceOwnedOriginals` from `Unchecked()` is correct, now that
  production code cannot pass a set.
- Keys that are not ASCII are left to the catalogue.

## Opening

`OpenPack` takes a path only. It opens the file, reads it to the end in
chunks of 1 MiB and passes the bytes to `CheckPackOriginal`. The size used
is the number of bytes read, not one taken before reading. On Windows it
opens the wide path, so a path outside the ANSI code page opens, and other
processes may read the file meanwhile but not write it.

| Check | Error | Problem |
| --- | --- | --- |
| There is a file at the path | `PackOpenError` | `Missing` |
| It can be opened for reading | `PackOpenError` | `Unreadable` |
| Its bytes can be read to the end | `PackOpenError` | `Unreadable` |
| Then `CheckPackOriginal` of its bytes | as above | as above |

`OpenAndValidatePack` reads the file in the same way, with the same
`PackOpenError` cases, and returns `ValidatePack` of its bytes. It too
takes a path only.

`Missing` is a failure to open with `ENOENT`, which is also what a missing
folder on the path gives. Any other failure to open, and any read error, is
`Unreadable`. On macOS a file without read permission fails to open, and a
folder at the path opens but fails to read; both are `Unreadable`.
`PackOpenError` is a `std::runtime_error`, not a `FormatError`, because no
bytes were read. An allocation failure throws the standard exceptions.

Only the file at the path is read. Where the path comes from is the
caller's. The supported set is the source's, `SupportedOriginals()`, and
is not a parameter.

## Tests

`tests/fileformat/pack_validation_test.cpp` writes its packs with
`WritePackStructure`. For the comparison it calls
`CheckPackOriginalAgainst` with made-up digests and sets of its own. It
checks the only, the second and the highest-versioned identity and reads
back every key, version and payload. It refuses an empty set, a version
that differs in each part, every changed digest byte and the digest of
another supported version, and expects a damaged container to be reported
before its original. With `CheckPackOriginal` it checks a pack that
records the version and digest of `tests/fileformat/supported_release.h`,
the supported release's identity spelled by the tests, and refuses each
changed byte of that digest, a made-up digest and a version that differs
in each part. Such a pack claims the release's identity: it is compared,
not proved. On packs from `CheckPackOriginal` it refuses an entry index
past the end and reads the payloads of a pack moved by construction and by
assignment, and the original and empty directory of each pack it was moved
from. It lists the unchecked requirements. It states at compile time that
an `OriginalCheckedPack` cannot be default constructed, built from a
`PackStructure` or copied, that a temporary offers none of `Original()`,
`Entries()` and `EntryBytes()`, and that `CheckPackOriginal` takes no set,
neither a span nor an array, while `CheckPackOriginalAgainst` does.

`tests/fileformat/pack_open_test.cpp` writes its packs into a folder of its
own under the temporary folder and removes it at the end. It opens a pack
of three entries, packs of one read chunk exactly, one byte more and more
than two chunks, and a pack with no other file beside it. It refuses a
missing file, a missing folder, a folder in place of the file, a file
without read permission and an empty file. It changes one field at a
time, storing a matching CRC-32 again, and expects each
`PackStructureProblem`. Its packs record the supported release's identity
of `supported_release.h`, and it refuses a pack that records another
version, a made-up digest or that digest with its last byte changed.
Where permissions do not stop the test reading a file, as on Windows, the
read permission case prints that it was not run. With
`OpenAndValidatePack` it validates the file of a complete pack and reads
back its four strings, its four suffixes, three of its save directory
strings and its class name, and refuses a
missing file, a folder, a pack of the next catalogue version, a made-up
digest and a pack without the catalogue's entries, each with its own error.

`tests/fileformat/pack_catalogue_test.cpp` spells catalogue version 4
itself, the four keys, versions and sizes and the 19 field capacities,
and states at compile time that the source's catalogue is the same. Its
packs are written by `WritePackStructure` and record the identity of
`supported_release.h`. `ValidatePack` accepts complete packs of made-up
strings, of the longest string each field holds, of empty strings and, in
two packs for C1, four for the suffixes and one, in the second INI name,
for the save directory strings, of every byte value but zero, and returns
those strings with zeros after them; bytes after a field's zero byte, a
`%n` after the format's among them, are not returned. It accepts the
formats `%s`, `<%s>`, `%%%s`, `%s%%`, `a%%b%s`, `%%%%%s` and `%s%%%%`, and
refuses 22 others with `FormatConversion`, among them none, `%n`, `%s%n`,
`%n%s`, `%s%s`, `%d`, `%5s`, `%.3s`, `%*s`, `%ls`, `%%s` and a `%` at the
end; conversions in another save directory field are not refused. In
each folder field it refuses, of 20 crafted folders, those that fit, with
`FolderPath` and the reason, and accepts, of 18 others, those that fit,
among them `\a`, `a\b`, `a\`, `/a/b/`, `.`, `...`, `..a` and the empty
folder; `FolderPathRefusal` gives each its reason; a colon and a `..` part
in another save directory field are not refused. It refuses a pack without `INST`, under five other
keys, with two and with `WNDC` or `LOGS` alone; a pack without `LOGS`, with
`INST` alone, with `INST` and `WNDC` and beside four other keys; a pack
without `SDIR`, with `INST`, `LOGS` and `WNDC` as catalogue version 3 was,
and beside four other keys; a pack without `WNDC` beside four other keys; an unknown key before, between,
after and just above each entry, the lowest key, and a key that is not
ASCII, which the test stores after writing; entry versions 0, 2,
0x80000001 and 0xFFFFFFFF of each entry; sizes 1, 139, 141 and 280 of C1,
1, 71, 73 and 144 of the suffixes, 1, 367, 369 and 736 of the save
directory strings and 1, 255, 257 and 512 of the class name; each field
with no zero byte, C1's, the suffixes' and the save directory strings' also
when the fields after it are all zeros; the catalogue versions next to the source's,
0 and 0xFFFFFFFF, storing a matching CRC-32 again, and packs of catalogue
version 1, 2 and 3 as setup prepared them, C1 alone, C1 with the class
name, and those with the suffixes; each changed version part and the first and last changed digest
byte. Each is refused with its own problem, and for an entry or a field the
message names it. It checks the order: the container before the original,
the original before the catalogue, a missing `INST` before a missing
`LOGS`, a missing `LOGS` before a missing `SDIR`, a missing `SDIR` before a
missing `WNDC`, a missing entry before an unknown key, each entry of the
pack in turn, the version before the size, the size before the fields and
the fields in order, C1's before the suffixes', the suffixes' before the
save directory strings', those before the class name, and the format's zero
byte before its conversions and its conversions before the next field, the
format's conversions before a folder's path, an earlier field's zero byte
before a folder's path, a folder's path before a later field's zero byte
and before a later folder's path, and within a folder a colon before a
control character before a `..` part. It reads the values of a pack moved by
construction and by assignment, and of the pack moved from. It states at
compile time that a `ValidatedPack` cannot be default constructed, copied or
built from bytes, a `PackStructure`, an `OriginalCheckedPack` or decoded
values; that `ValidatePack` takes bytes and no `PackStructure`,
`OriginalCheckedPack`, set or list of entries or keys; that a
`ValidatedPack` offers no `Entries()`, `EntryBytes()` or `bytes`; and that a
temporary offers none of `Original()`, `SingleInstance()`, `PathSuffixes()`,
`SaveDirectory()` and `WindowClass()`.

On Windows the tests link the game archive. On other hosts the archive does
not build, so the tests compile the units themselves and link zlib; this
is the form that runs under AddressSanitizer and UndefinedBehaviorSanitizer.

The tests show these functions on synthetic packs only. They do not show
a real pack, a pack that setup prepared or startup.

## What remains

- Nothing. Setup computes the SHA-256 of the executable it reads with the
  `mbedtls_sha256` target and compares it with `SupportedOriginals()`, and
  validates the pack it writes with `ValidatePack` (`setup.md`).

## Build

`pack_validation.cpp` and `pack_open.cpp` are appended to the `game`
archive as two more members, after the NiAnimationKey table owner and in
that order. `ValidatePack` and `OpenAndValidatePack` are in those two
members, and the catalogue is a header, `pack_catalogue.h`, with no unit.
The stage of `data-pack-startup.md` calls `OpenAndValidatePack`, so the
`FalloutNV` link loads both.
