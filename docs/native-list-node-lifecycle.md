# Native three-pointer list-node lifecycle

VEGAS-57 replaces the common x86-shaped list-node refill and recycling state
with storage owned by the canonical `MemoryManager`. The production node is
three native pointers: next, previous, and payload. Pointer fields are never
stored in the old one-pointer/two-int record, and payload reference counts stay
32-bit native object counts rather than being inferred from bytes beside a
pointer.

## Owner and allocation domain

`MemoryManager` owns every node block, its allocation bitmap, free chain,
statistics, and synchronization. A refill creates a fixed 2,048 nodes. Checked
size arithmetic rejects zero, overflowing, and
unrepresentable requests before allocation. A failed allocation publishes
neither a block nor a partial free chain.

The block is allocated through the canonical manager while the calling thread's
real `g_tlsBlock.memoryContext` is active. Consequently, initialized context 9
uses the auxiliary domain, context 23 uses its context arena, and other contexts
follow the existing manager mapping and fallback rules. The pool does not
install a TLS value, substitute a host allocator, or expose a provider setter.
Each block retains its original allocation domain until retirement.

The owner's mutex covers refill publication, pop, recycle, membership bits,
counters, and block detachment. Exact slot starts are validated with
`uintptr_t`; foreign, interior, and duplicate recycling terminates instead of
corrupting the free chain. Recycling constructs the free-link lifetime only
after the caller has detached or released the payload.

## Node lifetimes

A pool slot is storage, not an object. `include/fnv/list_node.h` is the only
place that turns one into the other:

- `ConstructNode<NodeType>(arguments...)` acquires a slot and constructs the
  caller's complete node type in it, including a nontrivial element such as the
  property pointer in `font.cpp`. If that constructor throws, the slot returns
  to the pool.
- `DestroyNode(node)` runs the node's destructor and then recycles the slot.
- `AdoptNode<NodeType>(storage, arguments...)` is for a typed caller of the
  type-erased allocator entry `0x0043a010`. That entry constructs a zeroed
  `Node<void>`; the caller begins its own node in the same slot rather than
  converting the pointer.
- `RecycleViewedNode(node)` is for a unit that recycles a node it did not
  begin. The unit only views the slot through its own trivially destructible
  layout, so the slot is reused as storage and no lifetime of the view type is
  claimed.

All of these require the node type to be exactly three native pointers wide, so
a unit with a stale narrower node shape fails to compile instead of sharing a
slot.

A migrated unit that acquires a node constructs or adopts its own node type,
with the exceptions below. A unit calls `DestroyNode` only for a node type that
the same unit begins: the parser list in `tile.cpp`, the lights list in
`bsshaderlightingproperty.cpp`, and the `Node<Payload>` lists. Every other
typed recycle site uses `RecycleViewedNode`, because the node was begun in
another unit under that unit's own layout-identical type. The source's
type-erased pointer deallocators (`0x0045cee0`, `0x00a638c0`, `0x00a82620`,
`0x00b63df0` and the `Deallocate(void*)` members) do not know the node type.
Their typed callers clear the element first, and the deallocator passes the
slot to `RecycleStorage` without reading or writing it through a stand-in type.

Exceptions in migrated units, each left on its accepted form:

- `blk_00c40000_od.cpp`, `FUN_00c5ae70` and `FUN_00c5b140`: the local node
  types are 12 and 16 bytes, so they cannot be adopted. They still convert the
  `0x0043a010` result by cast.
- `nitpointerlistbase.inl`, the `NiPointer<BSMultiBound>` `AddTail`
  (`0x00a5a310`): `BSMultiBound` is incomplete in that unit, so the element's
  constructor cannot be instantiated there. It still converts by cast and
  reads the zeroed element as a null pointer.
- `niconsolefragmentshader.cpp` `0x00e8b5f0`, `niconsolerenderer.cpp`
  `0x00e72e50` and `nidevimageconverter.cpp` `0x00a7b0b0` keep the result as an
  untyped pointer. The first and third still write it at 32-bit offsets.
  `tile.cpp` `0x00a0d280` discards the result.
- Local list types that declare their own typed `FUN_0043a010` member without
  a definition (`bstexturemanager.cpp` `MultiBoundPool`,
  `bsshaderlightingproperty.cpp` `Pool_b71560`, `blk_00b60000_o2.cpp`
  `Alloc051`) are not bound to the entry at all.
- `ReleaseRefCountedNode` (`0x00e6e830`) and `FUN_00e6e8a0` receive an untyped
  node. Besides their source callers they fill generated virtual-table slots
  (4 and 28 slots in `vtables_0109.cpp`, `vtables_010e.cpp` and
  `vtables_010f.cpp`). The node type those receivers pass is not established,
  so that binding is unverified.

Units that this work did not migrate still convert the result of `0x0043a010`
to their own node types by cast. Moving them to `AdoptNode` is separate work.

