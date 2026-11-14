# One shared declaration of BSStringT

VEGAS-17 owns the `bscore` units. `BSStringT<T>` is the engine's string
holder: one character buffer with a 16-bit length and a 16-bit capacity. This
change gives the template one declaration that units share, moves 545 units
onto it, and removes a second, identical definition of the destructor. It
follows `docs/shared-simple-list.md`. It is a first increment, reviewed on
feb18080b and integrated on 21f1f1953, where the builds, link cells,
object comparisons, checks and remainder were measured again with the same
results; only the tip's own counts differ there: 35,224 undefined names,
2,303 objects, 2,321 build steps and 20,788 warning lines. Every figure
here was measured again on 2277431b8, whose files outside `docs/` are the
same as f0ed64652's. No
undefined name leaves with it: every member that has a
function row under the template's name was already emitted. "Defects
recorded for the next step", "Rulings" and "Open" say what comes next.

## Where the declaration lives

`include/fnv/bs_string.h`, beside `include/fnv/bs_simple_list.h`.

## What the recipe says

Fifteen addresses of `build/units.json` are members of the string holder.
The last column counts the recipe entries with a row in their `symbols`
table at the address, under any name. The recipe has 2,781 entries for 2,070
source files, so a file can count more than once.

| Address | Member | Recipe size | Unit with the function row | Name of the function row | Recipe entries with a symbol row |
| --- | --- | --- | --- | --- | --- |
| `0x004037b0` | `BSStringT()` | 22 | `bscore/bsstring.cpp` | the template's | 114 |
| `0x004037d0` | `~BSStringT()` | 23 | `fallout_shared/tesobjectacti.cpp` | `BSStringTChar::~BSStringTChar` | 120 |
| `0x004037f0` | `bool Set(const T*, unsigned int)` | 322 | `bscore/bsstring.cpp` | the template's | 86 |
| `0x00403970` | `void Init()` | 40 | `bscore/bsstring.cpp` | the template's | 2 |
| `0x004039a0` | `unsigned int MaxLength()` | 18 | `bscore/bsstring.cpp` | the template's | 4 |
| `0x004039c0` | `void SetLength(unsigned int)` | 51 | `bscore/bsstring.cpp` | the template's | 5 |
| `0x00403a00` | `void SetMaxLength(unsigned int)` | 51 | `bscore/bsstring.cpp` | `FUN_00403a00_class::FUN_00403a00` | 2 |
| `0x00438390` | `BSStringT& operator=(const T*)` | 30 | `bscore/bsstring.cpp` | the template's | 24 |
| `0x00438470` | `bool Set(const BSStringT&)` | 256 | `fallout_shared/extradataobjects.cpp` | the template's | 11 |
| `0x0040c0e0` | `BSStringT(const T*)` | 38 | `fallout_shared/magic/magicitem.cpp` | free function `FUN_0040c0e0` | 20 |
| `0x004047f0` | `BSStringT(const BSStringT&)` | 43 | `fallout_shared/magic/magicitem.cpp` | free function `AssignFromString` | 14 |
| `0x00404820` | `BSStringT& operator+=(const T*)` | 189 | `fallout/interface/menus/statsmenu.cpp` | free function `fnv_00404820::FUN_00404820` | 14 |
| `0x004048e0` | `unsigned int GetLength() const` | 60 | `fallout_shared/extradataobjects.cpp` | `FUN_004048e0_cls::FUN_004048e0` | 47 |
| `0x00406f60` | `int PrintfString(const char*, ...)` | 45 | `fallout/interface/interface.cpp` | free function `FUN_00406f60` | 57 |
| `0x00559450` | `const T* String()`, `operator const T*() const` | 16 | `fallout_shared/modelloader.cpp` | free function `FUN_00559450(int*)` | 367 |

Every member has a function row, with a size. So the original called each of
them out of line, and no member is given a body in the header.

The member names of the last six rows come from symbol rows that bind the
template's own name to the address. `0x00559450` is a folded body, two
instructions that return the first pointer of the object. Many classes that
are not strings reach it.

## What the header declares

The three fields, the seven members that the recipe gives to
`src/bscore/bsstring.cpp`, and the destructor, with that unit's signatures.
Nothing else, and no body.

