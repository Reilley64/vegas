# One provider of the model-loader matrix value constructor

VEGAS-61 asks for one native matrix and name value with genuine construction,
copy and retirement. This change is the bounded first part: the global
`FUN_00aade20::FUN_00aade20()` now has one definition. Everything else on the
ticket is listed under "Not covered".

## The constructor

`FUN_00aade20::FUN_00aade20()` is the function at `0x00aade20`.
`build/units.json` lists it once as a function, 142 bytes, in the unit of
`src/fallout_shared/modelloader.cpp` that holds eight functions. The same
unit's symbol table binds the constructor's exception handler name to
`0x00f1f490`. The class there is a float vector, a column count, a row count
and a name string.

`src/staging/blk_00aa0000_od.cpp` used to define the same name a second time,
inside its own class declaration. That body summed the integers 0 to 67 in a
local array and stored the total in the first word. It had no address tag.
The recipe gives that unit 99 functions; none is at `0x00aade20`. The unit's
symbol table binds the constructor's name to `0x00aade20`, as a name the unit
requires. The body was a placeholder for the callee of `0x00aadde0`, not a
second constructor. It is removed. The unit keeps its declaration.

The recipe records no call edges. That the function at `0x00aadde0` calls
`0x00aade20` is inferred from the unit's symbol row for the constructor's name
and from the body tagged `0x00aadde0`, which default-constructs the value and
passes it to `0x00aadf50`.

## Names the recipe binds to these addresses

| Address | Unit | Row | Name |
| --- | --- | --- | --- |
| `0x00aade20` | `modelloader.cpp` | function, 142 bytes | `FUN_00aade20::FUN_00aade20()` |
| `0x00aade20` | `blk_00aa0000_od.cpp` | symbol | `FUN_00aade20::FUN_00aade20()` |
| `0x00f1f490` | `modelloader.cpp` | symbol | exception handler of that constructor |

There is no other row for either address and no other spelling of the name.
No object emits the handler name: it belongs to the original release's
32-bit exception tables.

## Requirers

Measured from the relocations of all 2,223 objects of the windows-x64 archive.

| Object | State | Where |
| --- | --- | --- |
| `modelloader.cpp` | defines | the constructor |
| `blk_00aa0000_od.cpp` | requires, one relocation | `FUN_00aadde0_cls::FUN_00aadde0` (`0x00aadde0`) |
| `blk_00aa0000_od.cpp` | requires, one relocation | `AAOwner::FUN_00aaac10` (`0x00aaac10`), which has `0x00aadde0` inlined |

No other object names the constructor. No object requires `0x00aadde0` by
name. `tile.cpp` requires `AAOwner::FUN_00aaac10`. No generated data names
any of the three functions.

## Behaviour of the two paths

**`0x00aadde0` out of line.** Its instructions are the same before and after:
it calls the constructor by name, copies the value, calls `0x00aadf50` and
calls the destructor. Before, the name had two definitions and a link picked
one: with unreferenced sections kept, the forced link of the whole archive
bound it to the placeholder and the forced link of the worker-pool test bound
it to the model-loader definition. Now both bind the model-loader definition.

**`0x00aadde0` inlined in `0x00aaac10`.** Before, the compiler had inlined the
placeholder too: the function stored the total in the first word of the
temporary and called nothing. Now it calls the constructor. The function
shrinks from 1,976 to 1,159 bytes.

**What the constructor does in the windows-x64 object.** This is unchanged by
this commit; the model-loader object's code is identical before and after.
The constructor calls the float vector's constructor, stores eight zero bytes
at `+0x28` (the two counts), and then runs the inlined `VecStandIn::FUN_0044a0a0`
(`0x0044a0a0`): a call to `CallWithSelf` (`0x0065f550`) with a null second
argument and a call to `FUN_0065e000` with a null receiver, followed by a trap
instruction. The compiler ends the function there because the source passes
null result storage to `0x0044a170` and then reads through it. The name string
is never constructed in the emitted code. This is the "default clear passes
null result storage" contract the ticket lists as unresolved.

The constructor's first call targets the float vector's constructor,
`std::vector<float>::vector()`, which no archive member defines. Its unwind
funclet requires `std::vector<float>::~vector()`, which one member defines,
`bsfacegenmanager.cpp.obj`.

The default clear reads a 32-bit word at `+0xc` of the value and passes it to
`FUN_0065e000`. Laid out at 32-bit widths, `+0xc` is the float vector's first
pointer. On windows-x64 that pointer is 8 bytes at `+0x10`, and `+0xc` is the
vector's second allocator word.

So a caller that reached the constructor today would stop at that trap, where
a caller that reached the placeholder got one meaningless word and continued
with an otherwise unwritten value. Neither is the original's behaviour.

No program reaches either path today:

- The game executable links with lazy extraction. Its map has no row from
  `modelloader.cpp`, `blk_00aa0000_od.cpp` or `tile.cpp`, before or after, and
  the two maps are identical.
- 54 of the 55 test executables link ordinarily. None contains any of the
  three objects. The one that does not link is the worker-pool test.
