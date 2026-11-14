# Hacking menu element release binding

VEGAS-72 removes the second definition of `FUN_00702220::~FUN_00702220()`.
`src/fallout/interface/menus/hackingmenu.cpp` defined it with an empty body.
The one definition left is the function at 00702220 in
`src/staging/blk_00700000_od.cpp`, and the class now has one declaration,
`include/fnv/decl/FUN_00702220.h`, used by every unit that names it.

That header already existed and declared the class empty; this change gives
it the pointer member. Three units include it: `hackingmenu.cpp`,
`blk_00700000_od.cpp` and `blk_00840000_od.cpp`. Before, only the last did.

This is the binding only. It is not the repair of the hacking menu arrays; see
"Not covered".

A second change, measured on b93461c52, is described under "Element construction":
the element's constructor now zeroes both words, and `ElemArray::CopyFrom`
uses the same element class as `FUN_00768810`. The sections before it describe
the first change and keep its wording, except the `ArrElem` row of the
recipe table and the two lists at the end.

A third change, measured on 3a60c9e78, is described under "Array
retirement": 007687d0 deletes the array with `delete[]` of
`HackingArrayElement` instead of the 32-bit array path of 007021b0. The
sections before it keep their wording, except the 007687d0 entry of
"Producers and retirers of the element" and the list at the end.

A fourth change, measured on 6eafe8f01, is described under "The row at
007021b0": the hand-written body of `DestroyOrFree` is removed. The sections
before it keep their wording, except the first item of "What stays open"
under "Array retirement" and the second item of "Not covered".

## What the recipe records

`build/units.json` is the authority for addresses.

| Unit | Entry | Address | Size |
| --- | --- | --- | --- |
| `src/staging/blk_00700000_od.cpp` | function `FUN_00702220::~FUN_00702220()` | `0x00702220` | 33 |
| `src/fallout/interface/menus/hackingmenu.cpp` | function `FUN_007021b0_cls::DestroyOrFree(unsigned int)` | `0x007021b0` | 106 |
| `src/fallout/interface/menus/hackingmenu.cpp` | symbol `FUN_00702220::~FUN_00702220()` | `0x00702220` | |
| `src/fallout/interface/menus/hackingmenu.cpp` | symbol `FUN_007021b0_cls::FUN_00702220()` | `0x00702220` | |
| `src/fallout/interface/menus/hackingmenu.cpp` | symbol, the vector deleting destructor of `HackingArrayElement` (`ArrElem` before the second change) | `0x007021b0` | |
| `src/staging/blk_00840000_od.cpp` | symbol `FUN_00702220::~FUN_00702220()` | `0x00702220` | |

The recipe lists 00702220 as a function of the staging unit only. The hacking
menu unit lists it as a name it requires, not as one of its 55 functions. The
empty body in `hackingmenu.cpp` carried no address. It was a placeholder that
let the unit compile, not a second function: both units bound the name to the
same address.

The symbol tables of `src/fallout_shared/tesobject.cpp` and
`src/staging/blk_00ac0000_od.cpp` also bind the name to `0x00702220`. Neither
source nor either rebuilt object refers to it. Those entries are left as they
are.

## The function

00702220 reads the pointer in the first word of its object and passes it to
`FUN_00401030`, the engine heap release. It changes nothing else and does not
clear the pointer.

`FUN_00702220` is declared once, with that one pointer member. The hacking menu
element `HackingArrayElement` derives from it and holds the second word itself.
Its size and the offset of both words are unchanged.

## Every unit that requires the function

Read from the rebuilt windows-x64 objects before and after the change.

| Unit | Before | After |
| --- | --- | --- |
| `blk_00700000_od.cpp` | defines it | defines it; object unchanged |
| `hackingmenu.cpp` | defines the empty body; the call in `DestroyOrFree` compiled to nothing | requires it; `DestroyOrFree` calls it |
| `blk_00840000_od.cpp` | requires it, from `FUN_008456c0` | the same; object unchanged |

No other object defines or requires the name. No generated data names it.

`FUN_008456c0` (008456c0) calls the function on the address four bytes past its
argument. Its one requirer is the destructor entry 00845690 in
`nitmapbase.inl`.

## Behaviour change

`FUN_007021b0_cls::DestroyOrFree` (007021b0) with mask 2 of its flags clear
destroys one element. Before, that released nothing and then freed the element
when mask 1 was set. Now it first releases the buffer the element points to.

