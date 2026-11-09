# Native three-pointer list-node lifecycle

VEGAS-57 replaces the common x86-shaped list-node refill and recycling state
with storage owned by the canonical `MemoryManager`. The production node is
three native pointers: next, previous, and payload. Pointer fields are never
stored in the old one-pointer/two-int record, and payload reference counts stay
32-bit native object counts rather than being inferred from bytes beside a
pointer.

## Owner and allocation domain

`MemoryManager` owns every node block, its allocation bitmap, free chain,
statistics, and synchronization. A refill normally creates 2,048 nodes, matching
the source refill count. Checked size arithmetic rejects zero, overflowing, and
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

## Retained payload lists

`include/fnv/list_node.h` is the typed production boundary. Retained nodes use
`NiRefObject*` as the third pointer. Push obtains storage and successfully
increments the native reference count before publishing links or count. Pop and
member removal establish the returned reference before unlinking and retiring
the node's reference. An overflow leaves links, count, payload, and pool
membership unchanged. Empty head and tail removal returns an empty retained
result.

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

The generated data files remain unchanged. No source was added to the game
archive, so the accepted 2,218 logical-member sequence and order are unchanged;
`canonical_memory_manager.cpp` is the existing owner member. The expected
duplicate-symbol reduction remains zero because this work does not consolidate
the separate owning-return definitions. Only a complete link comparison may
state the measured result.

## Verification boundary

`runtime.list_node_recycling` uses the canonical manager, engine heaps, real TLS
block, typed production nodes, and genuine C++ virtual payload objects. Checks
remain active under `NDEBUG` and cover:

- empty, one, many, head, tail, and middle removal;
- node reuse, aliased payloads, and full-width pointers;
- retain-before-retire and payload destruction;
- reference-count overflow and checked refill failure with unchanged structure;
- context 9 and 23 allocation domains and TLS preservation;
- concurrent acquire/recycle from independent TLS contexts;
- exception-unwind cleanup; and
- refusal with outstanding nodes followed by successful shutdown retirement.

Optimized and ASan/UBSan/vptr runs execute the same owner and list operations.
The Windows target additionally links this test to the complete `game` archive.
These checks do not claim full startup, physical/range/recovery completion,
whole-engine shutdown, gameplay, saves, Steam, or VEGAS-1 acceptance.
