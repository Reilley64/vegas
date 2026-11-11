# The navmesh index array constructor at its owner

VEGAS-65 asks for coherent navmesh grid, record and array storage with genuine
construction, copying and retirement. `docs/navmesh-index-array-copy.md` is its
first part. This is the second: the constructor of the grid cell, the function
at `0x006917d0`, now has its own name and one definition, and two declarations
that gave it 16 bytes give it 24. The third part gives the destructor at
`0x00691800` its name, described under "The destructor at its owner".
Everything else on the ticket is listed under "Not covered".

## The constructor

`build/units.json` lists `0x006917d0` once as a function, 35 bytes, in the unit
`src/fallout_shared/pathfinding/navmesh_util.cpp`. The row was spelled as a
free function, `FUN_006917d0(int**)`. The same unit's symbol table binds
`BSSimpleArray<unsigned short, 1024>::BSSimpleArray()` to the address, and so
does the symbol table of `src/staging/blk_00680000_od.cpp`. So the recipe
itself says what the function is: the default constructor of the array of
16-bit indices.

Measured on the windows-x64 object, the body does three things.

| Write | Bytes | By |
| --- | --- | --- |
| the address of the table `0x0106abe4` at `+0` | 8 | the body |
| zero at `+8` to `+0x17` | 16 | `0x00692290`, called with two zero arguments |
| returns the object's address | | the body |

`0x00692290` is defined in `blk_00680000_od.cpp`. With two zero arguments it
stores the 16 zero bytes and returns; it calls nothing. With other arguments
it calls entry 1 of the table and `0x005ef650`. The constructor never passes
other arguments.

So the constructor needs 24 bytes: a table pointer, a buffer pointer and two
32-bit counts. These are the fields `0x005eee80` reads when the copy sizes a
cell: table at `+0`, buffer at `+8`, count at `+16`, capacity at `+20`.

The table `0x0106abe4` is legacy generated data. It has four entries:
`0x0069d9a0`, `0x00691870`, `0x006db090` and `0x006918a0`.

## The change

1. In `navmesh_util.cpp` the body tagged `0x006917d0` is now the definition of
   `BSSimpleArray<unsigned short, 1024>::BSSimpleArray()`, on the unit's own
   24-byte declaration of the template. The instructions and relocations are
   the same as before; only the name of the function differs. The free
   function name is gone. No object required it.
2. `blk_00680000_od.cpp` used to define the constructor's name with an empty
   body and no address tag. That body is removed; the declaration stays.
3. The recipe's function row at `0x006917d0` carries the constructor's name,
   and so does the symbols key at that address in
   `bgsdefaultobjectmanager.cpp`, which bound the free function's name. The
   address, the size and the unit are unchanged. Every other row is
   unchanged. See "Names for the address".
4. Three declarations of the cell get the four fields the constructor writes.
   See "Storage each requirer gives the constructor".

The second step follows the ruling on bounded placeholder removal. The
removed body has no function row and no address tag. Both units whose symbol
table has the name bind it to `0x006917d0`. The kept definition is that
address's function, in the unit with the function row. No other body remains
under the name, inline or not.

## Names for the address

The recipe binds seven names to `0x006917d0`, in eight units.

| Unit | Name in the recipe | The windows-x64 object |
| --- | --- | --- |
| `navmesh_util.cpp` | the function row; `BSSimpleArray<unsigned short, 1024>::BSSimpleArray()` | defines the constructor; required it before |
| `blk_00680000_od.cpp` | `BSSimpleArray<unsigned short, 1024>::BSSimpleArray()` | requires the constructor; defined the empty body before |
| `bgsdefaultobjectmanager.cpp` | `BSSimpleArray<unsigned short, 1024>::BSSimpleArray()`; `FUN_006917d0(int**)` before | requires the constructor |
| `navmeshpovsearch.cpp` | `Words::Words()` | requires that name; no definition |
| `pathfind.cpp` | `TriangleIndices::TriangleIndices()` | requires that name; no definition |
| `tesform.cpp` | `fnv_0069da40::DA00694f80::DA00694f80()` | requires that name; no definition |
| `blk_00c40000_od.cpp` | `FUN_006917d0_Arr::FUN_006917d0_Arr()` | requires that name; no definition |
| `blk_006a0000_od.cpp` | `FUN_006917d0(int**)`, twice, with two calling conventions | names nothing at this address |

