# One shared declaration of NiFixedString

`NiFixedString` is the Gamebryo handle to an interned string: one pointer to
the text. VEGAS-69 gave it one native owner
(`docs/native-fixed-string-lifecycle.md`). This change makes the owner's
declaration the one that units share, by the method of
`docs/shared-simple-list.md`: 113 units use it where 9 did, 41 private copies
of the class and 18 unit-local classes that stood in for it are gone, and 34
undefined names leave the forced link of every member.

It is a first increment. What stays is under "What did not move" and "Open
after this change". The checks that later changes must pass are under
"Integration checks". `AssignFixedString` (VEGAS-87) was measured and not
repaired; see its section.

Everything here was measured on 01bbc3a84, windows-x64, in builds of the tip
and of each commit made from one path. The change was first made and
reviewed on 2277431b8; on 01bbc3a84 the scripts that made it decided every
unit the same way and wrote the same trees.

## Where the declaration lives

`include/fnv/native_fixed_string.h`, the header the owner
`native_fixed_string.cpp` is built from. It was adopted as it stood; only its
head comment changed. It declares one field, `char* m_kHandle`, 8 bytes, and
these members:

| Member | Address | Function row in `build/units.json` | Units with a symbols row at the address | Defined by |
| --- | --- | --- | --- | --- |
| `NiFixedString(const char*)` | `0x00438170` | `bsfadenode.cpp`, under this name, 52 bytes | 84 (82 files) | the owner |
| `NiFixedString(const NiFixedString&)` | `0x0048af40` | `tesmodeltextureswap.cpp`, under this name, 38 bytes | 4 | the owner |
| `~NiFixedString()` | `0x004381b0` | `extradataobjects.cpp`, as `FUN_004381b0_shell::FUN_004381b0`, 23 bytes | 77 (75 files) | the owner |
| `operator=(const char*)` | `0x00a2e750` | `nifixedstring_h_unit.cpp`, under this name, 50 bytes | 3 | the owner |
| `IsNotEmpty()` | `0x0048af70` | `tesmodeltextureswap.cpp`, under this name, 27 bytes | 3 | the owner |
| `FUN_004b9900(unsigned int)` | `0x004b9900` | `blk_004a0000_od.cpp`, under this name, 44 bytes | 8 | `blk_004a0000_od.cpp` |
| `NiFixedString()` | none | none | | the owner |
| `operator=(const NiFixedString&)` | none | none | | the owner |
| `operator const char*()` | `0x0043b1b0` | `modelloader.cpp`, as `fnv_0043b1b0::FUN_0043b1b0_shell::FUN_0043b1b0`, 23 bytes | 46 (45 files), under 71 names | `nigeommorphercontroller.cpp`, without an address tag |

The unit counts count entries of the recipe's `units` list whose `symbols`
map has a value equal to the address. A source file can have more than one
entry: `actor.cpp` and `hudmainmenu.cpp` have two each, and both entries of
each have a row at `0x00438170` and at `0x004381b0`, and both entries of
`actor.cpp` have one at `0x0043b1b0`. The figure in brackets counts source
files instead.

The method asks for exactly the members whose function rows exist. Six
members have a row under the class's name or, for the destructor, under the
name of its address. Three do not have a function row of their own: the
default constructor and the copy assignment have no row at all, and the
conversion to text at `0x0043b1b0` has its row under another name, a 23-byte
function that the original shared between many classes. These three were in
the header the owner was accepted with (VEGAS-69) and stay. They are a
named exception to the method, in the way the polymorphic-class exception of
the 2026-11-11 rulings is one for virtual slots. The exception covers these
three members and nothing else; a new member without a function row is not
admitted by it. Whether removing one of them would change an object was not
measured.

One function row under the class's name is not declared:
`NiFixedString::FUN_00761760(int*, unsigned int)` at `0x00761760`, in
`blk_00760000_od.cpp`. That unit declares its own 1-byte `NiFixedString` and
calls the function through a cast from `FUN_00761760_class`. It is another
class's function under this class's name and needs its own identity first.

