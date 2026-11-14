# Calls that disagree on an integer width

VEGAS-97 widens 32-bit parameters that carry pointers, one declaration per
function, caller and callee agreeing, no casts. This document records the
first step on the calls whose required name differs from the defined one only
in an integer width: `int` against `__int64`, `unsigned int` against
`unsigned __int64` (`H` against `_J`, `I` against `_K` in the name). The
undefined-name census of `2fa5deb28` counts 228 such names. The widths were
decided on `973b5d612`, which changes only `src/fileformat`, tests and
documents against `2fa5deb28`. The repairs were built and measured on
`e904ce163`, where the fixed probes, run again, give the same decisions.

## Why they differ

In the original release every one of these values is 4 bytes, so the 32-bit
recipe rows spell them all `H` or `I` and do not tell a pointer from a count.
On windows-x64 earlier changes gave some declarations `intptr_t` (shared
`include/fnv/symbols_*.h` and `include/fnv/decl/*.h` headers, or a unit's own
declaration) and left the other side at `int`, or the reverse. The caller then
names a function no object defines. If the two were bound, the callee would
read 64 bits of which the caller set 32, or the caller would read 64 bits of a
32-bit result.

## How a width was decided

Every name was measured on the tip's own build, outside the repository:

1. Where each requiring unit's declaration is (the compiler's AST, by mangled
   name) and where the definition is.
2. How the definition's body uses each differing parameter or what it
   returns: converted to a pointer or passed to a pointer parameter, stored
   or compared at 32 or at 64 bits, used in arithmetic, unused.
3. What every call passes there, for both names: the required one in the
   requiring units, and the definition's present one in its own unit and its
   other users. A converted pointer, a constant or another value, with the
   value's type in the caller; whether the result is converted to a pointer.
4. Whether a generated object requires either name, including the asm labels
   of generated tables.

A repair was accepted only in these forms:

- **Widen the requirer.** The definition already has 64 bits and its body
  converts the value to a pointer or passes it to a pointer parameter, or
  returns a converted pointer. The requirer's declaration takes the
  definition's width.
- **Widen the definition.** The definition has 32 bits but converts the value
  to a pointer, and its callers pass converted pointers. The definition takes
  the pointer-sized width; its body is unchanged.

A widened requirer was accepted only when every caller passes a converted
pointer, a constant or a pointer-sized variable at each widened position, or
uses only the result, or takes the function's address. A widened declaration
over a caller's 32-bit variable would make the call agree with the callee but
pass a sign-extended 32-bit value where the callee reads a pointer. Those
names wait for the caller's repair, in the same commit (below).

Narrowing the requirer or the definition was also allowed by the rules. None
is accepted here: for each of the nine definition candidates a caller in the
defining unit passes a converted pointer or converts the result to a pointer.
The one requirer candidate of the first probe run, `0x00c3cb70`, is refused
by the fixed probes (below), so no candidate for narrowing the requirer
remains.

### The probes' blind spot

The first run of the caller and declaration probes skipped every unit whose
source path has a space: the 18 units in `distant terrain system` (4) and the
two `region system` folders (13 and 1). The probes named units as the census
does, by object path, where CMake writes the space as `_`. The compiler found
no such file, printed no match, and the unit looked like one without calls. The
probes now find each unit's source through the build's compile commands, and
list any unit that has none or fails to parse instead of dropping it.

The fixed probes were run again over all 228 names on `973b5d612`. They
found calls or declarations in those units for 11 names. One classification
changes: `0x00c3cb70`, from narrowing the requirer to pointer into a 32-bit
use (below). The other ten stay refused for the same reason:
`0x0043cc60`, `0x00441110`, `0x00540540`, `0x00540570`, `0x006286d0`,
`0x00825c00`, `0x0084e3a0` and `0x009611e0` (pointer into a 32-bit use),
`0x004538a0` and `0x00a5b230` (evidence open). No accepted name gains a
caller, and no other decision or reason changes. On `e904ce163` the fixed
probes find the same declarations and calls for all 228 names, with the same
arguments, apart from line numbers in `main.cpp` and `tesobjectrefr.cpp`, and
give the same classification and decision for every name.

## Accepted repairs

25 names in three commits whose changed objects are disjoint. Commit 1
widens 18 requirer declarations and commit 2 four more. Commit 3 holds the
two definition repairs and the requirer repair that shares an object with
one of them.