This scalar path has no caller in source. The one caller of `DestroyOrFree`,
`C7687d0::FUN_007687d0`, passes 3, and the compiler inlines the array path
into it. No object requires `DestroyOrFree`.

That 007021b0 calls 00702220 on the scalar path is inferred from the bindings
of unit 466 of `build/units.json`, the unit of `hackingmenu.cpp`: it lists
007021b0 as a function and binds the destructor's name to `0x00702220`. The
recipe records no call edges. This is recovered behaviour of the two
addresses, not a native policy.

The path with mask 2 set, which destroys an array, is not changed.

A link that held both definitions could take either one. This is measured
from the order of the duplicate report in two links of the previous tip: the
link with every archive member named the `hackingmenu.cpp` definition first,
and the worker-pool test link named the staging definition first. Now there
is one definition.

No program that contains either caller links today. The complete game link
does not extract `hackingmenu.cpp.obj` or `blk_00840000_od.cpp.obj`, and the
link with every archive member fails on other duplicate and undefined names.
The worker-pool test link does extract `hackingmenu.cpp.obj` and both staging
objects, and fails on other duplicates. The other 54 test executables link
ordinarily; none of them, and not the game executable, contains any of the
three objects. So no executable changes behaviour with this change.

## Producers and retirers of the element

- `FUN_00768810::FUN_00768810(unsigned int)` (00768810) allocates an array of
  `HackingArrayElement` and sizes each element through 00768920. No object
  requires it.
- `ElemArray::CopyFrom` (0076b0c0) deletes and allocates an array of
  `HackingArrayElement`. Until the second change it used `ArrElem`, a second
  declaration of the same two words whose constructor and destructor had no
  definition.
- `C7687d0::FUN_007687d0` (007687d0) deletes the array in the first word of
  its receiver with `delete[]` of `HackingArrayElement`. Until the third
  change it was the one caller of `DestroyOrFree`, with flags 3. No object
  requires it.
- 00768920 and `STR_0076b200::AssignFrom` (0076b200) release and replace the
  buffer of one element in place.

## Element construction

### What the recipe records

At b93461c52:

| Unit | Entry | Address |
| --- | --- | --- |
| `bssimplelist_h_unit.cpp` | function, the default constructor of `BSSimpleList`, 33 bytes | `0x0096a2d0` |
| `hackingmenu.cpp` | symbol `SL::SL()` | `0x0096a2d0` |
| `hackingmenu.cpp` | symbol `ArrElem::ArrElem()` | `0x0096a2d0` |
| `hackingmenu.cpp` | symbol, the vector deleting destructor of `ArrElem` | `0x007021b0` |
| `hackingmenu.cpp` | function `FUN_007021b0_cls::DestroyOrFree(unsigned int)`, 106 bytes | `0x007021b0` |

`SL` was the name of the element that 00768810 allocates until 653f9bea0
renamed it `HackingArrayElement`. So the key `??0SL@@QAE@XZ` is the earlier
name of the same constructor. The recipe kept the old name and it is left
as it is. So the unit binds a constructor to `0x0096a2d0` for each of its
two array allocations, in 00768810 and in 0076b0c0.

### The element is not a list

The function at `0x0096a2d0` is the list constructor: it sets an item and a
next pointer to null. The original linker gave identical functions one
address, so every constructor that zeroes two words is bound there.
`docs/simple-list-default-constructor.md` has the table of the names bound to
it.

The element is another class that was folded onto that code:

- The recipe gives its vector deleting destructor to 007021b0, a function of
  this unit. The list has no such function. Its destructor is at
  `0x0046ffb0` and removes nodes.
- 007021b0 destroys each element through 00702220, which releases the buffer
  in the first word, and steps 8 bytes per element: two 32-bit words.
- 00768920 stores a length in the second word and allocates that many bytes
  for the first. 0076b200 copies that many bytes. A list keeps a next pointer
  there.

So the constructor is defined in `hackingmenu.cpp`, for
`HackingArrayElement`: it sets the pointer and the length to zero. It
replaces the empty placeholder body, which had no function row and no
address tag. It carries no address tag either, because the function row at
`0x0096a2d0` belongs to `bssimplelist_h_unit.cpp`. Its comment names the
shared address, the form `idvspline.cpp` and `branch.cpp` use for other
folded functions.

### One element class in 0076b0c0

