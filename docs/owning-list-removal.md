# One provider of the owning list removal

VEGAS-66 asks for one typed owning-return protocol for the scene owner's
lists, with real producers, receivers and retirement. This change is the
bounded first part: `List_b9fcc0::FUN_00b9fcc0(const RefPtr_b9fcc0&)` now has
one definition. Everything else on the ticket is listed under "Not covered".

## The function

`List_b9fcc0::FUN_00b9fcc0` is the function at `0x00b9fcc0`. It walks the list
from the head, takes the first node whose payload is the argument's object,
removes that node through `0x00b9efa0` and returns the removed reference. When
no node matches it returns an owning copy of the argument.

`build/units.json` decides the owner:

| Unit | Row | Address | Size |
| --- | --- | --- | --- |
| `src/bsshader/shadowscenelight.cpp` | function `List_b9fcc0::FUN_00b9fcc0` | `0x00b9fcc0` | 219 |
| `src/bsshader/shadowscenelight.cpp` | symbol, its exception handler | `0x00f2a269` | |
| `src/staging/blk_00ba0000_o2.cpp` | symbol `List_b9fcc0::FUN_00b9fcc0` | `0x00b9fcc0` | |
| `src/staging/blk_00b40000_o2.cpp` | symbol `List_b9fcc0::FUN_00b9fcc0` | `0x00b9fcc0` | |

The definition in `shadowscenelight.cpp` carries the address tag. The recipe
gives `blk_00ba0000_o2.cpp` 245 functions and `0x00b9fcc0` is not one of them;
its symbol row names the function as something the unit requires. Its body had
no address tag. Inference: it was a second transcription of the callee of
`0x00ba01a0`. The symbol row indicates it, and so do the bytes: the two bodies
differ only in the two places the next section names. It is removed. The unit
keeps the declaration.

Every unit that uses the global name binds it to `0x00b9fcc0`. No second
address exists for it.

The recipe binds two more names to `0x00b9fcc0`. Both are required by one
object each and defined by none, before and after:

| Unit | Name | Object state |
| --- | --- | --- |
| `src/bsshader/shadowscenenode.cpp` | `fnv_00b5e870::List_b9fcc0::FUN_00b9fcc0(const FirstOwner&)` | required by 00b5e870, undefined |
| `src/fallout_shared/tes.cpp` | `List::FUN_00b9fcc0(const Ref&)` | required by 00b6da10 (five calls), undefined |

The handler row at `0x00f2a269` is a name of the original release's 32-bit
exception tables. No windows-x64 object emits it.

`build/units.json` is unchanged: no name in it changed.

## The two bodies at the tip

At 82eced425 both objects defined the name as an ordinary external function of
129 bytes. Their instructions were the same apart from the operand order of one
compare and the name of the removal they call:

| Definition | Calls for the removal | Defined in |
| --- | --- | --- |
| `shadowscenelight.cpp` (kept) | `List_b9fcc0::FUN_00b9efa0(void*&)` | `blk_00ba0000_o2.cpp` |
| `blk_00ba0000_o2.cpp` (removed) | `fnv_00b9efa0::RemovalList::FUN_00b9efa0(void*&)` | `shadowscenelight.cpp` |

Those two removals are both 272 bytes with identical bytes and relocations.
Each calls `fnv::list::Remove` on the list's three fields. So the kept and the
removed body did the same work through differently named callees.

The names the recipe binds to `0x00b9efa0`, none changed here:

| Unit | Row | Name | Object state |
| --- | --- | --- | --- |
| `shadowscenelight.cpp` | function, 285 bytes | `fnv_00b9efa0::RemovalList::FUN_00b9efa0` | defined there, tagged |
| `shadowscenelight.cpp` | symbol | `List_b9fcc0::FUN_00b9efa0` | required by 00b9fcc0; defined in `blk_00ba0000_o2.cpp`, no function row, no tag |
| `blk_00ba0000_o2.cpp` | symbol | `fnv_00b9efa0::RemovalList::FUN_00b9efa0` | required by 00ba01a0 and 00ba02b0 |
| `shadowscenenode.cpp` | symbol | `fnv_00b5e870::List_b9fcc0::FUN_00b9efa0` | defined there, 192 bytes, no function row |
| `shadowscenenode.cpp` | symbol | `fnv_00b5d040::List_b9fcc0::Remove(void*)` | required, undefined |
| `bstexturemanager.cpp` | symbol | `MultiBoundList::RemovePos(void*&)` | required, undefined |

