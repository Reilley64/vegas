# One provider of the leveled list save

`FUN_00488400_shell::SaveLeveledList()` had two definitions in the game
archive. It now has one. No repair-family ticket names this symbol; the units
belong to VEGAS-18. This change is the bounded removal of a placeholder.
Everything else is listed under "Not covered".

## The function

`SaveLeveledList()` is the function at `0x00488400`. `build/units.json` lists
it once as a function, 269 bytes, in the unit
`src/fallout_shared/tesleveledlist.cpp`. That definition carries the address
tag. It writes the list's chance, its flags and, when set, the form id of its
global, then one 12-byte chunk per entry and each entry's extra data.

## The removed definition

`src/fallout_shared/teslevitem.cpp` used to define the same name a second time
with an empty body and no address tag. The recipe gives that unit ten
functions, `0x0050adb0`, `0x0050b400`, `0x0050b490`, `0x0050b4c0`,
`0x0050b530`, `0x0050b560`, `0x0050b800`, `0x0050b840`, `0x0050b890` and
`0x0050b8d0`; none is `0x00488400`. The unit's symbol table binds the name to
`0x00488400`, as a name the unit requires. The empty body was a placeholder
for the callee of `0x0050b530`, not a second function. It is removed. The unit
keeps its declaration.

The recipe records no call edges. That the function at `0x0050b530` calls
`0x00488400` is inferred from the unit's symbol row for the name and from the
body tagged `0x0050b530`, which calls the name once.

## Names and requirers

The recipe binds one name to `0x00488400`, in three units. No other name is
bound to that address, in any unit.

| Recipe unit | Row | Windows-x64 object before | Now |
| --- | --- | --- | --- |
| `tesleveledlist.cpp` | function, 269 bytes, and symbol | defines, 346 bytes; no call of its own | the same |
| `teslevitem.cpp` | symbol | defines, 1 byte; no call instruction | requires; one call, in `0x0050b530` |
| `teslevcreature.cpp` | symbol | requires; one call, in `0x0050a8e0` | the same |

These are all the objects that name the function, among the 2,223 archive
members and every test object of the windows-x64 build. Both definitions were
ordinary functions in sections that allow no duplicate; there was no
select-any body, and there is one definition now.

Before this change the compiler saw the empty body in `teslevitem.cpp` and
emitted no call in `0x0050b530` at all. The call there is new in the object.

No object requires `FUN_0050b530_shell::FUN_0050b530()` or
`FUN_0050a8e0_shell::FUN_0050a8e0()`, the two callers. The recipe has no
symbol row for either address, only their function rows. No generated data
names `0x00488400`, `0x0050b530` or `0x0050a8e0`.

## Which body each call reached, and reaches now

Measured from maps of forced links with every section kept.

| Link | Before | Now |
| --- | --- | --- |
| whole archive, forced | the empty body in `teslevitem.cpp.obj`, the member loaded first | `tesleveledlist.cpp.obj` |
| worker-pool test, forced | `tesleveledlist.cpp.obj`; neither caller is loaded | the same |

So in the forced link of the whole archive the call in `0x0050a8e0` used to
reach the empty body and now reaches the real one. The call in `0x0050b530`
used to be nothing and is now a call of the real one.

## What the real body reads

Measured on the rebuilt windows-x64 object. On its receiver the body reads one
byte at `+0x10`, one byte at `+0x11` and a pointer at `+0x18`, so it needs
`0x20` bytes. It then passes the receiver to the list-head accessor and, for
each entry, reads a pointer at `+0x00`, two 16-bit values at `+0x08` and
`+0x0a`, and a pointer at `+0x10`. It writes nothing to the receiver.

In `tesleveledlist.cpp` the receiver class is `0x28` bytes, with the chance at
`+0x10`, the flags at `+0x11`, the global at `+0x18` and the list at `+0x20`.
Each size below comes from the unit's own declarations compiled with that
unit's command.

| Caller | Object it declares | Receiver it passes | Against the `0x20` bytes read |
| --- | --- | --- | --- |
| `0x0050b530` in `teslevitem.cpp` | `0x50` bytes | the second base, at `+0x40`, `0x10` bytes | 16 bytes short; the reads at `+0x10`, `+0x11` and `+0x18` are past the end of the object |
| `0x0050a8e0` in `teslevcreature.cpp` | `0x70` bytes | the fixed offset `+0x30` | inside the object, but not at a list |

`teslevitem.cpp` declares that second base as a virtual pointer and one
integer. It is not a leveled list declaration.

`teslevcreature.cpp` adds the original release's offset `0x30` to the object
pointer. At 32-bit widths its form base is `0x30` bytes, so `+0x30` is its
leveled list base. On windows-x64 its form base is `0x38` bytes and its
leveled list base starts at `+0x38`. The call passes the last eight bytes of
the form base. That unit's leveled list declaration is also `0x20` bytes with
no virtual pointer, which is not the `0x28`-byte class the real body reads.

So neither caller is safe to run on windows-x64. Before this change one did
nothing and the other could only reach the empty body. This change does not
endorse those declarations or offsets.

## Programs

No program that links today contains any of the three objects.

- The game executable, which loads archive members on demand, loads none of
  them, before or after. Its lists are unchanged and its map is identical
  below the header.
- Of the 55 test programs, 54 link and none of them contains any of the three
  objects. The table of test links is identical before and after.
- The worker-pool test does not link. Forced, its image contains
  `tesleveledlist.cpp.obj` and neither caller, before and after, and its list
  of undefined names is unchanged.

The real body also needs ten project names. Each has one definition in the
archive, but the list-head accessor, the next-node accessor, the form-id
reader and the extra-data writer are other classes' members reached through
casts, as before.

## Not covered

These were open before this change and remain open.

- The receiver in both callers, as measured above. `0x0050b530` needs a
  leveled list declaration for its second base, and `0x0050a8e0` needs its
  base by type instead of by the offset `0x30`.
- One leveled list declaration. `tesleveledlist.cpp`, `teslevitem.cpp` and
  `teslevcreature.cpp` each declare their own, with different sizes on
  windows-x64.
- The other fixed offset in `0x0050a8e0`, `+0x4c`.
- Two more untagged empty bodies in `teslevitem.cpp`,
  `FUN_004855a0_shell::FUN_004855a0()` and
  `FUN_00485680_shell::FUN_00485680()`. Each has one definition and no
  requirer, so neither is a duplicate. The calls beside them go to other
  names.
- No test executes the function: no program that contains it links without
  forcing.

No archive member is added, removed or reordered. `build/units.json` is
unchanged: no name in it changed.
