# Shared declarations of the Gamebryo base classes

VEGAS-30's boot bodies construct twelve classes, and eight of them stand on
Gamebryo bases that every unit declares for itself;
`docs/boot-real-classes.md` has the census of those classes and the ruling
that the bases go first. VEGAS-11 owns shared declarations. This change
gives the bases one declaration each, base first, by the method of
`docs/shared-simple-list.md` and `docs/shared-tesform.md`: a census of the
copies, a declaration whose every field and slot is shown by the repository
or marked open, and a move of the units whose copies agree, each object
byte-identical and every class of the unit laid out as before.

| Class | Header | Units on it before | Moved | Status |
| --- | --- | --- | --- | --- |
| `NiMemObject` | `include/fnv/ni_mem_object.h` | 101 | 16 copies and 2 private headers, in units that move `NiRefObject` | shared before this change |
| `NiRefObject` | `include/fnv/ni_ref_object.h` | 107 | 31 | shared before this change |
| `NiObject` | `include/fnv/ni_object.h` (new) | 0 | 2 | declared |
| `NiObjectNET` | none | | 0 | decided below; the header waits for its first unit |
| `NiProperty` | none | | 0 | decided below; the header waits for its first unit |
| `NiAVObject` | none | | 0 | stops at the property list |
| `NiNode` | none | | 0 | not reached |

No name leaves the link: every moved object is byte-identical. The step is a
declaration, not a binding.

Everything here was measured on 8cd5b2ee9, windows-x64, in one build tree
made from one export path, and in each commit of the change built in that
tree; the 32-bit columns come from the same units compiled for
`i686-pc-windows-msvc`. The change was then rebased onto 3503a01a1; the
link, the objects, the warnings, the layouts, the slot names, the class
census and checks (a) and (b) below were measured again there, and the
numbers in those sections are 3503a01a1's. Windows execution: not run.

## The census

A compiler plugin ran in each of the 2,237 units of the game library with
the unit's own command line and recorded every global definition of the
seven classes: size, alignment, bases, the layout flattened to leaves, and
the table slot by slot. A copy inside a namespace is another class and is
not counted.

| Class | Definitions | Sites |
| --- | --- | --- |
| `NiMemObject` | 242 | 139 |
| `NiRefObject` | 219 | 98 |
| `NiObject` | 219 | 142 |
| `NiObjectNET` | 94 | 49 |
| `NiProperty` | 50 | 41 |
| `NiAVObject` | 203 | 168 |
| `NiNode` | 151 | 116 |

`docs/boot-real-classes.md` counts 68 copies of `NiProperty`. It counts a
copy per role, unit and class: the 50 definitions above, the same three
definitions again as the class of the three `??0NiProperty@@QAE@XZ` keys
of the recipe, and 15 definitions of the class `FUN_00a5c200` (14 key
units and the owner, `nimemobject.cpp`), because those keys are bound to
`0x00a5c200`, the `NiObjectNET` constructor row (below). This document
counts definitions of the name only.

## The rule for moving a unit

A unit's copy is replaced by an include of the shared header when all hold:

1. Slots and fields. The copy has the shared declaration's size, fields
   (names, types and offsets) and table length, and its slots have the
   shared symbol at every index, OPEN slots included: the same name, the
   same parameters and the same `const`. Only a typedef that names the
   same type counts as the same parameter. This is the rule of
   `docs/shared-tesform.md`, rule 2, without its exception for established
   slots, which no move here needed.
2. Layout. No class that the unit defines changes on windows-x64 or on
   i686: size, alignment, the offsets and types of its fields, the offsets
   of its bases, the number of slots of each table and the owner and symbol
   in each slot, and the set of its functions that override. A class that
   gains or loses an empty base while all of this stays equal passes, and
   is recorded.
3. Bases. The class's bases in that unit are already the shared ones, or
   move in the same commit.
4. Object. The unit compiles on the header, and its object is
   byte-identical to the object before, with only the COFF timestamp
   masked.

Rules 1 and 2 are measured by one comparison: a second plugin records, in
every unit that sees a changed file, every class the unit defines, on
windows-x64 and in the i686 compile, before and after the edit; the moved
class itself is compared like the others, so its copy's slots are what the
header's must equal. Rule 4
covers what the comparison does not see, such as a call that binds another
overload.

The edits are made by a script from the census: every replaced copy is the
text from its class-key to the closing `};`, and nothing else in the file
changes, except where a private header defines `NiMemObject` under the
shared header's include guard (below). A copy in a header is replaced for
every unit that sees it, and each such unit must pass. The script adds the
units it refuses back to their copies and repeats until no unit fails.

## `NiRefObject`

The declaration in `include/fnv/ni_ref_object.h` is unchanged. Its owner is
`nirefobject_lifetime.cpp` (`docs/native-list-node-lifecycle.md`).

