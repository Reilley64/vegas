# Setup (VEGAS-13)

## Scope

Setup prepares the data pack, `vegas-data.pack`, from a player's own copy of
the original release and installs it in the install folder, beside
`FalloutNV.exe`. The engine reads it there at startup
(`data-pack-startup.md`). This page describes setup for catalogue version 1,
which has one entry, C1, the single-instance strings
(`data-pack-catalogue.md`). Setup does not replace `FalloutNV.exe` yet.

Setup follows the pack decision record, ADR 0001, and the rulings D-1 to D-5
of VEGAS-52 and VEGAS-13 of 2026-11-12.

## Status

VEGAS-13's first criterion asks for provenance, licence and permission,
the reviewed tool version and the maintenance responsibility before setup
reads a real input. The next section states them. That criterion is met
when this page passes review.

The owner ran setup privately on an actual input on 2026-11-13, with the
reviewed tool version `0ecb31723`. For C1 only, that run shows the input
checks of VEGAS-13's first criterion, the reproducible local preparation
that its fourth asks for, and the private actual-input check that its
seventh asks to document. The rest of the fourth, fifth and seventh
criteria covers the whole catalogue and is still open. "Private run on an
actual input" states what it showed, and "Not verified" states what it did
not cover.

## Before setup reads a real copy

**Provenance.** Setup reads only the player's own, lawfully obtained copy of
the supported original release, in the player's own install folder. Setup
uses the identity check to confirm that the copy is that release. The
executable's file version and the SHA-256 of the whole file must equal those
of the supported release (`src/fileformat/original_identity.h`). The SHA-256
also fixes the file's size, 16,549,704 bytes. If either differs, setup stops
with status 5 and writes nothing.

**Licence and permission.** Setup grants no rights to the original release
or to any of its data. The pack, and anything else setup reads from the
original release, stays private on the player's machine, in the install
folder. The repository never contains a pack, an original file or data read
from one, and no test needs them (see "Tests"). Before running setup, the
player confirms that the licence terms of their copy allow a private local
copy for their own use. This page is not legal clearance.

**Reviewed tool version.** A pack is only as trustworthy as the setup that
made it. Only a commit reachable from the reviewed integration branch is a
reviewed version. For such a commit,
`git merge-base --is-ancestor HEAD <remote>/<branch>` exits with status 0.
An unmerged branch is not reviewed. `vegas-setup` does not print the commit
you built it from, so record it yourself, privately, beside the pack. Build
from a checkout of a reviewed commit with no local changes
(`git status --porcelain` prints nothing). Keep the output of
`git rev-parse HEAD` in that checkout, the branch name and the date you made
the pack.

**Maintenance.** The ranges in `src/setup/single_instance_ranges.h` and the
recipe check, `tools/setup-recipe-ranges`, belong to setup and change with
it. Their authority is the recipe, `build/units.json`. A change that moves
or renames a `str_` name of `src/fallout/misc/main.cpp`, or binds a new
address inside one of the four fields, makes `setup.recipe_ranges` fail.
That change also updates the header and this page.

## Using setup

On a Windows host, set `STEAMWORKS_SDK` as `third_party/README.md`
describes. Then, from the root of the checkout, build the `vegas-setup`
target with the `windows-x64` preset:

```text
cmake --preset windows-x64
cmake --build --preset windows-x64 --target vegas-setup
```

The program is `out/build/windows-x64/vegas-setup.exe`. Run it with the
install folder as its only argument:

```text
vegas-setup "<install folder>"
```

Setup succeeded if its exit status is 0 and it printed the line below to
the standard error stream. To see the exit status, run
`echo %ERRORLEVEL%` in Command Prompt or `$LASTEXITCODE` in PowerShell.

```text
vegas-setup: vegas-data.pack was written beside FalloutNV.exe
```

Setup reads `FalloutNV.exe` in that folder and writes `vegas-data.pack`
beside it. While it runs, it writes nothing else there except its staged
file. It never writes, renames or deletes `FalloutNV.exe`. Running it again
replaces the pack with a newly prepared one. Setup replaces a pack only with
one that has passed validation.

Setup prints one line to the standard error stream that says how it ended.
Its exit status says the same:

| Status | Meaning |
| --- | --- |
| 0 | Setup wrote, installed and read back the pack. |
| 1 | The command line does not have exactly one argument. |
| 2 | There is no `FalloutNV.exe` in the folder, or no such folder. |
| 3 | Setup cannot open or read `FalloutNV.exe`. |
| 4 | `FalloutNV.exe` is not a 32-bit x86 executable with a readable version resource. A 64-bit executable, such as the one this project builds, gets this status. |
| 5 | `FalloutNV.exe` is not a supported original release. Its file version or its SHA-256 differs. |
| 6 | Setup cannot read a string of C1 as it is stored (see "Checks"). |
| 7 | The validator refuses the pack that setup wrote. This is a defect in setup. |
| 8 | Setup cannot write the staged file. |
| 9 | Setup reads the staged file back, and the validator refuses it, or it does not hold the prepared values. |
| 10 | Setup cannot rename the staged file over `vegas-data.pack`. |
| 11 | Setup reads the installed pack back, and the validator refuses it, or it does not hold the prepared values. |

