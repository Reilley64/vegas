#pragma once

// Element `index` of an array laid out as BSSimpleArray (vtable, item buffer, size, capacity), for code that
// reaches it through a stand-in type. It is what BSSimpleArray<T>::GetAt (0x006a7ad0) returns.
template <class T> T& SimpleArrayItem(void* array, unsigned int index)
{
    struct View
    {
        void* vtable;
        T* buffer;
    };
    return static_cast<View*>(array)->buffer[index];
}

// The item count of an array laid out as BSSimpleArray, for code that reaches it through a stand-in type. The folded
// 4-byte getter at 0x0044ddc0 (Twin_0044ddc0::GetName) returns it when called on such an array.
inline unsigned int& SimpleArraySize(void* array)
{
    struct View
    {
        void* vtable;
        void* buffer;
        unsigned int size;
    };
    return static_cast<View*>(array)->size;
}
