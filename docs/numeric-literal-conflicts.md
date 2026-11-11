# Numeric literals whose transcriptions disagree

VEGAS-83 lists numeric literals that an outside change wanted to replace.
Most of them are uses of floating constants that `build/units.json` names.
This page records what the recipe and the objects say about those
constants, which sites were changed, on what evidence, and what stays open.

## The ticket's names

The ticket names its sites by descriptions or by names the source does not
use. Each maps to an address of the recipe:

| Ticket name | Function | Address |
| --- | --- | --- |
| `Creature::CalculateRunSpeed` and its `actor.cpp` counterpart | `Creature::CalculateRunSpeed`, `Creature::FUN_008d4f10` | `0x008d4eb0`, `0x008d4f10` |
| `GamePlayFormulas_GetActorWalkSpeed` | `FUN_00647d10`, which multiplies by `fMoveBaseSpeed` | `0x00647d10` |
| camera scale-change comparisons | `FUN_008744a0` | `0x008744a0` |
| caravan idle step thresholds | `CaravanGame::FUN_00741500` | `0x00741500` |
| `StartRenderedMenuShudder` | `FUN_007fb250_owner::FUN_007fb250` | `0x007fb250` |
| geometry-decal opacity falloff | two functions of `bstempeffectgeometrydecal.cpp` | `0x00683c10`, `0x00685ef0` |
| simple-decal cosine clamp | the constructor `FUN_0068ad20::FUN_0068ad20` | `0x0068ad20` |
| pending-sound height | `SoundPlaybackManager::ProcessPendingSounds` | `0x0082d7c0` |
| `Engage::PrintDebugInfo` | `fnv_009d5410::Engage::PrintDebugInfo` | `0x009d5410` |
| `Normal::Density` | `Normal::Density` | `0x00b43ce0` |
| `Random::Raw` | `Random::Raw` | `0x00b43310` |

`gameplayformulas.cpp` has a second function that scales actor value 21,
`FUN_00647fd0` (`0x00647fd0`). It interpolates between `fMoveMinFlySpeed`
and `fMoveMaxFlySpeed`, so it is not the walk speed, and it already used
0.01.

## The recipe names floating constants

A unit's `symbols` map binds names of the form `__real@<bits>` to addresses.
The name is the constant: `<bits>` is the hexadecimal IEEE encoding, 16
digits for a double and 8 for a float. At `81a5145fb` the recipe has 4,634
such bindings of 695 names to 693 addresses.

The original linker keeps one copy of each such constant. So in the
original release one address holds one value: an address has one name, and
a name has one address. Where two units bind different names to one
address, one of the two transcriptions is wrong. The recipe alone shows the
conflict. It does not always show which side is wrong.

At `81a5145fb` four addresses carry two names:

| Address | Names and values | Units | Disposition |
| --- | --- | --- | --- |
| `0x01016978` | `3f50624de0000000`, 0.001f widened to double | 15 | the value at the address |
| | `3f1a36e2e0000000`, 0.0001f widened to double | 2 (`pathsmootherpov.cpp` binds both) | changed to 0.001f, decided by the recipe |
| `0x01031148` | `3f847ae147ae147b`, 0.01 | 4 (`gameplayformulas.cpp` binds both) | the value at the address, accepted |
| | `3ff199999999999a`, 1.1 | 6 | changed to 0.01 |
| `0x010231d8` | `4070000000000000`, 256.0 | 5 (`bstempeffectgeometrydecal.cpp` binds both) | undecidable from the repository |
| | `4069000000000000`, 200.0 | 3 | undecidable from the repository |
| `0x010229b8` | `3e000000001c5f68`, 4.656612875e-10 | 1 | undecidable from the repository |
| | `3e00000000000000`, 2^-31 | 1 | undecidable from the repository |

Two names also have two addresses. `3f1a36e2e0000000` is one of them, and
the first change below removes that. The other is `3f99999a` (1.2f), bound
to `0x01018204` by `highprocess.cpp` and to `0x0118b694` by
`tesobjectcell.cpp`. It is not one of the ticket's sites. It is recorded
here for a follow-up and not examined.

After the two changes below the recipe has 4,632 bindings of 694 names to
693 addresses. Only `0x010231d8` and `0x010229b8` carry two names, and only
the 1.2f name has two addresses.

