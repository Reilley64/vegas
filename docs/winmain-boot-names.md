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

WinMain's own code section refers to 54 names that a link rooted at WinMain
leaves undefined. 13 of them are Windows imports. After these steps 50
remain. None of the others is bound here:

- Bodies whose signature differs from the call: a discarded `bool` result
  (`0x0086ba10`), integer widths of results or arguments (`0x004da670`,
  `0x004f15a0`, `0x008774a0`), different pointer types (`0x0086d580`,
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
