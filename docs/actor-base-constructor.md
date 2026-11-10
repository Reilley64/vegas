# Actor base constructor binding

VEGAS-63 removes the second definition of `FUN_0087d4a0::FUN_0087d4a0(bool)`.
The one definition left is the function at `0x0087d4a0` in
`src/fallout/ai/actor.cpp`.

This is the binding only. It is not the repair of actor construction; see
"Not covered".

## What the recipe says

`build/units.json` is the address authority.

| Unit | Entry for `FUN_0087d4a0::FUN_0087d4a0(bool)` |
| --- | --- |
| `src/fallout/ai/actor.cpp` | function, `0x0087d4a0`, 314 bytes |
| `src/fallout_shared/tesdatahandler.cpp` | required name, bound to `0x0087d4a0` |
| `src/fallout/ai/character.cpp` | required name, bound to `0x0087d4a0` |
| `src/fallout/ai/creature.cpp` | required name, bound to `0x0087d4a0` |
| `src/staging/blk_008c0000_od.cpp` | required name, bound to `0x0087d4a0` |

The recipe lists the function in one unit and gives the name one address. The
four other units require it. There is one original function, not two that
share a name.

`tesdatahandler.cpp` nevertheless defined the constructor a second time, with
an empty body, no address and an empty class. It was a placeholder for the
callee of `FUN_008d43a0::FUN_008d43a0()` (`0x008d43a0`, 227 bytes, a function
of that unit), not a second owner. It is removed. The unit keeps its
declaration, so `0x008d43a0` now requires the name like the other three
producers. `build/units.json` already records exactly that and is unchanged.

## Producers

Each constructs `FUN_0087d4a0` as its base and passes the flag on.

| Producer | Unit | Flag | Objects that require the producer |
| --- | --- | --- | --- |
| `FUN_008d43a0::FUN_008d43a0()`, `0x008d43a0` | `tesdatahandler.cpp` | `true` | none |
| `FUN_008d1d30::FUN_008d1d30()`, `0x008d1d30` | `blk_008c0000_od.cpp` | `true` | `tesdatahandler.cpp` |
| `FUN_008d1f40_t::FUN_008d1f40_t(bool)`, `0x008d1f40` | `character.cpp` | argument | none |
| `FUN_008d4500::FUN_008d4500(bool)`, `0x008d4500` | `creature.cpp` | argument | `tesobjectrefr.cpp` |

The two requirers in the table allocate with the global `operator new`:
`tesdatahandler.cpp` asks for `0x1e0` bytes for `0x008d1d30`, and
`tesobjectrefr.cpp` asks for `0x208` bytes for `0x008d4500`.

The recipe also binds other names to three of the producer addresses. None of
these names has a definition, so the objects that require them do not reach
the producers above. They are an unbound remainder and are not rebound here.
Each requirer allocates with the global `operator new`; the last column is the
size it asks for.

| Address | Name required | Object | Allocation |
| --- | --- | --- | --- |
| `0x008d43a0` | `CreatureRef::CreatureRef()` | `tesdatahandler.cpp` | `0x1d8` |
| `0x008d43a0` | `fnv_0046ddb0::CreatureRef::CreatureRef()` | `tesdatahandler.cpp` | `0x1c8` |
| `0x008d43a0` | `Creature77::Creature77()` | `tessaveloadgame.cpp` | `0x1c8` |
| `0x008d43a0` | `fnv_005d9810::FUN_008d43a0::FUN_008d43a0()` | `tesscriptfunctions.cpp` | `0x1c0` |
| `0x008d1d30` | `fnv_0046ddb0::NPCRef::NPCRef()` | `tesdatahandler.cpp` | `0x1d0` |
| `0x008d1d30` | `NPC77::NPC77()` | `tessaveloadgame.cpp` | `0x1d0` |
| `0x008d1d30` | `fnv_005d9810::FUN_008d1d30::FUN_008d1d30()` | `tesscriptfunctions.cpp` | `0x1c8` |
| `0x008d1f40` | `Character::Character(bool)` | `mapmenu.cpp` | `0x1d0` |
| `0x008d1f40` | `Character::Character(bool)` | `tesobjectrefr.cpp` | `0x210` |