The x64 objects cannot decide it: the windows-x64 compiler emits its own
constants. They show which value each function loads today, which is
what changes when a source literal changes.

## 0x01016978: 0.001f

Fifteen units bind 0.001f widened to double to the address.
`forenderedmenu.cpp` and `pathsmootherpov.cpp` bind 0.0001f widened to
double to it. The 0.0001f name has its own address, `0x01032980`, which
`hkpsimplexsolver.cpp` and `blk_00d80000_o2.cpp` bind. A name has one
address, so `0x01016978` is not 0.0001f, and the address holds 0.001f.

| Unit | Recipe name at the address | Function that loads one of the two values | Value loaded at the tip |
| --- | --- | --- | --- |
| `forenderedmenu.cpp` | 0.0001f | `FUN_007fb250_owner::FUN_007fb250` (`0x007fb250`) | 0.0001f |
| `pathsmootherpov.cpp` | both | `PathSmootherPOVSearch::CalculatePathCost` | 0.001f |
| the other 14 units | 0.001f | 13 load 0.001f; `hudmainmenu.cpp` loads neither | 0.001f |

`blk_006a0000_od.cpp` and `blk_009c0000_od.cpp` also load 0.0001f, from the
float that the recipe binds at `0x010141cc`. That is another constant.

`FUN_007fb250` starts the vertical hold, the roll of the Pip-Boy screen
that the ticket calls a shudder. Its caller in `fopipboymanager.cpp` passes
the settings `fDefaultVertHoldDuration` and `fDefaultVertHoldSpeed`. It
stores the second argument, `afIntensity` in the source, times the constant
as a float rate. `FUN_007fb480` multiplies that rate by the time elapsed
since the start. The change makes the stored rate
`afIntensity * (double)0.001f`, ten times the value before. If the timer
counts milliseconds, which is an inference, 0.001 converts a rate per
second into one per millisecond.

The float literal widened to double is the form the recipe names. clang
narrows `f * (double)0.001f` to a float multiply that loads
`__real@3a83126f`; the product of two floats is exact in double, so the
result is the same either way. No function of `pathsmootherpov.cpp` loads
0.0001f, so its source does not change.

In the recipe, `forenderedmenu.cpp`'s key is respelled to the 0.001f name.
`pathsmootherpov.cpp` already binds the 0.001f name to the address, so its
0.0001f key is dropped. No address, function row or other key changes.

## 0x01031148: 0.01

Six units bind 1.1 to the address and four bind 0.01. Neither name has a
second address, so the recipe alone does not decide. One address holds one
value, so all ten loading sites below load the same constant. With 1.1,
three independent sites have no meaning:

- The simple-decal clamp. `FUN_0068ad20` (`0x0068ad20`, in
  `bstempeffectsimpledecal.cpp`) stores `cos(angle)` and on the next line
  `FUN_0068b050(C, that)`, which returns the larger of its two arguments. A
  cosine is at most 1, so with 1.1 the result is always 1.1 and the cosine
  is never used. The two readers of the stored value in the same unit
  agree: one computes `1 / (1 − value)` as a fade scale, which is negative
  for 1.1; the other accepts a triangle when the dot product of its normal
  with the direction exceeds the normal's length times the value, which a
  unit direction cannot do for 1.1.
- The caravan threshold. In `CaravanGame::FUN_00741500` the movement
  components are axis values divided by 32767. For the 16-bit axis values
  that the divisor implies, their magnitudes are at most 32768 / 32767,
  about 1.00003. With 1.1 both steps are always 0.
- The terrain grass interpolation. `GenerateGrassPositions` compares the
  fractional parts of two texture coordinates with C. A coordinate minus
  its integer part is below 1, so with 1.1 the neighbouring densities are
  never read.

No site makes 0.01 meaningless. With 1.1 the speed formulas give 110 times
the multiplier at actor value 100, where `FUN_00647fd0`, which already used
0.01, reads actor value 21 as a percentage.

The owner delegated the decision. The coordinator accepted the change to
0.01 at every site on this evidence. It is not a reading of the original.

Every site that loads a constant bound to the address, at the tip:

| Site | Function | What the code does with C | With 1.1 | With 0.01 | Before |
| --- | --- | --- | --- | --- | --- |
| `creature.cpp` | `Creature::CalculateRunSpeed` (`0x008d4eb0`) | run speed = actor value 21 × C × run animation multiplier; 0 when overencumbered | 110 times the multiplier at actor value 100 | 1 times the multiplier at actor value 100 | 1.1 |
| `actor.cpp` | `Creature::FUN_008d4f10` (`0x008d4f10`) | the same with animation group 7 | as above | as above | 1.1 |
| `gameplayformulas.cpp` | `FUN_00647d10` (`0x00647d10`) | actor value 21 × C, then × a setting × a base factor | as above | as above | 1.1 |
| `gameplayformulas.cpp` | `FUN_00647fd0` (`0x00647fd0`) | actor value 21 × C interpolates between two settings | at actor value 100, the first setting plus 110 times the difference | at actor value 100, the second setting | 0.01 |
| `main.cpp` | `FUN_008744a0` (`0x008744a0`), six comparisons | sets a flag when (current − stored) / stored exceeds C in any component of two vectors | a change of more than 110 percent | a change of more than 1 percent | 1.1 |
| `caravanmenu.cpp` | `CaravanGame::FUN_00741500` (`0x00741500`), two comparisons | step 0 when \|movement\| < C, else the sign of the movement; \|movement\| ≤ 32768 / 32767 | always 0: no meaning | a dead zone of 0.01 | 1.1 |
| `bstempeffectsimpledecal.cpp` | `FUN_0068ad20` (`0x0068ad20`) | max(C, cos(angle)) | always 1.1: no meaning | the cosine, clamped below at 0.01 | 1.1 |
| `projectile.cpp` | `PVProjectile::FUN_009ab390` (`0x009ab390`) | a value below C | threshold 1.1 | threshold 0.01 | 0.01 |
| `packagedatauseweapon.cpp` | `FUN_0067cfc0` (`0x0067cfc0`), two comparisons | two values differ when \|a − b\| > C | tolerance 1.1 | tolerance 0.01 | 0.01 |
| `testerrainlodmanager.cpp` | `GenerateGrassPositions` (`0x0057de00`), three comparisons | a fractional texture coordinate, below 1, above C | never: no meaning | threshold 0.01 | 0.01 |

The decal clamp, the caravan threshold and the grass interpolation have no
meaning with 1.1. No site makes 0.01 meaningless. The address joins all ten
sites. At every site the constant stays a double, as the recipe names it.

In the recipe, the 1.1 key is respelled to the 0.01 name in five units.
`gameplayformulas.cpp` already binds the 0.01 name to the address, so its
1.1 key is dropped.

## 0x010231d8: undecidable from the repository

Five units bind 256.0 and three bind 200.0. Neither name has a second
address and no site makes one value meaningless.

| Site | Function | What the code does with C | Value at the tip |
| --- | --- | --- | --- |
| `bstempeffectgeometrydecal.cpp` | the function at `0x00683c10` | texture z = power(opacity, 10) × (1 − \|z\| / C) | 256.0f |
| `bstempeffectgeometrydecal.cpp` | the function at `0x00685ef0` | the same expression in the sibling function | 200.0f |
| `falloutaudio.cpp` | `SoundPlaybackManager::ProcessPendingSounds` (`0x0082d7c0`) | adds C to the height of a pending sound before it is placed | 200.0 |
| `combatprocedureengagetarget.cpp` | `Engage::PrintDebugInfo` | passes C after the distance to a debug print; no function of the x64 object loads it | 200.0 |
| `combatstate.cpp` | `CombatUpdate::FUN_00997cf0` (`0x00997cf0`) | a search range at least C beyond another range | 256.0 |
| `combatutilities.cpp`, `tesscriptfunctions.cpp`, `testerrainlodmanager.cpp` | none loads either value | recipe binding only | 256.0 |

The two decal functions compute the same expression and must end equal.
Three of the sites write a float literal where the recipe names a double.

It is recorded as undecidable from the repository. What would decide it:
the eight bytes at the address in the original release, which the ticket
does not admit as a prerequisite, or a site found later where one of the
values has no meaning.

## 0x010229b8: undecidable from the repository

| Site | Function | Value at the tip | What the code does with C |
| --- | --- | --- | --- |
| `robertdavies_random.cpp` | `Random::Raw` (`0x00b43310`) and five other functions | 4.656612875e-10 | scales the seed of a Lewis-Goodman-Miller generator to a uniform value |
| `niconsolerenderer.cpp` | `DecodeVertexData` | 2^-31 | scales a decoded integer vertex value |

