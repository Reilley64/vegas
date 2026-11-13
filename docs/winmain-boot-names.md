# WinMain's boot calls

WinMain (`0x0086a850`, `src/fallout/misc/main.cpp`) creates the window,
starts the subsystems and runs the message loop. Its main loop, the world
start-up and the render set-up were not reached by name: WinMain called
them through `Receiver86`, a stand-in receiver the unit declares, under
names that nothing defines. This document records the VEGAS-30 steps that
bind four of WinMain's own undefined names to their bodies, the rule that
admitted each one, and why the others stay open.

Windows execution: not run. Nothing here shows what a running game does.

## Steps

| Commit | Address | Bound to | Forced link, undefined names |
| --- | --- | --- | --- |
| cfb37d259 | | moves three class definitions before WinMain | 35,133, unchanged |
| 54c52298b | `0x0086e650` | `FrameUpdate::MainLoop::FUN_0086e650` | 35,133 to 35,132 |
| edc9b18d5 | `0x0086cf20` | `BootInit::FUN_0086cf20(ScenePart*)` | 35,132 to 35,131 |
| 11d745b9b | `0x0086d590` | `fnv_0086d590::RenderSystem::FUN_0086d590` | 35,131 to 35,130 |
| 01b67a2f3 | `0x0086a0a0` | the window procedure, by its declaration | 35,130 to 35,129 |

The counts are those of the forced link of every archive member with no
error limit. Each was measured on a windows-x64 build of the same change
on top of `973b5d612`, before it was applied unchanged to this history:
the parent was built from scratch and each commit then built
incrementally at the same export path, the move commit included. No step leaves a name newly undefined,
adds a duplicate symbol, or changes the imports, the archive members,
their order, or the list of names with differing definitions.

## Authority

These are per-address naming steps under the rule of 2026-11-11 (3) on
the rules page "Symbol naming and native ownership": no naming change
may alter a call's argument list, conversions, receiver or callee, and
each carries an object proof. They are not steps of the stand-in
substitution route, which closed at `2277431b8`. The coordinator ruled
so on 2026-11-12.

## The rule each step follows

The recipe's function row decides the body. For the first three addresses
the row is in `main.cpp` itself, and the unit already defines the member
under the row's name. A member call needs the complete class, and the
three classes were defined after WinMain, so the first step moves their
definitions, verbatim and each in its own namespace, to just before
WinMain. `BootInit`'s parameter type `ScenePart` is declared there by a
forward declaration. That step leaves the object byte identical apart from
the timestamp.

A binding step then changes only the call:

- WinMain's existing cast to `Receiver86*` becomes a cast to the row's
  class. For `BootInit` the argument's existing cast to `Receiver86*`
  becomes a cast to `ScenePart*`. All are casts between unrelated pointer
  types, so receiver and argument keep their values. No cast is added.
- The member's signature is the row's: `void()` for the main loop and the
  render set-up, `void(ScenePart*)` for `BootInit`.
- The stand-in's member declaration that no call uses any more is removed.
- The unit's `symbols` key follows the row: the stand-in's 32-bit name
  becomes the row's name, at the same address. No address, size, row or
  other unit changes.

The window procedure is defined in `src/staging/blk_00860000_od.cpp` as
`LRESULT CALLBACK (HWND, UINT, WPARAM, LPARAM)`. `main.cpp` sees it through
`include/fnv/symbols_0086a000.h`, which gave it the 32-bit widths of
`WPARAM`, `LPARAM` and `LRESULT`. The header now declares the definition's
types, spelled with the fundamental types it uses. WinMain only takes the
function's address, so no call changes. The recipe keys are 32-bit
spellings, which were already equal.

Each step carries an object proof. `main.cpp` was compiled from one export
path with the build's own command at the unit's flags, with `/Ob0`, and
with `/Od /Gy`. Once the old name is mapped to the new one, every section
is equal: bytes, relocations, COMDAT selection and unwind data. The
`.llvm_addrsig` section names the same symbols. For the three bodies that
`main.cpp` defines, the function's sections move earlier in the object,
because the function is now named before its definition. That is the
function order tier of `docs/symbol-naming-batches.md`. Warnings are
unchanged.

