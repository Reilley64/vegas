# Data pack container structure (VEGAS-52, VEGAS-13)

## Scope

`fileformat::ParsePackStructure` in `src/fileformat/pack_structure.h` is the
structural stage of reading the data pack, the file `vegas-data.pack` that
setup prepares from a player's original release. It follows the container
that the pack decision record, ADR 0001, adopts. It is the first step of
VEGAS-52 and no more than that: `CheckPackOriginal` of
`data-pack-validation.md` calls it, the engine's `main` reaches it through
the stage of `data-pack-startup.md`, and a pack that passes it is not a
validated pack.

The reader takes the whole file as bytes and returns a `PackStructure` that
owns them, with the directory as offsets into them. It reads every field
with `ByteReader`, as an unsigned little-endian integer at a stated offset.
No C++ object is laid over the file.

## What it checks

The header checks, `HeaderTruncated` to `Checksum`, run in the order listed.
Then the four directory checks, `KeyOrder` to `EmptyPayload`, run in that
order for each record in turn, so a problem in an earlier record is reported
before any problem in a later record. `TrailingBytes` is checked last. Each
check has its own `PackStructureProblem`, and a failure throws a
`PackStructureError`, which is a `FormatError`.

| Check | Problem |
| --- | --- |
| The bytes hold the 88-byte header | `HeaderTruncated` |
| The first 8 bytes are `VEGASPK` and a zero byte | `Magic` |
| The envelope version is 1 | `EnvelopeVersion` |
| The catalogue version is the source catalogue's, `packCatalogueVersion` | `CatalogueVersion` |
| The native data contract is 1 | `NativeDataContract` |
| The build target is 1, windows-x64 | `BuildTarget` |
| `file_bytes` is the number of bytes given | `FileBytes` |
| `directory_bytes` is no more than follows the header | `DirectoryBytes` |
| `directory_bytes` is `entry_count` records of 24 bytes | `EntryCount` |
| There is at least one entry | `NoEntries` |
| The stored CRC-32 is that of bytes 0 to 83 followed by 88 to the end | `Checksum` |
| Each key is greater, compared as bytes, than the key before it | `KeyOrder` |
| Each payload starts and ends inside the file | `PayloadOutOfBounds` |
| Each payload starts where the directory or the payload before it ends | `PayloadPlacement` |
| No payload is empty | `EmptyPayload` |
| The last payload ends at the end of the file | `TrailingBytes` |

Ascending keys make them unique. Payloads placed end to end leave no hole and
no overlap, so the container has no alignment or padding to check.

No size from the file is used before it is compared with the number of bytes
given, and no comparison adds two values from the file. The directory size is
compared with the bytes after the header, the entry count with the quotient
of the directory size, and a payload size with the bytes after its offset.
The entries are allocated only after the count is known to fit in the file.
The CRC-32 is zlib's, fed in chunks no larger than zlib's length type holds.

## What it leaves unchecked

The reader passes these values on and decides nothing about them:

- `originalVersion` and `originalSha256` are the original release the pack
  claims to come from. The reader does not compare them with the supported
  set the source owns; `CheckPackOriginal` of `data-pack-validation.md`
  does.
- An entry's key and version are stored as read. Which keys exist, which
  version of each is supported and which entries are required belong to the
  catalogue, which `ValidatePack` of `data-pack-validation.md` checks. Keys
  are not required to be ASCII here, because an unknown key is the
  catalogue's to refuse.
- Payload bytes are exposed raw through `EntryBytes`. The span it returns
  points into the `PackStructure`, so it cannot be called on a temporary.

The check of the original is described in `data-pack-validation.md`.
There is no flag, constructor or conversion that turns a `PackStructure`
into an `OriginalCheckedPack` or a `ValidatedPack`: only
`CheckPackOriginal` and `CheckPackOriginalAgainst` make an
`OriginalCheckedPack`, and only the complete validator, `ValidatePack`,
makes a `ValidatedPack`.

## Writer

`fileformat::WritePackStructure` in `src/fileformat/pack_writer.h` is the
writer of the same container, the first step of VEGAS-13. It takes the
entries in order, each a key, a version and a payload, with the original
version and SHA-256 for the header, and returns the bytes of the file. It
is game library code, so setup can use the writer, and setup and the
engine the same reader. Setup calls it with the entry it prepared from an
original release (`setup.md`). Tests call it too, among them the fixture
that writes the pack for the `falloutnv.process_exit` test.

The envelope version, the native data contract and the build target are
written as 1, and the catalogue version as `packCatalogueVersion`. The
directory follows the header and the payloads follow the directory, end to
end in directory order. The file size and then the CRC-32 are stored last.

