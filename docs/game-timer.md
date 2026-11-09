# Native shared game timer (VEGAS-70)

## Scope and provenance

Base: accepted draft commit `e563a7f2c89d64a1865149958628f337b3ec403b`.
Upstream #33 head `1eafc1c27372773228fed90d45ef550dab1b4921`
provides identity/ownership evidence for `g_timeGlobal` at historical
`0x011f6394`: recipe-menu ownership, shared with spectator consumers.
It is not authority for native offsets, pointer widths or startup defaults.
No upstream permission to copy/adapt source was established, and no upstream
source or tools were copied/adapted. This implementation uses the accepted
local source contracts and independently authored native connections. No
original executable, extracted data or hybrid executable builder was used.

The recipe-menu module retains the sole public definition, factored into
`recipemenu_timer.cpp` so that tests link the real owner without replacement
UI, magic or save-buffer suppliers. The former empty recipe/spectator
objects are gone. The shared complete record contains only native scalar
state, not a Tile, a load-buffer Header or a pointer-bearing receiver view.

## Approved startup and existing behavior

The user explicitly approved this **native reconstruction decision**, not a
claim about recovered original startup:

1. Constant-initialize the complete global record, including unscaled delta.
2. Establish the startup tick once before the first timer API consumer.
3. Preserve the evidenced partial `Init(tick)` behavior on explicit
   reinitialization: it leaves the fourth float unchanged.

`Start(tick)` uses the same function-local initialization guard as lazy API
startup. Concurrent first use is guarded; later startup calls never reset a
running timer. This does not add synchronization to ordinary frame mutations.
The executable entry explicitly starts the clock; legacy frame/recipe/
spectator consumers are also safe if they precede that entry's use of the API.

The production-used explicit-tick update/pause/resume overloads are the
clock-injection seam for deterministic tests. Normal entry points supply
`GetTickCount`/`Sleep` on Windows and a monotonic clock/sleep on other hosts.

Preserved behavior includes unsigned tick arithmetic; fixed-interval
fractional accumulation; variable-step zero detection, 10-ms minimum sleep
and 166-ms delta maximum; unclamped elapsed timestamps; nested pause depth
and the original timestamp-complement protocol; scaled/unscaled deltas;
multiplier target/immediate/rescale behavior. A paused update clears scaled
delta but preserves the last unscaled delta. `UnmodifiedSeconds()` retains
scaled-delta/current-multiplier division; it is not replaced by the fourth
float. The zero interval sentinel is supported by its accepted, static
zero-initialized scalar supplier, not a newly guessed constant.

## Consumer boundary

All live ordinary-source accesses to the shared clock and its actor aliases
use the typed timer API. Timer reads no longer call the generic tick accessor
whose unrelated consumers include pointer-valued receivers. Timer seconds
no longer read a Tile-derived object. The frame policy byte is a named timer
flag, not a load-buffer Header write. The dialog's timer bracket uses timer
pause/resume, not unresolved lock methods on timer storage.

The two legacy tick/float accessor definitions and their non-timer clients
are not globally retyped, renamed or coalesced. Generated dispatch data and
alias directives remain immutable. This change does not assert correctness
of those unrelated receiver protocols.

Recipe brightness arithmetic is in production-used `RecipePulse::Advance`.
Tile callbacks still occur before clock sampling. Unsigned subtraction,
float arithmetic, max-first clamp and the two ordered direction checks are
preserved. Spectator save/load uses the shared elapsed-time subtraction
operations with unsigned four-byte values; transport width/order is unchanged.

The four direct `DAT_011f63a0` reads now use shared seconds. Historical scalar
storage and generated aliases remain in the archive, pending a separate
liveness/composition retirement review; no replacement scalar is introduced.

## Validation and limits

Focused tests link the actual timer and recipe-module owner. Checks remain
active under `NDEBUG`. Optimized and ASan/UBSan/vptr executions pass for
explicit concurrent startup and lazy concurrent startup, initialized fields,
partial reinitialization, update thresholds, wraparound, nested pause/resume,
interval fractions, scale changes, recipe pulse bounds/direction, and the
production-used spectator elapsed-time operations with a synthetic four-byte
payload. These are not claims of complete UI execution, complete spectator
object construction or full save-format interoperability.

Complete Windows-x64 recipe validation: 88 game TUs (87 existing members plus
the companion), including the actor header unit, the actual executable entry,
and three focused-test TUs
compile. Actual compiler flags, includes, optimization and EH policy are
retained; no error-limit weakening or pointer-cast suppression is added.
Every attempt, argv/cwd, tool/source/object identity, changed-object symbol/
relocation/section/unwind inventory and conservative project-input hash
inventory is retained with the external validation evidence.

The complete archive contains **2209** members: all original **2208** members
with relative order preserved, plus the recipe companion adjacent to its
module. All physical payload hashes are verified. There are 87 fresh existing
game-object replacements and 2121 reused accepted payloads; reuse does not
claim fresh compilation of unrelated source. The executable entry is fresh;
unchanged runtime/new and zlib inputs are retained.

Measured unlimited full-link diagnostics: **29 blocks / 26 distinct symbols
before; 28 blocks / 25 distinct symbols after**. Only the timer-global block
is retired; no new duplicate block appears. Ordinary full link exits 255;
unlimited full link exits 1. No successful executable is claimed. Downstream
executable unresolved categories remain **UNMEASURED** behind the duplicate
gate, not zero. Archive-level comparison adds no unprovided name or import,
and retires no definition still required by the complete archive. All other
native executable/play/save/Steam acceptance remains separate work.

## Integration custody

This is isolated accepted-base work. The draft-branch owner approved timer-only
hunks in overlapping files and retains final integration authority. No parked
or rejected candidate content is imported, and no generated data is changed.
CMake changes are limited to the companion's source registration and the
focused test target. Independent Standards and Spec review and serial owner
integration are required before this is accepted; isolated validation is not
an accepted integration commit.
