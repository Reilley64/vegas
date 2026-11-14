# One provider of the navmesh index array copy

VEGAS-65 asks for coherent navmesh grid, record and array storage with genuine
construction, copying and retirement. This change is the bounded first part:
`SA00694f80::FUN_00694f80(DA00694f80*)` now has one definition. Everything
else on the ticket is listed under "Not covered".

## The copy

`SA00694f80::FUN_00694f80` is the function at `0x00694f80`. `build/units.json`
lists it once as a function, 93 bytes, in the unit
`src/fallout_shared/pathfinding/navmesh_loadsave.cpp`. That definition sizes
the destination array to the source's count through `0x005eee80` and then
copies the 16-bit elements in ascending order.

`src/staging/blk_00680000_od.cpp` used to define the same name a second time
with an empty body and no address tag. The recipe gives that unit no function
at `0x00694f80`. The unit's symbol table binds the name to `0x00694f80`, as a
name the unit requires. The empty body was a placeholder for the callee of the
grid copy `NavMeshGrid::FUN_0069dd50` (`0x0069dd50`), which the recipe lists as
a function of that unit, 365 bytes. The placeholder is removed. The unit keeps
its declaration, and in the windows-x64 object `FUN_0069dd50` now calls the one
definition.

The recipe records no call edges. That the function at `0x0069dd50` calls
`0x00694f80` is inferred from the unit's symbol row for the name and from the
body tagged `0x0069dd50`, which calls it once per grid cell.

## Names and requirers

The recipe binds one name to `0x00694f80`, in two units, and no other name to
that address. Both objects emit it.

| Unit | Recipe row | Object at the tip | Object now |
| --- | --- | --- | --- |
| `navmesh_loadsave.cpp` | function, 93 bytes; symbol `0x00694f80` | defines | defines |
| `blk_00680000_od.cpp` | symbol `0x00694f80` only | defines (1 byte) | requires |

No other archive member and no test object names it. Call sites in source:

| Caller | Unit | Calls |
| --- | --- | --- |
| `NavMesh::CopyNavMeshDataTo` (`0x006942e0`) | `navmesh_loadsave.cpp` | three: the index list and the two additional lists |
| `NavMeshGrid::FUN_0069dd50` (`0x0069dd50`) | `blk_00680000_od.cpp` | one per grid cell |

`CopyNavMeshDataTo` also requires `FUN_0069dd50`, so the grid copy is reached
from it. `navmeshobstacletask.cpp` is the only object that requires
`CopyNavMeshDataTo`.

Two other recipe names contain `DA00694f80` and are not this function. The
recipe binds `fnv_00692950::DA00694f80::SetSize` to `0x005eee80` and
`fnv_0069da40::DA00694f80::DA00694f80()` to `0x006917d0`. They are required
names with no definition and are not changed here.
`include/fnv/decl/SA00694f80.h` declares the function a third time; no source
file includes it.

Both definitions were function-level sections that allow no duplicate, which
is why the linker reported them. Across the 2,223 archive members no name
matching this function, its classes, its callees `0x005eee80` and `0x005eeda0`
or its caller `0x0069dd50` has two definitions that the linker may choose
between.

## Behaviour of the grid copy

Measured from the windows-x64 objects of the tip and of this change.

Before, `FUN_0069dd50` retired the destination's old array through
`0x0069d2d0`, copied the 36 bytes of grid header, allocated `count * 24 + 8`
bytes, stored the element count in the first 8 and the array pointer at `+40`,
and returned. The empty body was inlined, so no cell was copied. No element was
constructed either: the unit's `BSSimpleArray<unsigned short, 1024>`
constructor is also an empty body. The destination's cells were left as the
allocator returned them.

Now it does the same and then calls `0x00694f80` once per cell, with a stride
of 24 bytes on both arrays. The 89-byte definition is unchanged from the tip.

No program reaches it today. The game executable that links lazily contains
15 archive members; neither unit is among them, nor are `bssimplearray.cpp`,
`navmesh_util.cpp` or `navmeshobstacletask.cpp`. 54 of the 55 test executables
link, and none contains any of the five. The one that does not link,
`runtime_havok_worker_pool_test`, loads both units, which is how it reported
this duplicate. `blk_00680000_od.cpp.obj` needs 85 names that no archive member
defines, `navmesh_loadsave.cpp.obj` 53 and `navmeshobstacletask.cpp.obj` 30.

Calling it would not be safe yet, before or after this change. See the next
section.

## Storage each caller gives the copy

Sizes and offsets are measured on windows-x64 from each unit's own
declarations, compiled with that unit's command. The accesses are read from
the rebuilt objects.

The definition reads 4 bytes at `+16` (count) and 8 bytes at `+8` (buffer) of
the source. It passes the destination to `0x005eee80`, which reads a table
pointer at `+0`, a buffer pointer at `+8`, a count at `+16` and a capacity at
`+20`, calls table entry 1 when it has to allocate, and writes `+8`, `+16` and
`+20`. The highest write is 4 bytes at `+20`, so each side needs 24 bytes.
Elements are then stored through `0x005eeda0`, which reads the buffer at `+8`.

