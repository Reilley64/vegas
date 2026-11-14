# Data pack catalogue: design (VEGAS-52, VEGAS-13)

## Status

This page is a design, not a description of code. Its three next increments
are implemented: catalogue version 1 and `ValidatePack`,
which `data-pack-validation.md` describes, the pack stage in `main`
with C1's consumer, which `data-pack-startup.md` describes, and setup,
which `setup.md` describes. Catalogue versions 2 and 3, under "Catalogue
version 2" and "Catalogue version 3", are implemented as well. It answers
what the
catalogue that ADR 0001 requires must hold before the engine may start
with a data pack, and how setup fills each entry from the original
release. It records no value of the original release. The
decisions it needed were taken on VEGAS-52 on 2026-11-12 and 2026-11-13;
they are under "Decisions".

The measurements are of commit `3b9a04c29`, built for windows-x64 with the
preset, linked as the `FalloutNV` executable is. The page was later moved onto
a newer tip without measuring again.

## What startup reads today

`main` calls `fnv::memory::StartProcessMemory`, starts the timer with
`fnv::timer::Start` and returns 0. A link that loads members on demand takes
15 members of the game archive:

`appmemory_console`, `bsniallocator`, `bstimer`, `canonical_memory_manager`,
`engine_heap_set`, `engine_memory_heap`, `engine_virtual_memory`,
`fixed_pool`, `memory_manager_startup`, `memoryusagetracker`,
`native_memory_pools`, `newoverloads`, `ni_allocator_holder`,
`recipemenu_timer` and `tls`.

Two of them include a legacy file of `src/generated/data/`:

| Member | Legacy definitions | Read by |
| --- | --- | --- |
| `bstimer` | three floats, at `0x011ac3a0`, `0x011ac3a4` and `0x011ac3ac` | the timer's `Update`, `SetMultiplier`, `UnmodifiedSeconds` and `FUN_00aa4e40`, not by `Start` |
| `appmemory_console` | three one-byte definitions, at `0x010824e4`, `0x010824f0` and `0x010824fc` | nothing: the object defines them and no relocation names them |

Following the relocations of the 17 objects of that link from `main` and
from every initializer and thread-local callback section reaches 143
sections. None of them reads a legacy generated value. The only legacy names
they reach are `DAT_011f6080` and `DAT_011f6118`, which the native data
retirements give to `ni_allocator_holder.cpp`, zero-initialized.

Every value startup uses today is written in the source by its native
owner. Under D7 those values are exempt for now; they are listed under
"Values already written in the source".

So the catalogue of what startup reads today is empty: the catalogue is
empty for values not already written in the source. A pack cannot be
empty, since the container requires at least one entry, and ADR 0001 allows
no successful complete validation without the complete catalogue and no
startup interface that can only fail. A pack stage therefore joins `main`
together with the first stage that reads a value from it, not before.

## The next stage in recorded order

The original constructs its memory manager in a dynamic initializer, before
`WinMain` (`0x0086a850`) runs. The other dynamic initializers run in the same
phase. In `main` the memory startup is explicit, so the recorded statements
that follow it are those of `0x0086a850`.

Its first statements are a single-instance check and a remote-session check.
They read four legacy definitions, all in
`src/generated/data/fallout/misc/main.inc`:

| Name | Address | Legacy extent | Recipe bound | Read by |
| --- | --- | --- | --- | --- |
| `str_01082ab8` | `0x01082ab8` | 19 | 20 | the mutex name of `CreateMutexA` |
| `str_01082a7c` | `0x01082a7c` | 59 | 60 | the text of the first message box |
| `str_0104df38` | `0x0104df38` | 6 | 8 | the caption of both message boxes |
| `str_01082a48` | `0x01082a48` | 52 | 52 | the text of the second message box |

The recipe bound is the distance to the next address the recipe binds. The
recipe binds `0x0104df38` under five names in five units, three of them
compiler string literal names; the other three addresses have one name in
one unit.

From those checks to `RegisterClassA` the function reads 16 legacy
definitions: six strings, seven one-byte definitions whose address it passes
as a string, and three pointers to strings. It also reads `Setting` objects
that the generated dynamic initializers construct from legacy name strings.

## Candidate first entries

Each candidate is one entry, version 1. The keys are examples; under D4 the
key is chosen with the owner's implementation. D3 chose C1.

