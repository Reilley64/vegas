# Allocation-context guard protocol

`include/AutoMemContext.h` is the complete native guard type.
`src/bscore/memoryusagetracker.cpp` owns its constructor, Enter, Leave,
destructor, and the existing getter/setter entries. They all use
`g_tlsBlock.memoryContext`, whose production per-thread initial value is 59.
No heap or manager is constructed or called by this guard.

## Lifetime contract

- Default construction creates an inactive guard for later explicit entry.
- The four-argument constructor enters immediately. The single-tag constructor
  is the same operation without source-location arguments.
- Enter always saves the calling thread's **current** context and installs the
  requested tag. Enter while active **replaces** the pending restoration point;
  it does not push another level and does not preserve the first snapshot.
  This follows the former production Enter body's unconditional save/set.
  BootInit actually constructs with 10 and immediately enters 10 again: its
  next Leave restores 10, not the context preceding construction.
- Leave restores the saved context once and makes the guard inactive. Further
  Leave calls and destruction of an inactive guard do nothing. A subsequent
  Enter takes a new snapshot and makes that same object active again.
- Destruction of an active guard leaves, including during exception unwinding.
  Entry, Leave, construction, and destruction do not allocate or throw.
- Guards cannot be copied or moved. They remain on their entering thread;
  nested independent guards leave in reverse entry order. This is not an
  out-of-order scope manager or a cross-thread ownership-transfer facility.
- The source provider ignored `overridable`, filename, and line. That behavior
  is retained for both boolean values. No filename is retained, encoded into
  an integer, or required to remain alive after entry.

The active bit distinguishes an explicit Leave from outstanding restoration
ownership. It is native state, not historical padding or an inferred original
object size. Existing tags remain integers, not pointers or wire layouts.

## Production joins

The former constructor/Enter/Leave shell receiver casts are gone from the
actual startup, BootInit, staging, and setting-registry callers. Startup owns
an initially inactive complete guard instead of a one-int object; its former
explicit destructor calls now Leave without ending an automatic object's
lifetime. The staging caller retains its explicit
construct/Leave/Enter/Leave/automatic-destruction sequence.

Declaration-only context aliases, including both distant-object context
families and the two distant-block ScopeLock families, now name the complete
native guard. Local names are aliases, not independent providers, fake
receivers, or layout facades. Original recipe bindings identify additional
misnamed context scopes (including profiling/locking names) at the same
constructor and destructor entries. Their surrounding object/task/lock
ownership is not changed or certified by this join.

The pool-construction context uses the same guard. Live process-scalar
allocation-context accesses and allocation-context casts through legacy TLS
layouts now address the existing typed TLS field. Unrelated TLS fields,
manager initialization/heap implementation, and generated data retirements
are not replaced. Historical generated declarations remain unchanged; they
are not permission to access the allocation context through a scalar.

## Tests and acceptance boundary

`runtime.allocation_context` links the production library on Windows. Host
checks compile the same complete guard provider and production TLS owner,
without another provider or manager. Checks remain active under `NDEBUG`.
The suite covers nested tags 9/23/36, normal and early return, explicit Leave
followed by destruction, repeated Leave, same-object re-entry, initially
inactive storage, BootInit's double entry, replacement with a different tag,
both boolean values, thrown exceptions, partially constructed containing
objects, native storage reuse, and overlapping real threads with independent
TLS initialization/restoration.

Optimized and ASan/UBSan checks exercise the actual canonical implementation.
The vptr sanitizer is enabled too; this guard is deliberately non-polymorphic
and has no vptr to fabricate or validate. Windows complete-TU compilation and
EH/cleanup evidence cover the joined production callers. These tests do not
execute the entire startup or distant-task pipelines.

**Real heap routing remains unaccepted under VEGAS-79.** The actual allocation
consumer reads the TLS context, but the complete initialized native manager,
real heap family, allocation membership/query and matching release path are
not supplied by this protocol increment. A separate test must connect actual
startup to the initialized manager and heaps, allocate under distinct contexts
9 and 23 through the real non-pool route, check owning heaps and matching
release, and exercise context 36's default behavior. A getter assertion is
not that test. No fake heap, hand-populated manager, host allocator fallback,
or unrelated allocator WIP is used here.

This is a bounded guard-construction/use/retirement increment, not completion
of VEGAS-56, VEGAS-79, or the windows-x64 product. Full executable linking,
real allocator/startup execution, gameplay, saves and independent Standards
and Spec acceptance remain separate gates.