`0x00403a00` is declared although its function row has a stand-in name:
`bsstring.cpp` defines `SetMaxLength` with that address. `bssimplelist_h_unit.cpp`
does the same for two list members.

Not declared:

- `Set(const BSStringT&)`. Its owner, `extradataobjects.cpp`, defines it on a
  private copy of the template and cannot move yet. No other object requires
  the name.
- The six members whose function row has a stand-in name. No object defines
  them under the template's name.

Ruling 2 says when each of them joins the header.

## Layout

The compiler measures `BSStringT<char>` in each of the 545 units on the
header, with the unit's own command line: 16 bytes, alignment 8, `pString` at
offset 0, `sLen` at 8, `sMaxLen` at 10.

## Who emits each member

| Member | Emitted by | How |
| --- | --- | --- |
| The seven members of `bsstring.cpp` | `bsstring.cpp` | Template member definitions and one member-level explicit instantiation each, for `char`. As before this change. The compiler always emits these. |
| `~BSStringT()` | `tesobjectacti.cpp` | An explicit specialisation for `char`, on that unit's private copy of the template. See below. |
| `Set(const BSStringT&)` | `extradataobjects.cpp` | An explicit specialisation for `char`, on that unit's private copy. |

The destructor now has one definition, and it is fragile.
`tesobjectacti.cpp` does not use the shared header. Its private copy of the
template, at `src/fallout_shared/tesobjectacti_layout.h:23`, gives the
destructor a body in the class, and the unit then specialises the destructor
for `char`. The compiler treats that specialisation as an inline function.
The definition comes out select-any, and the compiler emits it only while
the unit itself has a use of it that is not expanded in line. Today the
object has 9 call relocations to it, so it is emitted. 78 objects require
the name. If those 9 uses were expanded in line or removed, the definition
would leave the archive without any error from the compiler.

Check (b) guards this: it passes only when the destructor has exactly one
definition, in `tesobjectacti.cpp.obj`. Moving `tesobjectacti.cpp` onto the
shared header is an early item of the next step. There the destructor
becomes a template member with a member-level explicit instantiation, as in
`bsstring.cpp`, which the compiler cannot discard.

`char` is the only character type whose members any object requires.
`BSStringT<wchar_t>` occurs in two symbols, as a parameter type of
`BSFile::Read` and `BSFile::Write`. No member of it is required, so nothing
is emitted for it.

Nine names of the template are defined in the archive, each once. Six are
required by another object: the default constructor by 65 objects, the
destructor by 78, `operator=` by 9, `SetLength` by 3, and `Set` and
`MaxLength` by 1 each.

## Allocation

`Set(const T*, unsigned int)` takes the buffer with `new T[capacity + 1]` and
releases it with `delete[]`. In the windows-x64 object these are calls of
`operator new[](size_t)` and `operator delete[](void*)`, the replaced global
functions of `src/runtime/new.cpp`, which use the manager of
`docs/native-engine-heaps.md`. The destructor and `operator=` do not call
`Set`. They call the stand-in `TextString::FUN_004037f0`; see "Defects
recorded for the next step".

Other bodies bound to the same addresses allocate as follows. None was
unified with the owner's.

| Address | Body | Unit | Takes | Releases |
| --- | --- | --- | --- | --- |
| `0x004037f0` | `BSStringT<char>::Set(const char*, unsigned int)` | `bsstring.cpp`, function row | `new[]` | `delete[]` |
| `0x004037f0` | `TextString::FUN_004037f0` | `bsmenu/debugtext.cpp`, body in the class | `new[]` | `delete[]` |
| `0x00438470` | `BSStringT<char>::Set(const BSStringT&)` | `extradataobjects.cpp`, function row | `new[]` | `delete[]` |
| `0x00438470` | `fnv_00a0a410::ParsedText::FUN_00438470` | `bsmenu/tile.cpp`, body in the class | `new[]` | `delete[]` |
| `0x00438470` | `fnv_00a17390::LayoutString::Set` | `bsmenu/font.cpp`, body in the class | `new[]` | `delete`, the sized scalar form |
| `0x004037f0` | `BSStringT<char>::Set`, inline specialisation | `bsmenu/tile.cpp`, not emitted | `FUN_00401000` | `FUN_00401030` |

