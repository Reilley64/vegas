# A shared declaration of NiPointer

VEGAS-16 owns the Gamebryo units. `NiPointer<T>` is Gamebryo's smart pointer:
one pointer to an object that counts its references. This change gives the
template a declaration that units can share, has the unit that owns
`operator=(T*)` define that member for the element types other units
require, and moves 19 units onto the declaration. It follows the method of
`docs/shared-simple-list.md`, with one departure, the opt-in macro below.

It is a first increment and a small one. Most members of the template have
no function row under the template's name in `build/units.json`, and the
rulings for them are under "Rulings for later steps".

## Where the declaration lives

`include/fnv/ni_pointer.h`, beside `bs_simple_list.h` and `ni_ref_object.h`.

## What it declares

The field `T* m_pObject` and `NiPointer<T>& operator=(T*)`. Nothing else, and
no body.

A member is declared in the header in the commit in which its owner, the
unit with its function row, defines it. Four function rows carry the
template's name:

| Address | Member | Recipe size | Unit with the function row | Declared |
| --- | --- | --- | --- | --- |
| `0x0066b0d0` | `operator=(T*)` | 70 | `nimain/nishader.cpp`, under `NiAVObject` | yes: the unit defines it as a template member |
| `0x00a5f860` | `operator=(T*)` | 66 | `nimain/nismartpointer_h_unit.cpp`, under `NiGPUProgram` | the same member as the row above; this body changes the count in line |
| `0x006e5cc0` | `operator=(const NiPointer<T>&)` | 74 | `nimain/nismartpointer_h_unit.cpp`, under `WaitableObject` | no |
| `0x00b66f20` | `~NiPointer()` | 33 | `nimain/nismartpointer_h_unit.cpp`, under `NiD3DPixelShader` | no |

`nismartpointer_h_unit.cpp` defines each of its three for its own element
type only, as a member of an explicit specialisation, and not as a member
of the template. A unit on the shared header would get no definition of the
destructor or of the copy assignment for another element type, so neither is
declared.

The constructors, the conversion to `T*`, `operator->` and the comparisons
are not declared. Their function rows carry another name, or they have none.

## How the body is provided

`build/units.json` gives `operator=(T*)` one function row at `0x0066b0d0`,
in `nishader.cpp`. 87 units bind a name of the template to that address,
for 60 element types. So the original called this member out of line, at one
address, and `nishader.cpp` is its owner.

- The owner defines the member as a template member. Before, it defined it
  for its explicit specialisation `NiPointer<NiAVObject>`, which leaves
  `nishader_decls.h`. The body text is the same.
- At the end of the owner stands one member-level explicit instantiation per
  element type. It defines that member and no other.
- The body needs the pointee's name and class-key and nothing else: it
  reaches the two count functions through the casts it already had. The
  owner forward declares each pointee with the key the requiring units use.

The 22 instances, the owner's own and 21 more, are 77 bytes with one
content. The owner's own definition was an ordinary external function, with
COMDAT selection "no duplicates", and is select-any now, with the same
bytes. A second definition of that name is no longer a link error: check (b)
is now the only detector.

## The opt-in macro

`include/layout_support.h` holds a body of the template with a body in the
class for every member, and most units of the archive compile it. The owner
cannot define a member out of line against it. So that text stands under
`#ifndef FNV_SHARED_NI_POINTER`, and a unit that defines the macro before
its includes gets `fnv/ni_pointer.h` instead.

This is a departure from the list's method. There the shared header is the
default and a unit that cannot move defines a keep macro. Here the macro is
an opt-in, and `nishader.cpp` is the one unit that defines it. It is
transitional and covers that one unit:

- No second unit may opt in.
- The next step, which the coordinator rules, is the flip: the shared header
  becomes the default for the units on `layout_support.h` that compile and
  keep their objects without the in-class bodies, and the others define a
  keep macro. That step is build-proven on its own, as a declaration move.
  A compiler scan of the reviewed candidate at 2277431b8 found 358 of the
  399 units on that text using no member of an implicit instance; that
  figure is a prediction, not built.

