# One provider of the shape validation helper

VEGAS-68 asks for the private shape query connection: a real producer of the
argument that `0x00c6eb00` receives, the shape discriminator, the single
type-10 unwrap, and the container and triangle lifetime. This change is the
bounded first part: the global `GetValidatedPointer(void*)` now has one
definition. Everything else on the ticket is listed under "Not covered".

## The function

`GetValidatedPointer(void*)` is the function at `0x00c6ead0`.
`build/units.json` lists it once as a function, 42 bytes, in the unit
`src/staging/blk_00c60000_o2.cpp`. That definition carries the address tag.

It reads only. Given a null pointer it returns null. Otherwise it reads the
shape's type. When the type is 10 it replaces the shape with that shape's
child, once, and reads the child's type. It returns the resulting shape when
its type is `0x17`, `0x1e` or `0x1f`, and null for every other type. It does
not test the child for null. This is the recovered behaviour and it is
unchanged.

## The removed definition

`src/havok/common/base/math/vector/hkvector4.cpp` used to define the same name
a second time. The recipe gives that unit ten functions, `0x00c6e300`,
`0x00c6eb00`, `0x00c6fa20`, `0x00c7f4e0`, `0x00c7f520`, `0x00c7f5b0`,
`0x00c7f640`, `0x00c7f690`, `0x00c7f700` and `0x00c7f750`; none is
`0x00c6ead0`. The unit's symbol table binds the name to `0x00c6ead0`, as a name
the unit requires. The second body had no address tag. It was a placeholder
for the callee of `0x00c6eb00`, not a second function. It is removed. The unit
keeps a declaration, and its one call now reaches the one definition.

The recipe records no call edges. That the function at `0x00c6eb00` calls
`0x00c6ead0` is inferred from the unit's symbol row for the name and from the
body tagged `0x00c6eb00`, which calls the name once.

## Names and requirers

The recipe binds one name to `0x00c6ead0`, in three units. No other name is
bound to that address, in any unit.

| Recipe unit | Row | Windows-x64 object |
| --- | --- | --- |
| `src/staging/blk_00c60000_o2.cpp` | function, 42 bytes, and symbol | defines the name |
| `src/havok/common/base/math/vector/hkvector4.cpp` | symbol | defined it before; requires it now |
| `src/havok/common/base/math/clamped_acos.cpp` | symbol | neither defines nor requires it |

The symbol table of the `clamped_acos.cpp` unit is equal, row for row, to the
table of the staging unit, and its source does not use the name. No object
emits that row.

Across the 2,223 archive members and every test object of the windows-x64
build, two objects named the function before this change, both as
definitions. Now one defines it and one requires it:

| Object | Before | Now |
| --- | --- | --- |
| `blk_00c60000_o2.cpp.obj` | defines; no call of its own | the same |
| `hkvector4.cpp.obj` | defines; one call, in `0x00c6eb00` | requires; the same call |

`0x00c6eb00` is in turn required by one object, `blk_00c60000_od.cpp.obj`,
from the function tagged `0x00c711d0`. No generated data names the function or
its address.

## What the call reads now

The two bodies were the same code on the original release's fixed offsets.
Built for windows-x64 they differed in one instruction: where the child of a
type-10 shape is read.

| Reader | Type | Child of a type-10 shape |
| --- | --- | --- |
| removed body, through the `hkvector4.cpp` node declaration | `+0x18` | `+0x48` |
| kept body, through the staging unit's shape declaration | `+0x18` | `+0x58` |
| native `hkpShape` and `hkpMoppBvTreeShape` in `include/havok` | `+0x18` | `+0x58` |

The last row is the class the tree constructs with type 10, in
`native_mopp_construction.cpp`. Its child pointer is the contained shape of
its single-shape container. In that class `+0x48` is the last four bytes of
the code-info vector and the padding after it, so the removed body would have
taken a float and padding for the child pointer. The kept body reads the
field the native class stores.

The kept body's widest read is eight bytes at `+0x58`, for a type-10 shape.

| Storage | Bytes | Kept body's read |
| --- | --- | --- |
| native `hkpShape`, any type but 10 | `0x20` | 4 bytes at `+0x18`: fits |
| native `hkpMoppBvTreeShape`, type 10 | `0x68` | through `+0x5f`: fits |
| node declaration of `hkvector4.cpp` | `0x60` | through `+0x5f`: fits |

The native class requires a live child at construction, so a type-10 shape
built by the tree has one.

The caller's object changes with the removal. The compiler no longer sees the
callee, so `0x00c6eb00` keeps two more values across the call: it is 13 bytes
longer, with two more register moves and two more vector moves. Its
relocations and its stack frame are the same, its unwind records describe
the same frame, and no exception handling is added.

## Programs

No program that links today contains either object.

- The game executable, which loads archive members on demand, loads neither
  object and does not name the function, before or after.
- Of the 55 test programs, 54 link and none of them contains either object.
  The clamped arc cosine test contains `clamped_acos.cpp.obj`, which does not
  name the function.
- The worker-pool test does not link. Its link reported ten duplicate names
  before and reports nine now.

In the two forced links, of the whole archive and of the worker-pool test,
the call already resolved to the staging definition before this change,
because that member is loaded first. It resolves to the same definition now.
So no image that could be produced before changes which body the call
reaches. What changes is that an unforced link has one candidate instead of
two.

## Not covered

These were open before this change and remain open.

- The producer of the argument. `0x00c711d0` passes its contact to
  `0x00c6eb00` through a cast. The ticket records that nothing in the source
  constructs that contact and that how its pointer fields widen is not
  established. This is the
  ticket's blocker and it is unchanged.
- The node declaration of `hkvector4.cpp`. `0x00c6eb00` also performs the same
  validation inline, earlier in its body, through that declaration. On
  windows-x64 the inline copy still reads the child of a type-10 shape at
  `+0x48`, which the call now reads at `+0x58`. The same declaration supplies
  the triangle's points and radius. Replacing it needs the shape and argument
  contract above.
- The use of the result. `0x00c6eb00` takes the validated shape's container at
  `+0x10` and calls its entry 5. The native `hkpShape` is `0x20` bytes, so a
  container cannot start at `+0x10` of a native shape. The native container
  class declares only its destructor.
- A type-10 shape with a null child. The function reads through the child
  without testing it, as the recovered body is written. No behaviour is
  chosen here for that case.
- Lifetime of the container and of the triangle the entry returns.
- The acceptance tests of the ticket. `blk_00c60000_o2.cpp.obj` requires 187
  names that no archive member defines, and `hkvector4.cpp.obj` requires 8
  such names besides compiler support. A program that requires only this
  function still fails to link on the nine other duplicate names, and when
  forced it leaves 35,426 names undefined. So no test executes the function.
  The evidence for this change is the rebuilt windows-x64 objects, the
  composed archive and the complete links.

No archive member is added, removed or reordered. `build/units.json` is
unchanged: no name in it changed. Among the archive's definitions of the name
there was no select-any pair; there were two ordinary definitions with
different content, and there is now one.