`objects.winmain_boot_calls` checks the result in the cross build. Its
table is `tools/function-relocations/winmain-boot-calls.tsv`. It fails when
WinMain's code refers to one of the four former names, or no longer to the
name of one of the four bodies.

## What the steps do not prove

A step credits one provider, a rebuild and a link. It does not prove what
the receiver is. `g_osGlobals` holds the object WinMain allocates and builds
with `FUN_0086c160`. The main loop, `BootInit` and the render set-up each
read it through a different private class of `main.cpp`: `MainLoop` with a
flag at offset 7, `BootInit` with no fields, `RenderSystem` with fields
named for 32-bit offsets up to `0x98`.

The compiler measures these classes on windows-x64 as follows:

- `RenderSystem` is `0xB0` bytes with alignment 8. Its five resources,
  named `resource88` to `resource98` for the 32-bit offsets `0x88` to
  `0x98`, sit at `0x88`, `0x90`, `0x98`, `0xA0` and `0xA8`.
- WinMain allocates the object with `FUN_00401000(0xa4)`, a block of
  `0xa4` bytes. The bound body calls `FUN_00559450` on `resource94` and
  `resource98`, the members at bytes `0xA0` to `0xB0`, which lie partly
  and wholly past the end of that block. The member call asserts a
  receiver of `0xB0` bytes.
- `MainLoop` reads its flag in the byte at offset 7. `include/OSGlobals.h`
  names that byte `layoutPadding7`.

The binding is admitted only because no linking program contains the
object of `main.cpp`. This is addendum (3) of 2026-11-10 on the rules
page. In the windows-x64 build neither `FalloutNV` nor any test executable
that links loads it. The one link that does load it,
`runtime_havok_worker_pool_test`, fails with undefined names before and
after these steps, so it makes no program. In the host build `main.cpp`
does not compile, so no host executable can contain it.

`main` in `src/main.cpp` now composes WinMain's first statements, the
single-instance and remote-session checks (`data-pack-startup.md`), so they
exist twice: in `FUN_0086a850` and in `main`. Exactly one of them may run in
a process. The first `CreateMutexA` keeps its handle open, so a second one
on the same name in the same process returns `ERROR_ALREADY_EXISTS`, and the
second check would show the first message box and return. A program that
calls `FUN_0086a850` from `main` must first drop the checks from one of the
two.

The remaining obligation is the true windows-x64 size of the object that
`FUN_0086c160` builds, and which class that object is.

`main.cpp` reads `g_osGlobals` through more views than the three bound
bodies' classes. Where its source names `g_osGlobals`, it also reads the
object as `OSGlobals*`, its declared type, as raw bytes, and through these
classes:

- `Receiver86`, the stand-in receiver;
- seven shell classes cast from `Receiver86`: `FUN_00871c90_shell`,
  `FUN_004f15a0_shell`, `Twin_0044ddc0`, `MagicCaster_shell`,
  `FUN_004e2190_shell`, `FUN_005dc960_shell` and `FUN_00678ce0_shell`;
- `OSGlobals_ML`, `AudioGlobalHelper`, `FUN_008774a0_shell` and a second
  `FUN_004e2190_shell` in namespace `fnv_008727d0`, each a pointer type
  the global is reread as;
- `FUN_00877430_shell`, `FUN_005bb4d0_shell` and `FUN_008776e0`, cast from
  those.

Other units read the same global through further classes. Whether these
views agree with each other and with the object's real layout is open.

The scene pointer that `BootInit` receives is also unproved. WinMain
passes the result of `FUN_0045c670`, seen as a `BSFaceGenNiNode*`, cast to
`ScenePart*`. `ScenePart` is only declared, so the cast is a reinterpret
cast and keeps the pointer's value. It stays one only while `ScenePart` is
unrelated to `BSFaceGenNiNode`: if a later declaration makes one a base of
the other, the same cast becomes a conversion that may adjust the pointer,
and the call has to be proved again.