`FUN_00b584e0` is not a pool client. Its list allocates each node directly from
the memory manager, so it keeps that allocation domain, sized as three native
pointers.

## Retained payload lists

`include/fnv/list_node.h` is the typed production boundary. Retained nodes use
`NiRefObject*` as the third pointer. Push obtains storage and successfully
increments the native reference count before publishing links or count. Pop and
member removal establish the returned reference before unlinking and retiring
the node's reference. An overflow leaves links, count, payload, and pool
membership unchanged. Empty head and tail removal returns an empty retained
result.

`NiRefObject`'s object count, destructor, `DeleteThis` and the list's
retain/release functions are defined together in
`src/gamebryo2.2/corelibs/nimain/nirefobject_lifetime.cpp`. That unit depends on
nothing but the object declaration, so the memory manager does not depend on
`NiRefObject`, and host and Windows tests link the same lifetime bodies and
type identity as the game. The count's only legacy definition was moved to that
unit; `docs/native-data-ownership.md` records the move. Units that use the
retained list functions include `fnv/ni_ref_object.h` rather than declaring
their own class of that name.

The native count remains `unsigned int`. `TryIncRefCount` uses an atomic
compare/exchange and refuses `UINT_MAX` rather than wrapping. List counts remain
32-bit source counts and reject overflow before acquisition. Pointer identities,
including aliases and addresses above 4 GiB, retain native width.

The refill entry, head/tail/member removal families, endpoint recycler, portal
pending lists, and the other callers of the same common pool now use this one
owner. This includes the paths in `shadowscenelight.cpp`,
`blk_00ba0000_o2.cpp`, and `blk_00b40000_o2.cpp`; no caller continues to mutate
the old free-head/lock/count globals directly. `FUN_00a8a200` invokes bounded
node shutdown through the same owner.

## Retirement

List owners clear payloads before recycling nodes. Retained owners release each
payload through its actual virtual `NiRefObject` deletion protocol. Normal,
exception-unwind, and explicit clear paths therefore converge on the same
recycler. Node shutdown refuses while any node remains live. Once clients are
detached, it removes all blocks under the node lock and releases each block
through the canonical manager before pool and heap shutdown.

## Deliberate native policy

The following behaviour is chosen for the native owner. It is not recovered
from the source.

- Shutdown at `0x00a8a200` aborts if any node is still live, and recycling a
  node after shutdown aborts. The source released every block unconditionally.
  Whether ordered whole-engine shutdown can keep this is an open decision for
  VEGAS-79.
- Foreign, interior, duplicate and null recycling aborts.
- Removal calls `std::terminate` if a node is present while the list count is
  zero (`Remove` in `list_node.h`).
- Removing from an empty list returns an empty result.
- A payload reference count at `UINT_MAX` and a list count at `UINT32_MAX`
  throw instead of wrapping.
- `FUN_00b584e0` throws `std::bad_alloc` when the manager returns null.
- A refill is a fixed 2,048 nodes. The source read the count from
  `DAT_01188f7c`.
- The manager's `std::mutex` replaces the recursive spin lock at `0x011c5f80`.

The committed generated data files remain unchanged. The accepted 2,218
logical-member sequence and order are preserved, and
`nirefobject_lifetime.cpp` is appended as member 2,219;
`canonical_memory_manager.cpp` is the existing storage owner member. The
expected duplicate-symbol reduction remains zero because this work does not
consolidate the separate owning-return definitions. Only a complete link
comparison may state the measured result.

## Verification boundary

`runtime.list_node_recycling` uses the canonical manager, engine heaps, real TLS
block, typed production nodes, and payloads derived from the production
`NiRefObject` and deleted through its `DeleteThis`. Checks remain active under
`NDEBUG` and cover:

- empty, one, many, head, tail, and middle removal;
- node reuse, aliased payloads, and full-width pointers;
- retain-before-retire, payload destruction, and the object count;
- a node with a nontrivial element: construction, destruction, reuse of its
  slot by another node type, adoption, and a throwing constructor;
- reference-count overflow on push and removal, and list-count overflow at
  `UINT32_MAX`, each with unchanged links, counts, and pool membership;
- refill failure from checked sizing and from real exhaustion of the selected
  engine heap, with unchanged structure, TLS context, and a released lock;
- context 9 and 23 allocation domains and TLS preservation;
- concurrent acquire/recycle from independent TLS contexts;
- exception-unwind cleanup; and
- refusal with outstanding nodes followed by successful shutdown retirement.

`runtime.list_node_recycling.reject_*` run the same executable once per invalid
recycle (foreign, interior, duplicate, null) and require the production
recycler to abort.

Optimized and ASan/UBSan/vptr runs execute the same owner and list operations.
The Windows target links this test to the complete `game` archive.
These checks do not claim full startup, physical/range/recovery completion,
whole-engine shutdown, gameplay, saves, Steam, or VEGAS-1 acceptance.