| | C1, single-instance strings | C2, timer multipliers |
| --- | --- | --- |
| Key | `INST` | `TIMR` |
| Source | the four ranges in the table above | `0x011ac3a0` to `0x011ac3af`, four floats |
| Shape | four fields in that order, one per string, of 20, 60, 8 and 52 bytes, the recipe bounds; each holds its string through its first zero byte; setup writes zeros after it | four little-endian IEEE-754 single floats |
| Size | exactly 140 bytes, the sum of the bounds | 16 bytes |
| Decoder | the entry is exactly 140 bytes and each field holds a zero byte; no other constraint is known | four finite values; no other constraint is known |
| Consumer | the composed first statements of `0x0086a850` in `main` | the timer operations above, and a frame step in `main` that calls them |
| Prerequisites | the caption's address is shared with four other recipe names | one typed owner for the four floats, which the recipe binds in 8, 3, 1 and 1 units, the third defined in `blk_00920000_od.inc` |

Setup fills a C1 field by copying the stored string through its first zero
byte and filling the rest of the field with zeros. It never copies a byte
past that zero byte. A string with no zero byte within its bound is refused.

The decision record names a third candidate, two words under the key `RNGT`.
It records its native owner as not ready, and it is not a startup stage.

## Sourcing an entry in setup

The catalogue in the source gives each entry its source ranges as original
addresses, its shape and its decoder. The recipe is the authority for the
addresses: each range starts at an address the recipe binds, or, for a
string the original reaches through a stored pointer (ruling B of
2026-11-13), the pointer is stored at an address the recipe binds. Setup:

1. Reads the executable with `ParsePeFile` and identifies it with
   `IdentifyOriginal` against the source's supported set, the one identity
   the owner adopted on VEGAS-52.
2. Maps each range to one section: the range, less the base address the
   executable's header records, must lie in the section's stored bytes, and
   the section's characteristics must mark initialized data. A range in the
   zero-initialized tail, in a section whose characteristics mark code or
   execution, or in `.bind`, is refused. Zero-initialized objects are the
   source's, not the pack's.
3. Copies the stored bytes of each range and decodes them with the entry's
   decoder.

   Steps 2 and 3 include the existing known-string and recipe-target checks
   that VEGAS-13 requires before the data sections count as readable as
   stored. The decoder checks the entry's shape in addition; it does not
   replace them.
4. Writes the entries with `WritePackStructure` and validates the staged
   bytes with the same validator the engine uses.

An extent comes from the recipe bound and the consumer, never from a legacy
one-byte definition. The legacy files hold 612 non-zero one-byte character
definitions (1,135 including zero); 98 of the 612 sit at an address the
recipe names as a string literal, and `0x0086a850` passes the address of
seven of them as a string.

## The validation boundary

| Stage | Result | Fails with |
| --- | --- | --- |
| Find `vegas-data.pack` in the executable's folder | a path | (no failure: the next stage reports a missing file) |
| Read the file | bytes | `PackOpenError` |
| `ParsePackStructure` | `PackStructure` | `PackStructureError` |
| Compare the recorded original with the source's supported set | (intermediate) | `UnsupportedOriginalError` |
| Every required key is present | (intermediate) | a missing entry |
| Each directory key is in the catalogue, with its version and size | (intermediate) | an unknown key, an unsupported version, a wrong size |
| Each entry decodes | decoded values | the key and the shape problem |
| `ValidatePack` returns | `ValidatedPack` | |
| Publish each value to its native owner | | |
| The consuming stage runs | | |

`OpenPack`, `PackOpenError` and the comparison with a supported set belong
to the open-and-check stage of VEGAS-52 (`data-pack-validation.md`).
A missing entry is checked first: with the one required entry of version
1, a pack whose keys were all in the catalogue held it, so after the key
check no pack could have missed it. Version 2 keeps that order.
`ValidatePack` takes only the bytes. It takes no supported
set and no list of required keys; both are the source's. It is the only maker of a
`ValidatedPack`, which offers decoded values and no raw bytes. Every stage
above it yields a type that cannot become one. Publication and the
consuming stage come after it and are not part of validation.

## The legacy data a complete catalogue would replace

The legacy `.inc` files define 23,196 objects (heuristic count, before the
native data retirements apply):

| Class | Other files of `src/generated/data/` | `src/generated/data/generated/` | All |
| --- | --- | --- | --- |
| zero | 5,407 | 4,397 | 9,804 |
| string | 1,567 | 6,430 | 7,997 |
| numeric | 1,915 | 3,051 | 4,966 |
| pointer | 334 | 16 | 350 |
| integer stored as a pointer | 79 | 0 | 79 |

