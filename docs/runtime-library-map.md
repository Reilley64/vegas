# Runtime library calls and the standard library (VEGAS-23)

The original program links Microsoft's C runtime and C++ library statically.
`build/units.json` binds 175 addresses of that code to names that game units
call, between `0x00ec2f00` (the last recipe function before the library) and
`0x00ee6d44` (the first import thunk). This document says what each address is,
how sure that is, what the units call today and what this change mapped.

This is the increment of VEGAS-23 on the link frontier of 2026-11-10. Two
earlier parts of the ticket are merged already: one covered about 2,900
runtime calls, the other the global `operator new` and `operator delete`. `src/runtime/crt.h` declares about
30 `fnv::crt` project functions for the runtime functions that have no
standard equivalent.

This increment maps 13 addresses at 62 call sites in 23 units. 23 undefined
names leave the forced link of every archive member (35,574 to 35,551) and
none enters. Everything else is listed with a proposed treatment and is not
implemented. VEGAS-23 stays open.

## Scope and method

- **Address authority.** `build/units.json`. An address is in scope when a
  unit's symbol row binds a name to it and no recipe function row owns it.
  Three addresses below the range are included because the link frontier files
  them here: `0x00406cc0`, `0x004564f0` and `0x0046fd30` carry runtime names
  but lie in the game's own code range and have no function row.
