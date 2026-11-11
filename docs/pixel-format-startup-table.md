# The pixel-format startup table (VEGAS-85)

`gNiPoint3StartupSrc` and `gNiPoint3StartupDst` are two globals of 17 ints.
Their names are historical. The units that read them treat them as a pixel
format record, the default 32-bit format with alpha.

This is a first step. It gives the storage one complete declaration, lists
every unit that views it, and moves nine of the 16 units onto the declaration.
The objects of four of them do not change. Five change by aligned moves, which
the owner accepted. It changes no stored value. What stays open is under "The
open slot question", "The startup call" and "Not covered".

## The owner

`src/gamebryo2.2/corelibs/nimain/console/nipoint3_console.cpp` defines both
globals. The source is a constant list of 17 ints. The destination is a copy
of the source, made by a dynamic initializer before `main` runs.

`build/units.json` gives that unit these rows:

| Row | Address | Name | Size |
| --- | --- | --- | --- |
| function | `0x00a62110` | initializer of `gNiPoint3StartupDst` | 22 |
| symbol | `0x011aa2a0` | `gNiPoint3StartupSrc` | none |
| symbol | `0x011f4600` | `gNiPoint3StartupDst` | none |

The recipe has no size for a symbol row. The next recipe symbol after each
global is 72 bytes on, at `0x011aa2e8` and `0x011f4648`. So the recipe bounds
each global by 72 bytes, and the owner's 17 ints take 68 of them. Nothing in
the tree claims the last 4 bytes.

Both definitions are ordinary source. No file under `src/generated/data/`
defines either name, and `src/runtime/native_data_retirements.patch` does not
mention them. Under `docs/native-data-ownership.md` they are therefore native
defaults that the source owns, not legacy inputs.

## The declaration

`include/fnv/ni_point3_startup_table.h` declares the type and both globals:

```cpp
struct NiPoint3StartupTable
{
    int data[17];
};
```

This is the owner's own type, moved out of its unit. The name, the 17 ints
and the mangled names of the globals are as before. It is the one complete
declaration of the type.

The header declares both globals `alignas(16)`, and the owner's two
definitions repeat it. "The alignment of the storage" below says why.

A unit that views the storage under a record of its own calls
`NiPoint3StartupTableAs<View>(table)`. It compiles only when `View` is a
complete type of the same 68 bytes. A unit whose record is smaller, or has no
layout, cannot use it.

`NiPoint3StartupTableAs` is a transitional cast shim. It checks the size and
nothing else. It is not the typed owner of the storage, and that it compiles
for a record is not evidence that the storage has that record's layout. Each
new record it is used with needs a row in the table below. It retires when
the units share one `NiPixelFormat` declaration.

Two other headers still name the type without its layout:
`include/fnv/symbols_011aa000.h` and `include/fnv/symbols_011f4000.h`, as
they do for every address they list. A third site,
`src/gamebryo2.2/corelibs/nimain/nidevimageconverter_decls.h`, named the type
and the source global the same way until its unit moved onto the header.

## Units that view the storage

The windows-x64 archive has 16 units that refer to either global: the owner
and 15 others. The table gives each unit's record, its size in that build,
and what the unit's instructions do with the storage. "Address" means the
unit only takes the address and hands it to the function named.