The files of `src/generated/data/generated/` are, by file, the inputs of the
generated dynamic initializers. Zero objects are the source's. Under D10 raw
pointers are never pack values. Virtual tables and type information are not
pack values either: they are native dispatch, which the pack need not copy
(ADR 0001; VEGAS-52). A pointer to a string is a reference the source binds to a
value the pack may carry. Whenever a member that holds a generated dynamic
initializer is linked, the initializer runs before `main`, so no pack opened
in `main` can supply its inputs as things stand.

## Values already written in the source

Under D7 these values stay in the source for now. Each moves to the pack
under D1 when its owner is next reworked, one owner at a time.

| File | Values | Consumer |
| --- | --- | --- |
| `src/fallout/misc/native_memory_pools.cpp` | the 37 pool families: block sizes, reserve sizes and the names `Pool 8` to `Pool 596` | the pool startup of the memory manager |
| `src/bscore/engine_heap_set.cpp` | the capacities of three heaps and the names `Main` and `Context 23` | the heap startup of the memory manager |

The timer record `g_timeGlobal` is zero-initialized; zero objects are the
source's, so it is not on the list. Which of these values the original
stores in a data section and which are instruction immediates, kept in the
source under D1, is not checked.

## Decisions

Recorded on VEGAS-52 on 2026-11-12 and on the page "Symbol naming and
native ownership".

- **D1, which values the pack carries.** Values stored in the original
  executable's data sections that a native owner consumes at run time come
  from the pack. Constants that are instruction immediates stay in the
  source. Legacy generated data stays until its consumer moves to a native
  owner that reads the pack: migration is per consumer, never all at once.
- **D2, values read before `main`.** No pack is read before `main`. A dynamic
  initializer that consumes original data moves to an explicit step after the
  pack is validated when its owner migrates; until then it stays on legacy
  generated data.
- **D3, the first stage.** C1, the single-instance and remote-session checks
  of `0x0086a850` with their four strings, since it is the original's next
  step after the memory manager. C2 is not on the startup path today.
- **D4, keys and granularity.** One entry per native owner's group of values,
  under a four-character ASCII key chosen with the owner's implementation and
  recorded in the catalogue. No key encodes an address.
- **D5, catalogue growth.** Any change to the required entries raises the
  catalogue version. The engine accepts exactly the source's catalogue
  version, and setup prepares packs again.
- **D6, published storage.** Storage the pack fills may be non-`const`. Its
  size is fixed by the native owner's declaration in the source, and
  validation requires the entry's size to equal it exactly.

Further decisions of the coordinator, recorded on VEGAS-52 on 2026-11-12:

- **D7, values already written in the source.** Values that native owners
  already write in the source are exempt for now. They are listed under
  "Values already written in the source" and migrate per consumer under D1
  later. The catalogue is empty for values not already written in the
  source.
- **D8, C1's layout.** One field per string, its capacity the recipe bound:
  20, 60, 8 and 52 bytes. Setup copies each string through its terminating
  zero byte and fills the rest of the field with zeros; it never copies a
  byte past a terminator. Validation requires the exact entry size and a
  terminator inside each field.
- **D9, raising the catalogue version.** ADR 0001 was amended on
  2026-11-13: a pack's catalogue version must equal the source's
  `fileformat::packCatalogueVersion`, and any change to the required
  entries raises it by one. The engine refuses every other version. A
  version's catalogue lists every entry the engine reads at that version.
- **D10, pointers.** Raw pointers are never pack values.

The structural reader accepts exactly `packCatalogueVersion` of
`src/fileformat/pack_catalogue.h`, and the writer writes it. It is a
constant of its own, apart from the value 1 that the envelope version,
the native data contract and the build target keep.

Rulings of the coordinator on catalogue version 2, recorded on VEGAS-52 on
2026-11-13:

- **Content.** Version 2 holds C1 unchanged and one more entry, the main
  window class. Its consumer is the second-window check of `0x0086a850`,
  composed in `main`: `FindWindowA` on the class name, and if a window is
  found, `SetForegroundWindow` and return 0. Of the ten statements after
  the single-instance and remote-session checks, it is the only one whose
  trial link leaves no name undefined.
- **A, order.** `main` composes the statements of `0x0086a850` in their
  order among those it composes. A statement whose closure cannot link yet
  may be skipped. `data-pack-startup.md` lists every skipped statement with
  its prerequisite and names the side effects that the original performs
  before a later early return.