## Element types

The owner emits `operator=(T*)` for an element type when all of these hold.
They are the rules of `docs/shared-simple-list.md` read for one member, and
check (d) below.

- A unit requires the name and no object defines it.
- Every requiring unit has a recipe row that binds the name to
  `0x0066b0d0`.
- The element type is a class, struct or union named at global scope, and
  its name is not a placeholder.
- It is required under one class-key, counted over every name of
  `NiPointer<E>` in the archive.
- Every requiring unit declares `NiPointer<E>` as 8 bytes with one field at
  offset 0 (check (a)).
- No recipe row binds this member of this element type to an address whose
  function row is in another unit.
- In no requiring unit does the declaration of `E` contradict what the body
  does with the pointee (check (d)).

38 undefined names of `operator=(T*)` are bound to `0x0066b0d0` by every
unit that requires them. 21 are emitted:

`AnimIdle`, `BSFaceGenNiNode`, `BSFadeNode`, `BSShaderAccumulator`,
`CameraView`, `DecalNode`, `NiAlphaProperty`, `NiColorData`,
`NiControllerManager`, `NiExtraData`, `NiFloatData`, `NiGeometry`,
`NiGeometryData`, `NiPointLight`, `NiSourceTexture`, `NiTexture`,
`NiTriShape`, `NodeView`, `PathingRequest`, `PathingSolution`, `SceneGraph`.

The 17 that are not:

| Reason | Names |
| --- | --- |
| The pointee is nested in a namespace or in a class | 10 |
| `NiScreenElements`, required as `class` and as `struct`; counted once per key | 2 |
| `TreeCloneView`: its declaration contradicts the body (check (d)) | 1 |
| `Tile`: which class the pointee is was not settled | 1 |
| `NiNode`: `tesobjectcell.cpp` declares the template without a field, 1 byte | 1 |
| The element type is a pointer, `NiNode*` | 1 |
| The pointee has a placeholder name, `FUN_00b668b0` | 1 |

The first two rows are the next yield of this member: shared declarations
of the pointees could admit up to 12 names, the 10 nested pointees and the
2 names of `NiScreenElements`, one per class-key.

`TreeCloneView`. The body passes the pointee to
`WaitableObject::FUN_00401970`, which decrements a 32-bit count at offset 8
and calls virtual slot 1 when it reaches zero, and to
`FUN_0040f6e0_class::FUN_0040f6e0`, which passes the address of offset 8,
`NiRefObject::m_uiRefCount` in its own class, to the count function.
`bstreemodel.cpp` declares `TreeCloneView` without a table pointer, and its
field at offset 8 is `initialized`: `TreeCloneView::CloneFromModel` tests it
and sets it to 2. Binding the name would increment that flag. The name stays
undefined.

`Tile`. `forenderedmenu.cpp` assigns to its `NiPointer<Tile>` a pointer
that a function returns for the player's 3D node, and declares `Tile` as an
empty class. Other declarations of `Tile` in the tree describe the menu
tile, which has no count: `tile_packet_decls.h` puts a child list at offset
8. A VEGAS-11 step left out all 17 rows of `Tile`
(`docs/symbol-naming-batches.md`). The name stays undefined until the
pointee is identified.

`CameraView` and `NodeView` are local views in `forenderedmenu.cpp`
(`NodeView : NiNode`, `CameraView : NiAVObject`). They are emitted because
the rules admit them, as the list's owner emits `ModifierEntryView*`. When
VEGAS-11 replaces either view by an engine class, the same commit respells
that element type in `nishader.cpp`'s forward declarations and
instantiation lines.

## The rule for moving a unit

A unit's own copy of the primary template is replaced by
`#include "fnv/ni_pointer.h"` when both hold:

1. The compiler, in that unit, shows the copy to be compatible: one public
   field `T* m_pObject`, or no field, no base, no member with a body in the
   class, none virtual or static.
