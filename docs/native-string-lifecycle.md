# Canonical native parser/error string

`FUN_0044a4c0` is one native C++20 owner declared in
`include/fnv/decl/FUN_0044a4c0.h` and implemented by
`src/speedtree/native_string.cpp`. It keeps 0–15 characters and their terminator
inside the object. Longer values use native pointer and size fields and allocate
through the production `FUN_00401000` / `FUN_00401030` MemoryManager boundary.
It does not wrap a host `std::string`, install an allocator provider or depend on
a historical PC layout.

Assignment and append detect aliases by retaining the old owner until copying is
complete. In-place operations use overlap-safe moves. Growth allocates before
publication and retirement, so allocation failure leaves the old pointer,
length, contents and allocation domain unchanged. Copy owns independent storage;
move transfers heap ownership and leaves a valid empty source. Every live value
is null terminated. Shrinking retains capacity for reuse.

## Production joins

The former constructor definitions in `blk_00440000_od.cpp` and
`blk_00ac0000_od.cpp` are retired. The accepted archive inventory had exactly
seven objects requiring `??0FUN_0044a4c0@@QEAA@PEBD@Z`; each now includes the
complete owner:

- `src/speedtree/treeengine.cpp`
- `src/speedtree/speedtreert.cpp`
- `src/speedtree/lightingengine.cpp`
- `src/speedtree/libspline_source/idvspline.cpp`
- `src/speedtree/frondengine.cpp`
- `src/speedtree/branchinfo.cpp`
- `src/speedtree/billboardleaf.cpp`

Their incompatible global 28-byte views and inline fake-helper destructors are
removed. Distinct namespaced string types remain distinct.

The shared `FUN_00ec78e0` / `FUN_00b096a0` / `FUN_00b09480` error owner now has
one native polymorphic base, two native state integers and the canonical message
member. The seven caller units no longer reserve guessed integer arrays for it.
The canonical module supplies construction and virtual retirement, including
the source-distinct boolean and byte error-constructor behavior. The billboard
leaf caller explicitly selects the byte-zero constructor path rather than
allowing `false` to bind to the boolean overload; no captured vptr or raw
receiver cast supplies its lifetime.

`FUN_00b18860` now formats into an already-live canonical owner. Its external
requiring objects consume `c_str()` without casting the result to unrelated
local or host string layouts. The frond vertex-limit error explicitly copies
that text into its own string owner, and collision indices use unsigned
formatting. The formatter's old empty output type and opaque `StringSlot`
storage are retired.
Formatting larger than the old stack buffer grows the same canonical owner and
retains the destination if allocation fails.

The mapped `tesobject.cpp` `FUN_00ac7f50` parser has a separate local class-key
and storage declaration. Its real line supplier,
`FUN_00ad43a0(ParserStream&, ParserString&)`, is undefined in the complete
production archive. The formerly ambiguous local class is named `ParserString`
and kept separate rather than being nominally rebound without its producer. No
facade or substitute parser is provided, so end-to-end parser execution and its final
storage join remain blocked and VEGAS-73 must remain open.

## Test boundary

`runtime.native_string` uses the real global MemoryManager and fixed pools. It
covers empty/null, 15/16/large values, self and overlapping assignment/append,
growth/shrink/reuse, copy independence, move, failed growth retention, partial
construction, unwind retirement, high pointers, dynamic formatting, distinct
byte-zero/byte-nonzero/boolean error construction, branch-error throw/catch and
retirement, and unsigned formatting above `INT_MAX` through `UINT_MAX`. The test supplies no
allocator and no parser facade.
Complete Windows object, archive and link evidence is still required for the
seven callers and formatting consumers. Full parser execution remains blocked
by the missing production supplier above.