All of these end at the same two entries of the manager: every form of
`operator new` in `src/runtime/new.cpp` calls `FUN_00401000` and every form
of `operator delete` calls `FUN_00401030`. The spellings still differ.
`LayoutString::Set` in `font.cpp` releases an array with scalar `delete`,
and the specialisation in `tile.cpp` calls the manager's entries directly,
without the size check of `operator new`. No such body may replace the
owner's or be replaced by it without a comparison of its own.

## The rule for moving a unit

A unit's own copy of the template is replaced by
`#include "fnv/bs_string.h"` when both hold:

1. The compiler, in that unit, shows the copy to be compatible: three public
   fields `T* pString; unsigned short sLen; unsigned short sMaxLen;` in that
   order, no base class, no member with a body in the class, none virtual or
   static.
2. After the replacement the unit compiles, and its object is byte-identical
   to the object before, with only the COFF timestamp masked.

Condition 1 does not compare the special members. Three of the 34 replaced
copies declared no constructor and no destructor:
`src/bsmenu/font_types.h:17`, `src/bsmenu/menu.cpp:120` and
`src/bsmenu/tileimage_private.h:84`. In their units, `font.cpp`, `menu.cpp`
and `tileimage.cpp`, the string was a trivial class before and is a class
with a declared constructor and destructor now. The three objects are
byte-identical all the same, so condition 2 holds. The other 31 copies
declared both. Condition 2 is what catches a unit where the difference
matters.

A unit that uses a member the header lacks stops compiling and stays on its
copy. No header shared by several units needed a keep macro in this step.

## Integration checks

Run these three on every change that touches the header, a copy of the
template, or a unit that emits a member. They were run on the windows-x64
archive of the last code commit.

(a) Layout per requirer. Take every name of the global template that an
owning object defines and another object requires. For each requiring unit,
the compiler must measure that `BSStringT<...>` in the unit as 16 bytes with
fields at offsets 0, 8 and 10. Result: 84 pairs of unit and string in 84
units; 82 pass. The two that do not are older than this change:

- `src/bsmenu/tile3d_h_unit.cpp`: its copy at `src/bsmenu/tile3d_decls.h:18`
  is `char data[8]`, 8 bytes. The unit requires the default constructor and
  the destructor.
- `src/fallout_shared/bgsquestobjective.cpp`: its copy at
  `src/fallout_shared/bgsquestobjective_decls.h:19` is `char storage[8]`,
  8 bytes. The unit requires `operator=`.

The owner's bodies write 16 bytes. A new exception fails the check.

(b) Definitions. No name of the global template may have two definitions.
The destructor must have exactly one, in `tesobjectacti.cpp.obj`. The count
of names with differing definitions in the whole archive may not rise.
Result: 9 defined names, 0 with two definitions; the destructor has one, in
`tesobjectacti.cpp.obj`, select-any, 68 bytes; 525 names with differing
definitions before and after, none entering.

(c) Class-key and character type. Every use of the global template as a type
in a symbol of the archive must have the key `class` and the argument
`char`. Result: 114 uses as a type, all `class`; 112 with `char` and the two
with `wchar_t` named above.

The count of (c) is of occurrences. A symbol counts once in every object
that defines or requires it, and once more for each further place the
template has in its name. The 114 occurrences are 44 distinct symbols.

Check (c) reads symbols only, so it does not see a declaration. A mangled
name carries the class-key only where the template is a parameter or return
type. The name of a member, a constructor or a destructor carries none.
Seven units declare the global template with the key `struct` and pass:

- `src/fallout/interface/menus/bookmenu.cpp:1089` and
  `src/fallout_shared/sky/stars.cpp:413` declare a pointer and two 16-bit
  fields under other names. Their objects require the default constructor
  and the destructor, and `bookmenu.cpp` also requires `BSStringT(const T*)`.
- `src/fallout_shared/facegen/bsfacegenmanager.cpp:367`,
  `src/fallout_shared/pathfinding/navmeshpovsearch.cpp:236`,
  `src/fallout_shared/tesland.cpp:293`,
  `src/fallout_shared/tesobjectrefr.cpp:3809` and
  `src/fallout_shared/teswater.cpp:472` declare no fields. Their objects
  require `operator const char*`.

