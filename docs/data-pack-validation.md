# Data pack validation and opening (VEGAS-52)

## Scope

`fileformat::CheckPackOriginal` in `src/fileformat/pack_validation.h` is
the step after the structural reader of `data-pack-structure.md`: it
decides whether a well-formed pack records a supported original release.
`fileformat::ValidatePack`, in the same header, is the complete validator
of ADR 0001: it runs that check, then checks the pack against catalogue
version 2 of `src/fileformat/pack_catalogue.h` and decodes its entries.
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
| Each field, in turn, holds a zero byte: C1's four, then the class name | `PackCatalogueError` | `FieldTerminator` |

The catalogue version is checked by the structural reader, which accepts
only the catalogue's `packCatalogueVersion`, now 2, so a pack of another
catalogue version, a pack of version 1 among them, fails with
`PackStructureError` and `CatalogueVersion`. `PackCatalogueError` is a
`FormatError`. Its message names the entry and, for a field, the field;
an unknown key is not printed, since it may hold any byte.

A missing entry is checked before the keys of the pack, not after them as
the boundary table of `data-pack-catalogue.md` lists. The container
requires at least one entry and unique keys, so when every key of a pack
was in catalogue version 1, which had one entry, the pack held that entry:
in the other order no pack could have failed with `MissingEntry`. Version 2
keeps the order, the catalogue's entries in key order.

Catalogue version 2 has two entries, C1 and the main window class of
`data-pack-catalogue.md`. C1 has the key `INST`, version 1, 140 bytes, four
fields of 20, 60, 8 and 52 bytes, end to end, each holding a string of the
single-instance and remote-session checks. The main window class has the
key `WNDC`, version 1, 256 bytes, one field holding the class name. The
field capacities are those of `SingleInstanceStrings` and
`MainWindowClass`, so each size is fixed by its declaration. The decoder
reads each field with `ByteReader`, copies it through its first zero byte
and fills the rest of the decoded field with zeros. A byte after the zero
byte is not copied and does not refuse the pack.

`ValidatedPack` keeps the decoded values only, not the file, its
directory or any entry's bytes. It offers `Original()`, the supported
identity the pack matched, `SingleInstance()`, C1's four strings, and
`WindowClass()`, the class name; each is refused on a temporary. It can be
moved, not copied; no constructor, conversion or flag makes one from bytes,
a `PackStructure`, an `OriginalCheckedPack` or decoded values, and a
moved-from pack keeps its values. The original is compared, not proved:
nothing reads an executable or computes a digest.

Neither entry holds a reference to other data, so there is no reference
for the validator to resolve. The original reaches the class name through
a pointer; the pack holds the string, never the pointer (D10).

## Rulings on the next stages

These were ruled for this stage:

- `OpenPack` is not called from the engine's `main` until both of these
  exist in the source: a supported-original set, version 1.4.0.525 with
  the SHA-256 of the supported release's complete `FalloutNV.exe`, adopted
  by the owner under the reviewed procedure; and the complete catalogue,
  its keys, entry versions, required entries and decoding. The set exists
  now, adopted on VEGAS-52 on 2026-11-12, and so does the catalogue, now
  version 2.
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
back its four strings and its class name, and refuses a missing file, a
folder, a pack of the next catalogue version, a made-up digest and a pack
without the catalogue's entries, each with its own error.

`tests/fileformat/pack_catalogue_test.cpp` spells catalogue version 2
itself, the two keys, versions and sizes and the five field capacities,
and states at compile time that the source's catalogue is the same. Its
packs are written by `WritePackStructure` and record the identity of
`supported_release.h`. `ValidatePack` accepts complete packs of made-up
strings, of the longest string each field holds, of empty strings and, in
two packs, of every byte value but zero, and returns those strings with
zeros after them; bytes after a field's zero byte are not returned. It
refuses a pack without `INST`, under five other keys, with two and with
`WNDC` alone; a pack without `WNDC`, with `INST` alone and beside four other
keys; an unknown key before, between, after and just above each entry, the
lowest key, and a key that is not ASCII, which the test stores after
writing; entry versions 0, 2, 0x80000001 and 0xFFFFFFFF of each entry;
sizes 1, 139, 141 and 280 of C1 and 1, 255, 257 and 512 of the class name;
each field with no zero byte, C1's also when the fields after it are all
zeros; catalogue versions 0, 1, 3 and 0xFFFFFFFF, storing a matching CRC-32
again, and a pack of catalogue version 1 as setup prepared it, C1 alone;
each changed version part and the first and last changed digest byte. Each
is refused with its own problem, and for an entry or a field the message
names it. It checks the order: the container before the original, the
original before the catalogue, a missing `INST` before a missing `WNDC`, a
missing entry before an unknown key, each entry of the pack in turn, the
version before the size, the size before the fields and the fields in
order, C1's before the class name. It reads the values of a pack moved by
construction and by assignment, and of the pack moved from. It states at
compile time that a `ValidatedPack` cannot be default constructed, copied or
built from bytes, a `PackStructure`, an `OriginalCheckedPack` or decoded
values; that `ValidatePack` takes bytes and no `PackStructure`,
`OriginalCheckedPack`, set or list of entries or keys; that a
`ValidatedPack` offers no `Entries()`, `EntryBytes()` or `bytes`; and that a
temporary offers none of `Original()`, `SingleInstance()` and
`WindowClass()`.

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