The supported original release is Fallout: New Vegas for PC, version
1.4.0.525, as Steam installs it (`pe-file-reader.md`). Setup reads the
player's own copy, in the player's own install folder, and nothing else. The
pack it writes holds data of the original release, so keep it in that
folder. Never commit it, attach it to an issue or publish it. `.gitignore`
ignores `*.pack` and `*.pack.staged`. `tools/hooks/public-check` refuses a
commit that adds a file matching either pattern in any folder and in any
letter case, even a file added with `git add -f`. It also refuses a commit
that replaces such a file with a symbolic link.

Setup does not catch an allocation failure. When memory runs out, the
program stops through `std::terminate` without printing a line. Its exit
status is then abnormal and is not one of the statuses above. The exact
value on Windows is not verified.

## What setup does

`setup::RunSetup` (`src/setup/run_setup.h`) is the command. The `main` of
`vegas-setup` only passes it the arguments. `RunSetup` takes these steps:

1. It reads the whole of `FalloutNV.exe` in the install folder.
2. It calls `setup::PrepareDataPack` (`src/setup/prepare_pack.h`), which
   takes only the bytes and:
   1. parses them with `fileformat::ParsePeFile`;
   2. computes the SHA-256 of the bytes it parsed, in one operation, with
      the `mbedtls_sha256` target;
   3. identifies the original with `fileformat::IdentifyOriginal`, against
      the source's supported set;
   4. reads C1's four strings (see "Checks");
   5. writes the pack with `fileformat::WritePackStructure`, using the
      identified original's version and SHA-256;
   6. checks the written bytes with `fileformat::ValidatePack`, the
      validator the engine uses.
3. It calls `setup::InstallDataPack` (`src/setup/install_pack.h`), which:
   1. writes the bytes to `vegas-data.pack.staged` in the install folder;
   2. reads it back with `fileformat::OpenAndValidatePack` and requires the
      values that step 2 prepared;
   3. renames it over `vegas-data.pack`;
   4. reads `vegas-data.pack` back the same way.

   When step 1, 2 or 3 fails, setup removes the staged file and leaves an
   existing pack as it was. When step 4 fails, the new pack stays installed
   and setup ends with status 11. The engine's validator still checks it at
   every start.

Setup decrypts nothing. It neither decrypts nor bypasses SteamStub, and it
refuses a string in `.bind`. It reads C1's strings only from the stored
bytes of data sections.

## Checks

Setup reads each string of C1 at a range the recipe gives.
`src/setup/single_instance_ranges.h` holds the ranges as data. For each of
C1's four fields, it holds the `str_` name the recipe binds for
`src/fallout/misc/main.cpp`, the original address and the recipe bound,
with the recipe entries of `main.cpp` merged. The
header holds no byte of the original release.

| Field | Recipe name | Address | Capacity |
| --- | --- | --- | --- |
| mutex name | `str_01082ab8` | `0x01082ab8` | 20 |
| first message text | `str_01082a7c` | `0x01082a7c` | 60 |
| message caption | `str_0104df38` | `0x0104df38` | 8 |
| second message text | `str_01082a48` | `0x01082a48` | 52 |

**Recipe target.** The CTest `setup.recipe_ranges`
(`tools/setup-recipe-ranges`) fails when a row no longer matches
`build/units.json`. That happens when the recipe does not bind the name at
the address for `main.cpp`, or when the capacity is not the distance to the
next address the recipe binds. `static_assert`s in the header require each
capacity to be the size of C1's field.

Setup checks the fields in catalogue order. For each field it tests the
problems below in this order, and refuses with the first
`setup::ExtractError` that applies:

| Problem | When |
| --- | --- |
| `NoSection` | no section holds the address less the image base the header records, or the address is below it |
| `SteamStubSection` | the section is `.bind` |
| `CodeSection` | the section is marked as code or as executable |
| `NotInitializedData` | the section is not marked as initialized data |
| `ZeroTail` | the field's bytes run past the section's stored bytes, into its zero-initialized tail or past its end |
| `NoTerminator` | no zero byte within the capacity |
| `KnownString` | the string is not the text of the recipe literal at its address |

**Known string.** Every string must end within its capacity. The recipe also
binds the caption's address as the compiler literal
`??_C@_05NAOIJFC@Error?$AA@`. That name spells a 6-byte `Error` and its zero
byte, so the caption must be exactly that. The recipe names no literal at
the other three addresses, so nothing more is known of them.

Setup copies each string through its first zero byte and fills the rest of
its field with zeros. It never copies a byte past that zero byte.

