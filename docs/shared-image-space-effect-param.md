# One shared declaration of ImageSpaceEffectParam

VEGAS-17 owns the `bsshader` units, and with them
`src/bsshader/imagespaceeffectparam_h_unit.cpp`, the unit that
`build/units.json` gives the constructor at `0x00414430`. This change gives
the class of that constructor one declaration that units share, moves 7
units onto it, moves the 4 units of a member-only declaration of the class
onto it and removes that declaration, and replaces
19 stand-in classes by it in 16 units (VEGAS-11). 23 units and the owner
use the declaration afterwards. It follows the method of
`docs/shared-simple-list.md`. It is a first increment: what stays open is
under "What did not move", "Stand-ins refused" and "Not covered". The checks
that later changes to the class must pass are under "Integration checks".

Everything below was measured on 5b1781acf with clang-cl for windows-x64.
Windows execution: not run.

## Where the declaration lives

`include/fnv/image_space_effect_param.h`, beside `bs_simple_list.h` and the
other native declarations that several units share.

## What it declares

```cpp
struct ImageSpaceEffectParam
{
  public:
    float r, g, b, a;
    ImageSpaceEffectParam(float red, float green, float blue, float alpha); // 0x00414430
};
```

| Address | Member | Recipe size | Units with a symbols key at the address | Names in those keys |
| --- | --- | --- | --- | --- |
| `0x00414430` | `ImageSpaceEffectParam(float, float, float, float)` | 51 | 73 before and after | 84 before, 65 after |

A unit counts when its `symbols` map has at least one key whose value is the
address; a name counts once however many units carry it. The 19 keys that
leave are in units that keep a key at the address, so the unit count does
not change.

## Evidence for the fields

The class is the owning unit's own declaration, unchanged: four `float`
fields and the constructor. The owner's body stores its four arguments in
the four fields. It is compiled from the same declaration, so it is not
independent evidence for the fields. The evidence is this:

- The recipe's function row at `0x00414430` is
  `??0ImageSpaceEffectParam@@QAE@MMMM@Z`: a constructor that takes four
  `float` arguments. The recipe gives it 51 bytes, the size of a function
  that stores four values and returns. It was not compared with a capture
  of the original code.
- The offsets are the ABI consequence of the declared types. The compiler,
  probed in each of the 23 units on the header with the unit's own command
  line (check (a) below), lays
  the class out as 16 bytes with alignment 4 and the fields at offsets 0, 4,
  8 and 12.
- User bodies agree with that layout. `testerrainlodmanager.cpp`
  constructs the class, has the land or the world fill it, and reads `.r`,
  `.g` and `.b` into a luminance (`r * 0.31 + g * 0.37 + b * 0.32`).
  `bstempeffectsimpledecal.cpp` (around line 1870) allocates 8192 bytes for
  the colours of at most 512 vertices, next to 6144 bytes for 512 points of
  three floats: a stride of 16 bytes per colour against 12 per point.
- No body that contradicts the layout is known. Bodies outside the units
  of this change were not searched for one.

Nothing else is declared. Two members that some copies declare have a
function row, but not under this class's name, and they join the header
when their owner is settled:

| Address | Declared by copies as | Function row | Units with a symbols key at the address | Names |
| --- | --- | --- | --- | --- |
| `0x004a7800` | `ImageSpaceEffectParam()` | `S::FUN_004a7800` in `fallout_shared/bgsprimitive.cpp`, 43 bytes | 22 | 20 |
| `0x00532f60` | `ImageSpaceEffectParam ScaleVector4(float)` | `FUN_00532f60_cls::ScaleVector4` in `fallout_shared/tesimagespacemodifier.cpp`, 106 bytes | 4 | 4 |

The counting rule is the one above; this change alters neither row.

## How the body is provided

The header has no body. The owning unit defines the constructor, in
`src/bsshader/imagespaceeffectparam.h`, which only that unit includes. The
definition is an ordinary external function, so a second definition in
another unit is a duplicate symbol at link time. No unit other than the
owner may define it, and a unit on the shared header cannot: it sees the
declaration only.

## Two classes under one name

The program has two different definitions of `::ImageSpaceEffectParam`. In
C++ that is a violation of the one-definition rule: the program is
ill-formed, and no diagnostic is required. This header is the first of the
two.

