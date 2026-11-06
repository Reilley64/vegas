#pragma once
#include "havok/NativePackfile.h"

namespace havok::serialize
{
// Allocating producers publish real objects and exact source identities through
// the same resource owner used by in-place and mesh loaders.
struct NativeGraph
{
    struct Object { Location location; ObjectReference reference; };
    struct Fixup { Location field, target; };
    std::vector<Object> objects;
    std::vector<const void*> allocations; // genuine allocator blocks, not object aliases
    std::vector<Fixup> references;
    std::vector<SymbolLocation> exports, imports;
    Location root;
    std::shared_ptr<const CompletionLedger> completed;
    ObjectReference Find(Location) const;
    ObjectReference Reference(Location) const;
};
}