2. After the replacement the unit compiles, and its object is byte-identical
   to the object before, with only the COFF timestamp masked.

A copy without a field is a copy of the primary template, not an explicit
specialisation. For it the proof is condition 2 together with one including
unit: the copy is seen by that unit alone, and that unit's object is
unchanged. The unit was also compiled with the copy's default constructor,
copy constructor and destructor deleted, and compiled; that probe is
supplementary.

23 sites were tried, each seen by one unit. 19 moved:

| | Moved |
| --- | --- |
| The field `T* m_pObject`, members declared only | 15 |
| No field: `gridcell.cpp:199`, `tesmodeltextureswap.cpp:289`, `threadsafestructures.cpp:240`, and `ninode_packet_decls.h:56`, which only `ninode.cpp` includes | 4 |

The other four keep their copies. The units use the members the header does
not declare:

| Site | Unit | Why it stays |
| --- | --- | --- |
| `bsshader/lighting30shader_lighting30_factory_types.h` | `lighting30shader.cpp` | Defines a body of `~NiPointer()` (`lighting30shader.cpp:6290`). A unit on the shared header may not define a member body; with the header it does not compile. |
| `fallout/interface/menumanager.cpp:281` | itself | Requires `~NiPointer<NiNode>()`. With the header the destructor is trivial and the object differs. |
| `fallout_shared/pathfinding/navmesh.cpp:2637` | itself | Requires `~NiPointer<NavMesh>()`. The object differs: the call and its cleanup block leave. |
| `fallout_shared/tesnpc_decls.h` | `tesnpc_h_unit.cpp` | Requires `operator=(const NiPointer<NiAVObject>&)`. The object differs. |

So the units on these copies do use the destructor and the copy assignment:
three require one of them and one defines the destructor's body. They stay
on their copies until those members are declared in the commit in which an
owner emits them.

`testopicinfo_topicinfo_layout_support.h` declares `~NiPointer()` as well.
Its one unit, `testopicinfo.cpp`, never calls it, and its object is
byte-identical; it moved.

20 units use the header's declaration: the 19 and `nishader.cpp`.

## What changed in the link

Forced link of every archive member, windows-x64, 2,227 members in the same
order:

| | b93461c52 | Header and owner | 19 units | 21 types |
| --- | --- | --- | --- | --- |
| Undefined names | 35,168 | 35,168 | 35,168 | 35,147 |
| Left / entered | | 0 / 0 | 0 / 0 | 21 / 0 |
| Duplicate symbols | 0 | 0 | 0 | 0 |
| Imports | 137 | the same | the same | the same |
| Objects that differ from the column before | | 1 | 0 | 1 |
| Names with differing definitions in the archive | 519 | 519 | 519 | 519 |

The object that differs in the second column is `nishader.cpp.obj`. Its one
definition of the member changes its COMDAT selection, and its section moves
from the second of the object's ten code sections to the last, because the
explicit instantiation stands at the end of the unit. The bodies are
unchanged. In the fourth column it is the same object, with 21 definitions
added and its ten functions unchanged.

The 21 names are those of the list above, each defined once, by
`nishader.cpp.obj`. No recipe row was added or changed: every requiring
unit already had a row that binds its name to `0x0066b0d0`.
`src/generated` is untouched.

The second to fourth columns were built in the build tree of b93461c52,
from the same path, by rebuilding the units whose files changed. The fourth
was also built fresh: 2,330 steps, none failed, 20,785 warning lines that
are equal to the first column's once line and column are removed, and every
object equal to the one the rebuild made.

## Integration checks

Run these four on every change that touches the header, the owner's list of
element types, a copy of the template, the class-key of a pointee, or the
declaration of a pointee in a requiring unit.

