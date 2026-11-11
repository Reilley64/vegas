# Data pack container structure (VEGAS-52)

## Scope

`fileformat::ParsePackStructure` in `src/fileformat/pack_structure.h` is the
structural stage of reading the data pack, the file `vegas-data.pack` that
setup prepares from a player's original release. It follows the container
that the pack decision record, ADR 0001, adopts. It is the first step of
VEGAS-52 and no more than that: nothing calls it yet, the engine does not
look for a pack at startup, and a pack that passes it is not a validated
pack.

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
| The catalogue version is 1 | `CatalogueVersion` |
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

The decision record leaves these undecided, so the reader passes the values
on and decides nothing about them:

- `originalVersion` and `originalSha256` are the original release the pack
  claims to come from. The set of supported identities is not decided.
- An entry's key and version are stored as read. Which keys exist, which
  version of each is supported and which entries are required belong to the
  catalogue, which is not decided. Keys are not required to be ASCII here,
  because an unknown key is the catalogue's to refuse.
- Payload bytes are exposed raw through `EntryBytes`. The span it returns
  points into the `PackStructure`, so it cannot be called on a temporary.

The complete validation the decision record names, and the validated pack
only it may construct, are not written. There is no flag, constructor or
conversion that turns a `PackStructure` into one.

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
single changed bit.

On Windows the test links the game archive. On other hosts the archive does
not build, so the test compiles `pack_structure.cpp` itself and links zlib;
this is the form that runs under AddressSanitizer and
UndefinedBehaviorSanitizer.

The zlib chunk loop runs once in every test, because a second pass needs a
file larger than 4 GB. An allocation failure is not provoked by a test.

## Build

`pack_structure.cpp` is appended to the `game` archive as one more member.
It has no caller in the archive, so a link that loads members on demand does
not load it.
