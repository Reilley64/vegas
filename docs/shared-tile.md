# One shared declaration of Tile: measurement and design

VEGAS-17 owns the `bsmenu` units, and criterion 2 of VEGAS-11 asks for one
declaration of every class that units share. This document measures every
definition of the user interface class `Tile` and designs its shared
declaration. Step 1 is done: the owning unit, `tile.cpp`, now declares one
real class in its own header. It is described under "The owner's class".
No shared header is written and no other unit moves yet. The rulings that
step 1 applied, and what stays open, close the document.

The census of copies was measured on 2277431b8, and the views of the owning
unit on f0ed64652, whose code is the same, for the windows-x64 build
target, with the build's own command line for each unit. Step 1 was
built and checked on 15297e447. Sections that describe the owning unit
before step 1 say so. Offsets and sizes are the
compiler's, in bytes, for windows-x64.

## What was measured

- 2,223 units are in the game archive. The include closure of 661 has the
  word `Tile`. 81 see a file that defines a class named `Tile` in any scope.
- 77 units see a definition of the global class `Tile`. Two of the other four
  have no global `Tile` (`bgsmenupacker.cpp`, `bgsautowater.cpp`), and two
  have a forward declaration only (`modelloader.cpp`, `blk_00440000_od.cpp`).
  A unit without a definition cannot name a member, so the 77 are all the
  units that can require or define a name of the class.
- The 77 definitions fall into 46 classes of equal declarations: the same
  key, bases, fields, members and nested names. 38 of the 46 serve one unit.
- By record layout they fall into 17 classes.

| Shape of the copy | Units | Sizes |
| --- | --- | --- |
| Member declarations only: no field, no base, no virtual function | 46 | 1 |
| Virtual functions and no field | 11 | 8 |
| Virtual functions and fields | 6 | 16, 64, 80, 96 (3 units) |
| Fields, a pointer field at offset 0, 96 bytes | 3 | 96 |
| Fields, other | 11 | 4, 8 (5 units), 56, 112, 592 (3 units) |

`include/fnv/decl/Tile.h` is one of the 46 member-only copies. Five units
use it: `lovetestermenu.cpp`, `mediaset.cpp`, `blk_00700000_od.cpp`,
`blk_00760000_od.cpp` and `blk_007a0000_od.cpp`.

## The owning unit

This section describes the unit before step 1.

`build/units.json` gives `src/bsmenu/tile.cpp` 151 function rows. Seven
carry a member name of `Tile`. Other units hold four more rows under the
class's name, and one symbol row uses the class's name for a function row
that has another name:

| Address | Member | Recipe size | Unit with the function row | Units whose object requires the name |
| --- | --- | --- | --- | --- |
| `0x00700320` | `void Set(int, int)` | 34 | `bsmenu/tile.cpp` | 50 |
| `0x00715c60` | `void Set(int, unsigned int)` | 49 | `bsmenu/tile.cpp` | 8 |
| `0x0071aa80` | `bool GetSpeechChallengeFailure()` | 17 | `bsmenu/tile.cpp` | 6 |
| `0x00a01530` | `static float GetInterfaceScale()` | 10 | `bsmenu/tile.cpp` | 33 |
| `0x00a03c60` | `bool IsMenuRendered()` | 36 | `bsmenu/tile.cpp` | 0 |
| `0x00a04620` | `void SetSpeechChallengeFailure(bool)` | 23 | `bsmenu/tile.cpp` | 2 |
| `0x00a0bae0` | `bool IsPointInside(float, float)` | 15 | `bsmenu/tile.cpp` | 0 |
| `0x00a0bb00` | `static bool IsSpecialTileName(const char*)`, private | 77 | `bsmenu/tile_h_unit.cpp` | 0 |
| `0x00707e10` | `void SetName(const char*)` | 28 | `fallout/interface/interface.cpp` | 10 |
| `0x006faa90` | `void SetNodeFloat(float)` | 59 | `staging/blk_006e0000_od.cpp` | 0 |
| `0x00a216b0` | `bool FUN_00a216b0(float, float)` | 811 | `bsmenu/radialtile.cpp` | 0 |
| `0x007e7850` | `void UpdateEffectChanges(Tile*)` in one unit's symbol row; the function row is `PerkMenuX::UpdateEffectChanges(ValueTile*)` | 545 | `fallout/interface/menus/traitmenu.cpp` | 1, not defined |

The other 144 function rows of `tile.cpp` carry other names: free functions
and members of stand-in classes. 89 units bind 194 distinct names to those
144 addresses.

`tile.cpp` takes its definition of `Tile` from
`src/bsmenu/tile_packet_decls.h`. `tile_copies_002.cpp` and
`tile_copies_003.cpp` use the same text.

| Offset | Field | The owning unit references it |
| --- | --- | --- |
| 0 | `void* m_pVtbl` | no |
| 8 | `TileChildListStorage m_kChildren`: two pointers and a count | yes |
| 32 | `TileValueArrayStorage m_kValues`: two pointers and two counts | yes |
| 56 | `TileNameStorage m_kName`: a pointer and two 16-bit lengths | yes |
| 72 | `Tile* m_pParent` | yes |
| 80 | `void* m_spNode` | yes |
| 88 | `unsigned int m_uiFlags` | yes |
| 92 | `char unk34` | no |
| 93 | `bool m_bSpeechChallengeFailure` | yes |
| 94 | `char tileUnknown36[492]` | no |
| 586 | `unsigned short floatFlags` | no |

The class is 592 bytes there. It is incomplete, and the unit contradicts it:

- It has no base, no virtual function, no constructor and no destructor. A
  pointer field stands at offset 0 in place of the virtual table pointer.
- Its three storage structs are not the member classes. A comment in the
  header says the unit casts their addresses to the list, array, string and
  pointer types it uses.
- Nothing in the unit references the last two fields. In a 32-bit layout
  the tail puts `floatFlags` at `0x222`, which is the offset of
  `LoadingMenu::floatFlags` in the same header.
- 27 classes of the unit derive from it (counted in the text), and the unit
  reaches their member functions through casts.
- The unit holds three more views of the same object:

| View in `tile.cpp` | Size | What it is |
| --- | --- | --- |
| `::Tile` | 592 | the definition above |
| `FUN_009ff340` | 64 | the class whose destructor is the function row at `0x009ff340`; virtual destructor, a base with three `int` fields, fields of 32-bit `int` |
| `fnv_00a00c20::Tile3D` | 64 | the base of the six classes that the function at `0x00a00c20` creates by type; virtual destructor, fields of 32-bit `int` |
| `fnv_00a09410::EvalTile` | not measured | seven virtual functions and eleven `int` fields before the flags |

  The function at `0x00a00c20` allocates 64 bytes for `TileRect`, 72 for
  `TileMenu`, 80 for `TileImage`, `TileText` and `FUN_00a21660`, and 104 for
  `FUN_00a0bc80`. The fields the unit accesses through `::Tile` reach offset
  93.

## The views of the object in the owning unit

Measured on f0ed64652, whose code is that of 2277431b8, with the build's
own command line for `tile.cpp`. A clang plugin reads every record that an
explicit pointer cast or a derivation connects to `::Tile`, and every field
access through such a record in each function row. The same text is also
measured for the 32-bit target, which is the layout the transcriptions were
written against. A field of a view agrees when its windows-x64 offset is the
offset of the `::Tile` field that starts at the same 32-bit offset, and is
stale when it is not. The windows-x64 instructions of the object were then
searched for each access: 220 of the 224 accesses have a memory operand of
the measured size at the measured displacement. The other four have no
operand there, because the optimiser folds or merges them.

- 80 of the 151 function rows touch the object: they access a field
  through a view, or name a view as receiver, cast target or call object.
- 47 rows access 224 fields. 34 records are layout views of the object, and
  30 of them have at least one stale field.
- `::Tile` itself is used by 20 rows. Each of its accesses agrees, because
  `::Tile` is the reference.
- 21 rows make 104 stale accesses. One more row, `TileV::FUN_00a0b420` at
  `0x00a0b420`, reads 8 bytes at offset 600, past the 592 bytes of `::Tile`:
  `TileV` derives from `::Tile` and then declares the fields of a
  standalone 32-bit view, `unk00` at 0 and the child list head at 4.

### The two 64-byte views