- The class of `0x00414430`: four floats and a constructor. By its field
  names in the owner and in most copies it is a colour.
- A polymorphic class with a table of virtual functions and two arrays,
  declared in 15 places, most of them headers of `src/bsshader`: 56 bytes
  where the arrays are declared (7), 40 or 36 bytes where they are opaque
  storage (2), and 1, 4 or 8 bytes where a unit declares a shell (6). That
  the six shells mean this class is INFERRED from the units they are in.
  Two recipe rows belong to it: `ImageSpaceEffectParam::DestroyIfFlagged`
  at `0x004ebb00`, a function row of `fallout_shared/teswater.cpp` that a
  generated table of virtual functions lists, and a default constructor at
  `0x004eba20`, which `bsshader/shadowscenelight.cpp` binds as
  `fnv_00b9f780::ImageSpaceEffectParam`. The image-space effects take a
  pointer to it in `Setup(ImageSpaceManager*, ImageSpaceEffectParam*)`.

The violation is older than this change. The change neither creates it nor
widens it: it adds no third definition and moves no unit from one
definition to the other. The 12 units that gain the include had no
definition under the name before and now see the four-float one, the
definition the owner already had. It is harmless today because nothing is
emitted under the name on which the two definitions could disagree. The
archive defines two members of the global name, each once and out of line:
the constructor of `0x00414430` in the owner and `DestroyIfFlagged` in
`teswater.cpp`. No inline member, table of virtual functions, RTTI record
or CodeView type record is emitted under the name. Check (b) under
"Integration checks" guards that: a differing definition of any name would
raise the count it measures. The shared header gets no inline body until
the name is settled.

A unit that declares the polymorphic class cannot include the shared
header, and none does.

Decision (coordinator, VEGAS-11): the polymorphic class keeps the global
name `ImageSpaceEffectParam`, because its name comes with its table of
virtual functions and its type records. The four-float colour class takes a
scoped identity in a later step: one header, the function row at
`0x00414430` and its keys, and the 23 units that depend on the header,
changed by name only and proved by the objects. That step is not part of
this change, which respells no function row. Until it lands, "the class" in
this document is the class of `0x00414430`.

## The rule for moving a unit

A unit's own definition of the global class is replaced, where it stands,
by `#include "fnv/image_space_effect_param.h"` when both hold. This is the
rule of `docs/shared-simple-list.md`.

1. The compiler, in every unit that sees the definition, shows it to be
   the shared class: four public `float` fields `r`, `g`, `b`, `a` in that
   order, 16 bytes, alignment 4, no base class, and no member other than
   the constructor `(float, float, float, float)`, declared without a body.
2. After the replacement every such unit compiles, with the same warnings,
   and its object is byte-identical to the object before, with only the
   COFF timestamp masked.

The field names are part of condition 1 on purpose. The original linker
kept one body for every function with the same code, so the constructors
of every class of four floats have the address `0x00414430`: units bind
it for colours, for rectangles (`left`, `right`, `top`, `bottom`) and for
a rotation. A recipe row at the address does not say which class the unit
means, and the field names are the only evidence the tree has. A copy with
other field names stays until its identity is decided.

## What was measured

34 definitions of a global class named `ImageSpaceEffectParam` are seen by
units of the archive, besides the owner's and the member-only file below.
Each is seen by one unit. Every one was tried under condition 2, whatever
condition 1 said.

| Definition | Sites | Object when replaced | Moved |
| --- | --- | --- | --- |
| The shared class exactly | 7 | identical | 7 |
| Four float fields under other names | 7 | identical | none |
| Four float fields and a member the shared class lacks | 3 | does not compile | none |
| No field and the constructor | 1 | identical | none |
| The polymorphic class, or a shell of it | 15 | differs (14), does not compile (1) | none |
| Six fields, 24 bytes | 1 | does not compile | none |

The seven units moved: `explosion.cpp`, `projectile.cpp`, `seendata.cpp`,
`tesland.cpp`, `tesobjectrefr.cpp`, `blk_004a0000_o2.cpp`, and
`bgsdecalmanager.cpp` through `bgsdecalmanager_decls.h`.

## What did not move