| Address | Function | Repair | Positions | Commit |
| --- | --- | --- | --- | --- |
| 0x00444d40 | `S_00444d40_Class::FUN_00444d40` | widen requirer | p4 | 1 |
| 0x00537d60 | `FUN_00537d60_Create` | widen requirer | p1 | 1 |
| 0x00553bf0 | `fnv_00553bf0::S00553bf0::FUN_00553bf0` | widen requirer | p3 | 1 |
| 0x005a8ef0 | `FUN_005a8e20_cls::FUN_005a8ef0` | widen requirer | p1 | 1 |
| 0x00621440 | `FUN_00621440_cls::FUN_00621440` | widen requirer | result | 1 |
| 0x00623570 | `FUN_00623570_class::FUN_00623570` | widen requirer | result | 1 |
| 0x0065da80 | `FUN_0065e000_class::FUN_0065da80` | widen requirer | result p2 | 1 |
| 0x0066e810 | `UpdateOrRemoveItems` | widen requirer | p1 | 1 |
| 0x00687d40 | `Class87d40::ForwardActorBaseData` | widen requirer | p4 p5 | 1 |
| 0x008586d0 | `FUN_008586d0_class::FUN_008586d0` | widen requirer | p1 p2 | 1 |
| 0x008c70c0 | `QuantitySet::FUN_008c70c0` | widen requirer | p1 | 1 |
| 0x009fa260 | `FUN_009fa260` | widen requirer | p1 | 1 |
| 0x00a51ab0 | `FUN_00a51ab0_cls::FUN_00a51ab0` | widen requirer | p1 p3 | 1 |
| 0x00ce51f0 | `Transform::FUN_00ce51f0` | widen requirer | p1 | 1 |
| 0x00dd9270 | `FUN_00dd9270_cls::FindEntry` | widen requirer | p1 | 1 |
| 0x00e89ad0 | `FUN_00e89ad0` | widen requirer | p1 | 1 |
| 0x00e9f400 | `FUN_00e9f400` | widen requirer | p2 p3 p4 p5 | 1 |
| 0x00e9f510 | `FUN_00e9f510` | widen requirer | p3 p5 | 1 |
| 0x004da670 | `fnv_004da670::FUN_004da670` | widen requirer | result | 2 |
| 0x00585e00 | `fnv_00585e00::FUN_00585e00_cls::FUN_00585e00` | widen requirer | p1 | 2 |
| 0x005885f0 | `WORLD_SHELL::ProcessCellsInRadius` | widen requirer | p6 | 2 |
| 0x005aa580 | `FUN_005aa580` | widen requirer | p1 | 2 |
| 0x004f05c0 | `FUN_004f05c0_cls::ApplyFlagsToEntries` | widen definition | p1 | 3 |
| 0x00619c50 | `FUN_00619c50_shell::FindTopicByInfoID` | widen definition | p1 | 3 |
| 0x00c40e70 | `Map40::FUN_00c40e70` | widen requirer | p3 | 3 |

Two of the widened requirers were read by hand rather than by the rule:
`FUN_009fa260` builds object pointers from `a + 0xc` and passes `a` on as
`intptr_t`, and `FUN_00621440` returns a local `intptr_t` that holds a
converted pointer.

Four callers held a pointer-sized value that the old declaration cut to 32
bits: `pThis` (0x009fa260), `aiArg3` in `tes.cpp` (0x00553bf0), `b` in
`blk_00640000_od.cpp` (0x0065da80) and `data` in `tesdatahandler.cpp`, a
`std::intptr_t` parameter of `GetReferencesInArea` (0x005885f0). The other
caller of `ProcessCellsInRadius`, in `vatsmenu.cpp`, passes `{}`.

The old `int` declaration of `FUN_004da670` (0x004da670) also truncated.
The body returns a converted pointer, the result of `FUN_00559450`, and
its one caller in `main.cpp` treats 0 as failure, shows an error and exits.
Through the old declaration a pointer whose low 32 bits are zero read as
that failure.

### What binding credits

Each accepted name now has one provider, rebuilds and links. Receivers,
layouts and lifetimes of the bodies it binds to are not looked at here and
stay open.

## Held repairs

13 names passed the rule but are not repaired here: 11 whose callers pass
a 32-bit variable, one count on the wire and one index.

