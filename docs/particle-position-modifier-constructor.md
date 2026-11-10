# One provider of the position modifier constructor

VEGAS-82 asks for the genuine particle modifier family: shared declarations,
typed allocation, name handles, clone ownership and retirement. This change is
the bounded first part: the global
`NiPSysPositionModifier::NiPSysPositionModifier()` now has one definition.
Everything else on the ticket is listed under "Not covered".

## The constructor

`NiPSysPositionModifier::NiPSysPositionModifier()` is the function at
`0x00c31720`. `build/units.json` lists it once as a function, 38 bytes, in the
unit `src/gamebryo2.2/corelibs/niparticle/nipsyspositionmodifier.cpp`. That
definition constructs its `NiObject` base, then stores the name handle from
`DAT_0109b220`, the update order 0, a null target and the active flag.

`src/staging/blk_00c40000_od.cpp` used to define the same name a second time
with an empty body. The body had no address tag. The recipe gives that unit
327 functions and none is the constructor; the unit's symbol table binds the
constructor's name to `0x00c31720`, as a name the unit requires. The empty body
was a placeholder for the callee of two functions the unit does own,
`0x00c5fd30` and `0x00c465a0`. It is removed. The unit keeps its declaration,
and its object now requires the one definition.

No second address exists for this name. Sixteen units have a symbol row for
it, and every row binds it to `0x00c31720`:

- `nipsyspositionmodifier.cpp`, the owner
- `nipsysagedeathmodifier.cpp`, `nipsysbombmodifier.cpp`,
  `nipsysboundupdatemodifier.cpp`, `nipsysboxemitter.cpp`,
  `nipsyscollidermanager.cpp`, `nipsyscolormodifier.cpp`,
  `nipsysdragmodifier.cpp`, `nipsysgrowfademodifier.cpp`,
  `nipsysmeshupdatemodifier.cpp`, `nipsysradialfieldmodifier.cpp`,
  `nipsysspawnmodifier.cpp`
- `src/nipsysrotationmodifier.cpp`
- `blk_00c20000_o2.cpp`, `blk_00c40000_od.cpp`, `blk_00c60000_od.cpp` (the
  105-function unit)

No object defines the constructor inline, before or after. After this change
one object defines the name and it is the recipe's owner.

### Other names for `0x00c31720`

| Name | Recipe | Objects |
| --- | --- | --- |
| `fnv_00c28b20::NiPSysPositionModifier::NiPSysPositionModifier()` | symbol row in `blk_00c20000_o2.cpp`, bound to `0x00c31720` | required by `blk_00c20000_o2.cpp`, defined nowhere |
| `fnv_00c2dec0::NiPSysPositionModifier::NiPSysPositionModifier()` | no row; the unit `nipsysboundupdatemodifier.cpp` has a row for the global name instead | required by `nipsysboundupdatemodifier.cpp`, defined nowhere |
| `FUN_00c31720::FUN_00c31720()` | no row; the unit `nipsysgrowfademodifier.cpp` has a row for the global name instead | required by `nipsysgrowfademodifier.cpp`, defined nowhere |

Four units have a row for the global name that their object does not emit:
`nipsysboundupdatemodifier.cpp` and `nipsysgrowfademodifier.cpp`, as the table
shows, and `nipsysdragmodifier.cpp` and `nipsysmeshupdatemodifier.cpp`, whose
objects require no constructor of this class under any name.

None of these names changes here. The three scoped or stand-in names were
undefined before and are undefined now.

The recipe records no call edges. That `0x00c5fd30` and `0x00c465a0` call
`0x00c31720` is inferred from their unit's symbol row for the constructor's
name and from the two bodies, each of which constructs that base first.

## Requirers

Eleven objects require the global name, at 23 call sites. Before this change
`blk_00c40000_od.cpp` satisfied its own four sites with the placeholder, which
the compiler reduced to nothing.

The address is the recipe function that contains the site. "Bytes" is the
storage the site gives the constructor on windows-x64: the size the object
passes to the allocating call before the constructor call, or, where the
constructor runs on the function's own receiver, the size of that receiver's
class as the unit declares it, compiled with the unit's command.

