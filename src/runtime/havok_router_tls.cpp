#include "fnv/symbols_00c85000.h"

namespace
{
// The router belongs to its caller. Thread exit does not release it.
thread_local void* router = nullptr;
}

// @fnv 0x00c85730
void SetThreadLocalValue(void* value)
{
    router = value;
}

// @fnv 0x00c85750
void* FUN_00c85750()
{
    return router;
}

namespace fnv_00c85760
{
// @fnv 0x00c85760
void* FUN_00c85760()
{
    return router;
}
}