## WinMain's other undefined names

WinMain's own code section referred to 54 names that a link rooted at
WinMain left undefined, 13 of them Windows imports, and after these steps
50 remained. Those counts use the historical link command, which names no
`user32.lib`. Measured again at `d5d1d60ec` with the lazy link rooted at
WinMain, WinMain's code refers to 49 undefined names with the historical
command, 13 of them imports. With `user32.lib` added, the method since
`891a44f50`, it refers to 39, and the 3 imports among them are
`GetStockObject` (gdi32), `CommandLineToArgvW` and `ShellExecuteA`
(shell32). The call repair of `0x008774a0` (below) leaves 48 and 38. None of
the others is bound here:

- Bodies whose signature differs from the call: a discarded `bool` result
  (`0x0086ba10`), integer widths of results or arguments (`0x004da670`,
  `0x004f15a0`), different pointer types (`0x0086d580`,
  `0x0086bff0`, `0x004a0ea0`, `0x0049fef0`), a pointer passed where the body
  takes `int` (`0x0086bd90`), variadic declarations called with arguments
  the body types differently (`0x0086bce0`, `0x0086bde0`, `0x0086be90`), and
  stand-in members whose body is a free function (`0x0086bda0`,
  `0x00460140`, `0x004a0370`, `0x00559450`, `0x008526c0`). Binding any of
  these changes an argument, result or receiver conversion, which a naming
  step may not do.
- `0x0086bc60`: same signature, but the call goes through `this` of
  `FUN_0086bc10_t`, while the row's class is another private class of the
  same object. Binding it needs one class for both, not a new cast.
- Two destructors (`FUN_00450770`, `FUN_008784d0`): `main.cpp` sees each
  class through a member-only header with a non-virtual destructor, while
  the body is the virtual destructor of a polymorphic class. They need a
  shared declaration of the class.
- Folded addresses whose rows belong to shared template work: the setting
  accessor `0x00408d60` (`SettingT<INISettingCollection>::Bool`, the shared
  `SettingT` of VEGAS-70), its collection getters, `NiPointer` assignment
  at `0x0066b0d0` (VEGAS-16), `NiTArray` members at `0x00877a30` and
  `0x00877a50`.
- No body to bind: `0x00406d50` has no function row, `UNK_010828ec` is data
  with no definition, `Sky::pInstance` has no recipe address, and the
  `NiTArray::SetAt` names have no linkable body under the row name.
- The Windows imports of `user32`, `gdi32` and `shell32`. Their
  declarations already come from the Windows SDK headers. They resolve
  only when the import libraries are on the link line, which is a build
  decision and not a naming step.

## The boot functions' callees

Later VEGAS-30 steps bind five more names that functions of `main.cpp`
on the boot path called and no object defined. Each call went through a
declaration scoped to the calling function's own namespace
(`fnv_<address of the caller>`), while the unit already declares the row's
function or class at file scope with the same signature.

| Commit | Address | Caller | Bound to | Forced link, undefined names |
| --- | --- | --- | --- | --- |
| 2235d9f30 | `0x00706320` | `FUN_008774a0` | `FUN_00706320(int)` | 35,079 to 35,078 |
| 21b703730 | `0x004a0e90` | `FUN_00876850` | `FUN_004a0e90()` | 35,078 to 35,077 |
| 76b06a11b | `0x004a0e90` | `FUN_00873200` | `FUN_004a0e90()` | 35,077 to 35,076 |
| b8345b3e2 | | | moves `BSRenderedTexture` before `FUN_00874ac0` | 35,076, unchanged |
| 355dac128 | `0x00b6b790` | `FUN_00874ac0` | `BSRenderedTexture::EndAllAndResetRendererState()` | 35,076 to 35,075 |
| d365ec8de | `0x0043d410` | `FUN_00877730` | `NiUpdateData::NiUpdateData(float, bool, bool)` | 35,075 to 35,074 |