| Part | x64 | 32-bit | Evidence |
| --- | --- | --- | --- |
| table pointer | 0, 8 bytes | 0, 4 bytes | the table below |
| `m_uiRefCount`, `unsigned int` | 8 | 4 | the count functions the shared `NiPointer` binds read a 32-bit count after the table pointer (`docs/shared-ni-pointer.md`, check (d)) |
| slot 0, deleting destructor | | | `??_7NiRefObject@@6B@` is bound to `0x0101dce4` by 8 units; the generated table there holds `0x004968e0` |
| slot 1, `DeleteThis` | | | the same table holds `0x00cfcc20`, the row `NiRefObject::DeleteThis` of `nirefobject.cpp` |

31 units moved. 20 of them first saw their own empty `NiMemObject`,
through 16 copies (`niobject_nimemobject.h` is seen by five of the units),
which `ni_ref_object.h` includes; those copies moved in the same commit. Two
more, `processlists.cpp` and `navmesh_loadsave.cpp`, had a private header
that defined the same empty class under the shared header's include guard,
`FNV_NIMEMOBJECT_H`, so the shared header was skipped in those units; the
whole body of each of those two headers, guard included, is now the
include. Six more files of the tree use that guard for their own copy of
the class; their units did not move.

The 31 units saw 27 copies. 10 of them had no `NiMemObject` base and now
have the empty one, which the compiler places after the table pointer, at
x64 offset 8 and 32-bit offset 4. In each of those 10 units every class
keeps its size, field offsets, base offsets and slots on windows-x64 and
in the i686 compile; the comparison covers all of them, not a sample.
`ninode.cpp` declared its `NiMemObject` as a `struct`; the shared header
declares it as a `class`. Its object is byte-identical.

Three copies (`niunionbv.cpp`, `nid3dpixelshader.cpp`,
`nid3dpixelshader_copies_039.cpp`) defined the constructor, destructor and
`DeleteThis` inline and declared the count protected; `ninode.cpp`'s
declared a member `SetParent`, and `particleshaderproperty.cpp`'s declared
`IncRefCount` without a body. None is used in those units: the objects are
identical.

6 moved units, `niunionbv.cpp`, `nid3dpixelshader.cpp`,
`nid3dpixelshader_copies_039.cpp`, `niavobject_inl_unit.cpp`,
`niobject_h_unit.cpp` and `teslandtexture.cpp`, did not include
`<windows.h>` before; `ni_ref_object.h` does, so each now also defines
about 1,275 classes of the SDK headers that it did not define before. No
class it defined before changes, and the objects and warnings are the same.

The 219 definitions:

| Outcome | Units |
| --- | --- |
| Already on the shared header | 107 |
| Moved | 31 |
| Rule 1: another size: 1 byte, members only (21), 8 bytes, a table pointer and no count (12), 4 bytes, no table pointer (1) | 34 |
| Rule 1: another field layout: the count `signed` (22, five of them under another name), or the table pointer that of a polymorphic `NiMemObject` (3) | 25 |
| Rule 1: another table: one slot (8), two slots under other names (4), no table (2), three slots (1) | 15 |
| Rule 2: a class of the unit changes layout: `fnv_00b6bbd0::NiPixelData` in `bsshaderutil.cpp` (x64: its first own field moves from 16 to 20; i686: every field moves by 4, 116 bytes become 120), `NiPixelData` in `bsshadermanager.cpp` (144 to 152 bytes on x64, 116 to 120 on i686), and `NiRefObject` itself in `modelloader.cpp`, whose `NiMemObject` has a field | 3 |
| Rule 4: the object differs; each copy has no `NiMemObject` base (`nid3dshaderprogramfactory.cpp`, `blk_00a80000_o2.cpp`, `blk_00cc0000_o2.cpp`, `teswater.cpp`) | 4 |

`bsshaderutil.cpp` keeps its copy. Its `NiPixelData` derives from
`NiRefObject` and from an empty `NiMemObject` of its own namespace. With the
shared `NiRefObject`, which has the global `NiMemObject` as an empty base,
the compiler places that second base one byte later (x64 16 to 17, i686 8
to 9), and every field after it moves. `bsshadermanager.cpp`'s
`NiPixelData` does the same with the global `NiMemObject`.

138 units now see the shared `NiRefObject` (107 + 31).

## `NiObject`

`include/fnv/ni_object.h`, new.

Fields: none of its own. The constructor row `0x00a5d3a0`
(`niloddata.cpp`) stores the table address into the object and nothing
else, and the owner rows of `NiObjectNET` reach its first field at x64
offset 16, the end of `NiRefObject` (below).