## How the bodies are provided

By the owner, as since VEGAS-69. The owner defines the bodies of five
addresses: `0x00438170`, `0x0048af40`, `0x004381b0`, `0x00a2e750` and
`0x0048af70`. The units that hold the function rows do not emit these
members. `docs/inline-recipe-bodies.md` lists only two of the five,
`0x00438170` and `0x0048af40`, under "Another unit, not the one in the recipe
row, defines the function"; `0x004381b0`, `0x00a2e750` and `0x0048af70` are
provided the same way and are not in its list. Nothing changes here in who
provides what.

Two of those units still hold a body at a fixed-string address:

- `bsfadenode.cpp` defines the constructor from text `__forceinline`, with
  the tag `0x00438170`. It compares against the sentinel `DAT_0109b220`,
  which the owner never writes. The body is expanded in the unit and not
  emitted.
- `extradataobjects.cpp` defines `FUN_004381b0_shell::FUN_004381b0` with the
  tag `0x004381b0`, the destructor's address. It is emitted, and two other
  objects require it. So that address has two tagged bodies under two names.

Neither was touched. See "Bodies outside the owner".

### The destructor: a native-owner exception

`0x004381b0` is an exception to the 2026-11-11 ruling that the recipe row
decides over a source address comment. The function row is held by
`extradataobjects.cpp` under the stand-in name
`FUN_004381b0_shell::FUN_004381b0`, and that unit still emits a body tagged
with the address. VEGAS-69 accepted the native owner,
`native_fixed_string.cpp`, as the one provider of `??1NiFixedString@@QEAA@XZ`,
the destructor this change binds. So the address has two tagged bodies, and
the one the bound name reaches is not in the unit of the row.

The two bodies are equivalent for releases only while `DAT_0109b220` stays
zero. The stand-in's body calls `FUN_004381d0`, which returns when the handle
equals `DAT_0109b220` and otherwise decrements the count before the text
through `0x004019a0` (named `WaitForSingleObjectEx`, its body is
`InterlockedDecrement`). The owner's body returns on the null handle and
otherwise decrements the same count. `DAT_0109b220` is defined in
`src/generated/data/bsmenu/font.inc` without an initialiser, and no source
writes it. That is a standing check (integration check (d) below): if it ever
gets a value, the two bodies diverge.

The next step is to respell the function row at `0x004381b0` and the keys of
its `symbols` rows to `??1NiFixedString@@QAE@XZ` and remove the stand-in body
(criterion 4 of VEGAS-11, and VEGAS-69). This change does neither.

## What was measured

The compiler was run over each of the 2,224 units of the archive with the
unit's own command line. It reported every class whose name contains
`NiFixedStr`, and every class with a member that the unit's recipe binds to
one of the addresses above: fields, bases, members, bodies, and the size and
field offsets.

326 declarations with a body were found. 165 are named `NiFixedString`: 110
at global scope and 55 inside a namespace or class. By size, fields and
member signatures the 165 fall into 87 shapes; 146 are 8 bytes, 13 are 1
byte and 6 are 4 bytes.

What each unit uses as the global class:

| Declaration of `::NiFixedString` | Units at the tip | Units after |
| --- | --- | --- |
| `include/fnv/native_fixed_string.h`, the shared one | 9 | 113 |
| `include/NiFixedString.h`, the plain layout view | 57 | 9 |
| `include/fnv/decl/NiFixedString.h`, members without a field | 3 | removed |
| a copy in the unit or in a header under `src/` | 107 | 66 |
| declared without a body | 650 | 639 |
| not declared | 7 | 6 |

## The rule for replacing a declaration

Three kinds of declaration are candidates: a copy of the global class, a
class named `NiFixedString` inside a namespace or class, and a class of
another name whose constructor the unit's recipe binds to a fixed-string
address. A candidate is replaced by the shared declaration when all of the
static conditions hold and one of the three proofs succeeds.

Static conditions, measured by the compiler in the unit or read from the
recipe:

1. The class is 8 bytes, alignment 8, with one field at offset 0 of type
   `char*` or `const char*`.
2. It has no base, no virtual or static member, no nested declaration, no
   defaulted or deleted member, and no member body in the class. The unit
   defines no member of it outside the class.
3. Every member it declares is a member of the shared declaration with the
   same parameters.
4. The unit does not name the field, unless the field is `char* m_kHandle`.
5. The class is defined in the unit's `.cpp` or in a header that only that
   unit includes.
6. For a class that is not the global one: every member of it that the
   object requires, other than the destructor, is bound by the unit's recipe
   to the address of the shared member it becomes. No other entity of the
   unit carries its name. The unit's only definition of the global class is
   the shared one, or a copy that is replaced with it.

The proofs, per object, against the build of the parent commit from the same
path:

| Proof | What may differ in the object | Commits |
| --- | --- | --- |
| T0, a pure declaration move | nothing; byte-identical with the COFF timestamp masked | the two header moves, 36 copies |
| T1, a substitution | the old names become the new names; the symbol table is otherwise the same and every section and relocation is equal | 8 classes |
| T2, two steps | first the constructor is declared `noexcept` and only unwind data differs; then the substitution is T0 or T1 | 14 classes |

T2 is new with this change. Its rule: declare the constructor `noexcept` to
match the one definition its recipe row binds; only unwind data may differ;
then substitute. It holds for a unit only under all of these conditions:

1. The recipe row the unit's constructor is bound to has one definition, and
   that definition is `noexcept`. Here: `0x00438170`, defined by the owner.
2. The first step adds `noexcept` to the unit's declarations of that
   constructor and changes nothing else in the source.
3. Against the parent, no byte of any `.text` section changes, and every
   function that is not an unwind funclet has the same instructions and
   relocations. Only `.xdata` and the relocations and labels of funclets may
   differ.
4. Every unwind state the step removes describes a throw out of a callee
   that cannot throw: the constructor, whose one definition is `noexcept`.
   Here this follows from conditions 2 and 3: the only change to the source
   is that constructor's specification, and no instruction changes.
5. The second step is a T0 or T1 substitution against the first.