| Unit | Global | Record in the unit | Size | Instructions on the storage |
| --- | --- | --- | --- | --- |
| `nimain/console/nipoint3_console.cpp` | both | `NiPoint3StartupTable`, 17 ints | 68 | reads bytes 0 to 67 of the source and writes them to the destination: four 16-byte moves and one 4-byte move |
| `bsshader/bsshadermanager.cpp` | source | `NiPixelFormat`, 17 unsigned ints | 68 | address, 5 times, to the `NiPixelData` constructor |
| `fallout_shared/facegen/bsfacegenmanager.cpp` | source | `fnv_00650ea0::NiPixelFormat`, 68 chars | 68 | address, twice, to the `NiPixelData` constructor |
| `nimain/niddsreader.cpp` | source | `NiPixelFormat`, 2 bytes, a short and 16 unsigned ints | 68 | address, 4 times: twice it is one of two pointers through which 68 bytes are copied, once to `NiPixelFormat::operator==`, once kept as a pointer |
| `nimain/nidevimageconverter.cpp` | source | `NiPixelFormat`, typed fields, and `Mipmap::Format`, 17 unsigned ints | 68 | one read of bytes 0 to 67; address, 6 times, to `NiPixelFormat::operator==`; address returned once |
| `nimain/nipixelformat.cpp` | source | `NiPixelFormat`, typed fields | 68 | one read of bytes 0 to 67 |
| `staging/blk_00a80000_o2.cpp` | source | `NiPixelFormat`, 17 unsigned ints | 68 | one read of bytes 0 to 67; address, once, to `NiPixelFormat::operator==` |
| `staging/blk_00e60000_o2.cpp` | source | `PixelTemplate`, 17 unsigned ints | 68 | address, once, as one of the pointers through which 68 bytes are read |
| `staging/blk_00a60000_o2.cpp` | destination | `Settings_a62`, 17 ints | 68 | one write of bytes 0 to 67, in `ApplySettings` |
| `bsmenu/font.cpp` | source | `PixelFormat`, one int | 4 | address, once, to the `PixelData` constructor |
| `staging/blk_00640000_o2.cpp` | source | `NiPixelFormat`, 4 ints | 16 | address, once, to the `NiPixelData` constructor |
| `staging/blk_00640000_od.cpp` | source | `FGPixelFormat`, one int | 4 | address, once, to `FUN_00b6bbd0` |
| `fallout_shared/region system/tesregiondatalandscape.cpp` | source | `NiPixelFormat`, no layout | none | address, once, to the `NiPixelData` constructor |
| `nimain/nitexturecodec.cpp` | source | `NiPixelFormat`, no layout | none | address, once, to the `PixelData` constructor |
| `nimain/nitexture.cpp` | destination | `NiPixelFormat`, no layout | none | address, once, to `CreateCheckerboardTexture` |
| `nimain/nifixedstring_h_unit.cpp` | source | none, a `void*` | none | address, once, to `NiTexture::FUN_0064ceb0` |

Every read and write in these units covers bytes 0 to 67 and no more. No
unit reads or writes a single field of the storage directly. The fields are
read by the functions the address goes to.