The counts were measured on a windows-x64 build of the same changes on top
of `891a44f50`, at one export path, before they were applied unchanged to
this history. They use the historical link command, which names no
`user32.lib`; with the command that links it, the method since `891a44f50`,
the same five names leave 35,039 (35,034, derived and not linked). The projected closure from WinMain, which
follows names to bodies under other names, loses one name with each
binding step: 20,979 to 20,974. No step leaves a name newly undefined,
adds a duplicate symbol, or changes the imports, the archive members,
their order, or the list of names with differing definitions.

Each step changes one declaration and no cast:

- `0x00706320` and `0x004a0e90`: the scoped declaration of the free
  function is removed, so the call names the file-scope declaration with
  the same signature.
- `0x00b6b790` is a static member, so the call has no receiver. The call
  now names the file-scope `BSRenderedTexture`, a copy of
  `include/fnv/decl/BSRenderedTexture.h` that the unit declares itself and
  whose static member the unit's other functions call, and the scoped class, which nothing else
  used, is removed. That class was defined after `FUN_00874ac0`, so the
  step before moves its definition there verbatim. The move leaves the
  object identical apart from the timestamp.
- `0x0043d410`: `FUN_00877730`, which `BootInit` calls, built two locals
  of its own copy of `NiUpdateData`. The copy's fields agree with
  `include/fnv/decl/NiUpdateData.h`, which the unit includes and the
  constructor's owner uses: a float and five bools, 12 bytes with
  alignment 4. The locals now take that class. The copy's constructor
  declaration, which nothing else used, is removed. Other functions of
  `main.cpp` build copies that disagree with the header, with an `int` at
  offset 4 or 8, and stay on them.

The unit's `symbols` key of the scoped name is merged into the key of the
row's name, which the unit already had at the same address.

The object proof is the one above, with the old name mapped to the new.
For four steps every section is equal apart from `.llvm_addrsig`, which
names the same symbols. The step at `0x00706320` also changes the code of
`FUN_008774a0` at the unit's flags and with `/Ob0`: the call no longer
sets the argument register to 0, and the function is two bytes shorter.
The compiler now sees, in the same object, that `FUN_00706320` does not
read its parameter. WinMain's existing call of the same function is
compiled the same way. With `/Od /Gy` the function is equal apart from the
call's target. Warnings are unchanged.

`objects.winmain_boot_calls` checks these functions too, as the table's
batch `callees`. Each binding step's table fails on its parent's object.

These steps prove no more than the ones above. `FUN_00706320`'s body does
not read its `int` parameter; whether the original function reads it is
not established. Which object `FUN_00877730`'s update data describes, and
what the callee does with it, is open. The binding is admitted on the same
condition: no linking program contains `main.cpp`. Measured again on the
windows-x64 build of `891a44f50` and of the last step, 83 executables are
linked, 64 read `game.lib`, and only `runtime_havok_worker_pool_test`
loads `main.cpp`'s object. That link fails with undefined names in both
builds.

The other names that these functions and the boot functions call were
refused for one of these reasons:

- The call goes through `this` of the calling function's class, while the
  row's class is another private class of the unit, as for `0x0086bc60`
  above. This includes three of the main loop's own calls.
- A constructor or destructor of the unit's private copy of a real
  class, such as the player character `BootInit` creates and the scene
  nodes of the render set-up. Binding them needs a shared declaration of
  the class with an established layout: `new` of the copy passes the
  copy's size.
- The unit's private copy disagrees with the shared declaration it
  includes (`NiUpdateData` in `BootInit` and the render set-up).
- Template members and shared classes other work owns: `SettingT`,
  `NiPointer`, `ImageSpaceEffectParam`, `NiFixedString` and the list
  templates.
- Binding would change an argument, result or receiver conversion, or the
  form of the call, as for the names listed above.

## Call repairs

VEGAS-90 repairs two calls on the boot path that named their bodies through
stand-ins, under names that no object defines, and passed an argument whose
type is not the type of the body's parameter. Each call now takes the
parameter type of the recipe's function row, and each repair is admitted by
its own ruling of 2026-11-13. Both bodies are defined in `main.cpp` at
their rows, and each has one caller, also in `main.cpp`. With every recipe
entry of every source merged, no other unit has a `symbols` key at the two
addresses.