## Requirers

Three objects name the global `List_b9fcc0::FUN_00b9fcc0`. The table gives the
object whose definition each link kept. "Forced" is the link of every archive
member. "Worker pool" is the link of `tests/runtime_havok_worker_pool_test`.
Both need `/force` to finish, at the tip and now.

| Requirer | Calls | Forced, before | Forced, after | Worker pool, before | Worker pool, after |
| --- | --- | --- | --- | --- | --- |
| `blk_00ba0000_o2.cpp`, `BA01A0Owner::FUN_00ba01a0` (00ba01a0), no-key path | 1 | staging body | kept body | staging body | kept body |
| `blk_00b40000_o2.cpp`, `TextureOwner::FUN_00b5ef90` (00b5ef90), both lists | 2 | staging body | kept body | staging body | kept body |
| `shadowscenelight.cpp` | the definition; no call of its own | | | | |

Both links loaded `blk_00ba0000_o2.cpp` first, so the kept body was bound by
nothing at the tip. The call in 00ba01a0 was a relocation against the external
name in both trees; it changed from defined in its own object to required.

Callers of the two requiring functions, unchanged:

- 00ba01a0: `shadowscenenode.cpp` (00b5b0e0 and `ProcessNodeChildren`),
  `bsshaderlightingproperty.cpp` (`RemoveItemsAfterPos`), and 00ba02b0 in its
  own unit by receiver cast. 00ba02b0 is called from `shadowscenenode.cpp`
  (00b5d300) and `src/fallout/misc/main.cpp` (00871290).
- 00b5ef90: `interfacemanager.cpp` (00b5fd60, two calls by receiver cast).

No file under `src/generated/` names 00b9fcc0, 00b9efa0, 00ba01a0, 00ba02b0 or
00b5ef90, and no generated object requires any of them. No virtual-table slot
dispatches to them.

## Behaviour of the paths that now reach the kept body

For both requirers the instructions executed are the same as before, with the
removal entered under the other of its two names.

- Match found: the node is removed by `fnv::list::Remove`, which establishes
  the returned reference before it unlinks and recycles the node. Before, this
  ran in the `shadowscenelight.cpp` copy of the removal; now it runs in the
  `blk_00ba0000_o2.cpp` copy. The copies are byte-identical.
- No match: the argument's object is retained through
  `fnv::list::TryRetainPayload` and returned. An overflowing count throws
  through `fnv::list::ThrowPayloadCountOverflow`. Unchanged.
- The result is returned through the hidden result pointer in both bodies.
  Neither body has an unwind funclet.

What the kept body and its removal read and write, against what each requirer
declares. Measured on windows-x64 with each unit's own compile command:

| | Kept body's unit | `blk_00ba0000_o2.cpp` | `blk_00b40000_o2.cpp` |
| --- | --- | --- | --- |
| List size | 24 | 24 | 24 |
| Head, tail, count offsets | 0, 8, 16 | 0, 8, 16 | 0, 8, 16 |
| Count width | 4 | 4 | 4 |
| Node size | 24 | 24 | 24 |
| Node next, payload offsets | 0, 16 | 0, 16 | 0, 16 |
| Reference size | 8 | 8 | 8 |
| Payload count offset, width | 8, 4 | 8, 4 | 8, 4 |

The kept body reads the head at `+0` of the list, `next` at `+0` and the
payload at `+16` of each node, and writes 8 bytes at `+0` of the result. The
removal writes the list's head, tail and 32-bit count; its highest write to
the list is 4 bytes at `+16`, inside the 24 bytes all three units declare. In
the nodes it writes the neighbours' links at `+0` and `+8` and clears the
removed node's payload at `+16`, inside the 24-byte node.

The numbers agree, but the types do not. `blk_00b40000_o2.cpp` declares its
payload as `TextureDesc`, a class of its own with two virtual functions and a
`long` count, and its node as `TextureNode`. The kept body retains that
payload as `NiRefObject`. This was the same before, because the removed body
also retained through `NiRefObject`.

## Programs that contain these objects