(a) Layout per requirer. For every name that the owner's instantiation
block defines and another object requires, each requiring unit must declare
`NiPointer<E>` as 8 bytes with one field at offset 0, measured by the
compiler with the unit's own command line. Result: 56 pairs of unit and
name, in 42 units and 22 names; 55 pass. The exception is older than this
change and is the only one: `screensplatter.cpp` requires the owner's own
name, `NiPointer<NiAVObject>::operator=`, and declares that instance as an
explicit specialisation without a field, 1 byte
(`screensplatter_decls.h:36`). The owner's body reads and writes 8 bytes
through `this`, so this is a layout defect of that unit, recorded here. A
new exception fails the check.

(b) Differing definitions. No name that the owner's instantiation block
defines may have a second definition in the archive, and the count of names
with differing definitions in the whole archive may not rise. Result: 22
names, one definition each, in `nishader.cpp.obj`, select-any, 77 bytes,
one content; 519 names with differing definitions before and after, none
entering. All 22 are select-any, so check (b) is the only detector of a
second definition. The archive test `archive.differing_definitions` passes
with no name new or stale; it reports a second definition only when its
content differs.

(c) Class-keys. Every forward declaration in the owner's instantiation
block has the key that every symbol of the archive naming `NiPointer<E>`
has, and the owner's definition has. Result: 21 forward declarations, 0
mismatches.

(d) The pointee per requirer. The body passes the pointee to callees that
use a table pointer at offset 0 and a 32-bit reference count at offset 8.
For every element type the owner emits, the unit's own one included, and
every unit that requires its name, the compiler shows the unit's view of
`E`. A pair fails when that view puts a field other than a count at offset
8, or lacks a table pointer at offset 0 with a field there, and the unit's
code references that field. A pair also fails when the unit allocates `E`
with a new-expression and its `sizeof(E)` is under 12 bytes, the end of the
count. Otherwise the check covers named fields only: an access to offset 0
or 8 of the pointee through a cast of `E*` is not checked. The requiring
units hold 501 explicit casts of an emitted `E*`, in 28 units; they were
counted, not read. Result on the 21 new types: 34 pairs in 23 units, none
fails.

| The unit's view of `E` | Pairs |
| --- | --- |
| A count at offset 8 (`refCount`, `refs`) | 4 |
| A table pointer at 0 and no count declared, or an opaque byte array over 8 | 9 |
| No table pointer; an opaque byte array over offsets 0 and 8, not referenced | 7 |
| An empty class, or incomplete in that unit | 13 |
| `lighteffect.cpp`: `NiPointLight` is a 32-bit transcription without a table pointer, `int unk08` at offset 8; the unit references none of its fields | 1 |

The `lighteffect.cpp` row passes because nothing in the unit uses those
fields; it is recorded, and a change that uses them fails the check. For
the owner's own type, 22 pairs, none fails. Allocations: 17 new-expressions
of an emitted `E` in 9 requiring units, the smallest 24 bytes; none is
under 12 bytes. `TreeCloneView` was refused by this check: its one pair
puts `initialized` at offset 8 and references it.

## Rulings for later steps

The coordinator's rulings for what this increment does not do:

- (a2) `operator=(const NiPointer&)` at `0x006e5cc0` may be emitted with a
  cast that does not adjust the pointer, to the class the callee's
  definition is a member of, when all of these hold: the owner's own object
  is unchanged apart from the COMDAT selection; the instances have one
  content; `nismartpointer_h_unit.cpp` gives up its own copy of the primary
  template; check (d) holds for each element type. A later step.
- (b) Members with no recipe row stay local to the unit: no body is put in
  the shared header for them.
- (c) Not admitted at present: emitting a member under the template's name
  at a folded address whose function row carries a placeholder name. The
  rulings keep the names of rows at folded addresses that other classes also
  reach, and the stand-in route closed at 2277431b8. The 147 names of that
  kind stay undefined.

The coordinator's rulings on the questions of the review of this increment:

- Check (d): a complete pointee without a table pointer passes when the
  unit's own code does not rely on offsets 0 or 8 of it.