| Address | Caller | Row | Argument before | Argument now | Authority |
| --- | --- | --- | --- | --- | --- |
| `0x008774a0` | WinMain | `fnv_008774a0::FUN_008774a0_shell::FUN_008774a0(bool)` | the constant `1` for an `int` | `1`, converted to `true` | constant to bool |
| `0x008707c0` | `FUN_008706b0` | `fnv_008707c0::RenderMgr::FUN_008707c0(void*, bool)` | the texture pointer | the same pointer, converted to `void*` | R5a |

The authorities:

- `0x008774a0`: the named admission "constant to bool". A call whose
  argument is the literal 0 or 1 may bind to a row whose parameter is
  `bool` when the conversion is implicit, the value is kept, the object
  differs only in the argument move and its unwind offsets, and the call
  has a row in a check table. This call is its first case. The body only
  tests the flag. The displaced jumps, the padding and the body's moved
  sections listed below are consequences of the move and of the binding,
  and the coordinator admitted them with it on 2026-11-13.
- `0x008707c0`: R5a. A naming step may bind a call whose only added
  conversion is the implicit conversion of an object pointer to `void*`,
  with no qualifier dropped, when the object is equal after the rename
  apart from the callee's name, the call has a row in a check table, and
  the receiver is recorded as open.

Neither repair adds a cast. The call's existing cast to the stand-in,
`Receiver86` or `MainStub`, now names the row's class. The stand-in's
member that the call used goes, and `main.cpp`'s `symbols` key takes the
row's name at the same address. A first commit moves the two classes,
verbatim, to before `FUN_008706b0` and WinMain. It leaves the object of
`main.cpp` identical apart from the timestamp.

The forced link of every archive member, with no error limit and with
`user32.lib` (the cells of the tip baseline method since `891a44f50`),
leaves 35,034 names undefined at `d5d1d60ec`. Each repair takes one
name: 35,033, then 35,032. The historical command counts 35,074, 35,073
and 35,072. No name enters, and the duplicate symbols (none), the imports,
the archive members and their order, and the list of names with differing
definitions (519) do not change. The projected closure from WinMain, which
counts `user32` names as system names, goes from 20,932 to 20,930.

### The object proof

`main.cpp` was compiled from one export path with the build's own command
at the unit's flags, with `/Ob0`, and with `/Od /Gy`.

For `0x008774a0`, WinMain's code changes in one instruction: `movl $1, %edx`
(5 bytes) becomes `movb $1, %dl` (2 bytes), because the second argument is
now a `bool`, and the call's relocation names the row. The code after it
moves 3 bytes earlier up to the next alignment padding, which grows by 3
bytes, so the code after the padding keeps its offsets. The relative jumps
across the moved span keep their targets and are encoded with a
displacement 3 bytes shorter or longer: 5 at the unit's flags, 6 with
`/Ob0`, 7 with `/Od /Gy`. The unwind data changes only in the offsets of
the moved span:

| Variant | Code | `.pdata` | `.xdata` |
| --- | --- | --- | --- |
| unit flags | the padding before offset `0x12a0` grows from 9 to 12 bytes; the function stays 5,178 bytes | equal | two entries of the instruction-to-state map, `0x10d4` and `0x10f5`, become `0x10d1` and `0x10f2` |
| `/Ob0` | the padding before the second range grows by 3 bytes | the first range ends at `0x11c5` instead of `0x11c8` | one entry, `0x11ab`, becomes `0x11a8` |
| `/Od /Gy` | the padding before the second range grows by 3 bytes | the first range ends at `0x1c91` instead of `0x1c94` | one entry, `0x1c3e`, becomes `0x1c3b` |

The body's own sections also move earlier in the object, because WinMain
now refers to the body's name before its definition. This is the function
order tier of `docs/symbol-naming-batches.md`. `.llvm_addrsig` differs and
names the same symbols. No other section changes.

