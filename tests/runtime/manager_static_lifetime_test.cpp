#include "fnv/decl/MemoryManager.h"
#include "fnv/symbols_00401000.h"
#include "fnv/tls.h"

#include <cstdio>
#include <cstdlib>

void VerifyManagerStaticClient();
void RetainManagerStaticHeapAllocation();

int main()
{
    if (FUN_00401020() != &g_memoryManager)
        std::abort();
    VerifyManagerStaticClient();
    FUN_00401020()->InitializeHeaps();
    g_tlsBlock.memoryContext = 36;
    RetainManagerStaticHeapAllocation();
    // Both allocations deliberately remain attached until the other TU's
    // static destructor. Shutting down the global owner here would be invalid.
    std::puts("static allocation client retained through main");
}