| Site | In its unit | Why it stays |
| --- | --- | --- |
| `fallout/ai/combat/combatgroup.cpp:2136` | fields `f0`, `f4`, `f8`, `fc` | other field names |
| `fallout/misc/main.cpp:10048` | fields `m_kPointA`, `m_kPointB`, `m_iThirdValue`, `m_iFourthElementInteger` | other field names |
| `fallout_shared/globalfunc.cpp:3682` | fields `x`, `y`, `z`, `w` | other field names |
| `fallout_shared/pathfinding/pathinglosmap.cpp:396` | fields `m0` to `m3` | other field names |
| `staging/blk_006a0000_od.cpp:3955` | fields `m_iWordAt00`, `m_iWordAt04`, `m_8`, `m_iThirdValue` | other field names |
| `staging/blk_007c0000_od.cpp:1288` | fields `left`, `right`, `top`, `bottom` | other field names |
| `staging/blk_007e0000_od.cpp:722` | fields `unk00` to `unk0C` | other field names |
| `fallout_shared/sky/moon.cpp:593` | the shared fields, and a default constructor | the unit default-constructs an array of four |
| `tesobjecttree.cpp:1478` | fields `a`, `b`, `c`, `d`, and a default constructor | other field names; the unit default-constructs an array of four |
| `fallout/interface/menus/lockpickmenu.cpp:1340` | the shared fields, and `ScaleVector4` | the unit calls `ScaleVector4` |
| `fallout_shared/bgsprimitive.cpp:882` | no field, the constructor; 1 byte | see below |
| `gamebryo2.2/corelibs/nicollision/nipick.cpp:286` | five `int` fields and a `float`, 24 bytes | another class |
| `fallout_shared/teswater.cpp:1652` | no field, `FUN_004eba90` and `DestroyIfFlagged` | the polymorphic class |
| 14 more sites in `src/bsshader`, `fovatseffectmanager_shader.h`, `blk_00ba0000_o2.cpp` and `blk_00bc0000_o2.cpp` | 1 to 56 bytes | the polymorphic class, or a shell of it |

`bgsprimitive.cpp` holds the function row at `0x004a7800`,
`S::FUN_004a7800`. Its body calls the four-float constructor with four
zeros on `this`, through a cast to a member-only `ImageSpaceEffectParam` of
1 byte. The unit's object is byte-identical on the shared header. It stays
because the object it constructs is `S`, a member-only stand-in whose size
no declaration gives: it moves when `0x004a7800` gets its name.

Besides these, the tree declares classes named `ImageSpaceEffectParam`
inside namespaces: 12 definitions. Those are stand-ins, and the section
"Stand-in classes" covers the ones whose constructor is bound to the
address.

## The member-only declaration

`include/fnv/decl/ImageSpaceEffectParam.h` declared the class with the
constructor and no field. Four units included it. The compiler gave the
class 1 byte there, and the constructor stores 16.

The four units name the class in ten expressions of one form: a placement
new of the constructor into a local variable of another class of 16 bytes.

| Unit | Expressions | Class of the local | Size, alignment | Fields |
| --- | --- | --- | --- | --- |
| `fallout/ai/combat/flameprojectile.cpp` | 2 | `Color4` | 16, 4 | four `float`: `r`, `g`, `b`, `a` |
| `fallout/ai/combat/missileprojectile.cpp` | 1 | `fnv_009b90b0::Color` | 16, 4 | four `float`: `r`, `g`, `b`, `a` |
| `fallout_shared/sky/atmosphere.cpp` | 6 | `fnv_006335d0::Param` | 16, 4 | four `float`: `a`, `b`, `c`, `d` |
| `fallout_shared/tesscriptfunctions.cpp` | 1 | `ScriptQuad` | 16, 4 | four `unsigned int` |

So the constructor wrote inside each local before and after. Each unit now
includes the shared header in the same place; each object is byte-identical
to the object before. Nothing else included the file, and it is removed.
Condition 1 does not apply to a declaration without fields; the measured
size of every receiver stands in for it. That the four locals are objects
of this class is not shown.

In `tesscriptfunctions.cpp` the four floats go into the `ScriptQuad` local,
four `unsigned int`, and the local is copied bit for bit into
`DAT_011fa090`, which other units read only as floats. Writing a `float`
and reading the storage as `unsigned int` breaks the aliasing rules of
C++. It does not miscompile here, because clang-cl runs with relaxed
aliasing, and it is left open. `DAT_011fa090` is declared `const float[8]`
in the generated data, and code writes it, here and in
`bsshader/bsshadermanager.cpp` (around line 4167). That is recorded for the
owner of the variable; this change does not touch it.