| Call | Unit | Element declared | Bytes | Fits | Fields agree |
| --- | --- | --- | --- | --- | --- |
| three lists in `CopyNavMeshDataTo` | `navmesh_loadsave.cpp` | table `+0`, buffer `+8`, count `+16`, capacity `+20` | 24 | yes | yes |
| grid cells in `FUN_0069dd50` | `blk_00680000_od.cpp` | pointer `+0`, three 32-bit words at `+8`, `+12`, `+16` | 24 | yes | no |

`navmesh_loadsave.cpp` declares the copy's own classes with 24 bytes, buffer
at `+8` and count at `+16`, which is what its three calls pass.
`blk_00680000_od.cpp` declares them as empty classes of 1 byte and casts each
24-byte cell to them.

So the grid cells are large enough, and no write lands outside a cell. The
defect is what the cells hold:

- The unit declares no table pointer and constructs nothing, so the
  destination cell's table, buffer, count and capacity are whatever the
  allocator returned. The definition would use them.
- Two functions produce grid cells. The grid's producer `0x0069d800` in the
  same unit allocates the same way and constructs nothing. The record loader
  `0x0069da40` in `tesform.cpp` allocates an array of its own 24-byte cell
  class, constructs each cell through a constructor name that no object
  defines, and sizes each cell through `0x005eee80`. Inference, not a recorded
  fact: one of the two supplies the source of a grid copy. The recipe records
  no call edges.

`0x005eee80` takes one of four paths on the destination. The count it is given
is the source's count word; the capacity, count and buffer are the
destination's own words.

| Condition | What `0x005eee80` does |
| --- | --- |
| count above capacity, capacity 0 | calls entry 1 of the table at the cell's `+0` and stores the result as the buffer |
| count above capacity, capacity not 0 | calls `0x005ef6a0`, which calls table entry 3, or entry 1 followed by a copy from the old buffer and `0x006a8500` on it; entry 1 alone when the buffer is null |
| count 0, buffer not null | calls `0x0072ba80` on the buffer, then `0x006a8500`, which calls table entry 2 with the buffer |
| otherwise | constructs or destroys 2-byte elements in the existing buffer |

On a cell that was never constructed, each path calls through, frees through
or writes through words the allocator left.

The previous tip was not safe either. The retirer `0x0069d2d0` reads the array
pointer at `+40` of the grid. When the count stored in front of the array is
not zero, it calls through the first word of cell 0. `0x0069dd50` calls the
retirer on its destination before anything else, and both `0x0069d800` and
`0x0069dd50` store the cell count in front of an array of unconstructed cells.
So a copy into a grid that already held cells called through an uninitialised
word at retirement. This change moves the first such use from retirement into
the copy.

The staging unit's symbol rows bind
`BSSimpleArray<unsigned short, 1024>::BSSimpleArray()` to `0x006917d0`. The
recipe lists `0x006917d0` as a 35-byte function of `navmesh_util.cpp`, defined
there as `FUN_006917d0(int**)`. It stores the address of the table
`0x0106abe4` at `+0` and calls `0x00692290` with two zero arguments, which on
windows-x64 zeroes `+8` to `+0x17` and does nothing else. Inference from the
symbol rows, not a recorded edge: that function is the cell constructor the
staging unit's empty placeholder stands for. `tesform.cpp` binds its own cell
constructor name to the same address.

The grid itself is 48 bytes with the array pointer at `+40` in
`blk_00680000_od.cpp`, in `navmesh_loadsave.cpp` and in the retirer's unit
`navmesh.cpp`.

## Not covered

These were open before this change and remain open.

- Construction of the grid cells. `BSSimpleArray<unsigned short, 1024>`'s
  constructor and destructor in `blk_00680000_od.cpp` are empty placeholders.
  `bgsdefaultobjectmanager.cpp.obj` and `navmesh_util.cpp.obj` require them, so
  they are kept. Until the cells are constructed as the array the copy
  expects, the grid copy and the producer `0x0069d800` leave unusable cells.
- One declaration of the cell. The unit's declaration has no table pointer
  and puts its fields at different offsets from the array the copy reads.
- Retirement. `0x0069d2d0` in `navmesh.cpp` deletes the array as elements of
  16 bytes with a virtual destructor, while the grid producer `0x0069d800`
  and the grid copy allocate elements of 24 bytes with none. The record
  loader's 24-byte cell class declares a virtual destructor. The 16 bytes are
  derived from the retirer's own element declaration, `D2d0Elem`. The
  retirer's code holds no stride: it calls the first entry of the table
  cell 0 points to. Allocation and retirement type, stride and domain are not
  reconciled. `blk_00680000_od.cpp` also keeps an unused empty
  `NavMeshGrid::FUN_0069d2d0`.
- Suppliers. `0x005eee80` requires the element entry `0x0072ba80` under two
  names that have no definition.
- The copy's classes. `SA00694f80` and `DA00694f80` are stand-ins for the
  16-bit array; `navmesh_loadsave.cpp` reaches them by casts from its own
  array type. They are not replaced by one shared array type here.
- The record loader's buffer, constructor and destructor, the reallocation
  helper's return type, and the out-of-grid query, all named on the ticket.
- The unused header `include/fnv/decl/SA00694f80.h`.

Neither unit compiles for the host, and a windows-x64 test that contains them
does not link, so no test executes the copy. The evidence for this change is
the rebuilt windows-x64 objects, the composed archive and the complete links.

No generated data names the function. No archive member is added, removed or
reordered. `build/units.json` is unchanged: no name in it changed.
