#include "fnv/tls.h"

// The initial values are the original module's .tls template; every field not
// listed here starts at zero.
thread_local TlsBlock_t g_tlsBlock = {
    .lastLocalVariableId = 0xffffffff,
    .lastRefObjectIndex = 0xffffffff,
    .flag298 = true,
    .textureLoadMethod = 3,
    .timeControllerLastCycleType = 3,
    .memoryContext = 0x3b,
};
