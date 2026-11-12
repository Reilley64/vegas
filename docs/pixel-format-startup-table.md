# The pixel-format startup table (VEGAS-85)

`gNiPoint3StartupSrc` and `gNiPoint3StartupDst` are two globals of 17 ints.
Their names are historical. The units that read them treat them as a pixel
format record, the default 32-bit format with alpha.

A first step gave the storage one complete declaration, listed every unit
that views it, and moved nine of the 16 units onto the declaration. The
objects of four of them did not change. Five changed by aligned moves, which
the owner accepted. A second step set the stored values to a native default
that the owner approved, as "The stored values" says. What stays open is under
"The stored values", "The startup call" and "Not covered".

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
| `tests/runtime/pixel_format_startup_table_test.cpp` (host test, outside the archive) | both | `NiPixelFormat` from `nipixelformat_decls.h`, typed fields | 68 | address to `GetPixelBitData`, `operator==` and `operator!=` |

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

## The stored values

### The list before the decision

Until the owner's decision the stored list was

```text
8193, 1, 0, -1, 0,   0, 264, 1,   0, 264, 2,   0, 264, 3,   0, 264, 3
```

Under the typed record the first five ints read well: flags 1 and 32 bits
per pixel, format 1 (`FORMAT_RGBA`), tiling 0, renderer hint -1, extra data
0. The four component records then read as component 0 with representation
264 and 1, 2, 3 and 3 bits. That is not a format the readers can use:

- 264 is not a value of the representation enum. Under the host's
  undefined-behaviour checker, `NiPixelFormat::operator==` reports the load of
  264 as a `Representation` as undefined behaviour.
- The bit counts add up to 9, not to the 32 bits per pixel.
- All four records name component 0, so `GetComponentMask` finds no green,
  blue or alpha and returns 0 for them. This is read from source, not run.
  `NiPixelFormat::GetPixelBitData` gives offset 0 for all four components;
  that was run, in the host test.

VEGAS-85 reported that the list may lack one zero before the first 264. The
tree supports that reading but does not prove it:

- The legacy inputs define 37 other records as lists of ints at `0x011aa210`
  to `0x011aaf90`. In 35 of them the values of 256 or more, from int 5 on,
  are at ints 7, 10, 13 and 16, and in the other two at ints 7 and 10. The
  stored list was the only one with such values at ints 6, 9, 12 and 15.
- The readers above work on that reading and not on the stored list.

Neither point gives the values of the original release, which cannot be
consulted.

### The decision

On 2026-11-12 the owner of VEGAS-85 approved this list as a native default:

```text
8193, 1, 0, -1, 0,   0, 0, 264,   1, 0, 264,   2, 0, 264,   3, 0, 264
```

It is the stored list with a zero inserted before the first 264 and with 264
as the 17th int, which drops the stored list's last 3. The second byte of each
264, the signed flag, stays 1. The values are a reconstruction decision, not
values recovered from the original release. The comment above the definitions
in `nipoint3_console.cpp` says so.

The list reads as components 0, 1, 2 and 3 (red, green, blue, alpha),
representation 0, and 8 bits each, 32 in all. That is the only reading under
which the readers obtain a usable format. The siblings support it: the alpha
record of the 32-bit sibling at `0x011aaac8` is `3, 0, 264`, every colour
component of the 46 records of `blk_00e60000_o2.inc` sets the signed byte to
1 (65 of 65; only the luma and padding components of `DAT_011aad08` and
`DAT_011aaf90` set it to 0), and `operator==` compares that byte.

The destination still starts as a copy of the source.

The change is the initializer of the source. In the windows-x64 build only
the bytes of that list in the owner's `.data` section change, and no other
object of the archive changes.

### What stays open

- What the signed byte means for an 8-bit colour channel. It is 1 here
  because every colour component of the sibling records sets it and
  `operator==` compares it.
- Whether the destination should start equal to the source. It does, as
  before; nothing in the tree speaks against it.
- `GetComponentMask` and `CreateCheckerboardTexture` are not run. Their unit
  does not build for the host.

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
int leaves the source as it was and is noticed by the comparison.

It also reads both globals through the functions of
`nimain/nipixelformat_h_unit.cpp`, the unit that the recipe names for
`NiPixelFormat::GetPixelBitData` (`0x00a62230`) and `operator==`
(`0x00a76540`). On the host the test links that unit; on windows-x64 it
links the game archive. It views the storage as that unit's `NiPixelFormat`,
from `nipixelformat_decls.h`, whose fields lie as in the typed records above.
It checks that:

- `GetPixelBitData` gives red, green, blue and alpha the offsets 0, 8, 16
  and 24, in both globals;
- the source is equal, by `operator==`, to a record of the approved list, and
  not unequal to it by `operator!=`;
- the source holds the 17 ints of the approved list. `operator==` does not
  compare the extra data and treats a renderer hint of -1 as any hint, so it
  alone does not pin those two ints;
- the list before the decision fails the offsets. It is not given to
  `operator==`, whose load of 264 as a `Representation` is undefined.

With the list before the decision in the owner, the test fails, both
optimized and under the address and undefined-behaviour checkers.

## Not covered

- The six units that cannot use the header stay on their own view.
- No windows-x64 executable was run. The aligned moves are shown safe from
  the objects and the link map, not by running them.
- `FUN_00a62110` stays undefined.
- The private copies of `NiPixelFormat` are not merged.
- No test reaches `ApplySettings`, `CreateCheckerboardTexture` or
  `GetComponentMask`.
- The research note that VEGAS-85 cites,
  `docs/research/upstream-pr33-and-recent-prs-assessment.md`, is not in the
  tree and was not read. Neither was the upstream change the ticket links.