`FUN_009ff340`, the class of the destructor row at `0x009ff340`, and
`fnv_00a00c20::Tile3D`, the base of the six classes that the function at
`0x00a00c20` creates, are both the 32-bit layout of `Tile` with every pointer
field spelt as a 4-byte `int`:

| 32-bit offset | `::Tile` field (windows-x64 offset) | `FUN_009ff340` field (windows-x64 offset) | `Tile3D` field (windows-x64 offset) |
| --- | --- | --- | --- |
| 0 | table pointer (0) | table pointer (0) | table pointer (0) |
| 4 | child list head (8) | `int unk00` (8) | `int unk04` (8) |
| 8 | child list tail (16) | `int unk04` (12) | `int unk08` (12) |
| 12 | child count (24) | `int e.unk00` (16) | `int unk0c` (16) |
| 16 | value array table pointer (32) | `int m10.unk00` (20) | `int unk10` (20) |
| 20 | value array data (40) | `int m10.unk04` (24) | `int unk14` (24) |
| 24 | value array size (48) | `int m10.unk08` (28) | `int unk18` (28) |
| 28 | value array capacity (52) | `int m10.unk0c` (32) | `int unk1c` (32) |
| 32 | name string (56) | `int m20.unk00` (36) | `int unk20` (36) |
| 36 | name lengths (64) | `int m20.unk04` (40) | `int unk24` (40) |
| 40 | parent (72) | `int m20.unk08` (44) | `int unk28` (44) |
| 44 | node pointer (80) | `m2c.m_obj`, a pointer (48) | `int unk2c.value` (48) |
| 48 | flags (88) | `unsigned int flags` (56) | `int unk30` (52) |
| 52 | two bytes (92, 93) | | `int unk34` (56) |
| 56 | | | `int unk38`, data of the derived classes (60) |

Every field after the table pointer is stale on windows-x64. The views are
stale 32-bit layouts, not layout evidence.

### Rows with stale accesses

| Address | Function | View | Accesses | Stale |
| --- | --- | --- | --- | --- |
| `0x009ff340` | `FUN_009ff340::~FUN_009ff340` | `FUN_009ff340` | 8 | 8 |
| `0x00a00b50` | `TileObject::FUN_00a00b50` | `TileObject` | 3 | 2 |
| `0x00a00c20` | `fnv_00a00c20::FUN_00a00c20` | `FUN_00a0bc80`, `TileText` (on `Tile3D`) | 4 | 4 |
| `0x00a01750` | `TileA01::FUN_00a01750` | `TileA01` | 1 | 1 |
| `0x00a033b0` | `fnv_00a033b0::C00a033b0::FUN_00a033b0` | `R_Tile` | 7 | 7 |
| `0x00a037e0` | `UpdateTreeNode::FUN_00a037e0` | `UpdateTreeNode` | 5 | 4 |
| `0x00a03c90` | `FUN_00a03c90_shell::FUN_00a03c90` | `TileMenu` | 1 | 1 |
| `0x00a03f70` | `fnv_00a03f70::FUN_00a03f70_shell::FUN_00a03f70` | `TileParent_00a03f70` | 1 | 1 |
| `0x00a040a0` | `sa040a0::Owner::IsAllChildrenFlag0` | `sa040a0::Owner` | 1 | 1 |
| `0x00a04640` | `RenderTile::FUN_00a04640` | `RenderTile` | 54 | 54 |
| `0x00a07580` | `fnv_00a07580::FUN_00a07580` | `TileResult_00a07580` | 2 | 2 |
| `0x00a07690` | `FUN_00a07690` | `FlaggedTile` | 5 | 5 |
| `0x00a07a40` | `ClipTile::FUN_00a07a40` | `ClipTile` | 4 | 3 |
| `0x00a080d0` | `FUN_00a080d0` | `FadeTile` | 1 | 1 |
| `0x00a087d0` | `FUN_00a087d0_shell::FUN_00a087d0` | `::Tile`, `TileFlags_00a087d0` | 23 | 1 |
| `0x00a08a20` | `SceneNodeOwner::FUN_00a08a20` | `SceneNodeOwner` | 2 | 2 |
| `0x00a09410` | `fnv_00a09410::EvalValue::FUN_00a09410` | `EvalTile` | 2 | 2 |
| `0x00a0b020` | `A0B020Tile::FUN_00a0b020` | `A0B020Tile` | 3 | 1 |
| `0x00a0b1f0` | `A0B1F0Tile::FUN_00a0b1f0` | `A0B1F0Tile` | 1 | 1 |
| `0x00a0b520` | `TileWork::FUN_00a0b520` | `TileWork` | 3 | 2 |
| `0x00a0bbf0` | `FUN_00a0bbf0::~FUN_00a0bbf0` | `TileBaseA0BBF0` | 1 | 1 |

The destructor at `0x009ff340` reads and writes the flags at 56 instead of
88, passes the node pointer from 48 instead of 80, and destroys the value
array at 20 and the name at 36 instead of 32 and 56. Its deleting
destructor frees 64 bytes. Slots 7 and 8 read the node pointer at 56 and 48
instead of 80.

### The creation function

`FUN_00a00c20` creates one of six types by a type number. Each constructor
starts with the base constructor. The text calls it as
`fnv_00a00c20::Tile3D::Tile3D`, a name with no key. The symbols map of
`tile.cpp` binds `Tile3D::Tile3D` to `0x00709860`, whose function row is
in `tile3d_h_unit.cpp`.

| Type number | Created type | Bytes allocated on windows-x64 | Bytes in the 32-bit layout of the same text |
| --- | --- | --- | --- |
| `0x385` | `TileRect` | 64 | 60 |
| `0x386`, `0x38a` | `TileImage` | 80 | 72 |
| `0x387` | `TileText` | 80 | 76 |
| `0x388` | `FUN_00a0bc80` | 104 | 80 |
| `0x389` | `TileMenu` | 72 | 64 |
| `0x38c` | `FUN_00a21660` | 80 | 72 |

Every created object is a `Tile` and needs the 94 bytes that the fields of
`::Tile` reach, plus the type's own fields. All six allocations are smaller
than that, and five are smaller than the 94 bytes alone. The writes of the
function itself are stale too: `FUN_00a0bc80` clears its own two fields at
60 and 64, inside the name of `Tile`, and passes the node pointer at 48. The
lazy link of the game does not load the object of `tile.cpp`, so no program
that links today contains this code.

## The owner's class

Step 1 is done for `tile.cpp`. The unit takes `Tile` from
`src/bsmenu/tile_class.h`, its own header, and holds no other view of the
object's destructor, creation or slots 7 to 9. The shared header under
`include/fnv/` is the next step.

### Layout

| Offset | Member | Bytes |
| --- | --- | --- |
| 0 | the compiler's table pointer | 8 |
| 8 | `TileChildListStorage m_kChildren`: head, tail, count | 24 |
| 32 | `TileValueArrayStorage m_kValues`: table pointer, data, size, capacity | 24 |
| 56 | `TileNameStorage m_kName`: string, two 16-bit lengths | 16 |
| 72 | `Tile* m_pParent` | 8 |
| 80 | `TileNodeStorage m_spNode`: one pointer | 8 |
| 88 | `unsigned int m_uiFlags` | 4 |
| 92 | `bool m_bFlagAfterUiFlags` | 1 |
| 93 | `bool m_bSpeechChallengeFailure` | 1 |

The class is 96 bytes with alignment 8, and 56 bytes with alignment 4 for
the 32-bit target. The header asserts the size and each offset for
windows-x64. Each field is established as the rulings of this step define
it: the declared types and their order give the offset, and every access of
`tile.cpp` through the class agrees with it. At the last commit 23 rows
make 95 accesses through `Tile` and all agree. The byte at 92 is never
accessed. It takes the type and name that the other copies give it, which
leaves the object unchanged. The size is the end of
`m_bSpeechChallengeFailure`, 94, rounded up to the alignment. Nothing in
`tile.cpp` accesses the object between 94 and 592, so the padding of the
old copy is gone.

The four storage structs stay. `tile.cpp` casts their addresses to the
list, array, string and pointer types it uses. Their destructors are
declared in the header, not inline, and defined inline in `tile.cpp`, from
the bodies of the removed view's members. They run in the order of that
view. The shared header has to take the definitions with it, because a
unit that includes the header and destroys a `Tile` needs them.