The ruling of 2026-11-11 on respelling a function row requires every symbols
key of the old name to be respelled in the same change or left honestly
undefined. Two units had a key of the free function's name, and each is
decided by the same question: does its object require either spelling at the
address?

- `bgsdefaultobjectmanager.cpp`: its object requires the constructor, under
  the constructor's name, three times in `NavMesh::NavMesh()`. Its key is
  respelled to the constructor's name, address kept. Before, the binding of
  those calls to `0x006917d0` was an inference from the key of the free
  function. Now the recipe records it.
- `blk_006a0000_od.cpp`: its object names neither spelling. Its cdecl key
  stays. It binds a name that no object defines or requires, so the name
  stays undefined and nothing depends on it. The unit's fastcall key for
  `FUN_006917d0(int**)` is a different mangled name and stays as well.

Across the 2,224 archive members, three objects name the constructor: one
defines it and two require it. Before, `blk_00680000_od.cpp.obj` defined it
and the two others required it.

## Behaviour of the two grid producers

Measured from the windows-x64 objects of the tip and of this change.

`blk_00680000_od.cpp` holds the two functions that allocate grid cells:
`0x0069d800`, which builds a grid, and the grid copy `0x0069dd50`. Both
allocate `count * 24 + 8` bytes, store the count in the first 8 and keep the
array pointer.

Before, the empty constructor was expanded in line, so neither function wrote
anything to a cell. Now each calls the constructor once per cell, with a
stride of 24 bytes, before it stores the array pointer. Each cell then holds
the table pointer, a null buffer, and zero for count and capacity.

This closes the hazard that the first part recorded for the copy. When
`0x0069dd50` passes a destination cell to `0x00694f80`, `0x005eee80` finds a
capacity of zero and a table pointer, and calls table entry 1 to allocate.
The retirer `0x0069d2d0` finds a table pointer in cell 0.

Both functions gain cleanup code for a constructor that throws: the array is
freed. Destroying the cells built so far emits no call, because the empty
destructor in this unit is expanded in line to nothing. The cleanup calls only
the sized `operator delete[]`. The empty destructor is described under "Not
covered".

One caller in `navmesh_util.cpp` changes as well. `NavMesh::AddDoorObstacle`
constructs an automatic array and used to call the empty body of
`blk_00680000_od.cpp`. Now the constructor is defined in the same unit and
the compiler expands it in line: the function stores the table and calls
`0x00692290` with two zero arguments. Nothing else in the function changes.

## Storage each requirer gives the constructor

Sizes and offsets are measured on windows-x64 by the compiler, from each
unit's own declaration with that unit's command. Allocation sizes are read
from the rebuilt objects.

| Unit | Class the unit constructs | Bytes before | Bytes now | Where |
| --- | --- | --- | --- | --- |
| `navmesh_util.cpp` | the array, from the unit's template | 24 | 24 | automatic arrays and members |
| `blk_00680000_od.cpp` | the array, from the unit's specialisation | 24 | 24 | grid cells, `count * 24 + 8` |
| `navmeshpovsearch.cpp` | `Words` | 16 | 24 | one automatic object in `0x0069e3b0` |
| `blk_00c40000_od.cpp` | `FUN_006917d0_Arr` | 16 | 24 | one allocation in `0x00c4db20` |
| `pathfind.cpp` | `TriangleIndices` | 24 | 24 | one automatic object |
| `tesform.cpp` | `fnv_0069da40::DA00694f80` | 24 | 24 | grid cells of the record loader `0x0069da40`, `count * 24 + 8` |
| `bgsdefaultobjectmanager.cpp` | the array, from the unit's template | 16 | 16 | three members of its `NavMesh` |

