#pragma once

#include "havok/PackfileRegistry.h"
#include <limits>
#include <stdexcept>
#include <type_traits>

// Source-owned metadata producer. Consumers use the constructed native record,
// never an untyped array of data and function-pointer representations.
struct Agg6
{
    template<class Finish, class Cleanup>
    Agg6(const void* name, Finish finish, Cleanup cleanup, const void* vtable,
        const void* auxiliary, const void* size)
        : metadata{static_cast<const char*>(name), BindFinish(finish), BindCleanup(cleanup),
              vtable, ObjectSize(size), auxiliary} {}
    hkEntryD479* Metadata() noexcept { return &metadata; }

private:
    // This is a real C++ subobject, not a view of serialized or erased elements.
    // Static generated producers own it for every borrowing resource's life.
    hkEntryD479 metadata;

    static int ObjectSize(const void* size)
    {
        const auto value = reinterpret_cast<std::uintptr_t>(size);
        if (value > static_cast<std::uintptr_t>(std::numeric_limits<int>::max()))
            throw std::invalid_argument("invalid generated metadata size");
        return static_cast<int>(value);
    }
    template<class Object, class Flag>
    static std::function<void(void*, int)> BindFinish(void (*function)(Object*, Flag))
    {
        if (!function) return {};
        return [function](void* object, int finishing)
        {
            // Keep the provider's actual declared function type. Some existing
            // providers express the finishing word as a pointer-sized token.
            if constexpr (std::is_pointer_v<Flag>)
            {
                static_assert(std::is_same_v<Flag, void*>);
                function(static_cast<Object*>(object),
                    reinterpret_cast<Flag>(static_cast<std::intptr_t>(finishing)));
            }
            else
            {
                static_assert(std::is_same_v<Flag, int> || std::is_same_v<Flag, unsigned int> ||
                    std::is_same_v<Flag, std::intptr_t>);
                function(static_cast<Object*>(object), static_cast<Flag>(finishing));
            }
        };
    }
    template<class Object>
    static std::function<void(void*, int)> BindFinish(void (*function)(Object*))
    {
        if (!function) return {};
        // The genuine one-argument provider does not consume a finishing word.
        return [function](void* object, int) { function(static_cast<Object*>(object)); };
    }
    static std::function<void(void*, int)> BindFinish(std::nullptr_t) { return {}; }
    template<class Result, class Object>
    static std::function<void(void*)> BindCleanup(Result (*function)(Object*))
    {
        static_assert(std::is_same_v<Result, void> || std::is_same_v<Result, int>);
        if (!function) return {};
        // Cleanup's metadata contract has no result. Invoke the genuine typed
        // provider; its incidental return value is not an object identity.
        return [function](void* object) { (void)function(static_cast<Object*>(object)); };
    }
    static std::function<void(void*)> BindCleanup(std::nullptr_t) { return {}; }
};