`ArrElem` was a pointer and an `unsigned int`, 16 bytes with the pointer at
0 and the length at 8 by the compiler's layout in this unit. That is the
layout of `HackingArrayElement`, which is `FUN_00702220` with an
`unsigned int`. 0076b0c0 already passed its elements to 0076b200 through a
cast, as 00768810 passes its elements to 00768920. `ElemArray::CopyFrom` now allocates and deletes
`HackingArrayElement`, and `ArrElem` is gone from this unit.
`blk_00680000_od.cpp` declares another class under the global name `ArrElem`
and is not touched.

`delete[]` in 0076b0c0 now destroys each element through
`FUN_00702220::~FUN_00702220()`, the function at 00702220. That is the
function the recipe shows for it: the vector deleting destructor of `ArrElem`
is 007021b0, and 007021b0 destroys through 00702220.

Two recipe keys of the unit follow the source. No address changes.

| Address | Old name | New name |
| --- | --- | --- |
| `0x0096a2d0` | `??0ArrElem@@QAE@XZ` | `??0HackingArrayElement@@QAE@XZ` |
| `0x007021b0` | `??_EArrElem@@QAEPAXI@Z` | `??_EHackingArrayElement@@QAEPAXI@Z` |

An i686 clang-cl compile of the unit emits the first name. Neither that
compile nor the windows-x64 compile emits `??_EHackingArrayElement`, the
vector deleting destructor of the class. So the second key is spelled by
rule: the old key with the class name replaced. It is never link evidence.
No object defines or requires it, so no link can confirm it.

### Behaviour change

- 00768810 zeroes each new element before 00768920 releases its pointer.
  Before, 00768920 released a pointer that nothing had set.
  `FUN_00401030` returns on a null pointer and aborts on a pointer the memory
  manager does not own (`canonical_memory_manager.cpp`).
- 0076b0c0 does the same for the array it allocates. For the array it
  replaces, it releases each element's buffer through 00702220 before it
  releases the array. Before, the element constructor and destructor it
  called were names that no object defined.
- 0076b0c0 loses its C++ exception tables and their cleanup funclet. They
  existed for an element constructor that threw: the funclet destroyed the
  elements already constructed and deleted the new array. The constructor
  is now visible to the compiler and cannot throw.

On windows-x64 the constructor writes 12 of the element's 16 bytes: the
pointer and the 32-bit length. The last four bytes are padding in
`HackingArrayElement`. 00768920 writes the second word through
`FUN_00768920_shell`, where it is pointer-sized, and 0076b200 reads it
through `STR_0076b200`, where it is a `uintptr_t`. Both producers call
00768920 on every element before anything reads it, and the allocation and
the copy take the length as an `unsigned int`. So no path reads the four
bytes before they are written. The three widths of the second word are still
three declarations; see "Not covered".

### Measured links

Windows-x64, built from one export path for b93461c52 and each commit, 2,227
archive members in the same order throughout. Each commit changes one
object, `hackingmenu.cpp.obj`.

| Commit | Names that leave the forced link | Names that enter |
| --- | --- | --- |
| Element constructor | 0 | 0 |
| One element class | 2: `ArrElem::ArrElem()`, `ArrElem::~ArrElem()` | 0 |

The first commit changes the body of a name the object already defined. The
second removes four definitions, all local to `ElemArray::CopyFrom`: its
exception tables and their cleanup funclet. In every link cell the
duplicates, imports and other diagnostics are those of b93461c52, and the
names with differing definitions stay 519.

The game executable links before and after, and its map is the same: it
loads neither `hackingmenu.cpp.obj` nor `bssimplelist_h_unit.cpp.obj`. The
worker-pool test, linked from the same archives, loads both and fails before
and after on undefined names, with no duplicate: the two `ArrElem` names
leave, and four more from the list of topic lists
(`docs/shared-simple-list.md`). The other test executables were not linked
here. So no executable measured here changes behaviour.

## Array retirement

### The pair

The array that 007687d0 deletes and the arrays the unit allocates are one
`new[]` and `delete[]` pair of one element type, in one unit:

- The recipe of `hackingmenu.cpp` binds the vector deleting destructor of
  the element, `??_EHackingArrayElement@@QAEPAXI@Z`, to `0x007021b0`, and
  binds `??_U@YAPAXI@Z` (`operator new[]`) to `0x00401000`,
  `??_V@YAXPAX@Z` (`operator delete[]`) to `0x00401030` and
  `??_M@YGXPAXIHP6EX0@Z@Z`, the compiler's array destructor loop, to
  `0x00ec5fce`. These are the names a 32-bit compiler uses for `new[]` and
  `delete[]` of a class with a destructor.
