// bsmenu/tilerect.cpp: TileRect (2 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_009ff600_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a074d0_shell.h"
#include "fnv/symbols_00450000.h"
#include "tilerect.h"

// Initializes the TileRect by calling Tile::Init, then sets a value of 0x0fa3 to 1.0f and calls a method with 3.
// @fnv 0x00a1f370
void TileRect::Init(Tile* parent, const char* name, Tile* replacedChild)
{
    reinterpret_cast<::FUN_009ff600_shell *>(this)->InitTile(parent, (char *)(name), replacedChild);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0x0fa3, 1.0f, true);
    reinterpret_cast<::FUN_00a074d0_shell *>(this)->FUN_00a074d0(3);
}

// @fnv 0x00709960
int TileRect::GetType()
{
    return eRect;
}
