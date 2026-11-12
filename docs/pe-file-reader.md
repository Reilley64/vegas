# PE file reader and original identification (VEGAS-13)

## Scope

`fileformat::ParsePeFile` in `src/fileformat/pe_file.h` reads the headers,
the section table and the version resource of a 32-bit x86 Windows
executable. `fileformat::IdentifyOriginal` in
`src/fileformat/original_identity.h` compares what it read, and a SHA-256 of
the file, with the supported original releases. They are the next step
of VEGAS-13 after the data pack writer: setup will use them to identify the
original release before it prepares a pack. Nothing calls them yet.

The reader takes the whole file as bytes and returns a `PeFile` that owns
them. It reads every field with `ByteReader`, as an unsigned little-endian
integer at an offset from the Microsoft PE and COFF specification. No C++
object is laid over the file.

## What it returns

- The image base and the entry point, and which section holds the entry
  point.
- For each section, in table order: its name, its address and size in
  memory, its offset and size in the file, `storedBytes`, the lesser of the
  two sizes, which is how much of its memory the file supplies, and
  `zeroBytes`, the zero-initialised tail after them. `StoredBytes` gives
  the section's stored bytes as they are in the file. Nothing is
  decompressed or decrypted.
- `steamStub`, true when the entry point is in a section named `.bind`,
  where SteamStub places it. The reader never reads code, so a wrapped
  `.text` is not an error: the flag reports it, and its bytes are offered
  as stored like any others. The flag is a sign, not a proof.
- The file version and the product version from the `VS_FIXEDFILEINFO` of
  the version resource, each as major, minor, patch and build.

## What it checks

The checks up to the entry point run in the order listed. The five
section checks run in that order for each section in turn, so a problem in
an earlier section is reported before any problem in a later one. The
resource problems after the entry point are reported in the order the
resource is walked, not in the order of the table: the resource directory,
the type table, the name table, the language table, the data entry, the
data and the `VS_VERSIONINFO`. So a malformed type entry is reported before
an empty name table, and an ambiguous name before a malformed language
entry. Each check has its own `PeProblem`, and a failure throws a
`PeError`, which is a `FormatError`.

| Check | Problem |
| --- | --- |
| The bytes hold the 64-byte MS-DOS header | `DosHeaderTruncated` |
| The file starts with `MZ` | `DosMagic` |
| The PE signature and the 20-byte file header fit after their offset | `PeHeaderTruncated` |
| The signature is `PE` and two zero bytes | `PeSignature` |
| The machine is x86, 0x14C | `Machine` |
| There are from 1 to 96 sections | `SectionCount` |
| The optional header holds the 96 bytes of PE32 fields and fits in the file | `OptionalHeaderSize` |
| The optional header magic is PE32, 0x10B | `OptionalHeaderMagic` |
| The data directories fit in the optional header | `OptionalHeaderSize` |
| The section table fits in the file | `SectionTableTruncated` |
| A section's bytes in the file start and end inside the file | `SectionOutOfFile` |
| A section with bytes in the file has a virtual size above 0 | `SectionVirtualSize` |
| A section ends in memory at or before `SizeOfImage` | `SectionBeyondSizeOfImage` |
| A section starts in memory at or after the end of the one before | `SectionOrder` |
| No two sections have the same name | `DuplicateSectionName` |
| The entry point is inside a section's memory | `EntryPoint` |
| There is a resource directory with a resource of type 16 | `NoVersionResource` |
| The resource directory, its tables, entries and the data are stored in the file and nested as the specification says | `ResourceMalformed` |
| There is one version resource with one language | `VersionResourceAmbiguous` |
| The data is a `VS_VERSIONINFO` whose value is a `VS_FIXEDFILEINFO` | `VersionInfo` |

No size from the file is used before it is compared with what holds it,
and no sum of values from the file can wrap: an offset is compared with
the size of what holds it, and a size with the bytes after the offset. The
sections are allocated only after the section table is known to fit.

The PE specification does not define a virtual size of 0 for a section
with bytes in the file, and loaders and linkers are not shown to agree on
it, so the reader refuses it to fail closed. A section with neither is
empty and is accepted.

The 96-section limit is the one the specification states for the Windows
loader. It also bounds the comparison of each name with those before it.

A 64-bit executable is refused for its machine, and the message names x64.
Every executable this project builds is 64-bit, so this refuses the
windows-x64 replacement executable, and setup cannot read ours as an
original. An x86 machine with a PE32+ optional header is refused for its
magic.

The version resource is found by type 16 among the type table's ID entries.
Below it there must be exactly one name and one language; more is
`VersionResourceAmbiguous`, none is `NoVersionResource`. Directory offsets
count from the start of the resource directory, and every table, entry and
the data entry must lie inside it. The data is found by its address and
must lie in the stored bytes of one section, which need not be the resource
directory's. The `VS_VERSIONINFO` must be at least 92 bytes, its length no
more than the data, its value length 52, its type 0, its key
`VS_VERSION_INFO` and the `VS_FIXEDFILEINFO` signature 0xFEEF04BD. Its
children, such as the string tables, are not read.

## What it leaves unchecked

- The section alignment, the file alignment, `SizeOfHeaders`, the
  checksum, the time stamp and the section characteristics are not
  compared with anything. The characteristics are returned as stored.
- Sections may overlap in the file. Only their memory is ordered.
- The relocations, imports, exports and every data directory other than
  the resource directory are not read.
- Whether the data sections hold what the recipe expects, the known-string
  and recipe-target checks of VEGAS-13, is not checked here.

## Original identification