- The transcription of 007687d0 reads the pointer in the first word of its
  receiver and, when it is not null, calls 007021b0 with flags 3. That is
  the 32-bit compiler's code for `delete[]` of that pointer: flag 2 for an
  array, flag 1 to free it.
- `FUN_00768810` (00768810) and `ElemArray::CopyFrom` (0076b0c0) allocate
  with `new HackingArrayElement[n]` and keep the array in the first word of
  their object. 0076b0c0 already deletes the array it replaces with
  `delete[]` of `HackingArrayElement`.

So 007687d0 now deletes with `delete[]` of `HackingArrayElement`. The
count, the element size and the freed block come from the windows-x64
declaration, as at the allocation.

Read from the windows-x64 object of 3a60c9e78 and of the change:

| | Allocation (00768810) | Deletion (007687d0, after) | Deletion (007687d0, before) |
| --- | --- | --- | --- |
| Call | `??_U@YAPEAX_K@Z` with `16*n+8` bytes | `??_V@YAXPEAX_K@Z` with `16*n+8` bytes | `FUN_00401030` |
| Count | written as 8 bytes at the block start | read as 8 bytes, 8 bytes before the array | read as 4 bytes, 4 bytes before the array |
| Address | the array starts 8 bytes after the block | frees the address 8 bytes before the array | frees the address 4 bytes before the array |
| Elements | 16 bytes apart | `??1FUN_00702220@@QEAA@XZ` on each, last first, 16 bytes apart | passed to `FUN_00ec5fce` with an element size of 8 |

With a count of 0, the deletion destroys nothing and frees the block of 8
bytes. `src/runtime/new.cpp` defines both array operators. In the forced
link of every archive member they resolve to `new.cpp.obj`, which passes
the block to `FUN_00401000` and `FUN_00401030` of
`canonical_memory_manager.cpp`. No archive member defines them.

### Behaviour change

`C7687d0::FUN_007687d0` (007687d0) deletes the array in the first word of
its receiver with `delete[]`. It no longer reaches the array path of
`DestroyOrFree`, which read a 32-bit count four bytes before the array,
stepped 8 bytes and freed a pointer the allocator did not return. No
object requires 007687d0, so no program runs either form.

The check `objects.hacking_array_retirement` of the windows-x64 cross build
(`tools/function-relocations/hacking-array-retirement.tsv`) fails when the
code of 007687d0 refers to `DestroyOrFree`, `FUN_00ec5fce`,
`FUN_007021b0_cls::FUN_00702220` or `FUN_00401030`, or no longer to the
element destructor and the sized array delete. It fails on the object of
3a60c9e78 and passes on the object of the change. The count, the element
size and the size passed are not relocations: they are the instructions in
the table above.

### Measured links

Windows-x64, built from one export path for 3a60c9e78 and the change, 2,227
archive members in the same order. One object differs, `hackingmenu.cpp.obj`,
and in it one function, 007687d0. In each of the four link cells no name
leaves or enters, the duplicates (none), the imports and the other
diagnostics are those of 3a60c9e78, and the names with differing
definitions stay 519. No name is newly defined or gains a content variant. The
one warning of the removed line, an unused expression result, leaves.

### What stays open

- `DestroyOrFree` (007021b0, the function row) kept its transcribed body
  after this change, with no caller. The fourth change removes it; see "The
  row at 007021b0".
- The receiver of 007687d0 is `C7687d0`, an empty class. The unit declares
  the object that holds the array several times: `FUN_00768810`,
  `FUN_007687d0`, `MatrixWrapper`, `grid76a::G7Grid`, `ElemArray` and
  `Struct0076b090`. `FUN_007687d0::~FUN_007687d0()` and
  `grid76a::G7Grid::~G7Grid()` are required and not defined, and the recipe
  binds neither name. Whether 007687d0 is that destructor is not
  established here.
- No test executes the deletion: `hackingmenu.cpp` does not build for a host
  test, and no windows-x64 program that contains it links.

## The row at 007021b0

### The decision

The coordinator ruled on 2026-11-12 that the hand-written body at the
function row 0x007021b0 is removed, because nothing calls it after the third
change. The body transcribed the vector deleting destructor of
`HackingArrayElement` under the stand-in name
`FUN_007021b0_cls::DestroyOrFree(unsigned int)`. The stand-in class, which
had no other member with a body, and the declaration of `FUN_00ec5fce` that
only this body used go with it.

