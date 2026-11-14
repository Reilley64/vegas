# Variadic argument lists on windows-x64

The 32-bit bodies built the argument list of a variadic function the way
the 32-bit compiler's `va_start` does: the address of the last named
parameter, plus its size. On windows-x64 that does not reach the caller's
variable arguments. The first four arguments arrive in registers, so the
address of such a parameter is a copy in the function's own frame, and what
follows the copy is another slot of that frame. A parameter past the fourth
is the caller's stack slot, but every slot is eight bytes, so four bytes
past it is the slot's upper half. The 32-bit step of four bytes per
argument is wrong there as well.

VEGAS-131 searched `src` and `include` for this form and for its relatives,
repaired every variadic function that has it with `va_start`, `va_arg` and
`va_end`, and recorded the rest here. Each repair is its own commit with its
object proof; `tests/checks/objects_variadic_lists.cmake` checks each
repaired function's list in the game archive, and
`runtime.format_into_buffer` formats known values through `FUN_00406d00`.

## How the sites were found

- A text search for `(&x + 1)`: 12 sites.
- A `clang-query` search of every unit under `src` in the windows-x64
  compile database (2,246 units at 087a5a0c1): the address of a parameter
  that is not a reference, as an operand of `+` or `-`, under a subscript,
  cast to a pointer to `char` or `void`, or held in a variable; every call of
  a `v*printf` function; every `va_start`.
- Blind spots: units that are not compiled were searched only as text
  (`src/fallout_shared/bgsentrypoint.cpp`), and `src/setup/setup_main.cpp`
  was not parsed (its generated header was not built; the text search finds
  nothing there). A pointer held in a variable and then stepped was read
  by hand. Reference parameters are left out: their address is the caller's
  object, not a parameter slot.

## Repaired

"Old list" is what the old form addressed at the unit's flags, from the
object proofs.

| Function | Row | Unit | Old list | Read by | Callers that changed |
| --- | --- | --- | --- | --- | --- |
| `FUN_00406d00` | `0x00406d00` | `src/fallout_shared/format_into_buffer.cpp` | the stack cookie slot | `std::vsnprintf` | none; no caller sees the body |
| `FUN_00a0e470` | `0x00a0e470` | `src/bsmenu/debugtext.cpp` | the stack cookie slot | the debug text's fifth virtual function | none |
| `FUN_00a0e580` | `0x00a0e580` | `src/bsmenu/debugtext.cpp` | the stack cookie slot | the seventh virtual function of its first argument | none |
| `FUN_00a0e690` | `0x00a0e690` | `src/bsmenu/debugtext.cpp` | the stack cookie slot | the debug text's fifth virtual function | none |
| `InvokeVFuncWithVarArgs` | `0x00a0e6d0` | `src/bsmenu/debugtext.cpp` | the caller's first variable argument: `p5` is a stack parameter, so the old form was right by accident | the fifth virtual function of its first argument | none |
| `NiSprintf` | `0x00a305b0` | `src/gamebryo2.2/corelibs/nisystem/console/nisystem.inl` | the stack cookie slot | `std::vsnprintf` | none |
| `LogScriptCompileError` | `0x005e2410` | `src/fallout_shared/tesscriptrunmanager.cpp` | a slot that nothing writes, before the output buffer | `FUN_00407000` (`vsprintf`) | `ScriptRunner::ParseOutput`: its inlined copy dropped the function and script names; it now passes them |
| `ApplyPerkModifiers` | `0x005e58f0` | `src/fallout/interface/fovatseffectmanager.cpp` | the body's own array of filters, four bytes a step | the body | none |
| `FUN_00406f60` | `0x00406f60` | `src/fallout/interface/interface.cpp` | the stack cookie slot | `FUN_00406f90` | none |
| `FUN_00703e80` | `0x00703e80` | `src/fallout/interface/interface.cpp` | the upper half of `axFirst`'s slot | `MessageCreation::QueueMessage` | none |
| `FUN_007ca200` (constructor) | `0x007ca200` | `src/fallout/interface/menus/specialbookmenu.cpp` | the upper half of `iNumNavMeshes`'s slot | the body | none |
| `FUN_007d6350` (constructor) | `0x007d6350` | `src/fallout/interface/menus/startmenu.cpp` | a slot of its own frame, four bytes a step | the body | none |
| `FUN_00845cc0` | `0x00845cc0` | `src/fallout/misc/saveload/bgssaveloaddefines.cpp` | the upper half of its copy of `apMessage` | `FUN_0084ab00` | `WriteEncodedInteger`: its inlined copy dropped `value`; it now passes it. `ReadEncodedInteger`: its message has no conversion |
| `ReportScriptError` | `0x005aea90` | `src/fallout_shared/tesscriptcompiler.cpp` | the `StrBuf8` it constructs after the call | `FUN_00407000` (`vsprintf`) | none |
| `hkStringPtr::FUN_00cb0c70` | `0x00cb0c70` | `src/havok/common/base/container/string/hkstringptr.cpp` | the slot of the exception handling state | `FUN_00cb0f50` | none |
| `ShaderPassEntry` (constructor) | `0x00ba8ec0` | `src/bsshader/bsshaderproperty.cpp` | `&light0` indexed: right at `/Od`, but at the unit's flags the compiler stored `light0` into every slot | the body | `ShaderPassList::Add`: its inlined copy dropped `light1` to `light3`; it now passes them |