`Words` and `FUN_006917d0_Arr` were declared as four 32-bit words, the
size the array has in the original release. Each now declares the table
pointer, the buffer pointer and the two counts. Their constructors keep their
own names, which no object defines. In `blk_00c40000_od.cpp` the allocation
passes 24 to `operator new` instead of 16. In `navmeshpovsearch.cpp` the one
function that holds a `Words` has a larger frame and is otherwise the same.
That function also passes the object to `0x0069a830` in `navmesh_util.cpp` as
the array, which clears it and appends to it.

`blk_00680000_od.cpp` declared its 24 bytes as one pointer and three 32-bit
words with no table pointer. The fields are private and nothing reads them.
They now have the constructor's layout. The object is byte-identical.

`pathfind.cpp` and `tesform.cpp` already give 24 bytes and are not changed.
`tesform.cpp` declares its cell with a virtual destructor, so the compiler
puts its own table pointer where the constructor stores `0x0106abe4`.

`bgsdefaultobjectmanager.cpp` is not repaired. Its `NavMesh` declares every
array as four 32-bit words, and its maps and its grid in the same way. The
three index arrays sit at `+0x98`, `+0xb8` and `+0x108` of that class, each
followed directly by another member. `NavMesh::NavMesh()` (`0x0068eb80`)
constructs the members in declaration order, so the constructor's last 8
bytes land in the first 8 bytes of the next member before that member is
constructed. That member's constructor is called next: the map at `+0xa8`,
the grid at `+0xc8` and the array of avoid nodes at `+0x118`. None of the
three has a definition in the archive, so whether each overwrites those 8
bytes is not measured. No write leaves the object. Before this change the
three calls reached the empty body and wrote nothing.

This is benign today: nothing outside the object is written. It is latent
until one shared declaration of `NavMesh` exists. Giving this one member type
its real size would move every later member of a class whose other members
are still the 32-bit view, so the class needs that shared declaration first.

No program reaches any of these sites. The game executable that links lazily
contains 15 archive members, and none of the seven units is among them. Each
of the seven objects needs names that no archive member defines.

## Why the array has no shared header yet

The compiler sees these declarations of the array in the units that name it.

| Declaration | Units | Bytes | Fields | Members besides the fields |
| --- | --- | --- | --- | --- |
| template in `navmesh_util_decls.h` | `navmesh_util.cpp` | 24 | table, buffer, count, capacity | constructor, destructor, eight more |
| template in `navmesh_loadsave_layout_support.h` | `navmesh_loadsave.cpp` | 24 | table, buffer, count, capacity | eight, no constructor, no destructor |
| template in `include/layout_support.h` | `pathbuilder.cpp` | 24 | table, buffer, count, capacity | five, no constructor, no destructor |
| specialisation in `navmesh.cpp` | `navmesh.cpp` | 24 | compiler table pointer, buffer, count, capacity | virtual destructor |
| specialisation in `blk_00680000_od.cpp` | that unit | 24 | table, buffer, count, capacity | constructor, destructor |
| specialisation in `blk_006a0000_od.cpp` | that unit | not laid out | none | none; nothing uses it |
| template in `bgsdefaultobjectmanager_nav.h` | `bgsdefaultobjectmanager.cpp` | 16 | four 32-bit words | constructor, destructor |
| template in `navmeshpovsearch_decls.h` | `navmeshpovsearch.cpp` | 16 | four 32-bit words | two copy members |

`bgsragdoll.cpp`, `pathinglocation.cpp` and `loadingmenu.cpp` name the array
only as the target of a pointer cast, each from a template of its own; the
compiler lays out no array there. `pathfind.cpp`, `tesform.cpp` and
`blk_00c40000_od.cpp` construct the array under stand-in classes and do not
name it.

A shared declaration of the array has to declare its destructor, because
units destroy the array. When the constructor moved to its owner, the
destructor had no owner. The only body under its name was an empty one in
`blk_00680000_od.cpp`, with no address tag, and no row of the recipe bound
the name to an address, so the ruling on placeholder removal did not cover
it. A header that declared the destructor then would have bound every unit
that moved onto it to the empty body. A header without it would stop those
units from destroying the array. So the declarations stayed where they were,
and that change gave no unit a new requirement for the destructor's name.