The documentation of R B Davies' newran library, version newran02C, says
that its `Random` class uses the Lewis-Goodman-Miller algorithm, with
Marsaglia mixing. That generator's seeds lie between 1 and 2^31 − 2, and
its scale is 1/(2^31 − 1) = 4.6566128752e-10, which is 4.656612875e-10 to
ten significant digits. `Random::Raw`'s literal is that value. 2^-31 is the
natural scale for a signed 32-bit integer, so `DecodeVertexData`'s literal
is plausible too. The documentation does not print the constant, and
neither value is meaningless at its site.

It is recorded as undecidable from the repository. What would decide it:
the eight bytes at the address in the original release; the constant in the published newran source, which would show
what the library writes but not that the game's copy was unchanged; or the
scale that Gamebryo's documentation gives for the vertex format.
`niconsolerenderer.cpp` is not one of the ticket's sites.

`Normal::Density` loads 0.398942280 from `0x010a5a78`, which has one name.
It is not in conflict.

## What was measured

The tip `81a5145fb` was built in full for windows-x64. Each change was then
built in the same export path and build tree, and its archive was compared
with the one before it.

- Recipe: the two changes alter `symbols` keys at `0x01016978` and
  `0x01031148` only. No address, function row, unit or other field changes.
- Build: no failed step. The warnings of every rebuilt step equal the tip's
  once line and column are removed.
- Archive: 2,224 members in the same order. The first change rebuilds
  `forenderedmenu.cpp` only; the second rebuilds `actor.cpp`,
  `creature.cpp`, `caravanmenu.cpp`, `main.cpp`, `gameplayformulas.cpp` and
  `bstempeffectsimpledecal.cpp`. `build/units.json` is not a build input.
- Links of all four kinds (lazy and forced extraction, each ordinary and
  unlimited): no name leaves or enters the undefined list, no duplicate,
  imports equal. The forced unlimited link has 35,196 undefined names before
  and after.
- Names with differing definitions in the archive: 525 before and after,
  none leaving or entering. No name of a class named `BSSimpleList` has two
  definitions.

In each changed function only the constant that one or more loads name
changes. The instruction streams are equal once the `__real@` names of the
relocation targets are masked:

| Change | Function | Loads whose target changes |
| --- | --- | --- |
| `0x01016978` | `FUN_007fb250_owner::FUN_007fb250` | 1: 0.0001f to 0.001f, as a float |
| `0x01031148` | `Creature::CalculateRunSpeed` | 1: 1.1 to 0.01 |
| `0x01031148` | `Creature::FUN_008d4f10` | 1 |
| `0x01031148` | `FUN_00647d10` | 1 |
| `0x01031148` | `FUN_008744a0` | 6 |
| `0x01031148` | `CaravanGame::FUN_00741500` | 1: both comparisons use one load |
| `0x01031148` | `FUN_0068ad20` | 2: the double, and 1.1f to 0.01f, the float the compiler stores when the constant is the larger value of the inlined maximum |

The windows-x64 compiler emits its own constants, so these names are not
the recipe's. In `gameplayformulas.cpp` and `bstempeffectsimpledecal.cpp`
the 1.1 constants are gone, so each object has one constant section fewer.

The host suites, optimized and with ASan, UBSan and vptr checks, were run on
the second change and on the tip. They have the same per-test results and
the same failed build steps: 54 passed, 15 not run and 2 failed of 71
optimized; 53, 16 and 2 with the sanitizers. No new test was added.

`tools/hooks/public-check` is a bash script. Run it directly or with
`bash`; under `sh` it stops with a syntax error.

## Not covered

- No function changed here has a test, and none was executed. The credit
  for the two changes is limited to "shown at source and object level,
  never executed". The coordinator accepted landing them on that basis.
  `forenderedmenu.cpp`, `actor.cpp`, `main.cpp`, `caravanmenu.cpp` and
  `bstempeffectsimpledecal.cpp` do not build on the host. The changed
  functions of `creature.cpp` and `gameplayformulas.cpp` read actor values
  through a virtual call, and a test would need a real actor.
- Nothing was run on Windows.
- The change at `0x01031148` rests on the evidence above, not on a reading
  of the original.
- `0x010231d8` and `0x010229b8` are not changed, and the 1.2f name with two
  addresses is not examined.
- The ticket asks for a tested correction at each changed site, so it stays
  open.
