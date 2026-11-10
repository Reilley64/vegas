# Native fixed-string lifecycle

One native owner, `src/gamebryo2.2/corelibs/nimain/native_fixed_string.cpp`,
supplies the global string table and the owning `NiFixedString` operations. It
is a production archive member appended after the accepted members, and the
focused test builds that same unit.

## Handle and node

A handle is the interned text pointer. The null handle is the null string: it
has no node, `AddString(nullptr)` returns it, and no operation reads through
it. `DAT_0109b220` keeps its zero value and the owner never writes it. An empty
text is an ordinary interned string.

A node keeps a 32-bit reference count eight bytes before the text and a 32-bit
length four bytes before it. This is the header the source allocates in
`0x00a5b690`, and the one older units still update directly with interlocked
operations on `handle - 8`. The owner's count is an atomic 32-bit value at that
address, so both forms act on the same count. The node's link to the next node
in its bucket sits before the count and is private to the owner. The owner
constructs only this 16-byte header; the text is the bytes after it in the same
allocation.

## Table

The table has the source's 513 buckets and the source hash from `0x00a5b270`:
`h * 33 + c` over the text with `c` taken as a signed character, modulo 513.
Lookup, allocation and publication of a node happen under the table lock.
A lookup matches the same pointer, or an equal length and equal text.

A new node is allocated with the thread's allocation context set to 8, as in
the source. The request is the header, the text and its terminator, rounded up
to four bytes as in the source, and the node starts with one reference. The
source header is the count and the length, 8 bytes; the owner's request is 8
bytes larger for its bucket link.

The source allocated nodes with `FUN_00aa1070` and freed them with
`FUN_00aa10f0`, the Ni allocator entries. The owner calls the native memory
manager entries `FUN_00401000` and `FUN_00401030` directly instead. The two Ni
entries in this tree dispatch through the allocator object in `DAT_011f6080`,
which no source in this tree assigns, so they cannot run on the host or in the
owner's test. The native manager is the one that reads the allocation context
the source sets to 8. The alignment and tag arguments of the Ni entries are
not passed on.

## Native policy where the source would fault

These three results are deliberate native policy, not recovered behaviour.
`AddString` returns the null handle, publishes nothing, and leaves the lock
free and the thread's context restored:

- before `FUN_00a5b630` has started the table,
- after a completed shutdown,
- when the allocation fails, or the text is too long for a 32-bit request.

The source uses the table pointer in `DAT_011f42c0` without a check, so before
startup it would fault on a null table. It also writes the count into the new
allocation without a check.

## Retain, release and retirement

Retaining adds one to the count. Releasing subtracts one and never frees.
An unreferenced node stays interned, and a later `AddString` of the same text
revives that node under the lock.

`FUN_00a5b460` is the only place a node is retired. Under the lock it unlinks
and frees every node whose count is zero, as `0x00a5b3c0` did. A count brought
to zero by an older unit's direct update is retired by the same sweep.

`FUN_00a5b630` starts the table. `A5B660StringTable::FUN_00a5b660` calls
`ShutdownTable`, which sweeps and then stops the table only if no node remains.
Live handles refuse the shutdown and stay valid. The refusal is silent:
`ShutdownTable` reports it, but `FUN_00a5b660` returns nothing and discards the
result, so production gets no signal that the table is still running. The table is
constant-initialized and its destructor is never registered, so handles held by
static objects in other units stay valid until the process ends.

## Production joins

| Source entry | Unit | Join |
| --- | --- | --- |
| `0x00a5b690` `NiGlobalStringTable::AddString` | owner | intern |
| `0x00a5b630`, `0x00a5b460` | owner | start, sweep |
| `0x00a5b660` | `blk_00a40000_o2.cpp` | calls `ShutdownTable` |
| `0x00438170`, `0x0048af40`, `0x004381b0`, `0x00a2e750`, `0x0048af70` | owner | `NiFixedString` construct, copy, destroy, assign text, `IsNotEmpty` |
| `0x00a5b950` `AssignFixedString` | `niobjectnet.cpp` | calls `AssignHandle` on the name slot after the `NiObject` base |
| `0x00b63420` `CreateRenderPassesNode` | `bsshaderaccumulator.cpp` | owning local name, `AssignFixedString`, owner destructor |
| `0x00e8e450` cache constructor | `nid3dgpuprogramcache.cpp` | owner construct, assign and destroy for its names and profile list |
| `0x004b9900` | `blk_004a0000_od.cpp` | calls the owner destructor |

The older table bodies in `blk_00a40000_o2.cpp` (`0x00a5b270`, `0x00a5b300`,
`0x00a5b3c0`, `0x00a5b530`, `0x00a5b5a0`) and the two competing destructor
definitions are removed. `0x004f31b0` stays in `niglobalstringtable.cpp`
unchanged: its callers apply it to pixel data, not to the table.

`DAT_011f42c0` is no longer written or read. Its old consumers treated it as
the 32-bit table layout, and all of them now call the owner.

## Two views of `NiFixedString`

`fnv/native_fixed_string.h` declares the owning class. `NiFixedString.h` stays
the plain layout view for units that manage the count by hand; giving those
units an implicit destructor would release twice. A unit includes only one of
the two. `fnv/fixed_string_handle.h` declares the handle operations alone and
can be included from either kind of unit.

Every unit that calls the global `NiFixedString` destructor sees the class as
one pointer at offset zero. Five of them declared a four-byte shell and now
include the owning class: `magicprojectile.cpp`, `bgsterrainchunk.cpp`,
`screensplatter.cpp`, `tesnpc.cpp` and `tesobject.cpp`. The others keep their
own one-pointer declaration and bind to the owner at link time.

## Test boundary

`runtime.native_fixed_string` runs the owner unit with the real MemoryManager,
fixed pools and thread context, with checks active under `NDEBUG`, in optimized
and ASan, UBSan and vptr builds. It covers the hash against the source form,
the null handle, an empty text, duplicate and distinct strings, the header an
older unit reads, texts of zero to three characters before the heaps start and
from the pools, the rounded request size the manager records before the heaps
start, copy and both assignments, the name-slot update, revival of an
unreferenced node, mixed direct and owner count updates, sweep retirement,
allocation failure with the lock and context restored, a text longer than the
largest pool family landing in the main heap while the caller's context is 23,
an oversized text, concurrent interning during sweeps, unwinding, and refused
then completed shutdown.

## Not covered

- The units that call the owner (`niobjectnet.cpp`, `bsshaderaccumulator.cpp`,
  `nid3dgpuprogramcache.cpp`, both staging blocks) build only for Windows and
  are not executed by any test. Their joins are checked by compiling the
  complete units and by the symbols and calls in the built objects.
- Most callers of `AssignFixedString` pass the name in the second argument and
  `{}` in the third. The definition reads the name through the third argument,
  so those calls dereference a null pointer in the definition. Only callers
  that pass the name third, such as `CreateRenderPassesNode`, reach the name
  update. The mismatch is in the accepted tree, is unchanged here, and is
  tracked separately.
- Units that manage the count by hand still do so; they are compatible with
  the owner but not migrated to it.
- Engine startup order, Windows execution, boot, play and save compatibility.