None of the eleven symbols carries a key. A key mismatch in these units
would show only when one of them names the string in a signature. The
compiler's view of the declarations, not check (c), is what lists them.

The three checks of `docs/shared-simple-list.md` were run on the same
archive and give the figures recorded there for step 2: 236 pairs with the
same two exceptions, 1,356 defined names with none defined twice, and 139
forward declarations with no key mismatch.

## What was measured

At 2277431b8 the compiler sees 72 declarations of the global template with a
body, in 584 of the 2,223 units of the windows-x64 archive. By fields and
member signatures they fall into 43 classes.

| Group | Declarations | Units | Moved |
| --- | --- | --- | --- |
| The shared fields, members declared only | 39 | 550 | 34 declarations, 545 units |
| A pointer and two 16-bit fields under other names, 16 bytes | 14 | 14 | none |
| No fields, 1 byte | 12 | 12 | none |
| Eight bytes of storage, the 32-bit size | 4 | 5 | none |
| The shared fields with bodies in the class | 2 | 2 | none |
| A pointer and one 32-bit length, 16 bytes | 1 | 1 | none |

`include/layout_support.h` carries 413 of the units and
`src/fallout_shared/layout_support.h` 96. Counting every class whose name
contains `BSString`, the compiler sees 166 declarations with a body, in 91
classes; 43 of them are copies of the template inside a namespace
`fnv_<address>`.

Forced link of every archive member, windows-x64, 2,223 members in the same
order:

| | 2277431b8 | Header and units | Second destructor removed |
| --- | --- | --- | --- |
| Undefined names | 35,224 | 35,224 | 35,224 |
| Left / entered | | 0 / 0 | 0 / 0 |
| Duplicate symbols | 0 | 0 | 0 |
| Imports | 137 | the same | the same |
| Objects that differ from the column before, of 2,299 | | 0 | 1 |
| Names with differing definitions in the archive | 525 | 525 | 525 |

Every build has 2,317 steps, none failed, and 20,786 warning lines that are
equal once line and column are removed. `build/units.json` and
`src/generated` are untouched.

## The second definition of the destructor

One function, one definition (VEGAS-17). `BSStringT<char>::~BSStringT()` had
two definitions in the archive, in `bsstring.cpp.obj` and in
`tesobjectacti.cpp.obj`. They were the same definition twice: one mangled
name, both select-any, 68 bytes, the same content and the same relocation.
So the name was never among the names with differing definitions, and that
count is 525 before and after.

The recipe has one function row at `0x004037d0`. It is in
`tesobjectacti.cpp`, under the stand-in name
`BSStringTChar::~BSStringTChar`. `bsstring.cpp` has no row there; it carried
an address comment and a body with the same tokens. Where a recipe row and
an address comment in the source disagree, the row decides. That is ruling 1.

The copy in `bsstring.cpp` and its explicit instantiation are removed. In
that unit's object the definition and its cleanup block leave, and each of
the other 15 functions has the same instructions and relocations.
`tesobjectacti.cpp.obj` is byte-identical. The first line of `bsstring.cpp`
now counts the 14 functions the file defines; one of the 15 in the object
is a cleanup block of another function.

## Units that did not move

- Five copies have the shared fields and stay, because their unit uses a
  member the header lacks:

  | Copy | Unit | Uses |
  | --- | --- | --- |
  | `src/fallout/dialogue/menutopic_layout.h:311` | `menutopic.cpp` | `FUN_00438470`, a placeholder name for `Set(const BSStringT&)` |
  | `src/fallout/interface/menuconsole_support.h:311` | `menuconsole.cpp` | `BSStringT(const T*)` |
  | `src/fallout_shared/extradataobjects_private_layout_support.h:23` | `extradataobjects.cpp` | defines `Set(const BSStringT&)`; calls `GetLength` and `GetMaxLength` |
  | `src/fallout_shared/sky/clouds_decls.h:48` | `clouds.cpp` | `operator const T*`, `operator+=` |
  | `src/fallout_shared/tesscriptfunctions_layout_support.h:310` | `tesscriptfunctions.cpp` | `PrintfString` |

