# The warning sink and its format types

VEGAS-84 asked whether the warning sink at `0x005b5e40` should emit text.
It stays silent. This change repairs the three calls whose arguments did
not have the types their format text names. The sink is not touched.

## The sink

The recipe has one function row at `0x005b5e40`:
`int FUN_005b5e40(...)` in `src/fallout_shared/tesscriptfunctions.cpp`,
18 bytes. The body returns 0. It has no named parameter, so it cannot read
its arguments, and it formats and emits nothing. `scriptrunner.cpp` calls
it the release build's empty logger.

The decision of 2026-11-12, recorded on the ticket, keeps it silent: that
is the behaviour of the original release as far as the repository shows.
Routing calls that carry a format to a typed function that emits would be
a separate feature. So no test of emitted text exists for this ticket.

The recipe binds seven names to the address, in 288 recipe unit entries
(263 source files). A lexical scan
of the source finds 1,303 calls of these names, and 1,229 of them pass no
argument. The calls that pass arguments are printf-shaped: a format, then
its values. The format text of 36 of them is known.

## The three repaired calls

The arguments' values and the order and number of their evaluations are
unchanged. Each call now passes the type its placeholder names.

| Unit and function | Placeholder | Argument before | Argument now |
| --- | --- | --- | --- |
| `bipedanim.cpp`, `BipedAnim::AttachBipedModel`, the unnamed-bone warning | `%i` | `j`, `unsigned int` | `(int)j` |
| `animation.cpp`, `AnimationBlend::BlendAnimation::FUN_004949a0`, the controller-count morph warning | `%d` twice | `(unsigned int)` of the `intptr_t` that `FUN_0084e3a0` returns | `(int)` of the same call |
| `animation.cpp`, `fnv_00499b90::Holder_00499b90::WriteToStream`, the save block size warning | `%s` | the source file name's address as `std::uintptr_t` | the same address as `char *` |

The comparison of the two controller counts just above the morph warning
keeps its `unsigned int` casts.

## Machine code

The windows-x64 objects of both units are byte-identical to those before
the change apart from the COFF header's timestamp. Each argument is passed
by the same instruction in both forms:

- the bone index: `mov edx, r12d`, a 32-bit move;
- each controller count: a 32-bit store, `mov dword ptr [rsp+20h], r15d`,
  and a 32-bit move, `mov r8d, ebx`;
- the file name: `lea rdx, [DAT_0101d930]`, a 64-bit address.

## How the types were checked

The format text of the 36 calls is a literal at the call or a data symbol
whose definition is in the tree. In a scratch copy, each of them was
rewritten to call a function declared
`format(printf, 1, 2)`, with its text as a literal. Then each unit was
parsed with its windows-x64 compile command plus `-Wformat`,
`-Wformat-signedness` and `-Wformat-pedantic`, five units. Before the
change the compiler reported the four arguments above and nothing else.
After it, it reports no format diagnostic.

This is not a standing check. The sink's names are declared without a
format attribute, and most calls that pass arguments (43 of 74) pass the
format as a data symbol, which the attribute cannot check.

## Not covered

- In the windows-x64 game archive no member defines the names these three
  calls use: `Warning(const char*, ...)`,
  `AnimationBlend::FUN_005b5e40(const char*, ...)` and
  `fnv_00499b90::FUN_005b5e40(void*, ...)`. The recipe binds the first two
  to `0x005b5e40` for the unit and does not name the third. Which
  definition they should reach is not changed here.
- Calls whose format is not known in the tree were not checked: those that
  pass a one-byte data symbol, a symbol with no definition, or text built
  at run time as the format.
- The other sites of the ticket are not dispositioned here.
