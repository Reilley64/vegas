# Bodies that return void while callers use a result

VEGAS-124. `void-result-bodies.tsv` lists the bodies at recipe function rows
that return `void` while a requiring unit calls the row's address through a
declaration with a result, and uses that result. Such a call cannot bind to
the body: the caller's object is the same whichever name it calls, so an
object proof does not see the missing result, and `tools/bind-batch` refuses
the call as `void-result-used`.

The table was derived at `9b14ee21c`. It holds 202 definitions, reached by
455 names, with 799 call sites that use a result.

## The table

Tab-separated, one line per definition, the definition reached by the most
names first.

| Column | What it holds |
| --- | --- |
| `address` | the recipe function row's address |
| `unit` | the source of the row, every recipe entry of it merged |
| `row` | the row's 32-bit symbol |
| `row_result` | the result type that symbol carries |
| `body` | file and line of the body's definition |
| `body_result` | the result type the body declares |
| `dropped` | the type of the value that the body's last statement computes and drops, as clang writes it (with the type it stands for in parentheses); `void` when that statement computes no value; `-` when the body ends in a statement that is not an expression |
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

## What it shows

Every row says `void` (`X` in its symbol), and every body declares `void`.
No row carries the result that the callers use, so no row establishes one.

| `note` | Definitions |
| --- | --- |
| every caller uses the dropped value's type | 60 (149 names, 281 sites) |
| callers use another type than the dropped value's | 46 |
| callers use 2 to 13 result types | 29 |
| the body computes no value | 50 |
| the body ends in a statement, not a dropped value | 17 |

For example, `NiObjectNET::GetNumChildren` at `0x0043b480` evaluates
`GetShortAtOffsetA()`, whose row at `0x00658930` returns `unsigned int`,
and drops it, while each of its 66 names declares an `unsigned int` result.

## What stays open

No body is repaired. A result type for a body whose row says `void` needs a
decision on what may establish it: the dropped value and the callers, with
the row respelled to match. Until then each definition stays open, with
the `note` as the reason.

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