## Stand-in classes

On the tip, 81 names that no archive member defines are the constructor
`(float, float, float, float)` of a class other than the global
`ImageSpaceEffectParam`, bound by a recipe row of every requiring unit to
`0x00414430`: 93 pairs of unit and name in 53 units. Four more undefined
names belong to classes of this name and to other addresses; "Not covered"
lists them.

The stand-in census counts 82 names for this class. The 82 are these 81
and `PathDebugRender::DbgColor::DbgColor()`, a default constructor that no
recipe row binds and that the census counts because its class defines a
constructor. It is not a name of `0x00414430`, so it is no candidate here.

The rules page closed the stand-in route at 2277431b8. This change reopens
it for stand-ins with fields, under the storage and identity conditions
below; points 3 and 7 are the new ones.

A stand-in is replaced by the shared class when all of this holds.

1. Every unit that requires the name has a recipe row that binds it to
   `0x00414430`, and the name is accepted in every one of them.
2. The unit can see the shared header: it has no class of its own under
   the global name. Where the unit does not include the header yet, the
   include is added to the include block that follows the unit's
   description comment, and the header must then stand before the first
   use of the stand-in.
3. Storage. By the compiler's record layout in that unit the stand-in and
   the shared class have the same size and alignment, the same fields by
   name, type, offset and access, no base class, no virtual function, and
   the same answers to the triviality questions that decide how an object
   is passed, copied and destroyed. The stand-in declares no member other
   than its fields and the bound constructor.
4. The rules of the stand-in batches of VEGAS-11 hold, except the three
   that only say the stand-in has storage: the stand-in is defined in the
   unit's own file, at file or namespace scope, outside any template and
   any macro; no function signature and no variable with static storage
   names it; nothing derives from it; it is no template argument.
5. Substitution only: the definition leaves, each type name that names the
   stand-in becomes `::ImageSpaceEffectParam`, and nothing else is written
   but the include of point 2. No cast and no member is added.
6. The object proof: the unit, compiled before and after with its own
   command at its own path, gives an object that is equal once the retired
   name is respelled, in its symbol table, every section and every
   relocation; and the compiler's warnings are the same.
7. Identity. All three of these hold for the stand-in: the unit's own
   recipe row binds its constructor to `0x00414430`; its layout and
   triviality equal the shared class's (point 3); and its fields are named
   `r`, `g`, `b`, `a` and the unit uses it as a colour. The shared address
   alone is weak evidence: 84 names bound it before this change and 65
   after, for colours, rectangles and a rotation alike.

The stand-in batches refused every stand-in with a field, because there the
stand-in had no storage to compare. Here the compiler compares it.

19 stand-ins in 16 units were replaced, and 19 names left. The scripts
check points 1 to 6, and with point 3 the field names of point 7. The
colour use was read by hand from each unit's source; the last column gives
it:

| Unit | Stand-in | Used as a colour |
| --- | --- | --- |
| `fallout/ai/actor.cpp` | `ImpactColor` | RGBA constants (blue, red) for an impact marker |
| `fallout/ai/combat/combatmanager.cpp` | `fnv_00991770::RgbaColor` | `arrowColor`, `sphereColor`, `color` of the detection display, passed as `Color4` |
| `fallout/ai/combat/explosion.cpp` | `Color810` | red or green line colour of a debug line |
| `fallout/ai/combat/missileprojectile.cpp` | `UpdateColor` | yellow `debugColor` of a debug line |
| `fallout/ai/combat/projectile.cpp` | `NiColorAP9`, `NiColorAPB` | red, yellow or blue `kColor` of a debug line and sphere |
| `fallout/interface/menus/computersmenu.cpp` | `fnv_00757b70::Color` | white passed to the colour manager's `ApplyToChild` |
| `fallout/interface/menus/hackingmenu.cpp` | `fnv_00765b80::Color84` | read as `NiColor` by `SystemColorManager::GetColor`; white to `ApplyToChild` |
| `fallout/interface/menus/racesexmenu.cpp` | `fnv_007b2b50::ColorB50` | a packed RGB value divided by 255, alpha 1 |
| `fallout/magic/absorbeffect.cpp` | `fnv_008034c0::NiColorAStandIn` | the settings `fAbsorbCoreColorR`, `G`, `B` and `fAbsorbGlowColorR`, `G`, `B`, each with alpha 1; see below |
| `fallout/magic/bhkcharacterlistenerspell.cpp` | `ColorA807` | red colour of a debug octahedron |
| `fallout_shared/facegen/bsfacegenmanager.cpp` | `fnv_00655fa0::RgbaColor` | the hair colour, divided by 255, into `kTintColor` |
| `fallout_shared/sky/sun.cpp` | `fnv_00641830::RgbaColor` | three floats that `FUN_00461110` gives for the sky, with the disc or glare alpha, into a shader property at offset `0x60` |
| `fallout_shared/tempeffects/bstempeffectsimpledecal.cpp` | `Color4`, `DecalColor` | vertex colours of a decal |
| `fallout_shared/tesobjectweap.cpp` | `FireColor` | red or green colour of a debug marker |
| `fallout_shared/tesscriptfunctions.cpp` | `fnv_005d3780::ImageSpaceEffectParam`, `fnv_005d3930::ImageSpaceEffectParam` | red, green and blue divided by 255 into `kColor` |
| `fallout_shared/testerrainlodmanager.cpp` | `fnv_0057de00::FUN_00414430_Color` | `.r`, `.g`, `.b` read into a luminance |

In `absorbeffect.cpp` the colour use rests on the names of the settings
the unit reads into the first three floats. It constructs the stand-in
twice, each time from three settings and alpha 1, and the generated
initializer data of the tree names the settings `fAbsorbCoreColorR`, `G`,
`B` for the first and `fAbsorbGlowColorR`, `G`, `B` for the second. The
unit reads no field of the stand-in. The coordinator accepted the setting
names as the evidence of point 7 for this stand-in.

One stand-in that passes points 1 to 6 stays, by a ruling of the
coordinator. `forenderedmenuracesex.cpp` uses `xColorA` twice. The first
object is a colour: `SystemColorManager::GetColor` fills it. The second,
constructed as `(0, 1, 1, 0)`, is passed to `_Cam_00712e60::FUN_00712e60`,
which copies it into the view rectangle `m_kPort` of a new camera: a
rectangle that the unit builds with the folded constructor. So the unit
does not use the stand-in only as a colour, and point 7 fails. The
generator is given the pair as an exclusion with that reason (the rule
`R-identity`), and refuses it before any trial. The unit, its object and
its recipe key `??0xColorA@@QAE@MMMM@Z` stay as they are; its object is
byte-identical to the object before the change.

- 19 definitions removed and 58 type names respelled. 12 units gained the
  include; 4 had it from the earlier steps.
- All 19 stand-ins had the fields `r`, `g`, `b`, `a`; 15 were declared
  `struct` and 4 `class` with public members.
- 15 existing casts name the shared class afterwards: 12 C-style and 3
  `reinterpret_cast`. None is added.
- 16 objects are equal once the names are respelled; no other object of
  the build changes. In 4 of them (`explosion.cpp`, `projectile.cpp`,
  `bstempeffectsimpledecal.cpp`, `tesscriptfunctions.cpp`) the retired name
  merges into the shared name the object already had, so the symbol table
  is 1 or 2 entries shorter and the indices in the address-significance
  table move; decoded to names, that table is the same.
- `build/units.json`: 19 keys of `symbols` maps leave, in 16 units. 14 are
  respelled to the owner's function-row spelling and 5 are merged into a
  key the unit already had at the address. Nothing else in the file
  changes.

## Stand-ins refused

62 names stay. Each has one cause here, the first that applies in the
order of the table, so the rows sum to the total. The third column counts
the names that have that cause and no other.

| Cause | Names | Alone |
| --- | --- | --- |
| Refused by the ruling above: not used only as a colour (point 7) | 1 | 1 |
| The unit has a class of its own under the global name, so it cannot see the shared header | 22 | 7 |
| The stand-in is not four float fields: an array of four, a base class, a nested class | 6 | 5 |
| Four float fields at the same offsets under other names | 16 | 10 |
| The stand-in declares a member the shared class lacks: a default constructor, an operator, a helper | 11 | 0 |
| A function signature or a variable with static storage names the stand-in | 4 | 4 |
| The shared header would stand after the first use of the stand-in | 2 | 2 |
| Total | 62 | 29 |

