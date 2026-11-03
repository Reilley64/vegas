#pragma once

// The leading fields of Tile, for interface code that reaches a tile through a stand-in type.
// Tile::FUN_0056c7f0 (0x0056c7f0, a folded getter) returns renderedNode.
struct TileFields
{
    void* vtable;
    void* childHead;
    void* childTail;
    unsigned int childCount;
    void* valuesVtable;
    void* valuesBuffer;
    unsigned int valuesSize;
    unsigned int valuesCapacity;
    char* name;
    unsigned short nameLength;
    unsigned short nameCapacity;
    TileFields* parent;
    void* renderedNode;
    unsigned int flags;
};