- In both forced links, with the linker's default section collection, the
  constructor, `0x00aadde0` and `0x00aaac10` are discarded as unreachable from
  the entry point, before and after.
- `blk_00aa0000_od.cpp` requires 316 names that no object defines, and
  `modelloader.cpp` 618, so a program that contains either does not link
  without forcing. They include the value's destructor
  `FUN_00aade20::~FUN_00aade20()`, the copy constructor and destructor of
  `FUN_006593e0`, and the float vector's constructor.

## Storage the caller gives the constructor

Measured on windows-x64: the constructor from the rebuilt object, each size
from the unit's own declaration compiled with that unit's command.

| Item | Unit | Bytes |
| --- | --- | --- |
| The class the constructor is declared on | `modelloader.cpp` | `0x50` |
| float vector base | `modelloader.cpp` | `0x28`, at `+0x00` |
| column and row counts | `modelloader.cpp` | 4 each, at `+0x28` and `+0x2c` |
| name string | `modelloader.cpp` | `0x20`, at `+0x30` |
| Highest store the emitted constructor makes itself | `modelloader.cpp` | 8 bytes at `+0x28`, so `0x30` |
| Temporary in `0x00aadde0` and in `0x00aaac10` | `blk_00aa0000_od.cpp` | `0x3c` |
| Value type `0x00aadf50` takes, `FUN_006593e0` | `blk_00aa0000_od.cpp` | `0x3c` |

The emitted constructor's own stores fit the temporary. The class does not:
it is 20 bytes larger than the storage both sites give it, so a constructor
that built the name string would write past the temporary. In `0x00aadde0`
the temporary ends where the function's exception state slot begins. The
float vector's constructor has no definition, so its writes are not measured.

The staging unit declares the value as fifteen 32-bit words, the size its own
comment gives for the original release's object. The model-loader class holds
four native pointers in the float vector and a pointer in the string's storage
union. On windows-x64 the four pointers add 16 bytes, and the union's pointer
adds 4 bytes of alignment padding in front of the string's storage. The class
is `0x3c` bytes when clang lays the same declarations out at 32-bit widths and
`0x50` on windows-x64. Layout arithmetic, not a recorded fact: at 32-bit
widths the two declarations are the same `0x3c`-byte object. This change does
not endorse either declaration.

## One body per name

Every COMDAT section of the 2,223 archive members was read, with content
taken as the section bytes plus each relocation's offset, type and target.

| Name | Before | After |
| --- | --- | --- |
| `FUN_00aade20::FUN_00aade20()` | `modelloader.cpp` 112 bytes, no-duplicates; `blk_00aa0000_od.cpp` 376 bytes, pick-any | `modelloader.cpp` 112 bytes, same content |
| `FUN_00aadde0_cls::FUN_00aadde0` | one, 135 bytes | one, same content |
| `AAOwner::FUN_00aaac10` | one, 1,976 bytes | one, 1,159 bytes |

No name this change touches has two definitions. The number of names in the
archive whose pick-any definitions differ in content is 489 before and after,
with the same names.

## Not covered

These were open before this change and remain open.

- One native value declaration. The staging unit's fifteen words, its
  `FUN_006593e0`, its loaded element `AAItem` and the model-loader class are
  four declarations of one value. Their sizes and members are not reconciled.
- The constructor's body. On windows-x64 it traps after the default clear,
  as described above, and never constructs the name string. The default clear
  `0x0044a0a0` and its null result storage are not repaired here.
- The order of that repair. The model-loader class extends 20 bytes past each
  of the two `0x3c`-byte staging temporaries. In `0x00aadde0` the first 8 of
  those bytes are the function's exception state slot and the other 12 are
  saved registers. In `0x00aaac10` they are the first 20 bytes of the copy
  temporary beside it. The name string's length and capacity are 4 bytes each
  at `+0x48` and `+0x4c`, inside that excess. If the null result storage of
  `VecStandIn::FUN_0044a0a0` were repaired before the `0x3c` and `0x50`
  storage is reconciled, the constructor would run to its end and construct
  the name string there. The storage has to be reconciled first or in the
  same change. `Vector64D::FUN_0064db70` (`0x0064db70`) in
  `src/staging/blk_00640000_od.cpp` is the in-tree model for the repair: it
  makes the same two supplier calls, to `0x0044a170` and `CallWithSelf`, and
  passes a local pair to each as result storage where `FUN_0044a0a0` passes
  null.
- The float vector's constructor, the value's destructor, and the copy
  constructor and destructor of `FUN_006593e0` have no definition. Until they
  do, neither path can run in a linked program.
- The resize `0x00aadf50`, its iterator supplier and the loader
  `0x00aaac10`: argument and return widths, partial-read cleanup and retry
  are unchanged and untested.
- Copy, move and assignment of the value, and the cleanup of partly built
  elements on failure.

Neither unit compiles for the host, and a windows-x64 test that contains them
does not link, so no test executes the constructor. The evidence for this
change is the rebuilt windows-x64 objects, the composed archive and the
complete links.

No archive member is added, removed or reordered. `build/units.json` is
unchanged: no name in it changed.
