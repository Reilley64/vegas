# Bodies that return void while callers use a result

VEGAS-124. `void-result-bodies.tsv` lists the bodies at recipe function rows
that return `void` while a requiring unit calls the row's address through a
declaration with a result, and uses that result. Such a call cannot bind to
the body: the caller's object is the same whichever name it calls, so an
object proof does not see the missing result, and `tools/bind-batch` refuses
the call as `void-result-used`.

The table was derived at `9b14ee21c`. It holds 202 definitions, reached by
460 names, with 804 call sites that use a result; five of those names were
added while repairing (below).

## The table

Tab-separated, one line per definition, the definition reached by the most
names first.

| Column | What it holds |
| --- | --- |
| `address` | the recipe function row's address |
| `unit` | the source of the row, every recipe entry of it merged |
| `row` | the row's 32-bit symbol; for a repaired body, as respelled with the result |
| `row_result` | the result type that symbol carries |
| `body` | file and line of the body's definition |
| `body_result` | the result type the body declares |
| `dropped` | the type of the value that the body's last statement computes and drops, as clang writes it (with the type it stands for in parentheses); `void` when that statement computes no value; `-` when the body ends in a statement that is not an expression; for a repaired body, the type of the value it now returns |
| `used_as` | the result types under which the requiring units declare the callee, as their names carry them |
| `names` | how many such names use the result |
| `note` | how `dropped` and `used_as` compare |
| `callers` | every call site that uses the result, as file and line |

## How it was derived

The survey was not repeated. Its inputs are the two earlier lists: the
acceleration research at `c3ad69b43` (201 definitions) and the
`void-result-used` sites of the `tools/bind-batch` gate at `1a4404c01`
(280 sites). Each requiring unit and name of those lists was looked up again
at the tip:

- The address is the requiring unit's recipe `symbols` key for the name,
  every entry of the source merged, compared by demangled name with the
  calling convention and `__ptr64` aside. Where no key matches, a key that
  spells a pointer-sized integer as `int` is matched with `__int64` read as
  `int`.
- The definition is the function row at that address.
- The call sites come from the unit's AST at the tip, through the
  extraction of `tools/bind-batch`. A call uses its result unless it is a
  whole statement of a block, is cast to `void`, is the body (not the
  condition) of an `if`, loop, `switch`, `case` or label, is a `for`
  increment or is the left operand of a comma.
- `body_result` is read from the definition that follows the row's
  `// @fnv` marker. `dropped` is the type of the body's last statement in
  the AST of the row's unit.

Not tabled:

- Two names whose unit has no recipe key for them at one address:
  `?FUN_00d2d4b0@@YAPEAXPEAXPEAUS00d2d890_Hits@@@Z` in
  `hkpbvtreeagent3.cpp` and
  `?FUN_00449f80@FUN_0044b8d0_Class@@QEAAPEAUItem@@XZ` in
  `threadsafestructures.cpp`. Their definitions are tabled through other
  names.
- Five definitions whose only listed site does not use the result at the
  tip: `0x004740a0` (`tesfile.cpp:1105`, listed at line 1112 by the gate,
  the body of an unbraced `if`),
  `0x00726db0`, `0x00adb1a0`, `0x00cd2470` and `0x00cf2410` (each a whole
  statement).

Before a definition is repaired, every recipe `symbols` key at its
address, every entry of every source merged, is read. At three
definitions whose callers all used the dropped value's type in the
surveys, a unit's key carries another result type and its call uses the
result at a site the surveys did not list. Those names and sites are now
in their rows, whose notes say so:

- `0x0043b480`: `teseffectshader.cpp:571` declares `int`.
- `0x00433a00`: `extradatalist.cpp:14029` declares `int`,
  `extradatalist.cpp:14105` `fnv_0041ea30::ReferenceFloatEntry *` and
  `extradataobjects.cpp:6309` `ActivateEntry334 *`.
- `0x00863d90`: `tessaveloadgame.cpp:2465` declares `unsigned short`.

## What it shows

At `9b14ee21c` every row said `void` (`X` in its symbol), and every body
declared `void`: no row carried the result that the callers use. A body
whose `note` says repaired now returns the value, under its row respelled
with the result.

| `note` | Definitions |
| --- | --- |
| repaired: the body returns the value | 10 (32 names, 52 sites) |
| every caller uses the dropped value's type | 47 (48 names, 87 sites) |
| callers use another type than the dropped value's | 46 |
| callers use 2 to 13 result types | 32 |
| the body computes no value | 50 |
| the body ends in a statement, not a dropped value | 17 |

For example, `NiObjectNET::GetNumChildren` at `0x0043b480` evaluates
`GetShortAtOffsetA()`, whose row at `0x00658930` returns `unsigned int`,
and drops it, while 66 of its 67 names declare an `unsigned int` result
and one declares `int`.

## What stays open

A body whose row says `void` may return the value it computes and drops,
with its row respelled, when its last statement is an expression of the
result type, every caller that uses the result declares exactly that
type, and a dropped call's own row returns it (VEGAS-124, ruling of
2026-11-14). Each other definition stays open, with the `note` as the
reason.

Ten bodies are repaired, the largest first by names, each in its own
commit with its object proof: `0x0044df20`, `0x00696540`, `0x004e32c0`,
`0x004e32e0`, `0x004dfea0`, `0x0044a2c0`, `0x004dc2b0`, `0x004e3280`,
`0x004e32a0` and `0x006c08e0`. `objects.void_result_repairs`
(`tools/function-relocations/void-result-repairs.tsv`) requires each
under its row's name and forbids the former `void` name. The callers
were not changed: a caller's own name that now matches a repaired
definition is bound later by `tools/bind-batch`. `0x00877a50`, in
`src/fallout/misc/main.cpp`, is left for the work that owns that unit.

Blind spots:

- The use rule is read from the AST, not from the objects.
- A call in a file that the unit includes has no position in the unit's
  AST. Its line was found by name in the files the unit includes from its
  own folder; one site is placed so (`nifixedstring.inl:128`).
- `used_as` comes from the requiring units' own declarations. Whether their
  receivers, argument types and layouts match the body is not checked.
- `dropped` names only the type of the last statement. Whether that value
  is what the original returned is not established.
- The inputs list the definitions that the two earlier surveys found. A
  definition that neither found is not in the table.
- The keys read before a repair are the recipe's. A caller whose unit has
  no key for its name at the address is not seen.
- The `callers` and `names` columns of the repaired rows come from the
  two surveys and may be incomplete. Before each repair the callers were
  found again from every recipe key at the address and every spelling of
  it in the tree; that sweep is the input to condition (b), not the table.