- **B, a string reached through a pointer.** Allowed, and D10 holds: the
  pack carries the string, never the pointer. Setup reads the pointer at
  the recipe-bound address `0x011a2fe8`, requires a base relocation entry
  for it, follows it to stored read-only initialized data and requires the
  zero byte within the capacity. There is no recipe bound and no
  known-string check for the text itself.
- **C, capacity.** 256 bytes, the length limit Windows documents for a
  window class name. The entry has exactly that size (D6), and the zero
  byte must lie inside it.
- **D.** The defect of the `DAT_01202fa0` buffer was VEGAS-109, which
  is repaired. It gated the four log-path statements and a later
  entry for their suffix strings, not version 2.
- **E.** `FUN_0086a850` in `src/fallout/misc/main.cpp` reads the class name
  from the owner, as it reads C1's strings. The two other units that read
  the pointer, `filefinder.cpp` and `renderer.cpp`, keep the legacy data
  until their consumers move (D1).
- **F.** The key is `WNDC`, and the owner group is "main window class".

The consequence: the pack stage enters `main` only together with C1's
consumer, not before. Catalogue version 1 requires that one entry and the
source's supported original. Under D6 and D8, C1's entry is exactly 140
bytes, four fields at the recipe bounds, and its owner's declaration in the
source has those four capacities.

## Next increments

They follow D1 and D3, with C1 as the first entry. The packs, executables and
values in their tests are synthetic.

1. **Catalogue version 1 and `ValidatePack` (VEGAS-52), implemented.** The catalogue of
   the first entry, its decoder, `ValidatePack` and `ValidatedPack`; the
   source's supported set exists (`pe-file-reader.md`). About 400 lines with
   tests. Tests: a pack of the entry
   validates and returns the decoded values; an unknown key, a wrong entry
   version, a missing entry, an unsupported original and each shape problem
   are refused with their problem, in the stated order; the shape problems
   include an entry of the wrong size and a field with no zero byte; no path
   makes a `ValidatedPack` from a `PackStructure` or an intermediate pack.
2. **The pack stage in `main` (VEGAS-52), implemented.**
   `data-pack-startup.md` describes the code. Find the pack beside the
   executable, validate it, publish the entry, run the consuming stage; report
   a missing, corrupt or incompatible pack and exit non-zero. About 200 lines
   with tests. Tests: the publication and the stage run on a synthetic pack;
   each invalid pack fails before its values are used; `falloutnv.process_exit`
   runs with a synthetic pack beside the executable, written at test time,
   and no original executable in the folder, so startup can read values only
   from the pack; this covers VEGAS-52's runtime data availability after
   executable swapping. On an unattended runner `falloutnv.process_exit` must not stop
   at a modal message, such as the second-instance or remote-session message
   box; those two branches are tested without modal UI.
3. **Setup for catalogue version 1 (VEGAS-13), implemented.** `setup.md`
   describes the code. SHA-256 of the executable,
   identification, the section rules above, decoding, writing and validation
   of the staged pack. About 500 lines with tests, beside the SHA-256 module.
   Tests: executables built in memory with synthetic bytes at the source
   ranges give a pack that `ValidatePack` accepts; a range in code, in
   `.bind`, in a zero tail, in a section not marked as initialized data or
   outside the file, a failed known-string or recipe-target check, a failed
   shape and an unsupported executable are refused; a C1 string is copied
   through its zero byte, never past it, and its field is filled with
   zeros.
4. **Catalogue version 2 (VEGAS-52, VEGAS-13), implemented.** The
   catalogue version as a constant of its own, the `WNDC` entry and its
   owner, setup's string reached through a pointer, the composed
   second-window check in `main`, and `FUN_0086a850` reading the class name
   from the owner. "Catalogue version 2" below states the content;
   `data-pack-startup.md`, `data-pack-validation.md` and `setup.md`
   describe the code.
5. **Catalogue version 3 (VEGAS-127), implemented.** The `LOGS` entry and
   its owner, setup's four suffixes read by recipe ranges, and `WinMain`'s
   statements S2 to S5 composed in `main`. "Catalogue version 3" below
   states the content.

## Catalogue version 2

Version 2 is implemented. It holds two entries, in key order:

| Key | Owner group | Version | Fields | Size |
| --- | --- | --- | --- | --- |
| `INST` | C1, the single-instance and remote-session strings | 1 | 20, 60, 8 and 52 bytes | 140 bytes |
| `WNDC` | the main window class | 1 | the class name, 256 bytes | 256 bytes |

`fileformat::MainWindowClass` declares the `WNDC` field, so its size fixes
the entry's (D6). The field holds the class name, then a zero byte, then
zeros to its end, as C1's fields do (D8). The class name is also the
title `0x0086a850` gives the main window.

