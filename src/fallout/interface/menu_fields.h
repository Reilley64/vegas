#pragma once

class Tile;

// The leading fields of Menu, for interface code that reaches a menu through a stand-in type.
struct MenuFields
{
    void* vtable;
    Tile* tile;
};
