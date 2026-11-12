# Setup (VEGAS-13)

## Scope

Setup prepares the data pack, `vegas-data.pack`, from a player's own copy of
the original release and installs it in the install folder, beside
`FalloutNV.exe`. The engine reads it there at startup
(`data-pack-startup.md`). This page describes setup for catalogue version 1,
whose one entry is C1, the single-instance strings
(`data-pack-catalogue.md`). Setup does not replace `FalloutNV.exe` yet.

It follows the pack decision record, ADR 0001, and the rulings D-1 to D-5 of
VEGAS-52 and VEGAS-13 of 2026-11-12.

## Status

VEGAS-13's first criterion asks for provenance, licence and permission,
the reviewed tool version and the maintenance responsibility before setup
reads a real input. The next section states them. That criterion is not met
until this page and its review are accepted. The private check of setup on
an actual input is still to be done; VEGAS-13's first, fourth, fifth and
seventh criteria wait for it.

## Before setup reads a real copy

**Provenance.** The only input is the player's own, lawfully obtained copy
of the supported original release, in the player's own install folder.
Setup establishes that it is that release with the identity check: the
executable's file version and the SHA-256 of the whole file, which also
fixes its size of 16,549,704 bytes, must be those of the supported release
(`src/fileformat/original_identity.h`), or setup stops with status 5 and
writes nothing.

**Licence and permission.** Setup grants no rights to the original release
or to any of its data. The pack, and anything else read from the original
release, stays private on the player's machine, in the install folder. The
repository never contains a pack, an original file or data read from one,
and no test needs them (see "Tests"). Before running setup, the player
confirms that the licence terms of their copy allow a private local copy
for their own use. This page is not legal clearance.

**Reviewed tool version.** A pack is only as trustworthy as the setup that
made it. Only a commit reachable from the reviewed integration branch is a
reviewed version: `git merge-base --is-ancestor HEAD <remote>/<branch>`
exits 0 for it; an unmerged branch is not reviewed. `vegas-setup` does not
print the commit it was built from. Note it yourself, privately, beside the
pack: build from such a checkout with no local changes
(`git status --porcelain` prints nothing), and keep the output of
`git rev-parse HEAD` of that checkout, the branch name and the date the
pack was made.

**Maintenance.** The ranges in `src/setup/single_instance_ranges.h` and the
recipe check, `tools/setup-recipe-ranges`, belong to setup and change with
it. The recipe, `build/units.json`, is their authority: a change that moves
or renames a `str_` name of `src/fallout/misc/main.cpp`, or binds a new
address inside one of the four fields, makes `setup.recipe_ranges` fail, and
that change also updates the header and this page.

## Using setup

On a Windows host, build the `vegas-setup` target with the `windows-x64`
preset, with `STEAMWORKS_SDK` set as `third_party/README.md` describes,
from the root of the checkout:

```text
cmake --preset windows-x64
cmake --build --preset windows-x64 --target vegas-setup
```

The program is `out/build/windows-x64/vegas-setup.exe`. Run it with the
install folder as its only argument:

```text
vegas-setup "<install folder>"
```

It succeeded when its exit status is 0 (`echo %ERRORLEVEL%` in Command
Prompt, `$LASTEXITCODE` in PowerShell) and it printed this line:

```text
vegas-setup: vegas-data.pack was written beside FalloutNV.exe
```

It reads `FalloutNV.exe` in that folder and writes `vegas-data.pack` beside
it. It writes nothing else there except its staged file while it runs. It
never writes, renames or deletes `FalloutNV.exe`. Running it again replaces
the pack with one prepared again. A pack is only ever replaced by one that
has passed validation.

It prints one line that says how it ended, and its exit status says the
same:

| Status | Meaning |
| --- | --- |
| 0 | The pack was written, installed and read back. |
| 1 | Not exactly one argument. |
| 2 | There is no `FalloutNV.exe` in the folder, or no such folder. |
| 3 | `FalloutNV.exe` cannot be opened or read. |
| 4 | `FalloutNV.exe` is not a 32-bit x86 executable whose version resource can be read. A 64-bit executable, such as the one this project builds, ends here. |
| 5 | `FalloutNV.exe` is not a supported original release: its file version or its SHA-256 differs. |
| 6 | A string of C1 cannot be read as stored (see "Checks"). |
| 7 | The pack setup wrote is refused by the validator. This is a defect of setup. |
| 8 | The staged file cannot be written. |
| 9 | The staged file, read back, is refused or does not hold the values prepared. |
| 10 | The staged file cannot be renamed over `vegas-data.pack`. |
| 11 | The installed pack, read back, is refused or does not hold the values prepared. |

The supported original release is Fallout: New Vegas for PC, version
1.4.0.525, as Steam installs it (`pe-file-reader.md`). Setup reads the
player's own copy, in the player's own install folder, and nothing else. The
pack it writes holds data of the original release: keep it in that folder.
Never commit it, attach it to an issue or publish it. `.gitignore` ignores
`*.pack` and `*.pack.staged`, and `tools/hooks/public-check` refuses a commit
that adds a file of either name in any folder, in any letter case, even one
added with `git add -f`, and one that replaces such a file with a symbolic
link.

When memory runs out, the allocation failure is not caught: the program
stops through `std::terminate` without printing a line, with an abnormal
exit status that is not one of the statuses above. The exact value on
Windows is not verified.

## What setup does

`setup::RunSetup` (`src/setup/run_setup.h`) is the command; `vegas-setup`'s
`main` only passes it the arguments.

