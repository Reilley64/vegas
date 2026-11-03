#pragma once

class Tile;

// The leading fields of ListBox<T>, for interface code that reaches a list box through a stand-in type.
struct ListBoxFields
{
    void* vtable;
    void* listItem;
    void* listNext;
    Tile* parentTile;
    Tile* selected;
    Tile* scrollBar;
};