- **What units call today** is read from the built windows-x64 archive, not
  from the source text: for each unit, the symbols its object uses under the
  recipe's names, the relocations that reference them, and where each resolves
  (the toolchain's runtime, another archive member, or nowhere).
- **Call-site shapes** come from the compiler's syntax tree: the declared type
  of the stand-in, each argument's type as written, and the node that consumes
  the result.
- The original code's bytes are not available. An identification rests on the
  name the units already use (N), the call-site argument shape (S), the
  position next to an identified neighbour in the well-known layout of the
  static Microsoft runtime (L), or an idiom at the call site (I). An
  identification is marked "inferred" when no unit names the function, when
  only one unit does and the name is its own guess, or when the units' names
  disagree. 25 of the 190 rows are marked so, 4 of them among the 13 mapped
  addresses.

## Classes

| class | meaning |
|---|---|
| a | a standard C or C++ function, identical for the calls the tree makes |
| b | a function whose result a call site could observe differently: secure variant, Microsoft-only name, 32-bit file offsets, implementation-defined sequence. It needs a project function (`fnv::crt`, `src/runtime/crt.h`) or a decision per site |
| c | a compiler helper. A native build has no source-level call to it, so the call must become the source construct that produced it |
| d | startup, shutdown, heap and the old C++ library's internals |
| e | not identified from the tree |
| x | not a runtime function: game code or an import thunk inside the scanned range |

| class | addresses | with an undefined name at the tip | undefined names at the tip |
|---|---|---|---|
| a | 63 | 17 | 35 |
| b | 25 | 6 | 40 |
| c | 27 | 4 | 54 |
| d | 25 | 19 | 62 |
| e | 37 | 11 | 35 |
| x | 13 | 0 | 0 |
| total | 190 | 57 | 226 |

Undefined names are the names the forced link of every member leaves undefined
at the parent commit `9d640192c`. The link frontier counts the same 226 names
at 57 addresses.

Separately, 38 undefined names carry `std::` or `stdext::` names of the old
library with no address binding: 26 in `speedtree/indexedgeometry.cpp` (the
old `std::vector` helpers), 4 in `fallout_shared/tesobject.cpp` (old string
and stream members), and 8 in six other units. They need the real standard
class in the unit, which is typed owner work, and are not touched here.

## The rule for mapping a call

A stand-in is one function a unit declares for a library address and that its
object leaves undefined, or that only another member's project body satisfies.
It is mapped only if all of this holds:

1. The address is identified as a class a function.
2. The stand-in's parameter types are the standard prototype's, with one
   exception: a size parameter may be declared `unsigned int`, or `int` when
   every argument passed to it is a non-negative literal.
3. Each argument converts without a cast and without changing value on
   windows-x64. A signed integer passed as a size is refused unless it is a
   non-negative literal, because sign extension to 64 bits changes a negative
   count.
4. An arithmetic argument is written with exactly the parameter's type.
   Otherwise the standard overload set would select another function: a
   `float` argument to `std::cos` calls the `float` overload, which computes a
   different result.
5. The stand-in's result type is the standard function's, with two
   exceptions, each taken only where the site converts the result without
   changing its value: a stand-in that returns `double` for the `float`
   function `floor`, and a stand-in that returns `int` for `strstr` whose
   result is only tested against zero. `unsigned int` for `size_t` and `void`
   or `void*` for the `void*` of `memset` and `memmove` are accepted too.
6. Every reference to the stand-in is a direct call, every declaration of it
   is a whole-line declaration in the unit's own source file, and the unit
   does not define it.
7. Every call site of the stand-in passes, and every unit that references the
   same name passes.

No cast is added, no wrapper function is written and no link alias is used.
The call names the standard function with its qualified name and the
stand-in's declarations are removed.

Every rewritten unit names the C++ header of each standard name itself, on a
line before the first rewritten use: `<cstring>`, `<cmath>`, `<cerrno>`,
`<cstdio>`, `<cstdlib>` or `<exception>`. The C spelling does not count,
because `<string.h>` is not required to declare the names in `std`. 13
`#include` lines are added. With only the `#include` added and nothing else,
9 of the 13 objects are byte-identical to the parent's. Three more differ only
in linker directives: `gameplayformulas.cpp`, `tesregiondataweather.cpp` and
`blk_004a0000_o2.cpp` included no C++ library header before, and `<cmath>`
brings the three `/FAILIFMISMATCH` checks and `/DEFAULTLIB:libcpmt.lib` that
1,085 of the 2,223 members already carry. The thirteenth is `tesdatahandler.cpp`, where the
`<cstdio>` line is the hand edit described below.

## What was mapped

| address | function there | evidence | now calls | units | stand-ins | call sites |
|---|---|---|---|---|---|---|
| `0x00406cc0` | float floor(float)  (<math.h> C++ overload, compiled into the game's own code range) | N: ?floor@@YAMM@Z in 7 units; S: float(float) | `std::floor` | 9 | 9 | 10 |
| `0x00ec3241` | std::uncaught_exception() | I: its caller is the destructor of an output-stream sentry, which tests it before the flush; L: 5 bytes to the next referenced address, the size of one jump; only one unit names it, and the name is that unit's own (inferred) | `std::uncaught_exceptions() > 0` | 1 | 1 | 1 |
| `0x00ec44d0` | memmove or memcpy (the units use both names for it) | N conflicting: memmove and memcpy; S: (void*, const void*, unsigned) (inferred) | `std::memmove` | 1 | 1 | 1 |
| `0x00ec6130` | strlen | N | `std::strlen` | 2 | 2 | 3 |
| `0x00ec61c0` | memset | N | `std::memset` | 4 | 4 | 24 |
| `0x00ec623a` | sprintf | N | `std::sprintf` | 1 | 1 | 1 |
| `0x00ec6cde` | fabs | N | `std::fabs` | 1 | 1 | 2 |
| `0x00ec7750` | strstr | N | `std::strstr` | 1 | 1 | 1 |
| `0x00ec7d40` | abs | N | `std::abs` | 1 | 1 | 11 |
| `0x00ec85e3` | _errno | S: int*(); I: *f() passed to the function at 0x00ecdb42 (inferred) | `errno` | 1 | 1 | 1 |
| `0x00ec8a19` | strncmp | N | `std::strncmp` | 2 | 2 | 3 |
| `0x00ec9a47` | fopen | N | `std::fopen` | 1 | 1 | 1 |
| `0x00ecdb42` | strerror | S: char*(int); I: called with *errno inside a bracketed error text (inferred) | `std::strerror` | 1 | 1 | 1 |

`0x00406cc0` is not in the library range. It is the runtime header's inline
`float floor(float)`, which the original compiler emitted among the game's own
functions; 7 units name it `?floor@@YAMM@Z`. It is mapped here because the
link frontier files its names with this ticket. Read strictly by range, it and
its 9 undefined names, 7 of which leave here, are a separate group.

Four of the 13 identifications are inferred:

- `0x00ec3241`, `std::uncaught_exception()`. One unit names it, in its own
  copy of the old stream classes. The call is in the destructor of an output
  stream sentry, which tests exactly this before it flushes, and the next
  referenced address is 5 bytes on, the size of one jump.
- `0x00ec44d0`, `memmove` or `memcpy`. The units use both names for the
  address. `std::memmove` is right for both.
- `0x00ec85e3` and `0x00ecdb42`, `_errno` and `strerror`. No unit names them.
  One site passes `*f()` to `g(int)` inside the bracketed tail of an error
  text.

Three stand-ins had no symbol row in their unit's recipe, so no recipe key
changes for them:

| unit | stand-in | address | how it was matched |
|---|---|---|---|
| `speedtree/treeengine.cpp` | `FUN_00ec85e3` | `0x00ec85e3` | the address in the stand-in's own name |
| `speedtree/treeengine.cpp` | `FUN_00ecdb42` | `0x00ecdb42` | the address in the stand-in's own name |
| `bsaudio/bsaudiomanager.cpp` | `fnv_zlib_memset` | `0x00ec61c0` | by name: `staging/blk_00e80000_o2.cpp` has a recipe row that binds `_fnv_zlib_memset` to the address, and no member defines the name |

Per unit:

| address | function there | unit | stand-in the unit called | call sites | now calls |
|---|---|---|---|---|---|
| `0x00406cc0` | float floor(float) | `fallout/ai/actor.cpp` | `floor : float (float)` | 1 | `std::floor` |
| `0x00406cc0` | float floor(float) | `fallout/magic/magicballprojectile.cpp` | `FUN_00406cc0 : float (float)` | 2 | `std::floor` |
| `0x00406cc0` | float floor(float) | `fallout_shared/gameplayformulas.cpp` | `_floor : double (float)` | 1 | `std::floor` |
| `0x00406cc0` | float floor(float) | `fallout_shared/region system/tesregiondataweather.cpp` | `_floor : double (float)` | 1 | `std::floor` |
| `0x00406cc0` | float floor(float) | `fallout_shared/tesscriptfunctions.cpp` | `floor : float (float)` | 1 | `std::floor` |
| `0x00406cc0` | float floor(float) | `staging/blk_004a0000_o2.cpp` | `FUN_00406cc0 : float (float)` | 1 | `std::floor` |
| `0x00406cc0` | float floor(float) | `staging/blk_00880000_od.cpp` | `FUN_00406cc0 : float (float)` | 1 | `std::floor` |
| `0x00406cc0` | float floor(float) | `staging/blk_009c0000_od.cpp` | `FUN_00406cc0 : float (float)` | 1 | `std::floor` |
| `0x00406cc0` | float floor(float) | `tesregiondatasound.cpp` | `blendFloor : double (float)` | 1 | `std::floor` |
| `0x00ec3241` | std::uncaught_exception() | `staging/blk_00ac0000_od.cpp` | `uncaught_exception : bool ()` | 1 | `std::uncaught_exceptions() > 0` |
| `0x00ec44d0` | memmove or memcpy | `fallout_shared/tesobject.cpp` | `FUN_00ec44d0 : void *(void *, const void *, unsigned int)` | 1 | `std::memmove` |
| `0x00ec6130` | strlen | `fallout_shared/tesobject.cpp` | `FUN_00ec6130 : unsigned int (const char *)` | 1 | `std::strlen` |
| `0x00ec6130` | strlen | `speedtree/speedtreert.cpp` | `_strlen : unsigned int (const char *)` | 2 | `std::strlen` |
| `0x00ec61c0` | memset | `bsaudio/bsaudiomanager.cpp` | `fnv_zlib_memset : void *(void *, int, unsigned int)` | 1 | `std::memset` |
| `0x00ec61c0` | memset | `staging/blk_00b80000_o2.cpp` | `FUN_00ec61c0 : void *(void *, int, unsigned int)` | 18 | `std::memset` |
| `0x00ec61c0` | memset | `staging/blk_00c80000_o2.cpp` | `FUN_00ec61c0 : void (void *, int, unsigned int)` | 3 | `std::memset` |
| `0x00ec61c0` | memset | `staging/blk_00e80000_o2.cpp` | `fnv_zlib_memset : void *(void *, int, unsigned int)` | 2 | `std::memset` |
| `0x00ec623a` | sprintf | `fallout_shared/tesobjectrefr.cpp` | `FUN_00ec623a : int (char *, const char *, ...)` | 1 | `std::sprintf` |
| `0x00ec6cde` | fabs | `fallout/ai/movement/detailedactorpathhandler.cpp` | `_fabs : double (double)` | 2 | `std::fabs` |
| `0x00ec7750` | strstr | `fallout_shared/tesobjectrefr.cpp` | `FUN_00ec7750 : int (const char *, const char *)` | 1 | `std::strstr` |
| `0x00ec7d40` | abs | `fallout/ai/playercharacter.cpp` | `FUN_00ec7d40 : int (int)` | 11 | `std::abs` |
| `0x00ec85e3` | _errno | `speedtree/treeengine.cpp` | `FUN_00ec85e3 : int *()` | 1 | `errno` |
| `0x00ec8a19` | strncmp | `fallout_shared/bgsdecalmanager.cpp` | `FUN_00ec8a19 : int (const char *, const char *, int)` | 2 | `std::strncmp` |
| `0x00ec8a19` | strncmp | `fallout_shared/tesobjectrefr.cpp` | `FUN_00ec8a19 : int (const char *, const char *, unsigned int)` | 1 | `std::strncmp` |
| `0x00ec9a47` | fopen | `fallout_shared/tesobject.cpp` | `FUN_00ec9a47 : void *(const char *, const char *)` | 1 | `std::fopen` |
| `0x00ecdb42` | strerror | `speedtree/treeengine.cpp` | `FUN_00ecdb42 : char *(int)` | 1 | `std::strerror` |

Two more units were edited by hand:

- `staging/blk_00d80000_o2.cpp` defined its own byte loop under the C name
  `FUN_00ec61c0`, with no recipe function row and no address tag. It was the
  only definition of that name in the archive, so the nine functions of
  `staging/blk_00b80000_o2.cpp` that call the name reached it only when a link
  happened to load that member. Both units now call `std::memset`, the body is
  removed and the unit includes `<cstring>`. No object references the name any
  more.
- `fallout_shared/tesdatahandler.cpp` declared `sprintf` by hand without the
  header. The toolchain's `sprintf` is an inline function, so the call bound to
  whichever other member carried a copy. The unit now includes `<cstdio>` and
  its object carries its own copy.

### Semantics of each mapping

| now calls | what the call site can observe |
|---|---|
| `std::floor(float)` | The function at `0x00406cc0` is the runtime header's own `float floor(float)`, which is `(float)floor((double)x)`. The floor of a `float` is a `float`, so the result is the same for every argument. In the object every site calls `floorf`. All ten sites convert the result straight to an integer. Three stand-ins were declared to return `double`: there the site converted a `double` to the integer and now converts the `float`, which is the same value. |
| `std::uncaught_exceptions() > 0` | True exactly when `std::uncaught_exception()` was true. The unit already uses this form in two other destructors. |
| `std::memmove` | The same, whether the original function is `memmove` or `memcpy`. The size is an `unsigned int` variable. |
| `std::strlen` | The same. The three sites keep the result in `unsigned int`. The original's `size_t` had 32 bits, so the original had no conversion there; the native syntax tree now has a narrowing from the 64-bit `size_t` at each of the three, and a length of 4 GiB or more would be cut. In `tesobject.cpp` the site is expanded into four calls with string-literal arguments, which are now folded to constants. |
| `std::memset` | The same. The sizes are literals and `sizeof` expressions, and one `unsigned int` variable in `bsaudiomanager.cpp`. Small fills are now expanded in line. |
| `std::sprintf` | The mapped site's format is `'%s' :%s` with two character pointers. No number is formatted, so the text does not depend on the runtime. The hand-edited site in `tesdatahandler.cpp` called the toolchain's `sprintf` before and after; its format has `%s` conversions only. |
| `std::fabs(double)` | The sign bit is cleared in line. Inferred, not verifiable here: the original entry also reports a NaN argument through the runtime's math error path. The two sites only compare the result. |
| `std::strstr` | The stand-in returned `int`, so the site tested the low 32 bits of a pointer. It now tests the pointer. |
| `std::abs(int)` | The same for every value but `INT_MIN`, which is undefined in the standard function. The arguments are controller axis values. |
| `errno`, `std::strerror` | One site builds the bracketed tail of a SpeedTree error text. The message text belongs to the runtime in use. |
| `std::strncmp` | The same. The three counts are literals; one stand-in declared the count as `int`. |
| `std::fopen` | The same, mode `"wb"`. The unit keeps the handle in its own `GvFileHandle*` through a cast it already had; that cast now takes `FILE*` instead of `void*`. |

Result conversions at the 62 sites, from the syntax tree of the rewritten
source: a `float` converted to an integer (10 sites, `floor`), `size_t`
narrowed to `unsigned int` (3 sites, `strlen`, new in the tree as said above),
a pointer tested for truth (1 site, `strstr`), an `int` tested for truth
(1 site, `strncmp`), an `int` converted to `float` (1 site, `abs`), `char*`
to `const char*` (1 site, `strerror`), and the `fopen` cast above (1 site).
The other 44 sites use or drop the result as it is.

A standard function that cannot throw has no unwind entry at its call. In
functions with cleanups the compiler therefore renumbers its cleanup blocks.
No function changes that does not contain a mapped call, and no other
reference to a toolchain function in the 23 units binds to another function
type than before.

### The recipe

`build/units.json` keeps every address, size, function row and unit. Only
symbol-row keys change: the key under the stand-in's 32-bit name becomes the
original function's own 32-bit name at that address, in place. Where the unit
already had that key at the same address, the old key is merged into it. 18
keys are respelled and 5 merged. No requirement is removed: each unit still
requires the same address.

The key names the original function, not the symbol a compiler emits for the
new call. They differ in three cases:

- the key at `0x00ec3241` is `?uncaught_exception@std@@YA_NXZ`, and the call
  is `std::uncaught_exceptions()`;
- the key at `0x00406cc0` is `?floor@@YAMM@Z`, and the object calls `floorf`;
- the key at `0x00ec623a` is `_sprintf`, and the toolchain's `sprintf` is an
  inline function that calls `__stdio_common_vsprintf`.

| unit | old key | new key | address | action |
|---|---|---|---|---|
| `fallout/ai/actor.cpp` | `?floor@fnv_0088e8d0@@YAMM@Z` | `?floor@@YAMM@Z` | `0x00406cc0` | merged |
| `fallout/ai/movement/detailedactorpathhandler.cpp` | `?_fabs@fnv_009e2aa0@@YANN@Z` | `_fabs` | `0x00ec6cde` | respelled |
| `fallout/ai/playercharacter.cpp` | `?FUN_00ec7d40@@YAHH@Z` | `_abs` | `0x00ec7d40` | respelled |
| `fallout/magic/magicballprojectile.cpp` | `?FUN_00406cc0@fnv_0081a320@@YAMM@Z` | `?floor@@YAMM@Z` | `0x00406cc0` | respelled |
| `fallout_shared/bgsdecalmanager.cpp` | `?FUN_00ec8a19@@YAHPBD0H@Z` | `_strncmp` | `0x00ec8a19` | merged |
| `fallout_shared/gameplayformulas.cpp` | `?_floor@@YANM@Z` | `?floor@@YAMM@Z` | `0x00406cc0` | respelled |
| `fallout_shared/region system/tesregiondataweather.cpp` | `?_floor@@YANM@Z` | `?floor@@YAMM@Z` | `0x00406cc0` | respelled |
| `fallout_shared/tesobject.cpp` | `_FUN_00ec6130` | `_strlen` | `0x00ec6130` | merged |
| `fallout_shared/tesobject.cpp` | `?FUN_00ec44d0@errac6@fnv_00ac6430@@YAPAXPAXPBXI@Z` | `_memmove` | `0x00ec44d0` | respelled |
| `fallout_shared/tesobject.cpp` | `_FUN_00ec9a47` | `_fopen` | `0x00ec9a47` | respelled |
| `fallout_shared/tesobjectrefr.cpp` | `?FUN_00ec7750@fnv_00571760@@YAHPBD0@Z` | `_strstr` | `0x00ec7750` | respelled |
| `fallout_shared/tesobjectrefr.cpp` | `_FUN_00ec8a19` | `_strncmp` | `0x00ec8a19` | respelled |
| `fallout_shared/tesobjectrefr.cpp` | `?FUN_00ec623a@DialogueUpdate@@YAHPADPBDZZ` | `_sprintf` | `0x00ec623a` | merged |
| `fallout_shared/tesscriptfunctions.cpp` | `?floor@fnv_005bfe90@@YAMM@Z` | `?floor@@YAMM@Z` | `0x00406cc0` | respelled |
| `speedtree/speedtreert.cpp` | `?_strlen@@YAIPBD@Z` | `_strlen` | `0x00ec6130` | respelled |
| `staging/blk_004a0000_o2.cpp` | `?FUN_00406cc0@@YAMM@Z` | `?floor@@YAMM@Z` | `0x00406cc0` | respelled |
| `staging/blk_00880000_od.cpp` | `?FUN_00406cc0@@YAMM@Z` | `?floor@@YAMM@Z` | `0x00406cc0` | respelled |
| `staging/blk_009c0000_od.cpp` | `?FUN_00406cc0@ProjectileImpact@@YAMM@Z` | `?floor@@YAMM@Z` | `0x00406cc0` | respelled |
| `staging/blk_00ac0000_od.cpp` | `?uncaught_exception@std@fnv_00ad47f0@@YA_NXZ` | `?uncaught_exception@std@@YA_NXZ` | `0x00ec3241` | respelled |
| `staging/blk_00b80000_o2.cpp` | `_FUN_00ec61c0` | `_memset` | `0x00ec61c0` | merged |
| `staging/blk_00c80000_o2.cpp` | `?FUN_00ec61c0@fnv_00c828f0@@YAXPAXHI@Z` | `_memset` | `0x00ec61c0` | respelled |
| `staging/blk_00e80000_o2.cpp` | `_fnv_zlib_memset` | `_memset` | `0x00ec61c0` | respelled |
| `tesregiondatasound.cpp` | `?blendFloor@@YANM@Z` | `?floor@@YAMM@Z` | `0x00406cc0` | respelled |

## What was refused

12 stand-ins with 16 call sites were refused. Each is a real 64-bit or typing
question for VEGAS-12 and VEGAS-44, or needs a decision.

| address | function there | unit | stand-in | call sites | rule | why |
|---|---|---|---|---|---|---|
| `0x00406cc0` | float floor(float) | `fallout/ai/playercharacter.cpp` | `FUN_00406cc0 : void (float)` | 1 | result type | the stand-in returns nothing: the result was not recovered |
| `0x00406cc0` | float floor(float) | `fallout_shared/teswater.cpp` | `FUN_00406cc0 : float (float)` | 2 | other overload | the argument is written as `double`, the parameter is `float` |
| `0x00ec6130` | strlen | `fallout_shared/tesobject.cpp` | `FUN_00ec6130 : unsigned int (const void *)` | 1 | parameter type | parameter 1 is `const void *` |
| `0x00ec61c0` | memset | `havok/common/base/memory/util/hkmemutil.cpp` | `FUN_00ec61c0 : void ()` | 1 | argument count | the stand-in takes no arguments |
| `0x00ec61c0` | memset | `havok/common/serialize/packfile/binary/hkbinarypackfilewriter.cpp` | `FUN_00ec61c0 : void (void *, int, int)` | 1 | signed count | the size parameter is `int` and the argument is an `int` variable |
| `0x00ec6cde` | fabs | `speedtree/branch.cpp` | `FUN_00ec6cde : double (double)` | 2 | other overload | the argument is written as `float`, the parameter is `double` |
| `0x00ec7595` | _finite | `fallout_shared/tesobjectrefr.cpp` | `FUN_00ec7595 : int (double)` | 3 | other overload | the argument is written as `float`, the parameter is `double` |
| `0x00ec9907` | fclose | `fallout_shared/tesobject.cpp` | `FUN_00ec9907 : void (void *)` | 1 | parameter type | parameter 1 is `void *` |
| `0x00ec9907` | fclose | `fallout_shared/tesobject.cpp` | `_fclose : int (int)` | 1 | parameter type | parameter 1 is `int` |
| `0x00ec9a47` | fopen | `fallout_shared/tesobject.cpp` | `_fopen : int (const char *, const char *)` | 1 | result type | the stand-in returns `int` and the site keeps the handle in an `int` |
| `0x00ec9f30` | cos | `staging/blk_00b00000_od.cpp` | `FUN_00ec9f30 : double (double)` | 1 | other overload | the argument is written as `float`, the parameter is `double` |
| `0x00eca060` | sin | `staging/blk_00b00000_od.cpp` | `FUN_00eca060 : double (double)` | 1 | other overload | the argument is written as `float`, the parameter is `double` |

- **Signed count.** `hkbinarypackfilewriter.cpp` passes `int fill` as the
  size. The site guards it with `fill > 0`, but the rule does not read guards.
- **No arguments.** `hkmemutil.cpp` declares `void FUN_00ec61c0()`: the
  arguments were not recovered.
- **Handles held as integers.** `tesobject.cpp` keeps a `FILE*` in `int`
  (`_fopen`, `_fclose`) and in `void*` (`FUN_00ec9907`). The holder's type has
  to change first.
- **`float` arguments to `double` functions** (`fabs`, `_finite`, `cos`,
  `sin`): the standard name would select the `float` overload. For `fabs` and
  `isfinite` the result is the same real value or truth value; for `cos` and
  `sin` it is not. All four are left for one decision.
- **`double` argument to `float floor(float)`** in `teswater.cpp`: the
  original narrows first, and `std::floor` would not.

## What remains

After this change 203 of the 226 names are still undefined, at 49 addresses,
and the 38 old `std::` names are unchanged.

| class | undefined names left | why not here |
|---|---|---|
| a | 12 | the refusals above |
| b | 40 | secure and Microsoft-only functions. `fnv::crt` has project functions for most of them (the rows below say "exists"); the calls differ in parameter types and need the same per-site checks. `0x004564f0` and `0x0046fd30` are not in the runtime range and have no body |
| c | 54 | 40 names of `__RTDynamicCast` (157 calls that pass recovered type descriptors), 7 of `_ftol2_sse` (13 calls with no operand: it was on the x87 stack), 4 of the array destructor helper, 3 of `_CxxThrowException`. None is a plain source construct yet |
| d | 62 | the old string, stream, locale and exception internals and the checked-iterator failure call (`_invalid_parameter_noinfo`, 13 names, 152 calls). They go with the typed owners of VEGAS-73 and a native policy for the failure call |
| e | 35 | 24 of them name `0x00ec7c6b`, five bytes inside what is inferred to be `memcpy_s`; no recipe row binds that address |

Not measured:

- Stand-ins for runtime functions that carry an invented name and have no
  recipe row. They are outside the 226 names, so the ticket cannot be closed
  on that count alone. Example: `speedtree/treeengine.cpp` declares
  `errno_ptr()` and `error_text(int)` for a second copy of the error text
  mapped above; the names `fnv_00b2d2e0::errno_ptr` and
  `fnv_00b2d2e0::error_text` are still undefined and the frontier files them
  as unbound code. The same file declares `_errno` and `strerror` by hand near
  line 2959 for a third copy.
- Units that declare a standard function by hand instead of including its
  header, other than the one `sprintf` case found through the link. They call
  the standard function already.
- Three other units still declare the removed C name `FUN_00ec61c0` by hand
  and no object of theirs references it: `staging/blk_00e80000_o2.cpp`,
  `gamebryo2.2/corelibs/niconsolerenderer/niconsolerenderer.cpp` and
  `havok/common/serialize/copier/hkobjectcopier.cpp` (its one call is in an
  inline function that is never used). The declarations are left in place.

Windows execution of the changed units: NOT RUN. No production-entry test can
link: a test that calls `ComputeIntelligenceResult` from
`gameplayformulas.cpp`, the smallest changed function, needs 35,242 names
that no member defines. The proof is per object: in each of the 40
changed functions the relocation to the stand-in is replaced by the standard
symbol or by in-line code, and no other function changes.

## Every address

| address | class | function | evidence | recipe units | objects | undefined names | proposed treatment |
|---|---|---|---|---|---|---|---|
| `0x00406cc0` | a | float floor(float)  (<math.h> C++ overload, compiled into the game's own code range) | N: ?floor@@YAMM@Z in 7 units; S: float(float) | 20 | 12 | 9 | std::floor(float) **Mapped here: 9 stand-ins, 10 call sites mapped to std::floor.** Refused here: 3 call sites. |
| `0x004564f0` | b | _mbsnicmp-named function in the game's own code range | N only; no recipe function row | 12 | 12 | 9 | not in the runtime range: needs its body or an owner decision (fnv::crt::strnicmp if the multibyte code page is single-byte) |
| `0x0046fd30` | b | _mbsicmp-named function in the game's own code range | N only; no recipe function row | 3 | 3 | 1 | as 0x004564f0 (fnv::crt::stricmp) |
| `0x00ec3020` | x | NiTMapBase<...> constructor (template instance) | N | 1 | 0 | 0 | game code; folder ticket |
| `0x00ec30b0` | d | std::_String_base::_Xlen (throws length_error) | N: __Xlen, StrXlen | 4 | 1 | 3 | throw std::length_error at the site, with the VEGAS-73 string owner |
| `0x00ec30e8` | d | std::_String_base::_Xran (throws out_of_range) | N: StrXran | 4 | 3 | 5 | throw std::out_of_range at the site, with the VEGAS-73 string owner |
| `0x00ec31b3` | e | old C++ library internal, void(void*) | S only | 1 | 1 | 1 | identify with the stream owner (VEGAS-73 parser/stream units) |
| `0x00ec3205` | d | std::ios_base::_Ios_base_dtor(ios_base*) | N: member of ios_base in two units; S | 2 | 2 | 4 | disappears when the unit uses the standard stream class |
| `0x00ec3241` | a | std::uncaught_exception() | I: its caller is the destructor of an output-stream sentry, which tests it before the flush; L: 5 bytes to the next referenced address, the size of one jump; only one unit names it, and the name is that unit's own (inferred) | 1 | 1 | 1 | std::uncaught_exceptions() > 0 (uncaught_exception was removed in C++20) **Mapped here: 1 stand-ins, 1 call sites mapped to (std::uncaught_exceptions() > 0).** |
| `0x00ec3246` | e | old C++ library internal constructor | unit defines its own body | 1 | 1 | 0 | the unit holds a project body at a library address: owner decision |
| `0x00ec3260` | e | old C++ library internal, member void() | S only | 1 | 1 | 1 | identify with the locale/stream owner |
| `0x00ec3277` | e | old C++ library internal, member void() | S only | 1 | 1 | 1 | identify with the locale/stream owner |
| `0x00ec3280` | e | old C++ library internal, member void() | S only | 1 | 1 | 1 | identify with the locale/stream owner |
| `0x00ec3289` | d | std::_Init_locks::_Init_locks() | L: before _Lockit; S: constructor of a global object (inferred) | 1 | 1 | 1 | startup of the old library's locks: no native equivalent needed |
| `0x00ec32ba` | d | std::_Init_locks::~_Init_locks() | L, S (inferred) | 1 | 1 | 1 | as 0x00ec3289 |
| `0x00ec32e3` | d | std::_Lockit::_Lockit(int) | N: Lockit; S: constructor taking int | 1 | 2 | 6 | disappears when the unit uses the standard locale/stream |
| `0x00ec330b` | d | std::_Lockit::~_Lockit() | N: Lockit | 1 | 1 | 4 | as 0x00ec32e3 |
| `0x00ec33da` | d | std::_Fiopen(const char*, openmode, int) | S: File*(const char*, int, int) (inferred) | 1 | 1 | 1 | std::fopen with the mode string, or std::filebuf, with the stream owner |
| `0x00ec34d4` | e | old C++ library internal, char*() | S only | 1 | 1 | 1 | identify with the locale owner |
| `0x00ec3599` | d | std::locale::facet::_Facet_Register(facet*) | N: facet_Register | 1 | 1 | 1 | disappears with the standard locale |
| `0x00ec35d7` | e | old C++ library internal, void(void*) | S only | 1 | 2 | 2 | identify with the locale owner |
| `0x00ec36a6` | e | old C++ library internal, int() | S only | 1 | 1 | 1 | identify with the locale owner |
| `0x00ec3740` | d | std::_Locinfo::_Locinfo_ctor(_Locinfo*, const char*) | S (inferred) | 1 | 2 | 2 | disappears with the standard locale |
| `0x00ec379c` | d | _Tolower(int, const _Ctypevec*) | S: char(char, char*); L (inferred) | 1 | 1 | 1 | std::tolower with the locale owner |
| `0x00ec38a9` | d | _Getctype() | S: returns a 16-byte record; L between 0x00ec379c and 0x00ec3909 (inferred) | 1 | 1 | 1 | disappears with the standard locale |
| `0x00ec3909` | d | _Toupper(int, const _Ctypevec*) | S, L (inferred) | 1 | 1 | 1 | std::toupper with the locale owner |
| `0x00ec3a75` | e | old C++ library internal constructor (const char*, int, int) | S only | 1 | 1 | 1 | identify with the stream owner |
| `0x00ec3bad` | e | not identified, int(int) | S only; no x64 object references it | 3 | 0 | 0 | identify when a unit needs it |
| `0x00ec3bda` | e | not identified | no x64 object references it | 3 | 0 | 0 | identify when a unit needs it |
| `0x00ec3bf0` | e | not identified, __int64(__int64) | S only; no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ec3d33` | c | __CxxFrameHandler3 | N | 4 | 4 | 0 | compiler-emitted; four units still name it in hand-written tables: remove with their owners |
| `0x00ec408c` | c | __security_check_cookie | N | 432 | 386 | 0 | compiler-emitted (/GS); nothing to map |
| `0x00ec43fb` | c | __RTDynamicCast | N | 328 | 326 | 40 | dynamic_cast between real polymorphic classes; the stand-in calls pass recovered type descriptors, so each needs its typed owner (VEGAS-11) |
| `0x00ec44d0` | a | memmove or memcpy (the units use both names for it) | N conflicting: memmove and memcpy; S: (void*, const void*, unsigned) (inferred) | 90 | 33 | 1 | std::memmove is right for both **Mapped here: 1 stand-ins, 1 call sites mapped to std::memmove.** |
| `0x00ec4835` | a | memcmp | N | 61 | 10 | 0 | std::memcmp |
| `0x00ec5ec0` | c | _alloca_probe_16 / _alloca_probe | N | 125 | 0 | 0 | compiler-emitted; nothing to map |
| `0x00ec5fce` | c | eh vector destructor iterator (??_M) | N | 85 | 8 | 4 | array destruction of a real class; stand-in calls pass a member pointer: typed owner, or fnv::crt::vector_destructor |
| `0x00ec6040` | c | _CIsqrt | N | 85 | 0 | 0 | compiler intrinsic entry of sqrt; nothing to map |
| `0x00ec6054` | a | sqrt | N | 6 | 0 | 0 | std::sqrt |
| `0x00ec6130` | a | strlen | N | 55 | 31 | 3 | std::strlen **Mapped here: 2 stand-ins, 3 call sites mapped to std::strlen.** Refused here: 1 call sites. |
| `0x00ec61c0` | a | memset | N | 137 | 15 | 5 | std::memset **Mapped here: 4 stand-ins, 24 call sites mapped to std::memset ; 3 hand edits.** Refused here: 2 call sites. |
| `0x00ec623a` | a | sprintf | N | 47 | 27 | 1 | std::sprintf; the conversions used at a site decide whether the text is identical (three-digit exponents, see fnv::crt::gcvt) **Mapped here: 1 stand-ins, 1 call sites mapped to std::sprintf ; 3 hand edits.** |
| `0x00ec62c0` | c | _ftol2_sse | N | 204 | 9 | 7 | a cast to an integer type (truncation toward zero); the stand-in calls take no argument (the operand was on the x87 stack), so the operand must be recovered first |
| `0x00ec62f6` | c | _ftol2 | N | 7 | 0 | 0 | as 0x00ec62c0 |
| `0x00ec6370` | a | strcpy | N | 9 | 6 | 0 | std::strcpy |
| `0x00ec6380` | a | strcat | N | 5 | 1 | 0 | std::strcat |
| `0x00ec658f` | d | atexit | N | 50 | 38 | 0 | compiler-emitted registration of static destructors; shutdown order is VEGAS-79 |
| `0x00ec65a6` | b | strcpy_s | N | 57 | 10 | 2 | fnv::crt::strcpy_s (exists) |
| `0x00ec67aa` | a | tolower | N | 12 | 8 | 0 | std::tolower ("C" locale: the tree never calls setlocale) |
| `0x00ec68e4` | b | _stricmp | N | 13 | 0 | 0 | fnv::crt::stricmp (exists) |
| `0x00ec6940` | e | not identified, double(double) (candidate: floor) | S only; no x64 object references it | 6 | 0 | 0 | identify when a unit needs it |
| `0x00ec6bb5` | b | vsprintf_s | N | 3 | 0 | 0 | std::vsnprintf with the Microsoft error results, as a project function |
| `0x00ec6bd2` | b | strcat_s | N | 21 | 4 | 0 | fnv::crt::strcat_s (exists) |
| `0x00ec6cc4` | a | vsprintf | S: int(char*, const char*, va_list); L after vsprintf_s (inferred) | 3 | 0 | 0 | std::vsprintf |
| `0x00ec6cde` | a | fabs | N | 18 | 2 | 2 | std::fabs(double) **Mapped here: 1 stand-ins, 2 call sites mapped to std::fabs.** Refused here: 2 call sites. |
| `0x00ec6da0` | a | strcmp | N | 15 | 3 | 0 | std::strcmp |
| `0x00ec6e30` | a | strrchr | N | 19 | 13 | 0 | std::strrchr |
| `0x00ec6f20` | a | qsort | N | 9 | 1 | 0 | std::qsort |
| `0x00ec716d` | a | bsearch | N | 2 | 1 | 0 | std::bsearch |
| `0x00ec7230` | a | memcpy | S: (void*, const void*, unsigned); distinct from 0x00ec44d0 (inferred) | 22 | 0 | 0 | std::memcpy |
| `0x00ec7595` | a | _finite | N: FNV_Finite; L before _isnan | 11 | 2 | 1 | std::isfinite Refused here: 3 call sites. |
| `0x00ec75b1` | a | _isnan | N: FNV_IsNaN | 10 | 0 | 0 | std::isnan |
| `0x00ec7690` | a | strchr | N | 12 | 5 | 0 | std::strchr |
| `0x00ec7750` | a | strstr | N | 25 | 12 | 1 | std::strstr **Mapped here: 1 stand-ins, 1 call sites mapped to std::strstr.** |
| `0x00ec77e0` | c | _allshr | N | 4 | 0 | 0 | 64-bit shift helper of the 32-bit compiler; nothing to map |
| `0x00ec7810` | c | _allshl | N | 10 | 0 | 0 | as 0x00ec77e0 |
| `0x00ec782f` | c | eh vector constructor iterator (??_L) | N | 91 | 0 | 0 | array construction of a real class; typed owner, or fnv::crt::vector_constructor |
| `0x00ec7894` | c | _CxxThrowException | N | 21 | 20 | 3 | a throw expression of a real exception type; the stand-in calls pass an object and a recovered ThrowInfo: typed owner |
| `0x00ec78e0` | d | std::exception::exception() | N | 4 | 3 | 2 | the VEGAS-73 exception base (native_string.cpp) or std::exception, per owner |
| `0x00ec78f1` | d | std::exception::exception(const char* const&) | N | 8 | 5 | 5 | as 0x00ec78e0 |
| `0x00ec7944` | d | std::exception::exception(const exception&) | N | 2 | 2 | 4 | as 0x00ec78e0 |
| `0x00ec79a1` | d | std::exception::~exception() | N | 4 | 4 | 6 | as 0x00ec78e0 |
| `0x00ec79c4` | d | std::bad_cast::bad_cast(const char*) | N | 1 | 1 | 1 | std::bad_cast (the standard one takes no text) with the locale owner |
| `0x00ec7c56` | d | _invalid_parameter_noinfo | N | 23 | 9 | 13 | the checked-iterator failure path of the old C++ library: native policy needed (terminate, as the original does without a handler) |
| `0x00ec7c66` | b | memcpy_s | S: int(void*, unsigned, const void*, unsigned); L: 16 bytes after _invalid_parameter_noinfo, before memmove_s (inferred) | 4 | 7 | 21 | fnv::crt::memcpy_s (exists) |
| `0x00ec7c6b` | e | inside memcpy_s (five bytes after its entry); no recipe row binds it | address only in symbol names (inferred) | 0 | 6 | 24 | bind the callers to 0x00ec7c66 in the recipe first, then fnv::crt::memcpy_s |
| `0x00ec7ce3` | b | memmove_s | N | 11 | 5 | 6 | fnv::crt::memmove_s (exists) |
| `0x00ec7d40` | a | abs | N | 20 | 1 | 1 | std::abs(int) **Mapped here: 1 stand-ins, 11 call sites mapped to std::abs.** |
| `0x00ec7d50` | a | clock | N: BatchClock; S: int() (inferred) | 1 | 0 | 0 | std::clock |
| `0x00ec7ec0` | b | _strnicmp | N | 27 | 0 | 0 | fnv::crt::strnicmp (exists) |
| `0x00ec7f1e` | b | _splitpath_s | N | 6 | 0 | 0 | fnv::crt::splitpath_s (exists) |
| `0x00ec8244` | e | not identified, int(void*, void*) | S only; no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ec825b` | b | _makepath_s | N | 4 | 0 | 0 | fnv::crt::makepath_s (exists) |
| `0x00ec858a` | e | case-insensitive string compare (named StrCmp and Stricmp by two units) | N conflicting; no x64 object references it | 2 | 0 | 0 | identify when a unit needs it |
| `0x00ec85e3` | a | _errno | S: int*(); I: *f() passed to the function at 0x00ecdb42 (inferred) | 3 | 1 | 1 | errno **Mapped here: 1 stand-ins, 1 call sites mapped to errno.** |
| `0x00ec862c` | e | not identified, int(const char*, const char*) | S only; no x64 object references it | 3 | 0 | 0 | identify when a unit needs it |
| `0x00ec8660` | c | _chkstk | N | 38 | 38 | 0 | compiler-emitted; nothing to map |
| `0x00ec86e1` | a | isalpha | N | 3 | 1 | 0 | std::isalpha ("C" locale) |
| `0x00ec8860` | a | isdigit | N | 1 | 0 | 0 | std::isdigit |
| `0x00ec8965` | e | character classification, int(int) | S; L between isdigit and isalnum (inferred); no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ec89e9` | a | isalnum | N | 1 | 1 | 0 | std::isalnum ("C" locale) |
| `0x00ec8a19` | a | strncmp | N | 11 | 3 | 2 | std::strncmp **Mapped here: 2 stand-ins, 3 call sites mapped to std::strncmp.** |
| `0x00ec8d08` | a | strtol | N | 3 | 1 | 0 | std::strtol |
| `0x00ec8d33` | e | not identified, void(int, int, int) | S only; no x64 object references it | 2 | 0 | 0 | identify when a unit needs it |
| `0x00ec8d5f` | b | strncpy_s | N | 12 | 2 | 0 | fnv::crt::strncpy_s (exists) |
| `0x00ec8feb` | b | _strlwr_s | N | 2 | 0 | 0 | fnv::crt::strlwr_s (exists) |
| `0x00ec9010` | a | atan | N | 2 | 1 | 0 | std::atan |
| `0x00ec9050` | c | _CIatan | N | 4 | 0 | 0 | compiler intrinsic entry; nothing to map |
| `0x00ec9130` | a | fmod | N | 3 | 1 | 0 | std::fmod |
| `0x00ec913a` | c | _CIfmod | N | 6 | 0 | 0 | compiler intrinsic entry; nothing to map |
| `0x00ec923c` | b | _stat | S: int(const char*, stat record*) | 2 | 0 | 0 | fnv::crt::stat (exists) |
| `0x00ec9610` | a | asin | S: double(double); L: 0x40 before _CIasin, as atan, cos, sin, pow before theirs (inferred) | 2 | 0 | 0 | std::asin |
| `0x00ec9650` | c | _CIasin | N | 3 | 0 | 0 | compiler intrinsic entry; nothing to map |
| `0x00ec9760` | a | atan2 | N | 4 | 4 | 0 | std::atan2 |
| `0x00ec9774` | a | fprintf | S: int(FILE*, const char*, ...) (inferred); no x64 object references it | 1 | 0 | 0 | std::fprintf |
| `0x00ec9907` | a | fclose | N | 9 | 5 | 2 | std::fclose Refused here: 2 call sites. |
| `0x00ec9a47` | a | fopen | N | 7 | 5 | 2 | std::fopen **Mapped here: 1 stand-ins, 1 call sites mapped to std::fopen.** Refused here: 1 call sites. |
| `0x00ec9a5e` | b | fopen_s | N | 3 | 0 | 0 | fnv::crt::fopen_s (exists) |
| `0x00ec9ac0` | a | pow | N | 5 | 2 | 0 | std::pow |
| `0x00ec9b00` | c | _CIpow | N | 9 | 0 | 0 | compiler intrinsic entry; nothing to map |
| `0x00ec9d4a` | a | printf | S: int(const char*, ...) (inferred); no x64 object references it | 1 | 0 | 0 | std::printf |
| `0x00ec9e10` | a | ceil | N | 8 | 0 | 0 | std::ceil |
| `0x00ec9f30` | a | cos | N | 7 | 2 | 1 | std::cos(double) Refused here: 1 call sites. |
| `0x00ec9f70` | c | _CIcos | N | 17 | 0 | 0 | compiler intrinsic entry; nothing to map |
| `0x00eca060` | a | sin | N | 6 | 2 | 1 | std::sin(double) Refused here: 1 call sites. |
| `0x00eca0a0` | c | _CIsin | N | 16 | 0 | 0 | compiler intrinsic entry; nothing to map |
| `0x00eca190` | a | acos | S: double(double); L: 0x40 before _CIacos (inferred) | 1 | 0 | 0 | std::acos |
| `0x00eca1d0` | c | _CIacos | N | 9 | 0 | 0 | compiler intrinsic entry; nothing to map |
| `0x00eca2e0` | e | not identified | no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00eca38d` | b | sprintf_s | S: int(char*, unsigned, const char*, ...) (inferred); no x64 object references it | 2 | 0 | 0 | std::snprintf with the Microsoft error results, as a project function |
| `0x00eca4a6` | a | sscanf | N | 6 | 3 | 0 | std::sscanf |
| `0x00eca573` | a | atof | N | 9 | 6 | 0 | std::atof ("C" locale) |
| `0x00eca590` | a | tan | N | 2 | 0 | 0 | std::tan |
| `0x00eca5d0` | c | _CItan | N | 2 | 0 | 0 | compiler intrinsic entry; nothing to map |
| `0x00eca6bd` | a | atol | N | 2 | 2 | 0 | std::atol |
| `0x00eca6d3` | a | atoi | S: int/long(const char*); L after atol; one unit already calls atoi | 14 | 1 | 0 | std::atoi |
| `0x00eca7f4` | a | toupper | N | 8 | 6 | 0 | std::toupper ("C" locale) |
| `0x00eca903` | e | not identified | no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00eca920` | e | not identified, double(double) | S only; no x64 object references it | 2 | 0 | 0 | identify when a unit needs it |
| `0x00ecacb2` | e | not identified, char*(char*, const char*, unsigned) (candidate: strncat) | S only; no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ecad86` | b | wcstombs_s | S: int(size_t*, char*, size_t, const wchar_t*, size_t) (inferred) | 1 | 1 | 1 | fnv::crt::wcstombs_s (exists) |
| `0x00ecada6` | b | srand | N | 4 | 2 | 0 | std::srand; the sequence is implementation-defined: equal on the Microsoft runtime, a project generator if it must be equal elsewhere |
| `0x00ecadb8` | b | rand | N | 30 | 16 | 0 | as 0x00ecada6 |
| `0x00ecadda` | b | _time64 | N | 6 | 2 | 0 | std::time (64-bit time_t on windows-x64) |
| `0x00ecae30` | a | exp | N | 2 | 0 | 0 | std::exp |
| `0x00ecae6c` | c | _CIexp | N | 4 | 0 | 0 | compiler intrinsic entry; nothing to map |
| `0x00ecaebb` | c | eh vector copy constructor iterator | S: (void*, void*, size, count, copy, destroy) (inferred); no x64 object references it | 1 | 0 | 0 | fnv::crt::vector_copy_constructor or a typed owner |
| `0x00ecb086` | a | fwrite | N | 5 | 4 | 0 | std::fwrite |
| `0x00ecb3a8` | a | fread | N | 4 | 4 | 0 | std::fread |
| `0x00ecb562` | b | ftell | N | 4 | 0 | 0 | fnv::crt::ftell (exists; 64-bit offsets) |
| `0x00ecb65a` | b | fseek | N | 8 | 2 | 0 | fnv::crt::fseek (exists; 64-bit offsets) |
| `0x00ecb849` | e | not identified | no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ecba8e` | e | not identified, void(int, int, int) | S only; no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ecbc5b` | e | not identified, int(char*, unsigned) (candidates: _strupr_s, _strlwr_s); the caller is named LowerY | S only | 2 | 1 | 1 | identify from the archive name comparison it feeds, then a fnv::crt function |
| `0x00ecbc80` | e | not identified, double(double) | S only; no x64 object references it | 2 | 0 | 0 | identify when a unit needs it |
| `0x00ecbe60` | e | not identified, void(const char*, char*) | S only; no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ecbf05` | b | _access | N | 8 | 0 | 0 | fnv::crt::access (exists) |
| `0x00ecbf20` | a | strpbrk | N | 3 | 1 | 0 | std::strpbrk |
| `0x00ecc071` | e | not identified, int(...) | S only; no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ecc104` | a | fgets | N | 2 | 1 | 0 | std::fgets |
| `0x00ecc250` | c | _alldiv | N | 3 | 0 | 0 | 64-bit division helper of the 32-bit compiler; nothing to map |
| `0x00ecc300` | c | _allmul | N | 5 | 0 | 0 | 64-bit multiplication helper of the 32-bit compiler; nothing to map |
| `0x00ecc5f8` | b | strtok_s | N | 5 | 1 | 0 | fnv::crt::strtok_s (exists) |
| `0x00ecc6e6` | a | strtok | N | 1 | 1 | 0 | std::strtok |
| `0x00ecc7b0` | a | strncpy | N | 4 | 1 | 0 | std::strncpy |
| `0x00ecc8e0` | c | _except_handler4 | N | 2 | 0 | 0 | structured-exception handler of the 32-bit compiler; nothing to map |
| `0x00eccbdc` | e | not identified | no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00eccec5` | d | exit | N | 2 | 1 | 0 | std::exit; shutdown order is VEGAS-79 |
| `0x00eccf5d` | d | realloc | N | 2 | 0 | 0 | heap: the engine allocator decides (VEGAS-79, docs/native-engine-heaps.md) |
| `0x00ecd1c7` | d | malloc | N | 1 | 0 | 0 | as 0x00eccf5d |
| `0x00ecd291` | d | free | N | 2 | 1 | 0 | as 0x00eccf5d |
| `0x00ecd31f` | d | _msize | N | 1 | 0 | 0 | no standard equivalent: the owner must carry the size (VEGAS-79) |
| `0x00ecd3c2` | a | fputc | N | 1 | 1 | 0 | std::fputc |
| `0x00ecd5bf` | a | ungetc | N | 1 | 1 | 0 | std::ungetc |
| `0x00ecd631` | a | fgetc | N | 1 | 1 | 0 | std::fgetc |
| `0x00ecd735` | e | not identified | no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ecd7a3` | e | not identified | no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ecd7e8` | e | not identified, int(int, int, int, int) | S only; no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ecda70` | e | stdio function taking a FILE* (candidate: fflush) | S only; no x64 object references it | 3 | 0 | 0 | identify when a unit needs it |
| `0x00ecdacc` | a | feof | N | 1 | 1 | 0 | std::feof |
| `0x00ecdb00` | a | wcslen | N | 3 | 1 | 0 | std::wcslen |
| `0x00ecdb42` | a | strerror | S: char*(int); I: called with *errno inside a bracketed error text (inferred) | 1 | 1 | 1 | std::strerror **Mapped here: 1 stand-ins, 1 call sites mapped to std::strerror.** |
| `0x00ecdd16` | b | _gcvt | N | 3 | 2 | 0 | fnv::crt::gcvt (exists) |
| `0x00ecddf1` | e | not identified, void(intptr, int, intptr, intptr) | S only | 2 | 1 | 1 | identify with the Havok string unit that forwards to it |
| `0x00ecdf2d` | a | strtod | S: double(const char*, char**) (inferred); no x64 object references it | 2 | 0 | 0 | std::strtod |
| `0x00ecdf44` | e | not identified, void*() | S only; no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ece104` | c | _except_handler3 | N | 1 | 0 | 0 | structured-exception handler of the 32-bit compiler; nothing to map |
| `0x00ece23e` | e | string tokenizer (named MovieStrtok) | N from one unit; no x64 object references it | 1 | 0 | 0 | identify when a unit needs it |
| `0x00ee6d44` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d4a` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d50` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d56` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d5c` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d62` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d68` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d6e` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d74` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d7a` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d80` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
| `0x00ee6d9e` | x | import thunk (jump through an import-table slot) | six-byte spacing; names of imported functions | 1 | 0 | 0 | not this ticket (VEGAS-12/24/29) |