The virtual destructor now has its owner; see "The destructor at its owner".
The empty body is still there, under the non-virtual spelling, and the
declarations still stay where they are.

## Not covered

These were open before this change and remain open.

- The destructor's other spellings. "The destructor at its owner" lists
  what stays open after it.
- Retirement of the grid. `0x0069d2d0` still deletes the cells as its own
  16-byte element class. `0x0069d9a0` passes an element size of 16 to the
  array destruction helper, while the cells are 24 bytes on windows-x64.
  `blk_00680000_od.cpp` keeps an unused empty `NavMeshGrid::FUN_0069d2d0`.
- The four stand-in names for the constructor: `Words`, `TriangleIndices`,
  `fnv_0069da40::DA00694f80` and `FUN_006917d0_Arr`. Each needs the array
  declared, with its destructor, in its unit.
- `bgsdefaultobjectmanager.cpp`, as described above: three 16-byte index
  arrays, each followed by a member that receives the constructor's last 8
  bytes.
- A 32-bit-width view of the same array in `src/unmapped/bssimplearray.cpp`.
  `FUN_00691820_arr`, the receiver of `Append` at `0x00691820`, declares an
  `int` first field and then the buffer pointer. The buffer lands at `+8`
  only because the pointer is aligned to 8 bytes; the table pointer the
  constructor stores at `+0` is 8 bytes wide.
- A second transcription of the constructor's body. `NewShorts086` in
  `blk_00c40000_od.cpp` stores the same table and calls `0x00692290` in line.
  `0x0069ada0`, the constructor with two counts, is defined in
  `blk_00680000_od.cpp` under a stand-in name and required by
  `blk_006a0000_od.cpp` as `FirstArray::FirstArray(int, int)`.
- `0x00692290` requires `0x005ef650` with an integer first parameter; the
  definition in `bssimplearray.cpp` takes a pointer. The constructor's call
  does not reach it.
- Everything else `docs/navmesh-index-array-copy.md` lists: the copy's
  stand-in classes, the element entry `0x0072ba80`, the record loader's
  buffer, the reallocation helper's return type, the out-of-grid query.

The four units changed here do not compile for the host, and a windows-x64
test that contains them does not link, so no test executes the constructor.
The evidence for this change is the rebuilt windows-x64 objects, the composed
archive and the complete links.

No generated data is changed. No archive member is added, removed or
reordered.

## The destructor at its owner

The coordinator admitted the function row `0x00691800` as the array's
destructor in its virtual spelling,
`BSSimpleArray<unsigned short, 1024>::~BSSimpleArray()` declared `virtual`.
This third part carries that out. It is one commit, for one address.

### The function and its table

`build/units.json` lists `0x00691800` once as a function, 30 bytes, in the
unit `src/fallout_shared/pathfinding/navmesh.cpp`. The row was spelled as a
free function, `FUN_00691800(GlobalObject_00869f00*)`. Its body stores the
address of the table `0x0106abe4` at `+0` and calls `0x008454f0` with
`true`, which clears the array.

The table is in the generated data, in `vtables_0106.cpp`, with the four
entries listed under "The constructor". Entry 0, `0x0069d9a0`, is a
106-byte function row of `blk_00680000_od.cpp`. With bit 2 of its argument
set it destroys each element of an array through `0x00691800`, and otherwise
one object. With bit 1 set it then frees the memory. It is the vector
deleting destructor, so the destructor is virtual and its slot is 0. The
constructor `0x006917d0` stores the same table.

`navmesh.cpp` already declares the array as a specialisation with one
virtual function, the destructor, which is slot 0 there as well. The change
uses that class. It adds no field, no table and no other virtual function.

### The change

1. In `navmesh.cpp` the body tagged `0x00691800` is now the definition of
   the virtual destructor that the unit's specialisation declares. Its two
   statements are unchanged. `this` takes the place of the first parameter,
   held in a local of that parameter's type.
