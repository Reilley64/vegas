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
the source-distinct boolean and byte error-constructor behavior.
`src/unmapped/throw.cpp` also consumes this declaration directly: its
`FUN_0044a310` constructor, destructor, RTTI and unwind cleanup all name the
same global base rather than a competing translation-unit definition. Its
source-supported pointer member has a distinct `FUN_0044a310Pointer` identity,
preserves native pointer width, and is explicitly non-owning: copies preserve
the observed pointer and destruction performs no release because the source has
no matching release edge. The pointee must outlive all exception copies. The
unrelated legacy `FUN_0044a500_s` body lives with its existing `Unk65` provider
in `raiseexception.cpp`, so linking the complete `throw.cpp` object does not
pull that path's separate unresolved dependencies. The billboard leaf caller
explicitly selects the byte-zero constructor path rather than allowing `false`
to bind to the boolean overload; no captured vptr or raw receiver cast supplies
its lifetime.

The `FUN_0044a500` placeholder previously also named two incompatible global
staging declarations. The 0x0044a450 copy path now names its unresolved member
contract `fnv_0044a450::Value`; the archive has no material copy/destructor
provider for that shell, so none is invented. The constructible 0x00ac87b0
parser string is `fnv_00ac87b0::String`, a distinct wrapper over the canonical
native string owner with ordinary copy/move/destruction. Its local function,
table and error-call signatures all use that identity. `FUN_00ac87b0` passes
its path to `Stream87b0` through `c_str()` and copies the bounded
`ToStagingText` view of the exact `"//"` bytes into the distinct
`fnv_00ac7aa0::Exclusion` owner. `FUN_00ac7aa0` and all four real staging call
edges use that typed contract. The exclusion owns canonical storage with an
exact length and terminator because the source-local `FnvString` material
operation is archive-unprovided; neither `FUN_00ac87b0` nor the sibling
`FUN_00ac8390` casts or constructs an incompatible string layout. No requiring
archive object uses the old same-mangled global copy constructor, so that
ambiguous symbol is retired rather than assigned an arbitrary provider. The
separate `fnv_00b0d810::FUN_0044a500` was already namespaced and remains
unchanged.

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
facade or substitute parser is provided. The staging parser's source-local
`FnvString::FUN_0044a7f0(char const*, unsigned int)` material operation is also
archive-unprovided; the exclusion migration does not invent that supplier.
End-to-end parser execution and its final storage join therefore remain blocked,
and VEGAS-73 must remain open.

## Test boundary

`runtime.native_string` uses the real global MemoryManager and fixed pools. It
covers empty/null, 15/16/large values, self and overlapping assignment/append,
growth/shrink/reuse, copy independence, move, failed growth retention, partial
construction, unwind retirement, high pointers, dynamic formatting, distinct
byte-zero/byte-nonzero/boolean error construction, branch-error throw/catch and
retirement, explicit copy plus canonical-base catch and destruction of the
production `FUN_0044a310` path, construction/copy/move/destruction of the
0x00ac87b0 staging string, small-buffer and heap-backed staging path views,
exact `"//"` exclusion bytes/length/termination, and unsigned formatting above
`INT_MAX` through `UINT_MAX`. The test supplies no allocator, exception
provider or parser facade.
Complete Windows object, archive and link evidence is still required for the
seven callers and formatting consumers. Full parser execution remains blocked
by the missing production supplier above.