- The owner's own element type, `NiAVObject`, is in the scope of check (d).
- `tileshader.cpp`'s binding of `NiPointer<NiGPUProgram>::operator=` to
  the specialisation's row at `0x00a5f860` is acceptable as recorded.
  `NiGPUProgram` never enters the owner's list of element types. When (a2)
  takes the primary template out of `nismartpointer_h_unit.cpp`,
  `NiPointer<NiGPUProgram>` stays an explicit specialisation there.
- `Tile` stays unresolved.

## Open

244 undefined names of members of the global template remain, by what the
recipe rows of the requiring units say. Each name has one cause, the first
that applies:

| Cause | Names |
| --- | --- |
| Every requiring unit binds it to a row under the template's name: `operator=(T*)` at `0x0066b0d0` 17 (the list above), `operator=(const NiPointer&)` at `0x006e5cc0` 11, `operator=(T*)` at `0x00a5f860` 1, `~NiPointer()` at `0x00b66f20` 1 | 30 |
| The requiring units bind it to an address whose function row has another name | 147 |
| The requiring units bind it to two addresses | 1 |
| No requiring unit has a row for the name: destructors 49, constructors 8, conversions and `operator->` 7, `operator=(T*)` 2 | 66 |

Of the 347 names of the template in the archive, 103 are defined now, 82
before.

## Not covered

- Receivers. Emitting a name does not show that every requirer passes a
  pointer to a counted object, or that the count functions act on the
  pointee's count. `WaitableObject::FUN_00401970` and
  `FUN_0040f6e0_class::FUN_0040f6e0` are stand-in names of the functions at
  `0x00401970` and `0x0040f6e0`. Check (d) compares declarations, not
  objects passed at run time.
- `screensplatter.cpp`'s 1-byte specialisation (check (a)) and
  `lighteffect.cpp`'s `NiPointLight` (check (d)).
- Allocation size. Some requiring units construct `E` themselves, with the
  size of their own transcription of `E`, while the callees write the real
  x64 layout. The 17 new-expressions, with the unit's size of `E`:
  `lighteffect.cpp` (`NiPointLight`, 252 bytes), `forenderedmenu.cpp`
  (`NiPointLight` 256, `BSShaderAccumulator` 640), `bgsprimitive.cpp`
  (`BSFadeNode` 232, three sites), `main.cpp` (`SceneGraph` 200, three
  sites, one of them in `main.h`), `pathmanager.cpp` (`PathingSolution`
  68, two sites), `animation.cpp` (`NiControllerManager` 124), `moon.cpp`
  (`NiTriShape` 208, two sites; `NiAlphaProperty` 40),
  `nicolorinterpolator_h_unit.cpp` (`NiColorData` 24) and
  `nifloatinterpolator_h_unit.cpp` (`NiFloatData` 24). Check (d) fails only
  an allocation under 12 bytes; a passing check (d) says nothing about
  whether the allocation is as large as the class the callees write. This
  is the same kind of remainder as the storage of `BSAudioDefinition`.
- `tileshader.cpp`, on the shared header, requires
  `NiPointer<NiGPUProgram>::operator=`, which `nismartpointer_h_unit.cpp`
  defines at `0x00a5f860` as a member of its explicit specialisation. The
  binding is older than this change; that object is unchanged. It is
  acceptable as recorded (the rulings above).
- The explicit specialisations of the template, and the copies of the
  primary template that did not move.
- Namespace-scoped templates named `NiPointer`, such as
  `fnv_00b8a1f0::NiPointer`: 80 member names in 28 namespaces, 67 of them
  undefined. They are other classes under the template's name and need
  their own identity first.
- Classes with another name that stand in for the template: 1,449 undefined
  names of other classes and free functions are bound to the template's 21
  addresses.
- `nismartpointer.h` defines `operator=` for `NiPointer<KFModel>` and
  `NiPointer<LoadedFile>`. Their function rows, `0x0044b070` and
  `0x0044b220`, are in `src/unmapped/nismartpointer.cpp` under stand-in
  names.
- Nothing executes these functions. Windows execution: not run.