2. The recipe's function row at `0x00691800` and `navmesh.cpp`'s symbols key
   at that address carry the destructor's name,
   `??1?$BSSimpleArray@G$0EAA@@@UAE@XZ`. The address, the size and the unit
   are unchanged. Every other row is unchanged.

No generated data is changed. No archive member is added, removed or
reordered.

### Names for the address

Seven units have a symbols key of the free function's name at
`0x00691800`. The ruling of 2026-11-11 on respelling a function row
requires each key to be respelled in the same change or left honestly
undefined. As for the constructor, each is decided by what its
windows-x64 object names.

| Unit | Keys | The windows-x64 object | Decision |
| --- | --- | --- | --- |
| `navmesh.cpp` | the function row; cdecl key | defined the free function and required the virtual destructor; now defines the destructor | respelled |
| `blk_00680000_od.cpp` | cdecl and fastcall keys | requires the free function's name | kept |
| `navmesh_util.cpp` | cdecl key | requires the non-virtual spelling of the destructor, not the free function | kept |
| `navmeshpovsearch.cpp`, `pathfind.cpp`, `tesform.cpp` | cdecl key | names neither spelling | kept |
| `blk_006a0000_od.cpp` | cdecl and fastcall keys | names neither spelling | kept |

`blk_00680000_od.cpp` requires the free function's name in `0x0069d9a0`,
twice: once to call it for one object, once to pass its address to the
helper that destroys the elements of an array. That function's receiver is
a stand-in class of the unit. The unit's own specialisation of the array
declares a destructor that is not virtual, with the empty body. So the unit
cannot name the virtual destructor without changing its copy of the class,
which waits for a shared declaration. Its key stays, and the name is now
undefined.

### What the objects show

Measured on the windows-x64 objects of the tip and of this change. Only
`navmesh.cpp.obj` differs.

The ruling on respelling a function row asks for an object that is equal
once names are respelled. This object is not, so the change does not rest on
that clause. It rests on ruling 2026-11-11 (3), which accepts an object
proof in which each difference is listed and justified, and on the
coordinator's admission of the virtual spelling. Each difference below is a
consequence of that spelling.

- The destructor stores the same table at `+0` and calls `0x008454f0` with
  the same arguments as the free function did. A destructor is `noexcept`,
  and `Clear` is not, so the call now sits in a frame with a handler that
  calls `std::terminate` if it throws. Before, the function ended with a
  jump to `0x008454f0`.
- The compiler emits what a class with a defined virtual destructor gets:
  its own table for the class, with one entry; the scalar deleting
  destructor, which runs the destructor and frees 24 bytes; the vector
  deleting destructor, which the compiler makes a weak name for the scalar
  one; and the class's type information. Nothing stores the compiler's
  table. The destructor's own store of it is overwritten by the store of
  `0x0106abe4` and is not emitted, and the constructor stores `0x0106abe4`.
  No relocation in the object refers to the compiler's table. No other
  archive member defines any of these names.
- The out-of-line destructor has no caller in the archive at this commit.
  No other member requires its name, and in `navmesh.cpp.obj` the
  destructor of `0x0068ed70` and the scalar deleting destructor expand it
  in line. The scalar deleting destructor is reached only through the
  compiler's table, which nothing refers to.
- `fnv_0068ed70::FUN_0068ed70::~FUN_0068ed70()` (`0x0068ed70`) destroys
  three members of the array type, at `+0x88`, `+0xb0` and `+0x108`. Each
  used to be a call to the destructor. The destructor is now defined in the
  unit and the compiler expands it in line: each stores `0x0106abe4` at the
  member and calls `0x008454f0` with `true`, in the same order. The
  function's one handler that calls `std::terminate` becomes four.

### The exception specification

