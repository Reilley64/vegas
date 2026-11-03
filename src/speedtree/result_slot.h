#pragma once

#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"

// Some declarations return a value through a pointer the caller passes first. ResultSlot gives that
// pointer a temporary that lives until the end of the full-expression that calls the function.
template <class T> inline T& ResultSlot(T&& value)
{
    return value;
}

struct Float3
{
    float v[3];
};

// Storage for a string that the callee constructs in place; destroyed like the string temporary.
struct StringSlot
{
    alignas(void*) unsigned char storage[64];
    ~StringSlot()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls*>(this)->FUN_0044a730(true, 0);
    }
};