The table: the constructor row stores `&DAT_0109b4f4`, and the generated
table `?DAT_0109b4f4@@3HA` has 35 entries. Slots 0 and 1 are the ones of
`NiRefObject`: slot 1 holds `0x00cfcc20`, `DeleteThis`. The header declares
the 33 virtual functions that fill slots 2 to 34. The `NiObjectNET`
constructor row stores a table of the same 35 entries with that class's
overrides, `?DAT_0109b244@@3PEAEEA` (generated as `C7B0ObjectNET`).

Every one of the 33 is OPEN. No row that these tables hold is a function
under `NiObject`'s name: the entries are rows under stand-in names, most of
them shared by many classes (`0x00acbb70` fills sixteen slots). The four
rows under `NiObject`'s name (`0x00621a40`, `DynamicCast` at `0x00653290`,
`0x00c21cb0`, `0x00c61f30`) are in no slot. So the names and parameters are
the spelling that the two moved copies used, and the header says so.
Nothing may be concluded from them; a body may not be given one of those
names because of the header. Their indices are fixed by the table.

In the `NiObjectNET` table, slots 19, 20 and 26 hold the owner's rows
`NiObjectNET::LoadBinary` (`0x00a5c080`), `LinkObject` (`0x00a5c0e0`) and
`ProcessClone` (`0x00a5b8f0`), the names the header gives those slots. The
slots stay open in `NiObject`: what `NiObject`'s own table holds there,
`0x00a5d610`, `0x00a89af0` and `0x00a5d430`, are stand-in rows of other
units.

| Slot | Declared | `NiObject` table: entry, unit of its function row | `NiObjectNET` table |
| --- | --- | --- | --- |
| 0 | `~NiObject` (deleting) | `0x00a5d4e0`, blk_00a40000_o2.cpp | `0x00a5c7b0` |
| 1 | `DeleteThis` (`NiRefObject`) | `0x00cfcc20`, nirefobject.cpp | inherited |
| 2 | `GetRTTI` | `0x00529530`, imagespacemodifierinstance.cpp | `0x00a5c230` |
| 3 | `IsSceneNode` | `0x00acbb70`, impactmixer.cpp | inherited |
| 4 | `IsFadeNode` | `0x00acbb70`, impactmixer.cpp | inherited |
| 5 | `IsMultiBoundNode` | `0x00acbb70`, impactmixer.cpp | inherited |
| 6 | `IsGeometry` | `0x00acbb70`, impactmixer.cpp | inherited |
| 7 | `IsTriBasedGeometry` | `0x00acbb70`, impactmixer.cpp | inherited |
| 8 | `IsTriStrips` | `0x00acbb70`, impactmixer.cpp | inherited |
| 9 | `IsTriShape` | `0x00acbb70`, impactmixer.cpp | inherited |
| 10 | `IsSegmentedTriShape` | `0x00acbb70`, impactmixer.cpp | inherited |
| 11 | `IsResizableTriShape` | `0x00acbb70`, impactmixer.cpp | inherited |
| 12 | `IsParticlesGeom` | `0x00acbb70`, impactmixer.cpp | inherited |
| 13 | `IsLineGeometry` | `0x00acbb70`, impactmixer.cpp | inherited |
| 14 | `IsBhkNiCollisionObject` | `0x00acbb70`, impactmixer.cpp | inherited |
| 15 | `IsBhkBlendCollisionObject` | `0x00acbb70`, impactmixer.cpp | inherited |
| 16 | `IsBhkRigidBody` | `0x00acbb70`, impactmixer.cpp | inherited |
| 17 | `IsBhkLimitedHingeConstraint` | `0x00acbb70`, impactmixer.cpp | inherited |
| 18 | `MakeClone` | `0x00a44840`, blk_00a40000_o2.cpp | inherited |
| 19 | `LoadBinary` | `0x00a5d610`, blk_00a40000_o2.cpp | `0x00a5c080` |
| 20 | `LinkObject` | `0x00a89af0`, blk_00a80000_o2.cpp | `0x00a5c0e0` |
| 21 | `RegisterStreamables` | `0x00a5d2f0`, blk_00a40000_o2.cpp | `0x00a5c180` |
| 22 | `SaveBinary` | `0x00a89af0`, blk_00a80000_o2.cpp | `0x00a5c5b0` |
| 23 | `IsEqual` | `0x00a5d470`, blk_00a40000_o2.cpp | `0x00a5c820` |
| 24 | `GetViewerStrings` | `0x00a5d6e0`, blk_00a40000_o2.cpp | `0x00a5ca80` |
| 25 | `AddViewerStrings` | `0x004534f0`, tes.cpp | inherited |
| 26 | `ProcessClone` | `0x00a5d430`, blk_00a40000_o2.cpp | `0x00a5b8f0` |
| 27 | `PostLinkObject` | `0x00a89af0`, blk_00a80000_o2.cpp | `0x00a5c6a0` |
| 28 | `StreamCanSkip` | `0x00ee8990`, niobbleaf.cpp | inherited |
| 29 | `GetStreamableRTTI` | `0x00a5d310`, blk_00a40000_o2.cpp | inherited |
| 30 | `SetObjectBound` | `0x004534f0`, tes.cpp | inherited |
| 31 | `GetBlockAllocationSize` | `0x00e7cd40`, nitexturingproperty.cpp | inherited |
| 32 | `GetGroup` | `0x00e7cd40`, nitexturingproperty.cpp | inherited |
| 33 | `SetGroup` | `0x00a89af0`, blk_00a80000_o2.cpp | inherited |
| 34 | `IsControllerManager` | `0x00acbb70`, impactmixer.cpp | inherited |