For `0x008707c0`, once the former name is mapped to the row's name, every
section is equal apart from `.llvm_addrsig`, which names the same symbols.
The body's sections move earlier in the object, the function order tier of
`docs/symbol-naming-batches.md`. `FUN_008706b0` changes only its call's
target. Warnings are unchanged.

`objects.boot_call_repairs` checks the result in the cross build. Its table
is `tools/function-relocations/boot-call-repairs.tsv`, with one row per
repair. It fails when WinMain or `FUN_008706b0` refers to a former name, or
no longer to the name of a body. Each repair's table fails on its parent's
object.

### Two calls that stay open

`FUN_008706b0` makes two more calls of the same kind. Both pass the
texture pointer where the row's parameter has another type, and an
explicit cast at the call was refused on 2026-11-13, even one that keeps
the address and leaves the object equal: the rule concerns the source. Both
names stay undefined, and `MainStub` keeps their two members.

- `0x00870bd0`: the row is
  `fnv_00870bd0::RenderCoordinator::FUN_00870bd0(int, bool)`, which the
  source defines with `std::intptr_t`. The body uses the value only as an
  address. The route without a cast is a
  repair of the definition: the parameter becomes `void*`, as `b6619dc9a`
  did for `0x008707c0`, and so does the second parameter of `0x00876830`,
  to which the body passes it. That repair is queued under VEGAS-97, with
  its own object proof and reviews.
- `0x00870a00`: the row is
  `SceneRendererStub870::FUN_00870a00(TexStub870*, bool)`, and `TexStub870`
  is only declared. It waits for a shared declaration of the texture type.

### What the repairs do not prove

A repair, like a naming step, proves only that each name has one provider,
that the build succeeds and that the link resolves it. The compiler
measures the receivers on windows-x64 as follows:

- `FUN_008706b0` is a member of `fnv_008706b0::FUN_008706b0_shell`, which
  derives from the unit's `Main` and is 1 byte. It passes its own `this` as
  `RenderMgr` for `0x008707c0`: 0x98 bytes with alignment 8, its 35 `int`
  fields at `0x0` to `0x88` and `name`, a pointer, at `0x90`. The two open
  calls pass the same `this` as `RenderCoordinator`, 0x8c bytes with
  `shaders` at `0x88`, and as `SceneRendererStub870`, 1 byte.
- WinMain passes the object of `g_osGlobals` as
  `fnv_008774a0::FUN_008774a0_shell`, 1 byte. That class is already among the
  views of that object listed above.

Which class each object is, and how large, stays open.

The binding is admitted on the same condition as the steps above: no
linking program contains `main.cpp`'s object. Measured on the windows-x64
builds of `d5d1d60ec` and of the last repair, the build has 86
executables, 66 of their links read `game.lib`, and only `runtime_havok_worker_pool_test` loads
`main.cpp`'s object. That link fails with undefined names in both builds.
Before any program loads the object, two more obligations hold, added by
the coordinator on 2026-11-13:

- `FUN_008706b0`'s receiver: a 1-byte shell passed as `RenderMgr`, 0x98
  bytes, and as `RenderCoordinator`, 0x8c bytes.
- No name that the program's link keeps may be in the list of names with
  differing definitions.

The second one covers a change in model links. From the first repair on,
`main.cpp`'s object asks for archive members in another order. The lazy
links rooted at WinMain, at WinMain with `main`, and at the main loop load
the same 2,002 or 2,011 members, and from the `0x008707c0` repair on, 22
type-information names that the archive defines with more than one
content get another first-loaded copy:
`shadowscenenode.cpp`'s for one, `tesobjectweap.cpp`'s for the others. For
7 of them the old and the new copy
have the same content: the base class descriptor of `Base` and the three
type-information records of `TESFullName` and of `TESModel`. For 15 they
differ: those of `BGSDestructibleObjectForm`, `TESAttackDamageForm`,
`TESHealthForm`, `TESIcon` and `TESScriptableForm`. The links rooted at
`main`, which is `FalloutNV`'s own link, and at `InitStartMenu` do not
change. These links are models and no program uses them, so the
coordinator ruled that they need no guard now.