The constructor's highest write is one byte at `+0x28`, so it needs `0x29`
bytes. Its other writes are 8 bytes at `+0x0`, 8 at `+0x10`, 4 at `+0x18` and
8 at `+0x20`, after the base constructor's own.

| Unit | Function | Storage | Bytes | Short by |
| --- | --- | --- | --- | --- |
| `blk_00c20000_o2.cpp` | `0x00c2e4c0` | allocated, `operator new` | `0x38` | fits |
| `blk_00c20000_o2.cpp` | `0x00c2ef20` | allocated, `operator new` | `0x20` | 9 |
| `blk_00c20000_o2.cpp` | `0x00c22a80` | receiver, `FUN_00c22a80_cls` | `0x40` | fits |
| `blk_00c20000_o2.cpp` | `0x00c23b20` | allocated, `FUN_00aa13e0` | `0x34` | fits |
| `blk_00c20000_o2.cpp` | `0x00c2a2b0` | allocated, `FUN_00aa13e0` | `0x2c` | fits |
| `blk_00c40000_od.cpp` | `0x00c5fd30` | receiver, `FUN_00c5fd30` | `0x1` | 40 |
| `blk_00c40000_od.cpp` | `0x00c5fee0` | allocated, `operator new` | `0x30` | fits |
| `blk_00c40000_od.cpp` | `0x00c465a0` | receiver, `FUN_00c465a0` | `0x20` | 9 |
| `blk_00c40000_od.cpp` | `0x00c46740` | allocated, `operator new` | `0x20` | 9 |
| `blk_00c60000_od.cpp` | `0x00c60240` | receiver, `FUN_00c60240` | `0x1` | 40 |
| `blk_00c60000_od.cpp` | `0x00c63330` | receiver, `FUN_00c63330` | `0x1` | 40 |
| `blk_00c60000_od.cpp` | `0x00c637b0` | allocated, `operator new` | `0x50` | fits |
| `nipsysagedeathmodifier.cpp` | `0x00c2f150` | allocated, `operator new` | `0x20` | 9 |
| `nipsysbombmodifier.cpp` | `0x00c2e570` | allocated, `operator new` | `0x40` | fits |
| `nipsysboxemitter.cpp` | `0x00c21f00` | receiver, `NiPSysEmitter` | `0x60` | fits |
| `nipsyscollidermanager.cpp` | `0x00c2d5b0` | allocated, `operator new` | `0x1c` | 13 |
| `nipsyscollidermanager.cpp` | `0x00c2d550` | allocated, `operator new` | `0x1c` | 13 |
| `nipsyscolormodifier.cpp` | `0x00c2d240` | allocated, `Alloc00c2d240` | `0x24` | 5 |
| `nipsysradialfieldmodifier.cpp` | `0x00c31ff0` | receiver, `FUN_00c31ff0` | `0x30` | fits |
| `nipsysradialfieldmodifier.cpp` | `0x00c285d0` | allocated, `FUN_00aa13e0` | `0x34` | fits |
| `nipsysrotationmodifier.cpp` | `0x00c20640` | allocated, `operator new` | `0x38` | fits |
| `nipsysrotationmodifier.cpp` | `0x00c20980` | allocated, `operator new` | `0x40` | fits |
| `nipsysspawnmodifier.cpp` | `0x00c23d10` | allocated, `FUN_00aa13e0` | `0x34` | fits |

Thirteen sites fit and ten are short. The two sites that use a scoped name
allocate `0x18` bytes (`0x00c28b20`, short by 17) and `0x28` bytes
(`0x00c2dec0`, short by 1); they have no constructor to call.

Notes on single rows:

- `0x00c5fee0` and `0x00c46740` are the only constructions of `FUN_00c5fd30`
  and `FUN_00c465a0`; each contains its class's constructor inline. The `0x30`
  bytes of `0x00c5fee0` are the unit's `PositionModifierInstance`, whose first
  member is the one-byte `FUN_00c5fd30`.
