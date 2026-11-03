#pragma once

// Gives a temporary an address for the duration of a full expression, for calls that write their result
// through a pointer (the hidden result argument of functions returning a class by value).
template <class T> T& ResultSlot(T&& value)
{
    return value;
}