A caller that changed had inlined the old body: a variadic function that
does not use `va_start` can be inlined, and one that does cannot. Each
such change is a change of data flow, listed in its commit.

`ApplyPerkModifiers` now reads its filters and arguments as pointers,
eight bytes each. Two compiled callers pass a 32-bit integer in a
pointer's place: `src/staging/blk_00660000_od.cpp` (`(int)(intptr_t)obj`,
entry point 0x28) and `src/staging/blk_009a0000_od.cpp` (`unsigned int
actorFlags`, entry point 0x48). The pointer is cut to 32 bits before the
call; that is a defect of those callers, not repaired here.

## Not variadic, but walking their parameters

These functions were declared with a fixed parameter list and passed the
address of a parameter as an argument list. The declaration lost its
`...`, and the callers pass a fixed argument. VEGAS-131 left them as they
were; VEGAS-134 takes them under the coordinator's ruling of 2026-11-14,
whose seven conditions are in that ticket.

| Function | Row | Unit | Form | Read by | VEGAS-134 |
| --- | --- | --- | --- | --- | --- |
| `InvokeVirtualWithArgs` | `0x00a0e4b0` | `src/bsmenu/debugtext.cpp` | `(char*)&aiArg5` | the fifth virtual function of its first argument | tabled |
| `FUN_00cb0f80` | `0x00cb0f80` | `src/staging/blk_00ca0000_o2.cpp` | `(char*)&c` | `std::vsprintf` | restored |
| `FUN_00703c80` | `0x00703c80` | `src/fallout_shared/tesscriptfunctions.cpp` | `int* p = &b`, passed as `char*` | `ConsoleText::FUN_0071d0a0` | tabled |
| `FUN_00703c00` | `0x00703c00` | `src/fallout/ai/processlists.cpp` | `(char const*)&context` | `ConsoleText::FUN_0071d0a0` | tabled |

`FUN_00cb0f80` is now `void FUN_00cb0f80(char*, const char*, ...)` and
makes its list with `va_start` on the format. Its one caller,
`FUN_00d87aa0` in `src/staging/blk_00d80000_o2.cpp`, formats a count with
`"%4i\t\t"` and passes the count as an `int`; it passed it through
`char*` before. The recipe's two keys take the new name, and
`tests/checks/objects_ellipsis_restored.cmake` checks the list and that no
object refers to the former name.