- 33 copies differ, as in the table above. The two with bodies in the class
  are `src/bsmenu/debugtext.cpp:2398`, which defines `Set`, `Clear` and the
  destructor, and `src/fallout_shared/tesobjectacti_layout.h:23`, whose
  destructor body is empty. For `char` that unit specialises the destructor,
  so the empty body is never used for it.
- Classes that are not the global template were not touched.
- Ten more copies of the global template exist as text that the compiler
  sees in no unit. They are not in the counts above, which are the
  compiler's. Nothing checks them, and each would become a live copy if a
  unit began to compile it.

  | Copy | Fields | Why no unit compiles it |
  | --- | --- | --- |
  | `include/layout_support_decl_blk_00820000_od.h:345` | the shared fields | `staging/blk_00820000_od.cpp` opens the file after `FNV_LAYOUT_SUPPORT_H` is defined, so its include guard skips it |
  | `include/layout_support_decl_combatgoal.h:346` | the shared fields | the same, in `fallout/ai/combat/combatgoal.cpp` |
  | `src/bsmenu/tileimage_private_decl_tileimage.h:83` | the shared fields | the same, in `bsmenu/tileimage.cpp`, with the guard `FNV_TILEIMAGE_PRIVATE_H` |
  | `include/layout_support_rtti2_bgssaveloadgame.h:342` | the shared fields | no unit opens the file |
  | `src/effectsetting.h:15` | the shared fields | no unit opens the file |
  | `src/fallout_shared/tesconditionfunctions_conditionfn_dep_layout_support_decl_tesconditionfunctions.h:326` | the shared fields | no unit opens the file |
  | `src/fallout_shared/bipedanim_decls_decl_bipedanim.h:205` | a pointer and two 16-bit fields under other names | no unit opens the file |
  | `src/fallout_shared/tesworldspace_packet_rtti2_tesworldspace.h:45` | none | no unit opens the file |
  | `src/fallout_shared/tesworldspace_packet_rtti_variant.h:57` | none | no unit opens the file |
  | `src/fallout_shared/tesworldspace_packet_rtti_variant_decl_tesworldspace_rtti_variant.h:98` | none | no unit opens the file |

## Second bodies and private specialisations in other units

A unit that specialises a member, or the class, for `char` has a private
copy for the one type the owners emit. Nothing reports a disagreement.

`src/bsmenu/tile.cpp` is on the shared header and defines four inline
specialisations for `char`, at lines 6168 to 6185: `SetLength`,
`SetMaxLength`, the default constructor and `Set(const char*, unsigned int)`.
Each has a function row in `bsstring.cpp`. The recipe of `tile.cpp` has a
symbol row for `Set` at `0x004037f0` and none for the other three.

- The object of `tile.cpp` defines none of the four names, so check (b)
  passes. An inline definition is emitted when a use is not expanded in
  line. Check (b) is the only detector for a second definition of these
  four names.
- The specialised constructor and the specialised `Set` store the capacity
  through `FUN_00403a00_class::FUN_00403a00`. That is defect 2 below.
- The specialised `Set` calls the manager's entries directly. The object
  does not require `FUN_00401000`, so no use of it is expanded today.

None was removed: the constructor behaves differently from the owner's, and
`Set` allocates through another spelling.

Three units specialise the class for `char`, and none is on the shared
header: `src/bsmenu/tile3d.cpp:46`, with the shared fields;
`src/fallout/interface/menus/blackjackmenu.cpp:4351` and
`src/fallout/interface/menus/lockpickmenu.cpp:701`, with a pointer and two
16-bit fields under other names. The last two require the owner's default
constructor and destructor, at 16 bytes with fields at 0, 8 and 10.

Four units declare a global class named `BSStringT` that is not a template:
`companionwheelmenu.cpp:1294`, `computersmenu.cpp:773` and
`tutorialmenu.cpp:269`, 16 bytes each, and
`bgsdestructibleobjectform.cpp:774`, one `int`. Their members are other
symbols, `BSStringT::BSStringT()` and the like, and are counted under "Open"
as copies.

## Defects recorded for the next step

Both are older than this change, and this change repairs neither. Both are
recorded against criterion 5 of VEGAS-17.

