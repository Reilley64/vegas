# One provider of the geometry base constructor

VEGAS-75 asks for a shared native geometry base with genuine construction,
clone and retirement at every site. This change is the bounded first part: the
global `FUN_00a744a0::FUN_00a744a0()` now has one definition. Everything else
on the ticket is listed under "Not covered", and most of it waits for the
native base of VEGAS-86.

## The constructor

`FUN_00a744a0::FUN_00a744a0()` is the function at `0x00a744a0`.
`build/units.json` lists it once as a function, 18 bytes, in the unit
`src/gamebryo2.2/corelibs/nimain/nitrishape.cpp`. That definition carries the
address tag. It constructs its `NiTriStrips` base, the function at
`0x00a89740`, and then stores the table of its own class.

`src/staging/blk_00c40000_od.cpp` used to define the same name a second time
with an empty body and no address tag. The recipe gives that unit no function
at `0x00a744a0`. The unit's symbol table binds the constructor's name to
`0x00a744a0`, as a name the unit requires. The empty body was a placeholder
for the callee of the unit's two constructors `0x00c5ceb0` and `0x00c5ced0`,
not a second constructor. It is removed. The unit keeps its declaration.

No second address exists for this name, and no second name for this address:

| Recipe row | Unit | Binding |
| --- | --- | --- |
| function, 18 bytes | `nitrishape.cpp` | `??0FUN_00a744a0@@QAE@XZ` at `0x00a744a0` |
| symbol | `bsresizabletrishape.cpp` | same name, `0x00a744a0` |
| symbol | `bssegmentedtrishape.cpp` | same name, `0x00a744a0` |
| symbol | `nioldscreenspace.cpp` | same name, `0x00a744a0` |
| symbol | `niscreenelements.cpp` | same name, `0x00a744a0` |
| symbol | `blk_00a80000_o2.cpp` | same name, `0x00a744a0` |
| symbol | `blk_00c40000_od.cpp` | same name, `0x00a744a0` |

These are all the rows that name the constructor or the address. The row of
`niscreenelements.cpp` is a name no object emits: that unit's object requires
the address as `ChildBase::ChildBase()` instead, which has no definition.

Related rows, unchanged:

- `0x00a89740`, 18 bytes, is the function `??0NiTriStrips@@QAE@XZ` of
  `nitristrips.cpp`. `nitrishape.cpp` and `blk_00a60000_o2.cpp` bind the name
  to it.
- No unit has a row for `NiParticles::NiParticles()`, the base that the
  definition of `0x00a89740` constructs. The unit of `nitristrips.cpp` binds
  `??0NiGeometry@@QAE@XZ` to `0x00a80540`; its object requires that name from
  `0x00a9b150`, not from the definition of `0x00a89740`. Apart from its own
  constructor `0x00a89740`, the unit has no row for any other constructor.
- `0x00c5ceb0`, 31 bytes, and `0x00c5ced0`, 81 bytes, are functions of
  `blk_00c40000_od.cpp`. The same unit binds `??0EmitterObjectStub@@QAE@XZ` to
  `0x00c5ceb0`. Its object requires that name, and no object defines it.
- `nitrishape.cpp` binds five table names to `0x0109d454`, among them
  `??_7FUN_00a744a0@@6B@`. No generated table exists at that address; the
  compiler emits the table of the class.

The recipe records no call edges. That `0x00c5ceb0` and `0x00c5ced0` call
`0x00a744a0` is inferred from the unit's symbol row and from the two tagged
bodies, which construct a `FUN_00a744a0` base first.

`build/units.json` is unchanged: no name in it changed.

## Requirers

Read from the rebuilt windows-x64 objects.

| Object | Function that calls the constructor | Reached from |
| --- | --- | --- |
| `nitrishape.cpp` | the definition | |
| `blk_00a80000_o2.cpp` | `FUN_00a877a0` (`0x00a877a0`), `FUN_00a87140` (`0x00a87140`) | stream loaders registered in `nimainsdm.cpp` |
| `nioldscreenspace.cpp` | `FUN_00a8ff80` (`0x00a8ff80`) | stream loader registered in `nimainsdm.cpp` |
| `bsresizabletrishape.cpp` | `FUN_00a86e80_shell::FUN_00a86e80` (`0x00a86e80`) | entry 18 of the generated table `0x0109e704` |
| `bssegmentedtrishape.cpp` | `FUN_00a87340_cls::CreateTarget` (`0x00a87340`) | entry 18 of the generated table `0x0109e834` |
| `blk_00c40000_od.cpp` | `FUN_00c5ceb0::FUN_00c5ceb0`, `FUN_00c5ced0::FUN_00c5ced0`: new requirements | nothing: no object requires either name |

`niscreenelements.cpp` (`0x00a87860`, entry 18 of the generated table of
`ChildObject`) requires `ChildBase::ChildBase()`, before and after.

The definition's object requires `NiTriStrips::NiTriStrips()`, which
`nitristrips.cpp` defines, and `FUN_00a744a0::~FUN_00a744a0()`, which no
object defines. `nitristrips.cpp` requires `NiParticles::NiParticles()`, which
no object defines. Nothing retires an object of this class: the only retirer
is the deleting destructor the compiler emits in `nitrishape.cpp`, and it
needs the missing destructor.

No object carries an inline body of the constructor. Its only definition in
the archive is the one in `nitrishape.cpp`.

## What each path did and does

The windows-x64 link of every archive member, and the link of
`tests/runtime_havok_worker_pool_test`, were forced past their errors to see
the bindings. In both, the accepted tip bound the constructor's name to the
empty body in `blk_00c40000_od.cpp`, for all five external callers. Now both
bind it to the definition in `nitrishape.cpp`.

