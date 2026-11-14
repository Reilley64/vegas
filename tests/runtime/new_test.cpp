#include "check.h"
#include "fnv/symbols_00401000.h"

#include <cstdlib>
#include <new>
#include <string>
#include <vector>

// Stand-ins for the game's operator new and operator delete, which take
// memory from its MemoryManager. They remember the last request so the tests
// can see which heap each allocation used.
namespace
{
unsigned int lastSize;
void* lastAllocated;
void* lastFreed;
bool failNextAllocation;
}

void* FUN_00401000(unsigned int size)
{
    lastSize = size;
    if (failNextAllocation)
    {
        failNextAllocation = false;
        lastAllocated = nullptr;
        return nullptr;
    }
    lastAllocated = std::malloc(size == 0 ? 1 : size);
    return lastAllocated;
}

void FUN_00401030(void* memory)
{
    lastFreed = memory;
    std::free(memory);
}

namespace
{

// Clang may remove a new-expression whose result never escapes, even when
// operator new is replaced. Storing the pointer through a volatile keeps the
// allocation, so the tests see the calls the game would make.
template <class T>
T* Escape(T* pointer)
{
    static T* volatile sink;
    sink = pointer;
    return pointer;
}

void SingleObjects(Checks& checks)
{
    int* value = Escape(new int(7));
    checks.Equal("new size", 4u, lastSize);
    checks.Equal("new uses the game heap", true, static_cast<void*>(value) == lastAllocated);
    delete value;
    checks.Equal("delete returns the block to the game heap", true, static_cast<void*>(value) == lastFreed);
}

void Arrays(Checks& checks)
{
    int* values = Escape(new int[5]);
    checks.Equal("new[] size", 20u, lastSize);
    checks.Equal("new[] uses the game heap", true, static_cast<void*>(values) == lastAllocated);
    delete[] values;
    checks.Equal("delete[] returns the block to the game heap", true, static_cast<void*>(values) == lastFreed);
}

void SizedForms(Checks& checks)
{
    void* memory = ::operator new(12);
    ::operator delete(memory, 12);
    checks.Equal("sized delete returns the block to the game heap", true, memory == lastFreed);

    memory = ::operator new[](12);
    ::operator delete[](memory, 12);
    checks.Equal("sized delete[] returns the block to the game heap", true, memory == lastFreed);
}

void AllocationFailure(Checks& checks)
{
    // Explicit calls through volatile pointers cannot be elided like new-expressions.
    using Allocate = void* (*)(std::size_t);
    Allocate volatile allocate = &::operator new;
    Allocate volatile allocateArray = &::operator new[];
    for (Allocate function : {allocate, allocateArray})
    {
        bool threw = false;
        failNextAllocation = true;
        try
        {
            function(16);
        }
        catch (const std::bad_alloc&)
        {
            threw = true;
        }
        const unsigned int requestedSize = lastSize;
        const bool returnedNull = lastAllocated == nullptr;
        checks.Equal("allocation failure throws bad_alloc", true, threw);
        checks.Equal("failed allocation forwards size", 16u, requestedSize);
        checks.Equal("native allocator returned null", true, returnedNull);
    }
}

void StandardContainers(Checks& checks)
{
    void* data = nullptr;
    {
        std::vector<int> values(100);
        data = Escape(values.data());
        checks.Equal("vector uses the game heap", true, data == lastAllocated);
    }
    checks.Equal("vector frees into the game heap", true, data == lastFreed);
}

}

int main()
{
    Checks checks("runtime.new");
    checks.Run("single objects", [&] { SingleObjects(checks); });
    checks.Run("arrays", [&] { Arrays(checks); });
    checks.Run("sized forms", [&] { SizedForms(checks); });
    checks.Run("allocation failure", [&] { AllocationFailure(checks); });
    checks.Run("standard containers", [&] { StandardContainers(checks); });
    return checks.ExitCode();
}