- No other object requires the constructors `0x00c60240` and `0x00c63330` by
  name.
  Both write their fields through a second declaration, not through the
  one-byte class.
- "Fits" is a statement about size only. Every unit lays its fields out by its
  own declaration, and most of those declarations keep the original release's
  32-bit offsets. For example `0x00c465a0` stores 4000 at `+0x10` and `1.0f` at
  `+0x1c` after the constructor has stored the name handle at `+0x10` and the
  update order at `+0x18`.

Each unit above declares its own class under the name
`NiPSysPositionModifier`, or includes the one-member declaration in
`include/fnv/decl/NiPSysPositionModifier.h`. Their sizes on windows-x64 range
from 1 byte to 64 bytes; the owner's class is 48.

## What each requirer bound

"Forced" is the link of every archive member and "worker pool" the link of
`tests/runtime_havok_worker_pool_test`. Both need `/force` to finish, at
82eced425 and now. The bindings were read from link maps made with unreferenced
sections kept.

| Requirer | Forced, before | Forced, after | Worker pool, before | Worker pool, after |
| --- | --- | --- | --- | --- |
| 19 sites in the ten other objects | placeholder | owner | placeholder | owner |
| 4 sites in `blk_00c40000_od.cpp` | placeholder, inlined | owner | placeholder, inlined | owner |

- Before, both links reported the constructor as a duplicate and kept the
  placeholder. `blk_00c40000_od.cpp` is member 299 of the archive and the
  owner member 1,560. The owner's definition was in both links and nothing
  reached it.
- After, both links have one definition and every site reaches it.
- The game executable's ordinary link loads 15 archive members. None of them
  is the owner, a requirer or one of the factories' registrars, before or
  after. Nothing in it changes.
- Of the 55 test executables, 54 link without forcing, before and after. None
  of them loads any of these objects. The 55th is the worker pool test; see
  "Links".

## Behaviour of the paths that now reach the constructor

Before, under a forced link, each of the 23 sites ran no base construction:
the callee returned its argument and wrote nothing. Now each site runs the
owner's body, which calls `NiObject::NiObject()`, installs the owner unit's
table for the class and writes the four members.

In `blk_00c40000_od.cpp` the change is visible in the object:

- `FUN_00c5fd30::FUN_00c5fd30()` and `FUN_00c465a0::FUN_00c465a0()` call the
  constructor before their own stores. Before, they contained only those
  stores.
- `CreatePositionModifierInstance` (`0x00c5fee0`) and `FUN_00c46740` call it
  between the allocation and their stores. Each also gains an unwind path that
  frees the allocation, with sizes `0x30` and `0x20`, if the constructor
  throws. Before, the compiler saw an empty callee and emitted none.
- The object requires no other new name. Its definition of the constructor
  becomes a requirement.

The other ten objects are byte-identical in the functions that call the
constructor.

No program reaches any of these sites today, for two separate reasons:

- No program that contains one of the twelve objects links without forcing.
  Each of them requires names that no object defines, from 2 names for
  `nipsysrotationmodifier.cpp` to 321 for `blk_00c40000_od.cpp`.
- The owner's body cannot complete in a linked program yet. Its first
  instruction after the prologue calls `NiObject::NiObject()`, which no object
  defines. The table it installs holds one entry, the deleting destructor,
  which calls `NiPSysPositionModifier::~NiPSysPositionModifier()`, which no
  object defines either.

That is also why calling it would not be safe yet: ten sites give it too
little storage, and the others lay their fields over the ones it writes. This
change does not endorse those declarations, sizes or offsets.

The name handle is copied from `DAT_0109b220` without a retain. By
`docs/native-fixed-string-lifecycle.md` that variable holds the null handle,
which has no node to retain. The constructor does not call
`AssignFixedString`, so the argument-order defect that document records does
not affect it.

## Producers and generated consumers

Nine of the functions above are object loaders, registered with
`NiStream::RegisterObjectLoader`:

- by `niparticlesdm.cpp`: `0x00c28b20`, `0x00c2e4c0`, `0x00c2ef20`,
  `0x00c2d5b0`, `0x00c20640`, `0x00c23b20`, `0x00c2a2b0`
- by `blk_00c20000_od.cpp`: `0x00c46740`, `0x00c5fee0`

Eight are entries of generated tables: `0x00c637b0`, `0x00c2f150`,
`0x00c2e570`, `0x00c2dec0` and `0x00c2d550` in
`src/generated/data/vtables_010c.cpp`, and `0x00c2d240`, `0x00c285d0`,
`0x00c20980` and `0x00c23d10` in `vtables_010b.cpp`. The generated entry for
`0x00c20980` names it with an `int` parameter, the object defines it with a
`CloningProcess&` parameter, and so that entry has no definition. This was so
before this change.

No generated file names the constructor. The recipe binds the class's table
name `??_7NiPSysPositionModifier@@6B@` to `0x010c09cc`. The generated data
defines that address as a 41-entry table under the name `DAT_010c09cc`; the
owner's object instead installs the one-entry table the compiler makes for the
owner unit's declaration. The two are not connected here.

No generated file is edited. No archive member is added, removed or
reordered. `build/units.json` is unchanged: no name in it changed.

## Links

Measured on windows-x64 against a rebuild of 82eced425.

| Link | Before | After |
| --- | --- | --- |
| Forced, no error limit: duplicate reports / symbols | 23 / 16 | 22 / 15 |
| Forced, no error limit: undefined names | 35,672 | 35,672, same list |
| Forced, no error limit: imports | 137 | 137, same list |
| Worker pool test, no error limit: duplicates | 9 | 8 |
| Game executable, ordinary | links | links, same imports |

The only duplicate that leaves is this constructor. None enters. The worker
pool test still fails to link, on the eight others.

## Type records under the same name

`nipsysboxemitter.cpp` and the owner unit both emit the run-time type records
of `NiPSysPositionModifier`, from two different declarations: the emitter
unit's class has a virtual `LoadBinary` and no base, the owner's has a
`NiObject` base. Three of the records differ in content, and a link keeps
whichever it loads first without a report.

| Link | Records kept before | Records kept after |
| --- | --- | --- |
| Forced | owner's | owner's |
| Worker pool | emitter unit's | owner's |

The worker pool row changes because that link loads members on demand, and
the constructor's requirers now pull the owner's member in before the emitter
unit's. Neither choice is right for both units. The archive has the same 488
names with differing select-any content before and after.

The two declarations under one name were there before this change and are
not changed by it. It is not a second constructor: the emitter unit requires the constructor and does not define it.
The recipe binds that requirement to `0x00c31720`, so the two declarations are
two views of one class of the original release, and the repair is the shared
declaration, not a second name.

## Not covered

These were open before this change and remain open.

- One shared declaration of the modifier, its base and its derived classes.
  Ten units declare the class for themselves and three include the
  one-member declaration. Their sizes and members are not reconciled, and the
  type records above differ for that reason.
- The ten allocations and receivers that are smaller than `0x29` bytes,
  and the field offsets of every site.
- `NiObject::NiObject()` and
  `NiPSysPositionModifier::~NiPSysPositionModifier()`, which the owner's
  object requires and no object defines. The owner's object requires five
  other undefined names for its other functions.
- The three other names for `0x00c31720` in the table above, and the four
  recipe rows that no object emits.
- The table at `0x010c09cc`.
- The allocation domain. Of the 18 allocating sites, 13 use the global
  `operator new`, four `FUN_00aa13e0` and one `Alloc00c2d240`; the deleting destructor in the
  owner's table frees `0x30` bytes with the sized global `operator delete`.
- Name-handle retention in the derived classes and clones, typed string-table
  allocation, clone-map keys, stream and list attachment, and retirement on
  the normal, failure and unwind paths.
- The generated entry for `0x00c20980`.

None of the units named here builds for a host test, and no Windows test that
contains them links, so no test executes the constructor. The evidence for
this change is the rebuilt windows-x64 objects, the composed archive and the
complete links.