`FUN_00703c80` takes a string object by value and formats with its text.
The recipe binds three names in its unit to the address, each with
another class for that parameter: the definition's `S_00703c80_A`, two
32-bit fields; `FUN_00703c80(TreeStr)`, called three times; and
`xConsolePrint(DynamicString)`, called three times. `TreeStr` and
`DynamicString` have the string's three fields but other members.
Condition (4) does not need one class: each name can take its own `...`
and each key its new spelling in one commit. What fails is condition (6):
`S_00703c80_A` is the 32-bit view of the string the format is read from,
a lost parameter type that needs its own stated commit first, and no rule
yet picks the class for a string passed by value (`TreeStr`,
`DynamicString` or the unit's `BSStringT<char>`).

`FUN_00703c00` stays for its own lane. The recipe has 194 keys at the
address in 27 entries of 25 sources, under 166 names: `FUN_00703c00`,
`DebugLog`, `_DebugLog`, `xDebugLog`, `B5CC970DebugLog`, `Log`,
`LogPositionCondition`, `ReportMessage` and a `char` variable
`_DebugLog`, in many namespaces, with and without C linkage. In 24 units
700 calls name 165 of them. Of the calls, 17 pass fewer arguments than
their format's conversions; 20 pass more, 12 of those an empty
placeholder `{}`; 34 have a format that is a run-time string or of which
the source holds only the first one to four bytes, and 17 of those pass
`{}`. Two more calls name `FUN_00703c00` in a namespace that no key
binds. Some declarations take another type in the format's place
(`unsigned int`, `const void*`, `void*`) or return a value (`int`,
`bool`), each a separate change under the ruling.

`InvokeVirtualWithArgs` has no caller in the recipe. Its siblings
`FUN_00a0e470`, `FUN_00a0e690` and `InvokeVFuncWithVarArgs` call the
fifth virtual function of their receiver with the format fourth and the
list fifth, where
it passes `aiArg4` and the address of `aiArg5`, so they place the format
at `aiArg4`, an `int` that would first become `const char*`. Its first
argument's class is a stand-in, as is `InvokeVFuncWithVarArgs`'s
receiver, so that the virtual function is the same one is not shown. A
second declaration at `debugtext.cpp:1475` moves with any later restore.

## Functions that take a list

These take a list as a parameter and are right when their callers pass one
made with `va_start`: `FUN_00407000` (`effectitemlist.cpp`),
`E4F0DebugText::PrintFormattedLine` and `A0E5C0DebugText::PrintFormattedAtSlot`
(`debugtext.cpp`), `FUN_0084ab00` (`bgssaveloadgame.cpp`),
`ConsoleText::FUN_0071d0a0` (`staging/blk_00700000_od.cpp`),
`FUN_00406f90` (`interface.cpp`), `FUN_00cb0f50` (declared in
`hkstringptr.cpp` and `hkstringbuf.cpp`) and `MessageCreation::QueueMessage`
(`messagemenu.cpp`, which steps its list by the size of a pointer).

## Not argument lists

- `FUN_0060cd60` in `src/fallout_shared/tesquest.cpp`: `&tESIconComponent + 1`
  and `&tESFullNameComponent + 1`, three sites, step from one member to the
  next. They depend on `TESQuest`'s layout, which this search did not check.
- `FUN_00b304f0` in `src/speedtree/indexedgeometry.cpp`: `(&afValue)[1]`
  through a reference parameter reads the float after the caller's; right
  only if the caller passes an element of an array, which was not checked.
- Views of the bytes of one parameter, within its size:
  `bsshadermanager.cpp`, `hkbinarypackfilewriter.cpp`, `hkpentity.cpp`,
  `caravanmenu.cpp`, `bgssaveloadfile.cpp`, `nipsysdragfieldmodifier.cpp`,
  `hkgpmesh.cpp`, `bstaskmanager.h`, `tileimage.cpp`, `blk_00720000_od.cpp`
  and `blk_00c60000_o2.cpp`.
- A parameter's address kept or passed on without arithmetic, as an out
  pointer or into a table: `hkfreelist.cpp`, `hkmonitorstreamanalyzer.cpp`,
  `hkserializeutil.cpp`, `hkpagent1nmachineprocess.cpp`,
  `hkpworldoperationutil.cpp`, `hkpmoppdefaultassembler.cpp`,
  `hkmatrix3.cpp`, `hkbsdsocket.cpp`, `bstreenode.cpp`, `tesobjectrefr.cpp`,
  `hkclass.cpp`, `hkpmultisphereshape.cpp`, `hkpreportcontactmgr.cpp`,
  `hkpragdolllimitsdata.cpp`, `blk_00c80000_o2.cpp`, `blk_00ca0000_o2.cpp`
  and `blk_00cc0000_o2.cpp`.
- `FUN_00dc12c0` in `hkversionutil.cpp` stores the sum of three parameters'
  addresses, a value that depends on the frame; its purpose is not known.
- The constructor `FUN_00ac5490` in `tile.cpp` computes addresses past
  `signature` into locals that nothing reads.

## Lists already made with va_start

`shader.cpp`, `bgssaveloadglobaldata.cpp` (without `va_end`, which does
nothing on windows-x64), `hkstring.cpp`, `native_string.cpp`,
`bsstring.cpp`, `actorvalue.cpp`, `bsshaderproperty.cpp`
(`ShaderPassEntry::FUN_00ba8c50`), `taskqueueinterface.cpp`,
`bgssaveloadhistory.cpp`, `interface.cpp`, `lovetestermenu.cpp`,
`tesscript.cpp`, `hkstringbuf.cpp`, `hkostream.cpp`, `hkpworld.cpp`,
`blk_00d60000_o2.cpp`, `blk_00d80000_o2.cpp`, `setting.cpp`,
`debugtext.cpp` (`FUN_00a0e710`) and `bgsentrypoint.cpp`, which is not
compiled.