The recipe is not changed. Unit 466, the unit of `hackingmenu.cpp`, keeps
the function row `?DestroyOrFree@FUN_007021b0_cls@@QAEPAXI@Z` at
`0x007021b0`, 106 bytes, and the symbols keys
`?DestroyOrFree@FUN_007021b0_cls@@QAEPAXI@Z` and
`??_EHackingArrayElement@@QAEPAXI@Z` at `0x007021b0` and
`?FUN_00702220@FUN_007021b0_cls@@QAEXXZ` at `0x00702220`. The row is now a
function the compiler emits, with no windows-x64 provider: the windows-x64
compiler emits no vector deleting destructor for the element and writes the
code of each `delete[]` where it is used, as in 007687d0 and 0076b0c0. This
matches the treatment `docs/runtime-library-map.md` gives compiler-emitted
runtime addresses, which have no function row: nothing to map.

`include/fnv/decl/FUN_007021b0_cls.h` declares `DestroyOrFree` too. No file
includes it, before or after this change. It is not touched.

### Before the removal

At 6eafe8f01, read from the source and from the objects of the windows-x64
build. The first two items cover every object: the 2,229 archive members,
the game executable's two objects and the objects of every test executable.
The next two cover the archive members.

- No object requires `?DestroyOrFree@FUN_007021b0_cls@@QEAAPEAXI@Z`.
  `hackingmenu.cpp.obj` defines it.
- `hackingmenu.cpp.obj` is the one object that requires
  `?FUN_00702220@FUN_007021b0_cls@@QEAAXXZ`. No object defines it.
- Five archive members require `FUN_00ec5fce`: `hackingmenu.cpp.obj`,
  `tescondition.cpp.obj`, `blk_00680000_od.cpp.obj`,
  `blk_00b20000_od.cpp.obj` and `blk_00c40000_od.cpp.obj`.
- No archive member defines or requires the vector or scalar deleting
  destructor of `HackingArrayElement`.
- In the source, the body was the one use of `FUN_007021b0_cls` and the one
  definition of its `DestroyOrFree`; nothing called it. The other lines that name
  the address are the comment of 007687d0, the unincluded header, and the
  table of `objects.hacking_array_retirement`, which forbids the names, and
  its description in `tools/function-relocations/README.md`.

### Measured links

Windows-x64, built from one export path for 6eafe8f01 and the change, 2,229
archive members in the same order. One object differs,
`hackingmenu.cpp.obj`. It loses one function, `DestroyOrFree`, and no longer
requires `FUN_007021b0_cls::FUN_00702220()` or `FUN_00ec5fce`. No
other function of the object changes.

| Link cell | Undefined names, before and after | Change |
| --- | --- | --- |
| Lazy, ordinary | 0, 0 | none |
| Lazy, unlimited | 0, 0 | none |
| Forced, ordinary | 20, 20 | none |
| Forced, unlimited | 35,139, 35,138 | `FUN_007021b0_cls::FUN_00702220()` leaves |

In every cell the duplicates (none), the imports and the other diagnostics
are those of 6eafe8f01. Four archive members still require
`FUN_00ec5fce`, so it stays undefined. Per name, every definition in the
archive is the same before and after except the one that goes, `DestroyOrFree`; no name is
newly defined or gains a content variant, and the first definition in
member order is in the same member for every name. The names with differing
definitions stay 519, and the differing-definitions allowlist loses no line.
`objects.hacking_array_retirement` passes. The worker-pool test link, which
loads `hackingmenu.cpp.obj`, fails before and after on undefined names with
no duplicate, and the same name leaves.

### Behaviour change

None in any program. No object called the body, and no program that links
contains `hackingmenu.cpp.obj`.

## Not covered

These were open before these changes and remain open for VEGAS-72.

- `STR_0076b200`, `FUN_00768920_shell` and `HackingArrayElement` are three
  declarations of one element, joined by casts. Their second word is a
  `uintptr_t`, a pointer and an `unsigned int`. They are not merged here.
- The array that 00768810 allocates was retired by 007687d0 with the 32-bit
  count and stride until the third change. The fourth change removes that
  path with the body of `DestroyOrFree`. The array that 0076b0c0 allocates
  is retired by 0076b0c0 itself, with the compiler's own count and stride.
- The recipe key `??0SL@@QAE@XZ` at `0x0096a2d0` of this unit is the earlier
  name of the element constructor. It names nothing in the source now.
- `FUN_008456c0` reaches its receiver through a cast and a four-byte offset
  that is also the 32-bit layout. Its owner has no typed construction.
- Neither `hackingmenu.cpp` nor the staging units build for a host test, and no
  windows-x64 program that contains them links, so no test executes this path.
  The evidence is the rebuilt objects and the complete links.
