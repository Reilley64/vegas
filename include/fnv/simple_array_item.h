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
