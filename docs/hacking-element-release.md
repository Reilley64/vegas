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
- `C7687d0::FUN_007687d0` (007687d0) is the one caller of `DestroyOrFree`, with
  flags 3. No object requires it.
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

## Live hazard: the array of 00768810 is retired with the 32-bit layout

This was there before these changes. Its owner is VEGAS-72.

00768810 allocates its array with `new HackingArrayElement[n]`. The
windows-x64 compiler keeps the count in 8 bytes, eight bytes before the
array, and the elements are 16 bytes apart. 007687d0 retires that array
through `DestroyOrFree` (0x007021b0) with flags 3. The array path of
`DestroyOrFree` is a transcription of the original's: it reads a 32-bit
count four bytes before the array, steps 8 bytes per element, passing
`FUN_007021b0_cls::FUN_00702220` to `FUN_00ec5fce`, and frees the block
four bytes before the array. On windows-x64 it would read the wrong count,
destroy at the wrong addresses and free a pointer the allocator did not
return. No program runs it today: neither `FUN_00ec5fce` nor
`FUN_007021b0_cls::FUN_00702220` has a definition, and no program that
links contains 007687d0.

The recipe binds `FUN_007021b0_cls::FUN_00702220` to `0x00702220`, the
function kept here, but the call is not rebound, because the count and
stride around it are the 32-bit layout.

Next step: a coordinator ruling that 0x007021b0 is the compiler's vector
deleting destructor of `HackingArrayElement`, which is what the respelled
recipe key says. Then 007687d0 becomes a typed `delete[]`, and the
transcribed body of `DestroyOrFree` is retired from its row. Yield:
`FUN_007021b0_cls::FUN_00702220` leaves the undefined names of this unit.
It needs a test that retires arrays of zero, one and many elements.

## Not covered

These were open before these changes and remain open for VEGAS-72.

- `STR_0076b200`, `FUN_00768920_shell` and `HackingArrayElement` are three
  declarations of one element, joined by casts. Their second word is a
  `uintptr_t`, a pointer and an `unsigned int`. They are not merged here.
- The array that 00768810 allocates is retired by 007687d0 with the 32-bit
  count and stride (the hazard above). The array that 0076b0c0 allocates is
  retired by 0076b0c0 itself, with the compiler's own count and stride.
- The recipe key `??0SL@@QAE@XZ` at `0x0096a2d0` of this unit is the earlier
  name of the element constructor. It names nothing in the source now.
- `FUN_008456c0` reaches its receiver through a cast and a four-byte offset
  that is also the 32-bit layout. Its owner has no typed construction.
- Neither `hackingmenu.cpp` nor the staging units build for a host test, and no
  windows-x64 program that contains them links, so no test executes this path.
  The evidence is the rebuilt objects and the complete links.