## Build

`vegas_setup` is a static library of the setup units and of the PE reader and
data pack units it uses: `pe_file`, `original_identity`, `pack_writer`,
`pack_structure`, `pack_container`, `pack_validation` and `pack_open`. It
compiles them itself from the same sources and links zlib and
`mbedtls_sha256`. The game archive's members are unchanged. Setup and the
game never link together. `vegas-setup` is `src/setup/setup_main.cpp`
linked with the library. On Windows it takes the folder as a wide string, so
a path outside the ANSI code page works.

On a Windows host, building setup does not need Python. Only the
`setup.recipe_ranges` test needs it. A configure without Python 3 warns, and
that test then fails and says why. A cross build from another host also
needs a clang-cl toolchain file, and its configure stops without Python 3
(`tests/CMakeLists.txt`).

**Distributing a binary.** `vegas-setup` contains Mbed TLS's SHA-256 code,
which this project uses under Apache-2.0 (`third_party/README.md`). Anyone
who gives a `vegas-setup` binary to others must give them a copy of the
Apache License 2.0 with it, as section 4 of that licence requires. One such
copy is the `LICENSE` file of the Mbed TLS release archive that the build
downloads.

## Tests

The tests build their executables in memory, as `tests/fileformat/pe_fixture.h`
does, and use temporary folders. No test reads, embeds or needs an original
file or a real pack. Every string is made up, except the caption `Error`,
which the recipe literal fixes.

- `setup.prepare_pack` covers the round trip, each refusal of "Checks" in
  order, copying through the zero byte, an unsupported executable and a
  64-bit one. A synthetic executable is never a supported original release.
  So the test runs the same code as steps 1 to 5 of `PrepareDataPack`, but
  with `IdentifyOriginalAgainst` and a set that holds the synthetic
  executable's own identity. It checks the written bytes with
  `CheckPackOriginalAgainst`. Then it writes the same entry with the
  supported release's identity, which is compared, not proved, and requires
  `ValidatePack` to accept it with the same strings. That form exists only
  in the test. No file under `src/` takes a set, and the production
  `PrepareDataPack` refuses the synthetic executable.
- `setup.install_pack` covers installation, replacement of an existing pack,
  a staged file that does not validate or holds other values, a staged name
  or pack name that a folder already uses, and statuses 1 to 5 of
  `RunSetup`, with the folder unchanged.
- `setup.recipe_ranges` runs the recipe check above.

## Private run on an actual input

On 2026-11-13 the owner ran `vegas-setup`, built from the reviewed tool
version `0ecb31723`, on their own Steam copy of `FalloutNV.exe`. The pack,
the original file and every value read from them stay private. This page
records outcomes and statuses only.

- The identity check accepted the copy as the supported original release.
- Setup ran on two separate copies of the executable. Each run ended with
  status 0, and the two packs were identical byte for byte.
- Setup ran again on a folder that already held a pack. It replaced the
  pack and ended with status 0. The new pack was identical to the first
  two.
- No run left a `vegas-data.pack.staged` file.
- A separate PE check, independent of setup's code, found all four strings
  of C1 in the stored bytes of one read-only initialized-data section. Each
  string's zero byte lies within its capacity.
- This project's `FalloutNV.exe`, built from the same commit, exited with
  status 0 beside the pack, with no original executable present. Exit
  status 0 alone does not tell which path `main` took
  (`data-pack-startup.md`).
- With no pack beside it, it exited with status 2 and reported the pack
  missing on the standard error stream.
- Beside a corrupted copy of the pack, it exited with status 2. On the
  standard error stream it reported that the pack is not a valid data pack
  because its CRC-32 is not that of the file.

These runs are private actual-input checks. They are not synthetic tests
and not full-game acceptance.

## Not verified

- The private run ran in session 0, where no user sees a message box, and
  showed none. Nobody has yet seen C1's strings in the message boxes of
  `main` (`data-pack-startup.md`). This page records no run of setup or of
  this project's `FalloutNV.exe` in a desktop session.
- No real input has triggered the refusal statuses 6 to 11 of `RunSetup`.
  The private run of setup ended only with status 0.
- No test reaches statuses 0 and 6 to 11 of `RunSetup`, because they need a
  supported original release. A test of `InstallDataPack` on its own covers
  statuses 8 to 10. Status 11 needs the installed file to change between the
  rename and the read back.
- Setup does not flush the staged file to the disk before the rename. After
  a power failure the pack may be missing or refused. The engine then
  reports it, and setup can run again.
- Apart from the private run, nobody has run a Windows executable of
  setup. The Windows build of `vegas-setup` and its tests compiles and
  links. Windows CI runs the test suite on every push, but at 91357ecf7,
  d8f06e7b0 and 0ecb31723 its configure step failed before any test ran,
  so no CI run of the setup tests is recorded here.
- Nobody has checked the exit status of an uncaught allocation failure on
  Windows.