The 22 names of the first row are 23 pairs of unit and name in nine
units: `teswater.cpp` (9), `main.cpp` (7), and one each in
`combatgroup.cpp`, `fovatseffectmanager.cpp`, `lockpickmenu.cpp`,
`bgsprimitive.cpp`, `moon.cpp`, `blk_006a0000_od.cpp` and
`blk_007e0000_od.cpp`. The two of the last row are in `tesland.cpp`,
whose copy of the class stood at line 9462, after both stand-ins; the
include took its place there.

### What the next step can yield

The basis is the refusal record of each name: every rule a name failed,
not only the first. Two next steps are in view.

- The default constructor at `0x004a7800` and `ScaleVector4` at
  `0x00532f60` join the header once their owners are settled, and
  `moon.cpp`, `tesobjecttree.cpp` and `lockpickmenu.cpp` move onto it. Of
  the 62 refused names it admits none by itself. The 11 names refused
  first for a member the shared class lacks all carry another cause that
  the step does not remove: 10 are named in a function signature or in the
  type of a variable with static storage, and the eleventh,
  `TESLandInit::LandColor`, stands before the header in `tesland.cpp`; 4 of
  the 11 also declare an operator or a helper the step does not add. Its
  own yield is the 2 undefined names of the class at those addresses (the
  default constructor that `moon.cpp` and `tesobjecttree.cpp` require,
  `ScaleVector4` that `lockpickmenu.cpp`
  requires). Moving the include of `tesland.cpp` before its stand-ins
  would add `Color960` and `NiColorAL53`, refused for that alone, and with
  the default constructor `TESLandInit::LandColor`. The other 20 names at
  the two addresses, besides those two and the two function rows, were not
  looked at and could add to it.
- The scoped identity of the four-float class lets `teswater.cpp`, whose
  own global class is the polymorphic one, see the shared header. 7 names
  of that unit are refused for that alone. They were not checked further,
  because the unit did not compile with the header, so 7 is an upper bound;
  one of them, `fnv_004e21b0::WRect`, is a rectangle by its name and would
  fail point 7.

On this basis the first step yields 2 names, or 5 with the include of
`tesland.cpp` moved, and the second at most 7, or 6 without `WRect`: about
5 to 8 names for the next step, not the 10 to 15 that an earlier estimate
gave by counting the 11 names of the member row as admitted. `xColorA`
is admitted by neither step.

The first step needs the two function rows renamed to the class's names:
`S::FUN_004a7800` in `bgsprimitive.cpp` and
`FUN_00532f60_cls::ScaleVector4` in `tesimagespacemodifier.cpp`. Those row
renames are a later step of their own, reviewed separately; this change
renames no function row.

## Integration checks

Run these on every change that touches the header, the owner, a copy of
the class, or a stand-in bound to `0x00414430`.

(a) Layout per requirer. For every unit whose object requires
`ImageSpaceEffectParam::ImageSpaceEffectParam(float, float, float, float)`
under the global name, have the compiler measure the global class in that
unit with the unit's own command line. It must be 16 bytes with four
`float` fields at offsets 0, 4, 8 and 12. Result on the tip: 22 units, 17
pass. Result after this change: 35 units, 33 pass, 23 of them on the
shared header. The two that do not pass are older than this change:

- `fallout/interface/fovatseffectmanager.cpp` sees the polymorphic class,
  56 bytes with a pointer to a table of virtual functions at offset 0,
  which its header `fovatseffectmanager_shader.h` gives the four-float
  constructor. The unit calls that constructor twice, each time by
  placement new into a local of `Vec4Tmp_00801ad0`: four `unsigned int`,
  16 bytes. The unit's declaration says the object is the 56-byte class;
  the storage the owner's body writes, 16 bytes, is the 16-byte local.
- `fallout_shared/bgsprimitive.cpp`, the 1-byte member-only copy above.

A new exception fails the check. The three exceptions that this change
removes were the units of the member-only file.