Every slot is OPEN except slot 1, which `NiRefObject` declares and
`nirefobject_lifetime.cpp` defines.

The constructor and destructor are declared, without a body: an implicit
one would let a unit emit a compiler-made body under a name such as
`??0NiObject@@QEAA@XZ`. The constructor row `0x00a5d3a0` and the deleting
destructor in slot 0, `0x00a5d4e0`, keep their stand-in names. The two moved
copies left both implicit; their objects are the same with them declared.

The other rows under `NiObject`'s name are not declared, because their
owners are not on the header. A member joins when its owner moves.

2 units moved: `nitransformdata.cpp` and `nipsysrotationmodifier.cpp`.
Their copies are the header's text, slot for slot. Neither object defines
or requires a table, deleting destructor, constructor, destructor or
locator of `NiMemObject`, `NiRefObject` or `NiObject`, or any name of the
33 open slots.

The six other copies with 35 slots on the shared `NiRefObject` keep their
copy. The slots where the copy's symbol differs from the header's:

| Unit | Copy | Slots that differ |
| --- | --- | --- |
| `niavobject_inl_unit.cpp` | `niavobject_types.h` | 30: takes a `FourComponentFloatVector*` (24 and 25 take `NiViewerStringsArray*`, a typedef of the same type, and agree) |
| `niblendtransforminterpolator.cpp` | `niblendtransforminterpolator_NiObject.h` | 24 and 25: take `NiTPrimitiveArray<const char*>*` |
| `teslandtexture.cpp` | `teslandtexture_decls.h` | 24 and 25: take a `NiViewerStringsArray*` of a class of that name |
| `lighting30shader.cpp` | `lighting30shader_lighting30_factory_types.h` | 3 (`IsNiNode`); 18 to 22, 26 and 27 take pointers where the header takes references |
| `NiRenderedTexture.cpp` | `NiRenderedTexture.h` | 32 of the 33 open slots (all but 28): another spelling (`GetType`, `GetNiNode`, ..., `Unk_20`, `Unk_21`, `GetControllerManager`), pointers for references, other `const` |
| `imagespaceshaderparam.cpp` | its own text | the same 32 slots, the same spelling as `NiRenderedTexture.h` |

`teslandtexture.cpp` and `lighting30shader.cpp` declare a virtual destructor,
as the header now does; the other four leave it implicit. In each of the
six units the derived classes' tables change with the slots, so rule 2
refuses them as well.

| Outcome | Units |
| --- | --- |
| Moved | 2 |
| Rule 1: slots differ (the six above, and `processlists.cpp`, `interface.cpp`, `niblendinterpolator.cpp` at 24 and 25, `nifloatextradatacontroller.cpp` at 32 slots; the last four also fail rule 4) | 10 |
| Rule 1: another table. 82 units see 2 slots, 62 of them through `include/NiObject.h`, 5 through `niobject_declarations.h`, which `niobject_h_unit.cpp`, the owner of `DynamicCast`, includes; 13 see 1 slot, 4 none, the others 3 to 55 | 114 |
| Rule 1: 1 byte, members only | 47 |
| Rule 1: 8 bytes (40 units, `fadermanager.cpp` among them), or another size (5) | 45 |
| Rule 3: the unit's `NiRefObject` is not the shared one, its count is `signed` (`nicamera.cpp`) | 1 |

`include/NiObject.h` declares `NiObject` as a polymorphic class with the
two slots of `NiRefObject` and none of its own. It is a copy that disagrees
with the table, and its 62 units stay on it.

### The forward declarations of the header

The header declares the classes its slots name before it, with the
class-keys of the moved copies except for `BSFadeNode` (below). For four of
them the moved copies' key is the tree's minority, counted over the lines
of `src/` and `include/` that define or forward-declare the name:

| Name | Header | `class` lines | `struct` lines |
| --- | --- | --- | --- |
| `BSFadeNode` | `struct` | 53 | 213 |
| `BSMultiBoundNode` | `class` | 27 | 30 |
| `bhkNiCollisionObject` | `class` | 21 | 40 |
| `bhkRigidBody` | `class` | 29 | 48 |

clang-cl mangles a class by the key of its definition when the unit
defines it, and by the key of its first declaration otherwise.
`-Wmismatched-tags` is not enabled by the game's command lines
(`docs/shared-tesanimgroup.md`), so nothing warns. Both moved units define
`struct BSFadeNode`, so slot 4 is
`?IsFadeNode@NiObject@@UEBAPEAUBSFadeNode@@XZ` in both, and the header
declares the name as a `struct` to match. The other three names are
defined by neither unit and keep the class key of the moved copies; by the
archive's symbols that key is the only one in use for `BSMultiBoundNode`,
`bhkNiCollisionObject` and `bhkRigidBody`. A unit that defines one of the
forward-declared classes with the other key gets another symbol in that
slot. The layout comparison prints types without their class-key and does
not see this, so check (a) also compares the mangled names of the 33 slots
across the units on the header.

## `NiObjectNET`: decided, the header waits for its first unit

No unit can move onto a shared `NiObjectNET` today, so no header is
written. The decided declaration, for the commit in which a unit can move:

```cpp
struct NiObjectNET : public NiObject
{
  public:
    NiObjectNET();
    virtual ~NiObjectNET();
    NiFixedString m_kName;
    NiTimeController* m_pControllers;
    NiExtraData** m_ppExtraData;
    unsigned short m_usExtraDataCount;
    unsigned short m_usMaxSize;
};
```

| Field | Type | x64 | 32-bit | What the rows do with it |
| --- | --- | --- | --- | --- |
| `m_kName` | `NiFixedString` | 16 | 8 | `LoadBinary` (`0x00a5c080`) passes the address at 16 to the stream's readers; `0x00a5c820` compares the handles at 16 of two objects; `0x00a5c290` copies the handle |
| `m_pControllers` | `NiTimeController*` | 24 | 12 | `AddController` (`0x00a5c400`), `0x00a5c050`, `ProcessClone` and `LinkObject` read and store the pointer at 24 and count its references by hand |
| `m_ppExtraData` | `NiExtraData**` | 32 | 16 | `ResizeExtraData` (`0x00a5bba0`) allocates, moves and stores the array at 32; `ProcessClone` (`0x00a5b8f0`) walks it |
| `m_usExtraDataCount` | `unsigned short` | 40 | 20 | `ResizeExtraData` reads and clears 16 bits at 40 |
| `m_usMaxSize` | `unsigned short` | 42 | 22 | `ResizeExtraData` compares and stores 16 bits at 42 |

The field spelling is the owner's, `niobjectnet_decls.h`: the controller is
a raw `NiTimeController*` whose references the owner counts by hand, not
the `NiPointer<NiTimeController>` of `include/NiObjectNET.h` and of most
copies. The order and sizes are those of the owner's declaration and of
every 48-byte copy; the x64 offsets are the ABI consequence, and the
owner's x64 bodies use exactly them, which is agreement, not separate
evidence. The same holds for the i686 column of the rows that agree: it is
the same source compiled for that target. The independent 32-bit evidence
is the four stale rows, whose literal offsets 8, 12, 16, 20 and 22 are the
declaration's 32-bit layout.

The fields are ESTABLISHED: every function row under the class's name and
the copy of every unit whose copy has fields was compared on windows-x64
and in the i686 compile. Each row, from its x64 object and from the same
unit compiled for i686:

| Row | Unit | x64 offsets used | i686 | Reading |
| --- | --- | --- | --- | --- |
| `0x00a5b8f0` `ProcessClone` | `niobjectnet.cpp` | controllers 24, array 32, count 40 | 12, 16, 20 | agrees |
| `0x00a5bba0` `ResizeExtraData` | `niobjectnet.cpp` | array 32, count 40, max 42 | 16, 20, 22 | agrees |
| `0x00a5c050` | `niobjectnet.cpp` | controllers 24 | 12 | agrees |
| `0x00a5c080` `LoadBinary` | `niobjectnet.cpp` | name 16 | 8 | agrees |
| `0x00a5c0e0` `LinkObject` | `niobjectnet.cpp` | controllers 24, array 32, count 40, max 42 | 12, 16, 20, 22 | agrees |
| `0x00a5c400` `AddController` | `niobjectnet.cpp` | controllers 24 | 12 | agrees |
| `0x00a5bca0` (`FUN_00a5bca0_shell::SetExtraDataName`; the owner's recipe entry also names it `NiObjectNET::AddExtraData`) | `niobjectnet.cpp` | count 40, then calls `0x00a5ba40` | 20 | agrees; a member of a class derived from the owner's copy |
| `0x004393e0` `SetFlags` | `niobjectnet.cpp` | none: calls `0x00439360` | none | no evidence |
| `0x0043b480` `GetNumChildren` | `niobjectnet.cpp` | none: calls another class's row | none | no evidence |
| `0x00a57240` `RefreshExtraData` | `niobjectnet.cpp` | pointers at 0x2c and 0x3c, then calls `NiAVObject::GetExtraData` | 0x2c, 0x3c | raw offsets past the 24-byte 32-bit class: a row of a derived class. Defect |
| `0x00a5b990` `DeleteExtraData` | `nitexture.cpp` | array 16, count 24 | 16, 20 | its copy (`nitexture_match.h`) puts 16 opaque bytes before the array, the 32-bit size of what precedes it: right on i686, stale on x64. Defect |
| `0x00a5bf50` | `niswitchnode.cpp` | count at raw 0x14 | 0x14 | the 32-bit offset of the count on windows-x64 and in the i686 compile; on x64 it lies inside the name. Defect |
| `0x00439360` | `bgsautowater.cpp` | 16 bits at raw 0x18, read, masked and written | 0x18 | no field of the class on windows-x64 or in the i686 compile: inside the controller pointer on x64, past the 24-byte class on i686. Defect |
| `0x0049edb0` | `bgsautowater.cpp` | as `0x00439360`, into which it is inlined | 0x18 | as `0x00439360` |
| `0x00439340` | `blk_00420000_od.cpp` | none: tail call of `0x00439360` | none | no evidence |
| `0x00533fb0` | `blk_00520000_od.cpp` | none: tail call of `0x00439360` | none | no evidence |
| `0x00a5c200`, the constructor (`FUN_00a5c200`) | `nimemobject.cpp` | table pointer stored in 4 bytes at 0, name 8, controllers 16, array 24, counts 32 and 34 | 0, 8, 12, 16, 20, 22 | `NiObject` laid out as 8 bytes on x64; right on i686. Defect |
| `0x00a5ba40` (`Holder`) | `blk_00a40000_o2.cpp` | array 16, counts 24 and 26 | 16, 20, 22 | its copy has four `int`s before the array: right on i686, stale on x64. Defect |
| `0x00a5c290` | `niobjectnet.cpp` | name 16, controllers 24, array 32, count 40 | 8, 12, 16, 20 | agrees |
| `0x00a5c820` | `niobjectnet.cpp` | name 16, controllers 24, array 32, count 40 | 8, 12, 16, 20 | agrees |
| `0x00a5be90`, `0x00a5bfa0`, `0x00a5c480` | `niobjectnet.cpp` | array 32, count 40; array 32, count 40; controllers 24 | 16, 20; 16, 20; 12 | agree; members of classes derived from the owner's copy |

The last seven rows are not defined under the class's name; they use the
class. `0x00a5bca0` is listed with the member rows because the owner's
recipe entry binds `NiObjectNET::AddExtraData` to it. They read the fields
by member name through the owner's declaration, which is agreement by
construction, not evidence. Rows of other units that reach the fields
through casts at raw offsets are found only when a row above leads to
them.

The copies with fields are 18 sites in 40 units. 14 sites have the five
fields at the decided offsets on windows-x64 and in the i686 compile;
among them are the owner's, `include/NiObjectNET.h` (23 units,
`nimultitargettransformcontroller.cpp` among them), `fnv_a3d_camera.h`
(`nicamera.cpp`, which spells the name and the controller as raw
pointers) and `globalfunc_decls.h` (a copy without the base, which
declares the reference count itself). `blk_00c40000_od.cpp`
has no copy with fields; its stand-in `FUN_00c5e010_Object` declares the
controller at 24 (x64) and 12 (i686), and the unit's function
`FUN_00c5e010` reads it at 24 on x64, which agrees. Four copies do not have
the fields:
`tilerect_copies_004.cpp` and `bsfadenode_decls.h` hold opaque bytes,
`nitexture_match.h` and the `Holder` of `blk_00a40000_o2.cpp` are the stale
copies of the two defect rows above. The owner's own copy is 200 bytes,
the five fields followed by padding and an array of another class.

A row that uses a stale 32-bit layout of the same declaration is a defect,
and the fields stay established (the `TESForm` precedent). The defects are
repaired by body first, under VEGAS-16, and then respelled per address
under VEGAS-11: the four stale-layout rows `0x00a5c200`, `0x00a5ba40`,
`0x00a5b990`, `0x00a5bf50`, the raw-offset rows of derived classes
`0x00439360` (with `0x0049edb0`) and `0x00a57240` with the forwarders
`0x004393e0`, `0x00439340` and `0x00533fb0`, which are respelled with
`0x00439360`, and the three `??0NiProperty@@QAE@XZ` keys bound to
`0x00a5c200`, whose body stores `&DAT_0109b244`, the `NiObjectNET` table,
so the binding names the wrong class. The VEGAS-16 step first decides
which derived class owns `0x00439360` and `0x00a57240`.