The destructor keeps the specification it gets by default, `noexcept`. The
other choice, `noexcept(false)` on the declaration and the definition, was
compiled for `navmesh.cpp` and not committed. With it the code of
`0x00691800` is equal to the free function's, ending with a jump to
`0x008454f0`. But it changes the specification of
`fnv_0068ed70::FUN_0068ed70::~FUN_0068ed70()` (`0x0068ed70`), whose class
has a member of the array type, to `noexcept(false)`. Its bases `Base5a`
and `EBase` declare destructors that are `noexcept`, so the override is
looser than the function it overrides. That is ill-formed in ISO C++;
clang-cl accepts it as a Microsoft extension and warns
(`-Wmicrosoft-exception-spec`, at the declaration of `~FUN_0068ed70()` in
`navmesh.cpp`). It also changes the code and exception tables of
`~FUN_0068ed70()`, and gives the scalar deleting destructor of
`FUN_0068ed70` exception tables that it does not have now.

The windows-x64 object of the free function shows that it let an exception
from `0x008454f0` propagate, because it ended with a jump. The repository
does not show how the original release behaved when `0x008454f0` throws: it
holds no record of the exception handling of `0x00691800` or `0x0068ed70`.
The choice is to be decided again when `0x0069d9a0` binds to the
destructor.

### The binding this step cuts

Before this change `0x0069d9a0`, entry 0 of `0x0106abe4`, reached the real
body of `0x00691800` through the free function's name, which
`navmesh.cpp.obj` defined. That binding was correct. After it the name is
defined nowhere, so `0x0069d9a0` reaches no body. The next step, one shared
declaration of the array with all four slots of the table, moves
`blk_00680000_od.cpp` onto the virtual destructor and restores the binding.

### Conditions until the four slots are declared

- Nothing in `navmesh.cpp` may construct the array until all four slots
  are declared. A constructor compiled in the unit would store the
  compiler's table of one entry, not `0x0106abe4`.
- When a declaration with a table of four entries lands, `navmesh.cpp`
  moves onto the shared header in the same commit. Otherwise two members
  would emit the class's table, with one entry and with four, and the
  linker would keep the larger of the two by its COMDAT rule.
- The scalar deleting destructor frees 24 bytes with the global sized
  `operator delete`, while `0x0069d9a0` frees through `0x00401030`
  (`FUN_00401030`). It must not become reachable before slot 0 binds to
  `0x0069d9a0`.
- The `reinterpret_cast` of `this` to `GlobalObject_00869f00*` in the
  destructor goes away in the step that declares the four slots.

### Links

In the forced link with no error limit, 35,185 names are undefined before
and after. The virtual destructor that `navmesh.cpp.obj` required leaves
the list. The free function's name that `blk_00680000_od.cpp.obj` requires
enters it. The other three cells are unchanged, and so are duplicates,
imports, the 15 members that the lazy link loads, and the 525 names with
differing definitions. The change moves one name and adds one, so the
count of undefined names does not fall.

### What stays open

- The non-virtual spelling. `blk_00680000_od.cpp` still defines
  `BSSimpleArray<unsigned short, 1024>::~BSSimpleArray()` with an empty
  body, and `navmesh_util.cpp.obj` and `bgsdefaultobjectmanager.cpp.obj`
  require it. Arrays they destroy are not cleared. All three objects move
  onto the virtual spelling together with a shared declaration of the
  array.
- `0x0069d9a0` requires the free function's name, which is now undefined.
  It still passes an element size of 16.
- The table's entries 1 to 3, `0x00691870`, `0x006db090` and `0x006918a0`,
  are not declared as virtual functions of the class in `navmesh.cpp`, so
  the compiler's table has one entry where the generated one has four. A
  shared declaration of the array has to declare all four slots.
- No test runs the destructor. `navmesh.cpp` compiles for the host, but the
  host game library it belongs to does not build, so no host test that
  links that library builds. The other host tests do not contain the unit.

In the forced link with no error limit, seven undefined names are still a
constructor or destructor of this array under a stand-in's name:

- `FUN_006917d0_Arr::FUN_006917d0_Arr()`
- `TriangleIndices::TriangleIndices()` and its destructor
- `Words::Words()` and its destructor
- `fnv_0069da40::DA00694f80::DA00694f80()` and its virtual destructor

They leave the list only when `Words`, `TriangleIndices`, `DA00694f80` and
`FUN_006917d0_Arr` move onto a shared declaration of the array.