(b) One definition. Scan every definition of every external name in every
archive member. The constructor must have exactly one, in the owner's
object, and it must not be select-any. The count of names with differing
definitions in the whole archive may not rise. Result: one definition, in
`imagespaceeffectparam_h_unit.cpp.obj`, as a COMDAT of selection 1, no
duplicates; 525 names with differing definitions before and after, none
entering. The archive defines two symbols as members of the global
`ImageSpaceEffectParam`, each once and out of line: the four-float
constructor in the owner and `DestroyIfFlagged` in `teswater.cpp`. No
member carries a table of virtual functions, an RTTI record or a CodeView
type section under the name.

(c) Recipe. Exactly one function row at `0x00414430`, the owner's, and
every key of a `symbols` map that this change wrote is that row's
spelling; no JSON object of the recipe has a duplicate key. Result: holds;
19 keys changed in 16 units; the row is unchanged.

The three standing checks of `docs/shared-simple-list.md` were run on the
tip and on the result, with that document's guard script, and give the
same results on both. No file of the list changed. (a): 245 pairs of unit
and list in 113 units and 135 lists, 243 pass, the same two recorded
exceptions; the compiler scan of that check was limited to the 221
objects that require a name of `BSSimpleList`, the only units the check
reads. (b): 1,366 defined names of classes named `BSSimpleList`, none with
two definitions; 525 names with differing definitions, none entering; the
two select-any names it names each have one definition, in their unit.
(c): 128 forward declarations of the element list and 12 of the two
instantiation blocks, 0 mismatches.

## Forced link

Forced link of every archive member, windows-x64, 2,225 members in
the same order:

| | 5b1781acf | Header | 7 units | Member-only file | Stand-ins |
| --- | --- | --- | --- | --- | --- |
| Undefined names | 35,185 | the same | the same | the same | 35,166 |
| Left / entered | | 0 / 0 | 0 / 0 | 0 / 0 | 19 / 0 |
| Duplicate symbols | 0 | the same | the same | the same | 0 |
| Imports | 137 | the same | the same | the same | the same |
| Objects that differ from the column before | | 0 | 0 | 0 | 16, by the retired names only |

The first and last columns are full builds from one path and the four
links of each: lazy and forced extraction, each with and without an error
limit. The last column's four links give the same duplicates, imports and
exit codes as the tip's, and the same undefined names but the 19. For the
three middle columns the 24 units whose inputs the series changes were
compiled at the same path with the build's own commands: every object is
byte-identical to the tip's, with the COFF timestamp masked, and every
other object's inputs are unchanged, so those links were not run again.
In the last column every object but the 16 is byte-identical to the tip's.

Each of the 19 names that left was the constructor of a stand-in.
The name the 16 units require instead has one definition, in the owner's
object.

## Not covered

- The name. Two classes share it; the decision above gives it to the
  polymorphic class, and the step that moves the four-float class to a
  scoped identity is still to come.
- Identity. The 19 replaced stand-ins are shown to have this class's
  storage, to be bound to this constructor's address, and to be used as a
  colour. That each of them is this class and not another class of four
  floats with the same field names is INFERRED from point 7. The original
  linker folded all such constructors into one address.
- `xColorA` in `forenderedmenuracesex.cpp`, left by the ruling under
  "Stand-in classes": one stand-in class serves a colour and a rectangle
  in the same unit, and which class each use is stays open.
- Receivers. The owner's body writes 16 bytes through `this`. Check (a)
  measures the requirer's declaration of the class, not the object a call
  passes. Fifteen casts in the 16 units and ten placement expressions in
  the four units of the member-only file construct or name the class in
  storage of another type.
- The aliasing in `tesscriptfunctions.cpp` and the `const` declaration of
  `DAT_011fa090` (see "The member-only declaration").
- The 62 names of "Stand-ins refused", and the sites of "What did not
  move".
- Four undefined names of classes of this name at other addresses: the
  default constructor at `0x004a7800`, required by `moon.cpp` and
  `tesobjecttree.cpp`; `ScaleVector4` at `0x00532f60`, required by
  `lockpickmenu.cpp`; and the default constructor and the destructor of
  `fnv_00b9f780::ImageSpaceEffectParam`, the polymorphic class, required by
  `shadowscenelight.cpp`.
- Of the 20 names at `0x004a7800` and the 4 at `0x00532f60`, only the
  class's own two and the two function rows were looked at.
- Nothing executes these functions. Windows execution: not run.