### Caller storage 32-bit

The callee's body takes a pointer-sized value, but at least one caller passes
a variable that is itself 32 bits wide. Widening the declaration alone would
make that call pass a sign-extended truncated value where the callee reads a
pointer. Each needs the caller repair in the same commit.

| Address | Function | Caller's 32-bit value |
| --- | --- | --- |
| 0x004c37d0 | `Transfer4c37C37This::FUN_004c37d0` | `p2`, `p3` (`int`) in `tesobjectrefr.cpp` |
| 0x004ce340 | `FUN_004ce340_stand::FUN_004ce340` | `firstValue`, `fifthInput` (`int`) in `tesscriptfunctions.cpp` |
| 0x00547750 | `FUN_00547750_shell::FUN_00547750` | `iValue` (`int`) in `tesscriptfunctions.cpp` |
| 0x005fd400 | `Outer_5fd400::FUN_005fd400` | `arg1` (`int`) in `tesscriptfunctions.cpp` |
| 0x00616f40 | `FUN_00616f40_shell::DispatchOnNextFormType` | `aiArg1`, `aiArg3` (`int`) in `dialogueresponse.cpp` |
| 0x009f9d30 | `FUN_009f9d10_cls::CallAndReturnThis` | `aiArg2` (`int`) in `FUN_00831e20`, `blk_00820000_od.cpp` |
| 0x00a71cc0 | `FUN_00a71cc0_cls::FUN_00a71cc0` | `aiArg` (`int`) in `blk_00c00000_o2.cpp` |
| 0x00b6d170 | `RTManager_b6d170::CreateRenderTarget` | `a9`, `a10` (`int`) in `bstexturemanager.cpp` |
| 0x00b6ee70 | `TexturePool::ResizeActivePool` | `*reinterpret_cast<int*>(&NiRenderer::ms_pRenderer)` in `distantlodshaderproperty.cpp` |
| 0x00b812b0 | `FUN_00b812b0_class::FUN_00b812b0` | `arg` (`int`) in `bsshaderbloodsplatterproperty.cpp` |
| 0x00ddf170 | `FUN_00ddf170_cls::FUN_00ddf170` | `a` (`int`) in `hkpworldsnapshotviewer.cpp` |

### A count on the wire

`FUN_00e06d70_Class::WriteSize` (0x00e06d70) is called with `difference`, an
`unsigned int` in `hkpmoppdefaultassembler.cpp`. It is a count written to a
stream, so it keeps the original fixed width of 32 bits. Its definition takes
64 bits; it is a candidate for narrowing the definition instead (width
agreement, VEGAS-11; wire widths, VEGAS-44).

### An index passed as a pointer

`FUN_0083c850::AppendTopicInfo` (0x0083c850) takes `std::intptr_t` and
passes it on as `(void*)` to `FUN_0061f170` (0x0061f170), which passes it
to `TESTopicInfo::GetResultScript` (0x0061eb60) as `(uintptr_t)`. There it
is the `onEnd` index into `g_resultScripts`, which has two entries: 0 for
the script run at the start, 1 for the one run at the end. Every caller of
`AppendTopicInfo` passes the constant 0 or 1. No function in the chain uses
the value as a pointer, so the pointer width does not hold. The chain
0x0083c850, 0x0061f170, `GetResultScript` should carry a `bool` or an
`unsigned int`; that is a separate repair of meaning, and the name stays
undefined until it is made.

## Refused names

190 names, each with one reason (the first that applies):

| Reason | Names | What it means |
| --- | --- | --- |
| Pointer into a 32-bit use | 91 | A caller of either name passes a converted pointer, or converts the result to a pointer, but the definition keeps the value in 32 bits: a field, an array element, a comparison or a 32-bit callee. Widening the parameter alone would not keep the pointer; the storage needs its layout first. |
| Evidence open | 38 | The value is only passed on to a call whose parameter type was not resolved, its address is taken, or the uses mix kinds. Needs reading. |
| Placement | 27 | The definition does not use the parameter and callers pass a value there. 13 of the 27 have a fastcall row (`YI`); in those read, the definition's unused `int` is the EDX slot and the caller passes the object in it. A call-argument repair, not a width repair. |
| Meaning | 13 | Caller and callee disagree on what the value is (a format, a chunk code, flags, a table index, a value where the callee writes through a pointer). |
| Storage width | 11 | The definition stores or compares the value at 64 bits with no pointer use, and callers pass 32-bit values; which width the field has is not established. |
| Generated | 6 | A generated table or asm label requires the name that would have to change. |
| Storage | 2 | The value lives in a 32-bit slot that the body reads back as a pointer, or a 32-bit list data field is returned. |
| Body truncates | 1 | The body returns `(unsigned int)(uintptr_t)pointer`; widening the result also needs the cast removed. |
| Function pointer field | 1 | The requirer stores the function in a field typed `void(__cdecl*)(int)`. |

