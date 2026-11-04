#pragma once

class Tile;
namespace tile_path_resolver { struct UITile; }

// 0x00a080d0
void FUN_00a080d0();
// 0x00a08b20
namespace tile_path_resolver { ::tile_path_resolver::UITile *FUN_00a08b20(::tile_path_resolver::UITile *, const char *); }
// 0x00a08f20
::Tile *FindTileByName(::Tile *, const char *);