`tile_packet_decls.h` keeps the 592-byte copy for `tile_copies_002.cpp` and
`tile_copies_003.cpp`, which include it alone. Their objects are unchanged
apart from the timestamp. They move with the shared header.

### Virtual slots

| Slot | Member of `Tile` | Body | Evidence for the slot |
| --- | --- | --- | --- |
| 0 | `~Tile()` | `0x009ff340`, `tile.cpp` | the function row, and the table at `0x0106ed9c` that the body stores |
| 1 | `void Init(Tile*, const char*, Tile*)` | none | `TileMenu::Init`, `TileImage::Init` |
| 2 | `NiNode* CalculateNode()` | none | `TileMenu::CalculateNode` |
| 3 | `int GetType()` | none | `TileMenu::GetType`, `TileImage::GetType` |
| 4 | `const char* GetImageTag()` | none | `TileImage::GetImageTag` |
| 5 | `bool IsPointInside(float, float)` | `0x00a0bae0`, `tile.cpp` | slot 5 of `??_7TileMenu@@6B@` |
| 6 | `Tile* SetTraitValue(int, float, const char*)` | none | `TileMenu::SetTraitValue`, `TileImage::SetTraitValue` |
| 7 | `void FUN_00a0b020()` | `0x00a0b020`, `tile.cpp` | slot 7 of `??_7FUN_00a21660@@6B@` |
| 8 | `TileShaderProperty* FUN_00a0b1f0()` | `0x00a0b1f0`, `tile.cpp` | slot 8 of both |
| 9 | `void ApplyAlphaAndColorToChildren(NiNode*, float, void*)` | `0x00a0b280`, `tile.cpp` | slot 9 of both |

The deleting destructors in slot 0 of the two generated tables show only
that slot 0 is a destructor. The body of `~Tile` is identified by its
function row and by the table it stores.

A slot with a body keeps the name of its function row; only the class and
the virtual key change. A slot without a body takes the name of a derived
class's override that a function row carries, by the rule of the most
defining rows. These names are provisional until the coordinator records
them in the override table. Slot 4 is `GetImageTag` by that rule, while
the copies of `Tile` in `tilemenu.h`, `tilemenu_private.h`,
`tileimage_private.h`, `tileimage_private_decl_tileimage.h` and
`tile3d.cpp` spell it `GetTypeStr`. Slots 1 to 4 and 6 are declared
virtual, without a body and not pure: the repository does not show which
function the table of `Tile` holds in them. Slots 2, 3 and 4 are the three
of ruling R3. Slots 1 and 6 are added for the same reason: no table holds
`FUN_009ff600_shell::InitTile` at `0x009ff600` or
`UpdateTreeNode::FUN_00a037e0` at `0x00a037e0`, whose parameters are those
of slots 1 and 6, so neither is respelled. The object of `tile.cpp`
requires the five names. `Init`, `GetType` and `SetTraitValue` were
already undefined, required by `tile3d.cpp` and `tilemenu.cpp`;
`CalculateNode` and `GetImageTag` are new.

### The table at `0x0106ed9c`

`tile.cpp`'s key for `0x0106ed9c` is `??_7Tile@@6B@` from the commit that
makes `0x009ff340` the destructor of `Tile`, the commit in which the object
starts to emit that table. Both ends of the object's life store it. The
destructor row at `0x009ff340` stores it: the object's relocation names the
table of the destructor's class, and `tile.cpp`'s key binds it to
`0x0106ed9c`. The base constructor stores it too. Its row at `0x00709860`
is in `tile3d_h_unit.cpp`, whose object stores `??_7Tile3D@@6B@`, and that
unit's key binds the name to `0x0106ed9c`. `src/generated` has no table at
that address, so its ten slot addresses are not shown. `tile.cpp` is the
only object that defines `??_7Tile@@6B@`. `tile3d_h_unit.cpp` keeps
`??_7Tile3D@@6B@`.

### The derived classes of the creation function

The six classes that `FUN_00a00c20` creates derive from `Tile`. Where the
class's own unit declares its fields, the types of that declaration decide
the x64 size, not the 32-bit view. The compiler measured each unit's
declaration:

| Class | Fields after `Tile` in `tile.cpp` | Size | Owning unit's declaration |
| --- | --- | --- | --- |
| `TileRect` | `bool m_bTextureLoaded` at 96 | 104 | `tilemenu.h` (in `tilemenu.cpp`): the same, at 96, 104 bytes. `tilerect.h` declares the same field, but on a base of `0x34` padding bytes: there it is at 64 and the class is 72 bytes |
| `TileMenu` | `Menu* pMenu` at 104 | 112 | `tilemenu.h`: the same, at 104, 8 bytes, 112 bytes. `tilemenu.cpp` reads it as 8 bytes at 104 |
| `TileImage` | `float fScale` 96, `NiPointer<NiTexture> spTexture` 104, `NiPointer<TileShaderProperty> m_spShaderProperty` 112, `bool m_bTextureLoaded` 120 | 128 | `tileimage.cpp`: the same offsets, 128 bytes |
| `FUN_00a21660` | none | 128 | `radialtile.cpp` declares no field; its `TileImage` there is an 8-byte view, which shows nothing about the size. The 32-bit allocation of the same text is 72 bytes, equal to `TileImage`'s |
| `FUN_00a0bc80` | `int` 96, `int` 100, two 16-byte strings at 104 and 120 | 136 | `blk_00a00000_od.cpp`: the same types, but after its 64-byte `Tile3D` view, so there at 64, 68, 72 and 88 and 104 bytes |
| `TileText` | four `int` from 96, one byte at 112 | 120 | not established: `tiletext.cpp` declares no field. The fields reach the byte the function writes at 112 |

Every allocation now covers `Tile` and the class's fields:

| Type number | Created type | Bytes on windows-x64, before | After | 32-bit layout of the same text |
| --- | --- | --- | --- | --- |
| `0x385` | `TileRect` | 64 | 104 | 60 |
| `0x386`, `0x38a` | `TileImage` | 80 | 128 | 72 |
| `0x387` | `TileText` | 80 | 120 | 76 |
| `0x388` | `FUN_00a0bc80` | 104 | 136 | 80 |
| `0x389` | `TileMenu` | 72 | 112 | 64 |
| `0x38c` | `FUN_00a21660` | 80 | 128 | 72 |

The function clears `TileMenu::pMenu` with an 8-byte store at 104. Before,
a 4-byte store at 64 left the high half of the pointer unset, and
`~TileMenu` and `TileMenu::SetTraitValue` test the whole pointer.
`TileImage::Init` at `0x00a1f6e0` writes `fScale` at 96, resets the
pointer at 104 and writes the byte at 120. All three stores now fall inside
the 128 bytes allocated; before, the byte at 120 was past the 80. The
32-bit sizes are unchanged, so this is a windows-x64 repair. The
evidence of the change has the instruction table of the function: each
allocation size and each store, with its reason.

Where an owning unit's own declaration sits on a stale base view, as in
`tilerect.h` and `blk_00a00000_od.cpp`, that unit keeps its copy and the
difference is listed under "Open items".

### Derived tables

`tile.cpp` emits four derived tables. The 2026-11-11 (2) ruling asks, for
each, whether the generated table at the recipe address confirms its slots.

| Table in `tile.cpp` | Address | Generated table | Slots |
| --- | --- | --- | --- |
| `TileMenu` | `0x0106ed44` | `??_7TileMenu@@6B@` in `vtables_0106.cpp` | 5, 8 and 9 confirmed: the base's bodies. Slots 1 to 4, 6 and 7 hold TileMenu's own functions, so `tile.cpp`'s `TileMenu` declares them without a body |
| `TileRect` | `0x0106ed70` | none | unconfirmed |
| `TileText` | `0x01094878` | none | unconfirmed |
| `FUN_00a0bc80` | none in the recipe | none | unconfirmed |

TileMenu's overrides in the generated table, and the names `tile.cpp`
gives them:

| Slot | Function row | Name in the recipe | Override in `tile.cpp` |
| --- | --- | --- | --- |
| 1 | `0x00a1ef30` | `TileMenu::Init`, `tilemenu.cpp` | `TileMenu::Init` |
| 2 | `0x00a1f140` | `TileMenu::CalculateNode`, `tilemenu.cpp` | `TileMenu::CalculateNode` |
| 3 | `0x00709a40` | `TileMenu::GetType`, `tilemenu.cpp` | `TileMenu::GetType` |
| 4 | `0x00709a50` | `TileMenu::FUN_00709a50`, non-virtual, `interface.cpp` | `TileMenu::GetImageTag` |
| 6 | `0x00a1f160` | `TileMenu::SetTraitValue`, `tilemenu.cpp` | `TileMenu::SetTraitValue` |
| 7 | `0x00a1f310` | `TileMenuStub::FUN_00a1f310`, `tilemenu.cpp` | `TileMenu::FUN_00a0b020` |

An override must have the name of the slot it overrides, so slots 4 and 7
take the base's names, not the rows' names. The classes of the creation
function are in the namespace `fnv_00a00c20`, as the recipe's keys for
their tables spell them, so the six names are new undefined names of that
namespace. Without these declarations the table would bind slot 7 to
`Tile::FUN_00a0b020` and slots 1 to 4 and 6 to the base's names, which the
generated table contradicts. Before this series, `tile.cpp`'s `TileMenu`
derived from `Tile3D` through `TileRect` and had one virtual slot, the
destructor.

The recipe also has rows of `TileRect::Init` at `0x00a1f370`,
`TileRect::GetType` at `0x00709960` and `TileText::GetType` at
`0x00a0bbd0`. Without a generated table it is not shown which slots of
those tables hold them, so `tile.cpp` does not declare them. Their slots
bind undefined names of the base, so nothing binds to a wrong body.

### What changed per commit

Every row named below keeps its address, size and unit. A script kept
outside the repository respelled the names and checked that every label's
slot comes from the generated table itself. Code that changes is listed by
instruction in the evidence of the change; each changed run of
instructions has a reason.

| Commit | Respelled | Changed code | Forced unlimited link |
| --- | --- | --- | --- |
| The class | `IsPointInside`: row, key, label in `vtables_0106.cpp` | `TileV::FUN_00a0b420` read the child list head at 600, now at 8 | 35,224 undefined names, unchanged |
| Slot 7 | `FUN_00a0b020`: row, label in `vtables_0109.cpp` | node pointer at 80, was 56 | +1: `tilemenu.cpp`'s call of `A0B020Tile::FUN_00a0b020` |
| Slot 8 | `FUN_00a0b1f0`: row, labels in both | node pointer at 80, was 48 | unchanged |
| Slot 9 | `ApplyAlphaAndColorToChildren`: row, key, labels in both | none | unchanged |
| The destructor | row; in `tile.cpp` the handler key, `FUN_0057c730`'s parameter, the table key of `0x0106ed9c`, and the key of `FUN_009ff690` merged with the row's own name; the destructor key of five other units | flags at 88, was 56; node pointer at 80, was 48; values at 32, was 20; name at 56, was 36; delete size 96, was 64 | 0: three names leave, three enter |
| Creation | `tile.cpp`'s key of `0x00709860` | allocation sizes, store widths and offsets, funclets and deleting destructors at the new sizes; TileMenu's table holds its six overrides | +5: `Tile3D`'s constructor and destructor leave; `Tile::Tile` and the six overrides enter |
| The byte at 92 | none | none: the object is identical apart from the timestamp | unchanged |

The +1 of the slot 7 commit is admitted by the 2026-11-11 respelling rule:
every symbols key of the old name is respelled in the same commit or left
honestly undefined. `tilemenu.cpp`'s call was bound correctly by address
before: `0x00a1f310` is TileMenu's slot 7 override, and it calls the base's
body at `0x00a0b020`. The repair renames slot 7 in `tilemenu.h` from
`ClearTextures` to the base's name, and is a required item of the
shared-header step.

The destructor key `??1FUN_009ff340@@UAE@XZ` of `tile3d.cpp`,
`tilemenu.cpp`, `interface.cpp`, `interfacemanager.cpp` and
`tesscriptfunctions.cpp` is respelled with the row. The objects of
`tilemenu.cpp` and `tesscriptfunctions.cpp` require `Tile::~Tile`; the
other three require neither spelling.

On every commit: 0 failed compile steps, 0 duplicates, 137 imports, 2,223
archive members in the order of the tip, 525 names with differing
definitions with none entering, warnings equal by class and position, and
each new name defined exactly once, in `tile.cpp`. The run-time type
records of `Tile` that `tile.cpp` now emits have the contents of the three
objects that already defined them. The lazy link loads the same members
and symbols as on the tip; it does not load `tile.cpp`.

### New bindings

`tilemenu.cpp` and `tesscriptfunctions.cpp` required `Tile::~Tile`, and it
was defined nowhere. Both now bind it to the destructor of `tile.cpp`.
Their own copies of `Tile` are 96 and 8 bytes. The class whose destructor
calls it in `tesscriptfunctions.cpp`, `FUN_007099b0`, has the table at
`0x0106ed70`, which `tilemenu.cpp` names `??_7TileRect@@6B@`.

The destructor calls `FUN_009ff690`. Before, the call required
`FUN_009ff340::FUN_009ff690`, which nothing defined. It now binds to
`ReleaseTile::FUN_009ff690`, which `tile.cpp` defines at that row. Its view
`ReleaseTile` agrees with `Tile` at every field up to the flags.

Binding a body credits one provider, a rebuild and a link. Whether every
caller passes a full `Tile` is open.

## The virtual table

This section describes 2277431b8, before step 1, apart from where it says
otherwise.

The recipe binds four addresses under a table name of the family:

| Address | Names | Unit | Generated table |
| --- | --- | --- | --- |
| `0x0106ed44` | `??_7TileMenu@@6B@` | `tilemenu.cpp` | yes, `vtables_0106.cpp` |
| `0x0106ed44` | `??_7TileMenu@fnv_00a00c20@@6B@` | `tile.cpp` | |
| `0x0106ed70` | `??_7TileRect@@6B@` | `tilemenu.cpp` | no |
| `0x0106ed70` | `??_7TileRect@fnv_00a00c20@@6B@` | `tile.cpp` | |
| `0x0106ed70` | `??_7FUN_007099b0@@6B@` | `tesscriptfunctions.cpp` | |
| `0x0106ed9c` | `??_7FUN_009ff340@@6B@` | `tile.cpp` | no |
| `0x0106ed9c` | `??_7Tile3D@@6B@` | `tile3d_h_unit.cpp` | |
| `0x01094878` | `??_7TileText@fnv_00a00c20@@6B@`, `??_7FUN_00a0bbf0@@6B@` | `tile.cpp` | no |

`0x0106ed9c` is the table that the class of the destructor at `0x009ff340`
stores, so it is the table of `Tile`. Before step 1 no row called it
`??_7Tile@@6B@`; step 1 respells `tile.cpp`'s key, with the evidence under
"The owner's class". `src/generated` has no table at that address.

Two generated tables belong to the family: `??_7TileMenu@@6B@` and
`??_7FUN_00a21660@@6B@` in `vtables_0109.cpp`. Both have ten slots and share
the last two. Their labels give the signature of each slot:

| Slot | Signature | Functions in the two tables | Names in the copies that declare the slot |
| --- | --- | --- | --- |
| 0 | deleting destructor | `0x00709a60`, `0x00a219e0` | `~Tile` (13), `Destroy` (3), `Dummy`, `vf0` |
| 1 | `void (Tile*, const char*, Tile*)` | `TileMenu::Init`, `TileImage::Init` | `Init` (6), `vf04`, `vf1` |
| 2 | `NiNode* ()` | `TileMenu::CalculateNode`, `ImageNodeBuild::TileImageShim::FUN_00a1fd50` | `CalculateNode` (2), `CalcNode`, three others |
| 3 | `int ()` | `TileMenu::GetType`, `TileImage::GetType` | `GetType` (3), two others |
| 4 | `const char* ()` | `TileMenu::FUN_00709a50`, `TileImage::GetImageTag`; both labels are non-virtual | `GetTypeStr` (3), two others |
| 5 | `bool (float, float)` | `Tile::IsPointInside` at `0x00a0bae0`, `Tile::FUN_00a216b0` at `0x00a216b0`; both labels are non-virtual | `Unk_05` (2), `Unk05`, two others |
| 6 | `Tile* (int, float, const char*)` | `TileMenu::SetTraitValue`, `TileImage::SetTraitValue` | `SetTraitValue` (2), `UpdateField`, `vf18` |
| 7 | `void ()` | `A0B020Tile::FUN_00a0b020`, `TileMenuStub::FUN_00a1f310`; both labels are non-virtual | `ClearTextures` (3), `vf1c` |
| 8 | `TileShaderProperty* ()` | `A0B1F0Tile::FUN_00a0b1f0` in both; non-virtual | `GetShaderProperty` (3), `vf20` |
| 9 | `void (NiNode*, float, void*)` | `FUN_00a0b280_shell::ApplyAlphaAndColorToChildren` in both; non-virtual | `SetAlphaAndOverlayColor` (2) |

