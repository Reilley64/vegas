# Hacking menu element release binding

VEGAS-72 removes the second definition of `FUN_00702220::~FUN_00702220()`.
`src/fallout/interface/menus/hackingmenu.cpp` defined it with an empty body.
The one definition left is the function at 00702220 in
`src/staging/blk_00700000_od.cpp`, and the class now has one declaration,
`include/fnv/decl/FUN_00702220.h`, used by every unit that names it.

This is the binding only. It is not the repair of the hacking menu arrays; see
"Not covered".

## What the recipe records

`build/units.json` is the authority for addresses.

| Unit | Entry | Address | Size |
| --- | --- | --- | --- |
| `src/staging/blk_00700000_od.cpp` | function `FUN_00702220::~FUN_00702220()` | `0x00702220` | 33 |
| `src/fallout/interface/menus/hackingmenu.cpp` | function `FUN_007021b0_cls::DestroyOrFree(unsigned int)` | `0x007021b0` | 106 |
| `src/fallout/interface/menus/hackingmenu.cpp` | symbol `FUN_00702220::~FUN_00702220()` | `0x00702220` | |
| `src/fallout/interface/menus/hackingmenu.cpp` | symbol `FUN_007021b0_cls::FUN_00702220()` | `0x00702220` | |
| `src/fallout/interface/menus/hackingmenu.cpp` | symbol, the vector deleting destructor of `ArrElem` | `0x007021b0` | |
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

`FUN_007021b0_cls::DestroyOrFree` (007021b0) with bit 2 of its flags clear
destroys one element. Before, that released nothing and then freed the element
when bit 1 was set. Now it first releases the buffer the element points to.
This is the recovered behaviour of the two addresses, not a native policy.

The path with bit 2 set, which destroys an array, is not changed.

A link that held both definitions and needed the name could take either one.
A link with every archive member reported the duplicate. Now there is one
definition.

No program that contains either caller links today. The complete game link
does not extract `hackingmenu.cpp.obj` or `blk_00840000_od.cpp.obj`, and the
link with every archive member fails on other duplicate and undefined names.
So no executable changes behaviour with this change.

## Producers and retirers of the element

- `FUN_00768810::FUN_00768810(unsigned int)` (00768810) allocates an array of
  `HackingArrayElement` and sizes each element through 00768920. No object
  requires it.
- `ElemArray::CopyFrom` (0076b0c0) deletes and allocates an array of `ArrElem`,
  a second declaration of the same two words. The `ArrElem` constructor and
  destructor have no definition.
- `C7687d0::FUN_007687d0` (007687d0) is the one caller of `DestroyOrFree`, with
  flags 3. No object requires it.
- 00768920 and `STR_0076b200::AssignFrom` (0076b200) release and replace the
  buffer of one element in place.

## Not covered

These were open before this change and remain open for VEGAS-72.

- `HackingArrayElement::HackingArrayElement()` is empty, so a new element's
  pointer is not initialised before 00768920 releases it.
- The array path of `DestroyOrFree` passes `FUN_007021b0_cls::FUN_00702220` to
  `FUN_00ec5fce`. Neither has a definition. The recipe binds the first to
  `0x00702220`, the function kept here, but the call is not rebound: the path
  reads a 32-bit count four bytes before the array and steps eight bytes per
  element, which is the original release's 32-bit array layout and not the
  layout the windows-x64 compiler gives `new HackingArrayElement[n]`.
- `ArrElem`, `STR_0076b200`, `FUN_00768920_shell` and `HackingArrayElement` are
  four declarations of one element, joined by casts. They are not merged here.
- `FUN_008456c0` reaches its receiver through a cast and a four-byte offset
  that is also the 32-bit layout. Its owner has no typed construction.
- Neither `hackingmenu.cpp` nor the staging units build for a host test, and no
  windows-x64 program that contains them links, so no test executes this path.
  The evidence is the rebuilt objects and the complete links.