- The game executable's ordinary link loads none of `shadowscenelight.cpp`,
  `blk_00ba0000_o2.cpp`, `blk_00b40000_o2.cpp`, `shadowscenenode.cpp`,
  `bsshaderlightingproperty.cpp`, `interfacemanager.cpp`,
  `src/fallout/misc/main.cpp`, `tes.cpp` or `bstexturemanager.cpp`, before or
  after.
- 54 of the 55 test executables link without forcing, before and after. None
  of them contains any of those objects.
- The 55th, `tests/runtime_havok_worker_pool_test`, contains all nine and does
  not link, before or after.

No program that loads these objects links without `/force`, so there is no
working behaviour to keep or to lose.

## Measured links

Windows-x64, the archive's 2,223 members in the same order before and after.

| Link | Before | After |
| --- | --- | --- |
| Forced, no error limit: duplicate blocks / symbols | 23 / 16 | 22 / 15 |
| Forced, no error limit: undefined names | 35,672 | 35,672, same list |
| Forced, no error limit: imports | 137 | 137, same list |
| Worker pool test, no error limit: duplicates | 9 | 8 |
| Worker pool test, forced: undefined names | 35,350 | 35,350, same list |
| Ordinary game link | links | links |

One row of the archive's symbol table changes: `blk_00ba0000_o2.cpp` now
requires the name instead of defining it. No name with several inline
definitions is involved; `RefPtr_b9fcc0`'s destructor is emitted out of line
by `blk_00ba0000_o2.cpp` only.

## Not covered

These were open before this change and remain open.

- VEGAS-59, the scene owner as one initialized production owner: its
  allocation, constructor, destructor and publication. Until it exists no
  constructed list reaches 00b9fcc0, so the first-match, absent, head, tail,
  middle, duplicate, null and alias cases the ticket names are not tested
  through a production entry.
- One shared declaration of the list, the node and the reference.
  `shadowscenelight.cpp`, `blk_00ba0000_o2.cpp`, `blk_00b40000_o2.cpp` and
  `shadowscenenode.cpp` each declare their own `List_b9fcc0` and
  `RefPtr_b9fcc0` under the global names. `TextureDesc` and `BA01A0Item` are
  not connected to the real payload classes.
- The second copy of the removal. The recipe owner of `0x00b9fcc0`, in
  `shadowscenelight.cpp`, calls `List_b9fcc0::FUN_00b9efa0`. The only
  definition of that name is the staging copy in `blk_00ba0000_o2.cpp`. That
  copy has no address tag, and its unit has no function row and no symbol row
  for the name. The owner does not call the recipe function of its own unit,
  `fnv_00b9efa0::RemovalList::FUN_00b9efa0` (`0x00b9efa0`, 285 bytes in the
  recipe). The two removals are instruction-identical: each is a 272-byte
  section with the same bytes and the same relocations.
- So this change swaps which half of the pair is staging code. Before it, the
  two requirers bound the staging body of `0x00b9fcc0`, which called the
  recipe-bound removal. Now they bind the recipe-bound `0x00b9fcc0`, which
  calls the staging removal. The kept 00b9fcc0 is the staging removal's only
  requirer. The staging removal goes when 00b9fcc0 calls 00b9efa0 under the
  recipe's function name, which needs the shared declaration.
- A third copy of the removal: `fnv_00b5e870::List_b9fcc0::FUN_00b9efa0` in
  `shadowscenenode.cpp`, a 192-byte section on that unit's own types, with
  no function row.
- The other names for `0x00b9fcc0` and `0x00b9efa0` listed above that have no
  definition, and the `PopFront`, `PopBack`, `RemoveHead`, `RemoveTail` and
  `ReleaseRefCountedNode` members these lists declare without one.
- The receiver casts: 00ba02b0 to `BA01A0Owner`, 00ba01a0 to
  `fnv_00b9efa0::RemovalList` and to the watcher set, `interfacemanager.cpp`
  to `TextureOwner` and its `NiPointer<Item>` to `RefPtr_b9fcc0`. The owners'
  field offsets (`kList` at 224 of `BA01A0Owner`, the lists at 184 and 208 of
  `TextureOwner`) come from declarations of 32-bit fields and are not
  endorsed here.
- Watcher removal order, discarded-result order and unwind on these paths are
  as the tip had them. Nothing here tests them.

None of the units named here builds for a host test, and no Windows test that
contains them links yet. The evidence is the rebuilt objects, the composed
archive and the complete links.

No generated data changes. No archive member is added, removed or reordered.