So the class is polymorphic with ten slots, and four of the functions in
those slots have their function row in `tile.cpp`: `0x00a0bae0`,
`0x00a0b020`, `0x00a0b1f0` and `0x00a0b280`. Only the first is named as a
member of `Tile`, and as a non-virtual one. `0x00a216b0` is another class's
override of slot 5, named as a second non-virtual member of `Tile`.

`tile.cpp` also holds `FUN_009ff600_shell::InitTile(Tile*, char*, Tile*)`
at `0x009ff600` and `UpdateTreeNode::FUN_00a037e0(int, float, const char*)`
at `0x00a037e0`. Their parameters are those of slots 1 and 6. No table in
the repository holds either address, so that they are the base's bodies for
those slots is INFERRED.

## Names in the objects

This section describes 2277431b8, before step 1, apart from where it says
otherwise.

The objects of the 81 units define or require 36 external names of the
class, its table and its run-time type records. 15 are defined. 21 are
required and defined nowhere:

| Names | Count | Cause |
| --- | --- | --- |
| Virtual functions of `Tile`, in the spellings of three copies | 16 | `tile3d.cpp`, `tilemenu.cpp` and `tesscriptfunctions.cpp` emit tables of classes derived from their own copy of `Tile`; the inherited slots have no body under those names |
| `Tile::IsSpecialTileName`, public | 1 | `tile.cpp` calls the public spelling; the function row and the definition are private |
| `Tile::Set(int, float, bool)` | 1 | the function row at `0x00a012d0` is `FUN_00a012d0_t::FUN_00a012d0` |
| `Tile::GetTraitID(const char*)` | 1 | the function row at `0x00a01860` is the free function `FUN_00a01860` |
| `Tile::FUN_00700300()` | 1 | the function row at `0x00700300` is `Flt::FUN_00700300` |
| `Tile::UpdateEffectChanges(Tile*)` | 1 | the function row at `0x007e7850` is `PerkMenuX::UpdateEffectChanges(ValueTile*)` |

The 16 use two spellings for six of the slots: `~Tile` and `Destroy`,
`GetType` returning `int` and `unsigned int`, `Unk05` and `Unk_05`,
`SetTraitValue` and `UpdateField`, two return types of `GetShaderProperty`,
and two parameter types of `SetAlphaAndOverlayColor`.

Before step 1 no object defined or required `??_7Tile@@6B@`; now `tile.cpp`
defines it. The run-time type descriptor of `Tile` was defined in nine
objects and its three hierarchy records in three, each from the unit's own
copy of the class. Step 1 adds `tile.cpp` to both, and every definition of
each of the four records has the same contents.

## The reference the copies are compared with

No copy is taken as the truth. The reference is built from evidence:

- offset 0 is a virtual table pointer, with the ten slots above;
- the fields are those of the owning unit's definition from offset 8 up to
  `m_bSpeechChallengeFailure` at 93, the last field it references;
- the size is 96, the end of that field rounded up to the alignment.

A field of a copy agrees when it starts at the offset of a reference field
and is a pointer, the same scalar type, or a record of the same extent. The
record types are not compared, because the owning unit uses storage structs.
`unk34` at 92 is never referenced by the owning unit, so only its offset is
compared.

Six copies are 96 bytes with fields at the reference offsets and other
field types:

| Offset | Types in the six copies |
| --- | --- |
| 8 | `NiTPointerList_Tile___` (3), `NiTPointerList<Tile*>`, its base `NiTPointerListBase<NiTPointerAllocator<unsigned int>, Tile*>`, an unnamed struct |
| 32 | `BSSimpleArray<Tile__Value*, 8>` (4), `BSSimpleArray<Tile::Value*, 8>`, an unnamed struct |
| 56 | `BSStringT<char>` (6) |
| 80 | `NiPointer<NiNode>` (5), `NiNode*` |

The recipe has four names of `BSSimpleArray<Tile::Value*, 8>`, with the
nested `Value`, and none with `Tile__Value`.

## Every copy

One row per class of equal declarations. "(used)" marks a difference in a
field the unit references or a member it uses. The 46 member-only copies
come last; a member-only copy has no layout to disagree with, and its row
lists what it declares.