| Path | Before | Now |
| --- | --- | --- |
| The five external callers | In a forced link, base construction did nothing; the caller then stored its own table. | Base construction runs the definition: `0x00a89740`, then the table of the class. |
| `0x00c5ceb0` | The empty body was expanded in place: one store of the table `0x010c2e7c`. | Calls the definition, then the same store. |
| `0x00c5ced0` | The empty body was expanded in place: the table store and four 32-bit stores. | Calls the definition, then the same five stores. |
| `0x00a87860` | Requires an undefined name. | The same. |

The definition cannot complete yet. `0x00a89740` calls
`NiParticles::NiParticles()` first, and that name has no definition, so a
forced link gives it address zero. Before this change a forced link hid that
behind the empty body. This is a defect of the present chain, not of this
change; it is recorded under "Not covered".

No program that links today contains any of these objects:

- The game executable links with 15 archive members. None is one of the
  eight objects above or `nimainsdm.cpp`.
- Of the 55 test executables, 54 link, before and after, and none of the 54
  contains any of the eight objects.
- `tests/runtime_havok_worker_pool_test` contains all eight and does not
  link, before and after. It stops on duplicate definitions: nine before,
  eight now.

## Storage each caller gives the constructor

Measured on windows-x64: the bodies from the rebuilt objects, each size from
the unit's own declaration compiled with that unit's command, and each
allocation from the size the object passes to the allocator.

The definition's own highest write is the 8-byte table pointer at `+0`.
`0x00a89740` writes the same 8 bytes. The base below it has no body, so its
writes are not known. The definition's unit declares the class with `0xc8`
bytes and passes that size to the sized free.

| Storage | Unit | Bytes | Against the 8 bytes written | Against the declared `0xc8` |
| --- | --- | --- | --- | --- |
| `FUN_00a877a0`, allocated | `blk_00a80000_o2.cpp` | `0xc4` | fits | 4 short |
| `FUN_00a87140`, allocated | `blk_00a80000_o2.cpp` | `0xd0` | fits | fits |
| `FUN_00a8ff80`, allocated | `nioldscreenspace.cpp` | `0xc4` | fits | 4 short |
| `0x00a86e80`, allocated | `bsresizabletrishape.cpp` | `0xd8` | fits | fits |
| `0x00a87340`, allocated | `bssegmentedtrishape.cpp` | `0xd0` | fits | fits |
| `FUN_00c5ceb0`, whole object | `blk_00c40000_od.cpp` | 8 | fits | 192 short |
| `FUN_00c5ced0`, whole object | `blk_00c40000_od.cpp` | 8 | fits | 192 short |

The allocation sizes are those of the original release, where pointers are
4 bytes. `FUN_00c5ced0` also stores its own four fields at `+0xc8` to `+0xd4`
through a second view of `0xd8` bytes, as it did before. The other units
declare the class with no members: `blk_00a80000_o2.cpp`,
`nioldscreenspace.cpp`, `bsresizabletrishape.cpp` and
`bssegmentedtrishape.cpp` see 1 byte, and `nitristrips.cpp` declares
`NiTriStrips` with 8 bytes where `nitrishape.cpp` declares it with `0xc8`.
This change does not endorse those declarations or sizes.

Two callers' own stores already pass their allocations. This change does not
alter them:

- `FUN_00a87140` allocates `0xd0` bytes and stores 1 byte at `+0xd0`, 1 byte
  past the end. Its unit declares `FUN_00a87140_class` with `0xd8` bytes.
- `0x00a87340` allocates `0xd0` bytes and stores 4 bytes at `+0xd0` and 1
  byte at `+0xd4`, 5 bytes past the end. Its unit declares `Target` with
  `0xd8` bytes.

The body of `0x00a80540` in `nitribasedgeom.cpp` is not in this chain today.
Its own highest store is 8 bytes at `+0xd0`, so it writes up to `+0xd8`. If
the chain ended in it, that would be against allocations of `0xc4`, `0xc4`,
`0xd0`, `0xd0` and `0xd8` bytes. Its two callees, `NiAVObject::NiAVObject()`
and `NiPropertyState::NiPropertyState()`, are not counted.

## Not covered

These were open before this change and remain open.

- The native geometry base. Each unit above declares its own view of the
  object. One shared declaration from `NiObject` down to this class, with
  native-width members, is VEGAS-86.
- `NiParticles::NiParticles()` has no definition and no recipe row. That the
  unit's only row for a constructor other than its own is `0x00a80540`
  suggests that the base `0x00a89740` constructs is `NiGeometry`
  (`0x00a80540`). That is an inference, and the base is not changed here.
- `FUN_00a744a0::~FUN_00a744a0()` has no definition, so nothing can retire
  the class.
- The table at `0x0109d454` is the compiler's, with one entry. The original
  table's entries are not reproduced.
- The five allocations use the original release's sizes. Two are smaller
  than the class the definition's unit declares.
- `0x00c5ceb0` is defined as `FUN_00c5ceb0` and required as
  `EmitterObjectStub`. They are not connected here.
- `0x00a87860` requires the address as `ChildBase::ChildBase()`. It is not
  connected here.
- Clone and copy order at the three table entries, and failure and unwind
  behaviour at all sites, are unchanged and untested.

The definition's unit does not build for a host test, and a windows-x64
program that contains it does not link, so no test executes the constructor.
The evidence for this change is the rebuilt windows-x64 objects, the composed
archive and the complete links.

No generated data names the constructor. No archive member is added, removed
or reordered. One archive member changes, `blk_00c40000_od.cpp`: it no longer
defines the constructor and requires it instead.