The table `?DAT_0109b244@@3PEAEEA` has 35 entries: `NiObject`'s, with the
owner's rows in slots 0, 19 to 24, 26 and 27, six of them under stand-in
names, and a row of `nimemobject.cpp` in slot 2. So the class adds no
virtual function. The owner's own copy declares `LoadBinary` and
`LinkObject` in slots 27 and 28, which the table contradicts; the owner
stays on its copy. The overrides are declared in the header when the owner
moves.

Why no unit can move:

| Outcome | Units |
| --- | --- |
| Rule 1: the controller is `NiPointer<NiTimeController>`, not the owner's raw pointer (`nitransformdata.cpp`, the only 48-byte copy whose `NiObject` is shared) | 1 |
| Rule 3: the unit's `NiObject` or `NiRefObject` is not the shared one (`NiRenderedTexture.cpp`, `imagespaceshaderparam.cpp`, `interface.cpp`, `niblendtransforminterpolator.cpp`, `niavobject_inl_unit.cpp`, `nicamera.cpp`) | 6 |
| Rule 1: another table: 26 units see 2 slots, 23 of them through `include/NiObjectNET.h`; one 4, one 27 | 28 |
| Rule 1: another size: 1 byte with members only (41), or 8 (11), 16 (2), 32 (3), 56 (1) or 200 (1) bytes | 59 |

`imagespaceshaderparam.cpp`'s copy also spells the five fields otherwise.

## `NiProperty`: decided, the header waits for its first unit

- Fields: none. The property constructors allocate `0x1c` bytes, call the
  `NiObjectNET` constructor row `0x00a5c200`, store their own table and
  write their first field at 32-bit offset `0x18`, the end of
  `NiObjectNET` (`0x00a5ceb0` and `0x00a5cef0` in `nialphaproperty.cpp`).
- Slots: 37. The tables of `NiAlphaProperty` (`??_7FUN_004391c0@@6B@`) and
  `NiTexturingProperty` (`??_7FUN_00a6aa40@@6B@`) have 37 entries each and
  hold the same row, `0x00a5d7c0`, in slot 36: `niproperty.cpp`'s
  `PropHack00a5d7c0::UpdateControllerChain`. Slot 35 holds a different
  entry in each. Both slots are OPEN. In slots 0 to 34 the two tables
  differ from `NiObjectNET`'s in slots 0, 2 and 18 to 24, where each holds
  its own class's rows, and agree with it in the others. No table of
  `NiProperty` itself was found: no constructor row of the class stores
  one.

The two copies with 37 slots on a 48-byte `NiObjectNET` are in
`niavobject_inl_unit.cpp` and `interface.cpp`, whose `NiObject` copies stay
(above). 10 units see `include/NiProperty.h`, on the two-slot `NiObject`.

## `NiAVObject`: where it stops

The class starts at 32-bit offset `0x18`, after `NiObjectNET`. Its owner
rows in `niavobject.cpp` are 32-bit transcriptions that use raw 32-bit
offsets on windows-x64, so each is a stale-offset body. What they show,
with the copies counted over the 203 definitions of the class, at their
32-bit offsets:

| 32-bit offset | Copies: pointer / integer | Use in the rows read | Decision |
| --- | --- | --- | --- |
| `0x18` | 19 / 9 | `0x00a59d00` stores a `NiNode*` there and calls the old value's slot 58 | a pointer to the parent node |
| `0x1c` | 19 / 9 | the constructor row `0x00a5aa20` releases a counted object there | a counted pointer |
| `0x20` | 19 / 6 | `0x00a59dc0` frees the old value through the memory manager and stores a pointer | a pointer |
| `0x24` | 11 / 6 | `0x00a59f00` and `0x00a5a170` walk list nodes from there | the head of a list |
| `0x28` | 11 / 6 | none: `volatile int m_28` in the constructor row, the list's tail pointer in 11 copies | UNDECIDED |
| `0x2c` | 1 / 16 | `0x00a5a170` tests it as a count | a count |

It stops at `0x24` to `0x2c`: the property list. Its type, a list of counted
property pointers, has no shared declaration, and its middle field has no
use in the rows read. A row that adds or removes a property through the
list's tail would decide `0x28`; the list's own declaration would decide the
field's type. `NiAVObject`'s table was not found either: the constructor
row `0x00a5aa20` stores none.

`NiNode` derives from `NiAVObject` and was not examined further.

## What changed in the link