### 1. The destructor and `operator=` do not reach `Set`

`0x004037f0` is `BSStringT<char>::Set(const char*, unsigned int)` itself.
The function row is in `bsstring.cpp`, under the template's name. Symbol
rows bind four names to the address, in 86 recipe entries and 81 source
files:

| Name | Recipe entries | Source files |
| --- | --- | --- |
| `BSStringT<char>::Set` | 85 | 80 |
| `TextString::FUN_004037f0` | 71 | 68 |
| `TextString::Set` | 1 | 1, `bsmenu/tiletext.cpp` |
| `String65::Set` | 1 | 1, `fallout_shared/tesworldspace.cpp` |

`TextString::FUN_004037f0` is a stand-in name for that one function. Its
only body is one in the class, in `src/bsmenu/debugtext.cpp`. That unit has
no function row for it, and the definition is select-any, 224 bytes against
the owner's 218. The body calls `LocalStringLength` and `LocalCopy`.
`debugtext.cpp` declares both and nothing in the archive defines either;
both are among the 35,224 undefined names.

80 objects require `TextString::FUN_004037f0`. Two of the callers are the
string's own members: the destructor in `tesobjectacti.cpp` and `operator=`
in `bsstring.cpp` both cast `this` to `TextString` and call the stand-in.
One object, `menutopic.cpp.obj`, requires `BSStringT<char>::Set` itself. So every
destructor and every `operator=` of `BSStringT<char>` reaches `Set` through
a body that cannot link today.

The repair is the next step, not this one. First the destructor and
`operator=` call `Set` directly. Then the stand-in is retired across the
objects that require it, and the body in `debugtext.cpp` leaves with it.

### 2. `0x00403a00` is transcribed twice, and one body is wrong on windows-x64

`bsstring.cpp` defines two functions with the address `0x00403a00`:

| Body | Stores the 16-bit capacity at |
| --- | --- |
| `BSStringT<T>::SetMaxLength` | offset 10 of the object, `sMaxLen` |
| `FUN_00403a00_class::FUN_00403a00` | offset 6 of the object |

Both offsets were read from the disassembly of the windows-x64 object.
Offset 6 is where the capacity is on x86, where the pointer has 4 bytes.
Compiled for x86, the two bodies are the same instructions. On windows-x64
the second body writes into bytes 6 and 7 of the buffer pointer and leaves
`sMaxLen` as it was.

The function row at `0x00403a00` carries the second name. Five call sites
call the second body on a string:

- `src/fallout_shared/extradataobjects.cpp`, twice, in
  `Set(const BSStringT&)`.
- `src/bsmenu/tile.cpp`, three times: once in its specialised constructor
  and twice in its specialised `Set`.

The objects of both units require the name. The class copy at
`src/bsmenu/debugtext.cpp:2398` has two more such calls in a `Set` that is
never instantiated. No object requires `SetMaxLength` from outside
`bsstring.cpp`.

So a string that `Set(const BSStringT&)` reallocates gets its length
written into the top two bytes of the new buffer pointer, and `sMaxLen`
keeps its old value. A string that `tile.cpp` constructs in line has
`sMaxLen` unset. The two bodies behave differently, so neither was removed
here. The repair, in the
next step: the five sites call `SetMaxLength`, and the second body leaves.
That changes what `Set(const BSStringT&)` does on windows-x64, on purpose.
The function row would then name a function that no longer exists. The
rulings below do not list `0x00403a00`, so its respelling is asked with the
repair.

## Rulings

These were made for this change and for the next step.

1. **A recipe row decides against a source comment.** The function row at
   `0x004037d0` is in `tesobjectacti.cpp`. The address lies inside the run
   of `bsstring.cpp`, between `0x004037b0` and `0x004037f0`, and only
   `bsstring.cpp` carried an address comment for it. Where a recipe row and
   an address comment in the source disagree, the row decides. So the
   destructor stays in `tesobjectacti.cpp`. The row still carries a
   stand-in name, `BSStringTChar::~BSStringTChar`.
2. **When the header declares a member.** A member is declared in the header
   in the commit that makes its owner define it under the template's name,
   and not before. `Set(const BSStringT&)` is already defined under the
   template's name, so it may be declared in the commit that moves its
   owner, `extradataobjects.cpp`, onto the header.
