# One provider of the pathing request constructor

VEGAS-64 asks for one shared request and close-point declaration with genuine
construction and retirement. This change is the bounded first part: the global
`PathingRequest::PathingRequest()` now has one definition. Everything else on
the ticket is listed under "Not covered".

## The constructor

`PathingRequest::PathingRequest()` is the function at `0x006e2420`.
`build/units.json` lists it once as a function, 428 bytes, in the unit
`src/fallout_shared/pathfinding/pathingrequest.cpp`, together with its
exception tail at `0x00f05a70`. That definition constructs its `PathingInfo`
base first, then the two locations, the actor data, the centre and the
avoidance reference, and stores the defaults.

`src/fallout_shared/pathfinding/pathingrequestclosepoint.cpp` used to define
the same name a second time with an empty body. The recipe gives that unit six
functions, `0x006e3f30`, `0x006e3f70`, `0x006e3fb0`, `0x006e4030`, `0x006e5f00`
and `0x006e5f50`; none is the constructor. The unit's symbol table binds the
constructor's name to `0x006e2420`, as a name the unit requires. The empty body
was a placeholder for the callee of the close-point constructor `0x006e3f30`,
not a second constructor. It is removed. The unit keeps its declaration, and
in the windows-x64 object `FUN_006e3f30::FUN_006e3f30()` now calls the one
definition.

The recipe records no call edges. That the function at `0x006e3f30` calls
`0x006e2420` is inferred from the unit's symbol row for the constructor's name
and from the body tagged `0x006e3f30`, which constructs its base first.

No second address exists for this name: every unit that names
`PathingRequest::PathingRequest()` in the recipe binds it to `0x006e2420`.

## Requirers

Seven objects name the global constructor. All bind it to `0x006e2420`.

| Object | Use |
| --- | --- |
| `pathingrequest.cpp` | the definition; `CreateRequestForType` case 0 |
| `pathingrequestclosepoint.cpp` | base construction in `0x006e3f30` |
| `lowprocess.cpp` | three automatic requests |
| `highprocess.cpp` | two automatic requests |
| `middlehighprocess.cpp` | two automatic requests |
| `blk_006e0000_od.cpp` | base construction in `0x006e4080`, the factory's case 1 |
| `blk_008c0000_od.cpp` | one automatic request |

`searchpackage.cpp` requires it indirectly: its object requires
`FUN_006e4080::FUN_006e4080()`, which `blk_006e0000_od.cpp` defines.

The recipe's unit of `blk_006e0000_od.cpp` also has a symbol row that binds
`FUN_006e3f30::FUN_006e3f30()` to `0x006e3f30`. No object emits that name as a
requirement; the object of that unit requires the address as
`PathingRequestClosePoint::PathingRequestClosePoint()` instead.

Before this change a link that needed the constructor had two candidates, and
one of them left the whole request unwritten. Now the factory and the five other
clients can only reach the definition that initializes it.

Other units reach `0x006e2420` under names of their own, such as
`CoverRequest`, `PathingRequestHelper` or a `PathingRequest` inside a
namespace. Those names have no definition and are not changed here.

## Behaviour of the close-point constructor

Before, the windows-x64 object's `FUN_006e3f30::FUN_006e3f30()` ran no base
construction and wrote only its own three stores. Now it runs the request
constructor first. That the function at `0x006e3f30` does so is the inference
stated above.

No program reaches it today. Nothing requires the name
`FUN_006e3f30::FUN_006e3f30()`. The factory, `middlehighprocess.cpp` and
`blk_006e0000_od.cpp` require the address under the name
`PathingRequestClosePoint::PathingRequestClosePoint()`, which has no
definition. Each of the seven objects above also needs names that no object
defines, so a program that contains one does not link without forcing. For the
five clients the request destructor is among them. For the definition's unit
they include the constructors of the location, the actor data, the centre and
the avoidance reference.

That is also why calling it would not be safe yet. The close-point unit
declares its own `PathingRequest` with one pointer member and writes the
derived fields at the original release's fixed offsets `0xb0` and `0xb4`. The
definition constructs the full shared class, which is larger than both. This
change does not endorse those declarations or offsets.

## Storage each client gives the constructor

Measured on windows-x64: the constructor from the rebuilt object, each size
from the unit's own declaration compiled with that unit's command, and each
allocation from the size the object passes to `operator new`.

The constructor's highest write is one byte at `+0xfc`, so it needs `0xfd`
bytes.

| Storage | Unit | Bytes | Short by |
| --- | --- | --- | --- |
| factory case 0, allocated | `pathingrequest.cpp` | `0x100` | fits |
| automatic requests | `lowprocess.cpp` | `0x100` | fits |
| automatic requests | `highprocess.cpp` | `0xb8` | 69 |
| automatic request | `blk_008c0000_od.cpp` | `0xb8` | 69 |
| automatic requests | `middlehighprocess.cpp` | `0xe8` | 21 |
| base of `FUN_006e4080` | `blk_006e0000_od.cpp` | `0xb8` | 69 |
| `FUN_006e3f30`, whole object | `pathingrequestclosepoint.cpp` | 16 | 237 |

The `0xb8` base of `FUN_006e4080` sits inside a class of `0xf8` bytes, so the
constructor's writes run into the class's own members and 5 bytes past its
end. Factory case 1 allocates `0x140` bytes for it. `searchpackage.cpp`
declares the class with `0xec` bytes and embeds it at `+0xb0` of its own
object. In `pathingrequestclosepoint.cpp` the request base is 8 bytes of the
16.

None of these sites can execute today, for the reason given above: no
program that contains one links without forcing.

## Not covered

These were open before this change and remain open.

- One shared request and close-point declaration. The five clients, the
  close-point unit and the pathfinding units each declare their own request
  class. Their sizes and members are not reconciled.
- The close-point constructor's identity. `0x006e3f30` is defined as
  `FUN_006e3f30` and required as `PathingRequestClosePoint`. They are not
  connected here, because the definition's class is not the factory's class.
- The request destructor and the constructors and destructors of the
  request's members (location, actor data, centre, avoidance reference) have
  no definition under the names the shared class requires. Until they do, the
  constructor cannot run in a linked program.
- The close-point deleting entry `0x006e3f70` passes the original release's
  size `0xb8` to the sized free, while the factory allocates the shared class
  with the global `operator new`. Allocation domain and size are not
  reconciled.
- The other names for `0x006e2420` listed above.
- Save and load order of the close-point fields is unchanged and untested.

The definition's unit does not compile for the host, and a windows-x64 test
that contains it does not link, so no test executes the constructor. The
evidence for this change is the rebuilt windows-x64 object, the composed
archive and the complete links.

No generated data names the constructor. No archive member is added, removed
or reordered. `build/units.json` is unchanged: no name in it changed.
