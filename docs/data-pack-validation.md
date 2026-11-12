# Data pack original check and opening (VEGAS-52)

## Scope

`fileformat::CheckPackOriginal` in `src/fileformat/pack_validation.h` is
the step after the structural reader of `data-pack-structure.md`: it
decides whether a well-formed pack records a supported original release.
`fileformat::OpenPack` in `src/fileformat/pack_open.h` is the step a later
startup calls: it reads the file of a pack and checks it.
Both are game library code in `src/fileformat`, beside the reader and the
writer, because the pack decision record, ADR 0001, has setup and the
engine use the same validator. There is no engine loading code yet to put
them in.

They are a named intermediate stage, not the complete validator of ADR
0001. The names `ValidatePack` and `ValidatedPack` are kept for that
validator and the type only it makes, and neither is written. Nothing
calls these functions yet. The engine's `main` does not open a pack. A
pack that passes is not a complete pack and does not allow the engine to
start.

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
what is not checked because it is not decided:

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
pack came from. Each of the two is to be removed from the list by the
change that checks it.

## Rulings on the next stages

These were ruled for this stage:

- `OpenPack` is not called from the engine's `main` until both of these
  exist in the source: a supported-original set, version 1.4.0.525 with
  the SHA-256 of the supported release's complete `FalloutNV.exe`, adopted
  by the owner under the reviewed procedure; and the complete catalogue,
  its keys, entry versions, required entries and decoding. The set exists
  now, adopted on VEGAS-52 on 2026-11-12. The catalogue does not, so
  `main` still does not open a pack.
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
read permission case prints that it was not run.

On Windows the tests link the game archive. On other hosts the archive does
not build, so the tests compile the units themselves and link zlib; this
is the form that runs under AddressSanitizer and UndefinedBehaviorSanitizer.

The tests show these functions on synthetic packs only. They do not show
a real pack, a complete pack or startup.

## What remains

- The complete catalogue: its keys, entry versions, required entries and
  decoding. Until it exists `main` does not open a pack.
- Hashing in setup: setup computes the SHA-256 of the executable it reads
  and compares it with `SupportedOriginals()`, as `pe-file-reader.md`
  says. The SHA-256 code is a separate change; nothing hashes yet.

## Build

`pack_validation.cpp` and `pack_open.cpp` are appended to the `game`
archive as two more members, after the NiAnimationKey table owner and in
that order. Nothing in the archive calls them, so a link that loads
members on demand loads neither.