1. Reads the whole of `FalloutNV.exe` in the install folder.
2. `setup::PrepareDataPack` (`src/setup/prepare_pack.h`), which takes the
   bytes only:
   1. `fileformat::ParsePeFile`.
   2. The SHA-256 of the bytes it parsed, in one operation, with the
      `mbedtls_sha256` target.
   3. `fileformat::IdentifyOriginal`, against the source's supported set.
   4. Reads C1's four strings (see "Checks").
   5. `fileformat::WritePackStructure`, with the identified original's version
      and SHA-256.
   6. `fileformat::ValidatePack` of the written bytes, the validator the
      engine uses.
3. `setup::InstallDataPack` (`src/setup/install_pack.h`):
   1. writes the bytes to `vegas-data.pack.staged` in the install folder;
   2. reads it back with `fileformat::OpenAndValidatePack` and requires the
      values that step 2 prepared;
   3. renames it over `vegas-data.pack`;
   4. reads `vegas-data.pack` back the same way.

   When step 1, 2 or 3 fails, the staged file is removed and an existing pack
   is left as it was. When step 4 fails, the new pack stays installed and
   setup ends with status 11; the engine's validator still checks it at every
   start.

Nothing is decrypted. SteamStub is neither decrypted nor bypassed: a string in
`.bind` is refused. Only the stored bytes of data sections are read.

## Checks

Setup reads each string of C1 at a range the recipe gives. The ranges are
written as data in `src/setup/single_instance_ranges.h`: the original address
and the recipe bound of each `str_` name of `src/fallout/misc/main.cpp`, its
recipe entries merged. No byte of the original release is written there.

| Field | Recipe name | Address | Capacity |
| --- | --- | --- | --- |
| mutex name | `str_01082ab8` | `0x01082ab8` | 20 |
| first message text | `str_01082a7c` | `0x01082a7c` | 60 |
| message caption | `str_0104df38` | `0x0104df38` | 8 |
| second message text | `str_01082a48` | `0x01082a48` | 52 |

**Recipe target.** The CTest `setup.recipe_ranges`
(`tools/setup-recipe-ranges`) fails when a row no longer matches
`build/units.json`: when the recipe does not bind the name at the address for
`main.cpp`, or when the capacity is not the distance to the next address the
recipe binds. `static_assert`s in the header require each capacity to be the
size of C1's field.

For each field in catalogue order, setup refuses with `setup::ExtractError`,
in this order:

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
`??_C@_05NAOIJFC@Error?$AA@`, whose name spells a 6-byte `Error` and its zero
byte, so the caption must be exactly that. The recipe names no literal at the
other three addresses, so nothing more is known of them.

Setup copies each string through its first zero byte and fills the rest of
its field with zeros. It never copies a byte past that zero byte.

## Build

`vegas_setup` is a static library of the setup units and of the PE reader and
data pack units it uses: `pe_file`, `original_identity`, `pack_writer`,
`pack_structure`, `pack_container`, `pack_validation` and `pack_open`. It
compiles them itself from the same sources and links zlib and
`mbedtls_sha256`. The game archive's members are unchanged; setup and the game
never link together. `vegas-setup` is `src/setup/setup_main.cpp` linked with
the library. On Windows it takes the folder as a wide string, so a path
outside the ANSI code page works.

On a Windows host, building setup does not need Python; only the
`setup.recipe_ranges` test does. A configure without Python 3 warns, and
that test then fails and says why. A cross build from another host also
needs a clang-cl toolchain file, and its configure stops without Python 3
(`tests/CMakeLists.txt`).

**Distributing a binary.** `vegas-setup` holds Mbed TLS's SHA-256 code, used
under Apache-2.0 (`third_party/README.md`). Whoever gives a `vegas-setup`
binary to others must give them a copy of the Apache License 2.0 with it, as
its section 4 requires, for example the `LICENSE` file of the Mbed TLS
release archive the build downloads.

## Tests

The tests build their executables in memory, as `tests/fileformat/pe_fixture.h`
does, and use temporary folders. No test reads, embeds or needs an original
file or a real pack. Every string is made up, except the caption `Error`,
which the recipe literal fixes.

- `setup.prepare_pack`: the round trip, each refusal of "Checks", in order,
  copying through the zero byte, an unsupported executable and a 64-bit one.
  A synthetic executable is never a supported original release, so the test
  runs steps 1 to 5 of `PrepareDataPack`, the same code, with
  `IdentifyOriginalAgainst` and a set holding the synthetic executable's own
  identity. It checks the written bytes with `CheckPackOriginalAgainst`, then
  writes the same entry with the supported release's identity, which is
  compared, not proved, and requires `ValidatePack` to accept it with the same
  strings. That form lives in the test: no file under `src/` takes a set, and
  the production `PrepareDataPack` refuses the synthetic executable.
- `setup.install_pack`: installation, replacement of an existing pack, a
  staged file that does not validate or holds other values, a staged name or
  pack name taken by a folder, and `RunSetup`'s statuses 1 to 5, with the
  folder unchanged.
- `setup.recipe_ranges`: the recipe check above.

## Not verified

- No original executable was read. That the four ranges lie in the stored
  bytes of a data section, and that each string ends within its capacity, is
  not checked.
- Statuses 0 and 6 to 11 of `RunSetup` are not reached by a test: they need
  a supported original release. `InstallDataPack` is tested on its own for
  8 to 10. Status 11 needs the installed file to change between the rename
  and the read back.
- The staged file is not flushed to the disk before the rename. After a power
  failure the pack may be missing or refused; the engine then reports it and
  setup can run again.
- No Windows executable was run: the Windows build of `vegas-setup` and its
  tests compiles and links only.
- The exit status of an uncaught allocation failure on Windows.
