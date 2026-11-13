# The real classes the boot functions construct

WinMain (`0x0086a850`), BootInit (`0x0086cf20`), the render set-up
(`0x0086d590`) and three other functions of `src/fallout/misc/main.cpp`
(`0x0086bee0`, `0x00872b00`, `0x00877730`) construct or destroy objects
of twelve real classes through main.cpp's
own copies of those classes. The constructor and destructor names of
those copies are undefined: no object defines them. Binding one of them
to its recipe row needs one declaration of the class that both main.cpp
and the row's unit use, so that the size `new` passes and the fields the
body writes agree. That is the shared-declaration method of
`docs/shared-simple-list.md`, `docs/shared-ni-pointer.md` and
`docs/shared-tesform.md`, with the rule for fields of transcribed classes
of 2026-11-11 (2) on the rules page "Symbol naming and native ownership".

This document records the census of the twelve classes on `1b3b79d69`
(2026-11-13; VEGAS-30, VEGAS-11) and why none of them can be declared yet. No source
changed. Windows execution: not run.

## The twelve names

| Address | Constructed or destroyed in main.cpp as | Recipe row: unit, class | main.cpp's copy, bytes x64 / i686 | Row's class, bytes x64 / i686 |
| --- | --- | --- | --- | --- |
| `0x00938180` | `new PlayerInit` in BootInit | `staging/blk_00920000_od.cpp`, `FUN_00938180` | 3,672 / 3,664 | 3,792 / 3,664 |
| `0x00b5e0f0` | `new fnv_0086d590::FUN_00b5e0f0` in the render set-up | `bsshader/shadowscenenode.cpp`, `FUN_00b5e0f0` | 512 / 512 | 640 / 512 |
| `0x00450770` | `~FUN_00450770()`, called by name in `0x0086bee0`; WinMain's code calls it too | `staging/blk_00440000_od.cpp`, `FUN_00450770` | member-only declaration, non-virtual destructor | 272 / 196, virtual destructor |
| `0x00c46970` | `new fnv_0086d590::FUN_00c46970` | `staging/blk_00c40000_od.cpp`, `fnv_00c46970::FUN_00c46970` | 180 / 180 | 184 / 176 |
| `0x00c503d0` | `new fnv_0086d590::FUN_00c503d0` | `staging/blk_00c40000_od.cpp`, `fnv_00c503d0::FUN_00c503d0` | 184 / 184 | 200 / 184 |
| `0x00a6aa40` | `new fnv_0086d590::FUN_00a6aa40` | `fallout_shared/tesscriptfunctions.cpp`, `FUN_00a6aa40` | 48 / 48 | 72 / 48 |
| `0x008784d0` | `~FUN_008784d0()`, called by name in WinMain on a `Text86` | `fallout/misc/memorymanagerfile.cpp`, `FUN_008784d0` | member-only declaration; the storage is 24 / 24 | 16 / 8 |
| `0x00bc2980` | `new fnv_0086d590::FUN_00bc2980` | `nianimation/nimaterialcolorcontroller.cpp`, `FUN_00bc2980` | 184 / 184 | 184 / 184 |
| `0x00a5ecb0` | `new fnv_0086d590::FUN_00a5ecb0(0)`, six times | `nimain/nibillboardnode.cpp`, `FUN_00a5ecb0_o2` | 172 / 172 | 168 / 160 |
| `0x00872e00` | `static CamWatcher kWatcher` in `MainX::UpdateCamera` | `staging/blk_00860000_od.cpp`, `fnv_00872e00::FUN_00872e00` | 4 / 4 | 192 / 164 |
| `0x00bb8180` | `new fnv_0086d590::BSFogProperty` | `bsshader/bsfogproperty.cpp`, `BSFogProperty` | 100 / 100 | 120 / 100 |
| `0x0049ec80` | `new NiAlphaProperty` in `0x00877730` (main.cpp's typedef: `NiAlphaProperty` for `FUN_0049ec80_Property`; two other copies name it a stencil property) | `staging/blk_00480000_od.cpp`, `FUN_0049ec80` | 56 / 36 | 36 / 36 |

The `nianimation` and `nimain` units are under `src/gamebryo2.2/corelibs/`.
Every other unit is under `src/`. Sizes are the compiler's, in each unit.
At `1b3b79d69` each of the twelve names is undefined in the forced link of
every archive member, and main.cpp is the only unit that requires it.

The main.cpp copies of the render set-up's classes are not polymorphic:
they are rows of 32-bit integers, the same size on both targets. A bound
constructor would write the x64 layout of its own unit into an allocation
of the copy's size. For `PlayerInit` the allocation is 120 bytes short of
the row's class, for the shadow scene node 128 bytes.

The static `CamWatcher`'s destructor,
`fnv_00872b00::CamWatcher::~CamWatcher()`, is undefined as well. It has
no recipe row, and the static local's `atexit` destructor references it,
so binding the constructor alone leaves it open.

## The census

A compiler plugin ran in each of the 2,235 units of the game library with
the unit's own windows-x64 command line, and again with the target
replaced by `i686-pc-windows-msvc`, which gives the 32-bit offsets of the
same declarations. For each class it recorded every definition: size,
alignment, bases, the virtual tables slot by slot, and the layout down to
leaf fields.

The copies of a class are the row's class, every class that a constructor
or destructor key of the recipe binds to the same address, and every
definition of the class's usual names: `PlayerCharacter`, `TES`,
`ShadowSceneNode`, `NiNode`, `NiProperty`, `NiFogProperty` and the
Gamebryo bases `NiAVObject`, `NiObjectNET`, `NiObject` and `NiRefObject`.

Two measures decide whether a layout can be established for x64:

- An offset is undecided when, at the same 32-bit offset, one copy has a
  pointer and another a 4-byte integer, a field or an element of an
  integer array. Byte padding counts as neither. The two copies cannot
  both describe the field, and on x64 a pointer is 8 bytes.
- A placeholder is an integer named only for its offset or as unknown
  (`unk04`, `f5ec`, `field0c`, `pad`), or an integer array. Its 32-bit
  size is known; whether it holds a pointer is not.

A copy is one row of role, unit and class; an owner that a key also
names is counted twice. A member-only copy declares no data member: its
x64 size is 1 (three `NiObject` copies hold a single `char` and count
here). The x64 layouts include the empty layout of member-only
declarations.

| Class | Copies | Member-only copies | x64 layouts | Undecided offsets | Placeholders in the row's class |
| --- | --- | --- | --- | --- | --- |
| `PlayerCharacter` (`0x00938180`) | 104 | 47 | 29 | 71 | 266 of 420 leaves |
| shadow scene node (`0x00b5e0f0`) | 30 | 18 | 7 | 21 | 88 of 130 |
| `TES` (`0x00450770`) | 73 | 68 | 6 | 15 | 32 of 49 |
| `0x00c46970` | 11 | 0 | 6 | 2 | 42 of 44 |
| `0x00c503d0` | 3 | 0 | 3 | 2 | 42 of 46 |
| `NiTexturingProperty` (`0x00a6aa40`) | 7 | 0 | 4 | 2 | 1 of 10, and the `NiProperty` base |
| `0x008784d0` | 4 | 1 | 3 | 0 | 1 of 2 |
| `0x00bc2980` | 2 | 0 | 2 | 0 | 3 of 5 |
| `NiNode` (`0x00a5ecb0`) | 240 | 90 | 45 | 43 | 1 of 3, and the `NiAVObject` base |
| `0x00872e00` | 2 | 0 | 2 | 0 | 36 of 41 |
| `BSFogProperty` (`0x00bb8180`) | 6 | 0 | 6 | 3 | 2 of 24 |
| `0x0049ec80` | 7 | 0 | 4 | 3 | 1 of 4 |

The bases the Gamebryo classes stand on, base first:

| Base | Copies | Member-only copies | x64 layouts | Undecided offsets |
| --- | --- | --- | --- | --- |
| `NiRefObject` | 219 | 21 | 6 | 1 |
| `NiObject` | 219 | 47 | 11 | 7 |
| `NiObjectNET` | 94 | 41 | 9 | 2 |
| `NiProperty` | 68 | 26 | 19 | 4 |
| `NiAVObject` | 203 | 102 | 42 | 47 |

`NiRefObject` is already shared: `include/fnv/ni_ref_object.h`.
`include/NiObject.h`, `include/NiObjectNET.h` and `include/NiProperty.h`
declare a layout and `include/fnv/decl/NiObjectNET.h` member functions
only; none of the four declares a virtual slot of its own class, so none
is a shared declaration under the method. What the bases lack is their
virtual slot tables. For `NiObjectNET`, 35 copies share one layout of
48 / 24 bytes, 32 of them with the same type in every field, and both
undecided offsets come from one copy, `staging/blk_00a40000_o2.cpp`,
which declares `int m_08` and `int m_0c` where the others have the name
and the controller pointer.

## Why each class stops

Under the rule of 2026-11-11 (2) a field is established on x64 when
(a) its order and size come from the owner's declaration, (b) its x64
offset follows from the declared types, (c) every body that disagrees
uses the 32-bit offset of that declaration, and (d) no agreeing body
contradicts it. What stops a class here is the owner's own declaration:
opaque padding or integer arrays, integers named only for an offset
whose x64 width no body has been read for, a table pointer stored by
hand, or a member-only declaration. An undecided offset stops a class
only where the owner's declaration is one side of it (the table's column
counts all of them); other disagreeing copies stay on their copies and
are tabled. By the coordinator's ruling of 2026-11-13, a placeholder
integer is open, not refuted: it becomes established as a 32-bit integer
when rows
other than the constructor use it as a 32-bit value and none stores or
loads an address through it; byte and integer arrays are opaque padding
and never qualify. This census reads declarations only, so it shows
these fields are not established, not that they cannot be. None of the
twelve stops on placeholders alone.

