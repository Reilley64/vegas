# The npos of the string library

VEGAS-100. The recipe, `build/units.json`, binds `?g_010173f0@@3IA` to
`0x010173f0` in 17 sources over 26 entries. Its users pass it where the
string code expects `npos`: as the length of `assign`, `append` and `erase`,
in the bounds test `npos - _Mysize <= _Count`, and in position tests such as
`idx == npos`. `src/speedtree/frondengine.cpp` defined it zero-initialised,
so every bound unit received 0 there.

It is a code-level constant and stays in source, not in the pack (D1 of the
2026-11-12 catalogue rulings). The definition is now

```cpp
unsigned int g_010173f0 = 0xFFFFFFFFu;
```

## How the users read it

A compiler plugin, kept outside the repository with the review evidence,
listed every reference to a variable whose name contains `010173f0` in the
190 units of the game archive that include `fnv/symbols_01017000.h` or
`fnv/decl/fnv_00ac87b0__String.h` or name the address in their own text.
Each unit was parsed with its own windows-x64 command, template
instantiations included. For each reference it records how the object is
read and what consumes the value. 190 references in 18 units:

| Class | References | Read as | Consumed as |
| --- | --- | --- | --- |
| 32-bit unsigned | 110 | `unsigned int` | an `unsigned int` argument, operand, return value or default argument |
| 32-bit signed | 57 | `int`, through `*reinterpret_cast<int *>(&g_010173f0)` or a private `extern int` | an `int` argument, or converted back to `unsigned int` |
| unsigned to `int` | 1 | `unsigned int` | an `int` argument |
| zero-extended | 3 | `unsigned int` | compared with `!=` against a `uintptr_t` |
| 8-byte read | 2 | `void *`, through `*reinterpret_cast<void **>(&g_010173f0)` | a `void *` argument |
| template pattern | 17 | `unsigned int` | inside a template; each instantiation is its own row above |

So every user that compiles to code reads the 32 bits of an `unsigned int`,
or the same 32 bits as an `int`, where all ones is -1. None needs a 64-bit
`npos`, and none writes the object.

- The three zero-extended reads are in `messagemenu.cpp`
  (`MessageCreation::QueueMessage` and two in `BuildActionMenu`). The other
  side is a `uintptr_t` initialised from `FUN_007aafe0`, which the unit
  declares to return `unsigned int`, so both sides are zero-extended 32-bit
  values and `0xFFFFFFFF` compares as `npos`. Both declarations of
  `FUN_007aafe0` are undefined names at c7abe570e.
- The two 8-byte reads load 4 bytes past the end of the object, whatever its
  value: `S00ac5490_Str`'s copy constructor in `tile.cpp`, which passes it to
  `S00ac5490_Str::Set`, and `FUN_0044a500_s::FUN_0044a500` in
  `raiseexception.cpp`, which passes it to `FUN_0044a500_s::AssignSubstring`.
  No object defines either callee, so no linking program runs these calls.
  They are left as they are; the repair belongs to the callee's binding,
  whose parameter is a 32-bit count in the original release.
- The seven template patterns in `tileimage.cpp` and `cuassembler.cpp`
  belong to copies of `std::basic_string` whose `size_type` is dependent.
  Neither unit instantiates them. An instantiation with a 64-bit
  `size_type` would need its own `npos` expression, not a wider
  definition.

## Why the definition stays writable

The original's `npos` is a constant, and a `const` definition would say so.
But a `const` object has another mangled name, `?g_010173f0@@3IB`. Every
recipe key (26 entries in 17 sources) and both header declarations would be
respelled, and each of the 56 casts that read it (53 to `int *`, 2 to
`void **`, 1 to `unsigned long *`) would need a `const` added inside it. Measured
with such a definition, about 42 functions in 8 units change, because their
loads are hoisted or folded, and each would need its own object proof. That
is VEGAS-105. No user writes the object, so the writable definition keeps
every user's object and every recipe key as they are; only the defining
object changes. Its one change is the value: 4 bytes of `.data` holding
`ff ff ff ff` instead of 4 bytes of `.bss`.

## The check

`objects.string_npos` runs `tools/data-values` on `string-npos.tsv` in the
windows-x64 cross build. It requires the bytes `ffffffff` at
`?g_010173f0@@3IA` in the object of `frondengine.cpp`. On the earlier
object it fails: the name lies in `.bss`, which has no initialised
contents. No host test is possible: no unit that reads the name links into
a host test.

## The two record models

The census of undefined names at 2fa5deb28 held two names of this address
back until the value was repaired: `DAT_010173f0` in the record models of
namespaces `fnv_00b3e520` and `fnv_00b2e3f0` in `blk_00b20000_od.cpp`,
declared `extern const unsigned int`. No object defines them. They stay
as they are: respelling them to the writable definition would drop their
`const`, which changes the type of the use; three functions would then load
the value before each call in a loop instead of once. They wait for the
`const` definition, VEGAS-105, under which they keep their `const`.

## What stays open

- Two other private declarations of the address remain:
  `fnv_00b3a050::DAT_010173f0` in `blk_00b20000_od.cpp` and
  `fnv_00b1f9e0::DAT_010173f0` in `frondengine.cpp`. Their users are inline
  members that no object emits, so they are not undefined names today.
  `record_model::DAT_010173f0` in `blk_00b20000_od.cpp` is declared and not
  used.
- The two 8-byte reads above.
- The `const` definition and the two record models, VEGAS-105.