Two code commits. Forced link of every archive member, windows-x64, with
`user32.lib` (the cell command of the 891a44f50 baseline), 2,237
members in the same order at every commit:

| | 3503a01a1 | `NiRefObject` | `NiObject` |
| --- | --- | --- | --- |
| Undefined names | 35,030 | 35,030 | 35,030 |
| Left / entered | | 0 / 0 | 0 / 0 |
| Duplicate symbols | 0 | 0 | 0 |
| Imports | 133 | the same | the same |
| Objects that differ from the tip's, timestamp masked | | 0 | 0 |
| Names with differing definitions in the archive | 519 | 519 | 519 |

The other three cells, and the four cells without `user32.lib`, have the
same undefined names, duplicates and imports at every commit.
`NiObject::NiObject`, the virtual `NiObject::~NiObject` and
`NiObject::GetType` are undefined before and after. The warnings of every
rebuilt object are those of the tip. Every definition of every external
name in the archive has the same defining object, COMDAT selection and
content. The boot-closure model is unchanged. No recipe row changes and
`src/generated` is untouched.

## Integration checks

Run these on every change that touches a shared header named here, a copy
of one of the classes, or a unit on a header.

(a) Layout per unit. The census, with each unit's own command line, finds
`NiRefObject` and `NiObject` defined at the shared headers in every unit
this document lists as moved, with the layout and table above. And in
every unit that sees a changed file, every class the unit defines has, on
windows-x64 and in the i686 compile, the size, alignment, field offsets
and types, base offsets, slots (count, owner and symbol of each) and
overrides it had before. And the 33 slots of `NiObject` have the same
mangled names in every unit on `fnv/ni_object.h` and in a file that only
includes the header, compiled with a moved unit's command line. Result on
the last code commit: the census finds `NiRefObject` at
`fnv/ni_ref_object.h` in 138 units and `NiObject` at `fnv/ni_object.h` in
2, every moved unit among them, and `NiMemObject` at `fnv/ni_mem_object.h`
in 132. The 31 units that see a changed file define 48,500 classes on
windows-x64 and 48,141 on i686, and none of them changes on windows-x64
or in the i686 compile; 10 gain the empty base, and 6 units define
classes they did not define before (`<windows.h>`, above). The 33 slot
names are the same in the two units and in the header-only file.

(b) Differing definitions. No name of the four classes may enter the set of
names with differing definitions, and the count of that set may not rise.
Result: 519 names before and after, the same names. 10 of them are names
of these classes before and after: `NiRefObject`'s table and deleting
destructor, and type information of `NiMemObject`, `NiRefObject` and
`NiObject` that copies which differ emit. Every name of the four classes
has the same definitions, by object, selection and content, as at the
tip. Today `??_7NiObject@@6B@`, `??_GNiObject@@UEAAPEAXI@Z` and
`??_R4NiObject@@6B@` each have one definition, from the two-slot copy in
`nicolordata_h_unit.cpp`. The first unit on `fnv/ni_object.h` that emits
`NiObject`'s table will add a 35-slot definition of those names, which
differs, and this check fails on it: a move that emits the table is a
binding of the table, not a declaration move. The type information of
`NiRefObject` is emitted in several variants before and after this change,
because copies with and without the `NiMemObject` base remain; a move that
would change that variant is refused (rule 4).

The standing checks of `docs/shared-simple-list.md` and
`docs/shared-string.md` hold on the last code commit. Check (b) of both
was run on the archive: 1,382 defined names of `BSSimpleList` classes and
6 of `BSStringT<char>`, none with two definitions; the `BSStringT<char>`
destructor has one definition, in `tesobjectacti.cpp.obj`; the same as at
the tip. Checks (a) and (c) of both were not run again as their own
scripts: they read the archive's symbols and the requiring units'
declarations, every object is byte-identical to the tip's, and in the 31
units that see a changed file every class, the `BSSimpleList` and
`BSStringT` instantiations among them, keeps its layout on windows-x64 and
in the i686 compile.

## Not covered

- Receivers and lifetimes. A move shows one declaration; it does not show
  that the objects the moved units handle are of these classes, or anything
  about their lifetimes.
- The open slots of `NiObject` and `NiProperty`, and the overrides of
  `NiObjectNET`, which wait for their owners.
- The defect rows of `NiObjectNET` and the stale-offset rows of
  `NiAVObject`.
- The 62 units on `include/NiObject.h` and the 23 on `include/NiObjectNET.h`:
  copies that disagree with the tables.
- Copies in a namespace: they are other classes under the same name.
- The layout comparison prints types without their exception specification
  and without class-keys, and compares classes by name within one unit; a
  class defined twice in a unit is compared by its order of appearance.
- Nothing executes these functions. Windows execution: not run.