| Units | Definition | Size | Offset 0 | Differences from the reference |
| --- | --- | --- | --- | --- |
| `tile3d.cpp` | `bsmenu/tile3d.cpp` | 96 | virtual table pointer | slot 0 Destroy is Tile *(bool), the tables have a deleting destructor (used); slot 3 GetType is unsigned int(), the tables have int() (used); slot 6 UpdateField is Tile *(unsigned int, float, const char *), the tables have Tile *(int, float, const char *) (used); slot 8 GetShaderProperty is void *(), the tables have TileShaderProperty *() (used); slot 9 SetAlphaAndOverlayColor is void(NiNode *, float, const RgbaColor &), the tables have void(NiNode *, float, void *) (used) |
| `tileimage.cpp` | `bsmenu/tileimage_private.h` | 96 | virtual table pointer | 9 of the 10 virtual slots |
| `tilemenu.cpp` | `bsmenu/tilemenu_private.h` | 96 | virtual table pointer | slot 9 SetAlphaAndOverlayColor is void(NiNode *, float, NiColorAlpha *), the tables have void(NiNode *, float, void *) (used) |
| `tilerect.cpp` | `bsmenu/tilerect.h` | 64 | virtual table pointer | size 64; layoutPadding4 at 8: unsigned char[52] where the reference has struct TileChildListStorage; 2 of the 10 virtual slots |
| `tilerect_copies_004.cpp` | `bsmenu/tilerect_copies_004.cpp` | 80 | virtual table pointer | size 80; layoutPadding4 at 8: unsigned char[28] where the reference has struct TileChildListStorage; StringProvider at 40: inside the reference field m_kValues at 32; xNameLength at 48: inside the reference field m_kValues at 32; pParent at 56: Tile * where the reference has struct TileNameStorage; m_pRenderedNodeEntry at 64: inside the reference field m_kName at 56 (used); uiFlags at 72: unsigned int where the reference has Tile *; m_bFlagAfterUiFlags at 76: inside the reference field m_pParent at 72; m_bSpeechChallengeFailure at 77: inside the reference field m_pParent at 72; 6 of the 10 virtual slots; slot 2 GetType is int(), the tables have ImageNodeBuild::NiNode *() or NiNode *(); slot 3 GetTypeName is const char *(), the tables have int(); slot 4 CalculateNode is NiNode *(), the tables have const char *(); slot 5 SetTraitValue is Tile *(int, float, const char *), the tables have bool(float, float) |
| `main.cpp` | `fallout/misc/main.cpp` | 16 | virtual table pointer | size 16; 1 of the 10 virtual slots |
| `interface.cpp` | `fallout/interface/interface_rebase_types_Tile.h` | 96 | field m_ppVirtualMethodTable | m_ppVirtualMethodTable at 0: a field in place of the virtual table pointer |
| `listbox_h_unit.cpp` | `fallout/interface/listbox_types_Tile.h` | 96 | field m_ppVirtualMethodTable | m_ppVirtualMethodTable at 0: a field in place of the virtual table pointer |
| `statsmenu.cpp` | `statsmenu_types_Tile.h` | 96 | field m_ppVirtualMethodTable | m_ppVirtualMethodTable at 0: a field in place of the virtual table pointer |
| `tile.cpp`, `tile_copies_002.cpp`, `tile_copies_003.cpp` | `bsmenu/tile_packet_decls.h` | 592 | field m_pVtbl | size 592; m_pVtbl at 0: a field in place of the virtual table pointer; tileUnknown36 at 94: beyond the reference; floatFlags at 586: beyond the reference |
| `bgsterrainnode.cpp` | `bgsterrainnode.cpp` | 56 | field pad | size 56; pad at 0: a field in place of the virtual table pointer; m_pSceneNode at 48: inside the reference field m_kValues at 32 (used) |
| `bookmenu.cpp` | `fallout/interface/menus/bookmenu.cpp` | 8 | base | size 8; base TGF |
| `caravanmenu.cpp` | `fallout/interface/menus/caravanmenu.cpp` | 4 | field uiFlags | size 4; uiFlags at 0: a field in place of the virtual table pointer |
| `computersmenu.cpp` | `fallout/interface/menus/computersmenu.cpp` | 8 | field pParent | size 8; pParent at 0: a field in place of the virtual table pointer |
| `mapmenu.cpp` | `fallout/interface/menus/mapmenu_decls.h` | 112 | base | size 112; base TileListBoxCalls; fields at 8: void *[13] where the reference has struct TileChildListStorage; 2 of the 10 virtual slots; slot 0 Destroy is Tile *(bool), the tables have a deleting destructor |
| `roulettemenu.cpp` | `fallout/interface/menus/roulettemenu.cpp` | 8 | field m_pRenderedNodeEntry | size 8; m_pRenderedNodeEntry at 0: a field in place of the virtual table pointer |
| `navmeshobstaclemanager.cpp` | `fallout_shared/pathfinding/navmeshobstaclemanager.cpp` | 8 | field m_iWordAt00 | size 8; m_iWordAt00 at 0: a field in place of the virtual table pointer |
| `blk_006e0000_od.cpp` | `staging/blk_006e0000_od.cpp` | 8 | field _0 | size 8; _0 at 0: a field in place of the virtual table pointer |
| `companionwheelmenu.cpp`, `blk_007e0000_od.cpp` | `fallout/interface/menus/companionwheelmenu.cpp`, `staging/blk_007e0000_od.cpp` | 8 | virtual table pointer | size 8; 1 of the 10 virtual slots |
| `radialtile.cpp` | `bsmenu/radialtile.cpp` | 8 | virtual table pointer | size 8; 1 of the 10 virtual slots; slot 0 Dummy is void(), the tables have a deleting destructor |
| `menuconsole.cpp` | `fallout/interface/menuconsole_decls.h` | 8 | virtual table pointer | size 8; 1 of the 10 virtual slots |
| `menumanager.cpp` | `fallout/interface/menumanager.cpp` | 8 | virtual table pointer | size 8; 1 of the 10 virtual slots |
| `creditsmenu.cpp` | `fallout/interface/menus/creditsmenu.cpp` | 8 | virtual table pointer | size 8; 1 of the 10 virtual slots |
| `dialogmenu.cpp` | `fallout/interface/menus/dialogmenu_decls.h` | 8 | virtual table pointer | size 8; 1 of the 10 virtual slots |
| `hudmainmenu.cpp` | `fallout/interface/menus/hudmainmenu.cpp` | 8 | virtual table pointer | size 8; 9 of the 10 virtual slots; slot 1 vf04 is void(), the tables have void(Tile *, const char *, Tile *) (used); slot 2 vf08 is void(), the tables have ImageNodeBuild::NiNode *() or NiNode *() (used); slot 3 vf0c is void(), the tables have int() (used); slot 4 vf10 is void(), the tables have const char *() (used); slot 5 vf14 is void(), the tables have bool(float, float) (used); slot 6 vf18 is void(), the tables have Tile *(int, float, const char *) (used); slot 8 vf20 is CompassStub *(), the tables have TileShaderProperty *() (used) |
| `itemmodmenu.cpp` | `fallout/interface/menus/itemmodmenu_unit_decls.h` | 8 | virtual table pointer | size 8; 1 of the 10 virtual slots; slot 0 Destroy is Tile *(bool), the tables have a deleting destructor (used) |
| `tesobjectrefr.cpp` | `fallout_shared/tesobjectrefr.cpp` | 8 | virtual table pointer | size 8; 3 of the 10 virtual slots; slot 0 vf0 is void(), the tables have a deleting destructor; slot 1 vf1 is void(), the tables have void(Tile *, const char *, Tile *); slot 2 vf2 is void(Vec577 *), the tables have ImageNodeBuild::NiNode *() or NiNode *() (used) |
| `tesscriptfunctions.cpp` | `fallout_shared/tesscriptfunctions.cpp` | 8 | virtual table pointer | size 8; 1 of the 10 virtual slots |
| `inventorymenu.cpp`, `lockpickmenu.cpp`, `messagemenu.cpp`, `racesexmenu.cpp`, `repairmenu.cpp`, `repairservicesmenu.cpp`, `sleepwaitmenu.cpp`, `slotmachinemenu.cpp`, `traitselectmenu.cpp`, `tutorialmenu.cpp` | 10 files | 1 | nothing | declares `GetInterfaceScale float ()`, `Set void (int, int)` |
| `hotkeyswheel.cpp`, `playernameentrymenu.cpp`, `specialbookmenu.cpp`, `surgerymenu.cpp`, `vatsmenu.cpp`, `blk_00720000_od.cpp`, `blk_00740000_od.cpp`, `blk_007c0000_od.cpp` | 8 files | 1 | nothing | declares `Set void (int, int)` |
| `bsaudio.cpp`, `combatactions.cpp`, `forenderedmenu.cpp`, `quantitymenu.cpp`, `memorylevelmanager.cpp`, `bsfacegenmanager.cpp`, `miscstats.cpp` | 7 files | 1 | nothing | declares nothing |
| `lovetestermenu.cpp`, `mediaset.cpp`, `blk_00700000_od.cpp`, `blk_00760000_od.cpp`, `blk_007a0000_od.cpp` | `include/fnv/decl/Tile.h` | 1 | nothing | declares `GetInterfaceScale float ()`, `GetSpeechChallengeFailure bool ()`, `IsMenuRendered bool ()`, `IsSpecialTileName bool (const char *)`, `Set void (int, int)`, `Set void (int, unsigned int)`, `SetName void (const char *)`, `SetNodeFloat void (float)`, `SetSpeechChallengeFailure void (bool)` |
| `bartermenu.cpp`, `hackingmenu.cpp` | `fallout/interface/menus/bartermenu.cpp`, `fallout/interface/menus/hackingmenu.cpp` | 1 | nothing | declares `GetInterfaceScale float ()`, `Set void (int, int)`, `Set void (int, unsigned int)`, `SetName void (const char *)` |
| `chargenmenu.cpp`, `containermenu.cpp` | `fallout/interface/menus/chargenmenu.cpp`, `fallout/interface/menus/containermenu_decls.h` | 1 | nothing | declares `GetInterfaceScale float ()`, `Set void (int, int)`, `SetName void (const char *)` |
| `menu.cpp` | `bsmenu/menu.cpp` | 1 | nothing | declares `Set void (int, float, bool)` |
| `tile_h_unit.cpp` | `bsmenu/tile_h_decls.h` | 1 | nothing | declares `IsSpecialTileName bool (const char *)` |
| `tiletext.cpp` | `bsmenu/tiletext.h` | 1 | nothing | declares nothing |
| `interfacemanager.cpp` | `fallout/interface/interfacemanager_packet.h` | 1 | nothing | declares `Set void (int, int)`, `Set void (int, unsigned int)`, `SetSpeechChallengeFailure void (bool)` |
| `listbox.cpp` | `fallout/interface/listbox.cpp` | 1 | nothing | declares `GetSpeechChallengeFailure bool ()`, `Set void (int, int)`, `Set void (int, unsigned int)` |
| `blackjackmenu.cpp` | `fallout/interface/menus/blackjackmenu.cpp` | 1 | nothing | declares `GetInterfaceScale float ()`, `Set void (int, float, bool)`, `Set void (int, int)` |
| `levelupmenu.cpp` | `fallout/interface/menus/levelupmenu.cpp` | 1 | nothing | declares `GetInterfaceScale float ()`, `GetSpeechChallengeFailure bool ()`, `Set void (int, int)`, `SetName void (const char *)` |
| `loadingmenu.cpp` | `fallout/interface/menus/loadingmenu_packet.h` | 1 | nothing | declares `GetInterfaceScale float ()`, `Set void (int, const char *, bool)`, `Set void (int, float, bool)`, `Set void (int, int)`, `Set void (int, unsigned int)` |
| `recipemenu.cpp` | `fallout/interface/menus/recipemenu.cpp` | 1 | nothing | declares `GetInterfaceScale float ()`, `GetSpeechChallengeFailure bool ()`, `Set void (int, int)`, `Set void (int, unsigned int)` |
| `startmenu.cpp` | `fallout/interface/menus/startmenu.cpp` | 1 | nothing | declares `GetInterfaceScale float ()`, `Set void (int, float, bool)`, `Set void (int, int)`, `Set void (int, unsigned int)`, `SetName void (const char *)` |
| `statsmenu_h_unit.cpp` | `fallout/interface/menus/statsmenu_decls.h` | 1 | nothing | declares `Set void (int, int)` |
| `traitmenu.cpp` | `fallout/interface/menus/traitmenu.cpp` | 1 | nothing | declares `GetInterfaceScale float ()`, `Set void (int, int)`, `UpdateEffectChanges void (Tile *)` |