The reader and the writer take the magic, the header and record sizes, the
CRC-32 field offset, the revision value and the CRC-32 routine from one
internal header and unit, `src/fileformat/pack_container.h`. Nothing else
includes it. The revision value, 1, is that of the envelope version, the
native data contract and the build target. The catalogue version is not
the revision value: the writer writes `packCatalogueVersion` of
`src/fileformat/pack_catalogue.h`, and the reader accepts only that value
and names it when it refuses another. Under ADR 0001 as amended on
2026-11-13, any change to the required entries raises it by one.

The writer refuses entries whose pack the reader would refuse, and keys
that the decision record does not allow; the reader's other rules hold by
construction. TooManyEntries and NoEntries are checked first. Then
the three key and payload checks run in the order listed for each entry in
turn, so a problem in an earlier entry is reported before any problem in a
later entry. Each check has its own `PackWriteProblem`, and a failure
throws a `PackWriteError`, which is a `std::invalid_argument`. An
allocation failure throws `std::bad_alloc` or `std::length_error` instead.

| Check | Problem |
| --- | --- |
| There are no more entries than the 32-bit entry count holds | `TooManyEntries` |
| There is at least one entry | `NoEntries` |
| Each key byte is ASCII, 0x00 to 0x7F | `KeyNotAscii` |
| Each key is greater, compared as unsigned bytes, than the key before it | `KeyOrder` |
| No payload is empty | `EmptyPayload` |

The decision record leaves these undecided, so the writer writes them as
given and decides nothing about them:

- The original version and SHA-256. The writer does not compute a digest
  and does not compare one with a supported set.
- Which keys exist, which version of each is supported and which entries a
  pack needs. A pack the writer returns is a well-formed container, not a
  complete or valid pack.
- The order of the entries. The writer does not sort them; out of order is
  refused.

These choices were ruled on in review:

- Keys may hold any byte from 0x00 to 0x7F, as the decision record allows.
  Allowing printable bytes only would be stricter than the record, with no
  basis for it.
- `PackWriteError` is a `std::invalid_argument`, not a `FormatError`: the
  caller broke a precondition, and no bytes were malformed.
- The `TooManyEntries` check stays, although no test reaches it. No mutant
  changes it, so the mutation score does not cover it.
- `pack_container.h` has no constant for the offset 64 of the file size.
  The writer stores the file size where it wrote the field, and the reader
  reads the header in order.

## Tests

`tests/fileformat/pack_structure_test.cpp` builds every pack it reads with
`ByteWriter`. It states the field offsets itself and computes the CRC-32 one
bit at a time, so it does not compare the reader with its own constants or
zlib with zlib. It reads a pack of one entry and a pack of three, then
changes one thing at a time, stores a matching CRC-32 again and expects the
one problem that change causes. The values include sizes and offsets near
2^32 and 2^64 whose sums wrap. One pack passes every check but the payload
size bound: its first payload size wraps the end to 0, where a second payload
spans the whole file. One passes every check but the comparison of a key with
the one before it: its third key lies between the first and the second. The
test also expects a rejection for every prefix of a valid pack and for every
single changed bit. Its packs carry the source's catalogue version, and it
refuses 0, the versions next to the source's and versions that differ from
it in a higher byte only.

On Windows the test links the game archive. On other hosts the archive does
not build, so the test compiles `pack_structure.cpp` and `pack_container.cpp`
itself and links zlib; this is the form that runs under AddressSanitizer and
UndefinedBehaviorSanitizer.

`tests/fileformat/pack_writer_test.cpp` writes packs of one, three and five
entries, keys of the lowest and highest ASCII bytes and a 16 MiB payload,
reads each back with `ParsePackStructure` and expects what was written. It
checks every stored CRC-32 with its own bit-by-bit CRC-32. It spells out a
minimal pack of 113 bytes byte by byte, catalogue version 3 included: the
reader must accept it and the writer must reproduce it exactly, so a
mistake shared by the two through `pack_container.h` still fails. It expects
each refusal with its problem and the problem reported first when entries
have several. It does not include `pack_container.h` and is built the same
way as the reader's test.

The zlib chunk loop runs once in every test, because a second pass needs a
file larger than 4 GB. `TooManyEntries` is not reached by a test, because
it needs more than 2^32 - 1 entries. An allocation failure is not provoked
by a test.

## Build

`pack_structure.cpp`, `pack_container.cpp` and `pack_writer.cpp` are
appended to the `game` archive as three more members, in that order. Only
the reader and the writer call `pack_container.cpp`, and only the
check of `data-pack-validation.md` calls the reader. Nothing in the
archive calls the writer. The `FalloutNV` link reaches the reader through
the stage of `data-pack-startup.md`, so it loads `pack_structure.cpp` and
`pack_container.cpp`, not `pack_writer.cpp`.