17 were refused by reading: 0x00a26b40, 0x00e7ade0, 0x0068f3b0, 0x00471ad0,
0x00620b80, 0x004dee70, 0x004dee10, 0x0047a240, 0x0048a520, 0x005f0b30,
0x00a4e0f0, 0x005f1b30 and 0x00a50b10 (meaning), 0x0049ec60 (body
truncates), 0x0049c5d0 and 0x006cc560 (storage) and 0x005586c0 (function
pointer field). The two formatters `FUN_00a7d4d0` (`"%d"`, 25
requirers) and `FUN_00a7d510` (`"%u"`, 49 requirers) are in "evidence open":
their width is 32 bits by the format, but a few callers pass pointers to them.

`fnv_00c3cb70::IOTask::FUN_00c3cb70` (0x00c3cb70) is counted among the
pointers into a 32-bit use. It uses its first argument as a 32-bit state,
and the other callers pass integer variables. But `RunOnce` in
`bgsdistantobjectblock.cpp` passes `(std::intptr_t)(apTaskState)`, a
converted pointer, which an `int` declaration would cut without a
diagnostic. The first probe run did not see that caller (the blind spot
above). What `RunOnce`'s `void* apTaskState` carries has not been read.

## Checks

`objects.integer_width_calls` (`tools/function-relocations/integer-width-calls.tsv`)
forbids the 23 former requirer names. It lists the 51 functions that call or
take the address of an agreed name (52 rows: one function takes two), and
the two widened definitions, which must be defined under the agreed name.
On each commit's parent it fails; on the commit it passes. It cannot see a
call through a pointer, or a caller that passes a 32-bit variable through a
widened declaration.

## Measured on each commit

Built from the same export path as the tip (`e904ce163`), windows-x64, the
real preset:

| | Tip | Commit 1 | Commit 2 | Commit 3 |
| --- | --- | --- | --- | --- |
| Forced unlimited link: undefined names | 35,104 | 35,086 | 35,082 | 35,079 |
| Names entering | – | 0 | 0 | 0 |
| Duplicates (four cells) | 0 | 0 | 0 | 0 |
| Imports (forced unlimited) | 137 | 137 | 137 | 137 |
| Objects changed against the parent | – | 18 | 4 | 3 |
| Functions changed against the parent | – | 40 | 6 | 4 |
| Names with differing definitions | 519 | 519 | 519 | 519 |

Every object that changes changes only in the functions that call or take the
address of a repaired name, their unwind data and the address-significance
table: the relocation names the agreed function, the argument or result is
set up at 64 bits (a sign or zero extension, a 64-bit register or stack slot,
in two calls two zero stack arguments merged into one 16-byte store; one
caller of `Map40::FUN_00c40e70` that formed the address with a 32-bit `lea`
now passes the full address), and register choice and alignment padding
follow. In the two widened definitions the 32-bit copy of the argument
becomes a 64-bit one. Symbol tables change only in the former and agreed
names. Warnings of the rebuilt units are equal by class and text.

Per name, the defining members, COMDAT selection and content were compared
before and after each commit. Each of the 48 functions whose code changed
keeps one definition, in the same member, with the same selection. The two
widened definitions change name: the former name has one definition before
and none after, the agreed name none before and one after, in the same
member, both with selection 1. No name gains a second definition or a second
content.

The host suites, optimized and with ASan, UBSan and vptr checks, give the
same per-test results as the tip; the new check runs only in the cross
build, where it passes.

## Not verified

- Windows execution: not run.
- Whether the bodies the accepted names bind to are correct on windows-x64
  (receivers, layouts, lifetimes).
- The held names and their callers.
- The evidence is the compiler's view of each declaration and call; calls
  through pointers and calls the optimizer removed are not seen.