No generated data names the constructor. No archive member is added, removed
or reordered.

## What changes

Only `tesdatahandler.cpp.obj` changes. Its definition of the constructor
becomes a reference, and `0x008d43a0` changes:

- Before: the compiler inlined the empty placeholder, so `0x008d43a0` ran no
  base constructor at all.
- After: `0x008d43a0` calls `0x0087d4a0` with `true` before it stores its own
  table pointers. `0x0087d4a0` constructs its bases and members and calls
  `ActorInitialization::Actor::FUN_0087d890` (`0x0087d890`, in
  `blk_00860000_od.cpp`) with the flag.

That the creature producer runs the actor base constructor first is the
recovered behaviour of the two addresses, not a native policy. The other three
producers already called it.

The recipe records no call edges. That `0x008d43a0` calls `0x0087d4a0` with
`true` is inferred from three things: the unit's symbol row, which binds the
constructor's name to `0x0087d4a0`; the body tagged `0x008d43a0`, which
constructs its base with `true`; and the sibling producer `0x008d4500`, which
makes that call and stores the same five tables after it.

`0x008d43a0` now constructs through `0x0087d4a0` and `0x0087d890` and has no
cleanup. The empty destructor in its own unit is inlined, so the function has
no unwind entry, and nothing retires what the base constructor built. The
other three producers were already in this construct-without-retire state:
their unwind entries call that same empty destructor.

No program that links today contains either function. The game executable
links without `actor.cpp.obj` and without `tesdatahandler.cpp.obj`. A link that
takes `actor.cpp.obj` still fails or leaves names unresolved, because
`0x0087d4a0` requires twelve functions that have no definition: the
constructors of `BMobile_S`, `BCaster_S`, `FUN_00822a40`, `BAVOwner_S`,
`FUN_0087d860`, `BSSpinLock_S` and `Pt_S`, and the destructors of
`BSSpinLock_S`, `FUN_00937000`, `BMobile_S`, `BCaster_S` and `FUN_00822a40`.
For the same reason no test can construct an actor through these
entries yet, and neither unit builds for a host test. The evidence for this
change is the rebuilt object, the composed archive and the complete links.

## Measured windows-x64 layout

Read from the rebuilt objects. Each range ends one past its last byte.

- `0x0087d4a0` stores its six table pointers at `0x0`, `0x20`, `0x98`, `0xa8`,
  `0xc0` and `0xc8`. With `0x0087d890`, which it calls, the real constructor
  writes up to `0x1c6`: the highest store is two bytes at `0x1c4`.
- `0x008d43a0` and `0x008d4500` store their table pointers at those same six
  offsets. The own writes of `0x008d43a0` reach `0x1e4`, an 8-byte store at
  `0x1dc`. That exceeds every allocation that names it in the table above.
- `0x008d1d30` and `0x008d1f40` store table pointers at `0x0`, `0x18`, `0x88`,
  `0x94`, `0xa4` and `0xa8`. Each store is 8 bytes, so they overlap the slots
  at `0x98` and `0xa8` that `0x0087d4a0` wrote.

## Not covered

These were open before this change and remain open under VEGAS-63.

- The five units each declare `FUN_0087d4a0` differently. `actor.cpp` gives it
  five bases and members; `tesdatahandler.cpp`, `character.cpp` and
  `blk_008c0000_od.cpp` declare it empty; `creature.cpp` gives it one virtual
  function. The producers write their fields at offsets that do not come from
  the `actor.cpp` declaration. One shared complete declaration of the actor
  and its bases does not exist yet. This change endorses none of the present
  ones and does not show that a windows-x64 object built by a producer is laid
  out as `0x0087d4a0` expects.
- `FUN_0087d4a0::~FUN_0087d4a0()` still has only the empty definition in
  `tesdatahandler.cpp`. The recipe gives that name no address. The three other
  producers require it for unwinding. The real actor destructor and the
  retirement of a partly constructed actor are not supplied.
- The base and member constructors and destructors listed above have no
  definition.
- The process, controller and registration lifetime behind `0x0087d890`, both
  flag values, and the derived initialization order are not verified by any
  test.