A unit where the first step changes instructions is refused, whatever the
second step gives. 22 units are refused for that reason ("The exception
specification step").

The classes are held by value: they are temporaries and locals. The stand-in
batches refused such a class because they compared no storage. Here the
storage is compared: size, alignment and the one field offset are the shared
class's, in that unit.

A unit is decided as a whole. When one of its candidates fails, none of that
unit's candidates is replaced.

## The plain view and the two other headers

`include/NiFixedString.h` declared the class as a field, a conversion and an
assignment from text, with no constructor and no destructor. 57 units saw
it. It now includes the shared declaration, and keeps its old text under
`FNV_KEEPS_PLAIN_NIFIXEDSTRING` for a unit that defines that macro before
its includes.

Each of the 57 units was compiled on the shared declaration. 48 have a
byte-identical object and moved. 9 do not, and define the macro:

| Unit | What its object gains on the shared declaration |
| --- | --- |
| `bsshaderbloodsplatter.cpp`, `debugshader.cpp`, `speedtreeleafshader.cpp`, `watershader.cpp` | a call of the owner's destructor, and a deleting destructor and table of `NiShader` |
| `imagespacemanager.cpp`, `nid3dtexturestage_lifetime.cpp`, `nidefaultavobjectpalette.cpp`, `nishaderfactory.cpp` | calls of the owner's default constructor and destructor |
| `nitextureeffect.cpp` | the same, and a static initialiser with an `atexit` registration |

These nine hold fixed strings by value. The plain view has no constructor
and no destructor, so on it nothing is called for such an object; on the
shared declaration the owner would be. That is the disagreement, and the
nine stay on the plain view. Whether each of them updates the count by hand
was not measured.

`tests/runtime/d3d_texture_stage_lifetime_test.cpp` includes the plain view
and is built into one program with `nid3dtexturestage_lifetime.cpp`. It gets
the macro from `tests/CMakeLists.txt`, as a definition for that one source.
Both sources of the program then see one class, and no line of the test
moves, so its `assert` line numbers and its object are unchanged.

The macro is not transitional in the way `FNV_KEEPS_OWN_BSSIMPLELIST` is. It
leaves when the nine units construct and destroy through the owner, which is
a change of behaviour and not a declaration move.

`include/fnv/decl/NiFixedString.h` declared the class a third time, with six
members and no field, 1 byte. Its three units, `bgsaddonnode.cpp`,
`bsfacegenanimationdata.cpp` and `bsfacegenmorphdata.cpp`, include the shared
declaration instead, with byte-identical objects, and the header is removed.
The three were exceptions of check (a) below: they required owner members
for a class they measured as 1 byte.

## Copies of the global class

107 units carried their own definition of `::NiFixedString`, counted as
pairs of copy and unit.

| Outcome | Pairs |
| --- | --- |
| Replaced by the include, object byte-identical (T0) | 36 |
| Replaced in a unit of T1 or T2 | 5 |
| Fails a static condition | 47 |
| The constructor's `noexcept` would change instructions | 16 |
| The copy is plain data in the unit | 3 |

The 47, by first condition that fails: a member body in the class 22, the
unit names the field 7, another layout 6, a field of another pointer type 6,
a member defined outside the class 4, a member the shared declaration lacks
1, a virtual or static member 1.

The three plain-data units are `font.cpp`,
`nishaderconstantmapentry_h_unit.cpp` and `nipsyspositionmodifier.cpp`. Their
copy declares no member, and the unit default-constructs, copies or assigns
such objects. On the shared declaration the object gains calls of the owner's
default constructor, destructor or copy assignment, which would start
counting references where the unit counts none.

## Classes replaced

| Unit | Class | Proof |
| --- | --- | --- |
| `middlehighprocess.cpp` | `fnv_0091e830::NiFixedString` | T1 |
| `loadingmenu.cpp` | `fnv_007890e0::NiFixedString` | T1 |
| `absorbeffect.cpp` | `fnv_008034c0::NiFixedStringStandIn` | T1 |
| `magicballprojectile.cpp` | `fnv_008106d0::Fixed`, and a copy of the global class | T1 |
| `magicfogprojectile.cpp` | `FxFixedString` | T1 |
| `magicprojectile.cpp` | `MADName` | T1 |
| `reanimateeffect.cpp` | `BoneName`, `BoneKey` | T1 |
| `caravanmenu.cpp` | `fnv_0074fc00::NiFixedString`, `FixedName`, `CaravanSetup::FixedString` | T2 |
| `roulettemenu.cpp` | `fnv_007bd2a0::FixedStr`, and a copy of the global class | T2 |
| `tesobjectcell.cpp` | `fnv_00548880::NiFixedString` | T2 |
| `tesrace.cpp` | `fnv_006149b0::NiFixedString` | T2 |
| `forenderedmenuracesex.cpp` | `xFixedStr` | T2 |
| `blackjackmenu.cpp` | `String90` | T2 |
| `navmeshrender.cpp` | `FixedStrX` | T2 |
| `teslight.cpp` | `LightCreation::FixedString` | T2 |
| `fopipboymanager.cpp`, `slotmachinemenu.cpp`, `surgerymenu.cpp` | a copy of the global class | T2 |

18 classes of another name or scope in 15 units, and 5 copies of the global
class. Each of the 18 declares a field, the constructor from text and the
destructor, and nothing else.

Edits, in the unit's own `.cpp` or its own header: the definition leaves;
every type name that named the class becomes `::NiFixedString`; the include
is added before the file's first include when the file does not have it
above the class. Nothing is declared, no cast and no member is added. In
`tesrace.cpp` one call cast its argument to `::NiFixedString` in front of a
cast to `fnv_006149b0::NiFixedString`; after the respelling the two casts are
the same and one is dropped, with the object unchanged. 70
type names were respelled for the classes of another name and 4 qualified
names for the namespaced ones. Seven of the 74 are the parameter of a
virtual function in a table of virtual slots that the unit declares.

### Recipe keys

In the symbols map of each changed unit, the key of the replaced constructor
becomes the symbol of the function row at `0x00438170`,
`??0NiFixedString@@QAE@PBD@Z`: 12 keys respelled and 6 merged into that key,
which the unit already had or gets from another class of the same change.
No other key changes. No function row changes.

The destructor has no key under the class's name, before or after, in any
unit of the tree. Every one of the 15 units has a symbols row at
`0x004381b0` under the name of that address's function row,
`FUN_004381b0_shell::FUN_004381b0`. The destructor binding therefore rests
on the class: the unit constructs a `NiFixedString` at `0x00438170`, and the
object it constructs is destroyed by that class's destructor. That the
function row at `0x004381b0` carries a stand-in name is open against
criterion 4 of VEGAS-11.

## The exception specification step

The owner defines the constructor from text `noexcept`. A unit-local class
declared it without. Replacing such a class by the shared one therefore
changes more than names wherever the compiler had kept unwind state for a
throw out of the constructor.

For 11 units the commit before the replacement adds `noexcept` to the 14
constructor declarations and does nothing else. Measured against its parent:

- every function that is not an unwind funclet has the same instructions and
  relocations, and no `.text` section differs;
- only `.xdata` differs. In 10 of the objects 15 `.xdata` sections differ
  by bytes: the unwind tables of 15 functions, each without the state for
  that throw. `.xdata` shrinks by up to 184 bytes per object;
- in `navmeshrender.cpp` and `tesrace.cpp` the compiler numbers the unwind
  funclets of one function anew. Their bytes are the same; the labels and
  the relocations that name them differ. In `tesrace.cpp` that is the whole
  difference: no section differs by bytes, only the relocations of one
  `.xdata` section, and `.xdata` keeps its size;
- the warnings and the link are unchanged.

So no instruction changes on any path. The declaration now agrees with the
one definition its recipe row binds it to. The replacement after it is a T0
or T1 substitution.

22 more units have such a declaration and were measured the same way. There
the step changes instructions in 28 functions that are not funclets, so the
units were left alone. In 25 of the 28 the function grows or shrinks by at
most three instructions. In all but one the relocation targets are the same.
`InitializeMultiBounds` in `globalfunc.cpp` loses 165 instructions, and
`xActor::FUN_00953060` in `playercharacter.cpp` gains a stack cookie check.
After the step each of the 22 would be a T0 or T1 substitution. The
per-function figures were measured on 2277431b8. On 01bbc3a84 the step was
tried again with the same verdict for each of the 22 units. 21 of their
objects are byte-identical to those of 2277431b8; `modelloader.cpp` has
changed since, and its per-function comparison, made again, has the same
result. Whether a declaration that agrees with its definition may change
instructions is a question for a ruling; it is not answered here.

## Bodies outside the owner

The owner is not the only place where a body acquires or releases a fixed
string. 38 units compile 88 member bodies of a class named `NiFixedString`,
79 in the class and 9 outside it. Read from their text, with the helpers
they call followed to their bodies:

| Member | Bodies | What the body does |
| --- | --- | --- |
| Destructor | 21 | `InterlockedDecrement` on the count before the text, guarded by a comparison with `DAT_0109b220` |
| Destructor | 6 | the same through a helper: `DecRefCount` (3), `DecRef` (2) or `FUN_004381d0` (1), each of which compares with `DAT_0109b220` or is called after that comparison, and decrements the count |
| Constructor | 25 | `AddString`, or `FUN_00a5b690` once; 17 of them compare with `DAT_0109b220` first |
| Constructor | 1 | the copy: `InterlockedIncrement` with the sentinel comparison |
| Constructor | 7 | no update of the count: 3 default constructors (one stores `DAT_0109b220`, two leave the field unset), and 4 that store a pointer they are given without interning or retaining it, one of them a constructor from text in `tesobjectrefr.cpp` |
| Assignment | 6 | `InterlockedIncrement` and `InterlockedDecrement`, directly or through helpers, with the sentinel comparison |
| Assignment | 3 | `AddString` for the new text, and a decrement of the old one |
| Assignment | 1 | stores the pointer it is given, with no update of the count |
| Other members | 18 | conversions, comparisons, `Clear`, `Release`, `Exists` |

`FUN_004381d0` calls `0x004019a0`. That function is named
`WaitForSingleObjectEx` in the recipe and in `bgsdehydration.cpp`, but its
body is `InterlockedDecrement`. So every one of the 27 destructors releases
by decrementing the count before the text, as the owner's destructor does.

The owner's bodies call `RetainHandle` and `ReleaseHandle`, treat the null
handle as the null string and never read `DAT_0109b220`. While
`DAT_0109b220` is zero the comparison with it is the owner's null test, and
the 27 destructors, the 25 constructors that intern, the copy constructor and
the 9 assignments that update the count release and acquire as the owner
does. Where the bodies do differ is narrower: the 7 constructors and the 1
assignment that do not update the count. None of the 88 bodies is in a file
this change touches.

None was unified with the owner. A copy with a member body fails static
condition 2 and its unit stays on the copy. None of these bodies is emitted
under a name of the global class: check (b) finds one definition per name.

## AssignFixedString (VEGAS-87)

The defect is as the ticket says, and the direction is settled by the tree's
own history:

- The definition at `0x00a5b950` in `niobjectnet.cpp` reads the name through
  its third parameter. Before the commit that gave each address one name
  (3f0599801) it was declared `void __fastcall AssignFixedString(char* pThis,
  int, char** ppkName)`: the object in the first register, an unused second
  register, and the name as the one argument on the stack.
- The recipe binds a second name to the address,
  `NiAVObject::SetName(const NiFixedString&)`: a member call with the name as
  its one argument.
- Before that commit the call sites were member calls with one argument,
  such as `node->SetName(NiFixedString(text))`. The commit turned them into
  calls of the free function, with the name second and an empty third
  argument. It created 87 of the calls counted below; for 77 of them the
  line it removed holds a member call with one argument, 40 named `SetName`
  and 19 `AssignFixedString`.

The argument order of these calls was changed by 3f0599801. Before it the
tree had no call of the form `AssignFixedString(..., {})`; after it, 130.
They replaced member calls with one argument, and passed the name's address
as the second argument cast to `int`, which truncated the pointer to 32 bits
(6d096bffd later made that parameter `intptr_t`). At least 87 of the 108
such calls at 01bbc3a84 come straight from 3f0599801; the other 21 were added by
later commits in the same form.

So the name belongs third. 21 calls already pass it there. 108 pass it
second with `{}` third. Two more pass a 32-bit integer second and `{}` third,
in `niscmextradata.cpp` and `missileprojectile.cpp`; no pointer can be made
of those.

The repair was written as a script and tried, and is not part of this
change. With the 108 calls rewritten to the form of the 21, 89 functions
change in 46 objects. In 86 of them the relocation targets are the same and
the function grows or shrinks by at most one instruction. In three functions
of `niobjectnet.cpp`, where the definition is visible, the compiler adds or
removes whole stretches of code: two gain the name update they lacked, and
one loses about half of its body with the calls in it.

The definition reads 8 bytes through the pointer it is given. Of the 108
arguments, 73 are temporaries: 56 of a class the unit measures as 8 bytes,
11 of a class it measures as 4 bytes, 6 of a class that was not measured.
The other 35 are existing objects whose class was not measured. So the
repair depends, call by call, on the class of the argument, and those
classes are the stand-ins this document tables. Moving the name to the third
argument before their layouts are right trades a null read for a short read
at 11 calls at least.

The ticket also requires tests through the production entry on constructed
objects. `niobjectnet.cpp` builds for windows-x64 only and no test program
links it, so no such test can run on the host.

What a later change can use: the script and its trial tables are kept with
the review evidence. The script also declares a deleted overload of the free
function for a null third argument, so that a call without a name does not
compile; that is how the two integer calls were found.

The repair plan, in order:

1. Type the third parameter as `const NiFixedString*`, so that the compiler
   reports the class of every site's argument.
2. Repair first the sites whose argument is the shared 8-byte class in a unit
   on the shared declaration, each with an object proof. This change makes
   34 of the 108 calls spell the argument as `::NiFixedString`, where 30 did;
   which of those units use the shared declaration is not counted here.
3. Then the sites whose argument is an 8-byte stand-in, together with its
   substitution by the shared class.
4. The sites whose argument is a 4-byte class wait for that class's layout
   repair.
5. The 2 sites that pass an integer need producers that return a typed fixed
   string.

The test the ticket requires stays blocked until `niobjectnet.cpp` links into
a host program or Windows tests run.

## Integration checks

Run these on every change that touches the shared header, a copy of the
class, or a class that stands in for it. They were run on the archive of the
tip and of the last code commit.

(a) Layout per requirer. Take every name of the global class that an archive
member defines and another member requires. For each requiring unit the
compiler's measure of `::NiFixedString` in that unit must be 8 bytes,
alignment 8, with one pointer field at offset 0. Tip: 9 names, 58 requiring
objects, 53 pass. After: 9 names, 70 requiring objects, 68 pass. The three
units of the removed header were exceptions and now pass. Two exceptions are
older than this change and remain: `blk_00560000_od.cpp` and
`blk_00760000_od.cpp` each declare a 1-byte class of their own and require a
member the archive defines for the 8-byte one. A new exception fails the
check.

(b) Definitions. No name of a class named `NiFixedString`, in any scope, may
have two definitions in the archive, and the count of names with differing
definitions in the whole archive may not rise. Tip and after: 10 defined
names, none with two definitions; 525 names with differing definitions, none
entering or leaving.

(c) Class-key. No symbol of the archive may spell the global class with the
`struct` key. Tip and after: none.

(d) The sentinel stays zero. `DAT_0109b220` must keep its definition without
an initialiser, and no object of the archive may write it. Disassemble every
object with a relocation against `?DAT_0109b220@@3PEADEA` or against
`EmptyFS`, an alternate name of it, and classify each instruction that uses
it. Tip and after: 1,825 uses, each a read (`cmp`, `mov` into a register,
`movd`, `movsxd`); no write and no address taken. The stand-in destructor at
`0x004381b0` and the bodies outside the owner release as the owner does only
while this holds.

## Measured links

Forced link of every archive member, windows-x64, 2,224 members in the same
order at every commit. Each column is a fresh build of that commit.

| | 01bbc3a84 | Headers | 36 copies | 8 classes | `noexcept` | 14 classes |
| --- | --- | --- | --- | --- | --- | --- |
| Undefined names | 35,224 | 35,224 | 35,224 | 35,208 | 35,208 | 35,190 |
| Left / entered | | 0 / 0 | 0 / 0 | 16 / 0 | 0 / 0 | 18 / 0 |
| Duplicate symbols | 0 | 0 | 0 | 0 | 0 | 0 |
| Imports | 137 | the same | the same | the same | the same | the same |
| Objects that differ from the column before, of 2,302 | | 0 | 0 | 7 | 11 | 8 |
| Names with differing definitions in the archive | 525 | 525 | 525 | 525 | 525 | 525 |

Every build has 2,320 steps, none failed, and 20,788 warning lines that are
equal once line and column are removed. `src/generated` is untouched. The
other three link cells are unchanged at every commit.

The 34 names that leave are the constructor from text and the destructor of
17 classes. The eighteenth, `xFixedStr`, is replaced in
`forenderedmenuracesex.cpp`; `bstempeffectsimpledecal.cpp` has a class of
that name too and still requires both names.

## What did not move

Classes named `NiFixedString` inside a namespace or class, as pairs of class
and unit: 55, of which 5 were replaced. The other 50: another layout 14, a
member body in the class 12, a member the shared declaration lacks 8, the
`noexcept` step would change instructions 8, a member bound to another
address 3, the unit names the field 3, a field of another pointer type 1,
the unit has another definition of the global class 1.

Classes of another name with a constructor bound to a fixed-string address:
58 pairs, of which 13 were replaced. The other 45: another layout 19, the
`noexcept` step would change instructions 10, a field of another pointer
type 6, a member bound to another address 3, the unit has another definition
of the global class 3, and one each for a named field, a second entity of the
same name, a member the shared declaration lacks and a member body.

"Another layout" is 39 pairs over the three kinds. 12 declare no field at
all, 1 byte. 20 declare one `int` or `unsigned int`, 4 bytes: the owner's
constructor writes 8 bytes into such an object. A class named `BSFadeNode`
in six units is one of these: its constructor from text is bound to
`0x00438170`. 6 have a base or a second field and one is a one-byte array.
None was touched.

## Open after this change

One accounting, applied to the archive of the tip and of the last code
commit. A name is counted when no archive member defines it, the forced link
lists it as undefined, and one of these holds: its class has a name
containing `NiFixedStr`; the recipe of a requiring unit binds it to one of
the addresses of the first table, to `AssignFixedString` or to `AddString`;
or it is another member of a class that a requiring unit binds, through one
of its members, to an address the owner defines. Each name has one cause,
the first that applies in the order of the table.

| Cause | Tip | After |
| --- | --- | --- |
| Replaced | 34 | 0 |
| A conversion to text at `0x0043b1b0` on a class that is not a candidate | 43 | 43 |
| The unit declares the class with another layout | 40 | 40 |
| The `noexcept` step would change instructions | 35 | 35 |
| A member of the class is bound to another address | 16 | 16 |
| The field is a pointer of another type than `char` | 9 | 9 |
| The unit has another definition of the global class | 6 | 6 |
| The string table entry or the name assignment under another name | 5 | 5 |
| Another class named after the fixed string | 4 | 4 |
| A member the shared declaration lacks | 3 | 3 |
| The unit names the field | 2 | 2 |
| Another entity of the unit has the same name | 2 | 2 |
| A member body in the class | 1 | 1 |
| Total | 200 | 166 |

34 names leave and none enters or changes row. The two names of `xFixedStr`
are in the row of the `noexcept` step, because of the unit that still
requires them.

What each row waits for:

- The 35 names: a ruling on the `noexcept` step where it changes
  instructions. The 22 units are then substitutions.
- The 16 names: for 13 of the 14 classes the other address is `0x0043b1b0`,
  the conversion to text. `nigeommorphercontroller.cpp` defines it under the
  global class's name without an address tag, and nine objects bind it. Once
  that definition has a recorded owner these classes are candidates. The
  fourteenth, `CreditFixedString`, binds a default constructor to
  `0x007613f0`.
- The 43 names: the same conversion on classes that declare nothing else,
  mostly without a field. They are views of a pointer, not constructions.
- The 40 names: the unit's class must first be 8 bytes. That is a layout
  repair in each unit.
- The 9 and 2 names: a rule that respells a named field and accepts `void*`
  after comparing every use.

## Not covered

- Receivers. A unit that moved onto the shared declaration passes fixed
  strings by pointer or reference, as far as its object shows. Whether the
  objects it receives were made by the owner is not established. A unit whose
  class was replaced constructs and destroys through the owner at the sites
  the recipe binds; that the original reached `0x00438170` with an 8-byte
  object at each of them is not proven.
- The nine units on the plain view, the 66 remaining copies, the 88 bodies
  outside the owner, and the two tagged bodies at `0x004381b0`.
- The three members of the shared declaration without a function row, and
  `FUN_00761760`.
- `AssignFixedString`: 110 calls give the definition a null name.
- Nothing executes the changed units. No linking program loads them. Windows
  execution: not run.