- `PlayerCharacter`. The row's class derives from `Actor122`, which
  derives from six bases; only its unit declares them. It names its
  fields by 32-bit offset. At `0x6b8`
  `include/PlayerCharacter.h` declares `TESQuest* m_pCurrentQuest`, and
  the row's class and main.cpp's `PlayerInit` declare an `int`. 29 copies
  have a pointer where the row's class has an integer.
  `include/PlayerCharacter.h`, which main.cpp itself includes (through
  `main.h`), is a partly typed copy of 4,520 / 3,664 bytes: 41 of its 190
  leaves are placeholders, among them seven `unsigned int` padding arrays
  of 411 integers in all. It is the likelier starting point than typing
  the row's 266 placeholders, but its padding arrays are as opaque as
  theirs.
- The shadow scene node. It derives from its unit's copy of `NiNode`,
  a virtual table and fields `unsigned unk004` onwards, and holds a
  frustum of 41 placeholder integers.
- `TES`. The row's class declares `field04`, `field0c` to `field18`,
  `field24` to `field34` and `field40` to `field64` as `int`.
  `fallout_shared/speedtree/bstreemanager_types_TES.h` declares pointers
  at `0x04`, `0x0c` to `0x18` and others, and three copies begin with a
  table pointer field instead of a virtual table.
