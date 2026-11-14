#pragma once

// The element count of an array laid out as hkArray (data pointer, size, capacity and flags), for code that reaches
// it through a stand-in type. The folded 4-byte getter at 0x00726070 (BSSimpleList::GetNext) returns it when called
// on such an array.
inline int& HavokArraySize(void* array)
{
    struct View
    {
        void* data;
        int size;
    };
    return static_cast<View*>(array)->size;
}