`IdentifyOriginal` takes a `PeFile` and a SHA-256 of the whole file, and no
set. It compares them with `SupportedOriginals()`, the set the source owns,
below, whose identities are each a file version and a digest: the two
values a data pack's header records as its original. It returns the
identity whose version is the file version and whose digest is the digest
given. Otherwise it throws an `UnsupportedOriginalError`, which is a
`std::runtime_error`, not a `FormatError`, because the bytes may be well
formed:

| Check | Problem |
| --- | --- |
| A supported identity has the file version | `Version` |
| One of those has the digest | `Digest` |

`IdentifyOriginalAgainst` takes a set as well. It is for the tests of the
comparison only, and no file under `src/` calls it. An empty set given to
it refuses every executable. The product version is not compared.

The data pack's header records the original as `original_version` and
`original_sha256`. This reader takes `original_version` to be the file
version from the `VS_FIXEDFILEINFO`, the version `IdentifyOriginal`
compares. The pack decision record, ADR 0001, fixes the version as
1.4.0.525, the original release of the glossary, but does not say whether
it is the file or the product version. How the SHA-256 is computed is not
decided: zlib has none, and a hashing dependency or an implementation of
our own needs a review first. So the caller computes the digest over
`PeFile::bytes`, and nothing here hashes.

## The supported original release

`SupportedOriginals()` in `src/fileformat/original_identity.h` is the set
of supported original releases, owned by the source. It holds exactly one:
`FalloutNV.exe` of the Steam release as Steam distributes it, file version
1.4.0.525, with the SHA-256 of the whole file. The owner adopted it on
VEGAS-52 on 2026-11-12. The source records only these identification
values, the file version and the digest, and in a comment the file's size
of 16,549,704 bytes and that decision. No other byte or value of the file
is written into the source.

`IdentifyOriginal`, and `CheckPackOriginal` and `OpenPack` of
`data-pack-validation.md`, take no set: each checks against this one. The
size is not compared: nothing reads it from a file.

## Rulings

These choices were reviewed and kept:

- At most 96 sections.
- Exactly one name and one language below the version resource type.
  Revisit only if the original release's executable has more.
- Two sections with the same name are refused, so that a later lookup by
  name is unambiguous.
- Refusing a 64-bit executable is an early structural guard against
  reading our replacement. The guarantee that setup reads only a supported
  original is the digest set.
- A section with bytes in the file and a virtual size of 0 is refused to
  fail closed, because the PE specification does not define it; one with
  neither is accepted.
- `supportedOriginalReleases` is accepted as the name of the array behind
  `SupportedOriginals()`.
- A check of the executable's size is optional. If one is added, it runs
  in setup before hashing, and it never replaces the digest.

## What remains

- Move `pe_file`, `original_identity` and the data pack writer into a
  setup target once there is one; they are game archive members until
  then.
- Setup must hash `PeFile::bytes`, the same buffer it parsed, in one
  operation, and compare the result with `SupportedOriginals()`. The
  SHA-256 code is a separate change. Passing a digest to
  `IdentifyOriginal`, as it is offered now, must not be setup's path,
  since nothing then ties the digest to the bytes read.
- Extraction, a later step, must refuse the stored bytes of executable or
  code sections and read only data.

## Tests

`tests/fileformat/pe_fixture.h` builds the executables the tests read, in
memory, while the test runs. It states every field offset itself from the
specification and does not share them with the reader. The files hold no
code and nothing from the original release: section bytes are a pattern
of the test's, and the digests are made up, except the supported
release's digest of `tests/fileformat/supported_release.h`. That header
spells the release's version and digest, the digest as text, so that the
tests do not share the source's bytes. A fixture that records them claims
the release's identity: it is compared, not proved. No executable is
committed.

`tests/fileformat/pe_file_test.cpp` reads a file with code, constants,
data with a zero-initialised tail and a version resource, and checks every
field it returns and that the stored bytes are the file's. It reads
sections with no bytes in the file, with neither bytes in the file nor
size in memory, and with more bytes in the file than in memory; versions
at their limits; a version resource between a named and other type
entries, and with its data in another section; a resource directory that
ends with its data entry; 96 sections; a section that ends at
`SizeOfImage` or starts where the one before ends; the entry point in the
zero-initialised tail of `.data`; and the entry point in `.bind`, at its
first and last byte, and beside it. It refuses every prefix of a valid
file, the x64 replacement's machine with its message, and each problem
above, with values just past several bounds and sums that would wrap 2^32,
a section that overlaps the one before but not the first, a name repeated
two sections later, a type table whose named entries do not fit, and a
resource directory that ends one byte before the end of its data entry.
When a file has several problems it expects the one met first, in the
stated order up to the entry point and in walk order in the resource.

`tests/fileformat/original_identity_test.cpp` tests the comparison with
`IdentifyOriginalAgainst`: it identifies the only, the second and the
highest-versioned identity, and refuses an empty set, a version that
differs in each part, a match of the product version only, every changed
digest byte and the digest of another supported version. It checks that
`SupportedOriginals()` holds exactly the version and digest of
`supported_release.h`. With `IdentifyOriginal` it identifies a fixture of
that version that claims the digest, and refuses each changed byte of that
digest, a made-up digest and a version that differs in each part. It
states at compile time that `IdentifyOriginal` takes no set, neither a
span nor an array, while `IdentifyOriginalAgainst` does.

On Windows the tests link the game archive. On other hosts the archive does
not build, so the tests compile the units themselves; this is the form that
runs under AddressSanitizer and UndefinedBehaviorSanitizer.

## Build

`pe_file.cpp` and `original_identity.cpp` are appended to the `game`
archive as two more members, after the data pack writer and in that order.
Nothing in the archive calls them, so a link that loads members on demand
loads neither.