- `0x00c46970`, `0x00bc2980` and `0x0049ec80`. The row's class is not
  polymorphic, and its constructor stores the address of a table into the
  object: into the field `void* m_vtbl`, or through `*(void**)this`.
  Declaring the class with its virtual table changes that constructor's
  object, which a declaration move may not do. `0x00bc2980` stands on
  `char _pad[0xAC]` for its `NiNode`, and `0x0049ec80` on
  `unsigned int unk[6]` where main.cpp's copy has three pointers.
- `0x00c503d0`, `NiTexturingProperty`, `NiNode` and `BSFogProperty`. Each
  stands on a `NiNode`, `NiAVObject` or `NiProperty` of its own unit, and
  those bases are undecided at the offsets of the table above.
  `BSFogProperty` is typed throughout except its `NiProperty`, which has
  `unsigned char data[0x4]` and `pad10[0x8]` where the `NiProperty` of
  the `NiProperty.h` that `bsshader/shadowscenenode_fog_decls.h` includes
  inherits the reference count and `NiExtraData** m_ppExtraData`.
- `0x008784d0`. The row's class holds one placeholder `int` for its file
  member. The constructor row's unit, `tesscriptfunctions.cpp`, declares
  the member as an empty class. The class is 16 / 8 bytes in both recipe
  units. main.cpp declares it member-only and constructs it by placement
  in a `Text86` of 24 bytes, so the declarations do not agree on the
  object's size. `tesscriptfunctions.cpp` holds a second 24-byte copy,
  `fnv_005b5e60::FUN_008783c0`, six `unsigned int` placeholders.
- `0x00872e00`. It holds a member declared with 35 placeholder integers.
  The member's own row in the same unit, `0x00872ea0`, declares it with
  the field `void* m_vft`, which its constructor sets. main.cpp's
  `CamWatcher` is one `int`.

## What would let them move

- Eight of the twelve are Gamebryo classes. They need shared declarations
  of `NiObject`, `NiObjectNET`, `NiProperty`, `NiAVObject` and `NiNode`
  first, on top of `include/fnv/ni_ref_object.h`, each with its undecided
  offsets decided.
- `PlayerCharacter` and `TES` need the types of their placeholders, one
  field at a time, under the rule of 2026-11-11 (2).
- The three owner constructors that store a table address by hand
  (`0x00c46970`, `0x00bc2980`, `0x0049ec80`) and the member constructor
  `0x00872ea0` need a body change with its own object proof, under a
  repair ticket (VEGAS-110), not a declaration move.

## Not covered

- In 23 units the i686 compile stopped with errors: size assertions
  written for x64, and declarations that differ between the two targets.
  Their layouts were still measured.
- Stand-ins whose methods the recipe binds to other addresses of these
  classes, and not to the constructor or destructor, are not counted as
  copies.
- The census plugin is not part of the repository, so the counts cannot
  be regenerated from it. A single class can be re-measured with the
  compiler's record-layout dump in the unit.
- The census reads declarations. It does not read what a body does with
  a field, so an offset that every copy declares alike is not shown to be
  right.
