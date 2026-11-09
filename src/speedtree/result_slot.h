#pragma once

#include "fnv/decl/FUN_0044a4c0.h"

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

// Formatting producers assign into a genuine live owner; no opaque storage or
// layout-cast destructor stands in for the native string.
using StringSlot = FUN_0044a4c0;
