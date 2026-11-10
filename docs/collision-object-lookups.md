# One emission of the collision object lookups

VEGAS-17 owns the `bshavok` units. No repair-family ticket names these three
symbols. This change is bounded: the three `bhkCollisionObject` members that
`src/bshavok/bhkcollisionobject.h` defines are now emitted by one object
instead of two. Everything else is listed under "Not covered".

## The functions

| Address | Member | Recipe size |
| --- | --- | --- |
| `0x0056d5b0` | `bhkCollisionObject::GetRTTI() const` | 16 |
| `0x0043b610` | `bhkCollisionObject::GetFromNiAVObject(NiAVObject*)` | 36 |
| `0x004b5a20` | `bhkCollisionObject::GetFromRigidBody(const hkpRigidBody*)` | 40 |

`GetRTTI` returns the address of the global at `0x012043f8`. Each lookup
calls one function to obtain an object, then passes it with that same global
to the function at `0x00653270` and returns the result. None of the three
writes through a pointer. This is the recovered behaviour and it is
unchanged.

## What the recipe says

`build/units.json` lists `src/bshavok/bhkcollisionobject_h_unit.cpp` three
times, once per set of compiler flags. The unoptimised unit has the three
function rows above and no other function. No other unit has a function row
at any of the three addresses.

`src/bshavok/bhkcollisionobject.cpp` has no unit in the recipe, and has had
none since the first commit. The file held one line, the include of
`bhkcollisionobject.h`.

The header defines the three members out of line and not inline. So each
unit that includes it emits them. Two did: the recipe's unit and the file
with no unit. That is one transcription emitted twice, not two functions.
The recipe decides the owner: the address rows belong to
`bhkcollisionobject_h_unit.cpp`.

Symbol rows for the three names:

| Name | Rows | Address in every row |
| --- | --- | --- |
| `GetFromNiAVObject` | the owning unit and 13 requiring units | `0x0043b610` |
| `GetFromRigidBody` | the owning unit and 11 requiring units | `0x004b5a20` |
| `GetRTTI` | none | function row only |

A requiring unit that the recipe builds more than once is counted once.

The recipe binds two more names to these addresses, each in one unit:

| Address | Other name | Unit | Windows-x64 archive |
| --- | --- | --- | --- |
| `0x0043b610` | C function `FUN_0043b610` | `src/fallout_shared/havok/teshavokutilities.cpp` | required by that object, defined nowhere |
| `0x004b5a20` | global `FUN_004b5a20(int)` returning `SrcC*` | `src/fallout/ai/playercharacter.cpp` | required by that object, defined nowhere |

No other name is bound to `0x0056d5b0`.

## The change

`bhkcollisionobject.cpp` now includes `bhkcollisionobject_decls.h`, the
declarations the header itself includes, in the way
`src/gamebryo2.2/corelibs/nimain/niobject.cpp` includes only its
declarations. Its object stays in the archive at the same position and now
defines and requires nothing. The header and the owning unit are untouched.

## The two emissions were the same code

At the previous tip, in the windows-x64 archive:

| Name | Bytes | Relocations | Both objects |
| --- | --- | --- | --- |
| `GetRTTI` | 8 | 1 | same bytes, same relocation |
| `GetFromNiAVObject` | 28 | 3 | same bytes, same relocations |
| `GetFromRigidBody` | 28 | 3 | same bytes, same relocations |

All six were ordinary functions in sections that refuse a second definition.
None was select-any. Now each name has one definition, in
`bhkcollisionobject_h_unit.cpp.obj`, with the same bytes as before.

## Requirers

From the objects of the windows-x64 build, before and after:

- `GetFromNiAVObject`: 13 objects require it. `arrowprojectile`,
  `projectile`, `grenadeprojectile`, `mobileobject`, `reanimateeffect`,
  `bgsdestructibleobjectform`, `bipedanim`, `globalfunc`,
  `teshavokutilities`, `navmeshobstaclemanager`, `blk_00560000_o2`,
  `blk_00620000_o2` and `blk_008c0000_o2`.
- `GetFromRigidBody`: 11 objects require it. `actor`, `playercharacter`,
  `grenadeprojectile`, `fovatseffectmanager`, `tesarrowtargetlistener`,
  `focollisionlistener`, `blk_008a0000_o2`, `blk_008c0000_o2`,
  `blk_008c0000_od`, `blk_009a0000_o2` and `blk_009a0000_od`.
- `GetRTTI`: one object requires it, the generated dispatch table object
  `vtables_0103.cpp.obj`. Its source names the function by its address, as
  the third entry of the table at `0x0103046c`. No other generated file names
  any of the three.

No test names any of the three.

## Which body each requirer reached

The owning object precedes the other in the archive. In a link forced to
accept duplicates the first loaded definition is kept. Measured in four
forced links with a map, of the whole archive and of the worker-pool test,
each with and without collection of unreferenced sections:

| Name | Previous tip | Now |
| --- | --- | --- |
| `GetRTTI` | `bhkcollisionobject_h_unit.cpp.obj` | the same |
| `GetFromNiAVObject` | `bhkcollisionobject_h_unit.cpp.obj` | the same |
| `GetFromRigidBody` | `bhkcollisionobject_h_unit.cpp.obj` | the same |

So no path reaches a different body. The body that was reachable is the one
kept.

## Programs

- The game executable loads archive members on demand. It loads neither
  object, before or after. Its map is unchanged below the header.
- Of the 55 test programs, 54 link and none contains either object.
- The worker-pool test does not link. Forced, its closure contains
  `bhkcollisionobject_h_unit.cpp.obj` and not `bhkcollisionobject.cpp.obj`,
  before and after.

## Measured links

Windows-x64, 2,223 archive members in the same order before and after. One
object differs, `bhkcollisionobject.cpp.obj`: it loses the three definitions
and the four names they required.

| Link | Previous tip | This change |
| --- | --- | --- |
| on demand, ordinary and unlimited | links, 78 imports | every list identical |
| forced, whole archive: duplicate symbols / blocks | 7 / 14 | 4 / 11 |
| forced unlimited: undefined names | 35,674 | the same 35,674 |
| forced unlimited: imports | 137 | the same 137 |

The three symbols that leave are the three above, one block each. None
enters.

The build has one warning fewer: the file no longer parses the class header.

## Not covered

These were open before this change and remain open.

- The two other names of `0x0043b610` and `0x004b5a20` in the table above.
  Each is a second name for a function this change keeps, under a different
  signature, and each is still undefined. Joining them to the members needs
  the callers' argument types, which this change does not establish.
- The class declaration. `include/fnv/decl/bhkCollisionObject.h`, which the
  requirers include, declares the class with the two static members only.
  The header of the owning unit declares it with a base and two virtual
  members. The static members are named alike under both.
- The bodies reach their callees through casts to stand-in classes. The
  second lookup calls the function at `0x004b5a50` under the name
  `NiShader::DynamicCast`; that this name is a stand-in is an inference from
  its argument type. Each callee name has one definition in the archive.
- The header still defines the three members out of line. A second includer
  would emit them again. Only the owning unit includes it now.
- Nothing executes these functions. In the forced links the owning object
  loads beside 35,674 undefined names.

`build/units.json` is unchanged: no name in it changed.
