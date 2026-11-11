# One shared declaration of Tile: measurement and design

VEGAS-17 owns the `bsmenu` units, and criterion 2 of VEGAS-11 asks for one
declaration of every class that units share. This document measures every
definition of the user interface class `Tile` and designs its shared
declaration. No header is written and no unit moves yet. The owning unit's
own declaration is incomplete and contradicted, and a real declaration needs
three rulings first. They are under "Decisions needed".

Everything was measured on 2277431b8, for the windows-x64 build target, with
the build's own command line for each unit. Offsets and sizes are the
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

## The virtual table

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
stores, so it is the table of `Tile`. No row calls it `??_7Tile@@6B@`, and
`src/generated` has no table at that address. That the destructor stores
this table is INFERRED from the unit's symbol row and the tagged body.

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

No object defines or requires `??_7Tile@@6B@`. The run-time type descriptor
of `Tile` is defined in nine objects and its three hierarchy records in
three, each from the unit's own copy of the class. Whether their contents
are equal was not compared.

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
member includes it. Three facts stand in the way.

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
which is `tile.cpp`. No object defines that table today. A unit that
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
| 1. The owning unit uses one view: the 592-byte definition, `FUN_009ff340` and `fnv_00a00c20::Tile3D` become the 96-byte class | `tile.cpp`, `tile_copies_002.cpp`, `tile_copies_003.cpp` | per function: instructions, relocations, allocation sizes and write extents against the tip | decisions 1 to 3 |
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

## Decisions needed

1. Respelling for the virtual slots. May the respelling script change, in
   the recipe keys and in the labels of `vtables_0106.cpp` and
   `vtables_0109.cpp`, the names of the functions in the ten slots to
   virtual members of `Tile` and of its derived classes, under the three
   conditions that hold for the class-key respelling? Without it
   `Tile::IsPointInside` cannot be the virtual function that slot 5 is.
2. Names of slots 4, 7, 8 and 9, and of the base's bodies for slots 0, 1
   and 6. The recipe has placeholders or stand-in classes for them:
   `FUN_00709a50`, `FUN_00a0b020`, `A0B1F0Tile::FUN_00a0b1f0`,
   `FUN_00a0b280_shell::ApplyAlphaAndColorToChildren`,
   `FUN_009ff340::~FUN_009ff340`, `FUN_009ff600_shell::InitTile` and
   `UpdateTreeNode::FUN_00a037e0`. The copies offer `GetTypeStr`,
   `ClearTextures`, `GetShaderProperty` and `SetAlphaAndOverlayColor`. The
   reviewed override table needs an entry for each.
3. The base's own table. Nothing in the repository shows which slots of the
   table at `0x0106ed9c` are pure. No function row of `tile.cpp` is
   identified as the base's body for slots 2, 3 and 4. Either they are
   declared pure, or they are declared without a body and the object of
   `tile.cpp` requires three names that nothing defines. Reading the table
   needs the original release.

Step 1 is the largest piece of work and belongs to VEGAS-17. Which function
rows of `tile.cpp` use each of the four views was not measured here.

## Not covered

- Nothing was changed in `src`, `include` or `build/units.json`. No object,
  link or test differs from 2277431b8.
- The derived classes `TileRect`, `TileImage`, `TileText`, `TileMenu`,
  `Tile3D` and `RadialTile` were not measured, apart from the six sizes in
  the creation function of `tile.cpp`.
- 71 classes named `Tile` inside a namespace or another class, in 35 of the
  81 units, were counted and not measured. They are stand-ins and follow
  step 6.
- Receivers. The tables measure each unit's declaration, not the object a
  caller passes.
- The contents of the three definitions of the run-time type records.
- Windows execution: not run.