The original stores no class name at a recipe-bound address. It stores a
32-bit pointer to it at `0x011a2fe8`, which the recipe binds under one
name in three units, `src/fallout/misc/main.cpp`, `filefinder.cpp` and
`renderer.cpp`, with a recipe bound of 8 bytes. Setup reads the string
through that pointer under ruling B (`setup.md`). The capacity is ruling
C's, not a recipe bound.

The consumer is the second-window check, which `main` composes after the
single-instance and remote-session checks (`data-pack-startup.md`). It
skips the eight statements between them under ruling A. A pack of
catalogue version 1 is refused for its catalogue version.

## Catalogue version 3

Version 3 is implemented (VEGAS-127). It holds three entries, in key order:

| Key | Owner group | Version | Fields | Size |
| --- | --- | --- | --- | --- |
| `INST` | C1, the single-instance and remote-session strings | 1 | 20, 60, 8 and 52 bytes | 140 bytes |
| `LOGS` | the log path suffixes | 1 | 16, 16, 24 and 16 bytes | 72 bytes |
| `WNDC` | the main window class | 1 | the class name, 256 bytes | 256 bytes |

`INST` and `WNDC` are unchanged. `LOGS` holds the four strings that
`WinMain`'s log-path builders, its statements S2 to S5, each append to the
user folder, one field per string in the order `WinMain` passes them:
`firstSuffix`, `secondSuffix`, `thirdSuffix` and `fourthSuffix` of
`fileformat::LogPathSuffixes`, whose sizes fix the entry's (D6). Each field
holds its string, then a zero byte, then zeros to its end, as C1's fields do
(D8), and validation requires the entry's exact size and a zero byte inside
each field.

The original stores the four strings at `0x01082a38`, `0x01082a28`,
`0x01082a10` and `0x01082a00`, the addresses `FUN_0086a850` passes to the
four builders. The recipe binds each under a one-byte `UNK_` name for
`src/fallout/misc/main.cpp`, and binds `0x01082a48`, C1's second message
text, next. Each capacity is the recipe bound, the distance to the next
address the recipe binds, as for C1: 16, 16, 24 and 16 bytes. It is the
most the original can hold there without reaching the next bound object;
the consumer's own limit, a buffer of 260 characters that also holds the
user folder, is looser. The one-byte legacy definitions give no extent.
The recipe names no literal at these addresses, so no text is known and
setup has no known-string check for them. The key, `LOGS`, encodes no
address (D4).

The change to the required entries raised the catalogue version from 2 to
3 (D5, the ADR 0001 amendment of 2026-11-13). A pack of catalogue version 2
is refused for its catalogue version, before its entries are read, so setup
must prepare the pack again.

The consumer is `WinMain`'s S2 to S5, which `main` composes after the
single-instance and remote-session checks and before the second-window
check (`data-pack-startup.md`). Of the eight statements between those
checks, `main` skips S1, S6, S7 and S8 under ruling A. `FUN_0086a850`
itself still passes the legacy definitions; it links into no program.

## Not verified

- No original executable was read for this page's measurements. That the
  ranges above lie in data sections, and that the legacy extents match the
  stored bytes, is not checked. The owner's private runs of 2026-11-13
  and 2026-11-14 (`setup.md`) read an original executable for C1, the log
  path suffixes and the main window class only.
- Which values of "Values already written in the source" the original
  stores in a data section is not checked.
- The census is a parser of the legacy text, not of objects. It reads the
  files before the retirement patch applies.
- The reachability follows relocations only. It follows virtual tables as
  data, so it may reach more than runs, and it sees no call made through a
  value computed at run time.
- No Windows executable was run for this page's measurements.
- The page was not measured again on the tip it was moved onto.
- For version 3, the owner's third private run of 2026-11-14 (`setup.md`)
  read an original executable. Setup ended with status 0, so its checks of
  the four suffix ranges passed. A separate PE check found the four ranges
  in the stored bytes of one read-only initialized-data section, each
  string's zero byte within its recipe bound. No test in this repository
  checks this on an original executable.
- For version 2, the owner's second private run of 2026-11-13 (`setup.md`) read
  an original executable. Setup ended with status 0, so its checks of the
  pointer at `0x011a2fe8` and of its string passed. A separate PE check
  found exactly one 32-bit base relocation at the pointer, its target in
  the stored bytes of a read-only initialized-data section, and the
  string's zero byte within 256 bytes. No test in this repository checks
  this on an original executable.