Seven units use something that differs: `bgsterrainnode.cpp` and
`tilerect_copies_004.cpp` reference a field at an offset where the reference
has another field, and `tile3d.cpp`, `tilemenu.cpp`, `hudmainmenu.cpp`,
`itemmodmenu.cpp` and `tesobjectrefr.cpp` use a virtual slot with another
signature. These are the layout errors to repair first. `tilemenu.cpp`'s
one difference is the third parameter of slot 9, a pointer in both.

## Why no shared declaration is written yet

The shared declaration must be the real class, and the unit that defines a
member includes it. Three facts stood in the way. Step 1 removed the first
two for `tile.cpp`; the third remains.

1. The owning unit cannot include a real declaration today. Its own
   definition has a pointer field for the table, a tail from offset 94 to
   592 that nothing uses, and storage structs for three members. Its creation
   function and its destructor use two other views of 64 bytes whose fields
   are 32-bit `int`. A 96-byte class with a virtual table changes
   allocation sizes and field offsets in those functions. That is a repair
   of the unit under VEGAS-17, with function-level evidence, not a
   declaration move.
2. A real class makes the ten slot functions virtual members of `Tile`.
   13 of the 20 labels in the two generated tables are non-virtual names,
   most of them of stand-in classes, and the destructor's row is
   `FUN_009ff340::~FUN_009ff340`. Declaring them virtual respells recipe
   keys and labels in `src/generated/data/vtables_0106.cpp` and
   `vtables_0109.cpp`. `docs/native-data-ownership.md` permits only the
   class-key respelling of those files.
3. The copies do not agree on the member classes. The owning unit uses
   storage structs, and the six 96-byte copies use four spellings of the
   child list and three of the value array. The header needs one shared
   declaration of each member class first.

A header that left out the virtual functions, or kept a pointer field at
offset 0, would be a second member-only definition or a fake table pointer.
Neither is written.

## Design

### Where the declaration lives

`include/fnv/tile.h`, beside `ni_ref_object.h` and `bs_simple_list.h`. The
step that creates it replaces `include/fnv/decl/Tile.h` by an include of it
in the five units that use the member-only copy, and removes that file.

### What it declares

- No base class.
- Ten virtual functions in slot order, the destructor first, with the
  signatures of the slot table above.
- The fields of the reference at their offsets, with the member classes:
  the child list at 8, the value array at 32, the name at 56, the parent at
  72, the node pointer at 80, the flags at 88, two one-byte fields at 92 and
  93. The class is 96 bytes. The header asserts the size and each offset for
  windows-x64.
- The nested class `Tile::Value`, as the recipe names it.
- The non-virtual members that have a function row under the class's name:
  `Set(int, int)`, `Set(int, unsigned int)`, `GetSpeechChallengeFailure`,
  `GetInterfaceScale`, `IsMenuRendered`, `SetSpeechChallengeFailure`,
  `SetName`, `SetNodeFloat`, and `IsSpecialTileName` as a private static
  member, as its row spells it.

Nothing else. `Set(int, float, bool)`, `Set(int, const char*, bool)`,
`GetTraitID`, `FUN_00700300`, `UpdateEffectChanges`, `GetValue`, `GetFloat`,
`IsSpecial`, `GetUnderlyingNode`, `SetFlag8000` and `SetTraitValueAndText`
are declared by some copies and have no function row under the class's
name. Each joins the header when its row is respelled under the rules of
VEGAS-11. `FUN_00a216b0` is another class's override and never joins.

### How the bodies are provided

The header has no body. The unit with the function row defines the member.
The compiler emits the table of `Tile` where the destructor is defined,
which is `tile.cpp`. Since step 1 it does. A unit that
derives a class from its own copy of `Tile` emits a table with slots of
that copy; `tile3d.cpp`, `tilemenu.cpp` and `tesscriptfunctions.cpp` do so
now, and their derived classes move with them.

### The rule for moving a unit

A unit's copy is replaced by `#include "fnv/tile.h"` when all of these hold:

1. Every field the unit references is in the header at the same offset with
   the same type, measured by the compiler in that unit.
2. Every member the unit uses is in the header with the same signature, and
   virtual in both or in neither.
3. After the replacement the unit compiles, and its object is byte-identical
   to the object before, with only the COFF timestamp masked. For a unit
   that binds a name it did not bind before, the object is equal once that
   name is respelled, and the name has one definition, in the unit with the
   function row.
4. No virtual call and no reference to a virtual table or a run-time type
   record appears or disappears in the object.

A unit that fails stays on its copy and is tabled with the difference. The
owning unit is the exception to condition 3: its step is a repair, proven
per function.

### Order of steps

| Step | Units | Proof | Waits for |
| --- | --- | --- | --- |
| 1. The owning unit uses one view: the 592-byte definition, `FUN_009ff340` and `fnv_00a00c20::Tile3D` become the 96-byte class | `tile.cpp`; `tile_copies_002.cpp` and `tile_copies_003.cpp` keep the old copy and move in step 2 | per function: instructions, relocations, allocation sizes and write extents against the tip | done |
| 2. The header; the units of `decl/Tile.h` and the member-only copies | up to 44 of 46 | byte-identical objects | step 1 |
| 3. Copies with virtual functions and no field | up to 6 of 11 | byte-identical objects, condition 4 | step 1 |
| 4. Copies of 96 bytes | 6 | byte-identical objects once the member classes are shared | one shared declaration each of the child list, the value array, `BSStringT` and `NiPointer` |
| 5. The other 11 copies with fields, and the units held in steps 2 and 3 | 11 and up to 7 | each is a layout error or uses a member without a row; repaired or tabled | |
| 6. Stand-in receivers of the 144 other function rows of `tile.cpp` | 89 units, 194 names | the rules of the VEGAS-11 batches | steps 1 and 2 |

The counts in steps 2 and 3 are estimates from the declarations. Two
member-only copies use a member that the header lacks: `blackjackmenu.cpp`
uses `Set(int, float, bool)` and `traitmenu.cpp` uses `UpdateEffectChanges`.
Five copies with virtual functions and no field are held: `hudmainmenu.cpp`,
`itemmodmenu.cpp` and `tesobjectrefr.cpp` use a slot with another signature,
`menuconsole.cpp` uses `FUN_00700300`, and `radialtile.cpp` defines
`FUN_00a216b0` as a member. The object comparison decides each unit.

## Rulings for step 1

The coordinator answered the three decisions this document asked for with
five rulings for step 1. Reviews confirmed them, R4 in a tightened form.

1. R1, respelling. A script kept outside the repository may respell recipe
   keys and the labels of `vtables_0106.cpp` and `vtables_0109.cpp` so that
   the slot functions become virtual members of `Tile`. Names only: every
   address, size, slot, unit and order stays, the retirement patch is not
   touched, and each label's slot is read from the generated table. Neither
   file is a pinned input of the composition, so no pin is recomputed.
   `docs/native-data-ownership.md` records the permission.
2. R2, names. A slot function keeps the name of its function row, a
   placeholder included. Only the virtual key changes.
3. R3, slots without a body. Slots 2, 3 and 4 are declared virtual without a
   body and not pure. Step 1 applies the same to slots 1 and 6, because no
   generated table shows their bodies either.
