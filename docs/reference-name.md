# Reference name query binding

VEGAS-62 leaves `FUN_0055d520_shell::FUN_0055d520()` to its one definition, in
`src/fallout_shared/tesobjectrefr.cpp`. The second definition, a body in
`src/fallout_shared/tesconditionfunctions.cpp` that returned a null pointer, is
removed.

This is the binding only. It is not the repair of the receiver or of the
reference and base-form types; see "Not established".

## The one function

`build/units.json` lists the name once as a function: `0x0055d520`, 30 bytes,
in the unit of `src/fallout_shared/tesobjectrefr.cpp`. Every other unit that
names it, the unit of `tesconditionfunctions.cpp` included, only binds the name
to that same address in its symbol table. No second address is recorded, so the
two definitions were never two original functions.

The definition takes the address `0x00891170` returns for its receiver, reads
the form pointer stored there, and returns the result of `FUN_00482720`
(`0x00482720`) for that form. `0x00891170` is the 17-byte accessor that returns
its receiver plus 32, spelled `BGSCameraPath::GetShotList` in every unit that
calls it. In the original release's layout the word 32 bytes into a reference
is its base form. The recipe records no call edges: that `0x0055d520` calls
these two functions comes from the unit binding both names and from the
function's size.

On windows-x64 the same source reads a different word. In the rebuilt
`tesobjectrefr.cpp.obj` the definition calls the accessor, whose whole body is
`lea 0x20(%rcx), %rax`, loads the 8-byte word at that address and passes it to
`FUN_00482720`, which gives it to the dynamic cast from `TESForm` to
`TESFullName`. The shared declaration `include/TESObjectREFR.h`, compiled with
that unit's windows-x64 command, has `sizeof(TESForm)` 40,
`tESChildCellComponent` at 40, `m_pSoundForm` at 48 and the base-form data
(`data`, whose first member is the base-form pointer) at 56. Offset 32 is
therefore inside the `TESForm` base: it is the second word of the 16-byte
`m_kSourceFiles`, which starts at 24. The same four numbers come out of the
command of `tesconditionfunctions.cpp`. "The reference's name" is true only
for the original release's layout.

## The returned name is borrowed

`FUN_00482720` returns either the text of the base form's full-name component
or the empty string literal. Neither is a copy. The caller does not own the
result and must not free or write it, although the name's return type is
`char *`. The text is valid only while the base form lives and its name is not
replaced. The tree has 175 call expressions on 167 lines in 39 files. Twelve
store the result in a variable before using it; the twelfth, at
`src/fallout/ai/actor.cpp:129820`, stores it only when the attacker is not
null. How long each of those keeps the pointer is not traced here. The nine
condition functions below pass it straight to a formatter.

## The removed body

The body in `tesconditionfunctions.cpp` carried no address and ignored its
receiver. It stood in for the callee of nine condition functions in the same
file: `0x0059c990`, `0x0059fdb0`, `0x005a1ee0`, `0x005a3390`, `0x005a3460`,
`0x005a4f30`, `0x005a5020`, `0x005a50f0` and `0x005a59a0`. Each calls the name
query only to format a log line, and only when the thread's
`conditionFunctionDebug` flag is set. One statement sets that flag:
`src/fallout_shared/tesscript.cpp:1741`, reached only when
`compilerIndex == 1`. Line 1749 of the same function clears it, and so does
line 365. The file keeps its declaration of the type.

Before this change the windows-x64 object of that file inlined the null body
into all nine functions and referenced no name query, so these log lines were
formatted with a null name. The object now requires the one definition, with
14 call sites, and the nine functions call the owner. On windows-x64 the
owner reads the word at +32 of the reference, as measured above, so what the
nine functions pass is the reference's name only in the original release's
layout. That is the recovered behaviour of the recorded addresses, not a
native policy.

`0x005a59a0` calls the query outside its null guard; the guard covers only
its two virtual calls. With the flag set and a null reference, the accessor
returns address `0x20` and the owner reads it.

Eight of the nine functions pass the result to a logger that no archive
member provides:

| Function | Logger it requires |
| --- | --- |
| `0x0059c990` | `fnv_0059c990::DebugLog` |
| `0x0059fdb0` | `DebugLog` |
| `0x005a3390` | `fnv_005a3390::FUN_00703c00` |
| `0x005a3460` | `fnv_005a3460::FUN_00703c00` |
| `0x005a4f30` | `fnv_005a4f30::FUN_00703c00` |
| `0x005a5020` | `fnv_005a5020::FUN_00703c00` |
| `0x005a50f0` | `fnv_005a50f0::DebugLog` |
| `0x005a59a0` | `fnv_005a59a0::_DebugLog` |

The ninth, `0x005a1ee0`, uses the file's own `_DebugLog`.

No complete program containing either object linked before this change, and
none links now: a link that extracts every archive member stops on the
remaining duplicate definitions. A link that extracts members on demand from
`main` reaches neither object.

## Requirers

At the accepted tip 714f4a53f, 37 archive members require the name and two
define it. The recipe binds the name to `0x0055d520` in the units of 49 source
files; the ten without a requiring object are `combatgroup.cpp`,
`combatmanager.cpp`, `missileprojectile.cpp`, `projectile.cpp`,
`detailedactorpathhandler.cpp`, `virtualactorpathhandler.cpp`, `menutopic.cpp`,
`summoncreatureeffect.cpp`, `bipedanim.cpp` and `tesobject.cpp`, which declare
the type and emit no call. After this change 38 members require it and one
defines it. The 37 members that already required the name reach the same
definition, so the +32 read above is what they get too; this follows from
there being one definition, and their call sites were not disassembled. No
generated data names the function. No archive member is added,
removed or reordered, and `build/units.json` is unchanged.

## Not established

These were open before this change and remain open.

- No call site holds a `FUN_0055d520_shell` object. Each passes a pointer to
  another type through a cast. `tesobjectrefr.cpp` declares the type as
  derived from `TESObjectREFR`; the shared declaration header and the other
  files declare it with no base. This change endorses none of the casts.
- The 32-byte offset and the accessor's camera-path spelling are the original
  release's 32-bit layout and its shared code. A windows-x64 reference of the
  shared declaration keeps its base form 56 bytes in, not 32, so the owner
  does not read it there. Which declaration each caller's receiver has is
  not traced. The removed body could not have been right for any receiver,
  because it ignored it.
- `tesconditionfunctions.cpp` requires the same address under four more names,
  `MobileObject_Shell::GetFullName` and three `MobileObjectShell::GetFullName`
  spellings. None has a definition; they are not rebound here.
- That file's own `_DebugLog` is an empty body, so `0x005a1ee0` calls the
  query twice and still discards the line.
- Neither unit compiles for a host test, and `FUN_00482720`'s unit and the
  accessor's unit do not either, so no test executes the query. The evidence
  is the rebuilt windows-x64 object, the composed archive and the complete
  links.
