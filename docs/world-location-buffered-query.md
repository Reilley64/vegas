# World-location buffered-cell query binding

VEGAS-76 removes the second definition of `CoordinateTriple::FUN_00527a00()`.
The one definition left is the function at `0x00527a00` in
`src/fallout_shared/bgsworldlocation.cpp`.

This is the binding only. It is not the typed world-location result the ticket
asks for; see "Not covered".

## What the recipe says

`build/units.json` lists `?FUN_00527a00@CoordinateTriple@@QAE_NXZ` as a
function of one unit, `src/fallout_shared/bgsworldlocation.cpp`: address
`0x00527a00`, size 51. No other unit lists a function at that address or under
that name.

The unit `src/fallout_shared/teleportdata.cpp` does not list it as a function.
It lists it as a required symbol bound to `0x00527a00`, for its function
`FUN_009a96f0` (`0x009a96f0`, size 45). The definition that
`teleportdata.cpp` carried returned false, had no address annotation and no
recipe identity. It was a placeholder for the callee of `FUN_009a96f0`, not a
second function. It is removed; the unit keeps the declaration and the call.
No name changes, so `build/units.json` is unchanged.

## Every requirer

Two objects require the name, and the recipe binds both to `0x00527a00`:

| Object | Call site | Receiver passed |
| --- | --- | --- |
| `teleportdata.cpp` | `FUN_009a96f0` (`0x009a96f0`) | its `CoordinateTriple*` argument |
| `combatgroup.cpp` | the function at `0x0098a580` | the address of its 16-byte `Location` member, through a cast |

`FUN_009a96f0` has one definition and two requiring objects:

| Object | Caller | Location passed |
| --- | --- | --- |
| `combatgroup.cpp` | `ActorPicker::SelectActor` (`0x00986c60`) | a local 16-byte `PoseData`, filled by `FUN_00575650` |
| `combatstate.cpp` | `CombatNodeFinder::FindNearestCombatNode` (`0x0098c3d0`) | a local 16-byte `Loc2S`, copied from the result of `FUN_0043a390` |

No generated data names `FUN_00527a00`, `FUN_009a96f0` or `FUN_00527900`. No
archive member is added, removed or reordered.

## The owner

`0x00527a00` resolves the location to a cell through `FUN_00527900`
(`0x00527900`, same unit) and, when there is one, returns
`TESCallHelper::IsCellBuffered(cell, false)` on the global `g_TES`.
`include/fnv/decl/TESCallHelper.h` declares that query at `0x004511e0`.

`FUN_00527900` reads the location's form pointer. A null pointer gives no
cell. A form of type `0x39` is the cell. A form of type `0x41` is a worldspace:
the cell is `GetCellAtGridPosition` of the first two coordinates, each
converted to an integer and shifted right by 12 with sign. Any other type
gives no cell.

## Behaviour before and after

No program that contains `FUN_009a96f0` or the caller at `0x0098a580` links
today, before or after this change: the complete link still stops on the other
duplicate definitions. The successful lazy link of the game executable
extracts none of these units.

These units also cannot link because they require names that are defined
nowhere. `teleportdata.cpp.obj` requires three:
`FUN_00431ae0::FUN_00431ae0(int)`, `g_TESSaveLoadGame` and
`Flt::operator unsigned int`. `bgsworldlocation.cpp.obj` requires four:
`TESForm::FNV_GetFormType`, `NiPoint3::operator-`,
`fnv_00527a40::NiPoint3::operator-` and
`fnv_00527a40::NiPoint3::UpdateCombatStyle`. `combatgroup.cpp.obj` requires
119 such names and `combatstate.cpp.obj` 163.

Before, the placeholder was visible to the compiler in `teleportdata.cpp`, so
the windows-x64 object's `FUN_009a96f0` was a single jump to `FUN_005653d0`:
the location argument was never used. The caller at `0x0098a580` required the
name from outside its unit, and a link that contained it failed on the
duplicate. Which definition a link forced past the duplicate gave that caller
was the linker's choice and is not established here.

After, `FUN_009a96f0` calls `FUN_005653d0` and, when that returns false, the
function at `0x00527a00`, and the caller at `0x0098a580` reaches the same
function. That is what the recipe binds both to. The location's form pointer
is now read, a non-null form is asked for its type, and a worldspace is asked
for a cell. The value returned by `0x00527a00` is still false whenever it
returns, because the only definition of `TESCallHelper::IsCellBuffered`, in
`src/fallout_shared/tes.cpp`, returns false unconditionally. That definition
is taken to be a placeholder and is not touched here.

This is recovered behaviour of the two addresses, not a native policy. This
change sets no native policy.

## Not covered

These were open before this change and remain open in VEGAS-76.

- **The location's size.** The producer `FUN_0043a3c0` writes three floats and
  a form pointer. `FUN_00527900` reads through a shell of two floats, an
  integer and a form pointer. Both place the pointer at offset 12 in the
  original release's 32-bit layout and at offset 16 in a windows-x64 object,
  where the producer's object is 24 bytes. The three callers above hold
  16-byte locations of four 32-bit words. In a windows-x64 object the read of
  the form pointer is therefore past the end of each caller's location.
  Measured in the rebuilt windows-x64 objects:
  - `SelectActor` (`0x00986c60`) was not memory-safe at the previous tip.
    `FUN_00575650` already builds the 24-byte object in the 16-byte `PoseData`
    local. Its 8-byte store at +16 lands on a 4-byte local and on the first
    four bytes of the function's other `PoseData`. The query's new read is of
    those same 8 bytes.
  - `FindNearestCombatNode` (`0x0098c3d0`) was not memory-safe either. It
    calls both producers with a null result pointer, at
    `combatstate.cpp:5291`, `5306` and `5310`, and each producer stores
    through that pointer. The first two calls come before the query.
  - In the caller at `0x0098a580` the read at +16 lands on the group's
    `position`, the member after `location`, inside the object.
  - `FUN_00575650` passes the form pointer through `int`, so only its low 32
    bits survive. It does the same to the position pointer.

  The removed placeholder kept `FUN_009a96f0` from reaching this read; it did
  not repair any of this. The repair is one typed 24-byte location shared by
  producers, callers and this query, and result buffers that are not null,
  which is the body of the ticket. Both must land before any `IsCellBuffered`
  supplier is admitted.
- **`IsCellBuffered`.** The recipe lists the function at `0x004511e0` in
  `src/fallout_shared/tes.cpp` under another name, and the ticket records that
  its present body is not an admitted buffered-state supplier. Until one
  exists, this query cannot return true.
- **The first predicate of `FUN_009a96f0`**, `FUN_005653d0` (`0x005653d0`,
  reference persistence), is called through a cast of the reference and is
  unchanged.
- **Tests.** `teleportdata.cpp` does not compile for the host, and no
  windows-x64 program containing it links, so no test executes this path. The
  evidence is the rebuilt windows-x64 object, the composed archive and the
  complete links.