4. R4, layout evidence. A field is established when the declared types and
   order give its offset and the owner's accesses through the class agree.
   A field of a 32-bit view is a defect to repair, not evidence. Where a
   derived class's owning unit declares x64 field types, those types decide
   its size, not the 32-bit view.
5. R5, the table. `??_7Tile@@6B@` may name `0x0106ed9c` only if the recipe
   and the objects show it. They show that the destructor and the base
   constructor store it; they do not show its ten slot addresses.

`tile.cpp`'s key for the base constructor at `0x00709860` is respelled from
`??0Tile3D@@QAE@XZ` to `??0Tile@@QAE@XZ` in the creation commit, because
its object then requires `Tile::Tile`. A key that names something its
object does not require is respelled, as ruled on VEGAS-65.

## Open items

- The shared header. `include/fnv/tile.h` comes next, from the owner's
  class, with the units of `include/fnv/decl/Tile.h` and the other
  member-only copies, as the design above says. `tile_copies_002.cpp` and
  `tile_copies_003.cpp` move with it. It also takes the definitions of the
  storage structs' destructors, and renames slot 7 of `tilemenu.h` from
  `ClearTextures` to `FUN_00a0b020`, which binds `tilemenu.cpp`'s call
  again.
- The member classes. The header needs one shared declaration each of the
  child list, the value array, `BSStringT` and `NiPointer` before the
  storage structs can go and the six 96-byte copies can move.
- 17 rows of `tile.cpp` still access the object through stand-in views
  with 32-bit offsets, 90 accesses in all. They are step 6.

| Address | Function | View | Stale accesses |
| --- | --- | --- | --- |
| `0x00a00b50` | `TileObject::FUN_00a00b50` | `TileObject` | 2 |
| `0x00a01750` | `TileA01::FUN_00a01750` | `TileA01` | 1 |
| `0x00a033b0` | `fnv_00a033b0::C00a033b0::FUN_00a033b0` | `R_Tile` | 7 |
| `0x00a037e0` | `UpdateTreeNode::FUN_00a037e0` | `UpdateTreeNode` | 4 |
| `0x00a03c90` | `FUN_00a03c90_shell::FUN_00a03c90` | `TileMenu` | 1 |
| `0x00a03f70` | `fnv_00a03f70::FUN_00a03f70_shell::FUN_00a03f70` | `TileParent_00a03f70` | 1 |
| `0x00a040a0` | `sa040a0::Owner::IsAllChildrenFlag0` | `sa040a0::Owner` | 1 |
| `0x00a04640` | `RenderTile::FUN_00a04640` | `RenderTile` | 54 |
| `0x00a07580` | `fnv_00a07580::FUN_00a07580` | `TileResult_00a07580` | 2 |
| `0x00a07690` | `FUN_00a07690` | `FlaggedTile` | 5 |
| `0x00a07a40` | `ClipTile::FUN_00a07a40` | `ClipTile` | 3 |
| `0x00a080d0` | `FUN_00a080d0` | `FadeTile` | 1 |
| `0x00a087d0` | `FUN_00a087d0_shell::FUN_00a087d0` | `TileFlags_00a087d0` | 1 |
| `0x00a08a20` | `SceneNodeOwner::FUN_00a08a20` | `SceneNodeOwner` | 2 |
| `0x00a09410` | `fnv_00a09410::EvalValue::FUN_00a09410` | `EvalTile` | 2 |
| `0x00a0b520` | `TileWork::FUN_00a0b520` | `TileWork` | 2 |
| `0x00a0bbf0` | `FUN_00a0bbf0::~FUN_00a0bbf0` | `TileBaseA0BBF0` | 1 |

- The base constructor. `tile.cpp` calls it as `Tile::Tile`, which nothing
  defines, and its key spells that name. The row at `0x00709860` is
  `Tile3D::Tile3D` in `tile3d_h_unit.cpp`. The row and the `??0Tile3D` keys
  of `interfacemanager.cpp`, `tesscriptfunctions.cpp` and
  `blk_00a00000_od.cpp` move in the step that moves `tile3d_h_unit.cpp`.
  Its object also writes up to byte 69 of its own 72-byte copy.
- The derived classes in their own units. `tilerect.h` puts
  `m_bTextureLoaded` at 64 on a base of `0x34` padding bytes, and
  `blk_00a00000_od.cpp` puts the fields of `FUN_00a0bc80` at 64 to 103 on
  its 64-byte `Tile3D`, so its constructor at `0x00a0bc80` writes at the
  stale offsets 64 to 103. `radialtile.cpp`'s `TileImage` is an 8-byte view, and
  `tiletext.cpp`'s `Tile` has no fields. Each unit stays on its copy until
  it moves. The size of `TileText` is not established.
- The overrides of TileMenu that `tile.cpp` declares are undefined names of
  the namespace `fnv_00a00c20`. They bind when the classes of the creation
  function move to the shared declarations of `TileRect` and `TileMenu`,
  with the rows' names respelled to the slots' names where they differ
  (`TileMenu::FUN_00709a50` for slot 4, `TileMenuStub::FUN_00a1f310` for
  slot 7). The tables of `TileRect`, `TileText` and `FUN_00a0bc80` are
  unconfirmed. The coordinator ruled that the overrides of slots 4 and 7
  carry the base's names because C++ requires it, and that their rows are
  respelled when the class moves. No recipe key names any of the six
  overrides until the commit in which the name the object requires equals
  the row's name.
- The overrides of `TileRect` and `TileText` are inferred, not declared:
  the rows `TileRect::Init` (`0x00a1f370`), `TileRect::GetType`
  (`0x00709960`) and `TileText::GetType` (`0x00a0bbd0`). Their slots in
  `tile.cpp`'s tables bind undefined names of the base, so nothing binds
  to a wrong body.
- `tile.cpp`'s key `??0FUN_00a0bc80@fnv_00a00c20@@QAE@XZ` names a
  constructor that the object never requires; the constructor is inline.
  The key belongs to the step that moves `blk_00a00000_od.cpp`.
- A 4-byte view of an 8-byte pointer. The inline constructor of
  `FUN_00a0bc80` in `tile.cpp` calls `NodeRef::Assign(int)` through a
  `NodeRef` view, whose one field is an `int`, of the 8-byte node pointer
  at 80. The callee is undefined and has no row. It is open with the
  pointer truncation below.
- Slot 5 of `??_7FUN_00a21660@@6B@` is labelled `Tile::FUN_00a216b0`, a
  non-virtual name for the override whose row is in `radialtile.cpp`. It
  stays until that unit moves.
- `tilemenu.cpp` keeps its key for `A0B020Tile::FUN_00a0b020`. The name is
  now honestly undefined; before, it bound by address to the right body,
  the stand-in body in `tile.cpp`, under a forced link.
- A pointer truncation (VEGAS-17 criterion 4). `Tile::~Tile` and
  `ReleaseTile::FUN_009ff690` pass `this` to `ClearInterfaceRefs` cast to a
  32-bit `unsigned int`, while the function takes a 64-bit argument. The
  casts and their warnings are older than this step and unchanged. By the
  coordinator's ruling the two casts, in `tile.cpp`'s destructor and in
  `ReleaseTile::FUN_009ff690`, are the first item of the next step, in a
  commit of their own with the evidence of the objects.
- Slot names without a body are provisional, slot 4 among them, until the
  coordinator records them in the override table.
- The bodies of slots 1 to 4 and 6, and whether any slot of the base's
  table is pure, are not shown in the repository.
- Windows execution: not run.

## Not covered

- Step 1 changed `tile.cpp`, its two headers, names in `build/units.json`
  and labels in `vtables_0106.cpp` and `vtables_0109.cpp`. Nothing else in
  `src` or `include` changed.
- The derived classes `Tile3D` and `RadialTile` were not measured. Of
  `TileRect`, `TileImage`, `TileText`, `TileMenu`, `FUN_00a0bc80` and
  `FUN_00a21660` only the declarations in the owning units named above
  were measured.
- 71 classes named `Tile` inside a namespace or another class, in 35 of the
  81 units, were counted and not measured. They are stand-ins and follow
  step 6.
- Receivers. The tables measure each unit's declaration, not the object a
  caller passes.
- Tests. `tile.cpp` does not compile for the host build, before or after
  step 1, and its functions need the game archive, so no host test reaches
  them. The header's layout assertions and the per-function instruction
  tables in the evidence of the change stand in for a test.
- Windows execution: not run.
