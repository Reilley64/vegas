# Native fixed-string lifecycle

`NiGlobalStringTable` and `NiFixedString` now have one native C++20 ownership
contract. The table is a fixed 513-bucket intrusive intern table protected by its
own mutex; it is not a host `unordered_map` or a facade over a legacy byte
layout. A node owns its full-width links, owning-table identity, reference count,
length and terminated text. Handles point at the node's text and remain stable
until the last release.

`FUN_00a5b630` publishes the table and the process-stable empty sentinel through
the existing globals. `ShutdownGlobalStringTable` refuses shutdown while any
node is retained. The table itself has process lifetime and no static destructor;
ordered shutdown is explicit. Null `NiFixedString` construction uses the
sentinel. `AddString(nullptr)` retains its source return contract and returns
null, while an actual empty string is interned as a normal, distinct node.

New nodes and fixed-string arrays allocate and release through the production
`FUN_00401000` / `FUN_00401030` MemoryManager boundary. Allocation runs under
the real per-thread context 8 guard. Lookup, allocation and publication stay
under the table lock. Allocation failure publishes no node and restores both
the lock and TLS context. Assignment and copy retain before retiring the old
handle. Stale handles are rejected by identity lookup without dereferencing
freed storage.

## Production joins

`niglobalstringtable.cpp` embeds the owner implementation in its existing
archive member, so the accepted 2,218-member sequence does not gain or reorder a
logical member. `NiObjectNET::SetName` uses the typed retain-before-retire name
operation. `CreateRenderPassesNode` constructs a canonical handle and calls that
typed name entry instead of releasing a string header as `MyRef`.

The GPU cache uses canonical names and a MemoryManager-owned fixed-string array.
Its name, profile, suffix and fallback list are staged before publication. A
failed intern or array growth leaves the previous cache state and references
unchanged. Retirement destroys array elements before releasing their storage.

The two destructor providers in `bsshaderaccumulator.cpp` and
`nid3dgpuprogramcache.cpp`, plus dormant inline global constructor/destructor
bodies, are retired. Source-local namespaced fixed-string classes remain
separate types. The following 41 archive objects that required the global
`NiFixedString` destructor now include the complete owner instead of relying on
incompatible global pointer, integer or four-byte shells:

- `src/bsshader/bsshadermanager.cpp`
- `src/fallout/ai/actor.cpp`
- `src/fallout/ai/middlehighprocess.cpp`
- `src/fallout/interface/interfacemanager.cpp`
- `src/fallout/interface/menus/caravanmenu.cpp`
- `src/fallout/interface/menus/hudmainmenu.cpp`
- `src/fallout/interface/menus/loadingmenu.cpp`
- `src/fallout/interface/menus/lockpickmenu.cpp`
- `src/fallout/interface/menus/lovetestermenu.cpp`
- `src/fallout/interface/menus/roulettemenu.cpp`
- `src/fallout/interface/menus/slotmachinemenu.cpp`
- `src/fallout/interface/menus/specialbookmenu.cpp`
- `src/fallout/interface/menus/surgerymenu.cpp`
- `src/fallout/magic/magicballprojectile.cpp`
- `src/fallout/magic/magicboltprojectile.cpp`
- `src/fallout/magic/magicprojectile.cpp`
- `src/fallout/misc/main.cpp`
- `src/fallout_shared/bgsautowater.cpp`
- `src/fallout_shared/distant terrain system/bgsterrainchunk.cpp`
- `src/fallout_shared/facegen/bsfacegenmanager.cpp`
- `src/fallout_shared/modelloader.cpp`
- `src/fallout_shared/region system/tesregiondatalandscape.cpp`
- `src/fallout_shared/screencustomsplatter.cpp`
- `src/fallout_shared/screensplatter.cpp`
- `src/fallout_shared/speedtree/bstreemanager.cpp`
- `src/fallout_shared/tempeffects/bstempeffectparticle.cpp`
- `src/fallout_shared/tesland.cpp`
- `src/fallout_shared/tesnpc.cpp`
- `src/fallout_shared/tesobjectcell.cpp`
- `src/fallout_shared/tesobjectrefr.cpp`
- `src/fallout_shared/tesrace.cpp`
- `src/fallout_shared/tesscriptfunctions.cpp`
- `src/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp`
- `src/gamebryo2.2/corelibs/niconsolerenderer/nid3dgpuprogramcache.cpp`
- `src/staging/blk_00420000_od.cpp`
- `src/staging/blk_004a0000_od.cpp`
- `src/staging/blk_007c0000_od.cpp`
- `src/staging/blk_00800000_od.cpp`
- `src/staging/blk_00880000_od.cpp`
- `src/staging/blk_00a00000_od.cpp`
- `src/unmapped/debugtextmanager.cpp`

Generated data remains unchanged. On Windows it continues to provide the two
published pointer globals; native startup assigns their values. Non-Windows
production tests use the same owner source's definitions rather than test
providers.

## Test boundary

`runtime.native_fixed_string` executes the actual table, fixed-string, name
assignment, GPU-name update, MemoryManager, fixed pools and TLS owners. Checks
remain active under `NDEBUG`. It covers sentinel and interned empty strings,
distinct and duplicate strings, table/node/handle identity, high pointers,
copy/move/retain/release, concurrent interning, heap-initialized/pool-unavailable
allocation and update rollback, TLS restoration, stale-handle rejection, normal
retirement, exception unwinding, live-handle shutdown refusal and ordered final
shutdown. The same test runs under ASan, UBSan and vptr instrumentation.

This bounded join does not claim complete engine startup, every historical
manual header-refcount receiver, Windows execution, executable closure, boot,
play or save compatibility.