3. **Function rows with a stand-in name.** The function-row names at
   `0x0040c0e0`, `0x004047f0`, `0x00404820` and `0x00406f60` may be
   respelled to the template's member, one address per commit. Each commit
   must hold all of these:
   - The address, the size and the unit of the row are unchanged.
   - The body is unchanged, except that its first parameter becomes `this`.
   - Every `symbols` key of the old name is respelled in the same commit,
     or is left undefined and reported as such.
   - The object is equal to the object before, once the names are
     respelled.

   The folded addresses `0x00559450` and `0x004048e0` keep their rows. Many
   classes that are not strings reach them.

No member lacked a function row, so no ruling on a body in the header is
needed.

## Open

One accounting. A name is counted when no archive member defines it, at
least one requires it, and either its class is the global template, or its
class is named `BSString*`, or the recipe of a requiring unit binds it to
one of the fifteen addresses. Each name has one cause, the first that
applies. The archive of the last code commit and the archive of 2277431b8
give the same table.

| Cause | Names |
| --- | --- |
| The template's own name | 9 |
| A member of another class at a folded address, `0x00559450` or `0x004048e0` | 569 |
| A free function | 4 |
| A copy of the string class under another name or in a namespace | 70 |
| A stand-in class with another name, used as the receiver | 116 |
| A class named `BSString*`; no row binds the name to a string address | 17 |
| A class named `BSString*`, bound to an address that is not a string member | 2 |
| Total | 787 |

The 569 are mostly not strings. Of the other 218:

| Waits for | Names | Of these, the receiver is 16 bytes with fields at 0, 8, 10 in every requiring unit |
| --- | --- | --- |
| Replacing the receiver class by the template; `bsstring.cpp` or `tesobjectacti.cpp` already defines the member | 87 | 51 |
| `BSStringT<char>::FUN_00438470`, below | 1 | 1 |
| Replacing the receiver class, for a member at `0x00438470`; `extradataobjects.cpp` already defines it and ruling 2 lets the header declare it | 9 | 3 |
| Ruling 3, or a row at a folded address | 102 | 31 |
| A recipe row | 19 | 15 |
| Total | 218 | 101 |

`BSStringT<char>::FUN_00438470` has its own line because it waits for no
ruling. The function row at `0x00438470` already has the template's name,
`Set(const BSStringT&)`, and `extradataobjects.cpp` defines it. One unit,
`menutopic.cpp`, calls it under the placeholder name. The placeholder
returns `BSStringT&` where the owner's member returns `bool`, so the repair
is a rename and a look at what the caller does with the result.

The 102 are members at six addresses whose function row has a stand-in
name: 51 at the four addresses of ruling 3, and 51 at the folded addresses
`0x00559450` and `0x004048e0`, which keep their rows and so stay open.

The other eight names of the template itself: `BSStringT(const T*)`, the
copy constructor, `operator+=` and `PrintfString` wait for ruling 3.
`GetLength`, `String` and `operator const T*` are at the folded addresses.
`GetMaxLength() const` is a second name for `MaxLength()` at `0x004039a0`,
a rename.

The next step, in order:

1. Repair defect 1: the destructor and `operator=` call `Set` directly.
2. Move `tesobjectacti.cpp` onto the header, with a destructor definition
   the compiler cannot discard.
3. Repair defect 2.
4. Replace stand-in classes by `BSStringT<char>` in units that are on the
   header, by the rule of "Stand-in receivers" in
   `docs/shared-simple-list.md`. Its first candidates are the 51 names.
5. Respell the four rows of ruling 3, one address per commit.

Also open:

- Receivers. Emitting a name does not show that every requirer passes a
  16-byte string. Check (a) measures the requirer's declaration of the
  template, not the object it passes. 26 of the 87 names have a receiver with
  another layout, 14 of them 8 bytes.
- The two 8-byte copies of check (a).
- The seven declarations with the key `struct` of check (c), and the ten
  text copies that no unit compiles.
- Nothing executes these functions. No linking program loads
  `bsstring.cpp.obj` or `tesobjectacti.cpp.obj`. Windows execution: not run.