The 68-byte records fall into four shapes: 17 ints or unsigned ints (the
owner's and five others), 68 chars (one), 2 bytes, a short and 16 unsigned
ints (one), and typed fields (two). The typed records agree with each other: a flags byte at
0, a bits-per-pixel byte at 1, the format at 4, the tiling at 8, the renderer
hint at 12, the extra data at 16, and four 12-byte component records from 20.

### Units on the declaration

Nine units include the header.

Four moved with no change to their objects: the owner,
`bsshadermanager.cpp`, `bsfacegenmanager.cpp` and `niddsreader.cpp`. Their
windows-x64 objects are the same as before, byte for byte, apart from the
time stamp of the object file.

Five moved by a decision of the owner of VEGAS-85, because the header changes
their objects: `nidevimageconverter.cpp`, `nipixelformat.cpp`,
`blk_00a80000_o2.cpp`, `blk_00e60000_o2.cpp` and `blk_00a60000_o2.cpp`. The
next section gives the change and its proof.

In each of the five the edit is an include of the header and one call of
`NiPoint3StartupTableAs` in place of each cast of the global's address:
two in `nidevimageconverter.cpp`, two in `blk_00a80000_o2.cpp` and one in
each of the other three. `nidevimageconverter_decls.h` also loses its own
declaration of the type and of the source global, and its macro
`SOURCE_FORMAT_RGB` calls the helper.

`nifixedstring_h_unit.cpp` needs no change. It casts nothing.

### The alignment of the storage

The five units copy the storage in 16-byte moves. Before, they saw the type
without its layout, so the compiler assumed no alignment and emitted
unaligned moves. With the layout the compiler knows that the storage is
aligned to 16 bytes and emits aligned moves. An aligned move faults when its
address is not a multiple of 16, so the change needs proof that the address
always is one.

For the windows-x64 build target the compiler aligns every global of 64 bytes
or more to 16 bytes, where it defines one and where it only declares one.
That is a default of the compiler, not a statement of the source. So the
header and the owner write `alignas(16)` on both globals. The owner's object
is the same with and without it, byte for byte apart from the time stamp.

Measured on the windows-x64 build of this change:

- In each of the five objects exactly four instructions differ, each an
  unaligned 16-byte load or store (`movups`) that became the aligned one
  (`movaps`) with the same operands. That is 20 instructions and 20 bytes.
  The only other bytes that differ are the time stamp and the checksum of
  each changed section. No relocation, symbol or other instruction differs.
- The four moves are the four 16-byte loads from the source in
  `nidevimageconverter.cpp` (`Converter::GenerateMipmaps`),
  `nipixelformat.cpp` (`PixelFormatReader::FUN_00a7c9f0`),
  `blk_00a80000_o2.cpp` (`BitmapReader::ReadBitmapHeader`) and
  `blk_00e60000_o2.cpp` (`GetPixelTemplateForFormat`), and the four 16-byte
  stores to the destination in `blk_00a60000_o2.cpp` (`ApplySettings`).
- In the owner's object the source is at offset 0 of a `.data` section and
  the destination at offset 0 of a `.bss` section. Both sections are aligned
  to 16 bytes.
- In the map of the link that takes every member of the archive both globals
  are at addresses that are multiples of 16.

`GetPixelTemplateForFormat` does not load from the source by name. It picks
one of 47 records in a `switch` and copies through the pointer. An aligned
load there needs all 47 records aligned, not only the source. The other 46
are the records `DAT_011aa210` to `DAT_011ab2f0` that
`src/generated/data/staging/blk_00e60000_o2.inc` defines. That file is part
of the same unit, so one compiler run both defines the 46 and emits the
loads. In the unit's object each of the 46 is at an offset that is a multiple
of 16 in a `.rdata` section aligned to 16 bytes, and in the map each is at an
address that is a multiple of 16. The unit already saw the layout of those
46, and so already assumed them aligned. Only the source record held the
moves back.

The alignment of the 46 is the compiler default named above. Nothing in the
generated file writes it out, and this change does not edit that file.

### Units left on their own view

Six units cannot use the header. Three have a record of 4 or 16 bytes
(`font.cpp`, `blk_00640000_o2.cpp`, `blk_00640000_od.cpp`), and three name
`NiPixelFormat` without a layout (`tesregiondatalandscape.cpp`,
`nitexturecodec.cpp`, `nitexture.cpp`). Each of them only passes the address
on. They join the declaration when they share a `NiPixelFormat` with the
function they call, which is the work of a shared declaration of that class
and not of this step.

## Where the fields are read

The address reaches these functions, which read fields under the typed
record. This table is taken from the source of the four functions only. Their
objects were not read for it.

| Function | Unit | Fields read |
| --- | --- | --- |
| `NiPixelFormat::operator==`, `0x00a76540` | `nimain/nipixelformat.inl` | flags, bits per pixel, format, tiling, renderer hint, and the four fields of each component record |
| `NiPixelData` constructor, `0x00a7c190` | `nimain/nipixeldata.cpp` | the whole record by copy, then format and bits per pixel |
| `CreateCheckerboardTexture`, `0x00a62330` | `staging/blk_00a60000_o2.cpp` | bits per pixel, flags, and the component and bit count of each component record |
| `FUN_00b6bbd0`, `0x00b6bbd0` | `bsshader/bsshaderutil.cpp` | the whole record by copy |

`ApplySettings`, `0x00a622d0`, is the only writer of the destination after
startup. `NiConsoleRenderer` calls it with one of its formats.
`GetTextureForType` in `nitexture.cpp` is the only reader of the
destination: it passes it to `CreateCheckerboardTexture`.

## The open slot question

The stored list is

```text
8193, 1, 0, -1, 0,   0, 264, 1,   0, 264, 2,   0, 264, 3,   0, 264, 3
```

Under the typed record the first five ints read well: flags 1 and 32 bits
per pixel, format 1 (`FORMAT_RGBA`), tiling 0, renderer hint -1, extra data
0. The four component records then read as component 0 with representation
264 and 1, 2, 3 and 3 bits. That is not a format the readers can use:

- 264 is not a value of the representation enum.
- The bit counts add up to 9, not to the 32 bits per pixel.
- All four records name component 0, so `GetComponentMask` finds no green,
  blue or alpha and returns 0 for them. This is read from source, not run.

VEGAS-85 reports that the list may lack one zero before the first 264. With
that zero, and the same 17-int extent, the list would be

```text
8193, 1, 0, -1, 0,   0, 0, 264,   1, 0, 264,   2, 0, 264,   3, 0, 264
```

which reads as components 0, 1, 2 and 3, representation 0, and 8 bits each,
32 in all. The last int of the stored list, a 3, has no place in this
reading.

The tree supports the second reading but does not prove it:

- The legacy inputs define 37 other records as lists of ints at `0x011aa210`
  to `0x011aaf90`. In 35 of them the values of 256 or more, from int 5 on,
  are at ints 7, 10, 13 and 16, and in the other two at ints 7 and 10. The
  stored list is the only one with such values at ints 6, 9, 12 and 15.
- The readers above work on the second reading and not on the first.

Neither point gives the values of the original release. Four things are not
settled by the tree:

1. Whether the 17th int is 264, as the pattern suggests. The stored list ends
   in a 3 that the second reading drops, and nothing says where it came from.
2. What the second byte of each 264 means. The typed records call it a signed
   flag, and it is 1 here and in all 37 sibling records.
3. Whether the destination should start equal to the source. It does today.
4. What the stored list does to the readers. This consequence is probable
   and not verified. With the stored list the component masks of components
   1 to 3 are 0, so the checkerboard texture built from the destination
   would lose green, blue and alpha. The same source data goes to the
   `NiPixelData` constructor, and to the `operator==` comparisons in the DDS
   and BMP readers and in the mipmap code.

Each reading needs this evidence before a value changes:

- For the stored list: a reader that takes the component records as they
  stand and yields a usable format. No such reader is in the tree.
- For the list with the zero: a decision by the owner that the shape of the
  sibling records and the readers' arithmetic are enough to write a native
  default, since the values of the original release cannot be consulted.
  The 17th int and the signed flag need the same decision.

Until then the stored list stays as it is.

## The startup call

The recipe binds two names to `0x00a62110`. The owner's function row names
the dynamic initializer of the destination. A symbol row of
`nimain/nimainsdm.cpp` names `FUN_00a62110`, and `InitializeGameSystems`
calls it between `FUN_00a91290` and `FUN_00a7e930`.

In the native build the dynamic initializer makes the copy before `main`.
`FUN_00a62110` has no definition and is one of the undefined names of the
link. So the copy happens once, at startup, and the later call that the
recipe records is not joined to it. Whether that call should repeat the copy,
which would undo an earlier `ApplySettings`, is open.

## Test

`runtime.pixel_format_startup_table` links the owning unit. It checks that
the two globals do not share storage, that the destination holds a copy of
all 17 source ints after startup, and that a change of any one destination
int leaves the source as it was and is noticed by the comparison. It names no
stored value, so it holds for either reading above.

## Not covered

- No stored value and no slot changes.
- The six units that cannot use the header stay on their own view.
- The comment above the definitions in `nipoint3_console.cpp` speaks of a
  160-byte region and of a `rep movsd`. VEGAS-85 supports neither. The
  comment is left for the step that settles the values.
- No windows-x64 executable was run. The aligned moves are shown safe from
  the objects and the link map, not by running them.
- `FUN_00a62110` stays undefined.
- The private copies of `NiPixelFormat` are not merged.
- No test reaches `ApplySettings` or `CreateCheckerboardTexture`.
- The research note that VEGAS-85 cites,
  `docs/research/upstream-pr33-and-recent-prs-assessment.md`, is not in the
  tree and was not read. Neither was the upstream change the ticket links.
